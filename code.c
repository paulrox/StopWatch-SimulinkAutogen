/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2013  Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation,
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */

#include "ee.h"
#include "ee_irq.h"
#include <stdio.h>
#include "stm32f4xx_conf.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_lcd.h"
#include "stm32f4xx.h"

#include "STMPE811QTR.h"
#include "mypictures.h"
#include "Widget.h"
#include "WidgetConfig.h"
#include "Touch.h"
#include "Event.h"
#include "SWatchFSM.h"
#include "lcd_add.h"
#include "fonts.h"
#include "debug.h"

static void strencode1digit(char *str, int digit);
static void strencode2digit(char *str, int digit);

/* State variables for generated code */
RT_MODEL_SWatchFSM_T SWatch_state;
char_T errorSig[6];
PrevZCX_SWatchFSM_T ZCSig;
DW_SWatchFSM_T DWork;


boolean_T Bwatch, Bswatch, Balarm, Btimer, Bplus, Bminus, Bstart, Bstop;
uint8_T hours=0, minutes=0, seconds=0, tenths=0, mode, alarm_status, timer_exp, swatchrun, watchset;

/*
 * SysTick ISR2
 */
ISR2(systick_handler)
{
	/* count the interrupts, waking up expired alarms */
	CounterTick(myCounter);
}

/*
 * TASK LCD
 */

TASK(TaskLCD)
{
unsigned int px, py;
TPoint p;

	if (GetTouch_SC_Async(&px, &py)) {
		p.x = px;
		p.y = py;
		OnTouch(MyWatchScr, &p);
	}
}


/*
 * TASK Clock
 */
unsigned char IsUpdateTime()
{
unsigned char res;
static unsigned char oh=0, om=0, os=0;

	if (hours!=oh || minutes!=om || seconds!= os)
		res = 1;
	else
		res = 0;
	oh = hours;
	om = minutes;
	os = seconds;
	return res;
}

void updateScreen(unsigned char om, unsigned char m)
{
char tstr[3];

	switch (om) {
	case WATCHMODE:
		/* avoid overwriting the same picture */
		if (m != WATCHMODE) DrawOff(&MyWatchScr[BWATCH]);
		DrawOff(&MyWatchScr[BPLUS]);
		DrawOff(&MyWatchScr[BMINUS]);
		break;
	case SWATCHMODE:
		DrawOff(&MyWatchScr[BSWATCH]);
		DrawOff(&MyWatchScr[BSTART]);
		DrawOff(&MyWatchScr[BSTOP]);
		break;
	case ALARMMODE : case TIMERMODE:
		DrawOff(&MyWatchScr[BSET]);
		DrawOff(&MyWatchScr[BRESET]);
		DrawOff(&MyWatchScr[BPLUS]);
		DrawOff(&MyWatchScr[BMINUS]);
		if (om == ALARMMODE) {
			DrawOff(&MyWatchScr[BALARM]);
			strencode2digit(tstr, (int)seconds);
			WPrint(&MyWatchScr[SECSTR], tstr);
		} else {
			DrawOff(&MyWatchScr[BTIMER]);
		}
		break;
	default:
		break;
	}
	switch (m) {
	case WATCHMODE:
		/* avoid overwriting the same picture */
		if (om != WATCHMODE) {
			DrawOn(&MyWatchScr[BWATCH]);
			DrawOn(&MyWatchScr[TTSBKG]);
		}
		if (watchset) {
			DrawOn(&MyWatchScr[BPLUS]);
			DrawOn(&MyWatchScr[BMINUS]);
		}
		break;
	case SWATCHMODE:
		DrawOn(&MyWatchScr[BSWATCH]);
		DrawOn(&MyWatchScr[BSTART]);
		if (swatchrun <= 1) {
			DrawOn(&MyWatchScr[BSTOP]);
		} else {
			DrawOn(&MyWatchScr[BRESET]);
		}
		break;
	case ALARMMODE: case TIMERMODE:
		DrawOn(&MyWatchScr[BSET]);
		DrawOn(&MyWatchScr[BRESET]);
		DrawOn(&MyWatchScr[BPLUS]);
		DrawOn(&MyWatchScr[BMINUS]);
		DrawOn(&MyWatchScr[TTSBKG]);
		if (m == ALARMMODE) {
			DrawOn(&MyWatchScr[BALARM]);
			DrawOn(&MyWatchScr[SECBKG]);
		} else {
			DrawOn(&MyWatchScr[BTIMER]);
		}
		break;
	default:
		break;
	}
}

void strencode2digit(char *str, int digit)
{
	str[2]=0;
	str[0]=digit/10+'0';
	str[1]=digit%10+'0';
}

static void strencode1digit(char *str, int digit)
{
	str[1] = 0;
	str[0] = digit + '0';
}

TASK(TaskClock)
{
unsigned char i;
static int oldmode=8;
static int oldswatchrun = 10;
static int oldwatchset = 2;
static int oldalarm = 3;
static int oldtimer = 2;
static unsigned char oh=99, om=99, os=99, ot=99;
char tstr[3];

	if (IsEvent(WATCHBPRESS))
		Bwatch=1;
	else
		Bwatch=0;

	if (IsEvent(SWATCHBPRESS))
		Bswatch=1;
	else
		Bswatch=0;

	if (IsEvent(ALARMBPRESS))
		Balarm=1;
	else
		Balarm=0;

	if (IsEvent(TIMERBPRESS))
		Btimer=1;
	else
		Btimer=0;

	if (IsEvent(PLUSBPRESS))
		Bplus=1;
	else
		Bplus=0;

	if (IsEvent(MINUSBPRESS))
		Bminus=1;
	else
		Bminus=0;

	if (IsEvent(STARTBPRESS))
		Bstart = 1;
	else
		Bstart = 0;

	if (IsEvent(STOPBPRESS))
		Bstop = 1;
	else
		Bstop = 0;

	SWatchFSM_step(&SWatch_state, Bwatch, Bswatch, Balarm, Btimer, Bplus, Bminus, Bstart, Bstop,
				&hours, &minutes, &seconds, &tenths, &mode, &swatchrun, &watchset, &alarm_status, &timer_exp);

	ClearEvents();
	Bplus=Bminus=Bwatch=Btimer=Balarm=Bswatch=Bstart=Bstop=0;

	if (hours!=oh) {
		strencode2digit(tstr, (int)hours);
		DrawOn(&MyWatchScr[HRSBKG]);
		WPrint(&MyWatchScr[HRSSTR], tstr);
		oh=hours;
	}
	if (minutes!=om) {
		strencode2digit(tstr, (int)minutes);
		DrawOn(&MyWatchScr[MINBKG]);
		WPrint(&MyWatchScr[MINSTR], tstr);
		om=minutes;
	}
	if (seconds!= os) {
		strencode2digit(tstr, (int)seconds);
		DrawOn(&MyWatchScr[SECBKG]);
		WPrint(&MyWatchScr[SECSTR], tstr);
		os=seconds;
	}
	if ((tenths != ot && mode == SWATCHMODE) || (oldmode != SWATCHMODE && mode == SWATCHMODE)) {
		strencode1digit(tstr, (int)tenths);
		DrawOn(&MyWatchScr[TTSBKG]);
		WPrint(&MyWatchScr[TTSSEP], ".");
		WPrint(&MyWatchScr[TTSSTR], tstr);
		ot=tenths;
	}

	if (oldalarm != alarm_status) {
		if (alarm_status == 1) {
			DrawOn(&MyWatchScr[ALARMEXP]);
		} else {
			DrawOff(&MyWatchScr[ALARMEXP]);
		}
		oldalarm = alarm_status;
	}

	if (oldtimer != timer_exp) {
			if (timer_exp == 1) {
				DrawOn(&MyWatchScr[TIMEREXP]);
			} else {
				DrawOff(&MyWatchScr[TIMEREXP]);
			}
			oldtimer = timer_exp;
		}

	if (oldmode != mode || oldswatchrun != swatchrun || oldwatchset != watchset) {
	updateScreen(oldmode, mode);
	oldmode = mode;
	oldswatchrun = swatchrun;
	oldwatchset = watchset;
	}
}

/*
 * MAIN TASK
 */
int main(void)
{

	SystemInit();
  /*Initializes Erika related stuffs*/
	EE_system_init();

	SWatch_state.errorStatus = errorSig;
	SWatch_state.ModelData.prevZCSigState = &ZCSig;
	SWatch_state.ModelData.dwork = &DWork;

  /* init state machine */
	SWatchFSM_initialize(&SWatch_state, &Bwatch, &Bswatch, &Balarm, &Btimer, &Bplus, &Bminus, &Bstart, &Bstop,
			&hours, &minutes, &seconds, &tenths, &mode, &swatchrun, &watchset, &alarm_status, &timer_exp);

	/*Initialize systick */
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, SystemCoreClock));
	EE_systick_enable_int();
	EE_systick_start();

	/* Initializes LCD and touchscreen */
	IOE_Config();
	/* Initialize the LCD */
	STM32f4_Discovery_LCD_Init();

	InitTouch(-0.0853, 0.0665, -331, 15);

	/* Draw the background */
	DrawInit(MyWatchScr);

	/* Program cyclic alarms which will fire after an initial offset,
	 * and after that periodically
	 * */
	SetRelAlarm(AlarmTaskLCD, 10, 100);
	SetRelAlarm(AlarmTaskClock, 10, 50);

  /* Forever loop: background activities (if any) should go here */
	for (;;) { }
}



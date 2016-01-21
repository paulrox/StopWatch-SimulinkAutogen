/*
 * File: SWatchFSM.c
 *
 * Code generated for Simulink model 'SWatchFSM'.
 *
 * Model version                  : 1.173
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Sat Dec 19 12:52:36 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWatchFSM.h"
#include "SWatchFSM_private.h"

/* Named constants for Chart: '<S1>/SWatch' */
#define SWatchFSM_IN_A_count           ((uint8_T)1U)
#define SWatchFSM_IN_A_stop            ((uint8_T)2U)
#define SWatchFSM_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define SWatchFSM_IN_S_count           ((uint8_T)1U)
#define SWatchFSM_IN_S_stop            ((uint8_T)2U)
#define SWatchFSM_IN_T_count           ((uint8_T)1U)
#define SWatchFSM_IN_T_stop            ((uint8_T)2U)
#define SWatchFSM_IN_W_count           ((uint8_T)1U)
#define SWatchFSM_IN_alarm_m           ((uint8_T)1U)
#define SWatchFSM_IN_alarm_running     ((uint8_T)1U)
#define SWatchFSM_IN_alarm_set         ((uint8_T)2U)
#define SWatchFSM_IN_alarm_sethours    ((uint8_T)1U)
#define SWatchFSM_IN_alarm_setminutes  ((uint8_T)2U)
#define SWatchFSM_IN_swatch_m          ((uint8_T)2U)
#define SWatchFSM_IN_swatch_pause      ((uint8_T)1U)
#define SWatchFSM_IN_swatch_running    ((uint8_T)2U)
#define SWatchFSM_IN_swatch_stop       ((uint8_T)3U)
#define SWatchFSM_IN_timer_m           ((uint8_T)3U)
#define SWatchFSM_IN_timer_running     ((uint8_T)1U)
#define SWatchFSM_IN_timer_set         ((uint8_T)2U)
#define SWatchFSM_IN_timer_sethours    ((uint8_T)1U)
#define SWatchFSM_IN_timer_setminutes  ((uint8_T)2U)
#define SWatchFSM_IN_timer_setseconds  ((uint8_T)3U)
#define SWatchFSM_IN_watch_m           ((uint8_T)4U)
#define SWatchFSM_IN_watch_sethours    ((uint8_T)1U)
#define SWatchFSM_IN_watch_setminutes  ((uint8_T)2U)
#define SWatchFSM_IN_watch_settime     ((uint8_T)1U)
#define SWatchFSM_IN_watch_showtime    ((uint8_T)2U)
#define SWatchFSM_event_alarm_b        (3)
#define SWatchFSM_event_minus_b        (6)
#define SWatchFSM_event_plus_b         (5)
#define SWatchFSM_event_start_b        (7)
#define SWatchFSM_event_stop_b         (8)
#define SWatchFSM_event_swatch_b       (2)
#define SWatchFSM_event_tick_t         (0)
#define SWatchFSM_event_timer_b        (4)
#define SWatchFSM_event_watch_b        (1)

/* Forward declaration for local functions */
static void SWatchFS_enter_internal_alarm_m(uint8_T *SWatchFSM_Y_hours_D,
    uint8_T *SWatchFSM_Y_minutes_D, DW_SWatchFSM_T *SWatchFSM_DW);
static void SWatchFS_enter_internal_timer_m(uint8_T *SWatchFSM_Y_hours_D,
    uint8_T *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D,
    DW_SWatchFSM_T *SWatchFSM_DW);
static void SWatchFSM_swatch_m(uint8_T *SWatchFSM_Y_hours_D, uint8_T
    *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D, uint8_T
    *SWatchFSM_Y_tenths_D, uint8_T *SWatchFSM_Y_mode, uint8_T
    *SWatchFSM_Y_swatchrun, uint8_T *SWatchFSM_Y_watchset, DW_SWatchFSM_T
    *SWatchFSM_DW);
static void SWatchFSM_timer_m(uint8_T *SWatchFSM_Y_hours_D, uint8_T
    *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D, uint8_T
    *SWatchFSM_Y_mode, uint8_T *SWatchFSM_Y_watchset, uint8_T
    *SWatchFSM_Y_time_exp, DW_SWatchFSM_T *SWatchFSM_DW);
static void SWatchFSM_Mode_mng(uint8_T *SWatchFSM_Y_hours_D, uint8_T
    *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D, uint8_T
    *SWatchFSM_Y_tenths_D, uint8_T *SWatchFSM_Y_mode, uint8_T
    *SWatchFSM_Y_swatchrun, uint8_T *SWatchFSM_Y_watchset, uint8_T
    *SWatchFSM_Y_alarm_exp, uint8_T *SWatchFSM_Y_time_exp, DW_SWatchFSM_T
    *SWatchFSM_DW);
static void SWatchFS_chartstep_c3_SWatchFSM(uint8_T *SWatchFSM_Y_hours_D,
    uint8_T *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D, uint8_T
    *SWatchFSM_Y_tenths_D, uint8_T *SWatchFSM_Y_mode, uint8_T
    *SWatchFSM_Y_swatchrun, uint8_T *SWatchFSM_Y_watchset, uint8_T
    *SWatchFSM_Y_alarm_exp, uint8_T *SWatchFSM_Y_time_exp, DW_SWatchFSM_T
    *SWatchFSM_DW);

/* Function for Chart: '<S1>/SWatch' */
static void SWatchFS_enter_internal_alarm_m(uint8_T *SWatchFSM_Y_hours_D,
    uint8_T *SWatchFSM_Y_minutes_D, DW_SWatchFSM_T *SWatchFSM_DW)
{
    /* Entry Internal 'alarm_m': '<S3>:23' */
    switch (SWatchFSM_DW->was_alarm_m) {
      case SWatchFSM_IN_alarm_running:
        SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_alarm_running;
        SWatchFSM_DW->was_alarm_m = SWatchFSM_IN_alarm_running;
        break;

      case SWatchFSM_IN_alarm_set:
        SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_alarm_set;
        SWatchFSM_DW->was_alarm_m = SWatchFSM_IN_alarm_set;

        /* Entry 'alarm_set': '<S3>:237' */
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;

        /* Entry Internal 'alarm_set': '<S3>:237' */
        /* Transition: '<S3>:242' */
        SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_alarm_sethours;

        /* Entry 'alarm_sethours': '<S3>:238' */
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
        break;

      default:
        /* Transition: '<S3>:250' */
        SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_alarm_set;
        SWatchFSM_DW->was_alarm_m = SWatchFSM_IN_alarm_set;

        /* Entry 'alarm_set': '<S3>:237' */
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;

        /* Entry Internal 'alarm_set': '<S3>:237' */
        /* Transition: '<S3>:242' */
        SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_alarm_sethours;

        /* Entry 'alarm_sethours': '<S3>:238' */
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
        break;
    }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatchFS_enter_internal_timer_m(uint8_T *SWatchFSM_Y_hours_D,
    uint8_T *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D,
    DW_SWatchFSM_T *SWatchFSM_DW)
{
    /* Entry Internal 'timer_m': '<S3>:21' */
    switch (SWatchFSM_DW->was_timer_m) {
      case SWatchFSM_IN_timer_running:
        SWatchFSM_DW->is_timer_m = SWatchFSM_IN_timer_running;
        SWatchFSM_DW->was_timer_m = SWatchFSM_IN_timer_running;
        break;

      case SWatchFSM_IN_timer_set:
        SWatchFSM_DW->is_timer_m = SWatchFSM_IN_timer_set;
        SWatchFSM_DW->was_timer_m = SWatchFSM_IN_timer_set;

        /* Entry 'timer_set': '<S3>:211' */
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
        *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;

        /* Entry Internal 'timer_set': '<S3>:211' */
        /* Transition: '<S3>:220' */
        SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_sethours;

        /* Entry 'timer_sethours': '<S3>:215' */
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
        break;

      default:
        /* Transition: '<S3>:229' */
        SWatchFSM_DW->is_timer_m = SWatchFSM_IN_timer_set;
        SWatchFSM_DW->was_timer_m = SWatchFSM_IN_timer_set;

        /* Entry 'timer_set': '<S3>:211' */
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
        *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;

        /* Entry Internal 'timer_set': '<S3>:211' */
        /* Transition: '<S3>:220' */
        SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_sethours;

        /* Entry 'timer_sethours': '<S3>:215' */
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
        break;
    }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatchFSM_swatch_m(uint8_T *SWatchFSM_Y_hours_D, uint8_T
    *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D, uint8_T
    *SWatchFSM_Y_tenths_D, uint8_T *SWatchFSM_Y_mode, uint8_T
    *SWatchFSM_Y_swatchrun, uint8_T *SWatchFSM_Y_watchset, DW_SWatchFSM_T
    *SWatchFSM_DW)
{
    /* During 'swatch_m': '<S3>:22' */
    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_timer_b) {
        /* Transition: '<S3>:56' */
        /* Exit Internal 'swatch_m': '<S3>:22' */
        SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_timer_m;

        /* Entry 'timer_m': '<S3>:21' */
        *SWatchFSM_Y_mode = 3U;
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
        *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;
        SWatchFS_enter_internal_timer_m(SWatchFSM_Y_hours_D,
            SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D, SWatchFSM_DW);
    } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_alarm_b) {
        /* Transition: '<S3>:63' */
        /* Exit Internal 'swatch_m': '<S3>:22' */
        SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_alarm_m;

        /* Entry 'alarm_m': '<S3>:23' */
        *SWatchFSM_Y_mode = 2U;
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;
        SWatchFS_enter_internal_alarm_m(SWatchFSM_Y_hours_D,
            SWatchFSM_Y_minutes_D, SWatchFSM_DW);
    } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_watch_b) {
        /* Transition: '<S3>:275' */
        /* Exit Internal 'swatch_m': '<S3>:22' */
        SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_watch_m;

        /* Entry 'watch_m': '<S3>:20' */
        *SWatchFSM_Y_mode = 0U;

        /* Entry Internal 'watch_m': '<S3>:20' */
        /* Transition: '<S3>:252' */
        *SWatchFSM_Y_watchset = 0U;
        SWatchFSM_DW->is_watch_m = SWatchFSM_IN_watch_showtime;
    } else {
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_S;
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_S;
        *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_S;
        *SWatchFSM_Y_tenths_D = SWatchFSM_DW->tenths_S;
        switch (SWatchFSM_DW->is_swatch_m) {
          case SWatchFSM_IN_swatch_pause:
            /* During 'swatch_pause': '<S3>:93' */
            if (SWatchFSM_DW->sfEvent == SWatchFSM_event_start_b) {
                /* Transition: '<S3>:94' */
                *SWatchFSM_Y_swatchrun = 1U;
                SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_swatch_running;
                SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_swatch_running;
            } else {
                if (SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) {
                    /* Transition: '<S3>:97' */
                    *SWatchFSM_Y_swatchrun = 0U;
                    SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_swatch_stop;
                    SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_swatch_stop;
                }
            }
            break;

          case SWatchFSM_IN_swatch_running:
            /* During 'swatch_running': '<S3>:89' */
            if (SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) {
                /* Transition: '<S3>:92' */
                *SWatchFSM_Y_swatchrun = 2U;
                SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_swatch_pause;
                SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_swatch_pause;
            }
            break;

          default:
            /* During 'swatch_stop': '<S3>:87' */
            if (SWatchFSM_DW->sfEvent == SWatchFSM_event_start_b) {
                /* Transition: '<S3>:90' */
                *SWatchFSM_Y_swatchrun = 1U;
                SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_swatch_running;
                SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_swatch_running;
            }
            break;
        }
    }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatchFSM_timer_m(uint8_T *SWatchFSM_Y_hours_D, uint8_T
    *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D, uint8_T
    *SWatchFSM_Y_mode, uint8_T *SWatchFSM_Y_watchset, uint8_T
    *SWatchFSM_Y_time_exp, DW_SWatchFSM_T *SWatchFSM_DW)
{
    int32_T tmp;
    uint32_T qY;

    /* During 'timer_m': '<S3>:21' */
    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_alarm_b) {
        /* Transition: '<S3>:61' */
        /* Exit Internal 'timer_m': '<S3>:21' */
        SWatchFSM_DW->is_timer_m = SWatchFSM_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'timer_set': '<S3>:211' */
        SWatchFSM_DW->is_timer_set = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_alarm_m;

        /* Entry 'alarm_m': '<S3>:23' */
        *SWatchFSM_Y_mode = 2U;
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;
        SWatchFS_enter_internal_alarm_m(SWatchFSM_Y_hours_D,
            SWatchFSM_Y_minutes_D, SWatchFSM_DW);
    } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_watch_b) {
        /* Transition: '<S3>:64' */
        /* Exit Internal 'timer_m': '<S3>:21' */
        SWatchFSM_DW->is_timer_m = SWatchFSM_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'timer_set': '<S3>:211' */
        SWatchFSM_DW->is_timer_set = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_watch_m;

        /* Entry 'watch_m': '<S3>:20' */
        *SWatchFSM_Y_mode = 0U;

        /* Entry Internal 'watch_m': '<S3>:20' */
        /* Transition: '<S3>:252' */
        *SWatchFSM_Y_watchset = 0U;
        SWatchFSM_DW->is_watch_m = SWatchFSM_IN_watch_showtime;
    } else if (SWatchFSM_DW->is_timer_m == SWatchFSM_IN_timer_running) {
        /* During 'timer_running': '<S3>:173' */
        if (SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) {
            /* Transition: '<S3>:184' */
            SWatchFSM_DW->hours_T = 0U;
            SWatchFSM_DW->minutes_T = 0U;
            SWatchFSM_DW->seconds_T = 0U;
            SWatchFSM_DW->tenths_T = 0U;
            *SWatchFSM_Y_time_exp = 0U;
            SWatchFSM_DW->is_timer_m = SWatchFSM_IN_timer_set;
            SWatchFSM_DW->was_timer_m = SWatchFSM_IN_timer_set;

            /* Entry 'timer_set': '<S3>:211' */
            *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
            *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;

            /* Entry Internal 'timer_set': '<S3>:211' */
            /* Transition: '<S3>:220' */
            SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_sethours;

            /* Entry 'timer_sethours': '<S3>:215' */
            *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
        } else {
            *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
            *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
            *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;
        }
    } else {
        /* During 'timer_set': '<S3>:211' */
        if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_start_b) &&
                ((SWatchFSM_DW->hours_T > 0) || ((SWatchFSM_DW->hours_T == 0) &&
              (SWatchFSM_DW->minutes_T > 0)) || ((SWatchFSM_DW->hours_T == 0) &&
              (SWatchFSM_DW->minutes_T == 0) && (SWatchFSM_DW->seconds_T > 0))))
        {
            /* Transition: '<S3>:169' */
            /* Exit Internal 'timer_set': '<S3>:211' */
            SWatchFSM_DW->is_timer_set = SWatchFSM_IN_NO_ACTIVE_CHILD;
            SWatchFSM_DW->is_timer_m = SWatchFSM_IN_timer_running;
            SWatchFSM_DW->was_timer_m = SWatchFSM_IN_timer_running;
        } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) {
            /* Transition: '<S3>:226' */
            SWatchFSM_DW->hours_T = 0U;
            SWatchFSM_DW->minutes_T = 0U;
            SWatchFSM_DW->seconds_T = 0U;
            SWatchFSM_DW->tenths_T = 0U;

            /* Exit Internal 'timer_set': '<S3>:211' */
            SWatchFSM_DW->is_timer_m = SWatchFSM_IN_timer_set;
            SWatchFSM_DW->was_timer_m = SWatchFSM_IN_timer_set;

            /* Entry 'timer_set': '<S3>:211' */
            *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
            *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;

            /* Entry Internal 'timer_set': '<S3>:211' */
            /* Transition: '<S3>:220' */
            SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_sethours;

            /* Entry 'timer_sethours': '<S3>:215' */
            *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
        } else {
            switch (SWatchFSM_DW->is_timer_set) {
              case SWatchFSM_IN_timer_sethours:
                /* During 'timer_sethours': '<S3>:215' */
                if (SWatchFSM_DW->sfEvent == SWatchFSM_event_timer_b) {
                    /* Transition: '<S3>:217' */
                    SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_setminutes;

                    /* Entry 'timer_setminutes': '<S3>:214' */
                    *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
                } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_plus_b) {
                    /* Transition: '<S3>:222' */
                    tmp = (int32_T)(SWatchFSM_DW->hours_T + 1U);
                    if ((uint32_T)tmp > 255U) {
                        tmp = 255;
                    }

                    SWatchFSM_DW->hours_T = (uint8_T)((uint32_T)(uint8_T)tmp -
                        (uint8_T)((uint8_T)tmp / 24U * 24U));
                    SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_sethours;

                    /* Entry 'timer_sethours': '<S3>:215' */
                    *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
                } else {
                    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_minus_b) {
                        /* Transition: '<S3>:223' */
                        qY = SWatchFSM_DW->hours_T - 1U;
                        if (qY > SWatchFSM_DW->hours_T) {
                            qY = 0U;
                        }

                        SWatchFSM_DW->hours_T = (uint8_T)((uint32_T)(uint8_T)qY
                            - (uint8_T)((uint8_T)qY / 24U * 24U));
                        SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_sethours;

                        /* Entry 'timer_sethours': '<S3>:215' */
                        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
                    }
                }
                break;

              case SWatchFSM_IN_timer_setminutes:
                /* During 'timer_setminutes': '<S3>:214' */
                if (SWatchFSM_DW->sfEvent == SWatchFSM_event_plus_b) {
                    /* Transition: '<S3>:224' */
                    tmp = (int32_T)(SWatchFSM_DW->minutes_T + 1U);
                    if ((uint32_T)tmp > 255U) {
                        tmp = 255;
                    }

                    SWatchFSM_DW->minutes_T = (uint8_T)((uint32_T)(uint8_T)tmp -
                        (uint8_T)((uint8_T)tmp / 24U * 24U));
                    SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_setminutes;

                    /* Entry 'timer_setminutes': '<S3>:214' */
                    *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
                } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_minus_b) {
                    /* Transition: '<S3>:218' */
                    qY = SWatchFSM_DW->minutes_T - 1U;
                    if (qY > SWatchFSM_DW->minutes_T) {
                        qY = 0U;
                    }

                    SWatchFSM_DW->minutes_T = (uint8_T)((uint32_T)(uint8_T)qY -
                        (uint8_T)((uint8_T)qY / 24U * 24U));
                    SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_setminutes;

                    /* Entry 'timer_setminutes': '<S3>:214' */
                    *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
                } else {
                    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_timer_b) {
                        /* Transition: '<S3>:231' */
                        SWatchFSM_DW->is_timer_set =
                            SWatchFSM_IN_timer_setseconds;

                        /* Entry 'timer_setseconds': '<S3>:225' */
                        *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;
                    }
                }
                break;

              default:
                /* During 'timer_setseconds': '<S3>:225' */
                if (SWatchFSM_DW->sfEvent == SWatchFSM_event_plus_b) {
                    /* Transition: '<S3>:232' */
                    tmp = (int32_T)(SWatchFSM_DW->seconds_T + 1U);
                    if ((uint32_T)tmp > 255U) {
                        tmp = 255;
                    }

                    SWatchFSM_DW->seconds_T = (uint8_T)((uint32_T)(uint8_T)tmp -
                        (uint8_T)((uint8_T)tmp / 60U * 60U));
                    SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_setseconds;

                    /* Entry 'timer_setseconds': '<S3>:225' */
                    *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;
                } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_minus_b) {
                    /* Transition: '<S3>:233' */
                    qY = SWatchFSM_DW->seconds_T - 1U;
                    if (qY > SWatchFSM_DW->seconds_T) {
                        qY = 0U;
                    }

                    SWatchFSM_DW->seconds_T = (uint8_T)((uint32_T)(uint8_T)qY -
                        (uint8_T)((uint8_T)qY / 60U * 60U));
                    SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_setseconds;

                    /* Entry 'timer_setseconds': '<S3>:225' */
                    *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;
                } else {
                    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_timer_b) {
                        /* Transition: '<S3>:234' */
                        SWatchFSM_DW->is_timer_set = SWatchFSM_IN_timer_sethours;

                        /* Entry 'timer_sethours': '<S3>:215' */
                        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
                    }
                }
                break;
            }
        }
    }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatchFSM_Mode_mng(uint8_T *SWatchFSM_Y_hours_D, uint8_T
    *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D, uint8_T
    *SWatchFSM_Y_tenths_D, uint8_T *SWatchFSM_Y_mode, uint8_T
    *SWatchFSM_Y_swatchrun, uint8_T *SWatchFSM_Y_watchset, uint8_T
    *SWatchFSM_Y_alarm_exp, uint8_T *SWatchFSM_Y_time_exp, DW_SWatchFSM_T
    *SWatchFSM_DW)
{
    int32_T tmp;
    uint32_T qY;

    /* During 'Mode_mng': '<S3>:19' */
    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_swatch_b) {
        /* Transition: '<S3>:276' */
        /* Exit Internal 'Mode_mng': '<S3>:19' */
        /* Exit Internal 'alarm_m': '<S3>:23' */
        SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'alarm_set': '<S3>:237' */
        SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'swatch_m': '<S3>:22' */
        SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'timer_m': '<S3>:21' */
        SWatchFSM_DW->is_timer_m = SWatchFSM_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'timer_set': '<S3>:211' */
        SWatchFSM_DW->is_timer_set = SWatchFSM_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'watch_m': '<S3>:20' */
        /* Exit Internal 'watch_settime': '<S3>:254' */
        SWatchFSM_DW->is_watch_settime = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_watch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_swatch_m;

        /* Entry 'swatch_m': '<S3>:22' */
        *SWatchFSM_Y_mode = 1U;
        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_S;
        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_S;
        *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_S;
        *SWatchFSM_Y_tenths_D = SWatchFSM_DW->tenths_S;

        /* Entry Internal 'swatch_m': '<S3>:22' */
        switch (SWatchFSM_DW->was_swatch_m) {
          case SWatchFSM_IN_swatch_pause:
            SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_swatch_pause;
            SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_swatch_pause;
            break;

          case SWatchFSM_IN_swatch_running:
            SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_swatch_running;
            SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_swatch_running;
            break;

          case SWatchFSM_IN_swatch_stop:
            SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_swatch_stop;
            SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_swatch_stop;
            break;

          default:
            /* Transition: '<S3>:102' */
            SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_swatch_stop;
            SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_swatch_stop;
            break;
        }
    } else {
        switch (SWatchFSM_DW->is_Mode_mng) {
          case SWatchFSM_IN_alarm_m:
            /* During 'alarm_m': '<S3>:23' */
            if (SWatchFSM_DW->sfEvent == SWatchFSM_event_timer_b) {
                /* Transition: '<S3>:60' */
                /* Exit Internal 'alarm_m': '<S3>:23' */
                SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_NO_ACTIVE_CHILD;

                /* Exit Internal 'alarm_set': '<S3>:237' */
                SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_NO_ACTIVE_CHILD;
                SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_timer_m;

                /* Entry 'timer_m': '<S3>:21' */
                *SWatchFSM_Y_mode = 3U;
                *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
                *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
                *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;
                SWatchFS_enter_internal_timer_m(SWatchFSM_Y_hours_D,
                    SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D, SWatchFSM_DW);
            } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_watch_b) {
                /* Transition: '<S3>:273' */
                /* Exit Internal 'alarm_m': '<S3>:23' */
                SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_NO_ACTIVE_CHILD;

                /* Exit Internal 'alarm_set': '<S3>:237' */
                SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_NO_ACTIVE_CHILD;
                SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_watch_m;

                /* Entry 'watch_m': '<S3>:20' */
                *SWatchFSM_Y_mode = 0U;

                /* Entry Internal 'watch_m': '<S3>:20' */
                /* Transition: '<S3>:252' */
                *SWatchFSM_Y_watchset = 0U;
                SWatchFSM_DW->is_watch_m = SWatchFSM_IN_watch_showtime;
            } else if (SWatchFSM_DW->is_alarm_m == SWatchFSM_IN_alarm_running) {
                /* During 'alarm_running': '<S3>:151' */
                if (SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) {
                    /* Transition: '<S3>:159' */
                    SWatchFSM_DW->hours_A = 0U;
                    SWatchFSM_DW->minutes_A = 0U;
                    *SWatchFSM_Y_alarm_exp = 0U;
                    SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_alarm_set;
                    SWatchFSM_DW->was_alarm_m = SWatchFSM_IN_alarm_set;

                    /* Entry 'alarm_set': '<S3>:237' */
                    *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;

                    /* Entry Internal 'alarm_set': '<S3>:237' */
                    /* Transition: '<S3>:242' */
                    SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_alarm_sethours;

                    /* Entry 'alarm_sethours': '<S3>:238' */
                    *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
                }
            } else {
                /* During 'alarm_set': '<S3>:237' */
                if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_start_b) &&
                        ((SWatchFSM_DW->hours_A > SWatchFSM_DW->hours_W) ||
                         ((SWatchFSM_DW->hours_A == SWatchFSM_DW->hours_W) &&
                          (SWatchFSM_DW->minutes_A > SWatchFSM_DW->minutes_W))))
                {
                    /* Transition: '<S3>:152' */
                    /* Exit Internal 'alarm_set': '<S3>:237' */
                    SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_NO_ACTIVE_CHILD;
                    SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_alarm_running;
                    SWatchFSM_DW->was_alarm_m = SWatchFSM_IN_alarm_running;
                } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) {
                    /* Transition: '<S3>:249' */
                    SWatchFSM_DW->hours_A = 0U;
                    SWatchFSM_DW->minutes_A = 0U;

                    /* Exit Internal 'alarm_set': '<S3>:237' */
                    SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_alarm_set;
                    SWatchFSM_DW->was_alarm_m = SWatchFSM_IN_alarm_set;

                    /* Entry 'alarm_set': '<S3>:237' */
                    *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;

                    /* Entry Internal 'alarm_set': '<S3>:237' */
                    /* Transition: '<S3>:242' */
                    SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_alarm_sethours;

                    /* Entry 'alarm_sethours': '<S3>:238' */
                    *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
                } else if (SWatchFSM_DW->is_alarm_set ==
                           SWatchFSM_IN_alarm_sethours) {
                    /* During 'alarm_sethours': '<S3>:238' */
                    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_alarm_b) {
                        /* Transition: '<S3>:240' */
                        SWatchFSM_DW->is_alarm_set =
                            SWatchFSM_IN_alarm_setminutes;

                        /* Entry 'alarm_setminutes': '<S3>:239' */
                        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;
                    } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_plus_b)
                    {
                        /* Transition: '<S3>:243' */
                        tmp = (int32_T)(SWatchFSM_DW->hours_A + 1U);
                        if ((uint32_T)tmp > 255U) {
                            tmp = 255;
                        }

                        SWatchFSM_DW->hours_A = (uint8_T)((uint32_T)(uint8_T)tmp
                            - (uint8_T)((uint8_T)tmp / 24U * 24U));
                        SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_alarm_sethours;

                        /* Entry 'alarm_sethours': '<S3>:238' */
                        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
                    } else {
                        if (SWatchFSM_DW->sfEvent == SWatchFSM_event_minus_b) {
                            /* Transition: '<S3>:245' */
                            qY = SWatchFSM_DW->hours_A - 1U;
                            if (qY > SWatchFSM_DW->hours_A) {
                                qY = 0U;
                            }

                            SWatchFSM_DW->hours_A = (uint8_T)((uint32_T)(uint8_T)
                                qY - (uint8_T)((uint8_T)qY / 24U * 24U));
                            SWatchFSM_DW->is_alarm_set =
                                SWatchFSM_IN_alarm_sethours;

                            /* Entry 'alarm_sethours': '<S3>:238' */
                            *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
                        }
                    }
                } else {
                    /* During 'alarm_setminutes': '<S3>:239' */
                    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_alarm_b) {
                        /* Transition: '<S3>:247' */
                        SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_alarm_sethours;

                        /* Entry 'alarm_sethours': '<S3>:238' */
                        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
                    } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_plus_b)
                    {
                        /* Transition: '<S3>:244' */
                        tmp = (int32_T)(SWatchFSM_DW->minutes_A + 1U);
                        if ((uint32_T)tmp > 255U) {
                            tmp = 255;
                        }

                        SWatchFSM_DW->minutes_A = (uint8_T)((uint32_T)(uint8_T)
                            tmp - (uint8_T)((uint8_T)tmp / 60U * 60U));
                        SWatchFSM_DW->is_alarm_set =
                            SWatchFSM_IN_alarm_setminutes;

                        /* Entry 'alarm_setminutes': '<S3>:239' */
                        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;
                    } else {
                        if (SWatchFSM_DW->sfEvent == SWatchFSM_event_minus_b) {
                            /* Transition: '<S3>:241' */
                            qY = SWatchFSM_DW->minutes_A - 1U;
                            if (qY > SWatchFSM_DW->minutes_A) {
                                qY = 0U;
                            }

                            SWatchFSM_DW->minutes_A = (uint8_T)((uint32_T)
                                (uint8_T)qY - (uint8_T)((uint8_T)qY / 60U * 60U));
                            SWatchFSM_DW->is_alarm_set =
                                SWatchFSM_IN_alarm_setminutes;

                            /* Entry 'alarm_setminutes': '<S3>:239' */
                            *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;
                        }
                    }
                }
            }
            break;

          case SWatchFSM_IN_swatch_m:
            SWatchFSM_swatch_m(SWatchFSM_Y_hours_D, SWatchFSM_Y_minutes_D,
                               SWatchFSM_Y_seconds_D, SWatchFSM_Y_tenths_D,
                               SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                               SWatchFSM_Y_watchset, SWatchFSM_DW);
            break;

          case SWatchFSM_IN_timer_m:
            SWatchFSM_timer_m(SWatchFSM_Y_hours_D, SWatchFSM_Y_minutes_D,
                              SWatchFSM_Y_seconds_D, SWatchFSM_Y_mode,
                              SWatchFSM_Y_watchset, SWatchFSM_Y_time_exp,
                              SWatchFSM_DW);
            break;

          default:
            /* During 'watch_m': '<S3>:20' */
            if (SWatchFSM_DW->sfEvent == SWatchFSM_event_timer_b) {
                /* Transition: '<S3>:54' */
                /* Exit Internal 'watch_m': '<S3>:20' */
                /* Exit Internal 'watch_settime': '<S3>:254' */
                SWatchFSM_DW->is_watch_settime = SWatchFSM_IN_NO_ACTIVE_CHILD;
                SWatchFSM_DW->is_watch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
                SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_timer_m;

                /* Entry 'timer_m': '<S3>:21' */
                *SWatchFSM_Y_mode = 3U;
                *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_T;
                *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_T;
                *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_T;
                SWatchFS_enter_internal_timer_m(SWatchFSM_Y_hours_D,
                    SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D, SWatchFSM_DW);
            } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_alarm_b) {
                /* Transition: '<S3>:55' */
                /* Exit Internal 'watch_m': '<S3>:20' */
                /* Exit Internal 'watch_settime': '<S3>:254' */
                SWatchFSM_DW->is_watch_settime = SWatchFSM_IN_NO_ACTIVE_CHILD;
                SWatchFSM_DW->is_watch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
                SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_alarm_m;

                /* Entry 'alarm_m': '<S3>:23' */
                *SWatchFSM_Y_mode = 2U;
                *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_A;
                *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_A;
                SWatchFS_enter_internal_alarm_m(SWatchFSM_Y_hours_D,
                    SWatchFSM_Y_minutes_D, SWatchFSM_DW);
            } else if (SWatchFSM_DW->is_watch_m == SWatchFSM_IN_watch_settime) {
                /* During 'watch_settime': '<S3>:254' */
                if (SWatchFSM_DW->is_watch_settime ==
                        SWatchFSM_IN_watch_sethours) {
                    /* During 'watch_sethours': '<S3>:264' */
                    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_watch_b) {
                        /* Transition: '<S3>:262' */
                        SWatchFSM_DW->is_watch_settime =
                            SWatchFSM_IN_watch_setminutes;

                        /* Entry 'watch_setminutes': '<S3>:265' */
                        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_W;
                    } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_plus_b)
                    {
                        /* Transition: '<S3>:268' */
                        tmp = (int32_T)(SWatchFSM_DW->hours_W + 1U);
                        if ((uint32_T)tmp > 255U) {
                            tmp = 255;
                        }

                        SWatchFSM_DW->hours_W = (uint8_T)((uint32_T)(uint8_T)tmp
                            - (uint8_T)((uint8_T)tmp / 24U * 24U));
                        SWatchFSM_DW->is_watch_settime =
                            SWatchFSM_IN_watch_sethours;

                        /* Entry 'watch_sethours': '<S3>:264' */
                        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_W;
                    } else {
                        if (SWatchFSM_DW->sfEvent == SWatchFSM_event_minus_b) {
                            /* Transition: '<S3>:270' */
                            qY = SWatchFSM_DW->hours_W - 1U;
                            if (qY > SWatchFSM_DW->hours_W) {
                                qY = 0U;
                            }

                            SWatchFSM_DW->hours_W = (uint8_T)((uint32_T)(uint8_T)
                                qY - (uint8_T)((uint8_T)qY / 24U * 24U));
                            SWatchFSM_DW->is_watch_settime =
                                SWatchFSM_IN_watch_sethours;

                            /* Entry 'watch_sethours': '<S3>:264' */
                            *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_W;
                        }
                    }
                } else {
                    /* During 'watch_setminutes': '<S3>:265' */
                    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_plus_b) {
                        /* Transition: '<S3>:266' */
                        tmp = (int32_T)(SWatchFSM_DW->minutes_W + 1U);
                        if ((uint32_T)tmp > 255U) {
                            tmp = 255;
                        }

                        SWatchFSM_DW->minutes_W = (uint8_T)((uint32_T)(uint8_T)
                            tmp - (uint8_T)((uint8_T)tmp / 60U * 60U));
                        SWatchFSM_DW->is_watch_settime =
                            SWatchFSM_IN_watch_setminutes;

                        /* Entry 'watch_setminutes': '<S3>:265' */
                        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_W;
                    } else if (SWatchFSM_DW->sfEvent == SWatchFSM_event_minus_b)
                    {
                        /* Transition: '<S3>:267' */
                        qY = SWatchFSM_DW->minutes_W - 1U;
                        if (qY > SWatchFSM_DW->minutes_W) {
                            qY = 0U;
                        }

                        SWatchFSM_DW->minutes_W = (uint8_T)((uint32_T)(uint8_T)
                            qY - (uint8_T)((uint8_T)qY / 60U * 60U));
                        SWatchFSM_DW->is_watch_settime =
                            SWatchFSM_IN_watch_setminutes;

                        /* Entry 'watch_setminutes': '<S3>:265' */
                        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_W;
                    } else {
                        if (SWatchFSM_DW->sfEvent == SWatchFSM_event_watch_b) {
                            /* Transition: '<S3>:271' */
                            SWatchFSM_DW->seconds_W = 0U;
                            SWatchFSM_DW->tenths_W = 0U;
                            *SWatchFSM_Y_watchset = 0U;
                            SWatchFSM_DW->is_watch_settime =
                                SWatchFSM_IN_NO_ACTIVE_CHILD;
                            SWatchFSM_DW->is_watch_m =
                                SWatchFSM_IN_watch_showtime;
                        }
                    }
                }
            } else {
                /* During 'watch_showtime': '<S3>:251' */
                if (SWatchFSM_DW->sfEvent == SWatchFSM_event_watch_b) {
                    /* Transition: '<S3>:255' */
                    *SWatchFSM_Y_watchset = 1U;
                    SWatchFSM_DW->is_watch_m = SWatchFSM_IN_watch_settime;

                    /* Entry 'watch_settime': '<S3>:254' */
                    *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_W;
                    *SWatchFSM_Y_seconds_D = 0U;

                    /* Entry Internal 'watch_settime': '<S3>:254' */
                    /* Transition: '<S3>:269' */
                    SWatchFSM_DW->is_watch_settime = SWatchFSM_IN_watch_sethours;

                    /* Entry 'watch_sethours': '<S3>:264' */
                    *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_W;
                } else {
                    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_tick_t) {
                        /* Transition: '<S3>:31' */
                        *SWatchFSM_Y_hours_D = SWatchFSM_DW->hours_W;
                        *SWatchFSM_Y_minutes_D = SWatchFSM_DW->minutes_W;
                        *SWatchFSM_Y_seconds_D = SWatchFSM_DW->seconds_W;
                        *SWatchFSM_Y_tenths_D = SWatchFSM_DW->tenths_W;
                        SWatchFSM_DW->is_watch_m = SWatchFSM_IN_watch_showtime;
                    }
                }
            }
            break;
        }
    }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatchFS_chartstep_c3_SWatchFSM(uint8_T *SWatchFSM_Y_hours_D,
    uint8_T *SWatchFSM_Y_minutes_D, uint8_T *SWatchFSM_Y_seconds_D, uint8_T
    *SWatchFSM_Y_tenths_D, uint8_T *SWatchFSM_Y_mode, uint8_T
    *SWatchFSM_Y_swatchrun, uint8_T *SWatchFSM_Y_watchset, uint8_T
    *SWatchFSM_Y_alarm_exp, uint8_T *SWatchFSM_Y_time_exp, DW_SWatchFSM_T
    *SWatchFSM_DW)
{
    boolean_T guard1 = false;
    uint32_T qY;
    int32_T tmp;

    /* During: SWatchFSM/SWatch */
    SWatchFSM_Mode_mng(SWatchFSM_Y_hours_D, SWatchFSM_Y_minutes_D,
                       SWatchFSM_Y_seconds_D, SWatchFSM_Y_tenths_D,
                       SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                       SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                       SWatchFSM_Y_time_exp, SWatchFSM_DW);

    /* During 'Watch_mng': '<S3>:36' */
    /* During 'W_count': '<S3>:37' */
    if (SWatchFSM_DW->sfEvent == SWatchFSM_event_tick_t) {
        /* Transition: '<S3>:44' */
        tmp = (int32_T)(SWatchFSM_DW->tenths_W + 1U);
        if ((uint32_T)tmp > 255U) {
            tmp = 255;
        }

        SWatchFSM_DW->tenths_W = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 10U * 10U));
        if (SWatchFSM_DW->tenths_W == 0) {
            /* Transition: '<S3>:42' */
            tmp = (int32_T)(SWatchFSM_DW->seconds_W + 1U);
            if ((uint32_T)tmp > 255U) {
                tmp = 255;
            }

            SWatchFSM_DW->seconds_W = (uint8_T)((uint32_T)(uint8_T)tmp -
                (uint8_T)((uint8_T)tmp / 60U * 60U));
            if (SWatchFSM_DW->seconds_W == 0) {
                /* Transition: '<S3>:51' */
                tmp = (int32_T)(SWatchFSM_DW->minutes_W + 1U);
                if ((uint32_T)tmp > 255U) {
                    tmp = 255;
                }

                SWatchFSM_DW->minutes_W = (uint8_T)((uint32_T)(uint8_T)tmp -
                    (uint8_T)((uint8_T)tmp / 60U * 60U));
                if (SWatchFSM_DW->minutes_W == 0) {
                    /* Transition: '<S3>:52' */
                    tmp = (int32_T)(SWatchFSM_DW->hours_W + 1U);
                    if ((uint32_T)tmp > 255U) {
                        tmp = 255;
                    }

                    SWatchFSM_DW->hours_W = (uint8_T)((uint32_T)(uint8_T)tmp -
                        (uint8_T)((uint8_T)tmp / 24U * 24U));
                } else {
                    /* Transition: '<S3>:49' */
                }
            } else {
                /* Transition: '<S3>:48' */
            }
        } else {
            /* Transition: '<S3>:45' */
        }

        /* Transition: '<S3>:47' */
        SWatchFSM_DW->is_Watch_mng = SWatchFSM_IN_W_count;
    }

    /* During 'Swatch_mng': '<S3>:69' */
    if (SWatchFSM_DW->is_Swatch_mng == SWatchFSM_IN_S_count) {
        /* During 'S_count': '<S3>:70' */
        if (SWatchFSM_DW->sfEvent == SWatchFSM_event_tick_t) {
            /* Transition: '<S3>:72' */
            tmp = (int32_T)(SWatchFSM_DW->tenths_S + 1U);
            if ((uint32_T)tmp > 255U) {
                tmp = 255;
            }

            SWatchFSM_DW->tenths_S = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
                ((uint8_T)tmp / 10U * 10U));
            if (SWatchFSM_DW->tenths_S == 0) {
                /* Transition: '<S3>:76' */
                tmp = (int32_T)(SWatchFSM_DW->seconds_S + 1U);
                if ((uint32_T)tmp > 255U) {
                    tmp = 255;
                }

                SWatchFSM_DW->seconds_S = (uint8_T)((uint32_T)(uint8_T)tmp -
                    (uint8_T)((uint8_T)tmp / 60U * 60U));
                if (SWatchFSM_DW->seconds_S == 0) {
                    /* Transition: '<S3>:84' */
                    tmp = (int32_T)(SWatchFSM_DW->minutes_S + 1U);
                    if ((uint32_T)tmp > 255U) {
                        tmp = 255;
                    }

                    SWatchFSM_DW->minutes_S = (uint8_T)((uint32_T)(uint8_T)tmp -
                        (uint8_T)((uint8_T)tmp / 60U * 60U));
                    if (SWatchFSM_DW->minutes_S == 0) {
                        /* Transition: '<S3>:85' */
                        tmp = (int32_T)(SWatchFSM_DW->hours_S + 1U);
                        if ((uint32_T)tmp > 255U) {
                            tmp = 255;
                        }

                        SWatchFSM_DW->hours_S = (uint8_T)((uint32_T)(uint8_T)tmp
                            - (uint8_T)((uint8_T)tmp / 24U * 24U));
                    } else {
                        /* Transition: '<S3>:82' */
                    }
                } else {
                    /* Transition: '<S3>:78' */
                }
            } else {
                /* Transition: '<S3>:79' */
            }

            /* Transition: '<S3>:81' */
            SWatchFSM_DW->is_Swatch_mng = SWatchFSM_IN_S_count;
        } else {
            if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) &&
                    (*SWatchFSM_Y_mode == 1)) {
                /* Transition: '<S3>:99' */
                SWatchFSM_DW->is_Swatch_mng = SWatchFSM_IN_S_stop;
            }
        }
    } else {
        /* During 'S_stop': '<S3>:86' */
        if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_start_b) &&
                (*SWatchFSM_Y_mode == 1)) {
            /* Transition: '<S3>:100' */
            SWatchFSM_DW->is_Swatch_mng = SWatchFSM_IN_S_count;
        } else {
            if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) &&
                    (*SWatchFSM_Y_mode == 1)) {
                /* Transition: '<S3>:101' */
                SWatchFSM_DW->hours_S = 0U;
                SWatchFSM_DW->minutes_S = 0U;
                SWatchFSM_DW->seconds_S = 0U;
                SWatchFSM_DW->tenths_S = 0U;
                SWatchFSM_DW->is_Swatch_mng = SWatchFSM_IN_S_stop;
            }
        }
    }

    /* During 'Alarm_mng': '<S3>:106' */
    if (SWatchFSM_DW->is_Alarm_mng == SWatchFSM_IN_A_count) {
        /* During 'A_count': '<S3>:109' */
        if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_tick_t) &&
                (SWatchFSM_DW->minutes_W == SWatchFSM_DW->minutes_A) &&
                (SWatchFSM_DW->hours_W == SWatchFSM_DW->hours_A)) {
            /* Transition: '<S3>:135' */
            *SWatchFSM_Y_alarm_exp = 1U;
            SWatchFSM_DW->is_Alarm_mng = SWatchFSM_IN_A_stop;
        } else {
            if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) &&
                    (*SWatchFSM_Y_mode == 2)) {
                /* Transition: '<S3>:140' */
                SWatchFSM_DW->is_Alarm_mng = SWatchFSM_IN_A_stop;
            }
        }
    } else {
        /* During 'A_stop': '<S3>:108' */
        if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_start_b) &&
                (*SWatchFSM_Y_mode == 2) && ((SWatchFSM_DW->hours_A >
                SWatchFSM_DW->hours_W) || ((SWatchFSM_DW->hours_A ==
                SWatchFSM_DW->hours_W) && (SWatchFSM_DW->minutes_A >
                SWatchFSM_DW->minutes_W)))) {
            /* Transition: '<S3>:123' */
            SWatchFSM_DW->is_Alarm_mng = SWatchFSM_IN_A_count;
        }
    }

    /* During 'Timer_mng': '<S3>:107' */
    if (SWatchFSM_DW->is_Timer_mng == SWatchFSM_IN_T_count) {
        /* During 'T_count': '<S3>:186' */
        if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_stop_b) &&
                (*SWatchFSM_Y_mode == 3)) {
            /* Transition: '<S3>:193' */
            SWatchFSM_DW->is_Timer_mng = SWatchFSM_IN_T_stop;
        } else {
            if (SWatchFSM_DW->sfEvent == SWatchFSM_event_tick_t) {
                /* Transition: '<S3>:202' */
                qY = SWatchFSM_DW->tenths_T - 1U;
                if (qY > SWatchFSM_DW->tenths_T) {
                    qY = 0U;
                }

                SWatchFSM_DW->tenths_T = (uint8_T)qY;
                if (SWatchFSM_DW->tenths_T == 0) {
                    /* Transition: '<S3>:200' */
                    SWatchFSM_DW->tenths_T = 9U;
                    if (SWatchFSM_DW->seconds_T == 1) {
                        /* Transition: '<S3>:292' */
                        qY = SWatchFSM_DW->seconds_T - 1U;
                        if (qY > SWatchFSM_DW->seconds_T) {
                            qY = 0U;
                        }

                        SWatchFSM_DW->seconds_T = (uint8_T)qY;
                        guard1 = true;
                    } else {
                        /* Transition: '<S3>:291' */
                        qY = SWatchFSM_DW->seconds_T - 1U;
                        if (qY > SWatchFSM_DW->seconds_T) {
                            qY = 0U;
                        }

                        SWatchFSM_DW->seconds_T = (uint8_T)qY;
                        if ((SWatchFSM_DW->seconds_T == 0) &&
                                (SWatchFSM_DW->minutes_T == 0) &&
                                (SWatchFSM_DW->hours_T == 0)) {
                            /* Transition: '<S3>:235' */
                            *SWatchFSM_Y_time_exp = 1U;
                            SWatchFSM_DW->is_Timer_mng = SWatchFSM_IN_T_stop;
                        } else {
                            if (SWatchFSM_DW->seconds_T == 0) {
                                /* Transition: '<S3>:205' */
                                SWatchFSM_DW->seconds_T = 59U;
                                if (SWatchFSM_DW->minutes_T == 1) {
                                    /* Transition: '<S3>:288' */
                                    qY = SWatchFSM_DW->minutes_T - 1U;
                                    if (qY > SWatchFSM_DW->minutes_T) {
                                        qY = 0U;
                                    }

                                    SWatchFSM_DW->minutes_T = (uint8_T)qY;
                                } else {
                                    /* Transition: '<S3>:289' */
                                    qY = SWatchFSM_DW->minutes_T - 1U;
                                    if (qY > SWatchFSM_DW->minutes_T) {
                                        qY = 0U;
                                    }

                                    SWatchFSM_DW->minutes_T = (uint8_T)qY;
                                    if ((SWatchFSM_DW->minutes_T == 0) &&
                                            (SWatchFSM_DW->hours_T > 0)) {
                                        /* Transition: '<S3>:209' */
                                        SWatchFSM_DW->minutes_T = 59U;
                                        qY = SWatchFSM_DW->hours_T - 1U;
                                        if (qY > SWatchFSM_DW->hours_T) {
                                            qY = 0U;
                                        }

                                        SWatchFSM_DW->hours_T = (uint8_T)qY;
                                    } else {
                                        /* Transition: '<S3>:206' */
                                    }
                                }
                            } else {
                                /* Transition: '<S3>:210' */
                            }

                            guard1 = true;
                        }
                    }
                } else {
                    /* Transition: '<S3>:203' */
                    guard1 = true;
                }

                if (guard1) {
                    /* Transition: '<S3>:204' */
                    SWatchFSM_DW->is_Timer_mng = SWatchFSM_IN_T_count;
                }
            }
        }
    } else {
        /* During 'T_stop': '<S3>:187' */
        if ((SWatchFSM_DW->sfEvent == SWatchFSM_event_start_b) &&
                (*SWatchFSM_Y_mode == 3) && ((SWatchFSM_DW->hours_T > 0) ||
                ((SWatchFSM_DW->hours_T == 0) && (SWatchFSM_DW->minutes_T > 0)) ||
             ((SWatchFSM_DW->hours_T == 0) && (SWatchFSM_DW->minutes_T == 0) &&
                (SWatchFSM_DW->seconds_T > 0)))) {
            /* Transition: '<S3>:194' */
            SWatchFSM_DW->is_Timer_mng = SWatchFSM_IN_T_count;
        }
    }
}

/* Model step function */
void SWatchFSM_step(RT_MODEL_SWatchFSM_T *const SWatchFSM_M, boolean_T
                    SWatchFSM_U_watch_b, boolean_T SWatchFSM_U_swatch_b,
                    boolean_T SWatchFSM_U_alarm_b, boolean_T SWatchFSM_U_timer_b,
                    boolean_T SWatchFSM_U_plus_b, boolean_T SWatchFSM_U_minus_b,
                    boolean_T SWatchFSM_U_start_b, boolean_T SWatchFSM_U_stop_b,
                    uint8_T *SWatchFSM_Y_hours_D, uint8_T *SWatchFSM_Y_minutes_D,
                    uint8_T *SWatchFSM_Y_seconds_D, uint8_T
                    *SWatchFSM_Y_tenths_D, uint8_T *SWatchFSM_Y_mode, uint8_T
                    *SWatchFSM_Y_swatchrun, uint8_T *SWatchFSM_Y_watchset,
                    uint8_T *SWatchFSM_Y_alarm_exp, uint8_T
                    *SWatchFSM_Y_time_exp)
{
    DW_SWatchFSM_T *SWatchFSM_DW = ((DW_SWatchFSM_T *)
        SWatchFSM_M->ModelData.dwork);
    PrevZCX_SWatchFSM_T *SWatchFSM_PrevZCX = ((PrevZCX_SWatchFSM_T *)
        SWatchFSM_M->ModelData.prevZCSigState);
    uint8_T rtb_FixPtSum1;
    boolean_T zcEvent[9];
    int8_T rtb_inputevents[9];
    int32_T i;
    boolean_T tmp;

    /* Chart: '<S1>/SWatch' incorporates:
     *  TriggerPort: '<S3>/ input events '
     */
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  UnitDelay: '<S2>/Output'
     */
    zcEvent[0] = ((SWatchFSM_DW->Output_DSTATE != 0) &&
                  (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[0] != POS_ZCSIG));

    /* Inport: '<Root>/watch_b' */
    zcEvent[1] = (SWatchFSM_U_watch_b && (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[1]
                   != POS_ZCSIG));

    /* Inport: '<Root>/swatch_b' */
    zcEvent[2] = (SWatchFSM_U_swatch_b && (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[2]
                   != POS_ZCSIG));

    /* Inport: '<Root>/alarm_b' */
    zcEvent[3] = (SWatchFSM_U_alarm_b && (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[3]
                   != POS_ZCSIG));

    /* Inport: '<Root>/timer_b' */
    zcEvent[4] = (SWatchFSM_U_timer_b && (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[4]
                   != POS_ZCSIG));

    /* Inport: '<Root>/plus_b' */
    zcEvent[5] = (SWatchFSM_U_plus_b && (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[5]
                   != POS_ZCSIG));

    /* Inport: '<Root>/minus_b' */
    zcEvent[6] = (SWatchFSM_U_minus_b && (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[6]
                   != POS_ZCSIG));

    /* Inport: '<Root>/start_b' */
    zcEvent[7] = (SWatchFSM_U_start_b && (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[7]
                   != POS_ZCSIG));

    /* Inport: '<Root>/stop_b' */
    zcEvent[8] = (SWatchFSM_U_stop_b && (SWatchFSM_PrevZCX->SWatch_Trig_ZCE[8]
                   != POS_ZCSIG));
    tmp = false;
    for (i = 0; i < 9; i++) {
        tmp = (tmp || zcEvent[i]);
    }

    if (tmp) {
        for (i = 0; i < 9; i++) {
            rtb_inputevents[i] = (int8_T)zcEvent[i];
        }

        /* Gateway: SWatchFSM/SWatch */
        if (rtb_inputevents[0U] == 1) {
            /* Event: '<S3>:5' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_tick_t;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }

        if (rtb_inputevents[1U] == 1) {
            /* Event: '<S3>:6' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_watch_b;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }

        if (rtb_inputevents[2U] == 1) {
            /* Event: '<S3>:16' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_swatch_b;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }

        if (rtb_inputevents[3U] == 1) {
            /* Event: '<S3>:7' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_alarm_b;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }

        if (rtb_inputevents[4U] == 1) {
            /* Event: '<S3>:8' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_timer_b;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }

        if (rtb_inputevents[5U] == 1) {
            /* Event: '<S3>:9' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_plus_b;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }

        if (rtb_inputevents[6U] == 1) {
            /* Event: '<S3>:10' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_minus_b;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }

        if (rtb_inputevents[7U] == 1) {
            /* Event: '<S3>:11' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_start_b;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }

        if (rtb_inputevents[8U] == 1) {
            /* Event: '<S3>:12' */
            SWatchFSM_DW->sfEvent = SWatchFSM_event_stop_b;
            SWatchFS_chartstep_c3_SWatchFSM(SWatchFSM_Y_hours_D,
                SWatchFSM_Y_minutes_D, SWatchFSM_Y_seconds_D,
                SWatchFSM_Y_tenths_D, SWatchFSM_Y_mode, SWatchFSM_Y_swatchrun,
                SWatchFSM_Y_watchset, SWatchFSM_Y_alarm_exp,
                SWatchFSM_Y_time_exp, SWatchFSM_DW);
        }
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  UnitDelay: '<S2>/Output'
     */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[0] = (uint8_T)
        (SWatchFSM_DW->Output_DSTATE != 0 ? (int32_T)POS_ZCSIG : (int32_T)
         ZERO_ZCSIG);

    /* Inport: '<Root>/watch_b' */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[1] = (uint8_T)(SWatchFSM_U_watch_b ?
        (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

    /* Inport: '<Root>/swatch_b' */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[2] = (uint8_T)(SWatchFSM_U_swatch_b ?
        (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

    /* Inport: '<Root>/alarm_b' */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[3] = (uint8_T)(SWatchFSM_U_alarm_b ?
        (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

    /* Inport: '<Root>/timer_b' */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[4] = (uint8_T)(SWatchFSM_U_timer_b ?
        (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

    /* Inport: '<Root>/plus_b' */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[5] = (uint8_T)(SWatchFSM_U_plus_b ?
        (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

    /* Inport: '<Root>/minus_b' */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[6] = (uint8_T)(SWatchFSM_U_minus_b ?
        (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

    /* Inport: '<Root>/start_b' */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[7] = (uint8_T)(SWatchFSM_U_start_b ?
        (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

    /* Inport: '<Root>/stop_b' */
    SWatchFSM_PrevZCX->SWatch_Trig_ZCE[8] = (uint8_T)(SWatchFSM_U_stop_b ?
        (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

    /* Sum: '<S4>/FixPt Sum1' incorporates:
     *  Constant: '<S4>/FixPt Constant'
     *  UnitDelay: '<S2>/Output'
     */
    rtb_FixPtSum1 = (uint8_T)(SWatchFSM_DW->Output_DSTATE + 1U);

    /* Switch: '<S5>/FixPt Switch' */
    if (rtb_FixPtSum1 > 1) {
        /* Update for UnitDelay: '<S2>/Output' incorporates:
         *  Constant: '<S5>/Constant'
         */
        SWatchFSM_DW->Output_DSTATE = 0U;
    } else {
        /* Update for UnitDelay: '<S2>/Output' */
        SWatchFSM_DW->Output_DSTATE = rtb_FixPtSum1;
    }

    /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model initialize function */
void SWatchFSM_initialize(RT_MODEL_SWatchFSM_T *const SWatchFSM_M, boolean_T
    *SWatchFSM_U_watch_b, boolean_T *SWatchFSM_U_swatch_b, boolean_T
    *SWatchFSM_U_alarm_b, boolean_T *SWatchFSM_U_timer_b, boolean_T
    *SWatchFSM_U_plus_b, boolean_T *SWatchFSM_U_minus_b, boolean_T
    *SWatchFSM_U_start_b, boolean_T *SWatchFSM_U_stop_b, uint8_T
    *SWatchFSM_Y_hours_D, uint8_T *SWatchFSM_Y_minutes_D, uint8_T
    *SWatchFSM_Y_seconds_D, uint8_T *SWatchFSM_Y_tenths_D, uint8_T
    *SWatchFSM_Y_mode, uint8_T *SWatchFSM_Y_swatchrun, uint8_T
    *SWatchFSM_Y_watchset, uint8_T *SWatchFSM_Y_alarm_exp, uint8_T
    *SWatchFSM_Y_time_exp)
{
    DW_SWatchFSM_T *SWatchFSM_DW = ((DW_SWatchFSM_T *)
        SWatchFSM_M->ModelData.dwork);
    PrevZCX_SWatchFSM_T *SWatchFSM_PrevZCX = ((PrevZCX_SWatchFSM_T *)
        SWatchFSM_M->ModelData.prevZCSigState);

    /* Registration code */

    /* states (dwork) */
    (void) memset((void *)SWatchFSM_DW, 0,
                  sizeof(DW_SWatchFSM_T));

    /* external inputs */
    (*SWatchFSM_U_watch_b) = false;
    (*SWatchFSM_U_swatch_b) = false;
    (*SWatchFSM_U_alarm_b) = false;
    (*SWatchFSM_U_timer_b) = false;
    (*SWatchFSM_U_plus_b) = false;
    (*SWatchFSM_U_minus_b) = false;
    (*SWatchFSM_U_start_b) = false;
    (*SWatchFSM_U_stop_b) = false;

    /* external outputs */
    (*SWatchFSM_Y_hours_D) = 0U;
    (*SWatchFSM_Y_minutes_D) = 0U;
    (*SWatchFSM_Y_seconds_D) = 0U;
    (*SWatchFSM_Y_tenths_D) = 0U;
    (*SWatchFSM_Y_mode) = 0U;
    (*SWatchFSM_Y_swatchrun) = 0U;
    (*SWatchFSM_Y_watchset) = 0U;
    (*SWatchFSM_Y_alarm_exp) = 0U;
    (*SWatchFSM_Y_time_exp) = 0U;

    {
        int32_T i;
        for (i = 0; i < 9; i++) {
            SWatchFSM_PrevZCX->SWatch_Trig_ZCE[i] = POS_ZCSIG;
        }

        /* InitializeConditions for Chart: '<S1>/SWatch' */
        SWatchFSM_DW->is_alarm_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->was_alarm_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_alarm_set = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_swatch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->was_swatch_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_timer_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->was_timer_m = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_timer_set = SWatchFSM_IN_NO_ACTIVE_CHILD;
        SWatchFSM_DW->is_watch_settime = SWatchFSM_IN_NO_ACTIVE_CHILD;

        /* Entry: SWatchFSM/SWatch */
        /* Entry Internal: SWatchFSM/SWatch */
        SWatchFSM_DW->is_active_Mode_mng = 1U;

        /* Entry Internal 'Mode_mng': '<S3>:19' */
        /* Transition: '<S3>:29' */
        SWatchFSM_DW->is_Mode_mng = SWatchFSM_IN_watch_m;

        /* InitializeConditions for Outport: '<Root>/mode' incorporates:
         *  InitializeConditions for Chart: '<S1>/SWatch'
         */
        /* Entry 'watch_m': '<S3>:20' */
        *SWatchFSM_Y_mode = 0U;

        /* InitializeConditions for Outport: '<Root>/watchset' incorporates:
         *  InitializeConditions for Chart: '<S1>/SWatch'
         */
        /* Entry Internal 'watch_m': '<S3>:20' */
        /* Transition: '<S3>:252' */
        *SWatchFSM_Y_watchset = 0U;

        /* InitializeConditions for Chart: '<S1>/SWatch' */
        SWatchFSM_DW->is_watch_m = SWatchFSM_IN_watch_showtime;
        SWatchFSM_DW->is_active_Watch_mng = 1U;

        /* Entry Internal 'Watch_mng': '<S3>:36' */
        /* Transition: '<S3>:46' */
        SWatchFSM_DW->hours_W = 0U;
        SWatchFSM_DW->minutes_W = 0U;
        SWatchFSM_DW->seconds_W = 0U;
        SWatchFSM_DW->tenths_W = 0U;
        SWatchFSM_DW->is_Watch_mng = SWatchFSM_IN_W_count;
        SWatchFSM_DW->is_active_Swatch_mng = 1U;

        /* Entry Internal 'Swatch_mng': '<S3>:69' */
        /* Transition: '<S3>:80' */
        SWatchFSM_DW->hours_S = 0U;
        SWatchFSM_DW->minutes_S = 0U;
        SWatchFSM_DW->seconds_S = 0U;
        SWatchFSM_DW->tenths_S = 0U;
        SWatchFSM_DW->is_Swatch_mng = SWatchFSM_IN_S_stop;
        SWatchFSM_DW->is_active_Alarm_mng = 1U;

        /* Entry Internal 'Alarm_mng': '<S3>:106' */
        /* Transition: '<S3>:162' */
        SWatchFSM_DW->hours_A = 0U;
        SWatchFSM_DW->minutes_A = 0U;

        /* InitializeConditions for Outport: '<Root>/alarm_exp' incorporates:
         *  InitializeConditions for Chart: '<S1>/SWatch'
         */
        *SWatchFSM_Y_alarm_exp = 0U;

        /* InitializeConditions for Chart: '<S1>/SWatch' */
        SWatchFSM_DW->is_Alarm_mng = SWatchFSM_IN_A_stop;
        SWatchFSM_DW->is_active_Timer_mng = 1U;

        /* Entry Internal 'Timer_mng': '<S3>:107' */
        /* Transition: '<S3>:190' */
        SWatchFSM_DW->hours_T = 0U;
        SWatchFSM_DW->minutes_T = 0U;
        SWatchFSM_DW->seconds_T = 0U;
        SWatchFSM_DW->tenths_T = 0U;

        /* InitializeConditions for Outport: '<Root>/time_exp' incorporates:
         *  InitializeConditions for Chart: '<S1>/SWatch'
         */
        *SWatchFSM_Y_time_exp = 0U;

        /* InitializeConditions for Chart: '<S1>/SWatch' */
        SWatchFSM_DW->is_Timer_mng = SWatchFSM_IN_T_stop;
    }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

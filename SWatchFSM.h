/*
 * File: SWatchFSM.h
 *
 * Code generated for Simulink model 'SWatchFSM'.
 *
 * Model version                  : 1.199
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Wed Feb 17 14:10:03 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWatchFSM_h_
#define RTW_HEADER_SWatchFSM_h_
#include <string.h>
#ifndef SWatchFSM_COMMON_INCLUDES_
# define SWatchFSM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWatchFSM_COMMON_INCLUDES_ */

#include "SWatchFSM_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
    int32_T sfEvent;                   /* '<S1>/SWatch' */
    uint8_T Output_DSTATE;             /* '<S2>/Output' */
    uint8_T is_Mode_mng;               /* '<S1>/SWatch' */
    uint8_T is_active_Mode_mng;        /* '<S1>/SWatch' */
    uint8_T is_watch_m;                /* '<S1>/SWatch' */
    uint8_T is_watch_settime;          /* '<S1>/SWatch' */
    uint8_T is_swatch_m;               /* '<S1>/SWatch' */
    uint8_T was_swatch_m;              /* '<S1>/SWatch' */
    uint8_T is_alarm_m;                /* '<S1>/SWatch' */
    uint8_T was_alarm_m;               /* '<S1>/SWatch' */
    uint8_T is_alarm_set;              /* '<S1>/SWatch' */
    uint8_T is_timer_m;                /* '<S1>/SWatch' */
    uint8_T was_timer_m;               /* '<S1>/SWatch' */
    uint8_T is_timer_set;              /* '<S1>/SWatch' */
    uint8_T is_Watch_mng;              /* '<S1>/SWatch' */
    uint8_T is_active_Watch_mng;       /* '<S1>/SWatch' */
    uint8_T is_Swatch_mng;             /* '<S1>/SWatch' */
    uint8_T is_active_Swatch_mng;      /* '<S1>/SWatch' */
    uint8_T is_Alarm_mng;              /* '<S1>/SWatch' */
    uint8_T is_active_Alarm_mng;       /* '<S1>/SWatch' */
    uint8_T is_Timer_mng;              /* '<S1>/SWatch' */
    uint8_T is_active_Timer_mng;       /* '<S1>/SWatch' */
    uint8_T hours_W;                   /* '<S1>/SWatch' */
    uint8_T minutes_W;                 /* '<S1>/SWatch' */
    uint8_T seconds_W;                 /* '<S1>/SWatch' */
    uint8_T tenths_W;                  /* '<S1>/SWatch' */
    uint8_T hours_S;                   /* '<S1>/SWatch' */
    uint8_T minutes_S;                 /* '<S1>/SWatch' */
    uint8_T seconds_S;                 /* '<S1>/SWatch' */
    uint8_T tenths_S;                  /* '<S1>/SWatch' */
    uint8_T minutes_A;                 /* '<S1>/SWatch' */
    uint8_T hours_A;                   /* '<S1>/SWatch' */
    uint8_T tenths_T;                  /* '<S1>/SWatch' */
    uint8_T seconds_T;                 /* '<S1>/SWatch' */
    uint8_T minutes_T;                 /* '<S1>/SWatch' */
    uint8_T hours_T;                   /* '<S1>/SWatch' */
    uint8_T alarm_cycle;               /* '<S1>/SWatch' */
} DW_SWatchFSM_T;

/* Zero-crossing (trigger) state */
typedef struct {
    ZCSigState SWatch_Trig_ZCE[9];     /* '<S1>/SWatch' */
} PrevZCX_SWatchFSM_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWatchFSM_T {
    const char_T *errorStatus;

    /*
     * ModelData:
     * The following substructure contains information regarding
     * the data used in the model.
     */
    struct {
        PrevZCX_SWatchFSM_T *prevZCSigState;
        DW_SWatchFSM_T *dwork;
    } ModelData;
};

/* Model entry point functions */
extern void SWatchFSM_initialize(RT_MODEL_SWatchFSM_T *const SWatchFSM_M,
    boolean_T *SWatchFSM_U_watch_b, boolean_T *SWatchFSM_U_swatch_b, boolean_T
    *SWatchFSM_U_alarm_b, boolean_T *SWatchFSM_U_timer_b, boolean_T
    *SWatchFSM_U_plus_b, boolean_T *SWatchFSM_U_minus_b, boolean_T
    *SWatchFSM_U_start_b, boolean_T *SWatchFSM_U_stop_b, uint8_T
    *SWatchFSM_Y_hours_D, uint8_T *SWatchFSM_Y_minutes_D, uint8_T
    *SWatchFSM_Y_seconds_D, uint8_T *SWatchFSM_Y_tenths_D, uint8_T
    *SWatchFSM_Y_mode, uint8_T *SWatchFSM_Y_swatchrun, uint8_T
    *SWatchFSM_Y_watchset, uint8_T *SWatchFSM_Y_alarm_status, uint8_T
    *SWatchFSM_Y_time_exp);
extern void SWatchFSM_step(RT_MODEL_SWatchFSM_T *const SWatchFSM_M, boolean_T
    SWatchFSM_U_watch_b, boolean_T SWatchFSM_U_swatch_b, boolean_T
    SWatchFSM_U_alarm_b, boolean_T SWatchFSM_U_timer_b, boolean_T
    SWatchFSM_U_plus_b, boolean_T SWatchFSM_U_minus_b, boolean_T
    SWatchFSM_U_start_b, boolean_T SWatchFSM_U_stop_b, uint8_T
    *SWatchFSM_Y_hours_D, uint8_T *SWatchFSM_Y_minutes_D, uint8_T
    *SWatchFSM_Y_seconds_D, uint8_T *SWatchFSM_Y_tenths_D, uint8_T
    *SWatchFSM_Y_mode, uint8_T *SWatchFSM_Y_swatchrun, uint8_T
    *SWatchFSM_Y_watchset, uint8_T *SWatchFSM_Y_alarm_status, uint8_T
    *SWatchFSM_Y_time_exp);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('SwatchModel/SWatchFSM')    - opens subsystem SwatchModel/SWatchFSM
 * hilite_system('SwatchModel/SWatchFSM/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SwatchModel'
 * '<S1>'   : 'SwatchModel/SWatchFSM'
 * '<S2>'   : 'SwatchModel/SWatchFSM/Counter Limited'
 * '<S3>'   : 'SwatchModel/SWatchFSM/SWatch'
 * '<S4>'   : 'SwatchModel/SWatchFSM/Counter Limited/Increment Real World'
 * '<S5>'   : 'SwatchModel/SWatchFSM/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_SWatchFSM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

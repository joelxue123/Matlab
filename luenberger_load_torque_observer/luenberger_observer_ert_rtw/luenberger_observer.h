/*
 * File: luenberger_observer.h
 *
 * Code generated for Simulink model 'luenberger_observer'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Jul  2 19:11:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_luenberger_observer_h_
#define RTW_HEADER_luenberger_observer_h_
#ifndef luenberger_observer_COMMON_INCLUDES_
#define luenberger_observer_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* luenberger_observer_COMMON_INCLUDES_ */

#include "luenberger_observer_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator1_DSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator2_DSTATE;           /* '<S1>/Integrator2' */
  real_T Integrator_DSTATE;            /* '<Root>/Integrator' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_luenberger_observer_T;

/* Real-time Model Data Structure */
struct tag_RTM_luenberger_observer_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_luenberger_observer_T luenberger_observer_DW;

/* Model entry point functions */
extern void luenberger_observer_initialize(void);
extern void luenberger_observer_step(void);
extern void luenberger_observer_terminate(void);

/* Real-time Model object */
extern RT_MODEL_luenberger_observer_T *const luenberger_observer_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'luenberger_observer'
 * '<S1>'   : 'luenberger_observer/Subsystem'
 */
#endif                                 /* RTW_HEADER_luenberger_observer_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

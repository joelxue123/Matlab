/*
 * File: pll.h
 *
 * Code generated for Simulink model 'pll'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 30 14:00:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pll_h_
#define RTW_HEADER_pll_h_
#ifndef pll_COMMON_INCLUDES_
#define pll_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pll_COMMON_INCLUDES_ */

#include "pll_types.h"
#include "rtw_modelmap.h"
#include <string.h>
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Integrator1;                  /* '<S1>/Integrator1' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T Integrator;                   /* '<S1>/Integrator' */
  real_T Sum;                          /* '<S1>/Sum' */
} B_pll_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator1_DSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator_DSTATE;            /* '<S1>/Integrator' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
} DW_pll_T;

/* Real-time Model Data Structure */
struct tag_RTM_pll_T {
  const char_T * volatile errorStatus;
  B_pll_T *blockIO;
  DW_pll_T *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Model entry point functions */
extern void pll_initialize(RT_MODEL_pll_T *const pll_M);
extern void pll_step(RT_MODEL_pll_T *const pll_M);
extern void pll_terminate(RT_MODEL_pll_T *const pll_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  pll_GetCAPIStaticMap(void);

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
 * '<Root>' : 'pll'
 * '<S1>'   : 'pll/Subsystem'
 */
#endif                                 /* RTW_HEADER_pll_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

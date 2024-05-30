/*
 * File: pll.c
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

#include "pll.h"
#include <math.h>
#include "rtwtypes.h"
#include "pll_capi.h"
#include <string.h>

/* Model step function */
void pll_step(RT_MODEL_pll_T *const pll_M)
{
  B_pll_T *pll_B = pll_M->blockIO;
  DW_pll_T *pll_DW = pll_M->dwork;
  real_T HoldCosine;
  real_T HoldSine;

  /* DiscreteIntegrator: '<S1>/Integrator1' */
  pll_B->Integrator1 = pll_DW->Integrator1_DSTATE;

  /* Sin: '<Root>/Sine Wave' */
  if (pll_DW->systemEnable != 0) {
    pll_DW->lastSin = sin(100.0 * ((pll_M->Timing.clockTick0) * 5.0E-5));
    pll_DW->lastCos = cos(100.0 * ((pll_M->Timing.clockTick0) * 5.0E-5));
    pll_DW->systemEnable = 0;
  }

  /* Sin: '<Root>/Sine Wave' */
  pll_B->SineWave = ((pll_DW->lastSin * 0.99998750002604164 + pll_DW->lastCos *
                      (-0.0049999791666927081)) * 0.99998750002604164 +
                     (pll_DW->lastCos * 0.99998750002604164 - pll_DW->lastSin *
                      (-0.0049999791666927081)) * 0.0049999791666927081) * 1.0 +
    0.0;

  /* Sum: '<S1>/Sum1' */
  pll_B->Sum1 = pll_B->SineWave - pll_B->Integrator1;

  /* Gain: '<S1>/Gain' */
  pll_B->Gain = 1000.0 * pll_B->Sum1;

  /* Gain: '<S1>/Gain1' */
  pll_B->Gain1 = 250000.0 * pll_B->Sum1;

  /* DiscreteIntegrator: '<S1>/Integrator' */
  pll_B->Integrator = pll_DW->Integrator_DSTATE;

  /* Sum: '<S1>/Sum' */
  pll_B->Sum = pll_B->Gain + pll_B->Integrator;

  /* Update for DiscreteIntegrator: '<S1>/Integrator1' */
  pll_DW->Integrator1_DSTATE += 5.0E-5 * pll_B->Sum;

  /* Update for Sin: '<Root>/Sine Wave' */
  HoldSine = pll_DW->lastSin;
  HoldCosine = pll_DW->lastCos;
  pll_DW->lastSin = HoldSine * 0.99998750002604164 + HoldCosine *
    0.0049999791666927081;
  pll_DW->lastCos = HoldCosine * 0.99998750002604164 - HoldSine *
    0.0049999791666927081;

  /* Update for DiscreteIntegrator: '<S1>/Integrator' */
  pll_DW->Integrator_DSTATE += 5.0E-5 * pll_B->Gain1;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 5.0E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  pll_M->Timing.clockTick0++;
}

/* Model initialize function */
void pll_initialize(RT_MODEL_pll_T *const pll_M)
{
  DW_pll_T *pll_DW = pll_M->dwork;
  B_pll_T *pll_B = pll_M->blockIO;

  /* Registration code */

  /* block I/O */
  (void) memset(((void *) pll_B), 0,
                sizeof(B_pll_T));

  /* states (dwork) */
  (void) memset((void *)pll_DW, 0,
                sizeof(DW_pll_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  pll_InitializeDataMapInfo(pll_M);

  /* Enable for Sin: '<Root>/Sine Wave' */
  pll_DW->systemEnable = 1;
}

/* Model terminate function */
void pll_terminate(RT_MODEL_pll_T *const pll_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(pll_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

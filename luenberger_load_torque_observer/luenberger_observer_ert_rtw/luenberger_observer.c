/*
 * File: luenberger_observer.c
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

#include "luenberger_observer.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_luenberger_observer_T luenberger_observer_DW;

/* Real-time model */
static RT_MODEL_luenberger_observer_T luenberger_observer_M_;
RT_MODEL_luenberger_observer_T *const luenberger_observer_M =
  &luenberger_observer_M_;

/* Model step function */
void luenberger_observer_step(void)
{
  real_T rtb_Gain4;
  real_T rtb_Gain6;
  real_T rtb_Integrator;
  real_T rtb_Sum;

  /* DiscreteIntegrator: '<Root>/Integrator' */
  rtb_Integrator = luenberger_observer_DW.Integrator_DSTATE;

  /* Sum: '<S1>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S1>/Integrator1'
   */
  rtb_Sum = rtb_Integrator - luenberger_observer_DW.Integrator1_DSTATE;

  /* Gain: '<S1>/Gain4' */
  rtb_Gain4 = 2000.0 * rtb_Sum;

  /* Gain: '<S1>/Gain6' */
  rtb_Gain6 = -100.0 * rtb_Sum;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if ((luenberger_observer_DW.clockTickCounter < 5000) &&
      (luenberger_observer_DW.clockTickCounter >= 0)) {
    rtb_Sum = 0.5;
  } else {
    rtb_Sum = 0.0;
  }

  if (luenberger_observer_DW.clockTickCounter >= 9999) {
    luenberger_observer_DW.clockTickCounter = 0;
  } else {
    luenberger_observer_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  rtb_Sum = (1.0 - rtb_Sum) - 0.01 * rtb_Integrator;

  /* Update for DiscreteIntegrator: '<S1>/Integrator1' incorporates:
   *  Constant: '<Root>/Constant'
   *  DiscreteIntegrator: '<S1>/Integrator2'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain5'
   *  Sum: '<S1>/Sum1'
   */
  luenberger_observer_DW.Integrator1_DSTATE += (((1.0 -
    luenberger_observer_DW.Integrator2_DSTATE) + 0.0001 * rtb_Gain4) - 0.01 *
    luenberger_observer_DW.Integrator1_DSTATE) * 10000.0 * 0.0001;

  /* Update for DiscreteIntegrator: '<S1>/Integrator2' */
  luenberger_observer_DW.Integrator2_DSTATE += 0.0001 * rtb_Gain6;

  /* Update for DiscreteIntegrator: '<Root>/Integrator' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  luenberger_observer_DW.Integrator_DSTATE += 10000.0 * rtb_Sum * 0.0001;
}

/* Model initialize function */
void luenberger_observer_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void luenberger_observer_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

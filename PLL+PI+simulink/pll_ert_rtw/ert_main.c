/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'pll'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 29 20:10:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "pll.h"                       /* Model header file */
#include <unistd.h>

static RT_MODEL_pll_T pll_M_;
static RT_MODEL_pll_T *const pll_MPtr = &pll_M_;/* Real-time model */
static B_pll_T pll_B;                  /* Observable signals */
static DW_pll_T pll_DW;                /* Observable states */


// 定时器函数
void timerFunction(int intervalSeconds) {
    printf("Timer task executed at %ld seconds.\n", time(NULL));
    sleep(intervalSeconds); // 暂停指定的秒数
}
/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_pll_T *const pll_M);
void rt_OneStep(RT_MODEL_pll_T *const pll_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(pll_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  pll_step(pll_M);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_pll_T *const pll_M = pll_MPtr;
  FILE *file;
  const char *filename = "derived_from_source_data.csv"; // CSV文件名

  file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  pll_M->blockIO = &pll_B;
  pll_M->dwork = &pll_DW;

  /* Initialize model */
  pll_initialize(pll_M);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 5.0E-5 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep(pll_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  int step = 0;
  int max_step = 5000;

  while (rtmGetErrorStatus(pll_M) == (NULL)) {
   
   if(step < max_step )
   {
    step++;
    rt_OneStep(pll_M);
    printf("origin_sigal %f\n", pll_M->blockIO->SineWave);
    printf("drived_from source signal %f\n", pll_M->dwork->Integrator_DSTATE);

        // 写入数据到CSV文件，每个数据对占一行，中间用逗号分隔

    fprintf(file, "%f,%f\n", pll_M->blockIO->SineWave, pll_M->dwork->Integrator_DSTATE);
 
   }
   else
   {
    fclose(file);
    printf("step up to %d",max_step);
    break;//terminal
   }
    /*  Perform application tasks here */
  }

  /* Terminate model */
  pll_terminate(pll_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

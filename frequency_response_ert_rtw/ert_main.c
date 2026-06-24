/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'frequency_response'.
 *
 * Model version                  : 13.6
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Wed Jun 24 14:09:17 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "frequency_response.h"
#include "rtwtypes.h"
#include "ext_mode.h"                  /* External mode header file */
#include "xcp.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)0;
  extmodeErrorCode_T extmodeError = EXTMODE_SUCCESS;

  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  enableTimer0Interrupt();
  extmodeTime = (extmodeSimulationTime_T)
    (((frequency_response_M->Timing.clockTick0 * 1) + 0));
  frequency_response_step();

  /* Get model outputs here */
  extmodeError = extmodeEvent((extmodeEventId_T)(0), extmodeTime);
  if (extmodeError != EXTMODE_SUCCESS) {
    /* Code to handle external mode event errors may be added here */
  }

  disableTimer0Interrupt();
  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int_T main(void)
{
  float modelBaseRate = 0.0005;
  float systemClock = 200;
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  c2000_flash_init();
  init_board();

#if defined(MW_EXEC_PROFILER_ON) || (defined(MW_EXTMODE_RUNNING) && !defined(XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME))

  hardwareTimer1Init();

#endif

  ;
  rtmSetErrorStatus(frequency_response_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, (const char_T**)NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return errorCode;
  }

  frequency_response_initialize();
  globalInterruptDisable();
  globalInterruptEnable();

  /* External Mode initialization */
  errorCode = extmodeInit(frequency_response_M->extModeInfo,
    (extmodeSimulationTime_T *)rteiGetPtrTFinalTicks
    (frequency_response_M->extModeInfo));
  if (errorCode != EXTMODE_SUCCESS) {
    return errorCode;
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(frequency_response_M, true);
    }
  }

  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    !extmodeSimulationComplete() && !extmodeStopRequested()&&
    !rtmGetStopRequested(frequency_response_M);
  enableTimer0Interrupt();
  initBoardEnd();
  globalInterruptEnable();
  while (runModel) {
    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS && errorCode != EXTMODE_EMPTY) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    stopRequested = !(
                      !extmodeSimulationComplete() && !extmodeStopRequested()&&
                      !rtmGetStopRequested(frequency_response_M));
    runModel = !(stopRequested);
    if (stopRequested)
      disableTimer0Interrupt();
  }

  /* Terminate model */
  frequency_response_terminate();

  /* External Mode reset */
  extmodeReset();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

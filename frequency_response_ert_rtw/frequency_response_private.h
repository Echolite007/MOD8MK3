/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: frequency_response_private.h
 *
 * Code generated for Simulink model 'frequency_response'.
 *
 * Model version                  : 13.4
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Wed Jun 24 11:42:12 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef frequency_response_private_h_
#define frequency_response_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "frequency_response_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void config_QEP_eQEP2(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);

#endif                                 /* frequency_response_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

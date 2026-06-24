/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: frequency_response.c
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

#include "frequency_response.h"
#include "frequency_response_private.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>

/* Block signals (default storage) */
B_frequency_response_T frequency_response_B;

/* Block states (default storage) */
DW_frequency_response_T frequency_response_DW;

/* Real-time model */
static RT_MODEL_frequency_response_T frequency_response_M_;
RT_MODEL_frequency_response_T *const frequency_response_M =
  &frequency_response_M_;

/* Model step function */
void frequency_response_step(void)
{
  real_T Fres;
  real_T b_f_start;
  real_T b_time;

  /* S-Function (c280xqep): '<S3>/Encoder' */
  {
    frequency_response_B.Encoder = EQep2Regs.QPOSCNT;/*eQEP Position Counter*/
  }

  /* Gain: '<S3>/increments to m(calculate yourself)' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  frequency_response_B.incrementstomcalculateyourself =
    frequency_response_P.incrementstomcalculateyourself_ * (real_T)
    frequency_response_B.Encoder;

  /* Sin: '<S2>/Sine Wave1' */
  if (frequency_response_DW.systemEnable != 0L) {
    Fres = frequency_response_P.multisineFrequencies[0] *
      ((frequency_response_M->Timing.clockTick0) * 0.0005);
    frequency_response_DW.lastSin = sin(Fres);
    frequency_response_DW.lastCos = cos(Fres);
    frequency_response_DW.systemEnable = 0L;
  }

  /* Sin: '<S2>/Sine Wave2' */
  if (frequency_response_DW.systemEnable_i != 0L) {
    Fres = frequency_response_P.multisineFrequencies[1] *
      ((frequency_response_M->Timing.clockTick0) * 0.0005);
    frequency_response_DW.lastSin_e = sin(Fres);
    frequency_response_DW.lastCos_d = cos(Fres);
    frequency_response_DW.systemEnable_i = 0L;
  }

  /* Sin: '<S2>/Sine Wave3' */
  if (frequency_response_DW.systemEnable_iq != 0L) {
    Fres = frequency_response_P.multisineFrequencies[2] *
      ((frequency_response_M->Timing.clockTick0) * 0.0005);
    frequency_response_DW.lastSin_o = sin(Fres);
    frequency_response_DW.lastCos_dm = cos(Fres);
    frequency_response_DW.systemEnable_iq = 0L;
  }

  /* Sin: '<S2>/Sine Wave4' */
  if (frequency_response_DW.systemEnable_im != 0L) {
    Fres = frequency_response_P.multisineFrequencies[3] *
      ((frequency_response_M->Timing.clockTick0) * 0.0005);
    frequency_response_DW.lastSin_i = sin(Fres);
    frequency_response_DW.lastCos_i = cos(Fres);
    frequency_response_DW.systemEnable_im = 0L;
  }

  /* Sin: '<S2>/Sine Wave5' */
  if (frequency_response_DW.systemEnable_n != 0L) {
    Fres = frequency_response_P.multisineFrequencies[4] *
      ((frequency_response_M->Timing.clockTick0) * 0.0005);
    frequency_response_DW.lastSin_l = sin(Fres);
    frequency_response_DW.lastCos_f = cos(Fres);
    frequency_response_DW.systemEnable_n = 0L;
  }

  /* MATLAB Function: '<S1>/ChirpGenerator' incorporates:
   *  DigitalClock: '<S1>/Digital Clock'
   */
  Fres = 1.0 / frequency_response_P.T;
  b_time = fmod(((frequency_response_M->Timing.clockTick0) * 0.0005),
                frequency_response_P.T);
  b_f_start = floor(frequency_response_P.f_start * frequency_response_P.T) *
    Fres;

  /* Gain: '<S1>/Gain' incorporates:
   *  MATLAB Function: '<S1>/ChirpGenerator'
   */
  frequency_response_B.Gain = sin(((floor(frequency_response_P.f_end *
    frequency_response_P.T) * Fres - b_f_start) / frequency_response_P.T *
    b_time / 2.0 + b_f_start) * 2.0 * 3.141592653589793 * b_time) *
    frequency_response_P.Gain_Gain;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sin: '<S2>/Sine Wave1'
   *  Sin: '<S2>/Sine Wave2'
   *  Sin: '<S2>/Sine Wave3'
   *  Sin: '<S2>/Sine Wave4'
   *  Sin: '<S2>/Sine Wave5'
   *  Sum: '<S2>/Sum'
   */
  if ((int16_T)frequency_response_P.inputType == 0) {
    Fres = ((((((frequency_response_DW.lastSin *
                 frequency_response_P.SineWave1_PCos +
                 frequency_response_DW.lastCos *
                 frequency_response_P.SineWave1_PSin) *
                frequency_response_P.SineWave1_HCos +
                (frequency_response_DW.lastCos *
                 frequency_response_P.SineWave1_PCos -
                 frequency_response_DW.lastSin *
                 frequency_response_P.SineWave1_PSin) *
                frequency_response_P.SineWave1_Hsin) *
               frequency_response_P.SineWave1_Amp +
               frequency_response_P.SineWave1_Bias) +
              (((frequency_response_DW.lastSin_e *
                 frequency_response_P.SineWave2_PCos +
                 frequency_response_DW.lastCos_d *
                 frequency_response_P.SineWave2_PSin) *
                frequency_response_P.SineWave2_HCos +
                (frequency_response_DW.lastCos_d *
                 frequency_response_P.SineWave2_PCos -
                 frequency_response_DW.lastSin_e *
                 frequency_response_P.SineWave2_PSin) *
                frequency_response_P.SineWave2_Hsin) *
               frequency_response_P.SineWave2_Amp +
               frequency_response_P.SineWave2_Bias)) +
             (((frequency_response_DW.lastSin_o *
                frequency_response_P.SineWave3_PCos +
                frequency_response_DW.lastCos_dm *
                frequency_response_P.SineWave3_PSin) *
               frequency_response_P.SineWave3_HCos +
               (frequency_response_DW.lastCos_dm *
                frequency_response_P.SineWave3_PCos -
                frequency_response_DW.lastSin_o *
                frequency_response_P.SineWave3_PSin) *
               frequency_response_P.SineWave3_Hsin) *
              frequency_response_P.SineWave3_Amp +
              frequency_response_P.SineWave3_Bias)) +
            (((frequency_response_DW.lastSin_i *
               frequency_response_P.SineWave4_PCos +
               frequency_response_DW.lastCos_i *
               frequency_response_P.SineWave4_PSin) *
              frequency_response_P.SineWave4_HCos +
              (frequency_response_DW.lastCos_i *
               frequency_response_P.SineWave4_PCos -
               frequency_response_DW.lastSin_i *
               frequency_response_P.SineWave4_PSin) *
              frequency_response_P.SineWave4_Hsin) *
             frequency_response_P.SineWave4_Amp +
             frequency_response_P.SineWave4_Bias)) +
      (((frequency_response_DW.lastSin_l * frequency_response_P.SineWave5_PCos +
         frequency_response_DW.lastCos_f * frequency_response_P.SineWave5_PSin) *
        frequency_response_P.SineWave5_HCos + (frequency_response_DW.lastCos_f *
         frequency_response_P.SineWave5_PCos - frequency_response_DW.lastSin_l *
         frequency_response_P.SineWave5_PSin) *
        frequency_response_P.SineWave5_Hsin) *
       frequency_response_P.SineWave5_Amp + frequency_response_P.SineWave5_Bias);
  } else {
    Fres = frequency_response_B.Gain;
  }

  /* Gain: '<Root>/K_sign' incorporates:
   *  Gain: '<Root>/GainU'
   *  MultiPortSwitch: '<Root>/Multiport Switch'
   */
  frequency_response_B.K_sign = frequency_response_P.GainU * Fres *
    frequency_response_P.K_sign;

  /* SignalConversion generated from: '<Root>/To Workspace' */
  frequency_response_B.TmpSignalConversionAt_asyncqueu[0] =
    frequency_response_B.K_sign;
  frequency_response_B.TmpSignalConversionAt_asyncqueu[1] =
    frequency_response_B.incrementstomcalculateyourself;

  /* Saturate: '<S3>/Protection Max 6.4512V Do not change!' */
  if (frequency_response_B.K_sign >
      frequency_response_P.ProtectionMax64512VDonotchange_) {
    Fres = frequency_response_P.ProtectionMax64512VDonotchange_;
  } else if (frequency_response_B.K_sign <
             frequency_response_P.ProtectionMax64512VDonotchang_l) {
    Fres = frequency_response_P.ProtectionMax64512VDonotchang_l;
  } else {
    Fres = frequency_response_B.K_sign;
  }

  /* Gain: '<S3>/double sided' incorporates:
   *  Gain: '<S3>/Voltage to PWM dutycycle'
   *  Saturate: '<S3>/Protection Max 6.4512V Do not change!'
   */
  Fres = frequency_response_P.VoltagetoPWMdutycycle_Gain * Fres *
    frequency_response_P.doublesided_Gain;

  /* Saturate: '<S3>/Saturation3' */
  if (Fres > frequency_response_P.Saturation3_UpperSat) {
    Fres = frequency_response_P.Saturation3_UpperSat;
  } else if (Fres < frequency_response_P.Saturation3_LowerSat) {
    Fres = frequency_response_P.Saturation3_LowerSat;
  }

  /* End of Saturate: '<S3>/Saturation3' */

  /* S-Function (c2802xpwm): '<S3>/ePWM' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant4'
   *  Sum: '<S3>/Sum1'
   */
  uint16_T tbprdValue4Outputs = EPwm4Regs.TBPRD;

  {
    EPwm4Regs.TBPRD = (uint16_T)(frequency_response_P.Constant_Value);
  }

  /*-- Update CMPA value for ePWM4 --*/
  {
    EPwm4Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)EPwm4Regs.TBPRD * (Fres +
      frequency_response_P.Constant4_Value) * 0.01);
  }

  /* S-Function (c2802xpwm): '<S3>/ePWM1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant3'
   *  Sum: '<S3>/Sum'
   */
  uint16_T tbprdValue5Outputs = EPwm5Regs.TBPRD;
  EPwm5Regs.TBPHS.bit.TBPHS = (uint16_T)frequency_response_P.Constant3_Value;

  /*-- Update CMPA value for ePWM5 --*/
  {
    EPwm5Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)EPwm5Regs.TBPRD * (Fres +
      frequency_response_P.Constant1_Value) * 0.01);
  }

  /* Gain: '<Root>/displ to angle' */
  frequency_response_B.displtoangle = frequency_response_P.displtoangle_Gain *
    frequency_response_B.incrementstomcalculateyourself;

  /* Update for Sin: '<S2>/Sine Wave1' */
  Fres = frequency_response_DW.lastSin;
  frequency_response_DW.lastSin = frequency_response_DW.lastSin *
    frequency_response_P.SineWave1_HCos + frequency_response_DW.lastCos *
    frequency_response_P.SineWave1_Hsin;
  frequency_response_DW.lastCos = frequency_response_DW.lastCos *
    frequency_response_P.SineWave1_HCos - Fres *
    frequency_response_P.SineWave1_Hsin;

  /* Update for Sin: '<S2>/Sine Wave2' */
  Fres = frequency_response_DW.lastSin_e;
  frequency_response_DW.lastSin_e = frequency_response_DW.lastSin_e *
    frequency_response_P.SineWave2_HCos + frequency_response_DW.lastCos_d *
    frequency_response_P.SineWave2_Hsin;
  frequency_response_DW.lastCos_d = frequency_response_DW.lastCos_d *
    frequency_response_P.SineWave2_HCos - Fres *
    frequency_response_P.SineWave2_Hsin;

  /* Update for Sin: '<S2>/Sine Wave3' */
  Fres = frequency_response_DW.lastSin_o;
  frequency_response_DW.lastSin_o = frequency_response_DW.lastSin_o *
    frequency_response_P.SineWave3_HCos + frequency_response_DW.lastCos_dm *
    frequency_response_P.SineWave3_Hsin;
  frequency_response_DW.lastCos_dm = frequency_response_DW.lastCos_dm *
    frequency_response_P.SineWave3_HCos - Fres *
    frequency_response_P.SineWave3_Hsin;

  /* Update for Sin: '<S2>/Sine Wave4' */
  Fres = frequency_response_DW.lastSin_i;
  frequency_response_DW.lastSin_i = frequency_response_DW.lastSin_i *
    frequency_response_P.SineWave4_HCos + frequency_response_DW.lastCos_i *
    frequency_response_P.SineWave4_Hsin;
  frequency_response_DW.lastCos_i = frequency_response_DW.lastCos_i *
    frequency_response_P.SineWave4_HCos - Fres *
    frequency_response_P.SineWave4_Hsin;

  /* Update for Sin: '<S2>/Sine Wave5' */
  Fres = frequency_response_DW.lastSin_l;
  frequency_response_DW.lastSin_l = frequency_response_DW.lastSin_l *
    frequency_response_P.SineWave5_HCos + frequency_response_DW.lastCos_f *
    frequency_response_P.SineWave5_Hsin;
  frequency_response_DW.lastCos_f = frequency_response_DW.lastCos_f *
    frequency_response_P.SineWave5_HCos - Fres *
    frequency_response_P.SineWave5_Hsin;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0005, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  frequency_response_M->Timing.clockTick0++;
}

/* Model initialize function */
void frequency_response_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)frequency_response_M, 0,
                sizeof(RT_MODEL_frequency_response_T));
  rtmSetTFinal(frequency_response_M, 500.0);

  /* External mode info */
  frequency_response_M->Sizes.checksums[0] = (439431260U);
  frequency_response_M->Sizes.checksums[1] = (2076419083U);
  frequency_response_M->Sizes.checksums[2] = (2008336259U);
  frequency_response_M->Sizes.checksums[3] = (1014003825U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    frequency_response_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(frequency_response_M->extModeInfo,
      &frequency_response_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(frequency_response_M->extModeInfo,
                        frequency_response_M->Sizes.checksums);
    rteiSetTFinalTicks(frequency_response_M->extModeInfo, 1000000);
  }

  /* block I/O */
  (void) memset(((void *) &frequency_response_B), 0,
                sizeof(B_frequency_response_T));

  /* states (dwork) */
  (void) memset((void *)&frequency_response_DW, 0,
                sizeof(DW_frequency_response_T));

  /* Start for S-Function (c280xqep): '<S3>/Encoder' */
  config_QEP_eQEP2((uint32_T)4294967295U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)0, (uint16_T)4104, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c2802xpwm): '<S3>/ePWM' */
  real32_T tbprdValue4 = (real32_T)EPwm4Regs.TBPRD;

  /*** Initialize ePWM4 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL             = 1U;          -- Sync Output Select

       EPwm4Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm4Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm4Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm4Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm4Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm4Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
    EPwm4Regs.TBCTL2.all = (EPwm4Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 64000U;          // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm4Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm4Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm4Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm4Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm4Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm4Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm4Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm4Regs.CMPCTL2.all = (EPwm4Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm4Regs.CMPA.bit.CMPA = 32000U;  // Counter Compare A Register
    EPwm4Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm4Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm4Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
    EPwm4Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm4Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE             = 0U;          -- Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL               = 0;          -- Polarity Select Control
       EPwm4Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm4Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm4Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm4Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm4Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm4Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCASEL              = 0U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM4SOC Period Select
       EPwm4Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM4SOCB Period Select
       EPwm4Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm4Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM4INTn Period Select
       EPwm4Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7FU) | 0x1001U;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm4Regs.ETSOCPS.all = (EPwm4Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm4Regs.ETINTPS.all = (EPwm4Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4B
       EPwm4Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM4A action on DCAEVT1
       EPwm4Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM4A action on DCAEVT2
       EPwm4Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM4B action on DCBEVT1
       EPwm4Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM4B action on DCBEVT2
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm4Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm4Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm4Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm4Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm4Regs.DCACTL.all = (EPwm4Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm4Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm4Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm4Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm4Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm4Regs.DCBCTL.all = (EPwm4Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm4Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm4Regs.DCTRIPSEL.all = (EPwm4Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm4Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm4Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm4Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm4Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm4Regs.TZDCSEL.all = (EPwm4Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm4Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm4Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm4Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm4Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm4Regs.DCFCTL.all = (EPwm4Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm4Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm4Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm4Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm4Regs.DCCAPCTL.all = (EPwm4Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm4Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm4Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm4Regs.HRCNFG.all = (EPwm4Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm4Regs.EPWMXLINK.bit.TBPRDLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPALINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPBLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPCLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPDLINK = 3U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm4Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm4Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm4Regs.HRPCTL.all = (EPwm4Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S3>/ePWM1' */
  real32_T tbprdValue5 = (real32_T)EPwm5Regs.TBPRD;

  /*** Initialize ePWM5 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm5Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm5Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm5Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm5Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm5Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm5Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm5Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm5Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm5Regs.TBCTL.all = (EPwm5Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm5Regs.TBCTL2.all = (EPwm5Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm5Regs.TBPRD = 64000U;          // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm5Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm5Regs.TBPHS.all = (EPwm5Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm5Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm5Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm5Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm5Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm5Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm5Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm5Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm5Regs.CMPCTL.all = (EPwm5Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm5Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm5Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm5Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm5Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm5Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm5Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm5Regs.CMPCTL2.all = (EPwm5Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm5Regs.CMPA.bit.CMPA = 32000U;  // Counter Compare A Register
    EPwm5Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm5Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm5Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm5Regs.AQCTLA.all = 105U;
                               // Action Qualifier Control Register For Output A
    EPwm5Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm5Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm5Regs.AQSFRC.all = (EPwm5Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm5Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm5Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm5Regs.AQCSFRC.all = (EPwm5Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm5Regs.DBCTL.bit.OUT_MODE             = 0U;          -- Dead Band Output Mode Control
       EPwm5Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm5Regs.DBCTL.bit.POLSEL               = 0;          -- Polarity Select Control
       EPwm5Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm5Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm5Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm5Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm5Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm5Regs.DBCTL.all = (EPwm5Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm5Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm5Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm5Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm5Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm5Regs.ETSEL.bit.SOCASEL              = 0U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM5SOC Period Select
       EPwm5Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm5Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm5Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm5Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM5SOCB Period Select
       EPwm5Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm5Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM5INTn Enable
       EPwm5Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm5Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM5INTn Period Select
       EPwm5Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm5Regs.ETSEL.all = (EPwm5Regs.ETSEL.all & ~0xFF7FU) | 0x1001U;
    EPwm5Regs.ETPS.all = (EPwm5Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm5Regs.ETSOCPS.all = (EPwm5Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm5Regs.ETINTPS.all = (EPwm5Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm5Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm5Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm5Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm5Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm5Regs.PCCTL.all = (EPwm5Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm5Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm5Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM5A
       EPwm5Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM5B
       EPwm5Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM5A action on DCAEVT1
       EPwm5Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM5A action on DCAEVT2
       EPwm5Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM5B action on DCBEVT1
       EPwm5Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM5B action on DCBEVT2
     */
    EPwm5Regs.TZCTL.all = (EPwm5Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm5Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm5Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm5Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm5Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm5Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm5Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm5Regs.TZEINT.all = (EPwm5Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm5Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm5Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm5Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm5Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm5Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm5Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm5Regs.DCACTL.all = (EPwm5Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm5Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm5Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm5Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm5Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm5Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm5Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm5Regs.DCBCTL.all = (EPwm5Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm5Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm5Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm5Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm5Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm5Regs.DCTRIPSEL.all = (EPwm5Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm5Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm5Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm5Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm5Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm5Regs.TZDCSEL.all = (EPwm5Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm5Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm5Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm5Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm5Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm5Regs.DCFCTL.all = (EPwm5Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm5Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm5Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm5Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm5Regs.DCCAPCTL.all = (EPwm5Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm5Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm5Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm5Regs.HRCNFG.all = (EPwm5Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm5Regs.EPWMXLINK.bit.TBPRDLINK = 3U;
    EPwm5Regs.EPWMXLINK.bit.CMPALINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPBLINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPCLINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPDLINK = 4U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm5Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm5Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm5Regs.HRPCTL.all = (EPwm5Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Enable for Sin: '<S2>/Sine Wave1' */
  frequency_response_DW.systemEnable = 1L;

  /* Enable for Sin: '<S2>/Sine Wave2' */
  frequency_response_DW.systemEnable_i = 1L;

  /* Enable for Sin: '<S2>/Sine Wave3' */
  frequency_response_DW.systemEnable_iq = 1L;

  /* Enable for Sin: '<S2>/Sine Wave4' */
  frequency_response_DW.systemEnable_im = 1L;

  /* Enable for Sin: '<S2>/Sine Wave5' */
  frequency_response_DW.systemEnable_n = 1L;
}

/* Model terminate function */
void frequency_response_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

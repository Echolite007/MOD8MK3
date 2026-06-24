/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: frequency_response.h
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

#ifndef frequency_response_h_
#define frequency_response_h_
#ifndef frequency_response_COMMON_INCLUDES_
#define frequency_response_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* frequency_response_COMMON_INCLUDES_ */

#include "frequency_response_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&)
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);
extern void initBoardEnd(void);

/* Block signals (default storage) */
typedef struct {
  real_T Gain;                         /* '<S1>/Gain' */
  real_T K_sign;                       /* '<Root>/K_sign' */
  real_T incrementstomcalculateyourself;
                                /* '<S3>/increments to m(calculate yourself)' */
  real_T TmpSignalConversionAt_asyncqueu[2];
  /* '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To WorkspaceInport1' */
  int32_T Encoder;                     /* '<S3>/Encoder' */
} B_frequency_response_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T lastSin;                      /* '<S2>/Sine Wave1' */
  real_T lastCos;                      /* '<S2>/Sine Wave1' */
  real_T lastSin_e;                    /* '<S2>/Sine Wave2' */
  real_T lastCos_d;                    /* '<S2>/Sine Wave2' */
  real_T lastSin_o;                    /* '<S2>/Sine Wave3' */
  real_T lastCos_dm;                   /* '<S2>/Sine Wave3' */
  real_T lastSin_i;                    /* '<S2>/Sine Wave4' */
  real_T lastCos_i;                    /* '<S2>/Sine Wave4' */
  real_T lastSin_l;                    /* '<S2>/Sine Wave5' */
  real_T lastCos_f;                    /* '<S2>/Sine Wave5' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  int32_T systemEnable;                /* '<S2>/Sine Wave1' */
  int32_T systemEnable_i;              /* '<S2>/Sine Wave2' */
  int32_T systemEnable_iq;             /* '<S2>/Sine Wave3' */
  int32_T systemEnable_im;             /* '<S2>/Sine Wave4' */
  int32_T systemEnable_n;              /* '<S2>/Sine Wave5' */
  boolean_T doneDoubleBufferReInit;    /* '<S1>/ChirpGenerator' */
} DW_frequency_response_T;

/* Parameters (default storage) */
struct P_frequency_response_T_ {
  real_T GainU;                        /* Variable: GainU
                                        * Referenced by: '<Root>/GainU'
                                        */
  real_T K_sign;                       /* Variable: K_sign
                                        * Referenced by: '<Root>/K_sign'
                                        */
  real_T T;                            /* Variable: T
                                        * Referenced by: '<S1>/ChirpGenerator'
                                        */
  real_T f_end;                        /* Variable: f_end
                                        * Referenced by: '<S1>/ChirpGenerator'
                                        */
  real_T f_start;                      /* Variable: f_start
                                        * Referenced by: '<S1>/ChirpGenerator'
                                        */
  real_T inputType;                    /* Variable: inputType
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T multisineFrequencies[21];     /* Variable: multisineFrequencies
                                        * Referenced by:
                                        *   '<S2>/Sine Wave1'
                                        *   '<S2>/Sine Wave2'
                                        *   '<S2>/Sine Wave3'
                                        *   '<S2>/Sine Wave4'
                                        *   '<S2>/Sine Wave5'
                                        */
  real_T SineWave1_Amp;                /* Expression: 0.1
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Hsin;               /* Computed Parameter: SineWave1_Hsin
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_HCos;               /* Computed Parameter: SineWave1_HCos
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_PSin;               /* Computed Parameter: SineWave1_PSin
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_PCos;               /* Computed Parameter: SineWave1_PCos
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave2_Amp;                /* Expression: 0.1
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Hsin;               /* Computed Parameter: SineWave2_Hsin
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_HCos;               /* Computed Parameter: SineWave2_HCos
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_PSin;               /* Computed Parameter: SineWave2_PSin
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_PCos;               /* Computed Parameter: SineWave2_PCos
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave3_Amp;                /* Expression: 0.1
                                        * Referenced by: '<S2>/Sine Wave3'
                                        */
  real_T SineWave3_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave3'
                                        */
  real_T SineWave3_Phase;              /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave3'
                                        */
  real_T SineWave3_Hsin;               /* Computed Parameter: SineWave3_Hsin
                                        * Referenced by: '<S2>/Sine Wave3'
                                        */
  real_T SineWave3_HCos;               /* Computed Parameter: SineWave3_HCos
                                        * Referenced by: '<S2>/Sine Wave3'
                                        */
  real_T SineWave3_PSin;               /* Computed Parameter: SineWave3_PSin
                                        * Referenced by: '<S2>/Sine Wave3'
                                        */
  real_T SineWave3_PCos;               /* Computed Parameter: SineWave3_PCos
                                        * Referenced by: '<S2>/Sine Wave3'
                                        */
  real_T SineWave4_Amp;                /* Expression: 0.1
                                        * Referenced by: '<S2>/Sine Wave4'
                                        */
  real_T SineWave4_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave4'
                                        */
  real_T SineWave4_Phase;              /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave4'
                                        */
  real_T SineWave4_Hsin;               /* Computed Parameter: SineWave4_Hsin
                                        * Referenced by: '<S2>/Sine Wave4'
                                        */
  real_T SineWave4_HCos;               /* Computed Parameter: SineWave4_HCos
                                        * Referenced by: '<S2>/Sine Wave4'
                                        */
  real_T SineWave4_PSin;               /* Computed Parameter: SineWave4_PSin
                                        * Referenced by: '<S2>/Sine Wave4'
                                        */
  real_T SineWave4_PCos;               /* Computed Parameter: SineWave4_PCos
                                        * Referenced by: '<S2>/Sine Wave4'
                                        */
  real_T SineWave5_Amp;                /* Expression: 0.1
                                        * Referenced by: '<S2>/Sine Wave5'
                                        */
  real_T SineWave5_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave5'
                                        */
  real_T SineWave5_Phase;              /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave5'
                                        */
  real_T SineWave5_Hsin;               /* Computed Parameter: SineWave5_Hsin
                                        * Referenced by: '<S2>/Sine Wave5'
                                        */
  real_T SineWave5_HCos;               /* Computed Parameter: SineWave5_HCos
                                        * Referenced by: '<S2>/Sine Wave5'
                                        */
  real_T SineWave5_PSin;               /* Computed Parameter: SineWave5_PSin
                                        * Referenced by: '<S2>/Sine Wave5'
                                        */
  real_T SineWave5_PCos;               /* Computed Parameter: SineWave5_PCos
                                        * Referenced by: '<S2>/Sine Wave5'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.3
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T incrementstomcalculateyourself_;/* Expression: 2.441406e-7
                                          * Referenced by: '<S3>/increments to m(calculate yourself)'
                                          */
  real_T Constant_Value;               /* Expression: 64000/2^5
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T ProtectionMax64512VDonotchange_;/* Expression: 6.4512
                                          * Referenced by: '<S3>/Protection Max 6.4512V Do not change!'
                                          */
  real_T ProtectionMax64512VDonotchang_l;/* Expression: -6.4512
                                          * Referenced by: '<S3>/Protection Max 6.4512V Do not change!'
                                          */
  real_T VoltagetoPWMdutycycle_Gain;   /* Expression: 100/24
                                        * Referenced by: '<S3>/Voltage to PWM dutycycle'
                                        */
  real_T doublesided_Gain;             /* Expression: 0.5
                                        * Referenced by: '<S3>/double sided'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 25
                                        * Referenced by: '<S3>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -25
                                        * Referenced by: '<S3>/Saturation3'
                                        */
  real_T Constant4_Value;              /* Expression: 74
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 26
                                        * Referenced by: '<S3>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_frequency_response_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_frequency_response_T frequency_response_P;

/* Block signals (default storage) */
extern B_frequency_response_T frequency_response_B;

/* Block states (default storage) */
extern DW_frequency_response_T frequency_response_DW;

/* Model entry point functions */
extern void frequency_response_initialize(void);
extern void frequency_response_step(void);
extern void frequency_response_terminate(void);

/* Real-time Model object */
extern RT_MODEL_frequency_response_T *const frequency_response_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'frequency_response'
 * '<S1>'   : 'frequency_response/Chirp'
 * '<S2>'   : 'frequency_response/Multisine'
 * '<S3>'   : 'frequency_response/VCM '
 * '<S4>'   : 'frequency_response/Chirp/ChirpGenerator'
 */
#endif                                 /* frequency_response_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

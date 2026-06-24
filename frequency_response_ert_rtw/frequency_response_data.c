/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: frequency_response_data.c
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

/* Block parameters (default storage) */
P_frequency_response_T frequency_response_P = {
  /* Variable: GainU
   * Referenced by: '<Root>/GainU'
   */
  0.5,

  /* Variable: K_sign
   * Referenced by: '<Root>/K_sign'
   */
  1.0,

  /* Variable: T
   * Referenced by: '<S1>/ChirpGenerator'
   */
  50.0,

  /* Variable: f_end
   * Referenced by: '<S1>/ChirpGenerator'
   */
  150.0,

  /* Variable: f_start
   * Referenced by: '<S1>/ChirpGenerator'
   */
  0.5,

  /* Variable: inputType
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Variable: multisineFrequencies
   * Referenced by:
   *   '<S2>/Sine Wave1'
   *   '<S2>/Sine Wave2'
   *   '<S2>/Sine Wave3'
   *   '<S2>/Sine Wave4'
   *   '<S2>/Sine Wave5'
   */
  { 3.1415926535897931, 6.2831853071795862, 12.566370614359172,
    18.849555921538759, 31.415926535897931, 43.982297150257104,
    56.548667764616276, 75.398223686155035, 94.247779607693786,
    106.81415022205297, 125.66370614359172, 157.07963267948966,
    188.49555921538757, 251.32741228718345, 314.15926535897933, 439.822971502571,
    565.48667764616278, 753.98223686155029, 1005.3096491487338,
    1256.6370614359173, 1570.7963267948965 },

  /* Expression: 0.1
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.0,

  /* Computed Parameter: SineWave1_Hsin
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.0015707956808308789,

  /* Computed Parameter: SineWave1_HCos
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.99999876629970352,

  /* Computed Parameter: SineWave1_PSin
   * Referenced by: '<S2>/Sine Wave1'
   */
  -0.0015707956808308789,

  /* Computed Parameter: SineWave1_PCos
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.99999876629970352,

  /* Expression: 0.1
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.0,

  /* Computed Parameter: SineWave2_Hsin
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.0031415874858795635,

  /* Computed Parameter: SineWave2_HCos
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.99999506520185821,

  /* Computed Parameter: SineWave2_PSin
   * Referenced by: '<S2>/Sine Wave2'
   */
  -0.0031415874858795635,

  /* Computed Parameter: SineWave2_PCos
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.99999506520185821,

  /* Expression: 0.1
   * Referenced by: '<S2>/Sine Wave3'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave3'
   */
  0.0,

  /* Computed Parameter: SineWave3_Hsin
   * Referenced by: '<S2>/Sine Wave3'
   */
  0.0062831439655589511,

  /* Computed Parameter: SineWave3_HCos
   * Referenced by: '<S2>/Sine Wave3'
   */
  0.99998026085613712,

  /* Computed Parameter: SineWave3_PSin
   * Referenced by: '<S2>/Sine Wave3'
   */
  -0.0062831439655589511,

  /* Computed Parameter: SineWave3_PCos
   * Referenced by: '<S2>/Sine Wave3'
   */
  0.99998026085613712,

  /* Expression: 0.1
   * Referenced by: '<S2>/Sine Wave4'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave4'
   */
  0.0,

  /* Computed Parameter: SineWave4_Hsin
   * Referenced by: '<S2>/Sine Wave4'
   */
  0.0094246384331440058,

  /* Computed Parameter: SineWave4_HCos
   * Referenced by: '<S2>/Sine Wave4'
   */
  0.99995558710894983,

  /* Computed Parameter: SineWave4_PSin
   * Referenced by: '<S2>/Sine Wave4'
   */
  -0.0094246384331440058,

  /* Computed Parameter: SineWave4_PCos
   * Referenced by: '<S2>/Sine Wave4'
   */
  0.99995558710894983,

  /* Expression: 0.1
   * Referenced by: '<S2>/Sine Wave5'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave5'
   */
  0.0,

  /* Computed Parameter: SineWave5_Hsin
   * Referenced by: '<S2>/Sine Wave5'
   */
  0.015707317311820675,

  /* Computed Parameter: SineWave5_HCos
   * Referenced by: '<S2>/Sine Wave5'
   */
  0.99987663248166059,

  /* Computed Parameter: SineWave5_PSin
   * Referenced by: '<S2>/Sine Wave5'
   */
  -0.015707317311820675,

  /* Computed Parameter: SineWave5_PCos
   * Referenced by: '<S2>/Sine Wave5'
   */
  0.99987663248166059,

  /* Expression: 0.3
   * Referenced by: '<S1>/Gain'
   */
  0.3,

  /* Expression: 2.441406e-7
   * Referenced by: '<S3>/increments to m(calculate yourself)'
   */
  2.441406E-7,

  /* Expression: 64000/2^5
   * Referenced by: '<S3>/Constant'
   */
  2000.0,

  /* Expression: 6.4512
   * Referenced by: '<S3>/Protection Max 6.4512V Do not change!'
   */
  6.4512,

  /* Expression: -6.4512
   * Referenced by: '<S3>/Protection Max 6.4512V Do not change!'
   */
  -6.4512,

  /* Expression: 100/24
   * Referenced by: '<S3>/Voltage to PWM dutycycle'
   */
  4.166666666666667,

  /* Expression: 0.5
   * Referenced by: '<S3>/double sided'
   */
  0.5,

  /* Expression: 25
   * Referenced by: '<S3>/Saturation3'
   */
  25.0,

  /* Expression: -25
   * Referenced by: '<S3>/Saturation3'
   */
  -25.0,

  /* Expression: 74
   * Referenced by: '<S3>/Constant4'
   */
  74.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant3'
   */
  0.0,

  /* Expression: 26
   * Referenced by: '<S3>/Constant1'
   */
  26.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

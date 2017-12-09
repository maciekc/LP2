/*
 * Helikopter_new_LQ_data.c
 *
 * Code generation for model "Helikopter_new_LQ".
 *
 * Model version              : 1.254
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Dec 05 13:09:03 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Helikopter_new_LQ.h"
#include "Helikopter_new_LQ_private.h"

/* Block parameters (auto storage) */
P_Helikopter_new_LQ_T Helikopter_new_LQ_P = {
  /*  Variable: K_lqr
   * Referenced by: '<Root>/Gain'
   */
  { -0.086143346465459167, 0.45162962209082708, 0.0029514597255064379 },

  /*  Variable: L
   * Referenced by: '<Root>/Gain4'
   */
  { 15.04342925243817, 49.921796770462556, 87.9692737864249 },

  /*  Variable: lin_A
   * Referenced by: '<Root>/Gain2'
   */
  { 0.0, -4.4004778781967113, 0.0, 1.0, -0.069539418766975461, 0.0, 0.0,
    0.024437340135356631, -2.8870313287947873 },

  /*  Variable: lin_B
   * Referenced by: '<Root>/Gain1'
   */
  { 0.0, 0.0, 577.57706979136651 },

  /*  Variable: lin_C
   * Referenced by: '<Root>/Gain3'
   */
  { 1.0, 0.0, 0.0 },
  0.0,                                 /* Variable: lin_alpha_v
                                        * Referenced by:
                                        *   '<Root>/Constant4'
                                        *   '<Root>/Constant5'
                                        */
  235.90435132588519,                  /* Variable: lin_w_v
                                        * Referenced by:
                                        *   '<Root>/Constant10'
                                        *   '<Root>/Constant6'
                                        *   '<Root>/Constant7'
                                        */

  /*  Variable: wsp_V
   * Referenced by: '<S5>/Polynomial'
   */
  { 0.1644266474095355, 0.0018823989890005325 },
  0.7812,                              /* Mask Parameter: SliderGain2_gain
                                        * Referenced by: '<S4>/Slider Gain'
                                        */
  0.0,                                 /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S2>/Slider Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain6'
                                        */

  /*  Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S5>/Encoder'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S5>/Encoder'
                                        */

  /*  Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S5>/Encoder'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: T0
                                        * Referenced by: '<S5>/Encoder'
                                        */
  0.0009765625,                        /* Expression: 1/1024
                                        * Referenced by: '<S5>/Encoder 1024 PPR'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S5>/Convert to rad'
                                        */
  0.3490658503988659,                  /* Expression: pi/9
                                        * Referenced by: '<Root>/Constant'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain7'
                                        */

  /*  Computed Parameter: AnalogInput_P1_Size
   * Referenced by: '<S5>/Analog Input'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S5>/Analog Input'
                                        */

  /*  Computed Parameter: AnalogInput_P2_Size
   * Referenced by: '<S5>/Analog Input'
   */
  { 1.0, 2.0 },

  /*  Expression: [1 0]
   * Referenced by: '<S5>/Analog Input'
   */
  { 1.0, 0.0 },

  /*  Computed Parameter: AnalogInput_P3_Size
   * Referenced by: '<S5>/Analog Input'
   */
  { 1.0, 2.0 },

  /*  Expression: [1 1]
   * Referenced by: '<S5>/Analog Input'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: AnalogInput_P4_Size
   * Referenced by: '<S5>/Analog Input'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: T0
                                        * Referenced by: '<S5>/Analog Input'
                                        */
  1923.0769230769231,                  /* Expression: 1000/0.52
                                        * Referenced by: '<S5>/Convert to RPM1'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain5'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<Root>/Integrator'
   */
  { 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Azimuth Ctrl'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant11'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Pitch Ctrl1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S5>/Saturation'
                                        */

  /*  Computed Parameter: PWM_P1_Size
   * Referenced by: '<S5>/PWM'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S5>/PWM'
                                        */

  /*  Computed Parameter: PWM_P2_Size
   * Referenced by: '<S5>/PWM'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: T0
                                        * Referenced by: '<S5>/PWM'
                                        */

  /*  Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S5>/ResetEncoder'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S5>/ResetEncoder'
                                        */

  /*  Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S5>/ResetEncoder'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: T0
                                        * Referenced by: '<S5>/ResetEncoder'
                                        */

  /*  Computed Parameter: BitstreamVersion_P1_Size
   * Referenced by: '<S5>/Bitstream Version'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S5>/Bitstream Version'
                                        */

  /*  Computed Parameter: BitstreamVersion_P2_Size
   * Referenced by: '<S5>/Bitstream Version'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: T0
                                        * Referenced by: '<S5>/Bitstream Version'
                                        */

  /*  Computed Parameter: ThermStatus_P1_Size
   * Referenced by: '<S5>/Therm Status'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S5>/Therm Status'
                                        */

  /*  Computed Parameter: ThermStatus_P2_Size
   * Referenced by: '<S5>/Therm Status'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: T0
                                        * Referenced by: '<S5>/Therm Status'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<S5>/PWMPrescalerSource'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S5>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S5>/PWMPrescaler'
                                        */

  /*  Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S5>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: T0
                                        * Referenced by: '<S5>/PWMPrescaler'
                                        */

  /*  Expression: [1 1]
   * Referenced by: '<S5>/ThermFlagSource'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S5>/ThermFlag '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S5>/ThermFlag '
                                        */

  /*  Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S5>/ThermFlag '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: T0
                                        * Referenced by: '<S5>/ThermFlag '
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  0U                                   /* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
};

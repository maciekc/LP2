/*
 * RECZNYpid_data.c
 *
 * Code generation for model "RECZNYpid".
 *
 * Model version              : 1.248
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Dec 05 12:06:15 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RECZNYpid.h"
#include "RECZNYpid_private.h"

/* Block parameters (auto storage) */
P_RECZNYpid_T RECZNYpid_P = {
  /*  Variable: wsp_V
   * Referenced by: '<S5>/Polynomial'
   */
  { 0.1644266474095355, 0.0018823989890005325 },
  0.035,                               /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S2>/Derivative Gain'
                                        */
  0.015,                               /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  0.012,                               /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  0.0,                                 /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
  0.015,                               /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S1>/Kb'
                                        */
  -1.0,                                /* Mask Parameter: PIDController1_LowerSaturationL
                                        * Referenced by: '<S2>/Saturate'
                                        */
  -1.0,                                /* Mask Parameter: PIDController_LowerSaturationLi
                                        * Referenced by: '<S1>/Saturate'
                                        */
  100.0,                               /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S2>/Filter Coefficient'
                                        */
  100.0,                               /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  0.025,                               /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  0.02,                                /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  1.0,                                 /* Mask Parameter: PIDController1_UpperSaturationL
                                        * Referenced by: '<S2>/Saturate'
                                        */
  1.0,                                 /* Mask Parameter: PIDController_UpperSaturationLi
                                        * Referenced by: '<S1>/Saturate'
                                        */
  0.0,                                 /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S3>/Slider Gain'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
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
  31.415926535897931,                  /* Expression: pi/9/2*180
                                        * Referenced by: '<Root>/Constant'
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
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S2>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S2>/Filter'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Switch1'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Switch'
                                        */
  0.3611,                              /* Expression: 0.3611
                                        * Referenced by: '<Root>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Azimuth Ctrl'
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
  0U                                   /* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
};

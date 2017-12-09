/*
 * RECZNYpid.c
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
#include "RECZNYpid_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.001, 0.0,
};

/* Block signals (auto storage) */
B_RECZNYpid_T RECZNYpid_B;

/* Continuous states */
X_RECZNYpid_T RECZNYpid_X;

/* Block states (auto storage) */
DW_RECZNYpid_T RECZNYpid_DW;

/* Real-time model */
RT_MODEL_RECZNYpid_T RECZNYpid_M_;
RT_MODEL_RECZNYpid_T *const RECZNYpid_M = &RECZNYpid_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  RECZNYpid_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  RECZNYpid_output();
  RECZNYpid_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  RECZNYpid_output();
  RECZNYpid_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  RECZNYpid_output();
  RECZNYpid_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  RECZNYpid_output();
  RECZNYpid_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  RECZNYpid_output();
  RECZNYpid_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void RECZNYpid_output(void)
{
  real_T rtb_Saturate_n;
  real_T rtb_Sum;
  real_T rtb_Switch1;
  real_T u0;
  if (rtmIsMajorTimeStep(RECZNYpid_M)) {
    /* set solver stop time */
    if (!(RECZNYpid_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&RECZNYpid_M->solverInfo,
                            ((RECZNYpid_M->Timing.clockTickH0 + 1) *
        RECZNYpid_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&RECZNYpid_M->solverInfo,
                            ((RECZNYpid_M->Timing.clockTick0 + 1) *
        RECZNYpid_M->Timing.stepSize0 + RECZNYpid_M->Timing.clockTickH0 *
        RECZNYpid_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(RECZNYpid_M)) {
    RECZNYpid_M->Timing.t[0] = rtsiGetT(&RECZNYpid_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(RECZNYpid_M)) {
    /* Level2 S-Function Block: '<S5>/Encoder' (TRAS_Encoder) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S5>/Convert to rad' incorporates:
     *  Gain: '<S5>/Encoder 1024 PPR'
     */
    RECZNYpid_B.Converttorad[0] = RECZNYpid_P.Encoder1024PPR_Gain *
      RECZNYpid_B.Encoder[0] * RECZNYpid_P.Converttorad_Gain;
    RECZNYpid_B.Converttorad[1] = RECZNYpid_P.Encoder1024PPR_Gain *
      RECZNYpid_B.Encoder[1] * RECZNYpid_P.Converttorad_Gain;

    /* Constant: '<Root>/Constant' */
    RECZNYpid_B.Constant = RECZNYpid_P.Constant_Value;

    /* Level2 S-Function Block: '<S5>/Analog Input' (TRAS_AnalogInput) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S5>/Convert to RPM1' incorporates:
     *  Polyval: '<S5>/Polynomial'
     */
    RECZNYpid_B.ConverttoRPM1[0] = (RECZNYpid_P.wsp_V[0] *
      RECZNYpid_B.AnalogInput[0] + RECZNYpid_P.wsp_V[1]) *
      RECZNYpid_P.ConverttoRPM1_Gain;
    RECZNYpid_B.ConverttoRPM1[1] = (RECZNYpid_P.wsp_V[0] *
      RECZNYpid_B.AnalogInput[1] + RECZNYpid_P.wsp_V[1]) *
      RECZNYpid_P.ConverttoRPM1_Gain;

    /* Sum: '<Root>/Add' */
    RECZNYpid_B.Add = RECZNYpid_B.Constant - RECZNYpid_B.Converttorad[1];

    /* Gain: '<S2>/Proportional Gain' */
    RECZNYpid_B.ProportionalGain = RECZNYpid_P.PIDController1_P *
      RECZNYpid_B.Add;

    /* Gain: '<S2>/Derivative Gain' */
    RECZNYpid_B.DerivativeGain = RECZNYpid_P.PIDController1_D * RECZNYpid_B.Add;
  }

  /* Gain: '<S2>/Filter Coefficient' incorporates:
   *  Integrator: '<S2>/Filter'
   *  Sum: '<S2>/SumD'
   */
  RECZNYpid_B.FilterCoefficient = (RECZNYpid_B.DerivativeGain -
    RECZNYpid_X.Filter_CSTATE) * RECZNYpid_P.PIDController1_N;
  if (rtmIsMajorTimeStep(RECZNYpid_M)) {
    /* Abs: '<Root>/Abs' */
    RECZNYpid_B.Abs = fabs(RECZNYpid_B.Add);

    /* Switch: '<Root>/Switch1' incorporates:
     *  Gain: '<Root>/Gain'
     */
    if (RECZNYpid_B.Abs > RECZNYpid_P.Switch1_Threshold) {
      rtb_Switch1 = RECZNYpid_P.Gain_Gain * RECZNYpid_B.Add;
    } else {
      rtb_Switch1 = RECZNYpid_B.Add;
    }

    /* End of Switch: '<Root>/Switch1' */

    /* Gain: '<S1>/Proportional Gain' */
    RECZNYpid_B.ProportionalGain_m = RECZNYpid_P.PIDController_P * rtb_Switch1;

    /* Gain: '<S1>/Derivative Gain' */
    RECZNYpid_B.DerivativeGain_n = RECZNYpid_P.PIDController_D * rtb_Switch1;
  }

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  RECZNYpid_B.FilterCoefficient_c = (RECZNYpid_B.DerivativeGain_n -
    RECZNYpid_X.Filter_CSTATE_c) * RECZNYpid_P.PIDController_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  Integrator: '<S1>/Integrator'
   */
  rtb_Sum = (RECZNYpid_B.ProportionalGain_m + RECZNYpid_X.Integrator_CSTATE_i) +
    RECZNYpid_B.FilterCoefficient_c;

  /* Saturate: '<S1>/Saturate' */
  if (rtb_Sum > RECZNYpid_P.PIDController_UpperSaturationLi) {
    rtb_Saturate_n = RECZNYpid_P.PIDController_UpperSaturationLi;
  } else if (rtb_Sum < RECZNYpid_P.PIDController_LowerSaturationLi) {
    rtb_Saturate_n = RECZNYpid_P.PIDController_LowerSaturationLi;
  } else {
    rtb_Saturate_n = rtb_Sum;
  }

  /* End of Saturate: '<S1>/Saturate' */

  /* Switch: '<Root>/Switch' */
  if (RECZNYpid_B.Abs > RECZNYpid_P.Switch_Threshold) {
    /* Sum: '<S2>/Sum' incorporates:
     *  Integrator: '<S2>/Integrator'
     */
    u0 = (RECZNYpid_B.ProportionalGain + RECZNYpid_X.Integrator_CSTATE) +
      RECZNYpid_B.FilterCoefficient;

    /* Saturate: '<S2>/Saturate' */
    if (u0 > RECZNYpid_P.PIDController1_UpperSaturationL) {
      u0 = RECZNYpid_P.PIDController1_UpperSaturationL;
    } else {
      if (u0 < RECZNYpid_P.PIDController1_LowerSaturationL) {
        u0 = RECZNYpid_P.PIDController1_LowerSaturationL;
      }
    }

    /* End of Saturate: '<S2>/Saturate' */
  } else {
    u0 = rtb_Saturate_n;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  u0 += RECZNYpid_P.Constant1_Value;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > RECZNYpid_P.Saturation_UpperSat) {
    RECZNYpid_B.Saturation = RECZNYpid_P.Saturation_UpperSat;
  } else if (u0 < RECZNYpid_P.Saturation_LowerSat) {
    RECZNYpid_B.Saturation = RECZNYpid_P.Saturation_LowerSat;
  } else {
    RECZNYpid_B.Saturation = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(RECZNYpid_M)) {
  }

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if (RECZNYpid_P.ManualSwitch_CurrentSetting == 1) {
    RECZNYpid_B.ManualSwitch = RECZNYpid_P.Constant3_Value;
  } else {
    RECZNYpid_B.ManualSwitch = RECZNYpid_B.Saturation;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(RECZNYpid_M)) {
    /* Gain: '<S1>/Integral Gain' */
    RECZNYpid_B.IntegralGain = RECZNYpid_P.PIDController_I * rtb_Switch1;
  }

  /* Sum: '<S1>/SumI1' incorporates:
   *  Gain: '<S1>/Kb'
   *  Sum: '<S1>/SumI2'
   */
  RECZNYpid_B.SumI1 = (rtb_Saturate_n - rtb_Sum) * RECZNYpid_P.PIDController_Kb
    + RECZNYpid_B.IntegralGain;
  if (rtmIsMajorTimeStep(RECZNYpid_M)) {
    /* Gain: '<S2>/Integral Gain' */
    RECZNYpid_B.IntegralGain_o = RECZNYpid_P.PIDController1_I * RECZNYpid_B.Add;

    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     *  Constant: '<Root>/Reset'
     */
    if (RECZNYpid_P.ResetEncoders_CurrentSetting == 1) {
      RECZNYpid_B.ResetEncoders = RECZNYpid_P.Reset_Value;
    } else {
      RECZNYpid_B.ResetEncoders = RECZNYpid_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */

    /* Gain: '<S3>/Slider Gain' incorporates:
     *  Constant: '<Root>/Azimuth Ctrl'
     */
    RECZNYpid_B.SliderGain = RECZNYpid_P.SliderGain_gain *
      RECZNYpid_P.AzimuthCtrl_Value;
  }

  /* Saturate: '<S5>/Saturation' */
  if (RECZNYpid_B.SliderGain > RECZNYpid_P.Saturation_UpperSat_k) {
    RECZNYpid_B.Saturation_j[0] = RECZNYpid_P.Saturation_UpperSat_k;
  } else if (RECZNYpid_B.SliderGain < RECZNYpid_P.Saturation_LowerSat_k) {
    RECZNYpid_B.Saturation_j[0] = RECZNYpid_P.Saturation_LowerSat_k;
  } else {
    RECZNYpid_B.Saturation_j[0] = RECZNYpid_B.SliderGain;
  }

  if (RECZNYpid_B.ManualSwitch > RECZNYpid_P.Saturation_UpperSat_k) {
    RECZNYpid_B.Saturation_j[1] = RECZNYpid_P.Saturation_UpperSat_k;
  } else if (RECZNYpid_B.ManualSwitch < RECZNYpid_P.Saturation_LowerSat_k) {
    RECZNYpid_B.Saturation_j[1] = RECZNYpid_P.Saturation_LowerSat_k;
  } else {
    RECZNYpid_B.Saturation_j[1] = RECZNYpid_B.ManualSwitch;
  }

  /* End of Saturate: '<S5>/Saturation' */
  if (rtmIsMajorTimeStep(RECZNYpid_M)) {
    /* Level2 S-Function Block: '<S5>/PWM' (TRAS_PWM) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/ResetEncoder' (TRAS_ResetEncoder) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/Bitstream Version' (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/Therm Status' (TRAS_PWMTherm) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S5>/PWMPrescalerSource' */
    RECZNYpid_B.PWMPrescalerSource[0] = RECZNYpid_P.PWMPrescalerSource_Value[0];
    RECZNYpid_B.PWMPrescalerSource[1] = RECZNYpid_P.PWMPrescalerSource_Value[1];

    /* Level2 S-Function Block: '<S5>/PWMPrescaler' (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S5>/ThermFlagSource' */
    RECZNYpid_B.ThermFlagSource[0] = RECZNYpid_P.ThermFlagSource_Value[0];
    RECZNYpid_B.ThermFlagSource[1] = RECZNYpid_P.ThermFlagSource_Value[1];

    /* Level2 S-Function Block: '<S5>/ThermFlag ' (TRAS_ThermFlag) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }
  }
}

/* Model update function */
void RECZNYpid_update(void)
{
  if (rtmIsMajorTimeStep(RECZNYpid_M)) {
    rt_ertODEUpdateContinuousStates(&RECZNYpid_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++RECZNYpid_M->Timing.clockTick0)) {
    ++RECZNYpid_M->Timing.clockTickH0;
  }

  RECZNYpid_M->Timing.t[0] = rtsiGetSolverStopTime(&RECZNYpid_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++RECZNYpid_M->Timing.clockTick1)) {
      ++RECZNYpid_M->Timing.clockTickH1;
    }

    RECZNYpid_M->Timing.t[1] = RECZNYpid_M->Timing.clockTick1 *
      RECZNYpid_M->Timing.stepSize1 + RECZNYpid_M->Timing.clockTickH1 *
      RECZNYpid_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void RECZNYpid_derivatives(void)
{
  XDot_RECZNYpid_T *_rtXdot;
  _rtXdot = ((XDot_RECZNYpid_T *) RECZNYpid_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = RECZNYpid_B.IntegralGain_o;

  /* Derivatives for Integrator: '<S2>/Filter' */
  _rtXdot->Filter_CSTATE = RECZNYpid_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = RECZNYpid_B.SumI1;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE_c = RECZNYpid_B.FilterCoefficient_c;
}

/* Model initialize function */
void RECZNYpid_initialize(void)
{
  /* Start for Constant: '<S5>/PWMPrescalerSource' */
  RECZNYpid_B.PWMPrescalerSource[0] = RECZNYpid_P.PWMPrescalerSource_Value[0];
  RECZNYpid_B.PWMPrescalerSource[1] = RECZNYpid_P.PWMPrescalerSource_Value[1];

  /* Start for Constant: '<S5>/ThermFlagSource' */
  RECZNYpid_B.ThermFlagSource[0] = RECZNYpid_P.ThermFlagSource_Value[0];
  RECZNYpid_B.ThermFlagSource[1] = RECZNYpid_P.ThermFlagSource_Value[1];

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  RECZNYpid_X.Integrator_CSTATE = RECZNYpid_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Filter' */
  RECZNYpid_X.Filter_CSTATE = RECZNYpid_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  RECZNYpid_X.Integrator_CSTATE_i = RECZNYpid_P.Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  RECZNYpid_X.Filter_CSTATE_c = RECZNYpid_P.Filter_IC_a;
}

/* Model terminate function */
void RECZNYpid_terminate(void)
{
  /* Level2 S-Function Block: '<S5>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = RECZNYpid_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = RECZNYpid_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = RECZNYpid_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = RECZNYpid_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = RECZNYpid_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = RECZNYpid_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = RECZNYpid_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = RECZNYpid_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  RECZNYpid_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  RECZNYpid_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  RECZNYpid_initialize();
}

void MdlTerminate(void)
{
  RECZNYpid_terminate();
}

/* Registration function */
RT_MODEL_RECZNYpid_T *RECZNYpid(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)RECZNYpid_M, 0,
                sizeof(RT_MODEL_RECZNYpid_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RECZNYpid_M->solverInfo,
                          &RECZNYpid_M->Timing.simTimeStep);
    rtsiSetTPtr(&RECZNYpid_M->solverInfo, &rtmGetTPtr(RECZNYpid_M));
    rtsiSetStepSizePtr(&RECZNYpid_M->solverInfo, &RECZNYpid_M->Timing.stepSize0);
    rtsiSetdXPtr(&RECZNYpid_M->solverInfo, &RECZNYpid_M->ModelData.derivs);
    rtsiSetContStatesPtr(&RECZNYpid_M->solverInfo, (real_T **)
                         &RECZNYpid_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&RECZNYpid_M->solverInfo,
      &RECZNYpid_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&RECZNYpid_M->solverInfo, (&rtmGetErrorStatus
      (RECZNYpid_M)));
    rtsiSetRTModelPtr(&RECZNYpid_M->solverInfo, RECZNYpid_M);
  }

  rtsiSetSimTimeStep(&RECZNYpid_M->solverInfo, MAJOR_TIME_STEP);
  RECZNYpid_M->ModelData.intgData.y = RECZNYpid_M->ModelData.odeY;
  RECZNYpid_M->ModelData.intgData.f[0] = RECZNYpid_M->ModelData.odeF[0];
  RECZNYpid_M->ModelData.intgData.f[1] = RECZNYpid_M->ModelData.odeF[1];
  RECZNYpid_M->ModelData.intgData.f[2] = RECZNYpid_M->ModelData.odeF[2];
  RECZNYpid_M->ModelData.intgData.f[3] = RECZNYpid_M->ModelData.odeF[3];
  RECZNYpid_M->ModelData.intgData.f[4] = RECZNYpid_M->ModelData.odeF[4];
  RECZNYpid_M->ModelData.intgData.f[5] = RECZNYpid_M->ModelData.odeF[5];
  RECZNYpid_M->ModelData.contStates = ((real_T *) &RECZNYpid_X);
  rtsiSetSolverData(&RECZNYpid_M->solverInfo, (void *)
                    &RECZNYpid_M->ModelData.intgData);
  rtsiSetSolverName(&RECZNYpid_M->solverInfo,"ode5");
  RECZNYpid_M->solverInfoPtr = (&RECZNYpid_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = RECZNYpid_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    RECZNYpid_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RECZNYpid_M->Timing.sampleTimes = (&RECZNYpid_M->Timing.sampleTimesArray[0]);
    RECZNYpid_M->Timing.offsetTimes = (&RECZNYpid_M->Timing.offsetTimesArray[0]);

    /* task periods */
    RECZNYpid_M->Timing.sampleTimes[0] = (0.0);
    RECZNYpid_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    RECZNYpid_M->Timing.offsetTimes[0] = (0.0);
    RECZNYpid_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(RECZNYpid_M, &RECZNYpid_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RECZNYpid_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    RECZNYpid_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RECZNYpid_M, -1);
  RECZNYpid_M->Timing.stepSize0 = 0.001;
  RECZNYpid_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  RECZNYpid_M->Sizes.checksums[0] = (3116290505U);
  RECZNYpid_M->Sizes.checksums[1] = (1747840451U);
  RECZNYpid_M->Sizes.checksums[2] = (596291950U);
  RECZNYpid_M->Sizes.checksums[3] = (1953715243U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    RECZNYpid_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(RECZNYpid_M->extModeInfo,
      &RECZNYpid_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RECZNYpid_M->extModeInfo, RECZNYpid_M->Sizes.checksums);
    rteiSetTPtr(RECZNYpid_M->extModeInfo, rtmGetTPtr(RECZNYpid_M));
  }

  RECZNYpid_M->solverInfoPtr = (&RECZNYpid_M->solverInfo);
  RECZNYpid_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&RECZNYpid_M->solverInfo, 0.001);
  rtsiSetSolverMode(&RECZNYpid_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  RECZNYpid_M->ModelData.blockIO = ((void *) &RECZNYpid_B);

  {
    RECZNYpid_B.Encoder[0] = 0.0;
    RECZNYpid_B.Encoder[1] = 0.0;
    RECZNYpid_B.Converttorad[0] = 0.0;
    RECZNYpid_B.Converttorad[1] = 0.0;
    RECZNYpid_B.Constant = 0.0;
    RECZNYpid_B.AnalogInput[0] = 0.0;
    RECZNYpid_B.AnalogInput[1] = 0.0;
    RECZNYpid_B.ConverttoRPM1[0] = 0.0;
    RECZNYpid_B.ConverttoRPM1[1] = 0.0;
    RECZNYpid_B.Add = 0.0;
    RECZNYpid_B.ProportionalGain = 0.0;
    RECZNYpid_B.DerivativeGain = 0.0;
    RECZNYpid_B.FilterCoefficient = 0.0;
    RECZNYpid_B.Abs = 0.0;
    RECZNYpid_B.ProportionalGain_m = 0.0;
    RECZNYpid_B.DerivativeGain_n = 0.0;
    RECZNYpid_B.FilterCoefficient_c = 0.0;
    RECZNYpid_B.Saturation = 0.0;
    RECZNYpid_B.ManualSwitch = 0.0;
    RECZNYpid_B.IntegralGain = 0.0;
    RECZNYpid_B.SumI1 = 0.0;
    RECZNYpid_B.IntegralGain_o = 0.0;
    RECZNYpid_B.ResetEncoders = 0.0;
    RECZNYpid_B.SliderGain = 0.0;
    RECZNYpid_B.Saturation_j[0] = 0.0;
    RECZNYpid_B.Saturation_j[1] = 0.0;
    RECZNYpid_B.PWM[0] = 0.0;
    RECZNYpid_B.PWM[1] = 0.0;
    RECZNYpid_B.ResetEncoder[0] = 0.0;
    RECZNYpid_B.ResetEncoder[1] = 0.0;
    RECZNYpid_B.BitstreamVersion = 0.0;
    RECZNYpid_B.ThermStatus[0] = 0.0;
    RECZNYpid_B.ThermStatus[1] = 0.0;
    RECZNYpid_B.PWMPrescalerSource[0] = 0.0;
    RECZNYpid_B.PWMPrescalerSource[1] = 0.0;
    RECZNYpid_B.PWMPrescaler[0] = 0.0;
    RECZNYpid_B.PWMPrescaler[1] = 0.0;
    RECZNYpid_B.ThermFlagSource[0] = 0.0;
    RECZNYpid_B.ThermFlagSource[1] = 0.0;
    RECZNYpid_B.ThermFlag[0] = 0.0;
    RECZNYpid_B.ThermFlag[1] = 0.0;
  }

  /* parameters */
  RECZNYpid_M->ModelData.defaultParam = ((real_T *)&RECZNYpid_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &RECZNYpid_X;
    RECZNYpid_M->ModelData.contStates = (x);
    (void) memset((void *)&RECZNYpid_X, 0,
                  sizeof(X_RECZNYpid_T));
  }

  /* states (dwork) */
  RECZNYpid_M->ModelData.dwork = ((void *) &RECZNYpid_DW);
  (void) memset((void *)&RECZNYpid_DW, 0,
                sizeof(DW_RECZNYpid_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    RECZNYpid_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &RECZNYpid_M->NonInlinedSFcns.sfcnInfo;
    RECZNYpid_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(RECZNYpid_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &RECZNYpid_M->Sizes.numSampTimes);
    RECZNYpid_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(RECZNYpid_M)[0]);
    RECZNYpid_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(RECZNYpid_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,RECZNYpid_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(RECZNYpid_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(RECZNYpid_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(RECZNYpid_M));
    rtssSetStepSizePtr(sfcnInfo, &RECZNYpid_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(RECZNYpid_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &RECZNYpid_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &RECZNYpid_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &RECZNYpid_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &RECZNYpid_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &RECZNYpid_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &RECZNYpid_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &RECZNYpid_M->solverInfoPtr);
  }

  RECZNYpid_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&RECZNYpid_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    RECZNYpid_M->childSfunctions =
      (&RECZNYpid_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        RECZNYpid_M->childSfunctions[i] =
          (&RECZNYpid_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: RECZNYpid/<S5>/Encoder (TRAS_Encoder) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = RECZNYpid_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = RECZNYpid_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = RECZNYpid_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RECZNYpid_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, RECZNYpid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RECZNYpid_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RECZNYpid_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RECZNYpid_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) RECZNYpid_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "RECZNYpid/TRAS/Encoder");
      ssSetRTModel(rts,RECZNYpid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RECZNYpid_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RECZNYpid_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RECZNYpid_P.Encoder_P2_Size);
      }

      /* registration */
      TRAS_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RECZNYpid/<S5>/Analog Input (TRAS_AnalogInput) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = RECZNYpid_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = RECZNYpid_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = RECZNYpid_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RECZNYpid_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, RECZNYpid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RECZNYpid_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RECZNYpid_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RECZNYpid_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) RECZNYpid_B.AnalogInput));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog Input");
      ssSetPath(rts, "RECZNYpid/TRAS/Analog Input");
      ssSetRTModel(rts,RECZNYpid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RECZNYpid_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RECZNYpid_P.AnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RECZNYpid_P.AnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RECZNYpid_P.AnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RECZNYpid_P.AnalogInput_P4_Size);
      }

      /* registration */
      TRAS_AnalogInput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RECZNYpid/<S5>/PWM (TRAS_PWM) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = RECZNYpid_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = RECZNYpid_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = RECZNYpid_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RECZNYpid_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, RECZNYpid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RECZNYpid_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RECZNYpid_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RECZNYpid_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &RECZNYpid_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = RECZNYpid_B.Saturation_j;
          sfcnUPtrs[1] = &RECZNYpid_B.Saturation_j[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) RECZNYpid_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "RECZNYpid/TRAS/PWM");
      ssSetRTModel(rts,RECZNYpid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RECZNYpid_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RECZNYpid_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RECZNYpid_P.PWM_P2_Size);
      }

      /* registration */
      TRAS_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: RECZNYpid/<S5>/ResetEncoder (TRAS_ResetEncoder) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = RECZNYpid_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = RECZNYpid_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = RECZNYpid_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RECZNYpid_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, RECZNYpid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RECZNYpid_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RECZNYpid_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RECZNYpid_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &RECZNYpid_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &RECZNYpid_B.ResetEncoders;
          sfcnUPtrs[1] = &RECZNYpid_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) RECZNYpid_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "RECZNYpid/TRAS/ResetEncoder");
      ssSetRTModel(rts,RECZNYpid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RECZNYpid_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RECZNYpid_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RECZNYpid_P.ResetEncoder_P2_Size);
      }

      /* registration */
      TRAS_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: RECZNYpid/<S5>/Bitstream Version (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = RECZNYpid_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = RECZNYpid_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = RECZNYpid_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RECZNYpid_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, RECZNYpid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RECZNYpid_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RECZNYpid_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RECZNYpid_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &RECZNYpid_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "RECZNYpid/TRAS/Bitstream Version");
      ssSetRTModel(rts,RECZNYpid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RECZNYpid_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RECZNYpid_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RECZNYpid_P.BitstreamVersion_P2_Size);
      }

      /* registration */
      TRAS_BitstreamVersion(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RECZNYpid/<S5>/Therm Status (TRAS_PWMTherm) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = RECZNYpid_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = RECZNYpid_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = RECZNYpid_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RECZNYpid_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, RECZNYpid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RECZNYpid_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RECZNYpid_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RECZNYpid_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) RECZNYpid_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "RECZNYpid/TRAS/Therm Status");
      ssSetRTModel(rts,RECZNYpid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RECZNYpid_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RECZNYpid_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RECZNYpid_P.ThermStatus_P2_Size);
      }

      /* registration */
      TRAS_PWMTherm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RECZNYpid/<S5>/PWMPrescaler (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = RECZNYpid_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = RECZNYpid_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = RECZNYpid_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RECZNYpid_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, RECZNYpid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RECZNYpid_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RECZNYpid_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RECZNYpid_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &RECZNYpid_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = RECZNYpid_B.PWMPrescalerSource;
          sfcnUPtrs[1] = &RECZNYpid_B.PWMPrescalerSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) RECZNYpid_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "RECZNYpid/TRAS/PWMPrescaler");
      ssSetRTModel(rts,RECZNYpid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RECZNYpid_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RECZNYpid_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RECZNYpid_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      TRAS_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: RECZNYpid/<S5>/ThermFlag  (TRAS_ThermFlag) */
    {
      SimStruct *rts = RECZNYpid_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = RECZNYpid_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = RECZNYpid_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = RECZNYpid_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &RECZNYpid_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, RECZNYpid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RECZNYpid_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RECZNYpid_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RECZNYpid_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &RECZNYpid_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = RECZNYpid_B.ThermFlagSource;
          sfcnUPtrs[1] = &RECZNYpid_B.ThermFlagSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RECZNYpid_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) RECZNYpid_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "RECZNYpid/TRAS/ThermFlag ");
      ssSetRTModel(rts,RECZNYpid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RECZNYpid_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RECZNYpid_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RECZNYpid_P.ThermFlag_P2_Size);
      }

      /* registration */
      TRAS_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  RECZNYpid_M->Sizes.numContStates = (4);/* Number of continuous states */
  RECZNYpid_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  RECZNYpid_M->Sizes.numY = (0);       /* Number of model outputs */
  RECZNYpid_M->Sizes.numU = (0);       /* Number of model inputs */
  RECZNYpid_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  RECZNYpid_M->Sizes.numSampTimes = (2);/* Number of sample times */
  RECZNYpid_M->Sizes.numBlocks = (64); /* Number of blocks */
  RECZNYpid_M->Sizes.numBlockIO = (29);/* Number of block outputs */
  RECZNYpid_M->Sizes.numBlockPrms = (98);/* Sum of parameter "widths" */
  return RECZNYpid_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

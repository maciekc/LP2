/*
 * Helikopter_new_LQI_private.h
 *
 * Code generation for model "Helikopter_new_LQI".
 *
 * Model version              : 1.260
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Dec 05 13:01:41 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Helikopter_new_LQI_private_h_
#define RTW_HEADER_Helikopter_new_LQI_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern void TRAS_Encoder(SimStruct *rts);
extern void TRAS_AnalogInput(SimStruct *rts);
extern void TRAS_PWM(SimStruct *rts);
extern void TRAS_ResetEncoder(SimStruct *rts);
extern void TRAS_BitstreamVersion(SimStruct *rts);
extern void TRAS_PWMTherm(SimStruct *rts);
extern void TRAS_PWMPrescaler(SimStruct *rts);
extern void TRAS_ThermFlag(SimStruct *rts);

/* private model entry point functions */
extern void Helikopter_new_LQI_derivatives(void);

#endif                                 /* RTW_HEADER_Helikopter_new_LQI_private_h_ */

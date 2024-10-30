/*
 * chairforceone_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "chairforceone".
 *
 * Model version              : 1.9
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Tue Oct 29 21:18:25 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef chairforceone_private_h_
#define chairforceone_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "chairforceone.h"
#include "chairforceone_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern void chairforc_EnabledSubsystem_Init(B_EnabledSubsystem_chairforce_T
  *localB, P_EnabledSubsystem_chairforce_T *localP);
extern void chairforceone_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_chairforceone_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_chairforce_T *localB);

#endif                                 /* chairforceone_private_h_ */

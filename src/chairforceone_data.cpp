/*
 * chairforceone_data.cpp
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

#include "chairforceone.h"

/* Block parameters (default storage) */
P_chairforceone_T chairforceone_P = {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S4>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S5>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S6>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Expression: 3
   * Referenced by: '<S2>/Observed_Lead_Vehicle_Max_Deceleration (For now keeping one fixed  value to all vehicles  for scope of deliverable 1 )'
   */
  3.0,

  /* Expression: 3.5
   * Referenced by: '<Root>/Ego_Max_Deceleration'
   */
  3.5,

  /* Expression: 10
   * Referenced by: '<Root>/Min_Breaking_point_Gap'
   */
  10.0,

  /* Expression: 5
   * Referenced by: '<S2>/Min_Space_Gap_At_All_Times'
   */
  5.0,

  /* Expression: 4
   * Referenced by: '<Root>/Ego_Max_Acceleration'
   */
  4.0,

  /* Expression: 70
   * Referenced by: '<Root>/Speed_limit'
   */
  70.0,

  /* Expression: 20
   * Referenced by: '<S2>/Operational_Frequency(Hz)'
   */
  20.0,

  /* Expression: 500
   * Referenced by: '<S2>/Error_for_Max_Accel (The error distance in breaking points which is  threshold for using max acceleration of vehicle)'
   */
  500.0,

  /* Expression: 2
   * Referenced by: '<S2>/Space_Gap_to_call_Max_Decel'
   */
  2.0,

  /* Start of '<S6>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S14>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  ,

  /* End of '<S6>/Enabled Subsystem' */

  /* Start of '<S5>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S13>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  ,

  /* End of '<S5>/Enabled Subsystem' */

  /* Start of '<S4>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S12>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  /* End of '<S4>/Enabled Subsystem' */
};

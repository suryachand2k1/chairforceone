/*
 * chairforceone.cpp
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
#include "rtwtypes.h"
#include "chairforceone_types.h"
#include "chairforceone_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>

/* Block signals (default storage) */
B_chairforceone_T chairforceone_B;

/* Block states (default storage) */
DW_chairforceone_T chairforceone_DW;

/* Real-time model */
RT_MODEL_chairforceone_T chairforceone_M_ = RT_MODEL_chairforceone_T();
RT_MODEL_chairforceone_T *const chairforceone_M = &chairforceone_M_;

/*
 * System initialize for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 *    '<S6>/Enabled Subsystem'
 */
void chairforc_EnabledSubsystem_Init(B_EnabledSubsystem_chairforce_T *localB,
  P_EnabledSubsystem_chairforce_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S12>/In1' incorporates:
   *  Outport: '<S12>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 *    '<S6>/Enabled Subsystem'
 */
void chairforceone_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_chairforceone_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_chairforce_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S12>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
}

/* Model step function */
void chairforceone_step(void)
{
  SL_Bus_chairforceone_std_msgs_Float64 rtb_BusAssignment;
  real_T dt;
  real_T error_tmp;
  real_T error_tmp_0;
  real_T rtb_Sum;
  real_T working_decel_ego;
  real_T working_min_gap;
  boolean_T b_varargout_1;

  /* Outputs for Atomic SubSystem: '<Root>/curr_vel' */
  /* MATLABSystem: '<S4>/SourceBlock' */
  b_varargout_1 = Sub_chairforceone_27.getLatestMessage(&chairforceone_B.r);

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S4>/SourceBlock' */
  chairforceone_EnabledSubsystem(b_varargout_1, &chairforceone_B.r,
    &chairforceone_B.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/curr_vel' */

  /* Outputs for Atomic SubSystem: '<Root>/rel_vel' */
  /* MATLABSystem: '<S6>/SourceBlock' */
  b_varargout_1 = Sub_chairforceone_29.getLatestMessage(&chairforceone_B.r);

  /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S6>/SourceBlock' */
  chairforceone_EnabledSubsystem(b_varargout_1, &chairforceone_B.r,
    &chairforceone_B.EnabledSubsystem_i);

  /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/rel_vel' */

  /* Sum: '<Root>/Sum' */
  rtb_Sum = chairforceone_B.EnabledSubsystem.In1.Data +
    chairforceone_B.EnabledSubsystem_i.In1.Data;

  /* Outputs for Atomic SubSystem: '<Root>/lead_dist' */
  /* MATLABSystem: '<S5>/SourceBlock' */
  b_varargout_1 = Sub_chairforceone_30.getLatestMessage(&chairforceone_B.r);

  /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S5>/SourceBlock' */
  chairforceone_EnabledSubsystem(b_varargout_1, &chairforceone_B.r,
    &chairforceone_B.EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/lead_dist' */

  /* MATLAB Function: '<S2>/Acceleration(To be worked on)' incorporates:
   *  Constant: '<Root>/Ego_Max_Acceleration'
   *  Constant: '<Root>/Ego_Max_Deceleration'
   *  Constant: '<Root>/Min_Breaking_point_Gap'
   *  Constant: '<S2>/Error_for_Max_Accel (The error distance in breaking points which is  threshold for using max acceleration of vehicle)'
   *  Constant: '<S2>/Min_Space_Gap_At_All_Times'
   *  Constant: '<S2>/Observed_Lead_Vehicle_Max_Deceleration (For now keeping one fixed  value to all vehicles  for scope of deliverable 1 )'
   *  Constant: '<S2>/Operational_Frequency(Hz)'
   *  Constant: '<S2>/Space_Gap_to_call_Max_Decel'
   */
  dt = 1.0 / chairforceone_P.Operational_FrequencyHz_Value;
  working_decel_ego = chairforceone_P.Ego_Max_Deceleration_Value;
  working_min_gap = chairforceone_P.Min_Breaking_point_Gap_Value;
  if (chairforceone_P.Ego_Max_Deceleration_Value >
      chairforceone_P.Observed_Lead_Vehicle_Max_Decel) {
    working_decel_ego = chairforceone_P.Observed_Lead_Vehicle_Max_Decel;
    if ((chairforceone_P.Min_Space_Gap_At_All_Times_Valu <=
         chairforceone_P.Min_Breaking_point_Gap_Value) || rtIsNaN
        (chairforceone_P.Min_Breaking_point_Gap_Value)) {
      working_min_gap = chairforceone_P.Min_Space_Gap_At_All_Times_Valu;
    }
  }

  error_tmp = rtb_Sum * rtb_Sum;
  error_tmp_0 = chairforceone_B.EnabledSubsystem.In1.Data *
    chairforceone_B.EnabledSubsystem.In1.Data;
  working_decel_ego = (((error_tmp / 19.6 * 0.55 + error_tmp / (2.0 *
    chairforceone_P.Observed_Lead_Vehicle_Max_Decel)) +
                        chairforceone_B.EnabledSubsystem_h.In1.Data) -
                       (error_tmp_0 / 19.6 * 0.55 + error_tmp_0 / (2.0 *
    working_decel_ego))) - working_min_gap;
  working_min_gap = -(working_min_gap -
                      chairforceone_P.Space_Gap_to_call_Max_Decel_Val);
  if (working_decel_ego >= chairforceone_P.Error_for_Max_AccelTheerrordist) {
    working_min_gap = chairforceone_P.Ego_Max_Acceleration_Value;
  } else if (working_decel_ego >= 0.0) {
    working_min_gap = working_decel_ego /
      chairforceone_P.Error_for_Max_AccelTheerrordist;
    working_min_gap = working_min_gap * working_min_gap *
      chairforceone_P.Ego_Max_Acceleration_Value;
  } else if (working_decel_ego <= working_min_gap) {
    working_min_gap = -chairforceone_P.Ego_Max_Deceleration_Value;
  } else {
    working_min_gap = working_decel_ego / working_min_gap *
      -chairforceone_P.Ego_Max_Deceleration_Value;
  }

  working_decel_ego = dt * dt;
  error_tmp = chairforceone_B.EnabledSubsystem.In1.Data * dt;
  rtb_Sum = rtb_Sum * dt + chairforceone_B.EnabledSubsystem_h.In1.Data;
  if (rtb_Sum - (0.5 * working_min_gap * working_decel_ego + error_tmp) <
      chairforceone_P.Min_Space_Gap_At_All_Times_Valu) {
    rtb_Sum = ((rtb_Sum - (error_tmp +
      chairforceone_P.Min_Space_Gap_At_All_Times_Valu)) - error_tmp) * 2.0 /
      working_decel_ego;
    if ((rtb_Sum <= working_min_gap) || rtIsNaN(working_min_gap)) {
      working_min_gap = rtb_Sum;
    }

    if ((!(working_min_gap <= chairforceone_P.Ego_Max_Acceleration_Value)) &&
        (!rtIsNaN(chairforceone_P.Ego_Max_Acceleration_Value))) {
      working_min_gap = chairforceone_P.Ego_Max_Acceleration_Value;
    }

    if ((!(working_min_gap >= -chairforceone_P.Ego_Max_Deceleration_Value)) && (
         !rtIsNaN(-chairforceone_P.Ego_Max_Deceleration_Value))) {
      working_min_gap = -chairforceone_P.Ego_Max_Deceleration_Value;
    }
  }

  if ((!(working_min_gap <= chairforceone_P.Ego_Max_Acceleration_Value)) &&
      (!rtIsNaN(chairforceone_P.Ego_Max_Acceleration_Value))) {
    working_min_gap = chairforceone_P.Ego_Max_Acceleration_Value;
  }

  if ((working_min_gap >= -chairforceone_P.Ego_Max_Deceleration_Value) ||
      rtIsNaN(-chairforceone_P.Ego_Max_Deceleration_Value)) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = working_min_gap;
  } else {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = -chairforceone_P.Ego_Max_Deceleration_Value;
  }

  /* End of MATLAB Function: '<S2>/Acceleration(To be worked on)' */

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_chairforceone_36.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
}

/* Model initialize function */
void chairforceone_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset((static_cast<void *>(&chairforceone_B)), 0,
                sizeof(B_chairforceone_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&chairforceone_DW), 0,
                sizeof(DW_chairforceone_T));

  {
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_1[11];
    char_T b_zeroDelimTopic_0[9];
    static const char_T b_zeroDelimTopic_2[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_3[9] = "/rel_vel";
    static const char_T b_zeroDelimTopic_4[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_5[11] = "/cmd_accel";

    /* Start for Atomic SubSystem: '<Root>/curr_vel' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    chairforceone_DW.obj_i.matlabCodegenIsDeleted = false;
    chairforceone_DW.objisempty_aw = true;
    chairforceone_DW.obj_i.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_chairforceone_27.createSubscriber(&b_zeroDelimTopic[0], 1);
    chairforceone_DW.obj_i.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/curr_vel' */

    /* Start for Atomic SubSystem: '<Root>/rel_vel' */
    /* Start for MATLABSystem: '<S6>/SourceBlock' */
    chairforceone_DW.obj_c.matlabCodegenIsDeleted = false;
    chairforceone_DW.objisempty = true;
    chairforceone_DW.obj_c.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_chairforceone_29.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    chairforceone_DW.obj_c.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/rel_vel' */

    /* Start for Atomic SubSystem: '<Root>/lead_dist' */
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    chairforceone_DW.obj_d.matlabCodegenIsDeleted = false;
    chairforceone_DW.objisempty_a = true;
    chairforceone_DW.obj_d.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Sub_chairforceone_30.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    chairforceone_DW.obj_d.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/lead_dist' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    chairforceone_DW.obj.matlabCodegenIsDeleted = false;
    chairforceone_DW.objisempty_k = true;
    chairforceone_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_5[i];
    }

    Pub_chairforceone_36.createPublisher(&b_zeroDelimTopic_1[0], 1);
    chairforceone_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/curr_vel' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  chairforc_EnabledSubsystem_Init(&chairforceone_B.EnabledSubsystem,
    &chairforceone_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/curr_vel' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/rel_vel' */
  /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  chairforc_EnabledSubsystem_Init(&chairforceone_B.EnabledSubsystem_i,
    &chairforceone_P.EnabledSubsystem_i);

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/rel_vel' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/lead_dist' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  chairforc_EnabledSubsystem_Init(&chairforceone_B.EnabledSubsystem_h,
    &chairforceone_P.EnabledSubsystem_h);

  /* End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/lead_dist' */
}

/* Model terminate function */
void chairforceone_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/curr_vel' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!chairforceone_DW.obj_i.matlabCodegenIsDeleted) {
    chairforceone_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/curr_vel' */

  /* Terminate for Atomic SubSystem: '<Root>/rel_vel' */
  /* Terminate for MATLABSystem: '<S6>/SourceBlock' */
  if (!chairforceone_DW.obj_c.matlabCodegenIsDeleted) {
    chairforceone_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/rel_vel' */

  /* Terminate for Atomic SubSystem: '<Root>/lead_dist' */
  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  if (!chairforceone_DW.obj_d.matlabCodegenIsDeleted) {
    chairforceone_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/lead_dist' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!chairforceone_DW.obj.matlabCodegenIsDeleted) {
    chairforceone_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}

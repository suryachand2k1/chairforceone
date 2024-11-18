/*
 * chairforceone.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "chairforceone".
 *
 * Model version              : 1.91
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov 18 10:35:03 2024
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
#include <math.h>

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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void chairforceone_step(void)
{
  SL_Bus_chairforceone_std_msgs_Float64 rtb_BusAssignment;
  real_T lead_accel;
  real_T lead_future_vel;
  real_T rtb_Sum;
  real_T weighted_future_gap_tmp;
  int32_T tmp;
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
   *  Constant: '<Root>/Speed_limit'
   *  Constant: '<S2>/Error_for_Max_Accel (The error distance in breaking points which is  threshold for using max acceleration of vehicle)'
   *  Constant: '<S2>/Min_Space_Gap_At_All_Times'
   *  Constant: '<S2>/Observed_Lead_Vehicle_Max_Deceleration (For now keeping one fixed  value to all vehicles  for scope of deliverable 1 )'
   *  Constant: '<S2>/Operational_Frequency(Hz)'
   *  Constant: '<S2>/Space_Gap_to_call_Max_Decel'
   *  Memory: '<S2>/previous_accel'
   *  Memory: '<S2>/previous_lead_velocity'
   */
  if ((fabs(chairforceone_B.EnabledSubsystem.In1.Data - rtb_Sum) < 0.001) &&
      (chairforceone_B.EnabledSubsystem_h.In1.Data > 250.0)) {
    if (chairforceone_B.EnabledSubsystem.In1.Data <
        chairforceone_P.Speed_limit_Value) {
      chairforceone_B.working_min_gap = (chairforceone_P.Speed_limit_Value -
        chairforceone_B.EnabledSubsystem.In1.Data) / (1.0 /
        chairforceone_P.Operational_FrequencyHz_Value);
      if ((chairforceone_P.Ego_Max_Acceleration_Value <=
           chairforceone_B.working_min_gap) || rtIsNaN
          (chairforceone_B.working_min_gap)) {
        chairforceone_B.working_min_gap =
          chairforceone_P.Ego_Max_Acceleration_Value;
      }
    } else {
      chairforceone_B.working_min_gap = 0.0;
    }

    if ((!(chairforceone_B.working_min_gap <=
           chairforceone_P.Ego_Max_Acceleration_Value)) && (!rtIsNaN
         (chairforceone_P.Ego_Max_Acceleration_Value))) {
      chairforceone_B.working_min_gap =
        chairforceone_P.Ego_Max_Acceleration_Value;
    }

    if ((!(chairforceone_B.working_min_gap >=
           -chairforceone_P.Ego_Max_Deceleration_Value)) && (!rtIsNaN
         (-chairforceone_P.Ego_Max_Deceleration_Value))) {
      chairforceone_B.working_min_gap =
        -chairforceone_P.Ego_Max_Deceleration_Value;
    }

    if (rtIsNaN(chairforceone_B.working_min_gap)) {
      chairforceone_B.working_decel_ego = (rtNaN);
    } else if (chairforceone_B.working_min_gap < 0.0) {
      chairforceone_B.working_decel_ego = -1.0;
    } else {
      chairforceone_B.working_decel_ego = (chairforceone_B.working_min_gap > 0.0);
    }

    if (rtIsNaN(chairforceone_DW.previous_accel_PreviousInput)) {
      lead_future_vel = (rtNaN);
    } else if (chairforceone_DW.previous_accel_PreviousInput < 0.0) {
      lead_future_vel = -1.0;
    } else {
      lead_future_vel = (chairforceone_DW.previous_accel_PreviousInput > 0.0);
    }

    if (chairforceone_B.working_decel_ego * lead_future_vel < 0.0) {
      chairforceone_DW.previous_accel_PreviousInput = 0.0;
    }

    chairforceone_B.working_min_gap = 0.3 * chairforceone_B.working_min_gap +
      0.7 * chairforceone_DW.previous_accel_PreviousInput;
  } else {
    chairforceone_B.working_decel_ego =
      chairforceone_P.Ego_Max_Deceleration_Value;
    chairforceone_B.working_min_gap =
      chairforceone_P.Min_Breaking_point_Gap_Value;
    if (chairforceone_P.Ego_Max_Deceleration_Value >
        chairforceone_P.Observed_Lead_Vehicle_Max_Decel) {
      chairforceone_B.working_decel_ego =
        chairforceone_P.Observed_Lead_Vehicle_Max_Decel;
      if ((chairforceone_P.Min_Space_Gap_At_All_Times_Valu <=
           chairforceone_P.Min_Breaking_point_Gap_Value) || rtIsNaN
          (chairforceone_P.Min_Breaking_point_Gap_Value)) {
        chairforceone_B.working_min_gap =
          chairforceone_P.Min_Space_Gap_At_All_Times_Valu;
      }
    }

    lead_future_vel = rtb_Sum * rtb_Sum;
    chairforceone_B.dt = chairforceone_B.EnabledSubsystem.In1.Data *
      chairforceone_B.EnabledSubsystem.In1.Data;
    chairforceone_B.working_decel_ego = (((lead_future_vel / 19.6 * 0.55 +
      lead_future_vel / (2.0 * chairforceone_P.Observed_Lead_Vehicle_Max_Decel))
      + chairforceone_B.EnabledSubsystem_h.In1.Data) - (chairforceone_B.dt /
      19.6 * 0.55 + chairforceone_B.dt / (2.0 *
      chairforceone_B.working_decel_ego))) - chairforceone_B.working_min_gap;
    chairforceone_B.working_min_gap = -(chairforceone_B.working_min_gap -
      chairforceone_P.Space_Gap_to_call_Max_Decel_Val);
    if (chairforceone_B.working_decel_ego >=
        chairforceone_P.Error_for_Max_AccelTheerrordist) {
      chairforceone_B.working_min_gap =
        chairforceone_P.Ego_Max_Acceleration_Value;
    } else if (chairforceone_B.working_decel_ego >= 0.0) {
      chairforceone_B.working_min_gap = rt_powd_snf
        (chairforceone_B.working_decel_ego /
         chairforceone_P.Error_for_Max_AccelTheerrordist, 1.1) *
        chairforceone_P.Ego_Max_Acceleration_Value;
    } else if (chairforceone_B.working_decel_ego <=
               chairforceone_B.working_min_gap) {
      chairforceone_B.working_min_gap =
        -chairforceone_P.Ego_Max_Deceleration_Value;
    } else {
      chairforceone_B.working_min_gap = sqrt(chairforceone_B.working_decel_ego /
        chairforceone_B.working_min_gap) *
        -chairforceone_P.Ego_Max_Deceleration_Value;
    }

    if (chairforceone_B.working_min_gap >
        -chairforceone_P.Ego_Max_Deceleration_Value) {
      if (chairforceone_B.working_min_gap < 0.0) {
        tmp = -1;
      } else {
        tmp = (chairforceone_B.working_min_gap > 0.0);
      }

      if (rtIsNaN(chairforceone_DW.previous_accel_PreviousInput)) {
        chairforceone_B.working_decel_ego = (rtNaN);
      } else if (chairforceone_DW.previous_accel_PreviousInput < 0.0) {
        chairforceone_B.working_decel_ego = -1.0;
      } else {
        chairforceone_B.working_decel_ego =
          (chairforceone_DW.previous_accel_PreviousInput > 0.0);
      }

      if (static_cast<real_T>(tmp) * chairforceone_B.working_decel_ego < 0.0) {
        chairforceone_DW.previous_accel_PreviousInput = 0.0;
      }

      if (chairforceone_B.working_min_gap >= 0.0) {
        chairforceone_B.working_decel_ego = 0.3;
      } else {
        chairforceone_B.working_decel_ego = 0.6;
      }

      chairforceone_B.working_min_gap = (1.0 - chairforceone_B.working_decel_ego)
        * chairforceone_DW.previous_accel_PreviousInput +
        chairforceone_B.working_decel_ego * chairforceone_B.working_min_gap;
    }

    chairforceone_B.dt = 1.0 / chairforceone_P.Operational_FrequencyHz_Value;
    lead_accel = (rtb_Sum - chairforceone_DW.previous_lead_velocity_Previous) /
      chairforceone_B.dt;
    chairforceone_B.working_decel_ego = chairforceone_B.working_min_gap *
      chairforceone_B.dt + chairforceone_B.EnabledSubsystem.In1.Data;
    lead_future_vel = lead_accel * chairforceone_B.dt + rtb_Sum;
    weighted_future_gap_tmp = chairforceone_B.dt * chairforceone_B.dt;
    chairforceone_B.dt = ((lead_future_vel * chairforceone_B.dt +
      chairforceone_B.EnabledSubsystem_h.In1.Data) + 0.5 * lead_accel *
                          weighted_future_gap_tmp) - (0.5 *
      chairforceone_B.working_min_gap * weighted_future_gap_tmp +
      chairforceone_B.working_decel_ego * chairforceone_B.dt);
    if (chairforceone_B.dt < chairforceone_P.Min_Space_Gap_At_All_Times_Valu) {
      chairforceone_B.dt -= chairforceone_P.Min_Space_Gap_At_All_Times_Valu;
      chairforceone_B.working_decel_ego -= lead_future_vel;
      if (chairforceone_B.dt < 0.0) {
        chairforceone_B.working_decel_ego = chairforceone_B.working_decel_ego *
          chairforceone_B.working_decel_ego / (2.0 * fabs(chairforceone_B.dt));
        if (-chairforceone_B.working_decel_ego < chairforceone_B.working_min_gap)
        {
          chairforceone_B.working_min_gap = 0.4 *
            -chairforceone_B.working_decel_ego + 0.6 *
            chairforceone_DW.previous_accel_PreviousInput;
        }
      }
    }

    if ((chairforceone_B.EnabledSubsystem.In1.Data <= 0.001) &&
        (chairforceone_B.working_min_gap < 0.0)) {
      chairforceone_B.working_min_gap = 0.0;
    }

    chairforceone_B.working_decel_ego = chairforceone_B.working_min_gap -
      chairforceone_DW.previous_accel_PreviousInput;
    if (chairforceone_B.working_decel_ego > 1.0) {
      chairforceone_B.working_min_gap =
        chairforceone_DW.previous_accel_PreviousInput + 1.0;
    } else if (chairforceone_B.working_decel_ego < -1.0) {
      chairforceone_B.working_min_gap =
        chairforceone_DW.previous_accel_PreviousInput - 1.0;
    }

    if ((!(chairforceone_B.working_min_gap <=
           chairforceone_P.Ego_Max_Acceleration_Value)) && (!rtIsNaN
         (chairforceone_P.Ego_Max_Acceleration_Value))) {
      chairforceone_B.working_min_gap =
        chairforceone_P.Ego_Max_Acceleration_Value;
    }

    if ((!(chairforceone_B.working_min_gap >=
           -chairforceone_P.Ego_Max_Deceleration_Value)) && (!rtIsNaN
         (-chairforceone_P.Ego_Max_Deceleration_Value))) {
      chairforceone_B.working_min_gap =
        -chairforceone_P.Ego_Max_Deceleration_Value;
    }
  }

  /* End of MATLAB Function: '<S2>/Acceleration(To be worked on)' */

  /* BusAssignment: '<Root>/Bus Assignment' */
  rtb_BusAssignment.Data = chairforceone_B.working_min_gap;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_chairforceone_36.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */

  /* Update for Memory: '<S2>/previous_accel' */
  chairforceone_DW.previous_accel_PreviousInput =
    chairforceone_B.working_min_gap;

  /* Update for Memory: '<S2>/previous_lead_velocity' */
  chairforceone_DW.previous_lead_velocity_Previous = rtb_Sum;
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

  /* InitializeConditions for Memory: '<S2>/previous_accel' */
  chairforceone_DW.previous_accel_PreviousInput =
    chairforceone_P.previous_accel_InitialCondition;

  /* InitializeConditions for Memory: '<S2>/previous_lead_velocity' */
  chairforceone_DW.previous_lead_velocity_Previous =
    chairforceone_P.previous_lead_velocity_InitialC;

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

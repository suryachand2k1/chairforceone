/*
 * chairforceone.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "chairforceone".
 *
 * Model version              : 1.91
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sat Nov 16 12:57:24 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef chairforceone_h_
#define chairforceone_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "chairforceone_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S4>/Enabled Subsystem' */
struct B_EnabledSubsystem_chairforce_T {
  SL_Bus_chairforceone_std_msgs_Float64 In1;/* '<S12>/In1' */
};

/* Block signals (default storage) */
struct B_chairforceone_T {
  real_T dt;
  real_T working_decel_ego;
  real_T working_min_gap;
  SL_Bus_chairforceone_std_msgs_Float64 r;
  B_EnabledSubsystem_chairforce_T EnabledSubsystem_i;/* '<S6>/Enabled Subsystem' */
  B_EnabledSubsystem_chairforce_T EnabledSubsystem_h;/* '<S5>/Enabled Subsystem' */
  B_EnabledSubsystem_chairforce_T EnabledSubsystem;/* '<S4>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_chairforceone_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S3>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_c;/* '<S6>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_d;/* '<S5>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_i;/* '<S4>/SourceBlock' */
  real_T previous_accel_PreviousInput; /* '<S2>/previous_accel' */
  real_T previous_lead_velocity_Previous;/* '<S2>/previous_lead_velocity' */
  boolean_T objisempty;                /* '<S6>/SourceBlock' */
  boolean_T objisempty_a;              /* '<S5>/SourceBlock' */
  boolean_T objisempty_aw;             /* '<S4>/SourceBlock' */
  boolean_T objisempty_k;              /* '<S3>/SinkBlock' */
};

/* Parameters for system: '<S4>/Enabled Subsystem' */
struct P_EnabledSubsystem_chairforce_T_ {
  SL_Bus_chairforceone_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                                 * Referenced by: '<S12>/Out1'
                                                 */
};

/* Parameters (default storage) */
struct P_chairforceone_T_ {
  SL_Bus_chairforceone_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                        * Referenced by: '<S1>/Constant'
                                                        */
  SL_Bus_chairforceone_std_msgs_Float64 Constant_Value_a;/* Computed Parameter: Constant_Value_a
                                                          * Referenced by: '<S4>/Constant'
                                                          */
  SL_Bus_chairforceone_std_msgs_Float64 Constant_Value_o;/* Computed Parameter: Constant_Value_o
                                                          * Referenced by: '<S5>/Constant'
                                                          */
  SL_Bus_chairforceone_std_msgs_Float64 Constant_Value_p;/* Computed Parameter: Constant_Value_p
                                                          * Referenced by: '<S6>/Constant'
                                                          */
  real_T Observed_Lead_Vehicle_Max_Decel;/* Expression: 2.5
                                          * Referenced by: '<S2>/Observed_Lead_Vehicle_Max_Deceleration (For now keeping one fixed  value to all vehicles  for scope of deliverable 1 )'
                                          */
  real_T Ego_Max_Deceleration_Value;   /* Expression: 3
                                        * Referenced by: '<Root>/Ego_Max_Deceleration'
                                        */
  real_T Min_Breaking_point_Gap_Value; /* Expression: 30
                                        * Referenced by: '<Root>/Min_Breaking_point_Gap'
                                        */
  real_T Min_Space_Gap_At_All_Times_Valu;/* Expression: 20
                                          * Referenced by: '<S2>/Min_Space_Gap_At_All_Times'
                                          */
  real_T Ego_Max_Acceleration_Value;   /* Expression: 4
                                        * Referenced by: '<Root>/Ego_Max_Acceleration'
                                        */
  real_T Speed_limit_Value;            /* Expression: 70
                                        * Referenced by: '<Root>/Speed_limit'
                                        */
  real_T Operational_FrequencyHz_Value;/* Expression: 5
                                        * Referenced by: '<S2>/Operational_Frequency(Hz)'
                                        */
  real_T Error_for_Max_AccelTheerrordist;/* Expression: 250
                                          * Referenced by: '<S2>/Error_for_Max_Accel (The error distance in breaking points which is  threshold for using max acceleration of vehicle)'
                                          */
  real_T Space_Gap_to_call_Max_Decel_Val;/* Expression: 2
                                          * Referenced by: '<S2>/Space_Gap_to_call_Max_Decel'
                                          */
  real_T previous_accel_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S2>/previous_accel'
                                          */
  real_T previous_lead_velocity_InitialC;/* Expression: 0
                                          * Referenced by: '<S2>/previous_lead_velocity'
                                          */
  P_EnabledSubsystem_chairforce_T EnabledSubsystem_i;/* '<S6>/Enabled Subsystem' */
  P_EnabledSubsystem_chairforce_T EnabledSubsystem_h;/* '<S5>/Enabled Subsystem' */
  P_EnabledSubsystem_chairforce_T EnabledSubsystem;/* '<S4>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_chairforceone_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_chairforceone_T chairforceone_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_chairforceone_T chairforceone_B;

#ifdef __cplusplus

}

#endif

/* Block states (default storage) */
extern struct DW_chairforceone_T chairforceone_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void chairforceone_initialize(void);
  extern void chairforceone_step(void);
  extern void chairforceone_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_chairforceone_T *const chairforceone_M;

#ifdef __cplusplus

}

#endif

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
 * '<Root>' : 'chairforceone'
 * '<S1>'   : 'chairforceone/Blank Message'
 * '<S2>'   : 'chairforceone/Inputs_To-Desired_Acceleration_Computation (Main Work)'
 * '<S3>'   : 'chairforceone/Publish'
 * '<S4>'   : 'chairforceone/curr_vel'
 * '<S5>'   : 'chairforceone/lead_dist'
 * '<S6>'   : 'chairforceone/rel_vel'
 * '<S7>'   : 'chairforceone/Inputs_To-Desired_Acceleration_Computation (Main Work)/Acceleration(To be worked on)'
 * '<S8>'   : 'chairforceone/Inputs_To-Desired_Acceleration_Computation (Main Work)/Breaking_Point_Difference_For_Plotting'
 * '<S9>'   : 'chairforceone/Inputs_To-Desired_Acceleration_Computation (Main Work)/Breaking_Point_Difference_For_Plotting/Breaking_Dist_Lead'
 * '<S10>'  : 'chairforceone/Inputs_To-Desired_Acceleration_Computation (Main Work)/Breaking_Point_Difference_For_Plotting/Breaking_Distance_Ego'
 * '<S11>'  : 'chairforceone/Inputs_To-Desired_Acceleration_Computation (Main Work)/Breaking_Point_Difference_For_Plotting/Breaking_Distance_Error'
 * '<S12>'  : 'chairforceone/curr_vel/Enabled Subsystem'
 * '<S13>'  : 'chairforceone/lead_dist/Enabled Subsystem'
 * '<S14>'  : 'chairforceone/rel_vel/Enabled Subsystem'
 */
#endif                                 /* chairforceone_h_ */

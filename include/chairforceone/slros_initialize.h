#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "chairforceone_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block chairforceone/curr_vel
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_chairforceone_std_msgs_Float64> Sub_chairforceone_27;

// For Block chairforceone/lead_dist
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_chairforceone_std_msgs_Float64> Sub_chairforceone_30;

// For Block chairforceone/rel_vel
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_chairforceone_std_msgs_Float64> Sub_chairforceone_29;

// For Block chairforceone/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_chairforceone_std_msgs_Float64> Pub_chairforceone_36;

void slros_node_init(int argc, char** argv);

#endif

#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "chairforceone";

// For Block chairforceone/curr_vel
SimulinkSubscriber<std_msgs::Float64, SL_Bus_chairforceone_std_msgs_Float64> Sub_chairforceone_27;

// For Block chairforceone/lead_dist
SimulinkSubscriber<std_msgs::Float64, SL_Bus_chairforceone_std_msgs_Float64> Sub_chairforceone_30;

// For Block chairforceone/rel_vel
SimulinkSubscriber<std_msgs::Float64, SL_Bus_chairforceone_std_msgs_Float64> Sub_chairforceone_29;

// For Block chairforceone/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_chairforceone_std_msgs_Float64> Pub_chairforceone_36;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}


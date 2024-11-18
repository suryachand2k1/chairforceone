# Chairforceone Controller README

## High-Level Overview
The controller is designed to maintain a safe and adaptive following distance between the ego and lead vehicles by dynamically adjusting the ego vehicle’s acceleration and deceleration based on their respective braking capabilities. When the ego vehicle has better braking power than the lead, it can follow at a closer distance, whereas if it has equal or lesser braking ability, it maintains a larger gap to ensure safety.

## Detailed Parameter Explanations
- **lead_vel**: Current speed of the lead vehicle, used to calculate stopping distance and assess safe following distance.
- **ego_vel**: Current speed of the ego vehicle, crucial for adjusting the following gap relative to the lead vehicle.
- **current_space_gap**: Measured distance between the lead and ego vehicles, serving as the basis for maintaining a safe gap.
- **lead_max_decel**: Maximum deceleration capacity of the lead vehicle, impacting how much following space is needed.
- **ego_max_decel**: Maximum deceleration capacity of the ego vehicle, influencing whether it can follow closer to the lead.
- **min_braking_points_gap**: The minimum safe following distance calculated based on braking capabilities of both vehicles when decelerations are equal or ego’s deceleration is less.
- **min_space_gap**: Minimum possible safe gap for closer following, used when the ego has better braking capacity than the lead.
- **ego_max_accel**: Maximum acceleration rate of the ego vehicle, limiting how quickly it can close the distance with the lead.
- **speed_limit**: The maximum allowable speed on the road, currently unused in the function but can be used for speed adjustments.
- **controller_frequency**: Frequency at which the controller updates, determining the time intervals for dynamic adjustments.
- **error_for_max_accel**: Threshold value that, when exceeded, triggers the application of the ego’s maximum acceleration.
- **max_decel_space_gap**: Additional buffer in the space gap, activated when the ego needs to decelerate sharply for safety.
- 

## Current Parameter Values for the Controller
- **lead_vel**: Sensor input, calculated from radar velocity of the sensor reading.
- **ego_vel**: Sensor input.
- **current_space_gap**: Sensor input.
- **lead_max_decel**: 2.5 m/s² (currently constant but can be made dynamic based on the observed vehicle in front).
- **ego_max_decel**: 3 m/s² (constant as it pertains to the ego vehicle).
- **min_braking_points_gap**: 30 m (constant).
- **min_space_gap**: 20 m (constant).
- **ego_max_accel**: 4 m/s² (constant).
- **speed_limit**: - 30 m/s (constant)
- **controller_frequency**: 5 Hz (constant).
- **error_for_max_accel**: 250 m (constant).
- **max_decel_space_gap**: 2 m (constant).

## Observations of the In-Car Experiment for the Controller
- Link to repository: [GitHub Repository](https://github.com/suryachand2k1/chairforceone.git)
- A lead vehicle may or may not be present in front of the ego vehicle for the controller to operate effectively.
  - **If the lead vehicle is missing**: Smooth acceleration until the speed limit is reached, followed by zero acceleration.
  - **If the lead vehicle is present**: With the current parameter settings, the **ego_max_decel (3 m/s²)** is greater than the **lead_max_decel (2.5 m/s²)**, resulting in maintaining the **min_space_gap** for closer following.
- Acceleration is observed to be smooth and remains within the operational range specified by the maximum acceleration limit.
- Deceleration is less smooth than acceleration but stays within the specified deceleration limit.
- Deceleration should be **0** when the velocity of the ego car is **0**.

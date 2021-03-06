# reaching-with-avoidance
===
## Synopsis

- **`reaching-with-avoidance`** is a completed solution to plan and monitor operation of iCub arm. It includes some modules for path planning generation and supervisor the movement of iCub arm, as describing in detail as following:

	- **`reaching-planner`** is a module to generate a motion plan for an arm of the iCub, based on the Incremental Sampling-based Algorithm - RRT* [1], [2]. A path plan includes the End-effector and the Elbow in the Forearm, generated by trigger from rpc command. The planner can operate alone or in combination with supervisor.
	- **`reaching-supervisor`** is a module to handle the communication between the `reaching-planner`, the `reactController` and user through yarp communication protocol.

## Dependencies
- [YARP](https://github.com/robotology/yarp)
- [iCub](https://github.com/robotology/icub-main)
- [icub-contrib-common](https://github.com/robotology/icub-contrib-common)
- [WYSIWYD](https://github.com/robotology/wysiwyd): for running with real robot 
- [reactController] (https://github.com/robotology/react-control) 

## Pipeline

<img src="https://github.com/robotology-playground/reaching-planner/blob/master/misc/planner_supervisor.bmp"/>

## Commands
- For the operation with `reaching-planner` only:
	- By sending commands through yarp rpc port, we can trigger the planner to generate a plan based on the environment perception,
i.e: `yarp rpc /<planner_module_name>/rpc:i`.

	- Command for replan: `replan <deadline>`, with `<deadline>` is the maximum exploration time of each planner.

- For the operation with `reaching-supervisor`:
	- By using rpc service to communicate with the supervisor, i.e: `yarp rpc /<supervisor_module_name>/rpc:i`.

## Documentation
Online documentation is available here: [http://robotology-playground.github.com/reaching-with-avoidance](http://robotology-playground.github.com/reaching-planner).

## Results
An example of the path generated by the planner is as following:

<p align="center">
  <img src="https://github.com/robotology-playground/reaching-planner/blob/master/misc/planning_result_GUI.bmp"/>
</p>

## License
Material included here is Copyright of *iCub Facility - Istituto Italiano di Tecnologia*
and is released under the terms of the GPL v2.0 or later. See the file LICENSE for details.

## Reference
[1] S. Karaman and E. Frazzoli, *"Optimal kinodynamic motion planning using incremental sampling-based methods,"* 49th IEEE Conference on Decision and Control (CDC), Atlanta, GA, 2010, pp. 7681-7687.

[2] S. Karaman and E. Frazzoli, *"Incremental Sampling-based Algorithms for Optimal Motion Planning,"* Proceedings of Robotics: Science and Systems, Zaragoza, Spain, 2010.
 

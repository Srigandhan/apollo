# Adding a Dummy Planner in the Planning Module

### Purpose
The purpose is to add a new planner and understand how the architecture is working. The planner need not solve the actual motion planning problem. 

### Instructions
* First step is to create a separate folder for the new [planner](/modules/planning/planner/dummy_planner/) in the planner directory.

* Then add dummy_planner.h,dummy_planner.cc, dummy_planner_test.cc and BUILD files in that directory.

* The first two files hold the declaration and implementation details of the new planner respectively.

* Make sure the new planner class implements Planner class from [planner.h](/modules/planning/planner/planner.h) and add the necessary methods that needed to be implemented. We can add any no of new functions in future.

* dummy_planner_test.cc file holds the unit test cases that needs to be verified each time the code is changed.

* BUILD file holds the dependencies related information for building the new planner.

* I have referred other planners to gather these details.

* For debugging and understanding the flow, I used ADEBUG to print out the debugging values to the planning log files. For enabling the debug mode, add --v=4 in [planning.conf](/modules/planning/conf/planning.conf) file.

* I have tried to load my planner instead of the other planners that are already there. In the existing setup, after loading loading apollo if we choose sim control in tasks and choose planning in module controller it will go to the public_road planner.

* I tried to modify that and load the new planner. For that I have added a flag and if the flag is true, it will call the new planner instead of the existing one. The following changes are done for the same.

* In [planning_gflags.h](/modules/planning/common/planning_gflags.h) and [planning_gflags.cc](/modules/planning/common/planning_gflags.cc) files the flag enable_dummy_planner is declared and defined respectively.

* In [on_lane_planner_dispatcher.cc](/modules/planning/planner/on_lane_planner_dispatcher.cc) file add an if condition to check the new flag whether its true and return the new planner's object.

* For returning the new planner's object first it should be added to [planning_config.pb.txt](/modules/planning/conf/planning_config.pb.txt) file, where other planners are present.

* And also the new planner should be registered in file [planner_dispatcher.cc](/modules/planning/planner/planner_dispatcher.cc) to return the object of the new planner.

* By following these steps I was successfully able to call the new planner module from Apollo.

* Note: For easy identification of the files added and modified check the commit changes in my apollo repo with commit message "Adding Dummy Planner to the Planning Module"

### Outcome
The following log files shows the debug messages that I added in the old planner and the new planner indicating the successful calling of the new planner.

The log file before changing the enable_dummy_planner to true

![Public Road Planner](/modules/planning/planner/dummy_planner/PublicRoadPlanner.png)

and the log file after changing the enable_dummy_planner to true

![Dummy Planner](/modules/planning/planner/dummy_planner/DummyPlanner.png)




##### It is a basic demo for adding a new planner, Apollo has lot of features needs to be explored further in detail.

# showpath_tum

#### introduce

Use rviz to draw path trajectories in geometry_msgs/PoseStamped format in. bag files

#### Software architecture

Software Architecture Description Using ROS system and C++language, refer to CMakeLists.txt for configuration, usually only ROS and cmake need to be installed.

#### Installation and Compilation

Download this source code into the src folder of your catkin worksapce:
```
$ cd catkin_ws/src
$  git clone https://github.com/hsiaochao/showpath
```
Compile the project:
```
$ cd catkin_ws
$ source devel/setup.bash
$ catkin_make
```
#### How to use it
Start the project on a terminal:
```
$ roslaunch showpath_tum showpath01.launch
```
You can complete the playback trajectory in rviz, and the effect is:
#### Participate in contributions

    Fork warehouse
    Create a new Feature_ Xxx branch
    Submit code
    Create a new Pull Request

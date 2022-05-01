# Navigation Using BehaviorTrees.CPP

## Launch Turtlebot Navigation

Source ros noetic (do this in every terminal):

`source /opt/ros/noetic/setup.bash`

Go to your workspace directory and source it (do this in every terminal): 

1. `cd ~/{workspace_dir}`

2. `source devel/setup.bash`

Then run the following launch files:

* (Terminal 1) `roslaunch turtlebot3_gazebo turtlebot3_world.launch`
* (Terminal 2) `roslaunch turtlebot3_navigation turtlebot3_navigation.launch`

First you need to click on the "2D Pose Estimate" button on rviz, so the robot knows its current position on the map. It should look like this:

![turtlebot_navigation](https://user-images.githubusercontent.com/52609366/166153170-41ababf5-00ed-48c5-81b8-1eb3841a885f.png)

* (Terminal 3) Go to the build directory: 
`cd ~/thesis_ws/src/Groot/build && ./Groot`

* (Terminal 4) `roslaunch bt_nav_actions node.bt_nav_move_base.launch`

On Groot, go to monitor mode and click "Connect". You should see the following behavior tree (you have 10 seconds to do that, otherwise the node would start and you won't see anything):

![groot](https://user-images.githubusercontent.com/52609366/166153368-35645408-1626-4c65-9c6a-033c2780a9d2.png)




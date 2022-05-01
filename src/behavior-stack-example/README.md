# behavior-stack-example

Repository containing a simple example of the Behavior Stack

The stack is partitioned into different layers of abstractions, each addressing different concerns; the separation of the layers allows level-specific efficient solutions. The number and separation of the layers are the subject of controversial discussions; in this example we use the abstraction layers defined by the [RobMoSys Robotic Software Component](robmosys.eu/wiki/start)
Following the abstraction above, we categorize the robotic software in:

- **Task Layer**, the layer where we design how the robot accomplishes a goal, disregarding the implementation details. In this example, it describes the a Behavior Tree (BT).

- **Skill Layer** , the layer where we design the basic capabilities of a robot (e.g. grasp an object); It describes the implementation of a leaf node of a BT that that can run in mainly two fashions with respect to the BT engine:

  - In the same executable, where the source code of the skill is written inside a leaf node of the BT engine that implements the *Tick()* and (for actions) the *Halt()* methods.

  - -In a separate executable, where the source code of the skill is written in a separate program that exposes the interface for calling
    the *Tick()* and (for actions) the *Halt()* methods. Over the network. A leaf node of the BT engine forwards the calls to the corresponding executable.

  A middleware usually handles these calls over the network.


- **Service Layer**, the layer that contains system-level entities that serve as the access point for the skills to command the robot (e.g. move mobile base destination, read sensor input); It described the server side of a service called by a skill to perform its basic capability (e.g. get battery level).

This example contains:

**run_bt**: An executable that runs a Behavior Tree (a **task**).

**SimpleCounter**: An executable that implements a counter and exposed 3 **services**, implemented as  [YARP Remote Procedure Calls](https://www.yarp.it/git-master/rpc_ports.html): one to increase, one to decrease, and one to reset the counter.

**ActionExample** A **skill** that when *starts* request to SimpleCounter to increase the counter by 1 every second. When the skill *stops*, it resets the counter.

**ConditionExample:** A **skill** that when *starts* request to SimpleCounter its counter value and returns to the BT on a *success* state if the counter is lower than 10; it returns  a *failure* state otherwise.

The skills **ActionExample** and **ConditionExample** are implemented in three ways:

- As leaf nodes in the BT (In the same executable of the BT).

- As YARP RF Modules (in a separate executable).

- As State Charts, using the QtSCXML engine (in a separate executable).

## Dependencies

- [YARP](https://www.yarp.it/)
- [BehaviorTree.cpp](https://github.com/BehaviorTree/BehaviorTree.CPP/)
- [Groot](https://github.com/BehaviorTree/Groot/) (For behavior trees visualization, optional)
- [GammaRay](https://www.kdab.com/development-resources/qt-tools/gammaray/) (State Chart visualization, optional)





## Installation (Tested on Ubuntu 20.04)

Install Dependencies:

- **YARP**: More information  [here](http://yarp.it/git-master/install.html).

  `sudo apt-get install cmake libace-dev`

  `git clone -b v3.6.0 https://github.com/robotology/yarp`

  `cd yarp && mkdir build && cd build && cmake .. && make`

  `sudo make install`  # Optional **NOTE! this installs the library system wide**

- **Behavior Tree.cpp**: (use a specific commit) run :

  `git clone -b 3.6.1  https://github.com/BehaviorTree/BehaviorTree.CPP.git`


  Then install the library:

  `cd BehaviorTree.CPP`

  `mkdir build;cd build`

  `cmake ..`

  `make`

  `sudo make install` **NOTE! this installs the library system wide**

- **Groot**: Follow the instructions [here](https://github.com/BehaviorTree/Groot/).

- **GammaRay:**

  add the following ppa :

  `sudo add-apt-repository -s -y ppa:robotology/test`

  `sudo apt install -y \
          gammaray \
          gammaray-plugin-quickinspector \
          gammaray-plugin-statemachineviewer`

Clone and compile this library:

`git clone https://github.com/hsp-iit/behavior-stack-example`

`mkdir build;cd build`

`cmake ..`

`make`



### Execute the examples

#### Example with skills as Leaf nodes

Go to the bin directory:

`cd bin`

and run the following executables:

1. `./simple_counter`
2. `./run_bt --from ./BT_leaf_nodes_example.xml`

If you have Groot installed, execute it in "Monitor Mode" and then click "Connect" to see the execution of the BT, as in the figure below


![leaf-nodes-BT](https://user-images.githubusercontent.com/8132627/100381717-dde4b100-3019-11eb-9725-0a2412d21562.png)


#### Example with skills as RFModules

Go to the bin directory:

`cd bin`

and run the following executables:

1. `./simple_counter`
2. `./rf_module_condition_example`
3. `./rf_module_action_example`
4. `./run_bt --from ./BT_rf_modules_example.xml`

If you have Groot installed, execute it in "Monitor Mode" and then click "Connect" to see the execution of the BT, as in the figure below

![rf-BT](https://user-images.githubusercontent.com/8132627/100381737-e9d07300-3019-11eb-8c7c-d73ddf99152a.png)
#### Example with skills as State Charts

Go to the bin directory:

`cd bin`

and run the following executables:

1. `./simple_counter`

2. `./state_chart_condition_example`

3. `./state_chart_action_example`

4. `./run_bt --from ./BT_state_charts_example.xml`


if you have GammaRay installed, run the executables 2. e 3. as:

`gammaray ./state_charts_condition_example`

`gammaray ./state_charts_action_example`

and then select the tab "State Machine" to see the execution of the skill, as in the figure below:

![gammaray](https://user-images.githubusercontent.com/8132627/100381949-78dd8b00-301a-11eb-9cd8-db05f27387ab.png)

If you have Groot installed, execute it in "Monitor Mode" and then click "Connect" to see the execution of the BT, as in the figure below

![SC-BT](https://user-images.githubusercontent.com/8132627/100381718-de7d4780-3019-11eb-8373-cc5e0a791b0c.png)

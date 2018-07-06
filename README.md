#Abstract
Our idea is to implement a robot which can perform SLAM (Simultaneous Localization and Mapping) autonomously in any surrounding. This automated bot can be deployed in various situations which are risky for humans such as in remote survelliance, etc. 

#Pre-requisite and Software Used
This whole work is being developed in ROS(Robot Operating System). It is being chosen due to its simple usage to implement various different components and pacjkages used for robot  building and to integrate them easily. To get basic ROS usage guidelines, refer this link: [ROS Documentaion](http://wiki.ros.org/) </br>
For kinect related installation of libraries and its working in Ubuntu, refer this link: [Libfreenect2](https://github.com/OpenKinect/libfreenect2) </br>
For learning more about ROS tools and its functionalties, I found this [book](pdfs/Mastering ROS for Robotics Programming.pdf) useful. </br>
Additionally, [rtabmap_ros](http://wiki.ros.org/rtabmap_ros/Tutorials/HandHeldMapping) generates real time 3D map using kinect and a GUI is being opened to view the map with some additional features. </br>
Create a new pacakge named rtabmap_ros inside your catkin workspace as stated in this [page](https://github.com/introlab/rtabmap_ros)

#Hardware and Electronics Used
* 1 Kinect Sensor
* 2 DC motors
* 1 Arduino Mega
* 2 Motor Controller
* 1 ESP-8266
* 6 Ultrasonic Sensor
* 2 simple wheel
* 2 castor wheel
* 1 Laptop
* Batteries/Adapters and wires

## Use of each component
* Kinect- Main sensor used for vision. It is 3D camera which have RGB as well depth sensing. Therefore used to create 3D map of surroundings.
* DC motors- 2 of them are used to achieve differntial drive configuration so so that our robot can move along all sides freely. 
* Arduino mega- Used to recieve commands from Ultrasonic sensors present at all sides of robot to prevent it from collision ny controlling motors accordingly.
* ESP-8266 - To control robot manually, it has been used. It is connected to arduino as well as with Mobile app so that robot can be move in any direction manually.

#Mechanical Design
A simple robot with differential drive as shown in below figure </br>.
![alt text](/images/mech1.png)
![alt text](/images/mech2.png)
![alt text](/images/mech3.png)

#Results 
A 3D map is being created as shown in figures
![alt text](/images/implementation1.png)
![alt text](/images/implementation2.png)

But some problems arises in autonomous localization. Also complete kinect capablities of depth sensing hasn't been harnessed. These things can be looked upon for future improvements of this project. 
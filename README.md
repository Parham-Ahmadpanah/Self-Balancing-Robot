# Project Introduction:
The Balancing Self Robot is a two-wheeled robot capable of maintaining balance vertically on its two wheels and preventing falls. The control mechanism implemented in this robot provides resistance against impacts and external forces, enabling it to move on uneven and sloped surfaces.
To achieve balance, the robot’s center of mass and the center of its wheels must align along a hypothetical vertical line. In this project, the deviation of the robot from the vertical position is detected and calculated using an ultrasonic sensor (05SR). To compensate for this deviation, the wheels must rotate in the direction of the robot’s fall, and proportional, derivative, and integral control coefficients (PID controller) are experimentally determined to balance the robot based on its behavior in different control coefficients.
## Objective:
The mechanical behavior of a balancing robot is akin to an inverted pendulum on a moving cart, exhibiting inherent instability due to its nonlinearity. This project serves as a suitable platform for researching control algorithms and examining the effects of each controller coefficient. Additionally, two-wheeled robots, due to their physical characteristics, offer other advantages:

Two-wheeled robots require fewer components and occupy less space compared to robots with three or four wheels.
They have greater degrees of freedom and are highly practical in confined spaces.
Due to their lightweight and fewer components, they consume less energy and can serve as a good option in transportation systems.

## Components and Equipment Introduction:
The two-wheeled balancing robot has a simple mechanical structure. It consists of a pendulum that mimics the robot’s body, along with two wheels aligned on the lower part of the robot, each directly powered by an electric motor. The robot may have additional degrees of freedom, leading to a more complex mechanical section.
The main components of this robot include:

Chassis or main body of the robot
Wheels
Actuators
Sensors
Electronic circuits for implementing control algorithms and motor operation
Battery

For each section of the structure, the following components are used:

Plastic parts, screws, and nuts for the robot’s body
Two wheels
Two DC motors (actuators)
Driver for the motor (actuator) and adapter for the driver
Two gearboxes to convert motor speed to torque (actuator)
Ultrasonic sensor 05SR (sensor)
Arduino Uno board (electronic circuits)
Jumper wires (electronic circuits)
Breadboard (electronic circuits)


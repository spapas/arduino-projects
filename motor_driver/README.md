Drive a 28BYJ-48 stepper motor

Uses an ULN2003 darlington transistor array (included in a pre-made mini board stepper driver) to drive a small 5v stepper motor.


Components
----------

1 x Arduino Uno R3
1 x 28BYJ-48 5V
1 x SBT0811 stepper driver
1 x ULN2003 (included in previous mini board)


Connection is very simple so I won't include a schematic:

- Connect + input of SBT0811 to arduino 5V output
- Connect - input of SBT0811 to ground
- Connect in1 input of SBT0811 Arduino pin 8 to 
- Connect in2 input of SBT0811 Arduino pin 9 to 
- Connect in3 input of SBT0811 Arduino pin 10 to 
- Connect in4 input of SBT0811 Arduino pin 11 to 

Just raise in 1-2-3-4 with the correct order (1, 12, 2, 23, 3, 34, 4, 41) to turn the stepper motor! 
The darlington array is needed to provide more current to the motor (arduino outputs 40 mA per output
pin while the motor needs ~ 200 mA -- https://arduino-info.wikispaces.com/SmallSteppers)


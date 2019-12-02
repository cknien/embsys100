**folder of Problem 2**
2. Convert the blinking led program into assembly code.
a. Go to the link Assignment\A06 folder and download the zip file “Module07_Assignment06_Starter_Code.zip”. Use the skeleton files (main.c, user_led.s, and delay.s) inside that zip file.
b. Create a new project and add the skeleton files to that project.
c. Make sure to setup the project to connect to your board (follow instructions form Module_02 if you forgot how to do that).
d. Implement the function control_user_led in assembly.
i. The function takes as input the led requested state (0 == OFF, 1 == ON) and the duration for holding the state.
ii. The function returns void.
e. Implement the function delay in assembly
i. The function takes as input an integer value.
ii. The function will decrement the value until it reaches 0
iii. Then returns void.
f. Call the “control_user_led” function from a while loop in main.
g. For any C code, use only data types defined in the “stdint.h” file

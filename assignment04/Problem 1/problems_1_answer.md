**1. Using bit-band region for peripherals:**

*a. Convert the Blinking Led demo to use the corresponding bit-band address instead of the register address used in the peripheral region.*

Ans:see attached source code "main.c"

*b. What instructions does the compiler produce in assembly for the “writing” to the GPIO bit when using bit-band address?*

Ans: MOVS

     LDR. N
     
     STR

*c. What were the instructions produced when writing to the GPIOx_ODR bit[5] directly?*

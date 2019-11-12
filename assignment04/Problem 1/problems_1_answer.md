**1. Using bit-band region for peripherals:**

*a. Convert the Blinking Led demo to use the corresponding bit-band address instead of the register address used in the peripheral region.*

Ans:see attached source code "main.c"

*b. What instructions does the compiler produce in assembly for the “writing” to the GPIO bit when using bit-band address?*

Ans: 

     MOVS      R0, #1
     LDR. N    R1, [PC, #0x3c]
     STR       R0, [R1]

*c. What were the instructions produced when writing to the GPIOx_ODR bit[5] directly?*

Ans:

     LDR.N     R1, [PC, #0x30]
     LDR       R2, [R1]
     ORRS.W    R2, R2, #32
     STR       R2, [R1]

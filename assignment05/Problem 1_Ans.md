**1. Create a function that allows swapping of two pointers.**

*a. Explain what the “main” function does to the CSTACK in order setup the input arguments prior to calling the swap_pointer() function?*

> First "main" push registers and LR into CSTACK for data storage purpose, and then manipulate stack pointer operations to store local int variable a, b and local int pointer variable ap, bp into CSTACK with their values respectively.


*b. And what are the values in R0 & R1 when swap_pointer() is called?*

> R0 and R1 values are the address of local pointer ap and bp


c. Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns, showing the values of the pointers and what they are pointing to, similar to the picture below:

**f. Set a break point inside the SysTick_Handler interrupt and capture a snapshot of the stack once inside the interrupt and LR value. Explain what are the values stored on the stack at the moment the Handler gets invoked.**
> The complier push the EPSR, PC, LR, R0-R3 and R12 into stack
> and use EXC_RETURN code in LR which indicates return to Thread mode by using Main Stack

![image of pb1f](https://github.com/cknien/embsys100/blob/master/assignment07/Problem%201/Problem%201f.PNG)

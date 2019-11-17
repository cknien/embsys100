**Create a function with multiple arguments (5 arguments for example) and call that function from within another function. Trace thru the assembler and note:**

*a. How does the calling function pass the values to the called function?*

  >Ans: Moves the values to registers, inside the function grab the values from stored registers

*b. What extra code did the compiler generate before calling the function with the multiple arguments?*

  >Ans: Push the Link register and some general register into CSTACK, so the LR value to origianl return place won't lose

*c. What extra code did the compiler generate inside the called function with the multiple list of arguments?*

  >Ans: Also push the Link register and some general register into CSTACK because the LR may use for storing data, so the LR value to the  return place of calling function won't lose

*d. Any other observations?*

  >Ans: If there are too many arguments the comliper will use registers beyond R0-R12 like LR, it is ok since origianl LR value was pushed into CSTACK for return use 

**Observe and answer:**
	
  1. Inject 0x1FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
  
	a) What is the value of the “counter” from the “Locals” window?
	 0x20000000
	b) What is the value of the “counter” in the “Register” window?
	 0x20000000 
	c) Which flags are set in the APSR register? Explain why? 
	 No flag is set in APST register. 0x20000000 is still positive value and no overflow
   
  2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter” 
  
	a) What happens to the value of “counter” in the “Locals” window? 
	 Counter value becomes 0x00000000
	b) What flags, if any, are set in the APSR? 
	 Z flag is set to 1 and C flag is set to 1
  
  3. Change the “counter” variable type in your code to “unsigned”. Inject the values “0x1FFFFFFF” then step thru the program to increment the “counter” once: 
  
  a) What is the value of “counter” in the “Locals” window after incrementing for each value?
	 
   0x20000000 
   
   b) What flags, if any, are set in the APSR? Explain why? 
	 
   No flag is set in APST register. 0x20000000 is still positive value and no overflow
   
  4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once: 
  
	a) What is the value of “counter” in the “Locals” window after incrementing for each value?
	 Counter value becomes 0x00000000 
	b) What flags, if any, are set in the APSR? Explain why? 
	 Z flag is set to 1 and C flag is set to 1
  
  5. Move the “counter’ variable outside of main (at the top of the file):   
  
  a) What is the scope of the variable “counter”?
  
	 Global variable
   
	b) Is it still visible in the “Locals” view? 
	 No
   
	c) In which window view can we track “counter” now?
	 Auto view or Watch view
   
	d) What is the address of the “counter” variable in memory? 
	 0x20000000
	
  6. Change the source code to the following, then run the program still in the simulator: 

	a) What is the value of “counter” at the end of the program (halting at the return 0 statement) 
	 4
	b) Explain why the counter value has changed? 
	 Because counter and p_int point to same address 0x20000000. So if conduct operation of increment 1 to *p_int will also increment counter’s value to 1
   
   7. Change the setting of IAR to run the same program on the evaluation board: 

	a) What is the address where “counter” is stored? 
	 0x20000000
	b) Is the “counter” variable stored in RAM or ROM?
	 RAM 
	c) What is the value of “counter” at the end of the program (halting at the return 0 statement). 
	 4


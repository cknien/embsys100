/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swaping 2 Chars
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr_swap   // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm       // Exports symbols to other modules
                          // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Calls C code to print a string; 
                  swaps of its input arguments
C Prototype     : void swapCharsAsm(char* char1, char* char2)
                : Where values of char1 and char2 pointed to is going to be swapped
Parameters      : R0: Address of val
Return value    : R0
*******************************************************************************/  
  
swapCharsAsm
    PUSH {R0,R1,LR}             // save the input arguments and return address
    LDR R0,=myCstr_swap         // load (global) address of address of string into R0
    LDR R0,[R0]                 // load address of string into R0
    BL  PrintString             // call PrintString to print the string
    POP {R0,R1,LR}              // Restore R0, R1 and LR
    LDRB R2, [R0]               // load the value at address stored in R0 to R2
    LDRB R3, [R1]               // load the value at address stored in R1 to R3
    STRB R3, [R0]               // store the value at R3 to address stored in R0
    STRB R2, [R1]               // store the value at R2 to address stored in R1
    BX LR                       // return (with function result in R0)


    END

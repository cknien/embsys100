#include"stack.h"
#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

// Pointer to stack elements for adding and retrieving
int* stackPtr;

// LIFO Stack is Empty if stackPtr==0;
// LIFO Stack is Full if stackPtr+1 > Address of last element in the stack;

// Initialize internals of the stack
void stack_init(void)
{
    stackPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = 0;
    }
}

// Push data to stack
// If stack is full return error
// Otherwise return success
int stack_push(int data)
{
    if (stackPtr == &StackStore[STACK_SIZE-1])
    {
        // stack is full
        return -1;
    }
    
    if (stackPtr == 0)
    {
        stackPtr = &StackStore[0];
    }    
    else    
    {
        stackPtr++;
    }
    
    *stackPtr = data;
    return 0;
}

// Pop data from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* data)
{   
    if (stackPtr == 0)
    {
        // stack is empty
        return -1;
    }

    *data = *stackPtr;
    
    if (stackPtr == &StackStore[0])
    {
        stackPtr = 0;
    }
    else
    {
        stackPtr--;
    }
    
    return 0;
}

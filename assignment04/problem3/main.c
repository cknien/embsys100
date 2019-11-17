#include <assert.h>
#include "stack.h"

int main()
{
    int result1;
    int result2;
    int testInt;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testInt);
      
    // Assert:
    assert(-1 == result1);
    assert(100 == testInt);
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_push(99);
    result2 = stack_pop(&testInt);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(99 == testInt);
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(99);
    stack_push(98);
    stack_push(97);                                    
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(97 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(98 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(99 == testInt);
  
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(99);
    stack_push(98);
    stack_push(97);
    
    // Assert:
    assert(-1 == stack_push(96));

    assert(0 == stack_pop(&testInt));
    assert(97 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(98 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(99 == testInt);
    
    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(99);
    stack_push(98);
    stack_push(97);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(97 == testInt);

    assert(0 == stack_push(96));
    
    assert(0 == stack_pop(&testInt));
    assert(96 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(98 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(99 == testInt);
    
    // ***********************************************************************
    // Test6: Fill stack and retrieve all items twice
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(99);
    stack_push(98);
    stack_push(97);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(97 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(98 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(99 == testInt);

    assert(0 == stack_push(96));
    assert(0 == stack_push(95));
    assert(0 == stack_push(94));
    
    assert(-1 == stack_push(93));

    assert(0 == stack_pop(&testInt));
    assert(94 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(95 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(96 == testInt);
   
    
  return 0;
}

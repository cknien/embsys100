#include "delay.h"
#include "stdint.h"
#include "stm32f401xe.h"

int delay_count; //count milliseconds

//void delay(unsigned int iteration)
//{
//    while (iteration > 0)
//    {
//        iteration--;    
//    }
//}

void delay(uint32_t delayInMilliseconds)
{
  if (delay_count == delayInMilliseconds)
  {
    GPIOA->ODR ^= GPIO_ODR_OD5;
    delay_count = 0;
  }
}
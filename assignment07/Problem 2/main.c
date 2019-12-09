#include "stm32f401xe.h"
#include "stdint.h"
#include "delay.h"

#define SYS_CLOCK_HZ 16000000u / 1000;

void main(void)
{
   
    // ***********************

    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
    
    SysTick->LOAD = SYS_CLOCK_HZ;  
    SysTick->VAL = 0x0;
    SysTick->CTRL = 0x7;
   
    while(1)
    {
        delay(2000);              
    }
}

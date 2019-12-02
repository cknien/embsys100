#include "stm32f401xe.h"

//#define RCC_BASE 0x40023800
//#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

//#define GPIOA_BASE 0x40020000
//#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
//#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

//#define GPIOA (1<<5)

void delay(int);
void delay(int iteration)
{
  while (iteration > 0)
  {
    iteration--;
  }
}

int main()
{
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Write: 0x1
    // 1. Enable clock to Peripheral
    //RCC_AHB1ENR |= 0x1;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
  
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Write: 0x400
    // 2. Set GPIO5 to Output
    //GPIOA_MODER |= 0x400;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    
    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Write: 0x20
    // 3. Write 1 or 0 to turn ON/OFF LED
  
    while(1)
    {
      delay(1000000);
      
      //GPIOA_ODR |= 0x00000020;
      //GPIOA_ODR |= GPIOA;
      GPIOA->ODR |= GPIO_ODR_OD5;
      
      delay(1000000);
      
      //GPIOA_ODR &= 0xFFFFFFDF;
      //GPIOA_ODR &= ~GPIOA;
      GPIOA->ODR &= ~GPIO_ODR_OD5;
    }
    return 0;
}
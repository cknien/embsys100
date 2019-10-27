/*EMBSYS100 Assignment 03 Problems 2
    LED Blinking Morse Code for First Name
    My First Name is: Chun Wei
*/


#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

//Function of unit delay for Morse code
void delay(int unit)
{
    volatile int counter = 0;
    while (counter < (unit * 1000000))
    {
      counter++;
    }
}

int main()
{
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Write: 0x1
    // 1. Enable clock to Peripheral
   RCC_AHB1ENR |= 0x1;
  
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Write: 0x400
    // 2. Set GPIO5 to Output
  GPIOA_MODER |= 0x400;

    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Write: 0x20
    // 3. Write 1 or 0 to turn ON/OFF LED

  
  void delay();
  
  while(1)
  {
    delay(1);
    
    //Signal word "Chun"
    //Signal letter "c"       
    GPIOA_ODR |= GPIOA; //    GPIOA_ODR |= 0x00000020; Turn on LED
    delay(3);
    
    GPIOA_ODR &= ~GPIOA; //   GPIOA_ODR &= 0xFFFFFFDF; Turn off LED
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(3);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(3); //space from next letter is 3 unit
    
    //Singal letter "h"
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(3);
    
    //Signal letter "u"
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
   
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(3);
    
    GPIOA_ODR &= ~GPIOA;
    delay(3);
    
    //Singal letter "n"
    GPIOA_ODR |= GPIOA;
    delay(3);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(7); //space from next word is 7 unit
    
    //Signal word "Wei"
    //Signal letter "w"
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(3);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(3);
    
    GPIOA_ODR &= ~GPIOA;
    delay(3);
    
    //Singal letter "e"
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(3);
    
    //Singal letter "i"
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(1);
    
    GPIOA_ODR |= GPIOA;
    delay(1);
    
    GPIOA_ODR &= ~GPIOA;
    delay(14); //Take a break and cycle another run of code
    
    
  }
  return 0;
}

#include "stm32f767xx.h"

int main(void) {
    // Enable GPIOB clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    
    // Set PB0 as output
    GPIOB->MODER &= ~GPIO_MODER_MODER0;
    GPIOB->MODER |= (0x1 << GPIO_MODER_MODER0_Pos);
    
    while (1) {
        GPIOB->ODR ^= GPIO_ODR_OD0;
        for (volatile int i = 0; i < 500000; i++);
    }
}
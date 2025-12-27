#include "stm32f767xx.h"

int main(void) {
    // Enable GPIOD clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    
    // Enable USART3 clock
    RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    
    // PD8 as alternate function
    GPIOD->MODER &= ~(0b11 << 16);
    GPIOD->MODER |= (0b10 << 16);
    GPIOD->AFR[1] &= ~(0xF << 0);
    GPIOD->AFR[1] |= (7 << 0);  // AF7 for USART3
    
    // Baud rate for 16 MHz HSI
    USART3->BRR = 139;
    
    // Enable TX and USART
    USART3->CR1 = (1 << 0) | (1 << 3);
    
    // Send 'U' forever
    while (1) {
        while (!(USART3->ISR & (1 << 7)));
        USART3->TDR = 'U';
        for (volatile int i = 0; i < 500000; i++);
    }
}
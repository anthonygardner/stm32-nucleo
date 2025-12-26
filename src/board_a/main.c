#include "can.h"
#include "clock.h"
#include "eth.h"
#include "gpio.h"
#include "uart.h"
#include "stm32f767xx.h"

int main(void) {
    // Enable clocks
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    
    // Configure PD8 as AF7
    GPIOD->MODER |= (0b10 << 16);
    GPIOD->AFR[1] |= (7 << 0);
    
    // Baud rate for 16 MHz, 115200 baud
    USART3->BRR = 139;
    
    // Enable TX and USART
    USART3->CR1 |= (1 << 3) | (1 << 13);
    
    // Send forever
    while (1) {
        while (!(USART3->ISR & (1 << 7)));
        USART3->TDR = 'U';
        for (volatile int i = 0; i < 100000; i++);
    }
}
#include "gpio.h"
#include "stm32f767xx.h"

void led_init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    
    GPIOB->MODER &= ~GPIO_MODER_MODER0;
    GPIOB->MODER |= (0x1 << GPIO_MODER_MODER0_Pos);
}

void led_toggle(void) {
    GPIOB->ODR ^= GPIO_ODR_OD0;
}
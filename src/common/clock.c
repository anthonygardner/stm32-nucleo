#include "clock.h"
#include "stm32f767xx.h"

void clock_init(void) {
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY));

    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
}
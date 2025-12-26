#include "can.h"
#include "clock.h"
#include "eth.h"
#include "gpio.h"
#include "stm32f767xx.h"

int main(void) {
    clock_init();
    led_init();
    can_init();
    eth_init();
    
    uint8_t counter = 0;
    
    while (1) {
        uint8_t data[8] = {counter++, 0, 0, 0, 0, 0, 0, 0};
        can_transmit(0x100, data, 1);
        
        led_toggle();
        for (volatile int i = 0; i < 500000; i++);
    }
}
#ifndef CAN_H
#define CAN_H

#include <stdint.h>

void can_init(void);

int can_receive(uint32_t *id, uint8_t *data, uint8_t *len);

void can_transmit(uint32_t id, uint8_t *data, uint8_t len);

#endif
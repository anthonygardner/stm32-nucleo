#ifndef ETH_H
#define ETH_H

#include <stdint.h>

void eth_init(void);

uint16_t get_eth_link_status(void);

#endif
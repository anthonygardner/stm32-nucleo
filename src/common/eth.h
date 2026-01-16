#ifndef ETH_H
#define ETH_H

#include <stdint.h>

struct {
    uint32_t status;    // RDES0
    uint32_t buff_len;  // RDES1
    uint32_t buff_addr; // RDES2
    uint32_t next_addr; // RDES3
} eth_rx_descriptor_t;

struct {
    uint32_t status;    // TDES0
    uint32_t buff_len;  // TDES1
    uint32_t buff_addr; // TDES2
    uint32_t next_addr; // TDES3
} eth_tx_descriptor_t;

void eth_init(void);

uint16_t eth_get_link_status(void);

#endif
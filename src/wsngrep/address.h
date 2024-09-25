#pragma once

#include <stdint.h>
#include <stdbool.h>

//! Address string Length
#define ADDRESSLEN 22

//! Shorter declaration of address structure
typedef struct address address_t;

/**
 * @brief Network address
 */
struct address {
    //! IP address
    char ip[ADDRESSLEN];
    //! Port
    uint16_t port;
};

/**
 * @brief Check if two address are equal (including port)
 *
 * @param addr1 Address structure
 * @param addr2 Address structure
 * @return true if addresses contain the IP address, false otherwise
 */
bool
addressport_equals(address_t addr1, address_t addr2);

/**
 * @brief Check if two address are equal (ignoring port)
 *
 * @param addr1 Address structure
 * @param addr2 Address structure
 * @return true if addresses contain the same data, false otherwise
 */
bool
address_equals(address_t addr1, address_t addr2);

/**
 * @brief Check if a given IP address belongs to a local device
 *
 * @param address Address structure
 * @return true if address is local, false otherwise
 */
bool
address_is_local(address_t addr);

/**
 * @brief Convert string IP:PORT to address structure
 *
 * @param string in format IP:PORT
 * @return address structure
 */
address_t
address_from_str(const char* ipport);

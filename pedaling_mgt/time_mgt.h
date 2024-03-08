/**
 * Copyright (c) 2019 eBikeLabs. All Rights Reserved.
 */

#pragma once

#include <stdint.h>

/**** Public API ****/

/**
 * @brief Update the current timestamp
 */
void update_timestamp(void);

/**
 * @brief Return the current timestamp in µs
 */
uint32_t get_timestamp(void);
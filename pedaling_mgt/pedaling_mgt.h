/**
 * Copyright (c) 2019 eBikeLabs. All Rights Reserved.
 */

#pragma once

/**** Public API ****/

/**
 * @brief Return current pedaling speed in RPM
 */
float get_pedaling_speed(void);

/**
 * @brief Return average current pedaling speed in RPM
 */
float get_average_pedaling_speed(void);

/**
 * @brief Callback when a magnet passes in front of the pedaling sensor
 */
void new_magnet_cb(void);

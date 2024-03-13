/**
 * Copyright (c) 2019 eBikeLabs. All Rights Reserved.
 */

#include "pedaling_mgt.h"
#include "time_mgt.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

//Cyclical buffer of size 13.
//We allocate one extra location (13 instead of 12)
//to be able to compute the average speed, keeping track
//of the current magnet previous activation value.
#define n_magnet 12u
static uint32_t cyclic_buff[n_magnet+1u]={0u};
static uint8_t buff_pos = n_magnet; //Start at the end of the buffer
static bool is_buff_full = false;

/**
 * @brief get_prev_pos gets the previous cyclical buffer index.
 * @return the index preceding buff_pos.
 */
static uint8_t get_prev_pos(void){
    return (buff_pos == 0u) ? n_magnet
                            : buff_pos-1u;
}

/**
 * @brief get_next_pos gets the next cyclical buffer index.
 * @return the index following buff_pos.
 */
static uint8_t get_next_pos(void){
    return (buff_pos == n_magnet) ? 0u
                                  : buff_pos+1u;
}

/**** Public API ****/

float get_pedaling_speed(void){
    if(!is_buff_full && (buff_pos < 1u || buff_pos == n_magnet)){
        //Not enough data to compute pedaling speed.
        //we test buff_pos == n_magnet because buff_pos is
        //set to n_magnet at init
        return 0.0f;
    }
    const float delta_t = cyclic_buff[buff_pos] - cyclic_buff[get_prev_pos()];
    return 60.0f*1e6f / (n_magnet*delta_t); //Get the speed in rotation / seconds
}

float get_average_pedaling_speed(void){
    if(!is_buff_full){
        //If we have done less than one rotation,
        //We don't compute the average speed.
        return 0.0f;
    }
    //Since the buffer is of size n_magnet+1,
    //cyclic_buff[get_next_pos()] gives the previous value of cyclic_buff[buff_pos]
    const float delta_t = cyclic_buff[buff_pos] - cyclic_buff[get_next_pos()];
    return 60.0f*1e6f / delta_t; //Get the speed in rotation / seconds
}

void new_magnet_cb(void){
    buff_pos = get_next_pos();
    cyclic_buff[buff_pos] = get_timestamp();
    if(!is_buff_full && (buff_pos == n_magnet)){
        is_buff_full = true;
    }
}

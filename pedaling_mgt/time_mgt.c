/**
 * Copyright (c) 2019 eBikeLabs. All Rights Reserved.
 */

#include "time_mgt.h"

#include <sys/timeb.h>
#include <sys/time.h>
#include <stdio.h>
#include <time.h>

/**** Defines ****/

#define NUMBER_SAMPLE_TIME 30

/**** Private variables ****/

static uint32_t timestamp = 0;
static const uint32_t timestamp_array[NUMBER_SAMPLE_TIME] = {
    100000u,
    189287u,
    269932u,
    349298u,
    422824u,
    486928u,
    549428u,
    616095u,
    685539u,
    759067u,
    851661u,
    970709u,
    1137375u,
    1315947u,
    1482613u,
    1643904u,
    1800152u,
    1943011u,
    2068011u,
    2184291u,
    2297926u,
    2406622u,
    2513004u,
    2617172u,
    2719213u,
    2819212u,
    2915367u,
    3009708u,
    3102300u,
    3202301u};

/**** Public API ****/

void update_timestamp(void)
{
    static uint8_t index = 0;
    timestamp = timestamp_array[index];

    // Update index
    index++;
    if (index > NUMBER_SAMPLE_TIME)
    {
        index = 0u;
    }
}

uint32_t get_timestamp(void)
{
    return timestamp;
}

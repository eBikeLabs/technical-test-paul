/**
 * Copyright (c) 2019 eBikeLabs. All Rights Reserved.
 */

#include "pedaling_mgt.h"
#include "time_mgt.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**** Defines ****/

#define NUMBER_OF_INTERRUPTION 30

/**** MAIN ****/

int main(void)
{
    FILE *fp;

    fp = fopen("pedaling_speed.csv", "w+");

    fprintf(fp, "pedaling_speed,average_pedaling_speed\n");

    for (uint8_t i = 0; i < NUMBER_OF_INTERRUPTION; i++)
    {
        update_timestamp();

        // Call handler interrupt
        new_magnet_cb();

        // Save data on CSV file
        fprintf(fp, "%2.1f,%2.1f\n", get_pedaling_speed(), get_average_pedaling_speed());
    }

    // Close CSV file
    fclose(fp);

    return 0;
}
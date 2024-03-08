# Technical test pedaling speed

## Context

In order to provide top-notch assistance, eBikeLabs needs to know the rider’s pedaling speed.

It is given by a [12 magnets PAS sensor](https://www.amazon.fr/MAGT-Assistant-%C3%A9lectrique-Sensor-v%C3%A9lo-ebike-Adjoint/dp/B07S7RSWQN/ref=sr_1_3?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=3EFEQ8ZX40M4H&keywords=pedaling+sensor&qid=1700823138&sprefix=pedaling+sensor%2Caps%2C86&sr=8-3) mounted on the bracket housing, that sends a signal every time a magnet passes in front of the sensor.

Our algorithms require knowledge of the current pedaling speed, as well as the average pedaling speed over the last pedal revolution.

## Problem statement  

Please implement the 3 public functions of the C module `pedaling_mgt`, as described in the header `pedaling_mgt.h`.

Your code may rely on the public function `uint32_t get_timestamp(void)` provided by the C module `time_mgt`.

## How the program works

The main file calls the `new_magnet_cb` function which simulates the passage of magnets. The program creates a csv file to store the information sent by the `pedaling_mgt` library.

## How to use the program

- First you need to compile the program using the make command. A `pedaling_speed` executable will be created.
- To run the program, run the `./pedaling_speed` command. A pedaling_speed.csv file will be created, it contains the `pedaling_speed` and `average_pedaling_speed` information.

Good luck

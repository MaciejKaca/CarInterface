#include <stdint.h>

#pragma once

enum Devices
{
    BRAKE_LIGHT = 0,
    REVERSE_LIGHT = 1,
    LEFT_BLINKER_LIGHT = 2,
    RIGHT_BLINKER_LIGHT = 3,
    HEADLIGHT = 4,
    SERVO = 5,
    HAZARD_LIGHTS = 6
};

enum Command
{
    OFF = 0,
    ON = 255,
    DAYTIME = 10,
    BRAKE = 255,
    HIGH_BEAM = 255,
    SET_NEW_ZERO = 1,
    TURN = 2
};

struct LightsAndServoMsg
{
    Devices device;
    Command command;
    int8_t degrees;
};

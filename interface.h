#pragma once

#include <stdint.h>

enum Devices
{
    BRAKE_LIGHT = 1,
    REVERSE_LIGHT = 2,
    TURN_SIGNAL = 3,
    HEADLIGHT = 4,
    SERVO = 5
};

enum ServoCommand
{
    SET_NEW_ZERO = 1,
    TURN = 2
};

enum TurnSignalCommand
{
    TURN_SIGNAL_OFF = 0,
    LEFT = 2,
    RIGHT = 3,
    HAZARD_LIGHTS = 4
};

enum HeadLightCommand
{
    HEADLIGHT_OFF = 0,
    HEADLIGHT_DAYTIME = 20,
    HIGH_BEAM = 255
};

enum BrakeLightsCommand
{
    BRAKE_LIGHT_OFF = 0,
    BRAKE_LIGHT_DAYTIME = 20,
    STOP = 255
};

enum ReverseLightCommand
{
    REVERSE_LIGHT_OFF = 0,
    ON = 20
};

struct ServoInfo
{
    ServoCommand command;
    int8_t degrees;
};

struct LightsAndServoMsg
{
    Devices device;
    ServoInfo servoInfo;
    HeadLightCommand headLightCommand;
    BrakeLightsCommand brakeLightsCommand;
    ReverseLightCommand reverseLightCommand;
    TurnSignalCommand turnSignalCommand;
};

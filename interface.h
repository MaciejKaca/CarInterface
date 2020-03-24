#pragma once

#include <stdint.h>

enum Devices : uint8_t
{
    BRAKE_LIGHT = 1,
    REVERSE_LIGHT = 2,
    TURN_SIGNAL = 3,
    HEADLIGHT = 4,
    SERVO = 5
};

enum ServoCommand : uint8_t
{
    SET_NEW_ZERO = 1,
    TURN = 2
};

enum TurnSignalCommand : uint8_t
{
    TURN_SIGNAL_OFF = 0,
    TURN_SIGNAL_LEFT = 2,
    TURN_SIGNAL_RIGHT = 3,
    HAZARD_LIGHTS = 4
};

enum HeadLightCommand : uint8_t
{
    HEADLIGHT_OFF = 0,
    HEADLIGHT_DAYTIME = 20,
    HEADLIGHT_HIGH_BEAM = 255
};

enum BrakeLightsCommand : uint8_t
{
    BRAKE_LIGHT_OFF = 0,
    BRAKE_LIGHT_DAYTIME = 20,
    BRAKE_LIGHT_STOP = 255
};

enum ReverseLightCommand : uint8_t
{
    REVERSE_LIGHT_OFF = 0,
    REVERSE_LIGHT_ON = 20
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

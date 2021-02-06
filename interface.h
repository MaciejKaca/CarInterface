#pragma once

#include <stdint.h>
#include "../MPU9250/MPU9250.h"

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

struct Vector3D
{
    float x;
    float y;
    float z;
};

enum SignalID
{
    CONFIGURATION_REQ = 0,
    CONFIGURATION_CFM = 1,
    CALIBRATION_REQ = 2,
    CALIBRATION_CFM = 3,
    MEASUREMENT_IND = 4
};

struct SignalBase
{
    SignalBase(SignalID _signalID) : signalID(_signalID) {}
    const SignalID signalID;
};


struct CalibrationReq : SignalBase
{
    CalibrationReq() : SignalBase(CALIBRATION_REQ) {}
    float magneticDelication;
    MPU9250Setting mpuSettings;
};

struct ConfigurationReq : SignalBase, CalibrationReq
{
    ConfigurationReq() : SignalBase(CONFIGURATION_REQ) {}
    Vector3D accelrBias;
    Vector3D gyroBias;
    Vector3D magBias;
    Vector3D magScale;
};

struct MeasurementInd : SignalBase
{
    MeasurementInd() : SignalBase(MEASUREMENT_IND) {} 
    int16_t roll;
    int16_t pitch;
    int16_t yaw;
};

struct ConfigurationCfm : SignalBase
{
    ConfigurationCfm() : SignalBase(CONFIGURATION_CFM) {} 
    bool isValid;
};

struct CalibrationCfm : SignalBase, ConfigurationCfm
{
    CalibrationCfm() : SignalBase(CALIBRATION_CFM) {}
};
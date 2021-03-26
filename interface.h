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

enum class ACCEL_FS_SEL : uint8_t
{
    A2G,
    A4G,
    A8G,
    A16G
};

enum class GYRO_FS_SEL : uint8_t
{
    G250DPS,
    G500DPS,
    G1000DPS,
    G2000DPS
};

enum class MAG_OUTPUT_BITS : uint8_t
{
    M14BITS,
    M16BITS
};

enum class FIFO_SAMPLE_RATE : uint8_t
{
    SMPL_1000HZ,
    SMPL_500HZ,
    SMPL_333HZ,
    SMPL_250HZ,
    SMPL_200HZ,
    SMPL_167HZ,
    SMPL_143HZ,
    SMPL_125HZ,
};

enum class GYRO_DLPF_CFG : uint8_t
{
    DLPF_250HZ,
    DLPF_184HZ,
    DLPF_92HZ,
    DLPF_41HZ,
    DLPF_20HZ,
    DLPF_10HZ,
    DLPF_5HZ,
    DLPF_3600HZ,
};

enum class ACCEL_DLPF_CFG : uint8_t
{
    DLPF_218HZ_0,
    DLPF_218HZ_1,
    DLPF_99HZ,
    DLPF_45HZ,
    DLPF_21HZ,
    DLPF_10HZ,
    DLPF_5HZ,
    DLPF_420HZ,
};

struct MPU9250Setting
{
    ACCEL_FS_SEL accel_fs_sel {ACCEL_FS_SEL::A16G};
    GYRO_FS_SEL gyro_fs_sel {GYRO_FS_SEL::G2000DPS};
    MAG_OUTPUT_BITS mag_output_bits {MAG_OUTPUT_BITS::M16BITS};
    FIFO_SAMPLE_RATE fifo_sample_rate {FIFO_SAMPLE_RATE::SMPL_200HZ};
    uint8_t gyro_fchoice {0x03};
    GYRO_DLPF_CFG gyro_dlpf_cfg {GYRO_DLPF_CFG::DLPF_41HZ};
    uint8_t accel_fchoice {0x01};
    ACCEL_DLPF_CFG accel_dlpf_cfg {ACCEL_DLPF_CFG::DLPF_45HZ};
};

struct CalibrationReq : SignalBase
{
    CalibrationReq() : SignalBase(CALIBRATION_REQ) {}
    float magneticDelication;
    MPU9250Setting mpuSettings;
};

struct ConfigurationReq : SignalBase
{
    ConfigurationReq() : SignalBase(CONFIGURATION_REQ) {}
    float magneticDelication;
    MPU9250Setting mpuSettings;
    Vector3D accelrBias;
    Vector3D gyroBias;
    Vector3D magBias;
    Vector3D magScale;
};

struct MeasurementInd : SignalBase
{
    MeasurementInd() : SignalBase(MEASUREMENT_IND) {} 
    float roll;
    float pitch;
    float yaw;
};

struct ConfigurationCfm : SignalBase
{
    ConfigurationCfm() : SignalBase(CONFIGURATION_CFM) {} 
    bool isValid;
};

struct CalibrationCfm : SignalBase
{
    CalibrationCfm() : SignalBase(CALIBRATION_CFM) {}
    bool isValid;
    Vector3D accelrBias;
    Vector3D gyroBias;
    Vector3D magBias;
    Vector3D magScale;
};

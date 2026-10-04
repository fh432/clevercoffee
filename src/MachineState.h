#pragma once

/**
 * Machine state enum used across the firmware
 */
enum MachineState {
    kInit = 0,
    kPidNormal = 20,
    kBrew = 30,
    kManualFlush = 35,
    kSteam = 40,
    kBackflush = 50,
    kWaterTankEmpty = 70,
    kEmergencyStop = 80,
    kPidDisabled = 90,
    kStandby = 95,
    kSensorError = 100,
    kEepromError = 110,
};

// Globals used by various modules
extern MachineState machineState;
extern MachineState lastmachinestate;
extern int lastmachinestatepid;

extern double temperature;
extern double setpoint;
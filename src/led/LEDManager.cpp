#include "led/LEDManager.h"
#include "Logger.h"
#include "MachineState.h" // global machine state and important variables
#include "userConfig.h"  // for FEATURE_STEAM_LED
#include <Adafruit_NeoPixel.h> // for NeoPixel LED by floh

// Access globals defined in main.cpp (declared in MachineState.h)
// (no duplicate definitions here)

#if FEATURE_NEOPIXEL_LED == 1
extern Adafruit_NeoPixel ring;
#ifndef NUMPIXELS
#define NUMPIXELS 12
#endif
#endif

#if FEATURE_NEOPIXEL_LED == 1
extern Adafruit_NeoPixel ring; // use global ring to color neo pixels
#endif

LEDManager::LEDManager(LED* status, LED* brew, LED* steam) :
    statusLed(status), brewLed(brew), steamLed(steam), lastToggle_(0), statusOn_(false) {
}

void LEDManager::tick() {
    unsigned long now = millis();

    // Update standard LEDs (checked every INTERVAL_MS)
    if (statusLed) {
        // Condition equivalent to previous logic: PID normal and temp close to setpoint
        bool shouldBeOn = ((machineState == kPidNormal && (fabs(temperature - setpoint) < 0.3)) || (temperature > 115 && fabs(temperature - setpoint) < 5));
        statusLed->setGPIOState(shouldBeOn);
    }

    if (brewLed) {
        brewLed->setGPIOState(machineState == kBrew);
    }

#if FEATURE_STEAM_LED
    if (steamLed) {
        steamLed->setGPIOState(machineState == kSteam);
    }
#endif
    // LOG(INFO, "floh: LEDManager::tick() executed");
#if FEATURE_NEOPIXEL_LED == 1
    // For NeoPixel ring we update colors based on machine state
    // Keep this reasonably cheap (just set colors and show)
    switch (machineState) {
        case kPidNormal: {
            const uint32_t GREEN = ring.Color(0, 255, 0);
            for (int i = 0; i < NUMPIXELS; ++i) ring.setPixelColor(i, GREEN);
            break;
        }
        case kPidDisabled: {
            const uint32_t GREEN_DIM = ring.Color(0, 51, 0); // 20% intensity green
            for (int i = 0; i < NUMPIXELS; ++i) ring.setPixelColor(i, GREEN_DIM);
            break;
        }
        case kInit:
        case kStandby: {
            const uint32_t BLUE = ring.Color(0, 0, 255);
            for (int i = 0; i < NUMPIXELS; ++i) ring.setPixelColor(i, BLUE);
            break;
        }
        case kBrew: {
            const uint32_t CYAN = ring.Color(0, 128, 128);
            for (int i = 0; i < NUMPIXELS; ++i) ring.setPixelColor(i, CYAN);
            break;
        }
        case kSteam: {
            const uint32_t ORANGE = ring.Color(255, 128, 0);
            for (int i = 0; i < NUMPIXELS; ++i) ring.setPixelColor(i, ORANGE);
            break;
        }
        case kBackflush: {
            const uint32_t PURPLE = ring.Color(128, 0, 255);
            for (int i = 0; i < NUMPIXELS; ++i) ring.setPixelColor(i, PURPLE);
            break;
        }
        case kEmergencyStop:
        case kSensorError:
        case kEepromError: {
            const uint32_t RED = ring.Color(255, 0, 0);
            for (int i = 0; i < NUMPIXELS; ++i) ring.setPixelColor(i, RED);
            break;
        }
        default: {
            const uint32_t WHITE_DIM = ring.Color(51, 51, 51); // 20% intensity white
            for (int i = 0; i < NUMPIXELS; ++i) ring.setPixelColor(i, WHITE_DIM);
            break;
        }
    }
    ring.show();
    // LOG(INFO, "floh: LEDManager::tick() ->  ring.show() executed");
#endif
}

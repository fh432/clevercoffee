#pragma once

#include "hardware/LED.h"
#include "utils/Timer.h"

class LEDManager {
public:
    /** Interval in ms for LED updates */
    static const unsigned int INTERVAL_MS = 400;

    LEDManager(LED* status, LED* brew, LED* steam);

    /** Called regularly by a software timer (non-blocking) */
    void tick();

private:
    LED* statusLed;
    LED* brewLed;
    LED* steamLed;

    unsigned long lastToggle_;
    bool statusOn_;
};
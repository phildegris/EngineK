#include "sensesp/signalk/signalk_output.h"

/**
1. Temperature Bus GPIO 17 (4 Sensors)
2. Engine High Temperature GPIO 26 (A0)
3. Engine Low Oil Pressure - VP 2003 GPIO 27 (A10)
4. Raw Water Intake Flow - VP 2003 GPIO 32 (A7)
5. Bilge Water Switch GPIO 33
6. Forward Hatch Open GPIO 14
7. Aft Hatch Open GPIO 15
8. Alternator Tach Pulse 21 
**/

// Huzzah32 feather pinouts
// https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/pinouts

const uint8_t GPIO_TEMPERATURE_BUS_PIN = 17; 
const uint8_t GPIO_ENGINE_HIGH_TEMP_SWITCH = 21;
const uint8_t GPIO_ENGINE_LOW_OIL_PRESSURE_SWITCH = 27; //(A10)
const uint8_t GPIO_ENGINE_RAW_WATER_INTAKE_FLOW_SWITCH = 32; //(A7)
const uint8_t GPIO_ENGINE_BILGE_WATER_SWITCH = 33;
const uint8_t GPIO_ENGINE_FORWARD_HATCH_SWITCH = 14;
const uint8_t GPIO_ENGINE_AFT_HATCH_SWITCH = 15;

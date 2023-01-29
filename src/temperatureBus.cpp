// ** TEMPERATURES **
// All temps reported in Kelvin
// Compartment Temp ->  /vessels/<RegExp>/environment/inside/engineRoom/temperature 
// Exhaust Temp -> /vessels/<RegExp>/propulsion/mainEngine/exhaustTemperature
// Cylinder Head Temp -> /vessels/<RegExp>/propulsion/main/temperature
// Alternator Temperature -> /vessels/<RegExp>/electrical/alternators/12V/temperature

#include "sensesp/signalk/signalk_output.h"
#include "sensesp/transforms/linear.h"
#include "sensesp_onewire/onewire_temperature.h"

#include "engineK.h"
#include "temperatureBus.h"

using namespace sensesp;

void configureBusses(){

   configureBus(GPIO_TEMPERATURE_BUS_PIN);

}

/// @brief 
/// @param pin 
void configureBus(uint8_t pin){


    Serial.printf("Configuring OneWire Bus on Pin %i", pin);

    DallasTemperatureSensors* dts = new DallasTemperatureSensors(pin);

    uint read_delay = 500;

    // Below are temperatures sampled and sent to Signal K server
    // To find valid Signal K Paths that fits your need you look at this link:
    // https://signalk.org/specification/1.4.0/doc/vesselsBranch.html

    // Measure compartment temperature
    auto* compartment_temp =
        new OneWireTemperature(dts, read_delay, "/compartmentTemperature/oneWire");

    compartment_temp->connect_to(new Linear(1.0, 0.0, "/compartmentTemperature/linear"))
        ->connect_to(new SKOutputFloat("environment.inside.engineRoom.temperature",
                                        "/compartmentTemperature/skPath"));

    // Measure exhaust temperature
    auto* exhaust_temp =
        new OneWireTemperature(dts, read_delay, "/exhaustTemperature/oneWire");

    exhaust_temp->connect_to(new Linear(1.0, 0.0, "/exhaustTemperature/linear"))
        ->connect_to(new SKOutputFloat("propulsion.mainEngine.exhaustTemperature",
                                        "/exhaustTemperature/skPath"));

    // Measure cylinder head temperature
    auto* cylinderHead_temp =
        new OneWireTemperature(dts, read_delay, "/cylinderHeadTemperature/oneWire");

    cylinderHead_temp->connect_to(new Linear(1.0, 0.0, "/cylinderHeadTemperature/linear"))
        ->connect_to(new SKOutputFloat("propulsion.mainEngine.cylinderHeadTemperature",
                                        "/cylinderHeadTemperature/skPath"));
    
    //Measure temperature of 12v alternator
    auto* alt_12v_temp =
        new OneWireTemperature(dts, read_delay, "/12vAltTemperature/oneWire");

    alt_12v_temp->connect_to(new Linear(1.0, 0.0, "/12vAltTemperature/linear"))
        ->connect_to(new SKOutputFloat("electrical.alternators.12V.temperature",
                                       "/12vAltTemperature/skPath"));
}
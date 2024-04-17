#include "switches.h"
#include "sensesp/sensors/digital_input.h"
#include "sensesp/signalk/signalk_value_listener.h"

#include "engineK.h"

using namespace sensesp;

void configure_switches(){

    configure_switch(
        GPIO_ENGINE_HIGH_TEMP_SWITCH,
        "propulsion.mainEngine.switches.highTemperature",
        "Engine Temperature Warning Switch",
        "This value represents the state of the engines high temperature warning switch. When true, the switch is closed, when open, false."
    );
  
    configure_switch(
        GPIO_ENGINE_LOW_OIL_PRESSURE_SWITCH,
        "propulsion.mainEngine.switches.lowOilPressure",
        "Low Oil Pressure Warning Switch",
        "This value represents the state of the engines oil pressure warning switch. When true, the switch is closed, when open, false."
    );

    configure_switch(
        GPIO_ENGINE_RAW_WATER_INTAKE_FLOW_SWITCH,
        "propulsion.mainEngine.switches.rawWaterIntakeFlow",
        "Raw water intake flow switch",
        "This value represents the state of the raw water intake flow switch. When true, the switch is closed, when open, false."
    );

    configure_switch(
        GPIO_ENGINE_FORWARD_HATCH_SWITCH,
        "propulsion.mainEngine.switches.forwardHatch",
        "Engine bay forward hatch switch",
        "This value represents the state of the engine bay forward hatch switch. When true, the switch is closed, when open, false."
    );

    configure_switch(
        GPIO_ENGINE_AFT_HATCH_SWITCH,
        "propulsion.mainEngine.switches.aftHatch",
        "Engine bay aft hatch switch",
        "This value represents the state of the engine bay aft hatch switch. When true, the switch is closed, when open, false."
    );

     configure_switch(
        GPIO_ENGINE_BILGE_WATER_SWITCH,
        "propulsion.mainEngine.switches.bilgeWater",
        "Engine bay aft hatch switch",
        "This value represents the state of the engine bay aft hatch switch. When true, the switch is closed, when open, false."
    );

}

void configure_switch(uint8_t pin, String signalK_path, String display_name, String description){

  auto* sw = new DigitalInputChange(pin, INPUT_PULLDOWN, CHANGE, "");
  sw
  ->connect_to(new SKOutputBool(
      signalK_path,                 // Signal K path
      "",                           // no configuration for switcheds
      new SKMetadata("",            // No units for boolean values
                     display_name,
                     description
                     ) 
      ));
}
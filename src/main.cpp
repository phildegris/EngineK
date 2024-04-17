// boat-toys:engine-monitor
// 
// This application provides a boat toys sensor node for monitoring
// a single diesel engine, a single alternator and the engine compartment  .
// Changes in readings are reported to an automaitcally discovered SignalK server 

// ** ENGINE WARNINGS **
// Low Oil Pressure -> 
// High Engine Temp ->
// Cooling Water Flow ->

// ** PERFORMANCE **
// Engine RPM -> /vessels/<RegExp>/propulsion/main/revolutions (Hz)
// Engine State -> /vessels/<RegExp>/propulsion/main/state
// Running Time 

// ** ALTERNATOR **
// Alternator Name /vessels/<RegExp>/electrical/alternators/main/name =="Main Alternator"
// Alternator Voltage -> /vessels/<RegExp>/electrical/alternators/main/voltage
// Alternator RPM -> /vessels/<RegExp>/electrical/alternators/main/revolutions (Hz)
// Pulley Ratio -> /vessels/<RegExp>/electrical/alternators/main/pulleyRatio (Hz)

#include "sensesp/transforms/linear.h"
#include "sensesp_app_builder.h"
#include "temperatureBus.h"
#include "switches.h"

using namespace sensesp;  

reactesp::ReactESP app;

// The setup function performs one-time application initialization.
void setup() {
#ifndef SERIAL_DEBUG_DISABLED
  SetupSerialDebug(115200);
#endif

  // Construct the global SensESPApp() object
  SensESPAppBuilder builder;
  sensesp_app = (&builder)
                    // Set a custom hostname for the app.
                    ->set_hostname("boat-toys:engine-monitor")
                    // Optionally, hard-code the WiFi and Signal K server
                    // settings. This is normally not needed.
                    ->set_wifi("RockHouse", "C0mmand0")
                    //->set_sk_server("192.168.10.3", 80)
                    ->get_app();
                    
  configure_busses();
  configure_switches();

  sensesp_app->start();


}


void loop() { app.tick(); }

# EngineK: a boat toys producer node

This project produces engine related SignalK events and measurements. It is built using the SensESP framework [SensESP documentation site](https://signalk.org/SensESP/).

## Part of a Boat Toys Network

### Binary Sensors (Switches on 12v Circuits)

- Engine High Temperature
- Engine Low Oil Pressure
- Raw Water Intake Flow
- Bilge Water Switch
- Forward Hatch Open
- Aft Hatch Open
- Alternator Tach Pulse

### One Wire Temperature Sensors

- Engine Bay Ambient Temperature
- Alternator Temperature
- Exhaust Temperature
- Cylinder Head Temperature

### Analog sensors
- Alternator RPM 
- Alternator Output Current

## Connections to Node

The node will require a connector which supports at least 12 separate pins

DC connections +ve 12-14v
Ground  

8 Connections to Input headers
OneWire Bus
1. Temperature Bus GPIO 25 (A1) (4 Sensors)

12v Switch Sources
2. Engine High Temperature GPIO 26 (A0)
3. Engine Low Oil Pressure - VP 2003 GPIO 27 (A10)
4. Raw Water Intake Flow - VP 2003 GPIO 32
5. Bilge Water Switch GPIO 33
6. Forward Hatch Open GPIO 14
7. Aft Hatch Open GPIO 15

Alternator W Terminal
8. Alternator Tach Pulse 21 

1. Connections to Analog Input Headers
2. Alternator Output Current A4 (GPIO36)
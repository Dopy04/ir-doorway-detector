# Infrared Passage Detection — ESP32-S3

**Personal electronics project · In progress · ESP32-S3 · IR LED / phototransistor · Analog measurement**

This project investigates detecting a person or object crossing an infrared light path. It uses an infrared emitter and an analog receiver with an ESP32-S3 to compare the received signal under different illumination conditions.

**Current status:** The optical receiver has been bench-tested under lamp light, normal room lighting and darkness. In these initial tests, the differential ADC readings for the clear and blocked beam do not overlap. Detection of fast crossings, long-term reliability, installation in a doorway, Wi-Fi alerts and the final PCB have not yet been validated.

## Current implementation

The [firmware](firmware/ir-doorway-detector/src/main.cpp) drives the IR emitter using **GPIO 4** and samples the receiver with the ESP32-S3's **12-bit ADC on GPIO 5**. For each measurement it:

1. Turns the emitter off, waits 200 ms and averages 10 ADC readings.
2. Turns the emitter on, waits 200 ms and averages another 10 readings.
3. Prints the two averages and their difference to the serial monitor at **115200 baud**.

The difference is calculated as `ADC(IR off) - ADC(IR on)`. Its sign and magnitude depend on the receiver circuit and the lighting conditions; two hysteresis thresholds (1500 for blocked, 2500 for clear) are proposed from recorded data, but are not yet implemented or validated in the current firmware.

## Files and tools

- [Firmware source — main.cpp](firmware/ir-doorway-detector/src/main.cpp)
- [PlatformIO project configuration](firmware/ir-doorway-detector/platformio.ini)
- [IR sensor validation report — 19 November 2026 (LaTeX, Spanish)](docs/informe_validacion_sensor_ir.tex)
- [Circuit schematics and calculations (LaTeX, Spanish)](docs/circuitos_y_calculos.tex)
- [Experiment log and troubleshooting (LaTeX, Spanish)](docs/registro_de_avances.tex)
- [Recorded measurements](tests/medidas.md)
- [How to compile the LaTeX reports](docs/COMPILACION.md)
- [ESP32-S3 datasheets](docs/)
- [Earlier firmware experiments](firmware/ir-doorway-detector/examples/)
- **Tools:** VS Code, PlatformIO, Arduino framework, multimeter and ESP32 ADC

## Reproducing the current measurement

1. Open `firmware/ir-doorway-detector` in VS Code with PlatformIO.
2. Verify the emitter and receiver wiring and current limiting before powering the circuit.
3. Build and upload to an ESP32-S3 DevKitC-1.
4. Open the serial monitor at 115200 baud.
5. Compare readings with the emitter off/on, with the heads facing each other; block the beam and observe the differential ADC values.

**Important:** The repository does not yet include a verified final schematic. Do not infer wiring solely from the GPIO assignments.

## Initial optical results (19 November 2026)

All results below are ranges of the differential 12-bit ADC value `ADC(IR off) - ADC(IR on)`, not voltages. The full report is in [LaTeX](docs/informe_validacion_sensor_ir.tex).

| Lighting | Clear beam | Blocked beam |
|---|---:|---:|
| Lamp | 3378–3385 | 323–638 |
| Indoor ambient light | 3917–3924 | 391–604 |
| Darkness | 3913–3916 | 319–739 |

The overall conservative gap across the recorded conditions is 2639 ADC counts (3378−739). The reported results cover an initial bench test only; sample counts, crossing speeds and long-term error rates were not recorded. The current measurement cycle takes about 1.6 seconds, so short interruptions may be missed.

## Testing and next steps

- Implement hysteresis-based state detection and shorten the acquisition cycle.
- Measure distance, alignment tolerance and performance in direct sunlight.
- Test actual crossings, including speed and false detection rate over time.
- Add mobile notifications; select the bare microcontroller and design/validate the PCB.

## What I am learning

Analog signal acquisition, sensor behavior, electrical measurements, C++ firmware and systematic debugging. Results and limitations will be documented as the prototype develops.

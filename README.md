# Infrared Passage Detection — ESP32-S3

**Personal electronics project · In progress · ESP32-S3 · IR LED / phototransistor · Analog measurement**

This project investigates detecting a person or object crossing an infrared light path. It uses an infrared emitter and an analog receiver with an ESP32-S3 to compare the received signal under different illumination conditions.

**Current status:** A working measurement program is available, but the optical-barrier setup, range, false-detection rate and final PCB have not yet been validated. This is a prototype, not a finished security device.

## Current implementation

The [firmware](firmware/ir-doorway-detector/src/main.cpp) drives the IR emitter using **GPIO 4** and samples the receiver with the ESP32-S3's **12-bit ADC on GPIO 5**. For each measurement it:

1. Turns the emitter off, waits 200 ms and averages 10 ADC readings.
2. Turns the emitter on, waits 200 ms and averages another 10 readings.
3. Prints the two averages and their difference to the serial monitor at **115200 baud**.

The difference is calculated as `ADC(IR off) - ADC(IR on)`. Its sign and magnitude depend on the receiver circuit and the lighting conditions; it is not yet a validated detection threshold.

## Files and tools

- [Firmware source — main.cpp](firmware/ir-doorway-detector/src/main.cpp)
- [PlatformIO project configuration](firmware/ir-doorway-detector/platformio.ini)
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
5. Compare readings with the emitter off/on; then repeat with the components correctly aligned and an opaque object in the light path.

**Important:** The repository does not yet include a verified final schematic. Do not infer wiring solely from the GPIO assignments.

## Testing and next steps

- Repeat measurements with the emitter and receiver facing each other.
- Compare ambient light and IR-illuminated ADC values.
- Check sensitivity to distance, room lighting and occlusion.
- Establish a threshold using recorded measurements and test false triggers.
- Finish and validate the optical measurements; design and validate the PCB.

## What I am learning

Analog signal acquisition, sensor behavior, electrical measurements, C++ firmware and systematic debugging. Results and limitations will be documented as the prototype develops.

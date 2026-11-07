# Motorized Cake Decorating Turntable

An ESP32-based motorized turntable designed to make cake decorating more precise, consistent, and convenient.

The project aims to combine programmable rotational speed, smooth motor control, and a custom-built mechanical enclosure into a compact, aesthetically pleasing machine.

**Status:** Under active development

## Project Goals

The goal is to build a reliable motorized turntable suitable for small bakery and cake-decorating applications.

Planned capabilities include:

- Adjustable rotational speed from 1–100 RPM.
- Clockwise and anticlockwise rotation.
- Rotary encoder for speed selection.
- Push-button start/stop control.
- OLED display for speed and operating status.
- Closed-loop speed regulation using a Hall-effect sensor.
- Smooth, low-vibration operation under load.
- Physical emergency stop.
- Manual operation through a mechanical drive disengagement mechanism.
- Custom-designed plywood enclosure and removable food-contact platter.

## Hardware

The project uses an ESP32 microcontroller as its central controller.

| Component | Purpose |
|---|---|
| ESP32 DevKit V1 | Main controller |
| EC11 rotary encoder | Speed selection and user input |
| SSD1306 OLED (128×64) | User interface |
| TMC2209 stepper driver | Stepper motor control |
| Bipolar stepper motor | Rotational drive |
| A3144 Hall-effect sensor | Rotational speed feedback |
| 24V DC power supply | Main motor power |
| Buck converter | Regulated 5V supply for control electronics |

*Some components are planned for later integration and have not yet been implemented.*

## Firmware

The firmware is being developed using **ESP-IDF 6.1** in C.

Development environment:
- ESP32 DevKit V1
- ESP-IDF
- C programming language
- FreeRTOS
- Visual Studio Code alternative: Zed Editor
- Debian on WSL2

### Current Development Progress

- [x] ESP-IDF installation and project setup.
- [x] GPIO output control.
- [x] LED blinking using FreeRTOS delays.
- [x] Push-button input using internal pull-up resistors.
- [x] Software debouncing using elapsed-time measurement.
- [x] Button-controlled LED toggle.
- [x] Rotary encoder GPIO configuration.
- [x] Quadrature encoder state detection.
- [x] Direction detection using a 4×4 lookup table.
- [x] Encoder transition counting.
- [x] RPM selection logic using encoder detents.
- [x] Target RPM boundaries (0–100).

### Upcoming Development

- [ ] Encoder push-button start/stop functionality.
- [ ] SSD1306 OLED integration.
- [ ] Stepper motor and TMC2209 integration.
- [ ] Stepper motor speed control.
- [ ] Hall-effect sensor integration.
- [ ] Closed-loop RPM regulation.
- [ ] Emergency stop implementation.
- [ ] Mechanical drive disengagement.
- [ ] Final firmware and hardware integration.

## Mechanical Design

The mechanical assembly is planned around a large rotating platter supported by a suitable bearing and driven through a timing-belt transmission.

Design priorities include:

- Stable support for cakes weighing approximately 10 kg.
- Minimal platter wobble and rotational runout.
- Low vibration at slow rotational speeds.
- Adjustable belt tension.
- Mechanical disengagement for manual operation.
- Removable, food-safe platter.
- An elegant enclosure inspired by premium audio turntables.

CAD models, 3D-printed components, and plywood enclosure designs will be added as development progresses.

## Safety Considerations

Safety is an important part of the design.

Planned provisions include:

- A physical emergency stop that independently interrupts motor power.
- Appropriate electrical protection and fusing.
- Separation of food-contact surfaces from the wooden enclosure.
- Secure mounting of rotating mechanical components.
- Testing under progressively increasing loads before regular use.

## Project Structure

```text
motorized-turntable/
├── firmware/       # ESP32 firmware
├── electronics/    # Circuit diagrams and wiring
├── mechanical/     # CAD and fabrication files
├── docs/           # Architecture and development notes
└── README.md
```

The repository will evolve as the project progresses.

## Learning and Development

This project is also an opportunity to explore embedded systems and mechanical design through practical implementation.

Key learning areas include:

- Embedded C and ESP-IDF.
- GPIO, digital inputs, and hardware interfaces.
- Rotary encoder quadrature decoding.
- FreeRTOS task scheduling.
- Stepper motor control and driver configuration.
- Sensor feedback and closed-loop control.
- CAD and 3D printing.
- Mechanical transmission design.
- Fabrication and enclosure construction.

## License

To be determined.

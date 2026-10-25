# ESP32 GPIO Practice — ESP-IDF

A hands-on learning project exploring GPIO programming on the ESP32 using the ESP-IDF framework and C. This repository develops the fundamentals needed for a future motorized turntable controller.

## Learning Progress

### 1. LED Blinker

- Configure a GPIO pin as an output.
- Control an LED using `gpio_set_level()`.
- Introduce timing and delays with FreeRTOS.
- Understand the ESP-IDF build, flash, and monitor workflow.

### 2. Push Button Input

- Configure a GPIO pin as an input.
- Use the ESP32's internal pull-up resistor.
- Read button states using `gpio_get_level()`.
- Understand active-low logic: the button reads LOW when pressed and HIGH when released.

### 3. Software Debouncing

- Understand why mechanical switches can produce multiple transitions during a single press.
- Use `esp_timer_get_time()` to measure elapsed time in microseconds.
- Accept a new button state only after it remains unchanged for a defined debounce interval.

### 4. Button-Controlled LED Toggle

- Use the debounced button state to detect a press.
- Maintain the LED state in a variable.
- Toggle the LED ON or OFF once per confirmed press.

## Hardware

- ESP32 development board
- Breadboard and jumper wires
- LED
- 330 Ω current-limiting resistor
- Momentary push button

## Wiring

### LED — GPIO18

Connect GPIO18 to a 330 Ω resistor, then to the LED's anode (long leg). Connect the LED's cathode (short leg) to GND.

### Push Button — GPIO19

Connect the push button between GPIO19 and GND. The program enables the internal pull-up resistor, so an external pull-up resistor is not required.

| Component     | ESP32 connection |
| ------------- | ---------------- |
| LED control   | GPIO18           |
| Button input  | GPIO19           |
| LED return    | GND              |
| Button return | GND              |

## Software Requirements

- ESP-IDF
- ESP32 toolchain and build tools installed through ESP-IDF
- USB data cable compatible with the development board

## Build, Flash, and Monitor

Open a terminal in the project root and activate your ESP-IDF environment if it is not already active.

Set the target for a standard ESP32:

```bash
idf.py set-target esp32
```

Build the firmware:

```bash
idf.py build
```

Flash the firmware to the connected board (replace the port if necessary):

```bash
idf.py -p /dev/ttyUSB0 flash
```

Open the serial monitor:

```bash
idf.py -p /dev/ttyUSB0 monitor
```

Use `Ctrl+]` to exit the ESP-IDF monitor.

## Concepts Practiced

- C functions, variables, and conditional statements
- GPIO input and output configuration
- Digital HIGH and LOW states
- Internal pull-up resistors
- FreeRTOS task delays
- Elapsed-time measurement
- Mechanical switch debouncing
- State tracking and toggle logic
- ESP-IDF component dependencies and CMake configuration
- Compiling, flashing, and debugging embedded firmware

## Project Goal

This project is part of a learning journey toward building a programmable motorized turntable. The next stages will introduce motor drivers, stepper motor control, speed measurement, and user-interface components.

## Safety

Disconnect USB power before changing breadboard wiring. Always use a suitable series resistor with a bare LED, and never connect a motor directly to an ESP32 GPIO pin.

## License

Add a license if you intend to grant others permission to reuse, modify, and distribute this project.

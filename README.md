# ESP32 LED Blinker (ESP-IDF)

A beginner-friendly ESP-IDF project that blinks an external LED using an ESP32 GPIO pin. It is a small hands-on exercise in embedded C, GPIO outputs, delays, serial logging, and the ESP-IDF build/flash workflow.

## Features

- Prints a startup message to the serial monitor.
- Configures GPIO18 as a digital output.
- Blinks an external LED with approximately one second ON and one second OFF.
- Prints a message after each blink cycle.

This is a learning project and is not the final firmware for a motorized turntable.

## Hardware required

- ESP32 development board compatible with the ESP-IDF `esp32` target
- USB data cable
- Breadboard and jumper wires
- One LED (a standard red LED is suitable)
- 330 Ω series resistor

## Wiring

Disconnect USB power before changing the wiring.

1. Connect ESP32 GPIO18 to one end of the 330 Ω resistor.
2. Connect the other end of the resistor to the LED anode (usually the longer leg).
3. Connect the LED cathode (usually the shorter leg) to an ESP32 GND pin.

The resistor and LED can be swapped in order as long as they remain in the same series path. Ensure the LED legs are in separate electrically connected breadboard rows. Do not connect an LED directly between GPIO18 and GND without a current-limiting resistor.

## Software prerequisites

- ESP-IDF installed and configured for the ESP32 target
- Git (optional, for version control)
- A serial terminal or the ESP-IDF monitor

Follow Espressif's official ESP-IDF installation guide for your operating system:
<https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/>

These instructions assume the ESP-IDF command `idf.py` is available in your terminal. Commands should be run from the project root, where the top-level `CMakeLists.txt` is located—not from inside `main/`.

## Build, flash, and monitor

### 1. Configure the target

Run this once for a fresh project configuration:

```bash
idf.py set-target esp32
```

### 2. Build

```bash
idf.py build
```

### 3. Flash the firmware

Replace `/dev/ttyUSB0` with the serial port for your board if it differs. On Windows, a COM port may be used instead; see the ESP-IDF documentation for the appropriate port syntax.

```bash
idf.py -p /dev/ttyUSB0 flash
```

### 4. Open the serial monitor

```bash
idf.py -p /dev/ttyUSB0 monitor
```

Exit the monitor with `Ctrl+]`.

### The difference between build, flash, and monitor

- **Build** compiles and links the source code into firmware artifacts.
- **Flash** writes the firmware to the ESP32.
- **Monitor** displays serial output; it does not compile or upload source changes.

After editing the code, build and flash again before expecting the new firmware to run.

## Project structure

```text
.
├── CMakeLists.txt
├── README.md
├── main/
│   ├── CMakeLists.txt
│   └── blinker.c
└── sdkconfig
```

ESP-IDF also generates a `build/` directory during compilation. It contains generated output and normally should not be committed to Git.

### Component registration

The `main/CMakeLists.txt` file should register the actual source filename and declare the GPIO driver dependency. For this project, it should be equivalent to:

```cmake
idf_component_register(
    SRCS "blinker.c"
    INCLUDE_DIRS "."
    PRIV_REQUIRES esp_driver_gpio
)
```

If your source file has a different name, update `SRCS` to match it.

## Uploading the project to GitHub

1. Create a new repository at <https://github.com/new>. Choose a repository name such as `esp32-led-blinker`.
2. For a straightforward first push, create the remote repository without initializing it with a README, `.gitignore`, or license.
3. In a terminal, change directory to this project's root.
4. Add a `.gitignore` file:

   ```gitignore
   build/
   managed_components/
   .vscode/
   .idea/
   .DS_Store
   Thumbs.db
   *.log
   ```

5. Initialize Git and review the files before committing:

   ```bash
   git init
   git add .
   git status
   git commit -m "Add ESP32 LED blinker"
   ```

6. Set the branch name and add the URL of the repository you created. Replace the example URL with your own:

   ```bash
   git branch -M main
   git remote add origin https://github.com/YOUR-USERNAME/esp32-led-blinker.git
   git push -u origin main
   ```

7. Follow GitHub's authentication prompts if asked. Do not put passwords or access tokens into source files or repository URLs.

If `origin` already exists, inspect it with `git remote -v` instead of adding it again.

For future changes:

```bash
git status
git add main/blinker.c README.md
git commit -m "Describe your change"
git push
```

Review `git status` before each commit. Add other changed files intentionally as needed.

## Troubleshooting

- **`idf.py: command not found`:** ESP-IDF may not be activated in the current terminal. Follow the official installation guide for your operating system.
- **CMake cannot find a source file:** Confirm the filename in `main/CMakeLists.txt` matches the actual file in `main/`.
- **`driver/gpio.h` cannot be found:** Check the GPIO driver dependency in `main/CMakeLists.txt`. ESP-IDF component names and requirements can vary by ESP-IDF version.
- **Serial port not found:** Check the USB cable, board connection, operating-system device list, and port permissions.
- **LED does not blink:** Disconnect power and check LED polarity, the series resistor, the GND connection, the selected GPIO, and the build/flash steps.

## What this project teaches

- How `app_main()` serves as the ESP-IDF application entry point
- How to configure a GPIO as an output
- How to drive a pin HIGH and LOW
- How to use `vTaskDelay(pdMS_TO_TICKS(1000))` for a one-second delay
- How to distinguish source-code, build, flashing, wiring, and measurement issues

Contributions and beginner-friendly improvements are welcome.

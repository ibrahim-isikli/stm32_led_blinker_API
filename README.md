# stm32_led_blinker_API

A small, lightweight C API for blinking and controlling LEDs on STM32 microcontrollers.  
This repository provides an easy-to-use interface to initialize GPIOs, toggle LEDs, and create simple blink patterns suitable for quick demos, tests, or learning STM32 GPIO programming.

## Features
- Simple initialization for LED GPIO pins
- Turn LEDs on/off and toggle
- Configurable blink with period and duty cycle
- Small footprint suitable for STM32CubeIDE/STM32CubeMX projects

## Supported targets
- STM32 (Cortex-M) microcontrollers — adapt GPIO port/pin definitions per board
- Tested with (example): STM32F1 / STM32F4 (update this list with your tested MCUs)

## Repository structure
- src/ — implementation files
- include/ — public headers (API)
- examples/ — example projects or minimal demo usage
- docs/ — optional documentation or usage notes
- README.md — this file

(Adjust the paths above to match the actual layout in the repo.)

## Prerequisites
- STM32 toolchain (ARM GCC toolchain or STM32CubeIDE)
- STM32 HAL (if your implementation depends on STM32Cube HAL)
- Basic knowledge of configuring clocks and GPIOs for your target MCU

## Installation / Integration
1. Add the `src/` and `include/` folders to your STM32 project.
2. Include the public header in your application:
   ```c
   #include "stm32_led_blinker.h" // replace with actual header name
   ```
3. Ensure your project's clock and HAL are initialized before calling API functions.

## Usage example
The exact function names below are illustrative — replace them with the real API names from `include/`:

```c
// Initialize the LED library (configure HAL, clocks and pass any context if needed)
stm32_led_blinker_init();

// Configure an LED (example)
led_handle_t led = led_configure(GPIOB, GPIO_PIN_0); // GPIO port/pin example

// Turn LED on
led_on(led);

// Turn LED off
led_off(led);

// Blink LED with 500ms period (example)
led_blink(led, 500); // period in ms
```

If your implementation uses HAL types directly, show exact prototypes from your header here for clarity.

## Example project
Include a minimal example under `examples/` showing:
- CubeMX project or .ioc file (optional)
- main.c that initializes HAL, board clocks, and runs an LED blink demo

## API documentation
Add a brief section listing the public functions in your header:
- stm32_led_blinker_init() — initialize library
- led_configure(port, pin) — register an LED pin
- led_on(handle)
- led_off(handle)
- led_toggle(handle)
- led_blink(handle, period_ms, duty_cycle) — start blinking (if supported)
(Replace with actual names and full prototypes.)

## Contributing
Contributions, bug reports, and pull requests are welcome. Please:
1. Open an issue describing the problem or feature.
2. Create a branch, make changes, and submit a pull request.
3. Follow any existing coding style and include build/test instructions.

## License
Specify your license here (e.g., MIT, Apache-2.0). If you don't have one yet, consider adding an MIT license for permissive reuse.

## Contact
Created by Ibrahim Isikli — feel free to open issues or reach out via GitHub.

---

If you'd like, I can:
- Update this README.md in the repository directly (commit the file).
- Add an example main.c under `examples/`.
- Generate a CONTRIBUTING.md or LICENSE file.

Tell me which changes you want me to push and I'll apply them.                                                                              

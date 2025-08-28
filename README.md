# Intel Decimal Floating-Point Library for Raspberry Pi Pico

This project demonstrates the use of Intel's Decimal Floating-Point (BID) library on the Raspberry Pi Pico 2 microcontroller.

## Features

- Intel BID library integration for precise decimal arithmetic
- Support for 128-bit decimal floating-point operations
- Mathematical functions (trigonometric, logarithmic, exponential, etc.)
- Optimized for Raspberry Pi Pico 2 (RP2350)

## Building

1. Ensure you have the Pico SDK installed
2. Clone this repository
3. Build using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
Note: The project includes the Intel Decimal Floating-Point Math Library as a precompiled static library (`gcc111libbid_pico2.a`) and modified header files for compatibility with the Pico platform. See this [repository](https://github.com/ice458/Intel_RDFP_Library_Builder_for_RPi_Pico2) for details on how the library was built.

## Usage
Please import this project using the Raspberry Pi Pico extension in Visual Studio Code.  
The example code in `intel_decimal.c` demonstrates various decimal floating-point operations including:

- Basic arithmetic (addition, subtraction, multiplication, division)
- Trigonometric functions (sin, cos, tan, asin, acos, atan)
- Logarithmic and exponential functions
- Hyperbolic functions
- Comparison operations

## License

This project is licensed under the BSD 3-Clause License - see the [LICENSE](LICENSE) file for details.

### Third-Party Components

- **Intel BID Library**: Copyright (c) 2007-2011, Intel Corp. Licensed under BSD 3-Clause License.
- **Modified headers** (`bid_conf.h`, `bid_functions.h`): Based on Intel BID library headers with modifications for Pico compatibility.

## Dependencies

- Raspberry Pi Pico SDK
- Intel Decimal Floating-Point Library (included as `gcc111libbid_pico2.a`)

## Hardware Requirements

- Raspberry Pi Pico 2 (RP2350)
- USB connection for output


# Intel Decimal Floating-Point Math Library for Raspberry Pi Pico2

This project demonstrates the use of Intel's Decimal Floating-Point Math Library on the Raspberry Pi Pico 2 microcontroller.

## Features

- Intel Decimal Floating-Point Math Library integration for precise decimal arithmetic
- Support for 128-bit decimal floating-point operations
- Mathematical functions (trigonometric, logarithmic, exponential, etc.)
- Optimized for Raspberry Pi Pico 2 (RP2350)

## Building

1. Ensure you have the Pico SDK installed
2. Clone this repository
3. Recommended: build and flash via the Raspberry Pi Pico VS Code extension tasks:
   - "Compile Project"
   - "Run Project" (UF2 load)
   - "Flash" (OpenOCD)
   - Rescue/Reset tasks as needed
4. CLI alternative (generic CMake/Ninja flow):
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

- Project code in this repository is under the BSD 3-Clause License. See [LICENSE](LICENSE).
- Third-party licenses are documented in [THIRD_PARTY_LICENSES.md](THIRD_PARTY_LICENSES.md).
- A verbatim copy of Intel's EULA distributed with IntelRDFPMathLib v2.2 is included at `licenses/vendor-intel-dfp-eula.txt` for convenience. Note: the original `IntelRDFPMathLib20U2/eula.txt` is ignored by `.gitignore` and is therefore not committed.

### Third-Party Components

- Intel Decimal Floating-Point Math Library: BSD 3-Clause (see `licenses/vendor-intel-dfp-eula.txt`).
- Modified headers (`bid_conf.h`, `bid_functions.h`): Derived from Intel's headers with Pico compatibility tweaks, retaining the original license header.

## Dependencies

- Raspberry Pi Pico SDK
- Intel Decimal Floating-Point Math Library (included as `gcc111libbid_pico2.a`)

## Hardware Requirements

- Raspberry Pi Pico 2 (RP2350)
- USB connection for output


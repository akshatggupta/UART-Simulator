# UART Communication Simulator

A modular, multithreaded UART (Universal Asynchronous Receiver Transmitter) communication simulator written in modern C++.

This project emulates asynchronous serial communication between virtual embedded devices, including UART frame generation, bit-level transmission, baud-rate timing, communication noise, packet corruption, and real-time transmission statistics.

Designed as a systems-level educational and engineering project inspired by real embedded firmware architectures.

---

# Features

- UART frame generation
- Start and stop bit simulation
- Bit-by-bit serial transmission
- Configurable baud rates
- Virtual serial communication channel
- Multithreaded TX/RX communication
- Communication noise simulation
- Random bit corruption
- Packet drop simulation
- Frame transmission statistics
- Modular architecture
- CMake-based build system

---

# Architecture

```text
+----------------+
|   Device A     |
+----------------+
        |
        v
+----------------+
| UART TX Module |
+----------------+
        |
        v
+----------------+
| Serial Channel |
| (Noise/Errors) |
+----------------+
        |
        v
+----------------+
| UART RX Module |
+----------------+
        |
        v
+----------------+
|   Device B     |
+----------------+
```

---

# Project Structure

```text
UART/
│
├── include/
│   ├── Channel.h
│   ├── Device.h
│   ├── Statistics.h
│   ├── UART.h
│   └── UARTFrame.h
│
├── src/
│   ├── Channel.cpp
│   ├── Device.cpp
│   ├── Statistics.cpp
│   ├── UART.cpp
│   ├── UARTFrame.cpp
│   └── main.cpp
│
├── build/
│
├── CMakeLists.txt
├── .gitignore
└── README.md
```

---

# UART Frame Format

Each transmitted character is converted into a UART frame.

```text
| Start Bit | Data Bits | Stop Bit |
```

Example:

```text
Character: 'A'
ASCII    : 65
Binary   : 01000001
Frame    : 0 10000010 1
```

- Start bit = `0`
- Data bits transmitted LSB-first
- Stop bit = `1`

---

# Build Instructions

## Requirements

- C++17
- CMake >= 3.10
- GNU Make
- g++

---

## Linux / WSL

Clone repository:

```bash
git clone https://github.com/your-username/UART.git
cd UART
```

Create build directory:

```bash
mkdir build
cd build
```

Generate build files:

```bash
cmake ..
```

Compile:

```bash
make
```

Run:

```bash
./uart_simulator
```

---

# Example Output

```text
====================================
 UART COMMUNICATION SIMULATOR
====================================

Enter message: HELLO

========== DEVICE A TRANSMITTING ==========

[TX] Sending Character: H
[TX] Bit Sent: 0
[TX] Bit Sent: 1

========== DEVICE B RECEIVING ==========

[RX] Start Bit Detected
[RX] Bit Received: 1

========== UART STATISTICS ==========
Frames Sent      : 5
Frames Received  : 5
Corrupted Frames : 1
Dropped Frames   : 0
```

---

# Communication Error Simulation

The simulator supports probabilistic communication faults:

| Error Type | Description |
|---|---|
| Bit Corruption | Random bit flips during transmission |
| Packet Drop | Randomly dropped bits/frames |
| Noise Injection | Simulated unstable communication channel |

---

# Technologies Used

- Modern C++17
- STL Containers
- Multithreading
- Mutexes
- Condition Variables
- CMake
- GNU Make

---

# Engineering Concepts

This project explores concepts commonly used in:

- Embedded systems
- Firmware engineering
- Device drivers
- Real-time systems
- Systems programming
- Serial communication protocols
- Concurrent programming

---

# Current Limitations

- No parity bit support yet
- No CRC/checksum validation
- No graphical waveform visualization
- Single communication channel
- No interrupt-driven UART simulation

---

# Roadmap

## Planned Features

- Parity bit implementation
- CRC validation
- Ring buffer architecture
- Interrupt-driven UART simulation
- Logic analyzer visualization
- SDL2 waveform viewer
- React-based frontend dashboard
- Multi-device UART bus
- Packet analyzer
- UART terminal emulator
- DMA simulation

---

# Development Goals

This project was built to:

- Explore low-level communication protocols
- Simulate embedded UART behavior
- Learn concurrency and synchronization in C++
- Understand asynchronous serial communication
- Build production-style modular C++ architecture

---

# Contributing

Contributions, ideas, and improvements are welcome.

Potential contribution areas:

- Protocol extensions
- Visualization tooling
- Performance optimization
- Error handling
- Testing framework
- Cross-platform support

---

# License

This project is licensed under the MIT License.

---

# Acknowledgements

Inspired by:

- Embedded firmware architectures
- Serial communication protocols
- Real UART peripherals used in microcontrollers
- Linux systems programming methodologies
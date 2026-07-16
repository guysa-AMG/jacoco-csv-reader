# jcov

A high-performance, zero-dependency C++ CLI utility to parse JaCoCo (Java Code Coverage) CSV reports and render clean, human-readable coverage summaries directly in your terminal.

Optimized for speed and minimal memory footprint, `jcov` processes massive coverage files using stream-based parsing, making it perfect for both local development and CI/CD pipelines.

---

## Features

- **Blazing Fast:** Written in modern C++ utilizing stream-based CSV parsing.
- **Low Memory Footprint:** Processes files line-by-line without loading entire datasets into RAM.
- **CI/CD Friendly:** Standardized exit codes make it easy to integrate into build pipelines.
- **Clean Output:** Formats complex coverage metrics into an easily scannable console output.

---

## Prerequisites

Before building, ensure you have the following installed on your system:

- A compiler supporting **C++17** or higher (e.g., `GCC >= 8`, `Clang >= 7`, or `MSVC`)
- `make` build utility
- Standard C++ Library (`libstdc++`)

---

## Build & Installation
build via make the source code


`jcov` uses a standard `Makefile` configuration for easy compilation and system deployment.

### 1. Clone the Repository
```bash
git clone [https://github.com/yourusername/readJacoco.git](https://github.com/yourusername/readJacoco.git)
cd readJacoco
```
### 2. build binary executable and install
```bash
make
make install
```

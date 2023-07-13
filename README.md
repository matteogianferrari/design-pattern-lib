# Design Pattern Examples Library

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

Welcome to the Design Pattern Examples Library! This repository provides a collection of concrete examples for commonly used design patterns in software engineering. Whether you're a beginner looking to understand design patterns or an experienced developer seeking practical implementations, this library is here to assist you.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Design patterns are proven solutions to common software design problems. By leveraging these patterns, developers can create reusable and maintainable code, promote separation of concerns, and improve overall system architecture. This library aims to provide clear and concise examples for various design patterns, allowing you to learn and apply them in your own projects.

The design patterns covered in this library are grouped into 3 macro-directories:

- Creational Patterns
- Structural Patterns
- Behavioral Patterns

Each pattern example is presented in a separate sub-directory, along with detailed explanations and code samples in C++. Whether you're interested in understanding how to implement the Singleton pattern or exploring the Observer pattern, you'll find valuable resources within this library. The examples were developed on Linux using Visual Studio Code as the integrated development environment and CMake as the build system.

## Installation

To use the examples in this library, you can simply clone the repository to your local machine:

```bash
git clone https://github.com/matteogianferrari/DesignPattern.git
```

## Usage

Once you have the repository cloned, you can navigate to the specific design pattern directory you're interested in. Each directory contains a code examples in C++. In the main.cpp is provided an overview of the pattern implementation and its use cases.

To build and run the examples, make sure you have the following dependencies installed on your Linux machine:

- C++ compiler (my version: gcc (Ubuntu 12.2.0-17ubuntu1) 12.2.0)
- CMake (my version: cmake 3.25.1) 
- Make (my version: GNU Make 4.3)

Then, follow these steps:

1. Navigate to the root directory of the design pattern example you wish to explore.
2. Create a build directory: `mkdir build && cd build`.
3. Generate the build files using CMake: `cmake ..`.
4. Build the example using Make: `make`.
5. Run the example: `./<example-name>`.

Feel free to explore the code and experiment with it in your preferred development environment. You can use these examples as a reference or starting point for implementing design patterns in your own projects.

## Documentation

The examples in this library are documented using Doxygen, a powerful documentation generator for C++. Doxygen provides an in-depth understanding of each design pattern's purpose, structure, and usage. To understand the details and documentation of each example, you can generate the Doxygen documentation by following these steps:

1. Install [Doxygen](https://www.doxygen.nl/download.html) on your machine.
2. Navigate to the root directory of the design pattern example you wish to explore.
3. Run the Doxygen command to generate the configuration file:

```bash
doxygen -g <config-file-name>
```

4. Run the Doxygen command to generate the documentation:

```bash
doxygen <config-file-name>
```

5. Once the documentation is generated, you can open the HTML file `index.html` in the `html` directory to explore the detailed documentation of the pattern and the associated code samples.

The generated Doxygen documentation includes:

- Overview and description of the design pattern
- Detailed class and function documentation
- Inheritance diagram for classes 
- Usage instructions

Please refer to the generated documentation for comprehensive information on each design pattern example.

## Contributing

Contributions to this library are welcome! If you'd like to add an implementation example for a design pattern or add a new example for a design pattern that isn't covered or improve existing examples, please follow these steps:

1. Fork the repository.
2. For new design pattern use this naming style: `DesignPatternName_v1`, for adding an implementation to a design pattern use the same naming style, with the correct number.
3. Create a new branch for your contribution: `git checkout -b DesignPatternName-YourUsername`.
4. Make your changes and test them thoroughly.
5. Commit your changes: `git commit -am 'Add new example for XYZ pattern'` or `git commit -am 'Add new implementation for XYZ pattern'`.
6. Push to the branch: `git push origin new-example`.
7. Submit a pull request, explaining the changes you've made and their significance.

Please ensure your code follows the repository's code style and includes appropriate documentation using Doxygen.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

I hope this library of design pattern examples proves valuable in your software engineering journey. If you have any questions, feedback, or suggestions, please don't hesitate to [open an issue](https://github.com/matteogianferrari/DesignPattern/issues). Happy coding!

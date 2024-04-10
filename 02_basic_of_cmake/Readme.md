# Basic of CMake

## Why CMake?

CMake is used primarily as a cross-platform build system generator that simplifies and automates the process of building software projects. It allows developers to write build configurations once and use them in any environment, making it easier to manage projects across different systems and compilers. 

![alt text](image_cmake.webp)

The key reasons for using CMake include:

1. Cross-Platform Compatibility: CMake can generate build systems for a wide range of platforms, including Windows, macOS, and various Unix-like systems. This flexibility is crucial for projects that aim to be portable across different operating systems.

2. Out-of-Source Builds: CMake supports out-of-source builds, allowing the build files to be separate from the source files. This keeps the source directory clean and makes it easier to manage multiple build configurations and targets.

3. Generates Native Build Configurations: CMake can generate native build configurations for various environments, such as Makefiles for Unix-like platforms, Visual Studio projects for Windows, and Xcode projects for macOS. This allows developers to use their preferred tools and IDEs for building the project.

4. Find Packages and Libraries: CMake includes a robust system for finding and linking with external libraries and packages. This simplifies the process of integrating third-party code and ensures that the build process is consistent across different environments.

## CMakeLists.txt

The CMakeLists.txt file serves as a configuration file for CMake, a cross-platform build system generator. This file defines the build process for a software project in a platform- and compiler-independent manner. It includes instructions for compiling the source code, linking libraries, including header file directories, and other build-related tasks.

The minimal example for single cpp file build is like below.

```cmake
project(BASIC_OF_CMAKE)

set(sources main.cpp)
add_executable(main ${sources})
```

It already located in second example folder (02_basic_of_cmake)
Let's do build it with cmake.

```bash
cd 02_basic_of_cmake
cmake . -B ./build -G Ninja
```

Command tear down
- cmake . : Use CMakeLists.txt in current directory (.)
- -B ./build : Build result files will be generated in "build" folder.
- -G Ninja : After build configuration, will use Ninja build system.

```bash
ninja -C .\build\
```

Command tear down
- ninja : Actual bulid command to make binary executable
- -C .\build : Before start build, move into bulid folder which made by cmake

Now you can find main.exe in build folder
```
- 01_basic_of_compiler
- 02_basic_of_cmake
  - build
    - ...
    - main.exe <= HERE!
  - main.cpp
  - CMakeLists.txt
```
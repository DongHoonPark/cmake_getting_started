# CMake project getting started guide

This repository gives step-by-step instruction for cmake beginners who are not used to system programming.
Assuming all examples and instructions run in Windows OS.


## Prerequisite

- [Git](https://git-scm.com/download/win)
- Compiler which you prefer
  - [MSYS(GCC)](https://www.msys2.org/)
  - [Visual Studio](https://visualstudio.microsoft.com/ko/) 
- [CMake](https://cmake.org/download/)
- [Ninja](https://ninja-build.org/)
- [Visual Studio Code](https://code.visualstudio.com/)

> Note that you can install CMake and Ninja with MSYS environment

## MSYS Setup

<details>
<summary>
Proxy Setting (Optional)
</summary> 

If you need to use proxy for web access, please follow instructions below

1. Open MSYS Shell
2. Open profile file with command below

```bash
nano /etc/profile
```

3. Add proxy address setting to last of file

```bash
export HTTP_PROXY="IpAddress:Port" # Like: 127.0.0.1:1477
export HTTPS_PROXY=$HTTP_PROXY
export http_proxy=$HTTP_PROXY
export https_proxy=$HTTP_PROXY
```

4. Close and reopen msys shell

</details> 

### Install Toolkits

Open MSYS shell and install developemnt environment

```bash
pacman -S base-devel mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc ninja 
```

Add ```C:\msys64\mingw64\bin``` to system environment variable

### Clone repository

```bash
git clone https://github.com/DongHoonPark/cmake_getting_started
```

## Contents

1. [Basic of compiler](01_basic_of_compiler/Readme.md)
2. [Basic of cmake]()
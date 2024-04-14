# Simple Features

# 3.1 Conditional Statements in CMake

## Lecture Overview:

In this session, we will learn how to use conditional statements in CMake to automatically adjust build settings based on various conditions. The if statement in CMake can be used to selectively include components of a project or apply specific compiler options, among other uses.

## Learning Objectives:

Understand the basic syntax of if statements in CMake.
Learn how to adjust build options based on conditions.
Apply conditional statements in a real project through hands-on practice.

## Syntax of if Statements in CMake

Basic structure: ```if(<condition>), elseif(<condition>), else(), endif()```

Conditions that can be used: comparing variable values, checking file existence, verifying compiler types, etc.
Example Using Conditional Statements: Platform-Specific Settings

## Setting up the example project

Configuring different compiler flags for Windows and Linux platforms

```cmake
cmake_minimum_required(VERSION 3.10)
project(ConditionalExample)

# Setting compiler flags based on the platform
if(WIN32)
    message("Configuring for Windows")
    add_definitions(-DWINDOWS)
elseif(UNIX AND NOT APPLE)
    message("Configuring for Linux")
    add_definitions(-DLINUX)
elseif(APPLE)
    message("Configuring for macOS")
    add_definitions(-DMACOS)
endif()
```

Automatically Adjusting Build Options Based on Conditions

Applying different build options for targets
For instance, linking a specific library only in Debug mode

```cmake
add_executable(myapp main.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(myapp debug_library)
endif()
```

## Practice:
Participants will set up a simple CMake project that compiles source code based on given conditions.
They will test various conditions and observe the outcomes.
Through this content, participants will learn how to use if statements in CMake to more finely control the build process. In the next session, we will explore how to use loops in CMake.

This setup will provide a practical and interactive way to understand conditional compilation in CMake.

# 3.2 Loops in CMake

## Lecture Overview:
In this session, we will explore the use of loop constructs foreach and while in CMake to dynamically create and manage multiple build targets. Loops are useful for batch processing multiple components of a project, generating configuration files, and automating test cases.

## Learning Objectives:
Understand the basic syntax and usage of foreach and while loops in CMake.
Learn how to dynamically create and manage multiple targets using loops.
Conduct hands-on practice applying loops in a real project.

## CMake’s foreach Statement

Basic structure and usage
Example of processing a list of components or files

```cmake
cmake_minimum_required(VERSION 3.10)
project(ForeachExample)

# Creating multiple executable files
set(APP_LIST app1 app2 app3)
foreach(app IN LISTS APP_LIST)
    add_executable(${app} main.cpp)
endforeach()
```

## CMake’s while Statement

Structure for repeating execution based on a condition
Example using simple conditions to control repetitive tasks

```cmake
set(counter 0)
while(counter LESS 5)
    message("Counter value: ${counter}")
    math(EXPR counter "${counter} + 1")
endwhile()
```

## Dynamic Target Creation and Management

Using loops to create targets with various compile options or linking options
Practical exercise to adjust target properties based on specific conditions

```cmake
foreach(index RANGE 1 4)
    set(target_name "library${index}")
    add_library(${target_name} STATIC "lib${index}.cpp")
    target_compile_definitions(${target_name} PRIVATE "VERSION=${index}")
endforeach()
```
## Practice:
Participants will set up a CMake project using foreach and while loops to create multiple targets and configure them differently based on conditions.
They will test various build scenarios using loops and evaluate the results.
This session will equip participants with the skills to effectively use loops in CMake, enhancing project management efficiency. Next, we will delve into setting up predefined symbols in CMake in the upcoming section.

# 3.3 Predefined Symbols in CMake

## Lecture Overview:

In this part of the course, we'll explore how to use predefined symbols in CMake to configure build settings at the compilation stage. This technique is particularly useful for defining conditional behaviors in your code, enabling feature flags, and making the build process adaptable to different environments or configurations.

## Learning Objectives:
Understand the purpose and usage of predefined symbols in CMake.
Learn how to set and use predefined symbols for different targets using target_compile_definitions.
Apply predefined symbols to a practical project example.

## Introduction to Predefined Symbols

Explanation of what predefined symbols are and how they can be used in CMake to influence the preprocessor during compilation.
Discussion on the strategic use of these symbols for enabling or disabling features dynamically.
Using target_compile_definitions

How to use target_compile_definitions to define symbols that are visible during the compilation of specific targets.
Syntax and examples of setting conditions within source code that respond to these definitions.

```cmake
cmake_minimum_required(VERSION 3.10)
project(SymbolExample)

# Define a symbol for a target
add_executable(myapp main.cpp)
target_compile_definitions(myapp PRIVATE "ENABLE_FEATURE=1")
```

## Practical Examples of Predefined Symbols

Scenario where different symbols are defined for different build types (e.g., Debug vs. Release).
Incorporating symbols to manage feature availability across multiple platforms or configurations.

```cmake
add_executable(myapp main.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(myapp PRIVATE "DEBUG_MODE=1")
else()
    target_compile_definitions(myapp PRIVATE "DEBUG_MODE=0")
endif()
```

## Practice:
Participants will modify an existing CMake project to include predefined symbols that change the behavior of the software depending on the build type and conditions.
This practice session will include tasks like adding diagnostic messages, enabling debug features, and customizing application behavior through compile-time definitions.
This session teaches participants how to utilize predefined symbols effectively in CMake to tailor the compilation process to different development needs and scenarios. In the next section, we will cover how to incorporate subdirectories into your CMake project.


# 3.4 Using Subdirectories in CMake

## Lecture Overview:

This section will focus on how to organize larger CMake projects by using subdirectories effectively. The add_subdirectory function plays a key role in this process, allowing developers to manage project complexity and modularize the code base.

## Learning Objectives:
Learn the role and benefits of using subdirectories in CMake projects.
Understand how to use the add_subdirectory function to include and manage multiple directories.
Gain hands-on experience in structuring a project with subdirectories.

## Introduction to Subdirectories

Overview of project organization and the advantages of dividing a project into multiple subdirectories.
Basic structure of a CMake project that uses multiple subdirectories.
Using add_subdirectory

How to structure your CMakeLists files across different directories.
Syntax and practical application of add_subdirectory to include various components like libraries, executables, and tests.
```cmake
cmake_minimum_required(VERSION 3.10)
project(MultiDirectoryExample)

# Include the library directory
add_subdirectory(library)

# Include the executable directory
add_subdirectory(executable)
```

## Practical Example of a Modular Project

Setting up a project with a clear separation of components: a library in one directory and an executable in another.
Configuring dependencies between different components within the subdirectories.

```cmake
# Directory: library/CMakeLists.txt
add_library(mylib STATIC lib.cpp lib.h)

# Directory: executable/CMakeLists.txt
add_executable(myapp main.cpp)
target_link_libraries(myapp PRIVATE mylib)
```

## Practice:
Participants will create a sample CMake project that includes at least two subdirectories, one for a library and another for an executable.
They will configure the project so that the executable depends on the library, demonstrating an understanding of managing project dependencies through subdirectories.
This session equips participants with the skills to structure large CMake projects using subdirectories, enhancing modularity and maintainability. This approach is essential for scaling projects efficiently and maintaining a clear project hierarchy.
# Basic of Compiler

## What the compiler is

![alt text](image.png)

A compiler is a specialized computer program that translates code written in one programming language into another language, typically transforming source code written in a high-level programming language (like C, C++, or Rust) into machine code, assembly language, or another high-level language. This conversion process enables the computer to execute the program.

The primary purpose of a compiler is to turn the source code, which is written by humans and understandable by humans, into a language that machines can understand and execute. 

## Your first compile 

Let's compile simple hello world program

```c++
#include <iostream>

int main(void)
{
    std::cout<<"Hello World!"<<std::endl;
}
```

Compile.

```bash
cd 01_basic_of_compiler
g++ main.cpp -o main.exe
```

Commands tear down

- g++ : Compile c++ program with gcc compiler
- main.cpp : input c++ file
- -o main.exe : output file name is main.exe

Run program
```bash
.\main.exe
Hello World!
```


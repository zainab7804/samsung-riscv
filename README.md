# Samsung-riscv
The program is centered around the RISC-V architecture and is designed to provide in-depth knowledge and practical experience in VLSI chip design using open-source tools. It help learners to bridge the gap between academic concepts and industry practices. The internship is guided by Mr. Kunal Ghosh.

## Basic Details

**Name:** Zainab Fathima

**College:** Vidyavardhaka College of Engineering

**Email ID:** zf7804@gmail.com

**GitHub Profile:** [zainab7804](https://github.com/zainab7804)

----------------------------------------------------------------------------------------------------------------------------

<details>
<summary><b>TASK 1:</b> 
  
The task focuses on exploring C and RISC-V labs to compile C programs using both the GCC and RISC-V compilers.</summary>

C Lab

We start by creating a file in the chosen directory using a simple editor like Leafpad. After writing the program to calculate the sum of numbers from 1 to n, save the file, close the editor, and compile it using GCC. Once compiled, you can run the program to see the output.

C Code to calculate 1 to n numbers


The commands used are
```
gcc sum1ton.c
./a.out

```

![Code compiled using gcc compiler](https://github.com/user-attachments/assets/f02b5054-2576-4505-8c07-e6c7d2bf00cf)



RISC-V lab

It involves viewing the code with the cat command to ensure it’s correct.

```
cat sum1ton.c

```
Next, compile it using the RISC-V GCC compiler.

```
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```
After compiling, use

```
riscv64-unknown-elf-objdump -d sum1ton.o

```
to disassemble the code and examine its assembly language version. This provides a closer look at how the program works at the hardware level.

![Code compiled using riscv compiler](https://github.com/user-attachments/assets/18cbdbe6-e335-4377-a2c7-f58c8d03c138)

The Assembly language code is displayed.

![objdump using O1](https://github.com/user-attachments/assets/80bb92da-641c-46d2-9783-0631849a783b)
Using O1

![Objdump using Ofast](https://github.com/user-attachments/assets/6c79d2a9-a40d-4fc9-8af6-954d91309a73)
Using Ofast

Optimization levels in GCC improve code performance and size to varying degrees. -O0 applies no optimization, suitable for debugging. -O1 offers basic optimizations, making code faster and smaller without significantly increasing compilation time, striking a balance between performance and simplicity. -Ofast prioritizes speed over strict compliance with standards, ideal for performance-critical tasks but requires thorough testing to avoid unexpected issues. Testing is crucial, as higher optimizations may complicate debugging or affect precision in critical calculations.

Description of the commands used while execution:

C lab

1. cd: Changes the current working directory in a command-line interface.
2. leafpad: A simple and lightweight graphical text editor for Linux systems.
3. gcc: Performs the compilation step to build a program.
4. ./a.out: It will execute the file that was created with the compile.

RISC-V lab

1. -mabi=lp64: Specifies the ABI (Application Binary Interface) for RISC-V, indicating the use of the LP64 model, which uses 64-bit long integers and pointers.
2. -march=rv64i: Specifies the target architecture for RISC-V. rv64i indicates a 64-bit RISC-V processor using the base integer instruction set (I).
3. riscv-objdump: A tool that displays assembly instructions from a compiled RISC-V binary file. It helps in debugging and understanding compiled code.
4. -Ofast: An aggressive optimization level in GCC that prioritizes performance over strict standards compliance. It enables high-speed optimizations, but some may deviate from strict IEEE or ISO standards.
5. -O1: Enables basic optimizations in GCC that improve performance without significantly increasing compilation time.
</details>

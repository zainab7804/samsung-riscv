![Objdump using O1](https://github.com/user-attachments/assets/54327850-ebb8-4c52-b871-2a95f9efd898)# Samsung-riscv
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
```
#include<stdio.h>
int main()
{
  int i, sum=0, n=90;
  for(i=0;i<=n;++i)
    {
      sum+=i;
    }
  printf("Sum of numbers from 1 to %d is %d\n",n,sum);
  return 0;
}
```

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
![Code compiled using riscv compiler](https://github.com/user-attachments/assets/18cbdbe6-e335-4377-a2c7-f58c8d03c138)

After compiling, use

```
riscv64-unknown-elf-objdump -d sum1ton.o

```
to disassemble the code and examine its assembly language version. This provides a closer look at how the program works at the hardware level.

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

<details>
<summary><b>TASK 2:</b> 
  
Performing SPIKE Simulation and Debugging the C code with Interactive Debugging Mode using Spike. </summary>

We start by creating a file in the chosen directory using a simple editor like Leafpad. After writing the program to swap two numbers, save the file, close the editor.

C Code to swap two numbers
```
#include<stdio.h>
void main()
{
int a=10, b=5, temp;
printf("Numbers before swap: A=%d and B=%d\n",a,b);
temp=a;
a=b;
b=temp;
printf("Numbers after swap: A=%d and B=%d\n",a,b);
}
```

The code has to be simulated using both gcc and riscv compiler. Same output should be displayed on the terminal for both.

The commands used are as follows:

For gcc compiler
```
gcc swap.c
./a.out
```
For riscv compiler
```
spike pk swap.o
```
![gcc and spike output](https://github.com/user-attachments/assets/47a39f63-5665-4642-b43f-adb50fc64e2c)

Object dump for C code using Ofast and O1

![Objdump using Ofast](https://github.com/user-attachments/assets/33446aa1-b054-46e3-b856-e6776a2f541d)
Using Ofast

![Objdump using O1](https://github.com/user-attachments/assets/db290a9e-e2f5-4c91-ad16-30f2da31da3a)
Using O1

To debug the assembly language program use the following commands

1. To open the object dump
   ```
   riscv64-unknown-elf-objdump -d swap.o | less
   ```
2. To debug
   ```
   spike -d pk swap.o

   ```
The debugging operations are performed as follows
![Debugging](https://github.com/user-attachments/assets/f150cd24-dd67-4e04-9744-b5354575f72f)

Description of the commands used while execution:
1. spike: This is the RISC-V ISA simulator (an instruction set simulator). Spike is commonly used for simulating and testing RISC-V programs. It emulates a RISC-V processor, running programs in a controlled environment.
2. -d: This flag is for debugging mode. It tells Spike to run in debug mode, allowing step-by-step execution, inspecting registers, memory, etc. Useful for identifying issues and analyzing program behavior.
3.  pk: This refers to the proxy kernel, which acts as a lightweight operating system for RISC-V. The proxy kernel handles system calls and facilitates program execution in the simulated environment.

Description of few assembly level instructions:
1. addi (Add Immediate)
   
   Format: addi rd, rs1, imm
   
   Adds an immediate value (imm) to the value in register rs1 and stores the result in register rd.
   
2.  sd (Store Doubleword)
   
    Format: sd rs2, offset(rs1)
   
    Stores a 64-bit value from register rs2 into memory at an address calculated by offset + rs1.
   
3. lui (Load Upper Immediate)

   Format: lui rd, imm
   
   The value in imm is shifted left by 12 bits and stored in the upper portion of the destination register.
   
4. li (Load Immediate)

   Format: li rd, imm
   
   Loads an immediate value (imm) into a register (rd).

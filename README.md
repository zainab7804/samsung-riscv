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

### C Lab

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



### RISC-V lab

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

### Description of the commands used while execution:

**C lab**

1. cd: Changes the current working directory in a command-line interface.
2. leafpad: A simple and lightweight graphical text editor for Linux systems.
3. gcc: Performs the compilation step to build a program.
4. ./a.out: It will execute the file that was created with the compile.

**RISC-V lab**

1. -mabi=lp64: Specifies the ABI (Application Binary Interface) for RISC-V, indicating the use of the LP64 model, which uses 64-bit long integers and pointers.
2. -march=rv64i: Specifies the target architecture for RISC-V. rv64i indicates a 64-bit RISC-V processor using the base integer instruction set (I).
3. riscv-objdump: A tool that displays assembly instructions from a compiled RISC-V binary file. It helps in debugging and understanding compiled code.
4. -Ofast: An aggressive optimization level in GCC that prioritizes performance over strict standards compliance. It enables high-speed optimizations, but some may deviate from strict IEEE or ISO standards.
5. -O1: Enables basic optimizations in GCC that improve performance without significantly increasing compilation time.
</details>

----------------------------------------------------------------------------------------------------------------------------

<details>
<summary><b>TASK 2:</b> 
  
Performing SPIKE Simulation and Debugging the C code with Interactive Debugging Mode using Spike. </summary>

We start by creating a file in the chosen directory using a simple editor like Leafpad. After writing the program to swap two numbers, save the file, close the editor.

### C Code to swap two numbers
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

### Description of the commands used while execution:
1. **spike:** This is the RISC-V ISA simulator (an instruction set simulator). Spike is commonly used for simulating and testing RISC-V programs. It emulates a RISC-V processor, running programs in a controlled environment.
2. **-d:** This flag is for debugging mode. It tells Spike to run in debug mode, allowing step-by-step execution, inspecting registers, memory, etc. Useful for identifying issues and analyzing program behavior.
3.  **pk:** This refers to the proxy kernel, which acts as a lightweight operating system for RISC-V. The proxy kernel handles system calls and facilitates program execution in the simulated environment.

### Description of few assembly level instructions:
1. **addi (Add Immediate)**
   
   Format: addi rd, rs1, imm
   
   Adds an immediate value (imm) to the value in register rs1 and stores the result in register rd.
   
2.  **sd (Store Doubleword)**
   
    Format: sd rs2, offset(rs1)
   
    Stores a 64-bit value from register rs2 into memory at an address calculated by offset + rs1.
   
3. **lui (Load Upper Immediate)**

   Format: lui rd, imm
   
   The value in imm is shifted left by 12 bits and stored in the upper portion of the destination register.
   
4. **li (Load Immediate)**

   Format: li rd, imm
   
   Loads an immediate value (imm) into a register (rd).

</details>

----------------------------------------------------------------------------------------------------------------------------

<details>
<summary><b>TASK 3:</b> 
  
The goal is to analyze and categorize each of the provided instructions based on their type, whether it be R-type, I-type, or J-type, and then translate them into their respective 32-bit machine instruction codes.</summary>


### What is RISC-V?

RISC-V is an open-source instruction set architecture (ISA) that enables developers to design processors for specific applications without the need for licensing fees. It is based on reduced instruction set computer (RISC) principles and represents the fifth generation of processors built on this concept. As an open and free alternative processor technology, RISC-V offers flexibility and accessibility to developers.

### Instruction Formats in RISC-V

The instruction format of a processor defines how machine language instructions are structured for execution. In RISC-V, the instructions are composed of fields that specify the data's location and operations. There are six main instruction formats in RISC-V:


1. R-format
2. I-format
3. S-format
4. B-format
5. U-format
6. J-format

Each format serves specific purposes in the processor's operation.

![Screenshot 2025-01-22 161646](https://github.com/user-attachments/assets/29ce1369-8c8b-4613-8747-4b28c26ccb8e)

### 1. R-type Instruction:
It is designed for operations that are performed on registers rather than memory locations. It is primarily used for executing arithmetic and logical operations.

The 32-bit instruction is divided into six fields:
![image](https://github.com/user-attachments/assets/290511a0-b7e0-4ace-9317-90ae6b202258)

1. **Opcode (7 bits):** Specifies the type of instruction format and operation to be performed.
2. **rd (5 bits):** Represents the Destination Register where the result of the operation is stored.
3. **func3 (3 bits):** Determines the specific arithmetic or logical operation to be performed.
4. **rs1 (5 bits):** First Source Register that holds input data for the operation.
5. **rs2 (5 bits):** Second Source Register used alongside rs1 for computation.
6. **func7 (7 bits):** Works similarly to func3 by providing additional operation details.

These fields together enable the execution of arithmetic and logical instructions using registers in RISC-V.

Example: add x1, x2, x3

![image](https://github.com/user-attachments/assets/6c0a77a4-0104-44cf-a604-71e8bfa873e7)

32-bit Instruction: 0000000   00011   00010   000   00001   0110011

### 2. I-type Instruction:
The "I" in I-type stands for Immediate, meaning operations use both registers and an immediate (constant) value, rather than memory locations. This instruction type is primarily used for immediate and load operations.

The 32-bit instruction is divided into five fields:

![image](https://github.com/user-attachments/assets/b9da4979-22e7-41aa-86b3-b82217cb3540)

1. **Opcode (7 bits):** Specifies the type of instruction format and operation to be performed.
2. **rd (5 bits):** Destination Register that stores the final result of the operation.
3. **func3 (3 bits):** Specifies the type of arithmetic or logical operation to be performed.
4. **rs1 (5 bits):** Source Register that provides input data for the operation.
5. **Immediate (12 bits):** A signed immediate value (imm[11:0]) used in calculations or load operations.

Key Difference from R-type:
Instead of having an rs2 register and func7 field (as in R-type), the I-type instruction includes a 12-bit immediate value, making it suitable for operations involving constants.

Example: addi x1, x2, 10

![image](https://github.com/user-attachments/assets/908a5336-bfac-4dcb-b356-048439797d3b)

32-bit Instruction: 000000000101   00010   000   00001   0010011

### 3. S-type Instruction:
 The "S" stands for Store, indicating that this instruction type is used to store the value from a register into memory. It is primarily used for store operations.

The 32-bit instruction is divided into six fields:

![image](https://github.com/user-attachments/assets/7b7c951e-c1e2-4432-b828-b946aafaebda)

1. **Opcode (7 bits):** Specifies the type of instruction format and operation to be performed.
2. **imm[11:5] (7 bits):** The upper 7 bits of a 12-bit signed immediate value, located in bits [31:25] of the instruction.
3. **rs2 (5 bits):** Source Register (register value to be stored in memory).
4. **rs1 (5 bits):** Base register used to calculate the memory address.
5. **func3 (3 bits):** Specifies the width and type of the store operation (e.g., word, half-word, or byte).
6. **imm[4:0] (5 bits):** The lower 5 bits of the 12-bit signed immediate value, located in bits [11:7] of the instruction.

Key Features of S-type:
There is no rd field in S-type instructions, as they do not store values in registers.
The value to be stored is found in the rs2 field, and the address is calculated using rs1 and the immediate field.

Example: sw x1, 8(x2)

![image](https://github.com/user-attachments/assets/8e1d1759-dabd-4525-b57c-33b2996196c1)

32-bit Instruction: 0000000   00001   00010   010   01000   0100011

### 4. B-type Instruction:
The "B" stands for Branching, indicating that this instruction is used for conditional branching based on certain conditions.

The 32-bit instruction is divided into eight fields:

![image](https://github.com/user-attachments/assets/9d801245-ebcb-42a9-af76-70f7d51a4a22)

1. **Opcode (7 bits):** Specifies the type of instruction format and operation to be performed.
2. **imm[12] (1 bit):** The most significant bit of a 12-bit signed immediate, located in bit [31] of the instruction.
3. **imm[10:5] (6 bits):** The next 6 bits of the signed immediate, located in bits [25:30] of the instruction.
4. **imm[4:1] (4 bits):** The next 4 bits of the signed immediate, located in bits [11:8] of the instruction.
5. **imm[11] (1 bit):** The second most significant bit of the signed immediate, located in bit [7] of the instruction.
6. **rs1 (5 bits):** First source register used in conditional operations.
7. **rs2 (5 bits):** Second source register used in conditional operations.
8. **func3 (3 bits):** Specifies the condition for branching (e.g., equal, not equal, less than).

Branching Logic:
If the condition defined by func3 is true, the Program Counter (PC) is updated by adding the immediate value to the current PC.
If false, the PC is updated by adding 4 bytes to the current PC, moving to the next instruction.
Word Alignment:
RV32 instructions are word-aligned, meaning the address is always a multiple of 4 bytes.

Example: beq x1, x2, 16

![image](https://github.com/user-attachments/assets/bd500417-76cf-4edd-abe0-10cdffc59f7f)

32-bit Instruction: 0000000   00001   00010   000   00010   1100011

### 5. U-type Instruction:
In the RV32 architecture, each U-type instruction is 32 bits long. The "U" stands for Upper Immediate, as these instructions are used to transfer an immediate value into the upper portion of the destination register. They are mainly used for loading large constants into registers.

The 32-bit instruction is divided into three fields:

![image](https://github.com/user-attachments/assets/5d6a9e21-f0c0-4227-849b-a47d7fdd0700)

1. **Opcode (7 bits):** Specifies the type of instruction format and operation to be performed.
2. **rd (5 bits):** Destination Register where the immediate value is transferred.
3. **Immediate (20 bits):** A 20-bit immediate value that is placed in the upper portion of the destination register.

Key Instructions in U-type:
The two primary U-type instructions are:
LUI (Load Upper Immediate)
AUIPC (Add Upper Immediate to PC)

Example: lui x1, 0x12345

![image](https://github.com/user-attachments/assets/b26962e1-a6fa-4186-b8a7-7ccb724cc8a4)

32-bit Instruction: 00010010001101000101   00001   0110111

### 6. J-type Instruction:
The "J" stands for Jump, indicating that this instruction format is used for jump-type operations, typically for branching to a specific memory location. J-type instructions are mainly used for implementing jumps and loops, allowing the program to branch to desired memory locations.

The 32-bit instruction is divided into six fields:

![image](https://github.com/user-attachments/assets/f2d82749-75bb-4019-a82d-1ba758fcbb99)

1. **Opcode (7 bits):** Specifies the type of instruction format and operation to be performed.
2. **rd (5 bits):** Destination Register used to store the return address in jump operations.
3. **Immediate (20 bits):** A 20-bit signed immediate value that represents the offset for the jump. 

Key Instruction in J-type:
JAL (Jump and Link):
This instruction performs a jump to the target address specified by the immediate value and stores the return address (next instruction) in the destination register (rd).

Example: jal x1, 2048

![image](https://github.com/user-attachments/assets/a725c779-d07f-4b39-b19d-5c741139f75b)

32-bit Instruction: 000000000010   0000000000   00001   1101111
</details>

----------------------------------------------------------------------------------------------------------------------------

<details>
<summary><b>TASK 4:</b> 
  
To perform a functional simulation of the given RISC-V Core Verilog netlist and testbench.</summary>

We will use the Verilog Code and Testbench of RISCV that has already been designed. 



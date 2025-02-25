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

Note: We will use the Verilog Code and Testbench of RISCV that has already been designed.

### Step 1: Installation of iverilog and gtkwave

Use the following commands for installation:
1. For iverilog installation:
 ```
  $ sudo apt install iverilog
 ```
2. For gtkwave installation:
 ```
  $ sudo apt install gtkwave
 ```
### Step 2: Create two files for verilog and testbench using the following commands
```
  $ gedit iiitb_rv32i.v
  $ gedit iiitb_rv32i_tb.v
```
### Step 3: To simulate and run the verilog code , enter the following commands in your terminal
```
  $ iverilog -o iiitb_rv32i iiitb_rv32i.v iiitb_rv32i_tb.v
  $ ./iiitb_rv32i
```
### Step 4: To see the simulation waveform in GTKWave, enter the following command:
```
  $ gtkwave iiitb_rv32i.vcd
```
 The gtkwave will be opened and the following window will appear.
 
 ![window](https://github.com/user-attachments/assets/03ae390f-cfe6-4812-8a62-7c1fdbc8b502)

### Step 5: Analysing the output waveform
**1. add r6,r1,r2**
 ![1](https://github.com/user-attachments/assets/00308126-3291-4427-b5d9-13e79de65fbc)

**2. sub r7,r1,r2**
![2](https://github.com/user-attachments/assets/3e4ee4d4-3d47-4595-ba87-0d9991f6641b)

**3. and r8,r1,r3**
![3](https://github.com/user-attachments/assets/ffae9471-fb14-487a-9552-de02d69dc951)

**4. or r9,r2,r5**
![4](https://github.com/user-attachments/assets/08fa8780-754e-4109-a70a-97a4b619370d)

**5. xor r10,r1,r4**
![5](https://github.com/user-attachments/assets/2b92a9dc-8d52-4f8b-a618-72ff0454355f)
 
**6. slt r11,r2,r4**
![6](https://github.com/user-attachments/assets/3749a038-8571-4353-8447-ba10ce15220b)

**7. addi r12,r4,5**
![7](https://github.com/user-attachments/assets/0b8e7fe4-f923-4fd5-8e65-8146dcd1ce41)

**8.  lw r13,r1,2**
![8](https://github.com/user-attachments/assets/c5e6ac2b-6912-4307-b33b-21d8a1ba2fec)
    
**9.  beq r0,r0,15**
![9](https://github.com/user-attachments/assets/36d38d5a-4c5c-4f9a-a233-1a79e395f8ea)

</details>

------------------------------------------------------------------------------------------------------------------------------------------------


<details>
<summary><b>TASK 5:</b> 
  
**Project:** 2 Bit Comparator using VSDSquadron mini board. </summary>

**Overview:**
This project focuses on developing and testing a 2-bit comparator using the VSDSquadron Mini board. A 2-bit comparator is a digital circuit that evaluates two 2-bit binary numbers and determines their relationship—whether one is greater than, less than, or equal to the other. The implementation includes writing the comparator logic in C using Visual Studio Code, assembling the circuit on a breadboard, and utilizing LEDs to display the comparison results. The project combines software and hardware integration to demonstrate the practical application of digital logic design.

**Components Required:**
1. ***VSDSquadron Mini Board:*** Serves as the main microcontroller for processing and implementing the comparator logic.
2. ***Breadboard and Jumper Wires:*** Used for assembling and testing the circuit connections.
3. ***LEDs:*** We require 3 LEDs which idicate the comparison results (greater than, less than, or equal).
4. ***Resistors (220 Ω):*** Protect the LEDs by limiting current flow.

**PIN Configurations:**
![image](https://github.com/user-attachments/assets/dab4caaf-87d0-40e3-984b-70fea92d80db)



**Circuit Diagram:**

![image](https://github.com/user-attachments/assets/5da872f2-a974-4882-8f40-026aba063bc2)




**Truth Table:**

![image](https://github.com/user-attachments/assets/88fde976-602c-4380-9d73-5964e8b5b853)


**C Code:**

```
#include <ch32v00x.h>
#include <debug.h>
#include<stdio.h>

#define LED1_PIN GPIO_Pin_4 //yellow LED
#define LED2_PIN GPIO_Pin_5 //red LED
#define LED3_PIN GPIO_Pin_6 //green LED
#define LED_PORT GPIOD

void GPIO_Config(void) {
    // Enable the clock for GPIOD

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    // Configure PD4, PD5, and PD6 as outputs
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN | LED3_PIN ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Push-pull output
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
}

void compare_2bit(uint8_t a, uint8_t b) {
    // Clear all LEDs
    GPIO_ResetBits(LED_PORT, LED1_PIN | LED2_PIN | LED3_PIN);

    if (a > b) {
      // Light up LED1 if a > b
        GPIO_SetBits(LED_PORT, LED1_PIN);
    } else if (a == b) {
        // Light up LED2 if a == b
        GPIO_SetBits(LED_PORT, LED2_PIN);
    } else {
        // Light up LED3 if a < b
        GPIO_SetBits(LED_PORT, LED3_PIN);
    }  
    
}  

int main(void) {   
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    // Initialize the GPIO for the LEDs
    GPIO_Config();


    // Main loop to iterate over all possible 2-bit numbers  
     for (uint8_t a = 0; a <= 3; a++) {
        for (uint8_t b = 0; b <= 3; b++) {
            compare_2bit(a, b);
            Delay_Ms(500); // Delay for visualization
        }
    }
    
    return 0;
}

```
**Conclusion:**
This project successfully demonstrates the use of the VSDSquadron Mini board to implement a basic digital circuit. The 2-bit comparato compares two binary numbers and displays the results using LEDs. This implementation reinforces key concepts of digital logic design, hardware integration, and microcontroller programming. Overall, the project provided a valuable hands-on learning experience in embedded systems and digital electronics.

Further improvements can be done by:

* Expanding to a 4-bit or 8-bit comparator.

* Displaying outputs on an LCD screen instead of LEDs.

* Using button inputs instead of hardcoded values.

</details>

---------------------------------------------------------------------------------------------------------------------------------

<details>
<summary><b>TASK 6:</b> 
  
Project Implementation.</summary>

**Implementation Video:**

https://github.com/zainab7804/samsung-riscv/raw/refs/heads/main/TASK%206/Video.mp4 

**Applications:**

1. **Digital Circuits and Processors:**
* Used in ALUs (Arithmetic Logic Units) as part of larger comparator circuits for decision-making.
* Helps in implementing control units in microprocessors for conditional branching operations.
* Forms the basis for larger bit comparators used in high-speed computing.
2. **Embedded Systems:**
* Used in sensor-based applications where small binary values need comparison (e.g., temperature thresholds, voltage levels).
* Employed in digital controllers to compare signals and trigger actions in embedded devices.
* Helps in low-power decision-making systems such as IoT devices.
3. **Communication Systems:**
* Used in error detection and correction circuits for comparing received and expected data bits.
* Plays a role in modulation and demodulation techniques, where bit-wise comparisons are necessary.
* Applied in signal processing systems for threshold detection.
4. **Robotics and Automation:**
* Used in robotic decision-making systems where conditions like distance measurement or object detection require comparison.
* Applied in automated sorting systems, where binary values represent categories.
* Helps in motion control applications, determining directional movements based on sensor inputs.
5. **Security and Access Control:**
* Used in digital lock systems, comparing entered codes against stored binary values.
* Helps in biometric authentication systems where digital patterns are compared.
* Applied in number-based security verifications in digital circuits.

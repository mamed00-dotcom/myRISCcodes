# myRISCcodes

- This repository contains some simple RISC-V assembly and C programs demonstrating -multithreading, system calls, and arithmetic operations.
- All programs are compiled STATICALLY, so they do not require additional shared libraries at runtime.


# Required Tools & Installation
To compile and run the RISC-V programs, I used:

- RISC-V Cross-Compiler (riscv64-unknown-elf-gcc and riscv64-linux-gnu-gcc)
- QEMU for RISC-V (to run the compiled programs)

```bash
#mamed@mamed-MS-7C95:~$ riscv64-unknown-elf-gcc --version
riscv64-unknown-elf-gcc (13.2.0-11ubuntu1+12) 13.2.0
#mamed@mamed-MS-7C95:~$ riscv64-linux-gnu-gcc --version
riscv64-linux-gnu-gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
#mamed@mamed-MS-7C95:~$ qemu-riscv64 --version
qemu-riscv64 version 8.2.2 (Debian 1:8.2.2+ds-0ubuntu1.5)
```

# For compilation : 

- if you want to compile everything at once, just simply use : 

```bash
make
```

- This will compile all source files inside ``src/`` and place the executables in the ``build/`` directory.

to clean compiled files 
```bash
make clean
```
# Running the Programs
### Addition (C program)
```bash
qemu-riscv64 ./build/addit
```
### Addition Assembly 
```bash 
qemu-riscv64 ./build/addp
echo $?
```
### Multithreading Examples
```bash
qemu-riscv64 ./build/thread_pool
qemu-riscv64 ./build/threads
qemu-riscv64 ./build/cond_example
```

### Assembly Program Example
```bash
qemu-riscv64 ./build/program
```

# why did I use static compilation?
By default, programs compiled with ``riscv64-linux-gnu-gcc`` dynamically link to system libraries.
This means that at runtime, they require access to shared libraries such as ``ld-linux-riscv64-lp64d.so.1.``

So, if the system running the program does not have these libraries installed, you might encounter this error as I had before :

```bash 
qemu-riscv64: Could not open '/lib/ld-linux-riscv64-lp64d.so.1': No such file or directory
```
To avoid this issue, I used static compilation ``-static`` , which ensures that: 
- All necessary libraries are included in the compiled binary.
- The program does not require any external shared libraries.
- The program can run on any system without missing dependencies.


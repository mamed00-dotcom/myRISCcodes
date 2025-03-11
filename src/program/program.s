.section .data
message:
    .asciz "Hello from RISC-V Assembly!\n"

.section .text
.global _start

_start:
    # Print string
    li a7, 64         # syscall: write
    li a0, 1          # stdout
    la a1, message    # Load address of message
    li a2, 26         # Length of message
    ecall             # Call system

    # Exit program
    li a7, 93         # syscall: exit
    li a0, 0          # Exit code 0
    ecall             # Call system

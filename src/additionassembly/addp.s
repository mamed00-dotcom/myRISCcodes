.section .text
.global _start

_start:
    # Load values into registers
    li a0, 5       # Load immediate 5 into register a0
    li a1, 7       # Load immediate 7 into register a1

    # Perform addition
    add a2, a0, a1 # a2 = a0 + a1

    # Exit program (Linux syscall)
    li a7, 93      # syscall for exit
    mv a0, a2      # return value in a0
    ecall

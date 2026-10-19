.syntax unified
.arm
.section .text.start,"ax",%progbits
.global _start
_start:
 b _entry
 .incbin "src/header.bin"
_entry:
 ldr sp, =0x03007F00
 ldr r0, =__data_load__
 ldr r1, =__data_start__
 ldr r2, =__data_end__
1: cmp r1,r2
 bhs 2f
 ldr r3,[r0],#4
 str r3,[r1],#4
 b 1b
2: ldr r1, =__bss_start__
 ldr r2, =__bss_end__
 mov r3,#0
3: cmp r1,r2
 bhs 4f
 str r3,[r1],#4
 b 3b
4: bl main
1: b 1b

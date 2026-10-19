ENTRY(_start)
MEMORY {
 ROM (rx) : ORIGIN = 0x08000000, LENGTH = 16M
 IWRAM (rwx) : ORIGIN = 0x03000000, LENGTH = 32K
}
SECTIONS {
 .text : { KEEP(*(.text.start)) *(.text*) *(.rodata*) . = ALIGN(4); } >ROM
 .data : { __data_start__ = .; *(.data*) . = ALIGN(4); __data_end__ = .; } >IWRAM AT>ROM
 __data_load__ = LOADADDR(.data);
 .bss (NOLOAD) : { __bss_start__ = .; *(.bss*) *(COMMON) . = ALIGN(4); __bss_end__ = .; } >IWRAM
 /DISCARD/ : { *(.comment*) *(.note*) *(.ARM.exidx*) *(.eh_frame*) }
}

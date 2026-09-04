PHDRS
{
    rom PT_LOAD;
    ram PT_LOAD;
}

SECTIONS
{
    . = 0x00000000;
    .text : { *(.text .text.*) } :rom
    . = 0x00010002;
    .data : { *(.data .data.*) } :ram
    .rodata : { *(.rodata .rodata.*) } :ram
    .bss : { *(.bss .bss.* COMMON) } :ram
}

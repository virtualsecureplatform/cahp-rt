PHDRS
{
    rom PT_LOAD;
    ram PT_LOAD;
}

SECTIONS
{
    . = 0x00000000;
    .text : { *(.text) } :rom
    . = 0x00010002;
    .data : { *(.data) } :ram
    .rodata : { *(.rodata) } :ram
    .bss : { *(.bss) } :ram
}

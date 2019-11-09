SECTIONS
{
    . = 0x00000000;
    .text : { *(.text) }
    . = 0x00010002;
    .data : { *(.data) }
    .rodata : { *(.rodata) }
    .bss : { *(.bss) }
}

OUTPUT_ARCH("riscv")
ENTRY(_entry)

PHDRS
{
  text   PT_LOAD;
  rodata PT_LOAD;
  data   PT_LOAD;
}

SECTIONS
{
  . = 0x80000000;

  .text : {
    *(.text .text.*)
  } :text

  .rodata : {
    . = ALIGN(16);
    *(.rodata .rodata.*)
  } :rodata

  .data : {
    . = ALIGN(16);
    *(.data .data.*)
  } :data

  .bss : {
    . = ALIGN(16);
    *(.bss .bss.*)
  } :data
}

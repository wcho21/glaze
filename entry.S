.section .text
.global _entry
_entry:
    la    sp,   stack + 4096

    call  start

park:
    wfi
    j     park

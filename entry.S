.section .text
.global _entry
_entry:
    la    sp,   stack + 4096

    jal   start

park:
    wfi
    j     park

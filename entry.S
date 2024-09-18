.equ      STACK_SIZE, 4096

.section  .text
.global   _entry
_entry:
    la    sp,   stack + STACK_SIZE

    call  start

park:
    wfi
    j     park

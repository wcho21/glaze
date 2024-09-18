.global handle_timer_interrupt
.align 4
handle_timer_interrupt:
    csrr  a0,   mepc

    jal   callback_timer_function

    csrw  mepc, a0

    mret

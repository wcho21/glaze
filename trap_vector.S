.global trap_vector
.align 4
trap_vector:
    csrrw t0,   mscratch, t0

    sd    ra,   0(t0)
    sd    sp,   8(t0)
    sd    gp,   16(t0)
    sd    tp,   24(t0)
    sd    t0,   32(t0)
    sd    t1,   40(t0)
    sd    t2,   48(t0)
    sd    a0,   72(t0)
    sd    a1,   80(t0)
    sd    a2,   88(t0)
    sd    a3,   96(t0)
    sd    a4,   104(t0)
    sd    a5,   112(t0)
    sd    a6,   120(t0)
    sd    a7,   128(t0)
    sd    t3,   216(t0)
    sd    t4,   224(t0)
    sd    t5,   232(t0)
    sd    t6,   240(t0)

    csrw  mscratch, t0

    csrr  a0, mepc
    csrr  a1, mcause
    call  handle_trap

    csrw  mepc, a0

    csrr  t0, mscratch

    ld    ra,   0(t0)
    ld    sp,   8(t0)
    ld    gp,   16(t0)
    ld    t0,   32(t0)
    ld    t1,   40(t0)
    ld    t2,   48(t0)
    ld    a0,   72(t0)
    ld    a1,   80(t0)
    ld    a2,   88(t0)
    ld    a3,   96(t0)
    ld    a4,   104(t0)
    ld    a5,   112(t0)
    ld    a6,   120(t0)
    ld    a7,   128(t0)
    ld    t3,   216(t0)
    ld    t4,   224(t0)
    ld    t5,   232(t0)
    ld    t6,   240(t0)

    mret

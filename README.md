# Glaze

A simple operating system kernel for [RISC-V][riscv].

[riscv]: https://riscv.org/

## How to Run

The following process is based on Ubuntu (24.04) with a cross-compiler `gcc` and an emulator `qemu`.

To build a kernel, run `make`.

To run a kernel with `qemu`, run `make qemu`.

To run a debugger, run `make qemu-gdb`.
In another terminal, run `gdb-multiarch`.
Then you can debug with `target remote:26000` in gdb.

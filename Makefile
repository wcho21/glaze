CC = riscv64-unknown-elf-gcc
LD = riscv64-unknown-elf-ld
QEMU = qemu-system-riscv64

GDBPORT = 26000

CFLAGS = -Wall -Werror -nostdlib -mcmodel=medany
QEMUFLAGS = -machine virt -nographic -smp 1 -bios none
QEMUGDB = -S -gdb tcp::$(GDBPORT)

KERNEL = kernel.elf
OBJS = \
	entry.o \
	start.o \
	uart.o \
	context_switch.o

.PHONY: kernel
kernel: $(KERNEL)

$(KERNEL): $(OBJS)
	$(LD) -T kernel.ld -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -g -o $@ $^

entry.o: entry.S
	$(CC) $(CFLAGS) -c -g -o $@ $^

.PHONY: qemu
qemu:
	$(QEMU) $(QEMUFLAGS) -kernel $(KERNEL)

.PHONY: qemu-gdb
qemu-gdb:
	$(QEMU) $(QEMUFLAGS) -kernel $(KERNEL) $(QEMUGDB)

.PHONY: clean
clean:
	rm -f *.o *.elf

CC = riscv64-unknown-elf-gcc
LD = riscv64-unknown-elf-ld
QEMU = qemu-system-riscv64
CFLAGS = -Wall -Werror -nostdlib -mcmodel=medany
QEMUFLAGS = -machine virt -nographic -smp 1 -bios none

KERNEL = kernel.elf
OBJS = \
	entry.o \
	start.o \
	uart.o

.PHONY: kernel
kernel: $(KERNEL)

$(KERNEL): $(OBJS)
	$(LD) -T kernel.ld -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

entry.o: entry.S
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: qemu
qemu:
	$(QEMU) $(QEMUFLAGS) -kernel $(KERNEL)

.PHONY: clean
clean:
	rm -f *.o *.elf

CC = riscv64-unknown-elf-gcc
LD = riscv64-unknown-elf-ld
QEMU = qemu-system-riscv64

GDBPORT = 26000

CFLAGS = -std=c17 -Wall -Werror -nostdlib -fno-builtin -mcmodel=medany
QEMUFLAGS = -machine virt -nographic -smp 1 -bios none
QEMUGDB = -S -gdb tcp::$(GDBPORT)

KERNEL = kernel.elf
OBJS = \
	entry.o \
	start.o \
	uart.o \
	context_switch.o \
	print.o \
	timer.o \
	task.o \
	user_tasks.o \
	trap_vector.o \
	trap.o \
	error.o

.PHONY: kernel
kernel: $(KERNEL)

$(KERNEL): $(OBJS)
	$(LD) -T kernel.ld -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -g -o $@ $^

%.o: %.S
	$(CC) $(CFLAGS) -c -g -o $@ $^

.PHONY: qemu
qemu: $(KERNEL)
	$(QEMU) $(QEMUFLAGS) -kernel $(KERNEL)

.PHONY: qemu-gdb
qemu-gdb: $(KERNEL)
	$(QEMU) $(QEMUFLAGS) -kernel $(KERNEL) $(QEMUGDB)

.PHONY: clean
clean:
	rm -f *.o *.elf

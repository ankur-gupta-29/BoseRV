# Module 10 — Booting Linux on BoseRV: Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all build/integration logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

Everything you've built (pipelining, caching, interrupts, virtual memory) is worthless if it can't run real software. **This module runs a full Linux kernel on your processor.**

Boot sequence:
```
1. Power on → Reset vector (0x1000)
2. MROM boot code loads OpenSBI from storage
3. OpenSBI (M-mode firmware) runs
   - Initializes CLINT, UART, memory
   - Sets up page tables for kernel
   - Jumps to Linux kernel entry point
4. Linux kernel (S-mode)
   - Initializes filesystems
   - Starts user-space init
5. User shell (U-mode)
   - User can type commands!
```

---

## Assignment J1 — Understand OpenSBI

**Goal:** Learn what OpenSBI does, how it initializes hardware.

### Concept: OpenSBI (Open Supervisor Binary Interface)

OpenSBI is the **firmware layer** that sits between bootloader and Linux kernel. It:
- Initializes hardware (CLINT, PLIC, UART)
- Handles SBI calls from kernel (like `sbi_console_putchar`)
- Manages exceptions and interrupts in M-mode
- Jumps to kernel at the right physical address

### Step 1 — Examine OpenSBI Source

- [ ] Clone OpenSBI repository:
  ```bash
  git clone https://github.com/riscv-software-src/opensbi.git
  cd opensbi
  ```

- [ ] Read key files:
  - `platform/generic/platform.c` — hardware initialization
  - `firmware/fw_base.S` — boot assembly (where does it jump to?)
  - `lib/sbi/sbi_console.c` — console I/O via UART

- [ ] Key question: How does OpenSBI know where to jump for the kernel?
  - Answer: It's compiled with a fixed `FW_JUMP_ADDR` (usually 0x80200000)

### Step 2 — Compile OpenSBI for BoseRV

- [ ] Create a platform definition for BoseRV:
  ```bash
  mkdir -p platform/boseRV
  cp -r platform/generic/* platform/boseRV/
  ```

- [ ] Modify `objects.mk` and `platform.c` to match BoseRV's memory layout:
  - UART at 0x10000000
  - CLINT at 0x02000000
  - Kernel space at 0x80200000

- [ ] Build OpenSBI:
  ```bash
  make PLATFORM=boseRV CROSS_COMPILE=riscv64-linux-gnu-
  ```

- [ ] Output: `build/platform/boseRV/firmware/fw_jump.bin`

**Concept check:**
> Why does OpenSBI need to know the UART address at compile time?

---

## Assignment J2 — Device Tree Blob (DTB)

**Goal:** Create a device tree that describes your hardware to Linux.

### Concept: Device Tree

Linux doesn't know a priori where your UART is, or how many CPUs you have. The **device tree** is a data structure that describes hardware:

```dts
/dts-v1/;
/ {
  #address-cells = <1>;
  #size-cells = <1>;
  compatible = "riscv,BoseRV";
  model = "BoseRV Single-Core 32-bit RISC-V";

  cpus {
    cpu@0 {
      compatible = "riscv";
      device_type = "cpu";
      reg = <0>;
      status = "okay";
    };
  };

  memory@80000000 {
    device_type = "memory";
    reg = <0x80000000 0x10000000>;  // 256 MB at 0x80000000
  };

  uart0: serial@10000000 {
    compatible = "ns16550a";
    reg = <0x10000000 0x100>;
    clock-frequency = <27000000>;
    interrupts = <10>;
  };

  clint@2000000 {
    compatible = "riscv,clint0";
    reg = <0x02000000 0x10000>;
    interrupts-extended = <&cpu0 3 &cpu0 7>;
  };
};
```

### Step 1 — Create Device Tree for BoseRV

- [ ] Create `boseRV.dts`:
  - Define CPU (single core, RV32I ISA)
  - Define memory range (0x80000000 - 0x8FFFFFFF, 256 MB)
  - Define UART at 0x10000000
  - Define CLINT at 0x02000000

- [ ] Compile to binary:
  ```bash
  dtc -o boseRV.dtb boseRV.dts
  ```

- [ ] Output: `boseRV.dtb` (passed to kernel at boot)

**Concept check:**
> What happens if the DTB says memory ends at 0x8FFFFFFF but the kernel tries to use 0x90000000?

---

## Assignment J3 — Build Linux Kernel (rv32_defconfig)

**Goal:** Build a Linux kernel configured for 32-bit RISC-V.

### Step 1 — Download and Configure Linux

- [ ] Clone Linux kernel:
  ```bash
  git clone https://github.com/torvalds/linux.git
  cd linux
  git checkout v6.1  # Stable release
  ```

- [ ] Configure for 32-bit RISC-V:
  ```bash
  make ARCH=riscv CROSS_COMPILE=riscv64-linux-gnu- rv32_defconfig
  ```

- [ ] Customize if needed:
  ```bash
  make ARCH=riscv CROSS_COMPILE=riscv64-linux-gnu- menuconfig
  # Enable: CONFIG_RISCV_ISA_C=n (no compressed instr if you don't support it)
  # Enable: CONFIG_SERIAL_OF_PLATFORM=y
  ```

- [ ] Build kernel:
  ```bash
  make ARCH=riscv CROSS_COMPILE=riscv64-linux-gnu- -j$(nproc)
  ```

- [ ] Output: `arch/riscv/boot/Image` (kernel binary)

**Concept check:**
> Why does the kernel need to be configured specifically for 32-bit RISC-V?

---

## Assignment J4 — Build Root Filesystem (Buildroot)

**Goal:** Create a minimal root filesystem with shell.

### Concept: Root Filesystem

Linux needs a filesystem with:
- `/bin/init` (first user-space program)
- `/bin/sh` (shell)
- Standard directories (`/dev`, `/proc`, `/sys`, etc)

Buildroot automates this.

### Step 1 — Configure and Build Buildroot

- [ ] Clone Buildroot:
  ```bash
  git clone https://github.com/buildroot/buildroot.git
  cd buildroot
  ```

- [ ] Configure for 32-bit RISC-V:
  ```bash
  make menuconfig
  # Target: RISC-V
  # ISA: rv32i
  # ABI: ilp32
  # System: BusyBox (minimal shell)
  ```

- [ ] Build:
  ```bash
  make -j$(nproc)
  ```

- [ ] Output: `output/images/rootfs.cpio` (root filesystem, CPIO format)

**Concept check:**
> What's the minimum set of files needed in a root filesystem?

---

## Assignment J5 — Create Boot Image & Test on QEMU

**Goal:** Assemble all pieces, verify they boot on QEMU first.

### Step 1 — Create Boot Flash Image

- [ ] Combine OpenSBI, DTB, and kernel into a single image:
  ```bash
  # Pad OpenSBI to 1 MB
  dd if=opensbi/build/platform/boseRV/firmware/fw_jump.bin \
     of=flash.img bs=1M conv=sync
  
  # Append DTB
  dd if=boseRV.dtb of=flash.img bs=1M seek=1 conv=sync
  
  # Append kernel
  dd if=linux/arch/riscv/boot/Image of=flash.img bs=1M seek=2 conv=sync
  
  # Append root filesystem
  dd if=buildroot/output/images/rootfs.cpio of=flash.img bs=1M seek=4 conv=sync
  ```

- [ ] Result: `flash.img` contains everything needed to boot

### Step 2 — Test on QEMU

- [ ] Boot on QEMU to verify everything works:
  ```bash
  qemu-system-riscv32 \
    -M virt \
    -m 256M \
    -kernel opensbi/build/platform/boseRV/firmware/fw_jump.bin \
    -append "root=/dev/vda ro" \
    -drive file=flash.img,format=raw,id=hd0 \
    -device virtio-blk-device,drive=hd0 \
    -nographic \
    -serial stdio
  ```

- [ ] Expected output:
  ```
  OpenSBI console log...
  Linux kernel boot...
  Please press Enter to activate this console.
  / #
  ```

- [ ] You now have a shell! Try:
  ```bash
  ls /
  cat /proc/cpuinfo
  echo "Hello from Linux!"
  ```

**Concept check:**
> What would happen if you swapped the kernel and rootfs in the flash image?

---

## Assignment J6 — Boot on BoseRV Verilator Simulation

**Goal:** Run the same Linux boot sequence on your simulated BoseRV processor.

### Step 1 — Create Verilator C++ Wrapper

- [ ] Create `tb_linux.cpp`:
  ```cpp
  #include "Vpipe_top.h"
  #include <fstream>
  #include <cstring>
  
  int main() {
    Vpipe_top *dut = new Vpipe_top;
    
    // Load flash image into simulated memory
    std::ifstream flash("flash.img", std::ios::binary);
    uint8_t buf[256*1024*1024];
    flash.read((char*)buf, sizeof(buf));
    memcpy(dut->imem->mem, buf, 1024*1024);  // Copy first MB (OpenSBI)
    
    // Reset
    dut->rst = 1;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    dut->rst = 0;
    
    // Run simulation
    for (int cycle = 0; cycle < 1000000000; cycle++) {
      dut->clk = 0;
      dut->eval();
      
      // Check for UART output
      if (dut->uart_tx_valid) {
        printf("%c", (char)dut->uart_tx_data);
        fflush(stdout);
      }
      
      dut->clk = 1;
      dut->eval();
      
      if (cycle % 1000000 == 0) {
        fprintf(stderr, "Cycle %d, PC=0x%08x\n", cycle, dut->pc);
      }
    }
    
    delete dut;
    return 0;
  }
  ```

- [ ] Compile Verilator testbench:
  ```bash
  verilator --exe --cc --trace pipe_top.v tb_linux.cpp -o tb_linux
  cd obj_dir && make -f Vpipe_top.mk
  ```

- [ ] Run simulation:
  ```bash
  ./tb_linux 2>&1 | tee boot.log
  ```

- [ ] Expected: Linux boot messages appear in simulation output

### Step 2 — Observe Boot Sequence

- [ ] Monitor:
  - `PC` advances (fetch from OpenSBI, then kernel)
  - UART output appears (OpenSBI console log)
  - Timer interrupts fire (seen in CSR writes)
  - Virtual memory page table walks (TLB misses → PTW activity)

- [ ] **Test:** Run full simulation, capture boot messages

**Concept check:**
> Why does booting take so long? (Hint: count instructions from reset to shell prompt.)

---

## Completion Gate

Before calling Module 10 done:
- [ ] OpenSBI compiles for BoseRV platform
- [ ] Device tree describes CPU, memory, UART, CLINT
- [ ] Linux kernel boots on QEMU (sanity check)
- [ ] Buildroot creates minimal root filesystem
- [ ] BoseRV simulation boots Linux and accepts shell input
- [ ] You can type commands and see output
- [ ] You can explain: what's the role of OpenSBI vs Linux kernel?

---

## Files Created/Modified in Module 10

| File | Change |
|------|--------|
| `opensbi/platform/boseRV/` | [NEW] Platform support for BoseRV |
| `boseRV.dts` | [NEW] Device tree for BoseRV |
| `boseRV.dtb` | [NEW] Compiled device tree |
| `flash.img` | [NEW] Boot image (OpenSBI + kernel + rootfs) |
| `tb_linux.cpp` | [NEW] Verilator C++ testbench for Linux boot |

---

## Full Boot Sequence (Detailed)

```
Cycle 0: Reset
  PC = 0x1000 (MROM reset vector)

Cycle 1-1000: MROM code
  MROM loads OpenSBI from flash into RAM at 0x80000000
  PC jumps to 0x80000000 (OpenSBI entry)

Cycle 1001-100000: OpenSBI (M-mode)
  Initialize CLINT, UART, PLIC
  Parse device tree
  Set up supervisor mode for kernel
  Load kernel from flash into memory
  Write satp to enable virtual memory
  Transition to S-mode
  Jump to kernel entry (0x80200000)

Cycle 100001-200000: Linux kernel (S-mode)
  Parse command-line args and device tree
  Initialize memory management
  Set up page tables
  Initialize filesystems
  Start init process (first user-space program)

Cycle 200001+: User shell (U-mode)
  Shell runs
  User can type commands
  Each command spawned as new U-mode process
```

---

## Testing Checklist

- [ ] OpenSBI boots (prints console messages)
- [ ] Linux kernel detects 1 CPU, 256 MB memory
- [ ] Timer interrupts working (kernel does `time dmesg`)
- [ ] Shell prompt appears (`#`)
- [ ] Can run simple commands (`ls`, `echo`, `cat /proc/cpuinfo`)
- [ ] Can write files
- [ ] Multi-tasking works (run multiple commands)

---

## Performance Notes

- Full Linux boot takes ~1 minute in simulation (millions of cycles)
- You can speed up by:
  - Skipping driver initialization (use minimal .dtb)
  - Using ramdisk instead of filesystem (Buildroot `initramfs`)
  - Compiling kernel with `-O2` optimization

---

## Congratulations!

You've built a complete RISC-V processor from scratch and booted Linux on it. You understand:
- Instruction execution (datapath)
- Pipelining and hazard handling
- Caching and memory hierarchy
- Privilege levels and virtual memory
- Exception and interrupt handling
- Real-world firmware (OpenSBI) integration

**What's next?**
- Optimize performance (better branch predictor, L2 cache)
- Add more ISA extensions (floating point, vector)
- Port more sophisticated OS (Zephyr, FreeRTOS)
- Design for synthesis on FPGA

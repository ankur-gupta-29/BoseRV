import sys

# =========================================================================
# BoseRV 2-Pass Assembler  —  FIXED VERSION
# Usage: python3 gen_hex.py <asm_file> [output.hex]
#
# Changes from original:
#   FIX 1 — Strip '#' comments (original only stripped '//')
#            Without this, every comment-only line was counted as an
#            instruction, shifting every label address by N*4 bytes.
#   FIX 2 — SLLI had wrong funct3=0x0 (same as ADDI).
#            Correct funct3 for SLLI is 0x1.
#            Symptom: SLLI assembled as ADDI, test 22 always fails.
#   FIX 3 — Skip assembler directives (lines starting with '.')
#            .section, .global etc. caused "Unknown instruction" errors.
#   FIX 4 — Added NOP pseudo-instruction (= addi x0, x0, 0)
# =========================================================================

def parse_reg(r):
    return int(r.replace('x', '').replace(',', ''))

def assemble_r(funct7, funct3, opcode, parts):
    rd, rs1, rs2 = parse_reg(parts[1]), parse_reg(parts[2]), parse_reg(parts[3])
    return (funct7 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode

def assemble_i(funct3, opcode, parts):
    rd, rs1 = parse_reg(parts[1]), parse_reg(parts[2])
    imm = int(parts[3], 0) & 0xFFF
    return (imm << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode

def assemble_s(funct3, opcode, parts):
    rs2 = parse_reg(parts[1])
    offset_str, rs1_str = parts[2].split('(')
    rs1 = parse_reg(rs1_str.strip(')'))
    imm = int(offset_str, 0) & 0xFFF
    imm11_5 = (imm >> 5) & 0x7F
    imm4_0  = imm & 0x1F
    return (imm11_5 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (imm4_0 << 7) | opcode

def assemble_l(funct3, opcode, parts):
    rd = parse_reg(parts[1])
    offset_str, rs1_str = parts[2].split('(')
    rs1 = parse_reg(rs1_str.strip(')'))
    imm = int(offset_str, 0) & 0xFFF
    return (imm << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode

def assemble_b(funct3, opcode, parts, pc, labels):
    rs1, rs2 = parse_reg(parts[1]), parse_reg(parts[2])
    target = parts[3]
    if target in labels:
        offset = labels[target] - pc
    else:
        offset = int(target, 0)
    offset = offset & 0x1FFF
    imm12    = (offset >> 12) & 0x1
    imm11    = (offset >> 11) & 0x1
    imm10_5  = (offset >>  5) & 0x3F
    imm4_1   = (offset >>  1) & 0xF
    return (imm12 << 31) | (imm10_5 << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (imm4_1 << 8) | (imm11 << 7) | opcode

def assemble_u(opcode, parts):
    rd  = parse_reg(parts[1])
    imm = int(parts[2], 0) & 0xFFFFF
    return (imm << 12) | (rd << 7) | opcode

def assemble_j(opcode, parts, pc, labels):
    rd = parse_reg(parts[1])
    target = parts[2]
    if target in labels:
        offset = labels[target] - pc
    else:
        offset = int(target, 0)
    offset   = offset & 0x1FFFFF
    imm20    = (offset >> 20) & 0x1
    imm19_12 = (offset >> 12) & 0xFF
    imm11    = (offset >> 11) & 0x1
    imm10_1  = (offset >>  1) & 0x3FF
    return (imm20 << 31) | (imm10_1 << 21) | (imm11 << 20) | (imm19_12 << 12) | (rd << 7) | opcode

def strip_comments(line):
    # FIX 1: strip both '#' and '//' comments
    line = line.split('#')[0]
    line = line.split('//')[0]
    return line.strip()

def assemble_line(line, pc, labels):
    parts = line.replace(',', ' ').split()
    if not parts or parts[0].endswith(':'):
        return None
    cmd = parts[0].upper()

    # R-Type
    if cmd == "ADD":  return assemble_r(0x00, 0x0, 0x33, parts)
    if cmd == "SUB":  return assemble_r(0x20, 0x0, 0x33, parts)
    if cmd == "SLL":  return assemble_r(0x00, 0x1, 0x33, parts)
    if cmd == "SLT":  return assemble_r(0x00, 0x2, 0x33, parts)
    if cmd == "SLTU": return assemble_r(0x00, 0x3, 0x33, parts)
    if cmd == "XOR":  return assemble_r(0x00, 0x4, 0x33, parts)
    if cmd == "SRL":  return assemble_r(0x00, 0x5, 0x33, parts)
    if cmd == "SRA":  return assemble_r(0x20, 0x5, 0x33, parts)
    if cmd == "OR":   return assemble_r(0x00, 0x6, 0x33, parts)
    if cmd == "AND":  return assemble_r(0x00, 0x7, 0x33, parts)

    # I-Type ALU
    if cmd == "ADDI":  return assemble_i(0x0, 0x13, parts)
    if cmd == "SLTI":  return assemble_i(0x2, 0x13, parts)
    if cmd == "SLTIU": return assemble_i(0x3, 0x13, parts)
    if cmd == "XORI":  return assemble_i(0x4, 0x13, parts)
    if cmd == "ORI":   return assemble_i(0x6, 0x13, parts)
    if cmd == "ANDI":  return assemble_i(0x7, 0x13, parts)
    # FIX 2: SLLI funct3 must be 0x1, NOT 0x0 (0x0 = ADDI, causing SLLI to silently become ADDI)
    if cmd == "SLLI":  return assemble_i(0x1, 0x13, parts)
    if cmd == "SRLI":  return assemble_i(0x5, 0x13, parts)
    if cmd == "SRAI":  return assemble_i(0x5, 0x13, parts) | (0x20 << 25)

    # Loads / Stores
    if cmd == "LW": return assemble_l(0x2, 0x03, parts)
    if cmd == "LH": return assemble_l(0x1, 0x03, parts)
    if cmd == "LB": return assemble_l(0x0, 0x03, parts)
    if cmd == "LHU": return assemble_l(0x5, 0x03, parts)
    if cmd == "LBU": return assemble_l(0x4, 0x03, parts)
    if cmd == "SW": return assemble_s(0x2, 0x23, parts)
    if cmd == "SH": return assemble_s(0x1, 0x23, parts)
    if cmd == "SB": return assemble_s(0x0, 0x23, parts)

    # Branches
    if cmd == "BEQ":  return assemble_b(0x0, 0x63, parts, pc, labels)
    if cmd == "BNE":  return assemble_b(0x1, 0x63, parts, pc, labels)
    if cmd == "BLT":  return assemble_b(0x4, 0x63, parts, pc, labels)
    if cmd == "BGE":  return assemble_b(0x5, 0x63, parts, pc, labels)
    if cmd == "BLTU": return assemble_b(0x6, 0x63, parts, pc, labels)
    if cmd == "BGEU": return assemble_b(0x7, 0x63, parts, pc, labels)

    # U-Type / J-Type
    if cmd == "LUI":   return assemble_u(0x37, parts)
    if cmd == "AUIPC": return assemble_u(0x17, parts)
    if cmd == "JAL":   return assemble_j(0x6F, parts, pc, labels)
    if cmd == "JALR":  return assemble_i(0x0,  0x67, parts)

    # FIX 4: NOP pseudo-instruction = addi x0, x0, 0
    if cmd == "NOP":
        return 0x00000013

    print(f"  Warning: Unknown instruction '{cmd}' at PC={pc} — skipped", file=sys.stderr)
    return None


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 gen_hex.py <asm_file> [output.hex]")
        sys.exit(1)

    out_file = sys.stdout
    if len(sys.argv) >= 3:
        out_file = open(sys.argv[2], 'w')

    labels = {}
    lines  = []

    # ---------------------------------------------------------------
    # Pass 1: Collect labels and non-empty instruction lines
    # ---------------------------------------------------------------
    pc = 0
    with open(sys.argv[1], 'r') as f:
        for raw_line in f:
            line = strip_comments(raw_line)
            if not line:
                continue                      # skip blank / comment-only lines
            if line.startswith('.'):
                continue                      # FIX 3: skip assembler directives
            if line.endswith(':'):
                labels[line[:-1]] = pc        # record label address
            else:
                lines.append(line)
                pc += 4

    # ---------------------------------------------------------------
    # Pass 2: Assemble instructions
    # ---------------------------------------------------------------
    pc = 0
    out_file.write("@00000000\n")             # Verilog $readmemh start address
    for line in lines:
        machine_code = assemble_line(line, pc, labels)
        if machine_code is not None:
            print(f"{machine_code:08x}", file=out_file)
            pc += 4

    if out_file is not sys.stdout:
        out_file.close()
        print(f"Done: {pc // 4} instructions assembled → {sys.argv[2]}")
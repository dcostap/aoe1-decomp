from iced_x86 import Decoder, DecoderOptions, Formatter, FormatterSyntax
from pathlib import Path

obj_path = Path(r"C:/Projects/my_decomps/aoe1_attempt3/build/obj/0046DFC0_TPicture.obj")
# We need to read .text section; we can reuse load_coff_section from tools.coff
import sys
sys.path.insert(0, str(Path(__file__).parent / "tools"))
from coff import load_coff_section

section = load_coff_section(obj_path, ".text")
code = section.data
start_va = 0x0046DFC0  # we can use that as IP

decoder = Decoder(32, code, ip=start_va, options=DecoderOptions.NONE)
formatter = Formatter(FormatterSyntax.NASM)

print(f"Decoding {len(code)} bytes from VA 0x{start_va:08X}")
for instruction in decoder:
    offset = instruction.ip - start_va
    next_offset = instruction.next_ip - start_va
    instr_bytes = code[offset:next_offset]
    print(f"{instruction.ip:08X}  {instr_bytes.hex():<16}  {formatter.format(instruction)}")

from coff import load_coff_section
from pathlib import Path
obj_path = Path(r"C:/Projects/my_decomps/aoe1_attempt3/build/obj/0046DFC0_TPicture.obj")
section = load_coff_section(obj_path, ".text")
data = section.data
print(f".text size: {len(data)}")
print("Hex:", data.hex())
# Also dump first 100 bytes as ints
print("Bytes:", list(data[:100]))

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent / "tools"))
from coff import load_coff_section

obj_path = Path(r"C:/Projects/my_decomps/aoe1_attempt3/build/obj/0046DFC0_TPicture.obj")
section = load_coff_section(obj_path, ".text")
data = section.data
print(f".text size: {len(data)}")
print("Bytes hex:", data.hex())
# print first 100 as ints
print("First 100 bytes:", list(data[:100]))
# Also print offset summary: compare with expected 85
expected = 85
if len(data) < expected:
    print(f"Short by {expected - len(data)} bytes")
elif len(data) > expected:
    print(f"Over by {len(data) - expected} bytes")
else:
    print("Size matches expected")

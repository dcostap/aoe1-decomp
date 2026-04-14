"""
Wave 10 auto-classifier: reads inventory packets, decodes hex patterns,
generates .cpp and .rsp files for all unclaimed __thiscall named <=15B functions.
"""
import csv, os, re, struct, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def read_packet(va, slug):
    prefix = va[:4]
    path = os.path.join(ROOT, 'inventory', 'functions', prefix, slug + '.txt')
    if not os.path.exists(path):
        return None
    with open(path) as f:
        return f.read()

def extract_hex(text):
    asm_lines = re.findall(r'^\s+[0-9A-Fa-f]+\s+([0-9a-f]+)\s+', text, re.M)
    return ''.join(asm_lines).upper()

def extract_class(text, name):
    m = re.search(r'(\w+)::' + re.escape(name), text)
    return m.group(1) if m else None

def le32(hx, pos):
    """Read little-endian 32-bit unsigned from hex string at byte position."""
    s = hx[pos*2:pos*2+8]
    if len(s) != 8:
        raise ValueError("le32 at pos %d: need 8 hex chars, got %d from hx=%s" % (pos, len(s), hx))
    return struct.unpack('<I', bytes.fromhex(s))[0]

def le16(hx, pos):
    s = hx[pos*2:pos*2+4]
    return struct.unpack('<H', bytes.fromhex(s))[0]

def u8(hx, pos):
    return int(hx[pos*2:(pos+1)*2], 16)

# --- Source generators ---

def make_gap(offset):
    """Generate gap/padding for a class stub up to the given offset."""
    if offset == 0:
        return ""
    return "    char gap_0[0x%X];\n" % offset

def make_class_stub(cls, body, has_vtable=True):
    """Generate a minimal class stub."""
    lines = ["class %s {\npublic:\n" % cls]
    if has_vtable:
        lines.append("    virtual ~%s();\n" % cls)
    lines.append(body)
    lines.append("};\n")
    return ''.join(lines)

def gen_file(va, slug, cls, method_decl, method_impl, has_vtable=True, class_body="", extra_pre="", flags="/nologo /c /O2"):
    """Write a .cpp and .rsp file."""
    src_path = os.path.join(ROOT, 'src', 'scratch', '%s.cpp' % slug)
    rsp_path = os.path.join(ROOT, 'config', 'flags', '%s.rsp' % slug)
    if os.path.exists(src_path):
        return False  # skip existing

    # Build source
    parts = []
    if extra_pre:
        parts.append(extra_pre + "\n")
    parts.append("class %s {\npublic:\n" % cls)
    if has_vtable:
        parts.append("    virtual ~%s();\n" % cls)
    parts.append(class_body)
    parts.append("    %s\n" % method_decl)
    parts.append("};\n\n")
    parts.append(method_impl + "\n")

    with open(src_path, 'w', newline='\n') as f:
        f.write(''.join(parts))
    with open(rsp_path, 'w', newline='\n') as f:
        f.write(flags + "\n")
    return True

def classify_and_generate(row, text, hx, cls):
    """Attempt to classify hex pattern and generate source. Returns True if generated."""
    va = row['va']
    slug = row['slug']
    name = row['name']
    size = int(row['size_bytes'])
    
    # === 1B: C3 (empty void, no params) ===
    if hx == 'C3':
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() {}" % (cls, name))

    # === 3B: C2XXXX (empty void with params) ===
    if size == 3 and hx[:2] == 'C2':
        param_bytes = le16(hx, 1)
        n_params = param_bytes // 4
        params = ', '.join(['int p%d' % i for i in range(n_params)])
        return gen_file(va, slug, cls,
            "void %s(%s);" % (name, params),
            "void %s::%s(%s) {}" % (cls, name, params))

    # === 3B: 33C0C3 (return 0, int) ===
    if hx == '33C0C3':
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return 0; }" % (cls, name))

    # === 3B: 32C0C3 (return 0, uchar) ===
    if hx == '32C0C3':
        return gen_file(va, slug, cls,
            "unsigned char %s();" % name,
            "unsigned char %s::%s() { return 0; }" % (cls, name))

    # === 3B: 8B01C3 (mov eax,[ecx]; ret — offset 0 getter, NO vtable) ===
    if hx == '8B01C3':
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_0; }" % (cls, name),
            has_vtable=False,
            class_body="    int field_0;\n")

    # === 3B: 8BC1C3 (mov eax,ecx; ret — return this) ===
    if hx == '8BC1C3':
        # This returns 'this' pointer as an int or char*
        # Ghidra might say char* — let's use that
        return gen_file(va, slug, cls,
            "char* %s();" % name,
            "char* %s::%s() { return (char*)this; }" % (cls, name),
            has_vtable=False)

    # === 4B: 8B41XX C3 (int getter, small offset) ===
    if size == 4 and hx[:4] == '8B41' and hx[6:8] == 'C3':
        offset = u8(hx, 2)
        has_vt = offset >= 4  # heuristic: if offset >= 4, might have vtable
        # Check if offset suggests vtable at 0
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    int field_%X;\n" % offset)

    # === 4B: D941XX C3 (float getter, small offset) ===
    if size == 4 and hx[:4] == 'D941' and hx[6:8] == 'C3':
        offset = u8(hx, 2)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "float %s();" % name,
            "float %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    float field_%X;\n" % offset)

    # === 4B: 8A41XX C3 (uchar getter, small offset) ===
    if size == 4 and hx[:4] == '8A41' and hx[6:8] == 'C3':
        offset = u8(hx, 2)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "unsigned char %s();" % name,
            "unsigned char %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    unsigned char field_%X;\n" % offset)

    # === 4B: 8D41XX C3 (lea — char*/ref getter, small offset) ===
    if size == 4 and hx[:4] == '8D41' and hx[6:8] == 'C3':
        offset = u8(hx, 2)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "char* %s();" % name,
            "char* %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    char field_%X[1];\n" % offset)

    # === 4B: FF41XX C3 (inc dword [ecx+XX]; ret) ===
    if size == 4 and hx[:4] == 'FF41' and hx[6:8] == 'C3':
        offset = u8(hx, 2)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() { this->field_%X++; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    int field_%X;\n" % offset)

    # === 4B: 83C8FF C3 (or eax,-1; ret — return -1) ===
    if hx == '83C8FFC3':
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return -1; }" % (cls, name))

    # === 4B: 6633C0 C3 (xor ax,ax; ret — return 0 short) ===
    if hx == '6633C0C3':
        return gen_file(va, slug, cls,
            "short %s();" % name,
            "short %s::%s() { return 0; }" % (cls, name))

    # === 4B: 66FF01 C3 (inc word [ecx]; ret — short increment, no vtable) ===
    if hx == '66FF01C3':
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() { this->field_0++; }" % (cls, name),
            has_vtable=False,
            class_body="    short field_0;\n")

    # === 5B: 33C0 C2XXXX (return 0 int with params) ===
    if size == 5 and hx[:4] == '33C0' and hx[4:6] == 'C2':
        param_bytes = le16(hx, 3)
        n_params = param_bytes // 4
        params = ', '.join(['int p%d' % i for i in range(n_params)])
        return gen_file(va, slug, cls,
            "int %s(%s);" % (name, params),
            "int %s::%s(%s) { return 0; }" % (cls, name, params))

    # === 5B: 32C0 C2XXXX (return 0 uchar with params) ===
    if size == 5 and hx[:4] == '32C0' and hx[4:6] == 'C2':
        param_bytes = le16(hx, 3)
        n_params = param_bytes // 4
        params = ', '.join(['int p%d' % i for i in range(n_params)])
        return gen_file(va, slug, cls,
            "unsigned char %s(%s);" % (name, params),
            "unsigned char %s::%s(%s) { return 0; }" % (cls, name, params))

    # === 5B: E9XXXXXXXX (jmp — destructor thunk or forwarding) ===
    # Skip these — they need special handling (implicit dtor pattern)

    # === 5B: 33C0 8A01 C3 (xor eax,eax; mov al,[ecx]; ret — int from byte@0) ===
    if hx == '33C08A01C3':
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_0; }" % (cls, name),
            has_vtable=False,
            class_body="    unsigned char field_0;\n")

    # === 5B: 668B41XX C3 (mov ax,[ecx+XX]; ret — short getter) ===
    if size == 5 and hx[:6] == '668B41' and hx[8:10] == 'C3':
        offset = u8(hx, 3)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "short %s();" % name,
            "short %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    short field_%X;\n" % offset)

    # === 5B: 8B01 FF60XX (mov eax,[ecx]; jmp [eax+XX] — virtual forwarding) ===
    if size == 5 and hx[:4] == '8B01' and hx[4:8] == 'FF60':
        # Virtual dispatch: this->vtable[XX/4]()
        # Skip — complex pattern
        pass

    # === 6B: 83C8FF C2XXXX (or eax,-1; ret N — return -1 with params) ===
    if size == 6 and hx[:6] == '83C8FF' and hx[6:8] == 'C2':
        param_bytes = le16(hx, 4)
        n_params = param_bytes // 4
        params = ', '.join(['int p%d' % i for i in range(n_params)])
        return gen_file(va, slug, cls,
            "int %s(%s);" % (name, params),
            "int %s::%s(%s) { return -1; }" % (cls, name, params))

    # === 6B: B8XXXXXXXX C3 (mov eax,imm32; ret — return constant) ===
    if size == 6 and hx[:2] == 'B8' and hx[10:12] == 'C3':
        val = le32(hx, 1)
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return %d; }" % (cls, name, val))

    # === 6B: A1XXXXXXXX C3 (mov eax,[addr]; ret — read global) ===
    if size == 6 and hx[:2] == 'A1' and hx[10:12] == 'C3':
        addr = le32(hx, 1)
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return g_%08X; }" % (cls, name, addr),
            extra_pre="extern int g_%08X;" % addr)

    # === 6B: 8B01 40 8901 C3 (mov eax,[ecx]; inc eax; mov [ecx],eax; ret) ===
    if hx == '8B0140890100C3'[:12]:
        # This is IncSessionCount pattern: this->field_0++; with explicit load/store
        pass

    # === 6B: 8B4108 C20400 (mov eax,[ecx+8]; ret 4 — getter ignoring param) ===
    if size == 6 and hx[:6] == '8B4108' and hx[6:12] == 'C20400':
        # This is weird — getter with 1 param but ignores it
        return gen_file(va, slug, cls,
            "int %s(int p0);" % name,
            "int %s::%s(int p0) { return this->field_8; }" % (cls, name),
            has_vtable=True,
            class_body="    int field_8;\n")

    # === 7B: 8B81XXXXXXXX C3 (int getter, large offset) ===
    if size == 7 and hx[:4] == '8B81' and hx[12:14] == 'C3':
        offset = le32(hx, 2)
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    int field_%X;\n" % offset)

    # === 7B: D981XXXXXXXX C3 (float getter, large offset) ===
    if size == 7 and hx[:4] == 'D981' and hx[12:14] == 'C3':
        offset = le32(hx, 2)
        return gen_file(va, slug, cls,
            "float %s();" % name,
            "float %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    float field_%X;\n" % offset)

    # === 7B: 8A81XXXXXXXX C3 (uchar getter, large offset) ===
    if size == 7 and hx[:4] == '8A81' and hx[12:14] == 'C3':
        offset = le32(hx, 2)
        return gen_file(va, slug, cls,
            "unsigned char %s();" % name,
            "unsigned char %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    unsigned char field_%X;\n" % offset)

    # === 7B: 8D81XXXXXXXX C3 (lea — char*/ref, large offset) ===
    if size == 7 and hx[:4] == '8D81' and hx[12:14] == 'C3':
        offset = le32(hx, 2)
        return gen_file(va, slug, cls,
            "char* %s();" % name,
            "char* %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    char field_%X[1];\n" % offset)

    # === 7B: C701XXXXXXXX C3 (mov dword [ecx], imm32; ret — vtable write dtor) ===
    if size == 7 and hx[:4] == 'C701' and hx[12:14] == 'C3':
        vtable_addr = le32(hx, 2)
        return gen_file(va, slug, cls,
            "",  # destructor — no separate decl needed
            "%s::~%s() {}" % (cls, cls),
            has_vtable=True,
            class_body="")

    # === 7B: 668B81XXXXXXXX C3 would be 8B but short — skip edge cases ===

    # === 8B: B8XXXXXXXX C2XXXX (return constant with params) ===
    if size == 8 and hx[:2] == 'B8' and hx[10:12] == 'C2':
        val = le32(hx, 1)
        param_bytes = le16(hx, 6)
        n_params = param_bytes // 4
        params = ', '.join(['int p%d' % i for i in range(n_params)])
        return gen_file(va, slug, cls,
            "int %s(%s);" % (name, params),
            "int %s::%s(%s) { return %d; }" % (cls, name, params, val))

    # === 8B: 0FBF81XXXXXXXX C3 (movsx eax, word [ecx+XX]; ret — short-to-int getter) ===
    if size == 8 and hx[:6] == '0FBF81' and hx[14:16] == 'C3':
        offset = le32(hx, 3)
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    short field_%X;\n" % offset)

    # === 8B: C681XXXXXXXX 00 C3 (mov byte [ecx+XX], 0; ret — clear byte, large offset) ===
    if size == 8 and hx[:4] == 'C681' and hx[12:16] == '00C3':
        offset = le32(hx, 2)
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() { this->field_%X = 0; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    unsigned char field_%X;\n" % offset)

    # === 8B: C681XXXXXXXX 01 C3 (mov byte [ecx+XX], 1; ret — set byte, large offset) ===
    if size == 8 and hx[:4] == 'C681' and hx[12:14] == '01' and hx[14:16] == 'C3':
        offset = le32(hx, 2)
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() { this->field_%X = 1; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    unsigned char field_%X;\n" % offset)

    # === 8B: C741XX 00000000 C3 (mov dword [ecx+XX], 0; ret — clear, small offset) ===
    if size == 8 and hx[:4] == 'C741' and hx[6:14] == '00000000' and hx[14:16] == 'C3':
        offset = u8(hx, 2)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() { this->field_%X = 0; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    int field_%X;\n" % offset)

    # === 8B: 807910XX 0F94C0 C3 (cmp byte [ecx+10h],XX; sete al; ret) — Not quite, let me check ===
    # 807910020F94C0C3 = cmp byte [ecx+10h], 2; sete al; ret
    if size == 8 and hx[:4] == '8079' and hx[8:14] == '0F94C0' and hx[14:16] == 'C3':
        offset = u8(hx, 2)
        cmp_val = u8(hx, 3)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_%X == %d; }" % (cls, name, offset, cmp_val),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    unsigned char field_%X;\n" % offset)

    # === 9B: 33C0 8A81XXXXXXXX C3 (xor eax,eax; mov al,[ecx+XX]; ret — int-from-byte, large offset) ===
    if size == 9 and hx[:4] == '33C0' and hx[4:8] == '8A81' and hx[16:18] == 'C3':
        offset = le32(hx, 4)
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_%X; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    unsigned char field_%X;\n" % offset)

    # === 9B: 8B44240489 01 C20400 (mov eax,[esp+4]; mov [ecx],eax; ret 4 — offset-0 setter, no vtable) ===
    if hx == '8B4424048901C20400':
        return gen_file(va, slug, cls,
            "void %s(int v);" % name,
            "void %s::%s(int v) { this->field_0 = v; }" % (cls, name),
            has_vtable=False,
            class_body="    int field_0;\n")

    # === 9B: 8BC1 C700XXXXXXXX C3 (mov eax,ecx; mov dword [eax], imm; ret — ctor pattern) ===
    if size == 9 and hx[:4] == '8BC1' and hx[4:8] == 'C700' and hx[16:18] == 'C3':
        vtable_addr = le32(hx, 4)
        # Constructor: sets vtable + returns this
        return gen_file(va, slug, cls,
            "%s();" % cls,
            "%s::%s() {}" % (cls, cls),
            has_vtable=True,
            class_body="")

    # === 10B: 8B442404 8941XX C20400 (int setter, small offset) ===
    if size == 10 and hx[:8] == '8B442404' and hx[8:12] == '8941' and hx[14:20] == 'C20400':
        offset = u8(hx, 6)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "void %s(int v);" % name,
            "void %s::%s(int v) { this->field_%X = v; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    int field_%X;\n" % offset)

    # === 10B: 8A442404 8841XX C20400 (uchar setter, small offset) ===
    if size == 10 and hx[:8] == '8A442404' and hx[8:12] == '8841' and hx[14:20] == 'C20400':
        offset = u8(hx, 6)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "void %s(unsigned char v);" % name,
            "void %s::%s(unsigned char v) { this->field_%X = v; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    unsigned char field_%X;\n" % offset)

    # === 10B: 8B442404 894IXX C20400 where I is 8 (ecx-based setter) ===
    # Already covered by above for 8941

    # === 10B: 8B442404 A3XXXXXXXX C20400 (store param to global; ret 4) ===
    if size == 10 and hx[:8] == '8B442404' and hx[8:10] == 'A3' and hx[18:24] == 'C20400':
        addr = le32(hx, 5)
        return gen_file(va, slug, cls,
            "void %s(int v);" % name,
            "void %s::%s(int v) { g_%08X = v; }" % (cls, name, addr),
            extra_pre="extern int g_%08X;" % addr)

    # === 11B: C781XXXXXXXX YYYYYYYY C3 (write immediate to large offset) ===
    if size == 11 and hx[:4] == 'C781' and hx[20:22] == 'C3':
        offset = le32(hx, 2)
        imm = le32(hx, 6)
        # Determine if imm is 0 or 1 (common patterns)
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() { this->field_%X = %d; }" % (cls, name, offset, imm),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    int field_%X;\n" % offset)

    # === 11B: 8A5114 33C0 84D2 0F95C0 C3 (movzx pattern — bool from byte) ===
    # 8A511433C084D20F95C0C3 = mov dl,[ecx+14h]; xor eax,eax; test dl,dl; setne al; ret
    if size == 11 and hx[:4] == '8A51' and hx[6:10] == '33C0' and hx[10:14] == '84D2' and hx[14:20] == '0F95C0' and hx[20:22] == 'C3':
        offset = u8(hx, 2)
        has_vt = offset >= 4
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_%X != 0; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    unsigned char field_%X;\n" % offset)

    # === 11B: 8B5168 33C0 85D2 0F9FC0 C3 (similar bool pattern with int) ===
    if size == 11 and hx[:4] == '8B51' and hx[6:10] == '33C0' and hx[10:14] == '85D2' and hx[14:20] == '0F9FC0' and hx[20:22] == 'C3':
        offset = u8(hx, 2)
        has_vt = offset >= 4
        # setg = signed greater
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() { return this->field_%X > 0; }" % (cls, name, offset),
            has_vtable=has_vt,
            class_body=make_gap(offset - (4 if has_vt else 0)) + "    int field_%X;\n" % offset)

    # === 11B: 8B4134 C741340000000 C3 (read-then-zero, small offset) ===
    # 8B4134C7413400000000C3 = mov eax,[ecx+34h]; mov dword [ecx+34h], 0; ret
    if size == 11 and hx[:4] == '8B41' and hx[6:10] == 'C741' and hx[18:22] == '00C3':
        offset1 = u8(hx, 2)
        offset2 = u8(hx, 5)
        if offset1 == offset2:
            has_vt = offset1 >= 4
            return gen_file(va, slug, cls,
                "int %s();" % name,
                "int %s::%s() {\n    int v = this->field_%X;\n    this->field_%X = 0;\n    return v;\n}" % (cls, name, offset1, offset1),
                has_vtable=has_vt,
                class_body=make_gap(offset1 - (4 if has_vt else 0)) + "    int field_%X;\n" % offset1)

    # === 13B: 8B442404 8981XXXXXXXX C20400 (int setter, large offset) ===
    if size == 13 and hx[:8] == '8B442404' and hx[8:12] == '8981' and hx[20:26] == 'C20400':
        offset = le32(hx, 6)
        return gen_file(va, slug, cls,
            "void %s(int v);" % name,
            "void %s::%s(int v) { this->field_%X = v; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    int field_%X;\n" % offset)

    # === 13B: 8A442404 8881XXXXXXXX C20400 (uchar setter, large offset) ===
    if size == 13 and hx[:8] == '8A442404' and hx[8:12] == '8881' and hx[20:26] == 'C20400':
        offset = le32(hx, 6)
        return gen_file(va, slug, cls,
            "void %s(unsigned char v);" % name,
            "void %s::%s(unsigned char v) { this->field_%X = v; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    unsigned char field_%X;\n" % offset)

    # === 13B: 8BC1 33C9 66890866894802894804 C3 (constructor — multi-field zero init) ===
    # This is XYZ constructor
    if hx == '8BC133C96689086689480289480400C3'[:26]:
        # Skip complex constructor patterns
        pass

    # === 13B: 8B016AXXFF50XXB801000000C3 (push N; call vtable[XX]; return 1) ===
    # Virtual call + return 1 pattern
    if size == 13 and hx[:4] == '8B01' and hx[4:6] == '6A' and hx[8:12] == 'FF50' and hx[14:24] == 'B801000000' and hx[24:26] == 'C3':
        push_val = u8(hx, 3)
        vtable_offset = u8(hx, 6)
        vtable_slot = vtable_offset // 4
        return gen_file(va, slug, cls,
            "int %s();" % name,
            "int %s::%s() {\n    this->vf%02X(%d);\n    return 1;\n}" % (cls, name, vtable_offset, push_val),
            has_vtable=True,
            class_body="    virtual int vf%02X(int);\n" % vtable_offset)

    # === 13B: 8B016AXXFF505CB801000000C3 (push N; call vtable[5Ch]; return 1) ===
    # Same as above but with specific encoding

    # === 13B: C605XXXXXXXX00 B8XXXXXXXX C3 (write 0 to global, return addr) ===
    if size == 13 and hx[:4] == 'C605' and hx[12:14] == '00' and hx[14:16] == 'B8' and hx[24:26] == 'C3':
        global_addr1 = le32(hx, 2)
        ret_addr = le32(hx, 8)
        if global_addr1 == ret_addr:
            return gen_file(va, slug, cls,
                "char* %s();" % name,
                "char* %s::%s() {\n    g_%08X = 0;\n    return &g_%08X;\n}" % (cls, name, global_addr1, global_addr1),
                extra_pre="extern char g_%08X;" % global_addr1)

    # === 14B patterns ===
    
    # 14B: 8D4C2404 E8XXXXXXXX 33C0 C2XXXX (lea ecx,[esp+4]; call XX; xor eax,eax; ret N)
    # This is the purge* pattern — calls helper with stack params as 'this'
    if size == 14 and hx[:8] == '8D4C2404' and hx[8:10] == 'E8' and hx[18:22] == '33C0' and hx[22:24] == 'C2':
        # This pattern delegates to another function via relative call
        # The call target is relative, so we need to compute it
        # For now, skip these — they need the actual helper function
        pass

    # 14B: 0FBF81XXXXXXXX 50 E803000000 C3 (movsx eax, short [ecx+XX]; push eax; call +3; ret)
    # Actually this is: movsx eax,[ecx+XX]; push eax; call next_func; ret
    # Complex — skip

    # 14B: 8B442404 8B8481XXXXXXXX C20400 (indexed array getter)
    if size == 14 and hx[:8] == '8B442404' and hx[8:12] == '8B84' and hx[14:16] == '81' and hx[24:28] == 'C204':  # need to check encoding
        pass  # complex addressing mode

    if size == 14 and hx[:8] == '8B442404' and hx[8:14] == '8B8481' and hx[22:28] == 'C20400':
        offset = le32(hx, 7)
        return gen_file(va, slug, cls,
            "int %s(int idx);" % name,
            "int %s::%s(int idx) { return this->array_%X[idx]; }" % (cls, name, offset),
            has_vtable=True,
            class_body=make_gap(offset - 4) + "    int array_%X[1];\n" % offset)

    # === 15B: 33C0 8981XXXXXXXX 8981YYYYYYYY C3 (zero two fields) ===
    if size == 15 and hx[:4] == '33C0' and hx[4:8] == '8981' and hx[16:20] == '8981' and hx[28:30] == 'C3':
        off1 = le32(hx, 4)
        off2 = le32(hx, 10)
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() {\n    this->field_%X = 0;\n    this->field_%X = 0;\n}" % (cls, name, off1, off2),
            has_vtable=True,
            class_body=make_gap(off1 - 4) + "    int field_%X;\n" % off1 + make_gap(off2 - off1 - 4) + "    int field_%X;\n" % off2)

    # === 15B: 33C0 894IXX 894IYY 894IZZ 894IWW C3 (zero four fields, small offset) ===
    if size == 15 and hx[:4] == '33C0' and hx[4:8] == '8941' and hx[8:12] == '8941' and hx[12:16] == '8941' and hx[16:20] == '8941' and hx[22:24] == 'C3':
        off1 = u8(hx, 3)
        off2 = u8(hx, 5)
        off3 = u8(hx, 7)
        off4 = u8(hx, 9)
        has_vt = off1 >= 4
        vt_adj = 4 if has_vt else 0
        body = make_gap(off1 - vt_adj)
        body += "    int field_%X;\n" % off1
        body += make_gap(off2 - off1 - 4)
        body += "    int field_%X;\n" % off2
        body += make_gap(off3 - off2 - 4)
        body += "    int field_%X;\n" % off3
        body += make_gap(off4 - off3 - 4)
        body += "    int field_%X;\n" % off4
        return gen_file(va, slug, cls,
            "void %s();" % name,
            "void %s::%s() {\n    this->field_%X = 0;\n    this->field_%X = 0;\n    this->field_%X = 0;\n    this->field_%X = 0;\n}" % (cls, name, off1, off2, off3, off4),
            has_vtable=has_vt,
            class_body=body)

    return False  # could not classify


def main():
    targets = []
    with open(os.path.join(ROOT, 'project_full_status.csv')) as f:
        for row in csv.DictReader(f):
            if (row['source_bucket'] == 'unclaimed' and 
                row['pdb_source_file'] and 
                row['calling_convention'] == '__thiscall' and
                int(row['size_bytes']) <= 15 and
                not row['name'].startswith('FUN_')):
                targets.append(row)

    generated = 0
    skipped_existing = 0
    failed = []

    for t in targets:
        va = t['va']
        slug = t['slug']
        name = t['name']
        prefix = va[:4]

        packet_path = os.path.join(ROOT, 'inventory', 'functions', prefix, slug + '.txt')
        if not os.path.exists(packet_path):
            failed.append((va, name, 'no packet'))
            continue

        with open(packet_path) as f:
            text = f.read()

        hx = extract_hex(text)
        cls = extract_class(text, name)
        if not cls:
            failed.append((va, name, 'no class'))
            continue

        src_path = os.path.join(ROOT, 'src', 'scratch', '%s.cpp' % slug)
        match_path = os.path.join(ROOT, 'src', 'matching', '%s.cpp' % slug)
        if os.path.exists(src_path) or os.path.exists(match_path):
            skipped_existing += 1
            continue

        result = classify_and_generate(t, text, hx, cls)
        if result:
            generated += 1
        else:
            failed.append((va, name, 'unclassified: ' + hx[:30]))

    print("Generated: %d" % generated)
    print("Skipped (existing): %d" % skipped_existing)
    print("Failed: %d" % len(failed))
    if failed:
        print("\nFailed functions:")
        for va, name, reason in failed:
            print("  %s %s: %s" % (va, name, reason))

if __name__ == '__main__':
    main()

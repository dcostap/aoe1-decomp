"""
Batch generator for small __thiscall functions (16-30 bytes).
Reads packets, analyzes asm, generates .cpp and .rsp files.
"""
import csv, os, re, sys

def get_existing_vas():
    vas = set()
    for d in ['src/matching', 'src/scratch', 'src/almost_matched']:
        if os.path.isdir(d):
            for f in os.listdir(d):
                if f.endswith('.cpp'):
                    vas.add(f.split('_')[0])
    return vas

def get_target_funcs():
    existing = get_existing_vas()
    funcs = []
    with open('project_full_status.csv', newline='') as f:
        for row in csv.DictReader(f):
            if row['source_bucket'] != 'unclaimed': continue
            sz = int(row['size_bytes'])
            va = row['va']
            cc = row.get('calling_convention','')
            src = row.get('pdb_source_file','')
            if 16 <= sz <= 30 and cc == '__thiscall' and va not in existing and src and src != '(no source)':
                name = row['name']
                pkt = os.path.join('inventory','functions',va[:4],va+'_'+name+'.txt')
                if os.path.exists(pkt):
                    funcs.append({'va': va, 'name': name, 'size': sz, 'src': src, 'pkt': pkt})
    return funcs

def parse_packet(pkt_path):
    with open(pkt_path) as f:
        content = f.read()
    
    # Parse asm
    asm_lines = []
    if '=== OriginalAsm ===' in content:
        asm_section = content.split('=== OriginalAsm ===')[1]
        end_idx = asm_section.find('===')
        if end_idx > 0:
            asm_section = asm_section[:end_idx]
        for line in asm_section.strip().split('\n'):
            line = line.strip()
            if not line: continue
            if re.match(r'^[0-9A-Fa-f]+-[0-9A-Fa-f]+$', line): continue
            m = re.match(r'([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]+)\s+(.*)', line)
            if m:
                asm_lines.append({'addr': m.group(1), 'hex': m.group(2), 'instr': m.group(3).strip()})
    
    # Parse Ghidra for class name
    class_name = None
    ghidra_decomp = ''
    
    if '=== GhidraDecompilerExcerpt ===' in content:
        dec = content.split('=== GhidraDecompilerExcerpt ===')[1]
        end = dec.find('===')
        if end > 0: dec = dec[:end]
        ghidra_decomp = dec.strip()
        # Extract class::method from comment
        m = re.search(r'(\w+)::(\w+)\(', ghidra_decomp)
        if m:
            class_name = m.group(1)
    
    if '=== GhidraListingExcerpt ===' in content:
        listing = content.split('=== GhidraListingExcerpt ===')[1]
        end = listing.find('===')
        if end > 0: listing = listing[:end]
        if not class_name:
            m = re.search(r'(\w+)::(\w+)', listing)
            if m:
                class_name = m.group(1)
    
    return asm_lines, class_name, ghidra_decomp, content

def hx(val):
    """Format hex offset for use in field names."""
    return f"{val:X}"

def hxv(val):
    """Format hex value for code."""
    if val == 0: return "0"
    if val <= 9: return str(val)
    return f"0x{val:X}"

def gen_gap(offset):
    """Generate gap array or nothing if offset is 0."""
    if offset > 0:
        return f"    char gap_0[{hxv(offset)}];\n"
    return ""

def gen_rsp():
    return '/nologo\n/c\n/O2\n'

def gen_rsp_gx():
    return '/nologo\n/c\n/GX\n/O2\n'

def extract_ghidra_field_names(ghidra_decomp, offsets):
    """Try to extract field names from Ghidra decompilation for given offsets."""
    names = {}
    for off in offsets:
        # Look for this->fieldName patterns near the offset
        # Ghidra often uses this->fieldName
        pass
    return names

def generate_function(func, asm_lines, class_name, ghidra_decomp):
    """Generate C++ source for a function based on asm analysis."""
    va = func['va']
    name = func['name']
    
    if not asm_lines:
        return None, None
    
    instrs = [a['instr'] for a in asm_lines]
    n = len(instrs)
    cn = class_name or 'UnknownClass'
    
    # Helper to parse [ecx+XX] offset
    def ecx_off(s):
        m = re.search(r'\[ecx\+([0-9A-Fa-f]+)h?\]', s)
        return int(m.group(1), 16) if m else None
    
    def esi_off(s):
        m = re.search(r'\[esi\+([0-9A-Fa-f]+)h?\]', s)
        return int(m.group(1), 16) if m else None
    
    def eax_off(s):
        m = re.search(r'\[eax\+([0-9A-Fa-f]+)h?\]', s)
        return int(m.group(1), 16) if m else None
    
    def edx_off(s):
        m = re.search(r'\[edx\+([0-9A-Fa-f]+)h?\]', s)
        return int(m.group(1), 16) if m else None
    
    def esp_off(s):
        m = re.search(r'\[esp\+([0-9A-Fa-f]+)h?\]', s)
        return int(m.group(1), 16) if m else None
    
    def vtable_slots(vtable_off):
        """Generate virtual method stubs up to a given vtable offset."""
        slot = vtable_off // 4
        lines = []
        for i in range(slot + 1):
            if i < slot:
                lines.append(f"    virtual void vf{i*4:02X}();")
        return lines
    
    def needs_gx():
        """Check if function likely needs /GX (exception handling) flag."""
        # Constructor patterns calling base ctors with virtual dtors often need GX
        for i in instrs:
            if 'call' in i:
                return False  # check more carefully
        return False
    
    # ============================================================
    # PATTERN: Simple field getter (mov eax,[ecx+XX]; ret)
    # ============================================================
    if n == 2 and re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]) and instrs[1] == 'ret':
        off = ecx_off(instrs[0])
        cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n    int {name}();\n}};\n\nint {cn}::{name}() {{\n    return this->field_{hx(off)};\n}}\n"
        return cpp, 'o2'
    
    # ============================================================
    # PATTERN: movsx/movzx word getter
    # ============================================================
    if n == 2 and re.match(r'mov[sz]x eax,(word|byte) \[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]) and instrs[1] == 'ret':
        m = re.match(r'mov([sz])x eax,(word|byte) \[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        sign = m.group(1)
        size = m.group(2)
        off = int(m.group(3), 16)
        if size == 'word':
            ftype = 'short' if sign == 's' else 'unsigned short'
        else:
            ftype = 'char' if sign == 's' else 'unsigned char'
        cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    {ftype} field_{hx(off)};\n\n    {ftype} {name}();\n}};\n\n{ftype} {cn}::{name}() {{\n    return this->field_{hx(off)};\n}}\n"
        return cpp, 'o2'
    
    # ============================================================
    # PATTERN: lea eax,[ecx+XX]; ret (return pointer to field)
    # ============================================================
    if n == 2 and re.match(r'lea eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]) and instrs[1] == 'ret':
        off = int(re.match(r'lea eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]).group(1), 16)
        cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n    int* {name}();\n}};\n\nint* {cn}::{name}() {{\n    return &this->field_{hx(off)};\n}}\n"
        return cpp, 'o2'
    
    # ============================================================
    # PATTERN: inc/dec dword [ecx+XX]; ret
    # ============================================================
    if n == 2 and instrs[1] == 'ret':
        m = re.match(r'(inc|dec) dword \[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        if m:
            op = m.group(1)
            off = int(m.group(2), 16)
            op_str = '++' if op == 'inc' else '--'
            cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n    void {name}();\n}};\n\nvoid {cn}::{name}() {{\n    this->field_{hx(off)}{op_str};\n}}\n"
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: mov dword [ecx+XX],IMM; ret (set field to constant)
    # ============================================================
    if n == 2 and instrs[1] == 'ret':
        m = re.match(r'mov dword \[ecx\+([0-9A-Fa-f]+)h?\],([0-9A-Fa-f]+)h?', instrs[0])
        if m:
            off = int(m.group(1), 16)
            val = int(m.group(2), 16)
            cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n    void {name}();\n}};\n\nvoid {cn}::{name}() {{\n    this->field_{hx(off)} = {hxv(val)};\n}}\n"
            return cpp, 'o2'
    
    # ============================================================  
    # PATTERN: mov byte [ecx+XX],IMM; ret
    # ============================================================
    if n == 2 and instrs[1] == 'ret':
        m = re.match(r'mov byte \[ecx\+([0-9A-Fa-f]+)h?\],([0-9A-Fa-f]+)h?', instrs[0])
        if m:
            off = int(m.group(1), 16)
            val = int(m.group(2), 16)
            cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    unsigned char field_{hx(off)};\n\n    void {name}();\n}};\n\nvoid {cn}::{name}() {{\n    this->field_{hx(off)} = {val};\n}}\n"
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: mov word [ecx+XX],IMM; ret
    # ============================================================
    if n == 2 and instrs[1] == 'ret':
        m = re.match(r'mov word \[ecx\+([0-9A-Fa-f]+)h?\],([0-9A-Fa-f]+)h?', instrs[0])
        if m:
            off = int(m.group(1), 16)
            val = int(m.group(2), 16)
            cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    short field_{hx(off)};\n\n    void {name}();\n}};\n\nvoid {cn}::{name}() {{\n    this->field_{hx(off)} = {val};\n}}\n"
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: add/sub dword [ecx+XX],IMM; ret
    # ============================================================
    if n == 2 and instrs[1] == 'ret':
        m = re.match(r'(add|sub) dword \[ecx\+([0-9A-Fa-f]+)h?\],([0-9A-Fa-f]+)h?', instrs[0])
        if m:
            op = m.group(1)
            off = int(m.group(2), 16)
            val = int(m.group(3), 16)
            op_c = '+=' if op == 'add' else '-='
            cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n    void {name}();\n}};\n\nvoid {cn}::{name}() {{\n    this->field_{hx(off)} {op_c} {hxv(val)};\n}}\n"
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: mov ecx,[ecx+XX]; jmp ADDR (tail call forwarding to member)
    # ============================================================
    if n == 2 and re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]) and instrs[1].startswith('jmp '):
        off = ecx_off(instrs[0])
        target = instrs[1].split()[1]
        cpp = f"class MemberType {{\npublic:\n    void {name}();\n}};\n\nclass {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n    void {name}();\n}};\n\nvoid {cn}::{name}() {{\n    this->member_{hx(off)}->{name}();\n}}\n"
        return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Setter 4 bytes: mov eax/edx,[esp+4]; mov [ecx+XX],reg; ret 4
    # ============================================================
    if n == 3 and instrs[2] == 'ret 4':
        m0 = re.match(r'mov (eax|edx),\[esp\+4\]', instrs[0])
        if m0:
            reg = m0.group(1)
            m1 = re.match(rf'mov \[ecx\+([0-9A-Fa-f]+)h?\],{reg}', instrs[1])
            if m1:
                off = int(m1.group(1), 16)
                cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n    void {name}(int value);\n}};\n\nvoid {cn}::{name}(int value) {{\n    this->field_{hx(off)} = value;\n}}\n"
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Setter short: mov ax,[esp+4]; mov [ecx+XX],ax; ret 4
    # ============================================================
    if n == 3 and instrs[2] == 'ret 4':
        if instrs[0] == 'mov ax,[esp+4]':
            m1 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],ax', instrs[1])
            if m1:
                off = int(m1.group(1), 16)
                cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    short field_{hx(off)};\n\n    void {name}(short value);\n}};\n\nvoid {cn}::{name}(short value) {{\n    this->field_{hx(off)} = value;\n}}\n"
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Setter byte: mov al,[esp+4]; mov [ecx+XX],al; ret 4
    # ============================================================
    if n == 3 and instrs[2] == 'ret 4':
        if instrs[0] == 'mov al,[esp+4]':
            m1 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],al', instrs[1])
            if m1:
                off = int(m1.group(1), 16)
                cpp = f"class {cn} {{\npublic:\n{gen_gap(off)}    unsigned char field_{hx(off)};\n\n    void {name}(unsigned char value);\n}};\n\nvoid {cn}::{name}(unsigned char value) {{\n    this->field_{hx(off)} = value;\n}}\n"
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Nested getter: mov eax,[ecx+XX]; mov eax,[eax+YY]; ret
    # ============================================================
    if n == 3 and instrs[2] == 'ret':
        m0 = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        m1 = re.match(r'mov eax,\[eax\+([0-9A-Fa-f]+)h?\]', instrs[1]) if m0 else None
        if m0 and m1:
            off1 = int(m0.group(1), 16)
            off2 = int(m1.group(1), 16)
            cpp = (f"class InnerType {{\npublic:\n{gen_gap(off2)}    int field_{hx(off2)};\n}};\n\n"
                   f"class {cn} {{\npublic:\n{gen_gap(off1)}    InnerType* member_{hx(off1)};\n\n"
                   f"    int {name}();\n}};\n\n"
                   f"int {cn}::{name}() {{\n    return this->member_{hx(off1)}->field_{hx(off2)};\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: mov ecx,[ecx+XX]; mov eax,[ecx]; jmp dword [eax+YY]
    # (forward virtual call through member, no args)
    # ============================================================
    if n == 3 and re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]) and instrs[1] == 'mov eax,[ecx]' and re.match(r'jmp dword \[eax\+([0-9A-Fa-f]+)h?\]', instrs[2]):
        off = ecx_off(instrs[0])
        voff = int(re.match(r'jmp dword \[eax\+([0-9A-Fa-f]+)h?\]', instrs[2]).group(1), 16)
        slot = voff // 4
        vlines = []
        for i in range(slot + 1):
            if i < slot:
                vlines.append(f"    virtual void vf{i*4:02X}();")
            else:
                vlines.append(f"    virtual void {name}();")
        vmethods = '\n'.join(vlines)
        cpp = (f"class MemberType {{\npublic:\n{vmethods}\n}};\n\n"
               f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
               f"    void {name}();\n}};\n\n"
               f"void {cn}::{name}() {{\n    this->member_{hx(off)}->{name}();\n}}\n")
        return cpp, 'o2'
    
    # ============================================================
    # PATTERN: mov dword [ecx],VTABLE; mov eax,ecx; ret (simple dtor that sets vtable)
    # ============================================================
    if n == 3 and re.match(r'mov dword \[ecx\],([0-9A-Fa-f]+)h?', instrs[0]) and instrs[1] == 'mov eax,ecx' and instrs[2] == 'ret':
        cpp = (f"class BaseClass {{\npublic:\n    virtual ~BaseClass();\n}};\n\n"
               f"class {cn} : public BaseClass {{\npublic:\n    virtual ~{cn}();\n}};\n\n"
               f"{cn}::~{cn}() {{\n}}\n")
        return cpp, 'gx'
    
    # ============================================================
    # PATTERN: Toggle bool - mov edx,[ecx+OFF]; xor eax,eax; test edx,edx; sete al; mov [ecx+OFF],eax; ret
    # ============================================================
    if n == 6 and instrs[1] == 'xor eax,eax' and instrs[3] == 'sete al' and instrs[5] == 'ret':
        m0 = re.match(r'mov edx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        if m0 and instrs[2] == 'test edx,edx':
            off = int(m0.group(1), 16)
            m4 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],eax', instrs[4])
            if m4 and int(m4.group(1), 16) == off:
                cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                       f"    void {name}();\n}};\n\n"
                       f"void {cn}::{name}() {{\n    this->field_{hx(off)} = (this->field_{hx(off)} == 0);\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Increment with param: mov eax,[ecx+OFF]; mov edx,[esp+4]; add edx,eax / add eax,edx; mov [ecx+OFF],reg; ret 4
    # Also: mov eax,[esp+4]; mov edx,[ecx+OFF]; add/sub edx,eax; mov [ecx+OFF],edx; ret 4
    # ============================================================
    if n == 5 and instrs[4] == 'ret 4':
        # Pattern A: mov eax,[esp+4]; mov edx,[ecx+OFF]; add edx,eax; mov [ecx+OFF],edx
        m0 = re.match(r'mov eax,\[esp\+4\]', instrs[0])
        m1 = re.match(r'mov edx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[1]) if m0 else None
        if m0 and m1:
            off = int(m1.group(1), 16)
            m2_add = re.match(r'add edx,eax', instrs[2])
            m2_sub = re.match(r'sub edx,eax', instrs[2])
            m3 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],edx', instrs[3])
            if m3 and int(m3.group(1), 16) == off:
                if m2_add:
                    cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                           f"    void {name}(int value);\n}};\n\n"
                           f"void {cn}::{name}(int value) {{\n    this->field_{hx(off)} += value;\n}}\n")
                    return cpp, 'o2'
                elif m2_sub:
                    cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                           f"    void {name}(int value);\n}};\n\n"
                           f"void {cn}::{name}(int value) {{\n    this->field_{hx(off)} -= value;\n}}\n")
                    return cpp, 'o2'
        
        # Pattern B: mov eax,[ecx+OFF]; mov edx,[esp+4]; add eax,edx; mov [ecx+OFF],eax
        m0b = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        m1b = re.match(r'mov edx,\[esp\+4\]', instrs[1]) if m0b else None
        if m0b and m1b:
            off = int(m0b.group(1), 16)
            if instrs[2] == 'add eax,edx' and re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],eax', instrs[3]):
                cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                       f"    void {name}(int value);\n}};\n\n"
                       f"void {cn}::{name}(int value) {{\n    this->field_{hx(off)} += value;\n}}\n")
                return cpp, 'o2'
            if instrs[2] == 'sub eax,edx' and re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],eax', instrs[3]):
                cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                       f"    void {name}(int value);\n}};\n\n"
                       f"void {cn}::{name}(int value) {{\n    this->field_{hx(off)} -= value;\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: decrementBuildAttempts: mov eax,[ecx+OFF]; dec eax; mov [ecx+OFF],eax; jns short ADDR; mov dword [ecx+OFF],0; ret
    # This is: field--; if (field < 0) field = 0;
    # The load-modify-store pattern (not inc [mem]) means volatile field
    # Actually this may just be because the compiler chose this codegen for the clamp pattern
    # ============================================================
    if n == 6:
        m0 = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        if m0 and instrs[1] == 'dec eax':
            off = int(m0.group(1), 16)
            m2 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],eax', instrs[2])
            if m2 and int(m2.group(1), 16) == off and instrs[3].startswith('jns short'):
                m4 = re.match(r'mov dword \[ecx\+([0-9A-Fa-f]+)h?\],0', instrs[4])
                if m4 and int(m4.group(1), 16) == off and instrs[5] == 'ret':
                    # dec eax is load-modify-store, so the compiler chose not to use dec [mem]
                    # This is because of the jns conditional after - the compiler needs the flags from dec eax
                    cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                           f"    void {name}();\n}};\n\n"
                           f"void {cn}::{name}() {{\n    this->field_{hx(off)}--;\n    if (this->field_{hx(off)} < 0) {{\n        this->field_{hx(off)} = 0;\n    }}\n}}\n")
                    return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Forwarding virtual through member with push arg from esp
    # mov ecx,[ecx+OFF]; mov edx,[esp+4]; push edx; mov eax,[ecx]; call dword [eax+VV]; ret 4
    # ============================================================
    if n == 6 and instrs[5] == 'ret 4':
        m0 = re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        m1 = re.match(r'mov (edx|eax),\[esp\+4\]', instrs[1])
        if m0 and m1:
            reg = m1.group(1)
            if instrs[2] == f'push {reg}' and instrs[3] == 'mov eax,[ecx]':
                m4 = re.match(r'call dword \[eax\+([0-9A-Fa-f]+)h?\]', instrs[4])
                if m4:
                    off = int(m0.group(1), 16)
                    voff = int(m4.group(1), 16)
                    slot = voff // 4
                    vlines = []
                    for i in range(slot + 1):
                        if i < slot:
                            vlines.append(f"    virtual void vf{i*4:02X}();")
                        else:
                            vlines.append(f"    virtual void {name}(int param);")
                    vmethods = '\n'.join(vlines)
                    cpp = (f"class MemberType {{\npublic:\n{vmethods}\n}};\n\n"
                           f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                           f"    void {name}(int param);\n}};\n\n"
                           f"void {cn}::{name}(int param) {{\n    this->member_{hx(off)}->{name}(param);\n}}\n")
                    return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Null-check member then tail-call forwarding
    # mov ecx,[ecx+OFF]; test ecx,ecx; je short ADDR; jmp ADDR; xor eax,eax; ret
    # OR: ... je short ADDR; jmp ADDR; ret (void return)
    # ============================================================
    if n == 6 and re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]) and instrs[1] == 'test ecx,ecx' and instrs[2].startswith('je short'):
        off = ecx_off(instrs[0])
        if instrs[3].startswith('jmp ') and instrs[4] == 'xor eax,eax' and instrs[5] == 'ret':
            # Returns member->method() or 0 if null
            cpp = (f"class MemberType {{\npublic:\n    int {name}();\n}};\n\n"
                   f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                   f"    int {name}();\n}};\n\n"
                   f"int {cn}::{name}() {{\n    if (this->member_{hx(off)}) {{\n        return this->member_{hx(off)}->{name}();\n    }}\n    return 0;\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Null-check + forward void: mov ecx,[ecx+OFF]; test ecx,ecx; je; jmp ADDR; ret
    # ============================================================
    if n == 5 and re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]) and instrs[1] == 'test ecx,ecx' and instrs[2].startswith('je short') and instrs[3].startswith('jmp ') and instrs[4] == 'ret':
        off = ecx_off(instrs[0])
        cpp = (f"class MemberType {{\npublic:\n    void {name}();\n}};\n\n"
               f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
               f"    void {name}();\n}};\n\n"
               f"void {cn}::{name}() {{\n    if (this->member_{hx(off)}) {{\n        this->member_{hx(off)}->{name}();\n    }}\n}}\n")
        return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Null check + forwarding with push 1
    # mov ecx,[ecx+OFF]; test ecx,ecx; je short ADDR; push 1; call ADDR; ret
    # (calls member->method(1) if not null)
    # ============================================================
    if n == 6 and re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0]):
        off = ecx_off(instrs[0])
        if instrs[1] == 'test ecx,ecx' and instrs[2].startswith('je short'):
            if re.match(r'push ([0-9A-Fa-f]+)h?', instrs[3]) and instrs[4].startswith('call ') and instrs[5] == 'ret':
                push_val_m = re.match(r'push ([0-9A-Fa-f]+)h?', instrs[3])
                push_val = int(push_val_m.group(1), 16)
                cpp = (f"class MemberType {{\npublic:\n    void target_method(int param);\n}};\n\n"
                       f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                       f"    void {name}();\n}};\n\n"
                       f"void {cn}::{name}() {{\n    if (this->member_{hx(off)}) {{\n        this->member_{hx(off)}->target_method({push_val});\n    }}\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Null check + forwarding with arg from esp
    # mov eax,[esp+4]; test eax,eax; je short ADDR; mov ecx,[ecx+OFF]; push eax; call ADDR; ret 4
    # OR: mov ecx,[ecx+OFF]; test ecx,ecx; je short; mov eax,[esp+4]; push eax; call ADDR; ret 4; xor eax,eax; ret 4
    # ============================================================
    # Variant 1: test arg first
    if n == 7 and instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'test eax,eax' and instrs[2].startswith('je short'):
        m3 = re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[3])
        if m3 and instrs[4] == 'push eax' and instrs[5].startswith('call ') and instrs[6] == 'ret 4':
            off = int(m3.group(1), 16)
            cpp = (f"class MemberType {{\npublic:\n    void target_method(int param);\n}};\n\n"
                   f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                   f"    void {name}(int param);\n}};\n\n"
                   f"void {cn}::{name}(int param) {{\n    if (param) {{\n        this->member_{hx(off)}->target_method(param);\n    }}\n}}\n")
            return cpp, 'o2'
    
    # Variant 2: test member first, forwarding with arg
    if n == 9:
        m0 = re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        if m0 and instrs[1] == 'test ecx,ecx' and instrs[2].startswith('je short'):
            off = int(m0.group(1), 16)
            if instrs[3] == 'mov eax,[esp+4]' and instrs[4] == 'push eax' and instrs[5].startswith('call ') and instrs[6] == 'ret 4' and instrs[7] == 'xor eax,eax' and instrs[8] == 'ret 4':
                cpp = (f"class MemberType {{\npublic:\n    int target_method(int param);\n}};\n\n"
                       f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                       f"    int {name}(int param);\n}};\n\n"
                       f"int {cn}::{name}(int param) {{\n    if (this->member_{hx(off)}) {{\n        return this->member_{hx(off)}->target_method(param);\n    }}\n    return 0;\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Constructor calling base (push esi; mov esi,ecx; call ADDR; mov eax,esi; pop esi; ret)
    # ============================================================
    if (n == 6 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx' and 
        instrs[2].startswith('call ') and instrs[3] == 'mov eax,esi' and 
        instrs[4] == 'pop esi' and instrs[5] == 'ret'):
        cpp = (f"class BaseClass {{\npublic:\n    BaseClass();\n}};\n\n"
               f"class {cn} : public BaseClass {{\npublic:\n    {cn}();\n}};\n\n"
               f"{cn}::{cn}() : BaseClass() {{\n}}\n")
        return cpp, 'gx'
    
    # ============================================================
    # PATTERN: push esi; mov esi,ecx; call ADDR; mov dword [esi],IMM; mov eax,esi; pop esi; ret
    # Constructor: call base ctor, set vtable
    # ============================================================
    if (n == 7 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx' and
        instrs[2].startswith('call ') and re.match(r'mov dword \[esi\],([0-9A-Fa-f]+)h?', instrs[3]) and
        instrs[4] == 'mov eax,esi' and instrs[5] == 'pop esi' and instrs[6] == 'ret'):
        cpp = (f"class BaseClass {{\npublic:\n    virtual ~BaseClass();\n    BaseClass();\n}};\n\n"
               f"class {cn} : public BaseClass {{\npublic:\n    virtual ~{cn}();\n    {cn}();\n}};\n\n"
               f"{cn}::{cn}() : BaseClass() {{\n}}\n")
        return cpp, 'gx'
    
    # ============================================================
    # PATTERN: Constructor with arg calling base ctor + set vtable
    # mov eax,[esp+4]; push esi; mov esi,ecx; push eax; call ADDR; mov dword [esi],IMM; mov eax,esi; pop esi; ret 4
    # ============================================================
    if (n == 9 and instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'push esi' and 
        instrs[2] == 'mov esi,ecx' and instrs[3] == 'push eax' and instrs[4].startswith('call ') and
        re.match(r'mov dword \[esi\],([0-9A-Fa-f]+)h?', instrs[5]) and
        instrs[6] == 'mov eax,esi' and instrs[7] == 'pop esi' and instrs[8] == 'ret 4'):
        cpp = (f"class BaseClass {{\npublic:\n    virtual ~BaseClass();\n    BaseClass(int param);\n}};\n\n"
               f"class {cn} : public BaseClass {{\npublic:\n    virtual ~{cn}();\n    {cn}(int param);\n}};\n\n"
               f"{cn}::{cn}(int param) : BaseClass(param) {{\n}}\n")
        return cpp, 'gx'
    
    # ============================================================
    # PATTERN: Constructor with arg calling base ctor + set vtable + field write + byte write
    # mov eax,[esp+4]; push esi; mov esi,ecx; push eax; call ADDR; mov dword [esi],IMM; mov byte [esi+OFF],1; mov eax,esi; pop esi; ret 4
    # ============================================================
    if (n == 10 and instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'push esi' and 
        instrs[2] == 'mov esi,ecx' and instrs[3] == 'push eax' and instrs[4].startswith('call ') and
        re.match(r'mov dword \[esi\],([0-9A-Fa-f]+)h?', instrs[5])):
        m6 = re.match(r'mov byte \[esi\+([0-9A-Fa-f]+)h?\],([0-9A-Fa-f]+)h?', instrs[6])
        if m6 and instrs[7] == 'mov eax,esi' and instrs[8] == 'pop esi' and instrs[9] == 'ret 4':
            off = int(m6.group(1), 16)
            val = int(m6.group(2), 16)
            cpp = (f"class BaseClass {{\npublic:\n    virtual ~BaseClass();\n    BaseClass(int param);\n}};\n\n"
                   f"class {cn} : public BaseClass {{\npublic:\n    virtual ~{cn}();\n{gen_gap(off)}    unsigned char field_{hx(off)};\n\n"
                   f"    {cn}(int param);\n}};\n\n"
                   f"{cn}::{cn}(int param) : BaseClass(param) {{\n    this->field_{hx(off)} = {val};\n}}\n")
            return cpp, 'gx'
    
    # ============================================================
    # PATTERN: push esi; mov esi,ecx; call ADDR; pop esi; ret (thiscall forwarding)
    # ============================================================
    if (n == 5 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx' and 
        instrs[2].startswith('call ') and instrs[3] == 'pop esi' and instrs[4] == 'ret'):
        # Method that calls another method on this and returns void
        cpp = (f"class {cn} {{\npublic:\n    void target_method();\n\n"
               f"    void {name}();\n}};\n\n"
               f"void {cn}::{name}() {{\n    this->target_method();\n}}\n")
        return cpp, 'o2'
    
    # ============================================================
    # PATTERN: push esi; mov esi,ecx; call ADDR; mov eax,[esi+OFF]; pop esi; ret
    # Call method then return a field
    # ============================================================
    if (n == 6 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx' and
        instrs[2].startswith('call ') and instrs[4] == 'pop esi' and instrs[5] == 'ret'):
        m3 = re.match(r'mov eax,\[esi\+([0-9A-Fa-f]+)h?\]', instrs[3])
        if m3:
            off = int(m3.group(1), 16)
            cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                   f"    void target_method();\n    int {name}();\n}};\n\n"
                   f"int {cn}::{name}() {{\n    this->target_method();\n    return this->field_{hx(off)};\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: push esi; mov esi,ecx; call ADDR; mov ecx,[esi+OFF]; call ADDR; pop esi; ret
    # Two sequential thiscall calls: first on this, then on a member
    # ============================================================
    if (n == 7 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx' and
        instrs[2].startswith('call ') and instrs[5] == 'pop esi' and instrs[6] == 'ret'):
        m3 = re.match(r'mov ecx,\[esi\+([0-9A-Fa-f]+)h?\]', instrs[3])
        if m3 and instrs[4].startswith('call '):
            off = int(m3.group(1), 16)
            cpp = (f"class MemberType {{\npublic:\n    void target_method2();\n}};\n\n"
                   f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                   f"    void target_method1();\n    void {name}();\n}};\n\n"
                   f"void {cn}::{name}() {{\n    this->target_method1();\n    this->member_{hx(off)}->target_method2();\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: push esi; mov esi,ecx; mov ecx,[esi+OFF]; call ADDR; mov ecx,esi; call ADDR; pop esi; ret
    # Two sequential calls: first on member, then on this
    # ============================================================
    if (n == 8 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx' and
        instrs[4] == 'mov ecx,esi' and instrs[6] == 'pop esi' and instrs[7] == 'ret'):
        m2 = re.match(r'mov ecx,\[esi\+([0-9A-Fa-f]+)h?\]', instrs[2])
        if m2 and instrs[3].startswith('call ') and instrs[5].startswith('call '):
            off = int(m2.group(1), 16)
            cpp = (f"class MemberType {{\npublic:\n    void target_method1();\n}};\n\n"
                   f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                   f"    void target_method2();\n    void {name}();\n}};\n\n"
                   f"void {cn}::{name}() {{\n    this->member_{hx(off)}->target_method1();\n    this->target_method2();\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: push esi; mov esi,ecx; mov ecx,[esi+OFF]; test ecx,ecx; je; call ADDR; mov ecx,esi; call ADDR; pop esi; ret
    # Null-check member, call member method, then call this method
    # ============================================================
    if (n == 10 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx'):
        m2 = re.match(r'mov ecx,\[esi\+([0-9A-Fa-f]+)h?\]', instrs[2])
        if m2 and instrs[3] == 'test ecx,ecx' and instrs[4].startswith('je short') and instrs[5].startswith('call ') and instrs[6] == 'mov ecx,esi' and instrs[7].startswith('call ') and instrs[8] == 'pop esi' and instrs[9] == 'ret':
            off = int(m2.group(1), 16)
            cpp = (f"class MemberType {{\npublic:\n    void target_method1();\n}};\n\n"
                   f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                   f"    void target_method2();\n    void {name}();\n}};\n\n"
                   f"void {cn}::{name}() {{\n    if (this->member_{hx(off)}) {{\n        this->member_{hx(off)}->target_method1();\n    }}\n    this->target_method2();\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Setter with notify (virtual call)
    # mov eax,[esp+4]; mov edx,[ecx]; push 1; mov [ecx+OFF],eax; call dword [edx+VV]; ret 4
    # ============================================================
    if n == 6 and instrs[0] == 'mov eax,[esp+4]' and instrs[5] == 'ret 4':
        m1 = re.match(r'mov edx,\[ecx\]', instrs[1])
        m2 = re.match(r'push ([0-9A-Fa-f]+)h?', instrs[2])
        m3 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],eax', instrs[3])
        m4 = re.match(r'call dword \[edx\+([0-9A-Fa-f]+)h?\]', instrs[4])
        if m1 and m2 and m3 and m4:
            push_val = int(m2.group(1), 16)
            off = int(m3.group(1), 16)
            voff = int(m4.group(1), 16)
            slot = voff // 4
            vlines = []
            for i in range(slot + 1):
                if i < slot:
                    vlines.append(f"    virtual void vf{i*4:02X}();")
                else:
                    vlines.append(f"    virtual void notify(int param);")
            vmethods = '\n'.join(vlines)
            cpp = (f"class {cn} {{\npublic:\n{vmethods}\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                   f"    void {name}(int value);\n}};\n\n"
                   f"void {cn}::{name}(int value) {{\n    this->field_{hx(off)} = value;\n    this->notify({push_val});\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Two-field setter with notify
    # mov eax,[esp+4]; mov edx,[esp+8]; mov [ecx+OFF1],eax; mov eax,[ecx]; push 1; mov [ecx+OFF2],edx; call dword [eax+VV]; ret 8
    # ============================================================
    if n == 8 and instrs[7] == 'ret 8':
        if instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'mov edx,[esp+8]':
            m2 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],eax', instrs[2])
            if m2 and instrs[3] == 'mov eax,[ecx]' and re.match(r'push ([0-9A-Fa-f]+)', instrs[4]):
                m5 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],edx', instrs[5])
                m6 = re.match(r'call dword \[eax\+([0-9A-Fa-f]+)h?\]', instrs[6])
                if m5 and m6:
                    off1 = int(m2.group(1), 16)
                    off2 = int(m5.group(1), 16)
                    voff = int(m6.group(1), 16)
                    push_val = int(re.match(r'push ([0-9A-Fa-f]+)h?', instrs[4]).group(1), 16)
                    slot = voff // 4
                    vlines = []
                    for i in range(slot + 1):
                        if i < slot:
                            vlines.append(f"    virtual void vf{i*4:02X}();")
                        else:
                            vlines.append(f"    virtual void notify(int param);")
                    vmethods = '\n'.join(vlines)
                    max_off = max(off1, off2)
                    # Both fields are after vtable
                    cpp_lines = [f"class {cn} {{", "public:"]
                    cpp_lines.extend(vlines)
                    if off1 < off2:
                        cpp_lines.append(gen_gap(off1).rstrip())
                        cpp_lines.append(f"    int field_{hx(off1)};")
                        gap2 = off2 - off1 - 4
                        if gap2 > 0:
                            cpp_lines.append(f"    char gap_{hx(off1+4)}[{hxv(gap2)}];")
                        cpp_lines.append(f"    int field_{hx(off2)};")
                    else:
                        cpp_lines.append(gen_gap(off2).rstrip())
                        cpp_lines.append(f"    int field_{hx(off2)};")
                        gap2 = off1 - off2 - 4
                        if gap2 > 0:
                            cpp_lines.append(f"    char gap_{hx(off2+4)}[{hxv(gap2)}];")
                        cpp_lines.append(f"    int field_{hx(off1)};")
                    cpp_lines.append(f"")
                    cpp_lines.append(f"    void {name}(int a, int b);")
                    cpp_lines.append(f"}};")
                    cpp_lines.append(f"")
                    cpp_lines.append(f"void {cn}::{name}(int a, int b) {{")
                    cpp_lines.append(f"    this->field_{hx(off1)} = a;")
                    cpp_lines.append(f"    this->field_{hx(off2)} = b;")
                    cpp_lines.append(f"    this->notify({push_val});")
                    cpp_lines.append(f"}}")
                    return '\n'.join(cpp_lines) + '\n', 'o2'
    
    # ============================================================
    # PATTERN: Two-field getter
    # mov edx,[esp+4]; mov eax,[ecx+OFF1]; mov [edx],eax; mov eax,[ecx+OFF2]; mov ecx,[esp+8]; mov [ecx],eax; ret 8
    # ============================================================
    if n == 7 and instrs[6] == 'ret 8':
        if instrs[0] == 'mov edx,[esp+4]':
            m1 = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[1])
            if m1 and instrs[2] == 'mov [edx],eax':
                m3 = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[3])
                if m3 and instrs[4] == 'mov ecx,[esp+8]' and instrs[5] == 'mov [ecx],eax':
                    off1 = int(m1.group(1), 16)
                    off2 = int(m3.group(1), 16)
                    cpp_lines = [f"class {cn} {{", "public:"]
                    if off1 < off2:
                        cpp_lines.append(gen_gap(off1).rstrip())
                        cpp_lines.append(f"    int field_{hx(off1)};")
                        gap2 = off2 - off1 - 4
                        if gap2 > 0:
                            cpp_lines.append(f"    char gap_{hx(off1+4)}[{hxv(gap2)}];")
                        cpp_lines.append(f"    int field_{hx(off2)};")
                    else:
                        cpp_lines.append(gen_gap(off2).rstrip())
                        cpp_lines.append(f"    int field_{hx(off2)};")
                        gap2 = off1 - off2 - 4
                        if gap2 > 0:
                            cpp_lines.append(f"    char gap_{hx(off2+4)}[{hxv(gap2)}];")
                        cpp_lines.append(f"    int field_{hx(off1)};")
                    cpp_lines.append(f"")
                    cpp_lines.append(f"    void {name}(int* out1, int* out2);")
                    cpp_lines.append(f"}};")
                    cpp_lines.append(f"")
                    cpp_lines.append(f"void {cn}::{name}(int* out1, int* out2) {{")
                    cpp_lines.append(f"    *out1 = this->field_{hx(off1)};")
                    cpp_lines.append(f"    *out2 = this->field_{hx(off2)};")
                    cpp_lines.append(f"}}")
                    return '\n'.join(cpp_lines) + '\n', 'o2'
    
    # ============================================================
    # PATTERN: Rehook list loop
    # push esi; mov esi,[ecx+OFF]; test esi,esi; je; mov ecx,[esi]; mov eax,[ecx]; call dword [eax+VV]; mov esi,[esi+4]; test esi,esi; jne; pop esi; ret
    # ============================================================
    if (n == 12 and instrs[0] == 'push esi' and instrs[3].startswith('je short') and
        instrs[10].startswith('jne short') and instrs[11] == 'pop esi'):
        m1 = re.match(r'mov esi,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[1])
        if m1 and instrs[2] == 'test esi,esi':
            off = int(m1.group(1), 16)
            if instrs[4] == 'mov ecx,[esi]' and instrs[5] == 'mov eax,[ecx]':
                m6 = re.match(r'call dword \[eax\+([0-9A-Fa-f]+)h?\]', instrs[6])
                m7 = re.match(r'mov esi,\[esi\+([0-9A-Fa-f]+)h?\]', instrs[7])
                if m6 and m7:
                    voff = int(m6.group(1), 16)
                    next_off = int(m7.group(1), 16)
                    if instrs[8] == 'test esi,esi':
                        slot = voff // 4
                        vlines = []
                        for i in range(slot + 1):
                            if i < slot:
                                vlines.append(f"    virtual void vf{i*4:02X}();")
                            else:
                                vlines.append(f"    virtual void target_method();")
                        vmethods = '\n'.join(vlines)
                        cpp = (f"class NodeType {{\npublic:\n{vmethods}\n}};\n\n"
                               f"struct ListNode {{\n    NodeType* data;\n{gen_gap(next_off)}    ListNode* next;\n}};\n\n"
                               f"class {cn} {{\npublic:\n{gen_gap(off)}    ListNode* list_{hx(off)};\n\n"
                               f"    void {name}();\n}};\n\n"
                               f"void {cn}::{name}() {{\n    ListNode* node = this->list_{hx(off)};\n    while (node) {{\n        node->data->target_method();\n        node = node->next;\n    }}\n}}\n")
                        return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Delete list loop
    # push esi; mov esi,ecx; mov eax,[esi+OFF]; test eax,eax; je; mov ecx,esi; call ADDR; mov eax,[esi+OFF]; test eax,eax; jne; pop esi; ret
    # ============================================================
    if (n == 12 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx' and
        instrs[4].startswith('je short') and instrs[9].startswith('jne short') and
        instrs[10] == 'pop esi' and instrs[11] == 'ret'):
        m2 = re.match(r'mov eax,\[esi\+([0-9A-Fa-f]+)h?\]', instrs[2])
        if m2 and instrs[3] == 'test eax,eax' and instrs[5] == 'mov ecx,esi' and instrs[6].startswith('call '):
            m7 = re.match(r'mov eax,\[esi\+([0-9A-Fa-f]+)h?\]', instrs[7])
            if m7 and instrs[8] == 'test eax,eax':
                off = int(m2.group(1), 16)
                cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                       f"    void remove_item();\n    void {name}();\n}};\n\n"
                       f"void {cn}::{name}() {{\n    while (this->field_{hx(off)}) {{\n        this->remove_item();\n    }}\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Forwarding with add ecx (adjust this pointer)
    # mov eax,[esp+4]; add ecx,IMM; push eax; call ADDR; ret 4
    # OR: add ecx,IMM; mov eax,[esp+4]; push eax; call ADDR; ret 4 (different order)
    # ============================================================
    if n == 5 and instrs[4] == 'ret 4':
        if instrs[0] == 'mov eax,[esp+4]':
            m1 = re.match(r'add ecx,([0-9A-Fa-f]+)h?', instrs[1])
            if m1 and instrs[2] == 'push eax' and instrs[3].startswith('call '):
                adj = int(m1.group(1), 16)
                # this is: ((SubObj*)(((char*)this)+adj))->method(arg)
                # Simplest model: embedded sub-object at offset adj
                cpp = (f"class SubType {{\npublic:\n    void target_method(int param);\n}};\n\n"
                       f"class {cn} {{\npublic:\n{gen_gap(adj)}    SubType sub_{hx(adj)};\n\n"
                       f"    void {name}(int param);\n}};\n\n"
                       f"void {cn}::{name}(int param) {{\n    this->sub_{hx(adj)}.target_method(param);\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Forward with add ecx,IMM + 2 args
    # mov eax,[esp+8]; mov edx,[esp+4]; push eax; push edx; add ecx,IMM; call ADDR; ret 8
    # ============================================================
    if n == 7 and instrs[6] == 'ret 8':
        if instrs[0] == 'mov eax,[esp+8]' and instrs[1] == 'mov edx,[esp+4]':
            m4 = re.match(r'add ecx,([0-9A-Fa-f]+)h?', instrs[4])
            if instrs[2] == 'push eax' and instrs[3] == 'push edx' and m4 and instrs[5].startswith('call '):
                adj = int(m4.group(1), 16)
                cpp = (f"class SubType {{\npublic:\n    void target_method(int a, int b);\n}};\n\n"
                       f"class {cn} {{\npublic:\n{gen_gap(adj)}    SubType sub_{hx(adj)};\n\n"
                       f"    void {name}(int a, int b);\n}};\n\n"
                       f"void {cn}::{name}(int a, int b) {{\n    this->sub_{hx(adj)}.target_method(a, b);\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: 4-arg forwarding (common set_rect etc)
    # mov eax,[esp+10h]; mov edx,[esp+0Ch]; push eax; mov eax,[esp+0Ch]; push edx; mov edx,[esp+0Ch]; push eax; push edx; call ADDR; ret 10h
    # ============================================================
    if n == 10 and instrs[9] == 'ret 10h':
        if (instrs[0] == 'mov eax,[esp+10h]' and instrs[1] == 'mov edx,[esp+0Ch]' and
            instrs[2] == 'push eax' and instrs[3] == 'mov eax,[esp+0Ch]' and
            instrs[4] == 'push edx' and instrs[5] == 'mov edx,[esp+0Ch]' and
            instrs[6] == 'push eax' and instrs[7] == 'push edx' and instrs[8].startswith('call ')):
            cpp = (f"class {cn} {{\npublic:\n    void target_method(int a, int b, int c, int d);\n\n"
                   f"    void {name}(int a, int b, int c, int d);\n}};\n\n"
                   f"void {cn}::{name}(int a, int b, int c, int d) {{\n    this->target_method(a, b, c, d);\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Two-field setter with byte
    # mov eax,[esp+4]; mov dl,[esp+8]; mov [ecx+OFF1],eax; mov [ecx+OFF2],dl; ret 8
    # ============================================================
    if n == 5 and instrs[4] == 'ret 8':
        if instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'mov dl,[esp+8]':
            m2 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],eax', instrs[2])
            m3 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],dl', instrs[3])
            if m2 and m3:
                off1 = int(m2.group(1), 16)
                off2 = int(m3.group(1), 16)
                cpp_lines = [f"class {cn} {{", "public:"]
                if off1 < off2:
                    cpp_lines.append(gen_gap(off1).rstrip())
                    cpp_lines.append(f"    int field_{hx(off1)};")
                    gap = off2 - off1 - 4
                    if gap > 0:
                        cpp_lines.append(f"    char gap_{hx(off1+4)}[{hxv(gap)}];")
                    cpp_lines.append(f"    unsigned char field_{hx(off2)};")
                else:
                    cpp_lines.append(gen_gap(off2).rstrip())
                    cpp_lines.append(f"    unsigned char field_{hx(off2)};")
                    gap = off1 - off2 - 1
                    if gap > 0:
                        cpp_lines.append(f"    char gap_{hx(off2+1)}[{hxv(gap)}];")
                    cpp_lines.append(f"    int field_{hx(off1)};")
                cpp_lines.append(f"")
                cpp_lines.append(f"    void {name}(int a, unsigned char b);")
                cpp_lines.append(f"}};")
                cpp_lines.append(f"")
                cpp_lines.append(f"void {cn}::{name}(int a, unsigned char b) {{")
                cpp_lines.append(f"    this->field_{hx(off1)} = a;")
                cpp_lines.append(f"    this->field_{hx(off2)} = b;")
                cpp_lines.append(f"}}")
                return '\n'.join(cpp_lines) + '\n', 'o2'
    
    # ============================================================
    # PATTERN: Null check nested getter with 0 return
    # mov eax,[ecx+OFF1]; test eax,eax; je; mov eax,[eax+OFF2]; ret; xor eax,eax; ret
    # ============================================================
    if n == 7:
        m0 = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        if m0 and instrs[1] == 'test eax,eax' and instrs[2].startswith('je short'):
            off1 = int(m0.group(1), 16)
            m3 = re.match(r'mov eax,\[eax\+([0-9A-Fa-f]+)h?\]', instrs[3])
            if m3 and instrs[4] == 'ret' and instrs[5] == 'xor eax,eax' and instrs[6] == 'ret':
                off2 = int(m3.group(1), 16)
                cpp = (f"class InnerType {{\npublic:\n{gen_gap(off2)}    int field_{hx(off2)};\n}};\n\n"
                       f"class {cn} {{\npublic:\n{gen_gap(off1)}    InnerType* member_{hx(off1)};\n\n"
                       f"    int {name}();\n}};\n\n"
                       f"int {cn}::{name}() {{\n    if (this->member_{hx(off1)}) {{\n        return this->member_{hx(off1)}->field_{hx(off2)};\n    }}\n    return 0;\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Null check with movsx return
    # mov eax,[ecx+OFF1]; test eax,eax; je; movsx eax,word [eax+OFF2]; ret; xor eax,eax; ret
    # ============================================================
    if n == 7:
        m0 = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        if m0 and instrs[1] == 'test eax,eax' and instrs[2].startswith('je short'):
            off1 = int(m0.group(1), 16)
            m3 = re.match(r'movsx eax,word \[eax\+([0-9A-Fa-f]+)h?\]', instrs[3])
            if m3 and instrs[4] == 'ret' and instrs[5] == 'xor eax,eax' and instrs[6] == 'ret':
                off2 = int(m3.group(1), 16)
                cpp = (f"class InnerType {{\npublic:\n{gen_gap(off2)}    short field_{hx(off2)};\n}};\n\n"
                       f"class {cn} {{\npublic:\n{gen_gap(off1)}    InnerType* member_{hx(off1)};\n\n"
                       f"    int {name}();\n}};\n\n"
                       f"int {cn}::{name}() {{\n    if (this->member_{hx(off1)}) {{\n        return this->member_{hx(off1)}->field_{hx(off2)};\n    }}\n    return 0;\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Null check + deref + vtable call + return 0
    # mov eax,[ecx+OFF]; test eax,eax; je; mov eax,[eax]; mov eax,[eax+VV]; ret; xor eax,eax; ret  (8 instrs)
    # This gets the vtable, then the function pointer from the vtable
    # Actually: it's like return ptr ? ptr->vmethod() : 0  but that's not right
    # Actually: mov eax,[eax] loads vtable ptr, mov eax,[eax+VV] loads slot -> returns func ptr
    # ============================================================
    
    # ============================================================
    # PATTERN: Setter with prev value swap
    # mov eax,[ecx+OFF1]; mov edx,[esp+4]; mov [ecx+OFF1],eax_or_edx... complex
    # mov eax,[ecx+OFF1]; mov edx,[esp+4]; mov [ecx+OFF2],eax; mov [ecx+OFF1],edx; ret 4
    # ============================================================
    if n == 5 and instrs[4] == 'ret 4':
        m0 = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        m1 = re.match(r'mov edx,\[esp\+4\]', instrs[1])
        if m0 and m1:
            off_read = int(m0.group(1), 16)
            m2 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],eax', instrs[2])
            m3 = re.match(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],edx', instrs[3])
            if m2 and m3:
                off_w1 = int(m2.group(1), 16)
                off_w2 = int(m3.group(1), 16)
                # this->field_w1 = this->field_read; this->field_w2 = param;
                offsets = sorted(set([off_read, off_w1, off_w2]))
                cpp_lines = [f"class {cn} {{", "public:"]
                prev_end = 0
                for o in offsets:
                    if o > prev_end:
                        cpp_lines.append(f"    char gap_{hx(prev_end)}[{hxv(o - prev_end)}];")
                    cpp_lines.append(f"    int field_{hx(o)};")
                    prev_end = o + 4
                cpp_lines.append(f"")
                cpp_lines.append(f"    void {name}(int value);")
                cpp_lines.append(f"}};")
                cpp_lines.append(f"")
                cpp_lines.append(f"void {cn}::{name}(int value) {{")
                cpp_lines.append(f"    this->field_{hx(off_w1)} = this->field_{hx(off_read)};")
                cpp_lines.append(f"    this->field_{hx(off_w2)} = value;")
                cpp_lines.append(f"}}")
                return '\n'.join(cpp_lines) + '\n', 'o2'
    
    # ============================================================
    # PATTERN: Forwarding thiscall with arg through push esi pattern
    # mov eax,[esp+4]; push esi; mov esi,ecx; push eax; call ADDR; ... pop esi; ret 4
    # ============================================================
    if (n >= 6 and instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'push esi' and 
        instrs[2] == 'mov esi,ecx' and instrs[3] == 'push eax' and instrs[4].startswith('call ')):
        # After call, various things can happen
        remaining = instrs[5:]
        
        # Variant: call; mov ecx,[esi+OFF]; call; pop esi; ret 4
        if len(remaining) == 4:
            m5 = re.match(r'mov ecx,\[esi\+([0-9A-Fa-f]+)h?\]', remaining[0])
            if m5 and remaining[1].startswith('call ') and remaining[2] == 'pop esi' and remaining[3] == 'ret 4':
                off = int(m5.group(1), 16)
                cpp = (f"class MemberType {{\npublic:\n    void target_method2();\n}};\n\n"
                       f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                       f"    void target_method1(int param);\n    void {name}(int param);\n}};\n\n"
                       f"void {cn}::{name}(int param) {{\n    this->target_method1(param);\n    this->member_{hx(off)}->target_method2();\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Getter through member chain: mov ecx,[ecx+OFF1]; mov eax,[ecx+OFF2]; ret 4
    # where [ecx+OFF2] depends on an arg
    # mov ecx,[ecx+OFF1]; mov eax,[esp+4]; push eax; mov ecx,[ecx+OFF2]; call ADDR; ret 4
    # ============================================================
    if n == 6 and instrs[5] == 'ret 4':
        m0 = re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        if m0 and instrs[1] == 'mov eax,[esp+4]' and instrs[2] == 'push eax':
            m3 = re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[3])
            if m3 and instrs[4].startswith('call '):
                off1 = int(m0.group(1), 16)
                off2 = int(m3.group(1), 16)
                cpp = (f"class InnerInnerType {{\npublic:\n    void target_method(int param);\n}};\n\n"
                       f"class InnerType {{\npublic:\n{gen_gap(off2)}    InnerInnerType* inner_{hx(off2)};\n}};\n\n"
                       f"class {cn} {{\npublic:\n{gen_gap(off1)}    InnerType* member_{hx(off1)};\n\n"
                       f"    void {name}(int param);\n}};\n\n"
                       f"void {cn}::{name}(int param) {{\n    this->member_{hx(off1)}->inner_{hx(off2)}->target_method(param);\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Call method on member with arg: mov eax,[ecx+OFF]; push eax; call; ret 4
    # where push eax pushes the member, not the arg... Wait, let me think.
    # Actually if it's: mov ecx,[ecx+OFF]; mov eax,[esp+4]; push eax; call ADDR; ret 4
    # This is member->call(arg)
    # ============================================================
    
    # ============================================================
    # PATTERN: Array bounds check + indexed access
    # mov eax,[esp+4]; test eax,eax; jl; cmp eax,N; jg/jge; mov eax,[ecx+eax*4+OFF]; ret 4; or eax,-1; ret 4
    # ============================================================
    if n >= 8:
        if instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'test eax,eax' and instrs[2].startswith('jl short'):
            # Check for cmp eax,N
            m3 = re.match(r'cmp eax,([0-9A-Fa-f]+)h?', instrs[3])
            if not m3:
                m3 = re.match(r'cmp eax,(\d+)', instrs[3])
            if m3 and (instrs[4].startswith('jg short') or instrs[4].startswith('jge short')):
                m5 = re.match(r'mov eax,\[ecx\+eax\*4\+([0-9A-Fa-f]+)h?\]', instrs[5])
                if m5 and instrs[6] == 'ret 4':
                    off = int(m5.group(1), 16)
                    limit = int(m3.group(1), 16) if 'h' in instrs[3] else int(m3.group(1))
                    if instrs[4].startswith('jg'):
                        upper = limit
                    else:
                        upper = limit - 1
                    # Return -1 on out of bounds
                    if n >= 9 and (instrs[7] == 'or eax,0FFFFFFFFh' or instrs[7] == 'or eax,FFFFFFFFh') and instrs[8] == 'ret 4':
                        arr_count = upper + 1
                        cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int arr_{hx(off)}[{arr_count}];\n\n"
                               f"    int {name}(int index);\n}};\n\n"
                               f"int {cn}::{name}(int index) {{\n    if (index < 0 || index > {upper}) {{\n        return -1;\n    }}\n    return this->arr_{hx(off)}[index];\n}}\n")
                        return cpp, 'o2'
    
    # Also: cmp eax,[ecx+OFF] for dynamic bounds
    if n >= 8:
        if instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'test eax,eax' and instrs[2].startswith('jl short'):
            m3 = re.match(r'cmp eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[3])
            if m3 and (instrs[4].startswith('jge short')):
                m5 = re.match(r'mov eax,\[ecx\+eax\*4\+([0-9A-Fa-f]+)h?\]', instrs[5])
                if m5 and instrs[6] == 'ret 4':
                    count_off = int(m3.group(1), 16)
                    arr_off = int(m5.group(1), 16)
                    if n >= 9 and (instrs[7] == 'or eax,0FFFFFFFFh' or instrs[7] == 'or eax,FFFFFFFFh') and instrs[8] == 'ret 4':
                        cpp_lines = [f"class {cn} {{", "public:"]
                        if count_off < arr_off:
                            cpp_lines.append(gen_gap(count_off).rstrip())
                            cpp_lines.append(f"    int count_{hx(count_off)};")
                            gap = arr_off - count_off - 4
                            if gap > 0:
                                cpp_lines.append(f"    char gap_{hx(count_off+4)}[{hxv(gap)}];")
                            cpp_lines.append(f"    int* arr_{hx(arr_off)};")
                        else:
                            cpp_lines.append(gen_gap(arr_off).rstrip())
                            cpp_lines.append(f"    int* arr_{hx(arr_off)};")
                            gap = count_off - arr_off - 4
                            if gap > 0:
                                cpp_lines.append(f"    char gap_{hx(arr_off+4)}[{hxv(gap)}];")
                            cpp_lines.append(f"    int count_{hx(count_off)};")
                        cpp_lines.append(f"")
                        cpp_lines.append(f"    int {name}(int index);")
                        cpp_lines.append(f"}};")
                        cpp_lines.append(f"")
                        cpp_lines.append(f"int {cn}::{name}(int index) {{")
                        cpp_lines.append(f"    if (index < 0 || index >= this->count_{hx(count_off)}) {{")
                        cpp_lines.append(f"        return -1;")
                        cpp_lines.append(f"    }}")
                        cpp_lines.append(f"    return this->arr_{hx(arr_off)}[index];")
                        cpp_lines.append(f"}}")
                        return '\n'.join(cpp_lines) + '\n', 'o2'
    
    # ============================================================
    # PATTERN: call then return field (movsx variant)
    # mov ecx,[ecx+OFF]; call ADDR; test al,al; setne al; ret
    # ============================================================
    if n == 5 and instrs[4] == 'ret':
        m0 = re.match(r'mov ecx,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        if m0 and instrs[1].startswith('call ') and instrs[2] == 'test al,al' and instrs[3] == 'setne al':
            off = int(m0.group(1), 16)
            cpp = (f"class MemberType {{\npublic:\n    unsigned char target_method();\n}};\n\n"
                   f"class {cn} {{\npublic:\n{gen_gap(off)}    MemberType* member_{hx(off)};\n\n"
                   f"    int {name}();\n}};\n\n"
                   f"int {cn}::{name}() {{\n    return this->member_{hx(off)}->target_method() != 0;\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Constructor pattern: mov eax,ecx; mov ecx,[esp+4]; mov dword [eax],IMM; mov [eax+OFF],ecx; mov dword [eax+OFF2],0; ret 4
    # ============================================================
    if n == 6 and instrs[0] == 'mov eax,ecx' and instrs[1] == 'mov ecx,[esp+4]' and instrs[5] == 'ret 4':
        m2 = re.match(r'mov dword \[eax\],([0-9A-Fa-f]+)h?', instrs[2])
        m3 = re.match(r'mov \[eax\+([0-9A-Fa-f]+)h?\],ecx', instrs[3])
        m4 = re.match(r'mov dword \[eax\+([0-9A-Fa-f]+)h?\],0', instrs[4])
        if m2 and m3 and m4:
            off1 = int(m3.group(1), 16)
            off2 = int(m4.group(1), 16)
            # This is a constructor: set vtable, set member from param, zero another field
            cpp_lines = [f"class {cn} {{", "public:"]
            cpp_lines.append(f"    virtual void dummy();")
            gap = off1 - 4
            if gap > 0:
                cpp_lines.append(f"    char gap_4[{hxv(gap)}];")
            cpp_lines.append(f"    int field_{hx(off1)};")
            gap2 = off2 - off1 - 4
            if gap2 > 0:
                cpp_lines.append(f"    char gap_{hx(off1+4)}[{hxv(gap2)}];")
            cpp_lines.append(f"    int field_{hx(off2)};")
            cpp_lines.append(f"")
            cpp_lines.append(f"    {cn}(int param);")
            cpp_lines.append(f"}};")
            cpp_lines.append(f"")
            cpp_lines.append(f"{cn}::{cn}(int param) {{")
            cpp_lines.append(f"    this->field_{hx(off1)} = param;")
            cpp_lines.append(f"    this->field_{hx(off2)} = 0;")
            cpp_lines.append(f"}}")
            return '\n'.join(cpp_lines) + '\n', 'o2'
    
    # ============================================================
    # PATTERN: push esi; mov esi,ecx; call; push 0; mov ecx,esi; call; pop esi; ret 4
    # Call method(arg), then call another method(0)
    # Actually: push arg; call method1; push 0; mov ecx,esi; call method2; pop; ret
    # ============================================================
    if (n == 9 and instrs[0] == 'mov eax,[esp+4]' and instrs[1] == 'push esi' and
        instrs[2] == 'mov esi,ecx' and instrs[3] == 'push eax' and instrs[4].startswith('call ') and
        instrs[5] == 'push 0' and instrs[6] == 'mov ecx,esi'):
        if instrs[7].startswith('call '):
            # Need to find the rest
            pass
    
    # ============================================================
    # PATTERN: Getter with indexed array through member
    # mov eax,[ecx+OFF1]; mov ecx,[esp+4]; mov eax,[eax+ecx*4]; ret 4
    # ============================================================
    if n == 4 and instrs[3] == 'ret 4':
        m0 = re.match(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        m1 = re.match(r'mov ecx,\[esp\+4\]', instrs[1])
        if m0 and m1:
            off = int(m0.group(1), 16)
            m2 = re.match(r'mov eax,\[eax\+ecx\*4\]', instrs[2])
            if m2:
                cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int* arr_{hx(off)};\n\n"
                       f"    int {name}(int index);\n}};\n\n"
                       f"int {cn}::{name}(int index) {{\n    return this->arr_{hx(off)}[index];\n}}\n")
                return cpp, 'o2'
    
    # ============================================================
    # PATTERN: push esi; mov esi,ecx; call ADDR; mov eax,[esp+8]; mov [esi+OFF],eax; pop esi; ret 4
    # Call base ctor, then set field from arg
    # ============================================================
    if (n == 7 and instrs[0] == 'push esi' and instrs[1] == 'mov esi,ecx' and
        instrs[2].startswith('call ') and instrs[3] == 'mov eax,[esp+8]' and
        instrs[5] == 'pop esi' and instrs[6] == 'ret 4'):
        m4 = re.match(r'mov \[esi\+([0-9A-Fa-f]+)h?\],eax', instrs[4])
        if m4:
            off = int(m4.group(1), 16)
            cpp = (f"class {cn} {{\npublic:\n{gen_gap(off)}    int field_{hx(off)};\n\n"
                   f"    void base_init();\n    void {name}(int param);\n}};\n\n"
                   f"void {cn}::{name}(int param) {{\n    this->base_init();\n    this->field_{hx(off)} = param;\n}}\n")
            return cpp, 'o2'
    
    # ============================================================
    # PATTERN: Constructor no vtable: mov eax,ecx; mov ecx,[esp+4]; mov dword [eax],IMM; mov dword [eax+OFF1],0; mov [eax+OFF2],ecx; ret 4
    # ============================================================
    if n == 6 and instrs[0] == 'mov eax,ecx' and instrs[1] == 'mov ecx,[esp+4]' and instrs[5] == 'ret 4':
        m2 = re.match(r'mov dword \[eax\],([0-9A-Fa-f]+)h?', instrs[2])
        m3 = re.match(r'mov dword \[eax\+([0-9A-Fa-f]+)h?\],0', instrs[3])
        m4 = re.match(r'mov \[eax\+([0-9A-Fa-f]+)h?\],ecx', instrs[4])
        if m2 and m3 and m4:
            pass  # Already handled above
    
    # ============================================================
    # PATTERN: 3 arg forwarding
    # mov eax,[esp+0Ch]; mov edx,[esp+8]; push eax; mov eax,[esp+8]; push edx; push eax; call ADDR; ret 0Ch
    # ============================================================
    if n == 8 and instrs[7] == 'ret 0Ch':
        if (instrs[0] == 'mov eax,[esp+0Ch]' and instrs[1] == 'mov edx,[esp+8]' and
            instrs[2] == 'push eax' and instrs[3] == 'mov eax,[esp+8]' and
            instrs[4] == 'push edx' and instrs[5] == 'push eax' and instrs[6].startswith('call ')):
            cpp = (f"class {cn} {{\npublic:\n    void target_method(int a, int b, int c);\n\n"
                   f"    void {name}(int a, int b, int c);\n}};\n\n"
                   f"void {cn}::{name}(int a, int b, int c) {{\n    this->target_method(a, b, c);\n}}\n")
            return cpp, 'o2'
    
    return None, None


def main():
    funcs = get_target_funcs()
    print(f"Total target functions: {len(funcs)}")
    
    generated = []
    unclassified = []
    
    for func in funcs:
        asm_lines, class_name, ghidra_decomp, content = parse_packet(func['pkt'])
        cpp, flags = generate_function(func, asm_lines, class_name, ghidra_decomp)
        if cpp:
            generated.append((func, cpp, flags))
        else:
            unclassified.append((func, asm_lines))
    
    print(f"Generated: {len(generated)}")
    print(f"Unclassified: {len(unclassified)}")
    
    if '--generate' in sys.argv:
        count = 0
        for func, cpp, flags in generated:
            va = func['va']
            name = func['name']
            fname = f"{va}_{name}"
            cpp_path = os.path.join('src', 'scratch', fname + '.cpp')
            rsp_path = os.path.join('config', 'flags', fname + '.rsp')
            
            if not os.path.exists(cpp_path):
                with open(cpp_path, 'w', newline='\n') as f:
                    f.write(cpp)
                count += 1
            
            if not os.path.exists(rsp_path):
                rsp_content = gen_rsp_gx() if flags == 'gx' else gen_rsp()
                with open(rsp_path, 'w', newline='\n') as f:
                    f.write(rsp_content)
        
        print(f"Wrote {count} new .cpp files")
    
    if '--list-unclassified' in sys.argv:
        for func, asm_lines in unclassified[:50]:
            instrs = [a['instr'] for a in asm_lines]
            print(f"\n{func['va']} {func['name']} ({func['size']}B):")
            for i in instrs:
                print(f"  {i}")

if __name__ == '__main__':
    main()

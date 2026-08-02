"""
Wave 19: Auto-classifier for 31-50B __thiscall functions.
Reads inventory packets, parses asm mnemonics, generates source.
"""

import csv, os, glob, re, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def load_unclaimed_31_50():
    """Load all unclaimed __thiscall 31-50B functions with packets."""
    va_info = {}
    with open(os.path.join(REPO, 'project_full_status.csv')) as f:
        for row in csv.DictReader(f):
            va_info[row['va']] = row

    funcs = []
    for pkt_path in glob.glob(os.path.join(REPO, 'inventory/functions/*/*.txt')):
        va = os.path.basename(pkt_path).split('_')[0].upper()
        info = va_info.get(va)
        if not info:
            continue
        if info.get('corpus_bucket', 'normal') != 'normal':
            continue
        if info['source_bucket'] in ('matching', 'accepted_drift', 'verified_logic', 'scratch'):
            continue
        if info['calling_convention'] != '__thiscall':
            continue
        sz = int(info['size_bytes'])
        if not (31 <= sz <= 50):
            continue

        with open(pkt_path) as f:
            content = f.read()

        asm_start = content.find('=== OriginalAsm ===')
        ghidra_start = content.find('=== GhidraListingExcerpt ===')
        if asm_start < 0:
            continue
        end = ghidra_start if ghidra_start > asm_start else len(content)
        asm_block = content[asm_start:end]

        instrs = []
        for line in asm_block.split('\n'):
            line = line.split(';', 1)[0].strip()
            m = re.match(r'([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s+(\w+)\s*(.*)', line)
            if m:
                instrs.append({
                    'addr': m.group(1),
                    'bytes': m.group(2),
                    'mnem': m.group(3).lower(),
                    'ops': m.group(4).strip()
                })

        # Extract class from Ghidra
        cls = ''
        if ghidra_start >= 0:
            ghidra = content[ghidra_start:]
            m = re.search(r'(\w+)::\w+', ghidra)
            if m:
                cls = m.group(1)

        funcs.append({
            'va': va,
            'name': info['name'],
            'slug': info.get('slug', '%s_%s' % (va, info['name'])),
            'size': sz,
            'src': info.get('pdb_source_file', ''),
            'cls': cls,
            'instrs': instrs,
            'pkt_path': pkt_path,
            'content': content,
        })

    return funcs


def parse_offset(operand):
    """Extract numeric offset from operand like [ecx+1ACh] or [esi+0Ch]."""
    m = re.search(r'\[(?:ecx|esi|eax|edi|ebx)\+([0-9a-fA-F]+)h?\]', operand)
    if m:
        return int(m.group(1), 16)
    m = re.search(r'\[(?:ecx|esi|eax|edi|ebx)\]', operand)
    if m:
        return 0
    return None


def parse_esp_offset(operand):
    """Extract stack offset from [esp+XXh]."""
    m = re.search(r'\[esp\+([0-9a-fA-F]+)h?\]', operand)
    if m:
        return int(m.group(1), 16)
    return None


def parse_immediate(operand):
    """Extract immediate value."""
    m = re.match(r'([0-9a-fA-F]+)h$', operand)
    if m:
        return int(m.group(1), 16)
    m = re.match(r'(\d+)$', operand)
    if m:
        return int(m.group(1))
    return None


def offset_field(off, typ='int'):
    """Generate field name for a given offset."""
    return 'field_%X' % off


def offset_gap(off):
    """Generate gap declaration up to offset."""
    if off == 0:
        return ''
    return '    char gap_0[0x%X];\n' % off


def offset_gap_from(start, end):
    """Generate gap from start to end offset."""
    size = end - start
    if size <= 0:
        return ''
    return '    char gap_%X[0x%X];\n' % (start, size)


def ret_stack_bytes(instrs):
    """Get ret N value (stack cleanup bytes)."""
    for i in instrs:
        if i['mnem'] == 'ret':
            m = re.match(r'([0-9a-fA-F]+)h?', i['ops'])
            if m:
                return int(m.group(1), 16)
            return 0
    return 0


def num_params(instrs):
    """Estimate number of stack parameters from ret N."""
    n = ret_stack_bytes(instrs)
    return n // 4


def classify_three_field_setter(fn):
    """
    Pattern: mov eax,[esp+4]; mov edx,[esp+8]; mov [ecx+OFF1],eax;
             mov eax,[esp+C]; mov [ecx+OFF2],edx; mov [ecx+OFF3],eax; ret 0Ch
    """
    instrs = fn['instrs']
    if len(instrs) < 7:
        return None

    mnems = [i['mnem'] for i in instrs]
    if mnems[:7] != ['mov', 'mov', 'mov', 'mov', 'mov', 'mov', 'ret']:
        return None

    # Check: first two are loads from esp, next is store, then load, store, store, ret
    if not instrs[0]['ops'].startswith('eax,[esp+'):
        return None
    if not (instrs[1]['ops'].startswith('edx,[esp+') or instrs[1]['ops'].startswith('ecx,[esp+')):
        return None
    if ret_stack_bytes(instrs) != 0x0C:
        return None

    # Extract field offsets from stores
    offsets = []
    field_types = []
    for i in range(2, 6):
        ops = instrs[i]['ops']
        # Check if it's a store to [ecx+X] or [esi+X]
        m = re.search(r'\[(?:ecx|esi)\+([0-9a-fA-F]+)h?\]', ops)
        if m and ('eax' in ops or 'edx' in ops) and ops.index('[') > 0:
            off = int(m.group(1), 16)
            # Check if it's a word/byte/dword store
            if 'word' in instrs[i]['bytes'] or instrs[i]['bytes'].startswith('6689'):
                field_types.append('short')
            else:
                field_types.append('int')
            offsets.append(off)

    if len(offsets) != 3:
        return None

    return {
        'type': 'three_field_setter',
        'offsets': offsets,
        'field_types': ['int', 'int', 'int'],  # Default to int for 4-byte stores
    }


def classify_bounds_check_setter(fn):
    """
    Pattern: mov eax,[esp+4]; test eax,eax; jl END; cmp eax,MAX; jge END;
             mov edx,[esp+8]; ... store ...; END: ret 8
    Covers: indexed writes with bounds check on first param.
    """
    instrs = fn['instrs']
    if len(instrs) < 6:
        return None

    mnems = [i['mnem'] for i in instrs]
    # Pattern: mov test jl cmp jge mov ...
    if mnems[0] != 'mov' or mnems[1] != 'test' or mnems[3] != 'cmp':
        return None
    if mnems[2] not in ('jl', 'jle') or mnems[4] not in ('jge', 'jg', 'jle'):
        return None

    # Extract max bound
    max_val = parse_immediate(instrs[3]['ops'].split(',')[-1])
    if max_val is None:
        return None

    # Find the store pattern after bounds check
    # Could be: add+shl+mov (T_Scenario indexed), or direct indexed
    remaining = instrs[5:]
    rem_mnems = [i['mnem'] for i in remaining]

    # Check for add+shl+mov (T_Scenario pattern)
    if 'add' in rem_mnems and 'shl' in rem_mnems:
        # T_Scenario indexed array: add eax,CONST; shl eax,N; mov [eax+ecx],edx; ret
        add_idx = rem_mnems.index('add')
        add_ops = remaining[add_idx]['ops']
        m = re.search(r'eax,([0-9a-fA-F]+)h?', add_ops)
        add_const = int(m.group(1), 16) if m else 0

        shl_idx = rem_mnems.index('shl')
        shl_ops = remaining[shl_idx]['ops']
        m = re.search(r'eax,([0-9a-fA-F]+)h?', shl_ops)
        if not m:
            m = re.search(r'eax,(\d+)', shl_ops)
        shl_amount = int(m.group(1), 16 if 'h' in shl_ops else 10) if m else 0

        return {
            'type': 'bounds_indexed_setter_shl',
            'max_val': max_val,
            'add_const': add_const,
            'shl_amount': shl_amount,
        }

    # Direct indexed: mov [ecx+eax*4+OFF],edx or similar
    for i in remaining:
        m = re.search(r'\[ecx\+eax\*(\d)\+([0-9a-fA-F]+)h?\]', i['ops'])
        if m:
            stride = int(m.group(1))
            base_off = int(m.group(2), 16)
            return {
                'type': 'bounds_indexed_setter_direct',
                'max_val': max_val,
                'stride': stride,
                'base_off': base_off,
            }

    return {
        'type': 'bounds_check_generic',
        'max_val': max_val,
    }


def classify_multi_compare(fn):
    """
    Pattern: mov eax,[esp+4]; cmp eax,V1; je RET1; cmp eax,V2; je RET1; ...
    Returns 1 if param matches any value, 0 otherwise.
    """
    instrs = fn['instrs']
    if len(instrs) < 6:
        return None

    mnems = [i['mnem'] for i in instrs]
    if mnems[0] != 'mov' or mnems[1] != 'cmp' or mnems[2] != 'je':
        return None
    if mnems[3] != 'cmp' or mnems[4] != 'je':
        return None

    # Count the comparison chain
    values = []
    idx = 1
    while idx + 1 < len(instrs) and instrs[idx]['mnem'] == 'cmp' and instrs[idx+1]['mnem'] == 'je':
        val_str = instrs[idx]['ops'].split(',')[-1]
        val = parse_immediate(val_str)
        if val is not None:
            values.append(val)
        idx += 2

    if len(values) < 2:
        return None

    # Check what happens after the chain: return 0, then at target: return 1
    # Or similar boolean pattern
    return {
        'type': 'multi_compare',
        'values': values,
    }


def classify_constructor_base_call(fn):
    """
    Pattern: mov eax,[esp+8]; push esi; mov esi,ecx; push IMM; mov ecx,[esp+0Ch]; push eax; push ecx;
             mov ecx,esi; call BASE_CTOR; mov dword [esi],VTABLE; mov word [esi+4],TYPE; mov eax,esi;
             pop esi; ret ARGS
    """
    instrs = fn['instrs']
    if len(instrs) < 8:
        return None

    mnems = [i['mnem'] for i in instrs]

    # Look for push esi + mov esi,ecx pattern (esi save)
    has_push_esi = False
    for idx, i in enumerate(instrs):
        if i['mnem'] == 'push' and i['ops'] == 'esi':
            has_push_esi = True
            break

    if not has_push_esi:
        return None

    # Look for vtable write: mov dword [esi],IMMEDITATE
    vtable_addr = None
    type_val = None
    type_off = None
    for i in instrs:
        if i['mnem'] == 'mov' and re.match(r'dword \[esi\],([0-9a-fA-F]+)h', i['ops']):
            m = re.match(r'dword \[esi\],([0-9a-fA-F]+)h', i['ops'])
            vtable_addr = int(m.group(1), 16)
        elif i['mnem'] == 'mov' and re.match(r'word \[esi\+([0-9a-fA-F]+)h?\],([0-9a-fA-F]+)h', i['ops']):
            m = re.match(r'word \[esi\+([0-9a-fA-F]+)h?\],([0-9a-fA-F]+)h', i['ops'])
            type_off = int(m.group(1), 16)
            type_val = int(m.group(2), 16)

    if vtable_addr is None:
        return None

    # Look for: mov eax,esi (return this) pattern
    has_return_this = any(i['mnem'] == 'mov' and i['ops'] == 'eax,esi' for i in instrs)
    if not has_return_this:
        return None

    # Count params from ret N
    nparams = num_params(instrs)

    # Look for base call
    has_call = any(i['mnem'] == 'call' for i in instrs)

    return {
        'type': 'constructor_base_call',
        'vtable_addr': vtable_addr,
        'type_val': type_val,
        'type_off': type_off,
        'nparams': nparams,
        'has_base_call': has_call,
    }


def classify_null_check_member_call(fn):
    """
    Pattern: push esi; mov esi,ecx; mov ecx,[esi+OFF]; test ecx,ecx; je SKIP;
             call TARGET; SKIP: ... pop esi; ret
    Null-check a member pointer, then call a method on it.
    """
    instrs = fn['instrs']
    if len(instrs) < 7:
        return None

    mnems = [i['mnem'] for i in instrs]

    # Find push esi; mov esi,ecx
    esi_save = -1
    for idx in range(len(instrs) - 1):
        if instrs[idx]['mnem'] == 'push' and instrs[idx]['ops'] == 'esi' and \
           instrs[idx+1]['mnem'] == 'mov' and instrs[idx+1]['ops'] == 'esi,ecx':
            esi_save = idx
            break

    if esi_save < 0:
        return None

    # Find member load + test + je
    for idx in range(esi_save + 2, len(instrs) - 2):
        if instrs[idx]['mnem'] == 'mov' and 'ecx,[esi+' in instrs[idx]['ops']:
            off = parse_offset(instrs[idx]['ops'].replace('esi', 'ecx').replace('[ecx', '[esi'))
            if off is None:
                m = re.search(r'\[esi\+([0-9a-fA-F]+)h?\]', instrs[idx]['ops'])
                if m:
                    off = int(m.group(1), 16)
            if off is not None and instrs[idx+1]['mnem'] == 'test' and instrs[idx+2]['mnem'] in ('je', 'jne'):
                return {
                    'type': 'null_check_member_call',
                    'member_offset': off,
                }

    return None


def classify_save_forward(fn):
    """
    Pattern: push esi; push edi; mov edi,[esp+0Ch]; mov esi,ecx; push edi; call TARGET; ...
    Save + push args + forward to another function.
    """
    instrs = fn['instrs']
    if len(instrs) < 6:
        return None

    mnems = [i['mnem'] for i in instrs]

    # Look for push esi + (optional push edi) + mov X,ecx + ... + call + ... + pop + ret
    # This is a catch-all for simple forwarding wrappers
    push_count = sum(1 for i in instrs if i['mnem'] == 'push' and i['ops'] in ('esi', 'edi', 'ebx'))
    pop_count = sum(1 for i in instrs if i['mnem'] == 'pop')
    call_count = sum(1 for i in instrs if i['mnem'] == 'call' and 'dword' not in i['ops'])
    vcall_count = sum(1 for i in instrs if i['mnem'] == 'call' and 'dword' in i['ops'])

    if push_count >= 1 and call_count == 1 and vcall_count == 0:
        # Simple direct call forwarding
        return {'type': 'save_forward_direct'}

    return None


def classify_four_word_write(fn):
    """
    Pattern: or eax,-1; mov word [ecx+OFF],ax; mov word [ecx+OFF+2],ax; ...; ret
    Write same value to multiple word fields.
    """
    instrs = fn['instrs']
    if len(instrs) < 4:
        return None

    # Count word-sized stores
    word_stores = []
    for i in instrs:
        if i['mnem'] == 'mov' and 'word' in i['bytes']:
            m = re.search(r'\[ecx\+([0-9a-fA-F]+)h?\]', i['ops'])
            if m:
                word_stores.append(int(m.group(1), 16))

    if len(word_stores) >= 3:
        # Check if there's an 'or eax,-1' or 'xor eax,eax' for the value
        has_init = any(i['mnem'] == 'or' and '0FFFFFFFFh' in i['ops'] for i in instrs)
        has_xor = any(i['mnem'] == 'xor' and i['ops'] == 'eax,eax' for i in instrs)
        if has_init:
            return {'type': 'multi_word_write', 'offsets': word_stores, 'value': -1}
        elif has_xor:
            return {'type': 'multi_word_write', 'offsets': word_stores, 'value': 0}

    return None


def classify_conditional_sub_zero(fn):
    """
    Pattern: mov eax,[ecx+OFF]; mov edx,[esp+4]; cmp eax,edx; jae SUBTRACT;
             mov dword [ecx+OFF],0; ret 4; SUBTRACT: sub eax,edx; mov [ecx+OFF],eax; ret 4
    Subtract if enough, else zero.
    """
    instrs = fn['instrs']
    if len(instrs) < 8:
        return None

    mnems = [i['mnem'] for i in instrs]
    
    # Look for cmp + jae/jb + mov 0 + ret + sub + mov + ret pattern
    has_sub = any(i['mnem'] == 'sub' for i in instrs)
    has_cmp = any(i['mnem'] in ('cmp',) for i in instrs)
    has_jae = any(i['mnem'] in ('jae', 'jnb', 'jb', 'jbe') for i in instrs)
    ret_count = sum(1 for i in instrs if i['mnem'] == 'ret')

    if has_sub and has_cmp and has_jae and ret_count == 2:
        # Find the field offset
        for i in instrs:
            if i['mnem'] == 'mov':
                off = parse_offset(i['ops'])
                if off is not None and off > 0:
                    return {'type': 'conditional_sub_zero', 'field_offset': off}

    return None


def classify_handle_idle_global(fn):
    """
    Pattern: push esi; mov esi,ecx; mov ecx,[GLOBAL]; mov eax,[ecx+OFF]; test eax,eax;
             jne SKIP; call TARGET; SKIP: mov ecx,esi; call TARGET2; pop esi; ret
    """
    instrs = fn['instrs']
    if len(instrs) < 8:
        return None

    mnems = [i['mnem'] for i in instrs]
    if mnems[:6] != ['push', 'mov', 'mov', 'mov', 'test', 'jne']:
        return None

    # Check: push esi; mov esi,ecx; mov ecx,[GLOBAL]; mov eax,[ecx+OFF]
    if instrs[0]['ops'] != 'esi':
        return None
    if instrs[1]['ops'] != 'esi,ecx':
        return None
    if not re.match(r'ecx,\[([0-9a-fA-F]+)h\]', instrs[2]['ops']):
        return None

    return {'type': 'handle_idle_global'}


def generate_source(fn, classification):
    """Generate C++ source for a classified function."""
    cls = fn['cls']
    name = fn['name']
    va = fn['va']

    if not cls:
        return None

    ctype = classification['type']

    if ctype == 'three_field_setter':
        offsets = classification['offsets']
        # Build class with gaps
        lines = []
        lines.append('class %s {' % cls)
        lines.append('public:')

        # Determine field types from instruction encoding
        # All three-field setters at this size use dword (int/float) stores
        fields = []
        prev_end = 0
        for off in sorted(set(offsets)):
            if off > prev_end:
                lines.append('    char gap_%X[0x%X];' % (prev_end, off - prev_end))
            lines.append('    int %s;' % offset_field(off))
            fields.append(off)
            prev_end = off + 4

        # Method declaration
        lines.append('    void %s(int, int, int);' % name)
        lines.append('};')
        lines.append('')

        # Method body - write in ORDER that matches the original asm
        # The original writes field1, field2, field3 in a specific order
        # Parse the actual write order from asm
        write_order = []
        for i in fn['instrs']:
            if i['mnem'] == 'mov':
                for off in offsets:
                    if ('[ecx+%Xh]' % off) in i['ops'] or \
                       ('[ecx+%xh]' % off) in i['ops'] or \
                       ('[esi+%Xh]' % off) in i['ops'] or \
                       ('[esi+%xh]' % off) in i['ops']:
                        if off not in write_order:
                            write_order.append(off)

        # Map params to fields based on write order vs load order
        # Params loaded from esp+4, esp+8, esp+C
        param_names = ['a', 'b', 'c']

        lines.append('void %s::%s(int a, int b, int c) {' % (cls, name))
        # Need to match the exact write order
        # In the three-field setter, the write order corresponds to param order
        for idx, off in enumerate(offsets):
            if idx < 3:
                lines.append('    this->%s = %s;' % (offset_field(off), param_names[idx]))
        lines.append('}')

        return '\n'.join(lines)

    elif ctype == 'multi_word_write':
        offsets = classification['offsets']
        value = classification['value']
        lines = []
        lines.append('class %s {' % cls)
        lines.append('public:')
        prev_end = 0
        for off in sorted(offsets):
            if off > prev_end:
                lines.append('    char gap_%X[0x%X];' % (prev_end, off - prev_end))
            lines.append('    short %s;' % offset_field(off))
            prev_end = off + 2
        lines.append('    void %s();' % name)
        lines.append('};')
        lines.append('')
        lines.append('void %s::%s() {' % (cls, name))
        for off in offsets:
            lines.append('    this->%s = %d;' % (offset_field(off), value))
        lines.append('}')
        return '\n'.join(lines)

    elif ctype == 'conditional_sub_zero':
        off = classification['field_offset']
        lines = []
        lines.append('class %s {' % cls)
        lines.append('public:')
        if off > 0:
            lines.append('    char gap_0[0x%X];' % off)
        lines.append('    unsigned int %s;' % offset_field(off))
        lines.append('    void %s(unsigned int);' % name)
        lines.append('};')
        lines.append('')
        lines.append('void %s::%s(unsigned int amount) {' % (cls, name))
        lines.append('    if (this->%s < amount) {' % offset_field(off))
        lines.append('        this->%s = 0;' % offset_field(off))
        lines.append('    } else {')
        lines.append('        this->%s -= amount;' % offset_field(off))
        lines.append('    }')
        lines.append('}')
        return '\n'.join(lines)

    elif ctype == 'multi_compare':
        values = classification['values']
        lines = []
        lines.append('class %s {' % cls)
        lines.append('public:')
        lines.append('    int %s(int);' % name)
        lines.append('};')
        lines.append('')
        lines.append('int %s::%s(int value) {' % (cls, name))
        conditions = ' || '.join(['value == 0x%X' % v for v in values])
        lines.append('    if (%s)' % conditions)
        lines.append('        return 1;')
        lines.append('    return 0;')
        lines.append('}')
        return '\n'.join(lines)

    return None


def main():
    funcs = load_unclaimed_31_50()
    print('Loaded %d unclaimed 31-50B __thiscall functions with packets' % len(funcs))

    classified = 0
    generated = 0
    unclassified = []

    for fn in funcs:
        result = None

        # Try classifiers in order
        for classifier in [
            classify_three_field_setter,
            classify_four_word_write,
            classify_conditional_sub_zero,
            classify_multi_compare,
            classify_bounds_check_setter,
            classify_null_check_member_call,
            classify_constructor_base_call,
            classify_handle_idle_global,
            classify_save_forward,
        ]:
            result = classifier(fn)
            if result:
                break

        if result:
            classified += 1
            source = generate_source(fn, result)
            if source:
                # Write source file
                cpp_path = os.path.join(REPO, 'src', 'scratch', '%s_%s.cpp' % (fn['va'], fn['name']))
                rsp_path = os.path.join(REPO, 'config', 'flags', '%s_%s.rsp' % (fn['va'], fn['name']))

                if not os.path.exists(cpp_path):
                    with open(cpp_path, 'w') as f:
                        f.write(source + '\n')
                    if not os.path.exists(rsp_path):
                        with open(rsp_path, 'w') as f:
                            f.write('/nologo /c /O2\n')
                    generated += 1
                    print('GEN %s %s (%dB) [%s]' % (fn['va'], fn['name'], fn['size'], result['type']))
            else:
                print('CLASSIFIED but no source: %s %s [%s]' % (fn['va'], fn['name'], result['type']))
        else:
            unclassified.append(fn)

    print()
    print('Classified: %d, Generated: %d, Unclassified: %d' % (classified, generated, len(unclassified)))

    # Show pattern distribution of unclassified
    patterns = {}
    for fn in unclassified:
        sig = ' '.join([i['mnem'] for i in fn['instrs'][:5]])
        patterns.setdefault(sig, []).append(fn)

    print()
    print('Top unclassified patterns:')
    for sig, fns in sorted(patterns.items(), key=lambda x: -len(x[1]))[:15]:
        print('  %3d x %s  e.g. %s %s' % (len(fns), sig, fns[0]['va'], fns[0]['name']))


if __name__ == '__main__':
    main()

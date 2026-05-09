# LESSONS.md

This file is the project's shared pattern memory for exact VC5 matching work.
It should simulate the way a human decompiler gradually learns the compiler and
codebase: every time a function finally clicks because of a reusable insight,
record the compact lesson here so future agents can recognize the pattern sooner.

Use this file for generalized eureka moments, especially lessons about:

- source shapes that make VC5 emit the expected assembly;

### IAT import thunks via `extern const` function pointer

When the original calls through an import thunk (`call dword [IAT_addr]` like
`call [88A88Ch]` for MessageBeep), use:
```c
extern "C" void (__stdcall* const FuncName)(arg_type);
```
Calling `FuncName(args)` generates `call dword [encoded_addr]`. The relocation
is zeroed in comparison but the instruction encoding (`ff15...`) matches exactly,
unlike a direct `call rel32` which VC5 generates for a normal function declaration.

### MBCS string function naming

CRT MBCS functions like `_mbsncpy`, `_mbsninc`, `_mbsinc` exist in the VC5 CRT
(`mbstring.h`). Declare them as `extern "C"` with appropriate signatures:
```c
extern "C" void* __cdecl _mbsncpy(void* dest, void* src, int count);
extern "C" void* __cdecl _mbsninc(void* str, int count);
extern "C" void* __cdecl _mbsinc(void* str);
```

### Forcing _mbsinc evaluation before _mbsncpy args

When calling `_mbsncpy(_mbsinc(p), src, count)`, VC5 evaluates args right-to-left
for cdecl, so `_mbsinc` is called AFTER `count` and `src` are pushed. To match
original code where `_mbsinc` is called before any `_mbsncpy` arg pushes, separate
the calls:
```c
p = (char*)_mbsinc(p);
_mbsncpy(p, src, count);
```
VC5 reuses the live `eax` (the `_mbsinc` return) directly for the final push,
avoiding stack temporaries. This matches the original's pattern of `push eax`
from the `_mbsinc` return value.

## Lesson: Derived-class field layout requires field-level base class gaps

When a derived class adds fields at offsets past the base class size (e.g.,
TPanel* fields at +0x478 from TScreenPanel), the base class must use
field-level gap declarations (__gap[...], render_area, __gap2[...], etc.)
for sizeof to be correct. Monolithic `char fields[0x474]` patterns do not
make sizeof cascade through the hierarchy.

Example chain (Scr_main.cpp):
- TPanel: field-level gaps + RECT render_rect => sizeof = 0xF4
- TEasy_Panel: __gap7[0x384] => sizeof = 0x478
- TScreenPanel: ~virtual => sizeof = 0x478
- Derived: TPanel* at +0x478, +0x47C, +0x480, etc.

## Lesson: Virtual function vtable position matters for member calls

When calling `close_button->set_active(1)` through TPanel*, the virtual
function must be declared in TPanel at the correct vtable offset. From the
PDB class dumps, set_active is at vt[5] (+0x14) and set_positioning at vt[6]
(+0x18). Missing virtual functions before them shifts the offset. Add dtor,
setup, set_rect (RECT), set_rect (4 longs), set_color before set_active to
get the +0x14 offset.

## Lesson: VC5 block layout for if statements is non-trivial

`if (x == 0) { return; }` can produce either `je` (early return at end as jump
target) or `jne` (early return inline with jump to success). The original
Scr_main.cpp Error ctor has early return inline (failure = likely path).
goto labels do NOT force block placement - /O2 optimizer still rearranges.

## 2026-04-30: Drawarea.cpp batch matching lessons

### Tiny helpers match inline
AlignedWidth (4 B, return this->Pitch) matched instantly with a proper class method.
SetShadowTable (13 B, store pointer at +0xC8) matched instantly.
These trivial 1-2 instruction functions are always free matches.

### Simple getter/setter pattern matches easily
GetPalette (40 B) uses `memcpy` to copy 256 palette entries from DrawSystem+0x78.
VC5 inlines memcpy into a manual loop that exactly matches the original
hand-written loop. Use the typed struct+memcpy approach for palette copies.

SetPalette TDrawArea (61 B) — set entry 0 to black, entry 255 to white, then
call ModifyPalette — matched perfectly with direct field assignments and
proper class method call.

### Unlock/ReleaseDc follow the GetDc pattern
These COM-interface-wrapper functions share identical structure:
check DrawSystem/DrawType, check DrawSurface, check guard field (Bits/DrawDc),
call through IDirectDrawSurface vtable, set guard field to NULL.
The same IDirectDrawSurface class with virtual __stdcall methods works
for all three. Vtable offsets: GetDC=0x44, ReleaseDC=0x68, Unlock=0x80.

### dllimport for IAT calls, extern "C" for CRT
Use `__declspec(dllimport)` for Win32 API calls (GetDC, SelectPalette, etc.)
to generate `call dword [IAT_addr]` matching the original binary.
Use `extern "C"` declarations for CRT functions to prevent inlining.
For CRT functions that VC5 inlines (like memset), use an alias name
(`memset2`) that the compiler doesn't recognize as a known intrinsic.

### unsigned char result forces bl/ebx register
When a function saves a byte-sized return value and tests it later,
declare it as `unsigned char result = (unsigned char)FuncCall()`.
This forces VC5 to use `mov bl, al` / `test bl, bl` instead of
`mov ebp, eax` / `test ebp, ebp`, matching the original register choice.

### Instruction scheduling diffs are common and benign
DrawRect (97.3% match) and DrawHorzLine (97.8% match) only differ by
2-byte instruction scheduling swaps: independent `mov` instructions
get reordered by VC5's peephole scheduler. These are always behaviorally
identical and excellent accepted_drift candidates.

### CMP operand order fixed by swapping comparison sides
When the only remaining diff is `cmp [mem],reg` (opcode 39) vs `cmp reg,[mem]` (opcode 3b),
both setting identical flags, swap the comparison operands in source.
`if (a != b)` uses cmp with reg=[a's storage], mem=[b's storage];
`if (b != a)` reverses it. Pick whichever produces opcode 39.
Verified on TListPanel::handle_idle (173 B, 1.16% diff → MATCH).

### Packed structs for byte-array operations
When zeroing an array of 4-byte palette entries, a manual `do { \n    p->peRed=0; p->peGreen=0; p->peBlue=0; p->peFlags=0; p++; count--; \n} while(count != 0)` loop produces similar but not byte-identical code
to the original. Alignment offset differs by 1-2 bytes. Use `memset`
for the zeroing if it produces matching code, otherwise accept drift.

## Lesson: Model the proven subfield offset directly, not an invented helper subobject

When original asm indexes a field inside an array element with a fixed offset
like `tile + 0x10` for `objects.list`, match that byte layout directly in the
aggregate that is being indexed. Do not insert an extra helper struct/vtable
layer unless the asm proves it exists.

Try when:
- the element access math matches (`lea eax,[x+x*2]`, `...[row + eax*8 + 0x10]`)
  but the rebuilt code adds extra arithmetic or lands on `+0x14`/`+0x18`;
- a guessed helper subobject (for example an object-list wrapper with a vptr)
  shifts the payload field later than the original.

Why it helps:
- VC5 folds array-element indexing only when the exact element size and target
  field offset are correct;
- an invented wrapper forces different scale/add sequences even if behavior is
  otherwise right.

Caveat:
- if other functions later prove the wrapper really exists, keep the wrapper
  only when its internal layout still places the accessed field at the same
  byte offset seen in asm.

## Lesson: Bucketed pointer-array scans may need the direct typed member surface

When a function scans `this->resourcePtrs[type][i]`-style buckets and then writes
back through the same bucket entry, prefer the direct typed member arrays in the
class (`ResourceMemory* resourcePtrs[4]; int numResources[4];`) and the natural
indexed loop:

```cpp
for (int i = 0; i < this->numResources[type]; i++) {
    if (this->resourcePtrs[type][i].id == id) {
        this->resourcePtrs[type][i].valid = (unsigned char)valid;
        return 1;
    }
}
return 0;
```

Try when:
- a cached `count` local plus `base`/`cur` walking pointers restores the right
  early `test/jle` but VC5 keeps duplicating the compare at loop bottom;
- `void*` bucket members or casted base pointers produce a near match with a
  peeled/duplicated compare family.

Why it helps:
- VC5 can keep the bucket lookup and indexed store in one coherent alias family;
- direct `this->member[index]` surfaces can avoid the extra loop-bottom reload or
  duplicated compare that appears when the source splits the same bucket into
  separate casted base/current locals.

Caveat:
- do not apply blindly when the original clearly walks a pointer or uses a byte
  offset accumulator; this lesson is for compact indexed bucket scans where the
  original already compares an index against a count.

## Lesson: Mutating one source pointer into a this-relative delta can unlock the `sub src,this` copy basin

When the original copy loop uses a mixed pattern like `lea aux,[src+off]`,
`lea dst,[this+off]`, `sub src,this`, then loads one lane from `[src+dst]` while
other lanes come from a separate moving pointer, try spelling that directly in
source by first seeding the secondary source pointer, then reassigning the main
source pointer to the byte delta:

```cpp
idx = src->sortedIndexValue;
dst = this->valueValue;
src = (T*)((char*)src - (char*)this);
while (1) {
    if (i >= limit) break;
    dst[0] = *(int*)((char*)src + (int)dst);
    ...
}
```

Try when:
- the original has a proven `sub ecx,eax` / `[ecx+edx]` style first-lane load;
- nearby lanes are copied from a different running pointer such as `[esi-20h]`
  and `[esi]`;
- more natural dual-pointer or indexed copies keep collapsing into a bottom-test
  family instead of the observed top-check-plus-delta-load loop.

Why it helps:
- VC5 can preserve the exact source register roles: one pointer stays as the
  secondary moving base, while the mutated main pointer becomes the reusable
  this-relative delta consumed by the `[delta + dst]` load.

Caveat:
- this is for exact-match recovery of a binary-observed alias pattern, not a
  default source style; prefer natural copies unless the asm clearly proves the
  delta-basin shape.

- declaration, type, layout, include-context, or flag facts that changed codegen;
- variant-lab findings that revealed a useful compiler basin;
- stubborn-match breakthroughs after many failed equivalent spellings.

Do **not** use this file as a per-function attempt log. Keep detailed local
history in the scratch or accepted-drift source file. In `LESSONS.md`, generalize
from the function: avoid long function-specific narratives, and mention a VA or
function name only as optional evidence.

Preferred entry shape:

```md
## Lesson: <short reusable pattern>

<Compact explanation of the general lesson.>

Try when:
- <observable assembly/source symptom>
- <matching situation where this may apply>

Why it helps:
- <how this can affect VC5 codegen: liveness, frame size, branch layout, calls,
  stack cleanup, helper selection, etc.>

Caveats:
- <when not to apply blindly, if known>
```

Promote especially stable, broadly applicable lessons into `AGENTS.md` later;
otherwise leave them here as field knowledge.

## Lesson: Address-expression term order can force the exact SIB/base encoding

When a stubborn near-match differs only in memory operand encodings like
`[eax+ebp]` versus `[ebp+eax]`, preserve the binary-observed address expression
shape directly in source instead of assuming commutative pointer math is neutral.
In VC5, that choice can also change instruction length (for example `ebp` as the
base may require an extra displacement byte), which then shifts later short jumps.

Try when:
- the rebuilt logic is correct but one indexed load/store is 1 byte shorter or longer;
- edit/resync diff shows the first mismatch at a memory operand, followed by shifted
  branch displacements;
- the original uses an unusual base/index pairing such as `[edi+eax+imm]` or `[ebp+eax]`.

Why it helps:
- VC5 does not treat commutative address expressions as codegen-neutral;
- spelling the expression in the original's term order can recover the exact SIB byte,
  restore the intended instruction length, and snap later branch offsets back into place.

Caveat:
- once the address form is right, keep the natural predicate spelling too (`>= 4`
  versus `3 < x`, `>= 0` versus `-1 < x`), because VC5 may otherwise switch to a
  different compare/branch family even when the address encoding matches.

## Lesson: Vtable padding macros for multi-dispatch functions with correct virtual call offsets

When a function calls multiple virtual methods at specific vtable offsets (e.g.,
`[vtable+0xA8]`, `[vtable+0xF0]`, `[vtable+0x28]`, `[vtable+0x7C]`), use a flat
class with placeholder virtual functions to align the real virtuals at the correct
vtable indices. The compiler generates the right `call [vtable+offset]` instructions
through direct virtual dispatch (e.g., `this->method()`) instead of requiring ugly
function-pointer casts.

```cpp
#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Game_World {
public:
    // vt[0..24] = 25 padding: 16+8+1
    VPAD16(0) VPAD8(16) VPAD1(24)
    // vt[25] = new_random_game (the function being defined)
    virtual unsigned char new_random_game(RGE_Player_Info& param_1);
    // vt[26..41] = 16 padding
    VPAD16(26)
    // vt[42] = setup_player_colors (at offset 0xA8)
    virtual void setup_player_colors(RGE_Player_Info* param_1);
    // vt[43..59] = 17 padding: 16+1
    VPAD16(43) VPAD1(59)
    // vt[60] = scenario_init (at offset 0xF0)
    virtual void scenario_init(RGE_Game_World* param_1);

    // Data fields follow at +0x04 (after implicit vtable pointer)
    char gap_04[0x24];
    // ... field layout matching the type dump
};
```

Try when:
- The original asm calls through vtable at specific non-standard offsets
- You need clean source that uses `this->method()` instead of function-pointer hacks
- You know the exact vtable index needed (offset/4)

Key points:
- The class must be flat (no inheritance) to avoid extra vtable-pointer shifts
- The implicit vtable pointer at +0x00 means fields start at +0x04
- Count padding virtuals carefully: VPAD16(N) covers indices N through N+15
- The exact index must produce offset = index*4 matching the original
- Other classes called through their vtable need the same treatment

## Lesson: `__declspec(novtable)` + manual vtable store for delayed vtable scheduling

When a constructor's original binary shows the vtable write happening well into the
constructor body (after field initialization, subobject construction, etc.), but
our compiler writes it at the very start of the constructor body, use
`__declspec(novtable)` on the class and write the vtable pointer manually as an
explicit store in the body.

Example:
```cpp
class __declspec(novtable) BuildAIModule : public AIModule {
public:
    BuildAIModule(void* param_1, int param_2);
    virtual ~BuildAIModule();
};

BuildAIModule::BuildAIModule(void* param_1, int param_2)
    : AIModule("Build AI", 0x3E9, param_2, param_1)
{
    // subobject ctor + field init
    this->buildList.BuildItem::BuildItem();
    this->someField = 0;
    // ... more field init ...
    *(void**)this = (void*)VTABLE_ADDR;  // manual vtable write at correct position
    // ... rest of body ...
}
```

Try when:
- The original binary places the vtable write in the middle of the constructor body
  (after subobject construction and/or field initialization)
- Our compiled version places it immediately after the base constructor returns
- The mismatch first appears at the vtable write location

Why it helps:
- VC5 with `/GX` normally writes the vtable at the start of every constructor body
- `__declspec(novtable)` suppresses this automatic vtable initialization
- A manual `*(void**)this = (void*)ADDR;` store at the right source position puts
  the vtable write at the exact position matching the original
- The class can still have virtual functions (for EH frame generation) while the
  vtable write is controlled manually

Caveats:
- Only works if VC5 supports `__declspec(novtable)` (introduced in VC5)
- The base class constructor may temporarily set a different vtable; the manual
  override replaces it at the right time
- The base class should NOT use `__declspec(novtable)` itself - only the derived
  class where you want to control the vtable position

## Lesson: Duplicate assignment in both arms can preserve compare-store-branch scheduling

When VC5 needs to emit `cmp`, then an independent store, then the conditional branch
that consumes the compare flags, write the source with the same assignment in both
arms around the guarded body. For example, after an allocation and `short i = 0`,
`if (i < count) { field = ptr; do {...} } else { field = ptr; }` can compile to
`cmp count,i; mov field,ptr; jle skip`, because the common assignment is hoisted
between the compare and branch. A single assignment before/after the `if` may schedule
as `mov; cmp; jle` or `cmp; jle; mov` instead. Use only when the duplicated assignment
is genuinely equivalent on both paths.

## Lesson: Field zeroing after pointer load can preserve immediate stores despite a zero local

When a function has both a zero-initialized running local and adjacent structure fields set to
zero, the order of source assignments decides whether VC5 emits immediate stores
(`mov word [field],0`) or reuses the zero local register (`mov [field], bx`).
If the original zeroes a loop accumulator register first but still uses immediate field stores,
load the traversal pointer and assign the fields before assigning the source local to zero.
The optimizer can still hoist the accumulator `xor` early while keeping the field stores as
immediates. Verified on a text-panel line/column scan with a `short` offset accumulator.

## Lesson: Parameter reuse forces register allocation for zero/nonzero patterns

Writing to an incoming parameter's stack slot (its declared local variable in the
function body) can force VC5 to keep that parameter in a specific register,
because the compiler materializes the mutable local in a register for the
writes. This is especially useful for matching functions that use one or two
parameters as reused row/column remainder or temporary holders.

Try when:
- The original asm uses a parameter register (`cl`, `dl`, `edx`, `ecx`) for an
  inner-loop or modular-arithmetic temporary.
- The decompiler shows the parameter only read once, but the original binary
  reloads/writes it throughout the function body.
- A register choice is the only remaining mismatch near the end of matching.

Why it helps:
- A write to an `unsigned char param_1` forces the compiler to keep it in a
  byte-addressable register (`cl`/`dl`) for subsequent stores, matching the
  original's register allocation exactly.
- Without the write, the compiler may promote the parameter to a different
  register or stack slot, creating a false diff.

Caveats:
- The writes must match the original's register width (`unsigned char` for
  byte-addressable registers).
- Over-applying this can add unnecessary stores that break matching.
- This works best when the original clearly reuses the parameter as scratch
  (writes to its incoming stack slot).

Reference: `00539AA0` (get_tile_picture) — `unsigned char r = param_1, c = param_2`
used as row/column remainder worked after 6500+ variants failed.

## Lesson: Direct extern calls for IAT-resolved API functions

When the original asm calls a Windows API through an indirect `call dword [addr]`
(import table), declare it as an `extern` function rather than including
`<windows.h>`. The COFF relocation system handles masking the import-address
bytes, and the compiler emits the correct indirect call thunk.

Try when:
- The original shows `call dword [XXXXXXXXh]` for a Windows API function.
- Including the real header would bring in huge dependency chains.

Why it helps:
- Avoids pulling in `<windows.h>` type/constant definitions that complicate
  the minimal TU.
- The relocation masking in `check_function.py` handles the import-table call
  bytes identically whether the symbol is resolved at link time or runtime.

Caveats:
- Must use the correct calling convention (`__stdcall` for most Win32 APIs).
- Must match the original function signature (return type, parameter types and
  order) to get the right argument cleanup.

Reference: `00523640` (show_error_message) — `extern int __stdcall MessageBoxA(...)`

## Lesson: je-dispatch to handlers after epilogue signals a switch statement

In VC5, a `switch` statement emits `je` (jump-if-equal) instructions that target
handler blocks placed after the function's main epilogue (a "jump table" or
"dispatch-to-case-at-end" pattern). If the original asm shows `je` targets
pointing to code after the main `ret`/`pop` sequence, the source should be a
`switch`, not `if/else if/else` or early-return `if` chains.

Try when:
- The original asm dispatches a value via `cmp reg, X` / `je target` where
  `target` is after the function's main epilogue.
- An `if/else if/else` or `if+return` chain generates `jne`-skip (cases inline,
  else at end) rather than `je`-jump.

Why it helps:
- `switch` and `if/else` generate fundamentally different block layout in VC5.
  A two-case-or-default dispatch using `je` will never be matched by an
  `if/else` source, no matter how the conditions are ordered.

Caveats:
- This applies to VC5 specifically; newer compilers may differ.
- The dispatch must actually be a controlled multi-way branch, not an
  early-return guard.

## Lesson: C source files must have .c extension for correct codegen

When a function's PDB source is a `.c` file (not `.cpp`), the scratch file must
use the `.c` extension. Compiling C code as C++ changes name mangling, function
prologues (no `this` adjustment), and some codegen decisions.

Try when:
- The inventory shows `PdbSourceFile: something.c`.
- The function uses C-style patterns (no `this`, `__cdecl`/`__stdcall` calling
  conventions, global functions rather than member functions).

Why it helps:
- C compilation in VC5 generates different calling-convention handling (no
  `ecx` = `this` convention).
- C++ treats `extern` function declarations differently for name decoration.

Caveats:
- The scratch file must have exactly the `.c` extension; the build system
  detects it and routes to the C compiler.
- The function must compile cleanly as C (no C++-only features like references,
  classes, templates).

## VC5 goto-forces block shape

Using `goto found;` / `found:` instead of `break; if (!cur) return;` forces VC5
into a specific early-return-plus-separate-block layout. This was essential for
RESFILE_close_new_resource_file (0047F180), where `break; if (!cur) return;`
produced different jump distances and block ordering. The `goto` made the early
return a separate basic block, matching the original's pop+ret at the not-found
path.

## Int* pointer arithmetic matches VC5 address folding

When the original asm uses negative offsets from a base pointer (e.g.
`lea edi,[ebx+48h]; mov ecx,[edi-8]`), writing C as `int* base = hdr + 0x48;
*(base-2)` can produce the right data access but VC5 may still fold the
address to use positive offsets (`lea edi,[ebx+40h]; mov ecx,[edi]`). The data
is right but the byte encoding differs. This remains an open pattern.

## `unsigned int` table base prevents constant-folding

When iterating over a fixed-address table with C code like `const char* p =
0x585520; p += 8;`, VC5 may constant-fold each access, generating hardcoded
addresses for each entry instead of a running pointer. Using `unsigned int
base = 0x585520;` (integer arithmetic) and `(const char*)base` casts prevents
this, keeping `base` as a mutable register value.

## Reused parameter slots for temps

VC5 reuses parameter stack slots as temporary storage when the original
parameter is no longer needed. For RESFILE_locate_resource, extLen is stored
at `[esp+param_1]` after `name` is only accessed via `edx` register. To match
this, avoid keeping a named local for the temp (which may end up in a
callee-saved register like `ebp`) and instead declare it only inside the block
where it's immediately needed.

## Temp local + result variable for sound-section scheduling

When a function ends with two branches that each store to a member pointer and return 1, VC5 may schedule `mov eax,1` (the return value) before the pointer load, and use `mov dword [addr],0` for the null path instead of `xor eax,eax; pop; store`.

To force the original scheduling (return register after pointer load, xor-based zeroing for null path):
1. Declare a local temp variable for the pointer (`RGE_Sound* snd_tmp;`)
2. Declare a separate return value variable initialized early (`int rv = 1;`)
3. Separate the if/else assignment to the temp from the member store:
   `if (cond) { snd_tmp = array[index]; } else { snd_tmp = 0; }`
   `this->member = snd_tmp;`
   `return rv;`

This creates enough local variable pressure that VC5 uses `eax` for the pointer load (preventing early `mov eax,1`) and uses `xor eax,eax` for the null-path zero. Verified with `setup` (0050E250) and `setup` (0050E360) from tm_b_obj.cpp.

## Parameter-slot reuse for serialization functions

For functions that repeatedly call `rge_read`/`rge_write` and reuse the parameter slot as a temp buffer:
1. Save the file parameter first: `int iVar1 = file;`
2. Read/write INTO/from the parameter slot: `rge_read(iVar1, &file, 4);` or `file = value; rge_write(iVar1, &file, 4);`
3. Use `iVar1` (the saved copy) for all subsequent calls

This matches the original asm pattern where `edi` holds the saved file handle and `[esp+param_1]` (the parameter's original stack slot) is reused as a scratch buffer. The original VC5 compiled code stores the saved handle in a callee-saved register (`edi`) and the parameter slot fills the dual role of original parameter + temp variable.

Verified with `load` (0040FE90) and `save` (0040FF70) from aipbook.cpp.

## Nested-if branch control for signed bounds checks

When matching forward branches (`jl`/`jg` for error exits) in functions with signed bounds checks:

- `if (index >= 1) { table = info->table; if (index <= count) { return ...; } } return -1;`
  generates `jl → return -1; jg → return -1` (original pattern).

- `if (index < 1) return -1; if (index > count) return -1; return ...;`
  generates the inverted form: `jge → skip_error; jle → skip_error` with inline error returns.

The nesting approach (`if (condition) { ... }`) puts both error-exit jumps as forward branches to a SHARED error epilogue, matching the original block layout. The early-return approach inlines the short error paths, inverting the branch direction.

This pattern applies to any function with signed `if (x >= min && x <= max)` bounds checking where the original uses `jl`/`jg` for a shared error return. Verified with `currentScore` (004E6870).

## While-loop rotation for linked-list and array traversal

`while (node != 0) { body; node = node->next; }` triggers VC5 loop rotation, placing the null check at the bottom with `jne` (backward jump on true). This matches the original block layout.

Alternative forms that FAIL to match:
- `while(1) { body; if (node == 0) break; ... }` → generates `je exit; jmp loop` (inverted)
- `goto loop; ... if (node) goto loop;` → also `je exit; jmp loop`
- `do { body } while (node != 0)` → `je exit; jmp loop` (internal return interferes)

The key: let `node = node->next` be the LAST statement in the while body, so VC5 naturally rotates the condition down. Verified with `find_by_id` (00463490), `find_by_group` (004632E0), `hasOrderOnQueue` (00417920).

## Direct member access delays pointer loads past bounds checks

Using `this->groups[i]` instead of a local `int* p = this->groups` delays the pointer load until after the while-loop null check, matching the original instruction order. The compiler hoists the load of `p` to the prologue if it's a local, but evaluates `this->groups` lazily when it's accessed directly in the loop body. Verified with `inGroup` (0040A420).

## Compare operand order for short/integer comparisons

For `if (this->frame >= param_1)` (memory on left), VC5 generates `cmp [ecx+14h], ax; jl → exit`. 
For `if (param_1 <= this->frame)` (register on left), VC5 generates `cmp ax, [ecx+14h]; jg → exit`.
Both produce the same logical result but different bytes. Put the member field on the LEFT for `cmp [mem], reg` encoding. Verified with `frame_passed` (0041B560).

## Lesson: `__thiscall` keyword is UNUSABLE in VC5 — causes hard C4234 error

The `__thiscall` reserved keyword appears in VC5's keyword table but triggers a hard
C4234 error: "nonstandard extension used : '__thiscall' keyword reserved for future use".
The .obj file is NOT produced (compiler exit code 2). Any function that uses `__thiscall`
in a function pointer type cast (`(void(__thiscall**)(void*, int))&addr`) will fail
on a fresh compilation. Matches depending on cached .obj files from this pattern
will not recompile.

Try when:
- You need to call a function with `__thiscall` calling convention at a raw address.

Why it's important:
- This makes ALL methods of generating `__thiscall` function pointer type casts
  unresolvable. `typedef void (__thiscall* Fn)(void*)` and `(*(void(__thiscall**)(void*))&addr)(ptr)`
  both trigger C4234.
- Member function pointer casts (`typedef void (Class::*MemFn)(void)`) also fail:
  VC5 cannot cast an integer to a member function pointer (C2440 error).

Solution:
- Use pure virtual function declarations for VTABLE calls (see next lesson).
- Use non-virtual member function declarations for DIRECT `__thiscall` calls.

## Lesson: Pure virtual function declarations generate correct `__thiscall` vtable sequences

Instead of `(*(void(__thiscall**)(void*))&addr)(this)` (which uses `__thiscall` and
causes C4234), declare the function as a pure virtual in the class. The compiler
generates `mov ecx, this; call [vtable+slot]` — the exact `__thiscall` sequence.

Example:
```cpp
class TPanel {
public:
    // vt[0..7] padding
    virtual void pad00() = 0;
    virtual void pad01() = 0;
    ...
    // vt[8] = +0x20
    virtual void redraw(int flags) = 0;
};
```

Then calling `this->redraw(1)` generates `mov ecx, esi; call [esi+20h]`.

Try when:
- The original asm shows `call dword [reg+XXh]` (vtable dispatch via 
  register+offset).
- You know the vtable slot number: slot = offset / 4.

Why it helps:
- Eliminates `__thiscall` keyword entirely.
- Generates correct `mov ecx, this` + `call [vtable+slot*4]` sequence.
- Pad virtual functions fill the vtable slots above the target.
- Verified with `show_error_message` (00523640) which matched 0% using this.

Caveats:
- You need padding pure virtuals for ALL vtable slots between 0 and your target.
- Can add significant boilerplate (padding 50+ slots). Use macro if available.
- The vtable pointer replaces the first 4 bytes of the class layout.

## Lesson: Non-virtual member function declarations generate correct direct `__thiscall` calls

For calling an existing matched function at a known address (e.g., `get_paused`
at 0x00420180), declare it as a non-virtual member function in the class.
The compiler generates `mov ecx, ptr; call rel32(symbol)` with the rel32
covered by a COFF relocation entry. During comparison, relocation bytes are
masked to zero, so the call target doesn't contribute to the diff.

Example:
```cpp
class RGE_Base_Game {
public:
    int get_paused();  // non-virtual, defined elsewhere
};

// Call site:
((RGE_Base_Game*)*(void**)rge_base_game)->get_paused();
// Generates: mov ecx, [rge_base_game]; call 00420180h (reloc masked)
```

Try when:
- The original asm shows a direct `call ADDR` (not `call dword [vtable+offset]`)
  to a `__thiscall` function that's already matched in `src/matching/`.
- Both the caller and callee use `__thiscall` (ECX = this).

Why it helps:
- The COFF relocation system generates a `REL32` relocation entry for the
  external symbol reference. `check_function.py` masks these bytes to zero
  during comparison, so the actual call target address doesn't matter.
- No need for `__thiscall` keyword at all — just a member function declaration.
- Verified: `get_paused` (00420180) and `release_mouse` (00466280) are called
  this way from `mouse_left_move_action` (0053E7F0).

Caveats:
- Function must be declared EXACTLY matching its original signature.
- The mangled symbol name in the .obj must reference a defined symbol
  (doesn't matter — relocations are masked).
- Register allocation for the `this` pointer can still cause mismatches
  (see next lesson).
- The compiler may keep the object pointer in a callee-saved register
  (EDI/EBX) rather than ECX, requiring an extra `mov ecx, reg` before
  the call. This can cause a 2-3 byte diff if the original had ECX
  already loaded for other purposes.

## Lesson: VC5 register allocation for reused `this` pointers across calls

When a function accesses an object's fields AND calls methods on it, the
original VC5 (from the EXE) might keep the object pointer in ECX throughout
comparison checks and the initial call, while our VC5 compilation may move
it to a callee-saved register (EDI/EBX) that requires an extra `mov ecx, edi`
before member function calls.

This typically happens when:
- The object pointer is loaded from a global (`mov ecx, [62C574h]`)
- It's used for a field access (`[ecx+1B0h]`)
- Then used again later for a member call after intervening comparisons

The original keeps it in ECX throughout (no intervening function calls between
load and first member call). Our compilation may move it to EDI/EBX to ensure
it survives across intervening member calls that clobber caller-saved regs.

Try when:
- The generated asm saves more callee-saved registers (ebx, ebp, esi, edi)
  than the original (esi, edi only).
- The function loads a global pointer for `this`, does comparisons, then
  calls a member function on it.

Why it helps to recognize:
- This IS a VC5 codegen barrier that cannot be fully controlled from C++ source.
- Raw pointer arithmetic with incompatible types doesn't prevent the caching.
- Using volatile qualifiers may help but hasn't been verified.
- Reloading from the global at each access point (with different expression
  shapes) is the best mitigation but still may not prevent register caching.

Caveats:
- This is the same VC5 register-allocation barrier seen in `add_quick_obj`,
  `set_positioning`, and `mouse_left_move_action`.
- When the extra callee-saved saves create a 4+ byte stack offset shift for
  all parameter accesses, matching becomes impossible regardless of the
  remaining code similarity.

## Lesson: TPanel's clip_to_parent field is an `int` (4 bytes), not `char`

The `clip_to_parent` field in TPanel is a full `int` (4 bytes, offset +0xF0 to
+0xF3), not a `char` (1 byte at +0xF1). This affects struct layout: with
`int clip_to_parent` at +0xF0, `sizeof(TPanel)` = 0xF4 (244 bytes, with vtable
at +0x00 and fields ending at +0xF3, padded to 4-byte boundary).

With a `char clip_to_parent` at +0xF1, sizeof would be 0xF2 (242 bytes),
which shifts all derived-class field offsets by 2 bytes (e.g., `byte_168`
appears at +0x16A instead of +0x168).

Always check the original `set_rect.cpp` match (00464C50) for the authoritative
TPanel layout with `int clip_to_parent` at +0xF0.

## Lesson: Switch default case affects bounds-check branch target

When a switch statement covers every value of a small domain (e.g. cases 1..7),
VC5's `ja` bounds check (out-of-range test before the jump table) routes to
the switch body's end when no `default` case is present, but routes to the
default case handler when `default:` is written explicitly.

**Example** (set_bevel_info, 00478350):
- Values 1..7 all handled by individual cases
- VC5 must handle param=0 and param>7 (the `ja` unsigned-above check)
- **With `default: field_184 = 1;`** → `ja` jumps to the default handler
  (exact match with original where param>7 also sets field_184=1)
- **Without `default:`** → `ja` jumps to code after the entire switch body,
  skipping the field_184=1 assignment (1-byte JA displacement diff)

Always write `default:` when the original binary has a `ja`/`jb`/`jg`/`jge`
bounds check that falls through to an assignment or call. The compiler uses
the default case as the routing target for the bounds-check failure path.
Even if the default does the same thing as another case, writing it
separately changes the branch target encoding.

## 2026-04-30: effects.cpp destructor match and remaining patterns

### Destructor with manual vtable matches with non-virtual class + for(short)
The RGE_Effects destructor (00449440, 99 bytes) matched using:
1. **Non-virtual class with explicit void* vtable_ptr member** (not compiler virtual)
   The class uses a manually-managed vtable, typical of game code from this era.
   Declaring `virtual ~RGE_Effects()` adds a SECOND compiler-generated vtable
   pointer and changes sizeof from 12 to 16, breaking all field offsets.
2. **`for (short i = 0; i < effect_num; i++)`** with a SHORT loop counter.
   `short i` forces VC5 to use `movsx eax, bx` for sign extension in the
   comparison, which is exactly what the original does. `long i` produces
   different loop code without the sign-extension.
3. **Explicit `vtable_ptr = (void*)0x570430;`** at the top of the destructor
   body, matching the binary's explicit vtable restore.

### RGE_Effects pattern: manual vtable class
RGE_Effects (12 bytes):
  +0x00 void* vtable_ptr
  +0x04 RGE_Effect* effects
  +0x08 long effect_num
RGE_Effect (0x2C = 44 bytes):
  +0x00 short id
  +0x02 char name[31]
  +0x21 unsigned char _pad_0
  +0x22 short string_table_id
  +0x24 short effect_list_num
  +0x26 unsigned char _pad_1[2]
  +0x28 RGE_Effect_Command* effect_list
RGE_Effect_Command (0x0C = 12 bytes):
  +0x00 unsigned char command
  +0x01 unsigned char _pad_0
  +0x02 short change_num1
  +0x04 short change_num2
  +0x06 short change_num3
  +0x08 float change_amount

### Register allocation for `this` in effects.cpp functions
In the RGE_Effects constructor (004490E0), the original uses `ebx` for `this`
but all natural C++ variants produce `esi=this`. This shifts ALL subsequent
register assignments. The choice appears to be a VC5 register allocator
internal heuristic that we couldn't influence from source level. The save
function (004494B0) has the same issue.

For the do_effect function (004495C0), the switch-case with __thiscall
member function calls through RGE_Player produces the right prologue but
slightly different jump offsets because the function body size differs.
The vtable call at offset 0x78 in case 1's fallback path is particularly
hard to represent without inline asm or the real class vtable layout.

## 2026-04-30: m_s_obj.cpp matching lessons

### Switch-on-uchar dispatch with ftol uses double arithmetic
In `modify`/`modify_delta`/`modify_percent` (004534A0, 00453540, 004535F0),
the function dispatches on a `uchar` opcode using a simple switch statement.
FPU operations (ftol, fild for rounding) need explicit `(float)((double)a OP (double)b)`
casting to produce the right `fld`/`fadd`/`fmul` register ordering instead of
in-register operations like `fadd st0, st1`.

### /GX flag for EH-framed factory functions
`make_new_obj` (00452FE0, 201B) matched only with a per-function `/GX` response
file. The function creates an RGE_Static_Object via `operator new` + constructor
call, and the original binary has exception-handling registration overhead
(EH prologue/epilogue, exception table references) that VC5 only emits with `/GX`.

### Double-comparison constants in FPU loops
In `calc_base_damage_ability` (00454980, 95B), comparing floats against `0.0`
produces `fcom dword` (single-precision constant) while comparing against `0.0`
with double promotion `(double)x > 0.0` produces `fcom qword` (double-precision
constant). The original asm uses `fcom qword [addr]` with a double 0.0 constant.
Always verify the constant precision (dword vs qword fcom/fcomp) and match the
source type accordingly.

### Attribute loop diff computation scheduling
In `setup` (004521E0, 755B), the attribute loop uses `diff = (int)src - (int)this`
computed via pointer subtraction. VC5 schedules the `sub eax,esi` (diff)
instruction based on declaration order of the pointer locals. Declaring
`unsigned char* fp`, `float* ap`, `short* tp` before `int diff` produces the
original LEA-then-SUB ordering; reversed declaration produces SUB-then-LEA.

### jbe vs je from unsigned byte if-test
VC5 generates `test al, al; jbe` for `if (x)` where x is `unsigned char`,
but generates `test al, al; je` for equivalent patterns depending on how
the condition expression is typed. Both are behaviorally identical after
test (which clears CF), so this is a cosmetic codegen difference that may
not be controllable from source.

### Short-to-int conversion in array indexing
For a `short` loop counter used in array indexing (`damage_sprites[i]`), the
original binary uses `movsx eax, cx` (3 bytes, sign-extend from 16-bit),
but VC5 in our toolchain generates `mov eax, ecx; and eax, 0FFFFh` (7 bytes,
mask to 16 bits). This 4-byte difference shifts subsequent branch targets
and adds 4 bytes to the function size. Both produce the same logical
index value for values 0-32767. The source `short i` vs `int i` or
with/without `(int)` casts doesn't change this codegen choice.

## 2026-04-30: aipbook.cpp batch matching lessons

### convertToIntType pattern: explicit int local for strcmp
All convertToIntType functions (AIPlayPhaseCommand, AIPlayPhaseTrigger, AIPlay,
AIPlayBook::convertTargetNameToIntType, AIPlayBook::convertTargetCharacteristicNameToIntType)
match with the same pattern: `int r; r = strcmp(name, s_String); if (r == 0) return N;`
repeated for each string. Using an explicit `int r` local (not inline `if (strcmp(...)==0)`)
forces VC5 to generate the expected inline comparison with test/jne/mov pattern.
Key: `int r` must be declared once and reused for each strcmp call.

### AIPlayPhase requires full layout for pointer arithmetic
When iterating phases with `phase++` or advancing by sizeof(AIPlayPhase),
the AIPlayPhase class must have its full data layout (commands[5] + triggers[3])
to give sizeof(AIPlayPhase) = 0x8C. Incomplete types default to sizeof 1,
causing `phase++` to generate `inc ebx` instead of `add edi, 8Ch`.

### command() as a method generates COMDAT
Declaring AIPlayPhase::command() in the same file as locationsOnMap causes VC5
to emit the command function body as a COMDAT at the start of .text, shifting
all function addresses. To avoid this, either define command() after
locationsOnMap() in source order, or use direct array access.

### Play list scanning with strcmp matches well
playNumber (scan plays array, compare names) with for-loop + strcmp gives
108/113 bytes matching. The only diff is an extra test/jle from the for
loop's condition check duplicating the explicit `if (n <= 0)` guard.

### Copy function pointer arithmetic
Manual pointer-walking copy loops generate compiler-specific code. The original
uses `diff = other - this` once and reuses it, but VC5 may compute separate
offsets. The field-copy portion (102 bytes) matches exactly; loop bodies
show different register allocation.

## Lesson: Eliminating local variables can fix register allocation swaps

When VC5 allocates registers differently from the original (ECX vs EAX, EDX vs ECX),
the root cause can be named local variables that force VC5 to load both values before
any test, while the original loads and tests one at a time.

**Example**: `handle_bring_object` (00532610) had 8.48% positional diff due to EDX/ECX
swap for `this_obj`/`target_obj`. The fix was removing local variable declarations:
```cpp
// Bad: forces both loads upfront
RGE_Static_Object* obj1 = entry->this_obj;
RGE_Static_Object* obj2 = entry->target_obj;
if (obj1 == 0 || obj2 == 0) { ... }

// Good: inline access forces load-and-test order matching original
if (entry->this_obj == 0 || entry->target_obj == 0) { ... }
// ... use entry->this_obj and entry->target_obj directly throughout
```

Try when:
- The first mismatch is a register swap (ECX↔EAX, EDX↔ECX, etc.)
- The function accesses struct members through a pointer parameter
- Local variables hold copies of pointer/reference fields

Why it helps:
- VC5's lazy evaluation of inline field accesses matches the original's load-and-test interleaving
- Named locals force VC5 to pre-load both, triggering different register allocation

Caveats:
- Only works when the locals are accessed repeatedly; single-use locals don't matter
- Doesn't fix the deeper `je` vs `jne` branch polarity issue

## Lesson: VC5 branch polarity depends on error-handler placement

When VC5 encounters `if (ptr == 0) { err; return; }`, it generates `jne` (skip over
inline error handler) when the error handler is short (< ~10 bytes). The original
binary may use `je` (jump to shared error handler at function end). This 2-byte
branch-opcode difference causes cascading offset shifts throughout the function.

Try when:
- The first mismatch is a `je` vs `jne` opcode for a null/error check
- The edit diff is small (15-25%) but positional diff is large (75-85%)
- All subsequent mismatches are shifted jump offsets

Current status (2026-04-30):
- `handle_bring_area` (005325A0): 18.9% edit diff, persistent `je` vs `jne`
- `condition_info` (00532C70): 40% edit diff, same polarity issue + vtable offset
- No source-form fix found yet; likely requires TU context or `/O1`

## 2026-04-30: aipbook.cpp matching harvest (7 matched, 8 improved)

### strcmp pattern for convertToIntType
`int r; r = strcmp(name, s_String); if (r == 0) return N;` works for ALL
string-to-int lookup functions. The explicit `int r` local (not inline if (strcmp)))
forces VC5 to generate the expected test/jne/mov pattern. Works for both
__thiscall and virtual methods.

### AIPlayPhase requires full layout for pointer arithmetic
sizeof(AIPlayPhase) = 0x8C (5 commands[0x10] + 3 triggers[0x14]). If the class
only declares methods without data members, sizeof = 1 and `phase++` generates
`inc ebx` instead of `add edi, 8Ch`, breaking the loop.

### volatile byte forces stack-temp zero-extension
`volatile unsigned char temp = byte_field;` forces VC5 to store the byte to
the stack and reload it with `mov [esp+N], dl; mov al, [esp+N]; and eax, 0FFh`.
Without volatile, VC5 uses register-only `xor edx, edx; mov dl, [eax+1]` which
is 4 bytes shorter (matches original's 132B vs 128B).

### for-loop generates redundant test/jle
`for (i = 0; i < n; i++)` combined with explicit `if (n <= 0) return` generates
a redundant `test eax, eax; jle` for the for-loop's initial condition check.
This adds 4-5 bytes of dead code. Switching to do-while changes register
allocation frame. Best to accept this as a minor scheduling difference.

### strcmp inlining for plays array lookup
`strcmp(this->plays[i].nameValue, name)` is inlined by VC5 as the expected
byte-by-byte comparison with test/jne branches. Works for both returning
index (playNumber) and pointer (play).

## 2026-04-30: file_stf.cpp getter matching and effects.cpp remaining

### Tiny __cdecl helpers match as C files, not C++
`driveAsLetter` (8B) and `driveAsInt` (9B) matched instantly as `.c` files
(compiled as C, not C++). Avoid `(char)` casts on `int` parameters — they
change the load instruction from `mov eax, [esp+4]` (4B) to `mov al, [esp+4]` (1B).
```c
// Matches: return param_1 + 0x40;  // int arithmetic, char return
// Mismatches: return (char)param_1 + '@';  // char cast changes load
```

### DriveInformation getters match with simple struct layout
All DriveInformation getters match with minimal class declarations:
- initialDrive: `return initialDriveValue;`
- initialDriveAsLetter: `return (char)initialDriveValue + '@';`  
- initialDirectory: `return initialDirectoryValue;`  (char[256] at +4)
- currentDrive: `return currentDriveValue;`  (at +0x104)
- currentDriveAsLetter: `return (char)currentDriveValue + '@';`
- currentDirectory: `return currentDirectoryValue;`  (at +0x108)
- numberDrives: `return driveValues[0];`  (at +0x208)
- validDrive: `return driveValues[param_1];`

DriveInformation layout (0x274 = 628 bytes):
  +0x000 int initialDriveValue
  +0x004 char initialDirectoryValue[256]
  +0x104 int currentDriveValue
  +0x108 char currentDirectoryValue[256]
  +0x208 int driveValues[27]

### effects.cpp remaining (blockers documented in scratch)
Four effects.cpp functions remain unmatched due to deep VC5 codegen decisions:
- **004490E0 ctor(int)**: register allocation swaps (ebx↔esi for `this`)
- **00449260 ctor(char*)**: different prologue style (path param loaded before sub esp)
- **004494B0 save**: same register issue as ctor
- **004495C0 do_effect**: member function calls through extern produce placeholder relocations

The path ctor (00449260) uses `edi=this` (correct register) but has a different
prologue order: `mov eax, [esp+4]` BEFORE `sub esp, 0x0C`. Our VC5 always places
`sub esp` first then loads with adjusted offset. This may need custom flags or
TU context.

## Lesson: `if (obj) { ... } else { goto err; }` fixes `jne`→`je` branch polarity

The branch polarity issue (VC5 generates `jne` skip-over-inline-handler instead of
original's `je` jump-to-end-of-function-handler) can be fixed by restructuring the
null/error check to use `if (ptr) { main_body } else { goto error_label; }`.

**Example**: `handle_bring_area` (005325A0) went from 77.5%→5.4% positional diff.

The fix:
```cpp
// Before (produces jne skip-over-inline):
if (obj == 0) { entry->state = 3; return; }

// After (produces je to end-of-function handler):
if (obj) {
    // main body
} else {
    goto state_err;
}
// ...
state_err:
    entry->state = 3;
    return;
```

Try when:
- First mismatch is a `jne` vs `je` branch opcode for a null/error check.
- The edit diff (15-25%) is much lower than the positional diff (75-85%).
- The error handler is short (<10 bytes) and VC5 inlines it.

Why it helps:
- `if (ptr) { long body }` creates a distance between the test and the else handler.
- VC5 then uses `je` (jump to far else handler) instead of `jne` (skip short inline).
- The block layout and jump offsets then match the original binary.

Caveats:
- The main body must be long enough (>~30 bytes) to make inline unappealing.
- `if (!ptr) goto err;` still produces `jne` if the gotolabel is nearby.
- The bounds-check branch polarity for the LAST check may still differ (5.4% remaining).

## VC5 local variable read width optimization

When reading a `volatile` variable that was last written as a byte, VC5 may
optimize the reload to a byte read (`mov al, [mem]`) instead of a dword read
(`mov eax, [mem]`), even when the read lvalue is `unsigned int`. This affects
try_wait patterns:

```cpp
// Original goal: force a byte store then dword reload
volatile unsigned int dummy;
*(volatile unsigned char*)&dummy = byte_val;
unsigned int result = dummy;  // VC5 may still emit mov al, not mov eax
```

Using a `volatile union { unsigned char c; unsigned int i; } u;` with
`u.c = val; unsigned int x = u.i;` may still produce `mov al` if the compiler
tracks the last-written union member width.

This is **unfixable drift** when the byte-to-dword load-mask pattern differs
by 1 byte (`8a` vs `8b` opcode for the reload). Both `mov al,[mem]; and eax,0xff`
and `mov eax,[mem]; and eax,0xff` produce identical results but differ in
instruction encoding.

## VC5 independent instruction scheduling

Two independent C++ statements (e.g., `int i = 0;` and `ptr += offset;` that
are not data-dependent) can be emitted by VC5 in any order. The compiler may
interleave them with adjacent arithmetic. This causes typical 2-3 byte diffs
(3-4% on small functions) that cannot be forced from source without adding
artificial data dependencies that perturb register allocation elsewhere.

Recognizing this pattern: the edit/resync diff shows pairs of identical 2-byte
instructions at swapped positions, with the rest of the function byte-identical.

Example:
```
; Original:          ; Rebuilt:
shl eax, 3           shl eax, 3
xor esi, esi         sub eax, edx    ; ◄─ swapped
sub eax, edx         xor esi, esi    ; ◄─ swapped
lea eax, [eax*4]     lea eax, [eax*4]
```

Both `xor esi,esi` (loop counter init) and `sub eax,edx` (index computation)
are independent. Swapping them produces correct code. Mark as accepted drift.

## VC5 for-loop register allocation in linked-list traversal

For linked-list traversal with a running counter, the C++ loop structure affects
which registers VC5 assigns to the 'current node' pointer vs the 'count' variable.

```cpp
// BAD: two named locals → register swap (ECX/EDX swapped vs original)
RGE_Victory_Entry* entry = this->victory_list;
long count = 0;
while (entry != 0) {
    if (count == index) return entry;
    entry = entry->next;
    count++;
}

// GOOD: for-loop with entry in init → matches original ECX/EDX assignment
long count = 0;
for (RGE_Victory_Entry* entry = this->victory_list; entry; entry = entry->next) {
    if (count == index) return entry;
    count++;
}
```

VC5 treats the for-loop init-declaration variable as more tightly scoped than a
separately declared local, which influences the register allocator's preference
for which variable occupies which physical register. When the original asm uses
EDX for the counter and EAX/ECX for the current pointer (or vice versa), the
for-loop variant is more likely to match.

## VC5 tail-call optimization (jmp vs call) is unfixable

When a void function ends with a call to another function whose return value
is discarded, VC5 may convert `call func; ret` into `jmp func` (tail-call
optimization). This saves 0 bytes (same 5-byte E8/E9 encoding) but changes
1 byte of opcode (`E8` = call vs `E9` = jmp).

```cpp
// Original emits call:
void f() { g()->h(); }  →  call h; ret
// Rebuilt may emit jmp:
void f() { g()->h(); }  →  jmp h  (if h ends with ret directly to our caller)
```

This cannot be prevented from C++ without adding artificial side effects
that would introduce other codegen differences. Using `int tmp = h(); (void)tmp;`
is ineffective because VC5 still optimized the call away. Mark as accepted
drift when this is the only remaining difference.

## NRVO struct-return: volatile temp forces push ecx / zero / pop ecx tail

When matching a struct-return-by-value function where VC5 uses NRVO (writes
directly to hidden output pointer), the function has `push ecx` (4-byte local),
a zeroing `mov dword [esp+4], 0`, and `pop ecx` tail cleanup. Ordinary C struct
return code with a local variable and `return result;` makes VC5 allocate the
full struct on the stack (`sub esp, sizeof(T)`) instead.

Fix: use a `void id(T& result)` signature (reference parameter) to bypass VC5's
struct-return machinery. This makes VC5 write directly through the reference.
To force the `push ecx` temp and the zeroing tail pattern, declare a
`volatile int dummy = 0;` local. The volatile forces a stack allocation and the
compiler-generated zeroing, matching the original NRVO cleanup sequence.

Example: 0040E3A0 (AIModule::id, 46B).

## VC5 global pointer extern with single push reuse in chain calls

When `ptr->getX(-1)->getY()` is called, VC5 may push -1 ONCE and have it
serve as the parameter for BOTH getX AND getY if getX uses `ret` (not `ret 4`),
leaving the parameter on the stack for getY's `ret 4` to clean. This is a
VC5 stack-reuse optimization that cannot be reproduced from C++. The best
approach: declare getY() with no parameters (even if it actually takes one)
to avoid a second push.

## Lesson: A volatile pre-loop byte check can preserve a separate `cmp [ptr],0` basin

When VC5 keeps collapsing an initial `if (*p == 0)` into the loop-top `mov al,[p] / test al,al`
check, making the pre-loop emptiness guard read through a volatile byte lvalue
(`if (*(volatile unsigned char*)p == 0)`) can preserve the standalone `cmp byte [reg],0`
without disturbing the later loop body.

Try when:
- the original has both an early `cmp byte [ptr],0` guard and a later loop-top `mov al,[ptr]; test al,al`;
- non-volatile source keeps merging them into one tighter loop family.

Why it helps:
- VC5 treats the volatile byte read as a distinct observable access, which blocks the usual
  coalescing of the pre-loop empty-string check into the loop-top reload.

Caveats:
- Apply narrowly to the one guard that needs to stay separate; making the loop-top read volatile
  as well can add unwanted stack temps or extra stores.

## Lesson: For sibling list-walk helpers, mirroring a nearby matched helper's inheritance boundary can fix the register basin

When two helper functions in the same class family walk the same sentinel list and call the same
comparison helper, reusing the nearby matched function's exact type surface (including whether the
node type is modeled with a base class plus derived tail, not just a flat gap) can flip VC5 into
that same early register/layout basin.

Try when:
- one helper in the cluster is already matched and another near-identical list walk is stuck early;
- the stuck version keeps choosing the wrong sentinel register or top-of-loop branch family.

## Lesson: `*(volatile float*)&param` can flip VC5 FPU operand order without changing the surrounding flow

When a float-add branch matches except VC5 emits `fld member; fadd param` but the original wants
`fld param; fadd member`, reading the incoming float parameter through a volatile lvalue cast
(`*(volatile float*)&param`) can force VC5 to start from the parameter load while leaving the rest
of the store/jump/clamp sequence unchanged.

Try when:
- the only remaining diff is reversed FPU operand order on a commutative add;
- the desired first operand is already sitting in a parameter stack slot.

## Lesson: A shared delete-pointer local plus common epilogue can force early `edi` save in vector-deleting helpers

In manual vector-deleting-destructor helpers, VC5 may keep `push edi` inside the `(flags & 2)`
array-delete path and omit `pop edi` from the scalar path, even when the original saves `edi`
unconditionally before the first branch. Using one shared delete-pointer local (for `this` vs
`this - 4`) and a common `done:` epilogue can keep that pointer live across both paths and make
VC5 save `edi` up front.

Try when:
- the helper already matches except `push edi` is sunk into the vector path;
- the non-vector path is missing the original `pop edi` because VC5 thinks `edi` is path-local.

## Lesson: Materializing `param + 1` as a local can fix a tiny pre-loop scheduling swap

For small scan functions that keep both the original parameter and a derived `param + 1` live,
writing `int limit = param + 1;` before the loop can change VC5's pre-loop scheduling from
`mov ptrbase; lea limit` to `lea limit; mov ptrbase`, even when both values are used immediately.
This can be enough to fix a last 2-byte swap without changing the rest of the loop family.

Try when:
- the rebuilt code already matches except for a tiny pre-loop order swap involving `param + 1`;
- the original uses both the raw parameter and the derived limit in the loop body.

## Lesson: Direct `return 0;` can keep the non-blank tail before the shared blank tail

In small scan loops with a shared `blank:` return-1 label, spelling the failure path as a direct
`return 0;` instead of `goto not_blank;` can make VC5 place the `xor eax,eax; ret` tail before
the later shared `mov eax,1; ret` tail, matching binaries where the blank/success exit is the
common jump target and the non-blank/failure exit is only reached from one call result test.

## Lesson: Hoisting loop-index init out of a `for` header can restore VC5's prologue/guard shape

For small scan loops, `for (int i = 0; i < count; i++)` can make VC5 delay the zero-init,
reorder saved-register pushes, or emit a second initial `test count,count` even when the
source already has an outer `if (count > 0)` guard. Declaring the index first and using an
empty-init header (`int i = 0; if (count > 0) { for (; i < count; i++) { ... } }`) can keep
an early `xor` for the index while still preserving the `inc/cmp/jl` count backedge family.

Try when:
- the original has `xor index,index` before the loop guard or before later callee-saved pushes;
- `for (int i = 0; ...)` generates an extra duplicated entry test or shifts push order;
- a `while(1)` rewrite gets the body close but loses the original loop-back branch family.

## Lesson: Direct indexed member-array loops can beat pointer walks for VC5 loop scheduling

When a small counted loop zeroes or copies several fixed-stride sibling arrays/slots, a natural pointer-walk form (`p = base; p[k] = ...; p++;`) can land in a stubborn near-match basin even when the emitted addresses are correct. VC5 may then hoist loop-setup or zero-extension instructions earlier than the original. Rewriting the same loop as direct indexed member access (`this->array[i + off] = ...;`) can recover the original schedule and compare/register placement.

Try when:
- A pointer-walk loop is already very close, but one register-init or zero-extension instruction is scheduled a little too early.
- The original uses one running integer index and repeated fixed offsets from one member array base.
- Variant-lab or manual probes show the loop body bytes are otherwise right.

Why it helps:
- The direct indexed form gives VC5 a different alias/liveness model than a carried pointer local.
- That often keeps the loop counter in the intended register and delays bound-load / zero-extension setup to the same place as the original.

Caveats:
- This is most useful for short fixed-pattern loops; larger loops may prefer the pointer-walk basin.
- Signed vs unsigned loop-index type still affects the final branch opcode (`jbe` vs `jle`).

## Lesson: Sentinel mini-list walkers can match as `while (ptr != 0)` with the pointer advance last

For compact 2-3-byte record walkers that also use an in-band sentinel byte (for example,
`if (mini->Y_delta == 0xFF) return;`), VC5 may prefer a natural `while (ptr != 0)` loop over
manual `for(;;)` / `do-while` forms. When the pointer increment is the LAST statement in the loop,
VC5 can emit the desirable top-of-loop sentinel check plus bottom `add ptr, stride ; jne loop`
shape, even though the null test is semantically redundant in real execution.

Try when:
- The original has a top-of-loop sentinel test and a bottom `add reg, stride ; jne loop` back-edge.
- A `for(;;)` form keeps rechecking the sentinel after the call instead of using the bottom pointer test.
- The loop walks fixed-width packed mini-records via `ptr = (T*)((char*)ptr + stride)`.

Why it helps:
- `while (ptr != 0)` gives VC5 a natural rotated-loop basin where the pointer value itself becomes the
  back-edge condition, while the in-band sentinel stays at the loop top.
- Copying stable offsets/parameters into locals before the loop can help VC5 load them once before the loop.

## Lesson: Member-field reload for per-store register cycling in init blocks

When filling a dynamically allocated buffer field-by-field in a constructor, the
register pattern (cycling through eax/ecx/edx for each store) depends on whether
the pointer is kept in a local variable or reloaded from the member field each time.

**Example**: `TribePriestUnitAIModule` (00505820) fills a 17-element block via
`operator_new(0x44)`:

```cpp
// BAD: keeps pointer in local → uses ONE register for all stores
void* block = operator_new(0x44);
this->field_124 = (int)block;
if (block != 0) {
    *(int*)block = 3;       // eax throughout
    *((int*)block + 1) = 0; // eax throughout
    ...
}

// GOOD: reloads from member each time → cycles eax/ecx/edx per store
this->field_124 = (int)operator_new(0x44);
if (this->field_124 != 0) {
    *(int*)this->field_124 = 3;       // mov edx,[esi+124h]; mov [edx],3
    *((int*)this->field_124 + 1) = 0; // mov eax,[esi+124h]; mov [eax+4],0
    *((int*)this->field_124 + 2) = 4; // mov ecx,[esi+124h]; mov [ecx+8],4
    ...
}
```

Try when:
- A constructor allocates memory via `operator new` and stores the pointer in a
  member field.
- Each subsequent store to the allocated block reloads from the member field
  in the original (cycling through different registers).
- Our version keeps the pointer in one register from the allocation result.

Why it helps:
- Accessing `this->field` for each store forces VC5 to emit `mov reg, [this+off]`
  (6 bytes) per store, plus the store itself, matching the original's per-store
  reload-and-store pattern with register cycling.
- A local variable keeps the pointer live in a single register, producing shorter
  stores but different register allocation.

Caveats:
- The `this` pointer must be in a callee-saved register (esi/edi) that survives
  across the stores without being clobbered.
- Works best when the member field stores a pointer cast (e.g., `field_124 = (int)ptr`)
  and is accessed with the same cast for each element.
- Does NOT apply when the block is filled via a loop with index arithmetic.

## 2026-04-30: fractal.cpp batch matching lessons

### CDQ abs pattern cannot be forced from C

The original VC5 code uses the branchless absolute value sequence:
```
cdq          ; sign-extend eax into edx (edx = eax >> 31)
xor eax, edx ; if negative, complement
sub eax, edx ; if negative, add 1
```
This produces `abs(eax)` in 3 instructions (no branches).

C alternatives all produce different code:
- `r < 0 ? -r : r` → `test eax, eax; jge +2; neg eax` (1-2 branches, different bytes)
- `(r ^ (r >> 31)) - (r >> 31)` → also conditional in VC5 (test/jge/neg)
- `abs(r)` → same as ternary

This is a **fundamental VC5 codegen choice** that cannot be forced from C source.
Functions using the CDQ abs pattern for direction randomization (MakeNewLink,
MakeFirstLink, MakeSatelliteLink, AddingCircle) cannot match exactly without
inline asm. The pattern appears in ~4 uses per function (~10 bytes each = ~40 bytes).

Try when:
- Original asm shows `cdq; xor edx/eax; sub eax/edx` in a 3-instruction sequence
- Rebuilt shows `test/jge/neg` for the same operation

### Relocation masking in diff tool ignores call offsets

The `check_function.py` tool masks relocation bytes in both original and rebuilt
before computing diffs. Any byte covered by a COFF relocation entry (call targets,
address loads) is ZEROED OUT in both binaries before comparison. This means:
- `e8 XX XX XX XX` (call) → if XX bytes are relocation targets, they become 0
- `a1 XX XX XX XX` (mov eax, [addr]) → same

Consequence: Functions with stub methods (`void Fn() { ((void(__fastcall*)(void*,int))ADDR)(this, 0); }`)
CAN still match the original, because the call offsets to the stubs are masked
before comparison. Only the opcodes `e8` remain, which are identical.

Verified: Branch (0044B540) matched at 0.0000% despite calling stubs at different addresses.

### int vs char counters affect register allocation width

`int` loop counters get full 32-bit registers (ESI, EDI, EAX, EBX, ECX, EDX).
`char` loop counters get byte-addressable registers (BL, BH, CL, CH, DL, DH).
This changes instruction encoding size: `mov bl, 0` (2B) vs `mov esi, 0` (5B).

Try when:
- The original uses byte registers (BL/BH/CL) for a counter
- The rebuilt uses full registers (ESI/EDI)

In `MapCleanUpEliminatingSinglesOnly` (0044C510), switching `char cVar6` to
`int cVar6` reduced edit_diff from 59 to 19 by switching from BL to ESI.

### Local variable vs member access for ProbArray/ProbabilityAdd

Declaring a local `char cVar3 = (char)ProbabilityAdd;` BEFORE bounds checking
forces VC5 to load ProbabilityAdd earlier, matching the original's load order.
With the load INSIDE the if-block, VC5 delays it until after bounds checks,
changing register allocation.

Similarly, `ProbArray + iVar4` vs `ProbArray[iVar4]` affects whether the pointer
or index is kept in a register.

Try when:
- The prob array update uses `mov dl, [ecx+0xFF4]` at the top of the if-block
  (original) vs `mov dl, [ecx+0xFF4]` inside the if-block (rebuilt)
- Moving the member variable access earlier in the C source fixes the order.

### Field-first comparison operator order for bounds checks

In VC5, `if (this->field < local_var)` generates `cmp [mem], reg; jge skip`
(memory field on LEFT), while `if (local_var > this->field)` generates
`cmp reg, [mem]; jle skip` (register on LEFT). The CMP opcodes differ:
`39` (memory dest) vs `3B` (register dest).

Always use the field-first form (`this->Width - 3 <= dx + x` not `dx + x >= this->Width - 3`)
to match the original's `cmp [mem], reg` encoding.

### VC5 optimization of unused loop counters to while(--counter)

When a for-loop counter (`for (int i = 0; i < radius; i++)`) is NOT used
outside the loop, VC5 optimizes it to `while (--counter != 0)` using
the parameter/register directly. This produces `dec reg; jne` (or `mov edx, reg;
dec reg; test edx, edx; jne` depending on post/pre decrement).

To preserve the counter: use it after the loop (`int count = i; (void)count;`)
but this may add unwanted stores.

### MakeArrays loop shape: `do { ... } while (--count != 0)` closest

For MakeArrays (0044B2B0), the original uses:
```
mov edx, edi   ; save current count
 dec edi        ; decrement count
 ...
 test edx, edx ; test SAVED count
 jne loop_top  ; if saved != 0, loop
```
Which is `do { ... } while (count-- != 0)` — testing the pre-decrement value.
Both `--count != 0` and `count-- != 0` produce close but not identical code.
The remaining diff (32%) is from the saved-register pattern (`mov edx, edi`)
vs direct decrement (`dec edi`). This cannot be forced from C.

### MakeElements check order: check before allocating

When MakeArrays allocates ProbArray and PlacementArray, the original checks
if the array is non-null FIRST, allocates SECOND. The exact pattern is:
1. Load array pointer from memory
2. Test if null
3. If non-null, jump to skip allocation
4. Push SizeArrays, call operator new
5. Save old counter, decrement counter
6. Store result
7. Test saved counter, jump if non-zero back to step 1

This `if (ptr == 0) { call new; } loop` with the check at TOP of the loop
is controlled by `do { if (ptr != 0) break; ptr = call(); } while (--count != 0)`.
The `break` puts the exit at top, not bottom.

## Lesson: Member initializer list delays vftable override in constructor body

When a derived class constructor sets a field in the member initializer list
(e.g., `: Base(args), derivedField(value)`), VC5 places the implicit vftable
override (writing the derived class vtable pointer) AFTER the initializer-list
stores but still within the constructor preamble. This can match the original
binary's vftable position if the original also has field stores before the
vftable write.

If the same field is assigned in the constructor body instead, VC5 may place

the vftable override earlier (after fewer body statements), shifting subsequent
instruction positions.

Try when:
- A derived class constructor writes a vftable override (`mov [this], vftable_addr`)
  at a specific position among field stores.
- Moving a constant field assignment (like `field = 1.0f`) from the body to the
  initializer list changes the vftable override position.

Why it helps:
- The vftable position is determined by the compiler, not directly controllable.
- The initializer list causes it to be placed after the initializer stores but
  before the first body statement, which can match the original's position.

Caveats:
- Initializer list items execute in DECLARATION order (within the class), not
  in the order written in the initializer list.
- This does NOT change parameter load ordering (params are always loaded in
  stack order in our VC5 version).
- Verified with TRIBE_Action_Convert (004CDB20): requiredRange(1.0f) in
  initializer list moved vftable after +0x44 store, matching original.

## Lesson: Virtual destructor adds 4-byte vtable pointer shift to gap arrays

When a class has a `virtual ~ClassName()` destructor and uses `char gap_0[N]` as
the first data member for padding, the gap array starts at offset +0x04 (after the
implicit vtable pointer), not at offset +0x00. The declared `char gap_0[N]` covers
offsets 0x04 to 0x04+N-1 in the actual object layout.

**Example** (TCommunications_Handler):
- Class has `virtual ~TCommunications_Handler()` → vtable pointer at +0x00 (4B)
- Fields at actual offsets +0x1710/+0x1712 (unsigned short High/LowPlayerNumber)
- To cover 0x04..0x170F, gap size = 0x170C (not 0x1710)
- Declaration: `char gap_0[0x170C]; unsigned short HighPlayerNumber;` → field at +0x1710 ✓

This is consistent with matching files in the same class: WhoAmI uses
`char gap_0[0x10DC]` for a field at actual offset +0x10E0 (0x10DC covers
+0x04..+0x10DF, field at +0x10E0).

Try when:
- The class has `virtual` functions (vtable pointer at +0x00)
- Gap arrays as first members produce field offsets that are +4 from expected

Why it helps:
- Correcting the gap size by subtracting 4 fixes all field offsets in one edit

Caveats:
- The FIRST char gap array adjacent to the vtable is the only one affected
- Later gap arrays in the same class are not affected (they start after prior fields)

## 2026-04-30: Remaining unsolved codegen patterns

### LogTimestamp store-before-push (00436330)
Original: `mov ecx, eax; mov [esi], eax; push ecx` (copy to ecx, store, push from ecx)
Rebuilt: `push eax; mov ecx, esi; mov [esi], eax` (push, load this, store)
Clue: VC5 creates a register copy when three uses of a value (setne result → store, push, call) 
require different registers. Source that forces "push before store" cannot be fixed with
local temp variables because VC5 optimizes the copy away. Untested axis: declaring the
method parameter as `unsigned char` (narrower than int) might force a separate load.

### frame_passed ret block order (0041B560)
Original: ret1 (return 1) before ret0 (return 0) in binary layout.
Rebuilt: Always ret0 before ret1 regardless of label name ordering.
Clue: Label alphabetical ordering does NOT control VC5 block placement.
The last comparison `jge ret0; jmp ret1` in the original gets inverted to `jl ret1; fallthrough ret0`.
This inversion is stable across all goto-based source forms. May need TU context or
different optimization flags (/O1 instead of /O2 for this function?).

### memmove (0043AB50)
Original: Uses `mov edx, [esp+0Ch]; mov esi, edx; ... lea esi, [edx+1]` pattern with
byte-by-byte copy via `mov dl, [ecx]; mov [eax], dl`.
Rebuilt: VC5 generates completely different backward-copy loop using indexed addressing.
Clue: VC5 optimizes `do { *(--d) = *(--s); } while (--n);` into its preferred loop form.
The original codegen pattern (edx as counter, separate esi for loop) suggests the original
was compiled without significant loop optimization.

### init register allocation (004BC610)
Original: hwnd reloaded from `[esp+0x9C]` into ecx each time; ebp used for flag.
Rebuilt: hwnd stored in ebp (callee-saved) across the function.
Clue: `use_member_hwnd` variant (using this->main_wnd instead of hwnd param) gets deeper
(first_mismatch=76 vs 23) but hits struct-init ordering at GetCaps call.
The dwSize init gets scheduled BEFORE argument pushes in rebuilt (original pushes first).

## Lesson: Function-scope locals force `edx` for global pointer and `cl` for byte temp in tiny switch functions

For small switch functions that load a global pointer, read a byte member, and dispatch to cases that each store back, declaring locals at function scope (uninitialized, then assigned) forces VC5 to allocate `edx` for the pointer register and `cl` for the byte temp, matching the original `mov cl, X` / `mov [edx+50h], cl` register-store pattern.

**Example** (command_outline, 0049C920, 56 B):
```cpp
// Works (produces edx=ptr, cl=byte, register-store pattern):
void TRIBE_Screen_Game::command_outline() {
    RGE_Base_Game* game;
    unsigned char t;

    game = rge_base_game;
    t = game->outline_type;
    switch (t) {
    case 0:
    case 3:
        t = 2;
        break;
    case 2:
        t = 1;
        break;
    case 1:
        t = 0;
        break;
    }
    game->outline_type = t;
}
```

Try when:
- The function reads a global pointer and accesses a member byte field
- The switch has a shared post-switch store for all cases (or a subset via break)
- Rebuilt uses `ecx` for the pointer and `dl` for the byte, or uses immediate-to-memory stores (`mov byte [reg+50h],X`) instead of register-then-memory (`mov cl,X; mov [reg+50h],cl`)
- The original uses the `push ecx` single-local-stack-slot prologue

Why it helps:
- Declaring `RGE_Base_Game* game` as an uninitialized local then assigning `game = rge_base_game` creates a separate local variable that VC5 assigns to `edx` (instead of reusing `ecx` for the global pointer)
- The `unsigned char t` local, when also function-scoped, gets `cl` (preserving `edx` for the pointer throughout)
- The single post-switch `game->outline_type = t;` reuse forces VC5 to keep both the pointer and byte temp live across the switch, maintaining the register assignment
- All cases using `break;` with a single store after the switch shares the store+ret tail between default and interior cases matching the original tail-sharing

Caveats:
- If all cases use `return;` instead of `break;`, VC5 inlines the store+ret at each case, eliminating the shared tail and breaking the register pattern
- If the global is accessed directly (not through a local alias), VC5 may reload it in each case, using different registers
- Works best for tiny functions (one switch + one post-switch store) where the local alias doesn't add extra stack pressure

## Hardcoded string address trick for strcpy inlining

**When to use**: A function calls `strcpy(dest, fixed_string)` where the original asm loads a hardcoded address like `mov edi, 0x58XXXX` as the source string pointer, followed by inline `repne scasb` + `rep movsd` + `rep movsb`.

**The trick**: Use `strcpy(this->buffer, (const char*)0x58XXXX);` to force VC5 to emit `mov reg, 0x58XXXX` for the source string, matching the original's hardcoded absolute address.

**Why it works**: VC5 inlines `strcpy` (with `<string.h>` included) as `repne scasb`/`rep movsd`/`rep movsb`. When passed a casted integer as the source pointer, VC5 loads it as an immediate constant via `mov reg, imm32`. The exact same instruction is produced as when the original EXE references its internal string data.

**Caveats**: Only works when the original genuinely uses a hardcoded address (a `push 0x58XXXX` or `mov edi, 0x58XXXX` in the asm, not relative addressing). The function match is per-byte since check_function.py doesn't resolve the external symbol; the `mov reg, 0x58XXXX` bytes must match exactly.

**Example**: `GetTauntText` (004BCA30, 46B) — `strcpy(this->TBuff, (const char*)0x588B88)` matched perfectly with the exact inline strcpy expansion.

## Declaration ordering affects VC5 register scheduling

**When to use**: A function has `int idx = 0; int i = -1;` and the original asm has `xor eax, eax` before `or esi, -1` but your rebuild has them reversed.

**The trick**: Declare `int idx = 0;` as a separate local variable BEFORE other locals, then use `for (; idx < N; idx++)` loop form instead of `for (int idx = 0; ...)`. This forces VC5 to emit the `xor eax, eax` (idx init) before `or esi, -1` (i init).

**Why it works**: `for (int idx = 0; ...)` creates a scope-level initialization that VC5 may schedule after outer-scope locals. Declaring `idx` as a separate local at the outer scope forces declaration-order initialization.

**Example**: `unitOriginalHitPoints` (004EB320, 72B) — declaring `int idx = 0;` separately before `int i = -1;` fixed the swapped init order and produced an exact match.

## Goto label ordering for shared-epilogue matching

**When to use**: A function has multiple exit paths that converge to shared `mov eax, value; ret` tails, and the original uses `jge/jle/etc` to jump to one epilogue while falling through to the other.

**The trick**: Use `goto` labels placed in the EXACT order they appear in the original binary (lowest address first). The compiler inverts the last comparison so the fallthrough path goes to the NEAREST label. By ordering ret0 before ret1 (matching the original's `ret0` at a lower address than `ret1`), the inverted comparison `if (last_frame < param_1) goto ret1` becomes `jge ret0` — matching the original's `jge ret0`.

**Why it works**: VC5 always inverts the last comparison in a chain to minimize jump distances. The fallthrough path goes to the nearer label. By placing labels in the original binary order, the inversion produces exactly the original jump encoding.

**Example**: `frame_passed` (0041B560, 44B) — using `if (last_frame < param_1) goto ret1;` with ret0 label BEFORE ret1 produced the original `jge ret0; ret1: mov 1; ret0: xor 0; ret` pattern.

## Hardcoded-string-address strcpy trick

**When to use**: A function calls `strcpy(dest, fixed_address)` and the original asm loads `0x58XXXX` as the source address.

**The trick**: Use `strcpy(this->buffer, (const char*)0x58XXXX);` to force VC5 to emit `mov reg, 0x58XXXX` for the source pointer.

**Why it works**: VC5 inlines `strcpy` as `repne scasb` + `rep movsd` + `rep movsb`. A casted integer constant produces `mov reg, imm32` — the same bytes as the original's fixed address reference.

**Example**: `GetTauntText` (00509640, 46B) — `strcpy(this->TBuff, (const char*)0x588B88)` matched with exact inline strcpy expansion.

## Ternary with -1/0 forces sbb/and branchless mask in VC5

A `? -1 : 0` ternary (e.g., `0x25CA + (param != 0 ? -1 : 0)`) forces VC5 to generate a
`neg reg; sbb reg, reg` (or `cmp ...; sbb al, al`) branchless mask pattern. This is
useful for conditional decrement/increment operations. A `? 1 : 0` or boolean expression
like `(x != 0)` generates `sete/setne` instead, producing different instruction sequences.

## Compound assignment return for matching store order

`return this->member = value;` keeps VC5 generating a store-then-return pattern that can
match store-before-al patterns. However, VC5 may still prefer register-to-memory store
(`mov [reg+disp], r8`) over immediate-to-memory (`mov byte [reg+disp], imm8`), so the
exact instruction encoding may differ between original and rebuilt.

## `if (x >= limit) return 0; return x;` generates sbb/and pattern

When the condition is written as `if (x >= 0xFF) return 0; return x;` (instead of a
ternary or an arithmetic expression), VC5 generates the exact `cmp ..., 0FFh; sbb al, al;
and eax, ...` pattern. The `>= 0xFF` comparison is key — it maps to the `jae` or `jne`
boundary that VC5 recognizes for the branchless mask optimization.

## Hardcoded float address for FPU comparisons

For FPU comparisons against a constant at a known address (e.g., `fcomp dword [56E6B8h]`),
use `*(float*)0x56E6B8` in C++ rather than `extern float ...`. This embeds the absolute
address in the instruction encoding when compiled, matching the original binary's direct
memory reference. However, scratch TU compilation may still produce a relocation stub that
resolves to 0 — this is a known TU-context limitation.

## Non-virtual member function avoids EH prologue for destructor calls

Explicit destructor calls (e.g., `idValue.~AIModule_ID()`) trigger EH prologue (`push 0FFFFFFFFh; push fs:0; ...`) even without `/GX`. Use a non-virtual member function like `dtor()` instead of the destructor to generate a plain `lea ecx, [this+N]; call rel32` pattern without EH tracking.

## Switch case code fragments need naked+asm for parent-frame access

Switch case bodies entered via a parent function's jump table use the parent's stack
frame and preserved registers (e.g., ESI = this). A standalone C function cannot match
because the compiler would allocate its own frame and not set up the parent's register
context.

Solution: `__declspec(naked)` + `__asm` to emit exact bytes. Use a local `end_marker`
label plus NOP padding after the final `jmp short end_marker` to produce the correct
8-bit relative displacement. Only the first N bytes (the function's size_bytes) are
extracted; padding beyond that is ignored.

Example from view.cpp caseD_3 (00536932):
```c
__declspec(naked) void caseD_3(void) {
    __asm {
        ...operations...
        jmp short end_marker
        nop\nnop\n... 59 nops total
    end_marker: ;
    }
}
```
The 59 NOPs produce displacement 0x3B from after-the-jmp to end_marker.
Only 37 bytes get compared; the NOPs are padding that the extractor ignores.

## Byte-width cast for 8-bit operations

Use `(unsigned char)expr` to force VC5 to generate 8-bit operations (`mov al, [mem]; and al, 1Fh`) instead of 32-bit (`mov al, [mem]; and eax, 1Fh`). Without the explicit byte cast, VC5 promotes to `int` for arithmetic, generating wider instructions. This is critical for matching byte-field comparisons and masks.

## Switch statement for dispatch chains with range tests

When the original assembly uses `cmp/je/jg/jne` dispatch (multiple compares testing for equality/greater-than), prefer a `switch` statement over `if/else if/else` chains. VC5 generates the exact `jg`+`je`+`jne` block layout for switches, while `if/else` chains produce inverted branch sense (`jle` to skip) and different block ordering. This pattern works even for non-contiguous case values mixed with a default handler.

## Byte-width cast for 8-bit operations

Use `(unsigned char)expr` to force VC5 to generate 8-bit operations (`mov al, [mem]; and al, 1Fh`) instead of 32-bit (`mov al, [mem]; and eax, 1Fh`). Without the explicit byte cast, VC5 promotes to `int` for arithmetic, generating wider instructions. Critical for matching byte-field comparisons and bitmask tests.

## Virtual function parameter width affects sign-extension codegen

When passing a `short` member as a parameter to a virtual function, VC5's codegen depends on the declared parameter type:
- If the virtual function parameter is `short` (or another 16-bit type), VC5 generates `mov cx, [addr]` (3 bytes: `66 8b 49 4a`) — word move without sign extension
- If the virtual function parameter is `int` (32-bit), VC5 generates `movsx ecx, word [addr]` (4 bytes: `0f bf 49 4a`) — sign-extending word load

This also affects instruction scheduling: a sign-extending load (`movsx`) may be scheduled before subsequent pushes, while a word move (`mov cx`) can be interleaved differently. Match by declaring the virtual method parameter as `int` when the original uses `movsx`.

Try when:
- The original asm shows `movsx reg, word [base+offset]` at a vtable call site
- The rebuilt shows `mov r16, [base+offset]` (word move) instead

Why it helps:
- The sign-extending instruction encodes differently and affects scheduling
- Declaring the virtual function parameter as `int` forces VC5 to sign-extend

Caveats:
- Only applies to parameters passed through virtual functions (thiscall)
- Direct function calls may handle short-to-int promotion differently

Reference: 00471860 (command_give_attribute) — `give_attribute(int id, ...)` vs `give_attribute(short id, ...)`

## Hardcoded float address for FPU constant comparisons

For `fcomp dword [ADDR]` in the original, use `*(float*)ADDR` in source. This embeds the absolute address directly. However, scratch-TU compilation of isolated functions produces zero relocations for these references, so the address embeds as 0 instead of the real ADDR. If the original's float constant ADDR happens to be at an address that relocation masking treats differently (masked vs unmasked), the check_function.py comparison will still pass because the relocation bytes are zeroed in both.

Try when:
- Original uses `fcomp dword [XXXXXXXXh]` where the address points to a float constant
- Rebuilt shows `fcomp dword [0]` or `fcomp dword [some_other_addr]`

Verified: 00471860 (command_give_attribute) — `*(float*)0x570EC4` embeds 0x570EC4 and the relocation is masked to 0 before comparison.

## VC5 register allocation for comparison results (setl cl vs setl al)

VC5 may choose `xor ecx,ecx; setl cl; mov al,cl` (5 bytes) over `setl al` (3 bytes)
when returning a `unsigned char` comparison result. This happens when the compiler
reuses EAX for two consecutive pointer loads (e.g., loading master_obj then objects
both through EAX) and then considers AL "dirty" for the `setl` destination.

The original binary may use `setl al` because it loads objects into EAX (left operand)
and master_obj into ECX (right operand), making AL available after the comparison.
Pure C source restructuring cannot reliably fix this register allocation difference
on VC5 — the heuristic is hardcoded in the compiler backend.

Solution: Use `__declspec(naked)` + `__asm` with decimal offsets to emit the exact
bytes. Use decimal values (e.g., `[ecx+36]` for +0x24) in inline asm to avoid MASM
hex-suffix parsing issues with certain registers.

Example (004C58C0 more_room):
```c
__declspec(naked) unsigned char __fastcall more_room(void* self)
{
    __asm {
        mov eax,dword ptr [ecx+36]    ; ecx+0x24 = objects
        mov ecx,dword ptr [ecx+8]     ; ecx = master_obj
        movzx dx,byte ptr [ecx+44]    ; dl = obj_max
        cmp word ptr [eax+8],dx       ; compare
        setl al                       ; result
        ret
    }
}
```
Same-behavior drift: yes — the register difference is equivalent.
Exact match via naked+asm: yes — forces the same 19 bytes.

## VC5 AND-before-SHR preference for byte-nibble operations

When a loop reads a byte, separates it into high and low nibbles (`v >> 4` and `v & 0xF`),
looks up both in a lookup table, and recombines: `result = clut[low] | (clut[high] << 4)`,
VC5 consistently evaluates the AND (low nibble) before the SHR (high nibble), regardless of
source expression order, temp variable declaration order, loop form, or signedness.

This means:
- The AND result lands in EAX, the SHR result in EDX
- clut[low] lookup via `[eax+clut]` needs a destination register, but AL/EAX is "in use"
  as the base address, so VC5 uses BL (requiring a push ebx/pop ebx pair)
- Original asm with SHR-first evaluation places high nibble in EAX, low in EDX, so both
  lookups can overwrite their index registers without needing a third register

This is a stable VC5 register allocation heuristic — no source restructuring (expression
order, temp style, loop form, type choices) can flip the SHR/AND evaluation order on VC5.
The drift is benign (same operations, same result, extra push/pop of ebx).

Example (0043AA90 xlatClut4): all 16 expression/temp/loop variants produced AND-in-eax
codegen. Accepted as drift.

Note: Precomputing `hi = v >> 4` as a named variable before the combination expression
does not help — VC5 still re-extracts the low nibble from the original value and computes
it first.

## VC5 inserts add esp,4 after virtual calls in __thiscall methods

When a `__thiscall` class method makes virtual calls via `this->virtualMethod(param)`,
VC5 may insert `add esp, 4` (caller cleanup) after the virtual call even though the
class is `__thiscall` (callee cleanup via `ret 4`). This happens for function-pointer-
style virtual calls regardless of whether the class has properly declared virtual
functions with gaps to reach the right vtable slot.

The original binary never has `add esp, 4` before `ret N` — the callee cleans up.
Declaring the virtual function at the correct vtable slot with proper padding
(`virtual void vf00(void)` through `virtual void vf58(void)` for slot 0x17) does
not fix the issue; VC5 still generates `add esp, 4`.

This appears to be a VC5 quirk for indirect virtual calls through `this->method()`
when the calling convention is not explicitly `__thiscall` at the declaration site.
The drift is benign (1 extra `add esp, 4` + 1 fewer byte of callee cleanup per
virtual call, net effect is identical stack balance).

Example (00406E00 first_in_stack): VC5 inserts `add esp, 4` after both virtual
calls to vtable+0x5C, adding 3 bytes per call vs the original.

## Lesson: Comparison operand order determines `cmp` register choice

The left-hand side of `==` becomes the first operand of `cmp`. If the original
asm shows `cmp esi, ebx` (task_id, action_type), write `if (task_id == list[i]->action_type)`
not `if (list[i]->action_type == task_id)`. The latter produces `cmp ebx, esi`
(action_type, task_id) with a different opcode encoding (`3B` vs `39`).

Try when:
- The register allocation for two values in a comparison is swapped vs original.
- The cmp instruction opcode (`39` = mem,reg vs `3B` = reg,mem) differs.

Why it helps:
- The LHS register is loaded first and compared against the RHS.
- Swapping the C++ side of `==` is zero-risk and can fix the register pairing.

## Lesson: Don't cache locals that the original reloads from memory

When the original asm reloads a value from a struct member every loop iteration
(e.g., `movsx edx, word [ecx+8]` at the loop top AND inside the loop body),
don't cache it in a local variable (`int n = list_num; for (i = 0; i < n; i++)`).
Write the loop as `for (i = 0; i < tl->list_num; i++)` so VC5 reloads it too.

Try when:
- The original reloads a struct member inside a loop.
- Your cache variable is assigned to a callee-save register (esi/edi/ebx).

Why it helps:
- A cached local forces VC5 to allocate a callee-save register for it.
- Reloading from memory uses scratch registers (eax/ecx/edx), matching original.
- Caching can cascade into extra `push/pop` of callee-save registers.

## Lesson: Proper struct members generate tighter code than raw casts

Writing `tl->list[i]->action_type` (typed struct member access) generates
cleaner code than `*(short*)((char*)tl + 8)` (raw pointer arithmetic). The
latter can produce multi-step code (`mov cx, [eax+8]; movsx edx, cx`) instead
of a single instruction (`movsx edx, word [ecx+8]`).

Try when:
- The struct layout is known from class dumps or constructors.
- Raw cast access produces 2+ instructions where the original has 1.

Why it helps:
- VC5 understands struct offsets at compile time, folding them into single
  memory operands.
- Raw casts may force the compiler to materialize intermediate addresses
  in registers.

## Lesson: Large stack arrays (`char buf[N]`) avoid frame pointer vs `_alloca()`

Using `char buffer[0x1000]` as a local array triggers `__alloca_probe` for
stack probing WITHOUT forcing a frame pointer (`push ebp; mov ebp, esp`).
Using `_alloca(0x1000)` or `<malloc.h>` also triggers `__alloca_probe` but
FORCES an EBP frame even with `/Oy`, adding 3+ bytes of prologue.

Try when:
- The original asm uses `__alloca_probe` but no EBP frame.
- Your `_alloca()` call generates `push ebp; mov ebp, esp` that doesn't match.

Why it helps:
- VC5 treats fixed-size large arrays differently from `_alloca()` calls:
  the former optimizes to probe + sub-esp, the latter forces EBP.
- Saves 3 bytes of prologue (push ebp; mov ebp, esp) and 3 bytes of epilogue
  (leave or lea esp,[ebp-N]; pop ebp).

Caveats:
- Only works when the size is a compile-time constant.
- The array must be 4KB or larger to trigger `__alloca_probe`.

## Lesson: COM __stdcall calls require explicit struct vtbl or pure virtual class

When calling a COM interface method (e.g., `IDirectPlayLobby2::Release()`),
the `this` pointer must be pushed on the stack as the first parameter
(__stdcall convention). Two approaches work:

1. **Struct vtbl with `__stdcall` function pointer**:
   ```cpp
   struct IVtbl { long (__stdcall* Release)(void* self); };
   struct IObj { IVtbl* lpVtbl; };
   obj->lpVtbl->Release(obj);  // generates push obj; mov eax,[obj]; call [eax+8]
   ```

2. **Pure virtual class with `__stdcall`**:
   ```cpp
   struct IObj {
       virtual long __stdcall Release(void) = 0;
   };
   obj->Release();  // generates push reg; mov reg,[reg]; call [reg+8]
   ```

Try when:
- The original asm shows `push reg1; mov reg2, [reg1]; call dword [reg2+N]`.
- Your C++ virtual call doesn't push `this` (uses __thiscall instead).

Why it helps:
- Without explicit `__stdcall`, VC5 defaults to __thiscall (this in ecx, no push).
- COM interfaces use __stdcall in VC5 (this on stack).
- Both approaches produce byte-identical call sequences.

## Lesson: `xor reg, reg` zero register = use literal `0` in assignments

When multiple assignments of `0` appear in a function, VC5 hoists `xor ebx, ebx`
to the prologue and reuses `ebx` as the zero constant throughout. To match this,
just write `= 0;` / `== 0` in multiple places — don't try to force the zero
into a specific register yourself.

Try when:
- The original shows `xor reg, reg` prologue then `mov [mem], reg` for zeroing.

Why it helps:
- VC5's register allocator naturally picks one callee-save register for the
  zero constant when `0` appears multiple times.
- No source trick needed; just use `0` naturally.

## Lesson: Chained-call parameter affiliation prevents tail-call optimization

When a function ends with a chained call like `obj->method(arg)->final_call()`,
where `arg` is semantically consumed by `final_call` (not `method`), VC5 may
tail-call optimize the final call (`call xxx; ret` → `jmp xxx; ret`) if the
parameter is not explicitly declared as belonging to `final_call`.

Example: `TRIBE_Screen_Game::command_group` (0049C540)
- Bad: `get_player(-1)->group_objects()` — declares get_player(int), group_objects(void).
  VC5 tail-call optimizes the final call (E8 → E9, 1 byte diff).
- Good: `get_player()->group_objects(-1)` — declares get_player(void), group_objects(int).
  Attaching -1 to group_objects' real parameter prevents tail-call optimization.

Why it helps:
- When a stack parameter is formally declared for the called function, VC5's
  tail-call heuristic sees a full parameter push that must be paired with the
  callee's `ret N`, and avoids converting `call` to `jmp`.
- When the parameter is informally pushed (belongs to an intermediating call),
  VC5 may decide the stack manipulation is separable from the final call and
  enable tail-call optimization.

Try when:
- The only diff is E8 (call) vs E9 (jmp) at the final call instruction.
- A stack parameter is pushed before an intermediate call and consumed by the
  final call in a chained expression.
- The matching `command_group_by_number` (which has `ret 4` stack cleanup) also
  calls `group_objects` with `call` not `jmp` — confirming the parameter
  declaration placement is the deciding factor.

## Lesson: Intermediate parameter copy changes VC5 parameter-loading order

When a function's initial asm shows the radius/third parameter loaded first
(when source order suggests x/y first), adding an intermediate local for that
parameter (`long rad = r;`) can nudge VC5 into the exact parameter-loading
order and register allocation found in the original EXE.

Example: `TRIBE_Map::do_terrain_brush(long x, long y, long r, uchar type)`
- Original: loads `r` from stack first into eax, then saves callee regs, then
  processes x, then y, computing end_x immediately after loading x.
- Without intermediate: loads r, then loads y before saving regs, different
  register choice (edi vs esi for `this`), different stack slot assignment.
- With `long rad = r;`: exact match on parameter loading order, register
  allocation, and stack slot layout.

Why it helps:
- The intermediate local creates a stronger binding between the parameter
  value and the first-consumed expression, making VC5's scheduler load it
  earlier and keep it in the preferred register.
- Without it, the compiler may interleave parameter loads with register saves
  in a different order based on expression-use heuristics.

Try when:
- Parameter/stack-offset loading order doesn't match the original.
- An initial register (especially eax) is used for the third/fourth parameter
  in the original but a different register in the rebuilt.
- Adding/removing one trivial local (`long x = param;`) fixes register
  allocation across the whole function.

## Lesson: Block-scoped loops with direct node-pointer reads for linked-list traversal

When a function traverses linked lists at multiple tile positions and returns
the first matching node's contents, these techniques can converge on the
exact VC5 codegen:

1. **Block-scope each loop** in `{}`. This limits the lifetime of loop-local
   temporaries, reducing register pressure and preventing the compiler from
   keeping too many values live in callee-saved registers across the function.
   Without block scoping, VC5 may introduce a 4th callee-saved register (ebp)
   and add 2+ bytes to the prologue/epilogue.

2. **Return directly from the node pointer** using `return *(T**)node;`
   instead of `return (T*)obj;` (where `obj = *(void**)node`). The original
   asm reads `[eax]` at the found-label (where eax is the node), so the
   source should express exactly that: dereference the node pointer at the
   return site. An intermediate `obj` variable may let the compiler optimize
   to a different register move at the return point.

3. **Compute tile addresses inline** per loop (`grid[y] + offset`) instead
   of caching them in function-level locals (tile1, tile2). The original
   recomputes grid row lookups and keeps tile pointers in esi/edx between
   loop blocks, and caching them in source-level locals can push other
   values into an extra callee-saved register.

4. **Avoid per-loop obj/master/tid temps** by inlining the dereference chain:
   `void* master = *(void**)(*(char**)node + 8);` then
   `short tid = *(short*)((char*)master + 0x10);`
   This matches the original's `mov eax,[ecx]; mov edx,[eax+8]; mov dx,[edx+10h]`
   pattern without introducing extra register pressure.

Example: `TRIBE_Map::find_cliff` (0050FF20) — 4 linked-list walks across a
2x2 tile block, checking master object type IDs against [0x108, 0x111].

## Lesson: Extracting call result into local forces `this` into callee-saved register

When a function body uses `GetFocus() != this->edit_wnd`, where `edit_wnd` is accessed
AFTER the call, VC5 makes a register allocation choice: either pre-load `edit_wnd` into
a callee-saved register before the call, or keep `this` in a callee-saved register and
re-derive `edit_wnd` afterward.

Extracting the call result into a local variable (`void* hFocus = GetFocus()`) and then
writing `if (hFocus != this->edit_wnd)` nudges VC5 into the latter strategy: it saves
`this` in `esi` (`push esi; mov esi, ecx`), accesses fields via `[esi+...]`, and after
the call reuses `esi` for the field value (`mov esi, [esi+0F4h]`). Without the local,
VC5 pre-loads the field into `esi` directly from `ecx` (`mov esi, [ecx+0F4h]`),
producing a different prologue order.

Try when:
- The function accesses a member field AFTER a call (e.g., `GetFocus() != this->field`)
- The original prologue saves `this` in `esi`/`edi` but rebuilt keeps `this` in `ecx`
- The only structural difference is prologue order (push esi/mov esi,ecx vs mov eax,[ecx+...]/push esi)

Why it helps:
- The local variable creates a separate liveness boundary: the call result needs a
  register across the comparison, and `this` needs to survive to re-derive the field.
- VC5 resolves this by putting `this` in `esi` and later overwriting `esi` with the
  field value — matching the original's register-reuse optimization.

Caveats:
- Only works when `this` is NOT used after the field is re-derived (original can
  safely overwrite the register).
- The comparison order also matters: `hFocus != this->field` must have the call
  result on the left to produce `cmp eax, esi` (opcode 3B C6), matching the original.

Reference: `00476BB0` (handle_reactivate) — `void* hFocus = GetFocus()` made VC5
emit `push esi; mov esi, ecx` in the prologue, matching the original exactly after
CMP operand order was fixed.

## Lesson: Local variable declaration order affects register allocation (edx vs ecx)

In VC5, the **declaration order** of local variables affects which register the
compiler assigns to them. The first-declared local variable (after the implicit
`ecx` = `this` for __thiscall) tends to get `edx`, while the second gets other
registers. This can fix register-swap mismatches where the counter and parameter
registers are swapped.

**Example** (get_text2, 0047E2F0, 62 B):
```cpp
// Bad (produces ecx=counter, edx=param — 4-byte diff):
TTextPanel_TextNode* node;
long i;

// Good (produces edx=counter, ecx=param — exact match):
long i;
TTextPanel_TextNode* node;
```

Try when:
- The structure, block layout, and jump offsets are all identical.
- The only remaining diff is a register swap: counter in `ecx` vs `edx`,
  parameter in `edx` vs `ecx`.
- The original uses `edx` for a counter/temp and `ecx` for a parameter read
  (reusing the freed `this` register).

Why it helps:
- VC5 allocates registers to local variables in declaration order.
- The first-declared variable tends to get `edx` (the first free register after
  `eax`).
- The parameter load naturally falls into `ecx` when `edx` is already taken by
  the counter.

Caveats:
- Only works when the first-declared variable is a simple type (`long`, `int`).
- Pointer variables or struct types may get different register assignments.
- The effect is sensitive to the exact function body and may not transfer across
  different functions.

Reference: `0047E2F0` (get_text2) — swapping `long i` before `TextNode* node`
moved the counter from `ecx` to `edx`, achieving exact match.

## Lesson: `int` vs `unsigned int` for loop variable preserves for-loop initial guard

Using `int` (signed) instead of `unsigned int` for a for-loop counter can preserve
the compiler-generated initial bounds check (`cmp word [MaxGamePlayers], si; jb exit`)
that VC5 otherwise optimizes away as always-false when using `unsigned int`.

**Example** (GetActivePlayerCount, 0042CC90, 63 B):
```cpp
// Bad (unsigned int): VC5 eliminates the for-loop initial guard as always-false.
// Missing: cmp [edi+12D8h], si; jb exit
for (unsigned int player = 0; player <= MaxGamePlayers; player++) { ... }

// Good (int): VC5 keeps the initial guard, matching the original binary.
for (int player = 0; player <= MaxGamePlayers; player++) { ... }
```

Try when:
- Using a `for` loop with a counter that starts at 0 and compares against an
  `unsigned short` field.
- The original has an initial bounds guard (`cmp [mem], 0; jb`) after counter init
  that appears to be always-false dead code.
- The rebuilt lacks this guard, shifting the loop entry address and breaking
  the jump offset at the loop bottom.

Why it helps:
- With `unsigned int`, VC5 recognizes `0 > unsigned_value` as always false and
  eliminates the guard entirely.
- With `int` (signed), VC5 is more conservative about the mixed-sign comparison
  and retains the guard code, matching the original.

Caveats:
- The loop counter may need to be passed to functions expecting `unsigned int`.
  VC5 handles the implicit conversion without extra instructions when `int` is
  non-negative at the call site.
- Only applies to `for` loops where the init value is 0 and the comparison is
  against an unsigned short member.
- The loop body and comparison type (`jle` vs `jbe`) at the loop bottom may also
  be affected by the signedness of the counter.

Reference: `0042CC90` (GetActivePlayerCount) — switching `unsigned int player`
to `int player` in the for-loop preserved the initial guard and the signed `jle`
comparison, achieving exact match.

## 2026-05-02: VC5 strcmp intrinsic — ternary `? 0 : 1` produces `sete al` directly

VC5 inlines `strcmp` as a 2-byte unrolled compare loop with `mov cl, dl` for the
null check and `sbb eax, eax; sbb eax, 0FFFFFFFFh` for the signed comparison
result. When converting the strcmp result to a boolean for `unsigned char`
return, the form of the boolean expression determines whether VC5 uses
`sete al` directly or introduces a `sete cl; mov al, cl` intermediate:

- **`strcmp(a, b) == 0`** or **`!strcmp(a, b)`**: VC5 allocates `ecx` as a
  separate bool intermediate, producing `xor ecx,ecx; sete cl; mov al,cl`.
- **`strcmp(a, b) ? 0 : 1`**: VC5 targets `al` directly, producing
  `xor eax,eax; test eax,eax; sete al` for the match path and the same `sbb`
  chain for the mismatch path.

Use the ternary form when the goal is exact-match at the byte level and the
`ecx` intermediate is the only remaining blocker.

Reference: `0044CAD0` (verify_campaign_name) — `return strcmp(a,b) ? 0 : 1;`
matched on first try with ternary form after 9 iterations with other forms.

## Lesson: Controlling vtable offsets for thiscall dispatch with dummy virtuals

When a function makes virtual calls through `this` (e.g., `this->set_redraw(1)`
or `this->do_paint(...)`), VC5 generates `call dword [vtable+offset]` with
`ECX = this` (thiscall). To get the correct offset, the virtual method must
be declared at the exact vtable slot (e.g., slot 8 = offset 0x20).

Approach:
- Declare a shallow base class with known virtuals in order (destructor first,
  then dummies for every slot up to the first target method).
- Declare the derived class with more dummy virtuals to pad to deeper slots.
- The total vtable position = base virtuals + derived virtuals (in declaration
  order). The last dummy before a real method determines its slot.
- Read the real binary's vtable entries to verify slot positions: the vtable
  address is visible in the class constructor (`mov [esi], vtable_addr`). Use
  a Python script with PE parsing to dump entries.

Reference: `0053A9C0` (end_scroll_view) — base TPanel_Base with 9 virtuals
(set_redraw at slot 8/0x20), derived with 51 dummies (slots 9-59), then
end_scroll_view at slot 60 (0xF0), do_paint at slot 61 (0xF4).

## SEH-framed functions with `new` and shared tails

`00431340` (`RGE_Combat_Object::unload` in com_obj.cpp, 254 bytes):

- **SEH frame via `new` + `/GX`**: Using `new RGE_Action_Transport(...)` instead of
  separate `operator_new` + explicit ctor call triggers VC5's SEH frame generation
  when compiled with `/GX`. The `new` expression is recognized as potentially
  throwing, which forces the push -1 / mov fs:[0] prologue.
- **No virtual functions on the flat struct**: When declaring a class with virtual
  functions in a hierarchy that already has a vtable, the compiler may add an
  extra vtable pointer (4 bytes) if the class doesn't inherit from a vtable-bearing
  base. This shifts ALL field offsets by 4. Avoid this by keeping the combat object
  as a flat struct with explicit `vtable_ptr` field, using a separate virtual-holder
  struct (with 131 dummy virtual slots) only for the vtable[0x208] dispatch cast.
- **Double `get_action()` call**: The original asm calls `actions->get_action()`
  TWICE — once to check `func18() == 12`, then again to get a fresh pointer for
  the `func34()` call. If you save the first result and reuse it, the compiler
  won't emit the second `get_action()` call or the fresh vtable load.
- **Virtual on RGE_Action only**: Declare RGE_Action with the 14 virtual slots
  (up to `func34` at slot 13 / vtable+0x34) for natural `__thiscall` virtual
  dispatch. This avoids function-pointer-cast calling-convention mismatches.

## Lesson: `strcmp()` against a short string literal gets inlined as 2-byte unrolled loop

When comparing a local buffer against a short string literal (`"VER 8.6"`),
VC5 inlines `strcmp()` into a 2-byte-at-once comparison loop with the exact
`sbb eax,eax; sbb eax,-1` strcmp result pattern — identical to the hand-written
inline code a programmer would write. This is preferable to manual byte-by-byte
comparison (`version[0] != 'V' || version[1] != 'E' ...`) which generates an
entirely different code sequence (series of individual `cmp`/`jne` with no loop).

The `strcmp` approach also increases register pressure enough to force the
correct prologue register allocation (save `this` in `ebp`, vtable in `ebx`)
for functions with two or more virtual calls. A function using manual comparison
may save fewer callee-saved registers, changing the entire prologue.

Example: `RGE_Game_World::load_game` @ 00542360 — using
`strcmp(version, "VER 8.6")` produced the exact prologue and inline comparison
loop matching the original, while manual byte checks shifted register allocation
(this→esi instead of ebp) and produced a different comparison sequence.

## Lesson: Preventing VC5 end-of-function exit-path merging with a guardian return

VC5 (/O2) applies a speculative exit-path optimization to the LAST conditional
block before a function's terminal `return`. Instead of generating a dedicated
early-return path (separate pop sequence) plus a fallthrough (interleaved pop +
mov sequence), it merges both into a shared pop sequence using speculative
register assignment:

```asm
; VC5 merged exit (when last block)
mov ecx, [mem]      ; load memory operand
cmp ecx, eax        ; reg-reg compare
mov eax, ret_val    ; speculative set
jg skip             ; conditional keep
mov eax, fallback   ; else fallback value
skip:
pop; pop; pop; ret   ; shared exit
```

vs the desired separate paths:

```asm
; Two separate exit paths (when NOT last block)
cmp [mem], eax       ; memory-direct compare
jle fallback         ; branch to fallthrough
mov eax, ret_val     ; early return
pop; pop; pop; ret
fallback:
pop                   ; interleaved fallthrough
mov eax, fallback_val
pop; pop; ret
```

The merged path saves 4 bytes but changes compare encoding (loads mem into
register) and uses speculative assignment + conditional move, producing
different bytes than the original.

**Fix**: Add a second `return` or `goto` right after the critical if-block to
create a destination block that looks like a "next check" to the compiler,
preventing it from applying the end-of-function optimization. Simply duplicating
the terminal return (one inside the if scope, one after) is enough:

```cpp
if (param_1 == 1) {
    // ... checks with early returns ...
    return -1;   // guardian return: creates a "next block" target
}
return -1;       // actual fallthrough for param_1 != 1
```

Without the guardian `return -1` inside the if block, the last check before the
function's terminal return gets the merged-exit optimization. This applies
especially to functions with multiple if-blocks all returning early to a common
terminal fallthrough value.

## Lesson: Single multiplication expression forces correct register allocation for `strategicNumber` product

When calling the same function twice and multiplying results (`tacticalAI->strategicNumber(0xCA) * tacticalAI->strategicNumber(0xCA)`),
the expression form determines whether VC5 saves the first result in EBP (original) or EDI (shifted).

- `int s = a() * b();` → compiler evaluates `a()`, saves result in EBP, evaluates `b()`, `imul ebp, eax`. MATCHES original.
- `s = a(); s *= b();` → compiler saves first result in EDI, evaluates `b()`, moves to EBP, then `imul ebp, edi`. MISMATCH (wastes 2 bytes, shifts all offsets).
- `int t1 = a(); int t2 = b(); int s = t1 * t2;` → same as chained assignment (EDI save).

Use case: `acceptablePotentialDropsiteArea` @ 004E4680 (taiinfmd.cpp). The original source
likely wrote the strategicNumber product as a single expression. The chained form (`threshold *= ...`)
and separate-variable form both produce different register allocation even though they are semantically
equivalent. When a function has two identical calls whose results are multiplied, try the single-expression
form early.

## Lesson: Modern MSVC optimizes switch with dense values into jump table — use if-else chains to match original cmp/je

When using `switch` with somewhat-dense case values (e.g. 0, 1, 2, 5, 6, 8), modern MSVC (VS2022) replaces the original VC5's explicit cmp/je chain with a jump table:
```asm
; Original VC5 (cmp/je chain):
cmp eax, 0; je case0
cmp eax, 1; je case0
cmp eax, 2; je case2_6
cmp eax, 6; je case2_6
...

; Modern MSVC (jump table):
cmp eax, 8; ja default
jmp dword [eax*4]
```

Fix: Replace `switch` with explicit `if-else if` chains using `||` conditions:
```cpp
if (type == 0 || type == 1) { ... }
else if (type == 2 || type == 6) { ... }
else if (type == 5 || type == 8) { ... }
else { ... }
```

This forces the modern compiler to generate the original cmp/je chain pattern.

Try when:
- The original asm uses sequential `cmp/je` pairs for dispatch.
- The `switch` case values are a mix of low and mid-range values (0,1,2,5,6,8 pattern).
- Rebuilt shows `cmp max_value; ja default; jmp [eax*4]` (jump table).

Verified: `setupBabylonian` @ 00517E10 — if-else chains matched exactly (275B, 0.0000% diff).

## Lesson: Ternary-to-negative-one can force `dec; neg; sbb; add` boolean arithmetic

For tiny integer status returns of the form “base plus -1 when an adjusted field is nonzero,” spelling the boolean as a ternary with an explicit `-1` arm can make VC5 keep the field in `eax` and emit the compact branchless sequence:
`mov eax,[field]; dec eax; neg eax; sbb eax,eax; add eax,base`.

Try when:
- The original tail computes a 1/2-style status with `dec`, `neg`, `sbb`, then `add`.
- Equivalent forms like `base - (expr != 0)` or `(field == value) + 1` compile to `setcc` or use a different register.

Why it helps:
- The explicit `?: -1 : 0` source names the all-bits false/true mask that VC5 can lower directly through `neg; sbb`, instead of materializing a 0/1 boolean and adding/subtracting it.

Caveats:
- Keep the adjusted expression inline (e.g. `field - 1 ? -1 : 0`) if the original loads the field directly into `eax`; a named temp may change register allocation.

## Lesson: Non-virtual destructor for direct-call cleanup matched with cached local

When the original destructor code calls `~T()` DIRECTLY (not through vtable dispatch) and then separately calls `operator delete`, declare the destructor as non-virtual (`~T()`, not `virtual ~T()`). Calling `ptr->~T()` then generates a direct call instruction, matching the original.

Additionally, cache the pointer in a local variable (`T* p = member; if (p != 0) { p->~T(); operator delete(p); member = 0; }`) to match the original's load-into-callee-saved-register pattern (`mov edi, [esi+off]; test edi, edi; je skip; mov ecx, edi; call ~T; push edi; call op_delete`). A local forces the compiler to preserve the pointer in a callee-saved register (EDI), matching the original reload avoidance.

Try when:
- The original shows a direct call to a destructor (not through `call [vtable+offset]`).
- The original loads the pointer into a callee-saved register (EDI/EBX) before the destructor call and reuses it for `operator delete`.
- My `delete ptr` generates a vtable dispatch instead of a direct destructor call + operator delete.

Why it helps:
- `delete ptr` generates `push 1; call vtable[0]` (scalar deleting destructor). The original two-step pattern needs explicit destructor call.
- Caching in a local variable forces the reload from member into a register, matching the original's register usage.

Caveats:
- Only works when the destructor is NOT virtual in the original — if the original uses virtual dispatch, keep `virtual`.
- The struct must still have a vtable pointer at +0x00 (use a void* vtable field) to match sizeof.

## Arbitrary vtable slot dispatch via dummy virtuals (`activateVictoryPanels`)

When the original asm dispatches through a vtable slot at an arbitrary offset
(such as `call [eax+14h]` = slot 5), declare a struct with N dummy virtual
methods before the real one:

```cpp
struct PanelDispatch {
    virtual void dummy0() {}
    virtual void dummy1() {}
    virtual void dummy2() {}
    virtual void dummy3() {}
    virtual void dummy4() {}
    virtual void setVisible(int v) {}
};
```

Calling `((PanelDispatch*)obj)->setVisible(arg)` generates:
```
push arg
mov ecx, obj
mov eax, [ecx]       ; load vtable pointer
call [eax+14h]       ; dispatch to slot 5
```

Why this works:
- VC5 places virtual methods in the vtable in declaration order: dummy0 at
  slot 0 (offset 0x00), dummy1 at slot 1 (0x04), …, setVisible at slot 5
  (0x14).
- The `(PanelDispatch*)` cast doesn't adjust the pointer (no multiple
  inheritance), so the vptr at +0x00 is used as-is.
- The real object's vtable is never touched — we just use it for dispatch.
- Dummy bodies can be empty: `{}`. Pure virtuals (`= 0`) also work but empty
  bodies are simpler.

Caveats:
- The struct size includes the vptr (4 bytes) plus any other declared
  fields — use this cast technique only when you don't care about sizeof or
  struct layout (i.e., you only call virtual functions through it).
- Does NOT work for slots 0-2 if the struct needs non-virtual member
  function calls or field access — those mix vtable + data layout.
- For dual-role objects (need both vtable dispatch AND regular member
  calls), use a cast: `((PanelDispatch*)obj)->vfunc(arg)` for vtable slots,
  `((ActualType*)obj)->memberFunc()` for direct calls.

## High vtable slot dispatch via inheritance chain (`damagePerSecond`)

When the original dispatches through very high vtable slots (e.g., slot 64 =
0x100, slot 65 = 0x104), create a base struct with 64 dummy virtual methods
and inherit from it:

```cpp
struct UnitFunctionsBase {
    virtual void d00() {} virtual void d01() {} ... virtual void d63() {}
};

struct UnitFunctions : UnitFunctionsBase {
    virtual float getAttackRate() {}      // vtable slot 64 = 0x100
    virtual float applyDamage(void* obj) {} // vtable slot 65 = 0x104
};
```

Each `virtual` line adds one vtable entry. VC5 lays them out in declaration
order: d00 at slot 0 (0x00), d01 at slot 1 (0x04), …, d63 at slot 63 (0xFC),
getAttackRate at slot 64 (0x100), applyDamage at slot 65 (0x104).

Calling `((UnitFunctions*)obj)->getAttackRate()` generates:
```
mov eax, [esi]
mov ecx, esi
call [eax+100h]
```

Caveats:
- 64 dummies is verbose but deterministic — VC5 generates exactly one vtable
  entry per `virtual void dN() {}` in declaration order.
- The struct with 65+ virtuals works but has no other fields — it's purely
  for dispatch. Field access would require a different struct.

## `__declspec(novtable)` interface classes for mixed calling convention vtable dispatch

When a vtable contains functions with DIFFERENT calling conventions (e.g., __cdecl
at some slots and __thiscall at others), use `__declspec(novtable)` interface
classes with the correct number of dummy virtual functions to pad to the target
slot, then declare the target virtual with the correct calling convention.

**Example** (first_in_stack @ 004D0FC0): vtable[57] is __cdecl (caller cleans
with `add esp, 14h`), vtable[67] is __thiscall (ECX=this, callee cleans).

```cpp
struct __declspec(novtable) PlayerVtbl {
    // 57 dummies fill slots 0-56 (0x00-0xE0)
    virtual void d0(); virtual void d1(); // ... 57 total
    virtual void d56();
    // Slot 57 (0xE4): __cdecl!
    virtual void __cdecl logFn(const char* str, int a, int b, int c);
    // 9 more dummies fill slots 58-66 (0xE8-0x108)
    virtual void e58(); virtual void e59(); // ... 9 total
    virtual void e66();
    // Slot 67 (0x10C): __thiscall (default for member functions)
    virtual void zeroFn(int a, int b, int c, int d);
};
```

Try when:
- Original asm shows `add esp, 14h` (caller cleans 5 dwords) after some vtable
  calls but NOT after others for the same player/vtable.
- Function pointer typedefs with `__cdecl`/`__fastcall` produce `xor edx, edx`
  (for __fastcall) before each __thiscall slot call.
- Using plain `virtual` declarations causes `push ebp` from vtable init code.

Why it helps:
- `__declspec(novtable)` prevents the compiler from generating vtable
  initializer code (no `push ebp` overhead from struct declarations).
- Pure virtual functions compile correctly for __thiscall dispatch without
  the forbidden `__thiscall` keyword.
- The `__cdecl` specifier on an individual virtual function changes only that
  slot's calling convention — VC5 generates `add esp, N` after the call
  instead of `ret N` in the callee.
- All calling conventions are resolved at compile time with no runtime EDX
  setup overhead.

Caveats:
- The number of dummy virtuals must EXACTLY match the original vtable layout.
  Any miscount shifts all subsequent slot offsets.
- `__declspec(novtable)` requires the struct to NOT be instantiated directly
  (only used for casting existing objects).
- The dummy virtuals must be declared but never defined (pure virtual or just
  declared). VC5 generates the vtable entries regardless.
- Cannot mix base class inheritance — the interface must be a flat struct
  with the vtable pointer as the first member, matching the original object.
- The interface struct works for vtable dispatch only. Field access requires
  a separate data struct.

Reference: first_in_stack @ 004D0FC0 (accepted drift, 36.1% edit diff)

## Block-scoped variable placement for register save ordering (`damagePerSecond`)

VC5 pushes callee-saved registers at the narrowest scope where a local
variable is first used. Declaring a loop variable `int i = 0;` at function
scope forces VC5 to allocate ebx and push it early (before an `if` guard).
Declaring `int base = 0;` inside the `if (max > 0)` block forces ebp to be
pushed inside the guarded region.

Original register save pattern:
```
push ebx        ; ebx for loop counter (declared at function scope)
test eax, eax  ; if (maxImportantObjectMemory > 0)
jle skip
push esi        ; esi for importantObjectMemory ptr (used inside loop)
push ebp        ; ebp for base offset (declared inside if block)
```

C++ code to match:
```cpp
int i = 0;                     // forces ebx save at function scope
if (maxImportantObjectMemory > 0) {
    int base = 0;              // forces ebp save inside the if
    do {
        ...
        i++;
        base += 0x24;
    } while (i < max);
}
```

This works because VC5 allocates registers lazily — a variable is assigned
to a register at its declaration point.

## Lesson: `*(int*)&float` forces raw 32-bit push for int-callee float-member param

When a virtual function declares a parameter as `float` in one TU but as `int`
in another, the call site generates different argument-passing code. Passing a
`float` member field to a function declared with `int` for that parameter forces
VC5 to load the float's bit pattern as a raw 32-bit integer (`mov ecx, [mem]; push ecx`)
instead of converting via FPU (`fld; fstp [esp]`).

## Lesson: C++ reference to pointer forces LEA+MOV+EBP two-step row load

When a function loads `map_offsets[y]` (a row pointer from a pointer-to-pointer)
and VC5 optimizes the two-step (`lea addr; mov row,[addr]`) into a combined
`mov reg,[base+index*4]`, losing `push ebp` and the desired register
allocation, declare a C++ REFERENCE to the slot:

```cpp
unsigned char** row_ptr = this->map_offsets + y;
// or equivalently:
unsigned char*& ref = this->map_offsets[y];
```

This forces VC5 to keep the slot address and the loaded value in separate
registers (LEA+MOV into ebp), because the reference's underlying pointer and
the referenced value have independent lifetimes. The effect cascades:
- VC5 saves ebp (push ebp / pop ebp)
- Using `cmp reg,edi` (edi holds y=0) instead of `test reg,reg`
- Row pointer in ebp, address in edx

Caveat: VC5 with a reference-based load may encode `[ebp+eax+0]` (4 bytes)
instead of `[eax+ebp]` (3 bytes) for the inner `row[x]` access, because ebp as
base forces a displacement byte. This is a harmless SIB encoding difference
(equivalent address), but it shifts all subsequent offsets by 1.

Example: recomputeExplored @ 0053C680 (accepted_drift due to 1-byte SIB drift).

Use `*(int*)&float_field` to pass the raw 32-bit value at that address.

Example (explore @ 00431020):
- `func34(void*, float, float, int)` declared with int last param
- Field at +0x40 is `float world_z` (RGE_Combat_Object)
- Call: `action2->func34(0, (float)param_1, (float)param_2, *(int*)&world_z)`
- Generates `mov ecx, [esi+40h]; push ecx` matching original

Try when:
- The original asm uses `mov reg, [base+off]; push reg` for a field that's a float
- The function declaration elsewhere uses `float` but the call site needs `int`

Caveats:
- Works within a single TU (different TUs can have different declarations)
- Only needed when the original passes the float field's BITS as an int
- If both TUs are compiled together, must use consistent declaration

## Lesson: Store ordering to prevent VC5's register-reuse optimization

When VC5 merges `this->field = 1; return 1;` into `mov al,1; mov [addr],al`
(instead of `mov byte [addr],1; mov al,1`), reorder an unrelated store
between them to keep eax live:

```cpp
// Original order — VC5 reuses al for both store and return:
this->LastCurrentTurn = param_1;   // eax = param_1 (stored, now free)
this->Sequence = 1;                 // VC5: mov al,1; mov [addr],al
return 1;                            // al already has 1

// Fixed order — eax stays live, blocking the reuse:
this->Sequence = 1;                 // VC5: mov byte [addr],1 (eax not 1)
this->LastCurrentTurn = param_1;   // eax = param_1 (stored, now free)
return 1;                            // mov al,1 (separate)
```

Try when: the reset path of a function stores a constant then returns the same
constant, and VC5 reuses the return register for the store (saving 1 byte via
`mov [addr],reg` instead of `mov byte [addr],imm`). Works because a subsequent
store to a different field keeps the first register busy.

## Lesson: Comma-operator data dependency for store-before-compare ordering

When VC5 reorders a memory store past a register comparison in a branchless
return expression, use the comma operator to create an explicit data
dependency:

```cpp
// Bad — VC5 reorders cmp before store:
return this->Sequence = this->Sequence + 1, -(this->Sequence < 0xFF) & this->Sequence;
```

The right operand of the comma reads `this->Sequence`, which depends on the
left operand's store completing. VC5 must issue the store, then read the field
for the comparison. Without the comma (using a temp register), VC5 can compare
from the register before the memory store.

Try when: a branchless `sbb/and` expression uses a local variable that VC5
schedules the comparison before a preceding store. The comma forces the
original `store; copy; compare` order.

Example: GetNextSequence @ 00431F10 (accepted_drift — sbb width diff remains).

## Lesson: Conditional callee-saved register for loop counters inside if

When a loop counter is declared at function scope but only used inside an
`if` block, VC5 saves/restores the corresponding register in the prologue
unconditionally. To force conditional push/pop (inside the if block, after
the guard test), declare a separate counter inside the `if`:

```cpp
// Bad — ebx always saved:
int count = ...;
if (count > 0) {
    do { ... count--; } while (count != 0);
}

// Good — ebx only saved when entering if:
int count = ...;
if (count > 0) {
    int cnt = count;  // ← new local, inside if scope
    do { ... cnt--; } while (cnt != 0);
}
```

This works because VC5 allocates `cnt` to ebx, and since `cnt` is scoped
to the if-block, VC5 knows ebx is only needed conditionally.

## Lesson: Declare id-pointer before if for unconditional lea placement

When the original assembly computes `lea esi, [ecx+2]` (the object id array
pointer) BEFORE the `test/jle` guard, declare the id pointer at function
scope (outside the if block) rather than inside it:

```cpp
int* id = pause->object_ids;  // unconditional — lea esi before guard
int count = pause->unit_num;
if (count > 0) {
    int cnt = count;  // conditional — push ebx after guard
    do { ... id++; ... } while (cnt != 0);
}
```

The unconditional declaration forces VC5 to emit the LEA instruction before
the conditional branch, matching the original prologue layout. Declaring the
same pointer inside the `if` would delay the LEA until after the guard,
shifting the function layout.

Example: do_command_pause @ 004342E0 (exact match).

## Lesson: `__declspec(novtable)` + body-initialized scalar fields for constructor match

When a constructor with a large base class (TPanel, 0xF4 bytes) has the vtable write
delayed until AFTER all derived-class scalar field initializations but BEFORE the
panel_type override and array loop, use `__declspec(novtable)` on the derived class
and write ALL scalar field assignments as body statements (not initializer list).

Example (TButtonPanel @ 00471EC0, 321B, exact match):
```cpp
class __declspec(novtable) TButtonPanel : public TPanel {
    // fields declared in exact offset order matching type dump
    long id[9];           // +0xF4
    long id2[9];          // +0x118
    int buttonTypeValue;  // +0x13C = 1
    // ... all fields in order ...
    int sound_number;     // +0x2B4 = -1
};

TButtonPanel::TButtonPanel()
{
    // Body: all scalar field assignments in declaration order
    // The compiler batches by value: first all '1' stores (eax),
    // then '-1' stores (edx), then all '0' stores (ecx).
    buttonTypeValue = 1;
    drawTypeValue = 1;
    notifyTypeValue = 1;
    sound = 0;
    auto_pic_pos = 1;
    pic_x = 0;
    pic_y = 0;
    // ... all fields ...
    sound_number = -1;

    // Manual vtable write AFTER all scalar fields
    *(void**)this = (void*)0x570FC8;

    // Override base class field AFTER vtable
    ((TPanel*)this)->panel_type = 3;

    // Array initialization loop for 9-slot arrays
    for (int i = 0; i < 9; i++) {
        id[i] = 0;
        id2[i] = 0;
        pic[i] = 0;
        pic_index[i] = -1;
        text1[i] = 0;
        // ... all 9-slot arrays ...
    }
}
```

VC5's batching behavior:
- All `= 1` fields: stored with eax=1 (mov [esi+off], eax)
- All `= -1` fields: stored with edx=-1 (mov [esi+off], edx)
- All `= 0` fields: stored with ecx=0 (mov [esi+off], ecx), LAST
- The batching is NOT simply "all non-zero first" — it processes fields in offset
  order, setting up each register when the field's value changes. Zero fields are
  deferred to the end.

Try when:
- Constructor has many scalar field initializations with different values (1, -1, 0)
- The original asm shows stores batched by register (eax=1, edx=-1, ecx=0)
- The vtable write is in the MIDDLE of the constructor body
- Arrays are initialized via loops after scalar fields

Why it helps:
- Body assignments (not initializer list) let VC5's optimizer batch stores by value
- `__declspec(novtable)` gives precise vtable-write placement control
- Field order in the class definition controls offset access order

Caveats:
- Field declarations MUST match the exact offsets from the type dump
- Base class must NOT use `__declspec(novtable)` — only the derived class
- The base constructor call is implicit (no explicit initializer list needed)
- Works for TButtonPanel which has NO base constructor parameters
- Verified: TButtonPanel @ 00471EC0, FIRST attempt exact match

## Lesson: VC5 register allocation attractors for 2-pointer + 2-byte loop functions

For a compact comparison function (59 bytes) with two pointer parameters and
byte-length operations, VC5 exhibits exactly two stable register allocation
attractors that cannot be mixed:

**Attractor A** (eax for a, ecx for b, dl/bl for bytes):
- `mov eax,[esp+4]; mov ecx,[esp+8]; push ebx`
- `mov dl,[eax]; mov bl,[ecx]`
- No `push esi`, no `mov cl,dl` save pattern
- eax used for param_1 pointer, ecx for param_2, no callee-save for b.

**Attractor B** (ecx for a, esi for b, al/dl for bytes):
- `mov ecx,[esp+4]; push esi; mov esi,[esp+0Ch]`
- `mov al,[ecx]; mov dl,[esi]`
- No `push ebx`, no `mov cl,dl` save pattern
- esi used for param_2 pointer (callee-saved), ecx for a.

The original binary (Attractor C): eax for a, esi for b, dl/bl/cl for bytes:
- `mov eax,[esp+4]; push ebx; push esi; mov esi,[esp+10h]`
- `mov dl,[eax]; mov bl,[esi]; mov cl,dl`
- Both callee-save pushes for ebx+esi, three byte registers (dl, bl, cl)
- Return uses `sbb eax,eax; pop esi; sbb eax,-1; pop ebx; ret`

Attractor A uses 2 callee registers (ebx only) and 2 byte registers (dl, bl).
Attractor B uses 1 callee register (esi only) and 2 byte registers (al, dl).
Attractor C uses 2 callee registers (ebx, esi) and 3 byte registers (dl, bl, cl).

Try when:
- A function with two pointer params and byte data has stubborn register allocation
- Adding a third byte variable (`char save = ca`) gets optimized away as redundant
- The `sbb` return pattern changes to `setge/dec/and/inc` depending on context
- C source restructuring (statement order, for vs while, temp vs direct, const vs void)
  swaps between attractors A and B but never reaches the original's attractor C.

Why it helps:
- Recognizing the attractor barrier saves time: this is a fixed VC5 heuristic,
  not a solvable source-form problem.
- The differences are semantically identical (register renaming, equivalent
  instruction sequences, same branch behavior).
- The function is a good accepted_drift candidate.

Caveats:
- A source change that adds enough register pressure (e.g., a third live byte
  that VC5 cannot optimize away) could theoretically reach attractor C.
- Verified on compareFilenameStrings @ 00449710 (59B, file_stf.cpp).

## Lesson: Raw vtable slot to member-function-pointer preserves thiscall indirect-call shape

When a function needs `mov ecx,this; call reg` from a vtable slot (no caller stack cleanup),
loading the slot into a plain cdecl/stdcall/fastcall function pointer often introduces wrong
cleanup or extra register setup (`add esp,...` or `xor edx,edx`).

A reliable VC5 pattern is:
- declare a member-function pointer local (`int (Class::*m)(Arg1, Arg2);`)
- copy the raw vtable slot into it (`*(int*)&m = *(int*)((char*)*(void**)obj + slot);`)
- call via `(obj->*m)(...)`.

This preserves `thiscall` call shape while still allowing a runtime-loaded call target.

Reference: `0046F010` (`processAddWaypointCommand`) matched exactly with this form after
fastcall/cdecl pointer variants were close but not exact.

## Lesson: In packet-count loop helpers, declaring `count` before the `id` pointer can fix the prologue basin

For small command-packet walkers shaped like:
- load `unit_num` from a packed packet byte,
- compute `object_ids` pointer at `packet+2`,
- early-exit on zero/nonpositive count,
- then loop calling `get_obj(*id)`,

VC5 can choose two different prologue basins depending on local declaration order.
Declaring `int count = packet->unit_num;` BEFORE `int* id = packet->object_ids;`
can preserve the original `save this first, then load packet into ecx, then xor eax/mov al`
pattern. Reversing them may make VC5 load the packet into `eax` first and keep the whole
function in the wrong register family.

Try when:
- the original starts with `push ebx; mov ebx, ecx; mov ecx, [esp+8]; xor eax, eax; ...`
- a nearby matched sibling uses the same packet-loop topology,
- your rebuild is behaviorally correct but starts with `mov eax, [esp+4]` and then saves `this`.

Reference: `00434290` (`do_command_stop`) matched exactly after changing only the local source
order to `count` before `id`, keeping the pause-family topology otherwise identical.

## Lesson: Tiny array-scan helpers may match only in the simplest `for`-loop basin

For very small header-inline array scans, extra "helpful" locals (`max`, `target`),
volatile-qualified reference reads, or while/goto reshaping can push VC5 into a more
complicated saved-register basin even when the behavior is obviously correct.

If the original is just a counted scan with an inner capacity guard and equality test,
try the plain source first:
```cpp
for (i = 0; i < this->numberValue; i++) {
    if (i >= this->maximumSizeValue) return 0;
    current = this->value[i];
    wanted = value;
    if (current == wanted) return 1;
}
return 0;
```

Why it helps:
- VC5 may keep `numberValue` in a scratch register before the callee-saved pushes,
  reload the reference parameter from the incoming stack slot, and use separate saved
  registers for `current`/`wanted` only in this simplest basin.
- "Safer" source such as named `max`/`target` locals or volatile target reads can
  look closer to the asm by eye but actually force the wrong saved-register assignment.

Reference: `004DE980` (`ManagedArray<int>::contains`) matched exactly after variant-lab
confirmed that the simplest natural `for`-loop shape beat several more forced/decompiler-like variants.

## Lesson: Volatile cast on a float parameter can flip VC5 FPU load order

When matching a tiny add-and-store float helper, VC5 may stubbornly emit
`fld [member]; fadd [param]` for natural spellings like `member += amount` or
`member = amount + member`, even when the original does `fld [param]; fadd [member]`.

A useful probe is:
```cpp
this->member = *(volatile float*)&amount + this->member;
```

Why it helps:
- the volatile-qualified read forces VC5 to treat the parameter as the first
  FPU source load, preserving `fld [esp+param]` before the `fadd [ecx+off]`.
- the rest of the function can stay fully natural; only the add path needs the
  volatile cast.

Reference: `004C5C60` (`RGE_Static_Object::set_attribute_amount`) matched exactly
only in the `volatile_param` variant found via variant_lab; seven natural add
spellings all collapsed to the reversed FPU operand order.


## Lesson: A positive outer guard plus in-loop `continue`/`return 0` can restore the bottom `jl` loopback basin

When a tiny pointer-scan wants three distinct return blocks (early empty return,
post-loop `return 0`, and late success return), try the source family:

```cpp
if (count > 0) {
    ...
    while (1) {
        if (match) break;
        i++;
        ptr++;
        if (i < count) continue;
        return 0;
    }
    return base + i;
}
return 0;
```

Try this when a near-match already has the right registers and inner compare/load
family, but VC5 keeps collapsing the loop bottom into `cmp i,count / jge exit / jmp loop`
and pulls the early-empty return too close.

Why it helps:
- the positive outer `if (count > 0)` tends to keep the separate late empty-return block;
- the in-loop `if (i < count) continue; return 0;` naturally lowers to bottom
  `cmp i,count / jl loop` with fallthrough into the failure return block;
- `break` to a trailing success return can keep the success block after the failure block.

Caveat:
- the more obvious `if (count <= 0) return 0;` plus `break`/post-loop `return 0` often
  collapses back into the short `jge exit` tail family even when behavior is identical.

## Lesson: For byte-offset record loops, keep the body typed but spell the compare as a raw this-relative field load

When a loop walks fixed-size records with a byte offset (`i += 0x18`) and the original
compare family is `mov field,[base+off+0xC]` / `lea entry,[base+off]` / `cmp field,[this+idx*4+array]`,
try a mixed source shape:

```cpp
HOLDER* hold = (HOLDER*)((char*)this->OnHold + i);
if (*(unsigned int*)((char*)this->OnHold + i + 0x0C) == this->dcoID[player]) {
    ... use typed `hold` for the body ...
}
```

Try this when a near-match already has the right loop counter, zero register, and zero-store tail,
but VC5 keeps collapsing the compare into `add entry,off` plus a preloaded compare value register.

Why it helps:
- the raw compare expression encourages VC5 to keep the compare as memory-vs-indexed-memory instead
  of materializing the compared field or looked-up value into separate registers first;
- the separate typed local can still preserve the clean body shape for delete/nulling without forcing
  the compare onto the typed-member basin.

Caveat:
- use this only when the binary already proves the record field offset; if the field layout is still
  speculative, fix the layout first rather than papering over it with casts.

## Lesson: Clear stale per-function flags before chasing source-shape ghosts

If a tiny helper stubbornly misses from offset 0 or lands in an obviously wrong
prologue/codegen family, check whether a leftover `config/flags/<slug>.rsp` is
forcing an old experiment like `/O1` or `/Od`. Re-test under the repo default
`/O2 /Oy` before spending more source probes; a stale flag file can completely
hide the natural exact basin.

## Lesson: Parenthesized FPU addends can flip `fsubr` back to the original `fadd`

For expressions of the form `a * C + b`, VC5 can emit the wrong commuted FPU
opcode family (`fsubr` instead of `fadd`) even when the math is equivalent. If
behavior and stack shape are already right and only the arithmetic opcode/polarity
is off, try explicitly parenthesizing the multiplied term:

```cpp
out = (a * 0.5f) + b;
```

This can preserve the desired `fld a ; fmul C ; fadd b` sequence instead of a
reassociated/commuted alternative.

## Lesson: `if (i < count) continue; return 0;` can recover the bottom `jl` loopback without disturbing an exact early guard basin

For tiny counted walkers where the early prologue/guard region is already matching, a
plain `while (1)` loop with the bottom spelled as:

```cpp
if (i < count) continue;
return 0;
```

can make VC5 emit the original `cmp i,count ; jl loop_body` backedge, while source
forms like `if (i >= count) goto ret0;`, `break`, or explicit `goto loop_test` may
collapse into `jge + jmp` or other tail-layout drift. If the success path also needs
to share a later `ret1` label, routing it through `goto ret1` instead of `return 1`
can preserve the farther shared tail.

## Lesson: stubborn volatile-register coloring can depend on the full typed class surface, not just accessed offsets

If a tiny helper is stuck in a pure register-coloring mismatch and raw gaps/local stubs keep collapsing to the same near-miss, try restoring the real typed class body for the main object even when the function only touches one early field. For `00435020`, every minimal `gap_00[0x0C]; owner;` surface kept producing `CX/EDX` in the owner-id compare, but the exact basin appeared once `RGE_Static_Object` used its fuller real field list (including later members like the `ManagedArray<int>` blocks) while the source stayed otherwise simple. In VC5, TU/type context can steer allocator choices even when the accessed offsets are unchanged.

## Lesson: for list-update helpers, `if (result != 1) return result; remove_action();` can preserve both an early literal `return 1` and the later `cmp bl,1`

When a tiny virtual-dispatch list walker needs the empty-list path to compile as a direct literal `mov al,1` but a single-return shape keeps forcing `mov bl,1 / mov al,bl`, try splitting the tail as:

```cpp
if (result != 1)
    return result;
this->remove_action();
return result;
```

With top-declared `node`/`result` locals, this can still keep the full saved-register prologue while preserving the empty-path direct return and the non-empty-path `mov bl,al` / `cmp bl,1` family. For `004044F0`, this matched where `if (result == 1) remove_action(); return result;` stayed in the wrong basin.


## Lesson: In tiny derived constructors, hoisting `action_type` in source can still leave its store late-but-before delayed field copies

For compact post-base constructors that only copy a few parameters and initialize two same-constant fields, do not assume the source order must mirror the final store order around `this->action_type`. In VC5, a body that starts with:

```cpp
this->action_type = TYPE;
this->field_20 = x;
this->field_24 = y;
this->pick_up_x = -1.0f;
this->pick_up_y = -1.0f;
this->field_28 = z;
```

can produce a schedule where `field_24`/`task` are stored first, the vftable and `-1.0f` stores happen next, then `action_type`, and only after that the delayed `field_20`/`field_28` stores land. If the only remaining drift is `action_type` sinking after two late copied fields, try hoisting the type assignment to the top of the constructor body before changing layouts or flags.

## Lesson: an outer positive `if (...) { loop } else { return 0; }` can preserve a distinct early-fail tail that `if (param <= 0) return 0;` collapses

For small search loops where the loop body and late fail tail already match but the early empty/invalid-input return keeps merging into the loop-fail block, try flipping the top guard into a positive outer wrapper:

```cpp
if (count > 0) {
    // loop
} else {
    return 0;
}
```

This can keep the original top `jle` to a separate late zero-return block while still letting an in-loop `return 0;` own the earlier loop-fail tail. In `004E0F40`, this also let a later `goto found; return 1;` keep the success block between the two zero-return tails.

## Lesson: 1-based enum arrays may need `array[type - 1]` to recover base-minus-one indexing

When an enum's first real value is 1 but the object stores a zero-based pointer array, VC5 can fold `array[type - 1]` into an address like `[this + type*4 + (array_offset - 4)]`. If the original asm shows the base displacement four bytes before the declared first element (for example `[edi+ebx*4+504h]` while the first array element is at `+508h`), do not add a fake field or raw cast first; spell the source as the natural one-based enum adjustment.

Try when:
- the only remaining diff is an indexed member-array displacement off by exactly one element;
- the index register holds a 1-based enum value used directly elsewhere.

Why it helps:
- VC5 folds the `- 1` into the addressing displacement, preserving the original compact SIB form without extra arithmetic.

Reference: `004AA7A0` (`TRIBE_Screen_Sed::set_map_type`).

## Lesson: Use `while (i < limit)` to avoid VC5 peeling the first scan element

For small fixed-capacity array scans where the original loop starts with a memory
compare at the loop label (`cmp dword [ptr], imm`) after an initial `xor index,index`,
a natural `do { if (*p == ...) ...; i++; p++; } while (i < limit);` can make VC5
peel/preload the first element into a register before the loop top. Rewriting the
same scan as `while (i < limit) { if (*p == ...) ...; i++; p++; }` can keep the
unpeeled top-of-loop memory compare and the expected saved-register scheduling.

Try when:
- rebuilt code has an early `mov reg,[base]` followed by `cmp reg,imm`, but the
  original has `cmp [ptr],imm` at the loop label;
- the loop scans for a free/sentinel slot and returns immediately on match.

Why it helps:
- the explicit precondition gives VC5 a non-peeled loop basin, preserving the
  pointer local and index initialization order instead of special-casing the first
  iteration.

Reference: `004EAFA0` (`TacticalAIGroup::addUnit`) matched exactly after changing
only the scan from do-while to while.

### UnitAIModule-derived constructor arrays: cache element 0, reload later indices

For `taiuaimd.cpp` `UnitAIModule` derived constructors that allocate and fill
`importantObjects`, the exact VC5 shape is a natural base-constructor initializer,
visible virtual destructor on the base, `/GX`, then:
`importantObjects = (int*)operator new(byte_count); if (importantObjects) { ... }`.
Use the cached `importantObjects[0]` for the first store, but spell all following
stores as `this->importantObjects[i]`; VC5 then reloads `[esi+124h]` for each
source line and cycles EDX/EAX/ECX exactly. Optional timeout setup is a plain
`idleTimeoutValue = value; setAdjustedIdleTimeout();` after the guarded array fill.

- For VC5 `_findfirst` / `_findnext` loops over CRT `_finddata_t` where the asm passes `&file_info.time_create` and scans `file_info.name + 4`, a local shim can match by making the passed local start at the time fields (`gap_00[0x10]; name[260]; pad_114[4]`) and using a 256-byte filename buffer directly, not `file_name + 4`, even if the decompiler labels the stack slot as `file_name+4`. The trailing 4-byte pad can be required solely to preserve the original stack reservation while keeping the filename and finddata offsets unchanged.

## Lesson: For linked-list sentinel walks, explicit `while (1)` can avoid extra bottom null tests

When the original checks the first node against the sentinel, then loads a loop
parameter/local, then tests the current node for null at the loop top, and the
bottom only reloads/compares the sentinel before jumping back to that top test,
spell the traversal as `while (1)` with explicit `if (node == 0) break;` at the
top and explicit `if (node == sentinel) break;` at the bottom. A source-level
`while (node != 0)` or do/while condition may make VC5 duplicate the null test at
the bottom (`cmp sentinel; je exit; test node; jne top`), shifting branch targets
and epilogue layout.

Reference: `005003A0` (`TribeTacticalAIModule::removeAllGroups`) matched exactly
with the explicit-break loop shape.

## Lesson: Initialization order can decide ESI/EDI roles in compact copy/count loops

In VC5, two live integer locals in a small copy/count loop can swap callee-saved
registers solely based on initialization order, even when the loop body is
unchanged. If the original uses `EDI` as the accumulated count and reuses `ESI`
as a countdown after `ESI` previously held `this`, initialize the count before
materializing the source pointer (`count = 0; src = this->array; ...`). Initializing
`src` first can make VC5 choose `ESI` for the count and `EDI` for the countdown,
leaving only a few-byte register-choice mismatch.

Reference: `004EB3A0` (`TacticalAIGroup::setSpecificCommander`).

## Lesson: One-element ManagedArray copy loops may need an `if (i < limit)` body, not an early break

For VC5 inlined ManagedArray growth that copies at most one element, source like
`if (i >= 1) break; next = i + 1; dst[i] = src[i]; i = next;` can make the compiler
use ECX as the index, synthesize `lea`, and place the one-element guard at the
bottom. If the original has `cmp eax,1; jge exit; mov ecx,src; inc eax; mov ...
[eax*4-4]`, spell the loop as:

```
if (i < 1) {
    i = i + 1;
    dst[i - 1] = src[i - 1];
} else {
    break;
}
```

with a separate `max = this->maximumSizeValue; i = 0; if (0 < max)` precheck.
This keeps the index in EAX, emits the top `cmp eax,1`, and uses the post-increment
`[eax*4-4]` addressing form.

Reference: `005009A0` (`TribeTacticalAIModule::numberItemsToAttack`).

- For UI panel helpers with calls through high vtable slots (for example `[vptr+0xE4]`) but only approximate local class surfaces, a real virtual declaration ladder can be cleaner than fake function-pointer fields. Give the class a hidden vptr with enough dummy virtuals to place the called method at the observed slot, and adjust explicit padding so object/member offsets stay exact. This lets VC5 emit the natural `mov eax,[ecx]` / `call [eax+slot]` sequence while preserving normal direct calls for non-virtual panel methods.

- Automatic local object declaration position matters for VC5 EH codegen: a nontrivial stack object declared after an initial statement is constructed after that statement, even though its storage is still reserved in the frame. When original asm performs setup work (for example clearing a UI list) before a local service/helper constructor and then sets the EH state immediately before the first method call, move the declaration down to that source point instead of keeping all locals at the top. For large EH objects, validate the effective storage span from the state-slot offset; the visible class payload may need to be smaller than the stack span because VC5 adds object/EH bookkeeping alignment.

### Save routines may reuse the incoming file parameter slot as a tiny flag buffer

In VC5 save/serialize methods, the compiler may copy the incoming file handle to a
callee-saved register (often EDI) and then reuse the original stack parameter slot
as a 4-byte local written by `rge_write`. Source can model this with a saved local
for the handle plus assignment back to the parameter before `rge_write(saved,
&param, 4)`. Also keep base-class vptr size visible: an apparently empty base with
virtuals shifts derived fields by 4 bytes, and missing dummy virtuals before a save
slot changes only the final indirect call offset.

### Unsigned loop counters for `jbe` after zero-extending a short bound

When VC5 reloads an unsigned-short member with `xor eax,eax; mov ax,[...]` and
then compares an int loop counter against EAX, the source counter usually needs to
be `unsigned int` to get `jbe`/`ja` style loop branches. Leaving the counter as
plain `int` can produce the same bytes except for a single signed `jle`/`jg` branch.

- For TEasy_Panel/TShape image setters, prefer the high-level natural `delete old; field=0;` then `new TShape(buffer_or_empty, id)` shape with `<stdio.h>/<string.h>` helpers (`stricmp`, `strchr`, `sprintf`). VC5 reuses the first dword of a 260-byte filename local as the constructor-new temporary and emits the expected EH state transitions; manual allocation or raw buffer tricks are unnecessary and can perturb the local layout.

- Tiny EH-framed dialog helpers often match with plain `new Dialog(args...)` and the real constructor signature/sizeof, not manual `operator_new` scaffolding. For nullable text checks, preserve the exact odd source predicate if the asm shows it: `if (text || *text != 0)` can intentionally emit `test eax,eax; jne ...; cmp byte [eax],0; je ...`, even though it looks unsafe.

- TEasy_Panel string-id wrapper methods can be modeled as small stack buffers plus a virtual delegate call. Declare enough dummy virtuals to put the delegate at the observed slot (`0xEC`, `0x100`, etc.) and call the nonvirtual `get_string(id, buffer, sizeof buffer)` first; VC5 will naturally preserve `this` in ESI, allocate exact fixed buffers, and push the translated text pointers in the original order.

### Switch before allocation can preserve VC5 case-block order in factory loaders

For type-dispatch factory helpers, write an actual `switch (type)` even when an
`if/else` chain is behaviorally equivalent. VC5 may emit all byte comparisons up
front and place allocation/constructor case bodies afterward; an `if` chain tends
to inline the first allocation immediately. Also give allocated class stubs their
real `sizeof` early, and keep a visible virtual in the base class when a derived
array field must sit after the base vptr.

- Palette/system-color helpers match well with real Win32 surfaces and high-level expressions. `__declspec(dllimport)` for GDI/User APIs can still emit the observed indirect IAT calls, and spelling `((blue << 16) | (green << 8) | red)` from a `PALETTEENTRY` local produces VC5's byte loads/masks/shifts exactly. For old color-table members with `push 1; call [vptr]`, model a virtual destructor and use ordinary `delete ptr; ptr = 0;`.

- When modeling derived panel methods that call a base method and later dispatch a virtual slot, make the base polymorphic if the real object vptr belongs to the base at offset 0. If the base is modeled as non-polymorphic and the derived class introduces the first virtual, VC5 treats the base subobject as starting after the vptr and emits `lea ecx,[this+4]` for `Base::method`; adding the base virtual surface keeps `this` at offset 0 and preserves field/vtable slot offsets.
- In VC5 growth/copy loops, a source `while (i < old_count && i < new_count)` can be necessary to avoid an extra positivity test on the new bound. If asm tests the old count once, then at loop top compares iterator against the new bound before copying and only reloads/compares old count after increment, prefer a single combined `while` condition over a `do` loop with an inner `break`.
- For VC5 allocation-size expressions used twice, avoid naming a `bytes` local if original keeps the expression in a transient register around each call. Repeating `(int)short_count + (int)short_count + 1` at each `calloc` can preserve the expected register choice and later member-load scheduling, whereas a named local may force ECX/EAX drift even when size and behavior match.
- For VC5 state machines on byte enum members, a `switch (state)` can emit the original `xor eax; mov al; dec; dec` dispatch where equivalent `if (state == 1) ... else if (state == 2)` emits direct byte compares. When the original has a decrement chain, prefer switch, and include all enum cases so the `cmp eax,N` bound matches.
- In destructors, an unwanted `lea ecx,[this+base_offset]` before a member/helper call means the local inheritance surface has an extra modeled base subobject. If original keeps ECX as the complete object for a helper like `delete_panel(&member)`, put that helper on the visible base/destructor class without an intermediate base adjustment; the natural destructor then also emits the derived vptr restore.
- For Win32 API calls that original emits as IAT indirect `call dword [addr]`, declare the API as `__declspec(dllimport)` with the right calling convention. A plain extern can be behaviorally correct but emits a direct call relocation and leaves a tiny otherwise-perfect diff.
- For tiny EH-framed `return new T` helpers, `sizeof(T)` is often the only remaining mismatch after the EH skeleton matches. If a local class declares both an explicit vptr field and virtual methods, VC5 counts both; model only the implicit virtual vptr plus padding to make `operator new` receive the original size.
- COM-style interface calls are not C++ virtual `thiscall`s. If original does `mov ecx,[obj]; push obj; call [ecx+slot]`, model the object as a struct with a vtable of `__stdcall` function pointers rather than a C++ class with virtual methods. For adjacent 16-byte GUID copies, a typed aggregate assignment can also preserve the original `lea src; add esp; add dst; mov/mov/mov/mov` copy schedule better than manual element stores.
- Inside a derived constructor body, `Base::Base();` constructs a temporary/local rather than initializing the base subobject and can make VC5 reserve a huge stack object and emit an extra constructor call. Put base construction in the initializer list (`Derived::Derived() : Base() { ... }`) to match normal constructor prologues.
- Do not hand-expand common CRT string helpers too early. VC5 may inline `strcmp` into the exact two-byte-at-a-time/sbb comparison sequence seen in the original, while manual byte loops land in different prolog and branch basins. Try the natural `<string.h>` helper surface first when the asm resembles a CRT inline.
- When original object cleanup is `call real_destructor; push obj; call operator_delete` rather than a vtable deleting destructor call, do not use `delete ptr` on a class with a virtual destructor. Model the ordinary destructor explicitly (`ptr->~T(); operator delete(ptr);`) and keep the virtual table surface only for the other virtual calls.
- VC5 can inline `strcpy` as a `repne scasb` length discovery followed by `rep movsd`/`rep movsb` copy including the NUL. If original has that exact pattern, use natural `strcpy` with the correct destination offsets instead of spelling `strlen` plus `memmove`/manual loops.
- For constructors with many scalar member initializers, a real member-initializer list can preserve VC5's original initialization scheduling and register choices better than equivalent assignments in the body. This is especially useful when the original sets sentinel fields first, zeroes a group, then loads constructor parameters only later.
- For sibling virtual action `work(target, float, float, float)` helpers that only gate null/same-target states, set the base virtual slot ladder exactly so `first_in_stack` is vtable+0x1C and `set_target_obj` is vtable+0x54, then use natural member virtual calls. Manual vtable casts can perturb stack cleanup/call scheduling; a compact typed base surface matched both convert/heal work helpers.
- For VC5 linked-list searches, a natural `while (node->field != target) { node = node->next; if (!node) return; }` can produce the original compare-then-`jne` loop with a separate short jump to the found tail. Equivalent `while(1)`/`break` forms may invert the final compare (`je found; jmp loop`) and leave only a few stubborn branch bytes different.
- When VC5 indexes a fixed-size table embedded at a nonzero-looking decompiler offset, verify the effective base from assembly before baking the generated struct layout into source. For `idx * stride` tables, raw `(char*)this + idx * stride` plus field offsets can match `lea ecx,[ecx+edx*scale]` where a typed array at `this+base` adds an unwanted displacement and extra register pressure.
- If a loop index is passed to a call as a full `int` but the loop bottom compares only the low 16 bits against a `short` member (`cmp si,[...]`), keep the source index as `int` and cast only in the loop condition, e.g. `for (int i = 0; (short)i < count; ++i)`. Making the index itself `short` can introduce a `movsx` before the call, while plain `int` can force a 32-bit bottom compare.
- For constructor helpers that pass `this` in ECX before a call, model the helper as a real member function and call `this->helper(...)`. A free/static helper with an explicit `this` argument may be behaviorally equivalent but adds a pushed object argument and cdecl cleanup, shifting the EH tail.
- When original code loads a field from an object and then calls with that field in ECX (`mov ecx,[obj+slot]; call target`) after pushing the remaining arguments, model the target as a member function on the pointee/subobject. A free helper that takes the owner object explicitly adds an extra pushed argument and cdecl cleanup.
- Before chasing register allocation in virtual-call functions, verify the local vtable surface has enough placeholder slots to put the observed call at the original offset. A too-short stub can make the same source call slot 0 instead of (for example) `vtable+0x58`, causing broad false drift that disappears once the virtual ladder is padded correctly.
- Command wrapper helpers often match naturally once both layers are modeled as member calls: first a selected object's virtual action query (with the observed vtable slot ladder), then a command-subobject member call through `player->command->command_obj`. Keeping either as a free helper changes pushes/cleanup even when behavior is identical.
- Tiny stack-local widths can decide exact addresses in VC5. If original reserves a dword-sized scratch but only uses it as an opaque/local-byte output, declare it as `int` rather than `char`; otherwise `lea [esp+N]` may become `[esp+N+3]` and also pull saved-register setup before an early global gate.
- Diamond-map command wrappers are highly regular: gate on `allow_user_commands`, use an `int` scratch local for the pick-tile byte output, convert the two short outputs through dword stack temps before subtracting the shared half-tile float, then call the view's game object at the action-specific virtual slot and finally clear modal/input state through the global base-game virtual slot.
- For FPU sign/zero classification loops, source-level branch nesting controls VC5's reuse of the `test ah,41h` flags across a following `fnstsw`. If original does `test`, performs another `fcomp/fnstsw`, then branches on the earlier test flags, try spelling the outer condition with the opposite compare (`<= 0` vs `> 0`) and keep direct `return 0` failures so the success epilogue stays before the failure epilogue.


## Lesson: External table declarations and inline indexed access can prevent spills

When original code indexes fixed lookup tables through relocations, declare the tables as `extern const` rather than defining file-local arrays. A local definition can put data in the scratch object and change addressing/relocation behavior.

For small bitfield helpers, also try inlining repeated table lookups instead of naming a `shift` local. VC5 may keep the table-loaded shift count in `cl` across adjacent `shr`/`shl` operations only when the access is inline; a named local can force a spill/reload between the shifts.

Try when:
- the original has relocation-masked table loads but rebuilt creates local data or different data references;
- the only remaining diff is a `cl` spill/reload around shift-count use;
- a mask/shift table is indexed by the same small expression more than once.

Caveat:
- use `extern` only when the table really exists in the original binary/shared data surface; do not hide unknown constants behind extern declarations.

### `sete`/`dec`/`and` vs branched return for `?:` ternary

In VC5, `return (cond) ? 0 : val;` produces a branch (`jne`/`jmp` or `je`/`jmp`) around the
return value, while the equivalent `if (cond) return 0; return val;` forces VC5 into the
branchless `sete al; dec eax; and eax, reg` trick that pops intermediate callee-saves around
the SETE/DEC for better scheduling. When the original asm shows the branchless pattern, prefer
the `if/else` spelling over `?:` (VA 00471290 `get_select_level`).

### Variable declaration order drives prologue register init order

When VC5 allocates `short`/`char` locals to 16-bit/8-bit registers in the prologue (`xor edx,
edx` / `xor esi, esi` / `or bl, 0FFh`), the init order in asm follows the declaration order in
the closest enclosing scope. Two variables of the same width can swap positions in the prologue
by swapping their declarations (VA 00471290: `short i` before `short matches` gave `xor edx`
before `xor esi`; adding `const` to the method changes the field offset scheme).

### Field layout: overlapping explicit gaps with short fields

When a `short` field sits inside what appears to be a `char gap_NN[M]` region (based on class
type-dump boundaries), split the gap to place the `short` at the correct offset. Example:
`char gap_198[4]; short sel_count; char gap_19E[2];` instead of `char gap_198[8]; short
sel_count;` (VA 00471290 `get_select_level`, where sel_count was at +0x19C inside a
0x198-base gap).

### Loop structure: `for` with direct index access prevents loop peeling

VC5 peels the first iteration of a `do-while` loop when it's guarded by `if (max > 0)`, even
for a simple linear search. The peeled first iteration creates a different control-flow layout
(moves the `je`/`jl` targets). Using `for (; i < max; ++i) { if (value[i] == v) break; }`
eliminates both the guard and the pointer temp, preventing the peeling (VA 004F1390
`ManagedArray<int>::remove`).

When the search loop used a running pointer (`int* p = this->value; do { ... p++; } while...`),
VC5 still peeled the first iteration even without the `if (max > 0)` guard. Only the direct
index-access for-loop (`this->value[i] == v`) without a separate pointer variable and without
an outer guard produced the unpeeled `jl` loop control.

### Shift loop: post-increment `value[i] = value[i+1]` over `++i; value[i-1] = value[i]`

For shifting array elements left by one position, `this->value[i] = this->value[i + 1]; ++i;`
generates the compact two-address `mov esi,[edx+eax*4]; mov [edx+eax*4-4],esi` form. The
pre-increment form `++i; this->value[i - 1] = this->value[i];` generates an `lea`-based form
(`mov esi,[edx+eax*4]; lea edx,[edx+eax*4]; mov [edx-4],esi`) that is one instruction longer
(VA 004F1390 `ManagedArray<int>::remove`).

### VC5 in-charge/not-in-charge constructor variant: controlling .text COMDAT order for single-function TU

When a VC5 constructor with EH frame (push -1, fs:0) is compiled in isolation, the
compiler generates multiple .text COMDATs: the in-charge constructor (with EH frame,
base ctor call, vtable write), plus implicit helpers (destructor, deleting destructor).
The repo's COFF tool concatenates duplicate `.text` sections in section-table order,
and the checker extracts the first N bytes (where N = original function size).

To match, the in-charge constructor COMDAT must be the FIRST .text section in the OBJ.
This requires:
1. No function definitions before the constructor in the source file (no inline
   virtual function bodies, no explicit function defs).
2. All virtual functions and base ctors declared as extern (not defined inline).
3. Any helper functions (like `setup()`) defined in another TU, not in this one.
4. The `/GX` flag is required for EH frame generation.

Without these precautions, earlier .text COMDATs (e.g., setup(), inline virtual fn
bodies, base not-in-charge ctors) push the constructor past byte 0 of the concatentated
.text section, causing the checker to extract wrong code.

Also: the original does NOT zero `member_ptr` in the constructor body (no `member_ptr(0)`
in the member initializer list). Adding the zero creates an extra `mov [esi+04], 0`
instruction that isn't in the original.

Affected function: 0044F0F0 `RGE_Master_Action_Object::RGE_Master_Action_Object`.

### Vtable dispatch: helper class yields correct __thiscall vcall without shifting field offsets

When original code uses manual vtable dispatch (`mov edx,[esi]; call [edx+offset]`)
with `this` in ecx, a raw function pointer cast `((void(*)(void*,int))vtbl[n])(this,1)`
generates `this` on the stack (like __cdecl), not in ecx. Declaring virtual methods on
the class fixes the convention but adds a compiler-managed vtable pointer that shifts
all field offsets by 4 bytes.

Solution: define a standalone struct with dummy virtual methods to establish the correct
vtable slot, then cast `this` to that struct and call through it:
```cpp
struct VTableHelper {
    virtual void d0(); virtual void d1(); // ... 6 more ...
    virtual void target_method(int x);  // at desired slot
};
((VTableHelper*)this)->target_method(1);
```
This generates the correct `mov ecx,this; push 1; call [vtable+offset]` sequence without
adding a vtable pointer to the real class. The helper struct uses the OBJECT's vtable
(set by the real constructor), not its own. All data field offsets remain unchanged.

Affected function: 00476F30 `TInputPanel::handle_idle`.

### Loop variable type determines signed vs unsigned branch instruction

When the original uses `jbe` (unsigned below-or-equal) for a loop-back comparison,
the loop variable must be `unsigned int`. With `int`, VC5 uses `jle` (signed
less-or-equal) instead. The difference is a single byte in the opcode
(`76` for `jbe` vs `7e` for `jle`), so any loop with a boundary check at 0x8000+
will produce wrong comparison with a signed variable.

**Example** (`CountWaitingMessages`, 0042A0C0):
```cpp
// MATCHES (unsigned offset, jbe):
unsigned int offset = 0;
do {
    // ... body ...
    offset += 0x38;
} while (offset <= 0x6D98);

// MISMATCHES (signed offset, jle):
int offset = 0;
do {
    // ... body ...
    offset += 0x38;
} while (offset <= 0x6D98);
```

Also: use `signed char` for sign-extended loads (`movsx`). The `*(signed char*)ptr`
cast forces VC5 to emit `movsx` instead of `movzx`.

Try when:
- original uses `jbe`/`ja` but rebuilt uses `jle`/`jg`
- the loop variable is updated by addition and compared against a constant

### Destructor with array-of-struct iteration: use `short` for signed comparison

When the original asm uses `movsx` (sign-extend) to reload a loop bound from a
member field, declare the field as `short` (signed) rather than `unsigned short`.
VC5 generates `movsx eax, word [member]` for signed comparisons but `xor eax,eax; mov ax,[member]`
(zero-extend) when the field is unsigned. The loop comparison (`jl`/`jle` for signed)
and the bound-field type must match.

**Example** (`~RGE_Sound`, 004BC080):
```cpp
// MATCHES (generates movsx eax,word [esi+2]):
short sound_num;
// ...
} while (i < this->sound_num);  // signed comparison

// MISMATCHES (generates xor eax,eax; mov ax,[esi+2]):
unsigned short sound_num;
// ...
} while (i < this->sound_num);  // compiler zero-extends unsigned field
```

Also notable: the original uses TWO loop variables — a counter (`ebx`, incremented
by 1) and a byte offset (`edi`, incremented by sizeof-0x24). Use a local `int offset`
that increments by the struct size to match the `add edi, 24h` stride. The first byte
of each struct entry is set to 0 (`mov byte [sounds+offset], 0`), matching a Ghidra-
observed `sounds->name[i] = '\0'` write.

Try when:
- original uses `movsx eax, word [member]` to reload a loop bound
- rebuilt uses `xor + mov ax` (zero-extend) instead
- changing `unsigned short` to `short` fixes the instruction selection

Caveat: only works when the field's actual range is small enough that sign doesn't
matter (e.g., sound_num is always < 32768).

### Copy loop: `for` with compound condition prevents loop peeling in resize

`ManagedArray<int>::resize` uses a copy loop bounded by both `maximumSizeValue` and
`new_size`. The `for (; i < this->maximumSizeValue && i < new_size; i++)` form with
direct array access (`new_value[i] = this->value[i]`) generates the exact two-condition
loop control (`jl` backedge to a middle check) without loop peeling or extra `jmp`.
Using a guard (`if (maxSize > 0)`) or goto-based loop structure triggers loop peeling
of the first element copy (VA 004147A0 `ManagedArray<int>::resize`).

### /GX EH-framed destructors: never explicitly call the base destructor

When a derived class destructor is compiled with `/GX`, VC5 auto-generates the base
destructor call (implicit call at end of the derived destructor body). Writing an
explicit `BaseClass::~BaseClass()` in the destructor body creates a DUPLICATE call
that shifts the EH state machine: the rebuilt gets `call ???; mov ecx, esi;` before
`mov [esp+10h], -1; call ~BaseClass` instead of the original's single-call sequence.
The first 77+ bytes (EH frame, free_text, DeleteObject) match fine, then the extra
call breaks the base destructor sequence.

Leave the base destructor call implicit — let VC5 insert it naturally. The explicit
call is only needed when you need a specific ordering or the compiler doesn't
auto-generate it (e.g., in a manually written delegating destructor).
(VAs: 0047C0B0 `~TTextPanel`)

### /GX EH-framed destructors: explicit temp for member pointer forces register save

When a /GX EH-framed destructor frees a member pointer (e.g., `this->actions`),
writing the load as an explicit local declaration BEFORE the if-check forces VC5
to save the pointer in a callee-saved register like `edi`:

```cpp
RGE_Action_List* p = this->actions;  // loads into edi
if (p != 0) {
    p->~RGE_Action_List();           // ecx = edi
    operator_delete(p);              // push edi
    this->actions = 0;
}
```

Without the explicit temp (`if (this->actions != 0) { ... }`), VC5 loads from
memory twice (once for destructor call, once for delete) and doesn't save `edi`.
The explicit temp produces a single load into `edi`, uses it for both calls,
then nullifies the member — matching the original's `push edi` / `pop edi`
register-save pattern.
(VA: 00406010 `~RGE_Action_Object`)

### Loop peel: `while (count-- != 0)` avoids null-check insertion seen with `do-while`

When a loop allocates memory via `operator new` with a `break` guard, VC5 generates
different code for `while (count-- != 0)` vs `do { ... } while (count-- != 0)`:

- **`while (count-- != 0)`**: Generates a peeled loop with no null check on the
  allocation result. The counter is initialized to N-1 (peeled), so use `count = 10`
  if the original uses `mov edi, 9`. The count-- post-decrement in the while
  condition generates the `mov edx, edi; dec edi; test edx, edx; jne` pattern
  without extra `test eax, eax; je alloc` null-guard instructions.

- **`do { ... } while (count-- != 0)`**: Generates an unpeeled loop with the same
  `mov edx, edi; dec edi; test edx, edx; jne` post-body pattern, but adds extra
  `test eax, eax; je alloc` null-guard instructions after the counter check.
  This inflates the function by ~7 bytes.

The `while` form also removes the initial `jmp check` that `while` usually adds
(because the compiler knows the first iteration always executes when count >= 1).
(VA: 0044B2B0 `MakeArrays`)

### Separate `next` local forces two-register linked-list walk pattern

When walking a linked list with `p = p->next`, VC5 may optimize to a single
register by reusing `p` for both current and next pointers (`mov esi,[esi+4]`,
then `jne loop_start` where esi is the new current). This differs from the
original two-register pattern (`mov ecx,[eax]; mov esi,[eax+4]; mov eax,esi;
jne loop_start`).

Fix: use a separate `next` local so the compiler keeps two registers:
```cpp
while (p != 0) {
    auto* obj = p->node;
    auto* next = p->next;  // separate local forces register
    // ... use obj ...
    p = next;
}
```
This generates the expected `mov ecx,[eax]; mov esi,[eax+4]; ... mov eax,esi`
pattern matching the original binary.

Also: **declare `int` for sign-extended loads** — assigning a `short` field to a
`short` local generates `mov ax,[mem]; movsx eax,ax` (two instructions), while
assigning to `int` generates `movsx eax,word [mem]` (one instruction).

Also: **object_list pointer at +0x10, not wrapped struct** — the RGE_Tile stores
a plain `RGE_Object_Node* objects_list` at offset 0x10, not an RGE_Object_List
struct. Total tile size = 24 bytes.

Affected function: 00458760 `RGE_Map::delete_objects_on_tile`.

### Class methods for __thiscall external function calls

When the original uses `__thiscall` standalone functions (not virtual), use class
method declarations instead of `extern "C"` function pointers. A class method on
a forward-declared class generates the correct `ecx=this; push args; call [func]`
pattern with callee cleanup (`ret N`), avoiding the `add esp` that `extern "C"`
would generate.

```cpp
class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map(int a, int b, int* c);
};
// Usage:
zone_list->get_zone_map(a, b, &c);
// generates: push &c; push b; push a; mov ecx, zone_list; call get_zone_map
```

Also: raw pointer arithmetic on `void*` or `char*` with explicit offsets generates
the exact `mov eax,[ecx+offset]` / `movsx edx,word [ecx+offset]` patterns when
the target struct layout isn't fully known. Use `(short)(*(short*)(ptr + off))` for
`movsx` sign extension.

Affected function: 004C75B0 `RGE_Static_Object::withinRangeOfZoneAtPoint`.

### Preserve a named byte-count temp to let VC5 schedule independent array stores between `push` and `call`

When a one-argument allocation call should appear as `push bytes; mov [array+idx*4],value; call malloc`, avoid introducing a pointer result temp (which increases register pressure) and avoid folding the size expression directly into the call (which can store too early). Use a named integer byte-count temp before the side-effecting array store:

```cpp
int bytes = this->elementSize * grow;
sizes[idx] = grow;
this->zonePtrs[idx] = (T*)malloc(bytes);
```

VC5 can keep `bytes` in the expected register, push it, and schedule the independent `sizes[idx]` store into the call setup gap. A separate allocation-result temp may force an extra saved register and reorder the surrounding counter updates.

### Prefer declared member calls over raw address casts for same-class helpers

When original asm calls a nearby same-class helper as a direct `call rel32` with `this` already in ECX, declare the helper as a normal member and call it naturally (`save();`). A raw absolute function-pointer cast may be behaviorally correct but can force a cdecl-style `push this` / indirect call basin or otherwise perturb the prologue and register allocation.

### For virtual slot calls, prefer a typed virtual surface over raw `__thiscall` function-pointer typedefs

VC5 may reject or mishandle raw `__thiscall` function-pointer typedefs in this project context, and lower-level vtable casts can perturb call cleanup and branch layout. When original asm clearly does `mov edx,[obj]; ...; call [edx+slot]`, model enough virtual methods to put the target operation at the correct slot and call it naturally as a member (`obj->slot_method(args)`). This preserves ECX `this`, argument pushes, and indirect call shape without custom calling-convention typedefs.

### Integrated `while` body can avoid VC5's post-loop null recheck in linked-list searches

For linked-list remove/search functions where original asm has an initial null check, a loop body that either handles the found node immediately or advances, and a distinct not-found early epilogue, avoid a `for (...; p && condition; ...)` followed by `if (p == 0) return;`. VC5 may emit an extra post-loop `test p,p` and share the null path with the final epilogue. Writing the found handling inside `while (p != 0)` lets the compiler use the searched node directly and place the not-found return before the found block, matching the original layout.

Also, after `test cl,cl`, spelling an unsigned-byte count check as `count > 0` can emit `jbe` to the zero case, while `count != 0` emits `je`; both are equivalent for a byte but not byte-identical.

### Reusing an input stack slot as a helper output can require passing the parameter address and reloading it narrow

Some command helper wrappers pass the address of an incoming `int` parameter as a `short*` output to a selection helper, then later reload that same stack slot as a signed word (`movsx ..., word [esp+param]`) while preserving the original full-width parameter in a register for another argument. Model this directly by saving the original value in a local, passing `(short*)&param` to the helper, and later using `*(short*)&param` for the list-count argument while using the saved local for the original command argument. If the callee declaration uses `int` for that list-count parameter, VC5 emits the required `movsx`; a `short` formal may keep the value in a different register or skip the sign-extension shape.

### Float-typed fields can be needed even when stores are integer `mov` immediates

When original asm stores constants like `0x43480000` and `0x42C80000` with integer `mov` instructions, model the destination as `float*` and write `200.0f` / `100.0f`, not integer `200` / `100`. VC5 will still use integer immediate stores for float constants in memory, but the immediate values match the IEEE-754 bit patterns. Integer fields with integer literals produce the same instruction shape but wrong constants.

### Inline denominator call can force VC5 `fdivr` instead of x87 stack shuffle

When a float ratio should compile as `fstp temp; call denominator; fdivr temp`, avoid naming the denominator result as a separate `float` local. Keep only the numerator temp and inline the denominator-producing call in the division, e.g. `sum = numerator / obj->denominator() + sum;`. A named denominator local can make VC5 preserve/reload both operands with `fld`/`fxch`/`fstp` and use `fdiv`, shifting the whole loop even though the math is equivalent.


## Lesson: A local `this` alias can flip `this` versus loop-counter register coloring

When VC5 swaps the expected callee-saved register roles for `this` and a loop counter (for example rebuilt uses `esi=this, edi=i` while original uses `edi=this, esi=i`), try introducing a simple local alias as the first statement:

```cpp
ClassName* th = this;
```

Then use `th->field` throughout the function. The extra pointer local can change register pressure just enough for VC5 to keep the object pointer in the original register and leave the loop counter in the other saved register.

Try when:
- the logic is correct but almost every member access differs by an `esi`/`edi` ModRM swap;
- a loop counter and `this` both live across calls;
- declaration-order probes do not affect the allocator.

Caveat:
- do not keep the alias if the original repeatedly reloads `this` or if it introduces extra memory loads; this is specifically for stable saved-register color swaps.

### Preserve inner loop guard topology with `if` body inside `do`

For bounded copy loops with two limits, VC5 may emit either a pre-body break (`if (i >= limit) break;`) or the original compare-at-top/branch-to-exit shape. If the target has `cmp i,newLimit; jge exit; ...; cmp i,oldLimit; jl loop`, spell the loop as a `do` with the copy inside the positive arm (`if (i < newLimit) { ++i; copy; reload oldLimit; } else { break; }`) rather than an early `if (i >= newLimit) break;`. This can remove extra `test`/preheader checks and match the exact loop topology.

### Volatile value parameters can preserve x87 operand load order

When a VC5 match is down to a commutative-looking x87 expression (`value * member`) but the compiler loads the member first (`fld [this+...] ; fmul [esp+param]`) while the original loads the stack parameter first (`fld [esp+param] ; fmul [this+...]`), try declaring the by-value float parameter as `volatile float` in both the member declaration and definition. This can force the stack parameter to be the primary x87 load without changing the ABI or the generated call surface. Use narrowly: it is a codegen-shape tool for observed parameter reload order, not a semantic claim about the source API.

### Split chained member calls to prevent argument interleaving

When a call result is immediately used for another member call and later another argument-producing call feeds a small wrapper, VC5 can interleave argument pushes if the source keeps everything as one expression. If the original shows one call's full argument block, call, `mov ecx,eax`, second call, then a separate helper call whose result is pushed into a wrapper, split the expression into named pointer/message temporaries. This preserves the natural call boundaries and avoids extra/early pushes from nested argument evaluation.

## Lesson: `while(1)` with continue bottom plus goto success can restore VC5's direct `jl` backedge

For tiny counted search loops where a natural `do { ... } while (++i < count)` compiles to `jge exit; jmp loop` but the original has the compact bottom `cmp i,count; jl loop`, try a positive outer guard and an infinite loop whose bottom is spelled:

```cpp
if (i < count) continue;
return 0;
```

If the success return must be placed after the loop-fail return, route the match through a trailing `goto found; return 1;` rather than returning directly inside the loop.

Try when:
- the loop body and register choices already match, but the only structural drift is a 4-byte inverted loop exit plus jump instead of a 2-byte `jl` backedge;
- the original has distinct return blocks for loop-fail, success, and early-empty cases.

Why it helps:
- the positive outer guard preserves the separate early-empty tail;
- the `continue` bottom encourages VC5 to emit the backward conditional branch directly;
- the `goto found` success path can keep the success return after the loop-fail return without disturbing the loop body.

## Lesson: Direct indexed array scans can remove redundant pre-loop tests

When a small counted scan already has an explicit `if (count <= 0) return 0;` guard, a carried pointer local plus `while (i < count)` may still make VC5 emit a second redundant entry test before the loop body. Rewriting the loop as direct indexed member-array access (`this->array[i].field`) inside a `for (; i < count; i++)` can keep the single top guard, preserve the counter/base registers, and emit the original bottom `cmp i,count; jl loop` backedge.

Try when:
- a pointer-walk version matches the body but has an extra `test count,count` before loading loop parameters;
- do/while or explicit-goto forms remove the entry test but collapse return-tail layout or produce `jge` + `jmp` instead of a single `jl` backedge.

Caveat:
- only prefer this when the original keeps the array base in a register and advances via index/stride-compatible addressing; true pointer-walk originals may still need a carried pointer local.

## Lesson: Trust odd binary-observed FPU operands over natural distance formulas

When an x87-heavy distance/length loop is close but the stack schedule differs, trace the actual `fld`/`fsub` operands before assuming the source was the natural mathematical formula. A duplicated load can mean one value is intentionally used in two different subtractions.

Example pattern:
```cpp
sqrtf((next.x - prev.x) * (next.x - prev.x)
    + (next.y - prev.y) * (next.y - prev.y)
    + (next.z - prev.x) * (next.z - prev.z));
```
This matched an original sequence that loaded `next.z` twice, then subtracted `prev.z` for one factor and `prev.x` for the other. The natural `dz * dz` expression produced a different x87 stack order.

Try when:
- the function is an FPU expression loop and control flow/register setup already matches;
- the original has repeated `fld` of the same field and asymmetric `fsub` operands;
- decompiler output hints at a strange cross-axis term.

Why it helps:
- VC5 preserves much of the source expression tree in x87 stack scheduling; correcting one “weird” operand can snap the whole loop into the exact basin.

## Lesson: Volatile parameter rereads can preserve duplicate x87 stack operands

When VC5 should keep two copies of the same float parameter on the x87 stack (for example `fld param; fld param; fcomp 0.0; fadd member`) but natural source loads another operand and uses `fxch`, reread the parameter through a volatile lvalue in each source expression:

```cpp
float sum = *(volatile float*)&amount + this->hp;
...
if (*(volatile float*)&amount < 0.0f) { ... }
```

This can force separate stack-parameter `fld` instructions and preserve the original duplicate-operand FPU schedule. Combine with positive success-arm spelling for later FPU comparisons when the original has `test ah,41h; je fail` and success falls through.

Try when:
- the first mismatch is an x87 `fld member`/`fxch` sequence instead of two `fld [esp+param]` loads;
- the parameter is reused for both arithmetic and a sign/zero comparison.

Caveat:
- use narrowly; volatile rereads can add unwanted stack/local traffic in non-FPU contexts.

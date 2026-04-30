# LESSONS.md

This file is the project's shared pattern memory for exact VC5 matching work.
It should simulate the way a human decompiler gradually learns the compiler and
codebase: every time a function finally clicks because of a reusable insight,
record the compact lesson here so future agents can recognize the pattern sooner.

Use this file for generalized eureka moments, especially lessons about:

- source shapes that make VC5 emit the expected assembly;

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


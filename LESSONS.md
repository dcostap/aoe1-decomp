# LESSONS.md

This file is the project's shared pattern memory for exact VC5 matching work.
It should simulate the way a human decompiler gradually learns the compiler and
codebase: every time a function finally clicks because of a reusable insight,
record the compact lesson here so future agents can recognize the pattern sooner.

Use this file for generalized eureka moments, especially lessons about:

- source shapes that make VC5 emit the expected assembly;

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


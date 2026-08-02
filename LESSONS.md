# LESSONS.md

This file is the project's shared pattern memory for exact VC5 matching work.
It should simulate the way a human decompiler gradually learns the compiler and
codebase: every time a function finally clicks because of a reusable insight,
record the compact lesson here so future agents can recognize the pattern sooner.

Use this file for generalized eureka moments, especially lessons about:

- source shapes that make VC5 emit the expected assembly;
- declaration, type, layout, include-context, or flag facts that changed codegen;
- variant-lab findings that revealed a useful compiler basin;
- stubborn-match breakthroughs after many failed equivalent spellings.

Do **not** use this file as a per-function attempt log. Keep detailed local
matching history in the scratch, accepted-drift, or verified-logic source file;
semantic-review history belongs in the per-function `logic_reviews` ledger. In `LESSONS.md`, generalize
from the function: avoid long function-specific narratives, and mention a VA or
function name only as optional evidence.

Before adding a lesson, search for an existing entry that covers the same pattern.
Update and strengthen the canonical entry instead of appending a duplicate. Do not
record temporary blockers, claims that a source shape is impossible, or advice that
conflicts with the current exact-match, relocation-identity, and inline-asm policies
in `AGENTS.md`.

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

## Lesson: Declaration and initialization placement affect scheduling and register roles

VC5 treats declaration scope and initialization position as codegen inputs. Moving a
loop counter out of a `for` header, declaring a pointer before a guard, or separating
declaration from assignment can move zeroing/LEAs across calls and alter saved-register
roles. For example:
```cpp
int i = 0;
object.reset();
for (; i < count; ++i) object.add_default();
```
can emit the counter zero before `reset` rather than after it. Probe these placements
only when the mismatch is a localized setup-order or register-coloring difference;
extra long-lived locals can also make the function worse.

## Lesson: Redundant null-test preservation via mixed local/member access in `&&`

For functions where the original VC5 preserves a redundant `test reg,reg` inside
a short-circuit `&&` expression (e.g. `if (own_pic && pic)` generating both a
guard `test reg,reg` and a redundant inner `test reg,reg`), use a LOCAL alias for
the outer null check and delete calls, but MEMBER ACCESS in the inner `&&`
condition:
```cpp
Type* p = this->member;     // local alias for outer check
if (p != 0) {
    if (this->flag != 0 && this->member != 0) {  // member access inside &&
        p->method();                             // local for the body
    }
    this->member = 0;
}
```
The member access inside `&&` prevents VC5 from optimizing away the redundant
null check, and keeps the saved-pointer register allocation (push edi/edi = ptr).
Example: 0047A5B0 TPicturePanel::free_pic.

## Lesson: IAT import thunks via `extern const` function pointer

When the original calls through an import thunk (`call dword [IAT_addr]` like
`call [88A88Ch]` for MessageBeep), use:
```c
extern "C" void (__stdcall* const FuncName)(arg_type);
```
Calling `FuncName(args)` generates `call dword [encoded_addr]`. The relocation
is handled by the checker while the indirect `ff15` call shape is preserved, unlike
the direct `call rel32` emitted for a normal function declaration.

For repeated imports, VC5 may either issue repeated indirect calls or cache the IAT
function pointer in a register. A narrowly scoped local pointer in only the branch
that reuses it can recover the latter shape; declaration order and `void*` versus a
typed pointer can affect register choice. Keep the real import target and calling
convention exact, and use `__declspec(dllimport)` only when donor context supports it.

## Lesson: Use real MBCS CRT surfaces and split nested calls when push timing differs

CRT MBCS functions like `_mbsncpy`, `_mbsninc`, `_mbsinc` exist in the VC5 CRT
(`mbstring.h`); prefer their real declarations over guessed helpers. For cdecl, VC5
evaluates nested arguments right-to-left, so `_mbsncpy(_mbsinc(p), src, count)` calls
`_mbsinc` after pushing `count` and `src`. To match
an earlier `_mbsinc` call, split the expression:
```c
p = (char*)_mbsinc(p);
_mbsncpy(p, src, count);
```
VC5 can then reuse the return in `eax` for the destination push without a stack temp.

## Lesson: Derived-class field layout requires the exact visible base size

When a derived class adds fields past a large base, model the base's exact size,
including its implicit vptr and every proven field boundary. A monolithic byte gap
can preserve `sizeof` if counted correctly, but field-level gaps are preferable once
subfields are known because they prevent accidental vptr double-counting and make
reused offsets auditable.

## Lesson: VC5 block layout for if statements is non-trivial

`if (x == 0) { return; }` can produce either `je` (early return at end as jump
target) or `jne` (early return inline with jump to success). The original
Scr_main.cpp Error ctor has early return inline (failure = likely path).
Goto labels can influence CFG shape but do not reliably dictate physical block
placement; `/O2` may still rearrange them.

When the original puts a rare failure/null handler late, try a positive guarded
success body with `else`/shared failure after it. Nested positive bounds can likewise
route several checks to one tail. Use negative early returns when the binary instead
keeps the rare handler inline. Source arm order is a layout probe, not a semantic rule.

## Lesson: Model the proven subfield offset directly, not an invented helper subobject

When asm proves an array-element size and fixed subfield offset, model those bytes
directly. Do not invent a helper wrapper or vptr that shifts the payload merely to
make decompiler output look object-oriented. Replace a local raw view with the real
shared type once broader evidence proves it.

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
`[vtable+0xA8]`, `[vtable+0xF0]`, `[vtable+0x28]`, `[vtable+0x7C]`), a local flat
dispatch-view class with declaration-only placeholder virtuals can align the called
methods at the observed indices. The compiler then generates natural
`call [vtable+offset]` dispatch without raw function-pointer casts.

```cpp
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
```

Count slots exactly (`offset / 4`). Keep a synthetic dispatch view flat, account for
its implicit vptr, and prefer declaration-only placeholders so the TU does not emit
unrelated inline COMDATs. Use the real inherited surface when it is known.

## Lesson: `__declspec(novtable)` + manual vtable store for delayed vtable scheduling

When a constructor's original binary shows the vtable write happening well into the
constructor body (after field initialization, subobject construction, etc.), but
the natural verified class surface writes it at the start, a narrow fallback is to use
`__declspec(novtable)` on the class and write the vtable pointer manually as an
explicit store in the body. `novtable` suppresses the automatic derived-vptr write
while retaining the virtual surface needed for other lowering.

Caveats:
- Only works if VC5 supports `__declspec(novtable)` (introduced in VC5)
- The base class constructor may temporarily set a different vtable; the manual
  override replaces it at the right time
- Apply `novtable` only to the class whose automatic store must be suppressed;
  preserve the real base surface and constructor behavior.
- Body assignments can also let VC5 batch repeated scalar values around the manual
  vptr store; initializer-list stores may schedule differently. Keep the proven
  field offsets and observed store order rather than assuming one universal form.

## Lesson: Duplicate assignment in both arms can preserve compare-store-branch scheduling

When VC5 needs to emit `cmp`, then an independent store, then the conditional branch
that consumes the compare flags, write the source with the same assignment in both
arms around the guarded body. For example, after an allocation and `short i = 0`,
`if (i < count) { field = ptr; do {...} } else { field = ptr; }` can compile to
`cmp count,i; mov field,ptr; jle skip`, because the common assignment is hoisted
between the compare and branch. A single assignment before/after the `if` may schedule
as `mov; cmp; jle` or `cmp; jle; mov` instead. Use only when the duplicated assignment
is genuinely equivalent on both paths.

## Lesson: `je` dispatch to handlers after the epilogue signals a switch

In VC5, a `switch` statement emits `je` (jump-if-equal) instructions that target
handler blocks placed after the function's main epilogue (a "jump table" or
"dispatch-to-case-at-end" pattern). If the original asm shows `je` targets
pointing to code after the main `ret`/`pop` sequence, try a `switch` before
hand-shaping `if/else` or early-return chains.

Try when:
- The original asm dispatches a value via `cmp reg, X` / `je target` where
  `target` is after the function's main epilogue.
- An `if/else if/else` or `if+return` chain generates `jne`-skip (cases inline,
  else at end) rather than `je`-jump.

Explicit `default:` changes the bounds-failure target, and source case order can
change physical body order even when dispatch semantics are unchanged. Preserve a
real default assignment/call and probe case order when only placement differs. For
sparse signed values, a natural switch may lower to a signed compare tree instead
of a jump table.

## Lesson: C source files must have .c extension for correct codegen

When PDB metadata names a `.c` donor, keep the scratch source as `.c`. Compiling it
as C++ changes declaration/linkage rules and can alter codegen. Do not use C++
classes, references, or other C++-only scaffolding to make a C donor compile.

## Lesson: A goto can preserve a separate found/not-found block

Using `goto found;` / `found:` instead of `break; if (!cur) return;` can steer VC5
into a separate early-return/found-block layout. This was effective for
RESFILE_close_new_resource_file (0047F180), where `break; if (!cur) return;`
produced different jump distances and block ordering. The `goto` made the early
return a separate basic block, matching the original's pop+ret at the not-found
path. Treat this as a local CFG probe, not a guarantee of final block placement.

## Lesson: Model binary-observed parameter-slot reuse directly

VC5 often reuses a dead incoming stack slot as scratch. When asm writes to
`[esp+param]`, passes its address, or later reloads it at a narrower width, save the
still-needed original value and assign back to or take the address of the parameter.
Serialization helpers commonly preserve a file handle in a register while using its
old stack slot as the read/write buffer. Conversely, do not force explicit mutation
when the compiler naturally chose the dead slot for an ordinary block-local temp.

The same reuse can arise from a natural API output local: declare the separate
out-pointer local and pass its address, rather than taking the address of the input
parameter just because the binary uses that incoming slot. In old C utility code,
an initialized descriptor plus a separate wave-data output local can let VC5 reuse
the dead name-parameter home while preserving the original zero-store schedule.

## Lesson: Nested-if branch control for signed bounds checks

When matching forward branches (`jl`/`jg` for error exits) in functions with signed bounds checks:

- `if (index >= 1) { table = info->table; if (index <= count) { return ...; } } return -1;`
  generates `jl → return -1; jg → return -1` (original pattern).

- `if (index < 1) return -1; if (index > count) return -1; return ...;`
  generates the inverted form: `jge → skip_error; jle → skip_error` with inline error returns.

The nesting approach (`if (condition) { ... }`) puts both error-exit jumps as forward branches to a SHARED error epilogue, matching the original block layout. The early-return approach inlines the short error paths, inverting the branch direction.

This pattern applies to any function with signed `if (x >= min && x <= max)` bounds checking where the original uses `jl`/`jg` for a shared error return. Verified with `currentScore` (004E6870).

## Lesson: While-loop rotation for linked-list and array traversal

`while (node != 0) { body; node = node->next; }` often lets VC5 rotate the null
check to a bottom `jne` backedge. Keep the pointer advance last when the original
has that shape. A `do/while`, explicit break, integrated found handling, or top null
break can each produce different entry/exit tests, so choose from observed CFG rather
than assuming one canonical list loop.

## Lesson: Compare operand order for short/integer comparisons

For `if (this->frame >= param_1)` (memory on left), VC5 generates `cmp [ecx+14h], ax; jl → exit`.
For `if (param_1 <= this->frame)` (register on left), VC5 generates `cmp ax, [ecx+14h]; jg → exit`.
Both produce the same logical result but different bytes. Put the member field on the LEFT for `cmp [mem], reg` encoding. Verified with `frame_passed` (0041B560).

## Lesson: Use typed member declarations for direct and virtual `thiscall` calls

Model direct member calls as non-virtual declarations and vtable dispatch as
virtual declarations at the observed slot. VC5 then supplies `ECX=this` and emits
either `call rel32(symbol)` or `call [vtable+offset]` naturally. This is safer than
raw calling-convention casts; explicit `__thiscall` function-pointer syntax is not
reliably accepted by this VC5 compiler.

Keep the signature, inheritance boundary, vtable index, and external symbol exact.
The checker validates direct-call relocation identity, and a virtual declaration
also changes object layout by introducing an implicit vptr. Use a local flat
dispatch view only when the real class surface is unavailable.

## Lesson: Header-provided CRT declarations can be required for constructor EH shape

In `/GX` constructors, hand-declaring CRT functions such as `calloc` can keep VC5 in a non-EH or wrong register-save basin even when behavior is identical. If a matched sibling constructor uses `<stdlib.h>`, include it rather than replacing it with `extern "C" void* calloc(...)`. Also, after a base constructor stores a parameter into a member, using the member (`this->obj`) for later work can avoid preserving the incoming parameter in an extra callee-saved register. Verified on 004CE530 `TRIBE_Action_Discovery_Artifact`.

## Lesson: Use the real constructor call to trigger VC5 `/GX` new-object EH state

For factory/init helpers where the original has an SEH `FS:[0]` frame, a try-level local set to `0` around construction, and then reset to `-1`, model the allocation as a direct C++ construction expression:

```cpp
T* obj = new T(arg1, arg2, ...);
```

Do not lower it to `new T; obj->init(...)`: even if the called routine is the same code address, VC5 may not generate the constructor EH state pattern. Also avoid defining empty special members locally just to satisfy declarations; an empty destructor/ctor body can emit an extra COMDAT before the target and shift extraction. Leave special members as declarations when only their call surface is needed. Verified on 0045A9E0 `init_missile`.

Make `sizeof(T)` match the observed allocation immediately, including any real vptr
or base. An empty/undersized local stub can preserve the EH shape while emitting the
wrong `operator new` argument.

## Lesson: Direct member access versus locals controls reloads and liveness

Named pointer/value locals can preload fields, enable CSE, and keep values live across
calls; repeated direct member expressions can delay loads and preserve binary-observed
rereads. Conversely, a local is appropriate when asm clearly carries one value through
a phase. Choose from observed load timing and register lifetime, not source tidiness.
If only one guard must remain uncached, use a narrow volatile read rather than making
the whole object or API volatile.

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

## Lesson: Narrow volatile float rereads can preserve x87 operand order

When an FPU expression differs only in stack-parameter/member load order or an
observed duplicate parameter load, a narrow volatile lvalue read such as
`*(volatile float*)&param` can prevent CSE and preserve the stack-slot operand.
Declaring the by-value parameter itself volatile is another probe, but keep volatility
local when possible and use it only for binary-observed rereads—not as an API claim.

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

## Lesson: Member-field reload for per-store register cycling in init blocks

When original initialization code reloads an allocated pointer member before each
field store, use repeated `this->member` accesses rather than carrying the allocation
result in a local. A local encourages one long-lived address register; member reloads
can reproduce VC5's alternating `eax/ecx/edx` load-and-store schedule.

Apply only when repeated loads are binary-observed. Do not manufacture them merely
to perturb register allocation, and model the member as a pointer rather than an
integer when its real type is known.

## Lesson: Width and signedness control loads, registers, and branch families

`char`, `short`, `int`, and unsigned spellings are not neutral in VC5. They affect
byte-register eligibility, `movsx` versus `movzx`, integer promotion, compare width,
and signed (`jl/jle`) versus unsigned (`jb/jbe`) loop branches. Match the real
parameter/field ABI first, then use an accurately typed local or cast at the use
site when the binary proves a narrower or differently signed operation. Never widen
a real call signature merely to steer caller codegen.

## Lesson: Member initializer list delays vftable override in constructor body

When a derived constructor initializes a field in its initializer list, VC5 can place
the derived-vptr write after initializer stores but before body statements. Moving the
same assignment into the body can move the vptr earlier. Initializers execute in
member declaration order, not textual list order, so verify both layout and schedule.

## Lesson: Equivalent boolean spellings select different branchless idioms

VC5 may lower `cond ? -1 : 0` as `neg/sbb`, a guarded bounded return as
`sbb/and`, and `cond ? 0 : 1` as `setcc`. An ordinary boolean expression or explicit
branch can choose another family. When the original uses one of these compact idioms,
probe natural ternary, guard-return, and explicit-if spellings rather than hand-writing
arithmetic. Exact lowering remains sensitive to operand width and use.

## Lesson: Removing explicit `if (n <= 0)` guard eliminates VC5's redundant duplicate loop guard

When a `for` loop uses `i < n` as its condition, VC5 already generates the upper-bound guard
(`test n,n; jle epilogue`) internally. An explicit `if (n <= 0) return 0;` before the for-loop
creates a *redundant* duplicate guard — the second `test/jle` appears right before the loop
body, adding 4 extra bytes. Removing the explicit check lets VC5 generate exactly one guard,
matching the original binary.
Keep an explicit guard when it performs side effects or the binary proves both checks.

## Lesson: Proper struct members generate tighter code than raw casts

When layout is known, typed member access often lets VC5 fold address calculation
and sign extension into one memory operand. Prefer it before raw byte casts. Retain
a local raw view only when the binary proves an offset but the broader type remains
uncertain or the typed surface demonstrably chooses the wrong address basin.

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

VC5 may merge the final conditional and terminal return into one speculative
result assignment and shared epilogue, changing compare form and pop order. If the
original keeps distinct exits, duplicating the fallback return at the end of the
guarded arm can preserve a separate destination block:

```cpp
if (param_1 == 1) {
    // ... checks with early returns ...
    return -1;
}
return -1;
```

Use this only when the binary proves separate epilogues; otherwise prefer the
natural shared return.

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

## Lesson: Independent store order and dependencies affect VC5 scheduling

VC5 can reorder adjacent non-volatile stores or reuse a return register for a
same-valued store. Probe source assignment order—even the reverse of asm order—when
the effects are independent. If asm requires a store before a later reload/compare,
a natural comma expression or direct reread can express the dependency. Do not mark
ordinary fields volatile solely to freeze instruction order; that changes semantics
and often perturbs the wider function.

## Lesson: Raw vtable slot to member-function-pointer preserves thiscall indirect-call shape

When a function needs `mov ecx,this; call reg` from a vtable slot (no caller stack cleanup),
loading the slot into a plain cdecl/stdcall/fastcall function pointer often introduces wrong
cleanup or extra register setup (`add esp,...` or `xor edx,edx`).

Prefer a real virtual declaration first. Use the lower-level member-pointer form only
when asm specifically proves a separately loaded runtime call register.

A reliable VC5 pattern is:
- declare a member-function pointer local (`int (Class::*m)(Arg1, Arg2);`)
- copy the raw vtable slot into it (`*(int*)&m = *(int*)((char*)*(void**)obj + slot);`)
- call via `(obj->*m)(...)`.

This preserves `thiscall` call shape while still allowing a runtime-loaded call target.

Reference: `0046F010` (`processAddWaypointCommand`) matched exactly with this form after
fastcall/cdecl pointer variants were close but not exact.

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

## Lesson: Stubborn register coloring can depend on the full typed class surface

If a tiny helper is stuck in a pure register-coloring mismatch and raw gaps/local stubs keep collapsing to the same near-miss, try restoring the real typed class body for the main object even when the function only touches one early field. For `00435020`, every minimal `gap_00[0x0C]; owner;` surface kept producing `CX/EDX` in the owner-id compare, but the exact basin appeared once `RGE_Static_Object` used its fuller real field list (including later members like the `ManagedArray<int>` blocks) while the source stayed otherwise simple. In VC5, TU/type context can steer allocator choices even when the accessed offsets are unchanged.

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

## Lesson: 1-based enum arrays may need `array[type - 1]` to recover base-minus-one indexing

When an enum's first real value is 1 but the object stores a zero-based pointer array, VC5 can fold `array[type - 1]` into an address like `[this + type*4 + (array_offset - 4)]`. If the original asm shows the base displacement four bytes before the declared first element (for example `[edi+ebx*4+504h]` while the first array element is at `+508h`), do not add a fake field or raw cast first; spell the source as the natural one-based enum adjustment.

Try when:
- the only remaining diff is an indexed member-array displacement off by exactly one element;
- the index register holds a 1-based enum value used directly elsewhere.

Why it helps:
- VC5 folds the `- 1` into the addressing displacement, preserving the original compact SIB form without extra arithmetic.

Reference: `004AA7A0` (`TRIBE_Screen_Sed::set_map_type`).

## Lesson: External table declarations and inline indexed access can prevent spills

When original code indexes fixed lookup tables through relocations, declare the tables as `extern const` rather than defining file-local arrays. A local definition can put data in the scratch object and change addressing/relocation behavior.

For small bitfield helpers, also try inlining repeated table lookups instead of naming a `shift` local. VC5 may keep the table-loaded shift count in `cl` across adjacent `shr`/`shl` operations only when the access is inline; a named local can force a spill/reload between the shifts.

Try when:
- the original has external table loads but rebuilt creates local data or different references;
- the only remaining diff is a `cl` spill/reload around shift-count use;
- a mask/shift table is indexed by the same small expression more than once.

Caveat:
- use `extern` only when the table really exists in the original binary/shared data surface; do not hide unknown constants behind extern declarations.

## Lesson: Shift loop: post-increment `value[i] = value[i+1]` over `++i; value[i-1] = value[i]`

For shifting array elements left by one position, `this->value[i] = this->value[i + 1]; ++i;`
generates the compact two-address `mov esi,[edx+eax*4]; mov [edx+eax*4-4],esi` form. The
pre-increment form `++i; this->value[i - 1] = this->value[i];` generates an `lea`-based form
(`mov esi,[edx+eax*4]; lea edx,[edx+eax*4]; mov [edx-4],esi`) that is one instruction longer
(VA 004F1390 `ManagedArray<int>::remove`).

## Lesson: Leave the base destructor implicit unless the binary proves an explicit call

When a derived class destructor is compiled with `/GX`, VC5 auto-generates the base
destructor call at the end of the derived body. An explicit source call usually
duplicates it and shifts EH state. Leave it implicit unless the binary clearly proves
two calls or a nonstandard ordering; in that exceptional case, model both deliberately.

## Lesson: /GX EH-framed destructors: explicit temp for member pointer forces register save

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

## Lesson: Separate `next` local forces two-register linked-list walk pattern

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

## Lesson: Preserve a named byte-count temp to let VC5 schedule independent array stores between `push` and `call`

When a one-argument allocation call should appear as `push bytes; mov [array+idx*4],value; call malloc`, avoid introducing a pointer result temp (which increases register pressure) and avoid folding the size expression directly into the call (which can store too early). Use a named integer byte-count temp before the side-effecting array store:

```cpp
int bytes = this->elementSize * grow;
sizes[idx] = grow;
this->zonePtrs[idx] = (T*)malloc(bytes);
```

VC5 can keep `bytes` in the expected register, push it, and schedule the independent `sizes[idx]` store into the call setup gap. A separate allocation-result temp may force an extra saved register and reorder the surrounding counter updates.

## Lesson: Float-typed fields can be needed even when stores are integer `mov` immediates

When original asm stores constants like `0x43480000` and `0x42C80000` with integer `mov` instructions, model the destination as `float*` and write `200.0f` / `100.0f`, not integer `200` / `100`. VC5 will still use integer immediate stores for float constants in memory, but the immediate values match the IEEE-754 bit patterns. Integer fields with integer literals produce the same instruction shape but wrong constants.

## Lesson: Inline denominator call can force VC5 `fdivr` instead of x87 stack shuffle

When a float ratio should compile as `fstp temp; call denominator; fdivr temp`, avoid naming the denominator result as a separate `float` local. Keep only the numerator temp and inline the denominator-producing call in the division, e.g. `sum = numerator / obj->denominator() + sum;`. A named denominator local can make VC5 preserve/reload both operands with `fld`/`fxch`/`fstp` and use `fdiv`, shifting the whole loop even though the math is equivalent.

## Lesson: Split chained member calls to prevent argument interleaving

When a call result is immediately used for another member call and later another argument-producing call feeds a small wrapper, VC5 can interleave argument pushes if the source keeps everything as one expression. If the original shows one call's full argument block, call, `mov ecx,eax`, second call, then a separate helper call whose result is pushed into a wrapper, split the expression into named pointer/message temporaries. This preserves the natural call boundaries and avoids extra/early pushes from nested argument evaluation.

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

## Lesson: Natural virtual destructor surface can beat manual vptr/base-dtor plumbing

For EH-framed VC5 destructors that restore a derived vtable, call a few virtual methods, then tail into the base destructor, prefer a real `virtual ~Base()` / `virtual ~Derived()` class surface and let the compiler emit the vptr restore and base-dtor call. Manual `this->vtable_ptr = addr; ... this->Base::~Base();` can be behaviorally identical but may reorder the vptr store after object loads/EH-state setup and route the base destructor through an extra local thunk/call basin. A natural virtual destructor declaration can make VC5 place the vptr store at the source-line boundary and emit the direct base destructor tail expected by the original.

## Lesson: Declare global byte bases as `char*` to recover indexed LEA/load/store sequences

When a global table base is used only for byte-offset arithmetic, declaring it as `extern char*` and indexing it directly can steer VC5 into the original register/addressing basin:

```cpp
extern char* global_base;
int* p = (int*)(global_base + index * 4 + OFFSET);
int old = *p;
*p = old - 1;
```

This can emit a separate global load into the expected register plus `lea address`, `mov value`, `dec`, `mov [address],value`, instead of shorter or shifted forms such as `a1` global loads, memory `dec`, or recomputed `[base+index]` stores.

Try when:
- the logic is correct but the global table load uses `mov eax,[imm]`/wrong register instead of `mov edx,[imm]`;
- VC5 collapses a read-modify-write on a global indexed table or emits a one-byte-short branch-shifting variant.

Caveat:
- use this only when the global truly is being treated as an untyped byte base in the original addressing; typed globals may be preferable for ordinary field access.

## Lesson: Avoid naming a reusable divisor when the original delays saving EAX across a call

For expressions like `debug_rand(...) % member + (base - member / 2)`, naming `int sep = member` can make VC5 allocate the divisor in EDI from the first load (`mov edi,[...] ; test edi,edi`). If the original instead loads/tests in EAX and only does `mov edi,eax` immediately before the call, try leaving the member as direct rereads inside the expression:

```cpp
if (this->member > 0) {
    this->out = debug_rand(file, line) % this->member + (this->base - this->member / 2);
}
```

Even though this looks like extra source-level rereads, VC5 can keep the tested EAX value until the call-save point and then generate the expected delayed `mov edi,eax`, idiv, and signed-half arithmetic. Use when a correct local-divisor version is stuck in an early saved-register family.

## Lesson: Member helper surface can preserve `this` and call-argument scheduling

When a method calls helpers that are really same-class `thiscall` members, declaring
them as free/static functions can make VC5 treat `ECX` as scratch and change argument
scheduling. A real member declaration keeps `ECX` live as `this`. Preserve the exact
helper symbol/signature; do not invent a second declaration merely to block tail merging.

## Lesson: Plain C++ callee declarations can trigger /GX constructor base-unwind frames

For compact /GX constructors that call a nontrivial base constructor and then call a helper such as `rge_read`, declaring the helper as `extern "C"` can suppress the C++ EH constructor frame entirely: VC5 emits only the short non-EH body even though the original has the `push -1 / fs:[0]` frame and a state store after the base ctor.

If symbol/PDB evidence shows C++ linkage, declare it as an ordinary C++ function:

```cpp
void rge_read(int handle, void* buffer, int count);
```

Try when:
- a constructor under `/GX` is byte-perfect in the body but the rebuilt object is missing the whole EH prologue/epilogue;
- adding fake cleanup locals/destructors creates the right frame size but inserts extra normal-path destructor calls;
- the call after the base constructor is currently declared `extern "C"`.

Why it helps:
- VC5 treats the plain C++ call as potentially throwing, so it emits the base-subobject unwind state for the already-constructed base;
- the call remains a normal direct call to the verified helper symbol while the
  declaration exposes the correct throwing context.

Caveat:
- keep `/GX` only when the original has the EH frame, and do not change linkage if it
  would name a different external symbol; relocation identity remains mandatory.

Reference: `00405510` and `004CF090` matched by changing only `rge_read` from `extern "C"` to a plain C++ declaration.

## Lesson: Split aggregate loads and vtable loads to control late store scheduling

When VC5 moves a call argument push or structure field store too early around a
zeroed stack aggregate, split source into small named loads in the original order
and introduce a vtable/function-table local before the late field assignment.

Try when:
- the rebuilt code has the right `rep stosd`, globals, and virtual call, but
  schedules a constant argument push or `dwSize`/header store before nearby
  global copies;
- the original loads a service/global pointer and vtable before a final aggregate
  header store immediately before the call.

Why it helps:
- naming each global dword load can preserve the original load/store interleave;
- `void** vt = *(void***)serv;` creates a real use that VC5 schedules before the
  following field assignment, allowing a later `desc.a[0] = size` store to land
  after the vtable load but before the remaining argument pushes/call.

Caveat:
- this is a scheduling tool for already-understood calls; it can worsen codegen if
  the function pointer local changes register pressure or if argument order is not
  already correct. Verified on `004324F0` Refresh.

## Lesson: Use `strcpy` to expose VC5's exact strlen-plus-copy REP-string idiom

When a function copies a NUL-terminated string and the original assembly shows a
`repne scasb` length scan followed by `rep movsd`/`rep movsb`, try the natural
`strcpy(dst, src)` surface before spelling it as `strlen(src)+1` plus `memcpy`.

Try when:
- manual `strlen`/`memcpy` produces the right REP instructions but schedules the
  destination slot calculation after the scan or saves `this` unnecessarily;
- the original computes the destination pointer/slot before the scan and then
  copies the whole string including the terminator.

Why it helps:
- VC5 recognizes `strcpy` as a single string-copy idiom and can lower it to the
  compact scan/copy sequence with the same live registers;
- separate `strlen` and `memcpy` calls/expressions can create extra temps, delayed
  address calculation, or no-op length adjustments.

Caveat:
- keep any destination slot pointer local if later code reuses the same slot; this
  can preserve the null-source and tail-store shape. Verified on `0048BA60` Set_BuildList.

## Lesson: Preserve destructor inheritance context but override a vtordisp-shifted field access with a proven byte offset

For destructor matches, real inheritance may be needed to get VC5's EH frame,
vptr restore, base-destructor call, and saved-register choices. If that inherited
surface inserts a vtordisp and shifts a derived field by 4 bytes compared with the
binary, do not throw away the whole class context. Keep the inheritance and access
the binary-proven field through an explicit byte offset:

```cpp
FieldType*& field = *(FieldType**)((char*)this + 0x104);
```

Try when:
- the destructor frame/registers/base call match with inheritance;
- only a derived field load/store is off by a vtordisp-sized displacement
  (for example +0x108 rebuilt vs +0x104 original).

Why it helps:
- VC5 still sees the natural destructor context, while the source forces the exact
  data offset used by the original binary.

Caveat:
- use only for binary-proven offsets; do not hide uncertain class layout guesses
  behind raw pointer arithmetic.

## Lesson: Exact stack windows can beat nominal locals for fscanf filename blocks

When a loader parses many fixed-width filename buffers with one large `fscanf` and then passes
odd slices of those locals to virtual load helpers, a single explicit stack-window array can be
closer to the original than many named `char name[24]` locals.

Try when:
- the original reserves one large frame and all pre-call `lea` offsets form a regular record layout;
- named locals get the right behavior but frame size/local order is off;
- later helper calls pass a mixture of pointers and dword values reloaded from the same local slots.

Why it helps:
- using `char local[frame_size]` and binary-observed offsets preserves VC5's exact `lea [esp+disp]`
  setup across right-to-left vararg pushes;
- modeling stack-slot dword reloads as `*(int*)(local+off)` prevents VC5 from taking addresses where
  the original loaded the slot contents.

Caveat:
- only use this after the frame layout is proven from asm; otherwise prefer typed/named locals.
  Verified on `005415B0` (`data_load_world`).

Interpret every `lea [esp+N]` with the transient argument pushes present at that
instruction. A decompiler's `buffer+4` name may be a stack-accounting artifact; try
the natural buffer start unless multiple binary accesses prove a real slice.

## Lesson: Overlay struct for parallel arrays accessed through a single iterating pointer

When VC5 accesses multiple parallel member arrays through the same iterating
pointer (e.g. `&resources[iter]` to also reach `numResources[iter]`,
`closestDropsiteValue[iter]`, etc.), it uses one base register (ebx) and fixed
offsets, never computing the index explicitly.

Writing `int idx = rp - &this->resources[0]` and then `this->closestDropsiteValue[idx]`
defeats this: the compiler computes idx with a sub/sar sequence and uses scaled-index
addressing, which adds an extra local and shifts the frame.

**Fix:** Define a local struct that overlays the parallel arrays' memory layout as
seen from the base pointer, cast `&resources[0]` to it, and access fields through it.

The struct has padded fields at the correct offsets (0x10 for count, 0x70 for
closestDropsiteValue). The compiler then emits `mov [ebx+70h]` exactly. Advance
by 4 bytes per iteration via `rp = (BlockType*)((int*)rp + 1)`.

Used in: `004E2D10_updateAllResourceDropsites`.

## Lesson: Generating `rep movsd` for block copy loops in VC5

VC5 with `/O2` generates inline `rep movsd` for `memcpy()` calls with non-constant
sizes when `<string.h>` is included and the size is a multiple of 4. The compiler
emits alignment-handling code (`shr ecx,2` + `rep movsd` + `and ecx,3` + `rep movsb`)
for arbitrary sizes, or a plain `rep movsd` when it can prove alignment.

Manual dword copy loops (`while (n--) { *d++ = *s++; }`) do NOT trigger `rep movsd`
in VC5; they compile to inlined scalar dword moves (`mov [edx],ebx; add edx,4; dec ecx; jne`).

## Lesson: __ftol via C-style cast avoids temp spill overhead

When the original asm calls `__ftol` directly without storing the float argument
to memory (`fld; fmul; fdiv; fmul; call __ftol` — result stays on FPU stack),
passing the expression through `__ftol(expr)` (declared as `extern long __ftol(float)`)
forces VC5 to `fstp` the result to a stack temp, reload it on the next line, and
do `push ecx/add esp,4` around the call. Using `(long)(expr)` C-style cast instead
keeps the value on the FPU register stack, generating the same `...; call __ftol`
pattern as the original.

Also, when calling a `__thiscall` method (ecx=this, parameters on stack), declare
the method as a member function of the appropriate class and use `ptr->method(args)`
syntax. The compiler generates the correct `mov ecx, ptr` setup. Do NOT redeclare
it as a `__fastcall` wrapper with dummy second parameter (the added `xor edx,edx`
for the unused edx parameter bloats the call site by 2 bytes).

For `unsigned char` locals that are only compared against 0 or 1, use
`unsigned char done = 0` instead of `int done = 0`. VC5 generates a byte store
(`mov byte [esp+4], 0`) matching the original, and avoids allocating a
callee-saved register (`esi`) for the flag variable.

For `fild` of a 32-bit integer difference, store the intermediate in an explicit
`int ticks = cur - prev` local rather than casting inline. The compiler emits
`fild dword [mem]` (32-bit load) instead of `fild qword` (64-bit load).

Used in: `00493540_RGE_fade_palette_step`

## Lesson: Inline the real `ManagedArray<int>::operator[]` surface instead of hand-expanding resize

When original code indexes a `ManagedArray<int>` and the asm includes the familiar
inline grow/copy/delete path (`index > maximumSizeValue - 1`, allocate `index+1`,
copy while bounded by both old max and new size, update `value`/`maximumSizeValue`),
define the actual `operator[](int)` body and use `array[index]` at the call site.
Hand-expanding equivalent resize logic in the parent can look close but VC5 may
emit extra pre-loop tests, different loop predicates, or shifted block sizes. The
inline operator surface lets VC5 reproduce the canonical utmarray.h code shape.

## Lesson: Model strided scenario tables as real multidimensional arrays for indexed member addressing

When VC5 should compute `index * stride` once, keep that offset in `eax`, form a
separate base register with `lea edi,[eax+this]`, and then access fields as
large `[edi+member_offset]` displacements, a real member array such as
`int table[N][20]` can be crucial. Hand-building a row pointer like
`&table[i * 20]` may instead make VC5 set the base register to the member address
(`this + offset + member_offset`) and then use short `[edi+small]` displacements,
which is behaviorally identical but changes size and every following branch/jump
span. Prefer natural multidimensional member indexing (`this->table[i][j]`) when
original asm has the `lea index; shl; lea base=this+index; [base+field]` pattern.

## Lesson: Proven fixed-address globals can use a narrow local absolute view

When the binary proves a global's absolute address and no stable shared declaration
exists yet, a local typed macro such as `(*(T**)0x0062C574)` can emit the observed
absolute memory operand. Prefer the shared global surface once the identity/type is
stable. Do not use an arbitrary address to bypass relocation or symbol-identity
checks, and do not assume all extern-global relocations are interchangeable.

## Lesson: Literal call-and-return arms can tail-merge into `push imm; jmp shared_call`

When a long dispatcher has many arms that all call the same member function with a
small literal argument and return success, spell each arm as the direct call plus
return (for example via a `SEND(imm)` macro) instead of assigning the argument to a
shared `code` local and calling once at the end.

Try when:
- the original emits `push imm` in each matching arm followed by a jump to one shared
  call/return tail;
- the rebuilt uses `mov eax, imm` in each arm and `push eax` at the shared tail.

Why it helps:
- VC5 tail-merges identical call/epilogue sequences while preserving each arm's
  literal argument push, avoiding a live result/code local and saving bytes per arm.

Caveat:
- this only applies when every arm is semantically an immediate call-and-return;
  if later code really consumes the selected value, keep the local.

## Lesson: Explicit if/else byte assignment can avoid setcc zero-extension

When the original stores a boolean byte with `cmp ...; sete cl; mov [field],cl` and
there is no preceding `xor ecx,ecx`, a compact expression or ternary assignment to an
`unsigned char`/`bool` field may make VC5 zero the whole register first. Spell the
assignment as an explicit `if { field = 1; } else { field = 0; }`; VC5 can still
collapse it to `setcc` but may omit the zero-extension and preserve the original
scheduling. Verified on TXChat (00429870).

## Lesson: Lock/Unlock cleanup may run after failed Lock when guarded by outer feature flag

When original code checks an outer feature/state flag, calls `Lock`, and then branches to a common default/tail block on Lock failure or switch default, do not assume `Unlock` is inside the `if (Lock())` body. A source shape like:
```cpp
if (enabled) {
    if (draw->Lock(name, 1)) {
        switch (mode) { ... }
    }
    draw->Unlock(name);
}
```
can be required even though it appears to unlock after a failed lock. This fixes the near-branch target to the shared cleanup block rather than the final epilogue. Verified on Time_Line_Panel::draw_border (0051F120), where moving `Unlock` outside the Lock-success guard changed the only remaining byte and produced an exact match.

## Lesson: FPU `test ah,41h` after `fcomp` often means inclusive bound (`<=` / `>=`), not strict `<`

When VC5 emits `fcomp`, `fnstsw ax`, then `test ah,41h` and branches on nonzero, it is testing C0 or C3: less-than OR equal (and some unordered cases depending on operands). If a near match differs only by `test ah,01h`, the source likely used an inclusive comparison such as `x <= 0.0` or `max <= x`, not a strict comparison like `x < 0.0` / `max < x`. This can fix a tiny mask-only diff without changing surrounding FPU code. Verified on TribeConstructionAIModule::canPlace (004D5F00).

## Lesson: Duplicate branch calls can preserve pre-pushed argument layout around a shared call tail

When one branch selects between two constant/string arguments for the same member call, a tidy source shape with a `target` local followed by one common call can compile shorter/differently than the original. If the original pushes the call arguments inside each branch and jumps into a shared tail at the `mov ecx, object; call method` sequence, spell the call in both branches:

```cpp
if (panel_exists) {
    panel_system.setCurrentPanel(name_a, 0);
} else {
    new Screen;
    panel_system.setCurrentPanel(name_b, 0);
}
```

Try when:
- rebuilt code uses `mov eax, const; jmp common_push_args` but original has `push 0; push const; jmp common_call`;
- the diff is a small size/layout mismatch around two branches that call the same method with different constant args.

Why it helps:
- VC5 can tail-merge the actual `this` load and call while preserving branch-local argument pushes and EH-state stores.

Caveat:
- only duplicate the call when both branches truly make the same call and the original shows arguments already pushed before the join.

## Lesson: For COM vtable calls, naming the vtable local can preserve load-before-local-store setup

When matching VC5 code that calls a COM-style `__stdcall` vtable method and initializes an input struct immediately before the call, a direct typed expression such as `obj->vtbl[n](obj, &local, flags)` may let VC5 store the struct size before loading the vtable. If the original loads `ecx = [eax]` first, then pushes arguments, then stores `local.dwSize` after the pushes, introduce a `void **vtbl = obj->vtbl;` local before the struct-size assignment and call through `vtbl[n]`.

This can make VC5 emit the original sequence:
`mov ecx,[eax] ; ... push flags ; push &local ; push eax ; mov [esp+...],sizeof(T) ; call [ecx+slot]`.

Caveat: make sure the struct layout is exact; in DirectPlay `DPCAPS`, `dwMaxLocalPlayers` sits before `dwHeaderLength` and `dwTimeout`, so a size-only fix can still leave later stack-offset mismatches.

## Lesson: Combined `&&` loop bounds can remove extra guard tests and recover VC5 counted-copy loops

For small array search/copy loops with two upper bounds, spelling the loop as a single combined condition (`while (i < count && i < capacity)`) can produce VC5's compact compare-at-bottom topology. An equivalent source with outer `if`, `do`, and explicit `if (i >= capacity) break;` may add extra `test`/`jge` guards, shift block layout, and perturb saved-register choices even when behavior is the same.

Try this when an append/reallocation helper is behaviorally right but rebuilt loops contain extra pre-loop capacity tests or pointer-increment scans while the original uses indexed `[base+eax*4]` loads and a pair of simple bound compares. Verified on a managed-int-array append in TribeInformationAIModule::addObject (004DC1B0).

## Lesson: Derived `new` can be needed just to reproduce post-constructor vptr stores

When VC5 emits `operator new`, a base-class constructor call, then an explicit vptr store before using the object, model the allocation as a small derived class even if the surrounding code only calls base methods. A plain `new Base` may compile to the same allocation and constructor call but omit the post-constructor `mov [obj], derived_vtbl`, producing a too-small EH/new block. This can occur for adjacent list members where some are derived list types and a later one is only the base type. Verified in TRIBE_Player::load (005128A0) for two object-list members.

## Lesson: If a virtual numeric getter feeds a common `ftol`, its source return type may be `float`

When original VC5 code chooses between a virtual getter and a float member, then joins both paths at one shared `__ftol` call, declare the virtual getter as returning `float` and cast each branch to `int` at the assignment site. Declaring the virtual as `int` makes VC5 skip the shared conversion for that branch and changes the short jump over the float-member load.

Try this when one branch is `call [vtable+slot]; jmp shared_ftol` and the other is `fld [field]; shared_ftol:`. The key is that the virtual returns its value in the FPU stack, not in `eax`.

## Lesson: Duplicate branch calls can beat a selector temp for VC5 tail merging

When two branches call the same method with only one argument different, a clean selector temp such as `techID = cond ? a : b; obj->method(techID, this);` can be shorter but land in the wrong branch family. If original asm has each branch loading its own object/arguments and then jumping into a shared call setup, write the source as duplicated calls inside the `if`/`else`:
```cpp
if (cond) {
    world->effects->do_tech_effect((short)this->startTech, this);
} else {
    world->effects->do_tech_effect(0xD2, this);
}
```
VC5 may tail-merge the duplicate call setup exactly, preserving the original branch distances and per-arm reloads. Example: 00512690 `TRIBE_Player::scenario_load`.

## Lesson: Prefer CRT string/memory surfaces and avoid carried pointer liveness when original reloads late

For VC5 string-buffer initialization code, prefer CRT-recognized `memset`/`strcpy` surfaces over handwritten loops/helpers when original uses `rep stosd` and inline `repne scasb` / `rep movsd` / `rep movsb`. Also, in pointer/index loops over multiple parallel arrays, source liveness of the row/name pointer matters: using `array[i][0]` instead of a carried pointer can keep the pointer-slot reload/update at the original late location while preserving the array-index register schedule.

## Lesson: Visible virtual destructors can trigger the expected /GX constructor EH frame

When a constructor body already matches except it is missing the original VC5 EH registration prologue/epilogue, and the original was built with `/GX`, make the base/derived class surface include visible virtual destructors if the real classes are polymorphic/destructible. The destructor declarations can make VC5 treat the base constructor phase as needing unwind cleanup and emit the `push -1; push handler; fs:[0]` constructor frame without changing the natural constructor body.

Try when:
- a constructor with a base-constructor call is undersized by exactly the EH frame/tail;
- the body after the base call (vptr store, member initialization, repeated calls) already matches closely;
- `/GX` alone does not emit EH because the local class surface is too non-polymorphic/non-destructible.

Caveat: keep this to real constructor/destructor surfaces; do not add fake virtuals just to perturb ordinary functions. Verified on `0050F410 TRIBE_Map`.

## Lesson: Fixed-size zero fill may need `memset` to order `mov ecx; xor eax; lea edi; rep stosd`

For fixed small array clearing, a natural `for` loop can optimize to `lea edi,
[dst]` before loading the repeat count and zero register. An explicit `memset`
with a constant size can make VC5 emit the classic sequence `mov ecx,count; xor
eax,eax; lea edi,[dst]; rep stosd`, matching constructors that zero a fixed int
array in an else/default path.

## Lesson: Seed only the low byte of an `int` memset value to avoid zero/sign extension

For VC5 inline `memset` patterns that build a repeated byte in `EBX`/`EAX`, an ordinary `char` or `unsigned char` argument may cause `movsx` or `xor eax,eax; mov al,...` before the fill setup. If the original only does `mov al,[byte]` and then copies `al` into `bl/bh`, declare an `int fill;` and assign only its low byte before passing it to `memset`:

```cpp
int fill;
*(char*)&fill = this->fill_value;
memset(buf, fill, count);
```

This preserves the binary-observed low-byte load while letting the compiler form the repeated dword value naturally. Pair with operand-order probes for the `count` expression; VC5 may emit `height * width` source as a load-width / imul-height sequence.

## Lesson: `register`-qualified parameters can keep stack args in caller-saved registers

When VC5 insists on preserving an input parameter in ESI/EDI and this causes a whole-function register-family mismatch, try `register` on the parameter declaration/definition before rewriting the algorithm. In small read-only helper methods, `register int param` can make VC5 load the stack argument into EAX before saving callee-saved registers and keep it as the table index, matching originals that use EAX directly. Applying `register` to a dispatch parameter can similarly steer the switch/if chain into EDX rather than EAX.

Try when:
- original begins with `mov eax,[esp+4]; push esi; test eax,eax` but rebuilt starts `push esi; mov esi,[esp+8]`;
- table lookups differ only by `eax*scale` versus `esi*scale`;
- dispatch temp uses EDX in original but EAX in rebuilt.

Caveat: only use where source semantics do not require the parameter address; overuse can perturb other functions. Verified on a DiplomacyAIModule stance helper.

## Lesson: Correct aggregate size can unlock VC5 whole-struct copy addressing

When original VC5 copies a small aggregate by first forming source base pointers
(`lea reg,[base+off]`, `add base,next_off`) and then moving adjacent dwords, model
the aggregate at its exact binary size and use natural whole-struct assignment.
A too-large pseudo-struct can make VC5 abandon the base-pointer copy sequence and
fold every member load as fixed `[base+imm]` accesses.

Try when:
- a GUID/RECT/small parameter block copy is behaviorally right but lacks the original
  `lea`/`add` source pointer setup;
- generated type guesses have widened subfields (for example treating a 16-byte GUID
  as five dwords / 20 bytes).

Why it helps:
- exact aggregate size lets VC5 recognize a compact struct-copy pattern and schedule
  base pointer formation before the dword moves;
- wrong size/field layout forces independent member loads and changes both instruction
  count and register roles.

Caveat:
- do not pad standard binary aggregates just to name apparent decompiler fields; verify
  the actual adjacent offsets first. Verified on 00432200 TCommunications_Sessions.

## Lesson: Natural virtual float getters plus casted arguments can reproduce interleaved FPU/push forwarding

When a forwarding wrapper builds a long argument list from virtual float-returning methods and float fields, prefer declaring the real virtual slots and writing the final callee call naturally with casts in the desired left-to-right argument order. VC5 will evaluate arguments right-to-left, leaving virtual float returns on the FPU stack and emitting `push ecx; fstp [esp]` for float arguments, while `(int)float_field` arguments interleave as `fld field; call __ftol; push eax`.

Try when:
- original has virtual calls like `[vtable+0x100]`, `[+0x108]`, `[+0x10c]` followed by `fstp dword [esp]`;
- a fake helper or manual ftol stub produces too-short code or misses the FPU stack/push pattern;
- the wrapper simply forwards object fields, virtual float properties, and ftol-converted coordinates to another overload.

Caveat: vtable slot padding and the destination overload signature/order must be exact, since right-to-left argument evaluation determines the emitted push sequence.

## Lesson: Reuse an incoming parameter as a moving offset to preserve dual-index loops

When original VC5 mutates one incoming parameter into an address offset (for example `param = param*4 + 0x10; param += stride`) while a separate register tracks the loop byte offset, spell that mutation directly on the source parameter instead of introducing a clean `offset` local. Also consider repeating the base member expression inside the condition/store rather than caching a base pointer or loaded value; this can keep the original register roles (`edx` loop index, `esi` moving offset, `eax` base, `ecx` loaded value).

Try this when a near-match has the right loop but uses one register for both index/base arithmetic or inserts an extra `add base,index` before the store. Verified on an acknowledge-message scan that clears a per-destination slot.

## Lesson: Use real C++ `delete` syntax in destructors to preserve VC5 destructor EH cleanup

For virtual destructors that delete pointer members and then call a nontrivial base destructor under `/GX`, prefer natural `delete this->member; this->member = 0;` with the ordinary C++ `void operator delete(void*)` declaration. Declaring an `extern "C" operator_delete` helper or manually calling a delete-like function can compile to a shorter function or the wrong EH/local layout, while real `delete` lets VC5 emit the expected destructor EH frame, vptr restore, cleanup-state store, and base destructor call.

Try when:
- original destructor has an ESP-based EH prologue (`push -1; push handler; fs:[0]`) and a state slot before the base destructor;
- body diffs center around missing EH frame or wrong local allocation;
- member deletes are currently modeled as raw helper calls.

Caveat: this applies to actual C++ deletion of object/char buffers; keep the base destructor virtual/nontrivial surface accurate.

## Lesson: Out-parameter casts can intentionally target stack slots

When VC5 uses incoming parameter/local stack slots as callee out-parameters, exact
LEA displacements may depend more on the *casted argument expression* than local
declaration order. If a near-match only differs in `lea ..., [esp+XX]` addresses
for out-params, try passing the naturally typed local for the pointer output and
casting an adjacent narrow local for the short/count output instead of preserving
decompiler-inferred swapped casts. In 00513600 this changed only two LEA
displacements and produced a full match.

## Lesson: Keep FPU temporaries live and match constant precision independently

For compact VC5 FPU range-normalization helpers, an extra named float temporary can
force an `fstp`/`fld` bridge between adjacent comparisons even when behavior is the
same. If the original keeps `ST0` live through multiple `fcom`/loop checks, write the
source so one variable is updated in place instead of copying through a second `val`
local.

Also match constant precision at each use: the same mathematical constant may need a
`double` literal for `fmul`/upper-bound `fcom` (`qword` memory operand) but a `float`
literal for the subtract step (`dword` `fsub`). Example pattern from 00460EB0
`rotate`: compute with a double 2*pi expression, use in-place `rotation +=/-=`, and
use a double literal in both `>= 2*pi` comparisons while subtracting the float form.

## Lesson: Varargs push order and direct `this+offset` expressions can avoid saved base registers

For large `sprintf`/varargs calls, remember VC5 evaluates and pushes varargs
right-to-left. Reconstruct source argument order from the reverse push sequence and
the format string; do not swap established semantic arguments merely to match pushes.

When the original mutates `ECX` to a buffer base (`add ecx, 404h`) and indexes from
that, avoid a named base local if it makes VC5 save another register for the base.
Direct expressions like `(char*)this + offset`, combined with a `register` divisor
or loop scalar, can let VC5 keep the scalar in `ESI` and reuse adjusted `ECX` as the
base. Example: 00421FA0 `calc_timing_text` matched after reversing the varargs and
replacing a `base` local with direct `this+offset` accesses.

## Lesson: An explicit self stack argument signals a static/free cdecl helper

Functions like `AIModule::logCommonHistory` that take an `AIModule*` as the first explicit parameter and a format string are typically **static member functions or free __cdecl functions**, not thiscall member functions. The call signature `logCommonHistory(this, fmt, ...)` pushes `this` as the first stack argument, and the caller cleans up (`add esp, 14h` for 5 args). Declaring them as class member functions (`this->logCommonHistory(...)`) generates incorrect thiscall dispatch.

Instead, declare as a free function or `static` member:
```cpp
void logCommonHistory(AIModule* module, const char* fmt, ...);
```
and call as `logCommonHistory(this, fmt, arg1, arg2)`.

## Lesson: Use compare-threshold spelling to control unsigned byte branches

For unsigned byte state checks, equivalent predicates can encode differently. If the original tests `cmp byte [obj+off], 2` with `jbe`, prefer spelling `state <= 2` instead of `state < 3`; VC5 may otherwise emit `cmp ..., 3` / `jb`. Likewise, when an equality compare should use an immediate (`cmp byte [mem], 2`), a direct byte lvalue or cast can avoid materializing `2` in a register.

## Lesson: Shared `goto done` return can avoid eager callee-save pressure

When a loop setup has an early no-next/no-more path that returns the same value as the
normal loop exit, spelling that path as `goto done` to a shared return can keep VC5 from
saving extra callee-saved registers up front. A direct early `return count;` or more
structured loop may push the compiler into an eager EBX/EBP/EDI save basin even though
behavior is identical.

Try when:
- the original initializes a count/state before a first iterator call, then has a
no-next path joining the normal exit;
- rebuilt code is semantically correct but saves too many registers in the prologue or
materializes loop state too early.

Why it helps:
- a shared tail can shorten live ranges around the first iterator result and preserve
VC5's lazy register-save layout.

Caveat:
- use for genuinely shared exits only; do not force gotos when exits have distinct
cleanup/calls. Verified on 00449990.

## Lesson: Pre-call zero initialization plus named elapsed local can preserve signed time arithmetic

For elapsed-time formatting helpers, initialize output components such as hours and
minutes before the timestamp call, then compute a named signed `elapsed` local from the
post-call delta. This can preserve VC5's pre-call zeroing and the expected signed `/60`
quotient/remainder arithmetic.

Try when:
- original zeroes time component locals before a `timeGetTime`-style helper call;
- rebuilt code moves zeroing after the call or uses unsigned division/remainder shapes.

Why it helps:
- the source lifetime of the zeroed components crosses the call, while the named signed
`elapsed` local guides VC5 into signed division/subtract scheduling for minutes/seconds.

Caveat:
- keep the elapsed local typed as `int`/signed when the original uses signed divide;
unsigned casts can change division codegen. Verified on 004806D0.

## Lesson: Runtime `strlen` on extern strings can restore repne-scasb and save pressure

For string-prefix command parsers, do not replace known global string lengths with
hardcoded constants too early. Calling `strlen(extern_global_string)` as the length
argument to `_strnicmp` can emit VC5's original `repne scasb` length calculation and
create the expected callee-save/register pressure.

Try when:
- original computes string length inline before `_strnicmp` rather than pushing an
immediate length;
- hardcoded lengths produce a too-short body or too few saved registers.

Why it helps:
- the runtime length scan extends live ranges around the compare calls and can restore
the original multi-register save basin.

Caveat:
- only use when the original actually computes length at runtime; constants are still
right when asm pushes an immediate count. Verified on 00509490.

## Lesson: One local-frame struct can preserve VC5 stack layout for C API helper chains

For C functions that pass several adjacent local structs/buffers through helper calls,
separate local declarations may let VC5 shrink or reorder the frame. Model the whole
observed frame as one explicit local struct, including padding between subobjects, when
the original stack offsets are proven.

Try when:
- the rebuilt C function is a few bytes/frame slots too small despite correct helper calls;
- original stack offsets show adjacent API structs with a fixed gap or required alignment;
- helper arguments are addresses into those local subobjects.

Why it helps:
- the aggregate local forces VC5 to reserve the exact contiguous frame and preserves
subobject offsets for address-taking call arguments.

Caveat:
- keep the `.c` source surface for original C files and model only proven frame layout.
Verified on 004485C0.

## Lesson: Tiny constant-count loops can be the exact source for repeated zero stores in constructors

When a constructor clears a short fixed array and the original emits one zeroed register (for example `xor ecx,ecx`) followed by several same-register member stores, a literal sequence of `field[0] = 0; field[1] = 0; ...` may not match: VC5 can reuse an existing zero register such as `EDI` or keep `ECX` live as `this` for the next member call. Writing the source as a small constant-count loop, e.g. `for (int i = 0; i < 3; ++i) field[i] = 0;`, can collapse under /O2 into the desired repeated stores while also forcing the expected zero register and reload-before-call shape. Example: T_Scenario ctor (0052AAC0).

## Lesson: Group address-taken scratch locals with saved self to lock stack offsets

When several scratch accumulators are passed by address inside a loop and the original
also stores a saved `this` pointer adjacent to them, model those locals as one small
frame struct. This can force VC5's exact stack frame size and offsets while keeping the
loop source natural.

Try when:
- rebuilt logic is correct but address-taken locals land at different `[esp+N]` offsets;
- original has a compact local frame with accumulators and a saved object pointer;
- helper calls take pointers to the scratch values and the loop later reloads `this`.

Why it helps:
- the aggregate fixes relative local ordering and prevents VC5 from independently
reordering/scattering address-taken temps.

Caveat:
- only group locals whose adjacency/order is proven by stack offsets. Verified on
00422960.

## Lesson: Aggregate assignment can be the natural source for `rep movsd` header copies

When the original copies a fixed-size header from a buffer into an object with `rep movsd`, prefer modeling the header as a real aggregate and assigning it (`this->header = *(Header*)buffer`) before writing a manual word/dword loop or calling `memcpy`. In VC5 /O2 this can both emit the compact `rep movsd` sequence and change register pressure enough to recover the original saved-register coloring around file/read constructors. Manual loops may expand into explicit load/store loops, and `memcpy` may remain a call. Example: RGE_Flic_Player ctor (00449B30).

## Lesson: Redundant guard predicates can preserve two-step branch shapes

When the original tests one parameter with two adjacent branches such as `jz` followed
by `jl`, source that looks redundant (`x == 0 || x >= 0`) may be needed to keep both
checks. Simplifying to `x >= 0` can collapse the branch topology and shift constructor
or allocation setup.

Try when:
- original has a zero special-case branch immediately followed by a signed negative
check on the same value;
- the simplified predicate is semantically equivalent for the guarded body but emits only
one compare/branch.

Why it helps:
- VC5 preserves the explicit short-circuit tests, maintaining block layout and register
liveness before allocation/copy code.

Caveat:
- only keep redundant predicates when binary-observed and behavior-equivalent. Verified
on 0046A740.

## Lesson: Initialize FPU loop cursor before fallback count loads

For angle/facet loops, declaring and initializing the running float cursor before a
fallback that loads or computes the loop count can make VC5 emit the zero `fld` before
the count load/fild sequence. Initializing the cursor later may be behaviorally identical
but changes FPU stack order.

Try when:
- original loads `0.0` into the FPU stack before resolving a default count;
- rebuilt computes/loads the count first and only then initializes the float loop cursor.

Why it helps:
- the source lifetime of the cursor begins before the fallback path, guiding VC5's FPU
stack scheduling around subsequent division/loop setup.

Caveat:
- only move initialization earlier when the value is independent of the fallback and no
side effects are introduced. Verified on 004C6AA0.

## Lesson: Real base-constructor initializer can unlock `/GX` derived load constructors

For derived constructors that load fields from a file under `/GX`, declare the real base
constructor signature and call it in the initializer list. Manual base setup or fake
helpers may preserve behavior but miss VC5's EH state, vptr, and constructor-call basin.

Try when:
- original constructor starts with a base constructor call and EH/unwind state;
- derived body is mostly straightforward `rge_read` field loads but prologue/state/call
shape differs;
- the base constructor has an extra mode/flag argument visible in asm.

Why it helps:
- VC5 lowers initializer-list base construction with the correct object lifetime and EH
cleanup context before emitting derived field loads.

Caveat:
- keep base/derived layouts and constructor signature exact; wrong base size or missing
virtual destructor can change offsets and EH. Verified on 00404BB0.

## Lesson: Comma expression can preload one parameter while delaying its member store

When VC5 needs to load a parameter early for later switch/dispatch but the original
delays the corresponding member store until after an adjacent store, a comma expression
like `fieldA = a, fieldB = b` can produce the desired load/store scheduling.

Try when:
- original preloads a dispatch parameter before several byte/member stores;
- a direct sequence stores the dispatch field too early or reloads the parameter later;
- the assignment order is semantically independent.

Why it helps:
- VC5 may evaluate the left assignment's source into a register early while scheduling
the actual store around the right assignment, preserving later switch input liveness.

Caveat:
- use sparingly and only when the binary proves the delayed store/preload pattern.
Verified on 0047CD40.

## Lesson: Anchor packed cost loops on the paid-byte cursor and keep amount separate

For packed cost/resource arrays where each entry has type/amount/paid fields, anchor the
loop cursor at the observed paid byte and use negative offsets for type/amount. Keep the
amount as a separate `int` before loading the resource pointer when the original spills
the converted short before resource reloads.

Try when:
- original uses a pointer like `object+paid_offset` and indexes entries by a fixed byte
stride;
- type is loaded from `cursor-4`, amount from `cursor-2`, and paid from `cursor`;
- rebuilt direct struct fields choose a different base or reload resources too early.

Why it helps:
- the cursor base and separate amount local reproduce VC5's `movsx`/spill/resource-load
scheduling and preserve skip-flag liveness.

Caveat:
- use only for binary-proven packed layouts; natural structs may be clearer when they
produce the same base/offset code. Verified on 00513C50.

## Lesson: Preserve overloaded/default member-call arity from call-site pushes

When original assembly calls the same member helper sometimes with pushed arguments and sometimes with none, do not model it as one default-argument declaration if VC5 then pushes default zeros at no-arg call sites. Declare separate overloads (for example `get_player()` and `get_player(short,int)`) and match each call-site arity exactly. Also verify downstream helper arity: arguments pushed for one call may not belong to the following method even if the decompiler assigns them there.

## Lesson: Keep chained arithmetic/calls in one expression to preserve VC5 saved-register roles

When a result is built from several calls and arithmetic steps, splitting the computation into
multiple assignments (`r = call() % bound; r -= other()/2; r += base();`) can extend the result
local's lifetime enough for VC5 to put it in the wrong callee-saved register and move `this` to
another register. If the original keeps `this` in one saved register and uses a different saved
register only inside the success branch for the arithmetic result, try spelling the whole value as
one assignment expression:

```cpp
this->field = call_a() % obj->bound() - obj->bound() / 2 + obj->base();
```

Why it helps:
- VC5 can evaluate the chained expression with the branch-local result register chosen from the
  original basin, while keeping the owner/`this` pointer in its long-lived register.
- Semantically equivalent stepwise compound assignments may introduce a stable EBX/EDI swap across
  the prologue, arithmetic hunk, final store, and epilogues.

Caveat:
- Use only when the original call/arithmetic order matches the expression's evaluation order; keep
  separate statements if they are needed to force interleaving or side-effect order. Verified on
  004E6580 `setTributeChat`.

## Lesson: Explicit row/column while cursors can recover terrain-brush register roles

For clipped rectangle/brush loops, a natural `for` loop over adjusted bounds may still make VC5 preload parameters before saving registers or swap the row/column bound registers. After computing and clipping `x1/x2/y1/y2`, try assigning explicit cursor locals and using nested `while` loops:

```cpp
long row = y1;
while (row <= y2) {
    long col = x1;
    while (col <= x2) {
        this->set_terrain(world, col, row, terrain, 0, 0);
        ++col;
    }
    ++row;
}
```

Try when:
- the original keeps the owner in one saved register, uses separate saved registers for `x2`, `row`, and `col`, and reloads the inner cursor from the clipped start after each row;
- `for` headers or parameter-mutation source are behaviorally correct but cause early parameter preloads and EBX/EBP/ESI role swaps.

Why it helps:
- explicit cursors shorten the live ranges of the bounds and make VC5 materialize the inner cursor at the loop boundary, matching the original nested-loop schedule. Verified on `00457320` `do_terrain_brush`.

## Lesson: Destructible member subobjects control VC5 destructor EH state numbering

When a /GX destructor is behaviorally correct but EH state numbers are off and a cleanup block
looks like manual delete/zero code, the missing source fact may be that the cleaned-up fields are a
real member subobject with an inline destructor, not ordinary fields manually cleaned in the parent
destructor. Model the member type with its real fields and destructor, then let VC5 automatically
call it from the parent destructor.

Try when:
- rebuilt destructor has state sequence like `1 -> 0 -> -1` but original has `2 -> 1 -> 0 -> -1`;
- an omitted/redundant state store appears immediately before a delete/zero block;
- manual cleanup matches visible effects but the unwind topology differs.

Why it helps:
- each visible destructible member contributes to VC5's EH unwind-state numbering;
- an inline member destructor can emit the same delete/zero stores while giving the parent destructor
  the correct state transitions and automatic subobject cleanup ordering.

Caveat:
- preserve exact member size/offsets when replacing raw fields with a subobject. Verified on
  00408D50 `BuildAIModule::~BuildAIModule`.

## Lesson: Recompute fixed byte strides from the loop index to let VC5 strength-reduce into the original offset register

When a loop walks fixed-size records and a carried `offset += STRIDE` local gives the wrong register basin, try computing the offset from the loop index inside the body:

```cpp
for (int i = 0; i < this->count; ++i) {
    int offset = i * STRIDE;
    use(base + offset);
}
```

VC5 can strength-reduce the multiplication back into a running byte-offset register, but the source shape may preserve a separate loop counter and narrow pre-loop count tests that a manually carried offset local perturbs.

Try when:
- the original has both a loop counter and a byte-offset induction variable;
- a manual `offset += STRIDE` source swaps registers or changes the pre-loop count load/test;
- the loop bound is reloaded from a member at the bottom.

Caveat: this is for fixed-stride record loops where the binary already proves the stride; direct multiplication may generate worse code if VC5 cannot strength-reduce it.

## Lesson: Mutate source string parameters and keep nested vararg expressions inline for debug logging helpers

For compact debug logging wrappers that copy a slice of a filename into a small stack buffer and then call `sprintf`, mutating the incoming string parameter in place can recover VC5's exact pointer/end loop:

```cpp
param_1 += 10;
char* d = buf;
char* end = param_1 + 8;
char c = *param_1;
while (c != '.' && param_1 < end) {
    *d = c;
    c = param_1[1];
    ++d;
    ++param_1;
}
```

This can emit the desired `add eax,0Ah`, `lea end,[eax+8]`, copy current byte, preload next byte, increment both pointers loop shape. Separately, avoid naming nested globals like `game` or `world_time` before a vararg `sprintf` if the original evaluates stack arguments first. Keeping the nested expression inline in the argument list can preserve right-to-left vararg scheduling:

```cpp
sprintf(log + idx * 100, fmt,
        (*(Game**)&rge_base_game)->world->world_time,
        buf, line, seed);
```

Try when:
- a filename-slice copy loop is close but uses index/delta arithmetic instead of a moving source pointer plus end pointer;
- `sprintf` call setup loads global owner/world pointers too early before pushing later varargs.

Why it helps:
- mutating the parameter gives VC5 the same source pointer lifetime as the original;
- inline nested expressions let VC5 evaluate varargs right-to-left without long-lived locals that force early global loads.

Caveat:
- use only when the original parameter value is dead after the copy or only needed through another saved argument/register. Verified on 00423140 `debug_srand`.

## Lesson: Replace aggregate assignment with explicit narrow-field copies when padding matters

For small structs whose logical fields do not fill the full stride (for example three dwords plus a trailing byte in a 16-byte slot), C++ aggregate assignment may copy the trailing padding as a full dword and push VC5 into a different saved-register/stack-home basin. Spelling each field explicitly, especially copying the final byte member as a byte, can recover the original narrow `mov dl`/`mov [dst],dl` shape and avoid extra saved registers.

Try when:
- original copies several dwords and then a byte from each element;
- rebuilt aggregate assignment copies the last slot as a dword or introduces a stack temp;
- the loop stride is larger than the sum of meaningful fields.

Caveat: only omit padding copies when the original really omits them; if padding is semantically initialized elsewhere, aggregate assignment may still be the right source.

## Lesson: Inline repeated row-address expressions to avoid base-pointer liveness

When iterating fixed-size table rows, naming a row pointer local can make VC5 preserve the table base in an extra register and synthesize `mov base; mov index; add`, which can shift the whole loop and even lengthen an earlier short branch to near form. If the original reloads the table member and adds the offset directly for each access (`mov eax,[this+table]; add eax,offset`), try repeating the full `(char*)this->table + offset` expression in the byte test and ID/load sites instead of introducing an `entry`/`row` local. This can reduce register pressure and recover the original short-branch layout.

## Lesson: Model relation/flag arrays as pointer fields to preserve pointer-load-plus-cmp

When original VC5 loads a member pointer to a byte table and then compares through it (`mov eax,[obj+84h]; cmp byte [eax+idx],0`), raw byte-offset expressions like `(char*)obj + 0x84 + idx` can compile to a shorter direct object-relative load/test (`mov al,[obj+idx+84h]; test al,al`). Declare the member as the real `unsigned char*` table and index it naturally (`obj->table[idx]`) so VC5 emits the separate pointer load and memory compare.

Try when:
- a near-match is exactly a couple bytes short in a loop over diplomacy/relation/flag arrays;
- rebuilt uses `mov/test` from `[object+index+offset]` but original uses `mov table_ptr; cmp [table_ptr+index],0`;
- the offset is known to hold a pointer, not an inline byte array.

Why it helps:
- the typed pointer field preserves the extra indirection and lets VC5 keep surrounding registers/block layout intact, instead of folding the access as an inline array. Verified on `00532880` `handle_victory_points`.

## Lesson: Volatile raw guard read can prevent count reuse and recover delayed callee-save prologues

When an early capacity guard should compile as a direct memory compare and return before any heavy locals/register saves, but VC5 preloads the count into a register for later reuse and eagerly saves EBX/EBP/EDI, make only the guard read volatile through the proven raw offset:

```cpp
if (*(volatile int*)((char*)this + COUNT_OFF) >= LIMIT) return 0;
int count = this->count;  // normal non-volatile reload for the body
```

Try when:
- the original has `push esi; mov esi,ecx; cmp [esi+off],imm; jl body; xor eax; pop esi; ret`;
- the rebuilt loads the count into a register before the compare and shifts the body by a couple bytes, or saves all callee-saves at entry;
- the later body legitimately needs a normal count local.

Why it helps:
- the volatile raw guard blocks CSE/reuse between the early guard and the body count local;
- VC5 then emits the guard as a standalone memory compare and can delay heavier callee-save pushes until after the guard succeeds.

Caveat:
- keep volatility limited to the guard. Making the body count or whole object volatile can force a wrong stack-home/register family. Verified on `004C7920` `addToGroup`.

## Lesson: Prefer natural constant division over hand-written magic multiplies

When original VC5 code contains a magic multiply/shift sequence for division by a constant (for example `mul 0xD1B71759; shr edx,0x0D` for unsigned `/ 10000` after a 32-bit product), write the source as the ordinary `/ constant` expression first. Hand-writing the `__int64` multiply/shift can force helper calls, save `this` in an extra register, and perturb the entire function even if the math is equivalent. Natural division lets VC5 choose its built-in strength reduction and often preserves register allocation.

## Lesson: Duplicate tiny helper tails with per-case returns to shape switch layout

For VC5 switch functions that copy or return a string per case, a single shared post-switch tail can collapse the layout differently from the original. If the binary has duplicated helper tails and only some paths fall through, try spelling each named case as `helper(...); return;` and leave only the default (or exceptional path) to fall through. This can recover sparse byte-table dispatch layout, branch polarity for pre-switch guards, and the original duplicated inline `strcpy`/REP-copy tails.

## Lesson: Natural `memset` plus guarded `do/while` can recover constructor fill and row-pointer setup

When a constructor allocates a flat byte buffer and fills it with one repeated byte, try the natural CRT `memset(buffer, fill, total)` with `<string.h>` before hand-writing dword/byte fill loops. VC5 can inline `memset` into the exact `and fill,0xff; bl/bh byte replication; rep stosd; rep stosb` sequence without extra callee-saves or guard branches.

For the following row-pointer table setup, a source `for` loop may keep the byte offset and row index in the opposite registers. If the original uses `EAX` as the row index and `ECX` as the accumulated byte offset (`row[i] = value + offset; inc i; offset += xSize; cmp i,ySize`), spell the loop as an explicit guarded `do/while` with `i++` before `offset += xSize`:

```cpp
int i = 0;
int offset = 0;
if (i < this->ySize) {
    do {
        this->row[i] = this->value + offset;
        i++;
        offset += this->xSize;
    } while (i < this->ySize);
}
```

Try when:
- manual fill loops introduce EBP or guarded rep loops but the original has a compact inline memset basin;
- the row setup is behaviorally correct but `i` and `offset` are swapped between EAX/ECX.

Why it helps:
- VC5's recognized `memset` intrinsic supplies the original byte-replication and REP-string code;
- the guarded `do/while` with source increment order steers VC5's induction-variable coloring and bottom compare to the original pattern.

Caveat:
- include `<string.h>` so VC5 recognizes the intrinsic; an external/custom memset declaration may compile as a call or a too-short helper sequence.

## Lesson: Infer virtual wrapper argument ownership from right-to-left pushes, not decompiler labels

For command/wrapper methods that make several virtual calls, verify which source parameter feeds each call by the actual stack offsets after saved-register pushes. A decompiler may label nearby pushed values as the wrong formal. Once the callee signature is modeled with the full observed arity, source argument order controls VC5's right-to-left push sequence exactly:

```cpp
// To emit ... push param5; push param4; push cmd ...
obj->send_signal(id, p1, cmd, param4, param5, ...);
```

Try when:
- a near-match differs only by adjacent `push reg` order late in a virtual call;
- one parameter is saved in a callee-saved register and another is reloaded from the stack;
- a preceding helper call uses a different parameter than the decompiler suggests.

Why it helps:
- correcting the visible virtual prototype/arity avoids missing pushes and wrong object size;
- swapping the source argument order for the semantically correct callee signature restores the original right-to-left push order without lower-level casts.

Caveat:
- only swap after confirming the callee's real parameter order from callers/vtable semantics; otherwise this can hide a wrong prototype.

## Lesson: C helper arity and stack-slot reuse can unlock MMIO chunk walkers

For old C helpers around WinMM/MMIO APIs, infer the true parameter list from stack-slot
loads, not from the decompiler prototype. A load like `[esp+20h]` inside a callee-saved
block may be a fourth pointer parameter even when the decompiler collapses the two handles
to one. Also, VC5 may reuse an incoming parameter home as a `result = 0` stack slot before
a function-pointer call; keeping a named `int result` local can reproduce the store.

Try when:
- an MMIO/RIFF walker is close but a copied chunk call pushes the same handle twice;
- original reloads a later stack argument for one source/destination handle;
- a zero result store appears between argument pushes and an indirect API call.

Why it helps:
- the extra formal preserves the exact `[esp+disp]` reload and push order;
- the stack result local gives VC5 the same home-slot store and later reload without inline asm.

Caveat:
- match compare operand order too (`childEnd > parentEnd`) because equivalent reversed
  bounds tests can leave only a tiny `cmp`/branch opcode drift. Verified on `00448340`.

## Lesson: Separate the current method from a same-object fallback virtual slot

When a method body ends by dispatching through this object's vtable at a high offset, do not assume the source should call the same named method recursively. The current function can be declared as the concrete non-virtual method being matched, while a separate padded virtual declaration represents the fallback/default slot:

```cpp
class Owner {
public:
    // pad to observed slot
    virtual int default_handle(unsigned int command, long param);
    int handle(unsigned int command, long param);
};

int Owner::handle(unsigned int command, long param) {
    ...
    return this->default_handle(command, param) != 0;
}
```

Try when:
- the original uses `mov eax,[this]; ...; call [eax+slot]` near the tail of the method being matched;
- a qualified base call would emit a direct call, but the binary clearly uses virtual dispatch;
- the vtable slot is not necessarily the current function's own slot.

Why it helps:
- the local class surface can preserve the real object vptr and data offsets while giving VC5 a natural thiscall virtual dispatch at the observed slot;
- the current function definition remains a normal member, avoiding accidental self-recursion or wrong vtable layout assumptions. Verified on `004212E0`.

## Lesson: Use protocol wire-size constants when local structs may be padded

For C API/file-format helpers, a visible local struct can have VC5 alignment padding that is
not part of the on-disk/API wire size. If the original computes a variable write size as a
field plus a literal (for example `cbSize + 0x12` for `WAVEFORMATEX`), do not use
`sizeof(local_struct) + field` unless the emitted add immediate proves it.

Try when:
- a near-match differs only by `add reg, 14h` vs `add reg, 12h` or a similar size literal;
- the source struct mixes DWORDs and WORDs and VC5 rounds `sizeof` up;
- the binary is writing a packed file/API record rather than copying the C object layout.

Why it helps:
- spelling the protocol constant preserves the original immediate and downstream compare;
- it avoids inventing a packed pragma or changing field offsets just to make `sizeof` work.

Caveat:
- use the literal only when the format/API size is binary-proven. Verified on `00448080`
  `_WaveCreateFile`, where non-PCM WAVEFORMATEX writes used `18 + cbSize` while the
  visible C struct rounded to 20 bytes.

## Lesson: Normalize cross-member cursors into canonical arrays and indexed loops

When a loop has correct raw offsets but remains stuck in pointer-induction,
constant-hoisting, or register-allocation drift, reconstruct the canonical owning
arrays/fields and try the natural indexed loop the original developer likely
wrote. Decompiler-style cursors that walk across neighboring members can hide an
off-by-one and also push VC5 into the wrong IR basin.

Try when:
- one running pointer addresses several binary-proven arrays through large
  positive and negative subscripts;
- the loop index naturally selects the same element from each array;
- emitted memory offsets are nearly aligned but induction updates or immediates
  differ.

Why it helps:
- named arrays expose common-index relationships to VC5;
- natural `array[i]` expressions can recover the original induction scheduling,
  immediate stores, and register allocation;
- explicit field ownership makes displacement errors visible during review.

Verify every offset and array extent first; readable source is not permission to
approximate layout. This normalization recovered full byte equality after a
pointer-cursor reconstruction had appeared codegen-stalled.

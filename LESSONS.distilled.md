# LESSONS.md (distilled draft)

This is a proposed compact replacement for the current `LESSONS.md`. It merges repeated
entries by theme and removes per-function diary material. Keep detailed attempts in the
scratch/accepted-drift source file; add only generalized, reusable lessons here.

Core rule: the original EXE is the behavioral oracle. PDB/type dumps, Ghidra names, and
similar metadata are reference material. Exact promotion still requires positional byte
match via `tools/check_function.py`.

Relocation bytes are masked during comparison, so relocated call/address immediates do not
need to match literally. The opcode and addressing mode still must match: direct `call rel32`,
indirect `call [IAT]`, `call reg`, relocated `mov reg,[0]`, and literal `mov reg,[ADDR]`
are distinct source-shape facts.

## 1. First instincts: source shape and context

### Prefer natural high-level source before decompiler scaffolding

Try the source a VC5-era programmer likely wrote before raw casts, fake helpers, or manual
allocation plumbing. Natural member calls, constructors/destructors, `new`/`delete`, CRT
string helpers, aggregate assignment, and direct member indexing often land in a better VC5
basin than hand-expanded equivalents.

Use lower-level spellings only when the assembly proves a particular aliasing/addressing
shape or when the natural form is already understood and misses locally.

### Translation-unit context is a real matching axis

Small header/TU details can affect VC5 codegen: visible special members, helper declarations,
`<stdlib.h>`/`<string.h>`, C vs C++ compilation, `/GX`, and even nearby inline definitions.
Prefer the likely donor-file context, then reduce it to the smallest proven surface.

- If PDB source is `.c`, use a `.c` scratch file; compiling as C++ changes naming and call
  surfaces.
- Clear stale `config/flags/<slug>.rsp` files before chasing source ghosts.
- Use `/GX` only when the original has EH/SEH registration, unwind state slots, constructor
  cleanup tracking, or sibling evidence.
- In isolated constructor TUs, keep virtuals/special members declared but not defined before
  the target; avoid helper bodies before the target COMDAT. The in-charge constructor often
  must be the first emitted `.text` section, or the checker may extract the wrong bytes.

## 2. Layout, object, and vtable surface

### Exact layout beats plausible layout

Model proven offsets, sizes, vptrs, base boundaries, field widths, and `sizeof` immediately.
Wrong layout creates false codegen drift.

- Virtual classes have an implicit vptr at `+0x00`; first data member is at `+0x04`.
  Do not double-count it with an explicit `gap_00[4]` unless the binary proves a separate
  data word.
- First gap arrays in virtual classes must be sized from `+0x04`, not `+0x00`.
- Split gap arrays to place proven fields at exact offsets, including fields hidden inside
  generated gaps.
- Incomplete/empty class stubs silently change `sizeof(T)`; add a local size pad when only
  the size is proven.
- Do not embed opaque empty C++ member objects in owner structs unless their real size is known;
  an empty member still consumes one byte and can shift later fixed offsets. Use byte-backed
  owner storage plus casts to subobjects at observed offsets until sizes are proven.
- For derived classes, preserve real base-vs-derived ownership when it affects vptr stores,
  EH state, base ctor/dtor lowering, offsets, or `sizeof`.
- Do not invent helper subobjects or wrappers when the assembly indexes a subfield directly
  inside an array element; model the observed element size and field offset.
- If gap-only stubs have correct accessed offsets but a stable register-coloring mismatch
  remains, try the fuller donor class/inheritance surface from a matched sibling. VC5 can
  change allocation/liveness from visible type context even for untouched fields.
- If the binary treats the first word as an ordinary stored/restored vtable pointer and the
  offsets already include it, model a non-virtual data struct with explicit `void* vtable_ptr`;
  use a separate dispatch-only virtual helper for calls if needed.
- If original direct base calls pass unchanged `ECX` and there is no binary evidence for base
  vptr/data, keep the local base stub minimal/non-virtual. Adding a guessed base vptr can
  introduce `this` adjustment and shift derived offsets. Diagnostic: `Base::method` rebuilding as
  `lea ecx,[this+4]` while original uses unchanged `this` means the local base/derived vptr
  ownership is wrong.

Stable concrete layout facts should ideally move to shared headers. Until then, keep them
compact: e.g. `TPanel::clip_to_parent` is a 4-byte `int` at `+0xF0`, and TTextPanel short
fields at `+0xF8/+0xFA/+0xFC` require the `+0xF4..+0xF7` gap after `TPanel`.

### Vtable slots must match exactly

For `call [vtable+offset]`, declare enough virtuals so the target method lands at
`offset / 4`. Padding virtuals, pure virtuals, or `__declspec(novtable)` interface stubs are
preferable to raw function-pointer casts when the original is a C++ virtual call.

- VC5 does not support usable `__thiscall` function-pointer syntax; it errors or perturbs
  calls. Use real member declarations or virtual declarations instead.
- Direct thiscall call (`mov ecx,this; call target`): declare a non-virtual member and call it
  normally. Relocation masking handles the direct call target.
- Virtual thiscall call (`mov ecx,this; call [vptr+slot]`): declare/pad the virtual slot and
  call it normally.
- Runtime-loaded thiscall slot (`mov reg,[vptr+slot]; mov ecx,obj; call reg`): copy the raw
  slot into a member-function-pointer local and invoke `(obj->*m)(...)`; plain cdecl/stdcall
  function pointers add wrong cleanup/register setup.
- COM-style calls (`push self; mov reg,[self]; call [reg+slot]`) are `__stdcall`, not C++
  thiscall. Model them as a vtbl struct of `__stdcall` function pointers or virtual methods
  declared `__stdcall`.
- Mixed calling-convention vtables can use a flat `__declspec(novtable)` interface with
  padding virtuals and per-slot calling conventions.
- If a fallback/base virtual call uses `[vtable]` instead of `[vtable+observed]`, the base
  vtable stub is under-padded.
- If `delete p` calls `[vtable]` but original calls `[vtable+4]`, model any preceding virtual
  slot before the destructor.

Use a dispatch-only helper class when field layout would otherwise shift: cast the object to a
small padded-virtual interface for the virtual call, and use the real data struct for fields.

### Member-call surfaces and arity matter

Model same-class/direct helpers as member functions, not free helpers or raw address casts, when
original passes `this` in `ECX`. Conversely, helpers that push `this` as an explicit stack
argument and clean up with `add esp,N` are static/free `__cdecl`, not thiscall members.

Declare overloads when the original calls the same logical helper with different argument counts;
default-argument-looking wrappers can add wrong pushes at no-arg call sites. Check right-to-left
push order before deciding which call owns a pushed constant; in nested-call arguments, VC5 may
push an outer-call argument before evaluating an inner member call. Split chained expressions when
needed to preserve call boundaries. In chained calls, one pushed argument may also be deliberately
reused across calls with different cleanup, which is an arity clue and sometimes a source-level
barrier.

Callee parameter widths affect call-site codegen. Widen visible callee parameters to `int` or
`unsigned int` when the original sign/zero-extends byte/short fields before pushing them; keep
stored field widths unchanged.

## 3. Constructors, destructors, `/GX`, `new`, and `delete`

### Use constructor-shaped `new T(args...)` for EH allocation frames

When original code has `FS:[0]` EH registration, try-state stores, and `operator new` followed
by a constructor, write a real `new T(args...)` expression under `/GX`. Manual
`operator_new` + init/constructor calls often omits or reshapes the EH frame.

Requirements:
- visible constructor declaration with the real signature;
- exact `sizeof(T)` (local size pad is fine when only size is known);
- correct virtual/base surface if the allocated object is polymorphic;
- `/GX` only when EH is binary-observed.

A plain `new Base` may omit a post-constructor derived vptr store that original emits after a
base constructor; model a small derived class when the binary proves that store.

After `this->ptr = operator new(...)`, if original reloads `[this+ptr]` before each store into
the allocated block, do not keep the allocation result in one local pointer. Spell later stores
through `this->ptr[...]` so VC5 reloads the member and cycles registers as observed.

### Base constructors belong in initializer lists

For derived constructors, use `Derived::Derived(...) : Base(args...), member(...) { ... }` when
original has base-constructor lifetime/EH behavior. A fake helper or `Base::Base()` in the body
constructs the wrong object (or a temporary) and changes frame/state/vptr scheduling.

Initializer-list vs body assignment is also a scheduling axis: initializer-list fields can place
the derived vptr store after those initializers; body assignments can let VC5 batch scalar stores
by value. Match the binary-observed vptr/store order.

### Visible destructors/subobjects drive EH state

For `/GX` constructors and destructors, visible virtual/nontrivial destructors on bases and
member subobjects can be required for EH registration and state-store emission. A byte blob with
only a constructor declaration may call the right address but miss the `state = N` stores before
subobject construction. For nontrivial stack locals under `/GX`, the source declaration point is
the construction point even if storage is reserved earlier; move the declaration down to the
binary-observed constructor/state-store point instead of hoisting all locals.

In destructors, prefer natural destructor declarations and natural `delete`/member cleanup so VC5
emits vptr restore, member destructors, EH states, and the base destructor. Manual vptr stores or
manual member-dtor calls can duplicate compiler-generated cleanup or schedule stores too late.

Exceptions:
- If original directly calls `~T()` then `operator delete`, declare a non-virtual destructor and
  spell `p->~T(); operator delete(p);` rather than `delete p`.
- If original shows a plain direct cleanup call and no destructor/EH state, do not force `~T()`
  syntax just because the callee name looks destructor-like; a normal cleanup member may be closer.
- If original truly has a double base-dtor tail, an explicit `this->Base::~Base()` inside the
  derived destructor plus the compiler's automatic base dtor can match it.
- If natural inheritance gives the correct destructor/EH basin but vtordisp shifts one proven
  field, keep the inheritance and access only that field through a byte offset.
- For destructor/delete blocks, an explicit pointer temp can force the original EDI/EBX carry
  through destructor plus `operator delete`; for vector-deleting helpers, use a shared delete
  pointer and common epilogue when original saves registers unconditionally.

### Delayed vptr stores

When original writes the derived vptr in the middle of a constructor, `__declspec(novtable)` on
that derived class plus an explicit `*(void**)this = vtbl;` at the observed source point can
control the write. Do this narrowly; natural constructor/destructor vptr handling is usually
better.

## 4. Imports, globals, CRT declarations, and fixed addresses

### Match the import-call opcode, not just the target

For Win32/API IAT calls, inspect the original opcode.

- `call dword [IAT]` can be emitted by `__declspec(dllimport)` API declarations or by an
  `extern "C" ret (__stdcall* const Func)(...)` pointer surface.
- A plain `extern` function declaration may emit a direct `call rel32`; relocation masking hides
  target bytes but not the opcode.
- If one switch arm calls an import once and another reuses it several times, cache an IAT
  function-pointer local only in the multi-call arm to reproduce `call [IAT]` vs `call reg`.

### Use absolute-address macros only when bytes must embed the address

For original `mov reg,[ADDR]` with the literal address bytes, use a macro/cast such as:

```cpp
#define rge_base_game (*(RGE_Base_Game**)0x62C574)
```

An `extern` global creates a relocation that compare tooling masks to zero (`mov reg,[0]`).
Use `extern const` for original tables when relocation-masked table loads are intended; do not
hide unknown data behind externs.

Hardcoded string/float addresses are valid only when the original genuinely embeds that address.
For string copies, `strcpy(dst, (const char*)ADDR)` can expose VC5's inline REP-string idiom.
For FPU constants, match both address style and float/double precision.

For fixed-address table iteration, avoid source that makes VC5 constant-fold every access into
separate absolute addresses when the original carries a running base. Use a mutable integer or
`char*` byte base for load+LEA/indexed sequences; use `extern const` tables plus inline indexed
lookups when the original uses relocation-masked table loads and preserving `CL`/shift liveness
matters.

### Header-provided declarations can change codegen

Do not replace CRT headers with hand declarations too early. `<string.h>`/`<stdlib.h>` can enable
VC5's inline `strcmp`/`strcpy`/`memset`/`memcpy` patterns or the expected EH constructor basin.
Conversely, a plain C++ declaration (not `extern "C"`) may be needed under `/GX` so VC5 treats a
post-base-constructor helper call as potentially throwing and emits base-unwind state.

MBCS helpers exist in VC5 CRT (`_mbsinc`, `_mbsninc`, `_mbsncpy`). Split `_mbsinc` into a separate
statement when the original calls it before pushing `_mbsncpy` arguments.

## 5. Locals, liveness, and register allocation

### Declaration order and scope are codegen knobs

Named locals are not neutral. VC5's register choice, initialization order, and callee-save pushes
can depend on declaration order and block scope.

Use this when a near-match differs by register color or a two-instruction scheduling swap:
- swap declarations of same-width locals to change `edx/ecx`, `esi/edi`, or prologue init order;
- declare an index/cursor before a setup call to move zeroing/LEA before the call;
- block-scope loop locals to delay callee-save pushes until after guards;
- hoist pointer/cursor locals before a guard when original emits `lea` between `cmp` and branch;
- name `i + 1`, a byte count, or a parameter copy when original keeps that value in a specific
  register across allocation/copy code;
- group address-taken locals in a local struct when exact stack offsets matter.

Call setup can also depend on small locals: a named byte-count temp can let VC5 schedule an
independent store between `push` and `call`; preloading sibling struct fields before a flag dispatch
can recover the original pre-branch load cluster; shared result locals across two arms can force the
callee-save basin, while duplicated calls can be better when original pushes branch-local literals.
If original saves `this` across a call and only then reloads a member for comparison, extract the
call result into a local first; a direct `call() != this->field` expression may preload the field
instead of preserving `this` in ESI/EDI.

If a local causes broad drift, remove it and access members directly. VC5 often lazily reloads
direct member expressions in the original, while clean locals pre-load and lengthen liveness.

### Cache only values the original carries

Do not cache scenario/player/object/target pointers when original reloads them before each call or
loop iteration. Direct member chains can be the exact source. Conversely, if original carries a
pointer through destructor/delete or a two-call sequence, a local can force the expected EDI/EBX save.
Avoid naming reusable numeric locals (`bytes`, `divisor`, `sep`, allocation sizes) when original
uses transient reloads or delays saving `EAX` until a call; recomputing the expression at each use
can preserve the original register family.

A local `this` alias (`Class* th = this;`) can flip saved-register roles for `this` vs a loop
counter when everything else is exact. Use only for stable ESI/EDI color swaps.

When original reloads a pointer/byte or keeps a redundant test that VC5 optimizes away, use narrow
anti-CSE surfaces before declaring drift: access the member directly inside the condition instead
of through a local, read through `*(void**)((char*)p + off)`, or use a volatile read only on the
observed pre-loop/field access. A volatile pointer local can also force one dependent owner/object
load before a byte reload. Do not make the whole loop volatile unless the asm proves it.

When original loads a pointer slot as two steps (`lea slot_addr; mov ptr,[slot_addr]`), a C++
reference to the slot (`T*& r = table[i]`) can force VC5 to keep both the address and loaded
value live. This can restore saved-register choices, but may also change SIB/base encoding.

### Parameter stack slots are usable source variables

Writes to incoming parameter slots are often real VC5 shape, not decompiler noise.

Patterns:
- mutate a parameter into a clipped bound, row/column remainder, moving byte offset, or loop start;
- save the original value in a local, then pass `&param` or `(short*)&param`/`(unsigned char*)&param`
  as a helper output;
- later reload the stack slot at the observed width, e.g. `*(short*)&param` for `movsx` from a word;
- use the saved local for durable full-width uses.

This avoids introducing clean locals that perturb saved-register allocation and stack offsets.

### Store scheduling tricks

When only store order/register reuse differs, try small source-shape changes before flags:

- Duplicate the same assignment in both `if` arms when original emits `cmp; independent store; branch`.
- Reorder unrelated stores to prevent VC5 from reusing `AL/EAX` for both a constant store and return.
- Use a comma expression only when the binary proves a store must happen before a later read/compare.
- Spell adjacent field assignments in observed order; VC5 often preserves order for mixed byte/word
  stores but may reorder independent nonvolatile stores near calls. Sometimes writing adjacent stores
  in reversed source order lets VC5 reschedule them into the observed order without volatile.
- A comma expression can preload a parameter while delaying the actual member store; use this only
  for binary-proven preload/store-delay patterns.
- Use volatile narrowly on the specific store/read whose order is binary-observed; broad volatile often
  adds spills.
- For repeated zero stores, natural `= 0` often makes VC5 hoist one `xor reg,reg`; for small fixed
  arrays, a constant-count loop can unroll into the desired repeated stores.

## 6. Loop and scan shapes

### Loop form is not interchangeable

`for`, `while`, `do`, `while(1)`, `break`, `continue`, and `goto` can produce different VC5 block
layout even with identical behavior.

Common patterns:
- A plain `for (i = 0; i < count; ++i)` often owns the empty-loop guard; remove an explicit
  `if (count <= 0)` when it causes duplicate `test/jle`.
- Hoist `int i = 0;` out of a `for` header when original zeroes the index before setup/calls.
- Direct indexed member-array loops can beat pointer walks when original keeps one index and fixed
  offsets; pointer walks can add hoisted setup or duplicate guards.
- Conversely, true pointer-walk originals may need one running pointer plus a saved boundary/start.
- `while (ptr != 0)` with the pointer advance as the last statement lets VC5 rotate linked-list
  loops to a bottom null backedge.
- For sentinel lists, `while (node != sentinel) { if (!node) break/return; ...; node=node->next; }`
  often preserves a bottom sentinel compare without an extra bottom null test.
- A separate `next` local can force the original two-register linked-list advance pattern.
- Computing `p = base + i * stride` inside a `for (i=0; i<count; ++i)` body can keep the first
  pointer LEA after the count guard while VC5 still strength-reduces the loop.
- `while (count-- != 0)` can avoid allocation-result null checks that a `do/while` form inserts.
- Refreshing a named `count = obj->count()` at the loop bottom can avoid peeling while preserving
  bottom call/test topology.
- For shift-left copies, `value[i] = value[i + 1]; ++i;` can be shorter than `++i; value[i-1] = value[i]`.

### Recovering compact bottom `jl` backedges

For tiny counted scans where VC5 emits `jge exit; jmp loop` but original uses direct
`cmp i,count; jl loop`, use a positive outer guard plus infinite loop bottom:

```cpp
if (count > 0) {
    while (1) {
        if (match) break;      // or goto found
        ++i; ++ptr;
        if (i < count) continue;
        return 0;              // or break to a not-found test
    }
    return 1;                  // or trailing found label
}
return 0;
```

This also helps keep distinct early-empty, loop-fail, and success tails. Use only when assembly
proves those separate tails; natural `for` remains the first probe.

### Avoid loop peeling when the original is unpeeled

If rebuilt preloads/peels element 0 but original compares memory at the loop label, try:
- `while (i < limit)` instead of guarded `do/while`;
- direct indexed access instead of a carried pointer;
- combined conditions like `while (i < old_count && i < new_count)` for copy/resize loops;
- spelling one-element copy as a positive `if (i < limit) { ++i; copy i-1; } else break;`.

### Loop width and signedness

Counter type and use-site casts drive branch opcodes and extension code:
- `unsigned int` tends to produce `jbe/ja`; `int` tends to produce `jle/jg` and may preserve
  otherwise-dead mixed-sign entry guards.
- Keep a loop counter as `int` when original passes/increments it full-width, but cast index or
  condition uses to `short` when original uses `movsx` or `cmp di,[count]` at those sites.
- Use signed `short` fields when original reloads loop bounds with `movsx`; unsigned fields produce
  zero-extension.
- Use `signed char`/`unsigned char` casts to force `movsx`/`movzx` and 8-bit masks.
- `register` on a read-only stack parameter can keep it in a caller-saved register when VC5 otherwise
  preserves it in ESI/EDI.

## 7. Branch layout, switches, and shared tails

### Switches and if-chains produce different physical layouts

If original compares a value and uses `je` to handlers placed after the main epilogue, try a real
`switch` before forcing gotos. VC5 switches can emit case bodies out of source order, jump tables,
subtract/dec cascades, sparse signed binary-search trees, or classification tables.

Switch tips:
- In tiny byte-state switches with one shared post-switch store, function-scope uninitialized locals
  for the pointer and byte temp can force `edx`/`cl` register roles and preserve the shared tail.
- Include `default:` when original's range/bounds check jumps to default behavior; omitting it can
  change the `ja` target.
- Reorder source case blocks to match original physical body order when jump-table target distances
  are off.
- Sparse HRESULT/error-code maps are often natural `switch (long)`; cast high-bit constants to signed
  `long`.
- For tiny case mutations that original places after a shared check, explicit `goto` case labels after
  the shared body can force out-of-line case blocks.
- For adjacent raw byte cases lowered as `sub; je; dec; jne`, switch on the raw byte values rather than
  a pre-adjusted temporary.

### Guard polarity controls tail placement

Positive guard wrappers often preserve original layout better than early negative returns:
- `if (obj) { main } else { null_handler; return; }` can emit `je` to a late null-handler tail.
- Nested success paths (`if (gate) { if (call()==1) { ... return 1; } } return 0;`) preserve shared
  failure epilogues.
- Explicit negative guard returns (`if (key != SPECIAL) return default;`) can push rare handlers
  out of line.
- A redundant-looking guard such as `x == 0 || x >= 0` may be needed when original has separate `jz`
  then `jl` branches.
- For compound predicates, flat boolean expressions are not layout-neutral. If original loads/tests
  groups in phases, preserve that topology with nested positive groups instead of flattening
  `a && b && !c && !d`.
- Add a guardian duplicate return/goto after a critical final `if` when VC5 merges the last exit paths
  but original has separate epilogues.
- Cleanup can belong to an outer feature/acquire guard rather than an inner success path. If original
  branches failed `Lock`/acquire and default cases to a common cleanup block, keep the cleanup under
  the outer guard even if it appears to run after a failed acquire.

### Tail merging and duplicated calls

A clean selector local plus one common call may not match. If original pushes literal arguments in
each branch and jumps to a shared call tail, duplicate the call in source and let VC5 tail-merge the
common part. This preserves branch-local `push imm` order and EH state stores.

Other tail rules:
- A shared `goto done` can avoid eager callee-save pushes for early iterator failure paths.
- Chained-call parameter affiliation can decide tail-call optimization: attach a pushed argument to the
  final callee's real declaration if original keeps `call` instead of `jmp`.
- Literal call-and-return arms can tail-merge into `push imm; jmp shared_call`; a shared `code` local
  often emits `mov reg,imm; push reg` instead.

### Compare spelling changes opcodes

Operand order matters for both register-vs-memory encoding and branch polarity.

- If original has `cmp [mem],reg`, put the member/field expression on the left.
- If original has `cmp reg,[mem]`, put the register/local expression on the left.
- Threshold spelling matters: `state <= 2` can emit `cmp ...,2; jbe`, while `state < 3` emits
  `cmp ...,3; jb`.
- Arithmetic-shaped zero tests (`(a - b) != 0`) can emit `sub` instead of `cmp`.
- FPU comparison direction matters (`best > dist` vs `dist < best`) because it changes `fcomp` order
  and `test ah,mask`.

## 8. Expression, arithmetic, width, and FPU details

### Equivalent arithmetic is not codegen-neutral

Keep the original expression tree when visible:
- single multiplication expressions can preserve the original result-save register;
- left-associative division/multiplication chains can prevent VC5 from delaying sign-adjust work;
- address-expression term order can change SIB/base encoding and instruction length;
- one-based enum indexing should be spelled as `array[type - 1]` when original uses base-minus-one
  displacement;
- direct byte-offset expressions may be needed for queue/record scans when typed `array[index]`
  shortens the address sequence. A useful mixed form is raw byte-offset compare/load for the
  binary-proven field plus typed body access; for packed records, anchor the cursor at the
  observed field (for example a paid byte) and use negative offsets when original does.
- For copy loops where original computes `sub src,this` and later loads through `[delta+dst]`, try
  mutating one source pointer into a this-relative byte delta in source. This is an exact-match
  alias basin, not just an address-term-order issue.

### Boolean and byte idioms

- Use `(unsigned char)expr` to force 8-bit operations/masks when original uses `al/cl/dl`, but do
  not cast stack `int` parameters to `char` too early in tiny helpers if original loads the full
  dword (`mov eax,[esp+4]`) and only the return type is narrow.
- `?: -1 : 0` can force `neg/sbb` all-bits mask arithmetic; `?: 1 : 0` usually produces `setcc`.
- For `strcmp` boolean returns, `strcmp(a,b) ? 0 : 1` can target `AL` directly and avoid `sete cl; mov al,cl`.
- `if (cond) return 0; return val;` can produce branchless `sete/dec/and` where ternary emits branches.
- Explicit `if { field=1; } else { field=0; }` can avoid unwanted whole-register zeroing before `setcc` byte stores.
- To seed inline `memset` with only a low byte, use an `int fill; *(char*)&fill = byte; memset(..., fill, n);`.
- Sometimes the fix is to keep a byte value in a wider integer temp, not narrow it. If original
  mutates `cl`/`dl` from an already-live register, delay the byte cast until the compare/store;
  a premature `unsigned char` temp often forces AL-based code.

### FPU source shape

VC5 preserves much of the x87 expression/source tree. For localized FPU mismatches:
- use volatile float parameter reads (`*(volatile float*)&amount`) or `volatile float` parameters to force stack-parameter `fld` order;
- reread a parameter through volatile when original keeps duplicate `fld param` operands;
- parenthesize addends (`(a * C) + b`) to recover `fadd` vs `fsubr` families;
- match constant precision independently at each use (`float` dword vs `double` qword);
- model float fields as `float` even when constant stores are integer-looking `mov imm32`; the
  immediate must be the IEEE-754 bit pattern, not the integer value;
- use `(long)(fexpr)` casts for direct `__ftol` lowering; calling a hand-declared `__ftol(expr)` can spill/reload;
- pass raw float bits with `*(int*)&float_field` when original does `mov reg,[field]; push reg` to an int-declared callee;
- use an explicit `int` local before `fild` when original loads a 32-bit difference from memory;
- declare virtual numeric getters as returning `float` when original joins the virtual branch and a float-member branch at one shared `__ftol`;
- initialize an independent FPU loop cursor before fallback count loads when original `fld 0.0` precedes count setup;
- inline denominator-producing calls in ratios when original uses `fdivr temp` rather than storing both operands;
- trust odd binary-observed operands in distance formulas if x87 loads/subtracts prove them.

`fcomp; fnstsw ax; test ah,41h` usually corresponds to inclusive comparisons (`<=`/`>=`), not strict `<`/`>`.

## 9. CRT, string/memory helpers, aggregates, and stack windows

### Let VC5 inline known CRT helpers

Try natural CRT surfaces before manual loops:
- `strcmp` can inline as a two-byte-at-a-time loop with `sbb eax,eax; sbb eax,-1`.
- `strcpy` can inline as `repne scasb` plus `rep movsd/movsb`, including the NUL.
- `memset` can emit `mov ecx,count; xor eax,eax; lea edi,dst; rep stosd`.
- `memcpy`/aggregate assignment can emit `rep movsd` or tight fixed dword copies.

Runtime `strlen(extern_string)` can be required when original computes a prefix length inline before
`_strnicmp`; hardcoded constants can be too short and reduce register pressure. For string-to-int
lookup chains, a single reused `int r; r = strcmp(...); if (r == 0) return N;` often matches better
than inline `if (strcmp(...) == 0)` tests. If original calls a CRT helper rather than inlining it,
use a non-intrinsic alias/declaration to block recognition.

For project inline helpers/containers, prefer the real inline surface when the asm shows its canonical
shape. For example, define/use `ManagedArray<int>::operator[]` instead of hand-expanding equivalent
resize/copy logic in the parent; VC5 may then reproduce the expected grow/copy/delete path.

Backward `std; rep movsd` copies and some CRT helper islands may not be reproducible from ordinary C;
treat as a known barrier only after natural CRT forms and loop forms fail.

### Aggregate assignment and exact aggregate size

Use real aggregates for fixed copies: GUIDs, RECTs, headers, parameter blocks, palette entries, and
small structs. Exact aggregate size matters; a too-large pseudo-struct forces independent member loads
instead of source-base setup plus dword moves.

For multidimensional/strided tables, model real arrays (`table[i][j]`) when original computes
`index * stride` once and accesses large displacements from a row base. For parallel arrays walked
through one pointer, an overlay struct with padded fields can recover one-base fixed-offset addressing.

### Stack windows and API structs

When stack offsets are the key diff, model the observed frame directly:
- one local frame struct or `char local[frame_size]` can preserve contiguous `fscanf`/API/helper
  subobject offsets;
- do not trust decompiler names like `buffer + 4` until you account for transient pushes and ESP state;
- fixed API structs should use the observed stack window and written fields, not a guessed larger SDK
  layout; sometimes the right local is a shim/subwindow of an SDK/CRT struct (for example starting
  at time fields) rather than the nominal full struct start;
- group address-taken scratch locals and saved `this` in one struct when helper calls use exact `&field`
  offsets.

If original calls `__alloca_probe` but still omits an EBP frame under `/Oy`, prefer a fixed-size
local array (`char buf[0x1000]`) over `_alloca()`: VC5 treats compile-time large arrays differently
and `_alloca()` may force `push ebp; mov ebp,esp`.

For COM/API vtable calls that initialize a stack struct immediately before the call, naming the
vtable/function-table local can move the vtable load before final `dwSize`/header stores, matching
`mov vtbl,[obj]; push args; store header; call [vtbl+slot]` schedules.

For small struct-return helpers, inspect whether original writes through the hidden return pointer
or NRVO slot. If normal `T result; return result;` creates a full local object, a reference-output
shaped source plus a tiny volatile dummy can reproduce the original hidden-output stack pattern;
use only when the ABI/frame proves it.

For varargs, remember VC5 pushes right-to-left. If the original push order looks reversed from labels in
the format string, the source argument order may need to look odd to match bytes.

## 10. Known VC5 barriers and accepted-drift candidates

Accepted drift remains rare and reviewed; positional `MATCH` is required for promotion to
`src/matching`. The patterns below are useful for recognizing when further C source probing may be
low-yield after behavior, calls, stack cleanup, and layout are understood.

Common benign barriers:
- independent instruction scheduling swaps of adjacent `mov`/`xor`/`sub` instructions;
- `call` vs `jmp` tail-call opcode when stack behavior and callee affiliation cannot be changed;
- stable register-allocation attractors in tiny byte/pointer comparison helpers;
- VC5 choosing branchy `test/jge/neg` instead of original `cdq; xor; sub` abs;
- AND-before-SHR order for byte-nibble extraction loops;
- pointer-copy loop optimization that precomputes `src - dst` and uses `[dst+delta]`;
- byte-vs-dword volatile reload width when both are masked to the same value;
- `movsx` vs `mov/and 0xFFFF` short-index codegen when both are behaviorally equivalent;
- `jbe` vs `je` after `test` when CF is known clear;
- extra caller cleanup after some virtual-call surfaces when stack balance is otherwise equivalent;
- prologue load-before-`sub esp` ordering that source variants cannot move;
- `/GX` new-expression simple-store/common-tail quirks where VC5 always adds a sunk store or join test;
- stable constant-register choices in tiny constructors despite many source variants;
- backward `std; rep movsd` not emitted from tested C forms.

Do not use inline asm/naked wrappers to force normal real functions. Parent-owned fragments,
asm-special regions, and padding-only pseudo-functions are separate workflows.

## 11. High-yield checklist before pausing a stubborn function

1. Re-run under default flags; remove stale per-function `.rsp` experiments.
2. Verify exact field offsets, vptr/base boundaries, `sizeof(new T)`, parameter widths, and callee arity.
3. Verify import/global call opcodes and whether relocations or absolute addresses should appear.
4. Try natural helper/member/constructor/destructor surfaces before raw helpers.
5. Use PDB line info and first mismatch to localize; do not churn later solved bands.
6. Probe declaration order/scope, direct member access vs locals, and parameter-slot reuse.
7. Probe switch vs if, positive guard wrappers, duplicate call arms, and shared-return labels.
8. Probe loop family (`for`, `while`, `while(1)+continue`, direct index vs pointer walk) only after
   behavior and layout are fixed.
9. For FPU diffs, inspect actual x87 operand order and constant precision before algebraic cleanup.
10. If the remaining mismatch matches a known barrier, leave compact scratch notes or propose reviewed
    accepted drift; do not hide it with inline asm.

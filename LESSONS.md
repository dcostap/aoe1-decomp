# VC5 matching lessons

Shared reusable exact-match knowledge only; keep per-function attempts in source logs and semantic reviews in `logic_reviews`. Search/merge before adding; write terse symptom → source shape → codegen reason → caveat bullets, and promote mature general rules to `AGENTS.md`. Prefer binary-supported, period-plausible source and canonical ownership; use casts, volatility, overlays, gotos, manual vptrs, or odd source only when the executable proves the behavior/codegen need. Exactness still requires bytes, boundaries, and relocation identity per `AGENTS.md`.

## Source shape, scope, and liveness

- When an inline ManagedArray-style scan/grow is present and a same-TU sibling
  already matches, mirror that sibling's reference plus bounded `for` scan and
  two-condition copy-loop shape before introducing cached count/capacity locals;
  VC5's induction/register topology can otherwise drift across the whole
  function.  For the paired virtual dispatch, use the proven slot signature
  with real `float` parameters so `-1.0f` remains a raw `0xBF800000` push;
  all-integer proxies/casts change argument bits and scheduling.
- VC5 treats declaration scope/order, initialization site, and assignment form as codegen inputs: they alter scheduling, stack homes, callee-save choice, zero-register lifetime, and even prologues. Probe only against observed symptoms.
- When an old-TU call zeroes two address-taken output locals before loading a later member-valued argument, declaring those locals at function scope and assigning them inside the guard can preserve the original VC5 zero-store/load order; nested declarations let the member load hoist. Prefer the period-plausible top-level declaration style over volatile or aggregate scheduling scaffolding.
- Moving a counter out of a `for`, declaring before/after a guard, or splitting declaration/assignment moves zeroing/LEAs across calls. An inner-body invariant temp may be hoisted yet color registers differently from the same temp before the inner loop (`0044E900`).
- Among call-crossing locals competing for one callee-saved register, earlier declarations often win; order locals to match register-versus-stack pushes (`00514720`).
- A late declaration of an initially-zero value can keep a dedicated zero register live and force another temp into an extra callee-save; a top-level `=0` may be rematerialized and free that register (`0041F030`).
- `for (int i=...)` versus top-level `int i;` can swap two pointer stack homes (fresh slot versus reused parameter home). Together with declaration order, this can control the whole prologue (`00435110`).
- A plausible intervening declaration/use can block count-read hoisting: in one exact pattern, declare incoming count/pointer before `last_order`, then last count/pointer; keep `i` in the `for` header. Reverse compare operands separately if needed (`00435110`).
- Named locals preload/CSE fields and extend liveness; direct member expressions delay loads and preserve rereads. Use a local only where asm carries a value through a phase; otherwise prefer direct access.
- To preserve an outer pointer but force an inner redundant null test, guard/delete through a local while spelling the inner `&&` with fresh member access (`0047A5B0`). Separate sibling `if`s likewise preserve a binary-observed predicate recheck that nesting lets VC5 eliminate.
- Repeated member reloads can reproduce per-store `eax/ecx/edx` cycling in initialization; a saved allocation pointer instead creates one long-lived address register.
- If asm loads/tests a member in EAX and saves it to EDI only immediately before a call, do not name an early divisor/local; direct rereads can preserve the delayed save.
- Killing a constructor parameter after its first member store—later reload `this->member` rather than reuse the parameter—can free a callee-save for `this` and change the entire frame (`0048AE10`).
- A mid-loop reassignment can force an otherwise spilled variable into a callee-save. If the replacement value feeds one immediate call, use a separate call-argument temp and leave the original variable unchanged (`004A37D0`).
- Keep chained calls/arithmetic in one expression when split assignments extend result liveness and swap saved-register roles; split expressions when the binary instead proves call/argument interleaving boundaries.
- A single multiplication expression `a()*b()` can preserve the first result in the expected register where staged `s=a(); s*=b();` does not (`004E4680`).
- A named `param+1` limit can fix a tiny pre-loop `lea`/base-load ordering swap when both raw and derived values stay live.
- A named byte-count before `malloc` can allow VC5 to emit `push bytes`, schedule an independent array store, then call; an allocation-result temp may add pressure.
- A named aligned value (`end=node->EndPx|3; node->EndPx=end; compare(end,...)`) preserves a register across store/guard where member rereads do not.
- When a byte member is passed to a helper whose ABI takes `int`, keep the natural promoted call surface: VC5 can emit `xor eax,eax; ...; mov al,[member]` and preserve the original address/load order, whereas a byte-typed helper may omit the zeroing.
- For elapsed-time expressions whose delta is needed both across a timestamp call and later as an argument, mutate the accumulator in place (`accum -= prior`) instead of introducing a derived delta local; VC5 can then keep the subtraction in the expected callee-saved register before the call.
- For consecutive scans over paired typed arrays, keep preserved base pointers and reset working cursors before every `do/while`; VC5 can require assigning the value cursor before the type cursor to reproduce the original setup-move order. If the binary demonstrably rereads raw parameter bits after the predicate, a narrow volatile source lvalue can block only that hoist; leave the destination ordinary and document the observed reload.
- Common stores belong after an `if/else` when the source naturally shares them: VC5 may tail-duplicate the store while moving a callee-save from loop-top to the prologue. Conversely, duplicate a genuinely common assignment in both arms when VC5 must hoist it between `cmp` and its consuming branch (also useful between x87 compare/pop operations).
- Independent nonvolatile stores may reorder; try source order (even opposite asm order) or a real dependency/direct reread. Do not mark ordinary state volatile merely to freeze scheduling.
- A comma expression can preload one parameter yet delay its store around an independent assignment, but retain it only for a binary-proven, plausible scheduling need (`0047CD40`).
- `register` on a read-only parameter can keep a stack arg in EAX/EDX instead of ESI/EDI; use narrowly and never for address-taken parameters.
- If one early guard must not share a later load, a narrow volatile lvalue can block CSE: e.g. standalone byte `cmp` before a loop, float stack-slot reread, or raw count compare before delayed callee-save pushes. Keep the body/object nonvolatile.
- A pre-loop volatile byte guard can preserve separate `cmp byte [p],0` plus later `mov/test` loop check. A volatile raw count guard can preserve an early direct-memory return and a normal body reload (`004C7920`).
- Do not keep fake volatility or unused locals merely because metrics improve; they are diagnostics unless the access itself is binary-observed.

## Types, ownership, layout, and addressing

- Establish exact widths, signedness, pointer-vs-inline-array ownership, base sizes, vptrs, alignment, field offsets, aggregate sizes, and strides before source-shape tuning. Typed fields usually beat raw casts.
- Derived fields start at aligned `sizeof(Base)`, not the raw end of its last field. If the executable accesses a byte in base tail padding, use a narrow proven flat overlay while retaining real inheritance elsewhere.
- A derived class needs the exact visible base size (including vptr/tail padding). A vtable-only base shifts every derived field; add the proven base data gap (`004A2D50`).
- Full typed class/TU surfaces can alter VC5 register coloring even when touched offsets are unchanged; inspect exact siblings before concluding a minimal gap is equivalent (`00435020`).
- Model proven subfields directly; do not invent helper subobjects/vptrs. Replace local gaps/overlays with canonical shared types when broader evidence stabilizes.
- A binary-proven destructor may need real inheritance for EH/vptr/base-call context but a raw offset for one vtordisp-shifted derived field. Keep the context and override only that access.
- Correct aggregate size can unlock whole-struct base-pointer copy addressing; a widened pseudo-struct forces independent loads. Protocol/wire size may differ from padded `sizeof`, so use the proven wire constant (e.g. WAVEFORMATEX `18+cbSize`) rather than fake packing.
- Aggregate assignment is ideal when the original copies all bytes/uses `rep movsd`; explicit fields are required when trailing padding is omitted or a last byte is copied narrowly.
- Proper typed members can fold address calculation and extension; raw views are appropriate only for proven offsets with uncertain broader layout or a demonstrated codegen need.
- Relation/flag tables that asm loads through a member pointer must be declared pointer fields; modeling them as inline bytes incorrectly folds the indirection (`00532880`).
- For bucket scans, natural typed `resourcePtrs[type][i]`/`numResources[type]` can avoid duplicated bottom compares caused by casted base/current locals. Use pointer walks only when asm proves them.
- Parallel arrays accessed through one iterating pointer may need a proven padded overlay so fixed offsets stay relative to one base; do not compute an index if asm never does (`004E2D10`).
- Strided scenario tables often need real multidimensional member arrays: `table[i][j]` can yield index*stride plus `[this+index+large_offset]`, unlike row pointers with short displacements.
- A 1-based enum over a zero-based member array should be `array[type-1]`; VC5 folds `-1` into base-minus-one displacement.
- Packed records may naturally anchor a cursor at an interior field (paid byte, coordinate byte) and use negative/positive offsets. Do so only after proving owner, stride, and anchor.
- For packed cost entries, anchor at the observed paid-byte cursor and keep sign-extended amount as a separate `int` if asm spills it before resource reloads (`00513C50`).
- For a typed body whose compare needs raw addressing, use a binary-proven raw field load only at the compare while retaining the typed record local elsewhere.
- A loop over a mid-call record array may need natural `Queue[i].field` rather than raw byte cursors: VC5 can strength-reduce `i*sizeof(T)`, reload the member, and keep indexed-load plus separate `lea` element shape (`00431E40`).
- Normalize decompiler cross-member cursors into canonical arrays and an indexed loop when one index selects corresponding elements; this exposes off-by-one errors and often restores VC5 induction.
- Inline repeated row/member expressions when a row-pointer local adds base liveness; conversely split a per-row typed tile base from its subfield offset when asm computes the base before a branch and adds the field offset inside it (`00455CB0`).
- Address term order is not neutral: `[eax+ebp]` versus `[ebp+eax]` can change SIB bytes/instruction length and all branch spans. Preserve observed source-like term order and compare spelling.
- Exception: VC5 canonicalizes `int+ptr` in terminator stores; if registers/load order already match, rewriting the subscript will not flip the SIB base/index. Treat it as a dead axis/TU artifact.
- A global byte-offset base may need `extern char*`; a known global character buffer may need `extern char buffer[]` to preserve symbol-relative indexed stores. Prefer canonical typed declarations for ordinary data.
- Prefer established extern globals/tables over literal absolute dereferences: even the same VA changes relocation, scheduling, and coloring. A narrow typed absolute macro is acceptable only for a proven address lacking stable identity; never bypass relocation checks.
- Fixed lookup tables should be `extern const`; local definitions change data/relocations. Inline repeated shift-table accesses can keep the count in `cl`, while a named temp may spill.
- A flat local virtual dispatch view may use declaration-only padding slots (`offset/4`) to reach observed vtable offsets; account for its vptr and prefer the real inherited surface when known.
- COM calls need explicit `__stdcall`: either a struct vtbl function pointer taking `self`, or a pure virtual `__stdcall` method. Ordinary C++ virtuals use `thiscall` and do not push `this`.
- For COM/aggregate scheduling, name the vtable local before late struct fields when asm loads it first; splitting global/aggregate dword loads can preserve load/store interleaving. Better yet, restore the period SDK-shaped pure-virtual interface: preceding slots can change push/vtable/store scheduling even at the same called offset (`0042F190`).
- For a VC5 C-style COM vtable call with an address-taken size/out local, caching the interface, declaring a vtable-pointer local, and only then zero-initializing the size can preserve the original `vtable load -> argument pushes -> delayed zero store` schedule. Use this only when the indirect-call bytes prove that ordering; a redundant vtable local is otherwise a codegen experiment, not canonical source.
- Model direct members as nonvirtual and vtable calls as virtual at the exact slot; typed calls naturally set ECX/push args. A separately loaded runtime thiscall target can use a member-function pointer raw slot only when a real virtual declaration cannot express the observed shape.
- A method's late virtual fallback slot may be distinct from the nonvirtual method being reconstructed; declare a separate padded virtual rather than recurse or force a qualified direct call (`004212E0`).
- Preserve real helper arity, overloads, calling convention, return width, and ownership from calls/PDB. Default args can insert zero pushes; separate no-arg/arg overloads may be required.
- PDB `__thiscall` plus `ret N` requires a true member definition; a free cdecl function changes cleanup/offsets. Conversely, an explicit self stack argument plus caller cleanup indicates static/free cdecl, not thiscall.
- Narrow virtual setter parameters can avoid caller zero-extension and preserve low-word increments; only narrow with ABI evidence.
- A virtual numeric getter feeding a shared `__ftol` likely returns `float` on ST0, not `int`; cast each branch at the join.
- Struct-return ABI is not an out-param ABI: initialization `T x=f()` passes `&x` directly; assignment `x=f()` uses a temp and aggregate copy. Reuse exact donor signatures/mangled widths.
- Decompiler stack-field names are hypotheses: two adjacent `POINT` locals may be more natural than `int[4]`/`&point.y`; verify `lea` bases.

## Parameters, stack homes, and frames

- VC5 often reuses dead incoming parameter slots. If asm writes/passes/reloads a parameter home, preserve a still-needed original in a register/local and mutate or address the parameter; but do not force this when ordinary locals naturally coalesce there.
- Separate narrow out locals can coalesce onto full-width parameter homes while parameters remain in saved registers. This reproduces overlapping `lea` destinations in `%hd`/`fscanf` and API-output code better than `&param` casts (`00438720`, `004516C0`).
- Conversely, out-parameter cast spelling can intentionally select adjacent stack slots; use exact `lea` displacements and real types, not decompiler-inferred cast labels.
- An incoming parameter can naturally become a moving byte offset while a separate register tracks the loop index; mutate it directly when asm writes its home/uses that topology.
- In long serializers, separate an early address-taken temp from later dead-parameter reuse; collapsing both roles changes stack homes/prologue (`004D84E0`).
- Declare-only output locals assigned only in the valid branch can coalesce with a dead incoming parameter home, reproducing invalid-path reloads and pre-division copies. This is formally uninitialized-path UB: retain only with explicit binary proof/comment and exact assignment order (`00480570`).
- A decompiler may fold a distinct address-taken terminator dword into `buffer[0]`. If the frame is exactly 4 bytes short and string accesses are shifted by +4, restore a separate marker local and use the true buffer base (`0048C3E0`).
- A single proven local-frame struct can lock contiguous C API subobjects/padding; group address-taken scratch values and saved `this` similarly. Prefer named locals unless exact offsets prove the aggregate.
- For large proven fscanf filename layouts, one stack-window byte array can preserve vararg `lea` offsets and dword reloads better than nominal buffers. Account for transient pushes at every `lea`; apparent `buffer+4` may be decompiler stack accounting.
- Fixed `char buf[N]` (>=4 KiB) triggers `__alloca_probe` without forcing EBP under `/Oy`; `_alloca(N)` forces an EBP frame.
- Keep original `.c` donors as `.c`; C++ mode changes language/linkage/codegen.

## Calls, imports, strings, and memory intrinsics

- For original `call dword [IAT]`, declare `extern "C" Ret (__stdcall* const Name)(...)`; normal declarations emit rel32. A narrow local function pointer can model branch-local IAT caching when observed. Preserve symbol/convention.
- Use real VC5 headers/declarations. Header `<stdlib.h>` versus hand-declared `calloc`, `<string.h>` intrinsics, or `<mbstring.h>` MBCS surfaces can change EH and optimization basins.
- `_mbsncpy(_mbsinc(p),...)` evaluates cdecl args right-to-left; split `p=_mbsinc(p); _mbsncpy(...)` when asm calls `_mbsinc` before pushes.
- Split chained member calls/argument-producing helpers when nested right-to-left evaluation interleaves pushes unlike the original. Keep expressions inline when the original intentionally evaluates nested varargs before global-chain loads.
- When a VC5 thiscall shows a literal argument pushed before the call that
  produces the member-call object, preserve the nested form
  (`object->unitAI()->hasOrderOnQueue(0x2C1)`); assigning the object to a temp
  moves the push after that call. Use the split form only when the binary proves
  the opposite evaluation order.
- Put a binary-observed width cast inside the call argument to bind extension and push timing; a pre-cast local allows unrelated LEAs to hoist (`0047C560`).
- Chained-call parameter affiliation matters: attach an argument to the callee that truly consumes it; wrong ownership can enable final-call tail-jump instead of `call` (`0049C540`).
- Member helpers must be declared as members when ECX must remain `this`; free/static declarations change scheduling. Infer virtual wrapper argument ownership from right-to-left pushes and true signatures, not decompiler labels.
- For old C/MMIO helpers, infer full arity from stack loads; a missing fourth handle/out parameter changes pushes. A named result local can reproduce parameter-home zero/store around indirect calls (`00448340`).
- Prefer natural `strcpy` when asm shows VC5's combined `repne scasb` + `rep movsd/movsb`; `strlen+memcpy` creates different liveness. Runtime `strlen(extern_string)` is required when asm scans before `_strnicmp`; do not hardcode the count.
- VC5 `strlen` intrinsic's raw post-`not ecx` count includes NUL. `strlen(x)` emits `dec ecx`; `strlen(x)+1` cancels it. Match serialization semantics and observed fixup.
- `strcat(dst,src)` scans `src` before `dst`; `strcpy(dst+strlen(dst),src)` scans `dst` first. Choose by observed scan order.
- `strcmp(buf,"short literal")` may inline as a two-byte compare loop plus `sbb` result and alter register pressure; prefer it over manual character checks when that idiom appears (`00542360`).
- `memcpy` with `<string.h>` and variable size can inline REP copies; manual dword loops remain scalar. Exact aggregate assignment can also produce fixed `rep movsd` headers where `memcpy` might call.
- Fixed-size `memset` can control `mov ecx; xor eax; lea edi; rep stosd`, preserve zero stores that `T x={0}` dead-store-eliminates, and emit canonical byte-replication fill code. Include `<string.h>`.
- For inline memset where asm loads only AL, seed the low byte of an `int fill` rather than using signed/unsigned char (which may extend). Use only when the uninitialized high bytes are genuinely irrelevant to the intrinsic's byte replication.
- A literal `char buf[32]="..."` declared after a call can reproduce literal dword copies, tail zero stores, and delayed cdecl cleanup interleaving; `strcpy`/manual stores do not (`0042F190`). Buffer size and declaration line matter.
- Prefer natural constant division; let VC5 emit magic multiply/shift. Hand-written 64-bit magic often invokes helpers and changes saves.
- Natural `(long)fpu_expression` invokes `__ftol` directly on ST0; explicitly calling a guessed `__ftol(float)` spills/reloads. For `fild dword`, materialize an `int` difference; use a byte local for byte stack stores.
- Long float-forwarding wrappers should expose real virtual float getters and use natural casts in the final call: right-to-left evaluation then interleaves vtable calls, `fstp [esp]`, `__ftol`, and pushes. Fake helpers lose that schedule.
- For elapsed-time formatters, zero output components before the timestamp call and use a named signed `elapsed` afterward; this preserves pre-call zeroing and signed `/60` quotient/remainder code.
- A moving source-string parameter plus explicit end pointer can recover compact filename-slice loops; keep nested global expressions inline in a following vararg call when asm pushes later args before loading globals (`00423140`).
- In large vararg loops, avoid a named `this+offset` buffer base if it adds a saved register; direct expressions plus right-to-left argument reconstruction can let VC5 reuse adjusted ECX (`00421FA0`).
- An external/static copy/string/helper surface can affect intrinsic selection; clear stale per-function `/O1`/`/Od` flags before chasing source ghosts and retest default `/O2 /Oy`.

## Constructors, destructors, `new`/`delete`, and `/GX`

- Use real constructors (`new T(args)`), base initializer lists, member subobjects, destructors, and `delete`; manual init/delete/vptr plumbing often loses VC5 lifetime/EH state. Match `sizeof(T)` immediately.
- A direct construction expression triggers `/GX` new-object state (`0` during ctor, `-1` after); `new T; init()` does not. Leave declaration-only special members when bodies would emit unrelated COMDATs.
- A derived `new` may be needed solely for the post-base-ctor derived-vptr store; `new Base` omits it.
- Plain C++ linkage for a potentially throwing helper can trigger base-subobject unwind state where `extern "C"` suppresses the constructor EH frame; preserve actual symbol linkage (`00405510`, `004CF090`).
- Visible real virtual destructors and correct header CRT declarations can be what makes `/GX` emit the constructor frame. Do not invent fake virtuals.
- A real base-constructor initializer can unlock derived load-ctor EH/vptr/state; preserve signature, mode args, base size, and destructor surface.
- Constructor initializer lists schedule member stores in declaration order and can delay derived-vptr override relative to body assignment. Hoisting a body field assignment can still schedule its store late among independent copies.
- The first constructor body statement that consumes a parameter can hoist that load and defer the automatic vptr store past zero stores. Do not insert aliases/manual vptr stores before it (`004B8100`).
- If natural lowering cannot place a proven delayed vptr, narrow fallback: `__declspec(novtable)` on only the derived class plus an explicit vptr store; preserve base ctor/vptr behavior and use only with strong evidence.
- Natural virtual destructor surfaces can place derived-vptr restore and direct base-dtor call correctly; manual stores/base calls often reorder or introduce thunks.
- Leave base destructor invocation implicit under `/GX`; explicit source calls usually duplicate automatic destruction/state. Likewise, explicit destruction of an automatic local causes two destructor calls at scope exit—remove it when asm shows one automatic call/state reset.
- Real C++ `delete member; member=0;` can trigger destructor EH cleanup that raw `operator_delete` helpers miss.
- An explicit member-pointer temp before a destructor null guard can force one callee-saved pointer across destructor/delete and avoid duplicate member reloads. Vector-deleting helpers may need one shared delete-pointer local plus common epilogue to make EDI saved unconditionally.
- Real destructible member subobjects contribute EH state numbering and automatic cleanup order; manual parent cleanup can have correct effects but wrong `2→1→0→-1` states (`00408D50`).

## Branches, returns, switches, and block layout

- Equivalent control flow is not layout-neutral. Read original branch polarity/targets and PDB line bands; choose nested positive guards, negative early returns, sibling `if`s, `goto`, or shared tails only when they match observed topology.
- Rare late failure handlers often come from a positive guarded success body with `else`/shared failure; inline failure often comes from negative early return. Multi-stage open/validate code may need outer positive resource guard plus inner negative validation guard.
- Signed bounds with `jl/jg` to one shared error tail commonly come from nested positive `if (x>=min) { if (x<=max) success; } return error`, not two negative early returns.
- A `goto found` can preserve separate found/not-found epilogues; `goto done` can reduce eager callee-save pressure on a genuinely shared return. Do not force gotos without binary topology.
- A direct failure return can place its tail before a shared success label; a duplicated fallback/guardian return can prevent end-of-function exit merging when the binary has distinct epilogues.
- Redundant predicates may be real source/codegen: `x==0 || x>=0` preserves adjacent `jz`/`jl`; simplify only if asm has one check.
- `state<=2` versus `state<3`, member-left versus parameter-left, and `var==1` versus truthy `var` select different immediates, compare operands, and branch polarity. Match per site; one int 0/1 variable can legitimately use both `cmp reg,1` and `test reg,reg`.
- Boolean/ternary forms select `setcc`, `neg/sbb`, or `sbb/and`; probe natural ternary, guard-return, and explicit `if` rather than handwritten arithmetic.
- Explicit `if/else` byte assignments can yield `setcc byte` without a preceding whole-register zero.
- Adjacent-constant call-argument ternaries often become branchless `neg/sbb/add`; duplicate the full call in `if/else` arms to retain binary-observed branching and let VC5 merge the common tail.
- A call+return in each literal dispatcher arm can tail-merge to per-arm `push imm; jmp shared_call`; a selector local instead emits `mov reg,imm`.
- Duplicate same-call branches when asm pre-pushes differing args then joins at `this` load/call. Duplicate both call and derived value expression if repeated calls use the same branch-specific value; VC5 may CSE the derived expression while preserving immediate pushes (`00498A50`).
- Counterintuitively, a single shared post-`if` virtual call may be tail-duplicated into both arms, while explicit per-arm calls may merge to one. Choose by original call count (`0049C650`).
- Return placement inside versus after near-identical switch case guards changes VC5 cross-jump grouping (all merged, 3+1, 2+2); mixed placement can reproduce binary grouping (`0047D120`).
- A single return after `if/else` or guarded block can make VC5 hoist a return constant into a callee-save and tail-duplicate epilogues; per-arm returns may use immediate EAX and different merge groups (`004A2D50`).
- A `switch` is strongly indicated by `je` targets to handlers after the main epilogue. `if/else` usually emits inline cases with `jne` skips. Explicit default and case source order affect placement.
- One sparse switch can generate upper bound check + reused `je max` + `dec/sub` compare chain; hand-built nested guards usually test in the wrong order. A direct switch on a narrow parameter preserves one-based `and/dec/je` and load timing better than switching on a decremented temp.
- Restore every natural dispatch before diagnosing tail merging: replacing a later sparse `switch` with an equivalent hand-written subtract chain can make VC5 merge the independent call-and-return handlers of an earlier jump-table switch. Once handler bodies are independent, source case order can control their emitted order (`004DE4A0`).
- Separate identical `case` blocks produce duplicated bodies/calls and often a `dec/je` chain; stacked `case X: case Y:` produces one shared body/range dispatch.
- Cases that share a value should `break` to one post-switch return when asm has one shared tail; per-case returns duplicate it. Cases whose helper tails are duplicated should instead use per-case helper+return.
- Nested negative equality (`if (x!=A) ... else handler`) can place equality handlers late and preserve `je`; use only where late layout is proven.
- A positive switch arm plus explicit shared FPU cleanup can keep a cold equality handler before a late `fstp st0` cleanup; do not add cleanup labels without observed x87 liveness.
- Duplicating identical cursor advances in common skip arms can tail-merge those advances and move the rare update arm cold; useful for self/threshold scans.
- Lock cleanup can sit outside `if (Lock())` but inside an outer feature guard, so Unlock occurs even on Lock failure; trust executable control flow over API assumptions (`0051F120`).
- For-header comma init/increments can make a loop error handler cold where equivalent `do/while` keeps it inline (`004A2060`).

## Loop and induction forms

- Choose loop shape from CFG: `while(node){...;node=next;}` often rotates the test to a bottom backedge; `do/while`, breaks, and found handling differ.
- If a guarded do-loop has an original `xor` of its index immediately after the object/null guard, declare the index before the guard, assign zero inside that guard, and nest the positive-count test. Initializing `i` inside a combined `&&` can make VC5 fold the setup into `cmp count,0` and lose the observed register compare.
- When a linked-list scan has an explicit initial null return and a second return after exhausting the list, prefer `while (node)` after the guard over `do/while (node)`. VC5 can preserve the original `jne` backedge and distinct fall-through zero-return epilogue; `do/while` may tail-merge both zero-return paths into one shared exit.
- A separate `next` local forces a two-register linked-list walk. Assign a sign-extended `short` directly to `int` for one `movsx` rather than short-local load+extend.
- Remove an explicit `if(n<=0)` when the natural `for(i<n)` already emits the sole observed guard; retain it if asm has both or it has effects.
- A bound that must occur at the top each iteration can be the first body statement while another fixed bound is the `while` condition; putting both in the condition may peel/fold the known first iteration and duplicate tests (`0049D370`).
- Combined `while(i<count && i<capacity)` can yield compact bottom compares; outer guard + `do` + break often adds tests.
- Direct-return bounded scans avoid a post-loop `index==limit` branch. Keep success work/return inside the loop and let exhaustion fall through; put cursor updates in observed order.
- A `for` versus `while` can flip counter/flag register coloring and x87 mask peepholes. Put `i++` explicitly in the body before a call when asm schedules it between `fadd` and `fstp` (`00502230`).
- Explicit row/column cursors in nested `while`s can recover clipped-brush bound/register roles that `for` headers or parameter mutation swap (`00457320`).
- A small constant-count zero loop can unroll into repeated same-register stores more accurately than explicit elements; fixed memset is another distinct basin.
- Shift-left loops: `value[i]=value[i+1]; ++i` yields compact two-address loads/stores; preincrement plus `[i-1]` may introduce an LEA.
- Fixed-stride loops: computing `offset=i*STRIDE` may be strength-reduced into the desired separate byte-offset register when manual `offset+=STRIDE` colors badly.
- Restore the real inline `ManagedArray<T>::operator[]` when asm contains its grow/copy/delete path; hand-expanding it in the parent or defining it out-of-line changes loop tests and call count.
- In ManagedArray-style scans, a bounded indexed loop can recover the donor basin; for a later RMW, name the element address and spell load/value/store separately to prevent collapse to `dec dword [mem]`.
- Pointer loops with spilled counts may need index-primary `for(i)` plus `i*N+j` accesses; VC5 then keeps count in a callee-save and derives stride-1/stride-N stepping cursors without a frame spill (`004A94A0`).
- If asm has two induction registers, mutate an incoming offset parameter or use explicit cursor/index roles rather than collapsing both into one base.
- Preserve a pointer advance last when a rotated loop does so; post-increment member updates can likewise preserve delta/index ordering better than named `index=member+1`.
- For row-pointer setup after allocation/fill, an explicit guarded `do/while` with `i++` before `offset+=width` can swap induction registers into the original roles.
- For coupled scalar-index/pointer inductions, put both updates in the `for` increment in observed order; VC5 preserves that node's `inc index; add cursor,stride` order and may also restore earlier save/guard scheduling.

## Floating point, arithmetic, width, and comparisons

- Trace x87 stack and exact operands; do not “correct” odd formulas. Repeated loads/asymmetric subtractions or transposed x/y bounds can be original bugs and must be preserved (`00453C40`).
- Match literal precision per use: `fcomp dword` needs `f`, `fcomp qword` needs double. One helper may use double multiply/bounds but float subtract. Version checks can intentionally mix widths.
- `test ah,1` after `fcomp` tests C0 (less-than); `test ah,40h` tests C3 (equality); `test ah,41h` combines less/equal (plus unordered implications). Infer predicate and operand order from the actual x87 stack.
- Keep one FPU variable live/in-place when asm carries ST0 through multiple checks; an extra named temp inserts `fstp/fld`.
- Initialize an FPU loop cursor before fallback count resolution when original loads zero before count/fild setup.
- A narrow volatile float read can preserve duplicate stack-param loads/x87 order, but only for observed rereads.
- Parenthesizing `(a*C)+b` can stop reassociation into the wrong `fsubr` family. A double-cast multiply `(float)((double)a*(double)b)` can anchor left-to-right `fld/fmul` where plain float multiplication is commuted.
- When the original x87 tail is `fchs` followed by `fadd [field]`, VC5 may reassociate unary `-product + base` (or `base - product`) into the shorter `fsubr [field]`. A simple `(0.0f - product) + base` can preserve the separate negate/add topology and exact bytes; use it only when the binary proves that arithmetic shape, since it is a codegen/source-spelling axis rather than a semantic correction.
- Inline a denominator-producing call in `numerator/call()` when original spills numerator then uses `fdivr`; naming denominator often causes x87 shuffle and `fdiv`.
- Float fields initialized to `200.0f` may still use integer immediate stores; type/literal must produce IEEE bits, not integer 200.
- Width/signedness govern `movsx/movzx`, byte-register availability, compare width, and signed/unsigned branches. Keep real ABI width and use accurate local/cast only at observed narrow uses.
- To get a dword field load followed by AL compares, use `int mode=field; if((char)mode==...)`; declaring a char local changes the load.
- Compare operand order matters (`member>=param` versus `param<=member`), including short memory-vs-register forms. Preserve observed `cmp` side and branch.
- Use exact threshold spelling for unsigned bytes (`<=2` gives compare 2/jbe; `<3` may compare 3/jb).
- `(unsigned char)(value*32)` can schedule byte RMW memory-read first, while `value<<5` often schedules value/address first; choose from observed operand load order (`00484700`).
- Natural post-increment, compound assignment, and single-expression arithmetic are not interchangeable with expanded forms; use the binary's load/store/call order.

## Globals, translation-unit context, and donor evidence

- Same-TU/same-class exact donors are strong codegen evidence. Mirror their inheritance boundary, includes, declarations, helper surfaces, and—when original bytes are identical—the full body/scopes, not one isolated idiom (`004A6800` donor case).
- An intermediate local for `global->field->method()` can change absolute global load from 6-byte EDX form to 5-byte EAX form and interleave `this` load among pushes. Scope it to one call so it does not become callee-saved.
- Preserve external table/global constness and linkage. Declarations affect relocation identity and codegen; generated names/layouts remain hypotheses.
- TU/header context can trigger EH/intrinsics/register basins even when body text does not use every declaration. Reduce proven context carefully rather than stripping blindly.
- Clear stale custom response files before source experiments. Default VC5 `/O2 /Oy` is the baseline; custom flags remain exceptional evidence.

## Compact diagnostic reminders

- Call-count parity is not call-site parity; verify ordered targets/relocations. A tiny size drift near one SIB/branch can shift every later displacement.
- PDB line bands can distinguish inline expressions, declaration sites, for-header increments, and mid-function initializers, but executable bytes remain the oracle.
- Right-to-left pushes reveal vararg/member argument order; transient ESP changes alter every apparent local offset.
- Before blaming register/frame drift, verify helper out-param ABI and row/column ownership. Transposed indices can preserve CFG/calls yet swap every stack slot (`00485520`).
- Keep exact-source winners natural and typed. Preserve unusual source only for a real original idiom/bug, exact output, or binary-observed aliasing, width, lifetime, evaluation, fault, or stack-home behavior.
- For 32-bit byte-row access where the oracle adds a computed row to a pointer member in EAX and uses a width term as the final displacement, a typed array expression may reassociate into extra instructions. When the original arithmetic is binary-proven, a row-first address expression such as `stride * y + (long)Bits - x + Width - 1` can preserve `add eax,[Bits]; sub eax,x; [eax+Width-1]`; keep the named member ownership and avoid absolute-address plumbing.
- When an `if/else` selects between two same-member integer calls but the original keeps both call sites and converts each result before a common x87 compare, model the branch result as `float`, cast in each arm, and spell the final predicate in the observed direction (for example `dist > threshold`). VC5 can then retain branch-local `fild`/calls and emit the original stack-to-stack `fld`/`fcomp`/`test ah,41h` shape instead of tail-merging to one call plus a memory `fcomp`; use only when the duplicate calls and FPU topology are binary-proven.
- In virtual child traversals with a captured/non-captured outer split, return a child's nonzero result directly and let the outer `if/else` share the final zero return. Spelling `return 1` for the child can move the literal into the epilogue and leave an otherwise exact VC5 function with a localized mismatch.

- When VC5 canonicalizes a commutative field product inside an intrinsic clear into the wrong member-load order, materialize the first operand and compound-multiply the second before `memset`; this can preserve a binary-proven height/width load order without raw-address plumbing. In a packed-record scan, an interior-field cursor declared before the loop-count local can likewise place the count spill after the cursor LEA; retain that shape only when the original anchor and store order are observed.
- In a nested scan over two coordinate offsets, which loop updates the first versus second call argument can control VC5's callee-save/register coloring even when the iteration set is identical. Read the original accumulator additions and use the corresponding outer/inner axis order before introducing register-forcing source tricks; this can turn an otherwise exact-size loop into an exact match.
- When a short/int FPU quotient has the original divisor sign-extension before numerator conversion but `fild` still consumes the numerator first, split the natural numerator into a named `float` temporary (`progress = numerator; result = progress / divisor`). VC5 can then materialize the divisor first and recover the original conversion order; use only when the x87 sequence proves that topology. For a dispatch whose two arms end with the same member assignment, place that assignment after the `if/else` so VC5 tail-duplicates it with the original per-arm register choices. A real virtual declaration at the observed slot is likewise preferable to a hand-cast function pointer when the binary uses `__thiscall` dispatch.
- In an EH-framed constructor with inline polymorphic members, model the proven virtual base/destructor surfaces rather than flattening vptrs into explicit padding; VC5 can then emit the original per-member EH-state stores. When independent sentinel-link stores interleave with initializer stores, moving the link statements later in the natural body can recover the original optimized schedule without volatile or fake locals.
- For VC5 byte decrements with signed saturation, `int diff = (int)cell - (int)amount; if (diff < 0) cell = 0; else cell = (unsigned char)diff;` can lower to the original `sets/dec/and` sequence; an equivalent ternary may instead retain branches, so use this spelling only when the binary proves the saturating behavior.
- In an EH-framed deserialization constructor, put the child-construction loop inside the positive-count allocation arm when the original cold path directly zeroes the array field; after storing context members, pass those members to each child rather than incoming parameter homes when asm reloads `[this+...]` and reuses a parameter slot for EH state. This preserves branch topology, member reloads, and stack-home reuse without artificial locals.
- When VC5 folds `position - product` into `fsubr` but the original x87 sequence proves `fchs` followed by `fadd position`, an explicit float cast around the negated product—`(float)(-((delta / distance) * scale)) + position`—can preserve the source-level rounding boundary and exact stack topology without spills. Use only when the binary shows the separate negate/add sequence; the cast is not a general scheduling trick.
- In serialized setup routines that resolve short IDs into member pointers, one named result local per lookup plus a member store after each `if/else` can preserve VC5's test/join and success/null epilogues; direct member stores may hoist zero, introduce `cmp` against a zero register, or merge returns. Keep the source predicate/arm order aligned with the observed late null arm, and retain this shape only when the binary topology proves it.

- In an outer list/count loop with original writes back to the incoming parameter homes, capture the pointer and remaining count as locals inside the positive-count guard; VC5 can coalesce them back to those homes while retaining the delayed-save prologue. Direct cursor mutation or a separate top-level cursor may instead reload the pointer before the loop.
- For a bounded dynamic-array copy, an un-nested `for (i=0; i<oldMaximum && i<newMaximum; i++)` can reproduce VC5's compare-before-copy and old-maximum reload after the increment. An added outer maximum guard or a do/break loop may introduce extra tests and a different induction shape.

- When an EH-framed lazy-load gate has a far failure return and an inline success
  block, VC5 may require a positive nested guard (`if (loaded) { ... } else
  return 0`) rather than the equivalent early negative return; the former keeps
  the original `je` to the distant epilogue and exact block spans. For a local
  pointer zeroed immediately before a call, declaring it without an initializer
  and assigning it at the call site can also preserve the original delayed stack
  store and EH-prologue ordering. Use only when the binary proves those shapes;
  retain the ordinary typed lazy-load source rather than compiler-steering hacks.

- When a destructor walks several adjacent pointer arrays with one shared stride, a natural indexed loop over each named array can compile to the original single cursor plus per-call LEAs. A hand-written overlapping cursor such as `p`, `p-8`, and `p+8` may make VC5 hoist a second pointer and add a callee-save; prefer the indexed form when the binary shows one cursor and a countdown register.
- Recompute stack homes after every callee-cleanup `__thiscall`/virtual call before trusting decompiler parameter labels. A multi-argument call can restore ESP, so later `[esp+...]` loads may refer to the original earlier x/y parameters rather than the arguments just passed; preserving the corrected source call can remove artificial callee-save pressure and recover exact VC5 codegen.
- When PDB/assembly prove a small buffer and adjacent scalar local occupy one VC5 stack window, a typed aggregate such as `{ char buffer[N]; int value; }` can preserve the proven window while a separate scalar consumes the loaded dword without adding a store; use only for that binary-backed local topology and audit source plausibility before promotion.
- When a dispatch's first case is a late shared-tail path, switching directly on the original value can emit VC5's subtract/je cascade; an arithmetic temporary plus nested `if` may collapse the second test to `cmp/jne`. For one-argument vtable calls, use typed virtual methods at the observed slots and let the real base vptr provide offset zero—duplicating a derived vptr gap shifts every proven member field.
- For symmetric rectangle-bound tests, algebraically equivalent operand reversals can control VC5's `cmp` direction and branch polarity independently at each site. Preserve the binary-proven mixed spellings (for example `right > other` versus `other < right`) before changing layout or control flow; this can resolve a byte-only mismatch while retaining a natural typed overlap tree.
- For a ManagedArray-style task list, a reference-local array plus the donor's natural indexed scan/growth `for` loops can preserve VC5's count register, compare-before-copy topology, and exact allocation calls; use a real typed virtual declaration and promote a proven short field at the call boundary rather than hand-casting a vtable.
- In two-pass bounded scans sharing one count, VC5 can color the persistent count and first-pass countdown differently when the second pass is written as a natural `while`/`for` instead of `do/while`, even under an outer positive-count guard. Try those ordinary loop forms before register-oriented source tricks.
- When a counted list loop stores its incremented count back to an incoming parameter home and the original max-count branch targets a shared final return that reloads the count, `if (++count == limit) break; return count;` can match where `return count` keeps EAX live and skips the reload. Use only when the branch target proves the shared-return topology.
- For VC5 x87 threshold chains, an otherwise identical threshold written with ordinary float literals can let the compiler schedule `fld`/`fdiv` before an integer member update and `fmul` afterward; binding those values to external typed rdata symbols may keep the whole expression after the store. Try the literal spelling only when the original x87 interleave proves it, and retain it only as a plausible exact source form.
- For a validation-heavy VC5 routine with one shared failure epilogue after the success body, nested positive guards can preserve the original long conditional branches; early `goto fail` forms may create a local short-branch failure block. When integer load/add/sub order is also localized, split a natural expression into sequential initialization and compound updates before considering lower-level scheduling tricks.
- For list builders, model the real `Item_Avail` input stride and inherited output ownership (`list_size` plus `rdlg_list_info*` with its `0x66` record size) before tuning loops. A typed `TRIBE_Player::interface_item_avail(Item_Avail**, short*, short)` surface, an early `short` index, and a guarded `do/while` can recover VC5's local/register topology and copy schedule; minimal pointer records or reversed ABI proxies can hide the same stride and spill the wrong values.
- When a small outer selector has adjacent cases and one case owns a large nested dispatch, an outer `switch` on the original selector can produce VC5's sequential `dec/je` then `dec/jne` cascade and outline the nested switch body; equivalent `if/else` source may emit `cmp` branches with the large body inline. Keep ordinary `break` defaults and a common tail when the binary shows that topology.
- In a file loader whose original callee-save counters appear only after successful resource/count guards, a positive outer resource guard plus counter initialization bound to the successful count read can preserve staged VC5 saves; an early return or hoisted top-level initializer may save all counters at entry.
- For adjacent short outputs read by a varargs `fscanf`, use the original LEA order and downstream call roles to recover source destination order. Right-to-left argument lowering can require source `&second, &first` when the first parsed value feeds the callee's second argument; verify this from binary stack homes rather than decompiler labels.
- For VC5 dynamic output-array growth, keep the old-buffer copy as a natural `for` inside `if (old != 0)`, but put `delete(old)` in a separate following guard after the capacity update; combining the guards changes the branch topology and loop-init order. A cursor declared before the outer positive guard and reset at its start can also preserve the observed parameter-home/local-home schedule when the binary proves those stores.
- When two branch-specific calls share one final call/return shape, an explicit success-arm `return` followed by a fall-through fallback call can let VC5 tail-merge the calls while preserving the original long-lived pointer register allocation; an equivalent `if/else` with a common return may swap those registers. Use only when the binary proves one call site and the success return topology.
- For VC5 dynamic-array growth, mathematically equivalent capacity updates are not codegen-neutral: `capacity = capacity << 1`/`<<=` can leave a localized register/block drift while `capacity = capacity * 2` recovers the original reload and downstream parameter scheduling. Try the ordinary multiply spelling when the allocation/copy/append topology already matches, and retain it only when the binary confirms the exact source shape.

- In a constructor mask tail, independent inverse/member assignments can control VC5's register schedule even when all stores are semantically fixed. If the binary stores the visible mask, copies it, shifts the original register for the explored mask, then emits explored-inverse before visible-inverse, place the visible-inverse assignment before the explored-mask assignments; use only when that natural field-update order is binary-proven.
- When a typed two-pass scan has exact CFG/size but the persistent count and first-pass countdown are assigned to swapped registers, restore the same-TU base/record field ownership and donor local declaration/lifetime shape before trying register-forcing tricks; VC5 can then recover both counter colors and shared pointer reuse exactly.
- For fixed Windows palette buffers, if stack evidence proves `HWND` shares `PALETTEENTRY[0]` and a 256-entry API call starts at `entries + 1`, model the overlap with a typed union and name the adjacent one-entry API-overrun home with a typed aggregate member. This can retain VC5's original frame and array offsets without raw frame offsets or fake volatility; verify the overlap/overrun from the actual stack addresses first.
- When two natural branch calls share an identical outgoing literal, VC5 may hoist that push before the branch test; matching the shared argument can recover the original compare/branch topology. Likewise, assigning a proven short field to an `int` local can preserve `movsx` into a callee-save plus later dword compares/pushes, while a short local emits only a word move. Use only when the original width and shared push are binary-proven.
- In EH-framed queue update routines with duplicated global counter notifications, a branch-local typed counter pointer plus explicit `old_count`/`new_count` assignment can preserve VC5's separate load/store blocks and callee-save vtable register instead of tail-merging `++` paths. A positive resource-available guard can place the attr-needed fallback in the original late block; verify the FPU branch polarity. For `new` of a polymorphic action, model the proven complete `sizeof`/field surface (0x50 here) before tuning surrounding control flow, since the allocation immediate is structural.

- For same-TU HRESULT/error-number helpers, mirror an exact sibling's real member
  switch surface and `(long)0x...` case-constant spelling before tuning the
  decision tree. VC5 can emit the complete balanced compare/return tree exactly;
  one wrong case result or a free-function shim shifts the whole helper despite
  otherwise matching its structure.
- For a reverse indexed scan whose original setup is `dec index; js cold_return; lea walker`, keep the ordinary loop topology but add a natural `if (index < 0) return;` before initializing `walker = base + index`. A guarded `do/while` can delay the LEA too, but changes the cold/common epilogue and broadens the drift.
- For a VC5 coordinate swap feeding two float virtual-call arguments, the temporary orientation can control both parameter-home stores and x87 evaluation order. When the binary stores the first post-swap value into the original first home, use `temp = second; second = first; first = temp;`, then name semantic coordinates from the post-swap fields before the call; this can recover exact `fild`/`fstp` slot scheduling without raw offsets.

- When a conditional argument is passed to a chained member call, duplicating the
  ordinary call in the null and non-null source arms can let VC5 tail-merge the
  receiver/callee while retaining branch-local `push` order. A common pointer
  temporary may instead materialize `xor`/`push` and load the receiver too early;
  use the duplicated form only when the binary shows one merged call site.
- For old panel hierarchies, model the proven base size and nested vptr-bearing
  object before tuning body shape: a `TPanel` base ending at `0xF4`, a
  `TScreenPanel` ending at `0x478`, and a draw-surface vptr can recover otherwise
  broad field and indirect-call drift. In indexed button scans, a natural
  `TButtonPanel** slot = &array[i]` plus repeated `(*slot)` member expressions
  preserves slot-address liveness; an ordinary `button` local may choose the
  wrong register topology. A `while (i < limit)` header can also emit the
  original `jl` backedge and cold found-arm jump where `do/while` reverses them.
- For a sparse key/button dispatch whose binary uses a compressed range-map jump table, an ordinary `switch` with explicit grouped cases can reproduce VC5's map. Express arrow guards as positive combined conditions with one shared success tail, rather than early returns, to preserve the original common-return topology; verify case order and per-case return values.
- For VC5 map brush-stroke interpolation, declare integer endpoint distances before the double step/position locals, and declare the loop count inside the positive-count guard after testing the distance. Updating the x accumulator before y can recover the target x87 spill order and branch/store placement while keeping a natural typed source.
- In an EH-framed VC5 `new` path, a proven polymorphic screen/object surface is structural: if the allocation immediate and a member access are both exactly 4 bytes too small, model the vptr with a real virtual destructor (and preserve the named field offset) before changing control flow. With `/GX`, a natural typed `new T(args)` then restores the compiler's constructor/EH state and exact size.
- For a same-TU class helper whose natural indexed loop has exact size/CFG/calls but only SIB base/index bytes differ, model the proven polymorphic base and full member placement before trying pointer walkers or casts. A real vptr plus the known derived member boundary can flip VC5's encoder choice while leaving the readable indexed source unchanged.
- When two identical switch arms contain binary-proven separate API call sites, a function-wide result local can make VC5 fold the calls into one site. Scoped result locals inside each natural case can preserve both calls and the original liveness basin without register-forcing tricks.

- For a counted scan bounded by both a live count and a capacity, an un-nested
  `for (i = 0; i < count && i < capacity; ++i)` can preserve VC5's one initial
  count test, capacity compare, indexed SIB load, and backedge exactly. An outer
  positive-count guard can duplicate the count test, while an equivalent
  do/while may turn the indexed access into a pointer walk; use this only when
  the original compare order and loop bounds support it.
- For a proven fixed-size member record whose zeroing must interleave with a later API argument address, `memset(&record, 0, sizeof(record))` can recover VC5's early address/store and `rep stosd` schedule where a scalar field zero emits a later direct store. Keep this only when the record size and byte-level schedule are independently established.

- For VC5 status loggers with a timestamp and a 256-byte formatting buffer, declaring the `long` timestamp before the buffer can reproduce the 0x104 stack window and the buffer's +4 offset across `time` and later API calls. A typed inherited `get_string(int,char*,int)` at the proven vtable slot, combined with direct map/victory helper methods, preserves the natural right-to-left push/evaluation schedule. Do not add a defensive owner-null guard when the oracle dereferences the object before testing its name; that guard changes the CFG and function size.
- When a virtual position/teleport slot is proven to return `float` and the
  caller ignores it, declare the real return type: VC5 emits the required
  `fstp st0` before the next call. The return-type correction can change the
  surrounding integer register coloring, so recover the original source order
  of adjacent coordinate stores afterward; an ordinary x/y/z assignment order
  may emit the binary's z-before-y stores. Likewise, an initialization group
  written as type/owner/master can preserve an observed type-before-owner store
  while still preloading the second parameter at entry. Use these only when
  the vslot and store order are established from the executable.
- When a same-named helper has multiple generated donors, resolve the actual
  direct-call target before copying its ABI: the Shape.cpp `TDrawArea::AlignedWidth`
  target is the long-returning method at 00444B40, while another `AlignedWidth`
  donor has a different class/return surface. A wrong return declaration may
  leave bytes unchanged but produces the wrong mangled relocation identity and
  can perturb VC5 scheduling.

- For tiled-map setup fills that lower to unconditional `rep stosd`/`rep stosb`,
  use the natural `memset(map, 1, width * height)` surface rather than a
  guarded byte loop. In an adjacent-cell prune, repeated direct indexing for
  the first cell test plus a named cell pointer for neighbor/store accesses can
  preserve VC5's row-base/cell-pointer topology; spell zero-edge guards as
  `index <= 0` when the binary shows `test`/`jle` rather than `< 1` (`cmp`/`jl`).

- For tcommand building/research handlers, `TRIBE_Building_Object::work_status`
  is the period ABI `int work_status(short&, short&, short&, char*, short)`.
  A natural three-short output surface lets VC5 reuse the incoming command
  parameter home for the first status and can collapse a large EH-framed
  mismatch to exact bytes; passing the command pointer is only a decompiler
  artifact. Likewise, TRIBE_Player slots `0x10C` and `0x118` are the four-int
  `cancelTrain`/`cancelResearch` surfaces, not short-parameter `make`/`research`
  guesses; the int signature recovers required `movsx` loads. Finally, source
  that writes the player fallback separately in the building-status and
  no-building arms preserves VC5's duplicated lookup blocks instead of allowing
  common-tail folding to remove them.

- For paired same-TU interpolation routines, mirror the exact donor's
  declaration/initialization order for integer distances, double steps, and
  double positions before tuning x87 stores. If the oracle tests an integer
  distance and only then spills a loop count, declare that count inside the
  positive-count arm; declaring it before the test can move its stack store
  ahead of the branch and shift the whole FPU cleanup sequence.

- When a VC5 text-measurement path copies a prefix into a temporary only to
  obtain its byte length, verify the later extent-call pointer independently:
  the original may pass the source string with the copied-prefix count, not the
  temporary buffer. This also lets VC5 share the final text/DC pushes across
  both arms. For small alignment enums, a source `switch` can recover the
  original subtract/dec/je dispatch and shared tails where equivalent `if`
  chains emit cmp/jne blocks.

- In a small VC5 rectangle updater, caching a contiguous member such as
  `render_rect.left` in a local can change only the late register schedule while
  preserving size, calls, and every earlier byte. Replacing that cache with the
  direct named member expression in both format arms restored the original
  LEA destination and exact suffix. When a localized hunk is an expression
  scheduling mismatch, test direct canonical member ownership before adding
  temporaries or compiler-steering scaffolding.

- For four-neighbor tile checks that convert two float coordinates with `__ftol`,
  restore the typed world/player/master/map/list surface and the donor's local
  declaration order before chasing registers: an `int` counter followed by
  `short h,w,y,max_y` can recover the whole EBX/EBP coordinate and out-pointer
  coloring. In the final neighbor arm, an ordinary common return with explicit
  owner-mismatch and boundary clears (but no redundant null-arm assignment) can
  preserve VC5's counter stack store and shared failure tail; a direct success
  return or extra null assignment changes the late epilogue. Keep this shape
  only when the original branch/tail topology proves it.

- In VC5 switch handlers that initialize two common-tail result locals, source
  assignment order can choose which immediate lands in EAX versus a callee-save.
  If the handler topology and values already match but the two stores are
  reversed, assign the action/result value before the order/selector value; keep
  this only when the original handler bytes prove that per-case store order.

- When a period utility source body already matches structurally but a persistent
  pointer pair is colored into the wrong callee-saves, restore the donor TU's
  plausible headers before adding locals or aliases. For VC5 DIB utilities,
  adding the original `windowsx.h`, `stdio.h`, and `memory.h` context changed
  register allocation without changing source semantics and closed a localized
  seven-byte gap; unused header context can affect the optimizer basin.

- For VC5 scans over fixed-stride memory, a named entry pointer can force a
  persistent offset into the wrong callee-save and shorten the whole function.
  Once behavior and stride are proven, mirror an exact same-TU donor's direct
  indexed member expressions (`records[i].field`) before adding register
  aliases; this can recover the original late-save loop topology and full size.
  The declaration order of two result locals can then independently control
  the initial parameter-home store order.

- When a function repurposes incoming parameter homes across a late register
  push, track their fixed entry addresses rather than their changing `[esp+N]`
  labels. A closest-object scan may retain the squared distance in one home,
  the selected object id in the other, and return the id after the save is
  popped; this can look like a distance return in the decompiler's renamed
  locals.

- For a packed-record update with an independent running offset, source order can be
  counterintuitive: writing `entry.size = size` before `output_offset += size` let VC5
  emit the oracle's pointer reload/add/size-store/offset-spill sequence exactly, even
  though the add instruction precedes the store in the final bytes. Use this ordinary
  statement order only when the accumulator has no intervening observable use and the
  binary proves the stores are independent.

- In EH-framed VC5 destructors that release several same-type heap members, save each
  member pointer in a local before the null check and direct `delete`. Reusing that
  local across the cleanup blocks lets VC5 keep the pointer in a callee-save across
  the destructor call; accessing the member again makes it reload after the call and
  can add bytes or change the whole register/lifetime topology.

- In a bounded VC5 coordinate scan, initialize both upper-bound fields before
  applying map-width/height clamps. This can preserve the original `lea`/`add`
  schedule, frame, and loop topology; once the remaining hunk is a comparison,
  reverse equivalent operands (for example `best > distance` versus
  `distance < best`) to reproduce the oracle's `cmp` direction without changing
  behavior or resorting to compiler-steering scaffolding.

- In a bounded VC5 scan with a persistent cursor and a conditional match count,
  a natural `for (; index < limit; ++index, ++cursor)` can emit a materially
  different and much closer basin than an equivalent `do/while`. After that
  structural change, reverse the inner bound spelling (`matches >= count`) when
  the oracle proves the opposite `cmp` operand order; the pair can remove a
  localized branch hunk without aliases or volatility.

- In a stateful VC5 transition routine, reuse the clipped/result local when a
  later fallback assigns it (rather than introducing a second `new_*` local).
  This can keep the value in the expected callee-save register through the
  branch and eliminate a spill. Once the hunk is localized, equivalent source
  comparison spellings such as `old_x < new_x` versus `new_x > old_x`, and
  `old_y >= new_y` versus `new_y <= old_y`, can select the oracle's `cmp` order
  without changing behavior.

- For a VC5 fixed-stride queue scan, a single index plus a top-tested
  `while (*cursor != 0)` can preserve the compiler's EBP=this/ESI=index basin;
  separate decompiler locals for the same index can swap this and the spill
  home. After the loop topology matches, put the index on the left of
  equivalent bounds (`index >= limit`, `index > high`) to recover the oracle's
  `cmp` operand order and branch bytes.

- For a same-TU x87 turn helper whose first angle result is spilled to an
  incoming float-parameter home, binary-proven literal thresholds/zero can
  select VC5's `fst`/`fcomp`/`fld` topology where external typed constants keep
  the value live in ST0. Apply a facet step directly as `this->angle +=/-=` and
  put the negative case inline when the oracle has a common `fstp` and opposite
  branch polarity; remove redundant coordinate aliases after checking that
  ordinary parameter use still preserves the home reuse.

- In an EH-framed VC5 derived constructor with destructible fixed-layout members,
  model the members with their natural inline default constructors and list
  scalar initializers before array/member initializers. This can recover the
  compiler's delayed member-constructor call and derived-vptr placement. If a
  final scalar store and vptr store are swapped, moving that proven zero
  initialization into the member-initializer sequence can change only the
  localized ordering without aliases or volatility; retain the shape only when
  the original constructor bytes confirm it.

# Recovery journal: 004B9440 `shape_draw`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Shape.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Shape.cpp`.
- Earlier recovery note: `recovery_notes/Shape_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:6d3376e1f19126b9daa0 -->
### `target-session` `build/target_sessions/004B9440_shape_draw.json:1-28`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=871; shape=65.57377049180327: Baseline: current clean scratch reconstruction with typed TShape/TDrawArea/Shape_Info surfaces, direct helper calls, FShape fast and clipped dispatch paths.
probe 2 liveness; result=MISMATCH; diff=824; shape=63.53887399463807: Hypothesis 1: narrow volatile return byte forces the observed stack byte home and may recover the 0x1C frame/prologue; diagnostic only unless surrounding source supports it.
probe 3 layout; result=MISMATCH; diff=820; shape=53.82513661202186: Hypothesis 2: reuse incoming x/y formals as clipped x0/y0, while retaining raw x1/y1 locals; tests binary-supported parameter-home reuse instead of four fresh coordinate locals.
probe 5 liveness; result=MISMATCH; diff=871; shape=65.57377049180327: Hypothesis 3: register qualifier on the frequently reused shape_num parameter may recover original early EBX color/load before callee-save pushes; diagnostic only if it creates unsupported or worse output. [same emitted code as probe 1]
probe 7 liveness; result=MISMATCH; diff=824; shape=63.53887399463807: Hypothesis 4: keep the observed byte return home and split all normal-path coordinate declarations from assignments; tests source lifetime and initialization-site effects on the 0x1C frame. [same emitted code as probe 2]
probe 9 abi; result=MISMATCH; diff=871; shape=65.57377049180327: Hypothesis 5: replace opaque head/FShape pointers with period-typed forward declarations, testing canonical TShape field ownership without changing proven offsets or helper ABI. [same emitted code as probe 5]
probe 11 abi; result=MISMATCH; diff=871; shape=65.57377049180327: Hypothesis 6: signed char return local instead of unsigned byte tests whether original byte home came from a plain char source declaration and changes VC5 promotion/liveness. [same emitted code as probe 9]
probe 13 liveness; result=MISMATCH; diff=871; shape=65.57377049180327: Hypothesis 7: add a natural original-bottom alias across the late unclipped test, testing whether one extra proven live coordinate forces the original 0x1C stack frame and parameter-home reuse. [same emitted code as probe 11]
probe 14 liveness; result=MISMATCH; diff=871; shape=65.57377049180327: Hypothesis 8: retain one typed draw_area alias through the normal-shape branch, testing whether branch-local receiver lifetime recovers original EDI draw-area color and homes. [same emitted code as probe 13]
probe 15 layout; result=MISMATCH; diff=871; shape=65.57377049180327: Hypothesis 9: split tagRECT declaration from aggregate assignment, testing VC5 aggregate-copy lowering and local initialization timing against the observed four-field stack copy. [same emitted code as probe 14]
probe 16 variant; result=MISMATCH; diff=871; shape=65.57377049180327: variant lab build\variant_lab\004B9440_shape_draw\20260817_154829: 128 variants, 0 invariant-eligible, 0 exact
probe 17 liveness; result=MISMATCH; diff=871; shape=65.57377049180327: Hypothesis 11: declare x1/y1 before x0/y0 but preserve emitted computation order, testing VC5 declaration-order register coloring and stack-home assignment. [same emitted code as probe 16]
probe 18 abi; result=MISMATCH; diff=879; shape=65.84699453551913: Hypothesis 12: use the inventory-proven zero-argument ASMGet_Color_Xform and nest it in AddDrawNode; original pushes draw-level/object-id before the no-arg helper, which requires natural right-to-left member-call evaluation.
probe 19 control-flow; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 14: replace the clipped if/else mode chain with the binary-proven switch topology; original emits dword mask, subtract, and decrement dispatch before the clipped helper tail.
probe 20 control-flow; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 15: route both invalid mode arms through one explicit local-return label; original has a distinct byte-home return path at 004B97CB instead of constant xor-zero. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 16: move the proven rectangle local to function scope while assigning it only in the normal-shape arm; mirror's period source uses function-scope clip locals and the target frame is four bytes short. [same emitted code as probe 20]
probe 22 liveness; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 17: move all rectangle and raw/clipped coordinate locals to function scope, mirroring period sibling declaration scope and testing persistent liveness across FShape and normal arms. [same emitted code as probe 21]
probe 23 abi; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 18: type the inventory ASMGet_Color_Xform return as int, matching its dword masked result and the xform argument ABI instead of an opaque pointer. [same emitted code as probe 22]
probe 24 liveness; result=MISMATCH; diff=824; shape=57.608695652173914: Hypothesis 19: diagnostic narrow volatility on the return byte combined with corrected helper ABI and clipped switch may recover the original byte home without opaque control-flow scaffolding.
probe 25 liveness; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 20: address the return byte through a natural local pointer instead of volatile, testing whether alias liveness reproduces the observed stack zero store without retaining fake volatility. [same emitted code as probe 23]
probe 29 control-flow; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 1: split the negative shape_num and Check_shape guards into sequential early returns, matching the original line 627 guard topology and deferring this-register setup. [same emitted code as probe 28]
probe 31 control-flow; result=MISMATCH; diff=878; shape=59.83606557377049: Hypothesis 2: recover the Ghidra/PDB natural dispatcher: preserve draw_area alias, mutate clipped x/y parameter homes, retain raw bounds, and put clipped mode dispatch before unclipped dispatch.
probe 33 liveness; result=MISMATCH; diff=894; shape=60.10928961748634: Hypothesis 3: reuse the x/y incoming homes for clipped bounds while keeping raw bound locals and the proven current dispatch order; this tests the prior Ghidra-backed parameter-home topology with corrected helper ABI and natural ret.
probe 35 liveness; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 4: keep a natural TShape self alias across the dispatcher, testing whether explicit object lifetime recovers the original ESI self and EBX shape_num register basin without ABI changes. [same emitted code as probe 29]
probe 37 liveness; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 5: use the PDB/Ghidra local set and declaration order (ret, shape_y1, shape_x1, rect), with raw upper bounds carried by function-scope locals instead of branch-local original_x1/original_y1. [same emitted code as probe 35]
probe 39 control-flow; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 6: remove the FShape else wrapper and fall through naturally into the normal-shape path after the fast-path return, matching the Ghidra/PDB source topology. [same emitted code as probe 37]
probe 41 context; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 7: restore the period Windows SDK RECT context instead of a local tagRECT clone, testing whether Shape.cpp header state selects the original VC5 local/frame basin. [same emitted code as probe 39]
probe 43 control-flow; result=MISMATCH; diff=890; shape=68.0327868852459: Hypothesis 8: mirror exact Shape.cpp donor style with nested shape_num and Check_shape guards rather than one combined && guard. [same emitted code as probe 41]
```
<!-- end-recovered:6d3376e1f19126b9daa0 -->

<!-- recovered:937d62ee68b6547dc43d -->
### `0923cad7edb1` `src/scratch/004B9440_shape_draw.cpp:1-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004B9440 TShape::shape_draw
// Attempt log:
// try 1: packet-grounded dispatcher/wrapper reconstruction: Check_shape guard, fast FShape/ASM paths,
// clip rectangle computation, unclipped dispatch by draw mode, clipped dispatch by draw mode/shadow table. Compiled too short (880B vs 933B).
// try 2: diagnostic-only padding branch reached byte compare, then removed. Diagnostic compare was broad mismatch (85.9593% positional / 127.1168% edit), first mismatch frame 0x20 vs original 0x1c and parameter/register order wrong from the prologue.
// try 3: modeled Check_shape(shape_num,"RGL_shape_draw") guard and negative shape_num return; call surface compiles but not codegen-close.
// try 4: modeled FShape capture path using SDI globals, color xform, AddDrawNode, fog_next_shape, and frame offsets.
// try 5: modeled FShape fast ASM surface setup path: surface info, optional xlate table, ASMDraw_Sprite, ASM_Fast_Count++.
// try 6: modeled normal shape path: load shape frame from offset table, compute unclipped bounds, clamp against draw-area clip and dimensions, early empty return.
// try 7: modeled exact high-level dispatch families for mode 0/1/2 and table present/absent to unclipped and clipped shape helper variants.
// try 8: restored the period TShape/TDrawArea/Shape_Info surfaces and the real
// DClipInfo_List::AddDrawNode thiscall ABI. Corrected the FShape capture/fast
// fields and all helper argument order/arity from the inventory declarations.
// The first integrated check after this source correction is the structural
// baseline for the current ownership model.
// session sa0400c379_r1 probes 9-10: splitting the result-byte declaration
// from its zero assignment and adding donor-era stdlib/string headers were
// both codegen duplicates. The retained natural source has exact ordered call
// and relocation parity; remaining drift is the broad VC5 prologue/frame and
// normal-path local/register basin (0x14 rebuilt frame versus 0x1c original),
// with the first mismatch at the entry register/home schedule.
// session shardB2-B9440 probe 1: captured draw_level and object_id locals
// through AddDrawNode; the typed local-liveness lead worsened the frame and
// structural diff, so the clean direct-global form is retained.
// session shardB6-B9440 probe 1: used a typed shared line-count local with
// branch-local subtraction for the Shape.cpp span-list gate; this follows the
// first non-prologue structural hunk and tests the donor-era branch topology.
// BINARY NOTE: 0056C780 returns with plain ret and has no arguments. Keep its
// call nested in AddDrawNode so the caller's two preceding pushes stay live.
// BINARY NOTE: the clipped mode tail uses the same mask/decrement switch shape
// as the unclipped tail; keep a switch instead of an if/else chain.
// session sa-7adcaa0c-r1 probes 1-20: volatile return storage, parameter and
// local scope/order, typed pointer surfaces, receiver aliases, aggregate-copy
// spelling, return labels, and ambient declarations did not close the frame.
// The reduced source keeps only the zero-argument helper ABI and switch changes.
// Remaining mismatch is the original 0x1c frame/register/home basin.
// No inline asm used; no accepted_drift proposal.
// session sa-fd1bceaa-r1 probes 1-8: sequential versus combined guards,
// Ghidra-style clipped-bound mutation and dispatch, self aliases, function-
// scope raw-bound locals, FShape fall-through, nested guards, and Windows RECT
// context were duplicate or worse. The pinned natural source is restored.
// These tests confirm 14/14 ordered calls and 0x14 rebuilt frame versus the
// original 0x1c frame; the next lead remains original local-home/register
// allocation, not ABI or behavior.
// continuation Shape-prefix audit: PDB locals ret_num, shape_y1, shape_x1,
// and rect were restored in declaration order. Bound-local order variants did
// not improve code. The ret_num stack home and 0x1c frame remain unresolved.
```
<!-- end-recovered:937d62ee68b6547dc43d -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

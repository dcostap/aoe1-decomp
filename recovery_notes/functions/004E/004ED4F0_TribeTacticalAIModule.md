# Recovery journal: 004ED4F0 `TribeTacticalAIModule`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.
- Earlier recovery note: `recovery_notes/functions/004E/004ED4F0_TribeTacticalAIModule.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:aab6636e7f826560e14e -->
### `target-session` `build/target_sessions/004ED4F0_TribeTacticalAIModule.json:1-37`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=5325; shape=84.92753623188406: Baseline: typed TacticalAIModule base with raw group/resource storage; frame and call count match, but entry vptr and source order differ at +2F.
probe 2 abi; result=MISMATCH; diff=5403; shape=84.91879350348027: Hypothesis 2: apply __declspec(novtable) to the derived constructor, based on the adjacent 004ED1C0 constructor whose oracle delays the derived vptr store.
probe 3 abi; result=MISMATCH; diff=5325; shape=84.92753623188406: Hypothesis 3: use the repository's canonical AIModule -> TacticalAIModule inheritance surface, not a flattened TacticalAIModule base; matching 00412B50 defines this hierarchy.
probe 4 liveness; result=MISMATCH; diff=5403; shape=84.91879350348027: Hypothesis 4: with novtable, add a plain initialized EH-state local to reproduce the original early [esp+3Ch] zero store without forcing volatility.
probe 5 liveness; result=MISMATCH; diff=5235; shape=84.92753623188406: Hypothesis 5: make the EH-state local volatile so VC5 must materialize its zero store near the constructor entry, testing whether that recovers [esp+3Ch].
probe 6 liveness; result=MISMATCH; diff=5403; shape=84.91879350348027: Hypothesis 6: reuse tempUD.data1 immediately after the base call, because the original reuses its entry temp home for the first EH state zero at [esp+3Ch].
probe 7 abi; result=MISMATCH; diff=5392; shape=66.5893271461717: Hypothesis 7: flatten the derived class and use placement construction for the proven 0xF0 TacticalAIModule prefix, avoiding VC5's automatic derived-vptr store while retaining a real base constructor call.
probe 8 control-flow; result=MISMATCH; diff=5508; shape=82.66666666666667: Hypothesis 8: use the donor-supported bounded for-loop form for the first duplicate scan, instead of an outer positive guard plus do-loop; this should remove the extra compare block.
probe 9 control-flow; result=MISMATCH; diff=5508; shape=82.66666666666667: Hypothesis 9: use a top-tested while loop with the bounded break, avoiding both the outer positive guard and the for-loop liveness shift; compare its CFG with the oracle. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=5461; shape=82.45109321058688: Hypothesis 10: remove the metric-steering volatile qualifiers from ManagedIntArray fields and test the natural four-int record surface against the loader loops.
probe 11 liveness; result=MISMATCH; diff=5320; shape=84.98550724637681: Hypothesis 11: retain volatility only on ManagedIntArray.value, testing whether pointer reloads alone explain the original indexed scan without extending scalar-field liveness.
probe 12 liveness; result=MISMATCH; diff=5458; shape=82.39355581127732: Hypothesis 12: keep only the scalar count fields volatile, testing whether forced count reloads reproduce the oracle better than pointer volatility.
probe 13 liveness; result=MISMATCH; diff=5450; shape=84.2748980780431: Hypothesis 13: make maximumSizeValue volatile as well, testing whether the oracle's repeated capacity reads require an explicit reload.
probe 14 behavior; result=MISMATCH; diff=5325; shape=83.8840579710145: Hypothesis 14: use unsuffixed period literals for every save_game_version gate, testing whether VC5's float-to-double comparison basin matches the source spelling in Ghidra.
probe 15 control-flow; result=MISMATCH; diff=5325; shape=84.92753623188406: Hypothesis 15: spell version gates with direct >= comparisons instead of negated <, testing the branch polarity and x87 condition basin across all save sections. [same emitted code as probe 3]
probe 16 abi; result=MISMATCH; diff=5325; shape=84.92753623188406: Hypothesis 16: invoke the explicit group constructor through a typed reference rather than a pointer, testing whether VC5 tracks the placement object's EH state while preserving its receiver LEA. [same emitted code as probe 15]
probe 17 abi; result=MISMATCH; diff=5325; shape=84.92753623188406: Hypothesis 17: omit the derived virtual-destructor declaration while retaining the proven TacticalAIModule base, testing whether VC5 then delays the derived vptr without novtable.
probe 18 abi; result=MISMATCH; diff=5325; shape=84.92753623188406: Hypothesis 18: mark only the TacticalAIModule base novtable, testing whether the base vtable context changes the derived entry store or call scheduling. [same emitted code as probe 16]
probe 19 flags; result=MISMATCH; diff=5331; shape=21.0431654676259: Hypothesis 19: switch this target from /O2 to /O1 while keeping /Oy and /GX, testing whether the old constructor basin uses size optimization.
probe 20 flags; result=MISMATCH; diff=5758; shape=66.40969162995594: Hypothesis 20: disable frame-pointer omission with /Oy-, testing whether the oracle's 0x24 frame and saved-register pattern require an EBP frame.
probe 21 liveness; result=MISMATCH; diff=5406; shape=84.86078886310905: Hypothesis 21: remove the source initialization of lastGroupRebalanceTime, whose target has no corresponding early store; test whether its dead assignment controls group-pointer scheduling.
probe 22 abi; result=MISMATCH; diff=5357; shape=63.91632771644393: Hypothesis 22: flatten the target, retain a novtable virtual surface, and placement-construct the proven TacticalAIModule prefix; this combines the EH-generating class with delayed derived vptr emission.
probe 26 abi; result=MISMATCH; diff=5920; shape=34.751381215469614: Hypothesis 1: give every ManagedIntArray its proven zeroing constructor and delete-and-zero destructor; natural subobject construction should reproduce the target's post-base zero stores and EH cleanup surface.
probe 28 abi; result=MISMATCH; diff=6098; shape=34.7705914870094: Hypothesis 2: add only the proven zeroing ManagedIntArray constructor, without destructor state; natural subobject construction may preserve the target's post-base zero stores without expanding EH cleanup.
probe 30 control-flow; result=MISMATCH; diff=5330; shape=84.92753623188406: Hypothesis 3: follow the decompiler and executable order by zeroing lastGroupRebalanceTime after the TacticalAIGroup constructor, not before it; this is a binary-supported source-order test.
probe 32 abi; result=MISMATCH; diff=5488; shape=83.84481760277939: Hypothesis 4: express the delayed group and ResourceItem lifetimes as natural placement construction in their proven inline storage, instead of explicit qualified constructor calls.
probe 34 abi; result=MISMATCH; diff=5123; shape=85.30092592592592: Hypothesis 5: model the proven inline TacticalAIGroup and ResourceItem as real members, and pair them with natural ManagedIntArray construction plus lastGroupRebalanceTime's member initializer; declaration order should reproduce the observed constructor sequence.
probe 35 liveness; result=MISMATCH; diff=5186; shape=82.82596209075244: Hypothesis 6: remove unsupported volatile qualifiers from the now-proven nontrivial ManagedIntArray surface; the exact destructor donor uses ordinary fields, and this may restore the original EH-state placement while keeping natural member construction.
probe 36 abi; result=MISMATCH; diff=5119; shape=85.35879629629629: Hypothesis 7: combine natural typed subobject construction with novtable and one explicit derived-vptr assignment at the binary-proven late point; test whether this reproduces the shipped delayed vptr without an early compiler store. Do not retain if policy rejects manual vptr plumbing.
probe 37 liveness; result=MISMATCH; diff=5123; shape=85.30092592592592: Hypothesis 8: restore the decompiler-proven local declaration order by placing iVar6 before the loop index and stack locals; declaration order can control VC5 home assignment without changing behavior. [same emitted code as probe 34]
probe 38 liveness; result=MISMATCH; diff=5219; shape=82.07926479035038: Hypothesis 9: retain volatile scalar counts but use the canonical nonvolatile ManagedIntArray value pointer from the exact destructor donor; test whether natural member construction preserves the loop reloads.
probe 39 liveness; result=MISMATCH; diff=5118; shape=85.30092592592592: Hypothesis 10: retain only the count volatility that affects the loader and use an ordinary desiredNumberValue field; the desired count is not read by this constructor.
probe 40 control-flow; result=MISMATCH; diff=5232; shape=80.71182548794489: Hypothesis 11: in the natural typed-member basin, use the donor-supported bounded for-loop for the first duplicate scan; this can preserve the original index-capacity test before the element compare.
probe 41 liveness; result=MISMATCH; diff=5186; shape=82.82596209075244: Hypothesis 12: keep only the value-pointer reload qualification and make both scalar counts ordinary fields; test whether the natural typed array surface still holds the original indexed scan topology. [same emitted code as probe 35]
probe 42 liveness; result=MISMATCH; diff=5180; shape=80.56516724336794: Hypothesis 13: name the first scan's one-time maximum-size read, matching the original's hoisted capacity load; test whether this natural cache preserves the index-capacity CFG.
probe 43 abi; result=MISMATCH; diff=5185; shape=82.82596209075244: Hypothesis 14: use the canonical AIModule-to-TacticalAIModule inheritance chain from the exact base constructor and adjacent source donors, while keeping the new natural inline-member model.
probe 44 liveness; result=MISMATCH; diff=5118; shape=85.30092592592592: Hypothesis 15: keep the natural nontrivial array members but spell their four zero stores in the constructor body, testing whether VC5 places the EH-state store before the first array field without changing the proven layout. [same emitted code as probe 39]
```
<!-- end-recovered:aab6636e7f826560e14e -->

<!-- recovered:25a45569ee4c9982c536 -->
### `3789ccb1ae1e` `src/scratch/004ED4F0_TribeTacticalAIModule.cpp:2-110`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004ED4F0 TribeTacticalAIModule::TribeTacticalAIModule(int,int)
// Source: taitacmd.cpp lines 1803-2027
// Ghidra-body compileable baseline. Not exact yet; intended as a fuller journey
// starting point than a hand-summarized skeleton.
// Attempt log:
// - 2026-05-04: replaced the earlier partial skeleton with the full Ghidra
//   approximated body (lines 1803-2027), adjusted just enough to compile as C++:
//   EH scaffolding removed, base/member ctors expressed via initializer list,
//   vtable store uses *(int*)this = 0x575788, and groups.next/prev modeled.
// - FLAGS: /GX retained for original EH-framed constructor
//   (config/flags/004ED4F0_TribeTacticalAIModule.rsp).
// - 2026-05-04 continued: original constructs groups/neededResources inside
//   the body after many stores, not in initializer-list order.  Switched those
//   members to raw storage and call their constructors manually in-body.
// - Stack-frame note: packet uses a 0x24 byte local area.  The Ghidra locals only
//   induced 0x20; a volatile padding local did not change VC5's allocation, so
//   this remains tied to the missing EH registration/state slot.
// - Switched the TacticalAIModule base to raw storage plus an explicit in-body
//   constructor call.  This better matches the original's source order (save this
//   in ESI, push file/player args, then call base ctor) and avoids C++'s forced
//   base-initializer scheduling.
// - Tried wrapping the body in __try/__finally to force FS:[0] setup.  It did
//   produce an EH-looking prologue, but with an EBP frame and much worse edit diff
//   (~103%), so rolled back.  A declared-but-undefined FakeDtor guard also did
//   not produce the original C++ EH registration sequence and slightly worsened
//   diff, so it is removed.  The dead `eh_state` local from Ghidra likewise had
//   no benefit after removing the guard, so it is gone.  The first 0x100 bytes are mostly aligned after
//   ignoring the missing 21-byte EH prefix; a local issue remains that VC5 hoists
//   ResourceItem's `push 4` before the final +0xD50..+0xD64 zero stores.
// - Marked ManagedIntArray::value volatile: this prevents VC5 from turning the
//   duplicate-scan loop into a single incrementing pointer walk.  The rebuilt
//   loop now reloads the array base for indexed comparisons, much closer to the
//   original `[base+eax*4]` family.  Marking numberValue and desiredNumberValue
//   volatile too (but not maximumSizeValue) improves the repeated list loader
//   substantially; current best is ~85.19% positional / ~60.77% edit.
// - Flag probes /O2 /GX, /O2 /Oy- /GX, /O1 /Oy /GX, and /O1 /GX produced the
//   same metrics; this is source/type/EH-context work, not a simple flag issue.
// - Rewriting equivalent bounds checks with the induction variable on the left
//   (`i >= max`, `i >= newMax`) is a small edit-diff win for all inlined list
//   loaders.
// - Comparing against the saved temp local (`local_28`) instead of the raw read
//   buffer (`local_2c`) is a larger win and better expresses the original's
//   store-to-local after each read.  Removing the no-op FakeDtor guard gave a
//   good baseline (~84.79% positional / ~57.98% edit).
// - Variant not kept: modeling full virtual inheritance/interface like smaller
//   matched AI ctors improves edit diff (~56.44%) but emits an early automatic
//   vptr store/zero after the base ctor and still no EH prefix; it contradicts
//   the packet where the TribeTacticalAIModule vptr is written much later at
//   004ED741.  Raw class + manual vptr remains the better positional baseline.
// - Variant not kept: making groups/neededResources real typed members with
//   destructors improved edit diff to ~66.93%, but forced their constructors to
//   run before the base ctor and before all zeroing, contradicting original order.
//   Keep raw storage as the behavioral/scheduling baseline unless a TU-context
//   trick can recover EH without auto-member construction.
// - Fixed one Ghidra-local artifact in the compileable body: old gatherer reads
//   now use tempUD.data4/data5 instead of uninitialized stack aliases. Duplicate
//   checks use the raw read buffer (`local_2c`) as in Ghidra/original asm; using
//   the saved add temp/local id instead produced the same current metrics.
//   Current validation after layout/FPU/list-predicate fixes: compiles cleanly,
//   84.95% positional / 55.95% edit.
// - Probe not kept: removing volatile from numberValue/desiredNumberValue worsened
//   the loader family (edit diff ~58.98%), so the earlier volatile surface stays.
// - Probe not kept: an explicit volatile `eh_state` local with byte writes at
//   the Ghidra EH-state transitions worsened edit diff (~58.84%) and still did
//   not recover the real FS:[0] registration prefix; rolled back.
// - Probe not kept: making maximumSizeValue volatile only slightly helped
//   positional diff but badly worsened edit diff (~68.91%), so max stays plain.
// - Corrected PlacementState/AttackState active offsets from type dumps and
//   changed the legacy-version clearing loops to raw dword zeroing.  This fixes
//   real field offsets (+0xF60/+0xFD4) and improves edit diff to ~56.54%.
// - Version gates use float literals for original dword FPU constants.  For
//   `constant <= save_game_version` gates, spelling as `!(save_game_version < C)`
//   preserves the original `test ah,1` branch family; direct `C <= save` emitted
//   `test ah,41h` and worsened the diff.  The 6.2/7.04 old-layout gates also
//   need the negated form to keep the read block before the zero-fill block.
// - Rewriting ManagedArray grow checks as `count > max - 1` instead of
//   `max + -1 < count` preserves the original jle-skip compare family and trims
//   edit diff slightly.
// - Natural-lifetime probe: made TacticalAIModule, TacticalAIGroup, and
//   ResourceItem typed bases/members, and moved their construction to the
//   initializer list. Removed the manual derived-vptr store. This is retained
//   as the one constructor-order test for the current session.
// - Kept the typed TacticalAIModule base but restored raw placement storage for
//   group/resource objects. This retained compiler EH setup, removed automatic
//   lifetime reordering, and improved the structural diff to 5325 bytes.
// - A novtable derived-class context removed the compiler's early vptr store,
//   but moved the first mismatch and worsened the structural diff. Rolled back.
// - Tested moving lastGroupRebalanceTime initialization after the explicit
//   Group constructor; it worsened the diff by 5 bytes and was rolled back.
// - Declaring the proven derived virtual destructor preserved the clean metrics
//   and improved one local alignment, but did not change the structural basin.
// - Removing the decompiler tempUD self-assignment shortened the function but
//   worsened the structural diff; restored the prior source.
// - 2026-08-17 claim pass: ran 22 distinct source, ABI, liveness, control-flow,
//   and flag probes. No probe reached exactness. The clean baseline remains
//   5325 differing bytes (90.9945%), 84.93% shape, 0x24 frame, and 104/104
//   ordered calls. The main blocker is the derived vptr store at +0x2F and the
//   missing original EH-state store at [esp+0x3C].
// - Evidence: __declspec(novtable), flattened placement construction, alternate
//   loop forms, scalar/pointer volatility axes, unsuffixed/direct version gates,
//   and /O1, /Oy- flag variants all remained nonexact. Restore the clean source
//   before further work. Next lead: recover VC5's original constructor EH state
//   and delayed derived-vptr scheduling without manual assembly.
// - 2026-08-22 claim pass: modeled ManagedIntArray as a natural zeroing,
//   delete-and-zero member; modeled groups and neededResources as their proven
//   inline objects. Declaration-order construction improved the clean diff from
//   5325 to 5186 bytes and moved the first mismatch from the prologue to the
//   late inline-object/vptr transition. The retained fields are nonvolatile;
//   volatile probes were metric-only and were removed.
```
<!-- end-recovered:25a45569ee4c9982c536 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

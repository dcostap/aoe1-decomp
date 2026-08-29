# Recovery journal: 0042A180 `StoreIncoming`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_hand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Com_hand.cpp`.
- Earlier recovery note: `recovery_notes/com_hand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8d6907faa0777b51ed3b -->
### `target-session` `build/target_sessions/0042A180_StoreIncoming.json:1-33`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=278; shape=99.30555555555556: Baseline current typed HOLDER reconstruction; exact call set and 99.31% shape, first structural mismatch at operator_new receiver formation.
probe 2 layout; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 1: replace indexed address-of with packet-base plus index; tests whether pointer formation preserves original mov base then add order. [same emitted code as probe 1]
probe 3 layout; result=MISMATCH; diff=411; shape=81.94444444444444: Probe 2: remove successful-slot pointer local and use repeated typed this->OnHold[i] accesses; tests whether original packet record ownership reloads base for new and copy.
probe 4 layout; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 3: express successful slot as byte offset with proven 0x18 stride; tests whether explicit packet stride recovers original base/offset register topology. [same emitted code as probe 2]
probe 5 liveness; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 4: separate successful-slot pointer local from duplicate-scan cursor; tests whether original uses distinct pointer lifetime and register color. [same emitted code as probe 4]
probe 6 liveness; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 5: assign successful-slot pointer inside operator_new argument; tests whether source evaluation order drives original base-load then offset-copy sequence. [same emitted code as probe 5]
probe 7 layout; result=MISMATCH; diff=279; shape=99.30555555555556: Probe 6: use the established OnHold cursor for successful Length assignment, matching decompiler pHVar9[uVar5] ownership; tests whether base expression controls pointer formation.
probe 8 abi; result=MISMATCH; diff=128; shape=96.52777777777777: Probe 7: keep the slot pointer for destination but read allocation length through direct packet indexing; tests argument ownership without changing later copy semantics.
probe 9 control-flow; result=MISMATCH; diff=343; shape=89.93288590604027: Probe 8: move slot-pointer assignment before Length store; tests whether VC5 scheduling then materializes original base-plus-offset sequence while preserving behavior.
probe 10 liveness; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 9: use a block-scoped successful-slot pointer declaration; tests whether shorter pointer lifetime changes the operator_new receiver basin. [same emitted code as probe 6]
probe 11 liveness; result=MISMATCH; diff=307; shape=98.61111111111111: Probe 10: restore the binary-observed Length cursor as a typed uint pointer with six-word stride; tests whether its live address controls successful record pointer formation.
probe 12 liveness; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 11: use a block-scoped HOLDER reference for the successful slot; tests whether reference aliasing selects the original pointer register topology. [same emitted code as probe 10]
probe 13 context; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 12: add period-supported stdlib header beside string.h; tests whether VC5 front-end context selects the original register basin. [same emitted code as probe 12]
probe 14 abi; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 13: use natural new char[] allocation instead of the reviewed operator_new declaration; tests whether source allocation syntax recovers the call ABI.
probe 15 context; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 14: restore HOLDER as a class with declared period constructor/destructor surface; tests whether non-POD type context changes pointer indexing codegen. [same emitted code as probe 14]
probe 16 layout; result=MISMATCH; diff=351; shape=87.83783783783784: Probe 16: use one established HOLDER cursor for both successful Length store and slot address; tests whether common owner expression controls the original pointer formation.
probe 17 layout; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 17: materialize a proven byte offset before successful slot formation; tests whether explicit offset ownership recovers original EAX base plus EBX offset sequence. [same emitted code as probe 15]
probe 18 liveness; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 18: mark the loop index register; tests whether explicit index register intent selects original offset/base register colors. [same emitted code as probe 17]
probe 20 layout; result=MISMATCH; diff=351; shape=87.83783783783784: Probe 1: advance the typed OnHold cursor with h += i after the Length store; tests whether natural cursor ownership recovers the original base-plus-offset allocation form.
probe 22 layout; result=MISMATCH; diff=279; shape=99.30555555555556: Probe 2: use the established typed packet cursor for Length and advance it with natural pointer addition; tests the original pHVar9 ownership form without raw offsets.
probe 24 liveness; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 3: swap the typed cursor and loop-index declarations; tests whether natural declaration order controls the original allocation pointer register map. [same emitted code as probe 19]
probe 26 layout; result=MISMATCH; diff=278; shape=99.30555555555556: Probe 4: reverse the valid typed pointer-add operands in the successful slot formation; tests whether expression operand order controls the original base/offset register sequence. [same emitted code as probe 24]
probe 29 layout; result=MISMATCH; diff=128; shape=96.52777777777777: Probe A: read the allocation length through direct this->OnHold[i].Length, the natural packet-backed form from the earlier closest structural basin; tests whether reload ownership recovers original slot-pointer schedule.
probe 31 layout; result=MISMATCH; diff=278; shape=99.30555555555556: Probe B: form the successful slot as natural typed pointer addition this->OnHold + i; tests whether the original pHVar9 ownership produces its base-load/copy/add schedule without raw cursors. [same emitted code as probe 28]
probe 33 context; result=MISMATCH; diff=278; shape=99.30555555555556: Probe C: restore the PDB-proven HOLDER class surface (fromPlayer field, Store(char*,uint), Clear, constructor, destructor); tests whether original header context affects this function's VC5 register basin without inventing layout. [same emitted code as probe 31]
probe 34 context; result=MISMATCH; diff=278; shape=99.30555555555556: Probe D: use PDB-proven parameter names SerialNumber, InBuff, Length, dcoFromID, dcoReceiveID; tests whether canonical source spelling changes VC5 scheduling or only confirms naming is codegen-neutral. [same emitted code as probe 33]
probe 35 variant; result=MISMATCH; diff=278; shape=99.30555555555556: variant lab build\variant_lab\0042A180_StoreIncoming\20260817_123624: 5 variants, 0 invariant-eligible, 0 exact
probe 36 liveness; result=MISMATCH; diff=351; shape=87.83783783783784: Probe E: retain a typed OnHold base alias for the successful slot, then form h = base + i; tests whether separate base ownership produces the original mov-base, copy-offset, add-slot sequence without raw addressing. [same emitted code as probe 16]
probe 38 layout; result=MISMATCH; diff=279; shape=99.30555555555556: Probe F: assign the successful record Length through the established typed h[i] base, matching the decompiler's pHVar9[uVar5] ownership; tests whether first-store ownership controls later slot register coloring. [same emitted code as probe 22]
probe 40 liveness; result=MISMATCH; diff=183; shape=97.22222222222223: Probe G: initialize the typed OnHold pointer at declaration, matching a natural local initialization form; tests whether declaration initialization changes only front-end liveness or the successful-slot register sequence.
probe 42 layout; result=MISMATCH; diff=343; shape=89.93288590604027: Probe H: form the successful slot pointer before the Length store while keeping the typed field access; tests whether VC5 schedules the proven store-before-slot bytes from a different natural statement order.
probe 44 liveness; result=MISMATCH; diff=278; shape=99.30555555555556: Probe I: keep the scan base h live and use a separate typed slot = this->OnHold + i for allocation/copy, while retaining indexed final stores; tests whether original base/index and slot-pointer lifetimes are distinct. [same emitted code as probe 35]
probe 49 context; result=MISMATCH; diff=278; shape=99.30555555555556: Probe J: compile StoreIncoming after the real com_hand_tu wrapper and complete handler context, without config edits; output stayed in the 415-byte 278-diff basin, so wrapper context is not the allocation-order blocker.
```
<!-- end-recovered:8d6907faa0777b51ed3b -->

<!-- recovered:58bea7b176f110bef8e4 -->
### `2b076d14a9b9` `src/scratch/0042A180_StoreIncoming.cpp:1-48`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0042A180 TCommunications_Handler::StoreIncoming
// Com_hand.cpp lines 3237-3305
// Attempt log:
// 1: natural indexed source: comparable full-size output, but prologue/registers wrong (len in EDI, this in EBP); pos 77.9376%, edit 79.3765%.
// 2: explicit self/length locals and pointer-walk scans worsened; duplicate case returned inline and edit diff >116%.
// 3: declarations delayed until after zero-length log: no prologue improvement; still this=EBX/len=EDI and duplicate inline.
// tried flags /O2 no-/Oy, /Ox, /Ob0: same; /O1 too short.
// session: canonical TDebuggingLog member surface plus memcpy restored REP MOVSD/MOVSB,
// exact prologue/first scans, unsigned jbe/jb bounds, and 99.31% shape. The only
// remaining codegen hunk is the cold full-table base/offset register coloring (+2B).
// left in scratch: behavior modeled, but VC5 standalone register allocation won't produce original len=EBX, this=EDI, late duplicate handler; broad drift, not accepted_drift-safe.
// Follow-up: reordered the cold zero assignments to match xor EBP then EBX and used the
// direct OnHold base expression; this reduced the positional diff from 111 to 109 bytes.
// A direct Length predicate reduced the metric to 96 bytes but changed the exact log-argument
// schedule, so it was rolled back. The current source keeps the natural named scan cursor.
// Main-agent audit replaced both byte-offset HOLDER cursors with typed indexing
// and pointer iteration. Keep canonical 0x18-byte record ownership in scratch.
// Follow-up: direct typed OnHold Length assignment improves the indexed store
// encoding by one byte; separate typed entry/base pointers are compiler duplicates.
// Direct repeated field accesses destroy the earlier CFG, so the simple HOLDER
// entry form remains. Do not reintroduce byte-offset cursors for the cold report.
// Readiness audit found that each cold-report iteration must reload OnHold after
// Log returns. This preserves replacement or invalidation by the callback.
// Follow-up: packet-backed `this->OnHold + i` assignment matched the original
// pHVar9 form but emitted duplicate code; restored the indexed spelling.
// Assigned pass sa-e4d2a8b8, 2026-08-16: baseline retained at 415 bytes, 144
// instructions, 99.31% shape, six ordered calls, and 278 positional diff bytes.
// Probes 1, 3-5, 9, 11-14, 17-18 produced the same code or the same basin.
// Probe 2 repeated typed member access caused a 436-byte control-flow basin.
// Probe 6 used the scan cursor for Length and worsened one store byte.
// Probe 7 reduced diagnostic diff bytes to 128 but changed the cold loop basin.
// Probe 8 moved pointer setup before Length and broke the prologue and CFG.
// Probe 10 used a raw-style Length cursor and added a loop branch.
// Probe 15 failed qualification because volatile OnHold needed unsafe casts.
// Probe 16 reused the scan cursor for the successful slot and broke the frame.
// Natural `new char[]` and the declared HOLDER class are codegen-identical and
// remain the simplest period-plausible source. The remaining mismatch is local
// register and SIB-base coloring around allocation and final record stores.
// Revisit pass sa-b719bbdc-r1, 2026-08-17: restoring a typed cursor with `h += i`
// broke the prologue and CFG. Using `h[i].Length` with typed pointer addition,
// swapping declaration order, and reversing the valid pointer-add operands all
// stayed in the clean basin or worsened it. Keep the pinned typed packet source.
// Revisit pass sa-bce60210-r1, 2026-08-17: PDB type records confirm HOLDER's
// fromPlayer field and Store/Clear member surface; restoring them and using the
// PDB parameter names was codegen-neutral. Natural slot-pointer, reference,
// direct-length, declaration, and base-alias forms did not recover the two-byte
// allocation hunk. A five-variant typed slot family also found no exact result;
// separate slot locals entered a worse prologue basin. Keep this natural source.
```
<!-- end-recovered:58bea7b176f110bef8e4 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

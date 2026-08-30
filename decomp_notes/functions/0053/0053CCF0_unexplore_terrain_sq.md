# Function notes: 0053CCF0 `unexplore_terrain_sq`

Module notes: `decomp_notes/visible.md`.

## Recovered attempt history

<!-- recovered:331b34e1e50d72ba23ee -->
### `target-session` `build/target_sessions/0053CCF0_unexplore_terrain_sq.json:1-36`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=361; shape=64.4927536231884: Clean scratch candidate: canonical visible-map layout and natural paired unexplore loop; establish baseline metrics.
probe 2 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: define self after the logging call and use direct this for logging to preserve a later self local; test whether VC5 keeps the original local-c home. [same emitted code as probe 1]
probe 4 layout; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: remove the artificial self alias and use direct this expressions throughout; test whether natural ownership restores the oracle's EBP/local-home topology. [same emitted code as probe 2]
probe 5 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: keep a distinct map-owner alias only for the late mask update; test whether a branch-local use forces the oracle's spilled self home. [same emitted code as probe 4]
probe 7 control-flow; result=MISMATCH; diff=361; shape=65.21739130434783: Hypothesis: use an explicit row cursor initialized after clamping; this tests the prior row-local lead against the target's parameter-home loop topology.
probe 9 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Diagnostic hypothesis: take the self alias address through a pointer-to-pointer, which can force a real stack home without volatile memory semantics; test against the proven local-c spill. [same emitted code as probe 5]
probe 11 liveness; result=MISMATCH; diff=366; shape=64.4927536231884: Diagnostic only: force the checksum through p6's address with a volatile home, matching the target's observed p6 store/reload; do not retain without exact, policy review.
probe 13 control-flow; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: invert suppression into an early return and remove the outer success block; test whether source nesting selects the target frame and branch layout. [same emitted code as probe 9]
probe 15 context; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: restore visible.cpp's preceding LOS table declarations before this method; test whether VC5 translation-unit front-end context selects the oracle basin. [same emitted code as probe 13]
probe 17 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: bind the row traversal to a reference alias of y1; this may naturally force the unconditional y1 parameter-home store seen before the row loop. [same emitted code as probe 15]
probe 19 abi; result=MISMATCH; diff=361; shape=64.4927536231884: Diagnostic hypothesis: mark x1 register to test whether VC5 selects the oracle's EDI coordinate color and spills the other inputs naturally. [same emitted code as probe 17]
probe 21 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: reverse declaration order of tile and self to match the oracle's -0x8 self and -0x4 tile slot order; test VC5 local coloring. [same emitted code as probe 19]
probe 24 baseline; result=MISMATCH; diff=361; shape=64.4927536231884: Recheck pinned natural typed traversal before new ownership-context hypotheses. [same emitted code as probe 23]
probe 25 layout; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: restore the proven RGE_Map prefix and typed map ownership before map_row_offset, which may recover the original VC5 register basin without changing terrain traversal. [same emitted code as probe 24]
probe 27 control-flow; result=MISMATCH; diff=360; shape=63.768115942028984: Hypothesis: express the natural outer terrain-row traversal as a top-tested while loop, which may select the oracle's late row-update block without changing behavior.
probe 29 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: split the natural tile declaration from its zero assignment, which may alter local lifetime and recover the oracle's saved tile/self homes. [same emitted code as probe 25]
probe 31 layout; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: use a typed RGE_Visible_Map reference for the owner, preserving direct map and terrain field ownership while testing whether reference lowering recovers the oracle's saved-this color. [same emitted code as probe 29]
probe 33 layout; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: express row ownership with typed two-dimensional indexing and address-of, which may recover the oracle's row-base and x-offset instruction order. [same emitted code as probe 31]
probe 35 abi; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: restore the normal C++ declaration used by the exact visible.cpp log_map_call donor, rather than the prior C-linkage spelling.
probe 38 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Natural outer cursor/count declarations and direct this ownership mirror the original source-level locals; test whether this recovers the saved-this EBP basin. [same emitted code as probe 37]
probe 42 control-flow; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: spell upper clamps as assignment followed by decrement, matching original DEC plus parameter-home store rather than compiler LEA lowering. [same emitted code as probe 41]
probe 44 context; result=MISMATCH; diff=361; shape=64.4927536231884: Hypothesis: visible.cpp's likely stdio context changes VC5 front-end state enough to recover the EBP/local-home basin without changing the function model. [same emitted code as probe 42]
probe 47 context; result=MISMATCH; diff=361; shape=64.4927536231884: Temporary full visible.cpp group with PDB-ordered exact anchors. Default preserves anchors and emits 368/381 with 361 diff; /Oy- gives 381/381 with 354 diff but invalidates all anchors. [same emitted code as probe 46]
probe 51 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Natural source-model probe: declare tile before self and assign both before the direct logger call, matching original PDB local initialization order without fake storage.
probe 53 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Natural mixed-receiver probe: use direct this only for log_map_call, then keep the named self for checksum and map writes. This tests call-site receiver scheduling without changing behavior or fault order. [same emitted code as probe 50]
probe 54 control-flow; result=MISMATCH; diff=361; shape=64.4927536231884: Natural positive-bounds guard probe: preserve the same signed rejection and clamp behavior while testing the executable's nested-success layout and shared late return. [same emitted code as probe 53]
probe 55 liveness; result=MISMATCH; diff=366; shape=65.21739130434783: Diagnostic natural aggregate probe: keep self and tile in one typed local state to test the original two local homes. Retains pointer widths, visibility writes, unconditional tile advance, and fault order.
probe 56 liveness; result=MISMATCH; diff=371; shape=64.4927536231884: Diagnostic address-taken aggregate probe: use a pointer to the typed self/tile state to test whether a natural local address forces the original EBP frame.
probe 57 abi; result=MISMATCH; diff=361; shape=64.4927536231884: Natural const-pointer alias probe: constrain self rebinding while preserving the same owner, writes, calls, and partial-map behavior. [same emitted code as probe 54]
probe 58 layout; result=MISMATCH; diff=361; shape=64.4927536231884: Natural mixed-owner probe: retain self only for logger receiver, then use direct this for checksum, bounds, map, tile, and mask ownership. This tests the binary's repeated self/map rereads without caching. [same emitted code as probe 57]
probe 59 context; result=MISMATCH; diff=361; shape=64.4927536231884: Context family: 128 ambient file-scope declaration samples under the current visible.cpp header and default /O2 /Oy all emitted one 356-byte group; no declaration-state basin or EBP frame appeared. Generated lab: build/variant_lab/0053CCF0_unexplore_terrain_sq/20260823_192451.
probe 60 behavior; result=MISMATCH; diff=361; shape=64.4927536231884: Natural direct-this reconstruction: remove the redundant self alias and use direct this ownership for logger, checksum, bounds, map, tile, and mask operations. This is behavior-correct and preserves all observed writes and fault order. [same emitted code as probe 58]
probe 64 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: Test a natural reference alias for the mutable p6 checksum to preserve the observed parameter-home store/load pair and callee-saved pressure; verify whether it recovers the original EBP/self/tile topology. [same emitted code as probe 63]
probe 66 abi; result=MISMATCH; diff=361; shape=64.4927536231884: Natural x2/y2 parameter-home reference aliases were codegen-identical at 356 bytes, 361 diff, no EBP frame; direct check completed before session-lock timeout. [same emitted code as probe 64]
probe 68 liveness; result=MISMATCH; diff=354; shape=79.71014492753623: A 24-variant VC5 source lab crossed self initialized/split/register/cast, tile initialized/split, and checksum parameter/named/reference shapes. All 24 emitted one 356-byte group with no frame; declaration and checksum lifetime axes are exhausted as a blocker.
probe 69 liveness; result=MISMATCH; diff=361; shape=64.4927536231884: A diagnostic pointer to the p6 parameter home and explicit dereferences did not alter the 356-byte default group; no natural parameter-home address-taking cause was established.
```
<!-- end-recovered:331b34e1e50d72ba23ee -->

<!-- recovered:045e34ebaba75f80e172 -->
### `b2d987a352e2` `src/scratch/0053CCF0_unexplore_terrain_sq.cpp:1-67`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0053CCF0 RGE_Visible_Map::unexplore_terrain_sq
// Source: visible.cpp lines 891-975
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map layout and the natural
// paired unexplore loop; tile advances are unconditional as in the executable.
// self alias plus absolute global surfaces improved relocation/edit alignment but
// did not change the default emitted structure.
// /Oy- reproduced the 381-byte size and moved the frame/register basin closer,
// but still lacked the original two-slot frame and was rolled back as a flag crutch.
// Named width/height and negative-return/control-flow variants were nonproductive.
// Typed unified_map_offsets[256] and full visible.cpp world/player/map/tile record
// surfaces were emitted identically to the clean candidate. A separate typed
// checksum accumulator was likewise optimized to the same code.
// A natural start-column local reached exact size but retained the wrong register
// basin (339 positional bytes); a start-row local improved edit/resync similarity
// to 59.06% and 354 positional bytes, yet still omitted the original EBP frame and
// parameter-home topology. Delaying the self owner made no further change.
// Those source-shape experiments were diagnostic only and were restored.
// This session: hoisted row cursors, reused a function-scope inner count, and
// added string.h context; each emitted the clean 356-byte code unchanged.
// An ordinary self/reference alias for the late mask reload was likewise
// optimized away. A contiguous typed self/tile local aggregate forced an 8-byte
// stack allocation and a 363-byte result but not the oracle's EBP frame, and
// reversing its member order plus old-TU top-level scan locals was unchanged;
// those layout probes were restored.
// Direct this-member ownership in the coordinate loop, guided by the binary's
// saved this while EBX is reused for tile access, was codegen-identical and
// restored; the persistent alias is not the EBP/local-home cause.
// This claim tested post-call self setup, a pointer-to-pointer self home,
// visible.cpp LOS declarations, inverted suppression nesting, a y1 reference,
// x1 register qualification, and local declaration order. All natural probes
// were codegen duplicates; the row-cursor probe changed structure but not the
// frame basin and was restored. A volatile p6 home was diagnostic only and was
// also restored. The next useful evidence is a donor-level VC5 TU or ABI
// context that explains the original EBP/local-home allocation.
// Revisit claim: restoring the proven RGE_Map prefix, splitting the tile zero
// declaration, using a typed owner reference, typed row indexing, and normal
// C++ linkage for log_map_call all emitted the clean 356-byte basin unchanged.
// An explicit outer while loop reached 360 bytes but changed the CFG and still
// lacked the oracle frame, so it was restored. Typed map ownership and the
// natural paired row/column traversal remain authoritative.
// Left in scratch: default code is 25 bytes short with broad prologue/register
// drift; canonical behavior and field ownership are stable, but source/ABI context
// still needs a donor-level explanation for the original EBP/local topology.
// Current claim: assignment-then-decrement upper clamps and a stdio include were
// codegen duplicates. The original EBP frame and separate self/tile homes remain.
// Authentic TU context gate (proved unless marked otherwise): PDB module is
// C:\\msdev\\work\\age1_x1\\visible.cpp. This owner occupies source lines
// 891-975, with the ordered bands 891, 902, 905, 909, 913-924, 927, 931-940,
// 943-975. Its address sequence is 0053CCF0-0053CE6A; the next visible.cpp
// owner begins at 0053CE70. The class owner is RGE_Visible_Map and the exact
// symbol is ?unexplore_terrain_sq@RGE_Visible_Map@@QAEXHHHHHH@Z with __thiscall
// cleanup ret 18h. Anchors are the visible_tu.cpp include at this address,
// visible_tu_context.h's RGE_Visible_Map layout, direct log_map_call at
// 0053CD30 -> 0053D150, and the observed accesses to this+04/+08/+0C/+14/
// +18/+34 plus map_offsets, unified_map_offsets, and map_row_offset. The
// neighboring address order 0053C6F0, 0053C920, 0053CAC0, 0053CCF0, 0053CE70
// proves one contiguous visible.cpp source band. Any source-order explanation
// for the EBP/local-home difference remains unknown; no dummy context is used.
// Resume probes: splitting self/tile declaration from assignment was a codegen
// duplicate (356 bytes, 361 strict differences, no frame). A const-qualified
// self pointer was also a codegen duplicate with the same metrics. Both failed
// experiments were restored to the pinned natural source.
// Accepted-drift audit: do not promote this candidate. The original has an
// 0x08 local frame at log_map_call, while the rebuild has none. The logger
// therefore receives a different stack and exception context before any map
// checksum or visibility update.
```
<!-- end-recovered:045e34ebaba75f80e172 -->

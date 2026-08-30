# Function notes: 0053C6F0 `explore_terrain`

Module notes: `decomp_notes/visible.md`.

## Recovered attempt history

<!-- recovered:ef81ff546bfd8d412226 -->
### `target-session` `build/target_sessions/0053C6F0_explore_terrain.json:1-32`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 control-flow; result=MISMATCH; diff=457; shape=86.86868686868686: Test the source-plausible positive suppression guard: if (Map_Update_Suppresion == 0) body; return Revealed. Original cmp-zero sequence and body/fallback layout support this form.
probe 2 control-flow; result=MISMATCH; diff=457; shape=83.49514563106796: Refine positive suppression guard with explicit in-body return Revealed and post-guard return 0, matching the oracle's separate zero-return epilogue and body return.
probe 5 liveness; result=MISMATCH; diff=531; shape=83.41463414634147: Test a natural early curVisPlayer initialization. The oracle carries a zero in ECX from suppression through the ally test while delaying the curVisPlayer home store; this tests whether declaration lifetime explains that zero without fake steering.
probe 7 control-flow; result=MISMATCH; diff=468; shape=83.57487922705315: Test default-zero ally visibility followed by a positive curPlayer guard. This is a natural equivalent of the if/else and tests the oracle's explicit zero-plus-setcc branch bands.
probe 11 control-flow; result=MISMATCH; diff=466; shape=90.9090909090909: Restore the natural zero-valued checksum local before suppression comparison. Original emits xor ecx,ecx followed by cmp eax,ecx; test whether the local source form recovers the first structural hunk without changing ownership. [same emitted code as probe 10]
probe 12 control-flow; result=MISMATCH; diff=466; shape=90.9090909090909: Compare suppression against the already-zero Revealed result instead of a dead checksum local. This tests whether the oracle xor/cmp zero register comes from the live result variable and preserves the original suppression branch shape naturally. [same emitted code as probe 11]
probe 14 liveness; result=MISMATCH; diff=466; shape=90.9090909090909: Bind the checksum player read to a short-lived local, then keep the later ally expression as this->player. This tests the binary-proven player-pointer reread while retaining natural ownership and checks whether the local lifetime recovers the checksum spill. [same emitted code as probe 12]
probe 16 liveness; result=MISMATCH; diff=466; shape=90.9090909090909: Bind this->player immediately before the ally-id read and use that local only in the ally predicate. This tests a natural fresh ownership read at the binary's reload point without changing calls or control flow. [same emitted code as probe 14]
probe 18 liveness; result=MISMATCH; diff=466; shape=90.9090909090909: Move checksum declaration beside curVisPlayer, matching the observed reuse of the checksum home for the later player pointer. Test whether declaration scope/order makes VC5 spill the checksum and reuse that home naturally. [same emitted code as probe 16]
probe 20 control-flow; result=MISMATCH; diff=466; shape=90.9090909090909: Feed the suppression comparison from the live zero result (checksum = Revealed), rather than a literal or dead zero. This tests whether a natural data dependency keeps ECX zero for the oracle cmp while preserving early-return behavior. [same emitted code as probe 18]
probe 22 liveness; result=MISMATCH; diff=466; shape=90.9090909090909: Scope the checksum local inside the successful suppression body, matching its first PDB use after the guard and its short lifetime before ally lookup. Test whether block scope recovers the oracle parameter-home spill and local-home reuse without scaffolding. [same emitted code as probe 20]
probe 24 layout; result=MISMATCH; diff=466; shape=90.9090909090909: Complete RGE_Game_World with the binary-proven map member at +0x28 while preserving players at +0x40. This tests canonical world ownership and old-TU type context for the hash and ally scheduling. [same emitted code as probe 22]
probe 26 liveness; result=MISMATCH; diff=477; shape=86.40776699029126: Initialize the clipped-radius source local before Revealed and the log call, matching Ghidra's observed param_3 copy at function entry. Test whether this earlier lifetime controls the oracle checksum and parameter-home allocation.
probe 29 context; result=MISMATCH; diff=466; shape=90.9090909090909: Temporary full visible.cpp group with PDB-ordered exact anchors 0053C400/0053C490/0053C4D0. Default /O2 /Oy preserves all anchors; target is 571/546 with 555 diff. /Oy- target is 528/546 with 466 diff but invalidates all anchors. [same emitted code as probe 28]
probe 32 variant; result=MISMATCH; diff=555; shape=64.14141414141415: Manual /Oy- hypothesis: remove checksum local and xor p6 directly with this->player->id. Custom compile reached 528 bytes and 474 strict positional diff versus clean 527/466; not retained.
probe 33 liveness; result=MISMATCH; diff=555; shape=64.14141414141415: Manual /Oy- hypothesis: declare curPlayer before checksum to test VC5 local color and early player load. Custom compile stayed 528 bytes and 474 strict diff, farther than clean 527/466; not retained.
probe 34 liveness; result=MISMATCH; diff=555; shape=64.14141414141415: Manual /Oy- hypothesis: put checksum player read in a nested short-lived pointer scope, then use direct this->player for ally lookup. Custom compile stayed 528/474, so scope did not alter the basin; not retained.
probe 35 liveness; result=MISMATCH; diff=555; shape=64.14141414141415: Manual /Oy- hypothesis: move checksum declaration into the successful suppression body and initialize it at the player-id read. Custom compile stayed 528/474; no basin change, not retained.
probe 36 liveness; result=MISMATCH; diff=555; shape=64.14141414141415: Manual /Oy- hypothesis: declare curVisPlayer before checksum so the early checksum can reuse its later stack home. Custom compile stayed 528/474; declaration order did not change this basin.
probe 37 control-flow; result=MISMATCH; diff=555; shape=64.14141414141415: Manual /Oy- hypothesis: use one positive suppression guard and fall through to Revealed, mirroring the binary je-to-body block. Typed shared-header source built 522 effective bytes and 469 raw positional differences; worse than clean custom 529/475 raw, not retained.
probe 38 liveness; result=MISMATCH; diff=555; shape=64.14141414141415: Manual /Oy- hypothesis: reverse source assignments of checksum and input_csum to test VC5 load scheduling. Emitted object was byte-identical to clean custom baseline; no source-order effect, not retained.
probe 39 context; result=MISMATCH; diff=555; shape=64.14141414141415: Manual context hypothesis: add period <stdlib.h> before the shared visible header. VC5 rejected the duplicate _rotl declaration with C2733/C2668, so this context cannot be used without a forbidden shared-header edit; source restored.
probe 40 control-flow; result=MISMATCH; diff=555; shape=64.14141414141415: Manual /Oy- hypothesis: compare suppression against the live zero-valued Revealed/checksum local to preserve the oracle xor/cmp zero register. VC5 optimized both forms to the clean test/jump basin (529-byte section, 475 raw diff); not retained.
probe 43 liveness; result=MISMATCH; diff=555; shape=64.14141414141415: Natural source-shape probe: moved checksum player alias and LOS/coordinate locals into semantic scopes, mutated radius directly, and kept tile initialized before row traversal. VC5 emitted byte-identical 571-byte default /Oy basin; no frame, reload, or malformed-coordinate change. Restored. [same emitted code as probe 41]
probe 44 context; result=MISMATCH; diff=466; shape=90.9090909090909: Compiler-context probe: scoped period VC5 pragma optimize y off around explore_terrain. This restores the oracle EBP frame and saved-register set, reducing code to 527 bytes with 466 strict differences and 90.91% shape; all 3 calls and owner remain aligned. It is not yet authentic evidence for vis_unit.cpp and remains only while testing source recovery.
probe 45 context; result=MISMATCH; diff=466; shape=90.9090909090909: Authentic vis_unit.cpp context audit: replacing target owner with the historical standalone 20260817 source under scoped /Oy- was rejected by the registered visible.cpp wrapper. The wrapper already declares LOSTBL, RGE_Tile_List, RGE_Player, RGE_Game_World, RGE_Tile, RGE_Map, RGE_Visible_Map, _rotl, and stdlib, causing C2011/C2668/C2733 conflicts. This proves vis_unit.cpp is a different PDB module and cannot be used as target context without unsupported shared/config edits; source restored.
probe 46 control-flow; result=MISMATCH; diff=466; shape=90.9090909090909: Suppression comparison probe: compared Map_Update_Suppresion against the live Revealed zero local instead of literal zero. Under scoped /Oy- VC5 optimized this to the same 527-byte test/equal-466 basin; it did not recover the oracle xor/cmp or cleanup order. Restored literal suppression guard. [same emitted code as probe 44]
probe 47 liveness; result=MISMATCH; diff=466; shape=90.9090909090909: Zero-local probe: initialized a dedicated zero local and compared suppression against it. VC5 optimized it to the same 527-byte scoped-/Oy- test basin, so it cannot explain the oracle xor/cmp zero register. Restored.
probe 48 control-flow; result=MISMATCH; diff=457; shape=86.86868686868686: Suppression CFG family probe: changed to positive Map_Update_Suppresion == 0 body with explicit else return 0, preserving fault order and two returns. Scoped /Oy- reached 531 bytes, two returns, 457 positional bytes, but widened edit cost and retained wrong zero guard. The implicit positive body variant was 520 bytes with one return and the same 457 strict diff; both are rejected and source will restore the original early return.
probe 49 liveness; result=MISMATCH; diff=466; shape=90.9090909090909: Checksum lifetime probe: declared checksum after the p6 input read inside the successful path, matching the line-band initialization site. This changed 17 body bytes but stayed in the 527/466 default scoped-/Oy- basin and moved the late call-tail farther. The top-scoped checksum source is restored. [same emitted code as probe 46]
probe 50 abi; result=MISMATCH; diff=467; shape=90.9090909090909: Player-read ordering probe: bound a fresh visibilityPlayer = this->player after publishing input_csum, then used it for mutualAlly indexing. VC5 retained the initial player pointer and changed the hash topology, reaching 529 bytes and 467 strict diff; it did not restore the proven post-publication reload. Restored direct source form.
probe 51 liveness; result=MISMATCH; diff=466; shape=90.9090909090909: Radius-home probe: mutated the incoming radius directly before LOS selection instead of using radius_value, matching the original ESI clamp and narrow parameter reuse. Under scoped /Oy- emitted the same 527/466 code basin; restored named radius_value for current clean source. [same emitted code as probe 49]
```
<!-- end-recovered:ef81ff546bfd8d412226 -->

<!-- recovered:7259010d823942be83ad -->
### `f34d90e6a2ad` `src/scratch/0053C6F0_explore_terrain.cpp:1-57`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0053C6F0 RGE_Visible_Map::explore_terrain
// Source: visible.cpp lines 521-658
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map ownership and the
// natural paired explore/unexplore loops.
// External LOS/unified-map declarations recover the same-TU register/local basin;
// the remaining mismatch is the checksum spill/suppression compare and a short
// late-loop schedule.  A polymorphic full-class context was codegen-neutral.
// Default /O2 /Oy was tested and regressed to 571 bytes/64.1% shape; retain the
// existing narrow /Oy- donor-context flag while this target remains unresolved.
// Main-agent audit replaced raw absolute globals and byte tile cursors with
// canonical symbols and typed map/tile ownership.
// Binary symbol evidence confirms unified_map_offsets is unsigned long*[] and
// NormalLOS/SquareLOS are LOSTBL*[]; typed those globals/locals and the complete
// RGE_Tile/RGE_Map layout without changing emitted instructions. Making tile advance
// unconditional, as the oracle's post-store stride proves, improved the typed source
// to 466 positional bytes / 90.91% shape / 85.16% resync similarity.
// A radius_value local was source-plausible but codegen-neutral; a positive
// suppression-success wrapper worsened CFG and was rolled back. Remaining drift
// starts at the zero-register suppression cmp (oracle xor/cmp versus rebuilt test)
// and the checksum parameter-home spill; no raw byte cursor is retained.
// Follow-up probes: wrapping the full success body in the binary je-to-body
// guard reproduced the prior 457-byte basin and was restored. Direct player-id
// hashing, an unsigned checksum accumulator, local declaration reordering, and
// a dedicated zero guard local were all emitted-code duplicates of the clean
// source. The new blocker lead is therefore the old-TU local-lifetime/context
// split that spills checksum to [ebp-14] and reuses the p6 home; do not retain
// artificial stack or volatile steering.
// Revisit probes: an explicit in-body Revealed return preserved the two-return
// CFG but stayed in the 457-byte basin; an early curVisPlayer initializer
// regressed to 531 bytes. A default-zero ally guard reached 468 bytes and was
// also restored. The canonical typed source remains the clean owner.
// Accepted-drift audit: do not promote this candidate. Before the ally lookup,
// the original reloads this->player after publishing input_csum. The rebuild
// reuses the player pointer read during checksum calculation. Concurrent player
// pointer mutation can therefore change the ally test and later tile-list call.
// Current claim probes: zero-valued guard locals, fresh player aliases, checksum
// declaration scope/order, and a complete world map member all rebuilt the same
// 527-byte basin. Moving radius initialization before the log moved to 533 bytes
// but worsened CFG and shape. Restore the pinned typed source; no new owner fact
// was established.
// Exact-finish pass: target-local /Oy- probes for checksum ownership, local order,
// suppression guard shape, and period header context did not recover the oracle.
// The header probe failed on a duplicate _rotl declaration. All probes are
// restored. A fresh registered-TU check uses default /Oy: 571/546 bytes, a
// 0x10/0x14 frame, 3/3 ordered calls, and a matching PDB-qualified owner.
// The original EBP frame needs /Oy- or a context change. This pass made no
// shared or view-TU edit. Fresh checks still match pick_best_target 00540010 and
// view anchors 0053DAB0, 0053DB40, 0053E280, 0053E2F0, 0053E340, 0053F660,
// 0053F6B0, and 0053F800 at 0.0000%.
// Specialist audit: the target PDB owner is visible.cpp, not vis_unit.cpp.
// A temporary vis_unit.cpp source group conflicts with the registered
// visible.cpp declarations. It cannot be an authentic target context.
// A scoped VC5 /Oy- pragma restored the EBP frame and reached 527 bytes / 466
// differences, but no natural source form reached the 546-byte oracle.
// Restore the pinned default source. Fresh grouped checks still match 0053C400,
// 0053C490, 0053C4D0, 00535480, 00538280, 00538410, and 0053DBA0.
```
<!-- end-recovered:7259010d823942be83ad -->

## Worker updates

### 2026-08-30 `wave21-visible-explore-integrate`

- Integrated the completed typed candidate's canonical `RGE_Tile::draw_as`
  store. The reviewed `RGE_Tile` bitfield layout places `draw_as` at byte
  offset `+0x09`; the original store at `0053C8C3` is `c6 42 09 0f`.
- Kept the existing typed `LOSTBL*`, `unsigned long*`, `RGE_Tile*`, map, and
  player operations. No unrelated function or shared header changed.
- Focused `check_function.py --va 0053C6F0 --rebuild` remains unavailable after
  source reunification: extraction rejects the four same-name visible-map
  methods in the natural object. The grouped visible audit compared the target
  as `MISMATCH`, 555 bytes, with matching owner and no relocation mismatch;
  three boundary escapes reflect the known default-TU basin.
- Final grouped command: `python tools/audit_translation_unit_observed.py
  --group visible --jobs 1 --output-dir
  build/audits/workers/wave21-visible-explore-integrate/visible-final`.

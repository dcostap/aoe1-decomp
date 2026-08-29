# Recovery journal: 00429D90 `ExecuteIncoming`

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


<!-- recovered:e567b79121172e943891 -->
### `target-session` `build/target_sessions/00429D90_ExecuteIncoming.json:1-26`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=442; shape=72.67080745341615: Current clean typed reconstruction: 457 bytes, 0xC frame, 8 calls, but this in EDI and offset/pno homes differ from original EBX/ESI topology.
probe 2 liveness; result=MISMATCH; diff=460; shape=73.91304347826087: Swapped outer declaration order: pno before byte offset, testing original pno-low/offset-register allocation.
probe 4 liveness; result=MISMATCH; diff=448; shape=76.47058823529412: Scoped each HOLDER clear pointer to its own proven clear branch, testing whether shared entry liveness causes the wrong callee-saved register basin.
probe 6 control-flow; result=MISMATCH; diff=442; shape=72.67080745341615: Removed the explicit else after the early multiplayer return, matching the decompiler's positive body plus final return while preserving two return sites. [same emitted code as probe 1]
probe 8 liveness; result=MISMATCH; diff=442; shape=72.67080745341615: Moved pno, player, and dco declarations to function scope with delayed assignments, testing original function-local stack-home ordering. [same emitted code as probe 6]
probe 10 liveness; result=MISMATCH; diff=442; shape=72.67080745341615: Swapped inner declaration order to player before dco, testing whether VC5 maps player to EBP and dco to EDI as in the original. [same emitted code as probe 8]
probe 12 liveness; result=MISMATCH; diff=442; shape=72.67080745341615: Removed the named serial local and used direct member reads in the stale-entry predicate and log, testing whether reduced long-lived pressure lets offset and this use the original saved registers. [same emitted code as probe 10]
probe 14 layout; result=MISMATCH; diff=452; shape=74.53416149068323: Replaced byte-offset field arithmetic with typed HOLDER[slot] indexing and slot count, testing whether VC5 strength-reduces the natural 24-byte record scan.
probe 16 liveness; result=MISMATCH; diff=431; shape=86.144578313253: Removed the named HOLDER entry alias and expressed clear/dispatch fields as direct offset member accesses, testing whether alias liveness is the source of the register basin.
probe 17 liveness; result=MISMATCH; diff=431; shape=86.144578313253: With direct clear fields, swapped player and dco declarations to test whether the original EBX offset and EDI dco colors are declaration-order driven. [same emitted code as probe 16]
probe 19 liveness; result=MISMATCH; diff=372; shape=91.56626506024097: Used branch-local HOLDER aliases only for the two clear blocks, while retaining direct offset reads for checks and calls, testing a mixed alias/reload topology.
probe 20 variant; result=MISMATCH; diff=3; shape=100.0: Kept branch-local entry only for cleanup, but restored direct field expressions for PreprocessMessages and the clearing log to match the original shared pointer setup.
probe 21 variant; result=MISMATCH; diff=3; shape=100.0: Changed only pno from unsigned to signed int, testing whether the original outer-tail EDX color depends on source signedness. [same emitted code as probe 20]
probe 22 variant; result=MISMATCH; diff=3; shape=100.0: Changed outer pno update from post-increment to pre-increment, testing the source update form that may select the oracle's EDX tail register. [same emitted code as probe 21]
probe 23 variant; result=MATCH; diff=0; shape=100.0: Swapped source update order to increment pno before advancing the byte offset, testing compiler scheduling and tail register color.
probe 25 variant; result=MATCH; diff=0; shape=100.0: Restored pno to the decompiler-proven unsigned type while retaining pno-before-offset source order; signedness was codegen-neutral. [same emitted code as probe 24]
probe 26 layout; result=MATCH; diff=0; shape=100.0: Spelled the proven 24-byte holder stride as sizeof(HOLDER), testing a more natural period source form. [same emitted code as probe 25]
probe 27 baseline; result=MISMATCH; diff=463; shape=75.77639751552795: Current clean typed HOLDER-index source baseline; 0x14 frame, 437 bytes, diff 463, ordered eight calls.
probe 28 layout; result=MISMATCH; diff=418; shape=67.70186335403727: Natural outer HOLDER pointer cursor with ++entry replaces indexed entry expression; tests whether period source used a moving record pointer.
probe 29 layout; result=MISMATCH; diff=449; shape=68.63905325443787: Natural direct indexed HOLDER member expressions without a persistent entry alias; tests whether VC5 retains this and strength-reduces the slot index.
probe 32 layout; result=MISMATCH; diff=454; shape=77.91411042944786: Period-plausible do/while outer offset with typed HOLDER entry and typed dco cursor; tests the decompiler-proven stride and update topology without raw field casts.
probe 34 liveness; result=MISMATCH; diff=469; shape=77.63975155279503: Natural typed indexed HOLDER source with a scoped running dcoID pointer, matching the original dco cursor and proven donor ownership.
probe 36 control-flow; result=MISMATCH; diff=463; shape=75.77639751552795: Natural indexed HOLDER entry with explicit positive do/while player guard, isolating inner CFG shape from the dco pointer choice. [same emitted code as probe 27]
probe 38 layout; result=MATCH; diff=0; shape=100.0: Typed HOLDER member casts over the decompiler-proven byte stride, with branch-local cleanup pointers; tests whether explicit field typing can retain the original offset basin. [same emitted code as probe 26]
probe 39 variant; result=MATCH; diff=0; shape=100.0: Exact walkback: change only the outer pno from unsigned to signed while retaining typed HOLDER casts and exact loop bounds. [same emitted code as probe 38]
probe 40 variant; result=MATCH; diff=0; shape=100.0: Exact walkback: replace sizeof(HOLDER) in the proven byte-stride update with literal 0x18. [same emitted code as probe 39]
```
<!-- end-recovered:e567b79121172e943891 -->

<!-- recovered:facb0902e739b3cc7d5e -->
### `912332e8f578` `src/scratch/00429D90_ExecuteIncoming.cpp:1-64`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00429D90 TCommunications_Handler::ExecuteIncoming
// PDB: Com_hand.cpp:3080-3142, 485 bytes
// Attempt log:
// - v1: reconstructed on-hold message scan from packet/decompiler with local structs and member calls.
// - v2: inlined clear-entry code and rewrote around byte offset to match original EBX offset topology.
// - v3: delayed offset initialization until after multiplayer check and marked offset register to probe EBX allocation; no size improvement.
// - v4: introduced self local and restored offset zero-before-check to probe original ESI-this/EBX-zero allocation.
// - v5: tried /GX as TU-context probe; no change to compiled main .text size, removed flag.
// - v6 (sa8b70374_r1): removed the self alias and used direct this accesses to
//   test whether the original ESI-this/EBX-offset basin comes from natural
//   member expressions rather than a long-lived receiver alias.
// - v7 (sa8b70374_r1): restored the proven HOLDER/PlayerHighSerialNumber and
//   PlayerOptions.dcoID ownership (dcoID starts at +1564, with the loop's
//   pre-increment selecting player 1) and scoped loop locals to their guards.
// - v8 (sa8b70374_r1): declared the byte offset before the packet counter and
//   scoped pno to the multiplayer arm, matching the original's early zeroed
//   offset and late address-taken counter home.
// - v9 (sa8b70374_r1): initialized the dco cursor at dcoID+1 and advanced it
//   once at the loop tail, the same typed player-1 ownership used by the exact
//   KillAnyMissingPlayers donor.
// - v10 (sa8b70374_r1): expressed the multiplayer gate as the original
//   positive guarded body with one fall-through return, rather than an early
//   negative return, to test VC5's block placement and local lifetime basin.
// - v11 (sa8b70374_r1): made the negative multiplayer return an explicit
//   if/else arm so the body remains a separate positive region while retaining
//   the oracle's two return sites.
// - v12 (sa8b70374_r1): mirrored the decompiler/PDB condition shape by
//   assigning player=1 inside the Length-and-MaxGamePlayers conjunction,
//   rather than spelling two nested guards.
// - v13 (sa8b70374_r1): corrected the direct-call ABI surface to the exact
//   Com_hand.cpp donor: variadic member Log and CRT C-linkage sprintf, while
//   restoring the cleaner nested guard after the conjunction probe.
// - v14 (sa8b70374_r1): declared the inner dco cursor before player and
//   assigned it only in the MaxGamePlayers arm, probing the original dco/player
//   stack-home ordering without changing the observed loop behavior; emitted
//   code was unchanged from v13.
// - bounded pass result: direct this access, canonical HOLDER/serial/dcoID
//   ownership, typed donor ABI, natural nested loops, and guard/local-order
//   probes all preserve the same 457-byte VC5 basin.  The positive-gate
//   diagnostic was 456 bytes but collapsed the oracle's separate early return;
//   it was not retained.
// Prior structural gap: behavior and the eight-call set were reconstructed, but
// the earlier source model used the wrong register basin.
// The resolved model keeps the original 0xC frame, saved EBX/ESI, eight calls,
// and byte-offset ownership.
// Follow-up pass: same-TU zero-local and pno-scope probes were codegen duplicates or
// worse. A positive guard improved the metric to 398 bytes but lost the separate early
// return topology. Restored the negative guard. Exact KillAnyMissingPlayers ownership
// also confirms COMMPLAYEROPTIONS::dcoID; the nested type is retained although bytes stay
// unchanged. A fully indexed HOLDER scan widened the frame and was rolled back.
// fresh shardC3 probe: the first checker hunk and PDB 3080/3142 bands led to a
// positive Multiplayer guard with one natural common return. It reached the prior
// 398-byte diagnostic basin but emitted one return instead of the oracle's two;
// restored the negative guard and kept the typed owner-lifetime reconstruction.
// shardC5 probe: a typed HOLDER cursor and PlayerHighSerialNumber cursor preserved
// the two clear/process branches and eight calls, but widened the frame to 0x10 and
// worsened the positional diff; restored the clean byte-offset reconstruction.
// Exact diagnostic: a byte-offset HOLDER cursor plus a pointer that crosses
// from dcoID into PlayerHighSerialNumber matched all 485 bytes. Main review
// rejected both raw cross-owner cursor forms. Keep indexed HOLDER, serial,
// and dcoID ownership in the living source. The exact result is not promotable.
// Exact follow-up: a byte-offset HOLDER cursor recovered all 485 bytes, but
// main review rejected that source as compiler-steering plumbing. The retained
// source uses typed HOLDER indexing and named player arrays.
```
<!-- end-recovered:facb0902e739b3cc7d5e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

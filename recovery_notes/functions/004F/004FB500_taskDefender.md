# Recovery journal: 004FB500 `taskDefender`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.

## Translation-unit context

The PDB module is `taitacmd.cpp`. The owner is `TribeTacticalAIModule`.
The natural owner is `src/taitacmd.cpp`.
The function is the two-integer `taskDefender` overload.
The body spans `004FB500-004FB51C` and has no frame.
Its only direct call is `AIModule::logCommonHistory` at `004FB510`.

The source call uses `groupId, defenderId` after the format string.
This order produces the original push order and preserves the shipped code.

## Current mismatch

The fresh baseline differed by two parameter-load bytes at `+0x3` and `+0x7`.
The call shape, size, boundary, owner, and relocation count already matched.
The final source is exact: 29 of 29 bytes match with no first mismatch.
The frame is absent in both builds.
The direct call count is one in both builds.
Both relocation sites are safely masked.

## Recovered attempt history


<!-- recovered:bdb0e1cabd62b50589c8 -->
### `d050eea3c` `src/taitacmd.cpp:11105-11118`

Mapping: `ambiguous`. next mapped function definition is taskDefender at old line 11207.

```text
//     object locals to test declaration-order register coloring.
// [non-comment lines omitted during migration]
//     the call result directly, mirroring the donor-era declaration surface.
// [non-comment lines omitted during migration]
// 19: reversed the target/no-target branch order as a natural typed call-order probe;
//     it moved the no-target calls ahead of target lookup and worsened structural parity,
// [non-comment lines omitted during migration]
// Final bounded state: the canonical typed reconstruction is retained in scratch.
// The ten-probe run established exact call count/targets, vslot 0x10c weaponRange,
// the 12-argument player order ABI, exact size, and a localized two-byte mismatch.
```
<!-- end-recovered:bdb0e1cabd62b50589c8 -->

<!-- recovered:d36f87d02e44c837fa49 -->
### `6a2aef2e2` `src/taitacmd.cpp:9569-9591`

Mapping: `ambiguous`. next mapped function definition is taskDefender at old line 9680.

```text
// 2: rewrote early failure paths to shared fail label and corrected world pointer chain (+f0/+f0/+3c).
// 3: made attackerID parameter const to avoid early save in ebx; prologue now matches through first object lookup, but function became 1 byte short and fail block placed early.
// 4: replaced direct fail returns with result variable and done label; no placement change.
// 5: expanded RGE_Static_Object virtual surface so vf_10c call lands at vtable +0x10c.
// 6: corrected command id expression: original maps commandFlag==1 to 0x2d9, otherwise 0x2bc.
// 8: verified object lookup chain now matches original +0xf0/+0xf0/+0x3c and first prologue matches after const attackerID.
// 9: remaining target-command branch still differs broadly; vtable +0x10c is fixed but stack argument scheduling and command vtable call are wrong.
//     same-TU ManagedArray<int> growth idiom, modeled md->player->world, and identified the
//     +0x10c call as the zero-argument weaponRange getter used by the 12-argument order call.
// 12: corrected the weaponRange slot count and moveUnit's float/float ABI after the
//     rebuilt call map exposed a +0x108 dispatch and two spurious __ftol calls.
// 13: hoisted the target pointer and target-branch scalar locals to the function
// 14: moved the command selector ahead of target lookup as a liveness/scheduling
// 15: retained the command selector after target validation but before distance
//     computation, isolating its scheduling point from the object lookup.
// 16: restored late command evaluation and moved the command local ahead of the
// 17: retained the binary-proven unitAI result as a typed local instead of testing
// 18: reordered the top-level locals to the decompiler's attacker/unitAI/target/int
//     sequence before the final validation checkpoint.
//     so the clean canonical branch order is restored.
// 20: explicit late command if/else after priority restored the original EBP attacker,
//     EAX target-ID, 545-byte size, and all call/relocation sites; only the no-target
//     distance temporary home differs (original [esp+20], rebuilt [esp+28]), diff 2.
```
<!-- end-recovered:d36f87d02e44c837fa49 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

No further source recovery is needed for this owner.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### wave21-taitacmd

- Baseline: fresh rebuild, 2 bytes different, 6.8966% positional difference.
- Tested the two natural varargs orders for `logCommonHistory`.
- The order `groupId, defenderId` matches the original register loads and pushes.
- Final focused check: `Result: MATCH`, `0.0000%`, 29/29 bytes.
- Final owner, boundary, call target, and two relocations are correct.
- Grouped `taitacmd` audit completed under `build/audits/workers/wave21-taitacmd-integrate/taitacmd`.
- The grouped audit reports `MATCH`, 0 positional difference, and correct ownership for this function.

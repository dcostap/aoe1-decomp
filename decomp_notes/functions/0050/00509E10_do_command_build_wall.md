# Function notes: 00509E10 `do_command_build_wall`

Module notes: `decomp_notes/tcommand_module.md`.

## Recovered attempt history

<!-- recovered:18a270288d9b1452c99f -->
### `target-session` `build/target_sessions/00509E10_do_command_build_wall.json:1-14`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=19; shape=98.44559585492227: Clean typed command/world ownership baseline before probes.
probe 2 variant; result=MISMATCH; diff=17; shape=97.40932642487047: Reverse endpoint comparisons to test original load order in vertical and horizontal split arms.
probe 4 liveness; result=MISMATCH; diff=11; shape=99.48186528497409: Name branch endpoint bytes to test whether an ordinary cached comparison value reproduces reversed load order.
probe 5 liveness; result=MISMATCH; diff=35; shape=94.81865284974093: Split count declaration from assignment to test scheduler order around world lookup.
probe 6 liveness; result=MISMATCH; diff=28; shape=96.89119170984456: Reorder ids before count declaration to test ordinary declaration-order register coloring.
probe 7 abi; result=MISMATCH; diff=11; shape=99.48186528497409: Split the typed world-table result from the TRIBE_Player cast to test canonical base/player ownership. [same emitted code as probe 4]
probe 8 abi; result=MISMATCH; diff=11; shape=99.48186528497409: Recheck the TRIBE_Player** world-table ownership hypothesis after restoring its forward declaration. [same emitted code as probe 7]
probe 9 liveness; result=MISMATCH; diff=11; shape=99.48186528497409: Name the command player index as an int to test whether the original EAX index register is source-driven. [same emitted code as probe 8]
probe 10 context; result=MISMATCH; diff=11; shape=99.48186528497409: Add the donor-supported RGE_Game_World::object declaration to test period class context. [same emitted code as probe 9]
probe 11 liveness; result=MISMATCH; diff=11; shape=99.48186528497409: Split player declaration from assignment to test whether declaration scope changes initial world/index register colors. [same emitted code as probe 10]
probe 12 abi; result=MISMATCH; diff=11; shape=99.48186528497409: Use a fully typed TRIBE_Player** world table without a cast to test the natural derived ownership surface. [same emitted code as probe 11]
probe 13 context; result=MISMATCH; diff=11; shape=99.48186528497409: Recheck the same-TU TRIBE_Player virtual surface after restoring the RGE_Player** cast. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=11; shape=99.48186528497409: Cache the command world pointer as an ordinary local to test its influence on initial load scheduling. [same emitted code as probe 13]
probe 16 abi; result=MISMATCH; diff=11; shape=99.48186528497409: Policy correction: canonical class-dump RGE_Command and RGE_Static_Object virtual declarations replace fake OPAD and generic vfunc slots; rebuild remains an 11-byte mismatch. [same emitted code as probe 15]
```
<!-- end-recovered:18a270288d9b1452c99f -->

<!-- recovered:590fef3f97a00fe63c89 -->
### `43d52720245a` `src/scratch/00509E10_do_command_build_wall.cpp:1-37`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00509E10 TRIBE_Command::do_command_build_wall
// tcommand.cpp lines 337-450
// Attempt log:
// 1: natural structured source from packet/decompiler: behavior/call set modeled, rebuilt 480 B vs original 500 B.
// 2: corrected TRIBE_Player object table to proven +0x24 with explicit gap; fixed object-table offset but still 480 B.
// 3: tried adding a virtual vptr to TRIBE_Player for +0x24; caused worse register allocation (player in ebp, this homed to stack) and 0x1C frame; rolled back.
// 4: tried sign-shift absolute value spelling to force cdq/xor/sub; VC5 used sar temps, saved this to stack, frame 0x1C, 500 B but broad 91% positional diff; rolled back.
// 5: tried named sign temps for abs; same bad frame/register family; rolled back.
// 6: reordered dominance branch as dy > dx so inline branch matches original's post-compare fallthrough family; kept.
// 7: tried default /O2 /Oy /GX flags; unchanged 480 B.
// 8: tried /O2 without /Oy; unchanged 480 B.
// 9: compared dumped asm: top/object lookup and final pathing loop are close; remaining major gap is middle wall-splitting region, especially abs codegen and push/tail-sharing register allocation.
// 10: left in scratch: not accepted_drift-safe; broad middle control-flow/register mismatch despite correct behavior-level model and call boundaries.
// 11: direct command-field expressions plus natural stdlib abs recovered the original 0x18 frame, 500-byte size, and most middle/cold bytes (209 strict bytes; 41.7%); retained as the canonical source lead.
// 12: positive dy>=dx vertical arm with horizontal else matched the original JL block topology and reduced drift to 19 strict bytes; retained.
// 13: a named world-base local was codegen-duplicate and did not improve the 19-byte result; restored the simpler direct world member form.
// Current pause: calls, frame, size, CFG, and 73.6% exact blocks are aligned; remaining 19 bytes are localized to initial world/player register scheduling and do not justify opaque forcing.
// Typed the world player table as RGE_Player** from the shared engine ABI;
// output was codegen-duplicate at 500/500 B and 19 strict bytes. Retained the
// natural typed ownership, but kept the clean source as the recovery authority.
// Tried a natural cached player-table local; it was codegen-duplicate at 19 bytes
// and was rolled back. The clean direct world member form remains authoritative.
// Reordered natural early declarations to evaluate player before ids; this widened the
// first hunk to 40 bytes and was rolled back. The clean declaration order remains best.
// Tested exact-TU world/player ABI surfaces, split declarations, an explicit byte index,
// and named pointer arithmetic; these all stayed at 19 bytes or worsened the first hunk.
// Restored the clean source before the final ownership pass.
// Final ownership pass: modeled the proven 0x10-byte command header with trailing
// RGE_Obj_Info records and the player master_objects table; output stayed at 19 bytes.
// Naming branch-local x2/y2 bytes recovered both split-arm compare load orders;
// the natural source moved to 11 strict bytes and 90.2% exact blocks.
// Tested typed player-table, cached world/player, split declaration, and full
// same-TU player-vtable surfaces; these were codegen-duplicate. Current pause:
// the remaining 11 bytes are the initial world/player register-color schedule.
// Policy correction: replaced the fake virtual-slot padding and generic names
// with canonical RGE_Command and RGE_Static_Object virtual surfaces from the
// repository class dumps. The rebuild remains 500 B with an 11-byte mismatch.
```
<!-- end-recovered:590fef3f97a00fe63c89 -->

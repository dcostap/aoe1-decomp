# Function notes: 00509C60 `do_command_build`

## Recovered attempt history

<!-- recovered:a724ebab14f6a20e9538 -->
### `target-session` `build/target_sessions/00509C60_do_command_build.json:1-18`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=250; shape=65.2439024390244: Baseline clean typed reconstruction: 411 rebuilt bytes vs 418 original, 10 ordered calls, 0x08 frame vs 0x0C original.
probe 2 liveness; result=MISMATCH; diff=415; shape=82.92682926829268: Hypothesis: narrow count to uchar may recover original count register and byte argument lowering.
probe 3 abi; result=MISMATCH; diff=414; shape=71.95121951219512: Hypothesis: restore canonical 0x14-byte command record and use trailing RGE_Obj_Info at cmd+1, instead of embedding ids[1] in the command type.
probe 4 layout; result=MISMATCH; diff=411; shape=78.65853658536585: Hypothesis: original has distinct int placement output at entry -8 and uchar return result at adjacent entry -4; the two locals explain the 0x0C frame and return-byte store.
probe 5 layout; result=MISMATCH; diff=246; shape=94.51219512195122: Hypothesis: model the adjacent int placement output and uchar result as one natural local state aggregate to recover original address order (pointer at -8, result at -4).
probe 6 control-flow; result=MISMATCH; diff=246; shape=94.51219512195122: Hypothesis: explicit else around pay/foundation arm may preserve the original info register and branch topology with the recovered placement state. [same emitted code as probe 5]
probe 7 liveness; result=MISMATCH; diff=246; shape=94.51219512195122: Hypothesis: aliases to aggregate fields may restore the original separate count/result liveness and cancelBuild argument lowering while retaining proven adjacent addresses. [same emitted code as probe 6]
probe 8 liveness; result=MISMATCH; diff=400; shape=89.63414634146342: Hypothesis: remove the named count local and let repeated direct cmd->count expressions reproduce the compiler's dead parameter-home reuse and EAX count color.
probe 9 liveness; result=MISMATCH; diff=247; shape=95.1219512195122: Hypothesis: name the loop's fetched RGE_Obj_Info before get_obj to recover the original EDX load and post-push receiver setup.
probe 10 liveness; result=MISMATCH; diff=288; shape=67.0807453416149: Hypothesis: copy the aggregate's byte return into a separate placementResult local, matching a plausible original result local and changing cancelBuild value liveness.
probe 11 control-flow; result=MISMATCH; diff=247; shape=95.1219512195122: Hypothesis: express placement failure as nested positive count and object guards, matching the original jle and null-join topology without early returns. [same emitted code as probe 9]
probe 12 liveness; result=MISMATCH; diff=247; shape=95.1219512195122: Hypothesis: join count declaration and initialization, which may change the local's first-use and reload color without changing behavior. [same emitted code as probe 11]
probe 13 abi; result=MISMATCH; diff=247; shape=95.1219512195122: Hypothesis: use the canonical 0x14-byte command record and trailing RGE_Obj_Info records at cmd+1 with the recovered placement state. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=247; shape=95.1219512195122: Hypothesis: a natural pointer alias for the placement output may alter register pressure toward the original count/result setup. [same emitted code as probe 13]
probe 15 abi; result=MISMATCH; diff=247; shape=95.1219512195122: Hypothesis: widen the returned placement byte into an int local immediately before cancelBuild, matching its proven int ABI and original dword mask. [same emitted code as probe 14]
probe 18 behavior; result=MATCH; diff=0; shape=100.0: Binary stack-home audit: cancelBuild second argument reads entry -8, the check_placement int output, not the count at the reused parameter home.
probe 19 layout; result=MATCH; diff=0; shape=100.0: Policy audit probe: replace the local aggregate with ordinary placement and placementResult locals; semantic output ownership is tested without invented aggregate machinery. [same emitted code as probe 18]
probe 20 other; result=MATCH; diff=0; shape=100.0: Policy audit: replaced fake virtual-slot methods and generic BuildInfo with real local class declarations and the TRIBE master-object inheritance chain; canonical names and offsets remain exact.
```
<!-- end-recovered:a724ebab14f6a20e9538 -->

<!-- recovered:c83f6e29190239274e8e -->
### `1f02fa47d8e2` `src/scratch/00509C60_do_command_build.cpp:1-30`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00509C60 TRIBE_Command::do_command_build
// tcommand.cpp lines 256-331
// Attempt log:
// 1: natural structured source from packet/decompiler: 416 B, frame 8 not original 0xC; count tested as byte.
// 2: introduced int count local loaded from cmd->count early: restored original early prologue/load order through player lookup, still frame 8 and 416 B.
// 3: widened placementResult storage to int while passing uchar*: worsened to 400 B; rolled back.
// 4: split count declaration/assignment: no material change, still 416 B.
// 5: volatile count stack-forcing: section 432 B, first mismatch still frame imm and broad extra volatile traffic; rolled back.
// 6: positive count comparisons (0 < count) instead of count <= 0: no size/layout improvement.
// 7: local one variable for can_place constant args optimized away/no improvement.
// 8: flags /O2 no-/Oy, /Ox, and /GX: same 416 B outcome.
// Left in scratch: behavior/call surface is modeled and early load order is close, but VC5 standalone keeps a 0x08 frame instead of original 0x0C and then broad branch/register displacement drift remains. Not accepted_drift-safe.
// This pass normalized the shared RGE_Command base and retested declaration
// order/self-alias context; output stayed at 405B/250 strict bytes, frame
// 0x08 versus 0x0C. Final candidate is natural and validated in scratch.
// Main-agent audit restored canonical polymorphic world/static/player/build
// ownership while retaining the ordinary placement/foundation branches.
// 9: ground-truth ABI pass changed command coordinates to float, IDs to RGE_Obj_Info, the player call to cancelBuild, the foundation call to make_new_obj, and the object call to do_command; size moved 405 -> 411 but the frame stayed 0x08.
// 10: nested the placement/pay/foundation arms to mirror the PDB line topology; it was slightly worse (407 B), so the natural early-return form remains authoritative.
// 11: tested int placementResult against the proven check_placement int* metadata; it regressed broadly and was rolled back to the binary-supported uchar local.
// 12-13: local declaration order and named command self alias were tested; emitted code was unchanged at 411 B/250 strict bytes.
// Current pause: canonical float/object/virtual surfaces and early-return behavior are modeled; remaining structural blocker is VC5's 0x08 standalone frame versus original 0x0C, shifting otherwise aligned stack homes by four bytes. Best output is 411/418 B, 10/10 ordered calls, CFG 12/12, 250 strict bytes.
// Main-agent audit removed the diagnostic command self-alias; direct member calls
// remain the canonical source even though the alias was codegen-neutral.
// Recovery: rebuilt the clean pinned source after the host crash; output stayed
// at 411/418 B and 250 strict bytes. No new evidence-backed structural lead
// remains, so this typed reconstruction stays in scratch.
// Ownership probe: the same-TU make_new_obj donor supports TRIBE_Master_Building_Object;
// its canonical hierarchy with the observed uchar placement ABI was codegen-neutral.
// Restored the clean BuildInfo-shaped surface; the frame remains 0x08 versus 0x0C.
```
<!-- end-recovered:c83f6e29190239274e8e -->

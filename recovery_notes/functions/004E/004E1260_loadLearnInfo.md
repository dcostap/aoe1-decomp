# Recovery journal: 004E1260 `loadLearnInfo`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiinfmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiinfmd.cpp`.
- Earlier recovery note: `recovery_notes/taiinfmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:28b80ca01c86235e1a82 -->
### `target-session` `build/target_sessions/004E1260_loadLearnInfo.json:1-40`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 liveness; result=MISMATCH; diff=1141; shape=91.75257731958763: Remove the long-lived civ local and use direct md->player->id expressions; original loads the id at each sprintf setup and keeps suffix in EBX.
probe 2 layout; result=MISMATCH; diff=1153; shape=92.50645994832041: Move the serialized ObjectMemory local before the scalar read counters; this tests whether declaration order moves its read buffer four bytes earlier while retaining the observed scalar homes.
probe 3 abi; result=MISMATCH; diff=1168; shape=91.98966408268734: Narrow civ to the proven short player-id width; original emits one movsx word load before the filename branch, so test whether the local width restores that value flow.
probe 4 liveness; result=MISMATCH; diff=1141; shape=91.75257731958763: Make civ branch-local in both filename arms; this tests whether the id is consumed as a short-lived call argument while suffix remains in the original EBX color. [same emitted code as probe 1]
probe 5 layout; result=MISMATCH; diff=1154; shape=89.6640826873385: Add four trailing bytes to the local ObjectMemory type only; serialized reads remain 0x18/0x24 and field offsets stay fixed, while a 0x28 local may recover the original temp stack anchor.
probe 6 layout; result=MISMATCH; diff=1153; shape=92.50645994832041: Declare the uninitialized float before ObjectMemory; this tests whether the four-byte value occupies the original gap and moves the address-taken temp buffer to the observed stack anchor. [same emitted code as probe 2]
probe 7 layout; result=MISMATCH; diff=1153; shape=92.50645994832041: Represent the 0x24 serialized window as a byte array with a typed local reference; this tests whether VC5 gives the address-taken storage the original stack anchor without changing field offsets. [same emitted code as probe 6]
probe 8 context; result=MISMATCH; diff=1152; shape=92.50645994832041: Replace the absolute rge_base_game macro with the reviewed extern symbol; compare whether VC5 restores the original A1 relocation and receiver scheduling.
probe 9 liveness; result=MISMATCH; diff=1151; shape=92.48704663212435: Cache md->player as a typed pointer, then read the shared short id in both filename arms; this tests whether pointer ownership restores the original EBX suffix and common id-load schedule.
probe 10 liveness; result=MISMATCH; diff=1153; shape=92.50645994832041: Declare the int civ before the filename pointer; this tests the original PDB declaration-order possibility without changing the call ABI or field expressions. [same emitted code as probe 7]
probe 11 liveness; result=MISMATCH; diff=1136; shape=92.01030927835052: Use the hoisted civ only in the default-name arm and a direct player-id expression in the suffix arm; this tests whether the common push schedule depends on expression sharing across the branch.
probe 12 layout; result=MISMATCH; diff=1153; shape=92.50645994832041: Make the PDB-listed unused numMemoriesToLoad volatile; test whether VC5 reserves its four-byte stack slot and shifts temp to the original address without adding behavior. [same emitted code as probe 10]
probe 13 abi; result=MISMATCH; diff=1153; shape=92.50645994832041: Spell serialized reads as a byte cursor at temp+4 instead of a typed short member; test whether original cursor typing controls LEA register and stack-load order. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=1141; shape=91.75257731958763: Re-run the direct player-id expression model with canonical local order; inspect its exact suffix register and call setup as the strongest alternate basin. [same emitted code as probe 4]
probe 15 abi; result=MISMATCH; diff=1164; shape=91.98966408268734: Use a narrow char civ diagnostic to test whether saved-register pressure, not branch structure, controls EBX suffix coloring; retain only if binary width evidence permits.
probe 16 liveness; result=MISMATCH; diff=1153; shape=92.50645994832041: Apply register to the independent civ local; test a controlled register-coloring axis against the original EBX suffix/EDX id setup. [same emitted code as probe 13]
probe 17 liveness; result=MISMATCH; diff=1153; shape=92.50645994832041: Copy suffix to a named pointer alias and use the alias in the filename branch; test whether VC5 assigns the persistent branch value to original EBX without changing ABI. [same emitted code as probe 16]
probe 18 context; result=MISMATCH; diff=1153; shape=92.50645994832041: Add the period string header alongside stdio; test a supported translation-unit context axis for front-end register and call scheduling. [same emitted code as probe 17]
probe 19 liveness; result=MISMATCH; diff=1153; shape=92.50645994832041: Hoist the first-loop index declaration to function scope but keep its zero assignment at the observed post-count site; test scope-driven register and stack lifetime effects. [same emitted code as probe 18]
probe 20 liveness; result=MISMATCH; diff=1153; shape=92.50645994832041: Predeclare the file handle and assign it after filename construction; test whether function-scope handle lifetime recovers original EBP file coloring without changing calls. [same emitted code as probe 19]
probe 24 liveness; result=MISMATCH; diff=1136; shape=92.01030927835052: Keep the hoisted civ local for the default arm but reread the player id directly in the suffix arm; test whether object-first declarations recover original EDX id and EBX suffix without the extra frame. [same emitted code as probe 11]
probe 26 liveness; result=MISMATCH; diff=1132; shape=93.28165374677003: Use the period nested get_current_player_name expression in the suffix sprintf instead of a branch-local playerName alias; test whether the original VC5 argument schedule recovers common civ setup.
probe 27 abi; result=MISMATCH; diff=1132; shape=93.28165374677003: Remove the explicit int cast from the hoisted player id while retaining nested suffix formatting; test whether VC5 chooses original EDX for the common narrow load. [same emitted code as probe 26]
probe 28 layout; result=MISMATCH; diff=1132; shape=93.28165374677003: Swap float local before ObjectMemory while retaining nested filename formatting; test declaration order for original EDX id register and temp.type stack anchor. [same emitted code as probe 27]
probe 29 liveness; result=MISMATCH; diff=1132; shape=93.28165374677003: Move the civ declaration before the filename alias in the nested-format basin; test declaration order for the original EDX common id load without changing source behavior. [same emitted code as probe 28]
probe 30 liveness; result=MISMATCH; diff=1132; shape=93.28165374677003: Apply register to the hoisted civ local in the nested-format basin; test a source-supported register-color axis for target EDX while preserving EBX suffix and common push. [same emitted code as probe 29]
probe 31 layout; result=MISMATCH; diff=1132; shape=93.28165374677003: Declare ObjectMemory before scalar locals in the improved nested-format basin; test whether VC5 moves temp.type to the original entry-relative stack anchor. [same emitted code as probe 30]
probe 32 layout; result=MISMATCH; diff=1132; shape=93.28165374677003: Pack the explicitly serialized ObjectMemory record; test whether aggregate alignment moves temp.type to target without changing its proven field offsets or frame. [same emitted code as probe 31]
probe 33 liveness; result=MISMATCH; diff=1132; shape=93.28165374677003: Split the civ declaration from its assignment in the nested-format source; test whether delayed initialization changes only the target EDX register without adding a store. [same emitted code as probe 32]
probe 34 abi; result=MISMATCH; diff=1170; shape=91.98966408268734: Narrow the hoisted civ local to short in the nested-format basin; test whether original signed word width recovers EDX and common push without changing the call surface.
probe 35 liveness; result=MISMATCH; diff=1132; shape=93.28165374677003: Cache the typed md player before the civ assignment in the nested-format basin; test whether a real owner alias yields target EDX while retaining direct field offsets. [same emitted code as probe 33]
probe 36 context; result=MISMATCH; diff=1131; shape=93.28165374677003: Use the reviewed extern rge_base_game surface with nested filename formatting; test whether relocation and register scheduling recover target absolute-load topology.
probe 37 liveness; result=MISMATCH; diff=870; shape=93.04123711340206: Remove the civ local and use nested direct player-id expressions in both sprintf arms with reviewed global; test whether VC5 naturally hoists the shared stack argument and frees target EAX/EDX colors.
probe 38 layout; result=MISMATCH; diff=870; shape=93.04123711340206: Reserve the PDB-listed unused numMemoriesToLoad slot as volatile in the direct-expression basin; test whether target temp.type anchor is a debug-local stack reservation. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=870; shape=93.04123711340206: Scope the uninitialized float local inside the object-memory loop; test whether its short lifetime recovers target local_4 and the missing addObjectMemory setup instruction. [same emitted code as probe 38]
probe 40 layout; result=MISMATCH; diff=878; shape=72.68041237113403: Use the PDB-listed numMemoriesToLoad for the first serialized count and numToLoad for the second; test whether distinct source count homes recover target temp placement while preserving read order.
probe 41 liveness; result=MISMATCH; diff=870; shape=93.04123711340206: Name the serialized id before importantUnits.add; test whether the original post-call temp.id home is a separate natural local that shifts temp and recovers the missing call-setup instruction. [same emitted code as probe 39]
probe 42 layout; result=MISMATCH; diff=867; shape=93.04123711340206: Place serialized type/group before id in ObjectMemory; x-through-range offsets stay fixed, while the proven temp.type read and decompiler temp._4_4_ first argument become natural.
probe 43 layout; result=MISMATCH; diff=96; shape=93.24675324675324: Restore canonical ObjectMemory id-first layout and assign temp.id from the serialized type/group dword before importantUnits.add, matching Ghidra's explicit post-call assignment evidence.
probe 44 layout; result=MISMATCH; diff=96; shape=93.24675324675324: Restore PDB declaration order with ObjectMemory after scalar locals while retaining the explicit serialized id assignment; test whether target temp.type anchor moves from +24 to +20. [same emitted code as probe 43]
```
<!-- end-recovered:28b80ca01c86235e1a82 -->

<!-- recovered:72560dc324a361e988e3 -->
### `fc4b000c6e8f` `src/scratch/004E1260_loadLearnInfo.cpp:1-46`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004E1260 TribeInformationAIModule::loadLearnInfo
// PDB: taiinfmd.cpp:6451-6549
//
// Attempt log:
// initial reconstruction from packet/decompiler: filename build, rge_read temp stack blocks, natural add/grow int-array helpers.
// try 1: static add_unique helper compiled too small (.text 880 vs 1212), because helper not inlined/parent inlining missing.
// try 2: macro-expanded add_unique to inline the three grow/list blocks; compiles to full size but broad mismatch.
// try 3: fixed storeAttackMemory visible arity to 11 explicit params (matching wrapper in 004E0F90); still broad drift.
// try 4: switched temp from struct ObjectMemory24 to raw char[0x24] and named filename/civ locals to test stack/local scheduling; edit diff improved 71% -> 55.6%, frame still wrong.
// try 5: tested /GX flag; no change (original has no EH frame); removed flag.
// try 6: restored the period ObjectMemory/ManagedArray source surface, parameter-home loop counters, canonical resource arrays, and exact serialized field widths.
// try 7: corrected the addObjectMemory ABI to the packet's four-byte/byte/short/float parameter widths.
// try 8: swapped local_4 ahead of ObjectMemory temp to test the original four-byte stack-window placement.
// try 9: reordered the count/temp locals to the PDB/decompiler declaration order and named the reused local_2c explicitly.
// try 10: used the binary-proven absolute rge_base_game address without changing the canonical source surface.
// left in scratch: validate the canonical source before any codegen-only tuning.
// Main-agent audit: added donor-backed virtual destructors for the proven
// Base_Game and Player polymorphic boundaries without changing emitted bytes;
// the remaining uninitialized local warning reflects an unresolved serialized
// argument/stack-slot reconstruction, not a promoted exact candidate.
// shard B6 tranche 6: dossier, same-TU donors, and ABI query confirm exact size,
// frame, calls, and list ownership. Short civ grew to 1215 bytes. Temp-first
// declarations and direct player-id expressions reached positional 1141 but
// grew to 1225 bytes. Restored this 1212-byte canonical source; first hunk is
// still the suffix register assignment (original EBX, current EBP).
// orch-4E1260-a probe 18: removed the explicit player-id vararg from the suffix
// filename branch; suffix moved to EBX but cleanup fell from 20 to 16 and diff
// worsened to 1154. Rolled back because the original stack surface has 20-byte cleanup.
// probe 19: kept that branch shape and narrowed the hoisted id to short; diff reached
// 1115, but the load used AX then sign-extended and cleanup stayed 16. Rolled back.
// probe 20: removed the explicit cast on the int id; duplicate of probe 18.
// probe 21: restored both id varargs and made the id local const; duplicate of clean.
// probe 22: split the id declaration from its assignment; duplicate of clean.
// claim sa-40a4b942 probes 1-20: tested direct and branch-local civ expressions,
// short/char/register civ widths, local declaration order, a byte-window temp,
// reviewed global spelling, pointer and suffix aliases, headers, loop scopes,
// a hoisted file handle, and a volatile unused local. No basin beat the clean
// 1212-byte source. Probe 11 was closest at 1136 differing bytes but grew 14 bytes.
// BINARY NOTE: the original preserves suffix in EBX, places temp.type at the
// observed entry-relative stack window, and keeps the file handle in EBP.
// These properties remain unresolved in the natural source below.
// claim sa-f093e5cf-r1 probes 1-20: nested direct filename expressions and the
// reviewed global improved the source from 1153 to 870 differing bytes. The
// id-first ObjectMemory layout plus a diagnostic type-punning assignment
// reduced the difference to 96 bytes. Main review rejected that assignment.
// It copied the type/group dword into id without a supported source model.
```
<!-- end-recovered:72560dc324a361e988e3 -->

<!-- recovered:aaf37a8e06806267caf6 -->
### `fc4b000c6e8f` `src/scratch/004E1260_loadLearnInfo.cpp:227-251`

Mapping: `exact`. historical standalone source path names this target VA.

```text
                    *(short*)&temp.attackAttempts,
                    *((unsigned char*)&temp.attackAttempts + 2),
                    *(unsigned long*)&temp.range,
                    *(int*)&temp.damageCapability);
// [non-comment lines omitted during migration]
                    *((unsigned char*)&temp.kills + 1),
                    *(short*)&temp.attackAttempts,
                    *(int*)&temp.range,
                    *((unsigned char*)&temp.damageCapability),
```
<!-- end-recovered:aaf37a8e06806267caf6 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

# Recovery journal: 004D0EB0 `TRIBE_Action_Make_Obj`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_mob.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_mob.cpp`.
- Earlier recovery note: `recovery_notes/tact_mob_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1ebe6e8e399d8ecbe87a -->
### `d050eea3c` `src/tact_mob.cpp:22-34`

Mapping: `strong`. next mapped function definition is TRIBE_Action_Make_Obj at old line 48.

```text
// 004D0DD0  lines 31-41   matching
// 004D0EB0  lines 48-54   scratch
// 004D0EF0  lines 60-65   matching
// 004D0F70  lines 69-76   matching
// 004D0FC0  lines 79-116  scratch
// 004D10E0  lines 120-123 matching
// 004D10F0  lines 126-167 scratch (canonical owner available)
// 004D12B0  lines 171-233 matching
// 004D1550  lines 237-251 matching
// 004D15F0  lines 255-268 matching
// [non-comment lines omitted during migration]
// VA 004D0DD0; PDB tact_mob.cpp:31-41; matching.
// /GX is part of the constructor's original exception-handling frame.
```
<!-- end-recovered:1ebe6e8e399d8ecbe87a -->

<!-- recovered:36f37795bdb2d75ccda1 -->
### `6a2aef2e2` `src/tact_mob.cpp:36-37`

Mapping: `strong`. comment lies after mapped function TRIBE_Action_Make_Obj at old line 34.

```text
// The disambiguated constructor still differs by 31 bytes in its natural
// register and field-width schedule.
```
<!-- end-recovered:36f37795bdb2d75ccda1 -->

<!-- recovered:f484fa91a7d3c4710a83 -->
### `3d4c471259c2` `src/scratch/004D0EB0_TRIBE_Action_Make_Obj.cpp:1-30`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004D0EB0 TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, unsigned char)
// PDB source: tact_mob.cpp lines 48-54 (63 bytes, 18 asm lines)
// Default flags
//
// __thiscall: this in ecx, 4 stack params. ret 10h cleanup.
// Attempt log:
// - Original scratch raw-store/typed-member forms: VC5 read/stored obj_id first
//   (mov ax,[esp+0Ch]) instead of original post-base load order p4,p3,p2.
// - Previous (HollowSnowdrop): typed members, locals, volatile still stuck at
//   parameter-load scheduling; 31/63 positional diff, 51/63 edit-equal.
// - Try 1: volatile reads into pp/uid/oid locals before stores fixed the entire
//   load/store schedule but VC5 chose dword obj_id load (`mov edx,[esp+0Ch]`)
//   instead of original word load (`mov dx,[esp+0Ch]`): edit diff 2, 62/63 equal.
// - Try 2: plain `short oid = obj_id` restored a word load but VC5 used `cx`,
//   clobbered uid, and moved the unique_id store before obj_id load.
// - Try 3: direct volatile-short store expression (no oid local) also moved
//   unique_id store too early and used ecx/cx.
// - Try 4: volatile short local forced a stack spill/reload and was much worse.
// - Try 5: volatile short formal parameter with volatile locals still used the
//   same dword obj_id load as try 1.
// - Try 6: unsigned short formal/local restored word load but again used cx and
//   scheduled unique_id store early.
// - Try 7: volatile pp local with plain uid/oid introduced stack traffic and worse
//   byte-register allocation.
// - Try 8: `register short oid` collapsed back to try 1 (single missing 66 prefix).
// - Try 9: temporary /O1 probe emitted only 58 bytes, wrong family; removed flag.
// - Try 10: `const short oid` also collapsed to try 1.
// Left in scratch: best source below is behaviorally right and has only the stable
//   1-byte width drift at the obj_id load (`8b54240c` vs `668b54240c`), which shifts
//   the remainder by one byte. No inline asm/hacks used.
```
<!-- end-recovered:f484fa91a7d3c4710a83 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

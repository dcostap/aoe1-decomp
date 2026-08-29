# Recovery journal: 004D0EB0 `TRIBE_Action_Make_Obj`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `accepted_drift`.
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

### wave20-tact-mob (2026-08-29)

- Result: unresolved natural reconstruction. Status remains `scratch`.
- The pinned source is the simple period-plausible body. It calls
  `RGE_Action(obj, 1)`, then assigns `pre_paid`, `unique_id`, `action_type`,
  `obj_id`, and zero `work_done`.
- The fresh baseline and final validation are both 63 bytes. The target has
  31 strict differing bytes (49.2063%), 28 edit-diff bytes (44.44%), and
  83.33% instruction-shape similarity. The first mismatch is +0x0F
  (`004D0EBF`). One direct base call is aligned. The owner symbol matches.
- Original evidence proves the parameter load order `pre_paid`, `unique_id`,
  `obj_id`, with widths 1, 4, and 2. The natural VC5 build chooses another
  register and order. The original writes fields in the order `pre_paid`,
  `unique_id`, vptr, `action_type`, `obj_id`, and `work_done`.
- Tested natural local copies and a sequenced comma expression. Both emitted
  the same 31-byte mismatch. Member initializers reduced the strict mismatch
  to 30 bytes, but produced a less similar edit alignment and a wrong field
  store order. A volatile parameter snapshot improved shape similarity but
  produced a 62-byte body and a 37-byte mismatch. These forms were rejected.
- A historical exact probe used volatile parameter snapshots and a raw vptr
  store. That source form is artificial and violates the no-manual-vptr rule.
  It is not retained.
- Focused validation: `target_session.py check` final `validation` probe;
  `check_function.py --no-build --detail concise`; both report `MISMATCH`.
  The target size, call set, owner, and boundary are correct. The audit shows
  zero relocation target mismatches and zero boundary escapes.
- Grouped validation: `build/audits/workers/wave20-tact-mob/tact_mob_cpp/`
  reports 7/7 registered exact owners matching. The translation unit has 10
  normal functions, with 3 unregistered grouped mismatches. Exact-neighbor
  count is 7.
- The clean source is pinned. Session state is active pending coordinator
  review; no status or registration change was made.
- Blocker: the remaining difference is VC5 constructor scheduling and the
  16-bit `obj_id` load. Next work should seek period source or compiler-context
  evidence. Do not retain raw vptr or volatile scheduling tricks.

### wave20-tact-mob follow-up (2026-08-29)

- The coordinator requested more natural structural tests. The exact
  `TRIBE_Action_Make_Tech` donor uses the order `unique_id`, `action_type`,
  then its short object id. Applying that order here, with `work_done` zero and
  `pre_paid` last, reduced the target to 9 differing bytes.
- The final rebuilt bytes match the original from +0x00 through +0x1E and
  from +0x28 through +0x3E. The only edit-resync hunk is the six-byte vptr
  store: the rebuilt constructor emits the relocated vptr store at +0x1F,
  before the unique-id store; the original emits it at +0x22, after that
  store. The parameter loads, all member stores, call target, size, and return
  are otherwise equal.
- Tested other natural field orders, partial member initializer lists, and a
  work-member initializer. They produced 20-32 differing bytes or the prior
  30-byte basin. Moving `work_done` and `pre_paid` does not change the 9-byte
  output. Qualified and unqualified member forms also produce the prior
  31-byte output. No new natural form reaches `MATCH`.
- Focused final validation is probe `#30` (`validation`): `MISMATCH`, 9 bytes,
  14.2857%, 90.48% edit similarity, 94.44% instruction-shape similarity,
  one aligned direct base call, owner match, and the correct 63-byte boundary.
  `check_function.py --no-build --call-map-unmatched --stack-map` confirms no
  call-target or stack-home issue. The only first hunk is the vptr scheduling
  difference at +0x1F.
- Grouped final validation is in
  `build/audits/workers/wave20-tact-mob/tact_mob_cpp/`. It reports 7/7
  registered exact neighbors matching, including the unchanged exact owners.
  Three unregistered normal functions remain grouped mismatches.
- The improved natural source is pinned. This is a narrow accepted-drift
  proposal, not a status change: the one vptr store moves across one ordinary
  member store, with no call, branch, fault, or observable effect between
  them. The coordinator must review the proposal.

### Coordinator accepted-drift review

The coordinator approved accepted drift after the wave closed. Both bodies are
63 bytes with the same base call, parameters, field values, owner, boundary,
and return. The only edit-resynchronized difference moves the implicit vptr
store across the `unique_id` store. No call or branch occurs between them. The
donor-supported natural member order remains.

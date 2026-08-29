# Recovery journal: 00488E60 `count_map_tiles`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `accepted_drift`.
- Living source: `src/rmm_terr.cpp`.
- PDB source: `C:\msdev\work\age1_x1\rmm_terr.cpp`.
- Earlier recovery note: `recovery_notes/rmm_terr_module.md`.

## Translation-unit context

- PDB module: `rmm_terr.cpp`; source order position 8 of 11 natural bodies.
- Owner: `RGE_RMM_Terrain_Generator::count_map_tiles(unsigned char)`.
- Natural source uses `map_row_offset[0]`, `map_width`, `map_height`, and typed
  `RGE_Tile` iteration. The tile record is 0x18 bytes.
- Original body is `00488E60-00488E95` (54 bytes), with no calls, no frame, and
  saved `esi` and `edi`.
- No source change remains. The direct bitfield comparison is retained because
  `RGE_Tile::terrain_type` already has the proven five-bit width.

## Current mismatch

- Fresh baseline and final natural source both emit 54 bytes with the correct
  owner, boundary, frame, saved registers, and zero calls or relocations.
- Baseline and final result: `MISMATCH`, 2 bytes, 3.7037%.
- The only difference is the order of two independent dimension loads at
  offsets `+0x0B` and `+0x0F`: original loads `[this+0x14]` then `[this+0x18]`;
  VC5 emits `[this+0x18]` then `[this+0x14]`.
- The grouped audit is under
  `build/audits/workers/wave20-rmm-terr/rmm_terr/`. It reports 8 registered
  exact neighbors and the target at 2 differing bytes.

## Recovered attempt history


<!-- recovered:10cb44ec182fa35c9214 -->
### `d050eea3c` `src/rmm_terr.cpp:257-257`

Mapping: `strong`. comment lies after mapped function count_map_tiles at old line 253.

```text
    // BINARY NOTE: The executable scans +0x10 rows with +0x18 tile records.
```
<!-- end-recovered:10cb44ec182fa35c9214 -->

<!-- recovered:2232fd3030e0905fee3f -->
### `00492347d989` `src/scratch/00488E60_count_map_tiles.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_RMM_Terrain_Generator::count_map_tiles
// VA: 00488E60
// rmm_terr.cpp:231-241
// 54 bytes, 19 diff bytes (35.19%)
// Body (35 bytes) is exact match. Prolog register scheduling differs:
// Original: eax=width*total, ecx=total*3 (overwrites this), esi=end
// Rebuilt: esi=height*total→end, ecx=total*3, eax=tileInfo (discarded)
// TU-context register allocation issue. 7+ source forms tried.
// Cleanest version kept below.
```
<!-- end-recovered:2232fd3030e0905fee3f -->

## Rejected approaches

- Reversing the multiplication operands did not change emitted code.
- Explicit local width and height temporaries did not change emitted code.
- Explicit compound multiplication did not change emitted code.
- A byte-cursor form using `reinterpret_cast`, byte offsets, and `sizeof` did
  not change emitted code. It is not retained because typed iteration is the
  simpler natural source.
- An explicit `& 0x1f` on `terrain_type` did not change emitted code. It is not
  retained because the declared five-bit bitfield already supplies the mask.
- Accessing contiguous dimensions through a local pointer did not change
  emitted code. It is not retained because direct named members are clearer.
- Moving the count initialization before pointer setup changed 19 bytes and
  was restored.

## Open questions

- Why VC5 selects the height field as the first multiply operand in this
  canonical natural translation unit remains unresolved. The old standalone
  context source reached an exact result, but it used a copied class surface
  and byte cursor, so it is not a valid natural owner.
- The remaining difference is a narrow scheduling/encoding drift with the
  same arithmetic, memory effects, control flow, calls, and fault behavior.

## Next useful approaches

- Review the accepted-drift candidate against the natural-source policy.
- If exactness is required, test only a period-plausible declaration or
  expression form that changes the VC5 multiply load order without raw byte
  access or artificial class declarations.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### wave20-rmm-terr (2026-08-29)

- Restored the clean typed scan with no source change remaining. The explicit
  terrain mask was removed because the field declaration already supplies it.
- Fresh baseline and final natural source: 2 bytes differ (3.7037%).
- Focused checker confirmed owner, 54-byte boundary, zero calls, and the two
  swapped dimension-load encodings.
- Grouped audit found 8 registered exact neighbors. The target remains scratch
  with a narrow accepted-drift proposal, not an approved status change.
- `target_session.py start` timed out while waiting for `build/target_sessions/
  sessions.lock`; the preclaimed active lease remained usable, so no retry was
  made.

### wave20-rmm-terr-r2 (2026-08-29)

- Removed the explicit `& 0x1f` after review. The declared five-bit
  `terrain_type` field already provides that mask.
- The source now matches its initial natural form; no source change remains.
- A natural count-declaration reorder changed 19 bytes. A natural `do-while`
  loop lowered to the same 2-byte mismatch. Both forms were rejected.
- Final focused rebuild remains `MISMATCH`, 2 bytes (3.7037%), with the same
  owner, boundary, calls, relocations, and dimension-load order difference.
- The refreshed grouped audit still reports 8 registered exact neighbors. The
  session remains paused and no status or registration changed.

### Coordinator accepted-drift review

The coordinator approved accepted drift after the wave closed. Both bodies are
54 bytes with the same owner, frame, saved registers, CFG, arithmetic, fields,
and return. The only change is the commutative order of the independent
`map_width` and `map_height` loads for multiplication. The typed scan remains.

# Recovery journal: 00467A50 `set_ideal_size`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `matching`.
- Living source: `src/Panel_ez.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Panel_ez.cpp`.
- Earlier recovery note: `recovery_notes/Panel_ez_module.md`.

## Translation-unit context

- PDB owner: `TEasy_Panel::set_ideal_size`, `Panel_ez.cpp` lines 559-562.
- Source order: after `set_info_file` and before `set_background`.
- The original body is `00467A50-00467A66` (23 bytes), with no relocations or
  direct calls.
- The natural body assigns `ideal_width` and then `ideal_height` from the two
  `long` parameters.
- Original owner symbol: `?set_ideal_size@TEasy_Panel@@MAEXJJ@Z`.

## Current mismatch

- Before coordinator review, `target_session.py check` could not extract the expected owner symbol:
  `Expected one defined function named '?set_ideal_size@TEasy_Panel@@MAEXJJ@Z'; found []`.
- The natural source previously emitted the same body under
  `?set_ideal_size@TEasy_Panel@@UAEXJJ@Z`. The source header places this
  virtual declaration in the public section, while the original symbol proves
  protected access (`MAE`).
- The emitted `UAEX` body is 23 bytes and matches the original bytes exactly:
  `8b4424048b5424088981f40000008991f8000000c20800`.
- The coordinator moved only this declaration to the PDB-proven protected
  section. Focused validation now reports the protected `MAEX` owner,
  `MATCH`, `0.0000%`, and the exact 23-byte boundary.

## Recovered attempt history


<!-- recovered:53e6ab50c4b74a669776 -->
### `target-session` `build/target_sessions/00467A50_set_ideal_size.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Replace the synthetic TRIBE_Screen_Sed_Open owner with PDB-proven protected virtual TEasy_Panel::set_ideal_size(long,long).
probe 2 context; result=MATCH; diff=0; shape=100.0: Walkback: restore the original wrapper include order. The anchor includes the shared header itself, so wrapper relocation is incidental. [same emitted code as probe 1]
```
<!-- end-recovered:53e6ab50c4b74a669776 -->

<!-- recovered:4b6daaeb63f7fdb3106e -->
### `82c8c744e6de` `src/matching/00467A50_set_ideal_size.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00467A50, TEasy_Panel::set_ideal_size, Panel_ez.cpp lines 559-562.
// Exact finish: the PDB-proven protected virtual long/long owner replaces a
// synthetic same-layout class. The shared class header belongs before the
// ordered Panel_ez.cpp method bodies; a repeated local include was incidental.
```
<!-- end-recovered:4b6daaeb63f7fdb3106e -->

## Rejected approaches

- Do not add a wrapper, alias, manual symbol, inline assembly, or compiler
  steering. These would hide the declaration ABI error and violate source
  policy.

## Open questions

- Can the coordinator repair the `TEasy_Panel` declaration access in the shared
  header? This worker cannot edit headers under the assigned lease.

## Next useful approaches

- Move only `set_ideal_size` to the protected virtual declaration section in
  `include/panel_ez.h`, then rerun the focused check and grouped audit.
- Confirm the expected `MAEX` symbol, 23-byte boundary, and exact bytes after
  that ABI repair.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### 2026-08-29 wave20-panel-ez

- Kept the existing natural assignment body unchanged.
- `check_function.py --rebuild` and the target-session baseline both stopped
  at expected-symbol extraction because the public `UAEX` symbol is emitted.
- The grouped audit found 66 registered owner matches. It classified this
  target as `NOT_EMITTED`; the other five grouped mismatches and two accepted
  drifts belong to other functions.
- No source improvement is available within the assigned function. The
  unresolved blocker is the shared declaration access.
- Coordinator review repaired the shared declaration access and registered the
  natural exact body.

# Recovery journal: 0047A1D0 `TPicturePanel`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Pnl_pic.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_pic.cpp`.
- Earlier recovery note: `recovery_notes/0047A1D0_TPicturePanel.md`.

## Translation-unit context

The PDB module is `Pnl_pic.cpp`. The target is the first normal function in
`src/Pnl_pic.cpp`, followed by the destructor, `setup`, `set_picture`,
`load_pic`, `free_pic`, and `draw`. The owning class is `TPicturePanel`.

The constructor spans `0047A1D0-0047A228` (89 bytes). It calls the canonical
out-of-line `TPanel::TPanel()` at `004648B0`, stores the derived vtable after
the picture-panel fields, and returns `this`.

## Current mismatch

No current mismatch remains. A direct fresh checker run reports `MATCH`,
`0.0000%`, 89/89 bytes, no frame, one aligned call, two safe relocations,
closed boundaries, and a matching owning symbol.

The first natural body used an assignment for `keep_loaded`. Its fresh
baseline was 52 bytes different. VC5 moved that store after the zero stores
and emitted the derived vtable store first. The final source uses the natural
member initializer `keep_loaded(1)`, which restores the original store order.

## Recovered attempt history


<!-- recovered:dfdacad9eebc6ea5f205 -->
### `a5fb96a1e6de` `src/scratch/0047A1D0_TPicturePanel.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TPicturePanel::TPicturePanel (0047A1D0, 89 bytes, Pnl_pic.cpp)
// Attempt 5 - minimal TPanel stub
```
<!-- end-recovered:dfdacad9eebc6ea5f205 -->

### `wave21-pnl-pic` current natural reconstruction

- Baseline body assignments: `MISMATCH`, 52 bytes, 58.4270%, same size and
  call count. The mismatch was only constructor store order and relocation
  encoding remained safe.
- Member-initializer probe: `MATCH`, 0 bytes, 0.0000%, same 89-byte size,
  one direct call, two safe relocations, and closed boundaries.
- The source remains period-plausible. It uses the canonical `TPanel` base
  and a standard member initializer. It does not use manual vtable code,
  overlays, wrappers, or inline assembly.
- Grouped `pnl_pic` audit in
  `build/audits/workers/wave21-pnl-pic/pnl_pic/report.txt` reports all seven
  included functions as matches. The target and all six registered neighbors
  have zero grouped diffs, zero relocation mismatches, and zero boundary
  escapes.

## Rejected approaches

- Plain body assignment for `keep_loaded` is rejected for code generation:
  it produced the 52-byte baseline mismatch described above.
- The earlier local `TPanel` stub and manual vtable store are not retained.
  The canonical header and out-of-line base constructor provide the proven
  ABI without artificial source.

## Open questions

The function status remains `scratch` until the coordinator reviews the exact
source and promotes it. No code-generation blocker remains.

## Next useful approaches

Review source plausibility, then promote the target if the coordinator accepts
the exact result. Do not change the constructor unless new ABI evidence
appears.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### `wave21-pnl-pic-integrate` review

- Reviewed the natural constructor form. The `keep_loaded(1)` member
  initializer is retained. No artificial vtable store, wrapper, or local base
  stub is present.
- Focused validation recorded as `probe-003-validation` reports `MATCH`,
  `0.0000%`, 89/89 bytes, the `TPicturePanel` owner, closed boundaries, one
  aligned direct call, and 2/2 safe relocations.
- The worker-specific `pnl_pic` audit reports all seven included functions as
  `MATCH`. All rows have zero grouped diffs, relocation mismatches, and
  boundary escapes. Six rows have registered owners; the scratch target is the
  one unregistered row awaiting promotion.

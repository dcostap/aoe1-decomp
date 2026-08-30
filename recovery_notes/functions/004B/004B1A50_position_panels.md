# Recovery journal: 004B1A50 `position_panels`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sed2.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sed2.cpp`.
- Earlier recovery note: `recovery_notes/scr_sed2_module.md`.

## Translation-unit context

The PDB module is `scr_sed2.cpp`, and the natural owner is
`src/scr_sed2.cpp`. The function is a `TRIBE_Screen_Sed` member in source and
address order. Its effective body is `004B1A50` through `004B29D0`
(end-exclusive), for 3969 bytes. The original symbol is public. The declaration
in `include/scr_sed.h` now has one narrow public entry for `position_panels`.

## Current mismatch

There is no current mismatch. A fresh rebuild produced 3969 bytes against the
3969-byte original. Both functions have no frame, save `esi`, and contain 1341
instructions. The owner matches
`?position_panels@TRIBE_Screen_Sed@@QAEXXZ`.

All 157 calls align at their original sites. The call map has 155 virtual calls
at the proved slots and the direct `numberLines` and `numberDrawLines` helper
calls. Both relocated call sites are safe. The CFG has 17 condition signals,
two jumps, and one return on both sides.

Focused check result: `MATCH`, `0.0000%`, 100.00% shape, 100.00% exact-block
coverage, and no positional spans.

## Recovered attempt history


<!-- recovered:3adfd4067bafba3e5a5f -->
### `d050eea3c` `src/scr_sed2.cpp:1281-1282`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// VA: 004B1A50 TRIBE_Screen_Sed::position_panels.
// BINARY NOTE: The panel cursor loops follow the adjacent array layout shown
```
<!-- end-recovered:3adfd4067bafba3e5a5f -->

<!-- recovered:c9e746e4ddc7711c16e3 -->
### `b6e159352e2d` `src/scratch/004B1A50_position_panels.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004B1A50 TRIBE_Screen_Sed::position_panels (3969 B)
// PDB source: scr_sed2.cpp:1900-2175
// Attempt log:
// - Replaced the panel-name placeholder with the binary-supported panel layout.
// - Baseline uses the recovered set_position/set_fixed_position virtual surfaces,
//   natural panel arrays, and the two layout loops shown by the source-line bands.
// - Restored omitted object, unit-list, victory, and current-message fields from
//   the proven offsets; signed /4 and %4 reproduces the victory grid arithmetic.
// - Best check is 3969/3969 bytes with 157/157 calls and 100% shape.  The only
//   drift is nine option-loop register-color bytes; the natural TTextPanel cursor
//   is retained after equivalent register probes produced no exact match.
// - Tested a TPanel base cursor for the adjacent option fields; emitted bytes
//   were unchanged, so the canonical TTextPanel cursor was restored.
```
<!-- end-recovered:c9e746e4ddc7711c16e3 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Review the exact source and promote it after the normal policy review. Do not
replace the adjacent panel cursors without new binary evidence.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### wave21-scr-sed2-integrate

The natural `position_panels` body was already present in `src/scr_sed2.cpp`.
The integration corrected only its class access declaration, moving the one
method from the protected block to the public block. This restores the original
public decorated owner without widening any other API.

Focused validation used:

```text
python tools/check_function.py --va 004B1A50 --rebuild --detail concise --checkpoint wave21-integration
```

The result was `MATCH`, `0.0000%`, with the 3969-byte boundary, public owner,
all 157 call sites, the proved virtual slots and direct helpers, and safe
relocations proved.

The grouped audit used:

```text
python tools/audit_translation_unit_observed.py --group scr_sed2 --jobs 1 --output-dir build/audits/workers/wave21-scr-sed2-integrate/scr_sed2
```

The target remained `MATCH`. All 17 registered exact neighbors remained
`MATCH`. The audit also reports the known unrelated relocation problem at
`004AE070`; it is not part of this integration.

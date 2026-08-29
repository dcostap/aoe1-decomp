# scr_sed2.cpp module merge

- PDB source: `C:\msdev\work\age1_x1\scr_sed2.cpp`.
- Source: `src/scr_sed2.cpp`.
- Header: `include/scr_sed2.h`.
- Manifest: `config/source_modules/scr_sed2.json`.
- Flags: `config/flags/scr_sed2.rsp`.

## Source order

The source owns all 19 normal PDB owners in address and source order. The
padding-only fragments at `004AE05A`, `004AEC95`, and `004AF2D2` stay excluded.
The owner sequence is:

`004ADC80`, `004ADD00`, `004ADD50`, `004ADD60`, `004AE070`, `004AE620`,
`004AE9D0`, `004AECB0`, `004AED50`, `004AEE10`, `004AF320`, `004AF6C0`,
`004B1A50`, `004B29E0`, `004B2AA0`, `004B2BC0`, `004B2C50`, `004B2DD0`,
`004B2E60`.

The module has one compiler-facing source owner. It has no per-function source
includes or wrapper source. `scr_sed2.h` composes the canonical `scr_sed.h`
screen owner. The source consumes the canonical panel, control, scenario,
world, view, shape, and scenario-editor headers.

## Context evidence

The generated module packet identifies `scr_sed2.cpp` and the line bands from
343 through 2324. The class owner for every normal entry is
`TRIBE_Screen_Sed`. The address sequence above follows the PDB line sequence.
The executable anchors include the disabled-item setters and getters, the
victory-condition scenario calls, the panel creation ranges, and the final
button helpers. The three non-behavioral entries are not source owners.

`004AE070` is the only non-exact normal owner. Its PDB owner is the protected
`TRIBE_Screen_Sed::save_victory_cond_in_scenario(int)` member. The original
switch has two selected-object setter tails that VC5 merges in the current
natural reconstruction.

## Source recovery

The direct source keeps the complete PDB body sequence and uses the canonical
screen owner from `scr_sed.h`. It removes the copied panel, control, view,
scenario, world, and scenario-editor declarations. The implementation uses
explicit casts to the canonical `T_Scenario` surface where the world stores its
base `RGE_Scenario` pointer. The call at the old local `reset` surface is the
canonical `rehook` virtual slot.

The source keeps the original screen fields, fault order, and shipped amount
versus destination predicate. The position-panel cursor loops remain because
executable evidence proves the adjacent array layout. Replacing those loops
with indexed arrays changed the function by 3312 positional bytes, so that
form is not a supported source improvement.

No synthetic body, inline assembly, fake virtual slot, fallback function, or
context-selection macro is used. The source uses `_finddata_t` and the
canonical `TEditPanel` format and `TPanel` positioning enums.

## Validation

The grouped candidate check used `src/scr_sed2.cpp` and the configured flags.
Results are:

- 18 registered owners: `MATCH`, `0.0000%`, correct boundaries, relocations,
  and direct targets.
- `004AE070`: `MISMATCH`, 771 positional bytes, two relocation target
  mismatches, and no boundary escape. It remains an observed scratch owner.

The focused checks covered all 19 normal owners. The module test passed:
`python -m unittest tests/test_scr_sed2_tu.py`.

The old wrapper, old context header, and 19 per-function source files are
removed. The direct translation-unit registry points to `src/scr_sed2.cpp`
and records the module name `scr_sed2`.

## Blockers

`004AE070` remains blocked by the unresolved VC5 merge of the case-6 and
case-9 `SetSPVictoryType`/`SetSPObject` tails and the related local-home
permutation. Further work needs a new source-context lead.

The assigned `build/source_reunification/terra_system/orchestrator_contract.md`
file was not present in this checkout. The generated packet from
`tools/plan_translation_unit.py --module scr_sed2.cpp` supplied the available
module evidence.

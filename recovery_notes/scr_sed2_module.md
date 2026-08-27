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
includes or wrapper source. The module-local header holds the reviewed panel,
scenario, world, shape, and screen layouts.

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

The direct source removes the wrapper includes and the old context header. It
also removes the screen-pointer alias in `SaveDisabledItemsInScenario`, the
`SCEN` alias macro, the absolute empty-string pointer, and the raw diplomacy
array address calculations. These changes preserve the exact bytes for the
affected registered owners. The position-panel cursor loops remain because
executable evidence proves the adjacent array layout. Replacing those loops
with indexed arrays changed the function by 3312 positional bytes, so that
form is not a supported source improvement.

No synthetic body, inline assembly, fake virtual slot, or fallback function is
used. The shipped amount-versus-destination predicate in `004AE620` remains
unchanged.

## Validation

The pre-migration candidate check used `src/scr_sed2_tu.cpp` and all old owner
files. It reported 18 of 18 exact owners as `MATCH`. The observed
`004AE070` result was `MISMATCH`, with 771 positional bytes, two relocation
target mismatches, and no boundary escape.

The post-migration direct source checks used the registered `scr_sed2` group
and the configured flags. Results remain:

- 18 registered owners: `MATCH`, `0.0000%`, correct boundaries, relocations,
  and direct targets.
- `004AE070`: `MISMATCH`, 1375 original and rebuilt bytes, 771 positional
  bytes, 53 rebuilt calls versus 55 original calls, and no boundary escape.

The focused checks covered all 19 normal owners. The module test passed:
`python -m unittest tests/test_scr_sed2_tu.py`.

The old wrapper, old context header, and 19 per-function source files are
removed. The direct translation-unit registry now points to
`src/scr_sed2.cpp` and records the module name `scr_sed2`.

## Blockers

`004AE070` remains blocked by the unresolved VC5 merge of the case-6 and
case-9 `SetSPVictoryType`/`SetSPObject` tails and the related local-home
permutation. Further work needs a new source-context lead.

The assigned `build/source_reunification/terra_system/orchestrator_contract.md`
file was not present in this checkout. The generated packet from
`tools/plan_translation_unit.py --module scr_sed2.cpp` supplied the available
module evidence.

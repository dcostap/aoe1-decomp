# scenario.cpp source reunification

The source owner is `src/scenario.cpp`, in PDB order. The normal owner set has
48 functions. The source module has 43 matching owners and 5 accepted-drift
owners.

The three nearby padding fragments at 0048C33D, 0048CE21, and 0048CE82 are not
normal owners. They stay outside the module.

## Accepted drift

- 0048AD60 has a VC5 scheduling difference in the constructor memset setup.
  The build keeps the same fields and writes.
- 0048AE10 has seven one-byte SIB base/index differences at string terminator
  stores. The writes, calls, guards, and control flow stay the same.
- 0048BCC0 and 0048BEC0 keep the same call order, guards, writes, and return
  values. VC5 caches the temporary text address before late `sprintf` calls.
  The original recomputes that address in the return blocks.
- 0048C0E0 has the same nine ordered calls and behavior. VC5 keeps the
  temporary text address in a register around the late `sprintf` calls.

These differences were accepted before source reunification. The natural source
keeps the reviewed behavior. Exact repair can resume on the final source tree.

## Reunification regression record

The old grouped wrapper and all source-bank fragments are removed. The new
module uses one direct source owner and one natural header. Rebuild metrics after
this structural change are recorded by the module validation run and may differ
from the pre-migration grouped wrapper. No behavior change was introduced to
hide a temporary exactness regression.

The reunified object differs from the prior grouped object at two reviewed
owners. 0048AE10 has one changed SIB byte. 0048C0E0 has three direct-global
relocations, because the wrapper-only target-address macro is removed. Both
forms read the same storage and keep the same control flow.

The module header declares protected virtual `get_object_pointer` and public
virtual `rehook`. Their PDB owners belong to `scenario.h`, not `scenario.cpp`.
The direct scenario object uses the shipped virtual slots.

## TPicture ownership

The PDB assigns all `TPicture` bodies to `Picture.cpp`. `include/Picture.h`
owns the complete 0x20-byte class. `scenario.h` stores only a `TPicture*`, so
it keeps a forward declaration. `scenario.cpp` includes `Picture.h` before it
constructs or destroys a picture. `diam_map.h` uses the same owner.

The old partial `TPicture` body is removed from `scenario.h`. Focused registered
checks report `MATCH` for Scenario, Picture, and Diamond Map owners.

## Source-shape cleanup

The original `.data` bytes prove the former absolute string uses:

- `00585800` is `"."`.
- `00585FE8` is `"%stemp_buildlist%d.tmp"`.
- `00585FE0` is `"%s%s.ai"`.
- `0058600C` is `"%stemp_CityPlan%d.tmp"`.
- `00586000` is `"%s%s.cty"`.
- `0057F324` is `"%s"`.

The source now uses these natural literals. `TempText1` and `TempText2` are
the reviewed fields at offsets `0x1028` and `0x1108`. `DAT_00572178` is the
canonical version constant from `game_globals.h`; the local `g_version`
declaration is removed.

The source-shape cleanup keeps all guards, calls, writes, and returns. The
registered checks for `0048C0D0` remain `MATCH`. The accepted-drift checks for
`0048BCC0` and `0048BEC0` still differ by eight emitted bytes because VC5
caches the canonical temporary-field address before late returns.

The complete polished candidate check reports `43/43` registered owners as
`MATCH`, with zero relocation mismatches and zero boundary escapes.

## Accepted-drift behavior re-review (2026-09-28)

The four assigned drift targets were checked again against their original bodies.
No behavior defect was proved, so no behavior repair was made.
The old 43/5 count above records the earlier reunification sweep.
The current translation-unit audit includes 50 functions: 46 exact and four drift targets.
0048AE10 now matches exactly; it is not one of the four current drift targets.

0048AD60 still has nine differing bytes in its constructor clear setup.
Both builds store the same fields and clear the same 4096 bytes.
An equivalent first-byte pointer expression produced the same nine-byte mismatch.
The source uses the simpler array expression.

0048BCC0 still differs by 74 bytes; 0048BEC0 and 0048C0E0 each differ by 95 bytes.
Each rebuilt getter is eight bytes shorter than the original.
All three retain the original guards, calls, arguments, memory effects, and return fields.
The rebuilt code caches the temporary-text address before `sprintf` returns.
The original recomputes the same address after `sprintf`.

The CityPlan and AI getters compare `BuildList[which_player]` with both sentinel strings.
The original executable proves this field choice.
No evidence proves that it is a defect, so the source preserves it.

The re-review removed unused two-byte padding declarations from `Get_BuildList` and `Get_CityPlan`.
PDB offsets and the AI getter's natural local layout support compiler alignment.
This cleanup changed no emitted owner bytes.

Fresh closure checks report 46 exact owners, four accepted-drift owners, and no exact regressions.
The final private audit report is `build/drift-015-scenario/module-final/report.txt`.
Function evidence is in `decomp_notes/functions/0048/0048AD60.md`, `0048BCC0.md`, `0048BEC0.md`, and `0048C0E0.md`.
No registry status changed.

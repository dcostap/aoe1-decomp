# scr_cams.cpp source composition

## PDB plan

The PDB source is `C:\\msdev\\work\\age1_x1\\scr_cams.cpp`. It owns eight
normal bodies in source order:

`004909D0`, `00490E30`, `00490EA0`, `00490F90`, `00490FF0`, `004911A0`,
`00491290`, and `00491350`.

The source-line bands are 48-125, 131-152, 158-171, 177-190, 196-241,
247-278, 284-312, and 318-419. `00490E10` is the compiler-generated
vector-deleting destructor. The constructor is the exact context anchor. The
module uses `config/flags/004909D0_TRIBE_Screen_Campaign_Selection.rsp` with
`/O2 /Oy /GX`.

## Canonical ownership

`include/scr_cams.h` owns only `TRIBE_Screen_Campaign_Selection`. It consumes
the canonical `Pnl_scr.h` screen base. The source privately includes the
canonical Panel, screen, text-list, scrollbar, dropdown, button, Base Game,
game-info, campaign, game, communications, scenario, and name-screen
providers. It does not include the old copied context hierarchy.

`src/scr_cams.cpp` owns all eight handwritten bodies in PDB order. It uses the
natural screen constructor, nested panel setup, named panel fields, game-info
calls, game option setters, scenario player setup, and communication calls.
The source uses recovered string and language literals. It uses `comm` as the
reviewed communications global because the executable loads that global at
`004915CD`, `004915E5`, and `00491603`. Derived game calls use canonical
`TRIBE_Game` static casts. Panel fields use natural `delete` expressions. No
wrapper, fragment include, context macro, fallback declaration, copied class,
raw address, raw vptr, inline assembly, C-style pointer cast, or private-symbol
alias remains.

The old `src/scr_cams_tu.cpp`, `include/scr_cams_context.h`, and eight matching
source-bank owners were removed after the complete candidate passed. The
source-module manifest and translation-unit registry now point every owner at
`src/scr_cams.cpp`.

## Status and validation

Six normal owners remain `matching`. `00490EA0` is an honest `accepted_drift`
owner because natural deletion replaces the old `delete_panel(TPanel**)`
address casts. `00491350` remains `scratch`: its natural `TRIBE_Game* game`
local replaces repeated global loads and the old `self` alias, but that change
causes a non-local 717-byte mismatch and one relocation mismatch. This is not
localized drift. The generated destructor remains compiler generated and is
not a normal source owner.

The grouped candidate is
`build/candidate_tus/scr_cams_natural_final_cleanup2/report.json`. It compiled
all eight direct owners and the generated destructor. The six matching rows
report `MATCH` and `0.0000%`. `00490EA0` reports an accepted 212-byte drift
with correct ownership and zero relocation errors. Natural deletion changes two
body boundaries. `00491350` reports a 717-byte scratch mismatch with one
relocation mismatch and zero boundary errors. The generated destructor reports
`MATCH` and `0.0000%`. The cached report predates the scratch
reclassification. It recorded the 717-byte row as accepted drift with no
comparison errors. The metadata now classifies that non-local mismatch as
scratch. No rebuild was needed for this status fix.

The candidate proposal is `build/scr_cams_natural_proposal.json`. The natural
source was also validated before and after removal of the old wrapper and
context files. The cast-cleanup candidate was validated after the rebase. No
status promotion or unrelated provider change was made.

## Provider handoff

The canonical `scr_name.h` owner now consumes the canonical Panel, dialog, and
screen providers. Its eight exact normal owners and two generated destructors
still report `MATCH` and `0.0000%`. Its two natural-delete destructors and
`004A6D50 TRIBE_Dialog_Name` are honest accepted-drift owners.

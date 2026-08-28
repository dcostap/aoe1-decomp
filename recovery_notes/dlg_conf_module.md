# dlg_conf.cpp source recovery

## PDB context

The source module is `C:\\msdev\\work\\age1_x1\\dlg_conf.cpp`.
The PDB line bands and shipped address order are:

- `0043B560`, lines 84-321, `TribeConfigDialog::TribeConfigDialog`;
- `0043C0C0`, lines 326-371, `TribeConfigDialog::~TribeConfigDialog`;
- `0043C2B0`, lines 377-647, `TribeConfigDialog::action`.

`0043C0A0` is the compiler-generated scalar deleting destructor. The class,
line bands, and address sequence prove one compiler-facing dialog module.

## Provider surface

`src/dlg_conf.cpp` now owns all three handwritten bodies in PDB order.
`include/dlg_conf.h` owns only `TribeConfigDialog` and its true
`TDialogPanel` base. The source includes the canonical panel, text, button,
slider, screen, draw-area, base-game, program-info, world, command, music,
sound, communications, and registry headers.

The body uses `RGE_Base_Game` from `include/basegame.h`. It does not declare a
local base-game layout or method surface. `RGE_Prog_Info` comes from
`include/main.h`; `RGE_Game_World` comes from `include/world.h`; and
`TRIBE_Command` comes from `include/tcommand.h`. The base-game virtual
`set_interface_messages` call uses the public `TRIBE_Game` override from
`include/tribegam.h`. The four panel-system names are natural literals.

The executable evidence labels them `Music Volume`, `Game Screen`, `Main Menu`,
and `Config Dialog`. The original action pushes them at `0043C58B`,
`0043C657`/`0043C8E0`, `0043C8FC`, and `0043C90B`. The direct module has no
unresolved `?s_*@@3PADA` references and adds no string provider.

## Status and validation

The statuses remain unchanged:

- `0043B560`: accepted drift. The fresh grouped check rebuilds 2,879 bytes
  against 2,880 original bytes, with 313 differing bytes.
- `0043C0C0`: matching. Fresh standalone check reports `MATCH`, `0.0000%`,
  485 bytes, correct owner symbol, boundaries, relocations, and direct calls.
- `0043C2B0`: scratch. Fresh standalone check rebuilds 1,601 bytes against
  1,659 original bytes, with 1,502 differing bytes and 47 aligned calls.
- `0043C0A0`: compiler-generated. Focused candidate validation reports
  `MATCH` for the 30-byte generated destructor.

The focused proposal is `build/dlg_conf_candidate.json`. Its report is
`build/candidate_tus/dlg_conf_natural/report.txt`. Candidate output is
supplemental. The reproducible exact-owner command is:

```text
python tools/check_function.py --va 0043C0C0 --rebuild --detail concise
```

The constructor and action checks remain documented mismatches:

```text
python tools/check_function.py --va 0043B560 --rebuild --detail concise
python tools/check_function.py --va 0043C2B0 --rebuild --detail concise
```

## Natural-source correction

The path-finding controls use their typed title and button arrays. They do not
depend on cross-array cursor arithmetic. The derived game and command calls
use proven `static_cast` conversions. This keeps the constructor as accepted
drift and keeps the action as scratch.

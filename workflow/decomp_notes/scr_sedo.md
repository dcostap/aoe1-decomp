# scr_sedo.cpp source-module composition

## Context

The PDB source is `C:\\msdev\\work\\age1_x1\\scr_sedo.cpp`.
The module has four normal owners in source order:

- `004B33D0` `TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open`, lines 45-99;
- `004B36A0` `TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open`, lines 104-111;
- `004B3740` `TRIBE_Screen_Sed_Open::fillList`, lines 116-149;
- `004B38A0` `TRIBE_Screen_Sed_Open::action`, lines 155-245.

The scalar deleting destructor at `004B3680` is compiler generated. It has no
source-line owner.

## Canonical ownership

`include/scr_sedo.h` owns only `TRIBE_Screen_Sed_Open`. It composes the
canonical `Pnl_scr.h` screen and panel providers. The source composes the
canonical control, program-info, BaseGame, global, and scenario-menu owners.
It has no copied panel hierarchy, wrapper, fragment, raw offset, or manual
vtable.

The source uses `TPanel::error_code` for the setup failure field. It casts the
canonical `RGE_Base_Game` global to `TRIBE_Game` only for the proven
`start_scenario_editor` call. `TRIBE_Screen_Sed_Menu` comes from
`include/scr_sedm.h`.

## Candidate validation

Candidate: `build/scr_sedo_natural_candidate.json`.
Report: `build/candidate_tus/scr_sedo_natural/report.json`.

- `004B33D0`: `MATCH`, 683 bytes, zero relocations, zero boundary escapes.
- `004B36A0`: 176 differing bytes, 206 rebuilt bytes, two boundary escapes,
  and zero relocations.
- `004B3680`: generated `MATCH`, 30 bytes.
- `004B3740`: four differing bytes, 352 rebuilt bytes, zero relocations, zero
  boundary escapes.
- `004B38A0`: 569 differing bytes, 997 rebuilt bytes, zero relocations, zero
  boundary escapes.

The constructor remains an exact registered owner. The destructor is scratch
because direct typed deletion changes its emitted body and boundary. `fillList`
remains scratch because its natural canonical output differs by four local stack
bytes. `action` is scratch because stack overlap removal causes a larger
natural codegen change, and its changed overflow and fault behavior needs
review. All four normal bodies stay in the complete source module and preserve
PDB order.

The natural source removes pointer casts, child-pointer address casts, the
`OFSTRUCT` buffer overlay, and `+4` stack shaping. It uses direct list and
control calls, independent arrays, and a typed `OFSTRUCT` local.

## Rebase validation

The provider commits were rebased onto main `6d8915d72`. The fresh candidate
is `build/candidate_tus/scr_sedo_natural_rebased/report.json`.

The rebased build gives the same results: the constructor and generated
destructor match. The natural destructor differs by 176 bytes and has two
boundary escapes. `fillList` differs by four bytes. `action` differs by 569
bytes. All four normal bodies remain in `src/scr_sedo.cpp`, and the registered
translation-unit owners contain only `004B33D0`.

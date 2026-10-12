# Scr_sing.cpp source reunification

## Module

- PDB source: `C:\\msdev\\work\\age1_x1\\Scr_sing.cpp`.
- Source: `src/scr_sing.cpp`.
- Header: `include/scr_sing.h`.
- Flags: `config/flags/gx.rsp` (`/GX`).
- Owners: four normal functions in PDB source order; three are exact claims.
- Generated entry: `004B6BE0`, vector-deleting destructor. It has no handwritten source owner.

The source-line bands and address sequence are:

| VA | PDB lines | bytes | owner |
| --- | ---: | ---: | --- |
| `004B69A0` | 55-106 | 573 | `TribeSPMenuScreen::TribeSPMenuScreen()` |
| `004B6C00` | 111-117 | 129 | `TribeSPMenuScreen::~TribeSPMenuScreen()` |
| `004B6C90` | 123-128 | 33 | `TribeSPMenuScreen::handle_idle()` |
| `004B6CC0` | 134-318 | 1138 | `TribeSPMenuScreen::action` |

All four owners belong to `TribeSPMenuScreen`. The class size is `0x49C`.
The PDB symbols, source lines, and ascending addresses prove this context.

## Ownership

`src/scr_sing.cpp` is the compiler-facing source owner for all four normal
functions. The source follows PDB order. `include/scr_sing.h` owns only
`TribeSPMenuScreen`. Shared Panel, BaseGame, tribe game, settings, game-info,
list, button, and screen surfaces come from owner headers.

The old `scr_sing_tu.cpp` wrapper, context header, and four source-bank owner
files are obsolete. They are removed after this direct module validation.
The foreign screen headers used for construction now consume the canonical
screen base instead of redeclaring Panel, BaseGame, game, list, or button
classes.

The constructor preserves setup failure, seven button slots, title and close
button creation, labels, hotkey fields, current child, and tab order. The
action preserves button order, game state updates, people-list cleanup, child
construction, panel transitions, and fallback dispatch.

The destructor uses a `TPanel*` temporary for each derived member and calls
`delete_panel` with that temporary. This avoids pointer-address casts. Its
natural form is `scratch`: the current build reports a 159-byte difference.

## Validation

Candidate validation:

`python tools/validate_candidate_tu.py --proposal build/candidate_tus/scr_sing_natural/proposal.json --output-dir build/candidate_tus/scr_sing_natural/final`

| VA | kind | status | result | diff bytes | relocations | boundary escapes |
| --- | --- | --- | --- | ---: | ---: | ---: |
| `004B69A0` | exact | matching | `MATCH` | 0 | 0 | 0 |
| `004B6C00` | exact | matching | `MATCH` | 0 | 0 | 0 |
| `004B6C90` | exact | matching | `MATCH` | 0 | 0 | 0 |
| `004B6CC0` | exact | matching | `MATCH` | 0 | 0 | 0 |
| `004B6BE0` | generated | compiler_generated | `MATCH` | 0 | 0 | 0 |

The earlier candidate had four exact normal owners. The generated destructor
also matched. The typed destructor is now scratch and is excluded from the
current exact registration.

## Exact finish

The first direct source used direct `button[5]` member assignments. It matched
all owners except the constructor, with 74 positional bytes and two boundary
escapes. The first constructor mismatch occurred at `004B6A89`.

The reduced source declares one natural `TButtonPanel* cancel` local before
the two hotkey assignments. This restores the original member receiver save
and keeps the source readable. The constructor then matches at 573 bytes.

Walking back this local restores the 74-byte mismatch. The other constructor
changes are required for canonical typed ownership and remain in the source.
The retained form is the smallest natural source that matches.

## Open questions

- Review consumers that still need a complete `TribeSPMenuScreen` type after
  the old context header removal.

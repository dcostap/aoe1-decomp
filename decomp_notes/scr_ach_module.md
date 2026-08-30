# scr_ach.cpp source reunification

## Source context

The PDB source is `C:\\msdev\\work\\age1_x1\\scr_ach.cpp`.
The eight normal owners span lines 110 through 936 and keep this address order:

`0048D530`, `0048E210`, `0048E400`, `0048F0B0`, `0048F190`, `0048F280`,
`0048F500`, `0048F530`.

All owners are `TribeAchievementsScreen` members. The vector-deleting
destructor at `0048E1F0` is compiler generated and has no ordinary source
owner.

The constructor and mode setup own the long setup and statistics paths. The
remaining owners are the destructor, draw, input, action, idle, and window
handlers. The PDB line bands, address sequence, base-constructor anchor, and
ordered panel, player, victory-condition, and game calls establish this
translation-unit context.

`0048D530` ends at `0048E1D2`; the generated vector-deleting destructor at
`0048E1F0` is outside handwritten ownership. `0048F530` ends at `0048F5C1`;
padding follows to the next compiland owner.

## Source ownership

`src/scr_ach.cpp` contains all eight handwritten owners in PDB order. The
module uses `include/scr_ach.h` for its declarations and has no wrapper,
function-fragment include, context macro, or fallback declaration block.

The constructor and `set_mode` retain the reviewed typed panel, player, world,
and victory-condition surfaces. They use indexed statistics storage and retain
the ordered mode-3 victory-ID calls. These facts preserve observed local state
and fault order.

The constructor uses the period `set_positioning` and `set_tab_order` virtual
surfaces. The call arguments and slots are proved by the original calls at
`0048DA18`, `0048E17E`, and `0048E18C`. The previous `vf_*` declarations were
codegen-only residue and are removed.

The constructor `0048D530`, destructor `0048E210`, and `set_mode` owner
`0048E400` are scratch. The other five owners remain registered matching
owners.

## Function notes

The constructor uses 260-byte `info_file` storage. A 256-byte probe matched
the frame but lacks packet support. The player loop uses a zero-based row index
and reads `world->players[player_index + 1]`. It preserves the eight player
slots and their original player-array positions. The source has the explicit
mode-selection branch and the panel surface proved by the translation-unit
packet.

The constructor remains scratch at the current 2830-byte difference. A
rejected 48-byte local variant matched the frame but used compiler steering. An
uninitialized temporary was also rejected because VC5 removed it and changed
the frame. The next useful evidence is a fresh exact constructor context check
after the module move.

`set_mode` uses `statistics[player][column]`. It does not use a row cursor or
negative array indexes. A raw two-byte player cursor can recover setup blocks
but reverses the mode-3 victory-ID calls at `0048ED20` and `0048ED2A`. That
form is rejected because it changes fault order. The natural source keeps
explicit sequencing and is scratch after this cleanup.

## Validation and regressions

The pre-migration wrapper was `src/scr_ach_tu.cpp`. It included one source
fragment for each owner and selected `include/scr_ach_context.h` with a context
macro. The migrated source uses one direct compiler-facing owner and the
module-local header.

The constrained grouped audit was run once as
`python tools/audit_translation_unit_observed.py --group scr_ach --jobs 1
--output-dir build/audits/scr_ach_final --print-full`. It compiled all eight
owners and found six registered exact owners with zero positional differences,
zero relocation mismatches, and zero boundary escapes. This result predates
the typed cleanup. Current status comes from the later candidate validation.

The three cached standalone checks attempted for `0048E210`, `0048F0B0`, and
`0048F280` rejected stale artifacts after the final source/config cleanup.
They did not rebuild because the assignment permits cached checks only. The
module test passes with two tests.

The natural typed close-button deletion differs by 435 bytes and has two
boundary escapes. `0048E210` is no longer an exact owner. The indexed
statistics cleanup changes `0048E400` by 2970 bytes. It is scratch, not
accepted drift.

## Canonical panel-provider cleanup

`include/scr_ach.h` now includes `Pnl_scr.h`. It owns only
`TribeAchievementsScreen` and its typed fields. It no longer defines copied
Panel, Easy Panel, Screen Panel, child panel, Draw Area, Base Game, game, or
world types.

`src/scr_ach.cpp` privately includes the canonical child-panel, Shape, Base
Game, game, player, world, victory, scenario, and color providers. The source
uses `color_table->id`, `game_status`, `render_area->Wnd`, and a `TRIBE_Game`
cast. These names map to the original field offsets and direct targets.

`include/tpnl_tml.h` now owns the complete `Time_Line_Panel` class. The
achievements header includes it directly. It has no caller-side timeline
declaration.

Candidate validation reports all five registered owners as `MATCH` with zero
differences. The generated deleting destructor also matches. The constructor
remains scratch with 2830 differing bytes. The destructor remains scratch with
435 differing bytes and two boundary escapes. `set_mode` remains scratch with
2970 differing bytes.

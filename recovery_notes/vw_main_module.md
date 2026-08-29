# `vw_main.cpp` recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\vw_main.cpp`.
- Source: `src/vw_main.cpp`.
- Header: `include/vw_main.h`.
- Flags: `config/flags/default.rsp`.
- Normal owners: 27. The PDB line order is `0053DAB0` through `00540700`.

## Ownership

`RGE_Main_View` owns this module. It uses canonical View, Player, World, Map,
Sprite, Static Object, visibility, task-list, and master-action headers.
View owns `RGE_Pick_Info`, `RGE_Pick_Obj_Info`, and `Picked_Objects`.
`vw_main.h` consumes that surface through `view.h`.

The source has no View-local compatibility class, context header, wrapper, raw
vtable, or copied Sprite class. `0053DB10` is the compiler-generated deleting
destructor. `0053E8E9` is padding only. Neither has a source body here.

## Status

These direct owners remain exact: `0053DAB0`, `0053DB40`, `0053DBA0`,
`0053E280`, `0053E2F0`, `0053F660`, `0053F6B0`, `0053F6F0`, `0053F800`,
`0053F810`, `0053FA10`, `0053FFB0`, `00540350`, `00540420`, `005405C0`,
`005405E0`, `00540680`, and `00540700`.

`0053DEB0`, `0053E340`, `0053E7F0`, `0053E910`, `0053F220`, `0053F2F0`,
`0053F3D0`, `0053FBD0`, and `00540010` are scratch. Their direct sources have
correct owners and relocation targets. `0053E910` has relocation mismatches.
No source is retained for its byte score.

The policy repair replaced stack-slot aliases in the two mouse-up handlers with
named `selected_objects` and `selected_count` locals. It also uses canonical
hierarchy casts. These changes leave all registered exact owners unchanged.

## Validation

`python tools/validate_candidate_tu.py --proposal
build/vw_main_natural_proposal.json --output-dir
build/candidate_tus/vw_main_natural_policy_repair` compiled the repaired source.

All 18 matching owners report `MATCH`, `0.0000%`, correct ownership,
relocations, and boundaries. The generated deleting destructor also reports
`MATCH`.

## Global-storage consolidation repair

The canonical `game_globals.h` declarations for `00577900`, `00577904`, and
`00577908` are non-const `float` objects. The global inventory records the
same type, and the original view code uses direct `float` relocations at its
`FLD`, `FCOMP`, and `FSUB` sites. The three local `extern const float`
declarations therefore conflicted with the canonical declarations. They were
removed from `src/vw_main.cpp`. The duplicate local declarations for
`allow_user_commands` and `do_draw_log` were also removed; canonical headers
already provide those declarations.

On 2026-08-29, the complete registered group compiled through
`build/manifests/build_tu_vw_main.json`. Owners `0053DAB0` and `0053DBA0`
both report `MATCH`, `0.0000%`, correct ownership, boundaries, and all
relocations. The PDB source map identifies `0053DBA0` as
`RGE_Main_View::do_auto_scroll` in `vw_main.cpp`. It covers the repaired
scrolling-global references.

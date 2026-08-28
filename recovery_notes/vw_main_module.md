# `vw_main.cpp` recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\vw_main.cpp`.
- Source: `src/vw_main.cpp`.
- Header: `include/vw_main.h`.
- Flags: `config/flags/default.rsp`.
- Normal owners: 27. The PDB line order is `0053DAB0` through `00540700`.

## Ownership

`RGE_Main_View` owns this module. It uses canonical View, Player, World, Map,
Sprite, Static Object, visibility, task-list, and master-action headers.
`RGE_Pick_Info` stays in `vw_main.h` with its owning view consumer.

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
correct owners and relocation targets. `0053E910` has one relocation mismatch.
No source is retained for its byte score.

## Validation

`python tools/validate_candidate_tu.py --proposal
build/vw_main_natural_proposal.json --output-dir
build/candidate_tus/vw_main_natural` compiled the direct source.

All 18 matching owners report `MATCH`, `0.0000%`, correct ownership,
relocations, and boundaries. The generated deleting destructor also reports
`MATCH`.

# `m_s_obj.cpp` recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\m_s_obj.cpp`.
- Source: `src/m_s_obj.cpp`.
- Header: `include/m_s_obj.h`.
- Flags: `config/flags/00452FE0_make_new_obj.rsp`.
- Normal owners: 23, in source and address order from `00452120` to
  `00454980`.

## Ownership

`RGE_Master_Static_Object` owns this module. It uses canonical BaseGame,
Player, World, Map, Static Object, Master Combat, Sprite, Sound, visibility,
color, View, and string headers. The source has no context header, wrapper,
local carrier, copied class, or manual vtable.

`00452150` is the compiler-generated deleting destructor. `00453695` is a
reviewed padding-only entry. Neither has a source body.

**ORIGINAL BUG:** `save` writes two bytes at `damage_percent`, though the field
is one byte. The original save stream proves this overlap. Keep this file-format
behavior. It does not define an object-layout access pattern.

## Status

These direct owners are exact: `00452120`, `00452170`, `004521A0`,
`004524E0`, `00452FA0`, `00452FE0`, `004530B0`, `00453120`, `004534A0`,
`00453540`, `004535F0`, `004536D0`, `004543C0`, `00454690`, `004547F0`,
`00454950`, `00454960`, `00454970`, and `00454980`.

`004521E0`, `00452B00`, `00453C40`, and `004543D0` remain scratch.
`004521E0` uses a natural indexed copy of its three typed arrays. It differs by
230 bytes and has one relocation mismatch. The file parser and placement source
use named fields, typed tile access, and typed object lists. No scratch source
is registered as exact.

## Validation

`python tools/validate_candidate_tu.py --proposal
build/m_s_obj_natural_proposal.json --output-dir
build/candidate_tus/m_s_obj_natural_final` compiled the direct source.

All 19 exact owners report `MATCH`, `0.0000%`, correct ownership, relocations,
and boundaries. The generated deleting destructor also reports `MATCH`.

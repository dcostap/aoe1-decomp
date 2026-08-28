# `misl_obj.cpp` recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\misl_obj.cpp`.
- Source: `src/misl_obj.cpp`.
- Header: `include/misl_obj.h`.
- Flags: `config/flags/0045AB20_make_object_collision_list.rsp`.
- Normal owners: 11. The PDB line order is `0045A740` through `0045AB20`.

## Ownership

`RGE_Missile_Object` owns this module. It derives from the canonical combat,
action, moving, animated, and static object owners. The source uses the
canonical Action Missile/List, combat-master, player, world, map, tile,
object-list, and collision-list declarations.

The source has no context header, copied hierarchy, manual vptr, raw cursor
layout, alias union, padding carrier, or wrapper. The collision scan uses
natural typed rows, tiles, and object nodes.

`0045A7D0` and `0045A7F0` are compiler-generated destructor neighbors. The
inherited virtual destructor surface emits them. `0045A7EE` and `0045A8FF` are
not normal PDB owners. They remain outside this source module.

## Status

The direct compiland keeps these exact owners: `0045A740`, `0045A800`,
`0045A870`, `0045A8A0`, `0045A900`, `0045A910`, `0045A940`, `0045A950`,
`0045A9E0`, and `0045AA70`.

`0045AB20` is scratch. Its natural collision scan has 542 differing bytes.
It has the correct symbol, boundary, and relocation targets. Do not retain the
old raw row and tile cursors for byte score alone.

## Validation

`python tools/validate_candidate_tu.py --proposal
build/misl_obj_natural_proposal.json --output-dir
build/candidate_tus/misl_obj_natural` compiled the direct source.

All ten matching owners report `MATCH`, `0.0000%`, correct ownership,
relocations, and boundaries. Both compiler-generated destructor neighbors also
report `MATCH`. The scratch owner reports a correct owner, zero relocation
target mismatches, and zero boundary escapes.

The shared `config/translation_units.json` entry still names the removed
wrapper. The parent integration pass must update it to `src/misl_obj.cpp` and
register the direct owners.

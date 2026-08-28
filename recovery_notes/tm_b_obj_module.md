# `tm_b_obj.cpp` recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\tm_b_obj.cpp`.
- Source: `src/tm_b_obj.cpp`.
- Header: `include/tm_b_obj.h`.
- Flags: `config/flags/0050E040_TRIBE_Master_Building_Object.rsp`.
- Normal owners: 17. The PDB line order is `0050E040` through `0050E950`.

## Ownership

`TRIBE_Master_Building_Object` derives from the canonical
`TRIBE_Master_Combat_Object` owner. The executable at `00512A90` creates the
0x164-byte combat master for type `F` and this 0x17C-byte building master for
type `P`. These direct targets disprove separate Fish and Projectile classes.

The header keeps check placement at vtable +0x20, alignment at +0x24, draw at
+0x34, and the five-argument factory at +0x3C. The source uses real inheritance
and natural constructors. It has no vptr store, raw layout, context header,
or wrapper.

`copy_obj` receives a building-master source through the base pointer. The PDB
owner type and the copied fields after +0x164 prove the one downcast.

## Status

These direct owners remain exact: `0050E040`, `0050E0C0`, `0050E130`,
`0050E1B0`, `0050E430`, `0050E440`, `0050E4D0`, `0050E500`, `0050E530`,
`0050E550`, `0050E630`, `0050E6B0`, `0050E730`, and `0050E950`.

`0050E250` and `0050E360` are scratch. Their natural file-load setup bodies
have 71 and 90 differing bytes. `0050E7A0` remains scratch pending a source
review. It happens to match in the direct candidate. No status changed from a
single first result.

## Validation

`python tools/validate_candidate_tu.py --proposal
build/tm_b_obj_natural_proposal.json --output-dir
build/candidate_tus/tm_b_obj_natural` compiled the direct source.

All 14 matching owners report `MATCH`, `0.0000%`, correct ownership,
relocations, and boundaries. The three scratch owners have correct ownership,
zero relocation-target mismatches, and zero boundary escapes. The generated
deleting destructor at `0050E0A0` also reports `MATCH`.

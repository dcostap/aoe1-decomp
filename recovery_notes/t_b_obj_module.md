# t_b_obj.cpp source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\t_b_obj.cpp`.
- Source owner: `src/t_b_obj.cpp`.
- Header: `include/t_b_obj.h`.
- Normal owners: 40, in PDB order from `004C7F50` through `004CA0B0`.
- Compiler-generated neighbor: `004C8090`, the scalar deleting destructor.

## Context gate

The PDB source path, line bands, and address order identify one direct module.
The source order is the address order in the original PDB bands. Exact anchors
include the constructors at `004C7F50` through `004C81D0`, the destructor at
`004C82A0`, and the first queue owner at `004C9870`.

The old partial wrapper was `src/t_b_obj_tu.cpp`. It included 40 owner fragments
and `include/t_b_obj_context.h`. The direct source has no wrapper include, no
context-selection macro, no copied base classes, no raw offset layout, and no
manual vptr store.

## Canonical ownership

`TRIBE_Building_Object` now composes the canonical `TRIBE_Combat_Object` header.
Its queue fields start at `+0x1C8` and the object size is `0x204`.
`tm_co_ob.h` supplies the canonical master-combat base and `RGE_Master_Static_Object`
fields. The building-master fields at `+0x164` through `+0x178` are declared in
`t_b_obj.h` because the repository has no published `m_b_obj.h` owner header.

The canonical `tplayer.h` header supplies `TRIBE_Player`, including the cost
methods, `registerBuild`, and the `tech_tree` owner at `+0x220`.
The canonical `world.h` header supplies `RGE_Game_World`, and `map.h` supplies
`RGE_Map` and `RGE_Tile`. `TRIBE_World::check_destructables` is still absent
from the canonical world header. The direct source has a method-only declaration
for that owner. It adds no fields or vtable slots.

`TRIBE_Player_Tech::do_tech` and `undo_tech` are also absent from the small
canonical `tech.h` surface. The t_b header keeps only these two method
signatures. This is a declaration gap, not a copied object layout.

## Status ledger

The module keeps the existing reviewed source statuses:

- `matching`: 33 owners;
- `accepted_drift`: 5 owners (`004C85D0`, `004C86C0`, `004C8CB0`, `004C9870`,
  and `004C9C80`);
- `scratch`: 2 owners (`004C8A60` and `004C8E90`);
- `verified_logic`: 0 owners.

The direct source contains all 40 normal bodies. The statuses remain source
recovery states. They do not claim grouped exactness after context migration.

## Candidate validation

Candidate proposal:
`build/candidate_tus/t_b_obj_direct/proposal.json`.

The candidate compiled all 40 normal comparison entries and the generated
scalar destructor. It produced these
exact owners in the direct module: `004C8370`, `004C8B80`, `004C8E60`,
`004C9480`, `004C9760`, `004C9D90`, and `004CA0B0`. The scratch owner
`004C8A60` also produced a match, but its status remains scratch. The remaining
entries are observed mismatches or accepted source states. The generated
`004C8090` destructor also matched through its VC5 weak `??_G` fallback.

The grouped result is diagnostic. Source recovery did not byte-tune the scratch
owners. Exactness must be rechecked after the main agent registers the direct
module in `config/translation_units.json`.

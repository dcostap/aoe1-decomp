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

`TRIBE_Building_Object` now composes canonical `TRIBE_Combat_Object` and
`TRIBE_Master_Building_Object` owners. Its queue fields start at `+0x1C8` and
the object size is `0x204`. The building-master fields at `+0x164` through
`+0x178` live in `include/tm_b_obj.h`.

The canonical `tplayer.h` header supplies `TRIBE_Player`, including cost
methods, `registerBuild`, and `tech_tree` at `+0x220`. The canonical
`tworld.h` header supplies `TRIBE_World::check_destructables`. The canonical
`tech.h` header declares `do_tech` and `undo_tech`. No local class carrier
remains.

## Status ledger

The direct candidate keeps these source statuses:

- `matching`: 7 owners (`004C8370`, `004C8B80`, `004C8E60`, `004C9480`,
  `004C9760`, `004C9D90`, and `004CA0B0`);
- `accepted_drift`: 5 owners (`004C85D0`, `004C86C0`, `004C8CB0`, `004C9870`,
  and `004C9C80`);
- `scratch`: 28 owners, including `004C8A60` and `004C8E90`;
- `verified_logic`: 0 owners.

The direct source contains all 40 normal bodies. The migration moves the 26
former fragment matches that did not remain exact into scratch. It does not
claim grouped exactness for them.

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
functions. The migration check found seven exact functions.

## Compile debt validation

The registered group compiles with `python tools/build_function.py --va
004C8370 --force`.  Representative owner `004C8370` reports `MATCH` and
`0.0000%`.  No source or ABI repair was needed in this module.

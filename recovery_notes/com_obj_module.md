# com_obj.cpp source reunification

- PDB source: `C:\msdev\work\age1_x1\com_obj.cpp`.
- Source: `src/com_obj.cpp`.
- Header: `include/com_obj.h`.
- Owners: 50 normal functions, in PDB source order.
- Generated neighbor: `0042F9C0` vector deleting destructor.

## ABI review

The reviewed class inventory identifies `RGE_Combat_Object` as a derived
`RGE_Action_Object` with size `0x1C4`. The combat fields occupy `+0x194` through
`+0x1C0`, followed by three bytes of tail padding. The declaration surface uses
that reviewed base and virtual-slot surface. This migration adds no unsupported
base, inheritance edge, or virtual slot.

The source keeps the proven member signatures. In particular, the four output
helpers use references, the combat overloads keep their distinct return types,
and the inherited calls stay typed member calls. The vector deleting destructor
is compiler generated and is not a handwritten owner.

`RGE_Static_Object::master_obj` stays a `RGE_Master_Static_Object*`. Each
combat field access uses one local `static_cast<RGE_Master_Combat_Object*>`.
Moving and static fields use their reviewed base types. No source adds a shadow
master field, view, or accessor.

## Migration

The old per-function fragments and `src/com_obj_tu.cpp` wrapper supplied the
source evidence. The new source owns all 50 handwritten bodies directly. It
removes source-bank includes, recovery contexts, and the absolute map-offset
macro. `unified_map_offsets` uses the reviewed pointer-table symbol.

Commands use `actions`, `getTask`, and `set_only_action`. The source uses the
typed visible manager, world delta, map rows, map tiles, and file I/O surface.
It does not retain local links, raw field access, task creators, or visibility
global substitutes.

The static-object header had one unsupported nonvirtual six-argument `notify`
declaration. It had no PDB symbol or executable owner. Removing it lets the
proved virtual notify call retain its source ABI.

## Candidate validation

The candidate used `config/flags/default.rsp` through
`tools/validate_candidate_tu.py`.

- 44 normal owners were checked.
- 28 owners matched with zero relocation mismatches and no boundary escapes.
- `0042F9C0` generated scalar deleting destructor matched.
- 16 former matching owners are now scratch:
  `0042F930`, `0042F9E0`, `0042FA50`, `0042FC50`, `0042FCA0`, `00430230`,
  `004304B0`, `00430510`, `00430570`, `004305A0`, `004308C0`, `00430A90`,
  `00430C30`, `00431150`, `00431340`, and `004314F0`.
- `0042FCA0` has three boundary escapes. `004314F0` has one.
- The six prior observed bodies remain observed. Their statuses stay unchanged.
- The report has zero comparison errors.

Exact repair resumes on this source tree.

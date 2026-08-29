# RMM Terrain Generator owner-only header

## Integrated owner

`include/rmm_terrain_generator.h` is the declaration surface for
`RGE_RMM_Terrain_Generator`. The natural source module includes it directly.
Terrain Info records remain in `include/rmm_terrain_info.h`.

The generator header includes only `rmm_base.h` and `rmm_terrain_info.h`. It
forward-declares `RGE_Zone_Map`. It does not declare Tile, Map context, globals,
padding fields, or unions.

CNTR and DBCT include this owner-only header when they create a terrain
generator. They include `rmm_terrain_info.h` for direct record use.

The old context-heavy `include/rmm_terr.h` provider is removed. It duplicated
the RMM base and generator declarations.

## PDB and CodeView evidence

The PDB source map assigns the complete Terrain generator sequence to
`C:\\msdev\\work\\age1_x1\\rmm_terr.cpp`:

- `004888E0` constructor
- `00488920` `generate`
- `004889D0` `water`
- `004889F0` `check_borders`
- `00488B90` `check_terrain`
- `00488D50` `generate_modifiers`
- `00488E40` `fig_chance`
- `00488E60` `count_map_tiles`
- `00488EA0` `link_stack_randomly`
- `00488F90` `remove_area_from_lists`
- `00489030` `base_terrain_generate`

The source map rows are `inventory/pdb/function_source_map.csv:3272-3282`.
The CodeView class record is `inventory/types/dumps/RGE_RMM_Terrain_Generator.txt`.
It proves:

| Member | Offset | Size |
| --- | ---: | ---: |
| `RGE_Random_Map_Module` base | `0x00` | `0x30` |
| `RGE_Terrain_Info info` | `0x30` | `0x1298` |
| `RGE_Zone_Map* map_zone` | `0x12C8` | `0x04` |
| Complete generator | `0x00` | `0x12CC` |

`inventory/classes/dumps/RGE_RMM_Terrain_Generator.txt` gives high-confidence
layout, donor-header, base-match, and size-match evidence. It lists all 11
methods and the constructor signature:

```cpp
RGE_RMM_Terrain_Generator(RGE_Map*, RGE_Random_Map_Module*, RGE_Terrain_Info*);
```

The proposed header declares those 11 methods with the CodeView/PDB types and
order. The base and stack types come from `rmm_base.h`. The three Terrain Info
records come from `rmm_terrain_info.h`.

## Constructor evidence

`inventory/functions/0048/004888E0_RGE_RMM_Terrain_Generator.txt` proves the
constructor body range `004888E0-0048891A` and size `59` bytes. It shows:

- A call to `RGE_Random_Map_Module::RGE_Random_Map_Module`.
- The generator vtable store.
- A `0x4A6`-dword copy into `this + 0x30`.
- `schedule = 2.0f` at `this + 0x1C`.
- The `__thiscall` constructor cleanup of `0x0C` bytes.

The direct call sites are CNTR `00482864` and DBCT `00483475`.

## VC5 layout probe

The build-only probe is `build/probes/rmm_terrain_generator_layout.cpp`.
It checks the base size, Info size, generator size, and the `info` and
`map_zone` offsets through a derived access probe.

The pinned VC5 compiler `11.00.7022` compiled and linked the probe with
`/nologo /O2 /Oy`. The executable returned `0`.

Results:

- `sizeof(RGE_Random_Map_Module) == 0x30`
- `sizeof(RGE_Terrain_Info) == 0x1298`
- `sizeof(RGE_RMM_Terrain_Generator) == 0x12CC`
- `info == +0x30`
- `map_zone == +0x12C8`

The probe is a build artifact. It is not a source owner.

## Focused constructor candidate

The build-only candidate is `build/probes/rmm_terrain_generator_ctor.cpp`.
It uses the owner-only header and the natural constructor form:

```cpp
: RGE_Random_Map_Module(map, parent, 1)
{
    this->info = *info;
    this->schedule = 2.0f;
}
```

The pinned VC5 compiler produced a `59`-byte effective function span. The
original and rebuilt spans are both `59` bytes.

A relocation-aware positional comparison returned `MATCH` and `0.0000%`:

- Diff bytes after relocation masking: `0`
- Compatible relocations: `2`
- Incompatible relocations: `0`
- Boundary escapes: `0`
- Direct target mismatches: `0`

The two compatible relocation sites are the base constructor call and the
Terrain generator vtable. Raw bytes differ only in those unresolved relocation
slots.

The complete natural source now uses this header. The grouped candidate keeps
the retained exact owners in the registered `rmm_terr` translation unit.

## Integration boundary

**Recommendation:** Keep `include/rmm_terrain_info.h` as the sole owner of the
Terrain Info records. Keep this header as the sole owner of the Terrain
generator declaration surface.

**Recommendation:** CNTR and DBCT consumers should include this header for the
complete generator declaration and `rmm_terrain_info.h` for direct record use.

**Recommendation:** Do not move generator or base declarations into
`rmm_terrain_info.h`. Do not add context macros or a second generator or record
owner.

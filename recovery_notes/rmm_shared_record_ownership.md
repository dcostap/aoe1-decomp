# Shared RMM record ownership recommendations

This is a recommendation-only dossier. It does not claim to recover the
unseen original header declarations. The PDB assigns functions to compilands,
not declarations to headers.

## Recommended family owners

| Family | Recommended canonical owner header | Related generator source | Proven size |
| --- | --- | --- | ---: |
| `RGE_Land_Info_Line`, `RGE_Land_Info` | `include/rmm_land.h` | `rmm_land.cpp` | `0x34`, `0x1438` |
| `RGE_Terrain_Info_Line`, `RGE_Terrain_Hot_Spots`, `RGE_Terrain_Info` | `include/rmm_terr.h` | `rmm_terr.cpp` | `0x20`, `0x10`, `0x1298` |
| `RGE_Object_Info_Line`, `RGE_Land_Point_Info_Line`, `RGE_Object_Info` | `include/rmm_obj.h` | `rmm_obj.cpp` | `0x30`, `0x10`, `0x18C8` |
| `RGE_Elevation_Info_Line`, `RGE_Elevation_Hot_Spots`, `RGE_Elevation_Info` | `include/rmm_elev.h` (future owner-only header) | `rmm_elev.cpp` | `0x18`, `0x10`, `0xF80` |
| `RGE_Land_Data_Entry`, `RGE_Land_Data`, and the other DBCT data records | `include/rmm_dbct.h` | `rmm_dbct.cpp` | `0x2C`, `0x08` where applicable |

**Recommendation:** Keep `RGE_RMM_Land_Generator` in `rmm_land.h`,
`RGE_RMM_Terrain_Generator` in `rmm_terr.h`, and
`RGE_RMM_Object_Generator` in `rmm_obj.h`.

**Recommendation:** Create `include/rmm_elev.h` later as the owner-only
Elevation record and generator header. `include/rmm_elev_context.h` is a
legacy compiler context. It is not canonical and cannot be an owner.

**Recommendation:** Keep `RGE_RMM_Database_Controller` and its file-data
records in `rmm_dbct.h`. Do not make that header the owner of the four
run-time `*_Info` families. DBCT stores and passes those records, but its
source does not own their generator methods.

## Evidence

### PDB compilands

- `inventory/pdb/function_source_map.csv` assigns all five Land owners
  `00485200` through `00485520` to `rmm_land.cpp`.
- The same map assigns the Terrain generator owners to `rmm_terr.cpp`, the
  Object generator owners to `rmm_obj.cpp`, and the Elevation generator
  owners to `rmm_elev.cpp`.
- CNTR owners `004821A0` through `004828B0` belong to `rmm_cntr.cpp`.
  CNTR fills Land, Terrain, and Object records and creates child generators.
- DBCT owners `00482B70` through `00484470` belong to `rmm_dbct.cpp`.
  The DBCT class stores all four `*_Info` aggregates.

These rows prove function ownership and consumer use. They do not prove the
original header that declared a shared UDT.

### Type and member evidence

- `inventory/types/dumps/RGE_Land_Info_Line.txt` proves 13 named fields,
  size `0x34`, and gaps at `+0x19` and `+0x31`.
- `RGE_Land_Info.txt` proves 99 lines at `+0x00`, `land_num` at `+0x141C`,
  and size `0x1438`.
- `RGE_RMM_Land_Generator.txt` proves `info` at `+0x30` and class size
  `0x1468`.
- `RGE_Terrain_Info.txt`, `RGE_Object_Info.txt`, and
  `RGE_Elevation_Info.txt` prove the corresponding array offsets and
  aggregate sizes.
- The generator type dumps place Terrain `info` at `+0x30`, Object `info`
  at `+0x34`, and Elevation `info` at `+0x30`.
- `RGE_RMM_Database_Controller.txt` places DBCT's four fields at `+0x3C`,
  `+0x1474`, `+0x270C`, and `+0x3FD4`. Their sizes are `0x1438`, `0x1298`,
  `0x18C8`, and `0xF80`.

### Direct constructors and calls

- `00485200_RGE_RMM_Land_Generator.txt` shows a `0x50E`-dword copy to
  `this + 0x30`. This copies the complete `0x1438` Land record.
- `00482270_add_land_module.txt` shows CNTR writes to the Land tail at
  `+0x141C` through `+0x1434` and uses a `0x34` line stride. It allocates
  `0x1468` bytes and calls the Land constructor at `00482698`.
- `004826E0_add_terrain_module.txt` reads Land `land_num`, `x`, and `y`
  while creating Terrain hot spots.
- `src/rmm_dbct.cpp` creates all four matching generators in
  `RGE_RMM_Database_Controller::generate`. This requires complete generator
  declarations in that source context.

## Exact consumer include rules

**Recommendation:** A declaration-only header may forward-declare an Info
record when it uses only a pointer or reference. Use the matching complete
owner header before field access, aggregate construction, `sizeof`, or
allocation of a related generator.

**Recommendation:** CNTR declaration headers should forward-declare
`RGE_Land_Info`, `RGE_Terrain_Info`, and `RGE_Object_Info` when signatures are
the only use. The CNTR source must include `rmm_land.h`, `rmm_terr.h`, and
`rmm_obj.h` for its local records and `new` expressions.

**Recommendation:** DBCT must use complete Land, Terrain, Object, and
Elevation Info definitions because its controller embeds all four by value.
The DBCT source must include the four matching generator owner headers before
its four `new` expressions. It must not keep local duplicate records or
placeholder generator classes.

**Recommendation:** TDBC must use complete Info definitions for its by-value
controller fields. Its pointer-only declarations may use forward declarations.
Its current context duplicates all four families and must become a consumer of
the four recommended owners when reopened.

**Recommendation:** `include/game_types.h` should keep forward declarations
for pointer-only users. `include/rmm_dbct.h` should keep complete DBCT data
records and should not be used as a second Info-family definition.

**Recommendation:** Resolve competing random-map base declarations before
including the full generator headers into old compiler contexts. The current
CNTR, DBCT, TDBC, and Elevation context headers contain incompatible local
base or Map surfaces. A blind include can change VC5 output or cause type
redefinition. Do not solve this with a second record declaration.

## Object record conclusion

**Recommendation:** Use the type surface from `include/rmm_obj.h` for
`RGE_Object_Info_Line`:

| Offset | Field |
| ---: | --- |
| `+0x00` | `long obj_id` |
| `+0x04` | `long terrain` |
| `+0x08` | `uchar group_flag` |
| `+0x09` | `uchar scale_flag` |
| `+0x0A`-`+0x0B` | implicit compiler alignment; no PDB field |
| `+0x0C` | `long object_number_per_group` |
| `+0x10`-`+0x2C` | the remaining named `long` fields |

Do not add explicit `+0x0A` or `+0x0B` fields. Do not add a named
`reserved` field for those bytes. Do not use the `RGE_Object_Number_Per_Group`
helper or the `initial_flags` union from `rmm_cntr_context.h` as canonical
fields.

## Land owner-field audit

The following audit covers the current `rmm_land.h` and `rmm_land.cpp`. It is
evidence for a future one-owner repair. It does not authorize source changes
in the held Land lane.

### Explicit padding

- `rmm_land.h:124` `RGE_Land_Info_Line::pad_19[3]` occupies the alignment gap
  after `zone` at `+0x18`. The PDB has no field there.
- `rmm_land.h:131` `pad_31[3]` occupies trailing alignment after
  `wall_fade` at `+0x30`. The PDB has no field there.
- `rmm_land.h:141` `RGE_Land_Info::pad_1421[3]` occupies the alignment gap
  after `base_terrain` at `+0x1420`. The PDB has no field there.
- `rmm_land.h:147` `pad_1435[3]` occupies trailing alignment after
  `wall_fade` at `+0x1434`. The PDB has no field there.
- `rmm_land.cpp:141` `LandInfo_00485480::gap0[0x50]` is a local overlay gap.
  It is not a PDB record field. Its only purpose is to reach the wall fields
  from the raw receiver address.

**Recommendation:** For the Land record, replace the four header pad arrays
with natural alignment between named fields. Keep `gap0` only as a temporary
source-private compatibility overlay for the accepted-drift `chance` owner.
The overlay must not enter a shared header.

### Public globals and imported helpers

- `rmm_land.h:173` declares `extern double dbl_571ED0`. The PDB proves the
  data reference at `00571ED0` from `0048531A`. The declaration has the right
  double width but is used by only `check_terrain_and_zone`.
- `rmm_land.h:177` declares the C `debug_rand(char*, int)` import. The Land
  source uses it only in `base_land_generate` at the five PDB line sites
  299, 312, 315, 318, and 321.
- `rmm_land.cpp:23` declares the C `memset` import. This is a compiler/runtime
  helper for `generate`, not a Land record field.

**Recommendation:** Keep `dbl_571ED0`, `debug_rand`, and the explicit `memset`
declaration source-private. Preserve the proven `double`, C linkage, calling
convention, and symbol identity. Do not publish these declarations from the
Land record header unless another exact owner proves the need.

### Raw receiver offsets

- `rmm_land.cpp:152` computes `(char*)this + land_id * 52` and casts it to
  `LandInfo_00485480*`. The `0x34` stride is proven, but the receiver starts
  at the class base and relies on the `+0x50` overlay location.
- `rmm_land.cpp:164` reads `(char*)this + 0x14`. The PDB base layout identifies
  `+0x14` as `RGE_Random_Map_Module::map_width`.

**Recommendation:** Replace the `chance` receiver expression with
`&this->info.land[land_id]` when that accepted-drift owner is reopened. Until
an exact-preserving check proves the replacement, keep the overlay source
private and do not use it in the record header.

**Recommendation:** Replace the `+0x14` read with the canonical
`map_width` field. This is a known base field, not an uncertain offset.

### Local carriers

- `rmm_land.cpp:232` `long land_size[100]` carries per-land counts in later
  elements. Its first element is passed as a float output through
  `(float*)land_size` at lines 346 and 404. This mixed use is a local ABI
  carrier, not a Land record.
- `rmm_land.cpp:242-245` union `tile` overlays a `long row` and a `float f`.
  It carries a row index during map writes and the land index as a float in
  stack pushes.
- `rmm_land.cpp:31` `void* buf` aliases `search_map` for the exact `generate`
  fill call.
- `iStack_af8`, `bVar3`, `bVar4`, and `uVar6` are scalar temporaries tied to
  the phase-B call and cost expressions. They have no shared-record meaning.

**Recommendation:** Treat `land_size` and `tile` as source-private carriers
only while recovering the scratch `base_land_generate` owner. Do not move
them into a header or use them to justify record fields. A future repair may
test separate `float cost`, `long land_size[99]`, `long row`, and `float index`
locals, but that is a different owner and outside this bounded audit.

**Recommendation:** Keep `buf` local to `generate` unless a new exact check
proves that direct `search_map` spelling preserves the existing anchor.

### Pointer cursors

- `rmm_land.cpp:77` `rows` is a direct alias for the proven base member
  `search_map_rows`. It is a natural local pointer.
- `rmm_land.cpp:151` `land_info` is the accepted-drift overlay pointer
  described above.
- `rmm_land.cpp:235` `local_b08`, `398` `pMVar5`, and `403` `pMVar2` point
  into the local `Map_Stack stack[99]`. Their pointer type is natural; their
  source scope is local to `base_land_generate`.
- `rmm_land.cpp:240` `index1` changes role. Phase A points into
  `RGE_Land_Info_Line` through `base_size`; Phase B points into the local
  `land_size` array. It also uses negative and positive word offsets.
- `rmm_land.cpp:250` `max_y` points to `land_size[1]` and acts as a count
  cursor.
- `rmm_land.cpp:253` `plVar12` points to `clumpiness_factor` and advances
  by 13 `long` values per Land line.
- `rmm_land.cpp:399` `puVar14` points to each Land line's `zone` byte and
  advances by `0x34` bytes.
- `rmm_land.cpp:351` `tile2` and `rmm_land.cpp:405` `tile3` are natural
  typed tile pointers. Their complete type should come from the Map owner.

**Recommendation:** Split `index1` into typed phase-local cursors. Use
`RGE_Land_Info_Line*` and named fields for the record loop, and a separate
`long*` or indexed local only for the proven count array. Replace `plVar12`
with `RGE_Land_Info_Line*` and `puVar14` with a typed Land-line cursor when
those owners are reopened. Keep the stack cursors as local `Map_Stack*` values.

The following raw cursor forms are source-shape artifacts, not record fields:
`index1[-2]`, `index1[-1]`, `index1[-3]`, `index1 + 2`, `plVar12[-7]`,
`plVar12[-6]`, `plVar12[-1]`, `plVar12[0]`, `*(long*)index1`, and
`*(unsigned char*)(puVar14 - 0x14)`.

**Recommendation:** Remove those cursor expressions in a future repair only
when the corresponding PDB fields are named. Do not replace them with new
absolute offsets or an unproved aggregate.

### Probe-history blocks

The live source contains these probe-history blocks in the
`base_land_generate` comment at `rmm_land.cpp:212-230`:

- H1 records the rejected REAL32 and frame experiment.
- H2 records the `&x`, `&y`, and `chance` argument experiment.
- H3-H16 records cursor, scope, control-flow, and local experiments.
- H17 records the restored `pop_stack` output order.
- H28-H29 records edge-cursor and neighbor-cost experiments.
- H31 records the two-word union experiment.
- H32 records the split-edge-guard experiment.
- H33 records the clipped-terrain cursor experiment.

**Recommendation:** Move this probe history to a recovery note or attempt
ledger when `base_land_generate` is next reopened. Keep only short binary
notes in living source. Do not treat a probe-history result as proof of the
original source form.

### Additional header owner drift

The current `rmm_land.h` also declares local `RGE_Tile`, `Map_Stack`,
`RGE_Random_Map_Module`, and narrow `RGE_Map` surfaces. These are not Land
record fields. The current local Map and base declarations compete with the
canonical Map and RMM owners described by the shared dossier.

**Recommendation:** When the held Land lane reopens, use `rmm_base.h` for the
random-map base and stack ABI. Use `map.h` only at the source boundary for
Map and Tile access. Keep Map and World dependencies source-private when
pointers are the only header use. Preserve all exact owners during that
context change.

## Future Elevation owner plan

**Recommendation:** Do not use `rmm_elev_context.h` as an owner. It contains
legacy base, Map, Tile, and Elevation declarations in one compiler context.
It cannot serve as the canonical Elevation header.

**Recommendation:** First prove and build the future owner-only
`include/rmm_elev.h` from the `rmm_elev.cpp` PDB order, UDT sizes, generator
member offset, and direct method signatures. Compose the natural Elevation
source against that header. Keep the current Elevation source status until a
candidate proves the context.

**Recommendation:** After `rmm_elev.h` is proven, fan out its complete
Elevation records to DBCT and TDBC. Their by-value controller fields require
complete types. Include the complete generator owner headers at source sites
that allocate generators. Use forward declarations only for pointer or
reference-only declarations.

**Recommendation:** Validate the Elevation source, DBCT source, TDBC source,
and affected consumers with grouped translation-unit candidates. Require
exact-owner `MATCH`, positional `0.0000%`, owner and boundary parity,
relocation parity, and direct-target parity before any status or ownership
move.

## Bounded one-owner Land repair plan

**Recommendation:** Reopen only `004852D0 check_terrain_and_zone` for the next
Land repair. Keep exact owners `00485200` and `00485240`, accepted drift
`00485480`, and scratch owner `00485520` unchanged.

**Recommendation:** Use the existing PDB argument order and direct field
facts. Preserve the initial `search_map_rows[y][x]` guard, the signed
`< land_num` early return, the `area` bounds, the `+/-2` scan bounds, and the
four edge count branches. Do not add the unused octagon bounds to behavior.

**Recommendation:** Test one natural source shape at a time: named
`RGE_Land_Info_Line` access for area and zone, a direct `map_width` and
`map_height` read, and separate phase-local cursors. Do not use raw receiver
offsets, raw record cursors, context wrappers, fake globals, explicit
volatility, or the rejected union as a compiler control.

**Recommendation:** Run one grouped candidate after the one-owner source
change. It must retain exact `00485200` and `00485240` results and report the
observed Land owners without ownership promotion. If the target remains
nonexact, record the blocker and restore the clean source. Do not alter CNTR,
DBCT, TDBC, or Elevation in this repair.

No code, header, configuration, or generated inventory change is part of this
recommendation-only audit.

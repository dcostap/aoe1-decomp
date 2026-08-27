# rmm_obj.cpp source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\rmm_obj.cpp`.
- Source: `src/rmm_obj.cpp`.
- Header: `include/rmm_obj.h`.
- The module owns 13 normal functions in PDB order from lines 28 through 638.
- The packet reports 4,953 normal-owner bytes.

## Context and ownership

The owner address sequence is:

`00485C50`, `00485CB0`, `00485DC0`, `00485E50`, `00485F10`, `00486110`,
`00486180`, `00486210`, `004862B0`, `004864F0`, `00486700`, `00486A60`,
`00486C40`.

The module header owns the generator and object-info declarations. It consumes
the canonical random-map base in `include/rmm_base.h`. The source passes
`Map_Stack` and pop outputs by reference, as the base owner proves.

It consumes `RGE_Master_Static_Object` from `m_s_obj.h`. It does not retain a
local master-object vtable view.

## Canonical Map and World fanout

The source now consumes `map.h`, `world.h`, `player.h`, and `zone_map.h`.
It uses owner names for the old local views: `map_zones`, `terrain_type`,
`check_placement`, and `make_new_object`.

`zone_map.h` now consumes `map.h`. `obj_list.h` now owns only its node and
list records. Neither header copies Map, World, Player, Static, Master, or
derived object classes.

## Migration

- Merged all 13 source-bank bodies into `src/rmm_obj.cpp` in PDB order.
- Replaced the wrapper and split context with `include/rmm_obj.h`.
- Removed the `RMM_OBJ_TU_COMBINED_CONTEXT` selection macro.
- Removed all source-bank `.cpp` includes, fallback class declarations, and
  branch-specific pointer/reference forms.
- Removed the old `src/rmm_obj_tu.cpp` wrapper.
- Removed the nine matching fragments, one accepted-drift fragment, and three
  scratch fragments owned by this module.
- Kept the source forms that have binary evidence or exact results, including
  the reference stack local, narrow cluster vtable view, register variance
  local, and proven typed local aliases.
- Removed `rmm_obj_base_context.h`. Random-map shallow and cliff consumers now
  include their canonical owner headers.

## Status and regressions

The manifest records nine matching owners, one accepted-drift owner, and three
scratch owners. The migration does not promote drift or scratch functions.
Before migration, the nine matching owners were registered under the temporary
`src/rmm_obj_tu.cpp` wrapper. The direct merged-source comparison found eight
matching owners. It found one source-reunification regression:

| VA | Owner | Result | Difference | Rebuilt size |
| --- | --- | --- | ---: | ---: |
| `00485E50` | `generate_objects` | MISMATCH | 2 bytes | 184 |

The other eight matching owners remain `MATCH` with `0.0000%`. All 13 checked
owners have the correct normalized owner symbol. The comparison found no
relocation target mismatch and no boundary escape. `00485F10` extracts 503
rebuilt bytes from its 507-byte section in both the old wrapper and the merged
source; this is not a migration regression.

`004862B0 place_avoid_objects` remains accepted drift. Its reviewed residual is
limited to private setup register and scheduling differences.

`00485F10 make_placement_stack`, `004864F0 place_objects`, and `00486C40
place_cluster` remain scratch. Their source notes describe the unresolved local
liveness or setup scheduling differences.

## Validation

The pinned VC5 compiler built `src/rmm_obj.cpp` with
`config/flags/default.rsp`. The object is
`build/candidate_tus/rmm_obj_module/rmm_obj.obj`. A direct checker comparison
covered all 13 owners and recorded the table above.

The source policy check passed. `git diff --check` passed. The direct
translation-unit entry now uses `src/rmm_obj.cpp`. It retains the eight matching
owners. `00485E50` is scratch after the documented two-byte residual.

After the canonical Map and World headers landed, the registered `rmm_obj`
candidate for `00485DC0` compiled and returned `MATCH`, `0.0000%`. This check
does not revalidate the remaining recorded owners.

# `victory.cpp` source-module migration

## Ownership

- PDB source: `C:\\msdev\\work\\age1_x1\\victory.cpp`.
- Source: `src/victory.cpp`.
- Header: `include/victory.h`.
- Flags: `config/flags/default.rsp`.
- The module owns 58 normal functions from `00531750` through `005334E0`.
- The owners stay in PDB source order in one compiler-facing source file.
- `00531F71` is reviewed padding-only data and stays outside the source file.

The former `victory_prefix`, `victory_description`, and `victory_points`
wrappers are replaced by one direct `victory` translation-unit entry. Matching
owners map directly to `src/victory.cpp`. The eight observed non-matching owners
stay in the module source, but are not registered as exact owners.

## Recovery state

The module retains 48 matching owners, six accepted-drift owners, and four
scratch owners. The accepted-drift owners are `00531DB0`, `005324A0`, `005326F0`,
`00532C10`, `00532ED0`, and `00532FA0`. The scratch owners are `00531750`,
`005327A0`, `00532880`, and `00533240`.

The source uses one module-owned declaration surface. It removes source-bank
fallback declarations, `.cpp` includes, wrapper files, context selection, and
codegen-only local surfaces. The source keeps the recovered behavior and the
original owner order. It does not add byte-tuning code.

## Header composition

`victory.h` is owner-only. It includes only the canonical `rge_fio.h` API and
forward-declares the game-owner types used by its public signatures. It defines
only `RGE_Victory_Conditions`, `RGE_Victory_Entry`, and
`RGE_Victory_Point_Entry`. It does not include Visible, Player, World, Object
List, Static Object, Master Static Object, or Map headers.

`victory.cpp` privately consumes `player.h`, `stat_obj.h`, `m_s_obj.h`,
`visible.h`, `world.h`, and `obj_list.h`. The source also owns its helper
declarations for allocation, formatting, and description text.

The source reads `RGE_Master_Static_Object::copy_id` at lines 459, 480, 509,
536, 593, 619, and 640. It reads `radius_x` and `radius_y` at lines 714-715.
The type inventory assigns `RGE_Master_Static_Object` to the m_s_obj owner and
proves `copy_id` at `+0x12`, `radius_x` at `+0x30`, `radius_y` at `+0x34`, and
size `0xB8` (`inventory/types/dumps/RGE_Master_Static_Object.txt`).

The canonical `m_s_obj.h` owns only `RGE_Master_Static_Object`. Its type dump
proves `copy_id` at `+0x12`, `radius_x` at `+0x30`, `radius_y` at `+0x34`, and
size `0xB8`. Natural size checks prove `RGE_Victory_Entry` at `0x34`,
`RGE_Victory_Point_Entry` at `0x1C`, and `RGE_Victory_Conditions` at `0x20`.

## Migration regressions

The old exact results came from split wrappers and isolated owner contexts. The
complete source now shares one header and one compiler context. A grouped build
can therefore change bytes, frames, register colors, and exact-owner results.
Those results are not promoted during this structural migration. Re-run exact
checks from the final source tree before status promotion.

Earlier isolated checks were exact for the `00531AF0` constructor, `00531B20`
destructor, `00531B70` serializer, and `005334E0` getter. The compiler emits the
destructor vptr store from the virtual class declaration. The source does not
use a manual vptr write. Those isolated results are historical; the grouped
canonical result is recorded below.

The earlier natural typed `00532880` handler was 161 bytes instead of 170 and
differed by 119 bytes. The natural `00533240` handler kept the original
230-byte boundary and differed by 21 bytes.

The earlier `005327A0` result was 223 bytes instead of 224, with 121 differing
bytes. It stays scratch. Its prior matching row is removed from direct exact
ownership.

`00532880` is 161 bytes instead of 170. It has 119 differing bytes and a
control-flow difference. It stays scratch. Its prior matching row is removed
from direct exact ownership.

## Validation

The final grouped candidate validation used
`build/candidate_tus/victory_canonical.json` and wrote its report to
`build/candidate_tus/victory_owner_only/report.{json,txt}`. The candidate
compiled successfully with `config/flags/default.rsp`.

The exact set covered 48 owners. It returned 46 `MATCH` results at `0.0000%`.
The two mismatches were:

- `00532610`: 6 bytes, `2.6786%`.
- `00533120`: 4 bytes, `4.6512%`.

All exact rows had matching owner symbols, zero relocation target mismatches,
and zero boundary escapes.

The observed set covered 10 owners. `005327A0` returned `MATCH` at `0.0000%`.
The other successful observations returned these mismatches:

- `00531750`: 493 bytes, `53.5870%`.
- `00531DB0`: 2 bytes, `0.9259%`.
- `005324A0`: 25 bytes, `12.5628%`.
- `005326F0`: 27 bytes, `15.5172%`.
- `00532880`: 119 bytes, `70.0000%`.
- `00532ED0`: 4 bytes, `13.3333%`.
- `00532FA0`: 5 bytes, `8.3333%`.
- `00533240`: 21 bytes, `9.1304%`.

`00532C10` returned one comparison error because the unqualified `sub` name
matched both `sub` and `sub_point`. Successful observed rows had matching owner
symbols, zero relocation target mismatches, and zero boundary escapes.

The complete result was 47 `MATCH` rows out of 58, with one comparison error.
The module is not fully exact. No compiler-generated owners were included.

The final result does not retain the five earlier exact regressions as a set:
`00532050`, `00532CC0`, and `00533410` now match. Their source-module statuses
remain unchanged. Only `00532610` and `00533120` remain exact mismatches.

## Open issues

- `00531750` keeps its typed natural reconstruction but remains scratch because
  its constructor has broad register and vtable-context drift.
- `00533240` keeps its typed natural reconstruction but remains scratch because
  its player-id spill and local-frame layout remain unresolved.
- `00531750` is a scratch overloaded constructor. The registered exact-owner
  map cannot store its symbol without making a false exact claim.
- The six accepted-drift owners retain their previously reviewed localized
  differences. Their old isolated metrics do not claim exactness for this
  complete translation unit.

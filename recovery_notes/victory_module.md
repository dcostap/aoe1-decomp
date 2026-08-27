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

## Migration regressions

The old exact results came from split wrappers and isolated owner contexts. The
complete source now shares one header and one compiler context. A grouped build
can therefore change bytes, frames, register colors, and exact-owner results.
Those results are not promoted during this structural migration. Re-run exact
checks from the final source tree before status promotion.

Natural checks remain exact for the `00531AF0` constructor, `00531B20`
destructor, `00531B70` serializer, and `005334E0` getter. The compiler emits the
destructor vptr store from the virtual class declaration. The source does not
use a manual vptr write. The natural typed `00532880` handler is 161 bytes
instead of 170 and differs by 119 bytes. Its reviewed matching status remains
in the module metadata, but this migration does not claim a fresh exact result
for the complete source module. The natural `00533240` handler keeps the
original 230-byte boundary and differs by 21 bytes.

`005327A0` is 223 bytes instead of 224. It has 121 differing bytes. It stays
scratch. Its prior matching row is removed from direct exact ownership.

`00532880` is 161 bytes instead of 170. It has 119 differing bytes and a
control-flow difference. It stays scratch. Its prior matching row is removed
from direct exact ownership.

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

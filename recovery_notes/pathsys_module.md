# pathsys.cpp source module

`src/pathsys.cpp` is the compiler-facing source for
`C:\msdev\work\age1_x1\pathsys.cpp`. It owns all 20 normal functions in PDB
source order. The startup initializers at `0046B060` and `0046B0B0`, and the
deleting destructor at `0046B250`, are compiler-generated.

The module defines `pathSystem` and `aiPathSystem` as ordinary global
`PathingSystem` objects. Their constructor arguments and declaration order
match the original startup calls. No placement wrapper or raw address remains.

The module uses `pathsys.h` and canonical Map, World, Player, Moving Object,
Path, and panel owners. It has no wrapper, context selector, copied foreign
class, flat obstruction alias, or synthetic carrier.

## Validation

The pinned VC5 compiler builds the module with
`config/flags/0046B0F0_PathingSystem.rsp`. The module passed an IL capture
compile after the typed Map tile repair.

Exact owners are `0046B0F0`, `0046B270`, `0046B310`, `0046B360`, `0046B550`,
`0046B570`, `0046B590`, `0046B5C0`, `0046D250`, `0046D260`, `0046D270`,
`0046D740`, and `0046D770`. The source-module metadata lists these exact
claims and no others.

Scratch rows are `0046B5E0`, `0046B620`, `0046B6E0`, `0046D280`, and
`0046DCB0`. `0046B680` and `0046D830` remain accepted drift. The direct
migration does not promote them.

The natural definitions emit VC5 CRT startup and destructor-registration
helpers. The direct constructor helpers mapped to the old initializer ranges
`0046B060` and `0046B0B0` both return `MATCH`, `0.0000%`. The surrounding
helper layout does not reproduce the old direct initializer boundaries. This
is an accepted structural change, not a handwritten owner.

The large search and passability bodies need future exact work.

# pathsys.cpp source module

`src/pathsys.cpp` is the compiler-facing source for
`C:\msdev\work\age1_x1\pathsys.cpp`. It owns all 22 normal functions in PDB
source order. The deleting destructor at `0046B250` is generated.

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

Scratch rows are `0046B060`, `0046B0B0`, `0046B5E0`, `0046B620`, `0046B6E0`,
`0046D280`, and `0046DCB0`. `0046B680` and `0046D830` remain accepted drift.
The direct migration does not promote them.

The E9 and E14 PDB display names need future source-name recovery. The large
search and passability bodies need future exact work.

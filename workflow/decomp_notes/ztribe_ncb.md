# ZTRIBE.NCB evidence

`AoE 1 Alpha 0.5/.../GAME/ZTRIBE.NCB` is the January 1997 Visual C++ 4.2
browse database. It records parameter names, default arguments, original
`BOOL`/`BYTE` spellings and typedef names for about 26 headers and four
browsed `.cpp` files. It is reference evidence from a build 18 months before
the target; signatures it shows can differ from the 1998 executable.

## `utmarray.h`

Applied, byte-identical in all 225 objects:

- template parameter `Type`;
- `ManagedArray(int initialSize = 0)`, `operator[](int v)`, `enlarge(int s)`,
  `contains(const Type& r)`, `position(Type& r)`, `add(Type r)`,
  `sort(CompareFunction cF)`.

`remove` and `setDesiredNumber` have no recorded parameter names and keep the
reconstructed ones.

Not applied:

- `typedef ManagedArray<int> ManagedIntArray;` and
  `typedef ManagedArray<void*> ManagedVoidPointerArray;`. Adding even the int
  typedef alone, with no uses, changed `view.obj` and `vw_main.obj` and broke
  six exact claims (for example `0045A500` `update`, `004D5F00` `canPlace`).
  The 109 `ManagedArray<int>` spellings stay.
- `ManagedArrayComparisonFunction` is listed unqualified, so the original was
  probably a global typedef. The NCB does not record its signature, so the
  member `CompareFunction` stays. `sort` has no callers.

## Default arguments

The NCB lists 32 defaults. Most belong to signatures that changed by 1998
(`explore_terrain` and `alignment` gained parameters, `scenario_load` and
`set_terrain` differ). Defaults cannot be checked against the binary, because
compiled calls always pass every argument. They are not applied yet.

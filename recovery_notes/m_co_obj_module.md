# m_co_obj.cpp source reunification

## Context

The PDB source is `C:\\msdev\\work\\age1_x1\\m_co_obj.cpp`.
The owner order follows the source lines 27-577.
The class owner is `RGE_Master_Combat_Object`.

The normal owner sequence is:

- `0044FE40`, `0044FEC0`, `0044FF30` constructors;
- `0044FFB0`, `00450170`, `00450450` setup overloads;
- `00450680` destructor;
- `004506D0`, `004507A0` factories;
- `00450810` copy;
- `00450A00`, `00450B40`, `00450D00` attribute updates;
- `00450E20` save;
- `00451000` base damage calculation.

`0044FEA0` is the compiler-generated vector deleting destructor. It has no
handwritten source owner.

## Reunified source

`src/m_co_obj.cpp` is the only compiler-facing source owner for all fifteen
normal VAs. `include/m_co_obj.h` owns the combat-master declarations and uses
the existing action-master declarations from `include/m_ac_obj.h`.

The old wrapper `src/m_co_obj_tu.cpp`, per-function includes, and per-function
fallback declarations are no longer used. `include/m_co_obj_context.h` remains
because the unrelated `0053B7E0` scratch owner uses its temporary combat-object
view. It is not included by the reunified module.

## Validation state

The thirteen former matching owners retain their exact source bodies:

`0044FE40`, `0044FEC0`, `0044FF30`, `0044FFB0`, `00450170`, `00450680`,
`004506D0`, `004507A0`, `00450810`, `00450A00`, `00450B40`, `00450D00`, and
`00450E20`.

`00450450` retains its reviewed accepted drift. Its size, six ordered parser
calls, allocation loops, max scans, stores, cleanup, and fault order match.
The seven changed bytes are only local stack displacements. The executable
reuses dead parameter homes for four parser outputs. The natural source uses
named local homes. The parser widths and destinations remain the same.

`00451000` retains its reviewed accepted drift. It has the exact 188-byte size,
frame, call set, nested loop bounds, x87 operation sequence, global thresholds,
and return. The remaining twelve bytes are the base-armor and value register
allocation basin at the entry and its dependent reload. The source uses the
natural branch-local remaining counter. Register hints and allocator scaffolds
are not retained.

The old exact claims are stale only as standalone source-bank claims. The module
metadata records the thirteen exact owners and two accepted-drift owners in the
single source file.

## Open regression

The structural migration changes the ambient header context. The old wrapper
used `m_co_obj_context.h`, while the natural header uses the canonical action
hierarchy from `m_ac_obj.h`. The accepted-drift metrics need a fresh grouped
candidate check after migration. Do not alter source behavior to hide a context
regression. Restore exact repair on the final source tree.

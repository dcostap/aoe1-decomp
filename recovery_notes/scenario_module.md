# scenario.cpp source reunification

The source owner is `src/scenario.cpp`, in PDB order. The normal owner set has
48 functions. The source module has 43 matching owners and 5 accepted-drift
owners.

The three nearby padding fragments at 0048C33D, 0048CE21, and 0048CE82 are not
normal owners. They stay outside the module.

## Accepted drift

- 0048AD60 has a VC5 scheduling difference in the constructor memset setup.
  The build keeps the same fields and writes.
- 0048AE10 has seven one-byte SIB base/index differences at string terminator
  stores. The writes, calls, guards, and control flow stay the same.
- 0048BCC0 and 0048BEC0 keep the same call order, guards, writes, and return
  values. VC5 caches the temporary text address before late `sprintf` calls.
  The original recomputes that address in the return blocks.
- 0048C0E0 has the same nine ordered calls and behavior. VC5 keeps the
  temporary text address in a register around the late `sprintf` calls.

These differences were accepted before source reunification. The natural source
keeps the reviewed behavior. Exact repair can resume on the final source tree.

## Reunification regression record

The old grouped wrapper and all source-bank fragments are removed. The new
module uses one direct source owner and one natural header. Rebuild metrics after
this structural change are recorded by the module validation run and may differ
from the pre-migration grouped wrapper. No behavior change was introduced to
hide a temporary exactness regression.

The reunified object differs from the prior grouped object at two reviewed
owners. 0048AE10 has one changed SIB byte. 0048C0E0 has three direct-global
relocations, because the wrapper-only target-address macro is removed. Both
forms read the same storage and keep the same control flow.

The module header declares protected virtual `get_object_pointer` and public
virtual `rehook`. Their PDB owners belong to `scenario.h`, not `scenario.cpp`.
The direct scenario object uses the shipped virtual slots.

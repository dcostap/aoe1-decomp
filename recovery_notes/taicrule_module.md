# taicrule.cpp source reunification

## PDB context

The PDB identifies `C:\\msdev\\work\\age1_x1\\taicrule.cpp` as the source
module. It owns five normal `CombatRuleSystem` functions in this order:

| VA | PDB lines | bytes | owner | status |
| --- | ---: | ---: | --- | --- |
| `004D68D0` | 23-24 | 9 | `CombatRuleSystem::CombatRuleSystem` | matching |
| `004D6900` | 29-30 | 7 | `CombatRuleSystem::~CombatRuleSystem` | matching |
| `004D6910` | 35-74 | 386 | `CombatRuleSystem::loadRules` | accepted_drift |
| `004D6AA0` | 79-81 | 6 | `CombatRuleSystem::bestUnitTypeToAttack` | matching |
| `004D6AB0` | 86-88 | 6 | `CombatRuleSystem::bestUnitTypeToDefendAgainst` | matching |

The PDB symbols and source-line records prove the owner class, address
sequence, and line bands. The nearby `004D68E0` scalar deleting destructor is
compiler generated. It is not a handwritten source owner.

The local class layout is supported by the class inventory and original code:
the vptr is at +0x00, `ratingValue` starts at +0x04, and the object size is
0x9C8 bytes. The `loadRules` body writes the 2500-byte table and reads its
three integer fields in the original stack frame.

## Statuses

The four short owners remain exact. `loadRules` remains `accepted_drift`. Its
reviewed source preserves the original boundary, calls, control flow, stores,
cleanup, and return values. Its 12 positional bytes differ at the memset
setup because VC5 schedules the `lea edi` differently from the original.

The prior accepted-drift attempt log recorded a best result of 3.1 percent
difference after testing local order, frame shape, parse variables, and store
forms. No source change in this reunification reopens that result.

## Migration

`src/taicrule.cpp` is now the direct compiler-facing owner for all five PDB
functions. It includes the module-local `include/taicrule.h` and keeps the
definitions in PDB order. The old `src/taicrule_tu.cpp` wrapper and five
source-bank fragments are removed.

The module metadata records every normal owner, including the accepted-drift
status. The generated scalar deleting destructor remains an emitted class
artifact and is not listed as a source owner.

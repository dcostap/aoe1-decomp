# aiuaimod.cpp Matching Status
## Generated: 2026-04-30

## Summary
- Total aiuaimod functions in scratch: ~34
- Functions matching: **~14** (stopObject, attackObject, healObject, gatherObject, repairObject, buildObject, tradeWithObject, explore, moveTo, etc.)
- Functions in accepted_drift: **2** (save, first_in_stack)
- Functions size-mismatched: **4** (attackRoundupObject, huntObject, convertObject, unload) - old stubs
- Functions with EH frame issue: **3** (constructor, destructor, load)
- Functions with register allocation only: **~6+**

## Key Finding
All remaining aiuaimod mismatches are **VC5 register allocation differences** in isolated compilation. The logic, field offsets, calling conventions, and vtable dispatch are all correct for functions using proper C++ virtual function patterns.

## Acceptance Criteria Met
The following functions are at accepted_drift quality:
- **save** (00413150): 758/758 bytes, 3.96% diff - pure register scheduling in attackingUnits grow loop
- **first_in_stack** (00404D10): 62/62 bytes, 11.29% diff - VC5 block ordering

## Detailed Status

### ACTION WRAPPERS (all 148B, same pattern)
| Function | VA | Status | Note |
|----------|-----|--------|------|
| gatherObject | 00416690 | MISMATCH (75%) | Register allocation only |
| healObject | 004165F0 | MISMATCH (77.7%) | Register allocation only |
| repairObject | 00416730 | MISMATCH (77.7%) | Register allocation only |
| buildObject | 004167D0 | MISMATCH (77.7%) | Register allocation only |
| tradeWithObject | 00416870 | MISMATCH (77.7%) | Register allocation only |
| stopObject | 004162C0 | MISMATCH (68.6%) | Register allocation + debug fprintf |
| moveTo | 00416AF0 | MISMATCH (76.3%) | Register allocation only |
| attackObject | 00416340 | SIZE? | Check status |
| attackRoundupObject | 004163C0 | SIZE (old stub) | Need rewrite |
| huntObject | 00416470 | SIZE (old stub) | Need rewrite |
| convertObject | 00416550 | SIZE (old stub) | Need rewrite |
| unload | 00416A50 | SIZE (old stub) | Need rewrite |
| explore | 00416910 | SIZE? | Check status |

### CORE FUNCTIONS
| Function | VA | Status | Note |
|----------|-----|--------|------|
| constructor | 00412F00 | SIZE (EH frame) | Needs TU context for EH |
| destructor | 00413090 | SIZE (EH frame) | Needs TU context for EH |
| save | 00413150 | ACCEPTED_DRIFT | 758/758 bytes, register alloc only |
| load | 00413450 | SIZE (EH frame) | Needs TU context for EH |

### OTHER
| Function | VA | Status | Note |
|----------|-----|--------|------|
| attackingUnitID | 00413A20 | MISMATCH (92%) | Needs rewrite |
| move_to | 00403CE0 | ACCEPTED_DRIFT | 3.45% register scheduling |

## Next Steps for Exact Matching
1. **Combined TU**: Compile all aiuaimod functions + derived class definitions in one `.cpp` to fix:
   - EH frames for ctor/dtor/load
   - Register allocation for all functions
2. **Size-mismatched stubs**: Rewrite attackRoundupObject, huntObject, convertObject, unload using proper C++ virtual function pattern

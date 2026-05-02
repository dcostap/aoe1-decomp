# Combined TU Implementation Plan

## Current Status (2026-04-30)
- **9 exact matches** (0.0000% diff) processed and promoted
- **5 accepted drift** functions
- **6 remaining aiuaimod stubs** - 1 implemented (evasiveMoveTo), 5 with basic stub bodies
- **Shared header** with correct field layout (vfptr fix applied)
- **Combined TU** infrastructure complete

## The 5 Remaining Functions

| Function | Bytes | Priority | Complexity |
|----------|-------|----------|------------|
| `processMisc` | 1383 | Low | Medium - cleanup logic |
| `selectNewPlayPhase` | 1298 | Low | Medium - phase selection |
| `intelligentEvasiveMoveTo` | 666 | Medium | High - pathfinding |
| `update` | 1372 | Medium | High - main tick handler |
| `processNotify` | 4916 | Low | Very High - event handler |

## Implementation Strategy

1. **Natural C++ source** - prefer readable member function calls
2. **Use shared header** - all fields and methods declared
3. **Accept debug_rand calls** - can't match absolute addresses
4. **Accept vtable function pointers** - produces different call sequences
5. **Combined TU** - compile all 6 together for register allocation + call resolution

## Verification
After each implementation, compile with combined TU and check against original binary.
Use `tools/check_combined_tu.py --source-file aiuaimod.cpp --va <VA>`.
Results will show MATCH (exact) or diff analysis.
Due to debug_rand absolute calls, most will be accepted_drift.

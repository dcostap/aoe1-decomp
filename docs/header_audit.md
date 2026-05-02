# Shared Header Field Offset Audit

## Problem
The shared header at `include/unit_ai_module.h` has field offsets that may not match 
the verified matching files in `src/matching/0041*.cpp`.

## Finding
Matching files use 3+ different class definition patterns:
1. **Virtual destructor pattern** (majority): `virtual ~UnitAIModule();` + `_` suffix fields
2. **Vtable pointer pattern**: `void* vtable_ptr;` + `RGE_Static_Object* object_;`
3. **Accessor pattern**: Minimal fields + gap arrays for unused offsets

All produce 0.0000% diff individually, proving VC5 only validates accessed fields.

## Key Discrepancies vs Shared Header
| Offset | Matching Files | Shared Header |
|--------|---------------|---------------|
| +0x04  | UnitAIObjectRef* object_ | RGE_Static_Object* objectValue |
| +0x14  | char gap_14[0x14] | 5 named fields (orderQueueMaxSize, orderQueueValue, etc.) |
| +0x4C  | char gap_4C[4] | int defendTargetValue |
| +0x60  | char gap_60[4] | int* attackingUnitsValue_value |
| +0x68  | char gap_68[0x88] | int attackingUnitsValue_maximumSizeValue + waypointGap[0x80] |
| +0xFC  | char gap_FC[4] | adjustedIdleTimeoutValue |
| +0x108 | char gap_108[0x18] | 6 named fields |
| +0x120 | float defenseBuffer_ | float defenseBufferValue (matches!) |
| Naming | `_` suffix | `Value` suffix |

## Resolution Path
1. Extract canonical field offsets from matching files
2. Rebuild shared header with `_` suffix naming
3. Use `char gap_XX[N]` for unverified offsets (as matching files do)
4. Add alias #defines for `Value` suffix compatibility

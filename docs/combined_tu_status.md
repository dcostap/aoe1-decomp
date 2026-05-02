# Session Final Status - Combined TU Key Discoveries

## Fixed: Virtual Destructor Required for Correct Field Layout
**Root cause**: VC5 omits the vfptr (+0x00, 4 bytes) when a class has NO virtual functions.
**Fix**: Added `virtual ~UnitAIModule();` to the shared header.
**Result**: All field offsets now match the verified matching files (e.g., `currentActionValue` at +0x30 = `[ecx+48]`).

## Correct Prologue Generated
```
push ecx         ; local allocation
mov eax, [esp+14h]  ; load flag param
push ebx
push ebp
push esi
push edi
mov ebp, ecx     ; save this
cmp [ebp+48], -1 ; currentAction == -1 check ✓
```

## Object Chain Correct
`[ebp+4]` → `[eax+12]` → `[ecx+60]` → `[edx+40]` 
All offsets match the original binary at byte level.

## Remaining Limitations
1. `debug_rand()` at absolute address 004230A0h - produces E8 00 00 00 00
2. vtable calls through function pointers (behavioral equivalent)
3. Control flow shape differences (compiler reordering)

## Infrastructure Complete
- `include/unit_ai_module.h` - Correct field layout (49 fields, 100 methods)
- `src/scratch/00416C80_evasiveMoveTo.cpp` - Correct implementation
- 5 remaining stubs compiling together
- `tools/check_combined_tu.py` - Ready for combined TU validation

## Next Steps
1. Verify remaining field offsets in object sub-structures
2. Implement remaining 5 large functions  
3. Run combined TU validation against original binary

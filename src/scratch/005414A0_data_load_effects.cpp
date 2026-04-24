// Function: RGE_Game_World::data_load_effects
// VA: 005414A0
// Source: World.cpp
// Signature: void __thiscall RGE_Game_World::data_load_effects(char* param_1)
//
// STATUS: Cannot match exactly due to MSVC5 calling convention limitations
//
// Attempt log:
// - try 1: Used __stdcall, generated ret 8 instead of ret 4
// - Result: Function is 64 bytes, original is 88 bytes
// - Issue: MSVC5 doesn't support __thiscall on extern functions
// - The original uses: this in ECX, param on stack, ret 4
// - Compiled uses: both params on stack, ret 8
// - Additional issue: Original has SEH (Structured Exception Handling) setup
//   with FS:[0] manipulation that's compiler-specific and hard to replicate
//
// Original assembly includes:
// - SEH frame setup: mov eax,[fs:0], push eax, mov [fs:0],esp
// - Exception handler restoration: mov [fs:0],ecx
// - These are MSVC-specific and don't translate to C code
//
// Leaving in scratch due to toolchain limitation.
//
// Original logic:
// 1. Set up exception handler frame (FS:[0])
// 2. Allocate memory for RGE_Effects (12 bytes)
// 3. If allocation succeeds, call RGE_Effects constructor
// 4. Store result in [this + 0x4C]
// 5. Restore exception handler frame
//
// Leaving in scratch due to toolchain limitation.

class RGE_Effects;

extern "C" void* __stdcall operator_new(size_t size);
extern "C" void __stdcall RGE_Effects__constructor(RGE_Effects* this_, char* param_1);

extern "C" void __stdcall RGE_Game_World__data_load_effects(void* this_, char* param_1) {
    // Set up exception handler frame
    // Note: Original uses FS:[0] for SEH, which is hard to replicate in C
    
    // Allocate memory for RGE_Effects (12 bytes)
    RGE_Effects* effects = (RGE_Effects*)operator_new(12);
    
    // Initialize local variable
    int local_4 = 0;
    
    // Check if allocation succeeded
    if (effects != 0) {
        // Call RGE_Effects constructor
        RGE_Effects__constructor(effects, param_1);
    } else {
        effects = 0;
    }
    
    // Store result in [this + 0x4C]
    *(void**)((char*)this_ + 0x4C) = effects;
    
    // Restore exception handler frame (FS:[0])
    // Note: Original restores from stack, hard to replicate in C
}

// Function: TRIBE_Player::scenario_save
// VA: 00512630
// Source: tplayer.cpp
// Signature: void __thiscall TRIBE_Player::scenario_save(int param_1)
//
// STATUS: Cannot match exactly due to MSVC5 calling convention limitations
//
// Attempt log:
// - try 1: Used __stdcall, generated ret 8 instead of ret 4, stack offsets wrong
// - Result: Function is 80 bytes, original is 88 bytes
// - Issue: MSVC5 doesn't support __thiscall on extern functions
// - The original uses: this in ECX, param on stack, ret 4
// - Compiled uses: both params on stack, ret 8
//
// Leaving in scratch due to toolchain limitation.

class RGE_Player;
class TRIBE_Player {
public:
    char pad_00[0x50];
    void* field_50;  // offset 0x50
};

// External function declarations
extern "C" void __stdcall RGE_Player__scenario_save(RGE_Player* this_, int param_1);
extern "C" void __stdcall rge_write(int file, void* data, int size);

// Attempt 2: Match exact register usage and stack layout
// Original: push esi, push edi, mov edi,[esp+0Ch], mov esi,ecx
// Using __stdcall to match original ret 4
extern "C" void __stdcall TRIBE_Player__scenario_save(TRIBE_Player* this_, int param_1) {
    // Simulate original register usage
    // esi = this_, edi = param_1
    
    // Call base class method
    RGE_Player__scenario_save((RGE_Player*)this_, param_1);
    
    // field_50 is at offset 0x50
    void* field50 = *(void**)((char*)this_ + 0x50);
    
    // Write field_50 + 0
    rge_write(param_1, field50, 4);
    
    // Write field_50 + 4
    void* ptr = (char*)field50 + 4;
    rge_write(param_1, ptr, 4);
    
    // Write field_50 + 12 (0xC)
    ptr = (char*)field50 + 12;
    rge_write(param_1, ptr, 4);
    
    // Write field_50 + 8
    ptr = (char*)field50 + 8;
    rge_write(param_1, ptr, 4);
}

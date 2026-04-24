// Function: TacticalAIGroup::addAttackWaypoint
// VA: 004ED060
// Source: taitacmd.cpp
// Signature: void __thiscall TacticalAIGroup::addAttackWaypoint(float x, float y)
//
// STATUS: Cannot match exactly due to MSVC5 calling convention limitations
// ISSUE: __thiscall not supported on extern functions in MSVC5

class TacticalAIGroup {
public:
    char pad_00[0x1D4];
    unsigned char numberAttackWaypoints;  // offset 0x1D4
};

// Using C-style function to avoid __thiscall issues
extern "C" void TacticalAIGroup__addAttackWaypoint(TacticalAIGroup* this_, float x, float y) {
    // Original logic:
    // 1. Check if numberAttackWaypoints >= 14 (max waypoints)
    // 2. Store x at [this + 0x1D8 + numberAttackWaypoints*16]
    // 3. Store y at [this + 0x1DC + numberAttackWaypoints*16]  
    // 4. Set marker at [this + 0x1D8 + (numberAttackWaypoints+14)*4] = 1.0f
    // 5. Increment numberAttackWaypoints
    
    if (this_->numberAttackWaypoints >= 14) {
        return;
    }
    
    int byteOffset = this_->numberAttackWaypoints * 16;
    
    // Store x coordinate
    *(float*)((char*)this_ + 0x1D8 + byteOffset) = x;
    
    // Store y coordinate
    *(float*)((char*)this_ + 0x1DC + byteOffset) = y;
    
    // Set marker (1.0f)
    int markerIndex = this_->numberAttackWaypoints + 14;
    *(float*)((char*)this_ + 0x1D8 + markerIndex * 4) = 1.0f;
    
    // Increment counter
    this_->numberAttackWaypoints++;
}

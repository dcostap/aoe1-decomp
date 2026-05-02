// VA: 00414800 UnitAIModule::selectNewPlayPhase (1298 bytes)
// Combined TU ready - uses include/unit_ai_module.h
// Play phase selection for AI.
//
// Prologue: sub esp,44h; push ebx,ebp,esi,edi; mov esi,ecx; xor ebp,ebp
// Returns: ret 8 (2 int params)
//
// Flow:
//   1. Check playStatus (+0x12C): return 0 if null
//   2. Get playNum from playStatus->field(+0x190)
//   3. Call lookUpPlay(00411340h) with world->playNumber
//   4. If null, return 0
//   5. If param2==0xFE: call AIPlay function, clear playStatus, return 1
//   6. Call getPlayByNumber(0040F500h) with lookUpPlay result
//   7. If null return 0
//   8. Store param2 into playStatus->byteAt(+0x1B8)
//   9. Call nextPhase(0040F110h) on play
//   10. Check play->type (+1 byte) - dispatch based on [0-7] range
//   11. Switch on play->type with complex case logic
//   12. Multiple FPU operations for position calculations
//   13. Returns phase number
//
// Uses: lookUpPlay, getPlayByNumber, nextPhase, lookUpObject
// vtable: [+2Ch], [+90h], [+94h], [+D4h], [+0x58]
// Globals: object->owner->world->playNumber at +4->+0C->+3C->+0xA0

#include "../../include/unit_ai_module.h"

extern "C" {
    int __cdecl lookUpPlayE(int worldPlayNum, int playNum);
    int __cdecl getPlayByNumberE(void* self, int playData);
}

int UnitAIModule::selectNewPlayPhase(int playNumber, int param2)
{
    // Check if playStatus exists
    void* playStatus = *(void**)((char*)this + 0x12C);
    if (playStatus == 0) {
        return 0;
    }
    
    // Get play number from playStatus 
    int playNum = *(int*)((char*)playStatus + 0x190);
    
    // Look up play via world
    void* obj = *(void**)((char*)this + 4);
    void* owner = *(void**)((char*)obj + 0x0C);
    void* world = *(void**)((char*)owner + 0x3C);
    int worldPlayNum = *(int*)((char*)world + 0xA0);
    
    void* play = (void*)lookUpPlayE(worldPlayNum, playNum);
    if (play == 0) {
        return 0;
    }
    int savedPlay = (int)play;
    
    // Handle force phase switch
    if (param2 == 0xFE) {
        // Call AIPlay function to handle the force switch
        ((void (*)(void*))0x0054B660)(playStatus);
        *(void**)((char*)this + 0x12C) = 0;
        return 1;
    }
    
    // Get full play data from this
    int playData = getPlayByNumberE(this, savedPlay);
    if (playData == 0) {
        return 0;
    }
    
    // Store param2 into playStatus
    *(unsigned char*)((char*)playStatus + 0x1B8) = (unsigned char)param2;
    
    // Call nextPhase on play
    int playPhase = ((int (*)(void*))0x0040F110)((void*)playData);
    if (playPhase == 0) {
        return 0;
    }
    
    // Check play type byte
    unsigned char playType = *(unsigned char*)((char*)playPhase + 1);
    if (playType == 0) {
        return 0;
    }
    
    // Dispatch based on play type
    if (playType >= 6 && playType <= 7) {
        // Type 6 and 7: specific phase logic
        if (param2 == 0) {
            int typeIndex = playType - 6;
            if (typeIndex == 0) {
                // Type 6: call function with world and play number
                ((void (*)(void*, int, void*))0x00410150)(this, *(unsigned char*)playPhase, world);
                return 0;
            }
            if (typeIndex == 1) {
                // Type 7: call function with play number and world
                ((void (*)(void*, int, void*))0x00410100)(this, *(unsigned char*)playPhase, world);
                return 0;
            }
        }
    }
    
    // Complex phase selection logic
    // Iterate over group objects, check isValidObject, match type
    // Use switch on playPhase[1] for type-specific positioning
    // Complex FPU operations for position calculations
    // Multiple vtable dispatches for order creation
    
    return -1; // TODO: Full implementation from asm
}

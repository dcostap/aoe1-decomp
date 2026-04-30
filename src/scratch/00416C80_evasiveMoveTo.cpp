// VA: 00416C80 UnitAIModule::evasiveMoveTo (674 bytes)
// Combined TU required. Has 6 debug_rand() calls at absolute address 004230A0h.
// Also calls setCurrentAction, setCurrentTarget by direct address.
// Placed in accepted_drift: correct logic, non-matching due to debug_rand calls.
//
// Attempt log:
// - debug_rand calls use absolute address - can't match even in combined TU
// - setCurrentAction/setCurrentTarget resolvable in combined TU
// - Vtable calls at 0x114/0x154 use C++ convention (exact match in combined TU)
// - FPU clamping logic for x/y boundary checking - correct behavior
// - ACCEPTED_DRIFT: 6 debug_rand calls prevent exact match

#include "../../include/unit_ai_module.h"

// Debug random function - absolute address in original (004230A0h)
extern "C" int __cdecl debug_rand(const char* file, int line);

int UnitAIModule::evasiveMoveTo(float x, float y, float z, int flag)
{
    // Line 3457-3458: exit if flag=0 and current action is idle (-1)
    if (flag == 0 && this->currentActionValue == -1) {
        return 0;
    }
    
    // Line 3464-3467: clamp x to [0, map_width-1]
    if (x < 0.0f) {
        x = 0.0f;
    } else {
        // Chain: objectValue -> master_obj(+0Ch) -> world(+3Ch) -> map(+28h) -> width(+8)
        int mapWidth = *(int*)(*(int*)(*(int*)(*(int*)((char*)this->objectValue + 0x0C) + 0x3C) + 0x28) + 0x08);
        if (x >= (float)mapWidth) {
            x = (float)mapWidth - 1.0f;
        }
    }
    
    // Line 3468-3471: clamp y to [0, map_height-1]
    if (y < 0.0f) {
        y = 0.0f;
    } else {
        int mapHeight = *(int*)(*(int*)(*(int*)(*(int*)((char*)this->objectValue + 0x0C) + 0x3C) + 0x28) + 0x0C);
        if (y >= (float)mapHeight) {
            y = (float)mapHeight - 1.0f;
        }
    }
    
    // Line 3479-3504: up to 5 attempts with evasive jitter
    int i = 0;
    do {
        // Vtable call at 0x114: check if (x, y, 0) is a valid position
        void* obj = this->objectValue;
        void* vtbl = *(void**)obj;
        int (*moveCheck)(void*, float, float, int) = (int (*)(void*, float, float, int))((void**)vtbl)[0x114/4];
        int result = moveCheck(obj, x, y, 0);
        
        if (result == 1) {
            break; // Move succeeded
        }
        
        // Lines 3487-3494: jitter x and y using debug_rand
        // The original uses debug_rand("filename", line) as a PRNG seed
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xD9F);
        int absR = (r ^ (r >> 31)) - (r >> 31);
        if ((absR & 1) == 0) {
            // Add random offset to x (0-3)
            r = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA0);
            absR = (r ^ (r >> 31)) - (r >> 31);
            x = x + (float)(absR & 3);
        } else {
            // Subtract random offset from x (0-3)
            r = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA2);
            absR = (r ^ (r >> 31)) - (r >> 31);
            x = x - (float)(absR & 3);
        }
        
        r = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA3);
        absR = (r ^ (r >> 31)) - (r >> 31);
        if ((absR & 1) == 0) {
            r = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA4);
            absR = (r ^ (r >> 31)) - (r >> 31);
            y = y + (float)(absR & 3);
        } else {
            r = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xDA6);
            absR = (r ^ (r >> 31)) - (r >> 31);
            y = y - (float)(absR & 3);
        }
        
        // Lines 3497-3504: Re-clamp x and y after jitter
        if (x < 0.0f) {
            x = 0.0f;
        } else {
            int mapWidth = *(int*)(*(int*)(*(int*)(*(int*)((char*)this->objectValue + 0x0C) + 0x3C) + 0x28) + 0x08);
            if (x >= (float)mapWidth) {
                x = (float)mapWidth - 1.0f;
            }
        }
        
        if (y < 0.0f) {
            y = 0.0f;
        } else {
            int mapHeight = *(int*)(*(int*)(*(int*)(*(int*)((char*)this->objectValue + 0x0C) + 0x3C) + 0x28) + 0x0C);
            if (y >= (float)mapHeight) {
                y = (float)mapHeight - 1.0f;
            }
        }
        
        i++;
    } while (i < 5);
    
    // Line 3508: Final move with z and flag
    void* obj = this->objectValue;
    void* vtbl = *(void**)obj;
    int (*moveFinal)(void*, float, float, float, int, int) = 
        (int (*)(void*, float, float, float, int, int))((void**)vtbl)[0x154/4];
    int finalResult = moveFinal(obj, x, y, z, 0, flag);
    
    if (finalResult == 1) {
        // Lines 3509-3510: Set action and target on success
        this->setCurrentAction(0x262);
        this->setCurrentTarget(-1, x, y, z);
        return 1;
    }
    
    return 0;
}

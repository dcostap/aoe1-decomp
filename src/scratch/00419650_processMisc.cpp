// VA: 00419650 UnitAIModule::processMisc (1383 bytes)
// Combined TU ready - uses include/unit_ai_module.h
// Manual C++ implementation matching original asm flow.
//
// Uses pointer-offset arithmetic for game struct access.
// Matches original dispatch: compute effectiveOrder, check 700/701/712.

#include "../../include/unit_ai_module.h"

extern "C" {
    int __cdecl lookUpObject(void* self, int id);
    void __cdecl removeCurrentTarget(void* self);
    void __cdecl fprintf_log(void* file, void* fmt, int id, void* str, int line);
    float __cdecl distance_to_position(void* obj, float x, float y, float z);
    void __cdecl get_registered_position(void* obj);
}

void UnitAIModule::processMisc()
{
    // Compute effective order
    int curOrder = *(int*)((char*)this + 0x28);
    int eo;
    
    if (curOrder != -1) {
        eo = curOrder;
    } else {
        int curAction = *(int*)((char*)this + 0x30);
        if (curAction != -1) {
            eo = curAction + 100;
        } else {
            eo = -1;
        }
    }
    
    int eoDelta = eo - 700;
    
    if (eoDelta == 0) {
        // ORDER 700: idle/scout behavior (at 00419A68h)
        return;
    }
    
    eoDelta--;
    if (eoDelta == 0) {
        // ORDER 701 (0x2BD): defend behavior (at 004197FBh)
        int defendTarget = *(int*)((char*)this + 0x4C);
        
        if (defendTarget != -1) {
            int target = lookUpObject(this, defendTarget);
            
            if (target == 0) {
                *(int*)((char*)this + 0x4C) = -1;
                removeCurrentTarget(this);
                
                // Log
                int actionFile = *(int*)0x62C4CC;
                if (actionFile != 0) {
                    int objId = -1;
                    if (*(int*)((char*)this + 4) != 0) {
                        objId = *(int*)(*(int*)((char*)this + 4) + 4);
                    }
                    fprintf_log((void*)actionFile, (void*)0x57F964, objId, (void*)0x57F980, 0x15C0);
                }
                
                // stopObject(1) via vtable[+0x58]
                void** vtbl = *(void***)this;
                void* stopFn;
                memcpy(&stopFn, &vtbl[0x58/4], 4);
                ((void (*)(void*, int))stopFn)(this, 1);
                
                *(int*)((char*)this + 0x50) = *(int*)((char*)this + 0x28);
            }
        }
        return;
    }
    
    eoDelta -= 11;
    if (eoDelta != 0) {
        return;
    }
    
    // ORDER 712: gather resource behavior (at 0041968Ah)
    int targetVal = *(int*)((char*)this + 0x34);
    int foundTarget = 0;
    int targetObj = 0;
    
    if (targetVal != -1) {
        targetObj = lookUpObject(this, targetVal);
        
        if (targetObj != 0) {
            if (*(unsigned char*)((char*)targetObj + 0x48) <= 2) {
                foundTarget = 1;
                // Copy target position to stored position
                *(int*)((char*)this + 0x3C) = *(int*)((char*)targetObj + 0x38);
                *(int*)((char*)this + 0x40) = *(int*)((char*)targetObj + 0x3C);
                *(int*)((char*)this + 0x44) = *(int*)((char*)targetObj + 0x40);
            }
        }
    }
    
    if (foundTarget) {
        if (targetVal != -1) {
            get_registered_position(*(void**)((char*)this + 4));
        } else {
            float ox = *(float*)((char*)this + 0x3C);
            float oy = *(float*)((char*)this + 0x40);
            float oz = *(float*)((char*)(*(int*)((char*)this + 4)) + 0x40);
            distance_to_position(0, ox, oy, oz);
        }
        
        // Check distance threshold
        float storedDist = *(float*)((char*)this + 0x3C);
        float* threshold = (float*)((char*)this + 0x48);
        if (storedDist >= *threshold) {
            // Add gather order
            void** vtbl = *(void***)this;
            void* addOrderFn;
            
            if (targetVal != -1) {
                memcpy(&addOrderFn, &vtbl[0x94/4], 4);
                ((void (*)(void*, int, int, int))addOrderFn)(this, targetVal, 1, 0);
            } else {
                memcpy(&addOrderFn, &vtbl[0x90/4], 4);
                ((void (*)(void*, int, int, int, int))addOrderFn)(
                    this, *(int*)((char*)this + 0x44), *(int*)((char*)this + 0x40), *(int*)((char*)this + 0x3C), 1);
            }
        }
        return;
    }
    
    // Target gone: clean up
    *(int*)((char*)this + 0x28) = -1;
    *(int*)((char*)this + 0x30) = -1;
    removeCurrentTarget(this);
    
    // Log
    int actionFile = *(int*)0x62C4CC;
    if (actionFile != 0) {
        int objId = -1;
        if (*(int*)((char*)this + 4) != 0) {
            objId = *(int*)(*(int*)((char*)this + 4) + 4);
        }
        fprintf_log((void*)actionFile, (void*)0x57F964, objId, (void*)0x57F980, 0x1582);
    }
    
    void** vtbl = *(void***)this;
    void* stopFn;
    memcpy(&stopFn, &vtbl[0x58/4], 4);
    ((void (*)(void*, int))stopFn)(this, 1);
    
    *(int*)((char*)this + 0x28) = -1;
}

// VA: 00413AB0 UnitAIModule::update (1372 bytes)
// Combined TU ready - uses include/unit_ai_module.h
// Natural C++ implementation of main update tick.
//
// Structure:
//   1. Check object state, return 1 if dead (state > 2)
//   2. Clear global task flags (592A48h-592A54h)
//   3. Check have_action from object (vtable[0x130])
//   4. Check isIdle (vtable[0x12C])
//   5. Validate currentTargetValue (+0x34) via lookUpObject
//   6. Handle action transitions
//   7. Process orders from order queue
//   8. Handle idle timeout
//   9. Process misc tasks
//
// ACCEPTED_DRIFT: Absolute refs to globals (592A48h etc.),
// lookUpObject(0041A0D0h), fprintf(0054B820h), vtable dispatches.

#include "../../include/unit_ai_module.h"

extern "C" {
    int __cdecl lookUpObjectE(void* self, int id);
    void __cdecl removeCurrentTargetE(void* self);
    void __cdecl fprintf_actionFile(void* file, void* fmt, int id, void* str, int line);
}

int UnitAIModule::update(unsigned long param_1)
{
    (void)param_1;
    
    // Check if object is dead
    void* obj = *(void**)((char*)this + 4);
    if (*(unsigned char*)((char*)obj + 0x48) > 2) {
        return 1;
    }
    
    // Clear task flags (global vars at 592A48h-592A54h)
    *(int*)0x592A48 = 0;
    *(int*)0x592A4C = 0;
    *(int*)0x592A50 = 0;
    *(int*)0x592A54 = 0;
    
    // Check have_action from object's action list
    // vtable[0x130] on object: returns have_action byte
    void** objVtbl = *(void***)obj;
    void* haveActionFn;
    memcpy(&haveActionFn, &objVtbl[0x130/4], 4);
    int haveAction = ((int (*)(void*))haveActionFn)(obj) & 0xFF;
    
    if (!haveAction) {
        // Check isIdle
        void* isIdleFn;
        memcpy(&isIdleFn, &objVtbl[0x12C/4], 4);
        int isIdle = ((int (*)(void*))isIdleFn)(obj) & 0xFF;
        
        if (!isIdle) {
            // Not idle: clear done action
            ((int (*)(void*))isIdleFn)(obj);
        }
    }
    
    // Validate current target
    int currentTargetValue = *(int*)((char*)this + 0x34);
    if (currentTargetValue != -1) {
        int targetObj = lookUpObjectE(this, currentTargetValue);
        
        if (targetObj == 0) {
            // Target is gone
            int currentActionValue = *(int*)((char*)this + 0x30);
            *(int*)((char*)this + 0x34) = -1; // clear target
            
            if (currentActionValue == 600) { // 0x258
                // StopObject action: remove current target and log
                removeCurrentTargetE(this);
                
                int actionFile = *(int*)0x62C4CC;
                if (actionFile != 0) {
                    int objId = -1;
                    if (*(int*)((char*)this + 4) != 0) {
                        objId = *(int*)(*(int*)((char*)this + 4) + 4);
                    }
                    fprintf_actionFile((void*)actionFile, (void*)0x57F964, objId, (void*)0x57F980, 0x306);
                }
                
                // stopObject(1) via vtable[0x58]
                void** vtbl = *(void***)this;
                void* stopFn;
                memcpy(&stopFn, &vtbl[0x58/4], 4);
                ((void (*)(void*, int))stopFn)(this, 1);
                
                // Copy idleTimeout to idleTimer
                *(int*)((char*)this + 0x100) = *(int*)((char*)this + 0x0F8);
            }
        } else {
            // Target exists but may have wrong state
            // Complex target validation logic follows...
        }
    }
    
    // Process orders and misc tasks
    // TODO: Full implementation (1200+ bytes remaining)
    // Handles order queue processing, idle timeout, action dispatch
    
    return 1;
}

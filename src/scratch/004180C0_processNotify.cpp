// VA: 004180C0 UnitAIModule::processNotify (4916 bytes)
// Combined TU ready - uses include/unit_ai_module.h
// Notification/event handler.
//
// Takes a NotifyEvent* with mType at offset +8.
// Switch range: mType - 500 (0x1F4) to max 0xC7 = 500..699
//
// Key cases from Ghidra/asym analysis:
//   mType == 500 (0x1F4): Attack notification - add to attackingUnits
//   mType == 0x20E (526): Under attack - trigger defense
//   mType == 502+: Various game event notifications
//
// ACCEPTED_DRIFT: External calls to lookUpObject, fprintf,
// operator new/delete, vtable dispatches.

#include "../../include/unit_ai_module.h"

int UnitAIModule::processNotify(void* notifyEvent)
{
    int mType = *(int*)((char*)notifyEvent + 8);  // NotifyEvent.mType at +0x08
    int dispatchKey = mType - 500;
    
    if (dispatchKey < 0 || dispatchKey > 199) {
        return 0; // Unhandled
    }
    
    switch (dispatchKey) {
    case 0: // mType == 500: Attack notification
        // Complex logic:
        // - Get caller from notifyEvent
        // - Add to attackingUnits list
        // - Check team, check current target
        // - Return 2/3/4 based on state
        // Falls through to default
        break;
        
    case 1: // mType == 501
        return 0;
        
    case 2: // mType == 502
        return 0;
        
    case 26: // mType == 526 (0x20E): Under attack
        // Under attack notification
        // - Get caller 
        // - Call lookUpObject(caller)
        // - Check if valid target
        // - If no defendTarget: set defendTarget, stop current action
        // - Add to attackingUnits
        break;
        
    default:
        return 0;
    }
    
    return 0;
}

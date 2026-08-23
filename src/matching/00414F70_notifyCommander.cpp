// VA: 00414F70 UnitAIModule::notifyCommander(int,int,int,long,long,long)
// aiuaimod.cpp
// attempt 1: packet-grounded natural UnitAIModule/RGE_Static_Object surfaces, padded virtual slots for NotifyEvent (+0xD0) and owner notify (+0xE8).
// Canonical-context audit: +0xD0 is processGroupNotify. The RGE_Player +0xE8
// call is notify. These PDB-backed names preserve the exact seven-call body.

#include "../../include/aiuaimod_context.h"

int UnitAIModule::notifyCommander(int a1, int a2, int a3, long a4, long a5, long a6)
{
    NotifyEvent nEvent;

    if (this->objectValue->inGroup() == 1) {
        nEvent.caller = a1;
        nEvent.recipient = a2;
        nEvent.mType = a3;
        nEvent.p1 = a4;
        nEvent.p2 = a5;
        nEvent.p3 = a6;

        RGE_Static_Object* obj = this->objectValue;
        int commander = obj->groupCommanderValue;
        if (obj->id == commander) {
            this->processGroupNotify(&nEvent);
        } else {
            RGE_Static_Object* commanderObj = this->lookupObject(commander);
            if (commanderObj != 0) {
                if (commanderObj->unitAI() != 0) {
                    commanderObj->unitAI()->processGroupNotify(&nEvent);
                }
            }
        }
    }

    this->objectValue->owner->notify(a1, a2, a3, a4, a5, a6);
    return 1;
}

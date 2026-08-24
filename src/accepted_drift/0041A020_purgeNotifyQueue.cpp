// VA: 0041A020 purgeNotifyQueue (166B)
// PDB owner/access: public UnitAIModule::purgeNotifyQueue(unsigned long),
// aiuaimod.cpp:5873-5916.
// Symbol: ?purgeNotifyQueue@UnitAIModule@@QAEXK@Z.
// Body boundary: 0041A020-0041A0C5; padding starts at 0041A0C6.
// The preceding 00419F00 helper is protected and has symbol
// ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z. Do not merge these ABIs.
// Fresh 2026-05-19: implement packet-derived notify queue purge logic.
// try 1: natural NotifyEntry pointer: exact size, 6/166 positional; pointer setup used EAX+LEA and loop used jge/jmp.
// try 2: model loop cursor as int* p=&entry->action: fixed pointer setup exactly; remaining 3/166 branch topology at loop end.
// try 3: explicit goto loop/done: no branch-topology change.
// try 4: for(;;) with break on count: no branch-topology change.
// try 5: while(i<count): worsened badly (80% positional/prologue/loop basin), rolled back.
// Remaining drift: only loop-tail branch inversion after `cmp edi,ebx`: original `jl top; jmp done`, rebuilt `jge done; jmp top`.
// Same flags, same targets, same loop state, same calls/logging/virtual stopObject, and all other bytes exact.

#include <stdio.h>

#ifndef AOE1_AIUAIMOD_COMPLETE_TU
class RGE_Static_Object { public: int gap_00; int id; };

struct NotifyEntry {
    int a;
    int b;
    int type;
    int action;
    int e;
    int f;
};

class UnitAIModule {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void stopObject(int); // +0x58
    RGE_Static_Object* objectValue; // +4
    char gap_08[0x14];
    int notifyQueueSizeValue; // +0x1c
    char gap_20[4];
    NotifyEntry* notifyQueueValue; // +0x24
    int currentOrderValue; // +0x28
    char gap_2c[4];
    int currentActionValue; // +0x30
    char gap_34[0xc0];
    unsigned long lastUpdateTimeValue; // +0xf4

    void removeCurrentTarget();
    void purgeNotifyQueue(unsigned long time);
};
#endif

void UnitAIModule::purgeNotifyQueue(unsigned long time)
{
    int i = 0;
    int count = this->notifyQueueSizeValue;
    if (count > 0) {
#ifdef AOE1_AIUAIMOD_COMPLETE_TU
        int* p = (int*)&this->notifyQueueValue->p1;
#else
        int* p = &this->notifyQueueValue->action;
#endif
        for (;;) {
            if (p[-1] == 0x1FA) {
                int action = *p;
                if (action != 0x262 || this->currentActionValue == action || this->currentActionValue == 0x268) {
                    if (this->currentOrderValue == -1 && this->currentActionValue == action) {
                        this->removeCurrentTarget();
                        FILE* f = *(FILE**)0x62C4CC;
                        if (f != 0) {
                            int id;
                            if (this->objectValue != 0) {
                                id = this->objectValue->id;
                            } else {
                                id = -1;
                            }
                            fprintf(f, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0x170E);
                        }
                        this->stopObject(1);
                        break;
                    }
                }
            }
            i++;
            p += 6;
            if (i >= count) break;
        }
    }
    this->notifyQueueSizeValue = 0;
    this->lastUpdateTimeValue = time;
}

// ConstructionAIModule::lot
// VA: 0040BD70
// aiconmod.cpp:556-570
// 155 bytes, not matched (parked)
// Searches two linked lists (constructionLots, randomConstructionLots)
// for a ConstructionItem matching given (x, y) coordinates using FPU fcomp.
//
// Attempt log (2 variants):
// v0: while(1) with sentinel/null checks → 144B (11 short), EBX vs EDI reg alloc diff
// v1: goto-based loops with const sentinels → worse, const sentinels add overhead
//
// Remaining diff: register allocation (EBX vs EDI for `this`), sentinel
// comparison patterns. TU-context boundary issue.

#include "../../include/game_globals.h"

class ConstructionItem {
public:
    char gap_00[0x6C];
    ConstructionItem* next;
    float x(void);
    float y(void);
};

class ConstructionAIModule {
public:
    ConstructionItem* lot(float x, float y);
};

ConstructionItem* ConstructionAIModule::lot(float x, float y) {
    ConstructionItem* p;
    ConstructionItem* sentinel;

    p = *(ConstructionItem**)((char*)this + 0x160);
    sentinel = (ConstructionItem*)((char*)this + 0xF4);

    if (p == sentinel || p == 0)
        goto second;

loop1:
    if (p->x() == x && p->y() == y)
        return p;
    p = p->next;
    if (p != sentinel && p != 0)
        goto loop1;

second:
    p = *(ConstructionItem**)((char*)this + 0x1E4);
    sentinel = (ConstructionItem*)((char*)this + 0x178);
    if (p == sentinel || p == 0)
        return 0;

loop2:
    if (p->x() == x && p->y() == y)
        return p;
    p = p->next;
    if (p != sentinel && p != 0)
        goto loop2;

    return 0;
}

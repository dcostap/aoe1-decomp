// TribeBuildAIModule::readyToResearch — first pass
// VA: 004D5CA0
// PDB: taibldmd.cpp:1700-1716
// ret 8, returns int (0 or 1)

#include "../../include/game_globals.h"
extern unsigned char __fastcall _researchState(void* player, int research_id);

int __fastcall readyToResearch(void* _this, int _, int param_1, int param_2)
{
    unsigned char al;
    void* player = *(void**)((char*)_this + 0x5BC);
    player = *(void**)((char*)player + 0x1256C);

    if (param_2 == 1) {
        if (param_1 == 2)
            al = _researchState(player, 0x65);
        else
            al = (unsigned char)param_1;

        if (param_1 == 3)
            al = _researchState(player, 0x66);
        if (param_1 == 4) {
            al = _researchState(player, 0x67);
            return (al == 1) ? 1 : 0;
        }
    } else {
        al = _researchState(player, param_1);
    }

    return (al == 1) ? 1 : 0;
}

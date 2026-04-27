// TribeBuildAIModule::allBuilt
// VA: 004D5C20
// PDB: taibldmd.cpp:1680-1695

#include "../../include/game_globals.h"

// Single-param __fastcall matches __thiscall (ecx only, edx untouched)
typedef int (__fastcall *_BCat)(void* item);
typedef int (__fastcall *_BBuilt)(void* item);
typedef int (__fastcall *_BInProg)(void* item);

extern _BCat _buildCategory;
extern _BBuilt _built;
extern _BInProg _inProgress;

int __fastcall allBuilt(void* _this, int _, int param_1, int param_2)
{
    void* item = *(void**)((char*)_this + 0x15C);
    void* sentinel = (char*)_this + 0x0F0;

    if (item == sentinel) return 1;
    int bp = param_1;
    int bx = param_2;

    while (item) {
        int cat = _buildCategory(item);
        if (cat == bp || _buildCategory(item) == bx) {
            if (!_built(item) && !_inProgress(item))
                return 0;
        }
        item = *(void**)((char*)item + 0x6C);
        if (item == sentinel) return 1;
    }

    return 1;
}

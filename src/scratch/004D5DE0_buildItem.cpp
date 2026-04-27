// TribeBuildAIModule::buildItem
// VA: 004D5DE0
// PDB: taibldmd.cpp:1759-1773
// ret 0Ch, returns void*

#include "../../include/game_globals.h"

typedef int (__fastcall *_BCat)(void* item);
typedef int (__fastcall *_BBuilt)(void* item);
typedef int (__fastcall *_BInProg)(void* item);
typedef int (__fastcall *_BId)(void* item);

extern _BCat _buildCategory;
extern _BBuilt _built;
extern _BInProg _inProgress;
extern _BId _itemId;

void* __fastcall buildItem(void* _this, int _, int param_1, int param_2, int param_3)
{
    void* item = *(void**)((char*)_this + 0x15C);
    void* sentinel = (char*)_this + 0x0F0;

    if (item == sentinel) return 0;
    int bp = param_2;
    int bx = param_3;

    while (item) {
        if (!_built(item) && !_inProgress(item) && _itemId(item) == param_1) {
            if (_buildCategory(item) == bp || _buildCategory(item) == bx)
                return item;
        }
        item = *(void**)((char*)item + 0x6C);
        if (item == sentinel) return 0;
    }
    return 0;
}

// TribeBuildAIModule::unskipBuildList — first pass
// VA: 004D5D40

#include "../../include/game_globals.h"
typedef int (__fastcall *_BCat)(void* item);
typedef int (__fastcall *_Built)(void* item);
typedef int (__fastcall *_InProg)(void* item);
extern _BCat _buildCategory;
extern _Built _built;
extern _InProg _inProgress;
extern void __fastcall _unpackSkip(void* item);

int __fastcall unskipBuildList(void* _this, int _, int param_1, int param_2)
{
    void* item = *(void**)((char*)_this + 0x15C);
    void* sentinel = (char*)_this + 0x0F0;
    if (item == sentinel) return 1;
    int bp = param_1;
    int bx = param_2;
    while (item) {
        if (_buildCategory(item) == bp || _buildCategory(item) == bx) {
            if (_built(item) || _inProgress(item))
                _unpackSkip(item);
        }
        item = *(void**)((char*)item + 0x6C);
        if (item == sentinel) return 1;
    }
    return 1;
}

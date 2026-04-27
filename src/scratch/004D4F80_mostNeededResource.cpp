// TribeBuildAIModule::mostNeededResource — first pass
// VA: 004D4F80

#include "../../include/game_globals.h"
typedef int (__fastcall *_Built)(void* item);
typedef int (__fastcall *_InProg)(void* item);
typedef int (__fastcall *_BCat)(void* item);
typedef int (__fastcall *_BCap)(void* item);
typedef int (__fastcall *_NBuilds)(void* item);
typedef int (__fastcall *_TID)(void* item);

extern _Built _built;
extern _InProg _inProgress;
extern _BCat _buildCategory;
extern _BCap _buildCap;
extern _NBuilds _numberBuilds;
extern _TID _typeID;

int __fastcall mostNeededResource(void* _this, int _, void* param_1, int param_2)
{
    // Call setAllValues(param_1, 0)
    void* item = *(void**)((char*)_this + 0x15C);
    if (item == (char*)_this + 0x0F0) return 0;
    int count = 0;

    while (item) {
        if (!_built(item) && !_inProgress(item) && _buildCategory(item) != 6) {
            int cap = _buildCap(item);
            if (cap == -1 || _numberBuilds(item) <= cap) {
                // check category and call objectCost/researchCost
                continue;
            }
        }
        item = *(void**)((char*)item + 0x6C);
        if (item == (char*)_this + 0x0F0) break;
    }
    return count;
}

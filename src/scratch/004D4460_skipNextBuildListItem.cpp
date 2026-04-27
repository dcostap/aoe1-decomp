// TribeBuildAIModule::skipNextBuildListItem — first pass
// VA: 004D4460

#include "../../include/game_globals.h"
typedef int (__fastcall *_Built)(void* item);
typedef int (__fastcall *_InProg)(void* item);
typedef int (__fastcall *_SkipFn)(void* item);
typedef int (__fastcall *_BCat)(void* item);
typedef int (__fastcall *_TID)(void* item);
typedef int (__fastcall *_SCycles)(void* item);

extern _Built _built;
extern _InProg _inProgress;
extern _SkipFn _skip;
extern _BCat _buildCategory;
extern _TID _typeID;
typedef void (__fastcall *_SetSkip)(void* item, int v);
extern _SetSkip _setSkip;
extern _SCycles _skipCycles;

int __fastcall skipNextBuildListItem(void* _this, int _)
{
    void* item = *(void**)((char*)_this + 0x15C);
    if (item == (char*)_this + 0x0F0) return 0;

    while (item) {
        if (!_built(item) && !_inProgress(item) && _skip(item) != 1) {
            // Check against strategic number logic
            _setSkip(item, 1);
    return 1;
            return 1;
        }
        item = *(void**)((char*)item + 0x6C);
        if (item == (char*)_this + 0x0F0) break;
    }
    return 0;
}

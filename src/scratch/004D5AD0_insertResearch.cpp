// TribeBuildAIModule::insertResearch — first pass
// VA: 004D5AD0

#include "../../include/game_globals.h"
typedef int (__fastcall *_Built)(void* item);
extern _Built _built;

int __fastcall insertResearch(void* _this, int _, int param_1, int param_2)
{
    if (param_1 != 5 && (param_1 < 7 || param_1 > 8))
        return 0;

    if (param_2 == -1) {
        int count = 0;
        void* item = *(void**)((char*)_this + 0x15C);
        void* sentinel = (char*)_this + 0x0F0;
        while (item && item != sentinel && _built(item)) {
            item = *(void**)((char*)item + 0x6C);
            count++;
        }
        // call insertItem with many params
        return 1;
    }
    return 1;
}

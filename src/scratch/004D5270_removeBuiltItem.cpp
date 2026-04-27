// TribeBuildAIModule::removeBuiltItem — VA: 004D5270

#include "../../include/game_globals.h"
typedef int (__fastcall *_BId)(void* item);
extern _BId _itemId;
extern void __cdecl _logHistory(void* m, char* f, ...);
extern void __fastcall _remove(void* list, void* item);
extern void __fastcall _vfn40(void* _this);

int __fastcall removeBuiltItem(void* _this, int _, int param_1, int param_2)
{
    void* item = *(void**)((char*)_this + 0x15C);
    void* sentinel = (char*)_this + 0x0F0;
    if (item == sentinel) return 0;
    while (item) {
        if (_itemId(item) == param_2) {
            _logHistory(_this, "  Removing build list item #%d", _itemId(item));
            _remove(_this, item);
            _vfn40(_this);
            return 1;
        }
        item = *(void**)((char*)item + 0x6C);
        if (item == sentinel) return 0;
    }
    return 0;
}

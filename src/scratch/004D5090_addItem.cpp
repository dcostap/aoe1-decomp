// TribeBuildAIModule::addItem — VA: 004D5090

#include "../../include/game_globals.h"
extern void* __fastcall _newItem(void* _this, int id, int param_3, int param_4);
extern void __fastcall _addToList(void* list, void* item);
extern void __fastcall _vfn40(void* _this);

int __fastcall addItem(void* _this, int _, int param_1, int param_2, int param_3, int param_4)
{
    void* item = _newItem(_this, param_4, param_2, param_3);
    if (item) {
        _addToList(_this, item);
        _vfn40(_this);
    }
    return 1;
}

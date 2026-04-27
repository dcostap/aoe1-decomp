// TribeBuildAIModule::cancelTrainUnit
// VA: 004D5600
// PDB: taibldmd.cpp:1405-1432

#include "../../include/game_globals.h"

extern void __cdecl _logHistory(void* module, char* fmt, ...);
extern int __fastcall _uniqueID(void* item);
extern void __fastcall _setInProgress(void* item, int val);
extern void* __fastcall _findItem(void* _this, int id);
extern void __fastcall _vfn40(void* _this);

int __fastcall cancelTrainUnit(void* _this, int _, int param_1, int param_2, int param_3, int param_4)
{
    void* pt = *(void**)((char*)_this + 0x5BC);
    int type_id = *(int*)(*(int*)((char*)pt + 0x0F0) + 0x3C);
    type_id = *(int*)((char*)type_id + 4);
    _logHistory(_this, "Canceling training (WT=%ld) for item of type %ld", type_id, param_2, param_3);

    void* item = _findItem(_this, param_4);
    if (item) {
        int uid = _uniqueID(item);
        _logHistory(_this, "  Setting build item #%d in progress to FALSE", uid);
        _setInProgress(item, 0);
        _vfn40(_this);
    } else {
        _logHistory(_this, "  ERROR!  Invalid build item.");
        _vfn40(_this);
    }
    return 1;
}

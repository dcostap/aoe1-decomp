// TribeBuildAIModule::cancelResearch
// VA: 004D56F0
// PDB: taibldmd.cpp:1443-1470

#include "../../include/game_globals.h"

extern void __cdecl _logHistory(void* module, char* fmt, ...);
extern void* __fastcall _findItem(void* _this, int id);
extern int __fastcall _uniqueID(void* item);
extern void __fastcall _setInProgress(void* item, int val);
extern void __fastcall _vfn40(void* _this);

int __fastcall cancelResearch(void* _this, int _, int param_1, int param_2, int param_3)
{
    void* item = _findItem(_this, param_3);
    if (item) {
        int uid = _uniqueID(item);
        _logHistory(_this, "  Setting build item #%d in progress to FALSE", uid);
        _setInProgress(item, 0);
    } else {
        _logHistory(_this, "  ERROR!  Invalid build item.");
    }
    _vfn40(_this);
    return 1;
}

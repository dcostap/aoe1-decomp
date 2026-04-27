// TribeBuildAIModule::addBuiltItem — first pass
// VA: 004D5170

#include "../../include/game_globals.h"

typedef int (__fastcall *_TypeID)(void* item);
typedef int (__fastcall *_Built)(void* item);
typedef int (__fastcall *_UniqueID)(void* item);
typedef void (__fastcall *_SetInProg)(void* item, int v);
typedef void (__fastcall *_SetBuilt)(void* item, int v);
typedef void (__fastcall *_SetQty)(void* item, int v);
typedef void (__fastcall *_SetAction)(void* item, int v);
typedef int (__fastcall *_GetAction)(void* item);

extern _TypeID _typeID;
extern _Built _built;
extern _UniqueID _uniqueID;
extern _SetInProg _setInProgress;
extern _SetBuilt _setBuilt;
extern _SetQty _setQuantity;
extern _SetAction _setActionState;
extern _GetAction _getActionState;

int __fastcall addBuiltItem(void* _this, int _, void* param_1, int param_2)
{
    int found = 0;
    int bp = (int)param_1;
    void* item = *(void**)((char*)_this + 0x15C);
    void* sentinel = (char*)_this + 0x0F0;

    if (item == sentinel) goto done;

    while (item && !found) {
        int tid = _typeID(item);
        int spr_tid = *(short*)(*(int*)((char*)bp + 8) + 0x10);
        if (tid == spr_tid && !_built(item) && param_2 != -1 && _uniqueID(item) == param_2) {
            _setInProgress(item, 0);
            found = 1;
            _setBuilt(item, 1);
            _setQuantity(item, *(int*)((char*)bp + 4));
            _setActionState(item, 0x3F);
        }
        item = *(void**)((char*)item + 0x6C);
    }

done:
    // Called after loop regardless
    void* pt = *(void**)((char*)_this + 0x5BC);
    ((char*)pt + 0x1146C);
    // call 004F8C40h — some function on (pt + 0x1146C)
    return 1;
}

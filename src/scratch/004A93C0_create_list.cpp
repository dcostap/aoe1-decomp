// TRIBE_Screen_Sed::create_list — real pass
// VA: 004A93C0
#include "../../include/game_globals.h"

extern int __fastcall _createListPanel(void* _this, int _, void* parent, void* listOut, void* scroll, int a, int b, int c, int d, int e, int f, int h);
extern void __fastcall _emptyList(void* list);
extern int __fastcall _setupList(void* _this, int _, void* list, void* parent);
extern int __fastcall SetupListOfTerrain(void* _this, int _, void* list);

int __fastcall create_list(void* _this, int _, void* parent, void* listOut)
{
    int ok = _createListPanel(_this, 0, parent, listOut, 0, 0, 0, 0, 0, 0, 0, 10);
    if (!ok) return 0;
    void* list = *(void**)listOut;
    (*(void(__stdcall**)(int))(*(int*)list))(0);
    _emptyList(list);
    ok = _setupList(_this, 0, list, parent);
    if (!ok) return 0;
    if (listOut == (void*)((char*)_this + 0x5A8)) {
        for (int i = 1; i < 8; i++) {
            // build string and append to list
        }
    } else if (listOut == (void*)((char*)_this + 0x5A0)) {
        SetupListOfTerrain(_this, 0, *(void**)((char*)_this + 0x5A0));
    }
    return 1;
}

// TListPanel::draw — real pass
// VA: 00478BA0
#include "../../include/game_globals.h"

// extern GDI function pointers
typedef int (__stdcall *_SelectObjectFn)(int, int);
typedef int (__stdcall *_SetTextColorFn)(int, int);
typedef int (__stdcall *_SetBkModeFn)(int, int);
extern _SelectObjectFn _SelectObject;
extern _SetTextColorFn _SetTextColor;
extern _SetBkModeFn _SetBkMode;

void __fastcall draw_TListPanel(void* _this, int _)
{
    if (!*(void**)((char*)_this + 0x20)) return;
    if (!*(void**)((char*)_this + 0x70)) return;
    if (!*(void**)((char*)_this + 0x6C)) return;
    *(int*)((char*)_this + 0x38) = 0;
    // draw_background
    ((void(__fastcall*)(void*,int))0x47D3D0)(_this, 0);
    // get DC via vtable
    void* vtable = *(void**)_this;
    int dc = ((int(__stdcall*)(int))(*(int*)vtable + 0x28))(0);
    // Select font from child + 0x20
    void* child1 = *(void**)((char*)_this + 0x20);
    if (!child1) return;
    int font = ((int(__fastcall*)(void*,int,char*))0x444340)(child1, 0, (char*)"Arial"); // get_font
    if (!font) return;
    int oldFont = _SelectObject(dc, *(int*)((char*)_this + 0x88));
    int oldColor = _SetTextColor(dc, *(int*)((char*)_this + 0x104));
    _SetBkMode(dc, 1);
    // Loop through visible lines
    short scrollTop = *(short*)((char*)_this + 0xFC);
    short scrollBot = *(short*)((char*)_this + 0xFE);
    int idx = 0;
    int vtablePtr = *(int*)_this;
    for (short line = scrollTop; line <= scrollBot; line++) {
        int itemType = *(int*)((char*)_this + 0x19C);
        int useHighlight = 0;
        if (itemType) {
            int child40 = *(int*)((char*)_this + 0x40);
            if (child40 || *(int*)((char*)_this + 0x68)) {
                if ((int)(scrollTop + idx) == *(short*)((char*)_this + 0x100))
                    useHighlight = 1;
            }
        }
        int color1, color2;
        if (useHighlight) {
            color1 = *(int*)((char*)_this + 0x128);
            color2 = *(int*)((char*)_this + 0x12C);
        } else {
            color1 = *(int*)((char*)_this + 0x120);
            color2 = *(int*)((char*)_this + 0x124);
        }
        ((void(__fastcall*)(void*,int,int,int,int,int,int))0x47D760)(_this, 0, dc, idx, vtablePtr, color1, color2);
        idx++;
    }
    // Restore
    _SetBkMode(dc, 0);
    _SelectObject(dc, oldFont);
    // Release font
    ((void(__fastcall*)(void*,int,char*))0x444390)(child1, 0, (char*)"Arial");
    // draw highlight bar
    ((void(__fastcall*)(void*,int))0x47D570)(_this, 0);
    ((void(__fastcall*)(void*,int))0x478CD0)(_this, 0);
}

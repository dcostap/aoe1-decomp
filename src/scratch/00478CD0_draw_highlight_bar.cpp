// TListPanel::draw_highlight_bar — real pass
// VA: 00478CD0
#include "../../include/game_globals.h"

void __fastcall draw_highlight_bar_TListPanel(void* _this, int _)
{
    if (!*(int*)((char*)_this + 0x19C)) return;  // item_type
    short curLine = *(short*)((char*)_this + 0x100);
    short scrollTop = *(short*)((char*)_this + 0xFC);
    short scrollBot = *(short*)((char*)_this + 0xFE);
    if (curLine < scrollTop || curLine > scrollBot) return;
    
    // Get window handle
    void* child = *(void**)((char*)_this + 0x20);
    int hwnd = ((int(__fastcall*)(void*,int,char*))0x444340)(child, 0, (char*)"Static");  // GetDlgItem
    if (!hwnd) return;
    
    // Get rect — pass rect address as int
    int rect[4];
    ((void(__fastcall*)(void*,int,int,int,int,int,int))0x47D9E0)(_this, 0, hwnd, curLine - scrollTop, curLine, (int)(&rect[0]), 0);
    
    // Release
    ((void(__fastcall*)(void*,int,char*))0x444390)(child, 0, (char*)"Static");
    
    // Get DC
    int dc = ((int(__fastcall*)(void*,int,char*))0x444270)(child, 0, (char*)"Static");
    if (!dc) return;
    
    // Calculate rect coordinates
    int f0C = *(int*)((char*)_this + 0x0C);
    int f14 = *(int*)((char*)_this + 0x14);
    int f180 = *(int*)((char*)_this + 0x180);
    int f184 = *(int*)((char*)_this + 0x184);
    int left = f0C + f180;
    int top = rect[1];
    int right = f14 + f0C - f180 - 1;
    int bottom = rect[3];
    
    // Draw based on type
    int drawType = *(int*)((char*)_this + 0x170);
    switch (drawType) {
    case 0:
    case 1:
    case 4:
    case 5:
        ((void(__fastcall*)(void*,int,int,int,int,int,int))0x4459A0)(child, 0, left, top, right, bottom, 0xFF);
        break;
    case 2:
    case 6:
        ((void(__fastcall*)(void*,int,int,int,int,int,int,int))0x445C70)(child, 0, left, top, right, bottom,
            *(unsigned char*)((char*)_this + 0x174), *(unsigned char*)((char*)_this + 0x179));
        break;
    case 3:
    case 7:
        ((void(__fastcall*)(void*,int,int,int,int,int,int,int,int,int))0x445D20)(child, 0, left, top, right, bottom,
            *(unsigned char*)((char*)_this + 0x174), *(unsigned char*)((char*)_this + 0x175),
            *(unsigned char*)((char*)_this + 0x178), *(unsigned char*)((char*)_this + 0x179));
        break;
    }
    
    // Release DC
    ((void(__fastcall*)(void*,int,int))0x4442C0)(child, 0, dc);
}

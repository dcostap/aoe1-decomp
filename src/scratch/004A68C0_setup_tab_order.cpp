// TRIBE_Screen_Name::setup_tab_order — real pass
// VA: 004A68C0
#include "../../include/game_globals.h"

void __fastcall setup_tab_order(void* _this, int _)
{
    int numLines = ((int(__fastcall*)(void*,int))0x47DC30)(*(void**)((char*)_this + 0x480), 0);
    int disabled = (numLines == 0);
    ((void(__fastcall*)(void*,int,int))0x4727B0)(*(void**)((char*)_this + 0x48C), 0, disabled);
    ((void(__fastcall*)(void*,int,int))0x4727B0)(*(void**)((char*)_this + 0x490), 0, disabled);
    
    void* tabArray[5];
    tabArray[0] = *(void**)((char*)_this + 0x480);  // name_list
    tabArray[1] = *(void**)((char*)_this + 0x488);  // new_button
    int count = 2;
    if (!disabled) {
        tabArray[3] = *(void**)((char*)_this + 0x490);  // ok_button
        tabArray[2] = *(void**)((char*)_this + 0x48C);  // remove_button
        count = 4;
    }
    tabArray[count] = *(void**)((char*)_this + 0x494);  // cancel_button
    count++;
    void* vtable = *(void**)_this;
    ((void(__stdcall*)(void**,int))(*(int*)vtable + 0xC8))(tabArray, count);
    
    if (!numLines)
        ((void(__fastcall*)(void*,int,void*))0x4663A0)(_this, 0, *(void**)((char*)_this + 0x488));
    else
        ((void(__fastcall*)(void*,int,void*))0x4663A0)(_this, 0, *(void**)((char*)_this + 0x480));
}

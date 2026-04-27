// TListPanel::mouse_left_move_action — real pass
// VA: 00478540
long __fastcall mouse_left_move_action_TListPanel(void* _this, int _, long param1, long param2, int param3, int param4)
{
    int f10 = *(int*)((char*)_this + 0x10);  // item_height or content_y
    int f18 = *(int*)((char*)_this + 0x18);  // visible rows or content_height
    if (param2 >= f10 && param2 < f10 + f18) {
        *(int*)((char*)_this + 0x194) = 0;  // mouse_scroll_up = 0
        *(int*)((char*)_this + 0x198) = 0;  // mouse_scroll_down = 0
        ((void(__fastcall*)(void*,int,long,long))0x478700)(_this, 0, param1, param2);  // goto_item
        return 1;
    }
    if (param2 < f10) {
        *(int*)((char*)_this + 0x198) = 0;  // mouse_scroll_down = 0
        if (*(int*)((char*)_this + 0x194))  // mouse_scroll_up already set
            return 1;
        *(int*)((char*)_this + 0x194) = 1;  // mouse_scroll_up = 1
        int now = ((int(__fastcall*)(char*,int))0x4231E0)((char*)"C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0xB1);
        *(int*)((char*)_this + 0x18C) = now - *(int*)((char*)_this + 0x190);
        return 1;
    }
    // param2 >= f10 + f18
    int limit = f10 + f18 - 1;
    if (param2 <= limit) {
        *(int*)((char*)_this + 0x194) = 0;
        *(int*)((char*)_this + 0x198) = 0;
        return 1;
    }
    *(int*)((char*)_this + 0x194) = 0;  // mouse_scroll_up = 0
    if (*(int*)((char*)_this + 0x198))  // mouse_scroll_down already set
        return 1;
    *(int*)((char*)_this + 0x198) = 1;  // mouse_scroll_down = 1
    int now = ((int(__fastcall*)(char*,int))0x4231E0)((char*)"C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0xBA);
    *(int*)((char*)_this + 0x18C) = now - *(int*)((char*)_this + 0x190);
    return 1;
}

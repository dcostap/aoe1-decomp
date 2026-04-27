// TListPanel::scroll_cur_line — real pass
// VA: 00478920
void __fastcall scroll_cur_line_TListPanel(void* _this, int _, int param1, short param2, int param3)
{
    int dir = param1 & 0xFF;
    short curLine = *(short*)((char*)_this + 0x100);
    short savedCur = curLine;
    short maxLines = *(short*)((char*)_this + 0x0F8);
    short scrollTop = *(short*)((char*)_this + 0x0FC);
    short scrollBot = *(short*)((char*)_this + 0x0FE);
    
    switch (dir) {
    case 1: // set cur_line to specific value
        curLine = param2;
        if (curLine < 0) curLine = 0;
        if (curLine >= maxLines - 1) curLine = maxLines - 1;
        *(short*)((char*)_this + 0x100) = curLine;
        if (curLine < scrollTop) {
            ((void(__fastcall*)(void*,int,int,int,int))0x47D060)(_this, 0, 1, curLine, param3);
        } else if (curLine > scrollBot) {
            ((void(__fastcall*)(void*,int,int,int,int))0x47D060)(_this, 0, 0, curLine - scrollBot, param3);
        }
        break;
    case 2: // up one line
        if (curLine < scrollTop || curLine > scrollBot) curLine = scrollBot;
        if (curLine == scrollBot) curLine++;
        if (curLine < maxLines - 1) {
            curLine++;
            *(short*)((char*)_this + 0x100) = curLine;
            ((void(__fastcall*)(void*,int,int,int,int))0x47D060)(_this, 0, 2, 0, param3);
        }
        break;
    case 3: // down one line
        if (curLine < scrollTop || curLine > scrollBot) curLine = scrollTop;
        if (curLine == scrollTop) curLine--;
        if (curLine > 0) {
            curLine--;
            *(short*)((char*)_this + 0x100) = curLine;
            ((void(__fastcall*)(void*,int,int,int,int))0x47D060)(_this, 0, 3, 0, param3);
        }
        break;
    case 4: // page up
        if (curLine < scrollTop || curLine > scrollBot) curLine = scrollBot;
        *(short*)((char*)_this + 0x100) = curLine;
        if (curLine < scrollBot) {
            curLine++;
            *(short*)((char*)_this + 0x100) = curLine;
        }
        if (curLine < maxLines - 1) {
            curLine++;
            *(short*)((char*)_this + 0x100) = curLine;
            ((void(__fastcall*)(void*,int,int,int,int))0x47D060)(_this, 0, 3, 0, param3);
        }
        break;
    case 5: // page down
        if (curLine < scrollTop || curLine > scrollBot) curLine = scrollTop;
        *(short*)((char*)_this + 0x100) = curLine;
        if (curLine > scrollTop) {
            curLine--;
            *(short*)((char*)_this + 0x100) = curLine;
        }
        if (curLine > 0) {
            curLine--;
            *(short*)((char*)_this + 0x100) = curLine;
            ((void(__fastcall*)(void*,int,int,int,int))0x47D060)(_this, 0, 2, 0, param3);
        }
        break;
    case 6: // scroll to top
        ((void(__fastcall*)(void*,int,int,int,int))0x47D060)(_this, 0, 6, 0, param3);
        curLine = scrollTop;
        break;
    case 7: // scroll to bottom
        ((void(__fastcall*)(void*,int,int,int,int))0x47D060)(_this, 0, 7, 0, param3);
        curLine = scrollBot;
        break;
    }
    
    *(short*)((char*)_this + 0x100) = curLine;
    
    // Invalidate / redraw
    void* vtable = *(void**)_this;
    ((int(__stdcall*)(int))(*(int*)vtable + 0x20))(1);
    
    // Notify child if cur_line changed
    if (curLine != savedCur) {
        void* child = *(void**)((char*)_this + 0x40);
        if (child && curLine != -1 && curLine < maxLines) {
            void* childVtbl = *(void**)child;
            ((void(__stdcall*)(void*,int,int,int))(*(int*)childVtbl + 0xB4))(_this, 1, curLine, 0);
        }
    }
}

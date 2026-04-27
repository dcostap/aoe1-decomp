// TListPanel::char_action — real pass
// VA: 00478850
long __fastcall char_action_TListPanel(void* _this, int _, long param1, short param2)
{
    // Linked list at [_this+0xF4] with next at [+0xC], string at [+0]
    int ch = ((int(__fastcall*)(int,int))0x54E250)(param1, 0);  // toupper
    void* node = *(void**)((char*)_this + 0xF4);
    int count = 0;
    short numLines = *(short*)((char*)_this + 0x100);
    // First pass: check if count > cur_line (skip lines up to current)
    for (; node; node = *(void**)((char*)node + 0xC)) {
        if (count > numLines) {
            int firstCh = ((int(__fastcall*)(int,int))0x54E250)(*(unsigned char*)(*(int*)node), 0);  // toupper of first byte
            if (firstCh == ch)
                goto found;
        }
        count++;
    }
    // Second pass: search from beginning
    if (numLines <= 0) return 0;
    node = *(void**)((char*)_this + 0xF4);
    count = 0;
    for (; node; ) {
        int firstCh = ((int(__fastcall*)(int,int))0x54E250)(*(unsigned char*)(*(int*)node), 0);
        if (firstCh == ch)
            goto found;
        count++;
        if (count >= numLines) return 0;
        node = *(void**)((char*)node + 0xC);
        if (!node) return 0;
    }
    return 0;
found:
    ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 1, count, 1);
    return 1;
}

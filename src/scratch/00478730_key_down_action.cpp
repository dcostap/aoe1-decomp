// TListPanel::key_down_action — real pass
// VA: 00478730
long __fastcall key_down_action_TListPanel(void* _this, int _, long vk, short param2, int param3, int param4, int param5)
{
    // Jump table dispatch based on vk - 0x0D
    // VK_PRIOR(0x21), VK_NEXT(0x22), VK_END(0x23), VK_HOME(0x24),
    // VK_LEFT(0x25), VK_UP(0x26), VK_RIGHT(0x27), VK_DOWN(0x28)
    if (vk == 0x21) { // VK_PRIOR
        ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 2, 0, 1);
        return 1;
    }
    if (vk == 0x22) { // VK_NEXT
        ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 3, 0, 1);
        return 1;
    }
    if (vk == 0x23) { // VK_END
        ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 4, 0, 1);
        return 1;
    }
    if (vk == 0x24) { // VK_HOME
        ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 5, 0, 1);
        return 1;
    }
    if (vk == 0x25) { // VK_LEFT
        ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 6, 0, 1);
        return 1;
    }
    if (vk == 0x26) { // VK_UP
        void* child = *(void**)((char*)_this + 0x40);
        if (child) {
            short cur = *(short*)((char*)_this + 0x100);
            if (cur != -1 && cur < *(short*)((char*)_this + 0xF8)) {
                void* vtable = *(void**)child;
                ((void(__fastcall*)(void*,int,void*,int,int))0x54C5F4)(child, 0, _this, 3, cur);
            }
        }
        return 1;
    }
    if (vk == 0x28) { // VK_DOWN
        ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 7, 0, 1);
        return 1;
    }
    if (vk == 0x27) { // VK_RIGHT
        return 1;
    }
    return 0;
}

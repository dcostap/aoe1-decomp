// VA: 0041E700 setup_class (152B)
// basegame.cpp: 2205-2236
// int __thiscall RGE_Base_Game::setup_class(void)

#include <windows.h>

#define RGE_BASE_GAME_WND_PROC ((WNDPROC)0x0041E7A0)


int RGE_Base_Game::setup_class() {
    if (prog_info->prev_instance != 0) {
        return 1;
    }

    WNDCLASSA cls;
    cls.hCursor = 0;
    char c = *prog_info->menu_name;
    cls.lpszMenuName = (LPCSTR)0x00592A40;
    if (c) {
        cls.lpszMenuName = prog_info->menu_name;
    }
    cls.hIcon = LoadIconA(prog_info->instance, prog_info->icon_name);
    cls.lpszClassName = (LPCSTR)prog_info;
    cls.hbrBackground = 0;

    cls.hInstance = (HINSTANCE)prog_info->instance;
    cls.style = 0x0B;
    cls.lpfnWndProc = RGE_BASE_GAME_WND_PROC;
    cls.cbWndExtra = 0;
    cls.cbClsExtra = 0;

    return RegisterClassA(&cls) != 0;
}

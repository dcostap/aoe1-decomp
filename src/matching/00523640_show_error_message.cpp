// 00523640 TRIBE_Game::show_error_message
// tribegam.cpp:1206-1211, 96 bytes, __thiscall

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType);

#include "../../include/tribegam_context.h"

void TRIBE_Game::show_error_message(int param_1) {
    char title[256];
    char msg[256];
    this->get_string(0xFA8, title, 256);
    this->get_string2(1, param_1, 0, msg, 256);
    MessageBoxA(this->prog_window, msg, title, 0x10);
}

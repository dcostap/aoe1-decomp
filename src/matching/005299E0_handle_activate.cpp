// VA: 005299E0 TRIBE_Game::handle_activate(void*, unsigned int, unsigned int, long)
// Source: tribegam.cpp lines 5085-5109
// Size: 141 bytes, __thiscall, ret 10h (4 params)
// Returns: int (always 1)
//
// Logic:
// 1. Call RGE_Base_Game::handle_activate(this, p1, p2, p3, p4)
// 2. If (field_1B0 == 1 && video_window != 0):
//    - If param_3 == 1 && video_paused: SendMessage(WM_SYS...=0x855), video_paused=0
//    - Else if param_3 != 1 && !video_paused: SendMessage(WM_SYS...=0x809), video_paused=1
// 3. Return 1

#ifndef TRIBEGAM_TU_CONTEXT
struct RGE_Base_Game {
    int handle_activate(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};

struct TRIBE_Game : RGE_Base_Game {
    char _gap[0x1B0 - sizeof(RGE_Base_Game)];
    int field_1B0;              // +0x1B0
    char _gap_1B4[0xBEC - 0x1B4];
    void* video_window;         // +0xBEC
    char _gap_BF0[8];            // +0xBF0 to +0xBF7
    int video_paused;           // +0xBF8

    int handle_activate(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};
#endif

int TRIBE_Game::handle_activate(void* param_1, unsigned int param_2, unsigned int param_3, long param_4) {
    RGE_Base_Game::handle_activate(param_1, param_2, param_3, param_4);

    if (this->prog_mode == 1 && this->video_window != 0) {
        if (param_3 == 1) {
            if (this->video_paused != 0) {
                SendMessageA(this->video_window, 0x855, 0, 0);
                this->video_paused = 0;
                return 1;
            }
        } else {
            if (this->video_paused == 0) {
                SendMessageA(this->video_window, 0x809, 0, 0);
                this->video_paused = 1;
            }
        }
    }

    return 1;
}

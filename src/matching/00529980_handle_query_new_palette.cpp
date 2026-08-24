// 00529980 TRIBE_Game::handle_query_new_palette
// tribegam.cpp:5066-5079, 91 bytes
// FLAGS: default
//
// Fixed: added RGE_Base_Game as real base class (was standalone TRIBE_Game
// with extern global function declaration for the forward call). Forward
// call changed from global __stdcall function to
// RGE_Base_Game::handle_query_new_palette(...) which generates direct call
// with correct __thiscall param staging (interleaved push/reload pattern).
// Padding recalculated: sizeof(RGE_Base_Game)=0x50, pad to game_mode=0x1B0.
#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Base_Game {
public:
    char gap_00[0x4C];
    virtual int handle_query_new_palette(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char pad_to_1B0[0x1B0 - 0x50];
    int game_mode;
    char pad_1B4[0xA38];
    void* video_window;       // +0xBEC
    char pad_BF0[0x1C];
    int video_hi_color;       // +0xC0C

    int handle_query_new_palette(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};
#endif

int TRIBE_Game::handle_query_new_palette(void* param_1, unsigned int param_2, unsigned int param_3, long param_4) {
    int result;
    int mode;

    result = 1;
    mode = this->prog_mode;
    if (mode == result) {
        if (this->video_window != 0 && this->video_hi_color == 0) {
            SendMessageA(this->video_window, 0x476, 0, 0);
        }
    }
    else {
        result = RGE_Base_Game::handle_query_new_palette(param_1, param_2, param_3, param_4);
    }

    return result;
}

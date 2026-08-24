// compact mission-screen key handler first
// expected basin: reject when no key or wrong key, play voice.wav only when sound is enabled and the screen is idle

#ifdef SCR_VC_CONTEXT_GROUP
#include "../../include/scr_vc_context.h"
#else
class RGE_Prog_Info {
public:
    char pad_00[0x8A8];
    int use_sound;
};

class TSound_Driver {
public:
    int stream_file(char* file_name, int param_2, long param_3);
};

class RGE_Base_Game {
public:
    char pad_00[0x0C];
    RGE_Prog_Info* prog_info;
    char pad_10[0x50];
    TSound_Driver* sound_driver;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Mission_Screen {
public:
    char pad_00[0x494];
    unsigned char game_flag;

    long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
};
#endif

long TRIBE_Mission_Screen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    if (param_4 == 0 || param_1 != 0x56) {
        return 0;
    }
    if (this->game_flag == 0 && rge_base_game->prog_info->use_sound != 0 && rge_base_game->sound_driver != 0) {
        rge_base_game->sound_driver->stream_file((char*)"voice.wav", 0, 0);
    }
    return 1;
}

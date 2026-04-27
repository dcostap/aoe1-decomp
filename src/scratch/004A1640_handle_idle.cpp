// 004A1640 handle_idle
// 130 bytes, __thiscall, TribeMPSetupScreen method
// probe 2: fix logic flow - SendSharedData conditional, return TPanel::handle_idle

class RGE_Base_Game {
public:
    char gap_00[0x1D8];
    unsigned int input_enabled;
};

extern RGE_Base_Game* rge_base_game;
extern void* comm;
extern const char* s_C__msdev_work_age1_x1_scr_mps_cp;

unsigned long debug_timeGetTime(const char* file, int line);
void RGE_Base_Game_enable_input(RGE_Base_Game* game);
int RGE_Base_Game_multiplayerGame(RGE_Base_Game* game);
void TCommunications_Handler_SendSharedData(void* handler, int param);
long TPanel_handle_idle(void* self);

class TribeMPSetupScreen {
public:
    unsigned long last_send_shared;

    long handle_idle();
};

long TribeMPSetupScreen::handle_idle() {
    if (rge_base_game->input_enabled == 0) {
        RGE_Base_Game_enable_input(rge_base_game);
    }
    int mp = RGE_Base_Game_multiplayerGame(rge_base_game);
    if (mp != 0) {
        if (last_send_shared == 0) {
            last_send_shared = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x2FE);
        } else {
            unsigned long t = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x301);
            if (t != last_send_shared) {
                TCommunications_Handler_SendSharedData(comm, 0);
            }
            last_send_shared = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x304);
        }
    }
    return TPanel_handle_idle(this);
}

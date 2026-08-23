// 004A1640 TribeMPSetupScreen::handle_idle
// Working pass: use real member-call surfaces and real object layout. last_send_shared is +0x888,
// debug file must be an array symbol (push immediate address), not `const char*` (load then push).

#ifndef SCR_MPS_TU_CONTEXT

class RGE_Base_Game {
public:
    char gap_00[0x1D8];
    unsigned int input_enabled;

    void enable_input();
    int multiplayerGame();
};

class TCommunications_Handler {
public:
    long SendSharedData(int send_mode);
};

class TPanel {
public:
    long handle_idle();
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern const char s_C__msdev_work_age1_x1_scr_mps_cp[];

unsigned long debug_timeGetTime(const char* file, int line);

class TribeMPSetupScreen : public TPanel {
public:
    char gap_panel[0x888];
    unsigned long last_send_shared;

    long handle_idle();
};

#endif

long TribeMPSetupScreen::handle_idle() {
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    if (rge_base_game->multiplayerGame()) {
        if (last_send_shared == 0) {
            last_send_shared = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x2FE);
        }
        else {
            unsigned long t = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x301);
            if (t - last_send_shared != 0) {
                comm->SendSharedData(0);
                last_send_shared = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x304);
            }
        }
    }
    return TPanel::handle_idle();
}

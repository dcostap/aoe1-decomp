#include "../../include/scr_main_context.h"

#if 0
class RGE_Base_Game {
public:
    char gap_0[0x1D8];
    int input_enabled;
    void enable_input();
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual long handle_idle();
};

class TRIBE_Screen_Main_Menu : public TPanel {
public:
    long handle_idle();
};
#endif

long TRIBE_Screen_Main_Menu::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

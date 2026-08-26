// Attempt log:
// - The standalone owner already matched with input_enabled at +0x1D8.
// - The authentic TU context also exposes draw_area, so its provisional
//   +0x50 member placed this access in the wrong field.
// - Main-agent policy review rejected the grouped raw input view. The local
//   scr_sedm context now keeps draw_area at +0x4C and input_enabled at the
//   executable-proved +0x1D8 offset. This does not prove the full game layout.

#ifndef SCR_SEDM_TU
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

class TRIBE_Screen_Sed_Menu : public TPanel {
public:
    long handle_idle();
};
#endif

long TRIBE_Screen_Sed_Menu::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

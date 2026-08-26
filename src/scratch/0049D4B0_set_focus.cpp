#if !defined(SCR_GAME_TU_CONTEXT)
class TScreenPanel {
public:
    virtual void set_focus(int);
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_04[0x74];
    int have_focus;
    virtual void set_focus(int);
};

class RGE_Base_Game {
public:
    void set_windows_mouse(int);
};

extern RGE_Base_Game* rge_base_game;
#endif

void TRIBE_Screen_Game::set_focus(int value) {
    TScreenPanel::set_focus(value);
    if (this->have_focus != 0) {
        rge_base_game->set_windows_mouse(0);
    } else {
        rge_base_game->set_windows_mouse(1);
    }
}

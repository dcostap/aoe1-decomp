class RGE_Panel_Tool_Box {
public:
    void game_mode_changed(int a, int b);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x4C8];
    int button_panel;
    char gap_4CC[0xB0];
    RGE_Panel_Tool_Box* tool_box;

    void reset_buttons(void);
    void game_mode_changed(int a, int b);
};

void TRIBE_Screen_Game::game_mode_changed(int a, int b) {
    if (this->tool_box != 0) {
        this->tool_box->game_mode_changed(a, b);
    }
    if (this->button_panel != 0) {
        this->reset_buttons();
    }
}

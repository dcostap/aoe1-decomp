// VA: 0048A520 game_mode_changed (195B)
// rpnl_tbx.cpp lines 380-422
// Attempt log:
// - Baseline used named view/button fields but incorrectly merged the move/delete
//   arms into the common terrain/elevation tail (74-byte diff).
// - Restored the source switch's direct-return arms (2-byte diff remained).
// - Corrected constructor-proven button ownership: delete is +0x108 and move is
//   +0x10C; exact match.

#ifndef RPNL_TBX_TU_CONTEXT
class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class TScreenPanel;

class RGE_Player {
public:
    void unselect_object(void);
};

class RGE_Base_Game {
public:
    RGE_Player* get_player(void);
};

extern RGE_Base_Game* rge_base_game;

class RGE_View {
public:
    void set_selection_area(int col1, int row1, int col2, int row2);
};

class TButtonPanel {
public:
    void set_radio_button(void);
};

class RGE_Panel_Tool_Box : public TPanel {
public:
    virtual ~RGE_Panel_Tool_Box();
    TScreenPanel* screen_panel;             // +0xF4
    RGE_View* view;                         // +0xF8
    void* map;                              // +0xFC
    TButtonPanel* game_mode_button;         // +0x100
    TButtonPanel* object_mode_button;       // +0x104
    TButtonPanel* delete_mode_button;       // +0x108
    TButtonPanel* move_mode_button;         // +0x10C
    TButtonPanel* terrain_mode_button;      // +0x110
    TButtonPanel* elevation_mode_button;    // +0x114

    void game_mode_changed(int mode, int new_mode);
};
#endif

void RGE_Panel_Tool_Box::game_mode_changed(int mode, int new_mode) {
    TButtonPanel* button;

    switch (mode) {
    case 1:
    case 0x12:
        rge_base_game->get_player()->unselect_object();
        break;
    case 2:
    case 3:
        this->view->set_selection_area(-1, -1, -1, -1);
        break;
    }

    switch (new_mode) {
    case 1:
        this->object_mode_button->set_radio_button();
        return;
    case 0x12:
        this->move_mode_button->set_radio_button();
        return;
    case 0xE:
        this->delete_mode_button->set_radio_button();
        return;
    case 2:
        button = this->terrain_mode_button;
        break;
    case 3:
        button = this->elevation_mode_button;
        break;
    default:
        this->game_mode_button->set_radio_button();
        return;
    }

    button->set_radio_button();
    rge_base_game->get_player()->unselect_object();
}

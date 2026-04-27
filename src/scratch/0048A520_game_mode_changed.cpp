// VA: 0048A520 game_mode_changed (195B)
// rpnl_tbx.cpp lines 380-422

extern int* rge_base_game;

class RGE_Panel_Tool_Box {
public:
    virtual ~RGE_Panel_Tool_Box();
    char gap0[0xF8];
    void* field_F8;      // +0xF8 (toolbox panel?)
    int field_FC;
    int field_100;       // buttons[0]
    int field_104;       // buttons[1]
    int field_108;       // buttons[2]
    int field_10C;       // buttons[3]
    int field_110;       // buttons[4]
    int field_114;       // buttons[5]
    
    void game_mode_changed(int mode, int subMode);
};

void __cdecl button_hide(void* btn, int, int, int, int);
void __cdecl set_build_mode(void* somePanel);
void __cdecl set_select_mode(void* somePanel);

void RGE_Panel_Tool_Box::game_mode_changed(int mode, int subMode) {
    switch (mode) {
    case 1:  // mode=1: build mode
    case 12: // mode=12: some mode
    {
        // call rge_base_game->get_player()->set_build_mode()
        // which is: (*(void**)rge_base_game)->method() -> get_player -> set_build_mode
        break;
    }
    case 2:  // mode=2: select mode
    {
        // call field_F8->hide(-1,-1,-1,-1)
        button_hide(field_F8, -1, -1, -1, -1);
        break;
    }
    }
    
    switch (subMode) {
    case 1:  // sub=1
        button_hide((void*)field_104, 0, 0, 0, 0);
        break;
    case 2:  // sub=2
        button_hide((void*)field_10C, 0, 0, 0, 0);
        break;
    case 3:  // sub=3
        button_hide((void*)field_108, 0, 0, 0, 0);
        break;
    case 4:  // sub=4
    case 5:  // sub=5
        button_hide((void*)field_110, 0, 0, 0, 0);
        break;
    default:
        button_hide((void*)field_100, 0, 0, 0, 0);
        break;
    }
}

// first pass: cheat-code gate, unselect current player object, view-panel callback, then game dispatch
// if this is sticky, the remaining lead is likely just the exact virtual-slot declarations on the two game callbacks
class RGE_Player;
class TRIBE_Main_View;

class RGE_Base_Game {
public:
    int allowCheatCodes(void);
    RGE_Player* get_player(void);
    char pad_00[0x1B0];
    int game_mode;
    int sub_game_mode;
    int paused;
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int a, int b);
    virtual void vf14(int a);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    char pad_00[0x130];
    void unselect_object(void);
};

class TRIBE_Main_View {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int arg);
};

class TRIBE_Screen_Game {
public:
    char pad_00[0x4B8];
    TRIBE_Main_View* main_view;

    void command_player(int param_1);
};

void TRIBE_Screen_Game::command_player(int param_1) {
    if (!rge_base_game->allowCheatCodes()) {
        return;
    }

    rge_base_game->get_player()->unselect_object();
    this->main_view->vf20(1);

    if (rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1) {
        rge_base_game->vf10(0, 0);
    }

    rge_base_game->vf14(param_1);
}

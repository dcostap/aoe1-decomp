// first pass: direct paused guard, optional unselect, default-to-10 group, then the main-view callback
// if this is sticky, the only likely drift is the exact member-call/vtable shape on the final 0x4B8 dispatch
#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Player;
class TRIBE_Main_View;

class RGE_Base_Game {
public:
    int get_paused(void);
    RGE_Player* get_player(void);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    void unselect_object(void);
    int select_group(int group);
};

class TRIBE_Screen_Game {
public:
    char pad_00[0x4B8];
    TRIBE_Main_View* main_view;

    void command_select_group(int group, int unselect);
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
#endif

void TRIBE_Screen_Game::command_select_group(int group, int unselect) {
    if (rge_base_game->get_paused()) {
        return;
    }
    if (unselect != 0) {
        rge_base_game->get_player()->unselect_object();
    }
    if (group == 0) {
        group = 10;
    }
    rge_base_game->get_player()->select_group(group);
    this->main_view->vf20(1);
}

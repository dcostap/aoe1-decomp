class RGE_Base_Game {
public:
    int get_paused(void);
    void* get_player(void);
};

class RGE_Player {
public:
    void ungroup_objects(void);
};

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void redraw(int value);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    TPanel* main_view;

    void command_ungroup(void);
};

void TRIBE_Screen_Game::command_ungroup(void) {
    if (rge_base_game->get_paused() == 0) {
        ((RGE_Player*)rge_base_game->get_player())->ungroup_objects();
        this->main_view->redraw(1);
    }
}

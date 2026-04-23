class TPanel;
class TButtonPanel;

class RGE_Player {
public:
    void unselect_object(void);
    void unselect_area(void);
};

class RGE_Base_Game {
public:
    int get_paused(void);
    RGE_Player* get_player(void);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Diamond_Map_View {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void set_redraw(int mode);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    RGE_Diamond_Map_View* main_view;

    void command_unselect(void);
};

void TRIBE_Screen_Game::command_unselect(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->get_player()->unselect_object();
        rge_base_game->get_player()->unselect_area();
        this->main_view->set_redraw(1);
    }
}

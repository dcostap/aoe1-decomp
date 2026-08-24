#if !defined(SCR_GAME_TU_CONTEXT)
class TMessagePanel {
public:
    void show_message(int type, char* text, unsigned char a3, unsigned char a4, void* user, int x, int y);
};

class TPanel {
public:
    char* get_string(int string_id);
};

class TScreenPanel : public TPanel {
};

class RGE_Base_Game {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void set_font(int font_id, int param_2);

    int get_paused(void);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_00[0x544];
    TMessagePanel* message_panel;

    void command_repair(void);
};
#endif

void TRIBE_Screen_Game::command_repair(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }
    this->message_panel->show_message(1, this->get_string(0xBEC), 0x32, 0, 0, 0, 0);
    rge_base_game->set_font(0x68, 0);
}

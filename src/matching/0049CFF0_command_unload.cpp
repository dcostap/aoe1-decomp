class RGE_Base_Game {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int cmd, int arg);

    int get_paused(void);
};

class TPanel {
public:
    char* get_string(int string_id, int len, int a3, int a4, int a5, int a6);
};

class TMessagePanel {
public:
    void show_message(int type, char* text);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game : public TPanel {
public:
    char gap_00[0x544];
    TMessagePanel* message_panel;

    void command_unload(void);
};

void TRIBE_Screen_Game::command_unload(void) {
    if (!rge_base_game->get_paused()) {
        this->message_panel->show_message(1, this->get_string(0xBED, 0x32, 0, 0, 0, 0));
        rge_base_game->vf10(0x69, 0);
    }
}

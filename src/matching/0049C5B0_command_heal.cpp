// tried the direct pause check, then the message text / panel call, then the trailing base-game virtual
// remaining mismatch would be in the exact wrapper-vs-virtual call basin, not the visible control flow

#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    int get_paused();
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int, int);
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    char* get_string(int string_id);
};

class TMessagePanel {
public:
    void show_message(int type, char* text, unsigned char a3, unsigned char a4, void* user, int x, int y);
};

class TRIBE_Screen_Game : public TPanel {
public:
    char gap_000[0x544];
    TMessagePanel* message_panel;

    void command_heal(void);
};
#endif

void TRIBE_Screen_Game::command_heal(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }

    this->message_panel->show_message(1, this->get_string(0xBE3), 0x32, 0, 0, 0, 0);
    rge_base_game->vf10(0x66, 0);
}

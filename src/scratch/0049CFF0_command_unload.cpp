// tried direct wrapper-style calls first; mismatch stayed in call-shape/register loading
// current probe still matches the high-level branch but the get_string/global load basin is wrong

class RGE_Base_Game;
class TPanel;
class TMessagePanel;

extern RGE_Base_Game* rge_base_game;

typedef void (*RGE_Base_Game_Vfunc4)(RGE_Base_Game*, int, int);

class RGE_Base_Game_Vtbl {
public:
    void* vfunc0;
    void* vfunc1;
    void* vfunc2;
    void* vfunc3;
    RGE_Base_Game_Vfunc4 vfunc4;
};

class RGE_Base_Game {
public:
    RGE_Base_Game_Vtbl* vtable;

    int get_paused(void);
};

class TPanel {
public:
    char* get_string(int string_id);
};

class TMessagePanel {
public:
    void show_message(int type, char* text);
};

class TRIBE_Screen_Game : public TPanel {
public:
    char gap_00[0x544];
    TMessagePanel* message_panel;

    void command_unload(void);
};

void TRIBE_Screen_Game::command_unload(void) {
    if (!rge_base_game->get_paused()) {
        this->message_panel->show_message(1, this->get_string(0xBED));
        rge_base_game->vtable->vfunc4(rge_base_game, 0x69, 0);
    }
}

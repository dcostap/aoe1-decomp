// VA: 0049C890 TRIBE_Screen_Game::command_move

void __cdecl free(void* ptr);

class RGE_Player {
public:
    unsigned char get_selected_objects_to_command();
};

class RGE_Base_Game {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void set_game_action(int action, int value);

    int get_paused();
    RGE_Player* get_player(void*** list, short* list_num, int a, int b, int c, int d);
};

class TMessagePanel {
public:
    void show_message(int type, char* msg);
};

class TRIBE_Screen_Game {
public:
    char gap_000[0x544];
    TMessagePanel* message_panel;

    char* get_string(int id, int a, int b, int c, int d, int e);
    void command_move();
};

extern RGE_Base_Game* rge_base_game;

void TRIBE_Screen_Game::command_move() {
    void** list;
    short list_num;

    if (rge_base_game->get_paused() == 0) {
        RGE_Player* player = rge_base_game->get_player(&list, &list_num, -1, -1, -1, -1);
        if (player->get_selected_objects_to_command()) {
            free(list);
            char* msg = this->get_string(0xBE0, 0x32, 0, 0, 0, 0);
            this->message_panel->show_message(1, msg);
            rge_base_game->set_game_action(4, 0);
        }
    }
}

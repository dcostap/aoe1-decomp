// 0049C890 command_move
// 130 bytes, __thiscall, TRIBE_Screen_Game method
// probe 2: get selected objects, show message, set move mode

class RGE_Base_Game;
class RGE_Player;
class TMessagePanel;

extern RGE_Base_Game* rge_base_game;
void __cdecl free(void* p);
int RGE_Base_Game_get_paused(RGE_Base_Game* game);
RGE_Player* RGE_Base_Game_get_player(RGE_Base_Game* game);
unsigned char RGE_Player_get_selected_objects_to_command(
    RGE_Player* player, void*** list, short* list_num, short a, short b, short c, short d);
const char* TPanel_get_string(void* self, int id);
void TMessagePanel_show_message(TMessagePanel* self, const char* msg, char a, char b, void* c, int d, int e);
void RGE_Base_Game_set_mode(RGE_Base_Game* game, int mode);
void RGE_Base_Game_set_list(RGE_Base_Game* game, void* list, short num);

class TRIBE_Screen_Game {
public:
    TMessagePanel* message_panel;

    void command_move();
};

void TRIBE_Screen_Game::command_move() {
    int paused = RGE_Base_Game_get_paused(rge_base_game);
    if (paused == 0) {
        void** list = 0;
        short list_num = -1;
        RGE_Player* player = RGE_Base_Game_get_player(rge_base_game);
        unsigned char count = RGE_Player_get_selected_objects_to_command(
            player, &list, &list_num, -1, -1, -1, -1);
        if (count == 0) {
            free(list);
            const char* msg = TPanel_get_string(this, 0xBE0);
            TMessagePanel_show_message(message_panel, msg, '2', 0, 0, 0, 0);
        } else {
            RGE_Base_Game_set_mode(rge_base_game, 2);
            RGE_Base_Game_set_list(rge_base_game, list, list_num);
        }
    }
}

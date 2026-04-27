// VA: 0049D100 command_view_tribe (165B)
// scr_game.cpp

extern int g_game_info;

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void command_view_tribe();
};

int get_paused(void*);
int g_game_info = 0;

void TRIBE_Screen_Game::command_view_tribe() {
    if (get_paused((void*)&g_game_info)) {
        return;
    }
    field_8 = 1;
}

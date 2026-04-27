// VA: 0049C0B0 command_comm_info (165B)
// scr_game.cpp

extern int* g_game_info_ptr;

class TRIBE_Screen_Game {
public:
    char gap4[0x584];
    int field_588;
    char gap58C[0x4];
    int field_590;
    
    void command_comm_info();
};

int* g_game_info_ptr = (int*)0x62C574;

void TRIBE_Screen_Game::command_comm_info() {
    int* info = g_game_info_ptr;
    if (info) {
        field_588 = 0;
        field_590 = (int)info;
    }
}

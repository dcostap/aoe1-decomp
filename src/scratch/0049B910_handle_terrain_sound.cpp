// VA: 0049B910 handle_terrain_sound (468B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void handle_terrain_sound();
};

int __cdecl color_log(int a1, int a2, int a3);

void TRIBE_Screen_Game::handle_terrain_sound() {
    color_log(4, 0x16, 0x54);
    field_8 = 1;
}

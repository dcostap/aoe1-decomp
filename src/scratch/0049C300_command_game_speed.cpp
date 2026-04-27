// VA: 0049C300 command_game_speed (571B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void command_game_speed();
};

int __cdecl sub_004231E0(int a1, int a2);

void TRIBE_Screen_Game::command_game_speed() {
    sub_004231E0(0x13FE, (int)"string_at_58637C");
    field_8 = 1;
}

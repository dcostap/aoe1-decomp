// VA: 0049AB60 set_button (475B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4C4];
    int field_4C8;
    
    void set_button(short idx, int value);
};

void TRIBE_Screen_Game::set_button(short idx, int value) {
    int* item = (int*)((char*)this + (signed short)idx * 4 + 0x4C8);
    if (item) {
        *item = value;
    }
}

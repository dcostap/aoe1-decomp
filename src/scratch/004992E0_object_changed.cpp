// VA: 004992E0 object_changed (199B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x5C4];
    int field_5C8;
    char gap5CC[0x4];
    int field_5D0;
    
    void object_changed();
};

void TRIBE_Screen_Game::object_changed() {
    field_5C8 = 1;
    field_5D0 = 0;
}

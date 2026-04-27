// VA: 004959B0 set_overlapped_redraw (217B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void set_overlapped_redraw();
};

int __cdecl sub_00463D40(void* obj);

void TRIBE_Screen_Game::set_overlapped_redraw() {
    sub_00463D40((void*)0x62E870);
    field_8 = 1;
}

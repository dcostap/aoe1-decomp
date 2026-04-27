// VA: 004970A0 wnd_proc (354B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    int wnd_proc(int msg, int wParam, int lParam);
};

int TRIBE_Screen_Game::wnd_proc(int msg, int wParam, int lParam) {
    if (msg == 0x104) {
        if (wParam == 0x79) {
            return 0;
        }
    }
    return field_8;
}

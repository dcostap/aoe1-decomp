// VA: 0049D610 TRIBE_Screen_Info::handle_idle
// scr_info.cpp lines 65-85

// attempt 1: natural C++ 

extern unsigned long debug_timeGetTime(const char* file, int line);

class RGE_Base_Game {
public:
    void enable_input();
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual ~TPanel();
    int handle_idle();
    char gap_04[0x474];
};

class TRIBE_Screen_Info : public TPanel {
public:
    int auto_close;     // +0x478
    int timer;          // +0x47C
    int last_time;      // +0x480

    void close_screen();
    int handle_idle();
};

int TRIBE_Screen_Info::handle_idle() {
    if (*(int*)((char*)rge_base_game + 0x1D8) == 0) {
        rge_base_game->enable_input();
    }
    if (auto_close != 0) {
        if (last_time == 0) {
            last_time = debug_timeGetTime("scr_info.cpp", 0x48);
            return TPanel::handle_idle();
        }
        unsigned long now = debug_timeGetTime("scr_info.cpp", 0x4B);
        unsigned int elapsed = now - last_time;
        if (elapsed > timer) {
            close_screen();
            return 0;
        }
    }
    return TPanel::handle_idle();
}

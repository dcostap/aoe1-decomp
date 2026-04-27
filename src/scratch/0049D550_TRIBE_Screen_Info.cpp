// VA: 0049D550 TRIBE_Screen_Info::TRIBE_Screen_Info
// scr_info.cpp lines 32-52

// attempt 1-2: natural constructor with /GX for EH
// 142/142 bytes exact size match, 70 diff bytes
// Remaining: auto_close computation pattern (cmp/sbb/neg) not matching,
// instruction ordering differs.
// Left in scratch.

class TPanel {
public:
    virtual ~TPanel();
    int handle_idle();
    char gap_04[0x474];
};

class TScreenPanel : public TPanel {
public:
    virtual ~TScreenPanel();
    TScreenPanel(int param);
    int setup(void* draw_area, char* param2, void* param3, int zero);
};

class RGE_Base_Game {
public:
    void* draw_area;  // +0x4C
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Info : public TScreenPanel {
public:
    int auto_close;           // +0x478
    unsigned int timer;       // +0x47C
    unsigned int last_time;   // +0x480

    void close_screen();
    TRIBE_Screen_Info(char* name, char* param2, long param3, unsigned long timer_val);
};

TRIBE_Screen_Info::TRIBE_Screen_Info(char* name, char* param2, long param3, unsigned long timer_val)
    : TScreenPanel((int)name) {
    this->timer = timer_val;
    this->auto_close = (0 < timer_val);
    this->last_time = 0;
    int result = TScreenPanel::setup(rge_base_game->draw_area, param2, (void*)param3, 0);
    if (result == 0) {
        *(int*)((char*)this + 0xD8) = 1;
    }
}

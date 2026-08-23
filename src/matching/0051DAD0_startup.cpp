// VA: 0051DAD0 startup (46B), owned by TRIBE_Panel_Time.
// BINARY NOTE: Authentic tpnl_tim.cpp order is lines 144, 146, and 147.
// The shipped code stores world at +0x114 before the time call, then stores
// its result at +0x11C. The direct call and its source path/line are required.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    void* world;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Panel_Time {
public:
    char gap_00[0x114];
    void* world;
    int gap_118;
    unsigned long start_real_time;

    void startup(void);
};

void TRIBE_Panel_Time::startup(void) {
    this->world = rge_base_game->world;
    this->start_real_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_tim.cpp", 0x92);
}

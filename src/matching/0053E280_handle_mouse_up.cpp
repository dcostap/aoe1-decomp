// first pass: direct timing wrapper around the base mouse-up handler and the add-to-timing call
// if this is sticky, the remaining lead is likely just the literal/string timing helper shape rather than the control flow
class RGE_Player;
class RGE_Base_Game;

extern RGE_Base_Game* rge_base_game;
extern unsigned long __cdecl debug_timeGetTime(char* param_1, int param_2);

class TPanel {
public:
    virtual long handle_mouse_up(unsigned char p1, long p2, long p3, int p4, int p5);
};

class RGE_View : public TPanel {
public:
    long handle_mouse_up(unsigned char p1, long p2, long p3, int p4, int p5);
};

class RGE_Main_View : public RGE_View {
public:
    char pad_00[0x380 - 0x0];
    long handle_mouse_up(unsigned char p1, long p2, long p3, int p4, int p5);
};

class RGE_Base_Game {
public:
    void add_to_timing(int index, unsigned long value);
};

long RGE_Main_View::handle_mouse_up(unsigned char p1, long p2, long p3, int p4, int p5) {
    unsigned long start;
    long result;
    unsigned long stop;

    start = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0x1AE);
    result = RGE_View::handle_mouse_up(p1, p2, p3, p4, p5);
    stop = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0x1B0);
    rge_base_game->add_to_timing(0x0D, stop - start);
    return result;
}

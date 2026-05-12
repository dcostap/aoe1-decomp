// VA: 0053A0D0 RGE_View::start_scroll_view
// view.cpp lines 5854-5914
// Attempt log:
// 1: natural reconstruction: too short 400 B because pick locals collapsed into parameter home area and no 0x14 frame.
// 2: explicit PickInfo still optimized into parameter home area; no frame.
// 3: volatile PickInfo forced 0x14 frame but prologue loads action into AL before pushes and code is 416 B.
// 4: action local/register did not change early AL compare.
// 5: switch(action) for 3/9 dispatch did not change 416 B/no compare.
// 6: volatile action local grew to 432 B but worsened prologue/order; rolled back.
// 7: signed char parameter/local probe: no improvement.
// 8: int action parameter with byte casts: no improvement; restored unsigned char and if/else as best natural source.
// 9: flags /O2 no-/Oy, /Ox unchanged; /O1 too short; /Og- broad mismatch.
// 10: tested alternate set_view_loc coordinate source; original appears to use same pick_info.scr_x slot twice.

class RGE_Player {
public:
    void unselect_object();
    void set_view_loc(float x, float y);
};

class RGE_Base_Game {
public:
    void mouse_off();
};
extern RGE_Base_Game* rge_base_game;
extern float flt_5776C0;

class TPanel_Base {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void set_redraw(int mode); // +0x20
};

struct PickInfo {
    float y;
    float scr_x;
    long a;
    long b;
    long c;
};

class RGE_View : public TPanel_Base {
public:
    char gap_04[0xFC];
    RGE_Player* player; // +0x100
    char gap_104[0x64];
    unsigned char scroll_action; // +0x168
    char gap_169[3];
    long mouse_last_x; // +0x16C
    long mouse_last_y; // +0x170
    char gap_174[0x180];
    long real_old_map_col; // +0x2F4
    long real_old_map_row; // +0x2F8

#define VPAD(n) virtual void d##n();
    VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15) VPAD(16)
    VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23) VPAD(24)
    VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29) VPAD(30) VPAD(31) VPAD(32)
    VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39) VPAD(40)
    VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47) VPAD(48)
    VPAD(49) VPAD(50) VPAD(51) VPAD(52) VPAD(53) VPAD(54) VPAD(55) VPAD(56)
    VPAD(57) VPAD(58) VPAD(59)
#undef VPAD
    virtual void end_scroll_view(); // +0xF0
    virtual int do_paint(long x1, long y1, long x2, long y2, int flag); // +0xF4

    unsigned char pick(unsigned char key, unsigned char p2, long x, long y, void* info, void* obj);
    void set_selection_area(long x1, long y1, long x2, long y2);
    int capture_mouse();
    int start_scroll_view(unsigned char action, long x, long y, int p4, int p5);
};

int RGE_View::start_scroll_view(unsigned char action, long x, long y, int p4, int p5)
{
    volatile PickInfo pick_info;
    int retval;
    register unsigned char act = action;

    if (act == 3) {
        if (this->pick(0x28, 0, x, y, (void*)&pick_info, 0) != 0x33) {
            return 0;
        }
        int iy = (int)pick_info.scr_x;
        int ix = (int)pick_info.y;
        this->set_selection_area(ix, iy, ix, iy);
    } else if (act == 9) {
        this->pick(0x28, 0, x, y, (void*)&pick_info, 0);
        this->real_old_map_col = (int)pick_info.y;
        this->real_old_map_row = (int)pick_info.scr_x;
        if (!this->do_paint(x, y, x, y, 1)) {
            return 0;
        }
        this->set_redraw(1);
    }

    retval = 0;
    this->scroll_action = act;
    this->mouse_last_x = x;
    *(long*)((char*)this + 0xC4) = x;
    this->mouse_last_y = y;
    *(long*)((char*)this + 0xC8) = y;
    this->capture_mouse();

    if (this->scroll_action == 1 || this->scroll_action == 2 || this->scroll_action == 6 ||
        this->scroll_action == 7 || this->scroll_action == 8) {
        rge_base_game->mouse_off();
    }

    if (this->scroll_action == 2) {
        if (p5 == 0 && p4 == 0) {
            this->player->unselect_object();
        }
        this->set_redraw(1);
    }

    if (this->scroll_action == 6 || this->scroll_action == 8) {
        if (this->pick(0x28, 0, x, y, (void*)&pick_info, 0) == 0x33) {
            this->player->set_view_loc(pick_info.scr_x - flt_5776C0, pick_info.scr_x - flt_5776C0);
            this->set_redraw(1);
            return 1;
        }
    }

    return retval;
}

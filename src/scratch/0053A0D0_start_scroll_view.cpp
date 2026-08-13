// VA: 0053A0D0 RGE_View::start_scroll_view
// PDB: view.cpp:5854-5914
// Fresh reconstruction: the pick result is the period RGE_Pick_Info object;
// the view owns the mouse-down and scroll fields at their proven offsets.
// Prior worker notes remain useful evidence: the former volatile stub forced
// the right frame but did not reproduce the source-level register schedule.
//
// Attempt log (normal-53A0D0-r1):
// 1: natural typed Pick_Info and named view fields: 397 B, 16 calls, 4 fewer returns.
// 2: delayed result initialization: codegen duplicate.
// 3: reused the action parameter as the zero result: codegen duplicate.
// 4: volatile result restored four returns and reached 421 B; retained as diagnostic.
// 5: declaration-order change: codegen duplicate.
// 6: saved action local: codegen duplicate.
// 7: volatile action local: 425 B and worse block coverage; rolled back.
// 8: register-qualified action local: codegen duplicate; rolled back.
// 9: reused result for the first converted coordinate: 441 B, 335 strict diff.
// 10: reversed conversion order: 437 B, 338 strict diff; exact-codegen stage.
// Final: restored the clean natural source. Remaining lead is result-home and
// action-register scheduling. Diagnostic volatile forms are not retained.
// 11: use one saved action value for dispatch and scroll state; codegen was
// unchanged at 397 B / 418 strict-diff bytes, so the natural baseline remains.
// 12: direct final return instead of a synthetic result local; codegen was
// unchanged at 397 B / 418 strict-diff bytes, so the baseline was restored.

struct RGE_Static_Object;
struct RGE_Tile;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

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

class RGE_View {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void set_redraw(int mode);

    char gap_04[0xC0];
    long mouse_down_x;
    long mouse_down_y;
    char gap_CC[0x34];
    RGE_Player* player;
    char gap_104[0x64];
    unsigned char scroll_action;
    char gap_169[3];
    long mouse_last_x;
    long mouse_last_y;
    char gap_174[0x180];
    long real_old_map_col;
    long real_old_map_row;

#define RGE_VIEW_DUMMY(n) virtual void d##n();
    RGE_VIEW_DUMMY(9) RGE_VIEW_DUMMY(10) RGE_VIEW_DUMMY(11) RGE_VIEW_DUMMY(12)
    RGE_VIEW_DUMMY(13) RGE_VIEW_DUMMY(14) RGE_VIEW_DUMMY(15) RGE_VIEW_DUMMY(16)
    RGE_VIEW_DUMMY(17) RGE_VIEW_DUMMY(18) RGE_VIEW_DUMMY(19) RGE_VIEW_DUMMY(20)
    RGE_VIEW_DUMMY(21) RGE_VIEW_DUMMY(22) RGE_VIEW_DUMMY(23) RGE_VIEW_DUMMY(24)
    RGE_VIEW_DUMMY(25) RGE_VIEW_DUMMY(26) RGE_VIEW_DUMMY(27) RGE_VIEW_DUMMY(28)
    RGE_VIEW_DUMMY(29) RGE_VIEW_DUMMY(30) RGE_VIEW_DUMMY(31) RGE_VIEW_DUMMY(32)
    RGE_VIEW_DUMMY(33) RGE_VIEW_DUMMY(34) RGE_VIEW_DUMMY(35) RGE_VIEW_DUMMY(36)
    RGE_VIEW_DUMMY(37) RGE_VIEW_DUMMY(38) RGE_VIEW_DUMMY(39) RGE_VIEW_DUMMY(40)
    RGE_VIEW_DUMMY(41) RGE_VIEW_DUMMY(42) RGE_VIEW_DUMMY(43) RGE_VIEW_DUMMY(44)
    RGE_VIEW_DUMMY(45) RGE_VIEW_DUMMY(46) RGE_VIEW_DUMMY(47) RGE_VIEW_DUMMY(48)
    RGE_VIEW_DUMMY(49) RGE_VIEW_DUMMY(50) RGE_VIEW_DUMMY(51) RGE_VIEW_DUMMY(52)
    RGE_VIEW_DUMMY(53) RGE_VIEW_DUMMY(54) RGE_VIEW_DUMMY(55) RGE_VIEW_DUMMY(56)
    RGE_VIEW_DUMMY(57) RGE_VIEW_DUMMY(58) RGE_VIEW_DUMMY(59)
#undef RGE_VIEW_DUMMY
    virtual void end_scroll_view();
    virtual int do_paint(long x1, long y1, long x2, long y2, int flag);

    unsigned char pick(unsigned char key, unsigned char p2, long x, long y,
                       RGE_Pick_Info* info, RGE_Static_Object* obj);
    void set_selection_area(long x1, long y1, long x2, long y2);
    int capture_mouse();

    int start_scroll_view(unsigned char action, long x, long y, int p4, int p5);
};

int RGE_View::start_scroll_view(unsigned char action, long x, long y,
                                int p4, int p5)
{
    RGE_Pick_Info pick_info;
    int result = 0;

    if (action == 3) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) != 0x33) {
            return 0;
        }
        long col = (long)pick_info.y;
        long row = (long)pick_info.x;
        this->set_selection_area(row, col, row, col);
    } else if (action == 9) {
        this->pick(0x28, 0, x, y, &pick_info, 0);
        this->real_old_map_col = (long)pick_info.x;
        this->real_old_map_row = (long)pick_info.y;
        if (!this->do_paint(x, y, x, y, 1)) {
            return 0;
        }
        this->set_redraw(1);
    }

    this->scroll_action = action;
    this->mouse_last_x = x;
    this->mouse_down_x = x;
    this->mouse_last_y = y;
    this->mouse_down_y = y;
    this->capture_mouse();

    if (this->scroll_action == 1 || this->scroll_action == 2 ||
        this->scroll_action == 6 || this->scroll_action == 7 ||
        this->scroll_action == 8) {
        rge_base_game->mouse_off();
    }

    if (this->scroll_action == 2) {
        if (p5 == 0 && p4 == 0) {
            this->player->unselect_object();
        }
        this->set_redraw(1);
    }

    if (this->scroll_action == 6 || this->scroll_action == 8) {
        if (this->pick(0x28, 0, x, y, &pick_info, 0) == 0x33) {
            this->player->set_view_loc(pick_info.y - flt_5776C0,
                                       pick_info.y - flt_5776C0);
            this->set_redraw(1);
            return 1;
        }
    }

    return result;
}

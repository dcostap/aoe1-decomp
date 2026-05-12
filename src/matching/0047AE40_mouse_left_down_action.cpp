// VA: 0047AE40 TScrollBarPanel::mouse_left_down_action
// PDB: Pnl_scbr.cpp lines 346-394
// Size: 391 bytes, __thiscall, ret 10h
// Attempt log:
// Probe 1: compile error
// Probe 2: virtual call via cast -> wrong register allocation
// Probe 3: proper virtual function declaration

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    int capture_mouse(void);
    int is_inside_rect(long x, long y, tagRECT* rect);
    void set_curr_child(TPanel* child);
    virtual void dummy_v1(void);
    virtual void dummy_v2(void);
    virtual void dummy_v3(void);
    virtual void dummy_v4(void);
    virtual void dummy_v5(void);
    virtual void dummy_v6(void);
    virtual void dummy_v7(void);
    virtual void after_mouse_down(int action);

    char gap_04[0x40 - 0x04];
    TPanel* parent_panel;     // +0x40
    char gap_44[0x74 - 0x44];
    int tab_stop;             // +0x74
    char gap_78[0xF4 - 0x78];
    TPanel* list_panel;       // +0xF4
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
    long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    void scroll(int action, int param);

    char gap_F8[0x124 - 0xF8];
    long tab_y;
    long tab_min_y;
    long tab_max_y;
    long tab_mouse_y;
    long tab_x;
    long tab_min_x;
    long tab_max_x;
    long tab_mouse_x;
    unsigned char item_down;
    char gap_145[3];
    long item_is_down;
    long item_x;
    long item_y;
    unsigned char item_mode;
    char gap_155[3];
    long item_last_time;
    char gap_15C[8];
    tagRECT up_rect;
    tagRECT down_rect;
    tagRECT tab_rect;
    tagRECT top_rect;
    tagRECT bottom_rect;
    long orientationValue;
};

long TScrollBarPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4)
{
    TPanel* p;

    this->capture_mouse();

    if (this->is_inside_rect(param_1, param_2, &this->up_rect)) {
        this->item_down = 1;
        this->item_is_down = 1;
        this->scroll(0, 0);
    } else if (this->is_inside_rect(param_1, param_2, &this->down_rect)) {
        this->item_down = 2;
        this->item_is_down = 1;
        this->scroll(1, 0);
    } else if (this->is_inside_rect(param_1, param_2, &this->tab_rect)) {
        this->item_down = 3;
        if (this->orientationValue == 1) {
            this->tab_mouse_x = param_1 - this->tab_x;
        } else {
            this->tab_mouse_y = param_2 - this->tab_y;
        }
    } else if (this->is_inside_rect(param_1, param_2, &this->top_rect)) {
        this->item_down = 4;
        this->item_is_down = 1;
        this->scroll(2, 0);
    } else if (this->is_inside_rect(param_1, param_2, &this->bottom_rect)) {
        this->item_down = 5;
        this->item_is_down = 1;
        this->scroll(3, 0);
    } else {
        this->item_down = 0;
    }

    if (this->item_down) {
        p = this->list_panel;
        if (p && p->tab_stop && p->parent_panel) {
            p->parent_panel->set_curr_child(p);
        }
        this->item_x = param_1;
        this->item_y = param_2;
        this->item_mode = 1;
        this->item_last_time = debug_timeGetTime("Pnl_scbr.cpp", 0x185);
        this->after_mouse_down(1);
    }

    return 0;
}

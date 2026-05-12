// VA: 0047B4E0 TScrollBarPanel::draw
// Source: Pnl_scbr.cpp lines 649-689
// Attempt log:
// 1: natural reconstruction from packet; use real helper calls and direct field offsets: first mismatch at rect check order/boolean temp shape.
// 2: check top/bottom before left/right and pass pressed predicate directly to avoid byte temp.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[4];
    unsigned char* Lock(char* name, int waitFlag);
    void Unlock(char* name);
};

class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void enterCS(int unk); // +28
    virtual void leaveCS();        // +2C
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void draw_rect(tagRECT* rect); // +3C
};

class TScrollBarPanel : public TPanel {
public:
    char gap_04[0x0C - 0x04];
    long field_0C;
    long field_10;
    long field_14;
    long field_18;
    char gap_1C[0x20 - 0x1C];
    TDrawArea* draw_area;      // +20
    tagRECT rect_24;           // +24
    char gap_34[0x40 - 0x34];
    TPanel* panel;             // +40
    char gap_44[0x8C - 0x44];
    tagRECT rect_8C;           // +8C
    char gap_9C[0x108 - 0x9C];
    void* button_pics;         // +108
    int back_frame;            // +10C
    int up_frame;              // +110
    int down_frame;            // +114
    int tab_frame;             // +118
    char gap_11C[0x144 - 0x11C];
    unsigned char pressed_part; // +144
    char gap_145[3];
    int active;                // +148
    char gap_14C[0x164 - 0x14C];
    tagRECT up_rect;           // +164
    tagRECT down_rect;         // +174
    tagRECT tab_rect;          // +184

    virtual void draw();
    void draw_back_pic();
    void draw_border(int x, int y, tagRECT* rect);
    void draw_button_pic(int frame, int pressed, tagRECT* rect);
};

void TScrollBarPanel::draw()
{
    if (this->panel != 0) {
        this->panel->draw_rect(&this->rect_24);
    }

    this->enterCS(0);

    if (this->draw_area->Lock("pnl_scbr::draw", 1)) {
        this->draw_back_pic();
        this->draw_border(0, 1, &this->rect_8C);

        if (this->up_rect.top != this->up_rect.bottom && this->up_rect.left != this->up_rect.right) {
            this->draw_button_pic(this->up_frame, this->pressed_part == 1 && this->active, &this->up_rect);
            this->draw_border(1, this->pressed_part == 1 && this->active, &this->up_rect);
        }

        if (this->down_rect.top != this->down_rect.bottom && this->down_rect.left != this->down_rect.right) {
            this->draw_button_pic(this->down_frame, this->pressed_part == 2 && this->active, &this->down_rect);
            this->draw_border(1, this->pressed_part == 2 && this->active, &this->down_rect);
        }

        this->draw_button_pic(this->tab_frame, 0, &this->tab_rect);
        this->draw_border(1, 0, &this->tab_rect);

        this->draw_area->Unlock("pnl_scbr::draw");
    }

    this->leaveCS();
}

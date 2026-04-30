// 00464E00 TPanel::set_positioning
// Panel.cpp:1158-1183, 166 bytes, __thiscall, ret 34h

class TDrawArea {
public:
    char gap_00[0x18];
    int Width;      // +0x18
    int Height;     // +0x1C
};

class TPanel {
public:
    char gap_04[0x08];
    int pnl_x;                     // +0x0C
    int pnl_y;                     // +0x10
    int pnl_wid;                   // +0x14
    int pnl_hgt;                   // +0x18
    char gap_1C[0x04];
    TDrawArea* render_area;        // +0x20
    int clip_left;                 // +0x24
    int clip_top;                  // +0x28
    int clip_right;                // +0x2C
    int clip_bottom;               // +0x30
    int position_mode;             // +0x34
    char gap_38[0x08];
    TPanel* parent_panel;          // +0x40
    TPanel* left_panel;            // +0x44
    TPanel* top_panel;             // +0x48
    TPanel* right_panel;           // +0x4C
    TPanel* bottom_panel;          // +0x50
    char gap_54[0x18];
    int active;                    // +0x6C
    int visible;                   // +0x70
    char gap_74[0x14];
    void* clip_rgn;                // +0x88
    int render_left;               // +0x8C
    int render_top;                // +0x90
    int render_right;              // +0x94
    int render_bottom;             // +0x98
    int left_border;               // +0x9C
    int top_border;                // +0xA0
    int right_border;              // +0xA4
    int bottom_border;             // +0xA8
    int min_wid;                   // +0xAC
    int max_wid;                   // +0xB0
    int min_hgt;                   // +0xB4
    int max_hgt;                   // +0xB8
    char gap_BC[0x35];
    char clip_to_parent;           // +0xF1

    // vt[0..7] padding
    virtual void pad00() = 0;
    virtual void pad01() = 0;
    virtual void pad02() = 0;
    virtual void pad03() = 0;
    virtual void pad04() = 0;
    virtual void pad05() = 0;
    virtual void pad06() = 0;
    virtual void pad07() = 0;
    // vt[8] = +0x20
    virtual void redraw(int flags) = 0;
    // vt[9..19] padding (11 functions for slots 9-19)
    virtual void pad09() = 0;
    virtual void pad10() = 0;
    virtual void pad11() = 0;
    virtual void pad12() = 0;
    virtual void pad13() = 0;
    virtual void pad14() = 0;
    virtual void pad15() = 0;
    virtual void pad16() = 0;
    virtual void pad17() = 0;
    virtual void pad18() = 0;
    virtual void pad19() = 0;
    // vt[20] = +0x50
    virtual void positioning_callback(int w, int h) = 0;
    
    void set_positioning(int p1, int p2, int p3, int p4,
                         int p5, int p6, int p7, int p8,
                         int p9, TPanel* p10, TPanel* p11,
                         TPanel* p12, TPanel* p13);
};

void TPanel::set_positioning(int p1, int p2, int p3, int p4,
                             int p5, int p6, int p7, int p8,
                             int p9, TPanel* p10, TPanel* p11,
                             TPanel* p12, TPanel* p13)
{
    position_mode = p1;
    right_border = p4;
    max_wid = p7;
    left_border = p2;
    top_border = p3;
    left_panel = p10;
    bottom_border = p5;
    min_wid = p6;
    bottom_panel = p13;
    min_hgt = p8;
    max_hgt = p9;
    top_panel = p11;
    right_panel = p12;
    
    int w = 0;
    int h = 0;
    if (render_area != 0) {
        w = render_area->Width;
        h = render_area->Height;
    }
    positioning_callback(w, h);
    
    if (active != 0) {
        redraw(2);
    }
}

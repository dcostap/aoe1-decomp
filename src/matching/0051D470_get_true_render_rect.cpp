// VA: 0051D470 TRIBE_Panel_Pop::get_true_render_rect
// PDB source: tpnl_pop.cpp, lines 299-307

class TDrawArea;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    char gap_00[0x20];
    TDrawArea* render_area;
    char gap_24[0x48];
    int active;
    int visible;
    char gap_74[0x18];
    tagRECT render_rect;
    char gap_9C[0x58];
};

class TRIBE_Panel_Pop : public TPanel {
public:
    char gap_F4[0x30];
    TDrawArea* ImageBuffer;
    char gap_128[0x20];
    tagRECT UsedScreenRect;

    void get_true_render_rect(tagRECT& rect);
};

void TRIBE_Panel_Pop::get_true_render_rect(tagRECT& rect) {
    if (this->ImageBuffer && this->render_area && this->visible && this->active) {
        rect = this->UsedScreenRect;
    } else {
        rect = this->render_rect;
    }
}

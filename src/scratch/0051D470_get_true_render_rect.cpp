// target: VA 0051D470 TRIBE_Panel_Pop::get_true_render_rect(tagRECT&)
// first pass: use a local layout stub with the four gate fields and the two RECT sources
// copied as explicit dword-sized member assignments to mirror the packet
// probe 1: initial stub matched the control flow shape but the offsets collapsed; base/derived sizes need the full padding
// probe 2: direct field access gives a valid build, but the copy block still uses disp forms instead of the packet's add-immediate source pointer
// probe 3: pointer-temp spelling collapsed to the same disp form
// probe 4: char* + dst temp spelling hit a checker size mismatch before comparison; leaving the buildable shape in place

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
    TDrawArea* render_area; // +0x20
    char gap_24[0x48];
    int active;             // +0x6C
    int visible;            // +0x70
    char gap_74[0x18];
    tagRECT render_rect;    // +0x8C
    char gap_9C[0x58];      // pad TPanel to its real 0xF4 size
};

class TRIBE_Panel_Pop : public TPanel {
public:
    char gap_F4[0x30];
    TDrawArea* ImageBuffer; // +0x124
    char gap_128[0x20];
    tagRECT UsedScreenRect; // +0x148

    void get_true_render_rect(tagRECT& rect);
};

void TRIBE_Panel_Pop::get_true_render_rect(tagRECT& rect) {
    if (this->ImageBuffer && this->render_area && this->visible && this->active) {
        rect.left = this->UsedScreenRect.left;
        rect.top = this->UsedScreenRect.top;
        rect.right = this->UsedScreenRect.right;
        rect.bottom = this->UsedScreenRect.bottom;
    } else {
        rect.left = this->render_rect.left;
        rect.top = this->render_rect.top;
        rect.right = this->render_rect.right;
        rect.bottom = this->render_rect.bottom;
    }
}

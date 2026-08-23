// first pass: typed RECT copy with direct field gates from the packet
// removed virtual declaration because the local stub has no base class; target offsets include the real vptr in gap_000
#ifndef AOE1_PNL_MSG_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TMessagePanel {
public:
    char gap_000[0x20];
    int render_area;
    char gap_024[0x48];
    int active;
    int visible;
    char gap_074[0x18];
    tagRECT render_rect;
    char gap_09C[0x25C];
    int showing_message;
    char gap_2FC[0x34];
    void* ImageBuffer;
    char gap_334[0x20];
    tagRECT UsedScreenRect;

    void get_true_render_rect(tagRECT& rect);
};
#endif

void TMessagePanel::get_true_render_rect(tagRECT& rect) {
    if (this->ImageBuffer && this->render_area && this->visible && this->active && this->showing_message) {
        rect = this->UsedScreenRect;
    } else {
        rect = this->render_rect;
    }
}

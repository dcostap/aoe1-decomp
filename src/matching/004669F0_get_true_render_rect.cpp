#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual void get_true_render_rect(tagRECT& rect);
    char gap_04[0x88];
    tagRECT render_rect; // 0x8C
};

#endif
void TPanel::get_true_render_rect(tagRECT& rect) {
    rect.left = render_rect.left;
    rect.top = render_rect.top;
    rect.right = render_rect.right;
    rect.bottom = render_rect.bottom;
}

#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual void set_pos(long x, long y, long width, long height);

    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long x, long y, long width, long height);
};

#endif
void TPanel::set_rect(tagRECT rect) {
    set_rect(rect.left, rect.top, (rect.right - rect.left) + 1, (rect.bottom - rect.top) + 1);
}

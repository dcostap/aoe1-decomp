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

// Context gate: PDB module Panel.cpp, line 1118, TPanel owner, with the
// wrapper's scalar call at original vslot +0x0C.
// Attempt log: the natural tagRECT wrapper keeps size, frame, and calls, but
// grouped context emits the scalar call at +0x08 due shared overload order.
// BINARY NOTE: the executable uses the source rectangle's inclusive bounds.
void TPanel::set_rect(tagRECT rect) {
    set_rect(rect.left, rect.top, (rect.right - rect.left) + 1, (rect.bottom - rect.top) + 1);
}

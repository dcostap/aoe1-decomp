#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    int is_inside_rect(long x, long y, tagRECT* rect);
};

#endif
int TPanel::is_inside_rect(long x, long y, tagRECT* rect) {
    if (rect->left <= x && x <= rect->right && rect->top <= y && y <= rect->bottom) {
        return 1;
    }
    return 0;
}

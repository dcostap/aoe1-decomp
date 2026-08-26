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
    if (x < rect->left || x > rect->right || y < rect->top || y > rect->bottom) {
        return 0;
    }
    return 1;
}

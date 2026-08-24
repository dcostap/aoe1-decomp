#ifndef PNL_SCBR_CANONICAL_TU
struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
};

class TScrollBarPanel {
public:
    void draw_border(int x, int y, int left, int top, int right, int bottom);
    void draw_border(int x, int y, tagRECT* rect);
};
#endif

void TScrollBarPanel::draw_border(int x, int y, tagRECT* rect) {
    draw_border(x, y, rect->left, rect->top, rect->right, rect->bottom);
}

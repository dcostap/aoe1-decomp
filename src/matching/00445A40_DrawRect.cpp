struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void DrawRect(long left, long top, long right, long bottom, unsigned char mode);
    void DrawRect(tagRECT* rect, unsigned char mode);
};

void TDrawArea::DrawRect(tagRECT* rect, unsigned char mode) {
    DrawRect(rect->left, rect->top, rect->right, rect->bottom, mode);
}

#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    char gap_00[0x24];
    tagRECT clip_rect;

    int bound_point(long& x, long& y);
};

#endif
int TPanel::bound_point(long& x, long& y) {
    int bounded;
    long limit;

    bounded = 0;
    limit = clip_rect.left + 1;
    if (x < limit || ((limit = clip_rect.right - 1), x > limit)) {
        x = limit;
        bounded = 1;
    }
    limit = clip_rect.top + 1;
    if (y < limit) {
        y = limit;
        return 1;
    }
    limit = clip_rect.bottom - 1;
    if (y > limit) {
        y = limit;
        bounded = 1;
    }
    return bounded;
}

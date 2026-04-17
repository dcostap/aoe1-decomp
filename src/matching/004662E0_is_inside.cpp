class TPanel {
public:
    char gap_00[0x20];
    long clip_left;
    long clip_top;
    long clip_right;
    long clip_bottom;
    char gap_34[0x38];
    int active;

    virtual int is_inside(long x, long y);
};

int TPanel::is_inside(long x, long y) {
    if (active != 0) {
        if (x >= clip_left) {
            if (x <= clip_right) {
                if (y >= clip_top) {
                    if (y <= clip_bottom) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

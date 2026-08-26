#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT;

class TPanel {
public:
    virtual void draw_rect(tagRECT* rect);
    virtual void draw_offset(long x, long y, tagRECT* rect);

    char gap_04[0xEE];
    unsigned char draw_rect2_flag;

    virtual void draw_offset2(long x, long y, tagRECT* rect);
};

#endif
void TPanel::draw_offset2(long x, long y, tagRECT* rect) {
    draw_rect2_flag = 1;
    draw_offset(x, y, rect);
    draw_rect2_flag = 0;
}

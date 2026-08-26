#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT;

class TPanel {
public:
    virtual void draw_rect(tagRECT* rect);

    char gap_04[0xEE];
    unsigned char draw_rect2_flag;

    virtual void draw_rect2(tagRECT* rect);
};

#endif
void TPanel::draw_rect2(tagRECT* rect) {
    draw_rect2_flag = 1;
    draw_rect(rect);
    draw_rect2_flag = 0;
}

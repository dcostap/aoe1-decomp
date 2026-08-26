#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual void draw(void);

    char gap_04[0x20];
    tagRECT clip_rect;

    virtual void draw_rect(tagRECT* rect);
};

#endif
void TPanel::draw_rect(tagRECT* rect) {
    tagRECT save_rect;

    save_rect = clip_rect;
    clip_rect = *rect;
    draw();
    clip_rect = save_rect;
}

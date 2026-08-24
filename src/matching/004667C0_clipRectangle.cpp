#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
};

class TPanel {
public:
    char gap_00[0x24];
    tagRECT clip_rect;

    tagRECT clipRectangle(void) const;
};

#endif
tagRECT TPanel::clipRectangle(void) const {
    return clip_rect;
}

struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
};

struct TPanelGap24 {
    char gap_00[0x24];
};

class TPanel : public TPanelGap24 {
public:
    tagRECT clip_rect;

    void setClipRectangle(tagRECT rect);
};

void TPanel::setClipRectangle(tagRECT rect) {
    this->clip_rect = rect;
}

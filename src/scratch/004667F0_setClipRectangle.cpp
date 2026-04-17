// STATUS: blocked
// BLOCKER: VC5 keeps folding the +0x24 member-base adjustment into direct stores, producing a 32-byte body instead of the original 33-byte add-ecx-then-store sequence
// NOTE: behavior and store order are correct; remaining drift is source-shape/codegen only

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

    void setClipRectangle(tagRECT rect);
};

void TPanel::setClipRectangle(tagRECT rect) {
    tagRECT* clip_rect_ptr;

    clip_rect_ptr = (tagRECT*)((char*)this + 0x24);
    clip_rect_ptr->left = rect.left;
    clip_rect_ptr->top = rect.top;
    clip_rect_ptr->right = rect.right;
    clip_rect_ptr->bottom = rect.bottom;
}

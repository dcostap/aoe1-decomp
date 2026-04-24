struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
};

class TRIBE_Panel_Time {
public:
    char gap_00[0x20];
    void* render_area;
    char gap_24[0x48];
    int field_6C;
    int field_70;
    char gap_74[0xC0];
    void* image_buffer;
    char gap_138[0x20];
    tagRECT used_screen_rect;

    void get_true_render_rect(tagRECT& rect);
};

void TRIBE_Panel_Time::get_true_render_rect(tagRECT& rect) {
    if (this->image_buffer != 0 && this->render_area != 0 && this->field_70 != 0 && this->field_6C != 0) {
        rect = this->used_screen_rect;
        return;
    }
    rect = *(tagRECT*)((char*)this + 0x8C);
}

class TShape;

#ifndef PNL_SCBR_CANONICAL_TU
class TScrollBarPanel {
public:
    char gap_00[0x108];
    TShape* button_pics;
    int back_frame;
    int up_frame;
    int down_frame;
    int tab_frame;

    void set_buttons(TShape* button_pics, int back_frame, int up_frame, int down_frame, int tab_frame);
};
#endif

void TScrollBarPanel::set_buttons(TShape* button_pics, int back_frame, int up_frame, int down_frame, int tab_frame) {
    this->button_pics = button_pics;
    this->back_frame = back_frame;
    this->up_frame = up_frame;
    this->down_frame = down_frame;
    this->tab_frame = tab_frame;
}

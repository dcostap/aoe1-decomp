#ifndef TPNL_TML_WRAPPER
class TShape {
public:
    long shape_count();
};

class Time_Line_Panel {
public:
    char gap_00[0x4D4];
    TShape* special_events_pic;

    long width();
    void draw_legend();
};
#endif

void Time_Line_Panel::draw_legend() {
    if (this->special_events_pic != 0) {
        if (this->special_events_pic->shape_count() != 0) {
            width();
        }
    }
}

// STATUS: blocked
// BLOCKER: argument reload/store order around notifyTypeValue, drawTypeValue, and set_sound still differs from the original post-setup sequence
// NOTE: overall behavior matches; remaining drift is source ordering/codegen only

class TDrawArea;
class TDigital;

class TPanel {
public:
    virtual ~TPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y, long width, long height, int modal);
};

class TButtonPanel : public TPanel {
public:
    char gap_04[0x13C];
    long drawTypeValue;
    long notifyTypeValue;

    void set_sound(TDigital* sound);
    void set_id(short state, long id1, long id2);
    long setup(
        TDrawArea* draw_area,
        TPanel* parent,
        long x,
        long y,
        long width,
        long height,
        long draw_type,
        TDigital* sound,
        long notify_type,
        long button_id
    );
};

long TButtonPanel::setup(
    TDrawArea* draw_area,
    TPanel* parent,
    long x,
    long y,
    long width,
    long height,
    long draw_type,
    TDigital* sound,
    long notify_type,
    long button_id
) {
    ((TPanel*)this)->setup(draw_area, parent, x, y, width, height, 0);
    notifyTypeValue = notify_type;
    set_sound(sound);
    drawTypeValue = draw_type;
    set_id(0, button_id, 0);
    return 1;
}

// STATUS: active lead
// overall behavior matches; the remaining drift is the post-setup ordering of notifyTypeValue, drawTypeValue, and the set_sound call
// direct notify-then-draw-then-set_sound fell into a worse draw-first basin; next lead is the donor-like visible parameter surface (enum draw/notify plus pointer-typed sound) on top of the best current body order

class TDrawArea;
class TDigital;

enum DrawType {
    DrawType_0 = 0
};

enum NotifyType {
    NotifyType_0 = 0
};

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
        DrawType draw_type,
        TDigital* sound,
        NotifyType notify_type,
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
    DrawType draw_type,
    TDigital* sound,
    NotifyType notify_type,
    long button_id
) {
    ((TPanel*)this)->setup(draw_area, parent, x, y, width, height, 0);
    notifyTypeValue = notify_type;
    set_sound(sound);
    drawTypeValue = draw_type;
    set_id(0, button_id, 0);
    return 1;
}

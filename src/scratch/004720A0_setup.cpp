// TButtonPanel::setup - call TPanel::setup, store notify/draw, set_sound, set_id

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
    long drawTypeValue;               // 0x140
    long notifyTypeValue;             // 0x144

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
    TPanel::setup(draw_area, parent, x, y, width, height, 0);
    this->notifyTypeValue = notify_type;
    this->set_sound(sound);
    this->drawTypeValue = draw_type;
    this->set_id(0, button_id, 0);
    return 1;
}

class TDigital;

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x144];
    TDigital* sound;
    void set_sound(TDigital* v);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_sound(TDigital* v) { this->sound = v; }

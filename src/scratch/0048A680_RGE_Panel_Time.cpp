// tried a plain helper-style body first; that matched the field stores but missed the EH/vfptr constructor prolog entirely
// tried /GX on the actual constructor shape too; VC5 still stayed in the short non-EH basin with the wrong initial vfptr handling
// next lead: recover the original constructor-context trigger for the FS:[0] frame, likely donor-file/exception-mode/class-surface related
class TDrawArea;
class TPanel;

class TPanel {
public:
    char gap_00[0x80];
    int field_80;
    char gap_84[0x54];
    int field_D8;
    char gap_DC[0x18];

    virtual void vf00();
    virtual void* vf04(unsigned int);
    virtual long vf08();
    virtual long handle_idle();

    TPanel();
    long setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, unsigned char modal);
};

class RGE_Panel_Time : public TPanel {
public:
    void* font;
    unsigned long game_time;
    unsigned long last_game_time;
    int old_time;
    unsigned long real_time;

    virtual void destroy();
    virtual void* scalar_deleting_destructor(unsigned int);
    virtual long draw();
    virtual long handle_idle();

    RGE_Panel_Time(TDrawArea* draw_area, TPanel* parent, void* font_arg);
};

RGE_Panel_Time::RGE_Panel_Time(TDrawArea* draw_area, TPanel* parent, void* font_arg) : TPanel() {
    this->font = font_arg;
    this->field_80 = 0;
    this->game_time = 0;
    this->last_game_time = 0;
    this->old_time = -1;
    if (!this->setup(draw_area, parent, 0, 0, 0, 0, 0)) {
        this->field_D8 = 1;
    }
}

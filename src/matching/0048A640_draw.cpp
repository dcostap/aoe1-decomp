#ifndef RPNL_TBX_TU_CONTEXT
struct RectStub { int a,b,c,d; };

class TDrawArea {
public:
    void Clear(RectStub* rect, int value);
};

class RGE_Panel_Tool_Box {
public:
    virtual ~RGE_Panel_Tool_Box();
    virtual long setup(TDrawArea*, RGE_Panel_Tool_Box*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, RGE_Panel_Tool_Box*, RGE_Panel_Tool_Box*,
                                 RGE_Panel_Tool_Box*, RGE_Panel_Tool_Box*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw();
    virtual void draw_setup(int value);
    virtual void draw_finish(void);

    char gap_04[0x1C];
    TDrawArea* draw_area;
    RectStub rect;
    char gap_34[0x38];
    int field_6C;
    int field_70;

    void draw(void);
};
#endif

void RGE_Panel_Tool_Box::draw(void) {
    if ((this->draw_area != 0) && (this->field_70 != 0) && (this->field_6C != 0)) {
        this->draw_setup(0);
        this->draw_area->Clear(&this->rect, 0);
        this->draw_finish();
    }
}

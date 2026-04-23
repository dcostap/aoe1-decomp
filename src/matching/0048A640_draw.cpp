struct RectStub { int a,b,c,d; };

class TDrawArea {
public:
    void Clear(RectStub* rect, int value);
};

class RGE_Panel_Tool_Box {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void pre_draw(int value);
    virtual void post_draw(void);

    char gap_04[0x1C];
    TDrawArea* draw_area;
    RectStub rect;
    char gap_34[0x38];
    int field_6C;
    int field_70;

    void draw(void);
};

void RGE_Panel_Tool_Box::draw(void) {
    if ((this->draw_area != 0) && (this->field_70 != 0) && (this->field_6C != 0)) {
        this->pre_draw(0);
        this->draw_area->Clear(&this->rect, 0);
        this->post_draw();
    }
}

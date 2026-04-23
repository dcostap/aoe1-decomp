class Time_Line_Panel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void redraw(int mode);

    char gap_04[0x480];
    void* body_font;
    long body_font_wid;
    long body_font_hgt;

    void set_body_font(void* font, long width, long height);
};

void Time_Line_Panel::set_body_font(void* font, long width, long height) {
    this->body_font = font;
    this->body_font_wid = width;
    this->body_font_hgt = height;
    this->redraw(1);
}

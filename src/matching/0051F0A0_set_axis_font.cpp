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

    char gap_04[0x474];
    void* axis_font;
    long axis_font_wid;
    long axis_font_hgt;

    void set_axis_font(void* font, long width, long height);
};

void Time_Line_Panel::set_axis_font(void* font, long width, long height) {
    this->axis_font = font;
    this->axis_font_wid = width;
    this->axis_font_hgt = height;
    this->redraw(1);
}

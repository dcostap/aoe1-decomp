class TEasy_Panel {
public:
    char gap_0[0x320];
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    void set_bevel_colors(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f);
};

void TEasy_Panel::set_bevel_colors(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f) {
    this->bevel_color1 = a;
    this->bevel_color2 = b;
    this->bevel_color3 = c;
    this->bevel_color4 = d;
    this->bevel_color5 = e;
    this->bevel_color6 = f;
}

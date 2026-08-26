#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char gap_00[0x320];
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;

    void get_bevel_colors(unsigned char& c1, unsigned char& c2, unsigned char& c3, unsigned char& c4, unsigned char& c5, unsigned char& c6);
};
#endif

void TEasy_Panel::get_bevel_colors(unsigned char& c1, unsigned char& c2, unsigned char& c3, unsigned char& c4, unsigned char& c5, unsigned char& c6) {
    c1 = this->bevel_color1;
    c2 = this->bevel_color2;
    c3 = this->bevel_color3;
    c4 = this->bevel_color4;
    c5 = this->bevel_color5;
    c6 = this->bevel_color6;
}

class TScrollBarPanel {
public:
    char gap_00[0x1B8];
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;

    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
};

void TScrollBarPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6) {
    bevel_type = type;
    bevel_color1 = (unsigned char)c1;
    bevel_color2 = (unsigned char)c2;
    bevel_color3 = (unsigned char)c3;
    bevel_color4 = (unsigned char)c4;
    bevel_color5 = (unsigned char)c5;
    bevel_color6 = (unsigned char)c6;
}

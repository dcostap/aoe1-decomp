// VA: 0047CD40 set_bevel_info
// Pnl_txt.cpp:705-738

#ifndef PNL_TXT_TU_CONTEXT
class TPanel { public: virtual ~TPanel(); };
class TTextPanel : public TPanel {
public:
    char gap_004[0x16C];
    int bevel_type;
    unsigned char bevel_color1, bevel_color2, bevel_color3, bevel_color4, bevel_color5, bevel_color6;
    char gap_17A[6];
    int border_size;
    virtual void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
    void calc_draw_info(int flag);
};
#endif

void TTextPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6)
{
    bevel_type = type, bevel_color1 = (unsigned char)c1;
    bevel_color2 = (unsigned char)c2;
    bevel_color3 = (unsigned char)c3;
    bevel_color4 = (unsigned char)c4;
    bevel_color5 = (unsigned char)c5;
    bevel_color6 = (unsigned char)c6;

    switch (type) {
    case 1:
    case 2:
    case 5:
        border_size = 1;
        break;
    case 3:
    case 6:
        border_size = 2;
        break;
    case 4:
    case 7:
        border_size = 3;
        break;
    default:
        border_size = 0;
        break;
    }
    calc_draw_info(1);
}

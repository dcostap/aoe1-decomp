#ifndef AOE1_TPNL_INV_H
#define AOE1_TPNL_INV_H

// This header owns TRIBE_Panel_Inven. Its base comes from panel.h.
#include "panel.h"

class TShape;
class TRIBE_Player;

class TRIBE_Panel_Inven : public TPanel {
public:
    TShape* pics;
    TRIBE_Player* player;
    short save_attr_num;
    unsigned char gap_FE[2];
    short* save_attr;
    unsigned long idle_time;
    unsigned long idle_interval;
    void* font;
    unsigned long font_color;
    unsigned long back_color;

    TRIBE_Panel_Inven(TDrawArea*, TPanel*, void*, TRIBE_Player*);
    virtual ~TRIBE_Panel_Inven();
    virtual unsigned char get_help_info(char*& out_str, long& out_val,
                                        long x, long y);
    void set_text_color(unsigned long color1, unsigned long color2);
    virtual void draw();
    virtual long handle_idle();
protected:
    void save_info();
public:
    void set_player(TRIBE_Player*);
};

typedef char tpnl_inv_panel_size_check[
    (sizeof(TRIBE_Panel_Inven) == 0x118) ? 1 : -1];

#endif

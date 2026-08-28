#ifndef AOE1_TPNL_BTN_H
#define AOE1_TPNL_BTN_H

// PDB owner: tpnl_btn.cpp. TButtonPanel stays in pnl_btn.h.

#include "pnl_btn.h"

class TShape;
class TDigital;

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;
    int garrsion_number;
    unsigned char tribe_button_type;
    TShape* border_pic;
    unsigned char* color_table;
    int border_frame;
    char text_msg[0x100];
    int in_use;

    TRIBE_Panel_Button(TDrawArea*, TPanel*, TDigital*, void*, long, long,
                       TShape*);
    virtual ~TRIBE_Panel_Button();
    virtual void draw();
    void set_text_msg(char*);
    virtual int is_inside(long, long);
    void set_display_garrison(int);
    void set_garrison_number(int);
    int get_garrison_number();
};

typedef char tpnl_btn_button_size_check[
    (sizeof(TRIBE_Panel_Button) == 0x3D4) ? 1 : -1];

#endif

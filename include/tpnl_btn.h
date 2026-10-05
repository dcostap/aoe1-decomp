#ifndef AOE1_TPNL_BTN_H
#define AOE1_TPNL_BTN_H

#include "pnl_btn.h"

class TShape;
class TDigital;
class TRIBE_Screen_Game;

class TRIBE_Panel_Button : public TButtonPanel {
  protected:
    friend class TRIBE_Screen_Game;

    int display_garrison;
    int garrsion_number;
    unsigned char tribe_button_type;
    TShape* border_pic;
    unsigned char* color_table;
    int border_frame;
    char text_msg[0x100];
    int in_use;

  public:
    TRIBE_Panel_Button(
        TDrawArea* render_area_in, TPanel* parent_panel_in, TDigital* sound_in, void* font_in, long font_wid_in,
        long font_hgt_in, TShape* border_pic_in
    );
    virtual void draw();
    void set_text_msg(char* text_msg_in);
    virtual int is_inside(long x, long y);
    void set_display_garrison(int value);
    void set_garrison_number(int value);
    int get_garrison_number();
};

typedef char tpnl_btn_button_size_check[(sizeof(TRIBE_Panel_Button) == 0x3D4) ? 1 : -1];

#endif

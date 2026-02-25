#pragma once

#include "TPanel.h"

class TRIBE_Panel_Inven : public TPanel {
public:
    TRIBE_Panel_Inven(TDrawArea* area, TPanel* parent, void* font, TRIBE_Player* player);
    virtual ~TRIBE_Panel_Inven();

    virtual void draw() override;
    virtual long handle_idle() override;
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4) override;

    void set_player(TRIBE_Player* player);
    void set_text_color(unsigned long color1, unsigned long color2);

protected:
    void save_info();

public:
    TShape* pics;
    TRIBE_Player* player;
    short save_attr_num;
    short* save_attr;
    unsigned long idle_time;
    unsigned long idle_interval;
    void* font;
    unsigned long font_color;
    unsigned long back_color;
};

static_assert(sizeof(TRIBE_Panel_Inven) == 0x118, "Size mismatch");

#ifndef AOE1_TPNL_TIM_H
#define AOE1_TPNL_TIM_H

#include "panel.h"

class TRIBE_World;
class TRIBE_Player;

class TRIBE_Panel_Time : public TPanel {
public:
    void* font;
    unsigned int color1;
    unsigned int color2;
    int clock_type;
    int old_clock_type;
    int clock_format;
    int old_clock_format;
    int player_id;
    TRIBE_World* world;
    TRIBE_Player* player;
    unsigned long start_real_time;
    unsigned long game_time;
    unsigned long last_game_time;
    unsigned long display_time;
    unsigned long last_display_time;
    HRGN image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int ImageTextActive;
    int LastIBWidth;
    int LastIBHeight;

    TRIBE_Panel_Time(TDrawArea*, TPanel*);
    virtual ~TRIBE_Panel_Time();
    void set_rect(long, long, long, long);
    void startup();
    void set_clock_type(int, int);
    int get_clock_type();
    int get_player_id();
    virtual void draw();
    virtual void get_true_render_rect(tagRECT&);
    virtual long handle_idle();

protected:
    int render_to_image_buffer();
};

typedef char tribe_panel_time_size_check[
    (sizeof(TRIBE_Panel_Time) == 0x174) ? 1 : -1];

#endif

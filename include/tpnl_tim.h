#ifndef AOE1_TPNL_TIM_H
#define AOE1_TPNL_TIM_H

// PDB owner: tpnl_tim.cpp.
// BLOCKER: tpnl_tim.cpp still uses its former copied field aliases.
// Normalize that source before its next exact validation.

#include "panel.h"
#include "drawarea.h"
#include "basegame.h"
#include "player.h"
#include "world.h"

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
    RGE_Game_World* world;
    RGE_Player* player;
    unsigned long start_real_time;
    unsigned long current_display_value;
    unsigned long last_display_value;
    unsigned long display_time;
    int old_display_time;
    HRGN image_clip_region;
    TDrawArea* image_buffer;
    tagRECT image_rect;
    tagRECT used_image_rect;
    tagRECT used_screen_rect;
    int image_text_active;
    long last_ib_width;
    long last_ib_height;

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

extern char s_time_message_panel[];
extern const char s_tpnl_tim_draw[];
extern const char s_tpnl_tim_render_to_image_buffer[];
extern const char s_clock_hms_fmt[];

#endif

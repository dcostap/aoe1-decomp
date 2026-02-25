#pragma once

#include "TPanel.h"

class TRIBE_Panel_Time : public TPanel {
public:
    TRIBE_Panel_Time(TDrawArea* area, TPanel* parent);
    virtual ~TRIBE_Panel_Time();

    void startup();
    void set_clock_type(int clock_type, int player_id);
    int get_clock_type();
    int get_player_id();

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4) override;
    virtual void draw() override;
    virtual void get_true_render_rect(tagRECT* param_1) override;
    virtual long handle_idle() override;

protected:
    int render_to_image_buffer();

public:

    void* font;
    unsigned long color1;
    unsigned long color2;
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
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int ImageTextActive;
    int LastIBWidth;
    int LastIBHeight;
};

static_assert(sizeof(TRIBE_Panel_Time) == 0x174, "Size mismatch");

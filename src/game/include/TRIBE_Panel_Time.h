#pragma once

#include "TPanel.h"

class TRIBE_Panel_Time : public TPanel {
public:
    TRIBE_Panel_Time(TDrawArea* area, TPanel* parent);
    virtual ~TRIBE_Panel_Time();

    void startup();
    void set_clock_type(int clock_type, int player_id);

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

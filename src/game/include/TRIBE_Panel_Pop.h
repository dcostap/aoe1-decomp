#pragma once

#include "TPanel.h"

class TRIBE_Panel_Pop : public TPanel {
public:
    TRIBE_Panel_Pop(TDrawArea* area, TPanel* parent);
    virtual ~TRIBE_Panel_Pop();

    void startup();
    int get_player_id();

    void* font;
    unsigned long color1;
    unsigned long color2;
    unsigned long color3;
    int player_id;
    TRIBE_World* world;
    TRIBE_Player* player;
    int pop;
    int max_pop;
    unsigned char mode;
    float timer;
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int ImageTextActive;
    int LastIBWidth;
    int LastIBHeight;
};

static_assert(sizeof(TRIBE_Panel_Pop) == 0x164, "Size mismatch");

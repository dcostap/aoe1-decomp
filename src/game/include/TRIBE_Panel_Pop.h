#pragma once

#include "TPanel.h"

class TRIBE_Panel_Pop : public TPanel {
public:
    TRIBE_Panel_Pop(TDrawArea* area, TPanel* parent);
    virtual ~TRIBE_Panel_Pop();

    void startup();
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

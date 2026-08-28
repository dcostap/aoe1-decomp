#ifndef AOE1_TPNL_POP_H
#define AOE1_TPNL_POP_H

#include "panel.h"

class TRIBE_Player;
class TRIBE_World;

class TRIBE_Panel_Pop : public TPanel {
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
    HRGN image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int ImageTextActive;
    int LastIBWidth;
    int LastIBHeight;

    TRIBE_Panel_Pop(TDrawArea*, TPanel*);
    virtual ~TRIBE_Panel_Pop();
    virtual void set_rect(long, long, long, long);
    void startup();
    int get_player_id();
    virtual void draw();
    virtual void get_true_render_rect(tagRECT&);
    virtual long handle_idle();

protected:
    int render_to_image_buffer();
};

typedef char tpnl_pop_panel_size_check[
    (sizeof(TRIBE_Panel_Pop) == 0x164) ? 1 : -1];

#endif

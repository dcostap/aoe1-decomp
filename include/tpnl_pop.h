#ifndef AOE1_TPNL_POP_H
#define AOE1_TPNL_POP_H

// PDB owner: tpnl_pop.cpp.
// BLOCKER: tpnl_pop.cpp still uses its former copied field aliases.
// Normalize that source before its next exact validation.

#include "panel.h"
#include "drawarea.h"
#include "basegame.h"
#include "player.h"
#include "world.h"

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
    unsigned char pad_119[3];
    float timer;
    HRGN image_clip_region;
    TDrawArea* image_buffer;
    tagRECT image_rect;
    tagRECT used_image_rect;
    tagRECT used_screen_rect;
    int image_text_active;
    long last_ib_width;
    long last_ib_height;

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

typedef char tribe_panel_pop_size_check[
    (sizeof(TRIBE_Panel_Pop) == 0x164) ? 1 : -1];

#endif

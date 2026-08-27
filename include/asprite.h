#ifndef AOE1_ASPRITE_H
#define AOE1_ASPRITE_H

#include "sprite_context.h"

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    RGE_Active_Sprite(RGE_Sprite* sprite);
    RGE_Active_Sprite(int handle, RGE_Sprite** sprites);

    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[3];
    long offset_x;
    long offset_y;

    virtual void set_offset(long x, long y);
    virtual void save(int handle);
    virtual void update(float elapsed, float speed);
    virtual void draw(short facet, long x, long y, long x2, long y2,
                      RGE_Color_Table* colors, TDrawArea* area);
    virtual void normal_draw(short facet, long x, long y,
                             RGE_Color_Table* colors, TDrawArea* area);
    virtual void shadow_draw(short facet, long x, long y,
                             RGE_Color_Table* colors, TDrawArea* area,
                             unsigned char mode);
    virtual short what_frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short frame);
    virtual unsigned char frame_passed(short frame);
    virtual unsigned char looped();
    virtual short get_facetindex(short facet);
    virtual unsigned char get_frame(short& min_x, short& min_y,
                                    short& max_x, short& max_y, long facet);
    virtual void setToFirstFrame();

    unsigned char get_lowest_draw_level();
    int check_for_shadows();
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    RGE_Active_Animated_Sprite(RGE_Sprite* sprite);
    RGE_Active_Animated_Sprite(int handle, RGE_Sprite** sprites);
    virtual ~RGE_Active_Animated_Sprite();

    virtual void save(int handle);
    virtual void update(float elapsed, float speed);
    virtual void draw(short facet, long x, long y, long x2, long y2,
                      RGE_Color_Table* colors, TDrawArea* area);
    virtual void normal_draw(short facet, long x, long y,
                             RGE_Color_Table* colors, TDrawArea* area);
    virtual void shadow_draw(short facet, long x, long y,
                             RGE_Color_Table* colors, TDrawArea* area,
                             unsigned char mode);
    virtual short what_frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short frame);
    virtual unsigned char frame_passed(short frame);
    virtual unsigned char looped();
    virtual short get_facetindex(short facet);
    virtual unsigned char get_frame(short& min_x, short& min_y,
                                    short& max_x, short& max_y, long facet);
    virtual void setToFirstFrame();

    short frame;
    char gap_16[2];
    float animate_interval;
    float animate_last;
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;
    unsigned char animate_flag;
};

typedef char rge_active_sprite_size_check[
    (sizeof(RGE_Active_Sprite) == 0x14) ? 1 : -1];
typedef char rge_active_animated_sprite_size_check[
    (sizeof(RGE_Active_Animated_Sprite) == 0x28) ? 1 : -1];

#endif

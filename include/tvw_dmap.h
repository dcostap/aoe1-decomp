#ifndef AOE1_TVW_DMAP_H
#define AOE1_TVW_DMAP_H


#include "vw_dimap.h"

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View {
public:
    TRIBE_Diamond_Map_View();
    virtual ~TRIBE_Diamond_Map_View();

    unsigned long last_attack_time;
    int flash_on;

    virtual void set_redraw(TPanel::RedrawMode);

protected:
    virtual void draw_objects();
    virtual void draw_object(short, short, unsigned char, short,
                             RGE_Static_Object*);
};

typedef char tvw_dmap_view_size_check[
    (sizeof(TRIBE_Diamond_Map_View) == 0x174) ? 1 : -1];

#endif

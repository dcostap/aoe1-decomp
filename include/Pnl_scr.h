#ifndef AOE1_PNL_SCR_H
#define AOE1_PNL_SCR_H

// This header owns TScreenPanel. Shared types come from their owners.
#include "panel_ez.h"
#include "drawarea.h"
#include "color.h"

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel();
    TScreenPanel(char* name);
    virtual ~TScreenPanel();

    long setup(TDrawArea* render_area_in, char* info_file_name, long resource_file_id, int allow_shadow_area_in);
    long setup(TDrawArea* render_area_in, char* palette_file, long pal_res_id, unsigned char color_in, int allow_shadow_area_in);
    virtual void draw();
    virtual long handle_paint();
    virtual void set_focus(int have_focus_in);
};

typedef char pnl_scr_tscreen_size_check[
    (sizeof(TScreenPanel) == 0x478) ? 1 : -1];

#endif

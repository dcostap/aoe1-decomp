// VA: 004AD0F0 TRIBE_Screen_Sed::draw (scr_sed.cpp:3239-3263, 322B)
// Attempt log:
// baseline: typed field/virtual-call reconstruction; initial free draw shim and
// wrong zero-argument vslot were corrected from ordered call/ABI evidence.
// probe: raw/typed scalar rectangle access used the wrong main-view register;
// a tagRECT pointer plus aggregate assignment reproduces the proven stack window.
// diagnostic volatile scalar stores reached a nearby basin but were not retained;
// the ordinary aggregate copy is both exact and period-plausible.
// probe: the direct TEasy_Panel::draw member and one-int vslot 0x28 surface
// aligned all seven calls; the original frame and size then matched.
// probe: typed main-view field expressions alone changed the basin; a natural
// tagRECT* plus aggregate assignment (`rect_local = *mrect`) matched exactly.
// FLAGS: /nologo /c /O2 /Oy

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::draw()
{
    tagRECT rect_local;

    this->TEasy_Panel::draw();

    if (use_bevels != 0 && main_view != 0) {
        if (stored_rect.left == clip_rect.left &&
            stored_rect.top == clip_rect.top &&
            stored_rect.right == clip_rect.right &&
            stored_rect.bottom == clip_rect.bottom)
        {
            this->draw_setup(0);

            unsigned char* locked = render_area->Lock("scr_sed::draw", 1);
            if (locked) {
                tagRECT* mrect = &main_view->stored_rect;
                rect_local = *mrect;

                render_area->DrawBevel3(0, 0, pnl_wid - 1, rect_local.top - 1,
                    bevel_color1, bevel_color2, bevel_color3, bevel_color4,
                    bevel_color5, bevel_color6);

                render_area->DrawBevel3(0, rect_local.bottom + 1,
                    pnl_wid - 1, pnl_hgt - 1,
                    bevel_color1, bevel_color2, bevel_color3, bevel_color4,
                    bevel_color5, bevel_color6);

                render_area->Unlock("scr_sed::draw");
            }

            this->draw_finish();
        }
    }
}

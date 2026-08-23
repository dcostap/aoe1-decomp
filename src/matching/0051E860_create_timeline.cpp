// VA: 0051E860 Time_Line_Panel::create_timeline
// Source: tpnl_tml.cpp lines 149-190
// Attempt log:
// 1: natural reconstruction from packet/decompiler; /GX for new Time_Line_Panel cleanup: close, but font default branches inverted vs original.
// 2: spell font selection as nonnegative fast path to match jl-to-default layout.
// 3: goto/result still duplicated success epilogue.
// 4: structured single-return result variable regressed early liveness; rolled back.
// 5: spell setup success as positive branch before failure block: branch right but success epilogue duplicated.
// 6: uninitialized result with structured if/else still duplicated epilogue.
// 7: explicit label order matching original fail/success/initial-fail/zero blocks regressed to 54-byte diff; rolled back to best 35-byte structured form.
// 8: volatile result forced stack spill and regressed; /O1 and no-/GX too small. Current best has only tail/epilogue block layout drift.
// The isolated build had reviewed localized SEH tail-layout drift. Setup calls,
// failure stores, side effects, returns, stack offsets, and object sizes matched.
// BINARY NOTE: this owner shares the complete tpnl_tml.cpp class declarations
// with the earlier constructor and destructor owners.
// BINARY NOTE: the authentic source-line order is constructor, destructor,
// then create_timeline. That group emits this owner as an exact 377-byte body.
// The constructor owner still has a proven 125-byte mismatch, so the group is
// not a complete exact owner set yet.
// Exact-finish: a fresh build remained an exact 377-byte owner with 11 ordered
// calls, no frame, four saved registers, the original boundary, and the PDB
// Time_Line_Panel symbol.
// Exact-finish walkback: removing the result local and using direct returns
// kept the exact bytes. Removing the outer and setup else scopes also kept them.
// Retain those reductions. The shared tpnl_tml header, /GX EH context, extern
// rge_base_game, natural new, publication before validation, and call order
// remain required by the current exact build.

#include "../../include/tpnl_tml_context.h"

long Time_Line_Panel::create_timeline(TPanel* parent, Time_Line_Panel** out, long x1, long y1, long x2, long y2, long axis_font_id, long body_font_id, long xden, long yden)
{
    long left = parent->width() * x1 / xden;
    long top = parent->height() * y1 / yden;
    long right = parent->width() * x2 / xden;
    long bottom = parent->height() * y2 / yden;

    Time_Line_Panel* panel = new Time_Line_Panel();
    *out = panel;
    if (panel == 0 || panel->error_code != 0) {
        this->error_code = 1;
        return 0;
    }

    RGE_Font* axis_font;
    if (axis_font_id >= 0) {
        axis_font = rge_base_game->get_font(axis_font_id);
    } else {
        axis_font = rge_base_game->get_font(0x0B);
    }

    RGE_Font* body_font;
    if (body_font_id >= 0) {
        body_font = rge_base_game->get_font(body_font_id);
    } else {
        body_font = rge_base_game->get_font(0x0B);
    }

    if ((*out)->setup(parent->renderArea(), parent, left, top, right, bottom,
                      axis_font->font, axis_font->font_wid, axis_font->font_hgt,
                      body_font->font, body_font->font_wid, body_font->font_hgt,
                      0, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return 0;
    }

    (*out)->init_timeline();
    return 1;
}

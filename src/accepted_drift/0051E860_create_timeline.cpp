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
// ACCEPTED_DRIFT: reviewed localized equivalent SEH tail/block-layout drift. Setup args/calls, field_D8 failure stores,
// init_timeline success side effect, return values, stack/EH offsets, and object sizes match; rebuilt duplicates/clones
// success/failure epilogues where original routes through a shared xor/mov return tail.
// Translation-unit sweep: one prior out-of-line diagnostic function selects an
// exact 377-byte body. The two real earlier tpnl_tml.cpp owners conflict with
// this local panel declaration and do not form a valid direct group. No
// synthetic context is retained. A future pass needs one shared timeline type.

class TDrawArea;
class TPanel;
class Time_Line_Panel;
class RGE_Base_Game;

class TPanel {
public:
    long width();
    long height();
    TDrawArea* renderArea();
};

class RGE_Font {
public:
    void* font;       // +0
    long font_wid;    // +4
    long font_hgt;    // +8
};

class RGE_Base_Game {
public:
    RGE_Font* get_font(int id);
};

extern RGE_Base_Game* rge_base_game;

class Time_Line_Panel {
public:
    char gap_000[0x0D8];
    int field_D8;
    char gap_0DC[0x52C - 0x0DC];

    Time_Line_Panel();
    long create_timeline(TPanel* parent, Time_Line_Panel** out, long x1, long y1, long x2, long y2, long axis_font_id, long body_font_id, long xden, long yden);
    long setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height,
               void* axis_font, long axis_w, long axis_h, void* body_font, long body_w, long body_h,
               char* bg, char* se, int fill_back, unsigned char back_color, int outline, unsigned char outline_color);
    void init_timeline();
};

long Time_Line_Panel::create_timeline(TPanel* parent, Time_Line_Panel** out, long x1, long y1, long x2, long y2, long axis_font_id, long body_font_id, long xden, long yden)
{
    long left = parent->width() * x1 / xden;
    long top = parent->height() * y1 / yden;
    long right = parent->width() * x2 / xden;
    long bottom = parent->height() * y2 / yden;

    Time_Line_Panel* panel = new Time_Line_Panel();
    *out = panel;
    long result;

    if (panel == 0 || panel->field_D8 != 0) {
        this->field_D8 = 1;
        result = 0;
    } else {
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
            this->field_D8 = 1;
            result = 0;
        } else {
            (*out)->init_timeline();
            result = 1;
        }
    }

    return result;
}

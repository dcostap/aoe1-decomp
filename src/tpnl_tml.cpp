// PDB source module: C:/msdev/work/age1_x1/tpnl_tml.cpp.
// Definitions follow the original PDB source order.

#include "../include/tpnl_tml.h"
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" int __cdecl stricmp(const char*, const char*);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);


// 0051E650 Time_Line_Panel::Time_Line_Panel (tpnl_tml.cpp:98-109)
//
// Attempt log:
// baseline: offset-backed TPanel constructor; exact size/instruction count but
//   wrong base-call symbol and several delayed constant stores.
// probe 2: period TEasy_Panel hierarchy and virtual class surface fixed the
//   direct call target, but VC5 placed the derived vtable immediately after the
//   base call and moved the constant stores.
// probes 3/7/10: the natural member-initializer-list form is the best basin
//   (276 bytes, 1 aligned TEasy_Panel call, 125 strict-diff bytes); it still
//   emits highlightTextColor1 before text_style and delays the vtable/back
//   color/timeline tail relative to the oracle.
// probes 4/5/6: body-only, reduced virtual surface, and complete PDB layout
//   variants did not improve the emitted code.
// probe 9: a focused constructor-form lab found no exact variant; the
//   remaining blocker is VC5 store/vtable scheduling, not size or call shape.
// current session: body-assignment, full TPanel/TEasy_Panel vtable, member-width,
// declaration-order, implicit-base, and narrowed initializer/body variants were
// compiled and restored; none beat the 276-byte/125-diff initializer-list basin.
//   The body forms moved the compiler vtable store to entry (200-209 diff), while
//   the full virtual surface and ground-truth widths emitted unchanged bytes.
// order lead: moving text_style to the first initializer-list entry emitted
// identical 276-byte/125-diff code; moving it to the first body statement was
// worse (276 bytes/221 diff), so restore the canonical initializer-list source.
// paused: ordered base call and all 47 instructions/size match, but the first
// mismatch remains +000C (highlightTextColor1 before text_style) with delayed
// vtable/back-color/tail stores; next lead is original TU/header scheduling.
// layout hypothesis: use the canonical 0xF4 TPanel and 0x478 TEasy_Panel
// ownership from the type dumps and the exact 0051E9E0 setup donor.
// layout probe: the full canonical declarations and handle_mouse_input name
// emitted the same 276-byte/125-diff constructor; retain them as source truth.
// BINARY NOTE: this owner shares the complete tpnl_tml.cpp class declarations
// with the later destructor and create_timeline owners.
// context probe: the authentic ordered group keeps this owner at 276 bytes with
// the same 125 strict-diff bytes; the shared context does not repair this owner.
// context audit: the grouped constructor has the PDB-qualified constructor
// symbol, one matching TEasy_Panel call, and the same stores to every proven
// field with the same values. Only independent store order and vtable timing
// differ. It has no branch or side-effect call after the base constructor.
// Source-order permutations and ground-truth member widths stayed in the same
// 125-byte basin. Treat this as localized equivalent compiler drift, not an
// ownership or behavior defect. The group remains valid context for 0051E860,
// but it is not an all-exact owner set.
// exact-finish retry: implicit-base plus style-first initialization, signed and
//   narrow constant spellings, field access, member access, source-line bands,
//   /G5, and class declaration order all kept the same 125-byte schedule.
// Moving highlightTextColor1 into the body changed the schedule but put that
//   store after the derived vptr. Member-derived color values added loads and
//   moved the vptr to entry. The remaining blocker is authentic header context
//   or another natural initializer model that preserves partial construction.
// fresh exact-finish baseline: PDB owner Time_Line_Panel::Time_Line_Panel in
//   tpnl_tml.cpp:98-109; 276 bytes, 47 instructions, one direct TEasy_Panel
//   call, no frame, and saved ESI. The canonical source preserves all proven
//   field widths, values, the derived-vptr publication, and UI tail stores.
// fresh probe: reordering the initializer-list entries to follow the original
//   emitted stores was a duplicate 125-byte schedule.
// fresh probe: replacing the first initializer group with body assignments kept
//   the 276-byte boundary but widened the strict diff to 209 bytes and moved
//   the derived vptr to entry.
// fresh probe: moving only back_color to the body produced 126 bytes and put
//   its store after the derived vptr; restore the initializer form.
// fresh probe: adding the period allocation headers changed no schedule and
//   was not retained. No natural context probe produced exact bytes.
// BLOCKED: the remaining 125-byte difference is independent store scheduling
//   and block order. Keep the canonical source and do not alter tpnl_tim.cpp.


Time_Line_Panel::Time_Line_Panel()
    : TEasy_Panel(),
      axis_font(0),
      axis_font_wid(0),
      axis_font_hgt(0),
      body_font(0),
      body_font_wid(0),
      body_font_hgt(0),
      text_style(ChiseledStyle),
      text_color1(0xFFFFFF),
      text_color2(0),
      highlightTextColor1(0xFFFF),
      highlightTextColor2(0),
      text_wid(0),
      text_hgt(0),
      background_pic(0),
      background_pic_wid(0),
      background_pic_hgt(0),
      fill_back(0),
      back_color(0xFF),
      outline(0),
      outline_color(0),
      bevel_type(0),
      bevel_color1(0),
      bevel_color2(0),
      bevel_color3(0),
      bevel_color4(0),
      bevel_color5(0),
      bevel_color6(0),
      special_events_pic(0),
      special_events_pic_wid(0),
      special_events_pic_hgt(0),
      total_slices_to_drop(0),
      time_slice_events(0)
{
    handle_mouse_input = 0;
    timeline_flag = 1;
    drop_flag = 0;
    pop_reading_rate = 0x0C;
    legend_entry_text[0] = 0;
    legend_entry_text[1] = 0;
    legend_entry_text[2] = 0;
}

// 0051E790 ~Time_Line_Panel (tpnl_tml.cpp:116-141)
// PDB source: tpnl_tml.cpp (Time_Line_Panel::~Time_Line_Panel)
//
// Attempt log:
// attempt 1: manual dtor+op delete; 192/206b, no EH frame.
// attempt 2: delete operator + virtual dtors for EH frame. EXACT MATCH.
// Key: virtual destructors in TPanel/TEasy_Panel/Time_Line_Panel force VC5
//   to emit EH frame (push -1; push handler; mov [fs:0],esp). Automatic base
//   dtor call (not explicit), proper linked-list walk using p->next before free.
//   Offsets: TPanel vtable at +0x00 (compiler-managed). 12 relocations masked.
// BINARY NOTE: this owner shares the complete tpnl_tml.cpp class declarations
// with the earlier constructor and the later create_timeline owner.
// context probe: the authentic ordered group remains an exact 206-byte owner.


Time_Line_Panel::~Time_Line_Panel() {
    Special_Events* p;

    while (this->time_slice_events != NULL) {
        p = this->time_slice_events;
        this->time_slice_events = p->next;
        free(p);
    }

    if (this->background_pic != NULL) {
        delete this->background_pic;
        this->background_pic = NULL;
    }

    if (this->special_events_pic != NULL) {
        delete this->special_events_pic;
        this->special_events_pic = NULL;
    }

    for (int i = 0; i < 3; i++) {
        this->delete_panel((TPanel**)&this->legend_entry_text[i]);
    }

}

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

// 0051E9E0 Time_Line_Panel::setup (tpnl_tml.cpp:202-227)
// Attempt 3: fix TPanel.layout - render_area at +0x20
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline surface.



long Time_Line_Panel::setup(
    TDrawArea* param_1,
    TPanel* param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6,
    void* param_7,
    long param_8,
    long param_9,
    void* param_10,
    long param_11,
    long param_12,
    char* param_13,
    char* param_14,
    int param_15,
    unsigned char param_16,
    int param_17,
    unsigned char param_18
)
{
    this->TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);

    this->fill_back = param_15;
    this->back_color = param_16;
    this->outline = param_17;
    this->outline_color = param_18;

    if (param_17) {
        this->bevel_type = 1;
    }

    this->set_axis_font(param_7, param_8, param_9);
    this->set_body_font(param_10, param_11, param_12);
    this->set_background(param_13);
    this->set_special_events(param_14);

    unsigned char pal_idx = (unsigned char)GetNearestPaletteIndex(
        *(void**)((*(char**)this->render_area) + 8), 0);
    this->set_back_color(1, pal_idx);

    return 1;
}

// 0051EAB0 Time_Line_Panel::set_bevel_info (tpnl_tml.cpp:234-242)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline surface.
// PDB-qualified owner: ?set_bevel_info@Time_Line_Panel@@QAEXHHHHHHH@Z.
// The body ends at 0051EAF8 after ret 1Ch; padding starts at 0051EAF9.
// Fresh exact validation used the authentic ordered module, with
// Time_Line_Panel::setup at 0051E9E0 immediately before this owner.
// Exact-finish: implicit int-to-byte member conversion is sufficient; removing
// explicit casts preserved all 73 bytes.


void Time_Line_Panel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    bevel_type = param_1;
    bevel_color1 = param_2;
    bevel_color2 = param_3;
    bevel_color3 = param_4;
    bevel_color4 = param_5;
    bevel_color5 = param_6;
    bevel_color6 = param_7;
}

// 0051EB00 Time_Line_Panel::set_background (tpnl_tml.cpp:248-268)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline and TShape surfaces.


int Time_Line_Panel::set_background(char* name) {
    long x_max;
    long x_min;
    long y_max;
    long y_min;

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (name == 0 || *name == '\0') {
        return 0;
    }

    this->background_pic = new TShape(name, -1);
    this->background_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, (long)0);
    this->background_pic_wid = (short)(y_max - x_max + 1);
    this->background_pic_hgt = (short)(y_min - x_min + 1);
    return 1;
}

// 0051EC10 Time_Line_Panel::set_background (tpnl_tml.cpp:275-314)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline and TShape surfaces.


int Time_Line_Panel::set_background(char* name, long id)
{
    long y_max;
    long y_min;
    long x_min;
    long x_max;
    char file_name2[260];

    if (this->background_pic != 0) {
        delete this->background_pic;
        this->background_pic = 0;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (name != 0 && *name != 0 && stricmp(name, "none") != 0) {
        if (strchr(name, '.') == 0) {
            sprintf(file_name2, "%s.shp", name);
        } else {
            sprintf(file_name2, "%s", name);
        }
        this->background_pic = new TShape(file_name2, id);
    } else if (id != -1) {
        this->background_pic = new TShape("", id);
    }

    if (this->background_pic != 0 && this->background_pic->is_loaded() == 0) {
        delete this->background_pic;
        this->background_pic = 0;
    }

    if (this->background_pic != 0) {
        this->background_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, (long)0);
        this->background_pic_wid = (short)(y_max - x_max + 1);
        this->background_pic_hgt = (short)(y_min - x_min + 1);
        return 1;
    }
    return 0;
}

// VA: 0051EDD0 Time_Line_Panel::set_special_events (258 B, EXACT MATCH)
// PDB source: tpnl_tml.cpp lines 321-341
// Key insight: function-scope locals force the 16-byte sub area to be fully
// occupied, leaving the param_1 slot available for the allocation result.
// Must use /GX flag for EH prologue (delete + new with throwing constructor).
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline and TShape surfaces.

int Time_Line_Panel::set_special_events(char* param_1) {
    long x_min;
    long y_max;
    long y_min;
    long loc;
    if (this->special_events_pic) {
        delete this->special_events_pic;
        this->special_events_pic = 0;
        this->special_events_pic_wid = 0;
        this->special_events_pic_hgt = 0;
    }
    if (param_1 && *param_1) {
        this->special_events_pic = new TShape(param_1, -1);
        this->special_events_pic->shape_minmax(&y_max, &loc, &x_min, &y_min, 0);
        this->special_events_pic_wid = (short)(x_min - y_max + 1);
        this->special_events_pic_hgt = (short)(y_min - loc + 1);
        return 1;
    }
    return 0;
}

// 0051EEE0 Time_Line_Panel::set_special_events
// Source: tpnl_tml.cpp lines 348-387
// attempt 1: cloned exact 0051EC10 set_background pattern with special_events offsets.


int Time_Line_Panel::set_special_events(char* name, long id)
{
    long y_max;
    long y_min;
    long x_min;
    long x_max;
    char file_name2[260];

    if (this->special_events_pic != 0) {
        delete this->special_events_pic;
        this->special_events_pic = 0;
        this->special_events_pic_wid = 0;
        this->special_events_pic_hgt = 0;
    }

    if (name != 0 && *name != 0 && stricmp(name, "none") != 0) {
        if (strchr(name, '.') == 0) {
            sprintf(file_name2, "%s.shp", name);
        } else {
            sprintf(file_name2, "%s", name);
        }
        this->special_events_pic = new TShape(file_name2, id);
    } else if (id != -1) {
        this->special_events_pic = new TShape("", id);
    }

    if (this->special_events_pic != 0 && this->special_events_pic->is_loaded() == 0) {
        delete this->special_events_pic;
        this->special_events_pic = 0;
    }

    if (this->special_events_pic != 0) {
        this->special_events_pic->shape_minmax(&x_max, &x_min, &y_max, &y_min, (long)0);
        this->special_events_pic_wid = (short)(y_max - x_max + 1);
        this->special_events_pic_hgt = (short)(y_min - x_min + 1);
        return 1;
    }
    return 0;
}

// 0051F0A0 Time_Line_Panel::set_axis_font (tpnl_tml.cpp:394-399)
// BINARY NOTE: the shared timeline surface preserves the redraw slot at +20.


void Time_Line_Panel::set_axis_font(void* font, long width, long height) {
    this->axis_font = font;
    this->axis_font_wid = width;
    this->axis_font_hgt = height;
    this->redraw(1);
}

// 0051F0D0 Time_Line_Panel::set_body_font (tpnl_tml.cpp:407-412)
// BINARY NOTE: the shared timeline surface preserves the redraw slot at +20.


void Time_Line_Panel::set_body_font(void* font, long width, long height) {
    this->body_font = font;
    this->body_font_wid = width;
    this->body_font_hgt = height;
    this->redraw(1);
}

// 0051F100 Time_Line_Panel::set_back_color (tpnl_tml.cpp:419-422)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline surface.


void Time_Line_Panel::set_back_color(int a, unsigned char b) {
    this->fill_back = a;
    this->back_color = b;
}

// 0051F120 Time_Line_Panel::draw_border (tpnl_tml.cpp:429-467)
// BINARY NOTE: this owner uses the shared TPanel and TDrawArea surfaces.
// The panel coordinate names map to the proven +0x0C..+0x18 homes.


void Time_Line_Panel::draw_border()
{
    if (this->bevel_type != 0) {
        if (this->render_area->Lock((char*)0x58b770, 1) != 0) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->outline_color);
                break;
            case 2:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_wid + this->pnl_x - 1, this->pnl_hgt + this->pnl_y - 1, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock((char*)0x58b770);
    }
}

// VA: 0051F310, Time_Line_Panel::init_timeline, 455 bytes
// Source: tpnl_tml.cpp lines 476-538
// Attempt log:
// - v1: natural reconstruction from packet/decompiler with local layout fields and direct TPanel methods.
// - v2: modeled rge_base_game->world (+0x3f4), world->player_num (+0x3c), players (+0x40), player history_info (+0x83c).
// - v3: used explicit int stack temps for FILD conversions and exact field offsets from type dump/asm.
// - v4: split usable_X assignment/subtraction to probe width-result register allocation.
// - v5: changed usable_X to long to probe local register choice.
// - v6: hoisted entries local before width call; worsened first mismatch to +0x62, rolled back.
// - v7: delayed entries local until after FILD setup, using member load for temp2 to probe edx/ecx swap.
// - v8: changed TPanel position/size return declarations from long to int; no change.
// - v9: spell usable_X as `-0x31 + width()` single expression; no change.
// - v10: reversed line-max assignments to probe late load/store order; edit diff improved to 8.79%.
// - v11: routed width result through temp1; worsened first mismatch/size family, rolled back.
// - v12: inverted float compare spelling to `1.0f > bar_thickness`; worsened edit diff, rolled back.
// - v13: paused in scratch with a 455-byte near-match; the remaining ECX/EDX
//   lifetime swap was traced to persistent entries/diff/temp copies.
// - v14: removed those compiler-steering copies and used direct member arithmetic;
//   the emitted function became an exact 455-byte match.
// - v15: removed the unused player_off increment scaffold; typed players[i+1]
//   traversal remained exact and is the cleaner source model.
// - v16: removed the unused explicit _ftol declaration; natural casts remained exact.
// Exact: 455/455 bytes, 0 strict diff, exact frame/call/CFG/relocation identity.
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline and world surfaces.


extern RGE_Base_Game* rge_base_game;

void Time_Line_Panel::init_timeline()
{
    int i = 0;
    this->num_history_entries = 0;
    RGE_Game_World* world = rge_base_game->world;
    int count = (int)world->player_num - 1;
    if (count > 0) {
        do {
            int n = world->players[i + 1]->history_info->get_history_entry_num();
            if (this->num_history_entries < n) {
                this->num_history_entries = n;
            }
            i++;
            world = rge_base_game->world;
        } while (i < (int)world->player_num - 1);
    }

    int usable_X = -0x31 + this->width();
    if (this->num_history_entries == 0) {
        this->num_history_entries = 1;
        this->timeline_flag = 0;
    }

    this->time_slice_drop_rate = 0.0f;
    this->bar_thickness = (float)usable_X / (float)this->num_history_entries;

    if (this->bar_thickness < 1.0f) {
        this->bar_thickness = 1.0f;
        this->num_entries_page = usable_X;
        this->drop_flag = 1;
        this->total_slices_to_drop = this->num_history_entries - usable_X;
        this->time_slice_drop_rate =
            (float)usable_X / (float)this->total_slices_to_drop;
    } else {
        this->num_entries_page = this->num_history_entries;
    }

    this->X_axis_length = (long)((float)this->num_entries_page * this->bar_thickness) + 4;
    this->Y_axis_length = this->height() - this->axis_font_hgt * 4 - 0x1a;
    this->X_start_line_pos = this->xPosition() + 0x1b;
    int y = this->yPosition() + this->axis_font_hgt * 2 + 0x0f;
    this->X_line_pos = this->X_start_line_pos;
    this->Y_start_line_pos = y;
    this->Y_line_pos = y;
    this->Y_line_max_length = this->Y_axis_length - 3;
    this->X_line_max_width = this->X_axis_length - 2;

    if (this->num_entries_page < 12) {
        this->pop_reading_rate = 1;
    } else {
        this->pop_reading_rate =
            (long)((float)(this->num_entries_page - 1) * 0.1f);
    }
}

// VA: 0051F4E0 Time_Line_Panel::add_pop_total_special_event()
// Source: tpnl_tml.cpp lines 544-575
// Size: 124 bytes, __thiscall, ret 10h (4 params)
//
// Attempt log:
// Probe 1: Natural struct with field-order assignments — 6 bytes diff
//   Pure register allocation: original uses edx=pop_total, ecx=icon_flag
//   Rebuilt reverses: ecx=pop_total, edx=icon_flag
// Probe 2: Moved pop_total assignment up (before zero-fill) — worse (21 bytes)
// Probe 3: Swapped icon_flag before pop_total in source — fixed reg alloc, reversed store order
// Probe 4: Exact struct types from type dump — still 6 bytes (edx/ecx swap)
// Probe 5: const locals for pop_total/icon_flag — still 6 bytes
// Probe 6: Renamed params (pt/iflg) + icon_flag first in source — fixed regs, wrong store order
//
// Probe 7: Moved event=3 and pop_total=pop_total before the remaining zero-fill.
//   This produced the original register colors, late event/pop/icon stores, and
//   the exact 124-byte target. Walkback of only this source-order change restored
//   the 6-byte permutation.
// Exact: 124/124 bytes, 0 strict diff, exact frame/call/CFG/relocation identity.
// BINARY NOTE: the target allocates a zeroed 0xB0-byte Special_Events record,
// writes the four parameters and event value 3, then prepends the record at
// Time_Line_Panel::time_slice_events (+0x518).
// BINARY NOTE: event and pop_total are assigned before the remaining zero
// stores in source; VC5 schedules their final stores in the original late group.


void Time_Line_Panel::add_pop_total_special_event(long time_slice, long pop_total, long X_line_pos, int icon_flag) {
    Special_Events* se = (Special_Events*)calloc(1, 0xB0);

    se->time_slice = time_slice;
    se->X_line_pos = X_line_pos;
    se->Y_line_pos = 0;
    se->intermediate_y_line_segment = 0;
    se->player_id = 0;
    se->player_color = 0;
    se->event = 3;
    se->pop_total = pop_total;
    se->integer_value_1 = 0;
    se->integer_value_2 = 0;
    se->start_x = 0;
    se->start_y = 0;
    se->start_txt_x1 = 0;
    se->start_txt_y1 = 0;
    se->start_txt_x2 = 0;
    se->start_txt_y2 = 0;
    se->text_length1 = 0;
    se->text1[0] = 0;
    se->text_length2 = 0;
    se->text2[0] = 0;
    se->icon_flag = icon_flag;
    se->next = this->time_slice_events;
    this->time_slice_events = se;
}

void* __cdecl calloc(int,int);
void Time_Line_Panel::record_special_event(unsigned char param_1,TRIBE_History_Info* param_2,unsigned char param_3,long param_4,long param_5,long param_6,long param_7){
    long t=param_4;
    if (!param_2->get_history_event(t, *(unsigned char*)&param_4)) return;
    Special_Events* p=(Special_Events*)calloc(1,0xB0);
    p->X_line_pos=param_5; p->Y_line_pos=param_6; p->intermediate_y_line_segment=param_7; p->time_slice=t;
    p->player_id=param_1; p->player_color=param_3; p->event=(unsigned char)param_4;
    p->pop_total=0;
    p->integer_value_1=0; p->integer_value_2=0; p->start_x=0; p->start_y=0; p->start_txt_x1=0; p->start_txt_y1=0; p->start_txt_x2=0; p->start_txt_y2=0; p->text_length1=0; p->text1[0]=0; p->text_length2=0; p->text2[0]=0; p->icon_flag=0;
    p->next=time_slice_events; time_slice_events=p;
}

// 0051F600 Time_Line_Panel::calculate_icon_location
// Attempt log:
// try 1-10 (prior worker): decompiler-shaped reconstruction with an incomplete
// Special_Events/Time_Line_Panel surface and a two-argument ABI; exact size was
// padded but the emitted body was broad drift.
// baseline candidate: restored the ground-truth Special_Events and
// Time_Line_Panel ownership/layout, the three-argument __thiscall ABI, the
// typed TShape reference surface, and direct strlen/switch source shape.
// probe 2: changed the valid flag to period-style `ok = 1` with an explicit
// null test; this recovered the original prologue and reduced the strict diff.
// probe 3: reversed the ordinary zero-initialized local declaration order;
// this recovered the +20/+1c/+18 initialization homes exactly.
// probe 4: reversed the centered-icon bound predicate; only the compare
// allocation changed, but the original operand polarity remained supported.
// probe 5: a named centered-x temporary was codegen-duplicate and rolled back.
// probe 7: a named right-bound temporary was codegen-duplicate and rolled back.
// probe 8: delayed case-2's text-x store with a scoped case local; this kept
// separate case-0/case-2 handlers and improved emitted size by 20 bytes.
// probe 9: named max-x/product-first truncation predicates were effectively
// duplicate; retained only as the cleaner phase-local source form.
// probe 10: swapping semantic start-x/start-y local ownership regressed the
// proven initialization homes; restored the probe-9 source.
// current claim probe: a separate natural left-x temporary was codegen-
// duplicate; restored the clean source.
// current claim probe: reversed the three text-fit predicates so the overflow
// arm stays inline and the fit arm branches to the later block; this reduced
// the strict diff by one byte and improved block topology, so it is retained.
// current claim probe: nested the post-shape-bounds ok guard as suggested by
// the decompiler's proven nested source structure; it worsened size by 8 bytes
// and lost the exact block at +00a4, so it was restored.
// Paused blocker: the typed ABI/layout, frame, saved-register set, and three
// direct calls are exact, but VC5 still chooses the wrong centered-bound
// register/reload topology and omits the oracle's case-0 stack stores and
// modes-6/8 parameter-home spill.  The remaining branch/case placement and
// final temporary coloring are structural/source-shape leads, not a safe blind
// register tweak.  No inline asm or opaque address plumbing was used.
// claim probes 1-27: case-local mode bounds recovered the exact function size
// and several exact handler blocks.  A reversed case-1 Y predicate and a
// case-0 text-X local improved the clean source, but did not change the first
// centered-bound mismatch.  Nested geometry guards, inherited panel context,
// Windows and standard-library header variants, and an eight-variant source
// lab produced no exact result.  The nested guard had better metrics, but the
// extra ok test is not in the oracle and was not retained.
// BINARY NOTE: the oracle writes case-0 text results to a local stack home and
// reuses the dead parameter-2 home in modes 6 and 8.  The clean source still
// misses both stores while preserving the proven behavior and ABI.
// LIKELY INTENT: the source uses one centered icon bound and separate text
// placement paths for event modes 0, 1, 2, 6, and 8.
// claim probes 29-44: source operand and field-order variants did not change
// the first centered-bound register basin.  Repeating the mode-6/8 bound
// expression recovered the oracle's dead parameter-2 home store and two
// exact truncation blocks.  Reversing the vertical clip predicate recovered
// its cmp/jcc polarity.  Reversing the vertical temporary declarations
// improved block shape without changing the strict diff.  The final source
// keeps those natural, binary-supported forms.  It remains unresolved.


int Time_Line_Panel::calculate_icon_location(
    Special_Events* param_1, short param_2, uchar param_3)
{
    Special_Events* event = param_1;
    short width;
    short height;
    int bounds_result;
    int ok = 1;
    int local_4 = 0;
    long start_y = 0;
    long start_x = 0;

    event->icon_flag = 0;

    if (this->special_events_pic == 0) {
        ok = 0;
    }
    if (this->special_events_pic->shape_count() == 0) {
        ok = 0;
    }
    if (this->special_events_pic->shape_count() < (long)param_2) {
        ok = 0;
    }

    if (ok != 0) {
        this->special_events_pic->shape_bounds(param_2, width, height);
        if (width > 0) {
            this->special_events_pic_wid = width;
        }
        if (height > 0) {
            this->special_events_pic_hgt = height;
        }
    }

    if (ok != 0) {
        if (this->special_events_pic_hgt > event->intermediate_y_line_segment) {
            ok = 0;
        }

        int half_width = this->special_events_pic_wid / 2;
        if (event->X_line_pos + half_width >
            this->X_line_max_width + this->X_start_line_pos) {
            ok = 0;
        }
        half_width = event->X_line_pos - half_width;
        if (half_width < this->X_start_line_pos) {
            ok = 0;
        }

        if (ok != 0) {
            start_x = (event->intermediate_y_line_segment / 2 +
                       event->Y_line_pos * 2) -
                      this->special_events_pic_hgt / 2;
            local_4 = half_width;
        }
    }

    switch (event->event) {
    case 0:
    {
        int text_x;
        event->text_length1 = strlen(event->text1);
        text_x = event->X_line_pos;
        bounds_result = this->body_font_wid * event->text_length1;
        if (bounds_result + 2 + text_x >=
            this->X_line_max_width + this->X_start_line_pos) {
            start_y = this->X_line_max_width - bounds_result - 3 +
                      this->X_start_line_pos;
        } else {
            start_y = text_x + 2;
        }
        bounds_result = event->Y_line_pos +
                        event->intermediate_y_line_segment -
                        this->body_font_hgt;
        break;
    }

    case 1:
        event->text_length1 = strlen(event->text1);
        bounds_result = this->body_font_wid * event->text_length1;
        if (bounds_result + 2 + event->X_line_pos >=
            this->X_line_max_width + this->X_start_line_pos) {
            start_y = this->X_line_max_width - bounds_result - 8 +
                      this->X_start_line_pos;
        } else {
            start_y = event->X_line_pos + 2;
        }
        bounds_result = event->Y_line_pos;
        if (this->body_font_hgt + 2 + bounds_result >=
            this->Y_start_line_pos + this->Y_line_max_length) {
            bounds_result = this->Y_start_line_pos +
                            this->Y_line_max_length -
                            this->body_font_hgt - 2;
            goto store_location;
        }
        goto top_location;

    case 2:
    {
        event->text_length1 = strlen(event->text1);
        bounds_result = this->body_font_wid * event->text_length1;
        int case2_x;
        if (bounds_result + 2 + event->X_line_pos >=
            this->X_line_max_width + this->X_start_line_pos) {
            case2_x = this->X_line_max_width - bounds_result - 3 +
                      this->X_start_line_pos;
        } else {
            case2_x = event->X_line_pos + 2;
        }
        bounds_result = event->Y_line_pos +
                        event->intermediate_y_line_segment -
                        this->body_font_hgt;
        start_y = case2_x;
        break;
    }

    default:
        goto store_location;

    case 6:
    {
        int top;
        int max_length;
        int body_height;
        if ((int)(strlen(event->text1) * this->body_font_wid +
                  event->X_line_pos) >
            this->X_start_line_pos + this->X_line_max_width) {
            event->text_length1 =
                (this->X_start_line_pos + this->X_line_max_width -
                 event->X_line_pos) / this->body_font_wid;
        } else {
            event->text_length1 = strlen(event->text1);
        }
        if (event->text_length1 > 2) {
            event->text_length1 = 2;
        }
        bounds_result = this->special_events_pic_hgt;
        body_height = this->body_font_hgt;
        max_length = this->Y_line_max_length;
        top = this->Y_start_line_pos;
        if (start_x + body_height + 1 + bounds_result > max_length + top) {
            start_x = (max_length - body_height) - bounds_result - 1 + top;
        }
        start_y = local_4;
        bounds_result = start_x + 1 + bounds_result;
        goto store_location;
    }

    case 8:
    {
        int top;
        int max_length;
        int body_height;
        if ((int)(strlen(event->text1) * this->body_font_wid +
                  event->X_line_pos) >
            this->X_start_line_pos + this->X_line_max_width) {
            event->text_length1 =
                (this->X_start_line_pos + this->X_line_max_width -
                 event->X_line_pos) / this->body_font_wid;
        } else {
            event->text_length1 = strlen(event->text1);
        }
        if (event->text_length1 > 5) {
            event->text_length1 = 5;
        }
        bounds_result = this->special_events_pic_hgt;
        body_height = this->body_font_hgt;
        max_length = this->Y_line_max_length;
        top = this->Y_start_line_pos;
        if (start_x + body_height + 1 + bounds_result > max_length + top) {
            start_x = (max_length - body_height) - bounds_result - 1 + top;
        }
        start_y = local_4;
        bounds_result = start_x + 1 + bounds_result;
        goto store_location;
    }
    }

    bounds_result -= 2;
    {
        int top = this->Y_start_line_pos;
        if (top < bounds_result) {
            int bottom = this->Y_line_max_length + top;
            if (bottom <= bounds_result) {
                bounds_result = bottom - this->body_font_hgt - 3;
            }
        } else {
            bounds_result = top + 2;
        }
    }
    goto store_location;

top_location:
    bounds_result = event->Y_line_pos + 2;
    goto store_location;

store_location:
    event->start_x = local_4;
    event->start_txt_x1 = start_y;
    event->start_y = start_x;
    event->start_txt_y1 = bounds_result;
    if (ok != 0) {
        event->icon_flag = 1;
    }
    return ok;
}

// attempt 1: direct Time_Line_Panel draw path using the panel dump offsets and the known helper sequence
// target shape: base draw, clear +0x38, gate on +0x20/+0x70/+0x6C, then vcall +0x28, helpers, and vcall +0x2C
// BINARY NOTE: the panel setup and finish calls use the inherited draw_setup and draw_finish slots.


void Time_Line_Panel::draw(void) {
    TPanel::draw();
    this->need_redraw = 0;
    if (this->render_area != 0 && this->visible != 0 && this->active != 0) {
        this->draw_setup(0);
        this->draw_background();
        this->draw_border();
        this->draw_axis();
        this->draw_timeline();
        this->draw_special_events();
        this->draw_civilization_names();
        this->draw_finish();
    }
}

// VA: 0051FA90 Time_Line_Panel::draw_axis
// Attempt log:
// - The prior rough source used a raw palette pointer, wrong GDI calls, wrong
//   string helper, and four-argument FillRect calls. It was not a valid source
//   reconstruction.
// - Rebuilt the panel geometry from the exact tpnl_tml.cpp donors and the
//   original call order. The palette belongs to DrawSystem::Pal. The axis is
//   four typed FillRect calls with the saved palette index as the fifth arg.
// - Baseline: this typed source reached 744 bytes with all 38 calls ordered,
//   but the third and fourth top edges lacked Y_axis_length.
// - Added the proven Y_axis_length terms. The result reached 762 bytes and
//   exposed the original centered-label load order.
// - Split centered-label x placement into ordered statements. This restored
//   the X_start_line_pos reload before strlen and produced an exact match.
// Exact: 760/760 bytes, 0 strict diff, exact frame/call/CFG/relocation identity.


extern char s_tpnl_tml_draw_axis[];


void Time_Line_Panel::draw_axis()
{
    HGDIOBJ old_font;
    char temp_str[100];
    uchar white_color;

    white_color = (uchar)GetNearestPaletteIndex(
        this->render_area->DrawSystem->Pal, 0xFFFFFF);

    if (this->render_area->Lock(s_tpnl_tml_draw_axis, 1) != 0) {
        this->render_area->FillRect(
            this->xPosition() + 0x19,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0C
                + this->Y_axis_length,
            this->xPosition() + 0x18 + this->X_axis_length,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D
                + this->Y_axis_length,
            white_color);

        this->render_area->FillRect(
            this->xPosition() + 0x19,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D,
            this->xPosition() + 0x18 + this->X_axis_length,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0E,
            white_color);

        this->render_area->FillRect(
            this->xPosition() + 0x19,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D,
            this->xPosition() + 0x1A,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D
                + this->Y_axis_length,
            white_color);

        this->render_area->FillRect(
            this->xPosition() + 0x17 + this->X_axis_length,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D,
            this->xPosition() + 0x18 + this->X_axis_length,
            this->yPosition() + this->axis_font_hgt * 2 + 0x0D
                + this->Y_axis_length,
            white_color);
    }

    this->render_area->Unlock(s_tpnl_tml_draw_axis);
    if (this->render_area->GetDc(s_tpnl_tml_draw_axis) != 0) {
        SetBkMode(this->render_area->DrawDc, 1);
        old_font = SelectObject(this->render_area->DrawDc, this->axis_font);

        if (this->get_string(0x2C57, temp_str, 100) != 0) {
            int x = this->xPosition() + 8;
            int y = this->yPosition() + 5;
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            TextOutA(this->render_area->DrawDc, x, y, temp_str,
                     strlen(temp_str));
        }

        if (this->get_string(0x2C56, temp_str, 100) != 0) {
            int x = this->X_start_line_pos;
            x -= (strlen(temp_str) * this->axis_font_wid) / 2;
            x += this->X_axis_length / 2;
            int y = this->height();
            y += this->yPosition();
            y -= this->axis_font_hgt + 5;
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            TextOutA(this->render_area->DrawDc, x, y, temp_str,
                     strlen(temp_str));
        }

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_tml_draw_axis);
    }
}

// 0051FD90 Time_Line_Panel::draw_special_events (tpnl_tml.cpp:923-1055)
// Attempt log:
// - Existing baseline used an incorrect EventNode layout, IsLocked/TextOut switch,
//   and a sub-esp frame; it was 674 bytes but only 73.7% call-site aligned.
// - Reconstructed the period TDrawSystem/TDrawArea palette ownership, exact
//   Special_Events offsets, Lock->Unlock->GetDc lifecycle, and the two switch
//   families from the executable packet.  The first compile is the current
//   structural hypothesis; further probes will focus on switch duplication and
//   text-expression source order.
// - Correct palette ownership changed the two calls to load TDrawSystem::Pal
//   ([draw_area]->[0]->[8]) and brought the ordered call set to 19/19.
// - Direct per-case draw_icon calls preserved a clean natural source but left
//   four duplicated pushes for the -1 position; the shared-local/goto variants
//   added a stack home and were rolled back as less plausible and farther.
// - Removing named x/y temporaries from the type-3 text path kept the frame
//   smaller and improved the resynchronized diff; the nearest-pointer scope
//   and shared iterator/lifetime probes emitted duplicate code.
// - Independent named strlen temporaries caused a larger frame.  The final
//   natural expression keeps the two binary-observed strlen scans inline, so
//   VC5 pushes the TextOut length before yPosition and rescans for centering.
// - Grouping event types 0..3 at one draw_icon body with the shared -1
//   position is the current best source reconstruction: exact size/frame,
//   19/19 ordered calls, 95.53% shape, 86.18% exact blocks. Main-agent string
//   normalization improved the strict diff from 570 to 569 bytes. The
//   remaining drift begins in the first switch's byte-load/jump-table shape;
//   budget exhausted without a source-plausible exact lead.
// - Tried one natural loop-local event code for the draw switch; it improved
//   strict diff to 479 bytes but added 74 bytes and lost block parity, so it
//   was rolled back as a nonviable lifetime hypothesis.
// - Tried source-order-separated constant draw_icon cases.  This reproduced
//   the original xor/mov-al jump-table load and improved strict diff to 419,
//   but duplicated the shared call tail, added 74 bytes, and crossed the
//   function boundary.  Rolled back.
// - Tried shared draw_icon tails with int locals, mixed-width locals, and the
//   function-scope short/uchar variables suggested by the decompiler.  These
//   all changed the prologue or added 102-142 bytes.  Rolled back; the clean
//   grouped switch remains the source-authoritative candidate.
// - Revisit probes: period Windows/import and decorated string declarations
//   changed the call basin without improving the target; explicit constant
//   cases, a decompiler-shaped goto tail, and named lower-y locals added
//   74-146 bytes or an ESP frame.  Reversing the lower y expression recovered
//   the binary yPosition-before-height call order at unchanged whole metrics.
//   Local declaration order, an explicit int switch cast, a separate first-loop
//   pointer, and an explicit default edge were unchanged.  An 8-state variant
//   lab confirmed only two code groups: the grouped source kept 674 bytes and
//   the constant-case source grew to 756 bytes.  No exact lead was found.
// - This claim's focused probes established that first-switch source case order
//   0, 1, 2, 4, 5, 6, 7, 8, 3 reproduces the target's immediate pushes and
//   shared -1 tail from +0055 through +00A6.  It reached 419 strict-diff bytes
//   and 91.46% exact-block coverage, but VC5 emitted 74 bytes of switch-table
//   data after the function boundary.  Separate second-scan pointers and
//   declaration-order variants did not change that output.  Repeated ternary
//   expressions moved the second event pointer to EBX but lost the target's
//   evaluation order and broad block parity.  The clean grouped source remains
//   authoritative; the late first-switch case order is the next lead.


void Time_Line_Panel::draw_special_events()
{
    Special_Events* event;
    HGDIOBJ old_font;

    if (this->timeline_flag != 0) {
        {
            unsigned int (__stdcall* nearest)(void*,
                                              unsigned int) =
                GetNearestPaletteIndex;
            nearest(this->render_area->DrawSystem->Pal, 0xFFFFFF);
            nearest(this->render_area->DrawSystem->Pal, 0);
        }

        if (this->render_area->Lock("tpnl_tml::draw_special_events", 1) != 0) {
            for (event = this->time_slice_events;
                 event != 0; event = event->next) {
                switch (event->event) {
                case 0:
                case 1:
                case 2:
                case 3:
                    this->draw_icon(event, -1, event->event);
                    break;
                case 4:
                    this->draw_icon(event, 0, 4);
                    break;
                case 5:
                    this->draw_icon(event, 1, 5);
                    break;
                case 6:
                    this->draw_icon(event, 2, 6);
                    break;
                case 7:
                    this->draw_icon(event, 3, 7);
                    break;
                case 8:
                    this->draw_icon(event, 4, 8);
                    break;
                }
            }
        }

        this->render_area->Unlock("tpnl_tml::draw_special_events");
        if (this->render_area->GetDc("tpnl_tml::draw_special_events") != 0) {
            SetBkMode(this->render_area->DrawDc, 1);
            old_font = SelectObject(this->render_area->DrawDc,
                                    this->body_font);

            for (event = this->time_slice_events;
                 event != 0; event = event->next) {
                switch (event->event) {
                case 0:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc,
                             event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 1:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc,
                             event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 2:
                    SetTextColor(this->render_area->DrawDc, 0);
                    TextOutA(this->render_area->DrawDc,
                             event->start_txt_x1, event->start_txt_y1,
                             event->text1, event->text_length1);
                    break;
                case 3: {
                    int x_offset = (event->time_slice != 0) ? -2 : 2;
                    SetTextColor(this->render_area->DrawDc, 0xFFFFFF);

                    TextOutA(this->render_area->DrawDc,
                             x_offset - (strlen(event->text1) >> 1)
                                 * this->axis_font_wid
                                 + event->X_line_pos,
                             this->yPosition() + 8 + this->axis_font_hgt,
                             event->text1, strlen(event->text1));
                    TextOutA(this->render_area->DrawDc,
                             x_offset - (strlen(event->text2) >> 1)
                                 * this->axis_font_wid
                                 + event->X_line_pos,
                             this->height() + this->yPosition()
                                 - this->axis_font_hgt * 2 - 7,
                             event->text2, strlen(event->text2));
                    break;
                }
                case 6:
                    if (event->icon_flag != 0) {
                        SetTextColor(this->render_area->DrawDc, 0);
                        TextOutA(this->render_area->DrawDc,
                                 event->start_txt_x1, event->start_txt_y1,
                                 event->text1, event->text_length1);
                    }
                    break;
                case 8:
                    if (event->icon_flag != 0) {
                        SetTextColor(this->render_area->DrawDc, 0);
                        TextOutA(this->render_area->DrawDc,
                                 event->start_txt_x1, event->start_txt_y1,
                                 event->text1, event->text_length1);
                    }
                    break;
                }
            }

            SelectObject(this->render_area->DrawDc, old_font);
            this->render_area->ReleaseDc("tpnl_tml::draw_special_events");
        }
    }
}

// 00520080 Time_Line_Panel::draw_background
// Source: tpnl_tml.cpp lines 1062-1120
// Attempt log:
// 1: natural decompiler-shaped tiling/fill/bevel paths; behavior/call set close, edit diff ~86B.
// 2: fixed the height tile-count source to match the original's odd uninitialized-local fallthrough when pic_h < panel_h; edit diff improved to 76B.
// 3: tried y-coordinate named local before shape_draw; VC5 optimized to the same scheduling.
// 4: tried reversed x/y expression term order; no codegen change.
// 5: tried void return for TShape::shape_draw; no codegen change.
// 6: tried narrow unsigned-char zero args for shape_draw tail parameters; no codegen change.
// 7: tried explicit draw_x/draw_y locals; no codegen change.
// 8: tried compound assignment draw_y/draw_x spelling to force original register sequence; no codegen change.
// 9: tried swapping local declaration order; no codegen change.
// 10: tried short locals and for-loop spelling; worsened diff, reverted.
// 11: corrected TShape::shape_draw to the executable unsigned-char/long/uchar ABI;
//     emitted code was unchanged, but the living declaration now has the exact symbol surface.
// 12: mirrored the same-TU donor's y-then-x named temporaries; VC5 emitted the
//     same tiled loop, so the direct canonical expressions were restored.
// 13: made both tile-count locals short without casts; this worsened the height
//     branch and was restored to the int locals that preserve the observed stack stores.
// 14: fresh pass reversed the coordinate terms to the exact Pnl_txt donor form;
//     VC5 emitted the unchanged tiled loop.
// 15: fresh pass materialized long draw_y/draw_x locals with compound additions;
//     VC5 optimized them to the unchanged loop.
// 16: fresh pass declared draw_x before draw_y, following exact terrain-shape
//     register-coloring evidence; the emitted code was unchanged.
// 17: fresh pass declared typed int draw_y before draw_x in shape_draw, following
//     the exact Pnl_txt donor's source order; emitted code was unchanged.
// 18: natural typed lead from the exact Pnl_txt timeline donor: expose the
// period TShape data surface and SDK context while retaining the target ABI.
//    This moved the tiled loop to exact shape and reduced strict drift to 15
//    register-encoding bytes; the remaining hunk is count-setup register color.
// 19: narrowed the width tile-count local to short; VC5 emitted the same 15-byte
//     register-color drift, so the change was not retained as a codegen lead.
// 20: narrowed the height tile-count local to short; this added four bytes and
//     changed the loop shape, so it was restored.
// 21: removed temporary width/height locals and used direct panel members, as in
//     the exact Pnl_txt donor; this produced an exact 412-byte match.



void Time_Line_Panel::draw_background()
{
    int pic_rows;
    int tile_rows;

    if (this->background_pic != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_background", 1) == 0) {
            return;
        }

        if (this->background_pic_wid >= this->pnl_wid) {
            pic_rows = 1;
        } else {
            pic_rows = this->pnl_wid / this->background_pic_wid;
            if ((short)pic_rows * this->background_pic_wid < this->pnl_wid) {
                pic_rows++;
            }
        }

        if (this->background_pic_hgt >= this->pnl_hgt) {
            tile_rows = this->pnl_hgt / this->background_pic_hgt;
            if ((short)tile_rows * this->background_pic_hgt < this->pnl_hgt) {
                tile_rows++;
            }
        }

        if ((short)tile_rows > 0) {
            int row = 0;
            tile_rows = (short)tile_rows;
            do {
                if ((short)pic_rows > 0) {
                    int col = 0;
                    int count = (short)pic_rows;
                    do {
                        this->background_pic->shape_draw(this->render_area,
                            col * this->background_pic_wid + this->pnl_x,
                            row * this->background_pic_hgt + this->pnl_y,
                            0, 0, 0);
                        col++;
                        count--;
                    } while (count != 0);
                }
                row++;
                tile_rows--;
            } while (tile_rows != 0);
        }

        this->render_area->Unlock("tpnl_tml::draw_background");
        return;
    }

    if (this->fill_back != 0) {
        if (this->render_area->Lock("tpnl_tml::draw_background2", 1) == 0) {
            return;
        }
        this->render_area->FillRect(this->pnl_x, this->pnl_y,
            this->pnl_x + this->pnl_wid - 1,
            this->pnl_y + this->pnl_hgt - 1,
            this->back_color);
        this->render_area->Unlock("tpnl_tml::draw_background2");
        return;
    }

    if (this->parent_panel != 0) {
        if (this->bevel_type >= 2 && this->bevel_type <= 7) {
            this->parent_panel->draw_rect2(&this->clip_rect);
            return;
        }
        if (this->parent_panel->just_drawn == 0) {
            this->parent_panel->draw_rect(&this->clip_rect);
        }
    }
}

// VA: 00520220 Time_Line_Panel::draw_civilization_names
// Attempt log:
// try 1: natural reconstruction from packet/Ghidra with GDI IAT function-pointer surface, game/world/player/history minimal layouts.
// try 2: initial source compiled exact-size 626 but broad drift: frame 0x148 vs original 0x144 and this kept in EBX instead of EBP.
// try 3: nested-control-flow form instead of early returns; still frame 0x148 and this kept in EBX.
// try 4: raw byte-offset player indexing for the population scan; reduced output to 624 bytes but did not recover original prologue/register allocation.
// try 5: raw byte-offset player indexing for the draw loop; same family, original wants EBX as player-array byte offset only after 00520333.
// try 6: /GX tested; no useful change, removed.
// try 7: /Od tested; exact size but completely wrong debug-basin codegen, removed.
// try 8: corrected RGE_Base_Game get_string virtual slot to +0x28; call surface now matches original vtable offset but size/register drift remains.
// try 9: kept GDI calls as extern function pointers to preserve indirect IAT call style.
// try 10: leaving in scratch: clean behavioral source was 624B vs 626B with immediate prologue/frame/register mismatch.
// try 11: corrected get_history_entry to its unsigned-char/long ABI; bytes were unchanged.
// try 12: added the period Windows/TPanel/TEasy_Panel surface and exact DrawDc ownership; size stayed 613B but the edit alignment improved.
// try 13: removed the cached second-loop player alias and restored the binary-proven repeated player-array reloads; exact 626B match.
// BINARY NOTE: the five-argument call at vtable +0x28 is RGE_Base_Game::get_string2.
// Exact: 626/626 bytes, 0 strict diff, exact frame/call/CFG/relocation identity.  The two named byte cursors are retained because the
// oracle has independent [players+offset] induction registers in both scans and the repeated player loads are observable; this is a
// period-plausible pointer-array traversal rather than an opaque address or register-forcing alias.


void Time_Line_Panel::draw_civilization_names()
{
    char temp_str[100];
    char civ_str[100];
    char name_str[100];
    HGDIOBJ old_font;
    int X_line_pos;
    int Y_line_pos;
    int y_line_segment_length;
    float pop_total;

    if (this->timeline_flag != 0) {
        SetTextColor(this->render_area->DrawDc, 0);
        if (this->render_area->GetDc("tpnl_tml::draw_civilization_names") != 0) {
            SetBkMode(this->render_area->DrawDc, 1);
            old_font = SelectObject(this->render_area->DrawDc, this->body_font);
            pop_total = 0.0f;
            int i = 0;
            if (rge_base_game->world->player_num - 1 > 0) {
                int off = 4;
                do {
                    pop_total += (float)((*(RGE_Player**)((char*)rge_base_game->world->players + off))->history_info->get_history_entry(0,0) & 0xff);
                    i++;
                    off += 4;
                } while (i < rge_base_game->world->player_num - 1);
            }
            if (pop_total != 0.0f) {
                X_line_pos = this->X_start_line_pos + 3;
                Y_line_pos = this->Y_start_line_pos;
                if (rge_base_game->world->player_num - 1 > 0) {
                    y_line_segment_length = 0;
                    int off2 = 4;
                    do {
                        int seg = (int)(((float)((*(RGE_Player**)((char*)rge_base_game->world->players + off2))->history_info->get_history_entry(0,0) & 0xff) / pop_total) * (float)this->Y_line_max_length);
                        rge_base_game->get_string2(0x69, (*(RGE_Player**)((char*)rge_base_game->world->players + off2))->civilization, 0, civ_str, 100);
                        strcpy(name_str, (*(RGE_Player**)((char*)rge_base_game->world->players + off2))->name);
                        sprintf(temp_str, "%s - %s", name_str, civ_str);
                TextOutA(this->render_area->DrawDc, X_line_pos, Y_line_pos + (seg / 2 - this->body_font_hgt / 2), temp_str, strlen(temp_str));
                        Y_line_pos += seg;
                        off2 += 4;
                        y_line_segment_length++;
                    } while (y_line_segment_length < rge_base_game->world->player_num - 1);
                }
                SelectObject(this->render_area->DrawDc, old_font);
                this->render_area->ReleaseDc("tpnl_tml::draw_civilization_names");
            }
        }
    }
}

// VA: 005204A0 Time_Line_Panel::draw_timeline (1565 bytes)
// Source: tpnl_tml.cpp lines 1191-1427
// Attempt log:
// - Initial bounded reconstruction from packet/Ghidra, preserving the original nested player scans,
//   switch color dispatch, x87 conversion expressions, and early-return behavior.
// - Probe: removed the decompiler-only special-event counter; original increment has no later read.
// - Probe: restored the packet's overlapping pop_total/event local and its zero initialization.
// - Structural probe: restored donor-proven byte-cursor scans and the original fractional segment
//   correction/local counter topology; replaced diagnostic _ftol stubs with typed conversions.
// - Probe: promoted the repeated segment temporary to the named local lifetime used by the draw loop.
// - Probe: typed conversion and outer-temporary variants preserved the 19-call set but did not
//   reduce the 0x64 frame; the prior clean result was 1565 bytes and 56.5% shape.
// - Probe: the binary's repeated player guard is `player_num - 1 > 0`; the simpler guard improved
//   CFG parity from 37/41 to 37/38 conditions.
// - Probe: direct repeated world/player expressions remove cached object homes and improve shape
//   to 65.5%; the candidate is 1616 bytes with a 0x5C frame and 19 aligned calls.
// - Probe: reusing local_38 as the inner player cursor is codegen-duplicate evidence.
// - Probe: modeled history samples as a float time_slice and kept the returned sample in a signed dword temp;
//   this reached the original 0x50/0x54 frame basin and reduced strict drift to 1337 bytes.
// - Probe: separated the 32-bit switch palette input from the byte palette-index result; this preserved the
//   original EAX switch constants and reduced strict drift to 1300 bytes with 73.7% shape similarity.
// - Probe: ordered the Y-line total load before the explicit sample conversion; the current clean source is
//   1600 bytes with a 0x50 frame, 19 aligned calls, and 1299-byte strict drift.
// - Current claim probes 1-20: tested loop forms, local types and order, interpolation groupings,
//   canonical class context, and Windows header context. Header context and alternate loop forms did not
//   improve strict output. Duplicate codegen ruled out several declaration and cast variants.
// - Binary-supported recovery: the inner bar loop has independent intermediate_x_pos and special_event_flag
//   counters. The stack uses [esp+4Ch] for interpolation and [esp+48h] for first-column event gating.
//   Restoring both counters reaches the original 0x54 frame and 19-call set, but remains nonexact at 1620
//   bytes, 70.04% shape, and 1310 strict-drift bytes. The pinned final source keeps this natural model.
// - Unresolved: initial local-home permutation, early page/history CFG layout, and x87 sample conversion
//   scheduling still differ. The separate bar_length local is retained because its source form is closer
//   than the binary-overlapped reuse variant; no unsupported register steering or inline assembly was used.
// - Follow-up claim probes 21-33 tested outer-loop forms, local scope and width, operand order, accumulator
//   forms, x87 interpolation ownership, and address-taken sample storage. No probe improved the clean bytes.
// - Final clean result: 1620 emitted bytes versus 1565, 0x54 frame, 19 ordered calls, 70.04% shape,
//   and 1310 strict-drift bytes. Keep the simplest two-counter source until new binary evidence appears.



void Time_Line_Panel::draw_timeline()
{
    unsigned char event;
    float pop_total;
    float temp_pop_num;
    float time_slice;
    long next_pop_total;
    float float_remainder;
    float cntr_droped_slice_rate;
    long pop_sample_cntr;
    int local_38;
    int local_34;
    long error_correction_drop_time_slice_rate;
    long time_slice_cntr;
    int local_28;
    long Y_line_total;
    long cntr2;
    long intermediate_x_pos;
    long error_correction_time_slice_thickness;
    int local_10;
    long y_line_segment_length;
    long temp_color;
    long segment;
    int special_event_flag;

    if (this->timeline_flag == 0) return;

    if (this->render_area->Lock((char*)0x58B820, 1) == 0) return;

    this->X_line_pos = this->X_start_line_pos;
    local_38 = 0;
    local_10 = 0;
    time_slice_cntr = 0;
    pop_sample_cntr = 0;
    local_28 = 0;
    next_pop_total = 0;

    if (this->num_history_entries > 0) {
        error_correction_drop_time_slice_rate = 1;
        do {
            if (local_28 >= this->num_entries_page) break;

            temp_pop_num = 0.0f;
            error_correction_time_slice_thickness = 0;
            int i = 0;
            if ((int)rge_base_game->world->player_num - 1 > 0) {
                int player_offset = 4;
                do {
                    temp_color = (*(TRIBE_Player**)((char*)rge_base_game->world->players + player_offset))
                        ->history_info->get_history_entry(0, (long)next_pop_total);
                    time_slice = (float)temp_color;
                    if ((*(TRIBE_Player**)((char*)rge_base_game->world->players + player_offset))
                            ->history_info->get_history_event((long)next_pop_total, event) != 0) {
                        error_correction_time_slice_thickness = 1;
                    }
                    temp_pop_num = time_slice + temp_pop_num;
                    i++;
                    player_offset += 4;
                } while (i < (int)rge_base_game->world->player_num - 1);
            }

            if (temp_pop_num == 0.0f) return;

            long drop_rate = (long)this->time_slice_drop_rate;
            long scaled_drop = (long)((float)error_correction_drop_time_slice_rate *
                                      this->time_slice_drop_rate);
            long error_correction = scaled_drop + (1 - error_correction_drop_time_slice_rate) * drop_rate - time_slice_cntr;
            if ((this->drop_flag == 0) || (error_correction_time_slice_thickness != 0) ||
                (pop_sample_cntr < error_correction) ||
                (error_correction_drop_time_slice_rate - 1 >= this->total_slices_to_drop)) {
                pop_sample_cntr++;
                local_28++;

                if (next_pop_total == this->num_entries_page - 1) {
                    float_remainder = temp_pop_num;
                } else {
                    float_remainder = 0.0f;
                    i = 0;
                    if ((int)rge_base_game->world->player_num - 1 > 0) {
                        int player_offset = 4;
                        do {
                            temp_color = (*(TRIBE_Player**)((char*)rge_base_game->world->players + player_offset))
                                ->history_info->get_history_entry(0, next_pop_total + 1);
                            float_remainder = (float)temp_color + float_remainder;
                            i++;
                            player_offset += 4;
                        } while (i < (int)rge_base_game->world->player_num - 1);
                    }
                    if (float_remainder == 0.0f) return;
                }

                if ((local_28 == this->pop_reading_rate - 1) || (next_pop_total == 0)) {
                    this->add_pop_total_special_event(next_pop_total,
                        (long)temp_pop_num, this->X_line_pos, 1);
                    local_28 = 0;
                } else {
                    local_28++;
                }

                y_line_segment_length = (long)next_pop_total + 1;
                long y_line_length =
                    (long)((float)y_line_segment_length * this->bar_thickness);
                long bar_length = (long)this->bar_thickness;
                if (bar_length * y_line_segment_length < y_line_length - local_10) {
                    bar_length = (y_line_length - local_10) - bar_length * y_line_segment_length + bar_length;
                    local_10++;
                }
                intermediate_x_pos = 0;
                special_event_flag = 0;
                if (bar_length > 0) {
                    do {
                        this->Y_line_pos = this->Y_start_line_pos;
                        cntr2 = 0;
                        cntr_droped_slice_rate = 0;
                        local_34 = 0;
                        if ((int)rge_base_game->world->player_num - 1 > 0) {
                            local_38 = 4;
                            do {
                                unsigned long palette_color;
                                unsigned char color;
                                switch ((*(TRIBE_Player**)((char*)rge_base_game->world->players + local_38))
                                            ->details->civilization) {
                                case 0: palette_color = 0x00C40000; break;
                                case 1: palette_color = 0x000000C8; break;
                                case 2: palette_color = 0x0000EAEA; break;
                                case 3: palette_color = 0x00215A8C; break;
                                case 4: palette_color = 0x000080FF; break;
                                case 5: palette_color = 0x00008000; break;
                                case 6: palette_color = 0x00808080; break;
                                case 7: palette_color = 0x00808040; break;
                                default: palette_color = 0x00FFFFFF; break;
                                }
                                color = GetNearestPaletteIndex((*(void***)this->render_area)[2], palette_color);
                                temp_color = (long)(*(TRIBE_Player**)((char*)rge_base_game->world->players + local_38))
                                    ->history_info->get_history_entry(0, next_pop_total);
                                Y_line_total = this->Y_line_max_length;
                                time_slice = (float)temp_color;
                                temp_pop_num = (time_slice / temp_pop_num) *
                                                (float)Y_line_total;
                                segment = (long)temp_pop_num;
                                if ((time_slice >= 1.0f) && (segment < 1)) segment = 1;

                                if (this->bar_thickness != 1.0f) {
                                    if (next_pop_total != this->num_entries_page - 1) {
                                        time_slice = (float)(*(TRIBE_Player**)((char*)rge_base_game->world->players + local_38))
                                            ->history_info->get_history_entry(0, y_line_segment_length);
                                    }
                                    Y_line_total = this->Y_line_max_length;
                                    long next_segment = (long)(time_slice /
                                                               float_remainder *
                                                               (float)Y_line_total);
                                    long difference = next_segment - segment;
                                    temp_pop_num = (float)segment +
                                                    (float)difference *
                                                    ((float)intermediate_x_pos / this->bar_thickness);
                                    segment = (long)temp_pop_num;
                                    if ((time_slice >= 1.0f) && (segment < 1)) segment = 1;
                                    cntr_droped_slice_rate += temp_pop_num - (float)segment;
                                    if (cntr_droped_slice_rate > 1.0f) {
                                        cntr_droped_slice_rate -= 1.0f;
                                        segment++;
                                    }
                                }

                                if (local_34 == (int)rge_base_game->world->player_num - 2) {
                                    if (Y_line_total < segment + cntr2) segment = Y_line_total - cntr2;
                                    if (segment + cntr2 < Y_line_total) segment = Y_line_total - cntr2;
                                }

                                this->render_area->DrawVertLine(this->X_line_pos, this->Y_line_pos, segment, (unsigned char)color);
                                if (special_event_flag == 0) {
                                this->record_special_event((unsigned char)(local_34 + 1),
                                    (*(TRIBE_Player**)((char*)rge_base_game->world->players + local_38))->history_info,
                                        (unsigned char)color, next_pop_total, this->X_line_pos,
                                        this->Y_line_pos, segment);
                                }
                                this->Y_line_pos += segment;
                                cntr2 += segment;
                                local_34++;
                                local_38 += 4;
                            } while (local_34 < (int)rge_base_game->world->player_num - 1);
                        }
                        intermediate_x_pos++;
                        special_event_flag++;
                        this->X_line_pos++;
                    } while (intermediate_x_pos < bar_length);
                }
            } else {
                error_correction_drop_time_slice_rate++;
                pop_sample_cntr = 0;
                if (error_correction_drop_time_slice_rate > drop_rate) time_slice_cntr++;
            }
            next_pop_total++;
        } while (next_pop_total < this->num_history_entries);
    }

    this->render_area->Unlock((char*)0x58B820);
}

// Attempt log for 00520AE0 Time_Line_Panel::draw_icon
// try 1: natural reconstruction from packet/decompiler with minimal surfaces; too small 528B.
// try 2: add all post-location draw cases and closer decompiler fields; exact size but EBP=this, no IAT ptr local, wrong palette +8 load.
// try 3: use self local, explicit GetNearestPaletteIndex function-pointer local, and palette[2] expression; edit diff improved to 31.5%, but EBP=this instead of EBX=this.
// try 4: predeclare minute/hour locals at top to encourage EBP as arithmetic local; no codegen change.
// try 5: /O1 flag probe; too small 422B, rolled back.
// try 6: /Oy- flag probe; worse from offset 0, rolled back.
// try 7: remove self local and use direct this to probe EBX allocation; no change.
// try 8: remove getNearest local and call import pointer directly; worse (75.7%/33.9%), rolled back.
// try 9: restore getNearest local best form.
// try 10: reviewed switch vs if-chain; switch dispatch matches original jump-table family, so kept.
// BLOCKER: exact 581B size, call set and much of structure plausible, but register allocation remains wrong from prologue (rebuilt EBP=this, original EBX=this with EBP used later for hour quotient). This shifts all this-relative encodings and broad positional diff. Not accepted_drift-safe.
// worker probe 2: corrected Special_Events ownership/layout, inherited TPanel/TEasy_Panel context, and the six-argument TShape ABI; 315B diff, exact size/frame/call set.
// worker probe 3: replaced gap-only panel declarations with the ground-truth typed member surfaces; emitted code was unchanged.
// worker probes 4-5: reordered/widened time-format locals; emitted code was unchanged.
// worker probe 7: restored the binary-proven seconds -> zero-minute -> optional-hour source semantics; 8 differing bytes remain, all temp_str+4 stack displacement bytes.
// worker probes 6/8: declaration-order variant families for arithmetic and local declarations collapsed to one emitted group.
// worker probe 9: minimal RECT/header-context variant emitted the same 8-byte drift.
// worker probe 10: a synthetic union overlay reduced no bytes and changed the frame to 0x34; rolled back as implausible.
// worker probe 11: scoped temp_str to the event switch as a natural lifetime/scheduling lead; emitted code stayed unchanged at 8 bytes, rolled back.
// current worker probe 1: stored the palette result in typed temp_str[0]; the frame fell to 0x34 while the same eight displacement bytes remained.
// current worker probe 2: widened temp_str to 54 bytes for its four-byte palette prefix and 0x32-byte text destination; exact 581-byte match.
// Best current reconstruction is the typed period-style source below. The 54-byte temporary models the four-byte palette prefix and 0x32-byte text destination.


void Time_Line_Panel::draw_icon(Special_Events* ev, short param_2, uchar param_3)
{
    char temp_str[54];
    long total;
    long hi_top;
    long q_top;
    unsigned int (__stdcall* getNearest)(void*,
                                         unsigned int) =
        GetNearestPaletteIndex;
    getNearest(this->render_area->DrawSystem->Pal, 0xffffff);
    temp_str[0] = (char)getNearest(this->render_area->DrawSystem->Pal, 0);

    switch (ev->event) {
    case 0:
        if (this->get_string(0x106a, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 1:
        if (this->get_string(0x106b, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 2:
        if (this->get_string(0x106c, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 8:
        sprintf(temp_str + 4, "%ld/%1d", ev->integer_value_1, ev->integer_value_2);
        sprintf(ev->text1, "%s", temp_str + 4);
        // fall through
    case 3: {
        sprintf(ev->text1, "%ld", ev->pop_total);
        hi_top = 0;
        ev->text_length1 = strlen(ev->text1);
        q_top = 0;
        total = ev->time_slice * 15;
        if (total > 59) {
            q_top = total / 60;
            if (q_top > 59) {
                hi_top = q_top / 60;
                q_top = q_top - hi_top * 60;
            }
        }
        sprintf(temp_str + 4, "%1ld:%02ld", hi_top, q_top);
        sprintf(ev->text2, "%s", temp_str + 4);
        ev->text_length2 = strlen(ev->text2);
        break;
    }
    default:
        break;
    }

    int ok = this->calculate_icon_location(ev, param_2, param_3);
    switch (ev->event) {
    case 0:
            this->render_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, (uchar)temp_str[0]);
        return;
    case 1:
        this->render_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, (uchar)temp_str[0]);
        return;
    case 2:
        this->render_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, (uchar)temp_str[0]);
        return;
    default:
        if (ok) {
            this->special_events_pic->shape_draw(this->render_area, ev->start_x, ev->start_y,
                                    (int)param_2, 0, (uchar*)0);
        }
        return;
    }
}

void Time_Line_Panel::draw_legend() {
    if (this->special_events_pic != 0) {
        if (this->special_events_pic->shape_count() != 0) {
            width();
        }
    }
}

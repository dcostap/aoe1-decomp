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

#include "../../include/tpnl_tml_context.h"

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

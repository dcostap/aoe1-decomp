// 0047BCE0 TVerticalSliderPanel::TVerticalSliderPanel
// Source: pnl_sld.cpp lines 24-25
// Size: 38 bytes, 0.0000% MATCH
//
// Attempt log:
// Probe 1-2: vtable before fields (body assignments) — mismatch
// Probe 3: member initializer list (drawBox(1), spineWidth(0)) + empty body
//   → VC5 puts vtable AFTER member initialization → EXACT MATCH

#include "../../include/pnl_sld_context.h"

TVerticalSliderPanel::TVerticalSliderPanel()
    : TScrollBarPanel(), drawBox(1), spineWidth(0)
{
}

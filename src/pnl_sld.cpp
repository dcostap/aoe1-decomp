// Authentic PDB-ordered source module for C:\\msdev\\work\\age1_x1\\pnl_sld.cpp.
// The ten normal owners below follow the original source-line order.
// The scalar deleting destructors at 0047BD10 and 0047BE10 are compiler-generated.

#include "../include/pnl_sld.h"

// 0047BCE0 TVerticalSliderPanel::TVerticalSliderPanel(void)
// PDB: pnl_sld.cpp lines 24-25. Status: matching.
TVerticalSliderPanel::TVerticalSliderPanel()
    : TScrollBarPanel(), drawBox(1), spineWidth(0)
{
}

// 0047BD30 TVerticalSliderPanel::~TVerticalSliderPanel(void)
// PDB: pnl_sld.cpp line 30. Status: matching.
TVerticalSliderPanel::~TVerticalSliderPanel()
{
}

// 0047BD40 TVerticalSliderPanel::setup
// PDB: pnl_sld.cpp lines 39-54. Status: matching.
long TVerticalSliderPanel::setup(TDrawArea* param_1, TPanel* param_2,
                                long param_3, long param_4, long param_5,
                                long param_6, char* param_7, char* param_8,
                                long param_9, long param_10, long param_11,
                                long param_12, int param_13, int param_14)
{
    drawBox = param_13;
    spineWidth = param_14;

    if (TScrollBarPanel::setup(param_1, param_2, param_3, param_4, param_5,
                               param_6, param_7, 0, 0, param_8, 0, param_9,
                               0, param_10, TScrollBarPanel::Vertical) == 0) {
        return 0;
    }

    one_step = param_11;
    page_step = param_12;
    return 1;
}

// 0047BDC0 TVerticalSliderPanel::set_rect
// PDB: pnl_sld.cpp lines 60-75. Status: matching.
void TVerticalSliderPanel::set_rect(long param_1, long param_2, long param_3,
                                    long param_4)
{
    TScrollBarPanel::set_rect(param_1, param_2, param_3, param_4);
}

// 0047BDE0 TVerticalSliderPanel::draw(void)
// PDB: pnl_sld.cpp line 80. Status: matching.
void TVerticalSliderPanel::draw()
{
    TScrollBarPanel::draw();
}

// 0047BDF0 THorizontalSliderPanel::THorizontalSliderPanel(void)
// PDB: pnl_sld.cpp lines 126-127. Status: matching.
THorizontalSliderPanel::THorizontalSliderPanel()
    : TVerticalSliderPanel()
{
}

// 0047BE30 THorizontalSliderPanel::~THorizontalSliderPanel(void)
// PDB: pnl_sld.cpp line 132. Status: matching.
THorizontalSliderPanel::~THorizontalSliderPanel()
{
}

// 0047BE40 THorizontalSliderPanel::setup
// PDB: pnl_sld.cpp lines 141-156. Status: matching.
long THorizontalSliderPanel::setup(TDrawArea* param_1, TPanel* param_2,
                                  long param_3, long param_4, long param_5,
                                  long param_6, char* param_7, char* param_8,
                                  long param_9, long param_10, long param_11,
                                  long param_12, int param_13, int param_14)
{
    drawBox = param_13;
    spineWidth = param_14;

    if (TScrollBarPanel::setup(param_1, param_2, param_3, param_4, param_5,
                               param_6, param_7, 0, 0, param_8, 0, param_9,
                               0, param_10, TScrollBarPanel::Horizontal) == 0) {
        return 0;
    }

    one_step = param_11;
    page_step = param_12;
    return 1;
}

// 0047BEC0 THorizontalSliderPanel::set_rect
// PDB: pnl_sld.cpp lines 162-176. Status: matching.
void THorizontalSliderPanel::set_rect(long param_1, long param_2, long param_3,
                                      long param_4)
{
    TScrollBarPanel::set_rect(param_1, param_2, param_3, param_4);

    long left = pnl_x;
    long right = left + pnl_wid - 1;
    up_rect.left = left;
    up_rect.right = left;
    down_rect.left = right;
    down_rect.right = right;
    tab_min_x = left + 1;
    tab_max_x = right - pnl_hgt + 2;
    tab_x = left + 1;
    TScrollBarPanel::calc_item_rects();
}

// 0047BF30 THorizontalSliderPanel::draw(void)
// PDB: pnl_sld.cpp line 181. Status: matching.
void THorizontalSliderPanel::draw()
{
    TScrollBarPanel::draw();
}

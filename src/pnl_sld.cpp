
#include "../include/pnl_sld.h"

TVerticalSliderPanel::TVerticalSliderPanel()
    : TScrollBarPanel(), drawBox(1), spineWidth(0)
{
}

TVerticalSliderPanel::~TVerticalSliderPanel()
{
}

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

void TVerticalSliderPanel::set_rect(long param_1, long param_2, long param_3,
                                    long param_4)
{
    TScrollBarPanel::set_rect(param_1, param_2, param_3, param_4);
}

void TVerticalSliderPanel::draw()
{
    TScrollBarPanel::draw();
}

THorizontalSliderPanel::THorizontalSliderPanel()
    : TVerticalSliderPanel()
{
}

THorizontalSliderPanel::~THorizontalSliderPanel()
{
}

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

void THorizontalSliderPanel::draw()
{
    TScrollBarPanel::draw();
}


#include "../include/pnl_sld.h"

TVerticalSliderPanel::TVerticalSliderPanel()
    : TScrollBarPanel(), drawBox(1), spineWidth(0) {
}

TVerticalSliderPanel::~TVerticalSliderPanel() {
}

long TVerticalSliderPanel::setup(TDrawArea* renderAreaIn, TPanel* parentPanelIn,
                                long xIn, long yIn, long widthIn,
                                long heightIn, char* backPictureIn, char* thumbPictureIn,
                                long thumbHeightIn, long scaleIn, long one_step_in,
                                long page_step_in, int drawBoxIn, int spineWidthIn) {
    drawBox = drawBoxIn;
    spineWidth = spineWidthIn;

    if (TScrollBarPanel::setup(renderAreaIn, parentPanelIn, xIn, yIn, widthIn,
                               heightIn, backPictureIn, 0, 0, thumbPictureIn, 0, thumbHeightIn,
                               0, scaleIn, TScrollBarPanel::Vertical) == 0) {
        return 0;
    }

    one_step = one_step_in;
    page_step = page_step_in;
    return 1;
}

void TVerticalSliderPanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    TScrollBarPanel::set_rect(x_in, y_in, wid_in, hgt_in);
}

void TVerticalSliderPanel::draw() {
    TScrollBarPanel::draw();
}

THorizontalSliderPanel::THorizontalSliderPanel()
    : TVerticalSliderPanel() {
}

THorizontalSliderPanel::~THorizontalSliderPanel() {
}

long THorizontalSliderPanel::setup(TDrawArea* renderAreaIn, TPanel* parentPanelIn,
                                  long xIn, long yIn, long widthIn,
                                  long heightIn, char* backPictureIn, char* thumbPictureIn,
                                  long thumbWidthIn, long scaleIn, long one_step_in,
                                  long page_step_in, int drawBoxIn, int spineWidthIn) {
    drawBox = drawBoxIn;
    spineWidth = spineWidthIn;

    if (TScrollBarPanel::setup(renderAreaIn, parentPanelIn, xIn, yIn, widthIn,
                               heightIn, backPictureIn, 0, 0, thumbPictureIn, 0, thumbWidthIn,
                               0, scaleIn, TScrollBarPanel::Horizontal) == 0) {
        return 0;
    }

    one_step = one_step_in;
    page_step = page_step_in;
    return 1;
}

void THorizontalSliderPanel::set_rect(long x_in, long y_in, long wid_in, long hgt_in) {
    TScrollBarPanel::set_rect(x_in, y_in, wid_in, hgt_in);

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

void THorizontalSliderPanel::draw() {
    TScrollBarPanel::draw();
}

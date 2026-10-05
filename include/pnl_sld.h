#ifndef AOE1_PNL_SLD_H
#define AOE1_PNL_SLD_H

#include "Pnl_scbr.h"

class TVerticalSliderPanel : public TScrollBarPanel {
  public:
    int drawBox;
    int spineWidth;
    virtual ~TVerticalSliderPanel();
    TVerticalSliderPanel();
    long setup(
        TDrawArea* renderAreaIn, TPanel* parentPanelIn, long xIn, long yIn, long widthIn, long heightIn,
        char* backPictureIn, char* thumbPictureIn, long thumbHeightIn, long scaleIn, long one_step_in,
        long page_step_in, int drawBoxIn, int spineWidthIn
    );
    virtual void set_rect(long x_in, long y_in, long wid_in, long hgt_in);
    virtual void draw();
};

class THorizontalSliderPanel : public TVerticalSliderPanel {
  public:
    virtual ~THorizontalSliderPanel();
    THorizontalSliderPanel();
    long setup(
        TDrawArea* renderAreaIn, TPanel* parentPanelIn, long xIn, long yIn, long widthIn, long heightIn,
        char* backPictureIn, char* thumbPictureIn, long thumbWidthIn, long scaleIn, long one_step_in, long page_step_in,
        int drawBoxIn, int spineWidthIn
    );
    virtual void set_rect(long x_in, long y_in, long wid_in, long hgt_in);
    virtual void draw();
};

typedef char pnl_sld_vertical_size_check[(sizeof(TVerticalSliderPanel) == 0x1CC) ? 1 : -1];
typedef char pnl_sld_horizontal_size_check[(sizeof(THorizontalSliderPanel) == 0x1CC) ? 1 : -1];

#endif

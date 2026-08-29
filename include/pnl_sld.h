#ifndef AOE1_PNL_SLD_H
#define AOE1_PNL_SLD_H

#include "Pnl_scbr.h"

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    int drawBox;
    int spineWidth;
    virtual ~TVerticalSliderPanel();
    TVerticalSliderPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, char*, char*,
               long, long, long, long, int, int);
    virtual void set_rect(long, long, long, long);
    virtual void draw();
};

class THorizontalSliderPanel : public TVerticalSliderPanel {
public:
    virtual ~THorizontalSliderPanel();
    THorizontalSliderPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, char*, char*,
               long, long, long, long, int, int);
    virtual void set_rect(long, long, long, long);
    virtual void draw();
};

typedef char pnl_sld_vertical_size_check[
    (sizeof(TVerticalSliderPanel) == 0x1CC) ? 1 : -1];
typedef char pnl_sld_horizontal_size_check[
    (sizeof(THorizontalSliderPanel) == 0x1CC) ? 1 : -1];

#endif

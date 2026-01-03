#pragma once
#include "../common.h"

enum SliderAction : unsigned int {
    ActionUp = 0,
    ActionDown = 1,
    ActionStartSlide = 2,
    ActionEndSlide = 3,
    ActionSelect = 4,
};


class TVerticalSliderPanel : public TScrollBarPanel {
public:
    int drawBox;                             // 0x1C4
    int spineWidth;                          // 0x1C8

    TVerticalSliderPanel();
    virtual ~TVerticalSliderPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void draw();
};

static_assert(sizeof(TVerticalSliderPanel) == 0x1CC, "TVerticalSliderPanel Size Mismatch");
static_assert(offsetof(TVerticalSliderPanel, spineWidth) == 0x1C8, "TVerticalSliderPanel Offset Mismatch");

class THorizontalSliderPanel : public TVerticalSliderPanel {
public:

    THorizontalSliderPanel();
    virtual ~THorizontalSliderPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void draw();
};

static_assert(sizeof(THorizontalSliderPanel) == 0x1CC, "THorizontalSliderPanel Size Mismatch");


#pragma once
#include "common.h"


enum SliderAction : unsigned int {
    ActionUp = 0,
    ActionDown = 1,
    ActionStartSlide = 2,
    ActionEndSlide = 3,
    ActionSelect = 4,
};

class THorizontalSliderPanel : public TVerticalSliderPanel {
public:

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt0[3]+0xC=0x47BEC0
    virtual void draw();                                    // vt0[12]+0x30=0x47BF30
    THorizontalSliderPanel();
    ~THorizontalSliderPanel();
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14);
};

static_assert(sizeof(THorizontalSliderPanel) == 0x1CC, "THorizontalSliderPanel Size Mismatch");

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    int drawBox;                             // 0x1C4
    int spineWidth;                          // 0x1C8

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt0[3]+0xC=0x47BDC0
    virtual void draw();                                    // vt0[12]+0x30=0x47BDE0
    TVerticalSliderPanel();
    ~TVerticalSliderPanel();
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14);
};

static_assert(sizeof(TVerticalSliderPanel) == 0x1CC, "TVerticalSliderPanel Size Mismatch");


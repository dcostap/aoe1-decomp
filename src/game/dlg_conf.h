#pragma once
#include "../common.h"

typedef enum Mode : unsigned int {
    InGame = 0,
    InPregame = 1,
};

class TribeConfigDialog : public TDialogPanel {
public:
    Mode modeValue;                          // 0x490
    TTextPanel* title;                       // 0x494
    TTextPanel* speedTitle[4];               // 0x498
    TButtonPanel* speedButton[3];            // 0x4A8
    TTextPanel* musicTitle[3];               // 0x4B4
    TVerticalSliderPanel* musicSlider;       // 0x4C0
    TTextPanel* soundTitle[3];               // 0x4C4
    TVerticalSliderPanel* soundSlider;       // 0x4D0
    TTextPanel* scrollSpeedTitle[3];         // 0x4D4
    TVerticalSliderPanel* scrollSpeedSlider; // 0x4E0
    TTextPanel* sizeTitle[4];                // 0x4E4
    TButtonPanel* sizeButton[3];             // 0x4F4
    TTextPanel* mouseTitle[3];               // 0x500
    TButtonPanel* mouseButton[2];            // 0x50C
    TTextPanel* rolloverTitle[3];            // 0x514
    TButtonPanel* rolloverButton[2];         // 0x520
    TTextPanel* pathFindingTitle[4];         // 0x528
    TButtonPanel* pathFindingButton[3];      // 0x538
    TButtonPanel* okButton;                  // 0x544
    TButtonPanel* cancelButton;              // 0x548
    long musicVolume;                        // 0x54C
    long soundVolume;                        // 0x550
    float gameSpeed;                         // 0x554
    long scrollSpeed;                        // 0x558
    long newMusicVolume;                     // 0x55C
    long newSoundVolume;                     // 0x560

    TribeConfigDialog(Mode param_1, TScreenPanel* param_2);
    virtual ~TribeConfigDialog();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TribeConfigDialog) == 0x564, "TribeConfigDialog Size Mismatch");
static_assert(offsetof(TribeConfigDialog, newSoundVolume) == 0x560, "TribeConfigDialog Offset Mismatch");


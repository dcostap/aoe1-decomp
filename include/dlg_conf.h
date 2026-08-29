#ifndef AOE1_DLG_CONF_H
#define AOE1_DLG_CONF_H

// This header owns only the configuration dialog surface.
#include "pnl_dlg.h"

class TScreenPanel;
class TTextPanel;
class TButtonPanel;
class TVerticalSliderPanel;

class TribeConfigDialog : public TDialogPanel {
public:
    enum Mode {
        InGame = 0
    };

    Mode modeValue;
    TTextPanel* title;
    TTextPanel* speedTitle[4];
    TButtonPanel* speedButton[3];
    TTextPanel* musicTitle[3];
    TVerticalSliderPanel* musicSlider;
    TTextPanel* soundTitle[3];
    TVerticalSliderPanel* soundSlider;
    TTextPanel* scrollSpeedTitle[3];
    TVerticalSliderPanel* scrollSpeedSlider;
    TTextPanel* sizeTitle[4];
    TButtonPanel* sizeButton[3];
    TTextPanel* mouseTitle[3];
    TButtonPanel* mouseButton[2];
    TTextPanel* rolloverTitle[3];
    TButtonPanel* rolloverButton[2];
    TTextPanel* pathFindingTitle[4];
    TButtonPanel* pathFindingButton[3];
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    long musicVolume;
    long soundVolume;
    float gameSpeed;
    long scrollSpeed;
    long newMusicVolume;
    long newSoundVolume;

    TribeConfigDialog(Mode, TScreenPanel*);
    virtual ~TribeConfigDialog();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char dlg_conf_dialog_size_check[
    (sizeof(TribeConfigDialog) == 0x564) ? 1 : -1];

#endif

#ifndef AOE1_SCR_TRB_H
#define AOE1_SCR_TRB_H

#include "Pnl_scr.h"

class TPicturePanel;
class TTextPanel;
class TButtonPanel;

class TribeSelectTribeScreen : public TScreenPanel {
public:
    TPicturePanel* background;
    TTextPanel* title;
    TTextPanel* tribeText;
    TButtonPanel* tribeButton[9];
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    char** screenText;
    int numLines;

    virtual ~TribeSelectTribeScreen();
    TribeSelectTribeScreen();

protected:
    virtual long action(TPanel* sender, long actionType, unsigned long param3,
                        unsigned long param4);
    void fillTribeText(int index);
    char* tribeName(int index);
};

typedef char scr_trb_screen_size_check[
    (sizeof(TribeSelectTribeScreen) == 0x4B8) ? 1 : -1];

#endif

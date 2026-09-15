#ifndef AOE1_SCR_END_H
#define AOE1_SCR_END_H

#include "Pnl_scr.h"

class TPicturePanel;
class TTextPanel;
class TButtonPanel;

class TribeEndScreen : public TScreenPanel {
public:
    TPicturePanel* background;
    TTextPanel* title;
    TTextPanel* text;
    TButtonPanel* okButton;

    TribeEndScreen(char* titleText, char** textText, int textLineCount);
    virtual ~TribeEndScreen();

protected:
    virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
};

typedef char tribe_end_screen_size_check[
    (sizeof(TribeEndScreen) == 0x488) ? 1 : -1];

#endif

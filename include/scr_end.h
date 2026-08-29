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

    TribeEndScreen(char* title_text, char** text_list, int text_count);
    virtual ~TribeEndScreen();

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char tribe_end_screen_size_check[
    (sizeof(TribeEndScreen) == 0x488) ? 1 : -1];

#endif

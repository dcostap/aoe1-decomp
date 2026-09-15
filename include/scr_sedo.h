#ifndef AOE1_SCR_SEDO_H
#define AOE1_SCR_SEDO_H

// This header owns the scenario-open screen. Shared panel and screen
// surfaces come from their canonical owners.
#include "Pnl_scr.h"

class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

class TRIBE_Screen_Sed_Open : public TScreenPanel {
public:
    TTextPanel* title;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* deleteButton;

    TRIBE_Screen_Sed_Open();
    virtual ~TRIBE_Screen_Sed_Open();

protected:
    void fillList();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char scr_sedo_screen_size_check[
    (sizeof(TRIBE_Screen_Sed_Open) == 0x490) ? 1 : -1];

#endif

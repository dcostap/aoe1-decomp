#ifndef AOE1_DLG_SEDM_H
#define AOE1_DLG_SEDM_H

// TRIBE_Dialog_Sed_Menu is the only class owned by this header. Its dialog
// base comes from the canonical panel owner.
#include "pnl_dlg.h"

class TPanel;
class TButtonPanel;
class TTextPanel;
class TRIBE_Screen_Sed;

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor;
    TTextPanel* title;
    TButtonPanel* buttons[7];

    TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed*);
    virtual ~TRIBE_Dialog_Sed_Menu();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char dlg_sedm_dialog_size_check[
    (sizeof(TRIBE_Dialog_Sed_Menu) == 0x4B4) ? 1 : -1];

#endif

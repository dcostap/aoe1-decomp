#ifndef AOE1_DLG_MENU_H
#define AOE1_DLG_MENU_H

// This header owns only TribeMenuDialog. Shared panel, dialog, screen, and
// button surfaces come from their canonical owner headers.
#include "pnl_dlg.h"
#include "Pnl_scr.h"
#include "pnl_btn.h"

class TribeMenuDialog : public TDialogPanel {
public:
    TButtonPanel* button[11];

    TribeMenuDialog(TScreenPanel* parent);
    virtual ~TribeMenuDialog();

protected:
    virtual long action(TPanel* panel, long id, unsigned long param3,
                        unsigned long param4);
};

typedef char dlg_menu_dialog_size_check[
    (sizeof(TribeMenuDialog) == 0x4BC) ? 1 : -1];

#endif

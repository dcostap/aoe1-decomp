#ifndef AOE1_DLG_MSG_H
#define AOE1_DLG_MSG_H

// PDB source: C:\\msdev\\work\\age1_x1\\Dlg_msg.cpp.
// This header owns TMessageDialog. Its panel bases come from their owners.
#include "pnl_dlg.h"
#include "pnl_btn.h"
#include "pnl_lst.h"

class TMessageDialog : public TDialogPanel {
public:
    unsigned char dlg_type;
    unsigned char pad_491[3];
    TTextPanel* text;
    TButtonPanel* button[3];
    TMessageDialog(char* name);
    virtual ~TMessageDialog();
    long setup(TPanel*, char*, long, long, long, unsigned char, char*, long,
               long);
    long setup(TPanel*, char*, long, long, long, unsigned char, int, long,
               long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long key_down_action(long, short, int, int, int);
    virtual long handle_idle();
};

typedef char dlg_msg_tmessage_dialog_size_check[
    (sizeof(TMessageDialog) == 0x4A4) ? 1 : -1];

#endif

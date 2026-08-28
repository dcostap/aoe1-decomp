#ifndef AOE1_DLG_LIST_H
#define AOE1_DLG_LIST_H

// PDB source module: C:\\msdev\\work\\age1_x1\\dlg_list.cpp.
// This header owns TListDialog.
#include "pnl_dlg.h"
#include "pnl_lst.h"
#include "Pnl_scbr.h"
#include "pnl_btn.h"

class TListDialog : public TDialogPanel {
public:
    TListDialog(char*);
    virtual ~TListDialog();

    // The PDB symbol for this overload is QAE. It is nonvirtual.
    long setup(TPanel*, char*, long, long, long, long, long, long, long,
               char*, long, long, long, long, char**, short, short,
               long, long, long, long, long);
    long setup(TPanel*, char*, long, long, long, long, long, long, long,
               int, long, long, long, long, char**, short, short,
               long, long, long, long, long);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual short get_list_id() { return list_id; }
    virtual char* get_list_name() { return list_name; }

    TTextPanel* title;
    TListPanel* list;
    TScrollBarPanel* scroll_bar;
    TButtonPanel* ok_btn;
    TButtonPanel* cancel_btn;
    short list_id;
    unsigned char pad_4A6[2];
    char* list_name;
};

typedef char dlg_list_dialog_size_check[
    (sizeof(TListDialog) == 0x4AC) ? 1 : -1];

#endif

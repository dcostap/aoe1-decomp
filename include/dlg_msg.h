#ifndef AOE1_DLG_MSG_H
#define AOE1_DLG_MSG_H

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
    long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in,
               long wid_in, long hgt_in, unsigned char dlg_type_in, char* text_in,
               long btn_wid_in, long btn_hgt_in);
    long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in,
               long wid_in, long hgt_in, unsigned char dlg_type_in, int text_id,
               long btn_wid_in, long btn_hgt_in);
    virtual long action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2);
    virtual long key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key);
    virtual long handle_idle();
};

typedef char dlg_msg_tmessage_dialog_size_check[
    (sizeof(TMessageDialog) == 0x4A4) ? 1 : -1];

#endif

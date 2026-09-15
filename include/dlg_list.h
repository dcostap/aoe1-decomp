#ifndef AOE1_DLG_LIST_H
#define AOE1_DLG_LIST_H

// This header owns TListDialog.
#include "pnl_dlg.h"
#include "pnl_lst.h"
#include "Pnl_scbr.h"
#include "pnl_btn.h"

class TListDialog : public TDialogPanel {
public:
    TListDialog(char* name);
    virtual ~TListDialog();

    long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in,
               long wid_in, long hgt_in, long title_x_in, long title_y_in,
               long title_wid_in, long title_hgt_in, char* title_in,
               long list_x_in, long list_y_in, long list_wid_in, long list_hgt_in,
               char** list_in, short list_num_lines_in, short list_id_in,
               long ok_btn_x_in, long cancel_btn_x_in, long btn_y_in,
               long btn_wid_in, long btn_hgt_in);
    long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in,
               long wid_in, long hgt_in, long title_x_in, long title_y_in,
               long title_wid_in, long title_hgt_in, int title_string_id,
               long list_x_in, long list_y_in, long list_wid_in, long list_hgt_in,
               char** list_in, short list_num_lines_in, short list_id_in,
               long ok_btn_x_in, long cancel_btn_x_in, long btn_y_in,
               long btn_wid_in, long btn_hgt_in);
    virtual long key_down_action(long key, short count, int alt_key, int ctrl_key,
                                 int shift_key);
    virtual long action(TPanel* from_panel, long action_in, unsigned long action_val1,
                        unsigned long action_val2);
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

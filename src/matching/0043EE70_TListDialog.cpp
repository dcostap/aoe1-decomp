#include "../../include/dlg_list_context.h"

TListDialog::TListDialog(char* param_1) : TDialogPanel(param_1) {
    this->list_id = -1;
    this->title = 0;
    this->list = 0;
    this->scroll_bar = 0;
    this->ok_btn = 0;
    this->cancel_btn = 0;
    this->list_name = 0;
}

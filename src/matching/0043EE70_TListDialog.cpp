#include "../../include/dlg_list_context.h"

TListDialog::TListDialog(char* param_1)
    : TDialogPanel(param_1), title(0), list(0), scroll_bar(0), ok_btn(0),
      cancel_btn(0), list_id(-1), list_name(0) {
}

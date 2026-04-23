class TDialogPanel {
public:
    void* vftable;
    char gap_04[0x474];

    TDialogPanel(char* param_1);
};

class TListDialog : public TDialogPanel {
public:
    char gap_478[0x18];
    void* title;        // 0x490
    void* list;         // 0x494
    void* scroll_bar;   // 0x498
    void* ok_btn;       // 0x49C
    void* cancel_btn;   // 0x4A0
    short list_id;      // 0x4A4
    char gap_4A6[0x2];
    void* list_name;    // 0x4A8

    TListDialog(char* param_1);
};

TListDialog::TListDialog(char* param_1) : TDialogPanel(param_1) {
    this->list_id = -1;
    this->title = 0;
    this->list = 0;
    this->scroll_bar = 0;
    this->ok_btn = 0;
    this->cancel_btn = 0;
    this->list_name = 0;
    this->vftable = (void*)0x0056FAF8;
}

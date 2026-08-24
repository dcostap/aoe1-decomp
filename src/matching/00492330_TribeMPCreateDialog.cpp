#ifndef SCR_CJ_GROUPED_TU
struct tagRECT;

class TPanel {
public:
    char pad[0xF0];

    virtual ~TPanel();
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char pad_easy[0x384];
};

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;

    virtual ~TDialogPanel();
};

class TribeMPCreateDialog : public TDialogPanel {
public:
    TPanel* title;
    TPanel* input_title;
    TPanel* inputGamename;
    TPanel* okButton;
    TPanel* cancelButton;

    virtual ~TribeMPCreateDialog();
};
#endif

TribeMPCreateDialog::~TribeMPCreateDialog() {
#ifdef SCR_CJ_GROUPED_TU
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->input_title);
    this->delete_panel((TPanel**)&this->inputGamename);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
#else
    this->delete_panel(&this->title);
    this->delete_panel(&this->input_title);
    this->delete_panel(&this->inputGamename);
    this->delete_panel(&this->okButton);
    this->delete_panel(&this->cancelButton);
#endif
}

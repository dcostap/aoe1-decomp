// attempt 1: natural virtual destructor with TScreenPanel-sized local stub and seven delete_panel calls; default flags missed the EH frame
// FLAGS: config/flags/004A75C0_TribeSaveGameScreen.rsp

class TPanel {
public:
    char pad_panel[0xF0];

    virtual ~TPanel();
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char pad_easy[0x380];
};

class TScreenPanel : public TEasy_Panel {
public:
    char pad_screen[4];

    virtual ~TScreenPanel();
};

class TribeSaveGameScreen : public TScreenPanel {
public:
    TPanel* title;
    TPanel* input;
    TPanel* list;
    TPanel* scrollbar;
    TPanel* okButton;
    TPanel* cancelButton;
    TPanel* deleteButton;

    virtual ~TribeSaveGameScreen();
};

TribeSaveGameScreen::~TribeSaveGameScreen() {
    this->delete_panel(&this->title);
    this->delete_panel(&this->input);
    this->delete_panel(&this->list);
    this->delete_panel(&this->scrollbar);
    this->delete_panel(&this->okButton);
    this->delete_panel(&this->cancelButton);
    this->delete_panel(&this->deleteButton);
}

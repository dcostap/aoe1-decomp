// attempt 1: natural virtual destructor with TScreenPanel-sized local stub and seven delete_panel calls; default flags missed the EH frame
// MODULE FLAGS: config/flags/scr_save.rsp

#include "../../include/scr_save_context.h"

#if 0
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
#endif

TribeSaveGameScreen::~TribeSaveGameScreen() {
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->input);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

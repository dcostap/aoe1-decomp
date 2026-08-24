// VA: 0049F890 ~TribeMPStartupScreen dtor (257B)
// scr_mp.cpp lines 225-241
// Baseline reconstruction: period-style EH destructor, ten panel members, and
// the three panel-system dialog removals in source order.
// FLAGS: config/flags/0049F890_TribeMPStartupScreen.rsp

#ifndef AOE1_SCR_MP_CONTEXT_H
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

class TPanelSystem {
public:
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TTextPanel;
class TEditPanel;
class TButtonPanel;
class TListPanel;
class TScrollBarPanel;

class TribeMPStartupScreen : public TScreenPanel {
public:
    TTextPanel* title;                 // +0x478
    TTextPanel* inputTitle;            // +0x47C
    TEditPanel* input;                 // +0x480
    TTextPanel* connectionTitle;       // +0x484
    TButtonPanel* okButton;            // +0x488
    TButtonPanel* cancelButton;        // +0x48C
    TButtonPanel* help_button;         // +0x490
    TButtonPanel* close_button;        // +0x494
    TListPanel* list;                  // +0x498
    TScrollBarPanel* scrollbar;        // +0x49C

    virtual ~TribeMPStartupScreen();
};
#endif

TribeMPStartupScreen::~TribeMPStartupScreen() {
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->inputTitle);
    this->delete_panel((TPanel**)&this->input);
    this->delete_panel((TPanel**)&this->connectionTitle);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->help_button);
    this->delete_panel((TPanel**)&this->close_button);

    panel_system.destroyPanel("Create Dialog");
    panel_system.destroyPanel("OKDialog");
    panel_system.destroyPanel("YesNoDialog");
}

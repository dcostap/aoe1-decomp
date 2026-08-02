// VA: 004B4190 | TribeSelectScenarioScreen::~TribeSelectScenarioScreen() | Scr_sels.cpp:167-179 | 226 bytes
// /GX EH-framed virtual destructor: restores derived vtable, deletes 11 panels in
// member order via TPanel::delete_panel, then tails into base ~TScreenPanel.
// Pattern mirrors matched sibling 004A75C0 TribeSaveGameScreen::~TribeSaveGameScreen.
// FLAGS: config/flags/004B4190_TribeSelectScenarioScreen.rsp (/GX for original EH frame)

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

class TribeSelectScenarioScreen : public TScreenPanel {
public:
    TPanel* title;                 // +0x478
    TPanel* scenarioTitle;         // +0x47C
    TPanel* scenarioPlayersTitle;  // +0x480
    char pad_484[0x10];            // +0x484-0x493 scenarioListX/Y/W/H
    TPanel* scenarioList;          // +0x494
    TPanel* scenarioScrollbar;     // +0x498
    int scenarioCount;             // +0x49C
    char** scenarioMission;        // +0x4A0
    int* scenarioFixed;            // +0x4A4
    int scenariosLoaded;           // +0x4A8
    TPanel* missionTitle;          // +0x4AC
    char pad_4B0[0x10];            // +0x4B0-0x4BF missionTextX/Y/W/H
    TPanel* missionText;           // +0x4C0
    TPanel* missionScrollbar;      // +0x4C4
    TPanel* okButton;              // +0x4C8
    TPanel* cancelButton;          // +0x4CC
    TPanel* close_button;          // +0x4D0
    int last_scenario_line;        // +0x4D4

    virtual ~TribeSelectScenarioScreen();
};

TribeSelectScenarioScreen::~TribeSelectScenarioScreen() {
    this->delete_panel(&this->title);
    this->delete_panel(&this->scenarioTitle);
    this->delete_panel(&this->scenarioPlayersTitle);
    this->delete_panel(&this->scenarioList);
    this->delete_panel(&this->scenarioScrollbar);
    this->delete_panel(&this->missionTitle);
    this->delete_panel(&this->missionText);
    this->delete_panel(&this->missionScrollbar);
    this->delete_panel(&this->okButton);
    this->delete_panel(&this->cancelButton);
    this->delete_panel(&this->close_button);
}

// 00490EA0 TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection
// PDB: scr_cams.cpp:158-171, 240 bytes
// virtual __thiscall ~TRIBE_Screen_Campaign_Selection()
// FLAGS: /GX (EH)

class TPanel {
public:
    char _gap_000[0xF0];
    void delete_panel(TPanel** panel_ptr);
    virtual ~TPanel();
};

class TScreenPanel : public TPanel {
public:
    char _gap_F4[0x384];   // 0xF4 + 0x384 = 0x478
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Campaign_Selection : public TScreenPanel {
public:
    TPanel* title;               // +0x478
    char _gap_47C[0x10];
    TPanel* campaignTitle;       // +0x48C
    TPanel* campaignList;        // +0x490
    TPanel* campaignScrollbar;   // +0x494
    char _gap_498[0x10];
    TPanel* scenarioTitle;       // +0x4A8
    TPanel* scenarioList;        // +0x4AC
    TPanel* scenarioScrollbar;   // +0x4B0
    TPanel* difficultyTitle;     // +0x4B4
    TPanel* difficultyDrop;      // +0x4B8
    TPanel* okButton;            // +0x4BC
    TPanel* cancelButton;        // +0x4C0
    TPanel* close_button;        // +0x4C4

    virtual ~TRIBE_Screen_Campaign_Selection();
};

TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection()
{
    // call delete_panel for each member panel
    delete_panel(&this->title);
    delete_panel(&this->campaignTitle);
    delete_panel(&this->campaignList);
    delete_panel(&this->campaignScrollbar);
    delete_panel(&this->scenarioTitle);
    delete_panel(&this->scenarioList);
    delete_panel(&this->scenarioScrollbar);
    delete_panel(&this->difficultyTitle);
    delete_panel(&this->difficultyDrop);
    delete_panel(&this->okButton);
    delete_panel(&this->cancelButton);
    delete_panel(&this->close_button);
}

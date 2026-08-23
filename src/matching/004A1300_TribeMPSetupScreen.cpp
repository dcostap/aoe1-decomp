// VA: 004A1300 TribeMPSetupScreen::~TribeMPSetupScreen
// scr_mps.cpp lines 669-753
// Attempt log:
// initial natural destructor surface: delete scenarioInfo, destroy five named panels,
// delete panel pointer fields in binary-observed order; uses /GX for EH-framed dtor.

#ifndef SCR_MPS_TU_CONTEXT

#include <windows.h>

class TPanel {
public:
    char _gap_04[0x1C];
    void* render_area;
    char _gap_24[0x1C];
    void* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
    void delete_panel(TPanel** panel_ptr);
};

class TScreenPanel : public TPanel {
public:
    char _gap_F4[0x384];
    virtual ~TScreenPanel();
};

class T_Scenario { public: virtual void unknown(); virtual ~T_Scenario(); };

class TPanelSystem {
public:
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TribeMPSetupScreen : public TScreenPanel {
public:
    TPanel* title;                 // +478
    TPanel* playerTitle;           // +47C
    TPanel* civTitle;              // +480
    TPanel* settingsTitle;         // +484
    TPanel* colorTitle;            // +488
    TPanel* teamTitle;             // +48C
    TPanel* playerNameText[8];     // +490
    TPanel* playerCivText[8];      // +4B0
    TPanel* scenarioPlayerText[8]; // +4D0
    TPanel* playerCDText[8];       // +4F0
    TPanel* playerVersionText[8];  // +510
    TPanel* playerColorText[8];    // +530
    TPanel* playerTeamText[8];     // +550
    TPanel* playerColor[8];        // +570
    TPanel* playerTeam[8];         // +590
    TPanel* playerNameDrop[8];     // +5B0
    TPanel* playerCivDrop[8];      // +5D0
    TPanel* scenarioPlayerDrop[8]; // +5F0
    TPanel* chatInput;             // +610
    TPanel* chatTitle;             // +614
    TPanel* chatBox;               // +618
    TPanel* chatScrollbar;         // +61C
    TPanel* gameSettingsButton;    // +620
    TPanel* scenarioName;          // +624
    TPanel* victoryFixedText;      // +628
    TPanel* settingText[20];       // +62C
    TPanel* settingValue[20];      // +67C
    TPanel* mapSizeLabel;          // +6CC
    TPanel* mapSizeDrop;           // +6D0
    TPanel* mapTypeLabel;          // +6D4
    TPanel* mapTypeDrop;           // +6D8
    TPanel* numberPlayersTitle;    // +6DC
    TPanel* numberPlayersDrop;     // +6E0
    TPanel* numberPlayersText;     // +6E4
    TPanel* hiddenMapButton;       // +6E8
    TPanel* hiddenMapText;         // +6EC
    TPanel* victoryTypeLabel;      // +6F0
    TPanel* victoryTypeDrop;       // +6F4
    TPanel* victoryAmountLabel;    // +6F8
    TPanel* victoryAmountInput;    // +6FC
    TPanel* startButton;           // +700
    TPanel* readyButtons[2];       // +704
    TPanel* cancelButton;          // +70C
    TPanel* help_button;           // +710
    TPanel* ready_button;          // +714
    TPanel* close_button;          // +718
    TPanel* ready_button_label;    // +71C
    int cancelMode;
    int playerToKick;
    int scenarioPlayerCount;
    int myCivilization;
    int myScenarioPlayer;
    int myPlayerColor;
    int myPlayerTeam;
    long myScenarioChecksum;
    char saveScenarioName[256];
    int saveRandomGame;
    long saveScenarioChecksum;
    T_Scenario* scenarioInfo;      // +848
    int settingsFixed;
    int numberAnyPlayers;
    int sent_cd_status;
    TPanel* netInfoButton;         // +858
    int rest[13];

    virtual ~TribeMPSetupScreen();
};

#endif

TribeMPSetupScreen::~TribeMPSetupScreen()
{
    if (this->scenarioInfo != 0) {
        delete this->scenarioInfo;
        this->scenarioInfo = 0;
    }

    panel_system.destroyPanel("Game Settings Screen");
    panel_system.destroyPanel("Select Tribe Screen");
    panel_system.destroyPanel("Kick Dialog");
    panel_system.destroyPanel("OKDialog");
    panel_system.destroyPanel("YesNoDialog");

    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->playerTitle);
    this->delete_panel((TPanel**)&this->civTitle);
    this->delete_panel((TPanel**)&this->settingsTitle);
    this->delete_panel((TPanel**)&this->colorTitle);
    this->delete_panel((TPanel**)&this->teamTitle);

    for (int i = 0; i < 8; i++) {
        this->delete_panel((TPanel**)&this->playerNameDrop[i]);
        this->delete_panel((TPanel**)&this->playerCivDrop[i]);
        this->delete_panel((TPanel**)&this->scenarioPlayerDrop[i]);
        this->delete_panel((TPanel**)&this->playerColor[i]);
        this->delete_panel((TPanel**)&this->playerTeam[i]);
        this->delete_panel((TPanel**)&this->playerNameText[i]);
        this->delete_panel((TPanel**)&this->playerCivText[i]);
        this->delete_panel((TPanel**)&this->scenarioPlayerText[i]);
        this->delete_panel((TPanel**)&this->playerCDText[i]);
        this->delete_panel((TPanel**)&this->playerVersionText[i]);
        this->delete_panel((TPanel**)&this->playerColorText[i]);
        this->delete_panel((TPanel**)&this->playerTeamText[i]);
    }

    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
    this->delete_panel((TPanel**)&this->chatBox);
    this->delete_panel((TPanel**)&this->gameSettingsButton);
    this->delete_panel((TPanel**)&this->scenarioName);
    this->delete_panel((TPanel**)&this->victoryFixedText);

    for (int j = 0; j < 20; j++) {
        this->delete_panel((TPanel**)&this->settingText[j]);
        this->delete_panel((TPanel**)&this->settingValue[j]);
    }

    this->delete_panel((TPanel**)&this->mapSizeLabel);
    this->delete_panel((TPanel**)&this->mapSizeDrop);
    this->delete_panel((TPanel**)&this->mapTypeLabel);
    this->delete_panel((TPanel**)&this->mapTypeDrop);
    this->delete_panel((TPanel**)&this->numberPlayersTitle);
    this->delete_panel((TPanel**)&this->numberPlayersDrop);
    this->delete_panel((TPanel**)&this->numberPlayersText);
    this->delete_panel((TPanel**)&this->hiddenMapButton);
    this->delete_panel((TPanel**)&this->hiddenMapText);
    this->delete_panel((TPanel**)&this->victoryTypeLabel);
    this->delete_panel((TPanel**)&this->victoryTypeDrop);
    this->delete_panel((TPanel**)&this->victoryAmountLabel);
    this->delete_panel((TPanel**)&this->victoryAmountInput);
    this->delete_panel((TPanel**)&this->startButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->ready_button);
    this->delete_panel((TPanel**)&this->ready_button_label);
    this->delete_panel((TPanel**)&this->netInfoButton);
    this->delete_panel((TPanel**)&this->help_button);
}

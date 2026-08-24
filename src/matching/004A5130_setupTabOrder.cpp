// 004A5130 TribeMPSetupScreen::setupTabOrder
// 223 bytes, __thiscall, scr_mps.cpp lines 2752-2787
// Attempt log:
// baseline: natural reconstruction modeled on exact sibling donor
//   004A68C0 (TRIBE_Screen_Name::setup_tab_order): VPAD virtual slots to
//   +0xC8 set_tab_order(TPanel**, int), non-virtual set_curr_child member,
//   local TPanel* tabList[4], rge_base_game->singlePlayerGame() guard.
//   Field offsets from exact destructor donor 004A1300: chatInput +0x610,
//   gameSettingsButton +0x620, startButton +0x700, cancelButton +0x70C,
//   ready_button +0x714.

#ifndef SCR_MPS_TU_CONTEXT

class TPanel;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class RGE_Base_Game {
public:
    int singlePlayerGame();
};

extern RGE_Base_Game* rge_base_game;

class TribeMPSetupScreen {
public:
    VPAD32(0)        // slots 0..31
    VPAD16(32)       // slots 32..47
    VPAD1(48)
    VPAD1(49)
    virtual void set_tab_order(TPanel** panels, int count); // slot 50 / +0xC8

    char gap_04[0x610 - 0x04];
    TPanel* chatInput;            // +0x610
    char gap_614[0x620 - 0x614];
    TPanel* gameSettingsButton;   // +0x620
    char gap_624[0x700 - 0x624];
    TPanel* startButton;          // +0x700
    char gap_704[0x70C - 0x704];
    TPanel* cancelButton;         // +0x70C
    char gap_710[0x714 - 0x710];
    TPanel* ready_button;         // +0x714

    void set_curr_child(TPanel* child);
    void setupTabOrder();
};

#endif

void TribeMPSetupScreen::setupTabOrder()
{
    TPanel* tabList[4];

    if (rge_base_game->singlePlayerGame()) {
        tabList[0] = startButton;
        tabList[1] = cancelButton;
        tabList[2] = gameSettingsButton;
        set_tab_order(tabList, 3);
        set_curr_child(startButton);
        return;
    }

    tabList[0] = chatInput;
    if (gameSettingsButton) {
        tabList[1] = startButton;
        tabList[2] = cancelButton;
        tabList[3] = gameSettingsButton;
        set_tab_order(tabList, 4);
        set_curr_child(chatInput);
        return;
    }

    tabList[1] = ready_button;
    tabList[2] = cancelButton;
    set_tab_order(tabList, 3);
    set_curr_child(chatInput);
}

// 004A5130 setupTabOrder
// 223 bytes, __thiscall, TribeMPSetupScreen method
// probe 2: fix type mismatch

class RGE_Base_Game;
class TPanel;

extern RGE_Base_Game* rge_base_game;
int RGE_Base_Game_singlePlayerGame(RGE_Base_Game* game);
void TPanel_set_curr_child(void* self, TPanel* child);

class TribeMPSetupScreen {
public:
    void (*vf50)(TPanel** list, int count);  // vtable slot at +0xC8
    TPanel* chatInput;
    TPanel* startButton;
    TPanel* cancelButton;
    TPanel* gameSettingsButton;
    TPanel* ready_button;

    void setupTabOrder();
};

void TribeMPSetupScreen::setupTabOrder() {
    TPanel* tabList[4];
    int single = RGE_Base_Game_singlePlayerGame(rge_base_game);
    if (single != 0) {
        tabList[1] = cancelButton;
        tabList[2] = startButton;
        tabList[3] = gameSettingsButton;
        vf50(tabList + 1, 3);
        TPanel_set_curr_child(this, startButton);
        return;
    }
    tabList[1] = chatInput;
    if (gameSettingsButton != 0) {
        tabList[2] = startButton;
        tabList[3] = cancelButton;
        vf50(tabList + 1, 4);
        TPanel_set_curr_child(this, chatInput);
        return;
    }
    tabList[2] = ready_button;
    tabList[3] = cancelButton;
    vf50(tabList + 1, 3);
    TPanel_set_curr_child(this, chatInput);
}

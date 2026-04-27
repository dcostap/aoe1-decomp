// 004A5060 activateVictoryPanels
// 181 bytes, __thiscall, TribeMPSetupScreen method
// probe 1: check victory type, activate/deactivate panels, switch on type

class TDropDownPanel {
public:
    int get_id();
};

class TPanel {
public:
    char gap_00[0x14];
    void set_enabled(int enabled);
    char gap_18[0xC8];
    void set_text(int stringId);
};

class TribeMPSetupScreen {
public:
    TDropDownPanel* victoryTypeDrop;
    TPanel* victoryAmountLabel;
    TPanel* victoryAmountInput;

    void activateVictoryPanels();
};

void TribeMPSetupScreen::activateVictoryPanels() {
    int id = victoryTypeDrop->get_id();
    if (id == 1 || id == 0) {
        victoryAmountLabel->set_enabled(0);
        victoryAmountInput->set_enabled(0);
    } else {
        victoryAmountLabel->set_enabled(1);
        victoryAmountInput->set_enabled(1);
        id = victoryTypeDrop->get_id();
        if (id == 2) {
            victoryAmountLabel->set_text(0x25CB);
        } else if (id == 3 || id == 4 || id == 5) {
            victoryAmountLabel->set_text(0x25CC);
        }
    }
}

// 004A5060 activateVictoryPanels
// 181 bytes, __thiscall, TribeMPSetupScreen method
// Retry 2026-05-26: rebuilt local layout/vtable slot surfaces; current exact-size near match.

class TDropDownPanel {
public:
    int get_id();
};

class TPanel {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void set_enabled(int enabled); // +0x14
    virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13();
    virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17();
    virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21();
    virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25();
    virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33();
    virtual void d34(); virtual void d35(); virtual void d36(); virtual void d37();
    virtual void d38(); virtual void d39(); virtual void d40(); virtual void d41();
    virtual void d42(); virtual void d43(); virtual void d44(); virtual void d45();
    virtual void d46(); virtual void d47(); virtual void d48(); virtual void d49();
    virtual void d50(); virtual void d51(); virtual void d52(); virtual void d53();
    virtual void d54(); virtual void d55(); virtual void d56();
    virtual void set_text(int stringId); // +0xE4 slot 57
};

class TribeMPSetupScreen {
public:
    char gap_00[0x6F4];
    TDropDownPanel* victoryTypeDrop;
    TPanel* victoryAmountLabel;
    TPanel* victoryAmountInput;

    void activateVictoryPanels();
};

void TribeMPSetupScreen::activateVictoryPanels() {
    int id = victoryTypeDrop->get_id();
    if (id == 1 || victoryTypeDrop->get_id() == 0) {
        victoryAmountLabel->set_enabled(0);
        victoryAmountInput->set_enabled(0);
    } else {
        victoryAmountLabel->set_enabled(1);
        victoryAmountInput->set_enabled(1);
        switch (victoryTypeDrop->get_id()) {
        case 2:
            victoryAmountLabel->set_text(0x25CB);
            return;
        case 3:
        case 4:
        case 5:
            victoryAmountLabel->set_text(0x25CC);
            return;
        case 6:
            victoryAmountLabel->set_text(0x25CD);
            return;
        }
    }
}

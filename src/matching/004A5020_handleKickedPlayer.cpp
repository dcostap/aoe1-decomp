// VA: 004A5020 handleKickedPlayer (55B)
// Match the neg/sbb/add trick for conditional decrement

#ifndef SCR_MPS_TU_CONTEXT

class TEasy_Panel {
public:
    void popupOKDialog(int text_id, char* panel_name, int param_4, int param_5);
};

class TPanelSystem {
public:
    TEasy_Panel* currentPanel();
};

extern TPanelSystem panel_system;

class TribeMPSetupScreen {
public:
    void cancelScreen(int timed_out);
    void handleKickedPlayer(int player_index);
};

#endif

void TribeMPSetupScreen::handleKickedPlayer(int player_index) {
    this->cancelScreen(0);
    TEasy_Panel* panel = panel_system.currentPanel();
    if (panel != 0) {
        panel->popupOKDialog(0x25CA + (player_index != 0 ? -1 : 0), 0, 0x1C2, 100);
    }
}

class TEasy_Panel {
public:
    void popupOKDialog(long text_id, char* panel_name, int param_4, int param_5);
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

// tried the direct cancel/currentPanel/popupOKDialog shape; remaining mismatch is helper-call sequence
void TribeMPSetupScreen::handleKickedPlayer(int player_index) {
    this->cancelScreen(0);
    TEasy_Panel* panel = panel_system.currentPanel();
    if (panel != 0) {
        int text_id = 0x25CA;
        if (player_index != 0) {
            --text_id;
        }
        panel->popupOKDialog(text_id, (char*)0, 0x1C2, 100);
    }
}

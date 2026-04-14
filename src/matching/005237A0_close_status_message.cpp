struct GlobalPanel {
    void showPanel(int val);
};

extern GlobalPanel g_panel;

class TRIBE_Game {
public:
    void close_status_message();
};

void TRIBE_Game::close_status_message() {
    g_panel.showPanel(1);
}

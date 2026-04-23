class TPanel {
public:
    virtual void destroy(int flag);
    char gap_04[0xD4];
    int error_code;
};

class RGE_Base_Game {
public:
    int create_dialog(TPanel** out, TPanel* panel);
};

int RGE_Base_Game::create_dialog(TPanel** out, TPanel* panel) {
    *out = 0;
    if (panel == 0) {
        return 0;
    }
    if (panel->error_code != 0) {
        panel->destroy(1);
        return 0;
    }
    *out = panel;
    return 1;
}

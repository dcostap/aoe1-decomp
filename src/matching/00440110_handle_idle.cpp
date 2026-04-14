// STATUS: wip
// FLAGS: config\flags\00440110_handle_idle.rsp

class RGE_Base_Game {
public:
    char gap_0[0x1D8];
    int input_enabled;
    void enable_input();
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual long handle_idle();
};

class TMessageDialog : public TPanel {
public:
    long handle_idle();
};

long TMessageDialog::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

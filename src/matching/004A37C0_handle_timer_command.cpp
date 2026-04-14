class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();
    int handle_timer_command(int p0, int p1);
};

int TribeMPSetupScreen::handle_timer_command(int p0, int p1) { return 1; }

class TribeMPStartupScreen {
public:
    virtual ~TribeMPStartupScreen();
    int handle_user_command(int p0, int p1);
};

int TribeMPStartupScreen::handle_user_command(int p0, int p1) { return 1; }

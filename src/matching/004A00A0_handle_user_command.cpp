#ifndef AOE1_SCR_MP_CONTEXT_H
class TribeMPStartupScreen {
public:
    virtual ~TribeMPStartupScreen();
    int handle_user_command(int p0, int p1);
};
#endif

int TribeMPStartupScreen::handle_user_command(int p0, int p1) { return 1; }

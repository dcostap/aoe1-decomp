#ifndef SCR_MPS_TU_CONTEXT
class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();
    int handle_timer_command(int p0, int p1);
};
#endif

int TribeMPSetupScreen::handle_timer_command(int p0, int p1) { return 1; }

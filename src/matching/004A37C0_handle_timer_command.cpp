#ifndef SCR_MPS_TU_CONTEXT
class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();
    virtual long handle_timer_command(unsigned int p0, long p1);
};
#endif

long TribeMPSetupScreen::handle_timer_command(unsigned int p0, long p1) { return 1; }

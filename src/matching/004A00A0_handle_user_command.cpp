#ifndef AOE1_SCR_MP_CONTEXT_H
class TribeMPStartupScreen {
public:
    virtual ~TribeMPStartupScreen();
    virtual long handle_user_command(unsigned int p0, long p1);
};
#endif

long TribeMPStartupScreen::handle_user_command(unsigned int p0, long p1) {
    return 1;
}

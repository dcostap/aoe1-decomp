#ifndef SCR_MPS_TU_CONTEXT

class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();
    virtual long key_down_action(long p0, short p1, int p2, int p3, int p4);
};

#endif

long TribeMPSetupScreen::key_down_action(long p0, short p1, int p2, int p3, int p4) { return 0; }

// VA: 004A16E0 action (2426B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    int action(int a1, int a2, int a3);
};

int TribeMPSetupScreen::action(int a1, int a2, int a3) {
    char buf[544];
    if (!a1) return 0;
    field_8 = a1 + a2 + a3;
    return 1;
}

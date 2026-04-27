// VA: 004A1300 ~TribeMPSetupScreen dtor (826B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    int* vtable;
    char gap4[0x474];
    int field_478;
    
    ~TribeMPSetupScreen();
};

TribeMPSetupScreen::~TribeMPSetupScreen() {
    vtable = (int*)0;  // vtable will be set
    if (field_478) {
        field_478 = 0;
    }
}

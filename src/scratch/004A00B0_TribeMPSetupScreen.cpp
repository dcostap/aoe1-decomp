// VA: 004A00B0 TribeMPSetupScreen ctor (3240B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    int* vtable;
    char gap4[0x474];
    int field_478;
    int field_47C;
    
    TribeMPSetupScreen();
};

TribeMPSetupScreen::TribeMPSetupScreen() {
    vtable = (int*)0x55F19B;
    field_478 = 0;
    field_47C = 0;
}

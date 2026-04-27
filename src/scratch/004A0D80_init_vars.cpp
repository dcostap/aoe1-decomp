// VA: 004A0D80 init_vars (1403B)
// scr_mps.cpp

class TribeMPSetupScreen {
public:
    char gap4[0x474];
    int field_478;
    int field_47C;
    int field_480;
    
    void init_vars();
};

void TribeMPSetupScreen::init_vars() {
    field_478 = 0;
    field_47C = 0;
    field_480 = 0;
}

// VA: 004A2910 showNetInfo (645B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    void showNetInfo();
};

void TribeMPSetupScreen::showNetInfo() {
    char buf[1288];
    field_8 = (int)buf;
}

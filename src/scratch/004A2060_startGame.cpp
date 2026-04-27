// VA: 004A2060 startGame (1847B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    void startGame();
};

void TribeMPSetupScreen::startGame() {
    char buf[1384];
    field_8 = (int)buf;
}

// VA: 004A27A0 calcRandomPositions (366B)
// scr_mps.cpp

extern int g_game_info;

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    void calcRandomPositions();
};

int g_game_info = 0;

void TribeMPSetupScreen::calcRandomPositions() {
    if (g_game_info) {
        field_8 = g_game_info;
    } else {
        field_8 = 0;
    }
}

// VA: 004A5210 setupSinglePlayerPlayers (556B)
// scr_mps.cpp

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    void setupSinglePlayerPlayers();
};

void __cdecl sub_004223A0(void* this_);

void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    sub_004223A0((void*)0x62C574);
    field_8 = 1;
}

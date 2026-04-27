// VA: 004A2BA0 cancelScreen (429B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    void cancelScreen();
};

void __cdecl sub_004223F0(void* this_);

void TribeMPSetupScreen::cancelScreen() {
    sub_004223F0((void*)0x62C574);
    field_8 = 0;
}

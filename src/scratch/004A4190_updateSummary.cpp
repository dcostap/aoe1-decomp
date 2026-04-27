// VA: 004A4190 updateSummary (3522B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    void updateSummary();
};

void __cdecl sub_004223A0(void* this_);

void TribeMPSetupScreen::updateSummary() {
    char buf[1332];
    sub_004223A0((void*)0x62C574);
    field_8 = (int)buf;
}

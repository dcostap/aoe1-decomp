// VA: 004A37D0 fillPlayers (2342B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    void fillPlayers();
};

void __cdecl sub_00422400(void* this_);

void TribeMPSetupScreen::fillPlayers() {
    sub_00422400((void*)0x62C574);
    field_8 = 0;
}

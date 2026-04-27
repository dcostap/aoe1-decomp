// VA: 004A2D50 handle_user_command (2551B)
// scr_mps.cpp
// EH frame (/GX)

class TribeMPSetupScreen {
public:
    char gap4[0x4];
    int field_8;
    
    void handle_user_command(int a1);
};

void __cdecl sub_004223F0(void* this_);

void TribeMPSetupScreen::handle_user_command(int a1) {
    sub_004223F0((void*)0x62C574);
    field_8 = a1;
}

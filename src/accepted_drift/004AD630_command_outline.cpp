// ACCEPTED_DRIFT: Same switch-codegen drift as 0049C920.
// VC5 uses xor+mov for zero-extension instead of push ecx + store/reload;
// and uses direct mov byte [base+0x50],X for stores instead of mov cl,X + mov [base+0x50],cl.
// Register allocation also differs (ecx for global ptr vs edx).
// VA: 004AD630 command_outline (56B, scr_sed.cpp)

extern unsigned char* rge_base_game;

class TRIBE_Screen_Sed {
public:
    void command_outline(void);
};

void TRIBE_Screen_Sed::command_outline(void)
{
    switch (rge_base_game[0x50]) {
    case 0:
    case 3:
        rge_base_game[0x50] = 2;
        return;
    case 2:
        rge_base_game[0x50] = 1;
        return;
    case 1:
        rge_base_game[0x50] = 0;
        return;
    }
}

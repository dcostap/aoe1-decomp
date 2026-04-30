// VA: 004AD630 command_outline
// Attempt log:
// [1] Direct Ghidra-style switch with local game pointer; VC5 picks ecx for global, not edx
// [2] Without local, all-return switch; structure completely different, no push ecx
// [3] Ghidra-style with proper fall-through for case 1
class RGE_Base_Game {
public:
    char gap_00[0x50];
    unsigned char outline_type;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed {
public:
    void command_outline(void);
};

void TRIBE_Screen_Sed::command_outline(void) {
    unsigned char outline = rge_base_game->outline_type;
    switch (outline) {
    case 0:
    case 3:
        rge_base_game->outline_type = 2;
        return;
    case 1:
        outline = 0;
        break;
    case 2:
        rge_base_game->outline_type = 1;
        return;
    }
    rge_base_game->outline_type = outline;
}

// VA: 004AD630 TRIBE_Screen_Sed::command_outline | scr_sed.cpp:3428-3450
// Attempt log:
// [1-5] Various switch/if shapes; register choice ecx vs edx for global is the barrier
// [6] Unified store approach - wrong structure
// [7] Virtual - changes symbol
// [8] Reorder switch cases - no change
// [9] Full class context with this usage via position_panels call

class RGE_Base_Game {
public:
    char gap_00[0x50];
    unsigned char outline_type;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed {
public:
    void position_panels(void);
    void command_outline(void);
};

void TRIBE_Screen_Sed::command_outline(void) {
    unsigned char outline = rge_base_game->outline_type;
    if (outline == 0 || outline == 3) {
        rge_base_game->outline_type = 2;
        return;
    }
    if (outline == 2) {
        rge_base_game->outline_type = 1;
        return;
    }
    if (outline == 1) {
        rge_base_game->outline_type = 0;
    }
}

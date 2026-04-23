// tried the direct switch form with a local game pointer; VC5 still picks the wrong global-load register basin
// remaining gap is the initial global-load / switch-table shape, not behavior
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
    RGE_Base_Game* game = rge_base_game;
    unsigned char outline = game->outline_type;
    switch (outline) {
    case 0:
    case 3:
        game->outline_type = 2;
        return;
    case 1:
        outline = 0;
        break;
    case 2:
        game->outline_type = 1;
        return;
    }
    game->outline_type = outline;
}

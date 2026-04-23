// tried the direct outline switch; VC5 still wants the table/push/pop-shaped basin
class TRIBE_Game {
public:
    unsigned char outline_type;
};

extern TRIBE_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    void command_outline(void);
};

void TRIBE_Screen_Game::command_outline(void) {
    unsigned char outline = rge_base_game->outline_type;
    switch (outline) {
    case 0:
    case 3:
        rge_base_game->outline_type = 2;
        break;
    case 1:
        outline = 0;
        rge_base_game->outline_type = outline;
        break;
    case 2:
        rge_base_game->outline_type = 1;
        break;
    }
}

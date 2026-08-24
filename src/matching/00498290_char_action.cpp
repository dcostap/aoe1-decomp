#if !defined(SCR_GAME_TU_CONTEXT)
extern int allow_user_commands;

class TRIBE_Screen_Game {
public:
    void command_game_speed(int value);
    long char_action(long action, short param_2);
};
#endif

long TRIBE_Screen_Game::char_action(long action, short param_2) {
    (void)param_2;
    switch (action) {
    case 0x2B:
    case 0x3D:
        if (allow_user_commands != 0) {
            this->command_game_speed(1);
        }
        return 0;
    case 0x2D:
        if (allow_user_commands != 0) {
            this->command_game_speed(0);
        }
        return 0;
    default:
        return 0;
    }
}

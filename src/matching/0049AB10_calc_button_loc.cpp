#if !defined(SCR_GAME_TU_CONTEXT)
class TRIBE_Screen_Game {
public:
    short calc_button_loc(unsigned char param_1);
};
#endif

short TRIBE_Screen_Game::calc_button_loc(unsigned char param_1) {
    if (param_1 >= 1 && param_1 <= 5) {
        return param_1 - 1;
    }
    if (param_1 >= 6 && param_1 <= 10) {
        return param_1;
    }
    if (param_1 >= 11 && param_1 <= 15) {
        return param_1 - 0xB;
    }
    if (param_1 >= 16 && param_1 <= 20) {
        return param_1 - 0xA;
    }
    return 0;
}

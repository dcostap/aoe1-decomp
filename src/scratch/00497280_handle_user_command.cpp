#if !defined(SCR_GAME_TU_CONTEXT)
class TRIBE_Screen_Game {
public:
    void target_00497280(int a, int b);
    void handle_user_command(int a, int b);
};
#endif

void TRIBE_Screen_Game::handle_user_command(int a, int b) {
    this->target_00497280(a, b);
}

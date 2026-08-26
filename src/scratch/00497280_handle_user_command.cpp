#if !defined(SCR_GAME_TU_CONTEXT)
class TPanel {
public:
    virtual long handle_user_command(unsigned int, long);
};

class TScreenPanel : public TPanel {
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    virtual long handle_user_command(unsigned int, long);
};
#endif

long TRIBE_Screen_Game::handle_user_command(unsigned int command, long value) {
    return TPanel::handle_user_command(command, value);
}

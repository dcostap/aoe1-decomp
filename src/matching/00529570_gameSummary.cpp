extern char g_0086BCA0;
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char* gameSummary();
};

char* TRIBE_Game::gameSummary() {
    g_0086BCA0 = 0;
    return &g_0086BCA0;
}

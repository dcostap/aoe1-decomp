#if !defined(SCR_GAME_TU_CONTEXT)
class TRIBE_Screen_Game {
public:
    char gap_00[0x5E2];
    short start_item;
    void setup_buttons();
    void reset_buttons();
};
#endif

void TRIBE_Screen_Game::reset_buttons() {
    this->start_item = 0;
    this->setup_buttons();
}

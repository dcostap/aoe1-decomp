#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[0xA90];
    char civilization_[16];

    void setCivilization(int, int);
};
#endif
void TRIBE_Game::setCivilization(int player, int civ) {
    this->tribe_game_options.civilizationValue[player] = (unsigned char)civ;
}

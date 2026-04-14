class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[0xA90];
    char civilization_[16];

    void setCivilization(int, int);
};
void TRIBE_Game::setCivilization(int player, int civ) {
    this->civilization_[player] = civ;
}

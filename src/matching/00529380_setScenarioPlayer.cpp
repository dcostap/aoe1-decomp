#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    char gap_0[0xAA0];
    int arr_[1];
    void setScenarioPlayer(int i, int v);
};
#endif

void TRIBE_Game::setScenarioPlayer(int i, int v) {
    this->tribe_game_options.scenarioPlayerValue[i] = v;
}

// quick-win attempt log:
// target is 00490E30 TRIBE_Screen_Campaign_Selection::init_vars from scr_cams.cpp
// first pass uses direct member-zeroing plus the two global base-game calls; if codegen drifts,
// probe call order and whether the global load wants to stay duplicated like the oracle.

class RGE_Base_Game {
public:
    int get_single_player_difficulty();
    void setDifficulty(int value);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Campaign_Selection {
public:
    char pad_000[0x478];
    void* title;
    char pad_47C[0x10];
    void* campaignTitle;
    void* campaignList;
    void* campaignScrollbar;
    char pad_498[0x10];
    void* scenarioTitle;
    void* scenarioList;
    void* scenarioScrollbar;
    void* difficultyTitle;
    void* difficultyDrop;
    void* okButton;
    void* cancelButton;
    void* close_button;
    int campaignsLoaded;

    void init_vars();
};

void TRIBE_Screen_Campaign_Selection::init_vars() {
    title = 0;
    campaignTitle = 0;
    campaignList = 0;
    campaignScrollbar = 0;
    scenarioTitle = 0;
    scenarioList = 0;
    scenarioScrollbar = 0;
    difficultyTitle = 0;
    difficultyDrop = 0;
    okButton = 0;
    cancelButton = 0;
    close_button = 0;
    campaignsLoaded = 0;

    int difficulty = rge_base_game->get_single_player_difficulty();
    rge_base_game->setDifficulty(difficulty);
}

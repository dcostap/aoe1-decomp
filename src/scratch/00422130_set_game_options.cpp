// VA: 00422130 RGE_Base_Game::set_game_options (297 B)
// PDB source: basegame.cpp
// Packet-grounded: write all game options from RGE_Game_Options struct
// Attempt log:
// - Replaced the initial cdecl self shims with the canonical member-setter
//   ABI and nested RGE_Game_Options layout; size/calls/CFG became exact.
// - Reversed subscripts, pointer-add/raw-byte offset forms, nested-type and
//   destructor context, loop declaration/register variants, and a focused
//   variant lab all emitted the same 2-byte SIB drift: rebuilt [edi+esi+92/9C]
//   versus original [esi+edi+92/9C].
// - Left the natural typed reconstruction in scratch; only the address-term
//   encoding remains unresolved.
// - Rechecked the ground-truth three-byte tail pad against the paired getter;
//   it is a codegen duplicate, so the natural nested record remains canonical.
// - Main-agent audit retained the shared named option record and ordinary
//   indexed loop; no address-expression steering survives.
// - New worker probes: do/while lowering, integer-address-sum spelling,
//   signed-byte fields with explicit casts, an inline array wrapper, and an
//   index-first pointer-cast address all remained the same 2-byte SIB group.
//   Array references added a 21-byte frame/CFG drift; a non-inlined helper
//   added two calls; both were restored. The vc5-small flag family (12
//   variants, including /GX, /Ow, /Oi, /Og, /Ot, /Ob0 combinations) also
//   collapsed to one 2-byte group. The residual is therefore a backend
//   address-term encoding basin, not a supported ownership/type lead.

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    struct RGE_Game_Options {
        float versionValue;
        unsigned char scenarioGameValue;
        char scenarioNameValue[0x80];
        unsigned char singlePlayerGameValue;
        unsigned char multiplayerGameValue;
        unsigned char mapXSizeValue;
        unsigned char mapYSizeValue;
        unsigned char mapZSizeValue;
        unsigned char allowCheatCodesValue;
        unsigned char mpPathFindingValue;
        unsigned char cheatNotificationValue;
        unsigned char fullVisibilityValue;
        unsigned char fogOfWarValue;
        unsigned char coloredChatValue;
        unsigned char numberPlayersValue;
        unsigned char gameDeveloperModeValue;
        unsigned char playerCDAndVersionValue[9];
        unsigned char difficultyValue;
        unsigned char playerTeamValue[9];
    };

    void setVersion(float v);
    void setScenarioGame(int v);
    void setScenarioName(const char* name);
    void setSinglePlayerGame(int v);
    void setMultiplayerGame(int v);
    void setMapSize(int x, int y, int z);
    void setAllowCheatCodes(int v);
    void setCheatNotification(int v);
    void setFullVisibility(int v);
    void setFogOfWar(int v);
    void setColoredChat(int v);
    void setNumberPlayers(int v);
    void setGameDeveloperMode(int v);
    void setDifficulty(int v);
    void setMpPathFinding(unsigned char v);
    void setPlayerCDAndVersion(int idx, unsigned char v);
    void setPlayerTeam(int idx, int v);

    void set_game_options(RGE_Game_Options* opt);
};

void RGE_Base_Game::set_game_options(RGE_Game_Options* opt)
{
    int i;

    this->setVersion(opt->versionValue);
    this->setScenarioGame(opt->scenarioGameValue);
    this->setScenarioName(opt->scenarioNameValue);
    this->setSinglePlayerGame(opt->singlePlayerGameValue);
    this->setMultiplayerGame(opt->multiplayerGameValue);
    this->setMapSize(opt->mapXSizeValue, opt->mapYSizeValue,
                     opt->mapZSizeValue);
    this->setAllowCheatCodes(opt->allowCheatCodesValue);
    this->setCheatNotification(opt->cheatNotificationValue);
    this->setFullVisibility(opt->fullVisibilityValue);
    this->setFogOfWar(opt->fogOfWarValue);
    this->setColoredChat(opt->coloredChatValue);
    this->setNumberPlayers(opt->numberPlayersValue);
    this->setGameDeveloperMode(opt->gameDeveloperModeValue);
    this->setDifficulty(opt->difficultyValue);
    this->setMpPathFinding(opt->mpPathFindingValue);

    for (i = 0; i < 9; i++) {
        this->setPlayerCDAndVersion(i, opt->playerCDAndVersionValue[i]);
        this->setPlayerTeam(i, opt->playerTeamValue[i]);
    }
}

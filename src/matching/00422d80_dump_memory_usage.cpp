class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3C];
    int error_code_;
    char gap_44[0x4C4];
    int world_update_count_;
    int view_update_count_;
    char gap_510[4];
    int last_world_update_count_;
    int last_view_update_count_;
    char gap_51C[0x3DC];
    float version_;
    unsigned char scenarioGame_;
    char scenarioName_[0x80];
    unsigned char singlePlayerGame_;
    unsigned char multiplayerGame_;
    unsigned char mapXSize_;
    unsigned char mapYSize_;
    unsigned char mapZSize_;
    unsigned char allowCheatCodes_;
    unsigned char mpPathFinding_;
    unsigned char cheatNotification_;
    unsigned char fullVisibility_;
    unsigned char fogOfWar_;
    unsigned char coloredChat_;
    unsigned char numberPlayers_;
    unsigned char gameDeveloperMode_;
    unsigned char cdAndVersion_[9];
    unsigned char difficulty_;
    char gap_994[0xC];
    int campaignGame_;
    int savedGame_;
    char gap_9A8[8];
    int playerID_[16];
    char gap_9F0[0x1C];
    float game_speed_;
    int single_player_difficulty_;
    unsigned char pathFinding_;

    void dump_memory_usage(int);
};

void RGE_Base_Game::dump_memory_usage(int) {
}

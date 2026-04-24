// quick-win attempt log:
// no existing work file for 0049CE40; the oracle is a multiplayer gate plus three
// virtual calls. Fixed the local screen offsets (tool_box/main_view), but the first
// mismatch is still in the initial multiplayerGame() call basin (offset 17).
// kept the direct branch order and virtual call chain; leaving this in scratch.

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

    int multiplayerGame();
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(int a, int b);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Panel_Tool_Box {
public:
    char pad_00[0x6C];
    void* field_6C;

    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int mode);
};

class TRIBE_Main_View {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(int a, int b);
};

class TRIBE_Screen_Game {
public:
    char pad_00[0x10];
    int field_14;
    int field_18;
    char pad_1C[0x49C];
    TRIBE_Main_View* main_view;
    char pad_4BC[0xC0];
    RGE_Panel_Tool_Box* tool_box;

    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);

    void command_tool_box(void);
};

void TRIBE_Screen_Game::command_tool_box(void) {
    if (rge_base_game->multiplayerGame() == 0) {
        if (this->tool_box->field_6C != 0) {
            this->tool_box->vf14(0);
        } else {
            this->tool_box->vf14(1);
        }
        this->main_view->vf50(this->field_14, this->field_18);
        rge_base_game->vf10(0, 0);
        this->vf20(1);
    }
}

class RGE_Game_World {
public:
    char gap_000[0x3C];
    short player_num;
};

class RGE_Player {
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
    char gap_000[0x38];
    RGE_Game_World* world;

    virtual void setDiplomaticStance(int target_id, int stance);
};

class MainDecisionAIModule {
public:
    char gap_000[0xF0];
    RGE_Player* player;
};

class DiplomacyAIModule {
public:
    char gap_000[0xF0];
    MainDecisionAIModule* md;
    int dislikeTable[10];
    int likeTable[10];
    unsigned char changeableTable[10];

    void setRelation(int player_id, int stance);
};

void DiplomacyAIModule::setRelation(int player_id, int stance) {
    if (player_id > 0) {
        if (player_id < this->md->player->world->player_num) {
            if (this->changeableTable[player_id] != 0) {
                this->md->player->setDiplomaticStance(player_id, stance);
            }
        }
    }
}

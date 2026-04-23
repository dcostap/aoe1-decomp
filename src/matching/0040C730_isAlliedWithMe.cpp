class RGE_Player;
class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x2];
    RGE_Player** players;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class DiplomacyAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;

    int isAlliedWithMe(int player_num) const;
};

class RGE_Player {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual int isAlly(int player_id);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0xA];
    short id;
};

int DiplomacyAIModule::isAlliedWithMe(int player_num) const
{
    if (0 < player_num) {
        RGE_Player* me = this->md->player;
        RGE_Game_World* world = me->world;
        if (player_num < world->player_num) {
            RGE_Player* other = world->players[player_num];
            if (other != 0) {
                if (other->isAlly((int)me->id) != 0)
                    return 1;
            }
        }
    }

    return 0;
}

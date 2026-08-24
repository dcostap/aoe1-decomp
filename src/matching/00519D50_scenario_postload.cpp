#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Player {
public:
    void scenario_postload(int param_1, long* param_2, float param_3);
};

class RGE_Game_World {
public:
    void update_mutual_allies(void);
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x10];
    void* info;
    char gap_54[0xAC];
    int mutual_allies_loaded;

    void scenario_postload(int param_1, long* param_2, float param_3);
};
#endif

void TRIBE_Player::scenario_postload(int param_1, long* param_2, float param_3) {
    RGE_Player::scenario_postload(param_1, param_2, param_3);
    if (0.0 < *(float*)((char*)this->info + 0xC8)) {
        this->mutual_allies_loaded = 1;
        this->world->update_mutual_allies();
    }
}

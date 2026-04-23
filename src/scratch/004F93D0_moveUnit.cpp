// tried loading md/player first and then the full dispatch; VC5 still insists on preloading the last stack arg
// remaining mismatch is the entry prolog/register basin, not the call target or argument count
class RGE_Player;
class TribeMainDecisionAIModule;

class RGE_Player {
public:
    void** vtable_ptr;
    char gap_04[0x4A - 0x4];
    short id;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;

    int moveUnit(int param_1, float param_2, float param_3, int param_4);
};

typedef void (*PlayerMoveUnit)(RGE_Player*, short, int, int, int, int, float, float, float, float, int, int, int);

int TribeTacticalAIModule::moveUnit(int param_1, float param_2, float param_3, int param_4) {
    TribeMainDecisionAIModule* md = this->md;
    RGE_Player* player = md->player;

    ((PlayerMoveUnit)player->vtable_ptr[0x30 / 4])(player, player->id, param_1, 0x2C6, -1, -1, param_2, param_3, 1.0f, 1.0f, 1, 0, param_4);
    return 1;
}

class RGE_Visible_Map {
public:
    float percentExplored();
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
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
    char gap_04[0xA0];
    int sn[226];

    int initialExplorationSatisfied();
};

int TribeTacticalAIModule::initialExplorationSatisfied()
{
    int iVar1;

    if (this->sn[0xA7] <= 0)
        return 1;

    iVar1 = (int)(this->md->player->visible->percentExplored() * 100.0f);
    return iVar1 >= this->sn[0xA7];
}

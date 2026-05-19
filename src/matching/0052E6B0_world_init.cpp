// VA: 0052E6B0 TRIBE_World::world_init
// PDB source: tworld.cpp
// Attempt log:
// try 1: natural member implementation with base world_init and TRIBE_Tech allocation.

void* operator new(unsigned int size);

class TSound_Driver;
class TCommunications_Handler;

class RGE_Game_World {
public:
    virtual void world_init(int param_1, TSound_Driver* sound, TCommunications_Handler* comm);
};

class TRIBE_World;

class TRIBE_Tech {
public:
    char gap_00[0x0C];
    TRIBE_Tech(int param_1, TRIBE_World* world);
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_004[0x104 - 0x004];
    TRIBE_Tech* tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    char countdown_victory;
    char gap_115[3];
    int countdown_clock;
    char score_displayed;

    virtual void world_init(int param_1, TSound_Driver* sound, TCommunications_Handler* comm);
};

void TRIBE_World::world_init(int param_1, TSound_Driver* sound, TCommunications_Handler* comm)
{
    RGE_Game_World::world_init(param_1, sound, comm);

    TRIBE_Tech* new_tech = new TRIBE_Tech(param_1, this);
    this->tech = new_tech;
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0;
    this->score_displayed = 0;
}

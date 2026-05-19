// VA: 0052E350 TRIBE_World::data_load_world
// tworld.cpp:210-227
// FLAGS: /GX

#include <stdio.h>
#include <stdlib.h>

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* f);
};

class TRIBE_Tech {
public:
    char gap_00[0x0C];
    TRIBE_Tech(char* tech_file);
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_004[0x100];
    TRIBE_Tech* tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    unsigned char countdown_victory;
    char gap_115[3];
    float countdown_clock;
    unsigned char score_displayed;

    virtual unsigned char data_load_world(FILE* f);
};

unsigned char TRIBE_World::data_load_world(FILE* f)
{
    char tech_file[23];

    RGE_Game_World::data_load_world(f);
    fscanf(f, "%s ", tech_file);
    this->tech = new TRIBE_Tech(tech_file);
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;
    return 1;
}

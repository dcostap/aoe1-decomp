// 0052C230 T_Scenario::set_player_tech
// Source: tscenaro.cpp lines 1045-1093
// attempt 1: natural source from packet and neighboring WriteDisabledTechnologiesToMainSystem; code shape exact but edi based at flags, producing short [edi+small] addressing and object too small.
// attempt 2: model disabled_tech as int[16][20] and use this->disabled_tech[i][j]; MATCH. This makes VC5 keep index*80 separate and use [edi+large member offset] addressing like original.

#include "../../include/tscenaro_context.h"

#if 0
struct IntfProxy {
    virtual void v00();
    virtual void v04();
    virtual void call08(int, void*);
};

class TRIBE_Player_Tech {
public:
    unsigned char check_for_new_tech();
};

class TRIBE_Player {
public:
    char gap_00[0x4A];
    short player_number;          // +0x4A
    char gap_4C[4];
    void* object_50;              // +0x50
    char gap_54[0x1CC];
    TRIBE_Player_Tech* tech_tree; // +0x220

    void tech_abling(int tech_id, uchar enable);
    void rev_tech(int tech_id);
};

class RGE_Game_World {
public:
    char gap_00[0x4C];
    IntfProxy* field_4C;
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
};

extern RGE_Base_Game* rge_base_game;
#pragma comment(linker, "/include:_rge_base_game")

class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    void* time_line;
    RGE_Game_World* world;
    char gap_0C[0x1984];
};

class T_Scenario : public RGE_Scenario {
public:
    char gap_1990[0x3264];
    int disabled_tech[16][20];    // +0x4BF4
    int scenario_options;         // +0x50F4
    int option_by_player[8];      // +0x50F8-ish

    void set_player_tech(TRIBE_Player* player);
};
#endif

#define RGE_BASE_GAME (*(RGE_Base_Game**)0x0062C574)

void T_Scenario::set_player_tech(TRIBE_Player* player)
{
    int i = player->player_number;
    i--;
    if (i < 0) {
        return;
    }

    player->tech_abling(0x58, (uchar)this->DisabledTechnology[i][0]);
    player->tech_abling(0x59, (uchar)this->DisabledTechnology[i][1]);
    player->tech_abling(0x5A, (uchar)this->DisabledTechnology[i][2]);
    player->tech_abling(0x5B, (uchar)this->DisabledTechnology[i][3]);
    player->tech_abling(0x5E, (uchar)this->DisabledTechnology[i][4]);
    player->tech_abling(0x5F, (uchar)this->DisabledTechnology[i][5]);
    player->tech_abling(0x61, (uchar)this->DisabledTechnology[i][6]);
    player->tech_abling(0x62, (uchar)this->DisabledTechnology[i][7]);
    player->tech_abling(0x5D, (uchar)this->DisabledTechnology[i][8]);
    player->tech_abling(0x60, (uchar)this->DisabledTechnology[i][9]);
    player->tech_abling(0x5C, (uchar)this->DisabledTechnology[i][10]);
    player->tech_abling(0x65, (uchar)this->DisabledTechnology[i][11]);
    player->tech_abling(0x66, (uchar)this->DisabledTechnology[i][12]);
    player->tech_abling(0x67, (uchar)this->DisabledTechnology[i][13]);
    player->tech_abling(0x73, (uchar)this->DisabledTechnology[i][14]);
    player->tech_abling(0x74, (uchar)this->DisabledTechnology[i][15]);

    player->tech_tree->check_for_new_tech();

    if (this->ScenarioOptions[0] != 0) {
        this->world->field_4C->call08(100, player);
    }

    if (RGE_BASE_GAME->prog_mode != 7) {
        switch (*(int*)((char*)this + 0x5100 + i * 4)) {
        case 1:
            player->rev_tech(0x19);
            break;
        case 2:
            player->rev_tech(0x17);
            break;
        case 3:
            player->rev_tech(0x18);
            break;
        case 4:
            player->rev_tech(1);
            break;
        }
    }

    if ((float)this->DisabledTechnology[i][14] == 0.0f) {
        *(int*)((char*)player->object_50 + 0xC0) = 0x3F800000;
    }
}

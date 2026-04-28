// 004ADA70 TRIBE_Screen_Sed::scenario_get_default_name
// Size: 116 bytes

#include <stdio.h>
#include <string.h>

extern void* rge_base_game;

class RGE_Scenario {
public:
    char* Get_scenario_name(void);
    void Set_scenario_name(char* name);
};

class RGE_Game_World {
public:
    char gap_00[0x5C];
    RGE_Scenario* scenario; // +0x5C
};

class TRegistry {
public:
    int RegGetInt(int default_val, const char* key);
};

class RGE_Base_Game {
public:
    char gap_00[0x1AC];
    TRegistry* registry; // +0x1AC
};

class TRIBE_Screen_Sed {
public:
    char gap_00[0x928];
    RGE_Game_World* world; // +0x928

    char* scenario_get_default_name(void);
};

char* TRIBE_Screen_Sed::scenario_get_default_name() {
    char temp_name[260];
    char* name;

    name = this->world->scenario->Get_scenario_name();
    if (name == 0 || name[0] == 0) {
        int file_num = ((RGE_Base_Game*)rge_base_game)->registry->RegGetInt(0, "Game File Number");
        sprintf(temp_name, "default%d.scx", file_num);
        this->world->scenario->Set_scenario_name(temp_name);
    }
    return this->world->scenario->Get_scenario_name();
}

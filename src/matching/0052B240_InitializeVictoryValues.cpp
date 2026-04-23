#include <string.h>

class RGE_Static_Object;

struct Victory_StartInfo {
    int MP_Conquest;
    int MP_Ruins;
    int MP_Artifacts;
    int MP_Discoveries;
    int MP_Exploration;
    int MP_Gold;
};

struct SP_Victory_Info {
    int ObjType;
    int AllFlag;
    int PlayerID;
    int DestObjID;
    float x1;
    float y1;
    float x2;
    float y2;
    int VictoryType;
    int Amount;
    int AttribType;
    int obj_ID;
    int dest_obj_ID;
    RGE_Static_Object* obj;
    RGE_Static_Object* dest_obj;
};

class T_Scenario {
public:
    char gap_0[0x1A90];
    Victory_StartInfo victory;
    SP_Victory_Info sp_victory[16][12];

    void InitializeVictoryValues();
};

void T_Scenario::InitializeVictoryValues() {
    int* victory_values;
    int i;

    this->victory.MP_Conquest = 1;
    this->victory.MP_Ruins = 0;
    this->victory.MP_Artifacts = 0;
    this->victory.MP_Discoveries = 0;
    this->victory.MP_Exploration = 0;
    this->victory.MP_Gold = 0;

    victory_values = &this->sp_victory[0][0].ObjType;
    for (i = 0; i < 0xB40; i++) {
        victory_values[i] = 0;
    }
}

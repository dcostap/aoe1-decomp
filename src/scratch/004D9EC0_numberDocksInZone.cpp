// 004D9EC0 TribeInformationAIModule::numberDocksInZone(int, RGE_Zone_Map*)
// Source: taiinfmd.cpp lines 1816-1828
// Size: 249 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 codegen drift (75.9% positional, 43.8% edit diff)
//
// Attempt log:
// Probe 1: initial — 75.9% positional, 249 bytes match
//
// Key findings (same pattern as numberFarmers/idleSoldier):
// - playerBuildings at +0x190 (value, numberValue=+0x194, maxSize=+0x19C)
// - md at +0x100 for object lookup
// - master_obj->id at [obj+8]->[+10h] == 0x2D = 45 (dock)
// - ftol(obj->z +0x3C) → y, ftol(obj->y +0x38) → x
// - get_zone_info(x, y) → byte, compared with param_1
// - Result stored at [esp+8]
//
// Remaining drift:
// - Prologue: push ecx vs sub esp,8
// - Early return: inline vs jump to common epilogue
// - Expansion check: cmp+jl vs mov+dec+cmp+jle
// - Copy loop: register allocation (same as other scanners)

extern "C" void* _new(unsigned int);
extern "C" void _delete(void*);

struct RGE_Static_Object;

struct MainDecisionAIModule {
    char pad_00[0xF0];
    int* _something;
    RGE_Static_Object* object(int id);
};

struct RGE_Zone_Map {
    unsigned char get_zone_info(int x, int y);
};

struct RGE_Static_Object {
    char pad_00[0x8];
    void* master_obj;          // +0x08
    char pad_0C[0x2C];         // +0x0C to +0x37
    float y;                   // +0x38
    float z;                   // +0x3C
};

struct TribeInformationAIModule {
    char pad_00[0x100];
    MainDecisionAIModule* md;   // +0x100
    char pad_104[0x8C];         // +0x104 to +0x18F
    // playerBuildings ManagedArray at +0x190
    int* playerBuildings_value;     // +0x190
    int playerBuildings_numberValue; // +0x194
    int playerBuildings_desiredNumberValue; // +0x198
    int playerBuildings_maximumSizeValue; // +0x19C

    int numberDocksInZone(int param_1, RGE_Zone_Map* param_2);
};

int TribeInformationAIModule::numberDocksInZone(int param_1, RGE_Zone_Map* param_2)
{
    int result = 0;
    int i = 0;

    if (playerBuildings_numberValue <= 0)
        return result;

    do {
        if (i >= playerBuildings_maximumSizeValue) {
            int* newArr = (int*)_new((i + 1) * 4);
            if (newArr != 0) {
                for (int j = 0; j < playerBuildings_maximumSizeValue && j < i + 1; j++)
                    newArr[j] = playerBuildings_value[j];
                _delete(playerBuildings_value);
                playerBuildings_value = newArr;
                playerBuildings_maximumSizeValue = i + 1;
            }
        }

        int unitID = playerBuildings_value[i];
        RGE_Static_Object* obj = md->object(unitID);
        if (obj != 0 && *(unsigned short*)((char*)obj->master_obj + 0x10) == 0x2D) {
            int y = (long)obj->z;
            int x = (long)obj->y;
            unsigned char zone = param_2->get_zone_info(x, y);
            if ((unsigned int)zone == param_1)
                result++;
        }
        i++;
    } while (i < playerBuildings_numberValue);

    return result;
}

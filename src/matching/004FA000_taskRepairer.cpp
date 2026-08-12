// VA: 004FA000 TribeTacticalAIModule::taskRepairer (366 B)
// PDB source: taitacmd.cpp:8414-8438
// __thiscall, returns 0/1
//
// Attempt log:
// - Replaced the raw-offset/free-function scaffold with the period-typed
//   MainDecision/world lookup, RGE_Static_Object::canPath call, distance and
//   priority calls, ManagedIntArray growth, and player order dispatch.
// - Baseline typed reconstruction follows the exact taskBuilder and
//   taskFollower donors in the same translation unit.
// - Baseline was 366/366 bytes with one relocation mismatch: canPath emitted
//   at vslot +0x198 instead of the observed +0x194.
// - Removed the final padding virtual before the six-argument canPath surface;
//   this restored vslot +0x194 and produced MATCH, 366/366 bytes.
// - Final source keeps named object/world/player ownership and the natural
//   ManagedIntArray scan/growth idiom. Default flags; no inline asm.

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class RGE_Game_World;

class RGE_Player {
public:
    VPAD8(g0) VPAD4(g8)
    virtual void sendUnitAIOrder(int player, int param, int action, int unitId,
                                 int player2, float x, float y, float z,
                                 float f, int a, int b, int priority);
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD64(0) VPAD32(64) VPAD4(96)
    virtual int canPath(int objectId, float distance, float* path,
                        int arg4, int arg5, int arg6);
    int id;
    char gap_08[0x30];
    float world_x;
    float world_y;
    float world_z;

    float distance_to_object(RGE_Static_Object* object);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;

    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int calculatePriority(float distance);
    int taskRepairer(int id, RGE_Static_Object* repairer);
};

int TribeTacticalAIModule::taskRepairer(int id, RGE_Static_Object* repairer)
{
    RGE_Static_Object* object = this->md->player->world->object(id);
    if (object == 0) {
        return 0;
    }

    if (object->canPath(repairer->id, 1.0f, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize)
            break;
        if (arr.value[i] == id)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSize - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSize && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSize = newSize;
        }
    }

    arr.value[arr.numberValue] = id;
    arr.numberValue++;

dispatch:
    float distance = repairer->distance_to_object(object);
    int priority = this->calculatePriority(distance);
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(player->id, id, 0x2CE, repairer->id,
                            player->id, repairer->world_x, repairer->world_y,
                            repairer->world_z, 1.0f, 1, 0, priority);
    return 1;
}

// VA: 004F9E00 TribeTacticalAIModule::taskBuilder
// Source: taitacmd.cpp lines 8350-8408
// Attempt log:
// 1: natural reconstruction with typed virtual calls and dynamic int-list growth: broad mismatch, 0x18 frame due aggregate/int temps.
// 2: reduced local lifetimes and removed aggregate source temps; still got 0x18 frame.
// 3: marked coordinate temps register to try to keep ftol results in EBX/EBP/EAX; no frame change.
// 4: inline coordinate casts directly into virtual calls to reduce named temp pressure; restored one-slot frame, but cached obj in EBP.
// 5: make obj volatile forced stack reloads but ordered store before test.
// 6: assignment-in-condition with nonvolatile obj restored store-after-test shape but cached obj in EBP.
// 7: restore named x/y/z before builder null check because original does all ftol before null test; code shrank below target and still frame/register mismatch.
// 8: tried narrow /O1 flag as possible code-size/register-pressure probe; smaller object and worse, flag removed.
// 9: tried /O2 /Oy /Ob0 to see if call/virtual inlining context caused frame/register changes; no improvement, flag removed.
// 10: left in scratch: best default family either has exact prologue with obj cached in EBP and delayed ftol, or correct ftol-before-null shape with a 0x18 spill frame. Remaining mismatch is broad register/liveness and virtual-call argument scheduling, not behavior.
// Session sa080eb53d_r1:
// - Reconstructed the first virtual call as canPath(XYZPoint, float, int, float*, int, int, int); the 0xc outgoing aggregate and three ftol results are binary-proven.
// - Mirrored the same-TU ManagedIntArray indexed scan and natural new[]/delete[] bounded copy idiom; this restored the target loop CFG and size family.
// - Split distance_to_object and calculatePriority into sequential locals; this restored the original 505-byte suffix topology.
// - Widened the RGE_Player sendUnitAIOrder player-id arguments to int, recovering the movsx/player-vtable load order and exact bytes.
// - Normalized module ownership to TribeTacticalAIModule -> TribeMainDecisionAIModule -> RGE_Player, preserving the proven offsets and exact output.
// Final: default /O2 /Oy, 505/505 bytes, MATCH; no inline asm or custom flags.

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Master_Object { public: char gap_00[0x10]; short id; };

struct XYZPoint {
    int x;
    int y;
    int z;
};

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class RGE_Static_Object {
public:
    VPAD64(0) VPAD32(64) VPAD4(96) VPAD2(100)
    virtual int canPath(struct XYZPoint point, float f, int objectId,
                        float* path, int a, int b, int c);
    int id;
    RGE_Master_Object* master_obj;
    char gap_0C[0x38 - 0x0C];
    float world_x;
    float world_y;
    float world_z;
    float distance_to_object(RGE_Static_Object* obj);
};

class RGE_Game_World { public: RGE_Static_Object* object(int id); };

class RGE_Player {
public:
    VPAD8(g0) VPAD4(g8)
    virtual void sendUnitAIOrder(int player, int param, int action, int unitId,
                                 int player2, float x, float y, float z, float f,
                                 int a, int b, int priority);
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

extern void* operator new(unsigned int sz);
extern void operator delete(void* p);

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC]; TribeMainDecisionAIModule* md;
    char gap_0F4[0xD58 - 0xF4]; ManagedIntArray tasked;
    int deleteUnit(int id);
    int calculatePriority(float distance);
    int taskBuilder(int id, RGE_Static_Object* builder);
};

int TribeTacticalAIModule::taskBuilder(int id, RGE_Static_Object* builder)
{
    RGE_Static_Object* builderObj;
    RGE_Static_Object* obj;
    if ((obj = this->md->player->world->object(id)) == 0) return 0;

    builderObj = builder;
    XYZPoint point;
    point.x = (int)builderObj->world_x;
    point.y = (int)builderObj->world_y;
    point.z = (int)builderObj->world_z;

    if (builderObj == 0) {
        if (!obj->canPath(point, 1.0f, -1, 0, 1, -1, -1)) return 0;
    }
    else {
        if (!obj->canPath(point, 1.0f, builderObj->id, 0, 1, -1, -1)) {
            if (builderObj->master_obj->id != 0x114) this->deleteUnit(builderObj->id);
            return 0;
        }
    }

    ManagedIntArray& arr = this->tasked;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize)
            break;
        if (arr.value[i] == id)
            goto found;
    }

    if (arr.numberValue > arr.maximumSize - 1) {
        int newMax = arr.numberValue + 1;
        int* newValues = new int[newMax];
        if (newValues != 0) {
            int j;
            for (j = 0; j < arr.maximumSize && j < newMax; j++) {
                newValues[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newValues;
            arr.maximumSize = newMax;
        }
    }
    arr.value[arr.numberValue] = id;
    arr.numberValue++;

found:
    float distance = builderObj->distance_to_object(obj);
    int priority = this->calculatePriority(distance);
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(player->id, id, 0x2be, builderObj->id,
                            player->id, builderObj->world_x, builderObj->world_y,
                            builderObj->world_z, 1.0f, 1, 1, priority);
    return 1;
}

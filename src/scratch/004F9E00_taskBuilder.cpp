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

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Master_Object { public: char gap_00[0x10]; short id; };

class RGE_Static_Object {
public:
    VPAD64(0) VPAD32(64) VPAD4(96) VPAD2(100)
    virtual int task_builder_action(int x, int y, int z, float f, int a, int b, int c, int d, int e);
    int id;
    RGE_Master_Object* master_obj;
    char gap_0C[0x38 - 0x0C];
    float world_x;
    float world_y;
    float world_z;
    float distance_to_object(RGE_Static_Object* obj);
};

class RGE_Game_World { public: RGE_Static_Object* object(int id); };

class GameThing {
public:
    VPAD8(g0) VPAD4(g8)
    virtual void issue(short player, int param, int action, int unitId, short player2, float x, float y, float z, float f, int a, int b, int priority);
    char gap_04[0x4A - 0x04];
    short player_id;
};

class ModuleData2 { public: char gap_00[0x3C]; RGE_Game_World* world; };
class ModuleData { public: char gap_00[0xF0]; ModuleData2* md; };
extern void* operator new(unsigned int sz);
extern void operator delete(void* p);

class TribeTacticalAIModule {
public:
    char gap_00[0xF0]; ModuleData* md;
    char gap_0F4[0xD58 - 0xF4]; int* taskedValues; int taskedNumber; char gap_D60[4]; int taskedMax;
    int deleteUnit(int id);
    int calculatePriority(float distance);
    int taskBuilder(int id, RGE_Static_Object* builder);
};

int TribeTacticalAIModule::taskBuilder(int id, RGE_Static_Object* builder)
{
    RGE_Static_Object* obj;
    if ((obj = this->md->md->world->object(id)) == 0) return 0;

    int x = (int)builder->world_x;
    int y = (int)builder->world_y;
    int z = (int)builder->world_z;

    if (builder == 0) {
        if (!obj->task_builder_action(x, y, z, 1.0f, -1, 0, 1, -1, -1)) return 0;
    }
    else {
        if (!obj->task_builder_action(x, y, z, 1.0f, builder->id, 0, 1, -1, -1)) {
            if (builder->master_obj->id != 0x114) this->deleteUnit(builder->id);
            return 0;
        }
    }

    int i = 0;
    int n = this->taskedNumber;
    if (n > 0) {
        do {
            if (i >= this->taskedMax) break;
            if (this->taskedValues[i] == id) goto found;
            i++;
        } while (i < n);
    }

    if (n > this->taskedMax - 1) {
        int newMax = n + 1;
        int* newValues = (int*)operator new(newMax * 4);
        if (newValues != 0) {
            i = 0;
            if (this->taskedMax > 0) {
                do {
                    if (i >= newMax) break;
                    newValues[i] = this->taskedValues[i];
                    i++;
                } while (i < this->taskedMax);
            }
            operator delete(this->taskedValues);
            this->taskedValues = newValues;
            this->taskedMax = newMax;
        }
    }
    this->taskedValues[this->taskedNumber] = id;
    this->taskedNumber = this->taskedNumber + 1;

found:
    GameThing* gt = (GameThing*)this->md->md;
    gt->issue(gt->player_id, id, 0x2be, builder->id, gt->player_id, builder->world_x, builder->world_y, builder->world_z, 1.0f, 1, 1, this->calculatePriority(builder->distance_to_object(obj)));
    return 1;
}

// VA: 00417960 UnitAIModule::askForHelp(int) (493B)
// aiuaimod.cpp:4005-4113
//
// Attempt log:
// - Replaced the placeholder with the binary-supported visible-unit bucket
//   scan.  The caller object is looked up first, then the five populated
//   visible-unit buckets are searched for nearby idle allied units.
// - The natural typed array form with repeated entry expressions reproduces
//   the 493-byte frame/size and all 15 ordered calls; a saved object-id local
//   collapsed the pointer/index schedule and was rolled back.
// - Binary evidence fixes the state guard at <= 2 and this routine's outer
//   scan at the two populated buckets (the emitted byte-offset loop compares
//   its cursor with 4).  The late scan and final dispatch blocks now align.
// - Remaining best drift is 20 bytes (4 edit bytes): the first hunk is the
//   declaration/evaluation order of the target unit-AI pointer versus the
//   caller Y local at 00417AC5-00417AD5.  A future worker should try declaring
//   targetAI before `float y = callerObject->world_y`; no further hypothesis
//   was spent after the ten-probe budget.

struct VisibleUnitRecord {
    int object_id;
    unsigned char distance;
    unsigned char owner;
    unsigned char pos_x;
    unsigned char pos_y;
};

extern int DAT_0087d7cc[5];
extern VisibleUnitRecord* DAT_0087d7e4[5];
extern float DAT_0056ebec;

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int isAlly(int player_id); // +0x1c

    char gap_04[0x46];
    short id;                           // +0x4a
};

class UnitAIModule;

#define RGE_STATIC_VPAD1(n) virtual void rge_static_vpad##n();
#define RGE_STATIC_VPAD2(n) RGE_STATIC_VPAD1(n) RGE_STATIC_VPAD1(n##_1)
#define RGE_STATIC_VPAD4(n) RGE_STATIC_VPAD2(n) RGE_STATIC_VPAD2(n##_2)
#define RGE_STATIC_VPAD8(n) RGE_STATIC_VPAD4(n) RGE_STATIC_VPAD4(n##_4)
#define RGE_STATIC_VPAD16(n) RGE_STATIC_VPAD8(n) RGE_STATIC_VPAD8(n##_8)
#define RGE_STATIC_VPAD32(n) RGE_STATIC_VPAD16(n) RGE_STATIC_VPAD16(n##_16)
#define RGE_STATIC_VPAD64(n) RGE_STATIC_VPAD32(n) RGE_STATIC_VPAD32(n##_32)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    RGE_STATIC_VPAD64(0)
    RGE_STATIC_VPAD2(64)
    virtual float method_10c(int a, int b, int c); // +0x10c

    int id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                   // +0x0c
    char gap_10[0x28];                   // +0x10..+0x37
    float world_x;                       // +0x38
    float world_y;                       // +0x3c
    char gap_40[0x08];                   // +0x40..+0x47
    unsigned char object_state;          // +0x48

    UnitAIModule* unitAI();
    float distance_to_object(RGE_Static_Object* other);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual void search(); // +0x20

    RGE_Static_Object* objectValue; // +0x04

    RGE_Static_Object* lookupObject(int object_id);
    int currentAction();
    int currentOrder();
    int orderQueueSize();
    void askForHelp(int caller);
};

void UnitAIModule::askForHelp(int caller)
{
    RGE_Static_Object* callerObject = this->lookupObject(caller);
    if (callerObject != 0) {
        this->search();

        int category = 0;
        do {
            int i = 0;
            if (DAT_0087d7cc[category] > 0) {
                do {
                    if (this->objectValue->id != DAT_0087d7e4[category][i].object_id) {
                        RGE_Static_Object* object =
                            this->lookupObject(DAT_0087d7e4[category][i].object_id);
                        if (object != 0 && object->unitAI() != 0) {
                            RGE_Player* owner = object->owner;
                            if (owner != 0 && object->object_state <= 2) {
                                short group = object->master_obj->object_group;
                                if (group != 1 && group != 3 && group != 4 &&
                                    group != 0x15 && group != 0x12 &&
                                    group != 0x14 && group != 0x1b) {
                                    short ownerId = this->objectValue->owner->id;
                                    if (owner->id == ownerId || owner->isAlly(ownerId)) {
                                        if (this->objectValue->distance_to_object(object) <= 3.0f) {
                                            if (object->unitAI()->currentAction() == -1) {
                                                if (object->unitAI()->currentOrder() == -1) {
                                                    if (object->unitAI()->orderQueueSize() <= 0) {
                                                        float y = callerObject->world_y;
                                                        UnitAIModule* targetAI = object->unitAI();
                                                        targetAI->order(
                                                            object->owner->id,
                                                            0x2bc,
                                                            caller,
                                                            callerObject->owner->id,
                                                            callerObject->world_x,
                                                            y,
                                                            y,
                                                            object->method_10c(1, 0, 0x32));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    ++i;
                } while (i < DAT_0087d7cc[category]);
            }
            ++category;
        } while (category <= 1);
    }
}

#undef RGE_STATIC_VPAD64
#undef RGE_STATIC_VPAD32
#undef RGE_STATIC_VPAD16
#undef RGE_STATIC_VPAD8
#undef RGE_STATIC_VPAD4
#undef RGE_STATIC_VPAD2
#undef RGE_STATIC_VPAD1

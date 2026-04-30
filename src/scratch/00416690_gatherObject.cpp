// VA: 00416690 gatherObject (148B)
// Fully typed approach

struct ObjVtable {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68();
    virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7C(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98();
    virtual void v9C(); virtual void vA0(); virtual void vA4();
    virtual void vA8(); virtual void vAC(); virtual void vB0();
    virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8();
    virtual void vCC(); virtual void vD0(); virtual void vD4();
    virtual void vD8(); virtual void vDC(); virtual void vE0();
    virtual void vE4(); virtual void vE8(); virtual void vEC();
    virtual void vF0(); virtual void vF4(); virtual void vF8();
    virtual void vFC(); virtual void v100(); virtual void v104();
    virtual void v108(); virtual void v10C(); virtual void v110();
    virtual void v114(); virtual void v118(); virtual void v11C();
    virtual void v120(); virtual void v124(); virtual void v128();
    virtual void v12C(); virtual void v130(); virtual void v134();
    virtual void v138(); virtual void v13C(); virtual void v140();
    virtual void v144(); virtual void v148(); virtual void v14C();
    virtual void v150(); virtual void v154(); virtual void v158();
    virtual void v15C(); virtual void v160(); virtual void v164();
    virtual int canAction(int targetId, int flag);
};

struct RGE_Static_Object;
struct RGE_Game_World {
    virtual void _v00();
    RGE_Static_Object* object(int id);
};

struct RGE_Player {
    // vtable at +0x00
    char pad_3C[0x3C - 4];  // pad from +0x04 to +0x3B
    RGE_Game_World* world;  // +0x3C
};

// RGE_Static_Object has vtable at +0x00, then fields
struct RGE_Static_Object {
    virtual void _v00();     // vfptr at +0x00
    int id;                  // +0x04
    void* master;            // +0x08
    RGE_Player* owner;       // +0x0C
    int x;                   // +0x38
    int y;                   // +0x3C
    int z;                   // +0x40
    char pad_10[0x38 - 0x10]; // pad to +0x38
};

struct RGE_Master_Static_Object {
    char pad_00[0x14];
    short object_group;      // +0x14
};

class UnitAIModule {
public:
    RGE_Static_Object* objectValue;  // +0x04
    int moodValue;                   // +0x08
    int objectCategoryValue;         // +0x0C
    int orderQueueSizeValue;         // +0x10
    int orderQueueMaxSizeValue;      // +0x14
    void* orderQueueValue;           // +0x18
    int notifyQueueSizeValue;        // +0x1C
    int notifyQueueMaxSizeValue;     // +0x20
    void* notifyQueueValue;          // +0x24
    int currentOrderValue;           // +0x28
    int currentOrderPriorityValue;   // +0x2C
    int currentActionValue;          // +0x30

    int gatherObject(int targetId, int flag);
    void setCurrentAction(int action);
    void setCurrentTarget(int targetId, int group, int x, int y, int z);
    virtual ~UnitAIModule();
};

int UnitAIModule::gatherObject(int targetId, int flag) {
    if (flag == 0 && currentActionValue == 0x261) return 0;

    int result = ((ObjVtable*)(void*)objectValue)->canAction(targetId, flag);
    if (result != 1) return 0;

    RGE_Static_Object* target = objectValue->owner->world->object(targetId);

    setCurrentAction(0x261);

    if (target == 0) {
        setCurrentTarget(targetId, 0, 0, 0, 0);
    } else {
        short group = ((RGE_Master_Static_Object*)target->master)->object_group;
        setCurrentTarget(targetId, group, target->x, target->y, target->z);
    }
    return 1;
}

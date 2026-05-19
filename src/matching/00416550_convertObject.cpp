// VA: 00416550 convertObject (148B)
// Based on matched gatherObject/buildObject siblings.
// Sibling pattern: inverted condition, nested success, shared return-0 tail.

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
    virtual void v168();
    virtual int canAction(int targetId, int flag);
};

struct RGE_Static_Object;
struct RGE_Game_World {
    virtual void _v00();
    RGE_Static_Object* object(int id);
};

struct RGE_Player {
    virtual void _v00();
    char pad_04[0x3C - 0x04];
    RGE_Game_World* world;
};

struct RGE_Static_Object {
    virtual void _v00();
    int id;
    void* master;
    RGE_Player* owner;
    char pad_10[0x38 - 0x10];
    int x;
    int y;
    int z;
};

struct RGE_Master_Static_Object {
    char pad_00[0x14];
    short object_group;
};

class UnitAIModule {
public:
    RGE_Static_Object* objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    void* orderQueueValue;
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    void* notifyQueueValue;
    int currentOrderValue;
    int currentOrderPriorityValue;
    int currentActionValue;

    int convertObject(int targetId, int flag);
    void setCurrentAction(int action);
    void setCurrentTarget(int targetId, int group, int x, int y, int z);
    virtual ~UnitAIModule();
};

int UnitAIModule::convertObject(int targetId, int flag) {
    if (flag != 0 || currentActionValue != 0x25C) {
        int result = ((ObjVtable*)(void*)objectValue)->canAction(targetId, flag);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetId);

            setCurrentAction(0x25C);

            if (target == 0) {
                setCurrentTarget(targetId, -1, 0, 0, 0);
            } else {
                short group = ((RGE_Master_Static_Object*)target->master)->object_group;
                setCurrentTarget(targetId, group, target->x, target->y, target->z);
            }
            return 1;
        }
    }
    return 0;
}

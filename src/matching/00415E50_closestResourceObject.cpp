// VA: 00415E50 UnitAIModule::closestResourceObject (235B)
// aiuaimod.cpp
//
// Canonical reconstruction: query the owning player's visible-resource list,
// rejecting already-tested resources until the object's path test succeeds.
// The 100-entry list is initialized to the historical 0x80000000 sentinel;
// the resource distance is returned through the optional integer output.
//
// Attempt log:
// - Replaced the stale placeholder with the binary-supported visible-resource
//   query, object path gate, distance check, and reject-list behavior.
// - A do/infinite-loop spelling caused VC5 to peel the first query; the
//   bounded while form restored one shared call site and the original CFG.
// - Naming the append cursor and incrementing the reject count before storing
//   the rejected ID reproduced the original EBP/EDI update order. MATCH.

extern float DAT_0056ebe0;

class Visible_Resource_Manager;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x24];
    float los;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x10C];
    Visible_Resource_Manager* VR_List;
};

class VISIBLE_RESOURCE_REC {
public:
    int object_id;
    unsigned char distance;
    unsigned char zone;
    unsigned char pos_x;
    unsigned char pos_y;
};

class Visible_Resource_Manager {
public:
    VISIBLE_RESOURCE_REC* Get_Closest_Resource(
        int x, int y, int zone, int resourceType,
        int* excludeList, int excludeCount);
};

#define VPAD1(n) virtual void vf##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Static_Object {
public:
    VPAD64(0)
    VPAD32(64)
    VPAD4(96)
    VPAD1(100)
    virtual int canPath(int objectId, float distance, float* path,
                        int param_4, int param_5, int param_6);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;

    unsigned char currentZone();
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    RGE_Static_Object* objectValue;

    virtual int closestResourceObject(int resourceType, int* distance);
};

int UnitAIModule::closestResourceObject(int resourceType, int* distance) {
    int excludeList[100];
    int* nextExclude = excludeList;
    for (int i = 0; i < 100; ++i) {
        excludeList[i] = 0x80000000;
    }

    int excludeCount = 0;
    VISIBLE_RESOURCE_REC* resource;
    while (excludeCount < 100) {
        resource = this->objectValue->owner->VR_List->Get_Closest_Resource(
            (int)this->objectValue->world_x,
            (int)this->objectValue->world_y,
            this->objectValue->currentZone(),
            resourceType,
            excludeList,
            excludeCount);
        if (resource == 0) {
            return -1;
        }

        if ((float)resource->distance >
            this->objectValue->master_obj->los - DAT_0056ebe0) {
            return -1;
        }

        if (this->objectValue->canPath(resource->object_id, 1.0f, 0,
                                       0, -1, -1) == 1) {
            break;
        }

        ++excludeCount;
        *nextExclude++ = resource->object_id;
    }

    if (distance != 0) {
        *distance = resource->distance;
    }
    return resource->object_id;
}

#undef VPAD64
#undef VPAD32
#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1

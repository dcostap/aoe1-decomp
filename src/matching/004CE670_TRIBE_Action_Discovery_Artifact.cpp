// TRIBE_Action_Discovery_Artifact ctor 3: 004CE670, tact_dar.cpp:53-61
// TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, float, float, float)
//
// tried initial draft

#include <stdlib.h>

struct DiscoverySizeInfo {
    char gap_00[0x3C];
    short size;
};

struct DiscoveryInfo {
    char gap_00[0x3C];
    DiscoverySizeInfo* size_info;
};

struct DiscoveryMaster {
    char gap_00[0x0C];
    DiscoveryInfo* info;
};

class RGE_Action_Object;
class RGE_Task;
class RGE_Static_Object;

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(RGE_Action_Object* object, int doSetup);

    unsigned short action_type;
    char gap_06[0x1A];
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    float minX;
    float minY;
    float minZ;
    float timer;
    RGE_Task* task;
    char gap_34[0x0C];
    char* flags;

    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, float fx, float fy, float fz);
};

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, float fx, float fy, float fz)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->action_type = 0x6C;
    this->minX = fx;
    this->minY = fy;
    this->minZ = fz;
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)obj)->info->size_info->size,
        1
    );
}

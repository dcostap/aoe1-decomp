// TRIBE_Action_Discovery_Artifact ctor 2: 004CE5F0, tact_dar.cpp:42-48
// TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)
//
// tried initial draft; compile error - needed member initializer list syntax
// tried fixed version; size too small (80 vs 127) - EH frame not generated
// tried /GX; still no EH frame - VC5 decides cleanup not needed
// tried adding setup() to base; still 80
// tried /O1 /Oy-; still no EH
// tried /EHa; still no EH
// PAUSED: EH frame is VC5 TU-context issue; logic correct, 47-byte size gap is EH prolog+epilog+stack bookkeeping

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
    char gap_06[0x26];

    void set_target_obj(RGE_Static_Object* obj);
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    float timer;
    RGE_Task* task;
    char gap_34[0x0C];
    char* flags;

    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
};

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(obj, 1) {
    this->action_type = 0x6C;
    this->task = task;
    this->set_target_obj(target);
    short size;
    size = ((DiscoveryMaster*)obj)->info->size_info->size;
    this->flags = (char*)calloc(size, 1);
}

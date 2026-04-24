// TRIBE_Action_Discovery_Artifact ctor 1: 004CE530, tact_dar.cpp:32-37
// TRIBE_Action_Discovery_Artifact(int file_id, RGE_Action_Object*)
//
// tried initial draft; size 96 vs 139 - EH frame not generated
// tried /GX; still no EH frame
// tried /O1 /Oy-; smaller (87)
// tried adding setup() to base; still 96
// tried extern "C" rge_read; still 96
// tried adding destructor to class; still 96
// tried /EHa; still 96
// PAUSED: EH frame is VC5 TU-context issue; logic correct, 43-byte size gap is EH prolog+epilog

#include <stdlib.h>

void rge_read(int file, void* data, int size);

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

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(int file_id, RGE_Action_Object* object, int doSetup);

    unsigned short action_type;
    char gap_06[0x12];
    int targetID;
    int target2ID;

    int setup(int mode, RGE_Action_Object* object);
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    float minX;
    float minY;
    float minZ;
    float timer;
    char gap_30[0x10];
    char* flags;

    TRIBE_Action_Discovery_Artifact(int file_id, RGE_Action_Object* obj);
};

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int file_id, RGE_Action_Object* obj)
    : RGE_Action(file_id, obj, 1) {
    this->action_type = 0x6C;
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)obj)->info->size_info->size,
        1
    );
    rge_read(file_id, this->flags,
             ((DiscoveryMaster*)obj)->info->size_info->size);
}

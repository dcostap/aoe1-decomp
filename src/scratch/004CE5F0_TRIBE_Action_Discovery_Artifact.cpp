// TRIBE_Action_Discovery_Artifact ctor: 004CE5F0, tact_dar.cpp:42-48
// EH-framed constructor; /GX response file required.
// HollowSnowdrop pass: /GX + visible virtual base dtor gets EH frame and exact size, but register/param scheduling still off (extra EDI save; obj kept in EDI for calloc chain). Current 127/127, 68.5% positional / 28.3% edit diff.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

struct DiscoverySizeInfo { char gap_00[0x3C]; short size; };
struct DiscoveryInfo { char gap_00[0x3C]; DiscoverySizeInfo* size_info; };
struct DiscoveryMaster { char gap_00[0x0C]; DiscoveryInfo* info; };

class RGE_Action_Object;
class RGE_Task;
class RGE_Static_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(RGE_Action_Object* object, int doSetup);
    void set_target_obj(RGE_Static_Object* obj);
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    char gap_04[0x2C];
    RGE_Task* task;       // +0x30
    char gap_34[0x0C];
    char* flags;          // +0x40

    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
};

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(obj, 1) {
    this->task = task;
    *(void**)this = (void*)0x575010;
    *(short*)((char*)this + 4) = 0x6C;
    this->set_target_obj(target);
    this->flags = (char*)calloc(((DiscoveryMaster*)obj)->info->size_info->size, 1);
}

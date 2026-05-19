// TRIBE_Action_Discovery_Artifact ctor 1: 004CE530, tact_dar.cpp:32-37
// TRIBE_Action_Discovery_Artifact(int file_id, RGE_Action_Object*)
// FLAGS: /GX
// Attempt log:
// 1: Existing draft with /GX but no visible virtual base destructor stayed size-short 96 (no EH frame).
// 2: Declared extern calloc/rge_read and raw vtable base; no improvement.
// 3: Added visible virtual RGE_Action destructor (pattern from matched RGE_Action_Gather); /GX then generated EH/exact size but using novtable/manual vptr and an extra overload produced wrong COMDAT/order, rolled back.
// 4: Rebuilt as a single constructor using full RGE_Action virtual surface from matched RGE_Action_Gather, natural base ctor initializer, direct action_type, calloc, rge_read.
// 5: Including <stdlib.h> instead of a hand extern for calloc restored the /GX EH frame. Using the incoming obj parameter after base ctor made VC5 save an extra EBX; using this->obj for the post-base size lookups lets file_id stay in EDI like original.
// MATCH: python tools/check_function.py --va 004CE530 => Result: MATCH / 0.0000%.

#include <stdlib.h>

void rge_read(int file, void* data, int size);

struct DiscoverySizeInfo { char gap_00[0x3C]; short size; };
struct DiscoveryInfo { char gap_00[0x3C]; DiscoverySizeInfo* size_info; };
struct DiscoveryMaster { char gap_00[0x0C]; DiscoveryInfo* info; };

class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object* param_1);
    virtual int vf08(int param_1, RGE_Action_Object* param_2);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int param_1);
    virtual short vf18(void);
    virtual void vf1C(unsigned char param_1);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void*, float, float, float);
    virtual int vf34(void*, float, float, float);
    virtual unsigned char vf38(void*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual void* vf4C(void);
    virtual void* vf50(void);
    virtual void set_target_obj(void*);
    virtual void vf58(void*);
    virtual void set_state(unsigned char);

    RGE_Action(int file_id, RGE_Action_Object* object, int doSetup);

    short action_type;
    char gap_06[0x2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x33];
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    char* flags; // +0x40

    TRIBE_Action_Discovery_Artifact(int file_id, RGE_Action_Object* obj);
};

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int file_id, RGE_Action_Object* obj)
    : RGE_Action(file_id, obj, 1)
{
    this->action_type = 0x6C;
    this->flags = (char*)calloc(((DiscoveryMaster*)this->obj)->info->size_info->size, 1);
    rge_read(file_id, this->flags, ((DiscoveryMaster*)this->obj)->info->size_info->size);
}

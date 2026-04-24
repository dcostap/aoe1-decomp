// update: 004CE740, tact_dar.cpp:96-121
// State machine: state==1 -> return 1; state==6 -> check_objects+set_state(10); state==10 -> timer check
//
// tried initial class layout; state was at 0x34, should be at 0x0C
// tried switch + virtual set_state; state offset still wrong
// tried overlap mode/state; offsets now correct (0x0C, 0x2C, vtable+0x5C)
// tried removing return 0 from case 10; fall-through correct but block order differs
// tried 3-level indirection; now matches ([eax+0C]->[ecx+3C]->[edx+84])
// tried case order 1,10,6; block layout worse than 1,6,10
// left this in scratch: remaining mismatch is FPU fst/fcom ordering (VC5 codegen drift)
//   original does fcom before fstp; VC5 does fst before fld/fcompp
//   all logic/offsets/indirections correct; behaviorally equivalent

extern float DAT_00575078;
extern double DAT_00575070;

class RGE_Action_Object;
class RGE_Task;

struct DiscoverySizeInfo {
    char gap_00[0x84];
    float tile_width;
};

struct DiscoveryInfo {
    char gap_00[0x3C];
    DiscoverySizeInfo* size_info;
};

struct DiscoveryMaster {
    char gap_00[0x0C];
    DiscoveryInfo* info;
};

class RGE_Action {
public:
    virtual void vf00(void);
    virtual void vf01(void);
    virtual void vf02(void);
    virtual void vf03(void);
    virtual void vf04(void);
    virtual void vf05(void);
    virtual void vf06(void);
    virtual void vf07(void);
    virtual void vf08(void);
    virtual void vf09(void);
    virtual void vf10(void);
    virtual void vf11(void);
    virtual void vf12(void);
    virtual void vf13(void);
    virtual void vf14(void);
    virtual void vf15(void);
    virtual void vf16(void);
    virtual void vf17(void);
    virtual void vf18(void);
    virtual void vf19(void);
    virtual void vf20(void);
    virtual void vf21(void);
    virtual void vf22(void);
    virtual void set_state(unsigned char v);
    char gap_60[0x04];
    RGE_Action_Object* object;
    unsigned char mode;
    char gap_0D[0x1F];
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    float timer;
    char* flags;

    unsigned char update();
    void check_objects();
};

unsigned char TRIBE_Action_Discovery_Artifact::update() {
    switch (this->mode) {
        case 1:
            return 1;
        case 6:
            check_objects();
            this->set_state(10);
            return 0;
        case 10:
            this->timer -= ((DiscoveryMaster*)this->object)->info->size_info->tile_width;
            if (this->timer <= (float)DAT_00575070) {
                this->set_state(6);
            }
            return 0;
    }
    return 0;
}

// VA: 004CE740 TRIBE_Action_Discovery_Artifact::update
// PDB source: tact_dar.cpp, lines 96-121
// ACCEPTED_DRIFT: remaining 5 bytes positional diff is FPU compare/store order
//   only: `fcom qword [addr]; fstp dword [mem]` (orig) vs
//   `fst dword [mem]; fcomp qword [addr]` (rebuilt). Both sequences are 9 bytes
//   total and produce identical behavior: compare timer with double, store timer
//   to memory, FPU stack ends empty. The order is a VC5 scheduler choice.
//   Everything else (switch dispatch, case bodies, return values) is byte-identical.
//
// Key structure choices:
// - break (not return) for cases 6 and 10, with return 0 after switch
//   → without break, VC5 generates different dispatch (sub 4; je vs jne)
// - DAT_00575070 compared as double (no float cast) → generates fcom/fcomp qword
// - Case order in source: 1, 6, 10 matches PDB line order

extern double DAT_00575070;

class RGE_Action_Object;
class RGE_Action;

class RGE_Action {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void set_state(unsigned char v);
    char gap_04[4];
    RGE_Action_Object* object;
    unsigned char mode;
    char gap_0D[0x1F];
    float timer;
};

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

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
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
        break;
    case 10:
        this->timer -= ((DiscoveryMaster*)this->object)->info->size_info->tile_width;
        if (this->timer <= DAT_00575070) {
            this->set_state(6);
        }
        break;
    }
    return 0;
}

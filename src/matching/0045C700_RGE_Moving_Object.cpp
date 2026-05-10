// VA: 0045C700 RGE_Moving_Object::~RGE_Moving_Object
// move_obj.cpp lines 152-158
// FLAGS: config/flags/0045C700_RGE_Moving_Object.rsp (/GX)
//
// Attempt log:
// - Initial scratch destructor was empty and had the wrong class surface.
// - Explicit manual vptr/path/base calls over-constrained the destructor and mismatched.
// - SpruceGlow MATCH: model the real members/base and let VC5 synthesize the destructor chain under /GX. Source only
//   deletes `userDefinedWaypoints` and clears it; compiler emits vptr restore, EH state transitions, member Path
//   destructors, and base RGE_Static_Object destructor in the original order.
// Result: MATCH locally with `python tools/check_function.py --va 0045C700`.

void __cdecl operator delete(void* p);

class Path {
public:
    ~Path();
    char gap_00[0x34];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0xA0];
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    Path pathValue;              // +0xA4
    Path exceptionPathValue;     // +0xD8
    char gap_10C[0x168 - 0x10C];
    void* userDefinedWaypoints;  // +0x168

    virtual ~RGE_Moving_Object();
};

RGE_Moving_Object::~RGE_Moving_Object() {
    if (this->userDefinedWaypoints != 0) {
        operator delete(this->userDefinedWaypoints);
        this->userDefinedWaypoints = 0;
    }
}

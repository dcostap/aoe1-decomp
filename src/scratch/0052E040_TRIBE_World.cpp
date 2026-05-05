// 0052E040 TRIBE_World::~TRIBE_World (tworld.cpp:143-149, 112B)
// BLOCKER: VC5-version vtordisp layout + register allocation differences.
//
// 1. VTORDISP GAP (4 bytes): Our VC5 inserts a 4-byte vtordisp between
//    RGE_Game_World base and TRIBE_World's first field (tech), shifting
//    tech from +0x104 (target) to +0x108. Same issue as 0040D020.
//    #pragma vtordisp(off) not supported by VC5.
//
// 2. NO PUSH EDI/POP EDI: Original uses edi register for tech pointer
//    (push edi at prologue, pop edi at epilogue). Our VC5 keeps tech in
//    ecx throughout, skipping the push/pop. This changes stack slot offsets
//    and function size by 2 bytes.
//
// 3. QUALIFIED DESTRUCTOR CALL: `tech->TRIBE_Tech::~TRIBE_Tech()` generates
//    a direct call. Original uses `mov ecx, edi; call TRIBE_Tech::~TRIBE_Tech`.
//    Our VC5 calls with ecx already set (from the null check), avoiding edi.
//
// Control flow and memory effects are correct. Both vtordisp and register
// allocation are VC5-version differences unresolvable from C source.

#include <new.h>

class TRIBE_Tech {
public:
    virtual ~TRIBE_Tech();
};

class RGE_Game_World {
public:
    void* vftable;
    char pad[0x100];

    virtual ~RGE_Game_World();
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;       // +0x104 target (+0x108 with vtordisp)

    virtual ~TRIBE_World();
};

extern void __cdecl operator_delete(void* p);

TRIBE_World::~TRIBE_World() {
    if (this->tech != 0) {
        this->tech->TRIBE_Tech::~TRIBE_Tech();
        operator_delete(this->tech);
        this->tech = 0;
    }
}

// 0052E040 TRIBE_World::~TRIBE_World (tworld.cpp:143-149, 112B)
// MATCH: VC5's inherited class surface inserted a vtordisp and made `this->tech`
// compile as +0x108. Keeping the inheritance for EH/vptr/base-dtor lowering but
// accessing the binary-proven field with `*(TRIBE_Tech**)((char*)this + 0x104)`
// restored the original +0x104 load/store while preserving the desired destructor
// frame and edi allocation.

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
    TRIBE_Tech*& techRef = *(TRIBE_Tech**)((char*)this + 0x104);
    TRIBE_Tech* tech = techRef;
    if (tech != 0) {
        tech->TRIBE_Tech::~TRIBE_Tech();
        operator_delete(tech);
        techRef = 0;
    }
}

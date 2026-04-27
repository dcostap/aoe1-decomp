// attempt log:
// first pass: EH-framed new-helper sibling to the matching Gaia ctor
// second pass: fix the TRIBE_Gaia surface to 0x858 so VC5 emits the correct allocation size
// third pass: the allocation size is right, but the ctor argument basin still drifts on the early push order
// paused here: the remaining mismatch is the ctor push/order basin around the vtable-ish Gaia player argument and the GAIA string
// target shape: allocate 0x858, call TRIBE_Gaia::TRIBE_Gaia(this/world, vtable-ish *[this+0x48], 0, GAIA, 0), store result into *([this+0x40]) or 0 on failure

class RGE_Master_Player {
public:
    void* vtable_ptr;
};

class TRIBE_Gaia;

class TRIBE_World {
public:
    char gap_00[0x40];
    TRIBE_Gaia** gaia_ptr;
    char gap_44[0x4];
    RGE_Master_Player* gaia_master_player;
    void setup_gaia(void);
};

class TRIBE_Gaia {
public:
    char pad_0[0x858];
    TRIBE_Gaia(TRIBE_World* world, void* player_vtable, unsigned char param_3, char* param_4, unsigned char param_5);
};

void TRIBE_World::setup_gaia(void) {
    *this->gaia_ptr = new TRIBE_Gaia(this, this->gaia_master_player->vtable_ptr, 0, "GAIA", 0);
}

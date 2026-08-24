// VA: 004C81D0 TRIBE_Building_Object::TRIBE_Building_Object
// PDB source: t_b_obj.cpp:117-124
// Baseline: natural three-argument constructor with the proven production
// queue layout, base constructor, setup gate, and doppleganger registration.

#ifndef T_B_OBJ_CONTEXT_H
class RGE_Game_World;
class RGE_Player;
class TRIBE_Building_Object;

class RGE_Doppleganger_Creator {
public:
    int add_doppleganger_check(TRIBE_Building_Object* object,
                               unsigned long* map_address);
};

class RGE_Player {
public:
    char gap_00[0x40];
    RGE_Doppleganger_Creator* doppleganger_creator;
};

class TRIBE_Combat_Object {
public:
    virtual ~TRIBE_Combat_Object();
    char gap_04[0x08];
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    char gap_40[0x188];

    TRIBE_Combat_Object(int mode, RGE_Game_World* world, int do_setup);
};

extern unsigned long* unified_map_offsets[];

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    void* production_queue;
    short production_queue_size;
    short production_queue_count;
    unsigned char production_queue_enabled;
    unsigned char gap_1D1[3];
    void* production_queue_actions;
    unsigned char production_queue_change_flag;
    unsigned char production_queue_auto_paused;
    short production_queue_need_attr;
    char gap_1DC[0x0C];
    int DoppleInstalled;

    virtual ~TRIBE_Building_Object();
    TRIBE_Building_Object(int mode, RGE_Game_World* world, int do_setup);
    int setup(int mode, RGE_Game_World* world);
};
#endif

TRIBE_Building_Object::TRIBE_Building_Object(int mode, RGE_Game_World* world,
                                             int do_setup)
    : TRIBE_Combat_Object(mode, world, 0)
{
    this->production_queue = 0;
    this->production_queue_size = 0;
    this->production_queue_count = 0;
    this->production_queue_enabled = 1;
    this->production_queue_actions = 0;
    this->production_queue_change_flag = 0;
    this->production_queue_auto_paused = 0;
    this->production_queue_need_attr = -1;
    this->DoppleInstalled = 0;
    // The separated constructor surface needs the derived vptr store at the
    // original body position; VC5 otherwise schedules its implicit store before
    // these member initializations.
    *(void**)this = (void*)0x574778;

    if (do_setup != 0) {
        this->setup(mode, world);
    }

    int row = (int)this->world_y;
    int col = (int)this->world_x;
    this->DoppleInstalled = this->owner->doppleganger_creator->add_doppleganger_check(
        this, unified_map_offsets[row] + col);
}

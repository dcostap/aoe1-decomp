// VA: 004C7F50, TRIBE_Building_Object::TRIBE_Building_Object
// PDB source: t_b_obj.cpp:57-76
//
// Canonical reconstruction: this is the seven-argument load/new constructor.
// The base and production-queue ownership are named rather than represented by
// decompiler cursor arithmetic.  The executable stores the derived vftable
// after the queue initializers. This source uses a member-initializer list and
// leaves vptr lowering to VC5; an explicit store or __declspec(novtable) is
// not an acceptable source model.
//
// Attempt log:
// - Typed the complete Static/Moving/Action/Combat base chain, master task
//   fields, player vptr/creator ownership, tile-table pointer array, and the
//   production-queue members. This reaches the original 311-byte size, frame,
//   saved registers, calls, CFG, and all post-constructor bytes.
// - Adding the proven player vptr is a codegen duplicate; it is retained for
//   canonical layout.
// - Restored the donor-proven virtual int setup, virtual set_task, and
//   TRIBE_Combat_Object destructor declarations; each was codegen-identical.
// - A natural member-initializer list for unique_build_id and the queue fields
//   schedules the compiler-managed derived-vptr store after those fields and
//   reaches an exact 311-byte match. No manual vptr store is used.
//
// FLAGS: /nologo /c /O2 /Oy /GX
// Main-agent audit restored canonical master/player destructor ownership and
// retained natural compiler-managed vptr lowering.

class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Doppleganger_Creator;
class Production_Queue_Record;
class RGE_Action_List;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;                                    // +0x10
    char gap_12[0xCA];
    short task_id;                               // +0xDC
};

class TRIBE_Master_Building_Object : public RGE_Master_Static_Object {
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;                                      // +0x04
    RGE_Master_Static_Object* master_obj;        // +0x08
    RGE_Player* owner;                            // +0x0C
    char gap_10[0x28];
    float world_x;                                // +0x38
    float world_y;                                // +0x3C
    float world_z;                                // +0x40
    char gap_44[0x44];
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_88[0xF8];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char gap_180[0x14];
    virtual void set_task(short task_id);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    char gap_194[0x30];
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    char gap_1C4[0x04];

    virtual ~TRIBE_Combat_Object();
    TRIBE_Combat_Object(TRIBE_Master_Building_Object* master,
                        RGE_Player* player, float x, float y, float z,
                        int do_setup);
};

class RGE_Doppleganger_Creator {
public:
    int add_doppleganger_check(RGE_Static_Object* object,
                               unsigned long* map_address);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x3C];
    RGE_Doppleganger_Creator* doppleganger_creator;
};

extern unsigned long* unified_map_offsets[];

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    Production_Queue_Record* production_queue;  // +0x1C8
    short production_queue_size;                 // +0x1CC
    short production_queue_count;                // +0x1CE
    unsigned char production_queue_enabled;      // +0x1D0
    unsigned char gap_1D1[3];
    RGE_Action_List* production_queue_actions;   // +0x1D4
    unsigned char production_queue_change_flag;  // +0x1D8
    unsigned char production_queue_auto_paused;  // +0x1D9
    short production_queue_need_attr;            // +0x1DA
    float build_pts;                             // +0x1DC
    int unique_build_id;                         // +0x1E0
    unsigned char culture;                       // +0x1E4
    unsigned char built;                         // +0x1E5
    unsigned char gap_1E6[2];
    int DoppleInstalled;                         // +0x1E8
    unsigned long PriorMap1;                    // +0x1EC
    unsigned long PriorMap2;                    // +0x1F0
    unsigned long PriorMap3;                    // +0x1F4
    long PriorTurn1;                             // +0x1F8
    long PriorTurn2;                             // +0x1FC
    long PriorTurn3;                             // +0x200

    virtual ~TRIBE_Building_Object();
    TRIBE_Building_Object(TRIBE_Master_Building_Object* master,
                          RGE_Player* player, float x, float y, float z,
                          int unique_id, int do_setup);
    virtual int setup(TRIBE_Master_Building_Object* master, RGE_Player* player,
                      float x, float y, float z);
};

TRIBE_Building_Object::TRIBE_Building_Object(
    TRIBE_Master_Building_Object* master, RGE_Player* player,
    float x, float y, float z, int unique_id, int do_setup)
    : TRIBE_Combat_Object(master, player, x, y, z, 0),
      production_queue(0),
      production_queue_size(0),
      production_queue_count(0),
      production_queue_enabled(1),
      production_queue_actions(0),
      production_queue_change_flag(0),
      production_queue_auto_paused(0),
      production_queue_need_attr(-1),
      unique_build_id(unique_id),
      DoppleInstalled(0)
{
    if (do_setup != 0) {
        this->setup(master, player, x, y, z);
    }

    RGE_Master_Static_Object* master_object = this->master_obj;
    if (master_object->id == 0x114) {
        this->set_task(master_object->task_id);
    }

    int row = (int)this->world_y;
    int col = (int)this->world_x;
    this->DoppleInstalled = this->owner->doppleganger_creator->add_doppleganger_check(
        this, unified_map_offsets[row] + col);

    this->PriorMap1 = 0;
    this->PriorMap2 = 0;
    this->PriorMap3 = 0;
    this->PriorTurn1 = 0;
    this->PriorTurn2 = 0;
    this->PriorTurn3 = 0;
}

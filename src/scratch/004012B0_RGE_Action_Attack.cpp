// RGE_Action_Attack::RGE_Action_Attack (004012B0)
// PDB source: Act_atak.cpp:145-190
// Size: 237 bytes
// PAUSED - exact matching exhausted this bounded pass; remaining drift is
// confined to initial field-load scheduling.

// Attempt log:
// - Baseline: wrong local base-call spelling and wrong parameter widths; 36 bytes.
// - ABI probe: real RGE_Action constructor call and float/short parameter ABI; 35 bytes.
// - Full same-TU RGE_Action virtual/member ownership was restored; it is codegen-
//   equivalent to the earlier narrow layout but is the canonical source surface.
// - Natural coordinate/range ordering and typed/direct RGE_Sprite chains were tested;
//   the best emitted result stayed 33 bytes (91.55% shape; 37/71 exact blocks).
// - Per-guard object/sprite locals and split p5 source/result locals were also tested;
//   they either duplicated the result or produced a structural regression.
// - A 12-variant permutation lab over the three coordinate and two range stores
//   found no exact codegen; the current x/z/y plus range/min order is the best
//   plausible family (33 bytes, 91.55% shape).
// - A current-context assignment lab found one diagnostic x/range/z/min/y
//   spelling at 32 positional bytes, but it moved the range register/store
//   topology farther from the binary and is not the PDB/decompiler-supported
//   canonical order; it was not promoted into the living source.
// - A six-way shared-local surface lab was codegen-neutral for the current
//   typed guards; sharing the action-object local instead forced an EBP frame.
// - Restored the proven 0x5C attack tail and typed the action-object/master-combat
//   inheritance and offsets.  Correcting the inherited gaps preserved the same
//   33-byte output; retain this canonical ownership rather than the old fake
//   sprite-at-+8 surface.
// - Final bounded result: 33 positional bytes (13.9241%), 40 edit bytes (16.88%);
//   all calls, size, frame, CFG, and the suffix block topology match.
// Remaining lead: reconstruct the original Act_atak.cpp assignment/declaration
// context for the first coordinate/range block; do not retain metric-only aliases.
//
// Key structural insights confirmed:
// - 11 stack params + this(ecx): (RGE_Action_Object*,float,float,float,RGE_Sprite*,
//   RGE_Sprite*,RGE_Sprite*,float,float,short,short) → ret 2Ch
// - Base ctor: __thiscall RGE_Action::ctor(RGE_Action_Object*, int flag)
// - RGE_Action is 0x20 bytes (vtable +04, type +06, pad, obj +08, fields +0C..+1F)
// - RGE_Action_Attack fields from +20: target coordinates, master sprites,
//   range/min-range, frame shorts, and three flags plus tail padding.
// - Sprite overrides: if null, get from action_obj->master_obj run/move/fight/
//   sprite fields at +0xC0/+0xBC, +0xFC, +0x18; range uses +0x114.
// - vtable=0x56E058, type=9, indirect_fire=2
// Main-agent audit retained compiler-owned vptr setup and the natural 0.4f
// fallback assignment.

struct RGE_Sprite;
struct RGE_Action_List;

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    unsigned char gap_04[0x14];
    RGE_Sprite* sprite;              // +18
    unsigned char gap_1C[0x9C];
};

struct RGE_Master_Animated_Object : public RGE_Master_Static_Object {
    float speed;                     // +B8
};

struct RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
    RGE_Sprite* move_sprite;         // +BC
    RGE_Sprite* run_sprite;          // +C0
    unsigned char gap_C4[0x14];
};

struct RGE_Master_Action_Object : public RGE_Master_Moving_Object {
    unsigned char gap_D8[0x24];
};

struct RGE_Master_Combat_Object : public RGE_Master_Action_Object {
    RGE_Sprite* fight_sprite;        // +FC
    unsigned char gap_100[0x14];
    float weapon_range;              // +114
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    long id;                         // +04
    RGE_Master_Static_Object* master_obj; // +08
    unsigned char gap_0C[0x7C];
};

struct RGE_Animated_Object : public RGE_Static_Object {
    float speed;                     // +88
};

struct RGE_Moving_Object : public RGE_Animated_Object {
    unsigned char gap_8C[0xF4];
};

struct RGE_Action_Object : public RGE_Moving_Object {
    unsigned char waiting;            // +180
    unsigned char gap_181[3];
    RGE_Action_List* actions;         // +184
    unsigned char command_flag;       // +188
    unsigned char gap_189[3];
    int last_action_value;            // +18C
    int last_action_state_value;      // +190
};

struct RGE_Task;

struct RGE_Action {
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int, RGE_Action_Object*);
    virtual RGE_Action_List* vf0C(RGE_Action_Object*);
    virtual void vf10(void);
    virtual void vf14(int);
    virtual short vf18(void);
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(RGE_Static_Object*, float, float, float);
    virtual int vf34(RGE_Static_Object*, float, float, float);
    virtual unsigned char vf38(RGE_Static_Object*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void vf58(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;                // +04
    unsigned char g0[2];              // +06
    RGE_Action_Object* action_obj;    // +08
    unsigned char state;              // +0C
    unsigned char g1[3];              // +0D
    RGE_Static_Object* target_obj;    // +10
    RGE_Static_Object* target_obj2;   // +14
    int targetID;                     // +18
    int target2ID;                    // +1C
    float target_x;                   // +20
    float target_y;                   // +24
    float target_z;                   // +28
    float timer;                      // +2C
    RGE_Task* task;                   // +30
    RGE_Action_List* sub_actions;    // +34
    RGE_Sprite* sprite;               // +38
    unsigned char subActionValue;    // +3C
    unsigned char g2[3];              // +3D
    
    RGE_Action(RGE_Action_Object* obj, int flag);
};

struct RGE_Action_Attack : public RGE_Action {
    virtual ~RGE_Action_Attack();
    RGE_Sprite* sprite_p5;
    RGE_Sprite* sprite_p6;
    RGE_Sprite* sprite_p7;
    float range;
    float min_range;
    short missile_frame;
    short fire_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire;
    unsigned char gap_5B;
    
    RGE_Action_Attack(RGE_Action_Object* obj, float p2, float p3, float p4,
                     RGE_Sprite* p5, RGE_Sprite* p6, RGE_Sprite* p7, float p8, float p9,
                     short p10, short p11);
};

RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Object* obj, float p2, float p3, float p4,
                                     RGE_Sprite* p5, RGE_Sprite* p6, RGE_Sprite* p7, float p8, float p9,
                                     short p10, short p11)
    : RGE_Action(obj, 1)
{
    target_x = p2;
    target_z = p4;
    target_y = p3;
    range = p8;
    min_range = p9;
    
    action_type = 9;
    sprite_p5 = p5;
    sprite_p6 = p6;
    sprite_p7 = p7;
    missile_frame = p10;
    fire_frame = p11;
    need_to_attack = 0;
    was_same_owner = 0;
    indirect_fire = 2;

    RGE_Master_Combat_Object* move_source;
    RGE_Sprite* move_sprite;
    
    if (p5 == 0) {
        RGE_Action_Object* object = action_obj;
        move_source = (RGE_Master_Combat_Object*)object->master_obj;
        move_sprite = move_source->run_sprite;
        if (move_sprite == 0) {
            move_sprite = move_source->move_sprite;
        }
        sprite_p5 = move_sprite;
    }
    
    if (p6 == 0) {
        RGE_Action_Object* object = action_obj;
        RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)object->master_obj;
        sprite_p6 = master->fight_sprite;
    }
    
    if (p7 == 0) {
        RGE_Action_Object* object = action_obj;
        RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)object->master_obj;
        sprite_p7 = master->sprite;
    }
    
    if (p8 == 0.0f) {
        RGE_Action_Object* object = action_obj;
        RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)object->master_obj;
        range = master->weapon_range;
        if (range == 0.0f) {
            range = 0.4f;
        }
    }
    
}

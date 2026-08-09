// RGE_Action_Attack::RGE_Action_Attack (004012B0)
// PDB source: Act_atak.cpp:145-190
// Size: 237 bytes
// PAUSED - exact matching exhausted this bounded pass; remaining drift is
// confined to initial field-load scheduling and suffix register coloring.

// Attempt log:
// - Baseline: wrong local base-call spelling and wrong parameter widths; 36 bytes.
// - ABI probe: real RGE_Action constructor call and float/short parameter ABI; 35 bytes.
// - Full same-TU RGE_Action virtual/member ownership was restored; it is codegen-
//   equivalent to the earlier narrow layout but is the canonical source surface.
// - Natural coordinate/range ordering and typed/direct RGE_Sprite chains were tested;
//   the best emitted result stayed 33 bytes (91.55% shape; 37/71 exact blocks).
// - Per-guard object/sprite locals and split p5 source/result locals were also tested;
//   they either duplicated the result or produced a structural regression.
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
// - RGE_Action_Attack fields from +20: field_20, field_24, move_sprite, gap, 
//   sprite_p5..p7, range, min_range, missile_frame, fire_frame, 3 bytes
// - Sprite overrides: if null, get from action_obj->sprite->+0xC0/+0xBC(p5),
//   +0xFC(p6), +0x18(p7)
// - Range override: if p8==0.0, use sprite->+0x114; if that's 0.0, set to 0.4
// - vtable=0x56E058, type=9, indirect_fire=2
// Main-agent audit retained canonical action/sprite ownership and replaced the
// residual float bit-pun with the natural literal assignment.

struct RGE_Sprite;

struct RGE_Action_Object {
    unsigned char g0[0x08];
    RGE_Sprite* sprite;  // +08
};

struct RGE_Sprite {
    unsigned char g0[0x08];
    unsigned char dummy_08[0x10];
    RGE_Sprite* attack_sprite;       // +18
    unsigned char g1[0xA0];
    RGE_Sprite* stand_sprite;        // +BC
    RGE_Sprite* move_sprite2;        // +C0
    unsigned char g2[0x38];
    RGE_Sprite* fight_sprite;        // +FC
    unsigned char g3[0x14];
    float attack_range;              // +114
};

struct RGE_Action_List;
struct RGE_Static_Object;
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

    RGE_Sprite* move_source;
    RGE_Sprite* move_sprite;
    
    if (p5 == 0) {
        RGE_Action_Object* object = action_obj;
        move_source = object->sprite;
        move_sprite = move_source->move_sprite2;
        if (move_sprite == 0) {
            move_sprite = move_source->stand_sprite;
        }
        sprite_p5 = move_sprite;
    }
    
    if (p6 == 0) {
        RGE_Action_Object* object = action_obj;
        RGE_Sprite* sprite = object->sprite;
        sprite_p6 = sprite->fight_sprite;
    }
    
    if (p7 == 0) {
        RGE_Action_Object* object = action_obj;
        RGE_Sprite* sprite = object->sprite;
        sprite_p7 = sprite->attack_sprite;
    }
    
    if (p8 == 0.0f) {
        RGE_Action_Object* object = action_obj;
        RGE_Sprite* sprite = object->sprite;
        range = sprite->attack_range;
        if (range == 0.0f) {
            range = 0.4f;
        }
    }
    
}

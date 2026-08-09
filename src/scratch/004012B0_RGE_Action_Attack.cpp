// RGE_Action_Attack::RGE_Action_Attack (004012B0)
// PDB source: Act_atak.cpp:145-190
// Size: 237 bytes
// PAUSED - exact matching exhausted this bounded pass; remaining drift is
// confined to the constructor's initial field-load scheduling.

// Attempt log:
// - Baseline: wrong local base-call spelling and wrong parameter widths; 36 bytes.
// - ABI probe: real RGE_Action constructor call and float/short parameter ABI; 35 bytes.
// - Full proven RGE_Action ownership was tested, but VC5 selected an EBP frame and
//   diverged broadly; restored the compact offset-equivalent local stub.
// - Coordinate grouping/order improved the best result to 33 bytes (91.55% shape;
//   37/71 instructions in exact blocks); later register/typed-sprite probes duplicated it.
// - Final bounded result: 33 positional bytes (13.9241%), 40 edit bytes (16.88%);
//   all calls, size, frame, CFG, and the 37-instruction suffix island match.
// - Main-agent audit restored compiler-owned polymorphic vptr setup and named
//   RGE_Sprite fields; the 33-byte mismatch is unchanged.
// Remaining lead: revisit initial coordinate/range assignment context with the full
// shared RGE_Action class/TU surface; do not repeat duplicate probes.
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

struct RGE_Sprite;

struct RGE_Action_Object {
    unsigned char g0[0x08];
    RGE_Sprite* sprite;  // +08
};

struct RGE_Sprite {
    unsigned char g0[0x08];
    unsigned char dummy_08[0x10];
    void* attack_sprite;             // +18
    unsigned char g1[0xA0];
    void* stand_sprite;              // +BC
    void* move_sprite2;              // +C0
    unsigned char g2[0x38];
    void* fight_sprite;              // +FC
    unsigned char g3[0x14];
    float attack_range;              // +114
};

struct RGE_Action {
    virtual ~RGE_Action();
    short action_type;                // +04
    unsigned char g0[2];
    RGE_Action_Object* action_obj;    // +08
    unsigned char g1[0x14];
    
    RGE_Action(RGE_Action_Object* obj, int flag);
};

struct RGE_Action_Attack : public RGE_Action {
    virtual ~RGE_Action_Attack();
    float target_x;
    float target_y;
    float target_z;
    unsigned char gap_2C[0x14];
    void* sprite_p5;
    void* sprite_p6;
    void* sprite_p7;
    float range;
    float min_range;
    short missile_frame;
    short fire_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire;
    
    RGE_Action_Attack(RGE_Action_Object* obj, float p2, float p3, float p4,
                     void* p5, void* p6, void* p7, float p8, float p9,
                     short p10, short p11);
};

RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Object* obj, float p2, float p3, float p4,
                                     void* p5, void* p6, void* p7, float p8, float p9,
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
    
    if (p5 == 0) {
        RGE_Sprite* s = action_obj->sprite;
        void* ms = s->move_sprite2;
        if (ms == 0) {
            ms = s->stand_sprite;
        }
        sprite_p5 = ms;
    }
    
    if (p6 == 0) {
        RGE_Sprite* s = action_obj->sprite;
        sprite_p6 = s->fight_sprite;
    }
    
    if (p7 == 0) {
        RGE_Sprite* s = action_obj->sprite;
        sprite_p7 = s->attack_sprite;
    }
    
    if (p8 == 0.0f) {
        RGE_Sprite* s = action_obj->sprite;
        range = s->attack_range;
        if (range == 0.0f) {
            *(int*)&range = 0x3ECCCCCD;
        }
    }
    
}

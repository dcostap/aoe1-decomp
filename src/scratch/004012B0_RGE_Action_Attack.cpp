// RGE_Action_Attack::RGE_Action_Attack (004012B0)
// PDB source: Act_atak.cpp:145-190
// Size: 237 bytes
// PARKED - pure VC5 instruction scheduling/register allocation drift

// Attempt log:
// - Probe 1 (RGE_Action_Attack constructor, 1st pass): 237 bytes, 84 byte diff (35.4%)
//   Struct layout issue: RGE_Action padding was 0x16 instead of 0x14, 
//   causing wrong field offsets in derived class.
// - Probe 2 (fixed base padding to 0x14): 237 bytes, 42 byte diff (17.7%)
//   Field offsets now correct. Missing return this (mov eax, esi).
// - Probe 3 (return RGE_Action_Attack* + return this): 237 bytes, 35 byte diff (14.8%)
//   mov eax,esi now present. Remaining drift is pure scheduling/registers.
//
// Remaining: Pure VC5 scheduling drift:
// 1. Parameter loading order differs: original interleaves loads then stores 
//    (eax=p4, edx=p3, then stores to +20/+4C/+50/+24/+28), 
//    rebuilt loads in statement order (field_20, range, min_range, etc.)
// 2. Register allocation in override paths: original uses eax->ecx for 
//    p5-derivation, rebuilt uses eax->ecx->eax; different regs in p6/p7 paths
// 3. FPU section register choice (ecx/edx vs edx/eax for sprite chain)
// 4. No difference in stack frame size, field offsets, control flow structure
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

struct RGE_Action_Object {
    unsigned char g0[0x08];
    void* sprite;  // +08
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
    void* vtable;                     // +00
    short action_type;                // +04
    unsigned char g0[2];
    RGE_Action_Object* action_obj;    // +08
    unsigned char g1[0x14];
    
    void ctor(RGE_Action_Object* obj, int flag);
};

struct RGE_Action_Attack : public RGE_Action {
    int field_20;
    int field_24;
    void* move_sprite;
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
    
    RGE_Action_Attack* constructor(RGE_Action_Object* obj, int p2, int p3, void* p4,
                     void* p5, void* p6, void* p7, float p8, int p9,
                     short p10, short p11);
};

RGE_Action_Attack* RGE_Action_Attack::constructor(RGE_Action_Object* obj, int p2, int p3, void* p4,
                                     void* p5, void* p6, void* p7, float p8, int p9,
                                     short p10, short p11)
{
    this->ctor(obj, 1);
    
    field_20 = p2;
    range = p8;
    min_range = *(float*)&p9;
    
    field_24 = p3;
    move_sprite = p4;
    
    vtable = (void*)0x56E058;
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
        void* s = action_obj->sprite;
        void* ms = *(void**)((char*)s + 0xC0);
        if (ms == 0) {
            ms = *(void**)((char*)s + 0xBC);
        }
        sprite_p5 = ms;
    }
    
    if (p6 == 0) {
        void* s = action_obj->sprite;
        sprite_p6 = *(void**)((char*)s + 0xFC);
    }
    
    if (p7 == 0) {
        void* s = action_obj->sprite;
        sprite_p7 = *(void**)((char*)s + 0x18);
    }
    
    if (p8 == 0.0f) {
        void* s = action_obj->sprite;
        range = *(float*)((char*)s + 0x114);
        if (range == 0.0f) {
            *(int*)&range = 0x3ECCCCCD;
        }
    }
    
    return this;
}

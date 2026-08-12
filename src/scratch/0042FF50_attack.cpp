// 0042FF50 RGE_Combat_Object::attack(RGE_Static_Object*, RGE_Combat_Object*)
// Source: com_obj.cpp lines 269-315
// attempt log:
// attempt 1: natural source from packet/decompiler; initial compile was 400B vs 407B so too small to extract.
// attempt 2: added Static_Object notify vtable surface at +0x148; fixed compile error for target notification.
// attempt 3: result local did not change codegen size or prologue.
// attempt 4: naming hp local and reversing comparisons made no size/codegen difference.
// attempt 5: volatile hp forced extractable size, but was artificial and produced broad mismatch (93.9% positional).
// attempt 6: fixed RGE_Player::objects offset from +0x20 to +0x24; corrects missile factory table load.
// attempt 7: introduced attacked local to try to keep target distinct from this/master; still 400B in natural form.
// attempt 8: changed missile-id branch to positive if (missile_id >= 0) with fallback in trailing else; matches original block order better.
// attempt 9: volatile-size diagnostic after branch reorder improved only to broad mismatch (87.96% positional); prologue still uses EBX/EBP, unlike original push-ecx/ESI/EDI then late EBX.
// attempt 10: reverted artificial volatile; left natural 400B scratch. Remaining blocker is source/register shape for target/master lifetimes plus x87 missile math interleave.
// session probes: canonicalized the missile factory to player->master_objects[]->make_new_obj, tested direct target/master ownership, block-scoped versus function-scoped locals, radius term order, and binary global constants.
// best emitted candidate: direct member source reaches 392B with all 7 calls aligned and 201-byte edit/resync drift; original still has a distinct x87 radius/trig schedule and shrink-wrapped EBX save.
// later probe: same-TU inherited Static/Animated/Moving/Action/Combat and Master_* surfaces plus the observed master hp notification argument produced 400B and 361 positional diff; retained as the best canonical source.
// later probes: named radius locals reproduced the original x87 block shape but not bytes; a named missile-master entry and an initialized c home were nonproductive or worse and were rolled back.
// paused after bounded matching: no artificial volatility, aliases, raw offsets, or register-forcing scaffolding retained.

class RGE_Static_Object;
class RGE_Combat_Object;
class RGE_Missile_Object;
class RGE_Player;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void pad04();
    virtual void pad08();
    virtual void pad0C();
    virtual void pad10();
    virtual void pad14();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);

    char pad_004[0x22];
    short hp;             // +0x26
    char pad_028[0x08];
    float radius_x;        // +0x30
    float radius_y;        // +0x34
    float radius_z;        // +0x38
    char pad_03C[0x7C];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x20];
    int computerPlayer();
    RGE_Master_Static_Object** master_objects; // +0x24
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;           // +0xB8
    char pad_BC[0x1C];
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char pad_D8[0x20];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char pad_F8[0x04];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char pad_FC[0x18];
    float weapon_range;    // +0x114
    char pad_118[0x0C];
    short missile_id;      // +0x124
    char pad_126[0x06];
    float weapon_offset_x; // +0x12C
    float weapon_offset_y; // +0x130
    float weapon_offset_z; // +0x134
};

#define SPAD(n) virtual void spad##n();
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    SPAD(001) SPAD(002) SPAD(003) SPAD(004) SPAD(005) SPAD(006) SPAD(007)
    SPAD(008) SPAD(009) SPAD(010) SPAD(011) SPAD(012) SPAD(013) SPAD(014) SPAD(015)
    SPAD(016) SPAD(017) SPAD(018) SPAD(019) SPAD(020) SPAD(021) SPAD(022) SPAD(023)
    SPAD(024) SPAD(025) SPAD(026) SPAD(027) SPAD(028) SPAD(029) SPAD(030) SPAD(031)
    SPAD(032) SPAD(033) SPAD(034) SPAD(035) SPAD(036) SPAD(037) SPAD(038) SPAD(039)
    SPAD(040) SPAD(041) SPAD(042) SPAD(043) SPAD(044) SPAD(045) SPAD(046) SPAD(047)
    SPAD(048) SPAD(049) SPAD(050) SPAD(051) SPAD(052) SPAD(053) SPAD(054) SPAD(055)
    SPAD(056) SPAD(057) SPAD(058) SPAD(059) SPAD(060) SPAD(061) SPAD(062) SPAD(063)
    SPAD(064) SPAD(065) SPAD(066) SPAD(067) SPAD(068) SPAD(069) SPAD(070) SPAD(071)
    SPAD(072) SPAD(073) SPAD(074) SPAD(075) SPAD(076) SPAD(077) SPAD(078) SPAD(079)
    SPAD(080) SPAD(081)
    virtual void notify(int id1, int id2, int a, int b, int c, int d);

    int id;
    RGE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
    char pad_10[0x20];
    float hp;                       // +0x30
    char pad_34[4];
    float world_x;                  // +0x38
    float world_y;                  // +0x3C
    float world_z;                  // +0x40
    char pad_44[0x44];
};
#undef SPAD

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;                    // +0x88
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char pad_08C[0x10];
    float angle;                    // +0x9C
    char pad_0A0[0xE0];
};

#define APAD(n) virtual void apad##n();
class RGE_Action_Object : public RGE_Moving_Object {
public:
    APAD(083) APAD(084) APAD(085) APAD(086) APAD(087) APAD(088) APAD(089) APAD(090)
    APAD(091) APAD(092) APAD(093) APAD(094) APAD(095) APAD(096) APAD(097) APAD(098)
    APAD(099) APAD(100) APAD(101) APAD(102) APAD(103) APAD(104) APAD(105) APAD(106)
    APAD(107) APAD(108) APAD(109) APAD(110) APAD(111) APAD(112) APAD(113) APAD(114)
    APAD(115) APAD(116) APAD(117) APAD(118) APAD(119) APAD(120) APAD(121) APAD(122)
    APAD(123) APAD(124) APAD(125) APAD(126) APAD(127) APAD(128) APAD(129) APAD(130)
    APAD(131) APAD(132) APAD(133) APAD(134) APAD(135) APAD(136) APAD(137)
    char pad_180[0x14];
};
#undef APAD

class RGE_Missile_Object {
public:
    void init_missile(RGE_Combat_Object* source, RGE_Static_Object* target, float range);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    char pad_194[0x30];
    virtual unsigned char attack(RGE_Static_Object* target, float x, RGE_Combat_Object* other, float y, float z); // +0x228
    unsigned char attack(RGE_Static_Object* target, RGE_Combat_Object* other);
};

#include <math.h>
#pragma intrinsic(cos)
#pragma intrinsic(sin)
#pragma intrinsic(sqrt)

extern "C" long __cdecl _ftol();
extern float DAT_0056f49c;
extern float DAT_0056f4ac;

unsigned char RGE_Combat_Object::attack(RGE_Static_Object* target, RGE_Combat_Object* other)
{
    if (target == 0) {
        return 0;
    }

    short missile_id = this->master_obj->missile_id;
    if (missile_id >= 0) {
        float a1 = this->angle;
        float a2 = this->angle;
        float c = (float)cos(a1);
        RGE_Player* owner = this->owner;
        float s = (float)sin(a2);
        float range = (float)sqrt(this->master_obj->radius_y * this->master_obj->radius_y +
            this->master_obj->radius_x * this->master_obj->radius_x) +
            this->master_obj->weapon_range - DAT_0056f4ac;

        RGE_Missile_Object* missile = (RGE_Missile_Object*)owner->master_objects[missile_id]->make_new_obj(owner,
            this->world_x + c * this->master_obj->weapon_offset_y - s * this->master_obj->weapon_offset_x,
            this->world_y + s * this->master_obj->weapon_offset_y + c * this->master_obj->weapon_offset_x,
            this->world_z + this->master_obj->weapon_offset_z);
        missile->init_missile(this, target, range);
        this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
        if (this->master_obj->weapon_range > DAT_0056f49c) {
            if (1 == target->owner->computerPlayer()) {
                int hp = (int)target->hp;
                target->notify(this->id, target->id, 0x20F, this->id, hp, target->master_obj->hp);
                return 1;
            }
        }
    } else {
        this->attack(target, this->world_x, other, this->world_y, this->world_z);
    }
    return 1;
}

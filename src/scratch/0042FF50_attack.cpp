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
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x20];
    int computerPlayer();
    RGE_Master_Static_Object** master_objects; // +0x24
};

class RGE_Master_Combat_Object {
public:
    char pad_000[0x30];
    float radius_x;        // +0x30
    float radius_y;        // +0x34
    char pad_038[0xDC];
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
    SPAD(000) SPAD(001) SPAD(002) SPAD(003) SPAD(004) SPAD(005) SPAD(006) SPAD(007)
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
    virtual void notify(int id1, int id2, int a, int b, int c);

    int id;
    void* master_obj;
    RGE_Player* owner;
    char pad_10[0x20];
    float hp;
    char pad_34[0x54];
};
#undef SPAD

class RGE_Missile_Object {
public:
    void init_missile(RGE_Combat_Object* source, RGE_Static_Object* target, float range);
};

#define VPAD(n) virtual void pad##n();
class RGE_Combat_Object {
public:
    VPAD(000) VPAD(001) VPAD(002) VPAD(003) VPAD(004) VPAD(005) VPAD(006) VPAD(007)
    VPAD(008) VPAD(009) VPAD(010) VPAD(011) VPAD(012) VPAD(013) VPAD(014) VPAD(015)
    VPAD(016) VPAD(017) VPAD(018) VPAD(019) VPAD(020) VPAD(021) VPAD(022) VPAD(023)
    VPAD(024) VPAD(025) VPAD(026) VPAD(027) VPAD(028) VPAD(029) VPAD(030) VPAD(031)
    VPAD(032) VPAD(033) VPAD(034) VPAD(035) VPAD(036) VPAD(037) VPAD(038) VPAD(039)
    VPAD(040) VPAD(041) VPAD(042) VPAD(043) VPAD(044) VPAD(045) VPAD(046) VPAD(047)
    VPAD(048) VPAD(049) VPAD(050) VPAD(051) VPAD(052) VPAD(053) VPAD(054) VPAD(055)
    VPAD(056) VPAD(057) VPAD(058) VPAD(059) VPAD(060) VPAD(061) VPAD(062) VPAD(063)
    VPAD(064) VPAD(065) VPAD(066) VPAD(067) VPAD(068) VPAD(069) VPAD(070) VPAD(071)
    VPAD(072) VPAD(073) VPAD(074) VPAD(075) VPAD(076) VPAD(077) VPAD(078) VPAD(079)
    VPAD(080) VPAD(081)
    virtual void notify(int id1, int id2, int a, int b, int c, int d); // +0x148
    VPAD(083) VPAD(084) VPAD(085) VPAD(086) VPAD(087) VPAD(088) VPAD(089) VPAD(090)
    VPAD(091) VPAD(092) VPAD(093) VPAD(094) VPAD(095) VPAD(096) VPAD(097) VPAD(098)
    VPAD(099) VPAD(100) VPAD(101) VPAD(102) VPAD(103) VPAD(104) VPAD(105) VPAD(106)
    VPAD(107) VPAD(108) VPAD(109) VPAD(110) VPAD(111) VPAD(112) VPAD(113) VPAD(114)
    VPAD(115) VPAD(116) VPAD(117) VPAD(118) VPAD(119) VPAD(120) VPAD(121) VPAD(122)
    VPAD(123) VPAD(124) VPAD(125) VPAD(126) VPAD(127) VPAD(128) VPAD(129) VPAD(130)
    VPAD(131) VPAD(132) VPAD(133) VPAD(134) VPAD(135) VPAD(136) VPAD(137)
    virtual unsigned char attack(RGE_Static_Object* target, float x, RGE_Combat_Object* other, float y, float z); // +0x228

    int id;                         // +0x04
    RGE_Master_Combat_Object* master_obj; // +0x08
    RGE_Player* owner;              // +0x0C
    char pad_010[0x28];
    float world_x;                  // +0x38
    float world_y;                  // +0x3C
    float world_z;                  // +0x40
    char pad_044[0x58];
    float angle;                    // +0x9C

    unsigned char attack(RGE_Static_Object* target, RGE_Combat_Object* other);
};
#undef VPAD

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
                target->notify(this->id, target->id, 0x20F, this->id, hp);
                return 1;
            }
        }
    } else {
        this->attack(target, this->world_x, other, this->world_y, this->world_z);
    }
    return 1;
}

// VA: 004300F0 RGE_Combat_Object::attack
// Attempt log:
// - Initial natural missile-spawn source from packet asm/decompiler compiled but used too-small FPU body until math intrinsics were visible.
// - Added if-positive body with direct returns; got correct sub esp,8 prologue and 305-byte function size, but FPU scheduling still broad drift (~45% edit diff).
// - Tried explicit rx/ry locals before trig; size matched but compiler used MOV stores and different x87 stack order versus original fld/mov/fld-st3 pattern.
// - Canonicalized the missile factory to RGE_Player::master_objects (+0x24) and
//   RGE_Master_Static_Object::make_new_obj; this is codegen-neutral but matches
//   the ground-truth owner/table surface.
// - Modeled the proven Master_Static->Animated->Moving->Action->Combat and
//   Static->Animated->Moving->Action->Combat base sizes with named inherited
//   fields; emitted code remained in the same basin.
// - Inline range and radius-local variants were structural regressions. The
//   retained range declaration is before trig because PDB line 339 begins at
//   radius_y; it gives 303 emitted bytes, 260 strict differing bytes, 75.93%
//   shape, and all 3 ordered calls aligned.
// - A no-destructor slot-pad diagnostic was codegen-neutral under the proven
//   inheritance surface and was rolled back. The remaining mismatch is the
//   radius/trig x87 schedule: original starts `fld radius_y`, spills only
//   radius_x, then uses `fld st3`; no inline asm or fake volatility retained.
// - Corrected the factory ABI to return RGE_Static_Object* and modeled the
//   proven RGE_Master_Combat_Object size as 0x148. Two radius temporaries are
//   assigned before trig, with the ordered sqrt/range expression deferred to
//   the init_missile argument. This emitted 285 bytes (283 strict diff),
//   structurally worse than the inherited 303-byte candidate; all calls stay
//   aligned and the ABI/layout corrections are retained as canonical source.
// - Separate declaration/assignment for both radius temporaries was a
//   codegen duplicate. Current source keeps the natural initialized order.

class RGE_Combat_Object;
class RGE_Missile_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Object_List;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void pad04();
    virtual void pad08();
    virtual void pad0C();
    virtual void pad10();
    virtual void pad14();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);

    char pad_004[0x2C];
    float radius_x;        // +0x30
    float radius_y;        // +0x34
    float radius_z;        // +0x38
    char pad_03C[0x7C];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x20];
    RGE_Master_Static_Object** master_objects;
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
    char pad_138[0x10];
};

class RGE_Missile_Object {
public:
    void init_missile(RGE_Combat_Object* target, float x, float y, float z, float range);
};

#define VPAD(n) virtual void pad##n();
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD(001) VPAD(002) VPAD(003) VPAD(004) VPAD(005) VPAD(006) VPAD(007)
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
    virtual void notify(int id1, int id2, int a, int b, int c, int d);

    int id;                         // +0x04
    RGE_Master_Combat_Object* master_obj; // +0x08
    RGE_Player* owner;              // +0x0C
    char pad_010[0x14];
    RGE_Object_List* objects;       // +0x24
    char pad_028[0x10];
    float world_x;                  // +0x38
    float world_y;                  // +0x3C
    float world_z;                  // +0x40
    char pad_044[0x44];
};

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

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char pad_180[0x14];
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    char pad_194[0x30];

    virtual unsigned char attack(float x, float y, float z, RGE_Combat_Object* target);
};
#undef VPAD

#include <math.h>
#pragma intrinsic(cos)
#pragma intrinsic(sin)
#pragma intrinsic(sqrt)

unsigned char RGE_Combat_Object::attack(float x, float y, float z, RGE_Combat_Object* target)
{
    RGE_Master_Combat_Object* master = this->master_obj;
    short missile_id = master->missile_id;
    if (missile_id >= 0) {
        float radius_y = master->radius_y;
        float radius_x = master->radius_x;
        float angle1 = this->angle;
        float angle2 = this->angle;
        float c = (float)cos(angle1);
        RGE_Player* owner = this->owner;
        RGE_Master_Static_Object* entry = owner->master_objects[missile_id];
        float s = (float)sin(angle2);

        RGE_Missile_Object* missile = (RGE_Missile_Object*)entry->make_new_obj(owner,
            this->world_x + c * master->weapon_offset_y - s * master->weapon_offset_x,
            this->world_y + s * master->weapon_offset_y + c * master->weapon_offset_x,
            this->world_z + master->weapon_offset_z);

        missile->init_missile(target, x, y, z,
            (float)sqrt(radius_y * radius_y + radius_x * radius_x) +
                master->weapon_range + 6.0f);
        this->notify(this->id, this->id, 0x200, 0x258, -1, 0);
        return 1;
    }
    return 0;
}

// VA: 004300F0 RGE_Combat_Object::attack
// Attempt log:
// - Initial natural missile-spawn source from packet asm/decompiler compiled but used too-small FPU body until math intrinsics were visible.
// - Added if-positive body with direct returns; got correct sub esp,8 prologue and 305-byte function size, but FPU scheduling still broad drift (~45% edit diff).
// - Tried explicit rx/ry locals before trig; size matched but compiler used MOV stores and different x87 stack order versus original fld/mov/fld-st3 pattern.
// - Changed owner/object-list surface: this->owner (+0x0C) has missile table at +0x24 and is also create_object first arg; fixed call receiver/arg register shape around the virtual call.
// - Current best: collapsed len/range into one natural range local after the angle/owner setup; exact size 305, all 3 call sites aligned, 176 strict-diff bytes.
// - Tried moving that range declaration before angle locals; size stayed exact but diff worsened to 178. A register-qualified radius_y local worsened to 261, and direct angle-member calls/range-first source caused a structural 237-byte rebuild. Restored the 176-byte candidate.
// - Remaining mismatch is the radius/trig x87 schedule: original starts `fld radius_y`, spills only radius_x, then uses `fld st3`; rebuilt still materializes radius fields differently. No inline asm or fake volatility retained.
// - Main-agent audit restored canonical destructor ownership for the player,
//   master, object-list entry, and combat object; emitted behavior is unchanged.

class RGE_Combat_Object;
class RGE_Missile_Object;

class RGE_Object_List_Entry {
public:
    virtual ~RGE_Object_List_Entry();
    virtual void pad04();
    virtual void pad08();
    virtual void pad0C();
    virtual void pad10();
    virtual void pad14();
    virtual RGE_Missile_Object* create_object(void* owner, float x, float y, float z);
};

class RGE_Object_List {
public:
    RGE_Object_List_Entry** entries;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x20];
    RGE_Object_List_Entry** objects;
};

class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    char pad_004[0x2C];
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

class RGE_Missile_Object {
public:
    void init_missile(RGE_Combat_Object* target, float x, float y, float z, float range);
};

#define VPAD(n) virtual void pad##n();
class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
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
    char pad_044[0x58];
    float angle;                    // +0x9C

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
        float angle1 = this->angle;
        float angle2 = this->angle;
        float c = (float)cos(angle1);
        RGE_Player* owner = this->owner;
        RGE_Object_List_Entry* entry = owner->objects[missile_id];
        float s = (float)sin(angle2);
        float range = (float)sqrt(master->radius_y * master->radius_y + master->radius_x * master->radius_x) +
            master->weapon_range + 6.0f;

        RGE_Missile_Object* missile = entry->create_object(owner,
            this->world_x + c * master->weapon_offset_y - s * master->weapon_offset_x,
            this->world_y + s * master->weapon_offset_y + c * master->weapon_offset_x,
            this->world_z + master->weapon_offset_z);

        missile->init_missile(target, x, y, z, range);
        this->notify(this->id, this->id, 0x200, 0x258, -1, 0);
        return 1;
    }
    return 0;
}

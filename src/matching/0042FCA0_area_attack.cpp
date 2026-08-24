// VA: 0042FCA0 RGE_Combat_Object::area_attack
// Attempt log:
// try 1: behavioral reconstruction from packet/Ghidra: scan map cells around attack point, filter combat targets, distance vs footprint/radius, random chance, apply damage.
// try 2: split x/y bound conversions into named statements to mirror four __ftol calls; no size/register recovery.
// try 3: /Od probe exact-size but completely wrong debug-basin codegen; removed.
// try 4: /GX probe no useful change; removed.
// try 5: modeled map rows/cells using row pointer + 0x10 + x*0x18 cell offset; high-level struct still not same addressing family.
// try 6: modeled skip-self, min blast level, skip-object tests in original order.
// try 7: modeled footprint-distance clamp separately for x/y before radius-square test.
// try 8: modeled random chance via debug_rand path/line and integer division; compiler uses simpler division than original magic multiply sequence.
// try 9: modeled virtual calc_attack_modifier and target damage call with observed parameter order.
// try 10: leaving in scratch: clean source is 672B vs 683B and mismatch is broad loop/FPU/register/addressing drift, not accepted_drift-safe.
// try 11: reversed the radius predicate to r2 > dx * dx + dy * dy; this reduced the mismatch to 5 bytes with full block and call alignment.
// session baseline: frame/CFG and all seven call sites were close, but the local class surface put calc_attack_modifier at vslot +0x70 and damage at +0x6C.
// session probes: restored Action_Object vtable ownership, player->world->map, master area/weapon fields, 0x18-byte map cells, typed footprint radii, and the fourth/fifth pointer affiliation proved by stack homes.
// best emitted candidate: 683B/frame 0x24, all seven calls aligned, 96.38% instruction-shape similarity and 207 positional diff bytes after restoring the real source-path literal; remaining drift is localized to the radius-square FPU expression and initial register order.
// paused after bounded matching: readable typed source retained; no frame padding, fake volatility, raw cursor arithmetic, or register-forcing aliases.
// session probe: initialized player before master; emitted code stayed identical, so restored the prior order.
// session probe: initialized owner/map before master/radius; exact 683B match and expected entry register colors.

extern "C" long __cdecl _ftol();
#ifndef RGE_COM_OBJ_SHARED_CONTEXT
extern "C" int __cdecl debug_rand(char*, int);
#endif
extern double DAT_0056f4a0;
extern float DAT_0056f4a8;

struct Link { void* object; Link* next; };
#ifndef RGE_COM_OBJ_SHARED_CONTEXT
struct MapCell { char gap[0x10]; Link* objects; char gap_end[4]; };
struct MapRow { MapCell cell[1]; };
struct RGE_Map { char gap0[8]; short width; char gapA[2]; short height; char gapE[0x8D7E]; MapRow** rows; };

class RGE_Armor_Weapon_Info;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x2C];
    float radius_x;
    float radius_y;
    char gap_38[0x53];
    unsigned char area_effect_object_level;
    char gap_8C[0x2C];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x50];
    short weapon_num;
    char gap_10A[2];
    RGE_Armor_Weapon_Info* weapon;
    char gap_110[4];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    char gap_11D[3];
    char gap_120[4];
    char gap_124[2];
    short base_hit_chance;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

#define VPAD(n) virtual void v##n();
class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object(); VPAD(004) VPAD(008) VPAD(00C) VPAD(010) VPAD(014) VPAD(018) VPAD(01C)
    VPAD(020) VPAD(024) VPAD(028) VPAD(02C) VPAD(030) VPAD(034) VPAD(038) VPAD(03C)
    VPAD(040) VPAD(044) VPAD(048) VPAD(04C) VPAD(050) VPAD(054) VPAD(058) VPAD(05C)
    VPAD(060) VPAD(064) VPAD(068) VPAD(06C)
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    VPAD(074) VPAD(078) VPAD(07C) VPAD(080) VPAD(084) VPAD(088) VPAD(08C) VPAD(090)
    VPAD(094) VPAD(098) VPAD(09C) VPAD(0A0) VPAD(0A4) VPAD(0A8) VPAD(0AC) VPAD(0B0)
    VPAD(0B4) VPAD(0B8) VPAD(0BC) VPAD(0C0) VPAD(0C4) VPAD(0C8) VPAD(0CC) VPAD(0D0)
    VPAD(0D4) VPAD(0D8) VPAD(0DC) VPAD(0E0) VPAD(0E4) VPAD(0E8) VPAD(0EC)

    int id;
    RGE_Master_Combat_Object* master;
    RGE_Player* owner;
    char gap_010[0x28];
    float x;
    float y;
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual float calc_attack_modifier(RGE_Static_Object*);

    unsigned char area_attack(float x, float y, float z, RGE_Combat_Object* attacker, RGE_Static_Object* ignored);
};
#endif
#undef VPAD

unsigned char RGE_Combat_Object::area_attack(float x, float y, float z, RGE_Combat_Object* attacker, RGE_Static_Object* ignored)
{
    float attack_modifier;
    RGE_Player* player = this->owner;
    RGE_Map* map = player->world->map;
    RGE_Master_Combat_Object* master = this->master;
    float radius = master->area_effect_range;
    short maxx = map->width - 1;
    short maxy = map->height - 1;
    float r2 = radius * radius;
    if (!(radius > DAT_0056f4a0)) return 0;

    short x0;
    x0 = (short)((long)(x - radius));
    x0 = x0 - 2;
    short x1;
    x1 = (short)((long)(x + radius));
    x1 = x1 + 2;
    short y0;
    y0 = (short)((long)(y - radius));
    y0 = y0 - 2;
    short y1;
    y1 = (short)((long)(y + radius));
    y1 = y1 + 2;
    if (x0 < 0) x0 = 0;
    if (x1 > maxx + 1) x1 = maxx + 1;
    if (y0 < 0) y0 = 0;
    if (y1 > maxy + 1) y1 = maxy + 1;

    for (short yy = y0; yy < y1; yy++) {
        for (short xx = x0; xx < x1; xx++) {
            Link* link = map->rows[yy]->cell[xx].objects;
            while (link != 0) {
                RGE_Combat_Object* obj = (RGE_Combat_Object*)link->object;
                if (obj != this &&
                    obj->master->area_effect_object_level >= this->master->area_effect_level &&
                    obj != (RGE_Combat_Object*)ignored) {
                    float dx = obj->x - x;
                    float dy = obj->y - y;
                    if (dx < DAT_0056f4a8) dx = -dx;
                    if (dy < DAT_0056f4a8) dy = -dy;
                    float radius_x = obj->master->radius_x;
                    float radius_y = obj->master->radius_y;
                    if (dx > radius_x) dx -= radius_x;
                    else dx = DAT_0056f4a8;
                    if (dy > radius_y) dy -= radius_y;
                    else dy = DAT_0056f4a8;
                    if (r2 > dx * dx + dy * dy) {
                        int rnd = debug_rand(
                            "C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xFA) * 100;
                        int chance = rnd / 0x7fff;
                        if ((short)chance <= this->master->base_hit_chance) {
                            attack_modifier = this->calc_attack_modifier((RGE_Static_Object*)obj);
                            obj->damage((int)this->master->weapon_num, this->master->weapon,
                                        attack_modifier, this->owner, (RGE_Static_Object*)attacker);
                        }
                    }
                }
                link = link->next;
            }
        }
    }
    return 1;
}

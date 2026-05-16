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

extern "C" long __cdecl _ftol();
extern "C" int __cdecl debug_rand(char*, int);

struct Link { void* object; Link* next; };
struct MapRow { char gap[0x10]; Link* cell[1]; };
struct RGE_Map { char gap0[8]; short width; char gapA[2]; short height; char gapE[0x8D7E]; MapRow** rows; };

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void take_damage(int,int,float,void*,float);
    char gap_04[4];
    void* master;
    char gap_0C[0x2C];
    float x;
    float y;
};

class RGE_Combat_Object : public RGE_Static_Object {
public:
    virtual float calc_attack_modifier(RGE_Combat_Object*);
    char gap_40[0x48];
    unsigned char blastLevel;
    char gap_8C[0x7C];
    short attack;
    int damageType;
    char gap_110[8];
    float blastRadius;
    unsigned char minBlastLevel;
    char gap_11D[9];
    short blastChance;

    unsigned char area_attack(float x, float y, float z, RGE_Combat_Object* skip, RGE_Static_Object* source);
};

unsigned char RGE_Combat_Object::area_attack(float x, float y, float z, RGE_Combat_Object* skip, RGE_Static_Object* source)
{
    float radius = this->blastRadius;
    RGE_Map* map = *(RGE_Map**)((char*)*(void**)((char*)this->master + 0x3C) + 0x28);
    short maxx = map->width - 1;
    short maxy = map->height - 1;
    float r2 = radius * radius;
    if (!(radius > 0.0f)) return 0;

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
            Link* link = map->rows[yy]->cell[xx];
            while (link != 0) {
                RGE_Combat_Object* obj = (RGE_Combat_Object*)link->object;
                if (obj != this && obj->blastLevel >= this->minBlastLevel && obj != skip) {
                    float dx = obj->x - x;
                    float dy = obj->y - y;
                    if (dx < 0.0f) dx = -dx;
                    if (dy < 0.0f) dy = -dy;
                    float sx = *(float*)((char*)obj->master + 0x30);
                    int syi = *(int*)((char*)obj->master + 0x34);
                    if (dx <= sx) dx = 0.0f; else dx -= sx;
                    float sy = *(float*)&syi;
                    if (dy <= sy) dy = 0.0f; else dy -= sy;
                    if (dy * dy + dx * dx < r2) {
                        int rnd = debug_rand((char*)0x583580, 0xFA) * 100;
                        int chance = rnd / 0x7fff;
                        if ((short)chance <= this->blastChance) {
                            float mod = this->calc_attack_modifier(obj);
                            obj->take_damage((int)this->attack, this->damageType, mod, this, z);
                        }
                    }
                }
                link = link->next;
            }
        }
    }
    return 1;
}

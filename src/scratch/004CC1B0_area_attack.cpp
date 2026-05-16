// VA: 004CC1B0 TRIBE_Combat_Object::area_attack
// Attempt log:
// 1: direct reconstruction from packet/decompiler with local offset stubs.
// 2: removed explicit vtbl data member after dump showed virtual class already has hidden vptr and had shifted type/owner offsets by 4.
// 3: tried dummy frame local to force original 0x28 frame; optimized out, rebuilt stays 0x24 frame and 752B.
// left in scratch: honest source compiles 752B vs original 776B. Early offsets now match (type +8, owner +0c, blast_radius +118), but frame size is wrong, register order differs from the first owner/map loads, and later virtual-call surfaces/damage handling are approximate. Broad loop/FPU topology mismatch, not accepted_drift-safe.

extern "C" int __cdecl debug_rand(char*, int);

struct Map { char gap0[8]; short width; char gapa[2]; short height; char gap10[0x8d7c]; void** rows; };
struct Owner { char gap0[0x3c]; Map* map; };
struct Type { char gap0[0x30]; float radius_x; float radius_y; char gap38[0xd0]; short attack_type; char gap10a[2]; int attack_value; char gap110[8]; float blast_radius; unsigned char blast_level; char gap11d[9]; short hit_chance; };
struct Node { void* obj; Node* next; };
class RGE_Combat_Object { public: char gap0[0x30]; float hp; virtual void f0(); };

class TRIBE_Combat_Object {
public:
    char gap04[4];
    Type* type;
    Owner* owner;
    unsigned short id;
    char gap12[0x26];
    float x;
    float y;
    char gap40[0xc8];
    short attack_type;
    int attack_value;
    char gap110[0xc];
    unsigned char blast_level;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual float vf_f0(TRIBE_Combat_Object*);
    unsigned char area_attack(float x, float y, float attack_modifier, RGE_Combat_Object* combat, TRIBE_Combat_Object* ignore);
};

unsigned char TRIBE_Combat_Object::area_attack(float ax, float ay, float attack_modifier, RGE_Combat_Object* combat, TRIBE_Combat_Object* ignore)
{
    int dummy_frame;
    float r = this->type->blast_radius;
    float r2 = r * r;
    Map* map = this->owner->map;
    short maxx = *(short*)((char*)map + 8);
    short maxy = *(short*)((char*)map + 0x0c);
    --maxx;
    --maxy;
    if (!(r > 0.0)) return 0;

    int x1 = (int)(ax - r) - 2;
    int x2 = (int)(ax + r) + 2;
    int y1 = (int)(ay - r) - 2;
    int y2 = (int)(ay + r) + 2;
    if ((short)x1 < 0) x1 = 0;
    if ((short)x2 > (short)(maxx + 1)) x2 = maxx + 1;
    if ((short)y1 < 0) y1 = 0;
    if ((short)y2 > (short)(maxy + 1)) y2 = maxy + 1;

    if ((short)y1 < (short)y2) {
        int rowOff = ((short)y1) * 4;
        int rows = (short)y2 - (short)y1;
        do {
            if ((short)x1 < (short)x2) {
                int cellOff = ((short)x1) * 24;
                int cols = (short)x2 - (short)x1;
                do {
                    Node* n = *(Node**)((char*)*(void**)((char*)map->rows + rowOff) + cellOff + 0x10);
                    while (n) {
                        TRIBE_Combat_Object* obj = (TRIBE_Combat_Object*)n->obj;
                        if (obj != ignore) {
                            unsigned short tid = this->type->gap0[0x10];
                            if (((tid != 0x2e && tid != 0x28 && tid != 0x153 && tid != 0x159) || obj->owner != this->owner) &&
                                obj != this && this->type->blast_level <= obj->type->gap0[0x8b]) {
                                float dx = obj->x - ax;
                                float dy = obj->y - ay;
                                if (dx < 0.0f) dx = -dx;
                                if (dy < 0.0f) dy = -dy;
                                if (dx <= obj->type->radius_x) dx = 0.0f; else dx -= obj->type->radius_x;
                                if (dy <= obj->type->radius_y) dy = 0.0f; else dy -= obj->type->radius_y;
                                if (dy * dy + dx * dx < r2) {
                                    int rr = debug_rand((char*)0x00587578, 0x653) * 100;
                                    if ((short)(rr % 0x7fff) <= this->type->hit_chance) {
                                        float f = this->vf_f0(obj);
                                        (*(void (__stdcall **)(int, int, float, Owner*, float))(*(int*)obj + 0x70))(this->type->attack_type, this->type->attack_value, f, this->owner, attack_modifier);
                                        if (((RGE_Combat_Object*)obj)->hp < 1.0f) {
                                            (*(void (__stdcall **)(int, int, int))(*(int*)obj + 0x84))(0, 0, 1);
                                        }
                                    }
                                }
                            }
                        }
                        n = n->next;
                    }
                    cellOff += 0x18;
                    --cols;
                } while (cols != 0);
            }
            rowOff += 4;
            --rows;
        } while (rows != 0);
    }
    return 1;
}

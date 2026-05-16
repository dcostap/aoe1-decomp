// VA: 004D12B0 TRIBE_Action_Make_Obj::place_obj
// Attempt log:
// initial natural reconstruction from packet: random side placement around source object, try collision/place up to 60 times, expand radius 3 times.
// tried separate helper for random side selection; emitted a separate/shorter text family, inlined the selection back into the function.
// tried /GX probe even though original has no EH; no size/code change, removed flag.
// changed random divisor from 0x4000 to 0x7fff to match original VC5 magic multiply (0x80010003) family; rebuilt grew from 608 to 624 bytes.
// fixed can_place surface to include the missing tenth argument; rebuilt grew to 640 bytes, now only 3 bytes short but check still stops before positional compare.
// tried explicit ==0 predicate and short loop counters for tries/expand; no size change.
// left in scratch: behavior and call surfaces are close, but rebuilt .text remains 640 vs original 643 so no local diff; not accepted_drift-safe.

extern "C" int __cdecl debug_rand(char*, int);
extern float k10;
extern float kRandScale;
extern float kHalf;

class RGE_Static_Object;
class RGE_Static_Object {
public:
#define OPAD(n) virtual void o##n();
    OPAD(0) OPAD(1) OPAD(2) OPAD(3) OPAD(4) OPAD(5)
#undef OPAD
    virtual RGE_Static_Object* create(void*, float, float, void*);
    virtual void o7();
    virtual unsigned char can_place(void*, float, float, int, int, int, int, int, int, int);
    char gap04[0x30-4];
    float x;
    float y;
    float radius_x;
    float radius_y;
    void* owner;
};
class Scenario { public: char gap[0x24]; RGE_Static_Object** objects; };
class Game { public: char gap0[8]; RGE_Static_Object* source; Scenario* scenario; char gap10[0x40-0x10]; void* player; };
class TRIBE_Action_Make_Obj {
public:
    char gap0[8]; Game* game; char gap0c[0x20-0x0c]; float place_x; float place_y; char gap28[0x40-0x28]; short obj_index;
    unsigned char place_obj(RGE_Static_Object** out);
};

unsigned char TRIBE_Action_Make_Obj::place_obj(RGE_Static_Object** out)
{
    short expand = 0;
    Game* g = this->game;
    RGE_Static_Object* src = g->source;
    RGE_Static_Object* proto = g->scenario->objects[this->obj_index];
    float rx = src->radius_x + proto->radius_x - k10;
    float r2x = rx + rx;
    float ry = src->radius_y + proto->radius_y - k10;
    float r2y = ry + ry;
    short tries;
    for (;;) {
        tries = 0;
        do {
            short dir;
            if (tries < 40) {
                dir = (short)((debug_rand((char*)0x00587764, 0xc0) * 2) / 0x7fff);
            } else {
                dir = (short)(((debug_rand((char*)0x00587764, 0xc2) * 2) / 0x7fff) + 2);
            }
            switch (dir) {
            case 0:
                this->place_y = src->y + r2y;
                this->place_x = src->x + ((float)debug_rand((char*)0x00587764, 0xc7) * r2x * kRandScale - rx);
                break;
            case 1:
                this->place_x = src->x - r2x;
                this->place_y = src->y + ((float)debug_rand((char*)0x00587764, 0xcb) * r2y * kRandScale - ry);
                break;
            case 2:
                this->place_x = src->x + r2x;
                this->place_y = src->y + ((float)debug_rand((char*)0x00587764, 0xcf) * r2y * kRandScale - ry);
                break;
            case 3:
                this->place_y = src->y - r2y;
                this->place_x = src->x + ((float)debug_rand((char*)0x00587764, 0xd3) * r2x * kRandScale - rx);
                break;
            }
            if (proto->can_place(g->scenario, this->place_x, this->place_y, 0, 1, 1, 1, 0, 0, 1) == 0) {
                *out = proto->create(g->scenario, this->place_x, this->place_y, g->player);
                return 1;
            }
            ++tries;
        } while (tries < 60);
        rx = proto->radius_x + rx + proto->radius_x * kHalf;
        ry = proto->radius_y + ry + proto->radius_y * kHalf;
        r2x += proto->radius_x;
        r2y += proto->radius_y;
        ++expand;
        if (expand >= 3) break;
    }
    return 0;
}

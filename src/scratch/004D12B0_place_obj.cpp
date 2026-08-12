// VA: 004D12B0 TRIBE_Action_Make_Obj::place_obj
// Attempt log:
// initial natural reconstruction from packet: random side placement around source object, try collision/place up to 60 times, expand radius 3 times.
// tried separate helper for random side selection; emitted a separate/shorter text family, inlined the selection back into the function.
// tried /GX probe even though original has no EH; no size/code change, removed flag.
// changed random divisor from 0x4000 to 0x7fff to match original VC5 magic multiply (0x80010003) family; rebuilt grew from 608 to 624 bytes.
// fixed can_place surface to include the missing tenth argument; rebuilt grew to 640 bytes, now only 3 bytes short but check still stops before positional compare.
// tried explicit ==0 predicate and short loop counters for tries/expand; no size change.
// canonicalized the object graph: +8 is the action object, its +8 master supplies
// radii, and its +0C owner supplies the master-object table. The prior Game/src
// names were decompiler-shaped and modeled the wrong ownership.
// hoisted the canonical prototype pointer: 643 bytes, exact call set, and a 0x1C frame.
// tested typed pointer-to-member and pure-virtual can_place surfaces; codegen did not improve, restored the ordinary virtual method.
// modeled the period virtual destructor surface; it preserved the call set but did not improve the frame.
// reloaded the owner master-object table only for create, matching the original success block: 643 bytes, 0x18 frame, 165 differing bytes.
// left in scratch: exact size, frame, and call set; remaining drift is localized in radius-slot ordering and later block liveness.

#include "../../include/game_globals.h"

extern "C" int __cdecl debug_rand(char*, int);

class RGE_Player;
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual RGE_Static_Object* create(RGE_Player*, float, float, float);
    virtual void v1C();
    virtual unsigned char can_place(RGE_Player*, float, float, int, int, int, int, int, int, int);
    char gap_04[0x2C];
    float radius_x;
    float radius_y;
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
};

class RGE_Action_Object {
public:
    void* vtable;
    int id;
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Player {
public:
    void* vtable;
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
};

class TRIBE_Action_Make_Obj {
public:
    void* vtable;
    char gap_04[4];
    RGE_Action_Object* obj;
    char gap_0C[0x14];
    float place_x;
    float place_y;
    char gap_28[0x18];
    short obj_id;
    unsigned char place_obj(RGE_Static_Object** out);
};

unsigned char TRIBE_Action_Make_Obj::place_obj(RGE_Static_Object** out)
{
    short expand = 0;
    RGE_Master_Static_Object* proto =
        this->obj->owner->master_objects[this->obj_id];
    float rx;
    float ry;
    float r2x;
    float r2y;
    rx = this->obj->master_obj->radius_x + proto->radius_x - DAT_00575190;
    r2x = rx + rx;
    ry = this->obj->master_obj->radius_y + proto->radius_y - DAT_00575190;
    r2y = ry + ry;
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
                this->place_y = this->obj->world_y + r2y;
                this->place_x = this->obj->world_x +
                    ((float)debug_rand((char*)0x00587764, 0xc7) * r2x * DAT_00575198 - rx);
                break;
            case 1:
                this->place_x = this->obj->world_x - r2x;
                this->place_y = this->obj->world_y +
                    ((float)debug_rand((char*)0x00587764, 0xcb) * r2y * DAT_00575198 - ry);
                break;
            case 2:
                this->place_x = this->obj->world_x + r2x;
                this->place_y = this->obj->world_y +
                    ((float)debug_rand((char*)0x00587764, 0xcf) * r2y * DAT_00575198 - ry);
                break;
            case 3:
                this->place_y = this->obj->world_y - r2y;
                this->place_x = this->obj->world_x +
                    ((float)debug_rand((char*)0x00587764, 0xd3) * r2x * DAT_00575198 - rx);
                break;
            }
            if (proto->can_place(
                    this->obj->owner, this->place_x, this->place_y, 0, 1, 1, 1, 0, 0, 1) == 0) {
                *out = this->obj->owner->master_objects[this->obj_id]->create(
                    this->obj->owner, this->place_y, this->place_x, this->obj->world_z);
                return 1;
            }
            ++tries;
        } while (tries < 60);
        rx = proto->radius_x + rx + proto->radius_x * DAT_0057519c;
        ry = proto->radius_y + ry + proto->radius_y * DAT_0057519c;
        r2x += proto->radius_x;
        r2y += proto->radius_y;
        ++expand;
        if (expand >= 3) break;
    }
    return 0;
}

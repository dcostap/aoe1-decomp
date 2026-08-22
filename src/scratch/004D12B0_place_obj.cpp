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
// reordered the local radius declaration pairs to test the first paired stack-home hunk; codegen was unchanged, so restored the prior order.
// tested expansion growth from a direct x87 reading: single radii doubled the
// prototype radius and doubled radii added four times that radius; it added 25
// bytes and was restored while the branch layout remains under test.
// reversed the can_place condition so the retry path is the positive arm and
// creation is its else target; this restored the original failure-before-success CFG.
// reordered doubled-radius declarations before single-radius declarations; VC5 emitted the same code.
// the three floating constants have stable shared identities at 00575190,
// 00575198, and 0057519C. Keep those globals rather than local literals.
// split doubled-radius copies before compound adds; VC5 emitted the same code, so kept the simpler expressions.
// interleaved doubled-radius declarations before each single radius; this moved to a 565-byte mismatch, so restored the natural order.
// swapped create coordinates to match the original push order; diff stayed 156 and the create block became source-plausible.
// restored the x87-proven expansion behavior: single radii add two prototype radii and doubled radii add four times each radius.
// testing the shared fourfold constant enlarged the function to 672 bytes; the
// original global remains the canonical source surface.
// left in scratch: correct expansion and create argument order; remaining drift is local radius-slot coloring, literal pool context, and block liveness.
// - Replaced the raw debug-file address with the period source-file string and
//   named the random scale. Raw addresses were not valid source ownership.
// Revisited from the Ghidra-supported donor spelling:
// `value = value + (radius + radius)` and `double_value = double_value +
// (radius * 4.0f)` reproduce the original 643-byte body and 204 instructions.
// The first natural source was 25 bytes short of the target byte stream. The
// remaining differences were four paired local-home swaps and the success
// epilogue store order.
// A 72-variant source lab and 128 ambient TU declaration samples found no exact
// result. All size/frame/call-set eligible variants stayed in the same 25-byte
// basin. The local donor 004C6DA0 matched 647/647 with typed x87 expressions.
// Fresh pass: a named created-object local and an output-reference alias both
// reproduced the same 25 bytes. Keep this target in scratch. The rebuilt output
// store moves after register pops, so an invalid output pointer faults with a
// different exception context. That prevents an accepted-drift proof.
// BINARY NOTE: ESP-normalized original accesses prove the shipped formulas:
// case 0/3 use rand * r2x - rx, and case 1/2 use rand * r2y - ry.
// The natural source now reproduces 636 of 643 bytes (7 differing bytes).
// A focused five-form epilogue lab kept the same 7-byte store-order mismatch.
// Fresh pass: restored the exact same-TU update donor's complete virtual class
// surface. It is codegen-neutral and replaces the raw vtable field. Minimal
// global declarations, a register output parameter, out[0], and one function-
// wide result also reproduced the same seven-byte epilogue basin.

#include "../../include/game_globals.h"

extern "C" int __cdecl debug_rand(char*, int);

static char s_tact_mob_cpp[] = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp";

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
    virtual ~TRIBE_Action_Make_Obj();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58();
    virtual void set_state(unsigned char);
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
    do {
        tries = 0;
        do {
            short dir;
            if (tries < 40) {
                dir = (short)((debug_rand(s_tact_mob_cpp, 0xc0) * 2) / 0x7fff);
            } else {
                dir = (short)(((debug_rand(s_tact_mob_cpp, 0xc2) * 2) / 0x7fff) + 2);
            }
            switch (dir) {
            case 0:
                this->place_y = this->obj->world_y + ry;
                this->place_x = this->obj->world_x +
                    ((float)debug_rand(s_tact_mob_cpp, 0xc7) * r2x * DAT_00575198 - rx);
                break;
            case 1:
                this->place_x = this->obj->world_x - rx;
                this->place_y = this->obj->world_y +
                    ((float)debug_rand(s_tact_mob_cpp, 0xcb) * r2y * DAT_00575198 - ry);
                break;
            case 2:
                this->place_x = this->obj->world_x + rx;
                this->place_y = this->obj->world_y +
                    ((float)debug_rand(s_tact_mob_cpp, 0xcf) * r2y * DAT_00575198 - ry);
                break;
            case 3:
                this->place_y = this->obj->world_y - ry;
                this->place_x = this->obj->world_x +
                    ((float)debug_rand(s_tact_mob_cpp, 0xd3) * r2x * DAT_00575198 - rx);
                break;
            }
            if (proto->can_place(
                    this->obj->owner, this->place_x, this->place_y, 0, 1, 1, 1, 0, 0, 1)) {
                ++tries;
            } else {
                *out = this->obj->owner->master_objects[this->obj_id]->create(
                    this->obj->owner, this->place_x, this->place_y, this->obj->world_z);
                return 1;
            }
        } while (tries < 60);
        rx = rx + (proto->radius_x + proto->radius_x);
        ry = ry + (proto->radius_y + proto->radius_y);
        r2x = r2x + (proto->radius_x * 4.0f);
        r2y = r2y + (proto->radius_y * 4.0f);
        ++expand;
    } while (expand < 3);
    return 0;
}

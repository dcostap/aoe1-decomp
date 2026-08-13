// 00434400 do_command_move (Command.cpp)
// First natural reconstruction from packet/decompiler.
// Attempts:
// - Natural source reaches same 0x28 frame and opening prologue through the get_obj setup, including count in edi and ids in ebx.
// - Fixed RGE_Static_Object layout so id/master/owner/world_x/world_y align with original (+4/+8/+0c/+38/+3c); this improved edit diff but not overall block shape.
// - Tried forcing target volatile / predeclared target to move stack slots; worsened or did not fix first mismatch, rolled back to natural target local.
// - Remaining mismatch starts at local stack-slot assignment: rebuilt stores unit count/target in different slots and omits the redundant `test edi,edi` before the bounds scan. Later loops are broadly similar behaviorally but not an accepted drift candidate.
// - Corrected the move/setFlag virtual slots, inlined the map clamps and
//   target-radius tests, and added the explicit positive-count guards. This
//   aligns all 26 ordered calls and the CFG; the remaining structural gap is
//   the target/local stack-home basin (10 code bytes, target at [esp+1c]
//   instead of the original [esp+24]).
// - Declared the packet cursor and resolved target before the accumulator
//   locals, matching the exact do_command_work ownership order; VC5 emitted
//   identical code, so the target-home lead remains unconfirmed.
// - Kept the six bounding/total locals inside the n > 1 branch, matching the
//   original line-521 initialization band; this is a natural scope lead for
//   the remaining target and accumulator stack-home mismatch.
// - Tried evaluating the target lookup before count and unit-cursor setup,
//   matching the original initial load order; this moved the first mismatch
//   to the prologue and worsened the diff, so it was restored.
// - Reordered top-level total and bound declarations while keeping binary
//   initialization order, based on the packet's stack-local ordering; VC5
//   emitted the clean 811-byte mismatch unchanged, so the branch-scoped form
//   remains the best source reconstruction.
// - Mirrored the same-TU do_command_order source shape by computing both
//   adjusted coordinates before either map clamp; this is the original FPU
//   interleave at Command.cpp:583-589, not a compiler-steering change.

#include "../../include/game_globals.h"

struct RGE_Obj_Info { int id; };
class UnitAIModule { public: void setCurrentOrder(int); void setCurrentAction(int); void setCurrentTarget(int,int,float,float,float); };
struct Map { int w; int h; int width; int height; };
struct World2 { char pad[0x3c]; void* p; Map* map; };
struct Owner { char pad[0x3c]; World2* world; };
struct Master { char pad[0x14]; short object_group; char pad16[0x1a]; float radius_x; float radius_y; };
class RGE_Static_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void move(RGE_Static_Object* target, float x, float y, int zero); // 9c
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8(); virtual void vDC();
    virtual void vE0(); virtual void vE4(); virtual void vE8(); virtual void vEC();
    virtual void vF0(); virtual void vF4(); virtual void vF8(); virtual void vFC();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10C();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11C();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void setFlag(int); //12c
    int id; Master* master; Owner* owner; char pad10[0x28]; float world_x; float world_y;
    void removeAllFromPathingGroup(); void addToPathingGroup(int); UnitAIModule* unitAI();
};
struct Order {
    unsigned char command;
    unsigned char gap_01[3];
    RGE_Obj_Info target;
    unsigned char unit_num;
    unsigned char gap_09[3];
    float x;
    float y;
    RGE_Obj_Info ids[1];
};
class RGE_Command { public: virtual ~RGE_Command(); char pad4[4]; void* world; RGE_Static_Object* get_obj(RGE_Obj_Info); void do_command_move(Order*); };

void RGE_Command::do_command_move(Order* order) {
    int n = order->unit_num;
    RGE_Obj_Info* ids = order->ids;
    RGE_Static_Object* target = this->get_obj(order->target);
    if (n > 1) {
        float minx = 10000.0f;
        float maxx = 0.0f;
        float miny = 10000.0f;
        float maxy = 0.0f;
        float totalx = 0.0f;
        float totaly = 0.0f;
        if (n > 0) {
            int i = n;
            RGE_Obj_Info* p = ids;
            do {
                RGE_Static_Object* obj = this->get_obj(*p);
                if (obj) {
                    if (obj->world_x < minx) minx = obj->world_x; else if (obj->world_x > maxx) maxx = obj->world_x;
                    if (obj->world_y < miny) miny = obj->world_y; else if (obj->world_y > maxy) maxy = obj->world_y;
                    totalx += obj->world_x;
                    totaly += obj->world_y;
                }
                ++p;
            } while (--i);
        }
        if (maxx - minx > DAT_0056f4d8 || maxy - miny > DAT_0056f4d8) goto simple;
        float avgx = totalx / (float)n;
        float avgy = totaly / (float)n;
        if (n > 0) {
            int idx = 0;
            RGE_Obj_Info* p = ids;
            do {
            RGE_Static_Object* obj = this->get_obj(*p);
            if (obj) {
                obj->removeAllFromPathingGroup(); obj->setFlag(1);
                int j = 0; RGE_Obj_Info* q = ids;
                do { if (j != idx) obj->addToPathingGroup(q->id); ++j; ++q; } while (j < n);
                float nx = (obj->world_x - avgx) + order->x;
                float ny = (obj->world_y - avgy) + order->y;
                if (nx < DAT_0056f4e0) nx = 1.0f;
                else {
                    float width = (float)obj->owner->world->map->width;
                    if (nx >= width) nx = width - DAT_0056f4e8;
                }
                if (ny < DAT_0056f4e0) ny = 1.0f;
                else {
                    float height = (float)obj->owner->world->map->height;
                    if (ny >= height) ny = height - DAT_0056f4e8;
                }
                if (target != 0 &&
                    (target->master->radius_x > DAT_0056f4e0 ||
                     target->master->radius_y > DAT_0056f4e0))
                    obj->move(target, nx, ny, 0);
                else
                    obj->move(0, nx, ny, 0);
                UnitAIModule* ai = obj->unitAI();
                if (ai) {
                    obj->unitAI()->setCurrentOrder(0x2c6); obj->unitAI()->setCurrentAction(0x262);
                    if (target != 0 &&
                        (target->master->radius_x > DAT_0056f4e0 ||
                         target->master->radius_y > DAT_0056f4e0))
                        obj->unitAI()->setCurrentTarget(target->id, target->master->object_group, nx, ny, 0.0f);
                    else obj->unitAI()->setCurrentTarget(-1, -1, nx, ny, 0.0f);
                }
            }
                ++idx; ++p;
            } while (idx < n);
        }
        return;
    }
simple:
    if (n > 0) {
        int idx = 0; RGE_Obj_Info* p = ids;
        do {
            RGE_Static_Object* obj = this->get_obj(*p);
            if (obj) {
                obj->removeAllFromPathingGroup(); obj->setFlag(1);
                int j = 0; RGE_Obj_Info* q = ids;
                do { if (j != idx) obj->addToPathingGroup(q->id); ++j; ++q; } while (j < n);
                obj->move(target, order->x, order->y, 0);
                UnitAIModule* ai = obj->unitAI();
                if (ai) {
                    obj->unitAI()->setCurrentOrder(0x2c6); obj->unitAI()->setCurrentAction(0x262);
                    if (target != 0 &&
                        (target->master->radius_x > DAT_0056f4e0 ||
                         target->master->radius_y > DAT_0056f4e0))
                        obj->unitAI()->setCurrentTarget(target->id, target->master->object_group, order->x, order->y, 0.0f);
                    else obj->unitAI()->setCurrentTarget(-1, -1, order->x, order->y, 0.0f);
                }
            }
            ++idx; ++p;
        } while (idx < n);
    }
}

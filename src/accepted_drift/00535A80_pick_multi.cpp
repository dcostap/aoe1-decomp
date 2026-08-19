// 00535A80 RGE_View::pick_multi (view.cpp:2306-2370)
// Attempt log:
// 1: Natural decompiler-shaped implementation: 86.46% diff; RGE_Static_Object fields were 4 bytes early and parameter/register allocation differed.
// 2: Add object vptr pad fixed object_state/master offsets; diff still broad, first mismatch register allocation for params/count.
// 3: Register loop index/named coordinate locals made no codegen change.
// 4: Mutating x2/y2 into deltas made no codegen change.
// 5: Pointer-before-index swapped init order slightly but still wrong registers.
// 6: Register count did not change allocation.
// 7: Negated dy spelling no change.
// 8: Hoisting loop index before pick call improved to 40% positional / 21.6% edit and restored xor ESI/count EBP.
// 9: Register y1 local did not change EBX (still y2).
// 10: Volatile y2 worsened to 87.68% and first mismatch offset 1; rolled back.
// 11: Used the incoming y1 parameter directly in both rectangle calls, matching the packet's direct y1 home reloads; VC5 emitted the same 495-byte code.
// 12: Spelled the first direct selection block as an early failure break followed by picked_any=1; testing the call before the assignment was a natural source-order lead.
// 13: Replaced raw int pick-record access with a typed RGE_Pick_Obj_Info pointer and named confidence field; VC5 was a codegen duplicate.
// 14: Declared the y delta before the x delta to test y1/EBX liveness coloring; diff worsened by 5 bytes, so restored x delta first.
// 15: Reused y1 as the second-pass count and x2 as the selected-object home; this matched the observed parameter writes but was a codegen duplicate, so restored named locals.
// 16: Carried y2 through a named local across both passes; VC5 was a codegen duplicate.
// 17: Removed register qualifiers from count and loop index; both were codegen duplicates, and the natural unqualified locals remain.
// 18: Used a positive second-pass do-while predicate; rebuilt size grew to 501 bytes and strict diff to 276, so restored count != 0.
// 19: A separate remaining count, initialized after the second cursor setup,
// recovered the original second-pass stack-home and reduced the diff to 40.
// 20: Reusing y1 for the second result, and moving remaining before the score,
// were duplicates or regressions. The separate remaining form remains best.
// 21: Split delta declarations were a duplicate. dx >= dy reduced the diff to
// 39. An explicit sub-50 if/else grew the body to 497 bytes and was restored.
// 22: Restored the canonical TPanel base surface. VC5 emitted a duplicate.
// 23: A 4x4 call/coordinate variant lab and a 32-sample ambient-context lab
// emitted one 495-byte group. No alias, delta, or ambient form moved bytes.
// Bounded session probes: exact-source ABI correction fixed the two helper
// relocations but did not move bytes; parameter-home reuse, declaration-order,
// natural delta, header-context, and focused score-lifetime variants were
// codegen duplicates or regressed size. The retained source below is the
// simplest typed reconstruction: the PDB-proven picked_obj local is function
// scoped, while the score/count remain ordinary locals.
// Current pass: the retained typed source builds to 495 bytes with 9 aligned
// calls and no frame/EH. The best strict diff is 39 bytes (7.8788%), first
// mismatch +0x0e.
// Direct y1/x2 parameter-home reuse, a split 56-slot TPanel surface, coordinate
// aliases, and register-qualified locals were codegen duplicates. A bool flag,
// declaration-site pointer initialization, and explicit radius arms regressed.
// Left in scratch: rebuilt size/calls/frame match, with exact first-pass and
// later loop islands. The first mismatch remains the initial y-coordinate load:
// original keeps y1 in EBX, while rebuilt keeps y2. The radius block also uses
// a different coordinate register map. No policy-valid exact source was found.
// ACCEPTED DRIFT: The changed regions use different registers for x1, y1, x2,
// y2, dx, dy, and the second-pass counter. Both builds push identical helper
// arguments, compute the same wrapped coordinate differences and radius, and
// visit objects in the same order. Reordered reads are parameter or private
// stack reads. Calls, used flags, memory effects, returns, and fault behavior
// match.

struct RGE_Pick_Obj_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};

extern RGE_Pick_Obj_Info Picked_Objects[];

class RGE_Static_Object_Master { public: char pad[0x8d]; unsigned char select_level; };
class RGE_Player;
class RGE_Static_Object {
public:
    void* vtbl;
    char pad04[4];
    RGE_Static_Object_Master* master_obj; // +8
    RGE_Player* owner; // +c
    char pad10[0x38-0x10];
    float x; // +38
    float y; // +3c
    char pad40[0x48-0x40];
    unsigned char object_state; // +48
};
class RGE_World { public: char pad[0x88]; RGE_Static_Object** objectsValue; };
class RGE_Visible_Map { public: unsigned char get_visible(int x, int y); };
class RGE_Player { public: char pad[0x38]; RGE_Visible_Map* visible; char pad2[0x4a-0x3c]; short id; int select_one_object(RGE_Static_Object*, int); };
class RGE_Map { public: char pad[0x8db8]; unsigned char map_visible_flag; };

class TPanel {
public:
    virtual void v0();
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    char pad004[0xfc-4];
};

class RGE_View : public TPanel {
public:
    virtual int can_pick(RGE_Static_Object*);
    virtual int pick_score(RGE_Static_Object*, int picked_index);

    RGE_World* world; // +fc
    RGE_Player* player; // +100
    RGE_Map* map; // +104

    unsigned char pick_multi(unsigned char p1, long x1, long y1, long x2, long y2);
protected:
    int pick_multi_objects(int x1, int y1, int x2, int y2,
                           int a, int b, int player, unsigned char p1, int flag);
    int pick_objects(int x, int y, int a, int b, int radius, int c, int d);
};

unsigned char RGE_View::pick_multi(unsigned char p1, long x1, long y1, long x2, long y2)
{
    int count;
    int i = 0;
    int picked_any = 0;
    RGE_Static_Object* picked_obj;
    count = this->pick_multi_objects(x1, y1, x2, y2, 10, 20, this->player->id, p1, 1);
    if (count > 0) {
        RGE_Pick_Obj_Info* pp = Picked_Objects;
        do {
            int idx = pp->object_id;
            if (idx != -1) {
                RGE_Static_Object* obj = this->world->objectsValue[idx];
                if (obj != 0 && obj->object_state < 7) {
                    if (!this->player->select_one_object(obj,0)) break;
                    picked_any = 1;
                }
            }
            i++;
            ++pp;
        } while (i < count);
    }
    if (picked_any) return 1;

    int dx;
    int dy;
    dx = x2 - x1;
    dy = y2 - y1;
    int r = dx;
    if (dx >= dy) r = dy;
    if (r < 50) {
        r = dy;
        if (dx < dy) r = dx;
    } else r = 50;

    count = this->pick_objects(x1 + dx/2, y1 + dy/2, 10, 20, r, 4, 1);
    if (count) {
        int bestScore = 0;
        picked_obj = 0;
        int remaining;
        if (count > 0) {
            RGE_Pick_Obj_Info* pp = Picked_Objects;
            remaining = count;
            do {
                int idx = pp->object_id;
                if (idx >= 0) {
                    RGE_Static_Object* obj = this->world->objectsValue[idx];
                    if (obj && obj->object_state < 7 && obj->master_obj->select_level >= 2) {
                        if (!this->map->map_visible_flag && !this->can_pick(obj)) {
                            int vy = (int)obj->y;
                            int vx = (int)obj->x;
                            if (this->player->visible->get_visible(vx, vy) != 0x0f) goto next;
                        }
                        int score = this->pick_score(obj, pp->confidence);
                        if (obj->owner == this->player) score += 5;
                        if (score > bestScore) { picked_obj = obj; bestScore = score; }
                    }
                }
next:
                ++pp;
                remaining--;
            } while (remaining != 0);
        }
        if (picked_obj && this->player->select_one_object(picked_obj,0)) return 1;
    }
    return 0;
}

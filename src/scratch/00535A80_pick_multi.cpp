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
// Left in scratch: best source has correct object/master offsets, count in EBP and index in ESI after hoisting loop index. Remaining mismatch starts at initial parameter register allocation: rebuilt keeps y2 in EBX where original keeps y1 in EBX and reloads y2 through EAX; this shifts early call setup and later rectangle math. Later second-pass loop/calls are behaviorally close but still have register/block-layout drift.

extern int Picked_Objects[];
extern "C" int __cdecl ftol_dummy(float); // not called; cast uses ftol

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

class RGE_View {
public:
    virtual void v0();
    // pad to vt[0xe0/4=56], vt[0xe4/4=57]
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual int can_pick(RGE_Static_Object*);
    virtual int pick_score(RGE_Static_Object*, int picked_index);

    char pad004[0xfc-4];
    RGE_World* world; // +fc
    RGE_Player* player; // +100
    RGE_Map* map; // +104

    unsigned char pick_multi(unsigned char p1, long x1, long y1, long x2, long y2);
    int pick_multi_objects(long x1,long y1,long x2,long y2,int a,int b,int player,unsigned char p1,int flag);
    int pick_objects(long x,long y,int a,int b,int radius,int c,int d);
};

unsigned char RGE_View::pick_multi(unsigned char p1, long x1, long y1, long x2, long y2)
{
    int picked_any = 0;
    register int i = 0;
    register long y1r = y1;
    register int count = this->pick_multi_objects(x1, y1r, x2, y2, 10, 20, this->player->id, p1, 1);
    if (count > 0) {
        int* pp = Picked_Objects;
        do {
            int idx = *pp;
            if (idx != -1) {
                RGE_Static_Object* obj = this->world->objectsValue[idx];
                if (obj != 0 && obj->object_state < 7) {
                    if (this->player->select_one_object(obj,0)) picked_any = 1;
                    else break;
                }
            }
            i++;
            pp += 3;
        } while (i < count);
    }
    if (picked_any) return 1;

    x2 = x2 - x1;
    y2 = -(y1r - y2);
    int dx = x2;
    int dy = y2;
    int r = dx;
    if (dy <= dx) r = dy;
    if (r < 50) {
        r = dy;
        if (dx < dy) r = dx;
    } else r = 50;

    count = this->pick_objects(x1 + dx/2, y1r + dy/2, 10, 20, r, 4, 1);
    if (count) {
        int bestScore = 0;
        RGE_Static_Object* best = 0;
        if (count > 0) {
            int* pp = Picked_Objects;
            do {
                int idx = *pp;
                if (idx >= 0) {
                    RGE_Static_Object* obj = this->world->objectsValue[idx];
                    if (obj && obj->object_state < 7 && obj->master_obj->select_level >= 2) {
                        if (!this->map->map_visible_flag && !this->can_pick(obj)) {
                            int vy = (int)obj->y;
                            int vx = (int)obj->x;
                            if (this->player->visible->get_visible(vx, vy) != 0x0f) goto next;
                        }
                        int score = this->pick_score(obj, (short)pp[1]);
                        if (obj->owner == this->player) score += 5;
                        if (score > bestScore) { best = obj; bestScore = score; }
                    }
                }
next:
                pp += 3;
                count--;
            } while (count != 0);
        }
        if (best && this->player->select_one_object(best,0)) return 1;
    }
    return 0;
}

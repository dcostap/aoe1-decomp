// 005396F0 RGE_View::pick_multi_objects
// Attempt log:
// initial decompiler-shaped source from packet: behavior/field offsets plausible but broad mismatch; VC5 chose EBP=this and ECX=count while original has EBX=this and EBP=count.
// added local self alias and register num_picked; no register allocation improvement.
// changed early returns to shared goto fail; improved positional diff from 88.69% to 70.85% by avoiding inline early-return epilogues, kept.
// tried /O2 /Oy /Ob0; no codegen change from default, removed custom flag.
// tried /O1 /Oy; function shrank to 454B and failed section-size check, removed custom flag.
// tried /O2 /Oy /Og-; generated EBP frame and much worse 92.93% diff, removed custom flag.
// tried explicit self alias throughout instead of direct member access; no prologue/register improvement but kept as part of current best shared-fail source.
// tried register num_picked to force EBP=count; VC5 still used ECX for count and EBP for this.
// local/global layout facts verified against asm: RGE_View +8c/+90/+94/+98 bounds, +fc world, +334 prior_objs; DClipInfo_Node +4 next, +8 object id, +2c type, +30..+36 bounds, +14/+18 draw coords; object +48 state, master +8d select_level.
// left in scratch: remaining mismatch is not accepted-drift-safe. Current default build has correct broad behavior but wrong callee-saved register topology and block layout: original starts `push ebx; mov ebx,ecx; push ebp; push esi; xor ebp,ebp`, uses shared far fail epilogue at end, and later restores EBX/EBP around inner loops; rebuilt starts `push ebx; push ebp; mov ebp,ecx; ... xor ecx,ecx`, uses earlier fail block, and cascades broad branch/register differences.

extern int Picked_Objects[];

struct RGE_Master_Object { char gap_00[0x8d]; unsigned char select_level; };
struct RGE_Player { char gap_00[0x4a]; short id; };
struct RGE_Static_Object {
    void* vtbl;
    char gap_04[4];
    RGE_Master_Object* master_obj; // +8
    RGE_Player* owner;             // +c
    char gap_10[0x48-0x10];
    unsigned char object_state;     // +48
};
struct RGE_World { char gap_00[0x88]; RGE_Static_Object** objectsValue; };
struct DClipInfo_Node {
    char gap_00[4];
    DClipInfo_Node* NextOnLevel; // +4
    int Object_ID;               // +8
    char gap_0c[8];
    short Draw_X;                // +14
    char gap_16[2];
    short Draw_Y;                // +18
    char gap_1a[0x2c-0x1a];
    int Node_Type;               // +2c
    short x1;                    // +30
    short y1;                    // +32
    short x2;                    // +34
    short y2;                    // +36
};
struct DClipInfo_List { char gap_00[0x5c]; DClipInfo_Node** Draw_Level_Head; };

class RGE_View {
public:
    virtual void v0();
    char gap_04[0x8c-4];
    int min_x; // +8c
    int min_y; // +90
    int max_x; // +94
    int max_y; // +98
    char gap_9c[0xfc-0x9c];
    RGE_World* world; // +fc
    char gap_100[0x334-0x100];
    DClipInfo_List* prior_objs; // +334

    int pick_multi_objects(int x1, int y1, int x2, int y2, int min_level, int max_level, int player_id, unsigned char select_level, int flag);
};

int RGE_View::pick_multi_objects(int x1, int y1, int x2, int y2, int min_level, int max_level, int player_id, unsigned char select_level, int flag)
{
    register int num_picked = 0;
    int z;
    RGE_View* self = this;
    if (x2 < self->min_x) goto fail;
    if (x1 > self->max_x) goto fail;
    if (y2 < self->min_y) goto fail;
    if (y1 > self->max_y) goto fail;
    if (min_level > 40) goto fail;
    if (max_level < 0) goto fail;
    if (min_level < 0) min_level = 0;
    if (max_level > 40) max_level = 40;

    x1 -= self->min_x;
    x2 -= self->min_x;
    y1 -= self->min_y;
    y2 -= self->min_y;

    z = max_level;
    if (max_level < min_level) return num_picked;
    do {
        DClipInfo_Node* node = self->prior_objs->Draw_Level_Head[z];
        if (node != 0) {
            short* out = (short*)((char*)Picked_Objects + 4 + num_picked * 12);
            do {
                int ok = 0;
                if (node->Node_Type == 0) {
                    int object_id = node->Object_ID;
                    if (object_id >= 0) {
                        if (x1 <= (int)node->x2 && x2 >= (int)node->x1 &&
                            y1 <= (int)node->y2 && y2 >= (int)node->y1) {
                            RGE_Static_Object* obj = self->world->objectsValue[object_id];
                            if (player_id == -1 || obj->owner->id == player_id) {
                                if (obj->object_state == 2 && obj->master_obj->select_level >= select_level) {
                                    ok = 1;
                                }
                            }
                        }
                    }
                }
                if (ok != 0) {
                    int add = 1;
                    if ((int)out > (int)((char*)Picked_Objects + 4)) {
                        int i = 0;
                        int* p = Picked_Objects;
                        while ((int)out > (int)((char*)Picked_Objects + 4)) {
                            if (*p == node->Object_ID) {
                                add = 0;
                                if ((short)ok < *((short*)((char*)Picked_Objects + 4 + i * 12))) {
                                    *((short*)((char*)Picked_Objects + 4 + i * 12)) = (short)ok;
                                }
                                break;
                            }
                            i++;
                            p += 3;
                            if (i >= num_picked) break;
                        }
                    }
                    if (add) {
                        *(int*)(out - 2) = node->Object_ID;
                        out[0] = (short)ok;
                        out[1] = (short)ok;
                        out[2] = node->Draw_X;
                        out[3] = node->Draw_Y;
                        num_picked++;
                        out += 6;
                    }
                    if ((int)out >= (int)((char*)Picked_Objects + 0x304)) return 0x40;
                }
                node = node->NextOnLevel;
            } while (node != 0);
        }
        z--;
    } while (z >= min_level);
    return num_picked;
fail:
    return 0;
}

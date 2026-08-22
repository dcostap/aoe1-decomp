// 005396F0 RGE_View::pick_multi_objects
// Attempt log:
// current pass: canonicalized the local world, master, player, and object
// overlays to the repository names and proven field ownership; matched the
// protected member access from the original decorated symbol. Split the
// viewport and level guards to follow the PDB bands; VC5 emitted the same
// 566-byte body.
// tested a loop-scoped object-id lifetime through duplicate suppression and
// output; it grew to 571B with a 0x10 frame and was restored. A canonical
// TPanel-base view surface moved 2 bytes farther and was restored.
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
// matching-worker probes: one short-circuit bounds guard plus the in-loop z<min return improved CFG/shape but not bytes; the typed RGE_Pick_Obj_Info global was codegen-neutral.
// matching-worker probe: natural RGE_Pick_Obj_Info output ownership recovered EBX=this and exact size, but retained a broad register/global-address mismatch; entry-plus-confidence cursor and field-cursor variants were worse or duplicate.
// matching-worker probes: reusing max_level as the node object-id home (with local or direct object expressions) caused a larger frame and broad regression; rolled back because the stack write can be compiler local-home reuse rather than source parameter mutation.
// matching-worker probe: restored the typed view.cpp donor context with an RGE_View : TPanel surface; VC5 emitted a codegen duplicate, so the prior clean source remains.
// matching-worker probe: moved the proven z>=min_level test outside the descending loop, matching the original pre-loop compare and shared count-return path; emitted code was an exact duplicate with no metric movement.
// matching-worker probe: a natural do-while duplicate scan removed the repeated output-pointer loop test; size reached 566B and strict diff improved to 420B, but register coloring remained broad.
// matching-worker diagnostics: direct confidence-field cursor plus the do-while scan reached 566B/417B, but raw field-pointer writes were rolled back in favor of the typed record source.
// matching-worker probes: self alias and register-qualified count were codegen duplicates; split record/confidence aliases regressed to 482B.
// final bounded best: natural typed record output, split viewport/level
// guards, and do-while duplicate scan; 566 rebuilt bytes, 420 strict diff,
// 72.09% shape, 34.30% exact-block coverage. Remaining drift is broad VC5
// register/block topology and global-address relocation, not safe localized drift.
// Main review replaced manual vptr fields with typed virtual ownership.
// A same-TU draw_view donor proves the four +0x8C fields form render_rect.
// Main review rejected a confidence-field cursor and pointer-relative object-id
// store. Keep typed RGE_Pick_Obj_Info ownership despite its three-byte penalty.

class RGE_Pick_Obj_Info {
public:
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};

extern RGE_Pick_Obj_Info Picked_Objects[];

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x89];
    unsigned char select_level;
};
struct RGE_Player {
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;
};
struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj; // +8
    RGE_Player* owner;             // +c
    char gap_10[0x48-0x10];
    unsigned char object_state;     // +48
};
struct RGE_Game_World {
    virtual ~RGE_Game_World();
    char gap_04[0x84];
    RGE_Static_Object** objectsValue;
};
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
    struct tagRECT {
        long left;
        long top;
        long right;
        long bottom;
    } render_rect; // +8c
    char gap_9c[0xfc-0x9c];
    RGE_Game_World* world; // +fc
    char gap_100[0x334-0x100];
    DClipInfo_List* prior_objs; // +334

protected:
    int pick_multi_objects(int x1, int y1, int x2, int y2, int min_level, int max_level, int player_id, unsigned char select_level, int flag);
};

int RGE_View::pick_multi_objects(int x1, int y1, int x2, int y2, int min_level, int max_level, int player_id, unsigned char select_level, int flag)
{
    int num_picked = 0;
    int z;
    if (x2 < this->render_rect.left || x1 > this->render_rect.right ||
        y2 < this->render_rect.top || y1 > this->render_rect.bottom)
        return 0;
    if (min_level > 40 || max_level < 0)
        return 0;
    if (min_level < 0) min_level = 0;
    if (max_level > 40) max_level = 40;

    x1 -= this->render_rect.left;
    x2 -= this->render_rect.left;
    y1 -= this->render_rect.top;
    y2 -= this->render_rect.top;

    z = max_level;
    if (z >= min_level) {
        do {
            DClipInfo_Node* node = this->prior_objs->Draw_Level_Head[z];
            if (node != 0) {
                RGE_Pick_Obj_Info* out = &Picked_Objects[num_picked];
                do {
                    int ok = 0;
                    if (node->Node_Type == 0) {
                        int object_id = node->Object_ID;
                        if (object_id >= 0) {
                            if (x1 <= (int)node->x2 && x2 >= (int)node->x1 &&
                                y1 <= (int)node->y2 && y2 >= (int)node->y1) {
                                RGE_Static_Object* obj = this->world->objectsValue[object_id];
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
                        if (out > Picked_Objects) {
                            int i = 0;
                            RGE_Pick_Obj_Info* p = Picked_Objects;
                            do {
                                if (p->object_id == node->Object_ID) {
                                    add = 0;
                                    if ((short)ok < Picked_Objects[i].confidence) {
                                        Picked_Objects[i].confidence = (short)ok;
                                    }
                                    break;
                                }
                                i++;
                                ++p;
                            } while (i < num_picked);
                        }
                        if (add) {
                            out->object_id = node->Object_ID;
                            out->confidence = (short)ok;
                            out->draw_level = (short)ok;
                            out->draw_x = node->Draw_X;
                            out->draw_y = node->Draw_Y;
                            num_picked++;
                            ++out;
                        }
                        if (out >= Picked_Objects + 64) return 0x40;
                    }
                    node = node->NextOnLevel;
                } while (node != 0);
            }
            z--;
        } while (z >= min_level);
    }
    return num_picked;
}

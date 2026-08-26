// 00539EC0 RGE_View::hit_object
// Attempt log:
// initial natural decomp from packet produced same 517B size but broad shifted mismatch; frame was too small (0x10 vs 0x1c).
// hoisted get_frame temporaries to function scope; recovered original 0x1c frame and prologue through the first local-zero store.
// tried adding point/local aliases for parameter liveness; no improvement, kept only x/y aliases because they preserve param register loads.
// tried while-loop form instead of do/while; object grew/shrank badly and failed size-section check, rolled back.
// tried delayed cur assignment after first-null test; worsened early store/check scheduling, rolled back.
// tried signed char mode local vs unsigned mode local; no byte change.
// tried direct this->function_mode tests instead of a mode local; no byte change.
// tried /O1 custom flags; .text too small / wrong size, removed flag.
// tried /O2 /Oy /Og- custom flags; produced EBP frame and much worse diff, removed flag.
// tried combining picked-owner/select-level tests into && expressions; no byte change.
// left in scratch: behavior/calls/stack cleanup look plausible, but loop prologue scheduling differs: original stores sort result in two stack slots, loads x/y/point params, then enters loop; rebuilt hoists first node load/test before those param loads and uses different save-list stack slots (+1c/+28 vs original +20/+1c).
// session sa7b331c8e_r1 baseline: current natural candidate rebuilt at 517B/0x1c frame, diff 440; checker stage was structural reconstruction.
// changed special-mode source to a natural plus/comma-owner if/else; ordered box/select/hit calls then aligned 6/6 and diff reached 384 at 517B.
// removed the redundant pre-loop cursor guard (duplicate codegen); delayed cursor declaration worsened the prologue and was restored.
// swapped retained cleanup-head and loop-cursor roles; cursor now uses the oracle's +1c home, but VC5 keeps the retained head at +28 instead of oracle +20.
// corrected stat_obj donor ABI: hit_test takes five shorts and get_frame takes four short references; call relocation spellings now agree without code movement.
// modeled the binary-proven get_frame window with dword local_4 and the tile parameter home; the third-output LEA at +12 matches, but the initial node load still precedes oracle parameter preloads.
// bounded session exhausted at 10 meaningful hypotheses; leave this readable typed reconstruction in scratch. Remaining lead: recover the original list-head +20 home and parameter-preload loop scheduling before any register tuning.
// tried splitting the natural mode/owner collision predicate; call sites and block shape diverged badly, rolled back to the clean source.
// moved natural x/y aliases before the first-node guard; VC5 emitted duplicate code, so restored the clean reconstruction.
// natural for-condition with typed node assignment recovered 96% exact blocks but shifted the select-level compare; kept as the new source shape.
// reversed the select-level comparison to load the master object first; diff fell to 10 bytes with exact CFG and calls.
// direct comma-mode gating was behavior-plausible but lost size and block parity; rolled back.
// duplicated the ordinary hit arm was structurally poor; rolled back.
// retained the binary-backed ordinary-hit label join for mode '+' and non-special modes; exact 517B match.

#ifndef RGE_VIEW_SHARED_CONTEXT
struct tagPOINT { long x; long y; };

struct RGE_Master_Object {
    char gap_00[0x65];
    unsigned char fog_flag;
    char gap_66[0x27];
    unsigned char select_level;
};

struct RGE_Player;

struct RGE_Static_Object {
    char gap_00[8];
    RGE_Master_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x18];
    short screen_x_offset;
    short screen_y_offset;
    char gap_2C[0x1C];
    unsigned char object_state;

    unsigned char hit_test(short x, short y, short x2, short y2, short mode);
    unsigned char box_hit_test(short x, short y, short x2, short y2, short x3, short y3);
    int get_frame(short& min_x, short& min_y, short& max_x, short& max_y);
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

struct RGE_Object_List {
    char gap_00[0x0C];
    RGE_Object_Node* sort();
};

struct RGE_Tile {
    char gap_00[0x0C];
    RGE_Object_List objects;
};

struct RGE_Player {
    int select_one_object(RGE_Static_Object* obj, int flag);
};

class RGE_View {
public:
    char gap_00[0x100];
    RGE_Player* player;
    char gap_104[0x3C];
    unsigned char function_mode;
    unsigned char function_parm;

protected:
    RGE_Static_Object* hit_object(RGE_Tile* tile, short x, short y, short a, short b,
                                  tagPOINT* p1, tagPOINT* p2, short* out_x, short* out_y,
                                  RGE_Static_Object* skip, unsigned char through_fog);
};
#endif

extern "C" void __cdecl free(void*);

RGE_Static_Object* RGE_View::hit_object(RGE_Tile* tile, short x, short y, short a, short b,
                                        tagPOINT* p1, tagPOINT* p2, short* out_x, short* out_y,
                                        RGE_Static_Object* skip, unsigned char through_fog)
{
    short min_x;
    int local_4;
    RGE_Object_Node* first;
    short min_y;
    short max_y;
    RGE_Static_Object* picked = 0;
    if (&tile->objects != 0) {
#ifdef RGE_VIEW_SHARED_CONTEXT
        first = tile->objects->sort();
#else
        first = tile->objects.sort();
#endif
        RGE_Object_Node* cur = first;
        short sx = x;
        short sy = y;
        RGE_Static_Object* obj;
        for (; cur != 0 && (obj = cur->node) != 0; cur = cur->next) {
                if (obj->object_state < 7) {
                    if ((!through_fog || obj->master_obj->fog_flag) &&
                        obj->master_obj->select_level >= this->function_parm) {
                        if (this->function_mode == '+' || this->function_mode == ',') {
                            if (obj->owner == this->player) {
                            if (this->function_mode == ',') {
                                if (obj->box_hit_test(sx, sy, (short)p2->x, (short)p2->y,
                                                      (short)p1->x, (short)p1->y)) {
                                    if (!this->player->select_one_object(obj, 0)) break;
                                    picked = obj;
                                }
                            } else {
                                goto ordinary_hit;
                            }
                            }
                        } else {
ordinary_hit:
                            if (obj->hit_test(sx, sy, (short)p1->x, (short)p1->y, 5)) {
                            if (skip != 0 && obj == skip && picked != 0) {
                                return picked;
                            }
                            if (picked != 0 && obj->owner != this->player && picked->owner == this->player) goto next;
                            if (picked != 0 && obj->master_obj->select_level < picked->master_obj->select_level) goto next;
                            {
                                picked = obj;
                                if (!obj->get_frame(min_y, (short&)local_4, min_x, max_y)) {
                                    min_y = 0;
                                    local_4 = 0;
                                }
                                *out_x = (short)(obj->screen_x_offset + min_y + sx);
                                *out_y = (short)(obj->screen_y_offset + (short)local_4 + sy);
                            }
                            }
                        }
                    }
                }
next:
                ;
        }
        while (first != 0) {
            RGE_Object_Node* next_node = first->next;
            free(first);
            first = next_node;
        }
    }
    return picked;
}

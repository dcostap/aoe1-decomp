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

    unsigned char hit_test(short x, short y, short x2, short y2, int mode);
    unsigned char box_hit_test(short x, short y, short x2, short y2, short x3, short y3);
    int get_frame(short* min_x, short* min_y, short* max_x, short* max_y);
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

    RGE_Static_Object* hit_object(RGE_Tile* tile, short x, short y, short a, short b,
                                  tagPOINT* p1, tagPOINT* p2, short* out_x, short* out_y,
                                  RGE_Static_Object* skip, unsigned char through_fog);
};

extern "C" void __cdecl free(void*);

RGE_Static_Object* RGE_View::hit_object(RGE_Tile* tile, short x, short y, short a, short b,
                                        tagPOINT* p1, tagPOINT* p2, short* out_x, short* out_y,
                                        RGE_Static_Object* skip, unsigned char through_fog)
{
    short min_x;
    short min_y;
    short max_x;
    short max_y;
    RGE_Static_Object* picked = 0;
    if (&tile->objects != 0) {
        RGE_Object_Node* first = tile->objects.sort();
        RGE_Object_Node* cur = first;
        if (cur != 0) {
            short sx = x;
            short sy = y;
            do {
                RGE_Static_Object* obj = cur->node;
                if (obj == 0) break;
                if (obj->object_state < 7) {
                    if ((!through_fog || obj->master_obj->fog_flag) &&
                        this->function_parm <= obj->master_obj->select_level) {
                        if (this->function_mode == '+' || this->function_mode == ',') {
                            if (obj->owner != this->player) goto next;
                            if (this->function_mode != ',') goto normal_hit;
                            if (!obj->box_hit_test(sx, sy, (short)p2->x, (short)p2->y,
                                                   (short)p1->x, (short)p1->y)) goto next;
                            if (!this->player->select_one_object(obj, 0)) break;
                            picked = obj;
                            goto next;
                        }
normal_hit:
                        if (obj->hit_test(sx, sy, (short)p1->x, (short)p1->y, 5)) {
                            if (skip != 0 && obj == skip && picked != 0) {
                                return picked;
                            }
                            if (picked != 0 && obj->owner != this->player && picked->owner == this->player) goto next;
                            if (picked != 0 && obj->master_obj->select_level < picked->master_obj->select_level) goto next;
                            {
                                picked = obj;
                                if (!obj->get_frame(&min_x, &min_y, &max_x, &max_y)) {
                                    min_y = 0;
                                    max_x = 0;
                                }
                                *out_x = (short)(obj->screen_x_offset + min_y + sx);
                                *out_y = (short)(obj->screen_y_offset + max_x + sy);
                            }
                        }
                    }
                }
next:
                cur = cur->next;
            } while (cur != 0);
        }
        while (first != 0) {
            RGE_Object_Node* next_node = first->next;
            free(first);
            first = next_node;
        }
    }
    return picked;
}

// VA: 004712F0 RGE_Player::get_selected_objects_to_command
// PDB source: player.cpp, lines 2158-2209
//
// Baseline reconstruction: allocate a candidate list, filter the selected
// objects by master-object properties, and return the accepted list/count.
//
// Attempt log:
// - Modeled the proven contiguous list/list-count stack window as a typed
//   local aggregate; this recovers the 0x8 frame and exact calloc/free call
//   set without raw frame offsets.
// - Moved counter initialization before the output stores and used the
//   binary-proven zero-extended select-level/short comparison.
// - Left in scratch: 256 positional bytes remain, principally prologue
//   register coloring, the distinct stack list-count/cursor lifetime, and
//   the target load-before-sub-esp scheduling. No opaque register forcing or
//   fake volatility is retained.
// - This pass tried output-store ordering, direct-this/alias and cursor
//   declaration permutations, and separate list/list_count locals; none beat
//   the aggregate 0x8-frame basin.
// - A diagnostic volatile list_count reproduced the target stack home and
//   reduced drift to 121B but added reloads and retained wrong register roles;
//   it was restored. A three-variant init-order lab found no exact candidate.
// - Corrected the behavior topology: list_count advances only for non-null
//   selected objects, after the filter chain; cursor and outer-index advances
//   stay outside that branch. Size became exact and drift fell to 9B.
// - Spelled the loop bound as list_count >= sel_count to match the target
//   compare order. Drift fell to 7B with 96.12% exact-block coverage.
// - Left in scratch: the remaining 7B is localized to prologue/register
//   coloring and the select-level compare polarity; no evidence-backed probe
//   remains in this assignment.

class RGE_Player;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    unsigned char master_type;
    char gap_05[0x0B];
    short id;
    char gap_12[2];
    short object_group;
    char gap_16[0x77];
    unsigned char select_level;
    char gap_8E[1];
    unsigned char unit_level;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x38];
    unsigned char object_state;
};

extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);

struct Selection_Locals {
    int list_count;
    RGE_Static_Object** list;
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    char gap_04[0x46];
    short id;
    char gap_4C[0xE4];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    char gap_198[4];
    short sel_count;

    unsigned char get_selected_objects_to_command(
        RGE_Static_Object***, short*, short, short, short, short);
};

unsigned char RGE_Player::get_selected_objects_to_command(
    RGE_Static_Object*** out_list, short* out_count,
    short min_select_level, short object_group, short object_id,
    short unit_level)
{
    RGE_Player* player = this;
    long j;
    RGE_Static_Object** selected;
    short count;
    RGE_Static_Object* object;
    RGE_Master_Static_Object* master;

    j = 0;
    *out_list = 0;
    count = 0;
    Selection_Locals locals;
    *out_count = 0;
    if (player->sel_count == 0) {
        return 0;
    }

    locals.list = (RGE_Static_Object**)calloc(4, (unsigned int)player->sel_count);
    if (min_select_level == -1) {
        min_select_level = 4;
    }

    locals.list_count = 0;
    selected = player->sel_list;
    while (j < 0x19) {
        if (locals.list_count >= player->sel_count) {
            break;
        }

        object = *selected;
        if (object != 0) {
            if (object->object_state == 2 && object->owner == player) {
                master = object->master_obj;
                if ((unsigned short)master->select_level >=
                        (unsigned short)min_select_level || player->id == 0) {
                    if (object_group == -1 ||
                        master->object_group == (unsigned char)object_group) {
                        if (object_id == -1 ||
                            master->id == (unsigned char)object_id) {
                            if (unit_level == -1 ||
                                master->unit_level == (unsigned char)unit_level) {
                                if (master->master_type >= 0x28 &&
                                    master->master_type != 0x5A) {
                                    locals.list[count] = object;
                                    ++count;
                                }
                            }
                        }
                    }
                }
            }
            ++locals.list_count;
        }
        ++j;
        ++selected;
    }

    if (count == 0) {
        free(locals.list);
        return 0;
    }

    *out_list = locals.list;
    *out_count = count;
    return 1;
}

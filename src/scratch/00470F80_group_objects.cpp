// VA: 00470F80 RGE_Player::group_objects
// PDB source: player.cpp, lines 1933-2009
//
// Baseline reconstruction: reserve or recover a group number, clear that
// group from existing objects when requested, then mark this player's
// selected objects with the resulting group.
//
// Attempt log:
// - Added the proven polymorphic player/object/list surfaces and a byte
//   selected_group local; BL then reproduces the original table-byte tests,
//   parameter-home reuse, and common selected-object stores.
// - Bounded for scans (rather than peeled do/while forms) recover the first
//   search and second recovery search CFG; the natural typed source remains
//   in scratch because exactness stalled at 37 positional bytes (+9 bytes).
// - Remaining binary-local drift is the second memset setup order and the
//   common selection-tail counter compare/register order; no opaque steering
//   or fake volatility was retained.
// - An ordinary byte-clear loop compiles to the exact REP-stos block and
//   removes the memset setup-order drift; swapped count/index declarations
//   recover ESI-then-EDI zeroing. The remaining 24 bytes are the compiler's
//   nested count recheck/polarity and a 9-byte late tail beyond the boundary.
// - Outer-guard/goto, pointer/header, and typed dword-clear variants were
//   tested and restored; they either changed the whole CFG or worsened output.
// - A count-controlled `while (count < sel_count)` with an index increment and
//   post-bound break improved shape to 96.15%, but VC5 still emitted a second
//   count check before the back-edge; the original has one guard at the tail.
// - Inverting the post-bound test to `continue` below 0x19 was codegen-identical
//   and less direct, so the direct while/break form remains the best source.
// - The exact player.cpp ungroup_objects tail donor uses an index-bound while
//   with the selected-count guard first; using that natural short index/count
//   form removed the prior 24-byte tail drift and matched size and CFG.
// - Spelling the guard as `count >= sel_count` produced the original compare
//   operand order and closed the final 2-byte mismatch in the narrow owner
//   context.  The complete player TU retains a six-byte SIB-order drift after
//   the canonical RGE_Game_World virtual surface is restored for addObject.
//   Direct member, pointer, and commuted array expressions keep the same
//   register map.  Do not retain a non-source steering construct for this.
// - The grouped player build now uses the canonical RGE_Player declaration
//   from include/rge_player_context.h.  Its addObject/removeObject neighbors
//   emit the original 0xF8/0xFC world slots and exact 71/88-byte bodies.

#include <string.h>


#ifndef PLAYER_GROUPED_TU
class RGE_Player;
class RGE_Game_World;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x27];
    unsigned char selected_group;
};

struct RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    unsigned char gap_0D[3];
};

class RGE_Object_List {
public:
    virtual void load(unsigned char, int, RGE_Game_World*);
    RGE_Object_Node* list;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects;
    char gap_2C[0x104];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;
    unsigned char groups_used[127];

    int group_objects(int);
};

#endif

int RGE_Player::group_objects(int group)
{
    unsigned char selected_group;
    if (!sel_count) {
        return 0;
    }

    if (group == -1) {
        short i = 0x0B;
        for (; i < 0x7F; ++i) {
            if (groups_used[i]) {
                continue;
            }
            selected_group = (unsigned char)i;
            groups_used[i] = 1;
            break;
        }

        if (i == 0x7F) {
            for (int clear_i = 1; clear_i < 0x7F; ++clear_i) {
                groups_used[clear_i] = 0;
            }

            RGE_Object_Node* node = objects->list;
            while (node) {
                selected_group = node->node->selected_group;
                if (selected_group && !groups_used[selected_group]) {
                    groups_used[selected_group] = 1;
                }
                node = node->next;
            }

            i = 1;
            for (; i < 0x7F; ++i) {
                if (groups_used[i]) {
                    continue;
                }
                selected_group = (unsigned char)i;
                groups_used[i] = 1;
                break;
            }

            if (i == 0x7F) {
                return 0;
            }
        }
    } else {
        selected_group = (unsigned char)group;
        RGE_Object_Node* node = objects->list;
        while (node) {
            if (node->node->selected_group == (unsigned char)group) {
                node->node->selected_group = 0;
            }
            node = node->next;
        }
    }

    short i = 0;
    short count = 0;
    while (i < 0x19) {
        if (count >= sel_count) {
            break;
        }
        RGE_Static_Object* object = sel_list[i];
        if (object && object->owner == this) {
            ++count;
            object->selected_group = selected_group;
        }
        ++i;
    }

    return 1;
}

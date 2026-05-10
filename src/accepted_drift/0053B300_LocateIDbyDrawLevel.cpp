// VA: 0053B300 DClipInfo_List::LocateIDbyDrawLevel (103 B)
// PDB source: view.cpp lines 6800-6822
// Notes: current best is 14.56% positional diff (15/103 bytes), edit diff 5.
// All structural elements match: prologue, swap, clamp, validation, loop, inner walk, epilogue.
// Remaining diff is localized: original emits `mov edx,eax` before the `jg` low>high validation
// and therefore uses a shorter branch displacement; rebuilt delays `mov edx,eax` until after
// loading Draw_Level_Head/params. Current best also matches original bottom-loop `inc edx; add ecx,4` order.
// Tried before this pass: declaration order, variable naming (Ghidra-style), pointer walk vs indexed access,
// do-while vs for, temp variable styles; none fixed eax/edx swap / loop-counter scheduling.
// SpruceGlow tries 1-10: reversed initial low/high, mutate-parameter form, nested-if, goto, while/for pointer,
// param-order aliases, explicit level temp, object/node local aliases, and reversed compare forms. Mutating the
// incoming level parameters fixed the initial eax/edx register choice and improved to edit diff 7, but still
// delayed `mov edx,eax` and had bottom `add/inc` reversed.
// SpruceGlow tries 11-20: nested positive validation with mutated params is best (edit diff 5): it preserves the
// initial register choice and bottom `inc/add` order; remaining mismatch is only the delayed loop-counter copy
// (`mov edx,eax`) crossing the validation branch. Separate level-before-check, for-increment order, param-as-loop,
// preincrement pointer, goto/continue forms, and direct member indexing were worse or same.
// ACCEPTED_DRIFT: reviewed by Boss. Behavior is correct and drift is localized to
// movement of the loop-counter copy `mov edx,eax` from before to after the validated
// low<=high branch setup. The copied value is only used by the subsequent loop, all
// validation predicates/branch targets, loop body, memory reads, return paths, size,
// and epilogue are identical; remaining byte differences are the moved instruction
// and one short-branch displacement adjustment. No inline asm/hacks.

struct DClipInfo_Node {
    DClipInfo_Node* field_0;
    DClipInfo_Node* NextOnLevel;
    int Object_ID;
    char gap_0C[0x20];
    int Node_Type;
};

class DClipInfo_List {
public:
    char gap_00[0x4C];
    int Max_Draw_Levels;
    char gap_50[0x0C];
    DClipInfo_Node** Draw_Level_Head;

    DClipInfo_Node* LocateIDbyDrawLevel(int object_id, int level_a, int level_b, int node_type);
};

DClipInfo_Node* DClipInfo_List::LocateIDbyDrawLevel(int object_id, int level_a, int level_b, int node_type)
{
    if (level_a > level_b) {
        int temp = level_a;
        level_a = level_b;
        level_b = temp;
    }

    if (level_a < 0) {
        level_a = 0;
    }

    int max_levels = this->Max_Draw_Levels;
    if (level_b > max_levels) {
        level_b = max_levels;
    }

    if (level_a <= max_levels && level_b >= 0 && level_a <= level_b) {
        DClipInfo_Node** head_ptr = this->Draw_Level_Head + level_a;
        int level = level_a;
        do {
            DClipInfo_Node* node = *head_ptr;
            while (node) {
                if (node->Object_ID == object_id && node->Node_Type == node_type) {
                    return node;
                }
                node = node->NextOnLevel;
            }
            level++;
            head_ptr++;
        } while (level <= level_b);
    }

    return 0;
}

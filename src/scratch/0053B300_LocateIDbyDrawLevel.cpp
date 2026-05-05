// VA: 0053B300 DClipInfo_List::LocateIDbyDrawLevel (103 B)
// PDB source: view.cpp lines 6800-6822
// Notes: 24.3% positional diff (25/103 bytes). All structural elements match
// (prologue, swap, clamp, validation, loop, inner walk, epilogue).
// Remaining diff: VC5 assigns level_a to edx instead of eax (original uses eax).
// This cascades: speculative `mov eax, edx` at swap point, `mov edx, eax`
// for loop counter positioned after param loads instead of before conditional jump.
// Tried: declaration order, variable naming (Ghida-style), pointer walk vs indexed
// access, do-while vs for, temp variable styles. None fix eax/edx swap.

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
    int low = level_a;
    int high = level_b;

    if (low > high) {
        int temp = low;
        low = high;
        high = temp;
    }

    if (low < 0) {
        low = 0;
    }

    int max_levels = this->Max_Draw_Levels;
    if (high > max_levels) {
        high = max_levels;
    }

    if (low > max_levels || high < 0 || low > high) {
        return 0;
    }

    DClipInfo_Node** head_ptr = this->Draw_Level_Head + low;
    for (int level = low; level <= high; level++) {
        DClipInfo_Node* node = *head_ptr;
        while (node) {
            if (node->Object_ID == object_id && node->Node_Type == node_type) {
                return node;
            }
            node = node->NextOnLevel;
        }
        head_ptr++;
    }
    return 0;
}

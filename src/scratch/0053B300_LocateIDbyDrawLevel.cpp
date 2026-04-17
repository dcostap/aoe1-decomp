// STATUS: blocked
// BLOCKER: behavior matches, but VC5 keeps carrying the clamped minimum level in edx/eax opposite the original's eax/edx split, shifting the whole middle search loop register shape
// NOTE: bounds clamp and list walk are understood; remaining drift is register-choice/source-shape only

struct DClipInfo_Node {
    DClipInfo_Node* Next;
    DClipInfo_Node* NextOnLevel;
    int Object_ID;
    char gap_0C[0x20];
    int Node_Type;
};

class DClipInfo_List {
public:
    char gap_00[0x4C];
    int Max_Draw_Levels;
    char gap_50[0x08];
    DClipInfo_Node** Draw_Level_Head;

    DClipInfo_Node* LocateIDbyDrawLevel(int object_id, int min_level, int max_level, int node_type);
};

DClipInfo_Node* DClipInfo_List::LocateIDbyDrawLevel(int object_id, int min_level, int max_level, int node_type) {
    DClipInfo_Node** heads;
    DClipInfo_Node* node;
    int max_draw_levels;

    if (min_level > max_level) {
        int temp;

        temp = min_level;
        min_level = max_level;
        max_level = temp;
    }
    if (min_level < 0) {
        min_level = 0;
    }
    max_draw_levels = Max_Draw_Levels;
    if (max_level > max_draw_levels) {
        max_level = max_draw_levels;
    }
    if (min_level > max_draw_levels || max_level < 0) {
        return 0;
    }
    if (min_level > max_level) {
        return 0;
    }
    heads = Draw_Level_Head + min_level;
    do {
        for (node = *heads; node != 0; node = node->NextOnLevel) {
            if (node->Object_ID == object_id && node->Node_Type == node_type) {
                return node;
            }
        }
        min_level = min_level + 1;
        heads = heads + 1;
    } while (min_level <= max_level);
    return 0;
}

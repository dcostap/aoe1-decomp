// VA: 00539930 RGE_View::pick_touched_object
// Source: view.cpp lines 5477-5550
// Attempt log:
// initial natural nested bounds/level scan from packet.
//
// BINARY NOTE: PDB names this owner RGE_View::pick_touched_object.
// BINARY NOTE: The body is 00539930-00539A94. Padding follows to 00539AA0.
// BINARY NOTE: PDB order puts this normal sibling after 005396F0.
// BINARY NOTE: 005396B0 has no PDB function entry. Treat it as data.
// BINARY NOTE: Both direct calls target the protected RGE_View::sprite_check.
// BINARY NOTE: The out-of-line 00539510 definition remains the canonical owner.
//
// Exact-finish note:
// The natural source matches 357 bytes and 109 instructions.
// Removing the x2 local changed 202 bytes and reduced the body to 353 bytes.
// The x2 local is required for the original load and register schedule.

struct Shape_Info;

struct DClipInfo_Node {
    DClipInfo_Node* Next;        // +0x00
    DClipInfo_Node* NextOnLevel; // +0x04
    int Object_ID;               // +0x08
    Shape_Info* Shape;           // +0x0C
    int Draw_Level;              // +0x10
    int Draw_X;                  // +0x14
    int Draw_Y;                  // +0x18
    int Draw_Flag;               // +0x1C
    unsigned char* Shape_Base;   // +0x20
    unsigned char* Color_Table;  // +0x24
    int Xform_Mask;              // +0x28
    int Node_Type;               // +0x2C
    short x1;                    // +0x30
    short y1;                    // +0x32
    short x2;                    // +0x34
    short y2;                    // +0x36
    short x3;                    // +0x38
    short y3;                    // +0x3A
    short x4;                    // +0x3C
    short y4;                    // +0x3E
};

class DClipInfo_List {
public:
    char gap_00[0x5C];
    DClipInfo_Node** Draw_Level_Head; // +0x5C
};

class RGE_View {
public:
    char gap_00[0x8C];
    int x_min; // +0x8C
    int y_min; // +0x90
    int x_max; // +0x94
    int y_max; // +0x98

    int sprite_check(unsigned char* shape_base, Shape_Info* shape, int x, int y);
    int pick_touched_object(DClipInfo_List* list, int x, int y, int min_level, int max_level, int* out_object_id);
};

int RGE_View::pick_touched_object(DClipInfo_List* list, int x, int y, int min_level, int max_level, int* out_object_id)
{
    *out_object_id = 0;
    if (max_level >= min_level &&
        x >= this->x_min && x <= this->x_max &&
        y >= this->y_min && y <= this->y_max &&
        min_level <= 0x28 && max_level >= 0) {
        if (min_level < 0) {
            min_level = 0;
        }
        if (max_level > 0x28) {
            max_level = 0x28;
        }
        int found = 0;
        int level = max_level;
        if (level >= min_level) {
            do {
                DClipInfo_Node* node = list->Draw_Level_Head[level];
                if (node != 0) {
                    do {
                        if (node->Node_Type == 0) {
                            int flags = node->Draw_Flag;
                            int x1 = node->x1;
                            int y1 = node->y1;
                            int x2 = node->x2;
                            if ((flags & 2) == 2) {
                                if (this->sprite_check(node->Shape_Base, node->Shape, x2 - x, y - y1) == 2) {
                                    found = 1;
                                    *out_object_id = node->Object_ID;
                                }
                            } else {
                                if (this->sprite_check(node->Shape_Base, node->Shape, x - x1, y - y1) == 2) {
                                    found = 1;
                                    *out_object_id = node->Object_ID;
                                }
                            }
                        }
                        node = node->NextOnLevel;
                    } while (node != 0);
                }
                if (found == 1) {
                    return 1;
                }
                level--;
            } while (level >= min_level);
        }
    }
    return 0;
}

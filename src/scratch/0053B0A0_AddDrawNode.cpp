// VA: 0053B0A0 DClipInfo_List::AddDrawNode
// PDB: view.cpp:6652-6736
// attempt 1: direct reconstruction from original asm/decompiler; behavior close but register allocation differs (shape/x swapped) and yline store delayed.
// attempt 2: use parameter slot for yline and compute bounds/hotspots in original source order; improved shape/x allocation but yline store still delayed and hotspot loads early.
// attempt 3: use compound yline += member spelling; no codegen change.
// attempt 4: delaying hotspot calculations worsened prologue/register allocation; rolled back.
// attempt 5: force yline parameter stack-slot store through cast assignment; no change.
// attempt 6: volatile yline sum forced original yline add/store schedule; kept.
// attempt 7: combine clipping predicates made no codegen change.
// attempt 8: split width/height temps before hotspot expressions; no codegen change.
// attempt 9: /Ob0 made no codegen change; /O1 produced a too-small 358-byte .text and was discarded.
// probe 10: inline visible bounds expressions — 343-byte diff; rolled back.
// probe 11: remove the cached Select_Box pointer so each member access reloads the field.
// probe 12: remove width/height temporaries but retain named right/bottom bounds.
// probe 13: split bound/hotspot declarations from assignments in original source order.
// probe 14: remove redundant Shape_Info* local — 387-byte output; rolled back.
// probe 15: short hotspot accumulators — 383-byte output; rolled back.
// probe 16: move the two natural null link stores before scalar node-field stores.
// probe 17: reverse bound/hotspot assignment order — 340-byte output; rolled back.
// probe 18: six-way variant lab over bound/hotspot statement order; no exact result,
// best emitted code unchanged at 38 positional bytes / 97.50% shape.
// probe 19: declaration initializers for bound and hotspot locals; codegen duplicate.
// probe 20: natural while traversal for the linked-node tail; codegen duplicate.
// probe 21: decompiler-supported for-loop update form for the same traversal; duplicate.
// probe 22: restored canonical Shape_Info long-field ownership; codegen duplicate.
// probe 23: reordered natural bound/hotspot local declarations to follow the original
// width/right/hotspot/bottom liveness schedule; emitted code was unchanged and rolled back.
// probe 24: direct Draw_Clip_Nodes[yline] indexing in the natural allocation/link path;
// emitted code was unchanged and rolled back.
// left in scratch: canonical typed source is validated at 379 bytes with exact
// call set/boundary. Null-link stores before scalar fields and direct Select_Box
// rereads reproduce the long tail; remaining drift is the localized width/height
// versus hotspot load order at +0037..+0057. The lab's best order did not improve it.

struct Shape_Info {
    unsigned long Shape_Data_Offsets; // +0x00
    unsigned long Shape_Outline_Offset; // +0x04
    long Reserved1; // +0x08
    long Reserved2; // +0x0C
    long Width;      // +0x10
    long Height;     // +0x14
    long Hotspot_X;  // +0x18
    long Hotspot_Y;  // +0x1C
};

struct DClipInfo_Node {
    DClipInfo_Node* Next;        // +0x00
    DClipInfo_Node* NextOnLevel; // +0x04
    int Object_ID;               // +0x08
    Shape_Info* Shape;           // +0x0C
    int Draw_Level;              // +0x10
    int Draw_X;                  // +0x14
    int Draw_Y;                  // +0x18
    int Draw_Flag;               // +0x1C
    void* Shape_Base;            // +0x20
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
    char gap_00[0x3C];
    int SD_XMin;                 // +0x3C
    int SD_XMax;                 // +0x40
    int SD_YMin;                 // +0x44
    int SD_YMax;                 // +0x48
    char gap_4C[0x50 - 0x4C];
    int Accept_Min_Level;        // +0x50
    int Accept_Max_Level;        // +0x54
    DClipInfo_Node** Draw_Clip_Nodes; // +0x58
    char gap_5C[0x64 - 0x5C];
    int YLine_Offset;            // +0x64
    int YLine_Size;              // +0x68
    short* Select_Box;           // +0x6C

    DClipInfo_Node* GetNode();
    void AddDrawNode(void* shape_base, Shape_Info* shape, int yline, int draw_x, int draw_y,
                     int draw_flag, unsigned char* color_table, int xform_mask,
                     int draw_level, int object_id);
};

void DClipInfo_List::AddDrawNode(void* shape_base, Shape_Info* shape, int yline, int draw_x, int draw_y,
                                 int draw_flag, unsigned char* color_table, int xform_mask,
                                 int draw_level, int object_id)
{
    volatile int yline_tmp = this->YLine_Offset + yline;
    yline = yline_tmp;

    if (draw_level > this->Accept_Max_Level)
        return;
    if (draw_level < this->Accept_Min_Level)
        return;

    Shape_Info* shp = shape;
    int right;
    int bottom;
    int hot_x;
    int hot_y;
    right = draw_x + shp->Width - 1;
    bottom = draw_y + shp->Height - 1;
    hot_x = draw_x + shp->Hotspot_X;
    hot_y = draw_y + shp->Hotspot_Y;

    if (!(draw_x <= this->SD_XMax && right >= this->SD_XMin &&
          draw_y <= this->SD_YMax && bottom >= this->SD_YMin &&
          yline >= 0 && yline < this->YLine_Size))
        return;

    DClipInfo_Node* node = this->GetNode();
    DClipInfo_Node** list = this->Draw_Clip_Nodes + yline;
    DClipInfo_Node* cur = *list;
    if (cur == 0) {
        *list = node;
    } else {
        DClipInfo_Node* next = cur->Next;
        if (next != 0) {
            do {
                cur = next;
                next = cur->Next;
            } while (next != 0);
        }
        cur->Next = node;
    }

    node->Next = 0;
    node->NextOnLevel = 0;
    node->Object_ID = object_id;
    node->Draw_Flag = draw_flag;
    node->Shape_Base = shape_base;
    node->Color_Table = color_table;
    node->Xform_Mask = xform_mask;
    node->Shape = shp;
    node->Draw_X = draw_x;
    node->Draw_Y = draw_y;
    node->Draw_Level = draw_level;
    node->Node_Type = 0;

    if (this->Select_Box != 0) {
        node->x1 = (short)(hot_x + this->Select_Box[0]);
        node->y1 = (short)(this->Select_Box[1] + hot_y);
        node->x2 = (short)(this->Select_Box[2] + hot_x);
        node->y2 = (short)(this->Select_Box[3] + hot_y);
        this->Select_Box = 0;
    } else {
        node->x1 = (short)draw_x;
        node->y1 = (short)draw_y;
        node->x2 = (short)(draw_x + shp->Width - 1);
        node->y2 = (short)(draw_y + shp->Height - 1);
    }

    node->x3 = (short)hot_x;
    node->y3 = (short)hot_y;
    node->x4 = 0;
    node->y4 = 0;
}

// 004BDEA0 TSpan_List_Manager::AddShape
// Source: spanlist.cpp:827-893
//
// Attempt log:
// - Replaced the placeholder with the natural TShape/Shape_Info outline walk;
//   the two arms preserve the original non-mirrored and mirrored edge order.
// - Splitting or early-returning the two null guards was codegen-identical.
// - Pointing a local Shape_Info directly at the selected record improved the
//   emitted topology (192 strict bytes, 85.98% shape similarity) while keeping
//   the canonical named layout; this is the retained reconstruction.
// - A base shape_info array local, an explicit height local, a line-based
//   initial bound, and a packed long edge cursor were tested and either
//   duplicated the weaker basin or made the body structurally worse.
// - Unresolved: original keeps the shape-number/index and selected-record
//   register topology differently, uses two 16-bit cursor advances, and loads
//   height/y before the mirror join. Calls, frame, size, and CFG are aligned;
//   no exact source-shape lead remains in this bounded pass.
// - A fresh direct shape_info base-array/indexed reconstruction lost the
//   selected-record prologue and worsened the block basin; restored this source.

// Main-agent audit confirmed typed selected-record ownership and retained the
// natural shape insertion path.
struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

struct Shape_File_Header_Data {
    char Version[4];
    long Num_Shapes;
    char Comment[24];
};

struct Shape_Header;
struct Shape_File_Header;
struct Shape_Offsets;

class TShape {
public:
    unsigned char* shape;             // +0x00
    int load_type;                    // +0x04
    int load_size;                    // +0x08
    Shape_Header* shape_header;       // +0x0C
    Shape_File_Header* head;          // +0x10
    Shape_Offsets* offsets;           // +0x14
    Shape_File_Header_Data* FShape;   // +0x18
    Shape_Info* shape_info;           // +0x1C
};

struct VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;       // +0x00
    int* Zone_Size_Ptrs;          // +0x04
    int Used_Zones;               // +0x08
    int Max_Zones;                // +0x0C
    VSpan_Node* Free_Head;        // +0x10
    int Free_Pool_Zone;           // +0x14
    int Free_Pool_Index;          // +0x18
    int Total_Blocks;             // +0x1C
    int Free_Blocks;              // +0x20
    int Default_Grow_Size;        // +0x24
    int Element_Size;             // +0x28
    int Alloc_Count;              // +0x2C
    int Dealloc_Count;            // +0x30
    int NewZone_Count;            // +0x34
    int Reset_Count;              // +0x38
};

class TSpan_List_Manager : public TSpan_Node_List {
public:
    VSpan_Node** Line_Head_Ptrs;  // +0x3C
    VSpan_Node** Line_Tail_Ptrs;  // +0x40
    int* LeftMostPx;              // +0x44
    int* RightMostPx;             // +0x48
    int* Span_Count;              // +0x4C
    int Num_Lines;                // +0x50
    int Num_Pixels;               // +0x54
    int Min_Span_Px;              // +0x58
    int Max_Span_Px;              // +0x5C
    int Min_Line;                 // +0x60
    int Max_Line;                 // +0x64

    void AddSpan(int start, int end, int line);
    void AddShape(TShape* shape, int shape_number, int x, int y, int mirror);
};

void TSpan_List_Manager::AddShape(TShape* shape, int shape_number,
                                  int x, int y, int mirror)
{
    if (shape != 0 && shape->FShape != 0) {
        Shape_Info* info = &shape->shape_info[shape_number];
        unsigned short* outline =
            (unsigned short*)(shape->FShape->Version +
                              info->Shape_Outline_Offset);
        int right = info->Width - 1 + x;

        if (mirror == 0) {
            int line = y;
            if (y < y + info->Height) {
                do {
                    unsigned short start = outline[0];
                    unsigned short end = outline[1];
                    outline++;
                    outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line
                        && (start & 0x8000) == 0) {
                        AddSpan((short)start + x, right - (short)end, line);
                    }
                    line++;
                } while (line < y + info->Height);
                return;
            }
        } else {
            int line = y;
            if (y < y + info->Height) {
                do {
                    unsigned short start = outline[0];
                    unsigned short end = outline[1];
                    outline++;
                    outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line
                        && (end & 0x8000) == 0) {
                        AddSpan((short)end + x, right - (short)start, line);
                    }
                    line++;
                } while (line < y + info->Height);
            }
        }
    }
}

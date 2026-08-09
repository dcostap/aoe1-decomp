// 004BDFA0 TSpan_List_Manager::AddShape_Align
// Source: spanlist.cpp:900-953
//
// Attempt log:
// - Reconstructed the Shape_Info outline walk from the original two loop arms;
//   the non-aligned flag selects which 16-bit edge is the start/end value.
// - Baseline had exact size/frame/call set but colored this/outline oppositely;
//   two separate cursor increments moved the allocation to the original
//   edi=this, esi=outline basin.
// - Spelling the lower clip test as line >= Min_Line matched the original
//   register-memory compare; the remaining drift is block scheduling and the
//   original split cursor-add/pre-branch load order.
// - Full TSpan_Node_List/manager layout, pointer-local variants, C-style
//   temporary declarations, and explicit byte advances were codegen duplicates;
//   no source model reached exactness within the ten-hypothesis budget.
// - A shared named y+Height limit changed the natural loop topology and shrank
//   the output by 24 bytes; restored the clean source.
// - A volatile outline pointer was a codegen duplicate and is not retained;
//   the two observed add-2 cursor instructions remain unexplained.

// Main-agent audit confirmed typed shape/span ownership and retained the natural
// aligned outline traversal.
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

struct VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    VSpan_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;
};

class TSpan_List_Manager : public TSpan_Node_List {
public:
    VSpan_Node** Line_Head_Ptrs;
    VSpan_Node** Line_Tail_Ptrs;
    int* LeftMostPx;
    int* RightMostPx;
    int* Span_Count;
    int Num_Lines;
    int Num_Pixels;
    int Min_Span_Px;
    int Max_Span_Px;
    int Min_Line;
    int Max_Line;

    void AddSpan(int start, int end, int line);
    void AddShape_Align(unsigned char* data, Shape_Info* shape,
                        int x, int y, int align);
};

void TSpan_List_Manager::AddShape_Align(unsigned char* data, Shape_Info* shape,
                                        int x, int y, int align)
{
    if (shape != 0) {
        unsigned short* outline;
        int right;
        int line;
        unsigned short start;
        unsigned short end;
        outline = (unsigned short*)(data + shape->Shape_Outline_Offset);
        right = shape->Width - 1 + x;

        if (align == 0) {
            line = y;
            if (y < y + shape->Height) {
                do {
                    start = *outline;
                    end = outline[1];
                    outline += 1;
                    outline += 1;
                    if (line >= this->Min_Line && line <= this->Max_Line
                        && (start & 0x8000) == 0) {
                        AddSpan((short)start + x & 0xfffffffc,
                                right - (short)end | 3, line);
                    }
                    line++;
                } while (line < y + shape->Height);
                return;
            }
        } else {
            line = y;
            if (y < y + shape->Height) {
                do {
                    start = *outline;
                    end = outline[1];
                    outline += 1;
                    outline += 1;
                    if (line >= this->Min_Line && line <= this->Max_Line
                        && (end & 0x8000) == 0) {
                        AddSpan((short)end + x & 0xfffffffc,
                                right - (short)start | 3, line);
                    }
                    line++;
                } while (line < y + shape->Height);
            }
        }
    }
}

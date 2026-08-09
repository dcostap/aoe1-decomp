// 004BE4B0 TSpan_List_Manager::DeleteShape
// Source: spanlist.cpp:1352-1402
//
// Baseline reconstruction follows the neighboring AddShape_Align source shape:
// a Shape_Info row-outline cursor, a right-edge local, and two explicit loop
// arms for the mirrored/non-mirrored edge ordering.
// Attempt log:
// - Baseline natural TShape/Shape_Info reconstruction: 219-byte output, 172
//   strict differing bytes; both DeleteSpan call targets and the saved-register
//   frame were correct, but the branch setup was 25 bytes short.
// - Sharing the line cursor, using an adjacent outline pointer, reversing the
//   commutative start expression, and moving edge temporaries to function scope
//   were codegen duplicates.
// - Post-incrementing each 16-bit outline edge reproduced the binary's two
//   `add esi,2` instructions. This is retained: 229-byte output, 167 strict
//   differing bytes, with both call sites still aligned.
// - Reversing the mirror arm order changed the branch to `je` and worsened
//   resynchronization; restored the natural zero/nonzero if/else.
// - Remaining structural gap is localized to height-limit scheduling before
//   the mirror branch and call/loop register coloring; no further source axis
//   was justified within this assignment. Left in scratch.
// - Main-agent audit corrected the local shape-file-header ownership name;
//   emitted code is unchanged.

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
    unsigned char* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    Shape_File_Header_Data* FShape;
    Shape_Info* shape_info;
};

class TSpan_List_Manager {
public:
    void DeleteSpan(int start, int end, int line);
    void DeleteShape(TShape* shape, int shape_number, int x, int y, int mirror);
};

void TSpan_List_Manager::DeleteShape(TShape* shape, int shape_number,
                                      int x, int y, int mirror)
{
    if (shape != 0 && shape->FShape != 0) {
        Shape_Info* info;
        unsigned short* outline;
        int right;
        int line;
        unsigned short start;
        unsigned short end;

        info = &shape->shape_info[shape_number];
        outline =
            (unsigned short*)(shape->FShape->Version + info->Shape_Outline_Offset);
        right = info->Width - 1 + x;

        if (mirror == 0) {
            line = y;
            if (y < y + info->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if ((start & 0x8000) == 0) {
                        DeleteSpan(x + (short)start, right - (short)end, line);
                    }
                    line++;
                } while (line < y + info->Height);
                return;
            }
        } else {
            line = y;
            if (y < y + info->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if ((end & 0x8000) == 0) {
                        DeleteSpan(x + (short)end, right - (short)start, line);
                    }
                    line++;
                } while (line < y + info->Height);
            }
        }
    }
}

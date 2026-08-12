// 0053B370 DClipInfo_List::Scroll
// view.cpp:6829-6898, 261 bytes
//
// void __thiscall DClipInfo_List::Scroll(int scroll_x, int scroll_y)
// - ret 8 cleanup (2 stack params + this in ecx)
//
// === Attempt log ===
// 1: Natural loop structure (for i=0..remaining-1) — 90.4% pos diff
//    scroll_y→ebx (+callee-save prologue push) vs original scroll_y→edx (no push)
//    Loop register cascade throughout all phases
// 2: Local copies (cx/cy) — same result
// 3: Post-increment loop structure to match original — 93.1% pos diff, worse
//    Compiler generated extra xor ebp,ebp for NULL constant
// 4: Reconstructed original do/while/index topology — 176-byte diff, 90.2% shape.
// 5: Reordered positive locals and named reverse source index — 217-byte diff; rolled back.
// 6: Positive remaining local is initialized before the index — 221-byte diff; rolled back.
// 7: Reverse source index scoped to the guarded copy loop — 284-byte output; rolled back.
// 8: Reverse source index live across the negative guard — 284-byte output; rolled back.
// 9: Named reverse-copy value — 284-byte output and register cascade; rolled back.
// 10: Moved the first positive-loop i=0 before YLine_Size-scroll_y and reused i — 166-byte diff, recovering the early xor eax and two exact blocks; remaining drift starts in the negative-loop index setup.
// BLOCKER: TU-context register allocation cascade (scroll_y in ebx vs edx)
// Best retained source: typed same-TU DClipInfo layout with direct member arrays,
// natural do/while copies, and switch fall-through; 166-byte diff, 92.16% shape,
// exact original boundary. The positive-loop init now matches the early xor and
// remaining drift starts at negative-loop index setup and reverse-copy addressing.
// Full view.cpp context or a stronger source donor is the
// next lead; source-index locals add 23 bytes past the original boundary.

struct DClipInfo_Node {
    DClipInfo_Node* Next;        // +0x00
    DClipInfo_Node* NextOnLevel; // +0x04
    int Object_ID;               // +0x08
    void* Shape;                 // +0x0C
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
    DClipInfo_Node** Zone_Ptrs;       // +0x00
    int* Zone_Size_Ptrs;              // +0x04
    int Used_Zones;                   // +0x08
    int Max_Zones;                    // +0x0C
    char gap_10[0x40];                // +0x10 to +0x4F
    int Accept_Min_Level;             // +0x50
    int Accept_Max_Level;             // +0x54
    DClipInfo_Node** Draw_Clip_Nodes; // +0x58
    DClipInfo_Node** Draw_Level_Head; // +0x5C
    DClipInfo_Node** Draw_Level_Tail; // +0x60
    int YLine_Offset;                 // +0x64
    int YLine_Size;                   // +0x68
    short* Select_Box;                // +0x6C

    void Scroll(int scroll_x, int scroll_y);
};

void DClipInfo_List::Scroll(int scroll_x, int scroll_y)
{
    if (scroll_y > 0) {
        int i = 0;
        if (this->YLine_Size - scroll_y > 0) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + scroll_y];
                i = next;
            } while (i < this->YLine_Size - scroll_y);
        }

        i = this->YLine_Size - scroll_y;
        if (i < this->YLine_Size) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = 0;
                i = next;
            } while (i < this->YLine_Size);
        }
    }

    if (scroll_y < 0) {
        int neg = -scroll_y;
        int i = this->YLine_Size - 1;

        if (i >= neg) {
            do {
                int next = i - 1;
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + scroll_y];
                i = next;
            } while (i >= neg);
        }

        i = 0;
        if (neg > 0) {
            do {
                int next = i + 1;
                this->Draw_Clip_Nodes[i] = 0;
                i = next;
            } while (i < neg);
        }
    }

    int i = 0;
    if (this->YLine_Size > 0) {
        do {
            DClipInfo_Node* node = this->Draw_Clip_Nodes[i];

            while (node != 0) {
                switch (node->Node_Type) {
                case 0:
                    node->Draw_X -= scroll_x;
                    node->Draw_Y -= scroll_y;
                    break;

                case 1:
                    node->y3 -= (short)scroll_y;
                    node->y4 -= (short)scroll_y;

                case 2:
                    node->x3 -= (short)scroll_x;
                    node->x4 -= (short)scroll_x;

                case 3:
                case 4:
                    node->x1 -= (short)scroll_x;
                    node->y1 -= (short)scroll_y;
                    node->x2 -= (short)scroll_x;
                    node->y2 -= (short)scroll_y;
                    break;
                }

                node = node->Next;
            }

            i = i + 1;
        } while (i < this->YLine_Size);
    }
}

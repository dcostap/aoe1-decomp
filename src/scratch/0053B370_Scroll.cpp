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
// BLOCKER: TU-context register allocation cascade (scroll_y in ebx vs edx)
// Same class as other view.cpp functions — full TU context needed for register match

struct DClipInfo_Node {
    DClipInfo_Node* Next;         // +0x00
    char gap_04[0x10];            // +0x04 to +0x13
    int Draw_X;                   // +0x14
    int Draw_Y;                   // +0x18
    char gap_1C[0x10];            // +0x1C to +0x2B
    int Node_Type;                // +0x2C
    short x1;                     // +0x30
    short y1;                     // +0x32
    short x2;                     // +0x34
    short y2;                     // +0x36
    short x3;                     // +0x38
    short y3;                     // +0x3A
    short x4;                     // +0x3C
    short y4;                     // +0x3E
};

class DClipInfo_List {
public:
    char gap_00[0x58];            // +0x00 to +0x57
    DClipInfo_Node** Draw_Clip_Nodes;  // +0x58
    char gap_5C[0x0C];            // +0x5C to +0x67
    int YLine_Size;               // +0x68

    void Scroll(int scroll_x, int scroll_y);
};

void DClipInfo_List::Scroll(int scroll_x, int scroll_y)
{
    // === PHASE 1: scroll_y > 0 (scrolling down) ===
    if (scroll_y > 0) {
        int remaining = this->YLine_Size - scroll_y;

        if (remaining > 0) {
            for (int i = 0; i < remaining; i++) {
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + scroll_y];
            }
        }

        if (remaining < this->YLine_Size) {
            for (int i = remaining; i < this->YLine_Size; i++) {
                this->Draw_Clip_Nodes[i] = 0;
            }
        }
    }

    // === PHASE 2: scroll_y < 0 (scrolling up) ===
    if (scroll_y < 0) {
        int neg = -scroll_y;
        int last = this->YLine_Size - 1;

        if (last >= neg) {
            for (int i = last; i >= neg; i--) {
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + scroll_y];
            }
        }

        if (neg > 0) {
            for (int i = 0; i < neg; i++) {
                this->Draw_Clip_Nodes[i] = 0;
            }
        }
    }

    // === PHASE 3: Walk all clip nodes and adjust coordinates ===
    for (int i = 0; i < this->YLine_Size; i++) {
        DClipInfo_Node* node = this->Draw_Clip_Nodes[i];

        while (node != 0) {
            switch (node->Node_Type) {
            case 0:
                // Type 0: full int coordinate adjustment (NO fall-through)
                node->Draw_X -= scroll_x;
                node->Draw_Y -= scroll_y;
                break;

            case 1:
                // Type 1: short y3/y4 adjustment (falls through to type 2/3)
                node->y3 -= (short)scroll_y;
                node->y4 -= (short)scroll_y;

            case 2:
                // Type 2: short x3/x4 adjustment (falls through to type 3)
                node->x3 -= (short)scroll_x;
                node->x4 -= (short)scroll_x;

            case 3:
            case 4:
                // Type 3/4: short x1/y1/x2/y2 adjustment
                node->x1 -= (short)scroll_x;
                node->y1 -= (short)scroll_y;
                node->x2 -= (short)scroll_x;
                node->y2 -= (short)scroll_y;
                break;
            }

            node = node->Next;
        }
    }
}

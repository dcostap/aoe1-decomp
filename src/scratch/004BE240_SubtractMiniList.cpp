// VA: 004BE240 TSpan_List_Manager::SubtractMiniList (71B)
// PDB source: spanlist.cpp lines 1164-1179
// tried the direct 3-byte mini-span walk with exact DeleteSpan arg order, local offset copies, and a `for(;;)`/return form
// best result keeps the body/call sequence right, but VC5 still chooses a different loop-top basin: it hoists `xor eax,eax; mov al,[esi]; cmp eax,0FFh` before loading x_off/y_off into ebx/edi, then emits a post-call zero/sentinel recheck instead of the original `add esi,3 ; jne loop`

class VSpanMiniList {
public:
    unsigned char Y_delta;
    unsigned char X_start;
    unsigned char X_end;
};

class TSpan_List_Manager {
public:
    char gap_00[0x3C];
    int* Line_Head_Ptrs;
    int* Line_Tail_Ptrs;
    int* LeftMostPx;
    int* RightMostPx;
    int* Span_Count;
    int Num_Lines;
    int Num_Pixels;
    int Min_Span_Px;
    int Max_Span_Px;
    int Min_Line;
    int Max_Line;

    void DeleteSpan(int x_start, int x_end, int y_delta);
    void SubtractMiniList(VSpanMiniList* mini, int x_off, int y_off);
};

void TSpan_List_Manager::SubtractMiniList(VSpanMiniList* mini, int x_off, int y_off) {
    int add_x;
    int add_y;

    if (mini == 0) {
        return;
    }
    add_x = x_off;
    add_y = y_off;
    for (;;) {
        int y_delta;

        y_delta = mini->Y_delta;
        if (y_delta == 0xFF) {
            return;
        }
        this->DeleteSpan((int)mini->X_start + add_x, (int)mini->X_end + add_x, y_delta + add_y);
        mini = (VSpanMiniList*)((char*)mini + 3);
        if (mini == 0) {
            return;
        }
    }
}

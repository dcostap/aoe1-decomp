// VA: 004BE240 TSpan_List_Manager::SubtractMiniList (71B)
// PDB source: spanlist.cpp lines 1164-1179
// Match note: variant_lab showed VC5 wants the natural `while (mini != 0)` form,
// with x/y offsets copied to locals before the loop and the 3-byte mini-span
// pointer advance left as the last statement in the loop body.

#ifndef SPANLIST_SHARED_CONTEXT
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
#endif

void TSpan_List_Manager::SubtractMiniList(VSpanMiniList* mini, int x_off, int y_off) {
    if (mini == 0) {
        return;
    }

    int add_x = x_off;
    int add_y = y_off;

    while (mini != 0) {
        int y_delta = mini->Y_delta;

        if (y_delta == 0xFF) {
            return;
        }

        this->DeleteSpan((int)mini->X_start + add_x,
            (int)mini->X_end + add_x,
            y_delta + add_y);

        mini = (VSpanMiniList*)((char*)mini + 3);
    }
}

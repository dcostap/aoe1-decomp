// attempt log:
// started with the direct 3-byte mini-span walk and exact DeleteSpan argument order; that got close but not exact
// tried copying the offsets into locals before the loop, then tried a plain int Y_delta local; the remaining mismatch stayed on the loop prologue / first byte-load basin
// left in scratch because the logic is right but VC5 keeps choosing a different early-load/register order
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
    if (mini == 0) {
        return;
    }
    int add_x = x_off;
    int add_y = y_off;
    do {
        int y_delta = mini->Y_delta;
        if (y_delta == 0xff) {
            return;
        }
        this->DeleteSpan((int)mini->X_start + add_x, (int)mini->X_end + add_x, y_delta + add_y);
        mini = mini + 1;
    } while (mini != 0);
}

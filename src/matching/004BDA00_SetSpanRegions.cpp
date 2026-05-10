// 004BDA00 TSpan_List_Manager::SetSpanRegions (spanlist.cpp:371-400, 105B)
// MATCH: natural in-place parameter swaps (temp + mutating param_1/3 and
// param_2/4) prevent VC5 from pre-loading param_3 before callee-save pushes.
// The earlier decompiler-style iVar2/iVar3 locals had correct behavior but
// forced broad register-allocation drift.

class TSpan_List_Manager {
public:
    char gap_00[0x50];
    int Num_Lines;   // +0x50
    int Num_Pixels;  // +0x54
    int Min_Span_Px; // +0x58
    int Max_Span_Px; // +0x5C
    int Min_Line;    // +0x60
    int Max_Line;    // +0x64

    void SetSpanRegions(int param_1, int param_2, int param_3, int param_4);
};

void TSpan_List_Manager::SetSpanRegions(int param_1, int param_2, int param_3, int param_4) {
    int temp;

    if (param_1 > param_3) {
        temp = param_1;
        param_1 = param_3;
        param_3 = temp;
    }

    if (param_2 > param_4) {
        temp = param_2;
        param_2 = param_4;
        param_4 = temp;
    }

    if (param_2 < 0) {
        param_2 = 0;
    }
    if (param_4 < 0) {
        return;
    }

    temp = this->Num_Lines;
    if (param_2 >= temp) {
        return;
    }
    if (param_4 >= temp) {
        param_4 = temp - 1;
    }

    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_3 < 0) {
        return;
    }

    temp = this->Num_Pixels;
    if (param_1 >= temp) {
        return;
    }
    if (param_3 >= temp) {
        param_3 = temp - 1;
    }

    this->Min_Line = param_2;
    this->Max_Line = param_4;
    this->Min_Span_Px = param_1;
    this->Max_Span_Px = param_3;
}

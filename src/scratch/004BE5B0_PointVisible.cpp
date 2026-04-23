// quick-win attempt: direct span walk with the exact line-head lookup and bounds checks
// tried the nested-branch and while-loop forms; remaining mismatch is still the early loop-exit branch shape
class VSpan_Node {
public:
    VSpan_Node* Next;
    int gap_04;
    int StartPx;
    int EndPx;
};

class TSpan_List_Manager {
public:
    char gap_00[0x3C];
    VSpan_Node** Line_Head_Ptrs;
    VSpan_Node** Line_Tail_Ptrs;
    int* LeftMostPx;
    int* RightMostPx;
    int* Span_Count;
    int Num_Lines;

    int PointVisible(int param_1, int param_2);
};

int TSpan_List_Manager::PointVisible(int param_1, int param_2) {
    VSpan_Node* pVVar1;

    if ((param_2 < 0) || (param_2 >= this->Num_Lines)) {
        return 0;
    }
    pVVar1 = this->Line_Head_Ptrs[param_2];
    if (pVVar1 == 0) {
        return 0;
    }
    while (1) {
        if (param_1 < pVVar1->StartPx) {
            pVVar1 = pVVar1->Next;
            if (pVVar1 == 0) {
                return 0;
            }
            continue;
        }
        if (param_1 > pVVar1->EndPx) {
            pVVar1 = pVVar1->Next;
            if (pVVar1 == 0) {
                return 0;
            }
            continue;
        }
        return 1;
    }
}

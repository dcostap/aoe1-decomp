// VA: 004BE5B0 TSpan_List_Manager::PointVisible (59B)
// PDB source: spanlist.cpp lines 1410-1426
// tried nested-branch, while-condition, and explicit if/return loop forms
// best shape gets the full compare chain and success path right; remaining drift is a 1-byte shorter early-zero block and VC5 still emits `je zero; jmp loop` instead of the original `jne loop; ret 8` null-tail shape after advancing Next

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
        if (param_1 >= pVVar1->StartPx) {
            if (param_1 <= pVVar1->EndPx) {
                return 1;
            }
        }
        pVVar1 = pVVar1->Next;
        if (pVVar1 == 0) {
            return 0;
        }
    }
}

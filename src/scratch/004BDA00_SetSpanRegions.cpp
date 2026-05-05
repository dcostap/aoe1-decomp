// 004BDA00 TSpan_List_Manager::SetSpanRegions (spanlist.cpp:371-400, 105B)
// 72/105 bytes (68.6%). VC5 pre-loads param_3 into eax before push instructions.
//
// Our VC5 schedules `iVar3 = param_3` as a pre-load (`mov eax, [esp+0Ch]`) before
// any pushes (ebx, esi, edi). The 1998 build loads it AFTER push ebx directly
// into ebx (`mov ebx, [esp+10h]`). This early-load cascade changes register
// allocation through the entire function: eax vs edx for the scratch register
// that holds Num_Lines/Num_Pixels, and edi vs eax/edx for min of second pair.
//
// All control flow, clamp logic, and field stores are structurally correct.
// Register allocation is the only difference.

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
    int iVar3;
    int iVar2;

    iVar3 = param_3;
    if (param_1 > param_3) {
        iVar3 = param_1;
        param_1 = param_3;
    }

    iVar2 = param_2;
    if (param_4 < param_2) {
        iVar2 = param_4;
        param_4 = param_2;
    }

    if (iVar2 < 0) {
        iVar2 = 0;
    }
    if (param_4 < 0) {
        return;
    }

    int iVar1 = this->Num_Lines;
    if (iVar2 >= iVar1) {
        return;
    }
    if (param_4 >= iVar1) {
        param_4 = iVar1 - 1;
    }

    if (param_1 < 0) {
        param_1 = 0;
    }
    if (iVar3 < 0) {
        return;
    }

    iVar1 = this->Num_Pixels;
    if (param_1 >= iVar1) {
        return;
    }
    if (iVar3 >= iVar1) {
        iVar3 = iVar1 - 1;
    }

    this->Min_Line = iVar2;
    this->Max_Line = param_4;
    this->Min_Span_Px = param_1;
    this->Max_Span_Px = iVar3;
}

// target: VA 004BDA00 TSpan_List_Manager::SetSpanRegions(int,int,int,int)
// first pass: mirror the packet's swap/normalize/clamp flow and keep the stores in the same order
// probe 1: the first build used a natural local layout but the argument loads/code shape were far from the packet
// probe 2: decompiler-shaped locals and nested guards should steer VC5 toward the ebx/esi/edi family
// probe 3: try the opposite compare spelling to mirror the packet's jle/jge polarity more directly
// blocker: VC5 is still choosing an early eax load / different saved-register basin; exact prolog shape and branch polarity are not yet aligned

class TSpan_List_Manager {
public:
    char gap_00[0x50];
    int Num_Lines;   // +0x50
    int Num_Pixels;  // +0x54
    int Min_Span_Px; // +0x58
    int Max_Span_Px; // +0x5C
    int Min_Line;    // +0x60
    int Max_Line;    // +0x64

    void SetSpanRegions(int firstLow, int firstHigh, int secondLow, int secondHigh);
};

void TSpan_List_Manager::SetSpanRegions(int param_1, int param_2, int param_3, int param_4) {
    int iVar1;
    int iVar2;
    int iVar3;

    iVar3 = param_3;
    if (param_1 > param_3) {
        iVar3 = param_1;
        param_1 = param_3;
    }

    iVar2 = param_2;
    if (param_2 > param_4) {
        iVar2 = param_4;
        param_4 = param_2;
    }

    if (iVar2 < 0) {
        iVar2 = 0;
    }
    if (param_4 < 0) {
        return;
    }

    iVar1 = this->Num_Lines;
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

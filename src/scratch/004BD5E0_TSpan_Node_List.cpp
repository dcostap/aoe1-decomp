// tried the direct member-by-member constructor; first mismatch stayed at the
// first argument load (param_1 came in early instead of the original -1 store)
// added neighbor method bodies in the same TU to mirror spanlist.cpp context
// and re-test whether TU context changes the register-allocation basin
#include <stdlib.h>

class VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    VSpan_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;

    TSpan_Node_List(int, int, int);
    ~TSpan_Node_List(void);
    void ResetStats(void);
    void SetNumZones(int);
    void InitNewZone(int);
};

TSpan_Node_List::TSpan_Node_List(int param_1, int param_2, int param_3) {
    this->Free_Pool_Zone = this->Free_Pool_Index = -1;
    this->Zone_Ptrs = 0;
    this->Zone_Size_Ptrs = 0;
    this->Used_Zones = 0;
    this->Free_Head = 0;
    this->Total_Blocks = 0;
    this->Free_Blocks = 0;
    this->Element_Size = param_3;
    this->Max_Zones = 8;
    this->Default_Grow_Size = param_2;
    this->ResetStats();
    this->SetNumZones(8);
    this->InitNewZone(param_1);
}

TSpan_Node_List::~TSpan_Node_List(void) {
    int i = 0;

    while (i < this->Used_Zones) {
        if (this->Zone_Ptrs[i] != 0) {
            free(this->Zone_Ptrs[i]);
        }
        i++;
    }

    if (this->Zone_Ptrs != 0) {
        free(this->Zone_Ptrs);
    }
    if (this->Zone_Size_Ptrs != 0) {
        free(this->Zone_Size_Ptrs);
    }
}

void TSpan_Node_List::SetNumZones(int param_1) {
    VSpan_Node **ppVVar1;
    int *piVar2;
    int iVar3;
    int iVar4;

    if (this->Max_Zones <= param_1) {
        ppVVar1 = (VSpan_Node **)calloc(param_1,4);
        piVar2 = (int *)calloc(param_1,4);
        if (this->Zone_Ptrs != (VSpan_Node **)0x0) {
            if (0 < this->Used_Zones) {
                iVar3 = 0;
                do {
                    iVar4 = iVar3 + 1;
                    *(VSpan_Node **)(((int)ppVVar1 - (int)piVar2) + (int)(piVar2 + iVar3)) =
                         this->Zone_Ptrs[iVar3];
                    piVar2[iVar3] = this->Zone_Size_Ptrs[iVar3];
                    iVar3 = iVar4;
                } while (iVar4 < this->Used_Zones);
            }
            free(this->Zone_Ptrs);
            free(this->Zone_Size_Ptrs);
        }
        this->Zone_Ptrs = ppVVar1;
        this->Zone_Size_Ptrs = piVar2;
        this->Max_Zones = param_1;
    }
}

void TSpan_Node_List::InitNewZone(int param_1) {
    int iVar1;
    int iVar2;
    VSpan_Node *pVVar3;

    if (this->Used_Zones == this->Max_Zones) {
        SetNumZones(this->Used_Zones + 4);
    }
    iVar1 = this->Used_Zones;
    this->Used_Zones = iVar1 + 1;
    iVar2 = this->Element_Size;
    this->Zone_Size_Ptrs[iVar1] = param_1;
    pVVar3 = (VSpan_Node *)malloc(iVar2 * param_1);
    this->Zone_Ptrs[iVar1] = pVVar3;
    this->NewZone_Count = this->NewZone_Count + 1;
    this->Total_Blocks = this->Total_Blocks + param_1;
    this->Free_Blocks = this->Free_Blocks + param_1;
    if (this->Free_Pool_Zone == -1) {
        this->Free_Pool_Zone = iVar1;
        this->Free_Pool_Index = 0;
    }
}

void TSpan_Node_List::ResetStats(void) {
    this->Alloc_Count = 0;
    this->Dealloc_Count = 0;
    this->NewZone_Count = 0;
    this->Reset_Count = 0;
}

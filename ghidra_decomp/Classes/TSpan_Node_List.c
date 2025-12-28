// Class: TSpan_Node_List
// Size:  0x3C
//
// Member Layout:
// [0x000] VSpan_Node * * Zone_Ptrs
// [0x004] int * Zone_Size_Ptrs
// [0x008] int Used_Zones
// [0x00C] int Max_Zones
// [0x010] VSpan_Node * Free_Head
// [0x014] int Free_Pool_Zone
// [0x018] int Free_Pool_Index
// [0x01C] int Total_Blocks
// [0x020] int Free_Blocks
// [0x024] int Default_Grow_Size
// [0x028] int Element_Size
// [0x02C] int Alloc_Count
// [0x030] int Dealloc_Count
// [0x034] int NewZone_Count
// [0x038] int Reset_Count
// ----------------------------------------------------------------

// Function: TSpan_Node_List
// Address: 004bd5e0
TSpan_Node_List * __thiscall
TSpan_Node_List::TSpan_Node_List(TSpan_Node_List *this,int param_1,int param_2,int param_3)
{
  this->Free_Pool_Zone = -1;
  this->Free_Pool_Index = -1;
  this->Zone_Ptrs = (VSpan_Node **)0x0;
  this->Zone_Size_Ptrs = (int *)0x0;
  this->Used_Zones = 0;
  this->Free_Head = (VSpan_Node *)0x0;
  this->Total_Blocks = 0;
  this->Free_Blocks = 0;
  this->Element_Size = param_3;
  this->Max_Zones = 8;
  this->Default_Grow_Size = param_2;
  ResetStats(this);
  SetNumZones(this,8);
  InitNewZone(this,param_1);
  return this;
}

// --------------------------------------------------

// Function: ~TSpan_Node_List
// Address: 004bd640
void __thiscall TSpan_Node_List::~TSpan_Node_List(TSpan_Node_List *this)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < this->Used_Zones) {
    do {
      if (this->Zone_Ptrs[iVar1] != (VSpan_Node *)0x0) {
        free(this->Zone_Ptrs[iVar1]);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->Used_Zones);
  }
  if (this->Zone_Ptrs != (VSpan_Node **)0x0) {
    free(this->Zone_Ptrs);
  }
  if (this->Zone_Size_Ptrs != (int *)0x0) {
    free(this->Zone_Size_Ptrs);
  }
  return;
}

// --------------------------------------------------

// Function: SetNumZones
// Address: 004bd690
void __thiscall TSpan_Node_List::SetNumZones(TSpan_Node_List *this,int param_1)
{
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
  return;
}

// --------------------------------------------------

// Function: InitNewZone
// Address: 004bd720
void __thiscall TSpan_Node_List::InitNewZone(TSpan_Node_List *this,int param_1)
{
  int iVar1;
  int iVar2;
  VSpan_Node *pVVar3;
  
  if (this->Used_Zones == this->Max_Zones) {
    SetNumZones(this,this->Used_Zones + 4);
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
  return;
}

// --------------------------------------------------

// Function: GetNode
// Address: 004bd790
VSpan_Node * __thiscall TSpan_Node_List::GetNode(TSpan_Node_List *this)
{
  VSpan_Node *pVVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (this->Free_Blocks == 0) {
    InitNewZone(this,this->Default_Grow_Size);
  }
  pVVar1 = this->Free_Head;
  if (pVVar1 != (VSpan_Node *)0x0) {
    this->Free_Head = pVVar1->Next;
    this->Free_Blocks = this->Free_Blocks + -1;
    return pVVar1;
  }
  iVar2 = this->Free_Pool_Index;
  iVar3 = this->Free_Pool_Zone;
  pVVar1 = this->Zone_Ptrs[iVar3];
  iVar4 = iVar2 + 1;
  this->Free_Blocks = this->Free_Blocks + -1;
  this->Free_Pool_Index = iVar4;
  if (iVar4 == this->Zone_Size_Ptrs[iVar3]) {
    this->Free_Pool_Zone = iVar3 + 1;
    this->Free_Pool_Index = 0;
    if (iVar3 + 1 == this->Used_Zones) {
      this->Free_Pool_Zone = -1;
    }
  }
  return pVVar1 + iVar2;
}

// --------------------------------------------------

// Function: FreeNode
// Address: 004bd800
void __thiscall TSpan_Node_List::FreeNode(TSpan_Node_List *this,VSpan_Node *param_1)
{
  param_1->Next = this->Free_Head;
  param_1->Prev = (VSpan_Node *)0x0;
  this->Free_Head = param_1;
  this->Free_Blocks = this->Free_Blocks + 1;
  return;
}

// --------------------------------------------------

// Function: FreeThread
// Address: 004bd820
int __thiscall
TSpan_Node_List::FreeThread(TSpan_Node_List *this,VSpan_Node *param_1,VSpan_Node *param_2)
{
  int iVar1;
  VSpan_Node *pVVar2;
  VSpan_Node *pVVar3;
  
  iVar1 = 0;
  if (param_1 == (VSpan_Node *)0x0) {
    return iVar1;
  }
  pVVar3 = param_1;
  if (param_2 == (VSpan_Node *)0x0) {
    do {
      pVVar2 = pVVar3;
      iVar1 = iVar1 + 1;
      this->Free_Blocks = this->Free_Blocks + 1;
      pVVar3 = pVVar2->Next;
    } while (pVVar3 != (VSpan_Node *)0x0);
    pVVar2->Next = this->Free_Head;
    this->Free_Head = param_1;
    return iVar1;
  }
  do {
    iVar1 = iVar1 + 1;
    this->Free_Blocks = this->Free_Blocks + 1;
    if (pVVar3 == param_2) {
      pVVar3 = (VSpan_Node *)0x0;
    }
    else {
      pVVar3 = pVVar3->Next;
    }
  } while (pVVar3 != (VSpan_Node *)0x0);
  param_2->Next = this->Free_Head;
  this->Free_Head = param_1;
  return iVar1;
}

// --------------------------------------------------

// Function: ReclaimAllNodes
// Address: 004bd880
void __thiscall TSpan_Node_List::ReclaimAllNodes(TSpan_Node_List *this)
{
  this->Free_Head = (VSpan_Node *)0x0;
  this->Free_Pool_Zone = 0;
  this->Free_Pool_Index = 0;
  this->Free_Blocks = this->Total_Blocks;
  this->Reset_Count = this->Reset_Count + 1;
  return;
}

// --------------------------------------------------

// Function: ResetStats
// Address: 004bd8a0
void __thiscall TSpan_Node_List::ResetStats(TSpan_Node_List *this)
{
  this->Alloc_Count = 0;
  this->Dealloc_Count = 0;
  this->NewZone_Count = 0;
  this->Reset_Count = 0;
  return;
}

// --------------------------------------------------


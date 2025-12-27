// Class: TSpan_List_Manager
// Function: TSpan_List_Manager
// Address: 004bd8b0
/* public: __thiscall TSpan_List_Manager::TSpan_List_Manager(int,int) */

TSpan_List_Manager * __thiscall
TSpan_List_Manager::TSpan_List_Manager(TSpan_List_Manager *this,int param_1,int param_2)
{
  VSpan_Node **ppVVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055f8d8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TSpan_Node_List::TSpan_Node_List
            (&this->VSList,((int)(param_1 + 0x1f + (param_1 + 0x1f >> 0x1f & 0x1fU)) >> 5) * param_2
             ,param_2 << 4,0x10);
  local_4 = 0;
  this->Num_Lines = param_2;
  if (param_2 < 0x10) {
    this->Num_Lines = 0x10;
  }
  this->Num_Pixels = param_1;
  if (param_1 < 0x10) {
    this->Num_Pixels = 0x10;
  }
  SetSpanRegions(this,0,0,this->Num_Pixels + -1,this->Num_Lines + -1);
  ppVVar1 = (VSpan_Node **)calloc(this->Num_Lines,4);
  this->Line_Head_Ptrs = ppVVar1;
  ppVVar1 = (VSpan_Node **)calloc(this->Num_Lines,4);
  this->Line_Tail_Ptrs = ppVVar1;
  piVar2 = (int *)calloc(this->Num_Lines,4);
  this->LeftMostPx = piVar2;
  piVar2 = (int *)calloc(this->Num_Lines,4);
  this->RightMostPx = piVar2;
  piVar2 = (int *)calloc(this->Num_Lines,4);
  this->Span_Count = piVar2;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~TSpan_List_Manager
// Address: 004bd9a0
/* public: __thiscall TSpan_List_Manager::~TSpan_List_Manager(void) */

void __thiscall TSpan_List_Manager::~TSpan_List_Manager(TSpan_List_Manager *this)
{
  if (this->Line_Head_Ptrs != (VSpan_Node **)0x0) {
    free(this->Line_Head_Ptrs);
  }
  if (this->Line_Tail_Ptrs != (VSpan_Node **)0x0) {
    free(this->Line_Tail_Ptrs);
  }
  if (this->LeftMostPx != (int *)0x0) {
    free(this->LeftMostPx);
  }
  if (this->RightMostPx != (int *)0x0) {
    free(this->RightMostPx);
  }
  if (this->Span_Count != (int *)0x0) {
    free(this->Span_Count);
  }
  TSpan_Node_List::~TSpan_Node_List(&this->VSList);
  return;
}

// --------------------------------------------------

// Function: SetSpanRegions
// Address: 004bda00
/* public: void __thiscall TSpan_List_Manager::SetSpanRegions(int,int,int,int) */

void __thiscall
TSpan_List_Manager::SetSpanRegions
          (TSpan_List_Manager *this,int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3;
  if (param_3 < param_1) {
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
  if ((-1 < param_4) && (iVar1 = this->Num_Lines, iVar2 < iVar1)) {
    if (iVar1 <= param_4) {
      param_4 = iVar1 + -1;
    }
    if (param_1 < 0) {
      param_1 = 0;
    }
    if ((-1 < iVar3) && (iVar1 = this->Num_Pixels, param_1 < iVar1)) {
      if (iVar1 <= iVar3) {
        iVar3 = iVar1 + -1;
      }
      this->Min_Line = iVar2;
      this->Max_Line = param_4;
      this->Min_Span_Px = param_1;
      this->Max_Span_Px = iVar3;
    }
  }
  return;
}

// --------------------------------------------------

// Function: ResetAll
// Address: 004bda70
/* public: void __thiscall TSpan_List_Manager::ResetAll(void) */

void __thiscall TSpan_List_Manager::ResetAll(TSpan_List_Manager *this)
{
  uint uVar1;
  int iVar2;
  VSpan_Node **ppVVar3;
  int *piVar4;
  
  TSpan_Node_List::ReclaimAllNodes(&this->VSList);
  ppVVar3 = this->Line_Head_Ptrs;
  for (uVar1 = this->Num_Lines & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *ppVVar3 = (VSpan_Node *)0x0;
    ppVVar3 = ppVVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)ppVVar3 = 0;
    ppVVar3 = (VSpan_Node **)((int)ppVVar3 + 1);
  }
  ppVVar3 = this->Line_Tail_Ptrs;
  for (uVar1 = this->Num_Lines & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *ppVVar3 = (VSpan_Node *)0x0;
    ppVVar3 = ppVVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)ppVVar3 = 0;
    ppVVar3 = (VSpan_Node **)((int)ppVVar3 + 1);
  }
  piVar4 = this->LeftMostPx;
  for (uVar1 = this->Num_Lines & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)piVar4 = 0;
    piVar4 = (int *)((int)piVar4 + 1);
  }
  piVar4 = this->RightMostPx;
  for (uVar1 = this->Num_Lines & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)piVar4 = 0;
    piVar4 = (int *)((int)piVar4 + 1);
  }
  piVar4 = this->Span_Count;
  for (uVar1 = this->Num_Lines & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)piVar4 = 0;
    piVar4 = (int *)((int)piVar4 + 1);
  }
  return;
}

// --------------------------------------------------

// Function: AddSpan
// Address: 004bdb00
/* public: void __thiscall TSpan_List_Manager::AddSpan(int,int,int) */

void __thiscall
TSpan_List_Manager::AddSpan(TSpan_List_Manager *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  VSpan_Node *pVVar3;
  VSpan_Node *pVVar4;
  int iVar5;
  VSpan_Node *pVVar6;
  
  iVar5 = param_2;
  if ((this->Min_Line <= param_3) && (param_3 <= this->Max_Line)) {
    if (param_2 < param_1) {
      param_2 = param_1;
      param_1 = iVar5;
    }
    iVar5 = this->Min_Span_Px;
    if ((iVar5 <= param_2) && (iVar1 = this->Max_Span_Px, param_1 <= iVar1)) {
      if (param_1 < iVar5) {
        param_1 = iVar5;
      }
      if (iVar1 < param_2) {
        param_2 = iVar1;
      }
      pVVar3 = this->Line_Head_Ptrs[param_3];
      if (pVVar3 == (VSpan_Node *)0x0) {
        pVVar3 = TSpan_Node_List::GetNode(&this->VSList);
        pVVar3->Prev = (VSpan_Node *)0x0;
        pVVar3->Next = (VSpan_Node *)0x0;
        pVVar3->StartPx = param_1;
        pVVar3->EndPx = param_2;
        this->Line_Head_Ptrs[param_3] = pVVar3;
        this->Line_Tail_Ptrs[param_3] = pVVar3;
        this->LeftMostPx[param_3] = param_1;
        this->RightMostPx[param_3] = param_2;
        this->Span_Count[param_3] = this->Span_Count[param_3] + 1;
        return;
      }
      pVVar4 = this->Line_Tail_Ptrs[param_3];
      iVar5 = this->LeftMostPx[param_3];
      if (iVar5 < param_1) {
        iVar5 = this->RightMostPx[param_3];
        if (param_2 < iVar5) {
          iVar5 = pVVar3->EndPx;
          while (iVar5 < param_1 + -1) {
            pVVar3 = pVVar3->Next;
            iVar5 = pVVar3->EndPx;
          }
          if (param_2 + 1 < pVVar3->StartPx) {
            pVVar6 = TSpan_Node_List::GetNode(&this->VSList);
            pVVar4 = pVVar3->Prev;
            pVVar6->Next = pVVar3;
            pVVar6->Prev = pVVar4;
            pVVar3->Prev = pVVar6;
            pVVar6->Prev->Next = pVVar6;
            pVVar6->StartPx = param_1;
            pVVar6->EndPx = param_2;
            this->Span_Count[param_3] = this->Span_Count[param_3] + 1;
            return;
          }
          if (param_1 < pVVar3->StartPx) {
            pVVar3->StartPx = param_1;
          }
          if ((pVVar3->EndPx < param_2) &&
             (pVVar4 = pVVar3->Next, pVVar3->Next != (VSpan_Node *)0x0)) {
            while( true ) {
              if (param_2 + 1 < pVVar4->StartPx) {
                pVVar3->EndPx = param_2;
                return;
              }
              if (param_2 <= pVVar4->EndPx) break;
              if (pVVar4->Prev != (VSpan_Node *)0x0) {
                pVVar4->Prev->Next = pVVar4->Next;
              }
              if (pVVar4->Next != (VSpan_Node *)0x0) {
                pVVar4->Next->Prev = pVVar4->Prev;
              }
              pVVar6 = pVVar4->Next;
              TSpan_Node_List::FreeNode(&this->VSList,pVVar4);
              this->Span_Count[param_3] = this->Span_Count[param_3] + -1;
              pVVar4 = pVVar6;
              if (pVVar6 == (VSpan_Node *)0x0) {
                return;
              }
            }
            pVVar3->EndPx = pVVar4->EndPx;
            pVVar3->Next = pVVar4->Next;
            TSpan_Node_List::FreeNode(&this->VSList,pVVar4);
            this->Span_Count[param_3] = this->Span_Count[param_3] + -1;
            if (pVVar3->Next != (VSpan_Node *)0x0) {
              pVVar3->Next->Prev = pVVar3;
              return;
            }
            this->Line_Tail_Ptrs[param_3] = pVVar3;
          }
        }
        else {
          if (iVar5 + 1 < param_1) {
            pVVar3 = TSpan_Node_List::GetNode(&this->VSList);
            pVVar3->Prev = pVVar4;
            pVVar3->Next = (VSpan_Node *)0x0;
            pVVar4->Next = pVVar3;
            pVVar3->StartPx = param_1;
            pVVar3->EndPx = param_2;
            this->RightMostPx[param_3] = param_2;
            this->Line_Tail_Ptrs[param_3] = pVVar3;
            this->Span_Count[param_3] = this->Span_Count[param_3] + 1;
            return;
          }
          this->RightMostPx[param_3] = param_2;
          iVar5 = param_1 + -1;
          if (iVar5 <= pVVar4->EndPx) {
            while( true ) {
              if (pVVar4->StartPx <= param_1) {
                pVVar4->EndPx = param_2;
                return;
              }
              pVVar3 = pVVar4->Prev;
              if (pVVar3->EndPx < iVar5) break;
              this->Line_Tail_Ptrs[param_3] = pVVar3;
              pVVar3->Next = (VSpan_Node *)0x0;
              TSpan_Node_List::FreeNode(&this->VSList,pVVar4);
              this->Span_Count[param_3] = this->Span_Count[param_3] + -1;
              pVVar4 = pVVar3;
              if (pVVar3->EndPx < iVar5) {
                return;
              }
            }
            pVVar4->StartPx = param_1;
            pVVar4->EndPx = param_2;
            return;
          }
        }
      }
      else {
        if (param_2 < iVar5 + -1) {
          pVVar4 = TSpan_Node_List::GetNode(&this->VSList);
          pVVar4->Prev = (VSpan_Node *)0x0;
          pVVar4->Next = pVVar3;
          pVVar3->Prev = pVVar4;
          pVVar4->StartPx = param_1;
          pVVar4->EndPx = param_2;
          this->LeftMostPx[param_3] = param_1;
          this->Line_Head_Ptrs[param_3] = pVVar4;
          this->Span_Count[param_3] = this->Span_Count[param_3] + 1;
          return;
        }
        if (this->RightMostPx[param_3] <= param_2) {
          piVar2 = this->Span_Count;
          iVar5 = TSpan_Node_List::FreeThread(&this->VSList,pVVar3->Next,(VSpan_Node *)0x0);
          piVar2[param_3] = piVar2[param_3] - iVar5;
          pVVar3->Prev = (VSpan_Node *)0x0;
          pVVar3->Next = (VSpan_Node *)0x0;
          pVVar3->StartPx = param_1;
          pVVar3->EndPx = param_2;
          this->Line_Tail_Ptrs[param_3] = pVVar3;
          this->RightMostPx[param_3] = param_2;
          this->LeftMostPx[param_3] = param_1;
          return;
        }
        this->LeftMostPx[param_3] = param_1;
        iVar5 = param_2 + 1;
        if (pVVar3->StartPx <= iVar5) {
          while( true ) {
            if (param_2 <= pVVar3->EndPx) {
              pVVar3->StartPx = param_1;
              return;
            }
            pVVar4 = pVVar3->Next;
            if (iVar5 < pVVar4->StartPx) break;
            this->Line_Head_Ptrs[param_3] = pVVar4;
            pVVar4->Prev = (VSpan_Node *)0x0;
            TSpan_Node_List::FreeNode(&this->VSList,pVVar3);
            this->Span_Count[param_3] = this->Span_Count[param_3] + -1;
            pVVar3 = pVVar4;
            if (iVar5 < pVVar4->StartPx) {
              return;
            }
          }
          pVVar3->StartPx = param_1;
          pVVar3->EndPx = param_2;
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: AddShape
// Address: 004bdea0
/* public: void __thiscall TSpan_List_Manager::AddShape(class TShape *,int,int,int,int) */

void __thiscall
TSpan_List_Manager::AddShape
          (TSpan_List_Manager *this,TShape *param_1,int param_2,int param_3,int param_4,int param_5)
{
  ushort *puVar1;
  char *pcVar2;
  int iVar3;
  Shape_Info *pSVar4;
  long lVar5;
  int iVar6;
  long *plVar7;
  
  if ((param_1 != (TShape *)0x0) && (param_1->FShape != (SLhape_File_Header *)0x0)) {
    pSVar4 = param_1->shape_info;
    plVar7 = (long *)(param_1->FShape->Version + pSVar4[param_2].Shape_Outline_Offset);
    iVar3 = pSVar4[param_2].Width + -1 + param_3;
    if (param_5 == 0) {
      iVar6 = param_4;
      if (param_4 < param_4 + pSVar4[param_2].Height) {
        do {
          lVar5 = *plVar7;
          puVar1 = (ushort *)((int)plVar7 + 2);
          plVar7 = plVar7 + 1;
          if (((this->Min_Line <= iVar6) && (iVar6 <= this->Max_Line)) &&
             (((ushort)lVar5 & 0x8000) == 0)) {
            AddSpan(this,(short)(ushort)lVar5 + param_3,iVar3 - (short)*puVar1,iVar6);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_4 + pSVar4[param_2].Height);
        return;
      }
    }
    else {
      iVar6 = param_4;
      if (param_4 < param_4 + pSVar4[param_2].Height) {
        do {
          lVar5 = *plVar7;
          pcVar2 = (char *)((int)plVar7 + 2);
          plVar7 = plVar7 + 1;
          if (((this->Min_Line <= iVar6) && (iVar6 <= this->Max_Line)) &&
             ((*(ushort *)pcVar2 & 0x8000) == 0)) {
            AddSpan(this,(short)*(ushort *)pcVar2 + param_3,iVar3 - (short)(ushort)lVar5,iVar6);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_4 + pSVar4[param_2].Height);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: AddShape_Align
// Address: 004bdfa0
/* public: void __thiscall TSpan_List_Manager::AddShape_Align(unsigned char *,struct Shape_Info
   *,int,int,int) */

void __thiscall
TSpan_List_Manager::AddShape_Align
          (TSpan_List_Manager *this,uchar *param_1,Shape_Info *param_2,int param_3,int param_4,
          int param_5)
{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  
  if (param_2 != (Shape_Info *)0x0) {
    puVar5 = (ushort *)(param_1 + param_2->Shape_Outline_Offset);
    iVar2 = param_2->Width + -1 + param_3;
    if (param_5 == 0) {
      iVar4 = param_4;
      if (param_4 < param_4 + param_2->Height) {
        do {
          uVar3 = *puVar5;
          puVar1 = puVar5 + 1;
          puVar5 = puVar5 + 2;
          if (((this->Min_Line <= iVar4) && (iVar4 <= this->Max_Line)) && ((uVar3 & 0x8000) == 0)) {
            AddSpan(this,(short)uVar3 + param_3 & 0xfffffffc,iVar2 - (short)*puVar1 | 3,iVar4);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_4 + param_2->Height);
        return;
      }
    }
    else {
      iVar4 = param_4;
      if (param_4 < param_4 + param_2->Height) {
        do {
          uVar3 = *puVar5;
          puVar1 = puVar5 + 1;
          puVar5 = puVar5 + 2;
          if (((this->Min_Line <= iVar4) && (iVar4 <= this->Max_Line)) && ((*puVar1 & 0x8000) == 0))
{
            AddSpan(this,(short)*puVar1 + param_3 & 0xfffffffc,iVar2 - (short)uVar3 | 3,iVar4);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_4 + param_2->Height);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: AddLine_Align
// Address: 004be090
/* public: void __thiscall TSpan_List_Manager::AddLine_Align(int,int,int,int) */

void __thiscall
TSpan_List_Manager::AddLine_Align
          (TSpan_List_Manager *this,int param_1,int param_2,int param_3,int param_4)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_3;
  if (param_1 == param_3) {
    iVar4 = param_4;
    if (param_4 < param_2) {
      iVar4 = param_2;
      param_2 = param_4;
    }
    for (; param_2 <= iVar4; param_2 = param_2 + 1) {
      AddSpan(this,param_1 & 0xfffffffc,param_1 | 3,param_2);
    }
  }
  else {
    if (param_2 == param_4) {
      AddSpan(this,param_1 & 0xfffffffc,param_3 | 3,param_2);
      return;
    }
    iVar5 = param_2;
    iVar3 = param_4;
    if (param_3 < param_1) {
      param_3 = param_1;
      param_1 = iVar4;
      iVar5 = param_4;
      iVar3 = param_2;
    }
    iVar4 = (param_3 - param_1) + 1;
    if (iVar5 < iVar3) {
      param_4 = 1;
      iVar2 = iVar3 - iVar5;
    }
    else {
      iVar2 = iVar5 - iVar3;
      param_4 = -1;
    }
    iVar2 = iVar2 + 1;
    if (iVar2 <= iVar4) {
      iVar3 = 0;
      uVar1 = param_1;
      for (; param_1 < param_3; param_1 = param_1 + 1) {
        iVar3 = iVar3 + iVar2;
        if (iVar4 <= iVar3) {
          AddSpan(this,uVar1 & 0xfffffffc,param_1 | 3,iVar5);
          iVar5 = iVar5 + param_4;
          iVar3 = iVar3 - iVar4;
          uVar1 = param_1 + 1;
        }
      }
      AddSpan(this,uVar1 & 0xfffffffc,param_1 | 3,iVar5);
      return;
    }
    param_3 = 0;
    for (; AddSpan(this,param_1 & 0xfffffffc,param_1 | 3,iVar5), iVar5 != iVar3;
        iVar5 = iVar5 + param_4) {
      param_3 = param_3 + iVar4;
      if (iVar2 <= param_3) {
        param_1 = param_1 + 1;
        param_3 = param_3 - iVar2;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: AddMiniList
// Address: 004be1f0
/* public: void __thiscall TSpan_List_Manager::AddMiniList(struct VSpanMiniList *,int,int) */

void __thiscall
TSpan_List_Manager::AddMiniList
          (TSpan_List_Manager *this,VSpanMiniList *param_1,int param_2,int param_3)
{
  if (param_1 != (VSpanMiniList *)0x0) {
    do {
      if (param_1->Y_delta == 0xff) {
        return;
      }
      AddSpan(this,(uint)param_1->X_start + param_2,(uint)param_1->X_end + param_2,
              (uint)param_1->Y_delta + param_3);
      param_1 = param_1 + 1;
    } while (param_1 != (VSpanMiniList *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: SubtractMiniList
// Address: 004be240
/* public: void __thiscall TSpan_List_Manager::SubtractMiniList(struct VSpanMiniList *,int,int) */

void __thiscall
TSpan_List_Manager::SubtractMiniList
          (TSpan_List_Manager *this,VSpanMiniList *param_1,int param_2,int param_3)
{
  if (param_1 != (VSpanMiniList *)0x0) {
    do {
      if (param_1->Y_delta == 0xff) {
        return;
      }
      DeleteSpan(this,(uint)param_1->X_start + param_2,(uint)param_1->X_end + param_2,
                 (uint)param_1->Y_delta + param_3);
      param_1 = param_1 + 1;
    } while (param_1 != (VSpanMiniList *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: DeleteSpan
// Address: 004be290
/* WARNING: Variable defined which should be unmapped: L */
/* public: void __thiscall TSpan_List_Manager::DeleteSpan(int,int,int) */

void __thiscall
TSpan_List_Manager::DeleteSpan(TSpan_List_Manager *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  VSpan_Node *pVVar4;
  VSpan_Node *pVVar5;
  VSpan_Node *pVVar6;
  VSpan_Node *L;
  VSpan_Node *local_4;
  
  iVar3 = param_3;
  iVar1 = param_2;
  if ((this->Min_Line <= param_3) && (param_3 <= this->Max_Line)) {
    if (param_2 < param_1) {
      param_2 = param_1;
      param_1 = iVar1;
    }
    iVar1 = this->Min_Span_Px;
    if ((iVar1 <= param_2) && (iVar2 = this->Max_Span_Px, param_1 <= iVar2)) {
      if (param_1 < iVar1) {
        param_1 = iVar1;
      }
      if (iVar2 < param_2) {
        param_2 = iVar2;
      }
      pVVar4 = this->Line_Head_Ptrs[param_3];
      if (((pVVar4 != (VSpan_Node *)0x0) && (this->LeftMostPx[param_3] <= param_2)) &&
         (param_1 <= this->RightMostPx[param_3])) {
        if ((param_1 <= this->LeftMostPx[param_3]) && (this->RightMostPx[param_3] <= param_2)) {
          TSpan_Node_List::FreeThread(&this->VSList,pVVar4,this->Line_Tail_Ptrs[param_3]);
          this->Line_Head_Ptrs[param_3] = (VSpan_Node *)0x0;
          this->Line_Tail_Ptrs[param_3] = (VSpan_Node *)0x0;
          this->Span_Count[param_3] = 0;
          this->LeftMostPx[param_3] = 0;
          this->RightMostPx[param_3] = 0;
          return;
        }
        pVVar6 = this->Line_Tail_Ptrs[param_3];
        iVar1 = pVVar4->EndPx;
        pVVar5 = pVVar4;
        while (iVar1 < param_1) {
          pVVar5 = pVVar5->Next;
          iVar1 = pVVar5->EndPx;
        }
        if (pVVar5->StartPx < param_1) {
          if (param_2 < pVVar5->EndPx) {
            pVVar4 = TSpan_Node_List::GetNode(&this->VSList);
            pVVar4->Prev = pVVar5;
            pVVar4->Next = pVVar5->Next;
            pVVar5->Next = pVVar4;
            if (pVVar4->Next != (VSpan_Node *)0x0) {
              pVVar4->Next->Prev = pVVar4;
            }
            if (pVVar5 == pVVar6) {
              this->Line_Tail_Ptrs[param_3] = pVVar4;
            }
            pVVar4->StartPx = param_2 + 1;
            pVVar4->EndPx = pVVar5->EndPx;
            pVVar5->EndPx = param_1 + -1;
            this->Span_Count[param_3] = this->Span_Count[param_3] + 1;
            return;
          }
          if (pVVar5->StartPx < param_1) {
            pVVar5->EndPx = param_1 + -1;
            pVVar5 = pVVar5->Next;
          }
        }
        param_3 = (int)pVVar6;
        local_4 = pVVar4;
        if (pVVar5 != (VSpan_Node *)0x0) {
          do {
            if ((pVVar5->StartPx < param_1) || (param_2 < pVVar5->EndPx)) {
              pVVar6 = (VSpan_Node *)0x0;
            }
            else {
              if (pVVar5 == pVVar4) {
                local_4 = pVVar5->Next;
              }
              if (pVVar5 == (VSpan_Node *)param_3) {
                param_3 = (int)pVVar5->Prev;
              }
              if (pVVar5->Prev != (VSpan_Node *)0x0) {
                pVVar5->Prev->Next = pVVar5->Next;
              }
              if (pVVar5->Next != (VSpan_Node *)0x0) {
                pVVar5->Next->Prev = pVVar5->Prev;
              }
              pVVar6 = pVVar5->Next;
              TSpan_Node_List::FreeNode(&this->VSList,pVVar5);
              this->Span_Count[iVar3] = this->Span_Count[iVar3] + -1;
              pVVar4 = local_4;
              pVVar5 = pVVar6;
            }
          } while (pVVar6 != (VSpan_Node *)0x0);
          if ((pVVar5 != (VSpan_Node *)0x0) && (pVVar5->StartPx <= param_2)) {
            pVVar5->StartPx = param_2 + 1;
          }
        }
        this->Line_Head_Ptrs[iVar3] = pVVar4;
        this->Line_Tail_Ptrs[iVar3] = (VSpan_Node *)param_3;
        this->LeftMostPx[iVar3] = pVVar4->StartPx;
        this->RightMostPx[iVar3] = *(int *)(param_3 + 0xc);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: DeleteShape
// Address: 004be4b0
/* public: void __thiscall TSpan_List_Manager::DeleteShape(class TShape *,int,int,int,int) */

void __thiscall
TSpan_List_Manager::DeleteShape
          (TSpan_List_Manager *this,TShape *param_1,int param_2,int param_3,int param_4,int param_5)
{
  ushort *puVar1;
  char *pcVar2;
  int iVar3;
  Shape_Info *pSVar4;
  long lVar5;
  long *plVar6;
  int iVar7;
  
  if ((param_1 != (TShape *)0x0) && (param_1->FShape != (SLhape_File_Header *)0x0)) {
    pSVar4 = param_1->shape_info;
    plVar6 = (long *)(param_1->FShape->Version + pSVar4[param_2].Shape_Outline_Offset);
    iVar3 = pSVar4[param_2].Width + -1 + param_3;
    if (param_5 == 0) {
      iVar7 = param_4;
      if (param_4 < param_4 + pSVar4[param_2].Height) {
        do {
          lVar5 = *plVar6;
          puVar1 = (ushort *)((int)plVar6 + 2);
          plVar6 = plVar6 + 1;
          if (((ushort)lVar5 & 0x8000) == 0) {
            DeleteSpan(this,param_3 + (short)(ushort)lVar5,iVar3 - (short)*puVar1,iVar7);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < param_4 + pSVar4[param_2].Height);
        return;
      }
    }
    else {
      iVar7 = param_4;
      if (param_4 < param_4 + pSVar4[param_2].Height) {
        do {
          lVar5 = *plVar6;
          pcVar2 = (char *)((int)plVar6 + 2);
          plVar6 = plVar6 + 1;
          if ((*(ushort *)pcVar2 & 0x8000) == 0) {
            DeleteSpan(this,param_3 + (short)*(ushort *)pcVar2,iVar3 - (short)(ushort)lVar5,iVar7);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < param_4 + pSVar4[param_2].Height);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: PointVisible
// Address: 004be5b0
/* public: int __thiscall TSpan_List_Manager::PointVisible(int,int) */

int __thiscall TSpan_List_Manager::PointVisible(TSpan_List_Manager *this,int param_1,int param_2)
{
  VSpan_Node *pVVar1;
  
  if (((-1 < param_2) && (param_2 < this->Num_Lines)) &&
     (pVVar1 = this->Line_Head_Ptrs[param_2], pVVar1 != (VSpan_Node *)0x0)) {
    while ((param_1 < pVVar1->StartPx || (pVVar1->EndPx < param_1))) {
      pVVar1 = pVVar1->Next;
      if (pVVar1 == (VSpan_Node *)0x0) {
        return (int)pVVar1;
      }
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: Merge_n_Align
// Address: 004be5f0
/* public: void __thiscall TSpan_List_Manager::Merge_n_Align(class TSpan_List_Manager *,class
   TSpan_List_Manager *) */

void __thiscall
TSpan_List_Manager::Merge_n_Align
          (TSpan_List_Manager *this,TSpan_List_Manager *param_1,TSpan_List_Manager *param_2)
{
  int iVar1;
  int iVar2;
  VSpan_Node *pVVar3;
  VSpan_Node *pVVar4;
  
  ResetAll(this);
  iVar1 = this->Num_Lines;
  if ((((iVar1 != param_1->Num_Lines) || (iVar1 != param_2->Num_Lines)) ||
      (this->Num_Pixels != param_1->Num_Pixels)) ||
     ((this->Num_Pixels != param_2->Num_Pixels || (iVar2 = 0, iVar1 < 1)))) {
    return;
  }
LAB_004be62f:
  pVVar4 = param_1->Line_Head_Ptrs[iVar2];
  pVVar3 = param_2->Line_Head_Ptrs[iVar2];
LAB_004be63b:
  if (pVVar4 == (VSpan_Node *)0x0) {
    if (pVVar3 == (VSpan_Node *)0x0) goto LAB_004be67c;
  }
  else {
    AddSpan(this,pVVar4->StartPx & 0xfffffffc,pVVar4->EndPx | 3,iVar2);
    pVVar4 = pVVar4->Next;
  }
  if (pVVar3 != (VSpan_Node *)0x0) {
    AddSpan(this,pVVar3->StartPx & 0xfffffffc,pVVar3->EndPx | 3,iVar2);
    pVVar3 = pVVar3->Next;
  }
  goto LAB_004be63b;
LAB_004be67c:
  iVar2 = iVar2 + 1;
  if (this->Num_Lines <= iVar2) {
    return;
  }
  goto LAB_004be62f;
}

// --------------------------------------------------

// Function: AlignamizeSpans
// Address: 004be690
/* public: void __thiscall TSpan_List_Manager::AlignamizeSpans(void) */

void __thiscall TSpan_List_Manager::AlignamizeSpans(TSpan_List_Manager *this)
{
  VSpan_Node *pVVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  VSpan_Node *pVVar5;
  
  iVar3 = 0;
  if (0 < this->Num_Lines) {
    do {
      pVVar5 = this->Line_Head_Ptrs[iVar3];
      while (pVVar5 != (VSpan_Node *)0x0) {
        pVVar1 = pVVar5->Next;
        pVVar5->StartPx = pVVar5->StartPx & 0xfffffffc;
        uVar2 = pVVar5->EndPx | 3;
        pVVar5->EndPx = uVar2;
        if (pVVar1 == (VSpan_Node *)0x0) {
          pVVar5 = (VSpan_Node *)0x0;
        }
        else if ((int)uVar2 < (int)((pVVar1->StartPx & 0x7ffffffcU) - 1)) {
          pVVar5 = pVVar5->Next;
        }
        else {
          pVVar5->EndPx = pVVar1->EndPx | 3;
          pVVar5->Next = pVVar1->Next;
          if (pVVar1 == this->Line_Tail_Ptrs[iVar3]) {
            this->Line_Tail_Ptrs[iVar3] = pVVar5;
          }
          if (pVVar1->Next != (VSpan_Node *)0x0) {
            pVVar1->Next->Prev = pVVar5;
          }
          TSpan_Node_List::FreeNode(&this->VSList,pVVar1);
          this->Span_Count[iVar3] = this->Span_Count[iVar3] + -1;
        }
      }
      iVar4 = iVar3 + 1;
      this->LeftMostPx[iVar3] = this->Line_Head_Ptrs[iVar3]->StartPx;
      this->RightMostPx[iVar3] = this->Line_Tail_Ptrs[iVar3]->EndPx;
      iVar3 = iVar4;
    } while (iVar4 < this->Num_Lines);
  }
  return;
}

// --------------------------------------------------

// Function: ScrollSpansHorizontally
// Address: 004be750
/* public: void __thiscall TSpan_List_Manager::ScrollSpansHorizontally(int,int) */

void __thiscall
TSpan_List_Manager::ScrollSpansHorizontally(TSpan_List_Manager *this,int param_1,int param_2)
{
  VSpan_Node *pVVar1;
  VSpan_Node *pVVar2;
  int iVar3;
  int iVar4;
  VSpan_Node *pVVar5;
  int iVar6;
  int iVar7;
  int y;
  int local_4;
  
  if (param_1 != 0) {
    if ((param_2 != 0) &&
       (this->Max_Span_Px - this->Min_Span_Px < (param_1 ^ param_1 >> 0x1f) - (param_1 >> 0x1f))) {
      ResetAll(this);
      return;
    }
    local_4 = 0;
    if (0 < this->Num_Lines) {
      do {
        pVVar1 = this->Line_Head_Ptrs[local_4];
        while (pVVar5 = pVVar1, pVVar5 != (VSpan_Node *)0x0) {
          pVVar1 = pVVar5->Next;
          iVar7 = pVVar5->StartPx + param_1;
          iVar6 = pVVar5->EndPx + param_1;
          pVVar2 = pVVar5->Prev;
          if (param_2 != 0) {
            iVar3 = this->Min_Span_Px;
            if ((iVar6 < iVar3) || (iVar4 = this->Max_Span_Px, iVar4 < iVar7)) {
              if (pVVar2 != (VSpan_Node *)0x0) {
                pVVar2->Next = pVVar1;
              }
              if (pVVar1 != (VSpan_Node *)0x0) {
                pVVar1->Prev = pVVar2;
              }
              TSpan_Node_List::FreeNode(&this->VSList,pVVar5);
              this->Span_Count[local_4] = this->Span_Count[local_4] + -1;
              pVVar5 = (VSpan_Node *)0x0;
            }
            else {
              if (iVar7 < iVar3) {
                iVar7 = iVar3;
              }
              if (iVar4 < iVar6) {
                iVar6 = iVar4;
              }
            }
          }
          if (pVVar5 != (VSpan_Node *)0x0) {
            pVVar5->StartPx = iVar7;
            pVVar5->EndPx = iVar6;
          }
        }
        local_4 = local_4 + 1;
      } while (local_4 < this->Num_Lines);
    }
  }
  return;
}

// --------------------------------------------------

// Function: ScrollSpansVertically
// Address: 004be850
/* public: void __thiscall TSpan_List_Manager::ScrollSpansVertically(int,int) */

void __thiscall
TSpan_List_Manager::ScrollSpansVertically(TSpan_List_Manager *this,int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = param_1;
  iVar5 = 0;
  if (param_1 != 0) {
    if (param_2 == 0) {
      param_1 = 0;
      param_2 = this->Num_Lines + -1;
    }
    else {
      param_1 = this->Min_Line;
      param_2 = this->Max_Line;
    }
    if (param_2 - param_1 < (iVar2 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f)) {
      ResetAll(this);
      return;
    }
    iVar4 = iVar2;
    if (0 < this->Num_Lines) {
      do {
        if ((this->Line_Head_Ptrs[iVar5] != (VSpan_Node *)0x0) &&
           ((iVar4 < param_1 || (param_2 < iVar4)))) {
          TSpan_Node_List::FreeThread
                    (&this->VSList,this->Line_Head_Ptrs[iVar5],this->Line_Tail_Ptrs[iVar5]);
          this->Line_Head_Ptrs[iVar5] = (VSpan_Node *)0x0;
          this->Line_Tail_Ptrs[iVar5] = (VSpan_Node *)0x0;
          this->Span_Count[iVar5] = 0;
          this->LeftMostPx[iVar5] = 0;
          this->RightMostPx[iVar5] = 0;
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar5 < this->Num_Lines);
    }
    if (iVar2 < 1) {
      iVar5 = this->Num_Lines;
      iVar6 = 1;
      param_1 = iVar5 - iVar2;
      iVar4 = iVar5 + -1;
      iVar3 = iVar2;
    }
    else {
      iVar4 = 0;
      iVar6 = -1;
      param_1 = 0;
      iVar5 = iVar2 + -1;
      iVar3 = (this->Num_Lines - iVar2) + -1;
    }
    if (iVar3 != iVar4 + iVar6) {
      iVar2 = (iVar3 + iVar2) * 4;
      do {
        *(VSpan_Node **)(iVar2 + (int)this->Line_Head_Ptrs) = this->Line_Head_Ptrs[iVar3];
        *(VSpan_Node **)(iVar2 + (int)this->Line_Tail_Ptrs) = this->Line_Tail_Ptrs[iVar3];
        *(int *)(iVar2 + (int)this->Span_Count) = this->Span_Count[iVar3];
        *(int *)(iVar2 + (int)this->LeftMostPx) = this->LeftMostPx[iVar3];
        piVar1 = this->RightMostPx + iVar3;
        iVar3 = iVar3 + iVar6;
        *(int *)(iVar2 + (int)this->RightMostPx) = *piVar1;
        iVar2 = iVar2 + iVar6 * 4;
      } while (iVar3 != iVar4 + iVar6);
    }
    for (; param_1 <= iVar5; param_1 = param_1 + 1) {
      this->Line_Head_Ptrs[param_1] = (VSpan_Node *)0x0;
      this->Line_Tail_Ptrs[param_1] = (VSpan_Node *)0x0;
      this->Span_Count[param_1] = 0;
      this->LeftMostPx[param_1] = 0;
      this->RightMostPx[param_1] = 0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: ValidateSpan
// Address: 004be9e0
/* public: int __thiscall TSpan_List_Manager::ValidateSpan(int) */

int __thiscall TSpan_List_Manager::ValidateSpan(TSpan_List_Manager *this,int param_1)
{
  VSpan_Node *pVVar1;
  VSpan_Node *pVVar2;
  VSpan_Node *pVVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((-1 < param_1) && (param_1 < this->Num_Lines)) {
    if (this->Line_Head_Ptrs[param_1] == (VSpan_Node *)0x0) {
      if (((this->Line_Tail_Ptrs[param_1] == (VSpan_Node *)0x0) && (this->Span_Count[param_1] == 0))
         && (this->LeftMostPx[param_1] == 0)) {
        return (uint)(this->RightMostPx[param_1] == 0);
      }
    }
    else {
      pVVar1 = this->Line_Head_Ptrs[param_1];
      pVVar3 = (VSpan_Node *)0x0;
      iVar4 = 0;
      do {
        pVVar2 = pVVar1;
        iVar5 = iVar5 + 1;
        if ((iVar5 == 1) && (pVVar2->StartPx != this->LeftMostPx[param_1])) {
          return 0;
        }
        if (pVVar2->Prev != pVVar3) {
          return 0;
        }
        if (pVVar2->EndPx < pVVar2->StartPx) {
          return 0;
        }
        if ((1 < iVar5) && (pVVar2->StartPx <= iVar4)) {
          return 0;
        }
        pVVar1 = pVVar2->Next;
        pVVar3 = pVVar2;
        iVar4 = pVVar2->EndPx;
      } while (pVVar2->Next != (VSpan_Node *)0x0);
      if (((this->Span_Count[param_1] == iVar5) && (this->Line_Tail_Ptrs[param_1] == pVVar2)) &&
         (pVVar2->EndPx == this->RightMostPx[param_1])) {
        return (uint)(this->LeftMostPx[param_1] <= this->RightMostPx[param_1]);
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: DecodeLine
// Address: 004bead0
/* public: int __thiscall TSpan_List_Manager::DecodeLine(unsigned char *,int,unsigned char,int) */

int __thiscall
TSpan_List_Manager::DecodeLine
          (TSpan_List_Manager *this,uchar *param_1,int param_2,uchar param_3,int param_4)
{
  VSpan_Node *pVVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  for (pVVar1 = this->Line_Head_Ptrs[param_2]; pVVar1 != (VSpan_Node *)0x0; pVVar1 = pVVar1->Next) {
    iVar2 = pVVar1->EndPx;
    for (iVar4 = pVVar1->StartPx; iVar4 <= iVar2; iVar4 = iVar4 + 1) {
      param_1[iVar4] = param_1[iVar4] + param_3;
    }
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

// --------------------------------------------------

// Function: take_snapshot
// Address: 004beb10
// [HELPER] s_C__AOE__03d_BMP: "C:\AOE_%03d.BMP"
/* WARNING: Variable defined which should be unmapped: Height */
/* public: void __thiscall TSpan_List_Manager::take_snapshot(char *,int &,class TDrawArea
   *,int,class TSpan_List_Manager * *,int *,int) */

void __thiscall
TSpan_List_Manager::take_snapshot
          (TSpan_List_Manager *this,char *param_1,int *param_2,TDrawArea *param_3,int param_4,
          TSpan_List_Manager **param_5,int *param_6,int param_7)
{
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  uint uVar8;
  TSpan_List_Manager **ppTVar9;
  uint uVar10;
  uchar *puVar11;
  char *pcVar12;
  int Height;
  int Width;
  int infile;
  int bmWide;
  tagBITMAPFILEHEADER bmFH;
  tagBITMAPINFOHEADER bmIH;
  char BMPFile [60];
  tagRGBQUAD bmPAL [256];
  tagPALETTEENTRY thePal [256];
  
  if ((0 < param_7) && (iVar4 = 0, ppTVar9 = param_5, 0 < param_7)) {
    do {
      if (*ppTVar9 == (TSpan_List_Manager *)0x0) {
        return;
      }
      iVar4 = iVar4 + 1;
      ppTVar9 = ppTVar9 + 1;
    } while (iVar4 < param_7);
  }
  iVar4 = this->Num_Pixels;
  iVar3 = this->Num_Lines;
  uVar10 = iVar4 + 3U & 0xfffc;
  bmFH._6_4_ = iVar3 * uVar10 + 0x436;
  bmFH.bfSize._2_2_ = 0x4d42;
  bmFH.bfOffBits._0_2_ = 0;
  bmFH.bfOffBits._2_2_ = 0;
  bmIH.biWidth = 0x28;
  bmIH.biCompression._0_2_ = 1;
  bmIH.biCompression._2_2_ = 8;
  bmIH.biSizeImage = 0;
  bmIH.biXPelsPerMeter = 0;
  bmIH.biYPelsPerMeter = 0;
  bmIH.biClrUsed = 0;
  bmIH.biClrImportant = 0;
  BMPFile[0] = '\0';
  BMPFile[1] = '\0';
  BMPFile[2] = '\0';
  BMPFile[3] = '\0';
  bmFH._0_4_ = this;
  bmIH.biHeight = iVar4;
  bmIH._12_4_ = iVar3;
  TDrawArea::GetPalette(param_3,thePal + 1);
  iVar5 = 0;
  do {
    uVar1 = (&thePal[1].peGreen)[iVar5];
    (&bmPAL[1].rgbBlue)[iVar5] = (&thePal[1].peBlue)[iVar5];
    uVar2 = (&thePal[1].peRed)[iVar5];
    (&bmPAL[1].rgbGreen)[iVar5] = uVar1;
    (&bmPAL[1].rgbRed)[iVar5] = uVar2;
    (&bmPAL[1].rgbReserved)[iVar5] = '\0';
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0x400);
  iVar5 = 0;
  if (*param_2 < 0) {
    *param_2 = 0;
  }
  while( true ) {
    if (param_1 == (char *)0x0) {
      iVar6 = *param_2;
      pcVar12 = s_C__AOE__03d_BMP;
    }
    else {
      iVar6 = *param_2;
      pcVar12 = param_1;
    }
    sprintf(BMPFile + 4,pcVar12,iVar6);
    iVar5 = iVar5 + 1;
    iVar6 = __open(BMPFile + 4,0);
    if (iVar6 == -1) break;
    *param_2 = *param_2 + 1;
    close(iVar6);
    if (1000 < iVar5) {
      return;
    }
  }
  puVar7 = (uchar *)malloc(uVar10);
  iVar5 = __open(BMPFile + 4,0x8301,0x180);
  if (iVar5 != -1) {
    write(iVar5,(undefined1 *)((int)&bmFH.bfSize + 2),0xe);
    write(iVar5,&bmIH.biWidth,0x28);
    write(iVar5,bmPAL + 1,0x400);
    while (iVar3 = iVar3 + -1, -1 < iVar3) {
      puVar11 = puVar7;
      for (uVar8 = uVar10 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        puVar11[0] = '\0';
        puVar11[1] = '\0';
        puVar11[2] = '\0';
        puVar11[3] = '\0';
        puVar11 = puVar11 + 4;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar11 = '\0';
        puVar11 = puVar11 + 1;
      }
      DecodeLine((TSpan_List_Manager *)bmFH._0_4_,puVar7,iVar3,(uchar)param_4,iVar4);
      if (0 < param_7) {
        Width = param_7;
        ppTVar9 = param_5;
        do {
          DecodeLine(*ppTVar9,puVar7,iVar3,*(uchar *)(((int)param_6 - (int)param_5) + (int)ppTVar9),
                     iVar4);
          ppTVar9 = ppTVar9 + 1;
          Width = Width + -1;
        } while (Width != 0);
      }
      write(iVar5,puVar7,uVar10);
    }
    close(iVar5);
  }
  free(puVar7);
  return;
}

// --------------------------------------------------


// Class: DClipInfo_List
// Function: DClipInfo_List
// Address: 0053ad90
/* public: __thiscall DClipInfo_List::DClipInfo_List(int,int,int,int,int,int) */

DClipInfo_List * __thiscall
DClipInfo_List::DClipInfo_List
          (DClipInfo_List *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  DClipInfo_Node **ppDVar1;
  
  this->Free_Pool_Zone = -1;
  this->Free_Pool_Index = -1;
  this->Element_Size = param_3;
  this->Default_Grow_Size = param_2;
  this->YLine_Size = (param_5 - param_4) + 1;
  this->Zone_Ptrs = (DClipInfo_Node **)0x0;
  this->Zone_Size_Ptrs = (int *)0x0;
  this->Max_Zones = 8;
  this->Used_Zones = 0;
  this->Free_Head = (DClipInfo_Node *)0x0;
  this->Total_Blocks = 0;
  this->Free_Blocks = 0;
  this->YLine_Offset = -param_4;
  this->Max_Draw_Levels = param_6;
  SetCaptureLevel(this,0,param_6);
  ppDVar1 = (DClipInfo_Node **)calloc(this->YLine_Size,4);
  this->Draw_Clip_Nodes = ppDVar1;
  ppDVar1 = (DClipInfo_Node **)calloc(this->Max_Draw_Levels + 1,4);
  this->Draw_Level_Head = ppDVar1;
  ppDVar1 = (DClipInfo_Node **)calloc(this->Max_Draw_Levels + 1,4);
  this->Draw_Level_Tail = ppDVar1;
  ResetStats(this);
  SetNumZones(this,8);
  InitNewZone(this,param_1);
  this->Select_Box = (short *)0x0;
  return this;
}

// --------------------------------------------------

// Function: ~DClipInfo_List
// Address: 0053ae50
/* public: __thiscall DClipInfo_List::~DClipInfo_List(void) */

void __thiscall DClipInfo_List::~DClipInfo_List(DClipInfo_List *this)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < this->Used_Zones) {
    do {
      if (this->Zone_Ptrs[iVar1] != (DClipInfo_Node *)0x0) {
        free(this->Zone_Ptrs[iVar1]);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->Used_Zones);
  }
  if (this->Zone_Ptrs != (DClipInfo_Node **)0x0) {
    free(this->Zone_Ptrs);
  }
  if (this->Zone_Size_Ptrs != (int *)0x0) {
    free(this->Zone_Size_Ptrs);
  }
  if (this->Draw_Clip_Nodes != (DClipInfo_Node **)0x0) {
    free(this->Draw_Clip_Nodes);
  }
  if (this->Draw_Level_Head != (DClipInfo_Node **)0x0) {
    free(this->Draw_Level_Head);
  }
  if (this->Draw_Level_Tail != (DClipInfo_Node **)0x0) {
    free(this->Draw_Level_Tail);
  }
  return;
}

// --------------------------------------------------

// Function: SetCaptureLevel
// Address: 0053aed0
/* public: void __thiscall DClipInfo_List::SetCaptureLevel(int,int) */

void __thiscall DClipInfo_List::SetCaptureLevel(DClipInfo_List *this,int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = param_2;
  if (param_2 < param_1) {
    iVar1 = param_1;
    param_1 = param_2;
  }
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (this->Max_Draw_Levels < iVar1) {
    iVar1 = this->Max_Draw_Levels;
  }
  this->Accept_Min_Level = param_1;
  this->Accept_Max_Level = iVar1;
  return;
}

// --------------------------------------------------

// Function: SetNumZones
// Address: 0053af00
/* private: void __thiscall DClipInfo_List::SetNumZones(int) */

void __thiscall DClipInfo_List::SetNumZones(DClipInfo_List *this,int param_1)
{
  DClipInfo_Node **ppDVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (this->Max_Zones <= param_1) {
    ppDVar1 = (DClipInfo_Node **)calloc(param_1,4);
    piVar2 = (int *)calloc(param_1,4);
    if (this->Zone_Ptrs != (DClipInfo_Node **)0x0) {
      if (0 < this->Used_Zones) {
        iVar3 = 0;
        do {
          iVar4 = iVar3 + 1;
          *(DClipInfo_Node **)(((int)ppDVar1 - (int)piVar2) + (int)(piVar2 + iVar3)) =
               this->Zone_Ptrs[iVar3];
          piVar2[iVar3] = this->Zone_Size_Ptrs[iVar3];
          iVar3 = iVar4;
        } while (iVar4 < this->Used_Zones);
      }
      free(this->Zone_Ptrs);
      free(this->Zone_Size_Ptrs);
    }
    this->Zone_Ptrs = ppDVar1;
    this->Zone_Size_Ptrs = piVar2;
    this->Max_Zones = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: InitNewZone
// Address: 0053af90
/* private: void __thiscall DClipInfo_List::InitNewZone(int) */

void __thiscall DClipInfo_List::InitNewZone(DClipInfo_List *this,int param_1)
{
  int iVar1;
  int iVar2;
  DClipInfo_Node *pDVar3;
  
  if (this->Used_Zones == this->Max_Zones) {
    SetNumZones(this,this->Used_Zones + 4);
  }
  iVar1 = this->Used_Zones;
  this->Used_Zones = iVar1 + 1;
  iVar2 = this->Element_Size;
  this->Zone_Size_Ptrs[iVar1] = param_1;
  pDVar3 = (DClipInfo_Node *)malloc(iVar2 * param_1);
  this->Zone_Ptrs[iVar1] = pDVar3;
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
// Address: 0053b000
/* public: struct DClipInfo_Node * __thiscall DClipInfo_List::GetNode(void) */

DClipInfo_Node * __thiscall DClipInfo_List::GetNode(DClipInfo_List *this)
{
  DClipInfo_Node *pDVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (this->Free_Blocks == 0) {
    InitNewZone(this,this->Default_Grow_Size);
  }
  pDVar1 = this->Free_Head;
  if (pDVar1 != (DClipInfo_Node *)0x0) {
    this->Free_Head = pDVar1->Next;
    this->Free_Blocks = this->Free_Blocks + -1;
    return pDVar1;
  }
  iVar2 = this->Free_Pool_Index;
  iVar3 = this->Free_Pool_Zone;
  pDVar1 = this->Zone_Ptrs[iVar3];
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
  return pDVar1 + iVar2;
}

// --------------------------------------------------

// Function: SetDrawRegion
// Address: 0053b070
/* public: void __thiscall DClipInfo_List::SetDrawRegion(int,int,int,int) */

void __thiscall
DClipInfo_List::SetDrawRegion(DClipInfo_List *this,int param_1,int param_2,int param_3,int param_4)
{
  if (param_1 <= param_3) {
    if (param_2 <= param_4) {
      this->SD_XMin = param_1;
      this->SD_XMax = param_3;
      this->SD_YMin = param_2;
      this->SD_YMax = param_4;
    }
  }
  return;
}

// --------------------------------------------------

// Function: AddDrawNode
// Address: 0053b0a0
/* public: void __thiscall DClipInfo_List::AddDrawNode(void *,struct Shape_Info
   *,int,int,int,int,unsigned char *,int,int,int) */

void __thiscall
DClipInfo_List::AddDrawNode
          (DClipInfo_List *this,void *param_1,Shape_Info *param_2,int param_3,int param_4,
          int param_5,int param_6,uchar *param_7,int param_8,int param_9,int param_10)
{
  DClipInfo_Node *pDVar1;
  short sVar2;
  short sVar3;
  DClipInfo_Node *pDVar4;
  int iVar5;
  DClipInfo_Node *pDVar6;
  short sVar7;
  short sVar8;
  
  iVar5 = this->YLine_Offset + param_3;
  if ((param_9 <= this->Accept_Max_Level) && (this->Accept_Min_Level <= param_9)) {
    sVar2 = (short)param_4;
    sVar8 = (short)param_2->Hotspot_X + sVar2;
    sVar3 = (short)param_5;
    sVar7 = (short)param_2->Hotspot_Y + sVar3;
    if (((param_4 <= this->SD_XMax) &&
        (((this->SD_XMin <= param_4 + -1 + param_2->Width && (param_5 <= this->SD_YMax)) &&
         (this->SD_YMin <= param_5 + -1 + param_2->Height)))) &&
       ((-1 < iVar5 && (iVar5 < this->YLine_Size)))) {
      pDVar6 = GetNode(this);
      pDVar1 = this->Draw_Clip_Nodes[iVar5];
      if (pDVar1 == (DClipInfo_Node *)0x0) {
        this->Draw_Clip_Nodes[iVar5] = pDVar6;
      }
      else {
        for (pDVar4 = pDVar1->Next; pDVar4 != (DClipInfo_Node *)0x0; pDVar4 = pDVar4->Next) {
          pDVar1 = pDVar4;
        }
        pDVar1->Next = pDVar6;
      }
      pDVar6->Object_ID = param_10;
      pDVar6->Draw_Flag = param_6;
      pDVar6->Shape_Base = (uchar *)param_1;
      pDVar6->Color_Table = param_7;
      pDVar6->Xform_Mask = param_8;
      pDVar6->Next = (DClipInfo_Node *)0x0;
      pDVar6->NextOnLevel = (DClipInfo_Node *)0x0;
      pDVar6->Shape = param_2;
      pDVar6->Draw_X = param_4;
      pDVar6->Draw_Y = param_5;
      pDVar6->Draw_Level = param_9;
      pDVar6->Node_Type = 0;
      if (this->Select_Box == (short *)0x0) {
        pDVar6->x1 = sVar2;
        pDVar6->y1 = sVar3;
        pDVar6->x2 = sVar2 + (short)param_2->Width + -1;
        pDVar6->y2 = sVar3 + (short)param_2->Height + -1;
      }
      else {
        pDVar6->x1 = sVar8 + *this->Select_Box;
        pDVar6->y1 = this->Select_Box[1] + sVar7;
        pDVar6->x2 = this->Select_Box[2] + sVar8;
        pDVar6->y2 = this->Select_Box[3] + sVar7;
        this->Select_Box = (short *)0x0;
      }
      pDVar6->x3 = sVar8;
      pDVar6->y3 = sVar7;
      pDVar6->x4 = 0;
      pDVar6->y4 = 0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: AddGDINode
// Address: 0053b220
/* public: struct DClipInfo_Node * __thiscall
   DClipInfo_List::AddGDINode(int,int,int,int,int,int,int,int,int,int,int,int,int) */

DClipInfo_Node * __thiscall
DClipInfo_List::AddGDINode
          (DClipInfo_List *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6,int param_7,int param_8,int param_9,int param_10,int param_11,int param_12,
          int param_13)
{
  DClipInfo_Node *pDVar1;
  int iVar2;
  
  iVar2 = this->YLine_Offset + param_2;
  if ((((param_11 <= this->Accept_Max_Level) && (this->Accept_Min_Level <= param_11)) &&
      (-1 < iVar2)) && (iVar2 < this->YLine_Size)) {
    pDVar1 = GetNode(this);
    pDVar1->Next = this->Draw_Clip_Nodes[iVar2];
    this->Draw_Clip_Nodes[iVar2] = pDVar1;
    pDVar1->Object_ID = param_13;
    pDVar1->Draw_Flag = param_12;
    pDVar1->Node_Type = param_1;
    pDVar1->x1 = (short)param_3;
    pDVar1->y1 = (short)param_4;
    pDVar1->x2 = (short)param_5;
    pDVar1->y2 = (short)param_6;
    pDVar1->x3 = (short)param_7;
    pDVar1->y3 = (short)param_8;
    pDVar1->NextOnLevel = (DClipInfo_Node *)0x0;
    pDVar1->Shape = (Shape_Info *)0x0;
    pDVar1->Draw_X = 0;
    pDVar1->Draw_Y = 0;
    pDVar1->Shape_Base = (uchar *)0x0;
    pDVar1->Color_Table = (uchar *)0x0;
    pDVar1->Xform_Mask = 0;
    pDVar1->Draw_Level = param_11;
    pDVar1->x4 = (short)param_9;
    pDVar1->y4 = (short)param_10;
    return pDVar1;
  }
  return (DClipInfo_Node *)0x0;
}

// --------------------------------------------------

// Function: LocateIDbyDrawLevel
// Address: 0053b300
/* public: struct DClipInfo_Node * __thiscall DClipInfo_List::LocateIDbyDrawLevel(int,int,int,int)
    */

DClipInfo_Node * __thiscall
DClipInfo_List::LocateIDbyDrawLevel
          (DClipInfo_List *this,int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  DClipInfo_Node *pDVar2;
  int iVar3;
  DClipInfo_Node **ppDVar4;
  
  iVar3 = param_2;
  if (param_3 < param_2) {
    iVar3 = param_3;
    param_3 = param_2;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar1 = this->Max_Draw_Levels;
  if (iVar1 < param_3) {
    param_3 = iVar1;
  }
  if (((iVar3 <= iVar1) && (-1 < param_3)) && (iVar3 <= param_3)) {
    ppDVar4 = this->Draw_Level_Head + iVar3;
    do {
      for (pDVar2 = *ppDVar4; pDVar2 != (DClipInfo_Node *)0x0; pDVar2 = pDVar2->NextOnLevel) {
        if ((pDVar2->Object_ID == param_1) && (pDVar2->Node_Type == param_4)) {
          return pDVar2;
        }
      }
      iVar3 = iVar3 + 1;
      ppDVar4 = ppDVar4 + 1;
    } while (iVar3 <= param_3);
  }
  return (DClipInfo_Node *)0x0;
}

// --------------------------------------------------

// Function: Scroll
// Address: 0053b370
/* public: void __thiscall DClipInfo_List::Scroll(int,int) */

void __thiscall DClipInfo_List::Scroll(DClipInfo_List *this,int param_1,int param_2)
{
  undefined4 *puVar1;
  DClipInfo_Node *pDVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  
  if (0 < param_2) {
    if (this->YLine_Size != param_2 && -1 < this->YLine_Size - param_2) {
      iVar8 = param_2 * 4;
      iVar4 = 0;
      do {
        iVar3 = iVar4 + 1;
        puVar1 = (undefined4 *)(iVar8 + (int)this->Draw_Clip_Nodes);
        iVar8 = iVar8 + 4;
        this->Draw_Clip_Nodes[iVar4] = (DClipInfo_Node *)*puVar1;
        iVar4 = iVar3;
      } while (iVar3 < this->YLine_Size - param_2);
    }
    iVar8 = this->YLine_Size - param_2;
    if (iVar8 < this->YLine_Size) {
      do {
        iVar4 = iVar8 + 1;
        this->Draw_Clip_Nodes[iVar8] = (DClipInfo_Node *)0x0;
        iVar8 = iVar4;
      } while (iVar4 < this->YLine_Size);
    }
  }
  if (param_2 < 0) {
    iVar4 = -param_2;
    iVar8 = this->YLine_Size + -1;
    if (SBORROW4(iVar8,iVar4) == iVar8 + param_2 < 0) {
      iVar3 = (param_2 + -1 + this->YLine_Size) * 4;
      do {
        iVar5 = iVar8 + -1;
        puVar1 = (undefined4 *)(iVar3 + (int)this->Draw_Clip_Nodes);
        iVar3 = iVar3 + -4;
        this->Draw_Clip_Nodes[iVar8] = (DClipInfo_Node *)*puVar1;
        iVar8 = iVar5;
      } while (iVar4 <= iVar5);
    }
    iVar8 = 0;
    if (iVar4 != 0 && param_2 < 1) {
      do {
        iVar3 = iVar8 + 1;
        this->Draw_Clip_Nodes[iVar8] = (DClipInfo_Node *)0x0;
        iVar8 = iVar3;
      } while (iVar3 < iVar4);
    }
  }
  iVar8 = 0;
  if (0 < this->YLine_Size) {
    do {
      for (pDVar2 = this->Draw_Clip_Nodes[iVar8]; pDVar2 != (DClipInfo_Node *)0x0;
          pDVar2 = pDVar2->Next) {
        sVar6 = (short)param_2;
        sVar7 = (short)param_1;
        switch(pDVar2->Node_Type) {
        case 0:
          pDVar2->Draw_X = pDVar2->Draw_X - param_1;
          pDVar2->Draw_Y = pDVar2->Draw_Y - param_2;
          break;
        case 1:
          pDVar2->y3 = pDVar2->y3 - sVar6;
          pDVar2->y4 = pDVar2->y4 - sVar6;
        case 2:
          pDVar2->x3 = pDVar2->x3 - sVar7;
          pDVar2->x4 = pDVar2->x4 - sVar7;
        case 3:
        case 4:
          pDVar2->x1 = pDVar2->x1 - sVar7;
          pDVar2->y1 = pDVar2->y1 - sVar6;
          pDVar2->x2 = pDVar2->x2 - sVar7;
          pDVar2->y2 = pDVar2->y2 - sVar6;
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < this->YLine_Size);
  }
  return;
}

// --------------------------------------------------

// Function: FreeNode
// Address: 0053b490
/* public: void __thiscall DClipInfo_List::FreeNode(struct DClipInfo_Node *) */

void __thiscall DClipInfo_List::FreeNode(DClipInfo_List *this,DClipInfo_Node *param_1)
{
  param_1->Next = this->Free_Head;
  this->Free_Head = param_1;
  this->Free_Blocks = this->Free_Blocks + 1;
  return;
}

// --------------------------------------------------

// Function: FreeThread
// Address: 0053b4b0
/* public: int __thiscall DClipInfo_List::FreeThread(struct DClipInfo_Node *,struct DClipInfo_Node
   *) */

int __thiscall
DClipInfo_List::FreeThread(DClipInfo_List *this,DClipInfo_Node *param_1,DClipInfo_Node *param_2)
{
  int iVar1;
  DClipInfo_Node *pDVar2;
  DClipInfo_Node *pDVar3;
  
  iVar1 = 0;
  if (param_1 == (DClipInfo_Node *)0x0) {
    return iVar1;
  }
  pDVar3 = param_1;
  if (param_2 == (DClipInfo_Node *)0x0) {
    do {
      pDVar2 = pDVar3;
      iVar1 = iVar1 + 1;
      this->Free_Blocks = this->Free_Blocks + 1;
      pDVar3 = pDVar2->Next;
    } while (pDVar3 != (DClipInfo_Node *)0x0);
    pDVar2->Next = this->Free_Head;
    this->Free_Head = param_1;
    return iVar1;
  }
  do {
    iVar1 = iVar1 + 1;
    this->Free_Blocks = this->Free_Blocks + 1;
    if (pDVar3 == param_2) {
      pDVar3 = (DClipInfo_Node *)0x0;
    }
    else {
      pDVar3 = pDVar3->Next;
    }
  } while (pDVar3 != (DClipInfo_Node *)0x0);
  param_2->Next = this->Free_Head;
  this->Free_Head = param_1;
  return iVar1;
}

// --------------------------------------------------

// Function: ReclaimAllNodes
// Address: 0053b510
/* public: void __thiscall DClipInfo_List::ReclaimAllNodes(void) */

void __thiscall DClipInfo_List::ReclaimAllNodes(DClipInfo_List *this)
{
  uint uVar1;
  int iVar2;
  DClipInfo_Node **ppDVar3;
  
  ppDVar3 = this->Draw_Clip_Nodes;
  for (uVar1 = this->YLine_Size & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *ppDVar3 = (DClipInfo_Node *)0x0;
    ppDVar3 = ppDVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)ppDVar3 = 0;
    ppDVar3 = (DClipInfo_Node **)((int)ppDVar3 + 1);
  }
  ppDVar3 = this->Draw_Level_Head;
  for (uVar1 = this->Max_Draw_Levels * 4 + 4U >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *ppDVar3 = (DClipInfo_Node *)0x0;
    ppDVar3 = ppDVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)ppDVar3 = 0;
    ppDVar3 = (DClipInfo_Node **)((int)ppDVar3 + 1);
  }
  ppDVar3 = this->Draw_Level_Tail;
  for (uVar1 = this->Max_Draw_Levels * 4 + 4U >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *ppDVar3 = (DClipInfo_Node *)0x0;
    ppDVar3 = ppDVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)ppDVar3 = 0;
    ppDVar3 = (DClipInfo_Node **)((int)ppDVar3 + 1);
  }
  this->Free_Head = (DClipInfo_Node *)0x0;
  this->Free_Pool_Zone = 0;
  this->Free_Pool_Index = 0;
  this->Free_Blocks = this->Total_Blocks;
  this->Reset_Count = this->Reset_Count + 1;
  return;
}

// --------------------------------------------------

// Function: ResetStats
// Address: 0053b590
/* public: void __thiscall DClipInfo_List::ResetStats(void) */

void __thiscall DClipInfo_List::ResetStats(DClipInfo_List *this)
{
  this->Alloc_Count = 0;
  this->Dealloc_Count = 0;
  this->NewZone_Count = 0;
  this->Reset_Count = 0;
  return;
}

// --------------------------------------------------


// Class: Visible_Unit_Manager
// Size:  0x24
//
// Member Layout:
// [0x000] VISIBLE_UNIT_PTR * * PlayerDataPtrs
// [0x004] VISIBLE_UNIT_REC *[5] Return_Buffer (sz: 0x14)
// [0x018] int Player_Count
// [0x01C] int Category_Count
// [0x020] uchar * distanceTable
// ----------------------------------------------------------------

// Function: Visible_Unit_Manager
// Address: 0053b5a0
/* public: __thiscall Visible_Unit_Manager::Visible_Unit_Manager(int,int) */

Visible_Unit_Manager * __thiscall
Visible_Unit_Manager::Visible_Unit_Manager(Visible_Unit_Manager *this,int param_1,int param_2)
{
  VISIBLE_UNIT_PTR **ppVVar1;
  VISIBLE_UNIT_PTR *pVVar2;
  VISIBLE_UNIT_REC *pVVar3;
  int iVar4;
  VISIBLE_UNIT_REC **ppVVar5;
  int iVar6;
  short *psVar7;
  
  iVar6 = 0;
  this->Player_Count = param_1;
  this->Category_Count = param_2 + 1;
  this->distanceTable = (uchar *)0x0;
  ppVVar1 = (VISIBLE_UNIT_PTR **)calloc(param_1,4);
  this->PlayerDataPtrs = ppVVar1;
  if (0 < this->Player_Count) {
    do {
      pVVar2 = (VISIBLE_UNIT_PTR *)calloc(this->Category_Count,8);
      iVar4 = 0;
      this->PlayerDataPtrs[iVar6] = pVVar2;
      if (0 < this->Category_Count) {
        psVar7 = &this->PlayerDataPtrs[iVar6]->used;
        do {
          psVar7[-1] = 0x20;
          *psVar7 = 0;
          pVVar3 = (VISIBLE_UNIT_REC *)calloc(0x20,8);
          ((VISIBLE_UNIT_PTR *)(psVar7 + -3))->unit_list = pVVar3;
          iVar4 = iVar4 + 1;
          psVar7 = psVar7 + 4;
        } while (iVar4 < this->Category_Count);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < this->Player_Count);
  }
  ppVVar5 = this->Return_Buffer;
  iVar6 = 0;
  do {
    pVVar3 = (VISIBLE_UNIT_REC *)malloc(0x800);
    *ppVVar5 = pVVar3;
    *(VISIBLE_UNIT_REC **)((int)&VisibleUnitList + iVar6) = pVVar3;
    *(undefined4 *)((int)&VisibleUnitList_Size + iVar6) = 0;
    iVar6 = iVar6 + 4;
    ppVVar5 = ppVVar5 + 1;
  } while (iVar6 < 0x14);
  Build_Distance_Table(this);
  VisibleUnitManager = this;
  return this;
}

// --------------------------------------------------

// Function: ~Visible_Unit_Manager
// Address: 0053b670
/* WARNING: Variable defined which should be unmapped: i */
/* public: __thiscall Visible_Unit_Manager::~Visible_Unit_Manager(void) */

void __thiscall Visible_Unit_Manager::~Visible_Unit_Manager(Visible_Unit_Manager *this)
{
  VISIBLE_UNIT_PTR *pVVar1;
  VISIBLE_UNIT_PTR *pVVar2;
  int iVar3;
  VISIBLE_UNIT_REC **ppVVar4;
  int i;
  int local_4;
  
  if (this->PlayerDataPtrs != (VISIBLE_UNIT_PTR **)0x0) {
    local_4 = 0;
    if (0 < this->Player_Count) {
      do {
        pVVar1 = this->PlayerDataPtrs[local_4];
        if (pVVar1 != (VISIBLE_UNIT_PTR *)0x0) {
          iVar3 = 0;
          pVVar2 = pVVar1;
          if (0 < this->Category_Count) {
            do {
              if (pVVar2->unit_list != (VISIBLE_UNIT_REC *)0x0) {
                free(pVVar2->unit_list);
              }
              iVar3 = iVar3 + 1;
              pVVar2 = pVVar2 + 1;
            } while (iVar3 < this->Category_Count);
          }
          free(pVVar1);
        }
        local_4 = local_4 + 1;
      } while (local_4 < this->Player_Count);
    }
    free(this->PlayerDataPtrs);
  }
  ppVVar4 = this->Return_Buffer;
  iVar3 = 0;
  do {
    if (*ppVVar4 != (VISIBLE_UNIT_REC *)0x0) {
      free(*ppVVar4);
    }
    *(undefined4 *)((int)&VisibleUnitList + iVar3) = 0;
    *(undefined4 *)((int)&VisibleUnitList_Size + iVar3) = 0;
    iVar3 = iVar3 + 4;
    ppVVar4 = ppVVar4 + 1;
  } while (iVar3 < 0x14);
  if (this->distanceTable != (uchar *)0x0) {
    free(this->distanceTable);
  }
  VisibleUnitManager = (Visible_Unit_Manager *)0x0;
  return;
}

// --------------------------------------------------

// Function: Build_Distance_Table
// Address: 0053b730
/* public: void __thiscall Visible_Unit_Manager::Build_Distance_Table(void) */

void __thiscall Visible_Unit_Manager::Build_Distance_Table(Visible_Unit_Manager *this)
{
  int *piVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar uVar6;
  int *piVar7;
  undefined **local_4;
  
  if (this->distanceTable != (uchar *)0x0) {
    free(this->distanceTable);
  }
  puVar2 = (uchar *)malloc(0x100);
  this->distanceTable = puVar2;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2[0] = 0xff;
    puVar2[1] = 0xff;
    puVar2[2] = 0xff;
    puVar2[3] = 0xff;
    puVar2 = puVar2 + 4;
  }
  uVar6 = '\0';
  local_4 = &NormalLOS;
  do {
    piVar7 = (int *)*local_4;
    iVar3 = *piVar7;
    while (iVar3 != 999) {
      iVar5 = piVar7[1];
      iVar4 = piVar7[2];
      if ((-1 < iVar3) && (iVar3 < 0x10)) {
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        if (0xf < iVar4) {
          iVar4 = 0xf;
        }
        iVar3 = iVar3 * 0x10 + iVar5;
        if (iVar5 <= iVar4) {
          iVar5 = (iVar4 - iVar5) + 1;
          do {
            if (this->distanceTable[iVar3] == 0xff) {
              this->distanceTable[iVar3] = uVar6;
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      piVar1 = piVar7 + 3;
      piVar7 = piVar7 + 3;
      iVar3 = *piVar1;
    }
    local_4 = local_4 + 1;
    uVar6 = uVar6 + '\x01';
  } while ((int)local_4 < 0x58ea51);
  return;
}

// --------------------------------------------------

// Function: Update_Unit_Info
// Address: 0053b7e0
/* public: void __thiscall Visible_Unit_Manager::Update_Unit_Info(int,int,int,int,int,unsigned
   long,unsigned long,struct VISIBLE_UNIT_REC * *) */

void __thiscall
Visible_Unit_Manager::Update_Unit_Info
          (Visible_Unit_Manager *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          ulong param_6,ulong param_7,VISIBLE_UNIT_REC **param_8)
{
  VISIBLE_UNIT_PTR *pVVar1;
  short sVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  int iVar6;
  VISIBLE_UNIT_REC *pVVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  VISIBLE_UNIT_REC *pVVar11;
  VISIBLE_UNIT_REC *pVVar12;
  int i;
  VISIBLE_UNIT_REC *r;
  
  uVar10 = (param_7 ^ param_6) & 0xffff;
  if ((param_5 < this->Category_Count) && (r = (VISIBLE_UNIT_REC *)0x0, 0 < this->Player_Count)) {
    iVar6 = 0x194 - (int)param_8;
    do {
      if (uVar10 == 0) {
        return;
      }
      if (((byte)uVar10 & 1) == 1) {
        pVVar1 = this->PlayerDataPtrs[(int)r] + param_5;
        if (((byte)param_7 & 1) == 1) {
          sVar2 = pVVar1->list_size;
          if (pVVar1->used == sVar2) {
            pVVar7 = (VISIBLE_UNIT_REC *)calloc(sVar2 * 2,8);
            pVVar11 = pVVar1->unit_list;
            pVVar12 = pVVar7;
            for (uVar8 = (uint)(sVar2 * 8) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              pVVar12->object_id = pVVar11->object_id;
              pVVar11 = (VISIBLE_UNIT_REC *)&pVVar11->distance;
              pVVar12 = (VISIBLE_UNIT_REC *)&pVVar12->distance;
            }
            for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
              *(char *)&pVVar12->object_id = (char)pVVar11->object_id;
              pVVar11 = (VISIBLE_UNIT_REC *)((int)&pVVar11->object_id + 1);
              pVVar12 = (VISIBLE_UNIT_REC *)((int)&pVVar12->object_id + 1);
            }
            free(pVVar1->unit_list);
            iVar9 = 0;
            pVVar1->unit_list = pVVar7;
            pVVar1->list_size = sVar2 * 2;
            if (0 < pVVar1->used) {
              do {
                if (VIS_UNIT_objectsValue[pVVar7->object_id] != (RGE_Static_Object *)0x0) {
                  *(VISIBLE_UNIT_REC **)
                   ((int)VIS_UNIT_objectsValue[pVVar7->object_id] + iVar6 + (int)param_8) = pVVar7;
                }
                iVar9 = iVar9 + 1;
                pVVar7 = pVVar7 + 1;
              } while (iVar9 < pVVar1->used);
            }
          }
          sVar2 = pVVar1->used;
          pVVar11 = pVVar1->unit_list;
          pVVar11[sVar2].distance = '\0';
          pVVar11 = pVVar11 + sVar2;
          pVVar11->object_id = param_1;
          pVVar11->player = (uchar)param_2;
          pVVar11->pos_x = (uchar)param_3;
          pVVar11->pos_y = (uchar)param_4;
          pVVar1->used = pVVar1->used + 1;
          *param_8 = pVVar11;
        }
        else {
          pVVar12 = *param_8;
          pVVar11 = pVVar1->unit_list + pVVar1->used + -1;
          if (pVVar11 != pVVar12) {
            pVVar12->object_id = pVVar11->object_id;
            uVar3 = pVVar11->player;
            uVar4 = pVVar11->pos_x;
            uVar5 = pVVar11->pos_y;
            pVVar12->distance = pVVar11->distance;
            pVVar12->player = uVar3;
            pVVar12->pos_x = uVar4;
            pVVar12->pos_y = uVar5;
            if (VIS_UNIT_objectsValue[pVVar12->object_id] != (RGE_Static_Object *)0x0) {
              *(VISIBLE_UNIT_REC **)
               ((int)VIS_UNIT_objectsValue[pVVar12->object_id] + iVar6 + (int)param_8) = pVVar12;
            }
          }
          *param_8 = (VISIBLE_UNIT_REC *)0x0;
          pVVar1->used = pVVar1->used + -1;
        }
      }
      param_8 = param_8 + 1;
      param_7 = param_7 >> 1;
      uVar10 = uVar10 >> 1;
      r = (VISIBLE_UNIT_REC *)((int)&r->object_id + 1);
    } while ((int)r < this->Player_Count);
  }
  return;
}

// --------------------------------------------------

// Function: GetVisibleUnits
// Address: 0053b9a0
/* public: int __thiscall Visible_Unit_Manager::GetVisibleUnits(int,int,int,int,int *,int,int *) */

int __thiscall
Visible_Unit_Manager::GetVisibleUnits
          (Visible_Unit_Manager *this,int param_1,int param_2,int param_3,int param_4,int *param_5,
          int param_6,int *param_7)
{
  byte bVar1;
  undefined1 uVar7;
  undefined1 uVar9;
  uchar *puVar2;
  VISIBLE_UNIT_PTR *pVVar3;
  int iVar4;
  int *piVar5;
  VISIBLE_UNIT_REC **ppVVar6;
  undefined1 uVar11;
  VISIBLE_UNIT_REC *pVVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  VISIBLE_UNIT_REC *pVVar16;
  int count;
  VISIBLE_UNIT_PTR *PDP;
  int x2;
  int x1;
  int y2;
  int y1;
  int found;
  undefined3 uVar8;
  undefined2 uVar10;
  
  found = 0;
  if (param_6 < 1) {
    return 0;
  }
  if (this->Player_Count <= param_4) {
    return 0;
  }
  if (0xf < param_3) {
    param_3 = 0xf;
  }
  puVar2 = this->distanceTable;
  pVVar3 = this->PlayerDataPtrs[param_4];
  VisibleUnitList_Size = (int *)0x0;
  DAT_0087d7cc = 0;
  DAT_0087d7d0 = 0;
  DAT_0087d7d4 = 0;
  DAT_0087d7d8 = 0;
  do {
                    /* Symbol Ref: {@symbol start} */
    iVar4 = *param_5;
    param_5 = param_5 + 1;
    pVVar16 = pVVar3[iVar4].unit_list;
    for (uVar13 = *(uint *)&pVVar3[iVar4].used & 0xffff; uVar13 != 0; uVar13 = uVar13 - 1) {
                    /* Symbol Ref: {@symbol scan_list} */
      uVar15 = (uint)pVVar16->pos_x;
      if ((int)uVar15 <= param_1 + param_3) {
        if ((int)uVar15 < param_1) {
          if ((int)uVar15 < param_1 - param_3) goto LAB_0053baff;
          uVar15 = param_1 - uVar15;
        }
        else {
                    /* Symbol Ref: {@symbol do_ypos2} */
          uVar15 = uVar15 - param_1;
        }
                    /* Symbol Ref: {@symbol do_ypos} */
        uVar14 = (uint)pVVar16->pos_y;
        if ((int)uVar14 <= param_3 + param_2) {
          if ((int)uVar14 < param_2) {
            if ((int)uVar14 < param_2 - param_3) goto LAB_0053baff;
            uVar14 = param_2 - uVar14;
          }
          else {
                    /* Symbol Ref: {@symbol do_dist2} */
            uVar14 = uVar14 - param_2;
          }
                    /* Symbol Ref: {@symbol do_dist} */
          bVar1 = puVar2[(uVar15 & 0xf) + (uVar14 & 0xf) * 0x10];
          if ((int)(uint)bVar1 <= param_3) {
            iVar4 = param_7[pVVar16->player];
            piVar5 = (&VisibleUnitList_Size)[iVar4];
            if ((int)piVar5 < 0x100) {
              ppVVar6 = (&VisibleUnitList)[iVar4];
              (&VisibleUnitList_Size)[iVar4] = (int *)((int)piVar5 + 1);
              uVar7 = pVVar16->player;
              uVar9 = pVVar16->pos_x;
              uVar11 = pVVar16->pos_y;
              uVar10 = CONCAT11(uVar11,uVar9);
              uVar8 = CONCAT21(uVar10,uVar7);
              pVVar12 = (VISIBLE_UNIT_REC *)CONCAT31(uVar8,bVar1);
              found = found + 1;
              ppVVar6[(int)piVar5 * 2] = (VISIBLE_UNIT_REC *)pVVar16->object_id;
              (ppVVar6 + (int)piVar5 * 2)[1] = pVVar12;
            }
          }
        }
      }
LAB_0053baff:
                    /* Symbol Ref: {@symbol next_entry} */
      pVVar16 = pVVar16 + 1;
    }
                    /* Symbol Ref: {@symbol empty_list} */
    param_6 = param_6 + -1;
    if (param_6 == 0) {
      return found;
    }
  } while( true );
}

// --------------------------------------------------


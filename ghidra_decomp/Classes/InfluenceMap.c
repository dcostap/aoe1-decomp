// Class: InfluenceMap
// Size:  0x28
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] `vector_deleting_destructor'
// [02] copy_obj
// [03] modify
// [04] modify_delta
// [05] modify_percent
// [06] save
// [07] make_new_obj
// [08] make_new_master
// [09] check_placement
// [10] alignment
// [11] calc_base_damage_ability
// [12] play_command_sound
// [13] play_move_sound
// [14] draw
// [15] create_task_list
//
// Member Layout:
// [0x004] int xSizeValue
// [0x008] int ySizeValue
// [0x00C] int xReferencePointValue
// [0x010] int yReferencePointValue
// [0x014] uchar * valueValue
// [0x018] uchar * * rowValue
// [0x01C] int coverageCountValue
// [0x020] int connectionCountValue
// [0x024] uchar unchangeableLimitValue
// ----------------------------------------------------------------

// Function: InfluenceMap
// Address: 0044df80
InfluenceMap * __thiscall
InfluenceMap::InfluenceMap(InfluenceMap *this,int param_1,int param_2,uchar param_3)
{
  uint uVar1;
  uchar *puVar2;
  uchar **ppuVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  this->ySizeValue = param_2;
  uVar1 = param_2 * param_1;
  this->xSizeValue = param_1;
  this->xReferencePointValue = 0;
  this->yReferencePointValue = 0;
  this->_padding_ = (int)&_vftable_;
  puVar2 = (uchar *)operator_new(uVar1);
  this->valueValue = puVar2;
  for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(uint *)puVar2 = CONCAT22(CONCAT11(param_3,param_3),CONCAT11(param_3,param_3));
    puVar2 = puVar2 + 4;
  }
  for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = param_3;
    puVar2 = puVar2 + 1;
  }
  ppuVar3 = (uchar **)operator_new(this->ySizeValue << 2);
  this->rowValue = ppuVar3;
  if (ppuVar3 != (uchar **)0x0) {
    iVar4 = 0;
    iVar6 = 0;
    if (0 < this->ySizeValue) {
      do {
        this->rowValue[iVar4] = this->valueValue + iVar6;
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + this->xSizeValue;
      } while (iVar4 < this->ySizeValue);
    }
  }
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0044e030
void * __thiscall InfluenceMap::_scalar_deleting_destructor_(InfluenceMap *this,uint param_1)
{
  ~InfluenceMap(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: InfluenceMap
// Address: 0044e050
InfluenceMap * __thiscall InfluenceMap::InfluenceMap(InfluenceMap *this,int param_1)
{
  this->xSizeValue = -1;
  this->ySizeValue = -1;
  this->_padding_ = (int)&_vftable_;
  this->xReferencePointValue = 0;
  this->yReferencePointValue = 0;
  load(this,param_1);
  return this;
}

// --------------------------------------------------

// Function: ~InfluenceMap
// Address: 0044e080
void __thiscall InfluenceMap::~InfluenceMap(InfluenceMap *this)
{
  this->_padding_ = (int)&_vftable_;
  if (this->valueValue != (uchar *)0x0) {
    operator_delete(this->valueValue);
  }
  if (this->rowValue != (uchar **)0x0) {
    operator_delete(this->rowValue);
  }
  return;
}

// --------------------------------------------------

// Function: initialize
// Address: 0044e0b0
int __thiscall InfluenceMap::initialize(InfluenceMap *this,uchar param_1)
{
  uint uVar1;
  uint uVar2;
  uchar *puVar3;
  
  uVar1 = this->ySizeValue * this->xSizeValue;
  puVar3 = this->valueValue;
  for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(uint *)puVar3 = CONCAT22(CONCAT11(param_1,param_1),CONCAT11(param_1,param_1));
    puVar3 = puVar3 + 4;
  }
  for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar3 = param_1;
    puVar3 = puVar3 + 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: save
// Address: 0044e0f0
void __thiscall InfluenceMap::save(InfluenceMap *this,int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1;
  piVar1 = &this->xSizeValue;
  rge_write(param_1,piVar1,4);
  rge_write(param_1,&this->ySizeValue,4);
  rge_write(param_1,&this->xReferencePointValue,4);
  rge_write(param_1,&this->yReferencePointValue,4);
  rge_write(param_1,&this->unchangeableLimitValue,1);
  param_1 = 0;
  if (0 < this->ySizeValue) {
    do {
      iVar3 = 0;
      if (0 < *piVar1) {
        do {
          rge_write(iVar2,this->rowValue[param_1] + iVar3,1);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *piVar1);
      }
      param_1 = param_1 + 1;
    } while (param_1 < this->ySizeValue);
  }
  return;
}

// --------------------------------------------------

// Function: load
// Address: 0044e1a0
void __thiscall InfluenceMap::load(InfluenceMap *this,int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int j;
  int local_4;
  
  iVar2 = param_1;
  piVar1 = &this->xSizeValue;
  rge_read(param_1,piVar1,4);
  rge_read(iVar2,&this->ySizeValue,4);
  rge_read(iVar2,&this->xReferencePointValue,4);
  rge_read(iVar2,&this->yReferencePointValue,4);
  rge_read(iVar2,&this->unchangeableLimitValue,1);
  local_4 = 0;
  if (0 < this->ySizeValue) {
    do {
      iVar3 = 0;
      if (0 < *piVar1) {
        do {
          rge_read(iVar2,&param_1,1);
          iVar4 = iVar3 + 1;
          this->rowValue[local_4][iVar3] = (uchar)param_1;
          iVar3 = iVar4;
        } while (iVar4 < *piVar1);
      }
      local_4 = local_4 + 1;
    } while (local_4 < this->ySizeValue);
  }
  return;
}

// --------------------------------------------------

// Function: printToFile
// Address: 0044e250
// [HELPER] s_FILENAME___s_: "FILENAME: %s\n"
// [HELPER] s_R_03d__: "R%03d: "
// [HELPER] s__03d_: "%03d "
// [HELPER] s__: "}"
// [HELPER] s__R_03d_: ":R%03d\n"
// [HELPER] s__R_03d__: ":R%03d\n\n"
// [HELPER] s___03d_: " %03d "
// [HELPER] s___Dimensions___d_X__d_: "  Dimensions: %d X %d\n"
// [HELPER] s___Reference_Point____d___d__: "  Reference Point: (%d, %d)\n"
// [HELPER] s_____: "--- "
// [HELPER] s______: "---- "
// [HELPER] s_______: "      "
// [HELPER] s_wa: "wa"
void __thiscall InfluenceMap::printToFile(InfluenceMap *this,char *param_1)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_1 != (char *)0x0) {
    iVar1 = fopen(param_1,s_wa);
    if (iVar1 != 0) {
      fprintf(iVar1,s_FILENAME___s_,param_1);
      fprintf(iVar1,s___Dimensions___d_X__d_,this->xSizeValue,this->ySizeValue);
      fprintf(iVar1,s___Reference_Point____d___d__,this->xReferencePointValue,
              this->yReferencePointValue);
      fprintf(iVar1,&s__);
      fprintf(iVar1,s_______);
      iVar2 = 0;
      if (0 < this->xSizeValue) {
        do {
          if (iVar2 % 5 == 0) {
            pcVar3 = s___03d_;
          }
          else {
            pcVar3 = s__03d_;
          }
          fprintf(iVar1,pcVar3,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < this->xSizeValue);
      }
      fprintf(iVar1,&s__);
      fprintf(iVar1,s_______);
      iVar2 = 0;
      if (0 < this->xSizeValue) {
        do {
          if (iVar2 % 5 == 0) {
            pcVar3 = s______;
          }
          else {
            pcVar3 = s_____;
          }
          fprintf(iVar1,pcVar3,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < this->xSizeValue);
      }
      fprintf(iVar1,&s__);
      param_1 = (char *)0x0;
      if (0 < this->ySizeValue) {
        do {
          fprintf(iVar1,s_R_03d__,param_1);
          iVar2 = 0;
          if (0 < this->xSizeValue) {
            do {
              if (iVar2 % 5 == 0) {
                pcVar3 = s___03d_;
              }
              else {
                pcVar3 = s__03d_;
              }
              fprintf(iVar1,pcVar3,this->rowValue[(int)param_1][iVar2]);
              iVar2 = iVar2 + 1;
            } while (iVar2 < this->xSizeValue);
          }
          pcVar3 = param_1 + 1;
          if ((int)pcVar3 % 5 == 0) {
            pcVar4 = s__R_03d__;
          }
          else {
            pcVar4 = s__R_03d_;
          }
          fprintf(iVar1,pcVar4,param_1);
          param_1 = pcVar3;
        } while ((int)pcVar3 < this->ySizeValue);
      }
      fprintf(iVar1,s_______);
      iVar2 = 0;
      if (0 < this->xSizeValue) {
        do {
          if (iVar2 % 5 == 0) {
            pcVar3 = s______;
          }
          else {
            pcVar3 = s_____;
          }
          fprintf(iVar1,pcVar3,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < this->xSizeValue);
      }
      fprintf(iVar1,&s__);
      fprintf(iVar1,s_______);
      iVar2 = 0;
      if (0 < this->xSizeValue) {
        do {
          if (iVar2 % 5 == 0) {
            pcVar3 = s___03d_;
          }
          else {
            pcVar3 = s__03d_;
          }
          fprintf(iVar1,pcVar3,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < this->xSizeValue);
      }
      fprintf(iVar1,&s__);
      fclose(iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: setReferencePoint
// Address: 0044e4c0
void __thiscall InfluenceMap::setReferencePoint(InfluenceMap *this,int param_1,int param_2)
{
  this->xReferencePointValue = param_1;
  this->yReferencePointValue = param_2;
  return;
}

// --------------------------------------------------

// Function: lookupValue
// Address: 0044e4e0
int __thiscall InfluenceMap::lookupValue(InfluenceMap *this,int param_1,int param_2)
{
  return (uint)this->rowValue[param_2 - this->yReferencePointValue]
               [param_1 - this->xReferencePointValue];
}

// --------------------------------------------------

// Function: setValue
// Address: 0044e510
int __thiscall InfluenceMap::setValue(InfluenceMap *this,int param_1,int param_2,uchar param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 - this->xReferencePointValue;
  iVar2 = param_2 - this->yReferencePointValue;
  if ((((-1 < iVar1) && (-1 < iVar2)) && (iVar1 < this->xSizeValue)) && (iVar2 < this->ySizeValue))
{
    this->rowValue[iVar2][iVar1] = param_3;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: setValue
// Address: 0044e560
int __thiscall
InfluenceMap::setValue
          (InfluenceMap *this,int param_1,int param_2,int param_3,int param_4,uchar param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_3 - this->xReferencePointValue;
  iVar5 = param_1 - this->xReferencePointValue;
  iVar2 = param_2 - this->yReferencePointValue;
  iVar3 = param_4 - this->yReferencePointValue;
  if (((((-1 < iVar5) && (-1 < iVar2)) && (iVar5 < this->xSizeValue)) &&
      ((iVar2 < this->ySizeValue && (-1 < iVar4)))) &&
     ((-1 < iVar3 && ((iVar4 < this->xSizeValue && (iVar3 < this->ySizeValue)))))) {
    for (; iVar1 = iVar5, iVar2 <= iVar3; iVar2 = iVar2 + 1) {
      for (; iVar1 <= iVar4; iVar1 = iVar1 + 1) {
        this->rowValue[iVar2][iVar1] = param_5;
      }
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: incrementValue
// Address: 0044e600
int __thiscall
InfluenceMap::incrementValue(InfluenceMap *this,int param_1,int param_2,uchar param_3)
{
  uchar *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = param_1 - this->xReferencePointValue;
  iVar5 = param_2 - this->yReferencePointValue;
  if ((((iVar4 < 0) || (iVar5 < 0)) || (this->xSizeValue <= iVar4)) || (this->ySizeValue <= iVar5))
{
    return 0;
  }
  bVar2 = this->unchangeableLimitValue;
  puVar1 = this->rowValue[iVar5] + iVar4;
  bVar3 = this->rowValue[iVar5][iVar4];
  if (bVar2 <= bVar3) {
    return 1;
  }
  uVar6 = (uint)param_3 + (uint)bVar3;
  if (bVar2 <= uVar6) {
    *puVar1 = bVar2 - 1;
    return 1;
  }
  *puVar1 = (uchar)uVar6;
  return 1;
}

// --------------------------------------------------

// Function: incrementValue
// Address: 0044e680
int __thiscall
InfluenceMap::incrementValue
          (InfluenceMap *this,int param_1,int param_2,int param_3,int param_4,uchar param_5)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_1 - this->xReferencePointValue;
  iVar5 = param_3 - this->xReferencePointValue;
  iVar4 = param_2 - this->yReferencePointValue;
  iVar3 = param_4 - this->yReferencePointValue;
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  else if (this->xSizeValue <= iVar6) {
    iVar6 = this->xSizeValue + -1;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  else if (this->xSizeValue <= iVar4) {
    iVar4 = this->xSizeValue + -1;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (this->xSizeValue <= iVar5) {
    iVar5 = this->xSizeValue + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (this->xSizeValue <= iVar3) {
    iVar3 = this->xSizeValue + -1;
  }
  if (iVar4 <= iVar3) {
    param_2 = iVar4 * 4;
    param_4 = (iVar3 - iVar4) + 1;
    iVar4 = iVar6;
    do {
      for (; iVar4 <= iVar5; iVar4 = iVar4 + 1) {
        bVar1 = this->unchangeableLimitValue;
        iVar3 = *(int *)(param_2 + (int)this->rowValue);
        if (*(byte *)(iVar4 + iVar3) < bVar1) {
          uVar2 = (uint)param_5 + (uint)*(byte *)(iVar4 + iVar3);
          if (uVar2 < bVar1) {
            *(char *)(iVar4 + iVar3) = (char)uVar2;
          }
          else {
            *(char *)(iVar4 + iVar3) = bVar1 - 1;
          }
        }
      }
      param_2 = param_2 + 4;
      param_4 = param_4 + -1;
      iVar4 = iVar6;
    } while (param_4 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: decrementValue
// Address: 0044e790
int __thiscall
InfluenceMap::decrementValue(InfluenceMap *this,int param_1,int param_2,uchar param_3)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1 - this->xReferencePointValue;
  iVar4 = param_2 - this->yReferencePointValue;
  if ((((-1 < iVar2) && (-1 < iVar4)) && (iVar2 < this->xSizeValue)) && (iVar4 < this->ySizeValue))
{
    bVar1 = this->rowValue[iVar4][iVar2];
    if (this->unchangeableLimitValue <= bVar1) {
      return 1;
    }
    iVar3 = (uint)bVar1 - (uint)param_3;
    this->rowValue[iVar4][iVar2] = (iVar3 < 0) - 1U & (byte)iVar3;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: decrementValue
// Address: 0044e800
int __thiscall
InfluenceMap::decrementValue
          (InfluenceMap *this,int param_1,int param_2,int param_3,int param_4,uchar param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  param_1 = param_1 - this->xReferencePointValue;
  param_3 = param_3 - this->xReferencePointValue;
  iVar3 = param_2 - this->yReferencePointValue;
  iVar2 = param_4 - this->yReferencePointValue;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (this->xSizeValue <= param_1) {
    param_1 = this->xSizeValue + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (this->xSizeValue <= iVar3) {
    iVar3 = this->xSizeValue + -1;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (this->xSizeValue <= param_3) {
    param_3 = this->xSizeValue + -1;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (this->xSizeValue <= iVar2) {
    iVar2 = this->xSizeValue + -1;
  }
  if (iVar3 <= iVar2) {
    param_2 = (iVar2 - iVar3) + 1;
    iVar3 = iVar3 * 4;
    iVar2 = param_1;
    do {
      for (; iVar2 <= param_3; iVar2 = iVar2 + 1) {
        if (*(byte *)(iVar2 + *(int *)((int)this->rowValue + iVar3)) < this->unchangeableLimitValue)
{
          pbVar4 = (byte *)(*(int *)((int)this->rowValue + iVar3) + iVar2);
          iVar1 = (uint)*pbVar4 - (uint)param_5;
          *pbVar4 = (iVar1 < 0) - 1U & (byte)iVar1;
        }
      }
      iVar3 = iVar3 + 4;
      param_2 = param_2 + -1;
      iVar2 = param_1;
    } while (param_2 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: setCoverageCount
// Address: 0044e900
int __thiscall
InfluenceMap::setCoverageCount(InfluenceMap *this,XYPoint *param_1,XYPoint *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int i;
  
  this->coverageCountValue = 0;
  iVar4 = param_1->x;
  if (((((-1 < iVar4) && (-1 < param_1->y)) && (iVar4 < this->xSizeValue)) &&
      ((param_1->y < this->ySizeValue && (iVar3 = param_2->x, -1 < iVar3)))) &&
     ((iVar1 = param_2->y, -1 < iVar1 && ((iVar3 < this->xSizeValue && (iVar1 < this->ySizeValue))))
     )) {
    if (iVar4 <= iVar3) {
      do {
        iVar3 = param_1->y;
        if (iVar3 <= iVar1) {
          iVar2 = iVar3 * 4;
          do {
            if (param_3 <=
                (int)(uint)*(byte *)(*(int *)(iVar2 + this->yReferencePointValue * -4 +
                                             (int)this->rowValue) +
                                    (iVar4 - this->xReferencePointValue))) {
              this->coverageCountValue = this->coverageCountValue + 1;
            }
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 4;
            iVar1 = param_2->y;
          } while (iVar3 <= iVar1);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= param_2->x);
    }
    return this->coverageCountValue;
  }
  return 0;
}

// --------------------------------------------------

// Function: setConnectionCount
// Address: 0044e9e0
int __thiscall
InfluenceMap::setConnectionCount
          (InfluenceMap *this,XYPoint *param_1,XYPoint *param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int j;
  int local_1c;
  int i;
  
  this->connectionCountValue = 0;
  iVar7 = param_1->x;
  if ((((iVar7 < 0) || (param_1->y < 0)) || (iVar1 = this->xSizeValue, iVar1 <= iVar7)) ||
     (((iVar2 = this->ySizeValue, iVar2 <= param_1->y || (iVar4 = param_2->x, iVar4 < 0)) ||
      ((iVar6 = param_2->y, iVar6 < 0 || ((iVar1 <= iVar4 || (iVar2 <= iVar6)))))))) {
    return 0;
  }
  if (iVar7 <= iVar4) {
    do {
      local_1c = param_1->y;
      if (local_1c <= iVar6) {
        j = local_1c * 4;
        do {
          if (param_3 <=
              (int)(uint)*(byte *)(*(int *)(j + this->yReferencePointValue * -4 +
                                           (int)this->rowValue) +
                                  (iVar7 - this->xReferencePointValue))) {
            uVar5 = 0;
            iVar4 = local_1c;
            iVar6 = j;
            iVar8 = iVar7;
            do {
              switch(uVar5) {
              case 0:
                iVar8 = iVar8 + -1;
              case 7:
                iVar4 = iVar4 + -1;
                iVar6 = iVar6 + -4;
                break;
              case 1:
              case 2:
                iVar8 = iVar8 + 1;
                break;
              case 3:
              case 4:
                iVar4 = iVar4 + 1;
                iVar6 = iVar6 + 4;
                break;
              case 5:
              case 6:
                iVar8 = iVar8 + -1;
              }
              uVar3 = (int)uVar5 >> 0x1f;
              if ((param_6 != 0) || (((uVar5 ^ uVar3) - uVar3 & 1 ^ uVar3) != uVar3)) {
                if ((iVar8 < 0) || (((iVar1 <= iVar8 || (iVar4 < 0)) || (iVar2 <= iVar4)))) {
                  if (((param_4 == 1) && (((uVar5 ^ uVar3) - uVar3 & 1 ^ uVar3) - uVar3 == 1)) ||
                     ((param_5 == 1 && (((uVar5 ^ uVar3) - uVar3 & 1 ^ uVar3) == uVar3))))
                  goto LAB_0044eb54;
                }
                else if (param_3 <=
                         (int)(uint)*(byte *)((*(int *)(iVar6 + this->yReferencePointValue * -4 +
                                                       (int)this->rowValue) + iVar8) -
                                             this->xReferencePointValue)) {
LAB_0044eb54:
                  this->connectionCountValue = this->connectionCountValue + 1;
                }
              }
              uVar5 = uVar5 + 1;
            } while ((int)uVar5 < 8);
          }
          j = j + 4;
          local_1c = local_1c + 1;
          iVar6 = param_2->y;
        } while (local_1c <= iVar6);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= param_2->x);
  }
  return this->connectionCountValue;
}

// --------------------------------------------------

// Function: coverageIncluding
// Address: 0044ec00
int __thiscall
InfluenceMap::coverageIncluding
          (InfluenceMap *this,XYPoint *param_1,XYPoint *param_2,uchar param_3,uchar param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int rVal;
  int local_10;
  
  local_10 = this->coverageCountValue;
  iVar7 = param_1->x;
  if (((((-1 < iVar7) && (iVar1 = param_1->y, -1 < iVar1)) && (iVar7 < this->xSizeValue)) &&
      ((iVar1 < this->ySizeValue && (iVar2 = param_2->x, -1 < iVar2)))) &&
     ((iVar3 = param_2->y, -1 < iVar3 && ((iVar2 < this->xSizeValue && (iVar3 < this->ySizeValue))))
     )) {
    for (; iVar7 <= iVar2; iVar7 = iVar7 + 1) {
      if (iVar1 <= iVar3) {
        iVar6 = iVar7 - this->xReferencePointValue;
        iVar5 = iVar1 * 4;
        iVar4 = (iVar3 - iVar1) + 1;
        do {
          if ((*(byte *)(*(int *)(iVar5 + this->yReferencePointValue * -4 + (int)this->rowValue) +
                        iVar6) < param_3) &&
             ((uint)param_3 <=
              (uint)*(byte *)(*(int *)(iVar5 + this->yReferencePointValue * -4 + (int)this->rowValue
                                      ) + iVar6) + (uint)param_4)) {
            local_10 = local_10 + 1;
          }
          iVar5 = iVar5 + 4;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    return local_10;
  }
  return 0;
}

// --------------------------------------------------

// Function: connectionsIncluding
// Address: 0044ed20
int __thiscall
InfluenceMap::connectionsIncluding
          (InfluenceMap *this,XYPoint *param_1,XYPoint *param_2,uchar param_3,uchar param_4,
          int param_5,int param_6,int param_7)
{
  XYPoint *pXVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar **ppuVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  XYPoint *pXVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int rVal;
  int i;
  
  iVar11 = param_1->x;
  iVar13 = this->connectionCountValue;
  if ((((iVar11 < 0) || (pXVar1 = (XYPoint *)param_1->y, (int)pXVar1 < 0)) ||
      (iVar2 = this->xSizeValue, iVar2 <= iVar11)) ||
     (((iVar3 = this->ySizeValue, iVar3 <= (int)pXVar1 || (iVar4 = param_2->x, iVar4 < 0)) ||
      ((iVar5 = param_2->y, iVar5 < 0 || ((iVar2 <= iVar4 || (i = iVar13, iVar3 <= iVar5)))))))) {
    return 0;
  }
  do {
    if (iVar4 < iVar11) {
      return iVar13;
    }
    if ((int)pXVar1 <= iVar5) {
      ppuVar6 = this->rowValue;
      iVar9 = iVar11 - this->xReferencePointValue;
      iVar8 = (int)pXVar1 * 4;
      iVar7 = this->yReferencePointValue;
      param_1 = pXVar1;
      do {
        if ((uint)param_3 <=
            (uint)*(byte *)(*(int *)(iVar8 + iVar7 * -4 + (int)ppuVar6) + iVar9) + (uint)param_4) {
          if (param_3 <= *(byte *)(*(int *)(iVar8 + iVar7 * -4 + (int)ppuVar6) + iVar9)) {
            uVar14 = 0;
            pXVar12 = param_1;
            iVar16 = iVar11;
            do {
              switch(uVar14) {
              case 0:
                iVar16 = iVar16 + -1;
              case 7:
                pXVar12 = (XYPoint *)((int)&pXVar12[-1].y + 3);
                break;
              case 1:
              case 2:
                iVar16 = iVar16 + 1;
                break;
              case 3:
              case 4:
                pXVar12 = (XYPoint *)((int)&pXVar12->x + 1);
                break;
              case 5:
              case 6:
                iVar16 = iVar16 + -1;
              }
              uVar10 = (int)uVar14 >> 0x1f;
              if ((param_7 != 0) || (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) != uVar10)) {
                if (((iVar16 < 0) ||
                    (((iVar2 <= iVar16 || ((int)pXVar12 < 0)) || (iVar3 <= (int)pXVar12)))) &&
                   (((param_5 == 1 && (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) - uVar10 == 1)) ||
                    ((param_6 == 1 && (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))))) {
                  iVar13 = iVar13 + -1;
                }
                i = iVar13;
                if (iVar13 < 1) break;
              }
              uVar14 = uVar14 + 1;
              i = iVar13;
            } while ((int)uVar14 < 8);
          }
          uVar14 = 0;
          pXVar12 = param_1;
          iVar16 = iVar8;
          iVar15 = iVar11;
          do {
            switch(uVar14) {
            case 0:
              iVar15 = iVar15 + -1;
            case 7:
              pXVar12 = (XYPoint *)((int)&pXVar12[-1].y + 3);
              iVar16 = iVar16 + -4;
              break;
            case 1:
            case 2:
              iVar15 = iVar15 + 1;
              break;
            case 3:
            case 4:
              pXVar12 = (XYPoint *)((int)&pXVar12->x + 1);
              iVar16 = iVar16 + 4;
              break;
            case 5:
            case 6:
              iVar15 = iVar15 + -1;
            }
            uVar10 = (int)uVar14 >> 0x1f;
            if ((param_7 != 0) || (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) != uVar10)) {
              if ((iVar15 < 0) ||
                 (((iVar2 <= iVar15 || ((int)pXVar12 < 0)) || (iVar3 <= (int)pXVar12)))) {
                if (((param_5 == 1) && (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) - uVar10 == 1)) ||
                   ((param_6 == 1 && (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))) {
                  i = i + -1;
                }
              }
              else if (param_3 <=
                       *(byte *)((*(int *)(iVar16 + iVar7 * -4 + (int)ppuVar6) + iVar15) -
                                this->xReferencePointValue)) {
                i = i + 2;
              }
            }
            uVar14 = uVar14 + 1;
            iVar13 = i;
          } while ((int)uVar14 < 8);
        }
        param_1 = (XYPoint *)((int)&param_1->x + 1);
        iVar8 = iVar8 + 4;
      } while ((int)param_1 <= iVar5);
    }
    iVar11 = iVar11 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: setUnchangeableLimit
// Address: 0044f030
void __thiscall InfluenceMap::setUnchangeableLimit(InfluenceMap *this,uchar param_1)
{
  if (param_1 != '\0') {
    this->unchangeableLimitValue = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: maxValue
// Address: 0044f040
int __thiscall InfluenceMap::maxValue(InfluenceMap *this)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = this->xSizeValue * this->ySizeValue;
  iVar3 = 0;
  uVar1 = (uint)*this->valueValue;
  if (0 < iVar4) {
    do {
      uVar2 = (uint)this->valueValue[iVar3];
      if (uVar1 < uVar2) {
        uVar1 = uVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  return uVar1;
}

// --------------------------------------------------


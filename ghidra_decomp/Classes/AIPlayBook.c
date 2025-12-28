// Class: AIPlayBook
// Size:  0x50
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] convertTargetNameToIntType
// [02] convertTargetCharacteristicNameToIntType
// [03] convertUnitNameToIntType
// [04] convertUnitToIntType
//
// Member Layout:
// [0x004] int numberPlaysValue
// [0x008] char[65] nameValue (sz: 0x41)
// [0x04C] AIPlay * plays
// ----------------------------------------------------------------

// Function: AIPlayBook
// Address: 004101b0
/* public: __thiscall AIPlayBook::AIPlayBook(void) */

void __thiscall AIPlayBook::AIPlayBook(AIPlayBook *this)
{
  this->numberPlaysValue = 0;
  this->plays = (AIPlay *)0x0;
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 004101d0
/* public: virtual void * __thiscall AIPlayBook::`vector deleting destructor'(unsigned int) */

void * __thiscall AIPlayBook::_vector_deleting_destructor_(AIPlayBook *this,uint param_1)
{
  ~AIPlayBook(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~AIPlayBook
// Address: 004101f0
/* public: virtual __thiscall AIPlayBook::~AIPlayBook(void) */

void __thiscall AIPlayBook::~AIPlayBook(AIPlayBook *this)
{
  this->_padding_ = (int)&_vftable_;
  if (this->plays != (AIPlay *)0x0) {
    this->numberPlaysValue = 0;
    operator_delete(this->plays);
    this->plays = (AIPlay *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: loadPlays
// Address: 00410220
// [HELPER] s_: ""
// [HELPER] s_Balance: "Balance"
// [HELPER] s_DeathPercentage: "DeathPercentage"
// [HELPER] s_EndPlay: "EndPlay"
// [HELPER] s_FirstGroup: "FirstGroup"
// [HELPER] s_Group: "Group"
// [HELPER] s_Intelligence: "Intelligence"
// [HELPER] s_MaxUnits: "MaxUnits"
// [HELPER] s_MinUnits: "MinUnits"
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
// [HELPER] s_NumberGroups: "NumberGroups"
// [HELPER] s_Overflow: "Overflow"
// [HELPER] s_Phase: "Phase"
// [HELPER] s_Play: "Play"
// [HELPER] s_PlayType: "PlayType"
// [HELPER] s_Power: "Power"
// [HELPER] s_RTrigger: "RTrigger"
// [HELPER] s_TargetChar: "TargetChar"
// [HELPER] s_TargetType: "TargetType"
// [HELPER] s_Trigger: "Trigger"
// [HELPER] s___c_c: " %c%c"
// [HELPER] s___s__d_: "%*s %d "
// [HELPER] s___s__d__s__d____d_: "%*s %d %s %d - %d "
// [HELPER] s___s__d__s__d__d_: "%*s %d %s %d %d "
// [HELPER] s___s__d__s__d__d__d_: "%*s %d %s %d %d %d "
// [HELPER] s___s__s_: "%*s %s "
// [HELPER] s__s: "%s"
// [HELPER] s__sF_d: "%sF%d"
// [HELPER] s__s_: "%s\n"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: temp3 */
/* public: int __thiscall AIPlayBook::loadPlays(char *) */

int __thiscall AIPlayBook::loadPlays(AIPlayBook *this,char *param_1)
{
  char cVar1;
  uchar uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  AIPlay *pAVar6;
  AIPlay *pAVar7;
  AIPlayGroup *pAVar8;
  AIPlayPhase *pAVar9;
  AIPlayPhaseCommand *pAVar10;
  AIPlayPhaseTrigger *pAVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  AIPlayPhase *pAVar15;
  byte *pbVar16;
  char *pcVar17;
  byte *pbVar18;
  char *pcVar19;
  undefined4 *unaff_FS_OFFSET;
  bool bVar20;
  int iVar21;
  int temp3;
  int temp4;
  int iStack_3b0;
  char commentTemp2;
  int currentPhase;
  int iStack_3a8;
  char commentTemp1;
  int j;
  AIPlayPhase *curPhase;
  int a;
  int currentPlay;
  AIPlayPhase *refPhase;
  int temp5;
  int i;
  int temp8;
  int temp7;
  _iobuf *fileIn;
  XYZ rotatedPoint;
  XYZ originalPoint;
  XYZ origin;
  char temp2 [256];
  AIPlayPhaseCommand command;
  AIPlayPhaseCommand newCommand;
  char temp [256];
  AIPlayPhaseTrigger trigger;
  AIPlayPhaseTrigger trigger_fffffedc;
  char temp6 [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c73e;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 == (char *)0x0) {
LAB_004112e9:
    pcVar14 = &s_NULL;
LAB_004112fb:
    uVar12 = 0xffffffff;
    do {
      pcVar17 = pcVar14;
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      pcVar17 = pcVar14 + 1;
      cVar1 = *pcVar14;
      pcVar14 = pcVar17;
    } while (cVar1 != '\0');
    uVar12 = ~uVar12;
    pcVar14 = pcVar17 + -uVar12;
    pcVar17 = this->nameValue;
    for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar14;
      pcVar14 = pcVar14 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar17 = *pcVar14;
      pcVar14 = pcVar14 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  else {
    pbVar18 = &s_NONE;
    pbVar16 = (byte *)param_1;
    do {
      bVar3 = *pbVar16;
      bVar20 = bVar3 < *pbVar18;
      if (bVar3 != *pbVar18) {
LAB_0041027f:
        iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
        goto LAB_00410284;
      }
      if (bVar3 == 0) break;
      bVar3 = pbVar16[1];
      bVar20 = bVar3 < pbVar18[1];
      if (bVar3 != pbVar18[1]) goto LAB_0041027f;
      pbVar16 = pbVar16 + 2;
      pbVar18 = pbVar18 + 2;
    } while (bVar3 != 0);
    iVar4 = 0;
LAB_00410284:
    if (iVar4 == 0) {
      if (param_1 == (char *)0x0) goto LAB_004112e9;
      pcVar14 = &s_NONE;
      goto LAB_004112fb;
    }
    strncpy(this->nameValue,param_1,0x40);
    sprintf(temp + 4,s__s,this->nameValue);
    iVar4 = fopen(temp + 4,s_r);
    if (iVar4 != 0) {
      rotatedPoint.xValue = iVar4;
      if (this->plays != (AIPlay *)0x0) {
        operator_delete(this->plays);
        this->plays = (AIPlay *)0x0;
      }
      this->numberPlaysValue = 0;
      iVar5 = fgets(temp + 4,0x100,iVar4);
      while (iVar5 != 0) {
        iVar5 = -1;
        pcVar14 = temp + 4;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          cVar1 = *pcVar14;
          pcVar14 = pcVar14 + 1;
        } while (cVar1 != '\0');
        if (iVar5 != -2) {
          sscanf(temp + 4,s__s_,temp2 + 4);
          pbVar16 = (byte *)(temp2 + 4);
          pbVar18 = &s_Play;
          do {
            bVar3 = *pbVar18;
            bVar20 = bVar3 < *pbVar16;
            if (bVar3 != *pbVar16) {
LAB_00410368:
              iVar5 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
              goto LAB_0041036d;
            }
            if (bVar3 == 0) break;
            bVar3 = pbVar18[1];
            bVar20 = bVar3 < pbVar16[1];
            if (bVar3 != pbVar16[1]) goto LAB_00410368;
            pbVar18 = pbVar18 + 2;
            pbVar16 = pbVar16 + 2;
          } while (bVar3 != 0);
          iVar5 = 0;
LAB_0041036d:
          if (iVar5 == 0) {
            this->numberPlaysValue = this->numberPlaysValue + 8;
          }
        }
        iVar5 = fgets(temp + 4,0x100,iVar4);
      }
      if (16000 < this->numberPlaysValue) {
        this->numberPlaysValue = 16000;
      }
      iVar4 = this->numberPlaysValue;
      pAVar6 = (AIPlay *)operator_new(iVar4 * 0x608);
      local_4 = 0;
      pAVar7 = (AIPlay *)0x0;
      temp5 = (int)pAVar6;
      if ((pAVar6 != (AIPlay *)0x0) && (pAVar7 = pAVar6, -1 < iVar4 + -1)) {
        do {
          AIPlay::AIPlay(pAVar6);
          iVar4 = iVar4 + -1;
          pAVar6 = pAVar6 + 1;
        } while (iVar4 != 0);
      }
      local_4 = 0xffffffff;
      this->plays = pAVar7;
      if (pAVar7 != (AIPlay *)0x0) {
        rewind(rotatedPoint.xValue);
        pAVar15 = (AIPlayPhase *)0xffffffff;
        refPhase = (AIPlayPhase *)0xffffffff;
        iStack_3a8 = -1;
        do {
          iVar4 = fgets(temp + 4,0x100,rotatedPoint.xValue);
          if (iVar4 == 0) break;
          iVar4 = -1;
          pcVar14 = temp + 4;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            cVar1 = *pcVar14;
            pcVar14 = pcVar14 + 1;
          } while (cVar1 != '\0');
          if (iVar4 != -2) {
            uVar12 = 0xffffffff;
            pcVar14 = s_;
            do {
              pcVar17 = pcVar14;
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              pcVar17 = pcVar14 + 1;
              cVar1 = *pcVar14;
              pcVar14 = pcVar17;
            } while (cVar1 != '\0');
            uVar12 = ~uVar12;
            pcVar14 = temp2;
            pcVar19 = temp6;
            pcVar17 = pcVar17 + -uVar12;
            for (uVar13 = uVar12 >> 2; pcVar14 = pcVar14 + 4, uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined4 *)pcVar14 = *(undefined4 *)pcVar17;
              pcVar17 = pcVar17 + 4;
            }
            for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
              *pcVar14 = *pcVar17;
              pcVar17 = pcVar17 + 1;
              pcVar14 = pcVar14 + 1;
            }
            uVar12 = 0xffffffff;
            pcVar14 = s_;
            do {
              pcVar17 = pcVar14;
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              pcVar17 = pcVar14 + 1;
              cVar1 = *pcVar14;
              pcVar14 = pcVar17;
            } while (cVar1 != '\0');
            uVar12 = ~uVar12;
            pcVar14 = pcVar17 + -uVar12;
            for (uVar13 = uVar12 >> 2; pcVar19 = pcVar19 + 4, uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined4 *)pcVar19 = *(undefined4 *)pcVar14;
              pcVar14 = pcVar14 + 4;
            }
            temp4 = 0;
            for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
              *pcVar19 = *pcVar14;
              pcVar14 = pcVar14 + 1;
              pcVar19 = pcVar19 + 1;
            }
            iStack_3b0 = 0;
            i = 0;
            fileIn = (_iobuf *)0x0;
            temp7 = 0;
            iVar4 = sscanf(temp + 4,s___c_c,(int)&j + 3,(int)&currentPhase + 3);
            if ((iVar4 != -1) && ((j._3_1_ != '/' || (currentPhase._3_1_ != '/')))) {
              sscanf(temp + 4,s__s_,temp2 + 4);
              pAVar9 = refPhase;
              pbVar18 = &s_Play;
              pbVar16 = (byte *)(temp2 + 4);
              do {
                bVar3 = *pbVar16;
                bVar20 = bVar3 < *pbVar18;
                if (bVar3 != *pbVar18) {
LAB_00410539:
                  iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                  goto LAB_0041053e;
                }
                if (bVar3 == 0) break;
                bVar3 = pbVar16[1];
                bVar20 = bVar3 < pbVar18[1];
                if (bVar3 != pbVar18[1]) goto LAB_00410539;
                pbVar16 = pbVar16 + 2;
                pbVar18 = pbVar18 + 2;
              } while (bVar3 != 0);
              iVar4 = 0;
LAB_0041053e:
              if (iVar4 == 0) {
                iVar4 = 0;
                iVar5 = 0;
                cVar1 = temp[4];
                while (cVar1 != '\"') {
                  iVar21 = iVar5 + 5;
                  iVar5 = iVar5 + 1;
                  iVar4 = iVar4 + 1;
                  cVar1 = temp[iVar21];
                }
                temp4 = iVar4 + 1;
                pcVar14 = temp + iVar5 + 5;
                cVar1 = temp[iVar5 + 5];
                iStack_3b0 = temp4;
                while (cVar1 != '\"') {
                  pcVar14 = pcVar14 + 1;
                  iStack_3b0 = iStack_3b0 + 1;
                  cVar1 = *pcVar14;
                }
                uVar12 = 0;
                if (temp4 < iStack_3b0) {
                  uVar12 = iStack_3b0 - temp4;
                  pcVar14 = temp2;
                  pcVar17 = temp + iVar4 + 5;
                  for (uVar13 = uVar12 >> 2; pcVar14 = pcVar14 + 4, uVar13 != 0; uVar13 = uVar13 - 1
                      ) {
                    *(undefined4 *)pcVar14 = *(undefined4 *)pcVar17;
                    pcVar17 = pcVar17 + 4;
                  }
                  for (uVar13 = uVar12 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
                    *pcVar14 = *pcVar17;
                    pcVar17 = pcVar17 + 1;
                    pcVar14 = pcVar14 + 1;
                  }
                }
                pAVar15 = (AIPlayPhase *)&pAVar15->commands[0].typeValue;
                temp2[uVar12 + 4] = '\0';
                refPhase = pAVar15;
                if (15999 < (int)pAVar15) break;
                AIPlay::setName(this->plays + (int)pAVar15,temp2 + 4);
              }
              else {
                pbVar18 = &s_PlayType;
                pbVar16 = (byte *)(temp2 + 4);
                do {
                  bVar3 = *pbVar16;
                  bVar20 = bVar3 < *pbVar18;
                  if (bVar3 != *pbVar18) {
LAB_00410612:
                    iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                    goto LAB_00410617;
                  }
                  if (bVar3 == 0) break;
                  bVar3 = pbVar16[1];
                  bVar20 = bVar3 < pbVar18[1];
                  if (bVar3 != pbVar18[1]) goto LAB_00410612;
                  pbVar16 = pbVar16 + 2;
                  pbVar18 = pbVar18 + 2;
                } while (bVar3 != 0);
                iVar4 = 0;
LAB_00410617:
                if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                  sscanf(temp + 4,s___s__s_,temp2 + 4);
                  pAVar7 = this->plays;
                  uVar2 = AIPlay::convertToIntType(pAVar7 + (int)pAVar15,temp2 + 4);
                  pAVar7[(int)pAVar15].typeValue = uVar2;
                }
                else {
                  pbVar18 = &s_MinUnits;
                  pbVar16 = (byte *)(temp2 + 4);
                  do {
                    bVar3 = *pbVar16;
                    bVar20 = bVar3 < *pbVar18;
                    if (bVar3 != *pbVar18) {
LAB_0041068e:
                      iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                      goto LAB_00410693;
                    }
                    if (bVar3 == 0) break;
                    bVar3 = pbVar16[1];
                    bVar20 = bVar3 < pbVar18[1];
                    if (bVar3 != pbVar18[1]) goto LAB_0041068e;
                    pbVar16 = pbVar16 + 2;
                    pbVar18 = pbVar18 + 2;
                  } while (bVar3 != 0);
                  iVar4 = 0;
LAB_00410693:
                  if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                    sscanf(temp + 4,s___s__d_,&temp4);
                    this->plays[(int)pAVar15].minimumNumberUnitsValue = (uchar)temp4;
                  }
                  else {
                    pbVar18 = &s_MaxUnits;
                    pbVar16 = (byte *)(temp2 + 4);
                    do {
                      bVar3 = *pbVar16;
                      bVar20 = bVar3 < *pbVar18;
                      if (bVar3 != *pbVar18) {
LAB_00410702:
                        iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                        goto LAB_00410707;
                      }
                      if (bVar3 == 0) break;
                      bVar3 = pbVar16[1];
                      bVar20 = bVar3 < pbVar18[1];
                      if (bVar3 != pbVar18[1]) goto LAB_00410702;
                      pbVar16 = pbVar16 + 2;
                      pbVar18 = pbVar18 + 2;
                    } while (bVar3 != 0);
                    iVar4 = 0;
LAB_00410707:
                    if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                      sscanf(temp + 4,s___s__d_,&temp4);
                      this->plays[(int)pAVar15].maximumNumberUnitsValue = (uchar)temp4;
                    }
                    else {
                      pbVar18 = &s_Power;
                      pbVar16 = (byte *)(temp2 + 4);
                      do {
                        bVar3 = *pbVar16;
                        bVar20 = bVar3 < *pbVar18;
                        if (bVar3 != *pbVar18) {
LAB_00410776:
                          iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                          goto LAB_0041077b;
                        }
                        if (bVar3 == 0) break;
                        bVar3 = pbVar16[1];
                        bVar20 = bVar3 < pbVar18[1];
                        if (bVar3 != pbVar18[1]) goto LAB_00410776;
                        pbVar16 = pbVar16 + 2;
                        pbVar18 = pbVar18 + 2;
                      } while (bVar3 != 0);
                      iVar4 = 0;
LAB_0041077b:
                      if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                        sscanf(temp + 4,s___s__d_,&temp4);
                        this->plays[(int)pAVar15].powerValue = (uchar)temp4;
                      }
                      else {
                        pbVar18 = &s_Overflow;
                        pbVar16 = (byte *)(temp2 + 4);
                        do {
                          bVar3 = *pbVar16;
                          bVar20 = bVar3 < *pbVar18;
                          if (bVar3 != *pbVar18) {
LAB_004107ea:
                            iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                            goto LAB_004107ef;
                          }
                          if (bVar3 == 0) break;
                          bVar3 = pbVar16[1];
                          bVar20 = bVar3 < pbVar18[1];
                          if (bVar3 != pbVar18[1]) goto LAB_004107ea;
                          pbVar16 = pbVar16 + 2;
                          pbVar18 = pbVar18 + 2;
                        } while (bVar3 != 0);
                        iVar4 = 0;
LAB_004107ef:
                        if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                          sscanf(temp + 4,s___s__s_,temp2 + 4);
                          pbVar18 = &s_Balance;
                          pbVar16 = (byte *)(temp2 + 4);
                          do {
                            bVar3 = *pbVar16;
                            bVar20 = bVar3 < *pbVar18;
                            if (bVar3 != *pbVar18) {
LAB_0041084b:
                              iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                              goto LAB_00410850;
                            }
                            if (bVar3 == 0) break;
                            bVar3 = pbVar16[1];
                            bVar20 = bVar3 < pbVar18[1];
                            if (bVar3 != pbVar18[1]) goto LAB_0041084b;
                            pbVar16 = pbVar16 + 2;
                            pbVar18 = pbVar18 + 2;
                          } while (bVar3 != 0);
                          iVar4 = 0;
LAB_00410850:
                          if (iVar4 == 0) {
                            this->plays[(int)pAVar15].overflowValue = '\x01';
                          }
                          else {
                            pbVar18 = &s_FirstGroup;
                            pbVar16 = (byte *)(temp2 + 4);
                            do {
                              bVar3 = *pbVar16;
                              bVar20 = bVar3 < *pbVar18;
                              if (bVar3 != *pbVar18) {
LAB_0041089d:
                                iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                goto LAB_004108a2;
                              }
                              if (bVar3 == 0) break;
                              bVar3 = pbVar16[1];
                              bVar20 = bVar3 < pbVar18[1];
                              if (bVar3 != pbVar18[1]) goto LAB_0041089d;
                              pbVar16 = pbVar16 + 2;
                              pbVar18 = pbVar18 + 2;
                            } while (bVar3 != 0);
                            iVar4 = 0;
LAB_004108a2:
                            if (iVar4 == 0) {
                              this->plays[(int)pAVar15].overflowValue = '\x02';
                            }
                          }
                        }
                        else {
                          pbVar18 = &s_DeathPercentage;
                          pbVar16 = (byte *)(temp2 + 4);
                          do {
                            bVar3 = *pbVar16;
                            bVar20 = bVar3 < *pbVar18;
                            if (bVar3 != *pbVar18) {
LAB_004108f3:
                              iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                              goto LAB_004108f8;
                            }
                            if (bVar3 == 0) break;
                            bVar3 = pbVar16[1];
                            bVar20 = bVar3 < pbVar18[1];
                            if (bVar3 != pbVar18[1]) goto LAB_004108f3;
                            pbVar16 = pbVar16 + 2;
                            pbVar18 = pbVar18 + 2;
                          } while (bVar3 != 0);
                          iVar4 = 0;
LAB_004108f8:
                          if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                            sscanf(temp + 4,s___s__d_,&temp4);
                            if (temp4 < 0) {
                              this->plays[(int)pAVar15].deathPercentageValue = '\0';
                            }
                            else if (temp4 < 0x65) {
                              this->plays[(int)pAVar15].deathPercentageValue = (uchar)temp4;
                            }
                            else {
                              this->plays[(int)pAVar15].deathPercentageValue = 'd';
                            }
                          }
                          else {
                            pbVar18 = &s_Intelligence;
                            pbVar16 = (byte *)(temp2 + 4);
                            do {
                              bVar3 = *pbVar16;
                              bVar20 = bVar3 < *pbVar18;
                              if (bVar3 != *pbVar18) {
LAB_0041099c:
                                iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                goto LAB_004109a1;
                              }
                              if (bVar3 == 0) break;
                              bVar3 = pbVar16[1];
                              bVar20 = bVar3 < pbVar18[1];
                              if (bVar3 != pbVar18[1]) goto LAB_0041099c;
                              pbVar16 = pbVar16 + 2;
                              pbVar18 = pbVar18 + 2;
                            } while (bVar3 != 0);
                            iVar4 = 0;
LAB_004109a1:
                            if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                              sscanf(temp + 4,s___s__d_,&temp4);
                              if (temp4 < 0) {
                                this->plays[(int)pAVar15].intelligenceValue = '\0';
                              }
                              else if (temp4 < 0x65) {
                                this->plays[(int)pAVar15].intelligenceValue = (uchar)temp4;
                              }
                              else {
                                this->plays[(int)pAVar15].intelligenceValue = 'd';
                              }
                            }
                            else {
                              pbVar18 = &s_TargetChar;
                              pbVar16 = (byte *)(temp2 + 4);
                              do {
                                bVar3 = *pbVar16;
                                bVar20 = bVar3 < *pbVar18;
                                if (bVar3 != *pbVar18) {
LAB_00410a45:
                                  iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                  goto LAB_00410a4a;
                                }
                                if (bVar3 == 0) break;
                                bVar3 = pbVar16[1];
                                bVar20 = bVar3 < pbVar18[1];
                                if (bVar3 != pbVar18[1]) goto LAB_00410a45;
                                pbVar16 = pbVar16 + 2;
                                pbVar18 = pbVar18 + 2;
                              } while (bVar3 != 0);
                              iVar4 = 0;
LAB_00410a4a:
                              if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                                sscanf(temp + 4,s___s__s_,temp6 + 4);
                                iVar4 = (**(code **)(this->_padding_ + 8))(temp6 + 4);
                                if (iVar4 != 0) {
                                  AIPlay::addTargetCharacteristic
                                            (this->plays + (int)pAVar15,(uchar)iVar4);
                                }
                              }
                              else {
                                pbVar18 = &s_TargetType;
                                pbVar16 = (byte *)(temp2 + 4);
                                do {
                                  bVar3 = *pbVar16;
                                  bVar20 = bVar3 < *pbVar18;
                                  if (bVar3 != *pbVar18) {
LAB_00410ad2:
                                    iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                    goto LAB_00410ad7;
                                  }
                                  if (bVar3 == 0) break;
                                  bVar3 = pbVar16[1];
                                  bVar20 = bVar3 < pbVar18[1];
                                  if (bVar3 != pbVar18[1]) goto LAB_00410ad2;
                                  pbVar16 = pbVar16 + 2;
                                  pbVar18 = pbVar18 + 2;
                                } while (bVar3 != 0);
                                iVar4 = 0;
LAB_00410ad7:
                                if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                                  sscanf(temp + 4,s___s__s_,temp6 + 4);
                                  iVar4 = (**(code **)(this->_padding_ + 4))(temp6 + 4);
                                  if (iVar4 != 0) {
                                    AIPlay::addTargetType(this->plays + (int)pAVar15,(uchar)iVar4);
                                  }
                                }
                                else {
                                  pbVar18 = &s_NumberGroups;
                                  pbVar16 = (byte *)(temp2 + 4);
                                  do {
                                    bVar3 = *pbVar16;
                                    bVar20 = bVar3 < *pbVar18;
                                    if (bVar3 != *pbVar18) {
LAB_00410b5f:
                                      iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                      goto LAB_00410b64;
                                    }
                                    if (bVar3 == 0) break;
                                    bVar3 = pbVar16[1];
                                    bVar20 = bVar3 < pbVar18[1];
                                    if (bVar3 != pbVar18[1]) goto LAB_00410b5f;
                                    pbVar16 = pbVar16 + 2;
                                    pbVar18 = pbVar18 + 2;
                                  } while (bVar3 != 0);
                                  iVar4 = 0;
LAB_00410b64:
                                  if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                                    sscanf(temp + 4,s___s__d_,&temp4);
                                    this->plays[(int)pAVar15].numberGroupsValue = (uchar)temp4;
                                  }
                                  else {
                                    pbVar18 = &s_Group;
                                    pbVar16 = (byte *)(temp2 + 4);
                                    do {
                                      bVar3 = *pbVar16;
                                      bVar20 = bVar3 < *pbVar18;
                                      if (bVar3 != *pbVar18) {
LAB_00410bd3:
                                        iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                        goto LAB_00410bd8;
                                      }
                                      if (bVar3 == 0) break;
                                      bVar3 = pbVar16[1];
                                      bVar20 = bVar3 < pbVar18[1];
                                      if (bVar3 != pbVar18[1]) goto LAB_00410bd3;
                                      pbVar16 = pbVar16 + 2;
                                      pbVar18 = pbVar18 + 2;
                                    } while (bVar3 != 0);
                                    iVar4 = 0;
LAB_00410bd8:
                                    if (((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) &&
                                       (iStack_3a8 == -1)) {
                                      sscanf(temp + 4,s___s__d__s__d____d_,&temp4,temp6 + 4,
                                             &stack0xfffffc50,&i);
                                      if (((-1 < temp4) && (temp4 < 5)) &&
                                         (iVar4 = (**(code **)(this->_padding_ + 0xc))(temp6 + 4),
                                         iVar4 != -1)) {
                                        iVar5 = iStack_3b0;
                                        if (i < 0) {
                                          iVar5 = 0;
                                        }
                                        iVar21 = iVar4;
                                        pAVar8 = AIPlay::group(this->plays + (int)pAVar15,temp4);
                                        AIPlayGroup::setMinimum(pAVar8,iVar21,iVar5);
                                        iVar5 = i;
                                        if (0x32 < i) {
                                          iVar5 = 0x32;
                                        }
                                        pAVar8 = AIPlay::group(this->plays + (int)pAVar15,temp4);
                                        AIPlayGroup::setMaximum(pAVar8,iVar4,iVar5);
                                      }
                                    }
                                    else {
                                      pbVar18 = &s_Phase;
                                      pbVar16 = (byte *)(temp2 + 4);
                                      do {
                                        bVar3 = *pbVar16;
                                        bVar20 = bVar3 < *pbVar18;
                                        if (bVar3 != *pbVar18) {
LAB_00410cf8:
                                          iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                          goto LAB_00410cfd;
                                        }
                                        if (bVar3 == 0) break;
                                        bVar3 = pbVar16[1];
                                        bVar20 = bVar3 < pbVar18[1];
                                        if (bVar3 != pbVar18[1]) goto LAB_00410cf8;
                                        pbVar16 = pbVar16 + 2;
                                        pbVar18 = pbVar18 + 2;
                                      } while (bVar3 != 0);
                                      iVar4 = 0;
LAB_00410cfd:
                                      if ((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                                        sscanf(temp + 4,s___s__d_,&temp4);
                                        iStack_3a8 = temp4;
                                      }
                                      else {
                                        pbVar18 = &s_Group;
                                        pbVar16 = (byte *)(temp2 + 4);
                                        do {
                                          bVar3 = *pbVar16;
                                          bVar20 = bVar3 < *pbVar18;
                                          if (bVar3 != *pbVar18) {
LAB_00410d5a:
                                            iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                            goto LAB_00410d5f;
                                          }
                                          if (bVar3 == 0) break;
                                          bVar3 = pbVar16[1];
                                          bVar20 = bVar3 < pbVar18[1];
                                          if (bVar3 != pbVar18[1]) goto LAB_00410d5a;
                                          pbVar16 = pbVar16 + 2;
                                          pbVar18 = pbVar18 + 2;
                                        } while (bVar3 != 0);
                                        iVar4 = 0;
LAB_00410d5f:
                                        if (((iVar4 == 0) && (pAVar15 != (AIPlayPhase *)0xffffffff))
                                           && (iStack_3a8 != -1)) {
                                          sscanf(temp + 4,s___s__d__s__d__d__d_,&temp4,temp6 + 4,
                                                 &stack0xfffffc50,&i,&fileIn);
                                          if ((-1 < temp4) && (temp4 < 5)) {
                                            pAVar9 = AIPlay::phase(this->plays + (int)pAVar15,
                                                                   iStack_3a8);
                                            AIPlayPhaseCommand::AIPlayPhaseCommand
                                                      ((AIPlayPhaseCommand *)&command.value1Value,
                                                       (uchar)temp4,temp6 + 4,iStack_3b0,i,
                                                       (int)fileIn);
                                            AIPlayPhase::addCommand
                                                      (pAVar9,(AIPlayPhaseCommand *)
                                                              &command.value1Value);
                                          }
                                        }
                                        else {
                                          pbVar18 = &s_Trigger;
                                          pbVar16 = (byte *)(temp2 + 4);
                                          do {
                                            bVar3 = *pbVar16;
                                            bVar20 = bVar3 < *pbVar18;
                                            if (bVar3 != *pbVar18) {
LAB_00410e43:
                                              iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                              goto LAB_00410e48;
                                            }
                                            if (bVar3 == 0) break;
                                            bVar3 = pbVar16[1];
                                            bVar20 = bVar3 < pbVar18[1];
                                            if (bVar3 != pbVar18[1]) goto LAB_00410e43;
                                            pbVar16 = pbVar16 + 2;
                                            pbVar18 = pbVar18 + 2;
                                          } while (bVar3 != 0);
                                          iVar4 = 0;
LAB_00410e48:
                                          if (((iVar4 == 0) &&
                                              (pAVar15 != (AIPlayPhase *)0xffffffff)) &&
                                             (iStack_3a8 != -1)) {
                                            sscanf(temp + 4,s___s__d__s__d__d_,&temp4,temp6 + 4,
                                                   &stack0xfffffc50,&temp7);
                                            iVar4 = iStack_3a8;
                                            pAVar9 = AIPlay::phase(this->plays + (int)pAVar15,
                                                                   iStack_3a8);
                                            AIPlayPhaseTrigger::AIPlayPhaseTrigger
                                                      ((AIPlayPhaseTrigger *)&trigger.value1Value,
                                                       temp6 + 4,iStack_3b0,temp7,(uchar)iVar4,
                                                       (uchar)temp4,0);
                                            AIPlayPhase::addTrigger
                                                      (pAVar9,(AIPlayPhaseTrigger *)
                                                              &trigger.value1Value);
                                          }
                                          else {
                                            pbVar18 = &s_RTrigger;
                                            pbVar16 = (byte *)(temp2 + 4);
                                            do {
                                              bVar3 = *pbVar16;
                                              bVar20 = bVar3 < *pbVar18;
                                              if (bVar3 != *pbVar18) {
LAB_00410f10:
                                                iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                                goto LAB_00410f15;
                                              }
                                              if (bVar3 == 0) break;
                                              bVar3 = pbVar16[1];
                                              bVar20 = bVar3 < pbVar18[1];
                                              if (bVar3 != pbVar18[1]) goto LAB_00410f10;
                                              pbVar16 = pbVar16 + 2;
                                              pbVar18 = pbVar18 + 2;
                                            } while (bVar3 != 0);
                                            iVar4 = 0;
LAB_00410f15:
                                            if (((iVar4 == 0) &&
                                                (pAVar15 != (AIPlayPhase *)0xffffffff)) &&
                                               (iStack_3a8 != -1)) {
                                              sscanf(temp + 4,s___s__d__s__d__d__d_,&temp4,temp6 + 4
                                                     ,&stack0xfffffc50,&temp7,&fileIn);
                                              iVar4 = iStack_3a8;
                                              pAVar9 = AIPlay::phase(this->plays + (int)pAVar15,
                                                                     iStack_3a8);
                                              AIPlayPhaseTrigger::AIPlayPhaseTrigger
                                                        ((AIPlayPhaseTrigger *)
                                                         &trigger_fffffedc.value1Value,temp6 + 4,
                                                         iStack_3b0,temp7,(uchar)iVar4,(uchar)temp4,
                                                         (int)fileIn);
                                              AIPlayPhase::addTrigger
                                                        (pAVar9,(AIPlayPhaseTrigger *)
                                                                &trigger_fffffedc.value1Value);
                                            }
                                            else {
                                              pbVar18 = &s_EndPlay;
                                              pbVar16 = (byte *)(temp2 + 4);
                                              do {
                                                bVar3 = *pbVar16;
                                                bVar20 = bVar3 < *pbVar18;
                                                if (bVar3 != *pbVar18) {
LAB_00410fe9:
                                                  iVar4 = (1 - (uint)bVar20) - (uint)(bVar20 != 0);
                                                  goto LAB_00410fee;
                                                }
                                                if (bVar3 == 0) break;
                                                bVar3 = pbVar16[1];
                                                bVar20 = bVar3 < pbVar18[1];
                                                if (bVar3 != pbVar18[1]) goto LAB_00410fe9;
                                                pbVar16 = pbVar16 + 2;
                                                pbVar18 = pbVar18 + 2;
                                              } while (bVar3 != 0);
                                              iVar4 = 0;
LAB_00410fee:
                                              if ((iVar4 == 0) &&
                                                 (pAVar15 != (AIPlayPhase *)0xffffffff)) {
                                                uVar12 = 0xffffffff;
                                                iStack_3a8 = -1;
                                                iVar4 = (int)refPhase * 0x608;
                                                temp5 = (int)(temp2 + 4);
                                                pAVar7 = this->plays + (int)refPhase;
                                                do {
                                                  pAVar6 = pAVar7;
                                                  if (uVar12 == 0) break;
                                                  uVar12 = uVar12 - 1;
                                                  pAVar6 = (AIPlay *)(pAVar7->nameValue + 1);
                                                  pcVar14 = pAVar7->nameValue;
                                                  pAVar7 = pAVar6;
                                                } while (*pcVar14 != '\0');
                                                uVar12 = ~uVar12;
                                                pcVar14 = (char *)((int)pAVar6 - uVar12);
                                                pcVar17 = (char *)temp5;
                                                for (uVar13 = uVar12 >> 2; uVar13 != 0;
                                                    uVar13 = uVar13 - 1) {
                                                  *(undefined4 *)pcVar17 = *(undefined4 *)pcVar14;
                                                  pcVar14 = pcVar14 + 4;
                                                  pcVar17 = pcVar17 + 4;
                                                }
                                                for (uVar12 = uVar12 & 3; uVar12 != 0;
                                                    uVar12 = uVar12 - 1) {
                                                  *pcVar17 = *pcVar14;
                                                  pcVar14 = pcVar14 + 1;
                                                  pcVar17 = pcVar17 + 1;
                                                }
                                                if ((temp2[4] == 'H') && (temp2[5] == 'P')) {
                                                  this->numberPlaysValue =
                                                       this->numberPlaysValue + -7;
                                                  pAVar15 = refPhase;
                                                }
                                                else {
                                                  refPhase = (AIPlayPhase *)
                                                             ((int)&refPhase->commands[0].
                                                                    value1Value + 3);
                                                  temp8 = 1;
                                                  do {
                                                    sprintf(temp2 + 4,s__sF_d,
                                                            this->plays + (int)pAVar9,temp8);
                                                    AIPlay::setName((AIPlay *)
                                                                    (this->plays[1].nameValue +
                                                                    iVar4),temp2 + 4);
                                                    iVar5 = 0;
                                                    this->plays[1].targetTypeValue[iVar4 + -1] =
                                                         this->plays[(int)pAVar9].typeValue;
                                                    this->plays[1].targetTypeValue[iVar4 + -3] =
                                                         this->plays[(int)pAVar9].
                                                         minimumNumberUnitsValue;
                                                    this->plays[1].targetTypeValue[iVar4 + -2] =
                                                         this->plays[(int)pAVar9].
                                                         maximumNumberUnitsValue;
                                                    this->plays[1].targetCharacteristicValue
                                                    [iVar4 + 5] = this->plays[(int)pAVar9].
                                                                  powerValue;
                                                    this->plays[1].groups[0].minValue[iVar4 + -4] =
                                                         this->plays[(int)pAVar9].overflowValue;
                                                    this->plays[1].groups[0].minValue[iVar4 + -2] =
                                                         this->plays[(int)pAVar9].
                                                         deathPercentageValue;
                                                    this->plays[1].groups[0].minValue[iVar4 + -3] =
                                                         this->plays[(int)pAVar9].intelligenceValue;
                                                    do {
                                                      uVar2 = AIPlay::targetType(this->plays +
                                                                                 (int)pAVar9,iVar5);
                                                      AIPlay::addTargetType
                                                                ((AIPlay *)
                                                                 (this->plays[1].nameValue + iVar4),
                                                                 uVar2);
                                                      uVar2 = AIPlay::targetCharacteristic
                                                                        (this->plays + (int)pAVar9,
                                                                         iVar5);
                                                      AIPlay::addTargetCharacteristic
                                                                ((AIPlay *)
                                                                 (this->plays[1].nameValue + iVar4),
                                                                 uVar2);
                                                      iVar5 = iVar5 + 1;
                                                    } while (iVar5 < 5);
                                                    curPhase = (AIPlayPhase *)0x0;
                                                    this->plays[1].groups[0].minValue[iVar4 + -1] =
                                                         this->plays[(int)pAVar9].numberGroupsValue;
                                                    do {
                                                      pAVar15 = curPhase;
                                                      a = (int)AIPlay::group(this->plays +
                                                                             (int)pAVar9,
                                                                             (int)curPhase);
                                                      currentPlay = (int)AIPlay::group((AIPlay *)
                                                                                       (this->plays
                                                                                        [1].
                                                  nameValue + iVar4),(int)pAVar15);
                                                  iVar5 = 0;
                                                  do {
                                                    bVar3 = AIPlayGroup::minimum
                                                                      ((AIPlayGroup *)a,iVar5);
                                                    AIPlayGroup::setMinimum
                                                              ((AIPlayGroup *)currentPlay,iVar5,
                                                               (uint)bVar3);
                                                    bVar3 = AIPlayGroup::maximum
                                                                      ((AIPlayGroup *)a,iVar5);
                                                    AIPlayGroup::setMaximum
                                                              ((AIPlayGroup *)currentPlay,iVar5,
                                                               (uint)bVar3);
                                                    iVar5 = iVar5 + 1;
                                                  } while (iVar5 < 6);
                                                  curPhase = (AIPlayPhase *)
                                                             &curPhase->commands[0].typeValue;
                                                  } while ((int)curPhase < 5);
                                                  curPhase = (AIPlayPhase *)0x0;
                                                  do {
                                                    pAVar15 = curPhase;
                                                    temp5 = (int)AIPlay::phase(this->plays +
                                                                               (int)pAVar9,
                                                                               (int)curPhase);
                                                    a = (int)AIPlay::phase((AIPlay *)
                                                                           (this->plays[1].nameValue
                                                                           + iVar4),(int)pAVar15);
                                                    currentPlay = 0;
                                                    do {
                                                      pAVar10 = AIPlayPhase::command
                                                                          ((AIPlayPhase *)temp5,
                                                                           currentPlay);
                                                      if (pAVar10->typeValue == '\x01') {
                                                        XYZ::XYZ((XYZ *)&origin.yValue,0,0,0);
                                                        XYZ::XYZ((XYZ *)&rotatedPoint.yValue);
                                                        XYZ::XYZ((XYZ *)&originalPoint.yValue,
                                                                 pAVar10->value1Value,
                                                                 pAVar10->value2Value,
                                                                 pAVar10->value3Value);
                                                        XYZ::rotateXYByFacet
                                                                  ((XYZ *)&originalPoint.yValue,
                                                                   (XYZ *)&origin.yValue,
                                                                   (XYZ *)&rotatedPoint.yValue,
                                                                   (uchar)temp8);
                                                        AIPlayPhaseCommand::AIPlayPhaseCommand
                                                                  ((AIPlayPhaseCommand *)
                                                                   &newCommand.value1Value,
                                                                   pAVar10->groupValue,
                                                                   pAVar10->typeValue,
                                                                   rotatedPoint.yValue,
                                                                   rotatedPoint.zValue,
                                                                   originalPoint.xValue);
                                                        pAVar10 = (AIPlayPhaseCommand *)
                                                                  &newCommand.value1Value;
                                                      }
                                                      AIPlayPhase::addCommand
                                                                ((AIPlayPhase *)a,pAVar10);
                                                      currentPlay = currentPlay + 1;
                                                    } while (currentPlay < 5);
                                                    iVar5 = 0;
                                                    do {
                                                      pAVar11 = AIPlayPhase::trigger
                                                                          ((AIPlayPhase *)temp5,
                                                                           iVar5);
                                                      AIPlayPhase::addTrigger
                                                                ((AIPlayPhase *)a,pAVar11);
                                                      iVar5 = iVar5 + 1;
                                                    } while (iVar5 < 3);
                                                    curPhase = (AIPlayPhase *)
                                                               &curPhase->commands[0].typeValue;
                                                  } while ((int)curPhase < 10);
                                                  temp8 = temp8 + 1;
                                                  pAVar15 = refPhase;
                                                  iVar4 = iVar4 + 0x608;
                                                  } while (temp8 < 8);
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        } while ((int)pAVar15 < 16000);
        fclose(rotatedPoint.xValue);
        iVar4 = 1;
        goto LAB_0041131a;
      }
    }
  }
  iVar4 = 0;
LAB_0041131a:
  *unaff_FS_OFFSET = local_c;
  return iVar4;
}

// --------------------------------------------------

// Function: play
// Address: 00411340
/* public: class AIPlay * __thiscall AIPlayBook::play(int) */

AIPlay * __thiscall AIPlayBook::play(AIPlayBook *this,int param_1)
{
  if (((this->plays != (AIPlay *)0x0) && (-1 < param_1)) && (param_1 < this->numberPlaysValue)) {
    return this->plays + param_1;
  }
  return (AIPlay *)0x0;
}

// --------------------------------------------------

// Function: play
// Address: 00411370
/* public: class AIPlay * __thiscall AIPlayBook::play(char *) */

AIPlay * __thiscall AIPlayBook::play(AIPlayBook *this,char *param_1)
{
  byte bVar1;
  AIPlay *pAVar2;
  AIPlay *pAVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  AIPlay *pAVar7;
  bool bVar8;
  
  pAVar2 = this->plays;
  if (pAVar2 != (AIPlay *)0x0) {
    iVar5 = 0;
    pAVar3 = pAVar2;
    pbVar6 = (byte *)param_1;
    pAVar7 = pAVar2;
    if (0 < this->numberPlaysValue) {
LAB_0041138f:
      do {
        bVar1 = pAVar3->nameValue[0];
        bVar8 = bVar1 < *pbVar6;
        if (bVar1 == *pbVar6) {
          if (bVar1 != 0) {
            bVar1 = pAVar3->nameValue[1];
            bVar8 = bVar1 < pbVar6[1];
            if (bVar1 != pbVar6[1]) goto LAB_004113b3;
            pAVar3 = (AIPlay *)(pAVar3->nameValue + 2);
            pbVar6 = pbVar6 + 2;
            if (bVar1 != 0) goto LAB_0041138f;
          }
          iVar4 = 0;
        }
        else {
LAB_004113b3:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        }
        if (iVar4 == 0) {
          return pAVar2 + iVar5;
        }
        iVar5 = iVar5 + 1;
        pAVar3 = pAVar7 + 1;
        pbVar6 = (byte *)param_1;
        pAVar7 = pAVar3;
        if (this->numberPlaysValue <= iVar5) {
          return (AIPlay *)0x0;
        }
      } while( true );
    }
  }
  return (AIPlay *)0x0;
}

// --------------------------------------------------

// Function: playNumber
// Address: 00411400
/* public: int __thiscall AIPlayBook::playNumber(char *) */

int __thiscall AIPlayBook::playNumber(AIPlayBook *this,char *param_1)
{
  byte bVar1;
  AIPlay *pAVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  AIPlay *pAVar6;
  bool bVar7;
  
  pAVar2 = this->plays;
  if (pAVar2 != (AIPlay *)0x0) {
    iVar4 = 0;
    pbVar5 = (byte *)param_1;
    pAVar6 = pAVar2;
    if (0 < this->numberPlaysValue) {
LAB_0041141c:
      do {
        bVar1 = pAVar2->nameValue[0];
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 == *pbVar5) {
          if (bVar1 != 0) {
            bVar1 = pAVar2->nameValue[1];
            bVar7 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_00411440;
            pAVar2 = (AIPlay *)(pAVar2->nameValue + 2);
            pbVar5 = pbVar5 + 2;
            if (bVar1 != 0) goto LAB_0041141c;
          }
          iVar3 = 0;
        }
        else {
LAB_00411440:
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        }
        if (iVar3 == 0) {
          return iVar4;
        }
        iVar4 = iVar4 + 1;
        pAVar2 = pAVar6 + 1;
        pbVar5 = (byte *)param_1;
        pAVar6 = pAVar2;
        if (this->numberPlaysValue <= iVar4) {
          return -1;
        }
      } while( true );
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: convertTargetNameToIntType
// Address: 00411480
// [HELPER] s_Any: "Any"
/* public: virtual int __thiscall AIPlayBook::convertTargetNameToIntType(char *)const  */

int __thiscall AIPlayBook::convertTargetNameToIntType(AIPlayBook *this,char *param_1)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = &s_Any;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 5;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 5;
    }
  }
  return (-(uint)(1 - bVar3 != (uint)(bVar3 != 0)) & 0xfffffffb) + 5;
}

// --------------------------------------------------

// Function: convertTargetCharacteristicNameToIntType
// Address: 004114e0
// [HELPER] s_Any: "Any"
// [HELPER] s_Fast: "Fast"
// [HELPER] s_Moving: "Moving"
// [HELPER] s_Slow: "Slow"
// [HELPER] s_Stationary: "Stationary"
/* public: virtual int __thiscall AIPlayBook::convertTargetCharacteristicNameToIntType(char *)const
    */

int __thiscall AIPlayBook::convertTargetCharacteristicNameToIntType(AIPlayBook *this,char *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Stationary;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_00411516:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0041151b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_00411516;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0041151b:
  if (iVar3 == 0) {
    return 1;
  }
  pbVar4 = &s_Moving;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_00411559:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0041155e;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_00411559;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0041155e:
  if (iVar3 == 0) {
    return 2;
  }
  pbVar4 = &s_Slow;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0041159c:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004115a1;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0041159c;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004115a1:
  if (iVar3 == 0) {
    return 3;
  }
  pbVar4 = &s_Fast;
  pbVar2 = (byte *)param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004115df:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004115e4;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004115df;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004115e4:
  if (iVar3 == 0) {
    return 4;
  }
  pbVar2 = &s_Any;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 5;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 5;
    }
  }
  return (-(uint)(1 - bVar5 != (uint)(bVar5 != 0)) & 0xfffffffb) + 5;
}

// --------------------------------------------------

// Function: convertUnitNameToIntType
// Address: 00411650
/* public: virtual int __thiscall AIPlayBook::convertUnitNameToIntType(char *)const  */

int __thiscall AIPlayBook::convertUnitNameToIntType(AIPlayBook *this,char *param_1)
{
  return -1;
}

// --------------------------------------------------

// Function: convertUnitToIntType
// Address: 00411660
/* public: virtual int __thiscall AIPlayBook::convertUnitToIntType(class RGE_Static_Object *)const
    */

int __thiscall AIPlayBook::convertUnitToIntType(AIPlayBook *this,RGE_Static_Object *param_1)
{
  return -1;
}

// --------------------------------------------------

// Function: ~AIPlayBook
// Address: 004e68ee
void __thiscall AIPlayBook::~AIPlayBook(AIPlayBook *this)
{
  this->_padding_ = (int)&_vftable_;
  if (this->plays != (AIPlay *)0x0) {
    this->numberPlaysValue = 0;
    operator_delete(this->plays);
    this->plays = (AIPlay *)0x0;
  }
  return;
}

// --------------------------------------------------


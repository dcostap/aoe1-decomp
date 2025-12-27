// GLOBAL FUNCTIONS PART 600
// Function: FUN_00411335
// Address: 00411335
int __thiscall FUN_00411335(int param_1,int param_2)
{
  if (((*(int *)(param_1 + 0x4c) != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 4))) {
    return *(int *)(param_1 + 0x4c) + param_2 * 0x608;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00411367
// Address: 00411367
byte * __thiscall FUN_00411367(int param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  
  pbVar2 = *(byte **)(param_1 + 0x4c);
  if (pbVar2 != (byte *)0x0) {
    iVar4 = 0;
    pbVar7 = pbVar2;
    pbVar5 = param_2;
    pbVar6 = pbVar2;
    if (0 < *(int *)(param_1 + 4)) {
LAB_0041138f:
      do {
        bVar1 = *pbVar7;
        bVar8 = bVar1 < *pbVar5;
        if (bVar1 == *pbVar5) {
          if (bVar1 != 0) {
            bVar1 = pbVar7[1];
            bVar8 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_004113b3;
            pbVar7 = pbVar7 + 2;
            pbVar5 = pbVar5 + 2;
            if (bVar1 != 0) goto LAB_0041138f;
          }
          iVar3 = 0;
        }
        else {
LAB_004113b3:
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        }
        if (iVar3 == 0) {
          return pbVar2 + iVar4 * 0x608;
        }
        iVar4 = iVar4 + 1;
        pbVar7 = pbVar6 + 0x608;
        pbVar5 = param_2;
        pbVar6 = pbVar7;
        if (*(int *)(param_1 + 4) <= iVar4) {
          return (byte *)0x0;
        }
      } while( true );
    }
  }
  return (byte *)0x0;
}

// --------------------------------------------------

// Function: FUN_004113f3
// Address: 004113f3
int __thiscall FUN_004113f3(int param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  pbVar2 = *(byte **)(param_1 + 0x4c);
  if (pbVar2 != (byte *)0x0) {
    iVar4 = 0;
    pbVar5 = param_2;
    pbVar6 = pbVar2;
    if (0 < *(int *)(param_1 + 4)) {
LAB_0041141c:
      do {
        bVar1 = *pbVar2;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 == *pbVar5) {
          if (bVar1 != 0) {
            bVar1 = pbVar2[1];
            bVar7 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_00411440;
            pbVar2 = pbVar2 + 2;
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
        pbVar2 = pbVar6 + 0x608;
        pbVar5 = param_2;
        pbVar6 = pbVar2;
        if (*(int *)(param_1 + 4) <= iVar4) {
          return -1;
        }
      } while( true );
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00411471
// Address: 00411471
// [HELPER] s_Any: "Any"
int FUN_00411471(byte *param_1)
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
    bVar1 = param_1[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = param_1 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 5;
    }
  }
  return (-(uint)(1 - bVar3 != (uint)(bVar3 != 0)) & 0xfffffffb) + 5;
}

// --------------------------------------------------

// Function: FUN_004114d2
// Address: 004114d2
// [HELPER] s_Any: "Any"
// [HELPER] s_Fast: "Fast"
// [HELPER] s_Moving: "Moving"
// [HELPER] s_Slow: "Slow"
// [HELPER] s_Stationary: "Stationary"
int FUN_004114d2(byte *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = &s_Stationary;
  pbVar2 = param_1;
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
  pbVar2 = param_1;
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
  pbVar2 = param_1;
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
  pbVar2 = param_1;
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
    bVar1 = param_1[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = param_1 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 5;
    }
  }
  return (-(uint)(1 - bVar5 != (uint)(bVar5 != 0)) & 0xfffffffb) + 5;
}

// --------------------------------------------------

// Function: FUN_00411643
// Address: 00411643
undefined4 FUN_00411643(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00411656
// Address: 00411656
undefined4 FUN_00411656(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00411666
// Address: 00411666
// [HELPER] s_: ""
// [HELPER] s_Research_AI: "Research AI"
AIModule * __thiscall FUN_00411666(AIModule *param_1,void *param_2,int param_3)
{
  AIModuleID *this;
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c758;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  AIModule::AIModule(param_1,s_Research_AI,0x3ee,param_3,param_2);
  this = &param_1[1].idValue;
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  TechnologyItem::TechnologyItem((TechnologyItem *)this);
  param_1[1].playerNameValue[8] = '\0';
  param_1[1].playerNameValue[9] = '\0';
  param_1[1].playerNameValue[10] = '\0';
  param_1[1].playerNameValue[0xb] = '\0';
  uVar2 = 0xffffffff;
  param_1->_padding_ = (int)&ResearchAIModule::_vftable_;
  param_1[1].idValue.id = (int)this;
  *(AIModuleID **)param_1[1].idValue.name = this;
  pcVar4 = s_;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = param_1[1].playerNameValue + 0xc;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00411719
// Address: 00411719
ResearchAIModule * __thiscall FUN_00411719(ResearchAIModule *param_1,byte param_2)
{
  ResearchAIModule::~ResearchAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041173e
// Address: 0041173e
// [HELPER] s_Research_AI: "Research AI"
AIModule * __thiscall FUN_0041173e(AIModule *param_1,int param_2,int param_3)
{
  AIModuleID *this;
  char *pcVar1;
  ResourceItem RVar2;
  TechnologyItem *this_00;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 in_stack_fffffdd8 [92];
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_1a8;
  int iStack_1a4;
  int iStack_1a0;
  TechnologyItem *pTStack_19c;
  AIModule *pAStack_198;
  undefined1 *puStack_194;
  int aiStack_190 [4];
  ResourceItem RStack_180;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c7a5;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = 0x41177f;
  pAStack_198 = param_1;
  AIModule::AIModule(param_1,s_Research_AI,0x3ee,param_2,(void *)0x0);
  this = &param_1[1].idValue;
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  TechnologyItem::TechnologyItem((TechnologyItem *)this);
  pcVar1 = param_1[1].playerNameValue + 8;
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  param_1->_padding_ = (int)&ResearchAIModule::_vftable_;
  param_1[1].idValue.id = (int)this;
  *(AIModuleID **)param_1[1].idValue.name = this;
  rge_read(param_3,pcVar1,4);
  rge_read(param_3,&iStack_1a8,4);
  rge_read(param_3,param_1[1].playerNameValue + 0xc,iStack_1a8);
  iStack_1a4 = 0;
  param_1[1].playerNameValue[iStack_1a8 + 0xc] = '\0';
  if (0 < *(int *)pcVar1) {
    do {
      rge_read(param_3,&iStack_1a8,4);
      rge_read(param_3,acStack_110,iStack_1a8);
      acStack_110[iStack_1a8] = '\0';
      rge_read(param_3,&iStack_1a0,4);
      piVar4 = aiStack_190;
      iVar3 = 4;
      do {
        iVar6 = 0x411869;
        rge_read(param_3,&iStack_1a8,4);
        *piVar4 = iStack_1a8;
        piVar4 = piVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar3 = 0x411888;
      ResourceItem::ResourceItem(&RStack_180,4,aiStack_190);
      iVar8 = 0x54;
      uStack_4._0_1_ = 2;
      iVar7 = 0x411897;
      this_00 = (TechnologyItem *)operator_new(0x54);
      uStack_4._0_1_ = 3;
      pTStack_19c = this_00;
      if (this_00 == (TechnologyItem *)0x0) {
        iVar3 = 0;
      }
      else {
        puStack_194 = &stack0xfffffdd8;
        ResourceItem::ResourceItem((ResourceItem *)&stack0xfffffdd8,&RStack_180);
        RVar2.sortedIndexValue[4] = iVar5;
        RVar2._padding_ = in_stack_fffffdd8._0_4_;
        RVar2.next = (ResourceItem *)in_stack_fffffdd8._4_4_;
        RVar2.prev = (ResourceItem *)in_stack_fffffdd8._8_4_;
        RVar2.valueValue[0] = in_stack_fffffdd8._12_4_;
        RVar2.valueValue[1] = in_stack_fffffdd8._16_4_;
        RVar2.valueValue[2] = in_stack_fffffdd8._20_4_;
        RVar2.valueValue[3] = in_stack_fffffdd8._24_4_;
        RVar2.valueValue[4] = in_stack_fffffdd8._28_4_;
        RVar2.valueValue[5] = in_stack_fffffdd8._32_4_;
        RVar2.valueValue[6] = in_stack_fffffdd8._36_4_;
        RVar2.valueValue[7] = in_stack_fffffdd8._40_4_;
        RVar2.sortedValue[0] = in_stack_fffffdd8._44_4_;
        RVar2.sortedValue[1] = in_stack_fffffdd8._48_4_;
        RVar2.sortedValue[2] = in_stack_fffffdd8._52_4_;
        RVar2.sortedValue[3] = in_stack_fffffdd8._56_4_;
        RVar2.sortedValue[4] = in_stack_fffffdd8._60_4_;
        RVar2.sortedValue[5] = in_stack_fffffdd8._64_4_;
        RVar2.sortedValue[6] = in_stack_fffffdd8._68_4_;
        RVar2.sortedValue[7] = in_stack_fffffdd8._72_4_;
        RVar2.sortedIndexValue[0] = in_stack_fffffdd8._76_4_;
        RVar2.sortedIndexValue[1] = in_stack_fffffdd8._80_4_;
        RVar2.sortedIndexValue[2] = in_stack_fffffdd8._84_4_;
        RVar2.sortedIndexValue[3] = in_stack_fffffdd8._88_4_;
        RVar2.sortedIndexValue[5] = iVar6;
        RVar2.sortedIndexValue[6] = iVar3;
        RVar2.sortedIndexValue[7] = iVar7;
        RVar2.numberValue = iVar8;
        iVar3 = TechnologyItem::TechnologyItem(this_00,iStack_1a0,acStack_110,RVar2);
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      *(AIModuleID **)(iVar3 + 4) = &param_1[1].idValue;
      iVar6 = *(int *)param_1[1].idValue.name;
      *(int *)(iVar3 + 8) = iVar6;
      *(int *)(iVar6 + 4) = iVar3;
      *(int *)param_1[1].idValue.name = iVar3;
      ResourceItem::~ResourceItem(&RStack_180);
      iStack_1a4 = iStack_1a4 + 1;
    } while (iStack_1a4 < *(int *)(param_1[1].playerNameValue + 8));
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004119a9
// Address: 004119a9
void __thiscall FUN_004119a9(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004119bd
// Address: 004119bd
undefined4 __thiscall FUN_004119bd(int param_1,int param_2)
{
  char cVar1;
  char *pcVar2;
  ResourceItem *this;
  uint uVar3;
  uint uVar4;
  TechnologyItem *this_00;
  int iVar5;
  char *pcVar6;
  int iStack_10c;
  TechnologyItem *pTStack_108;
  char acStack_104 [260];
  
  pTStack_108 = (TechnologyItem *)param_1;
  rge_write(param_2,(void *)(param_1 + 0x148),4);
  uVar3 = 0xffffffff;
  pcVar2 = (char *)(param_1 + 0x14c);
  do {
    pcVar6 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar6 + -uVar3;
  pcVar6 = acStack_104;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_10c = ~uVar3 - 1;
  rge_write(param_2,&iStack_10c,4);
  uVar3 = 0xffffffff;
  pcVar2 = acStack_104;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  rge_write(param_2,acStack_104,~uVar3 - 1);
  this_00 = *(TechnologyItem **)(param_1 + 0xf8);
  pTStack_108 = (TechnologyItem *)((int)pTStack_108 + 0xf4);
  if (this_00 != pTStack_108) {
    do {
      if (this_00 == (TechnologyItem *)0x0) {
        return 1;
      }
      pcVar2 = TechnologyItem::name(this_00);
      uVar3 = 0xffffffff;
      do {
        pcVar6 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar2 = pcVar6 + -uVar3;
      pcVar6 = acStack_104;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar6 = pcVar6 + 1;
      }
      uVar3 = 0xffffffff;
      pcVar2 = acStack_104;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      iStack_10c = ~uVar3 - 1;
      rge_write(param_2,&iStack_10c,4);
      rge_write(param_2,acStack_104,iStack_10c);
      iStack_10c = TechnologyItem::id(this_00);
      rge_write(param_2,&iStack_10c,4);
      this = TechnologyItem::resourceCost(this_00);
      iVar5 = 0;
      do {
        iStack_10c = ResourceItem::value(this,iVar5);
        rge_write(param_2,&iStack_10c,4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 4);
      this_00 = this_00->next;
    } while (this_00 != pTStack_108);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00411b3a
// Address: 00411b3a
void __thiscall FUN_00411b3a(ResearchAIModule *param_1,int param_2)
{
  TechnologyItem *this;
  
  this = ResearchAIModule::item(param_1,param_2);
  if (this == (TechnologyItem *)0x0) {
    return;
  }
  TechnologyItem::resourceCost(this);
  return;
}

// --------------------------------------------------

// Function: FUN_00411b5b
// Address: 00411b5b
undefined4 FUN_00411b5b(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_00411b68
// Address: 00411b68
void FUN_00411b68(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00411b73
// Address: 00411b73
// [HELPER] s_NONE: "NONE"
// [HELPER] s_NULL: "NULL"
// [HELPER] s___c_d__s___d___d__d__d__d__d___d: "%*c%d %s %*d %*d %d %d %d %d %*d %*d %*d %*d %*d %*d"
int __thiscall FUN_00411b73(ResearchAIModule *param_1,char *param_2)
{
  char cVar1;
  byte bVar2;
  TechnologyItem *pTVar3;
  ResourceItem RVar4;
  char *pcVar5;
  int iVar6;
  TechnologyItem *pTVar7;
  uint uVar8;
  uint uVar9;
  AIModule *this;
  byte *pbVar10;
  char *pcVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  bool bVar13;
  undefined1 in_stack_fffffda4 [76];
  undefined1 *puVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iStack_1d8;
  int aiStack_1d4 [4];
  undefined1 *puStack_1c4;
  TechnologyItem *pTStack_1c0;
  char acStack_1bc [64];
  ResourceItem RStack_17c;
  undefined1 auStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c7e9;
  *unaff_FS_OFFSET = &uStack_c;
  if (0 < param_1->techTreeLengthValue) {
    ResearchAIModule::removeOldTechTree(param_1);
  }
  uVar8 = 0xffffffff;
  pcVar11 = param_1->techTreeNameValue;
  do {
    pcVar5 = param_2;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar5 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar5;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  pcVar5 = pcVar5 + -uVar8;
  pcVar12 = pcVar11;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar12 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar12 = pcVar12 + 1;
  }
  pbVar10 = &s_NONE;
  pcVar5 = pcVar11;
  do {
    bVar2 = *pcVar5;
    this = (AIModule *)(uint)bVar2;
    bVar13 = bVar2 < *pbVar10;
    if (bVar2 != *pbVar10) {
LAB_00411c09:
      iVar6 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
      goto LAB_00411c0e;
    }
    if (bVar2 == 0) break;
    bVar2 = pcVar5[1];
    this = (AIModule *)(uint)bVar2;
    bVar13 = bVar2 < pbVar10[1];
    if (bVar2 != pbVar10[1]) goto LAB_00411c09;
    pcVar5 = pcVar5 + 2;
    pbVar10 = pbVar10 + 2;
  } while (bVar2 != 0);
  iVar6 = 0;
LAB_00411c0e:
  if (iVar6 == 0) {
    if (pcVar11 == (char *)0x0) goto LAB_00411dad;
LAB_00411dcf:
    AIModule::logCommonHistory(this,(char *)param_1);
  }
  else {
    if (pcVar11 == (char *)0x0) {
LAB_00411dad:
      uVar8 = 0xffffffff;
      pcVar11 = &s_NULL;
      do {
        pcVar5 = pcVar11;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pcVar5 = pcVar11 + 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar5;
      } while (cVar1 != '\0');
      uVar8 = ~uVar8;
      pcVar11 = pcVar5 + -uVar8;
      pcVar5 = (char *)0x0;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (this = (AIModule *)(uVar8 & 3); this != (AIModule *)0x0;
          this = (AIModule *)((int)&this[-1].processFrameValue + 3)) {
        *pcVar5 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar5 = pcVar5 + 1;
      }
      goto LAB_00411dcf;
    }
    AIModule::logCommonHistory(this,(char *)param_1);
    sprintf();
    iVar6 = fopen();
    if (iVar6 == 0) goto LAB_00411de2;
    iVar6 = fgets();
    if (iVar6 != 0) {
      do {
        piVar16 = aiStack_1d4;
        pcVar11 = acStack_1bc;
        piVar15 = &iStack_1d8;
        puVar14 = auStack_10c;
        pcVar5 = s___c_d__s___d___d__d__d__d__d___d;
        iVar6 = 0x411cbd;
        sscanf();
        iVar17 = 0x411cd0;
        ResourceItem::ResourceItem(&RStack_17c,4,aiStack_1d4);
        iVar19 = 0x54;
        uStack_4 = 0;
        iVar18 = 0x411ce2;
        pTVar7 = (TechnologyItem *)operator_new(0x54);
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        pTStack_1c0 = pTVar7;
        if (pTVar7 == (TechnologyItem *)0x0) {
          pTVar7 = (TechnologyItem *)0x0;
        }
        else {
          puStack_1c4 = &stack0xfffffda4;
          ResourceItem::ResourceItem((ResourceItem *)&stack0xfffffda4,&RStack_17c);
          RVar4.sortedIndexValue[0] = iVar6;
          RVar4._padding_ = in_stack_fffffda4._0_4_;
          RVar4.next = (ResourceItem *)in_stack_fffffda4._4_4_;
          RVar4.prev = (ResourceItem *)in_stack_fffffda4._8_4_;
          RVar4.valueValue[0] = in_stack_fffffda4._12_4_;
          RVar4.valueValue[1] = in_stack_fffffda4._16_4_;
          RVar4.valueValue[2] = in_stack_fffffda4._20_4_;
          RVar4.valueValue[3] = in_stack_fffffda4._24_4_;
          RVar4.valueValue[4] = in_stack_fffffda4._28_4_;
          RVar4.valueValue[5] = in_stack_fffffda4._32_4_;
          RVar4.valueValue[6] = in_stack_fffffda4._36_4_;
          RVar4.valueValue[7] = in_stack_fffffda4._40_4_;
          RVar4.sortedValue[0] = in_stack_fffffda4._44_4_;
          RVar4.sortedValue[1] = in_stack_fffffda4._48_4_;
          RVar4.sortedValue[2] = in_stack_fffffda4._52_4_;
          RVar4.sortedValue[3] = in_stack_fffffda4._56_4_;
          RVar4.sortedValue[4] = in_stack_fffffda4._60_4_;
          RVar4.sortedValue[5] = in_stack_fffffda4._64_4_;
          RVar4.sortedValue[6] = in_stack_fffffda4._68_4_;
          RVar4.sortedValue[7] = in_stack_fffffda4._72_4_;
          RVar4.sortedIndexValue[1] = (int)puVar14;
          RVar4.sortedIndexValue[2] = (int)pcVar5;
          RVar4.sortedIndexValue[3] = (int)piVar15;
          RVar4.sortedIndexValue[4] = (int)pcVar11;
          RVar4.sortedIndexValue[5] = (int)piVar16;
          RVar4.sortedIndexValue[6] = iVar17;
          RVar4.sortedIndexValue[7] = iVar18;
          RVar4.numberValue = iVar19;
          pTVar7 = (TechnologyItem *)
                   TechnologyItem::TechnologyItem(pTVar7,iStack_1d8,acStack_1bc,RVar4);
        }
        pTVar7->next = &param_1->techTree;
        pTVar3 = (param_1->techTree).prev;
        pTVar7->prev = pTVar3;
        uStack_4 = 0xffffffff;
        pTVar3->next = pTVar7;
        iVar6 = param_1->techTreeLengthValue;
        (param_1->techTree).prev = pTVar7;
        param_1->techTreeLengthValue = iVar6 + 1;
        ResourceItem::~ResourceItem(&RStack_17c);
        iVar6 = fgets();
      } while (iVar6 != 0);
    }
    fclose();
    iVar6 = strstr();
    if (iVar6 != 0) {
      __unlink();
    }
  }
  iVar6 = 1;
LAB_00411de2:
  *unaff_FS_OFFSET = uStack_c;
  return iVar6;
}

// --------------------------------------------------

// Function: FUN_00411dfd
// Address: 00411dfd
undefined4 __fastcall FUN_00411dfd(int param_1)
{
  return *(undefined4 *)(param_1 + 0x148);
}

// --------------------------------------------------

// Function: FUN_00411e07
// Address: 00411e07
int __fastcall FUN_00411e07(int param_1)
{
  return param_1 + 0x14c;
}

// --------------------------------------------------

// Function: FUN_00411e17
// Address: 00411e17
void __fastcall FUN_00411e17(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0xf8);
  puVar1 = (undefined4 *)(param_1 + 0xf4);
  while ((puVar2 != puVar1 && (puVar2 != (undefined4 *)0x0))) {
    puVar3 = (undefined4 *)*puVar2;
    puVar2 = (undefined4 *)puVar2[1];
    (*(code *)*puVar3)(1);
  }
  *(undefined4 **)(param_1 + 0xf8) = puVar1;
  *(undefined4 **)(param_1 + 0xfc) = puVar1;
  *(undefined4 *)(param_1 + 0x148) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00411e62
// Address: 00411e62
TechnologyItem * __thiscall FUN_00411e62(int param_1,int param_2)
{
  int iVar1;
  TechnologyItem *this;
  
  this = *(TechnologyItem **)(param_1 + 0xf8);
  if (this != (TechnologyItem *)(param_1 + 0xf4)) {
    while (this != (TechnologyItem *)0x0) {
      iVar1 = TechnologyItem::id(this);
      if (iVar1 == param_2) {
        return this;
      }
      this = this->next;
      if (this == (TechnologyItem *)(param_1 + 0xf4)) {
        return (TechnologyItem *)0x0;
      }
    }
  }
  return (TechnologyItem *)0x0;
}

// --------------------------------------------------

// Function: FUN_00411eb5
// Address: 00411eb5
void __fastcall FUN_00411eb5(undefined4 *param_1)
{
  int iVar1;
  
  iVar1 = 8;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x1b] = 0;
  *param_1 = &ResourceItem::_vftable_;
  param_1 = param_1 + 0xb;
  do {
    param_1[-8] = 0xffffffff;
    *param_1 = 0xffffffff;
    param_1[8] = 0xffffffff;
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_00411eef
// Address: 00411eef
ResourceItem * __thiscall FUN_00411eef(ResourceItem *param_1,byte param_2)
{
  ResourceItem::~ResourceItem(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00411f0e
// Address: 00411f0e
void __thiscall FUN_00411f0e(undefined4 *param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x1b] = param_2;
  *param_1 = &ResourceItem::_vftable_;
  if (0 < param_2) {
    puVar1 = param_1 + 0xb;
    do {
      if (7 < iVar2) {
        return;
      }
      puVar1[-8] = 0;
      *puVar1 = 0xffffffff;
      puVar1[8] = 0xffffffff;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < (int)param_1[0x1b]);
  }
  if (iVar2 < 8) {
    param_1 = param_1 + iVar2 + 0xb;
    iVar2 = 8 - iVar2;
    do {
      param_1[-8] = 0xffffffff;
      *param_1 = 0xffffffff;
      param_1[8] = 0xffffffff;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00411f72
// Address: 00411f72
void __thiscall FUN_00411f72(undefined4 *param_1,int param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x1b] = param_2;
  *param_1 = &ResourceItem::_vftable_;
  if (0 < param_2) {
    puVar1 = param_1 + 0xb;
    do {
      if (7 < iVar2) {
        return;
      }
      iVar2 = iVar2 + 1;
      puVar1[-8] = *param_3;
      *puVar1 = 0xffffffff;
      puVar1[8] = 0xffffffff;
      param_3 = param_3 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < (int)param_1[0x1b]);
  }
  if (iVar2 < 8) {
    param_1 = param_1 + iVar2 + 0xb;
    iVar2 = 8 - iVar2;
    do {
      param_1[-8] = 0xffffffff;
      *param_1 = 0xffffffff;
      param_1[8] = 0xffffffff;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00411fe9
// Address: 00411fe9
void __thiscall FUN_00411fe9(undefined4 *param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar1 = *(int *)(param_2 + 0x6c);
  *param_1 = &ResourceItem::_vftable_;
  param_1[0x1b] = iVar1;
  if (0 < iVar1) {
    puVar3 = (undefined4 *)(param_2 + 0x4c);
    puVar2 = param_1 + 3;
    do {
      if (7 < iVar4) {
        return;
      }
      iVar4 = iVar4 + 1;
      *puVar2 = *(undefined4 *)((param_2 - (int)param_1) + (int)puVar2);
      puVar2[8] = puVar3[-8];
      puVar2[0x10] = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 < (int)param_1[0x1b]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00412042
// Address: 00412042
void __thiscall FUN_00412042(undefined4 *param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar1 = *(int *)(param_2 + 0x6c);
  *param_1 = &ResourceItem::_vftable_;
  param_1[0x1b] = iVar1;
  if (0 < iVar1) {
    puVar3 = (undefined4 *)(param_2 + 0x4c);
    puVar2 = param_1 + 3;
    do {
      if (7 < iVar4) {
        return;
      }
      iVar4 = iVar4 + 1;
      *puVar2 = *(undefined4 *)((param_2 - (int)param_1) + (int)puVar2);
      puVar2[8] = puVar3[-8];
      puVar2[0x10] = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 < (int)param_1[0x1b]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004120a2
// Address: 004120a2
void __fastcall FUN_004120a2(undefined4 *param_1)
{
  *param_1 = &ResourceItem::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_004120b7
// Address: 004120b7
void __thiscall FUN_004120b7(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x6c) == *(int *)(param_2 + 0x6c)) &&
     (iVar2 = 0, 0 < *(int *)(param_1 + 0x6c))) {
    piVar1 = (int *)(param_1 + 0xc);
    do {
      iVar2 = iVar2 + 1;
      *piVar1 = *piVar1 + *(int *)((param_2 - param_1) + (int)piVar1);
      piVar1 = piVar1 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x6c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004120f6
// Address: 004120f6
undefined4 FUN_004120f6(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 != *(int *)(param_2 + 0x6c)) {
    return 0;
  }
  iVar3 = 0;
  if (0 < iVar1) {
    piVar2 = (int *)(param_1 + 0xc);
    do {
      if (*piVar2 != *(int *)((param_2 - param_1) + (int)piVar2)) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < iVar1);
  }
  return 1;
}

// --------------------------------------------------

// Function: operator==
// Address: 00412100
/* int __cdecl operator==(class ResourceItem const &,class ResourceItem const &) */

int __cdecl operator==(ResourceItem *param_1,ResourceItem *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = param_1->numberValue;
  if (iVar1 != param_2->numberValue) {
    return 0;
  }
  iVar3 = 0;
  if (0 < iVar1) {
    piVar2 = param_1->valueValue;
    do {
      if (*piVar2 != *(int *)(((int)param_2 - (int)param_1) + (int)piVar2)) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < iVar1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041213e
// Address: 0041213e
undefined4 FUN_0041213e(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 != *(int *)(param_2 + 0x6c)) {
    return 1;
  }
  iVar3 = 0;
  if (0 < iVar1) {
    piVar2 = (int *)(param_1 + 0xc);
    do {
      if (*piVar2 != *(int *)((param_2 - param_1) + (int)piVar2)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < iVar1);
  }
  return 0;
}

// --------------------------------------------------

// Function: operator!=
// Address: 00412140
/* int __cdecl operator!=(class ResourceItem const &,class ResourceItem const &) */

int __cdecl operator!=(ResourceItem *param_1,ResourceItem *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = param_1->numberValue;
  if (iVar1 != param_2->numberValue) {
    return 1;
  }
  iVar3 = 0;
  if (0 < iVar1) {
    piVar2 = param_1->valueValue;
    do {
      if (*piVar2 != *(int *)(((int)param_2 - (int)param_1) + (int)piVar2)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < iVar1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041217e
// Address: 0041217e
undefined4 __thiscall FUN_0041217e(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x6c))) {
    return *(undefined4 *)(param_1 + 0xc + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0041219a
// Address: 0041219a
void __thiscall FUN_0041219a(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x6c))) {
    *(undefined4 *)(param_1 + 0xc + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004121b8
// Address: 004121b8
void __thiscall FUN_004121b8(int param_1,int param_2,int param_3)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x6c))) {
    *(int *)(param_1 + 0xc + param_2 * 4) = *(int *)(param_1 + 0xc + param_2 * 4) + param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004121f3
// Address: 004121f3
undefined4 __fastcall FUN_004121f3(int param_1)
{
  return *(undefined4 *)(param_1 + 0x6c);
}

// --------------------------------------------------

// Function: FUN_00412204
// Address: 00412204
int __thiscall FUN_00412204(ResourceItem *param_1,int param_2)
{
  int iVar1;
  
  if (param_2 <= param_1->numberValue) {
    iVar1 = ResourceItem::sortLarge(param_1);
    if (iVar1 == 1) {
      return param_1->sortedValue[param_2 + 7];
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_00412238
// Address: 00412238
undefined4 __fastcall FUN_00412238(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piStack_10;
  int iStack_c;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    puVar2 = (undefined4 *)(param_1 + 0x2c);
    do {
      *puVar2 = puVar2[-8];
      puVar2[8] = iVar4;
      iVar4 = iVar4 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x6c));
  }
  iVar4 = *(int *)(param_1 + 0x6c);
  iStack_c = 0;
  if (0 < iVar4) {
    piVar7 = (int *)(param_1 + 0x2c);
    do {
      iVar1 = iStack_c + 1;
      iVar5 = iStack_c;
      if (iVar1 < iVar4) {
        iVar6 = (-0x2c - param_1) + (int)piVar7;
        iVar3 = iVar1;
        piStack_10 = piVar7;
        do {
          piStack_10 = piStack_10 + 1;
          if (*(int *)(param_1 + 0x2c + iVar6) < *piStack_10) {
            iVar6 = iVar3 * 4;
            iVar5 = iVar3;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar4);
      }
      if (iVar5 != iStack_c) {
        iVar4 = *piVar7;
        *piVar7 = *(int *)(param_1 + 0x2c + iVar5 * 4);
        *(int *)(param_1 + 0x2c + iVar5 * 4) = iVar4;
        iVar4 = piVar7[8];
        piVar7[8] = *(int *)(param_1 + 0x4c + iVar5 * 4);
        *(int *)(param_1 + 0x4c + iVar5 * 4) = iVar4;
      }
      iVar4 = *(int *)(param_1 + 0x6c);
      piVar7 = piVar7 + 1;
      iStack_c = iVar1;
    } while (iVar1 < iVar4);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00412308
// Address: 00412308
// [HELPER] s_Resource_AI: "Resource AI"
AIModule * __thiscall
FUN_00412308(AIModule *param_1,void *param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c808;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  AIModule::AIModule(param_1,s_Resource_AI,0x3ef,param_3,param_2);
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  param_1[1].idValue._padding_ = param_4;
  param_1->_padding_ = (int)&ResourceAIModule::_vftable_;
  pvVar2 = operator_new(param_4 * 4);
  param_1[1].idValue.id = (int)pvVar2;
  pvVar2 = operator_new(param_1[1].idValue._padding_ << 2);
  iVar1 = param_1[1].idValue._padding_;
  *(void **)param_1[1].idValue.name = pvVar2;
  pvVar2 = operator_new(iVar1 << 2);
  iVar1 = param_1[1].idValue._padding_;
  *(void **)(param_1[1].idValue.name + 4) = pvVar2;
  pvVar2 = operator_new(iVar1 << 2);
  *(void **)(param_1[1].idValue.name + 8) = pvVar2;
  pvVar2 = operator_new(param_1[1].idValue._padding_ << 2);
  iVar1 = param_1[1].idValue._padding_;
  *(void **)(param_1[1].idValue.name + 0xc) = pvVar2;
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = iVar3 + 1;
      *(undefined4 *)(param_1[1].idValue.id + -4 + iVar3 * 4) = param_5;
      *(undefined4 *)(*(int *)param_1[1].idValue.name + -4 + iVar3 * 4) = param_6;
      *(undefined4 *)(*(int *)(param_1[1].idValue.name + 4) + -4 + iVar3 * 4) = param_7;
      *(undefined4 *)(*(int *)(param_1[1].idValue.name + 0xc) + -4 + iVar3 * 4) = 0;
      *(undefined4 *)(*(int *)(param_1[1].idValue.name + 8) + -4 + iVar3 * 4) = 0;
    } while (iVar3 < param_1[1].idValue._padding_);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412455
// Address: 00412455
ResourceAIModule * __thiscall FUN_00412455(ResourceAIModule *param_1,byte param_2)
{
  ResourceAIModule::~ResourceAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041247e
// Address: 0041247e
void __fastcall FUN_0041247e(AIModule *param_1)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055c828;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&ResourceAIModule::_vftable_;
  iVar1 = 0;
  uStack_4 = 0;
  operator_delete((void *)param_1[1].idValue.id);
  operator_delete(*(void **)param_1[1].idValue.name);
  operator_delete(*(void **)(param_1[1].idValue.name + 4));
  if (0 < param_1[1].idValue._padding_) {
    do {
      operator_delete(*(void **)(*(int *)(param_1[1].idValue.name + 8) + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[1].idValue._padding_);
  }
  operator_delete(*(void **)(param_1[1].idValue.name + 8));
  operator_delete(*(void **)(param_1[1].idValue.name + 0xc));
  uStack_4 = 0xffffffff;
  AIModule::~AIModule(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0041253c
// Address: 0041253c
undefined4 FUN_0041253c(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00412545
// Address: 00412545
undefined4 FUN_00412545(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00412555
// Address: 00412555
void FUN_00412555(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00412563
// Address: 00412563
void __thiscall FUN_00412563(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0041257d
// Address: 0041257d
undefined4 __fastcall FUN_0041257d(int param_1)
{
  return *(undefined4 *)(param_1 + 0xf4);
}

// --------------------------------------------------

// Function: FUN_00412587
// Address: 00412587
undefined4 __thiscall FUN_00412587(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xf4))) {
    return *(undefined4 *)(*(int *)(param_1 + 0xf8) + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004125b2
// Address: 004125b2
undefined4 __thiscall FUN_004125b2(int param_1,ResourceItem *param_2)
{
  int iVar1;
  int iVar2;
  
  if (param_2 == (ResourceItem *)0x0) {
    return 0;
  }
  iVar1 = ResourceItem::number(param_2);
  if (*(int *)(param_1 + 0xf4) != iVar1) {
    return 0;
  }
  iVar2 = 0;
  iVar1 = ResourceItem::number(param_2);
  if (iVar1 < 1) {
    return 1;
  }
  do {
    iVar1 = ResourceItem::value(param_2,iVar2);
    if (*(int *)(*(int *)(param_1 + 0xf8) + iVar2 * 4) < iVar1) {
      return 0;
    }
    iVar2 = iVar2 + 1;
    iVar1 = ResourceItem::number(param_2);
  } while (iVar2 < iVar1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00412636
// Address: 00412636
int __thiscall FUN_00412636(int param_1,ResourceItem *param_2)
{
  int iVar1;
  int iVar2;
  
  if (param_2 == (ResourceItem *)0x0) {
    return 0;
  }
  iVar1 = ResourceItem::number(param_2);
  if (*(int *)(param_1 + 0xf4) == iVar1) {
    iVar2 = 0;
    iVar1 = ResourceItem::number(param_2);
    if (0 < iVar1) {
      do {
        iVar1 = ResourceItem::value(param_2,iVar2);
        if (*(int *)(*(int *)(param_1 + 0xf8) + iVar2 * 4) < iVar1) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        iVar1 = ResourceItem::number(param_2);
      } while (iVar2 < iVar1);
      return -1;
    }
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_004126aa
// Address: 004126aa
undefined4 __thiscall FUN_004126aa(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xf4))) {
    return *(undefined4 *)(*(int *)(param_1 + 0xfc) + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004126d2
// Address: 004126d2
undefined4 __thiscall FUN_004126d2(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xf4))) {
    return *(undefined4 *)(*(int *)(param_1 + 0x100) + param_2 * 4);
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00412702
// Address: 00412702
// [HELPER] s___setResource__r__d___d_: "  setResource: r[%d]=%d."
// [HELPER] s_setResource__n__d__v__d_: "setResource: n=%d, v=%d."
void __thiscall FUN_00412702(AIModule *param_1,int param_2,undefined4 param_3)
{
  AIModule *this;
  
  AIModule::logCommonHistory(param_1,(char *)param_1,s_setResource__n__d__v__d_,param_2,param_3);
  if ((-1 < param_2) && (param_2 < param_1[1].idValue._padding_)) {
    *(undefined4 *)(param_1[1].idValue.id + param_2 * 4) = param_3;
    this = (AIModule *)param_1[1].idValue.id;
    AIModule::logCommonHistory
              (this,(char *)param_1,s___setResource__r__d___d_,param_2,
               *(undefined4 *)((this->idValue).name + param_2 * 4 + -0xc));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00412761
// Address: 00412761
void __thiscall FUN_00412761(ResourceAIModule *param_1,ResourceItem *param_2)
{
  int iVar1;
  int iVar2;
  
  if (param_2 != (ResourceItem *)0x0) {
    iVar1 = ResourceItem::number(param_2);
    if (param_1->numberResourcesValue == iVar1) {
      iVar2 = 0;
      iVar1 = ResourceItem::number(param_2);
      if (0 < iVar1) {
        do {
          iVar1 = ResourceItem::value(param_2,iVar2);
          ResourceAIModule::setResource(param_1,iVar2,iVar1);
          iVar2 = iVar2 + 1;
          iVar1 = ResourceItem::number(param_2);
        } while (iVar2 < iVar1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004127bc
// Address: 004127bc
// [HELPER] s___incrementResource__r__d___d_: "  incrementResource: r[%d]=%d."
// [HELPER] s_incrementResource__n__d__v__d_: "incrementResource: n=%d, v=%d."
void __thiscall FUN_004127bc(AIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  AIModule *this;
  
  AIModule::logCommonHistory
            (param_1,(char *)param_1,s_incrementResource__n__d__v__d_,param_2,param_3);
  if (((-1 < param_2) && (param_2 < param_1[1].idValue._padding_)) &&
     (iVar1 = param_1[1].idValue.id,
     *(int *)(iVar1 + param_2 * 4) = *(int *)(iVar1 + param_2 * 4) + param_3, param_3 != 0)) {
    this = (AIModule *)param_1[1].idValue.id;
    AIModule::logCommonHistory
              (this,(char *)param_1,s___incrementResource__r__d___d_,param_2,
               *(undefined4 *)((this->idValue).name + param_2 * 4 + -0xc));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041281c
// Address: 0041281c
void __thiscall FUN_0041281c(ResourceAIModule *param_1,ResourceItem *param_2)
{
  int iVar1;
  int iVar2;
  
  if (param_2 != (ResourceItem *)0x0) {
    iVar1 = ResourceItem::number(param_2);
    if (param_1->numberResourcesValue == iVar1) {
      iVar2 = 0;
      iVar1 = ResourceItem::number(param_2);
      if (0 < iVar1) {
        do {
          iVar1 = ResourceItem::value(param_2,iVar2);
          ResourceAIModule::incrementResource(param_1,iVar2,iVar1);
          iVar2 = iVar2 + 1;
          iVar1 = ResourceItem::number(param_2);
        } while (iVar2 < iVar1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041286c
// Address: 0041286c
// [HELPER] s___decrementResource__r__d___d_: "  decrementResource: r[%d]=%d."
// [HELPER] s_decrementResource__n__d__v__d_: "decrementResource: n=%d, v=%d."
void __thiscall FUN_0041286c(AIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  AIModule *this;
  
  AIModule::logCommonHistory
            (param_1,(char *)param_1,s_decrementResource__n__d__v__d_,param_2,param_3);
  if (((-1 < param_2) && (param_2 < param_1[1].idValue._padding_)) &&
     (iVar1 = param_1[1].idValue.id,
     *(int *)(iVar1 + param_2 * 4) = *(int *)(iVar1 + param_2 * 4) - param_3, param_3 != 0)) {
    this = (AIModule *)param_1[1].idValue.id;
    AIModule::logCommonHistory
              (this,(char *)param_1,s___decrementResource__r__d___d_,param_2,
               *(undefined4 *)((this->idValue).name + param_2 * 4 + -0xc));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004128cc
// Address: 004128cc
void __thiscall FUN_004128cc(ResourceAIModule *param_1,ResourceItem *param_2)
{
  int iVar1;
  int iVar2;
  
  if (param_2 != (ResourceItem *)0x0) {
    iVar1 = ResourceItem::number(param_2);
    if (param_1->numberResourcesValue == iVar1) {
      iVar2 = 0;
      iVar1 = ResourceItem::number(param_2);
      if (0 < iVar1) {
        do {
          iVar1 = ResourceItem::value(param_2,iVar2);
          ResourceAIModule::decrementResource(param_1,iVar2,iVar1);
          iVar2 = iVar2 + 1;
          iVar1 = ResourceItem::number(param_2);
        } while (iVar2 < iVar1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041291c
// Address: 0041291c
void __thiscall FUN_0041291c(int param_1,int param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xf4))) {
    *(undefined4 *)(*(int *)(param_1 + 0xfc) + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041296d
// Address: 0041296d
void __thiscall FUN_0041296d(int param_1,int param_2,undefined4 param_3)
{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  
  param_2 = param_2 * 4;
  pvVar2 = operator_new(*(int *)(*(int *)(param_1 + 0x108) + param_2) * 4 + 4);
  iVar3 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x108) + param_2)) {
    do {
      iVar3 = iVar3 + 1;
      *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
           *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x104) + param_2) + -4 + iVar3 * 4);
    } while (iVar3 < *(int *)(*(int *)(param_1 + 0x108) + param_2));
  }
  *(undefined4 *)((int)pvVar2 + iVar3 * 4) = param_3;
  pvVar1 = *(void **)(*(int *)(param_1 + 0x104) + param_2);
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
  }
  *(void **)(*(int *)(param_1 + 0x104) + param_2) = pvVar2;
  *(int *)(*(int *)(param_1 + 0x108) + param_2) = *(int *)(*(int *)(param_1 + 0x108) + param_2) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00412a01
// Address: 00412a01
// [HELPER] s_Entering_isResourceType__r__d__t: "Entering isResourceType: r=%d, t=%d."
// [HELPER] s___No_match___Returning_FALSE_: "  No match!  Returning FALSE."
// [HELPER] s___There_are__d_resource_types_fo: "  There are %d resource types for resource %d."
// [HELPER] s_____Checking_against_type__d_: "    Checking against type %d."
// [HELPER] s_______Match___Returning_TRUE_: "      Match!  Returning TRUE."
undefined4 __thiscall FUN_00412a01(AIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  AIModule *extraout_ECX;
  AIModule *this;
  AIModule *pAVar3;
  int iVar4;
  
  AIModule::logCommonHistory
            (param_1,(char *)param_1,s_Entering_isResourceType__r__d__t,param_2,param_3);
  iVar1 = param_2 * 4;
  pAVar3 = *(AIModule **)(*(int *)(param_1[1].idValue.name + 0xc) + iVar1);
  AIModule::logCommonHistory
            (pAVar3,(char *)param_1,s___There_are__d_resource_types_fo,pAVar3,param_2);
  iVar4 = 0;
  pAVar3 = extraout_ECX;
  if (0 < *(int *)(*(int *)(param_1[1].idValue.name + 0xc) + iVar1)) {
    iVar2 = *(int *)(*(int *)(param_1[1].idValue.name + 8) + iVar1);
    do {
      pAVar3 = *(AIModule **)(iVar2 + iVar4 * 4);
      AIModule::logCommonHistory(pAVar3,(char *)param_1,s_____Checking_against_type__d_,pAVar3);
      iVar2 = *(int *)(*(int *)(param_1[1].idValue.name + 8) + iVar1);
      if (*(int *)(iVar2 + iVar4 * 4) == param_3) {
        AIModule::logCommonHistory(this,(char *)param_1,s_______Match___Returning_TRUE_);
        return 1;
      }
      pAVar3 = *(AIModule **)(param_1[1].idValue.name + 0xc);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((pAVar3->idValue).name + iVar1 + -0xc));
  }
  AIModule::logCommonHistory(pAVar3,(char *)param_1,s___No_match___Returning_FALSE_);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00412ac2
// Address: 00412ac2
undefined4 __thiscall FUN_00412ac2(int param_1,int param_2)
{
  return *(undefined4 *)(*(int *)(param_1 + 0x108) + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_00412ae6
// Address: 00412ae6
// [HELPER] s_Strategy_AI: "Strategy AI"
AIModule * __thiscall FUN_00412ae6(AIModule *param_1,void *param_2,int param_3)
{
  AIModule::AIModule(param_1,s_Strategy_AI,0x3f0,param_3,param_2);
  param_1->_padding_ = (int)&StrategyAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412b1a
// Address: 00412b1a
StrategyAIModule * __thiscall FUN_00412b1a(StrategyAIModule *param_1,byte param_2)
{
  StrategyAIModule::~StrategyAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412b3e
// Address: 00412b3e
void __fastcall FUN_00412b3e(AIModule *param_1)
{
  param_1->_padding_ = (int)&StrategyAIModule::_vftable_;
  AIModule::~AIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00412b4b
// Address: 00412b4b
// [HELPER] s_TacAI: "TacAI"
AIModule * __thiscall FUN_00412b4b(AIModule *param_1,void *param_2,int param_3)
{
  AIModule::AIModule(param_1,s_TacAI,0x3f1,param_3,param_2);
  param_1->_padding_ = (int)&TacticalAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412b7a
// Address: 00412b7a
TacticalAIModule * __thiscall FUN_00412b7a(TacticalAIModule *param_1,byte param_2)
{
  TacticalAIModule::~TacticalAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412b9e
// Address: 00412b9e
void __fastcall FUN_00412b9e(AIModule *param_1)
{
  param_1->_padding_ = (int)&TacticalAIModule::_vftable_;
  AIModule::~AIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00412bab
// Address: 00412bab
// [HELPER] s_: ""
undefined4 * __fastcall FUN_00412bab(undefined4 *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x14] = 0;
  *param_1 = &TechnologyItem::_vftable_;
  pcVar4 = s_;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = (char *)(param_1 + 4);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412bf2
// Address: 00412bf2
TechnologyItem * __thiscall FUN_00412bf2(TechnologyItem *param_1,byte param_2)
{
  TechnologyItem::~TechnologyItem(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412c1e
// Address: 00412c1e
undefined4 * __thiscall FUN_00412c1e(undefined4 *param_1,undefined4 param_2,char *param_3)
{
  char cVar1;
  ResourceItem *this;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055c853;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_2;
  *param_1 = &TechnologyItem::_vftable_;
  this = (ResourceItem *)operator_new(0x70);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  if (this == (ResourceItem *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ResourceItem::ResourceItem(this,(ResourceItem *)&stack0x0000000c);
  }
  param_1[0x14] = uVar2;
  uVar3 = 0xffffffff;
  do {
    pcVar5 = param_3;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  uStack_4 = 0xffffffff;
  pcVar5 = pcVar5 + -uVar3;
  pcVar6 = (char *)(param_1 + 4);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  ResourceItem::~ResourceItem((ResourceItem *)&stack0x0000000c);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412cc8
// Address: 00412cc8
undefined4 * __thiscall FUN_00412cc8(undefined4 *param_1,int param_2)
{
  char cVar1;
  ResourceItem *this;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c86b;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  *param_1 = &TechnologyItem::_vftable_;
  param_1[3] = uVar2;
  this = (ResourceItem *)operator_new(0x70);
  uStack_4 = 0;
  if (this == (ResourceItem *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ResourceItem::ResourceItem(this,*(ResourceItem **)(param_2 + 0x50));
  }
  param_1[0x14] = uVar2;
  uVar3 = 0xffffffff;
  pcVar5 = (char *)(param_2 + 0x10);
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = (char *)(param_1 + 4);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412d63
// Address: 00412d63
void __fastcall FUN_00412d63(undefined4 *param_1)
{
  *param_1 = &TechnologyItem::_vftable_;
  if ((undefined4 *)param_1[0x14] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x14])(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00412d84
// Address: 00412d84
bool FUN_00412d84(int param_1,int param_2)
{
  return *(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc);
}

// --------------------------------------------------

// Function: operator==
// Address: 00412d90
/* int __cdecl operator==(class TechnologyItem const &,class TechnologyItem const &) */

int __cdecl operator==(TechnologyItem *param_1,TechnologyItem *param_2)
{
  return (uint)(param_1->idValue == param_2->idValue);
}

// --------------------------------------------------

// Function: FUN_00412da8
// Address: 00412da8
bool FUN_00412da8(int param_1,int param_2)
{
  return *(int *)(param_1 + 0xc) != *(int *)(param_2 + 0xc);
}

// --------------------------------------------------

// Function: operator!=
// Address: 00412db0
/* int __cdecl operator!=(class TechnologyItem const &,class TechnologyItem const &) */

int __cdecl operator!=(TechnologyItem *param_1,TechnologyItem *param_2)
{
  return (uint)(param_1->idValue != param_2->idValue);
}

// --------------------------------------------------

// Function: FUN_00412dc8
// Address: 00412dc8
bool FUN_00412dc8(int param_1,int param_2)
{
  return *(int *)(param_1 + 0xc) < *(int *)(param_2 + 0xc);
}

// --------------------------------------------------

// Function: operator<
// Address: 00412dd0
/* int __cdecl operator<(class TechnologyItem const &,class TechnologyItem const &) */

int __cdecl operator<(TechnologyItem *param_1,TechnologyItem *param_2)
{
  return (uint)(param_1->idValue < param_2->idValue);
}

// --------------------------------------------------

// Function: FUN_00412de8
// Address: 00412de8
bool FUN_00412de8(int param_1,int param_2)
{
  return *(int *)(param_2 + 0xc) < *(int *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: operator>
// Address: 00412df0
/* int __cdecl operator>(class TechnologyItem const &,class TechnologyItem const &) */

int __cdecl operator>(TechnologyItem *param_1,TechnologyItem *param_2)
{
  return (uint)(param_2->idValue < param_1->idValue);
}

// --------------------------------------------------

// Function: FUN_00412e08
// Address: 00412e08
undefined4 __fastcall FUN_00412e08(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_00412e14
// Address: 00412e14
int __fastcall FUN_00412e14(int param_1)
{
  return param_1 + 0x10;
}

// --------------------------------------------------

// Function: FUN_00412e24
// Address: 00412e24
undefined4 __fastcall FUN_00412e24(int param_1)
{
  return *(undefined4 *)(param_1 + 0x50);
}

// --------------------------------------------------

// Function: FUN_00412e34
// Address: 00412e34
// [HELPER] s_Trade_AI: "Trade AI"
AIModule * __thiscall FUN_00412e34(AIModule *param_1,void *param_2,int param_3)
{
  AIModule::AIModule(param_1,s_Trade_AI,0x3f2,param_3,param_2);
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TradeAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412e74
// Address: 00412e74
TradeAIModule * __thiscall FUN_00412e74(TradeAIModule *param_1,byte param_2)
{
  TradeAIModule::~TradeAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412e9e
// Address: 00412e9e
// [HELPER] s_Trade_AI: "Trade AI"
AIModule * __thiscall FUN_00412e9e(AIModule *param_1,int param_2)
{
  AIModule::AIModule(param_1,s_Trade_AI,0x3f2,param_2,(void *)0x0);
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TradeAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00412ecf
// Address: 00412ecf
void __fastcall FUN_00412ecf(AIModule *param_1)
{
  param_1->_padding_ = (int)&TradeAIModule::_vftable_;
  AIModule::~AIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00412edb
// Address: 00412edb
void __thiscall FUN_00412edb(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xf0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00412eed
// Address: 00412eed
undefined4 FUN_00412eed(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_00412ef8
// Address: 00412ef8
UnitAIModule * __thiscall FUN_00412ef8(UnitAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  int *piVar1;
  OrderEvent *pOVar2;
  NotifyEvent *pNVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c88b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->objectValue = param_2;
  param_1->moodValue = -1;
  param_1->objectCategoryValue = -1;
  param_1->orderQueueSizeValue = 0;
  param_1->orderQueueMaxSizeValue = param_3;
  param_1->notifyQueueSizeValue = 0;
  param_1->notifyQueueMaxSizeValue = param_3;
  param_1->currentOrderValue = -1;
  param_1->currentOrderPriorityValue = -1;
  param_1->currentActionValue = -1;
  param_1->currentTargetValue = -1;
  param_1->currentTargetTypeValue = -1;
  param_1->currentTargetXValue = -1.0;
  param_1->currentTargetYValue = -1.0;
  param_1->currentTargetZValue = -1.0;
  param_1->desiredTargetDistanceValue = 2.0;
  param_1->defendTargetValue = -1;
  param_1->lastOrderValue = -1;
  param_1->lastActionValue = -1;
  param_1->lastTargetValue = -1;
  param_1->lastTargetTypeValue = -1;
  (param_1->attackingUnitsValue).value = (int *)0x0;
  (param_1->attackingUnitsValue).numberValue = 0;
  (param_1->attackingUnitsValue).desiredNumberValue = 0;
  (param_1->attackingUnitsValue).maximumSizeValue = 10;
  piVar1 = (int *)operator_new(0x28);
  (param_1->attackingUnitsValue).value = piVar1;
  uStack_4 = 0;
  param_1->waypointQueueSizeValue = 0;
  param_1->lastUpdateTimeValue = 0;
  param_1->idleTimerValue = 0;
  param_1->idleTimeoutValue = 3000;
  param_1->secondaryTimerValue = 0;
  param_1->lookAroundTimerValue = 0;
  param_1->lookAroundTimeoutValue = 1000;
  param_1->defenseBufferValue = 1.0;
  param_1->importantObjects = (int *)0x0;
  param_1->numberImportantObjects = 0;
  param_1->playStatus = (AIPlayStatus *)0x0;
  param_1->stopAfterTargetKilledValue = '\0';
  param_1->_padding_ = (int)&UnitAIModule::_vftable_;
  if (param_2 != (RGE_Static_Object *)0x0) {
    param_1->objectCategoryValue = (int)param_2->master_obj->object_group;
    param_1->defenseBufferValue = param_2->master_obj->los;
  }
  pOVar2 = (OrderEvent *)operator_new(param_1->orderQueueMaxSizeValue * 0x24);
  param_1->orderQueueValue = pOVar2;
  pNVar3 = (NotifyEvent *)operator_new(param_1->notifyQueueMaxSizeValue * 0x18);
  param_1->notifyQueueValue = pNVar3;
  (param_1->lastWorldPositionValue).x = -1.0;
  (param_1->lastWorldPositionValue).y = -1.0;
  (param_1->lastWorldPositionValue).z = -1.0;
  UnitAIModule::setAdjustedIdleTimeout(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00413064
// Address: 00413064
UnitAIModule * __thiscall FUN_00413064(UnitAIModule *param_1,byte param_2)
{
  UnitAIModule::~UnitAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041308e
// Address: 0041308e
void __fastcall FUN_0041308e(undefined4 *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055c8ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UnitAIModule::_vftable_;
  uStack_4 = 0;
  if ((void *)param_1[6] != (void *)0x0) {
    operator_delete((void *)param_1[6]);
    param_1[6] = 0;
  }
  if ((void *)param_1[9] != (void *)0x0) {
    operator_delete((void *)param_1[9]);
    param_1[9] = 0;
  }
  if ((void *)param_1[0x49] != (void *)0x0) {
    operator_delete((void *)param_1[0x49]);
    param_1[0x49] = 0;
  }
  if ((void *)param_1[0x4b] != (void *)0x0) {
    operator_delete((void *)param_1[0x4b]);
    param_1[0x4b] = 0;
  }
  uStack_4 = 0xffffffff;
  if ((void *)param_1[0x18] != (void *)0x0) {
    operator_delete((void *)param_1[0x18]);
    param_1[0x18] = 0;
  }
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00413147
// Address: 00413147
void __thiscall FUN_00413147(int param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_2;
  rge_write(param_2,(void *)(param_1 + 8),4);
  rge_write(iVar1,(void *)(param_1 + 0x28),4);
  rge_write(iVar1,(void *)(param_1 + 0x2c),4);
  rge_write(iVar1,(void *)(param_1 + 0x30),4);
  rge_write(iVar1,(void *)(param_1 + 0x34),4);
  rge_write(iVar1,(void *)(param_1 + 0x38),4);
  rge_write(iVar1,(void *)(param_1 + 0x3c),4);
  rge_write(iVar1,(void *)(param_1 + 0x40),4);
  rge_write(iVar1,(void *)(param_1 + 0x44),4);
  rge_write(iVar1,(void *)(param_1 + 0x48),4);
  rge_write(iVar1,(void *)(param_1 + 0x54),4);
  rge_write(iVar1,(void *)(param_1 + 0x50),4);
  rge_write(iVar1,(void *)(param_1 + 0x58),4);
  rge_write(iVar1,(void *)(param_1 + 0x5c),4);
  rge_write(iVar1,(void *)(param_1 + 0xf4),4);
  rge_write(iVar1,(void *)(param_1 + 0xf8),4);
  rge_write(iVar1,(void *)(param_1 + 0x100),4);
  rge_write(iVar1,(void *)(param_1 + 0xfc),4);
  rge_write(iVar1,(void *)(param_1 + 0x104),4);
  rge_write(iVar1,(void *)(param_1 + 0x108),4);
  rge_write(iVar1,(void *)(param_1 + 0x10c),4);
  rge_write(iVar1,(void *)(param_1 + 0x4c),4);
  rge_write(iVar1,(void *)(param_1 + 0x120),4);
  rge_write(iVar1,(void *)(param_1 + 0x110),0x10);
  rge_write(iVar1,(int *)(param_1 + 0x10),4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar4 = 0;
    do {
      rge_write(iVar1,(void *)(iVar4 + *(int *)(param_1 + 0x18)),0x24);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x24;
    } while (iVar3 < *(int *)(param_1 + 0x10));
  }
  rge_write(iVar1,(int *)(param_1 + 0x1c),4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar4 = 0;
    do {
      rge_write(iVar1,(void *)(iVar4 + *(int *)(param_1 + 0x24)),0x18);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar3 < *(int *)(param_1 + 0x1c));
  }
  param_2 = *(undefined4 *)(param_1 + 100);
  rge_write(iVar1,&param_2,4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    do {
      if (*(int *)(param_1 + 0x6c) + -1 < iVar3) {
        pvVar2 = operator_new(iVar3 * 4 + 4);
        if (pvVar2 != (void *)0x0) {
          iVar4 = 0;
          if (0 < *(int *)(param_1 + 0x6c)) {
            do {
              if (iVar3 + 1 <= iVar4) break;
              iVar4 = iVar4 + 1;
              *(undefined4 *)((int)pvVar2 + iVar4 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x60) + -4 + iVar4 * 4);
            } while (iVar4 < *(int *)(param_1 + 0x6c));
          }
          operator_delete(*(void **)(param_1 + 0x60));
          *(void **)(param_1 + 0x60) = pvVar2;
          *(int *)(param_1 + 0x6c) = iVar3 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 0x60) + iVar3 * 4);
      rge_write(iVar1,&param_2,4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 100));
  }
  if (*(int *)(param_1 + 300) == 0) {
    param_2 = 0;
    rge_write(iVar1,&param_2,4);
  }
  else {
    param_2 = 1;
    rge_write(iVar1,&param_2,4);
    AIPlayStatus::save(*(AIPlayStatus **)(param_1 + 300),iVar1);
  }
  rge_write(iVar1,(void *)(param_1 + 0x130),1);
  return;
}

// --------------------------------------------------

// Function: FUN_00413446
// Address: 00413446
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00413446(UnitAIModule *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  AIPlayStatus *this;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  AIPlayStatus *pAStack_3c;
  AIPlayStatus *pAStack_38;
  int iStack_34;
  OrderEvent OStack_30;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c8cb;
  *unaff_FS_OFFSET = &uStack_c;
  rge_read(param_2,&param_1->moodValue,4);
  rge_read(iVar1,&param_1->currentOrderValue,4);
  rge_read(iVar1,&param_1->currentOrderPriorityValue,4);
  rge_read(iVar1,&param_1->currentActionValue,4);
  rge_read(iVar1,&param_1->currentTargetValue,4);
  rge_read(iVar1,&param_1->currentTargetTypeValue,4);
  rge_read(iVar1,&param_1->currentTargetXValue,4);
  rge_read(iVar1,&param_1->currentTargetYValue,4);
  rge_read(iVar1,&param_1->currentTargetZValue,4);
  rge_read(iVar1,&param_1->desiredTargetDistanceValue,4);
  rge_read(iVar1,&param_1->lastActionValue,4);
  rge_read(iVar1,&param_1->lastOrderValue,4);
  rge_read(iVar1,&param_1->lastTargetValue,4);
  rge_read(iVar1,&param_1->lastTargetTypeValue,4);
  rge_read(iVar1,&param_1->lastUpdateTimeValue,4);
  rge_read(iVar1,&param_1->idleTimerValue,4);
  rge_read(iVar1,&param_1->idleTimeoutValue,4);
  rge_read(iVar1,&param_1->adjustedIdleTimeoutValue,4);
  rge_read(iVar1,&param_1->secondaryTimerValue,4);
  if (save_game_version < _DAT_0056ebb8) {
    param_1->lookAroundTimerValue = 0;
    param_1->lookAroundTimeoutValue = 1000;
  }
  else {
    rge_read(iVar1,&param_1->lookAroundTimerValue,4);
    rge_read(iVar1,&param_1->lookAroundTimeoutValue,4);
  }
  rge_read(iVar1,&param_1->defendTargetValue,4);
  rge_read(iVar1,&param_1->defenseBufferValue,4);
  rge_read(iVar1,&param_1->lastWorldPositionValue,0x10);
  rge_read(iVar1,&param_2,4);
  iVar5 = 0;
  if (0 < param_2) {
    do {
      rge_read(iVar1,&OStack_30,0x24);
      UnitAIModule::addToOrderQueue(param_1,&OStack_30,0);
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_2);
  }
  rge_read(iVar1,&iStack_48,4);
  iVar5 = 0;
  if (0 < iStack_48) {
    do {
      rge_read(iVar1,&OStack_30,0x18);
      UnitAIModule::addToNotifyQueue(param_1,(NotifyEvent *)&OStack_30);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iStack_48);
  }
  rge_read(iVar1,&iStack_40,4);
  iStack_44 = 0;
  if (0 < iStack_40) {
    do {
      rge_read(iVar1,&pAStack_3c,4);
      iVar5 = (param_1->attackingUnitsValue).numberValue;
      iVar2 = 0;
      pAStack_38 = pAStack_3c;
      if (0 < iVar5) {
        do {
          if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar2) break;
          if ((AIPlayStatus *)(param_1->attackingUnitsValue).value[iVar2] == pAStack_3c)
          goto LAB_0041375f;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar5);
      }
      if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar5) {
        iVar5 = iVar5 + 1;
        piVar3 = (int *)operator_new(iVar5 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
            do {
              if (iVar5 <= iVar2) break;
              iVar4 = iVar2 + 1;
              piVar3[iVar2] = (param_1->attackingUnitsValue).value[iVar2];
              iVar2 = iVar4;
            } while (iVar4 < (param_1->attackingUnitsValue).maximumSizeValue);
          }
          operator_delete((param_1->attackingUnitsValue).value);
          (param_1->attackingUnitsValue).value = piVar3;
          (param_1->attackingUnitsValue).maximumSizeValue = iVar5;
        }
      }
      (param_1->attackingUnitsValue).value[(param_1->attackingUnitsValue).numberValue] =
           (int)pAStack_38;
      (param_1->attackingUnitsValue).numberValue = (param_1->attackingUnitsValue).numberValue + 1;
LAB_0041375f:
      iStack_44 = iStack_44 + 1;
    } while (iStack_44 < iStack_40);
  }
  rge_read(iVar1,&iStack_34,4);
  if (iStack_34 == 1) {
    pAStack_38 = (AIPlayStatus *)operator_new(0x1c8);
    uStack_4 = 0;
    if (pAStack_38 == (AIPlayStatus *)0x0) {
      this = (AIPlayStatus *)0x0;
    }
    else {
      this = (AIPlayStatus *)AIPlayStatus::AIPlayStatus(pAStack_38);
    }
    uStack_4 = 0xffffffff;
    param_1->playStatus = this;
    AIPlayStatus::load(this,iVar1);
  }
  if (_DAT_0056ebbc <= save_game_version) {
    rge_read(iVar1,&param_1->stopAfterTargetKilledValue,1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00413805
// Address: 00413805
undefined4 __fastcall FUN_00413805(int param_1)
{
  return *(undefined4 *)(*(int *)(param_1 + 4) + 0xc);
}

// --------------------------------------------------

// Function: FUN_00413817
// Address: 00413817
undefined4 __fastcall FUN_00413817(int param_1)
{
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_00413824
// Address: 00413824
undefined4 __fastcall FUN_00413824(int param_1)
{
  return *(undefined4 *)(*(int *)(param_1 + 4) + 4);
}

// --------------------------------------------------

// Function: FUN_00413837
// Address: 00413837
undefined4 __fastcall FUN_00413837(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_00413844
// Address: 00413844
undefined4 __fastcall FUN_00413844(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_00413854
// Address: 00413854
undefined4 __fastcall FUN_00413854(int param_1)
{
  return *(undefined4 *)(param_1 + 0xf4);
}

// --------------------------------------------------

// Function: FUN_00413867
// Address: 00413867
undefined4 __fastcall FUN_00413867(int param_1)
{
  return *(undefined4 *)(param_1 + 0xf8);
}

// --------------------------------------------------

// Function: FUN_00413877
// Address: 00413877
undefined4 __fastcall FUN_00413877(int param_1)
{
  return *(undefined4 *)(param_1 + 0x100);
}

// --------------------------------------------------

// Function: FUN_00413887
// Address: 00413887
undefined4 __fastcall FUN_00413887(int param_1)
{
  return *(undefined4 *)(param_1 + 0x104);
}

// --------------------------------------------------

// Function: FUN_00413897
// Address: 00413897
float10 __fastcall FUN_00413897(int param_1)
{
  return (float10)*(float *)(param_1 + 0x120);
}

// --------------------------------------------------

// Function: FUN_004138a7
// Address: 004138a7
undefined4 FUN_004138a7(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004138b5
// Address: 004138b5
void __thiscall FUN_004138b5(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x120) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004138cd
// Address: 004138cd
undefined4 __fastcall FUN_004138cd(int param_1)
{
  return *(undefined4 *)(param_1 + 0x10);
}

// --------------------------------------------------

// Function: FUN_004138d4
// Address: 004138d4
int __thiscall FUN_004138d4(int param_1,int param_2)
{
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x10))) && (*(int *)(param_1 + 0x18) != 0)) {
    return *(int *)(param_1 + 0x18) + param_2 * 0x24;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00413902
// Address: 00413902
void __fastcall FUN_00413902(int param_1)
{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00413918
// Address: 00413918
undefined4 __fastcall FUN_00413918(int param_1)
{
  return *(undefined4 *)(param_1 + 0x28);
}

// --------------------------------------------------

// Function: FUN_00413924
// Address: 00413924
void __thiscall FUN_00413924(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x28) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00413944
// Address: 00413944
void __thiscall FUN_00413944(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0041395a
// Address: 0041395a
undefined4 __fastcall FUN_0041395a(int param_1)
{
  return *(undefined4 *)(param_1 + 0x30);
}

// --------------------------------------------------

// Function: FUN_00413964
// Address: 00413964
void __thiscall FUN_00413964(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00413984
// Address: 00413984
undefined4 __fastcall FUN_00413984(int param_1)
{
  return *(undefined4 *)(param_1 + 0x38);
}

// --------------------------------------------------

// Function: FUN_00413994
// Address: 00413994
float10 __fastcall FUN_00413994(int param_1)
{
  return (float10)*(float *)(param_1 + 0x3c);
}

// --------------------------------------------------

// Function: FUN_004139a4
// Address: 004139a4
float10 __fastcall FUN_004139a4(int param_1)
{
  return (float10)*(float *)(param_1 + 0x40);
}

// --------------------------------------------------

// Function: FUN_004139b4
// Address: 004139b4
float10 __fastcall FUN_004139b4(int param_1)
{
  return (float10)*(float *)(param_1 + 0x44);
}

// --------------------------------------------------

// Function: FUN_004139c4
// Address: 004139c4
undefined4 __fastcall FUN_004139c4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x54);
}

// --------------------------------------------------

// Function: FUN_004139d4
// Address: 004139d4
undefined4 __fastcall FUN_004139d4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x50);
}

// --------------------------------------------------

// Function: FUN_004139e4
// Address: 004139e4
undefined4 __fastcall FUN_004139e4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x58);
}

// --------------------------------------------------

// Function: FUN_004139f4
// Address: 004139f4
undefined4 __fastcall FUN_004139f4(int param_1)
{
  return *(undefined4 *)(param_1 + 0x5c);
}

// --------------------------------------------------

// Function: FUN_00413a04
// Address: 00413a04
float10 __fastcall FUN_00413a04(int param_1)
{
  return (float10)*(float *)(param_1 + 0x48);
}

// --------------------------------------------------

// Function: FUN_00413a14
// Address: 00413a14
undefined4 __thiscall FUN_00413a14(int param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 100) <= param_2)) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x6c) + -1 < param_2) {
    iVar1 = param_2 + 1;
    pvVar2 = operator_new(iVar1 * 4);
    if (pvVar2 != (void *)0x0) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x6c)) {
        do {
          if (iVar1 <= iVar3) break;
          iVar3 = iVar3 + 1;
          *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0x60) + -4 + iVar3 * 4);
        } while (iVar3 < *(int *)(param_1 + 0x6c));
      }
      operator_delete(*(void **)(param_1 + 0x60));
      *(void **)(param_1 + 0x60) = pvVar2;
      *(int *)(param_1 + 0x6c) = iVar1;
    }
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x60) + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_00413a9d
// Address: 00413a9d
undefined4 __fastcall FUN_00413a9d(int param_1)
{
  return *(undefined4 *)(param_1 + 100);
}

// --------------------------------------------------

// Function: FUN_00413aa4
// Address: 00413aa4
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
undefined4 __thiscall FUN_00413aa4(UnitAIModule *param_1,ulong param_2)
{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  uchar uVar4;
  char cVar5;
  RGE_Static_Object *pRVar6;
  long lVar7;
  int *piVar8;
  UnitAIModule *pUVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  undefined4 uVar15;
  
  if (2 < param_1->objectValue->object_state) {
    return 1;
  }
  taskedThisUpdate = 0;
  searchedThisUpdate = 0;
  numberVisibleObjects = 0;
  numberDifferentPlayerObjectsVisible = 0;
  uVar4 = RGE_Action_List::have_action((RGE_Action_List *)param_1->objectValue[2].unitAIValue);
  if ((uVar4 == '\0') &&
     (cVar5 = (**(code **)(param_1->objectValue->_padding_ + 0x130))(), cVar5 == '\x01')) {
    (**(code **)(param_1->objectValue->_padding_ + 300))(0);
  }
  if (param_1->currentTargetValue != -1) {
    pRVar6 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue);
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      param_1->currentTargetValue = -1;
      if (param_1->currentActionValue == 600) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar7 = -1;
          }
          else {
            lVar7 = param_1->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar7,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x306);
        }
        (**(code **)(param_1->_padding_ + 0x58))(1);
        param_1->idleTimerValue = param_1->idleTimeoutValue;
      }
    }
    else {
      if ((param_1->objectValue->object_state == '\x02') && (2 < pRVar6->object_state)) {
        iVar13 = param_1->_padding_;
        iVar12 = (**(code **)(iVar13 + 0x2c))(param_1->currentActionValue);
        if (iVar12 == 1) {
          param_1->stopAfterTargetKilledValue = '\0';
          if (param_1->currentActionValue == 600) {
            iVar11 = (**(code **)(iVar13 + 0xd4))(0);
            iVar12 = param_1->currentOrderValue;
            if (iVar11 == 5) {
              if (iVar12 != 0x2d5) {
                fVar14 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0x10c))(1);
                iVar12 = (**(code **)(iVar13 + 0x90))
                                   (param_1->currentTargetXValue,param_1->currentTargetYValue,
                                    param_1->currentTargetZValue,(float)fVar14);
                if (iVar12 == 0) {
                  UnitAIModule::removeCurrentTarget(param_1);
                  if (actionFile != (_iobuf *)0x0) {
                    if (param_1->objectValue == (RGE_Static_Object *)0x0) {
                      lVar7 = -1;
                      uVar15 = 0x335;
                    }
                    else {
                      lVar7 = param_1->objectValue->id;
                      uVar15 = 0x335;
                    }
                    goto LAB_00413c86;
                  }
                  goto LAB_00413c9a;
                }
                iVar13 = param_1->currentOrderValue;
                param_1->currentOrderValue = -1;
                param_1->lastOrderValue = iVar13;
                param_1->currentOrderPriorityValue = -1;
              }
            }
            else if (iVar12 != 0x2d5) {
              param_1->lastOrderValue = iVar12;
              param_1->currentOrderValue = -1;
              param_1->currentOrderPriorityValue = -1;
            }
          }
          else {
            UnitAIModule::removeCurrentTarget(param_1);
            if (actionFile != (_iobuf *)0x0) {
              if (param_1->objectValue == (RGE_Static_Object *)0x0) {
                lVar7 = -1;
              }
              else {
                lVar7 = param_1->objectValue->id;
              }
              uVar15 = 0x356;
LAB_00413c86:
              fprintf(actionFile,s___d_call_stopObject__s__d_,lVar7,
                      s_C__msdev_work_age1_x1_aiuaimod_c,uVar15);
            }
LAB_00413c9a:
            (**(code **)(iVar13 + 0x58))(1);
          }
        }
      }
      iVar13 = RGE_Player::computerPlayer(param_1->objectValue->owner);
      if (((iVar13 == 1) && (param_1->currentOrderPriorityValue != -1)) &&
         (param_1->currentOrderPriorityValue < 100)) {
        RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar6);
        iVar13 = __ftol();
        if (99 < iVar13) {
          iVar13 = 99;
        }
        param_1->currentOrderPriorityValue = iVar13;
      }
    }
  }
  if (((param_1->attackingUnitsValue).numberValue == 0) &&
     (cVar5 = (**(code **)(param_1->objectValue->_padding_ + 0xe8))(), cVar5 != '\0')) {
    (**(code **)(param_1->objectValue->_padding_ + 0xec))(0);
  }
  else {
    iVar13 = 0;
    if (0 < (param_1->attackingUnitsValue).numberValue) {
      do {
        if ((param_1->attackingUnitsValue).maximumSizeValue + -1 < iVar13) {
          piVar8 = (int *)operator_new(iVar13 * 4 + 4);
          if (piVar8 != (int *)0x0) {
            iVar12 = 0;
            if (0 < (param_1->attackingUnitsValue).maximumSizeValue) {
              do {
                if (iVar13 + 1 <= iVar12) break;
                iVar11 = iVar12 + 1;
                piVar8[iVar12] = (param_1->attackingUnitsValue).value[iVar12];
                iVar12 = iVar11;
              } while (iVar11 < (param_1->attackingUnitsValue).maximumSizeValue);
            }
            operator_delete((param_1->attackingUnitsValue).value);
            (param_1->attackingUnitsValue).value = piVar8;
            (param_1->attackingUnitsValue).maximumSizeValue = iVar13 + 1;
          }
        }
        pRVar6 = UnitAIModule::lookupObject(param_1,(param_1->attackingUnitsValue).value[iVar13]);
        if (((pRVar6 == (RGE_Static_Object *)0x0) ||
            (pUVar9 = RGE_Static_Object::unitAI(pRVar6), pUVar9 == (UnitAIModule *)0x0)) ||
           (2 < pRVar6->object_state)) {
LAB_00413db5:
          if (iVar13 <= (param_1->attackingUnitsValue).maximumSizeValue + -1) goto LAB_00413e08;
          iVar12 = iVar13 + 1;
          piVar8 = (int *)operator_new(iVar12 * 4);
          if (piVar8 == (int *)0x0) goto LAB_00413e08;
          iVar11 = 0;
          if ((param_1->attackingUnitsValue).maximumSizeValue < 1) goto LAB_00413df6;
          goto LAB_00413ddf;
        }
        pUVar9 = RGE_Static_Object::unitAI(pRVar6);
        iVar12 = UnitAIModule::currentTarget(pUVar9);
        if (iVar12 != param_1->objectValue->id) goto LAB_00413db5;
        iVar13 = iVar13 + 1;
      } while (iVar13 < (param_1->attackingUnitsValue).numberValue);
    }
  }
  goto LAB_00413e52;
  while( true ) {
    iVar10 = iVar11 + 1;
    piVar8[iVar11] = (param_1->attackingUnitsValue).value[iVar11];
    iVar11 = iVar10;
    if ((param_1->attackingUnitsValue).maximumSizeValue <= iVar10) break;
LAB_00413ddf:
    if (iVar12 <= iVar11) break;
  }
LAB_00413df6:
  operator_delete((param_1->attackingUnitsValue).value);
  (param_1->attackingUnitsValue).value = piVar8;
  (param_1->attackingUnitsValue).maximumSizeValue = iVar12;
LAB_00413e08:
  iVar12 = (param_1->attackingUnitsValue).maximumSizeValue;
  iVar11 = 0;
  if (0 < iVar12) {
    piVar8 = (param_1->attackingUnitsValue).value;
    do {
      if (*piVar8 == (param_1->attackingUnitsValue).value[iVar13]) break;
      iVar11 = iVar11 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar11 < iVar12);
  }
  if (iVar11 < iVar12) {
    if (iVar11 < iVar12 + -1) {
      do {
        piVar8 = (param_1->attackingUnitsValue).value;
        iVar13 = iVar11 + 1;
        piVar8[iVar11] = piVar8[iVar13];
        iVar11 = iVar13;
      } while (iVar13 < (param_1->attackingUnitsValue).maximumSizeValue + -1);
    }
    iVar13 = (param_1->attackingUnitsValue).numberValue + -1;
    (param_1->attackingUnitsValue).numberValue = iVar13;
    if (iVar13 < 0) {
      (param_1->attackingUnitsValue).numberValue = 0;
    }
  }
LAB_00413e52:
  pRVar6 = param_1->objectValue;
  uVar1 = param_1->idleTimerValue;
  iVar12 = 0;
  (param_1->lastWorldPositionValue).x = pRVar6->world_x;
  (param_1->lastWorldPositionValue).y = pRVar6->world_y;
  uVar2 = param_1->lookAroundTimerValue;
  iVar13 = param_1->notifyQueueSizeValue;
  (param_1->lastWorldPositionValue).z = pRVar6->world_z;
  param_1->idleTimerValue = uVar1 + param_2;
  param_1->secondaryTimerValue = param_1->secondaryTimerValue + param_2;
  param_1->lookAroundTimerValue = uVar2 + param_2;
  if (0 < iVar13) {
    iVar13 = 0;
    pcVar3 = *(code **)(param_1->_padding_ + 0xcc);
    do {
      iVar11 = (*pcVar3)((int)&param_1->notifyQueueValue->caller + iVar13,param_2);
      if (iVar11 == 4) {
        UnitAIModule::purgeNotifyQueue(param_1,param_2);
        return 0;
      }
      if (iVar11 == 3) break;
      iVar12 = iVar12 + 1;
      iVar13 = iVar13 + 0x18;
    } while (iVar12 < param_1->notifyQueueSizeValue);
  }
  UnitAIModule::purgeNotifyQueue(param_1,param_2);
  if (uVar4 == '\0') {
    switch(param_1->currentActionValue) {
    case 600:
    case 0x261:
    case 0x262:
    case 0x265:
    case 0x26b:
    case 0x26c:
      param_1->currentActionValue = -1;
      break;
    default:
      goto switchD_00413f02_caseD_259;
    }
  }
  else {
switchD_00413f02_caseD_259:
  }
  pRVar6 = param_1->objectValue;
  if (2 < pRVar6->object_state) {
    return 0;
  }
  if (pRVar6->groupCommanderValue == pRVar6->id) {
    UnitAIModule::updateGroup(param_1,param_2);
  }
  if ((param_1->currentActionValue == -1) && (iVar13 = 0, 0 < param_1->orderQueueSizeValue)) {
    iVar12 = 0;
    pcVar3 = *(code **)(param_1->_padding_ + 200);
    do {
      iVar11 = (*pcVar3)((int)&param_1->orderQueueValue->issuer + iVar12,iVar13);
      if (iVar11 == 1) break;
      iVar13 = iVar13 + 1;
      iVar12 = iVar12 + 0x24;
    } while (iVar13 < param_1->orderQueueSizeValue);
  }
  iVar13 = param_1->_padding_;
  (**(code **)(iVar13 + 0xd8))();
  if (param_1->adjustedIdleTimeoutValue < param_1->idleTimerValue) {
    if (param_1->currentActionValue == -1) {
      if (param_1->currentTargetValue == -1) {
        param_1->idleTimerValue = 0;
        (**(code **)(iVar13 + 0xd4))(1);
        goto LAB_00413fc6;
      }
      goto LAB_00413fb2;
    }
  }
  else {
LAB_00413fb2:
    if ((param_1->currentActionValue == -1) && (param_1->currentTargetValue == -1))
    goto LAB_00413fc6;
  }
  param_1->idleTimerValue = 0;
LAB_00413fc6:
  iVar13 = RGE_Player::computerPlayer(param_1->objectValue->owner);
  if ((iVar13 == 1) && (param_1->lookAroundTimeoutValue < param_1->lookAroundTimerValue)) {
    UnitAIModule::lookAround(param_1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00414767
// Address: 00414767
undefined4 __fastcall FUN_00414767(int param_1,undefined4 param_2)
{
  char *pcVar1;
  char in_AL;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char cVar6;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int in_stack_00000002;
  
  iVar3 = CONCAT22((short)((uint)unaff_EBX >> 0x10),
                   CONCAT11((char)((uint)unaff_EBX >> 8) * '\x02',(char)unaff_EBX));
  pcVar1 = (char *)(iVar3 + 0x45);
  *pcVar1 = *pcVar1 + (char)((uint)param_2 >> 8);
  cVar6 = (char)unaff_EBX + (char)((uint)(param_1 + 3) >> 8) + (char)((uint)(param_1 + 4) >> 8) +
          (char)((uint)(param_1 + 5) >> 8) + (char)((uint)(param_1 + 6) >> 8);
  *(char *)(unaff_EBP + 0x47) = *(char *)(unaff_EBP + 0x47) + in_AL;
  param_1 = param_1 + 9;
  iVar4 = CONCAT22((short)((uint)param_1 >> 0x10),
                   CONCAT11((char)((uint)param_1 >> 8) + cVar6,(char)param_1));
  piVar5 = (int *)(iVar4 + 1);
  pcVar1 = (char *)(CONCAT31((int3)((uint)iVar3 >> 8),cVar6) + -0x6fffbeba);
  *pcVar1 = *pcVar1 + (char)((uint)piVar5 >> 8);
  pvVar2 = operator_new(in_stack_00000002 * 4);
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
  iVar3 = 0;
  if (0 < *(int *)(iVar4 + 0xd)) {
    do {
      if (in_stack_00000002 <= iVar3) break;
      iVar3 = iVar3 + 1;
      *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) = *(undefined4 *)(*piVar5 + -4 + iVar3 * 4);
    } while (iVar3 < *(int *)(iVar4 + 0xd));
  }
  operator_delete((void *)*piVar5);
  *piVar5 = (int)pvVar2;
  *(int *)(iVar4 + 0xd) = in_stack_00000002;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004147ff
// Address: 004147ff
undefined4 __thiscall FUN_004147ff(UnitAIModule *param_1,long param_2,int param_3)
{
  uchar uVar1;
  short sVar2;
  AIPlayStatus *pAVar3;
  int iVar4;
  uchar uVar5;
  AIPlay *this;
  AIPlayPhase *this_00;
  RGE_Static_Object *pRVar6;
  AIPlayPhaseCommand *pAVar7;
  RGE_Static_Object *pRVar8;
  UnitAIModule *pUVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  RGE_Static_Object *pRVar13;
  int iVar14;
  undefined4 uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  int iStack_44;
  int iStack_40;
  int iStack_38;
  
  if (param_1->playStatus == (AIPlayStatus *)0x0) {
    return 0;
  }
  this = AIPlayBook::play(param_1->objectValue->owner->world->playbook,
                          param_1->playStatus->playNumberValue);
  if (this == (AIPlay *)0x0) {
    return 0;
  }
  if (param_2 == 0xfe) {
    operator_delete(param_1->playStatus);
    param_1->playStatus = (AIPlayStatus *)0x0;
    return 1;
  }
  this_00 = AIPlay::phase(this,param_2);
  if (this_00 == (AIPlayPhase *)0x0) {
    return 0;
  }
  pRVar6 = UnitAIModule::lookupObject(param_1,param_1->playStatus->targetValue);
  if (pRVar6 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iStack_38 = 0;
  param_1->playStatus->currentPhaseValue = (uchar)param_2;
  do {
    pAVar7 = AIPlayPhase::command(this_00,iStack_38);
    if ((pAVar7 != (AIPlayPhaseCommand *)0x0) && (uVar1 = pAVar7->typeValue, uVar1 != '\0')) {
      if (((uVar1 == '\x06') || (uVar1 == '\a')) && (param_3 == 0)) {
        if (uVar1 == '\x06') {
          AIPlayStatus::resetHitPoints
                    (param_1->playStatus,(uint)pAVar7->groupValue,param_1->objectValue->owner->world
                    );
        }
        else if (uVar1 == '\a') {
          AIPlayStatus::removeDeadUnits
                    (param_1->playStatus,(uint)pAVar7->groupValue,param_1->objectValue->owner->world
                    );
        }
      }
      else {
        pRVar8 = param_1->objectValue;
        iStack_44 = 0;
        if (0 < (pRVar8->groupMembers).numberValue) {
          do {
            if ((pRVar8->groupMembers).maximumSizeValue + -1 < iStack_44) {
              ManagedArray<int>::resize(&pRVar8->groupMembers,iStack_44 + 1);
            }
            pRVar8 = UnitAIModule::lookupObject(param_1,(pRVar8->groupMembers).value[iStack_44]);
            if (((pRVar8 == (RGE_Static_Object *)0x0) ||
                (pUVar9 = RGE_Static_Object::unitAI(pRVar8), pUVar9 == (UnitAIModule *)0x0)) ||
               (uVar1 = pAVar7->groupValue,
               uVar5 = AIPlayStatus::group(param_1->playStatus,pRVar8->id), uVar5 != uVar1))
            goto switchD_00414a03_caseD_6;
            if (param_3 == 1) {
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              iVar10 = UnitAIModule::currentAction(pUVar9);
              if (iVar10 != -1) goto switchD_00414a03_caseD_6;
            }
            switch(pAVar7->typeValue) {
            case '\x01':
              RGE_Static_Object::distance_to_position
                        (pRVar8,(float)pAVar7->value1Value + pRVar6->world_x,
                         (float)pAVar7->value2Value + pRVar6->world_y,
                         (float)pAVar7->value3Value + pRVar6->world_z);
              iVar10 = __ftol();
              iVar11 = AIPlay::gatherTolerance
                                 (this,(uint)pAVar7->groupValue,
                                  (uint)param_1->playStatus->currentPhaseValue);
              if (iVar11 < iVar10) {
                iVar10 = pAVar7->value1Value;
                iVar11 = pAVar7->value3Value;
                iVar4 = pAVar7->value2Value;
                pUVar9 = RGE_Static_Object::unitAI(pRVar8);
                iVar14 = pUVar9->_padding_;
                fVar18 = (float)iVar11 + pRVar6->world_z;
                fVar17 = (float)iVar4 + pRVar6->world_y;
                fVar16 = (float)iVar10 + pRVar6->world_x;
                iVar10 = -1;
                param_2 = -1;
                uVar15 = 0x2c6;
                break;
              }
              goto switchD_00414a03_caseD_6;
            case '\x02':
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              iVar10 = (int)pRVar6->owner->id;
              iVar14 = pUVar9->_padding_;
              fVar18 = -1.0;
              fVar17 = -1.0;
              fVar16 = -1.0;
              param_2 = pRVar6->id;
              uVar15 = 700;
              break;
            case '\x03':
              param_2 = param_1->playStatus->savedAttackerValue;
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              iVar14 = pUVar9->_padding_;
              fVar18 = -1.0;
              fVar17 = -1.0;
              fVar16 = -1.0;
              iVar10 = -1;
              uVar15 = 700;
              break;
            case '\x04':
              pAVar3 = param_1->playStatus;
              iVar10 = (pAVar3->originalPointValue).zValue;
              iVar11 = (pAVar3->originalPointValue).yValue;
              iVar4 = (pAVar3->originalPointValue).xValue;
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              fVar18 = (float)iVar10;
              iVar14 = pUVar9->_padding_;
              fVar17 = (float)iVar11;
              fVar16 = (float)iVar4;
              iVar10 = -1;
              param_2 = -1;
              uVar15 = 0x2c6;
              break;
            case '\x05':
              param_2 = -1;
              iStack_40 = 0;
              do {
                piVar12 = (int *)((int)&param_1->playStatus->groupings[0].id + iStack_40);
                if ((((uint)*(byte *)(piVar12 + 1) == pAVar7->value1Value) &&
                    (pRVar13 = UnitAIModule::lookupObject(param_1,*piVar12),
                    pRVar13 != (RGE_Static_Object *)0x0)) &&
                   (sVar2 = pRVar13->master_obj->hp, iVar10 = __ftol(), iVar10 + 1 < (int)sVar2)) {
                  param_2 = pRVar13->id;
                  break;
                }
                iStack_40 = iStack_40 + 8;
              } while (iStack_40 < 400);
              if (param_2 != -1) {
                pUVar9 = RGE_Static_Object::unitAI(pRVar8);
                iVar14 = pUVar9->_padding_;
                fVar18 = -1.0;
                fVar17 = -1.0;
                fVar16 = -1.0;
                iVar10 = -1;
                uVar15 = 0x2bf;
                break;
              }
            default:
              goto switchD_00414a03_caseD_6;
            case '\b':
              iVar10 = pAVar7->value1Value;
              iVar11 = pAVar7->value3Value;
              iVar4 = pAVar7->value2Value;
              pUVar9 = RGE_Static_Object::unitAI(pRVar8);
              iVar14 = pUVar9->_padding_;
              fVar18 = (float)iVar11 + pRVar6->world_z;
              fVar17 = (float)iVar4 + pRVar6->world_y;
              fVar16 = (float)iVar10 + pRVar6->world_x;
              iVar10 = -1;
              param_2 = -1;
              uVar15 = 0x2d8;
            }
            (**(code **)(iVar14 + 0x10))
                      (param_1->objectValue->id,uVar15,param_2,iVar10,fVar16,fVar17,fVar18,
                       0x3f800000,1,0,100);
switchD_00414a03_caseD_6:
            pRVar8 = param_1->objectValue;
            iStack_44 = iStack_44 + 1;
          } while (iStack_44 < (pRVar8->groupMembers).numberValue);
        }
      }
    }
    iStack_38 = iStack_38 + 1;
    if (4 < iStack_38) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00414d12
// Address: 00414d12
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_00414e72
// Address: 00414e72
int __thiscall
FUN_00414e72(UnitAIModule *param_1,int param_2,int param_3,int param_4,int param_5,long param_6,
            long param_7)
{
  int iVar1;
  int iVar2;
  
  if (param_1->objectValue->object_state != '\x02') {
    return 0;
  }
  if (param_4 == 699) {
    iVar2 = (param_1->attackingUnitsValue).numberValue;
    iVar1 = 0;
    if (0 < iVar2) {
      while (iVar1 < (param_1->attackingUnitsValue).maximumSizeValue) {
        if ((param_1->attackingUnitsValue).value[iVar1] == param_2) goto LAB_00414ecf;
        iVar1 = iVar1 + 1;
        if (iVar2 <= iVar1) {
          return 0;
        }
      }
    }
  }
  else {
LAB_00414ecf:
    if ((param_4 != 0x1fb) || (param_5 == param_1->currentActionValue)) {
      if ((param_4 == 0x1fa) &&
         (((param_5 == 0x262 && (param_1->currentActionValue != 0x262)) &&
          (param_1->currentActionValue != 0x268)))) {
        return 1;
      }
      iVar2 = UnitAIModule::addToNotifyQueue
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      return iVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00414f31
// Address: 00414f31
void __thiscall FUN_00414f31(int *param_1,undefined4 *param_2)
{
  (**(code **)(*param_1 + 0x18))(*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5]);
  return;
}

// --------------------------------------------------

// Function: FUN_00414f65
// Address: 00414f65
undefined4 __thiscall
FUN_00414f65(UnitAIModule *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  RGE_Static_Object *this;
  UnitAIModule *pUVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = RGE_Static_Object::inGroup(param_1->objectValue);
  if (iVar1 == 1) {
    uStack_18 = param_2;
    uStack_14 = param_3;
    uStack_10 = param_4;
    uStack_c = param_5;
    uStack_8 = param_6;
    uStack_4 = param_7;
    iVar1 = param_1->objectValue->groupCommanderValue;
    if (param_1->objectValue->id == iVar1) {
      (**(code **)(param_1->_padding_ + 0xd0))(&uStack_18);
    }
    else {
      this = UnitAIModule::lookupObject(param_1,iVar1);
      if (this != (RGE_Static_Object *)0x0) {
        pUVar2 = RGE_Static_Object::unitAI(this);
        if (pUVar2 != (UnitAIModule *)0x0) {
          pUVar2 = RGE_Static_Object::unitAI(this);
          (**(code **)(pUVar2->_padding_ + 0xd0))(&uStack_18);
        }
      }
    }
  }
  (**(code **)(param_1->objectValue->owner->_padding_ + 0xe8))
            (param_2,param_3,param_4,param_5,param_6,param_7);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00415036
// Address: 00415036
void __fastcall FUN_00415036(UnitAIModule *param_1)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Player *pRVar2;
  RGE_Static_Object *pRVar3;
  UnitAIModule *pUVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  
  if (searchedThisUpdate == 1) {
    return;
  }
  searchedThisUpdate = 1;
  if (param_1->importantObjects != (int *)0x0) {
    if ((((param_1->currentOrderValue == 0x2bd) && (param_1->defendTargetValue != -1)) &&
        (pRVar3 = UnitAIModule::lookupObject(param_1,param_1->defendTargetValue),
        pRVar3 != (RGE_Static_Object *)0x0)) &&
       (pUVar4 = RGE_Static_Object::unitAI(pRVar3), pUVar4 != (UnitAIModule *)0x0)) {
      iVar10 = param_1->numberImportantObjects;
      piVar9 = param_1->importantObjects;
      piVar11 = param_1->objectValue->owner->unitDiplomacy;
      iVar8 = (int)pRVar3->owner->id;
      iVar5 = __ftol();
    }
    else {
      pRVar3 = param_1->objectValue;
      pRVar1 = pRVar3->master_obj;
      iVar5 = __ftol();
      if (pRVar1->id == 0x76) {
        iVar5 = iVar5 * 2;
      }
      pRVar2 = pRVar3->owner;
      piVar11 = pRVar2->unitDiplomacy;
      iVar8 = (int)pRVar2->id;
      iVar10 = param_1->numberImportantObjects;
      piVar9 = param_1->importantObjects;
    }
    iVar6 = __ftol();
    iVar7 = __ftol();
    numberVisibleObjects =
         Visible_Unit_Manager::GetVisibleUnits
                   (VisibleUnitManager,iVar7,iVar6,iVar5,iVar8,piVar9,iVar10,piVar11);
    return;
  }
  searchedThisUpdate = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0041514f
// Address: 0041514f
undefined4 FUN_0041514f(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00415155
// Address: 00415155
undefined4 __thiscall FUN_00415155(int param_1,int param_2)
{
  if ((((*(char *)(param_1 + 0x130) != '\x01') && (param_2 != 600)) && (param_2 != 0x259)) &&
     (((param_2 != 0x25b && (param_2 != 0x25c)) && ((param_2 != 0x26a && (param_2 != 0x264)))))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004151a4
// Address: 004151a4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

VISIBLE_UNIT_REC * __thiscall FUN_004151a4(UnitAIModule *param_1,int param_2,int param_3)
{
  byte bVar1;
  short sVar2;
  int iVar3;
  RGE_Player *pRVar4;
  RGE_Game_World *this;
  uchar uVar5;
  int iVar6;
  int iVar7;
  RGE_Static_Object *pRVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  float10 fVar12;
  float10 fVar13;
  float fVar14;
  float fStack_38;
  int iStack_34;
  uint uStack_30;
  float fStack_2c;
  int iStack_28;
  int iStack_1c;
  VISIBLE_UNIT_REC *pVStack_18;
  int iStack_14;
  int iStack_10;
  code *pcStack_c;
  float fStack_8;
  VISIBLE_UNIT_REC *pVStack_4;
  
  iVar3 = param_1->_padding_;
  (**(code **)(iVar3 + 0x20))();
  iVar6 = RGE_Game_World::difficultyLevel(param_1->objectValue->owner->world);
  iVar7 = RGE_Base_Game::scenarioGame(rge_base_game);
  if (((((iVar7 == 1) && (iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar7 == 1)) &&
       (2 < iVar6)) && (param_1->objectValue->owner->id != 1)) ||
     (((iVar7 = RGE_Base_Game::singlePlayerGame(rge_base_game), iVar7 == 1 && (2 < iVar6)) &&
      ((pRVar4 = param_1->objectValue->owner, pRVar4->type == '\x03' &&
       ((iVar7 = (**(code **)(pRVar4->_padding_ + 0x3c))(0xdb), iVar7 != 100 ||
        (iVar7 = (**(code **)(param_1->objectValue->owner->_padding_ + 0x3c))(0xda), iVar7 != 100)))
       ))))) {
    pRVar4 = param_1->objectValue->owner;
    if (1 < pRVar4->id) {
      if (iVar6 == 3) {
        (**(code **)(pRVar4->_padding_ + 0x3c))(0xdb);
      }
      else {
        (**(code **)(pRVar4->_padding_ + 0x3c))(0xda);
      }
    }
    pRVar8 = param_1->objectValue;
    iStack_1c = __ftol();
    if (iStack_1c < 1) {
      iStack_1c = 1;
    }
  }
  else {
    pRVar8 = param_1->objectValue;
    iStack_1c = __ftol();
    iStack_1c = iStack_1c << 1;
  }
  pVStack_18 = (VISIBLE_UNIT_REC *)0xffffffff;
  this = pRVar8->owner->world;
  fStack_38 = 0.0;
  fStack_2c = 0.0;
  iStack_10 = 0;
  if (((param_1->currentTargetValue != -1) &&
      (pRVar8 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue),
      pRVar8 != (RGE_Static_Object *)0x0)) && (pRVar8->master_obj->object_group == 0x1b)) {
    iStack_10 = 1;
  }
  pVStack_4 = (VISIBLE_UNIT_REC *)0xffffffff;
  iStack_34 = 0;
  uStack_30 = 0;
  iStack_14 = 0;
  fStack_8 = 100000.0;
  pcStack_c = (code *)0x0;
  iVar6 = 4;
  do {
    iVar7 = 0;
    if (0 < (int)(&VisibleUnitList_Size)[iVar6]) {
      do {
        pRVar8 = RGE_Game_World::object(this,(int)(&VisibleUnitList)[iVar6][iVar7 * 2]);
        if ((((((pRVar8 != (RGE_Static_Object *)0x0) && (pRVar8->object_state < 3)) &&
              ((iVar9 = (**(code **)(param_1->objectValue->owner->_padding_ + 0x1c))
                                  ((int)pRVar8->owner->id), iVar9 != 1 &&
               (pRVar8->inside_obj == (RGE_Static_Object *)0x0)))) &&
             (((param_2 != 0 && (iStack_10 != 0)) || (pRVar8->master_obj->object_group != 0x1b))))
            && (((pRVar8->master_obj->object_group != 3 || (_DAT_0056ebd0 < pRVar8->hp)) ||
                ((sVar2 = param_1->objectValue->master_obj->id, sVar2 != 0x23 && (sVar2 != 0x24)))))
            ) && ((iVar9 = (**(code **)(iVar3 + 0x50))(pRVar8), iVar9 != 0 &&
                  ((iVar6 != 3 ||
                   (iVar9 = (**(code **)(iVar3 + 0x54))((int)pRVar8->master_obj->object_group),
                   iVar9 != 0)))))) {
          fVar14 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar8);
          fVar12 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0x110))();
          if ((fVar12 <= (float10)fVar14) &&
             ((int)(uint)*(byte *)((&VisibleUnitList)[iVar6] + iVar7 * 2 + 1) <= iStack_1c)) {
            if (pRVar8->id != param_1->currentTargetValue) {
              iStack_14 = iStack_14 + 1;
            }
            if (pRVar8->master_obj->object_group != 3) {
              iStack_34 = iStack_34 + 1;
            }
            fVar12 = (float10)(**(code **)(pRVar8->_padding_ + 0x108))();
            if ((float10)_DAT_0056ebc8 < fVar12) {
              uStack_30 = uStack_30 + 1;
            }
            if (pRVar8->master_obj->object_group != 3) {
              fVar12 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0x10c))();
              if ((float10)fVar14 < fVar12 - (float10)_DAT_0056ebd4) {
                pcStack_c = pcStack_c + 1;
              }
              if (fVar14 < fStack_8) {
                pVStack_4 = (VISIBLE_UNIT_REC *)pRVar8->id;
                fStack_8 = fVar14;
              }
            }
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)(&VisibleUnitList_Size)[iVar6]);
    }
    iVar6 = iVar6 + -1;
  } while (1 < iVar6);
  if ((((param_1->currentTargetValue != -1) && (param_3 == 0)) &&
      (param_1->currentActionValue == 600)) &&
     (pRVar8 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue),
     pRVar8 != (RGE_Static_Object *)0x0)) {
    iVar6 = __ftol();
    iVar7 = __ftol();
    uVar5 = UnitAIModule::visibleStatus(param_1,param_1->objectValue->owner->visible,iVar7,iVar6);
    if (iStack_14 != 0) {
      if (uVar5 != '\x0f') goto LAB_004156de;
      iVar6 = (**(code **)(param_1->objectValue->_padding_ + 0xe4))(pRVar8);
      if (iVar6 != 1) {
        iVar6 = param_1->objectValue->_padding_;
        fVar12 = (float10)(**(code **)(iVar6 + 0x10c))(0,0,0xffffffff,0xffffffff);
        iVar6 = (**(code **)(iVar6 + 0x194))(param_1->currentTargetValue,(float)fVar12);
        if (iVar6 != 1) goto LAB_004156de;
      }
    }
    pRVar8 = RGE_Game_World::object(this,param_1->currentTargetValue);
    if (((pRVar8 != (RGE_Static_Object *)0x0) && (pRVar8->object_state == '\x02')) &&
       (iVar6 = (**(code **)(param_1->objectValue->owner->_padding_ + 0x1c))((int)pRVar8->owner->id)
       , iVar6 == 0)) {
      if (pRVar8->master_obj->id == 0x114) {
        return (VISIBLE_UNIT_REC *)pRVar8->id;
      }
      pVStack_18 = (VISIBLE_UNIT_REC *)param_1->currentTargetValue;
      fVar12 = (float10)(**(code **)(pRVar8->_padding_ + 0x108))();
      fStack_38 = (float)(fVar12 * (float10)_DAT_0056ebd8);
      iStack_10 = (**(code **)(pRVar8->master_obj->_padding_ + 0x28))
                            (param_1->objectValue->master_obj);
      fStack_2c = RGE_Static_Object::distance_to_object(pRVar8,param_1->objectValue);
      bVar11 = pRVar8->master_obj->object_group == 3;
      if (!bVar11) {
        fStack_38 = (float)((int)fStack_38 + 1);
      }
      uStack_30 = (uint)bVar11;
      fVar12 = (float10)(*pcStack_c)();
      if ((float10)_DAT_0056ebc8 < fVar12) {
        uStack_30 = uStack_30 + 1;
      }
    }
  }
LAB_004156de:
  if ((1 < iStack_34) &&
     (pRVar8 = RGE_Game_World::object(this,(int)pVStack_4), pRVar8 != (RGE_Static_Object *)0x0)) {
    iVar6 = (**(code **)(param_1->objectValue->_padding_ + 0xe4))(pRVar8);
    if (iVar6 == 1) {
      return pVStack_4;
    }
    iVar6 = param_1->objectValue->_padding_;
    fVar12 = (float10)(**(code **)(iVar6 + 0x10c))(0,0,0xffffffff,0xffffffff);
    iVar6 = (**(code **)(iVar6 + 0x194))(pVStack_4,(float)fVar12);
    if (iVar6 == 1) {
      return pVStack_4;
    }
  }
  iVar6 = 4;
  do {
    iStack_28 = 0;
    if (0 < (int)(&VisibleUnitList_Size)[iVar6]) {
      do {
        pRVar8 = RGE_Game_World::object(this,(int)(&VisibleUnitList)[iVar6][iStack_28 * 2]);
        if ((((((pRVar8 != (RGE_Static_Object *)0x0) && (pRVar8->object_state < 3)) &&
              (iVar7 = (**(code **)(param_1->objectValue->owner->_padding_ + 0x1c))
                                 ((int)pRVar8->owner->id), iVar7 != 1)) &&
             (pRVar8->inside_obj == (RGE_Static_Object *)0x0)) &&
            (((param_2 != 0 && (iStack_10 != 0)) || (pRVar8->master_obj->object_group != 0x1b)))) &&
           (((((pRVar8->master_obj->object_group != 3 || (_DAT_0056ebd0 < pRVar8->hp)) ||
              ((sVar2 = param_1->objectValue->master_obj->id, sVar2 != 0x23 && (sVar2 != 0x24)))) &&
             (iVar7 = (**(code **)(iVar3 + 0x50))(pRVar8), iVar7 != 0)) &&
            ((iVar6 != 3 ||
             (iVar7 = (**(code **)(iVar3 + 0x54))((int)pRVar8->master_obj->object_group), iVar7 != 0
             )))))) {
          fVar14 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar8);
          fVar12 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0x110))();
          if (((fVar12 <= (float10)fVar14) &&
              ((int)(uint)*(byte *)((&VisibleUnitList)[iVar6] + iStack_28 * 2 + 1) <= iStack_1c)) &&
             ((param_3 != 1 ||
              (iVar7 = (**(code **)(param_1->objectValue->_padding_ + 0xe4))(pRVar8), iVar7 != 0))))
{
            if ((param_3 == 0) &&
               (iVar7 = (**(code **)(param_1->objectValue->_padding_ + 0xe4))(pRVar8), iVar7 == 0))
{
              iVar7 = param_1->objectValue->_padding_;
              fVar12 = (float10)(**(code **)(iVar7 + 0x10c))(0,0,0xffffffff,0xffffffff);
              iVar7 = (**(code **)(iVar7 + 0x194))
                                ((&VisibleUnitList)[iVar6][iStack_28 * 2],(float)fVar12);
              if (iVar7 == 0) goto LAB_004159dc;
            }
            fVar13 = (float10)(**(code **)(pRVar8->_padding_ + 0x108))();
            fVar12 = (float10)_DAT_0056ebd8;
            if (((int)uStack_30 < 1) || ((float)(fVar13 * fVar12) != _DAT_0056ebc8)) {
              iVar7 = (**(code **)(pRVar8->master_obj->_padding_ + 0x28))
                                (param_1->objectValue->master_obj);
              fVar14 = (float)iVar7 * _DAT_0056ebc0 + (float)(fVar13 * fVar12);
              if (_DAT_0056ebc8 < pRVar8->hp) {
                fVar14 = fVar14 / pRVar8->hp;
              }
              bVar1 = *(byte *)((&VisibleUnitList)[iVar6] + iStack_28 * 2 + 1);
              if (bVar1 != 0) {
                fVar14 = fVar14 / (float)bVar1;
              }
              if (1 < iStack_34) {
                uVar10 = (uint)bVar1;
                fVar14 = fVar14 / (float)(uVar10 * uVar10 * uVar10);
              }
              sVar2 = pRVar8->master_obj->object_group;
              if ((pVStack_18 == (VISIBLE_UNIT_REC *)0xffffffff) ||
                 (((fStack_2c != 0.0 || (sVar2 != 3)) &&
                  ((pVStack_18 == (VISIBLE_UNIT_REC *)0xffffffff ||
                   (((fStack_2c == 1.4013e-45 && (sVar2 != 3)) || (fStack_38 < fVar14)))))))) {
                pVStack_18 = (&VisibleUnitList)[iVar6][iStack_28 * 2];
                fStack_2c = (float)(uint)(sVar2 == 3);
                fStack_38 = fVar14;
              }
            }
          }
        }
LAB_004159dc:
        iStack_28 = iStack_28 + 1;
      } while (iStack_28 < (int)(&VisibleUnitList_Size)[iVar6]);
    }
    iVar6 = iVar6 + -1;
    if (iVar6 < 2) {
      return pVStack_18;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00415a08
// Address: 00415a08
int __thiscall FUN_00415a08(UnitAIModule *param_1,float *param_2)
{
  RGE_Master_Static_Object *pRVar1;
  int iVar2;
  undefined4 uVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  float10 fVar6;
  int iStack_8;
  float fStack_4;
  
  (**(code **)(param_1->_padding_ + 0x20))();
  iVar5 = -1;
  fStack_4 = 0.0;
  iStack_8 = 0;
  if (0 < DAT_0087d7d8) {
    do {
      pRVar4 = UnitAIModule::lookupObject(param_1,*(int *)(DAT_0087d7f0 + iStack_8 * 8));
      if (pRVar4 != (RGE_Static_Object *)0x0) {
        pRVar1 = pRVar4->master_obj;
        iVar2 = param_1->objectValue->_padding_;
        fVar6 = (float10)(**(code **)(iVar2 + 0xf0))(pRVar4,pRVar4->owner,pRVar4);
        uVar3._0_2_ = pRVar1[1].tile_req1;
        uVar3._2_2_ = pRVar1[1].tile_req2;
        fVar6 = (float10)(**(code **)(iVar2 + 0x74))
                                   ((int)pRVar1[1].portrait_pict,uVar3,(float)fVar6);
        if ((iVar5 == -1) || ((float10)fStack_4 < fVar6)) {
          fStack_4 = (float)fVar6;
          iVar5 = *(int *)(DAT_0087d7f0 + iStack_8 * 8);
        }
      }
      iStack_8 = iStack_8 + 1;
    } while (iStack_8 < DAT_0087d7d8);
  }
  if (param_2 != (float *)0x0) {
    *param_2 = fStack_4;
  }
  return iVar5;
}

// --------------------------------------------------

// Function: FUN_00415acc
// Address: 00415acc
int __thiscall FUN_00415acc(UnitAIModule *param_1,float *param_2)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  int iVar3;
  float fStack_4;
  
  (**(code **)(param_1->_padding_ + 0x20))();
  iVar2 = -1;
  iVar3 = 0;
  fStack_4 = 0.0;
  if (0 < DAT_0087d7d8) {
    do {
      pRVar1 = UnitAIModule::lookupObject(param_1,*(int *)(DAT_0087d7f0 + iVar3 * 8));
      if ((pRVar1 != (RGE_Static_Object *)0x0) && ((iVar2 == -1 || (pRVar1->hp < fStack_4)))) {
        fStack_4 = pRVar1->hp;
        iVar2 = *(int *)(DAT_0087d7f0 + iVar3 * 8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_0087d7d8);
  }
  if (param_2 != (float *)0x0) {
    *param_2 = fStack_4;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00415b4c
// Address: 00415b4c
int __thiscall FUN_00415b4c(int param_1,float *param_2)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  float fVar5;
  float fStack_c;
  int iStack_8;
  
  iVar4 = 0;
  iStack_8 = -1;
  fStack_c = 0.0;
  if (0 < *(int *)(param_1 + 100)) {
    do {
      if (*(int *)(param_1 + 0x6c) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x6c)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x60) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x6c));
          }
          operator_delete(*(void **)(param_1 + 0x60));
          *(void **)(param_1 + 0x60) = pvVar1;
          *(int *)(param_1 + 0x6c) = iVar4 + 1;
        }
      }
      pRVar3 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x3c),
                          *(int *)(*(int *)(param_1 + 0x60) + iVar4 * 4));
      if (pRVar3 != (RGE_Static_Object *)0x0) {
        fVar5 = RGE_Static_Object::distance_to_object(*(RGE_Static_Object **)(param_1 + 4),pRVar3);
        if ((iStack_8 == -1) || (fVar5 < fStack_c)) {
          if (*(int *)(param_1 + 0x6c) + -1 < iVar4) {
            pvVar1 = operator_new(iVar4 * 4 + 4);
            if (pvVar1 != (void *)0x0) {
              iVar2 = 0;
              if (0 < *(int *)(param_1 + 0x6c)) {
                do {
                  if (iVar4 + 1 <= iVar2) break;
                  iVar2 = iVar2 + 1;
                  *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                       *(undefined4 *)(*(int *)(param_1 + 0x60) + -4 + iVar2 * 4);
                } while (iVar2 < *(int *)(param_1 + 0x6c));
              }
              operator_delete(*(void **)(param_1 + 0x60));
              *(void **)(param_1 + 0x60) = pvVar1;
              *(int *)(param_1 + 0x6c) = iVar4 + 1;
            }
          }
          iStack_8 = *(int *)(*(int *)(param_1 + 0x60) + iVar4 * 4);
          fStack_c = fVar5;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 100));
  }
  if (param_2 != (float *)0x0) {
    *param_2 = fStack_c;
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_00415c98
// Address: 00415c98
int __thiscall
FUN_00415c98(int *param_1,int param_2,int param_3,uint param_4,int param_5,undefined4 *param_6)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float fStack_30;
  int iStack_2c;
  int aiStack_24 [9];
  
  (**(code **)(*param_1 + 0x20))();
  piVar6 = aiStack_24;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  iStack_2c = -1;
  fStack_30 = -1.0;
  iVar4 = 0;
  do {
    iVar5 = 0;
    if (0 < *(int *)((int)&VisibleUnitList_Size + iVar4)) {
      piVar6 = (int *)((int)&VisibleUnitList + iVar4);
      do {
        iVar1 = *piVar6;
        aiStack_24[*(byte *)(iVar1 + 5 + iVar5 * 8)] = 1;
        if (*(int *)(param_1[1] + 4) != *(int *)(iVar1 + iVar5 * 8)) {
          pRVar2 = RGE_Game_World::object
                             (*(RGE_Game_World **)(*(int *)(param_1[1] + 0xc) + 0x3c),
                              *(int *)(*piVar6 + iVar5 * 8));
          if (((((((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->object_state < 7)) &&
                 ((param_3 != 0 || ((iVar4 == 8 || (iVar4 == 4)))))) &&
                ((param_3 != 2 || (iVar4 == 0x10)))) &&
               (((param_3 != 3 || (iVar4 == 4)) &&
                (((param_3 != 1 || (iVar4 == 0xc)) &&
                 ((param_2 == -1 || (pRVar2->master_obj->object_group == param_2)))))))) &&
              ((param_5 == -1 || (pRVar2->master_obj->id == param_5)))) &&
             ((param_4 == 0xffffffff || (pRVar2->object_state == param_4)))) {
            if (iStack_2c != -1) {
              if (fStack_30 <= (float)*(byte *)(*piVar6 + 4 + iVar5 * 8)) goto LAB_00415de5;
            }
            fStack_30 = (float)*(byte *)(*piVar6 + 4 + iVar5 * 8);
            iStack_2c = *(int *)(*piVar6 + iVar5 * 8);
          }
        }
LAB_00415de5:
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)((int)&VisibleUnitList_Size + iVar4));
    }
    iVar4 = iVar4 + 4;
    if (0x10 < iVar4) {
      numberDifferentPlayerObjectsVisible = 0;
      piVar6 = aiStack_24;
      iVar4 = 8;
      do {
        piVar6 = piVar6 + 1;
        if (*piVar6 == 1) {
          numberDifferentPlayerObjectsVisible = numberDifferentPlayerObjectsVisible + 1;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (param_6 != (undefined4 *)0x0) {
        uVar3 = __ftol();
        *param_6 = uVar3;
      }
      return iStack_2c;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00415e44
// Address: 00415e44
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00415e44(int param_1,int param_2,uint *param_3)
{
  RGE_Static_Object *this;
  byte bVar1;
  int iVar3;
  int iVar4;
  VISIBLE_RESOURCE_REC *pVVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int aiStack_190 [100];
  uint uVar2;
  
  piVar8 = aiStack_190;
  piVar9 = aiStack_190;
  for (iVar7 = 100; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = -0x80000000;
    piVar9 = piVar9 + 1;
  }
  iVar7 = 0;
  do {
    this = *(RGE_Static_Object **)(param_1 + 4);
    piVar9 = aiStack_190;
    iVar6 = param_2;
    iVar10 = iVar7;
    bVar1 = RGE_Static_Object::currentZone(this);
    uVar2 = (uint)bVar1;
    iVar3 = __ftol();
    iVar4 = __ftol();
    pVVar5 = Visible_Resource_Manager::Get_Closest_Resource
                       (this->owner->VR_List,iVar4,iVar3,uVar2,iVar6,piVar9,iVar10);
    if (pVVar5 == (VISIBLE_RESOURCE_REC *)0x0) {
      return -1;
    }
    if (*(float *)((*(int **)(param_1 + 4))[2] + 0x28) - _DAT_0056ebe0 < (float)pVVar5->distance) {
      return -1;
    }
    iVar6 = (**(code **)(**(int **)(param_1 + 4) + 0x194))
                      (pVVar5->object_id,0x3f800000,0,0,0xffffffff,0xffffffff);
    if (iVar6 == 1) break;
    iVar7 = iVar7 + 1;
    *piVar8 = pVVar5->object_id;
    piVar8 = piVar8 + 1;
  } while (iVar7 < 100);
  if (param_3 != (uint *)0x0) {
    *param_3 = (uint)pVVar5->distance;
  }
  return pVVar5->object_id;
}

// --------------------------------------------------

// Function: FUN_00415f3b
// Address: 00415f3b
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00415f3b(UnitAIModule *param_1,int *param_2,int *param_3,int param_4)
{
  RGE_Static_Object *pRVar1;
  RGE_Player *pRVar2;
  RGE_Visible_Map *pRVar3;
  RGE_Map *pRVar4;
  int iVar5;
  uchar uVar6;
  uchar uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iStack_28;
  int iStack_24;
  int iStack_1c;
  
  if (((param_1->currentOrderValue != 0x2c1) || (param_1->currentTargetXValue == -1.0)) ||
     (param_1->currentTargetYValue == -1.0)) {
    pRVar1 = param_1->objectValue;
    iStack_1c = -1;
    iVar8 = __ftol();
    iVar9 = __ftol();
    __ftol();
    iStack_28 = __ftol();
    iStack_24 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    pRVar2 = pRVar1->owner;
    pRVar3 = pRVar2->visible;
    pRVar4 = pRVar2->world->map;
    if (iStack_28 < 0) {
      iStack_28 = 0;
    }
    iVar16 = pRVar4->map_width + -1;
    if (iVar16 < iStack_24) {
      iStack_24 = iVar16;
    }
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    iVar16 = pRVar4->map_height + -1;
    if (iVar16 < iVar11) {
      iVar11 = iVar16;
    }
    iVar16 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xb2e);
    uVar6 = RGE_Static_Object::currentZone(param_1->objectValue);
    for (; iVar5 = iStack_28, iVar10 <= iVar11; iVar10 = iVar10 + 1) {
      for (; iVar5 <= iStack_24; iVar5 = iVar5 + 1) {
        uVar7 = UnitAIModule::visibleStatus(param_1,pRVar3,iVar5,iVar10);
        if (((uVar7 == '\0') &&
            (uVar7 = RGE_Static_Object::lookupZone(param_1->objectValue,iVar5,iVar10),
            uVar6 == uVar7)) &&
           ((iVar12 = (**(code **)(param_1->objectValue->_padding_ + 0x114))
                                ((float)iVar5,(float)iVar10,0), iVar12 != 0 &&
            ((param_4 == 0 ||
             (iVar12 = UnitAIModule::inWaypointQueue(param_1,iVar5,iVar10), iVar12 == 0)))))) {
          iVar12 = (iVar5 - iVar8) * (iVar5 - iVar8) + (iVar10 - iVar9) * (iVar10 - iVar9);
          if (param_1->currentTargetXValue != -1.0) {
            iVar13 = __ftol();
            iVar14 = __ftol();
            iVar12 = (iVar10 - iVar14) * (iVar10 - iVar14) + iVar12 +
                     (iVar5 - iVar13) * (iVar5 - iVar13);
          }
          if ((iStack_1c == -1) || (iVar12 < iVar16 % 3 + iStack_1c)) {
            *param_2 = iVar5;
            *param_3 = iVar10;
            iStack_1c = iVar12;
          }
        }
      }
    }
    if (iStack_1c != -1) {
      pRVar1 = param_1->objectValue;
      iVar10 = *param_2;
      iVar11 = *param_3;
      uVar15 = __ftol();
      uVar15 = (**(code **)(pRVar1->_padding_ + 0x198))
                         (iVar10,iVar11,uVar15,pRVar1->master_obj->los - _DAT_0056ebd0,0xffffffff,
                          &param_2,0,0xffffffff,0xffffffff);
      return uVar15;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004161cc
// Address: 004161cc
undefined4 FUN_004161cc(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004161d5
// Address: 004161d5
undefined4 __fastcall FUN_004161d5(int param_1)
{
  return *(undefined4 *)(param_1 + 0xf0);
}

// --------------------------------------------------

// Function: FUN_004161e7
// Address: 004161e7
undefined4 __thiscall FUN_004161e7(int param_1,int param_2,int param_3)
{
  if (7 < *(int *)(param_1 + 0xf0)) {
    *(undefined4 *)(param_1 + 0xf0) = 0;
  }
  *(float *)((*(int *)(param_1 + 0xf0) + 7) * 0x10 + param_1) = (float)param_2;
  *(float *)(*(int *)(param_1 + 0xf0) * 0x10 + 0x74 + param_1) = (float)param_3;
  *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041623c
// Address: 0041623c
undefined4 __thiscall FUN_0041623c(int param_1,int param_2,int param_3)
{
  float *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0xf0) < 1) {
    return 0;
  }
  pfVar1 = (float *)(param_1 + 0x74);
  do {
    if (pfVar1[-1] == (float)param_2) {
      if ((float)param_3 == *pfVar1) {
        return 1;
      }
    }
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 4;
  } while (iVar2 < *(int *)(param_1 + 0xf0));
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041629b
// Address: 0041629b
undefined4 FUN_0041629b(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_004162a8
// Address: 004162a8
undefined4 FUN_004162a8(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_004162b8
// Address: 004162b8
// [HELPER] s_t_ld__U__d_sO__cOAA__d__: "t%ld, U#%d sO, cOAA=%d.\n"
undefined4 __thiscall FUN_004162b8(int param_1,int param_2)
{
  undefined4 uVar1;
  
  if (actionFile != (_iobuf *)0x0) {
    fprintf(actionFile,s_t_ld__U__d_sO__cOAA__d__,
            *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x3c) + 4),
            *(undefined4 *)(*(int *)(param_1 + 4) + 4),param_2);
  }
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x30);
  if ((param_2 == 0) || (*(int *)(param_1 + 0x30) + 100 == *(int *)(param_1 + 0x28))) {
    uVar1 = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x50) = uVar1;
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  }
  (**(code **)(**(int **)(param_1 + 4) + 0x18c))();
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00416336
// Address: 00416336
undefined4 __thiscall FUN_00416336(UnitAIModule *param_1,int param_2,int param_3)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  if ((param_3 != 0) || (param_1->currentActionValue == -1)) {
    pRVar1 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      iVar2 = (**(code **)(param_1->_padding_ + 0x50))(pRVar1);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(param_1->objectValue->_padding_ + 0x150))(param_2,param_3);
        if (iVar2 == 1) {
          UnitAIModule::setCurrentAction(param_1,600);
          UnitAIModule::setCurrentTarget
                    (param_1,param_2,pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416467
// Address: 00416467
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
undefined4 __thiscall FUN_00416467(UnitAIModule *param_1,undefined4 param_2,int param_3)
{
  long lVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int unaff_retaddr;
  
  if ((param_3 != 0) || (param_1->currentActionValue != 0x265)) {
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar1 = -1;
      }
      else {
        lVar1 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar1,s_C__msdev_work_age1_x1_aiuaimod_c,0xc48
             );
    }
    (**(code **)(param_1->_padding_ + 0x58))(1);
    iVar2 = (**(code **)(param_1->objectValue->_padding_ + 0x164))(unaff_retaddr,param_3);
    if (iVar2 == 1) {
      pRVar3 = RGE_Game_World::object(param_1->objectValue->owner->world,unaff_retaddr);
      UnitAIModule::setCurrentAction(param_1,0x265);
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,unaff_retaddr,-1,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,unaff_retaddr,(int)pRVar3->master_obj->object_group,pRVar3->world_x,
                 pRVar3->world_y,pRVar3->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416543
// Address: 00416543
undefined4 __thiscall FUN_00416543(UnitAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_3 != 0) || (param_1->currentActionValue != 0x25c)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x16c))(param_2,param_3);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
      UnitAIModule::setCurrentAction(param_1,0x25c);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_2,-1,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_2,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                 pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004165e4
// Address: 004165e4
undefined4 __thiscall FUN_004165e4(UnitAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_3 != 0) || (param_1->currentActionValue != 0x25b)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x88))(param_2,param_3);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
      UnitAIModule::setCurrentAction(param_1,0x25b);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_2,-1,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_2,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                 pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416684
// Address: 00416684
undefined4 __thiscall FUN_00416684(UnitAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_3 != 0) || (param_1->currentActionValue != 0x261)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x168))(param_2,param_3);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
      UnitAIModule::setCurrentAction(param_1,0x261);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_2,-1,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_2,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                 pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416724
// Address: 00416724
undefined4 __thiscall FUN_00416724(UnitAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_3 != 0) || (param_1->currentActionValue != 0x26a)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x170))(param_2,param_3);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
      UnitAIModule::setCurrentAction(param_1,0x26a);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_2,-1,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_2,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                 pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004167c4
// Address: 004167c4
undefined4 __thiscall FUN_004167c4(UnitAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_3 != 0) || (param_1->currentActionValue != 0x25a)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x174))(param_2,param_3);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
      UnitAIModule::setCurrentAction(param_1,0x25a);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_2,-1,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_2,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                 pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416864
// Address: 00416864
undefined4 __thiscall FUN_00416864(UnitAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_3 != 0) || (param_1->currentActionValue != 0x267)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x178))(param_2,param_3);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
      UnitAIModule::setCurrentAction(param_1,0x267);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_2,-1,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_2,(int)pRVar2->master_obj->object_group,pRVar2->world_x,
                 pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416904
// Address: 00416904
undefined4 __thiscall
FUN_00416904(UnitAIModule *param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  int unaff_ESI;
  
  if ((param_4 != 0) || (param_1->currentActionValue == -1)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x17c))(param_2,param_3);
    if (iVar1 == 1) {
      UnitAIModule::setCurrentAction(param_1,0x25d);
      UnitAIModule::setCurrentTarget(param_1,-1,(float)param_4,(float)unaff_ESI,1.0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416975
// Address: 00416975
undefined4 __thiscall FUN_00416975(UnitAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  
  if ((param_3 != 0) || (param_1->currentActionValue == -1)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x180))(param_2,param_3);
    if (iVar1 == 1) {
      UnitAIModule::setCurrentAction(param_1,0x269);
      UnitAIModule::setCurrentTarget(param_1,param_2,-1.0,-1.0,-1.0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004169dc
// Address: 004169dc
undefined4 __thiscall
FUN_004169dc(UnitAIModule *param_1,float param_2,float param_3,float param_4,int param_5)
{
  int iVar1;
  
  if ((param_5 != 0) || (param_1->currentActionValue == -1)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x188))(param_2,param_3,param_4,param_5);
    if (iVar1 == 1) {
      UnitAIModule::setCurrentAction(param_1,0x266);
      UnitAIModule::setCurrentTarget(param_1,-1,param_2,param_3,param_4);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416a41
// Address: 00416a41
undefined4 __thiscall
FUN_00416a41(UnitAIModule *param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  RGE_Static_Object *pRVar1;
  int iVar2;
  
  if ((param_2 != 0) || (param_1->currentActionValue == -1)) {
    iVar2 = (**(code **)(param_1->objectValue->_padding_ + 0x184))
                      (param_2,param_3,param_4,param_1->objectValue->world_z);
    if (iVar2 == 1) {
      pRVar1 = param_1->objectValue;
      UnitAIModule::setCurrentAction(param_1,0x26d);
      if (pRVar1 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_1->objectValue->id,-1,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_1->objectValue->id,(int)pRVar1->master_obj->object_group,
                 pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416ae4
// Address: 00416ae4
undefined4 __thiscall FUN_00416ae4(UnitAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_3 != 0) || (param_1->currentActionValue == -1)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x15c))(param_2,param_3);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
      UnitAIModule::setCurrentAction(param_1,0x262);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_2,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_2,pRVar2->world_x,pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416b77
// Address: 00416b77
undefined4 __thiscall FUN_00416b77(UnitAIModule *param_1,int param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((param_4 != 0) || (param_1->currentActionValue == -1)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x158))(param_2,param_3,param_4);
    if (iVar1 == 1) {
      pRVar2 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
      UnitAIModule::setCurrentAction(param_1,0x262);
      if (pRVar2 == (RGE_Static_Object *)0x0) {
        UnitAIModule::setCurrentTarget(param_1,param_2,0.0,0.0,0.0);
        return 1;
      }
      UnitAIModule::setCurrentTarget
                (param_1,param_2,pRVar2->world_x,pRVar2->world_y,pRVar2->world_z);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416c0c
// Address: 00416c0c
undefined4 __thiscall
FUN_00416c0c(UnitAIModule *param_1,float param_2,float param_3,float param_4,undefined4 param_5,
            int param_6)
{
  int iVar1;
  
  if ((param_6 != 0) || (param_1->currentActionValue == -1)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x154))
                      (param_2,param_3,param_4,param_5,param_6);
    if (iVar1 == 1) {
      UnitAIModule::setCurrentAction(param_1,0x262);
      UnitAIModule::setCurrentTarget(param_1,-1,param_2,param_3,param_4);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416c76
// Address: 00416c76
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00416c76(UnitAIModule *param_1,float param_2,float param_3,float param_4,int param_5)
{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_5 != 0) || (param_1->currentActionValue == -1)) {
    if (_DAT_0056ebc8 <= param_2) {
      fVar1 = (float)param_1->objectValue->owner->world->map->map_width;
      if (fVar1 <= param_2) {
        param_2 = fVar1 - _DAT_0056ebd0;
      }
    }
    else {
      param_2 = 0.0;
    }
    if (_DAT_0056ebc8 <= param_3) {
      fVar1 = (float)param_1->objectValue->owner->world->map->map_height;
      if (fVar1 <= param_3) {
        param_3 = fVar1 - _DAT_0056ebd0;
      }
    }
    else {
      param_3 = 0.0;
    }
    iVar5 = 0;
    do {
      iVar2 = (**(code **)(param_1->objectValue->_padding_ + 0x114))(param_2,param_3,0);
      if (iVar2 == 1) break;
      uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xd9f);
      uVar4 = (int)uVar3 >> 0x1f;
      if (((uVar3 ^ uVar4) - uVar4 & 1 ^ uVar4) == uVar4) {
        uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda2);
        uVar4 = (int)uVar3 >> 0x1f;
        param_2 = param_2 - (float)(int)(((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4);
      }
      else {
        uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda0);
        uVar4 = (int)uVar3 >> 0x1f;
        param_2 = (float)(int)(((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4) + param_2;
      }
      uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda3);
      uVar4 = (int)uVar3 >> 0x1f;
      if (((uVar3 ^ uVar4) - uVar4 & 1 ^ uVar4) == uVar4) {
        uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda6);
        uVar4 = (int)uVar3 >> 0x1f;
        param_3 = param_3 - (float)(int)(((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4);
      }
      else {
        uVar3 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xda4);
        uVar4 = (int)uVar3 >> 0x1f;
        param_3 = (float)(int)(((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4) + param_3;
      }
      if (_DAT_0056ebc8 <= param_2) {
        fVar1 = (float)param_1->objectValue->owner->world->map->map_width;
        if (fVar1 <= param_2) {
          param_2 = fVar1 - _DAT_0056ebd0;
        }
      }
      else {
        param_2 = 0.0;
      }
      if (_DAT_0056ebc8 <= param_3) {
        fVar1 = (float)param_1->objectValue->owner->world->map->map_height;
        if (fVar1 <= param_3) {
          param_3 = fVar1 - _DAT_0056ebd0;
        }
      }
      else {
        param_3 = 0.0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
    iVar5 = (**(code **)(param_1->objectValue->_padding_ + 0x154))
                      (param_2,param_3,param_4,0,param_5);
    if (iVar5 == 1) {
      UnitAIModule::setCurrentAction(param_1,0x262);
      UnitAIModule::setCurrentTarget(param_1,-1,param_2,param_3,param_4);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00416f22
// Address: 00416f22
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00416f22(UnitAIModule *param_1)
{
  RGE_Static_Object *pRVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  float unaff_EBX;
  float fVar6;
  float unaff_EBP;
  float unaff_ESI;
  float fVar7;
  float fVar8;
  int in_stack_00000014;
  float fStack_34;
  float fStack_30;
  int iStack_2c;
  int iStack_14;
  undefined4 uStack_10;
  
  if ((in_stack_00000014 != 0) || (param_1->currentActionValue == -1)) {
    fVar2 = (float)__ftol();
    iVar3 = __ftol();
    pRVar1 = param_1->objectValue;
    uVar4 = __ftol();
    iStack_2c = -1;
    fStack_30 = 0.0;
    fStack_34 = 0.0;
    iVar5 = (**(code **)(pRVar1->_padding_ + 0x198))(fVar2,iVar3,uVar4,0x3f800000,0xffffffff);
    if (iVar5 == 0) {
      fVar7 = RGE_Static_Object::distance_to_position
                        (param_1->objectValue,unaff_ESI,unaff_EBP,param_1->objectValue->world_z);
      fVar6 = -NAN;
LAB_0041704d:
      do {
        fStack_34 = (float)((int)fVar6 + 1);
        switch(fStack_34) {
        case 0.0:
          fVar2 = (float)((int)fVar2 + -2);
          fStack_30 = fVar2;
        case 9.80909e-45:
          iVar3 = iVar3 + -2;
          iStack_2c = iVar3;
          break;
        case 1.4013e-45:
        case 2.8026e-45:
          fVar2 = (float)((int)fVar2 + 2);
          fStack_30 = fVar2;
          break;
        case 4.2039e-45:
        case 5.60519e-45:
          iVar3 = iVar3 + 2;
          iStack_2c = iVar3;
          break;
        case 7.00649e-45:
        case 8.40779e-45:
          fVar2 = (float)((int)fVar2 + -2);
          fStack_30 = fVar2;
          break;
        default:
          goto switchD_0041705b_default;
        }
        if ((int)fVar2 < 0) {
          fVar2 = 0.0;
          fStack_30 = fVar2;
        }
        else {
          iVar5 = param_1->objectValue->owner->world->map->map_width;
          if (iVar5 <= (int)fVar2) {
            fVar2 = (float)(iVar5 + -1);
            fStack_30 = fVar2;
          }
        }
        if (iVar3 < 0) {
          iVar3 = 0;
          iStack_2c = iVar3;
        }
        else {
          iVar5 = param_1->objectValue->owner->world->map->map_height;
          if (iVar5 <= iVar3) {
            iVar3 = iVar5 + -1;
            iStack_2c = iVar3;
          }
        }
        if ((iStack_14 == 0) &&
           (fVar8 = RGE_Static_Object::distance_to_position
                              (param_1->objectValue,(float)(int)fStack_30 - _DAT_0056ebe4,
                               (float)iStack_2c - _DAT_0056ebe4,param_1->objectValue->world_z),
           fVar8 < fVar7)) {
          fVar6 = (float)((int)fVar6 + 2);
          goto LAB_0041704d;
        }
        iVar5 = (**(code **)(param_1->objectValue->_padding_ + 0x198))
                          (fVar2,iVar3,0xffffffff,0x3f800000,0xffffffff,0,0,0xffffffff,0xffffffff);
        fVar6 = fStack_34;
      } while (iVar5 != 1);
    }
    iVar3 = (**(code **)(param_1->objectValue->_padding_ + 0x154))
                      ((float)(int)fStack_30 - _DAT_0056ebe4,(float)iStack_2c - _DAT_0056ebe4,
                       unaff_EBX,0x3f000000,uStack_10);
    if (iVar3 == 1) {
      UnitAIModule::setCurrentAction(param_1,0x262);
      UnitAIModule::setCurrentTarget(param_1,-1,fStack_34,fStack_30,unaff_EBX);
      return 1;
    }
  }
switchD_0041705b_default:
  return 0;
}

// --------------------------------------------------

// Function: FUN_004171ca
// Address: 004171ca
/* WARNING: Instruction at (ram,0x00417228) overlaps instruction at (ram,0x00417226)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall
FUN_004171ca(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,float param_6
            ,undefined4 param_7,float param_8)
{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  float fVar5;
  uint in_EAX;
  char *pcVar6;
  void *pvVar7;
  int iVar8;
  RGE_Static_Object *pRVar9;
  undefined4 uVar10;
  char cVar11;
  char cVar12;
  byte bVar13;
  int unaff_EBX;
  int *unaff_ESI;
  char in_AF;
  float10 fVar14;
  byte bVar4;
  
  pcVar6 = (char *)(param_2 + -0x55ffbe8f);
  cVar2 = *pcVar6;
  cVar11 = (char)((uint)param_1 >> 8);
  *pcVar6 = *pcVar6 + cVar11;
  if (SCARRY1(cVar2,cVar11)) {
    pcVar6 = (char *)((int)unaff_ESI + -0x49ffbe8f);
    cVar2 = *pcVar6;
    cVar12 = (char)((uint)param_2 >> 8);
    *pcVar6 = *pcVar6 + cVar12;
    if (SCARRY1(cVar2,cVar12)) {
      pbVar1 = (byte *)((int)unaff_ESI + -0x41ffbe8f);
      bVar3 = *pbVar1;
      bVar13 = (byte)((uint)unaff_EBX >> 8);
      bVar4 = *pbVar1;
      *pbVar1 = *pbVar1 + bVar13;
      if (!SCARRY1(bVar4,bVar13)) {
        pcVar6 = (char *)CONCAT22((short)(in_EAX >> 0x10),
                                  CONCAT11(((char)*pbVar1 < '\0') << 7 | (*pbVar1 == 0) << 6 |
                                           in_AF << 4 | ((POPCOUNT(*pbVar1) & 1U) == 0) << 2 | 2U |
                                           CARRY1(bVar3,bVar13),(char)in_EAX));
        *pcVar6 = *pcVar6 + (char)in_EAX;
        *(char *)(unaff_EBX + 0x3b486c46) = *(char *)(unaff_EBX + 0x3b486c46) + (char)param_1;
        goto code_r0x00417234;
      }
      *(char *)(param_1 + 0x70) = *(char *)(param_1 + 0x70) + cVar11;
      unaff_ESI = (int *)(param_1 + 1);
      *(char *)(in_EAX + 0x51909090) = *(char *)(in_EAX + 0x51909090) + (char)param_2;
      if ((param_4 == 0) && (*(int *)(param_1 + 0x31) != -1)) {
        return 0;
      }
    }
    else {
      pcVar6 = (char *)(in_EAX & 0xffffff18);
      *pcVar6 = *pcVar6 + (char)pcVar6;
      *pcVar6 = *pcVar6 + (char)pcVar6;
    }
  }
  else {
    pcVar6 = (char *)(in_EAX & 0xffffff10);
    *pcVar6 = *pcVar6 + (char)pcVar6;
    *pcVar6 = *pcVar6 + (char)pcVar6;
  }
  unaff_EBX = 0;
  param_6 = 0.0;
  param_8 = 0.0;
  if (0 < unaff_ESI[0x19]) {
    do {
      if (unaff_ESI[0x1b] + -1 < unaff_EBX) {
code_r0x00417234:
        pvVar7 = operator_new(unaff_EBX * 4 + 4);
        if (pvVar7 != (void *)0x0) {
          iVar8 = 0;
          if (0 < unaff_ESI[0x1b]) {
            do {
              if (unaff_EBX + 1 <= iVar8) break;
              iVar8 = iVar8 + 1;
              *(undefined4 *)((int)pvVar7 + iVar8 * 4 + -4) =
                   *(undefined4 *)(unaff_ESI[0x18] + -4 + iVar8 * 4);
            } while (iVar8 < unaff_ESI[0x1b]);
          }
          operator_delete((void *)unaff_ESI[0x18]);
          unaff_ESI[0x18] = (int)pvVar7;
          unaff_ESI[0x1b] = unaff_EBX + 1;
        }
      }
      pRVar9 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(unaff_ESI[1] + 0xc) + 0x3c),
                          *(int *)(unaff_ESI[0x18] + unaff_EBX * 4));
      if (pRVar9 != (RGE_Static_Object *)0x0) {
        param_6 = (pRVar9->world_x - *(float *)(unaff_ESI[1] + 0x38)) + param_6;
        param_8 = (pRVar9->world_y - *(float *)(unaff_ESI[1] + 0x3c)) + param_8;
      }
      unaff_EBX = unaff_EBX + 1;
    } while (unaff_EBX < unaff_ESI[0x19]);
  }
  fVar14 = (float10)(**(code **)(*(int *)unaff_ESI[1] + 0xfc))();
  iVar8 = unaff_ESI[1];
  fVar5 = SQRT(param_8 * param_8 + param_6 * param_6);
  uVar10 = (**(code **)(*unaff_ESI + 0x9c))
                     (-((param_6 / fVar5) * (float)(fVar14 * (float10)_DAT_0056ebe8)) +
                      *(float *)(iVar8 + 0x38),
                      -((param_8 / fVar5) * (float)(fVar14 * (float10)_DAT_0056ebe8)) +
                      *(float *)(iVar8 + 0x3c),*(undefined4 *)(iVar8 + 0x40),1);
  return uVar10;
}

// --------------------------------------------------

// Function: FUN_00417355
// Address: 00417355
undefined4 __thiscall FUN_00417355(UnitAIModule *param_1,int param_2,float param_3,int param_4)
{
  RGE_Static_Object *pRVar1;
  
  if ((param_4 == 0) && (param_1->currentActionValue != -1)) {
    return 0;
  }
  pRVar1 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  UnitAIModule::setCurrentAction(param_1,0x264);
  UnitAIModule::setCurrentTarget(param_1,param_2,pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
  param_1->desiredTargetDistanceValue = param_3;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004173cc
// Address: 004173cc
undefined4 __thiscall FUN_004173cc(UnitAIModule *param_1,int param_2,float param_3,int param_4)
{
  RGE_Static_Object *pRVar1;
  
  if ((param_4 == 0) && (param_1->currentActionValue != -1)) {
    return 0;
  }
  pRVar1 = RGE_Game_World::object(param_1->objectValue->owner->world,param_2);
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  UnitAIModule::setCurrentAction(param_1,0x259);
  UnitAIModule::setCurrentTarget(param_1,param_2,pRVar1->world_x,pRVar1->world_y,pRVar1->world_z);
  param_1->defendTargetValue = param_2;
  param_1->desiredTargetDistanceValue = param_3;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041743f
// Address: 0041743f
undefined4 __thiscall
FUN_0041743f(UnitAIModule *param_1,float param_2,float param_3,float param_4,int param_5)
{
  if ((param_5 == 0) && (param_1->currentActionValue != -1)) {
    return 0;
  }
  UnitAIModule::setCurrentAction(param_1,0x259);
  UnitAIModule::setCurrentTarget(param_1,-1,param_2,param_3,param_1->objectValue->world_z);
  param_1->defendTargetValue = -1;
  param_1->desiredTargetDistanceValue = param_4;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00417494
// Address: 00417494
undefined4 __thiscall
FUN_00417494(UnitAIModule *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  int iVar1;
  int unaff_retaddr;
  
  if ((param_5 != 0) || (param_1->currentActionValue == -1)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x150))(param_2,param_5);
    if (iVar1 == 1) {
      UnitAIModule::setCurrentAction(param_1,0x26e);
      UnitAIModule::setCurrentTarget(param_1,param_2,(float)unaff_retaddr,(float)param_2,1.0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00417502
// Address: 00417502
undefined4 __thiscall
FUN_00417502(UnitAIModule *param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  int unaff_ESI;
  
  if ((param_4 != 0) || (param_1->currentActionValue == -1)) {
    iVar1 = (**(code **)(param_1->objectValue->_padding_ + 0x17c))(param_2,param_3);
    if (iVar1 == 1) {
      UnitAIModule::setCurrentAction(param_1,0x26f);
      UnitAIModule::setCurrentTarget(param_1,-1,(float)param_4,(float)unaff_ESI,1.0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00417575
// Address: 00417575
void __fastcall FUN_00417575(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  *(undefined4 *)(param_1 + 0x3c) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x40) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x44) = 0xbf800000;
  return;
}

// --------------------------------------------------

// Function: FUN_004175a4
// Address: 004175a4
void __thiscall
FUN_004175a4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  RGE_Static_Object *pRVar1;
  
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x38);
  *(int *)(param_1 + 0x34) = param_2;
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x40) = param_4;
  *(undefined4 *)(param_1 + 0x44) = param_5;
  pRVar1 = RGE_Game_World::object
                     (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x3c),param_2);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    *(int *)(param_1 + 0x38) = (int)pRVar1->master_obj->object_group;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004175fc
// Address: 004175fc
void __thiscall
FUN_004175fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)
{
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x34) = param_2;
  *(undefined4 *)(param_1 + 0x38) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = param_4;
  *(undefined4 *)(param_1 + 0x40) = param_5;
  *(undefined4 *)(param_1 + 0x44) = param_6;
  return;
}

// --------------------------------------------------

// Function: FUN_00417632
// Address: 00417632
undefined4 __thiscall FUN_00417632(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x128) < 1) {
    return 0;
  }
  piVar2 = *(int **)(param_1 + 0x124);
  do {
    if (*piVar2 == param_2) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < *(int *)(param_1 + 0x128));
  return 0;
}

// --------------------------------------------------

// Function: FUN_00417678
// Address: 00417678
bool __thiscall FUN_00417678(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  if (*(short *)(iVar1 + 0x4a) == param_2) {
    return false;
  }
  return *(char *)(*(int *)(iVar1 + 0x84) + param_2) == '\x03';
}

// --------------------------------------------------

// Function: FUN_004176af
// Address: 004176af
undefined4 __thiscall FUN_004176af(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  if (*(short *)(iVar1 + 0x4a) == param_2) {
    return 1;
  }
  if ((*(char *)(*(int *)(iVar1 + 0x84) + param_2) == '\0') &&
     (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 0x3c) + 0x40) + param_2 * 4) + 0x84) +
               (int)*(short *)(iVar1 + 0x4a)) == '\0')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004176fc
// Address: 004176fc
bool __thiscall FUN_004176fc(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  if (*(short *)(iVar1 + 0x4a) == param_2) {
    return false;
  }
  return *(char *)(*(int *)(iVar1 + 0x84) + param_2) == '\x01';
}

// --------------------------------------------------

// Function: FUN_0041772f
// Address: 0041772f
uint __thiscall FUN_0041772f(int param_1,undefined4 param_2,int param_3,int param_4)
{
  int iVar1;
  ulong *puVar2;
  undefined3 uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  puVar2 = (&unified_map_offsets)[param_4][param_3];
  uVar3 = (undefined3)((uint)puVar2 >> 8);
  if ((*(uint *)(iVar1 + 0xd4) & (uint)puVar2) != 0) {
    return CONCAT31(uVar3,0xf);
  }
  return CONCAT31(uVar3,-((*(uint *)(iVar1 + 0xd0) & (uint)puVar2) != 0)) & 0xffffff80;
}

// --------------------------------------------------

// Function: FUN_0041776c
// Address: 0041776c
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
void __fastcall FUN_0041776c(int param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x100);
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xf4c);
  *(uint *)(param_1 + 0xfc) = uVar2 % (uVar1 >> 1) + (uVar1 * 3 >> 2);
  return;
}

// --------------------------------------------------

// Function: FUN_004177a5
// Address: 004177a5
void __fastcall FUN_004177a5(UnitAIModule *param_1)
{
  UnitAIModule::purgeNotifyQueue(param_1,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004177b8
// Address: 004177b8
undefined4 FUN_004177b8(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004177c6
// Address: 004177c6
void __thiscall FUN_004177c6(int param_1,AIPlayStatus *param_2)
{
  AIPlayStatus *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c8eb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 300) == 0) {
    this = (AIPlayStatus *)operator_new(0x1c8);
    uStack_4 = 0;
    if (this == (AIPlayStatus *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = AIPlayStatus::AIPlayStatus(this);
    }
    *(undefined4 *)(param_1 + 300) = uVar1;
  }
  uStack_4 = 0xffffffff;
  if ((*(AIPlayStatus **)(param_1 + 300) != (AIPlayStatus *)0x0) && (param_2 != (AIPlayStatus *)0x0)
     ) {
    AIPlayStatus::copy(*(AIPlayStatus **)(param_1 + 300),param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00417853
// Address: 00417853
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
int __fastcall FUN_00417853(int *param_1)
{
  short sVar1;
  undefined4 uVar2;
  RGE_Game_World *this;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iVar5;
  
  (**(code **)(*param_1 + 0x20))();
  iVar4 = 0;
  uVar2 = *(undefined4 *)(param_1[1] + 4);
  iVar5 = *(int *)(param_1[1] + 0xc);
  sVar1 = *(short *)(iVar5 + 0x4a);
  this = *(RGE_Game_World **)(iVar5 + 0x3c);
  do {
    iVar5 = 0;
    if (0 < *(int *)((int)&DAT_0087d7d8 + iVar4)) {
      do {
        pRVar3 = RGE_Game_World::object
                           (this,*(int *)(*(int *)((int)&DAT_0087d7f0 + iVar4) + iVar5 * 8));
        if ((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar3->object_state < 3)) {
          (**(code **)(**(int **)(param_1[1] + 0xc) + 0xe8))(uVar2,(int)sVar1,0x20d,pRVar3->id,0,0);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)((int)&DAT_0087d7d8 + iVar4));
    }
    iVar4 = iVar4 + -4;
  } while (-8 < iVar4);
  param_1[0x42] = 0;
  iVar5 = debug_rand(s_C__msdev_work_age1_x1_aiuaimod_c,0xf92);
  param_1[0x43] = iVar5 % 1000 + 4000;
  return iVar5 / 1000;
}

// --------------------------------------------------

// Function: FUN_0041791e
// Address: 0041791e
undefined4 __thiscall FUN_0041791e(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x10) < 1) {
    return 0;
  }
  piVar2 = (int *)(*(int *)(param_1 + 0x18) + 4);
  do {
    if (*piVar2 == param_2) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 9;
  } while (iVar1 < *(int *)(param_1 + 0x10));
  return 0;
}

// --------------------------------------------------

// Function: FUN_00417955
// Address: 00417955
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00417955(UnitAIModule *param_1,int param_2)
{
  short sVar1;
  RGE_Player *pRVar2;
  RGE_Static_Object *pRVar3;
  RGE_Static_Object *this;
  UnitAIModule *pUVar4;
  int iVar5;
  float10 fVar6;
  float fVar7;
  int iStack_10;
  int iStack_c;
  
  pRVar3 = UnitAIModule::lookupObject(param_1,param_2);
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    (**(code **)(param_1->_padding_ + 0x20))();
    iStack_c = 0;
    do {
      iStack_10 = 0;
      if (0 < *(int *)((int)&DAT_0087d7cc + iStack_c)) {
        do {
          if (((((param_1->objectValue->id !=
                  *(int *)(iStack_10 * 8 + *(int *)((int)&DAT_0087d7e4 + iStack_c))) &&
                (this = UnitAIModule::lookupObject
                                  (param_1,*(int *)(iStack_10 * 8 +
                                                   *(int *)((int)&DAT_0087d7e4 + iStack_c))),
                this != (RGE_Static_Object *)0x0)) &&
               (pUVar4 = RGE_Static_Object::unitAI(this), pUVar4 != (UnitAIModule *)0x0)) &&
              (((pRVar2 = this->owner, pRVar2 != (RGE_Player *)0x0 && (this->object_state < 3)) &&
               ((sVar1 = this->master_obj->object_group, sVar1 != 1 &&
                ((sVar1 != 3 && (sVar1 != 4)))))))) &&
             ((sVar1 != 0x15 &&
              (((((sVar1 != 0x12 && (sVar1 != 0x14)) && (sVar1 != 0x1b)) &&
                ((sVar1 = param_1->objectValue->owner->id, pRVar2->id == sVar1 ||
                 (iVar5 = (**(code **)(pRVar2->_padding_ + 0x1c))((int)sVar1), iVar5 != 0)))) &&
               (fVar7 = RGE_Static_Object::distance_to_object(param_1->objectValue,this),
               fVar7 <= _DAT_0056ebec)))))) {
            pUVar4 = RGE_Static_Object::unitAI(this);
            iVar5 = UnitAIModule::currentAction(pUVar4);
            if (iVar5 == -1) {
              pUVar4 = RGE_Static_Object::unitAI(this);
              iVar5 = UnitAIModule::currentOrder(pUVar4);
              if (iVar5 == -1) {
                pUVar4 = RGE_Static_Object::unitAI(this);
                iVar5 = UnitAIModule::orderQueueSize(pUVar4);
                if (iVar5 < 1) {
                  pUVar4 = RGE_Static_Object::unitAI(this);
                  fVar7 = pRVar3->world_y;
                  iVar5 = pUVar4->_padding_;
                  fVar6 = (float10)(**(code **)(this->_padding_ + 0x10c))(1,0,0x32);
                  (**(code **)(iVar5 + 0x10))
                            ((int)this->owner->id,700,param_2,(int)pRVar3->owner->id,pRVar3->world_x
                             ,fVar7,fVar7,(float)fVar6);
                }
              }
            }
          }
          iStack_10 = iStack_10 + 1;
        } while (iStack_10 < *(int *)((int)&DAT_0087d7cc + iStack_c));
      }
      iStack_c = iStack_c + 4;
    } while (iStack_c < 5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00417b4d
// Address: 00417b4d
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
bool __thiscall FUN_00417b4d(UnitAIModule *param_1,int param_2,int param_3)
{
  AIPlay *pAVar1;
  AIPlayStatus *pAVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c90b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar8 = 0;
  switch(*(undefined4 *)(param_2 + 4)) {
  case 700:
    iVar8 = (**(code **)(param_1->_padding_ + 0x5c))(*(undefined4 *)(param_2 + 0xc),1);
    break;
  case 0x2bd:
    if (*(int *)(param_2 + 0xc) == -1) {
      iVar8 = (**(code **)(param_1->_padding_ + 0xb0))
                        (*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),
                         *(undefined4 *)(param_2 + 0x20),1);
    }
    else {
      iVar8 = (**(code **)(param_1->_padding_ + 0xac))
                        (*(int *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x20));
    }
    break;
  case 0x2be:
    iVar8 = (**(code **)(param_1->_padding_ + 0x78))(*(undefined4 *)(param_2 + 0xc),1);
    break;
  case 0x2bf:
    iVar8 = (**(code **)(param_1->_padding_ + 0x70))(*(undefined4 *)(param_2 + 0xc),1);
    break;
  case 0x2c0:
    iVar8 = (**(code **)(param_1->_padding_ + 0x6c))(*(undefined4 *)(param_2 + 0xc),1);
    break;
  case 0x2c1:
    iVar8 = param_1->_padding_;
    uVar5 = __ftol(1);
    uVar5 = __ftol(uVar5);
    iVar8 = (**(code **)(iVar8 + 0x80))(uVar5);
    break;
  case 0x2c2:
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar6 = -1;
      }
      else {
        lVar6 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar6,s_C__msdev_work_age1_x1_aiuaimod_c,
              0x105d);
      (**(code **)(param_1->_padding_ + 0x58))(1);
      iVar8 = 1;
      break;
    }
    goto LAB_00417eeb;
  case 0x2c5:
    iVar8 = (**(code **)(param_1->_padding_ + 0x68))(*(undefined4 *)(param_2 + 0xc),1);
    break;
  case 0x2c6:
    iVar8 = (**(code **)(param_1->_padding_ + 0x90))
                      (*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),
                       *(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x20),1);
    break;
  case 0x2c8:
    iVar8 = (**(code **)(param_1->_padding_ + 0xa8))
                      (*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x20),1);
    break;
  case 0x2c9:
    iVar8 = (**(code **)(param_1->_padding_ + 100))(*(undefined4 *)(param_2 + 0xc),1);
    break;
  case 0x2ca:
    iVar8 = (**(code **)(param_1->_padding_ + 0x8c))
                      (*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),
                       *(undefined4 *)(param_2 + 0x1c),1);
    break;
  case 0x2cd:
    iVar8 = (**(code **)(param_1->_padding_ + 0x84))(*(undefined4 *)(param_2 + 0xc),1);
    break;
  case 0x2ce:
    iVar8 = (**(code **)(param_1->_padding_ + 0x74))(*(undefined4 *)(param_2 + 0xc),1);
    break;
  case 0x2d1:
    iVar8 = (**(code **)(param_1->_padding_ + 0x88))
                      (1,*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18));
    break;
  case 0x2d2:
    iVar8 = param_1->_padding_;
    uVar5 = __ftol(1);
    uVar5 = __ftol(uVar5);
    iVar8 = (**(code **)(iVar8 + 0xb4))(*(undefined4 *)(param_2 + 0xc),uVar5);
    break;
  case 0x2d3:
    iVar8 = param_1->_padding_;
    uVar5 = __ftol(1);
    uVar5 = __ftol(uVar5);
    iVar8 = (**(code **)(iVar8 + 0xb8))(uVar5);
    break;
  case 0x2d4:
    iVar8 = (**(code **)(param_1->_padding_ + 0x90))
                      (*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),
                       *(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x20),1);
    break;
  case 0x2d5:
    UnitAIModule::removeCurrentTarget(param_1);
    if (actionFile != (_iobuf *)0x0) {
      if (param_1->objectValue == (RGE_Static_Object *)0x0) {
        lVar6 = -1;
      }
      else {
        lVar6 = param_1->objectValue->id;
      }
      fprintf(actionFile,s___d_call_stopObject__s__d_,lVar6,s_C__msdev_work_age1_x1_aiuaimod_c,
              0x10e9);
    }
LAB_00417eeb:
    (**(code **)(param_1->_padding_ + 0x58))(1);
LAB_00417ef4:
    iVar8 = 1;
    break;
  case 0x2d6:
    iVar8 = 1;
    pAVar1 = AIPlayBook::play(param_1->objectValue->owner->world->playbook,*(int *)(param_2 + 0x10))
    ;
    if (pAVar1 == (AIPlay *)0x0) {
      iVar8 = 0;
    }
    else {
      if (param_1->playStatus != (AIPlayStatus *)0x0) {
        operator_delete(param_1->playStatus);
      }
      pAVar2 = (AIPlayStatus *)operator_new(0x1c8);
      uStack_4 = 0;
      if (pAVar2 == (AIPlayStatus *)0x0) {
        pAVar2 = (AIPlayStatus *)0x0;
      }
      else {
        pAVar2 = (AIPlayStatus *)AIPlayStatus::AIPlayStatus(pAVar2);
      }
      param_1->playStatus = pAVar2;
      if (pAVar2 == (AIPlayStatus *)0x0) {
        iVar8 = 0;
      }
      else {
        pAVar2->playNumberValue = *(int *)(param_2 + 0x10);
        param_1->playStatus->targetValue = *(int *)(param_2 + 0xc);
        if (*(int *)(param_2 + 0x14) == -0x40800000) {
          iVar7 = __ftol();
          iVar3 = __ftol();
          iVar4 = __ftol();
          pAVar2 = param_1->playStatus;
          (pAVar2->originalPointValue).xValue = iVar4;
          (pAVar2->originalPointValue).yValue = iVar3;
          (pAVar2->originalPointValue).zValue = iVar7;
        }
        else {
          iVar7 = __ftol();
          iVar3 = __ftol();
          pAVar2 = param_1->playStatus;
          iVar4 = __ftol();
          (pAVar2->originalPointValue).xValue = iVar4;
          (pAVar2->originalPointValue).yValue = iVar3;
          (pAVar2->originalPointValue).zValue = iVar7;
        }
      }
    }
    break;
  case 0x2d7:
    if (param_1->playStatus != (AIPlayStatus *)0x0) {
      operator_delete(param_1->playStatus);
      param_1->playStatus = (AIPlayStatus *)0x0;
      iVar8 = 1;
      break;
    }
    goto LAB_00417ef4;
  case 0x2d8:
    iVar8 = 1;
    param_1->currentActionValue = 0x274;
    param_1->currentOrderValue = 0x2d8;
    break;
  case 0x2d9:
    iVar8 = (**(code **)(param_1->_padding_ + 0x60))(*(undefined4 *)(param_2 + 0xc));
  }
  if (iVar8 == 1) {
    iVar7 = *(int *)(param_2 + 4);
    if (iVar7 == 0x2c2) {
      iVar7 = -1;
      param_1->currentOrderValue = -1;
    }
    else {
      if (iVar7 == 0x2d9) {
        param_1->currentOrderValue = 700;
      }
      else if ((iVar7 == 700) && (param_1->objectValue->master_obj->id == 0x7d)) {
        param_1->currentOrderValue = -1;
        param_1->currentTargetValue = -1;
      }
      else {
        param_1->currentOrderValue = iVar7;
      }
      iVar7 = *(int *)(param_2 + 8);
    }
    param_1->currentOrderPriorityValue = iVar7;
  }
  if (((-1 < param_3) && (param_3 < param_1->orderQueueSizeValue)) &&
     (param_1->orderQueueValue != (OrderEvent *)0x0)) {
    if (param_3 < param_1->orderQueueSizeValue + -1) {
      iVar7 = param_3 * 0x24;
      do {
        *(undefined4 *)((int)&param_1->orderQueueValue->issuer + iVar7) =
             *(undefined4 *)((int)&param_1->orderQueueValue[1].issuer + iVar7);
        *(undefined4 *)((int)&param_1->orderQueueValue->orderType + iVar7) =
             *(undefined4 *)((int)&param_1->orderQueueValue[1].orderType + iVar7);
        *(undefined4 *)((int)&param_1->orderQueueValue->priority + iVar7) =
             *(undefined4 *)((int)&param_1->orderQueueValue[1].priority + iVar7);
        *(undefined4 *)((int)&param_1->orderQueueValue->target + iVar7) =
             *(undefined4 *)((int)&param_1->orderQueueValue[1].target + iVar7);
        *(undefined4 *)((int)&param_1->orderQueueValue->targetOwner + iVar7) =
             *(undefined4 *)((int)&param_1->orderQueueValue[1].targetOwner + iVar7);
        *(undefined4 *)((int)&param_1->orderQueueValue->targetX + iVar7) =
             *(undefined4 *)((int)&param_1->orderQueueValue[1].targetX + iVar7);
        *(undefined4 *)((int)&param_1->orderQueueValue->targetY + iVar7) =
             *(undefined4 *)((int)&param_1->orderQueueValue[1].targetY + iVar7);
        param_3 = param_3 + 1;
        *(undefined4 *)((int)&param_1->orderQueueValue->targetZ + iVar7) =
             *(undefined4 *)((int)&param_1->orderQueueValue[1].targetZ + iVar7);
        iVar7 = iVar7 + 0x24;
      } while (param_3 < param_1->orderQueueSizeValue + -1);
    }
    param_1->orderQueueSizeValue = param_1->orderQueueSizeValue + -1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return iVar8 == 1;
}

// --------------------------------------------------

// Function: FUN_00418045
// Address: 00418045
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Instruction at (ram,0x004180fe) overlaps instruction at (ram,0x004180fd)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall
FUN_00418045(char *param_1,char *param_2,UnitAIModule *param_3,code *param_4,ulong param_5,
            undefined4 param_6,undefined4 param_7,undefined4 *param_8,float param_9,int *param_10)
{
  undefined1 *puVar1;
  byte *pbVar2;
  char *pcVar3;
  byte bVar4;
  byte bVar5;
  short sVar6;
  float fVar7;
  byte bVar8;
  uint in_EAX;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  RGE_Static_Object *pRVar14;
  long lVar15;
  char cVar16;
  char cVar18;
  byte bVar19;
  char *pcVar17;
  char cVar20;
  char cVar21;
  char cVar22;
  char cVar24;
  int unaff_EBX;
  int iVar23;
  int *unaff_EBP;
  RGE_Static_Object *pRVar25;
  UnitAIModule *unaff_ESI;
  UnitAIModule *this;
  uint *unaff_EDI;
  uint *puVar26;
  bool bVar27;
  bool bVar28;
  float10 fVar29;
  float unaff_retaddr;
  RGE_Static_Object *pRVar30;
  
  iVar23 = unaff_EBX + 1;
  bVar8 = (byte)in_EAX;
  puVar26 = unaff_EDI;
  if (SCARRY4(unaff_EBX,1) == iVar23 < 0) {
code_r0x00418083:
    pcVar17 = (char *)((int)unaff_EDI * 3 + 0x41);
    cVar24 = (char)param_1;
    *pcVar17 = *pcVar17 + cVar24;
    pcVar17 = (char *)((int)unaff_EDI * 3 + 0x41);
    *pcVar17 = *pcVar17 + cVar24;
    pbVar2 = (byte *)(in_EAX + 0x9c00417e);
    bVar28 = CARRY1(*pbVar2,bVar8);
    bVar4 = *pbVar2;
    *pbVar2 = *pbVar2 + bVar8;
    if (SCARRY1(bVar4,bVar8) == (char)*pbVar2 < '\0') {
      iRam000000c7 = iRam000000c7 + 1;
      bVar27 = iRam000000c7 == 0;
      param_10 = unaff_EBP;
      this = unaff_ESI;
    }
    else {
      pcVar17 = (char *)((int)unaff_EDI * 3 + 0x41);
      *pcVar17 = *pcVar17 + cVar24;
      pcVar17 = (char *)((int)unaff_EDI * 3 + 0x41);
      *pcVar17 = *pcVar17 + cVar24;
      pcVar17 = param_1;
      iVar10 = iVar23;
code_r0x0041809b:
      pcVar3 = (char *)((int)&unaff_ESI[-0x2f6034].objectCategoryValue + 1);
      cVar24 = (char)((uint)pcVar17 >> 8);
      bVar28 = SCARRY1(*pcVar3,cVar24);
      *pcVar3 = *pcVar3 + cVar24;
      cVar24 = *pcVar3;
code_r0x004180a1:
      if (bVar28 == cVar24 < '\0') {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
code_r0x004180a3:
      cVar24 = (char)((uint)pcVar17 >> 8);
      cVar22 = (char)((uint)param_2 >> 8);
      cVar21 = cVar22 + cVar24;
      param_2 = (char *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(cVar21,(char)param_2));
      if (SCARRY1(cVar22,cVar24) == cVar21 < '\0') goto switchD_004180e8_switchD;
      puVar1 = &unaff_ESI->waypointQueue[0].field_0xe;
      *puVar1 = *puVar1 + bVar8;
      pcVar3 = param_2 + -0x73ffbe82;
      *pcVar3 = *pcVar3 + cVar21;
      param_1 = pcVar17 + 1;
      if ((POPCOUNT(*pcVar3) & 1U) != 0) goto code_r0x004180f8;
code_r0x004180b3:
      pbVar2 = (byte *)(iVar10 + 0x1900417c);
      bVar4 = *pbVar2;
      bVar19 = (byte)((uint)param_1 >> 8);
      bVar5 = *pbVar2;
      *pbVar2 = *pbVar2 + bVar19;
      if (*pbVar2 != 0 && SCARRY1(bVar5,bVar19) == (char)*pbVar2 < '\0') {
        *(char *)((int)unaff_EBP + -0x74c4803f) =
             *(char *)((int)unaff_EBP + -0x74c4803f) + bVar8 + CARRY1(bVar4,bVar19);
        unaff_ESI = (UnitAIModule *)((int)&unaff_ESI->_padding_ + 1);
        pRVar14 = (RGE_Static_Object *)CONCAT31((int3)(in_EAX >> 8),bVar8 + 0x8b);
        goto code_r0x00418108;
      }
code_r0x004180bb:
      *(char *)((int)unaff_EBP + 0x7d) = *(char *)((int)unaff_EBP + 0x7d) + (char)param_2;
      *(char *)(iVar10 + 0x55530cec) = *(char *)(iVar10 + 0x55530cec) + bVar8;
      in_EAX = param_10[2] - 500;
      bVar28 = in_EAX < 199;
      bVar27 = in_EAX == 199;
      this = (UnitAIModule *)(param_1 + 1);
      param_3 = unaff_ESI;
    }
    if (!bVar28 && !bVar27) {
      UnitAIModule::removeCurrentTarget(this);
      if (actionFile != (_iobuf *)0x0) {
        if (this->objectValue == (RGE_Static_Object *)0x0) {
          lVar15 = -1;
        }
        else {
          lVar15 = this->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar15,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x1439);
      }
      iVar23 = this->_padding_;
      (**(code **)(iVar23 + 0x58))(1);
      (**(code **)(iVar23 + 0x1c))(param_10);
      return 2;
    }
  }
  else {
    cVar21 = (char)(in_EAX >> 8);
    *(char *)((int)unaff_EBP + 0x7d) = *(char *)((int)unaff_EBP + 0x7d) + cVar21;
    pcVar17 = (char *)((int)&((UnitAIModule *)(unaff_ESI->waypointQueue + -7))->_padding_ +
                      (int)unaff_EDI * 2);
    *pcVar17 = *pcVar17 + (char)((uint)param_2 >> 8);
    pcVar17 = param_1 + 2;
    cVar24 = (char)((uint)iVar23 >> 8);
    cVar22 = (char)iVar23 + cVar24;
    iVar10 = CONCAT31((int3)((uint)iVar23 >> 8),cVar22);
    if (cVar22 != '\0' && SCARRY1((char)iVar23,cVar24) == cVar22 < '\0') {
      cVar18 = *param_2;
      cVar16 = (char)pcVar17;
      *param_2 = *param_2 + cVar16;
      if (*param_2 != '\0' && SCARRY1(cVar18,cVar16) == *param_2 < '\0') {
        puVar26 = (uint *)((int)unaff_EDI + 1);
        if ((char)*unaff_EDI <= (char)bVar8) goto code_r0x004180e0;
        bVar28 = SCARRY1(cVar24,bVar8);
        cVar24 = cVar24 + bVar8;
        iVar10 = CONCAT22((short)((uint)iVar23 >> 0x10),CONCAT11(cVar24,cVar22));
        goto code_r0x004180a1;
      }
      cVar18 = *pcVar17;
      cVar20 = (char)param_2;
      *pcVar17 = *pcVar17 + cVar20;
      if (*pcVar17 == '\0' || SCARRY1(cVar18,cVar20) != *pcVar17 < '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      param_2 = (char *)CONCAT31((int3)((uint)param_2 >> 8),cVar20 * '\x02');
      if (SCARRY1(cVar20,cVar20) != (char)(cVar20 * '\x02') < '\0') {
        out((short)param_2,bVar8);
        goto code_r0x004180a3;
      }
      pcVar3 = (char *)((int)unaff_EDI * 3 + 0x41);
      *pcVar3 = *pcVar3 + cVar16;
      pcVar3 = (char *)((int)unaff_EDI * 3 + 0x41);
      *pcVar3 = *pcVar3 + cVar16;
      iVar23 = unaff_ESI->_padding_;
      cVar18 = (char)((uint)pcVar17 >> 8);
      *(char *)&unaff_ESI->_padding_ = (char)unaff_ESI->_padding_ + cVar18;
      if ((char)unaff_ESI->_padding_ != '\0' &&
          SCARRY1((char)iVar23,cVar18) == (char)unaff_ESI->_padding_ < '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      cVar18 = *param_2;
      *param_2 = *param_2 + cVar21;
      cVar20 = *param_2;
      if (SCARRY1(cVar18,cVar21) != cVar20 < '\0') {
        pcVar17 = (char *)((int)unaff_EDI * 3 + 0x41);
        *pcVar17 = *pcVar17 + cVar16;
        *(char *)((int)unaff_EDI + 0x7e) = *(char *)((int)unaff_EDI + 0x7e) + cVar21;
        param_1 = param_1 + 3;
        bVar28 = SCARRY1(cRam9500417f,cVar24);
        cRam9500417f = cRam9500417f + cVar24;
        iVar23 = iVar10;
        if (cRam9500417f != '\0' && bVar28 == cRam9500417f < '\0') goto code_r0x00418083;
        goto code_r0x004180bb;
      }
      puVar26 = unaff_EDI + 1;
      *unaff_EDI = in_EAX;
      if (SCARRY1(cVar18,cVar21) == cVar20 < '\0') {
        *pcVar17 = *pcVar17 + cVar22;
        param_1 = pcVar17;
        goto code_r0x004180b3;
      }
code_r0x004180f8:
      (**(code **)(in_EAX + 0x1c))();
      if (unaff_EBP[4] < 1) {
        pRVar14 = unaff_ESI->objectValue;
        puVar26 = (uint *)*unaff_EBP;
code_r0x00418108:
        (**(code **)(pRVar14->owner->_padding_ + 0xe8))(pRVar14->id,pRVar14->id,0x209,puVar26,0,0);
        UnitAIModule::purgeNotifyQueue(unaff_ESI,param_5);
        return 4;
      }
      if (((unaff_ESI->attackingUnitsValue).numberValue == 0) ||
         (iVar23 = RGE_Player::computerPlayer(unaff_ESI->objectValue->owner), iVar23 == 1)) {
        lVar15 = unaff_ESI->objectValue->id;
        (**(code **)(unaff_ESI->objectValue->owner->_padding_ + 0xe8))
                  (lVar15,lVar15,0x201,*unaff_EBP,0,0);
      }
      iVar23 = (unaff_ESI->attackingUnitsValue).numberValue;
      iVar10 = 0;
      if (0 < iVar23) {
        do {
          if ((unaff_ESI->attackingUnitsValue).maximumSizeValue <= iVar10) break;
          if ((unaff_ESI->attackingUnitsValue).value[iVar10] == *unaff_EBP) goto LAB_004181b7;
          iVar10 = iVar10 + 1;
        } while (iVar10 < iVar23);
      }
      iVar23 = RGE_Player::computerPlayer(unaff_ESI->objectValue->owner);
      if ((iVar23 == 0) && (unaff_ESI->currentTargetValue != *unaff_EBP)) {
        UnitAIModule::askForHelp(unaff_ESI,*unaff_EBP);
      }
LAB_004181b7:
      iVar23 = (unaff_ESI->attackingUnitsValue).numberValue;
      iVar10 = *unaff_EBP;
      iVar11 = 0;
      if (0 < iVar23) {
        do {
          if ((unaff_ESI->attackingUnitsValue).maximumSizeValue <= iVar11) break;
          if ((unaff_ESI->attackingUnitsValue).value[iVar11] == iVar10) goto LAB_0041823e;
          iVar11 = iVar11 + 1;
        } while (iVar11 < iVar23);
      }
      if ((unaff_ESI->attackingUnitsValue).maximumSizeValue + -1 < iVar23) {
        iVar23 = iVar23 + 1;
        piVar12 = (int *)operator_new(iVar23 * 4);
        unaff_EBP = param_10;
        if (piVar12 != (int *)0x0) {
          iVar11 = 0;
          if (0 < (unaff_ESI->attackingUnitsValue).maximumSizeValue) {
            do {
              if (iVar23 <= iVar11) break;
              iVar13 = iVar11 + 1;
              piVar12[iVar11] = (unaff_ESI->attackingUnitsValue).value[iVar11];
              iVar11 = iVar13;
            } while (iVar13 < (unaff_ESI->attackingUnitsValue).maximumSizeValue);
          }
          operator_delete((unaff_ESI->attackingUnitsValue).value);
          (unaff_ESI->attackingUnitsValue).value = piVar12;
          (unaff_ESI->attackingUnitsValue).maximumSizeValue = iVar23;
        }
      }
      (unaff_ESI->attackingUnitsValue).value[(unaff_ESI->attackingUnitsValue).numberValue] = iVar10;
      (unaff_ESI->attackingUnitsValue).numberValue =
           (unaff_ESI->attackingUnitsValue).numberValue + 1;
LAB_0041823e:
      (**(code **)(unaff_ESI->objectValue->_padding_ + 0xec))(1);
      if (((unaff_ESI->currentOrderValue != 0x2d5) && (unaff_ESI->currentOrderValue != -1)) &&
         (iVar23 = RGE_Player::computerPlayer(unaff_ESI->objectValue->owner), iVar23 == 0)) {
        return 2;
      }
      if (unaff_ESI->currentOrderValue == 0x2d5) {
        return 2;
      }
      pRVar14 = UnitAIModule::lookupObject(unaff_ESI,*unaff_EBP);
      if (pRVar14 == (RGE_Static_Object *)0x0) {
        return 2;
      }
      if (pRVar14->owner->id == unaff_ESI->objectValue->owner->id) {
        return 2;
      }
      if ((unaff_ESI->currentActionValue == 0x25b) &&
         (iVar23 = (**(code **)(param_5 + 0xa4))(1), iVar23 == 1)) {
        return 3;
      }
      pRVar25 = (RGE_Static_Object *)0x0;
      if (unaff_ESI->currentTargetValue != -1) {
        pRVar25 = UnitAIModule::lookupObject(unaff_ESI,unaff_ESI->currentTargetValue);
      }
      if (pRVar25 != (RGE_Static_Object *)0x0) {
        sVar6 = pRVar25->master_obj->object_group;
        if (((sVar6 == 3) || (sVar6 == 0x1b)) &&
           ((sVar6 = pRVar25->master_obj->id, sVar6 != 0x4f &&
            (((sVar6 != 199 && (sVar6 != 0x45)) &&
             (iVar23 = RGE_Player::computerPlayer(unaff_ESI->objectValue->owner), iVar23 == 0))))))
{
          iVar23 = (**(code **)(param_5 + 0x50))(pRVar14);
          if (iVar23 != 1) {
LAB_0041844c:
            (**(code **)(param_5 + 0xa4))(1);
            return 3;
          }
          iVar23 = (**(code **)(unaff_ESI->objectValue->_padding_ + 0xe4))(pRVar14);
          if (iVar23 != 1) {
            iVar23 = unaff_ESI->objectValue->_padding_;
            fVar29 = (float10)(**(code **)(iVar23 + 0x10c))(0,0,0xffffffff,0xffffffff);
            iVar23 = (**(code **)(iVar23 + 0x194))(*param_8,(float)fVar29);
            if (iVar23 != 1) goto LAB_0041844c;
          }
          (**(code **)(param_5 + 0x5c))(*param_8,1);
          return 3;
        }
        iVar23 = RGE_Player::computerPlayer(unaff_ESI->objectValue->owner);
        if (iVar23 != 1) {
          return 2;
        }
        if (pRVar25->master_obj->id == 0x114) {
          return 2;
        }
        fVar7 = (float)pRVar25->_padding_;
        fVar29 = (float10)(**(code **)((int)fVar7 + 0x108))();
        if (fVar29 != (float10)_DAT_0056ebc8) {
          (**(code **)(unaff_ESI->objectValue->_padding_ + 0x104))(pRVar25);
        }
        pRVar30 = pRVar14;
        iVar23 = (**(code **)(param_5 + 0x50))();
        if ((iVar23 == 1) && (param_9 == _DAT_0056ebc8)) {
          iVar23 = (**(code **)(unaff_ESI->objectValue->_padding_ + 0xe4))(pRVar14);
          if (iVar23 != 1) {
            iVar23 = unaff_ESI->objectValue->_padding_;
            fVar29 = (float10)(**(code **)(iVar23 + 0x10c))(0,0,0xffffffff,0xffffffff);
            iVar23 = (**(code **)(iVar23 + 0x194))(*param_8,(float)fVar29);
            if (iVar23 != 1) goto LAB_00418533;
          }
          (**(code **)((int)param_4 + 0x5c))(*param_8,1);
        }
LAB_00418533:
        fVar29 = (float10)(**(code **)(param_5 + 0x104))(unaff_ESI->objectValue);
        if (fVar29 <= (float10)_DAT_0056ebc8) {
          param_4 = (code *)0x46c35000;
        }
        else {
          param_4 = (code *)(float)((float10)pRVar25->hp / fVar29);
        }
        (**(code **)(pRVar14->_padding_ + 0x104))(unaff_ESI->objectValue);
        iVar23 = (*param_4)(pRVar14);
        if (iVar23 != 1) {
          return 2;
        }
        if (unaff_retaddr <= fVar7) {
          return 2;
        }
        iVar23 = (**(code **)(unaff_ESI->objectValue->_padding_ + 0xe4))(pRVar14);
        if (iVar23 != 1) {
          iVar23 = unaff_ESI->objectValue->_padding_;
          fVar29 = (float10)(**(code **)(iVar23 + 0x10c))(0,0,0xffffffff,0xffffffff);
          iVar23 = (**(code **)(iVar23 + 0x194))(*(undefined4 *)param_4,(float)fVar29);
          if (iVar23 != 1) {
            return 2;
          }
        }
        (*(code *)(pRVar30->pathingGroupMembers).desiredNumberValue)(*(undefined4 *)param_4,1);
        return 2;
      }
      iVar23 = (**(code **)(param_5 + 0x50))(pRVar14);
      if (iVar23 == 1) {
        iVar23 = (**(code **)(unaff_ESI->objectValue->_padding_ + 0xe4))(pRVar14);
        if (iVar23 != 1) {
          iVar23 = unaff_ESI->objectValue->_padding_;
          fVar29 = (float10)(**(code **)(iVar23 + 0x10c))(0,0,0xffffffff,0xffffffff);
          iVar23 = (**(code **)(iVar23 + 0x194))(*param_8,(float)fVar29);
          if (iVar23 != 1) goto LAB_00418371;
        }
        iVar23 = (**(code **)(param_5 + 0x5c))(*param_8,1);
        if ((iVar23 == 1) && (unaff_ESI->currentOrderValue != 700)) {
          unaff_ESI->currentOrderValue = -1;
          return 3;
        }
      }
      else {
LAB_00418371:
        if (unaff_ESI->currentActionValue != 0x262) {
          (**(code **)(param_5 + 0xa4))(1);
          return 3;
        }
      }
      return 3;
    }
    if ((int)&stack0x00000000 < 2) goto code_r0x0041809b;
  }
code_r0x004180e0:
  pcVar17 = (char *)(uint)(&switchD_004180e8::switchdataD_0041943c)[in_EAX];
switchD_004180e8_switchD:
                    /* WARNING: Could not recover jumptable at 0x004180e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar9 = (*(code *)(&switchD_004180e8::switchdataD_004193f4)[(int)pcVar17])();
  return uVar9;
}

// --------------------------------------------------

// Function: FUN_004195e1
// Address: 004195e1
undefined4 __thiscall FUN_004195e1(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  if ((param_2 == 1) && (iVar1 = (**(code **)(*param_1 + 0xdc))(), iVar1 == 8)) {
    return 6;
  }
  iVar1 = *param_1;
  iVar2 = (**(code **)(iVar1 + 0x30))(1,0,0);
  if ((iVar2 != -1) && (iVar1 = (**(code **)(iVar1 + 0x5c))(iVar2,1), iVar1 == 1)) {
    return 6;
  }
  return 5;
}

// --------------------------------------------------

// Function: FUN_00419642
// Address: 00419642
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00419642(UnitAIModule *param_1)
{
  short sVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  UnitAIModule *pUVar8;
  int iVar9;
  RGE_Static_Object *pRVar10;
  int unaff_ESI;
  float10 fVar11;
  float fVar12;
  float fStack_4;
  
  iVar4 = param_1->currentOrderValue;
  if (iVar4 == -1) {
    if (param_1->currentActionValue == -1) {
      iVar4 = -1;
    }
    else {
      iVar4 = param_1->currentActionValue + 100;
    }
  }
  if (iVar4 == 700) {
    if ((((taskedThisUpdate != 1) &&
         (iVar4 = RGE_Player::computerPlayer(param_1->objectValue->owner), iVar4 != 0)) &&
        (cVar3 = (**(code **)(param_1->objectValue->_padding_ + 0x7c))(), cVar3 != '\0')) &&
       ((pRVar10 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue),
        pRVar10 == (RGE_Static_Object *)0x0 || (pRVar10->master_obj->id != 0x114)))) {
      iVar4 = param_1->_padding_;
      iVar9 = (**(code **)(iVar4 + 0x30))(0,0,0);
      pRVar10 = UnitAIModule::lookupObject(param_1,iVar9);
      if ((iVar9 != -1) &&
         ((pRVar10 != (RGE_Static_Object *)0x0 && (iVar9 != param_1->currentTargetValue)))) {
        sVar1 = pRVar10->master_obj->object_group;
        if ((sVar1 == 3) || (sVar1 == 0x1b)) {
          if (pRVar10->master_obj->id == 0x114) {
            fVar11 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0x10c))
                                        (1,0,param_1->currentOrderPriorityValue);
            (**(code **)(iVar4 + 0x10))
                      (param_1->objectValue->id,700,iVar9,(int)pRVar10->owner->id,pRVar10->world_x,
                       pRVar10->world_y,pRVar10->world_z,(float)fVar11);
          }
        }
        else if (((unaff_ESI == 0) ||
                 (sVar1 = *(short *)(*(int *)(unaff_ESI + 8) + 0x14), sVar1 == 3)) ||
                (sVar1 == 0x1b)) {
          fVar11 = (float10)(**(code **)(param_1->objectValue->_padding_ + 0x10c))
                                      (1,0,param_1->currentOrderPriorityValue);
          (**(code **)(iVar4 + 0x10))
                    (param_1->objectValue->id,700,iVar9,(int)pRVar10->owner->id,pRVar10->world_x,
                     pRVar10->world_y,pRVar10->world_z,(float)fVar11);
          return 9;
        }
      }
    }
  }
  else if (iVar4 == 0x2bd) {
    pRVar10 = (RGE_Static_Object *)0x0;
    if (param_1->defendTargetValue != -1) {
      pRVar10 = UnitAIModule::lookupObject(param_1,param_1->defendTargetValue);
      if (pRVar10 == (RGE_Static_Object *)0x0) {
        param_1->defendTargetValue = -1;
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar5 = -1;
          }
          else {
            lVar5 = param_1->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar5,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x15c0);
        }
        (**(code **)(param_1->_padding_ + 0x58))(1);
        param_1->currentOrderValue = -1;
        return 9;
      }
      if (param_1->currentTargetXValue == -1.0) {
        param_1->currentTargetXValue = pRVar10->world_x;
        param_1->currentTargetYValue = pRVar10->world_y;
      }
      if ((2 < pRVar10->object_state) && (pRVar10->owner->id != 0)) {
        param_1->defendTargetValue = -1;
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar5 = -1;
          }
          else {
            lVar5 = param_1->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar5,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x15d9);
        }
        goto LAB_004198c8;
      }
    }
    if ((param_1->currentActionValue != 600) &&
       ((param_1->currentActionValue != 0x262 ||
        (iVar4 = (**(code **)(param_1->objectValue->_padding_ + 0x11c))(),
        iVar4 != param_1->defendTargetValue)))) {
      if (param_1->defendTargetValue == -1) {
        fVar12 = RGE_Static_Object::distance_to_position
                           (param_1->objectValue,param_1->currentTargetXValue,
                            param_1->currentTargetYValue,param_1->objectValue->world_z);
      }
      else {
        param_1->currentTargetXValue = pRVar10->world_x;
        param_1->currentTargetYValue = pRVar10->world_y;
        param_1->currentTargetZValue = pRVar10->world_z;
        fVar12 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar10);
      }
      fVar2 = param_1->desiredTargetDistanceValue;
      if (fVar2 - _DAT_0056ebd4 < fVar12) {
        if (param_1->defendTargetValue == -1) {
          uVar6 = __ftol();
          uVar7 = __ftol();
          iVar4 = (**(code **)(param_1->objectValue->_padding_ + 0x198))
                            (uVar6,uVar7,0xffffffff,fVar2,0xffffffff,0,0,0xffffffff,0xffffffff);
          if (iVar4 == 1) {
            (**(code **)(param_1->_padding_ + 0x90))
                      (param_1->currentTargetXValue,param_1->currentTargetYValue,
                       param_1->currentTargetZValue,param_1->desiredTargetDistanceValue,1);
            return 10;
          }
        }
        else {
          iVar4 = (**(code **)(param_1->objectValue->_padding_ + 0x194))
                            (param_1->defendTargetValue,fVar2,0,0,0xffffffff,0xffffffff);
          if (iVar4 == 1) {
            (**(code **)(param_1->_padding_ + 0x94))
                      (param_1->defendTargetValue,param_1->desiredTargetDistanceValue,1);
            return 10;
          }
        }
        return 10;
      }
      if ((pRVar10 != (RGE_Static_Object *)0x0) &&
         (pUVar8 = RGE_Static_Object::unitAI(pRVar10), pUVar8 != (UnitAIModule *)0x0)) {
        pUVar8 = RGE_Static_Object::unitAI(pRVar10);
        iVar4 = (**(code **)(pUVar8->_padding_ + 0x3c))(0);
        if (iVar4 != -1) {
          (**(code **)(param_1->_padding_ + 0x5c))(iVar4,1);
          return 10;
        }
        iVar4 = (**(code **)(param_1->_padding_ + 0xd4))(0);
        if (iVar4 == 6) {
          return 10;
        }
      }
    }
  }
  else if (iVar4 == 0x2c8) {
    pRVar10 = (RGE_Static_Object *)0x0;
    if ((param_1->currentTargetValue != -1) &&
       ((pRVar10 = UnitAIModule::lookupObject(param_1,param_1->currentTargetValue),
        pRVar10 == (RGE_Static_Object *)0x0 || (2 < pRVar10->object_state)))) {
      param_1->defendTargetValue = -1;
      UnitAIModule::removeCurrentTarget(param_1);
      if (actionFile != (_iobuf *)0x0) {
        if (param_1->objectValue == (RGE_Static_Object *)0x0) {
          lVar5 = -1;
        }
        else {
          lVar5 = param_1->objectValue->id;
        }
        fprintf(actionFile,s___d_call_stopObject__s__d_,lVar5,s_C__msdev_work_age1_x1_aiuaimod_c,
                0x1582);
        (**(code **)(param_1->_padding_ + 0x58))(1);
        param_1->currentOrderValue = -1;
        return 9;
      }
LAB_004198c8:
      (**(code **)(param_1->_padding_ + 0x58))(1);
      param_1->currentOrderValue = -1;
      return 9;
    }
    if (pRVar10 == (RGE_Static_Object *)0x0) {
      fStack_4 = -10.0;
      fVar12 = _DAT_0056ebf8;
    }
    else {
      fStack_4 = pRVar10->world_y - param_1->currentTargetYValue;
      fVar12 = pRVar10->world_x - param_1->currentTargetXValue;
    }
    if ((((fVar12 < (float)_DAT_0056ec00) || ((float)_DAT_0056ec08 < fVar12)) ||
        (fStack_4 < (float)_DAT_0056ec00)) || ((float)_DAT_0056ec08 < fStack_4)) {
      if (param_1->currentTargetValue == -1) {
        fVar12 = RGE_Static_Object::distance_to_position
                           (param_1->objectValue,param_1->currentTargetXValue,
                            param_1->currentTargetYValue,param_1->objectValue->world_z);
      }
      else {
        param_1->currentTargetXValue = pRVar10->world_x;
        param_1->currentTargetYValue = pRVar10->world_y;
        param_1->currentTargetZValue = pRVar10->world_z;
        fVar12 = RGE_Static_Object::distance_to_object(param_1->objectValue,pRVar10);
      }
      fVar2 = param_1->desiredTargetDistanceValue;
      if (fVar2 < fVar12) {
        if (param_1->currentTargetValue == -1) {
          (**(code **)(param_1->_padding_ + 0x90))
                    (param_1->currentTargetXValue,param_1->currentTargetYValue,
                     param_1->currentTargetZValue,fVar2,1);
          return 10;
        }
        (**(code **)(param_1->_padding_ + 0x94))(param_1->currentTargetValue,fVar2);
        return 10;
      }
    }
  }
  return 9;
}

// --------------------------------------------------

// Function: FUN_00419bb7
// Address: 00419bb7
int __fastcall FUN_00419bb7(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = (**(code **)(iVar2 + 0x28))(param_1[0x14]);
  if (iVar1 == 1) {
    iVar1 = (**(code **)(iVar2 + 0x40))(param_1[0x17],0xffffffff,0xffffffff,0xffffffff,0);
    if (iVar1 != -1) {
      if (param_1[0x14] == 0x2c5) {
        iVar2 = (**(code **)(iVar2 + 0x68))(iVar1,0);
        return 8 - (uint)(iVar2 != 1);
      }
      if (param_1[0x14] == 0x2c9) {
        iVar2 = (**(code **)(iVar2 + 100))(iVar1,0);
        return 8 - (uint)(iVar2 != 1);
      }
    }
  }
  return 7;
}

// --------------------------------------------------

// Function: FUN_00419c26
// Address: 00419c26
void __thiscall FUN_00419c26(UnitAIModule *param_1,int *param_2,int param_3)
{
  UnitAIModule::addToOrderQueue
            (param_1,*param_2,param_2[1],param_2[3],param_2[4],(float)param_2[5],(float)param_2[6],
             (float)param_2[7],(float)param_2[8],param_3,param_2[2]);
  return;
}

// --------------------------------------------------

// Function: FUN_00419c64
// Address: 00419c64
undefined4 __thiscall
FUN_00419c64(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            int param_10,undefined4 param_11)
{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x14) == *(int *)(param_1 + 0x10)) {
    pvVar1 = operator_new(*(int *)(param_1 + 0x14) * 0x48);
    if (pvVar1 == (void *)0x0) {
      return 0;
    }
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x10)) {
      iVar2 = 0;
      puVar3 = (undefined4 *)((int)pvVar1 + 8);
      do {
        iVar5 = iVar5 + 1;
        puVar3[-2] = *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x18));
        puVar3[-1] = *(undefined4 *)(iVar2 + 4 + *(int *)(param_1 + 0x18));
        *puVar3 = *(undefined4 *)(iVar2 + 8 + *(int *)(param_1 + 0x18));
        puVar3[1] = *(undefined4 *)(iVar2 + 0xc + *(int *)(param_1 + 0x18));
        puVar3[2] = *(undefined4 *)(iVar2 + 0x10 + *(int *)(param_1 + 0x18));
        puVar3[3] = *(undefined4 *)(iVar2 + 0x14 + *(int *)(param_1 + 0x18));
        puVar3[4] = *(undefined4 *)(iVar2 + 0x18 + *(int *)(param_1 + 0x18));
        puVar3[5] = *(undefined4 *)(iVar2 + 0x1c + *(int *)(param_1 + 0x18));
        puVar3[6] = *(undefined4 *)(iVar2 + 0x20 + *(int *)(param_1 + 0x18));
        iVar2 = iVar2 + 0x24;
        puVar3 = puVar3 + 9;
      } while (iVar5 < *(int *)(param_1 + 0x10));
    }
    if (*(void **)(param_1 + 0x18) != (void *)0x0) {
      operator_delete(*(void **)(param_1 + 0x18));
    }
    *(void **)(param_1 + 0x18) = pvVar1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) << 1;
  }
  if ((param_10 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x10)) {
      iVar2 = 0;
      do {
        *(undefined4 *)(iVar2 + 0x24 + *(int *)(param_1 + 0x18)) =
             *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x18));
        iVar4 = *(int *)(param_1 + 0x18) + iVar2;
        *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(iVar4 + 4);
        iVar4 = *(int *)(param_1 + 0x18) + iVar2;
        *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 8);
        iVar4 = *(int *)(param_1 + 0x18) + iVar2;
        *(undefined4 *)(iVar4 + 0x30) = *(undefined4 *)(iVar4 + 0xc);
        iVar4 = *(int *)(param_1 + 0x18) + iVar2;
        *(undefined4 *)(iVar4 + 0x34) = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = *(int *)(param_1 + 0x18) + iVar2;
        *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)(iVar4 + 0x14);
        iVar4 = *(int *)(param_1 + 0x18) + iVar2;
        *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(iVar4 + 0x18);
        iVar4 = *(int *)(param_1 + 0x18) + iVar2;
        *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(iVar4 + 0x1c);
        iVar4 = *(int *)(param_1 + 0x18) + iVar2;
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 0x24;
        *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(iVar4 + 0x20);
      } while (iVar5 < *(int *)(param_1 + 0x10));
    }
    **(undefined4 **)(param_1 + 0x18) = param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = param_3;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 8) = param_11;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xc) = param_4;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10) = param_5;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x14) = param_6;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x18) = param_7;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x1c) = param_8;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x20) = param_9;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    return 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x10) * 0x24) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 4 + *(int *)(param_1 + 0x10) * 0x24) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 8 + *(int *)(param_1 + 0x10) * 0x24) = param_11;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xc + *(int *)(param_1 + 0x10) * 0x24) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10 + *(int *)(param_1 + 0x10) * 0x24) = param_5;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x14 + *(int *)(param_1 + 0x10) * 0x24) = param_6;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x18 + *(int *)(param_1 + 0x10) * 0x24) = param_7;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x1c + *(int *)(param_1 + 0x10) * 0x24) = param_8;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x20 + *(int *)(param_1 + 0x10) * 0x24) = param_9;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00419ecf
// Address: 00419ecf
void __thiscall FUN_00419ecf(UnitAIModule *param_1,int *param_2)
{
  UnitAIModule::addToNotifyQueue
            (param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5]);
  return;
}

// --------------------------------------------------

// Function: FUN_00419ef3
// Address: 00419ef3
undefined4 __thiscall
FUN_00419ef3(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)
{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x1c)) {
    pvVar2 = operator_new(*(int *)(param_1 + 0x20) * 0x30);
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      iVar3 = 0;
      puVar4 = (undefined4 *)((int)pvVar2 + 8);
      do {
        iVar5 = iVar5 + 1;
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar3);
        iVar3 = iVar3 + 0x18;
        puVar4[-2] = *puVar1;
        puVar4[-1] = *(undefined4 *)(*(int *)(param_1 + 0x24) + -0x14 + iVar3);
        *puVar4 = *(undefined4 *)(*(int *)(param_1 + 0x24) + -0x10 + iVar3);
        puVar4[1] = *(undefined4 *)(*(int *)(param_1 + 0x24) + -0xc + iVar3);
        puVar4[2] = *(undefined4 *)(*(int *)(param_1 + 0x24) + -8 + iVar3);
        puVar4[3] = *(undefined4 *)(*(int *)(param_1 + 0x24) + -4 + iVar3);
        puVar4 = puVar4 + 6;
      } while (iVar5 < *(int *)(param_1 + 0x1c));
    }
    if (*(void **)(param_1 + 0x24) != (void *)0x0) {
      operator_delete(*(void **)(param_1 + 0x24));
    }
    *(void **)(param_1 + 0x24) = pvVar2;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) << 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x1c) * 0x18) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 4 + *(int *)(param_1 + 0x1c) * 0x18) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 8 + *(int *)(param_1 + 0x1c) * 0x18) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc + *(int *)(param_1 + 0x1c) * 0x18) = param_5;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x10 + *(int *)(param_1 + 0x1c) * 0x18) = param_6;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x14 + *(int *)(param_1 + 0x1c) * 0x18) = param_7;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041a017
// Address: 0041a017
// [HELPER] s_C__msdev_work_age1_x1_aiuaimod_c: "C:\msdev\work\age1_x1\aiuaimod.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
void __thiscall FUN_0041a017(UnitAIModule *param_1,ulong param_2)
{
  long lVar1;
  long *plVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1->notifyQueueSizeValue) {
    plVar2 = &param_1->notifyQueueValue->p1;
    do {
      if (((plVar2[-1] == 0x1fa) &&
          (((*plVar2 != 0x262 || (param_1->currentActionValue == 0x262)) ||
           (param_1->currentActionValue == 0x268)))) &&
         ((param_1->currentOrderValue == -1 && (param_1->currentActionValue == *plVar2)))) {
        UnitAIModule::removeCurrentTarget(param_1);
        if (actionFile != (_iobuf *)0x0) {
          if (param_1->objectValue == (RGE_Static_Object *)0x0) {
            lVar1 = -1;
          }
          else {
            lVar1 = param_1->objectValue->id;
          }
          fprintf(actionFile,s___d_call_stopObject__s__d_,lVar1,s_C__msdev_work_age1_x1_aiuaimod_c,
                  0x170e);
        }
        (**(code **)(param_1->_padding_ + 0x58))(1);
        break;
      }
      iVar3 = iVar3 + 1;
      plVar2 = plVar2 + 6;
    } while (iVar3 < param_1->notifyQueueSizeValue);
  }
  param_1->notifyQueueSizeValue = 0;
  param_1->lastUpdateTimeValue = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0041a0c6
// Address: 0041a0c6
RGE_Static_Object * __thiscall FUN_0041a0c6(int param_1,int param_2)
{
  int iVar1;
  RGE_Game_World *this;
  RGE_Static_Object *pRVar2;
  
  if (((*(int *)(param_1 + 4) != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc), iVar1 != 0))
     && (this = *(RGE_Game_World **)(iVar1 + 0x3c), this != (RGE_Game_World *)0x0)) {
    pRVar2 = RGE_Game_World::object(this,param_2);
    return pRVar2;
  }
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: FUN_0041a0f9
// Address: 0041a0f9
void FUN_0041a0f9(int param_1,undefined4 param_2)
{
  undefined1 auStack_400 [1024];
  
  if (*(int *)(param_1 + 4) != 0) {
    vsprintf(auStack_400,param_2,&stack0x0000000c);
    (**(code **)(**(int **)(param_1 + 4) + 0x144))(*(int **)(param_1 + 4),auStack_400);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041a14e
// Address: 0041a14e
RGE_Animated_Object * __thiscall
FUN_0041a14e(RGE_Animated_Object *param_1,RGE_Master_Animated_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c928;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Static_Object::RGE_Static_Object
            ((RGE_Static_Object *)param_1,(RGE_Master_Static_Object *)param_2,param_3,param_4,
             param_5,param_6,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Animated_Object::_vftable_;
  if (param_7 != 0) {
    RGE_Animated_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------


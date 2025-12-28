// GLOBAL FUNCTIONS PART 0
// Function: FUN_00401746
// Address: 00401746
// XREFS: None
char __fastcall FUN_00401746(RGE_Action_Attack *param_1,int param_2)
{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  undefined4 in_EAX;
  int iVar9;
  char *pcVar10;
  RGE_Static_Object *pRVar11;
  uint uVar12;
  undefined2 uVar13;
  char *unaff_EBX;
  int *unaff_ESI;
  char *unaff_EDI;
  byte in_CF;
  byte in_AF;
  undefined4 uVar14;
  RGE_Action_Attack *apRStack_8 [2];
  
  bVar6 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  bVar7 = (byte)in_EAX + bVar6 * '\x06';
  pbVar1 = (byte *)((int)unaff_ESI + -0x52ffbfeb);
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 + (byte)param_2;
  iVar9 = CONCAT31((int3)((uint)in_EAX >> 8),
                   bVar7 + (0x90 < (bVar7 & 0xf0) | in_CF | bVar6 * (0xf9 < bVar7)) * '`') +
          (uint)CARRY1(bVar2,(byte)param_2);
  unaff_EDI[param_2] = unaff_EDI[param_2] + (char)iVar9 + 'B';
  *unaff_EDI = *unaff_EDI + (char)((uint)(iVar9 + 0x16a70043) >> 8);
  *unaff_EBX = *unaff_EBX + (char)((uint)param_2 >> 8);
  pcVar10 = (char *)(iVar9 + 0x16a70045);
  *pcVar10 = *pcVar10 + (char)pcVar10;
  *unaff_ESI = (int)(pcVar10 + *unaff_ESI);
  param_1->_padding_ =
       (int)(*(float *)(*(int *)(*(int *)(param_1->_padding_ + 0xc) + 0x3c) + 0x84) +
            (float)param_1->_padding_);
  apRStack_8[0] = param_1;
  if ((param_1->_padding_ != -1) &&
     (pRVar11 = RGE_Game_World::object
                          (*(RGE_Game_World **)(*(int *)(param_1->_padding_ + 0xc) + 0x3c),
                           param_1->_padding_), pRVar11 == (RGE_Static_Object *)0x0)) {
LAB_004017e3:
    iVar9 = param_1->_padding_;
    (**(code **)(iVar9 + 0x54))(0);
    (**(code **)(iVar9 + 0x5c))(2);
    return '\x05';
  }
  if ((param_1->_padding_ != -1) &&
     (pRVar11 = RGE_Game_World::object
                          (*(RGE_Game_World **)(*(int *)(param_1->_padding_ + 0xc) + 0x3c),
                           param_1->_padding_), pRVar11 == (RGE_Static_Object *)0x0)) {
    (**(code **)(param_1->_padding_ + 0x58))(0);
  }
  iVar9 = param_1->_padding_;
  if (iVar9 != 0) {
    if (2 < *(byte *)(iVar9 + 0x48)) goto LAB_004017e3;
    if (((iVar9 != 0) &&
        (piVar3 = *(int **)(param_1->_padding_ + 0xc), *(short *)((int)piVar3 + 0x4a) != 0)) &&
       (iVar9 = (**(code **)(*piVar3 + 0x1c))((int)*(short *)(*(int *)(iVar9 + 0xc) + 0x4a)),
       iVar9 != 0)) {
      (**(code **)(param_1->_padding_ + 0x5c))(1);
      cVar8 = (char)param_1->_padding_;
      goto joined_r0x004018c4;
    }
  }
  if ((param_1->_padding_ != 0) && (*(int *)(param_1->_padding_ + 0x20) != 0)) {
    iVar9 = param_1->_padding_;
    uVar14 = 1;
LAB_004018ba:
    (**(code **)(iVar9 + 0x5c))(uVar14);
    cVar8 = (char)param_1->_padding_;
joined_r0x004018c4:
    if (cVar8 == '\0') {
      iVar9 = ((int *)param_1->_padding_)[1];
      (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar9,iVar9,0x1fb,600,param_1->_padding_,0);
    }
    return '\x04';
  }
  bVar2 = (byte)param_1->_padding_;
  switch(bVar2) {
  case 1:
    return '\x01';
  case 2:
    cVar8 = (**(code **)(**(int **)(param_1->_padding_ + 0x18) + 0x24))
                      (*(undefined4 *)(param_1->_padding_ + 0x10));
    if (cVar8 == '\x01') {
      iVar9 = param_1->_padding_;
      (**(code **)(iVar9 + 0x54))(0);
      if ((char)param_1->_padding_ == '\0') {
        iVar5 = ((int *)param_1->_padding_)[1];
        (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar5,iVar5,0x1fa,600,0,0);
      }
      (**(code **)(iVar9 + 0x5c))(1);
      return (-((char)param_1->_padding_ != '\x01') & 0xfdU) + 5;
    }
    break;
  case 4:
    uVar12 = (**(code **)(*(int *)param_1->_padding_ + 0xc))();
    switch((uVar12 & 0xff) - 1) {
    case 0:
    case 1:
      (**(code **)(param_1->_padding_ + 0x5c))(6);
      return '\0';
    case 2:
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      if ((char)param_1->_padding_ != '\0') {
        return '\x03';
      }
      goto switchD_0040185b_caseD_d;
    case 3:
      iVar9 = param_1->_padding_;
      uVar14 = 0xe;
      break;
    default:
      goto switchD_0040185b_caseD_3;
    }
    goto LAB_004018ba;
  case 6:
    apRStack_8[0] = (RGE_Action_Attack *)0xffffffff;
    iVar9 = RGE_Action_Attack::ready_to_attack(param_1,(int *)apRStack_8);
    if (iVar9 != 0) {
      RGE_Combat_Object::reset_attack_timer((RGE_Combat_Object *)param_1->_padding_);
      (**(code **)(param_1->_padding_ + 0x5c))(7);
      return '\0';
    }
    break;
  case 7:
    uVar13 = (undefined2)(bVar2 - 1 >> 0x10);
    if (param_1->need_to_attack == '\0') {
      uVar14 = (**(code **)(*(int *)param_1->_padding_ + 0x7c))();
      if ((char)uVar14 == '\x01') {
        if ((param_1->_padding_ == 0) && (param_1->indirect_fire_flag == '\0')) {
          (**(code **)(param_1->_padding_ + 0x5c))(2);
          return '\0';
        }
        RGE_Combat_Object::reset_attack_timer((RGE_Combat_Object *)param_1->_padding_);
        pcVar4 = *(code **)(param_1->_padding_ + 0x5c);
        (*pcVar4)(6);
        cVar8 = (char)param_1->_padding_;
        if (cVar8 == '\r') {
          return '\0';
        }
        if (cVar8 == '\x04') {
          return '\0';
        }
        uVar14 = (*pcVar4)(7);
      }
      uVar13 = (undefined2)((uint)uVar14 >> 0x10);
      if (param_1->need_to_attack == '\0') {
        cVar8 = (**(code **)(**(int **)(param_1->_padding_ + 0x18) + 0x24))
                          (*(undefined4 *)(param_1->_padding_ + 0x10));
        if ((cVar8 != '\x01') && ((*(byte *)(*(int *)(param_1->_padding_ + 0x10) + 0x70) & 1) != 0))
{
          return '\0';
        }
        if ((param_1->_padding_ == 0) && (param_1->indirect_fire_flag == '\0')) {
          (**(code **)(param_1->_padding_ + 0x5c))(2);
          return '\0';
        }
        (**(code **)(param_1->_padding_ + 0x5c))(6);
        return '\0';
      }
    }
    uVar14 = CONCAT22(uVar13,param_1->fire_missile_at_frame);
    if (param_1->fire_missile_at_frame == 0) {
      apRStack_8[0] =
           (RGE_Action_Attack *)(int)*(short *)(*(int *)(param_1->_padding_ + 0x10) + 0x5e);
      uVar14 = __ftol();
    }
    cVar8 = (**(code **)(**(int **)(param_1->_padding_ + 0x18) + 0x20))
                      (*(undefined4 *)(param_1->_padding_ + 0x10),uVar14);
    if (cVar8 != '\0') {
      RGE_Action_Attack::do_attack(param_1);
      return '\0';
    }
    break;
  case 0xd:
switchD_0040185b_caseD_d:
    iVar9 = ((int *)param_1->_padding_)[1];
    (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar9,iVar9,0x1f9,600,0,0);
    return '\x03';
  }
switchD_0040185b_caseD_3:
  return '\0';
}

// --------------------------------------------------

// Function: FUN_00401a8e
// Address: 00401a8e
// XREFS: None
/* WARNING: Instruction at (ram,0x00401ade) overlaps instruction at (ram,0x00401adc)
    */

undefined4 __fastcall FUN_00401a8e(int *param_1,byte *param_2)
{
  byte bVar1;
  int in_EAX;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  byte *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  undefined2 in_ES;
  bool bVar10;
  byte *pbStack_c;
  
  bVar8 = (byte)unaff_EBX;
  *param_2 = bVar8;
  pcVar2 = (char *)(in_EAX + 1);
  bVar9 = *unaff_EBX;
  bVar6 = (byte)((uint)param_1 >> 8);
  *unaff_EBX = *unaff_EBX + bVar6;
  iVar3 = CONCAT31((int3)((uint)pcVar2 >> 8),((char)pcVar2 - *pcVar2) - CARRY1(bVar9,bVar6));
  pcVar2 = (char *)(iVar3 + 1);
  bVar9 = (byte)((uint)unaff_EBX >> 8);
  *pcVar2 = (*pcVar2 - (char)pcVar2) - CARRY1(bVar8,bVar9);
  pcVar2 = (char *)(iVar3 + 0x18b00042 +
                   CONCAT31((int3)((uint)unaff_EBX >> 8),(bVar8 + bVar9) - (char)*param_1));
  *pcVar2 = *pcVar2 + (char)param_1;
  pcVar2 = (char *)(iVar3 + 3);
  *pcVar2 = *pcVar2 + (char)pcVar2;
  *unaff_ESI = (int)(pcVar2 + *unaff_ESI);
  iVar3 = CONCAT31((int3)((uint)pcVar2 >> 8),(char)pcVar2 + (char)*unaff_ESI);
  uVar4 = iVar3 + *(int *)((int)unaff_ESI + iVar3);
  pbStack_c = (byte *)CONCAT22(pbStack_c._2_2_,in_ES);
  pbVar5 = (byte *)(uVar4 + 0xecff8b90);
  bVar9 = *pbVar5 - (byte)pbVar5;
  bVar10 = *pbVar5 < (byte)pbVar5 || bVar9 < (0x1300746f < uVar4);
  *pbVar5 = bVar9 - (0x1300746f < uVar4);
  bVar1 = in((short)param_2);
  pbVar5 = (byte *)CONCAT31((int3)((uint)pbVar5 >> 8),bVar1);
  bVar9 = *pbVar5;
  bVar6 = *pbVar5;
  bVar8 = *pbVar5 - bVar1;
  *pbVar5 = bVar8 - bVar10;
  cVar7 = (char)((uint)param_2 >> 8);
  if ((SBORROW1(bVar6,bVar1) != SBORROW1(bVar8,bVar10)) == (char)*pbVar5 < '\0') {
    *(char *)(unaff_ESI + -0x1bffeffa) = (char)unaff_ESI[-0x1bffeffa] + cVar7;
    if (pbStack_c == (byte *)0x0) {
      return 0;
    }
    pbVar5 = pbStack_c;
    unaff_ESI = param_1;
    if (pbStack_c != (byte *)param_1[4]) goto LAB_00401afd;
  }
  else {
    *(char *)(unaff_EBP + 0x1c) =
         *(char *)(unaff_EBP + 0x1c) + cVar7 + (bVar9 < bVar1 || bVar8 < bVar10);
  }
  cVar7 = (char)unaff_ESI[3];
  if (cVar7 == '\x04') {
    return 1;
  }
  if (cVar7 == '\x06') {
    return 1;
  }
  if (cVar7 == '\a') {
    return 1;
  }
LAB_00401afd:
  iVar3 = *unaff_ESI;
  *(undefined1 *)((int)unaff_ESI + 0x5a) = 0;
  (**(code **)(iVar3 + 0x54))(pbVar5);
  (**(code **)(iVar3 + 0x5c))(4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040239b
// Address: 0040239b
// XREFS: None
/* WARNING: Instruction at (ram,0x004023c1) overlaps instruction at (ram,0x004023c0)
    */

RGE_Action * __thiscall FUN_0040239b(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  char *pcVar1;
  uint in_EAX;
  byte *pbVar2;
  bool in_ZF;
  
  if (!in_ZF) {
    in_EAX = in_EAX & 0xffffff08;
  }
  pbVar2 = (byte *)(in_EAX + 1);
  *(char *)(in_EAX + 0x67004024) = *(char *)(in_EAX + 0x67004024) + (char)param_1;
  pcVar1 = (char *)(CONCAT22((short)((uint)pbVar2 >> 0x10),
                             (ushort)(byte)(((byte)pbVar2 & *pbVar2) +
                                           (char)((uint)pbVar2 >> 8) * '!')) + 0x1e004024);
  *pcVar1 = *pcVar1 + (char)param_1;
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  param_1->_padding_ = (int)&RGE_Action_Enter::_vftable_;
  param_1->action_type = 3;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040270e
// Address: 0040270e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0040270e(undefined4 param_1,int param_2)
{
  int *piVar1;
  undefined1 uVar2;
  uchar uVar3;
  undefined4 in_EAX;
  int iVar4;
  char *pcVar5;
  RGE_Static_Object *pRVar6;
  uint uVar7;
  RGE_Action *pRVar8;
  int *piVar9;
  int unaff_ESI;
  float fVar11;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 auStack_8 [8];
  char cVar10;
  
  uVar2 = in((short)param_2);
  iVar4 = CONCAT31((int3)((uint)in_EAX >> 8),uVar2);
  cVar10 = (char)((uint)param_1 >> 8) + (char)((uint)(iVar4 + 1) >> 8);
  piVar9 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar10,(char)param_1));
  *(char *)(unaff_ESI + 0x26) = *(char *)(unaff_ESI + 0x26) + (char)param_2;
  iVar4 = iVar4 + 3;
  pcVar5 = (char *)(CONCAT22((short)((uint)iVar4 >> 0x10),
                             CONCAT11((char)((uint)iVar4 >> 8) + cVar10,(char)iVar4)) + 2);
  *pcVar5 = *pcVar5 + (char)pcVar5;
  *(char **)(pcVar5 + param_2) = pcVar5 + *(int *)(pcVar5 + param_2);
  if ((piVar9[6] == -1) ||
     (pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(piVar9[2] + 0xc) + 0x3c),piVar9[6]),
     pRVar6 != (RGE_Static_Object *)0x0)) {
    if ((piVar9[7] != -1) &&
       (pRVar6 = RGE_Game_World::object
                           (*(RGE_Game_World **)(*(int *)(piVar9[2] + 0xc) + 0x3c),piVar9[7]),
       pRVar6 == (RGE_Static_Object *)0x0)) {
      (**(code **)(*piVar9 + 0x58))(0);
    }
    iVar4 = piVar9[4];
    if ((iVar4 == 0) ||
       ((*(byte *)(iVar4 + 0x48) < 3 &&
        ((iVar4 == 0 ||
         (iVar4 = (**(code **)(**(int **)(piVar9[2] + 0xc) + 0x1c))
                            ((int)*(short *)(*(int *)(iVar4 + 0xc) + 0x4a)), iVar4 != 0)))))) {
      switch((char)piVar9[3]) {
      case '\x01':
        return 1;
      case '\x02':
        fVar11 = (float)piVar9[0xb] -
                 ((RGE_Static_Object *)piVar9[2])->owner->world->world_time_delta_seconds;
        piVar9[0xb] = (int)fVar11;
        if (fVar11 <= _DAT_0056e1a8) {
          fVar11 = RGE_Static_Object::distance_to_object
                             ((RGE_Static_Object *)piVar9[2],(RGE_Static_Object *)piVar9[4]);
          if (*(float *)(piVar9[0xc] + 0x24) < fVar11 - _DAT_0056e1a4) {
            cVar10 = (**(code **)(*(int *)piVar9[4] + 0x134))();
            if (cVar10 != '\x02') {
              cVar10 = (**(code **)(*(int *)piVar9[4] + 0x134))();
              if (cVar10 == '\v') {
                pRVar8 = RGE_Action_List::get_action(*(RGE_Action_List **)(piVar9[4] + 0x184));
                fVar11 = RGE_Action::targetX(pRVar8);
                piVar9[8] = (int)fVar11;
                pRVar8 = RGE_Action_List::get_action(*(RGE_Action_List **)(piVar9[4] + 0x184));
                fVar11 = RGE_Action::targetY(pRVar8);
                piVar9[9] = (int)fVar11;
              }
              (**(code **)(*piVar9 + 0x5c))(4);
              return 0;
            }
            piVar1 = (int *)piVar9[2];
            uStack_10 = __ftol();
            uStack_c = __ftol();
            uStack_18 = __ftol();
            uStack_14 = __ftol();
            iVar4 = (**(code **)(*piVar1 + 0x1b4))(&uStack_10,&uStack_18,auStack_8,2,2,1);
            if (iVar4 == 1) {
              fVar11 = (float)iStack_1c - _DAT_0056e1a0;
              if (((float)piVar9[8] == (float)iStack_20 - _DAT_0056e1a0) &&
                 (fVar11 == (float)piVar9[9])) {
                piVar9[8] = *(int *)(piVar9[4] + 0x38);
                piVar9[9] = *(int *)(piVar9[4] + 0x3c);
                (**(code **)(*piVar9 + 0x5c))(4);
                return 0;
              }
              piVar9[8] = (int)((float)iStack_20 - _DAT_0056e1a0);
              piVar9[9] = (int)fVar11;
              (**(code **)(*(int *)piVar9[4] + 0x154))
                        ((float)iStack_20,(float)iStack_1c,((int *)piVar9[4])[0x10],0,1);
              (**(code **)(*piVar9 + 0x5c))(4);
              return 0;
            }
            piVar1 = (int *)piVar9[4];
            piVar9[8] = piVar1[0xe];
            iVar4 = *piVar1;
            piVar9[9] = piVar1[0xf];
            (**(code **)(iVar4 + 0x154))
                      (*(undefined4 *)(piVar9[2] + 0x38),*(undefined4 *)(piVar9[2] + 0x3c),
                       piVar1[0x10],0x3f000000,1);
            (**(code **)(*piVar9 + 0x5c))(4);
            return 0;
          }
          (**(code **)(*(int *)piVar9[2] + 0xd0))(piVar9[4]);
LAB_004028ef:
          if ((char)piVar9[0xf] == '\0') {
            iVar4 = ((int *)piVar9[2])[1];
            (**(code **)(*(int *)piVar9[2] + 0x148))(iVar4,iVar4,0x1fa,0x269,0,0);
          }
          (**(code **)(*piVar9 + 0x5c))(1);
          return 2;
        }
      default:
switchD_004027fc_caseD_3:
        return 0;
      case '\x04':
        goto switchD_004027fc_caseD_4;
      case '\r':
        iVar4 = ((int *)piVar9[2])[1];
        (**(code **)(*(int *)piVar9[2] + 0x148))(iVar4,iVar4,0x1f9,0x269,0,0);
        return 3;
      }
    }
  }
  iVar4 = *piVar9;
  (**(code **)(iVar4 + 0x5c))(1);
  (**(code **)(iVar4 + 0x54))(0);
  iVar4 = ((int *)piVar9[2])[1];
  (**(code **)(*(int *)piVar9[2] + 0x148))(iVar4,iVar4,0x1fb,0x269,0,0);
  return 4;
switchD_004027fc_caseD_4:
  if (((RGE_Static_Object *)piVar9[4] != (RGE_Static_Object *)0x0) &&
     (uVar3 = RGE_Static_Object::is_dying((RGE_Static_Object *)piVar9[4]), uVar3 == '\0')) {
    uVar7 = (**(code **)(*(int *)piVar9[0xd] + 0xc))();
    switch((uVar7 & 0xff) - 1) {
    case 0:
    case 1:
      fVar11 = RGE_Static_Object::distance_to_object
                         ((RGE_Static_Object *)piVar9[2],(RGE_Static_Object *)piVar9[4]);
      if (*(float *)(piVar9[0xc] + 0x24) < fVar11 - _DAT_0056e1a4) {
        (**(code **)(*piVar9 + 0x5c))(2);
        return 0;
      }
      (**(code **)(*(int *)piVar9[2] + 0xd0))(piVar9[4]);
      goto LAB_004028ef;
    case 2:
      (**(code **)(*piVar9 + 0x5c))(2);
      return 0;
    case 3:
    case 4:
      break;
    default:
      goto switchD_004027fc_caseD_3;
    }
  }
  iVar4 = *piVar9;
  (**(code **)(iVar4 + 0x54))(0);
  (**(code **)(iVar4 + 0x5c))(0xd);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00402afa
// Address: 00402afa
// XREFS: None
void __fastcall FUN_00402afa(undefined4 param_1,undefined4 *param_2)
{
  char *in_EAX;
  char unaff_BL;
  int unaff_ESI;
  
  *param_2 = *param_2;
  *(char *)(unaff_ESI + 0x3004028) = *(char *)(unaff_ESI + 0x3004028) + unaff_BL;
  *in_EAX = *in_EAX - (char)in_EAX;
  return;
}

// --------------------------------------------------

// Function: FUN_00402d67
// Address: 00402d67
// XREFS: None
undefined4 __fastcall FUN_00402d67(int *param_1,int param_2)
{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int *piVar5;
  int unaff_EDI;
  
  cVar1 = (char)in_EAX;
  *(char *)(param_2 + 0x4200402c) = *(char *)(param_2 + 0x4200402c) + cVar1 + -0x40;
  piVar5 = (int *)CONCAT31((int3)((uint)param_2 >> 8),(char)param_2 + cVar1 + -0x80);
  iVar2 = CONCAT31((int3)((uint)in_EAX >> 8),cVar1 + '@');
  pcVar3 = (char *)(iVar2 + 0x2c);
  *pcVar3 = *pcVar3 + (char)((uint)in_EAX >> 8);
  *(char *)(unaff_EDI + 0x2c) = *(char *)(unaff_EDI + 0x2c) + (char)((uint)param_1 >> 8);
  pcVar3 = (char *)(iVar2 + 2);
  *pcVar3 = *pcVar3 + (char)pcVar3;
  *piVar5 = (int)(pcVar3 + *piVar5);
  cVar1 = (char)param_1[3];
  if (cVar1 == '\x01') {
    return 1;
  }
  if (cVar1 == '\v') {
    uVar4 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    switch((uVar4 & 0xff) - 1) {
    case 0:
    case 1:
    case 4:
      (**(code **)(*param_1 + 0x5c))(3);
      return 0;
    case 2:
      (**(code **)(*param_1 + 0x5c))(0xd);
      break;
    case 3:
      iVar2 = *param_1;
      (**(code **)(iVar2 + 0x54))(0);
      (**(code **)(iVar2 + 0x5c))(0xb);
      return 0;
    }
  }
  else if (cVar1 == '\r') {
    iVar2 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar2,iVar2,0x1f9,0x25d,0,0);
    (**(code **)(*param_1 + 0x5c))(2);
    return 3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00402e26
// Address: 00402e26
// XREFS: None
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_0040354f
// Address: 0040354f
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0040354f(int *param_1,undefined4 param_2)
{
  char *pcVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  float fVar5;
  int in_EAX;
  byte *pbVar6;
  uint *puVar7;
  uint uVar8;
  RGE_Static_Object *pRVar9;
  undefined4 uVar10;
  int iVar11;
  RGE_Player *this;
  char cVar12;
  byte bVar14;
  char cVar15;
  undefined4 unaff_EBX;
  int unaff_ESI;
  float unaff_EDI;
  float fVar16;
  float fStack00000004;
  char *pcVar13;
  
  bVar14 = (byte)((uint)param_2 >> 8) & bRam317a0040;
  *(char *)(unaff_ESI + 0x31) = *(char *)(unaff_ESI + 0x31) + (char)param_1;
  *(char *)((int)param_1 + 0x32) = *(char *)((int)param_1 + 0x32) + (char)((uint)(in_EAX + 2) >> 8);
  cVar15 = (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_ESI + 0x32e20040) = *(char *)(unaff_ESI + 0x32e20040) + cVar15;
  pbVar6 = (byte *)(in_EAX + 4);
  cVar12 = (char)param_2 + cVar15;
  pcVar13 = (char *)CONCAT31((int3)(CONCAT22((short)((uint)param_2 >> 0x10),
                                             CONCAT11(bVar14,(char)param_2)) >> 8),cVar12);
  puVar7 = (uint *)CONCAT31((int3)((uint)pbVar6 >> 8),(byte)pbVar6 ^ *pbVar6);
  uVar8 = *puVar7;
  *(char *)(unaff_ESI + 0x31c50040) = *(char *)(unaff_ESI + 0x31c50040) + cVar15;
  *(char *)(unaff_ESI + 0x35220040) = *(char *)(unaff_ESI + 0x35220040) + cVar15;
  uVar8 = ((uint)puVar7 ^ uVar8) + 3;
  *pcVar13 = *pcVar13 + (char)(uVar8 >> 8);
  pcVar1 = (char *)((uVar8 ^ 0x31c50040) + 0x83909091);
  *pcVar1 = *pcVar1 + cVar12;
  in((short)pcVar13);
  if ((param_1[6] != -1) &&
     (pRVar9 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1[2] + 0xc) + 0x3c),param_1[6]),
     pRVar9 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*param_1 + 0x54))(0);
  }
  if ((param_1[7] != -1) &&
     (pRVar9 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1[2] + 0xc) + 0x3c),param_1[7]),
     pRVar9 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*param_1 + 0x58))(0);
  }
  if ((param_1[4] != 0) && (6 < *(byte *)(param_1[4] + 0x48))) {
    (**(code **)(*param_1 + 0x54))(0);
  }
  if ((param_1[5] != 0) && (6 < *(byte *)(param_1[5] + 0x48))) {
    (**(code **)(*param_1 + 0x58))(0);
  }
  piVar3 = (int *)param_1[4];
  if (((piVar3 != (int *)0x0) && (*(short *)(piVar3[3] + 0x4a) != 0)) &&
     (*(short *)(piVar3[3] + 0x4a) != *(short *)(*(int *)(param_1[2] + 0xc) + 0x4a))) {
    (**(code **)(*param_1 + 0x5c))(1);
    iVar11 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar11,iVar11,0x1fb,0x261,0,0);
    return 4;
  }
  switch(*(byte *)(param_1 + 3) - 1) {
  case 0:
    return 1;
  case 2:
    if ((float)param_1[0xb] < (float)(double)DAT_0056e278._8_8_) {
      piVar3 = (int *)param_1[2];
      fVar16 = *(float *)(*(int *)(piVar3[3] + 0x3c) + 0x84) + (float)param_1[0xb];
      fVar5 = (float)(double)DAT_0056e278._8_8_;
      param_1[0xb] = (int)fVar16;
      if (fVar5 < fVar16) {
        iVar11 = *piVar3;
        param_1[0xb] = -0x3ee00000;
        (**(code **)(iVar11 + 0x148))(piVar3[1],piVar3[1],0x202,0x261,param_1[0x10],0);
        return 0;
      }
    }
    break;
  case 3:
    uVar8 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    switch((uVar8 & 0xff) - 1) {
    case 0:
    case 1:
      (**(code **)(*param_1 + 0x5c))(6);
      return 0;
    case 2:
      this = *(RGE_Player **)(param_1[2] + 0xc);
      break;
    case 3:
    case 4:
      iVar11 = *param_1;
      (**(code **)(iVar11 + 0x54))(0);
      (**(code **)(iVar11 + 0x5c))(0xb);
      return 0;
    default:
      goto switchD_0040366f_caseD_1;
    }
    goto LAB_00403790;
  case 5:
    if (piVar3 == (int *)0x0) {
      (**(code **)(*param_1 + 0x5c))(3);
      return 0;
    }
    cVar12 = (**(code **)(*(int *)param_1[2] + 0x1f0))(piVar3,0,0);
    if (cVar12 != '\0') {
      if ((*(float *)(param_1[4] + 0x44) <= (float)DAT_0056e278._0_4_) &&
         (cVar12 = (**(code **)(*(int *)param_1[2] + 0x138))
                             ((int)*(short *)(*(int *)(param_1[4] + 8) + 0x10)), cVar12 == '\0')) {
        iVar11 = *param_1;
        (**(code **)(iVar11 + 0x54))(0);
        (**(code **)(iVar11 + 0x5c))(3);
        return 0;
      }
      (**(code **)(*param_1 + 0x5c))(7);
      return 0;
    }
    break;
  case 6:
    if (piVar3 != (int *)0x0) {
      if (rge_base_game->quick_build == 0) {
        fVar16 = *(float *)(param_1[0xc] + 0x1c) * *(float *)(*(int *)(param_1[2] + 8) + 0xe4) *
                 *(float *)(*(int *)(*(int *)(param_1[2] + 0xc) + 0x3c) + 0x84);
      }
      else {
        fVar16 = (float)piVar3[0x11];
      }
      if ((float)piVar3[0x11] < fVar16) {
        fVar16 = (float)piVar3[0x11];
      }
      if (*(short *)(param_1[0xc] + 0x16) == -1) {
        fStack00000004 = 1.0;
      }
      else {
        fStack00000004 =
             *(float *)(*(int *)(*(int *)(param_1[2] + 0xc) + 0x50) +
                       *(short *)(param_1[0xc] + 0x16) * 4);
      }
      fVar5 = (float)(int)*(short *)(*(int *)(param_1[2] + 8) + 0x7c) * fStack00000004 -
              *(float *)(param_1[2] + 0x44);
      if (fVar5 < fStack00000004 * fVar16) {
        fVar16 = fVar16 - (fStack00000004 * fVar16 - fVar5) / fStack00000004;
      }
      (**(code **)(*piVar3 + 0x84))(-fVar16,1,1);
      (**(code **)(*(int *)param_1[2] + 0x84))(unaff_ESI,1,0);
      if ((float)((int *)param_1[2])[0x11] < unaff_EDI) {
        if ((float)DAT_0056e278._0_4_ < *(float *)(param_1[4] + 0x44)) {
          return 0;
        }
        cVar12 = (**(code **)(*(int *)param_1[2] + 0x138))
                           ((int)*(short *)(*(int *)(param_1[4] + 8) + 0x10));
        if (cVar12 != '\0') {
          return 0;
        }
      }
      (**(code **)(*param_1 + 0x5c))(8);
      return 0;
    }
    if ((float)DAT_0056e278._0_4_ < *(float *)(param_1[2] + 0x44)) {
      (**(code **)(*param_1 + 0x5c))(8);
      return 0;
    }
    goto LAB_00403875;
  case 7:
    if ((float)(double)DAT_0056e278._8_8_ <= (float)param_1[0xb]) {
      uVar8 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
      switch((uVar8 & 0xff) - 1) {
      case 0:
      case 1:
        if ((RGE_Static_Object *)param_1[5] == (RGE_Static_Object *)0x0) {
          (**(code **)(*param_1 + 0x5c))(8);
          return 0;
        }
        fVar16 = RGE_Static_Object::distance_to_object
                           ((RGE_Static_Object *)param_1[2],(RGE_Static_Object *)param_1[5]);
        if ((float)_DAT_0056e290 < fVar16) {
          param_1[0xb] = -0x3fc00000;
          (**(code **)(*(int *)param_1[2] + 0x1ec))();
          return 0;
        }
        if (*(RGE_Sound **)(param_1[0xc] + 0x48) != (RGE_Sound *)0x0) {
          RGE_Sound::play(*(RGE_Sound **)(param_1[0xc] + 0x48),1);
        }
        sVar2 = *(short *)(param_1[0xc] + 0x18);
        if (sVar2 == -1) {
          sVar2 = *(short *)(param_1[2] + 0x4c);
        }
        (**(code **)(**(int **)(param_1[2] + 0xc) + 0x78))
                  (CONCAT22((short)((uint)param_1[0xc] >> 0x10),sVar2),
                   *(undefined4 *)(param_1[2] + 0x44),1);
        iVar11 = param_1[2];
        iVar4 = **(int **)(iVar11 + 0xc);
        uVar10 = __ftol();
        (**(code **)(iVar4 + 0x5c))(*(undefined4 *)(iVar11 + 4),(int)(short)unaff_EBX,uVar10);
        (**(code **)(*(int *)param_1[2] + 0x80))(0xffffffff,0);
        if (param_1[4] != 0) {
          iVar11 = *param_1;
          (**(code **)(iVar11 + 0x58))(0);
          (**(code **)(iVar11 + 0x5c))(4);
          return 0;
        }
        if ((param_1[8] != -0x40800000) && (param_1[9] != -0x40800000)) {
          (**(code **)(*param_1 + 0x5c))(0xb);
          return 0;
        }
        goto LAB_00403b35;
      case 2:
      case 3:
      case 4:
        param_1[0xb] = -0x3fc00000;
        (**(code **)(*(int *)param_1[2] + 0x1ec))();
        return 0;
      }
    }
    else {
      fVar16 = *(float *)(*(int *)(*(int *)(param_1[2] + 0xc) + 0x3c) + 0x84) + (float)param_1[0xb];
      fVar5 = (float)(double)DAT_0056e278._8_8_;
      param_1[0xb] = (int)fVar16;
      if (fVar5 < fVar16) {
        param_1[0xb] = 0;
        (**(code **)(*param_1 + 0x5c))(8);
        return 0;
      }
    }
    break;
  case 10:
  case 0xe:
    uVar8 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    switch((uVar8 & 0xff) - 1) {
    case 0:
    case 1:
    case 4:
      if ((char)param_1[3] == '\v') {
        (**(code **)(*param_1 + 0x5c))(3);
        return 0;
      }
LAB_00403b35:
      iVar11 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[2] + 0xc));
      if (iVar11 != 1) {
        (**(code **)(*param_1 + 0x5c))(2);
        return 0;
      }
      (**(code **)(*param_1 + 0x5c))(1);
      return 0;
    case 2:
      this = *(RGE_Player **)(param_1[2] + 0xc);
      break;
    case 3:
      iVar11 = *param_1;
      (**(code **)(iVar11 + 0x54))(0);
      if ((char)param_1[3] != '\v') {
        (**(code **)(iVar11 + 0x5c))(0xf);
        return 0;
      }
      (**(code **)(iVar11 + 0x5c))(0xb);
      return 0;
    default:
      goto switchD_0040366f_caseD_1;
    }
LAB_00403790:
    iVar11 = RGE_Player::computerPlayer(this);
    if (iVar11 == 1) {
      (**(code **)(*param_1 + 0x5c))(0xd);
      return 0;
    }
LAB_00403875:
    (**(code **)(*param_1 + 0x5c))(3);
    return 0;
  case 0xc:
    iVar11 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar11,iVar11,0x1f9,0x261,0,0);
    iVar11 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[2] + 0xc));
    if (iVar11 != 1) {
      (**(code **)(*param_1 + 0x5c))(2);
      return 3;
    }
    (**(code **)(*param_1 + 0x5c))(1);
    return 3;
  }
switchD_0040366f_caseD_1:
  return 0;
}

// --------------------------------------------------

// Function: FUN_004041c2
// Address: 004041c2
// XREFS: None
undefined4 __fastcall FUN_004041c2(int param_1,undefined4 param_2)
{
  byte bVar1;
  RGE_Task *pRVar2;
  RGE_Static_Object *pRVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  uint uVar6;
  UnitAIModule *pUVar7;
  undefined4 uVar8;
  char cVar10;
  int *piVar9;
  char *unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  byte in_AF;
  float fVar11;
  float fVar12;
  undefined4 uStack00000018;
  code *pcStack0000001c;
  undefined4 uStack00000020;
  undefined2 in_stack_00000024;
  RGE_Task *in_stack_00000028;
  RGE_Static_Object *in_stack_0000002c;
  float in_stack_00000030;
  RGE_Action_Attack *in_stack_00000034;
  RGE_Action_Attack *in_stack_00000038;
  long lVar13;
  float fVar14;
  
  pRVar3 = in_stack_0000002c;
  pRVar2 = in_stack_00000028;
  cVar10 = (char)((uint)param_2 >> 8);
  unaff_ESI[0x40] = unaff_ESI[0x40] + cVar10;
  unaff_ESI[-0x9ffbfc0] = unaff_ESI[-0x9ffbfc0] + cVar10;
  iVar5 = in_EAX + 4;
  cVar10 = cVar10 * '\x02';
  piVar9 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(cVar10,(char)param_2));
  bVar1 = 9 < ((byte)iVar5 & 0xf) | in_AF;
  uVar6 = CONCAT31((int3)((uint)iVar5 >> 8),(byte)iVar5 + bVar1 * -6) & 0xffffff0f;
  *unaff_ESI = *unaff_ESI + cVar10;
  *(char *)((int)piVar9 + 0x41) = *(char *)((int)piVar9 + 0x41) + cVar10;
  unaff_ESI[0x4041] = unaff_ESI[0x4041] + (char)((uint)(param_1 + 1) >> 8);
  *piVar9 = *piVar9 + CONCAT22((short)(uVar6 >> 0x10),
                               CONCAT11((char)((uint)iVar5 >> 8) - bVar1,(char)uVar6)) + 4;
  uStack00000018 = *unaff_FS_OFFSET;
  uStack00000020 = 0xffffffff;
  pcStack0000001c = FUN_0055c2ad;
  *unaff_FS_OFFSET = &stack0x00000018;
  switch(in_stack_00000028->action_type) {
  case 4:
    in_stack_0000002c = (RGE_Static_Object *)operator_new(0x40);
    uStack00000020 = 3;
    if (in_stack_0000002c != (RGE_Static_Object *)0x0) {
      uVar8 = RGE_Action_Explore::RGE_Action_Explore
                        ((RGE_Action_Explore *)in_stack_0000002c,
                         *(RGE_Action_Object **)(param_1 + 5),pRVar2,in_stack_00000030,
                         (float)in_stack_00000034,(float)in_stack_00000038);
      goto LAB_0040445e;
    }
    break;
  case 5:
    if (in_stack_0000002c == (RGE_Static_Object *)0x0) {
      in_stack_0000002c = (RGE_Static_Object *)operator_new(0x44);
      uStack00000020 = 5;
      if (in_stack_0000002c != (RGE_Static_Object *)0x0) {
        uVar8 = RGE_Action_Gather::RGE_Action_Gather
                          ((RGE_Action_Gather *)in_stack_0000002c,
                           *(RGE_Action_Object **)(param_1 + 5),pRVar2,in_stack_00000030,
                           (float)in_stack_00000034,(float)in_stack_00000038);
        goto LAB_0040445e;
      }
    }
    else {
      in_stack_00000034 = (RGE_Action_Attack *)operator_new(0x44);
      uStack00000020 = 4;
      if (in_stack_00000034 != (RGE_Action_Attack *)0x0) {
        uVar8 = RGE_Action_Gather::RGE_Action_Gather
                          ((RGE_Action_Gather *)in_stack_00000034,
                           *(RGE_Action_Object **)(param_1 + 5),pRVar2,pRVar3);
        goto LAB_0040445e;
      }
    }
    break;
  case 7:
    pUVar7 = RGE_Static_Object::unitAI(*(RGE_Static_Object **)(param_1 + 5));
    fVar4 = (float)in_stack_00000038;
    pRVar3 = in_stack_0000002c;
    if (pUVar7 != (UnitAIModule *)0x0) {
      iVar5 = 600;
      pUVar7 = RGE_Static_Object::unitAI(*(RGE_Static_Object **)(param_1 + 5));
      UnitAIModule::setCurrentAction(pUVar7,iVar5);
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        lVar13 = -1;
        fVar11 = (float)in_stack_00000034;
        fVar12 = fVar4;
        fVar14 = in_stack_00000030;
      }
      else {
        lVar13 = pRVar3->id;
        fVar11 = pRVar3->world_y;
        fVar12 = pRVar3->world_z;
        fVar14 = pRVar3->world_x;
      }
      pUVar7 = RGE_Static_Object::unitAI(*(RGE_Static_Object **)(param_1 + 5));
      UnitAIModule::setCurrentTarget(pUVar7,lVar13,fVar14,fVar11,fVar12);
    }
    if (pRVar3 == (RGE_Static_Object *)0x0) {
      in_stack_00000038 = (RGE_Action_Attack *)operator_new(0x5c);
      uStack00000020 = 2;
      if (in_stack_00000038 != (RGE_Action_Attack *)0x0) {
        iVar5 = (*(RGE_Action_Object **)(param_1 + 5))->_padding_;
        uVar8 = RGE_Action_Attack::RGE_Action_Attack
                          (in_stack_00000038,*(RGE_Action_Object **)(param_1 + 5),in_stack_00000030,
                           (float)in_stack_00000034,fVar4,pRVar2->move_sprite,pRVar2->work_sprite,
                           (RGE_Sprite *)0x0,pRVar2->work_range,*(float *)(iVar5 + 0x138),
                           *(short *)(iVar5 + 0x124),*(short *)(iVar5 + 0x12a));
        goto LAB_0040445e;
      }
    }
    else {
      in_stack_00000034 = (RGE_Action_Attack *)operator_new(0x5c);
      uStack00000020 = 1;
      if (in_stack_00000034 != (RGE_Action_Attack *)0x0) {
        iVar5 = (*(RGE_Action_Object **)(param_1 + 5))->_padding_;
        uVar8 = RGE_Action_Attack::RGE_Action_Attack
                          (in_stack_00000034,*(RGE_Action_Object **)(param_1 + 5),pRVar3,
                           pRVar2->move_sprite,pRVar2->work_sprite,(RGE_Sprite *)0x0,
                           pRVar2->work_range,*(float *)(iVar5 + 0x138),*(short *)(iVar5 + 0x124),
                           *(short *)(iVar5 + 0x12a));
        goto LAB_0040445e;
      }
    }
    break;
  case 10:
    in_stack_0000002c = (RGE_Static_Object *)operator_new(0x40);
    uStack00000020 = 0;
    if (in_stack_0000002c != (RGE_Static_Object *)0x0) {
      uVar8 = RGE_Action_Bird::RGE_Action_Bird
                        ((RGE_Action_Bird *)in_stack_0000002c,*(RGE_Action_Object **)(param_1 + 5),
                         pRVar2,in_stack_00000030,(float)in_stack_00000034,(float)in_stack_00000038)
      ;
      goto LAB_0040445e;
    }
    break;
  case 0x15:
    in_stack_00000034 = (RGE_Action_Attack *)operator_new(0x40);
    uStack00000020 = 6;
    if (in_stack_00000034 != (RGE_Action_Attack *)0x0) {
      uVar8 = RGE_Action_Make::RGE_Action_Make
                        ((RGE_Action_Make *)in_stack_00000034,*(RGE_Action_Object **)(param_1 + 5),
                         pRVar2);
      goto LAB_0040445e;
    }
  }
  uVar8 = 0;
LAB_0040445e:
  *unaff_FS_OFFSET = uStack00000018;
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_00404473
// Address: 00404473
// XREFS: None
char __fastcall FUN_00404473(RGE_Action_List *param_1,undefined4 param_2)
{
  RGE_Action_Node *pRVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  int iVar4;
  int unaff_EBX;
  int iVar5;
  char *unaff_ESI;
  
  iVar4 = CONCAT22((short)((uint)param_2 >> 0x10),
                   CONCAT11((char)((uint)param_2 >> 8) + (char)param_1,(char)param_2));
  iVar5 = unaff_EBX + 2;
  pcVar3 = (char *)(iVar4 + 0x40 + (in_EAX + 2) * 2);
  cVar2 = (char)((uint)iVar5 >> 8);
  *pcVar3 = *pcVar3 + cVar2;
  *unaff_ESI = *unaff_ESI + cVar2;
  (&stack0x00000000)[(in_EAX + 3) * 2] =
       (&stack0x00000000)[(in_EAX + 3) * 2] + (char)((uint)(iVar4 + 1) >> 8);
  pcVar3 = (char *)(in_EAX + 4);
  (&stack0x00000040)[(int)pcVar3 * 2] = (&stack0x00000040)[(int)pcVar3 * 2] + (char)iVar5;
  *pcVar3 = *pcVar3 + (char)pcVar3;
  pcRam03050502 = pcVar3 + (int)pcRam03050502;
  if (param_1->list != (RGE_Action_Node *)0x0) {
    cVar2 = (**(code **)(param_1->list->action->_padding_ + 0x20))(iVar5);
    for (pRVar1 = param_1->list->next; pRVar1 != (RGE_Action_Node *)0x0; pRVar1 = pRVar1->next) {
      (**(code **)(pRVar1->action->_padding_ + 0x24))();
    }
    if (cVar2 == '\x01') {
      RGE_Action_List::remove_action(param_1);
    }
    return cVar2;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: FUN_0040496e
// Address: 0040496e
// XREFS: None
RGE_Action * __fastcall
FUN_0040496e(int param_1,undefined4 param_2,int param_3,RGE_Action_Object *param_4)
{
  int in_EAX;
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  RGE_Action *this;
  char cVar5;
  char unaff_BH;
  int unaff_EBP;
  byte *unaff_ESI;
  char *unaff_EDI;
  int *piVar6;
  
  iVar4 = CONCAT31((int3)((uint)(param_1 + -1) >> 8),(char)(param_1 + -1) + unaff_BH);
  pcVar1 = (char *)(in_EAX + 1);
  *pcVar1 = *pcVar1 + (char)pcVar1;
  *unaff_EDI = *unaff_EDI + (char)in_EAX + '\x02';
  cVar5 = (char)param_2 + (char)((uint)param_2 >> 8);
  piVar6 = (int *)CONCAT31((int3)((uint)param_2 >> 8),cVar5);
  cRam1c004049 = cRam1c004049 + cVar5;
  this = (RGE_Action *)(iVar4 + -3);
  *(char *)(unaff_EBP + 0x49) = *(char *)(unaff_EBP + 0x49) + (char)in_EAX + '\x04';
  pbVar2 = (byte *)(in_EAX + 5);
  *pbVar2 = *pbVar2 + (char)pbVar2;
  bVar3 = (byte)this;
  *pbVar2 = *pbVar2 | bVar3;
  *piVar6 = (int)(pbVar2 + *piVar6);
  *pbVar2 = *pbVar2 | bVar3;
  pbVar2 = pbVar2 + *(int *)(in_EAX + 0x808080d);
  *pbVar2 = *pbVar2 | bVar3;
  *pbVar2 = *pbVar2 | bVar3;
  *unaff_ESI = *unaff_ESI | (byte)pbVar2;
  RGE_Action::RGE_Action(this,param_3,param_4,1);
  this->_padding_ = (int)&RGE_Action_Make::_vftable_;
  *(undefined2 *)(iVar4 + 1) = 0x15;
  return this;
}

// --------------------------------------------------

// Function: FUN_004050d5
// Address: 004050d5
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_004050d5(undefined4 param_1,undefined4 param_2)
{
  byte bVar1;
  uchar uVar2;
  RGE_Game_World *this;
  RGE_Missile_Object *this_00;
  RGE_Check_Node *pRVar3;
  float fVar4;
  uchar uVar5;
  int in_EAX;
  RGE_Static_Object *pRVar6;
  uint uVar7;
  RGE_Check_List *this_01;
  RGE_Check_List *extraout_EAX;
  int iVar8;
  char cVar11;
  int *piVar9;
  RGE_Static_Object *pRVar10;
  RGE_Static_Object *pRVar12;
  int iVar13;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  int iVar14;
  float fVar15;
  int iVar16;
  float fVar17;
  int *piVar18;
  float fVar19;
  float fStack_14;
  float fStack_8;
  float fStack_4;
  
  *unaff_EDI = *unaff_ESI;
  cVar11 = (char)((uint)param_1 >> 8);
  piVar9 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),
                           CONCAT11(cVar11 + (char)((uint)param_2 >> 8),(char)param_1));
  *(char *)(in_EAX + -0x6f6f6f6c) = *(char *)(in_EAX + -0x6f6f6f6c) + (char)param_2 + cVar11;
  fStack_4 = 0.0;
  fStack_8 = 0.0;
  fStack_14 = 0.0;
  this = *(RGE_Game_World **)(*(int *)(piVar9[2] + 0xc) + 0x3c);
  fVar19 = this->world_time_delta_seconds;
  fVar17 = *(float *)(*(int *)(piVar9[2] + 8) + 0xb8) * fVar19;
  if ((piVar9[6] != -1) &&
     (pRVar6 = RGE_Game_World::object(this,piVar9[6]), pRVar6 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*piVar9 + 0x54))(0);
  }
  if ((piVar9[7] != -1) &&
     (pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(piVar9[2] + 0xc) + 0x3c),piVar9[7]),
     pRVar6 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*piVar9 + 0x58))(0);
  }
  if (((RGE_Static_Object *)piVar9[4] != (RGE_Static_Object *)0x0) &&
     (uVar5 = RGE_Static_Object::is_dying((RGE_Static_Object *)piVar9[4]), uVar5 != '\0')) {
    (**(code **)(*piVar9 + 0x54))(0);
  }
  if (((RGE_Static_Object *)piVar9[5] != (RGE_Static_Object *)0x0) &&
     (uVar5 = RGE_Static_Object::is_dying((RGE_Static_Object *)piVar9[5]), uVar5 != '\0')) {
    (**(code **)(*piVar9 + 0x58))(0);
  }
  if (*(byte *)(piVar9 + 3) == 1) {
    return 1;
  }
  uVar7 = *(byte *)(piVar9 + 3) - 4;
  if (uVar7 == 0) {
    cVar11 = *(char *)(*(int *)(piVar9[2] + 8) + 0x148);
    if (cVar11 == '\0') {
      fVar15 = (float)piVar9[0xb];
      piVar9[0xb] = (int)(fVar17 + fVar15);
      fStack_4 = (float)piVar9[0x10] * fVar17;
      fStack_8 = (float)piVar9[0x11] * fVar17;
      fStack_14 = (float)piVar9[0x12] * fVar17;
      if (*(float *)(piVar9[2] + 0x1c4) <= fVar17 + fVar15) {
        (**(code **)(*piVar9 + 0x5c))(1);
      }
    }
    else if (cVar11 == '\x03') {
      fStack_4 = (float)piVar9[0x10];
      fStack_8 = (float)piVar9[0x11];
      fStack_14 = (float)piVar9[0x12];
    }
    if ((float)_DAT_0056e388 < *(float *)(((RGE_Moving_Object *)piVar9[2])->_padding_ + 0x150)) {
      fVar4 = (float)piVar9[0x14] * fVar19 * _DAT_0056e380;
      fVar15 = (float)piVar9[0x13];
      piVar9[0x13] = (int)((float)piVar9[0x14] * fVar19 + (float)piVar9[0x13]);
      fStack_14 = (fVar4 + fVar15) * fVar19 + fStack_14;
    }
    RGE_Moving_Object::set_velocity((RGE_Moving_Object *)piVar9[2],fStack_4,fStack_8,fStack_14);
    uVar5 = RGE_Missile_Object::missile_move((RGE_Missile_Object *)piVar9[2]);
    this_00 = (RGE_Missile_Object *)piVar9[2];
    bVar1 = *(byte *)(this_00->_padding_ + 0x148);
    this_01 = (RGE_Check_List *)CONCAT31((int3)((uint)this_00->_padding_ >> 8),bVar1);
    if (bVar1 < 3) {
      this_01 = RGE_Missile_Object::make_object_collision_list(this_00,fVar17);
      if (this_01 != (RGE_Check_List *)0x0) {
        for (pRVar3 = this_01->list; pRVar3 != (RGE_Check_Node *)0x0; pRVar3 = pRVar3->next) {
          pRVar6 = (RGE_Static_Object *)piVar9[2];
          uVar2 = pRVar6->master_obj[1].convert_terrain_flag;
          if (uVar2 == '\0') {
            pRVar12 = (RGE_Static_Object *)piVar9[4];
            if (pRVar3->node == pRVar12) {
              pRVar10 = (RGE_Static_Object *)piVar9[5];
              if (pRVar10 == (RGE_Static_Object *)0x0) {
LAB_0040540a:
                fVar19 = pRVar6->world_z;
                iVar13 = pRVar6->_padding_;
                fVar17 = pRVar6->world_y;
                fVar15 = pRVar6->world_x;
                pRVar10 = pRVar6;
              }
              else {
LAB_004053f8:
                fVar19 = pRVar6->world_z;
                iVar13 = pRVar10->_padding_;
                fVar17 = pRVar6->world_y;
                fVar15 = pRVar6->world_x;
              }
LAB_0040541c:
              (**(code **)(iVar13 + 0x228))(pRVar12,pRVar10,fVar15,fVar17,fVar19);
              goto LAB_00405422;
            }
          }
          else if (uVar2 == '\x01') {
            pRVar12 = pRVar3->node;
            if ((pRVar12->owner != pRVar6->owner) && (pRVar12->owner->id != 0)) {
              pRVar10 = (RGE_Static_Object *)piVar9[5];
              if (pRVar10 == (RGE_Static_Object *)0x0) goto LAB_0040540a;
              fVar19 = pRVar6->world_z;
              iVar13 = pRVar10->_padding_;
              fVar17 = pRVar6->world_y;
              fVar15 = pRVar6->world_x;
              goto LAB_0040541c;
            }
          }
          else if (uVar2 == '\x02') {
            pRVar10 = (RGE_Static_Object *)piVar9[5];
            pRVar12 = pRVar3->node;
            if (pRVar10 == (RGE_Static_Object *)0x0) {
              if ((pRVar12->owner != pRVar6->owner) && (pRVar12->owner->id != 0)) goto LAB_0040540a;
              (**(code **)(pRVar6->_padding_ + 0x21c))
                        (pRVar6->world_x,pRVar6->world_y,pRVar6->world_z,pRVar6,0);
            }
            else {
              if (pRVar12 == pRVar10) goto LAB_0040542b;
              if ((pRVar12->owner != pRVar6->owner) && (pRVar12->owner->id != 0)) goto LAB_004053f8;
              (**(code **)(pRVar10->_padding_ + 0x21c))
                        (pRVar6->world_x,pRVar6->world_y,pRVar6->world_z,pRVar10,0);
            }
LAB_00405422:
            (**(code **)(*piVar9 + 0x5c))(1);
          }
LAB_0040542b:
        }
        RGE_Check_List::~RGE_Check_List(this_01);
        operator_delete(this_01);
        this_01 = extraout_EAX;
      }
    }
    else if (bVar1 == 3) {
      piVar18 = (int *)piVar9[5];
      if (piVar18 == (int *)0x0) {
        (**(code **)(this_00->_padding_ + 0x228))
                  (piVar9[4],this_00,this_00->_padding_,this_00->_padding_,this_00->_padding_);
        this_01 = (RGE_Check_List *)(**(code **)(*piVar9 + 0x5c))(1);
      }
      else {
        (**(code **)(*piVar18 + 0x228))
                  (piVar9[4],piVar18,this_00->_padding_,this_00->_padding_,this_00->_padding_);
        this_01 = (RGE_Check_List *)(**(code **)(*piVar9 + 0x5c))(1);
      }
    }
    uVar7 = CONCAT31((int3)((uint)this_01 >> 8),uVar5);
    if ((uVar5 != '\0') && ((char)piVar9[3] != '\x01')) {
      piVar18 = (int *)piVar9[5];
      if (piVar18 == (int *)0x0) {
        piVar18 = (int *)piVar9[2];
        iVar16 = piVar18[0x10];
        iVar13 = *piVar18;
        iVar14 = piVar18[0xf];
        iVar8 = piVar18[0xe];
      }
      else {
        iVar8 = piVar9[2];
        iVar13 = *piVar18;
        iVar16 = *(int *)(iVar8 + 0x40);
        iVar14 = *(int *)(iVar8 + 0x3c);
        iVar8 = *(int *)(iVar8 + 0x38);
      }
      (**(code **)(iVar13 + 0x21c))(iVar8,iVar14,iVar16,piVar18,0);
      uVar7 = (**(code **)(*piVar9 + 0x5c))(1);
    }
  }
  return uVar7 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_0040582e
// Address: 0040582e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall
FUN_0040582e(int *param_1,char param_2,int param_3,float param_4,float param_5)
{
  code *pcVar1;
  undefined1 uVar2;
  int in_EAX;
  char *pcVar3;
  RGE_Static_Object *pRVar4;
  PathResult PVar5;
  int iVar6;
  int unaff_EBX;
  int *piVar7;
  byte in_CF;
  float fVar8;
  float fVar9;
  
  piVar7 = (int *)(unaff_EBX + *(int *)(in_EAX + 0x40) + (uint)in_CF);
  pcVar3 = (char *)(in_EAX + (int)piVar7 * 2);
  *pcVar3 = *pcVar3 + (char)in_EAX;
  *(char *)piVar7 = (char)*piVar7 + param_2;
  *(char *)piVar7 = (char)*piVar7 + (char)((uint)param_1 >> 8);
  pcVar3 = (char *)(param_3 + 1);
  *pcVar3 = *pcVar3 + (char)pcVar3;
  *piVar7 = (int)(pcVar3 + *piVar7 + *piVar7);
  if ((param_1[6] != -1) &&
     (pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1[2] + 0xc) + 0x3c),param_1[6]),
     pRVar4 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*param_1 + 0x54))(0);
LAB_004058b5:
    if ((char)param_1[0xf] == '\x01') {
      return 5;
    }
    iVar6 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar6,iVar6,0x1fb,0x262,param_1[6],0);
    return 4;
  }
  if ((param_1[7] != -1) &&
     (pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1[2] + 0xc) + 0x3c),param_1[7]),
     pRVar4 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*param_1 + 0x58))(0);
  }
  pRVar4 = (RGE_Static_Object *)param_1[4];
  if ((pRVar4 != (RGE_Static_Object *)0x0) && (6 < pRVar4->object_state)) {
    (**(code **)(*param_1 + 0x54))(0);
    goto LAB_004058b5;
  }
  switch((char)param_1[3]) {
  case '\x01':
    return 1;
  case '\x03':
    if ((pRVar4 != (RGE_Static_Object *)0x0) &&
       (iVar6 = RGE_Static_Object::inRange
                          ((RGE_Static_Object *)param_1[2],pRVar4,(float)param_1[0x10]), iVar6 != 0)
       ) {
      (**(code **)(*param_1 + 0x5c))(1);
      if ((char)param_1[0xf] == '\0') {
        iVar6 = ((int *)param_1[2])[1];
        (**(code **)(*(int *)param_1[2] + 0x148))(iVar6,iVar6,0x1fa,0x262,0,0);
      }
      (**(code **)(*(int *)param_1[2] + 300))(0);
      *(undefined4 *)(param_1[2] + 0x58) = 0;
      return 2;
    }
    iVar6 = param_1[4];
    if (iVar6 != 0) {
      param_1[8] = *(int *)(iVar6 + 0x38);
      param_1[9] = *(int *)(iVar6 + 0x3c);
      param_1[10] = *(int *)(iVar6 + 0x40);
    }
    RGE_Moving_Object::setGoal
              ((RGE_Moving_Object *)param_1[2],(float)param_1[8],(float)param_1[9],1.0);
    uVar2 = __ftol();
    param_4 = (float)CONCAT31(param_4._1_3_,uVar2);
    uVar2 = __ftol();
    param_4._0_2_ = CONCAT11(uVar2,param_4._0_1_);
    uVar2 = __ftol();
    param_4._0_3_ = CONCAT12(uVar2,param_4._0_2_);
    if ((char)((int *)param_1[2])[0x5d] == '\0') {
      (**(code **)(*(int *)param_1[2] + 0x1bc))(&param_4,0);
      RGE_Moving_Object::setFinalUserDefinedWaypoint((RGE_Moving_Object *)param_1[2]);
    }
    RGE_Moving_Object::setActionRange((RGE_Moving_Object *)param_1[2],(float)param_1[0x10]);
    if (param_1[4] == 0) {
      RGE_Moving_Object::setTargetID((RGE_Moving_Object *)param_1[2],-1);
      fVar9 = 0.0;
      fVar8 = 0.0;
    }
    else {
      RGE_Moving_Object::setTargetID((RGE_Moving_Object *)param_1[2],*(int *)(param_1[4] + 4));
      fVar9 = *(float *)(*(int *)(param_1[4] + 8) + 0x34);
      fVar8 = *(float *)(*(int *)(param_1[4] + 8) + 0x30);
    }
    RGE_Moving_Object::setTargetRadius((RGE_Moving_Object *)param_1[2],fVar8,fVar9);
    PVar5 = RGE_Moving_Object::findPath((RGE_Moving_Object *)param_1[2]);
    if (PVar5 == PathFound) {
      (**(code **)(*param_1 + 0x5c))(4);
      return 0;
    }
    break;
  case '\x04':
    if (pRVar4 != (RGE_Static_Object *)0x0) {
      fVar9 = (float)param_1[8] - pRVar4->world_x;
      param_4 = (float)param_1[9] - pRVar4->world_y;
      if ((((fVar9 < (float)ram0x0056e410) || ((float)_DAT_0056e418 < fVar9)) ||
          (param_4 < (float)ram0x0056e410)) || ((float)_DAT_0056e418 < param_4)) goto LAB_00405b55;
    }
    iVar6 = RGE_Moving_Object::doMove((RGE_Moving_Object *)param_1[2]);
    if (iVar6 == 0) {
      (**(code **)(*param_1 + 0x5c))(1);
      goto switchD_00405902_caseD_d;
    }
    if (iVar6 == 2) {
      iVar6 = param_1[4];
      if (iVar6 != 0) {
        fVar9 = (float)param_1[8] - *(float *)(iVar6 + 0x38);
        param_5 = (float)param_1[9] - *(float *)(iVar6 + 0x3c);
        if (((fVar9 < (float)ram0x0056e410) || ((float)_DAT_0056e418 < fVar9)) ||
           ((param_5 < (float)ram0x0056e410 || ((float)_DAT_0056e418 < param_5)))) {
LAB_00405b55:
          iVar6 = ((int *)param_1[2])[1];
          (**(code **)(*(int *)param_1[2] + 0x148))(iVar6,iVar6,0x1fc,0,0,0);
          iVar6 = *param_1;
          (**(code **)(iVar6 + 0x5c))(3);
          pcVar1 = *(code **)(iVar6 + 0x28);
          (*pcVar1)();
          (*pcVar1)();
          return 0;
        }
      }
      if ((char)param_1[0xf] == '\0') {
        iVar6 = ((int *)param_1[2])[1];
        (**(code **)(*(int *)param_1[2] + 0x148))(iVar6,iVar6,0x1fa,0x262,0,0);
      }
      (**(code **)(*param_1 + 0x5c))(1);
      return 2;
    }
    break;
  case '\r':
switchD_00405902_caseD_d:
    if ((char)param_1[0xf] == '\0') {
      iVar6 = ((int *)param_1[2])[1];
      (**(code **)(*(int *)param_1[2] + 0x148))(iVar6,iVar6,0x1f9,0x262,0,0);
    }
    return 3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405bca
// Address: 00405bca
// XREFS: None
void FUN_00405bca(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00406785
// Address: 00406785
// XREFS: None
void __fastcall FUN_00406785(byte *param_1,undefined4 param_2)
{
  int in_EAX;
  int iVar1;
  undefined2 uVar3;
  char *pcVar2;
  byte bVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar9;
  undefined4 unaff_EBX;
  char *pcVar8;
  char *unaff_EDI;
  undefined3 uVar10;
  
  out(0x66,in_EAX);
  iVar1 = in_EAX + 1;
  cVar7 = (char)unaff_EBX + (char)iVar1;
  uVar3 = (undefined2)((uint)iVar1 >> 0x10);
  bVar4 = (byte)param_1;
  cVar9 = (char)((uint)unaff_EBX >> 8) + bVar4;
  uVar10 = (undefined3)(CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar9,cVar7)) >> 8);
  cVar7 = cVar7 * '\x02';
  pcVar8 = (char *)CONCAT31(uVar10,cVar7);
  pcVar2 = (char *)(CONCAT22(uVar3,(short)iVar1 + 3) + -0xffbf9a);
  cVar5 = (char)((uint)param_1 >> 8);
  *pcVar2 = *pcVar2 + cVar5;
  iVar1 = CONCAT22(uVar3,(short)iVar1 + 4);
  cVar6 = (char)((uint)param_2 >> 8);
  unaff_EDI[0x17004066] = unaff_EDI[0x17004066] + cVar6;
  *pcVar8 = *pcVar8 + (char)((uint)(iVar1 + 1) >> 8);
  *unaff_EDI = *unaff_EDI + cVar5;
  iVar1 = iVar1 + 3;
  pcVar2 = (char *)CONCAT31(uVar10,cVar7 + cVar6);
  *pcVar2 = *pcVar2 + bVar4;
  *param_1 = *param_1 + cVar9;
  pcVar2 = (char *)(CONCAT22((short)((uint)iVar1 >> 0x10),(short)iVar1 + 1) + 2);
  *pcVar2 = *pcVar2 + (char)pcVar2;
  *param_1 = *param_1 | bVar4;
  return;
}

// --------------------------------------------------

// Function: FUN_0040712e
// Address: 0040712e
// XREFS: None
/* WARNING: Instruction at (ram,0x0040718d) overlaps instruction at (ram,0x0040718c)
    */

undefined4 __fastcall FUN_0040712e(byte *param_1,int param_2)
{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  uint in_EAX;
  char *pcVar4;
  byte bVar5;
  undefined2 uVar6;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  bool bVar8;
  bool in_OF;
  byte bVar7;
  
  if (in_OF) {
    *(byte *)(unaff_EBX + -0x76f3dbac) = *(byte *)(unaff_EBX + -0x76f3dbac) | (byte)param_1;
    param_1 = param_1 + 1;
    *(byte *)(unaff_EBX + -0x76efdbbc) = *(byte *)(unaff_EBX + -0x76efdbbc) & (byte)param_1;
    bVar8 = false;
    pcVar4 = (char *)(in_EAX & 0xffffff8b);
  }
  else {
    out(*unaff_ESI,(short)param_2);
    bVar7 = (char)((uint)param_2 >> 8) + (char)((uint)unaff_EBX >> 8);
    uVar6 = CONCAT11(bVar7,(char)param_2);
    param_2 = CONCAT22((short)((uint)param_2 >> 0x10),uVar6);
    out(unaff_ESI[1],uVar6);
    pcVar4 = (char *)(CONCAT31((int3)(in_EAX >> 8),(char)in_EAX + (char)unaff_EBX) + 2);
    pbVar1 = (byte *)(param_2 + -0x2ffbf91);
    bVar8 = CARRY1(*pbVar1,bVar7);
    bVar2 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar7;
    if (!SCARRY1(bVar2,bVar7)) {
      bVar2 = *param_1;
      bVar5 = (byte)((uint)param_1 >> 8);
      bVar7 = *param_1;
      *param_1 = *param_1 + bVar5;
      if (!SCARRY1(bVar7,bVar5)) {
        cVar3 = (char)pcVar4 - CARRY1(bVar2,bVar5);
        pcVar4 = (char *)CONCAT31((int3)((uint)pcVar4 >> 8),cVar3);
        *pcVar4 = *pcVar4 + cVar3;
        param_1[0x52ff2842] = param_1[0x52ff2842] + (byte)param_1 + 1;
        return 1;
      }
      *pcVar4 = *pcVar4 + (char)pcVar4;
      (**(code **)(*(int *)param_1 + 0x5c))(2);
      return 1;
    }
  }
  *(int *)(param_2 + 0xb) = *(int *)(param_2 + 0xb) + unaff_EBP + (uint)bVar8;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  *(char **)(param_1 + 0x28) = pcVar4;
  (**(code **)(param_2 + 0x5c))();
  return 1;
}

// --------------------------------------------------

// Function: operator==
// Address: 00407f80
// XREFS: operator!=
/* int __cdecl operator==(class BaseItem const &,class BaseItem const &) */

int __cdecl operator==(BaseItem *param_1,BaseItem *param_2)
{
  if (((param_1->gameIDValue == param_2->gameIDValue) && (param_1->xValue == param_2->xValue)) &&
     (param_1->yValue == param_2->yValue)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: operator!=
// Address: 00407fc0
// XREFS: None
/* int __cdecl operator!=(class BaseItem const &,class BaseItem const &) */

int __cdecl operator!=(BaseItem *param_1,BaseItem *param_2)
{
  int iVar1;
  
  iVar1 = operator==(param_1,param_2);
  return (uint)(iVar1 == 0);
}

// --------------------------------------------------

// Function: operator<
// Address: 00407fe0
// XREFS: None
/* int __cdecl operator<(class BaseItem const &,class BaseItem const &) */

int __cdecl operator<(BaseItem *param_1,BaseItem *param_2)
{
  return (uint)(param_1->gameIDValue < param_2->gameIDValue);
}

// --------------------------------------------------

// Function: operator>
// Address: 00408000
// XREFS: None
/* int __cdecl operator>(class BaseItem const &,class BaseItem const &) */

int __cdecl operator>(BaseItem *param_1,BaseItem *param_2)
{
  return (uint)(param_2->gameIDValue < param_1->gameIDValue);
}

// --------------------------------------------------

// Function: operator==
// Address: 00408480
// XREFS: None
/* int __cdecl operator==(class BuildItem const &,class BuildItem const &) */

int __cdecl operator==(BuildItem *param_1,BuildItem *param_2)
{
  return (uint)(param_1->_padding_ == param_2->_padding_);
}

// --------------------------------------------------

// Function: operator!=
// Address: 004084a0
// XREFS: None
/* int __cdecl operator!=(class BuildItem const &,class BuildItem const &) */

int __cdecl operator!=(BuildItem *param_1,BuildItem *param_2)
{
  return (uint)(param_1->_padding_ != param_2->_padding_);
}

// --------------------------------------------------

// Function: operator<
// Address: 004084c0
// XREFS: None
/* int __cdecl operator<(class BuildItem const &,class BuildItem const &) */

int __cdecl operator<(BuildItem *param_1,BuildItem *param_2)
{
  return (uint)(param_1->_padding_ < param_2->_padding_);
}

// --------------------------------------------------

// Function: operator>
// Address: 004084e0
// XREFS: None
/* int __cdecl operator>(class BuildItem const &,class BuildItem const &) */

int __cdecl operator>(BuildItem *param_1,BuildItem *param_2)
{
  return (uint)(param_2->_padding_ < param_1->_padding_);
}

// --------------------------------------------------

// Function: FUN_00409827
// Address: 00409827
// XREFS: None
int __fastcall FUN_00409827(char *param_1,undefined4 param_2)
{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  byte bVar28;
  int in_EAX;
  char *pcVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  byte *pbVar33;
  char cVar34;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  byte *unaff_EDI;
  int iVar35;
  
  LOCK();
  bVar2 = unaff_EDI[-0x6a08ffc0];
  unaff_EDI[-0x6a08ffc0] = (byte)param_2;
  pbVar33 = (byte *)CONCAT31((int3)((uint)param_2 >> 8),bVar2);
  UNLOCK();
  cVar34 = (char)unaff_EBX + (char)((uint)param_2 >> 8);
  iVar35 = CONCAT31((int3)((uint)unaff_EBX >> 8),cVar34);
  *param_1 = *param_1 + cVar34;
  pcVar29 = (char *)(unaff_EBP + 0x41 + (int)pbVar33 * 4);
  *pcVar29 = *pcVar29 + (byte)param_1;
  pcVar29 = (char *)(iVar35 + -0x6a);
  *pcVar29 = *pcVar29 + bVar2;
  *(char *)(in_EAX + -0x69) = *(char *)(in_EAX + -0x69) + (char)unaff_ESI + '\x02';
  *pbVar33 = *pbVar33 + bVar2;
  *unaff_EDI = *unaff_EDI + (char)((uint)(unaff_EBP + 2) >> 8);
  pcVar29 = (char *)(unaff_ESI + 4);
  *pcVar29 = *pcVar29 + (char)((uint)pcVar29 >> 8);
  iVar30 = unaff_EBP + 3;
  *(char *)(unaff_ESI + 0x409b) = *(char *)(unaff_ESI + 0x409b) + (char)iVar30;
  bVar2 = *pbVar33;
  bVar3 = *pbVar33;
  bVar4 = *pbVar33;
  bVar5 = *pbVar33;
  bVar6 = *pbVar33;
  bVar7 = *pbVar33;
  bVar8 = *pbVar33;
  bVar9 = *pbVar33;
  bVar10 = *pbVar33;
  bVar11 = *pbVar33;
  bVar12 = *pbVar33;
  bVar13 = *pbVar33;
  bVar14 = *pbVar33;
  bVar15 = *pbVar33;
  bVar16 = *pbVar33;
  bVar17 = *pbVar33;
  bVar18 = *pbVar33;
  bVar19 = *pbVar33;
  bVar20 = *pbVar33;
  bVar21 = *pbVar33;
  bVar22 = *pbVar33;
  bVar23 = *pbVar33;
  bVar24 = *pbVar33;
  bVar25 = *pbVar33;
  bVar26 = *pbVar33;
  bVar27 = *pbVar33;
  bVar28 = *pbVar33;
  *(int *)pbVar33 = *(int *)pbVar33 + iVar30;
  iVar31 = CONCAT31((int3)((uint)param_1 >> 8),
                    (byte)param_1 | bVar2 | bVar3 | bVar4 | bVar5 | bVar6 | bVar7 | bVar8 | bVar9 |
                    bVar10 | bVar11 | bVar12 | bVar13 | bVar14 | bVar15 | bVar16 | bVar17 | bVar18 |
                    bVar19 | bVar20 | bVar21 | bVar22 | bVar23 | bVar24 | bVar25 | bVar26 | bVar27 |
                    bVar28) + *(int *)pbVar33;
  iVar30 = CONCAT31((int3)((uint)iVar30 >> 8),(char)iVar30 + '\n') + 0xa0a0a0a;
  uVar32 = CONCAT31((int3)((uint)iVar31 >> 8),
                    (byte)iVar31 | *pbVar33 | *pbVar33 |
                    *(byte *)CONCAT31((int3)((uint)iVar30 >> 8),(byte)iVar30 | *unaff_EDI));
  puVar1 = (uint *)(iVar35 + 0x1a081);
  *puVar1 = *puVar1 | uVar32;
  return uVar32 + 0x1a4;
}

// --------------------------------------------------

// Function: operator==
// Address: 0040a370
// XREFS: None
/* int __cdecl operator==(class BaseObject const &,class BaseObject const &) */

int __cdecl operator==(BaseObject *param_1,BaseObject *param_2)
{
  return (uint)(param_1->gameIDValue == param_2->gameIDValue);
}

// --------------------------------------------------

// Function: operator!=
// Address: 0040a390
// XREFS: None
/* int __cdecl operator!=(class BaseObject const &,class BaseObject const &) */

int __cdecl operator!=(BaseObject *param_1,BaseObject *param_2)
{
  return (uint)(param_1->gameIDValue != param_2->gameIDValue);
}

// --------------------------------------------------

// Function: operator<
// Address: 0040a3b0
// XREFS: None
/* int __cdecl operator<(class BaseObject const &,class BaseObject const &) */

int __cdecl operator<(BaseObject *param_1,BaseObject *param_2)
{
  return (uint)(param_1->gameIDValue < param_2->gameIDValue);
}

// --------------------------------------------------

// Function: operator>
// Address: 0040a3d0
// XREFS: None
/* int __cdecl operator>(class BaseObject const &,class BaseObject const &) */

int __cdecl operator>(BaseObject *param_1,BaseObject *param_2)
{
  return (uint)(param_2->gameIDValue < param_1->gameIDValue);
}

// --------------------------------------------------

// Function: operator==
// Address: 0040a960
// XREFS: setBuilt, unplaceStructure
/* int __cdecl operator==(class ConstructionItem const &,class ConstructionItem const &) */

int __cdecl operator==(ConstructionItem *param_1,ConstructionItem *param_2)
{
  if (((float)param_1->_padding_ == (float)param_2->_padding_) &&
     ((float)param_1->_padding_ == (float)param_2->_padding_)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: operator!=
// Address: 0040a990
// XREFS: None
/* int __cdecl operator!=(class ConstructionItem const &,class ConstructionItem const &) */

int __cdecl operator!=(ConstructionItem *param_1,ConstructionItem *param_2)
{
  if (((float)param_1->_padding_ == (float)param_2->_padding_) &&
     ((float)param_1->_padding_ == (float)param_2->_padding_)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: operator<
// Address: 0040a9c0
// XREFS: None
/* int __cdecl operator<(class ConstructionItem const &,class ConstructionItem const &) */

int __cdecl operator<(ConstructionItem *param_1,ConstructionItem *param_2)
{
  return (uint)(param_1->_padding_ < param_2->_padding_);
}

// --------------------------------------------------

// Function: operator>
// Address: 0040a9e0
// XREFS: None
/* int __cdecl operator>(class ConstructionItem const &,class ConstructionItem const &) */

int __cdecl operator>(ConstructionItem *param_1,ConstructionItem *param_2)
{
  return (uint)(param_2->_padding_ < param_1->_padding_);
}

// --------------------------------------------------

// Function: FUN_0040cd5e
// Address: 0040cd5e
// XREFS: None
void FUN_0040cd5e(void)
{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0040ec4e
// Address: 0040ec4e
// XREFS: None
void __fastcall FUN_0040ec4e(undefined4 param_1,undefined2 param_2)
{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 in_EAX;
  int iVar5;
  char cVar6;
  int unaff_EBX;
  char *unaff_ESI;
  
  uVar1 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)param_1;
  uVar2 = in(param_2);
  cVar6 = (char)param_2;
  *unaff_ESI = *unaff_ESI + cVar6;
  uVar3 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)unaff_EBX;
  uVar4 = in(param_2);
  iVar5 = CONCAT31((int3)((uint)(CONCAT31((int3)((uint)(CONCAT31((int3)((uint)(CONCAT31((int3)((uint
                                                  )in_EAX >> 8),uVar1) + 1) >> 8),uVar2) + 1) >> 8),
                                          uVar3) + 1) >> 8),uVar4) + 1;
  *unaff_ESI = *unaff_ESI + (char)((uint)iVar5 >> 8);
  uVar1 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)((uint)param_1 >> 8);
  uVar2 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)((ushort)param_2 >> 8);
  uVar3 = in(param_2);
  *unaff_ESI = *unaff_ESI + (char)((uint)unaff_EBX >> 8);
  uVar4 = in(param_2);
  iVar5 = CONCAT31((int3)((uint)(CONCAT31((int3)((uint)(CONCAT31((int3)((uint)(CONCAT31((int3)((uint
                                                  )iVar5 >> 8),uVar1) + 1) >> 8),uVar2) + 1) >> 8),
                                          uVar3) + 1) >> 8),uVar4);
  *(char *)(unaff_EBX + -0x7c2dcd3f) = *(char *)(unaff_EBX + -0x7c2dcd3f) + (char)param_1;
  *(int *)(iVar5 + 0x4488911) = *(int *)(iVar5 + 0x4488911) + -1;
  *(undefined4 *)(iVar5 + 9) = param_1;
  *(char *)(iVar5 + 0xd) = cVar6;
  *(char *)(iVar5 + 0xe) = cVar6;
  return;
}

// --------------------------------------------------

// Function: FUN_0040f066
// Address: 0040f066
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void FUN_0040f066(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: `vector_constructor_iterator'
// Address: 0040f0e0
// XREFS: None
/* void __stdcall `vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *))
    */

void _vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)
{
  void *unaff_EBX;
  
  if (-1 < param_3 + -1) {
    do {
      (*param_4)(unaff_EBX);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040fb9e
// Address: 0040fb9e
// XREFS: None
undefined4 __fastcall
FUN_0040fb9e(int param_1,char param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,int param_8)
{
  char in_AL;
  AIPlayPhaseCommand *pAVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_ESI;
  int iVar4;
  AIPlayPhase *this;
  bool in_CF;
  bool in_ZF;
  
  if (in_CF || in_ZF) {
    *(char *)(unaff_EBX + 0x40fb76ff) = *(char *)(unaff_EBX + 0x40fb76ff) + (char)param_1;
  }
  else {
    in_AL = in_AL + '\x01';
  }
  *(char *)(unaff_ESI + -5) = *(char *)(unaff_ESI + -5) + (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_ESI + -0x71ffbf05) = *(char *)(unaff_ESI + -0x71ffbf05) + in_AL + '\x01';
  *(char *)(param_1 + 0x53) = *(char *)(param_1 + 0x53) + param_2;
  param_3 = 0;
  this = (AIPlayPhase *)(param_1 + 0x90);
  do {
    iVar4 = 0;
    do {
      pAVar1 = AIPlayPhase::command(this,iVar4);
      if (pAVar1->typeValue == '\x01') {
        iVar3 = pAVar1->value1Value + param_5;
        iVar2 = pAVar1->value2Value + param_6;
        if ((((iVar3 < 0) || (iVar2 < 0)) || (param_7 <= iVar3)) || (param_8 <= iVar2)) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    this = this + 1;
    param_3 = param_3 + 1;
    if (9 < param_3) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: operator==
// Address: 00412100
// XREFS: None
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

// Function: operator!=
// Address: 00412140
// XREFS: None
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

// Function: operator==
// Address: 00412d90
// XREFS: None
/* int __cdecl operator==(class TechnologyItem const &,class TechnologyItem const &) */

int __cdecl operator==(TechnologyItem *param_1,TechnologyItem *param_2)
{
  return (uint)(param_1->idValue == param_2->idValue);
}

// --------------------------------------------------

// Function: operator!=
// Address: 00412db0
// XREFS: None
/* int __cdecl operator!=(class TechnologyItem const &,class TechnologyItem const &) */

int __cdecl operator!=(TechnologyItem *param_1,TechnologyItem *param_2)
{
  return (uint)(param_1->idValue != param_2->idValue);
}

// --------------------------------------------------

// Function: operator<
// Address: 00412dd0
// XREFS: None
/* int __cdecl operator<(class TechnologyItem const &,class TechnologyItem const &) */

int __cdecl operator<(TechnologyItem *param_1,TechnologyItem *param_2)
{
  return (uint)(param_1->idValue < param_2->idValue);
}

// --------------------------------------------------

// Function: operator>
// Address: 00412df0
// XREFS: None
/* int __cdecl operator>(class TechnologyItem const &,class TechnologyItem const &) */

int __cdecl operator>(TechnologyItem *param_1,TechnologyItem *param_2)
{
  return (uint)(param_2->idValue < param_1->idValue);
}

// --------------------------------------------------

// Function: FUN_00414767
// Address: 00414767
// XREFS: None
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

// Function: FUN_00414d12
// Address: 00414d12
// XREFS: None
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_004171ca
// Address: 004171ca
// XREFS: None
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

// Function: FUN_00418045
// Address: 00418045
// XREFS: None
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

// Function: write_draw_log
// Address: 0041b620
// XREFS: do_draw, play
// [HELPER] s__s: "%s"
/* void __cdecl write_draw_log(char *) */

void __cdecl write_draw_log(char *param_1)
{
  if (draw_log != (_iobuf *)0x0) {
    fprintf(draw_log,s__s,param_1);
    fflush(draw_log);
  }
  return;
}

// --------------------------------------------------

// Function: write_draw_log2
// Address: 0041b650
// XREFS: do_draw, draw, play
// [HELPER] draw_log_name: "00000000"
// [HELPER] s__s: "%s"
// [HELPER] s_a_: "a+"
/* void __cdecl write_draw_log2(char *) */

void __cdecl write_draw_log2(char *param_1)
{
  if (draw_log != (_iobuf *)0x0) {
    fprintf(draw_log,s__s,param_1);
    fclose(draw_log);
    draw_log = (_iobuf *)fopen(&draw_log_name,s_a_);
  }
  return;
}

// --------------------------------------------------

// Function: rge_base_game_wnd_proc
// Address: 0041e7a0
// XREFS: setup_class
undefined4
rge_base_game_wnd_proc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uVar1;
  
  if (rge_base_game != (RGE_Base_Game *)0x0) {
    uVar1 = (**(code **)(rge_base_game->_padding_ + 8))
                      (rge_base_game,param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041f6fa
// Address: 0041f6fa
// XREFS: None
// [HELPER] s_Blank_Screen: "Blank Screen"
undefined4 __fastcall FUN_0041f6fa(int param_1,undefined4 param_2)
{
  undefined4 in_EAX;
  char *pcVar1;
  TScreenPanel *pTVar2;
  long lVar3;
  char cVar4;
  char unaff_BH;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  cVar4 = (char)((uint)param_2 >> 8);
  *(char *)(param_1 + -8) = *(char *)(param_1 + -8) + cVar4;
  *(char *)(param_1 + -7) = *(char *)(param_1 + -7) + cVar4;
  pcVar1 = (char *)(CONCAT31((int3)((uint)in_EAX >> 8),
                             (char)in_EAX + (char)((uint)in_EAX >> 8) * -0xb +
                             (char)((uint)(param_1 + 1) >> 8) + unaff_BH) & 0xffff00ff);
  *(char *)(param_1 + -5) = *(char *)(param_1 + -5) + cVar4;
  *pcVar1 = *pcVar1 + (char)(RGE_Base_Game *)(param_1 + 6);
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cbdb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar2 = (TScreenPanel *)operator_new(0x478);
  uStack_4 = 0;
  if (pTVar2 == (TScreenPanel *)0x0) {
    pTVar2 = (TScreenPanel *)0x0;
  }
  else {
    pTVar2 = (TScreenPanel *)TScreenPanel::TScreenPanel(pTVar2,s_Blank_Screen);
  }
  uStack_4 = 0xffffffff;
  if (pTVar2 == (TScreenPanel *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  lVar3 = TScreenPanel::setup(pTVar2,*(TDrawArea **)(param_1 + 0x52),(char *)0x0,-1,0);
  if (lVar3 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Blank_Screen,0);
  RGE_Base_Game::set_render_all((RGE_Base_Game *)(param_1 + 6));
  SendMessageA(*(undefined4 *)(param_1 + 0x16),0xf,0,0);
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: enum_wnd_proc
// Address: 00420580
// XREFS: None
/* WARNING: Variable defined which should be unmapped: wnd_title */
/* int __stdcall enum_wnd_proc(void *,long) */

int enum_wnd_proc(void *param_1,long param_2)
{
  char wnd_title [256];
  
  wnd_title[0] = -1;
  wnd_title[1] = '\0';
  wnd_title[2] = '\0';
  wnd_title[3] = '\0';
  GetWindowTextA(param_1,wnd_title + 4,0xff);
  return 1;
}

// --------------------------------------------------

// Function: enum_child_proc
// Address: 004205b0
// XREFS: None
/* WARNING: Variable defined which should be unmapped: wnd_title */
/* int __stdcall enum_child_proc(void *,long) */

int enum_child_proc(void *param_1,long param_2)
{
  char wnd_title [256];
  
  wnd_title[0] = -1;
  wnd_title[1] = '\0';
  wnd_title[2] = '\0';
  wnd_title[3] = '\0';
  GetWindowTextA(param_1,wnd_title + 4,0xff);
  return 1;
}

// --------------------------------------------------

// Function: enum_thread_proc
// Address: 004205e0
// XREFS: None
/* WARNING: Variable defined which should be unmapped: wnd_title */
/* int __stdcall enum_thread_proc(void *,long) */

int enum_thread_proc(void *param_1,long param_2)
{
  char wnd_title [256];
  
  wnd_title[0] = -1;
  wnd_title[1] = '\0';
  wnd_title[2] = '\0';
  wnd_title[3] = '\0';
  GetWindowTextA(param_1,wnd_title + 4,0xff);
  return 1;
}

// --------------------------------------------------

// Function: close_thread_windows
// Address: 00420610
// XREFS: None
/* int __stdcall close_thread_windows(void *,long) */

int close_thread_windows(void *param_1,long param_2)
{
  void *pvVar1;
  
  if (param_1 != AppWnd) {
    pvVar1 = (void *)GetParent(param_1);
    if (pvVar1 != AppWnd) {
      SendMessageA(param_1,0x10,0,0);
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: close_child_windows
// Address: 00420650
// XREFS: None
// [HELPER] s_Locate_Session: "Locate Session"
/* WARNING: Variable defined which should be unmapped: str */
/* int __stdcall close_child_windows(void *,long) */

int close_child_windows(void *param_1,long param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  char str [256];
  
  str[4] = '\0';
  GetWindowTextA(param_1,str + 4,0xff);
  pbVar4 = &s_Locate_Session;
  pbVar2 = (byte *)(str + 4);
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004206a7:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004206ac;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004206a7;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004206ac:
  if (iVar3 != 0) {
    SendMessageA(param_1,0x10,0,0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004225c7
// Address: 004225c7
// XREFS: None
undefined1 __fastcall FUN_004225c7(int param_1,int param_2,undefined4 param_3,int param_4)
{
  byte in_AL;
  char unaff_BL;
  char unaff_BH;
  char *unaff_EDI;
  
  *unaff_EDI = *unaff_EDI + (char)param_2 + '\x01';
  *unaff_EDI = *unaff_EDI;
  *unaff_EDI = *unaff_EDI + (char)((uint)(param_2 + 3) >> 8);
  unaff_EDI[0x25] = unaff_EDI[0x25] + (in_AL & 0x42);
  unaff_EDI[0x25] = unaff_EDI[0x25] + (char)param_1;
  unaff_EDI[0x25] = unaff_EDI[0x25] + (char)param_2 + '\x06';
  unaff_EDI[0x25] = unaff_EDI[0x25] + unaff_BL;
  unaff_EDI[0x25] = unaff_EDI[0x25];
  unaff_EDI[0x25] = unaff_EDI[0x25] + (char)((uint)param_1 >> 8);
  unaff_EDI[0x25] = unaff_EDI[0x25] + (char)((uint)(param_2 + 10) >> 8);
  unaff_EDI[0x25] = unaff_EDI[0x25] + unaff_BH;
  unaff_EDI[-0x70ffbddb] = unaff_EDI[-0x70ffbddb] + (in_AL & 0x42);
  unaff_EDI[-0x58ffbddb] = unaff_EDI[-0x58ffbddb] + unaff_BL;
  unaff_EDI[-0x6fffbddb] = unaff_EDI[-0x6fffbddb] + (char)((uint)(param_2 + 0xe) >> 8);
  return *(undefined1 *)(param_1 + 0x98a + param_4);
}

// --------------------------------------------------

// Function: debug_random_reset
// Address: 00423010
// XREFS: new_game
// [HELPER] debug_random_log: "00000000"
/* void __cdecl debug_random_reset(void) */

void __cdecl debug_random_reset(void)
{
  char **ppcVar1;
  
  ppcVar1 = &debug_random_log;
  do {
    *(undefined1 *)ppcVar1 = 0;
    ppcVar1 = ppcVar1 + 0x19;
  } while ((int)ppcVar1 < 0x62c498);
  debug_random_index = -1;
  return;
}

// --------------------------------------------------

// Function: debug_random_write
// Address: 00423030
// XREFS: action_user_command, do_command_game, quit_game, ~RGE_Base_Game
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_: ""
// [HELPER] s__: "}"
// [HELPER] s__s_d____s_: "%s%d - %s\n"
// [HELPER] s_c__aoerand_txt: "c:\aoerand.txt"
// [HELPER] s_w: "w"
/* void __cdecl debug_random_write(void) */

void __cdecl debug_random_write(void)
{
  int iVar1;
  undefined1 *puVar2;
  char **ppcVar3;
  int iVar4;
  
  iVar1 = fopen(s_c__aoerand_txt,s_w);
  if (iVar1 != 0) {
    iVar4 = 0;
    ppcVar3 = &debug_random_log;
    do {
      puVar2 = &s_>;
      if (iVar4 != debug_random_index) {
        puVar2 = &s__;
      }
      fprintf(iVar1,s__s_d____s_,puVar2,iVar4,ppcVar3);
      ppcVar3 = ppcVar3 + 0x19;
      iVar4 = iVar4 + 1;
    } while ((int)ppcVar3 < 0x62c498);
    fclose(iVar1);
    wrote_debug_random_log = 1;
  }
  return;
}

// --------------------------------------------------

// Function: debug_rand
// Address: 004230a0
// XREFS: AddingCircle, Branch, CreateShape, GetRandomSeed, MakeFirstLink, MakeNewLink, MakeSatelliteLink, RGE_Active_Animated_Sprite, SetRandomSeed, TEST, TRIBE_Player, action (... +70 more)
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_t_d__s_l_d_r_d: "t%d,%s,l%d,r%d"
/* WARNING: Variable defined which should be unmapped: temp_name */
/* int __cdecl debug_rand(char *,int) */

int __cdecl debug_rand(char *param_1,int param_2)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char temp_name [9];
  
  iVar2 = rand();
  if ((do_debug_random != 0) && (debug_random_on != 0)) {
    pcVar3 = param_1 + 10;
    pcVar4 = temp_name + 4;
    cVar1 = *pcVar3;
    for (; (cVar1 != '.' && (pcVar3 < param_1 + 0x12)); pcVar3 = pcVar3 + 1) {
      *pcVar4 = cVar1;
      cVar1 = pcVar3[1];
      pcVar4 = pcVar4 + 1;
    }
    *pcVar4 = '\0';
    if (debug_random_index < 4999) {
      debug_random_index = debug_random_index + 1;
    }
    else {
      debug_random_index = 0;
    }
    sprintf(&debug_random_log + debug_random_index * 0x19,s_t_d__s_l_d_r_d,
            rge_base_game->world->world_time,temp_name + 4,param_2,iVar2);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: debug_srand
// Address: 00423140
// XREFS: GetRandomSeed, SetRandomSeed, create_game, init_vars, loadAIInformation, map_generate2, new_game, new_scenario, notify, recycle_in_to_game, set_object_state, setup (... +1 more)
// [HELPER] debug_random_log: "00000000"
// [HELPER] s_t_d__s_l_d_s_u: "t%d,%s,l%d,s%u"
/* WARNING: Variable defined which should be unmapped: temp_name */
/* void __cdecl debug_srand(char *,int,unsigned int) */

void __cdecl debug_srand(char *param_1,int param_2,uint param_3)
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char temp_name [9];
  
  if ((do_debug_random != 0) && (debug_random_on != 0)) {
    pcVar2 = param_1 + 10;
    pcVar3 = temp_name + 4;
    cVar1 = *pcVar2;
    for (; (cVar1 != '.' && (pcVar2 < param_1 + 0x12)); pcVar2 = pcVar2 + 1) {
      *pcVar3 = cVar1;
      cVar1 = pcVar2[1];
      pcVar3 = pcVar3 + 1;
    }
    *pcVar3 = '\0';
    if (debug_random_index < 4999) {
      debug_random_index = debug_random_index + 1;
    }
    else {
      debug_random_index = 0;
    }
    sprintf(&debug_random_log + debug_random_index * 0x19,s_t_d__s_l_d_s_u,
            rge_base_game->world->world_time,temp_name + 4,param_2,param_3);
  }
  srand(param_3);
  return;
}

// --------------------------------------------------

// Function: debug_timeGetTime
// Address: 004231e0
// XREFS: CheckPingTime, CommOut, DestroyMultiplayerGame, DoCycle, FastSend, Get, GetCommInfo, GetDPLAYMessages, GetElapsedFirstCall, GetRandomSeed, Load, OpenLog (... +83 more)
/* unsigned long __cdecl debug_timeGetTime(char *,int) */

ulong __cdecl debug_timeGetTime(char *param_1,int param_2)
{
  ulong uVar1;
  
  if ((do_debug_timeGetTime != 0) && (debug_timeGetTime_on != 0)) {
    debug_timeGetTime_cnt = debug_timeGetTime_cnt + 1;
    if (debug_timeGetTime_cnt == debug_timeGetTime_interval) {
      debug_timeGetTime_cnt = 0;
      debug_timeGetTime_time = debug_timeGetTime_time + 1;
    }
    return debug_timeGetTime_time;
  }
                    /* WARNING: Could not recover jumptable at 0x00423222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = timeGetTime();
  return uVar1;
}

// --------------------------------------------------

// Function: RGE_translate_palette
// Address: 00423ee0
// XREFS: RGE_Color_Table, RGE_fade_palette, RGE_fade_palette_step
/* WARNING: Variable defined which should be unmapped: index1 */
/* void __cdecl RGE_translate_palette(struct tagPALETTEENTRY *,struct tagPALETTEENTRY *,struct
   tagPALETTEENTRY,long,int,int) */

void __cdecl
RGE_translate_palette
          (tagPALETTEENTRY *param_1,tagPALETTEENTRY *param_2,tagPALETTEENTRY param_3,long param_4,
          int param_5,int param_6)
{
  byte bVar1;
  tagPALETTEENTRY tVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  uchar *puVar8;
  long index1;
  long intense [3];
  
  puVar6 = &param_2->peFlags;
  iVar4 = (int)param_2 - (int)param_1;
  intense[0] = 0;
  puVar8 = &param_1->peGreen;
  do {
    if ((intense[0] == param_5) || (intense[0] == param_6)) {
      ((tagPALETTEENTRY *)(puVar6 + -3))->peRed = ((tagPALETTEENTRY *)(puVar8 + -1))->peRed;
      puVar8[iVar4] = *puVar8;
      puVar6[-1] = puVar8[1];
      *puVar6 = puVar8[2];
    }
    else {
      tVar2 = *(tagPALETTEENTRY *)(puVar8 + -1);
      intense[1] = (uint)tVar2 & 0xff;
      bVar1 = puVar8[1];
      intense[2] = (uint)*puVar8;
      param_2 = (tagPALETTEENTRY *)0x2;
      do {
        piVar3 = intense + 2;
        iVar7 = 2;
        do {
          iVar5 = piVar3[-1];
          if (iVar5 < *piVar3) {
            piVar3[-1] = *piVar3;
            *piVar3 = iVar5;
          }
          piVar3 = piVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        param_2 = (tagPALETTEENTRY *)&param_2[-1].peFlags;
      } while (param_2 != (tagPALETTEENTRY *)0x0);
      iVar7 = ((uint)bVar1 + intense[2]) * (0xff - intense[1]);
      iVar7 = ((int)(iVar7 + (iVar7 >> 0x1f & 0x1ffU)) >> 9) + intense[1];
      iVar5 = ((int)(((uint)param_3 & 0xff) * iVar7) / 0xff - ((uint)tVar2 & 0xff)) * param_4;
      ((tagPALETTEENTRY *)(puVar6 + -3))->peRed =
           (((char)(iVar5 / 100) + (char)(iVar5 >> 0x1f)) -
           (char)((longlong)iVar5 * 0x51eb851f >> 0x3f)) + ((tagPALETTEENTRY *)(puVar8 + -1))->peRed
      ;
      iVar5 = ((int)(((uint)param_3 >> 8 & 0xff) * iVar7) / 0xff - (uint)*puVar8) * param_4;
      puVar8[iVar4] =
           (((char)(iVar5 / 100) + (char)(iVar5 >> 0x1f)) -
           (char)((longlong)iVar5 * 0x51eb851f >> 0x3f)) + *puVar8;
      iVar7 = ((int)(((uint)param_3 >> 0x10 & 0xff) * iVar7) / 0xff - (uint)puVar8[1]) * param_4;
      puVar6[-1] = (((char)(iVar7 / 100) + (char)(iVar7 >> 0x1f)) -
                   (char)((longlong)iVar7 * 0x51eb851f >> 0x3f)) + puVar8[1];
      *puVar6 = puVar8[2];
    }
    intense[0] = intense[0] + 1;
    puVar8 = puVar8 + 4;
    puVar6 = puVar6 + 4;
  } while (intense[0] < 0x100);
  return;
}

// --------------------------------------------------

// Function: RGE_fade_palette
// Address: 004240b0
// XREFS: set_focus
// [HELPER] s_C__msdev_work_age1_x1_color_cpp: "C:\msdev\work\age1_x1\color.cpp"
/* WARNING: Variable defined which should be unmapped: delta_time */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl RGE_fade_palette(class TDrawArea *,struct tagPALETTEENTRY,float,unsigned char,struct
   tagPALETTEENTRY *,int,int) */

void __cdecl
RGE_fade_palette(TDrawArea *param_1,tagPALETTEENTRY param_2,float param_3,uchar param_4,
                tagPALETTEENTRY *param_5,int param_6,int param_7)
{
  float fVar1;
  bool bVar2;
  int iVar3;
  uchar *puVar4;
  uchar *puVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  tagPALETTEENTRY *ptVar9;
  float delta_time;
  uchar done;
  long old_time;
  float fade_time2;
  tagPALETTEENTRY palette1 [256];
  tagPALETTEENTRY palette2 [256];
  
  iVar3 = 0;
  do {
    (&palette1[1].peRed)[iVar3] = '\0';
    (&palette2[1].peRed)[iVar3] = '\0';
    (&palette1[1].peBlue)[iVar3] = '\0';
    (&palette2[1].peBlue)[iVar3] = '\0';
    (&palette1[1].peGreen)[iVar3] = '\0';
    (&palette2[1].peGreen)[iVar3] = '\0';
    (&palette1[1].peFlags)[iVar3] = '\0';
    (&palette2[1].peFlags)[iVar3] = '\0';
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x400);
  if (param_5 == (tagPALETTEENTRY *)0x0) {
    TDrawArea::GetPalette(param_1,palette1 + 1);
  }
  else {
    ptVar9 = palette1;
    iVar3 = 0x100;
    puVar4 = &param_5->peGreen;
    do {
      ptVar9 = ptVar9 + 1;
      puVar5 = puVar4 + 4;
      ptVar9->peRed = ((tagPALETTEENTRY *)(puVar4 + -1))->peRed;
      puVar5[(int)palette1 + (1 - (int)param_5)] = puVar4[1];
      puVar5[(int)palette1 - (int)param_5] = *puVar4;
      puVar5[(int)palette1 + (2 - (int)param_5)] = puVar4[2];
      iVar3 = iVar3 + -1;
      puVar4 = puVar5;
    } while (iVar3 != 0);
  }
  bVar2 = false;
  uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x69);
  palette1[0] = (tagPALETTEENTRY)(param_3 * param_3);
  if (param_4 != '\x01') {
    do {
      uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x88);
      fVar1 = param_3 - (float)(int)(uVar7 - uVar6) * _DAT_0056f020;
      if (((param_3 <= (float)_DAT_0056f028) || (param_3 < fVar1)) || (fVar1 < _DAT_0056f030)) {
        lVar8 = 0;
      }
      else {
        lVar8 = __ftol();
      }
      if (lVar8 < 1) {
        lVar8 = 0;
        bVar2 = true;
      }
      RGE_translate_palette(palette1 + 1,palette2 + 1,param_2,lVar8,param_6,param_7);
      TDrawArea::SetPalette(param_1,palette2 + 1);
    } while (!bVar2);
    return;
  }
  do {
                    /* language.dll match for 0x70: "B" */
    uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_color_cpp,0x70);
    fVar1 = (float)(int)(uVar7 - uVar6) * _DAT_0056f020;
    if (((param_3 <= (float)_DAT_0056f028) || (param_3 < fVar1)) || (fVar1 < _DAT_0056f030)) {
      lVar8 = 100;
    }
    else {
      lVar8 = __ftol();
    }
    if (99 < lVar8) {
      lVar8 = 100;
      bVar2 = true;
    }
    RGE_translate_palette(palette1 + 1,palette2 + 1,param_2,lVar8,param_6,param_7);
    TDrawArea::SetPalette(param_1,palette2 + 1);
  } while (!bVar2);
  return;
}

// --------------------------------------------------

// Function: color_log
// Address: 00424810
// XREFS: TShape, command_make_do, draw, handle_game_update, handle_idle, handle_paint, handle_terrain_sound, load, mouse_left_down_action, mouse_left_up_action, mouse_right_down_action, mouse_right_up_action (... +3 more)
// [HELPER] do_color_log: " "
/* WARNING: Variable defined which should be unmapped: scr_dest */
/* void __cdecl color_log(unsigned char,unsigned char,int) */

void __cdecl color_log(uchar param_1,uchar param_2,int param_3)
{
  TDrawSystem *pTVar1;
  IDirectDrawSurface *pIVar2;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  long *plStack_b8;
  IDirectDrawSurface *pIStack_b4;
  long *plStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  void *pvStack_a4;
  ulong *puStack_a0;
  tagRECT scr_dest;
  tagRECT back_dest;
  tagPOINT point;
  _DDBLTFX ddbltfx;
  
  if ((((do_color_log != '\0') && (rge_base_game != (RGE_Base_Game *)0x0)) &&
      (1 < rge_base_game->prog_mode)) &&
     ((pTVar1 = rge_base_game->draw_system, pTVar1 != (TDrawSystem *)0x0 &&
      (pTVar1->PrimarySurface != (IDirectDrawSurface *)0x0)))) {
    back_dest.right = 0;
    point.x = 10;
    back_dest.top = pTVar1->DrawArea->Width / 2 + (2 - param_3) * 0x14;
    back_dest.bottom = back_dest.top + 10;
    ddbltfx.dwSize = 0;
    point.y = back_dest.top;
    if (pTVar1->ScreenMode == '\x02') {
      pvStack_a4 = pTVar1->Wnd;
      puStack_a0 = (ulong *)&point.y;
      iStack_a8 = 0x4248b8;
      ClientToScreen();
    }
    scr_dest.bottom = point.y + 10;
    back_dest.left = ddbltfx.dwSize + 10;
    puStack_a0 = &ddbltfx.dwDDFX;
    ddbltfx.dwDDFX = 100;
    pIStack_b4 = pTVar1->PrimarySurface;
    pvStack_a4 = (void *)0x1000400;
    iStack_a8 = 0;
    plStack_b0 = &scr_dest.top;
    uStack_ac = 0;
    plStack_b8 = (long *)0x42490f;
    scr_dest.top = point.y;
    scr_dest.right = ddbltfx.dwSize;
    ddbltfx.ddckDestColorkey.dwColorSpaceLowValue = (uint)param_1;
    (**(code **)((int)*pIStack_b4 + 0x14))();
    back_dest.top = 100;
    plStack_b8 = &back_dest.top;
    uStack_bc = 0x1000400;
    pIVar2 = pTVar1->DrawArea->DrawSurface;
    uStack_c0 = 0;
    uStack_c4 = 0;
    ddbltfx.dwReserved = (uint)param_1;
    (**(code **)((int)*pIVar2 + 0x14))(pIVar2,&stack0xffffff6c);
    puStack_a0 = (ulong *)((int)puStack_a0 + 10);
    plStack_b8 = (long *)((int)plStack_b8 + 10);
    iStack_a8 = iStack_a8 + 10;
    plStack_b0 = (long *)((int)plStack_b0 + 10);
    ddbltfx.dwZDestConstBitDepth = ddbltfx.dwAlphaDestConstBitDepth & 0xff;
    (**(code **)((int)*pTVar1->PrimarySurface + 0x14))
              (pTVar1->PrimarySurface,&uStack_bc,0,0,0x1000400,&stack0xffffff6c);
    uStack_ac = 100;
    pIVar2 = pTVar1->DrawArea->DrawSurface;
    ddbltfx.dwDDROP = ddbltfx.dwAlphaDestConstBitDepth & 0xff;
    (**(code **)((int)*pIVar2 + 0x14))(pIVar2,&uStack_c4,0,0,0x1000400,&uStack_ac);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042965b
// Address: 0042965b
// XREFS: None
void __fastcall FUN_0042965b(undefined4 param_1,int param_2)
{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  TCommunications_Handler *this;
  char *pcVar5;
  char *unaff_EBX;
  undefined4 unaff_EBP;
  uint *unaff_ESI;
  uint uVar6;
  int unaff_retaddr;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  undefined2 uStack00000014;
  char *in_stack_0000001c;
  
  pcVar5 = (char *)(in_EAX + 1);
  *(char *)(in_EAX + -0x68ffbd6e) = *(char *)(in_EAX + -0x68ffbd6e) + (char)((uint)param_2 >> 8);
  *(char *)(in_EAX + -0x18ffbd6a) = *(char *)(in_EAX + -0x18ffbd6a) + (char)unaff_EBX;
  *(char *)(unaff_retaddr + -0x6f) = *(char *)(unaff_retaddr + -0x6f) + (char)((uint)unaff_EBP >> 8)
  ;
  this = (TCommunications_Handler *)CONCAT31((int3)((uint)param_1 >> 8),(char)param_1 * '\x02');
  cVar3 = (char)pcVar5;
  *(char *)(unaff_ESI + param_2 + 4) = (char)unaff_ESI[param_2 + 4] + cVar3;
  pcVar2 = (char *)((int)this + (param_2 + 5) * 4 + -0x69c9ffbe);
  *pcVar2 = *pcVar2 + cVar3;
  *pcVar5 = *pcVar5 + cVar3;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)this;
  this->OptionsChanged = this->OptionsChanged | (uint)pcVar5;
  uVar6 = CONCAT31((int3)((uint)pcVar5 >> 8),cVar3 + *unaff_EBX + '\x05');
  *unaff_ESI = *unaff_ESI | uVar6;
  pbVar1 = (byte *)(uVar6 + 0xec839090);
  *pbVar1 = *pbVar1 | (char)param_2 + 6U;
  uStack0000000c = 0x4e4e4e4e;
  uVar6 = 1;
  uStack00000010 = 0x4e4e4e4e;
  uStack00000014 = 0x4e4e;
  if (this->MaxGamePlayers != 0) {
    do {
      iVar4 = TChat::inChatGroup(this->Chat,uVar6);
      if (iVar4 != 0) {
        *(undefined1 *)((int)&stack0x0000000c + uVar6) = 0x59;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 <= this->MaxGamePlayers);
  }
  TCommunications_Handler::TXChat(this,this->Me,(uchar *)&stack0x0000000c,in_stack_0000001c);
  return;
}

// --------------------------------------------------

// Function: FUN_0042cbe3
// Address: 0042cbe3
// XREFS: None
void FUN_0042cbe3(void)
{
  return;
}

// --------------------------------------------------

// Function: StringFromGUID
// Address: 0042ec40
// XREFS: DebugSessionInformation
/* int __cdecl StringFromGUID(struct _GUID *,unsigned short *) */

int __cdecl StringFromGUID(_GUID *param_1,ushort *param_2)
{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  uint uVar3;
  
  *param_2 = 0x7b;
  pwVar1 = (wchar_t *)(param_2 + 1);
  uVar3 = 0;
  do {
    if ((&DAT_0056f218)[uVar3] == 0x2d) {
      *pwVar1 = L'-';
      pwVar2 = pwVar1;
    }
    else {
      pwVar2 = pwVar1 + 1;
      *pwVar1 = L"0123456789ABCDEF"[param_1->Data4[(byte)(&DAT_0056f218)[uVar3] - 8] >> 4];
      *pwVar2 = L"0123456789ABCDEF"[param_1->Data4[(byte)(&DAT_0056f218)[uVar3] - 8] & 0xf];
    }
    pwVar1 = pwVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x14);
  *pwVar1 = L'}';
  pwVar2[2] = L'\0';
  return 0x26;
}

// --------------------------------------------------

// Function: EnumPlayersCallback2
// Address: 0042f040
// XREFS: ForcePlayerEnumeration
// [HELPER] s_ENUM_DEBUG___s: "ENUM DEBUG: %s"
// [HELPER] s_ENUM__d_name__s_id__d: "ENUM %d name=%s id=%d"
// [HELPER] s_FILL_PLAYER_INFORMATION_: "FILL PLAYER INFORMATION."
// [HELPER] s_FORCEENUM__d_name__s_id__d: "FORCEENUM %d name=%s id=%d"
/* int __stdcall EnumPlayersCallback2(unsigned long,unsigned long,struct DPNAME *,unsigned long,void
   *) */

int EnumPlayersCallback2(ulong param_1,ulong param_2,DPNAME *param_3,ulong param_4,void *param_5)
{
  uint uVar1;
  ulong *puVar2;
  TDebuggingLog *this;
  
  if (param_1 != 0) {
    uVar1 = (uint)*(ushort *)((int)param_5 + 0x1712);
    if (uVar1 <= *(ushort *)((int)param_5 + 0x1710)) {
      puVar2 = (ulong *)((int)param_5 + uVar1 * 4 + 0x1564);
      do {
        if (*puVar2 == param_1) goto LAB_0042f07f;
        uVar1 = uVar1 + 1;
        puVar2 = puVar2 + 1;
      } while ((int)uVar1 <= (int)(uint)*(ushort *)((int)param_5 + 0x1710));
    }
  }
  uVar1 = 0;
LAB_0042f07f:
  sprintf(&DAT_0062c5f0,s_ENUM__d_name__s_id__d,param_1,(param_3->field2_0x8).lpszShortName,uVar1);
  TDebuggingLog::Log(L,(char *)L,s_ENUM_DEBUG___s,&DAT_0062c5f0);
  TDebuggingLog::Log(this,(char *)L,s_FORCEENUM__d_name__s_id__d,param_1,
                     (param_3->field2_0x8).lpszShortName,uVar1);
  TDebuggingLog::Log(L,(char *)L,s_FILL_PLAYER_INFORMATION_);
  TCommunications_Handler::UpdatePlayerInformation
            ((TCommunications_Handler *)param_5,param_1,(param_3->field2_0x8).lpszShortNameA,
             (param_3->field3_0xc).lpszLongNameA);
  return 1;
}

// --------------------------------------------------

// Function: EnumPlayersCallbackLobby
// Address: 0042f3a0
// XREFS: CheckForLobbyLaunch
// [HELPER] s_ENUMPLAYER__DPID____ld: "ENUMPLAYER: DPID = %ld"
// [HELPER] s_ENUMPLAYER__NAME____s: "ENUMPLAYER: NAME = %s"
// [HELPER] s_Local_Player: "Local Player"
// [HELPER] s_Remote_Player: "Remote Player"
// [HELPER] s_____Enumeration_not_done: "+++ Enumeration not done"
/* int __stdcall EnumPlayersCallbackLobby(unsigned long,unsigned long,struct DPNAME *,unsigned
   long,void *) */

int EnumPlayersCallbackLobby
              (ulong param_1,ulong param_2,DPNAME *param_3,ulong param_4,void *param_5)
{
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  
  TDebuggingLog::Log(L,(char *)L,s_ENUMPLAYER__DPID____ld,param_1);
  TDebuggingLog::Log(L,(char *)L,s_ENUMPLAYER__NAME____s,(param_3->field2_0x8).lpszShortName);
  TDebuggingLog::Log(this,(char *)L,s_____Enumeration_not_done);
  if ((param_4 & 0x10) != 0) {
    TDebuggingLog::Log(this_00,(char *)L,s_Remote_Player);
  }
  if ((param_4 & 8) != 0) {
    TDebuggingLog::Log(L,(char *)L,s_Local_Player);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0042f81e
// Address: 0042f81e
// XREFS: None
/* WARNING: Removing unreachable block (ram,0x0042f842) */
/* WARNING: Removing unreachable block (ram,0x0042f8d4) */
/* WARNING: Removing unreachable block (ram,0x0042f8d6) */
/* WARNING: Removing unreachable block (ram,0x0042f8db) */
/* WARNING: Removing unreachable block (ram,0x0042f8dd) */
/* WARNING: Removing unreachable block (ram,0x0042f8f9) */
/* WARNING: Removing unreachable block (ram,0x0042f90d) */

undefined4 __fastcall FUN_0042f81e(int param_1,char param_2)
{
  undefined1 in_AL;
  
  uRamc10042f7 = in_AL;
  *(char *)(param_1 + -0x76) = *(char *)(param_1 + -0x76) + param_2;
  return 0;
}

// --------------------------------------------------

// Function: DPEnumCallback
// Address: 00432180
// XREFS: TCommunications_Services
/* int __stdcall DPEnumCallback(struct _GUID *,char *,unsigned long,unsigned long,void *) */

int DPEnumCallback(_GUID *param_1,char *param_2,ulong param_3,ulong param_4,void *param_5)
{
  void *this;
  int iVar1;
  int iVar2;
  
  this = param_5;
  iVar1 = TCommunications_Services::GetServiceCount((TCommunications_Services *)param_5);
  TCommunications_Services::SetServiceName((TCommunications_Services *)this,iVar1,param_2);
  TCommunications_Services::EnumServiceGUID((TCommunications_Services *)this,iVar1,param_1);
  iVar2 = _DirectPlayCreate_12(param_1,&param_5,0);
  if (iVar2 == 0) {
    TCommunications_Services::SetServiceActive((TCommunications_Services *)this,iVar1,1);
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*param_5 + 8))(param_5);
    TCommunications_Services::IncServiceCount((TCommunications_Services *)this);
    return 1;
  }
  TCommunications_Services::SetServiceActive((TCommunications_Services *)this,iVar1,0);
  TCommunications_Services::IncServiceCount((TCommunications_Services *)this);
  return 1;
}

// --------------------------------------------------

// Function: EnumSessionCallback
// Address: 00432560
// XREFS: Refresh
/* int __stdcall EnumSessionCallback(struct DPSESSIONDESC2 *,unsigned long *,unsigned long,void *)
    */

int EnumSessionCallback(DPSESSIONDESC2 *param_1,ulong *param_2,ulong param_3,void *param_4)
{
  if ((param_3 & 1) != 0) {
    return 0;
  }
  TCommunications_Sessions::AddSession
            ((TCommunications_Sessions *)param_4,param_1->guidInstance,param_1->guidApplication,
             param_1->dwMaxPlayers,param_1->dwCurrentPlayers,(param_1->field6_0x30).lpszSessionNameA
             ,(param_1->field7_0x34).lpszPasswordA,param_1->dwUser1,param_1->dwUser2,
             param_1->dwUser3,param_1->dwUser4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00434d07
// Address: 00434d07
// XREFS: None
void __fastcall FUN_00434d07(int param_1,int param_2)
{
  char *pcVar1;
  undefined4 in_EAX;
  RGE_Static_Object *this;
  int iVar2;
  char *pcVar3;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  int in_stack_00000002;
  char *pcVar4;
  
  pcVar4 = (char *)(unaff_EDI + 1);
  iVar2 = CONCAT31((int3)((uint)(param_2 + -1) >> 8),(char)(param_2 + -1) * '\x02') + -3;
  iVar2 = CONCAT31((int3)((uint)iVar2 >> 8),(char)iVar2 * '\x02') + -1;
  pcVar3 = (char *)(CONCAT31((int3)((uint)iVar2 >> 8),(char)iVar2 * '\x02') + -1);
  *(char *)(unaff_ESI + 0x4b) = *(char *)(unaff_ESI + 0x4b) + (char)((uint)param_1 >> 8);
  *(char *)(unaff_EBX + -0x7ffbcae) = *(char *)(unaff_EBX + -0x7ffbcae) + (char)((uint)pcVar3 >> 8);
  *pcVar4 = *pcVar4 + (char)pcVar3;
  (&stack0x00000042)[param_1 * 2] = (&stack0x00000042)[param_1 * 2] + (char)((uint)in_EAX >> 8);
  *pcVar3 = *pcVar3 + (char)((uint)(unaff_EBX + 8) >> 8);
  pcVar1 = (char *)(CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX << 2) + -0x6f6f6f70);
  *pcVar1 = *pcVar1 + (char)pcVar3;
  this = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 4),*(int *)(in_stack_00000002 + 4));
  if (this != (RGE_Static_Object *)0x0) {
    RGE_Static_Object::removeAllFromPathingGroup(this);
    (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x40) +
                           (uint)*(byte *)(in_stack_00000002 + 1) * 4) + 0x34))
              (*(undefined1 *)(in_stack_00000002 + 2),*(undefined4 *)(in_stack_00000002 + 4),
               (int)*(short *)(in_stack_00000002 + 8),*(undefined4 *)(in_stack_00000002 + 0xc),
               *(undefined1 *)(in_stack_00000002 + 0x10),*(undefined4 *)(in_stack_00000002 + 0x14),
               *(undefined4 *)(in_stack_00000002 + 0x18),*(undefined4 *)(in_stack_00000002 + 0x1c),
               *(undefined4 *)(in_stack_00000002 + 0x20),*(undefined1 *)(in_stack_00000002 + 0x24),
               *(undefined1 *)(in_stack_00000002 + 0x25),*(undefined1 *)(in_stack_00000002 + 10),
               pcVar4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00435247
// Address: 00435247
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Command_cp: "C:\msdev\work\age1_x1\Command.cpp"
uchar __fastcall FUN_00435247(RGE_Command *param_1,int param_2,int param_3)
{
  char *pcVar1;
  uchar uVar2;
  char cVar4;
  uint in_EAX;
  ulong uVar3;
  int unaff_EBX;
  uchar *unaff_retaddr;
  
  *(char *)(unaff_EBX + 1) = *(char *)(unaff_EBX + 1) + (char)((uint)param_2 >> 8);
  cVar4 = (char)((in_EAX & 0xffffff52) >> 8);
  *(char *)(param_2 * 3) = *(char *)(param_2 * 3) + cVar4;
  *(char *)(param_2 * 3) = *(char *)(param_2 * 3) + cVar4;
  pcVar1 = (char *)((in_EAX & 0xffffff52) + 0x90909090);
  *pcVar1 = *pcVar1 + (char)param_2;
  if (((param_1->last_order != (uchar *)0x0) && (param_1->last_order_size == param_3)) &&
     (*param_1->last_order == *unaff_retaddr)) {
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Command_cp,0x497);
    if ((int)(uVar3 - param_1->last_order_time) < 500) {
      uVar2 = RGE_Command::close_check_for_duplicate_orders(param_1,unaff_retaddr);
      return uVar2;
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_00437bd9
// Address: 00437bd9
// XREFS: None
void FUN_00437bd9(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0043804d
// Address: 0043804d
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0043804d(int param_1,undefined4 param_2,short param_3,short param_4,uchar param_5,short param_6)
{
  short sVar1;
  short sVar2;
  char *unaff_EBX;
  int iVar3;
  int iVar4;
  
  *unaff_EBX = *unaff_EBX + '%';
  *unaff_EBX = *unaff_EBX + '\x05';
  *unaff_EBX = *unaff_EBX + '-';
  *unaff_EBX = *unaff_EBX + 'S';
  sVar2 = *(short *)(param_1 + 0x130);
  iVar3 = *(int *)(param_1 + 300);
  sVar1 = __ftol();
  sVar2 = *(short *)(iVar3 + -0x24 + (((int)sVar2 + (int)param_4) - (int)param_3) * 0x24);
  sVar1 = *(short *)(*(int *)(param_1 + 0x128) + 2 + sVar2 * 6) + *(short *)(param_1 + 0xc) + sVar1;
  sVar2 = *(short *)(param_1 + 0x10) + *(short *)(param_1 + 0x134) + sVar2;
  if (param_6 == 1) {
    TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),sVar1 + -1,sVar2 + -1,sVar1 + 1,sVar2 + 1,
                        param_5);
    return;
  }
  if (param_6 != 2) {
    if (param_6 == 3) {
      iVar4 = (int)sVar2;
      iVar3 = (int)sVar1;
      TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),iVar3 + -3,iVar4,iVar3 + 3,iVar4 + 1,
                          param_5);
      TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),iVar3 + -2,iVar4 + -1,iVar3 + 2,iVar4 + 2,
                          param_5);
      return;
    }
    if (param_6 == 4) {
      TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),sVar1 + -2,sVar2 + -2,sVar1 + 2,sVar2 + 2,
                          param_5);
    }
    return;
  }
  iVar4 = (int)sVar2;
  iVar3 = (int)sVar1;
  TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),iVar3,iVar4 + -1,iVar3,iVar4 + 1,param_5);
  TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),iVar3 + -1,iVar4,iVar3 + 1,iVar4,param_5);
  return;
}

// --------------------------------------------------

// Function: DibBlt
// Address: 00438820
// XREFS: Copy, DibWriteClipped, Draw, TileDibBlt, TransDibBlt
/* WARNING: Variable defined which should be unmapped: DestOrien */
/* void __cdecl DibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT
   *,long,long,long,long,struct BITMAPINFO256 *,unsigned char *,long,long,long,long,int,int,int) */

void __cdecl
DibBlt(BITMAPINFO256 *param_1,uchar *param_2,tagRECT *param_3,long param_4,long param_5,long param_6
      ,long param_7,BITMAPINFO256 *param_8,uchar *param_9,long param_10,long param_11,long param_12,
      long param_13,int param_14,int param_15,int param_16)
{
  long *plVar1;
  BITMAPINFO256 *pBVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  uchar *puVar10;
  long **pplVar11;
  uchar *puVar12;
  long DestOrien;
  long DestTotHgt;
  int local_4;
  
  iVar9 = param_16;
  pBVar2 = param_1;
  if ((param_14 != 0) &&
     (iVar3 = ClipDibBlt(param_1,param_3,&param_4,&param_5,&param_6,&param_7,&param_10,&param_11,
                         &param_12,&param_13,param_15,param_16), iVar3 == 0)) {
    return;
  }
  GetDibDim(pBVar2,&param_14,&local_4,&DestTotHgt);
  GetDibDim(param_8,&param_16,(long *)&param_3,(long *)&param_1);
  if (iVar9 != 0) {
    param_1 = (BITMAPINFO256 *)-(int)param_1;
  }
  iVar3 = (param_12 << 8) / param_6;
  iVar4 = (param_13 << 8) / param_7;
  iVar9 = param_5;
  if (DestTotHgt != 1) {
    iVar9 = (local_4 - param_5) + -1;
  }
  puVar12 = param_2 + param_14 * iVar9 + param_4;
  if ((iVar3 == 0x100) && (iVar4 == 0x100)) {
    if (param_15 == 0) {
      iVar9 = param_11;
      if (param_1 != (BITMAPINFO256 *)0x1) {
        iVar9 = (int)param_3 + (-1 - param_11);
      }
      iVar9 = param_16 * iVar9;
      param_14 = DestTotHgt * param_14;
      param_16 = (int)param_1 * param_16;
      puVar10 = param_9 + iVar9 + param_10;
      iVar9 = 0;
      if (param_7 < 1) {
        return;
      }
      param_8 = (BITMAPINFO256 *)0x100;
      do {
        memcpy(puVar12,puVar10,param_6);
        puVar12 = puVar12 + param_14;
        puVar10 = puVar10 + param_16;
        iVar9 = iVar9 + 1;
      } while (iVar9 < param_7);
      return;
    }
  }
  else if (param_15 == 0) {
    if (0 < param_6) {
      pplVar11 = &SrcXTbl;
      lVar5 = param_10;
      lVar8 = param_6;
      do {
        *pplVar11 = (long *)(lVar5 >> 8);
        lVar5 = lVar5 + iVar3;
        lVar8 = lVar8 + -1;
        pplVar11 = pplVar11 + 1;
      } while (lVar8 != 0);
    }
    goto LAB_00438a00;
  }
  if (-1 < param_6 + -1) {
    pplVar11 = &SrcXTbl + param_6 + -1;
    lVar5 = param_10;
    lVar8 = param_6;
    do {
      *pplVar11 = (long *)(lVar5 >> 8);
      lVar5 = lVar5 + iVar3;
      lVar8 = lVar8 + -1;
      pplVar11 = pplVar11 + -1;
    } while (lVar8 != 0);
  }
LAB_00438a00:
  iVar9 = param_11 << 8;
  param_15 = 0;
  if (0 < param_7) {
    do {
      iVar3 = iVar9 >> 8;
      if (param_1 != (BITMAPINFO256 *)0x1) {
        iVar3 = (int)param_3 + (-1 - iVar3);
      }
      if (0 < param_6) {
        pplVar11 = &SrcXTbl;
        iVar6 = 0;
        do {
          plVar1 = *pplVar11;
          iVar7 = iVar6 + 1;
          pplVar11 = pplVar11 + 1;
          puVar12[iVar6] = param_9[(int)plVar1 + iVar3 * param_16 + param_10];
          iVar6 = iVar7;
        } while (iVar7 < param_6);
      }
      iVar9 = iVar9 + iVar4;
      puVar12 = puVar12 + DestTotHgt * param_14;
      param_15 = param_15 + 1;
    } while (param_15 < param_7);
  }
  return;
}

// --------------------------------------------------

// Function: TransDibBlt
// Address: 00438aa0
// XREFS: Copy, Draw, TileDibBlt
/* WARNING: Variable defined which should be unmapped: SrcTotHgt */
/* void __cdecl TransDibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT
   *,long,long,long,long,struct BITMAPINFO256 *,unsigned char *,struct TRANSINFO
   *,long,long,long,long,int,int,int,int) */

void __cdecl
TransDibBlt(BITMAPINFO256 *param_1,uchar *param_2,tagRECT *param_3,long param_4,long param_5,
           long param_6,long param_7,BITMAPINFO256 *param_8,uchar *param_9,TRANSINFO *param_10,
           long param_11,long param_12,long param_13,long param_14,int param_15,int param_16,
           int param_17,int param_18)
{
  byte bVar1;
  BITMAPINFO256 *pBVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  TRANSINFO *pTVar9;
  long **pplVar10;
  uchar *puVar11;
  long SrcTotHgt;
  long sySkip;
  long DestOrien;
  long DestTotHgt;
  int local_4;
  
  iVar6 = param_17;
  pTVar9 = param_10;
  pBVar2 = param_1;
  if ((param_10 != (TRANSINFO *)0x0) && (param_10->AnyTrans == 0)) {
    DibBlt(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_11,param_12
           ,param_13,param_14,param_15,param_16,param_17);
    return;
  }
  if (param_18 < 0) {
    param_18 = 0;
  }
  if ((param_15 == 0) ||
     (iVar3 = ClipDibBlt(param_1,param_3,&param_4,&param_5,&param_6,&param_7,&param_11,&param_12,
                         &param_13,&param_14,param_16,param_17), iVar3 != 0)) {
    iVar3 = (param_13 << 8) / param_6;
    DestOrien = (param_14 << 8) / param_7;
    GetDibDim(pBVar2,&param_15,&local_4,&DestTotHgt);
    GetDibDim(param_8,(long *)&param_1,&sySkip,&param_17);
    if (iVar6 != 0) {
      param_17 = -param_17;
    }
    param_3 = (tagRECT *)((param_6 << 8) / param_13);
    iVar6 = param_5;
    if (DestTotHgt != 1) {
      iVar6 = (local_4 - param_5) + -1;
    }
    puVar11 = param_2 + param_15 * iVar6 + param_4;
    if (param_16 == 0) {
      if (0 < param_6) {
        pplVar10 = &SrcXTbl;
        lVar5 = param_11;
        lVar7 = param_6;
        do {
          *pplVar10 = (long *)(lVar5 >> 8);
          lVar5 = lVar5 + iVar3;
          lVar7 = lVar7 + -1;
          pplVar10 = pplVar10 + 1;
          pTVar9 = param_10;
        } while (lVar7 != 0);
      }
    }
    else if (-1 < param_6 + -1) {
      pplVar10 = &SrcXTbl + param_6 + -1;
      lVar5 = param_11;
      lVar7 = param_6;
      do {
        *pplVar10 = (long *)(lVar5 >> 8);
        lVar5 = lVar5 + iVar3;
        lVar7 = lVar7 + -1;
        pplVar10 = pplVar10 + -1;
        pTVar9 = param_10;
      } while (lVar7 != 0);
    }
    if (((param_16 == 0) && (pTVar9 != (TRANSINFO *)0x0)) &&
       (param_8 = (BITMAPINFO256 *)pTVar9->LineInfo, param_8 != (BITMAPINFO256 *)0x0)) {
      param_15 = DestTotHgt * param_15;
      param_10 = (TRANSINFO *)(param_12 << 8);
      param_16 = 0;
      if (0 < param_7) {
        do {
          iVar3 = (int)param_10 >> 8;
          iVar6 = iVar3;
          if (param_17 != 1) {
            iVar6 = (sySkip - iVar3) + -1;
          }
          iVar6 = iVar6 * (int)param_1 + param_11;
          if (param_8->bmiColors[iVar3 * 4 + -10] == (tagRGBQUAD)0x0) {
            if ((int)param_8->bmiColors[iVar3 * 4 + -8] < param_11) {
              iVar8 = 0;
            }
            else {
              iVar8 = ((int)param_8->bmiColors[iVar3 * 4 + -8] - param_11) * (int)param_3 >> 8;
            }
            iVar4 = (((int)param_8->bmiColors[iVar3 * 4 + -7] - param_11) + 1) * (int)param_3 >> 8;
            if (param_6 < iVar4) {
              iVar4 = param_6;
            }
            if (iVar8 < iVar4) {
              if ((param_3 == (tagRECT *)0x100) &&
                 (param_8->bmiColors[iVar3 * 4 + -9] != (tagRGBQUAD)0x0)) {
                memcpy(puVar11 + iVar8,param_9 + iVar8 + iVar6,iVar4 - iVar8);
              }
              else if (iVar8 < iVar4) {
                pplVar10 = &SrcXTbl + iVar8;
                do {
                  bVar1 = param_9[(int)*pplVar10 + iVar6];
                  param_2 = (uchar *)CONCAT31(param_2._1_3_,bVar1);
                  if ((uint)bVar1 != param_18) {
                    puVar11[iVar8] = bVar1;
                  }
                  iVar8 = iVar8 + 1;
                  pplVar10 = pplVar10 + 1;
                } while (iVar8 < iVar4);
              }
            }
          }
          puVar11 = puVar11 + param_15;
          param_10 = (TRANSINFO *)((int)&param_10->AnyTrans + DestOrien);
          param_16 = param_16 + 1;
        } while (param_16 < param_7);
        return;
      }
    }
    else {
      param_16 = 0;
      iVar6 = param_12 << 8;
      if (0 < param_7) {
        do {
          iVar3 = iVar6 >> 8;
          if (param_17 != 1) {
            iVar3 = (sySkip - iVar3) + -1;
          }
          iVar8 = 0;
          if (0 < param_6) {
            pplVar10 = &SrcXTbl;
            do {
              param_2 = (uchar *)(uint)param_9[(int)*pplVar10 + iVar3 * (int)param_1 + param_11];
              if (param_2 != (uchar *)param_18) {
                puVar11[iVar8] = param_9[(int)*pplVar10 + iVar3 * (int)param_1 + param_11];
              }
              iVar8 = iVar8 + 1;
              pplVar10 = pplVar10 + 1;
            } while (iVar8 < param_6);
          }
          puVar11 = puVar11 + DestTotHgt * param_15;
          iVar6 = iVar6 + DestOrien;
          param_16 = param_16 + 1;
        } while (param_16 < param_7);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: ClipDibBlt
// Address: 00438e80
// XREFS: DibBlt, TransDibBlt
/* WARNING: Variable defined which should be unmapped: ey */
/* int __cdecl ClipDibBlt(struct BITMAPINFO256 *,struct tagRECT *,long &,long &,long &,long &,long
   &,long &,long &,long &,int,int) */

int __cdecl
ClipDibBlt(BITMAPINFO256 *param_1,tagRECT *param_2,long *param_3,long *param_4,long *param_5,
          long *param_6,long *param_7,long *param_8,long *param_9,long *param_10,int param_11,
          int param_12)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long ey;
  
  if (param_2 == (tagRECT *)0x0) {
    iVar6 = 0;
    iVar7 = 0;
    iVar5 = (param_1->bmiHeader).biWidth;
    iVar2 = (param_1->bmiHeader).biHeight;
  }
  else {
    iVar6 = param_2->left;
    iVar7 = param_2->top;
    iVar5 = param_2->right + 1;
    iVar2 = param_2->bottom + 1;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar5 = iVar5 + -1;
  iVar2 = iVar2 + -1;
  iVar1 = *param_3;
  if (((((iVar1 <= iVar5) && (*param_4 <= iVar2)) && (iVar3 = *param_5, iVar6 <= iVar3 + -1 + iVar1)
       ) && ((iVar4 = *param_6, iVar7 <= iVar4 + -1 + *param_4 && (0 < iVar3)))) && (0 < iVar4)) {
    iVar3 = (*param_9 << 8) / iVar3;
    iVar4 = (*param_10 << 8) / iVar4;
    if (iVar1 < iVar6) {
      *param_3 = iVar6;
      *param_5 = *param_5 - (iVar6 - iVar1);
      iVar6 = (iVar6 - iVar1) * 0x100 * iVar3 >> 0x10;
      if (param_11 == 0) {
        *param_7 = *param_7 + iVar6;
      }
      *param_9 = *param_9 - iVar6;
    }
    iVar6 = *param_4;
    if (iVar6 < iVar7) {
      *param_4 = iVar7;
      iVar7 = iVar7 - iVar6;
      *param_6 = *param_6 - iVar7;
      iVar6 = iVar7 * 0x100 * iVar4 >> 0x10;
      if (param_12 == 0) {
        *param_8 = *param_8 + iVar6;
      }
      *param_10 = *param_10 - iVar6;
    }
    iVar6 = *param_3 + *param_5;
    if (iVar5 < iVar6 + -1) {
      iVar6 = (iVar6 - iVar5) + -1;
      *param_5 = *param_5 - iVar6;
      iVar6 = iVar6 * 0x100 * iVar3 >> 0x10;
      *param_9 = *param_9 - iVar6;
      if (param_11 != 0) {
        *param_7 = *param_7 + iVar6;
      }
    }
    iVar6 = *param_4 + *param_6;
    if (iVar2 < iVar6 + -1) {
      iVar6 = (iVar6 - iVar2) + -1;
      *param_6 = *param_6 - iVar6;
      iVar6 = iVar6 * 0x100 * iVar4 >> 0x10;
      *param_10 = *param_10 - iVar6;
      if (param_12 != 0) {
        *param_8 = *param_8 + iVar6;
      }
    }
    if (((0 < *param_5) && (0 < *param_6)) && ((0 < *param_9 && (0 < *param_10)))) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: GetDibDim
// Address: 00439060
// XREFS: DibBlt, DibCheckTrans, TransDibBlt
/* void __cdecl GetDibDim(struct BITMAPINFO256 *,long &,long &,long &) */

void __cdecl GetDibDim(BITMAPINFO256 *param_1,long *param_2,long *param_3,long *param_4)
{
  int iVar1;
  
  *param_2 = (param_1->bmiHeader).biWidth + 3U & 0xfffffffc;
  iVar1 = (param_1->bmiHeader).biHeight;
  *param_3 = iVar1;
  if (iVar1 < 0) {
    *param_3 = -iVar1;
    *param_4 = 1;
    return;
  }
  *param_4 = -1;
  return;
}

// --------------------------------------------------

// Function: TileDibBlt
// Address: 004390a0
// XREFS: Tile
/* WARNING: Variable defined which should be unmapped: SrcBotHgt */
/* long __cdecl TileDibBlt(struct BITMAPINFO256 *,unsigned char *,struct tagRECT
   *,long,long,long,long,long,long,struct BITMAPINFO256 *,unsigned char *,struct TRANSINFO
   *,long,long,long,long,int,int,int) */

long __cdecl
TileDibBlt(BITMAPINFO256 *param_1,uchar *param_2,tagRECT *param_3,long param_4,long param_5,
          long param_6,long param_7,long param_8,long param_9,BITMAPINFO256 *param_10,
          uchar *param_11,TRANSINFO *param_12,long param_13,long param_14,long param_15,
          long param_16,int param_17,int param_18,int param_19)
{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  long lVar15;
  long SrcBotHgt;
  long SrcRtWid;
  long DestBotHgt;
  long SrcTopHgt;
  long SrcLtWid;
  
  iVar3 = param_19;
  iVar1 = param_18;
  if (param_13 < 0) {
    param_13 = param_13 + param_15;
  }
  if (param_14 < 0) {
    param_14 = param_14 + param_16;
  }
  for (; param_15 <= param_13; param_13 = param_13 - param_15) {
  }
  for (; param_16 <= param_14; param_14 = param_14 - param_16) {
  }
  iVar4 = param_15 - param_13;
  iVar13 = param_16 - param_14;
  iVar7 = param_15 - iVar4;
  iVar9 = param_13 - iVar7;
  iVar11 = param_16 - iVar13;
  iVar10 = param_14 - iVar11;
  iVar12 = (iVar4 * 0x10000) / ((param_15 << 8) / param_8) >> 8;
  iVar8 = param_8 - iVar12;
  iVar14 = (iVar13 * 0x10000) / ((param_16 << 8) / param_9) >> 8;
  iVar5 = param_9 - iVar14;
  if ((param_8 < param_6) || (param_9 < param_7)) {
    iVar6 = param_6 / param_8;
    bVar2 = iVar6 * param_8 < param_6;
    param_6 = iVar6;
    if (bVar2) {
      param_6 = iVar6 + 1;
    }
    iVar6 = param_7 / param_9;
    bVar2 = iVar6 * param_9 < param_7;
    param_7 = iVar6;
    if (bVar2) {
      param_7 = iVar6 + 1;
    }
  }
  else {
    param_7 = 1;
    param_6 = 1;
  }
  if (param_17 == 0) {
    param_12 = (TRANSINFO *)param_5;
    if (0 < param_7) {
      param_17 = param_7;
      do {
        iVar1 = (int)&param_12->AnyTrans + iVar14;
        if (0 < param_6) {
          param_19 = param_6;
          lVar15 = param_4;
          do {
            if (iVar14 != 0) {
              if (iVar12 != 0) {
                DibBlt(param_1,param_2,param_3,lVar15,(long)param_12,iVar12,iVar14,param_10,param_11
                       ,param_13,param_14,iVar4,iVar13,1,param_18,iVar3);
              }
              if (iVar8 != 0) {
                DibBlt(param_1,param_2,param_3,lVar15 + iVar12,(long)param_12,iVar8,iVar14,param_10,
                       param_11,iVar9,param_14,iVar7,iVar13,1,param_18,iVar3);
              }
            }
            if (iVar5 != 0) {
              if (iVar12 != 0) {
                DibBlt(param_1,param_2,param_3,lVar15,iVar1,iVar12,iVar5,param_10,param_11,param_13,
                       iVar10,iVar4,iVar11,1,param_18,iVar3);
              }
              if (iVar8 != 0) {
                DibBlt(param_1,param_2,param_3,lVar15 + iVar12,iVar1,iVar8,iVar5,param_10,param_11,
                       iVar9,iVar10,iVar7,iVar11,1,param_18,iVar3);
              }
            }
            lVar15 = lVar15 + param_8;
            param_19 = param_19 + -1;
          } while (param_19 != 0);
        }
        param_12 = (TRANSINFO *)((int)&param_12->AnyTrans + param_9);
        param_17 = param_17 + -1;
      } while (param_17 != 0);
    }
  }
  else if (0 < param_7) {
    param_17 = param_7;
    do {
      if (0 < param_6) {
        param_18 = param_6;
        lVar15 = param_4;
        do {
          if (iVar14 != 0) {
            if (iVar12 != 0) {
              TransDibBlt(param_1,param_2,param_3,lVar15,param_5,iVar12,iVar14,param_10,param_11,
                          param_12,param_13,param_14,iVar4,iVar13,1,iVar1,param_19,0);
            }
            if (iVar8 != 0) {
              TransDibBlt(param_1,param_2,param_3,lVar15 + iVar12,param_5,iVar8,iVar14,param_10,
                          param_11,param_12,iVar9,param_14,iVar7,iVar13,1,iVar1,param_19,0);
            }
          }
          if (iVar5 != 0) {
            if (iVar12 != 0) {
              TransDibBlt(param_1,param_2,param_3,lVar15,param_5 + iVar14,iVar12,iVar5,param_10,
                          param_11,param_12,param_13,iVar10,iVar4,iVar11,1,iVar1,param_19,0);
            }
            if (iVar8 != 0) {
              TransDibBlt(param_1,param_2,param_3,lVar15 + iVar12,param_5 + iVar14,iVar8,iVar5,
                          param_10,param_11,param_12,iVar9,iVar10,iVar7,iVar11,1,iVar1,param_19,0);
            }
          }
          lVar15 = lVar15 + param_8;
          param_18 = param_18 + -1;
        } while (param_18 != 0);
      }
      param_5 = param_5 + param_9;
      param_17 = param_17 + -1;
    } while (param_17 != 0);
    return param_7 * param_6;
  }
  return param_7 * param_6;
}

// --------------------------------------------------

// Function: DibCheckTrans
// Address: 004395a0
// XREFS: Load, TPicture
/* WARNING: Variable defined which should be unmapped: h */
/* int __cdecl DibCheckTrans(struct BITMAPINFO256 *,struct TRANSINFO *,unsigned char *) */

int __cdecl DibCheckTrans(BITMAPINFO256 *param_1,TRANSINFO *param_2,uchar *param_3)
{
  BITMAPINFO256 *pBVar1;
  long lVar2;
  LINEINFO *pLVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long h;
  int AnyTrans;
  long tw;
  long w;
  long orien;
  int local_4;
  
  GetDibDim(param_1,&w,&AnyTrans,&local_4);
  iVar7 = (param_1->bmiHeader).biWidth;
  orien = iVar7;
  pLVar3 = (LINEINFO *)malloc(AnyTrans << 4);
  param_2->LineInfo = pLVar3;
  if (pLVar3 == (LINEINFO *)0x0) {
    return 1;
  }
  tw = 0;
  param_1 = (BITMAPINFO256 *)0x0;
  if (0 < AnyTrans) {
    iVar9 = 0;
    do {
      iVar10 = 1;
      pBVar1 = param_1;
      if (local_4 != 1) {
        pBVar1 = (BITMAPINFO256 *)((AnyTrans - (int)param_1) + -1);
      }
      iVar4 = w * (int)pBVar1;
      iVar5 = 0;
      iVar11 = iVar7;
      if (0 < iVar7) {
        do {
          if (param_3[iVar5 + iVar4] == '\0') {
            if (tw == 0) {
              tw = 1;
            }
          }
          else if (iVar10 != 0) {
            iVar10 = 0;
            iVar11 = iVar5;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar7);
      }
      iVar6 = iVar11;
      iVar5 = iVar11;
      if (iVar10 == 0) {
        while (iVar5 = iVar5 + 1, iVar5 < iVar7) {
          if (param_3[iVar5 + iVar4] != '\0') {
            iVar6 = iVar5;
          }
        }
      }
      uVar8 = 1;
      iVar7 = iVar11;
      if (iVar10 == 0) {
        for (; iVar7 <= iVar6; iVar7 = iVar7 + 1) {
          if (param_3[iVar7 + iVar4] == '\0') {
            uVar8 = 0;
            break;
          }
        }
      }
      *(int *)((int)&param_2->LineInfo->AllTrans + iVar9) = iVar10;
      *(undefined4 *)((int)&param_2->LineInfo->MidSolid + iVar9) = uVar8;
      *(int *)((int)&param_2->LineInfo->StartX + iVar9) = iVar11;
      *(int *)((int)&param_2->LineInfo->EndX + iVar9) = iVar6;
      param_1 = (BITMAPINFO256 *)((int)&(param_1->bmiHeader).biSize + 1);
      iVar7 = orien;
      iVar9 = iVar9 + 0x10;
    } while ((int)param_1 < AnyTrans);
  }
  lVar2 = tw;
  param_2->AnyTrans = tw;
  if (tw == 0) {
    free(param_2->LineInfo);
  }
  return lVar2;
}

// --------------------------------------------------

// Function: GetPaletteFromDib
// Address: 00439700
// XREFS: None
/* void * __cdecl GetPaletteFromDib(char *,int) */

void * __cdecl GetPaletteFromDib(char *param_1,int param_2)
{
  tagBITMAPINFOHEADER *ptVar1;
  void *pvVar2;
  
  ptVar1 = DibOpenFile(param_1);
  if (ptVar1 == (tagBITMAPINFOHEADER *)0x0) {
    return (void *)0x0;
  }
  pvVar2 = DibCreatePalette(ptVar1);
  if (param_2 != 0) {
    CreateIdentityPalette(pvVar2);
  }
  DibFree(ptVar1);
  return pvVar2;
}

// --------------------------------------------------

// Function: ReadPalette
// Address: 00439750
// XREFS: get_palette
// [HELPER] s___: "]\n"
// [HELPER] shape_file_first: " "
/* WARNING: Variable defined which should be unmapped: data */
/* void * __cdecl ReadPalette(char *,long,int) */

void * __cdecl ReadPalette(char *param_1,long param_2,int param_3)
{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  PAL_TABLE *pPVar6;
  int iVar7;
  undefined1 *puVar8;
  char *data;
  int own_mem;
  void *hpal;
  int resDataSize;
  int local_4;
  
  iVar7 = 0;
  own_mem = 0;
  hpal = (void *)0xffffffff;
  resDataSize = 0;
  if ((((param_1 != (char *)0x0) && (*param_1 != '\0')) && (shape_file_first != '\0')) &&
     (iVar2 = __open(param_1,0x8000), iVar2 != -1)) {
    lseek(iVar2,0,2);
    uVar3 = __tell(iVar2);
    own_mem = malloc(uVar3);
    if (own_mem != 0) {
      lseek(iVar2,0,0);
      read(iVar2,own_mem,uVar3);
      hpal = (void *)0x1;
    }
    close(iVar2);
  }
  if (((own_mem == 0) && (param_2 != -1)) &&
     (own_mem = (int)RESFILE_load(0x62696e61,param_2,(int *)&hpal,&local_4), hpal == (void *)0x0)) {
    iVar2 = malloc(local_4);
    memcpy(iVar2,own_mem,local_4);
    hpal = (void *)0x1;
    own_mem = iVar2;
  }
  if (own_mem == 0) {
    return (void *)0x0;
  }
  param_1._0_3_ = CONCAT12(DAT_005837c6,s___);
  iVar2 = strtok(own_mem,&param_1);
  if (((iVar2 != 0) && (iVar2 = strtok(0,&param_1), iVar2 != 0)) &&
     (iVar2 = strtok(0,&param_1), iVar2 != 0)) {
    iVar2 = atol(iVar2);
    puVar4 = (undefined2 *)malloc(iVar2 * 4 + 8);
    param_2 = 0;
    if (puVar4 != (undefined2 *)0x0) {
      puVar4[1] = (short)iVar2;
      *puVar4 = 0x300;
      if (0 < iVar2) {
        puVar8 = (undefined1 *)((int)puVar4 + 5);
        do {
          iVar5 = strtok(0,&param_1);
          if (iVar5 == 0) break;
          uVar1 = atoi(iVar5);
          puVar8[-1] = uVar1;
          iVar5 = strtok(0,&param_1);
          if (iVar5 == 0) break;
          uVar1 = atoi(iVar5);
          *puVar8 = uVar1;
          iVar5 = strtok(0,&param_1);
          if (iVar5 == 0) break;
          uVar1 = atoi(iVar5);
          puVar8[1] = uVar1;
          puVar8[2] = 0;
          if (iVar7 == iVar2 + -1) {
            param_2 = 1;
          }
          iVar7 = iVar7 + 1;
          puVar8 = puVar8 + 4;
        } while (iVar7 < iVar2);
      }
      if (param_2 != 0) {
        if ((iVar2 == 0x100) && (-1 < (int)System_color_Table)) {
          pPVar6 = System_color_Table;
          puVar8 = &DAT_005841e5;
          do {
            *(undefined1 *)(puVar4 + (int)pPVar6 * 2 + 2) = puVar8[-1];
            *(undefined1 *)((int)puVar4 + (int)pPVar6 * 4 + 5) = *puVar8;
            *(undefined1 *)(puVar4 + (int)pPVar6 * 2 + 3) = puVar8[1];
            *(undefined1 *)((int)puVar4 + (int)pPVar6 * 4 + 7) = 0;
            pPVar6 = *(PAL_TABLE **)(puVar8 + 3);
            puVar8 = puVar8 + 8;
          } while (-1 < (int)pPVar6);
        }
        if (((param_2 != 0) && (resDataSize = CreatePalette(puVar4), param_3 != 0)) &&
           ((rge_base_game->draw_system->DrawType == '\x01' ||
            (rge_base_game->draw_system->ScreenMode == '\x01')))) {
          CreateIdentityPalette((void *)resDataSize);
        }
      }
      free(puVar4);
    }
  }
  if (hpal == (void *)0x1) {
    free(own_mem);
  }
  return (void *)resDataSize;
}

// --------------------------------------------------

// Function: DibOpenFile
// Address: 00439a10
// XREFS: GetPaletteFromDib, Load
/* WARNING: Variable defined which should be unmapped: fh */
/* struct tagBITMAPINFOHEADER * __cdecl DibOpenFile(char *) */

tagBITMAPINFOHEADER * __cdecl DibOpenFile(char *param_1)
{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  tagBITMAPINFOHEADER *ptVar4;
  ulong uVar5;
  tagBITMAPINFOHEADER *ptVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int fh;
  ulong dwBits;
  _OFSTRUCT of;
  
  iVar2 = OpenFile(param_1,&of.Reserved1,0);
  if (iVar2 == -1) {
    uVar8 = 2;
    uVar3 = GetModuleHandleA(0,param_1,2);
    iVar2 = FindResourceA(uVar3,param_1,uVar8);
    if (iVar2 != 0) {
      uVar3 = GetModuleHandleA(0,iVar2);
      uVar3 = LoadResource(uVar3);
      ptVar4 = (tagBITMAPINFOHEADER *)LockResource(uVar3);
      return ptVar4;
    }
    return (tagBITMAPINFOHEADER *)0x0;
  }
  ptVar4 = DibReadBitmapInfo(iVar2);
  if (ptVar4 == (tagBITMAPINFOHEADER *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  uVar5 = ptVar4->biClrUsed;
  of._0_4_ = ptVar4->biSizeImage;
  if ((uVar5 == 0) && (ptVar4->biBitCount < 9)) {
    uVar5 = 1 << ((byte)ptVar4->biBitCount & 0x1f);
  }
  uVar1 = ptVar4->biSize;
  iVar2 = of._0_4_ + uVar5 * 4;
  uVar3 = GlobalHandle(ptVar4);
  GlobalUnlock(uVar3);
  uVar7 = 0;
  uVar8 = GlobalHandle(ptVar4,iVar2 + uVar1,0);
  uVar8 = GlobalReAlloc(uVar8);
  ptVar6 = (tagBITMAPINFOHEADER *)GlobalLock(uVar8);
  if (ptVar6 == (tagBITMAPINFOHEADER *)0x0) {
    uVar8 = GlobalHandle(ptVar4);
    GlobalUnlock(uVar8);
    uVar8 = GlobalHandle(ptVar4);
    GlobalFree(uVar8);
    ptVar6 = (tagBITMAPINFOHEADER *)0x0;
  }
  if (ptVar6 != (tagBITMAPINFOHEADER *)0x0) {
    uVar5 = ptVar6->biClrUsed;
    if ((uVar5 == 0) && (ptVar6->biBitCount < 9)) {
      uVar5 = 1 << ((byte)ptVar6->biBitCount & 0x1f);
    }
    _hread(uVar7,(int)&ptVar6->biSize + ptVar6->biSize + uVar5 * 4,uVar3);
  }
  _lclose(uVar7);
  return ptVar6;
}

// --------------------------------------------------

// Function: ReadDibBits
// Address: 00439b50
// XREFS: None
/* WARNING: Variable defined which should be unmapped: of */
/* unsigned char * __cdecl ReadDibBits(char *) */

uchar * __cdecl ReadDibBits(char *param_1)
{
  ulong uVar1;
  int iVar2;
  tagBITMAPINFOHEADER *ptVar3;
  undefined4 uVar4;
  uchar *puVar5;
  _OFSTRUCT of;
  
  puVar5 = (uchar *)0x0;
  iVar2 = OpenFile(param_1,&of.Reserved1,0);
  if (iVar2 == -1) {
    return (uchar *)0x0;
  }
  ptVar3 = DibReadBitmapInfo(iVar2);
  if (ptVar3 != (tagBITMAPINFOHEADER *)0x0) {
    uVar1 = ptVar3->biSizeImage;
    uVar4 = GlobalHandle(ptVar3);
    GlobalUnlock(uVar4);
    uVar4 = GlobalHandle(ptVar3);
    GlobalFree(uVar4);
    puVar5 = (uchar *)malloc(uVar1);
    if (puVar5 != (uchar *)0x0) {
      _hread(iVar2,puVar5,uVar1);
    }
  }
  _lclose(iVar2);
  return puVar5;
}

// --------------------------------------------------

// Function: DibWriteClipped
// Address: 00439be0
// XREFS: None
/* int __cdecl DibWriteClipped(struct tagBITMAPINFOHEADER *,char *,long,long,long,long) */

int __cdecl
DibWriteClipped(tagBITMAPINFOHEADER *param_1,char *param_2,long param_3,long param_4,long param_5,
               long param_6)
{
  BITMAPINFO256 *pBVar1;
  ulong uVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  pBVar1 = (BITMAPINFO256 *)DibCreate(8,param_5,param_6);
  if (pBVar1 == (BITMAPINFO256 *)0x0) {
    return 0;
  }
  uVar2 = param_1->biClrUsed;
  if ((uVar2 == 0) && (param_1->biBitCount < 9)) {
    uVar2 = 1 << ((byte)param_1->biBitCount & 0x1f);
  }
  memcpy((int)&(((BITMAPINFO256 *)(pBVar1->bmiColors + -10))->bmiHeader).biSize +
         (pBVar1->bmiHeader).biSize,(int)&param_1->biSize + param_1->biSize,uVar2 << 2);
  if (param_1->biCompression == 3) {
    puVar4 = (uchar *)((int)&param_1->biPlanes + param_1->biSize);
  }
  else {
    puVar4 = (uchar *)((int)&param_1->biSize + param_1->biSize + param_1->biClrUsed * 4);
  }
  if ((pBVar1->bmiHeader).biCompression == 3) {
    puVar3 = (uchar *)((int)(pBVar1->bmiColors + -7) + (pBVar1->bmiHeader).biSize);
  }
  else {
    puVar3 = &pBVar1->bmiColors[(pBVar1->bmiHeader).biClrUsed - 10].rgbBlue +
             (pBVar1->bmiHeader).biSize;
  }
  DibBlt(pBVar1,puVar3,(tagRECT *)0x0,0,0,param_5,param_6,(BITMAPINFO256 *)param_1,puVar4,param_3,
         param_4,param_5,param_6,1,0,0);
  DibWriteFile((tagBITMAPINFOHEADER *)pBVar1,param_2);
  DibFree((tagBITMAPINFOHEADER *)pBVar1);
  return 1;
}

// --------------------------------------------------

// Function: DibWriteFile
// Address: 00439cc0
// XREFS: DibWriteClipped
/* WARNING: Variable defined which should be unmapped: hdr */
/* int __cdecl DibWriteFile(struct tagBITMAPINFOHEADER *,char *) */

int __cdecl DibWriteFile(tagBITMAPINFOHEADER *param_1,char *param_2)
{
  int iVar1;
  int iVar2;
  tagBITMAPFILEHEADER hdr;
  _OFSTRUCT of;
  
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return 0;
  }
  iVar1 = OpenFile(param_2,&of.Reserved1,0x1002);
  if (iVar1 != -1) {
    hdr.bfSize._2_2_ = 0x4d42;
    hdr.bfOffBits._0_2_ = 0;
    iVar2 = param_1->biSizeImage + param_1->biClrUsed * 4 + param_1->biSize;
    hdr.bfOffBits._2_2_ = 0;
    hdr._6_4_ = iVar2 + 0xe;
    _lwrite(iVar1,(undefined1 *)((int)&hdr.bfSize + 2),0xe);
    _hwrite(iVar1,param_1,iVar2);
    _lclose(iVar1);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: DibCreatePalette
// Address: 00439d80
// XREFS: GetPaletteFromDib
/* WARNING: Variable defined which should be unmapped: hpal */
/* void * __cdecl DibCreatePalette(struct tagBITMAPINFOHEADER *) */

void * __cdecl DibCreatePalette(tagBITMAPINFOHEADER *param_1)
{
  ulong uVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  void *unaff_ESI;
  undefined1 *puVar5;
  void *unaff_EDI;
  ulong uVar6;
  void *hpal;
  
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return (void *)0x0;
  }
  uVar6 = param_1->biClrUsed;
  if ((uVar6 == 0) && (param_1->biBitCount < 9)) {
    uVar6 = 1 << ((byte)param_1->biBitCount & 0x1f);
  }
  if ((uVar6 == 3) && (param_1->biCompression == 3)) {
    uVar6 = 0;
  }
  if ((int)uVar6 < 1) {
    uVar4 = GetDC(0);
    unaff_ESI = (void *)CreateHalftonePalette(uVar4);
    ReleaseDC(0,uVar4);
  }
  else {
    uVar1 = param_1->biSize;
    puVar2 = (undefined2 *)LocalAlloc(0x40,uVar6 * 4 + 8);
    if (puVar2 != (undefined2 *)0x0) {
      puVar2[1] = (short)uVar6;
      *puVar2 = 0x300;
      if (0 < (int)uVar6) {
        puVar3 = (undefined1 *)((int)puVar2 + 5);
        puVar5 = (undefined1 *)((int)&param_1->biSize + uVar1);
        do {
          puVar3[-1] = puVar5[2];
          *puVar3 = puVar5[1];
          puVar3[1] = *puVar5;
          puVar3[2] = 0;
          puVar3 = puVar3 + 4;
          uVar6 = uVar6 - 1;
          puVar5 = puVar5 + 4;
        } while (uVar6 != 0);
      }
      CreatePalette(puVar2);
      LocalFree(puVar2);
      return unaff_EDI;
    }
  }
                    /* Symbol Ref: {@symbol exit} */
  return unaff_ESI;
}

// --------------------------------------------------

// Function: DibReadBitmapInfo
// Address: 00439e50
// XREFS: DibOpenFile, ReadDibBits
/* WARNING: Variable defined which should be unmapped: pdib */
/* struct tagBITMAPINFOHEADER * __cdecl DibReadBitmapInfo(int) */

tagBITMAPINFOHEADER * __cdecl DibReadBitmapInfo(int param_1)
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  tagBITMAPINFOHEADER *ptVar5;
  undefined1 *puVar6;
  ulong *puVar7;
  int unaff_EBX;
  undefined4 unaff_EBP;
  ushort *puVar8;
  ulong uVar9;
  tagBITMAPINFOHEADER *ptVar10;
  tagBITMAPINFOHEADER *pdib;
  ulong off;
  tagBITMAPCOREHEADER bc;
  tagBITMAPFILEHEADER bf;
  tagBITMAPINFOHEADER bi;
  
  if (param_1 == -1) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  uVar3 = _llseek(param_1,0,1);
  iVar4 = _lread(param_1,(undefined1 *)((int)&bf.bfSize + 2),0xe);
  if (iVar4 != 0xe) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  if (bf.bfSize._2_2_ != 0x4d42) {
    _llseek(param_1,uVar3,0);
  }
  iVar4 = _lread(param_1,&bi.biWidth,0x28);
  if (iVar4 != 0x28) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  if (bi.biWidth == 0xc) {
    bf.bfType = bi.biPlanes;
    bf.bfSize._0_2_ = bi.biBitCount;
    uVar2 = (uint)bi.biHeight >> 0x10;
    bi.biHeight = bi.biHeight & 0xffff;
    bi.biWidth = 0x28;
    bi.biCompression._2_1_ = (byte)bi.biBitCount;
    bi.biCompression._3_1_ = bi.biBitCount._1_1_;
    bi.biSizeImage._0_2_ = 0;
    bi.biSizeImage._2_2_ = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;
    bi._12_4_ = uVar2;
    bi.biCompression._0_2_ = bf.bfType;
    _llseek(param_1,0xffffffe4,1);
  }
  uVar9 = bi.biClrImportant;
  if ((bi.biClrImportant == 0) && (CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) < 9)) {
    uVar9 = 1 << (bi.biCompression._2_1_ & 0x1f);
  }
  if (bi.biXPelsPerMeter == 0) {
    bi.biXPelsPerMeter =
         (bi.biHeight * (uint)CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) + 0x1f >> 3 &
         0x1ffffffc) * bi._12_4_;
  }
  if ((bi.biClrImportant == 0) && (CONCAT11(bi.biCompression._3_1_,bi.biCompression._2_1_) < 9)) {
    bi.biClrImportant = 1 << (bi.biCompression._2_1_ & 0x1f);
  }
  uVar3 = GlobalAlloc(2,bi.biWidth + uVar9 * 4);
  ptVar5 = (tagBITMAPINFOHEADER *)GlobalLock(uVar3);
  if (ptVar5 != (tagBITMAPINFOHEADER *)0x0) {
    puVar8 = &bf.bfReserved2;
    ptVar10 = ptVar5;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      ptVar10->biSize = *(ulong *)puVar8;
      puVar8 = puVar8 + 2;
      ptVar10 = (tagBITMAPINFOHEADER *)&ptVar10->biWidth;
    }
    iVar4 = (int)&ptVar5->biSize + ptVar5->biSize;
    if (uVar9 != 0) {
      if (bi.biClrImportant == 0xc) {
        _lread(param_1,iVar4,uVar9 * 3);
        iVar1 = uVar9 - 1;
        if (-1 < iVar1) {
          puVar7 = (ulong *)(iVar4 + iVar1 * 4);
          puVar6 = (undefined1 *)(uVar9 + iVar4 + iVar1 * 2);
          do {
            bi.biClrImportant._0_2_ = CONCAT11(*puVar6,puVar6[-1]);
            bi.biClrImportant = (ulong)CONCAT12(puVar6[1],(undefined2)bi.biClrImportant);
            *puVar7 = bi.biClrImportant;
            puVar7 = puVar7 + -1;
            uVar9 = uVar9 - 1;
            puVar6 = puVar6 + -3;
          } while (uVar9 != 0);
        }
      }
      else {
        _lread(param_1,iVar4,unaff_EBP);
      }
    }
    if (CONCAT22(bf.bfSize._2_2_,(ushort)bf.bfSize) != 0) {
      _llseek(param_1,CONCAT22(bf.bfSize._2_2_,(ushort)bf.bfSize) + unaff_EBX,0);
    }
    return ptVar5;
  }
  return (tagBITMAPINFOHEADER *)0x0;
}

// --------------------------------------------------

// Function: DibFromBitmap
// Address: 0043a070
// XREFS: None
/* WARNING: Variable defined which should be unmapped: nColors */
/* struct tagBITMAPINFOHEADER * __cdecl DibFromBitmap(void *,unsigned long,unsigned int,void
   *,unsigned int) */

tagBITMAPINFOHEADER * __cdecl
DibFromBitmap(void *param_1,ulong param_2,uint param_3,void *param_4,uint param_5)
{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  tagBITMAPINFOHEADER *ptVar5;
  ulong uVar6;
  ulong uVar7;
  int unaff_EBX;
  undefined4 unaff_EBP;
  int nColors;
  tagBITMAP bm;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  bm.bmType = 0;
  if (param_1 == (void *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  if (param_4 == (void *)0x0) {
    param_4 = (void *)GetStockObject(0xf);
  }
  GetObjectA(param_1,0x18,&bm.bmWidth);
  GetObjectA(param_4,4,&bm);
  if (param_3 == 0) {
    param_3 = (uint)(ushort)bm.bmBits * (uint)bm.bmBits._2_2_;
  }
  uVar1 = GlobalAlloc(2,0x428);
  piVar2 = (int *)GlobalLock(uVar1);
  if (piVar2 == (int *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  *piVar2 = 0x28;
  piVar2[1] = unaff_EBX;
  piVar2[2] = bm.bmType;
  *(undefined2 *)(piVar2 + 3) = 1;
  *(ushort *)((int)piVar2 + 0xe) = (ushort)param_3;
  piVar2[4] = CONCAT22(uStack_2,uStack_4);
  piVar2[5] = 0;
  piVar2[6] = 0;
  piVar2[7] = 0;
  piVar2[8] = 0;
  piVar2[9] = 0;
  if ((ushort)param_3 < 9) {
    iVar3 = 1 << ((byte)param_3 & 0x1f);
  }
  else {
    iVar3 = 0;
  }
  piVar2[8] = iVar3;
  if (CONCAT22(uStack_2,uStack_4) == 3) {
    if (param_3 == 0x10) {
      piVar2[10] = 0xf800;
                    /* language.dll match for 0x7e0: "Age of Empires Expansion requires Age of
                       Empires 1.0, 1.0A, or 1.0B to be installed." */
      piVar2[0xb] = 0x7e0;
      piVar2[0xc] = 0x1f;
    }
    else if ((param_3 == 0x18) || (param_3 == 0x20)) {
      piVar2[10] = 0xff;
      piVar2[0xb] = 0xff00;
      piVar2[0xc] = 0xff0000;
    }
  }
  uVar1 = CreateCompatibleDC(0);
  SelectPalette(uVar1,param_4,0);
  RealizePalette(uVar1);
  SetStretchBltMode(uVar1,4);
  GetDIBits(uVar1,param_1,0,piVar2[2],0,piVar2,param_2);
  iVar3 = piVar2[8];
  if ((iVar3 == 0) && (*(ushort *)((int)piVar2 + 0xe) < 9)) {
    iVar3 = 1 << ((byte)*(ushort *)((int)piVar2 + 0xe) & 0x1f);
  }
  piVar2[8] = iVar3;
  iVar3 = piVar2[5];
  if (iVar3 == 0) {
    iVar3 = ((uint)*(ushort *)((int)piVar2 + 0xe) * piVar2[1] + 0x1f >> 3 & 0x1ffffffc) * piVar2[2];
  }
  piVar2[5] = iVar3;
  if (iVar3 == 0) {
    iVar3 = ((uint)*(ushort *)((int)piVar2 + 0xe) * piVar2[1] + 0x1f >> 3 & 0x1ffffffc) * piVar2[2];
    piVar2[5] = iVar3;
    if (CONCAT22(uStack_2,uStack_4) != 0) {
      piVar2[5] = (uint)(iVar3 * 3) >> 1;
    }
  }
  uVar4 = GlobalHandle(piVar2);
  GlobalUnlock(uVar4);
  uVar4 = GlobalHandle(piVar2,*piVar2 + piVar2[8] * 4 + piVar2[5],0);
  uVar4 = GlobalReAlloc(uVar4);
  ptVar5 = (tagBITMAPINFOHEADER *)GlobalLock(uVar4);
  if (ptVar5 == (tagBITMAPINFOHEADER *)0x0) {
    uVar4 = GlobalHandle(piVar2);
    GlobalUnlock(uVar4);
    uVar4 = GlobalHandle(piVar2);
    GlobalFree(uVar4);
  }
  else {
    if (ptVar5->biCompression == 3) {
      iVar3 = ptVar5->biSize + 0xc;
    }
    else {
      iVar3 = ptVar5->biSize + ptVar5->biClrUsed * 4;
    }
    iVar3 = GetDIBits(uVar1,unaff_EBP,0,ptVar5->biHeight,(int)&ptVar5->biSize + iVar3,ptVar5,
                      bm.bmHeight);
    uVar7 = ptVar5->biClrUsed;
    if ((uVar7 == 0) && (ptVar5->biBitCount < 9)) {
      uVar7 = 1 << ((byte)ptVar5->biBitCount & 0x1f);
    }
    uVar6 = ptVar5->biSizeImage;
    ptVar5->biClrUsed = uVar7;
    if (uVar6 == 0) {
      uVar6 = (ptVar5->biWidth * (uint)ptVar5->biBitCount + 0x1f >> 3 & 0x1ffffffc) *
              ptVar5->biHeight;
    }
    ptVar5->biSizeImage = uVar6;
    if (iVar3 != 0) goto LAB_0043a307;
    DibFree(ptVar5);
  }
  ptVar5 = (tagBITMAPINFOHEADER *)0x0;
LAB_0043a307:
                    /* Symbol Ref: {@symbol exit} */
  SelectPalette(uVar1,bm.bmWidth,0);
  DeleteDC(uVar1);
  return ptVar5;
}

// --------------------------------------------------

// Function: DibSetUsage
// Address: 0043a330
// XREFS: None
/* WARNING: Variable defined which should be unmapped: ape */
/* int __cdecl DibSetUsage(struct tagBITMAPINFOHEADER *,void *,unsigned int) */

int __cdecl DibSetUsage(tagBITMAPINFOHEADER *param_1,void *param_2,uint param_3)
{
  undefined1 *puVar1;
  int iVar2;
  tagPALETTEENTRY *ptVar3;
  undefined2 *puVar4;
  ulong uVar5;
  tagPALETTEENTRY ape [256];
  
  if (param_2 == (void *)0x0) {
    param_2 = (void *)GetStockObject(0xf);
  }
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return 0;
  }
  uVar5 = param_1->biClrUsed;
  if ((uVar5 == 0) && (param_1->biBitCount < 9)) {
    uVar5 = 1 << ((byte)param_1->biBitCount & 0x1f);
  }
  if ((uVar5 == 3) && (param_1->biCompression == 3)) {
    uVar5 = 0;
  }
  if (0 < (int)uVar5) {
    puVar4 = (undefined2 *)((int)&param_1->biSize + param_1->biSize);
    if (param_3 == 1) {
      iVar2 = 0;
      if (0 < (int)uVar5) {
        do {
          *puVar4 = (short)iVar2;
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
        } while (iVar2 < (int)uVar5);
      }
    }
    else {
      if (0xff < (int)uVar5) {
        uVar5 = 0x100;
      }
      GetPaletteEntries(param_2,0,uVar5,ape + 1);
      if (0 < (int)uVar5) {
        ptVar3 = ape;
        puVar1 = (undefined1 *)((int)puVar4 + 1);
        do {
          ptVar3 = ptVar3 + 1;
          puVar1[1] = ptVar3->peRed;
          *puVar1 = puVar1[(int)ape + (4 - (int)puVar4)];
          puVar1[-1] = puVar1[(int)ape + (5 - (int)puVar4)];
          puVar1[2] = 0;
          puVar1 = puVar1 + 4;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
        return 1;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: DibDraw
// Address: 0043a420
// XREFS: None
/* int __cdecl DibDraw(void *,int,int,int,int,struct tagBITMAPINFOHEADER
   *,int,int,int,int,long,unsigned int) */

int __cdecl
DibDraw(void *param_1,int param_2,int param_3,int param_4,int param_5,tagBITMAPINFOHEADER *param_6,
       int param_7,int param_8,int param_9,int param_10,long param_11,uint param_12)
{
  int iVar1;
  
  if (param_6 == (tagBITMAPINFOHEADER *)0x0) {
    return (int)param_6;
  }
  if ((param_9 == -1) && (param_10 == -1)) {
    param_9 = param_6->biWidth;
    param_10 = param_6->biHeight;
  }
  if ((param_4 == -1) && (param_5 == -1)) {
    param_4 = param_9;
    param_5 = param_10;
  }
  if (param_6->biCompression == 3) {
    iVar1 = param_6->biSize + 0xc;
  }
  else {
    iVar1 = param_6->biSize + param_6->biClrUsed * 4;
  }
  iVar1 = StretchDIBits(param_1,param_2,param_3,param_4,param_5,param_7,param_8,param_9,param_10,
                        (int)&param_6->biSize + iVar1,param_6,param_12,param_11);
  return iVar1;
}

// --------------------------------------------------

// Function: DibCopy
// Address: 0043a4b0
// XREFS: None
/* struct tagBITMAPINFOHEADER * __cdecl DibCopy(struct tagBITMAPINFOHEADER *) */

tagBITMAPINFOHEADER * __cdecl DibCopy(tagBITMAPINFOHEADER *param_1)
{
  undefined4 uVar1;
  tagBITMAPINFOHEADER *ptVar2;
  
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  uVar1 = GlobalAlloc(2,param_1->biSize + param_1->biClrUsed * 4 + param_1->biSizeImage);
  ptVar2 = (tagBITMAPINFOHEADER *)GlobalLock(uVar1);
  if (ptVar2 != (tagBITMAPINFOHEADER *)0x0) {
    memcpy(ptVar2,param_1,param_1->biSize + param_1->biClrUsed * 4 + param_1->biSizeImage);
  }
  return ptVar2;
}

// --------------------------------------------------

// Function: DibCreate
// Address: 0043a500
// XREFS: DibWriteClipped
/* struct tagBITMAPINFOHEADER * __cdecl DibCreate(int,int,int) */

tagBITMAPINFOHEADER * __cdecl DibCreate(int param_1,int param_2,int param_3)
{
  undefined4 uVar1;
  tagBITMAPINFOHEADER *ptVar2;
  tagBITMAPINFOHEADER *ptVar3;
  ulong uVar4;
  int iVar5;
  long unaff_retaddr;
  
  uVar4 = (((int)(param_2 * param_1 + (param_2 * param_1 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc) *
          param_3;
  uVar1 = GlobalAlloc(0x42,uVar4 + 0x428);
  ptVar2 = (tagBITMAPINFOHEADER *)GlobalLock(uVar1);
  if (ptVar2 == (tagBITMAPINFOHEADER *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  ptVar2->biSize = 0x28;
  ptVar2->biWidth = param_2;
  ptVar2->biHeight = unaff_retaddr;
  ptVar2->biPlanes = 1;
  ptVar2->biBitCount = (ushort)param_1;
  ptVar2->biCompression = 0;
  ptVar2->biSizeImage = uVar4;
  ptVar2->biXPelsPerMeter = 0;
  ptVar2->biYPelsPerMeter = 0;
  ptVar2->biClrUsed = 0;
  ptVar2->biClrImportant = 0;
  if (param_1 == 4) {
    ptVar2->biClrUsed = 0x10;
  }
  else if (param_1 == 8) {
    ptVar2->biClrUsed = 0x100;
  }
  iVar5 = 0;
  ptVar3 = ptVar2 + 1;
  if (0 < (int)(ptVar2->biClrUsed + ((int)ptVar2->biClrUsed >> 0x1f & 0xfU)) >> 4) {
    do {
      ptVar3->biSize = 0;
      ptVar3->biWidth = 0x800000;
      ptVar3->biHeight = 0x8000;
      ptVar3->biPlanes = 0x8000;
      ptVar3->biBitCount = 0x80;
      ptVar3->biCompression = 0x80;
      ptVar3->biSizeImage = 0x800080;
      ptVar3->biXPelsPerMeter = 0x8080;
      ptVar3->biYPelsPerMeter = 0xc0c0c0;
      ptVar3->biClrUsed = 0x808080;
      ptVar3->biClrImportant = 0xff0000;
      ptVar3[1].biSize = 0xff00;
      ptVar3[1].biWidth = 0xffff00;
      ptVar3[1].biHeight = 0xff;
      ptVar3[1].biPlanes = 0xff;
      ptVar3[1].biBitCount = 0xff;
      ptVar3[1].biCompression = 0xffff;
      ptVar3[1].biSizeImage = 0xffffff;
      ptVar3 = (tagBITMAPINFOHEADER *)&ptVar3[1].biXPelsPerMeter;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(ptVar2->biClrUsed + ((int)ptVar2->biClrUsed >> 0x1f & 0xfU)) >> 4);
  }
  return ptVar2;
}

// --------------------------------------------------

// Function: DibMapToPalette
// Address: 0043a660
// XREFS: Load
/* WARNING: Variable defined which should be unmapped: ZeroIndex */
/* void __cdecl DibMapToPalette(struct tagBITMAPINFOHEADER *,void *,int,int) */

void __cdecl DibMapToPalette(tagBITMAPINFOHEADER *param_1,void *param_2,int param_3,int param_4)
{
  tagRGBQUAD *ptVar1;
  ulong uVar2;
  uchar *puVar3;
  char cVar4;
  uchar uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  tagPALETTEENTRY tVar10;
  int iVar11;
  uchar ZeroIndex;
  uchar *lpBits;
  ulong SizeImage;
  int nPalColors;
  int nDibColors;
  tagRGBQUAD *lpRgb;
  tagPALETTEENTRY pe;
  int ZeroBlue;
  uchar TransIndex;
  int HitEnd;
  uchar xlat [256];
  
  puVar3 = lpBits;
  nDibColors = 0;
  lpBits = (uchar *)((uint)lpBits & 0xffffff);
  HitEnd = HitEnd & 0xffffff00;
  if (param_2 == (void *)0x0) {
    return;
  }
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return;
  }
  tVar10 = (tagPALETTEENTRY)((int)&param_1->biSize + param_1->biSize);
  pe = tVar10;
  GetObjectA(param_2,4,&nDibColors);
  ptVar1 = (tagRGBQUAD *)param_1->biClrUsed;
  lpRgb = ptVar1;
  if ((ptVar1 == (tagRGBQUAD *)0x0) && (param_1->biBitCount < 9)) {
    lpRgb = (tagRGBQUAD *)(1 << ((byte)param_1->biBitCount & 0x1f));
  }
  nPalColors = param_1->biSizeImage;
  if (nPalColors == 0) {
    nPalColors = (param_1->biWidth * (uint)param_1->biBitCount + 0x1f >> 3 & 0x1ffffffc) *
                 param_1->biHeight;
  }
  if (param_1->biCompression == 3) {
    iVar11 = param_1->biSize + 0xc;
  }
  else {
    iVar11 = param_1->biSize + (int)ptVar1 * 4;
  }
  SizeImage = (int)&param_1->biSize + iVar11;
  if (param_3 != 0) {
    if (param_4 == 0) {
      HitEnd = CONCAT31(HitEnd._1_3_,
                        *(undefined1 *)
                         ((param_1->biWidth + 3U & 0xfffffffc) * (param_1->biHeight + -1) +
                         SizeImage));
    }
    else {
      HitEnd = (uint)HitEnd._1_3_ << 8;
    }
    uVar8 = (uint)*(byte *)((int)tVar10 + 2);
    uVar7 = (uint)*(byte *)((int)pe + 1);
    lpBits = (uchar *)((uint)puVar3 & 0xffffff);
    _TransIndex = (uint)*(byte *)pe;
    xlat[0] = '\0';
    xlat[1] = '\0';
    xlat[2] = '\0';
    xlat[3] = '\0';
    iVar11 = 1;
    do {
      uVar8 = uVar8 + iVar11;
      uVar7 = uVar7 + iVar11;
      _TransIndex = _TransIndex + iVar11;
      if ((((0xff < (int)uVar8) || (0xff < (int)uVar7)) || (0xff < (int)_TransIndex)) ||
         ((((int)uVar8 < 0 || ((int)uVar7 < 0)) || ((int)_TransIndex < 0)))) {
        if (xlat._0_4_ != 0) break;
        iVar11 = -1;
        uVar8 = (uint)*(byte *)((int)pe + 2);
        uVar7 = (uint)*(byte *)((int)pe + 1);
        _TransIndex = (uint)*(byte *)pe;
        xlat[0] = '\x01';
        xlat[1] = '\0';
        xlat[2] = '\0';
        xlat[3] = '\0';
      }
      cVar4 = GetNearestPaletteIndex
                        (param_2,(uint)CONCAT11((char)_TransIndex,(char)uVar7) << 8 | uVar8 & 0xff);
      lpBits = (uchar *)CONCAT13(cVar4,lpBits._0_3_);
    } while (cVar4 == '\0');
  }
  uVar8 = 0;
  if (0 < (int)lpRgb) {
    puVar9 = (undefined1 *)((int)pe + 2);
    do {
      if (param_3 == 0) {
        uVar5 = GetNearestPaletteIndex
                          (param_2,(uint)CONCAT21(CONCAT11(puVar9[-2],puVar9[-1]),*puVar9));
        xlat[uVar8 + 4] = uVar5;
      }
      else if (uVar8 == (HitEnd & 0xffU)) {
        xlat[uVar8 + 4] = '\0';
      }
      else {
        uVar5 = GetNearestPaletteIndex
                          (param_2,(uint)CONCAT21(CONCAT11(puVar9[-2],puVar9[-1]),*puVar9));
        xlat[uVar8 + 4] = uVar5;
        if (uVar5 == '\0') {
          xlat[uVar8 + 4] = lpBits._3_1_;
        }
      }
      uVar8 = uVar8 + 1;
      puVar9 = puVar9 + 4;
    } while ((int)uVar8 < (int)lpRgb);
  }
  param_1->biClrUsed = nDibColors;
  if ((int)lpRgb < nDibColors) {
    uVar6 = GlobalHandle(param_1);
    GlobalUnlock(uVar6);
    uVar6 = GlobalHandle(param_1,lpBits + param_1->biSize + SizeImage * 4,0);
    uVar6 = GlobalReAlloc(uVar6);
    GlobalLock(uVar6);
    if (param_1->biCompression == 3) {
      iVar11 = param_1->biSize + 0xc;
    }
    else {
      iVar11 = param_1->biSize + param_1->biClrUsed * 4;
    }
    memmove((int)&param_1->biSize + iVar11,SizeImage,lpBits);
    if (param_1->biCompression == 3) {
      SizeImage = (int)&param_1->biPlanes + param_1->biSize;
      goto LAB_0043a9a9;
    }
  }
  else {
    if ((int)lpRgb <= nDibColors) goto LAB_0043a9a9;
    if (param_1->biCompression == 3) {
      iVar11 = param_1->biSize + 0xc;
    }
    else {
      iVar11 = param_1->biSize + nDibColors * 4;
    }
    memcpy((int)&param_1->biSize + iVar11,SizeImage,nPalColors);
    uVar6 = GlobalHandle(param_1);
    GlobalUnlock(uVar6);
    uVar6 = GlobalHandle(param_1,lpBits + param_1->biSize + SizeImage * 4,0);
    uVar6 = GlobalReAlloc(uVar6);
    GlobalLock(uVar6);
    if (param_1->biCompression == 3) {
      SizeImage = (int)&param_1->biPlanes + param_1->biSize;
      goto LAB_0043a9a9;
    }
  }
  SizeImage = (int)&param_1->biSize + param_1->biSize + param_1->biClrUsed * 4;
LAB_0043a9a9:
  uVar2 = param_1->biCompression;
  if (uVar2 == 0) {
    if (param_1->biBitCount == 8) {
      xlatClut8();
    }
    else {
      xlatClut4(SizeImage,nPalColors,xlat + 4);
    }
  }
  else if (uVar2 == 1) {
    xlatRle8(SizeImage,nPalColors,xlat + 4);
  }
  else if (uVar2 == 2) {
    xlatRle4(SizeImage,nPalColors,xlat + 4);
  }
  iVar11 = 0;
  if (0 < nDibColors) {
    puVar9 = (undefined1 *)((int)pe + 1);
    do {
      GetPaletteEntries(param_2,iVar11,1,&ZeroBlue);
      iVar11 = iVar11 + 1;
      puVar9[1] = (undefined1)ZeroBlue;
      *puVar9 = ZeroBlue._1_1_;
      puVar9[-1] = ZeroBlue._2_1_;
      puVar9[2] = 0;
      puVar9 = puVar9 + 4;
    } while (iVar11 < nDibColors);
  }
  return;
}

// --------------------------------------------------

// Function: xlatClut8
// Address: 0043aa60
// XREFS: DibMapToPalette
void xlatClut8(byte *param_1,int param_2,int param_3)
{
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      *param_1 = *(byte *)((uint)*param_1 + param_3);
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: xlatClut4
// Address: 0043aa90
// XREFS: DibMapToPalette
void xlatClut4(byte *param_1,int param_2,int param_3)
{
  if (param_2 != 0) {
    do {
      *param_1 = *(byte *)((*param_1 & 0xf) + param_3) |
                 *(char *)((uint)(*param_1 >> 4) + param_3) << 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: xlatRle8
// Address: 0043aad0
// XREFS: DibMapToPalette
void xlatRle8(byte *param_1,undefined4 param_2,int param_3)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = param_1;
  while( true ) {
    do {
      while( true ) {
        pbVar3 = pbVar2;
        bVar1 = pbVar3[1];
        param_1 = (byte *)(uint)bVar1;
        if (*pbVar3 == 0) break;
        pbVar3[1] = *(byte *)((int)param_1 + param_3);
        pbVar2 = pbVar3 + 2;
      }
      pbVar2 = pbVar3 + 2;
    } while (param_1 == (byte *)0x0);
    if (param_1 == (byte *)0x1) break;
    if (param_1 == (byte *)0x2) {
      pbVar2 = pbVar3 + 4;
    }
    else {
      pbVar3 = pbVar2;
      if (bVar1 != 0) {
        do {
          pbVar2 = pbVar3 + 1;
          param_1 = (byte *)((int)param_1 - 1);
          *pbVar3 = *(byte *)(param_3 + (uint)*pbVar3);
          pbVar3 = pbVar2;
        } while (param_1 != (byte *)0x0);
      }
      if ((bVar1 & 1) != 0) {
        pbVar2 = pbVar2 + 1;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: xlatRle4
// Address: 0043ab40
// XREFS: DibMapToPalette
void xlatRle4(void)
{
  return;
}

// --------------------------------------------------

// Function: memmove
// Address: 0043ab50
// XREFS: DibMapToPalette
void memmove(int param_1,int param_2,int param_3)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)(param_1 + -1 + param_3);
  puVar2 = (undefined1 *)(param_2 + -1 + param_3);
  if (param_3 != 0) {
    do {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + -1;
      puVar2 = puVar2 + -1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: CreateIdentityPalette
// Address: 0043ab80
// XREFS: GetPaletteFromDib, ReadPalette
/* WARNING: Variable defined which should be unmapped: hdc */
/* void __cdecl CreateIdentityPalette(void *) */

void __cdecl CreateIdentityPalette(void *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  PAL_TABLE *pPVar6;
  uchar *puVar7;
  tagPALETTEENTRY tVar8;
  void *hdc;
  void *hwnd;
  tagPALETTEENTRY new_pal [256];
  tagPALETTEENTRY from_pal [256];
  
  new_pal[0] = (tagPALETTEENTRY)GetActiveWindow();
  tVar8 = new_pal[0];
  if (new_pal[0] == (tagPALETTEENTRY)0x0) {
    tVar8.peRed = '\0';
    tVar8.peGreen = '\0';
    tVar8.peBlue = '\0';
    tVar8.peFlags = '\0';
  }
  uVar1 = GetDC(tVar8);
  iVar2 = GetSystemPaletteEntries(uVar1,0,0x100,new_pal + 1);
  iVar3 = GetPaletteEntries(param_1,0,0x100,from_pal + 1);
  puVar5 = &new_pal[0xb].peFlags;
  iVar4 = 0;
  puVar7 = &from_pal[0xb].peGreen;
  do {
    (&new_pal[0xb].peRed)[iVar4] = (&from_pal[0xb].peRed)[iVar4];
    (&new_pal[0xb].peGreen)[iVar4] = *puVar7;
    puVar5[-1] = (&from_pal[0xb].peBlue)[iVar4];
    *puVar5 = '\x01';
    iVar4 = iVar4 + 4;
    puVar5 = puVar5 + 4;
    puVar7 = puVar7 + 4;
  } while (iVar4 < 0x3b0);
  if (((iVar2 == 0) || (iVar3 == 0)) && (-1 < (int)System_color_Table)) {
    puVar5 = &DAT_005841e5;
    pPVar6 = System_color_Table;
    do {
      new_pal[(int)((int)&pPVar6->index + 1)].peRed = puVar5[-1];
      new_pal[(int)((int)&pPVar6->index + 1)].peGreen = *puVar5;
      new_pal[(int)((int)&pPVar6->index + 1)].peBlue = puVar5[1];
      new_pal[(int)((int)&pPVar6->index + 1)].peFlags = '\0';
      pPVar6 = *(PAL_TABLE **)(puVar5 + 3);
      puVar5 = puVar5 + 8;
    } while (-1 < (int)pPVar6);
  }
  ReleaseDC(new_pal[0],uVar1);
  ResizePalette(param_1,0x100);
  SetPaletteEntries(param_1,0,0x100,new_pal + 1);
  return;
}

// --------------------------------------------------

// Function: CopyPalette
// Address: 0043acb0
// XREFS: None
/* WARNING: Variable defined which should be unmapped: nNumEntries */
/* void * __cdecl CopyPalette(void *) */

void * __cdecl CopyPalette(void *param_1)
{
  undefined2 *puVar1;
  void *pvVar2;
  undefined4 unaff_EDI;
  int nNumEntries;
  void *local_4;
  
  local_4 = (void *)0x0;
  if (param_1 == (void *)0x0) {
    return (void *)0x0;
  }
  GetObjectA(param_1,4,&local_4);
  if (local_4 == (void *)0x0) {
    return local_4;
  }
  puVar1 = (undefined2 *)LocalAlloc(0x40,(int)local_4 * 4 + 8);
  if (puVar1 == (undefined2 *)0x0) {
    return (void *)0x0;
  }
  *puVar1 = 0x300;
  puVar1[1] = (short)unaff_EDI;
  GetPaletteEntries(param_1,0,unaff_EDI,puVar1 + 2);
  pvVar2 = (void *)CreatePalette(puVar1);
  LocalFree(puVar1);
  return pvVar2;
}

// --------------------------------------------------

// Function: DibFree
// Address: 0043ad40
// XREFS: DibFromBitmap, DibWriteClipped, GetPaletteFromDib, Load, TPicture, ~TPicture
/* void __cdecl DibFree(struct tagBITMAPINFOHEADER *) */

void __cdecl DibFree(tagBITMAPINFOHEADER *param_1)
{
  undefined4 uVar1;
  
  uVar1 = GlobalHandle(param_1);
  GlobalUnlock(uVar1);
  uVar1 = GlobalHandle(param_1);
  GlobalFree(uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_0043ffc7
// Address: 0043ffc7
// XREFS: None
void __thiscall
FUN_0043ffc7(undefined4 param_1,TPanel *param_2,TPanel *param_3,long param_4,uchar param_5,
            int param_6,long param_7,char *param_8)
{
  char cVar1;
  TMessageDialog *this;
  int unaff_EBX;
  char *pcVar2;
  int *piVar3;
  char *unaff_retaddr;
  char acStack_108 [260];
  
  pcVar2 = (char *)(unaff_EBX + 1);
  cVar1 = (char)param_1;
  *pcVar2 = *pcVar2 + cVar1;
  *pcVar2 = *pcVar2 + '\x01';
  pcVar2 = (char *)(unaff_EBX + 2);
  *pcVar2 = *pcVar2 + cVar1;
  *pcVar2 = *pcVar2 + '\x01';
  *(char *)(unaff_EBX + 3) = *(char *)(unaff_EBX + 3) + '\x01';
  in(0xfe);
  piVar3 = (int *)(unaff_EBX + 4);
  this = (TMessageDialog *)
         CONCAT22((short)((uint)param_1 >> 0x10),
                  CONCAT11((char)((uint)param_1 >> 8) + cVar1 + (char)((uint)piVar3 >> 8),cVar1));
  *(char *)piVar3 = *(char *)piVar3 + '\x01';
  *piVar3 = *piVar3 + 1;
  *piVar3 = *piVar3 + 1;
  TPanel::get_string((TPanel *)this,param_6,acStack_108,0x100);
  TMessageDialog::setup
            (this,(TPanel *)&stack0x00000000,unaff_retaddr,(long)param_2,(long)param_3,param_4,
             param_5,acStack_108,param_7,(long)param_8);
  return;
}

// --------------------------------------------------

// Function: operator<<
// Address: 00446710
// XREFS: None
/* class ostream & __cdecl operator<<(class ostream &,class DString const &) */

ostream * __cdecl operator<<(ostream *param_1,DString *param_2)
{
  if (param_2->stringValue != (char *)0x0) {
    ostream::operator<<(param_1,param_2->stringValue);
  }
  return param_1;
}

// --------------------------------------------------

// Function: operator>>
// Address: 00446730
// XREFS: None
/* WARNING: Variable defined which should be unmapped: buffer */
/* class istream & __cdecl operator>>(class istream &,class DString &) */

istream * __cdecl operator>>(istream *param_1,DString *param_2)
{
  char buffer [256];
  
  param_1->_fGline = param_1->_fGline + 1;
  istream::get(param_1,buffer + 4,0x100,10);
  DString::operator=(param_2,buffer + 4);
  return param_1;
}

// --------------------------------------------------

// Function: operator==
// Address: 00446880
// XREFS: None
/* int __cdecl operator==(class DString const &,class DString const &) */

int __cdecl operator==(DString *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)param_2->stringValue;
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return 1;
    }
  }
  return (uint)(1 - bVar4 == (uint)(bVar4 != 0));
}

// --------------------------------------------------

// Function: operator==
// Address: 004468e0
// XREFS: None
/* int __cdecl operator==(class DString const &,char const *) */

int __cdecl operator==(DString *param_1,char *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return 1;
    }
  }
  return (uint)(1 - bVar3 == (uint)(bVar3 != 0));
}

// --------------------------------------------------

// Function: operator==
// Address: 00446930
// XREFS: None
/* int __cdecl operator==(char const *,class DString const &) */

int __cdecl operator==(char *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_2->stringValue;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 1;
    }
  }
  return (uint)(1 - bVar3 == (uint)(bVar3 != 0));
}

// --------------------------------------------------

// Function: operator!=
// Address: 00446980
// XREFS: None
/* int __cdecl operator!=(class DString const &,class DString const &) */

int __cdecl operator!=(DString *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)param_2->stringValue;
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)(1 - bVar4 != (uint)(bVar4 != 0));
}

// --------------------------------------------------

// Function: operator!=
// Address: 004469e0
// XREFS: None
/* int __cdecl operator!=(class DString const &,char const *) */

int __cdecl operator!=(DString *param_1,char *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)(1 - bVar3 != (uint)(bVar3 != 0));
}

// --------------------------------------------------

// Function: operator!=
// Address: 00446a30
// XREFS: None
/* int __cdecl operator!=(char const *,class DString const &) */

int __cdecl operator!=(char *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_2->stringValue;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)(1 - bVar3 != (uint)(bVar3 != 0));
}

// --------------------------------------------------

// Function: operator<
// Address: 00446a80
// XREFS: None
/* int __cdecl operator<(class DString const &,class DString const &) */

int __cdecl operator<(DString *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)param_2->stringValue;
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)((int)((1 - (uint)bVar4) - (uint)(bVar4 != 0)) < 0);
}

// --------------------------------------------------

// Function: operator<
// Address: 00446ae0
// XREFS: None
/* int __cdecl operator<(class DString const &,char const *) */

int __cdecl operator<(DString *param_1,char *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)((int)((1 - (uint)bVar3) - (uint)(bVar3 != 0)) < 0);
}

// --------------------------------------------------

// Function: operator<
// Address: 00446b30
// XREFS: None
/* int __cdecl operator<(char const *,class DString const &) */

int __cdecl operator<(char *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_2->stringValue;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)((int)((1 - (uint)bVar3) - (uint)(bVar3 != 0)) < 0);
}

// --------------------------------------------------

// Function: operator>
// Address: 00446b80
// XREFS: None
/* int __cdecl operator>(class DString const &,class DString const &) */

int __cdecl operator>(DString *param_1,DString *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  pbVar5 = (byte *)param_2->stringValue;
  pbVar4 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar4;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar4[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) break;
    pbVar4 = pbVar4 + 2;
    pbVar5 = pbVar5 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  uVar2 = (uint)(bVar6 != 0);
  uVar3 = 1 - bVar6;
  return (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2));
}

// --------------------------------------------------

// Function: operator>
// Address: 00446be0
// XREFS: None
/* int __cdecl operator>(class DString const &,char const *) */

int __cdecl operator>(DString *param_1,char *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar4;
    bVar5 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar4[1];
    bVar5 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar4 = pbVar4 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  uVar2 = (uint)(bVar5 != 0);
  uVar3 = 1 - bVar5;
  return (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2));
}

// --------------------------------------------------

// Function: operator>
// Address: 00446c30
// XREFS: None
/* int __cdecl operator>(char const *,class DString const &) */

int __cdecl operator>(char *param_1,DString *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = (byte *)param_2->stringValue;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar4 = pbVar4 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  uVar2 = (uint)(bVar5 != 0);
  uVar3 = 1 - bVar5;
  return (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2));
}

// --------------------------------------------------

// Function: _ShowErrMsg
// Address: 004477d0
// XREFS: None
void _ShowErrMsg(void)
{
  return;
}

// --------------------------------------------------

// Function: _DSLoadSoundBuffer
// Address: 004477e0
// XREFS: _SndObjCreate
/* WARNING: Variable defined which should be unmapped: pDSB */

ulong _DSLoadSoundBuffer(int *param_1,undefined4 param_2)
{
  int iVar1;
  IDirectSoundBuffer *pDSB;
  _DSBUFFERDESC dsBD;
  undefined4 local_4;
  
  dsBD.dwBufferBytes = 0;
  dsBD.dwReserved = 0;
  dsBD.lpwfxFormat = (tWAVEFORMATEX *)0x0;
  local_4 = 0;
  dsBD.dwSize = 0;
  dsBD.dwFlags = 0;
  iVar1 = _DSGetWaveResource(0,param_2,&local_4,&param_2,&dsBD.dwReserved);
  if (iVar1 != 0) {
    dsBD.dwFlags = 0x14;
    dsBD.dwBufferBytes = 0xe2;
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&dsBD.dwFlags,&dsBD,0);
    if (iVar1 < 0) {
      return 0;
    }
    iVar1 = _DSFillSoundBuffer(dsBD.dwSize,param_2,dsBD.dwReserved);
    if (iVar1 == 0) {
      (**(code **)(*(int *)dsBD.dwSize + 8))(dsBD.dwSize);
      return 0;
    }
  }
  return dsBD.dwSize;
}

// --------------------------------------------------

// Function: _DSReloadSoundBuffer
// Address: 00447890
// XREFS: None
/* WARNING: Variable defined which should be unmapped: pbWaveData */

undefined4 _DSReloadSoundBuffer(int *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 uVar2;
  uchar *pbWaveData;
  undefined1 local_4 [4];
  
  uVar2 = 0;
  iVar1 = _DSGetWaveResource(0,param_2,0,local_4,&param_2);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x50))(param_1);
    if (-1 < iVar1) {
      iVar1 = _DSFillSoundBuffer(param_1,unaff_ESI,param_1);
      if (iVar1 != 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

// --------------------------------------------------

// Function: _DSGetWaveResource
// Address: 004478f0
// XREFS: _DSLoadSoundBuffer, _DSReloadSoundBuffer, _SndObjCreate
undefined4 _DSGetWaveResource(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 unaff_retaddr;
  
  iVar1 = FindResourceA(param_1,param_2,&PTR_FUN_00570428);
  if (iVar1 != 0) {
    iVar1 = LoadResource(param_1,iVar1);
    if (iVar1 != 0) {
      iVar1 = LockResource(iVar1);
      if (iVar1 != 0) {
        iVar1 = _DSParseWaveResource(iVar1,unaff_retaddr,param_1,param_2);
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: _SndObjCreate
// Address: 00447950
// XREFS: None
/* WARNING: Variable defined which should be unmapped: pbData */

undefined4 * _SndObjCreate(undefined4 param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 unaff_retaddr;
  uchar *pbData;
  uint cbData;
  tWAVEFORMATEX *pWaveHeader;
  int *local_4;
  
  puVar4 = (undefined4 *)0x0;
  iVar1 = _DSGetWaveResource(0,param_2,&local_4,&cbData,&pWaveHeader);
  if (iVar1 != 0) {
    iVar1 = 1;
    if (param_3 < 1) {
      param_3 = 1;
    }
    puVar4 = (undefined4 *)LocalAlloc(0x40,param_3 * 4 + 0x10);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[2] = param_3;
      *puVar4 = unaff_EBP;
      puVar4[1] = unaff_EBX;
      uVar2 = _DSLoadSoundBuffer(local_4,param_2);
      puVar4[4] = uVar2;
      if (1 < (int)puVar4[2]) {
        piVar5 = puVar4 + 5;
        do {
          iVar3 = (**(code **)(*local_4 + 0x14))(local_4,puVar4[4],piVar5);
          if (iVar3 < 0) {
            iVar3 = _DSLoadSoundBuffer(local_4,unaff_retaddr);
            *piVar5 = iVar3;
            if (iVar3 == 0) {
              _SndObjDestroy(puVar4);
              return (undefined4 *)0x0;
            }
          }
          iVar1 = iVar1 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar1 < (int)puVar4[2]);
        return puVar4;
      }
    }
  }
  return puVar4;
}

// --------------------------------------------------

// Function: _SndObjDestroy
// Address: 00447a20
// XREFS: _SndObjCreate
void _SndObjDestroy(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      piVar2 = (int *)(param_1 + 0x10);
      do {
        piVar1 = (int *)*piVar2;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *piVar2 = 0;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar3 < *(int *)(param_1 + 8));
    }
    LocalFree(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: _SndObjGetFreeBuffer
// Address: 00447a60
// XREFS: _SndObjPlay
int * _SndObjGetFreeBuffer(undefined4 *param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  byte unaff_DI;
  
  puVar1 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    return (int *)0x0;
  }
  piVar3 = (int *)param_1[param_1[3] + 4];
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,&param_1);
    if (iVar2 < 0) {
      unaff_DI = 0;
    }
    if ((unaff_DI & 1) == 1) {
      if ((int)puVar1[2] < 2) {
        piVar3 = (int *)0x0;
      }
      else {
        iVar2 = puVar1[3];
        puVar1[3] = iVar2 + 1;
        if ((int)puVar1[2] <= iVar2 + 1) {
          puVar1[3] = 0;
        }
        piVar3 = (int *)puVar1[puVar1[3] + 4];
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,&stack0xfffffffc);
        if ((-1 < iVar2) && ((unaff_DI & 1) == 1)) {
          (**(code **)(*piVar3 + 0x48))(piVar3);
          (**(code **)(*piVar3 + 0x34))(piVar3,0);
        }
      }
    }
    if ((piVar3 != (int *)0x0) && ((unaff_DI & 2) != 0)) {
      iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3);
      if ((-1 < iVar2) && (iVar2 = _DSFillSoundBuffer(piVar3,*puVar1,puVar1[1]), iVar2 != 0)) {
        return piVar3;
      }
      piVar3 = (int *)0x0;
    }
  }
  return piVar3;
}

// --------------------------------------------------

// Function: _SndObjPlay
// Address: 00447b20
// XREFS: None
uint _SndObjPlay(uint param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0) {
    return param_1;
  }
  if (((param_2 & 1) == 0) || (*(int *)(param_1 + 8) == 1)) {
    piVar1 = (int *)_SndObjGetFreeBuffer(param_1);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,0,0,param_2);
      uVar3 = (uint)(-1 < iVar2);
    }
  }
  return uVar3;
}

// --------------------------------------------------

// Function: _SndObjStop
// Address: 00447b70
// XREFS: None
undefined4 _SndObjStop(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      puVar1 = (undefined4 *)(param_1 + 0x10);
      do {
        (**(code **)(*(int *)*puVar1 + 0x48))((int *)*puVar1);
        (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,0);
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar2 < *(int *)(param_1 + 8));
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: _DSFillSoundBuffer
// Address: 00447bc0
// XREFS: _DSLoadSoundBuffer, _DSReloadSoundBuffer, _SndObjGetFreeBuffer
/* WARNING: Variable defined which should be unmapped: pMem1 */

undefined4 _DSFillSoundBuffer(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  void *pMem1;
  undefined1 local_4 [4];
  
  iVar2 = param_2;
  piVar1 = param_1;
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (param_3 != 0)) {
    puVar7 = &param_2;
    puVar6 = &param_3;
    puVar5 = &param_1;
    iVar4 = param_3;
    iVar3 = (**(code **)(*param_1 + 0x2c))(param_1,0,param_3,local_4,puVar5,puVar6,puVar7,0);
    if (-1 < iVar3) {
      memcpy(iVar4,iVar2,puVar5);
      if (puVar6 != (undefined4 *)0x0) {
        memcpy(puVar7,(int)puVar5 + iVar2,puVar6);
      }
      (**(code **)(*piVar1 + 0x4c))(piVar1,iVar4,puVar5,puVar7,puVar6);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: _DSParseWaveResource
// Address: 00447c60
// XREFS: _DSGetWaveResource
undefined4 _DSParseWaveResource(int *param_1,uint *param_2,int *param_3,uint *param_4)
{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  if (param_2 != (uint *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  piVar5 = param_1 + 3;
  if (((*param_1 != 0x46464952) || (param_1[2] != 0x45564157)) ||
     (piVar1 = (int *)(param_1[1] + -4 + (int)piVar5), piVar1 <= piVar5)) {
                    /* Symbol Ref: {@symbol exit} */
    return 0;
  }
  do {
    uVar2 = piVar5[1];
    piVar4 = piVar5 + 2;
    if (*piVar5 == 0x20746d66) {
      if ((param_2 != (uint *)0x0) && (*param_2 == 0)) {
        if (uVar2 < 0xe) {
          return 0;
        }
        *param_2 = (uint)piVar4;
        if ((param_3 == (int *)0x0) || (*param_3 != 0)) {
          if (param_4 == (uint *)0x0) {
            return 1;
          }
          uVar3 = *param_4;
          goto joined_r0x00447d2c;
        }
      }
    }
    else if ((*piVar5 == 0x61746164) &&
            (((param_3 != (int *)0x0 && (*param_3 == 0)) ||
             ((param_4 != (uint *)0x0 && (*param_4 == 0)))))) {
      if (param_3 != (int *)0x0) {
        *param_3 = (int)piVar4;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar2;
      }
      if (param_2 == (uint *)0x0) {
        return 1;
      }
      uVar3 = *param_2;
joined_r0x00447d2c:
      if (uVar3 != 0) {
        return 1;
      }
    }
    piVar5 = (int *)((int)piVar4 + (uVar2 + 1 & 0xfffffffe));
    if (piVar1 <= piVar5) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: _WaveOpenFile
// Address: 00447d50
// XREFS: _WaveLoadFile, ds_stream_file
/* WARNING: Variable defined which should be unmapped: pcmWaveFormat */

int _WaveOpenFile(int *param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  uint uVar2;
  short unaff_SI;
  int iVar3;
  int *unaff_retaddr;
  pcmwaveformat_tag pcmWaveFormat;
  _MMCKINFO ckIn;
  int *piStack_4;
  
  *param_3 = 0;
  iVar1 = mmioOpenA(param_1,0,0x10000);
  if (iVar1 == 0) {
    iVar3 = 0xe100;
  }
  else {
    iVar3 = mmioDescend(iVar1,param_1,0,0);
    if (iVar3 == 0) {
      if ((*param_1 == 0x46464952) && (param_1[2] == 0x45564157)) {
        pcmWaveFormat.wf.nAvgBytesPerSec = 0x20746d66;
        iVar3 = mmioDescend(iVar1,&pcmWaveFormat.wf.nAvgBytesPerSec,param_1,0x10);
        if (iVar3 != 0) goto LAB_00447eb8;
        if (0xf < (uint)pcmWaveFormat._12_4_) {
          iVar3 = mmioRead(iVar1,&stack0xffffffd0,0x10);
          if (iVar3 != 0x10) {
            iVar3 = 0xe102;
            goto LAB_00447eb8;
          }
          if (unaff_SI == 1) {
            ckIn.dwFlags = 0;
          }
          else {
            iVar3 = mmioRead(iVar1,&ckIn.dwFlags,2);
            if (iVar3 != 2) {
              iVar3 = 0xe102;
              goto LAB_00447eb8;
            }
          }
          iVar3 = GlobalAlloc(0,(ckIn.dwFlags & 0xffff) + 0x12);
          *unaff_retaddr = iVar3;
          if (iVar3 == 0) {
            iVar3 = 0xe000;
            goto LAB_00447eb8;
          }
          memcpy(iVar3,&stack0xffffffd0,0x10);
          *(short *)(*unaff_retaddr + 0x10) = (short)ckIn.dwFlags;
          if (((short)ckIn.dwFlags == 0) ||
             (uVar2 = mmioRead(iVar1,*unaff_retaddr + 0x12,ckIn.dwFlags & 0xffff),
             uVar2 == (ckIn.dwFlags & 0xffff))) {
            iVar3 = mmioAscend(iVar1,&pcmWaveFormat.wf.nAvgBytesPerSec,0);
            if (iVar3 == 0) {
              *piStack_4 = iVar1;
              return 0;
            }
            goto LAB_00447eb8;
          }
        }
      }
      iVar3 = 0xe101;
    }
  }
LAB_00447eb8:
                    /* Symbol Ref: {@symbol ERROR_READING_WAVE} */
  if (*unaff_retaddr != 0) {
    GlobalFree(*unaff_retaddr);
    *unaff_retaddr = 0;
  }
  if (iVar1 != 0) {
    mmioClose(iVar1,0);
    iVar1 = 0;
  }
                    /* Symbol Ref: {@symbol TEMPCLEANUP} */
  *piStack_4 = iVar1;
  return iVar3;
}

// --------------------------------------------------

// Function: _WaveStartDataRead
// Address: 00447ef0
// XREFS: _WaveLoadFile, ds_stream_file, ds_stream_time_func
undefined4 _WaveStartDataRead(undefined4 *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  
  iVar1 = mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  if (iVar1 == -1) {
    return 1;
  }
  *unaff_ESI = 0x61746164;
  uVar2 = mmioDescend(*param_1,unaff_ESI,param_3,0x10);
  return uVar2;
}

// --------------------------------------------------

// Function: _WaveReadFile
// Address: 00447f40
// XREFS: _WaveLoadFile, ds_stream_file, ds_stream_time_func
/* WARNING: Variable defined which should be unmapped: mmioinfoIn */

uint _WaveReadFile(int param_1,uint *param_2)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int unaff_retaddr;
  _MMIOINFO mmioinfoIn;
  uint uStack_4;
  
  iVar1 = mmioGetInfo(param_1,&mmioinfoIn.fccIOProc,0);
  uVar2 = (uint)(iVar1 != 0);
  if (uVar2 == 0) {
    uVar2 = *(uint *)(param_1 + 4);
    if (uVar2 < uStack_4) {
      uStack_4 = uVar2;
    }
    uVar3 = 0;
    *(uint *)(param_1 + 4) = uVar2 - uStack_4;
    if (uStack_4 != 0) {
      do {
        if ((char *)mmioinfoIn.cchBuffer == mmioinfoIn.pchBuffer) {
          uVar2 = mmioAdvance(mmioinfoIn.hmmio,&stack0xffffffac,0);
          if (uVar2 != 0) goto LAB_00447ffb;
          if ((char *)mmioinfoIn.cchBuffer == mmioinfoIn.pchBuffer) {
            *param_2 = 0;
            return 0xe103;
          }
        }
        uVar2 = (int)mmioinfoIn.pchBuffer - mmioinfoIn.cchBuffer;
        if (uStack_4 - uVar3 < uVar2) {
          uVar2 = uStack_4 - uVar3;
        }
        memcpy(uVar3 + unaff_retaddr,mmioinfoIn.cchBuffer,uVar2);
        uVar3 = uVar3 + uVar2;
        mmioinfoIn.cchBuffer = mmioinfoIn.cchBuffer + uVar2;
      } while (uVar3 < uStack_4);
    }
    uVar2 = mmioSetInfo(mmioinfoIn.hmmio,&stack0xffffffac,0);
    if (uVar2 == 0) {
      *param_2 = uStack_4;
      return 0;
    }
  }
LAB_00447ffb:
                    /* Symbol Ref: {@symbol ERROR_CANNOT_READ} */
  *param_2 = 0;
  return uVar2;
}

// --------------------------------------------------

// Function: _WaveCloseReadFile
// Address: 00448040
// XREFS: ds_stream_file, ds_stream_stop
undefined4 _WaveCloseReadFile(int *param_1,int *param_2)
{
  if (*param_2 != 0) {
    GlobalFree(*param_2);
    *param_2 = 0;
  }
  if (*param_1 != 0) {
    mmioClose(*param_1,0);
    *param_1 = 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: _WaveCreateFile
// Address: 00448080
// XREFS: _WaveSaveFile
// Error: 
Low-level Error: Symbol $$undef00000092 extends beyond the end of the address space

// --------------------------------------------------

// Function: _WaveStartDataWrite
// Address: 004481a0
// XREFS: _WaveSaveFile
void _WaveStartDataWrite(undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 unaff_retaddr;
  
  *param_2 = 0x61746164;
  param_2[1] = 0;
  iVar1 = mmioCreateChunk(*param_1,param_2,0);
  if (iVar1 == 0) {
    mmioGetInfo(*param_1,unaff_retaddr,0);
  }
                    /* Symbol Ref: {@symbol ERROR_CANNOT_WRITE} */
  return;
}

// --------------------------------------------------

// Function: _WaveWriteFile
// Address: 004481e0
// XREFS: _WaveSaveFile
void _WaveWriteFile(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,int *param_5,
                   uint *param_6)
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  *param_5 = 0;
  if (param_2 != 0) {
    do {
      if (param_6[7] == param_6[9]) {
        *param_6 = *param_6 | 0x10000000;
        iVar1 = mmioAdvance(param_1,param_6,1);
        if (iVar1 != 0) {
          return;
        }
      }
      *(undefined1 *)param_6[7] = *(undefined1 *)(uVar2 + param_3);
      param_6[7] = param_6[7] + 1;
      uVar2 = uVar2 + 1;
      *param_5 = *param_5 + 1;
    } while (uVar2 < param_2);
  }
                    /* Symbol Ref: {@symbol ERROR_CANNOT_WRITE} */
  return;
}

// --------------------------------------------------

// Function: _WaveCloseWriteFile
// Address: 00448250
// XREFS: _WaveSaveFile
int _WaveCloseWriteFile(int *param_1,undefined4 param_2,undefined4 param_3,uint *param_4)
{
  int iVar1;
  undefined4 *unaff_EBX;
  undefined4 unaff_retaddr;
  
  if (*param_1 == 0) {
    return 0;
  }
  *param_4 = *param_4 | 0x10000000;
  iVar1 = mmioSetInfo(*param_1,param_4,0);
  if (iVar1 == 0) {
    iVar1 = mmioAscend(*param_1,unaff_EBX,0);
    if (iVar1 == 0) {
      iVar1 = mmioAscend(*param_1,unaff_retaddr,0);
      if (iVar1 == 0) {
        mmioSeek(*param_1,0,0);
        iVar1 = mmioDescend(*param_1,unaff_retaddr,0,0);
        if (iVar1 == 0) {
          *unaff_EBX = 0x74636166;
          iVar1 = mmioDescend(*param_1,unaff_EBX,unaff_retaddr,0x10);
          if (iVar1 != 0) {
            return 1;
          }
          mmioWrite(*param_1,&stack0xfffffff8,4);
          mmioAscend(*param_1,unaff_EBX,0);
          iVar1 = mmioAscend(*param_1,unaff_retaddr,0);
        }
      }
    }
  }
                    /* Symbol Ref: {@symbol ERROR_CANNOT_WRITE} */
  if (*param_1 != 0) {
    mmioClose(*param_1,0);
    *param_1 = 0;
  }
  return iVar1;
}

// --------------------------------------------------

// Function: _WaveCopyUselessChunks
// Address: 00448340
// XREFS: None
undefined4 _WaveCopyUselessChunks(undefined4 *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int *unaff_EBX;
  undefined4 uVar2;
  
  iVar1 = mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  if (iVar1 == -1) {
    uVar2 = 0xe102;
  }
  else {
    uVar2 = 0;
    iVar1 = mmioDescend(*param_1,unaff_EBX,param_3,0);
    while ((iVar1 == 0 &&
           ((uint)(unaff_EBX[3] + unaff_EBX[1]) <=
            (uint)(*(int *)(param_3 + 4) + *(int *)(param_3 + 0xc))))) {
      iVar1 = *unaff_EBX;
      if ((iVar1 != 0x20444150) && ((iVar1 == 0x50534944 || (iVar1 == 0x74736c70)))) {
        riffCopyChunk(*param_1,*param_1,unaff_EBX);
      }
      mmioAscend(*param_1,unaff_EBX,0);
      iVar1 = mmioDescend(*param_1,unaff_EBX,param_3,0);
    }
  }
                    /* Symbol Ref: {@symbol ERROR_IN_PROC} */
  mmioSeek(*param_1,*(int *)(param_3 + 0xc) + 4,0);
  return uVar2;
}

// --------------------------------------------------

// Function: riffCopyChunk
// Address: 00448400
// XREFS: _WaveCopyUselessChunks
/* WARNING: Variable defined which should be unmapped: ck */
/* riffCopyChunk */

undefined4 __cdecl riffCopyChunk(undefined4 param_1,undefined4 param_2,int param_3)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  _MMCKINFO ck;
  undefined4 uStack_4;
  
  uStack_28 = *(undefined4 *)(param_3 + 4);
  uStack_2c = 0x42;
  uVar1 = GlobalAlloc();
  iVar2 = GlobalLock(uVar1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = mmioCreateChunk(uStack_4,&stack0xffffffe0,0);
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_3 + 4);
    iVar4 = mmioRead(ck.cksize,iVar2,iVar3);
    if (iVar4 == iVar3) {
      iVar3 = mmioWrite(uStack_4,iVar2,iVar3);
      if (iVar3 == *(int *)(param_3 + 4)) {
        iVar3 = mmioAscend(uStack_4,&uStack_2c,0);
        if (iVar3 == 0) {
          uVar1 = GlobalHandle(iVar2);
          GlobalUnlock(uVar1);
          uVar1 = GlobalHandle(iVar2);
          GlobalFree(uVar1);
          return 1;
        }
      }
    }
  }
                    /* Symbol Ref: {@symbol rscc_Error} */
  uVar1 = GlobalHandle(iVar2);
  GlobalUnlock(uVar1);
  uVar1 = GlobalHandle(iVar2);
  GlobalFree(uVar1);
  return 0;
}

// --------------------------------------------------

// Function: _WaveLoadFile
// Address: 004484d0
// XREFS: None
/* WARNING: Variable defined which should be unmapped: ckIn */

int _WaveLoadFile(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int *param_4,
                 int *param_5)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  _MMCKINFO ckIn;
  _MMCKINFO ckInRiff;
  
  piVar3 = param_5;
  piVar2 = param_4;
  *param_5 = 0;
  *param_4 = 0;
  *param_2 = 0;
  iVar4 = _WaveOpenFile(param_1,&param_5,param_4,&ckInRiff.cksize);
  if (iVar4 == 0) {
    iVar4 = _WaveStartDataRead(&param_5,&ckIn.cksize,&ckInRiff.cksize);
    if (iVar4 == 0) {
      iVar4 = GlobalAlloc(0,ckIn.fccType);
      *piVar3 = iVar4;
      if (iVar4 == 0) {
        iVar4 = 0xe000;
      }
      else {
        iVar4 = _WaveReadFile(param_5,ckIn.fccType,iVar4,&ckIn.cksize,&param_4);
        if (iVar4 == 0) {
          *param_2 = param_4;
          goto LAB_0044859a;
        }
      }
    }
  }
                    /* Symbol Ref: {@symbol ERROR_LOADING} */
  if (*piVar3 != 0) {
    GlobalFree(*piVar3);
    *piVar3 = 0;
  }
  iVar1 = *piVar2;
  if (iVar1 != 0) {
    GlobalFree(iVar1);
    *piVar2 = 0;
  }
LAB_0044859a:
                    /* Symbol Ref: {@symbol DONE_LOADING} */
  if (param_5 != (int *)0x0) {
    mmioClose(param_5,0);
  }
  return iVar4;
}

// --------------------------------------------------

// Function: _WaveSaveFile
// Address: 004485c0
// XREFS: None
/* WARNING: Variable defined which should be unmapped: hmmioOut */

void _WaveSaveFile(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)
{
  int iVar1;
  void *hmmioOut;
  uint cbActualWrite;
  _MMCKINFO ckOut;
  _MMCKINFO ckOutRIFF;
  _MMIOINFO mmioinfoOut;
  
  iVar1 = _WaveCreateFile(param_1,&cbActualWrite,param_4,&ckOut.cksize,&ckOutRIFF.cksize);
  if (iVar1 == 0) {
    iVar1 = _WaveStartDataWrite(&cbActualWrite,&ckOut.cksize,&mmioinfoOut.fccIOProc);
    if (iVar1 == 0) {
      iVar1 = _WaveWriteFile(cbActualWrite,param_2,param_5,&ckOut.cksize,&ckOut,
                             &mmioinfoOut.fccIOProc);
      if (iVar1 == 0) {
        _WaveCloseWriteFile(&cbActualWrite,&ckOut.cksize,&ckOutRIFF.cksize,&mmioinfoOut.fccIOProc,
                            param_3);
      }
    }
  }
                    /* Symbol Ref: {@symbol ERROR_SAVING} */
  return;
}

// --------------------------------------------------

// Function: ds_stream_init
// Address: 00448660
// XREFS: init
/* ds_stream_init */

void __cdecl ds_stream_init(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  _uLastPercent = 100;
  _lpDSBStreamBuffer = 0;
  _bFileOpen = 0;
  _bPlaying = 0;
  _bTimerInstalled = 0;
  _uTimerID = 0;
  _main_wnd = param_1;
  _lpBuffer._0_4_ = param_3;
  _lpDS = param_2;
  _ds_ready = 1;
  return;
}

// --------------------------------------------------

// Function: ds_stream_exit
// Address: 004486b0
// XREFS: exit
/* ds_stream_exit */

void __cdecl ds_stream_exit(void)
{
  if (_ds_ready != 0) {
    if (((_bFileOpen != 0) || (_bPlaying != 0)) || (_bTimerInstalled != 0)) {
      ds_stream_stop();
    }
    _ds_ready = 0;
  }
  return;
}

// --------------------------------------------------

// Function: ds_stream_file
// Address: 004486f0
// XREFS: stream_file
/* WARNING: Variable defined which should be unmapped: dwLen1 */
/* ds_stream_file */

undefined4 __cdecl ds_stream_file(undefined4 param_1)
{
  int iVar1;
  uchar **ppuVar2;
  ulong *puVar3;
  ulong *puVar4;
  uchar **ppuStack_50;
  undefined4 uStack_4c;
  int *piStack_48;
  ulong *puStack_44;
  Alignment *pAStack_40;
  undefined4 *puStack_3c;
  ulong dwLen1;
  uchar *lpWrite1;
  uint uChkErr;
  uchar *lpWrite2;
  ulong dwLen2;
  _DSBUFFERDESC dsbd;
  
  if (((_bFileOpen != 0) || (_bPlaying != 0)) || (_bTimerInstalled != 0)) {
    puStack_3c = (undefined4 *)0x448717;
    ds_stream_stop();
  }
  puStack_3c = (undefined4 *)0x88847c;
  pAStack_40 = (Alignment *)&_wiWave;
  puStack_44 = &DAT_00888464;
  piStack_48 = (int *)param_1;
  _stream_paused = 0;
  uStack_4c = 0x448736;
  iVar1 = _WaveOpenFile();
  if (iVar1 != 0) {
    return 0;
  }
  if (*_wiWave != 1) {
    puStack_3c = &_wiWave;
    pAStack_40 = (Alignment *)&DAT_00888464;
    puStack_44 = (ulong *)0x448766;
    _WaveCloseReadFile();
    return 0;
  }
  puStack_3c = (undefined4 *)0x88847c;
  pAStack_40 = &DAT_00888468;
  puStack_44 = &DAT_00888464;
  piStack_48 = (int *)0x448787;
  iVar1 = _WaveStartDataRead();
  if (iVar1 == 0) {
    puStack_3c = (undefined4 *)0x14;
    pAStack_40 = (Alignment *)0x0;
    DAT_00888498 = (uint)(*(int *)(_wiWave + 4) * 0x78) / 600;
    puStack_44 = &dsbd.dwFlags;
    DAT_00888494 = DAT_00888498 * 6;
    piStack_48 = (int *)0x4487ee;
    memset();
    puStack_44 = &dsbd.dwFlags;
    puStack_3c = (undefined4 *)0x0;
    dsbd.dwFlags = 0x14;
    dsbd.dwBufferBytes = 0xe0;
    dsbd.dwReserved = DAT_00888494;
    pAStack_40 = (Alignment *)&_lpDSBStreamBuffer;
    piStack_48 = _lpDS;
    uStack_4c = 0x44882b;
    iVar1 = (**(code **)(*_lpDS + 0xc))();
    if (iVar1 != 0) {
      return 0;
    }
    ppuStack_50 = &lpWrite1;
    uStack_4c = 0;
    puVar3 = &dwLen1;
    ppuVar2 = (uchar **)&stack0xffffffc8;
    DAT_00888490 = _lpDSBStreamBuffer;
    DAT_008884b0 = 0;
    DAT_008884b4 = 0;
    iVar1 = (**(code **)(*_lpDSBStreamBuffer + 0x2c))
                      (_lpDSBStreamBuffer,0,DAT_00888494,&stack0xffffffcc,ppuVar2,puVar3);
    if (iVar1 == 0) {
      puVar4 = puVar3;
      if ((ppuVar2 != (uchar **)0x0) &&
         (_WaveReadFile(DAT_00888464,ppuVar2,puVar3,&DAT_00888468,&ppuStack_50), puVar4 = puVar3,
         ppuStack_50 < ppuVar2)) {
        if (DAT_008884ac == 0) {
          DAT_008884b4 = (uint)ppuStack_50 / DAT_00888498;
          DAT_008884b0 = 1;
          memset((int)ppuStack_50 + (int)puVar3,(_wiWave[7] != 8) - 1U & 0x80,
                 (int)ppuVar2 - (int)ppuStack_50);
          puVar4 = puVar3;
        }
        else {
          do {
            ppuVar2 = (uchar **)((int)ppuVar2 - (int)ppuStack_50);
            puVar3 = (ulong *)((int)puVar3 + (int)ppuStack_50);
            _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
            _WaveReadFile(DAT_00888464,ppuVar2,puVar3,&DAT_00888468,&ppuStack_50);
          } while (ppuStack_50 < ppuVar2);
        }
      }
      (**(code **)(*_lpDSBStreamBuffer + 0x4c))(_lpDSBStreamBuffer,puVar4,ppuVar2,uStack_4c,0);
      DAT_008884ac = (uint)puStack_3c & 0xff;
      DAT_008884a4 = 0;
      DAT_008884a0 = 0;
      DAT_0088849c = 0;
      DAT_008884a8 = 0;
      _bFileOpen = 1;
      SendMessageA(_main_wnd,0x502,0,0);
      (**(code **)(*_lpDSBStreamBuffer + 0x34))(_lpDSBStreamBuffer,0);
      (**(code **)(*_lpDSBStreamBuffer + 0x3c))(_lpDSBStreamBuffer,pAStack_40);
      (**(code **)(*_lpDSBStreamBuffer + 0x30))(_lpDSBStreamBuffer,0,0,1);
      iVar1 = timeBeginPeriod(0x32);
      if (iVar1 == 0) {
        _uTimerID = timeSetEvent(0x32,10,ds_stream_time_func,0,1);
        if (_uTimerID != 0) {
          _bTimerInstalled = 1;
        }
        _bPlaying = 1;
        return 1;
      }
      (**(code **)(*_lpDSBStreamBuffer + 0x48))(_lpDSBStreamBuffer);
      _bTimerInstalled = 0;
      _bPlaying = 0;
      return 0;
    }
    return 0;
  }
  puStack_3c = &_wiWave;
  pAStack_40 = (Alignment *)&DAT_00888464;
  puStack_44 = (ulong *)0x44879d;
  _WaveCloseReadFile();
  return 0;
}

// --------------------------------------------------

// Function: ds_stream_volume
// Address: 00448a40
// XREFS: set_stream_volume
/* ds_stream_volume */

bool __cdecl ds_stream_volume(undefined4 param_1)
{
  int iVar1;
  
  if (_lpDSBStreamBuffer == (int *)0x0) {
    return false;
  }
  iVar1 = (**(code **)(*_lpDSBStreamBuffer + 0x3c))(_lpDSBStreamBuffer,param_1);
  return iVar1 == 0;
}

// --------------------------------------------------

// Function: ds_stream_pause
// Address: 00448a60
// XREFS: pause_stream
/* ds_stream_pause */

void __cdecl ds_stream_pause(void)
{
  _stream_paused = 1;
  return;
}

// --------------------------------------------------

// Function: ds_stream_resume
// Address: 00448a70
// XREFS: resume_stream
/* ds_stream_resume */

undefined4 __cdecl ds_stream_resume(void)
{
  _stream_paused = 0;
  return 1;
}

// --------------------------------------------------

// Function: ds_stream_stop
// Address: 00448a80
// XREFS: ds_stream_exit, ds_stream_file, ds_stream_messages, stop_stream
/* ds_stream_stop */

undefined4 __cdecl ds_stream_stop(void)
{
  DAT_008884a8 = 1;
  if (_bTimerInstalled != 0) {
    _bTimerInstalled = 0;
    timeKillEvent(_uTimerID);
    timeEndPeriod(0x32);
  }
  if ((_bPlaying != 0) && (_bPlaying = 0, _lpDSBStreamBuffer != (int *)0x0)) {
    (**(code **)(*_lpDSBStreamBuffer + 0x48))(_lpDSBStreamBuffer);
  }
  if (_bFileOpen != 0) {
    if (_wiWave != 0) {
      _WaveCloseReadFile(&DAT_00888464,&_wiWave);
      _wiWave = 0;
    }
    if (_lpDSBStreamBuffer != (int *)0x0) {
      (**(code **)(*_lpDSBStreamBuffer + 8))(_lpDSBStreamBuffer);
      _lpDSBStreamBuffer = (int *)0x0;
      DAT_00888490 = 0;
    }
    _bFileOpen = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: ds_stream_messages
// Address: 00448b30
// XREFS: handle_messages
/* ds_stream_messages */

undefined4 __cdecl ds_stream_messages(undefined4 param_1,int param_2)
{
  int iVar1;
  
  if (param_2 == 0x500) {
    ds_stream_stop();
  }
  else if (param_2 == 0x502) {
    if (DAT_00888480 < DAT_008884a4) {
      DAT_008884a4 = DAT_008884a4 - DAT_00888480;
    }
    iVar1 = __ftol((DAT_008884a4 * 100) / DAT_00888480,0);
    if (iVar1 != _uLastPercent) {
      _uLastPercent = iVar1;
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: ds_stream_time_func
// Address: 00448ba0
// XREFS: ds_stream_file
/* WARNING: Variable defined which should be unmapped: dwLen1 */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall ds_stream_time_func,20 */

void ds_stream_time_func(void)
{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  uchar **ppuVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  uchar **ppuVar8;
  ulong *puStack_3c;
  undefined1 *puStack_38;
  int *piStack_34;
  ulong *puStack_30;
  undefined1 *puStack_2c;
  ulong dwLen1;
  ulong dwLen2;
  uchar *lpWrite1;
  uint uChkErr;
  uchar *lpWrite2;
  ulong dwPlay;
  ulong dwWrite;
  undefined1 local_4 [4];
  uint uVar4;
  
  if (DAT_0062e658 != 0) {
    return;
  }
  if (_stream_paused != 0) {
    return;
  }
  DAT_0062e658 = 1;
  if (DAT_008884a8 != 0) {
    DAT_0062e658 = 0;
    return;
  }
  if (DAT_00888490 == (int *)0x0) {
    DAT_0062e658 = 0;
    return;
  }
  puStack_2c = local_4;
  puStack_30 = &dwWrite;
  piStack_34 = DAT_00888490;
  puStack_38 = (undefined1 *)0x448bf6;
  (**(code **)(*DAT_00888490 + 0x10))();
  if ((DAT_0088849c < uChkErr) && (uChkErr < (int)DAT_0088849c + DAT_00888498)) {
    DAT_0062e658 = 0;
    return;
  }
  if ((DAT_008884b0 != 0) && (DAT_008884b4 == 0)) {
    if (DAT_008884a8 != 0) {
      DAT_0062e658 = 0;
      return;
    }
    puStack_38 = (undefined1 *)0x0;
    puStack_3c = (ulong *)0x0;
    DAT_008884a8 = 1;
    PostMessageA(_main_wnd,0x500);
    DAT_0062e658 = 0;
    return;
  }
  uVar4 = uChkErr;
  if (uChkErr < DAT_008884a0) {
    uVar4 = (int)DAT_00888494 + uChkErr;
  }
  iVar3 = uVar4 - DAT_008884a0;
  DAT_008884a0 = uChkErr;
  puStack_38 = (undefined1 *)0x0;
  puStack_3c = (ulong *)0x0;
  DAT_008884a4 = DAT_008884a4 + iVar3;
  PostMessageA(_main_wnd,0x502);
  if ((DAT_008884b0 == 0) || (DAT_008884b4 == 0)) {
    if (DAT_00888490 == (int *)0x0) {
      DAT_0062e658 = 0;
      return;
    }
    puStack_3c = (ulong *)&stack0xffffffdc;
    puStack_38 = (undefined1 *)0x0;
    ppuVar5 = &lpWrite1;
    puVar2 = (ulong *)&stack0xffffffd8;
    puVar1 = &dwLen1;
    iVar3 = (**(code **)(*DAT_00888490 + 0x2c))(DAT_00888490,DAT_0088849c,DAT_00888498);
    if (iVar3 != 0) {
      DAT_0062e658 = 0;
      return;
    }
    if ((puVar1 == (ulong *)0x0) || (DAT_008884a8 != 0)) {
      ppuVar8 = ppuVar5;
      if ((puVar1 != (ulong *)0x0) &&
         (((DAT_008884a8 != 0 && (_wiWave != 0)) && (ppuVar5 != (uchar **)0x0)))) {
        memset(ppuVar5,(*(short *)(_wiWave + 0xe) != 8) - 1U & 0x80,puVar1);
        ppuVar8 = ppuVar5;
      }
    }
    else {
      _WaveReadFile(DAT_00888464,puVar1,ppuVar5,&DAT_00888468,&puStack_3c);
      ppuVar8 = ppuVar5;
      if (puStack_3c < puVar1) {
        if (DAT_008884ac == 0) {
          if ((_wiWave != 0) && (ppuVar5 != (uchar **)0x0)) {
            if (*(short *)(_wiWave + 0xe) == 8) {
                    /* language.dll match for 0x80: "Arial" */
              uVar7 = 0x80;
            }
            else {
              if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448e44;
              uVar7 = 0;
            }
            memset((undefined1 *)((int)puStack_3c + (int)ppuVar5),uVar7,
                   (int)puVar1 - (int)puStack_3c);
          }
LAB_00448e44:
          DAT_008884b0 = 1;
          ppuVar8 = ppuVar5;
          if (DAT_0088849c < piStack_34) {
            DAT_008884b4 = (uint)(((int)DAT_0088849c + (int)DAT_00888494) - (int)piStack_34) /
                           DAT_00888498;
          }
          else {
            DAT_008884b4 = (uint)((int)DAT_0088849c - (int)piStack_34) / DAT_00888498;
          }
        }
        else if (ppuVar5 != (uchar **)0x0) {
          do {
            puVar1 = (ulong *)((int)puVar1 - (int)puStack_3c);
            ppuVar5 = (uchar **)((int)ppuVar5 + (int)puStack_3c);
            _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
            _WaveReadFile(DAT_00888464,puVar1,ppuVar5,&DAT_00888468,&puStack_3c);
          } while (puStack_3c < puVar1);
        }
      }
    }
    if (puVar2 != (ulong *)0x0) {
      if (DAT_008884a8 == 0) {
        _WaveReadFile(DAT_00888464,puVar2,puStack_38,&DAT_00888468,&puStack_3c);
        if (puStack_3c < puVar2) {
          if (DAT_008884ac == 0) {
            if ((_wiWave != 0) && (puStack_38 != (undefined1 *)0x0)) {
              if (*(short *)(_wiWave + 0xe) == 8) {
                    /* language.dll match for 0x80: "Arial" */
                uVar7 = 0x80;
              }
              else {
                if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448faa;
                uVar7 = 0;
              }
              memset((undefined1 *)((int)puStack_3c + (int)puStack_38),uVar7,
                     (int)puVar2 - (int)puStack_3c);
            }
LAB_00448faa:
            DAT_008884b0 = 1;
            if (DAT_0088849c < piStack_34) {
              DAT_008884b4 = (uint)(((int)DAT_0088849c + (int)DAT_00888494) - (int)piStack_34) /
                             DAT_00888498;
            }
            else {
              DAT_008884b4 = (uint)((int)DAT_0088849c - (int)piStack_34) / DAT_00888498;
            }
          }
          else {
            puVar6 = puStack_38;
            if (puStack_38 != (undefined1 *)0x0) {
              do {
                puVar2 = (ulong *)((int)puVar2 - (int)puStack_3c);
                puVar6 = puVar6 + (int)puStack_3c;
                _WaveStartDataRead(&DAT_00888464,&DAT_00888468,0x88847c);
                _WaveReadFile(DAT_00888464,puVar2,puVar6,&DAT_00888468,&puStack_3c);
              } while (puStack_3c < puVar2);
            }
          }
        }
      }
      else if (((puVar2 != (ulong *)0x0) && (DAT_008884a8 != 0)) &&
              ((_wiWave != 0 && (puStack_38 != (undefined1 *)0x0)))) {
        memset(puStack_38,(*(short *)(_wiWave + 0xe) != 8) - 1U & 0x80,puVar2);
      }
    }
    if (DAT_00888490 != (int *)0x0) {
      (**(code **)(*DAT_00888490 + 0x4c))(DAT_00888490,ppuVar8,puVar1,puStack_38,puVar2);
    }
    DAT_0088849c = (int *)((int)DAT_0088849c + DAT_00888498);
    if (DAT_0088849c < DAT_00888494) {
      DAT_0062e658 = 0;
      return;
    }
    goto LAB_004490be;
  }
  DAT_008884b4 = DAT_008884b4 - 1;
  if ((int)DAT_008884b4 < 2) {
    DAT_0062e658 = 0;
    return;
  }
  if (DAT_00888490 == (int *)0x0) {
    DAT_0062e658 = 0;
    return;
  }
  puStack_3c = (ulong *)&stack0xffffffdc;
  puStack_38 = (undefined1 *)0x0;
  ppuVar5 = &lpWrite1;
  puVar6 = &stack0xffffffd8;
  puVar2 = &dwLen1;
  iVar3 = (**(code **)(*DAT_00888490 + 0x2c))(DAT_00888490,DAT_0088849c,DAT_00888498,puVar2,puVar6);
  if (iVar3 != 0) {
    DAT_0062e658 = 0;
    return;
  }
  if ((_wiWave != 0) && (ppuVar5 != (uchar **)0x0)) {
    if (*(short *)(_wiWave + 0xe) == 8) {
                    /* language.dll match for 0x80: "Arial" */
      uVar7 = 0x80;
    }
    else {
      if (*(short *)(_wiWave + 0xe) != 0x10) goto LAB_00448d37;
      uVar7 = 0;
    }
    memset(ppuVar5,uVar7,puVar2);
  }
LAB_00448d37:
  (**(code **)(*DAT_00888490 + 0x4c))(DAT_00888490,ppuVar5,puVar2,puStack_38,puVar6);
  DAT_0088849c = (int *)((int)DAT_0088849c + DAT_00888498);
  if (DAT_0088849c < DAT_00888494) {
    DAT_0062e658 = 0;
    return;
  }
LAB_004490be:
  DAT_0088849c = (int *)((int)DAT_0088849c - (int)DAT_00888494);
  DAT_0062e658 = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004496ed
// Address: 004496ed
// XREFS: None
/* WARNING: Unable to track spacebase fully for stack */

int __fastcall FUN_004496ed(undefined4 param_1,char *param_2)
{
  byte bVar1;
  char *in_EAX;
  byte *pbVar2;
  char cVar3;
  int unaff_EBX;
  undefined4 unaff_ESI;
  byte *pbVar4;
  bool bVar5;
  int unaff_retaddr;
  
  cVar3 = (char)((uint)unaff_EBX >> 8);
  *(char *)(unaff_EBX + -0x6a) = *(char *)(unaff_EBX + -0x6a) + cVar3;
  *(char *)(unaff_EBX + -0x34ffbb6a) =
       *(char *)(unaff_EBX + -0x34ffbb6a) + (char)((uint)param_2 >> 8);
  *in_EAX = *in_EAX + (char)unaff_EBX;
  *param_2 = *param_2 + cVar3;
  in_EAX[-0x6f6f6f70] = in_EAX[-0x6f6f6f70] + (char)param_2;
  pbVar2 = *(byte **)(unaff_retaddr + 9);
  *(int *)(unaff_retaddr + 1) = unaff_EBX;
  *(undefined4 *)(unaff_retaddr + -3) = unaff_ESI;
  pbVar4 = *(byte **)(unaff_retaddr + 0xd);
  while( true ) {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}

// --------------------------------------------------

// Function: compareFilenameStrings
// Address: 00449710
// XREFS: None
/* int __cdecl compareFilenameStrings(void const *,void const *) */

int __cdecl compareFilenameStrings(void *param_1,void *param_2)
{
  byte bVar1;
  bool bVar2;
  
  while( true ) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = *param_1;
                    /* WARNING: Load size is inaccurate */
    bVar2 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = *(byte *)((int)param_1 + 1);
    bVar2 = bVar1 < *(byte *)((int)param_2 + 1);
    if (bVar1 != *(byte *)((int)param_2 + 1)) break;
    param_1 = (void *)((int)param_1 + 2);
    param_2 = (void *)((int)param_2 + 2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (1 - (uint)bVar2) - (uint)(bVar2 != 0);
}

// --------------------------------------------------

// Function: driveAsLetter
// Address: 00449750
// XREFS: None
/* char __cdecl driveAsLetter(int) */

char __cdecl driveAsLetter(int param_1)
{
  return (char)param_1 + '@';
}

// --------------------------------------------------

// Function: driveAsInt
// Address: 00449760
// XREFS: None
/* int __cdecl driveAsInt(char) */

int __cdecl driveAsInt(char param_1)
{
  return param_1 + -0x40;
}

// --------------------------------------------------

// Function: FUN_0044a05d
// Address: 0044a05d
// XREFS: None
void FUN_0044a05d(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

// --------------------------------------------------

// Function: FUN_0044a4b9
// Address: 0044a4b9
// XREFS: None
void __fastcall FUN_0044a4b9(int param_1,char *param_2)
{
  int *piVar1;
  char cVar2;
  char cVar4;
  int in_EAX;
  char *pcVar3;
  char cVar5;
  char cVar6;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar12;
  int unaff_EBX;
  int iVar13;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  char *pcVar7;
  char *pcVar11;
  char cVar14;
  
  cVar5 = (char)param_1;
  *(char *)(in_EAX + -0x5a) = *(char *)(in_EAX + -0x5a) + cVar5;
  *(char *)(unaff_EDI + -0x59) = *(char *)(unaff_EDI + -0x59) + cVar5;
  cVar10 = (char)unaff_EBX;
  *(char *)(unaff_ESI + 0x44) = *(char *)(unaff_ESI + 0x44) + cVar10;
  cVar2 = (char)in_EAX;
  *(char *)(unaff_EBP + -0x1affbb57) = *(char *)(unaff_EBP + -0x1affbb57) + cVar2;
  param_2[-0x58] = param_2[-0x58] + cVar2;
  cVar4 = (char)((uint)in_EAX >> 8);
  param_2[0x20044a7] = param_2[0x20044a7] + cVar4;
  param_2[-0x55] = param_2[-0x55] + cVar5;
  cVar8 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_EBP + 0x130044aa) = *(char *)(unaff_EBP + 0x130044aa) + cVar8;
  *(char *)(unaff_EDI + 5) = cVar2;
  cVar14 = (char)((uint)unaff_EBX >> 8);
  *(char *)(param_1 + -0x57) = *(char *)(param_1 + -0x57) + cVar14;
  cVar5 = cVar5 + cVar10;
  cVar12 = (char)((uint)param_2 >> 8);
  *(char *)(unaff_ESI + 4) = *(char *)(unaff_ESI + 4) + cVar12;
  cVar9 = (char)param_2;
  *(char *)(unaff_ESI + -0x9ffbb55) = *(char *)(unaff_ESI + -0x9ffbb55) + cVar9;
  *(char *)(unaff_ESI + 5) = *(char *)(unaff_ESI + 5) + cVar14;
  *(int *)(unaff_EDI + 7) = in_EAX;
  pcVar3 = (char *)(CONCAT31((int3)((uint)param_1 >> 8),cVar5) + 0x70044aa);
  *pcVar3 = *pcVar3 + cVar4;
  *(char *)(unaff_EDI + 0xb) = cVar2;
  *(char *)(unaff_EBP + -0x57) = *(char *)(unaff_EBP + -0x57) + cVar8;
  cVar8 = cVar8 + cVar5;
  *param_2 = *param_2 + cVar8;
  param_2[-0x15ffbb59] = param_2[-0x15ffbb59] + cVar5;
  piVar1 = (int *)(unaff_EDI + 0xd);
  *(char *)piVar1 = *(char *)piVar1 + cVar8;
  *piVar1 = in_EAX;
  param_2[-0x7ffbb56] = param_2[-0x7ffbb56] + cVar9;
  *(char *)(unaff_ESI + 0x1b0044ae) = *(char *)(unaff_ESI + 0x1b0044ae) + cVar14;
  *(char *)(unaff_EBX + -0x59) = *(char *)(unaff_EBX + -0x59) + cVar14;
  cVar10 = cVar10 * '\x02';
  pcVar3 = (char *)CONCAT31((int3)((uint)unaff_EBX >> 8),cVar10);
  *pcVar3 = *pcVar3 + cVar4;
  *(int *)(unaff_EDI + 0x12) = in_EAX;
  *(char *)(unaff_ESI + -0x13ffbb4f) = *(char *)(unaff_ESI + -0x13ffbb4f) + cVar2;
  param_2[0xf0044a8] = param_2[0xf0044a8] + cVar12;
  *(char *)(unaff_EDI + -0x43) = *(char *)(unaff_EDI + -0x43) + cVar8;
  cVar14 = cVar14 + cVar5;
  iVar13 = CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar14,cVar10));
  pcVar3 = (char *)(iVar13 + unaff_EBP * 4);
  *pcVar3 = *pcVar3 + cVar9;
  *(char *)(unaff_EDI + -0x3f) = *(char *)(unaff_EDI + -0x3f) + cVar12;
  cVar8 = cVar8 + cVar10;
  *(char *)(iVar13 + 0x44a8) = *(char *)(iVar13 + 0x44a8) + cVar4;
  *(char *)(in_EAX + -0x59) = *(char *)(in_EAX + -0x59) + cVar4;
  cVar2 = cVar2 * '\x02';
  pcVar3 = (char *)CONCAT31((int3)((uint)in_EAX >> 8),cVar2);
  *pcVar3 = *pcVar3 + cVar5;
  *(char **)(unaff_EDI + 0x18) = pcVar3;
  *(char *)(iVar13 + -0x56) = *(char *)(iVar13 + -0x56) + cVar8;
  *(char *)(unaff_EDI + -0xbffbb3c) = *(char *)(unaff_EDI + -0xbffbb3c) + cVar9;
  *(char *)(unaff_EDI + 100) = *(char *)(unaff_EDI + 100) + cVar9;
  *(char *)(unaff_ESI + -0x5506ffaf) = *(char *)(unaff_ESI + -0x5506ffaf) + cVar12;
  param_2[unaff_EBP * 4 + 0x44] = param_2[unaff_EBP * 4 + 0x44] + cVar10;
  pcVar3[-0x1affbb58] = pcVar3[-0x1affbb58] + cVar5 + cVar9;
  *(char *)(unaff_EBP + -0x59) = *(char *)(unaff_EBP + -0x59) + cVar2;
  *(char *)(unaff_EBP + -0x12ffbb5a) = *(char *)(unaff_EBP + -0x12ffbb5a) + cVar4;
  *(char *)(unaff_EDI + 0x24) = cVar2;
  pcVar3[-0x56] = pcVar3[-0x56] + cVar9 + cVar2;
  *(char *)(unaff_ESI + 0x1c0044ba) = *(char *)(unaff_ESI + 0x1c0044ba) + cVar12;
  cVar6 = cVar5 + cVar9 + cVar10;
  pcVar7 = (char *)CONCAT31((int3)(CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar8,cVar5)) >>
                                  8),cVar6);
  *pcVar7 = *pcVar7 + cVar14;
  pcVar7[-0x21ffbb5a] = pcVar7[-0x21ffbb5a] + cVar10;
  *(char *)(unaff_EDI + 0x2d) = cVar2;
  pcVar7[-0x56] = pcVar7[-0x56] + cVar2;
  *(char *)(unaff_EDI + 0xd0044d7) = *(char *)(unaff_EDI + 0xd0044d7) + cVar4;
  cVar10 = cVar9 + cVar2 + cVar6;
  pcVar11 = (char *)CONCAT31((int3)((uint)param_2 >> 8),cVar10);
  *pcVar11 = *pcVar11 + cVar8;
  pcVar11[-0x2dffbb5a] = pcVar11[-0x2dffbb5a] + cVar6;
  *(char *)(unaff_EDI + 0x36) = cVar2;
  DAT_9b0044aa = DAT_9b0044aa + cVar12;
  pcVar7[-0x58] = pcVar7[-0x58] + cVar4;
  *(char *)(unaff_ESI + 0x1e0044c8) = *(char *)(unaff_ESI + 0x1e0044c8) + cVar14;
  *(char *)(unaff_ESI + -0x35) = *(char *)(unaff_ESI + -0x35) + cVar14;
  *(char *)(unaff_EDI + 0x3b) = cVar2;
  *(char *)(unaff_ESI + 0x25) = *(char *)(unaff_ESI + 0x25) + cVar4;
  *(char *)(unaff_EDI + 0x3c) = cVar2;
  pcVar7[unaff_EBP * 4 + -0x570dffbc] = pcVar7[unaff_EBP * 4 + -0x570dffbc] + cVar6;
  pcVar11[-0x58] = pcVar11[-0x58] + cVar10;
  *(char *)(unaff_EDI + 0xf0044e4) = *(char *)(unaff_EDI + 0xf0044e4) + cVar8;
  *(char *)(unaff_EDI + -0x19) = *(char *)(unaff_EDI + -0x19) + cVar8;
  *pcVar3 = *pcVar3 + cVar4;
  *pcVar3 = *pcVar3 + cVar2;
  *(undefined1 *)(unaff_EDI + 0x40) = *(undefined1 *)(unaff_ESI + 0x28);
  return;
}

// --------------------------------------------------

// Function: FUN_0044a64f
// Address: 0044a64f
// XREFS: None
void FUN_0044a64f(void)
{
  undefined1 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined1 *)(unaff_ESI + -1);
  *(undefined1 *)(unaff_EDI + -2) = *(undefined1 *)(unaff_ESI + -2);
  *(undefined1 *)(unaff_EDI + -1) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a65c
// Address: 0044a65c
// XREFS: None
void FUN_0044a65c(void)
{
  undefined1 uVar1;
  undefined1 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined1 *)(unaff_ESI + -2);
  uVar2 = *(undefined1 *)(unaff_ESI + -1);
  *(undefined1 *)(unaff_EDI + -3) = *(undefined1 *)(unaff_ESI + -3);
  *(undefined1 *)(unaff_EDI + -2) = uVar1;
  *(undefined1 *)(unaff_EDI + -1) = uVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a66f
// Address: 0044a66f
// XREFS: None
void FUN_0044a66f(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x5c);
  *(undefined4 *)(unaff_EDI + -0x60) = *(undefined4 *)(unaff_ESI + -0x60);
  *(undefined4 *)(unaff_EDI + -0x5c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x54);
  *(undefined4 *)(unaff_EDI + -0x58) = *(undefined4 *)(unaff_ESI + -0x58);
  *(undefined4 *)(unaff_EDI + -0x54) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4c);
  *(undefined4 *)(unaff_EDI + -0x50) = *(undefined4 *)(unaff_ESI + -0x50);
  *(undefined4 *)(unaff_EDI + -0x4c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x44);
  *(undefined4 *)(unaff_EDI + -0x48) = *(undefined4 *)(unaff_ESI + -0x48);
  *(undefined4 *)(unaff_EDI + -0x44) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3c);
  *(undefined4 *)(unaff_EDI + -0x40) = *(undefined4 *)(unaff_ESI + -0x40);
  *(undefined4 *)(unaff_EDI + -0x3c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x34);
  *(undefined4 *)(unaff_EDI + -0x38) = *(undefined4 *)(unaff_ESI + -0x38);
  *(undefined4 *)(unaff_EDI + -0x34) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2c);
  *(undefined4 *)(unaff_EDI + -0x30) = *(undefined4 *)(unaff_ESI + -0x30);
  *(undefined4 *)(unaff_EDI + -0x2c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x24);
  *(undefined4 *)(unaff_EDI + -0x28) = *(undefined4 *)(unaff_ESI + -0x28);
  *(undefined4 *)(unaff_EDI + -0x24) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1c);
  *(undefined4 *)(unaff_EDI + -0x20) = *(undefined4 *)(unaff_ESI + -0x20);
  *(undefined4 *)(unaff_EDI + -0x1c) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x14);
  *(undefined4 *)(unaff_EDI + -0x18) = *(undefined4 *)(unaff_ESI + -0x18);
  *(undefined4 *)(unaff_EDI + -0x14) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0xc);
  *(undefined4 *)(unaff_EDI + -0x10) = *(undefined4 *)(unaff_ESI + -0x10);
  *(undefined4 *)(unaff_EDI + -0xc) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -4);
  *(undefined4 *)(unaff_EDI + -8) = *(undefined4 *)(unaff_ESI + -8);
  *(undefined4 *)(unaff_EDI + -4) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a70f
// Address: 0044a70f
// XREFS: None
void FUN_0044a70f(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x5b);
  *(undefined4 *)(unaff_EDI + -0x5f) = *(undefined4 *)(unaff_ESI + -0x5f);
  *(undefined4 *)(unaff_EDI + -0x5b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x53);
  *(undefined4 *)(unaff_EDI + -0x57) = *(undefined4 *)(unaff_ESI + -0x57);
  *(undefined4 *)(unaff_EDI + -0x53) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4b);
  *(undefined4 *)(unaff_EDI + -0x4f) = *(undefined4 *)(unaff_ESI + -0x4f);
  *(undefined4 *)(unaff_EDI + -0x4b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x43);
  *(undefined4 *)(unaff_EDI + -0x47) = *(undefined4 *)(unaff_ESI + -0x47);
  *(undefined4 *)(unaff_EDI + -0x43) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3b);
  *(undefined4 *)(unaff_EDI + -0x3f) = *(undefined4 *)(unaff_ESI + -0x3f);
  *(undefined4 *)(unaff_EDI + -0x3b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x33);
  *(undefined4 *)(unaff_EDI + -0x37) = *(undefined4 *)(unaff_ESI + -0x37);
  *(undefined4 *)(unaff_EDI + -0x33) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2b);
  *(undefined4 *)(unaff_EDI + -0x2f) = *(undefined4 *)(unaff_ESI + -0x2f);
  *(undefined4 *)(unaff_EDI + -0x2b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x23);
  *(undefined4 *)(unaff_EDI + -0x27) = *(undefined4 *)(unaff_ESI + -0x27);
  *(undefined4 *)(unaff_EDI + -0x23) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1b);
  *(undefined4 *)(unaff_EDI + -0x1f) = *(undefined4 *)(unaff_ESI + -0x1f);
  *(undefined4 *)(unaff_EDI + -0x1b) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x13);
  *(undefined4 *)(unaff_EDI + -0x17) = *(undefined4 *)(unaff_ESI + -0x17);
  *(undefined4 *)(unaff_EDI + -0x13) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0xb);
  *(undefined4 *)(unaff_EDI + -0xf) = *(undefined4 *)(unaff_ESI + -0xf);
  *(undefined4 *)(unaff_EDI + -0xb) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -4);
  *(undefined4 *)(unaff_EDI + -7) = *(undefined4 *)(unaff_ESI + -7);
  *(undefined4 *)(unaff_EDI + -4) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a7af
// Address: 0044a7af
// XREFS: None
void FUN_0044a7af(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x5a);
  *(undefined4 *)(unaff_EDI + -0x5e) = *(undefined4 *)(unaff_ESI + -0x5e);
  *(undefined4 *)(unaff_EDI + -0x5a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x52);
  *(undefined4 *)(unaff_EDI + -0x56) = *(undefined4 *)(unaff_ESI + -0x56);
  *(undefined4 *)(unaff_EDI + -0x52) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4a);
  *(undefined4 *)(unaff_EDI + -0x4e) = *(undefined4 *)(unaff_ESI + -0x4e);
  *(undefined4 *)(unaff_EDI + -0x4a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x42);
  *(undefined4 *)(unaff_EDI + -0x46) = *(undefined4 *)(unaff_ESI + -0x46);
  *(undefined4 *)(unaff_EDI + -0x42) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3a);
  *(undefined4 *)(unaff_EDI + -0x3e) = *(undefined4 *)(unaff_ESI + -0x3e);
  *(undefined4 *)(unaff_EDI + -0x3a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x32);
  *(undefined4 *)(unaff_EDI + -0x36) = *(undefined4 *)(unaff_ESI + -0x36);
  *(undefined4 *)(unaff_EDI + -0x32) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2a);
  *(undefined4 *)(unaff_EDI + -0x2e) = *(undefined4 *)(unaff_ESI + -0x2e);
  *(undefined4 *)(unaff_EDI + -0x2a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x22);
  *(undefined4 *)(unaff_EDI + -0x26) = *(undefined4 *)(unaff_ESI + -0x26);
  *(undefined4 *)(unaff_EDI + -0x22) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1a);
  *(undefined4 *)(unaff_EDI + -0x1e) = *(undefined4 *)(unaff_ESI + -0x1e);
  *(undefined4 *)(unaff_EDI + -0x1a) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x12);
  *(undefined4 *)(unaff_EDI + -0x16) = *(undefined4 *)(unaff_ESI + -0x16);
  *(undefined4 *)(unaff_EDI + -0x12) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -10);
  *(undefined4 *)(unaff_EDI + -0xe) = *(undefined4 *)(unaff_ESI + -0xe);
  *(undefined4 *)(unaff_EDI + -10) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -2);
  *(undefined4 *)(unaff_EDI + -6) = *(undefined4 *)(unaff_ESI + -6);
  *(char *)(unaff_EDI + -2) = (char)uVar1;
  *(char *)(unaff_EDI + -1) = (char)((uint)uVar1 >> 8);
  return;
}

// --------------------------------------------------

// Function: FUN_0044a852
// Address: 0044a852
// XREFS: None
void FUN_0044a852(void)
{
  undefined1 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar2 = *(undefined4 *)(unaff_ESI + -0x59);
  *(undefined4 *)(unaff_EDI + -0x5d) = *(undefined4 *)(unaff_ESI + -0x5d);
  *(undefined4 *)(unaff_EDI + -0x59) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x51);
  *(undefined4 *)(unaff_EDI + -0x55) = *(undefined4 *)(unaff_ESI + -0x55);
  *(undefined4 *)(unaff_EDI + -0x51) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x49);
  *(undefined4 *)(unaff_EDI + -0x4d) = *(undefined4 *)(unaff_ESI + -0x4d);
  *(undefined4 *)(unaff_EDI + -0x49) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x41);
  *(undefined4 *)(unaff_EDI + -0x45) = *(undefined4 *)(unaff_ESI + -0x45);
  *(undefined4 *)(unaff_EDI + -0x41) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x39);
  *(undefined4 *)(unaff_EDI + -0x3d) = *(undefined4 *)(unaff_ESI + -0x3d);
  *(undefined4 *)(unaff_EDI + -0x39) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x31);
  *(undefined4 *)(unaff_EDI + -0x35) = *(undefined4 *)(unaff_ESI + -0x35);
  *(undefined4 *)(unaff_EDI + -0x31) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x29);
  *(undefined4 *)(unaff_EDI + -0x2d) = *(undefined4 *)(unaff_ESI + -0x2d);
  *(undefined4 *)(unaff_EDI + -0x29) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x21);
  *(undefined4 *)(unaff_EDI + -0x25) = *(undefined4 *)(unaff_ESI + -0x25);
  *(undefined4 *)(unaff_EDI + -0x21) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x19);
  *(undefined4 *)(unaff_EDI + -0x1d) = *(undefined4 *)(unaff_ESI + -0x1d);
  *(undefined4 *)(unaff_EDI + -0x19) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x11);
  *(undefined4 *)(unaff_EDI + -0x15) = *(undefined4 *)(unaff_ESI + -0x15);
  *(undefined4 *)(unaff_EDI + -0x11) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -9);
  *(undefined4 *)(unaff_EDI + -0xd) = *(undefined4 *)(unaff_ESI + -0xd);
  *(undefined4 *)(unaff_EDI + -9) = uVar2;
  uVar1 = *(undefined1 *)(unaff_ESI + -1);
  *(undefined4 *)(unaff_EDI + -5) = *(undefined4 *)(unaff_ESI + -5);
  *(undefined1 *)(unaff_EDI + -1) = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0044a8f2
// Address: 0044a8f2
// XREFS: None
void FUN_0044a8f2(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x58);
  *(undefined4 *)(unaff_EDI + -0x5c) = *(undefined4 *)(unaff_ESI + -0x5c);
  *(undefined4 *)(unaff_EDI + -0x58) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x50);
  *(undefined4 *)(unaff_EDI + -0x54) = *(undefined4 *)(unaff_ESI + -0x54);
  *(undefined4 *)(unaff_EDI + -0x50) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x48);
  *(undefined4 *)(unaff_EDI + -0x4c) = *(undefined4 *)(unaff_ESI + -0x4c);
  *(undefined4 *)(unaff_EDI + -0x48) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x40);
  *(undefined4 *)(unaff_EDI + -0x44) = *(undefined4 *)(unaff_ESI + -0x44);
  *(undefined4 *)(unaff_EDI + -0x40) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x38);
  *(undefined4 *)(unaff_EDI + -0x3c) = *(undefined4 *)(unaff_ESI + -0x3c);
  *(undefined4 *)(unaff_EDI + -0x38) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x30);
  *(undefined4 *)(unaff_EDI + -0x34) = *(undefined4 *)(unaff_ESI + -0x34);
  *(undefined4 *)(unaff_EDI + -0x30) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x28);
  *(undefined4 *)(unaff_EDI + -0x2c) = *(undefined4 *)(unaff_ESI + -0x2c);
  *(undefined4 *)(unaff_EDI + -0x28) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x20);
  *(undefined4 *)(unaff_EDI + -0x24) = *(undefined4 *)(unaff_ESI + -0x24);
  *(undefined4 *)(unaff_EDI + -0x20) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x18);
  *(undefined4 *)(unaff_EDI + -0x1c) = *(undefined4 *)(unaff_ESI + -0x1c);
  *(undefined4 *)(unaff_EDI + -0x18) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x10);
  *(undefined4 *)(unaff_EDI + -0x14) = *(undefined4 *)(unaff_ESI + -0x14);
  *(undefined4 *)(unaff_EDI + -0x10) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -8);
  *(undefined4 *)(unaff_EDI + -0xc) = *(undefined4 *)(unaff_ESI + -0xc);
  *(undefined4 *)(unaff_EDI + -8) = uVar1;
  *(undefined4 *)(unaff_EDI + -4) = *(undefined4 *)(unaff_ESI + -4);
  return;
}

// --------------------------------------------------

// Function: FUN_0044a98c
// Address: 0044a98c
// XREFS: None
void FUN_0044a98c(void)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x57);
  *(undefined4 *)(unaff_EDI + -0x5b) = *(undefined4 *)(unaff_ESI + -0x5b);
  *(undefined4 *)(unaff_EDI + -0x57) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4f);
  *(undefined4 *)(unaff_EDI + -0x53) = *(undefined4 *)(unaff_ESI + -0x53);
  *(undefined4 *)(unaff_EDI + -0x4f) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x47);
  *(undefined4 *)(unaff_EDI + -0x4b) = *(undefined4 *)(unaff_ESI + -0x4b);
  *(undefined4 *)(unaff_EDI + -0x47) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3f);
  *(undefined4 *)(unaff_EDI + -0x43) = *(undefined4 *)(unaff_ESI + -0x43);
  *(undefined4 *)(unaff_EDI + -0x3f) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x37);
  *(undefined4 *)(unaff_EDI + -0x3b) = *(undefined4 *)(unaff_ESI + -0x3b);
  *(undefined4 *)(unaff_EDI + -0x37) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2f);
  *(undefined4 *)(unaff_EDI + -0x33) = *(undefined4 *)(unaff_ESI + -0x33);
  *(undefined4 *)(unaff_EDI + -0x2f) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x27);
  *(undefined4 *)(unaff_EDI + -0x2b) = *(undefined4 *)(unaff_ESI + -0x2b);
  *(undefined4 *)(unaff_EDI + -0x27) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1f);
  *(undefined4 *)(unaff_EDI + -0x23) = *(undefined4 *)(unaff_ESI + -0x23);
  *(undefined4 *)(unaff_EDI + -0x1f) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x17);
  *(undefined4 *)(unaff_EDI + -0x1b) = *(undefined4 *)(unaff_ESI + -0x1b);
  *(undefined4 *)(unaff_EDI + -0x17) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0xf);
  *(undefined4 *)(unaff_EDI + -0x13) = *(undefined4 *)(unaff_ESI + -0x13);
  *(undefined4 *)(unaff_EDI + -0xf) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -7);
  uVar2 = *(undefined4 *)(unaff_ESI + -4);
  *(undefined4 *)(unaff_EDI + -0xb) = *(undefined4 *)(unaff_ESI + -0xb);
  *(undefined4 *)(unaff_EDI + -7) = uVar1;
  *(undefined4 *)(unaff_EDI + -4) = uVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044aa26
// Address: 0044aa26
// XREFS: None
void FUN_0044aa26(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + -0x56);
  *(undefined4 *)(unaff_EDI + -0x5a) = *(undefined4 *)(unaff_ESI + -0x5a);
  *(undefined4 *)(unaff_EDI + -0x56) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x4e);
  *(undefined4 *)(unaff_EDI + -0x52) = *(undefined4 *)(unaff_ESI + -0x52);
  *(undefined4 *)(unaff_EDI + -0x4e) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x46);
  *(undefined4 *)(unaff_EDI + -0x4a) = *(undefined4 *)(unaff_ESI + -0x4a);
  *(undefined4 *)(unaff_EDI + -0x46) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x3e);
  *(undefined4 *)(unaff_EDI + -0x42) = *(undefined4 *)(unaff_ESI + -0x42);
  *(undefined4 *)(unaff_EDI + -0x3e) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x36);
  *(undefined4 *)(unaff_EDI + -0x3a) = *(undefined4 *)(unaff_ESI + -0x3a);
  *(undefined4 *)(unaff_EDI + -0x36) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x2e);
  *(undefined4 *)(unaff_EDI + -0x32) = *(undefined4 *)(unaff_ESI + -0x32);
  *(undefined4 *)(unaff_EDI + -0x2e) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x26);
  *(undefined4 *)(unaff_EDI + -0x2a) = *(undefined4 *)(unaff_ESI + -0x2a);
  *(undefined4 *)(unaff_EDI + -0x26) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x1e);
  *(undefined4 *)(unaff_EDI + -0x22) = *(undefined4 *)(unaff_ESI + -0x22);
  *(undefined4 *)(unaff_EDI + -0x1e) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0x16);
  *(undefined4 *)(unaff_EDI + -0x1a) = *(undefined4 *)(unaff_ESI + -0x1a);
  *(undefined4 *)(unaff_EDI + -0x16) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -0xe);
  *(undefined4 *)(unaff_EDI + -0x12) = *(undefined4 *)(unaff_ESI + -0x12);
  *(undefined4 *)(unaff_EDI + -0xe) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -6);
  *(undefined4 *)(unaff_EDI + -10) = *(undefined4 *)(unaff_ESI + -10);
  *(undefined4 *)(unaff_EDI + -6) = uVar1;
  uVar1 = *(undefined4 *)(unaff_ESI + -2);
  *(char *)(unaff_EDI + -2) = (char)uVar1;
  *(char *)(unaff_EDI + -1) = (char)((uint)uVar1 >> 8);
  return;
}

// --------------------------------------------------

// Function: FUN_0044aac3
// Address: 0044aac3
// XREFS: None
void FUN_0044aac3(void)
{
  undefined1 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar2 = *(undefined4 *)(unaff_ESI + -0x55);
  *(undefined4 *)(unaff_EDI + -0x59) = *(undefined4 *)(unaff_ESI + -0x59);
  *(undefined4 *)(unaff_EDI + -0x55) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x4d);
  *(undefined4 *)(unaff_EDI + -0x51) = *(undefined4 *)(unaff_ESI + -0x51);
  *(undefined4 *)(unaff_EDI + -0x4d) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x45);
  *(undefined4 *)(unaff_EDI + -0x49) = *(undefined4 *)(unaff_ESI + -0x49);
  *(undefined4 *)(unaff_EDI + -0x45) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x3d);
  *(undefined4 *)(unaff_EDI + -0x41) = *(undefined4 *)(unaff_ESI + -0x41);
  *(undefined4 *)(unaff_EDI + -0x3d) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x35);
  *(undefined4 *)(unaff_EDI + -0x39) = *(undefined4 *)(unaff_ESI + -0x39);
  *(undefined4 *)(unaff_EDI + -0x35) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x2d);
  *(undefined4 *)(unaff_EDI + -0x31) = *(undefined4 *)(unaff_ESI + -0x31);
  *(undefined4 *)(unaff_EDI + -0x2d) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x25);
  *(undefined4 *)(unaff_EDI + -0x29) = *(undefined4 *)(unaff_ESI + -0x29);
  *(undefined4 *)(unaff_EDI + -0x25) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x1d);
  *(undefined4 *)(unaff_EDI + -0x21) = *(undefined4 *)(unaff_ESI + -0x21);
  *(undefined4 *)(unaff_EDI + -0x1d) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0x15);
  *(undefined4 *)(unaff_EDI + -0x19) = *(undefined4 *)(unaff_ESI + -0x19);
  *(undefined4 *)(unaff_EDI + -0x15) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -0xd);
  *(undefined4 *)(unaff_EDI + -0x11) = *(undefined4 *)(unaff_ESI + -0x11);
  *(undefined4 *)(unaff_EDI + -0xd) = uVar2;
  uVar2 = *(undefined4 *)(unaff_ESI + -5);
  uVar1 = *(undefined1 *)(unaff_ESI + -1);
  *(undefined4 *)(unaff_EDI + -9) = *(undefined4 *)(unaff_ESI + -9);
  *(undefined4 *)(unaff_EDI + -5) = uVar2;
  *(undefined1 *)(unaff_EDI + -1) = uVar1;
  return;
}

// --------------------------------------------------

// Function: _x_StandardMemCopy
// Address: 0044ab5d
// XREFS: None
void __fastcall _x_StandardMemCopy(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *unaff_ESI;
  undefined4 *puVar4;
  undefined4 *unaff_EDI;
  undefined4 *puVar5;
  
  uVar2 = -(int)unaff_EDI & 3;
  *unaff_EDI = *unaff_ESI;
  uVar1 = param_1 - uVar2 & 3;
  puVar4 = (undefined4 *)((int)unaff_ESI + uVar2);
  puVar5 = (undefined4 *)((int)unaff_EDI + uVar2);
  for (uVar3 = param_1 - uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)((uVar1 - 4) + (int)puVar5) = *(undefined4 *)((uVar1 - 4) + (int)puVar4);
  return;
}

// --------------------------------------------------

// Function: GetDXVersion
// Address: 0044dac0
// XREFS: setup
// [HELPER] s_Couldn_t_CreateSurface__: "Couldn't CreateSurface\n"
// [HELPER] s_Couldn_t_GetProcAddress_DInputCr: "Couldn't GetProcAddress DInputCreate\n"
// [HELPER] s_Couldn_t_LoadLibrary_DDraw__: "Couldn't LoadLibrary DDraw\n"
// [HELPER] s_Couldn_t_LoadLibrary_DInput__: "Couldn't LoadLibrary DInput\n"
// [HELPER] s_Couldn_t_QI_DDraw2__: "Couldn't QI DDraw2\n"
// [HELPER] s_Couldn_t_Set_coop_level__: "Couldn't Set coop level\n"
// [HELPER] s_Couldn_t_create_DDraw__: "Couldn't create DDraw\n"
// [HELPER] s_DDRAW_DLL: "DDRAW.DLL"
// [HELPER] s_DINPUT_DLL: "DINPUT.DLL"
// [HELPER] s_DirectDrawCreate: "DirectDrawCreate"
// [HELPER] s_DirectInputCreateA: "DirectInputCreateA"
/* WARNING: Variable defined which should be unmapped: pDDraw */
/* void __cdecl GetDXVersion(unsigned long *,unsigned long *) */

void __cdecl GetDXVersion(ulong *param_1,ulong *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  char **ppcVar5;
  int *unaff_retaddr;
  undefined **ppuVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piStack_14c;
  ulong *puStack_148;
  ulong *puStack_144;
  int *piStack_140;
  int *piStack_13c;
  undefined *puStack_138;
  int *piStack_134;
  int *piStack_130;
  char *apcStack_12c [2];
  IDirectDraw *pDDraw;
  IDirectPlay3 *dp3;
  IDirectDrawSurface *pSurf;
  IDirectDraw2 *pDDraw2;
  IDirectDrawSurface3 *pSurf3;
  _DDSURFACEDESC desc;
  _OSVERSIONINFOA osVer;
  undefined4 *puStack_4;
  
  apcStack_12c[1] = (char *)&osVer.dwMajorVersion;
  osVer.dwMajorVersion = 0x94;
  apcStack_12c[0] = (char *)0x44daf5;
  iVar1 = GetVersionExA();
  if (iVar1 == 0) {
    *unaff_retaddr = 0;
    *param_1 = 0;
    return;
  }
  if (osVer.dwPlatformId == 2) {
    *param_1 = 2;
    if (osVer.dwMajorVersion < 4) {
      *param_1 = 0;
      return;
    }
    if (osVer.dwMajorVersion != 4) {
      *unaff_retaddr = 0x501;
      return;
    }
    apcStack_12c[0] = s_DINPUT_DLL;
    *unaff_retaddr = 0x200;
    piStack_130 = (int *)0x44db68;
    piVar2 = (int *)LoadLibraryA();
    if (piVar2 == (int *)0x0) {
      piStack_130 = (int *)s_Couldn_t_LoadLibrary_DInput__;
      piStack_134 = (int *)0x44db79;
      OutputDebugStringA();
      return;
    }
    piStack_130 = (int *)s_DirectInputCreateA;
    puStack_138 = (undefined *)0x44db90;
    piStack_134 = piVar2;
    iVar1 = GetProcAddress();
    piStack_134 = (int *)0x44db99;
    piStack_130 = piVar2;
    FreeLibrary();
    if (iVar1 == 0) {
      piStack_134 = (int *)s_Couldn_t_GetProcAddress_DInputCr;
      puStack_138 = (undefined *)0x44dba8;
      OutputDebugStringA();
      return;
    }
    piStack_134 = (int *)0x0;
    *unaff_retaddr = 0x300;
    puStack_138 = (undefined *)0x44dbc1;
    iVar1 = CoInitialize();
    piStack_134 = (int *)&stack0xfffffee4;
    puStack_138 = &_IID_IDirectPlay3;
    piStack_13c = (int *)0x1;
    piStack_140 = (int *)0x0;
    puStack_144 = (ulong *)&_CLSID_DirectPlay;
    puStack_148 = (ulong *)0x44dbdc;
    iVar3 = CoCreateInstance();
    if (-1 < iVar3) {
      puStack_148 = (ulong *)piStack_130;
      piStack_14c = (int *)0x44dc03;
      (**(code **)(*piStack_130 + 8))();
      if (iVar1 != 0) {
        piStack_14c = (int *)0x44dc0d;
        CoUninitialize();
      }
      piStack_14c = (int *)0x44dc12;
      iVar1 = IsDPlay501a();
      *unaff_retaddr = (iVar1 != 0) + 0x500;
      return;
    }
    if (iVar1 != 0) {
      puStack_148 = (ulong *)0x44dbee;
      CoUninitialize();
      return;
    }
  }
  else {
    *param_1 = 1;
    if (0x549 < (osVer.dwBuildNumber & 0xffff)) {
      *unaff_retaddr = 0x501;
      return;
    }
    apcStack_12c[0] = s_DDRAW_DLL;
    piStack_130 = (int *)0x44dc87;
    piVar2 = (int *)LoadLibraryA();
    if (piVar2 == (int *)0x0) {
      piStack_130 = (int *)0x0;
      *puStack_4 = 0;
      *param_1 = 0;
      piStack_134 = (int *)0x44dc9f;
      FreeLibrary();
      return;
    }
    piStack_130 = (int *)s_DirectDrawCreate;
    puStack_138 = (undefined *)0x44dcb6;
    piStack_134 = piVar2;
    pcVar4 = (code *)GetProcAddress();
    if (pcVar4 == (code *)0x0) {
      *puStack_4 = 0;
      *param_1 = 0;
      piStack_134 = (int *)0x44dccc;
      piStack_130 = piVar2;
      FreeLibrary();
      piStack_134 = (int *)s_Couldn_t_LoadLibrary_DDraw__;
      puStack_138 = (undefined *)0x44dcd7;
      OutputDebugStringA();
      return;
    }
    piStack_134 = (int *)&stack0xfffffee4;
    piStack_130 = (int *)0x0;
    puStack_138 = (undefined *)0x0;
    piStack_13c = (int *)0x44dceb;
    iVar1 = (*pcVar4)();
    if (iVar1 < 0) {
      *(undefined4 *)osVer.szCSDVersion._116_4_ = 0;
      *param_1 = 0;
      piStack_140 = (int *)0x44dd01;
      piStack_13c = piVar2;
      FreeLibrary();
      piStack_140 = (int *)s_Couldn_t_create_DDraw__;
      puStack_144 = (ulong *)0x44dd0c;
      OutputDebugStringA();
      return;
    }
    piStack_13c = (int *)&stack0xfffffee4;
    puVar9 = *(undefined4 **)apcStack_12c[1];
    piStack_140 = (int *)&_IID_IDirectDraw2;
    puStack_144 = (ulong *)apcStack_12c[1];
    *(undefined4 *)osVer.szCSDVersion._116_4_ = 0x100;
    puStack_148 = (ulong *)0x44dd37;
    iVar1 = (*(code *)*puVar9)();
    if (iVar1 < 0) {
      puStack_148 = (ulong *)piStack_134;
      piStack_14c = (int *)0x44dd45;
      (**(code **)(*piStack_134 + 8))();
      piStack_14c = piVar2;
      FreeLibrary();
      OutputDebugStringA(s_Couldn_t_QI_DDraw2__);
      return;
    }
    puStack_148 = (ulong *)apcStack_12c[1];
    piStack_14c = (int *)0x44dd6c;
    (**(code **)(*(ulong *)apcStack_12c[1] + 8))();
    piStack_14c = (int *)s_DINPUT_DLL;
    *(undefined4 *)osVer.szCSDVersion._116_4_ = 0x200;
    iVar1 = LoadLibraryA();
    if (iVar1 == 0) {
      OutputDebugStringA(s_Couldn_t_LoadLibrary_DInput__);
      (**(code **)(*piStack_140 + 8))(piStack_140);
      FreeLibrary(piVar2);
      return;
    }
    puStack_138 = (undefined *)GetProcAddress(iVar1,s_DirectInputCreateA);
    FreeLibrary(iVar1);
    if (piStack_13c == (int *)0x0) {
      FreeLibrary(piVar2);
      (**(code **)(*puStack_144 + 8))(puStack_144);
      OutputDebugStringA(s_Couldn_t_GetProcAddress_DInputCr);
      return;
    }
    puVar9 = (undefined4 *)0x8;
    ppcVar5 = apcStack_12c;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar5 = (char *)0x0;
      ppcVar5 = ppcVar5 + 1;
    }
    *(undefined4 *)osVer.szCSDVersion._116_4_ = 0x300;
    apcStack_12c[0] = (char *)0x6c;
    apcStack_12c[1] = (char *)0x1;
    piVar8 = piStack_140;
    iVar1 = (**(code **)(*piStack_140 + 0x50))(piStack_140,0);
    if (iVar1 < 0) {
      (**(code **)(*piStack_14c + 8))(piStack_14c);
      FreeLibrary(piVar2);
      *(undefined4 *)osVer.szCSDVersion._116_4_ = 0;
      OutputDebugStringA(s_Couldn_t_Set_coop_level__);
      return;
    }
    piVar7 = (int *)0x0;
    ppuVar6 = &puStack_138;
    iVar1 = (**(code **)(*piStack_14c + 0x18))(piStack_14c,ppuVar6,&puStack_144);
    if (iVar1 < 0) {
      (**(code **)(*piVar8 + 8))(piVar8);
      FreeLibrary(piVar2);
      *(undefined4 *)osVer.szCSDVersion._116_4_ = 0;
      OutputDebugStringA(s_Couldn_t_CreateSurface__);
      return;
    }
    iVar1 = (**(code **)*puVar9)(puVar9,&_IID_IDirectDrawSurface3,&piStack_14c);
    if (-1 < iVar1) {
      iVar1 = IsDPlay501a();
      *(uint *)osVer.szCSDVersion._116_4_ = (iVar1 != 0) + 0x500;
      (**(code **)(*piVar7 + 8))(piVar7);
    }
    (**(code **)(*ppuVar6 + 8))(ppuVar6);
    FreeLibrary(piVar2);
  }
  return;
}

// --------------------------------------------------

// Function: IsDPlay501a
// Address: 0044dee0
// XREFS: GetDXVersion
// [HELPER] s__: "}"
// [HELPER] s_dplayx_dll: "dplayx.dll"
/* WARNING: Variable defined which should be unmapped: verInfo */
/* int __cdecl IsDPlay501a(void) */

int __cdecl IsDPlay501a(void)
{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  uint *puVar6;
  uint uStack_24;
  char *pcStack_1c;
  uint *puStack_18;
  tagVS_FIXEDFILEINFO *verInfo;
  ulong zero;
  uint verSize;
  
  puStack_18 = &verSize;
  pcStack_1c = s_dplayx_dll;
  uVar1 = _GetFileVersionInfoSizeA_8();
  if (uVar1 == 0) {
    GetLastError();
    return 0;
  }
  uStack_24 = 0x44df0e;
  pvVar2 = operator_new(uVar1);
  if (pvVar2 != (void *)0x0) {
    uStack_24 = uVar1;
    iVar3 = _GetFileVersionInfoA_16(s_dplayx_dll,0);
    if (iVar3 == 0) {
      GetLastError();
      return 0;
    }
    puVar6 = &uStack_24;
    iVar3 = _VerQueryValueA_16(pvVar2,s__,puVar6,&pcStack_1c);
    if (iVar3 == 0) {
      return 0;
    }
    bVar4 = puVar6[2] < 0x40005;
    bVar5 = puVar6[2] == 0x40005;
    if (bVar5) {
      if (0x1062e < puVar6[3]) {
        return 1;
      }
      bVar4 = false;
      bVar5 = true;
    }
    if (!bVar4 && !bVar5) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044ebd2
// Address: 0044ebd2
// XREFS: None
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_0044efe9
// Address: 0044efe9
// XREFS: None
void __fastcall FUN_0044efe9(undefined4 param_1,undefined2 param_2)
{
  byte bVar1;
  char cVar2;
  uint in_EAX;
  char cVar3;
  char cVar5;
  undefined2 uVar4;
  char unaff_BL;
  char cVar6;
  
  bVar1 = (byte)in_EAX;
  out(param_2,bVar1);
  out(param_2,in_EAX);
  out(param_2,in_EAX);
  out(param_2,in_EAX);
  out(param_2,in_EAX);
  cVar2 = (char)(in_EAX >> 8);
  cVar6 = unaff_BL + cVar2 * '\x02';
  out(param_2,in_EAX);
  out(param_2,in_EAX);
  *(char *)(in_EAX - 0x12) = *(char *)(in_EAX - 0x12) + (char)param_2;
  out(param_2,bVar1);
  cVar5 = (char)((ushort)param_2 >> 8);
  cVar3 = (char)param_2 + cVar6;
  out(CONCAT11(cVar5,cVar3),bVar1);
  cVar3 = cVar3 + cVar6;
  uVar4 = CONCAT11(cVar5,cVar3);
  out(uVar4,bVar1);
  out(uVar4,bVar1);
  out(uVar4,bVar1);
  out(uVar4,bVar1);
  out(uVar4,bVar1);
  out(CONCAT11(cVar5 + cVar2,cVar3),bVar1);
  *(char *)(in_EAX + 0x8a909090) = *(char *)(in_EAX + 0x8a909090) + cVar3;
  if ((in_EAX & 4) != 0) {
    *(byte *)(CONCAT22((short)((uint)param_1 >> 0x10),
                       CONCAT11((char)((uint)param_1 >> 8) + unaff_BL * '\x02' + cVar6 * '\x02',
                                (char)param_1)) + 0x24) = bVar1 & 4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00450b09
// Address: 00450b09
// XREFS: None
void __fastcall FUN_00450b09(uint param_1,uint *param_2,float param_3,uchar param_4)
{
  char *pcVar1;
  short *psVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  char cVar5;
  ushort uVar6;
  short sVar7;
  undefined4 in_EAX;
  undefined3 uVar9;
  uint uVar10;
  uint uVar11;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_EDI;
  int iVar12;
  uint uVar8;
  
  *param_2 = *param_2 & param_1;
  *(char *)(unaff_EBX + 10) = *(char *)(unaff_EBX + 10) + (char)param_1;
  *(char *)(param_1 + 0x9700450a) = *(char *)(param_1 + 0x9700450a) + (char)param_1;
  uVar9 = (undefined3)((uint)in_EAX >> 8);
  puVar3 = unaff_EDI + 1;
  *unaff_EDI = CONCAT31(uVar9,(byte)in_EAX | *(byte *)(unaff_EBP + 2));
  uVar4 = in(10);
  pcVar1 = (char *)(CONCAT31(uVar9,uVar4) + -0x6f6f6f70);
  *pcVar1 = *pcVar1 + (char)param_2;
  switch(param_4) {
  case '\x06':
    fRamcc0045ce = param_3 + fRamcc0045ce;
    return;
  default:
    RGE_Master_Action_Object::modify_delta((RGE_Master_Action_Object *)0xcc00450a,param_3,param_4);
    break;
  case '\b':
    uVar8 = __ftol(puVar3);
    uVar6 = (ushort)uVar8;
    if (iRamcc00460e != 0) {
      uVar11 = 0;
      if (0 < sRamcc00460c) {
        uVar10 = 0;
        while (iVar12 = iRamcc00460e,
              (int)*(short *)(iRamcc00460e + uVar10 * 4) != (uVar8 >> 8 & 0xff)) {
          uVar11 = uVar11 + 1;
          uVar10 = uVar11 & 0xffff;
          if ((int)sRamcc00460c <= (int)uVar10) {
            return;
          }
        }
LAB_00450c01:
        psVar2 = (short *)(iVar12 + 2 + (uVar11 & 0xffff) * 4);
        *psVar2 = *psVar2 + (uVar6 & 0xff);
        return;
      }
    }
    break;
  case '\t':
    uVar8 = __ftol(puVar3);
    uVar6 = (ushort)uVar8;
    if (iRamcc004616 != 0) {
      uVar11 = 0;
      if (0 < sRamcc004612) {
        uVar10 = 0;
        while (iVar12 = iRamcc004616,
              (int)*(short *)(iRamcc004616 + uVar10 * 4) != (uVar8 >> 8 & 0xff)) {
          uVar11 = uVar11 + 1;
          uVar10 = uVar11 & 0xffff;
          if ((int)sRamcc004612 <= (int)uVar10) {
            return;
          }
        }
        goto LAB_00450c01;
      }
    }
    break;
  case '\n':
    fRamcc00462a = param_3 + fRamcc00462a;
    return;
  case '\v':
    sVar7 = __ftol(puVar3);
    sRamcc004630 = sRamcc004630 + sVar7;
    return;
  case '\f':
    fRamcc00461e = param_3 + fRamcc00461e;
    return;
  case '\x0f':
    cVar5 = __ftol(puVar3);
    cRamcc00460a = cRamcc00460a + cVar5;
    return;
  case '\x10':
    sVar7 = __ftol(puVar3);
    sRamcc00462e = sRamcc00462e + sVar7;
    return;
  case '\x12':
    uRamcc00461a = __ftol(puVar3);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00450cc7
// Address: 00450cc7
// XREFS: None
void __fastcall FUN_00450cc7(int param_1,int param_2,float param_3,uchar param_4)
{
  char *pcVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint in_EAX;
  RGE_Master_Action_Object *this;
  char cVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  byte in_CF;
  
  this = (RGE_Master_Action_Object *)((param_1 - *(int *)(in_EAX * 2 + 0x450cb400)) - (uint)in_CF);
  *(char *)(unaff_EBX + 0xb) = *(char *)(unaff_EBX + 0xb) + (char)(in_EAX >> 8);
  cVar4 = (char)((uint)param_2 >> 8);
  *(char *)(param_2 + 0x3100450b) = *(char *)(param_2 + 0x3100450b) + cVar4;
  *(char *)(unaff_EDI + 0xc) = *(char *)(unaff_EDI + 0xc) + (char)(in_EAX | 0x45);
  *(char *)(unaff_EBP + 0xe) = *(char *)(unaff_EBP + 0xe) + (char)unaff_EBX;
  (&stack0x0cb40045)[(int)this] = (&stack0x0cb40045)[(int)this] + cVar4;
  *(char *)(unaff_EBX + 0xc) = *(char *)(unaff_EBX + 0xc) + cVar4;
  pcVar1 = (char *)((in_EAX | 0x45) + 0xb400450c);
  *pcVar1 = *pcVar1 + (char)this;
  *(char *)(unaff_ESI + -0x6fffbaf4) = *(char *)(unaff_ESI + -0x6fffbaf4) + (char)unaff_EBX;
  switch(param_4) {
  case '\x06':
    this->_padding_ = (int)(param_3 * (float)this->_padding_);
    return;
  default:
    RGE_Master_Action_Object::modify_percent(this,param_3,param_4);
switchD_00450d1a_caseD_8:
    return;
  case '\b':
  case '\t':
    goto switchD_00450d1a_caseD_8;
  case '\n':
    this[1]._padding_ = (int)(param_3 * (float)this[1]._padding_);
    return;
  case '\v':
    uVar3 = __ftol();
    *(undefined2 *)((int)&this[1]._padding_ + 2) = uVar3;
    return;
  case '\f':
    this[1]._padding_ = (int)(param_3 * (float)this[1]._padding_);
    return;
  case '\x0f':
    uVar2 = __ftol();
    *(undefined1 *)&this[1]._padding_ = uVar2;
    return;
  case '\x10':
    uVar3 = __ftol();
    *(undefined2 *)&this[1]._padding_ = uVar3;
    return;
  case '\x12':
    uVar3 = __ftol();
    *(undefined2 *)&this[1]._padding_ = uVar3;
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00450dea
// Address: 00450dea
// XREFS: None
void __fastcall
FUN_00450dea(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  char *pcVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  uint in_EAX;
  RGE_Master_Action_Object *this;
  char unaff_BL;
  
  iVar4 = param_5;
  uRam0dd90045 = uRam0dd90045 & param_1;
  cRam4900450d = cRam4900450d + (char)((uint)param_2 >> 8) + (char)(in_EAX >> 8);
  pcVar1 = (char *)((in_EAX | 0xdff0045) + 0xa200450d);
  *pcVar1 = *pcVar1 + (char)(in_EAX | 0xdff0045);
  this = (RGE_Master_Action_Object *)
         CONCAT22((short)(param_1 >> 0x10),
                  CONCAT11((char)(param_1 >> 8) + ((byte)in_EAX | 0x45),(char)param_1 + unaff_BL));
  RGE_Master_Action_Object::save(this,param_5);
  iVar3 = this[1]._padding_;
  if (iVar3 == 0) {
    param_5 = 0xffffffff;
  }
  else {
    param_5 = CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(iVar3 + 0x72));
  }
  rge_write(iVar4,&this[1]._padding_,1);
  rge_write(iVar4,&this[1]._padding_,2);
  if ((void *)this[1]._padding_ != (void *)0x0) {
    rge_write(iVar4,(void *)this[1]._padding_,(int)(short)this[1]._padding_ << 2);
  }
  psVar2 = (short *)((int)&this[1]._padding_ + 2);
  rge_write(iVar4,psVar2,2);
  if ((void *)this[1]._padding_ != (void *)0x0) {
    rge_write(iVar4,(void *)this[1]._padding_,(int)*psVar2 << 2);
  }
  rge_write(iVar4,&this[1]._padding_,2);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,2);
  rge_write(iVar4,(void *)((int)&this[1]._padding_ + 2),2);
  rge_write(iVar4,&this[1]._padding_,1);
  rge_write(iVar4,(void *)((int)&this[1]._padding_ + 2),2);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,1);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&param_5,2);
  rge_write(iVar4,&this[1]._padding_,2);
  rge_write(iVar4,(void *)((int)&this[1]._padding_ + 2),2);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  return;
}

// --------------------------------------------------

// Function: FUN_00453513
// Address: 00453513
// XREFS: None
float10 __fastcall FUN_00453513(int param_1,int *param_2)
{
  undefined1 *puVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  uint in_EAX;
  char *pcVar5;
  int *piVar6;
  int unaff_ESI;
  undefined2 in_ES;
  float10 in_ST0;
  float10 fVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float fStack_18;
  
  puVar1 = (undefined1 *)(in_EAX * 2 + 0x4534d100);
  *puVar1 = *puVar1;
  fVar7 = in_ST0 / (float10)*(double *)(in_EAX * 2 + 0x4534ec00);
  *(byte *)param_2 = (char)*param_2 + ((byte)in_EAX ^ 0x45);
  pcVar5 = (char *)(in_EAX ^ 0x350f0000);
  *pcVar5 = *pcVar5 + (byte)in_EAX;
  *param_2 = (int)(pcVar5 + *param_2);
  iVar2 = *(int *)(pcVar5 + unaff_ESI);
  fStack_18 = (float)CONCAT22(fStack_18._2_2_,in_ES);
  piVar6 = (int *)(pcVar5 + iVar2 + 0x24448b90);
  *(byte *)(unaff_ESI + 0x25) = *(byte *)(unaff_ESI + 0x25) | (byte)param_2;
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + (char)piVar6;
  switch(pcVar5 + iVar2) {
  case (char *)0xdbbb7470:
    sVar4 = __ftol();
    *(short *)(param_1 + 0x26) = *(short *)(param_1 + 0x26) + sVar4;
    return extraout_ST0;
  case (char *)0xdbbb7471:
    *(float *)(param_1 + 0x28) = fStack_18 + *(float *)(param_1 + 0x28);
    return fVar7;
  case (char *)0xdbbb7472:
    cVar3 = __ftol();
    *(char *)(param_1 + 0x2c) = *(char *)(param_1 + 0x2c) + cVar3;
    return extraout_ST0_00;
  case (char *)0xdbbb7473:
    *(float *)(param_1 + 0x30) = fStack_18 + *(float *)(param_1 + 0x30);
    return fVar7;
  case (char *)0xdbbb7474:
    *(float *)(param_1 + 0x34) = fStack_18 + *(float *)(param_1 + 0x34);
    return fVar7;
  case (char *)0xdbbb747e:
    sVar4 = __ftol();
    *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + sVar4;
    fVar7 = extraout_ST0_01;
  }
  return fVar7;
}

// --------------------------------------------------

// Function: FUN_00453695
// Address: 00453695
// XREFS: None
void __fastcall FUN_00453695(char *param_1,int *param_2)
{
  char *pcVar1;
  undefined4 in_EAX;
  uint uVar2;
  char cVar3;
  undefined4 unaff_EBX;
  short sVar4;
  char *pcVar5;
  int unaff_ESI;
  char *unaff_EDI;
  char *pcVar6;
  int iVar7;
  undefined2 in_ES;
  char in_CF;
  uint uStack_40;
  int *piStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  int *piStack_28;
  undefined4 auStack_24 [2];
  char *pcStack_1c;
  
  iVar7 = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + '6' + in_CF);
  *param_1 = *param_1 + (char)((uint)param_2 >> 8);
  cVar3 = (char)((uint)unaff_EBX >> 8);
  *unaff_EDI = *unaff_EDI + cVar3;
  pcVar1 = (char *)(unaff_ESI * 2 + 0x45);
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  *(char *)((int)param_2 + 0x36) = *(char *)((int)param_2 + 0x36) + (char)((uint)param_1 >> 8);
  pcVar1 = (char *)(iVar7 + 0x36);
  *pcVar1 = *pcVar1 + cVar3;
  param_1[0x4536] = param_1[0x4536] + (char)param_2;
  *param_2 = *param_2 + iVar7;
  pcStack_1c = (char *)CONCAT22(pcStack_1c._2_2_,in_ES);
  pcVar1 = pcStack_1c;
  uVar2 = 0xffffffff;
  iVar7 = *(int *)(param_1 + 0x40);
  piStack_3c = (int *)0xffffffff;
  uStack_38 = 0xffffffff;
  uStack_34 = 0xffffffff;
  uStack_30 = 0xffffffff;
  auStack_24[0] = 0xffffffff;
  piStack_28 = (int *)0xffffffff;
  if (iVar7 != 0) {
    uStack_30 = CONCAT22((short)((uint)iVar7 >> 0x10),*(undefined2 *)(iVar7 + 0xc));
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    param_2 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),
                              *(undefined2 *)(*(int *)(param_1 + 0x3c) + 0xc));
    piStack_28 = param_2;
  }
  iVar7 = *(int *)(param_1 + 0x44);
  if (iVar7 != 0) {
    auStack_24[0] = CONCAT22((short)((uint)iVar7 >> 0x10),*(undefined2 *)(iVar7 + 0xc));
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    param_2 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),
                              *(undefined2 *)(*(int *)(param_1 + 0x18) + 0x72));
    piStack_3c = param_2;
  }
  iVar7 = *(int *)(param_1 + 0x1c);
  if (iVar7 != 0) {
    uStack_38 = CONCAT22((short)((uint)iVar7 >> 0x10),*(undefined2 *)(iVar7 + 0x72));
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    uStack_34 = CONCAT22((short)((uint)param_2 >> 0x10),
                         *(undefined2 *)(*(int *)(param_1 + 0x20) + 0x72));
  }
  pcVar5 = *(char **)(param_1 + 8);
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  uStack_40 = ~uVar2 - 1;
  if (0 < (short)uStack_40) {
    uStack_40 = ~uVar2;
  }
  rge_write((int)pcStack_1c,param_1 + 4,1);
  rge_write((int)pcVar1,&uStack_40,2);
  rge_write((int)pcVar1,param_1 + 0x10,2);
  rge_write((int)pcVar1,param_1 + 0xc,2);
  rge_write((int)pcVar1,param_1 + 0xe,2);
  rge_write((int)pcVar1,param_1 + 0x14,2);
  rge_write((int)pcVar1,&piStack_3c,2);
  rge_write((int)pcVar1,&uStack_38,2);
  rge_write((int)pcVar1,&uStack_34,2);
  rge_write((int)pcVar1,param_1 + 0x24,1);
  rge_write((int)pcVar1,param_1 + 0x26,2);
  rge_write((int)pcVar1,param_1 + 0x28,4);
  rge_write((int)pcVar1,param_1 + 0x2c,1);
  rge_write((int)pcVar1,param_1 + 0x30,4);
  rge_write((int)pcVar1,param_1 + 0x34,4);
  rge_write((int)pcVar1,param_1 + 0x38,4);
  rge_write((int)pcVar1,&uStack_30,2);
  rge_write((int)pcVar1,param_1 + 0x48,2);
  rge_write((int)pcVar1,param_1 + 0x4a,1);
  rge_write((int)pcVar1,param_1 + 0x4b,1);
  rge_write((int)pcVar1,param_1 + 0x4c,2);
  rge_write((int)pcVar1,param_1 + 0x4e,1);
  rge_write((int)pcVar1,param_1 + 0x50,2);
  rge_write((int)pcVar1,param_1 + 0x52,1);
  rge_write((int)pcVar1,param_1 + 0x54,2);
  rge_write((int)pcVar1,param_1 + 0x56,2);
  rge_write((int)pcVar1,param_1 + 0x58,2);
  rge_write((int)pcVar1,param_1 + 0x5a,2);
  rge_write((int)pcVar1,param_1 + 0x5c,4);
  rge_write((int)pcVar1,param_1 + 0x60,4);
  rge_write((int)pcVar1,param_1 + 100,1);
  rge_write((int)pcVar1,param_1 + 0x65,1);
  rge_write((int)pcVar1,param_1 + 0x66,2);
  rge_write((int)pcVar1,param_1 + 0x68,1);
  rge_write((int)pcVar1,param_1 + 0x7c,2);
  rge_write((int)pcVar1,param_1 + 0x80,4);
  rge_write((int)pcVar1,param_1 + 0x8b,1);
  rge_write((int)pcVar1,param_1 + 0x8c,1);
  rge_write((int)pcVar1,param_1 + 0x8d,1);
  rge_write((int)pcVar1,param_1 + 0x8e,1);
  rge_write((int)pcVar1,param_1 + 0x8f,1);
  rge_write((int)pcVar1,param_1 + 0x84,4);
  rge_write((int)pcVar1,param_1 + 0x90,1);
  rge_write((int)pcVar1,param_1 + 0x98,4);
  rge_write((int)pcVar1,param_1 + 0x9c,4);
  rge_write((int)pcVar1,param_1 + 0xa0,4);
  rge_write((int)pcVar1,param_1 + 0xa4,1);
  rge_write((int)pcVar1,param_1 + 0xa5,1);
  rge_write((int)pcVar1,param_1 + 0xa6,1);
  rge_write((int)pcVar1,param_1 + 0xa7,1);
  rge_write((int)pcVar1,param_1 + 0xa8,1);
  rge_write((int)pcVar1,param_1 + 0xa9,1);
  rge_write((int)pcVar1,param_1 + 0xac,4);
  rge_write((int)pcVar1,param_1 + 0xb0,4);
  rge_write((int)pcVar1,param_1 + 0xb4,4);
  pcStack_1c = param_1 + 0x88;
  pcVar5 = param_1 + 0x70;
  pcVar6 = param_1 + 0x6a;
  iStack_2c = 3;
  do {
    rge_write((int)pcVar1,pcVar6,2);
    rge_write((int)pcVar1,pcVar5,4);
    rge_write((int)pcVar1,pcStack_1c,1);
    pcVar6 = pcVar6 + 2;
    pcVar5 = pcVar5 + 4;
    pcStack_1c = pcStack_1c + 1;
    iStack_2c = iStack_2c + -1;
  } while (iStack_2c != 0);
  rge_write((int)pcVar1,param_1 + 0x93,1);
  cVar3 = param_1[0x93];
  if (cVar3 != '\0') {
    sVar4 = 0;
    if (cVar3 != '\0') {
      do {
        iVar7 = sVar4 * 8;
        rge_write((int)pcVar1,(void *)(*(int *)(*(int *)(param_1 + 0x94) + iVar7) + 0x72),2);
        rge_write((int)pcVar1,(void *)(*(int *)(param_1 + 0x94) + 4 + iVar7),2);
        rge_write((int)pcVar1,(void *)(*(int *)(param_1 + 0x94) + 5 + iVar7),1);
        sVar4 = sVar4 + 1;
      } while (sVar4 < (short)(ushort)(byte)param_1[0x93]);
    }
  }
  rge_write((int)pcVar1,&piStack_28,2);
  rge_write((int)pcVar1,auStack_24,2);
  rge_write((int)pcVar1,param_1 + 0x91,1);
  rge_write((int)pcVar1,param_1 + 0x92,1);
  if ((short)uStack_40 != 0) {
    rge_write((int)pcVar1,*(void **)(param_1 + 8),(int)(short)uStack_40);
  }
  rge_write((int)pcVar1,param_1 + 0x12,2);
  return;
}

// --------------------------------------------------

// Function: _WinMain@16
// Address: 004549e0
// XREFS: entry
// [HELPER] s_00_03_01_0717: "00.03.01.0717"
// [HELPER] s_: ""
// [HELPER] s_AOE: "AOE"
// [HELPER] s_Age_of_Empires__Roman_Expansion: "Age of Empires, Roman Expansion"
// [HELPER] s_AppIcon: "AppIcon"
// [HELPER] s_Software_Microsoft_Games_Age_of_: "Software\Microsoft\Games\Age of Empires\1.00"
// [HELPER] s__s: "%s"
// [HELPER] s_avi_: "avi\"
// [HELPER] s_campaign_: "campaign\"
// [HELPER] s_data2_: "data2\"
// [HELPER] s_data2_empires_dat: "data2\empires.dat"
// [HELPER] s_mcursors: "mcursors"
// [HELPER] s_palette: "palette"
// [HELPER] s_savegame_: "savegame\"
// [HELPER] s_scenario_: "scenario\"
// [HELPER] s_sound_: "sound\"
// [HELPER] s_tr_wrld_txt: "tr_wrld.txt"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Variable defined which should be unmapped: retval */

int _WinMain_16(void *param_1,undefined4 param_2,char *param_3,undefined4 param_4)
{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_EBP;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  int retval;
  int error_code;
  RGE_Prog_Info info;
  char title [256];
  char msg [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055da7e;
                    /* language.dll match for 0x1440: "Axeman" */
  *unaff_FS_OFFSET = &local_c;
  uVar4 = 0xffffffff;
  pcVar7 = info.prog_name;
  pcVar8 = &s_Age_of_Empires__Roman_Expansion;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = info.prog_version;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_00_03_01_0717;
  do {
    pcVar6 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  sprintf(info.prog_title + 4,s__s,info.prog_name + 4);
  uVar4 = 0xffffffff;
  pcVar7 = &s_tr_wrld_txt;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.world_db_file;
  pcVar6 = info.game_data_file;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_data2_empires_dat;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.registry_key;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar6 = pcVar6 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar8 = &s_Software_Microsoft_Games_Age_of_;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = info.cmd_line;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar7 = param_3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = info.icon_name;
  pcVar7 = pcVar7 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_AppIcon;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.menu_name;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar6 = pcVar6 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar8 = s_;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = info.pal_file;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_palette;
  do {
    pcVar6 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.cursor_file;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar8 = &s_mcursors;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  pcVar6 = info.vol_name;
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_AOE;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar6 = pcVar6 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  }
  info.registry_key._0_4_ = param_2;
  info.prev_instance = param_1;
  info.icon_name._0_4_ = param_4;
  info.mouse_scroll_max_dist = 1.17709e-43;
  info.key_scroll_max_dist = 1.17709e-43;
  info.game_guid.Data4[0] = (uchar)DAT_00570654;
  info.game_guid.Data4[1] = DAT_00570654._1_1_;
  info.game_guid.Data4[2] = DAT_00570654._2_1_;
  info.game_guid.Data4[3] = DAT_00570654._3_1_;
  info.game_guid.Data2 = (ushort)_TRIBE_GUID;
  info.game_guid.Data3 = _TRIBE_GUID._2_2_;
  info.zone_guid.Data1 = DAT_0057065c;
  info.game_guid.Data4[4] = (uchar)DAT_00570658;
  info.game_guid.Data4[5] = DAT_00570658._1_1_;
  info.game_guid.Data4[6] = DAT_00570658._2_1_;
  info.game_guid.Data4[7] = DAT_00570658._3_1_;
  info.zone_guid.Data4[0] = (uchar)DAT_00570664;
  info.zone_guid.Data4[1] = DAT_00570664._1_1_;
  info.zone_guid.Data4[2] = DAT_00570664._2_1_;
  info.zone_guid.Data4[3] = DAT_00570664._3_1_;
  info.zone_guid.Data2 = (ushort)_ZONE_GUID;
  info.zone_guid.Data3 = _ZONE_GUID._2_2_;
  info.data_dir[0] = (char)DAT_0057066c;
  info.data_dir[1] = DAT_0057066c._1_1_;
  info.data_dir[2] = DAT_0057066c._2_1_;
  info.data_dir[3] = DAT_0057066c._3_1_;
  info.verify_cd = 0;
  info.max_players_per_cd = 1;
  info.instance = &DAT_00000003;
  info.check_expiration = 8;
  info.expire_month = 0;
  info.expire_day = 0;
  info.expire_year = 0;
  info._2182_2_ = 0;
  info.update_interval._0_2_ = 0;
  info.check_multi_copies = 1;
  info.skip_startup = 1;
  info.full_screen = 0;
  info.fixed_window_size = 1;
  info.use_dir_draw = 1;
  info.use_sys_mem = 1;
  info.use_music = 0;
  info.use_sound = 1;
  info.use_cd_audio = 1;
  info.auto_scroll = 1;
  info.mouse_scroll_edge = 1;
  info.mouse_scroll_interval = 3;
  info.key_scroll_interval = 0x40800000;
  info.key_scroll_object_move = 4.0;
  info.interface_style = -0x3333;
  info._2270_2_ = 0x3d4c;
  info.main_wid._0_2_ = 2;
  info.use_ima = 0;
  info.use_midi = 0;
  info.use_wave_music = 0;
  info.fast_view = 0;
  info.main_hgt = 800;
  info.game_guid.Data1 = 600;
  info.zone_guid.Data4[4] = (uchar)DAT_00570668;
  info.zone_guid.Data4[5] = DAT_00570668._1_1_;
  info.zone_guid.Data4[6] = DAT_00570668._2_1_;
  info.zone_guid.Data4[7] = DAT_00570668._3_1_;
  pcVar7 = info.data_dir;
  uVar4 = 0xffffffff;
  pcVar8 = &s_data2_;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_sound_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.sounds_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = s_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.graphics_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_savegame_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.save_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_scenario_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.scenario_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = info.campaign_dir;
  pcVar8 = &s_campaign_;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_data2_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.resource_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_data2_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.ai_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_avi_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.avi_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  error_code = 0;
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  info.prog_name._0_4_ = operator_new(0x1254);
  local_4 = 0;
  if ((TRIBE_Game *)info.prog_name._0_4_ == (TRIBE_Game *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)TRIBE_Game::TRIBE_Game
                              ((TRIBE_Game *)info.prog_name._0_4_,
                               (RGE_Prog_Info *)(info.prog_name + 4),1);
  }
  local_4 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    puVar2 = (undefined4 *)*piVar3;
    info.prog_name._0_4_ = (*(code *)puVar2[6])();
    if (info.prog_name._0_4_ == 0) {
      error_code = (*(code *)puVar2[1])();
      (*(code *)puVar2[6])();
      (*(code *)*puVar2)(1);
    }
    else if (info.prog_name._0_4_ != 4) {
                    /* language.dll match for 0x7d1: "Error" */
      (*(code *)puVar2[8])(0x7d1,title + 4,0x100);
      (*(code *)puVar2[10])(1,unaff_EBP,0,title + 0xf8,0x100);
      (*(code *)*puVar2)(1);
      MessageBoxA(0,msg + 4,title + 4,0x10);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return error_code;
}

// --------------------------------------------------

// Function: FUN_00455eda
// Address: 00455eda
// XREFS: None
void __fastcall
FUN_00455eda(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            uint param_6)
{
  uint uVar1;
  undefined4 in_EAX;
  int iVar2;
  char cVar4;
  short sVar3;
  int unaff_EBX;
  int *piVar5;
  short sVar6;
  undefined4 *unaff_EDI;
  
  uVar1 = param_6;
  *unaff_EDI = in_EAX;
  cVar4 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_EBX + -0x54ffbaa2) = *(char *)(unaff_EBX + -0x54ffbaa2) + cVar4;
  *(char *)(unaff_EBX + -0x54ffbaa2) = *(char *)(unaff_EBX + -0x54ffbaa2) + cVar4;
  *(char *)(param_4 + 0x455e) = *(char *)(param_4 + 0x455e) + (char)((uint)param_2 >> 8);
  rge_write(param_6,(void *)(param_1 + 8),4);
  piVar5 = (int *)(param_1 + 0xc);
  rge_write(uVar1,piVar5,4);
  iVar2 = *piVar5;
  sVar3 = 0;
  if (0 < iVar2) {
    do {
      sVar6 = 0;
      if (0 < iVar2) {
        iVar2 = 0;
        do {
          param_6 = CONCAT31(param_6._1_3_,
                             *(undefined1 *)
                              (*(int *)(*(int *)(param_1 + 0x8d8c) + sVar3 * 4) + 5 + iVar2 * 0x18))
                    & 0xffffff1f;
          rge_write(uVar1,&param_6,1);
          rge_write(uVar1,&stack0x00000002,1);
          rge_write(uVar1,&stack0x00000003,1);
          sVar6 = sVar6 + 1;
          iVar2 = (int)sVar6;
        } while (iVar2 < *piVar5);
      }
      iVar2 = *piVar5;
      sVar3 = sVar3 + 1;
    } while (sVar3 < iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00459352
// Address: 00459352
// XREFS: None
uint __fastcall FUN_00459352(char *param_1,uint param_2,short param_3,short param_4)
{
  char *pcVar1;
  char *in_EAX;
  int iVar2;
  uint uVar3;
  char cVar6;
  char cVar7;
  char *unaff_EBX;
  int unaff_EBP;
  char *unaff_ESI;
  int unaff_EDI;
  char cVar4;
  undefined2 uVar5;
  
  *(uint *)(param_2 + 0x90ce0045) = *(uint *)(param_2 + 0x90ce0045) & param_2;
  cVar6 = (char)param_1;
  *unaff_EBX = *unaff_EBX + cVar6;
  cVar4 = (char)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX + cVar4;
  in_EAX[0x6004591] = in_EAX[0x6004591] + (char)in_EAX;
  uVar5 = (undefined2)((uint)unaff_EBX >> 0x10);
  cVar7 = (char)((uint)param_1 >> 8);
  cVar4 = cVar4 + cVar7;
  iVar2 = CONCAT22(uVar5,CONCAT11(cVar4,(char)unaff_EBX));
  *(char *)(unaff_EBP + -0x68ffba69) = *(char *)(unaff_EBP + -0x68ffba69) + cVar4;
  *param_1 = *param_1 + cVar4;
  pcVar1 = (char *)(iVar2 + -0x1affba6f);
  cVar4 = (char)((uint)in_EAX >> 8);
  *pcVar1 = *pcVar1 + cVar4;
  *in_EAX = *in_EAX + cVar6;
  *unaff_ESI = *unaff_ESI + cVar7;
  *(char *)(unaff_EDI + -0x6e) = *(char *)(unaff_EDI + -0x6e) + cVar7;
  param_1[-0x6e] = param_1[-0x6e] + cVar4;
  pcVar1 = (char *)(iVar2 + -0x6f6f6f70);
  *pcVar1 = *pcVar1 + cVar6;
  uVar3 = CONCAT22(uVar5,param_3);
  if ((-1 < param_3) && (uVar3 = (uint)param_3, (int)uVar3 < *(int *)(param_2 + 8))) {
    uVar3 = CONCAT22(param_3 >> 0xf,param_4);
    if ((-1 < param_4) && ((int)param_4 < *(int *)(param_2 + 0xc))) {
      return CONCAT31((int3)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffff00;
}

// --------------------------------------------------

// Function: `vcall'{456,{flat}}'_}'
// Address: 00460fc0
// XREFS: findPath
/* [thunk]: __thiscall `vcall'{456,{flat}}' }' */

void __thiscall _vcall__456__flat______(void *this)
{
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Could not recover jumptable at 0x00460fc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*this + 0x1c8))();
  return;
}

// --------------------------------------------------

// Function: FUN_004614d9
// Address: 004614d9
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void FUN_004614d9(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: convert_us
// Address: 00462d70
// XREFS: RGE_Effects, RGE_Sprite, load_border_types, load_terrain_types
/* void __cdecl convert_us(char *) */

void __cdecl convert_us(char *param_1)
{
  char *pcVar1;
  char cVar2;
  
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    if (cVar2 == '_') {
      *param_1 = ' ';
    }
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  return;
}

// --------------------------------------------------

// Function: unconvert_us
// Address: 00462d90
// XREFS: None
/* void __cdecl unconvert_us(char *) */

void __cdecl unconvert_us(char *param_1)
{
  char *pcVar1;
  char cVar2;
  
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    if (cVar2 == ' ') {
      *param_1 = '_';
    }
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  return;
}

// --------------------------------------------------

// Function: addstring
// Address: 00462db0
// XREFS: Check_shape, RGE_Color_Table, add_description, do_draw, get_frame, get_size, load_border_types, load_campaign, load_terrain_types, make_campaign, shape_hit_test
/* void __cdecl addstring(char * *,char *,char *) */

void __cdecl addstring(char **param_1,char *param_2,char *param_3)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar3 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  uVar4 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar4 - 1;
  pcVar2 = (char *)calloc(~uVar4 + uVar3,1);
  pcVar6 = pcVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *param_2;
    param_2 = param_2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  pcVar6 = pcVar2 + uVar3;
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_3;
    param_3 = param_3 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar6 = *param_3;
    param_3 = param_3 + 1;
    pcVar6 = pcVar6 + 1;
  }
  if (*param_1 != (char *)0x0) {
    free(*param_1);
  }
  *param_1 = pcVar2;
  return;
}

// --------------------------------------------------

// Function: getstring
// Address: 00462e30
// XREFS: RGE_Player, TRIBE_Tech, add_description, condition_description, copy_obj, get_campaign_list, get_people_list, get_scenario_list, make_campaign, scenario_info, setup
/* void __cdecl getstring(char * *,char *) */

void __cdecl getstring(char **param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  if (*param_1 != (char *)0x0) {
    free(*param_1);
  }
  pcVar2 = (char *)calloc(uVar3,1);
  *param_1 = pcVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *param_2;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004630dd
// Address: 004630dd
// XREFS: None
/* WARNING: Instruction at (ram,0x0046311e) overlaps instruction at (ram,0x0046311b)
    */

int __thiscall
FUN_004630dd(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            char param_6,undefined4 param_7,undefined4 param_8)
{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  uint in_EAX;
  uint uVar4;
  undefined3 uVar6;
  int iVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  byte *unaff_ESI;
  int unaff_EDI;
  undefined2 in_SS;
  
  uVar4 = in_EAX ^ 0x3f004630;
  bVar3 = (byte)uVar4;
  *unaff_ESI = *unaff_ESI ^ bVar3;
  pbVar1 = (byte *)segment(in_SS,(short)unaff_EBP);
  *pbVar1 = *pbVar1 ^ bVar3;
  uVar6 = (undefined3)(uVar4 >> 8);
  if (*pbVar1 == 0) {
    *(char *)(unaff_EDI + -0x6fffb9d0) = *(char *)(unaff_EDI + -0x6fffb9d0) + (char)(uVar4 >> 8);
    iVar5 = CONCAT31(uVar6,param_6);
    unaff_ESI = *(byte **)(param_1 + 4);
    if (param_6 == '\0') {
      for (; unaff_ESI != (byte *)0x0; unaff_ESI = *(byte **)(unaff_ESI + 4)) {
        if (*(int **)unaff_ESI != (int *)0x0) {
          iVar5 = (**(code **)(**(int **)unaff_ESI + 0x10))(param_2,param_3,param_4,param_5);
        }
      }
    }
    else {
      unaff_EBX = param_3;
      unaff_EBP = param_4;
      unaff_EDI = param_2;
      if (unaff_ESI != (byte *)0x0) goto LAB_0046311f;
    }
    return iVar5;
  }
  iVar5 = CONCAT31(uVar6,bVar3 + 0x75);
LAB_0046311f:
  do {
    piVar2 = *(int **)unaff_ESI;
    if ((piVar2 != (int *)0x0) && (iVar5 = piVar2[2], *(char *)(iVar5 + 0x65) != '\0')) {
      iVar5 = (**(code **)(*piVar2 + 0x10))(unaff_EDI,unaff_EBX,unaff_EBP,param_8);
    }
    unaff_ESI = *(byte **)(unaff_ESI + 4);
  } while (unaff_ESI != (byte *)0x0);
  return iVar5;
}

// --------------------------------------------------

// Function: $E4
// Address: 00463ba0
// XREFS: None
void _E4(void)
{
  _E1();
  _E3();
  return;
}

// --------------------------------------------------

// Function: $E1
// Address: 00463bb0
// XREFS: $E4
void _E1(void)
{
  TPanelSystem::TPanelSystem(&panel_system);
  return;
}

// --------------------------------------------------

// Function: $E3
// Address: 00463bc0
// XREFS: $E4
void _E3(void)
{
  atexit(_E2);
  return;
}

// --------------------------------------------------

// Function: $E2
// Address: 00463bd0
// XREFS: $E3
void _E2(void)
{
  TPanelSystem::~TPanelSystem(&panel_system);
  return;
}

// --------------------------------------------------

// Function: FUN_00465746
// Address: 00465746
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Panel_cpp: "C:\msdev\work\age1_x1\Panel.cpp"
/* WARNING: Instruction at (ram,0x0046579e) overlaps instruction at (ram,0x0046579d)
    */
/* WARNING: Control flow encountered bad instruction data */

int __fastcall FUN_00465746(undefined4 param_1,int param_2)
{
  char *pcVar1;
  undefined4 *puVar2;
  char *in_EAX;
  ulong uVar3;
  int iVar4;
  char cVar5;
  char cVar7;
  char *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int iVar8;
  int iVar9;
  int iVar10;
  int unaff_EDI;
  bool in_ZF;
  char in_SF;
  char in_OF;
  int *piVar6;
  
  if (in_ZF || in_OF != in_SF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar5 = (char)param_1;
  cVar7 = (char)((uint)param_1 >> 8) + cVar5;
  piVar6 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar7,cVar5));
  *(char *)(unaff_EDI + -0x5fffb9ac) = *(char *)(unaff_EDI + -0x5fffb9ac) + cVar5;
  in_EAX[0x71004654] = in_EAX[0x71004654] + (char)((uint)in_EAX >> 8);
  pcVar1 = (char *)(unaff_EBP + 0x55b90046 + param_2 * 2);
  *pcVar1 = *pcVar1 + (char)param_2;
  iVar8 = unaff_ESI + 6;
  *unaff_EBX = *unaff_EBX + (char)in_EAX;
  iVar9 = unaff_ESI + 7;
  *in_EAX = *in_EAX + cVar7;
  *(char *)(unaff_EBP + 0x56) = *(char *)(unaff_EBP + 0x56) + cVar5;
  iVar10 = unaff_ESI + 9;
  in_EAX[-0x6f6f6f70] = in_EAX[-0x6f6f6f70] + (char)param_2;
  if (((piVar6[0x1b] != 0) && ((char)piVar6[0x3b] == '\x01')) &&
     (uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Panel_cpp,0x5fd),
     piVar6[0x2f] <= (int)(uVar3 - piVar6[0x35]))) {
    *(undefined1 *)(piVar6 + 0x3b) = 2;
    if (*(char *)((int)piVar6 + 0xed) == '\x01') {
      (**(code **)(*piVar6 + 0x88))();
    }
    else {
      (**(code **)(*piVar6 + 0x9c))(piVar6[0x31],piVar6[0x32],piVar6[0x33],piVar6[0x34]);
    }
  }
  puVar2 = (undefined4 *)piVar6[0x17];
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    iVar4 = (**(code **)(*(int *)*puVar2 + 0x4c))(iVar10,iVar9,iVar8);
    if (iVar4 != 0) break;
    puVar2 = (undefined4 *)puVar2[1];
  }
  return iVar4;
}

// --------------------------------------------------

// Function: operator<<
// Address: 0046a810
// XREFS: None
// [HELPER] s__: "}"
// [HELPER] s___: "]\n"
/* class ostream & __cdecl operator<<(class ostream &,class Path const &) */

ostream * __cdecl operator<<(ostream *param_1,Path *param_2)
{
  float fVar1;
  ostream *poVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar3 = 0;
  if (0 < param_2->currentSizeValue) {
    iVar4 = 0;
    do {
      poVar2 = ostream::operator<<(param_1,s__);
      fVar1 = *(float *)((int)&param_2->pathValue->x + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      poVar2 = ostream::operator<<(poVar2,s___);
      fVar1 = *(float *)((int)&param_2->pathValue->y + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      poVar2 = ostream::operator<<(poVar2,s___);
      pcVar5 = s___;
      fVar1 = *(float *)((int)&param_2->pathValue->z + iVar4);
      poVar2->x_floatused = 1;
      poVar2 = ostream::operator<<(poVar2,(double)fVar1);
      ostream::operator<<(poVar2,pcVar5);
      pcVar5 = s___;
      poVar2 = ostream::operator<<(param_1,(uint)(&param_2->pathValue->facetToNextWaypoint)[iVar4]);
      ostream::operator<<(poVar2,pcVar5);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar3 < param_2->currentSizeValue);
  }
  return param_1;
}

// --------------------------------------------------

// Function: $E12
// Address: 0046b050
// XREFS: None
void _E12(void)
{
  _E9();
  _E11();
  return;
}

// --------------------------------------------------

// Function: $E9
// Address: 0046b060
// XREFS: $E12
void _E9(void)
{
  PathingSystem::PathingSystem(&pathSystem,0xff,0xff,0,(RGE_Map *)0x0,(RGE_Game_World *)0x0);
  return;
}

// --------------------------------------------------

// Function: $E11
// Address: 0046b080
// XREFS: $E12
void _E11(void)
{
  atexit(_E10);
  return;
}

// --------------------------------------------------

// Function: $E10
// Address: 0046b090
// XREFS: $E11
void _E10(void)
{
  PathingSystem::~PathingSystem(&pathSystem);
  return;
}

// --------------------------------------------------

// Function: $E17
// Address: 0046b0a0
// XREFS: None
void _E17(void)
{
  _E14();
  _E16();
  return;
}

// --------------------------------------------------


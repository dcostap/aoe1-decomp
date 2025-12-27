// GLOBAL FUNCTIONS PART 4000
// Function: FUN_004cf0f7
// Address: 004cf0f7
TRIBE_Action_Hunt * __thiscall FUN_004cf0f7(TRIBE_Action_Hunt *param_1,byte param_2)
{
  TRIBE_Action_Hunt::~TRIBE_Action_Hunt(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cf125
// Address: 004cf125
RGE_Action * __thiscall
FUN_004cf125(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fec8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Hunt::_vftable_;
  param_1->action_type = 0x6e;
  RGE_Action::set_target_obj(param_1,param_4);
  if ((param_4 != (RGE_Static_Object *)0x0) && (param_4->object_state < 7)) {
    param_1->target_x = param_4->world_x;
    param_1->target_y = param_4->world_y;
    param_1->target_z = param_4->world_z;
    param_1[1]._padding_ = (int)param_4->master_obj->id;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cf1bc
// Address: 004cf1bc
RGE_Action * __thiscall
FUN_004cf1bc(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&TRIBE_Action_Hunt::_vftable_;
  param_1->action_type = 0x6e;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  param_1[1]._padding_ = -1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cf204
// Address: 004cf204
void __thiscall FUN_004cf204(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  return;
}

// --------------------------------------------------

// Function: FUN_004cf232
// Address: 004cf232
void __thiscall FUN_004cf232(int *param_1,char param_2)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = *(short *)(param_1[0xc] + 0x14);
  if ((short)((int *)param_1[2])[0x13] != sVar1) {
    (**(code **)(*(int *)param_1[2] + 0x80))(CONCAT22((short)((uint)param_1[0xc] >> 0x10),sVar1),0);
  }
  if (param_2 != '\0') {
    iVar2 = param_1[4];
    if (iVar2 == 0) {
      (**(code **)(*param_1 + 0x5c))(3);
      return;
    }
    iVar3 = param_1[2];
    if (*(int *)(iVar2 + 0xc) == *(int *)(iVar3 + 0xc)) {
      sVar1 = *(short *)(*(int *)(iVar2 + 8) + 0x10);
      if (((sVar1 == *(short *)(*(int *)(iVar3 + 8) + 0xe8)) ||
          (sVar1 == *(short *)(*(int *)(iVar3 + 8) + 0xea))) &&
         ((float)DAT_00575150._0_4_ < *(float *)(iVar3 + 0x44))) {
        iVar3 = *param_1;
        (**(code **)(iVar3 + 0x58))(iVar2);
        (**(code **)(iVar3 + 0x54))(0);
        param_1[8] = -0x40800000;
        param_1[9] = -0x40800000;
        param_1[10] = -0x40800000;
        (**(code **)(iVar3 + 0x5c))(8);
        return;
      }
    }
    (**(code **)(*param_1 + 0x5c))(4);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: FUN_004cf2fc
// Address: 004cf2fc
void __thiscall FUN_004cf2fc(TRIBE_Action_Hunt *param_1,byte param_2)
{
  RGE_Sound *this;
  RGE_Action_Move_To *pRVar1;
  RGE_Sprite *pRVar2;
  RGE_Action *pRVar3;
  RGE_Action_Attack *this_00;
  RGE_Sprite *pRVar4;
  RGE_Static_Object *pRVar5;
  int iVar6;
  undefined4 unaff_EBX;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  RGE_Sprite *pRVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  short sVar11;
  short sVar12;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ff0c;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1->_padding_);
  *(byte *)&param_1->_padding_ = param_2;
  switch(param_2 - 1) {
  case 0:
  case 0xc:
  case 0xd:
    param_1->_padding_ = 0;
    iVar6 = *(int *)param_1->_padding_;
    pRVar2 = TRIBE_Action_Hunt::get_wait_sprite(param_1);
    goto LAB_004cf805;
  case 1:
    iVar6 = *(int *)param_1->_padding_;
    pRVar2 = TRIBE_Action_Hunt::get_wait_sprite(param_1);
    (**(code **)(iVar6 + 0x38))(pRVar2);
    iVar6 = param_1->_padding_;
    (**(code **)(iVar6 + 0x54))(0);
    (**(code **)(iVar6 + 0x58))(0);
    param_1->_padding_ = 0;
    param_1->_padding_ = -0x40800000;
    param_1->_padding_ = -0x40800000;
    param_1->_padding_ = -0x40800000;
    *unaff_FS_OFFSET = unaff_EDI;
    return;
  case 2:
    iVar6 = ((int *)param_1->_padding_)[1];
    uVar9 = 0x202;
    (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar6,iVar6,0x202,0x265,param_1->targetType,0)
    ;
    iVar6 = *(int *)param_1->_padding_;
    pRVar2 = TRIBE_Action_Hunt::get_wait_sprite(param_1);
    (**(code **)(iVar6 + 0x38))(pRVar2);
    param_1->_padding_ = -0x3ee00000;
    *unaff_FS_OFFSET = uVar9;
    return;
  case 3:
    iVar6 = param_1->_padding_;
    param_1->_padding_ = 0;
    if (iVar6 == 0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    param_1->_padding_ = *(int *)(iVar6 + 0x38);
    param_1->_padding_ = *(int *)(iVar6 + 0x3c);
    param_1->_padding_ = *(int *)(iVar6 + 0x40);
    if (*(byte *)(iVar6 + 0x48) < 3) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xc);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 1;
    if (pRVar1 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar2 = TRIBE_Action_Hunt::get_move_sprite(param_1);
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar1,(RGE_Action_Object *)param_1->_padding_,
                          (RGE_Static_Object *)param_1->_padding_,
                          *(float *)(param_1->_padding_ + 0x24),pRVar2);
    }
    uStack_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    break;
  default:
    goto switchD_004cf338_caseD_4;
  case 5:
    param_1->_padding_ = 0;
    iVar6 = *(int *)param_1->_padding_;
    pRVar2 = TRIBE_Action_Hunt::get_move_sprite(param_1);
LAB_004cf805:
    (**(code **)(iVar6 + 0x38))(pRVar2);
switchD_004cf338_caseD_4:
    *unaff_FS_OFFSET = uStack_c;
    return;
  case 6:
    param_1->_padding_ = 0;
    sVar12 = *(short *)(param_1->_padding_ + 0x14);
    if ((short)((int *)param_1->_padding_)[0x13] != sVar12) {
      (**(code **)(*(int *)param_1->_padding_ + 0x80))
                (CONCAT22((short)(param_2 - 1 >> 0x10),sVar12),0);
    }
    (**(code **)(*(int *)param_1->_padding_ + 0x38))(*(undefined4 *)(param_1->_padding_ + 0x3c));
    this = *(RGE_Sound **)(param_1->_padding_ + 0x44);
    if (this != (RGE_Sound *)0x0) {
      RGE_Sound::play(this,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    goto switchD_004cf338_caseD_4;
  case 7:
    pRVar5 = (RGE_Static_Object *)param_1->_padding_;
    if (pRVar5->attribute_amount_held <= (float)DAT_00575150._0_4_) {
      if ((param_1->_padding_ != 0) &&
         (*(float *)(param_1->_padding_ + 0x44) <= (float)DAT_00575150._0_4_)) {
        (**(code **)(param_1->_padding_ + 0x54))(0);
      }
      (**(code **)(param_1->_padding_ + 0x5c))(3);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    if (param_1->_padding_ == 0) {
      sVar12 = *(short *)&pRVar5->master_obj[1].radius_x;
      if (sVar12 == -1) {
        (**(code **)(param_1->_padding_ + 0x58))(0);
      }
      else {
        iVar6 = param_1->_padding_;
        pRVar5 = RGE_Object_List::find_by_master_ids
                           (pRVar5->owner->objects,(int)sVar12,
                            (int)*(short *)((int)&pRVar5->master_obj[1].radius_x + 2),
                            pRVar5->world_x,pRVar5->world_y,'\x01','\x02',pRVar5);
        (**(code **)(iVar6 + 0x58))(pRVar5);
      }
      if (param_1->_padding_ == 0) {
        iVar6 = ((int *)param_1->_padding_)[1];
        uVar9 = 0x203;
        (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar6,iVar6,0x203,0x265,0,0);
        iVar6 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1->_padding_ + 0xc));
        if (iVar6 == 0) {
          (**(code **)(param_1->_padding_ + 0x5c))(2);
          *unaff_FS_OFFSET = uVar9;
          return;
        }
        (**(code **)(param_1->_padding_ + 0x5c))(1);
        *unaff_FS_OFFSET = uVar9;
        return;
      }
    }
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 3;
    if (pRVar1 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar2 = TRIBE_Action_Hunt::get_move_sprite(param_1);
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar1,(RGE_Action_Object *)param_1->_padding_,
                          (RGE_Static_Object *)param_1->_padding_,
                          *(float *)(param_1->_padding_ + 0x24),pRVar2);
    }
    uStack_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    break;
  case 10:
  case 0xe:
    param_1->_padding_ = 0;
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (pRVar1 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar2 = TRIBE_Action_Hunt::get_move_sprite(param_1);
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar1,(RGE_Action_Object *)param_1->_padding_,(float)param_1->_padding_,
                          (float)param_1->_padding_,(float)param_1->_padding_,
                          *(float *)(param_1->_padding_ + 0x24),pRVar2);
    }
    uStack_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    RGE_Action::setSubAction(pRVar3,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)param_1->_padding_,pRVar3);
    *unaff_FS_OFFSET = uStack_c;
    return;
  case 0xb:
    param_1->_padding_ = 0;
    this_00 = (RGE_Action_Attack *)operator_new(0x5c);
    uStack_4 = 2;
    if (this_00 == (RGE_Action_Attack *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      iVar6 = *(int *)(param_1->_padding_ + 8);
      sVar12 = *(short *)(iVar6 + 0x12a);
      sVar11 = *(short *)(iVar6 + 0x124);
      fVar10 = *(float *)(iVar6 + 0x138);
      fVar8 = *(float *)(param_1->_padding_ + 0x24);
      pRVar2 = *(RGE_Sprite **)(param_1->_padding_ + 0x38);
      pRVar7 = (RGE_Sprite *)0x0;
      pRVar4 = TRIBE_Action_Hunt::get_move_sprite(param_1);
      pRVar3 = (RGE_Action *)
               RGE_Action_Attack::RGE_Action_Attack
                         (this_00,(RGE_Action_Object *)param_1->_padding_,
                          (RGE_Static_Object *)param_1->_padding_,pRVar4,pRVar2,pRVar7,fVar8,fVar10,
                          sVar11,sVar12);
    }
    uStack_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
  }
  uStack_4 = 0xffffffff;
  RGE_Action_List::add_action((RGE_Action_List *)param_1->_padding_,pRVar3);
  RGE_Action::setSubAction(pRVar3,'\x01');
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004cfe93
// Address: 004cfe93
int __fastcall FUN_004cfe93(char *param_1,int param_2)
{
  char *pcVar1;
  short sVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  pcVar1 = (char *)(in_EAX * 2 + -0xc);
  *pcVar1 = *pcVar1 + -1;
  cVar6 = (char)((uint)param_1 >> 8);
  cVar7 = (char)unaff_EBX;
  cVar8 = (char)((uint)unaff_EBX >> 8) + cVar6;
  iVar3 = CONCAT22((short)((uint)unaff_EBX >> 0x10),CONCAT11(cVar8,cVar7));
  cVar5 = (char)param_1;
  param_1[-0x53ffb302] = param_1[-0x53ffb302] + cVar5;
  *param_1 = *param_1 + cVar7;
  *(char *)(in_EAX + -4) = *(char *)(in_EAX + -4) + cVar8;
  param_1[-0x76ffb302] = param_1[-0x76ffb302] + cVar5;
  pcVar1 = (char *)(in_EAX * 2 + 0x5c);
  *pcVar1 = *pcVar1 + -1;
  *(char *)(unaff_EDI + -6) = *(char *)(unaff_EDI + -6) + (char)in_EAX;
  *(char *)(unaff_EDI + -2) = *(char *)(unaff_EDI + -2) + cVar7;
  param_1[0x5c004cfe] = param_1[0x5c004cfe] + cVar5;
  pcVar1 = (char *)(iVar3 + -0x54ffb307);
  *pcVar1 = *pcVar1 + cVar6;
  *(char *)(param_2 + -7) = *(char *)(param_2 + -7) + cVar8;
  pcVar1 = (char *)(iVar3 + 0x34004cf9);
  *pcVar1 = *pcVar1 + cVar6;
  pcVar1 = (char *)(param_2 + unaff_EDI * 8);
  *pcVar1 = *pcVar1 + (char)((uint)param_2 >> 8);
  cRam65004cfa = cRam65004cfa + cVar5;
  *(char *)(unaff_EBP + -6) = *(char *)(unaff_EBP + -6) + (char)((uint)in_EAX >> 8);
  *(char *)(unaff_EDI + -6) = *(char *)(unaff_EDI + -6) + cVar8;
  *(char *)(unaff_EDI + -6) = *(char *)(unaff_EDI + -6) + cVar8;
  param_1[0x65004cfa] = param_1[0x65004cfa] + cVar7;
  *(char *)(unaff_EDI + -6) = *(char *)(unaff_EDI + -6) + cVar8;
  *param_1 = *param_1 + cVar5;
  *param_1 = *param_1 + cVar5;
  pcVar1 = (char *)(unaff_ESI + -0x75);
  cVar7 = *pcVar1;
  *pcVar1 = *pcVar1 + (char)param_2;
  if (SCARRY1(cVar7,(char)param_2)) {
    if (((*(short *)(unaff_ESI + 0x14) != -1) &&
        (*(short *)(unaff_ESI + 0x14) ==
         *(short *)(*(int *)(CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar6 << 3,cVar5)) + 8
                            ) + 0x4c))) &&
       ((iVar3 = __ftol(), 0 < iVar3 && (*(int *)(unaff_ESI + 0x40) != 0)))) {
      return *(int *)(unaff_ESI + 0x40);
    }
    return *(int *)(unaff_ESI + 0x34);
  }
  iVar3 = *(int *)(unaff_ESI + 0x30);
  sVar2 = *(short *)(iVar3 + 0x14);
  if ((((sVar2 != -1) && (sVar2 == *(short *)(*(int *)(unaff_ESI + 8) + 0x4c))) &&
      (iVar4 = __ftol(), 0 < iVar4)) && (iVar3 = *(int *)(iVar3 + 0x40), iVar3 != 0)) {
    return iVar3;
  }
  return *(int *)(*(int *)(*(int *)(unaff_ESI + 8) + 8) + 0x18);
}

// --------------------------------------------------

// Function: FUN_004cff4f
// Address: 004cff4f
int __fastcall FUN_004cff4f(int param_1)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x30);
  sVar1 = *(short *)(iVar2 + 0x14);
  if ((((sVar1 != -1) && (sVar1 == *(short *)(*(int *)(param_1 + 8) + 0x4c))) &&
      (iVar3 = __ftol(), 0 < iVar3)) && (iVar2 = *(int *)(iVar2 + 0x40), iVar2 != 0)) {
    return iVar2;
  }
  return *(int *)(*(int *)(*(int *)(param_1 + 8) + 8) + 0x18);
}

// --------------------------------------------------

// Function: FUN_004cff89
// Address: 004cff89
undefined4 __fastcall FUN_004cff89(int *param_1)
{
  int iVar1;
  
  iVar1 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[2] + 0xc));
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x5c))(2);
    return 1;
  }
  (**(code **)(*param_1 + 0x5c))(1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cffc2
// Address: 004cffc2
undefined4 __thiscall FUN_004cffc2(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  short sVar1;
  int iVar2;
  
  if ((param_2 != 0) && (iVar2 = param_1[2], *(int *)(param_2 + 0xc) == *(int *)(iVar2 + 0xc))) {
    sVar1 = *(short *)(*(int *)(param_2 + 8) + 0x10);
    if (((sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xe8)) ||
        (sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xea))) &&
       ((float)DAT_00575150._0_4_ < *(float *)(iVar2 + 0x44))) {
      if ((param_2 == param_1[5]) && ((char)param_1[3] == '\b')) {
        return 1;
      }
      iVar2 = *param_1;
      (**(code **)(iVar2 + 0x54))(0);
      param_1[8] = -0x40800000;
      param_1[9] = -0x40800000;
      param_1[10] = -0x40800000;
      (**(code **)(iVar2 + 0x58))(param_2);
      (**(code **)(iVar2 + 0x5c))(8);
      return 1;
    }
  }
  iVar2 = *param_1;
  param_1[10] = param_5;
  param_1[8] = param_3;
  param_1[9] = param_4;
  (**(code **)(iVar2 + 0x54))(0);
  (**(code **)(iVar2 + 0x5c))(0xf);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d007e
// Address: 004d007e
undefined4 __thiscall FUN_004d007e(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  short sVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *param_1;
    param_1[10] = param_5;
    param_1[8] = param_3;
    param_1[9] = param_4;
    (**(code **)(iVar2 + 0x54))(0);
    (**(code **)(iVar2 + 0x5c))(0xf);
    return 1;
  }
  iVar2 = param_1[2];
  if (*(int *)(param_2 + 0xc) == *(int *)(iVar2 + 0xc)) {
    sVar1 = *(short *)(*(int *)(param_2 + 8) + 0x10);
    if (((sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xe8)) ||
        (sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xea))) &&
       ((float)DAT_00575150._0_4_ < *(float *)(iVar2 + 0x44))) {
      iVar2 = *param_1;
      (**(code **)(iVar2 + 0x54))(0);
      param_1[0xb] = 0;
      param_1[8] = -0x40800000;
      param_1[9] = -0x40800000;
      param_1[10] = -0x40800000;
      (**(code **)(iVar2 + 0x58))(param_2);
      (**(code **)(iVar2 + 0x5c))(8);
      return 1;
    }
  }
  iVar2 = *param_1;
  (**(code **)(iVar2 + 0x54))(param_2);
  (**(code **)(iVar2 + 0x58))(0);
  (**(code **)(iVar2 + 0x5c))(4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d014f
// Address: 004d014f
RGE_Action_List * __thiscall FUN_004d014f(RGE_Action_List *param_1,RGE_Action_Object *param_2)
{
  RGE_Action_List::RGE_Action_List(param_1,param_2);
  param_1->_padding_ = (int)&TRIBE_Action_List::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d0169
// Address: 004d0169
RGE_Action * __thiscall FUN_004d0169(RGE_Action_List *param_1,int param_2,short param_3)
{
  TRIBE_Action_Build *this;
  TRIBE_Action_Make_Obj *this_00;
  TRIBE_Action_Make_Tech *this_01;
  TRIBE_Action_Convert *this_02;
  TRIBE_Action_Heal *this_03;
  TRIBE_Action_Artifact *this_04;
  TRIBE_Action_Wonder *this_05;
  TRIBE_Action_Discovery_Artifact *this_06;
  TRIBE_Action_Hunt *this_07;
  TRIBE_Action_Repair *this_08;
  TRIBE_Action_Trade *this_09;
  RGE_Action_Transport *this_10;
  RGE_Action_Enter *this_11;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ffaf;
  *unaff_FS_OFFSET = &uStack_c;
  switch(param_3) {
  case 3:
    this_11 = (RGE_Action_Enter *)operator_new(0x40);
    uStack_4 = 0xc;
    if (this_11 != (RGE_Action_Enter *)0x0) {
      pRVar1 = (RGE_Action *)RGE_Action_Enter::RGE_Action_Enter(this_11,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  default:
    pRVar1 = RGE_Action_List::create_action(param_1,param_2,param_3);
    *unaff_FS_OFFSET = uStack_c;
    return pRVar1;
  case 0xc:
    this_10 = (RGE_Action_Transport *)operator_new(0x40);
    uStack_4 = 0xb;
    if (this_10 != (RGE_Action_Transport *)0x0) {
      pRVar1 = (RGE_Action *)
               RGE_Action_Transport::RGE_Action_Transport(this_10,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x65:
    this = (TRIBE_Action_Build *)operator_new(0x40);
    uStack_4 = 0;
    if (this != (TRIBE_Action_Build *)0x0) {
      pRVar1 = (RGE_Action *)TRIBE_Action_Build::TRIBE_Action_Build(this,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x66:
    this_00 = (TRIBE_Action_Make_Obj *)operator_new(0x50);
    uStack_4 = 1;
    if (this_00 != (TRIBE_Action_Make_Obj *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(this_00,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x67:
    this_01 = (TRIBE_Action_Make_Tech *)operator_new(0x48);
    uStack_4 = 2;
    if (this_01 != (TRIBE_Action_Make_Tech *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(this_01,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x68:
    this_02 = (TRIBE_Action_Convert *)operator_new(0x48);
    uStack_4 = 3;
    if (this_02 != (TRIBE_Action_Convert *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Convert::TRIBE_Action_Convert(this_02,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x69:
    this_03 = (TRIBE_Action_Heal *)operator_new(0x40);
    uStack_4 = 4;
    if (this_03 != (TRIBE_Action_Heal *)0x0) {
      pRVar1 = (RGE_Action *)TRIBE_Action_Heal::TRIBE_Action_Heal(this_03,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x6a:
    this_08 = (TRIBE_Action_Repair *)operator_new(0x44);
    uStack_4 = 9;
    if (this_08 != (TRIBE_Action_Repair *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Repair::TRIBE_Action_Repair(this_08,param_2,param_1->obj,1);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x6b:
    this_04 = (TRIBE_Action_Artifact *)operator_new(0x40);
    uStack_4 = 5;
    if (this_04 != (TRIBE_Action_Artifact *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Artifact::TRIBE_Action_Artifact(this_04,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x6c:
    this_06 = (TRIBE_Action_Discovery_Artifact *)operator_new(0x44);
    uStack_4 = 7;
    if (this_06 != (TRIBE_Action_Discovery_Artifact *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact
                         (this_06,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x6e:
    this_07 = (TRIBE_Action_Hunt *)operator_new(0x44);
    uStack_4 = 8;
    if (this_07 != (TRIBE_Action_Hunt *)0x0) {
      pRVar1 = (RGE_Action *)TRIBE_Action_Hunt::TRIBE_Action_Hunt(this_07,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x6f:
    this_09 = (TRIBE_Action_Trade *)operator_new(0x48);
    uStack_4 = 10;
    if (this_09 != (TRIBE_Action_Trade *)0x0) {
      pRVar1 = (RGE_Action *)TRIBE_Action_Trade::TRIBE_Action_Trade(this_09,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
    break;
  case 0x78:
    this_05 = (TRIBE_Action_Wonder *)operator_new(0x40);
    uStack_4 = 6;
    if (this_05 != (TRIBE_Action_Wonder *)0x0) {
      pRVar1 = (RGE_Action *)TRIBE_Action_Wonder::TRIBE_Action_Wonder(this_05,param_2,param_1->obj);
      *unaff_FS_OFFSET = uStack_c;
      return pRVar1;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return (RGE_Action *)0x0;
}

// --------------------------------------------------

// Function: FUN_004d0517
// Address: 004d0517
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_004d0517(int param_1,int param_2)
{
  int in_EAX;
  char cVar1;
  int unaff_EBP;
  
  cVar1 = (char)((uint)param_1 >> 8);
  (&stack0x0000004d)[in_EAX] = (&stack0x0000004d)[in_EAX] + cVar1;
  *(char *)(param_2 + -0x15ffb2ff) = *(char *)(param_2 + -0x15ffb2ff) + cVar1;
  *(int *)(unaff_EBP + -1) = *(int *)(unaff_EBP + -1) + param_1;
  *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + cVar1;
  *(char *)(param_2 + -0x15ffb2fe) = *(char *)(param_2 + -0x15ffb2fe) + cVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_004d0eae
// Address: 004d0eae
RGE_Action * __thiscall
FUN_004d0eae(RGE_Action *param_1,RGE_Action_Object *param_2,undefined2 param_3,
            RGE_Action_Object *param_4,uchar param_5)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1[1].state = param_5;
  param_1[1].obj = param_4;
  param_1->_padding_ = (int)&TRIBE_Action_Make_Obj::_vftable_;
  param_1->action_type = 0x66;
  *(undefined2 *)&param_1[1]._padding_ = param_3;
  *(undefined4 *)&param_1[1].action_type = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d0eef
// Address: 004d0eef
// [HELPER] s_WT__ld__MkObjDestructor__obj_id_: "WT=%ld, MkObjDestructor: obj_id=%d, obj->id=%d, uniqueID=%d."
void __fastcall FUN_004d0eef(RGE_Action *param_1)
{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_005600c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Action_Make_Obj::_vftable_;
  uStack_4 = 0;
  piVar1 = (int *)param_1->obj->_padding_;
  (**(code **)(*piVar1 + 0xe4))
            (piVar1,s_WT__ld__MkObjDestructor__obj_id_,*(undefined4 *)(piVar1[0xf] + 4),
             (int)(short)param_1[1]._padding_,param_1->obj->_padding_,param_1[1].obj);
  uStack_4 = 0xffffffff;
  RGE_Action::~RGE_Action(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004d0f67
// Address: 004d0f67
void __thiscall FUN_004d0f67(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,2);
  rge_write(param_2,&param_1[1].action_type,4);
  rge_write(param_2,&param_1[1].obj,4);
  rge_write(param_2,&param_1[1].state,1);
  return;
}

// --------------------------------------------------

// Function: FUN_004d0fbf
// Address: 004d0fbf
// [HELPER] s_Canceling_Train__1a___obj_id__d_: "Canceling Train #1a:  obj_id=%d, obj->id=%d, uniqueID=%d."
// [HELPER] s_Canceling_Train__1b___obj_id__d_: "Canceling Train #1b:  obj_id=%d, obj->id=%d, uniqueID=%d."
// [HELPER] s_Canceling_Train__1c___obj_id__d_: "Canceling Train #1c:  obj_id=%d, obj->id=%d, uniqueID=%d."
void __thiscall FUN_004d0fbf(int *param_1,char param_2)
{
  short sVar1;
  int *piVar2;
  TRIBE_Player *this;
  int iVar3;
  uchar uVar4;
  
  if (param_2 == '\0') {
    return;
  }
  sVar1 = (short)param_1[0x10];
  if (sVar1 < 0) {
    piVar2 = *(int **)(param_1[2] + 0xc);
    (**(code **)(*piVar2 + 0xe4))
              (piVar2,s_Canceling_Train__1a___obj_id__d_,(int)sVar1,*(undefined4 *)(param_1[2] + 4),
               param_1[0x12]);
  }
  else {
    this = *(TRIBE_Player **)(param_1[2] + 0xc);
    if (*(int *)(this->_padding_ + sVar1 * 4) != 0) {
      if (((char)param_1[0x13] == '\0') &&
         (uVar4 = TRIBE_Player::pay_obj_cost(this,sVar1,1.0,0), uVar4 == '\0')) {
        piVar2 = *(int **)(param_1[2] + 0xc);
        (**(code **)(*piVar2 + 0xe4))
                  (piVar2,s_Canceling_Train__1c___obj_id__d_,(int)(short)param_1[0x10],
                   *(undefined4 *)(param_1[2] + 4),param_1[0x12]);
        (**(code **)(**(int **)(param_1[2] + 0xc) + 0x10c))
                  (0,(int)(short)param_1[0x10],*(undefined4 *)(param_1[2] + 4),param_1[0x12]);
        iVar3 = ((int *)param_1[2])[1];
        (**(code **)(*(int *)param_1[2] + 0x148))(iVar3,iVar3,0x1f9,0x26b,0,0);
        (**(code **)(*param_1 + 0x5c))(1);
        return;
      }
      (**(code **)(*param_1 + 0x5c))(6);
      return;
    }
    (**(code **)(this->_padding_ + 0xe4))
              (this,s_Canceling_Train__1b___obj_id__d_,(int)sVar1,*(undefined4 *)(param_1[2] + 4),
               param_1[0x12]);
  }
  (**(code **)(**(int **)(param_1[2] + 0xc) + 0x10c))
            (0,(int)(short)param_1[0x10],*(undefined4 *)(param_1[2] + 4),param_1[0x12]);
  return;
}

// --------------------------------------------------

// Function: FUN_004d10ea
// Address: 004d10ea
// [HELPER] s_Canceling_Train__2___obj_id__d__: "Canceling Train #2:  obj_id=%d, obj->id=%d, uniqueID=%d."
undefined4 __fastcall FUN_004d10ea(TRIBE_Action_Make_Obj *param_1)
{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uchar uVar5;
  int iVar6;
  undefined4 uVar7;
  
  cVar1 = (char)param_1->_padding_;
  if (cVar1 == '\x01') {
    return 1;
  }
  if (cVar1 == '\x06') {
    if (rge_base_game->quick_build == 0) {
      param_1->work_done =
           *(float *)(*(int *)(param_1->_padding_ + 8) + 0xe4) *
           *(float *)(*(int *)(*(int *)(param_1->_padding_ + 0xc) + 0x3c) + 0x84) +
           param_1->work_done;
    }
    else {
      param_1->work_done = 1000.0;
    }
    if ((float)(int)*(short *)(*(int *)(*(int *)(*(int *)(param_1->_padding_ + 0xc) + 0x24) +
                                       param_1->obj_id * 4) + 0x15a) <= param_1->work_done) {
      (**(code **)(param_1->_padding_ + 0x5c))(1);
      uVar5 = TRIBE_Action_Make_Obj::place_obj(param_1,(RGE_Static_Object **)&stack0xfffffff8);
      if (uVar5 == '\0') {
        TRIBE_Player::reimburse_obj_cost
                  (*(TRIBE_Player **)(param_1->_padding_ + 0xc),param_1->obj_id);
        (**(code **)(rge_base_game->_padding_ + 0x40))
                  (0x68,(int)*(short *)(*(int *)(param_1->_padding_ + 0xc) + 0x4a),
                   (int)param_1->obj_id,0,0);
        piVar2 = *(int **)(param_1->_padding_ + 0xc);
        (**(code **)(*piVar2 + 0xe4))
                  (piVar2,s_Canceling_Train__2___obj_id__d__,(int)param_1->obj_id,
                   *(undefined4 *)(param_1->_padding_ + 4),param_1->unique_id);
        (**(code **)(**(int **)(param_1->_padding_ + 0xc) + 0x10c))
                  (0,(int)param_1->obj_id,*(undefined4 *)(param_1->_padding_ + 4),param_1->unique_id
                  );
        iVar3 = ((int *)param_1->_padding_)[1];
        (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar3,iVar3,0x1f9,0x26b,0,0);
        return 1;
      }
      iVar3 = param_1->_padding_;
      iVar4 = rge_base_game->_padding_;
      iVar6 = __ftol();
      uVar7 = __ftol();
      (**(code **)(iVar4 + 0x40))
                (0x66,(int)*(short *)(*(int *)(iVar3 + 0xc) + 0x4a),(int)param_1->obj_id,uVar7);
      (**(code **)(**(int **)(param_1->_padding_ + 0xc) + 0x110))
                ((int)param_1->obj_id,*(undefined4 *)(param_1->_padding_ + 4),param_1->unique_id,
                 *(undefined4 *)(iVar6 + 4));
      iVar3 = ((int *)param_1->_padding_)[1];
      (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar3,iVar3,0x1fa,0x26b,0,0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d12ae
// Address: 004d12ae
// [HELPER] s_C__msdev_work_age1_x1_tact_mob_c: "C:\msdev\work\age1_x1\tact_mob.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004d12ae(int param_1)
{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  short sVar8;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined4 *puStack_c;
  int iStack_4;
  
  sVar4 = 0;
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 8);
  piVar1 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x24) +
                    *(short *)(param_1 + 0x40) * 4);
  fStack_18 = (*(float *)(iVar5 + 0x30) + (float)piVar1[0xc]) - _DAT_00575190;
  pcVar2 = *(code **)(*piVar1 + 0x20);
  fStack_10 = fStack_18 + fStack_18;
  fStack_14 = (*(float *)(iVar5 + 0x34) + (float)piVar1[0xd]) - _DAT_00575190;
  puStack_c = (undefined4 *)(fStack_14 + fStack_14);
  do {
    sVar8 = 0;
    do {
      if (sVar8 < 0x28) {
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xc0);
        iVar5 = iVar5 * 2;
        sVar7 = ((short)(iVar5 / 0x7fff) + (short)(iVar5 >> 0x1f)) -
                (short)((longlong)iVar5 * 0x80010003 >> 0x3f);
      }
      else {
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xc2);
        sVar7 = (short)((iVar5 * 2) / 0x7fff) + 2;
      }
      switch(sVar7) {
      case 0:
        *(float *)(param_1 + 0x24) = *(float *)(*(int *)(param_1 + 8) + 0x3c) + fStack_14;
        iStack_4 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,199);
        iVar5 = *(int *)(param_1 + 8);
        goto LAB_004d1449;
      case 1:
        *(float *)(param_1 + 0x20) = *(float *)(*(int *)(param_1 + 8) + 0x38) - fStack_18;
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xcb);
        *(float *)(param_1 + 0x24) =
             ((float)iVar5 * (float)puStack_c * _DAT_00575198 - fStack_14) +
             *(float *)(*(int *)(param_1 + 8) + 0x3c);
        break;
      case 2:
        *(float *)(param_1 + 0x20) = *(float *)(*(int *)(param_1 + 8) + 0x38) + fStack_18;
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xcf);
        *(float *)(param_1 + 0x24) =
             ((float)iVar5 * (float)puStack_c * _DAT_00575198 - fStack_14) +
             *(float *)(*(int *)(param_1 + 8) + 0x3c);
        break;
      case 3:
        *(float *)(param_1 + 0x24) = *(float *)(*(int *)(param_1 + 8) + 0x3c) - fStack_14;
        iStack_4 = debug_rand(s_C__msdev_work_age1_x1_tact_mob_c,0xd3);
        iVar5 = *(int *)(param_1 + 8);
LAB_004d1449:
        *(float *)(param_1 + 0x20) =
             ((float)iStack_4 * fStack_10 * _DAT_00575198 - fStack_18) + *(float *)(iVar5 + 0x38);
      }
      cVar3 = (*pcVar2)(*(undefined4 *)(*(int *)(param_1 + 8) + 0xc),*(undefined4 *)(param_1 + 0x20)
                        ,*(undefined4 *)(param_1 + 0x24),0,1,1,1,0,0,1);
      if (cVar3 == '\0') {
        iVar5 = *(int *)(*(int *)(param_1 + 8) + 0xc);
        uVar6 = (**(code **)(**(int **)(*(int *)(iVar5 + 0x24) + *(short *)(param_1 + 0x40) * 4) +
                            0x18))(iVar5,*(undefined4 *)(param_1 + 0x20),
                                   *(undefined4 *)(param_1 + 0x24),
                                   *(undefined4 *)(*(int *)(param_1 + 8) + 0x40));
        *puStack_c = uVar6;
        return 1;
      }
      sVar8 = sVar8 + 1;
    } while (sVar8 < 0x3c);
    fStack_18 = (float)piVar1[0xc] + (float)piVar1[0xc] + fStack_18;
    fStack_14 = (float)piVar1[0xd] + (float)piVar1[0xd] + fStack_14;
    fStack_10 = (float)piVar1[0xc] * _DAT_0057519c + fStack_10;
    puStack_c = (undefined4 *)((float)piVar1[0xd] * _DAT_0057519c + (float)puStack_c);
    sVar4 = sVar4 + 1;
    if (2 < sVar4) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004d1533
// Address: 004d1533
// [HELPER] s_Stopping_Train__8___obj_id__d__o: "Stopping Train #8:  obj_id=%d, obj->id=%d, uniqueID=%d."
undefined4 __fastcall FUN_004d1533(int *param_1,int param_2)
{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  byte bVar5;
  undefined4 in_EAX;
  int unaff_EBP;
  bool in_CF;
  bool in_ZF;
  
  if (!in_CF && !in_ZF) {
    pbVar1 = (byte *)(param_2 + -0x1dffb2ed);
    bVar2 = *pbVar1;
    bVar5 = (byte)((uint)in_EAX >> 8);
    *pbVar1 = *pbVar1 + bVar5;
    param_1 = (int *)((int)param_1 + (uint)CARRY1(bVar2,bVar5) + *(int *)(unaff_EBP + -1));
  }
  piVar3 = *(int **)(param_1[2] + 0xc);
  (**(code **)(*piVar3 + 0xe4))
            (piVar3,s_Stopping_Train__8___obj_id__d__o,(int)(short)param_1[0x10],
             *(undefined4 *)(param_1[2] + 4),param_1[0x12]);
  if ((char)param_1[3] != '\x01') {
    (**(code **)(*param_1 + 0x5c))(1);
    if ((char)param_1[0x13] == '\0') {
      TRIBE_Player::reimburse_obj_cost(*(TRIBE_Player **)(param_1[2] + 0xc),(short)param_1[0x10]);
    }
  }
  (**(code **)(rge_base_game->_padding_ + 0x40))
            (0x67,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),(int)(short)param_1[0x10],0,0);
  iVar4 = ((int *)param_1[2])[1];
  (**(code **)(*(int *)param_1[2] + 0x148))(iVar4,iVar4,0x1f9,0x26b,0,0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d15e6
// Address: 004d15e6
void __thiscall
FUN_004d15e6(int param_1,undefined2 *param_2,undefined2 *param_3,int param_4,short param_5)
{
  undefined2 uVar1;
  
  *param_2 = *(undefined2 *)(param_1 + 0x40);
  if (*(char *)(param_1 + 0xc) == '\x01') {
    *param_3 = 100;
  }
  else {
    uVar1 = __ftol();
    *param_3 = uVar1;
  }
  if (param_4 != 0) {
    strncpy(param_4,*(undefined4 *)
                     (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x24) +
                              *(short *)(param_1 + 0x40) * 4) + 8),(int)param_5);
    *(undefined1 *)(param_4 + -1 + (int)param_5) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d167c
// Address: 004d167c
TRIBE_Action_Repair * __thiscall
FUN_004d167c(TRIBE_Action_Repair *param_1,int param_2,RGE_Action_Object *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005600e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action((RGE_Action *)param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Repair::_vftable_;
  *(undefined2 *)&param_1->_padding_ = 0x6a;
  if (param_4 != 0) {
    TRIBE_Action_Repair::setup(param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d16eb
// Address: 004d16eb
TRIBE_Action_Repair * __thiscall FUN_004d16eb(TRIBE_Action_Repair *param_1,byte param_2)
{
  TRIBE_Action_Repair::~TRIBE_Action_Repair(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d1715
// Address: 004d1715
TRIBE_Action_Repair * __thiscall
FUN_004d1715(TRIBE_Action_Repair *param_1,RGE_Action_Object *param_2,int param_3,
            RGE_Static_Object *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560108;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action((RGE_Action *)param_1,param_2,1);
  param_1->_padding_ = param_3;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Repair::_vftable_;
  *(undefined2 *)&param_1->_padding_ = 0x6a;
  param_1->save_target_command_flag = '\0';
  RGE_Action::set_target_obj((RGE_Action *)param_1,param_4);
  if (param_4 != (RGE_Static_Object *)0x0) {
    param_1->_padding_ = (int)param_4->world_x;
    param_1->_padding_ = (int)param_4->world_y;
    param_1->_padding_ = (int)param_4->world_z;
    TRIBE_Action_Repair::meet_target(param_1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d17a7
// Address: 004d17a7
RGE_Action * __thiscall
FUN_004d17a7(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&TRIBE_Action_Repair::_vftable_;
  param_1->action_type = 0x6a;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d17f1
// Address: 004d17f1
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004d17f1(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  int iVar1;
  
  iVar1 = RGE_Action::setup(param_1,param_2,param_3);
  if (_DAT_00575268 <= save_game_version) {
    rge_read(param_2,param_1 + 1,1);
    return iVar1;
  }
  *(undefined1 *)&param_1[1]._padding_ = 0;
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_004d184c
// Address: 004d184c
void __thiscall FUN_004d184c(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,1);
  return;
}

// --------------------------------------------------

// Function: FUN_004d1872
// Address: 004d1872
void __thiscall FUN_004d1872(int *param_1,char param_2)
{
  if ((param_2 != '\0') && (param_1[4] != 0)) {
    (**(code **)(*param_1 + 0x5c))(4);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: FUN_004d18a3
// Address: 004d18a3
void __thiscall FUN_004d18a3(int *param_1,undefined1 param_2)
{
  short sVar1;
  int *piVar2;
  RGE_Action_Move_To *pRVar3;
  RGE_Action *pRVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560136;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
  *(undefined1 *)(param_1 + 3) = param_2;
  switch(param_2) {
  case 1:
    (**(code **)(*param_1 + 0x54))(0);
    if ((char)param_1[0xf] == '\0') {
      iVar5 = ((int *)param_1[2])[1];
      iVar6 = *(int *)param_1[2];
      uVar7 = 0x1fa;
      goto LAB_004d1b4f;
    }
    break;
  case 2:
    break;
  case 3:
    iVar5 = ((int *)param_1[2])[1];
    iVar6 = *(int *)param_1[2];
    uVar7 = 0x202;
LAB_004d1b4f:
    (**(code **)(iVar6 + 0x148))(iVar5,iVar5,uVar7,0x26a,0,0);
    break;
  case 4:
    iVar5 = param_1[4];
    if (iVar5 != 0) {
      param_1[8] = *(int *)(iVar5 + 0x38);
      param_1[9] = *(int *)(iVar5 + 0x3c);
      param_1[10] = *(int *)(iVar5 + 0x40);
    }
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 1;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,(RGE_Action_Object *)param_1[2],(RGE_Static_Object *)param_1[4],
                          *(float *)(((RGE_Action_Object *)param_1[2])->_padding_ + 0x114),
                          *(RGE_Sprite **)(param_1[0xc] + 0x34));
    }
    uStack_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(*param_1 + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],pRVar4);
    RGE_Action::setSubAction(pRVar4,'\x01');
    *unaff_FS_OFFSET = uStack_c;
    return;
  default:
    goto switchD_004d18e7_caseD_5;
  case 6:
    iVar5 = param_1[4];
    param_1[8] = *(int *)(iVar5 + 0x38);
    param_1[9] = *(int *)(iVar5 + 0x3c);
    iVar6 = *(int *)param_1[2];
    param_1[10] = *(int *)(iVar5 + 0x40);
    (**(code **)(iVar6 + 0x38))(*(undefined4 *)(param_1[0xc] + 0x34));
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  case 7:
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(param_1[0xc] + 0x38));
    if (*(RGE_Sound **)(param_1[0xc] + 0x44) != (RGE_Sound *)0x0) {
      RGE_Sound::play(*(RGE_Sound **)(param_1[0xc] + 0x44),1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    goto switchD_004d18e7_caseD_5;
  case 10:
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
    piVar2 = (int *)param_1[4];
    param_1[0xb] = 0x3f800000;
    if (((piVar2 != (int *)0x0) &&
        ((((sVar1 = *(short *)(piVar2[2] + 0x14), sVar1 == 2 || (sVar1 == 0x14)) || (sVar1 == 0x15))
         || (sVar1 == 0x16)))) && ((char)piVar2[0x62] == (char)param_1[0x10])) {
      iVar5 = param_1[2];
      uVar7 = *(undefined4 *)(iVar5 + 0x40);
      (**(code **)(*piVar2 + 0x154))
                (*(undefined4 *)(iVar5 + 0x38),*(undefined4 *)(iVar5 + 0x3c),uVar7,0,1);
      *unaff_FS_OFFSET = uVar7;
      return;
    }
    goto switchD_004d18e7_caseD_5;
  case 0xb:
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9]
                          ,(float)param_1[10],0.0,*(RGE_Sprite **)(param_1[0xc] + 0x34));
    }
    uStack_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(*param_1 + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action::setSubAction(pRVar4,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],pRVar4);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
switchD_004d18e7_caseD_5:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004d1b79
// Address: 004d1b79
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __fastcall FUN_004d1b79(uint param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  float fVar6;
  char cVar7;
  RGE_Static_Object *pRVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  short sVar12;
  ushort uVar13;
  undefined2 uVar15;
  byte *pbVar14;
  int *unaff_EBX;
  int unaff_EBP;
  uint *puVar16;
  int unaff_EDI;
  bool bVar17;
  float fVar18;
  undefined4 uVar19;
  
  *unaff_EBX = *unaff_EBX - (int)unaff_EBX;
  *(char *)(unaff_EDI + 0x1b) = *(char *)(unaff_EDI + 0x1b) + (char)param_2;
  puVar16 = (uint *)(unaff_EBP + -2);
  bVar17 = CARRY1((byte)((uint)param_2 >> 8),(byte)(param_1 >> 8));
  bVar1 = *(byte *)puVar16;
  bVar11 = *(byte *)puVar16 - (byte)param_1;
  *(byte *)puVar16 = bVar11 - bVar17;
  uVar4 = (uint)(bVar1 < (byte)param_1 || bVar11 < bVar17);
  uVar10 = *puVar16;
  uVar2 = *puVar16;
  *puVar16 = (uVar2 - param_1) - uVar4;
  uVar3 = (ushort)(uVar10 < param_1 || uVar2 - param_1 < uVar4);
  uVar5 = (ushort)param_1 - *(short *)puVar16;
  bVar17 = (ushort)param_1 < *(ushort *)puVar16 || uVar5 < uVar3;
  uVar15 = (undefined2)(param_1 >> 0x10);
  sVar12 = uVar5 - uVar3;
  bVar11 = (byte)sVar12;
  bVar1 = bVar11 - *(byte *)puVar16;
  uVar3 = (ushort)(bVar11 < *(byte *)puVar16 || bVar1 < bVar17);
  uVar13 = (ushort)CONCAT31((int3)(CONCAT22(uVar15,sVar12) >> 8),bVar1 - bVar17);
  uVar5 = uVar13 - *(short *)puVar16;
  sVar12 = ((uVar5 - uVar3) - *(short *)puVar16) -
           (ushort)(uVar13 < *(ushort *)puVar16 || uVar5 < uVar3);
  pbVar14 = (byte *)CONCAT22(uVar15,sVar12);
  bVar1 = *pbVar14;
  bVar11 = (byte)sVar12;
  *pbVar14 = *pbVar14 + bVar11;
  *(int *)(unaff_EBP + -3) = (*(int *)(unaff_EBP + -3) - (int)pbVar14) - (uint)CARRY1(bVar1,bVar11);
  uVar19 = 0xf6004d1a;
  if ((*(int *)(pbVar14 + 0x18) == -1) ||
     (pRVar8 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)(pbVar14 + 8) + 0xc) + 0x3c),
                          *(int *)(pbVar14 + 0x18)), pRVar8 != (RGE_Static_Object *)0x0)) {
    if ((*(int *)(pbVar14 + 0x1c) != -1) &&
       (pRVar8 = RGE_Game_World::object
                           (*(RGE_Game_World **)(*(int *)(*(int *)(pbVar14 + 8) + 0xc) + 0x3c),
                            *(int *)(pbVar14 + 0x1c)), pRVar8 == (RGE_Static_Object *)0x0)) {
      (**(code **)(*(int *)pbVar14 + 0x58))(0);
    }
    iVar9 = *(int *)(pbVar14 + 0x10);
    if ((iVar9 == 0) ||
       ((*(char *)(iVar9 + 0x48) == '\x02' &&
        ((iVar9 == 0 ||
         (iVar9 = (**(code **)(**(int **)(*(int *)(pbVar14 + 8) + 0xc) + 0x1c))
                            ((int)*(short *)(*(int *)(iVar9 + 0xc) + 0x4a),uVar19), iVar9 != 0))))))
{
      fVar18 = _DAT_00575278;
      switch(pbVar14[0xc] - 1) {
      case 0:
        return 1;
      case 3:
        uVar10 = (**(code **)(**(int **)(pbVar14 + 0x34) + 0xc))();
        switch((uVar10 & 0xff) - 1) {
        case 0:
        case 1:
        case 2:
          fVar18 = RGE_Static_Object::distance_to_object
                             (*(RGE_Static_Object **)(pbVar14 + 8),
                              *(RGE_Static_Object **)(pbVar14 + 0x10));
          DAT_0086bc08._0_4_ = fVar18 - _DAT_0057526c;
          if ((float)DAT_0086bc08 <= (float)_DAT_00575270) {
            (**(code **)(*(int *)pbVar14 + 0x5c))(6);
            return 0;
          }
          (**(code **)(*(int *)pbVar14 + 0x5c))(10);
          return 0;
        case 3:
        case 4:
          goto switchD_004d1c93_caseD_3;
        }
        break;
      case 5:
        if (*(int *)(pbVar14 + 0x10) == 0) {
          (**(code **)(*(int *)pbVar14 + 0x5c))(1);
          return 0;
        }
        cVar7 = (**(code **)(**(int **)(pbVar14 + 8) + 0x1f0))(*(int *)(pbVar14 + 0x10),0,0);
        if (cVar7 != '\0') {
          (**(code **)(*(int *)pbVar14 + 0x5c))(7);
          return 0;
        }
        break;
      case 6:
        pRVar8 = *(RGE_Static_Object **)(pbVar14 + 0x10);
        if (pRVar8 == (RGE_Static_Object *)0x0) {
          (**(code **)(*(int *)pbVar14 + 0x5c))(1);
          return 0;
        }
        if ((pRVar8->world_x != *(float *)(pbVar14 + 0x20)) ||
           (*(float *)(pbVar14 + 0x24) != pRVar8->world_y)) {
          fVar18 = RGE_Static_Object::distance_to_object
                             (*(RGE_Static_Object **)(pbVar14 + 8),pRVar8);
          DAT_0086bc08._0_4_ = fVar18 - _DAT_0057526c;
          if ((float)_DAT_00575270 < (float)DAT_0086bc08) {
            (**(code **)(*(int *)pbVar14 + 0x5c))(3);
            return 0;
          }
          iVar9 = *(int *)(pbVar14 + 0x10);
          *(undefined4 *)(pbVar14 + 0x20) = *(undefined4 *)(iVar9 + 0x38);
          *(undefined4 *)(pbVar14 + 0x24) = *(undefined4 *)(iVar9 + 0x3c);
          *(undefined4 *)(pbVar14 + 0x28) = *(undefined4 *)(iVar9 + 0x40);
          return 0;
        }
        cVar7 = (**(code **)(pRVar8->_padding_ + 0x8c))
                          (*(float *)(*(int *)(pbVar14 + 0x30) + 0x1c) *
                           *(float *)(*(int *)(*(int *)(*(int *)(pbVar14 + 8) + 0xc) + 0x3c) + 0x84)
                           * *(float *)(*(int *)(*(int *)(pbVar14 + 8) + 8) + 0xe4));
        if (cVar7 == '\x01') {
          (**(code **)(*(int *)pbVar14 + 0x5c))(1);
          return 0;
        }
        if (cVar7 == '\x02') {
          iVar9 = (*(int **)(pbVar14 + 8))[1];
          (**(code **)(**(int **)(pbVar14 + 8) + 0x148))(iVar9,iVar9,0x1fb,0x26a,0,0);
          (**(code **)(rge_base_game->_padding_ + 0x40))
                    (0x6b,(int)*(short *)(*(int *)(*(int *)(pbVar14 + 8) + 0xc) + 0x4a),
                     *(undefined4 *)(*(int *)(pbVar14 + 0x10) + 4),0,0);
          (**(code **)(*(int *)pbVar14 + 0x5c))(2);
          return 0;
        }
        break;
      case 9:
        if (*(RGE_Static_Object **)(pbVar14 + 0x10) != (RGE_Static_Object *)0x0) {
          fVar6 = *(float *)(pbVar14 + 0x2c) -
                  (*(RGE_Static_Object **)(pbVar14 + 8))->owner->world->world_time_delta_seconds;
          *(float *)(pbVar14 + 0x2c) = fVar6;
          if (fVar6 <= fVar18) {
            fVar18 = RGE_Static_Object::distance_to_object
                               (*(RGE_Static_Object **)(pbVar14 + 8),
                                *(RGE_Static_Object **)(pbVar14 + 0x10));
            DAT_0086bc08._0_4_ = fVar18 - _DAT_0057526c;
            if ((float)DAT_0086bc08 <= (float)_DAT_00575270) {
              (**(code **)(*(int *)pbVar14 + 0x5c))(6);
              return 0;
            }
            pbVar14[0x2c] = 0;
            pbVar14[0x2d] = 0;
            pbVar14[0x2e] = 0x80;
            pbVar14[0x2f] = 0x3f;
            return 0;
          }
        }
        break;
      case 10:
        uVar10 = (**(code **)(**(int **)(pbVar14 + 0x34) + 0xc))();
        switch((uVar10 & 0xff) - 1) {
        case 0:
        case 1:
        case 2:
        case 4:
          (**(code **)(*(int *)pbVar14 + 0x5c))(1);
          return 0;
        case 3:
          iVar9 = *(int *)pbVar14;
          (**(code **)(iVar9 + 0x54))(0);
          (**(code **)(iVar9 + 0x5c))(0xb);
          return 0;
        }
        break;
      case 0xc:
        iVar9 = (*(int **)(pbVar14 + 8))[1];
        (**(code **)(**(int **)(pbVar14 + 8) + 0x148))(iVar9,iVar9,0x1f9,0x26a,0,0);
        (**(code **)(*(int *)pbVar14 + 0x5c))(2);
        return 3;
      }
      return 0;
    }
  }
switchD_004d1c93_caseD_3:
  iVar9 = *(int *)pbVar14;
  (**(code **)(iVar9 + 0x54))(0);
  (**(code **)(iVar9 + 0x5c))(1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d1f5d
// Address: 004d1f5d
undefined4 __thiscall
FUN_004d1f5d(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  
  iVar1 = *param_1;
  param_1[9] = param_4;
  param_1[8] = param_3;
  param_1[10] = param_5;
  (**(code **)(iVar1 + 0x54))(0);
  (**(code **)(iVar1 + 0x5c))(0xb);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d1f93
// Address: 004d1f93
undefined4 __thiscall
FUN_004d1f93(TRIBE_Action_Repair *param_1,int param_2,int param_3,int param_4,int param_5)
{
  char cVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = param_1->_padding_;
    param_1->_padding_ = param_4;
    param_1->_padding_ = param_3;
    param_1->_padding_ = param_5;
    (**(code **)(iVar2 + 0x54))(0);
    (**(code **)(iVar2 + 0x5c))(0xb);
  }
  else if ((param_2 != param_1->_padding_) ||
          ((cVar1 = (char)param_1->_padding_, cVar1 != '\x04' && (cVar1 != '\x06')))) {
    iVar2 = param_1->_padding_;
    (**(code **)(iVar2 + 0x54))(param_2);
    param_1->_padding_ = *(int *)(param_2 + 0x38);
    param_1->_padding_ = *(int *)(param_2 + 0x3c);
    param_1->_padding_ = *(int *)(param_2 + 0x40);
    TRIBE_Action_Repair::meet_target(param_1);
    (**(code **)(iVar2 + 0x5c))(4);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d21a4
// Address: 004d21a4
RGE_Action * __thiscall FUN_004d21a4(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560148;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Make_Tech::_vftable_;
  param_1->action_type = 0x67;
  rge_read(param_2,param_1 + 1,2);
  rge_read(param_2,&param_1[1].action_type,4);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d2226
// Address: 004d2226
TRIBE_Action_Make_Tech * __thiscall FUN_004d2226(TRIBE_Action_Make_Tech *param_1,byte param_2)
{
  TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d224e
// Address: 004d224e
RGE_Action * __thiscall
FUN_004d224e(RGE_Action *param_1,RGE_Action_Object *param_2,undefined2 param_3,undefined4 param_4)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  *(undefined4 *)&param_1[1].action_type = param_4;
  param_1->_padding_ = (int)&TRIBE_Action_Make_Tech::_vftable_;
  param_1->action_type = 0x67;
  *(undefined2 *)&param_1[1]._padding_ = param_3;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d2281
// Address: 004d2281
void __fastcall FUN_004d2281(RGE_Action *param_1)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00560168;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Action_Make_Tech::_vftable_;
  uStack_4 = 0;
  if (param_1->state != '\x01') {
    TRIBE_Player_Tech::cancel_research
              (*(TRIBE_Player_Tech **)(param_1->obj->_padding_ + 0x220),(short)param_1[1]._padding_,
               '\0');
    if (rge_base_game->world->game_state == '\0') {
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x65,(int)*(short *)(param_1->obj->_padding_ + 0x4a),
                 (int)(short)param_1[1]._padding_,0,0);
      (**(code **)(*(int *)param_1->obj->_padding_ + 0x118))
                ((int)(short)param_1[1]._padding_,param_1->obj->_padding_,0xffffffff,
                 *(undefined4 *)&param_1[1].action_type);
      iVar1 = param_1->obj->_padding_;
      (**(code **)(param_1->obj->_padding_ + 0x148))(iVar1,iVar1,0x1f9,0x26c,0,0);
    }
  }
  uStack_4 = 0xffffffff;
  RGE_Action::~RGE_Action(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004d2368
// Address: 004d2368
void __thiscall FUN_004d2368(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,2);
  rge_write(param_2,&param_1[1].action_type,4);
  return;
}

// --------------------------------------------------

// Function: FUN_004d23a1
// Address: 004d23a1
void __thiscall FUN_004d23a1(int *param_1,short param_2)
{
  int iVar1;
  uchar uVar2;
  
  if (((char)param_2 != '\0') && (-1 < (short)param_1[0x10])) {
    uVar2 = TRIBE_Player_Tech::start_research
                      (*(TRIBE_Player_Tech **)(*(int *)(param_1[2] + 0xc) + 0x220),
                       (short)param_1[0x10],'\x01',&param_2);
    if (uVar2 == '\x01') {
      (**(code **)(*param_1 + 0x5c))(6);
      return;
    }
    (**(code **)(**(int **)(param_1[2] + 0xc) + 0x118))
              ((int)param_2,(int)(short)param_1[0x10],*(undefined4 *)(param_1[2] + 4),param_1[0x11])
    ;
    iVar1 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar1,iVar1,0x1f9,0x26c,0,0);
    (**(code **)(*param_1 + 0x5c))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d243d
// Address: 004d243d
void __thiscall FUN_004d243d(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004d244a
// Address: 004d244a
undefined4 __fastcall FUN_004d244a(int *param_1)
{
  int iVar1;
  int iVar2;
  uchar uVar3;
  undefined4 uVar4;
  float fStack_4;
  
  if ((char)param_1[3] == '\x01') {
    return 1;
  }
  if ((char)param_1[3] == '\x06') {
    if (rge_base_game->quick_build == 0) {
      fStack_4 = *(float *)(*(int *)(*(int *)(param_1[2] + 0xc) + 0x3c) + 0x84) *
                 *(float *)(*(int *)(param_1[2] + 8) + 0xe4);
    }
    else {
      fStack_4 = 1000.0;
    }
    uVar3 = TRIBE_Player_Tech::research
                      (*(TRIBE_Player_Tech **)(*(int *)(param_1[2] + 0xc) + 0x220),
                       (short)param_1[0x10],fStack_4);
    if (uVar3 == '\0') {
      (**(code **)(*param_1 + 0x5c))(1);
      iVar1 = param_1[2];
      iVar2 = rge_base_game->_padding_;
      uVar4 = __ftol();
      uVar4 = __ftol(uVar4);
      (**(code **)(iVar2 + 0x40))
                (100,(int)*(short *)(*(int *)(iVar1 + 0xc) + 0x4a),(int)(short)param_1[0x10],uVar4);
      (**(code **)(**(int **)(param_1[2] + 0xc) + 0x11c))
                ((int)(short)param_1[0x10],*(undefined4 *)(param_1[2] + 4),param_1[0x11]);
      iVar1 = ((int *)param_1[2])[1];
      (**(code **)(*(int *)param_1[2] + 0x148))(iVar1,iVar1,0x1fa,0x26c,0,0);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d254b
// Address: 004d254b
undefined4 __fastcall FUN_004d254b(int *param_1)
{
  int iVar1;
  
  (**(code **)(*param_1 + 0x5c))(1);
  TRIBE_Player_Tech::cancel_research
            (*(TRIBE_Player_Tech **)(*(int *)(param_1[2] + 0xc) + 0x220),(short)param_1[0x10],'\x01'
            );
  (**(code **)(rge_base_game->_padding_ + 0x40))
            (0x65,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),(int)(short)param_1[0x10],0,0);
  (**(code **)(**(int **)(param_1[2] + 0xc) + 0x118))
            ((int)(short)param_1[0x10],*(undefined4 *)(param_1[2] + 4),0xffffffff,param_1[0x11]);
  iVar1 = ((int *)param_1[2])[1];
  (**(code **)(*(int *)param_1[2] + 0x148))(iVar1,iVar1,0x1f9,0x26c,0,0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d25d7
// Address: 004d25d7
void __thiscall
FUN_004d25d7(int param_1,undefined2 *param_2,short *param_3,int param_4,short param_5)
{
  short sVar1;
  char *pcVar2;
  int iVar3;
  
  *param_2 = *(undefined2 *)(param_1 + 0x40);
  if (*(char *)(param_1 + 0xc) == '\x01') {
    *param_3 = 100;
  }
  else {
    sVar1 = TRIBE_Player_Tech::get_progress
                      (*(TRIBE_Player_Tech **)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x220),
                       *(short *)(param_1 + 0x40));
    *param_3 = sVar1;
  }
  if (param_4 != 0) {
    iVar3 = (int)param_5;
    pcVar2 = TRIBE_Player_Tech::get_name
                       (*(TRIBE_Player_Tech **)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x220),
                        *(short *)(param_1 + 0x40));
    strncpy(param_4,pcVar2,iVar3);
    *(undefined1 *)(param_4 + -1 + (int)param_5) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d2658
// Address: 004d2658
RGE_Action * __thiscall FUN_004d2658(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560188;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Trade::_vftable_;
  rge_read(param_2,param_1 + 1,4);
  rge_read(param_2,&param_1[1].action_type,4);
  param_1->action_type = 0x6f;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d26d6
// Address: 004d26d6
TRIBE_Action_Trade * __thiscall FUN_004d26d6(TRIBE_Action_Trade *param_1,byte param_2)
{
  TRIBE_Action_Trade::~TRIBE_Action_Trade(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d2705
// Address: 004d2705
RGE_Action * __thiscall
FUN_004d2705(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005601a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Trade::_vftable_;
  param_1->action_type = 0x6f;
  RGE_Action::set_target_obj(param_1,param_4);
  param_1->target_x = param_4->world_x;
  param_1->target_y = param_4->world_y;
  param_1->target_z = param_4->world_z;
  param_1[1]._padding_ = -0x40800000;
  *(undefined4 *)&param_1[1].action_type = 0xbf800000;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d2793
// Address: 004d2793
RGE_Action * __thiscall
FUN_004d2793(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->target_y = param_5;
  param_1->task = param_3;
  param_1->_padding_ = (int)&TRIBE_Action_Trade::_vftable_;
  param_1[1]._padding_ = -0x40800000;
  *(undefined4 *)&param_1[1].action_type = 0xbf800000;
  param_1->action_type = 0x6f;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d27e8
// Address: 004d27e8
void __thiscall FUN_004d27e8(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  rge_write(param_2,&param_1[1].action_type,4);
  return;
}

// --------------------------------------------------

// Function: FUN_004d2821
// Address: 004d2821
void __thiscall FUN_004d2821(int *param_1,char param_2)
{
  short sVar1;
  
  sVar1 = *(short *)(param_1[2] + 0x4c);
  if (((sVar1 != 0) && (sVar1 != 2)) && (sVar1 != 1)) {
    *(undefined2 *)(param_1[2] + 0x4c) = 1;
  }
  if (param_2 != '\0') {
    if (param_1[4] != 0) {
      (**(code **)(*param_1 + 0x5c))(4);
      return;
    }
    (**(code **)(*param_1 + 0x5c))(2);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: FUN_004d287b
// Address: 004d287b
void __thiscall FUN_004d287b(TRIBE_Action_Trade *param_1,undefined1 param_2)
{
  short sVar1;
  RGE_Sound *this;
  int iVar2;
  char cVar3;
  RGE_Action_Move_To *pRVar4;
  RGE_Sprite *pRVar5;
  RGE_Action *pRVar6;
  RGE_Static_Object *pRVar7;
  undefined4 unaff_EBX;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar8;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005601e1;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1->_padding_);
  *(undefined1 *)&param_1->_padding_ = param_2;
  switch(param_2) {
  case 2:
    iVar2 = *(int *)param_1->_padding_;
    pRVar5 = TRIBE_Action_Trade::get_wait_sprite(param_1);
    (**(code **)(iVar2 + 0x38))(pRVar5);
    iVar2 = param_1->_padding_;
    (**(code **)(iVar2 + 0x54))(0);
    (**(code **)(iVar2 + 0x58))(0);
    param_1->_padding_ = -0x40800000;
    param_1->_padding_ = -0x40800000;
    param_1->_padding_ = -0x40800000;
    *unaff_FS_OFFSET = unaff_EDI;
    return;
  case 3:
    iVar2 = ((int *)param_1->_padding_)[1];
    uVar8 = 0x202;
    (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar2,iVar2,0x202,0x267,0,0);
    iVar2 = *(int *)param_1->_padding_;
    pRVar5 = TRIBE_Action_Trade::get_wait_sprite(param_1);
    (**(code **)(iVar2 + 0x38))(pRVar5);
    *unaff_FS_OFFSET = uVar8;
    return;
  case 4:
    iVar2 = param_1->_padding_;
    if (iVar2 == 0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    param_1->_padding_ = *(int *)(iVar2 + 0x38);
    param_1->_padding_ = *(int *)(iVar2 + 0x3c);
    param_1->_padding_ = *(int *)(iVar2 + 0x40);
    pRVar4 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 1;
    if (pRVar4 != (RGE_Action_Move_To *)0x0) {
      pRVar5 = TRIBE_Action_Trade::get_move_sprite(param_1);
      pRVar6 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar4,(RGE_Action_Object *)param_1->_padding_,
                          (RGE_Static_Object *)param_1->_padding_,
                          *(float *)(param_1->_padding_ + 0x24),pRVar5);
      goto LAB_004d2ba3;
    }
    break;
  default:
switchD_004d28ba_caseD_5:
    *unaff_FS_OFFSET = uStack_c;
    return;
  case 6:
    iVar2 = *(int *)param_1->_padding_;
    pRVar5 = TRIBE_Action_Trade::get_move_sprite(param_1);
    (**(code **)(iVar2 + 0x38))(pRVar5);
    *unaff_FS_OFFSET = unaff_EBX;
    return;
  case 7:
    (**(code **)(*(int *)param_1->_padding_ + 0x38))(*(undefined4 *)(param_1->_padding_ + 0x38));
    this = *(RGE_Sound **)(param_1->_padding_ + 0x44);
    if (this != (RGE_Sound *)0x0) {
      RGE_Sound::play(this,1);
    }
    iVar2 = param_1->_padding_;
    if (iVar2 != 0) {
      param_1->pick_up_x = *(float *)(iVar2 + 0x38);
      param_1->pick_up_y = *(float *)(iVar2 + 0x3c);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    param_1->pick_up_x = -1.0;
    param_1->pick_up_y = -1.0;
    *unaff_FS_OFFSET = unaff_EBX;
    return;
  case 8:
    pRVar7 = (RGE_Static_Object *)param_1->_padding_;
    if (pRVar7->attribute_amount_held <= (float)DAT_00575348._0_4_) {
      iVar2 = param_1->_padding_;
      if (((iVar2 != 0) && (*(float *)(iVar2 + 0x44) <= (float)DAT_00575348._0_4_)) &&
         (cVar3 = (**(code **)(pRVar7->_padding_ + 0x138))
                            ((int)*(short *)(*(int *)(iVar2 + 8) + 0x10)), cVar3 == '\0')) {
        iVar2 = param_1->_padding_;
        (**(code **)(iVar2 + 0x54))(0);
        (**(code **)(iVar2 + 0x5c))(3);
      }
      goto switchD_004d28ba_caseD_5;
    }
    if ((param_1->_padding_ == 0) ||
       (*(short *)(*(int *)(param_1->_padding_ + 8) + 0x10) !=
        *(short *)&pRVar7->master_obj[1].radius_x)) {
      sVar1 = *(short *)&pRVar7->master_obj[1].radius_x;
      if (sVar1 == -1) {
        (**(code **)(param_1->_padding_ + 0x58))(0);
      }
      else {
        iVar2 = param_1->_padding_;
        pRVar7 = RGE_Object_List::find_by_master_ids
                           (pRVar7->owner->objects,(int)sVar1,
                            (int)*(short *)((int)&pRVar7->master_obj[1].radius_x + 2),
                            pRVar7->world_x,pRVar7->world_y,'\x01','\x02',pRVar7);
        (**(code **)(iVar2 + 0x58))(pRVar7);
      }
    }
    if (param_1->_padding_ == 0) {
      iVar2 = ((int *)param_1->_padding_)[1];
      uVar8 = 0x203;
      (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar2,iVar2,0x203,0x267,0,0);
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = uVar8;
      return;
    }
    pRVar4 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 2;
    if (pRVar4 != (RGE_Action_Move_To *)0x0) {
      pRVar5 = TRIBE_Action_Trade::get_move_sprite(param_1);
      pRVar6 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar4,(RGE_Action_Object *)param_1->_padding_,
                          (RGE_Static_Object *)param_1->_padding_,0.0,pRVar5);
      goto LAB_004d2ba3;
    }
    break;
  case 0xb:
    pRVar4 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (pRVar4 == (RGE_Action_Move_To *)0x0) {
      pRVar6 = (RGE_Action *)0x0;
    }
    else {
      pRVar5 = TRIBE_Action_Trade::get_move_sprite(param_1);
      pRVar6 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar4,(RGE_Action_Object *)param_1->_padding_,(float)param_1->_padding_,
                          (float)param_1->_padding_,(float)param_1->_padding_,0.0,pRVar5);
    }
    uStack_4 = 0xffffffff;
    if (pRVar6 == (RGE_Action *)0x0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_EBX;
      return;
    }
    RGE_Action::setSubAction(pRVar6,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)param_1->_padding_,pRVar6);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  pRVar6 = (RGE_Action *)0x0;
LAB_004d2ba3:
  uStack_4 = 0xffffffff;
  if (pRVar6 == (RGE_Action *)0x0) {
    (**(code **)(param_1->_padding_ + 0x5c))(0xd);
    *unaff_FS_OFFSET = unaff_EBX;
    return;
  }
  RGE_Action_List::add_action((RGE_Action_List *)param_1->_padding_,pRVar6);
  RGE_Action::setSubAction(pRVar6,'\x01');
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004d32ef
// Address: 004d32ef
int __fastcall FUN_004d32ef(int param_1)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x30);
  sVar1 = *(short *)(iVar2 + 0x14);
  if ((((sVar1 != -1) && (sVar1 == *(short *)(*(int *)(param_1 + 8) + 0x4c))) &&
      (iVar3 = __ftol(), 0 < iVar3)) && (iVar2 = *(int *)(iVar2 + 0x40), iVar2 != 0)) {
    return iVar2;
  }
  return *(int *)(*(int *)(*(int *)(param_1 + 8) + 8) + 0x18);
}

// --------------------------------------------------

// Function: FUN_004d3329
// Address: 004d3329
undefined4 __fastcall FUN_004d3329(int *param_1)
{
  (**(code **)(*param_1 + 0x5c))(2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d333d
// Address: 004d333d
undefined4 __thiscall FUN_004d333d(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  
  if (((param_2 == 0) || (*(int *)(param_2 + 0xc) != *(int *)(param_1[2] + 0xc))) ||
     (*(short *)(*(int *)(param_2 + 8) + 0x10) != *(short *)(*(int *)(param_1[2] + 8) + 0xe8))) {
    iVar1 = *param_1;
    param_1[9] = param_4;
    param_1[8] = param_3;
    param_1[10] = param_5;
    (**(code **)(iVar1 + 0x54))(0);
    (**(code **)(iVar1 + 0x5c))(0xb);
  }
  else if ((param_2 != param_1[5]) || ((char)param_1[3] != '\b')) {
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0x58))(param_2);
    (**(code **)(iVar1 + 0x5c))(8);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d33bd
// Address: 004d33bd
undefined4 __thiscall FUN_004d33bd(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  char cVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *param_1;
    param_1[9] = param_4;
    param_1[8] = param_3;
    param_1[10] = param_5;
    (**(code **)(iVar2 + 0x54))(0);
    (**(code **)(iVar2 + 0x5c))(0xb);
  }
  else if ((param_2 != param_1[4]) ||
          (((cVar1 = (char)param_1[3], cVar1 != '\x04' && (cVar1 != '\x06')) && (cVar1 != '\a')))) {
    if ((*(int *)(param_2 + 0xc) == *(int *)(param_1[2] + 0xc)) &&
       (*(short *)(*(int *)(param_2 + 8) + 0x10) == *(short *)(*(int *)(param_1[2] + 8) + 0xe8))) {
      iVar2 = *param_1;
      (**(code **)(iVar2 + 0x58))(param_2);
      (**(code **)(iVar2 + 0x5c))(8);
      return 1;
    }
    iVar2 = *param_1;
    (**(code **)(iVar2 + 0x54))(param_2);
    (**(code **)(iVar2 + 0x5c))(4);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d3462
// Address: 004d3462
RGE_Action * __thiscall FUN_004d3462(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  param_1->_padding_ = (int)&TRIBE_Action_Wonder::_vftable_;
  param_1->action_type = 0x78;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d3498
// Address: 004d3498
TRIBE_Action_Wonder * __thiscall FUN_004d3498(TRIBE_Action_Wonder *param_1,byte param_2)
{
  TRIBE_Action_Wonder::~TRIBE_Action_Wonder(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d34be
// Address: 004d34be
RGE_Action * __thiscall FUN_004d34be(RGE_Action *param_1,RGE_Action_Object *param_2)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->_padding_ = (int)&TRIBE_Action_Wonder::_vftable_;
  param_1->action_type = 0x78;
  param_1->timer = 0.0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d34e8
// Address: 004d34e8
void __fastcall FUN_004d34e8(RGE_Action *param_1)
{
  RGE_Game_World *pRVar1;
  int *piVar2;
  RGE_Action_Object *pRVar3;
  RGE_Player **ppRVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  RGE_Player **ppRVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_005601f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Action_Wonder::_vftable_;
  uStack_4 = 0;
  pRVar1 = rge_base_game->world;
  if (pRVar1->game_state == '\0') {
    ppRVar9 = pRVar1->players;
    iVar7 = (int)pRVar1->player_num;
    if ((param_1->state == '\x02') && (iVar8 = 1, ppRVar4 = ppRVar9, 1 < iVar7)) {
      do {
        if (iVar8 != *(short *)(param_1->obj->_padding_ + 0x4a)) {
          (**(code **)(param_1->obj->_padding_ + 0xdc))(ppRVar4[1],1,0xffffffff);
        }
        iVar8 = iVar8 + 1;
        ppRVar4 = ppRVar4 + 1;
      } while (iVar8 < iVar7);
    }
    if (param_1->state == '\x06') {
      iVar8 = 1;
      if (1 < iVar7) {
        do {
          ppRVar9 = ppRVar9 + 1;
          if (iVar8 != *(short *)(param_1->obj->_padding_ + 0x4a)) {
            (**(code **)(param_1->obj->_padding_ + 0xdc))(*ppRVar9,0,0xffffffff);
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar7);
      }
      if (rge_base_game->world[1].world_time == 0) {
        bVar5 = false;
        iVar7 = param_1->obj->_padding_;
        for (piVar2 = *(int **)(*(int *)(iVar7 + 0x28) + 4); piVar2 != (int *)0x0;
            piVar2 = (int *)piVar2[1]) {
          pRVar3 = (RGE_Action_Object *)*piVar2;
          if (((pRVar3 != param_1->obj) && (*(short *)(pRVar3->_padding_ + 0x10) == 0x114)) &&
             (1 < (byte)pRVar3->_padding_)) {
            bVar5 = true;
            break;
          }
        }
        RGE_Base_Game::reset_countdown_timer(rge_base_game,(int)*(short *)(iVar7 + 0x4a));
        if (bVar5) {
          RGE_Base_Game::set_countdown_timer
                    (rge_base_game,(int)*(short *)(param_1->obj->_padding_ + 0x4a),2000);
        }
      }
    }
    pRVar3 = param_1->obj;
    iVar7 = rge_base_game->_padding_;
    uVar6 = __ftol(0);
    uVar6 = __ftol(uVar6);
    (**(code **)(iVar7 + 0x40))(0x6e,(int)*(short *)(pRVar3->_padding_ + 0x4a),uVar6);
  }
  uStack_4 = 0xffffffff;
  RGE_Action::~RGE_Action(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004d3684
// Address: 004d3684
void __thiscall FUN_004d3684(int *param_1,char param_2)
{
  if (param_2 != '\0') {
    (**(code **)(*param_1 + 0x5c))(2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d36a2
// Address: 004d36a2
void __thiscall FUN_004d36a2(int param_1,char param_2)
{
  undefined4 uVar1;
  int iVar2;
  RGE_Player **ppRVar3;
  int iVar4;
  
  *(char *)(param_1 + 0xc) = param_2;
  if (param_2 == '\x02') {
    iVar4 = 1;
    iVar2 = (int)rge_base_game->world->player_num;
    ppRVar3 = rge_base_game->world->players;
    if (1 < iVar2) {
      do {
        ppRVar3 = ppRVar3 + 1;
        if (iVar4 != *(short *)((*(int **)(param_1 + 8))[3] + 0x4a)) {
          (**(code **)(**(int **)(param_1 + 8) + 0xd8))(*ppRVar3,1,0xffffffff);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
    iVar2 = *(int *)(param_1 + 8);
    iVar4 = rge_base_game->_padding_;
    uVar1 = __ftol(0);
    uVar1 = __ftol(uVar1);
    (**(code **)(iVar4 + 0x40))(0x6c,(int)*(short *)(*(int *)(iVar2 + 0xc) + 0x4a),uVar1);
  }
  else if (param_2 == '\x06') {
    iVar4 = 1;
    iVar2 = (int)rge_base_game->world->player_num;
    ppRVar3 = rge_base_game->world->players;
    if (1 < iVar2) {
      do {
        ppRVar3 = ppRVar3 + 1;
        if (iVar4 != *(short *)((*(int **)(param_1 + 8))[3] + 0x4a)) {
          (**(code **)(**(int **)(param_1 + 8) + 0xdc))(*ppRVar3,1,0xffffffff);
          (**(code **)(**(int **)(param_1 + 8) + 0xd8))(*ppRVar3,0,0xffffffff);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
    if (rge_base_game->world[1].world_time == 0) {
      RGE_Base_Game::set_countdown_timer
                (rge_base_game,(int)*(short *)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x4a),2000);
    }
    iVar2 = *(int *)(param_1 + 8);
    iVar4 = rge_base_game->_padding_;
    uVar1 = __ftol(0);
    uVar1 = __ftol(uVar1);
    (**(code **)(iVar4 + 0x40))(0x6d,(int)*(short *)(*(int *)(iVar2 + 0xc) + 0x4a),uVar1);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d3809
// Address: 004d3809
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_004d3809(int *param_1)
{
  float fVar1;
  int iVar2;
  RGE_Base_Game *this;
  ulong uVar3;
  long lVar4;
  undefined2 extraout_var;
  uint uVar5;
  
  if (*(byte *)(param_1 + 3) == 2) {
    uVar3 = 0;
    if (*(char *)(param_1[2] + 0x48) == '\x02') {
      uVar5 = (**(code **)(*param_1 + 0x5c))(6);
      return uVar5 & 0xffffff00;
    }
  }
  else {
    uVar3 = *(byte *)(param_1 + 3) - 6;
    if (uVar3 == 0) {
      fVar1 = (float)param_1[0xb];
      uVar3 = (ulong)(ushort)((ushort)(fVar1 < _DAT_005753d8) << 8 |
                              (ushort)(NAN(fVar1) || NAN(_DAT_005753d8)) << 10 |
                             (ushort)(fVar1 == _DAT_005753d8) << 0xe);
      if (fVar1 < _DAT_005753d8) {
        iVar2 = param_1[2];
        fVar1 = *(float *)(*(int *)(*(int *)(iVar2 + 0xc) + 0x3c) + 0x84);
        param_1[0xb] = (int)(fVar1 + fVar1 + (float)param_1[0xb]);
        this = rge_base_game;
        uVar3 = rge_base_game->world[1].world_time;
        if (uVar3 == 0) {
          lVar4 = __ftol();
          RGE_Base_Game::set_countdown_timer
                    (this,(int)*(short *)(*(int *)(iVar2 + 0xc) + 0x4a),lVar4);
          fVar1 = (float)param_1[0xb];
          uVar3 = CONCAT22(extraout_var,
                           (ushort)(fVar1 < _DAT_005753d8) << 8 |
                           (ushort)(NAN(fVar1) || NAN(_DAT_005753d8)) << 10 |
                           (ushort)(fVar1 == _DAT_005753d8) << 0xe);
          if (fVar1 >= _DAT_005753d8) {
            RGE_Player::win_game_now(*(RGE_Player **)(param_1[2] + 0xc));
            uVar5 = (uint)rge_base_game & 0xffffff00;
            rge_base_game->world->game_end_condition = 'd';
            return uVar5;
          }
        }
      }
    }
  }
  return uVar3 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004d38dc
// Address: 004d38dc
RGE_Action * __thiscall
FUN_004d38dc(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560218;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action::_vftable_;
  if (param_4 != 0) {
    TRIBE_Action::setup((TRIBE_Action *)param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d3945
// Address: 004d3945
TRIBE_Action * __thiscall FUN_004d3945(TRIBE_Action *param_1,byte param_2)
{
  TRIBE_Action::~TRIBE_Action(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d3975
// Address: 004d3975
RGE_Action * __thiscall FUN_004d3975(RGE_Action *param_1,RGE_Action_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560238;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action::_vftable_;
  if (param_3 != 0) {
    TRIBE_Action::setup((TRIBE_Action *)param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d39dd
// Address: 004d39dd
void __thiscall FUN_004d39dd(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  RGE_Action::setup(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004d39f2
// Address: 004d39f2
void __thiscall FUN_004d39f2(RGE_Action *param_1,RGE_Action_Object *param_2)
{
  RGE_Action::setup(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004d3a0d
// Address: 004d3a0d
undefined4 __fastcall FUN_004d3a0d(int param_1)
{
  TRIBE_Action_List *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0056025b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Action_List *)operator_new(0xc);
  uStack_4 = 0;
  if (this != (TRIBE_Action_List *)0x0) {
    uVar1 = TRIBE_Action_List::TRIBE_Action_List(this,*(RGE_Action_Object **)(param_1 + 8));
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d3a74
// Address: 004d3a74
BuildAIModule * __thiscall FUN_004d3a74(BuildAIModule *param_1,void *param_2,int param_3)
{
  BuildAIModule::BuildAIModule(param_1,param_2,param_3);
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TribeBuildAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d3aaa
// Address: 004d3aaa
TribeBuildAIModule * __thiscall FUN_004d3aaa(TribeBuildAIModule *param_1,byte param_2)
{
  TribeBuildAIModule::~TribeBuildAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d3ace
// Address: 004d3ace
BuildAIModule * __thiscall FUN_004d3ace(BuildAIModule *param_1,int param_2,int param_3)
{
  BuildAIModule::BuildAIModule(param_1,param_2,param_3);
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TribeBuildAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d3afa
// Address: 004d3afa
void __fastcall FUN_004d3afa(BuildAIModule *param_1)
{
  param_1->_padding_ = (int)&TribeBuildAIModule::_vftable_;
  BuildAIModule::~BuildAIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004d3b0b
// Address: 004d3b0b
void __thiscall FUN_004d3b0b(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x5bc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004d3b1d
// Address: 004d3b1d
void __thiscall FUN_004d3b1d(BuildAIModule *param_1,char *param_2,RGE_Player *param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar1 = (param_1->typesToIgnore).numberValue;
  if (0 < iVar1) {
    do {
      if ((param_1->typesToIgnore).maximumSizeValue <= iVar2) break;
      if ((param_1->typesToIgnore).value[iVar2] == 0x46) goto LAB_004d3bd8;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((param_1->typesToIgnore).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (param_1->typesToIgnore).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (param_1->typesToIgnore).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (param_1->typesToIgnore).maximumSizeValue);
      }
      operator_delete((param_1->typesToIgnore).value);
      (param_1->typesToIgnore).value = piVar3;
      (param_1->typesToIgnore).maximumSizeValue = iVar1;
    }
  }
  (param_1->typesToIgnore).value[(param_1->typesToIgnore).numberValue] = 0x46;
  (param_1->typesToIgnore).numberValue = (param_1->typesToIgnore).numberValue + 1;
LAB_004d3bd8:
  iVar1 = (param_1->typesToIgnore).numberValue;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if ((param_1->typesToIgnore).maximumSizeValue <= iVar2) break;
      if ((param_1->typesToIgnore).value[iVar2] == 0x67) goto LAB_004d3c8b;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((param_1->typesToIgnore).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (param_1->typesToIgnore).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (param_1->typesToIgnore).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (param_1->typesToIgnore).maximumSizeValue);
      }
      operator_delete((param_1->typesToIgnore).value);
      (param_1->typesToIgnore).value = piVar3;
      (param_1->typesToIgnore).maximumSizeValue = iVar1;
    }
  }
  (param_1->typesToIgnore).value[(param_1->typesToIgnore).numberValue] = 0x67;
  (param_1->typesToIgnore).numberValue = (param_1->typesToIgnore).numberValue + 1;
LAB_004d3c8b:
  iVar1 = (param_1->typesToIgnore).numberValue;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if ((param_1->typesToIgnore).maximumSizeValue <= iVar2) break;
      if ((param_1->typesToIgnore).value[iVar2] == 0x44) goto LAB_004d3d3e;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if ((param_1->typesToIgnore).maximumSizeValue + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    piVar3 = (int *)operator_new(iVar1 * 4);
    if (piVar3 != (int *)0x0) {
      iVar2 = 0;
      if (0 < (param_1->typesToIgnore).maximumSizeValue) {
        do {
          if (iVar1 <= iVar2) break;
          iVar4 = iVar2 + 1;
          piVar3[iVar2] = (param_1->typesToIgnore).value[iVar2];
          iVar2 = iVar4;
        } while (iVar4 < (param_1->typesToIgnore).maximumSizeValue);
      }
      operator_delete((param_1->typesToIgnore).value);
      (param_1->typesToIgnore).value = piVar3;
      (param_1->typesToIgnore).maximumSizeValue = iVar1;
    }
  }
  (param_1->typesToIgnore).value[(param_1->typesToIgnore).numberValue] = 0x44;
  (param_1->typesToIgnore).numberValue = (param_1->typesToIgnore).numberValue + 1;
LAB_004d3d3e:
  BuildAIModule::loadBuildList(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004d3d55
// Address: 004d3d55
void __fastcall FUN_004d3d55(TribeBuildAIModule *param_1)
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  BuildItem *pBVar9;
  undefined4 *unaff_FS_OFFSET;
  ResourceItem *pRVar10;
  int iVar11;
  int iStack_a8;
  int iStack_a0;
  int iStack_98;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  ResourceItem RStack_7c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560278;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar8 = -1;
  iStack_a8 = 0;
  pBVar9 = (BuildItem *)param_1->_padding_;
  iStack_90 = 0;
  iStack_88 = 0;
  iStack_8c = 0;
  iStack_80 = 0;
  iStack_84 = -1;
  iStack_98 = -1;
  bVar2 = false;
  bVar3 = false;
  bVar1 = false;
  for (; (pBVar9 != (BuildItem *)&param_1->_padding_ && (pBVar9 != (BuildItem *)0x0));
      pBVar9 = pBVar9->next) {
    iVar4 = BuildItem::buildCategory(pBVar9);
    if (iVar4 == 0) {
      iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
      if (iVar4 == 0x46) {
        iStack_a8 = iStack_a8 + 1;
      }
      else {
        iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
        if (iVar4 == 0x2d) {
          iStack_90 = iStack_90 + 1;
        }
      }
    }
    else {
      iVar4 = BuildItem::buildCategory(pBVar9);
      if (iVar4 == 2) {
        iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
        if (iVar4 == 0xd) {
          iStack_88 = iStack_88 + 1;
        }
        else {
          iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
          if ((iVar4 == 0x11) || (iVar4 = BaseItem::typeID((BaseItem *)pBVar9), iVar4 == 0x12)) {
            iStack_8c = iStack_8c + 1;
          }
          else {
            iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
            if ((iVar4 == 0x13) || (iVar4 = BaseItem::typeID((BaseItem *)pBVar9), iVar4 == 0xfa)) {
              iStack_80 = iStack_80 + 1;
            }
          }
        }
      }
      else {
        iVar4 = BuildItem::buildCategory(pBVar9);
        if ((iVar4 == 1) || (iVar4 = BuildItem::buildCategory(pBVar9), iVar4 == 4)) {
          iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
          if (iVar4 == 0x65) {
            iStack_84 = BaseItem::uniqueID((BaseItem *)pBVar9);
          }
          else {
            iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
            if (iVar4 == 0x66) {
              iVar8 = BaseItem::uniqueID((BaseItem *)pBVar9);
            }
            else {
              iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
              if (iVar4 == 0x67) {
                iStack_98 = BaseItem::uniqueID((BaseItem *)pBVar9);
              }
              else {
                iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
                if (iVar4 == 5) {
                  bVar2 = true;
                }
                else {
                  iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
                  if (iVar4 == 7) {
                    bVar3 = true;
                  }
                  else {
                    iVar4 = BaseItem::typeID((BaseItem *)pBVar9);
                    if (iVar4 == 8) {
                      bVar1 = true;
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
  iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd4);
  if ((iStack_90 < iVar4) &&
     (iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd0), iVar4 == 1)) {
    iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd4);
    iVar4 = iVar4 - iStack_90;
    if (iVar8 == -1) {
      if (iStack_84 == -1) {
        iVar5 = 10;
      }
      else {
        iVar5 = iStack_84 / iVar4;
      }
    }
    else {
      iVar5 = iVar8 / iVar4;
    }
    iVar6 = iVar5;
    if (0 < iVar4) {
      do {
        TribeBuildAIModule::insert(param_1,0x2d,-1,iVar6);
        iVar4 = iVar4 + -1;
        iVar6 = iVar6 + iVar5;
      } while (iVar4 != 0);
    }
  }
  iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd5);
  if ((iStack_88 < iVar4) &&
     (iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd1), iVar4 == 1)) {
    iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd5);
    iVar4 = iVar4 - iStack_88;
    if (0 < iVar4) {
      if (iVar8 == -1) {
        if (iStack_84 == -1) {
          iVar5 = 10;
        }
        else {
          iVar5 = iStack_84 / iVar4;
        }
      }
      else {
        iVar5 = iVar8 / iVar4;
      }
      iVar6 = iVar5;
      if (0 < iVar4) {
        do {
          TribeBuildAIModule::insert(param_1,0xd,-1,iVar6);
          iVar4 = iVar4 + -1;
          iVar6 = iVar6 + iVar5;
        } while (iVar4 != 0);
      }
    }
  }
  iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd6);
  if ((iStack_8c < iVar4) &&
     (iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd2), iVar4 == 1)) {
    iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xd6);
    iVar4 = iVar4 - iStack_8c;
    if (iStack_84 == -1) {
      if (iVar8 == -1) {
        iVar6 = 10;
        iVar5 = 0;
      }
      else {
        iVar6 = (param_1->_padding_ - iVar8) / (iVar4 * 2);
        iVar5 = -1;
      }
    }
    else {
      iVar6 = (param_1->_padding_ - iStack_84) / (iVar4 * 2);
      iVar5 = iVar8;
    }
    if (0 < iVar4) {
      do {
        iVar5 = iVar5 + iVar6;
        TribeBuildAIModule::insert(param_1,0x11,-1,iVar5);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if ((!bVar1) && (iStack_98 != -1)) {
      TribeBuildAIModule::insertResearch(param_1,8,iStack_98 + 2);
    }
  }
  iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xe0);
  if (((iStack_80 < iVar4) &&
      (iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xdf), iVar4 == 1))
     && ((iStack_98 != -1 || (iVar8 != -1)))) {
    iVar5 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xe0);
    iVar5 = iVar5 - iStack_80;
    iVar4 = iStack_98;
    if (iStack_98 == -1) {
      iVar4 = iVar8;
    }
    iVar4 = iVar4 / iVar5;
    iVar6 = iVar4;
    if (0 < iVar5) {
      do {
        TribeBuildAIModule::insertResearch(param_1,0x13,iVar6);
        iVar5 = iVar5 + -1;
        iVar6 = iVar6 + iVar4;
      } while (iVar5 != 0);
    }
    if ((!bVar2) && (iVar8 != -1)) {
      TribeBuildAIModule::insertResearch(param_1,5,iVar8 + 5);
    }
    if ((!bVar3) && (iStack_98 != -1)) {
      TribeBuildAIModule::insertResearch(param_1,7,iStack_98 + 5);
    }
  }
  if ((iStack_a8 == 0) &&
     (iVar8 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xb4), iVar8 == 1)) {
    pBVar9 = (BuildItem *)param_1->_padding_;
    iVar4 = 0;
    iVar8 = 0;
    iStack_a8 = 0;
    if (pBVar9 != (BuildItem *)&param_1->_padding_) {
      do {
        if (pBVar9 == (BuildItem *)0x0) break;
        iVar5 = BuildItem::buildCategory(pBVar9);
        if ((iVar5 == 0) && (iVar5 = BaseItem::typeID((BaseItem *)pBVar9), iVar5 == 0x6d)) {
          iVar8 = iVar8 + 4;
        }
        iVar5 = BuildItem::buildCategory(pBVar9);
        if (iVar5 == 2) {
          iStack_a8 = iStack_a8 + 1;
        }
        if (iVar8 < iStack_a8) {
          if (iVar4 < 2) {
            iVar5 = 1;
          }
          else {
            iVar5 = iVar4 + -1;
          }
          iVar5 = TribeBuildAIModule::insert(param_1,0x46,-1,iVar5);
          if (iVar5 == 1) {
            iVar8 = iVar8 + 4;
          }
        }
        iVar5 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x98);
        if (iVar5 + 0x32 < iVar8) break;
        pBVar9 = pBVar9->next;
        iVar4 = iVar4 + 1;
      } while (pBVar9 != (BuildItem *)&param_1->_padding_);
    }
  }
  iVar8 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xa0);
  iVar4 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x9b);
  if (iVar8 != 0) {
    pBVar9 = (BuildItem *)param_1->_padding_;
    ResourceItem::ResourceItem(&RStack_7c,4);
    iStack_a0 = 0;
    uStack_4 = 0;
    ResourceItem::setAllValues(&RStack_7c,0);
    if (pBVar9 != (BuildItem *)&param_1->_padding_) {
      iStack_a8 = 0;
      do {
        if (pBVar9 == (BuildItem *)0x0) break;
        iVar5 = BuildItem::buildCategory(pBVar9);
        if (iVar5 == 6) {
          pBVar9 = pBVar9->next;
          iStack_a0 = iStack_a0 + 1;
        }
        else {
          iVar5 = BuildItem::buildCategory(pBVar9);
          if ((iVar5 == 1) || (iVar5 = BuildItem::buildCategory(pBVar9), iVar5 == 4)) {
            pRVar10 = &RStack_7c;
            iVar11 = 1;
            iVar6 = -1;
            iVar5 = BaseItem::typeID((BaseItem *)pBVar9);
            TRIBE_Player::researchCost(param_1->md->aiPlayer,iVar5,iVar6,pRVar10,iVar11);
          }
          else {
            pRVar10 = &RStack_7c;
            iVar11 = 1;
            iVar6 = -1;
            iVar5 = BaseItem::typeID((BaseItem *)pBVar9);
            TRIBE_Player::objectCost(param_1->md->aiPlayer,iVar5,iVar6,pRVar10,iVar11);
          }
          iStack_a0 = iStack_a0 + 1;
          if (iVar4 + 4 <= iStack_a0) {
            iVar5 = 0;
            iVar6 = 0;
            do {
              iVar11 = ResourceItem::value(&RStack_7c,iVar6);
              iVar5 = iVar5 + iVar11;
              iVar6 = iVar6 + 1;
            } while (iVar6 < 4);
            if (0 < iVar5) {
              iVar6 = 0;
              do {
                iVar11 = iStack_a8;
                iVar7 = ResourceItem::value(&RStack_7c,iVar6);
                TribeBuildAIModule::insertGathererPercentage
                          (param_1,iVar6,(iVar7 * iVar8) / iVar5,iVar11);
                iVar6 = iVar6 + 1;
              } while (iVar6 < 4);
              ResourceItem::setAllValues(&RStack_7c,0);
              iStack_a8 = iStack_a8 + iVar4 + 4;
              iStack_a0 = 0;
            }
          }
          pBVar9 = pBVar9->next;
        }
      } while (pBVar9 != (BuildItem *)&param_1->_padding_);
    }
    uStack_4 = 0xffffffff;
    ResourceItem::~ResourceItem(&RStack_7c);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004d4454
// Address: 004d4454
void __fastcall FUN_004d4454(int param_1)
{
  int iVar1;
  int iVar2;
  BuildItem *this;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  if (this != (BuildItem *)(param_1 + 0xf0)) {
    while (this != (BuildItem *)0x0) {
      iVar1 = BuildItem::built(this);
      if (((iVar1 == 0) && (iVar1 = BuildItem::inProgress(this), iVar1 == 0)) &&
         (iVar1 = BaseItem::skip((BaseItem *)this), iVar1 != 1)) {
        iVar1 = TribeTacticalAIModule::strategicNumber
                          ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x5bc) + 0x1146c),0xb1);
        iVar2 = BaseItem::typeID((BaseItem *)this);
        if ((iVar2 != iVar1) || (iVar1 = BuildItem::buildCategory(this), iVar1 != 0)) {
          iVar1 = TribeTacticalAIModule::strategicNumber
                            ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x5bc) + 0x1146c),0x72);
          BuildItem::setBuildAttempts(this,iVar1);
          BaseItem::setSkip((BaseItem *)this,1);
          BuildItem::incrementSkipCycles(this);
          iVar1 = TribeTacticalAIModule::strategicNumber
                            ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x5bc) + 0x1146c),0x92);
          iVar2 = BuildItem::skipCycles(this);
          if (iVar2 != iVar1) {
            return;
          }
          BuildItem::setPermanentSkip(this,'\x01');
          return;
        }
      }
      this = this->next;
      if (this == (BuildItem *)(param_1 + 0xf0)) {
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d453a
// Address: 004d453a
/* WARNING: Removing unreachable block (ram,0x004d46de) */
/* WARNING: Removing unreachable block (ram,0x004d4758) */

BuildItem * __fastcall FUN_004d453a(TribeBuildAIModule *param_1)
{
  code *pcVar1;
  bool bVar2;
  uchar uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  BuildItem *this;
  RGE_Static_Object *pRVar9;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  int iVar10;
  int iVar11;
  int iVar12;
  ResourceItem *pRVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  ResourceItem RStack_94;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  int iStack_14;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005602a3;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pcVar1 = *(code **)(param_1->_padding_ + 0x48);
  (*pcVar1)(0x67);
  (*pcVar1)(0x44,0);
  iVar4 = (*pcVar1)(0x46,0);
  this = (BuildItem *)param_1->_padding_;
  iVar18 = 0;
  iVar5 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x73);
  if (-1 < iVar5) {
    do {
      if ((this == (BuildItem *)&param_1->_padding_) || (this == (BuildItem *)0x0)) break;
      iVar5 = BuildItem::buildCategory(this);
      if ((iVar5 == 1) || (iVar5 = BuildItem::buildCategory(this), iVar5 == 4)) {
        iVar5 = BaseItem::typeID((BaseItem *)this);
        iVar5 = TribeBuildAIModule::isAgeResearch(param_1,iVar5);
        if (iVar5 != 1) goto switchD_004d4615_default;
        iVar5 = BaseItem::typeID((BaseItem *)this);
        uVar3 = TRIBE_Player::researchState(param_1->md->aiPlayer,iVar5);
        switch(uVar3) {
        case '\0':
        case '\x01':
          iVar5 = 0;
          break;
        case '\x02':
          BuildItem::setBuilt(this,0);
          iVar5 = 1;
          goto LAB_004d4638;
        case '\x03':
          iVar5 = 1;
          break;
        default:
          goto switchD_004d4615_default;
        }
        BuildItem::setBuilt(this,iVar5);
        iVar5 = 0;
LAB_004d4638:
        BuildItem::setInProgress(this,iVar5);
      }
switchD_004d4615_default:
      iVar5 = BuildItem::built(this);
      if ((iVar5 == 0) && (iVar5 = BuildItem::inProgress(this), iVar5 == 0)) {
        bVar2 = true;
        iVar5 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xa1);
        if ((iVar5 == 1) && (unaff_EDI == 0)) {
          bVar2 = false;
        }
        if (((iVar5 == 2) &&
            (iVar6 = TribeResourceAIModule::resource(&param_1->md->resourceAI,1), iVar6 < 0xfa)) &&
           (unaff_EDI == 0)) {
          bVar2 = false;
        }
        if (iVar5 == 3) {
          bVar2 = false;
        }
        if (iVar5 == 4) {
          bVar2 = false;
        }
        if ((iStack_14 == 0) &&
           (((((!bVar2 && (iVar5 = BuildItem::buildCategory(this), iVar5 == 0)) &&
              ((iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 != 0x46 &&
               ((iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 != 0x6d &&
                (iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 != 0x67)))))) &&
             (iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 != 0x44)) ||
            (((((iStack_14 == 0 && (iVar5 = BuildItem::buildCategory(this), iVar5 == 0)) &&
               (iVar5 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xae),
               iVar5 <= iVar4)) &&
              ((iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 != 0x6d &&
               (iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 != 0x67)))) &&
             (iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 != 0x44)))))) goto LAB_004d489e;
        iVar5 = BuildItem::buildCategory(this);
        if ((iVar5 == 5) && (iVar18 == 0)) {
          TribeTacticalAIModule::enableAttack(&param_1->md->tacticalAI,1);
LAB_004d488c:
          BuildItem::setInProgress(this,0);
          BuildItem::setBuilt(this,1);
          goto LAB_004d489e;
        }
        iVar6 = BuildItem::buildCategory(this);
        iVar5 = iStack_14;
        if (iVar6 == 6) {
          if (0 < iVar18) goto LAB_004d489e;
          iVar5 = BuildItem::buildFrom(this);
          iVar6 = BaseItem::typeID((BaseItem *)this);
          TribeTacticalAIModule::setStrategicNumber(&param_1->md->tacticalAI,iVar6 + 0x9c,iVar5);
          goto LAB_004d488c;
        }
        if ((iStack_14 == 3) && (0 < iVar18)) break;
        iVar6 = BuildItem::buildCap(this);
        if (iVar6 != -1) {
          iVar6 = BuildItem::buildCap(this);
          iVar7 = BuildItem::numberBuilds(this);
          if (iVar6 < iVar7) goto LAB_004d489e;
        }
        if ((iVar5 == 1) &&
           ((iVar6 = BuildItem::buildCategory(this), iVar6 == 1 ||
            (iVar6 = BuildItem::buildCategory(this), iVar6 == 4)))) {
          iVar6 = BaseItem::typeID((BaseItem *)this);
          iVar6 = TRIBE_Player::researchEverAvailable(param_1->md->aiPlayer,iVar6);
          if (iVar6 == 0) goto LAB_004d488c;
        }
        iVar6 = BuildItem::buildCategory(this);
        if (iVar6 == 4) {
          ResourceItem::ResourceItem(&RStack_94,4);
          pRVar13 = &RStack_94;
          iVar16 = 1;
          iVar7 = -1;
          uStack_1c = 0;
          iVar6 = BaseItem::typeID((BaseItem *)this);
          TRIBE_Player::researchCost(param_1->md->aiPlayer,iVar6,iVar7,pRVar13,iVar16);
          iVar6 = BaseItem::typeID((BaseItem *)this);
          iVar6 = TRIBE_Player::researchAvailable(param_1->md->aiPlayer,iVar6);
          if ((iVar6 != 0) &&
             (iVar6 = TribeResourceAIModule::resourcesAvailable(&param_1->md->resourceAI,&RStack_94)
             , iVar6 != 0)) {
            uStack_1c = 0xffffffff;
            if (iVar5 == 1) {
              ResourceItem::~ResourceItem(&RStack_94);
              goto LAB_004d4a65;
            }
          }
          uStack_1c = 0xffffffff;
          ResourceItem::~ResourceItem(&RStack_94);
          break;
        }
LAB_004d4a65:
        iVar6 = BaseItem::skip((BaseItem *)this);
        if (((iVar6 == 1) && (iVar6 = BuildItem::buildAttempts(this), 0 < iVar6)) ||
           (uVar3 = BuildItem::permanentSkip(this), uVar3 != '\0')) {
          BuildItem::decrementBuildAttempts(this);
          goto LAB_004d489e;
        }
        iVar6 = BaseItem::skip((BaseItem *)this);
        if ((iVar6 == 1) && (iVar6 = BuildItem::buildAttempts(this), iVar6 < 1)) {
          BaseItem::setSkip((BaseItem *)this,0);
          iVar6 = BuildItem::buildCategory(this);
          if ((iVar6 == 0) &&
             ((iVar6 = BaseItem::typeID((BaseItem *)this), iVar6 == 0x67 ||
              (iVar6 = BaseItem::typeID((BaseItem *)this), iVar6 == 0x44)))) {
            iVar6 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x72);
            BuildItem::setBuildAttempts(this,iVar6 + -1);
          }
        }
        iVar6 = *(int *)(param_1->md->_padding_ + 0x50);
        if ((*(float *)(iVar6 + 0x2c) < *(float *)(iVar6 + 0x80)) ||
           (iVar6 = BuildItem::buildCategory(this), iVar6 != 2)) {
          iVar18 = iVar18 + 1;
        }
        if (iVar5 != 1) {
          iVar6 = BuildItem::buildCategory(this);
          if (iVar5 == iVar6) goto LAB_004d4b55;
          goto LAB_004d489e;
        }
        iVar6 = BuildItem::buildCategory(this);
        if ((iVar6 != 1) && (iVar6 = BuildItem::buildCategory(this), iVar6 != 4)) goto LAB_004d489e;
LAB_004d4b55:
        if ((iVar5 == 3) && (iVar6 = BuildItem::buildCategory(this), iVar6 != 3)) {
LAB_004d48db:
          BuildItem::setBuildAttempts(this,0);
          break;
        }
        BuildItem::incrementBuildAttempts(this);
        iVar6 = BuildItem::buildAttempts(this);
        iVar7 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x72);
        if (((iVar7 < iVar6) && (iVar6 = BaseItem::skip((BaseItem *)this), iVar6 == 0)) &&
           (uVar3 = BuildItem::permanentSkip(this), uVar3 == '\0')) {
          if ((iVar5 == 1) && (iVar6 = BuildItem::buildCategory(this), iVar6 == 4))
          goto LAB_004d48db;
          iVar6 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xb1);
          iVar7 = BaseItem::typeID((BaseItem *)this);
          if ((iVar7 != iVar6) || (iVar6 = BuildItem::buildCategory(this), iVar6 != 0)) {
            BaseItem::setSkip((BaseItem *)this,1);
            iVar5 = BuildItem::buildCategory(this);
            if ((iVar5 == 0) &&
               ((iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 == 0x67 ||
                (iVar5 = BaseItem::typeID((BaseItem *)this), iVar5 == 0x44)))) {
              iVar5 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x72);
              BuildItem::setBuildAttempts(this,iVar5 * 6);
            }
            else {
              iVar5 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x72);
              BuildItem::setBuildAttempts(this,iVar5);
            }
            goto LAB_004d489e;
          }
        }
        if ((iVar5 == 3) && (iVar6 = BuildItem::buildCategory(this), iVar6 == 3)) {
          uVar15 = 0x3f;
          pcVar8 = BaseItem::name((BaseItem *)this);
          strncpy((undefined1 *)((int)&param_1->_padding_ + 2),pcVar8,uVar15);
          iVar18 = BaseItem::uniqueID((BaseItem *)this);
          param_1->_padding_ = iVar18;
          uVar15 = 0x3f;
          pcVar8 = BaseItem::name((BaseItem *)this->next);
          strncpy((undefined1 *)((int)&param_1->_padding_ + 3),pcVar8,uVar15);
          iVar18 = BaseItem::uniqueID((BaseItem *)this);
          param_1->_padding_ = iVar18;
          goto LAB_004d499d;
        }
        if (iVar5 == 1) {
          iVar6 = BaseItem::typeID((BaseItem *)this);
          iVar6 = TRIBE_Player::researchAvailable(param_1->md->aiPlayer,iVar6);
        }
        else {
          iVar6 = BaseItem::typeID((BaseItem *)this);
          iVar6 = TRIBE_Player::objectAvailable(param_1->md->aiPlayer,iVar6);
        }
        if (iVar6 == 0) goto LAB_004d489e;
        ResourceItem::ResourceItem((ResourceItem *)&stack0xfffffefc,4);
        uStack_1c = 1;
        iVar6 = 1;
        if (iVar5 == 1) {
          pRVar13 = (ResourceItem *)&stack0xfffffefc;
          iVar16 = -1;
          iVar7 = BaseItem::typeID((BaseItem *)this);
          TRIBE_Player::researchCost(param_1->md->aiPlayer,iVar7,iVar16,pRVar13,iVar6);
        }
        else {
          pRVar13 = (ResourceItem *)&stack0xfffffefc;
          iVar16 = -1;
          iVar7 = BaseItem::typeID((BaseItem *)this);
          TRIBE_Player::objectCost(param_1->md->aiPlayer,iVar7,iVar16,pRVar13,iVar6);
        }
        iVar6 = TribeResourceAIModule::resourcesAvailable
                          (&param_1->md->resourceAI,(ResourceItem *)&stack0xfffffefc);
        if (iVar6 != 0) {
          if ((iVar5 == 2) || (iVar5 == 1)) {
            iVar17 = -1;
            iVar14 = 2;
            iVar12 = -1;
            iVar11 = -1;
            iVar10 = -1;
            iVar16 = -1;
            iVar7 = -1;
            iVar6 = -1;
            iVar5 = BuildItem::buildFrom(this);
            pRVar9 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_1->md,-1,iVar5,iVar6,iVar7,iVar16,
                                iVar10,iVar11,iVar12,iVar14,iVar17);
          }
          else {
            pRVar9 = (RGE_Static_Object *)
                     TribeConstructionAIModule::canPlace(&param_1->md->constructionAI,this);
          }
          if (pRVar9 != (RGE_Static_Object *)0x0) {
            uVar15 = 0x3f;
            pcVar8 = BaseItem::name((BaseItem *)this);
            strncpy((undefined1 *)((int)&param_1->_padding_ + 2),pcVar8,uVar15);
            iVar18 = BaseItem::uniqueID((BaseItem *)this);
            param_1->_padding_ = iVar18;
            uVar15 = 0x3f;
            pcVar8 = BaseItem::name((BaseItem *)this->next);
            strncpy((undefined1 *)((int)&param_1->_padding_ + 3),pcVar8,uVar15);
            iVar18 = BaseItem::uniqueID((BaseItem *)this);
            param_1->_padding_ = iVar18;
            uStack_1c = 0xffffffff;
            ResourceItem::~ResourceItem((ResourceItem *)&stack0xfffffefc);
            goto LAB_004d499d;
          }
        }
        this = this->next;
        uStack_1c = 0xffffffff;
        ResourceItem::~ResourceItem((ResourceItem *)&stack0xfffffefc);
      }
      else {
LAB_004d489e:
        this = this->next;
      }
      iVar5 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x73);
    } while (iVar18 <= iVar5);
  }
  this = (BuildItem *)0x0;
LAB_004d499d:
  *unaff_FS_OFFSET = uStack_24;
  return this;
}

// --------------------------------------------------

// Function: FUN_004d4e0e
// Address: 004d4e0e
int __fastcall FUN_004d4e0e(int param_1)
{
  BuildItem *pBVar1;
  uchar uVar2;
  int iVar3;
  BuildItem *this;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  ResourceItem *pRVar5;
  int iVar6;
  ResourceItem RStack_7c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005602b8;
  *unaff_FS_OFFSET = &uStack_c;
  this = *(BuildItem **)(param_1 + 0x15c);
  pBVar1 = (BuildItem *)(param_1 + 0xf0);
  if (this == pBVar1) goto LAB_004d4f6b;
  do {
    if (this == (BuildItem *)0x0) break;
    iVar3 = BuildItem::built(this);
    if (iVar3 == 0) {
      iVar3 = BuildItem::inProgress(this);
      if (iVar3 == 0) {
        iVar3 = BaseItem::skip((BaseItem *)this);
        if (iVar3 != 1) {
          uVar2 = BuildItem::permanentSkip(this);
          if (uVar2 == '\0') break;
        }
      }
    }
    this = this->next;
  } while (this != pBVar1);
  if ((this == pBVar1) || (this == (BuildItem *)0x0)) goto LAB_004d4f6b;
  ResourceItem::ResourceItem(&RStack_7c,4);
  uStack_4 = 0;
  iVar3 = BuildItem::buildCategory(this);
  if (iVar3 == 1) {
LAB_004d4edb:
    pRVar5 = &RStack_7c;
    iVar6 = 1;
    iVar4 = -1;
    iVar3 = BaseItem::typeID((BaseItem *)this);
    TRIBE_Player::researchCost
              (*(TRIBE_Player **)(*(int *)(param_1 + 0x5bc) + 0x1256c),iVar3,iVar4,pRVar5,iVar6);
  }
  else {
    iVar3 = BuildItem::buildCategory(this);
    if (iVar3 == 4) goto LAB_004d4edb;
    pRVar5 = &RStack_7c;
    iVar6 = 1;
    iVar4 = -1;
    iVar3 = BaseItem::typeID((BaseItem *)this);
    TRIBE_Player::objectCost
              (*(TRIBE_Player **)(*(int *)(param_1 + 0x5bc) + 0x1256c),iVar3,iVar4,pRVar5,iVar6);
  }
  iVar3 = TribeResourceAIModule::resourcesAvailable
                    ((TribeResourceAIModule *)(*(int *)(param_1 + 0x5bc) + 0x10d7c),&RStack_7c);
  if (iVar3 == 0) {
    iVar3 = TribeResourceAIModule::unavailableResource
                      ((TribeResourceAIModule *)(*(int *)(param_1 + 0x5bc) + 0x10d7c),&RStack_7c);
    uStack_4 = 0xffffffff;
    ResourceItem::~ResourceItem(&RStack_7c);
    *unaff_FS_OFFSET = uStack_c;
    return iVar3;
  }
  uStack_4 = 0xffffffff;
  ResourceItem::~ResourceItem(&RStack_7c);
LAB_004d4f6b:
  *unaff_FS_OFFSET = uStack_c;
  return -1;
}

// --------------------------------------------------

// Function: FUN_004d5088
// Address: 004d5088
undefined4 __thiscall FUN_004d5088(int param_1,RGE_Static_Object *param_2,int param_3)
{
  int iVar1;
  BuildItem *this;
  
  iVar1 = TribeInformationAIModule::isBuilding
                    ((TribeInformationAIModule *)(*(int *)(param_1 + 0x5bc) + 0xcec),param_2);
  if (iVar1 != 0) {
    TribeConstructionAIModule::setBuilt
              ((TribeConstructionAIModule *)(*(int *)(param_1 + 0x5bc) + 0x6c4),param_2,1);
  }
  if (param_3 == 0) {
    this = *(BuildItem **)(param_1 + 0x15c);
    if (this != (BuildItem *)(param_1 + 0xf0)) {
      while (this != (BuildItem *)0x0) {
        iVar1 = BaseItem::typeID((BaseItem *)this);
        if (iVar1 == param_2->master_obj->id) {
          iVar1 = BuildItem::built(this);
          if (iVar1 == 0) {
            BaseItem::setGameID((BaseItem *)this,param_2->id);
            BuildItem::setInProgress(this,0);
            BuildItem::setBuilt(this,1);
            BuildItem::incrementNumberBuilds(this);
            iVar1 = BaseItem::typeID((BaseItem *)this);
            if (iVar1 == 0x114) {
              *(undefined4 *)(*(int *)(param_1 + 0x5bc) + 0x122b4) = 1;
            }
            return 1;
          }
        }
        this = this->next;
        if (this == (BuildItem *)(param_1 + 0xf0)) {
          return 0;
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d5168
// Address: 004d5168
undefined4 __thiscall FUN_004d5168(int param_1,int param_2,int param_3)
{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  BuildItem *this;
  undefined4 uVar4;
  
  bVar3 = false;
  this = *(BuildItem **)(param_1 + 0x15c);
  if (this != (BuildItem *)(param_1 + 0xf0)) {
    do {
      if ((this == (BuildItem *)0x0) || (bVar3)) break;
      iVar1 = BaseItem::typeID((BaseItem *)this);
      if ((iVar1 == *(short *)(*(int *)(param_2 + 8) + 0x10)) &&
         (((iVar1 = BuildItem::built(this), iVar1 == 0 && (param_3 != -1)) &&
          (iVar1 = BaseItem::uniqueID((BaseItem *)this), iVar1 == param_3)))) {
        BuildItem::setInProgress(this,0);
        bVar3 = true;
        BuildItem::setBuilt(this,1);
        BaseItem::setGameID((BaseItem *)this,*(int *)(param_2 + 4));
        BuildItem::incrementNumberBuilds(this);
        iVar1 = BaseItem::typeID((BaseItem *)this);
        if (iVar1 == 0x114) {
          *(undefined4 *)(*(int *)(param_1 + 0x5bc) + 0x122b4) = 1;
        }
        uVar4 = 0x3f;
        pcVar2 = BaseItem::name((BaseItem *)this);
        strncpy(param_1 + 0x2a5,pcVar2,uVar4);
        iVar1 = BaseItem::uniqueID((BaseItem *)this);
        *(int *)(param_1 + 0x5a8) = iVar1;
      }
      else {
        this = this->next;
      }
    } while (this != (BuildItem *)(param_1 + 0xf0));
  }
  TribeTacticalAIModule::updateNeededResources
            ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x5bc) + 0x1146c));
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d526c
// Address: 004d526c
undefined4 __thiscall FUN_004d526c(int param_1,int param_2)
{
  BuildItem *this;
  int iVar1;
  bool bVar2;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  bVar2 = false;
  while (((this != (BuildItem *)(param_1 + 0xf0) && (this != (BuildItem *)0x0)) && (!bVar2))) {
    iVar1 = BaseItem::gameID((BaseItem *)this);
    if ((iVar1 == param_2) && (iVar1 = BuildItem::built(this), iVar1 == 1)) {
      BuildItem::setInProgress(this,0);
      BuildItem::setBuilt(this,0);
      BaseItem::setGameID((BaseItem *)this,-1);
      BuildItem::setBuildAttempts(this,0);
      iVar1 = BaseItem::typeID((BaseItem *)this);
      if (iVar1 == 0x114) {
        *(undefined4 *)(*(int *)(param_1 + 0x5bc) + 0x122b4) = 0;
      }
      bVar2 = true;
    }
    else {
      this = this->next;
      bVar2 = false;
    }
  }
  TribeTacticalAIModule::updateNeededResources
            ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x5bc) + 0x1146c));
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d530f
// Address: 004d530f
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004d530f(BuildAIModule *param_1,undefined4 param_2,int param_3,int param_4,float param_5,
            float param_6,undefined4 param_7,int param_8)
{
  bool bVar1;
  uchar uVar2;
  uchar uVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  ConstructionItem *this;
  BuildItem *this_00;
  uchar unaff_SI;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  if (param_8 != -1) {
    TribeMainDecisionAIModule::detask((TribeMainDecisionAIModule *)param_1[1]._padding_,param_8);
  }
  bVar1 = false;
  param_8 = 0;
  switch(param_2) {
  default:
    param_8 = 1;
    bVar1 = false;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    break;
  case 8:
    bVar1 = true;
    param_8 = 1;
    break;
  case 0xffffffff:
    param_8 = 1;
    bVar1 = false;
  }
  pRVar4 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1[1]._padding_,param_3);
  if ((pRVar4 != (RGE_Static_Object *)0x0) && (bVar1)) {
    iVar5 = TribeMainDecisionAIModule::isMoveable
                      ((TribeMainDecisionAIModule *)param_1[1]._padding_,param_3);
    if (iVar5 == 1) {
      this = ConstructionAIModule::lot
                       ((ConstructionAIModule *)(param_1[1]._padding_ + 0x6c4),param_5,param_6);
      if (this == (ConstructionItem *)0x0) {
        TribeTacticalAIModule::clearArea
                  ((TribeTacticalAIModule *)(param_1[1]._padding_ + 0x1146c),param_3,
                   param_5 - _DAT_00575498,param_6 - _DAT_00575498,param_5 - _DAT_00575494,
                   param_6 - _DAT_00575494);
      }
      else {
        fVar6 = BaseItem::y((BaseItem *)this);
        fVar7 = BaseItem::ySize((BaseItem *)this);
        fVar6 = fVar6 - fVar7 * _DAT_0057548c;
        fVar7 = BaseItem::x((BaseItem *)this);
        fVar8 = BaseItem::xSize((BaseItem *)this);
        fVar7 = fVar7 - fVar8 * _DAT_0057548c;
        fVar8 = BaseItem::y((BaseItem *)this);
        fVar9 = BaseItem::ySize((BaseItem *)this);
        fVar8 = fVar8 - fVar9 * _DAT_00575490;
        fVar9 = BaseItem::x((BaseItem *)this);
        fVar10 = BaseItem::xSize((BaseItem *)this);
        TribeTacticalAIModule::clearArea
                  ((TribeTacticalAIModule *)(param_1[1]._padding_ + 0x1146c),param_3,
                   fVar9 - fVar10 * _DAT_00575490,fVar8,fVar7,fVar6);
      }
    }
    else {
      (**(code **)(*(int *)(param_1[1]._padding_ + 0x6c4) + 0x58))(param_5,param_6,10);
    }
  }
  (**(code **)(*(int *)(param_1[1]._padding_ + 0x6c4) + 0x4c))(param_5,param_6,param_8);
  this_00 = BuildAIModule::specificBuildListItem(param_1,param_4);
  if (this_00 != (BuildItem *)0x0) {
    BuildItem::setInProgress(this_00,0);
    uVar2 = __ftol();
    uVar3 = __ftol();
    iVar5 = BaseItem::typeID((BaseItem *)this_00);
    TribeInformationAIModule::removeLot
              ((TribeInformationAIModule *)(param_1[1]._padding_ + 0xcec),iVar5,uVar3,uVar2,unaff_SI
              );
    iVar5 = BaseItem::typeID((BaseItem *)this_00);
    if (iVar5 == 0x114) {
      *(undefined4 *)(param_1[1]._padding_ + 0x122b0) = 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d5567
// Address: 004d5567
undefined4 __fastcall
FUN_004d5567(BuildAIModule *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int param_6)
{
  char *pcVar1;
  int in_EAX;
  BuildItem *this;
  char cVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  pcVar1 = (char *)(unaff_EBX + 0x4d + param_2 * 2);
  *pcVar1 = *pcVar1 + (char)((uint)(in_EAX + -1) >> 8);
  cVar2 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  *(char *)(unaff_ESI + 0x53) = *(char *)(unaff_ESI + 0x53) + cVar2;
  pcVar1 = (char *)((int)&param_1->_padding_ + 3);
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  *(char *)(unaff_EBX + 0x560c2444) = *(char *)(unaff_EBX + 0x560c2444) + (char)param_1;
  this = BuildAIModule::specificBuildListItem(param_1,in_EAX + -1);
  if (this != (BuildItem *)0x0) {
    BuildItem::setInProgress(this,0);
    BuildItem::setBuilt(this,1);
    BaseItem::setGameID((BaseItem *)this,param_6);
    BuildItem::incrementNumberBuilds(this);
  }
  TribeMainDecisionAIModule::detask((TribeMainDecisionAIModule *)param_1[1]._padding_,param_4);
  TribeTacticalAIModule::updateNeededResources
            ((TribeTacticalAIModule *)(param_1[1]._padding_ + 0x1146c));
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d55f4
// Address: 004d55f4
// [HELPER] s_Canceling_training__WT__ld__for_: "Canceling training (WT=%ld) for item of type %d at building w/ gameID=%d."
// [HELPER] s___ERROR___Invalid_build_item_: "  ERROR!  Invalid build item."
// [HELPER] s___Setting_build_item___d_in_prog: "  Setting build item #%d in progress to FALSE."
undefined4 __thiscall
FUN_004d55f4(BuildAIModule *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            int param_5)
{
  AIModule *this;
  BuildItem *this_00;
  int iVar1;
  AIModule *this_01;
  AIModule *this_02;
  
  this = *(AIModule **)(*(int *)(param_1[1]._padding_ + 0xf0) + 0x3c);
  AIModule::logCommonHistory
            (this,(char *)param_1,s_Canceling_training__WT__ld__for_,(this->idValue)._padding_,
             param_3,param_4);
  this_00 = BuildAIModule::specificBuildListItem(param_1,param_5);
  if (this_00 != (BuildItem *)0x0) {
    iVar1 = BaseItem::uniqueID((BaseItem *)this_00);
    AIModule::logCommonHistory(this_02,(char *)param_1,s___Setting_build_item___d_in_prog,iVar1);
    BuildItem::setInProgress(this_00,0);
    (**(code **)(param_1->_padding_ + 0x40))();
    return 1;
  }
  AIModule::logCommonHistory(this_01,(char *)param_1,s___ERROR___Invalid_build_item_);
  (**(code **)(param_1->_padding_ + 0x40))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d56e8
// Address: 004d56e8
// [HELPER] s_Canceling_research__WT__ld__for_: "Canceling research (WT=%ld) for item of type %d at building w/ gameID=%d."
// [HELPER] s___ERROR___Invalid_build_item_: "  ERROR!  Invalid build item."
// [HELPER] s___Setting_build_item___d_in_prog: "  Setting build item #%d in progress to FALSE."
undefined4 __thiscall
FUN_004d56e8(BuildAIModule *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            int param_5)
{
  AIModule *this;
  BuildItem *this_00;
  int iVar1;
  AIModule *this_01;
  AIModule *this_02;
  
  this = *(AIModule **)(*(int *)(param_1[1]._padding_ + 0xf0) + 0x3c);
  AIModule::logCommonHistory
            (this,(char *)param_1,s_Canceling_research__WT__ld__for_,(this->idValue)._padding_,
             param_3,param_4);
  this_00 = BuildAIModule::specificBuildListItem(param_1,param_5);
  if (this_00 != (BuildItem *)0x0) {
    iVar1 = BaseItem::uniqueID((BaseItem *)this_00);
    AIModule::logCommonHistory(this_02,(char *)param_1,s___Setting_build_item___d_in_prog,iVar1);
    BuildItem::setInProgress(this_00,0);
    (**(code **)(param_1->_padding_ + 0x40))();
    return 1;
  }
  AIModule::logCommonHistory(this_01,(char *)param_1,s___ERROR___Invalid_build_item_);
  (**(code **)(param_1->_padding_ + 0x40))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d595e
// Address: 004d595e
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_004d5b73
// Address: 004d5b73
void __thiscall FUN_004d5b73(BuildAIModule *param_1,int param_2,int param_3,int param_4)
{
  BuildAIModule::insertItem
            (param_1,*(RGE_Player **)(param_1[1]._padding_ + 0xf0),param_2,1,6,param_3,1,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_004d5baa
// Address: 004d5baa
int __thiscall FUN_004d5baa(BuildAIModule *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  if ((param_3 == 0) && ((param_2 == 0x67 || (param_2 == 0x44)))) {
    iVar1 = BuildAIModule::numberInProgressItemsOfType(param_1,param_2,0);
    if (param_2 == 0x67) {
      iVar2 = TribeInformationAIModule::numberStoragePits
                        ((TribeInformationAIModule *)(param_1[1]._padding_ + 0xcec));
      return iVar1 + iVar2;
    }
    iVar2 = TribeInformationAIModule::numberGranaries
                      ((TribeInformationAIModule *)(param_1[1]._padding_ + 0xcec));
    return iVar1 + iVar2;
  }
  iVar1 = BuildAIModule::numberBuiltOrInProgressItemsOfType(param_1,param_2,param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_004d5c1d
// Address: 004d5c1d
undefined4 __thiscall FUN_004d5c1d(int param_1,int param_2,int param_3)
{
  int iVar1;
  BuildItem *this;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  if (this != (BuildItem *)(param_1 + 0xf0)) {
    while (this != (BuildItem *)0x0) {
      iVar1 = BuildItem::buildCategory(this);
      if ((((iVar1 == param_2) || (iVar1 = BuildItem::buildCategory(this), iVar1 == param_3)) &&
          (iVar1 = BuildItem::built(this), iVar1 == 0)) &&
         (iVar1 = BuildItem::inProgress(this), iVar1 == 0)) {
        return 0;
      }
      this = this->next;
      if (this == (BuildItem *)(param_1 + 0xf0)) {
        return 1;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d5c94
// Address: 004d5c94
bool __thiscall FUN_004d5c94(int param_1,int param_2,int param_3)
{
  uchar uVar1;
  
  if (param_3 == 1) {
    if (param_2 == 2) {
      uVar1 = TRIBE_Player::researchState
                        (*(TRIBE_Player **)(*(int *)(param_1 + 0x5bc) + 0x1256c),0x65);
    }
    else {
      uVar1 = (uchar)param_2;
    }
    if (param_2 == 3) {
      uVar1 = TRIBE_Player::researchState
                        (*(TRIBE_Player **)(*(int *)(param_1 + 0x5bc) + 0x1256c),0x66);
    }
    if (param_2 == 4) {
      uVar1 = TRIBE_Player::researchState
                        (*(TRIBE_Player **)(*(int *)(param_1 + 0x5bc) + 0x1256c),0x67);
      return uVar1 == '\x01';
    }
  }
  else {
    uVar1 = TRIBE_Player::researchState
                      (*(TRIBE_Player **)(*(int *)(param_1 + 0x5bc) + 0x1256c),param_2);
  }
  return uVar1 == '\x01';
}

// --------------------------------------------------

// Function: FUN_004d5d31
// Address: 004d5d31
void __fastcall FUN_004d5d31(int *param_1)
{
  code *pcVar1;
  BuildItem *this;
  int iVar2;
  int iVar3;
  int iVar4;
  
  pcVar1 = *(code **)(*param_1 + 0x48);
  iVar2 = (*pcVar1)(0x67,0);
  iVar3 = (*pcVar1)(0x44,0);
  for (this = (BuildItem *)param_1[0x57];
      (this != (BuildItem *)(param_1 + 0x3c) && (this != (BuildItem *)0x0)); this = this->next) {
    iVar4 = BuildItem::built(this);
    if ((((iVar4 != 1) && (iVar4 = BuildItem::inProgress(this), iVar4 != 1)) &&
        ((iVar2 < 1 || (iVar4 = BaseItem::typeID((BaseItem *)this), iVar4 != 0x67)))) &&
       ((iVar3 < 1 || (iVar4 = BaseItem::typeID((BaseItem *)this), iVar4 != 0x44)))) {
      BaseItem::setSkip((BaseItem *)this,0);
      BuildItem::setBuildAttempts(this,0);
      BuildItem::setSkipCycles(this,0);
      BuildItem::setPermanentSkip(this,'\0');
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d5ddb
// Address: 004d5ddb
BuildItem * __thiscall FUN_004d5ddb(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  BuildItem *this;
  
  this = *(BuildItem **)(param_1 + 0x15c);
  if (this != (BuildItem *)(param_1 + 0xf0)) {
    while (this != (BuildItem *)0x0) {
      iVar1 = BuildItem::built(this);
      if ((((iVar1 == 0) && (iVar1 = BuildItem::inProgress(this), iVar1 == 0)) &&
          (iVar1 = BaseItem::typeID((BaseItem *)this), iVar1 == param_2)) &&
         ((iVar1 = BuildItem::buildCategory(this), iVar1 == param_3 ||
          (iVar1 = BuildItem::buildCategory(this), iVar1 == param_4)))) {
        return this;
      }
      this = this->next;
      if (this == (BuildItem *)(param_1 + 0xf0)) {
        return (BuildItem *)0x0;
      }
    }
  }
  return (BuildItem *)0x0;
}

// --------------------------------------------------

// Function: FUN_004d5e5b
// Address: 004d5e5b
ConstructionAIModule * __thiscall
FUN_004d5e5b(ConstructionAIModule *param_1,void *param_2,int param_3)
{
  ConstructionAIModule::ConstructionAIModule(param_1,param_2,param_3);
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TribeConstructionAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d5e8a
// Address: 004d5e8a
TribeConstructionAIModule * __thiscall FUN_004d5e8a(TribeConstructionAIModule *param_1,byte param_2)
{
  TribeConstructionAIModule::~TribeConstructionAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d5eae
// Address: 004d5eae
ConstructionAIModule * __thiscall
FUN_004d5eae(ConstructionAIModule *param_1,int param_2,int param_3)
{
  ConstructionAIModule::ConstructionAIModule(param_1,param_2,param_3);
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TribeConstructionAIModule::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d5eda
// Address: 004d5eda
void __fastcall FUN_004d5eda(ConstructionAIModule *param_1)
{
  param_1->_padding_ = (int)&TribeConstructionAIModule::_vftable_;
  ConstructionAIModule::~ConstructionAIModule(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004d5eeb
// Address: 004d5eeb
void __thiscall FUN_004d5eeb(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x314) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004d5efd
// Address: 004d5efd
int __thiscall FUN_004d5efd(int param_1,BuildItem *param_2)
{
  ConstructionItem *this;
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  float fVar3;
  float fVar4;
  ConstructionItem CStack_8c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005602db;
  *unaff_FS_OFFSET = &uStack_c;
  if (((((float)UNK_005754fc._4_8_ < *(float *)(param_1 + 0x2fc)) &&
       ((float)UNK_005754fc._4_8_ < *(float *)(param_1 + 0x300))) &&
      (*(float *)(param_1 + 0x2fc) < (float)*(int *)(param_1 + 0x308))) &&
     (*(float *)(param_1 + 0x300) < (float)*(int *)(param_1 + 0x30c))) {
    iVar1 = BaseItem::typeID((BaseItem *)param_2);
    if (iVar1 == 0x2d) {
      iVar1 = 1;
      goto LAB_004d60b9;
    }
    if ((useInfluencePlacement != 1) && (*(int *)(param_1 + 0xf0) != 0)) {
      ConstructionItem::ConstructionItem(&CStack_8c);
      this = *(ConstructionItem **)(param_1 + 0x160);
      CStack_8c.next = &CStack_8c;
      CStack_8c.prev = &CStack_8c;
      uStack_4 = 0;
      for (; (this != (ConstructionItem *)(param_1 + 0xf4) && (this != (ConstructionItem *)0x0));
          this = this->next) {
        iVar1 = BaseItem::typeID((BaseItem *)this);
        iVar2 = BaseItem::typeID((BaseItem *)param_2);
        if (iVar1 == iVar2) {
LAB_004d604d:
          iVar1 = ConstructionItem::built(this);
          if ((iVar1 == 0) && (iVar1 = ConstructionItem::inProgress(this), iVar1 == 0)) {
            uStack_4 = 0xffffffff;
            ConstructionItem::~ConstructionItem(&CStack_8c);
            iVar1 = 1;
            goto LAB_004d60b9;
          }
        }
        else {
          fVar3 = BaseItem::xSize((BaseItem *)this);
          fVar4 = BaseItem::xSize((BaseItem *)param_2);
          if (fVar4 == fVar3) {
            fVar3 = BaseItem::ySize((BaseItem *)this);
            fVar4 = BaseItem::ySize((BaseItem *)param_2);
            if ((fVar4 == fVar3) && (iVar1 = BaseItem::typeID((BaseItem *)this), iVar1 == -1))
            goto LAB_004d604d;
          }
        }
      }
      uStack_4 = 0xffffffff;
      ConstructionItem::~ConstructionItem(&CStack_8c);
      iVar1 = 0;
      goto LAB_004d60b9;
    }
  }
  iVar1 = TribeInformationAIModule::influenceCanPlaceStructure
                    ((TribeInformationAIModule *)(*(int *)(param_1 + 0x314) + 0xcec),param_2);
LAB_004d60b9:
  *unaff_FS_OFFSET = uStack_c;
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_004d60d4
// Address: 004d60d4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

RGE_Static_Object * __thiscall
FUN_004d60d4(TribeConstructionAIModule *param_1,BuildItem *param_2,int param_3,
            PlacementState *param_4,ulong param_5)
{
  int iVar1;
  int *piVar2;
  uchar uVar3;
  int iVar4;
  ConstructionItem *pCVar5;
  ConstructionItem *pCVar6;
  RGE_Static_Object *this;
  RGE_Static_Object *this_00;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *unaff_FS_OFFSET;
  float fVar11;
  float fVar12;
  uchar uStack_b5;
  int iStack_ac;
  int iStack_a4;
  ConstructionItem CStack_8c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560325;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (((((float)param_1->_padding_ <= (float)UNK_005754fc._4_8_) ||
       ((float)param_1->_padding_ <= (float)UNK_005754fc._4_8_)) ||
      ((float)param_1->_padding_ <= (float)param_1->_padding_)) ||
     ((float)param_1->_padding_ <= (float)param_1->_padding_)) {
LAB_004d674d:
    this = (RGE_Static_Object *)
           TribeInformationAIModule::influencePlaceStructure
                     (&param_1->md->informationAI,param_2,param_3,-1,0.0,(char *)0x0,-1,-1,-1,-1,
                      param_4,param_5);
  }
  else {
    iVar4 = BaseItem::typeID((BaseItem *)param_2);
    if (iVar4 == 0x2d) {
      pCVar5 = TribeConstructionAIModule::placeDock(param_1,param_2);
      if (pCVar5 != (ConstructionItem *)0x0) {
        pCVar6 = (ConstructionItem *)operator_new(0x80);
        uStack_4 = 0;
        if (pCVar6 != (ConstructionItem *)0x0) {
          this = (RGE_Static_Object *)ConstructionItem::ConstructionItem(pCVar6,pCVar5);
          goto LAB_004d675e;
        }
      }
    }
    else {
      iVar4 = BaseItem::typeID((BaseItem *)param_2);
      if ((((((iVar4 == 0x67) || (iVar4 = BaseItem::typeID((BaseItem *)param_2), iVar4 == 0x44)) ||
            ((iVar4 = BaseItem::typeID((BaseItem *)param_2), iVar4 == 0x4f ||
             ((iVar4 = BaseItem::typeID((BaseItem *)param_2), iVar4 == 199 ||
              (iVar4 = BaseItem::typeID((BaseItem *)param_2), iVar4 == 0x45)))))) ||
           (iVar4 = BaseItem::typeID((BaseItem *)param_2), iVar4 == 0x48)) ||
          (((iVar4 = BaseItem::typeID((BaseItem *)param_2), iVar4 == 0x75 ||
            (iVar4 = BaseItem::typeID((BaseItem *)param_2), iVar4 == 0x9b)) ||
           (useInfluencePlacement == 1)))) || (param_1->_padding_ == 0)) goto LAB_004d674d;
      this = MainDecisionAIModule::object
                       ((MainDecisionAIModule *)param_1->md,-1,-1,4,-1,-1,-1,-1,-1,-1,-1);
      if (this == (RGE_Static_Object *)0x0) goto LAB_004d675e;
      this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_3);
      uStack_b5 = '\0';
      if (this_00 != (RGE_Static_Object *)0x0) {
        uStack_b5 = RGE_Static_Object::currentZone(this_00);
      }
      ConstructionItem::ConstructionItem(&CStack_8c);
      pCVar5 = (ConstructionItem *)param_1->_padding_;
      CStack_8c.next = &CStack_8c;
      CStack_8c.prev = &CStack_8c;
      uStack_4 = 1;
      iStack_a4 = 0;
      iStack_ac = -1;
      for (; (pCVar5 != (ConstructionItem *)&param_1->_padding_ &&
             (pCVar5 != (ConstructionItem *)0x0)); pCVar5 = pCVar5->next) {
        iVar4 = BaseItem::typeID((BaseItem *)param_2);
        iVar7 = BaseItem::typeID((BaseItem *)pCVar5);
        if ((iVar7 == iVar4) || (iVar4 = BaseItem::typeID((BaseItem *)pCVar5), iVar4 == -1)) {
          fVar11 = BaseItem::xSize((BaseItem *)pCVar5);
          fVar12 = BaseItem::xSize((BaseItem *)param_2);
          if (fVar12 == fVar11) {
            fVar11 = BaseItem::ySize((BaseItem *)pCVar5);
            fVar12 = BaseItem::ySize((BaseItem *)param_2);
            if (((fVar12 == fVar11) && (iVar4 = ConstructionItem::built(pCVar5), iVar4 != 1)) &&
               (iVar4 = ConstructionItem::inProgress(pCVar5), iVar4 != 1)) {
              BaseItem::x((BaseItem *)pCVar5);
              BaseItem::xSize((BaseItem *)pCVar5);
              iVar4 = __ftol();
              BaseItem::y((BaseItem *)pCVar5);
              BaseItem::ySize((BaseItem *)pCVar5);
              iVar7 = __ftol();
              BaseItem::xSize((BaseItem *)pCVar5);
              iVar8 = __ftol();
              iVar8 = iVar8 + iVar4;
              BaseItem::ySize((BaseItem *)pCVar5);
              iVar9 = __ftol();
              if ((((-1 < iVar4) && (-1 < iVar7)) && (iVar8 < param_1->_padding_)) &&
                 (iVar9 + iVar7 < param_1->_padding_)) {
                for (; iVar1 = iVar7, iVar4 < iVar8; iVar4 = iVar4 + 1) {
                  for (; iVar1 < iVar9 + iVar7; iVar1 = iVar1 + 1) {
                    if (((this_00 != (RGE_Static_Object *)0x0) &&
                        (uVar3 = RGE_Static_Object::lookupZone(this_00,iVar4,iVar1),
                        uVar3 != uStack_b5)) ||
                       (iVar10 = (**(code **)(this->_padding_ + 0x114))
                                           ((float)iVar4 - ram0x00575508,
                                            (float)iVar1 - ram0x00575508,1), iVar10 == 0))
                    goto LAB_004d6520;
                  }
                }
                pCVar6 = (ConstructionItem *)operator_new(0x80);
                uStack_4._0_1_ = 2;
                if (pCVar6 == (ConstructionItem *)0x0) {
                  pCVar6 = (ConstructionItem *)0x0;
                }
                else {
                  pCVar6 = (ConstructionItem *)ConstructionItem::ConstructionItem(pCVar6,pCVar5);
                }
                pCVar6->next = &CStack_8c;
                pCVar6->prev = CStack_8c.prev;
                uStack_4 = CONCAT31(uStack_4._1_3_,1);
                (CStack_8c.prev)->next = pCVar6;
                iStack_a4 = iStack_a4 + 1;
                CStack_8c.prev = pCVar6;
                if ((iStack_ac == -1) ||
                   (iVar4 = ConstructionItem::buildAttempts(pCVar5), iVar4 < iStack_ac)) {
                  iStack_ac = ConstructionItem::buildAttempts(pCVar5);
                }
              }
            }
          }
        }
LAB_004d6520:
      }
      if (((1 < iStack_ac) || (iStack_ac == -1)) &&
         (this = (RGE_Static_Object *)
                 TribeInformationAIModule::influencePlaceStructure
                           (&param_1->md->informationAI,param_2,param_3,-1,0.0,(char *)0x0,-1,-1,-1,
                            -1,param_4,param_5), this != (RGE_Static_Object *)0x0)) {
        uStack_4 = 0xffffffff;
        ConstructionItem::~ConstructionItem(&CStack_8c);
        goto LAB_004d675e;
      }
      pCVar5 = CStack_8c.next;
      if (iStack_a4 != 0) {
        pCVar6 = (CStack_8c.next)->next;
        iVar4 = BaseItem::typeID((BaseItem *)param_2);
        if (iVar4 == 0x48) {
          if (pCVar6 != &CStack_8c) {
            do {
              if (pCVar6 == (ConstructionItem *)0x0) break;
              iVar4 = ConstructionItem::buildAttempts(pCVar5);
              iVar7 = ConstructionItem::buildAttempts(pCVar6);
              if (iVar7 + 5 < iVar4) {
                pCVar5 = pCVar6;
              }
              pCVar6 = pCVar6->next;
            } while (pCVar6 != &CStack_8c);
          }
        }
        else if (pCVar6 != &CStack_8c) {
          do {
            if (pCVar6 == (ConstructionItem *)0x0) break;
            pCVar5 = TribeConstructionAIModule::compare(param_1,pCVar5,pCVar6);
            pCVar6 = pCVar6->next;
          } while (pCVar6 != &CStack_8c);
        }
        fVar11 = BaseItem::y((BaseItem *)pCVar5);
        fVar12 = BaseItem::x((BaseItem *)pCVar5);
        pCVar5 = ConstructionAIModule::lot((ConstructionAIModule *)param_1,fVar12,fVar11);
        ConstructionItem::setInProgress(pCVar5,1);
        ConstructionItem::incrementBuildAttempts(pCVar5);
        iVar4 = BaseItem::uniqueID((BaseItem *)param_2);
        BaseItem::setUniqueID((BaseItem *)pCVar5,iVar4);
        this = (RGE_Static_Object *)0x0;
        param_1->_padding_ = 0;
        pCVar6 = (ConstructionItem *)operator_new(0x80);
        uStack_4._0_1_ = 3;
        if (pCVar6 != (ConstructionItem *)0x0) {
          this = (RGE_Static_Object *)ConstructionItem::ConstructionItem(pCVar6,pCVar5);
        }
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        iVar4 = BaseItem::typeID((BaseItem *)param_2);
        BaseItem::setTypeID((BaseItem *)this,iVar4);
        pCVar5 = CStack_8c.next;
        if (CStack_8c.next != &CStack_8c) {
          do {
            if (pCVar5 == (ConstructionItem *)0x0) break;
            piVar2 = &pCVar5->_padding_;
            pCVar5 = pCVar5->next;
            (**(code **)*piVar2)(1);
          } while (pCVar5 != &CStack_8c);
        }
        uStack_4 = 0xffffffff;
        ConstructionItem::~ConstructionItem(&CStack_8c);
        goto LAB_004d675e;
      }
      param_1->_padding_ = 5;
      uStack_4 = 0xffffffff;
      ConstructionItem::~ConstructionItem(&CStack_8c);
    }
    this = (RGE_Static_Object *)0x0;
  }
LAB_004d675e:
  *unaff_FS_OFFSET = uStack_c;
  return this;
}

// --------------------------------------------------

// Function: FUN_004d6779
// Address: 004d6779
ConstructionItem * __thiscall FUN_004d6779(int param_1,BuildItem *param_2)
{
  ConstructionItem *pCVar1;
  ConstructionItem *pCVar2;
  
  pCVar2 = TribeInformationAIModule::placeDock
                     ((TribeInformationAIModule *)(*(int *)(param_1 + 0x314) + 0xcec),param_2,
                      *(float *)(param_1 + 0x2fc),*(float *)(param_1 + 0x300),1,2);
  if (pCVar2 != (ConstructionItem *)0x0) {
    pCVar2->next = (ConstructionItem *)(param_1 + 0x178);
    pCVar1 = *(ConstructionItem **)(param_1 + 0x1e8);
    pCVar2->prev = pCVar1;
    pCVar1->next = pCVar2;
    *(ConstructionItem **)(param_1 + 0x1e8) = pCVar2;
    *(int *)(param_1 + 0x174) = *(int *)(param_1 + 0x174) + 1;
    *(undefined4 *)(param_1 + 0x310) = 0;
    return pCVar2;
  }
  *(undefined4 *)(param_1 + 0x310) = 5;
  return (ConstructionItem *)0x0;
}

// --------------------------------------------------

// Function: FUN_004d67f5
// Address: 004d67f5
void __thiscall FUN_004d67f5(int param_1,int param_2,int param_3)
{
  ConstructionItem *this;
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  float fVar4;
  uchar uVar5;
  
  this = *(ConstructionItem **)(param_1 + 0x160);
  while( true ) {
    if ((this == (ConstructionItem *)(param_1 + 0xf4)) || (this == (ConstructionItem *)0x0)) {
      uVar5 = '\x01';
      uVar1 = __ftol();
      uVar2 = __ftol();
      TribeInformationAIModule::storeLot
                ((TribeInformationAIModule *)(*(int *)(param_1 + 0x314) + 0xcec),
                 (int)*(short *)(*(int *)(param_2 + 8) + 0x10),uVar2,uVar1,uVar5);
      return;
    }
    iVar3 = BaseItem::typeID((BaseItem *)this);
    if ((iVar3 == *(short *)(*(int *)(param_2 + 8) + 0x10)) &&
       ((fVar4 = BaseItem::x((BaseItem *)this), fVar4 == *(float *)(param_2 + 0x38) &&
        (fVar4 = BaseItem::y((BaseItem *)this), fVar4 == *(float *)(param_2 + 0x3c))))) break;
    this = this->next;
  }
  ConstructionItem::setBuilt(this,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004d68c9
// Address: 004d68c9
void __fastcall FUN_004d68c9(undefined4 *param_1)
{
  *param_1 = &CombatRuleSystem::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_004d68d9
// Address: 004d68d9
CombatRuleSystem * __thiscall FUN_004d68d9(CombatRuleSystem *param_1,byte param_2)
{
  CombatRuleSystem::~CombatRuleSystem(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d68fe
// Address: 004d68fe
void __fastcall FUN_004d68fe(undefined4 *param_1)
{
  *param_1 = &CombatRuleSystem::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_004d6907
// Address: 004d6907
// [HELPER] s_NONE: "NONE"
// [HELPER] s__c_c: "%c%c"
// [HELPER] s__d__d__d_: "%d %d %d "
// [HELPER] s__s: "%s"
// [HELPER] s__tmp: ".tmp"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_004d6907(int param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  bool bVar7;
  char cStack_10e;
  char cStack_10d;
  int iStack_10c;
  undefined1 auStack_108 [4];
  int iStack_104;
  undefined1 auStack_100 [256];
  
  pbVar5 = &s_NONE;
  pbVar2 = param_2;
  do {
    bVar1 = *pbVar2;
    bVar7 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_004d694e:
      iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_004d6953;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar7 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_004d694e;
    pbVar2 = pbVar2 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_004d6953:
  if ((iVar3 != 0) && (param_2 != (byte *)0x0)) {
    sprintf(auStack_100,s__s,param_2);
    iVar3 = fopen(auStack_100,s_r);
    if (iVar3 != 0) {
      puVar6 = (undefined4 *)(param_1 + 4);
      for (iVar4 = 0x271; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0x32323232;
        puVar6 = puVar6 + 1;
      }
      iVar4 = fgets(auStack_100,0x100,iVar3);
      while (iVar4 != 0) {
        sscanf(auStack_100,s__c_c,&cStack_10e,&cStack_10d);
        if ((((cStack_10e != '/') || (cStack_10d != '/')) &&
            (sscanf(auStack_100,s__d__d__d_,&iStack_10c,&iStack_104,auStack_108), -1 < iStack_10c))
           && (iStack_10c < 0x32)) {
          *(undefined1 *)(iStack_104 + iStack_10c * 0x32 + 4 + param_1) = auStack_108[0];
        }
        iVar4 = fgets(auStack_100,0x100,iVar3);
      }
      fclose(iVar3);
      iVar3 = strstr(param_2,s__tmp);
      if (iVar3 != 0) {
        __unlink(param_2);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d6a92
// Address: 004d6a92
undefined4 FUN_004d6a92(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004d6aa6
// Address: 004d6aa6
undefined4 FUN_004d6aa6(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004d6ab6
// Address: 004d6ab6
void FUN_004d6ab6(void)
{
  _E9();
  _E11();
  return;
}

// --------------------------------------------------

// Function: $E12
// Address: 004d6ac0
void _E12(void)
{
  _E9();
  _E11();
  return;
}

// --------------------------------------------------

// Function: FUN_004d6aca
// Address: 004d6aca
void FUN_004d6aca(void)
{
  InfluenceMap::InfluenceMap(&iMap,0xfe,0xfe,'\0');
  return;
}

// --------------------------------------------------

// Function: $E9
// Address: 004d6ad0
void _E9(void)
{
  InfluenceMap::InfluenceMap(&iMap,0xfe,0xfe,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_004d6ae7
// Address: 004d6ae7
void FUN_004d6ae7(void)
{
  atexit(_E10);
  return;
}

// --------------------------------------------------

// Function: $E11
// Address: 004d6af0
void _E11(void)
{
  atexit(_E10);
  return;
}

// --------------------------------------------------

// Function: FUN_004d6afe
// Address: 004d6afe
void FUN_004d6afe(void)
{
  InfluenceMap::~InfluenceMap(&iMap);
  return;
}

// --------------------------------------------------

// Function: $E10
// Address: 004d6b00
void _E10(void)
{
  InfluenceMap::~InfluenceMap(&iMap);
  return;
}

// --------------------------------------------------

// Function: FUN_004d6b0a
// Address: 004d6b0a
void FUN_004d6b0a(void)
{
  _E14();
  _E16();
  return;
}

// --------------------------------------------------

// Function: $E17
// Address: 004d6b10
void _E17(void)
{
  _E14();
  _E16();
  return;
}

// --------------------------------------------------

// Function: FUN_004d6b1a
// Address: 004d6b1a
void FUN_004d6b1a(void)
{
  InfluenceMap::InfluenceMap(&losMap,0x32,0x32,'\0');
  return;
}

// --------------------------------------------------

// Function: $E14
// Address: 004d6b20
void _E14(void)
{
  InfluenceMap::InfluenceMap(&losMap,0x32,0x32,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_004d6b31
// Address: 004d6b31
void FUN_004d6b31(void)
{
  atexit(_E15);
  return;
}

// --------------------------------------------------

// Function: $E16
// Address: 004d6b40
void _E16(void)
{
  atexit(_E15);
  return;
}

// --------------------------------------------------

// Function: FUN_004d6b4e
// Address: 004d6b4e
void FUN_004d6b4e(void)
{
  InfluenceMap::~InfluenceMap(&losMap);
  return;
}

// --------------------------------------------------

// Function: $E15
// Address: 004d6b50
void _E15(void)
{
  InfluenceMap::~InfluenceMap(&losMap);
  return;
}

// --------------------------------------------------

// Function: FUN_004d6b5a
// Address: 004d6b5a
void FUN_004d6b5a(void)
{
  _E19();
  _E21();
  return;
}

// --------------------------------------------------

// Function: $E22
// Address: 004d6b60
void _E22(void)
{
  _E19();
  _E21();
  return;
}

// --------------------------------------------------

// Function: FUN_004d6b6a
// Address: 004d6b6a
void FUN_004d6b6a(void)
{
  InfluenceMap::InfluenceMap(&attackMap,0x32,0x32,'\0');
  return;
}

// --------------------------------------------------

// Function: $E19
// Address: 004d6b70
void _E19(void)
{
  InfluenceMap::InfluenceMap(&attackMap,0x32,0x32,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_004d6b81
// Address: 004d6b81
void FUN_004d6b81(void)
{
  atexit(_E20);
  return;
}

// --------------------------------------------------

// Function: $E21
// Address: 004d6b90
void _E21(void)
{
  atexit(_E20);
  return;
}

// --------------------------------------------------

// Function: FUN_004d6b9e
// Address: 004d6b9e
void FUN_004d6b9e(void)
{
  InfluenceMap::~InfluenceMap(&attackMap);
  return;
}

// --------------------------------------------------

// Function: $E20
// Address: 004d6ba0
void _E20(void)
{
  InfluenceMap::~InfluenceMap(&attackMap);
  return;
}

// --------------------------------------------------

// Function: FUN_004d6baa
// Address: 004d6baa
// [HELPER] s_learn_Default_uh: "learn\Default.uh"
InformationAIModule * __thiscall
FUN_004d6baa(InformationAIModule *param_1,void *param_2,int param_3)
{
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005603a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  InformationAIModule::InformationAIModule(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)&param_1[1].field_0x4 = 0;
  *(undefined4 *)&param_1[1].field_0x8 = 0;
  *(undefined4 *)&param_1[1].field_0xc = 0;
  *(undefined4 *)&param_1[1].field_0x10 = 0;
  *(undefined4 *)&param_1[1].field_0x14 = 0xffffffff;
  *(undefined4 *)&param_1[1].field_0x18 = 0xffffffff;
  *(undefined4 *)&param_1[1].field_0x1c = 0;
  *(undefined4 *)&param_1[1].field_0x20 = 500;
  *(undefined4 *)&param_1[1].field_0x28 = 0;
  *(undefined4 *)&param_1[1].field_0x2c = 0;
  *(undefined4 *)&param_1[1].field_0x30 = 0;
  *(undefined4 *)&param_1[1].field_0x34 = 0;
  *(undefined4 *)&param_1[1].field_0x38 = 0;
  *(undefined4 *)&param_1[1].field_0x3c = 0;
  *(undefined4 *)&param_1[1].field_0x40 = 0;
  *(undefined4 *)&param_1[1].field_0x44 = 0;
  *(undefined4 *)&param_1[1].field_0x48 = 0;
  *(undefined4 *)&param_1[1].field_0x4c = 0;
  *(undefined4 *)&param_1[1].field_0x50 = 0;
  *(undefined4 *)&param_1[1].field_0x54 = 0;
  *(undefined4 *)&param_1[1].field_0x58 = 0;
  *(undefined4 *)&param_1[1].field_0x5c = 0;
  *(undefined4 *)&param_1[1].field_0x60 = 0;
  *(undefined4 *)&param_1[1].field_0x64 = 0;
  uStack_4._0_1_ = 5;
  uStack_4._1_3_ = 0;
  InfluenceMap::InfluenceMap((InfluenceMap *)&param_1[1].field_0x68,0xfe,0xfe,0xff);
  *(undefined4 *)&param_1[1].field_0x90 = 0;
  *(undefined4 *)&param_1[1].field_0x94 = 0;
  *(undefined4 *)&param_1[1].field_0x98 = 0;
  *(undefined4 *)&param_1[1].field_0x9c = 0;
  *(undefined4 *)&param_1[1].field_0xa0 = 0;
  *(undefined4 *)&param_1[1].field_0xa4 = 0;
  *(undefined4 *)&param_1[1].field_0xa8 = 0;
  *(undefined4 *)&param_1[1].field_0xac = 0;
  uVar5 = 0xffffffff;
  *(undefined4 *)&param_1[2].field_0x14 = 200;
  *(undefined4 *)&param_1[2].field_0x1c = 0x19;
  *(undefined4 *)&param_1[2].field_0x24 = 0;
  *(undefined4 *)&param_1[5].field_0xb0 = 0;
  *(undefined ***)param_1 = &TribeInformationAIModule::_vftable_;
  pcVar8 = &s_learn_Default_uh;
  do {
    pcVar9 = pcVar8;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  uStack_4 = CONCAT31(uStack_4._1_3_,8);
  pcVar8 = pcVar9 + -uVar5;
  pcVar9 = &param_1[0x110].field_0x90;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  pvVar2 = operator_new(0x10);
  *(void **)&param_1[5].field_0x18 = pvVar2;
  pvVar2 = operator_new(0x10);
  *(void **)&param_1[5].field_0x1c = pvVar2;
  iVar7 = 0;
  do {
    iVar3 = iVar7 + 4;
    *(undefined4 *)(iVar7 + *(int *)&param_1[5].field_0x1c) = 0;
    *(undefined4 *)(iVar7 + *(int *)&param_1[5].field_0x18) = 0;
    iVar7 = iVar3;
  } while (iVar3 < 0x10);
  puVar4 = (undefined4 *)&param_1[0x110].field_0x64;
  for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)&param_1[5].field_0xb4;
  for (iVar7 = 16000; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)&param_1[5].field_0x60;
  iVar7 = 4;
  do {
    puVar4[-4] = 0;
    *puVar4 = 1;
    puVar4[4] = 1;
    puVar4[8] = 1;
    puVar4 = puVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar4 = (undefined4 *)&param_1[5].field_0xa0;
  iVar7 = 4;
  do {
    puVar4[-4] = 0xffffffff;
    *puVar4 = 0xffffffff;
    puVar4 = puVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  pvVar2 = operator_new(*(int *)&param_1[1].field_0x20 * 0x24);
  *(void **)&param_1[1].field_0x24 = pvVar2;
  if ((pvVar2 != (void *)0x0) && (iVar7 = 0, 0 < *(int *)&param_1[1].field_0x20)) {
    iVar3 = 0;
    do {
      iVar7 = iVar7 + 1;
      *(undefined4 *)(iVar3 + *(int *)&param_1[1].field_0x24) = 0xffffffff;
      *(undefined2 *)(iVar3 + 4 + *(int *)&param_1[1].field_0x24) = 0xffff;
      *(undefined2 *)(iVar3 + 6 + *(int *)&param_1[1].field_0x24) = 0xffff;
      *(undefined1 *)(iVar3 + 8 + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined1 *)(iVar3 + 9 + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined1 *)(iVar3 + 10 + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined1 *)(iVar3 + 0xb + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined2 *)(iVar3 + 0xc + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined4 *)(iVar3 + 0x10 + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined1 *)(iVar3 + 0x14 + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined4 *)(iVar3 + 0x18 + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined4 *)(iVar3 + 0x1c + *(int *)&param_1[1].field_0x24) = 0;
      *(undefined4 *)(iVar3 + 0x20 + *(int *)&param_1[1].field_0x24) = 0;
      iVar3 = iVar3 + 0x24;
    } while (iVar7 < *(int *)&param_1[1].field_0x20);
  }
  pvVar2 = operator_new(*(int *)&param_1[2].field_0x14 << 3);
  *(void **)&param_1[2].field_0x18 = pvVar2;
  if ((pvVar2 != (void *)0x0) && (iVar7 = 0, 0 < *(int *)&param_1[2].field_0x14)) {
    do {
      iVar7 = iVar7 + 1;
      *(undefined4 *)(*(int *)&param_1[2].field_0x18 + -8 + iVar7 * 8) = 0xffffffff;
      *(undefined1 *)(*(int *)&param_1[2].field_0x18 + -3 + iVar7 * 8) = 0;
      *(undefined1 *)(*(int *)&param_1[2].field_0x18 + -2 + iVar7 * 8) = 0;
      *(undefined1 *)(*(int *)&param_1[2].field_0x18 + -4 + iVar7 * 8) = 0;
    } while (iVar7 < *(int *)&param_1[2].field_0x14);
  }
  pvVar2 = operator_new(*(int *)&param_1[2].field_0x1c * 0x18);
  *(void **)&param_1[2].field_0x20 = pvVar2;
  if ((pvVar2 != (void *)0x0) && (iVar7 = 0, 0 < *(int *)&param_1[2].field_0x1c)) {
    iVar3 = 0;
    do {
      iVar7 = iVar7 + 1;
      *(undefined4 *)(iVar3 + *(int *)&param_1[2].field_0x20) = 0xffffffff;
      *(undefined4 *)(iVar3 + *(int *)&param_1[2].field_0x20) = 0xffffffff;
      *(undefined1 *)(iVar3 + 5 + *(int *)&param_1[2].field_0x20) = 0;
      *(undefined1 *)(iVar3 + 6 + *(int *)&param_1[2].field_0x20) = 0;
      *(undefined1 *)(iVar3 + 7 + *(int *)&param_1[2].field_0x20) = 0;
      *(undefined1 *)(iVar3 + 8 + *(int *)&param_1[2].field_0x20) = 0;
      *(undefined1 *)(iVar3 + 9 + *(int *)&param_1[2].field_0x20) = 0xff;
      *(undefined1 *)(iVar3 + 10 + *(int *)&param_1[2].field_0x20) = 0xff;
      *(undefined2 *)(iVar3 + 0xc + *(int *)&param_1[2].field_0x20) = 0;
      *(undefined1 *)(iVar3 + 0xe + *(int *)&param_1[2].field_0x20) = 0;
      *(undefined4 *)(iVar3 + 0x14 + *(int *)&param_1[2].field_0x20) = 0xffffffff;
      iVar3 = iVar3 + 0x18;
    } while (iVar7 < *(int *)&param_1[2].field_0x1c);
  }
  puVar4 = (undefined4 *)&param_1[1].field_0xc8;
  *(undefined4 *)&param_1[1].field_0xb0 = 0xffffffff;
  *(undefined4 *)&param_1[1].field_0xb4 = 0xffffffff;
  *(undefined4 *)&param_1[1].field_0xb8 = 0xffffffff;
  *(undefined4 *)&param_1[1].field_0xbc = 0xffffffff;
  *(undefined4 *)&param_1[1].field_0xc0 = 0xffffffff;
  iVar7 = 4;
  do {
    puVar4[-1] = 0xffffffff;
    *puVar4 = 0xffffffff;
    puVar4[7] = 0xffffffff;
    puVar4[8] = 0xffffffff;
    puVar4 = puVar4 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar3 = 4;
  puVar4 = (undefined4 *)&param_1[3].field_0x38;
  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  puVar4 = (undefined4 *)&param_1[4].field_0x50;
  do {
    iVar7 = 4;
    do {
      puVar4[-2] = 0;
      puVar4[-1] = 0;
      *puVar4 = 0;
      puVar4 = puVar4 + 3;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar4 = (undefined4 *)&param_1[5].field_0x40;
  iVar7 = 4;
  do {
    puVar4[-8] = 0;
    *puVar4 = 0;
    puVar4[-4] = 0;
    puVar4 = puVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d704e
// Address: 004d704e
TribeInformationAIModule * __thiscall FUN_004d704e(TribeInformationAIModule *param_1,byte param_2)
{
  TribeInformationAIModule::~TribeInformationAIModule(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d706e
// Address: 004d706e
// [HELPER] s_: ""
// [HELPER] s_learn_Default_uh: "learn\Default.uh"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TribeInformationAIModule * __thiscall
FUN_004d706e(TribeInformationAIModule *param_1,int param_2,int param_3)
{
  char cVar1;
  int **ppiVar2;
  int *piVar3;
  int iVar4;
  int (*paiVar5) [4];
  ObjectMemory *pOVar6;
  BuildingLot *pBVar7;
  AttackMemory *pAVar8;
  int iVar9;
  int iVar10;
  ResourceMemory *pRVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  XYPoint *pXVar15;
  char *pcVar16;
  char *pcVar17;
  undefined4 *unaff_FS_OFFSET;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  TribeInformationAIModule *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560438;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTStack_10 = param_1;
  InformationAIModule::InformationAIModule((InformationAIModule *)param_1,(void *)0x0,param_2);
  (param_1->farmsTaskedThisUpdate).value = (int *)0x0;
  (param_1->farmsTaskedThisUpdate).numberValue = 0;
  (param_1->farmsTaskedThisUpdate).desiredNumberValue = 0;
  (param_1->farmsTaskedThisUpdate).maximumSizeValue = 0;
  param_1->md = (TribeMainDecisionAIModule *)0x0;
  (param_1->importantObjects).value = (int *)0x0;
  (param_1->importantObjects).numberValue = 0;
  (param_1->importantObjects).desiredNumberValue = 0;
  (param_1->importantObjects).maximumSizeValue = 0;
  (param_1->importantUnits).value = (int *)0x0;
  (param_1->importantUnits).numberValue = 0;
  (param_1->importantUnits).desiredNumberValue = 0;
  (param_1->importantUnits).maximumSizeValue = 0;
  (param_1->importantMiscs).value = (int *)0x0;
  (param_1->importantMiscs).numberValue = 0;
  (param_1->importantMiscs).desiredNumberValue = 0;
  (param_1->importantMiscs).maximumSizeValue = 0;
  (param_1->itemsToDefend).value = (int *)0x0;
  (param_1->itemsToDefend).numberValue = 0;
  (param_1->itemsToDefend).desiredNumberValue = 0;
  (param_1->itemsToDefend).maximumSizeValue = 0;
  uStack_4._0_1_ = 5;
  uStack_4._1_3_ = 0;
  InfluenceMap::InfluenceMap(&param_1->pathMap,0xfe,0xfe,0xff);
  (param_1->playerObjects).value = (int *)0x0;
  (param_1->playerObjects).numberValue = 0;
  (param_1->playerObjects).desiredNumberValue = 0;
  (param_1->playerObjects).maximumSizeValue = 0;
  (param_1->playerBuildings).value = (int *)0x0;
  (param_1->playerBuildings).numberValue = 0;
  (param_1->playerBuildings).desiredNumberValue = 0;
  (param_1->playerBuildings).maximumSizeValue = 0;
  uVar12 = 0xffffffff;
  param_1->saveLearnInformationValue = 0;
  param_1->numberFoundForestTilesValue = 0;
  param_1->_padding_ = (int)&TribeInformationAIModule::_vftable_;
  pcVar16 = &s_learn_Default_uh;
  do {
    pcVar17 = pcVar16;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar17 = pcVar16 + 1;
    cVar1 = *pcVar16;
    pcVar16 = pcVar17;
  } while (cVar1 != '\0');
  uVar12 = ~uVar12;
  pcVar16 = pcVar17 + -uVar12;
  pcVar17 = param_1->unitHistoryFilename;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar16;
    pcVar16 = pcVar16 + 4;
    pcVar17 = pcVar17 + 4;
  }
  uStack_4 = CONCAT31(uStack_4._1_3_,8);
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *pcVar17 = *pcVar16;
    pcVar16 = pcVar16 + 1;
    pcVar17 = pcVar17 + 1;
  }
  ppiVar2 = (int **)operator_new(0x10);
  param_1->resourceTypesValue = ppiVar2;
  piVar3 = (int *)operator_new(0x10);
  param_1->numberResourceTypesValue = piVar3;
  iVar14 = 0;
  do {
    iVar4 = iVar14 + 4;
    *(undefined4 *)(iVar14 + (int)param_1->numberResourceTypesValue) = 0;
    *(undefined4 *)(iVar14 + (int)param_1->resourceTypesValue) = 0;
    iVar14 = iVar4;
  } while (iVar4 < 0x10);
  piVar3 = param_1->unitHistory;
  for (iVar14 = 0xb; iVar14 != 0; iVar14 = iVar14 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  piVar3 = param_1->playHistory;
  for (iVar14 = 16000; iVar14 != 0; iVar14 = iVar14 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  paiVar5 = param_1->dropsitesByAge + 1;
  iVar14 = 4;
  do {
    paiVar5[-1][0] = 0;
    (*paiVar5)[0] = 1;
    paiVar5[1][0] = 1;
    paiVar5[2][0] = 1;
    paiVar5 = (int (*) [4])(*paiVar5 + 1);
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  piVar3 = param_1->closestDropsiteResourceID;
  iVar14 = 4;
  do {
    piVar3[-4] = -1;
    *piVar3 = -1;
    piVar3 = piVar3 + 1;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  iVar14 = 0;
  do {
    rge_read(param_3,&param_2,4);
    iVar4 = 0;
    if (0 < param_2) {
      do {
        rge_read(param_3,&iStack_14,4);
        TribeInformationAIModule::addResourceType(param_1,iVar14,iStack_14);
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_2);
    }
    iVar4 = param_3;
    iVar14 = iVar14 + 1;
  } while (iVar14 < 4);
  rge_read(param_3,&param_1->mapXSizeValue,4);
  rge_read(iVar4,&param_1->mapYSizeValue,4);
  rge_read(iVar4,&param_1->lastUpdateRowValue,4);
  rge_read(iVar4,&param_1->maxImportantObjectMemory,4);
  pOVar6 = (ObjectMemory *)operator_new(param_1->maxImportantObjectMemory * 0x24);
  param_1->importantObjectMemory = pOVar6;
  if (pOVar6 != (ObjectMemory *)0x0) {
    iVar14 = 0;
    if (0 < param_1->maxImportantObjectMemory) {
      iVar4 = 0;
      do {
        rge_read(param_3,(void *)((int)&param_1->importantObjectMemory->id + iVar4),0x24);
        iVar14 = iVar14 + 1;
        iVar4 = iVar4 + 0x24;
      } while (iVar14 < param_1->maxImportantObjectMemory);
    }
    piVar3 = &param_1->maxBuildingLots;
    rge_read(param_3,piVar3,4);
    pBVar7 = (BuildingLot *)operator_new(*piVar3 << 3);
    param_1->buildingLots = pBVar7;
    if (pBVar7 != (BuildingLot *)0x0) {
      iVar14 = 0;
      if (0 < *piVar3) {
        do {
          rge_read(param_3,param_1->buildingLots + iVar14,8);
          iVar14 = iVar14 + 1;
        } while (iVar14 < *piVar3);
      }
      piVar3 = &param_1->maxAttackMemories;
      rge_read(param_3,piVar3,4);
      pAVar8 = (AttackMemory *)operator_new(*piVar3 * 0x18);
      param_1->attackMemories = pAVar8;
      if (pAVar8 != (AttackMemory *)0x0) {
        iVar14 = 0;
        if (0 < *piVar3) {
          iVar4 = 0;
          do {
            rge_read(param_3,(void *)((int)&param_1->attackMemories->id + iVar4),0x18);
            iVar14 = iVar14 + 1;
            iVar4 = iVar4 + 0x18;
          } while (iVar14 < *piVar3);
        }
        rge_read(param_3,&iStack_1c,4);
        param_2 = 0;
        if (0 < iStack_1c) {
          do {
            rge_read(param_3,&iStack_18,4);
            iVar4 = iStack_18;
            iVar14 = (param_1->importantObjects).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((param_1->importantObjects).maximumSizeValue <= iVar9) break;
                if ((param_1->importantObjects).value[iVar9] == iStack_18) goto LAB_004d74e2;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((param_1->importantObjects).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (param_1->importantObjects).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (param_1->importantObjects).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (param_1->importantObjects).maximumSizeValue);
                }
                operator_delete((param_1->importantObjects).value);
                (param_1->importantObjects).value = piVar3;
                (param_1->importantObjects).maximumSizeValue = iVar14;
              }
            }
            (param_1->importantObjects).value[(param_1->importantObjects).numberValue] = iVar4;
            (param_1->importantObjects).numberValue = (param_1->importantObjects).numberValue + 1;
LAB_004d74e2:
            param_2 = param_2 + 1;
          } while (param_2 < iStack_1c);
        }
        rge_read(param_3,&iStack_1c,4);
        param_2 = 0;
        if (0 < iStack_1c) {
          do {
            rge_read(param_3,&iStack_18,4);
            iVar4 = iStack_18;
            iVar14 = (param_1->importantUnits).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((param_1->importantUnits).maximumSizeValue <= iVar9) break;
                if ((param_1->importantUnits).value[iVar9] == iStack_18) goto LAB_004d75e7;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((param_1->importantUnits).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (param_1->importantUnits).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (param_1->importantUnits).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (param_1->importantUnits).maximumSizeValue);
                }
                operator_delete((param_1->importantUnits).value);
                (param_1->importantUnits).value = piVar3;
                (param_1->importantUnits).maximumSizeValue = iVar14;
              }
            }
            (param_1->importantUnits).value[(param_1->importantUnits).numberValue] = iVar4;
            (param_1->importantUnits).numberValue = (param_1->importantUnits).numberValue + 1;
LAB_004d75e7:
            param_2 = param_2 + 1;
          } while (param_2 < iStack_1c);
        }
        rge_read(param_3,&iStack_1c,4);
        param_2 = 0;
        if (0 < iStack_1c) {
          do {
            rge_read(param_3,&iStack_18,4);
            iVar4 = iStack_18;
            iVar14 = (param_1->importantMiscs).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((param_1->importantMiscs).maximumSizeValue <= iVar9) break;
                if ((param_1->importantMiscs).value[iVar9] == iStack_18) goto LAB_004d76ec;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((param_1->importantMiscs).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (param_1->importantMiscs).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (param_1->importantMiscs).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (param_1->importantMiscs).maximumSizeValue);
                }
                operator_delete((param_1->importantMiscs).value);
                (param_1->importantMiscs).value = piVar3;
                (param_1->importantMiscs).maximumSizeValue = iVar14;
              }
            }
            (param_1->importantMiscs).value[(param_1->importantMiscs).numberValue] = iVar4;
            (param_1->importantMiscs).numberValue = (param_1->importantMiscs).numberValue + 1;
LAB_004d76ec:
            param_2 = param_2 + 1;
          } while (param_2 < iStack_1c);
        }
        rge_read(param_3,&iStack_1c,4);
        param_2 = 0;
        if (0 < iStack_1c) {
          do {
            rge_read(param_3,&iStack_18,4);
            iVar4 = iStack_18;
            iVar14 = (param_1->itemsToDefend).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((param_1->itemsToDefend).maximumSizeValue <= iVar9) break;
                if ((param_1->itemsToDefend).value[iVar9] == iStack_18) goto LAB_004d77f1;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((param_1->itemsToDefend).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (param_1->itemsToDefend).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (param_1->itemsToDefend).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (param_1->itemsToDefend).maximumSizeValue);
                }
                operator_delete((param_1->itemsToDefend).value);
                (param_1->itemsToDefend).value = piVar3;
                (param_1->itemsToDefend).maximumSizeValue = iVar14;
              }
            }
            (param_1->itemsToDefend).value[(param_1->itemsToDefend).numberValue] = iVar4;
            (param_1->itemsToDefend).numberValue = (param_1->itemsToDefend).numberValue + 1;
LAB_004d77f1:
            param_2 = param_2 + 1;
          } while (param_2 < iStack_1c);
        }
        rge_read(param_3,&iStack_1c,4);
        param_2 = 0;
        if (0 < iStack_1c) {
          do {
            rge_read(param_3,&iStack_18,4);
            iVar4 = iStack_18;
            iVar14 = (param_1->playerBuildings).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((param_1->playerBuildings).maximumSizeValue <= iVar9) break;
                if ((param_1->playerBuildings).value[iVar9] == iStack_18) goto LAB_004d78f6;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((param_1->playerBuildings).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (param_1->playerBuildings).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (param_1->playerBuildings).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (param_1->playerBuildings).maximumSizeValue);
                }
                operator_delete((param_1->playerBuildings).value);
                (param_1->playerBuildings).value = piVar3;
                (param_1->playerBuildings).maximumSizeValue = iVar14;
              }
            }
            (param_1->playerBuildings).value[(param_1->playerBuildings).numberValue] = iVar4;
            (param_1->playerBuildings).numberValue = (param_1->playerBuildings).numberValue + 1;
LAB_004d78f6:
            param_2 = param_2 + 1;
          } while (param_2 < iStack_1c);
        }
        rge_read(param_3,&iStack_1c,4);
        param_2 = 0;
        if (0 < iStack_1c) {
          do {
            rge_read(param_3,&iStack_18,4);
            iVar4 = iStack_18;
            iVar14 = (param_1->playerObjects).numberValue;
            iVar9 = 0;
            if (0 < iVar14) {
              do {
                if ((param_1->playerObjects).maximumSizeValue <= iVar9) break;
                if ((param_1->playerObjects).value[iVar9] == iStack_18) goto LAB_004d79fb;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar14);
            }
            if ((param_1->playerObjects).maximumSizeValue + -1 < iVar14) {
              iVar14 = iVar14 + 1;
              piVar3 = (int *)operator_new(iVar14 * 4);
              if (piVar3 != (int *)0x0) {
                iVar9 = 0;
                if (0 < (param_1->playerObjects).maximumSizeValue) {
                  do {
                    if (iVar14 <= iVar9) break;
                    iVar10 = iVar9 + 1;
                    piVar3[iVar9] = (param_1->playerObjects).value[iVar9];
                    iVar9 = iVar10;
                  } while (iVar10 < (param_1->playerObjects).maximumSizeValue);
                }
                operator_delete((param_1->playerObjects).value);
                (param_1->playerObjects).value = piVar3;
                (param_1->playerObjects).maximumSizeValue = iVar14;
              }
            }
            (param_1->playerObjects).value[(param_1->playerObjects).numberValue] = iVar4;
            (param_1->playerObjects).numberValue = (param_1->playerObjects).numberValue + 1;
LAB_004d79fb:
            param_2 = param_2 + 1;
          } while (param_2 < iStack_1c);
        }
        iVar14 = param_3;
        InfluenceMap::load(&param_1->pathMap,param_3);
        rge_read(iVar14,&param_1->lastWallPosition,8);
        rge_read(iVar14,&param_1->lastWallPosition2,8);
        if (save_game_version < _DAT_00575550) {
          iVar4 = 8;
        }
        else {
          iVar4 = 4;
        }
        rge_read(iVar14,&param_1->numberGatesValue,iVar4);
        pXVar15 = param_1->maxGatePosition;
        iVar4 = 4;
        do {
          rge_read(iVar14,pXVar15 + -4,8);
          rge_read(iVar14,pXVar15,8);
          pXVar15 = pXVar15 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        rge_read(iVar14,&param_1->saveLearnInformationValue,4);
        if (save_game_version < _DAT_00575550) {
          uVar12 = 0xffffffff;
          pcVar16 = s_;
          do {
            pcVar17 = pcVar16;
            if (uVar12 == 0) break;
            uVar12 = uVar12 - 1;
            pcVar17 = pcVar16 + 1;
            cVar1 = *pcVar16;
            pcVar16 = pcVar17;
          } while (cVar1 != '\0');
          uVar12 = ~uVar12;
          pcVar16 = pcVar17 + -uVar12;
          pcVar17 = param_1->learnFileName;
          for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined4 *)pcVar17 = *(undefined4 *)pcVar16;
            pcVar16 = pcVar16 + 4;
            pcVar17 = pcVar17 + 4;
          }
          for (uVar12 = uVar12 & 3; iVar14 = param_3, uVar12 != 0; uVar12 = uVar12 - 1) {
            *pcVar17 = *pcVar16;
            pcVar16 = pcVar16 + 1;
            pcVar17 = pcVar17 + 1;
          }
        }
        else {
          rge_read(iVar14,&iStack_18,4);
          rge_read(iVar14,param_1->learnFileName,iStack_18);
          param_1->learnFileName[iStack_18] = '\0';
        }
        rge_read(iVar14,param_1->fullyExploredZoneValue,0xff);
        if (save_game_version < _DAT_00575554) {
          piVar3 = &param_1->quadrantLog[0][0].numberAttacksByUs;
          iVar4 = 4;
          do {
            iVar9 = 4;
            do {
              ((QuadrantLog *)(piVar3 + -2))->numberExploredTiles = 0;
              piVar3[-1] = 0;
              *piVar3 = 0;
              piVar3 = piVar3 + 3;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        else {
          rge_read(iVar14,param_1->quadrantLog,0xc0);
        }
        piVar3 = param_1->maxResources;
        rge_read(iVar14,piVar3,0x10);
        rge_read(iVar14,param_1->numResources,0x10);
        iVar4 = 4;
        do {
          if (*piVar3 == 0) {
            piVar3[-8] = 0;
          }
          else {
            pRVar11 = (ResourceMemory *)operator_new(*piVar3 * 0x14);
            piVar3[-8] = (int)pRVar11;
            rge_read(iVar14,pRVar11,*piVar3 * 0x14);
          }
          piVar3 = piVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (_DAT_00575558 <= save_game_version) {
          rge_read(iVar14,param_1->dropsitesByAge,0x40);
        }
        if (_DAT_00575558 <= save_game_version) {
          rge_read(iVar14,param_1->closestDropsiteValue,0x10);
          rge_read(iVar14,param_1->closestDropsiteResourceID,0x10);
        }
        if (_DAT_0057555c <= save_game_version) {
          rge_read(iVar14,&param_1->numberFoundForestTilesValue,4);
        }
        if (_DAT_00575560 <= save_game_version) {
          rge_read(iVar14,param_1->playHistory,64000);
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004d7ca9
// Address: 004d7ca9
void __fastcall FUN_004d7ca9(InformationAIModule *param_1)
{
  byte bVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *unaff_FS_OFFSET;
  int iStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  InformationAIModule *pIStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  pcStack_8 = FUN_005604c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined ***)param_1 = &TribeInformationAIModule::_vftable_;
  iVar5 = 0;
  iStack_4 = 8;
  iVar6 = 0;
  pIStack_10 = param_1;
  do {
    operator_delete(*(void **)(iVar6 + *(int *)&param_1[5].field_0x18));
    iVar6 = iVar6 + 4;
  } while (iVar6 < 0x10);
  operator_delete(*(void **)&param_1[5].field_0x18);
  operator_delete(*(void **)&param_1[5].field_0x1c);
  if ((*(int *)&param_1[2].field_0x24 == 1) &&
     (iVar6 = rge_open(&param_1[2].field_0x28,0x8301,0x180), iStack_14 = iVar6, iVar6 != -1)) {
    rge_write(iVar6,&param_1[1].field_0x14,4);
    rge_write(iVar6,&param_1[1].field_0x18,4);
    iVar4 = *(int *)&param_1[2].field_0x1c;
    iStack_1c = 0;
    if (0 < iVar4) {
      piVar2 = *(int **)&param_1[2].field_0x20;
      do {
        if (*piVar2 != -1) {
          iStack_1c = iStack_1c + 1;
        }
        piVar2 = piVar2 + 6;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    rge_write(iVar6,&iStack_1c,4);
    if (0 < *(int *)&param_1[2].field_0x1c) {
      iVar4 = 0;
      do {
        if (*(int *)(iVar4 + *(int *)&param_1[2].field_0x20) != -1) {
          rge_write(iVar6,(void *)(iVar4 + *(int *)&param_1[2].field_0x20),0x18);
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x18;
      } while (iVar5 < *(int *)&param_1[2].field_0x1c);
    }
    iVar5 = *(int *)&param_1[1].field_0x20;
    iStack_1c = 0;
    if (0 < iVar5) {
      piVar2 = *(int **)&param_1[1].field_0x24;
      do {
        if ((*piVar2 != -1) && ((short)piVar2[1] == 0x6d)) {
          iStack_1c = iStack_1c + 1;
        }
        piVar2 = piVar2 + 9;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    rge_write(iVar6,&iStack_1c,4);
    iVar5 = 0;
    if (0 < *(int *)&param_1[1].field_0x20) {
      iVar4 = 0;
      do {
        pvVar3 = (void *)(iVar4 + *(int *)&param_1[1].field_0x24);
        if ((*(int *)(iVar4 + *(int *)&param_1[1].field_0x24) != -1) &&
           (*(short *)((int)pvVar3 + 4) == 0x6d)) {
          rge_write(iVar6,pvVar3,0x24);
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x24;
      } while (iVar5 < *(int *)&param_1[1].field_0x20);
    }
    piVar2 = (int *)&param_1[5].field_0x40;
    iVar5 = 4;
    do {
      rge_write(iVar6,piVar2,4);
      rge_write(iVar6,piVar2 + -4,4);
      if (*piVar2 != 0) {
        rge_write(iVar6,(void *)piVar2[-8],*piVar2 * 0x14);
      }
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    uStack_18 = *(undefined4 *)&param_1[1].field_0x4c;
    rge_write(iVar6,&uStack_18,4);
    iVar5 = 0;
    if (0 < *(int *)&param_1[1].field_0x4c) {
      do {
        if ((*(int *)&param_1[1].field_0x54 + -1 < iVar5) &&
           (pvVar3 = operator_new(iVar5 * 4 + 4), pvVar3 != (void *)0x0)) {
          iVar4 = 0;
          if (0 < *(int *)&param_1[1].field_0x54) {
            do {
              if (iVar5 + 1 <= iVar4) break;
              iVar4 = iVar4 + 1;
              *(undefined4 *)((int)pvVar3 + iVar4 * 4 + -4) =
                   *(undefined4 *)(*(int *)&param_1[1].field_0x48 + -4 + iVar4 * 4);
            } while (iVar4 < *(int *)&param_1[1].field_0x54);
          }
          operator_delete(*(void **)&param_1[1].field_0x48);
          *(void **)&param_1[1].field_0x48 = pvVar3;
          *(int *)&param_1[1].field_0x54 = iVar5 + 1;
        }
        uStack_18 = *(undefined4 *)(*(int *)&param_1[1].field_0x48 + iVar5 * 4);
        rge_write(iVar6,&uStack_18,4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)&param_1[1].field_0x4c);
    }
    uStack_18 = *(undefined4 *)&param_1[1].field_0x5c;
    rge_write(iVar6,&uStack_18,4);
    iVar5 = 0;
    if (0 < *(int *)&param_1[1].field_0x5c) {
      do {
        if (*(int *)&param_1[1].field_0x64 + -1 < iVar5) {
          pvVar3 = operator_new(iVar5 * 4 + 4);
          iVar6 = iStack_14;
          if (pvVar3 != (void *)0x0) {
            iVar6 = 0;
            if (0 < *(int *)&param_1[1].field_0x64) {
              do {
                if (iVar5 + 1 <= iVar6) break;
                iVar6 = iVar6 + 1;
                *(undefined4 *)((int)pvVar3 + iVar6 * 4 + -4) =
                     *(undefined4 *)(*(int *)&param_1[1].field_0x58 + -4 + iVar6 * 4);
              } while (iVar6 < *(int *)&param_1[1].field_0x64);
            }
            operator_delete(*(void **)&param_1[1].field_0x58);
            *(void **)&param_1[1].field_0x58 = pvVar3;
            *(int *)&param_1[1].field_0x64 = iVar5 + 1;
            iVar6 = iStack_14;
          }
        }
        uStack_18 = *(undefined4 *)(*(int *)&param_1[1].field_0x58 + iVar5 * 4);
        rge_write(iVar6,&uStack_18,4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)&param_1[1].field_0x5c);
    }
    rge_close(iVar6);
  }
  iVar5 = *(int *)(*(int *)&param_1[1].field_0x10 + 0xf0);
  bVar1 = *(byte *)(*(int *)(iVar5 + 0x3c) + 0x11d);
  if ((((ushort)bVar1 == *(ushort *)(iVar5 + 0x4a)) || (bVar1 == 0xff)) &&
     (iVar5 = rge_open(&param_1[0x110].field_0x90,0x8301,0x180), iVar5 != -1)) {
    rge_write(iVar5,&param_1[0x110].field_0x64,0x2c);
    rge_close(iVar5);
  }
  if (*(void **)&param_1[1].field_0x24 != (void *)0x0) {
    operator_delete(*(void **)&param_1[1].field_0x24);
  }
  if (*(void **)&param_1[2].field_0x18 != (void *)0x0) {
    operator_delete(*(void **)&param_1[2].field_0x18);
  }
  if (*(void **)&param_1[2].field_0x20 != (void *)0x0) {
    operator_delete(*(void **)&param_1[2].field_0x20);
  }
  puVar7 = (undefined4 *)&param_1[5].field_0x20;
  iVar5 = 4;
  do {
    if ((void *)*puVar7 != (void *)0x0) {
      operator_delete((void *)*puVar7);
      *puVar7 = 0;
    }
    puVar7 = puVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iStack_4._0_1_ = 7;
  if (*(void **)&param_1[1].field_0xa0 != (void *)0x0) {
    operator_delete(*(void **)&param_1[1].field_0xa0);
    *(undefined4 *)&param_1[1].field_0xa0 = 0;
  }
  *(undefined4 *)&param_1[1].field_0xa4 = 0;
  *(undefined4 *)&param_1[1].field_0xa8 = 0;
  *(undefined4 *)&param_1[1].field_0xac = 0;
  iStack_4._0_1_ = 6;
  if (*(void **)&param_1[1].field_0x90 != (void *)0x0) {
    operator_delete(*(void **)&param_1[1].field_0x90);
    *(undefined4 *)&param_1[1].field_0x90 = 0;
  }
  *(undefined4 *)&param_1[1].field_0x94 = 0;
  *(undefined4 *)&param_1[1].field_0x98 = 0;
  *(undefined4 *)&param_1[1].field_0x9c = 0;
  iStack_4._0_1_ = 5;
  InfluenceMap::~InfluenceMap((InfluenceMap *)&param_1[1].field_0x68);
  iStack_4._0_1_ = 4;
  if (*(void **)&param_1[1].field_0x58 != (void *)0x0) {
    operator_delete(*(void **)&param_1[1].field_0x58);
    *(undefined4 *)&param_1[1].field_0x58 = 0;
  }
  *(undefined4 *)&param_1[1].field_0x5c = 0;
  *(undefined4 *)&param_1[1].field_0x60 = 0;
  *(undefined4 *)&param_1[1].field_0x64 = 0;
  iStack_4._0_1_ = 3;
  if (*(void **)&param_1[1].field_0x48 != (void *)0x0) {
    operator_delete(*(void **)&param_1[1].field_0x48);
    *(undefined4 *)&param_1[1].field_0x48 = 0;
  }
  *(undefined4 *)&param_1[1].field_0x4c = 0;
  *(undefined4 *)&param_1[1].field_0x50 = 0;
  *(undefined4 *)&param_1[1].field_0x54 = 0;
  iStack_4._0_1_ = 2;
  if (*(void **)&param_1[1].field_0x38 != (void *)0x0) {
    operator_delete(*(void **)&param_1[1].field_0x38);
    *(undefined4 *)&param_1[1].field_0x38 = 0;
  }
  *(undefined4 *)&param_1[1].field_0x3c = 0;
  *(undefined4 *)&param_1[1].field_0x40 = 0;
  *(undefined4 *)&param_1[1].field_0x44 = 0;
  iStack_4._0_1_ = 1;
  if (*(void **)&param_1[1].field_0x28 != (void *)0x0) {
    operator_delete(*(void **)&param_1[1].field_0x28);
    *(undefined4 *)&param_1[1].field_0x28 = 0;
  }
  *(undefined4 *)&param_1[1].field_0x2c = 0;
  *(undefined4 *)&param_1[1].field_0x30 = 0;
  *(undefined4 *)&param_1[1].field_0x34 = 0;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  if (*(void **)(param_1 + 1) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 1));
    *(undefined4 *)(param_1 + 1) = 0;
  }
  *(undefined4 *)&param_1[1].field_0x4 = 0;
  *(undefined4 *)&param_1[1].field_0x8 = 0;
  *(undefined4 *)&param_1[1].field_0xc = 0;
  iStack_4 = 0xffffffff;
  InformationAIModule::~InformationAIModule(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004d82ff
// Address: 004d82ff
undefined4 __fastcall FUN_004d82ff(TribeInformationAIModule *param_1)
{
  QuadrantLog *pQVar1;
  int iVar2;
  undefined4 *puVar3;
  RGE_Static_Object *pRVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  int iStack_20;
  RGE_Tile_List_Node *pRStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  RGE_Visible_Map *pRStack_c;
  InfluenceMap *pIStack_8;
  uint uStack_4;
  
  RGE_Tile_List::get_list_info
            ((RGE_Tile_List *)(param_1->md->_padding_ + 0x58),&pRStack_1c,&iStack_10);
  iStack_14 = RGE_Tile_List::get_new_count((RGE_Tile_List *)(param_1->md->_padding_ + 0x58));
  iVar6 = param_1->md->_padding_;
  pRStack_c = *(RGE_Visible_Map **)(iVar6 + 0x38);
  iStack_18 = *(int *)(*(int *)(iVar6 + 0x3c) + 0x28);
  if ((0 < iStack_14) && (iStack_14 = iStack_10 - iStack_14, iStack_14 < iStack_10)) {
    pIStack_8 = &param_1->pathMap;
    do {
      iVar7 = pRStack_1c->row;
      iVar2 = pRStack_1c->col;
      uVar5 = RGE_Visible_Map::get_visible(pRStack_c,iVar2,iVar7);
      iVar6 = iVar7 * 4;
      uStack_4 = *(byte *)(*(int *)(*(int *)(iStack_18 + 0x8d8c) + iVar6) + 5 + iVar2 * 0x18) & 0x1f
      ;
      if (param_1->mapXSizeValue != -1) {
        pQVar1 = param_1->quadrantLog[(iVar2 * 4) / param_1->mapXSizeValue] +
                 iVar6 / param_1->mapYSizeValue;
        pQVar1->numberExploredTiles = pQVar1->numberExploredTiles + 1;
      }
      InfluenceMap::setValue(pIStack_8,iVar2,iVar7,'\0');
      iStack_20 = 0;
      for (puVar3 = *(undefined4 **)
                     (*(int *)(*(int *)(iStack_18 + 0x8d8c) + iVar6) + 0x10 + iVar2 * 0x18);
          puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)puVar3[1]) {
        pRVar4 = (RGE_Static_Object *)*puVar3;
        if ((uVar5 != 0x80) || (pRVar4->master_obj->fog_flag != '\0')) {
          iVar7 = (int)pRVar4->master_obj->object_group;
          iVar6 = TribeInformationAIModule::importantObject(param_1,iVar7);
          if (iVar6 == 1) {
            TribeInformationAIModule::addImportantObject(param_1,pRVar4,0);
          }
          if (iVar7 == 0xf) {
            iStack_20 = iStack_20 + 1;
          }
        }
      }
      if ((0 < iStack_20) &&
         ((((uStack_4 == 10 || (uStack_4 == 0x13)) || (uStack_4 == 0xd)) || (uStack_4 == 0x14)))) {
        param_1->numberFoundForestTilesValue = param_1->numberFoundForestTilesValue + 1;
      }
      iStack_14 = iStack_14 + 1;
      pRStack_1c = pRStack_1c + 1;
    } while (iStack_14 < iStack_10);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d84c2
// Address: 004d84c2
void __thiscall FUN_004d84c2(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x100) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004d84dd
// Address: 004d84dd
undefined4 __thiscall FUN_004d84dd(int param_1,int param_2)
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int *piVar10;
  undefined4 uStack_4;
  
  iVar3 = param_2;
  iVar8 = 0;
  do {
    uStack_4 = *(undefined4 *)(iVar8 + *(int *)(param_1 + 0x4cc));
    rge_write(iVar3,&uStack_4,4);
    iVar7 = 0;
    if (0 < *(int *)(iVar8 + *(int *)(param_1 + 0x4cc))) {
      do {
        uStack_4 = *(undefined4 *)(*(int *)(iVar8 + *(int *)(param_1 + 0x4c8)) + iVar7 * 4);
        rge_write(iVar3,&uStack_4,4);
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(iVar8 + *(int *)(param_1 + 0x4cc)));
    }
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x10);
  rge_write(iVar3,(void *)(param_1 + 0x104),4);
  rge_write(iVar3,(void *)(param_1 + 0x108),4);
  rge_write(iVar3,(void *)(param_1 + 0x10c),4);
  rge_write(iVar3,(int *)(param_1 + 0x110),4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    iVar7 = 0;
    do {
      rge_write(iVar3,(void *)(iVar7 + *(int *)(param_1 + 0x114)),0x24);
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 0x24;
    } while (iVar8 < *(int *)(param_1 + 0x110));
  }
  piVar10 = (int *)(param_1 + 500);
  rge_write(iVar3,piVar10,4);
  iVar8 = 0;
  if (0 < *piVar10) {
    do {
      rge_write(iVar3,(void *)(*(int *)(param_1 + 0x1f8) + iVar8 * 8),8);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *piVar10);
  }
  rge_write(iVar3,(int *)(param_1 + 0x1fc),4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x1fc)) {
    iVar7 = 0;
    do {
      rge_write(iVar3,(void *)(iVar7 + *(int *)(param_1 + 0x200)),0x18);
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 0x18;
    } while (iVar8 < *(int *)(param_1 + 0x1fc));
  }
  param_2 = *(undefined4 *)(param_1 + 0x11c);
  rge_write(iVar3,&param_2,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x11c)) {
    do {
      if (*(int *)(param_1 + 0x124) + -1 < iVar8) {
        pvVar4 = operator_new(iVar8 * 4 + 4);
        if (pvVar4 != (void *)0x0) {
          iVar7 = 0;
          if (0 < *(int *)(param_1 + 0x124)) {
            do {
              if (iVar8 + 1 <= iVar7) break;
              iVar7 = iVar7 + 1;
              *(undefined4 *)((int)pvVar4 + iVar7 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x118) + -4 + iVar7 * 4);
            } while (iVar7 < *(int *)(param_1 + 0x124));
          }
          operator_delete(*(void **)(param_1 + 0x118));
          *(void **)(param_1 + 0x118) = pvVar4;
          *(int *)(param_1 + 0x124) = iVar8 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 0x118) + iVar8 * 4);
      rge_write(iVar3,&param_2,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x11c));
  }
  param_2 = *(undefined4 *)(param_1 + 300);
  rge_write(iVar3,&param_2,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 300)) {
    do {
      if (*(int *)(param_1 + 0x134) + -1 < iVar8) {
        pvVar4 = operator_new(iVar8 * 4 + 4);
        if (pvVar4 != (void *)0x0) {
          iVar7 = 0;
          if (0 < *(int *)(param_1 + 0x134)) {
            do {
              if (iVar8 + 1 <= iVar7) break;
              iVar7 = iVar7 + 1;
              *(undefined4 *)((int)pvVar4 + iVar7 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x128) + -4 + iVar7 * 4);
            } while (iVar7 < *(int *)(param_1 + 0x134));
          }
          operator_delete(*(void **)(param_1 + 0x128));
          *(void **)(param_1 + 0x128) = pvVar4;
          *(int *)(param_1 + 0x134) = iVar8 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 0x128) + iVar8 * 4);
      rge_write(iVar3,&param_2,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 300));
  }
  param_2 = *(undefined4 *)(param_1 + 0x13c);
  rge_write(iVar3,&param_2,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x13c)) {
    do {
      if (*(int *)(param_1 + 0x144) + -1 < iVar8) {
        pvVar4 = operator_new(iVar8 * 4 + 4);
        if (pvVar4 != (void *)0x0) {
          iVar7 = 0;
          if (0 < *(int *)(param_1 + 0x144)) {
            do {
              if (iVar8 + 1 <= iVar7) break;
              iVar7 = iVar7 + 1;
              *(undefined4 *)((int)pvVar4 + iVar7 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x138) + -4 + iVar7 * 4);
            } while (iVar7 < *(int *)(param_1 + 0x144));
          }
          operator_delete(*(void **)(param_1 + 0x138));
          *(void **)(param_1 + 0x138) = pvVar4;
          *(int *)(param_1 + 0x144) = iVar8 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 0x138) + iVar8 * 4);
      rge_write(iVar3,&param_2,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x13c));
  }
  param_2 = *(undefined4 *)(param_1 + 0x14c);
  rge_write(iVar3,&param_2,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x14c)) {
    do {
      if (*(int *)(param_1 + 0x154) + -1 < iVar8) {
        pvVar4 = operator_new(iVar8 * 4 + 4);
        if (pvVar4 != (void *)0x0) {
          iVar7 = 0;
          if (0 < *(int *)(param_1 + 0x154)) {
            do {
              if (iVar8 + 1 <= iVar7) break;
              iVar7 = iVar7 + 1;
              *(undefined4 *)((int)pvVar4 + iVar7 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x148) + -4 + iVar7 * 4);
            } while (iVar7 < *(int *)(param_1 + 0x154));
          }
          operator_delete(*(void **)(param_1 + 0x148));
          *(void **)(param_1 + 0x148) = pvVar4;
          *(int *)(param_1 + 0x154) = iVar8 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 0x148) + iVar8 * 4);
      rge_write(iVar3,&param_2,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x14c));
  }
  param_2 = *(undefined4 *)(param_1 + 0x194);
  rge_write(iVar3,&param_2,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x194)) {
    do {
      if (*(int *)(param_1 + 0x19c) + -1 < iVar8) {
        pvVar4 = operator_new(iVar8 * 4 + 4);
        if (pvVar4 != (void *)0x0) {
          iVar7 = 0;
          if (0 < *(int *)(param_1 + 0x19c)) {
            do {
              if (iVar8 + 1 <= iVar7) break;
              iVar7 = iVar7 + 1;
              *(undefined4 *)((int)pvVar4 + iVar7 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 400) + -4 + iVar7 * 4);
            } while (iVar7 < *(int *)(param_1 + 0x19c));
          }
          operator_delete(*(void **)(param_1 + 400));
          *(void **)(param_1 + 400) = pvVar4;
          *(int *)(param_1 + 0x19c) = iVar8 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 400) + iVar8 * 4);
      rge_write(iVar3,&param_2,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x194));
  }
  param_2 = *(undefined4 *)(param_1 + 0x184);
  rge_write(iVar3,&param_2,4);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x184)) {
    do {
      if (*(int *)(param_1 + 0x18c) + -1 < iVar8) {
        pvVar4 = operator_new(iVar8 * 4 + 4);
        if (pvVar4 != (void *)0x0) {
          iVar7 = 0;
          if (0 < *(int *)(param_1 + 0x18c)) {
            do {
              if (iVar8 + 1 <= iVar7) break;
              iVar7 = iVar7 + 1;
              *(undefined4 *)((int)pvVar4 + iVar7 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x180) + -4 + iVar7 * 4);
            } while (iVar7 < *(int *)(param_1 + 0x18c));
          }
          operator_delete(*(void **)(param_1 + 0x180));
          *(void **)(param_1 + 0x180) = pvVar4;
          *(int *)(param_1 + 0x18c) = iVar8 + 1;
        }
      }
      param_2 = *(undefined4 *)(*(int *)(param_1 + 0x180) + iVar8 * 4);
      rge_write(iVar3,&param_2,4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x184));
  }
  InfluenceMap::save((InfluenceMap *)(param_1 + 0x158),iVar3);
  rge_write(iVar3,(void *)(param_1 + 0x1a0),8);
  rge_write(iVar3,(void *)(param_1 + 0x1a8),8);
  rge_write(iVar3,(void *)(param_1 + 0x1b0),4);
  pvVar4 = (void *)(param_1 + 0x1d4);
  iVar8 = 4;
  do {
    rge_write(iVar3,(void *)((int)pvVar4 + -0x20),8);
    rge_write(iVar3,pvVar4,8);
    pvVar4 = (void *)((int)pvVar4 + 8);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  rge_write(iVar3,(void *)(param_1 + 0x204),4);
  pcVar1 = (char *)(param_1 + 0x208);
  uVar6 = 0xffffffff;
  pcVar9 = pcVar1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  param_2 = ~uVar6 - 1;
  rge_write(iVar3,&param_2,4);
  uVar6 = 0xffffffff;
  pcVar9 = pcVar1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  rge_write(iVar3,pcVar1,~uVar6 - 1);
  rge_write(iVar3,(void *)(param_1 + 0x308),0xff);
  rge_write(iVar3,(void *)(param_1 + 0x408),0xc0);
  piVar10 = (int *)(param_1 + 0x4f0);
  iVar8 = 4;
  piVar5 = piVar10;
  do {
    if ((*piVar5 != 0) && (piVar5[-8] == 0)) {
      *piVar5 = 0;
    }
    piVar5 = piVar5 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  rge_write(iVar3,piVar10,0x10);
  rge_write(iVar3,(void *)(param_1 + 0x4e0),0x10);
  iVar8 = 4;
  do {
    if (*piVar10 != 0) {
      rge_write(iVar3,(void *)piVar10[-8],*piVar10 * 0x14);
    }
    piVar10 = piVar10 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  rge_write(iVar3,(void *)(param_1 + 0x500),0x40);
  rge_write(iVar3,(void *)(param_1 + 0x540),0x10);
  rge_write(iVar3,(void *)(param_1 + 0x550),0x10);
  rge_write(iVar3,(void *)(param_1 + 0x560),4);
  rge_write(iVar3,(void *)(param_1 + 0x564),64000);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004d8c77
// Address: 004d8c77
void __thiscall
FUN_004d8c77(TribeInformationAIModule *param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  XStack_8.y = param_3;
  XStack_8.x = param_2;
  TribeInformationAIModule::mapBound(param_1,&XStack_8);
  XStack_10.y = param_5;
  XStack_10.x = param_4;
  TribeInformationAIModule::mapBound(param_1,&XStack_10);
  iVar1 = XStack_10.y;
  iVar2 = XStack_8.x;
  iVar3 = XStack_8.y;
  if (XStack_8.x <= XStack_10.x) {
    do {
      iVar4 = iVar3;
      if (iVar3 <= iVar1) {
        do {
          iVar1 = InfluenceMap::lookupValue(&param_1->pathMap,iVar2,iVar3);
          if (iVar1 != 1) {
            InfluenceMap::setValue(&param_1->pathMap,iVar2,iVar3,'\x02');
          }
          iVar3 = iVar3 + 1;
          iVar1 = XStack_10.y;
          iVar4 = XStack_8.y;
        } while (iVar3 <= XStack_10.y);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar4;
    } while (iVar2 <= XStack_10.x);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d8d18
// Address: 004d8d18
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004d8d18(TribeInformationAIModule *param_1,int param_2)
{
  RGE_Visible_Map *this;
  char cVar1;
  bool bVar2;
  bool bVar3;
  uchar uVar4;
  uchar uVar5;
  RGE_Static_Object *this_00;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  QuadrantLog *pQVar11;
  uint uVar12;
  int unaff_EBX;
  float *pfVar13;
  bool bVar14;
  int iStack_34;
  int iStack_2c;
  int iStack_28;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined1 auStack_c [4];
  int iStack_8;
  int iStack_4;
  
  iVar7 = param_1->md->_padding_;
  this = *(RGE_Visible_Map **)(iVar7 + 0x38);
  this_00 = RGE_Game_World::object(*(RGE_Game_World **)(iVar7 + 0x3c),param_2);
  if (this_00 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  bVar14 = this_00->master_obj->object_group == 4;
  uVar4 = RGE_Static_Object::currentZone(this_00);
  uVar6 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x397);
  uVar12 = (int)uVar6 >> 0x1f;
  pfVar13 = (float *)0x0;
  iStack_34 = ((uVar6 ^ uVar12) - uVar12 & 3 ^ uVar12) - uVar12;
  iVar7 = __ftol();
  iStack_8 = iVar7;
  iVar8 = __ftol();
  bVar2 = false;
  bVar3 = false;
  iStack_2c = 0;
  iStack_28 = 0;
  iStack_4 = iVar8;
  do {
    if ((((bVar2) && (bVar3)) && (iStack_2c != 0)) && (iStack_28 != 0)) {
      TribeInformationAIModule::setFullyExploredZone(param_1,param_2,1);
      return 0;
    }
    pfVar13 = (float *)((int)pfVar13 + 1);
    iStack_1c = 0;
    do {
      iStack_20 = 0;
      uVar6 = (int)(iStack_34 + 1U) >> 0x1f;
      iStack_34 = ((iStack_34 + 1U ^ uVar6) - uVar6 & 3 ^ uVar6) - uVar6;
      if (0 < (int)pfVar13) {
        do {
          switch(iStack_34) {
          case 0:
            iVar8 = iVar8 + 1;
            iStack_4 = iVar8;
            break;
          case 1:
            iVar7 = iVar7 + 1;
            iStack_8 = iVar7;
            break;
          case 2:
            iVar8 = iVar8 + -1;
            iStack_4 = iVar8;
            break;
          case 3:
            iVar7 = iVar7 + -1;
            iStack_8 = iVar7;
          }
          if (iVar7 < 0) {
            bVar2 = true;
          }
          else if (iVar7 < param_1->mapXSizeValue) {
            if (iVar8 < 0) {
              iStack_2c = 1;
            }
            else if (iVar8 < param_1->mapYSizeValue) {
              iVar9 = InfluenceMap::lookupValue(&param_1->pathMap,iVar7,iVar8);
              cVar1 = (char)iVar9;
              uVar5 = RGE_Visible_Map::get_visible(this,iVar7,iVar8);
              if ((((uVar5 != '\x0f') && ((!bVar14 || (cVar1 == -1)))) &&
                  ((bVar14 || ((cVar1 == -1 || (cVar1 == '\x02')))))) &&
                 ((iVar9 = (**(code **)(this_00->_padding_ + 0x114))
                                     ((float)iStack_8,(float)iStack_4,1), iVar9 != 0 &&
                  (uVar5 = RGE_Static_Object::lookupZone(this_00,iVar7,iVar8), uVar5 == uVar4)))) {
                uVar10 = __ftol();
                iVar9 = (**(code **)(this_00->_padding_ + 0x198))
                                  (iVar7,iVar8,uVar10,this_00->master_obj->los - _DAT_00575564,
                                   0xffffffff,auStack_c,1,0xffffffff,0xffffffff);
                if (iVar9 == 0) {
                  InfluenceMap::setValue(&param_1->pathMap,iVar7,iVar8,'\x01');
                  iVar7 = -1;
                  iStack_2c = 0;
                  iStack_18 = 0;
                  iStack_1c = 0;
                  pQVar11 = param_1->quadrantLog[0];
                  do {
                    iStack_20 = 0;
                    do {
                      iVar8 = ((QuadrantLog *)&pQVar11->numberExploredTiles)->numberExploredTiles;
                      iVar9 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x420);
                      iVar8 = pQVar11->numberAttacksOnUs * 0x19 + iVar8 + iVar9 % 100;
                      if ((iVar7 == -1) || (iVar8 < iVar7)) {
                        iVar7 = *(int *)(unaff_EBX + 0x104) * iStack_1c;
                        iVar9 = *(int *)(unaff_EBX + 0x108) * iStack_20;
                        iStack_2c = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
                        iStack_18 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
                        iVar7 = iVar8;
                      }
                      pQVar11 = pQVar11 + 1;
                      iStack_20 = iStack_20 + 1;
                    } while (iStack_20 < 4);
                    iStack_1c = iStack_1c + 1;
                  } while (iStack_1c < 4);
                  iVar7 = ((int)(*(int *)(unaff_EBX + 0x104) +
                                (*(int *)(unaff_EBX + 0x104) >> 0x1f & 3U)) >> 2) + -1 + iStack_2c;
                  iStack_28 = ((int)(*(int *)(unaff_EBX + 0x108) +
                                    (*(int *)(unaff_EBX + 0x108) >> 0x1f & 3U)) >> 2) + -1 +
                              iStack_18;
                  uVar6 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x430);
                  uVar12 = (int)uVar6 >> 0x1f;
                  uVar6 = (uVar6 ^ uVar12) - uVar12 & 3 ^ uVar12;
                  iVar8 = uVar6 - uVar12;
                  if (uVar6 == uVar12) {
                    iStack_28 = iStack_18;
                  }
                  else if ((iVar8 != 1) && (iStack_2c = iVar7, iVar8 != 2)) {
                    iStack_28 = iStack_18;
                  }
                }
                else {
                  InfluenceMap::setValue(&param_1->pathMap,iVar7,iVar8,'\0');
                }
                this->map_offsets = (uchar **)(float)iStack_2c;
                *pfVar13 = (float)iStack_28;
                return 1;
              }
            }
            else {
              iStack_28 = 1;
            }
          }
          else {
            bVar3 = true;
          }
          iStack_20 = iStack_20 + 1;
        } while (iStack_20 < (int)pfVar13);
      }
      iStack_1c = iStack_1c + 1;
    } while (iStack_1c < 2);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004d90f1
// Address: 004d90f1
undefined4 __thiscall FUN_004d90f1(int param_1,uint param_2)
{
  byte bVar1;
  RGE_Static_Object *this;
  
  this = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_2);
  if (this != (RGE_Static_Object *)0x0) {
    bVar1 = RGE_Static_Object::currentZone(this);
    param_2 = (uint)bVar1;
    if (*(char *)(param_2 + 0x308 + param_1) == '\0') {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d9156
// Address: 004d9156
void __thiscall FUN_004d9156(int param_1,uint param_2,undefined1 param_3)
{
  byte bVar1;
  RGE_Static_Object *this;
  
  this = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_2);
  if (this != (RGE_Static_Object *)0x0) {
    bVar1 = RGE_Static_Object::currentZone(this);
    param_2 = (uint)bVar1;
    *(undefined1 *)(param_2 + 0x308 + param_1) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d919b
// Address: 004d919b
undefined4 __thiscall FUN_004d919b(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  if ((((-1 < param_2) && (-1 < param_3)) && (param_2 < *(int *)(param_1 + 0x104))) &&
     (param_3 < *(int *)(param_1 + 0x108))) {
    iVar1 = InfluenceMap::lookupValue((InfluenceMap *)(param_1 + 0x158),param_2,param_3);
    if (iVar1 != 0xff) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004d91e1
// Address: 004d91e1
void __thiscall FUN_004d91e1(int param_1,int param_2,int param_3)
{
  if ((((-1 < param_2) && (-1 < param_3)) && (param_2 < *(int *)(param_1 + 0x104))) &&
     (param_3 < *(int *)(param_1 + 0x108))) {
    InfluenceMap::setValue((InfluenceMap *)(param_1 + 0x158),param_2,param_3,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004d9222
// Address: 004d9222
undefined4 FUN_004d9222(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004d9236
// Address: 004d9236
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004d9236(TribeInformationAIModule *param_1,int param_2,int param_3,float *param_4,float *param_5
            ,undefined4 *param_6,int *param_7,int param_8)
{
  short sVar1;
  ResourceMemory *pRVar2;
  bool bVar3;
  bool bVar4;
  uchar uVar5;
  uchar uVar6;
  RGE_Static_Object *this;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  RGE_Static_Object *pRVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  undefined4 *puVar16;
  int iStack_24;
  undefined4 *puStack_20;
  int iStack_1c;
  int iStack_14;
  
  *param_6 = 0xffffffff;
  this = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_3);
  if (this != (RGE_Static_Object *)0x0) {
    uVar5 = RGE_Static_Object::currentZone(this);
    iVar7 = __ftol();
    iVar8 = __ftol();
    iVar9 = TribeInformationAIModule::isBoat(param_1,this);
    iStack_1c = -1;
    puStack_20 = (undefined4 *)0x0;
    bVar4 = false;
    iStack_14 = 0;
    puVar16 = (undefined4 *)0x0;
    if (0 < param_1->numResources[param_2]) {
      iStack_24 = 0;
      do {
        piVar14 = (int *)((int)&param_1->resources[param_2]->id + iStack_24);
        if (*(char *)((int)piVar14 + 0xd) != '\x01') {
          if ((char)piVar14[3] == '\0') {
            bVar3 = false;
            iVar10 = 0;
            if (0 < param_8) {
              piVar13 = param_7;
              do {
                if (*piVar13 == *piVar14) {
                  bVar3 = true;
                  break;
                }
                iVar10 = iVar10 + 1;
                piVar13 = piVar13 + 1;
              } while (iVar10 < param_8);
            }
            if (!bVar3) {
              pRVar11 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,*piVar14);
              if (pRVar11 == (RGE_Static_Object *)0x0) {
                (&param_1->resources[param_2]->gone)[iStack_24] = '\x01';
                if (param_1->closestDropsiteResourceID[param_2] ==
                    *(int *)((int)&param_1->resources[param_2]->id + iStack_24)) {
                  bVar4 = true;
                }
              }
              else if (((((iVar9 != 1) || (sVar1 = pRVar11->master_obj->object_group, sVar1 == 5))
                        || (sVar1 == 0x1f)) || (sVar1 == 0x21)) &&
                      ((iVar9 != 0 ||
                       (((sVar1 = pRVar11->master_obj->object_group, sVar1 != 5 && (sVar1 != 0x1f))
                        && (sVar1 != 0x21)))))) {
                pRVar2 = param_1->resources[param_2];
                iVar10 = iVar7 - (uint)(&pRVar2->x)[iStack_24];
                iVar15 = iVar8 - (uint)(&pRVar2->y)[iStack_24];
                iVar10 = iVar10 * iVar10 + iVar15 * iVar15 +
                         *(int *)((int)&pRVar2->gatherValue + iStack_24) * 10;
                if (pRVar11->master_obj->id == 0x3b) {
                  if (0x14 < (&pRVar2->dropDistance)[iStack_24]) goto LAB_004d9646;
                  iVar10 = iVar10 + (&pRVar2->gatherAttempts)[iStack_24] / 0x96;
                  iVar15 = TribeTacticalAIModule::numberGatherersWithTarget
                                     (&param_1->md->tacticalAI,pRVar11->id);
                  if (2 < iVar15) {
                    iVar10 = iVar10 + 200;
                  }
                }
                else {
                  iVar10 = iVar10 + (&pRVar2->gatherAttempts)[iStack_24] / 0x32;
                }
                if ((puStack_20 == (undefined4 *)0x0) || (iVar10 < iStack_1c)) {
                  sVar1 = pRVar11->master_obj->object_group;
                  if (((sVar1 == 9) || (sVar1 == 10)) &&
                     ((2 < pRVar11->object_state && (_DAT_00575568 < pRVar11->attribute_amount_held)
                      ))) {
                    iVar10 = iVar10 + 0x19;
                  }
                  iVar15 = TribeInformationAIModule::withinXTilesOfEnemyTowncenter
                                     (param_1,pRVar11,0x19);
                  if (iVar15 != 1) {
                    iVar15 = TribeInformationAIModule::withinXTilesOfAttackOnPlayer
                                       (param_1,pRVar11,0xf,
                                        (int)*(short *)(param_1->md->_padding_ + 0x4a));
                    if (iVar15 == 1) {
                      iVar10 = iVar10 + 500;
                    }
                    if (pRVar11->master_obj->id == 0x32) {
                      if (((pRVar11->owner->id != *(short *)(param_1->md->_padding_ + 0x4a)) ||
                          (pRVar11->object_state != '\x02')) ||
                         (iVar15 = TribeTacticalAIModule::numberGatherersWithTarget
                                             (&param_1->md->tacticalAI,pRVar11->id), 0 < iVar15))
                      goto LAB_004d9646;
                      iVar15 = (param_1->farmsTaskedThisUpdate).numberValue;
                      iVar12 = 0;
                      if (0 < iVar15) {
                        do {
                          if ((param_1->farmsTaskedThisUpdate).maximumSizeValue <= iVar12) break;
                          if ((param_1->farmsTaskedThisUpdate).value[iVar12] == pRVar11->id)
                          goto LAB_004d9646;
                          iVar12 = iVar12 + 1;
                        } while (iVar12 < iVar15);
                      }
                    }
                    if (((param_2 != 1) ||
                        (iVar15 = TribeTacticalAIModule::numberGatherersWithTarget
                                            (&param_1->md->tacticalAI,pRVar11->id), iVar15 < 1)) &&
                       (((param_2 != 3 && (param_2 != 2)) ||
                        (iVar15 = TribeTacticalAIModule::numberGatherersWithTarget
                                            (&param_1->md->tacticalAI,pRVar11->id), iVar15 < 4)))) {
                      if ((pRVar11->master_obj->id == 0x30) && (pRVar11->object_state == '\x02')) {
                        iVar15 = TribeTacticalAIModule::strategicNumber
                                           (&param_1->md->tacticalAI,0xcc);
                        iVar12 = TribeTacticalAIModule::actualGathererCountByRealResourceID
                                           (&param_1->md->tacticalAI,0);
                        if (iVar12 < iVar15) goto LAB_004d9646;
                      }
                      uVar6 = RGE_Static_Object::lookupZone
                                        (this,(uint)(&param_1->resources[param_2]->x)[iStack_24],
                                         (uint)(&param_1->resources[param_2]->y)[iStack_24]);
                      if ((uVar5 == uVar6) &&
                         ((puStack_20 == (undefined4 *)0x0 || (iVar10 < iStack_1c)))) {
                        puStack_20 = (undefined4 *)
                                     ((int)&param_1->resources[param_2]->id + iStack_24);
                        *param_4 = pRVar11->world_x;
                        *param_5 = pRVar11->world_y;
                        iStack_1c = iVar10;
                      }
                    }
                  }
                }
              }
            }
          }
          else if (*(char *)((int)piVar14 + 0xd) == '\0') {
            *(char *)(piVar14 + 3) = (char)piVar14[3] + -1;
          }
        }
LAB_004d9646:
        iStack_14 = iStack_14 + 1;
        iStack_24 = iStack_24 + 0x14;
        puVar16 = puStack_20;
      } while (iStack_14 < param_1->numResources[param_2]);
    }
    if (bVar4) {
      TribeInformationAIModule::updateResourceDropsites(param_1,param_2);
    }
    if (puVar16 != (undefined4 *)0x0) {
      *(char *)((int)puVar16 + 6) = *(char *)((int)puVar16 + 6) + '\x01';
      *param_6 = puVar16[4];
      return *puVar16;
    }
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_004d96aa
// Address: 004d96aa
int __thiscall FUN_004d96aa(int param_1,int param_2,int *param_3,int *param_4,int param_5)
{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  void *pvVar5;
  int iStack_10;
  int iStack_c;
  int iStack_4;
  
  *param_3 = 0;
  iStack_c = 0;
  *param_4 = 0;
  iStack_10 = 10;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x11c)) {
    do {
      if (*(int *)(param_1 + 0x124) + -1 < iStack_4) {
        pvVar2 = operator_new(iStack_4 * 4 + 4);
        if (pvVar2 != (void *)0x0) {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x124)) {
            do {
              if (iStack_4 + 1 <= iVar3) break;
              iVar3 = iVar3 + 1;
              *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x118) + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)(param_1 + 0x124));
          }
          operator_delete(*(void **)(param_1 + 0x118));
          *(void **)(param_1 + 0x118) = pvVar2;
          *(int *)(param_1 + 0x124) = iStack_4 + 1;
        }
      }
      pRVar4 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x3c)
                          ,*(int *)(*(int *)(param_1 + 0x118) + iStack_4 * 4));
      if ((((pRVar4 != (RGE_Static_Object *)0x0) &&
           ((param_5 != -5 ||
            (*(short *)(*(int *)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x4a) != pRVar4->owner->id))
           )) && ((param_5 != -6 ||
                  (iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x18))
                                     ((int)pRVar4->owner->id), iVar3 == 0)))) &&
         (((param_5 == -1 || (pRVar4->owner->id == param_5)) &&
          ((param_2 == -1 || (param_2 == pRVar4->master_obj->id)))))) {
        if ((iStack_c == iStack_10) || (*param_3 == 0)) {
          pvVar2 = operator_new(iStack_10 * 8);
          pvVar5 = operator_new(iStack_10 * 8);
          if ((*param_3 != 0) && (iVar3 = 0, 0 < iStack_10)) {
            do {
              puVar1 = (undefined4 *)((int)pvVar5 + iVar3 * 4);
              iVar3 = iVar3 + 1;
              *(undefined4 *)(((int)pvVar2 - (int)pvVar5) + (int)puVar1) =
                   *(undefined4 *)(*param_3 + -4 + iVar3 * 4);
              *puVar1 = *(undefined4 *)(*param_4 + -4 + iVar3 * 4);
            } while (iVar3 < iStack_10);
          }
          iStack_10 = iStack_10 * 2;
          if ((void *)*param_3 != (void *)0x0) {
            operator_delete((void *)*param_3);
          }
          if ((void *)*param_4 != (void *)0x0) {
            operator_delete((void *)*param_4);
          }
          *param_3 = (int)pvVar2;
          *param_4 = (int)pvVar5;
        }
        if (*(int *)(param_1 + 0x124) + -1 < iStack_4) {
          pvVar2 = operator_new(iStack_4 * 4 + 4);
          if (pvVar2 != (void *)0x0) {
            iVar3 = 0;
            if (0 < *(int *)(param_1 + 0x124)) {
              do {
                if (iStack_4 + 1 <= iVar3) break;
                iVar3 = iVar3 + 1;
                *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                     *(undefined4 *)(*(int *)(param_1 + 0x118) + -4 + iVar3 * 4);
              } while (iVar3 < *(int *)(param_1 + 0x124));
            }
            operator_delete(*(void **)(param_1 + 0x118));
            *(void **)(param_1 + 0x118) = pvVar2;
            *(int *)(param_1 + 0x124) = iStack_4 + 1;
          }
        }
        *(undefined4 *)(*param_3 + iStack_c * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x118) + iStack_4 * 4);
        iStack_c = iStack_c + 1;
        *(int *)(*param_4 + -4 + iStack_c * 4) = (int)pRVar4->owner->id;
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < *(int *)(param_1 + 0x11c));
  }
  return iStack_c;
}

// --------------------------------------------------

// Function: FUN_004d9963
// Address: 004d9963
int __thiscall FUN_004d9963(int param_1,uint param_2,int *param_3,int param_4)
{
  int *piVar1;
  RGE_Static_Object *pRVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iStack_8;
  int iStack_4;
  
  piVar1 = param_3;
  *param_3 = 0;
  iStack_8 = 0;
  iVar5 = 10;
  param_3 = (int *)0x0;
  if (0 < *(int *)(param_1 + 0x110)) {
    iStack_4 = 0;
    do {
      iVar4 = *(int *)(*(int *)(param_1 + 0x114) + iStack_4);
      if (iVar4 != -1) {
        pRVar2 = RGE_Game_World::object
                           (*(RGE_Game_World **)
                             (*(int *)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x3c),iVar4);
        if (((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->owner->id == param_4)) &&
           ((param_2 == 0xffffffff ||
            (param_2 == *(byte *)(*(int *)(param_1 + 0x114) + 0xb + iStack_4))))) {
          if ((iStack_8 == iVar5) || (*piVar1 == 0)) {
            pvVar3 = operator_new(iVar5 * 8);
            if ((*piVar1 != 0) && (iVar4 = 0, 0 < iVar5)) {
              do {
                iVar4 = iVar4 + 1;
                *(undefined4 *)((int)pvVar3 + iVar4 * 4 + -4) =
                     *(undefined4 *)(*piVar1 + -4 + iVar4 * 4);
              } while (iVar4 < iVar5);
            }
            iVar5 = iVar5 * 2;
            if ((void *)*piVar1 != (void *)0x0) {
              operator_delete((void *)*piVar1);
            }
            *piVar1 = (int)pvVar3;
          }
          *(undefined4 *)(*piVar1 + iStack_8 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x114) + iStack_4);
          iStack_8 = iStack_8 + 1;
        }
      }
      param_3 = (int *)((int)param_3 + 1);
      iStack_4 = iStack_4 + 0x24;
    } while ((int)param_3 < *(int *)(param_1 + 0x110));
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_004d9a87
// Address: 004d9a87
int __thiscall FUN_004d9a87(int param_1,uint param_2,int param_3)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = 0;
  iVar3 = 0;
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x114) + iVar4);
      if ((((iVar1 != -1) &&
           (pRVar2 = RGE_Game_World::object
                               (*(RGE_Game_World **)
                                 (*(int *)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x3c),iVar1),
           pRVar2 != (RGE_Static_Object *)0x0)) && (pRVar2->owner->id == param_3)) &&
         ((param_2 == 0xffffffff || (param_2 == *(byte *)(*(int *)(param_1 + 0x114) + 0xb + iVar4)))
         )) {
        iStack_4 = iStack_4 + 1;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x24;
    } while (iVar3 < *(int *)(param_1 + 0x110));
  }
  return iStack_4;
}

// --------------------------------------------------

// Function: FUN_004d9b14
// Address: 004d9b14
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004d9b14(TribeInformationAIModule *param_1,BaseItem *param_2,float param_3,float param_4,
            uint param_5,int param_6)
{
  TRIBE_Player *pTVar1;
  RGE_Visible_Map *this;
  int iVar2;
  uint uVar3;
  int iVar4;
  uchar uVar5;
  byte bVar6;
  RGE_Zone_Map *this_00;
  int iVar7;
  int iVar8;
  int iVar9;
  ConstructionItem *pCVar10;
  char *pcVar11;
  undefined4 uVar12;
  int iVar13;
  byte *pbVar14;
  undefined4 *unaff_FS_OFFSET;
  float fVar15;
  float fVar16;
  float fVar17;
  int iStack_140;
  float fStack_13c;
  int iStack_134;
  float fStack_128;
  int iStack_124;
  int iStack_11c;
  int iStack_110;
  byte abStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_005604ee;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = param_1->md->aiPlayer;
  iVar7 = param_1->md->_padding_;
  this = (RGE_Visible_Map *)pTVar1->_padding_;
  iVar2 = *(int *)(pTVar1->_padding_ + 0x28);
  pbVar14 = abStack_10c;
  for (iVar13 = 0x40; iVar13 != 0; iVar13 = iVar13 + -1) {
    pbVar14[0] = 0xff;
    pbVar14[1] = 0xff;
    pbVar14[2] = 0xff;
    pbVar14[3] = 0xff;
    pbVar14 = pbVar14 + 4;
  }
  iVar13 = *(int *)(iVar7 + 0x3c);
  iStack_134 = -1;
  iStack_124 = -1;
  fStack_128 = -1.0;
  this_00 = RGE_Zone_Map_List::get_zone_map
                      (*(RGE_Zone_Map_List **)(iVar2 + 0x8dc4),
                       *(float **)
                        (*(int *)(iVar13 + 0x54) +
                        *(short *)(*(int *)(*(int *)(iVar7 + 0x24) + 0x4c) + 0x66) * 4),
                       (int)*(short *)(iVar13 + 0x52),&iStack_110);
  iVar7 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x6a9);
  iStack_11c = 1;
  if (1 < this->widthValue + -2) {
    do {
      iStack_140 = 1;
      if (1 < this->heightValue + -2) {
        do {
          uVar5 = RGE_Visible_Map::get_visible(this,iStack_11c,iStack_140);
          iVar13 = iStack_134;
          fVar15 = fStack_128;
          iVar4 = iStack_124;
          if (((((uVar5 != '\0') && (-1 < iStack_11c + -1)) && (-1 < iStack_140 + -1)) &&
              ((iStack_11c + 1 <= this->widthValue + -1 &&
               (iStack_140 + 1 <= this->heightValue + -1)))) &&
             ((param_5 == 0xffffffff ||
              ((*(byte *)(*(int *)(*(int *)(iVar2 + 0x8d8c) + iStack_140 * 4) + 5 +
                         iStack_11c * 0x18) & 0x1f) == param_5)))) {
            bVar6 = RGE_Zone_Map::get_zone_info(this_00,iStack_11c,iStack_140);
            iVar8 = RGE_Zone_Map::numberTilesInZone(this_00,bVar6);
            iVar9 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x70);
            if ((iVar9 <= iVar8) &&
               (iVar8 = TribeInformationAIModule::hasAdjacentTileType
                                  (param_1,iStack_11c,iStack_140,param_6), iVar8 != 0)) {
              pCVar10 = ConstructionAIModule::randomLot
                                  ((ConstructionAIModule *)&param_1->md->constructionAI,
                                   (float)iStack_11c - _DAT_00575570,
                                   (float)iStack_140 - _DAT_00575570);
              if (pCVar10 == (ConstructionItem *)0x0) {
                uVar3 = (uint)bVar6;
                fStack_13c = ((float)iStack_140 - param_4) * ((float)iStack_140 - param_4) +
                             ((float)iStack_11c - param_3) * ((float)iStack_11c - param_3);
                if (abStack_10c[uVar3] == 0xff) {
                  iVar13 = TribeInformationAIModule::numberDocksInZone(param_1,uVar3,this_00);
                  abStack_10c[uVar3] = (byte)iVar13;
                }
                bVar6 = abStack_10c[uVar3];
                if (bVar6 != 0) {
                  fStack_13c = (float)((uint)bVar6 * 1000) + fStack_13c;
                }
                iVar13 = TribeInformationAIModule::closestDockDistance
                                   (param_1,iStack_11c,iStack_140);
                if (iVar13 != -1) {
                  fStack_13c = (float)(int)(100000 / (longlong)iVar13) + fStack_13c;
                }
                iVar13 = iStack_11c;
                fVar15 = fStack_13c;
                iVar4 = iStack_140;
                if ((iStack_134 != -1) &&
                   (iVar13 = iStack_11c, fVar15 = fStack_13c, iVar4 = iStack_140,
                   (float)(iVar7 % 0x32) + fStack_128 <= fStack_13c)) {
                  iVar13 = iStack_134;
                  fVar15 = fStack_128;
                  iVar4 = iStack_124;
                }
              }
            }
          }
          iStack_124 = iVar4;
          fStack_128 = fVar15;
          iStack_134 = iVar13;
          iStack_140 = iStack_140 + 1;
        } while (iStack_140 < this->heightValue + -2);
      }
      iStack_11c = iStack_11c + 1;
    } while (iStack_11c < this->widthValue + -2);
  }
  if (iStack_134 != -1) {
    pCVar10 = (ConstructionItem *)operator_new(0x80);
    uStack_4 = 0;
    if (pCVar10 != (ConstructionItem *)0x0) {
      pcVar11 = BaseItem::name(param_2);
      iVar7 = BaseItem::typeID(param_2);
      fVar15 = BaseItem::zSize(param_2);
      fVar16 = BaseItem::ySize(param_2);
      fVar17 = BaseItem::xSize(param_2);
      uVar12 = ConstructionItem::ConstructionItem
                         (pCVar10,(float)iStack_134 - _DAT_00575570,
                          (float)iStack_124 - _DAT_00575570,0.0,fVar17,fVar16,fVar15,iVar7,pcVar11);
      goto LAB_004d9e9f;
    }
  }
  uVar12 = 0;
LAB_004d9e9f:
  *unaff_FS_OFFSET = uStack_c;
  return uVar12;
}

// --------------------------------------------------

// Function: FUN_004d9eba
// Address: 004d9eba
int __thiscall FUN_004d9eba(int param_1,uint param_2,RGE_Zone_Map *param_3)
{
  byte bVar1;
  void *pvVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  int iStack_8;
  
  iVar7 = 0;
  iStack_8 = 0;
  if (0 < *(int *)(param_1 + 0x194)) {
    do {
      if (*(int *)(param_1 + 0x19c) + -1 < iVar7) {
        pvVar2 = operator_new(iVar7 * 4 + 4);
        if (pvVar2 != (void *)0x0) {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x19c)) {
            do {
              if (iVar7 + 1 <= iVar3) break;
              iVar3 = iVar3 + 1;
              *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 400) + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)(param_1 + 0x19c));
          }
          operator_delete(*(void **)(param_1 + 400));
          *(void **)(param_1 + 400) = pvVar2;
          *(int *)(param_1 + 0x19c) = iVar7 + 1;
        }
      }
      pRVar4 = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0x100),
                          *(int *)(*(int *)(param_1 + 400) + iVar7 * 4));
      if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->master_obj->id == 0x2d)) {
        lVar5 = __ftol();
        lVar6 = __ftol();
        bVar1 = RGE_Zone_Map::get_zone_info(param_3,lVar6,lVar5);
        if (bVar1 == param_2) {
          iStack_8 = iStack_8 + 1;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x194));
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_004d9fb9
// Address: 004d9fb9
int __fastcall FUN_004d9fb9(int param_1)
{
  void *pvVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  int iStack_8;
  
  iVar4 = 0;
  iStack_8 = -1;
  if (0 < *(int *)(param_1 + 0x194)) {
    do {
      if (*(int *)(param_1 + 0x19c) + -1 < iVar4) {
        pvVar1 = operator_new(iVar4 * 4 + 4);
        if (pvVar1 != (void *)0x0) {
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x19c)) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar2 = iVar2 + 1;
              *(undefined4 *)((int)pvVar1 + iVar2 * 4 + -4) =
                   *(undefined4 *)(*(int *)(param_1 + 400) + -4 + iVar2 * 4);
            } while (iVar2 < *(int *)(param_1 + 0x19c));
          }
          operator_delete(*(void **)(param_1 + 400));
          *(void **)(param_1 + 400) = pvVar1;
          *(int *)(param_1 + 0x19c) = iVar4 + 1;
        }
      }
      pRVar3 = MainDecisionAIModule::object
                         (*(MainDecisionAIModule **)(param_1 + 0x100),
                          *(int *)(*(int *)(param_1 + 400) + iVar4 * 4));
      if ((pRVar3 != (RGE_Static_Object *)0x0) && (pRVar3->master_obj->id == 0x2d)) {
        __ftol();
        __ftol();
        iVar2 = __ftol();
        if ((iVar2 != 0) && ((iStack_8 == -1 || (iVar2 < iStack_8)))) {
          iStack_8 = iVar2;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x194));
  }
  return iStack_8;
}

// --------------------------------------------------

// Function: FUN_004da0d7
// Address: 004da0d7
undefined4 __thiscall FUN_004da0d7(int param_1,int param_2,int param_3,uint param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x3c) + 0x28);
  iVar2 = param_2;
  iVar3 = param_3;
  do {
    switch(iVar4) {
    case 0:
      iVar2 = param_2 + -1;
      iVar3 = param_3;
    case 7:
      iVar3 = iVar3 + -1;
      break;
    case 1:
    case 2:
      iVar2 = iVar2 + 1;
      break;
    case 3:
    case 4:
      iVar3 = iVar3 + 1;
      break;
    case 5:
    case 6:
      iVar2 = iVar2 + -1;
    }
    if ((((-1 < iVar2) && (-1 < iVar3)) && (iVar2 <= *(int *)(iVar1 + 8) + -1)) &&
       ((iVar3 <= *(int *)(iVar1 + 0xc) + -1 &&
        ((*(byte *)(*(int *)(*(int *)(iVar1 + 0x8d8c) + iVar3 * 4) + 5 + iVar2 * 0x18) & 0x1f) ==
         param_4)))) {
      return 1;
    }
    iVar4 = iVar4 + 1;
    if (7 < iVar4) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004da16d
// Address: 004da16d
undefined4 __fastcall FUN_004da16d(char *param_1,int param_2)
{
  char cVar1;
  undefined4 in_EAX;
  char unaff_BL;
  int unaff_EDI;
  char in_CF;
  char *pcVar2;
  
  cVar1 = (char)((uint)in_EAX >> 8);
  param_1[-0x5e9bffb3] = param_1[-0x5e9bffb3] + cVar1 + in_CF;
  param_1[0x4d] = param_1[0x4d] + cVar1;
  *(char *)(unaff_EDI + -0x5f) = *(char *)(unaff_EDI + -0x5f) + cVar1;
  *(char *)(unaff_EDI + -0x5f) = *(char *)(unaff_EDI + -0x5f) + cVar1;
  cVar1 = (char)((uint)param_1 >> 8);
  *(char *)(param_2 + -0x5f) = *(char *)(param_2 + -0x5f) + cVar1;
  *(char *)(param_2 + -0x5f) = *(char *)(param_2 + -0x5f) + cVar1;
  *param_1 = *param_1 + unaff_BL;
  cVar1 = (char)uRamb983004d + '\x01';
  pcVar2 = (char *)CONCAT31((int3)((uint)uRamb983004d >> 8),cVar1);
  *pcVar2 = *pcVar2 + cVar1;
  *(undefined4 *)(param_1 + 0x104) =
       *(undefined4 *)
        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x3c) + 0x28) + 8);
  return *(undefined4 *)(param_1 + 0x104);
}

// --------------------------------------------------

// Function: FUN_004da1bb
// Address: 004da1bb
undefined4 __fastcall FUN_004da1bb(int param_1)
{
  if (*(int *)(param_1 + 0x108) == -1) {
    *(undefined4 *)(param_1 + 0x108) =
         *(undefined4 *)
          (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x1256c) + 0x3c) + 0x28) + 0xc);
  }
  return *(undefined4 *)(param_1 + 0x108);
}

// --------------------------------------------------

// Function: FUN_004da1eb
// Address: 004da1eb
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004da1eb(TribeInformationAIModule *param_1,uint param_2,int param_3)
{
  byte bVar1;
  int *piVar2;
  RGE_Static_Object *pRVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_28;
  int iStack_24;
  XYPoint XStack_20;
  XYPoint XStack_18;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  iStack_24 = 0;
  if (0 < param_1->maxImportantObjectMemory) {
    iStack_28 = 0;
    do {
      piVar2 = (int *)((int)&param_1->importantObjectMemory->id + iStack_28);
      if (((*(byte *)((int)piVar2 + 0xb) == param_2) && (iVar5 = *piVar2, iVar5 != param_3)) &&
         (pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar5),
         pRVar3 != (RGE_Static_Object *)0x0)) {
        XStack_10.x = __ftol();
        XStack_10.y = __ftol();
        TribeInformationAIModule::mapBound(param_1,&XStack_10);
        XStack_20.x = __ftol();
        XStack_20.y = __ftol();
        TribeInformationAIModule::mapBound(param_1,&XStack_20);
        iVar5 = XStack_20.y;
        iVar6 = XStack_10.y;
        iVar8 = XStack_10.x;
        if (XStack_10.x <= XStack_20.x) {
          do {
            iVar7 = iVar6;
            if (iVar6 <= iVar5) {
              do {
                bVar1 = PathingSystem::lookupMisc(&aiPathSystem,iVar8,iVar6);
                uVar4 = bVar1 + 10;
                if (0xff < uVar4) {
                  uVar4 = 0xff;
                }
                PathingSystem::setMisc(&aiPathSystem,iVar8,iVar6,(uchar)uVar4);
                iVar6 = iVar6 + 1;
                iVar5 = XStack_20.y;
                iVar7 = XStack_10.y;
              } while (iVar6 <= XStack_20.y);
            }
            iVar8 = iVar8 + 1;
            iVar6 = iVar7;
          } while (iVar8 <= XStack_20.x);
        }
        if (_DAT_00575564 < *(float *)((int)&param_1->importantObjectMemory->range + iStack_28)) {
          XStack_8.x = __ftol();
          XStack_8.y = __ftol();
          TribeInformationAIModule::mapBound(param_1,&XStack_8);
          XStack_18.x = __ftol();
          XStack_18.y = __ftol();
          TribeInformationAIModule::mapBound(param_1,&XStack_18);
          iVar5 = XStack_18.y;
          iVar6 = XStack_8.y;
          iVar8 = XStack_8.x;
          if (XStack_8.x <= XStack_18.x) {
            do {
              iVar7 = iVar6;
              if (iVar6 <= iVar5) {
                do {
                  bVar1 = PathingSystem::lookupMisc(&aiPathSystem,iVar8,iVar6);
                  uVar4 = bVar1 + 10;
                  if (0xff < uVar4) {
                    uVar4 = 0xff;
                  }
                  PathingSystem::setMisc(&aiPathSystem,iVar8,iVar6,(uchar)uVar4);
                  iVar6 = iVar6 + 1;
                  iVar5 = XStack_18.y;
                  iVar7 = XStack_8.y;
                } while (iVar6 <= XStack_18.y);
              }
              iVar8 = iVar8 + 1;
              iVar6 = iVar7;
            } while (iVar8 <= XStack_18.x);
          }
        }
      }
      iStack_24 = iStack_24 + 1;
      iStack_28 = iStack_28 + 0x24;
    } while (iStack_24 < param_1->maxImportantObjectMemory);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004da413
// Address: 004da413
void __thiscall FUN_004da413(TribeInformationAIModule *param_1,uint param_2)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iStack_14;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  iVar4 = 0;
  iStack_14 = 0;
  if (0 < param_1->maxAttackMemories) {
    do {
      piVar1 = (int *)((int)&param_1->attackMemories->id + iVar4);
      if (((*piVar1 != -1) && (*(byte *)((int)piVar1 + 10) == param_2)) &&
         ((ushort)*(byte *)((int)piVar1 + 9) == *(ushort *)(param_1->md->_padding_ + 0x4a))) {
        XStack_8.x = (int)*(byte *)((int)piVar1 + 5);
        XStack_8.y = (int)*(byte *)((int)piVar1 + 6);
        TribeInformationAIModule::mapBound(param_1,&XStack_8);
        XStack_10.x = (int)(&param_1->attackMemories->maxX)[iVar4];
        XStack_10.y = (int)(&param_1->attackMemories->maxY)[iVar4];
        TribeInformationAIModule::mapBound(param_1,&XStack_10);
        uVar2 = XStack_10.y;
        uVar8 = XStack_8.x;
        if (XStack_8.x <= XStack_10.x) {
          do {
            uVar5 = XStack_8.y;
            if (XStack_8.y <= (int)uVar2) {
              do {
                PathingSystem::setMisc(&aiPathSystem,uVar8,uVar5,'K');
                uVar5 = uVar5 + 1;
                uVar2 = XStack_10.y;
              } while ((int)uVar5 <= XStack_10.y);
            }
            uVar8 = uVar8 + 1;
          } while ((int)uVar8 <= XStack_10.x);
        }
        XStack_8.x = XStack_8.x - 5;
        XStack_8.y = XStack_8.y - 5;
        TribeInformationAIModule::mapBound(param_1,&XStack_8);
        XStack_10.x = XStack_10.x + 5;
        XStack_10.y = XStack_10.y + 5;
        TribeInformationAIModule::mapBound(param_1,&XStack_10);
        iVar3 = XStack_10.y;
        iVar6 = XStack_8.y;
        iVar9 = XStack_8.x;
        if (XStack_8.x <= XStack_10.x) {
          do {
            iVar7 = iVar6;
            if (iVar6 <= iVar3) {
              do {
                PathingSystem::setMisc(&aiPathSystem,iVar9,iVar6,'\x0f');
                iVar6 = iVar6 + 1;
                iVar3 = XStack_10.y;
                iVar7 = XStack_8.y;
              } while (iVar6 <= XStack_10.y);
            }
            iVar9 = iVar9 + 1;
            iVar6 = iVar7;
          } while (iVar9 <= XStack_10.x);
        }
      }
      iStack_14 = iStack_14 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iStack_14 < param_1->maxAttackMemories);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004da59d
// Address: 004da59d
int * __thiscall FUN_004da59d(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  if (param_2 != -1) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x110)) {
      piVar2 = *(int **)(param_1 + 0x114);
      do {
        if (*piVar2 == param_2) {
          return *(int **)(param_1 + 0x114) + iVar1 * 9;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 9;
      } while (iVar1 < *(int *)(param_1 + 0x110));
      return (int *)0x0;
    }
  }
  return (int *)0x0;
}

// --------------------------------------------------

// Function: FUN_004da5e4
// Address: 004da5e4
ObjectMemory * __thiscall FUN_004da5e4(TribeInformationAIModule *param_1,RGE_Static_Object *param_2)
{
  RGE_Master_Static_Object *pRVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  short sVar5;
  ObjectMemory *pOVar6;
  float10 fVar7;
  uchar uVar8;
  int iVar9;
  uchar uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  RGE_Static_Object *pRVar14;
  
  if (param_2 == (RGE_Static_Object *)0x0) {
    return (ObjectMemory *)0x0;
  }
  iVar9 = param_2->_padding_;
  pRVar1 = param_2->master_obj;
  pRVar14 = param_2;
  fVar7 = (float10)(**(code **)(iVar9 + 0x10c))();
  fVar13 = (float)fVar7;
  fVar7 = (float10)(**(code **)(iVar9 + 0x100))();
  fVar12 = (float)fVar7;
  fVar7 = (float10)(**(code **)(iVar9 + 0x108))();
  fVar11 = (float)fVar7;
  uVar10 = '\0';
  iVar9 = 0;
  sVar5 = __ftol();
  uVar8 = (uchar)param_2->owner->id;
  uVar2 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  pOVar6 = TribeInformationAIModule::addObjectMemory
                     (param_1,param_2->id,pRVar1->id,pRVar1->object_group,uVar4,uVar3,uVar2,uVar8,
                      sVar5,iVar9,uVar10,fVar11,fVar12,fVar13,pRVar14);
  return pOVar6;
}

// --------------------------------------------------

// Function: FUN_004da67a
// Address: 004da67a
ObjectMemory * __thiscall
FUN_004da67a(TribeInformationAIModule *param_1,int param_2,short param_3,short param_4,uchar param_5
            ,uchar param_6,uchar param_7,uchar param_8,short param_9,int param_10,uchar param_11,
            float param_12,float param_13,float param_14,RGE_Static_Object *param_15)
{
  int iVar1;
  ObjectMemory *pOVar2;
  short *psVar3;
  ushort uVar4;
  int iVar5;
  
  iVar5 = -1;
  iVar1 = 0;
  if (0 < param_1->maxImportantObjectMemory) {
    pOVar2 = param_1->importantObjectMemory;
    do {
      if (pOVar2->id == param_2) {
        param_1->importantObjectMemory[iVar1].id = param_2;
        param_1->importantObjectMemory[iVar1].type = param_3;
        param_1->importantObjectMemory[iVar1].group = param_4;
        param_1->importantObjectMemory[iVar1].x = param_5;
        param_1->importantObjectMemory[iVar1].y = param_6;
        param_1->importantObjectMemory[iVar1].z = param_7;
        param_1->importantObjectMemory[iVar1].owner = param_8;
        param_1->importantObjectMemory[iVar1].hitPoints = param_9;
        param_1->importantObjectMemory[iVar1].attackAttempts = param_10;
        param_1->importantObjectMemory[iVar1].kills = param_11;
        param_1->importantObjectMemory[iVar1].damageCapability = param_12;
        param_1->importantObjectMemory[iVar1].rateOfFire = param_13;
        param_1->importantObjectMemory[iVar1].range = param_14;
        return param_1->importantObjectMemory + iVar1;
      }
      if ((pOVar2->id == -1) && (iVar5 == -1)) {
        iVar5 = iVar1;
      }
      iVar1 = iVar1 + 1;
      pOVar2 = pOVar2 + 1;
    } while (iVar1 < param_1->maxImportantObjectMemory);
  }
  if (param_15 != (RGE_Static_Object *)0x0) {
    uVar4 = (ushort)*(byte *)(*(int *)(param_1->md->_padding_ + 0x3c) + 0x11d);
    iVar1 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xc9);
    if ((iVar1 == 1) && ((uVar4 == *(ushort *)(param_1->md->_padding_ + 0x4a) || (uVar4 == 0xff))))
{
      if (0 < param_15->owner->id) {
        iVar1 = RGE_Player::computerPlayer(param_15->owner);
        if (iVar1 == 0) {
          iVar1 = RGE_Base_Game::singlePlayerGame(rge_base_game);
          if (iVar1 == 1) {
            iVar1 = TribeInformationAIModule::convertUnitToIntType(param_1,param_15);
            if (iVar1 != -1) {
              param_1->unitHistory[iVar1] = param_1->unitHistory[iVar1] + 1;
            }
          }
        }
      }
    }
  }
  if (iVar5 == -1) {
    pOVar2 = (ObjectMemory *)operator_new(param_1->maxImportantObjectMemory * 0x48);
    if (pOVar2 == (ObjectMemory *)0x0) {
      return (ObjectMemory *)0x0;
    }
    iVar5 = 0;
    if (0 < param_1->maxImportantObjectMemory) {
      iVar1 = 0;
      psVar3 = &pOVar2->group;
      do {
        iVar5 = iVar5 + 1;
        ((ObjectMemory *)(psVar3 + -3))->id =
             *(int *)((int)&param_1->importantObjectMemory->id + iVar1);
        psVar3[-1] = *(short *)((int)&param_1->importantObjectMemory->type + iVar1);
        *psVar3 = *(short *)((int)&param_1->importantObjectMemory->group + iVar1);
        *(uchar *)(psVar3 + 1) = (&param_1->importantObjectMemory->x)[iVar1];
        *(uchar *)((int)psVar3 + 3) = (&param_1->importantObjectMemory->y)[iVar1];
        *(uchar *)(psVar3 + 2) = (&param_1->importantObjectMemory->z)[iVar1];
        *(uchar *)((int)psVar3 + 5) = (&param_1->importantObjectMemory->owner)[iVar1];
        psVar3[3] = *(short *)((int)&param_1->importantObjectMemory->hitPoints + iVar1);
        *(int *)(psVar3 + 5) =
             *(int *)((int)&param_1->importantObjectMemory->attackAttempts + iVar1);
        *(uchar *)(psVar3 + 7) = (&param_1->importantObjectMemory->kills)[iVar1];
        *(float *)(psVar3 + 9) =
             *(float *)((int)&param_1->importantObjectMemory->damageCapability + iVar1);
        *(float *)(psVar3 + 0xb) =
             *(float *)((int)&param_1->importantObjectMemory->rateOfFire + iVar1);
        *(float *)(psVar3 + 0xd) = *(float *)((int)&param_1->importantObjectMemory->range + iVar1);
        iVar1 = iVar1 + 0x24;
        psVar3 = psVar3 + 0x12;
      } while (iVar5 < param_1->maxImportantObjectMemory);
    }
    if (iVar5 < param_1->maxImportantObjectMemory * 2) {
      psVar3 = &pOVar2[iVar5].group;
      do {
        iVar5 = iVar5 + 1;
        ((ObjectMemory *)(psVar3 + -3))->id = -1;
        psVar3[-1] = -1;
        *psVar3 = -1;
        *(uchar *)(psVar3 + 1) = '\0';
        *(uchar *)((int)psVar3 + 3) = '\0';
        *(uchar *)(psVar3 + 2) = '\0';
        *(uchar *)((int)psVar3 + 5) = '\0';
        psVar3[3] = 0;
        *(int *)(psVar3 + 5) = 0;
        *(uchar *)(psVar3 + 7) = '\0';
        *(float *)(psVar3 + 9) = 0.0;
        *(float *)(psVar3 + 0xb) = 0.0;
        *(float *)(psVar3 + 0xd) = 0.0;
        psVar3 = psVar3 + 0x12;
      } while (iVar5 < param_1->maxImportantObjectMemory * 2);
    }
    operator_delete(param_1->importantObjectMemory);
    param_1->importantObjectMemory = pOVar2;
    pOVar2[param_1->maxImportantObjectMemory].id = param_2;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].type = param_3;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].group = param_4;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].x = param_5;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].y = param_6;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].z = param_7;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].owner = param_8;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].hitPoints = param_9;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].attackAttempts = param_10;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].kills = param_11;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].damageCapability = param_12;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].rateOfFire = param_13;
    param_1->importantObjectMemory[param_1->maxImportantObjectMemory].range = param_14;
    iVar5 = param_1->maxImportantObjectMemory;
    param_1->maxImportantObjectMemory = iVar5 * 2;
    return param_1->importantObjectMemory + iVar5;
  }
  param_1->importantObjectMemory[iVar5].id = param_2;
  param_1->importantObjectMemory[iVar5].type = param_3;
  param_1->importantObjectMemory[iVar5].group = param_4;
  param_1->importantObjectMemory[iVar5].x = param_5;
  param_1->importantObjectMemory[iVar5].y = param_6;
  param_1->importantObjectMemory[iVar5].z = param_7;
  param_1->importantObjectMemory[iVar5].owner = param_8;
  param_1->importantObjectMemory[iVar5].hitPoints = param_9;
  param_1->importantObjectMemory[iVar5].attackAttempts = param_10;
  param_1->importantObjectMemory[iVar5].kills = param_11;
  param_1->importantObjectMemory[iVar5].damageCapability = param_12;
  param_1->importantObjectMemory[iVar5].rateOfFire = param_13;
  param_1->importantObjectMemory[iVar5].range = param_14;
  return param_1->importantObjectMemory + iVar5;
}

// --------------------------------------------------

// Function: FUN_004daba4
// Address: 004daba4
undefined4 __thiscall
FUN_004daba4(TribeInformationAIModule *param_1,RGE_Static_Object *param_2,int param_3)
{
  RGE_Player *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  if ((param_2 != (RGE_Static_Object *)0x0) && (-1 < param_2->id)) {
    iVar1 = (int)param_2->master_obj->object_group;
    iVar2 = TribeInformationAIModule::importantObject(param_1,iVar1);
    if (iVar2 != 0) {
      iVar3 = (int)param_2->owner->id;
      piVar5 = (int *)param_1->md->_padding_;
      iVar2 = piVar5[0xf];
      if ((((param_3 == 0) && (0 < iVar3)) &&
          (iVar3 = (**(code **)(*piVar5 + 0x18))(iVar3), iVar3 != 0)) &&
         (3 < *(short *)(iVar2 + 0x3c))) {
        iVar3 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xc2);
        iVar7 = 1;
        if ((iVar3 == 1) && (1 < *(short *)(iVar2 + 0x3c))) {
          do {
            if (iVar7 != *(short *)(param_1->md->_padding_ + 0x4a)) {
              this = *(RGE_Player **)(*(int *)(iVar2 + 0x40) + iVar7 * 4);
              iVar3 = RGE_Player::computerPlayer(this);
              if (((iVar3 != 0) &&
                  (iVar3 = (**(code **)(*(int *)param_1->md->_padding_ + 0x1c))(iVar7), iVar3 != 0))
                 && (iVar3 = (**(code **)(this->_padding_ + 0x1c))
                                       ((int)*(short *)(param_1->md->_padding_ + 0x4a)), iVar3 != 0)
                 ) {
                TribeInformationAIModule::addImportantObject
                          ((TribeInformationAIModule *)(this[1].position_checksum + 0xcec),param_2,1
                          );
              }
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(short *)(iVar2 + 0x3c));
        }
      }
      iVar7 = TribeInformationAIModule::checkDefend(param_1,param_2);
      iVar2 = (param_1->importantObjects).numberValue;
      iVar3 = param_2->id;
      iVar4 = 0;
      if (0 < iVar2) {
        do {
          if ((param_1->importantObjects).maximumSizeValue <= iVar4) break;
          if ((param_1->importantObjects).value[iVar4] == iVar3) goto LAB_004dad90;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar2);
      }
      if ((param_1->importantObjects).maximumSizeValue + -1 < iVar2) {
        iVar2 = iVar2 + 1;
        piVar5 = (int *)operator_new(iVar2 * 4);
        if (piVar5 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (param_1->importantObjects).maximumSizeValue) {
            do {
              if (iVar2 <= iVar4) break;
              iVar6 = iVar4 + 1;
              piVar5[iVar4] = (param_1->importantObjects).value[iVar4];
              iVar4 = iVar6;
            } while (iVar6 < (param_1->importantObjects).maximumSizeValue);
          }
          operator_delete((param_1->importantObjects).value);
          (param_1->importantObjects).value = piVar5;
          (param_1->importantObjects).maximumSizeValue = iVar2;
        }
      }
      (param_1->importantObjects).value[(param_1->importantObjects).numberValue] = iVar3;
      (param_1->importantObjects).numberValue = (param_1->importantObjects).numberValue + 1;
LAB_004dad90:
      iVar2 = TribeInformationAIModule::importantUnit(param_1,iVar1);
      if (iVar2 == 1) {
        iVar2 = (param_1->importantUnits).numberValue;
        iVar3 = param_2->id;
        iVar4 = 0;
        if (0 < iVar2) {
          do {
            if ((param_1->importantUnits).maximumSizeValue <= iVar4) break;
            if ((param_1->importantUnits).value[iVar4] == iVar3) goto LAB_004daf3b;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar2);
        }
        if ((param_1->importantUnits).maximumSizeValue + -1 < iVar2) {
          iVar2 = iVar2 + 1;
          piVar5 = (int *)operator_new(iVar2 * 4);
          if (piVar5 != (int *)0x0) {
            iVar4 = 0;
            if (0 < (param_1->importantUnits).maximumSizeValue) {
              do {
                if (iVar2 <= iVar4) break;
                iVar6 = iVar4 + 1;
                piVar5[iVar4] = (param_1->importantUnits).value[iVar4];
                iVar4 = iVar6;
              } while (iVar6 < (param_1->importantUnits).maximumSizeValue);
            }
            operator_delete((param_1->importantUnits).value);
            (param_1->importantUnits).value = piVar5;
            (param_1->importantUnits).maximumSizeValue = iVar2;
          }
        }
        (param_1->importantUnits).value[(param_1->importantUnits).numberValue] = iVar3;
        (param_1->importantUnits).numberValue = (param_1->importantUnits).numberValue + 1;
      }
      else {
        iVar2 = TribeInformationAIModule::importantResource(param_1,iVar1);
        if (iVar2 == 1) {
          TribeInformationAIModule::addResourceObject(param_1,param_2);
        }
        else {
          iVar2 = TribeInformationAIModule::importantMisc(param_1,iVar1);
          if (iVar2 == 1) {
            iVar2 = (param_1->importantMiscs).numberValue;
            iVar3 = param_2->id;
            iVar4 = 0;
            if (0 < iVar2) {
              do {
                if ((param_1->importantMiscs).maximumSizeValue <= iVar4) break;
                if ((param_1->importantMiscs).value[iVar4] == iVar3) goto LAB_004daf3b;
                iVar4 = iVar4 + 1;
              } while (iVar4 < iVar2);
            }
            if ((param_1->importantMiscs).maximumSizeValue + -1 < iVar2) {
              iVar2 = iVar2 + 1;
              piVar5 = (int *)operator_new(iVar2 * 4);
              if (piVar5 != (int *)0x0) {
                iVar4 = 0;
                if (0 < (param_1->importantMiscs).maximumSizeValue) {
                  do {
                    if (iVar2 <= iVar4) break;
                    iVar6 = iVar4 + 1;
                    piVar5[iVar4] = (param_1->importantMiscs).value[iVar4];
                    iVar4 = iVar6;
                  } while (iVar6 < (param_1->importantMiscs).maximumSizeValue);
                }
                operator_delete((param_1->importantMiscs).value);
                (param_1->importantMiscs).value = piVar5;
                (param_1->importantMiscs).maximumSizeValue = iVar2;
              }
            }
            (param_1->importantMiscs).value[(param_1->importantMiscs).numberValue] = iVar3;
            (param_1->importantMiscs).numberValue = (param_1->importantMiscs).numberValue + 1;
          }
        }
      }
LAB_004daf3b:
      iVar1 = TribeInformationAIModule::importantUnit(param_1,iVar1);
      if ((iVar1 == 1) || (iVar7 == 1)) {
        TribeInformationAIModule::addObjectMemory(param_1,param_2);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004daf72
// Address: 004daf72
void __thiscall FUN_004daf72(TribeInformationAIModule *param_1,int param_2)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_2);
  TribeInformationAIModule::addImportantObject(param_1,pRVar1,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004dafa1
// Address: 004dafa1
undefined4 __thiscall FUN_004dafa1(TribeInformationAIModule *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = TribeInformationAIModule::importantUnit(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = TribeInformationAIModule::importantResource(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = TribeInformationAIModule::importantMisc(param_1,param_2);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004dafe9
// Address: 004dafe9
undefined4 FUN_004dafe9(int param_1)
{
  if (((((((param_1 != 0) && (param_1 != 3)) && (param_1 != 4)) &&
        (((param_1 != 0x18 && (param_1 != 0x15)) &&
         ((param_1 != 6 && ((param_1 != 0x19 && (param_1 != 0x11)))))))) &&
       ((param_1 != 0x1a && (((param_1 != 0xc && (param_1 != 0x23)) && (param_1 != 0x17)))))) &&
      (((param_1 != 0x24 && (param_1 != 0x1c)) &&
       (((param_1 != 0x12 && ((param_1 != 0xd && (param_1 != 2)))) && (param_1 != 0x14)))))) &&
     (((param_1 != 0x1b && (param_1 != 0x16)) && (param_1 != 0x27)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004db069
// Address: 004db069
undefined4 FUN_004db069(int param_1)
{
  if (((((param_1 != 0x1f) && (param_1 != 5)) && (param_1 != 0x21)) &&
      ((param_1 != 7 && (param_1 != 9)))) &&
     ((param_1 != 8 && ((param_1 != 0x20 && (param_1 != 0xf)))))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004db0a9
// Address: 004db0a9
undefined4 FUN_004db0a9(int param_1)
{
  if ((param_1 != 1) && (param_1 != 0x1e)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004db0cb
// Address: 004db0cb
undefined4 FUN_004db0cb(int param_1)
{
  short sVar1;
  
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x14);
  if ((sVar1 != 3) && (sVar1 != 0x1b)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004db0f4
// Address: 004db0f4
undefined4 FUN_004db0f4(int param_1)
{
  short sVar1;
  
  if (*(short *)(*(int *)(param_1 + 8) + 0x14) != 3) {
    return 0;
  }
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x10);
  if (((((sVar1 != 0x6d) && (sVar1 != 0xc)) && (sVar1 != 0x57)) &&
      ((sVar1 != 0x31 && (sVar1 != 0x2d)))) &&
     ((sVar1 != 0 && ((sVar1 != 0x65 && (sVar1 != 0x68)))))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004db153
// Address: 004db153
undefined4 FUN_004db153(int param_1)
{
  short sVar1;
  
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x14);
  if ((((sVar1 != 0x15) && (sVar1 != 2)) && (sVar1 != 0x14)) && (sVar1 != 0x16)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004db1a4
// Address: 004db1a4
undefined4 FUN_004db1a4(int param_1)
{
  short sVar1;
  
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x10);
  if ((((sVar1 != 0x4f) && (sVar1 != 199)) && (sVar1 != 0x45)) &&
     ((sVar1 != 0x17f && (sVar1 != 0x17c)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004db1e6
// Address: 004db1e6
undefined4 __thiscall FUN_004db1e6(int param_1,undefined4 param_2,int param_3)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_3);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  sVar1 = pRVar2->master_obj->object_group;
  if ((((sVar1 != 0x15) && (sVar1 != 2)) && (sVar1 != 0x14)) &&
     ((sVar1 != 0x16 && (pRVar2->master_obj->id != 0x2d)))) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004db23a
// Address: 004db23a
undefined4 __thiscall FUN_004db23a(int param_1,undefined4 param_2,int param_3)
{
  short sVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_3);
  if ((((pRVar2 != (RGE_Static_Object *)0x0) &&
       (sVar1 = pRVar2->master_obj->object_group, sVar1 != 0x15)) && (sVar1 != 2)) &&
     ((sVar1 != 0x14 && (sVar1 != 0x16)))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004db288
// Address: 004db288
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
// [HELPER] s_Invalid_influence_placement_type: "Invalid influence placement type id (%d), bombing."
// [HELPER] s_____Unsupported_building_size___: "    Unsupported building size (%d x %d)."
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004db288(TribeInformationAIModule *param_1,BaseItem *param_2,int param_3,int param_4,
            float param_5,int *param_6,int param_7,int param_8,int param_9,int param_10,
            int *param_11,int param_12)
{
  XYPoint *pXVar1;
  bool bVar2;
  char cVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  int iVar6;
  BuildingLot *pBVar7;
  int iVar8;
  ulong uVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  AIModule *this;
  TribeMainDecisionAIModule *pTVar13;
  RGE_Static_Object *this_00;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 *unaff_FS_OFFSET;
  float fStack_198;
  int iStack_194;
  int iStack_190;
  int iStack_18c;
  AIModule *pAStack_184;
  int iStack_180;
  int iStack_178;
  int iStack_174;
  XYPoint XStack_170;
  XYPoint XStack_168;
  XYPoint XStack_160;
  RGE_Static_Object *pRStack_158;
  int iStack_154;
  ConstructionItem *pCStack_150;
  XYPoint XStack_14c;
  uint uStack_144;
  int iStack_140;
  int iStack_13c;
  XYPoint XStack_138;
  XYPoint XStack_130;
  XYPoint XStack_128;
  undefined4 uStack_120;
  int iStack_11c;
  XYPoint XStack_118;
  RGE_Master_Static_Object *pRStack_110;
  char acStack_10c [256];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560538;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = MainDecisionAIModule::object
                     ((MainDecisionAIModule *)param_1->md,-1,-1,4,-1,-1,-1,-1,-1,-1,-1);
  if (pRVar4 == (RGE_Static_Object *)0x0) {
    param_11[0x45] = 0;
  }
  else {
    if (param_11[0x45] == 1) {
      iStack_194 = *param_11;
      fStack_198 = (float)param_11[1];
      param_6 = param_11 + 2;
      uVar12 = 0xff;
    }
    else if (param_2 == (BaseItem *)0x0) {
      uVar12 = 0xff;
      iStack_194 = param_4;
      fStack_198 = param_5;
    }
    else {
      iStack_194 = BaseItem::typeID(param_2);
      fStack_198 = BaseItem::xSize(param_2);
      uVar12 = 0xff;
      param_6 = (int *)BaseItem::name(param_2);
    }
    strncpy(acStack_10c,param_6,uVar12);
    iStack_11c = __ftol();
    iVar5 = iStack_11c * iStack_11c * 0x14;
    pRStack_110 = ((RGE_Player *)param_1->md->_padding_)->master_objects[iStack_194];
    if (pRStack_110 != (RGE_Master_Static_Object *)0x0) {
      pRStack_158 = MainDecisionAIModule::object
                              ((MainDecisionAIModule *)param_1->md,-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
      iVar6 = param_3;
      if (param_11[0x45] == 1) {
        iVar6 = param_11[0x42];
      }
      MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar6);
      if ((param_2 == (BaseItem *)0x0) && (param_11[0x45] != 1)) {
        XStack_170.x = param_9;
        XStack_170.y = param_10;
      }
      else {
        XStack_170.x = __ftol();
        XStack_170.y = __ftol();
      }
      iVar6 = TribeInformationAIModule::placementCode(param_1,iStack_194);
      if (iVar6 == -1) {
        AIModule::logCommonHistory
                  (this,(char *)param_1,s_Invalid_influence_placement_type,iStack_194);
      }
      else {
        if ((param_2 == (BaseItem *)0x0) && (param_11[0x45] != 1)) {
          iStack_174 = param_8;
          iStack_154 = param_7;
          RGE_Static_Object::lookupZone(pRVar4,param_9,param_10);
        }
        else {
          if (iVar6 == 1) {
            iStack_154 = 7;
            iVar8 = TribeTacticalAIModule::inAge(&param_1->md->tacticalAI,2);
            if (iVar8 == 0) {
              iVar8 = TribeTacticalAIModule::inAge(&param_1->md->tacticalAI,3);
              if (iVar8 == 0) {
                iVar10 = TribeTacticalAIModule::inAge(&param_1->md->tacticalAI,4);
                iVar8 = 1;
                if (iVar10 != 0) {
                  iVar8 = 4;
                }
              }
              else {
                iVar8 = 3;
              }
            }
            else {
              iVar8 = 2;
            }
            iStack_174 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x56);
            iStack_174 = iStack_174 * iVar8;
            param_7 = iStack_154;
          }
          else if (iVar6 == 2) {
            iStack_154 = 4;
            iStack_174 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x57);
            param_7 = 4;
          }
          else {
            if ((iVar6 == 3) || (iVar6 == 4)) {
              iStack_154 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x49);
              pTVar13 = param_1->md;
            }
            else {
              iStack_154 = 4;
              pTVar13 = param_1->md;
            }
            param_7 = iStack_154;
            iStack_174 = TribeTacticalAIModule::strategicNumber(&pTVar13->tacticalAI,0x4a);
          }
          this_00 = pRStack_158;
          if (pRStack_158 == (RGE_Static_Object *)0x0) {
            this_00 = pRVar4;
          }
          RGE_Static_Object::currentZone(this_00);
        }
        if (param_7 < iStack_174) {
          XStack_138.x = XStack_170.x - iStack_174;
          XStack_138.y = XStack_170.y - iStack_174;
          TribeInformationAIModule::mapBound(param_1,&XStack_138);
          XStack_14c.x = iStack_174 + XStack_170.x;
          XStack_14c.y = iStack_174 + XStack_170.y;
          TribeInformationAIModule::mapBound(param_1,&XStack_14c);
          XStack_128.x = XStack_170.x - param_7;
          XStack_128.y = XStack_170.y - param_7;
          TribeInformationAIModule::mapBound(param_1,&XStack_128);
          XStack_130.x = param_7 + XStack_170.x;
          XStack_130.y = param_7 + XStack_170.y;
          TribeInformationAIModule::mapBound(param_1,&XStack_130);
          if (param_2 == (BaseItem *)0x0) {
LAB_004db819:
            if (param_11[0x45] == 0) {
              TribeInformationAIModule::setupInfluenceMap
                        (param_1,iVar6,iStack_194,&XStack_170,&XStack_138,&XStack_14c);
            }
          }
          else if (param_11[0x45] == 0) {
            pBVar7 = TribeInformationAIModule::availableLot(param_1,iStack_194);
            if (pBVar7 != (BuildingLot *)0x0) {
              if (iVar6 == 4) {
                iVar5 = (param_1->lastWallPosition).y;
                (param_1->lastWallPosition2).x = (param_1->lastWallPosition).x;
                (param_1->lastWallPosition2).y = iVar5;
                (param_1->lastWallPosition).x = (uint)pBVar7->x;
                (param_1->lastWallPosition).y = (uint)pBVar7->y;
              }
              if (fStack_198 == _DAT_00575574) {
                pCStack_150 = (ConstructionItem *)operator_new(0x80);
                uStack_4 = 0;
                if (pCStack_150 != (ConstructionItem *)0x0) {
                  uVar12 = ConstructionItem::ConstructionItem
                                     (pCStack_150,(float)pBVar7->x,(float)pBVar7->y,1.0,fStack_198,
                                      fStack_198,1.0,iStack_194,acStack_10c);
                  pBVar7->status = '\x01';
                  param_11[0x45] = 0;
                  goto LAB_004dc0d9;
                }
              }
              else {
                pCStack_150 = (ConstructionItem *)operator_new(0x80);
                uStack_4 = 1;
                if (pCStack_150 != (ConstructionItem *)0x0) {
                  uVar12 = ConstructionItem::ConstructionItem
                                     (pCStack_150,(float)pBVar7->x - _DAT_00575570,
                                      (float)pBVar7->y - _DAT_00575570,1.0,fStack_198,fStack_198,1.0
                                      ,iStack_194,acStack_10c);
                  pBVar7->status = '\x01';
                  param_11[0x45] = 0;
                  goto LAB_004dc0d9;
                }
              }
              uVar12 = 0;
              pBVar7->status = '\x01';
              param_11[0x45] = 0;
              goto LAB_004dc0d9;
            }
            goto LAB_004db819;
          }
          if (param_11[0x45] == 0) {
            iVar8 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xa8);
            if (iVar8 < 1) {
              iStack_18c = 0;
            }
            else {
              iStack_18c = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xac8);
              iStack_18c = iStack_18c % iVar8;
            }
            pAStack_184 = (AIModule *)0xffffffff;
            iStack_180 = -1;
            pRStack_158 = (RGE_Static_Object *)0xffffffff;
            iStack_190 = XStack_138.x;
          }
          else {
            iStack_18c = param_11[0x4a];
            pAStack_184 = (AIModule *)param_11[0x46];
            iStack_180 = param_11[0x47];
            pRStack_158 = (RGE_Static_Object *)param_11[0x48];
            iStack_190 = param_11[0x49];
          }
          pRVar4 = pRStack_158;
          uStack_144 = *(uint *)(*(int *)(param_1->md->_padding_ + 0x3c) + 0xf8);
          uVar9 = debug_timeGetTime(s_C__msdev_work_age1_x1_taiinfmd_c,0xade);
          if ((param_11[0x45] == 0) && (uStack_144 <= uVar9 - param_12)) {
            *param_11 = iStack_194;
            strncpy(param_11 + 2,acStack_10c,0xff);
            param_11[1] = (int)fStack_198;
            param_11[0x42] = param_3;
            param_11[0x43] = iStack_154;
            param_11[0x44] = iStack_174;
            param_11[0x46] = (int)pAStack_184;
            param_11[0x45] = 1;
            param_11[0x47] = iStack_180;
            param_11[0x48] = (int)pRVar4;
            param_11[0x49] = iStack_190;
            param_11[0x4a] = iStack_18c;
            param_11[0x4b] = (int)param_2;
            goto LAB_004dc0d7;
          }
          iStack_13c = 0;
          if ((iVar6 == 4) || (iVar6 == 3)) {
            iStack_13c = 1;
          }
          iStack_140 = 1;
          if (iStack_190 <= XStack_14c.x) {
            do {
              if (iStack_140 == 0) {
                uVar9 = debug_timeGetTime(s_C__msdev_work_age1_x1_taiinfmd_c,0xb16);
                if (uStack_144 <= uVar9 - param_12) {
                  *param_11 = iStack_194;
                  strncpy(param_11 + 2,acStack_10c,0xff);
                  param_11[1] = (int)fStack_198;
                  param_11[0x42] = param_3;
                  param_11[0x43] = iStack_154;
                  param_11[0x44] = iStack_174;
                  param_11[0x46] = (int)pAStack_184;
                  param_11[0x45] = 1;
                  param_11[0x47] = iStack_180;
                  param_11[0x48] = (int)pRVar4;
                  param_11[0x49] = iStack_190;
                  param_11[0x4a] = iStack_18c;
                  param_11[0x4b] = (int)param_2;
                  goto LAB_004dc0d7;
                }
              }
              else {
                iStack_140 = 0;
              }
              iStack_178 = XStack_138.y;
              if (XStack_138.y <= XStack_14c.y) {
                do {
                  if ((((iStack_13c != 1) || (iStack_190 < XStack_128.x)) ||
                      (XStack_130.x < iStack_190)) ||
                     ((iStack_178 < XStack_128.y || (XStack_130.y < iStack_178)))) {
                    if (fStack_198 == _DAT_00575578) {
LAB_004dbad8:
                      XStack_160.x = iStack_190 + -2;
                      XStack_160.y = iStack_178 + -2;
                      XStack_168.x = iStack_190 + 2;
                      XStack_168.y = iStack_178 + 2;
                    }
                    else if (fStack_198 == _DAT_0057557c) {
                      if (((iVar6 != 6) && (iVar6 != 3)) &&
                         (((iVar6 != 4 && ((iVar6 != 1 && (iVar6 != 2)))) && (iVar6 != 8))))
                      goto LAB_004dbad8;
LAB_004dbb67:
                      XStack_160.x = iStack_190 + -1;
                      XStack_160.y = iStack_178 + -1;
                      XStack_168.x = iStack_190 + 1;
                      XStack_168.y = iStack_178 + 1;
                    }
                    else if (fStack_198 == _DAT_00575574) {
                      if (((iVar6 == 6) || (iVar6 == 3)) || (iVar6 == 4)) {
                        XStack_160.x = iStack_190 + -1;
                        XStack_160.y = iStack_178 + -1;
                        XStack_168.y = iStack_178;
                        XStack_168.x = iStack_190;
                      }
                      else {
                        XStack_160.x = iStack_190 + -2;
                        XStack_160.y = iStack_178 + -2;
                        XStack_168.x = iStack_190 + 1;
                        XStack_168.y = iStack_178 + 1;
                      }
                    }
                    else {
                      if (fStack_198 != _DAT_00575564) {
                        iStack_180 = (int)((ulonglong)(double)fStack_198 >> 0x20);
                        pAStack_184 = SUB84((double)fStack_198,0);
                        AIModule::logCommonHistory
                                  (pAStack_184,(char *)param_1,s_____Unsupported_building_size___,
                                   pAStack_184,iStack_180,pAStack_184,iStack_180);
                        goto LAB_004dc0cd;
                      }
                      XStack_168.y = iStack_178;
                      XStack_168.x = iStack_190;
                      XStack_160.x = iStack_190;
                      XStack_160.y = iStack_178;
                      if (((iVar6 != 6) && (iVar6 != 3)) && (iVar6 != 4)) goto LAB_004dbb67;
                    }
                    iVar8 = TribeInformationAIModule::mapBound(param_1,&XStack_160);
                    if ((iVar8 != 1) &&
                       (iVar8 = TribeInformationAIModule::mapBound(param_1,&XStack_168), iVar8 != 1)
                       ) {
                      uStack_120 = 0xffffffff;
                      cVar3 = (**(code **)(pRStack_110->_padding_ + 0x20))
                                        (param_1->md->_padding_,(float)iStack_190 - _DAT_00575570,
                                         (float)iStack_178 - _DAT_00575570,&uStack_120,1,1,1,1,1,1);
                      if (cVar3 == '\0') {
                        iVar8 = 0;
                        bVar2 = false;
                        iVar10 = XStack_168.y;
                        iVar18 = XStack_160.x;
                        if (XStack_160.x <= XStack_168.x) {
                          do {
                            if (bVar2) break;
                            iVar16 = XStack_160.y;
                            if (XStack_160.y <= iVar10) {
                              do {
                                if (bVar2) break;
                                iVar10 = InfluenceMap::lookupValue(&iMap,iVar18,iVar16);
                                if (iVar10 == 0xff) {
                                  bVar2 = true;
                                }
                                else {
                                  iVar8 = iVar8 + iVar10;
                                }
                                iVar16 = iVar16 + 1;
                                iVar10 = XStack_168.y;
                              } while (iVar16 <= XStack_168.y);
                            }
                            iVar18 = iVar18 + 1;
                          } while (iVar18 <= XStack_168.x);
                        }
                        iVar10 = iMap.connectionCountValue;
                        if (!bVar2) {
                          if ((iVar6 == 4) || (iVar6 == 6)) {
                            iVar18 = InfluenceMap::connectionsIncluding
                                               (&iMap,&XStack_160,&XStack_168,0xff,0xff,1,0,1);
                            if ((iVar6 == 4) && (6 < iVar18 - iVar10)) goto LAB_004dbece;
                            iVar8 = (iVar18 - iVar10) * iVar8;
                          }
                          if (iVar6 == 4) {
                            XStack_118.y = iStack_178;
                            pXVar1 = &param_1->lastWallPosition;
                            XStack_118.x = iStack_190;
                            if (((param_1->lastWallPosition).x != -1) &&
                               (iVar10 = TribeInformationAIModule::isNextTo
                                                   (param_1,pXVar1,&XStack_118,0), iVar10 == 0)) {
                              iVar8 = iVar8 / 2;
                            }
                            uVar11 = TribeInformationAIModule::facetTo(param_1,pXVar1,&XStack_118);
                            uVar14 = (int)uVar11 >> 0x1f;
                            if (((uVar11 ^ uVar14) - uVar14 & 1 ^ uVar14) - uVar14 == 1) {
                              iVar8 = iVar8 * 3;
                            }
                            uVar14 = TribeInformationAIModule::facetTo
                                               (param_1,&param_1->lastWallPosition2,pXVar1);
                            if (uVar14 == uVar11) {
                              iVar8 = iVar8 * 3;
                            }
                            uVar14 = pXVar1->x - XStack_170.x;
                            uVar17 = (param_1->lastWallPosition).y - XStack_170.y;
                            uVar15 = (int)uVar14 >> 0x1f;
                            iVar18 = (uVar14 ^ uVar15) - uVar15;
                            uVar14 = (int)uVar17 >> 0x1f;
                            iVar10 = (uVar17 ^ uVar14) - uVar14;
                            if (iVar10 < iVar18) {
                              if (uVar11 == 1) {
LAB_004dbdb1:
                                iVar8 = iVar8 * 3;
                              }
                              else if (uVar11 == 5) {
                                iVar8 = iVar8 * 3;
                              }
                            }
                            else if ((iVar18 < iVar10) && ((uVar11 == 3 || (uVar11 == 7))))
                            goto LAB_004dbdb1;
                          }
                          else {
                            if ((iVar6 == 1) || (iVar6 == 2)) {
                              iVar10 = TribeInformationAIModule::undesirableLot
                                                 (param_1,iStack_194,(uchar)iStack_190,
                                                  (uchar)iStack_178,10);
                            }
                            else {
                              if (iVar6 == 6) goto LAB_004dbe30;
                              iVar10 = TribeInformationAIModule::undesirableLot
                                                 (param_1,iStack_194,(uchar)iStack_190,
                                                  (uchar)iStack_178,iStack_11c);
                            }
                            if (iVar10 == 1) {
                              iVar8 = iVar8 / 10;
                            }
                          }
LAB_004dbe30:
                          if ((iVar6 == 1) || (iVar6 == 2)) {
                            pCStack_150 = (ConstructionItem *)
                                          ((iStack_190 - XStack_170.x) * (iStack_190 - XStack_170.x)
                                          + (iStack_178 - XStack_170.y) *
                                            (iStack_178 - XStack_170.y));
                            iVar10 = __ftol();
                            if ((0 < iVar10 + -10) &&
                               (iVar10 = iVar8 - (iVar10 + -10) / 5, iVar5 < iVar10)) {
                              iVar8 = iVar10;
                            }
                          }
                          if ((pRStack_158 == (RGE_Static_Object *)0xffffffff) ||
                             ((int)pRStack_158 < iVar8 + iStack_18c)) {
                            if (iVar8 <= (int)pRStack_158) {
                              iStack_18c = iStack_18c / 2;
                            }
                            pAStack_184 = (AIModule *)iStack_190;
                            iStack_180 = iStack_178;
                            pRStack_158 = (RGE_Static_Object *)iVar8;
                          }
                        }
                      }
                    }
                  }
LAB_004dbece:
                  iStack_178 = iStack_178 + 1;
                  pRVar4 = pRStack_158;
                } while (iStack_178 <= XStack_14c.y);
              }
              iStack_190 = iStack_190 + 1;
            } while (iStack_190 <= XStack_14c.x);
          }
          if ((pRVar4 != (RGE_Static_Object *)0xffffffff) &&
             ((iVar5 < (int)pRVar4 || ((iVar6 != 2 && ((iVar5 < (int)pRVar4 || (iVar6 != 1)))))))) {
            if (iVar6 == 4) {
              iVar5 = (param_1->lastWallPosition).y;
              (param_1->lastWallPosition2).x = (param_1->lastWallPosition).x;
              (param_1->lastWallPosition2).y = iVar5;
              (param_1->lastWallPosition).x = (int)pAStack_184;
              (param_1->lastWallPosition).y = iStack_180;
            }
            if ((param_2 == (BaseItem *)0x0) && (param_11[0x45] != 1)) {
              TribeInformationAIModule::storeLot
                        (param_1,iStack_194,(uchar)pAStack_184,(uchar)iStack_180,'\0');
              param_11[0x45] = 0;
              uVar12 = 1;
              goto LAB_004dc0d9;
            }
            if (fStack_198 == _DAT_00575574) {
              pCStack_150 = (ConstructionItem *)operator_new(0x80);
              uStack_4 = 2;
              if (pCStack_150 == (ConstructionItem *)0x0) {
LAB_004dc06f:
                uVar12 = 0;
              }
              else {
                uVar12 = ConstructionItem::ConstructionItem
                                   (pCStack_150,(float)(int)pAStack_184,(float)iStack_180,1.0,
                                    fStack_198,fStack_198,1.0,iStack_194,acStack_10c);
              }
            }
            else {
              pCStack_150 = (ConstructionItem *)operator_new(0x80);
              uStack_4 = 3;
              if (pCStack_150 == (ConstructionItem *)0x0) goto LAB_004dc06f;
              uVar12 = ConstructionItem::ConstructionItem
                                 (pCStack_150,(float)(int)pAStack_184 - _DAT_00575570,
                                  (float)iStack_180 - _DAT_00575570,1.0,fStack_198,fStack_198,1.0,
                                  iStack_194,acStack_10c);
            }
            uStack_4 = 0xffffffff;
            TribeInformationAIModule::storeLot
                      (param_1,iStack_194,(uchar)pAStack_184,(uchar)iStack_180,'\x01');
            param_11[0x45] = 0;
            goto LAB_004dc0d9;
          }
          if (iVar6 == 4) {
            iVar5 = (param_1->lastWallPosition).y;
            (param_1->lastWallPosition2).x = (param_1->lastWallPosition).x;
            (param_1->lastWallPosition2).y = iVar5;
            (param_1->lastWallPosition).x = -1;
            (param_1->lastWallPosition).y = -1;
          }
        }
      }
    }
LAB_004dc0cd:
    param_11[0x45] = 0;
  }
LAB_004dc0d7:
  uVar12 = 0;
LAB_004dc0d9:
  *unaff_FS_OFFSET = uStack_c;
  return uVar12;
}

// --------------------------------------------------

// Function: FUN_004dc1ac
// Address: 004dc1ac
void __thiscall FUN_004dc1ac(TribeInformationAIModule *param_1,RGE_Static_Object *param_2)
{
  short sVar1;
  int iVar2;
  ObjectMemory *pOVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  if ((param_2 != (RGE_Static_Object *)0x0) && (-1 < param_2->id)) {
    pOVar3 = TribeInformationAIModule::objectMemory(param_1,param_2->id);
    if (pOVar3 != (ObjectMemory *)0x0) {
      pOVar3->owner = (uchar)param_2->owner->id;
    }
    iVar7 = (param_1->playerObjects).numberValue;
    iVar2 = param_2->id;
    iVar4 = 0;
    if (0 < iVar7) {
      do {
        if ((param_1->playerObjects).maximumSizeValue <= iVar4) break;
        if ((param_1->playerObjects).value[iVar4] == iVar2) goto LAB_004dc295;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar7);
    }
    if ((param_1->playerObjects).maximumSizeValue + -1 < iVar7) {
      iVar7 = iVar7 + 1;
      piVar5 = (int *)operator_new(iVar7 * 4);
      if (piVar5 != (int *)0x0) {
        iVar4 = 0;
        if (0 < (param_1->playerObjects).maximumSizeValue) {
          do {
            if (iVar7 <= iVar4) break;
            iVar6 = iVar4 + 1;
            piVar5[iVar4] = (param_1->playerObjects).value[iVar4];
            iVar4 = iVar6;
          } while (iVar6 < (param_1->playerObjects).maximumSizeValue);
        }
        operator_delete((param_1->playerObjects).value);
        (param_1->playerObjects).value = piVar5;
        (param_1->playerObjects).maximumSizeValue = iVar7;
      }
    }
    (param_1->playerObjects).value[(param_1->playerObjects).numberValue] = iVar2;
    (param_1->playerObjects).numberValue = (param_1->playerObjects).numberValue + 1;
LAB_004dc295:
    iVar7 = TribeInformationAIModule::isBuilding(param_1,param_2);
    if (iVar7 == 1) {
      iVar7 = (param_1->playerBuildings).numberValue;
      iVar2 = param_2->id;
      iVar4 = 0;
      if (0 < iVar7) {
        do {
          if ((param_1->playerBuildings).maximumSizeValue <= iVar4) break;
          if ((param_1->playerBuildings).value[iVar4] == iVar2) goto LAB_004dc357;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar7);
      }
      if ((param_1->playerBuildings).maximumSizeValue + -1 < iVar7) {
        iVar7 = iVar7 + 1;
        piVar5 = (int *)operator_new(iVar7 * 4);
        if (piVar5 != (int *)0x0) {
          iVar4 = 0;
          if (0 < (param_1->playerBuildings).maximumSizeValue) {
            do {
              if (iVar7 <= iVar4) break;
              iVar6 = iVar4 + 1;
              piVar5[iVar4] = (param_1->playerBuildings).value[iVar4];
              iVar4 = iVar6;
            } while (iVar6 < (param_1->playerBuildings).maximumSizeValue);
          }
          operator_delete((param_1->playerBuildings).value);
          (param_1->playerBuildings).value = piVar5;
          (param_1->playerBuildings).maximumSizeValue = iVar7;
        }
      }
      (param_1->playerBuildings).value[(param_1->playerBuildings).numberValue] = iVar2;
      (param_1->playerBuildings).numberValue = (param_1->playerBuildings).numberValue + 1;
LAB_004dc357:
      sVar1 = param_2->master_obj->id;
      if (((sVar1 == 0x6d) || (sVar1 == 0x67)) || (sVar1 == 0x44)) {
        TribeInformationAIModule::updateAllResourceDropsites(param_1);
      }
      if (param_2->master_obj->id == 0x32) {
        TribeInformationAIModule::addResourceObject(param_1,param_2);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004dc394
// Address: 004dc394
void __thiscall FUN_004dc394(TribeInformationAIModule *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  ObjectMemory *pOVar4;
  int *piVar5;
  
  iVar1 = 0;
  iVar2 = (param_1->playerBuildings).maximumSizeValue;
  if (0 < iVar2) {
    piVar5 = (param_1->playerBuildings).value;
    do {
      if (*piVar5 == param_2) break;
      iVar1 = iVar1 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar5 = (param_1->playerBuildings).value;
        iVar2 = iVar1 + 1;
        piVar5[iVar1] = piVar5[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (param_1->playerBuildings).maximumSizeValue + -1);
    }
    iVar2 = (param_1->playerBuildings).numberValue + -1;
    (param_1->playerBuildings).numberValue = iVar2;
    if (iVar2 < 0) {
      (param_1->playerBuildings).numberValue = 0;
    }
  }
  iVar2 = (param_1->playerObjects).maximumSizeValue;
  iVar1 = 0;
  if (0 < iVar2) {
    piVar5 = (param_1->playerObjects).value;
    do {
      if (*piVar5 == param_2) break;
      iVar1 = iVar1 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < iVar2) {
    if (iVar1 < iVar2 + -1) {
      do {
        piVar5 = (param_1->playerObjects).value;
        iVar2 = iVar1 + 1;
        piVar5[iVar1] = piVar5[iVar2];
        iVar1 = iVar2;
      } while (iVar2 < (param_1->playerObjects).maximumSizeValue + -1);
    }
    iVar2 = (param_1->playerObjects).numberValue + -1;
    (param_1->playerObjects).numberValue = iVar2;
    if (iVar2 < 0) {
      (param_1->playerObjects).numberValue = 0;
    }
  }
  pRVar3 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_2);
  if (pRVar3 != (RGE_Static_Object *)0x0) {
    pOVar4 = TribeInformationAIModule::objectMemory(param_1,param_2);
    if (pOVar4 != (ObjectMemory *)0x0) {
      pOVar4->owner = (uchar)pRVar3->owner->id;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004dc488
// Address: 004dc488
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
ObjectMemory * __thiscall
FUN_004dc488(TribeInformationAIModule *param_1,int param_2,int *param_3,ObjectMemory *param_4,
            int *param_5,int *param_6,int *param_7,int *param_8)
{
  byte bVar1;
  uchar uVar2;
  RGE_Game_World *pRVar3;
  AIPlayBook *this;
  bool bVar4;
  ObjectMemory *pOVar5;
  AIPlay *this_00;
  int iVar6;
  AIPlayPhase *this_01;
  AIPlayPhaseCommand *pAVar7;
  int iVar8;
  int iVar9;
  int iStack_1e0;
  int iStack_1d4;
  AIPlayStatus AStack_1c8;
  
  if (param_4 == (ObjectMemory *)0x0) {
    return param_4;
  }
  pOVar5 = TribeInformationAIModule::objectToAttackByGroup2(param_1,param_2,param_3,(int)param_4);
  if (pOVar5 == (ObjectMemory *)0x0) {
    return (ObjectMemory *)0x0;
  }
  iStack_1e0 = 0;
  pRVar3 = *(RGE_Game_World **)(param_1->md->_padding_ + 0x3c);
  this = pRVar3->playbook;
  *param_5 = -1;
  if (0 < this->numberPlaysValue) {
    do {
      this_00 = AIPlayBook::play(this,iStack_1e0);
      if ((this_00 != (AIPlay *)0x0) && (iVar6 = AIPlay::humanPlay(this_00), iVar6 != 1)) {
        AIPlayStatus::AIPlayStatus(&AStack_1c8);
        AStack_1c8.playNumberValue = iStack_1e0;
        AIPlay::fillGroups(this_00,&AStack_1c8,param_3,(int)param_4,pRVar3);
        if (AStack_1c8.deviationValue == '\0') {
          bVar4 = false;
          iStack_1d4 = 0;
          do {
            if (bVar4) goto LAB_004dc6f8;
            iVar6 = 0;
            do {
              if (bVar4) break;
              iVar8 = iVar6;
              this_01 = AIPlay::phase(this_00,iStack_1d4);
              pAVar7 = AIPlayPhase::command(this_01,iVar8);
              if (pAVar7->typeValue == '\x01') {
                iVar9 = pAVar7->value1Value + (uint)pOVar5->x;
                iVar8 = pAVar7->value2Value + (uint)pOVar5->y;
                if ((((iVar9 < 0) || (iVar8 < 0)) || (param_1->mapXSizeValue <= iVar9)) ||
                   (param_1->mapYSizeValue <= iVar8)) {
                  bVar4 = true;
                }
                iVar8 = TribeInformationAIModule::inRangeOfUnits(param_1,param_2,iVar9,iVar8,0);
                if (iVar8 == 1) {
                  bVar4 = true;
                }
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < 5);
            iStack_1d4 = iStack_1d4 + 1;
          } while (iStack_1d4 < 10);
          if (!bVar4) {
            iVar6 = TribeInformationAIModule::calculatePlayVariation(param_1,iStack_1e0);
            bVar1 = this_00->deathPercentageValue;
            iVar8 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xd49);
            iVar9 = 0;
            uVar2 = this_00->typeValue;
            if (uVar2 == '\x01') {
              iVar9 = 0xbd;
LAB_004dc687:
              iVar9 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,iVar9);
            }
            else {
              if (uVar2 == '\x02') {
                iVar9 = 0xc6;
                goto LAB_004dc687;
              }
              if (uVar2 == '\x03') {
                iVar9 = 199;
                goto LAB_004dc687;
              }
            }
            if ((*param_5 == -1) ||
               (0 < (int)(iVar9 + ((100 - (uint)bVar1) + iVar6) * 2 + iVar8 % 0x32))) {
              *param_5 = iStack_1e0;
              AIPlayStatus::copyUnits(&AStack_1c8,param_6,param_7);
              iVar6 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xd6a);
              *param_8 = param_6[iVar6 % *param_7];
            }
          }
        }
      }
LAB_004dc6f8:
      iStack_1e0 = iStack_1e0 + 1;
    } while (iStack_1e0 < this->numberPlaysValue);
  }
  iVar6 = *param_5;
  if (iVar6 != -1) {
    param_1->playHistory[iVar6] = param_1->playHistory[iVar6] + 1;
    return pOVar5;
  }
  return (ObjectMemory *)0x0;
}

// --------------------------------------------------

// Function: FUN_004dc74f
// Address: 004dc74f
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ObjectMemory * __thiscall
FUN_004dc74f(TribeInformationAIModule *param_1,uint param_2,int param_3,int param_4,int param_5,
            undefined4 *param_6)
{
  short sVar1;
  short sVar2;
  float10 fVar3;
  bool bVar4;
  uchar uVar5;
  uchar uVar6;
  ObjectMemory *pOVar7;
  RGE_Static_Object *this;
  UnitAIModule *pUVar8;
  int iVar9;
  RGE_Static_Object *pRVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  float10 fVar28;
  float fStack_88;
  int iStack_84;
  int iStack_78;
  int iStack_70;
  float fStack_6c;
  ObjectMemory *pOStack_68;
  float fStack_64;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_50;
  int iStack_4c;
  uint uStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  ObjectMemory OStack_24;
  
  pOVar7 = TribeInformationAIModule::wonderToAttack(param_1,-1);
  if (pOVar7 != (ObjectMemory *)0x0) {
    *param_6 = 1;
    return pOVar7;
  }
  this = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_5);
  if ((this == (RGE_Static_Object *)0x0) ||
     (pUVar8 = RGE_Static_Object::unitAI(this), pUVar8 == (UnitAIModule *)0x0)) {
    return (ObjectMemory *)0x0;
  }
  uVar5 = RGE_Static_Object::currentZone(this);
  sVar1 = this->master_obj->id;
  if (((sVar1 == 0x23) || (sVar1 == 0x24)) || (bVar4 = false, sVar1 == 0xb)) {
    bVar4 = true;
  }
  iVar9 = TribeInformationAIModule::isBoat(param_1,this);
  sVar1 = this->master_obj->object_group;
  TribeInformationAIModule::findObjectMemoryLimits
            (param_1,&OStack_24,param_2,param_5,&iStack_30,&iStack_28);
  pOStack_68 = (ObjectMemory *)0x0;
  iStack_4c = -1;
  iStack_44 = 0;
  if (0 < param_1->maxImportantObjectMemory) {
    iStack_84 = 0;
    do {
      if ((((&param_1->importantObjectMemory->owner)[iStack_84] == param_2) &&
          (pRVar10 = MainDecisionAIModule::object
                               ((MainDecisionAIModule *)param_1->md,
                                *(int *)((int)&param_1->importantObjectMemory->id + iStack_84)),
          pRVar10 != (RGE_Static_Object *)0x0)) && (pRVar10->object_state < 3)) {
        iVar11 = __ftol();
        iVar12 = __ftol();
        fStack_64 = TribeInformationAIModule::damagePerSecond(param_1,param_5,iVar12,iVar11);
        (**(code **)(pRVar10->_padding_ + 0x104))(this);
        fVar28 = (float10)(**(code **)(this->_padding_ + 0x100))();
        fVar3 = (float10)fStack_88;
        if (fStack_64 <= _DAT_00575580) {
          fStack_64 = -1.0;
        }
        else {
          fStack_64 = this->hp / fStack_64;
        }
        if (fVar3 / fVar28 <= (float10)_DAT_00575580) {
          fStack_6c = -1.0;
        }
        else {
          fStack_88 = (float)(int)*(short *)((int)&param_1->importantObjectMemory->hitPoints +
                                            iStack_84);
          fStack_6c = (float)((float10)(int)fStack_88 / (fVar3 / fVar28));
        }
        if (((((bVar4) || (param_3 == 0)) ||
             ((sVar2 = pRVar10->master_obj->object_group, sVar2 != 3 && (sVar2 != 0x1b)))) ||
            (iStack_30 < 1)) &&
           (((iVar9 != 0 || (param_4 == 0)) ||
            (((pRVar10->master_obj->id != 0x2d &&
              ((((sVar2 = pRVar10->master_obj->object_group, sVar2 != 2 && (sVar2 != 0x15)) &&
                (sVar2 != 0x16)) && (sVar2 != 0x14)))) || (iStack_28 < 1)))))) {
          if (sVar1 == 0x12) {
            pUVar8 = RGE_Static_Object::unitAI(this);
            iVar11 = (**(code **)(pUVar8->_padding_ + 0xc4))
                               (*(undefined4 *)
                                 ((int)&param_1->importantObjectMemory->id + iStack_84));
            if (iVar11 == 0) goto LAB_004dcecb;
          }
          pOVar7 = param_1->importantObjectMemory;
          iVar11 = __ftol();
          iVar12 = (uint)(&pOVar7->x)[iStack_84] - iVar11;
          if (iVar12 < 0) {
            iVar12 = -iVar12;
          }
          iVar13 = __ftol();
          iVar27 = (uint)(&pOVar7->y)[iStack_84] - iVar13;
          if (iVar27 < 0) {
            iVar27 = -iVar27;
          }
          if (((iVar12 < 6) && (iVar27 < 6)) ||
             (uVar6 = RGE_Visible_Map::get_visible
                                (*(RGE_Visible_Map **)(param_1->md->_padding_ + 0x38),iVar11,iVar13)
             , uVar6 == '\x0f')) {
            pOVar7 = param_1->importantObjectMemory;
            __ftol();
            __ftol();
            iVar11 = __ftol();
            if (OStack_24.id == 0) {
              iStack_38 = 100;
            }
            else {
              iStack_38 = 100 - (iVar11 * 100) / OStack_24.id;
            }
            if (OStack_24.hitPoints == 0) {
              iStack_3c = 100;
            }
            else {
              iStack_3c = (*(short *)((int)&pOVar7->hitPoints + iStack_84) * 100) /
                          (int)OStack_24.hitPoints;
            }
            if (OStack_24.kills == '\0') {
              uStack_50 = 100;
            }
            else {
              uStack_50 = ((uint)(&pOVar7->kills)[iStack_84] * 100) / (OStack_24._20_4_ & 0xff);
            }
            if (OStack_24.damageCapability == _DAT_00575580) {
              iStack_40 = 100;
            }
            else {
              iStack_40 = __ftol();
            }
            if (*(float *)((int)&pOVar7->damageCapability + iStack_84) <= _DAT_00575580) {
              iStack_70 = 0;
              iStack_78 = 0;
            }
            else {
              if (OStack_24.range == _DAT_00575580) {
                iStack_70 = 100;
              }
              else {
                iStack_70 = __ftol();
              }
              if (OStack_24.rateOfFire == _DAT_00575580) {
                iStack_78 = 100;
              }
              else {
                iStack_78 = __ftol();
                iStack_78 = 100 - iStack_78;
              }
            }
            iStack_2c = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xe36);
            iStack_2c = iStack_2c % 100;
            iVar11 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x6a);
            fStack_88 = (float)(uint)(*(short *)((int)&param_1->importantObjectMemory->type +
                                                iStack_84) == iVar11);
            iVar11 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x6b);
            uStack_58 = (uint)(*(short *)((int)&param_1->importantObjectMemory->type + iStack_84) ==
                              iVar11);
            iVar11 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x6c);
            uStack_48 = (uint)(*(short *)((int)&param_1->importantObjectMemory->type + iStack_84) ==
                              iVar11);
            iVar11 = __ftol();
            iVar12 = __ftol();
            uVar6 = RGE_Static_Object::lookupZone(this,iVar12,iVar11);
            uStack_5c = (uint)(uVar5 == uVar6);
            sVar2 = pRVar10->master_obj->object_group;
            if ((sVar2 == 3) || (sVar2 == 0x1b)) {
              iVar11 = (-(uint)bVar4 & 2) - 1;
            }
            else {
              iVar11 = (-(uint)bVar4 & 0xfffffffe) + 1;
            }
            if ((((pRVar10->master_obj->id == 0x2d) || (sVar2 == 2)) || (sVar2 == 0x15)) ||
               ((sVar2 == 0x16 || (sVar2 == 0x14)))) {
              iVar12 = (-(uint)(iVar9 != 0) & 2) - 1;
            }
            else {
              iVar12 = (-(uint)(iVar9 != 0) & 0xfffffffe) + 1;
            }
            iVar27 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x59);
            iVar13 = *(int *)((int)&param_1->importantObjectMemory->attackAttempts + iStack_84);
            iVar14 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x90);
            iVar15 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x7b);
            iVar16 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x7a);
            iVar17 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x50);
            iVar18 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x53);
            iVar18 = iVar18 * iStack_2c;
            iVar19 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x4d);
            iVar20 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x6f);
            iVar21 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x5a);
            iVar22 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x4e);
            iVar23 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x4f);
            iVar24 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x52);
            iVar25 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x6e);
            iVar26 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x6d);
            iVar11 = iVar27 * iVar13 + iVar14 * iVar12 + iVar15 * iVar11 + iVar16 * uStack_5c +
                     iVar17 * uStack_50 + iVar18 + iVar19 * iStack_38 + iVar20 * uStack_48 +
                     iVar21 * iStack_70 + iVar22 * iStack_3c + iVar23 * iStack_40 +
                     iVar24 * iStack_78 + iVar25 * uStack_58 + iVar26 * (int)fStack_88;
            if (((fStack_64 < fStack_6c) && (fStack_64 != _DAT_0057556c)) ||
               (fStack_6c == _DAT_0057556c)) {
              iVar11 = 1;
            }
            if ((pOStack_68 == (ObjectMemory *)0x0) || (iStack_4c < iVar11)) {
              pOStack_68 = (ObjectMemory *)((int)&param_1->importantObjectMemory->id + iStack_84);
              *param_6 = 1;
              iStack_4c = iVar11;
            }
          }
        }
      }
LAB_004dcecb:
      iStack_44 = iStack_44 + 1;
      iStack_84 = iStack_84 + 0x24;
    } while (iStack_44 < param_1->maxImportantObjectMemory);
  }
  return pOStack_68;
}

// --------------------------------------------------

// Function: FUN_004dcf09
// Address: 004dcf09
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ObjectMemory * __thiscall
FUN_004dcf09(TribeInformationAIModule *param_1,uint param_2,TacticalAIGroup *param_3,int *param_4,
            int param_5)
{
  byte bVar1;
  short sVar2;
  short sVar3;
  code *pcVar4;
  uint uVar5;
  float fVar6;
  byte bVar7;
  byte bVar8;
  uchar uVar9;
  int iVar10;
  RGE_Static_Object *pRVar11;
  UnitAIModule *pUVar12;
  RGE_Static_Object *pRVar13;
  ObjectMemory *pOVar14;
  int iVar15;
  int iVar16;
  void *pvVar17;
  ulong uVar18;
  int *piVar19;
  int iVar20;
  int iVar21;
  RGE_Static_Object *this;
  int iVar22;
  int iVar23;
  undefined4 *unaff_FS_OFFSET;
  bool bVar24;
  float10 fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fStack_58;
  int iStack_4c;
  float fStack_44;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  void *pvStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00560560;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar10 = TacticalAIGroup::commander(param_3);
  pRVar11 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar10);
  if ((pRVar11 == (RGE_Static_Object *)0x0) ||
     (pUVar12 = RGE_Static_Object::unitAI(pRVar11), pUVar12 == (UnitAIModule *)0x0)) {
    param_4[10] = 0;
  }
  else {
    bVar7 = RGE_Static_Object::currentZone(pRVar11);
    sVar2 = pRVar11->master_obj->object_group;
    iVar10 = TribeInformationAIModule::isBoat(param_1,pRVar11);
    bVar24 = iVar10 == 1;
    if ((((param_4[10] == 0) && (param_3->objectsToDestroyOwnerValue == param_2)) &&
        (0 < param_3->numberObjectsToDestroyValue)) &&
       (param_3->objectsToDestroyCommanderZoneValue == (uint)bVar7)) {
      iVar10 = TacticalAIGroup::objectToDestroy(param_3,param_3->numberObjectsToDestroyValue + -1);
      pRVar13 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar10);
      if (((pRVar13 != (RGE_Static_Object *)0x0) &&
          (iVar10 = (**(code **)(*(int *)param_1->md->_padding_ + 0x18))((int)pRVar13->owner->id),
          iVar10 == 1)) && (pRVar13->object_state < 3)) {
        iVar10 = param_3->numberObjectsToDestroyValue;
        iVar15 = pRVar11->_padding_;
        fVar25 = (float10)(**(code **)(iVar15 + 0x10c))(0,1,0xffffffff,0xffffffff);
        fVar28 = (float)fVar25;
        iVar10 = TacticalAIGroup::objectToDestroy(param_3,iVar10 + -1);
        iVar10 = (**(code **)(iVar15 + 0x194))(iVar10,fVar28);
        if (iVar10 == 1) {
          iVar10 = TacticalAIGroup::objectToDestroy
                             (param_3,param_3->numberObjectsToDestroyValue + -1);
          param_3->numberObjectsToDestroyValue = 0;
          TacticalAIGroup::addObjectToDestroy(param_3,iVar10);
          pOVar14 = TribeInformationAIModule::objectMemory(param_1,iVar10);
          goto LAB_004ddd27;
        }
      }
      iVar10 = 0;
      if (param_3->numberObjectsToDestroyValue != 1 &&
          -1 < param_3->numberObjectsToDestroyValue + -1) {
        do {
          iVar15 = TacticalAIGroup::objectToDestroy(param_3,iVar10);
          pRVar13 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar15);
          if (((pRVar13 != (RGE_Static_Object *)0x0) &&
              (iVar15 = (**(code **)(*(int *)param_1->md->_padding_ + 0x18))
                                  ((int)pRVar13->owner->id), iVar15 == 1)) &&
             (pRVar13->object_state < 3)) {
            iVar15 = pRVar11->_padding_;
            fVar25 = (float10)(**(code **)(iVar15 + 0x10c))(0,1,0xffffffff,0xffffffff);
            fVar28 = (float)fVar25;
            iVar16 = TacticalAIGroup::objectToDestroy(param_3,iVar10);
            iVar15 = (**(code **)(iVar15 + 0x194))(iVar16,fVar28);
            if (iVar15 == 1) goto LAB_004ddcee;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < param_3->numberObjectsToDestroyValue + -1);
      }
    }
    if (param_4[10] == 0) {
      pOVar14 = TribeInformationAIModule::wonderToAttack(param_1,-1);
      if (pOVar14 != (ObjectMemory *)0x0) {
        bVar8 = RGE_Static_Object::lookupZone(pRVar11,(uint)pOVar14->x,(uint)pOVar14->y);
        if ((bVar8 != bVar7) && (!bVar24)) goto LAB_004ddd27;
        iVar10 = pRVar11->_padding_;
        pcVar4 = *(code **)(iVar10 + 0x10c);
        fVar25 = (float10)(*pcVar4)(0,1,0xffffffff,0xffffffff);
        iVar15 = (**(code **)(iVar10 + 0x194))(pOVar14->id,(float)fVar25);
        if (iVar15 == 1) {
          param_3->numberObjectsToDestroyValue = 0;
          TacticalAIGroup::addObjectToDestroy(param_3,pOVar14->id);
          param_3->objectsToDestroyOwnerValue = (uint)pOVar14->owner;
          param_3->objectsToDestroyCommanderZoneValue = (uint)bVar7;
          goto LAB_004ddd27;
        }
        pvStack_1c = (void *)0x0;
        iStack_18 = 0;
        uStack_14 = 0;
        iStack_10 = 0;
        uStack_4 = 0;
        fVar25 = (float10)(*pcVar4)(0,1,param_2,0x1b,&pvStack_1c);
        iVar10 = (**(code **)(iVar10 + 0x1a0))(pOVar14->id,(float)fVar25);
        if (iVar10 == 1) {
          iVar10 = 0;
          param_3->numberObjectsToDestroyValue = 0;
          if (0 < iStack_18) {
            do {
              if (iStack_10 + -1 < iVar10) {
                pvVar17 = operator_new(iVar10 * 4 + 4);
                if (pvVar17 != (void *)0x0) {
                  iVar15 = 0;
                  if (0 < iStack_10) {
                    do {
                      if (iVar10 + 1 <= iVar15) break;
                      iVar15 = iVar15 + 1;
                      *(undefined4 *)((int)pvVar17 + iVar15 * 4 + -4) =
                           *(undefined4 *)((int)pvStack_1c + iVar15 * 4 + -4);
                    } while (iVar15 < iStack_10);
                  }
                  operator_delete(pvStack_1c);
                  pvStack_1c = pvVar17;
                  iStack_10 = iVar10 + 1;
                }
              }
              pRVar11 = MainDecisionAIModule::object
                                  ((MainDecisionAIModule *)param_1->md,
                                   *(int *)((int)pvStack_1c + iVar10 * 4));
              if (pRVar11 != (RGE_Static_Object *)0x0) {
                if (iStack_10 + -1 < iVar10) {
                  pvVar17 = operator_new(iVar10 * 4 + 4);
                  if (pvVar17 != (void *)0x0) {
                    iVar15 = 0;
                    if (0 < iStack_10) {
                      do {
                        if (iVar10 + 1 <= iVar15) break;
                        iVar15 = iVar15 + 1;
                        *(undefined4 *)((int)pvVar17 + iVar15 * 4 + -4) =
                             *(undefined4 *)((int)pvStack_1c + iVar15 * 4 + -4);
                      } while (iVar15 < iStack_10);
                    }
                    operator_delete(pvStack_1c);
                    pvStack_1c = pvVar17;
                    iStack_10 = iVar10 + 1;
                  }
                }
                TribeInformationAIModule::addImportantObject
                          (param_1,*(int *)((int)pvStack_1c + iVar10 * 4));
                if (iStack_10 + -1 < iVar10) {
                  pvVar17 = operator_new(iVar10 * 4 + 4);
                  if (pvVar17 != (void *)0x0) {
                    iVar15 = 0;
                    if (0 < iStack_10) {
                      do {
                        if (iVar10 + 1 <= iVar15) break;
                        iVar15 = iVar15 + 1;
                        *(undefined4 *)((int)pvVar17 + iVar15 * 4 + -4) =
                             *(undefined4 *)((int)pvStack_1c + iVar15 * 4 + -4);
                      } while (iVar15 < iStack_10);
                    }
                    operator_delete(pvStack_1c);
                    pvStack_1c = pvVar17;
                    iStack_10 = iVar10 + 1;
                  }
                }
                TacticalAIGroup::addObjectToDestroy(param_3,*(int *)((int)pvStack_1c + iVar10 * 4));
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < iStack_18);
          }
          TacticalAIGroup::addObjectToDestroy(param_3,pOVar14->id);
          bVar8 = pOVar14->owner;
          param_3->objectsToDestroyCommanderZoneValue = (uint)bVar7;
          param_3->objectsToDestroyOwnerValue = (uint)bVar8;
          uStack_4 = 0xffffffff;
          if (pvStack_1c != (void *)0x0) {
            operator_delete(pvStack_1c);
          }
          goto LAB_004ddd27;
        }
        uStack_4 = 0xffffffff;
        if (pvStack_1c != (void *)0x0) {
          operator_delete(pvStack_1c);
        }
      }
      *param_4 = -1;
      param_4[1] = -0x40800000;
      param_4[2] = -1;
      param_4[3] = 0;
      param_4[4] = -1;
      param_4[5] = -1;
      *(undefined1 *)(param_4 + 6) = 0;
      param_4[7] = -1;
      param_4[8] = -0x40800000;
      param_4[9] = -1;
      param_4[10] = 1;
    }
    iVar10 = param_4[3];
    if (iVar10 < param_1->maxImportantObjectMemory) {
      iVar15 = iVar10 * 0x24;
      do {
        if ((param_4[3] < iVar10) &&
           (uVar5 = *(uint *)(*(int *)(param_1->md->_padding_ + 0x3c) + 0xf8),
           uVar18 = debug_timeGetTime(s_C__msdev_work_age1_x1_taiinfmd_c,0xf5a),
           uVar5 <= uVar18 - param_5)) {
          param_4[3] = iVar10;
          goto LAB_004ddd25;
        }
        piVar19 = (int *)((int)&param_1->importantObjectMemory->id + iVar15);
        if ((((*(byte *)((int)piVar19 + 0xb) == param_2) &&
             (pRVar13 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,*piVar19),
             pRVar13 != (RGE_Static_Object *)0x0)) && (pRVar13->object_state < 3)) &&
           ((pRVar13->hp != _DAT_00575580 &&
            ((bVar24 || (iVar16 = TribeInformationAIModule::isBoat(param_1,pRVar13), iVar16 != 1))))
           )) {
          iVar16 = __ftol();
          iVar20 = __ftol();
          bVar8 = RGE_Static_Object::lookupZone(pRVar11,iVar20,iVar16);
          if (((bVar24) ||
              ((*(short *)((int)&param_1->importantObjectMemory->type + iVar15) != 0x2d ||
               (bVar7 == bVar8)))) &&
             ((((char)param_4[6] != '\0' ||
               (*(short *)((int)&param_1->importantObjectMemory->group + iVar15) != 0x1b)) &&
              (((char)param_4[6] != '\x01' ||
               (*(short *)((int)&param_1->importantObjectMemory->group + iVar15) == 0x1b)))))) {
            pOVar14 = param_1->importantObjectMemory;
            iVar16 = __ftol();
            iVar20 = (uint)(&pOVar14->x)[iVar15] - iVar16;
            if (iVar20 < 0) {
              iVar20 = -iVar20;
            }
            iVar21 = __ftol();
            iVar23 = (uint)(&pOVar14->y)[iVar15] - iVar21;
            if (iVar23 < 0) {
              iVar23 = -iVar23;
            }
            if (((iVar20 < 6) && (iVar23 < 6)) ||
               (uVar9 = RGE_Visible_Map::get_visible
                                  (*(RGE_Visible_Map **)(param_1->md->_padding_ + 0x38),iVar16,
                                   iVar21), uVar9 == '\x0f')) {
              if (sVar2 == 0x12) {
                pUVar12 = RGE_Static_Object::unitAI(pRVar11);
                iVar16 = (**(code **)(pUVar12->_padding_ + 0xc4))
                                   (*(undefined4 *)
                                     ((int)&param_1->importantObjectMemory->id + iVar15));
                if (iVar16 == 0) goto LAB_004ddc98;
              }
              fVar26 = TribeInformationAIModule::damageInflictedPerSecond(param_1,param_3,pRVar13);
              fVar28 = pRVar13->hp;
              fVar27 = TribeInformationAIModule::timeToBeKilled(param_1,param_3,pRVar13);
              if ((fVar26 != _DAT_00575580) && (fVar27 != _DAT_00575580)) {
                pOVar14 = param_1->importantObjectMemory;
                iVar16 = __ftol();
                iVar16 = (uint)(&pOVar14->x)[iVar15] - iVar16;
                iVar20 = __ftol();
                iVar20 = (uint)(&pOVar14->y)[iVar15] - iVar20;
                fStack_44 = SQRT((float)(iVar16 * iVar16 + iVar20 * iVar20));
                if (fStack_44 < _DAT_00575564) {
                  fStack_44 = 1.0;
                }
                bVar1 = (&pOVar14->kills)[iVar15];
                iVar16 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x53);
                if (iVar16 < 1) {
                  fStack_34 = 0.0;
                }
                else {
                  iVar16 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x53);
                  iVar20 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0xfd5);
                  fStack_34 = (float)(iVar20 % iVar16);
                }
                iVar20 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x59);
                iVar16 = *(int *)((int)&param_1->importantObjectMemory->attackAttempts + iVar15);
                if (bVar7 == bVar8) {
                  iVar21 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x7a);
                  fStack_38 = (float)iVar21;
                }
                else {
                  fStack_38 = 0.0;
                }
                fStack_3c = 0.0;
                iVar21 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xb9);
                if (0 < iVar21) {
                  iVar23 = 0;
                  iStack_4c = 0;
                  iVar21 = TacticalAIGroup::numberUnits(param_3);
                  if (0 < iVar21) {
                    do {
                      iVar21 = TacticalAIGroup::unit(param_3,iVar23);
                      this = MainDecisionAIModule::object
                                       ((MainDecisionAIModule *)param_1->md,iVar21);
                      if ((this != (RGE_Static_Object *)0x0) &&
                         (pUVar12 = RGE_Static_Object::unitAI(this), pUVar12 != (UnitAIModule *)0x0)
                         ) {
                        pUVar12 = RGE_Static_Object::unitAI(this);
                        iVar21 = UnitAIModule::currentTarget(pUVar12);
                        if (iVar21 == *(int *)((int)&param_1->importantObjectMemory->id + iVar15)) {
                          iStack_4c = iStack_4c + 1;
                        }
                      }
                      iVar23 = iVar23 + 1;
                      iVar21 = TacticalAIGroup::numberUnits(param_3);
                    } while (iVar23 < iVar21);
                  }
                  iVar21 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xb9);
                  fStack_3c = (float)iVar21 * (float)iStack_4c;
                }
                fStack_58 = 0.0;
                if (((char)param_4[6] == '\x01') && (param_4[7] != -1)) {
                  pOVar14 = param_1->importantObjectMemory;
                  iVar21 = (uint)(&pOVar14->x)[iVar15] - (uint)pOVar14[param_4[9]].x;
                  iVar23 = (uint)(&pOVar14->y)[iVar15] - (uint)pOVar14[param_4[9]].y;
                  fStack_58 = SQRT((float)(iVar21 * iVar21 + iVar23 * iVar23));
                  if (_DAT_00575564 <= fStack_58) {
                    fStack_58 = _DAT_0057558c / fStack_58;
                  }
                  else {
                    fStack_58 = 1000.0;
                  }
                }
                iVar21 = TribeInformationAIModule::isUnitBuilding(param_1,pRVar13);
                if (iVar21 == 1) {
                  sVar3 = pRVar13->master_obj->id;
                  fVar6 = _DAT_00575594;
                  if ((sVar3 != 0x6d) && (sVar3 != 0x2d)) {
                    fVar6 = _DAT_00575590;
                  }
                  fStack_58 = fStack_58 - fVar6;
                }
                iVar21 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x50);
                iVar23 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x4d);
                iVar22 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xb8);
                fStack_34 = (float)iVar22 * (fVar27 / (fVar28 / fVar26)) +
                            (float)iVar23 / fStack_44 + (float)iVar21 * (float)bVar1 + fStack_58 +
                            fStack_3c + fStack_38 + (float)iVar20 * (float)iVar16 + fStack_34;
                if ((*param_4 == -1) || ((float)param_4[1] < fStack_34)) {
                  if (((char)param_4[6] == '\0') &&
                     (fVar25 = (float10)(**(code **)(pRVar13->_padding_ + 0xfc))(),
                     fVar25 == (float10)_DAT_00575580)) {
                    param_4[7] = *(int *)((int)&param_1->importantObjectMemory->id + iVar15);
                    param_4[9] = iVar10;
                    param_4[8] = (int)fStack_34;
                  }
                  iVar16 = param_4[6];
                  pvStack_1c = (void *)0x0;
                  iStack_18 = 0;
                  uStack_14 = 0;
                  iStack_10 = 0;
                  uStack_4 = 1;
                  if (bVar7 == bVar8) {
                    iVar20 = pRVar11->_padding_;
                    pcVar4 = *(code **)(iVar20 + 0x10c);
                    fVar25 = (float10)(*pcVar4)(0,1,0xffffffff,0xffffffff);
                    iVar21 = (**(code **)(iVar20 + 0x194))
                                       (*(undefined4 *)
                                         ((int)&param_1->importantObjectMemory->id + iVar15),
                                        (float)fVar25);
                    if (iVar21 == 1) goto LAB_004ddaa8;
                    fVar25 = (float10)(*pcVar4)(0,1,param_2,
                                                (-(uint)((char)iVar16 != '\0') & 0xffffffe4) + 0x1b,
                                                &pvStack_1c);
                    iVar16 = (**(code **)(iVar20 + 0x1a0))
                                       (*(undefined4 *)
                                         ((int)&param_1->importantObjectMemory->id + iVar15),
                                        (float)fVar25);
                    if (iVar16 == 1) goto LAB_004ddaa8;
                  }
                  else {
LAB_004ddaa8:
                    iVar16 = 0;
                    param_3->numberObjectsToDestroyValue = 0;
                    if (0 < iStack_18) {
                      do {
                        if (iStack_10 + -1 < iVar16) {
                          pvVar17 = operator_new(iVar16 * 4 + 4);
                          if (pvVar17 != (void *)0x0) {
                            iVar20 = 0;
                            if (0 < iStack_10) {
                              do {
                                if (iVar16 + 1 <= iVar20) break;
                                iVar20 = iVar20 + 1;
                                *(undefined4 *)((int)pvVar17 + iVar20 * 4 + -4) =
                                     *(undefined4 *)((int)pvStack_1c + iVar20 * 4 + -4);
                              } while (iVar20 < iStack_10);
                            }
                            operator_delete(pvStack_1c);
                            pvStack_1c = pvVar17;
                            iStack_10 = iVar16 + 1;
                          }
                        }
                        pRVar13 = MainDecisionAIModule::object
                                            ((MainDecisionAIModule *)param_1->md,
                                             *(int *)((int)pvStack_1c + iVar16 * 4));
                        if (pRVar13 != (RGE_Static_Object *)0x0) {
                          if (iStack_10 + -1 < iVar16) {
                            pvVar17 = operator_new(iVar16 * 4 + 4);
                            if (pvVar17 != (void *)0x0) {
                              iVar20 = 0;
                              if (0 < iStack_10) {
                                do {
                                  if (iVar16 + 1 <= iVar20) break;
                                  iVar20 = iVar20 + 1;
                                  *(undefined4 *)((int)pvVar17 + iVar20 * 4 + -4) =
                                       *(undefined4 *)((int)pvStack_1c + iVar20 * 4 + -4);
                                } while (iVar20 < iStack_10);
                              }
                              operator_delete(pvStack_1c);
                              pvStack_1c = pvVar17;
                              iStack_10 = iVar16 + 1;
                            }
                          }
                          TribeInformationAIModule::addImportantObject
                                    (param_1,*(int *)((int)pvStack_1c + iVar16 * 4));
                          if (iStack_10 + -1 < iVar16) {
                            pvVar17 = operator_new(iVar16 * 4 + 4);
                            if (pvVar17 != (void *)0x0) {
                              iVar20 = 0;
                              if (0 < iStack_10) {
                                do {
                                  if (iVar16 + 1 <= iVar20) break;
                                  iVar20 = iVar20 + 1;
                                  *(undefined4 *)((int)pvVar17 + iVar20 * 4 + -4) =
                                       *(undefined4 *)((int)pvStack_1c + iVar20 * 4 + -4);
                                } while (iVar20 < iStack_10);
                              }
                              operator_delete(pvStack_1c);
                              pvStack_1c = pvVar17;
                              iStack_10 = iVar16 + 1;
                            }
                          }
                          TacticalAIGroup::addObjectToDestroy
                                    (param_3,*(int *)((int)pvStack_1c + iVar16 * 4));
                        }
                        iVar16 = iVar16 + 1;
                      } while (iVar16 < iStack_18);
                    }
                    TacticalAIGroup::addObjectToDestroy
                              (param_3,*(int *)((int)&param_1->importantObjectMemory->id + iVar15));
                    bVar8 = (&param_1->importantObjectMemory->owner)[iVar15];
                    param_3->objectsToDestroyCommanderZoneValue = (uint)bVar7;
                    param_3->objectsToDestroyOwnerValue = (uint)bVar8;
                    *param_4 = *(int *)((int)&param_1->importantObjectMemory->id + iVar15);
                    param_4[2] = iVar10;
                    param_4[1] = (int)fStack_34;
                  }
                  uStack_4 = 0xffffffff;
                  if (pvStack_1c != (void *)0x0) {
                    operator_delete(pvStack_1c);
                    pvStack_1c = (void *)0x0;
                  }
                  iStack_18 = 0;
                  uStack_14 = 0;
                  iStack_10 = 0;
                }
              }
            }
          }
        }
LAB_004ddc98:
        iVar10 = iVar10 + 1;
        iVar15 = iVar15 + 0x24;
      } while (iVar10 < param_1->maxImportantObjectMemory);
    }
    if (*param_4 != -1) {
      iVar10 = 0;
      param_1->importantObjectMemory[param_4[2]].attackAttempts =
           param_1->importantObjectMemory[param_4[2]].attackAttempts + 1;
      param_4[10] = 0;
LAB_004ddcee:
      iVar10 = TacticalAIGroup::objectToDestroy(param_3,iVar10);
      pOVar14 = TribeInformationAIModule::objectMemory(param_1,iVar10);
      goto LAB_004ddd27;
    }
    if ((char)param_4[6] == '\0') {
      *(undefined1 *)(param_4 + 6) = 1;
      param_4[3] = 0;
    }
    else {
      param_4[10] = 0;
    }
  }
LAB_004ddd25:
  pOVar14 = (ObjectMemory *)0x0;
LAB_004ddd27:
  *unaff_FS_OFFSET = uStack_c;
  return pOVar14;
}

// --------------------------------------------------

// Function: FUN_004ddd3f
// Address: 004ddd3f
// [HELPER] s_C__msdev_work_age1_x1_taiinfmd_c: "C:\msdev\work\age1_x1\taiinfmd.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ObjectMemory * __thiscall
FUN_004ddd3f(TribeInformationAIModule *param_1,uint param_2,int *param_3,int param_4)
{
  float fVar1;
  byte bVar2;
  short sVar3;
  uchar uVar4;
  uchar uVar5;
  ObjectMemory *pOVar6;
  RGE_Static_Object *this;
  UnitAIModule *pUVar7;
  RGE_Static_Object *pRVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  float fVar15;
  float fVar16;
  int iStack_3c;
  int iStack_34;
  float fStack_30;
  ObjectMemory *pOStack_2c;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  int iStack_14;
  
  pOVar6 = TribeInformationAIModule::wonderToAttack(param_1,-1);
  if (pOVar6 == (ObjectMemory *)0x0) {
    if (((param_4 != 0) &&
        (this = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,*param_3),
        this != (RGE_Static_Object *)0x0)) &&
       (pUVar7 = RGE_Static_Object::unitAI(this), pUVar7 != (UnitAIModule *)0x0)) {
      uVar4 = RGE_Static_Object::currentZone(this);
      sVar3 = this->master_obj->object_group;
      pOStack_2c = (ObjectMemory *)0x0;
      fStack_18 = -1.0;
      iStack_14 = 0;
      if (0 < param_1->maxImportantObjectMemory) {
        iStack_3c = 0;
        do {
          piVar14 = (int *)((int)&param_1->importantObjectMemory->id + iStack_3c);
          if (((*(byte *)((int)piVar14 + 0xb) == param_2) &&
              (pRVar8 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,*piVar14),
              pRVar8 != (RGE_Static_Object *)0x0)) &&
             ((pRVar8->object_state < 3 && (pRVar8->hp != _DAT_00575580)))) {
            pOVar6 = param_1->importantObjectMemory;
            iVar9 = __ftol();
            iVar13 = (uint)(&pOVar6->x)[iStack_3c] - iVar9;
            if (iVar13 < 0) {
              iVar13 = -iVar13;
            }
            iVar10 = __ftol();
            iVar12 = (uint)(&pOVar6->y)[iStack_3c] - iVar10;
            if (iVar12 < 0) {
              iVar12 = -iVar12;
            }
            if (((iVar13 < 6) && (iVar12 < 6)) ||
               (uVar5 = RGE_Visible_Map::get_visible
                                  (*(RGE_Visible_Map **)(param_1->md->_padding_ + 0x38),iVar9,iVar10
                                  ), uVar5 == '\x0f')) {
              if (sVar3 == 0x12) {
                pUVar7 = RGE_Static_Object::unitAI(this);
                iVar9 = (**(code **)(pUVar7->_padding_ + 0xc4))
                                  (*(undefined4 *)
                                    ((int)&param_1->importantObjectMemory->id + iStack_3c));
                if (iVar9 == 0) goto LAB_004de1b4;
              }
              fVar15 = TribeInformationAIModule::damageInflictedPerSecond
                                 (param_1,param_3,param_4,pRVar8);
              fVar1 = pRVar8->hp;
              fVar16 = TribeInformationAIModule::timeToBeKilled(param_1,param_3,param_4,pRVar8);
              if ((fVar15 != _DAT_00575580) && (fVar16 != _DAT_00575580)) {
                pOVar6 = param_1->importantObjectMemory;
                iVar9 = __ftol();
                iVar9 = (uint)(&pOVar6->x)[iStack_3c] - iVar9;
                iVar13 = __ftol();
                iVar13 = (uint)(&pOVar6->y)[iStack_3c] - iVar13;
                fStack_30 = SQRT((float)(iVar9 * iVar9 + iVar13 * iVar13));
                if (fStack_30 < _DAT_00575564) {
                  fStack_30 = 1.0;
                }
                bVar2 = (&pOVar6->kills)[iStack_3c];
                iVar9 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x53);
                if (iVar9 < 1) {
                  fStack_1c = 0.0;
                }
                else {
                  iVar9 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x53);
                  iVar13 = debug_rand(s_C__msdev_work_age1_x1_taiinfmd_c,0x110b);
                  fStack_1c = (float)(iVar13 % iVar9);
                }
                iVar13 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x59);
                iVar9 = *(int *)((int)&param_1->importantObjectMemory->attackAttempts + iStack_3c);
                iVar10 = __ftol();
                iVar12 = __ftol();
                uVar5 = RGE_Static_Object::lookupZone(this,iVar12,iVar10);
                if (uVar4 == uVar5) {
                  iVar10 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x7a);
                  fStack_20 = (float)iVar10;
                }
                else {
                  fStack_20 = 0.0;
                }
                fStack_24 = 0.0;
                iVar10 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xb9);
                if (0 < iVar10) {
                  iStack_34 = 0;
                  if (0 < param_4) {
                    fStack_24 = (float)param_4;
                    piVar14 = param_3;
                    do {
                      pRVar8 = MainDecisionAIModule::object
                                         ((MainDecisionAIModule *)param_1->md,*piVar14);
                      if ((pRVar8 != (RGE_Static_Object *)0x0) &&
                         (pUVar7 = RGE_Static_Object::unitAI(pRVar8), pUVar7 != (UnitAIModule *)0x0)
                         ) {
                        pUVar7 = RGE_Static_Object::unitAI(pRVar8);
                        iVar10 = UnitAIModule::currentTarget(pUVar7);
                        if (iVar10 == *(int *)((int)&param_1->importantObjectMemory->id + iStack_3c)
                           ) {
                          iStack_34 = iStack_34 + 1;
                        }
                      }
                      piVar14 = piVar14 + 1;
                      fStack_24 = (float)((int)fStack_24 + -1);
                    } while (fStack_24 != 0.0);
                  }
                  iVar10 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xb9);
                  fStack_24 = (float)iVar10 * (float)iStack_34;
                }
                iVar10 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0xb8);
                iVar12 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x4d);
                iVar11 = TribeTacticalAIModule::strategicNumber(&param_1->md->tacticalAI,0x50);
                fStack_1c = (float)iVar11 * (float)bVar2 +
                            (float)iVar12 / fStack_30 + (float)iVar10 * (fVar16 / (fVar1 / fVar15))
                            + fStack_24 + fStack_20 + (float)iVar13 * (float)iVar9 + fStack_1c;
                if ((pOStack_2c == (ObjectMemory *)0x0) || (fStack_18 < fStack_1c)) {
                  pOStack_2c = (ObjectMemory *)
                               ((int)&param_1->importantObjectMemory->id + iStack_3c);
                  fStack_18 = fStack_1c;
                }
              }
            }
          }
LAB_004de1b4:
          iStack_14 = iStack_14 + 1;
          iStack_3c = iStack_3c + 0x24;
        } while (iStack_14 < param_1->maxImportantObjectMemory);
      }
      return pOStack_2c;
    }
    pOVar6 = (ObjectMemory *)0x0;
  }
  return pOVar6;
}

// --------------------------------------------------

// Function: FUN_004de32a
// Address: 004de32a
int __thiscall FUN_004de32a(TribeInformationAIModule *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  uchar uVar2;
  uchar uVar3;
  RGE_Static_Object *this;
  int iVar4;
  RGE_Static_Object *this_00;
  int iVar5;
  int iVar6;
  float10 fVar7;
  XYPoint *pXVar8;
  int iStack_10;
  XYPoint XStack_8;
  
  this = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,param_2);
  iVar6 = 0;
  if (this == (RGE_Static_Object *)0x0) {
    return 0;
  }
  uVar2 = RGE_Static_Object::currentZone(this);
  iStack_10 = 0;
  param_4 = TribeInformationAIModule::defendPriority(param_1,param_3,param_4);
  param_3 = 0;
  if (0 < param_1->maxImportantObjectMemory) {
    do {
      iVar5 = *(int *)((int)&param_1->importantObjectMemory->id + iVar6);
      if (iVar5 != -1) {
        iVar1 = (param_1->itemsToDefend).numberValue;
        iVar4 = 0;
        if (0 < iVar1) {
          while (iVar4 < (param_1->itemsToDefend).maximumSizeValue) {
            if ((param_1->itemsToDefend).value[iVar4] == iVar5) {
              if ((0 < *(int *)((int)&param_1->importantObjectMemory->attackAttempts + iVar6)) ||
                 (this_00 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,iVar5),
                 this_00 == (RGE_Static_Object *)0x0)) break;
              uVar3 = RGE_Static_Object::currentZone(this_00);
              if (uVar2 != uVar3) {
                XStack_8.x = __ftol();
                XStack_8.y = __ftol();
                pXVar8 = &XStack_8;
                fVar7 = (float10)(**(code **)(this->_padding_ + 0x10c))();
                iVar5 = RGE_Static_Object::withinRangeOfZoneAtPoint(this,uVar2,(float)fVar7,pXVar8);
                if (iVar5 != 1) break;
              }
              iVar5 = TribeInformationAIModule::defendPriority
                                (param_1,(int)*(short *)((int)&param_1->importantObjectMemory->type
                                                        + iVar6),
                                 (int)*(short *)((int)&param_1->importantObjectMemory->group + iVar6
                                                ));
              if (iVar5 < param_4) {
                iStack_10 = (int)&param_1->importantObjectMemory->id + iVar6;
                param_4 = iVar5;
              }
              break;
            }
            iVar4 = iVar4 + 1;
            if (iVar1 <= iVar4) break;
          }
        }
      }
      param_3 = param_3 + 1;
      iVar6 = iVar6 + 0x24;
    } while (param_3 < param_1->maxImportantObjectMemory);
  }
  return iStack_10;
}

// --------------------------------------------------

// Function: FUN_004de49c
// Address: 004de49c
int __thiscall FUN_004de49c(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  
  switch(param_2) {
  case 0x2d:
    iVar1 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0x46);
    return iVar1;
  case 0x6d:
    iVar1 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0x38);
    return iVar1;
  case 0x9e:
  case 0xa3:
    iVar1 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0x36);
    return iVar1;
  case 0x9f:
    iVar1 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0x37);
    return iVar1;
  }
  if (param_3 == 7) {
    iVar1 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0x34);
    return iVar1;
  }
  if (param_3 == 8) {
    iVar1 = TribeTacticalAIModule::strategicNumber
                      ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0x33);
    return iVar1;
  }
  if (param_3 != 0x20) {
    return -1;
  }
  iVar1 = TribeTacticalAIModule::strategicNumber
                    ((TribeTacticalAIModule *)(*(int *)(param_1 + 0x100) + 0x1146c),0x32);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_004de8eb
// Address: 004de8eb
undefined4 __fastcall FUN_004de8eb(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)
{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  char *unaff_EBX;
  char *unaff_EDI;
  
  cVar1 = (char)in_EAX;
  out(0x4d,cVar1);
  *unaff_EDI = *unaff_EDI + (char)((uint)param_2 >> 8);
  out(0x4d,cVar1);
  unaff_EDI[0x4d] = unaff_EDI[0x4d] + (char)param_1;
  *unaff_EBX = *unaff_EBX + cVar1;
  out(0x4d,in_EAX);
  unaff_EDI[0x4d] = unaff_EDI[0x4d] + (char)param_1;
  unaff_EDI[0x4de7] = unaff_EDI[0x4de7] + (char)((uint)unaff_EBX >> 8);
  iVar2 = 0;
  if (0 < param_1[1]) {
    while (iVar2 < param_1[3]) {
      if (*(int *)(*param_1 + iVar2 * 4) == *param_4) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      if (param_1[1] <= iVar2) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004de9c6
// Address: 004de9c6
undefined4 __thiscall FUN_004de9c6(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = 0;
  iVar1 = param_1[1];
  if (0 < iVar1) {
    do {
      if (param_1[3] <= iVar2) break;
      if (*(int *)(*param_1 + iVar2 * 4) == param_2) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if (param_1[3] + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    pvVar3 = operator_new(iVar1 * 4);
    if (pvVar3 != (void *)0x0) {
      iVar2 = 0;
      if (0 < param_1[3]) {
        do {
          if (iVar1 <= iVar2) break;
          iVar2 = iVar2 + 1;
          *(undefined4 *)((int)pvVar3 + iVar2 * 4 + -4) = *(undefined4 *)(*param_1 + -4 + iVar2 * 4)
          ;
        } while (iVar2 < param_1[3]);
      }
      operator_delete((void *)*param_1);
      *param_1 = (int)pvVar3;
      param_1[3] = iVar1;
    }
  }
  *(int *)(*param_1 + param_1[1] * 4) = param_2;
  param_1[1] = param_1[1] + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004dea6a
// Address: 004dea6a
undefined4 __fastcall FUN_004dea6a(int param_1)
{
  return *(undefined4 *)(param_1 + 0x14c);
}

// --------------------------------------------------

// Function: FUN_004dea77
// Address: 004dea77
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004dea77(int param_1,int param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_8;
  int iStack_4;
  
  pRVar2 = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_2);
  iVar5 = 0;
  if (pRVar2 != (RGE_Static_Object *)0x0) {
    param_2 = 0;
    iStack_8 = 0;
    iStack_4 = 0;
    if (0 < *(int *)(param_1 + 0x110)) {
      do {
        iVar3 = *(int *)(*(int *)(param_1 + 0x114) + iVar5);
        iVar1 = *(int *)(param_1 + 0x114) + iVar5;
        if ((((iVar3 != -1) &&
             ((ushort)*(byte *)(iVar1 + 0xb) !=
              (*(MainDecisionAIModule **)(param_1 + 0x100))->player->id)) &&
            (*(short *)(iVar1 + 4) == 0x2d)) &&
           ((pRVar2 = MainDecisionAIModule::object
                                (*(MainDecisionAIModule **)(param_1 + 0x100),iVar3),
            pRVar2 != (RGE_Static_Object *)0x0 && (_DAT_00575580 < pRVar2->owner->attributes[9]))))
{
          iVar1 = *(int *)(param_1 + 0x114) + iVar5;
          iVar3 = __ftol();
          iVar3 = (uint)*(byte *)(iVar1 + 8) - iVar3;
          iVar4 = __ftol();
          iVar4 = (uint)*(byte *)(iVar1 + 9) - iVar4;
          iVar3 = iVar3 * iVar3 + iVar4 * iVar4;
          if ((param_2 == 0) || (iVar3 < iStack_8)) {
            param_2 = iVar1;
            iStack_8 = iVar3;
          }
        }
        iStack_4 = iStack_4 + 1;
        iVar5 = iVar5 + 0x24;
      } while (iStack_4 < *(int *)(param_1 + 0x110));
    }
    return param_2;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004deb95
// Address: 004deb95
bool __thiscall
FUN_004deb95(TribeInformationAIModule *param_1,XYPoint *param_2,int param_3,undefined4 param_4,
            int param_5,int param_6,int *param_7,int *param_8)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_54;
  XYPoint XStack_40;
  XYPoint XStack_38;
  XYPoint XStack_30;
  XYPoint XStack_28;
  XYPoint XStack_20;
  XYPoint XStack_18;
  int iStack_10;
  int iStack_c;
  undefined1 auStack_8 [8];
  
  if (param_5 <= param_6) {
    return false;
  }
  XStack_28.y = (param_2->y - param_5) - param_6;
  XStack_28.x = (param_2->x - param_5) - param_6;
  TribeInformationAIModule::mapBound(param_1,&XStack_28);
  XStack_38.y = param_6 + param_5 + param_2->y;
  XStack_38.x = param_2->x + param_6 + param_5;
  TribeInformationAIModule::mapBound(param_1,&XStack_38);
  XStack_20.x = (param_2->x - param_5) + param_6;
  XStack_20.y = (param_6 - param_5) + param_2->y;
  TribeInformationAIModule::mapBound(param_1,&XStack_20);
  XStack_18.x = (param_2->x - param_6) + param_5;
  XStack_18.y = (param_5 - param_6) + param_2->y;
  TribeInformationAIModule::mapBound(param_1,&XStack_18);
  TribeInformationAIModule::setupInfluenceMap(param_1,0,-1,param_2,&XStack_28,&XStack_38);
  iStack_54 = -1;
  iVar2 = TribeInformationAIModule::groupInfluenceDimension(param_1,param_3);
  iVar4 = XStack_28.x;
  if (XStack_28.x <= XStack_38.x) {
    do {
      iVar8 = XStack_28.y;
      if (XStack_28.y <= XStack_38.y) {
        do {
          if ((((iVar4 < XStack_20.x) || (XStack_18.x < iVar4)) || (iVar8 < XStack_20.y)) ||
             (XStack_18.y < iVar8)) {
            iVar5 = iVar2 / 2;
            XStack_30.x = iVar4 - iVar5;
            XStack_30.y = iVar8 - iVar5;
            iVar3 = TribeInformationAIModule::mapBound(param_1,&XStack_30);
            if (iVar3 != 1) {
              XStack_40.x = iVar4 + iVar5;
              XStack_40.y = iVar8 + iVar5;
              iVar3 = TribeInformationAIModule::mapBound(param_1,&XStack_40);
              if (iVar3 != 1) {
                bVar1 = false;
                iVar3 = XStack_40.y;
                iVar5 = XStack_30.x;
                if (XStack_30.x < XStack_40.x) {
                  do {
                    if (bVar1) break;
                    iVar6 = XStack_30.y;
                    if (XStack_30.y < iVar3) {
                      do {
                        if (bVar1) break;
                        iVar3 = (**(code **)(*param_7 + 0x114))((float)iVar5,(float)iVar6,1);
                        if (iVar3 == 0) {
                          bVar1 = true;
                        }
                        iVar6 = iVar6 + 1;
                        iVar3 = XStack_40.y;
                      } while (iVar6 < XStack_40.y);
                    }
                    iVar5 = iVar5 + 1;
                  } while (iVar5 < XStack_40.x);
                }
                if (!bVar1) {
                  iVar5 = 0x80;
                  iStack_10 = iVar4;
                  iStack_c = iVar8;
                  iVar3 = (**(code **)(*param_7 + 0x1b0))
                                    (&iStack_10,param_2,(float)param_5,auStack_8,1);
                  if (iVar3 == 0) {
                    iVar5 = 0x40;
                  }
                  iVar3 = XStack_40.y;
                  iVar6 = XStack_30.x;
                  if (XStack_30.x <= XStack_40.x) {
                    do {
                      if (bVar1) break;
                      iVar7 = XStack_30.y;
                      if (XStack_30.y <= iVar3) {
                        do {
                          if (bVar1) break;
                          iVar3 = InfluenceMap::lookupValue(&iMap,iVar6,iVar7);
                          if (iVar3 == 0xff) {
                            bVar1 = true;
                          }
                          else {
                            iVar5 = iVar5 + iVar3;
                          }
                          iVar7 = iVar7 + 1;
                          iVar3 = XStack_40.y;
                        } while (iVar7 <= XStack_40.y);
                      }
                      iVar6 = iVar6 + 1;
                    } while (iVar6 <= XStack_40.x);
                  }
                  if ((!bVar1) && ((iStack_54 == -1 || (iStack_54 < iVar5)))) {
                    *param_8 = iVar4;
                    param_8[1] = iVar8;
                    iStack_54 = iVar5;
                  }
                }
              }
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 <= XStack_38.y);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= XStack_38.x);
  }
  return iStack_54 != -1;
}

// --------------------------------------------------

// Function: FUN_004dee89
// Address: 004dee89
// [HELPER] s_____Unsupported_building_size___: "    Unsupported building size (%d x %d)."
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004dee89(TribeInformationAIModule *param_1,int param_2,int param_3,undefined4 param_4,
            int *param_5,int *param_6)
{
  int iVar1;
  short sVar2;
  float fVar3;
  RGE_Map *this;
  AttackMemory *pAVar4;
  BuildingLot *pBVar5;
  uchar uVar6;
  RGE_Static_Object *pRVar7;
  int *piVar8;
  int iVar9;
  AIModule *this_00;
  int iVar10;
  int iVar11;
  ResourceMemory **ppRVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  int iStack_70;
  int iStack_68;
  XYPoint XStack_64;
  float fStack_5c;
  XYPoint XStack_58;
  XYPoint XStack_50;
  XYPoint XStack_48;
  XYPoint XStack_40;
  XYPoint XStack_38;
  XYPoint XStack_30;
  XYPoint XStack_28;
  XYPoint XStack_20;
  XYPoint XStack_18;
  XYPoint XStack_10;
  XYPoint XStack_8;
  
  InfluenceMap::initialize(&iMap,'\x14');
  InfluenceMap::setUnchangeableLimit(&iMap,0xff);
  iVar11 = 0;
  BuildAIModule::numberBuiltItemsOfType((BuildAIModule *)&param_1->md->buildAI,0x44,0);
  BuildAIModule::numberBuiltItemsOfType((BuildAIModule *)&param_1->md->buildAI,0x67,0);
  iVar10 = param_1->mapXSizeValue;
  iVar9 = param_1->mapYSizeValue;
  XStack_8.x = 0;
  XStack_8.y = 0;
  XStack_10.x = iVar10;
  XStack_10.y = iVar9;
  if (((param_2 == 3) || (param_2 == 4)) || (param_2 == 0)) {
    XStack_18.y = iVar9 + -5;
    iVar1 = iVar10 + -5;
    iVar13 = 0;
    if (0 < iVar10) {
      do {
        iVar14 = iVar13;
        if (iVar13 < iVar9) {
          do {
            if (((iVar11 < 5) || (iVar1 < iVar11)) || ((iVar13 < 5 || (XStack_18.y < iVar13)))) {
              InfluenceMap::decrementValue(&iMap,iVar11,iVar13,'\n');
              iVar9 = XStack_10.y;
            }
            iVar13 = iVar13 + 1;
            iVar10 = XStack_10.x;
            iVar14 = XStack_8.y;
          } while (iVar13 < iVar9);
        }
        iVar11 = iVar11 + 1;
        iVar13 = iVar14;
      } while (iVar11 < iVar10);
    }
  }
  if (((param_2 == 1) || (param_2 == 2)) || (param_2 == 9)) {
    fStack_5c = (float)TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(param_1,param_2);
    ppRVar12 = param_1->resources;
    XStack_64.x = 4;
    do {
      iStack_68 = 0;
      if (0 < (int)ppRVar12[4]) {
        iStack_70 = 0;
        do {
          piVar8 = (int *)((int)&(*ppRVar12)->id + iStack_70);
          if ((*(char *)((int)piVar8 + 0xd) == '\x01') ||
             (pRVar7 = MainDecisionAIModule::object((MainDecisionAIModule *)param_1->md,*piVar8),
             pRVar7 == (RGE_Static_Object *)0x0)) goto LAB_004df33a;
          XStack_50.x = __ftol();
          XStack_50.y = __ftol();
          TribeInformationAIModule::mapBound(param_1,&XStack_50);
          XStack_58.x = __ftol();
          XStack_58.y = __ftol();
          TribeInformationAIModule::mapBound(param_1,&XStack_58);
          XStack_38.x = __ftol();
          XStack_38.y = __ftol();
          TribeInformationAIModule::mapBound(param_1,&XStack_38);
          if ((param_2 == 1) || (param_2 == 2)) {
            InfluenceMap::setValue(&iMap,XStack_38.x,XStack_38.y,0xff);
          }
          else {
            InfluenceMap::setValue(&iMap,XStack_50.x,XStack_50.y,XStack_58.x,XStack_58.y,0xff);
          }
          if (param_2 == 1) {
            sVar2 = pRVar7->master_obj->object_group;
            if (sVar2 == 7) {
              if (pRVar7->master_obj->object_group != 7) goto LAB_004df2c3;
              XStack_50.x = XStack_50.x + -5;
              XStack_50.y = XStack_50.y + -5;
              TribeInformationAIModule::mapBound(param_1,&XStack_50);
              XStack_58.x = XStack_58.x + 5;
              XStack_58.y = XStack_58.y + 5;
              TribeInformationAIModule::mapBound(param_1,&XStack_58);
              InfluenceMap::decrementValue
                        (&iMap,XStack_50.x,XStack_50.y,XStack_58.x,XStack_58.y,0x80);
            }
            else if ((((fStack_5c == -NAN) || ((fStack_5c == 4.2039e-45 && (sVar2 == 0x20)))) ||
                     ((fStack_5c == 2.8026e-45 && (sVar2 == 8)))) ||
                    (((fStack_5c == 1.4013e-45 && (sVar2 == 0xf)) ||
                     ((fStack_5c == 0.0 && (((sVar2 != 0x20 && (sVar2 != 8)) && (sVar2 != 0xf)))))))
                    ) {
              XStack_50.x = XStack_50.x + -1;
              XStack_50.y = XStack_50.y + -1;
              TribeInformationAIModule::mapBound(param_1,&XStack_50);
              XStack_58.x = XStack_58.x + 1;
              XStack_58.y = XStack_58.y + 1;
              TribeInformationAIModule::mapBound(param_1,&XStack_58);
              InfluenceMap::incrementValue
                        (&iMap,XStack_50.x,XStack_50.y,XStack_58.x,XStack_58.y,'\b');
              XStack_50.x = XStack_50.x + -3;
              XStack_50.y = XStack_50.y + -3;
              TribeInformationAIModule::mapBound(param_1,&XStack_50);
              XStack_58.x = XStack_58.x + 3;
              XStack_58.y = XStack_58.y + 3;
              TribeInformationAIModule::mapBound(param_1,&XStack_58);
              InfluenceMap::incrementValue
                        (&iMap,XStack_50.x,XStack_50.y,XStack_58.x,XStack_58.y,'\x04');
              XStack_50.x = XStack_50.x + -5;
              XStack_50.y = XStack_50.y + -5;
              TribeInformationAIModule::mapBound(param_1,&XStack_50);
              XStack_58.x = XStack_58.x + 5;
              XStack_58.y = XStack_58.y + 5;
              TribeInformationAIModule::mapBound(param_1,&XStack_58);
              uVar15 = CONCAT44(2,XStack_58.y);
              goto LAB_004df330;
            }
          }
          else {
LAB_004df2c3:
            if ((param_2 == 2) && (pRVar7->master_obj->object_group == 7)) {
              XStack_50.x = XStack_50.x + -3;
              XStack_50.y = XStack_50.y + -3;
              TribeInformationAIModule::mapBound(param_1,&XStack_50);
              XStack_58.x = XStack_58.x + 3;
              XStack_58.y = XStack_58.y + 3;
              TribeInformationAIModule::mapBound(param_1,&XStack_58);
              uVar15 = CONCAT44(0x80,XStack_58.y);
LAB_004df330:
              InfluenceMap::incrementValue
                        (&iMap,XStack_50.x,XStack_50.y,XStack_58.x,(int)uVar15,
                         (uchar)((ulonglong)uVar15 >> 0x20));
            }
          }
LAB_004df33a:
          iStack_68 = iStack_68 + 1;
          iStack_70 = iStack_70 + 0x14;
        } while (iStack_68 < (int)ppRVar12[4]);
      }
      ppRVar12 = ppRVar12 + 1;
      XStack_64.x = XStack_64.x + -1;
    } while (XStack_64.x != 0);
    XStack_64.x = 0;
  }
  if (((((param_2 == 1) || (param_2 == 2)) ||
       (((param_2 == 3 || ((param_2 == 4 || (param_2 == 0)))) || (param_2 == 5)))) ||
      ((param_2 == 6 || (param_2 == 8)))) &&
     (iStack_68 = 0, 0 < (param_1->playerBuildings).numberValue)) {
    do {
      if ((param_1->playerBuildings).maximumSizeValue + -1 < iStack_68) {
        piVar8 = (int *)operator_new(iStack_68 * 4 + 4);
        if (piVar8 != (int *)0x0) {
          iVar10 = 0;
          if (0 < (param_1->playerBuildings).maximumSizeValue) {
            do {
              if (iStack_68 + 1 <= iVar10) break;
              iVar9 = iVar10 + 1;
              piVar8[iVar10] = (param_1->playerBuildings).value[iVar10];
              iVar10 = iVar9;
            } while (iVar9 < (param_1->playerBuildings).maximumSizeValue);
          }
          operator_delete((param_1->playerBuildings).value);
          (param_1->playerBuildings).value = piVar8;
          (param_1->playerBuildings).maximumSizeValue = iStack_68 + 1;
        }
      }
      pRVar7 = MainDecisionAIModule::object
                         ((MainDecisionAIModule *)param_1->md,
                          (param_1->playerBuildings).value[iStack_68]);
      if (pRVar7 != (RGE_Static_Object *)0x0) {
        this_00 = (AIModule *)
                  TribeInformationAIModule::placementCode(param_1,(int)pRVar7->master_obj->id);
        fVar3 = pRVar7->master_obj->radius_x;
        fStack_5c = pRVar7->master_obj->radius_y;
        if (fVar3 == (float)_DAT_00575598) {
LAB_004df4ad:
          iVar10 = __ftol();
          iVar10 = iVar10 + -3;
          XStack_58.x = iVar10;
          iVar9 = __ftol();
          iVar9 = iVar9 + -3;
          XStack_58.y = iVar9;
          XStack_50.x = __ftol();
          XStack_50.x = XStack_50.x + 3;
          XStack_50.y = __ftol();
          XStack_50.y = XStack_50.y + 3;
        }
        else if (fVar3 == (float)_DAT_005755a0) {
          if (this_00 == (AIModule *)0x6) {
LAB_004df5bc:
            iVar10 = __ftol();
            iVar10 = iVar10 + -1;
            XStack_58.x = iVar10;
            iVar9 = __ftol();
            iVar9 = iVar9 + -1;
            XStack_58.y = iVar9;
            XStack_50.x = __ftol();
            XStack_50.x = XStack_50.x + 1;
            XStack_50.y = __ftol();
            XStack_50.y = XStack_50.y + 1;
          }
          else {
            if (param_3 == 0x46) goto LAB_004df4ad;
            iVar10 = __ftol();
            iVar10 = iVar10 + -2;
            XStack_58.x = iVar10;
            iVar9 = __ftol();
            iVar9 = iVar9 + -2;
            XStack_58.y = iVar9;
            XStack_50.x = __ftol();
            XStack_50.x = XStack_50.x + 2;
            XStack_50.y = __ftol();
            XStack_50.y = XStack_50.y + 2;
          }
        }
        else {
          if (fVar3 == _DAT_00575564) {
            if ((this_00 != (AIModule *)0x6) && (this_00 != (AIModule *)&DAT_00000003)) {
              iVar10 = __ftol();
              iVar10 = iVar10 + -2;
              XStack_58.x = iVar10;
              iVar9 = __ftol();
              iVar9 = iVar9 + -2;
              XStack_58.y = iVar9;
              XStack_50.x = __ftol();
              XStack_50.x = XStack_50.x + 1;
              XStack_50.y = __ftol();
              XStack_50.y = XStack_50.y + 1;
              goto LAB_004df622;
            }
            iVar10 = __ftol();
            iVar10 = iVar10 + -1;
            XStack_58.x = iVar10;
            iVar9 = __ftol();
            iVar9 = iVar9 + -1;
          }
          else {
            if (fVar3 != (float)_DAT_005755a8) {
              AIModule::logCommonHistory
                        (this_00,(char *)param_1,s_____Unsupported_building_size___,
                         (double)(fVar3 + fVar3),(double)(fStack_5c + fStack_5c));
              goto LAB_004df9fb;
            }
            if ((this_00 != (AIModule *)0x6) && (this_00 != (AIModule *)0x4)) goto LAB_004df5bc;
            iVar10 = __ftol();
            XStack_58.x = iVar10;
            iVar9 = __ftol();
          }
          XStack_58.y = iVar9;
          XStack_50.x = __ftol();
          XStack_50.y = __ftol();
        }
LAB_004df622:
        if (this_00 == (AIModule *)0x6d) {
          XStack_58.x = iVar10 + -1;
          XStack_58.y = iVar9 + -1;
          XStack_50.x = XStack_50.x + 1;
          XStack_50.y = XStack_50.y + 1;
        }
        TribeInformationAIModule::mapBound(param_1,&XStack_58);
        TribeInformationAIModule::mapBound(param_1,&XStack_50);
        InfluenceMap::setValue(&iMap,XStack_58.x,XStack_58.y,XStack_50.x,XStack_50.y,0xff);
        if ((param_2 == 3) || (param_2 == 0)) {
          iVar10 = __ftol();
          XStack_38.x = XStack_58.x - iVar10;
          XStack_38.y = XStack_58.y - iVar10;
          TribeInformationAIModule::mapBound(param_1,&XStack_38);
          XStack_40.x = XStack_50.x + iVar10;
          XStack_40.y = XStack_50.y + iVar10;
          TribeInformationAIModule::mapBound(param_1,&XStack_40);
          if ((param_2 == 0) && (this_00 == (AIModule *)&DAT_00000003)) {
            InfluenceMap::incrementValue(&iMap,XStack_38.x,XStack_38.y,XStack_40.x,XStack_40.y,'\n')
            ;
          }
          else {
            InfluenceMap::decrementValue(&iMap,XStack_38.x,XStack_38.y,XStack_40.x,XStack_40.y,'\n')
            ;
          }
        }
        else if ((param_2 == 1) || (param_2 == 2)) {
          iVar10 = __ftol();
          XStack_18.y = XStack_58.y - iVar10;
          XStack_18.x = XStack_58.x - iVar10;
          TribeInformationAIModule::mapBound(param_1,&XStack_18);
          XStack_20.y = XStack_50.y + iVar10;
          XStack_20.x = XStack_50.x + iVar10;
          TribeInformationAIModule::mapBound(param_1,&XStack_20);
          InfluenceMap::decrementValue(&iMap,XStack_18.x,XStack_18.y,XStack_20.x,XStack_20.y,'\n');
        }
        else if (param_2 == 5) {
          iVar10 = __ftol();
          XStack_28.x = XStack_58.x + iVar10 * -2;
          XStack_28.y = XStack_58.y + iVar10 * -2;
          TribeInformationAIModule::mapBound(param_1,&XStack_28);
          XStack_30.x = XStack_50.x + iVar10 * 2;
          XStack_30.y = XStack_50.y + iVar10 * 2;
          TribeInformationAIModule::mapBound(param_1,&XStack_30);
          InfluenceMap::decrementValue(&iMap,XStack_28.x,XStack_28.y,XStack_30.x,XStack_30.y,'\x14')
          ;
        }
        else if (param_2 == 8) {
          iVar10 = __ftol();
          XStack_48.x = XStack_58.x - iVar10;
          XStack_48.y = XStack_58.y - iVar10;
          TribeInformationAIModule::mapBound(param_1,&XStack_48);
          XStack_64.x = XStack_50.x + iVar10;
          XStack_64.y = XStack_50.y + iVar10;
          TribeInformationAIModule::mapBound(param_1,&XStack_64);
          InfluenceMap::incrementValue(&iMap,XStack_48.x,XStack_48.y,XStack_64.x,XStack_64.y,'\x14')
          ;
          iVar9 = iVar10 / 2;
          XStack_48.x = XStack_58.x - iVar9;
          XStack_48.y = XStack_58.y - iVar9;
          TribeInformationAIModule::mapBound(param_1,&XStack_48);
          XStack_64.x = XStack_50.x + iVar9;
          XStack_64.y = XStack_50.y + iVar9;
          TribeInformationAIModule::mapBound(param_1,&XStack_64);
          InfluenceMap::incrementValue(&iMap,XStack_48.x,XStack_48.y,XStack_64.x,XStack_64.y,'\x14')
          ;
          iVar10 = iVar10 / 3;
          XStack_48.x = XStack_58.x - iVar10;
          XStack_48.y = XStack_58.y - iVar10;
          TribeInformationAIModule::mapBound(param_1,&XStack_48);
          XStack_64.x = XStack_50.x + iVar10;
          XStack_64.y = XStack_50.y + iVar10;
          TribeInformationAIModule::mapBound(param_1,&XStack_64);
          InfluenceMap::incrementValue(&iMap,XStack_48.x,XStack_48.y,XStack_64.x,XStack_64.y,'\x14')
          ;
        }
      }
LAB_004df9fb:
      iStack_68 = iStack_68 + 1;
    } while (iStack_68 < (param_1->playerBuildings).numberValue);
  }
  if (((param_2 == 3) || (param_2 == 4)) || (param_2 == 0)) {
    iVar10 = *param_5;
    this = *(RGE_Map **)(*(int *)(param_1->md->_padding_ + 0x3c) + 0x28);
    if (iVar10 <= *param_6) {
      iStack_68 = iVar10 * 0x18;
      do {
        iVar9 = param_5[1];
        if (iVar9 <= param_6[1]) {
          do {
            uVar6 = RGE_Map::get_terrain(this,(short)iVar10,(short)iVar9);
            fStack_5c = (float)CONCAT31(fStack_5c._1_3_,uVar6);
            if (uVar6 == '\x01') {
              XStack_20.y = iVar9 + -2;
              XStack_20.x = iVar10 + -2;
              XStack_18.x = XStack_20.x;
              XStack_18.y = XStack_20.y;
              TribeInformationAIModule::mapBound(param_1,&XStack_20);
              TribeInformationAIModule::mapBound(param_1,&XStack_18);
              InfluenceMap::setValue(&iMap,iVar10,iVar9,0xff);
              InfluenceMap::decrementValue
                        (&iMap,XStack_20.x,XStack_20.y,XStack_18.x,XStack_18.y,'\n');
            }
            InfluenceMap::incrementValue
                      (&iMap,iVar10,iVar9,
                       ((byte)(&this->map_row_offset[iVar9]->field_0x5)[iStack_68] >> 5) * '\x05');
            iVar9 = iVar9 + 1;
          } while (iVar9 <= param_6[1]);
        }
        iVar10 = iVar10 + 1;
        iStack_68 = iStack_68 + 0x18;
      } while (iVar10 <= *param_6);
    }
  }
  if ((((param_2 == 3) || (param_2 == 4)) || ((param_2 == 0 || ((param_2 == 6 || (param_2 == 5))))))
     && (iVar10 = 0, 0 < param_1->maxAttackMemories)) {
    iVar9 = 0;
    do {
      pAVar4 = param_1->attackMemories;
      if ((*(int *)((int)&pAVar4->id + iVar9) != -1) &&
         ((ushort)(&pAVar4->targetOwner)[iVar9] == *(ushort *)(param_1->md->_padding_ + 0x4a))) {
        XStack_20.x = (&pAVar4->minX)[iVar9] - 4;
        XStack_20.y = (&pAVar4->minY)[iVar9] - 4;
        TribeInformationAIModule::mapBound(param_1,&XStack_20);
        XStack_18.x = (&param_1->attackMemories->maxX)[iVar9] + 4;
        XStack_18.y = (&param_1->attackMemories->maxY)[iVar9] + 4;
        TribeInformationAIModule::mapBound(param_1,&XStack_18);
        InfluenceMap::incrementValue(&iMap,XStack_20.x,XStack_20.y,XStack_18.x,XStack_18.y,'\x10');
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 0x18;
    } while (iVar10 < param_1->maxAttackMemories);
  }
  if (param_2 == 0) {
    TribeTacticalAIModule::setGroupInfluences(&param_1->md->tacticalAI,&iMap);
  }
  InfluenceMap::setConnectionCount(&iMap,&XStack_8,&XStack_10,0xff,1,(uint)(param_2 != 4),1);
  if ((param_2 != 0) && (iVar10 = 0, 0 < param_1->maxBuildingLots)) {
    do {
      pBVar5 = param_1->buildingLots;
      if ((pBVar5[iVar10].typeID == param_3) && (pBVar5[iVar10].status == '\x02')) {
        InfluenceMap::setValue(&iMap,(uint)pBVar5[iVar10].x,(uint)pBVar5[iVar10].y,0xff);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_1->maxBuildingLots);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004dfcd4
// Address: 004dfcd4
undefined4 __thiscall FUN_004dfcd4(int param_1,int *param_2)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*param_2 < 0) {
    *param_2 = 0;
  }
  else {
    if (*param_2 < *(int *)(param_1 + 0x104)) goto LAB_004dfd04;
    *param_2 = *(int *)(param_1 + 0x104) + -1;
  }
  uVar1 = 1;
LAB_004dfd04:
  if (param_2[1] < 0) {
    param_2[1] = 0;
    return 1;
  }
  if (*(int *)(param_1 + 0x108) <= param_2[1]) {
    uVar1 = 1;
    param_2[1] = *(int *)(param_1 + 0x108) + -1;
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_004dfd34
// Address: 004dfd34
int FUN_004dfd34(int param_1)
{
  if (param_1 < 2) {
    return 2;
  }
  return param_1 * param_1;
}

// --------------------------------------------------

// Function: FUN_004dfd57
// Address: 004dfd57
void __thiscall
FUN_004dfd57(int param_1,int *param_2,uint param_3,int param_4,int *param_5,int *param_6)
{
  short sVar1;
  ushort uVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *this;
  int *piVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float fVar12;
  XYPoint *pXVar13;
  int iStack_3c;
  int iStack_34;
  XYPoint XStack_2c;
  int aiStack_24 [3];
  ushort uStack_18;
  undefined4 uStack_14;
  undefined1 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  *param_5 = 0;
  *param_6 = 0;
  aiStack_24[0] = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  fStack_c = 0.0;
  fStack_8 = 0.0;
  fStack_4 = 0.0;
  this = MainDecisionAIModule::object(*(MainDecisionAIModule **)(param_1 + 0x100),param_4);
  if (this != (RGE_Static_Object *)0x0) {
    uVar3 = RGE_Static_Object::currentZone(this);
    iStack_34 = 0;
    if (0 < *(int *)(param_1 + 0x110)) {
      iStack_3c = 0;
      do {
        piVar5 = (int *)(*(int *)(param_1 + 0x114) + iStack_3c);
        if ((*(byte *)((int)piVar5 + 0xb) == param_3) &&
           (pRVar6 = MainDecisionAIModule::object
                               (*(MainDecisionAIModule **)(param_1 + 0x100),*piVar5),
           pRVar6 != (RGE_Static_Object *)0x0)) {
          uVar4 = RGE_Static_Object::currentZone(pRVar6);
          if (uVar3 != uVar4) {
            XStack_2c.x = __ftol();
            XStack_2c.y = __ftol();
            pXVar13 = &XStack_2c;
            fVar11 = (float10)(**(code **)(this->_padding_ + 0x10c))();
            iVar7 = RGE_Static_Object::withinRangeOfZoneAtPoint(this,uVar3,(float)fVar11,pXVar13);
            if (iVar7 != 1) goto LAB_004e0002;
          }
          pRVar6 = MainDecisionAIModule::object
                             (*(MainDecisionAIModule **)(param_1 + 0x100),
                              *(int *)(iStack_3c + *(int *)(param_1 + 0x114)));
          if (pRVar6 != (RGE_Static_Object *)0x0) {
            iVar9 = iStack_3c + *(int *)(param_1 + 0x114);
            iVar7 = __ftol();
            iVar10 = (uint)*(byte *)(iVar9 + 8) - iVar7;
            if (iVar10 < 0) {
              iVar10 = -iVar10;
            }
            iVar8 = __ftol();
            iVar9 = (uint)*(byte *)(iVar9 + 9) - iVar8;
            if (iVar9 < 0) {
              iVar9 = -iVar9;
            }
            if (((iVar10 < 6) && (iVar9 < 6)) ||
               (uVar4 = RGE_Visible_Map::get_visible
                                  (*(RGE_Visible_Map **)
                                    (*(int *)(*(int *)(param_1 + 0x100) + 0xf0) + 0x38),iVar7,iVar8)
               , uVar4 == '\x0f')) {
              sVar1 = *(short *)(iStack_3c + 6 + *(int *)(param_1 + 0x114));
              if ((sVar1 != 3) && (sVar1 != 0x1b)) {
                *param_5 = *param_5 + 1;
              }
              sVar1 = *(short *)(iStack_3c + 6 + *(int *)(param_1 + 0x114));
              if (((sVar1 != 2) && (sVar1 != 0x15)) &&
                 ((sVar1 != 0x16 &&
                  ((sVar1 != 0x14 && (*(short *)(iStack_3c + *(int *)(param_1 + 0x114) + 4) != 0x2d)
                   ))))) {
                *param_6 = *param_6 + 1;
              }
              iVar7 = iStack_3c + *(int *)(param_1 + 0x114);
              fVar12 = RGE_Static_Object::distance_to_position
                                 (this,(float)*(byte *)(iVar7 + 8),(float)*(byte *)(iVar7 + 9),
                                  (float)*(byte *)(iStack_3c + 10 + *(int *)(param_1 + 0x114)));
              if ((float)aiStack_24[0] < fVar12) {
                aiStack_24[0] = __ftol();
              }
              iVar7 = iStack_3c + *(int *)(param_1 + 0x114);
              uVar2 = *(ushort *)(iStack_3c + 0xc + *(int *)(param_1 + 0x114));
              if ((short)uStack_18 < (short)uVar2) {
                uStack_18 = uVar2;
              }
              if (0 < *(int *)(iVar7 + 0x10)) {
                uStack_18 = *(ushort *)(iVar7 + 0x10);
              }
              if (*(byte *)(iVar7 + 0x14) != 0) {
                uStack_18 = (ushort)*(byte *)(iVar7 + 0x14);
              }
              if (fStack_c < *(float *)(iVar7 + 0x18)) {
                fStack_c = *(float *)(iVar7 + 0x18);
              }
              if (fStack_8 < *(float *)(iVar7 + 0x1c)) {
                fStack_8 = *(float *)(iVar7 + 0x1c);
              }
              if (fStack_4 < *(float *)(iVar7 + 0x20)) {
                fStack_4 = *(float *)(iVar7 + 0x20);
              }
            }
          }
        }
LAB_004e0002:
        iStack_34 = iStack_34 + 1;
        iStack_3c = iStack_3c + 0x24;
      } while (iStack_34 < *(int *)(param_1 + 0x110));
    }
  }
  piVar5 = aiStack_24;
  for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
    *param_2 = *piVar5;
    piVar5 = piVar5 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e003b
// Address: 004e003b
undefined4 FUN_004e003b(int *param_1,int *param_2,int param_3)
{
  int iVar1;
  
  iVar1 = (*param_2 - *param_1) * (*param_2 - *param_1) +
          (param_2[1] - param_1[1]) * (param_2[1] - param_1[1]);
  if ((param_3 == 0) && (1 < iVar1)) {
    return 0;
  }
  if ((param_3 == 1) && (2 < iVar1)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e008d
// Address: 004e008d
int FUN_004e008d(int *param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2 - *param_1;
  iVar2 = param_2[1] - param_1[1];
  if (*param_2 == *param_1) {
    return ((-1 < iVar2) - 1 & 0xfffffffc) + 5;
  }
  if (param_2[1] == param_1[1]) {
    return ((-1 < iVar1) - 1 & 4) + 3;
  }
  if (iVar1 < 0) {
    return ((-1 < iVar2) - 1 & 0xfffffffa) + 6;
  }
  return ((-1 < iVar2) - 1 & 0xfffffffe) + 4;
}

// --------------------------------------------------

// Function: FUN_004e00f4
// Address: 004e00f4
undefined4 FUN_004e00f4(undefined4 param_1)
{
  switch(param_1) {
  case 0x2d:
    return 7;
  default:
    return 5;
  case 0x32:
    return 8;
  case 0x44:
    return 2;
  case 0x45:
  case 0x4f:
  case 199:
    return 3;
  case 0x46:
  case 0x52:
  case 0x54:
  case 0x6e:
  case 0x114:
    return 6;
  case 0x48:
  case 0x75:
  case 0x9b:
    return 4;
  case 0x67:
    return 1;
  case 0x6d:
    return 9;
  }
}

// --------------------------------------------------

// Function: FUN_004e0165
// Address: 004e0165
void __fastcall
FUN_004e0165(byte *param_1,char *param_2,char param_3,char param_4,undefined1 param_5)
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int in_EAX;
  byte *pbVar5;
  uint *puVar6;
  int *piVar7;
  void *pvVar8;
  undefined1 *puVar9;
  byte bVar10;
  int iVar12;
  byte bVar13;
  int iVar14;
  byte *unaff_EBX;
  uint *unaff_ESI;
  bool bVar15;
  bool bVar16;
  int unaff_retaddr;
  int iVar11;
  
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  uVar3 = *unaff_ESI;
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  pbVar5 = (byte *)((in_EAX + -0x5a009c02) - (uint)CARRY4(uVar3,(uint)param_1) & 0x1d004e01);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  *unaff_ESI = (uint)(param_1 + *unaff_ESI);
  bVar1 = *pbVar5;
  bVar13 = (byte)param_2;
  *pbVar5 = *pbVar5 + bVar13;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,CARRY1(bVar1,bVar13));
  *pbVar5 = *pbVar5 + bVar13 + CARRY1(bVar1,bVar13);
  bVar10 = (byte)pbVar5;
  bVar16 = CARRY1(*param_1,bVar10) || CARRY1(*param_1 + bVar10,bVar15);
  *param_1 = *param_1 + bVar10 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar1 = *pbVar5;
  bVar2 = *pbVar5;
  *pbVar5 = bVar2 + bVar13 + bVar15;
  *param_2 = *param_2 + bVar10 + (CARRY1(bVar1,bVar13) || CARRY1(bVar2 + bVar13,bVar15));
  pbVar5 = pbVar5 + *(int *)(pbVar5 + (int)param_2);
  puVar6 = (uint *)(pbVar5 + 0x10101010);
  bVar1 = (byte)*puVar6 + bVar13;
  bVar15 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,(byte *)0xefefefef < pbVar5);
  *(byte *)puVar6 = bVar1 + ((byte *)0xefefefef < pbVar5);
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  bVar10 = (byte)param_1;
  bVar1 = (byte)*puVar6 + bVar10;
  bVar15 = CARRY1((byte)*puVar6,bVar10) || CARRY1(bVar1,bVar16);
  *(byte *)puVar6 = bVar1 + bVar16;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar15 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar16);
  *(byte *)puVar6 = bVar1 + bVar16;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar15 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar16);
  *(byte *)puVar6 = bVar1 + bVar16;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar15 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar16);
  *(byte *)puVar6 = bVar1 + bVar16;
  bVar1 = (byte)*puVar6 + bVar13;
  bVar16 = CARRY1((byte)*puVar6,bVar13) || CARRY1(bVar1,bVar15);
  *(byte *)puVar6 = bVar1 + bVar15;
  uVar3 = *puVar6;
  bVar1 = (byte)*puVar6 + bVar13;
  *(byte *)puVar6 = bVar1 + bVar16;
  *(byte *)puVar6 = (byte)*puVar6 + bVar13 + (CARRY1((byte)uVar3,bVar13) || CARRY1(bVar1,bVar16));
  *puVar6 = *puVar6 | (uint)param_2;
  uVar3 = *puVar6;
  *(byte *)puVar6 = (byte)*puVar6 + bVar13;
  *(byte *)puVar6 = (byte)*puVar6 + bVar13 + CARRY1((byte)uVar3,bVar13);
  bVar10 = bVar10 | *unaff_EBX;
  iVar11 = CONCAT31((int3)((uint)param_1 >> 8),bVar10);
  bVar15 = CARRY1((byte)*puVar6,bVar13);
  *(byte *)puVar6 = (byte)*puVar6 + bVar13;
  uVar3 = *puVar6;
  bVar1 = (byte)*puVar6 + bVar13;
  *(byte *)puVar6 = bVar1 + bVar15;
  *(byte *)puVar6 = (byte)*puVar6 + bVar13 + (CARRY1((byte)uVar3,bVar13) || CARRY1(bVar1,bVar15));
  pbVar5 = (byte *)((uint)puVar6 | 0x10);
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar13;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,CARRY1(bVar1,bVar13));
  *pbVar5 = *pbVar5 + bVar13 + CARRY1(bVar1,bVar13);
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar1 = *pbVar5;
  bVar2 = *pbVar5;
  *pbVar5 = bVar2 + bVar13 + bVar15;
  *pbVar5 = *pbVar5 + bVar13 + (CARRY1(bVar1,bVar13) || CARRY1(bVar2 + bVar13,bVar15));
  pbVar5 = (byte *)((uint)puVar6 | 0x10101010);
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar13;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,CARRY1(bVar1,bVar13));
  *pbVar5 = *pbVar5 + bVar13 + CARRY1(bVar1,bVar13);
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar1 = (byte)*unaff_ESI + bVar10;
  bVar15 = CARRY1((byte)*unaff_ESI,bVar10) || CARRY1(bVar1,bVar16);
  *(byte *)unaff_ESI = bVar1 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar15 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar16);
  *pbVar5 = *pbVar5 + bVar13 + bVar16;
  bVar16 = CARRY1(*pbVar5,bVar13) || CARRY1(*pbVar5 + bVar13,bVar15);
  *pbVar5 = *pbVar5 + bVar13 + bVar15;
  bVar1 = *pbVar5;
  bVar2 = *pbVar5;
  *pbVar5 = bVar2 + bVar13 + bVar16;
  pbVar5[-0x6f6f6f70] = SCARRY1(bVar1,bVar13) != SCARRY1(bVar2 + bVar13,bVar16);
  iVar14 = -1;
  iVar12 = 0;
  iVar4 = *(int *)(iVar11 + 500);
  if (0 < iVar4) {
    piVar7 = *(int **)(iVar11 + 0x1f8);
    do {
      if (((*piVar7 == unaff_retaddr) && (*(char *)((int)piVar7 + 5) == param_3)) &&
         (*(char *)((int)piVar7 + 6) == param_4)) {
        *(undefined1 *)(*(int **)(iVar11 + 0x1f8) + iVar12 * 2 + 1) = param_5;
        return;
      }
      if ((iVar14 == -1) && (*piVar7 == -1)) {
        iVar14 = iVar12;
      }
      iVar12 = iVar12 + 1;
      piVar7 = piVar7 + 2;
    } while (iVar12 < iVar4);
  }
  if (iVar14 == -1) {
    pvVar8 = operator_new(iVar4 << 4);
    if (pvVar8 != (void *)0x0) {
      iVar14 = 0;
      if (0 < *(int *)(iVar11 + 500)) {
        puVar9 = (undefined1 *)((int)pvVar8 + 6);
        do {
          iVar14 = iVar14 + 1;
          *(undefined4 *)(puVar9 + -6) = *(undefined4 *)(*(int *)(iVar11 + 0x1f8) + -8 + iVar14 * 8)
          ;
          puVar9[-1] = *(undefined1 *)(*(int *)(iVar11 + 0x1f8) + -3 + iVar14 * 8);
          *puVar9 = *(undefined1 *)(*(int *)(iVar11 + 0x1f8) + -2 + iVar14 * 8);
          puVar9[-2] = *(undefined1 *)(*(int *)(iVar11 + 0x1f8) + -4 + iVar14 * 8);
          puVar9 = puVar9 + 8;
        } while (iVar14 < *(int *)(iVar11 + 500));
      }
      if (iVar14 < *(int *)(iVar11 + 500) * 2) {
        puVar9 = (undefined1 *)((int)pvVar8 + iVar14 * 8 + 6);
        do {
          *(undefined4 *)(puVar9 + -6) = 0xffffffff;
          puVar9[-1] = 0;
          *puVar9 = 0;
          puVar9[-2] = param_5;
          iVar14 = iVar14 + 1;
          puVar9 = puVar9 + 8;
        } while (iVar14 < *(int *)(iVar11 + 500) * 2);
      }
      operator_delete(*(void **)(iVar11 + 0x1f8));
      *(void **)(iVar11 + 0x1f8) = pvVar8;
      *(int *)((int)pvVar8 + *(int *)(iVar11 + 500) * 8) = unaff_retaddr;
      *(char *)(*(int *)(iVar11 + 0x1f8) + 5 + *(int *)(iVar11 + 500) * 8) = param_3;
      *(char *)(*(int *)(iVar11 + 0x1f8) + 6 + *(int *)(iVar11 + 500) * 8) = param_4;
      *(undefined1 *)(*(int *)(iVar11 + 0x1f8) + 4 + *(int *)(iVar11 + 500) * 8) = param_5;
      *(int *)(iVar11 + 500) = *(int *)(iVar11 + 500) << 1;
      return;
    }
  }
  else {
    iVar14 = iVar14 * 8;
    *(int *)(iVar14 + *(int *)(iVar11 + 0x1f8)) = unaff_retaddr;
    *(char *)(iVar14 + 5 + *(int *)(iVar11 + 0x1f8)) = param_3;
    *(char *)(iVar14 + 6 + *(int *)(iVar11 + 0x1f8)) = param_4;
    *(undefined1 *)(iVar14 + 4 + *(int *)(iVar11 + 0x1f8)) = param_5;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e0462
// Address: 004e0462
void __thiscall FUN_004e0462(int param_1,int param_2,char param_3,char param_4,char param_5)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 500)) {
    piVar2 = *(int **)(param_1 + 0x1f8);
    piVar3 = piVar2;
    while (((*piVar3 != param_2 || (*(char *)((int)piVar3 + 5) != param_3)) ||
           (*(char *)((int)piVar3 + 6) != param_4))) {
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 2;
      if (*(int *)(param_1 + 500) <= iVar4) {
        return;
      }
    }
    if (param_5 != '\x03') {
      *(char *)(piVar2 + iVar4 * 2 + 1) = param_5;
      return;
    }
    iVar1 = iVar4 * 8;
    piVar2[iVar4 * 2] = -1;
    *(undefined1 *)(*(int *)(param_1 + 0x1f8) + 5 + iVar1) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x1f8) + 6 + iVar1) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x1f8) + 4 + iVar1) = 3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004e050a
// Address: 004e050a
int * __thiscall FUN_004e050a(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 500) < 1) {
    return (int *)0x0;
  }
  piVar1 = *(int **)(param_1 + 0x1f8);
  while ((*piVar1 != param_2 || ((char)piVar1[1] != '\0'))) {
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 2;
    if (*(int *)(param_1 + 500) <= iVar2) {
      return (int *)0x0;
    }
  }
  return *(int **)(param_1 + 0x1f8) + iVar2 * 2;
}

// --------------------------------------------------

// Function: FUN_004e0557
// Address: 004e0557
undefined4 __thiscall FUN_004e0557(int param_1,int param_2,char param_3,char param_4)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 500) < 1) {
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x1f8);
  while ((((*piVar1 != param_2 || ((char)piVar1[1] != '\x02')) ||
          (*(char *)((int)piVar1 + 5) != param_3)) || (*(char *)((int)piVar1 + 6) != param_4))) {
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 2;
    if (*(int *)(param_1 + 500) <= iVar2) {
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e05b8
// Address: 004e05b8
undefined4 __thiscall FUN_004e05b8(int param_1,int param_2,uint param_3,uint param_4,int param_5)
{
  int *piVar1;
  int iStack_8;
  
  iStack_8 = 0;
  if (*(int *)(param_1 + 500) < 1) {
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x1f8);
  do {
    if ((*piVar1 == param_2) && ((char)piVar1[1] == '\x01')) {
      if (((int)((uint)*(byte *)((int)piVar1 + 5) - param_5) <= (int)(param_3 & 0xff)) &&
         ((((int)(param_3 & 0xff) <= (int)(param_5 + (uint)*(byte *)((int)piVar1 + 5)) &&
           ((int)((uint)*(byte *)((int)piVar1 + 6) - param_5) <= (int)(param_4 & 0xff))) &&
          ((int)(param_4 & 0xff) <= (int)(param_5 + (uint)*(byte *)((int)piVar1 + 6)))))) {
        return 1;
      }
    }
    piVar1 = piVar1 + 2;
    iStack_8 = iStack_8 + 1;
    if (*(int *)(param_1 + 500) <= iStack_8) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004e0f3d
// Address: 004e0f3d
undefined4 __thiscall FUN_004e0f3d(int param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 < 1) {
    return 0;
  }
  piVar1 = (int *)(param_1 + 0x1b8);
  while ((((param_3 < piVar1[-1] || (param_4 < *piVar1)) || (piVar1[7] < param_3)) ||
         (piVar1[8] < param_4))) {
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 2;
    if (param_2 <= iVar2) {
      return 0;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004e0f8d
// Address: 004e0f8d
void __thiscall
FUN_004e0f8d(TribeInformationAIModule *param_1,uchar param_2,uchar param_3,uchar param_4,
            uchar param_5,uchar param_6,short param_7,uchar param_8,ulong param_9,int param_10)
{
  TribeInformationAIModule::storeAttackMemory
            (param_1,param_2,param_3,param_4,param_3,param_4,param_5,param_6,param_7,param_8,param_9
             ,param_10);
  return;
}

// --------------------------------------------------

// Function: FUN_004e0fc7
// Address: 004e0fc7
int __thiscall
FUN_004e0fc7(int param_1,undefined1 param_2,byte param_3,undefined1 param_4,byte param_5,
            undefined1 param_6,byte param_7,byte param_8,undefined2 param_9,undefined1 param_10,
            undefined4 param_11,undefined4 param_12)
{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_4;
  
  if ((0 < *(int *)(param_1 + 0x104)) && (0 < *(int *)(param_1 + 0x108))) {
    iVar6 = ((uint)param_5 + (uint)param_3) * 4;
    iVar8 = (iVar6 / *(int *)(param_1 + 0x104)) / 2;
    iVar6 = (iVar6 / *(int *)(param_1 + 0x108)) / 2;
    if (4 < iVar8) {
      iVar8 = 3;
    }
    if (4 < iVar6) {
      iVar6 = 3;
    }
    uVar1 = *(ushort *)(*(int *)(*(int *)(param_1 + 0x100) + 0xf0) + 0x4a);
    if (param_8 == uVar1) {
      piVar3 = (int *)(param_1 + 0x40c + (iVar6 + iVar8 * 4) * 0xc);
    }
    else {
      if (param_7 != uVar1) goto LAB_004e1077;
      piVar3 = (int *)(param_1 + 0x410 + (iVar6 + iVar8 * 4) * 0xc);
    }
    *piVar3 = *piVar3 + 1;
  }
LAB_004e1077:
  iVar6 = -1;
  iVar7 = 0;
  iVar8 = iVar6;
  if (0 < *(int *)(param_1 + 0x1fc)) {
    iVar2 = *(int *)(param_1 + 0x200);
    iStack_4 = -0x18;
    iVar5 = 0;
    puVar4 = (uint *)(iVar2 + 0x10);
    do {
      iVar8 = iVar7;
      if (*(int *)(iVar5 + iVar2) == -1) break;
      if ((iVar6 == -1) || (*(uint *)(iStack_4 + 0x10 + iVar2) < *puVar4)) {
        iVar6 = iVar7;
        iStack_4 = iVar5;
      }
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x18;
      puVar4 = puVar4 + 6;
      iVar8 = iVar6;
    } while (iVar7 < *(int *)(param_1 + 0x1fc));
  }
  if (iVar8 != -1) {
    iVar6 = iVar8 * 0x18;
    *(int *)(iVar6 + *(int *)(param_1 + 0x200)) = iVar7;
    *(undefined1 *)(iVar6 + 4 + *(int *)(param_1 + 0x200)) = param_2;
    *(byte *)(iVar6 + 5 + *(int *)(param_1 + 0x200)) = param_3;
    *(undefined1 *)(iVar6 + 6 + *(int *)(param_1 + 0x200)) = param_4;
    *(byte *)(iVar6 + 7 + *(int *)(param_1 + 0x200)) = param_5;
    *(undefined1 *)(iVar6 + 8 + *(int *)(param_1 + 0x200)) = param_6;
    *(byte *)(iVar6 + 9 + *(int *)(param_1 + 0x200)) = param_7;
    *(byte *)(iVar6 + 10 + *(int *)(param_1 + 0x200)) = param_8;
    *(undefined2 *)(iVar6 + 0xc + *(int *)(param_1 + 0x200)) = param_9;
    *(undefined1 *)(iVar6 + 0xe + *(int *)(param_1 + 0x200)) = param_10;
    *(undefined4 *)(iVar6 + 0x10 + *(int *)(param_1 + 0x200)) = param_11;
    *(undefined4 *)(iVar6 + 0x14 + *(int *)(param_1 + 0x200)) = param_12;
  }
  return iVar8;
}

// --------------------------------------------------


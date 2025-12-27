// GLOBAL FUNCTIONS PART 0
// Function: FUN_00401121
// Address: 00401121
undefined4 __fastcall FUN_00401121(int param_1)
{
  return *(undefined4 *)(param_1 + 0x10);
}

// --------------------------------------------------

// Function: FUN_00401134
// Address: 00401134
undefined4 __fastcall FUN_00401134(int param_1)
{
  return *(undefined4 *)(param_1 + 0x14);
}

// --------------------------------------------------

// Function: FUN_00401144
// Address: 00401144
RGE_Action_Attack * __thiscall FUN_00401144(RGE_Action_Attack *param_1,byte param_2)
{
  RGE_Action_Attack::~RGE_Action_Attack(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040116e
// Address: 0040116e
RGE_Action * __thiscall
FUN_0040116e(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Static_Object *param_3,int param_4,
            int param_5,RGE_Action_Object *param_6,float param_7,RGE_Static_Object *param_8,
            undefined2 param_9,undefined2 param_10)
{
  float fVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c0d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Action_Attack::_vftable_;
  param_1->action_type = 9;
  RGE_Action::set_target_obj(param_1,param_3);
  param_1[1].obj = param_6;
  *(float *)&param_1[1].state = param_7;
  param_1[1].target_obj = param_8;
  *(undefined2 *)&param_1[1].target_obj2 = param_9;
  param_1->target_x = -1.0;
  param_1->target_y = -1.0;
  param_1->target_z = -1.0;
  param_1[1]._padding_ = param_4;
  *(int *)&param_1[1].action_type = param_5;
  *(undefined2 *)((int)&param_1[1].target_obj2 + 2) = param_10;
  *(undefined1 *)&param_1[1].targetID = 0;
  *(undefined1 *)((int)&param_1[1].targetID + 2) = 0;
  if ((param_3 == (RGE_Static_Object *)0x0) || (param_3->owner != (RGE_Player *)param_2->_padding_))
{
    *(undefined1 *)((int)&param_1[1].targetID + 1) = 0;
  }
  else {
    *(undefined1 *)((int)&param_1[1].targetID + 1) = 1;
  }
  if (param_4 == 0) {
    iVar2 = param_1->obj->_padding_;
    iVar4 = *(int *)(iVar2 + 0xc0);
    if (iVar4 == 0) {
      iVar4 = *(int *)(iVar2 + 0xbc);
    }
    param_1[1]._padding_ = iVar4;
  }
  if (param_5 == 0) {
    *(undefined4 *)&param_1[1].action_type = *(undefined4 *)(param_1->obj->_padding_ + 0xfc);
  }
  if (param_6 == (RGE_Action_Object *)0x0) {
    param_1[1].obj = *(RGE_Action_Object **)(param_1->obj->_padding_ + 0x18);
  }
  if ((param_7 == (float)DAT_0056e0b8._0_4_) &&
     (fVar1 = *(float *)(param_1->obj->_padding_ + 0x114),
     bVar3 = fVar1 == (float)DAT_0056e0b8._0_4_, *(float *)&param_1[1].state = fVar1, bVar3)) {
    *(undefined4 *)&param_1[1].state = 0x3ecccccd;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004012a7
// Address: 004012a7
RGE_Action * __thiscall
FUN_004012a7(RGE_Action *param_1,RGE_Action_Object *param_2,float param_3,float param_4,
            float param_5,int param_6,int param_7,RGE_Action_Object *param_8,float param_9,
            RGE_Static_Object *param_10,undefined2 param_11,undefined2 param_12)
{
  float fVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->target_x = param_3;
  *(float *)&param_1[1].state = param_9;
  param_1[1].target_obj = param_10;
  param_1->target_z = param_5;
  param_1->target_y = param_4;
  *(undefined2 *)&param_1[1].target_obj2 = param_11;
  param_1->_padding_ = (int)&RGE_Action_Attack::_vftable_;
  param_1->action_type = 9;
  param_1[1]._padding_ = param_6;
  *(int *)&param_1[1].action_type = param_7;
  param_1[1].obj = param_8;
  *(undefined2 *)((int)&param_1[1].target_obj2 + 2) = param_12;
  *(undefined1 *)&param_1[1].targetID = 0;
  *(undefined1 *)((int)&param_1[1].targetID + 1) = 0;
  *(undefined1 *)((int)&param_1[1].targetID + 2) = 2;
  if (param_6 == 0) {
    iVar2 = param_1->obj->_padding_;
    iVar4 = *(int *)(iVar2 + 0xc0);
    if (iVar4 == 0) {
      iVar4 = *(int *)(iVar2 + 0xbc);
    }
    param_1[1]._padding_ = iVar4;
  }
  if (param_7 == 0) {
    *(undefined4 *)&param_1[1].action_type = *(undefined4 *)(param_1->obj->_padding_ + 0xfc);
  }
  if (param_8 == (RGE_Action_Object *)0x0) {
    param_1[1].obj = *(RGE_Action_Object **)(param_1->obj->_padding_ + 0x18);
  }
  if ((param_9 == (float)DAT_0056e0b8._0_4_) &&
     (fVar1 = *(float *)(param_1->obj->_padding_ + 0x114),
     bVar3 = fVar1 == (float)DAT_0056e0b8._0_4_, *(float *)&param_1[1].state = fVar1, bVar3)) {
    *(undefined4 *)&param_1[1].state = 0x3ecccccd;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040139d
// Address: 0040139d
void __fastcall FUN_0040139d(RGE_Action *param_1)
{
  param_1->_padding_ = (int)&RGE_Action_Attack::_vftable_;
  RGE_Action::~RGE_Action(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004013ab
// Address: 004013ab
void __thiscall FUN_004013ab(RGE_Action *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  
  iVar2 = param_2;
  RGE_Action::save(param_1,param_2);
  rge_write(iVar2,&param_1[1].state,4);
  rge_write(iVar2,&param_1[1].target_obj,4);
  rge_write(iVar2,&param_1[1].target_obj2,2);
  rge_write(iVar2,(void *)((int)&param_1[1].target_obj2 + 2),2);
  rge_write(iVar2,&param_1[1].targetID,1);
  rge_write(iVar2,(void *)((int)&param_1[1].targetID + 1),1);
  rge_write(iVar2,(void *)((int)&param_1[1].targetID + 2),1);
  if (param_1[1]._padding_ == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22(extraout_var,*(undefined2 *)(param_1[1]._padding_ + 0x72));
  }
  rge_write(iVar2,&param_2,2);
  iVar1 = *(int *)&param_1[1].action_type;
  if (iVar1 == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x72));
  }
  rge_write(iVar2,&param_2,2);
  if (param_1[1].obj == (RGE_Action_Object *)0x0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = CONCAT22(extraout_var_00,*(undefined2 *)((int)&(param_1[1].obj)->_padding_ + 2));
  }
  rge_write(iVar2,&param_2,2);
  return;
}

// --------------------------------------------------

// Function: FUN_004014a7
// Address: 004014a7
void __fastcall FUN_004014a7(RGE_Action_Attack *param_1)
{
  UnitAIModule *pUVar1;
  int iVar2;
  float10 fVar3;
  RGE_Action_Attack *pRStack_4;
  
  pRStack_4 = param_1;
  fVar3 = (float10)(**(code **)(*(int *)param_1->_padding_ + 0xfc))();
  if (fVar3 != (float10)(double)DAT_0056e0b8._8_8_) {
    pUVar1 = RGE_Static_Object::unitAI((RGE_Static_Object *)param_1->_padding_);
    if (pUVar1 != (UnitAIModule *)0x0) {
      pUVar1 = RGE_Static_Object::unitAI((RGE_Static_Object *)param_1->_padding_);
      iVar2 = UnitAIModule::currentOrder(pUVar1);
      if (iVar2 == 0x2d5) goto LAB_004014fc;
    }
    (**(code **)(param_1->_padding_ + 0x5c))(4);
    return;
  }
LAB_004014fc:
  pRStack_4 = (RGE_Action_Attack *)0xffffffff;
  iVar2 = RGE_Action_Attack::ready_to_attack(param_1,(int *)&pRStack_4);
  if ((iVar2 == 0) && (pRStack_4 != (RGE_Action_Attack *)0x1)) {
    (**(code **)(param_1->_padding_ + 0x5c))(0xd);
    return;
  }
  (**(code **)(param_1->_padding_ + 0x5c))(6);
  return;
}

// --------------------------------------------------

// Function: FUN_00401537
// Address: 00401537
undefined4 __fastcall FUN_00401537(int *param_1)
{
  (**(code **)(*param_1 + 0x5c))(1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040154d
// Address: 0040154d
void __thiscall FUN_0040154d(RGE_Action_Attack *param_1,RGE_Action_Move_To *param_2)
{
  RGE_Action *this;
  int iVar1;
  RGE_Sprite *pRVar2;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c106;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1->_padding_);
  *(char *)&param_1->_padding_ = (char)param_2;
  switch((uint)param_2 & 0xff) {
  case 1:
  case 0xd:
  case 0xe:
    iVar1 = *(int *)param_1->_padding_;
LAB_0040172c:
    pRVar2 = param_1->wait_sprite;
    break;
  case 2:
    param_1->indirect_fire_flag = '\0';
    *unaff_FS_OFFSET = uStack_c;
    return;
  default:
    goto switchD_0040158f_caseD_3;
  case 4:
    if (param_1->indirect_fire_flag != '\0') {
      param_1->indirect_fire_flag = param_1->indirect_fire_flag + 0xff;
    }
    if (param_1->_padding_ == 0) {
      param_2 = (RGE_Action_Move_To *)operator_new(0x44);
      uStack_4 = 1;
      if (param_2 != (RGE_Action_Move_To *)0x0) {
        this = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (param_2,(RGE_Action_Object *)param_1->_padding_,(float)param_1->_padding_,
                          (float)param_1->_padding_,(float)param_1->_padding_,param_1->range,
                          param_1->move_sprite);
        goto LAB_0040162e;
      }
    }
    else {
      param_2 = (RGE_Action_Move_To *)operator_new(0x44);
      uStack_4 = 0;
      if (param_2 != (RGE_Action_Move_To *)0x0) {
        this = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (param_2,(RGE_Action_Object *)param_1->_padding_,
                          (RGE_Static_Object *)param_1->_padding_,param_1->range,
                          param_1->move_sprite);
        goto LAB_0040162e;
      }
    }
    this = (RGE_Action *)0x0;
LAB_0040162e:
    uStack_4 = 0xffffffff;
    if (this == (RGE_Action *)0x0) {
      if ((char)param_1->_padding_ == '\0') {
        iVar1 = ((int *)param_1->_padding_)[1];
        (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar1,iVar1,0x1f9,0x262,0,0);
      }
      (**(code **)(param_1->_padding_ + 0x5c))(1);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action_List::add_action((RGE_Action_List *)param_1->_padding_,this);
    RGE_Action::setSubAction(this,'\x01');
    param_1->_padding_ = 0;
    *unaff_FS_OFFSET = uStack_c;
    return;
  case 6:
    if ((param_1->indirect_fire_flag != '\0') && (param_1->_padding_ != 0)) {
      param_1->indirect_fire_flag = '\0';
    }
    param_2 = (RGE_Action_Move_To *)0xffffffff;
    iVar1 = RGE_Action_Attack::ready_to_attack(param_1,(int *)&param_2);
    if (iVar1 != 0) {
      RGE_Combat_Object::reset_attack_timer((RGE_Combat_Object *)param_1->_padding_);
      (**(code **)(param_1->_padding_ + 0x5c))(7);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    iVar1 = *(int *)param_1->_padding_;
    if (param_1->missile_id != -1) goto LAB_0040172c;
    pRVar2 = param_1->fight_sprite;
    break;
  case 7:
    (**(code **)(*(int *)param_1->_padding_ + 0x38))(param_1->fight_sprite);
    param_1->need_to_attack = '\x01';
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  (**(code **)(iVar1 + 0x38))(pRVar2);
switchD_0040158f_caseD_3:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00401746
// Address: 00401746
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

// Function: FUN_00401b21
// Address: 00401b21
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __fastcall FUN_00401b21(int *param_1)
{
  float fVar1;
  short sVar2;
  RGE_Static_Object *pRVar3;
  char cVar4;
  uchar uVar5;
  int iVar6;
  UnitAIModule *pUVar7;
  int iVar8;
  float10 fVar9;
  float fVar10;
  float fVar11;
  undefined4 *puStack_8;
  
  cVar4 = (**(code **)(*(int *)param_1[2] + 0x1f0))(param_1[4],param_1[8],param_1[9]);
  if (cVar4 == '\0') {
    return false;
  }
  iVar8 = param_1[4];
  if (iVar8 == 0) {
    fVar10 = RGE_Static_Object::distance_to_position
                       ((RGE_Static_Object *)param_1[2],(float)param_1[8],(float)param_1[9],
                        (float)param_1[10]);
    if (fVar10 < (float)param_1[0x14]) {
      *puStack_8 = 0;
LAB_00401d71:
      if ((char)param_1[0xf] == '\0') {
        iVar8 = ((int *)param_1[2])[1];
        (**(code **)(*(int *)param_1[2] + 0x148))(iVar8,iVar8,0x1fe,0,0,0);
      }
      fVar9 = (float10)(**(code **)(*(int *)param_1[2] + 0xfc))();
      if (fVar9 != (float10)(double)DAT_0056e0b8._8_8_) {
        pUVar7 = RGE_Static_Object::unitAI((RGE_Static_Object *)param_1[2]);
        if (pUVar7 == (UnitAIModule *)0x0) {
          return false;
        }
        pUVar7 = RGE_Static_Object::unitAI((RGE_Static_Object *)param_1[2]);
        iVar8 = UnitAIModule::currentOrder(pUVar7);
        if (iVar8 != 0x2d5) {
          return false;
        }
      }
      (**(code **)(*param_1 + 0x5c))(0xd);
      return false;
    }
    fVar11 = *(float *)(*(int *)(param_1[2] + 8) + 0x30);
    fVar1 = *(float *)(*(int *)(param_1[2] + 8) + 0x34);
    if (fVar10 <= (SQRT(fVar1 * fVar1 + fVar11 * fVar11) + (float)param_1[0x13]) - _DAT_0056e0cc)
    goto LAB_00401ea0;
    *puStack_8 = 2;
  }
  else {
    if (((0 < *(short *)(*(int *)(iVar8 + 0xc) + 0x4a)) &&
        (sVar2 = *(short *)(*(int *)(iVar8 + 8) + 0x14), sVar2 != 3)) && (sVar2 != 0x1b)) {
      iVar8 = __ftol();
      iVar6 = __ftol();
      uVar5 = RGE_Visible_Map::get_visible
                        (*(RGE_Visible_Map **)(*(int *)(param_1[2] + 0xc) + 0x38),iVar6,iVar8);
      if (uVar5 == '\0') {
        (**(code **)(*param_1 + 0x5c))(0xd);
        return false;
      }
      if ((uVar5 == 0x80) && (*(char *)(*(int *)(param_1[4] + 8) + 0x65) == '\0')) {
        (**(code **)(*param_1 + 0x5c))(0xd);
        return false;
      }
    }
    pRVar3 = (RGE_Static_Object *)param_1[4];
    if (((pRVar3->world_x == (float)param_1[8]) && (pRVar3->world_y == (float)param_1[9])) &&
       (pRVar3->world_z == (float)param_1[10])) {
LAB_00401ea0:
      *puStack_8 = 1;
      cVar4 = (**(code **)(*(int *)param_1[2] + 0x7c))();
      return cVar4 != '\0';
    }
    fVar11 = pRVar3->world_x - (float)param_1[8];
    fVar1 = pRVar3->world_y - (float)param_1[9];
    fVar10 = pRVar3->world_z - (float)param_1[10];
    if (((((fVar11 <= ram0x0056e0c8) && (_DAT_0056e0d0 <= fVar11)) && (fVar1 <= ram0x0056e0c8)) &&
        ((_DAT_0056e0d0 <= fVar1 && (fVar10 <= ram0x0056e0c8)))) && (_DAT_0056e0d0 <= fVar10))
    goto LAB_00401ea0;
    fVar11 = RGE_Static_Object::distance_to_object((RGE_Static_Object *)param_1[2],pRVar3);
    fVar1 = *(float *)(*(int *)(param_1[2] + 8) + 0x30);
    fVar10 = *(float *)(*(int *)(param_1[2] + 8) + 0x34);
    if (fVar11 < (float)param_1[0x14]) {
      *puStack_8 = 0;
      goto LAB_00401d71;
    }
    if (fVar11 <= (SQRT(fVar10 * fVar10 + fVar1 * fVar1) + (float)param_1[0x13]) - _DAT_0056e0cc) {
      iVar8 = param_1[4];
      param_1[8] = *(int *)(iVar8 + 0x38);
      param_1[9] = *(int *)(iVar8 + 0x3c);
      param_1[10] = *(int *)(iVar8 + 0x40);
      goto LAB_00401ea0;
    }
    *puStack_8 = 2;
  }
  if ((char)param_1[0xf] == '\0') {
    iVar8 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar8,iVar8,0x1fd,0,0,0);
  }
  fVar9 = (float10)(**(code **)(*(int *)param_1[2] + 0xfc))();
  if (fVar9 == (float10)(double)DAT_0056e0b8._8_8_) {
LAB_00401e78:
    (**(code **)(*param_1 + 0x5c))(0xd);
    return false;
  }
  pUVar7 = RGE_Static_Object::unitAI((RGE_Static_Object *)param_1[2]);
  if (pUVar7 != (UnitAIModule *)0x0) {
    pUVar7 = RGE_Static_Object::unitAI((RGE_Static_Object *)param_1[2]);
    iVar8 = UnitAIModule::currentOrder(pUVar7);
    if (iVar8 == 0x2d5) goto LAB_00401e78;
  }
  (**(code **)(*param_1 + 0x5c))(4);
  return false;
}

// --------------------------------------------------

// Function: FUN_00401ef8
// Address: 00401ef8
void __thiscall FUN_00401ef8(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 != 0) {
    if (((param_3 == 0) || (param_4 == 0)) || (iVar1 != *(int *)(param_3 + 0x34))) {
      if (iVar1 != *(int *)(*(int *)(*(int *)(param_1 + 8) + 8) + 0xbc)) goto LAB_00401f3f;
      uVar2 = *(undefined4 *)(param_2 + 0xbc);
    }
    else {
      uVar2 = *(undefined4 *)(param_4 + 0x34);
    }
    *(undefined4 *)(param_1 + 0x40) = uVar2;
  }
LAB_00401f3f:
  iVar1 = *(int *)(param_1 + 0x44);
  if (iVar1 == 0) goto LAB_00401f81;
  if (param_3 == 0) {
LAB_00401f6a:
    if (iVar1 != *(int *)(*(int *)(*(int *)(param_1 + 8) + 8) + 0xfc)) goto LAB_00401f81;
    uVar2 = *(undefined4 *)(param_2 + 0xfc);
  }
  else if ((param_4 == 0) || (iVar1 != *(int *)(param_3 + 0x38))) {
    if ((param_3 == 0) || ((param_4 == 0 || (iVar1 != *(int *)(param_3 + 0x3c)))))
    goto LAB_00401f6a;
    uVar2 = *(undefined4 *)(param_4 + 0x3c);
  }
  else {
    uVar2 = *(undefined4 *)(param_4 + 0x38);
  }
  *(undefined4 *)(param_1 + 0x44) = uVar2;
LAB_00401f81:
  iVar1 = *(int *)(param_1 + 0x48);
  if (iVar1 != 0) {
    if (param_3 != 0) {
      if ((param_4 != 0) && (iVar1 == *(int *)(param_3 + 0x38))) {
        *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_4 + 0x38);
        return;
      }
      if ((param_3 != 0) && ((param_4 != 0 && (iVar1 == *(int *)(param_3 + 0x3c))))) {
        *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_4 + 0x3c);
        return;
      }
    }
    if (iVar1 == *(int *)(*(int *)(*(int *)(param_1 + 8) + 8) + 0x18)) {
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x18);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00401fd1
// Address: 00401fd1
RGE_Action * __thiscall FUN_00401fd1(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  param_1->_padding_ = (int)&RGE_Action_Bird::_vftable_;
  param_1->action_type = 10;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00402008
// Address: 00402008
RGE_Action_Bird * __thiscall FUN_00402008(RGE_Action_Bird *param_1,byte param_2)
{
  RGE_Action_Bird::~RGE_Action_Bird(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00402035
// Address: 00402035
RGE_Action * __thiscall
FUN_00402035(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&RGE_Action_Bird::_vftable_;
  param_1->action_type = 10;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040207d
// Address: 0040207d
void __thiscall FUN_0040207d(int *param_1,char param_2)
{
  int *piVar1;
  
  if (param_2 != '\0') {
    piVar1 = (int *)param_1[2];
    (**(code **)(*piVar1 + 0x34))(piVar1[0xe],piVar1[0xf],0x40c00000);
    (**(code **)(*param_1 + 0x5c))(3);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: FUN_004020bc
// Address: 004020bc
// [HELPER] s_C__msdev_work_age1_x1_act_bird_c: "C:\msdev\work\age1_x1\act_bird.cpp"
void __thiscall FUN_004020bc(int param_1,char param_2)
{
  int *piVar1;
  int iVar2;
  
  *(char *)(param_1 + 0xc) = param_2;
  if (param_2 == '\x04') {
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_act_bird_c,0x44);
    *(float *)(param_1 + 0x2c) = (float)((iVar2 * 10) / 0x7fff + 5);
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x34);
  }
  else {
    if (param_2 != '\x06') {
      RGE_Action_List::delete_list(*(RGE_Action_List **)(param_1 + 0x34));
      return;
    }
    iVar2 = debug_rand(s_C__msdev_work_age1_x1_act_bird_c,0x4c);
    *(float *)(param_1 + 0x2c) = (float)((iVar2 * 10) / 0x7fff + 5);
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x38);
  }
  piVar1 = *(int **)(param_1 + 8);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x38))(iVar2);
    return;
  }
  (**(code **)(*piVar1 + 0x38))(*(undefined4 *)(piVar1[2] + 0x18));
  return;
}

// --------------------------------------------------

// Function: FUN_0040217c
// Address: 0040217c
// [HELPER] s_C__msdev_work_age1_x1_act_bird_c: "C:\msdev\work\age1_x1\act_bird.cpp"
uint __fastcall FUN_0040217c(int *param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  RGE_Action_Move_To *this;
  RGE_Action *pRVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c11b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if ((float)DAT_0056e138 < (float)param_1[0xb]) {
    param_1[0xb] = (int)((float)param_1[0xb] -
                        *(float *)(*(int *)(*(int *)(param_1[2] + 0xc) + 0x3c) + 0x84));
  }
  uVar2 = *(byte *)(param_1 + 3) - 1;
  switch(uVar2) {
  case 0:
    *unaff_FS_OFFSET = uStack_c;
    return CONCAT31((int3)(uVar2 >> 8),1);
  case 2:
    iVar1 = *(int *)(*(int *)(*(int *)(param_1[2] + 0xc) + 0x3c) + 0x28);
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_act_bird_c,0x84);
    param_1[8] = (int)(float)((iVar3 * *(int *)(iVar1 + 8)) / 0x7fff);
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_act_bird_c,0x85);
    param_1[9] = (int)(float)((iVar3 * *(int *)(iVar1 + 0xc)) / 0x7fff);
    param_1[10] = *(int *)(param_1[2] + 0x40);
    this = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (this == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (this,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9],
                          (float)param_1[10],*(float *)(param_1[0xc] + 0x24),
                          (RGE_Sprite *)((RGE_Action_Object *)param_1[2])->_padding_);
    }
    uStack_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      uVar2 = (**(code **)(*param_1 + 0x5c))(3);
      *unaff_FS_OFFSET = this;
      return uVar2 & 0xffffff00;
    }
    RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],pRVar4);
    uVar2 = (**(code **)(*param_1 + 0x5c))(4);
    *unaff_FS_OFFSET = this;
    return uVar2 & 0xffffff00;
  case 3:
    if ((float)param_1[0xb] <= (float)DAT_0056e138) {
      (**(code **)(*param_1 + 0x5c))(6);
    }
    uVar2 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    uVar2 = (uVar2 & 0xff) - 1;
    if (uVar2 == 0) {
      uVar2 = (**(code **)(*param_1 + 0x5c))(3);
      *unaff_FS_OFFSET = param_1;
      return uVar2 & 0xffffff00;
    }
    break;
  case 5:
    if ((float)param_1[0xb] <= (float)DAT_0056e138) {
      (**(code **)(*param_1 + 0x5c))(4);
    }
    uVar2 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    uVar2 = (uVar2 & 0xff) - 1;
    if (uVar2 == 0) {
      uVar2 = (**(code **)(*param_1 + 0x5c))(3);
      *unaff_FS_OFFSET = param_1;
      return uVar2 & 0xffffff00;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar2 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_0040239b
// Address: 0040239b
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

// Function: FUN_004023e8
// Address: 004023e8
RGE_Action_Enter * __thiscall FUN_004023e8(RGE_Action_Enter *param_1,byte param_2)
{
  RGE_Action_Enter::~RGE_Action_Enter(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040240e
// Address: 0040240e
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

RGE_Action * __thiscall
FUN_0040240e(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  code *pcVar1;
  char cVar2;
  uchar uVar3;
  int iVar4;
  RGE_Action *pRVar5;
  int unaff_EBX;
  int *unaff_FS_OFFSET;
  float fVar6;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  float fStack_10;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c138;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Action_Enter::_vftable_;
  param_1->action_type = 3;
  param_1->task = param_3;
  RGE_Action::set_target_obj(param_1,param_4);
  if (param_4 == (RGE_Static_Object *)0x0) goto LAB_004025d6;
  param_1->target_x = param_4->world_x;
  param_1->target_y = param_4->world_y;
  param_1->target_z = param_4->world_z;
  pcVar1 = *(code **)(param_4->_padding_ + 0x134);
  cVar2 = (*pcVar1)();
  if (cVar2 == '\x02') {
    uVar3 = RGE_Static_Object::more_room(param_4);
    if (uVar3 == '\x01') {
      iVar4 = RGE_Player::computerPlayer((RGE_Player *)param_1->obj->_padding_);
      if (iVar4 != 0) goto LAB_004024ad;
    }
    else {
LAB_004024ad:
      iVar4 = RGE_Player::computerPlayer((RGE_Player *)param_1->obj->_padding_);
      if (iVar4 != 1) goto LAB_004024bd;
    }
LAB_004024df:
    uStack_1c = __ftol();
    uStack_18 = __ftol();
    uStack_24 = __ftol();
    uStack_20 = __ftol();
    iVar4 = (**(code **)(param_2->_padding_ + 0x1b4))(&uStack_1c,&uStack_24,&fStack_14,2,2,1);
    if (iVar4 == 1) {
      fStack_10 = (float)unaff_EBX;
      param_1->target_x = (float)unaff_EBX - _DAT_0056e1a0;
      fStack_14 = (float)(int)param_1;
      param_1->target_y = (float)(int)param_1 - _DAT_0056e1a0;
      (**(code **)(iStack_c + 0x154))(fStack_10,fStack_14,param_4->world_z,0x3f000000,1);
    }
    else {
      param_1->target_x = param_4->world_x;
      param_1->target_y = param_4->world_y;
      (**(code **)(iStack_c + 0x154))
                (param_2->_padding_,param_2->_padding_,param_4->world_z,0x3f000000,1);
    }
  }
  else {
LAB_004024bd:
    cVar2 = (*pcVar1)();
    if (cVar2 == '\v') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_4[2].unitAIValue);
      if (pRVar5->target2ID == 0) goto LAB_004024df;
    }
    cVar2 = (*pcVar1)();
    if (cVar2 == '\v') {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_4[2].unitAIValue);
      fVar6 = RGE_Action::targetX(pRVar5);
      param_1->target_x = fVar6;
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_4[2].unitAIValue);
      fVar6 = RGE_Action::targetY(pRVar5);
      param_1->target_y = fVar6;
    }
  }
LAB_004025d6:
  *unaff_FS_OFFSET = iStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004025ed
// Address: 004025ed
void __fastcall FUN_004025ed(RGE_Action *param_1)
{
  param_1->_padding_ = (int)&RGE_Action_Enter::_vftable_;
  RGE_Action::~RGE_Action(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004025fb
// Address: 004025fb
void __fastcall FUN_004025fb(int *param_1)
{
  (**(code **)(*param_1 + 0x5c))(4);
  return;
}

// --------------------------------------------------

// Function: FUN_0040260a
// Address: 0040260a
void __thiscall FUN_0040260a(int *param_1,undefined1 param_2)
{
  RGE_Action_Move_To *this;
  RGE_Action *this_00;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c15b;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
  *(undefined1 *)(param_1 + 3) = param_2;
  switch(param_2) {
  case 2:
    param_1[0xb] = 0x3f800000;
  case 1:
  case 0xd:
  case 0xe:
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
  default:
    *unaff_FS_OFFSET = uStack_c;
    return;
  case 4:
    break;
  }
  this = (RGE_Action_Move_To *)operator_new(0x44);
  uStack_4 = 0;
  if (this == (RGE_Action_Move_To *)0x0) {
    this_00 = (RGE_Action *)0x0;
  }
  else {
    this_00 = (RGE_Action *)
              RGE_Action_Move_To::RGE_Action_Move_To
                        (this,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9],
                         (float)param_1[10],*(float *)(param_1[0xc] + 0x24),
                         *(RGE_Sprite **)(param_1[0xc] + 0x34));
  }
  uStack_4 = 0xffffffff;
  if (this_00 == (RGE_Action *)0x0) {
    (**(code **)(*param_1 + 0x5c))(0xd);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],this_00);
  RGE_Action::setSubAction(this_00,'\x01');
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0040270e
// Address: 0040270e
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

// Function: FUN_00402b68
// Address: 00402b68
RGE_Action_Explore * __thiscall FUN_00402b68(RGE_Action_Explore *param_1,byte param_2)
{
  RGE_Action_Explore::~RGE_Action_Explore(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00402b95
// Address: 00402b95
RGE_Action * __thiscall
FUN_00402b95(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&RGE_Action_Explore::_vftable_;
  param_1->action_type = 4;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00402bdd
// Address: 00402bdd
void __fastcall FUN_00402bdd(int *param_1)
{
  if (param_1[8] == -0x40800000) {
    (**(code **)(*param_1 + 0x5c))(3);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(0xb);
  return;
}

// --------------------------------------------------

// Function: FUN_00402bfd
// Address: 00402bfd
void __thiscall FUN_00402bfd(int *param_1,undefined1 param_2)
{
  int iVar1;
  RGE_Action_Move_To *this;
  RGE_Action *this_00;
  undefined4 unaff_ESI;
  RGE_Sprite *pRVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar3;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c17b;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
  *(undefined1 *)(param_1 + 3) = param_2;
  switch(param_2) {
  case 2:
    uVar3 = *(undefined4 *)(((int *)param_1[2])[2] + 0x18);
    (**(code **)(*(int *)param_1[2] + 0x38))();
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0x54))(0);
    (**(code **)(iVar1 + 0x58))(0);
    param_1[8] = -0x40800000;
    param_1[9] = -0x40800000;
    param_1[10] = -0x40800000;
    *unaff_FS_OFFSET = uVar3;
    return;
  case 3:
    iVar1 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar1,iVar1,0x202,0x25d,0,0);
  case 1:
  case 0xd:
  case 0xe:
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
  default:
    *unaff_FS_OFFSET = uStack_c;
    return;
  case 0xb:
    break;
  }
  if ((param_1[0xc] == 0) ||
     (pRVar2 = *(RGE_Sprite **)(param_1[0xc] + 0x34), pRVar2 == (RGE_Sprite *)0x0)) {
    pRVar2 = *(RGE_Sprite **)(*(int *)(param_1[2] + 8) + 0xbc);
  }
  this = (RGE_Action_Move_To *)operator_new(0x44);
  uStack_4 = 0;
  if (this == (RGE_Action_Move_To *)0x0) {
    this_00 = (RGE_Action *)0x0;
  }
  else {
    this_00 = (RGE_Action *)
              RGE_Action_Move_To::RGE_Action_Move_To
                        (this,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9],
                         (float)param_1[10],0.0,pRVar2);
  }
  uStack_4 = 0xffffffff;
  if (this_00 == (RGE_Action *)0x0) {
    (**(code **)(*param_1 + 0x5c))(0xd);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  RGE_Action::setSubAction(this_00,'\x01');
  RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],this_00);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00402d67
// Address: 00402d67
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
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_00402e95
// Address: 00402e95
RGE_Action * __thiscall FUN_00402e95(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c198;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Action_Gather::_vftable_;
  param_1->action_type = 5;
  rge_read(param_2,param_1 + 1,4);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00402f07
// Address: 00402f07
RGE_Action_Gather * __thiscall FUN_00402f07(RGE_Action_Gather *param_1,byte param_2)
{
  RGE_Action_Gather::~RGE_Action_Gather(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00402f35
// Address: 00402f35
RGE_Action * __thiscall
FUN_00402f35(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c1b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Action_Gather::_vftable_;
  param_1->action_type = 5;
  RGE_Action::set_target_obj(param_1,param_4);
  if (param_4 != (RGE_Static_Object *)0x0) {
    param_1->target_x = param_4->world_x;
    param_1->target_y = param_4->world_y;
    param_1->target_z = param_4->world_z;
    param_1[1]._padding_ = (int)param_4->master_obj->id;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00402fc6
// Address: 00402fc6
RGE_Action * __thiscall
FUN_00402fc6(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&RGE_Action_Gather::_vftable_;
  param_1->action_type = 5;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  param_1[1]._padding_ = -1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00403014
// Address: 00403014
void __thiscall FUN_00403014(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  return;
}

// --------------------------------------------------

// Function: FUN_00403042
// Address: 00403042
void __thiscall FUN_00403042(int *param_1,char param_2)
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
         ((float)DAT_0056e278._0_4_ < *(float *)(iVar3 + 0x44))) {
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

// Function: FUN_0040310c
// Address: 0040310c
void __thiscall FUN_0040310c(RGE_Action_Gather *param_1,byte param_2)
{
  short sVar1;
  RGE_Sound *this;
  int *piVar2;
  RGE_Master_Static_Object *pRVar3;
  char cVar4;
  RGE_Action_Move_To *pRVar5;
  RGE_Sprite *pRVar6;
  RGE_Action *pRVar7;
  RGE_Static_Object *pRVar8;
  int unaff_ESI;
  int iVar9;
  int *unaff_FS_OFFSET;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c1f1;
  *unaff_FS_OFFSET = (int)&iStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1->_padding_);
  *(byte *)&param_1->_padding_ = param_2;
  switch(param_2 - 1) {
  case 0:
  case 0xc:
  case 0xd:
    param_1->_padding_ = 0;
    break;
  case 1:
    param_1->_padding_ = 0;
    iVar9 = *(int *)param_1->_padding_;
    pRVar6 = RGE_Action_Gather::get_wait_sprite(param_1);
    (**(code **)(iVar9 + 0x38))();
    iVar9 = param_1->_padding_;
    (**(code **)(iVar9 + 0x54))(0);
    (**(code **)(iVar9 + 0x58))(0);
    param_1->_padding_ = -0x40800000;
    param_1->_padding_ = -0x40800000;
    param_1->_padding_ = -0x40800000;
    *unaff_FS_OFFSET = (int)pRVar6;
    return;
  case 2:
    iVar9 = ((int *)param_1->_padding_)[1];
    (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar9,iVar9,0x202,0x261,param_1->targetType,0)
    ;
    param_1->_padding_ = -0x3ee00000;
    break;
  case 3:
    iVar9 = param_1->_padding_;
    param_1->_padding_ = 0;
    if (iVar9 == 0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    param_1->_padding_ = *(int *)(iVar9 + 0x38);
    param_1->_padding_ = *(int *)(iVar9 + 0x3c);
    param_1->_padding_ = *(int *)(iVar9 + 0x40);
    pRVar5 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 1;
    if (pRVar5 != (RGE_Action_Move_To *)0x0) {
      pRVar6 = RGE_Action_Gather::get_move_sprite(param_1);
      pRVar7 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar5,(RGE_Action_Object *)param_1->_padding_,
                          (RGE_Static_Object *)param_1->_padding_,
                          *(float *)(param_1->_padding_ + 0x24),pRVar6);
      goto LAB_0040344b;
    }
    goto LAB_00403449;
  default:
    goto switchD_00403147_caseD_4;
  case 5:
    param_1->_padding_ = 0;
    iVar9 = *(int *)param_1->_padding_;
    pRVar6 = RGE_Action_Gather::get_move_sprite(param_1);
    goto LAB_00403535;
  case 6:
    param_1->_padding_ = 0;
    sVar1 = *(short *)(param_1->_padding_ + 0x14);
    if ((short)((int *)param_1->_padding_)[0x13] != sVar1) {
      (**(code **)(*(int *)param_1->_padding_ + 0x80))
                (CONCAT22((short)(param_2 - 1 >> 0x10),sVar1),0);
    }
    (**(code **)(*(int *)param_1->_padding_ + 0x38))(*(undefined4 *)(param_1->_padding_ + 0x38));
    this = *(RGE_Sound **)(param_1->_padding_ + 0x44);
    if (this != (RGE_Sound *)0x0) {
      RGE_Sound::play(this,1);
      *unaff_FS_OFFSET = iStack_c;
      return;
    }
    goto switchD_00403147_caseD_4;
  case 7:
    piVar2 = (int *)param_1->_padding_;
    if ((float)piVar2[0x11] <= (float)DAT_0056e278._0_4_) {
      iVar9 = param_1->_padding_;
      if (((iVar9 != 0) && (*(float *)(iVar9 + 0x44) <= (float)DAT_0056e278._0_4_)) &&
         (cVar4 = (**(code **)(*piVar2 + 0x138))((int)*(short *)(*(int *)(iVar9 + 8) + 0x10)),
         cVar4 == '\0')) {
        (**(code **)(param_1->_padding_ + 0x54))(0);
      }
      (**(code **)(param_1->_padding_ + 0x5c))(3);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    if (param_1->_padding_ == 0) {
      if (*(short *)(piVar2[2] + 0xe8) == -1) {
        (**(code **)(param_1->_padding_ + 0x58))(0);
      }
      else {
        cVar4 = (**(code **)(*piVar2 + 0x140))();
        iVar9 = param_1->_padding_;
        pRVar8 = (RGE_Static_Object *)param_1->_padding_;
        pRVar3 = pRVar8->master_obj;
        if (cVar4 == '\x01') {
          pRVar8 = RGE_Object_List::find_by_master_ids
                             (pRVar8->owner->objects,(int)*(short *)&pRVar3[1].radius_x,
                              (int)*(short *)((int)&pRVar3[1].radius_x + 2),pRVar8->world_x,
                              pRVar8->world_y,'\x01','\x02',pRVar8);
          (**(code **)(iVar9 + 0x58))(pRVar8);
        }
        else {
          pRVar8 = RGE_Object_List::find_by_master_ids
                             (pRVar8->owner->objects,(int)*(short *)&pRVar3[1].radius_x,
                              (int)*(short *)((int)&pRVar3[1].radius_x + 2),pRVar8->world_x,
                              pRVar8->world_y,'\x01','\x02',(RGE_Static_Object *)0x0);
          (**(code **)(iVar9 + 0x58))(pRVar8);
        }
      }
      if (param_1->_padding_ == 0) {
        iVar9 = ((int *)param_1->_padding_)[1];
        (**(code **)(*(int *)param_1->_padding_ + 0x148))(iVar9,iVar9,0x203,0x261,0,0);
        (**(code **)(param_1->_padding_ + 0x5c))(0xd);
        *unaff_FS_OFFSET = iVar9;
        return;
      }
    }
    pRVar5 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 2;
    if (pRVar5 != (RGE_Action_Move_To *)0x0) {
      pRVar6 = RGE_Action_Gather::get_move_sprite(param_1);
      pRVar7 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar5,(RGE_Action_Object *)param_1->_padding_,
                          (RGE_Static_Object *)param_1->_padding_,
                          *(float *)(param_1->_padding_ + 0x24),pRVar6);
      goto LAB_0040344b;
    }
LAB_00403449:
    pRVar7 = (RGE_Action *)0x0;
LAB_0040344b:
    uStack_4 = 0xffffffff;
    if (pRVar7 == (RGE_Action *)0x0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action_List::add_action((RGE_Action_List *)param_1->_padding_,pRVar7);
    RGE_Action::setSubAction(pRVar7,'\x01');
    *unaff_FS_OFFSET = iStack_c;
    return;
  case 10:
  case 0xe:
    param_1->_padding_ = 0;
    pRVar5 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (pRVar5 == (RGE_Action_Move_To *)0x0) {
      pRVar7 = (RGE_Action *)0x0;
    }
    else {
      pRVar6 = RGE_Action_Gather::get_move_sprite(param_1);
      pRVar7 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar5,(RGE_Action_Object *)param_1->_padding_,(float)param_1->_padding_,
                          (float)param_1->_padding_,(float)param_1->_padding_,
                          *(float *)(param_1->_padding_ + 0x24),pRVar6);
    }
    uStack_4 = 0xffffffff;
    if (pRVar7 == (RGE_Action *)0x0) {
      (**(code **)(param_1->_padding_ + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action::setSubAction(pRVar7,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)param_1->_padding_,pRVar7);
    *unaff_FS_OFFSET = iStack_c;
    return;
  }
  iVar9 = *(int *)param_1->_padding_;
  pRVar6 = RGE_Action_Gather::get_wait_sprite(param_1);
LAB_00403535:
  (**(code **)(iVar9 + 0x38))(pRVar6);
switchD_00403147_caseD_4:
  *unaff_FS_OFFSET = iStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0040354f
// Address: 0040354f
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

// Function: FUN_00403c8f
// Address: 00403c8f
int __fastcall FUN_00403c8f(int param_1)
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

// Function: FUN_00403cc9
// Address: 00403cc9
undefined4 __fastcall FUN_00403cc9(int *param_1)
{
  (**(code **)(*param_1 + 0x5c))(2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00403cdd
// Address: 00403cdd
undefined4 __thiscall FUN_00403cdd(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  short sVar1;
  int iVar2;
  
  if ((param_2 != 0) && (iVar2 = param_1[2], *(int *)(param_2 + 0xc) == *(int *)(iVar2 + 0xc))) {
    sVar1 = *(short *)(*(int *)(param_2 + 8) + 0x10);
    if (((sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xe8)) ||
        (sVar1 == *(short *)(*(int *)(iVar2 + 8) + 0xea))) &&
       ((float)DAT_0056e278._0_4_ < *(float *)(iVar2 + 0x44))) {
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

// Function: FUN_00403d8e
// Address: 00403d8e
undefined4 __thiscall FUN_00403d8e(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  char cVar1;
  short sVar2;
  int iVar3;
  
  if (param_2 == 0) {
    iVar3 = *param_1;
    param_1[10] = param_5;
    param_1[8] = param_3;
    param_1[9] = param_4;
    (**(code **)(iVar3 + 0x54))(0);
    (**(code **)(iVar3 + 0x5c))(0xf);
  }
  else if ((param_2 != param_1[4]) ||
          (((cVar1 = (char)param_1[3], cVar1 != '\x04' && (cVar1 != '\x06')) && (cVar1 != '\a')))) {
    iVar3 = param_1[2];
    if (*(int *)(param_2 + 0xc) == *(int *)(iVar3 + 0xc)) {
      sVar2 = *(short *)(*(int *)(param_2 + 8) + 0x10);
      if (((sVar2 == *(short *)(*(int *)(iVar3 + 8) + 0xe8)) ||
          (sVar2 == *(short *)(*(int *)(iVar3 + 8) + 0xea))) &&
         ((float)DAT_0056e278._0_4_ < *(float *)(iVar3 + 0x44))) {
        iVar3 = *param_1;
        param_1[0xb] = 0;
        (**(code **)(iVar3 + 0x54))(0);
        param_1[8] = -0x40800000;
        param_1[9] = -0x40800000;
        param_1[10] = -0x40800000;
        (**(code **)(iVar3 + 0x58))(param_2);
        (**(code **)(iVar3 + 0x5c))(8);
        return 1;
      }
    }
    iVar3 = *param_1;
    (**(code **)(iVar3 + 0x54))(param_2);
    param_1[8] = *(int *)(param_2 + 0x38);
    param_1[9] = *(int *)(param_2 + 0x3c);
    param_1[10] = *(int *)(param_2 + 0x40);
    (**(code **)(iVar3 + 0x58))(0);
    (**(code **)(iVar3 + 0x5c))(4);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00403e91
// Address: 00403e91
void __thiscall FUN_00403e91(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = &RGE_Action_List::_vftable_;
  param_1[1] = param_2;
  param_1[2] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00403eb9
// Address: 00403eb9
void __fastcall FUN_00403eb9(RGE_Action_List *param_1)
{
  param_1->_padding_ = (int)&RGE_Action_List::_vftable_;
  RGE_Action_List::delete_list(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00403ecb
// Address: 00403ecb
void __thiscall FUN_00403ecb(RGE_Action_List *param_1,int param_2)
{
  RGE_Action *pRVar1;
  RGE_Action_Node *pRVar2;
  RGE_Action_Node *pRVar3;
  RGE_Action_List *pRStack_4;
  
  pRStack_4 = param_1;
  if (param_1->list != (RGE_Action_Node *)0x0) {
    RGE_Action_List::delete_list(param_1);
  }
  pRVar3 = (RGE_Action_Node *)0x0;
  while( true ) {
    rge_read(param_2,&pRStack_4,2);
    if ((short)pRStack_4 == 0) break;
    pRVar1 = (RGE_Action *)(**(code **)param_1->_padding_)(param_2,pRStack_4);
    pRVar2 = (RGE_Action_Node *)calloc(1,8);
    pRVar2->action = pRVar1;
    pRVar2->next = (RGE_Action_Node *)0x0;
    if (pRVar3 == (RGE_Action_Node *)0x0) {
      param_1->list = pRVar2;
      pRVar3 = pRVar2;
    }
    else {
      pRVar3->next = pRVar2;
      pRVar3 = pRVar2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00403f3b
// Address: 00403f3b
void __fastcall FUN_00403f3b(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    (**(code **)(*(int *)*puVar1 + 0x10))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00403f58
// Address: 00403f58
void __thiscall FUN_00403f58(int param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_2;
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    (**(code **)(*(int *)*puVar1 + 0x14))(iVar2);
  }
  param_2 = 0;
  rge_write(iVar2,&param_2,2);
  return;
}

// --------------------------------------------------

// Function: FUN_00403f99
// Address: 00403f99
void __fastcall FUN_00403f99(RGE_Action_List *param_1)
{
  RGE_Action_Node *pRVar1;
  
  pRVar1 = param_1->list;
  while (pRVar1 != (RGE_Action_Node *)0x0) {
    RGE_Action_List::remove_action(param_1);
    pRVar1 = param_1->list;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00403fba
// Address: 00403fba
undefined4 __thiscall FUN_00403fba(int param_1,int param_2,undefined2 param_3)
{
  RGE_Action_Attack *this;
  RGE_Action_Bird *this_00;
  RGE_Action_Explore *this_01;
  RGE_Action_Gather *this_02;
  RGE_Action_Missile *this_03;
  RGE_Action_Move_To *this_04;
  RGE_Action_Make *this_05;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c24d;
  *unaff_FS_OFFSET = &uStack_c;
  switch(param_3) {
  case 1:
    this_04 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 5;
    if (this_04 != (RGE_Action_Move_To *)0x0) {
      uVar1 = RGE_Action_Move_To::RGE_Action_Move_To
                        (this_04,param_2,*(RGE_Action_Object **)(param_1 + 4));
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
    break;
  case 4:
    this_01 = (RGE_Action_Explore *)operator_new(0x40);
    uStack_4 = 2;
    if (this_01 != (RGE_Action_Explore *)0x0) {
      uVar1 = RGE_Action_Explore::RGE_Action_Explore
                        (this_01,param_2,*(RGE_Action_Object **)(param_1 + 4));
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
    break;
  case 5:
    this_02 = (RGE_Action_Gather *)operator_new(0x44);
    uStack_4 = 3;
    if (this_02 != (RGE_Action_Gather *)0x0) {
      uVar1 = RGE_Action_Gather::RGE_Action_Gather
                        (this_02,param_2,*(RGE_Action_Object **)(param_1 + 4));
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
    break;
  case 8:
    this_03 = (RGE_Action_Missile *)operator_new(0x54);
    uStack_4 = 4;
    if (this_03 != (RGE_Action_Missile *)0x0) {
      uVar1 = RGE_Action_Missile::RGE_Action_Missile
                        (this_03,param_2,*(RGE_Action_Object **)(param_1 + 4));
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
    break;
  case 9:
    this = (RGE_Action_Attack *)operator_new(0x5c);
    uStack_4 = 0;
    if (this != (RGE_Action_Attack *)0x0) {
      uVar1 = RGE_Action_Attack::RGE_Action_Attack
                        (this,param_2,*(RGE_Action_Object **)(param_1 + 4));
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
    break;
  case 10:
    this_00 = (RGE_Action_Bird *)operator_new(0x40);
    uStack_4 = 1;
    if (this_00 != (RGE_Action_Bird *)0x0) {
      uVar1 = RGE_Action_Bird::RGE_Action_Bird(this_00,param_2,*(RGE_Action_Object **)(param_1 + 4))
      ;
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
    break;
  case 0x15:
    this_05 = (RGE_Action_Make *)operator_new(0x40);
    uStack_4 = 6;
    if (this_05 != (RGE_Action_Make *)0x0) {
      uVar1 = RGE_Action_Make::RGE_Action_Make(this_05,param_2,*(RGE_Action_Object **)(param_1 + 4))
      ;
      *unaff_FS_OFFSET = uStack_c;
      return uVar1;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004041c2
// Address: 004041c2
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

// Function: FUN_004044e3
// Address: 004044e3
char __fastcall FUN_004044e3(RGE_Action_List *param_1)
{
  RGE_Action_Node *pRVar1;
  char cVar2;
  
  if (param_1->list != (RGE_Action_Node *)0x0) {
    cVar2 = (**(code **)(param_1->list->action->_padding_ + 0x28))();
    if (param_1->list != (RGE_Action_Node *)0x0) {
      for (pRVar1 = param_1->list->next; pRVar1 != (RGE_Action_Node *)0x0; pRVar1 = pRVar1->next) {
        (**(code **)(pRVar1->action->_padding_ + 0x24))();
      }
      if (cVar2 == '\x01') {
        RGE_Action_List::remove_action(param_1);
      }
    }
    return cVar2;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: FUN_00404539
// Address: 00404539
void __thiscall FUN_00404539(int param_1,int *param_2)
{
  undefined4 *puVar1;
  
  if (*(byte *)(*(int *)(param_1 + 4) + 0x48) < 3) {
    puVar1 = (undefined4 *)calloc(1,8);
    *puVar1 = param_2;
    puVar1[1] = *(undefined4 *)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = puVar1;
    (**(code **)(*param_2 + 0x1c))(1);
  }
  else if (param_2 != (int *)0x0) {
    (**(code **)*param_2)(1);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00404584
// Address: 00404584
void __thiscall FUN_00404584(int param_1,int *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(byte *)(*(int *)(param_1 + 4) + 0x48) < 3) {
    puVar2 = (undefined4 *)calloc(1,8);
    puVar2[1] = 0;
    *puVar2 = param_2;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) != 0) {
      do {
        iVar1 = *(int *)(iVar3 + 4);
        if (iVar1 == 0) {
          *(undefined4 **)(iVar3 + 4) = puVar2;
          (**(code **)(*param_2 + 0x1c))(1);
          return;
        }
        iVar3 = iVar1;
      } while (iVar1 != 0);
      (**(code **)(*param_2 + 0x1c))(1);
      return;
    }
    *(undefined4 **)(param_1 + 8) = puVar2;
    (**(code **)(*param_2 + 0x1c))(1);
  }
  else if (param_2 != (int *)0x0) {
    (**(code **)*param_2)(1);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00404602
// Address: 00404602
void __thiscall FUN_00404602(int param_1,int *param_2)
{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if (2 < *(byte *)(*(int *)(param_1 + 4) + 0x48)) {
    if (param_2 == (int *)0x0) {
      return;
    }
    (**(code **)*param_2)(1);
    return;
  }
  puVar6 = (undefined4 *)calloc(1,8);
  *puVar6 = param_2;
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    piVar1 = (int *)**(undefined4 **)(param_1 + 8);
    pcVar2 = *(code **)(*param_2 + 0x18);
    sVar4 = (*pcVar2)();
    sVar5 = (**(code **)(*piVar1 + 0x18))();
    if (sVar5 == sVar4) {
      iVar7 = *(int *)(param_1 + 8);
      if (iVar7 != 0) {
        while (*(undefined4 **)(iVar7 + 4) != (undefined4 *)0x0) {
          piVar1 = (int *)**(undefined4 **)(iVar7 + 4);
          sVar4 = (*pcVar2)();
          sVar5 = (**(code **)(*piVar1 + 0x18))();
          if (sVar5 != sVar4) break;
          iVar7 = *(int *)(iVar7 + 4);
          if (iVar7 == 0) {
            (**(code **)(*param_2 + 0x1c))(1);
            return;
          }
        }
        puVar6[1] = *(undefined4 *)(iVar7 + 4);
        iVar3 = *param_2;
        *(undefined4 **)(iVar7 + 4) = puVar6;
        (**(code **)(iVar3 + 0x1c))(1);
        return;
      }
      goto LAB_004046f1;
    }
  }
  puVar6[1] = *(undefined4 *)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = puVar6;
LAB_004046f1:
  (**(code **)(*param_2 + 0x1c))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00404702
// Address: 00404702
void __fastcall FUN_00404702(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    *(int *)(param_1 + 8) = piVar1[1];
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    free(piVar1);
    if ((*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) &&
       (*(byte *)(*(int *)(param_1 + 4) + 0x48) < 3)) {
      (**(code **)(*(int *)**(undefined4 **)(param_1 + 8) + 0x1c))(0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00404754
// Address: 00404754
undefined4 __fastcall FUN_00404754(int param_1)
{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 8) >> 8),*(int *)(param_1 + 8) != 0);
}

// --------------------------------------------------

// Function: FUN_00404769
// Address: 00404769
undefined4 __fastcall FUN_00404769(int param_1)
{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0040477b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)**(undefined4 **)(param_1 + 8) + 0x2c))();
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00404781
// Address: 00404781
undefined4 __thiscall
FUN_00404781(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    uVar1 = (**(code **)(*(int *)**(undefined4 **)(param_1 + 8) + 0x30))
                      (param_2,param_3,param_4,param_5);
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004047ba
// Address: 004047ba
undefined4 __thiscall
FUN_004047ba(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    uVar1 = (**(code **)(*(int *)**(undefined4 **)(param_1 + 8) + 0x34))
                      (param_2,param_3,param_4,param_5);
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004047ea
// Address: 004047ea
undefined1 __thiscall FUN_004047ea(int param_1,undefined4 param_2)
{
  undefined1 uVar1;
  
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    uVar1 = (**(code **)(*(int *)**(undefined4 **)(param_1 + 8) + 0x38))(param_2);
    return uVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00404835
// Address: 00404835
undefined4 __fastcall FUN_00404835(int param_1)
{
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    return **(undefined4 **)(param_1 + 8);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040484d
// Address: 0040484d
undefined4 __fastcall FUN_0040484d(int param_1)
{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    return *(undefined4 *)(**(int **)(param_1 + 8) + 0x30);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00404881
// Address: 00404881
void __thiscall FUN_00404881(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    (**(code **)(*(int *)*puVar1 + 0x44))(param_2,param_3,param_4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004048bf
// Address: 004048bf
// [HELPER] s_Attack: "Attack"
// [HELPER] s_Bird: "Bird"
// [HELPER] s_Explore: "Explore"
// [HELPER] s_Gather: "Gather"
// [HELPER] s_Make: "Make"
// [HELPER] s_Missile: "Missile"
// [HELPER] s_MoveTo: "MoveTo"
// [HELPER] s_None: "None"
// [HELPER] s_RunAway: "RunAway"
// [HELPER] s_Unknown: "Unknown"
void __thiscall FUN_004048bf(int param_1,char *param_2)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (*(int **)(param_1 + 8) == (int *)0x0) {
    pcVar4 = &s_None;
    goto LAB_0040494a;
  }
  switch(*(undefined2 *)(**(int **)(param_1 + 8) + 4)) {
  case 1:
    pcVar4 = s_MoveTo;
    goto LAB_00404921;
  default:
    pcVar4 = &s_Unknown;
    break;
  case 4:
    pcVar4 = s_Explore;
    break;
  case 5:
    pcVar4 = &s_Gather;
    goto LAB_00404921;
  case 8:
    pcVar4 = s_Missile;
    break;
  case 9:
    pcVar4 = &s_Attack;
    break;
  case 10:
    pcVar4 = s_Bird;
    goto LAB_00404921;
  case 0x14:
    pcVar4 = s_RunAway;
    break;
  case 0x15:
    pcVar4 = &s_Make;
LAB_00404921:
    uVar2 = 0xffffffff;
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
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)param_2 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      param_2 = param_2 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      param_2 = param_2 + 1;
    }
    return;
  }
LAB_0040494a:
  uVar2 = 0xffffffff;
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
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)param_2 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    param_2 = param_2 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040496e
// Address: 0040496e
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

// Function: FUN_004049d8
// Address: 004049d8
RGE_Action_Make * __thiscall FUN_004049d8(RGE_Action_Make *param_1,byte param_2)
{
  RGE_Action_Make::~RGE_Action_Make(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00404a05
// Address: 00404a05
RGE_Action * __thiscall
FUN_00404a05(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->_padding_ = (int)&RGE_Action_Make::_vftable_;
  param_1->action_type = 0x15;
  param_1->task = param_3;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00404a38
// Address: 00404a38
void __fastcall FUN_00404a38(int *param_1)
{
  short sVar1;
  undefined2 extraout_var;
  
  (**(code **)(*param_1 + 0x5c))(6);
  sVar1 = *(short *)(param_1[0xc] + 0x14);
  if ((-1 < sVar1) && ((short)((int *)param_1[2])[0x13] != sVar1)) {
    (**(code **)(*(int *)param_1[2] + 0x80))(CONCAT22(extraout_var,sVar1),0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00404a6e
// Address: 00404a6e
void __thiscall FUN_00404a6e(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x2c) =
       *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x50) + 0x90);
  return;
}

// --------------------------------------------------

// Function: FUN_00404a8c
// Address: 00404a8c
uint __fastcall FUN_00404a8c(int param_1)
{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float fVar6;
  uint uVar7;
  undefined4 uVar8;
  float unaff_EDI;
  
  if (*(byte *)(param_1 + 0xc) == 1) {
    return 1;
  }
  uVar7 = *(byte *)(param_1 + 0xc) - 6;
  if (uVar7 == 0) {
    if (*(float *)(param_1 + 0x2c) <= (float)DAT_0056e318) {
      iVar2 = *(int *)(param_1 + 8);
      iVar3 = *(int *)(iVar2 + 0xc);
      iVar4 = *(int *)(iVar3 + 0x50);
      if ((float)DAT_0056e318 < *(float *)(iVar4 + 0x90)) {
        fVar1 = *(float *)(iVar2 + 0x44);
        fVar6 = (float)DAT_0056e318;
        uVar7 = CONCAT22((short)((uint)iVar4 >> 0x10),
                         (ushort)(fVar1 < fVar6) << 8 | (ushort)(NAN(fVar1) || NAN(fVar6)) << 10 |
                         (ushort)(fVar1 == fVar6) << 0xe);
        if (fVar1 < fVar6 || (fVar1 == fVar6) != 0) {
          iVar4 = rge_base_game->_padding_;
          uVar8 = __ftol();
          uVar8 = __ftol(uVar8);
          (**(code **)(iVar4 + 0x40))
                    (0x7e,(int)*(short *)(iVar3 + 0x4a),*(undefined4 *)(iVar2 + 4),uVar8);
          uVar7 = (**(code **)(**(int **)(param_1 + 8) + 0x6c))();
          return uVar7 & 0xffffff00;
        }
        goto LAB_00404b94;
      }
    }
    piVar5 = *(int **)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0x30);
    fVar1 = *(float *)(piVar5[2] + 0xe4) * *(float *)(((int *)piVar5[3])[0xf] + 0x84) *
            *(float *)(iVar2 + 0x1c);
    if (*(short *)(iVar2 + 0x30) == 0) {
      uVar7 = (**(code **)(*piVar5 + 0x84))(fVar1,1,1);
    }
    else {
      uVar7 = (**(code **)(*(int *)piVar5[3] + 0x78))
                        (CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(iVar2 + 0x14)),fVar1,
                         0);
    }
    *(float *)(param_1 + 0x2c) =
         *(float *)(param_1 + 0x2c) - (*(float *)(*(int *)(param_1 + 8) + 0x44) - unaff_EDI);
  }
LAB_00404b94:
  return uVar7 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_00404ba5
// Address: 00404ba5
RGE_Action * __thiscall FUN_00404ba5(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c2c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Action_Missile::_vftable_;
  param_1->action_type = 8;
  rge_read(param_2,param_1 + 1,4);
  rge_read(param_2,&param_1[1].action_type,4);
  rge_read(param_2,&param_1[1].obj,4);
  rge_read(param_2,&param_1[1].state,4);
  rge_read(param_2,&param_1[1].target_obj,4);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00404c53
// Address: 00404c53
RGE_Action_Missile * __thiscall FUN_00404c53(RGE_Action_Missile *param_1,byte param_2)
{
  RGE_Action_Missile::~RGE_Action_Missile(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00404c85
// Address: 00404c85
RGE_Action * __thiscall
FUN_00404c85(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Static_Object *param_3,
            RGE_Static_Object *param_4,float param_5,float param_6,float param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c2e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->target_x = param_5;
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Action_Missile::_vftable_;
  param_1->action_type = 8;
  param_1->target_y = param_6;
  param_1->target_z = param_7;
  RGE_Action::set_target_obj(param_1,param_4);
  RGE_Action::set_target_obj2(param_1,param_3);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00404d0e
// Address: 00404d0e
void __thiscall FUN_00404d0e(int *param_1,char param_2)
{
  if (param_2 == '\0') {
    (**(code **)(*param_1 + 0x5c))(4);
    return;
  }
  if ((param_1[4] == 0) && ((param_1[8] == -0x40800000 || (param_1[9] == -0x40800000)))) {
    (**(code **)(*param_1 + 0x5c))(1);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: FUN_00404d4e
// Address: 00404d4e
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00404d4e(int param_1,undefined4 *param_2,undefined4 *param_3,float *param_4)
{
  if (*(int *)(param_1 + 0x10) == 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x20);
    *param_3 = *(undefined4 *)(param_1 + 0x24);
    *param_4 = *(float *)(param_1 + 0x28);
    return;
  }
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x38);
  *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x3c);
  *param_4 = *(float *)(*(int *)(*(int *)(param_1 + 0x10) + 8) + 0x38) * _DAT_0056e380 +
             *(float *)(*(int *)(param_1 + 0x10) + 0x40);
  return;
}

// --------------------------------------------------

// Function: FUN_00404da5
// Address: 00404da5
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00404da5(RGE_Action_Missile *param_1,char param_2)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  unkbyte10 Var7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  *(char *)&param_1->_padding_ = param_2;
  if (param_2 == '\x01') {
    (**(code **)(*(int *)param_1->_padding_ + 0x6c))();
  }
  else if (param_2 == '\x03') {
    RGE_Action_Missile::intercept(param_1,&fStack_c,&fStack_8,&fStack_4);
    iVar2 = param_1->_padding_;
    fStack_28 = fStack_c - *(float *)(iVar2 + 0x38);
    _param_2 = fStack_8 - *(float *)(iVar2 + 0x3c);
    fVar4 = fStack_4 - *(float *)(iVar2 + 0x40);
    fVar5 = fVar4 * fVar4;
    fStack_24 = SQRT(_param_2 * _param_2 + fStack_28 * fStack_28 + fVar5);
    if (((*(char *)(*(int *)(iVar2 + 8) + 0x149) == '\x01') &&
        ((int *)param_1->_padding_ != (int *)0x0)) &&
       (fVar6 = (float10)(**(code **)(*(int *)param_1->_padding_ + 0xf4))(),
       (float10)_DAT_0056e388 < fVar6)) {
      fVar6 = (float10)(**(code **)(*(int *)param_1->_padding_ + 0xf4))();
      fStack_20 = (float)fVar6;
      if (((param_1->_padding_ != 0) &&
          (((sVar1 = *(short *)(*(int *)(param_1->_padding_ + 8) + 0x10), sVar1 == 0x23 ||
            (sVar1 == 0x24)) || (sVar1 == 0x118)))) && (_DAT_0056e390 < fStack_20)) {
        fStack_20 = 1.0;
      }
      Var7 = (**(code **)(*(int *)param_1->_padding_ + 0xf8))();
      fVar6 = (float10)fcos(Var7);
      Var7 = (**(code **)(*(int *)param_1->_padding_ + 0xf8))();
      fVar8 = (float10)fsin(Var7);
      iVar2 = *(int *)(param_1->_padding_ + 8);
      fVar9 = (float10)(float)(fVar6 * (float10)fStack_20) + (float10)fStack_28;
      fVar10 = fVar8 * (float10)fStack_20 + (float10)_param_2;
      fVar9 = ((float10)fStack_24 -
              SQRT(fVar10 * (float10)(float)fVar10 + fVar9 * (float10)(float)fVar9 + (float10)fVar5)
              ) + (float10)*(float *)(iVar2 + 0xb8);
      if ((float10)*(float *)(iVar2 + 0xb8) * (float10)_DAT_0056e380 < fVar9) {
        fStack_24 = fStack_24 / (float)fVar9;
        fStack_28 = fStack_24 * (float)(fVar6 * (float10)fStack_20) + fStack_28;
        _param_2 = fStack_24 * (float)(fVar8 * (float10)fStack_20) + _param_2;
        fStack_24 = SQRT(_param_2 * _param_2 + fStack_28 * fStack_28 + fVar5);
      }
    }
    piVar3 = (int *)param_1->_padding_;
    switch(*(undefined1 *)(piVar3[2] + 0x148)) {
    case 0:
      iVar2 = *piVar3;
      param_1->velocity_x = (float)((float10)fStack_28 / (float10)fStack_24);
      param_1->velocity_y = (float)((float10)_param_2 / (float10)fStack_24);
      param_1->velocity_z = fVar4 / fStack_24;
      fVar6 = (float10)fpatan((float10)_param_2 / (float10)fStack_24,
                              (float10)fStack_28 / (float10)fStack_24);
      (**(code **)(iVar2 + 0xb4))((float)fVar6);
      param_1->_padding_ = 0;
      break;
    case 1:
      (**(code **)(param_1->_padding_ + 0x5c))(4);
      break;
    case 2:
      (**(code **)(param_1->_padding_ + 0x5c))(4);
      break;
    case 3:
      fVar6 = (float10)fpatan((float10)_param_2,(float10)fStack_28);
      param_1->velocity_x = fStack_28;
      param_1->velocity_y = _param_2;
      iVar2 = *piVar3;
      param_1->velocity_z = fVar4;
      (**(code **)(iVar2 + 0xb4))((float)fVar6);
    }
    iVar2 = *(int *)(param_1->_padding_ + 8);
    if (*(float *)(iVar2 + 0x150) <= (float)_DAT_0056e388) {
      param_1->ballistic_velocity = 0.0;
      param_1->ballistic_acceleration = 0.0;
      (**(code **)(param_1->_padding_ + 0x5c))(4);
      return;
    }
    fVar4 = _DAT_0056e394;
    if (_DAT_0056e394 < *(float *)(iVar2 + 0xb8)) {
      fVar4 = fStack_24 / *(float *)(iVar2 + 0xb8);
    }
    fVar4 = fVar4 * _DAT_0056e380;
    fVar5 = -(fStack_24 * *(float *)(iVar2 + 0x150));
    fVar5 = (fVar5 + fVar5) / (fVar4 * fVar4);
    param_1->ballistic_acceleration = fVar5;
    param_1->ballistic_velocity = -(fVar4 * fVar5);
    (**(code **)(param_1->_padding_ + 0x5c))(4);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004050d5
// Address: 004050d5
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

// Function: FUN_004054ab
// Address: 004054ab
void __thiscall FUN_004054ab(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  rge_write(param_2,&param_1[1].action_type,4);
  rge_write(param_2,&param_1[1].obj,4);
  rge_write(param_2,&param_1[1].state,4);
  rge_write(param_2,&param_1[1].target_obj,4);
  return;
}

// --------------------------------------------------

// Function: FUN_0040550e
// Address: 0040550e
RGE_Action * __thiscall FUN_0040550e(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c308;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Action_Move_To::_vftable_;
  param_1->action_type = 1;
  rge_read(param_2,param_1 + 1,4);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00405577
// Address: 00405577
RGE_Action_Move_To * __thiscall FUN_00405577(RGE_Action_Move_To *param_1,byte param_2)
{
  RGE_Action_Move_To::~RGE_Action_Move_To(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040559e
// Address: 0040559e
RGE_Action * __thiscall
FUN_0040559e(RGE_Action *param_1,RGE_Action_Object *param_2,float param_3,float param_4,
            float param_5,float param_6,RGE_Sprite *param_7)
{
  int iVar1;
  RGE_Sprite *pRVar2;
  undefined4 uVar3;
  
  RGE_Action::RGE_Action(param_1,param_2,1);
  uVar3 = DAT_0056e400._0_4_;
  param_1->target_x = param_3;
  param_1->target_z = param_5;
  param_1[1]._padding_ = (int)param_6;
  param_1->_padding_ = (int)&RGE_Action_Move_To::_vftable_;
  param_1->action_type = 1;
  param_1->target_y = param_4;
  param_1->sprite = param_7;
  if (param_6 <= (float)uVar3) {
    param_1[1]._padding_ = 0x3ecccccd;
  }
  if (param_7 == (RGE_Sprite *)0x0) {
    iVar1 = param_1->obj->_padding_;
    pRVar2 = *(RGE_Sprite **)(iVar1 + 0xbc);
    if (pRVar2 == (RGE_Sprite *)0x0) {
      param_1->sprite = *(RGE_Sprite **)(iVar1 + 0x18);
      return param_1;
    }
    param_1->sprite = pRVar2;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0040561f
// Address: 0040561f
RGE_Action * __thiscall
FUN_0040561f(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Static_Object *param_3,float param_4
            ,RGE_Sprite *param_5)
{
  int iVar1;
  RGE_Sprite *pRVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c328;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Action_Move_To::_vftable_;
  param_1->action_type = 1;
  RGE_Action::set_target_obj(param_1,param_3);
  if (param_3 != (RGE_Static_Object *)0x0) {
    param_1->target_x = param_3->world_x;
    param_1->target_y = param_3->world_y;
    param_1->target_z = param_3->world_z;
  }
  uVar3 = DAT_0056e400._0_4_;
  param_1[1]._padding_ = (int)param_4;
  param_1->sprite = param_5;
  if (param_4 <= (float)uVar3) {
    param_1[1]._padding_ = 0x3ecccccd;
  }
  if (param_5 == (RGE_Sprite *)0x0) {
    iVar1 = param_1->obj->_padding_;
    pRVar2 = *(RGE_Sprite **)(iVar1 + 0xbc);
    if (pRVar2 == (RGE_Sprite *)0x0) {
      param_1->sprite = *(RGE_Sprite **)(iVar1 + 0x18);
    }
    else {
      param_1->sprite = pRVar2;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004056da
// Address: 004056da
void __fastcall FUN_004056da(RGE_Action *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055c348;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Action_Move_To::_vftable_;
  uStack_4 = 0;
  (**(code **)(param_1->obj->_padding_ + 0x1c0))(0);
  (**(code **)(param_1->obj->_padding_ + 0x1ec))();
  pcStack_8 = (code *)0xffffffff;
  RGE_Action::~RGE_Action(param_1);
  *unaff_FS_OFFSET = param_1;
  return;
}

// --------------------------------------------------

// Function: FUN_00405742
// Address: 00405742
void __thiscall FUN_00405742(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  return;
}

// --------------------------------------------------

// Function: FUN_00405772
// Address: 00405772
void __fastcall FUN_00405772(int *param_1)
{
  int iVar1;
  float10 fVar2;
  
  if ((RGE_Static_Object *)param_1[4] != (RGE_Static_Object *)0x0) {
    iVar1 = RGE_Static_Object::inRange
                      ((RGE_Static_Object *)param_1[2],(RGE_Static_Object *)param_1[4],
                       (float)param_1[0x10]);
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0x5c))(1);
      return;
    }
  }
  fVar2 = (float10)(**(code **)(*(int *)param_1[2] + 0xfc))();
  if (fVar2 == (float10)(double)DAT_0056e400._8_8_) {
    (**(code **)(*param_1 + 0x5c))(0xd);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: FUN_004057da
// Address: 004057da
void __thiscall FUN_004057da(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xc) = param_2;
  switch(param_2) {
  case 1:
  case 0xd:
  case 0xe:
    if (*(char *)(param_1 + 0x3c) == '\0') {
      (**(code **)(**(int **)(param_1 + 8) + 0x38))
                (*(undefined4 *)((*(int **)(param_1 + 8))[2] + 0x18));
    }
    break;
  case 4:
    (**(code **)(**(int **)(param_1 + 8) + 0x38))(*(undefined4 *)(param_1 + 0x38));
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040582e
// Address: 0040582e
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
void FUN_00405bca(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00405c55
// Address: 00405c55
RGE_Action_Object * __thiscall
FUN_00405c55(RGE_Action_Object *param_1,RGE_Master_Action_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c368;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Moving_Object::RGE_Moving_Object
            ((RGE_Moving_Object *)param_1,(RGE_Master_Moving_Object *)param_2,param_3,param_4,
             param_5,param_6,0);
  uStack_4 = 0;
  param_1->lastActionValue = -1;
  param_1->lastActionStateValue = -1;
  param_1->_padding_ = (int)&RGE_Action_Object::_vftable_;
  if (param_7 != 0) {
    RGE_Action_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00405cf2
// Address: 00405cf2
undefined1 FUN_00405cf2(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405d03
// Address: 00405d03
undefined4 FUN_00405d03(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405d13
// Address: 00405d13
undefined4 FUN_00405d13(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405d25
// Address: 00405d25
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405d25(void)
{
  return (float10)_DAT_0056e63c;
}

// --------------------------------------------------

// Function: FUN_00405d39
// Address: 00405d39
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405d39(void)
{
  return (float10)_DAT_0056e640;
}

// --------------------------------------------------

// Function: FUN_00405d47
// Address: 00405d47
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405d47(void)
{
  return (float10)_DAT_0056e640;
}

// --------------------------------------------------

// Function: FUN_00405d57
// Address: 00405d57
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405d57(void)
{
  return (float10)_DAT_0056e640;
}

// --------------------------------------------------

// Function: FUN_00405d69
// Address: 00405d69
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405d69(void)
{
  return (float10)_DAT_0056e640;
}

// --------------------------------------------------

// Function: FUN_00405d77
// Address: 00405d77
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405d77(void)
{
  return (float10)_DAT_0056e640;
}

// --------------------------------------------------

// Function: FUN_00405d87
// Address: 00405d87
undefined4 FUN_00405d87(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00405d94
// Address: 00405d94
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405d94(void)
{
  return (float10)_DAT_0056e644;
}

// --------------------------------------------------

// Function: FUN_00405da7
// Address: 00405da7
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405da7(void)
{
  return (float10)_DAT_0056e644;
}

// --------------------------------------------------

// Function: FUN_00405db7
// Address: 00405db7
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00405db7(void)
{
  return (float10)_DAT_0056e644;
}

// --------------------------------------------------

// Function: FUN_00405dc7
// Address: 00405dc7
undefined1 FUN_00405dc7(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405dd5
// Address: 00405dd5
undefined1 FUN_00405dd5(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_00405de5
// Address: 00405de5
undefined1 FUN_00405de5(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_00405df3
// Address: 00405df3
void FUN_00405df3(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00405e03
// Address: 00405e03
undefined4 FUN_00405e03(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e15
// Address: 00405e15
undefined4 FUN_00405e15(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e25
// Address: 00405e25
undefined4 FUN_00405e25(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e35
// Address: 00405e35
undefined4 FUN_00405e35(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e45
// Address: 00405e45
undefined4 FUN_00405e45(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e55
// Address: 00405e55
undefined4 FUN_00405e55(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e65
// Address: 00405e65
undefined4 FUN_00405e65(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e75
// Address: 00405e75
undefined4 FUN_00405e75(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e85
// Address: 00405e85
undefined4 FUN_00405e85(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405e95
// Address: 00405e95
undefined4 FUN_00405e95(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405ea5
// Address: 00405ea5
undefined4 FUN_00405ea5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405eb5
// Address: 00405eb5
undefined4 FUN_00405eb5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405ec5
// Address: 00405ec5
undefined4 FUN_00405ec5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405ed5
// Address: 00405ed5
undefined4 FUN_00405ed5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405ee5
// Address: 00405ee5
undefined4 FUN_00405ee5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405ef5
// Address: 00405ef5
undefined4 FUN_00405ef5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405f05
// Address: 00405f05
undefined4 FUN_00405f05(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405f15
// Address: 00405f15
undefined4 FUN_00405f15(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405f23
// Address: 00405f23
undefined4 FUN_00405f23(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00405f33
// Address: 00405f33
float10 __fastcall FUN_00405f33(int param_1)
{
  return (float10)*(float *)(param_1 + 0x88);
}

// --------------------------------------------------

// Function: FUN_00405f47
// Address: 00405f47
float10 __fastcall FUN_00405f47(int param_1)
{
  return (float10)*(float *)(param_1 + 0x9c);
}

// --------------------------------------------------

// Function: FUN_00405f57
// Address: 00405f57
undefined4 __fastcall FUN_00405f57(int param_1)
{
  return *(undefined4 *)(param_1 + 0x16c);
}

// --------------------------------------------------

// Function: FUN_00405f67
// Address: 00405f67
RGE_Action_Object * __thiscall FUN_00405f67(RGE_Action_Object *param_1,byte param_2)
{
  RGE_Action_Object::~RGE_Action_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00405f8e
// Address: 00405f8e
RGE_Action_Object * __thiscall
FUN_00405f8e(RGE_Action_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c388;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Moving_Object::RGE_Moving_Object((RGE_Moving_Object *)param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->lastActionValue = -1;
  param_1->lastActionStateValue = -1;
  param_1->_padding_ = (int)&RGE_Action_Object::_vftable_;
  if (param_4 != 0) {
    RGE_Action_Object::setup(param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00406004
// Address: 00406004
void __fastcall FUN_00406004(RGE_Moving_Object *param_1)
{
  RGE_Action_List *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055c3a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Action_Object::_vftable_;
  this = (RGE_Action_List *)param_1[1]._padding_;
  uStack_4 = 0;
  if (this != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this);
    operator_delete(this);
    param_1[1]._padding_ = 0;
  }
  uStack_4 = 0xffffffff;
  RGE_Moving_Object::~RGE_Moving_Object(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0040609b
// Address: 0040609b
void __thiscall
FUN_0040609b(RGE_Moving_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  RGE_Moving_Object::recycle_in_to_game(param_1,param_2,param_3,param_4,param_5,param_6);
  *(undefined1 *)&param_1[1]._padding_ = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004060ce
// Address: 004060ce
undefined4 __thiscall
FUN_004060ce(RGE_Moving_Object *param_1,RGE_Master_Moving_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  int iVar1;
  
  RGE_Moving_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  iVar1 = param_1->_padding_;
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x28;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  iVar1 = (**(code **)(iVar1 + 0x218))();
  param_1[1]._padding_ = iVar1;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040611e
// Address: 0040611e
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040611e(RGE_Moving_Object *param_1,int param_2,RGE_Game_World *param_3)
{
  RGE_Action_List *this;
  
  RGE_Moving_Object::setup(param_1,param_2,param_3);
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x28;
  rge_read(param_2,param_1 + 1,1);
  if (save_game_version < _DAT_0056e648) {
    *(undefined1 *)&param_1[1]._padding_ = 0;
  }
  else {
    rge_read(param_2,&param_1[1]._padding_,1);
  }
  this = (RGE_Action_List *)(**(code **)(param_1->_padding_ + 0x218))();
  param_1[1]._padding_ = (int)this;
  RGE_Action_List::load(this,param_2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00406199
// Address: 00406199
undefined4 __fastcall FUN_00406199(RGE_Action_Object *param_1)
{
  RGE_Action_List *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c3cb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Action_List *)operator_new(0xc);
  uStack_4 = 0;
  if (this != (RGE_Action_List *)0x0) {
    uVar1 = RGE_Action_List::RGE_Action_List(this,param_1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004061fd
// Address: 004061fd
void __fastcall FUN_004061fd(RGE_Static_Object *param_1)
{
  RGE_Static_Object::rehook(param_1);
  RGE_Action_List::rehook((RGE_Action_List *)param_1[2].unitAIValue);
  return;
}

// --------------------------------------------------

// Function: FUN_00406215
// Address: 00406215
void __thiscall FUN_00406215(RGE_Moving_Object *param_1,int param_2)
{
  RGE_Moving_Object::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,1);
  rge_write(param_2,&param_1[1]._padding_,1);
  RGE_Action_List::save((RGE_Action_List *)param_1[1]._padding_,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00406263
// Address: 00406263
void __thiscall FUN_00406263(RGE_Moving_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Moving_Object::transform(param_1,param_2);
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[1]._padding_);
  return;
}

// --------------------------------------------------

// Function: FUN_0040628c
// Address: 0040628c
void __fastcall FUN_0040628c(RGE_Static_Object *param_1)
{
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[2].unitAIValue);
  RGE_Static_Object::destroy_obj(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004062a7
// Address: 004062a7
void FUN_004062a7(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004062b3
// Address: 004062b3
void __thiscall
FUN_004062b3(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  if (param_2 != param_1) {
    (**(code **)(*param_1 + 0x1f8))(param_2,param_3,param_4,param_5,0);
    *(char *)(param_1 + 0x62) = (char)param_1[0x62] + '\x01';
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004062f1
// Address: 004062f1
void __thiscall
FUN_004062f1(RGE_Action_Object *param_1,RGE_Action_Object *param_2,float param_3,float param_4,
            float param_5)
{
  int iVar1;
  RGE_Action_Move_To *pRVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c3f6;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == param_1) goto LAB_00406419;
  iVar1 = RGE_Action_List::action_move_to
                    (param_1->actions,(RGE_Static_Object *)param_2,param_3,param_4,param_5);
  if (iVar1 != 0) goto LAB_00406419;
  if (param_2 == (RGE_Action_Object *)0x0) {
    pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 1;
    if (pRVar2 == (RGE_Action_Move_To *)0x0) goto LAB_004063aa;
    iVar1 = RGE_Action_Move_To::RGE_Action_Move_To
                      (pRVar2,param_1,param_3,param_4,param_5,0.4,(RGE_Sprite *)0x0);
  }
  else {
    pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (pRVar2 == (RGE_Action_Move_To *)0x0) {
LAB_004063aa:
      iVar1 = 0;
    }
    else {
      iVar1 = RGE_Action_Move_To::RGE_Action_Move_To
                        (pRVar2,param_1,(RGE_Static_Object *)param_2,0.4,(RGE_Sprite *)0x0);
    }
  }
  uStack_4 = 0xffffffff;
  if ((UnitAIModule *)param_1->_padding_ != (UnitAIModule *)0x0) {
    UnitAIModule::setCurrentOrder((UnitAIModule *)param_1->_padding_,0x2c6);
    UnitAIModule::setCurrentAction((UnitAIModule *)param_1->_padding_,0x262);
    if (param_2 == (RGE_Action_Object *)0x0) {
      iVar3 = -1;
      iVar4 = -1;
    }
    else {
      iVar4 = param_2->_padding_;
      iVar3 = (int)*(short *)(param_2->_padding_ + 0x14);
    }
    UnitAIModule::setCurrentTarget
              ((UnitAIModule *)param_1->_padding_,iVar4,iVar3,param_3,param_4,param_5);
  }
  if (iVar1 != 0) {
    (**(code **)(param_1->_padding_ + 0x208))(iVar1);
  }
  param_1->command_flag = param_1->command_flag + '\x01';
LAB_00406419:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0040642e
// Address: 0040642e
void __thiscall
FUN_0040642e(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  if (param_2 != param_1) {
    (**(code **)(*param_1 + 0x1f8))(param_2,param_3,param_4,param_5,1);
    *(char *)(param_1 + 0x62) = (char)param_1[0x62] + '\x01';
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00406461
// Address: 00406461
void __thiscall
FUN_00406461(RGE_Static_Object *param_1,RGE_Static_Object *param_2,undefined4 param_3,
            undefined4 param_4,RGE_Static_Object *param_5)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Master_Static_Object *pRVar2;
  uchar uVar3;
  undefined2 uVar4;
  short sVar5;
  RGE_Task *pRVar6;
  RGE_Player *pRVar7;
  RGE_Task *pRVar8;
  int iVar9;
  RGE_Action *pRVar10;
  RGE_Static_Object *pRVar11;
  int *piVar12;
  float unaff_EBX;
  float unaff_EBP;
  long lVar13;
  int iVar14;
  
  if (param_2 != param_1) {
    pRVar6 = (RGE_Task *)
             (**(code **)(*(int *)(param_1->master_obj[1].undead_sprite)->pict_name + 4))
                       (param_1,param_2,param_3,param_4,param_5);
    if ((pRVar6 == (RGE_Task *)0x0) && (*(char *)&param_1->master_obj[1].radius_y != '\0')) {
      pRVar7 = param_1->owner;
      iVar14 = 0;
      if (0 < pRVar7->master_object_num) {
        do {
          pRVar1 = pRVar7->master_objects[iVar14];
          param_5 = param_1;
          if ((((pRVar1 != (RGE_Master_Static_Object *)0x0) &&
               (pRVar2 = param_1->master_obj, pRVar1->object_group == pRVar2->object_group)) &&
              (pRVar1->master_type == pRVar2->master_type)) &&
             ((*(char *)&pRVar1[1].radius_y == *(char *)&pRVar2[1].radius_y &&
              (pRVar6 = (RGE_Task *)
                        (**(code **)(*(int *)(pRVar1[1].undead_sprite)->pict_name + 4))
                                  (param_1,param_2,unaff_EBP,unaff_EBX,param_1),
              pRVar6 != (RGE_Task *)0x0)))) {
            (**(code **)(param_1->_padding_ + 0x54))(pRVar1);
            break;
          }
          pRVar7 = param_1->owner;
          iVar14 = iVar14 + 1;
        } while (iVar14 < pRVar7->master_object_num);
      }
    }
    pRVar8 = RGE_Action_List::get_task((RGE_Action_List *)param_1[2].unitAIValue);
    iVar14 = 0;
    uVar4 = 0xffff;
    if (((pRVar8 != (RGE_Task *)0x0) && (pRVar6 == pRVar8)) &&
       (iVar9 = RGE_Action_List::action_work
                          ((RGE_Action_List *)param_1[2].unitAIValue,param_2,unaff_EBP,unaff_EBX,
                           (float)param_5), iVar9 != 0)) {
      pRVar10 = RGE_Action_List::get_action((RGE_Action_List *)param_1[2].unitAIValue);
      uVar4 = (**(code **)(pRVar10->_padding_ + 0x18))();
      iVar14 = 1;
    }
    uVar3 = RGE_Action_List::have_action((RGE_Action_List *)param_1[2].unitAIValue);
    if (uVar3 == '\x01') {
      pRVar10 = RGE_Action_List::get_action((RGE_Action_List *)param_1[2].unitAIValue);
      pRVar11 = (RGE_Static_Object *)(**(code **)(pRVar10->_padding_ + 0x4c))();
      if (pRVar11 == param_2) {
        pRVar10 = RGE_Action_List::get_action((RGE_Action_List *)param_1[2].unitAIValue);
        sVar5 = (**(code **)(pRVar10->_padding_ + 0x18))();
        if (sVar5 == 9) {
          pRVar10 = RGE_Action_List::get_action((RGE_Action_List *)param_1[2].unitAIValue);
          iVar9 = (**(code **)(pRVar10->_padding_ + 0x34))(param_2,unaff_EBP,unaff_EBX,param_5);
          if (iVar9 != 0) {
            pRVar10 = RGE_Action_List::get_action((RGE_Action_List *)param_1[2].unitAIValue);
            uVar4 = (**(code **)(pRVar10->_padding_ + 0x18))();
            iVar14 = 1;
          }
        }
      }
    }
    if (iVar14 == 0) {
      if (pRVar6 == (RGE_Task *)0x0) {
        piVar12 = (int *)0x0;
      }
      else {
        piVar12 = (int *)(**(code **)((param_1[2].unitAIValue)->_padding_ + 4))
                                   (pRVar6,param_2,unaff_EBP,unaff_EBX,param_5);
      }
      if (piVar12 == (int *)0x0) {
        uVar4 = 1;
        (**(code **)(param_1->_padding_ + 0x9c))(param_2,unaff_EBP,unaff_EBX,param_5);
      }
      else {
        uVar4 = (**(code **)(*piVar12 + 0x18))();
        (**(code **)(param_1->_padding_ + 0x208))(piVar12);
      }
    }
    if (param_1->unitAIValue != (UnitAIModule *)0x0) {
      iVar14 = -1;
      iVar9 = -1;
      switch(uVar4) {
      case 1:
        iVar9 = 0x262;
        iVar14 = 0x2c6;
        break;
      case 3:
        iVar9 = 0x269;
        iVar14 = 0x2cd;
        break;
      case 4:
        iVar9 = 0x25d;
        iVar14 = 0x2c1;
        break;
      case 5:
        iVar9 = 0x261;
        iVar14 = 0x2c5;
        break;
      case 9:
        iVar9 = 600;
        iVar14 = 700;
        break;
      case 0xc:
        iVar9 = 0x266;
        iVar14 = 0x2ca;
        break;
      case 0x65:
        iVar9 = 0x25a;
        iVar14 = 0x2be;
        break;
      case 0x68:
        iVar9 = 0x25c;
        iVar14 = 0x2c0;
        break;
      case 0x69:
        iVar9 = 0x25b;
        iVar14 = 0x2bf;
        break;
      case 0x6a:
        iVar9 = 0x26a;
        iVar14 = 0x2ce;
        break;
      case 0x6e:
        iVar9 = 0x265;
        iVar14 = 0x2c9;
        break;
      case 0x6f:
        iVar9 = 0x267;
        iVar14 = 0x2cb;
      }
      UnitAIModule::setCurrentOrder(param_1->unitAIValue,iVar14);
      UnitAIModule::setCurrentAction(param_1->unitAIValue,iVar9);
      if (param_2 == (RGE_Static_Object *)0x0) {
        iVar14 = -1;
        lVar13 = -1;
      }
      else {
        lVar13 = param_2->id;
        iVar14 = (int)param_2->master_obj->object_group;
      }
      UnitAIModule::setCurrentTarget
                (param_1->unitAIValue,lVar13,iVar14,unaff_EBP,unaff_EBX,(float)param_1);
      UnitAIModule::setTaskedByPlayer(param_1->unitAIValue);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00406785
// Address: 00406785
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

// Function: FUN_00406833
// Address: 00406833
void __fastcall FUN_00406833(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x00406845. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_00406848
// Address: 00406848
void __fastcall FUN_00406848(int param_1)
{
                    /* WARNING: Could not recover jumptable at 0x00406855. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 8) + 0x30))();
  return;
}

// --------------------------------------------------

// Function: FUN_00406858
// Address: 00406858
int __thiscall
FUN_00406858(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  int iVar3;
  
  if ((param_2 != param_1) && (*(char *)(*(int *)(param_1 + 8) + 0xec) != '\0')) {
    iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0xd8) + 4))
                      (param_1,param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      return *(int *)(param_1 + 8);
    }
    if (*(char *)(*(int *)(param_1 + 8) + 0xec) != '\0') {
      iVar1 = *(int *)(param_1 + 0xc);
      iVar3 = 0;
      if (0 < *(short *)(iVar1 + 0x22)) {
        while ((((iVar1 = *(int *)(*(int *)(iVar1 + 0x24) + iVar3 * 4), iVar1 == 0 ||
                 (iVar2 = *(int *)(param_1 + 8),
                 *(short *)(iVar1 + 0x14) != *(short *)(iVar2 + 0x14))) ||
                (*(char *)(iVar1 + 4) != *(char *)(iVar2 + 4))) ||
               ((*(char *)(iVar1 + 0xec) != *(char *)(iVar2 + 0xec) ||
                (iVar2 = (**(code **)(**(int **)(iVar1 + 0xd8) + 4))
                                   (param_1,param_2,unaff_ESI,unaff_EBP,param_5), iVar2 == 0))))) {
          iVar1 = *(int *)(param_1 + 0xc);
          iVar3 = iVar3 + 1;
          if (*(short *)(iVar1 + 0x22) <= iVar3) {
            return *(int *)(param_1 + 8);
          }
        }
        return iVar1;
      }
    }
  }
  return *(int *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_0040693d
// Address: 0040693d
void __thiscall FUN_0040693d(int *param_1,short param_2)
{
  RGE_Task *pRVar1;
  int iVar2;
  
  pRVar1 = RGE_Master_Action_Object::get_task((RGE_Master_Action_Object *)param_1[2],param_2);
  if (pRVar1 != (RGE_Task *)0x0) {
    iVar2 = (**(code **)(*(int *)param_1[0x61] + 4))(pRVar1,0,0xbf800000,0xbf800000,0xbf800000);
    if (iVar2 != 0) {
      (**(code **)(*param_1 + 0x208))(iVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00406984
// Address: 00406984
void __thiscall FUN_00406984(int *param_1,int param_2)
{
  RGE_Task *pRVar1;
  int iVar2;
  
  pRVar1 = RGE_Master_Action_Object::getTaskByTaskID((RGE_Master_Action_Object *)param_1[2],param_2)
  ;
  if (pRVar1 != (RGE_Task *)0x0) {
    iVar2 = (**(code **)(*(int *)param_1[0x61] + 4))(pRVar1,0,0xbf800000,0xbf800000,0xbf800000);
    if (iVar2 != 0) {
      (**(code **)(*param_1 + 0x208))(iVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004069d4
// Address: 004069d4
void __thiscall FUN_004069d4(int param_1,RGE_Action *param_2)
{
  if (param_2 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action(*(RGE_Action_List **)(param_1 + 0x184),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004069f7
// Address: 004069f7
void __thiscall FUN_004069f7(int param_1,RGE_Action *param_2)
{
  RGE_Action_List::delete_list(*(RGE_Action_List **)(param_1 + 0x184));
  if (param_2 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action(*(RGE_Action_List **)(param_1 + 0x184),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00406a26
// Address: 00406a26
void __thiscall FUN_00406a26(int param_1,RGE_Action *param_2)
{
  if (param_2 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action_at_end(*(RGE_Action_List **)(param_1 + 0x184),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00406a47
// Address: 00406a47
void __fastcall FUN_00406a47(int param_1)
{
  int iVar1;
  
  iVar1 = RGE_Action_List::action_stop(*(RGE_Action_List **)(param_1 + 0x184));
  if (iVar1 == 0) {
    RGE_Action_List::delete_list(*(RGE_Action_List **)(param_1 + 0x184));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00406a6f
// Address: 00406a6f
// [HELPER] s_t_d___d__d__d__d__d_: "t%d, %d,%d,%d,%d,%d\n"
uchar __fastcall FUN_00406a6f(RGE_Animated_Object *param_1)
{
  byte bVar1;
  RGE_Action_List *this;
  uchar uVar2;
  char cVar3;
  short sVar4;
  RGE_Action *pRVar5;
  undefined2 extraout_var;
  uint uVar6;
  int iVar7;
  
  if (actionFile != (_iobuf *)0x0) {
    uVar2 = RGE_Action_List::have_action((RGE_Action_List *)param_1[2]._padding_);
    if (uVar2 == '\0') {
      iVar7 = -1;
      uVar6 = 0xffffffff;
    }
    else {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_1[2]._padding_);
      sVar4 = (**(code **)(pRVar5->_padding_ + 0x18))();
      iVar7 = (int)sVar4;
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_1[2]._padding_);
      uVar6 = (uint)pRVar5->state;
    }
    if ((param_1[2]._padding_ != iVar7) || (param_1[2]._padding_ != uVar6)) {
      fprintf(actionFile,s_t_d___d__d__d__d__d_,
              *(undefined4 *)(*(int *)(param_1->_padding_ + 0x3c) + 4),param_1->_padding_,
              param_1[2]._padding_,param_1[2]._padding_,iVar7,uVar6);
      param_1[2]._padding_ = iVar7;
      param_1[2]._padding_ = uVar6;
    }
  }
  uVar2 = RGE_Animated_Object::update(param_1);
  this = (RGE_Action_List *)param_1[2]._padding_;
  bVar1 = (byte)param_1->_padding_;
  if (bVar1 < 3) {
    if (this->list == (RGE_Action_Node *)0x0) {
      if ((bVar1 == 2) && (sVar4 = *(short *)(param_1->_padding_ + 0xdc), sVar4 != -1)) {
        (**(code **)(param_1->_padding_ + 0x1fc))(CONCAT22(extraout_var,sVar4));
        return uVar2;
      }
    }
    else {
      if (param_1->_padding_ != 0) {
        (**(code **)(this->_padding_ + 8))();
        return uVar2;
      }
      cVar3 = (**(code **)(this->_padding_ + 0xc))();
      if ((cVar3 == '\x03') || (cVar3 == '\x01')) {
        RGE_Action_List::remove_action((RGE_Action_List *)param_1[2]._padding_);
      }
    }
  }
  else if (this->list != (RGE_Action_Node *)0x0) {
    RGE_Action_List::delete_list(this);
    return uVar2;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00406b8b
// Address: 00406b8b
void __thiscall FUN_00406b8b(RGE_Static_Object *param_1,RGE_Player *param_2)
{
  int iVar1;
  
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0xa4))();
  RGE_Static_Object::change_ownership(param_1,param_2);
  (**(code **)(iVar1 + 0x208))(0);
  return;
}

// --------------------------------------------------

// Function: FUN_00406bb7
// Address: 00406bb7
void __thiscall FUN_00406bb7(RGE_Moving_Object *param_1,RGE_Master_Static_Object *param_2)
{
  (**(code **)(*(int *)param_1[1]._padding_ + 0x14))(param_2);
  RGE_Moving_Object::copy_obj(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00406be1
// Address: 00406be1
bool __fastcall FUN_00406be1(int param_1)
{
  uchar uVar1;
  
  uVar1 = RGE_Action_List::have_action(*(RGE_Action_List **)(param_1 + 0x184));
  return uVar1 != '\0';
}

// --------------------------------------------------

// Function: FUN_00406c01
// Address: 00406c01
undefined4 __fastcall FUN_00406c01(int param_1)
{
  RGE_Action *pRVar1;
  undefined4 uVar2;
  
  pRVar1 = RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x184));
  if (pRVar1 != (RGE_Action *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00406c23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(pRVar1->_padding_ + 0x4c))();
    return uVar2;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00406c29
// Address: 00406c29
int __thiscall
FUN_00406c29(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  int iVar1;
  int iVar2;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iVar3;
  
  iVar1 = (**(code **)(**(int **)(param_1[2] + 0xd8) + 4))(param_1,param_2,param_3,param_4,param_5);
  if ((iVar1 == 0) && (*(char *)(param_1[2] + 0xec) != '\0')) {
    iVar2 = param_1[3];
    iVar3 = 0;
    if (0 < *(short *)(iVar2 + 0x22)) {
      while ((((iVar2 = *(int *)(*(int *)(iVar2 + 0x24) + iVar3 * 4), iVar2 == 0 ||
               (iVar1 = param_1[2], *(short *)(iVar2 + 0x14) != *(short *)(iVar1 + 0x14))) ||
              (*(char *)(iVar2 + 4) != *(char *)(iVar1 + 4))) ||
             ((*(char *)(iVar2 + 0xec) != *(char *)(iVar1 + 0xec) ||
              (iVar1 = (**(code **)(**(int **)(iVar2 + 0xd8) + 4))
                                 (param_1,unaff_EDI,unaff_ESI,unaff_EBP,param_5), iVar1 == 0))))) {
        iVar2 = param_1[3];
        iVar3 = iVar3 + 1;
        if (*(short *)(iVar2 + 0x22) <= iVar3) {
          return 0;
        }
      }
      (**(code **)(*param_1 + 0x54))(iVar2);
    }
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00406d26
// Address: 00406d26
int __fastcall FUN_00406d26(int param_1)
{
  RGE_Action *pRVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(RGE_Action_List **)(param_1 + 0x184) != (RGE_Action_List *)0x0) {
    pRVar1 = RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x184));
    if (pRVar1 != (RGE_Action *)0x0) {
      iVar2 = (int)pRVar1->action_type + (uint)pRVar1->state;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00406d55
// Address: 00406d55
RGE_Action * __thiscall FUN_00406d55(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  param_1->_padding_ = (int)&RGE_Action_Transport::_vftable_;
  param_1->action_type = 0xc;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00406d88
// Address: 00406d88
RGE_Action_Transport * __thiscall FUN_00406d88(RGE_Action_Transport *param_1,byte param_2)
{
  RGE_Action_Transport::~RGE_Action_Transport(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00406db5
// Address: 00406db5
RGE_Action * __thiscall
FUN_00406db5(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&RGE_Action_Transport::_vftable_;
  param_1->action_type = 0xc;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00406dfd
// Address: 00406dfd
void __thiscall FUN_00406dfd(int *param_1,char param_2)
{
  if (param_2 == '\0') {
    (**(code **)(*param_1 + 0x5c))(2);
    return;
  }
  if ((UNK_0056e6b4._4_4_ <= (float)param_1[8]) && (UNK_0056e6b4._4_4_ <= (float)param_1[9])) {
    (**(code **)(*param_1 + 0x5c))(0xb);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(2);
  return;
}

// --------------------------------------------------

// Function: FUN_00406e46
// Address: 00406e46
void __thiscall FUN_00406e46(int *param_1,char param_2)
{
  RGE_Action_Move_To *pRVar1;
  RGE_Action *this;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c416;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
  *(char *)(param_1 + 3) = param_2;
  if (param_2 == '\x02') {
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
LAB_00406f77:
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  if ((param_2 != '\x04') && (param_2 != '\v')) goto LAB_00406f77;
  if (param_1[0xc] == 0) {
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 1;
    if (pRVar1 != (RGE_Action_Move_To *)0x0) {
      this = (RGE_Action *)
             RGE_Action_Move_To::RGE_Action_Move_To
                       (pRVar1,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9],
                        (float)param_1[10],0.3,
                        *(RGE_Sprite **)(((RGE_Action_Object *)param_1[2])->_padding_ + 0x18));
      goto LAB_00406f19;
    }
  }
  else {
    pRVar1 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (pRVar1 != (RGE_Action_Move_To *)0x0) {
      this = (RGE_Action *)
             RGE_Action_Move_To::RGE_Action_Move_To
                       (pRVar1,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9],
                        (float)param_1[10],0.3,*(RGE_Sprite **)(param_1[0xc] + 0x34));
      goto LAB_00406f19;
    }
  }
  this = (RGE_Action *)0x0;
LAB_00406f19:
  uStack_4 = 0xffffffff;
  if (this == (RGE_Action *)0x0) {
    (**(code **)(*param_1 + 0x5c))(2);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],this);
  RGE_Action::setSubAction(this,'\x01');
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00406f8a
// Address: 00406f8a
undefined4 __fastcall FUN_00406f8a(RGE_Action_Transport *param_1)
{
  RGE_Map *this;
  byte bVar1;
  uchar uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  switch(param_1->field_0xc) {
  case 1:
    return 1;
  case 4:
    bVar1 = (**(code **)(**(int **)&param_1->field_0x34 + 0xc))();
    if ((bVar1 != 0) && (bVar1 < 6)) {
      (**(code **)(*(int *)param_1 + 0x5c))(6);
      return 0;
    }
    break;
  case 6:
    iVar5 = RGE_Action_Transport::targetZone(param_1);
    if ((iVar5 == -1) ||
       (iVar5 = RGE_Static_Object::withinRangeOfZone
                          (*(RGE_Static_Object **)&param_1->field_0x8,(uchar)iVar5,2.0), iVar5 != 0)
       ) {
      if (*(short *)(*(int *)(*(int *)&param_1->field_0x8 + 0x24) + 8) < 1) goto LAB_004070ea;
      iVar5 = (**(code **)(*(int *)param_1 + 0x60))();
      if (iVar5 == 0) {
        this = *(RGE_Map **)(*(int *)(*(int *)(*(int *)&param_1->field_0x8 + 0xc) + 0x3c) + 0x28);
        if (*(int *)&param_1->field_0x20 != -0x40800000) {
          sVar3 = __ftol();
          sVar4 = __ftol();
          uVar2 = RGE_Map::get_terrain(this,sVar4,sVar3);
          if (uVar2 == '\x01') goto LAB_004070ea;
          sVar3 = __ftol();
          sVar4 = __ftol();
          uVar2 = RGE_Map::get_terrain(this,sVar4,sVar3);
          if (uVar2 == '\x16') goto LAB_004070ea;
        }
        goto LAB_004070c9;
      }
      iVar5 = RGE_Action_Transport::targetZone(param_1);
      uVar2 = RGE_Static_Object::drop_held_objects(*(RGE_Static_Object **)&param_1->field_0x8,iVar5)
      ;
      iVar5 = *(int *)&param_1->field_0x8;
      if (uVar2 == '\0') goto LAB_004070cc;
      if (*(short *)(*(int *)(iVar5 + 0x24) + 8) < 1) goto LAB_004070ea;
      uVar6 = *(undefined4 *)(iVar5 + 4);
      iVar5 = **(int **)(iVar5 + 0xc);
      uVar7 = 0x206;
    }
    else {
LAB_004070c9:
      iVar5 = *(int *)&param_1->field_0x8;
LAB_004070cc:
      uVar6 = *(undefined4 *)(iVar5 + 4);
      iVar5 = **(int **)(iVar5 + 0xc);
      uVar7 = 0x207;
    }
    (**(code **)(iVar5 + 0xe8))(uVar6,uVar6,uVar7,0x266,0,0);
LAB_004070ea:
    (**(code **)(*(int *)param_1 + 0x5c))(2);
    return 0;
  case 0xb:
    bVar1 = (**(code **)(**(int **)&param_1->field_0x34 + 0xc))();
    if ((bVar1 != 0) && (bVar1 < 6)) {
      (**(code **)(*(int *)param_1 + 0x5c))(2);
      return 0;
    }
    break;
  case 0xd:
    iVar5 = (*(int **)&param_1->field_0x8)[1];
    (**(code **)(**(int **)&param_1->field_0x8 + 0x148))(iVar5,iVar5,0x1f9,0x266,0,0);
    (**(code **)(*(int *)param_1 + 0x5c))(2);
    return 3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0040712e
// Address: 0040712e
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

// Function: FUN_0040716d
// Address: 0040716d
undefined4 __thiscall
FUN_0040716d(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)
{
  param_1[8] = param_3;
  param_1[9] = param_4;
  param_1[7] = 0;
  param_1[10] = param_5;
  (**(code **)(*param_1 + 0x5c))(0xb);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0040719b
// Address: 0040719b
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040719b(int *param_1,int param_2,float param_3,float param_4,int param_5)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  param_1[7] = 1;
  iVar2 = __ftol();
  iVar3 = __ftol();
  bVar1 = RGE_Static_Object::lookupZone((RGE_Static_Object *)param_1[2],iVar3,iVar2);
  fVar4 = RGE_Static_Object::distance_to_position
                    ((RGE_Static_Object *)param_1[2],param_3,param_4,
                     ((RGE_Static_Object *)param_1[2])->world_z);
  if (bVar1 != 0xffffffff) {
    iVar2 = RGE_Static_Object::withinRangeOfZone((RGE_Static_Object *)param_1[2],bVar1,2.0);
    if ((iVar2 == 1) && (fVar4 <= ram0x0056e6bc)) {
      param_1[9] = (int)param_4;
      param_1[8] = (int)param_3;
      param_1[10] = param_5;
      (**(code **)(*param_1 + 0x5c))(6);
      return 1;
    }
  }
  if (((float)_DAT_0056e6c0 <= param_3) && ((float)_DAT_0056e6c0 <= param_4)) {
    param_1[8] = (int)param_3;
    param_1[9] = (int)param_4;
    param_1[10] = param_5;
    if (param_2 != param_1[2]) {
      (**(code **)(*param_1 + 0x5c))(0xb);
      return 1;
    }
    (**(code **)(*param_1 + 0x5c))(4);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004072a5
// Address: 004072a5
undefined4 __fastcall FUN_004072a5(RGE_Action_Transport *param_1)
{
  RGE_Map *this;
  byte bVar1;
  uchar uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iStack_10;
  int iStack_8;
  int iStack_4;
  
  if ((*(int *)&param_1->field_0x30 != 0) && (*(short *)(*(int *)&param_1->field_0x30 + 0xe) == -1))
{
    return 1;
  }
  iVar5 = *(int *)&param_1->field_0x8;
  iStack_4 = __ftol();
  iVar3 = __ftol();
  iStack_10 = __ftol();
  iStack_8 = __ftol();
  this = *(RGE_Map **)(*(int *)(*(int *)(iVar5 + 0xc) + 0x3c) + 0x28);
  if (iStack_4 < 0) {
    iStack_4 = 0;
  }
  if (this->map_width <= iStack_10) {
    iStack_10 = this->map_width + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (this->map_height <= iStack_8) {
    iStack_8 = this->map_height + -1;
  }
  uVar4 = RGE_Action_Transport::targetZone(param_1);
  if (*(int *)&param_1->field_0x20 != -0x40800000) {
    iVar5 = __ftol();
    iVar6 = __ftol();
    bVar1 = RGE_Static_Object::lookupZone(*(RGE_Static_Object **)&param_1->field_0x8,iVar6,iVar5);
    uVar4 = (uint)bVar1;
  }
  iVar5 = iStack_4;
  if (iStack_8 < iVar3) {
    return 0;
  }
  do {
    while (iStack_10 < iVar5) {
      iVar3 = iVar3 + 1;
      iVar5 = iStack_4;
      if (iStack_8 < iVar3) {
        return 0;
      }
    }
    if ((uVar4 == 0xffffffff) ||
       (bVar1 = RGE_Static_Object::lookupZone
                          (*(RGE_Static_Object **)&param_1->field_0x8,iVar5,iVar3), bVar1 == uVar4))
{
      uVar2 = RGE_Map::get_terrain(this,(short)iVar5,(short)iVar3);
      if ((uVar2 == '\x02') ||
         (uVar2 = RGE_Map::get_terrain(this,(short)iVar5,(short)iVar3), uVar2 == '\x04')) {
        return 1;
      }
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0040741b
// Address: 0040741b
uint __fastcall FUN_0040741b(int param_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x20) != -0x40800000) {
    iVar2 = __ftol();
    iVar3 = __ftol();
    bVar1 = RGE_Static_Object::lookupZone(*(RGE_Static_Object **)(param_1 + 8),iVar3,iVar2);
    return (uint)bVar1;
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00407452
// Address: 00407452
RGE_Action * __thiscall
FUN_00407452(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3,int param_4)
{
  param_1->targetID = -1;
  param_1->target2ID = -1;
  param_1->_padding_ = (int)&RGE_Action::_vftable_;
  if (param_4 != 0) {
    RGE_Action::setup(param_1,param_2,param_3);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00407491
// Address: 00407491
RGE_Action * __thiscall FUN_00407491(RGE_Action *param_1,byte param_2)
{
  RGE_Action::~RGE_Action(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004074be
// Address: 004074be
RGE_Action * __thiscall FUN_004074be(RGE_Action *param_1,RGE_Action_Object *param_2,int param_3)
{
  param_1->targetID = -1;
  param_1->target2ID = -1;
  param_1->_padding_ = (int)&RGE_Action::_vftable_;
  if (param_3 != 0) {
    RGE_Action::setup(param_1,param_2);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004074ea
// Address: 004074ea
void __fastcall FUN_004074ea(RGE_Action *param_1)
{
  RGE_Action_List *this;
  
  param_1->_padding_ = (int)&RGE_Action::_vftable_;
  RGE_Action::set_target_obj(param_1,(RGE_Static_Object *)0x0);
  RGE_Action::set_target_obj2(param_1,(RGE_Static_Object *)0x0);
  this = param_1->sub_actions;
  if (this != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this);
    operator_delete(this);
    param_1->sub_actions = (RGE_Action_List *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040752b
// Address: 0040752b
undefined4 __thiscall FUN_0040752b(int *param_1,int param_2,int param_3)
{
  int iVar1;
  RGE_Sprite *pRVar2;
  short unaff_BX;
  int unaff_retaddr;
  
  *(undefined2 *)(param_1 + 1) = 0;
  param_1[2] = param_3;
  iVar1 = (**(code **)(*param_1 + 0xc))(param_3);
  param_1[0xd] = iVar1;
  rge_read(unaff_retaddr,param_1 + 3,1);
  rge_read(unaff_retaddr,&param_2,4);
  if (param_2 == -1) {
    param_1[4] = 0;
  }
  else {
    param_1[4] = param_2;
  }
  rge_read(unaff_retaddr,&param_2,4);
  if (param_2 == -1) {
    param_1[5] = 0;
  }
  else {
    param_1[5] = param_2;
  }
  rge_read(unaff_retaddr,param_1 + 6,4);
  rge_read(unaff_retaddr,param_1 + 7,4);
  rge_read(unaff_retaddr,param_1 + 8,4);
  rge_read(unaff_retaddr,param_1 + 9,4);
  rge_read(unaff_retaddr,param_1 + 10,4);
  rge_read(unaff_retaddr,param_1 + 0xb,4);
  rge_read(unaff_retaddr,&stack0xfffffff8,2);
  if (unaff_BX == -1) {
    param_1[0xc] = 0;
  }
  else {
    param_1[0xc] = *(int *)(*(int *)(*(int *)(*(int *)(param_1[2] + 8) + 0xd8) + 4) + unaff_BX * 4);
  }
  rge_read(unaff_retaddr,param_1 + 0xf,1);
  RGE_Action_List::load((RGE_Action_List *)param_1[0xd],unaff_retaddr);
  rge_read(unaff_retaddr,&stack0xfffffff8,2);
  pRVar2 = RGE_Static_Object::get_sprite_pointer((RGE_Static_Object *)param_1[2],unaff_BX);
  param_1[0xe] = (int)pRVar2;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00407676
// Address: 00407676
undefined4 __thiscall FUN_00407676(int *param_1,int param_2)
{
  int iVar1;
  
  *(undefined2 *)(param_1 + 1) = 0;
  param_1[2] = param_2;
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  iVar1 = (**(code **)(*param_1 + 0xc))(param_2);
  param_1[0xd] = iVar1;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004076c2
// Address: 004076c2
undefined4 __fastcall FUN_004076c2(int param_1)
{
  RGE_Action_List *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c42b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Action_List *)operator_new(0xc);
  uStack_4 = 0;
  if (this != (RGE_Action_List *)0x0) {
    uVar1 = RGE_Action_List::RGE_Action_List(this,*(RGE_Action_Object **)(param_1 + 8));
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00407734
// Address: 00407734
void __fastcall FUN_00407734(int param_1)
{
  RGE_Static_Object *pRVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    pRVar1 = RGE_Static_Object::get_object_pointer
                       (*(RGE_Static_Object **)(param_1 + 8),*(int *)(param_1 + 0x10));
    *(RGE_Static_Object **)(param_1 + 0x10) = pRVar1;
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      *(long *)(param_1 + 0x18) = pRVar1->id;
    }
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    pRVar1 = RGE_Static_Object::get_object_pointer
                       (*(RGE_Static_Object **)(param_1 + 8),*(int *)(param_1 + 0x14));
    *(RGE_Static_Object **)(param_1 + 0x14) = pRVar1;
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      *(long *)(param_1 + 0x1c) = pRVar1->id;
    }
  }
  if (*(RGE_Action_List **)(param_1 + 0x34) != (RGE_Action_List *)0x0) {
    RGE_Action_List::rehook(*(RGE_Action_List **)(param_1 + 0x34));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0040778b
// Address: 0040778b
void __thiscall FUN_0040778b(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined2 extraout_var;
  int iStack_4;
  
  iVar2 = param_2;
  iStack_4 = param_1;
  rge_write(param_2,(void *)(param_1 + 4),2);
  rge_write(iVar2,(void *)(param_1 + 0xc),1);
  if (*(int *)(param_1 + 0x10) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
  }
  rge_write(iVar2,&param_2,4);
  if (*(int *)(param_1 + 0x14) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    param_2 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
  }
  rge_write(iVar2,&param_2,4);
  rge_write(iVar2,(void *)(param_1 + 0x18),4);
  rge_write(iVar2,(void *)(param_1 + 0x1c),4);
  rge_write(iVar2,(void *)(param_1 + 0x20),4);
  rge_write(iVar2,(void *)(param_1 + 0x24),4);
  rge_write(iVar2,(void *)(param_1 + 0x28),4);
  rge_write(iVar2,(void *)(param_1 + 0x2c),4);
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 == 0) {
    iStack_4 = -1;
  }
  else {
    iStack_4 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 2));
  }
  rge_write(iVar2,&iStack_4,2);
  rge_write(iVar2,(void *)(param_1 + 0x3c),1);
  RGE_Action_List::save(*(RGE_Action_List **)(param_1 + 0x34),iVar2);
  if (*(int *)(param_1 + 0x38) == 0) {
    iStack_4 = -1;
  }
  else {
    iStack_4 = CONCAT22(extraout_var,*(undefined2 *)(*(int *)(param_1 + 0x38) + 0x72));
  }
  rge_write(iVar2,&iStack_4,2);
  return;
}

// --------------------------------------------------

// Function: FUN_004078c6
// Address: 004078c6
undefined2 __fastcall FUN_004078c6(int param_1)
{
  return *(undefined2 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_004078d5
// Address: 004078d5
void FUN_004078d5(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004078e3
// Address: 004078e3
undefined4 FUN_004078e3(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004078f3
// Address: 004078f3
undefined4 FUN_004078f3(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00407905
// Address: 00407905
undefined4 FUN_00407905(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00407915
// Address: 00407915
undefined1 FUN_00407915(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00407925
// Address: 00407925
undefined1 FUN_00407925(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00407935
// Address: 00407935
void __thiscall FUN_00407935(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0xc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0040794a
// Address: 0040794a
undefined4 __fastcall FUN_0040794a(int *param_1)
{
  if ((param_1[4] != 0) && (6 < *(byte *)(param_1[4] + 0x48))) {
    (**(code **)(*param_1 + 0x54))(0);
  }
  if ((param_1[5] != 0) && (6 < *(byte *)(param_1[5] + 0x48))) {
    (**(code **)(*param_1 + 0x58))(0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00407983
// Address: 00407983
undefined4 __fastcall FUN_00407983(int *param_1)
{
  if ((param_1[4] != 0) && (6 < *(byte *)(param_1[4] + 0x48))) {
    (**(code **)(*param_1 + 0x54))(0);
  }
  if ((param_1[5] != 0) && (6 < *(byte *)(param_1[5] + 0x48))) {
    (**(code **)(*param_1 + 0x58))(0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004079c3
// Address: 004079c3
uint __fastcall FUN_004079c3(int *param_1)
{
  uint uVar1;
  
  if ((param_1[4] != 0) && (6 < *(byte *)(param_1[4] + 0x48))) {
    (**(code **)(*param_1 + 0x54))(0);
  }
  if ((param_1[5] != 0) && (6 < *(byte *)(param_1[5] + 0x48))) {
    (**(code **)(*param_1 + 0x58))(0);
  }
  if (((int *)param_1[0xd])[2] != 0) {
    uVar1 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    return uVar1;
  }
  return (uint)((char)param_1[3] == '\x01');
}

// --------------------------------------------------

// Function: FUN_00407a1a
// Address: 00407a1a
void __thiscall FUN_00407a1a(int param_1,int *param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((*(int **)(param_1 + 0x10) != (int *)0x0) && (*(int **)(param_1 + 0x10) != param_2)) {
    pRVar2 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x3c),
                        *(int *)(param_1 + 0x18));
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar2->_padding_ + 0xc4))(*(undefined4 *)(param_1 + 8));
    }
  }
  if (*(int **)(param_1 + 0x10) != param_2) {
    *(int **)(param_1 + 0x10) = param_2;
    if (param_2 != (int *)0x0) {
      iVar1 = *param_2;
      *(int *)(param_1 + 0x18) = param_2[1];
      (**(code **)(iVar1 + 0xc0))(*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_1 + 4),0);
      return;
    }
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00407a8f
// Address: 00407a8f
void __thiscall FUN_00407a8f(int param_1,int *param_2)
{
  int iVar1;
  RGE_Static_Object *pRVar2;
  
  if ((*(int **)(param_1 + 0x14) != (int *)0x0) && (*(int **)(param_1 + 0x14) != param_2)) {
    pRVar2 = RGE_Game_World::object
                       (*(RGE_Game_World **)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x3c),
                        *(int *)(param_1 + 0x1c));
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar2->_padding_ + 0xc4))(*(undefined4 *)(param_1 + 8));
    }
  }
  if (*(int **)(param_1 + 0x14) != param_2) {
    *(int **)(param_1 + 0x14) = param_2;
    if (param_2 != (int *)0x0) {
      iVar1 = *param_2;
      *(int *)(param_1 + 0x1c) = param_2[1];
      (**(code **)(iVar1 + 0xc0))(*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_1 + 4),0);
      return;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00407aff
// Address: 00407aff
void __thiscall FUN_00407aff(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iStack_4;
  
  iStack_4 = 0;
  if ((param_1[0xc] == 0) || (iVar6 = *(int *)(param_2 + 0xd8), iVar6 == 0)) {
    (**(code **)(*param_1 + 0x44))(param_2,0,0);
    (**(code **)(*(int *)param_1[0xd] + 0x18))(param_2,0,0);
  }
  else {
    iVar1 = *(int *)(iVar6 + 4);
    iVar6 = *(short *)(iVar6 + 8) + -1;
    if (-1 < iVar6) {
      piVar5 = (int *)(iVar1 + iVar6 * 4);
      do {
        if (*(short *)(*piVar5 + 6) == *(short *)(param_1[0xc] + 6)) break;
        iVar6 = iVar6 + -1;
        piVar5 = piVar5 + -1;
      } while (-1 < iVar6);
    }
    if (-1 < iVar6) {
      iVar2 = *(int *)(iVar1 + iVar6 * 4);
      iVar3 = ((int *)param_1[2])[4];
      iVar4 = *(int *)(iVar2 + 0x34);
      if ((((iVar3 != *(int *)(iVar2 + 0x34)) &&
           (iVar4 = *(int *)(iVar2 + 0x38), iVar3 != *(int *)(iVar2 + 0x38))) &&
          (iVar4 = *(int *)(iVar2 + 0x3c), iVar3 != *(int *)(iVar2 + 0x3c))) &&
         (iVar4 = iStack_4, iVar3 == *(int *)(iVar2 + 0x40))) {
        iVar4 = *(int *)(iVar2 + 0x40);
      }
      iStack_4 = iVar4;
      if (iStack_4 != 0) {
        (**(code **)(*(int *)param_1[2] + 0x38))(iStack_4);
      }
      (**(code **)(*param_1 + 0x44))(param_2,param_1[0xc],*(undefined4 *)(iVar1 + iVar6 * 4));
      (**(code **)(*(int *)param_1[0xd] + 0x18))
                (param_2,param_1[0xc],*(undefined4 *)(iVar1 + iVar6 * 4));
      param_1[0xc] = *(int *)(iVar1 + iVar6 * 4);
      return;
    }
  }
  return;
}

// --------------------------------------------------


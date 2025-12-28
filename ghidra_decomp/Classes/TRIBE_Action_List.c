// Class: TRIBE_Action_List
// Size:  0xC
//
// VTable Layout:
// [00] create_action
// [01] create_task_action
// [02] inside_obj_update
// [03] update
// [04] get_action_name
// [05] copy_obj
// [06] copy_obj_sprites
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Action_List
// Address: 004d0150
TRIBE_Action_List * __thiscall
TRIBE_Action_List::TRIBE_Action_List(TRIBE_Action_List *this,RGE_Action_Object *param_1)
{
  RGE_Action_List::RGE_Action_List((RGE_Action_List *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: create_action
// Address: 004d0170
RGE_Action * __thiscall
TRIBE_Action_List::create_action(TRIBE_Action_List *this,int param_1,short param_2)
{
  TRIBE_Action_Build *this_00;
  TRIBE_Action_Make_Obj *this_01;
  TRIBE_Action_Make_Tech *this_02;
  TRIBE_Action_Convert *this_03;
  TRIBE_Action_Heal *this_04;
  TRIBE_Action_Artifact *this_05;
  TRIBE_Action_Wonder *this_06;
  TRIBE_Action_Discovery_Artifact *this_07;
  TRIBE_Action_Hunt *this_08;
  TRIBE_Action_Repair *this_09;
  TRIBE_Action_Trade *this_10;
  RGE_Action_Transport *this_11;
  RGE_Action_Enter *this_12;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055ffaf;
  *unaff_FS_OFFSET = &local_c;
  switch(param_2) {
  case 3:
    this_12 = (RGE_Action_Enter *)operator_new(0x40);
    local_4 = 0xc;
    if (this_12 != (RGE_Action_Enter *)0x0) {
      pRVar1 = (RGE_Action *)
               RGE_Action_Enter::RGE_Action_Enter
                         (this_12,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  default:
    pRVar1 = RGE_Action_List::create_action((RGE_Action_List *)this,param_1,param_2);
    *unaff_FS_OFFSET = local_c;
    return pRVar1;
  case 0xc:
    this_11 = (RGE_Action_Transport *)operator_new(0x40);
    local_4 = 0xb;
    if (this_11 != (RGE_Action_Transport *)0x0) {
      pRVar1 = (RGE_Action *)
               RGE_Action_Transport::RGE_Action_Transport
                         (this_11,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x65:
    this_00 = (TRIBE_Action_Build *)operator_new(0x40);
    local_4 = 0;
    if (this_00 != (TRIBE_Action_Build *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Build::TRIBE_Action_Build
                         (this_00,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x66:
    this_01 = (TRIBE_Action_Make_Obj *)operator_new(0x50);
    local_4 = 1;
    if (this_01 != (TRIBE_Action_Make_Obj *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj
                         (this_01,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x67:
    this_02 = (TRIBE_Action_Make_Tech *)operator_new(0x48);
    local_4 = 2;
    if (this_02 != (TRIBE_Action_Make_Tech *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech
                         (this_02,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x68:
    this_03 = (TRIBE_Action_Convert *)operator_new(0x48);
    local_4 = 3;
    if (this_03 != (TRIBE_Action_Convert *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Convert::TRIBE_Action_Convert
                         (this_03,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x69:
    this_04 = (TRIBE_Action_Heal *)operator_new(0x40);
    local_4 = 4;
    if (this_04 != (TRIBE_Action_Heal *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Heal::TRIBE_Action_Heal
                         (this_04,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x6a:
    this_09 = (TRIBE_Action_Repair *)operator_new(0x44);
    local_4 = 9;
    if (this_09 != (TRIBE_Action_Repair *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Repair::TRIBE_Action_Repair
                         (this_09,param_1,*(RGE_Action_Object **)&this->field_0x4,1);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x6b:
    this_05 = (TRIBE_Action_Artifact *)operator_new(0x40);
    local_4 = 5;
    if (this_05 != (TRIBE_Action_Artifact *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Artifact::TRIBE_Action_Artifact
                         (this_05,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x6c:
    this_07 = (TRIBE_Action_Discovery_Artifact *)operator_new(0x44);
    local_4 = 7;
    if (this_07 != (TRIBE_Action_Discovery_Artifact *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact
                         (this_07,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x6e:
    this_08 = (TRIBE_Action_Hunt *)operator_new(0x44);
    local_4 = 8;
    if (this_08 != (TRIBE_Action_Hunt *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Hunt::TRIBE_Action_Hunt
                         (this_08,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x6f:
    this_10 = (TRIBE_Action_Trade *)operator_new(0x48);
    local_4 = 10;
    if (this_10 != (TRIBE_Action_Trade *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Trade::TRIBE_Action_Trade
                         (this_10,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
    break;
  case 0x78:
    this_06 = (TRIBE_Action_Wonder *)operator_new(0x40);
    local_4 = 6;
    if (this_06 != (TRIBE_Action_Wonder *)0x0) {
      pRVar1 = (RGE_Action *)
               TRIBE_Action_Wonder::TRIBE_Action_Wonder
                         (this_06,param_1,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar1;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Action *)0x0;
}

// --------------------------------------------------

// Function: create_task_action
// Address: 004d05d0
RGE_Action * __thiscall
TRIBE_Action_List::create_task_action
          (TRIBE_Action_List *this,RGE_Task *param_1,RGE_Static_Object *param_2,float param_3,
          float param_4,float param_5)
{
  TRIBE_Action_Build *pTVar1;
  TRIBE_Action_Convert *pTVar2;
  TRIBE_Action_Heal *pTVar3;
  TRIBE_Action_Artifact *pTVar4;
  TRIBE_Action_Wonder *this_00;
  TRIBE_Action_Discovery_Artifact *pTVar5;
  TRIBE_Action_Hunt *pTVar6;
  TRIBE_Action_Repair *pTVar7;
  TRIBE_Action_Trade *pTVar8;
  RGE_Action_Enter *this_01;
  RGE_Action_Transport *this_02;
  RGE_Action *pRVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560091;
  *unaff_FS_OFFSET = &local_c;
  switch(param_1->action_type) {
  case 3:
    this_01 = (RGE_Action_Enter *)operator_new(0x40);
    local_4 = 0x11;
    if (this_01 != (RGE_Action_Enter *)0x0) {
      pRVar9 = (RGE_Action *)
               RGE_Action_Enter::RGE_Action_Enter
                         (this_01,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
      *unaff_FS_OFFSET = local_c;
      return pRVar9;
    }
    break;
  default:
    pRVar9 = RGE_Action_List::create_task_action
                       ((RGE_Action_List *)this,param_1,param_2,param_3,param_4,param_5);
    *unaff_FS_OFFSET = local_c;
    return pRVar9;
  case 0xc:
    this_02 = (RGE_Action_Transport *)operator_new(0x40);
    local_4 = 0x12;
    if (this_02 != (RGE_Action_Transport *)0x0) {
      pRVar9 = (RGE_Action *)
               RGE_Action_Transport::RGE_Action_Transport
                         (this_02,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                          param_5);
      *unaff_FS_OFFSET = local_c;
      return pRVar9;
    }
    break;
  case 0x65:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pTVar1 = (TRIBE_Action_Build *)operator_new(0x40);
      local_4 = 1;
      if (pTVar1 != (TRIBE_Action_Build *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Build::TRIBE_Action_Build
                           (pTVar1,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                            param_5);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    else {
      pTVar1 = (TRIBE_Action_Build *)operator_new(0x40);
      local_4 = 0;
      if (pTVar1 != (TRIBE_Action_Build *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Build::TRIBE_Action_Build
                           (pTVar1,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    break;
  case 0x68:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pTVar2 = (TRIBE_Action_Convert *)operator_new(0x48);
      local_4 = 3;
      if (pTVar2 != (TRIBE_Action_Convert *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Convert::TRIBE_Action_Convert
                           (pTVar2,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                            param_5);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    else {
      pTVar2 = (TRIBE_Action_Convert *)operator_new(0x48);
      local_4 = 2;
      if (pTVar2 != (TRIBE_Action_Convert *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Convert::TRIBE_Action_Convert
                           (pTVar2,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    break;
  case 0x69:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pTVar3 = (TRIBE_Action_Heal *)operator_new(0x40);
      local_4 = 5;
      if (pTVar3 != (TRIBE_Action_Heal *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Heal::TRIBE_Action_Heal
                           (pTVar3,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                            param_5);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    else {
      pTVar3 = (TRIBE_Action_Heal *)operator_new(0x40);
      local_4 = 4;
      if (pTVar3 != (TRIBE_Action_Heal *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Heal::TRIBE_Action_Heal
                           (pTVar3,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    break;
  case 0x6a:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pTVar7 = (TRIBE_Action_Repair *)operator_new(0x44);
      local_4 = 0xe;
      if (pTVar7 != (TRIBE_Action_Repair *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Repair::TRIBE_Action_Repair
                           (pTVar7,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                            param_5);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    else {
      pTVar7 = (TRIBE_Action_Repair *)operator_new(0x44);
      local_4 = 0xd;
      if (pTVar7 != (TRIBE_Action_Repair *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Repair::TRIBE_Action_Repair
                           (pTVar7,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    break;
  case 0x6b:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pTVar4 = (TRIBE_Action_Artifact *)operator_new(0x40);
      local_4 = 7;
      if (pTVar4 != (TRIBE_Action_Artifact *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Artifact::TRIBE_Action_Artifact
                           (pTVar4,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                            param_5);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    else {
      pTVar4 = (TRIBE_Action_Artifact *)operator_new(0x40);
      local_4 = 6;
      if (pTVar4 != (TRIBE_Action_Artifact *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Artifact::TRIBE_Action_Artifact
                           (pTVar4,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    break;
  case 0x6c:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pTVar5 = (TRIBE_Action_Discovery_Artifact *)operator_new(0x44);
      local_4 = 10;
      if (pTVar5 != (TRIBE_Action_Discovery_Artifact *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact
                           (pTVar5,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                            param_5);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    else {
      pTVar5 = (TRIBE_Action_Discovery_Artifact *)operator_new(0x44);
      local_4 = 9;
      if (pTVar5 != (TRIBE_Action_Discovery_Artifact *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact
                           (pTVar5,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    break;
  case 0x6e:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pTVar6 = (TRIBE_Action_Hunt *)operator_new(0x44);
      local_4 = 0xc;
      if (pTVar6 != (TRIBE_Action_Hunt *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Hunt::TRIBE_Action_Hunt
                           (pTVar6,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                            param_5);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    else {
      pTVar6 = (TRIBE_Action_Hunt *)operator_new(0x44);
      local_4 = 0xb;
      if (pTVar6 != (TRIBE_Action_Hunt *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Hunt::TRIBE_Action_Hunt
                           (pTVar6,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    break;
  case 0x6f:
    if (param_2 == (RGE_Static_Object *)0x0) {
      pTVar8 = (TRIBE_Action_Trade *)operator_new(0x48);
      local_4 = 0x10;
      if (pTVar8 != (TRIBE_Action_Trade *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Trade::TRIBE_Action_Trade
                           (pTVar8,*(RGE_Action_Object **)&this->field_0x4,param_1,param_3,param_4,
                            param_5);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    else {
      pTVar8 = (TRIBE_Action_Trade *)operator_new(0x48);
      local_4 = 0xf;
      if (pTVar8 != (TRIBE_Action_Trade *)0x0) {
        pRVar9 = (RGE_Action *)
                 TRIBE_Action_Trade::TRIBE_Action_Trade
                           (pTVar8,*(RGE_Action_Object **)&this->field_0x4,param_1,param_2);
        *unaff_FS_OFFSET = local_c;
        return pRVar9;
      }
    }
    break;
  case 0x78:
    this_00 = (TRIBE_Action_Wonder *)operator_new(0x40);
    local_4 = 8;
    if (this_00 != (TRIBE_Action_Wonder *)0x0) {
      pRVar9 = (RGE_Action *)
               TRIBE_Action_Wonder::TRIBE_Action_Wonder
                         (this_00,*(RGE_Action_Object **)&this->field_0x4);
      *unaff_FS_OFFSET = local_c;
      return pRVar9;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return (RGE_Action *)0x0;
}

// --------------------------------------------------

// Function: get_action_name
// Address: 004d0c50
// [HELPER] s_Artifact: "Artifact"
// [HELPER] s_Build: "Build"
// [HELPER] s_Convert: "Convert"
// [HELPER] s_DiscoveryArtifact: "DiscoveryArtifact"
// [HELPER] s_Enter: "Enter"
// [HELPER] s_Heal: "Heal"
// [HELPER] s_Hunt: "Hunt"
// [HELPER] s_MakeObject: "MakeObject"
// [HELPER] s_MakeTech: "MakeTech"
// [HELPER] s_None: "None"
// [HELPER] s_Repair: "Repair"
// [HELPER] s_Transport: "Transport"
void __thiscall TRIBE_Action_List::get_action_name(TRIBE_Action_List *this,char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (*(int **)&this->field_0x8 == (int *)0x0) {
    pcVar4 = &s_None;
    goto LAB_004d0ccc;
  }
  switch(*(undefined2 *)(**(int **)&this->field_0x8 + 4)) {
  case 3:
    pcVar4 = s_Enter;
    break;
  default:
    RGE_Action_List::get_action_name((RGE_Action_List *)this,param_1);
    return;
  case 0xc:
    pcVar4 = s_Transport;
    goto LAB_004d0cf5;
  case 0x65:
    pcVar4 = s_Build;
    break;
  case 0x66:
    pcVar4 = s_MakeObject;
    goto LAB_004d0cf5;
  case 0x67:
    pcVar4 = s_MakeTech;
    break;
  case 0x68:
    pcVar4 = s_Convert;
    goto LAB_004d0cf5;
  case 0x69:
    pcVar4 = &s_Heal;
    break;
  case 0x6a:
    pcVar4 = s_Repair;
    break;
  case 0x6b:
    pcVar4 = s_Artifact;
    goto LAB_004d0cf5;
  case 0x6c:
    pcVar4 = s_DiscoveryArtifact;
    break;
  case 0x6e:
    pcVar4 = s_Hunt;
    goto LAB_004d0cf5;
  case 0x6f:
    pcVar4 = &s_Trade;
LAB_004d0cf5:
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
      *(undefined4 *)param_1 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      param_1 = param_1 + 1;
    }
    return;
  }
LAB_004d0ccc:
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
    *(undefined4 *)param_1 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

// --------------------------------------------------


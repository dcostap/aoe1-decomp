// Class: TRIBE_Command
// Size:  0x18
//
// VTable Layout:
// [00] do_command_give_attribute
// [01] `vector_deleting_destructor'
// [02] do_command
// [03] command_give_attribute
// [04] do_command_give_attribute
// [05] command_give_attribute
//
// Member Layout:
// ----------------------------------------------------------------

// Function: TRIBE_Command
// Address: 00509720
TRIBE_Command * __thiscall
TRIBE_Command::TRIBE_Command
          (TRIBE_Command *this,TRIBE_World *param_1,TCommunications_Handler *param_2)
{
  RGE_Command::RGE_Command((RGE_Command *)this,(RGE_Game_World *)param_1,param_2);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00509740
void * __thiscall TRIBE_Command::_vector_deleting_destructor_(TRIBE_Command *this,uint param_1)
{
  ~TRIBE_Command(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Command
// Address: 00509760
void __thiscall TRIBE_Command::~TRIBE_Command(TRIBE_Command *this)
{
  *(undefined ***)this = &RGE_Command::_vftable_;
  *(undefined4 *)&this->field_0x4 = 0;
  *(undefined4 *)&this->field_0x14 = 0;
  if (*(int *)&this->field_0x8 != 0) {
    free(*(int *)&this->field_0x8);
  }
  return;
}

// --------------------------------------------------

// Function: do_command
// Address: 00509770
// [HELPER] s_C__msdev_work_age1_x1_tcommand_c: "C:\msdev\work\age1_x1\tcommand.cpp"
void __thiscall TRIBE_Command::do_command(TRIBE_Command *this,void *param_1)
{
  debug_rand(s_C__msdev_work_age1_x1_tcommand_c,0x3f);
  switch(*param_1) {
  case 4:
    do_command_tribe_create(this,(RGE_Command_Create *)param_1);
    return;
  default:
    RGE_Command::do_command((RGE_Command *)this,param_1);
    return;
  case 100:
    do_command_make(this,(TRIBE_Command_Make *)param_1);
    return;
  case 0x65:
    do_command_research(this,(TRIBE_Command_Research *)param_1);
    return;
  case 0x66:
    do_command_build(this,(TRIBE_Command_Build *)param_1);
    return;
  case 0x67:
    do_command_game(this,(TRIBE_Command_Game *)param_1);
    return;
  case 0x68:
    do_command_explore(this,(TRIBE_Command_Explore *)param_1);
    return;
  case 0x69:
    do_command_build_wall(this,(TRIBE_Command_Build_Wall *)param_1);
    return;
  case 0x6a:
    do_command_cancel_build(this,(TRIBE_Command_Cancel_Build *)param_1);
    return;
  case 0x6b:
    do_command_attack_ground(this,(TRIBE_Command_Attack_Ground *)param_1);
    return;
  case 0x6c:
    (**(code **)(*(int *)this + 0x10))(param_1);
    return;
  case 0x6d:
    do_command_trade_attribute(this,(TRIBE_Command_Trade_Attribute *)param_1);
    return;
  case 0x6e:
    do_command_repair(this,(TRIBE_Command_Repair *)param_1);
    return;
  case 0x6f:
    do_command_unload(this,(TRIBE_Command_Unload *)param_1);
    return;
  case 0x77:
    do_command_queue(this,(TRIBE_Command_Queue *)param_1);
    return;
  }
}

// --------------------------------------------------

// Function: do_command_tribe_create
// Address: 00509910
void __thiscall
TRIBE_Command::do_command_tribe_create(TRIBE_Command *this,RGE_Command_Create *param_1)
{
  TRIBE_Building_Object *this_00;
  int iVar1;
  int iVar2;
  
  iVar1 = (uint)param_1->player_id * 4;
  iVar2 = param_1->obj_catagory * 4;
  if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)&this->field_0x4 + 0x40) + iVar1) + 0x24
                                 ) + iVar2) + 0x68) == '\x01') {
    param_1->location_z = 4.0;
  }
  iVar1 = *(int *)(*(int *)(*(int *)&this->field_0x4 + 0x40) + iVar1);
  this_00 = (TRIBE_Building_Object *)
            (**(code **)(**(int **)(*(int *)(iVar1 + 0x24) + iVar2) + 0x18))
                      (iVar1,param_1->location_x,param_1->location_y,param_1->location_z);
  if (*(char *)(this_00->_padding_ + 4) == 'P') {
    TRIBE_Building_Object::build(this_00,10000.0);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_make
// Address: 00509980
void __thiscall TRIBE_Command::do_command_make(TRIBE_Command *this,TRIBE_Command_Make *param_1)
{
  int *piVar1;
  TRIBE_Command_Make *pTVar2;
  TRIBE_Building_Object *this_00;
  int iVar3;
  UnitAIModule *pUVar4;
  undefined4 *unaff_FS_OFFSET;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  short progress;
  short work_target;
  short local_78;
  short local_76;
  char work_name [100];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pTVar2 = param_1;
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560dcb;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Building_Object *)
            RGE_Game_World::object(*(RGE_Game_World **)&this->field_0x4,param_1->unit_id);
  if (this_00 == (TRIBE_Building_Object *)0x0) {
    piVar1 = *(int **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)pTVar2->unit_player_id * 4)
    ;
  }
  else {
    TRIBE_Building_Object::work_status
              (this_00,(short *)&param_1,&local_76,&local_78,work_name + 4,100);
    if (((short)param_1 != 0x67) && ((short)param_1 != 0x66)) {
      work_name._0_4_ = operator_new(0x50);
      local_4 = 0;
      if ((TRIBE_Action_Make_Obj *)work_name._0_4_ == (TRIBE_Action_Make_Obj *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj
                          ((TRIBE_Action_Make_Obj *)work_name._0_4_,(RGE_Action_Object *)this_00,
                           pTVar2->obj_id,pTVar2->unique_id,'\0');
      }
      local_4 = 0xffffffff;
      if (iVar3 != 0) {
        (**(code **)(this_00->_padding_ + 0x208))(iVar3);
      }
      pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)this_00);
      if (pUVar4 != (UnitAIModule *)0x0) {
        iVar3 = 0x26c;
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)this_00);
        UnitAIModule::setCurrentAction(pUVar4,iVar3);
        iVar3 = pTVar2->unique_id;
        fVar8 = -1.0;
        fVar7 = -1.0;
        fVar6 = -1.0;
        iVar5 = -1;
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)this_00);
        UnitAIModule::setCurrentTarget(pUVar4,iVar3,iVar5,fVar6,fVar7,fVar8);
        *unaff_FS_OFFSET = local_c;
        return;
      }
      goto LAB_00509ada;
    }
    piVar1 = *(int **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)pTVar2->unit_player_id * 4)
    ;
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10c))(0,(int)pTVar2->obj_id,pTVar2->unit_id,pTVar2->unique_id);
  }
LAB_00509ada:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: do_command_research
// Address: 00509af0
void __thiscall
TRIBE_Command::do_command_research(TRIBE_Command *this,TRIBE_Command_Research *param_1)
{
  int *piVar1;
  TRIBE_Command_Research *pTVar2;
  TRIBE_Building_Object *this_00;
  int iVar3;
  UnitAIModule *pUVar4;
  undefined4 *unaff_FS_OFFSET;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  short progress;
  short work_target;
  short local_78;
  short local_76;
  char work_name [100];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pTVar2 = param_1;
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560deb;
  *unaff_FS_OFFSET = &local_c;
  this_00 = (TRIBE_Building_Object *)
            RGE_Game_World::object(*(RGE_Game_World **)&this->field_0x4,param_1->unit_id);
  if (this_00 == (TRIBE_Building_Object *)0x0) {
    piVar1 = *(int **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)pTVar2->unit_player_id * 4)
    ;
  }
  else {
    TRIBE_Building_Object::work_status
              (this_00,(short *)&param_1,&local_76,&local_78,work_name + 4,100);
    if (((short)param_1 != 0x67) && ((short)param_1 != 0x66)) {
      work_name._0_4_ = operator_new(0x48);
      local_4 = 0;
      if ((TRIBE_Action_Make_Tech *)work_name._0_4_ == (TRIBE_Action_Make_Tech *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech
                          ((TRIBE_Action_Make_Tech *)work_name._0_4_,(RGE_Action_Object *)this_00,
                           pTVar2->tech_id,pTVar2->unique_id);
      }
      local_4 = 0xffffffff;
      if (iVar3 != 0) {
        (**(code **)(this_00->_padding_ + 0x208))(iVar3);
      }
      pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)this_00);
      if (pUVar4 != (UnitAIModule *)0x0) {
        iVar3 = 0x26c;
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)this_00);
        UnitAIModule::setCurrentAction(pUVar4,iVar3);
        iVar3 = pTVar2->unique_id;
        fVar8 = -1.0;
        fVar7 = -1.0;
        fVar6 = -1.0;
        iVar5 = -1;
        pUVar4 = RGE_Static_Object::unitAI((RGE_Static_Object *)this_00);
        UnitAIModule::setCurrentTarget(pUVar4,iVar3,iVar5,fVar6,fVar7,fVar8);
        *unaff_FS_OFFSET = local_c;
        return;
      }
      goto LAB_00509c48;
    }
    piVar1 = *(int **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)pTVar2->unit_player_id * 4)
    ;
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x118))
              ((int)pTVar2->tech_id,pTVar2->unit_id,0xffffffff,pTVar2->unique_id);
  }
LAB_00509c48:
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: do_command_build
// Address: 00509c60
void __thiscall TRIBE_Command::do_command_build(TRIBE_Command *this,TRIBE_Command_Build *param_1)
{
  TRIBE_Player *this_00;
  int *piVar1;
  int iVar2;
  RGE_Obj_Info RVar3;
  RGE_Obj_Info RVar4;
  RGE_Obj_Info RVar5;
  byte bVar6;
  uchar uVar7;
  RGE_Static_Object *pRVar8;
  uchar *puVar9;
  TRIBE_Command_Build *pTVar10;
  RGE_Command *pRVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  int blockingObject;
  uchar placementResult;
  
  this_00 = *(TRIBE_Player **)
             (*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)param_1->unit_player_id * 4);
  if (((this_00 != (TRIBE_Player *)0x0) && (param_1->obj_id != -1)) &&
     (piVar1 = *(int **)(this_00->_padding_ + param_1->obj_id * 4), piVar1 != (int *)0x0)) {
    iVar2 = *piVar1;
    iVar14 = 1;
    uVar12 = 1;
    puVar9 = &placementResult;
    pRVar11 = (RGE_Command *)0x1;
    bVar6 = (**(code **)(iVar2 + 0x20))
                      (this_00,param_1->location_x,param_1->location_y,puVar9,1,1,1,1,1,1);
    uVar13 = (uint)bVar6;
    if (bVar6 == 0) {
      uVar7 = TRIBE_Player::pay_obj_cost(this_00,param_1->obj_id,1.0,0);
      if (uVar7 == '\0') {
        if (0 < iVar14) {
          RVar4.id._0_1_ = param_1[1].command;
          RVar4.id._1_1_ = param_1[1].unit_num;
          RVar4.id._2_1_ = param_1[1].unit_player_id;
          RVar4.id._3_1_ = param_1[1].field_0x3;
          pRVar8 = RGE_Command::get_obj(pRVar11,RVar4);
          if (pRVar8 != (RGE_Static_Object *)0x0) {
            (**(code **)(this_00->_padding_ + 0x100))
                      (0,uVar12,(int)param_1->obj_id,param_1->location_x,param_1->location_y,
                       param_1->unique_id,pRVar8->id);
            return;
          }
        }
      }
      else {
        pRVar11 = (RGE_Command *)param_1->unique_id;
        uVar12 = (**(code **)(iVar2 + 0x3c))(this_00,param_1->location_x,param_1->location_y,0);
        if (0 < (int)puVar9) {
          pTVar10 = param_1 + 1;
          do {
            RVar5.id._0_1_ = pTVar10->command;
            RVar5.id._1_1_ = pTVar10->unit_num;
            RVar5.id._2_1_ = pTVar10->unit_player_id;
            RVar5.id._3_1_ = pTVar10->field_0x3;
            pRVar8 = RGE_Command::get_obj(pRVar11,RVar5);
            if (pRVar8 != (RGE_Static_Object *)0x0) {
              RGE_Static_Object::removeAllFromPathingGroup(pRVar8);
              (**(code **)(pRVar8->_padding_ + 0x98))
                        (uVar12,param_1->location_x,param_1->location_y,0);
            }
            pTVar10 = (TRIBE_Command_Build *)&pTVar10->location_x;
            puVar9 = puVar9 + -1;
          } while (puVar9 != (uchar *)0x0);
        }
      }
    }
    else if (0 < iVar14) {
      RVar3.id._0_1_ = param_1[1].command;
      RVar3.id._1_1_ = param_1[1].unit_num;
      RVar3.id._2_1_ = param_1[1].unit_player_id;
      RVar3.id._3_1_ = param_1[1].field_0x3;
      pRVar8 = RGE_Command::get_obj(pRVar11,RVar3);
      if (pRVar8 != (RGE_Static_Object *)0x0) {
        (**(code **)(this_00->_padding_ + 0x100))
                  (uVar13 & 0xff,uVar12,(int)param_1->obj_id,param_1->location_x,param_1->location_y
                   ,param_1->unique_id,pRVar8->id);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: do_command_build_wall
// Address: 00509e10
void __thiscall
TRIBE_Command::do_command_build_wall(TRIBE_Command *this,TRIBE_Command_Build_Wall *param_1)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  TRIBE_Player *pTVar4;
  TRIBE_Master_Building_Object *pTVar5;
  RGE_Obj_Info RVar6;
  TRIBE_Command_Build_Wall *pTVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  RGE_Static_Object *this_00;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  TRIBE_Command_Build_Wall *pTVar15;
  uint uVar16;
  int unitNum;
  RGE_Obj_Info *units;
  
  pTVar7 = param_1;
  uVar14 = (uint)param_1->unit_num;
  pTVar15 = param_1 + 1;
  pTVar4 = *(TRIBE_Player **)
            (*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)param_1->unit_player_id * 4);
  if (pTVar4 == (TRIBE_Player *)0x0) {
    return;
  }
  if (param_1->obj_id == -1) {
    return;
  }
  pTVar5 = *(TRIBE_Master_Building_Object **)(pTVar4->_padding_ + param_1->obj_id * 4);
  if (pTVar5 == (TRIBE_Master_Building_Object *)0x0) {
    return;
  }
  uVar16 = (uint)param_1->y2;
  uVar11 = (uint)param_1->y1;
  uVar12 = (int)(uVar16 - uVar11) >> 0x1f;
  param_1 = (TRIBE_Command_Build_Wall *)0x0;
  iVar8 = (uVar16 - uVar11 ^ uVar12) - uVar12;
  uVar10 = (uint)pTVar7->x1;
  uVar12 = (uint)pTVar7->x2;
  uVar13 = (int)(uVar12 - uVar10) >> 0x1f;
  iVar9 = (uVar12 - uVar10 ^ uVar13) - uVar13;
  if (iVar8 == iVar9) {
    iVar8 = pTVar7->unique_id;
  }
  else {
    if (iVar8 < iVar9) {
      place_line_of_walls(this,pTVar4,pTVar5,pTVar7->unique_id,uVar10,uVar11,uVar12,uVar11,
                          (RGE_Static_Object **)&param_1);
      bVar1 = pTVar7->y2;
      bVar2 = pTVar7->y1;
      if (bVar2 < bVar1) {
        bVar3 = pTVar7->x2;
        uVar11 = bVar2 + 1;
      }
      else {
        if (bVar2 <= bVar1) goto LAB_00509fae;
        bVar3 = pTVar7->x2;
        uVar11 = bVar2 - 1;
      }
      uVar10 = (uint)bVar3;
      uVar16 = (uint)bVar1;
      uVar12 = uVar10;
    }
    else {
      place_line_of_walls(this,pTVar4,pTVar5,pTVar7->unique_id,uVar10,uVar11,uVar10,uVar16,
                          (RGE_Static_Object **)&param_1);
      bVar1 = pTVar7->x2;
      bVar2 = pTVar7->x1;
      if (bVar2 < bVar1) {
        uVar11 = (uint)pTVar7->y2;
        uVar10 = bVar2 + 1;
        uVar12 = (uint)bVar1;
        uVar16 = uVar11;
      }
      else {
        if (bVar2 <= bVar1) goto LAB_00509fae;
        uVar11 = (uint)pTVar7->y2;
        uVar10 = bVar2 - 1;
        uVar12 = (uint)bVar1;
        uVar16 = uVar11;
      }
    }
    iVar8 = pTVar7->unique_id;
  }
  place_line_of_walls(this,pTVar4,pTVar5,iVar8,uVar10,uVar11,uVar12,uVar16,
                      (RGE_Static_Object **)&param_1);
LAB_00509fae:
  if (param_1 != (TRIBE_Command_Build_Wall *)0x0) {
    for (; uVar14 != 0; uVar14 = uVar14 - 1) {
      RVar6.id._0_1_ = pTVar15->command;
      RVar6.id._1_1_ = pTVar15->unit_num;
      RVar6.id._2_1_ = pTVar15->unit_player_id;
      RVar6.id._3_1_ = pTVar15->x1;
      this_00 = RGE_Command::get_obj((RGE_Command *)this,RVar6);
      if (this_00 != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(this_00);
        (**(code **)(this_00->_padding_ + 0x98))
                  (param_1,*(undefined4 *)&param_1[3].obj_id,param_1[3].unique_id,0);
      }
      pTVar15 = (TRIBE_Command_Build_Wall *)&pTVar15->y1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: place_line_of_walls
// Address: 0050a010
void __thiscall
TRIBE_Command::place_line_of_walls
          (TRIBE_Command *this,TRIBE_Player *param_1,TRIBE_Master_Building_Object *param_2,
          int param_3,int param_4,int param_5,int param_6,int param_7,RGE_Static_Object **param_8)
{
  code *pcVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  uchar uVar6;
  RGE_Static_Object *pRVar7;
  int x_skip;
  int y_skip;
  int local_8;
  
  iVar4 = param_4;
  if (param_4 == param_6) {
    y_skip = 0;
  }
  else {
    y_skip = ((param_6 <= param_4) - 1 & 2) - 1;
  }
  if (param_5 == param_7) {
    local_8 = 0;
  }
  else {
    local_8 = ((param_7 <= param_5) - 1 & 2) - 1;
  }
  param_4 = param_5;
  param_5 = iVar4;
  pcVar1 = *(code **)(param_2->_padding_ + 0x20);
  while( true ) {
    fVar2 = (float)param_5 - _DAT_00576570;
    fVar3 = (float)param_4 - _DAT_00576570;
    cVar5 = (*pcVar1)(param_1,fVar2,fVar3,0,1,(char)param_2->_padding_,0,1,1,1);
    if (cVar5 == '\0') {
      uVar6 = TRIBE_Player::pay_obj_cost(param_1,(short)param_2->_padding_,1.0,0);
      if (uVar6 == '\0') {
        return;
      }
      pRVar7 = (RGE_Static_Object *)
               (**(code **)(param_2->_padding_ + 0x3c))(param_1,fVar2,fVar3,0,param_3);
      if ((pRVar7 != (RGE_Static_Object *)0x0) && (*param_8 == (RGE_Static_Object *)0x0)) {
        *param_8 = pRVar7;
      }
    }
    if ((param_5 == param_6) && (param_4 == param_7)) break;
    param_5 = param_5 + y_skip;
    param_4 = param_4 + local_8;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_explore
// Address: 0050a140
void __thiscall
TRIBE_Command::do_command_explore(TRIBE_Command *this,TRIBE_Command_Explore *param_1)
{
  uchar *puVar1;
  RGE_Obj_Info RVar2;
  int iVar3;
  TRIBE_Command_Explore *pTVar4;
  RGE_Static_Object *this_00;
  undefined4 uVar5;
  TRIBE_Command_Explore *pTVar6;
  
  pTVar4 = param_1;
  pTVar6 = param_1 + 1;
  if ((*(int *)(*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)param_1->unit_player_id * 4) != 0)
     && (puVar1 = &param_1->numUnits, param_1 = (TRIBE_Command_Explore *)0x0, *puVar1 != '\0')) {
    do {
      RVar2.id._0_1_ = pTVar6->command;
      RVar2.id._1_1_ = pTVar6->numUnits;
      RVar2.id._2_1_ = pTVar6->unit_player_id;
      RVar2.id._3_1_ = pTVar6->field_0x3;
      this_00 = RGE_Command::get_obj((RGE_Command *)this,RVar2);
      if (this_00 != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(this_00);
        iVar3 = this_00->_padding_;
        uVar5 = __ftol(1);
        uVar5 = __ftol(uVar5);
        (**(code **)(iVar3 + 0x17c))(uVar5);
      }
      param_1 = (TRIBE_Command_Explore *)&param_1->numUnits;
      pTVar6 = (TRIBE_Command_Explore *)&pTVar6->targetXPosition;
    } while ((int)param_1 < (int)(uint)pTVar4->numUnits);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_game
// Address: 0050a1d0
// [HELPER] s_: ""
// [HELPER] s_Temp_Screen: "Temp Screen"
// [HELPER] s_syncerr_d_gam: "syncerr%d.gam"
void __thiscall TRIBE_Command::do_command_game(TRIBE_Command *this,TRIBE_Command_Game *param_1)
{
  TDrawSystem *this_00;
  uchar uVar1;
  int iVar2;
  TEasy_Panel *this_01;
  void *pvVar3;
  undefined4 *unaff_FS_OFFSET;
  char fileName [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00560e0e;
  *unaff_FS_OFFSET = &local_c;
  switch(param_1->game_command) {
  case '\0':
    uVar1 = __ftol();
    RGE_Player::set_relation
              (*(RGE_Player **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + param_1->var1 * 4),
               (int)param_1->var2,uVar1);
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (8,(int)param_1->var1,(int)param_1->var2,(int)param_1->var4,0);
    RGE_Game_World::update_mutual_allies(*(RGE_Game_World **)&this->field_0x4);
    break;
  case '\x01':
    RGE_Game_World::set_game_speed(*(RGE_Game_World **)&this->field_0x4,param_1->var3);
    break;
  case '\x02':
    (**(code **)(**(int **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + param_1->var1 * 4) + 0x78))
              (CONCAT22((short)((uint)param_1->var3 >> 0x10),param_1->var2),param_1->var3,0);
    break;
  case '\x04':
    rge_base_game->quick_build = (int)param_1->var1;
    break;
  case '\x05':
    RGE_Player::set_allied_victory
              (*(RGE_Player **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + param_1->var1 * 4),
               (uchar)param_1->var2);
    break;
  case '\x06':
    TRIBE_World::cheat(*(TRIBE_World **)&this->field_0x4,param_1->var1,(ushort)(byte)param_1->var2);
    break;
  case '\a':
    (**(code **)(**(int **)(*(int *)&this->field_0x4 + 0x4c) + 8))
              (0x71,*(undefined4 *)(*(int *)(*(int *)&this->field_0x4 + 0x40) + param_1->var1 * 4));
    break;
  case '\b':
    out_of_sync2 = 1;
    fileName._0_4_ = operator_new(0x47c);
    local_4 = 0;
    if ((TRIBE_Screen_Status_Message *)fileName._0_4_ != (TRIBE_Screen_Status_Message *)0x0) {
      TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
                ((TRIBE_Screen_Status_Message *)fileName._0_4_,s_Temp_Screen,s_,(char *)0x0,-1);
    }
    local_4 = 0xffffffff;
    TPanelSystem::setCurrentPanel(&panel_system,s_Temp_Screen,0);
    TRIBE_Game::close_game_screens((TRIBE_Game *)rge_base_game,1);
    if (do_debug_random != 0) {
      debug_random_write();
      dump_vismap_log();
      if (actionFile != (_iobuf *)0x0) {
        fclose(actionFile);
        actionFile = (_iobuf *)0x0;
      }
      if (DVlogf != (_iobuf *)0x0) {
        fclose(DVlogf);
        DVlogf = (_iobuf *)0x0;
      }
      if (DDlogf != (_iobuf *)0x0) {
        fclose(DDlogf);
        DDlogf = (_iobuf *)0x0;
      }
    }
    iVar2 = TCommunications_Handler::WhoAmI(comm);
    sprintf(fileName + 4,s_syncerr_d_gam,iVar2);
    TRIBE_Game::save_game((TRIBE_Game *)rge_base_game,fileName + 4);
    RGE_Player::loss_if_game_on
              (*(RGE_Player **)
                (*(int *)(*(int *)&this->field_0x4 + 0x40) +
                *(short *)(*(int *)&this->field_0x4 + 0x7c) * 4));
    TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
    this_01 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
    if (this_01 != (TEasy_Panel *)0x0) {
      this_00 = rge_base_game->draw_system;
      pvVar3 = TEasy_Panel::get_palette(this_01);
      TDrawSystem::SetPalette(this_00,pvVar3);
      RGE_Base_Game::set_render_all(rge_base_game);
      RGE_Base_Game::draw_window(rge_base_game);
      TEasy_Panel::popupOKDialog(this_01,0x966,(char *)0x0,0x1c2,100);
    }
    TPanelSystem::destroyPanel(&panel_system,s_Temp_Screen);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: do_command_cancel_build
// Address: 0050a490
void __thiscall
TRIBE_Command::do_command_cancel_build(TRIBE_Command *this,TRIBE_Command_Cancel_Build *param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = RGE_Game_World::object(*(RGE_Game_World **)&this->field_0x4,param_1->unit_id);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    (**(code **)(pRVar1->_padding_ + 0x240))();
  }
  return;
}

// --------------------------------------------------

// Function: do_command_attack_ground
// Address: 0050a4c0
void __thiscall
TRIBE_Command::do_command_attack_ground(TRIBE_Command *this,TRIBE_Command_Attack_Ground *param_1)
{
  RGE_Obj_Info RVar1;
  RGE_Static_Object *pRVar2;
  uint uVar3;
  TRIBE_Command_Attack_Ground *pTVar4;
  
  pTVar4 = param_1 + 1;
  for (uVar3 = (uint)param_1->unit_num; uVar3 != 0; uVar3 = uVar3 - 1) {
    RVar1.id._0_1_ = pTVar4->command;
    RVar1.id._1_1_ = pTVar4->unit_num;
    RVar1.id._2_2_ = *(undefined2 *)&pTVar4->field_0x2;
    pRVar2 = RGE_Command::get_obj((RGE_Command *)this,RVar1);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar2->_padding_ + 0x14c))(param_1->location_x,param_1->location_y,0,1);
    }
    pTVar4 = (TRIBE_Command_Attack_Ground *)&pTVar4->location_x;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_give_attribute
// Address: 0050a510
void __thiscall
TRIBE_Command::do_command_give_attribute(TRIBE_Command *this,TRIBE_Command_Give_Attribute *param_1)
{
  float *pfVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  TRIBE_Command_Give_Attribute *pTVar5;
  undefined4 uVar6;
  undefined4 in_EDX;
  float fVar7;
  float unaff_EBX;
  float unaff_ESI;
  float cost;
  float local_4;
  
  pTVar5 = param_1;
  local_4 = 0.0;
  if (param_1->attr_amount < _DAT_00576574) {
    param_1 = (TRIBE_Command_Give_Attribute *)0x0;
  }
  else {
    param_1 = (TRIBE_Command_Give_Attribute *)param_1->attr_amount;
  }
  if ((float)_DAT_00576578 < (float)param_1) {
    local_4 = pTVar5->attr_cost * (float)param_1;
  }
  bVar2 = pTVar5->attr_id;
  iVar3 = *(int *)(*(int *)&this->field_0x4 + 0x40);
  iVar4 = *(int *)(*(int *)(iVar3 + (uint)pTVar5->player_id * 4) + 0x50);
  pfVar1 = (float *)(iVar4 + (uint)bVar2 * 4);
  if (*(float *)(iVar4 + (uint)bVar2 * 4) < (float)param_1 + local_4) {
    param_1 = (TRIBE_Command_Give_Attribute *)(*pfVar1 - *pfVar1 * pTVar5->attr_cost);
  }
  fVar7 = (float)CONCAT22((short)((uint)in_EDX >> 0x10),(ushort)bVar2);
  (**(code **)(**(int **)(iVar3 + (uint)pTVar5->to_player_id * 4) + 0x78))(fVar7,param_1,0);
  iVar3 = *(int *)(*(int *)&this->field_0x4 + 0x40);
  (**(code **)(**(int **)(iVar3 + (uint)pTVar5->player_id * 4) + 0x78))
            (CONCAT22((short)((uint)iVar3 >> 0x10),(ushort)pTVar5->attr_id),-(unaff_EBX + unaff_ESI)
             ,0);
  (**(code **)(**(int **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)pTVar5->player_id * 4) +
              0x78))(0x35,param_1,0);
  (**(code **)(**(int **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)pTVar5->to_player_id * 4
                         ) + 0x78))(0x35,-fVar7,0);
  iVar3 = rge_base_game->_padding_;
  uVar6 = __ftol();
  (**(code **)(iVar3 + 0x40))(7,pTVar5->player_id,pTVar5->to_player_id,pTVar5->attr_id,uVar6);
  bVar2 = pTVar5->to_player_id;
  iVar3 = **(int **)(*(int *)(*(int *)&this->field_0x4 + 0x40) + (uint)bVar2 * 4);
  uVar6 = __ftol(0);
  (**(code **)(iVar3 + 0xe8))(pTVar5->player_id,(uint)bVar2,0x20a,pTVar5->attr_id,uVar6);
  return;
}

// --------------------------------------------------

// Function: do_command_trade_attribute
// Address: 0050a6a0
void __thiscall
TRIBE_Command::do_command_trade_attribute
          (TRIBE_Command *this,TRIBE_Command_Trade_Attribute *param_1)
{
  RGE_Obj_Info RVar1;
  RGE_Static_Object *pRVar2;
  uint uVar3;
  TRIBE_Command_Trade_Attribute *pTVar4;
  
  pTVar4 = param_1 + 1;
  for (uVar3 = (uint)param_1->unit_num; uVar3 != 0; uVar3 = uVar3 - 1) {
    RVar1.id._0_1_ = pTVar4->command;
    RVar1.id._1_1_ = pTVar4->unit_num;
    RVar1.id._2_2_ = *(undefined2 *)&pTVar4->field_0x2;
    pRVar2 = RGE_Command::get_obj((RGE_Command *)this,RVar1);
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      pRVar2->attribute_type_held = (short)param_1->attribute;
    }
    pTVar4 = (TRIBE_Command_Trade_Attribute *)&pTVar4->attribute;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_repair
// Address: 0050a6e0
void __thiscall TRIBE_Command::do_command_repair(TRIBE_Command *this,TRIBE_Command_Repair *param_1)
{
  byte bVar1;
  RGE_Obj_Info RVar2;
  RGE_Static_Object *pRVar3;
  TRIBE_Combat_Object *this_00;
  TRIBE_Command_Repair *pTVar4;
  uint uVar5;
  
  bVar1 = param_1->unit_num;
  pTVar4 = param_1 + 1;
  pRVar3 = RGE_Command::get_obj((RGE_Command *)this,(RGE_Obj_Info)(param_1->target).id);
  for (uVar5 = (uint)bVar1; uVar5 != 0; uVar5 = uVar5 - 1) {
    RVar2.id._0_1_ = pTVar4->command;
    RVar2.id._1_1_ = pTVar4->unit_num;
    RVar2.id._2_2_ = *(undefined2 *)&pTVar4->field_0x2;
    this_00 = (TRIBE_Combat_Object *)RGE_Command::get_obj((RGE_Command *)this,RVar2);
    if (this_00 != (TRIBE_Combat_Object *)0x0) {
      TRIBE_Combat_Object::do_repair(this_00,pRVar3);
    }
    pTVar4 = (TRIBE_Command_Repair *)&pTVar4->target;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_unload
// Address: 0050a730
void __thiscall TRIBE_Command::do_command_unload(TRIBE_Command *this,TRIBE_Command_Unload *param_1)
{
  RGE_Obj_Info RVar1;
  uint uVar2;
  RGE_Static_Object *this_00;
  int iVar3;
  TRIBE_Command_Unload *pTVar4;
  
  pTVar4 = param_1 + 1;
  for (uVar2 = (uint)param_1->unit_num; uVar2 != 0; uVar2 = uVar2 - 1) {
    RVar1.id._0_1_ = pTVar4->command;
    RVar1.id._1_1_ = pTVar4->unit_num;
    RVar1.id._2_2_ = *(undefined2 *)&pTVar4->field_0x2;
    this_00 = RGE_Command::get_obj((RGE_Command *)this,RVar1);
    if (this_00 != (RGE_Static_Object *)0x0) {
      RGE_Static_Object::removeAllFromPathingGroup(this_00);
      iVar3 = (int)this_00->owner->id;
      (**(code **)(this_00->owner->_padding_ + 0x34))
                (iVar3,this_00->id,0x2d1,this_00->id,iVar3,param_1->location_x,param_1->location_y,0
                 ,0x3f800000,1,0,100);
    }
    pTVar4 = (TRIBE_Command_Unload *)&pTVar4->location_x;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_queue
// Address: 0050a7b0
void __thiscall TRIBE_Command::do_command_queue(TRIBE_Command *this,TRIBE_Command_Queue *param_1)
{
  short sVar1;
  TRIBE_Building_Object *this_00;
  
  this_00 = (TRIBE_Building_Object *)
            RGE_Game_World::object(*(RGE_Game_World **)&this->field_0x4,param_1->bldg_id);
  if (this_00 != (TRIBE_Building_Object *)0x0) {
    sVar1 = param_1->train_count;
    if (0 < sVar1) {
      TRIBE_Building_Object::add_to_production_queue(this_00,param_1->train_id,sVar1);
      return;
    }
    TRIBE_Building_Object::remove_from_production_queue(this_00,param_1->train_id,-sVar1);
  }
  return;
}

// --------------------------------------------------

// Function: command_make
// Address: 0050a7f0
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_make(TRIBE_Command *this,RGE_Static_Object *param_1,short param_2)
{
  short sVar1;
  undefined1 *puVar2;
  
  if (param_1 != (RGE_Static_Object *)0x0) {
    puVar2 = (undefined1 *)calloc(1,0x10);
    if (puVar2 != (undefined1 *)0x0) {
      *(long *)(puVar2 + 4) = param_1->id;
      sVar1 = param_1->owner->id;
      *puVar2 = 100;
      puVar2[8] = (char)sVar1;
      *(short *)(puVar2 + 10) = param_2;
      *(undefined4 *)(puVar2 + 0xc) = 0xffffffff;
      TDebuggingLog::Log((TDebuggingLog *)param_1->master_obj,(char *)L,
                         s_______>SEND_CMD_MAKE__UNIT__s_OB,
                         ((TDebuggingLog *)param_1->master_obj)->LogToFile,(int)param_2);
      RGE_Command::submit((RGE_Command *)this,puVar2,0x10);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_make
// Address: 0050a860
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_make(TRIBE_Command *this,int param_1,int param_2,int param_3,int param_4)
{
  undefined1 *puVar1;
  
  if (-1 < param_2) {
    puVar1 = (undefined1 *)calloc(1,0x10);
    if (puVar1 != (undefined1 *)0x0) {
      *(int *)(puVar1 + 4) = param_2;
      puVar1[8] = (char)param_1;
      *puVar1 = 100;
      *(short *)(puVar1 + 10) = (short)param_3;
      *(int *)(puVar1 + 0xc) = param_4;
      TDebuggingLog::Log((TDebuggingLog *)param_3,(char *)L,s_______>SEND_CMD_MAKE2__PLR__d_BL,
                         param_1,param_2,param_3);
      RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_research
// Address: 0050a8d0
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_research(TRIBE_Command *this,RGE_Static_Object *param_1,short param_2)
{
  short sVar1;
  undefined1 *puVar2;
  
  if (param_1 != (RGE_Static_Object *)0x0) {
    puVar2 = (undefined1 *)calloc(1,0x10);
    if (puVar2 != (undefined1 *)0x0) {
      *(long *)(puVar2 + 4) = param_1->id;
      sVar1 = param_1->owner->id;
      *puVar2 = 0x65;
      puVar2[8] = (char)sVar1;
      *(short *)(puVar2 + 10) = param_2;
      *(undefined4 *)(puVar2 + 0xc) = 0xffffffff;
      TDebuggingLog::Log((TDebuggingLog *)param_1->master_obj,(char *)L,
                         s_______>SEND_CMD_RESEARCH__UNIT__,
                         ((TDebuggingLog *)param_1->master_obj)->LogToFile,(int)param_2);
      RGE_Command::submit((RGE_Command *)this,puVar2,0x10);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_research
// Address: 0050a940
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_research(TRIBE_Command *this,int param_1,int param_2,int param_3,int param_4)
{
  undefined1 *puVar1;
  
  if (-1 < param_2) {
    puVar1 = (undefined1 *)calloc(1,0x10);
    if (puVar1 != (undefined1 *)0x0) {
      *(int *)(puVar1 + 4) = param_2;
      puVar1[8] = (char)param_1;
      *puVar1 = 0x65;
      *(short *)(puVar1 + 10) = (short)param_3;
      *(int *)(puVar1 + 0xc) = param_4;
      TDebuggingLog::Log((TDebuggingLog *)param_3,(char *)L,s_______>SEND_CMD_RESEARCH2__PLR__,
                         param_1,param_2,param_3);
      RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_build
// Address: 0050a9b0
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_build
          (TRIBE_Command *this,RGE_Static_Object **param_1,short param_2,short param_3,float param_4
          ,float param_5)
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    iVar8 = (int)param_2;
    iVar1 = iVar8 * 4 + 0x14;
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 0x14);
    if (puVar4 != (undefined1 *)0x0) {
      if (0 < iVar8) {
        iVar6 = (int)param_1 - (int)puVar5;
        iVar7 = iVar8;
        do {
          iVar2 = *(int *)(iVar6 + (int)puVar5);
          if (iVar2 == 0) {
            *puVar5 = 0xffffffff;
          }
          else {
            *puVar5 = *(undefined4 *)(iVar2 + 4);
          }
          puVar5 = puVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *puVar4 = 0x66;
      puVar4[1] = (undefined1)param_2;
      if (*param_1 == (RGE_Static_Object *)0x0) {
        uVar3 = 0xff;
      }
      else {
        uVar3 = (undefined1)(*param_1)->owner->id;
      }
      puVar4[2] = uVar3;
      *(short *)(puVar4 + 0xc) = param_3;
      *(float *)(puVar4 + 4) = param_4;
      *(float *)(puVar4 + 8) = param_5;
      *(undefined4 *)(puVar4 + 0x10) = 0xffffffff;
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_BUILD__CNT__d_OB,iVar8,(int)param_3);
      RGE_Command::submit((RGE_Command *)this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_build
// Address: 0050aa90
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_build
          (TRIBE_Command *this,int param_1,int *param_2,int param_3,int param_4,float param_5,
          float param_6,int param_7)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    iVar1 = param_3 * 4 + 0x14;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 0x14);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_3) {
        iVar4 = (int)param_2 - (int)puVar3;
        iVar5 = param_3;
        do {
          *puVar3 = *(undefined4 *)(iVar4 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      *(float *)(puVar2 + 4) = param_5;
      *(float *)(puVar2 + 8) = param_6;
      *puVar2 = 0x66;
      puVar2[1] = (char)param_3;
      *(short *)(puVar2 + 0xc) = (short)param_4;
      *(int *)(puVar2 + 0x10) = param_7;
      puVar2[2] = (undefined1)param_1;
      TDebuggingLog::Log((TDebuggingLog *)param_7,(char *)L,s_______>SEND_CMD_BUILD2__CNT__d_O,
                         param_3,param_4);
      RGE_Command::submit((RGE_Command *)this,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_build_wall
// Address: 0050ab30
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_build_wall
          (TRIBE_Command *this,RGE_Static_Object **param_1,short param_2,short param_3,long param_4,
          long param_5,long param_6,long param_7)
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    iVar7 = (int)param_2;
    iVar1 = iVar7 * 4 + 0x10;
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 0x10);
    if (puVar4 != (undefined1 *)0x0) {
      if (0 < iVar7) {
        iVar6 = (int)param_1 - (int)puVar5;
        iVar8 = iVar7;
        do {
          iVar2 = *(int *)(iVar6 + (int)puVar5);
          if (iVar2 == 0) {
            *puVar5 = 0xffffffff;
          }
          else {
            *puVar5 = *(undefined4 *)(iVar2 + 4);
          }
          puVar5 = puVar5 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      *puVar4 = 0x69;
      puVar4[1] = (char)param_2;
      if (*param_1 == (RGE_Static_Object *)0x0) {
        uVar3 = 0xff;
      }
      else {
        uVar3 = (undefined1)(*param_1)->owner->id;
      }
      puVar4[2] = uVar3;
      *(short *)(puVar4 + 8) = param_3;
      if (param_4 < 0) {
        param_4 = 0;
      }
      if (0xff < param_4) {
        param_4 = 0xff;
      }
      if (param_5 < 0) {
        param_5 = 0;
      }
      if (0xff < param_5) {
        param_5 = 0xff;
      }
      if (param_6 < 0) {
        param_6 = 0;
      }
      if (0xff < param_6) {
        param_6 = 0xff;
      }
      if (param_7 < 0) {
        param_7 = 0;
      }
      if (0xff < param_7) {
        param_7 = 0xff;
      }
      puVar4[6] = (char)param_7;
      puVar4[3] = (char)param_4;
      puVar4[4] = (char)param_5;
      puVar4[5] = (char)param_6;
      *(undefined4 *)(puVar4 + 0xc) = 0xffffffff;
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_BLD_WALL__CNT__d,iVar7,(int)param_3);
      RGE_Command::submit((RGE_Command *)this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_explore
// Address: 0050ac70
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_explore
          (TRIBE_Command *this,int param_1,int *param_2,int param_3,float param_4,float param_5)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    iVar1 = param_3 * 4 + 0xc;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 0xc);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_3) {
        iVar4 = (int)param_2 - (int)puVar3;
        iVar5 = param_3;
        do {
          *puVar3 = *(undefined4 *)(iVar4 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      *puVar2 = 0x68;
      puVar2[1] = (char)param_3;
      puVar2[2] = (undefined1)param_1;
      *(float *)(puVar2 + 4) = param_4;
      *(float *)(puVar2 + 8) = param_5;
      TDebuggingLog::Log((TDebuggingLog *)param_4,(char *)L,s_______>SEND_CMD_EXPLORE__CNT__d_,
                         param_3);
      RGE_Command::submit((RGE_Command *)this,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_allied_victory
// Address: 0050ad00
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_allied_victory(TRIBE_Command *this,short param_1,uchar param_2)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *(short *)(puVar1 + 2) = param_1;
    *(ushort *)(puVar1 + 4) = (ushort)param_2;
    *(undefined4 *)(puVar1 + 8) = 0;
    *puVar1 = 0x67;
    puVar1[1] = 5;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_ALLIED_VIC__PLR_,(int)param_1,param_2);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_relation
// Address: 0050ad70
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_relation(TRIBE_Command *this,short param_1,short param_2,short param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *(short *)(puVar1 + 4) = param_2;
    *(short *)(puVar1 + 0xc) = param_3;
    *(float *)(puVar1 + 8) = (float)(int)param_3;
    *(short *)(puVar1 + 2) = param_1;
    *puVar1 = 0x67;
    puVar1[1] = 0;
    TDebuggingLog::Log((TDebuggingLog *)(int)param_2,(char *)L,s_______>SEND_CMD_RELATION__PLR__d,
                       (int)param_1,(TDebuggingLog *)(int)param_2,(int)param_3);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_game_speed
// Address: 0050adf0
// [HELPER] s_______: "      "
void __thiscall TRIBE_Command::command_game_speed(TRIBE_Command *this,float param_1)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(float *)(puVar1 + 8) = param_1;
    puVar1[1] = 1;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_GAME_SPD);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_save_game
// Address: 0050ae40
// [HELPER] s_______: "      "
void __thiscall TRIBE_Command::command_save_game(TRIBE_Command *this)
{
  undefined1 *puVar1;
  TDebuggingLog *this_00;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    puVar1[1] = 8;
    TDebuggingLog::Log(this_00,(char *)L,s_______>SEND_CMD_SAVEGAME);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_inventory
// Address: 0050ae80
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_inventory(TRIBE_Command *this,short param_1,short param_2,float param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *(short *)(puVar1 + 4) = param_2;
    *(float *)(puVar1 + 8) = param_3;
    *(short *)(puVar1 + 2) = param_1;
    *puVar1 = 0x67;
    puVar1[1] = 2;
    TDebuggingLog::Log((TDebuggingLog *)(int)param_2,(char *)L,s_______>SEND_CMD_INV__PLR__d_INV_,
                       (int)param_1,(TDebuggingLog *)(int)param_2);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_upgrade_town
// Address: 0050aee0
// [HELPER] s_______: "      "
void __thiscall TRIBE_Command::command_upgrade_town(TRIBE_Command *this,short param_1)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(short *)(puVar1 + 2) = param_1;
    puVar1[1] = 3;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_UPG_TOWN);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_quick_build
// Address: 0050af30
// [HELPER] s_______: "      "
void __thiscall TRIBE_Command::command_quick_build(TRIBE_Command *this,short param_1)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(short *)(puVar1 + 2) = param_1;
    puVar1[1] = 4;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_QUICKBLD);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_shared_los
// Address: 0050af80
// [HELPER] s_______: "      "
void __thiscall TRIBE_Command::command_shared_los(TRIBE_Command *this,short param_1)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(short *)(puVar1 + 2) = param_1;
    puVar1[1] = 7;
    TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_SHAREDLOS);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_cancel_build
// Address: 0050afd0
// [HELPER] s_______: "      "
void __thiscall TRIBE_Command::command_cancel_build(TRIBE_Command *this,RGE_Static_Object *param_1)
{
  TDebuggingLog *this_00;
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,8);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x6a;
    this_00 = (TDebuggingLog *)param_1->id;
    *(TDebuggingLog **)(puVar1 + 4) = this_00;
    TDebuggingLog::Log(this_00,(char *)L,s_______>SEND_CMD_CANCELBLD);
    RGE_Command::submit((RGE_Command *)this,puVar1,8);
  }
  return;
}

// --------------------------------------------------

// Function: command_attack_ground
// Address: 0050b020
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_attack_ground
          (TRIBE_Command *this,RGE_Static_Object **param_1,short param_2,float param_3,float param_4
          )
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    iVar7 = (int)param_2;
    iVar1 = iVar7 * 4 + 0xc;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0xc);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar7) {
        iVar5 = (int)param_1 - (int)puVar4;
        iVar6 = iVar7;
        do {
          iVar2 = *(int *)(iVar5 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      *puVar3 = 0x6b;
      puVar3[1] = (undefined1)param_2;
      *(float *)(puVar3 + 4) = param_3;
      *(float *)(puVar3 + 8) = param_4;
      TDebuggingLog::Log((TDebuggingLog *)param_4,(char *)L,s_______>SEND_CMD_ATTACK_GRND__CNT,iVar7
                        );
      RGE_Command::submit((RGE_Command *)this,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_cheat
// Address: 0050b0d0
// [HELPER] s_______: "      "
void __thiscall TRIBE_Command::command_cheat(TRIBE_Command *this,short param_1,short param_2)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x67;
    *(short *)(puVar1 + 2) = param_1;
    *(short *)(puVar1 + 4) = param_2;
    puVar1[1] = 6;
    TDebuggingLog::Log((TDebuggingLog *)(int)param_2,(char *)L,s_______>SEND_CMD_CHEAT__d,
                       (TDebuggingLog *)(int)param_2);
    RGE_Command::submit((RGE_Command *)this,puVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: command_give_attribute
// Address: 0050b130
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_give_attribute
          (TRIBE_Command *this,int param_1,int param_2,int param_3,float param_4,float param_5)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0xc);
  puVar1[3] = (undefined1)param_3;
  *(float *)(puVar1 + 4) = param_4;
  *puVar1 = 0x6c;
  puVar1[1] = (char)param_1;
  puVar1[2] = (char)param_2;
  *(float *)(puVar1 + 8) = param_5;
  TDebuggingLog::Log((TDebuggingLog *)param_2,(char *)L,s_______>SEND_CMD_GIVE_ATTR__PLR__,param_1,
                     param_2);
  RGE_Command::submit((RGE_Command *)this,puVar1,0xc);
  return;
}

// --------------------------------------------------

// Function: command_trade_attribute
// Address: 0050b190
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_trade_attribute
          (TRIBE_Command *this,RGE_Static_Object **param_1,short param_2,long param_3)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    iVar7 = (int)param_2;
    iVar1 = iVar7 * 4 + 8;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 8);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar7) {
        iVar5 = (int)param_1 - (int)puVar4;
        iVar6 = iVar7;
        do {
          iVar2 = *(int *)(iVar5 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      *puVar3 = 0x6d;
      puVar3[1] = (undefined1)param_2;
      *(long *)(puVar3 + 4) = param_3;
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_TRADE_ATTR__CNT_,iVar7);
      RGE_Command::submit((RGE_Command *)this,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_trade_attribute
// Address: 0050b230
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_trade_attribute(TRIBE_Command *this,int param_1,int param_2,long param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0xc);
  if ((puVar1 != (undefined1 *)0x0) && ((int *)(puVar1 + 8) != (int *)0x0)) {
    *(int *)(puVar1 + 8) = param_1;
    *puVar1 = 0x6d;
    puVar1[1] = 1;
    *(long *)(puVar1 + 4) = param_3;
    TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_______>SEND_CMD_TRADE_ATTR2);
    RGE_Command::submit((RGE_Command *)this,puVar1,0xc);
  }
  return;
}

// --------------------------------------------------

// Function: command_repair
// Address: 0050b290
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_repair
          (TRIBE_Command *this,RGE_Static_Object **param_1,short param_2,RGE_Static_Object *param_3)
{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 extraout_ECX;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = (int)param_2;
  iVar1 = iVar8 * 4 + 8;
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 8);
    if (puVar4 != (undefined1 *)0x0) {
      uVar6 = extraout_ECX;
      if (0 < iVar8) {
        iVar7 = (int)param_1 - (int)puVar5;
        iVar9 = iVar8;
        do {
          iVar2 = *(int *)(iVar7 + (int)puVar5);
          if (iVar2 == 0) {
            *puVar5 = 0xffffffff;
            uVar6 = 0;
          }
          else {
            uVar6 = *(undefined4 *)(iVar2 + 4);
            *puVar5 = uVar6;
          }
          puVar5 = puVar5 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      lVar3 = param_3->id;
      *puVar4 = 0x6e;
      *(long *)(puVar4 + 4) = lVar3;
      puVar4[1] = (undefined1)param_2;
      TDebuggingLog::Log((TDebuggingLog *)CONCAT31((int3)((uint)uVar6 >> 8),(undefined1)param_2),
                         (char *)L,s_______>SEND_CMD_REPAIR__CNT__d_,iVar8);
      RGE_Command::submit((RGE_Command *)this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_unload
// Address: 0050b330
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_unload
          (TRIBE_Command *this,RGE_Static_Object **param_1,short param_2,float param_3,float param_4
          )
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    iVar7 = (int)param_2;
    iVar1 = iVar7 * 4 + 0xc;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0xc);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar7) {
        iVar5 = (int)param_1 - (int)puVar4;
        iVar6 = iVar7;
        do {
          iVar2 = *(int *)(iVar5 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      *puVar3 = 0x6f;
      puVar3[1] = (undefined1)param_2;
      *(float *)(puVar3 + 4) = param_3;
      *(float *)(puVar3 + 8) = param_4;
      TDebuggingLog::Log((TDebuggingLog *)param_4,(char *)L,s_______>SEND_CMD_UNLOAD__CNT__d_,iVar7)
      ;
      RGE_Command::submit((RGE_Command *)this,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_queue
// Address: 0050b3e0
// [HELPER] s_______: "      "
void __thiscall
TRIBE_Command::command_queue
          (TRIBE_Command *this,RGE_Static_Object *param_1,short param_2,short param_3)
{
  long lVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)calloc(1,0xc);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 0x77;
    lVar1 = param_1->id;
    *(short *)(puVar2 + 10) = param_3;
    *(long *)(puVar2 + 4) = lVar1;
    *(short *)(puVar2 + 8) = param_2;
    TDebuggingLog::Log((TDebuggingLog *)(int)param_2,(char *)L,s_______>SEND_CMD_QUEUE__B__d_T__d,
                       param_1->id,(TDebuggingLog *)(int)param_2,(int)param_3);
    RGE_Command::submit((RGE_Command *)this,puVar2,0xc);
  }
  return;
}

// --------------------------------------------------


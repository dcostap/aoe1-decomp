// Class: RGE_Command
// Size:  0x18
//
// VTable Layout:
// [00] do_command_give_attribute
// [01] `vector_deleting_destructor'
// [02] do_command
// [03] command_give_attribute
//
// Member Layout:
// [0x004] RGE_Game_World * world
// [0x008] uchar * last_order
// [0x00C] long last_order_size
// [0x010] long last_order_time
// [0x014] TCommunications_Handler * com_hand
// ----------------------------------------------------------------

// Function: RGE_Command
// Address: 00433d40
void __thiscall
RGE_Command::RGE_Command(RGE_Command *this,RGE_Game_World *param_1,TCommunications_Handler *param_2)
{
  this->world = param_1;
  this->com_hand = param_2;
  this->_padding_ = (int)&_vftable_;
  this->last_order = (uchar *)0x0;
  this->last_order_size = 0;
  return;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 00433d70
void * __thiscall RGE_Command::_vector_deleting_destructor_(RGE_Command *this,uint param_1)
{
  ~RGE_Command(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Command
// Address: 00433d90
void __thiscall RGE_Command::~RGE_Command(RGE_Command *this)
{
  this->_padding_ = (int)&_vftable_;
  this->world = (RGE_Game_World *)0x0;
  this->com_hand = (TCommunications_Handler *)0x0;
  if (this->last_order != (uchar *)0x0) {
    free(this->last_order);
  }
  return;
}

// --------------------------------------------------

// Function: reset_communications
// Address: 00433db0
void __thiscall
RGE_Command::reset_communications(RGE_Command *this,TCommunications_Handler *param_1)
{
  this->com_hand = param_1;
  return;
}

// --------------------------------------------------

// Function: get_obj
// Address: 00433dc0
RGE_Static_Object * __thiscall RGE_Command::get_obj(RGE_Command *this,RGE_Obj_Info param_1)
{
  RGE_Static_Object *pRVar1;
  
  if (param_1.id == -1) {
    return (RGE_Static_Object *)0x0;
  }
  pRVar1 = RGE_Game_World::object(this->world,param_1.id);
  return pRVar1;
}

// --------------------------------------------------

// Function: do_commands
// Address: 00433de0
void __thiscall RGE_Command::do_commands(RGE_Command *this)
{
  code *pcVar1;
  void *pvVar2;
  
  if ((this->com_hand != (TCommunications_Handler *)0x0) &&
     (pvVar2 = TCommunications_Handler::get_command(this->com_hand), pvVar2 != (void *)0x0)) {
    pcVar1 = *(code **)(this->_padding_ + 8);
    do {
      (*pcVar1)(pvVar2);
      if (pvVar2 != (void *)0x0) {
        operator_delete(pvVar2);
      }
      pvVar2 = TCommunications_Handler::get_command(this->com_hand);
    } while (pvVar2 != (void *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: do_command
// Address: 00433e20
void __thiscall RGE_Command::do_command(RGE_Command *this,void *param_1)
{
  switch(*param_1) {
  case 0:
    do_command_order(this,(RGE_Command_Order *)param_1);
    return;
  case 1:
    do_command_stop(this,(RGE_Command_Stop *)param_1);
    return;
  case 2:
    do_command_work(this,(RGE_Command_Order *)param_1);
    return;
  case 3:
    do_command_move(this,(RGE_Command_Order *)param_1);
    return;
  case 4:
    do_command_create(this,(RGE_Command_Create *)param_1);
    return;
  case 5:
    do_command_add_attribute(this,(RGE_Command_Add_Attribute *)param_1);
    return;
  case 6:
    do_command_formation(this,(RGE_Command_Formation *)param_1);
    return;
  case 7:
    (**(code **)this->_padding_)(param_1);
    return;
  case 8:
    do_command_create_group(this,(RGE_Command_Create_Group *)param_1);
    return;
  case 9:
    do_command_destroy_group(this,(RGE_Command_Destroy_Group *)param_1);
    return;
  case 10:
    do_command_ai_order(this,(RGE_Command_AI_Order *)param_1);
    return;
  case 0xb:
    do_command_resign(this,(RGE_Command_Resign *)param_1);
    return;
  case 0xc:
    do_command_add_waypoint(this,(RGE_Command_Add_Waypoint *)param_1);
    return;
  case 0xe:
    do_command_add_to_group(this,(RGE_Command_Add_To_Group *)param_1);
    return;
  case 0xf:
    do_command_remove_from_group(this,(RGE_Command_Remove_From_Group *)param_1);
    break;
  case 0x10:
    do_command_group_waypoint(this,(RGE_Command_Group_Waypoint *)param_1);
    return;
  case 0x11:
    do_command_group_ai_order(this,(RGE_Command_Group_AI_Order *)param_1);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_order
// Address: 00433f20
void __thiscall RGE_Command::do_command_order(RGE_Command *this,RGE_Command_Order *param_1)
{
  byte bVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  float fVar4;
  RGE_Obj_Info *pRVar5;
  float fVar6;
  RGE_Command_Order *pRVar7;
  RGE_Command_Order *pRVar8;
  int unaff_retaddr;
  RGE_Command *pRVar9;
  float adjustedYLocation;
  float adjustedXLocation;
  int unit_num;
  float totalX;
  float totalY;
  float maxY;
  int i;
  RGE_Obj_Info *units;
  RGE_Static_Object *target;
  
  bVar1 = param_1->unit_num;
  fVar4 = (float)(uint)bVar1;
  pRVar7 = param_1 + 1;
  get_obj(this,(RGE_Obj_Info)(param_1->target).id);
  if (1 < bVar1) {
    adjustedXLocation = 10000.0;
    unit_num = 0;
    units = (RGE_Obj_Info *)0x461c4000;
    i = 0;
    totalY = 0.0;
    pRVar8 = pRVar7;
    for (fVar6 = fVar4; fVar6 != 0.0; fVar6 = (float)((int)fVar6 + -1)) {
      pRVar3 = get_obj(this,(RGE_Obj_Info)*(long *)pRVar8);
      if (pRVar3 != (RGE_Static_Object *)0x0) {
        if (adjustedXLocation <= pRVar3->world_x) {
          if ((float)unit_num < pRVar3->world_x) {
            unit_num = (int)pRVar3->world_x;
          }
        }
        else {
          adjustedXLocation = pRVar3->world_x;
        }
        if ((float)units <= pRVar3->world_y) {
          if ((float)i < pRVar3->world_y) {
            i = (int)pRVar3->world_y;
          }
        }
        else {
          units = (RGE_Obj_Info *)pRVar3->world_y;
        }
        totalY = totalY + pRVar3->world_x;
      }
      pRVar8 = (RGE_Command_Order *)&pRVar8->target;
    }
    if (((float)unit_num - adjustedXLocation <= (float)_DAT_0056f4d8) &&
       ((float)i - (float)units <= (float)_DAT_0056f4d8)) {
      units = (RGE_Obj_Info *)0x0;
      if (fVar4 == 0.0) {
        return;
      }
      do {
        pRVar3 = get_obj(this,(RGE_Obj_Info)*(long *)pRVar7);
        if (pRVar3 != (RGE_Static_Object *)0x0) {
          RGE_Static_Object::removeAllFromPathingGroup(pRVar3);
          iVar2 = pRVar3->_padding_;
          (**(code **)(iVar2 + 300))(1);
          pRVar8 = (RGE_Command_Order *)0x0;
          pRVar5 = units;
          do {
            if (pRVar8 != pRVar7) {
              RGE_Static_Object::addToPathingGroup(pRVar3,pRVar5->id);
            }
            pRVar8 = (RGE_Command_Order *)&pRVar8->field_0x1;
            pRVar5 = pRVar5 + 1;
          } while ((int)pRVar8 < unit_num);
          adjustedXLocation = (pRVar3->world_x - fVar4) + *(float *)(unaff_retaddr + 0xc);
          adjustedYLocation =
               (pRVar3->world_y - totalY / (float)(int)fVar4) + *(float *)(unaff_retaddr + 0x10);
          if ((float)_DAT_0056f4e0 <= adjustedXLocation) {
            fVar6 = (float)pRVar3->owner->world->map->map_width;
            if (fVar6 <= adjustedXLocation) {
              adjustedXLocation = fVar6 - _DAT_0056f4e8;
            }
          }
          else {
            adjustedXLocation = 1.0;
          }
          if ((float)_DAT_0056f4e0 <= adjustedYLocation) {
            fVar6 = (float)pRVar3->owner->world->map->map_height;
            if (fVar6 <= adjustedYLocation) {
              adjustedYLocation = fVar6 - _DAT_0056f4e8;
            }
          }
          else {
            adjustedYLocation = 1.0;
          }
          if ((this == (RGE_Command *)0x0) ||
             ((pRVar9 = this, *(float *)(this->last_order + 0x30) <= (float)_DAT_0056f4e0 &&
              (*(float *)(this->last_order + 0x34) <= (float)_DAT_0056f4e0)))) {
            pRVar9 = (RGE_Command *)0x0;
          }
          (**(code **)(iVar2 + 0x98))(pRVar9,adjustedXLocation,adjustedYLocation,0);
        }
        units = (RGE_Obj_Info *)((int)&units->id + 1);
        pRVar7 = (RGE_Command_Order *)&pRVar7->target;
      } while ((int)units < (int)fVar4);
      return;
    }
  }
  units = (RGE_Obj_Info *)0x0;
  if (fVar4 != 0.0) {
    do {
      pRVar3 = get_obj(this,(RGE_Obj_Info)*(long *)pRVar7);
      if (pRVar3 != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(pRVar3);
        iVar2 = pRVar3->_padding_;
        (**(code **)(iVar2 + 300))(1);
        pRVar8 = (RGE_Command_Order *)0x0;
        pRVar5 = units;
        do {
          if (pRVar8 != pRVar7) {
            RGE_Static_Object::addToPathingGroup(pRVar3,pRVar5->id);
          }
          pRVar8 = (RGE_Command_Order *)&pRVar8->field_0x1;
          pRVar5 = pRVar5 + 1;
        } while ((int)pRVar8 < unit_num);
        (**(code **)(iVar2 + 0x98))
                  (this,*(undefined4 *)(unaff_retaddr + 0xc),*(undefined4 *)(unaff_retaddr + 0x10),0
                  );
      }
      units = (RGE_Obj_Info *)((int)&units->id + 1);
      pRVar7 = (RGE_Command_Order *)&pRVar7->target;
    } while ((int)units < (int)fVar4);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_stop
// Address: 00434290
void __thiscall RGE_Command::do_command_stop(RGE_Command *this,RGE_Command_Stop *param_1)
{
  RGE_Static_Object *this_00;
  uint uVar1;
  RGE_Command_Stop *pRVar2;
  
  pRVar2 = param_1 + 1;
  for (uVar1 = (uint)param_1->unit_num; uVar1 != 0; uVar1 = uVar1 - 1) {
    this_00 = get_obj(this,(RGE_Obj_Info)*(long *)pRVar2);
    if (this_00 != (RGE_Static_Object *)0x0) {
      RGE_Static_Object::removeAllFromPathingGroup(this_00);
      (**(code **)(this_00->_padding_ + 0xa4))();
    }
    pRVar2 = pRVar2 + 2;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_pause
// Address: 004342e0
void __thiscall RGE_Command::do_command_pause(RGE_Command *this,RGE_Command_Pause *param_1)
{
  RGE_Static_Object *pRVar1;
  uint uVar2;
  RGE_Command_Pause *pRVar3;
  
  pRVar3 = param_1 + 1;
  for (uVar2 = (uint)param_1->unit_num; uVar2 != 0; uVar2 = uVar2 - 1) {
    pRVar1 = get_obj(this,(RGE_Obj_Info)*(long *)pRVar3);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 400))();
    }
    pRVar3 = pRVar3 + 2;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_work
// Address: 00434320
void __thiscall RGE_Command::do_command_work(RGE_Command *this,RGE_Command_Order *param_1)
{
  int iVar1;
  RGE_Static_Object *this_00;
  uint uVar2;
  int unaff_EBX;
  RGE_Command_Order *pRVar3;
  int iVar4;
  int unaff_retaddr;
  int index;
  int local_18;
  int unit_num;
  RGE_Static_Object *target;
  RGE_Obj_Info *units;
  
  uVar2 = (uint)param_1->unit_num;
  get_obj(this,(RGE_Obj_Info)(param_1->target).id);
  local_18 = 0;
  unit_num = (int)(param_1 + 1);
  if (uVar2 != 0) {
    do {
      this_00 = get_obj(this,(RGE_Obj_Info)*(long *)unit_num);
      if (this_00 != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(this_00);
        iVar1 = this_00->_padding_;
        (**(code **)(iVar1 + 300))(1);
        iVar4 = 0;
        pRVar3 = param_1 + 1;
        do {
          if (iVar4 != unaff_EBX) {
            RGE_Static_Object::addToPathingGroup(this_00,*(int *)pRVar3);
          }
          iVar4 = iVar4 + 1;
          pRVar3 = (RGE_Command_Order *)&pRVar3->target;
        } while (iVar4 < unit_num);
        (**(code **)(iVar1 + 0xa0))
                  (uVar2,*(undefined4 *)(unaff_retaddr + 0xc),*(undefined4 *)(unaff_retaddr + 0x10),
                   0);
      }
      local_18 = local_18 + 1;
      unit_num = unit_num + 4;
    } while (local_18 < (int)uVar2);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_move
// Address: 00434400
void __thiscall RGE_Command::do_command_move(RGE_Command *this,RGE_Command_Order *param_1)
{
  RGE_Command_Order *pRVar1;
  byte bVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Static_Object *pRVar4;
  RGE_Static_Object *pRVar5;
  UnitAIModule *pUVar6;
  float fVar7;
  RGE_Obj_Info *pRVar8;
  RGE_Command_Order *pRVar9;
  float fVar10;
  int iVar11;
  int unaff_retaddr;
  float fVar12;
  long lVar13;
  int iVar14;
  float fVar15;
  float adjustedYLocation;
  float adjustedXLocation;
  int unit_num;
  float totalX;
  float totalY;
  RGE_Static_Object *target;
  float maxY;
  int i;
  RGE_Obj_Info *units;
  
  bVar2 = param_1->unit_num;
  fVar7 = (float)(uint)bVar2;
  pRVar1 = param_1 + 1;
  pRVar4 = get_obj(this,(RGE_Obj_Info)(param_1->target).id);
  if (1 < bVar2) {
    adjustedXLocation = 10000.0;
    unit_num = 0;
    units = (RGE_Obj_Info *)0x461c4000;
    i = 0;
    totalY = 0.0;
    target = (RGE_Static_Object *)0x0;
    pRVar9 = pRVar1;
    for (fVar10 = fVar7; fVar10 != 0.0; fVar10 = (float)((int)fVar10 + -1)) {
      pRVar5 = get_obj(this,(RGE_Obj_Info)*(long *)pRVar9);
      if (pRVar5 != (RGE_Static_Object *)0x0) {
        if (adjustedXLocation <= pRVar5->world_x) {
          if ((float)unit_num < pRVar5->world_x) {
            unit_num = (int)pRVar5->world_x;
          }
        }
        else {
          adjustedXLocation = pRVar5->world_x;
        }
        if ((float)units <= pRVar5->world_y) {
          if ((float)i < pRVar5->world_y) {
            i = (int)pRVar5->world_y;
          }
        }
        else {
          units = (RGE_Obj_Info *)pRVar5->world_y;
        }
        totalY = totalY + pRVar5->world_x;
        target = (RGE_Static_Object *)((float)target + pRVar5->world_y);
      }
      pRVar9 = (RGE_Command_Order *)&pRVar9->target;
    }
    if (((float)unit_num - adjustedXLocation <= (float)_DAT_0056f4d8) &&
       ((float)i - (float)units <= (float)_DAT_0056f4d8)) {
      units = (RGE_Obj_Info *)0x0;
      fVar10 = (float)target / (float)(int)fVar7;
      i = (int)pRVar1;
      if (fVar7 == 0.0) {
        return;
      }
      do {
        pRVar5 = get_obj(this,(RGE_Obj_Info)*(long *)i);
        if (pRVar5 != (RGE_Static_Object *)0x0) {
          RGE_Static_Object::removeAllFromPathingGroup(pRVar5);
          iVar14 = pRVar5->_padding_;
          (**(code **)(iVar14 + 300))(1);
          iVar11 = 0;
          pRVar8 = units;
          do {
            if (iVar11 != i) {
              RGE_Static_Object::addToPathingGroup(pRVar5,pRVar8->id);
            }
            iVar11 = iVar11 + 1;
            pRVar8 = pRVar8 + 1;
          } while (iVar11 < unit_num);
          adjustedXLocation = (pRVar5->world_x - fVar7) + *(float *)(unaff_retaddr + 0xc);
          adjustedYLocation =
               (pRVar5->world_y - totalY / (float)(int)fVar7) + *(float *)(unaff_retaddr + 0x10);
          if ((float)_DAT_0056f4e0 <= adjustedXLocation) {
            fVar12 = (float)pRVar5->owner->world->map->map_width;
            if (fVar12 <= adjustedXLocation) {
              adjustedXLocation = fVar12 - _DAT_0056f4e8;
            }
          }
          else {
            adjustedXLocation = 1.0;
          }
          if ((float)_DAT_0056f4e0 <= adjustedYLocation) {
            fVar12 = (float)pRVar5->owner->world->map->map_height;
            if (fVar12 <= adjustedYLocation) {
              adjustedYLocation = fVar12 - _DAT_0056f4e8;
            }
          }
          else {
            adjustedYLocation = 1.0;
          }
          if ((fVar10 == 0.0) ||
             ((fVar12 = fVar10, *(float *)(*(int *)((int)fVar10 + 8) + 0x30) <= (float)_DAT_0056f4e0
              && (*(float *)(*(int *)((int)fVar10 + 8) + 0x34) <= (float)_DAT_0056f4e0)))) {
            fVar12 = 0.0;
          }
          (**(code **)(iVar14 + 0x9c))(fVar12,adjustedXLocation,adjustedYLocation,0);
          pUVar6 = RGE_Static_Object::unitAI(pRVar5);
          if (pUVar6 != (UnitAIModule *)0x0) {
            iVar14 = 0x2c6;
            pUVar6 = RGE_Static_Object::unitAI(pRVar5);
            UnitAIModule::setCurrentOrder(pUVar6,iVar14);
            iVar14 = 0x262;
            pUVar6 = RGE_Static_Object::unitAI(pRVar5);
            UnitAIModule::setCurrentAction(pUVar6,iVar14);
            if ((pRVar4 == (RGE_Static_Object *)0x0) ||
               ((pRVar3 = pRVar4->master_obj, pRVar3->radius_x <= (float)_DAT_0056f4e0 &&
                (pRVar3->radius_y <= (float)_DAT_0056f4e0)))) {
              iVar14 = -1;
              lVar13 = -1;
            }
            else {
              iVar14 = (int)pRVar3->object_group;
              lVar13 = pRVar4->id;
            }
            fVar12 = 0.0;
            pUVar6 = RGE_Static_Object::unitAI(pRVar5);
            UnitAIModule::setCurrentTarget
                      (pUVar6,lVar13,iVar14,adjustedXLocation,adjustedYLocation,fVar12);
          }
        }
        units = (RGE_Obj_Info *)((int)&units->id + 1);
        i = i + 4;
      } while ((int)units < (int)fVar7);
      return;
    }
  }
  units = (RGE_Obj_Info *)0x0;
  i = (int)pRVar1;
  if (fVar7 != 0.0) {
    do {
      pRVar5 = get_obj(this,(RGE_Obj_Info)*(long *)i);
      if (pRVar5 != (RGE_Static_Object *)0x0) {
        RGE_Static_Object::removeAllFromPathingGroup(pRVar5);
        iVar14 = pRVar5->_padding_;
        (**(code **)(iVar14 + 300))(1);
        iVar11 = 0;
        pRVar9 = pRVar1;
        do {
          if (iVar11 != i) {
            RGE_Static_Object::addToPathingGroup(pRVar5,*(int *)pRVar9);
          }
          iVar11 = iVar11 + 1;
          pRVar9 = (RGE_Command_Order *)&pRVar9->target;
        } while (iVar11 < unit_num);
        (**(code **)(iVar14 + 0x9c))
                  (target,*(undefined4 *)(unaff_retaddr + 0xc),*(undefined4 *)(unaff_retaddr + 0x10)
                   ,0);
        pUVar6 = RGE_Static_Object::unitAI(pRVar5);
        if (pUVar6 != (UnitAIModule *)0x0) {
          iVar14 = 0x2c6;
          pUVar6 = RGE_Static_Object::unitAI(pRVar5);
          UnitAIModule::setCurrentOrder(pUVar6,iVar14);
          iVar14 = 0x262;
          pUVar6 = RGE_Static_Object::unitAI(pRVar5);
          UnitAIModule::setCurrentAction(pUVar6,iVar14);
          if ((pRVar4 == (RGE_Static_Object *)0x0) ||
             ((pRVar3 = pRVar4->master_obj, pRVar3->radius_x <= (float)_DAT_0056f4e0 &&
              (pRVar3->radius_y <= (float)_DAT_0056f4e0)))) {
            fVar10 = param_1->location_y;
            fVar12 = param_1->location_x;
            iVar14 = -1;
            lVar13 = -1;
          }
          else {
            iVar14 = (int)pRVar3->object_group;
            fVar10 = param_1->location_y;
            fVar12 = param_1->location_x;
            lVar13 = pRVar4->id;
          }
          fVar15 = 0.0;
          pUVar6 = RGE_Static_Object::unitAI(pRVar5);
          UnitAIModule::setCurrentTarget(pUVar6,lVar13,iVar14,fVar12,fVar10,fVar15);
        }
      }
      units = (RGE_Obj_Info *)((int)&units->id + 1);
      i = i + 4;
    } while ((int)units < (int)fVar7);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_create
// Address: 004348b0
void __thiscall RGE_Command::do_command_create(RGE_Command *this,RGE_Command_Create *param_1)
{
  RGE_Player *pRVar1;
  
  pRVar1 = this->world->players[param_1->player_id];
  (**(code **)(pRVar1->master_objects[param_1->obj_catagory]->_padding_ + 0x18))
            (pRVar1,param_1->location_x,param_1->location_y,param_1->location_z);
  return;
}

// --------------------------------------------------

// Function: do_command_add_attribute
// Address: 004348f0
void __thiscall
RGE_Command::do_command_add_attribute(RGE_Command *this,RGE_Command_Add_Attribute *param_1)
{
  (**(code **)(this->world->players[param_1->player_id]->_padding_ + 0x78))
            (param_1->attr_id,param_1->attr_amount,0);
  return;
}

// --------------------------------------------------

// Function: do_command_give_attribute
// Address: 00434920
void __thiscall
RGE_Command::do_command_give_attribute(RGE_Command *this,RGE_Command_Give_Attribute *param_1)
{
  byte bVar1;
  RGE_Player **ppRVar2;
  RGE_Player *pRVar3;
  int iVar4;
  undefined4 uVar5;
  
  ppRVar2 = this->world->players;
  pRVar3 = ppRVar2[param_1->player_id];
  if (param_1->attr_amount <= pRVar3->attributes[param_1->attr_id]) {
    (**(code **)(pRVar3->_padding_ + 0x78))
              (CONCAT22((short)((uint)ppRVar2 >> 0x10),(ushort)param_1->attr_id),
               -param_1->attr_amount,0);
    (**(code **)(this->world->players[param_1->to_player_id]->_padding_ + 0x78))
              (CONCAT22((short)((uint)param_1->attr_amount >> 0x10),(ushort)param_1->attr_id),
               param_1->attr_amount,0);
    iVar4 = rge_base_game->_padding_;
    uVar5 = __ftol();
    (**(code **)(iVar4 + 0x40))(7,param_1->player_id,param_1->to_player_id,param_1->attr_id,uVar5);
    bVar1 = param_1->to_player_id;
    iVar4 = this->world->players[bVar1]->_padding_;
    uVar5 = __ftol(0);
    (**(code **)(iVar4 + 0xe8))(param_1->player_id,(uint)bVar1,0x20a,param_1->attr_id,uVar5);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_formation
// Address: 00434a00
void __thiscall RGE_Command::do_command_formation(RGE_Command *this,RGE_Command_Formation *param_1)
{
  RGE_Command_Formation *pRVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  RGE_Static_Object *pRVar5;
  RGE_Command_Formation *pRVar6;
  int iVar7;
  int iVar8;
  RGE_Command_Formation *pRVar9;
  float tempY;
  float tempX;
  float adjustedYLocation;
  float adjustedXLocation;
  int tempCount;
  RGE_Static_Object *referenceUnit;
  int unitNum;
  int i;
  int local_10;
  RGE_Obj_Info *units;
  float distance;
  float local_4;
  
  iVar2 = param_1->unitNum;
  pRVar1 = param_1 + 1;
  if (1 < iVar2) {
    iVar7 = 0;
    unitNum = 0;
    pRVar9 = pRVar1;
    if (0 < iVar2) {
      do {
        pRVar5 = get_obj(this,(RGE_Obj_Info)*(long *)pRVar9);
        if ((pRVar5 != (RGE_Static_Object *)0x0) &&
           ((fVar3 = SQRT(pRVar5->world_y * pRVar5->world_y + pRVar5->world_x * pRVar5->world_x),
            iVar7 == 0 || (fVar3 < local_4)))) {
          unitNum = (int)pRVar5;
          local_4 = fVar3;
        }
        iVar7 = iVar7 + 1;
        pRVar9 = (RGE_Command_Formation *)&pRVar9->unitNum;
      } while (iVar7 < iVar2);
    }
    adjustedYLocation = 1.0;
    tempX = 1.0;
    bVar4 = false;
    switch(param_1->formationID) {
    case 0:
      adjustedYLocation = 1.0;
      tempX = 1.0;
      break;
    case 1:
    case 4:
    case 5:
      adjustedYLocation = 1.5;
      tempX = 1.5;
      break;
    case 2:
    case 3:
      adjustedYLocation = 2.0;
      tempX = 2.0;
    }
    local_10 = 0;
    pRVar9 = pRVar1;
    if (0 < iVar2) {
      do {
        pRVar5 = get_obj(this,(RGE_Obj_Info)*(long *)pRVar9);
        if (pRVar5 != (RGE_Static_Object *)0x0) {
          RGE_Static_Object::removeAllFromPathingGroup(pRVar5);
          iVar7 = pRVar5->_padding_;
          (**(code **)(iVar7 + 300))(1);
          iVar8 = 0;
          pRVar6 = pRVar1;
          do {
            if (iVar8 != local_10) {
              RGE_Static_Object::addToPathingGroup(pRVar5,*(int *)pRVar6);
            }
            iVar8 = iVar8 + 1;
            pRVar6 = (RGE_Command_Formation *)&pRVar6->unitNum;
          } while (iVar8 < iVar2);
          if (pRVar5 != (RGE_Static_Object *)unitNum) {
            tempCount = *(int *)(unitNum + 0x38);
            adjustedXLocation = *(float *)(unitNum + 0x3c);
            switch(param_1->formationID) {
            case 0:
              tempCount = (int)((float)tempCount + adjustedYLocation);
              adjustedYLocation = adjustedYLocation - _DAT_0056f4f4;
              adjustedXLocation = adjustedXLocation + tempX;
              tempX = tempX - _DAT_0056f4f4;
              break;
            case 1:
              tempCount = (int)((float)tempCount + adjustedYLocation);
              adjustedYLocation = adjustedYLocation - _DAT_0056f4f8;
              adjustedXLocation = adjustedXLocation - tempX;
              tempX = tempX - _DAT_0056f4f8;
              break;
            case 2:
              tempCount = (int)((float)tempCount + adjustedYLocation);
              fVar3 = _DAT_0056f4fc;
LAB_00434cc0:
              adjustedYLocation = adjustedYLocation - fVar3;
              break;
            case 3:
              adjustedXLocation = adjustedXLocation + tempX;
              tempX = tempX - _DAT_0056f4fc;
              break;
            case 4:
              tempCount = (int)((float)tempCount + adjustedYLocation);
              if (bVar4) {
LAB_00434c8e:
                adjustedXLocation = adjustedXLocation + tempX;
                tempX = tempX - _DAT_0056f4f8;
                bVar4 = false;
                fVar3 = _DAT_0056f4f8;
                goto LAB_00434cc0;
              }
              adjustedXLocation = adjustedXLocation - tempX;
              bVar4 = true;
              break;
            case 5:
              tempCount = (int)((float)tempCount - adjustedYLocation);
              if (bVar4) goto LAB_00434c8e;
              adjustedXLocation = adjustedXLocation - tempX;
              bVar4 = true;
            }
            (**(code **)(iVar7 + 0x9c))(0,tempCount,adjustedXLocation,0x3f800000);
          }
        }
        local_10 = local_10 + 1;
        pRVar9 = (RGE_Command_Formation *)&pRVar9->unitNum;
      } while (local_10 < iVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: do_command_ai_order
// Address: 00434d40
void __thiscall RGE_Command::do_command_ai_order(RGE_Command *this,RGE_Command_AI_Order *param_1)
{
  RGE_Static_Object *this_00;
  
  this_00 = RGE_Game_World::object(this->world,param_1->recipient);
  if (this_00 != (RGE_Static_Object *)0x0) {
    RGE_Static_Object::removeAllFromPathingGroup(this_00);
    (**(code **)(this->world->players[param_1->player_id]->_padding_ + 0x34))
              (param_1->issuer,param_1->recipient,(int)param_1->orderType,param_1->target,
               param_1->targetOwner,param_1->targetX,param_1->targetY,param_1->targetZ,
               param_1->range,param_1->immediate,param_1->inFront,param_1->orderPriority);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_group_ai_order
// Address: 00434dc0
void __thiscall
RGE_Command::do_command_group_ai_order(RGE_Command *this,RGE_Command_Group_AI_Order *param_1)
{
  RGE_Obj_Info RVar1;
  RGE_Command_Group_AI_Order *pRVar2;
  RGE_Static_Object *this_00;
  uint uVar3;
  RGE_Command_Group_AI_Order *pRVar4;
  float targetY;
  float targetX;
  float local_8;
  
  pRVar2 = param_1;
  pRVar4 = param_1 + 1;
  for (uVar3 = (uint)param_1->recipient_count; uVar3 != 0; uVar3 = uVar3 - 1) {
    RVar1.id._0_1_ = pRVar4->command;
    RVar1.id._1_1_ = pRVar4->player_id;
    RVar1.id._2_1_ = pRVar4->issuer;
    RVar1.id._3_1_ = pRVar4->recipient_count;
    this_00 = get_obj(this,RVar1);
    if (this_00 != (RGE_Static_Object *)0x0) {
      local_8 = pRVar2->targetX;
      if (local_8 == -1.0) {
        local_8 = this_00->world_x;
      }
      targetX = pRVar2->targetY;
      if (targetX == -1.0) {
        targetX = this_00->world_y;
      }
      param_1 = (RGE_Command_Group_AI_Order *)pRVar2->targetZ;
      if (param_1 == (RGE_Command_Group_AI_Order *)0xbf800000) {
        param_1 = (RGE_Command_Group_AI_Order *)this_00->world_z;
      }
      RGE_Static_Object::removeAllFromPathingGroup(this_00);
      (**(code **)(this->world->players[pRVar2->player_id]->_padding_ + 0x34))
                (pRVar2->issuer,this_00->id,(int)pRVar2->orderType,pRVar2->target,
                 pRVar2->targetOwner,local_8,targetX,param_1,pRVar2->range,pRVar2->immediate,
                 pRVar2->inFront,pRVar2->orderPriority);
    }
    pRVar4 = (RGE_Command_Group_AI_Order *)&pRVar4->orderType;
  }
  return;
}

// --------------------------------------------------

// Function: do_command_resign
// Address: 00434eb0
void __thiscall RGE_Command::do_command_resign(RGE_Command *this,RGE_Command_Resign *param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar1 == 0) {
    (**(code **)(this->world->players[param_1->player_id]->_padding_ + 8))(param_1->dropped);
  }
  else {
    iVar4 = 0;
    iVar1 = 0;
    iVar3 = 1;
    rge_base_game->resigned[param_1->comm_player_id] = '\x01';
    do {
      uVar2 = RGE_Base_Game::playerID(rge_base_game,iVar3);
      if ((uVar2 == param_1->player_id) &&
         (iVar4 = iVar4 + 1, rge_base_game->resigned[iVar3] != '\0')) {
        iVar1 = iVar1 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 9);
    if (iVar4 == iVar1) {
      (**(code **)(this->world->players[param_1->player_id]->_padding_ + 8))(param_1->dropped);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: do_command_add_waypoint
// Address: 00434f70
void __thiscall
RGE_Command::do_command_add_waypoint(RGE_Command *this,RGE_Command_Add_Waypoint *param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = RGE_Game_World::object(this->world,param_1->recipient);
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    (**(code **)(this->world->players[param_1->player_id]->_padding_ + 0x48))
              (param_1->recipient,param_1->waypoint,param_1->numberWaypoints);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_group_waypoint
// Address: 00434fb0
void __thiscall
RGE_Command::do_command_group_waypoint(RGE_Command *this,RGE_Command_Group_Waypoint *param_1)
{
  ushort uVar1;
  RGE_Command_Group_Waypoint *pRVar2;
  RGE_Static_Object *pRVar3;
  uint uVar4;
  RGE_Command_Group_Waypoint *pRVar5;
  
  pRVar2 = param_1;
  pRVar5 = param_1;
  for (uVar4 = (uint)param_1->unit_num; uVar4 != 0; uVar4 = uVar4 - 1) {
    pRVar5 = pRVar5 + 1;
    pRVar3 = get_obj(this,(RGE_Obj_Info)*pRVar5);
    if (pRVar3 != (RGE_Static_Object *)0x0) {
      uVar1._0_1_ = pRVar2->x;
      uVar1._1_1_ = pRVar2->y;
      param_1._0_3_ = (uint3)uVar1;
      (**(code **)(pRVar3->owner->_padding_ + 0x48))(pRVar3->id,&param_1,1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: do_command_create_group
// Address: 00435020
void __thiscall
RGE_Command::do_command_create_group(RGE_Command *this,RGE_Command_Create_Group *param_1)
{
  RGE_Static_Object *this_00;
  
  this_00 = RGE_Game_World::object(this->world,param_1->groupCommander);
  if ((this_00 != (RGE_Static_Object *)0x0) && (this_00->owner->id == (ushort)param_1->player_id)) {
    RGE_Static_Object::commanderCreateGroup
              (this_00,param_1->unitsToGroup,(uint)param_1->numberUnitsToGroup,
               param_1->groupCommander,param_1->groupRange);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_add_to_group
// Address: 00435060
void __thiscall
RGE_Command::do_command_add_to_group(RGE_Command *this,RGE_Command_Add_To_Group *param_1)
{
  RGE_Static_Object *this_00;
  
  this_00 = RGE_Game_World::object(this->world,param_1->groupCommander);
  if ((this_00 != (RGE_Static_Object *)0x0) && (this_00->owner->id == (ushort)param_1->player_id)) {
    RGE_Static_Object::commanderAddToGroup(this_00,param_1->newUnit,param_1->groupRange);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_remove_from_group
// Address: 004350a0
void __thiscall
RGE_Command::do_command_remove_from_group(RGE_Command *this,RGE_Command_Remove_From_Group *param_1)
{
  RGE_Static_Object *this_00;
  
  this_00 = RGE_Game_World::object(this->world,param_1->groupCommander);
  if ((this_00 != (RGE_Static_Object *)0x0) && (this_00->owner->id == (ushort)param_1->player_id)) {
    RGE_Static_Object::commanderRemoveFromGroup(this_00,param_1->unit);
  }
  return;
}

// --------------------------------------------------

// Function: do_command_destroy_group
// Address: 004350e0
void __thiscall
RGE_Command::do_command_destroy_group(RGE_Command *this,RGE_Command_Destroy_Group *param_1)
{
  RGE_Static_Object *this_00;
  
  this_00 = RGE_Game_World::object(this->world,param_1->groupCommander);
  if ((this_00 != (RGE_Static_Object *)0x0) && (this_00->owner->id == (ushort)param_1->player_id)) {
    RGE_Static_Object::commanderDestroyGroup(this_00);
  }
  return;
}

// --------------------------------------------------

// Function: duplicate_check_command_order
// Address: 00435110
uchar __thiscall
RGE_Command::duplicate_check_command_order(RGE_Command *this,RGE_Command_Order *param_1)
{
  uchar *puVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  RGE_Command_Order *pRVar6;
  int iVar7;
  RGE_Obj_Info *last_units;
  
  puVar1 = this->last_order;
  uVar5 = (uint)param_1->unit_num;
  pRVar6 = param_1 + 1;
  if (uVar5 == puVar1[8]) {
    sVar3 = __ftol();
    sVar4 = __ftol();
    if (sVar4 == sVar3) {
      sVar3 = __ftol();
      sVar4 = __ftol();
      if ((sVar4 == sVar3) && (*(int *)(puVar1 + 4) == (param_1->target).id)) {
        iVar7 = 0;
        if (uVar5 != 0) {
          iVar2 = 0x14 - (int)pRVar6;
          do {
            if (*(int *)pRVar6 != *(int *)(puVar1 + iVar2 + (int)pRVar6)) {
              return '\0';
            }
            iVar7 = iVar7 + 1;
            pRVar6 = (RGE_Command_Order *)&pRVar6->target;
          } while (iVar7 < (int)uVar5);
        }
        return '\x01';
      }
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: duplicate_check_command_stop
// Address: 004351b0
uchar __thiscall
RGE_Command::duplicate_check_command_stop(RGE_Command *this,RGE_Command_Stop *param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1->unit_num;
  piVar2 = (int *)(this->last_order + 2);
  if (uVar4 != this->last_order[1]) {
    return '\0';
  }
  iVar3 = 0;
  if (uVar4 != 0) {
    iVar1 = 2 - (int)piVar2;
    do {
      if (*(int *)((int)param_1 + iVar1 + (int)piVar2) != *piVar2) {
        return '\0';
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < (int)uVar4);
    return '\x01';
  }
  return '\x01';
}

// --------------------------------------------------

// Function: close_check_for_duplicate_orders
// Address: 00435210
uchar __thiscall RGE_Command::close_check_for_duplicate_orders(RGE_Command *this,uchar *param_1)
{
  uchar uVar1;
  
  switch(*param_1) {
  case '\0':
  case '\x02':
  case '\x03':
    uVar1 = duplicate_check_command_order(this,(RGE_Command_Order *)param_1);
    if (uVar1 != '\0') {
      return '\x01';
    }
    break;
  case '\x01':
    uVar1 = duplicate_check_command_stop(this,(RGE_Command_Stop *)param_1);
    if (uVar1 != '\0') {
      return '\x01';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: check_for_duplicate_orders
// Address: 00435260
// [HELPER] s_C__msdev_work_age1_x1_Command_cp: "C:\msdev\work\age1_x1\Command.cpp"
uchar __thiscall
RGE_Command::check_for_duplicate_orders(RGE_Command *this,uchar *param_1,long param_2)
{
  uchar uVar1;
  ulong uVar2;
  
  if (((this->last_order != (uchar *)0x0) && (this->last_order_size == param_2)) &&
     (*this->last_order == *param_1)) {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Command_cp,0x497);
    if ((int)(uVar2 - this->last_order_time) < 500) {
      uVar1 = close_check_for_duplicate_orders(this,param_1);
      return uVar1;
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: submit
// Address: 004352c0
// [HELPER] s_C__msdev_work_age1_x1_Command_cp: "C:\msdev\work\age1_x1\Command.cpp"
void __thiscall RGE_Command::submit(RGE_Command *this,void *param_1,long param_2)
{
  uchar uVar1;
  ulong uVar2;
  
  uVar1 = check_for_duplicate_orders(this,(uchar *)param_1,param_2);
  if (uVar1 == '\0') {
    TCommunications_Handler::new_command(this->com_hand,param_1,param_2);
  }
  if (this->last_order != (uchar *)0x0) {
    free(this->last_order);
  }
  this->last_order = (uchar *)param_1;
  this->last_order_size = param_2;
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Command_cp,0x4ac);
  this->last_order_time = uVar2;
  return;
}

// --------------------------------------------------

// Function: command_order
// Address: 00435320
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_order
          (RGE_Command *this,RGE_Static_Object **param_1,short param_2,RGE_Static_Object *param_3,
          float param_4,float param_5)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = (int)param_2;
  iVar1 = iVar9 * 4 + 0x14;
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 0x14);
    if (puVar4 != (undefined1 *)0x0) {
      if (0 < iVar9) {
        iVar7 = (int)param_1 - (int)puVar5;
        iVar10 = iVar9;
        do {
          iVar2 = *(int *)(iVar7 + (int)puVar5);
          if (iVar2 == 0) {
            *puVar5 = 0xffffffff;
          }
          else {
            *puVar5 = *(undefined4 *)(iVar2 + 4);
          }
          puVar5 = puVar5 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      if (param_3 == (RGE_Static_Object *)0x0) {
        *(undefined4 *)(puVar4 + 4) = 0xffffffff;
      }
      else {
        *(long *)(puVar4 + 4) = param_3->id;
      }
      *puVar4 = 0;
      puVar4[8] = (char)param_2;
      *(float *)(puVar4 + 0xc) = param_4;
      *(float *)(puVar4 + 0x10) = param_5;
      if (param_3 == (RGE_Static_Object *)0x0) {
        pcVar8 = s_X;
      }
      else {
        pcVar8 = param_3->master_obj->name;
      }
      pRVar3 = *param_1;
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        pcVar6 = s_X;
        iVar10 = -1;
      }
      else {
        pcVar6 = pRVar3->master_obj->name;
        iVar10 = (int)pRVar3->owner->id;
      }
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_ORDER__CNT__d_OW,iVar9,iVar10,pcVar6,pcVar8);
      submit(this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_stop
// Address: 00435420
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_stop(RGE_Command *this,RGE_Static_Object **param_1,short param_2)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char *this_00;
  int iVar6;
  int iVar7;
  int iVar8;
  long size;
  
  iVar7 = (int)param_2;
  iVar1 = iVar7 * 4 + 2;
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 2);
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
      *puVar4 = 1;
      puVar4[1] = (undefined1)param_2;
      pRVar3 = *param_1;
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        this_00 = s_X;
        iVar8 = -1;
      }
      else {
        this_00 = pRVar3->master_obj->name;
        iVar8 = (int)pRVar3->owner->id;
      }
      TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,s_______>SEND_CMD_STOP__CNT__d_OWN,iVar7
                         ,iVar8,this_00);
      submit(this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_stop
// Address: 004354f0
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall RGE_Command::command_stop(RGE_Command *this,int param_1,int *param_2,int param_3)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  RGE_Static_Object *pRVar4;
  char *pcVar5;
  int iVar6;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this_00;
  int iVar7;
  
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    iVar1 = param_3 * 4 + 2;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 2);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_3) {
        iVar6 = (int)param_2 - (int)puVar3;
        iVar7 = param_3;
        do {
          *puVar3 = *(undefined4 *)(iVar6 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *puVar2 = 1;
      puVar2[1] = (char)param_3;
      pRVar4 = RGE_Game_World::object(this->world,*param_2);
      if (pRVar4 == (RGE_Static_Object *)0x0) {
        pcVar5 = s_X;
        this_00 = extraout_ECX;
      }
      else {
        this_00 = (TDebuggingLog *)pRVar4->master_obj;
        pcVar5 = (char *)this_00->LogToFile;
      }
      TDebuggingLog::Log(this_00,(char *)L,s_______>SEND_CMD_STOP2__CNT__d_OW,param_3,param_1,pcVar5
                        );
      submit(this,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_pause
// Address: 004355a0
// [HELPER] s_______: "      "
void __thiscall RGE_Command::command_pause(RGE_Command *this,int param_1,int *param_2,int param_3)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this_00;
  int iVar4;
  
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    iVar1 = param_3 * 4 + 2;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 2);
    if (puVar2 != (undefined1 *)0x0) {
      this_00 = extraout_ECX;
      if (0 < param_3) {
        this_00 = (TDebuggingLog *)((int)param_2 - (int)puVar3);
        iVar4 = param_3;
        do {
          *puVar3 = *(undefined4 *)((int)puVar3 + (int)(this_00->TBuff + -0x28));
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      *puVar2 = 0xd;
      puVar2[1] = (char)param_3;
      TDebuggingLog::Log(this_00,(char *)L,s_______>SEND_CMD_PAUSE);
      submit(this,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_work
// Address: 00435620
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_work
          (RGE_Command *this,RGE_Static_Object **param_1,short param_2,RGE_Static_Object *param_3,
          float param_4,float param_5)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = (int)param_2;
  iVar1 = iVar9 * 4 + 0x14;
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 0x14);
    if (puVar4 != (undefined1 *)0x0) {
      if (0 < iVar9) {
        iVar7 = (int)param_1 - (int)puVar5;
        iVar10 = iVar9;
        do {
          iVar2 = *(int *)(iVar7 + (int)puVar5);
          if (iVar2 == 0) {
            *puVar5 = 0xffffffff;
          }
          else {
            *puVar5 = *(undefined4 *)(iVar2 + 4);
          }
          puVar5 = puVar5 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      if (param_3 == (RGE_Static_Object *)0x0) {
        *(undefined4 *)(puVar4 + 4) = 0xffffffff;
      }
      else {
        *(long *)(puVar4 + 4) = param_3->id;
      }
      *puVar4 = 2;
      puVar4[8] = (char)param_2;
      *(float *)(puVar4 + 0xc) = param_4;
      *(float *)(puVar4 + 0x10) = param_5;
      if (param_3 == (RGE_Static_Object *)0x0) {
        pcVar8 = s_X;
      }
      else {
        pcVar8 = param_3->master_obj->name;
      }
      pRVar3 = *param_1;
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        pcVar6 = s_X;
        iVar10 = -1;
      }
      else {
        pcVar6 = pRVar3->master_obj->name;
        iVar10 = (int)pRVar3->owner->id;
      }
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_WORK__CNT__d_OWN,iVar9,iVar10,pcVar6,pcVar8);
      submit(this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_work
// Address: 00435720
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_work
          (RGE_Command *this,int param_1,int *param_2,int param_3,int param_4,int param_5,
          float param_6,float param_7)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  RGE_Static_Object *pRVar4;
  RGE_Static_Object *pRVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    iVar1 = param_3 * 4 + 0x14;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 0x14);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_3) {
        iVar7 = (int)param_2 - (int)puVar3;
        iVar9 = param_3;
        do {
          *puVar3 = *(undefined4 *)(iVar7 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      *(float *)(puVar2 + 0xc) = param_6;
      *puVar2 = 2;
      puVar2[8] = (char)param_3;
      *(int *)(puVar2 + 4) = param_4;
      *(float *)(puVar2 + 0x10) = param_7;
      pRVar4 = RGE_Game_World::object(this->world,*param_2);
      pRVar5 = RGE_Game_World::object(this->world,param_4);
      if (pRVar5 == (RGE_Static_Object *)0x0) {
        pcVar8 = s_X;
      }
      else {
        pcVar8 = pRVar5->master_obj->name;
      }
      if (pRVar4 == (RGE_Static_Object *)0x0) {
        pcVar6 = s_X;
      }
      else {
        pcVar6 = pRVar4->master_obj->name;
      }
      TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_WORK2__CNT__d_OW,param_3,param_1,pcVar6,
                         pcVar8);
      submit(this,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_move
// Address: 00435810
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_move
          (RGE_Command *this,RGE_Static_Object **param_1,short param_2,RGE_Static_Object *param_3,
          float param_4,float param_5)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char *this_00;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    iVar7 = (int)param_2;
    iVar1 = iVar7 * 4 + 0x14;
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 0x14);
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
      if (param_3 == (RGE_Static_Object *)0x0) {
        *(undefined4 *)(puVar4 + 4) = 0xffffffff;
      }
      else {
        *(long *)(puVar4 + 4) = param_3->id;
      }
      *puVar4 = 3;
      puVar4[8] = (char)param_2;
      *(float *)(puVar4 + 0xc) = param_4;
      *(float *)(puVar4 + 0x10) = param_5;
      pRVar3 = *param_1;
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        this_00 = s_X;
        iVar8 = -1;
      }
      else {
        this_00 = pRVar3->master_obj->name;
        iVar8 = (int)pRVar3->owner->id;
      }
      TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,s_______>SEND_CMD_MOVE__CNT__d_OWN,iVar7
                         ,iVar8,this_00);
      submit(this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_move
// Address: 00435900
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_move
          (RGE_Command *this,int param_1,int *param_2,int param_3,int param_4,int param_5,
          float param_6,float param_7)
{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  RGE_Static_Object *pRVar4;
  char *pcVar5;
  int iVar6;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this_00;
  int iVar7;
  
  if ((param_2 != (int *)0x0) && (0 < param_3)) {
    iVar1 = param_3 * 4 + 0x14;
    puVar2 = (undefined1 *)calloc(1,iVar1);
    puVar3 = (undefined4 *)(puVar2 + 0x14);
    if (puVar2 != (undefined1 *)0x0) {
      if (0 < param_3) {
        iVar6 = (int)param_2 - (int)puVar3;
        iVar7 = param_3;
        do {
          *puVar3 = *(undefined4 *)(iVar6 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *puVar2 = 3;
      puVar2[8] = (char)param_3;
      *(int *)(puVar2 + 4) = param_4;
      *(float *)(puVar2 + 0xc) = param_6;
      *(float *)(puVar2 + 0x10) = param_7;
      pRVar4 = RGE_Game_World::object(this->world,*param_2);
      if (pRVar4 == (RGE_Static_Object *)0x0) {
        pcVar5 = s_X;
        this_00 = extraout_ECX;
      }
      else {
        this_00 = (TDebuggingLog *)pRVar4->master_obj;
        pcVar5 = (char *)this_00->LogToFile;
      }
      TDebuggingLog::Log(this_00,(char *)L,s_______>SEND_CMD_MOVE2__CNT__d_OW,param_3,param_1,pcVar5
                        );
      submit(this,puVar2,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_create
// Address: 004359c0
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_create
          (RGE_Command *this,short param_1,short param_2,float param_3,float param_4,float param_5)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x14);
  *(float *)(puVar1 + 8) = param_3;
  *(float *)(puVar1 + 0xc) = param_4;
  puVar1[4] = (char)param_2;
  *(float *)(puVar1 + 0x10) = param_5;
  *puVar1 = 4;
  *(short *)(puVar1 + 2) = param_1;
  TDebuggingLog::Log((TDebuggingLog *)(int)param_2,(char *)L,s_______>SEND_CMD_CREATE__CAT__d_P,
                     (int)param_1,(TDebuggingLog *)(int)param_2);
  submit(this,puVar1,0x14);
  return;
}

// --------------------------------------------------

// Function: command_add_attribute
// Address: 00435a30
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_add_attribute(RGE_Command *this,int param_1,int param_2,float param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,8);
  *puVar1 = 5;
  puVar1[1] = (char)param_1;
  puVar1[2] = (char)param_2;
  *(float *)(puVar1 + 4) = param_3;
  TDebuggingLog::Log((TDebuggingLog *)param_2,(char *)L,s_______>SEND_CMD_ADD_ATTR__PLR__d,param_1,
                     param_2);
  submit(this,puVar1,8);
  return;
}

// --------------------------------------------------

// Function: command_give_attribute
// Address: 00435a80
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_give_attribute
          (RGE_Command *this,int param_1,int param_2,int param_3,float param_4)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,8);
  *puVar1 = 7;
  puVar1[1] = (char)param_1;
  puVar1[2] = (char)param_2;
  puVar1[3] = (char)param_3;
  *(float *)(puVar1 + 4) = param_4;
  TDebuggingLog::Log((TDebuggingLog *)param_2,(char *)L,s_______>SEND_CMD_GIV_ATTR__FRM__d,param_1,
                     param_2,param_3);
  submit(this,puVar1,8);
  return;
}

// --------------------------------------------------

// Function: command_formation
// Address: 00435ae0
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_formation
          (RGE_Command *this,RGE_Static_Object **param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char *this_00;
  int iVar6;
  int iVar7;
  
  iVar1 = param_2 * 4 + 0xc;
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 0xc);
    if (puVar4 != (undefined1 *)0x0) {
      if (0 < param_2) {
        iVar6 = (int)param_1 - (int)puVar5;
        iVar7 = param_2;
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
      *puVar4 = 6;
      *(uint *)(puVar4 + 4) = param_2 & 0xff;
      *(int *)(puVar4 + 8) = param_3;
      pRVar3 = *param_1;
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        this_00 = s_X;
        iVar7 = -1;
      }
      else {
        this_00 = pRVar3->master_obj->name;
        iVar7 = (int)pRVar3->owner->id;
      }
      TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,s_______>SEND_CMD_FORMATION__CNT__,
                         param_2,iVar7,this_00);
      submit(this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_create_group
// Address: 00435bb0
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_create_group
          (RGE_Command *this,int param_1,int param_2,int *param_3,int param_4,float param_5)
{
  int iVar1;
  undefined1 *puVar2;
  int *piVar3;
  RGE_Static_Object *pRVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  puVar2 = (undefined1 *)calloc(1,0x74);
  *puVar2 = 8;
  puVar2[1] = (undefined1)param_1;
  *(int *)(puVar2 + 4) = param_2;
  if (0 < param_4) {
    piVar6 = (int *)(puVar2 + 0xc);
    piVar3 = param_3;
    iVar7 = param_4;
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      *piVar6 = iVar1;
      piVar6 = piVar6 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  puVar2[0x70] = (char)param_4;
  *(float *)(puVar2 + 8) = param_5;
  pRVar4 = RGE_Game_World::object(this->world,*param_3);
  if (pRVar4 == (RGE_Static_Object *)0x0) {
    pcVar5 = s_X;
  }
  else {
    pcVar5 = pRVar4->master_obj->name;
  }
  TDebuggingLog::Log(L,(char *)L,s_______>SEND_CMD_CRT_GROUP__CNT__,param_4,param_1,pcVar5);
  submit(this,puVar2,0x74);
  return;
}

// --------------------------------------------------

// Function: command_add_to_group
// Address: 00435c50
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_add_to_group
          (RGE_Command *this,int param_1,int param_2,int param_3,float param_4)
{
  undefined1 *puVar1;
  RGE_Static_Object *pRVar2;
  char *pcVar3;
  TDebuggingLog *this_00;
  
  puVar1 = (undefined1 *)calloc(1,0x10);
  *(int *)(puVar1 + 4) = param_2;
  *puVar1 = 0xe;
  puVar1[1] = (char)param_1;
  *(int *)(puVar1 + 0xc) = param_3;
  *(float *)(puVar1 + 8) = param_4;
  pRVar2 = RGE_Game_World::object(this->world,param_3);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    pcVar3 = s_X;
  }
  else {
    pcVar3 = pRVar2->master_obj->name;
  }
  TDebuggingLog::Log(this_00,(char *)L,s_______>SEND_CMD_ADD_GROUP__PLR__,param_1,pcVar3);
  submit(this,puVar1,0x10);
  return;
}

// --------------------------------------------------

// Function: command_remove_from_group
// Address: 00435cd0
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_remove_from_group(RGE_Command *this,int param_1,int param_2,int param_3)
{
  undefined1 *puVar1;
  RGE_Static_Object *pRVar2;
  char *pcVar3;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *this_00;
  
  puVar1 = (undefined1 *)calloc(1,0xc);
  *(int *)(puVar1 + 4) = param_2;
  *puVar1 = 0xf;
  puVar1[1] = (char)param_1;
  *(int *)(puVar1 + 8) = param_3;
  pRVar2 = RGE_Game_World::object(this->world,param_3);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    pcVar3 = s_X;
    this_00 = extraout_ECX;
  }
  else {
    this_00 = (TDebuggingLog *)pRVar2->master_obj;
    pcVar3 = (char *)this_00->LogToFile;
  }
  TDebuggingLog::Log(this_00,(char *)L,s_______>SEND_CMD_REM_GROUP__PLR__,param_1,pcVar3);
  submit(this,puVar1,0xc);
  return;
}

// --------------------------------------------------

// Function: command_destroy_group
// Address: 00435d40
// [HELPER] s_______: "      "
void __thiscall RGE_Command::command_destroy_group(RGE_Command *this,int param_1,int param_2)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,8);
  *puVar1 = 9;
  puVar1[1] = (char)param_1;
  *(int *)(puVar1 + 4) = param_2;
  TDebuggingLog::Log((TDebuggingLog *)param_2,(char *)L,s_______>SEND_CMD_DES_GROUP__PLR__,param_1);
  submit(this,puVar1,8);
  return;
}

// --------------------------------------------------

// Function: command_ai_order
// Address: 00435d90
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_ai_order
          (RGE_Command *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6
          ,float param_7,float param_8,float param_9,float param_10,uchar param_11,uchar param_12,
          uchar param_13)
{
  undefined1 *puVar1;
  RGE_Static_Object *pRVar2;
  RGE_Static_Object *pRVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined1 *)calloc(1,0x28);
  puVar1[1] = (undefined1)param_1;
  puVar1[2] = (undefined1)param_2;
  *(undefined2 *)(puVar1 + 8) = (undefined2)param_4;
  puVar1[10] = param_13;
  puVar1[0x10] = (undefined1)param_6;
  *(float *)(puVar1 + 0x14) = param_7;
  *(float *)(puVar1 + 0x18) = param_8;
  *(float *)(puVar1 + 0x1c) = param_9;
  *puVar1 = 10;
  *(int *)(puVar1 + 4) = param_3;
  *(int *)(puVar1 + 0xc) = param_5;
  *(float *)(puVar1 + 0x20) = param_10;
  puVar1[0x24] = param_11;
  puVar1[0x25] = param_12;
  pRVar2 = RGE_Game_World::object(this->world,param_3);
  pRVar3 = RGE_Game_World::object(this->world,param_5);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    _param_13 = s_X;
  }
  else {
    _param_13 = pRVar3->master_obj->name;
  }
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    _param_11 = s_X;
  }
  else {
    _param_11 = pRVar2->master_obj->name;
  }
  uVar4 = __ftol();
  uVar4 = __ftol(uVar4);
  TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_______>SEND_CMD_AI_ORD__PLR__d__,param_1,
                     param_4,param_2,param_3,_param_11,param_5,_param_13,uVar4);
  submit(this,puVar1,0x28);
  return;
}

// --------------------------------------------------

// Function: command_group_ai_order
// Address: 00435ea0
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_group_ai_order
          (RGE_Command *this,int param_1,int param_2,RGE_Static_Object **param_3,short param_4,
          int param_5,int param_6,int param_7,float param_8,float param_9,float param_10,
          float param_11,uchar param_12,uchar param_13,uchar param_14)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  RGE_Static_Object *pRVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  long size;
  
  if ((param_3 != (RGE_Static_Object **)0x0) && (0 < param_4)) {
    iVar9 = (int)param_4;
    iVar1 = iVar9 * 4 + 0x24;
    puVar3 = (undefined1 *)calloc(1,iVar1);
    puVar4 = (undefined4 *)(puVar3 + 0x24);
    if (puVar3 != (undefined1 *)0x0) {
      if (0 < iVar9) {
        iVar8 = (int)param_3 - (int)puVar4;
        iVar10 = iVar9;
        do {
          iVar2 = *(int *)(iVar8 + (int)puVar4);
          if (iVar2 == 0) {
            *puVar4 = 0xffffffff;
          }
          else {
            *puVar4 = *(undefined4 *)(iVar2 + 4);
          }
          puVar4 = puVar4 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      puVar3[2] = (undefined1)param_2;
      puVar3[6] = param_14;
      puVar3[0xc] = (undefined1)param_7;
      puVar3[3] = (undefined1)param_4;
      *(float *)(puVar3 + 0x10) = param_8;
      *(float *)(puVar3 + 0x14) = param_9;
      *(int *)(puVar3 + 8) = param_6;
      *(float *)(puVar3 + 0x18) = param_10;
      *(float *)(puVar3 + 0x1c) = param_11;
      *puVar3 = 0x11;
      puVar3[1] = (char)param_1;
      *(short *)(puVar3 + 4) = (short)param_5;
      puVar3[0x20] = param_12;
      puVar3[0x21] = param_13;
      pRVar5 = RGE_Game_World::object(this->world,param_6);
      if (pRVar5 == (RGE_Static_Object *)0x0) {
        pcVar7 = s_X;
      }
      else {
        pcVar7 = pRVar5->master_obj->name;
      }
      if (*param_3 == (RGE_Static_Object *)0x0) {
        pcVar6 = s_X;
      }
      else {
        pcVar6 = (*param_3)->master_obj->name;
      }
      TDebuggingLog::Log((TDebuggingLog *)param_2,(char *)L,s_______>SEND_CMD_GRP_AI_ORD__PLR_,
                         param_1,param_5,param_2,iVar9,pcVar6,pcVar7);
      submit(this,puVar3,iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: command_resign
// Address: 00435fe0
// [HELPER] s_______: "      "
void __thiscall RGE_Command::command_resign(RGE_Command *this,int param_1,int param_2,int param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,4);
  puVar1[2] = (undefined1)param_2;
  *puVar1 = 0xb;
  puVar1[1] = (char)param_1;
  puVar1[3] = (char)param_3;
  TDebuggingLog::Log((TDebuggingLog *)param_3,(char *)L,s_______>SEND_CMD_RESIGN__PLR__d_D,param_1,
                     param_3);
  submit(this,puVar1,4);
  return;
}

// --------------------------------------------------

// Function: command_add_waypoint
// Address: 00436030
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_add_waypoint
          (RGE_Command *this,int param_1,int param_2,XYZBYTEPoint *param_3,int param_4)
{
  undefined1 *puVar1;
  uchar *puVar2;
  RGE_Static_Object *pRVar3;
  char *pcVar4;
  uchar *puVar5;
  
  puVar1 = (undefined1 *)calloc(1,0x18);
  *puVar1 = 0xc;
  puVar1[1] = (undefined1)param_1;
  *(int *)(puVar1 + 4) = param_2;
  puVar1[8] = (char)param_4;
  if (0 < param_4) {
    puVar5 = puVar1 + 10;
    puVar2 = &param_3->z;
    do {
      puVar5[-1] = ((XYZBYTEPoint *)(puVar2 + -2))->x;
      *puVar5 = puVar2[-1];
      puVar5[1] = *puVar2;
      puVar5 = puVar5 + 3;
      param_4 = param_4 + -1;
      puVar2 = puVar2 + 3;
    } while (param_4 != 0);
  }
  pRVar3 = RGE_Game_World::object(this->world,param_2);
  if (pRVar3 == (RGE_Static_Object *)0x0) {
    pcVar4 = s_X;
  }
  else {
    pcVar4 = pRVar3->master_obj->name;
  }
  TDebuggingLog::Log((TDebuggingLog *)param_1,(char *)L,s_______>SEND_CMD_ADD_WAY__PLR__d_,param_1,
                     pcVar4);
  submit(this,puVar1,0x18);
  return;
}

// --------------------------------------------------

// Function: command_add_waypoint
// Address: 004360d0
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_add_waypoint
          (RGE_Command *this,int param_1,int param_2,uchar param_3,uchar param_4,uchar param_5)
{
  undefined1 *puVar1;
  RGE_Static_Object *pRVar2;
  char *pcVar3;
  TDebuggingLog *this_00;
  
  puVar1 = (undefined1 *)calloc(1,0x18);
  puVar1[9] = param_3;
  *puVar1 = 0xc;
  puVar1[1] = (char)param_1;
  *(int *)(puVar1 + 4) = param_2;
  puVar1[8] = 1;
  puVar1[10] = param_4;
  puVar1[0xb] = param_5;
  pRVar2 = RGE_Game_World::object(this->world,param_2);
  if (pRVar2 == (RGE_Static_Object *)0x0) {
    pcVar3 = s_X;
  }
  else {
    pcVar3 = pRVar2->master_obj->name;
  }
  TDebuggingLog::Log(this_00,(char *)L,s_______>SEND_CMD_ADD_WAY2__PLR__d,param_1,pcVar3);
  submit(this,puVar1,0x18);
  return;
}

// --------------------------------------------------

// Function: command_group_waypoint
// Address: 00436150
// [HELPER] s_X: "X"
// [HELPER] s_______: "      "
void __thiscall
RGE_Command::command_group_waypoint
          (RGE_Command *this,RGE_Static_Object **param_1,short param_2,uchar param_3,uchar param_4)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object *pRVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char *this_00;
  int iVar6;
  int iVar7;
  
  iVar7 = (int)param_2;
  iVar1 = iVar7 * 4 + 4;
  if ((param_1 != (RGE_Static_Object **)0x0) && (0 < param_2)) {
    puVar4 = (undefined1 *)calloc(1,iVar1);
    puVar5 = (undefined4 *)(puVar4 + 4);
    if (puVar4 != (undefined1 *)0x0) {
      if (0 < iVar7) {
        iVar6 = (int)param_1 - (int)puVar5;
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
      *puVar4 = 0x10;
      puVar4[1] = (char)param_2;
      puVar4[2] = param_3;
      puVar4[3] = param_4;
      pRVar3 = *param_1;
      if (pRVar3 == (RGE_Static_Object *)0x0) {
        this_00 = s_X;
        iVar7 = -1;
      }
      else {
        this_00 = pRVar3->master_obj->name;
        iVar7 = (int)pRVar3->owner->id;
      }
      TDebuggingLog::Log((TDebuggingLog *)this_00,(char *)L,s_______>SEND_CMD_GRP_WAY__PLR__d_,iVar7
                         ,this_00);
      submit(this,puVar4,iVar1);
    }
  }
  return;
}

// --------------------------------------------------


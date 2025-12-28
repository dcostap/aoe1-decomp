// Class: TRIBE_Task_List
// Size:  0xC
//
// VTable Layout:
// [00] create_task
// [01] get_target_task
// [02] is_attack_task
// [03] check_task
// [04] `scalar_deleting_destructor'
// [05] copy_obj
// [06] modify
// [07] modify_delta
// [08] modify_percent
// [09] save
// [10] make_new_obj
// [11] make_new_master
// [12] check_placement
// [13] alignment
// [14] calc_base_damage_ability
// [15] play_command_sound
// [16] play_move_sound
// [17] draw
// [18] `scalar_deleting_destructor'
// [19] data_load_random_map
// [20] load_random_map
// [21] do_terrain_brush
// [22] do_terrain_brush_stroke
// [23] do_elevation_brush
// [24] do_elevation_brush_stroke
// [25] do_cliff_brush
// [26] do_cliff_brush_stroke
// [27] map_generate
// [28] map_generate2
// [29] save
// [30] delete_cliff
//
// Member Layout:
// ----------------------------------------------------------------

// Function: get_target_task
// Address: 0052c3f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual class RGE_Task * __thiscall TRIBE_Task_List::get_target_task(class
   RGE_Action_Object *,class RGE_Static_Object *,float,float,float) */

RGE_Task * __thiscall
TRIBE_Task_List::get_target_task
          (TRIBE_Task_List *this,RGE_Action_Object *param_1,RGE_Static_Object *param_2,float param_3
          ,float param_4,float param_5)
{
  short sVar1;
  short sVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Task *pRVar4;
  short sVar5;
  int *piVar6;
  short sVar7;
  int iVar8;
  
  sVar2 = (short)param_1->_padding_;
  if (((((sVar2 != -1) && (_DAT_0057733c < (float)param_1->_padding_)) &&
       (param_2 != (RGE_Static_Object *)0x0)) && (param_2->object_state == '\x02')) &&
     ((sVar1 = *(short *)(param_1->_padding_ + 0x14), sVar1 == 4 || (sVar1 == 0x15)))) {
    sVar5 = -1;
    sVar7 = -1;
    if (sVar1 == 4) {
      switch(sVar2) {
      case 1:
      case 2:
      case 3:
      case 0xf:
      case 0x11:
        sVar5 = 0x6d;
        sVar7 = 0x67;
        break;
      case 0x10:
        sVar5 = 0x6d;
        sVar7 = 0x44;
      }
    }
    else if ((sVar1 == 0x15) && ((sVar2 == 9 || (sVar2 == 0x11)))) {
      sVar5 = 0x2d;
    }
    sVar1 = param_2->master_obj->id;
    if (((sVar1 == sVar5) || (sVar1 == sVar7)) &&
       (param_2->owner->id == *(short *)(param_1->_padding_ + 0x4a))) {
      iVar8 = 0;
      if (0 < *(short *)&this->field_0x8) {
        piVar6 = *(int **)&this->field_0x4;
        do {
          pRVar4 = (RGE_Task *)*piVar6;
          if (pRVar4->attribute_type == sVar2) {
            sVar1 = pRVar4->action_type;
            if (sVar1 == 5) {
              return pRVar4;
            }
            if (sVar1 == 0x6e) {
              return pRVar4;
            }
            if (sVar1 == 0x6f) {
              return pRVar4;
            }
          }
          iVar8 = iVar8 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar8 < *(short *)&this->field_0x8);
      }
    }
  }
  if (param_2 != (RGE_Static_Object *)0x0) {
    if (((param_1 != (RGE_Action_Object *)0x0) &&
        (param_2->owner == (RGE_Player *)param_1->_padding_)) &&
       ((param_2->master_obj->master_type == 'P' && (param_2->object_state == '\0')))) {
      iVar8 = 0;
      if (*(short *)&this->field_0x8 < 1) {
        return (RGE_Task *)0x0;
      }
      piVar6 = *(int **)&this->field_0x4;
      do {
        if (((RGE_Task *)*piVar6)->action_type == 0x65) {
          return (RGE_Task *)*piVar6;
        }
        iVar8 = iVar8 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar8 < *(short *)&this->field_0x8);
      return (RGE_Task *)0x0;
    }
    if (param_2 != (RGE_Static_Object *)0x0) {
      if ((((param_2->owner == (RGE_Player *)param_1->_padding_) ||
           ((iVar8 = (**(code **)(((RGE_Player *)param_1->_padding_)->_padding_ + 0x1c))
                               ((int)param_2->owner->id), iVar8 != 0 &&
            (iVar8 = (**(code **)(param_2->owner->_padding_ + 0x1c))
                               ((int)*(short *)(param_1->_padding_ + 0x4a)), iVar8 != 0)))) &&
          (param_2->object_state < 3)) && (param_2->master_obj->unit_level == '\a')) {
        iVar8 = 0;
        if (*(short *)&this->field_0x8 < 1) {
          return (RGE_Task *)0x0;
        }
        piVar6 = *(int **)&this->field_0x4;
        do {
          if (((RGE_Task *)*piVar6)->action_type == 3) {
            return (RGE_Task *)*piVar6;
          }
          iVar8 = iVar8 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar8 < *(short *)&this->field_0x8);
        return (RGE_Task *)0x0;
      }
      if (param_2 != (RGE_Static_Object *)0x0) {
        if (param_1 != (RGE_Action_Object *)0x0) {
          if (((((param_2->owner == (RGE_Player *)param_1->_padding_) ||
                (iVar8 = (**(code **)(((RGE_Player *)param_1->_padding_)->_padding_ + 0x1c))
                                   ((int)param_2->owner->id), iVar8 != 0)) &&
               (pRVar3 = param_2->master_obj, pRVar3->master_type == 'P')) &&
              ((param_2->hp < (float)(int)pRVar3->hp && (param_2->object_state < 3)))) &&
             (pRVar3->id != 0x32)) {
            iVar8 = 0;
            if (*(short *)&this->field_0x8 < 1) {
              return (RGE_Task *)0x0;
            }
            piVar6 = *(int **)&this->field_0x4;
            do {
              pRVar4 = (RGE_Task *)*piVar6;
              if (pRVar4->action_type == 0x6a) {
                if (pRVar4->object_group == -1) {
                  return pRVar4;
                }
                if (pRVar4->object_group == 0) {
                  return pRVar4;
                }
              }
              iVar8 = iVar8 + 1;
              piVar6 = piVar6 + 1;
              if (*(short *)&this->field_0x8 <= iVar8) {
                return (RGE_Task *)0x0;
              }
            } while( true );
          }
        }
        if ((param_2 != (RGE_Static_Object *)0x0) && (param_1 != (RGE_Action_Object *)0x0)) {
          if ((param_2->owner == (RGE_Player *)param_1->_padding_) ||
             ((iVar8 = (**(code **)(((RGE_Player *)param_1->_padding_)->_padding_ + 0x1c))
                                 ((int)param_2->owner->id), iVar8 != 0 &&
              (iVar8 = (**(code **)(param_2->owner->_padding_ + 0x1c))
                                 ((int)*(short *)(param_1->_padding_ + 0x4a)), iVar8 != 0)))) {
            sVar2 = param_2->master_obj->object_group;
            if (((sVar2 == 2) || (((sVar2 == 0x14 || (sVar2 == 0x15)) || (sVar2 == 0x16)))) &&
               ((param_2->hp < (float)(int)param_2->master_obj->hp && (param_2->object_state < 3))))
{
              iVar8 = 0;
              if (*(short *)&this->field_0x8 < 1) {
                return (RGE_Task *)0x0;
              }
              piVar6 = *(int **)&this->field_0x4;
              while ((pRVar4 = (RGE_Task *)*piVar6, pRVar4->action_type != 0x6a ||
                     (pRVar4->object_group != sVar2))) {
                iVar8 = iVar8 + 1;
                piVar6 = piVar6 + 1;
                if (*(short *)&this->field_0x8 <= iVar8) {
                  return (RGE_Task *)0x0;
                }
              }
              return pRVar4;
            }
          }
        }
      }
    }
  }
  if ((param_1 != (RGE_Action_Object *)0x0) && (*(short *)(param_1->_padding_ + 0x14) == 0x12)) {
    if (param_2 != (RGE_Static_Object *)0x0) {
      if ((((param_2->owner == (RGE_Player *)param_1->_padding_) || (2 < param_2->object_state)) ||
          (sVar2 = param_2->owner->id, sVar2 < 1)) ||
         ((iVar8 = (**(code **)(((RGE_Player *)param_1->_padding_)->_padding_ + 0x1c))((int)sVar2),
          iVar8 != 0 || (param_2->master_obj->object_group == 1)))) {
        if (param_2 != (RGE_Static_Object *)0x0) {
          if ((((((param_2->owner == (RGE_Player *)param_1->_padding_) ||
                 (iVar8 = (**(code **)(((RGE_Player *)param_1->_padding_)->_padding_ + 0x1c))
                                    ((int)param_2->owner->id), iVar8 != 0)) &&
                ((param_2->hp < (float)(int)param_2->master_obj->hp &&
                 (((param_2->object_state < 3 &&
                   (sVar2 = param_2->master_obj->object_group, sVar2 != 0x15)) && (sVar2 != 2))))))
               && ((sVar2 != 0x14 && (sVar2 != 0x16)))) && (sVar2 != 1)) &&
             ((sVar2 != 0x1b && (sVar2 != 3)))) {
            iVar8 = 0;
            if (0 < *(short *)&this->field_0x8) {
              piVar6 = *(int **)&this->field_0x4;
              do {
                if (((RGE_Task *)*piVar6)->action_type == 0x69) {
                  return (RGE_Task *)*piVar6;
                }
                iVar8 = iVar8 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar8 < *(short *)&this->field_0x8);
              return (RGE_Task *)0x0;
            }
          }
        }
      }
      else {
        iVar8 = 0;
        if (0 < *(short *)&this->field_0x8) {
          piVar6 = *(int **)&this->field_0x4;
          do {
            if (((RGE_Task *)*piVar6)->action_type == 0x68) {
              return (RGE_Task *)*piVar6;
            }
            iVar8 = iVar8 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar8 < *(short *)&this->field_0x8);
          return (RGE_Task *)0x0;
        }
      }
    }
    return (RGE_Task *)0x0;
  }
  pRVar4 = RGE_Task_List::get_target_task
                     ((RGE_Task_List *)this,param_1,param_2,param_3,param_4,param_5);
  return pRVar4;
}

// --------------------------------------------------

// Function: is_attack_task
// Address: 0052c8d0
/* public: virtual int __thiscall TRIBE_Task_List::is_attack_task(class RGE_Task *) */

int __thiscall TRIBE_Task_List::is_attack_task(TRIBE_Task_List *this,RGE_Task *param_1)
{
  int iVar1;
  
  if (param_1->action_type == 0x68) {
    return 1;
  }
  iVar1 = RGE_Task_List::is_attack_task((RGE_Task_List *)this,param_1);
  return iVar1;
}

// --------------------------------------------------


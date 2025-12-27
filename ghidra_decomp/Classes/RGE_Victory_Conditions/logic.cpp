// Class: RGE_Victory_Conditions
// Function: RGE_Victory_Conditions
// Address: 00531750
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall RGE_Victory_Conditions::RGE_Victory_Conditions(class RGE_Player *,int,long
   *,unsigned char) */

RGE_Victory_Conditions * __thiscall
RGE_Victory_Conditions::RGE_Victory_Conditions
          (RGE_Victory_Conditions *this,RGE_Player *param_1,int param_2,long *param_3,uchar param_4)
{
  long *plVar1;
  undefined1 *puVar2;
  RGE_Player *pRVar3;
  float fVar4;
  int iVar5;
  void *pvVar6;
  RGE_Game_World *pRVar7;
  RGE_Static_Object *pRVar8;
  RGE_Victory_Point_Entry *pRVar9;
  int iVar10;
  undefined3 in_stack_00000011;
  long target_obj;
  RGE_Victory_Entry **temp2;
  long target_player;
  float version;
  long temp_num;
  int local_8;
  long *local_4;
  
  iVar5 = param_2;
  this->_padding_ = (int)&_vftable_;
  if (param_4 == '\x01') {
    rge_read(param_2,&temp_num,4);
  }
  else {
    temp_num = 0;
  }
  plVar1 = &this->list_num;
  local_4 = plVar1;
  rge_read(iVar5,plVar1,4);
  rge_read(iVar5,&this->victory,1);
  target_player = (long)&this->victory_list;
  *(RGE_Victory_Entry **)target_player = (RGE_Victory_Entry *)0x0;
  this->player = param_1;
  _param_4 = 0;
  if (0 < *plVar1) {
    do {
      pvVar6 = (void *)calloc(1,0x34);
      rge_read(iVar5,pvVar6,1);
      rge_read(iVar5,(void *)((int)pvVar6 + 4),4);
      rge_read(iVar5,&version,4);
      rge_read(iVar5,(void *)((int)pvVar6 + 0xc),4);
      rge_read(iVar5,(void *)((int)pvVar6 + 0x10),4);
      rge_read(iVar5,(void *)((int)pvVar6 + 0x14),4);
      rge_read(iVar5,(void *)((int)pvVar6 + 0x18),4);
      rge_read(iVar5,(void *)((int)pvVar6 + 0x1c),4);
      rge_read(iVar5,(void *)((int)pvVar6 + 0x20),4);
      rge_read(iVar5,&param_2,4);
      rge_read(iVar5,&temp2,4);
      rge_read(iVar5,(void *)((int)pvVar6 + 0x2c),1);
      rge_read(iVar5,(void *)((int)pvVar6 + 0x2d),1);
      puVar2 = (undefined1 *)((int)pvVar6 + 0x2e);
      rge_read(iVar5,puVar2,1);
      *(undefined4 *)((int)pvVar6 + 0x28) = 0;
      *(undefined4 *)((int)pvVar6 + 0x24) = 0;
      *(undefined4 *)((int)pvVar6 + 8) = 0;
      *(void **)target_player = pvVar6;
      target_player = (int)pvVar6 + 0x30;
      if (-1 < param_2) {
        iVar10 = 0;
        pRVar7 = this->player->world;
        if (0 < pRVar7->player_num) {
          do {
            pRVar8 = RGE_Object_List::find_by_id(pRVar7->players[iVar10]->objects,param_2);
            *(RGE_Static_Object **)((int)pvVar6 + 0x24) = pRVar8;
            if (pRVar8 != (RGE_Static_Object *)0x0) break;
            iVar10 = iVar10 + 1;
            pRVar7 = this->player->world;
          } while (iVar10 < pRVar7->player_num);
        }
        if ((-1 < param_2) && (*(int *)((int)pvVar6 + 0x24) == 0)) {
          *puVar2 = 3;
        }
      }
      if (-1 < (int)temp2) {
        pRVar8 = RGE_Object_List::find_by_id(this->player->objects,(long)temp2);
        *(RGE_Static_Object **)((int)pvVar6 + 0x28) = pRVar8;
      }
      if ((int)version < 0) {
        *(undefined4 *)((int)pvVar6 + 8) = 0;
      }
      else {
        if (param_3 != (long *)0x0) {
          version = (float)param_3[(int)version];
        }
        if ((int)version < 0) {
          *puVar2 = 3;
        }
        else {
          pRVar3 = this->player->world->players[(int)version];
          *(RGE_Player **)((int)pvVar6 + 8) = pRVar3;
          if (((pRVar3 != (RGE_Player *)0x0) && (*(int *)((int)pvVar6 + 0x28) == 0)) &&
             (-1 < (int)temp2)) {
            pRVar8 = RGE_Object_List::find_by_id(pRVar3->objects,(long)temp2);
            *(RGE_Static_Object **)((int)pvVar6 + 0x28) = pRVar8;
          }
        }
      }
      if ((-1 < (int)temp2) && (*(int *)((int)pvVar6 + 0x28) == 0)) {
        *puVar2 = 3;
      }
      _param_4 = _param_4 + 1;
    } while (_param_4 < *local_4);
  }
  fVar4 = (float)_DAT_00577590;
  this->victory_point_list = (RGE_Victory_Point_Entry *)0x0;
  this->point_list_num = 0;
  if ((float)temp_num < fVar4) {
    this->tot_victory_points = 0;
  }
  else {
    plVar1 = &this->tot_victory_points;
    rge_read(iVar5,plVar1,4);
    rge_read(iVar5,&local_8,4);
    _param_4 = 0;
    if (0 < local_8) {
      do {
        pRVar9 = add_point(this,'\0','\0');
        rge_read(iVar5,pRVar9,1);
        rge_read(iVar5,&pRVar9->state,1);
        rge_read(iVar5,&pRVar9->attribute,4);
        rge_read(iVar5,&pRVar9->amount,4);
        rge_read(iVar5,&pRVar9->points,4);
        rge_read(iVar5,&pRVar9->curr_points,4);
        rge_read(iVar5,&pRVar9->id,1);
        rge_read(iVar5,&pRVar9->group,1);
        rge_read(iVar5,&pRVar9->curr_attribute_amount,4);
        if (*plVar1 < 0) {
          pRVar9->points = 0;
        }
        _param_4 = _param_4 + 1;
      } while (_param_4 < local_8);
    }
    if (*plVar1 < 0) {
      *plVar1 = 0;
      return this;
    }
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Victory_Conditions
// Address: 00531af0
/* public: __thiscall RGE_Victory_Conditions::RGE_Victory_Conditions(class RGE_Player *) */

void __thiscall
RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Victory_Conditions *this,RGE_Player *param_1)
{
  this->player = param_1;
  this->_padding_ = (int)&_vftable_;
  this->list_num = 0;
  this->victory_list = (RGE_Victory_Entry *)0x0;
  this->victory_point_list = (RGE_Victory_Point_Entry *)0x0;
  this->victory = '\0';
  this->point_list_num = 0;
  this->tot_victory_points = 0;
  return;
}

// --------------------------------------------------

// Function: ~RGE_Victory_Conditions
// Address: 00531b20
/* public: __thiscall RGE_Victory_Conditions::~RGE_Victory_Conditions(void) */

void __thiscall RGE_Victory_Conditions::~RGE_Victory_Conditions(RGE_Victory_Conditions *this)
{
  RGE_Victory_Entry *pRVar1;
  RGE_Victory_Point_Entry *pRVar2;
  
  pRVar1 = this->victory_list;
  this->_padding_ = (int)&_vftable_;
  while (pRVar1 != (RGE_Victory_Entry *)0x0) {
    sub(this,pRVar1);
    pRVar1 = this->victory_list;
  }
  pRVar2 = this->victory_point_list;
  while (pRVar2 != (RGE_Victory_Point_Entry *)0x0) {
    sub_point(this,pRVar2);
    pRVar2 = this->victory_point_list;
  }
  this->list_num = 0;
  this->point_list_num = 0;
  this->victory = '\0';
  this->player = (RGE_Player *)0x0;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 00531b70
/* WARNING: Variable defined which should be unmapped: this_obj */
/* public: virtual void __thiscall RGE_Victory_Conditions::save(int) */

void __thiscall RGE_Victory_Conditions::save(RGE_Victory_Conditions *this,int param_1)
{
  RGE_Victory_Entry *pRVar1;
  RGE_Victory_Point_Entry *pRVar2;
  int iVar3;
  long this_obj;
  long target_obj;
  float version;
  undefined4 local_4;
  
  iVar3 = param_1;
  local_4 = 0x3f800000;
  rge_write(param_1,&local_4,4);
  rge_write(iVar3,&this->list_num,4);
  rge_write(iVar3,&this->victory,1);
  for (pRVar1 = this->victory_list; pRVar1 != (RGE_Victory_Entry *)0x0; pRVar1 = pRVar1->next) {
    if (pRVar1->target_player == (RGE_Player *)0x0) {
      param_1 = -1;
    }
    else {
      param_1 = (int)pRVar1->target_player->id;
    }
    if (pRVar1->this_obj == (RGE_Static_Object *)0x0) {
      target_obj = -1;
    }
    else {
      target_obj = pRVar1->this_obj->id;
    }
    if (pRVar1->target_obj == (RGE_Static_Object *)0x0) {
      version = -NAN;
    }
    else {
      version = (float)pRVar1->target_obj->id;
      param_1 = (int)pRVar1->target_obj->owner->id;
    }
    rge_write(iVar3,pRVar1,1);
    rge_write(iVar3,&pRVar1->obj_type,4);
    rge_write(iVar3,&param_1,4);
    rge_write(iVar3,&pRVar1->x0,4);
    rge_write(iVar3,&pRVar1->y0,4);
    rge_write(iVar3,&pRVar1->x1,4);
    rge_write(iVar3,&pRVar1->y1,4);
    rge_write(iVar3,&pRVar1->number,4);
    rge_write(iVar3,&pRVar1->count,4);
    rge_write(iVar3,&target_obj,4);
    rge_write(iVar3,&version,4);
    rge_write(iVar3,&pRVar1->victory_group,1);
    rge_write(iVar3,&pRVar1->ally_flag,1);
    rge_write(iVar3,&pRVar1->state,1);
  }
  rge_write(iVar3,&this->tot_victory_points,4);
  rge_write(iVar3,&this->point_list_num,4);
  for (pRVar2 = this->victory_point_list; pRVar2 != (RGE_Victory_Point_Entry *)0x0;
      pRVar2 = pRVar2->next) {
    rge_write(iVar3,pRVar2,1);
    rge_write(iVar3,&pRVar2->state,1);
    rge_write(iVar3,&pRVar2->attribute,4);
    rge_write(iVar3,&pRVar2->amount,4);
    rge_write(iVar3,&pRVar2->points,4);
    rge_write(iVar3,&pRVar2->curr_points,4);
    rge_write(iVar3,&pRVar2->id,1);
    rge_write(iVar3,&pRVar2->group,1);
    rge_write(iVar3,&pRVar2->curr_attribute_amount,4);
  }
  return;
}

// --------------------------------------------------

// Function: check_for_victory
// Address: 00531db0
/* WARNING: Variable defined which should be unmapped: victory_void_num */
/* protected: void __thiscall RGE_Victory_Conditions::check_for_victory(void) */

void __thiscall RGE_Victory_Conditions::check_for_victory(RGE_Victory_Conditions *this)
{
  uchar uVar1;
  bool bVar2;
  RGE_Victory_Entry *pRVar3;
  RGE_Victory_Conditions *pRVar4;
  int iVar5;
  int iVar6;
  long victory_void_num;
  long failed_group_num;
  long group_num;
  long curr_victory_group;
  
  pRVar3 = this->victory_list;
  failed_group_num = 0;
  curr_victory_group = 0;
  group_num = 0;
  if (pRVar3 != (RGE_Victory_Entry *)0x0) {
    this->victory = '\0';
    for (; pRVar4 = this, pRVar3 != (RGE_Victory_Entry *)0x0; pRVar3 = pRVar3->next) {
      pRVar3->checked_flag = '\0';
    }
LAB_00531deb:
    do {
      pRVar3 = this->victory_list;
      if (pRVar3 == (RGE_Victory_Entry *)0x0) goto LAB_00531e70;
      do {
        if (pRVar3->checked_flag == '\0') {
          pRVar4 = (RGE_Victory_Conditions *)(uint)pRVar3->victory_group;
          curr_victory_group = curr_victory_group + 1;
          break;
        }
        pRVar3 = pRVar3->next;
      } while (pRVar3 != (RGE_Victory_Entry *)0x0);
      if (pRVar3 == (RGE_Victory_Entry *)0x0) goto LAB_00531e70;
      iVar6 = 0;
      iVar5 = 0;
      bVar2 = false;
      do {
        if ((RGE_Victory_Conditions *)(uint)pRVar3->victory_group == pRVar4) {
          iVar6 = iVar6 + 1;
          uVar1 = pRVar3->state;
          pRVar3->checked_flag = '\x01';
          if (uVar1 == '\x01') {
            bVar2 = true;
          }
          else if (uVar1 == '\x02') {
            iVar5 = iVar5 + 1;
          }
          else if (uVar1 == '\x03') {
            failed_group_num = failed_group_num + 1;
          }
        }
        pRVar3 = pRVar3->next;
      } while (pRVar3 != (RGE_Victory_Entry *)0x0);
      if (bVar2) {
        group_num = group_num + 1;
        goto LAB_00531deb;
      }
    } while ((iVar5 < 1) || (iVar6 != failed_group_num + iVar5));
    this->victory = '\x02';
LAB_00531e70:
    if (curr_victory_group == group_num) {
      this->victory = '\x01';
    }
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00531e90
/* public: unsigned char __thiscall RGE_Victory_Conditions::update(void) */

uchar __thiscall RGE_Victory_Conditions::update(RGE_Victory_Conditions *this)
{
  RGE_Victory_Point_Entry *pRVar1;
  RGE_Victory_Entry *pRVar2;
  
  for (pRVar1 = this->victory_point_list; pRVar1 != (RGE_Victory_Point_Entry *)0x0;
      pRVar1 = pRVar1->next) {
    if ((pRVar1->state != '\x03') && (pRVar1->state != '\x01')) {
      (**(code **)this->_padding_)(pRVar1);
    }
  }
  for (pRVar2 = this->victory_list; pRVar2 != (RGE_Victory_Entry *)0x0; pRVar2 = pRVar2->next) {
    if ((pRVar2->state != '\x03') && (pRVar2->state != '\x01')) {
      (**(code **)(this->_padding_ + 4))(pRVar2);
    }
  }
  check_for_victory(this);
  return this->victory;
}

// --------------------------------------------------

// Function: update_for_object
// Address: 00531ef0
/* public: void __thiscall RGE_Victory_Conditions::update_for_object(class RGE_Static_Object *) */

void __thiscall
RGE_Victory_Conditions::update_for_object(RGE_Victory_Conditions *this,RGE_Static_Object *param_1)
{
  RGE_Victory_Entry *pRVar1;
  RGE_Victory_Entry *pRVar2;
  
  pRVar1 = this->victory_list;
  while (pRVar2 = pRVar1, pRVar2 != (RGE_Victory_Entry *)0x0) {
    pRVar1 = pRVar2->next;
    if ((pRVar2->this_obj == param_1) || (pRVar2->target_obj == param_1)) {
      sub(this,pRVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_point_condition
// Address: 00531f30
/* protected: virtual void __thiscall RGE_Victory_Conditions::handle_point_condition(struct
   RGE_Victory_Point_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_point_condition
          (RGE_Victory_Conditions *this,RGE_Victory_Point_Entry *param_1)
{
  switch(param_1->command) {
  case '\0':
    handle_points_attribute_amount(this,param_1);
    return;
  case '\x01':
    handle_points_attribute_first(this,param_1);
    return;
  case '\x02':
    handle_points_highest_attribute(this,param_1);
    return;
  case '\x03':
    handle_points_high_attribute_once(this,param_1);
    return;
  case '\x04':
    handle_points_high_attribute_amount(this,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: handle_condition
// Address: 00531f90
/* protected: virtual void __thiscall RGE_Victory_Conditions::handle_condition(struct
   RGE_Victory_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_condition(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  switch(param_1->command) {
  case '\0':
    handle_capture(this,param_1);
    return;
  case '\x01':
    handle_create(this,param_1);
    return;
  case '\x02':
    handle_destroy(this,param_1);
    return;
  case '\x03':
    handle_destroy_multiple(this,param_1);
    return;
  case '\x04':
    handle_bring_area(this,param_1);
    return;
  case '\x05':
    handle_bring_object(this,param_1);
    return;
  case '\x06':
    handle_attribute(this,param_1);
    return;
  case '\a':
    handle_explore(this,param_1);
    return;
  case '\b':
    handle_create_in_area(this,param_1);
    return;
  case '\t':
    handle_destroy_all(this,param_1);
    return;
  case '\n':
    handle_destroy_player(this,param_1);
    return;
  case '\f':
    handle_victory_points(this,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: handle_capture
// Address: 00532050
/* protected: void __thiscall RGE_Victory_Conditions::handle_capture(struct RGE_Victory_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_capture(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Static_Object *pRVar1;
  RGE_Player *pRVar2;
  RGE_Player *pRVar3;
  
  pRVar1 = param_1->target_obj;
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    if (pRVar1->object_state < 3) {
      if (param_1->state == '\0') {
        pRVar2 = pRVar1->owner;
        pRVar3 = this->player;
        if ((pRVar2 == pRVar3) ||
           ((((param_1->ally_flag != '\0' && (pRVar3->allied_victory != '\0')) &&
             (pRVar3->relations[pRVar2->id] == '\0')) &&
            ((pRVar2->relations[pRVar3->id] == '\0' && (pRVar2->allied_victory != '\0')))))) {
          param_1->state = '\x02';
          return;
        }
      }
      else if (param_1->state == '\x02') {
        if ((pRVar1->owner != this->player) &&
           ((param_1->ally_flag == '\0' || (this->player->relations[pRVar1->owner->id] != '\0')))) {
          param_1->state = '\0';
        }
      }
    }
    else {
      param_1->target_obj = (RGE_Static_Object *)0x0;
      if (param_1->state == '\0') {
        param_1->state = '\x01';
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_create
// Address: 00532110
/* WARNING: Variable defined which should be unmapped: num */
/* protected: void __thiscall RGE_Victory_Conditions::handle_create(struct RGE_Victory_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_create(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Player *pRVar1;
  RGE_Player *pRVar2;
  RGE_Object_Node *pRVar3;
  int iVar4;
  int iVar5;
  RGE_Player **ppRVar6;
  long num;
  int local_8;
  
  pRVar1 = this->player;
  iVar5 = 0;
  local_8 = 0;
  pRVar3 = pRVar1->objects->list;
  if (pRVar3 != (RGE_Object_Node *)0x0) {
    do {
      if (((int)pRVar3->node->master_obj->copy_id == param_1->obj_type) &&
         (pRVar3->node->object_state == '\x02')) {
        iVar5 = iVar5 + 1;
      }
      pRVar3 = pRVar3->next;
      local_8 = iVar5;
    } while (pRVar3 != (RGE_Object_Node *)0x0);
  }
  if ((param_1->ally_flag != '\0') && (pRVar1->allied_victory != '\0')) {
    iVar4 = 1;
    iVar5 = (int)pRVar1->world->player_num;
    ppRVar6 = pRVar1->world->players;
    if (1 < iVar5) {
      do {
        ppRVar6 = ppRVar6 + 1;
        if (pRVar1->relations[iVar4] == '\0') {
          pRVar2 = *ppRVar6;
          if ((((pRVar2->relations[pRVar1->id] == '\0') && (iVar4 != pRVar1->id)) &&
              (pRVar2->allied_victory != '\0')) &&
             (pRVar3 = pRVar2->objects->list, pRVar3 != (RGE_Object_Node *)0x0)) {
            do {
              if (((int)pRVar3->node->master_obj->copy_id == param_1->obj_type) &&
                 (pRVar3->node->object_state == '\x02')) {
                local_8 = local_8 + 1;
              }
              pRVar3 = pRVar3->next;
            } while (pRVar3 != (RGE_Object_Node *)0x0);
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar5);
    }
  }
  if (local_8 < param_1->number) {
    param_1->state = '\0';
    return;
  }
  param_1->state = '\x02';
  return;
}

// --------------------------------------------------

// Function: handle_create_in_area
// Address: 00532220
/* WARNING: Variable defined which should be unmapped: num */
/* protected: void __thiscall RGE_Victory_Conditions::handle_create_in_area(struct RGE_Victory_Entry
   *) */

void __thiscall
RGE_Victory_Conditions::handle_create_in_area
          (RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Player *pRVar1;
  RGE_Static_Object *pRVar2;
  RGE_Player *pRVar3;
  RGE_Object_Node *pRVar4;
  int iVar5;
  RGE_Player **ppRVar6;
  int iVar7;
  long num;
  int local_c;
  
  pRVar1 = this->player;
  iVar5 = 0;
  local_c = 0;
  pRVar4 = pRVar1->objects->list;
  if (pRVar4 != (RGE_Object_Node *)0x0) {
    do {
      pRVar2 = pRVar4->node;
      if ((((((int)pRVar2->master_obj->copy_id == param_1->obj_type) &&
            (pRVar2->object_state == '\x02')) && (param_1->x0 <= pRVar2->world_x)) &&
          ((pRVar2->world_x <= param_1->x1 && (param_1->y0 <= pRVar2->world_y)))) &&
         (pRVar2->world_y <= param_1->y1)) {
        iVar5 = iVar5 + 1;
      }
      pRVar4 = pRVar4->next;
      local_c = iVar5;
    } while (pRVar4 != (RGE_Object_Node *)0x0);
  }
  if ((param_1->ally_flag != '\0') && (pRVar1->allied_victory != '\0')) {
    iVar5 = 1;
    iVar7 = (int)pRVar1->world->player_num;
    ppRVar6 = pRVar1->world->players;
    if (1 < iVar7) {
      do {
        ppRVar6 = ppRVar6 + 1;
        if (pRVar1->relations[iVar5] == '\0') {
          pRVar3 = *ppRVar6;
          if ((((pRVar3->relations[pRVar1->id] == '\0') && (iVar5 != pRVar1->id)) &&
              (pRVar3->allied_victory != '\0')) &&
             (pRVar4 = pRVar3->objects->list, pRVar4 != (RGE_Object_Node *)0x0)) {
            do {
              pRVar2 = pRVar4->node;
              if (((((int)pRVar2->master_obj->copy_id == param_1->obj_type) &&
                   (pRVar2->object_state == '\x02')) &&
                  ((param_1->x0 <= pRVar2->world_x &&
                   ((pRVar2->world_x <= param_1->x1 && (param_1->y0 <= pRVar2->world_y)))))) &&
                 (pRVar2->world_y <= param_1->y1)) {
                local_c = local_c + 1;
              }
              pRVar4 = pRVar4->next;
            } while (pRVar4 != (RGE_Object_Node *)0x0);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar7);
    }
  }
  if (local_c < param_1->number) {
    param_1->state = '\0';
    return;
  }
  param_1->state = '\x02';
  return;
}

// --------------------------------------------------

// Function: handle_destroy
// Address: 005323b0
/* protected: void __thiscall RGE_Victory_Conditions::handle_destroy(struct RGE_Victory_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_destroy(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  if ((param_1->target_obj != (RGE_Static_Object *)0x0) &&
     (param_1->target_obj->object_state == '\a')) {
    param_1->state = '\x02';
    param_1->target_obj = (RGE_Static_Object *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: handle_destroy_multiple
// Address: 005323d0
/* protected: void __thiscall RGE_Victory_Conditions::handle_destroy_multiple(struct
   RGE_Victory_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_destroy_multiple
          (RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Player *pRVar1;
  RGE_Object_Node *pRVar2;
  RGE_Player **ppRVar3;
  int iVar4;
  
  if (param_1->state == '\0') {
    if (param_1->target_player == (RGE_Player *)0x0) {
      pRVar1 = this->player;
      iVar4 = 0;
      ppRVar3 = pRVar1->world->players;
      if (0 < pRVar1->world->player_num) {
        do {
          if ((pRVar1->relations[iVar4] != '\0') &&
             (pRVar2 = (*ppRVar3)->objects->list, pRVar2 != (RGE_Object_Node *)0x0)) {
            do {
              if (((int)pRVar2->node->master_obj->copy_id == param_1->obj_type) &&
                 (pRVar2->node->object_state == '\a')) {
                param_1->count = param_1->count + 1;
              }
              pRVar2 = pRVar2->next;
            } while (pRVar2 != (RGE_Object_Node *)0x0);
          }
          pRVar1 = this->player;
          iVar4 = iVar4 + 1;
          ppRVar3 = ppRVar3 + 1;
        } while (iVar4 < pRVar1->world->player_num);
      }
    }
    else {
      pRVar2 = param_1->target_player->objects->list;
      if (pRVar2 != (RGE_Object_Node *)0x0) {
        do {
          if (((int)pRVar2->node->master_obj->copy_id == param_1->obj_type) &&
             (pRVar2->node->object_state == '\a')) {
            param_1->count = param_1->count + 1;
          }
          pRVar2 = pRVar2->next;
        } while (pRVar2 != (RGE_Object_Node *)0x0);
      }
    }
    if (param_1->number <= param_1->count) {
      param_1->state = '\x02';
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_destroy_all
// Address: 005324a0
/* protected: void __thiscall RGE_Victory_Conditions::handle_destroy_all(struct RGE_Victory_Entry *)
    */

void __thiscall
RGE_Victory_Conditions::handle_destroy_all(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Player *pRVar1;
  RGE_Object_Node *pRVar2;
  int iVar3;
  RGE_Player **ppRVar4;
  int iVar5;
  
  if (param_1->target_player == (RGE_Player *)0x0) {
    pRVar1 = this->player;
    iVar3 = 0;
    iVar5 = (int)pRVar1->world->player_num;
    ppRVar4 = pRVar1->world->players;
    if (0 < iVar5) {
      do {
        if (((pRVar1->relations[iVar3] != '\0') && (iVar3 != pRVar1->id)) &&
           (pRVar2 = (*ppRVar4)->objects->list, pRVar2 != (RGE_Object_Node *)0x0)) {
          do {
            if ((int)pRVar2->node->master_obj->copy_id == param_1->obj_type) {
              param_1->state = '\0';
              return;
            }
            pRVar2 = pRVar2->next;
          } while (pRVar2 != (RGE_Object_Node *)0x0);
        }
        iVar3 = iVar3 + 1;
        ppRVar4 = ppRVar4 + 1;
      } while (iVar3 < iVar5);
      param_1->state = '\x02';
      return;
    }
  }
  else {
    pRVar2 = param_1->target_player->objects->list;
    if (pRVar2 != (RGE_Object_Node *)0x0) {
      do {
        if ((int)pRVar2->node->master_obj->copy_id == param_1->obj_type) {
          param_1->state = '\0';
          return;
        }
        pRVar2 = pRVar2->next;
      } while (pRVar2 != (RGE_Object_Node *)0x0);
      param_1->state = '\x02';
      return;
    }
  }
  param_1->state = '\x02';
  return;
}

// --------------------------------------------------

// Function: handle_destroy_player
// Address: 00532570
/* protected: void __thiscall RGE_Victory_Conditions::handle_destroy_player(struct RGE_Victory_Entry
   *) */

void __thiscall
RGE_Victory_Conditions::handle_destroy_player
          (RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  if (param_1->target_player != (RGE_Player *)0x0) {
    if (param_1->target_player->game_status != '\x02') {
      param_1->state = '\0';
      return;
    }
    param_1->state = '\x02';
  }
  return;
}

// --------------------------------------------------

// Function: handle_bring_area
// Address: 005325a0
/* protected: void __thiscall RGE_Victory_Conditions::handle_bring_area(struct RGE_Victory_Entry *)
    */

void __thiscall
RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = param_1->this_obj;
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    param_1->state = '\x03';
    return;
  }
  if (2 < pRVar1->object_state) {
    if (param_1->state == '\0') {
      param_1->state = '\x01';
    }
    param_1->this_obj = (RGE_Static_Object *)0x0;
    return;
  }
  if ((((param_1->x0 <= pRVar1->world_x) && (pRVar1->world_x <= param_1->x1)) &&
      (param_1->y0 <= pRVar1->world_y)) && (pRVar1->world_y <= param_1->y1)) {
    param_1->state = '\x02';
    return;
  }
  param_1->state = '\0';
  return;
}

// --------------------------------------------------

// Function: handle_bring_object
// Address: 00532610
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: void __thiscall RGE_Victory_Conditions::handle_bring_object(struct RGE_Victory_Entry
   *) */

void __thiscall
RGE_Victory_Conditions::handle_bring_object(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Static_Object *pRVar1;
  RGE_Static_Object *pRVar2;
  float fVar3;
  float fVar4;
  
  pRVar1 = param_1->this_obj;
  if ((pRVar1 == (RGE_Static_Object *)0x0) ||
     (pRVar2 = param_1->target_obj, pRVar2 == (RGE_Static_Object *)0x0)) {
    param_1->state = '\x03';
  }
  else {
    if ((pRVar1->object_state < 3) && (pRVar2->object_state < 3)) {
      fVar3 = pRVar1->world_x - pRVar2->world_x;
      fVar4 = pRVar1->world_y - pRVar2->world_y;
      if (fVar3 < _DAT_00577588) {
        fVar3 = -fVar3;
      }
      if (fVar4 < _DAT_00577588) {
        fVar4 = -fVar4;
      }
      if ((fVar3 <= (pRVar2->master_obj->radius_x + pRVar1->master_obj->radius_x) - _DAT_0057759c)
         && (fVar4 <= (pRVar2->master_obj->radius_y + pRVar1->master_obj->radius_y) - _DAT_0057759c)
         ) {
        param_1->state = '\x02';
        return;
      }
      param_1->state = '\0';
      return;
    }
    param_1->this_obj = (RGE_Static_Object *)0x0;
    param_1->target_obj = (RGE_Static_Object *)0x0;
    if (param_1->state == '\0') {
      param_1->state = '\x01';
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_attribute
// Address: 005326f0
/* protected: void __thiscall RGE_Victory_Conditions::handle_attribute(struct RGE_Victory_Entry *)
    */

void __thiscall
RGE_Victory_Conditions::handle_attribute(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  float fVar1;
  RGE_Player *pRVar2;
  RGE_Player *pRVar3;
  int iVar4;
  RGE_Player **ppRVar5;
  
  pRVar2 = this->player;
  if (pRVar2 != (RGE_Player *)0x0) {
    fVar1 = pRVar2->attributes[param_1->number];
    if ((param_1->ally_flag != '\0') && (pRVar2->allied_victory != '\0')) {
      iVar4 = pRVar2->world->player_num + -1;
      if (-1 < iVar4) {
        ppRVar5 = pRVar2->world->players + iVar4;
        do {
          if (pRVar2->relations[iVar4] == '\0') {
            pRVar3 = *ppRVar5;
            if (((pRVar3->relations[pRVar2->id] == '\0') && (iVar4 != pRVar2->id)) &&
               (pRVar3->allied_victory != '\0')) {
              fVar1 = fVar1 + pRVar3->attributes[param_1->number];
            }
          }
          iVar4 = iVar4 + -1;
          ppRVar5 = ppRVar5 + -1;
        } while (-1 < iVar4);
      }
    }
    if ((float)param_1->count <= fVar1) {
      param_1->state = '\x02';
      return;
    }
    param_1->state = '\0';
  }
  return;
}

// --------------------------------------------------

// Function: handle_explore
// Address: 005327a0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: void __thiscall RGE_Victory_Conditions::handle_explore(struct RGE_Victory_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_explore(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  RGE_Player **ppRVar3;
  float fVar4;
  
  if ((param_1->state == '\0') && (pRVar1 = this->player, pRVar1 != (RGE_Player *)0x0)) {
    if ((param_1->ally_flag == '\0') || (pRVar1->allied_victory == '\0')) {
      fVar4 = RGE_Visible_Map::percentExplored(pRVar1->visible);
      if ((float)param_1->count <= fVar4 * _DAT_005775a0) {
        param_1->state = '\x02';
      }
    }
    else {
      iVar2 = pRVar1->world->player_num + -1;
      if (-1 < iVar2) {
        ppRVar3 = pRVar1->world->players + iVar2;
        do {
          pRVar1 = this->player;
          if ((((pRVar1->relations[iVar2] == '\0') && ((*ppRVar3)->relations[pRVar1->id] == '\0'))
              && ((*ppRVar3)->allied_victory != '\0')) || (iVar2 == pRVar1->id)) {
            fVar4 = RGE_Visible_Map::percentExplored((*ppRVar3)->visible);
            if ((float)param_1->count <= fVar4 * _DAT_005775a0) {
              param_1->state = '\x02';
              return;
            }
          }
          iVar2 = iVar2 + -1;
          ppRVar3 = ppRVar3 + -1;
        } while (-1 < iVar2);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_victory_points
// Address: 00532880
/* WARNING: Variable defined which should be unmapped: player_count */
/* protected: void __thiscall RGE_Victory_Conditions::handle_victory_points(struct RGE_Victory_Entry
   *) */

void __thiscall
RGE_Victory_Conditions::handle_victory_points
          (RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Player *pRVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  RGE_Player **ppRVar6;
  long player_count;
  int local_4;
  
  pRVar1 = this->player;
  if (pRVar1 != (RGE_Player *)0x0) {
    lVar4 = this->tot_victory_points;
    local_4 = 1;
    if ((param_1->ally_flag != '\0') && (pRVar1->allied_victory != '\0')) {
      iVar5 = pRVar1->world->player_num + -1;
      if (-1 < iVar5) {
        ppRVar6 = pRVar1->world->players + iVar5;
        do {
          if (this->player->relations[iVar5] == '\0') {
            pRVar1 = *ppRVar6;
            iVar3 = (int)this->player->id;
            if (((pRVar1->relations[iVar3] == '\0') && (iVar5 != iVar3)) &&
               (pRVar1->allied_victory != '\0')) {
              lVar2 = get_victory_points(pRVar1->victory_conditions);
              lVar4 = lVar4 + lVar2;
              local_4 = local_4 + 1;
            }
          }
          iVar5 = iVar5 + -1;
          ppRVar6 = ppRVar6 + -1;
        } while (-1 < iVar5);
      }
    }
    if (param_1->count <= lVar4 / local_4) {
      param_1->state = '\x02';
    }
  }
  return;
}

// --------------------------------------------------

// Function: add
// Address: 00532930
/* protected: struct RGE_Victory_Entry * __thiscall RGE_Victory_Conditions::add(unsigned
   char,unsigned char) */

RGE_Victory_Entry * __thiscall
RGE_Victory_Conditions::add(RGE_Victory_Conditions *this,uchar param_1,uchar param_2)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = (RGE_Victory_Entry *)calloc(1,0x34);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->state = '\0';
    pRVar1->victory_group = param_1;
    pRVar1->ally_flag = param_2;
    pRVar1->count = 0;
    pRVar1->next = this->victory_list;
    this->victory_list = pRVar1;
    this->list_num = this->list_num + 1;
  }
  return pRVar1;
}

// --------------------------------------------------

// Function: add_capture
// Address: 00532970
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_capture(unsigned char,class
   RGE_Static_Object *,unsigned char) */

uchar __thiscall
RGE_Victory_Conditions::add_capture
          (RGE_Victory_Conditions *this,uchar param_1,RGE_Static_Object *param_2,uchar param_3)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,param_3);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\0';
    pRVar1->target_obj = param_2;
    pRVar1->target_player = param_2->owner;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_create
// Address: 005329a0
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_create(unsigned
   char,long,long,unsigned char) */

uchar __thiscall
RGE_Victory_Conditions::add_create
          (RGE_Victory_Conditions *this,uchar param_1,long param_2,long param_3,uchar param_4)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,param_4);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\x01';
    pRVar1->obj_type = param_2;
    pRVar1->number = param_3;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_create
// Address: 005329d0
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_create(unsigned
   char,long,long,float,float,float,float,unsigned char) */

uchar __thiscall
RGE_Victory_Conditions::add_create
          (RGE_Victory_Conditions *this,uchar param_1,long param_2,long param_3,float param_4,
          float param_5,float param_6,float param_7,uchar param_8)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,param_8);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->obj_type = param_2;
    pRVar1->number = param_3;
    pRVar1->x0 = param_4;
    pRVar1->y0 = param_5;
    pRVar1->command = '\b';
    pRVar1->x1 = param_6;
    pRVar1->y1 = param_7;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_destroy
// Address: 00532a20
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_destroy(unsigned char,class
   RGE_Static_Object *) */

uchar __thiscall
RGE_Victory_Conditions::add_destroy
          (RGE_Victory_Conditions *this,uchar param_1,RGE_Static_Object *param_2)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\x02';
    pRVar1->target_obj = param_2;
    pRVar1->target_player = param_2->owner;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_destroy
// Address: 00532a50
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_destroy(unsigned
   char,long,long,class RGE_Player *) */

uchar __thiscall
RGE_Victory_Conditions::add_destroy
          (RGE_Victory_Conditions *this,uchar param_1,long param_2,long param_3,RGE_Player *param_4)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->obj_type = param_2;
    pRVar1->command = '\x03';
    pRVar1->number = param_3;
    pRVar1->target_player = param_4;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_destroy
// Address: 00532a90
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_destroy(unsigned char,long,class
   RGE_Player *) */

uchar __thiscall
RGE_Victory_Conditions::add_destroy
          (RGE_Victory_Conditions *this,uchar param_1,long param_2,RGE_Player *param_3)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\t';
    pRVar1->obj_type = param_2;
    pRVar1->target_player = param_3;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_destroy
// Address: 00532ac0
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_destroy(unsigned char,class
   RGE_Player *) */

uchar __thiscall
RGE_Victory_Conditions::add_destroy(RGE_Victory_Conditions *this,uchar param_1,RGE_Player *param_2)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\n';
    pRVar1->target_player = param_2;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_bring
// Address: 00532af0
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_bring(unsigned char,class
   RGE_Static_Object *,class RGE_Static_Object *) */

uchar __thiscall
RGE_Victory_Conditions::add_bring
          (RGE_Victory_Conditions *this,uchar param_1,RGE_Static_Object *param_2,
          RGE_Static_Object *param_3)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\x05';
    pRVar1->this_obj = param_2;
    pRVar1->target_obj = param_3;
    pRVar1->target_player = param_3->owner;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_bring
// Address: 00532b30
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_bring(unsigned char,class
   RGE_Static_Object *,float,float,float,float) */

uchar __thiscall
RGE_Victory_Conditions::add_bring
          (RGE_Victory_Conditions *this,uchar param_1,RGE_Static_Object *param_2,float param_3,
          float param_4,float param_5,float param_6)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->this_obj = param_2;
    pRVar1->x0 = param_3;
    pRVar1->y0 = param_4;
    pRVar1->command = '\x04';
    pRVar1->x1 = param_5;
    pRVar1->y1 = param_6;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_attributes
// Address: 00532b70
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_attributes(unsigned
   char,long,long,unsigned char) */

uchar __thiscall
RGE_Victory_Conditions::add_attributes
          (RGE_Victory_Conditions *this,uchar param_1,long param_2,long param_3,uchar param_4)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,param_4);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\x06';
    pRVar1->number = param_2;
    pRVar1->count = param_3;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_explore
// Address: 00532ba0
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_explore(unsigned char,long,unsigned
   char) */

uchar __thiscall
RGE_Victory_Conditions::add_explore
          (RGE_Victory_Conditions *this,uchar param_1,long param_2,uchar param_3)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,param_3);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\a';
    if (param_2 < 1) {
      param_2 = 1;
    }
    if (100 < param_2) {
      param_2 = 100;
    }
    pRVar1->count = param_2;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_victory_points
// Address: 00532be0
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_victory_points(unsigned
   char,long,unsigned char) */

uchar __thiscall
RGE_Victory_Conditions::add_victory_points
          (RGE_Victory_Conditions *this,uchar param_1,long param_2,uchar param_3)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = add(this,param_1,param_3);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\f';
    pRVar1->count = param_2;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: sub
// Address: 00532c10
/* protected: void __thiscall RGE_Victory_Conditions::sub(struct RGE_Victory_Entry *) */

void __thiscall RGE_Victory_Conditions::sub(RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  RGE_Victory_Entry *pRVar1;
  RGE_Victory_Entry **ppRVar2;
  
  pRVar1 = this->victory_list;
  ppRVar2 = &this->victory_list;
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    while (pRVar1 != param_1) {
      ppRVar2 = &pRVar1->next;
      pRVar1 = pRVar1->next;
      if (pRVar1 == (RGE_Victory_Entry *)0x0) {
        return;
      }
    }
    *ppRVar2 = pRVar1->next;
    free(pRVar1);
    this->list_num = this->list_num + -1;
  }
  return;
}

// --------------------------------------------------

// Function: destroy_all
// Address: 00532c50
/* public: void __thiscall RGE_Victory_Conditions::destroy_all(void) */

void __thiscall RGE_Victory_Conditions::destroy_all(RGE_Victory_Conditions *this)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = this->victory_list;
  while (pRVar1 != (RGE_Victory_Entry *)0x0) {
    sub(this,pRVar1);
    pRVar1 = this->victory_list;
  }
  return;
}

// --------------------------------------------------

// Function: condition_info
// Address: 00532c70
/* public: unsigned char __thiscall RGE_Victory_Conditions::condition_info(long,char * *,unsigned
   char &) */

uchar __thiscall
RGE_Victory_Conditions::condition_info
          (RGE_Victory_Conditions *this,long param_1,char **param_2,uchar *param_3)
{
  int iVar1;
  undefined4 uVar2;
  RGE_Victory_Entry *pRVar3;
  
  pRVar3 = this->victory_list;
  iVar1 = 0;
  if (pRVar3 == (RGE_Victory_Entry *)0x0) {
    *param_2 = (char *)0x0;
    return '\0';
  }
  do {
    if (iVar1 == param_1) {
      uVar2 = (**(code **)(this->_padding_ + 8))(pRVar3);
      *(undefined4 *)param_1 = uVar2;
      *(uchar *)param_2 = pRVar3->command;
      return '\x01';
    }
    pRVar3 = pRVar3->next;
    iVar1 = iVar1 + 1;
  } while (pRVar3 != (RGE_Victory_Entry *)0x0);
  *param_2 = (char *)0x0;
  return '\0';
}

// --------------------------------------------------

// Function: condition_description
// Address: 00532cc0
// [HELPER] s_Bring__s_to__s: "Bring %s to %s"
// [HELPER] s_Bring__s_to_area___f___f______f_: "Bring %s to area (%f, %f) - (%f, %f)"
// [HELPER] s_Create__d__s_in_area___f___f____: "Create %d %s in area (%f, %f) - (%f, %f)"
// [HELPER] s_aqquire__d_of_attribute__d: "aqquire %d of attribute %d"
/* WARNING: Variable defined which should be unmapped: description */
/* protected: virtual char * __thiscall RGE_Victory_Conditions::condition_description(struct
   RGE_Victory_Entry *) */

char * __thiscall
RGE_Victory_Conditions::condition_description
          (RGE_Victory_Conditions *this,RGE_Victory_Entry *param_1)
{
  char *description;
  char temp [200];
  
  temp[0] = '\0';
  temp[1] = '\0';
  temp[2] = '\0';
  temp[3] = '\0';
  switch(param_1->command) {
  case '\0':
    goto LAB_00532e78;
  case '\x01':
    goto LAB_00532dd2;
  case '\x02':
    goto LAB_00532e78;
  case '\x03':
    sprintf();
    break;
  case '\x04':
    sprintf(temp + 4,s_Bring__s_to_area___f___f______f_,param_1->this_obj->master_obj->name,
            (double)param_1->x0,(double)param_1->y0,(double)param_1->x1,(double)param_1->y1);
    break;
  case '\x05':
    sprintf(temp + 4,s_Bring__s_to__s,param_1->this_obj->master_obj->name);
    break;
  case '\x06':
    sprintf(temp + 4,s_aqquire__d_of_attribute__d,param_1->count);
    break;
  case '\a':
LAB_00532e78:
    sprintf();
    break;
  case '\b':
    sprintf(temp + 4,s_Create__d__s_in_area___f___f____,param_1->number,
            param_1->target_player->master_objects[param_1->obj_type]->name,(double)param_1->x0,
            (double)param_1->y0,(double)param_1->x1,(double)param_1->y1);
    break;
  case '\t':
LAB_00532dd2:
    sprintf(temp + 4);
  }
  getstring((char **)temp,temp + 4);
  return (char *)temp._0_4_;
}

// --------------------------------------------------

// Function: condition_raw_info
// Address: 00532ed0
/* public: struct RGE_Victory_Entry * __thiscall RGE_Victory_Conditions::condition_raw_info(long) */

RGE_Victory_Entry * __thiscall
RGE_Victory_Conditions::condition_raw_info(RGE_Victory_Conditions *this,long param_1)
{
  RGE_Victory_Entry *pRVar1;
  int iVar2;
  
  pRVar1 = this->victory_list;
  iVar2 = 0;
  while( true ) {
    if (pRVar1 == (RGE_Victory_Entry *)0x0) {
      return (RGE_Victory_Entry *)0x0;
    }
    if (iVar2 == param_1) break;
    pRVar1 = pRVar1->next;
    iVar2 = iVar2 + 1;
  }
  return pRVar1;
}

// --------------------------------------------------

// Function: condition_number
// Address: 00532ef0
/* public: long __thiscall RGE_Victory_Conditions::condition_number(long) */

long __thiscall RGE_Victory_Conditions::condition_number(RGE_Victory_Conditions *this,long param_1)
{
  return this->list_num;
}

// --------------------------------------------------

// Function: victory_achieved
// Address: 00532f00
/* public: unsigned char __thiscall RGE_Victory_Conditions::victory_achieved(void) */

uchar __thiscall RGE_Victory_Conditions::victory_achieved(RGE_Victory_Conditions *this)
{
  return this->victory == '\x02';
}

// --------------------------------------------------

// Function: remove_condition
// Address: 00532f10
/* public: unsigned char __thiscall RGE_Victory_Conditions::remove_condition(long) */

uchar __thiscall RGE_Victory_Conditions::remove_condition(RGE_Victory_Conditions *this,long param_1)
{
  RGE_Victory_Entry *pRVar1;
  int iVar2;
  
  pRVar1 = this->victory_list;
  iVar2 = 0;
  if (pRVar1 == (RGE_Victory_Entry *)0x0) {
    return '\0';
  }
  do {
    if (iVar2 == param_1) {
      sub(this,pRVar1);
      return '\x01';
    }
    pRVar1 = pRVar1->next;
    iVar2 = iVar2 + 1;
  } while (pRVar1 != (RGE_Victory_Entry *)0x0);
  return '\0';
}

// --------------------------------------------------

// Function: add_point
// Address: 00532f50
/* protected: struct RGE_Victory_Point_Entry * __thiscall RGE_Victory_Conditions::add_point(unsigned
   char,unsigned char) */

RGE_Victory_Point_Entry * __thiscall
RGE_Victory_Conditions::add_point(RGE_Victory_Conditions *this,uchar param_1,uchar param_2)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = (RGE_Victory_Point_Entry *)calloc(1,0x1c);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->state = '\0';
    pRVar1->attribute = -1;
    pRVar1->amount = 0;
    pRVar1->command = 0xff;
    pRVar1->points = 0;
    pRVar1->curr_points = 0;
    pRVar1->next = this->victory_point_list;
    pRVar1->id = param_1;
    pRVar1->group = param_2;
    this->victory_point_list = pRVar1;
    this->point_list_num = this->point_list_num + 1;
  }
  return pRVar1;
}

// --------------------------------------------------

// Function: sub_point
// Address: 00532fa0
/* protected: void __thiscall RGE_Victory_Conditions::sub_point(struct RGE_Victory_Point_Entry *) */

void __thiscall
RGE_Victory_Conditions::sub_point(RGE_Victory_Conditions *this,RGE_Victory_Point_Entry *param_1)
{
  RGE_Victory_Point_Entry *pRVar1;
  RGE_Victory_Point_Entry **ppRVar2;
  
  pRVar1 = this->victory_point_list;
  ppRVar2 = &this->victory_point_list;
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    while (pRVar1 != param_1) {
      ppRVar2 = &pRVar1->next;
      pRVar1 = pRVar1->next;
      if (pRVar1 == (RGE_Victory_Point_Entry *)0x0) {
        return;
      }
    }
    *ppRVar2 = pRVar1->next;
    free(pRVar1);
    this->point_list_num = this->point_list_num + -1;
  }
  return;
}

// --------------------------------------------------

// Function: add_points_attribute_amount
// Address: 00532fe0
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_points_attribute_amount(unsigned
   char,unsigned char,long,long,long) */

uchar __thiscall
RGE_Victory_Conditions::add_points_attribute_amount
          (RGE_Victory_Conditions *this,uchar param_1,uchar param_2,long param_3,long param_4,
          long param_5)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = add_point(this,param_2,param_1);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_3;
    pRVar1->command = '\0';
    pRVar1->amount = param_4;
    pRVar1->points = param_5;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_points_attribute_first
// Address: 00533020
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_points_attribute_first(unsigned
   char,unsigned char,long,long,long) */

uchar __thiscall
RGE_Victory_Conditions::add_points_attribute_first
          (RGE_Victory_Conditions *this,uchar param_1,uchar param_2,long param_3,long param_4,
          long param_5)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = add_point(this,param_2,param_1);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_3;
    pRVar1->command = '\x01';
    pRVar1->amount = param_4;
    pRVar1->points = param_5;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_points_highest_attribute
// Address: 00533060
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_points_highest_attribute(unsigned
   char,unsigned char,long,long,long) */

uchar __thiscall
RGE_Victory_Conditions::add_points_highest_attribute
          (RGE_Victory_Conditions *this,uchar param_1,uchar param_2,long param_3,long param_4,
          long param_5)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = add_point(this,param_2,param_1);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_3;
    pRVar1->command = '\x02';
    pRVar1->amount = param_4;
    pRVar1->points = param_5;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_points_high_attribute_once
// Address: 005330a0
/* public: unsigned char __thiscall RGE_Victory_Conditions::add_points_high_attribute_once(unsigned
   char,unsigned char,long,long,long) */

uchar __thiscall
RGE_Victory_Conditions::add_points_high_attribute_once
          (RGE_Victory_Conditions *this,uchar param_1,uchar param_2,long param_3,long param_4,
          long param_5)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = add_point(this,param_2,param_1);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_3;
    pRVar1->command = '\x03';
    pRVar1->amount = param_4;
    pRVar1->points = param_5;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_points_high_attribute_amount
// Address: 005330e0
/* public: unsigned char __thiscall
   RGE_Victory_Conditions::add_points_high_attribute_amount(unsigned char,unsigned
   char,long,long,long) */

uchar __thiscall
RGE_Victory_Conditions::add_points_high_attribute_amount
          (RGE_Victory_Conditions *this,uchar param_1,uchar param_2,long param_3,long param_4,
          long param_5)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = add_point(this,param_2,param_1);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_3;
    pRVar1->command = '\x04';
    pRVar1->amount = param_4;
    pRVar1->points = param_5;
    return '\x01';
  }
  return '\0';
}

// --------------------------------------------------

// Function: handle_points_attribute_amount
// Address: 00533120
/* protected: void __thiscall RGE_Victory_Conditions::handle_points_attribute_amount(struct
   RGE_Victory_Point_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_points_attribute_amount
          (RGE_Victory_Conditions *this,RGE_Victory_Point_Entry *param_1)
{
  int iVar1;
  int iVar2;
  
  if (param_1->state == '\0') {
    iVar1 = __ftol();
    iVar2 = iVar1 / param_1->amount;
    param_1->curr_attribute_amount = (float)iVar1;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iVar2 = param_1->points * iVar2;
    if (iVar2 - param_1->curr_points != 0) {
      this->tot_victory_points = this->tot_victory_points + (iVar2 - param_1->curr_points);
      param_1->curr_points = iVar2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_points_attribute_first
// Address: 00533180
/* protected: void __thiscall RGE_Victory_Conditions::handle_points_attribute_first(struct
   RGE_Victory_Point_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_points_attribute_first
          (RGE_Victory_Conditions *this,RGE_Victory_Point_Entry *param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  RGE_Player **ppRVar5;
  int iVar6;
  long points;
  
  if (param_1->state == '\0') {
    pRVar1 = this->player;
    iVar2 = param_1->attribute;
    iVar4 = __ftol();
    iVar3 = param_1->points;
    ppRVar5 = pRVar1->world->players;
    param_1->curr_attribute_amount = (float)iVar4;
    if (param_1->amount <= iVar4) {
      iVar4 = 0;
      iVar6 = (int)this->player->world->player_num;
      if (0 < iVar6) {
        do {
          if ((iVar4 != this->player->id) &&
             ((float)param_1->amount <= (*ppRVar5)->attributes[iVar2])) {
            param_1->state = '\x01';
            return;
          }
          iVar4 = iVar4 + 1;
          ppRVar5 = ppRVar5 + 1;
        } while (iVar4 < iVar6);
      }
      this->tot_victory_points = this->tot_victory_points + (iVar3 - param_1->curr_points);
      param_1->curr_points = iVar3;
      param_1->state = '\x02';
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_points_highest_attribute
// Address: 00533240
/* protected: void __thiscall RGE_Victory_Conditions::handle_points_highest_attribute(struct
   RGE_Victory_Point_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_points_highest_attribute
          (RGE_Victory_Conditions *this,RGE_Victory_Point_Entry *param_1)
{
  long *plVar1;
  int iVar2;
  RGE_Game_World *pRVar3;
  float fVar4;
  RGE_Victory_Point_Entry *pRVar5;
  int iVar6;
  int iVar7;
  RGE_Player **ppRVar8;
  
  pRVar5 = param_1;
  if (param_1->state == '\0') {
    iVar2 = param_1->attribute;
    iVar6 = __ftol();
    plVar1 = &param_1->points;
    fVar4 = (float)iVar6;
    param_1->curr_attribute_amount = fVar4;
    pRVar3 = this->player->world;
    ppRVar8 = pRVar3->players;
    if (iVar6 < param_1->amount) {
      param_1 = (RGE_Victory_Point_Entry *)0x0;
    }
    else {
      iVar6 = (int)pRVar3->player_num;
      iVar7 = 1;
      param_1 = (RGE_Victory_Point_Entry *)*plVar1;
      if (1 < iVar6) {
        do {
          ppRVar8 = ppRVar8 + 1;
          if (iVar7 != this->player->id) {
            if (fVar4 < (*ppRVar8)->attributes[iVar2]) {
              param_1 = (RGE_Victory_Point_Entry *)0x0;
              break;
            }
            if ((*ppRVar8)->attributes[iVar2] == fVar4) {
              param_1 = (RGE_Victory_Point_Entry *)pRVar5->curr_points;
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar6);
      }
    }
    if (param_1 != (RGE_Victory_Point_Entry *)pRVar5->curr_points) {
      this->tot_victory_points =
           (int)param_1 + (this->tot_victory_points - (int)pRVar5->curr_points);
      pRVar5->curr_points = (long)param_1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_points_high_attribute_once
// Address: 00533330
/* protected: void __thiscall RGE_Victory_Conditions::handle_points_high_attribute_once(struct
   RGE_Victory_Point_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_points_high_attribute_once
          (RGE_Victory_Conditions *this,RGE_Victory_Point_Entry *param_1)
{
  int iVar1;
  RGE_Player *pRVar2;
  long lVar3;
  int iVar4;
  RGE_Player **ppRVar5;
  int iVar6;
  
  if (param_1->state == '\0') {
    iVar4 = param_1->attribute;
    iVar1 = __ftol();
    if (param_1->curr_attribute_amount < (float)iVar1) {
      param_1->curr_attribute_amount = (float)iVar1;
    }
    pRVar2 = this->player;
    iVar6 = 1;
    ppRVar5 = pRVar2->world->players;
    if (1 < pRVar2->world->player_num) {
      do {
        ppRVar5 = ppRVar5 + 1;
        if ((iVar6 != pRVar2->id) && ((float)param_1->amount <= (*ppRVar5)->attributes[iVar4])) {
          lVar3 = __ftol();
          param_1->amount = lVar3;
        }
        pRVar2 = this->player;
        iVar6 = iVar6 + 1;
      } while (iVar6 < pRVar2->world->player_num);
    }
    if (param_1->curr_attribute_amount < (float)param_1->amount) {
      if (iVar1 == param_1->amount) {
        iVar4 = param_1->curr_points;
      }
      else {
        iVar4 = 0;
      }
    }
    else {
      iVar4 = param_1->points;
    }
    if (iVar4 != param_1->curr_points) {
      this->tot_victory_points = this->tot_victory_points + (iVar4 - param_1->curr_points);
      param_1->curr_points = iVar4;
    }
  }
  return;
}

// --------------------------------------------------

// Function: handle_points_high_attribute_amount
// Address: 00533410
/* protected: void __thiscall RGE_Victory_Conditions::handle_points_high_attribute_amount(struct
   RGE_Victory_Point_Entry *) */

void __thiscall
RGE_Victory_Conditions::handle_points_high_attribute_amount
          (RGE_Victory_Conditions *this,RGE_Victory_Point_Entry *param_1)
{
  int iVar1;
  
  if (param_1->state == '\0') {
    iVar1 = __ftol();
    if (param_1->curr_attribute_amount < (float)iVar1) {
      param_1->curr_attribute_amount = (float)iVar1;
    }
    iVar1 = __ftol();
    iVar1 = iVar1 * param_1->points;
    if (iVar1 - param_1->curr_points != 0) {
      this->tot_victory_points = this->tot_victory_points + (iVar1 - param_1->curr_points);
      param_1->curr_points = iVar1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: get_victory_points
// Address: 00533480
/* public: long __thiscall RGE_Victory_Conditions::get_victory_points(void) */

long __thiscall RGE_Victory_Conditions::get_victory_points(RGE_Victory_Conditions *this)
{
  return this->tot_victory_points;
}

// --------------------------------------------------

// Function: get_victory_points_group
// Address: 00533490
/* public: long __thiscall RGE_Victory_Conditions::get_victory_points_group(unsigned char) */

long __thiscall
RGE_Victory_Conditions::get_victory_points_group(RGE_Victory_Conditions *this,uchar param_1)
{
  RGE_Victory_Point_Entry *pRVar1;
  int iVar2;
  
  iVar2 = 0;
  for (pRVar1 = this->victory_point_list; pRVar1 != (RGE_Victory_Point_Entry *)0x0;
      pRVar1 = pRVar1->next) {
    if ((pRVar1->group == param_1) || (param_1 == 0xff)) {
      iVar2 = iVar2 + pRVar1->curr_points;
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: get_victory_points_id
// Address: 005334c0
/* public: long __thiscall RGE_Victory_Conditions::get_victory_points_id(unsigned char) */

long __thiscall
RGE_Victory_Conditions::get_victory_points_id(RGE_Victory_Conditions *this,uchar param_1)
{
  RGE_Victory_Point_Entry *pRVar1;
  long lVar2;
  
  lVar2 = 0;
  for (pRVar1 = this->victory_point_list; pRVar1 != (RGE_Victory_Point_Entry *)0x0;
      pRVar1 = pRVar1->next) {
    if (pRVar1->id == param_1) {
      lVar2 = pRVar1->curr_points;
    }
  }
  return lVar2;
}

// --------------------------------------------------

// Function: get_attribute_id
// Address: 005334e0
/* public: long __thiscall RGE_Victory_Conditions::get_attribute_id(unsigned char) */

long __thiscall RGE_Victory_Conditions::get_attribute_id(RGE_Victory_Conditions *this,uchar param_1)
{
  RGE_Victory_Point_Entry *pRVar1;
  long lVar2;
  
  lVar2 = 0;
  for (pRVar1 = this->victory_point_list; pRVar1 != (RGE_Victory_Point_Entry *)0x0;
      pRVar1 = pRVar1->next) {
    if (pRVar1->id == param_1) {
      lVar2 = __ftol();
    }
  }
  return lVar2;
}

// --------------------------------------------------


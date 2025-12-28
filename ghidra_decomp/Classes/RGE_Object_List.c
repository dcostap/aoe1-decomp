// Class: RGE_Object_List
// Size:  0xC
//
// VTable Layout:
// [00] load
//
// Member Layout:
// [0x004] RGE_Object_Node * list
// [0x008] short number_of_objects
// ----------------------------------------------------------------

// Function: RGE_Object_List
// Address: 00462e80
/* public: __thiscall RGE_Object_List::RGE_Object_List(void) */

void __thiscall RGE_Object_List::RGE_Object_List(RGE_Object_List *this)
{
  this->_padding_ = (int)&_vftable_;
  this->list = (RGE_Object_Node *)0x0;
  this->number_of_objects = 0;
  return;
}

// --------------------------------------------------

// Function: ~RGE_Object_List
// Address: 00462ea0
/* public: __thiscall RGE_Object_List::~RGE_Object_List(void) */

void __thiscall RGE_Object_List::~RGE_Object_List(RGE_Object_List *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_Node *pRVar2;
  RGE_Static_Object **ppRVar3;
  
  this->_padding_ = (int)&_vftable_;
  pRVar2 = this->list;
  while (pRVar2 != (RGE_Object_Node *)0x0) {
    pRVar1 = pRVar2->next;
    ppRVar3 = &pRVar2->node;
    pRVar2 = pRVar1;
    if (*ppRVar3 != (RGE_Static_Object *)0x0) {
      (**(code **)(*ppRVar3)->_padding_)(1);
    }
  }
  pRVar2 = this->list;
  while (pRVar2 != (RGE_Object_Node *)0x0) {
    pRVar2 = this->list->next;
    free(pRVar2);
    this->list = pRVar2;
  }
  this->number_of_objects = 0;
  return;
}

// --------------------------------------------------

// Function: removeAllObjects
// Address: 00462ef0
/* public: void __thiscall RGE_Object_List::removeAllObjects(void) */

void __thiscall RGE_Object_List::removeAllObjects(RGE_Object_List *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Static_Object **ppRVar2;
  RGE_Object_Node *pRVar3;
  
  pRVar3 = this->list;
  while (pRVar3 != (RGE_Object_Node *)0x0) {
    pRVar1 = pRVar3->next;
    ppRVar2 = &pRVar3->node;
    pRVar3 = pRVar1;
    if (*ppRVar2 != (RGE_Static_Object *)0x0) {
      (**(code **)(*ppRVar2)->_padding_)(1);
    }
  }
  this->list = (RGE_Object_Node *)0x0;
  this->number_of_objects = 0;
  return;
}

// --------------------------------------------------

// Function: add_node
// Address: 00462f30
/* public: struct RGE_Object_Node * __thiscall RGE_Object_List::add_node(class RGE_Static_Object *)
    */

RGE_Object_Node * __thiscall
RGE_Object_List::add_node(RGE_Object_List *this,RGE_Static_Object *param_1)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_Node *pRVar2;
  
  pRVar2 = (RGE_Object_Node *)calloc(1,0x10);
  pRVar1 = this->list;
  pRVar2->prev = (RGE_Object_Node *)0x0;
  pRVar2->next = pRVar1;
  if (this->list != (RGE_Object_Node *)0x0) {
    this->list->prev = pRVar2;
  }
  pRVar2->node = param_1;
  this->number_of_objects = this->number_of_objects + 1;
  this->list = pRVar2;
  return pRVar2;
}

// --------------------------------------------------

// Function: remove_node
// Address: 00462f70
/* public: void __thiscall RGE_Object_List::remove_node(class RGE_Static_Object *,struct
   RGE_Object_Node *) */

void __thiscall
RGE_Object_List::remove_node
          (RGE_Object_List *this,RGE_Static_Object *param_1,RGE_Object_Node *param_2)
{
  RGE_Object_Node *pRVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar1 = this->list;
  if (pRVar1 != (RGE_Object_Node *)0x0) {
    if (param_2 == (RGE_Object_Node *)0x0) {
      pRVar2 = pRVar1->node;
      param_2 = pRVar1;
      while (pRVar2 != param_1) {
        param_2 = param_2->next;
        if (param_2 == (RGE_Object_Node *)0x0) {
          return;
        }
        pRVar2 = param_2->node;
      }
    }
    if (param_2->prev == (RGE_Object_Node *)0x0) {
      this->list = param_2->next;
    }
    else {
      param_2->prev->next = param_2->next;
    }
    if (param_2->next != (RGE_Object_Node *)0x0) {
      param_2->next->prev = param_2->prev;
    }
    free(param_2);
    this->number_of_objects = this->number_of_objects + -1;
  }
  return;
}

// --------------------------------------------------

// Function: invert
// Address: 00462fd0
/* protected: void __thiscall RGE_Object_List::invert(void) */

void __thiscall RGE_Object_List::invert(RGE_Object_List *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_Node *pRVar2;
  RGE_Object_Node *pRVar3;
  
  pRVar3 = this->list;
  pRVar2 = (RGE_Object_Node *)0x0;
  while (pRVar1 = pRVar3, pRVar1 != (RGE_Object_Node *)0x0) {
    this->list = pRVar1->next;
    pRVar1->next = pRVar2;
    if (pRVar2 != (RGE_Object_Node *)0x0) {
      pRVar2->prev = pRVar1;
    }
    pRVar1->prev = (RGE_Object_Node *)0x0;
    pRVar2 = pRVar1;
    pRVar3 = this->list;
  }
  this->list = pRVar2;
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 00463000
/* public: void __thiscall RGE_Object_List::draw(class TDrawArea *,short,short,unsigned char) */

void __thiscall
RGE_Object_List::draw
          (RGE_Object_List *this,TDrawArea *param_1,short param_2,short param_3,uchar param_4)
{
  RGE_Object_Node *pRVar1;
  RGE_Static_Object *pRVar2;
  RGE_Player *pRVar3;
  RGE_Object_Node *pRVar4;
  bool bVar5;
  RGE_Color_Table *pRVar6;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  pRVar1 = this->list;
  do {
    if (pRVar1 == (RGE_Object_Node *)0x0) {
      return;
    }
    pRVar2 = pRVar1->node;
    if (pRVar2 != (RGE_Static_Object *)0x0) {
      pRVar3 = pRVar2->owner;
      bVar5 = true;
      pRVar6 = pRVar3->color_table;
      switch(pRVar2->master_obj->fog_flag) {
      case '\0':
        if (param_4 != '\0') {
LAB_0046303d:
          bVar5 = false;
        }
        break;
      case '\x02':
        if ((param_4 != '\0') && (2 < pRVar2->object_state)) goto LAB_0046303d;
        break;
      case '\x03':
        bVar5 = false;
        if ((param_4 != '\0') &&
           (pRVar3->world->players[pRVar3->world->curr_player]->mutualAlly[pRVar3->id] != 0)) {
          pRVar6 = (RGE_Color_Table *)pRVar2[1].master_obj;
          bVar5 = true;
        }
        break;
      case '\x04':
        if ((param_4 != '\0') && (1 < this->number_of_objects)) {
          for (pRVar4 = this->list; pRVar4 != (RGE_Object_Node *)0x0; pRVar4 = pRVar4->next) {
            if (pRVar4->node->type == '\x19') goto LAB_0046303d;
          }
        }
      }
      if (bVar5) {
        (**(code **)(pRVar2->_padding_ + 0xc))(param_1,_param_2,_param_3,pRVar6);
      }
    }
    pRVar1 = pRVar1->next;
  } while( true );
}

// --------------------------------------------------

// Function: shadow_draw
// Address: 00463100
/* public: void __thiscall RGE_Object_List::shadow_draw(class TDrawArea *,short,short,unsigned
   char,unsigned char) */

void __thiscall
RGE_Object_List::shadow_draw
          (RGE_Object_List *this,TDrawArea *param_1,short param_2,short param_3,uchar param_4,
          uchar param_5)
{
  RGE_Static_Object *pRVar1;
  RGE_Object_Node *pRVar2;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  undefined3 in_stack_00000011;
  
  pRVar2 = this->list;
  if (param_5 == '\0') {
    for (; pRVar2 != (RGE_Object_Node *)0x0; pRVar2 = pRVar2->next) {
      if (pRVar2->node != (RGE_Static_Object *)0x0) {
        (**(code **)(pRVar2->node->_padding_ + 0x10))(param_1,_param_2,_param_3,_param_4);
      }
    }
  }
  else if (pRVar2 != (RGE_Object_Node *)0x0) {
    do {
      pRVar1 = pRVar2->node;
      if ((pRVar1 != (RGE_Static_Object *)0x0) && (pRVar1->master_obj->fog_flag != '\0')) {
        (**(code **)(pRVar1->_padding_ + 0x10))(param_1,_param_2,_param_3,_param_4);
      }
      pRVar2 = pRVar2->next;
    } while (pRVar2 != (RGE_Object_Node *)0x0);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: normal_draw
// Address: 00463180
/* public: void __thiscall RGE_Object_List::normal_draw(class TDrawArea *,short,short,unsigned char)
    */

void __thiscall
RGE_Object_List::normal_draw
          (RGE_Object_List *this,TDrawArea *param_1,short param_2,short param_3,uchar param_4)
{
  RGE_Object_Node **ppRVar1;
  RGE_Static_Object *pRVar2;
  RGE_Object_Node *pRVar3;
  RGE_Object_Node *pRVar4;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  pRVar3 = sort(this);
  if (param_4 == '\0') {
    pRVar4 = pRVar3;
    if (pRVar3 == (RGE_Object_Node *)0x0) {
      return;
    }
    do {
      if (pRVar4->node != (RGE_Static_Object *)0x0) {
        (**(code **)(pRVar4->node->_padding_ + 0x14))(param_1,_param_2,_param_3);
      }
      ppRVar1 = &pRVar4->next;
      pRVar4 = *ppRVar1;
    } while (*ppRVar1 != (RGE_Object_Node *)0x0);
  }
  else {
    pRVar4 = pRVar3;
    if (pRVar3 == (RGE_Object_Node *)0x0) {
      return;
    }
    do {
      pRVar2 = pRVar4->node;
      if ((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->master_obj->fog_flag != '\0')) {
        (**(code **)(pRVar2->_padding_ + 0x14))(param_1,_param_2,_param_3);
      }
      ppRVar1 = &pRVar4->next;
      pRVar4 = *ppRVar1;
    } while (*ppRVar1 != (RGE_Object_Node *)0x0);
  }
  while (pRVar3 != (RGE_Object_Node *)0x0) {
    pRVar4 = pRVar3->next;
    free(pRVar3);
    pRVar3 = pRVar4;
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 00463210
/* public: void __thiscall RGE_Object_List::update(void) */

void __thiscall RGE_Object_List::update(RGE_Object_List *this)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_Node *pRVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = 0;
  pRVar1 = this->list;
  while (pRVar2 = pRVar1, pRVar2 != (RGE_Object_Node *)0x0) {
    pRVar1 = pRVar2->next;
    if (pRVar2->node != (RGE_Static_Object *)0x0) {
      cVar3 = (**(code **)(pRVar2->node->_padding_ + 0x24))();
      if (cVar3 != '\0') {
        (**(code **)(pRVar2->node->_padding_ + 8))();
      }
      iVar4 = iVar4 + 1;
      if ((9 < iVar4) && (iVar4 = 0, MouseSystem != (TMousePointer *)0x0)) {
        TMousePointer::Poll(MouseSystem);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: sort
// Address: 00463260
/* WARNING: Variable defined which should be unmapped: sorted */
/* public: struct RGE_Object_Node * __thiscall RGE_Object_List::sort(void) */

RGE_Object_Node * __thiscall RGE_Object_List::sort(RGE_Object_List *this)
{
  byte bVar1;
  byte bVar2;
  RGE_Object_Node *pRVar3;
  RGE_Object_Node **ppRVar4;
  RGE_Object_Node *pRVar5;
  RGE_Object_Node *sorted;
  RGE_Object_Node *local_4;
  
  pRVar3 = this->list;
  local_4 = (RGE_Object_Node *)0x0;
  do {
    if (pRVar3 == (RGE_Object_Node *)0x0) {
      return local_4;
    }
    ppRVar4 = &local_4;
    bVar1 = pRVar3->node->master_obj->sort_number;
    for (pRVar5 = local_4; pRVar5 != (RGE_Object_Node *)0x0; pRVar5 = pRVar5->next) {
      bVar2 = pRVar5->node->master_obj->sort_number;
      if ((bVar2 < bVar1) ||
         ((bVar2 == bVar1 && (pRVar3->node->screen_y_offset < pRVar5->node->screen_y_offset))))
      break;
      ppRVar4 = &pRVar5->next;
    }
    pRVar5 = (RGE_Object_Node *)calloc(1,0x10);
    pRVar5->next = *ppRVar4;
    if (*ppRVar4 != (RGE_Object_Node *)0x0) {
      pRVar5->prev = (*ppRVar4)->prev;
      (*ppRVar4)->prev = pRVar5;
    }
    pRVar5->node = pRVar3->node;
    *ppRVar4 = pRVar5;
    pRVar3 = pRVar3->next;
  } while( true );
}

// --------------------------------------------------

// Function: find_by_group
// Address: 004632e0
/* public: class RGE_Static_Object * __thiscall RGE_Object_List::find_by_group(long) */

RGE_Static_Object * __thiscall RGE_Object_List::find_by_group(RGE_Object_List *this,long param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = (RGE_Static_Object *)this->list;
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return (RGE_Static_Object *)0x0;
  }
  while ((pRVar1->_padding_ == 0 || (*(short *)(*(int *)(pRVar1->_padding_ + 8) + 0x14) != param_1))
        ) {
    pRVar1 = (RGE_Static_Object *)pRVar1->id;
    if (pRVar1 == (RGE_Static_Object *)0x0) {
      return pRVar1;
    }
  }
  return (RGE_Static_Object *)pRVar1->_padding_;
}

// --------------------------------------------------

// Function: find_by_group
// Address: 00463310
/* WARNING: Variable defined which should be unmapped: diff_x */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class RGE_Static_Object * __thiscall
   RGE_Object_List::find_by_group(long,float,float,unsigned char,unsigned char,class
   RGE_Static_Object *) */

RGE_Static_Object * __thiscall
RGE_Object_List::find_by_group
          (RGE_Object_List *this,long param_1,float param_2,float param_3,uchar param_4,
          uchar param_5,RGE_Static_Object *param_6)
{
  RGE_Static_Object *pRVar1;
  float fVar2;
  RGE_Static_Object *pRVar3;
  float fVar4;
  RGE_Static_Object *this_00;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  RGE_Object_Node *pRVar9;
  float diff_x;
  RGE_Static_Object *found_obj;
  RGE_Static_Object *local_4;
  
  this_00 = param_6;
  if (((param_2 <= _DAT_00570c30) || (param_3 <= _DAT_00570c30)) ||
     (param_6 == (RGE_Static_Object *)0x0)) {
    uVar8 = 0xffffffff;
  }
  else {
    iVar6 = __ftol();
    iVar7 = __ftol();
    bVar5 = RGE_Static_Object::lookupZone(param_6,iVar7,iVar6);
    uVar8 = (uint)bVar5;
  }
  pRVar9 = this->list;
  local_4 = (RGE_Static_Object *)0x0;
  param_6 = (RGE_Static_Object *)0xbf800000;
  if (pRVar9 == (RGE_Object_Node *)0x0) {
    return (RGE_Static_Object *)0x0;
  }
  do {
    pRVar1 = pRVar9->node;
    if (((pRVar1 != (RGE_Static_Object *)0x0) && (pRVar1->master_obj->object_group == param_1)) &&
       ((param_4 == '\0' || (pRVar1->object_state == param_5)))) {
      if ((param_2 == _DAT_00570c30) || (param_3 == _DAT_00570c30)) {
        return pRVar9->node;
      }
      if (-1 < (int)uVar8) {
        iVar6 = __ftol();
        iVar7 = __ftol();
        bVar5 = RGE_Static_Object::lookupZone(this_00,iVar7,iVar6);
        if (bVar5 != uVar8) goto LAB_0046345a;
      }
      pRVar1 = pRVar9->node;
      fVar4 = param_2 - pRVar1->world_x;
      fVar2 = param_3 - pRVar1->world_y;
      pRVar3 = (RGE_Static_Object *)(fVar2 * fVar2 + fVar4 * fVar4);
      if (((float)param_6 == _DAT_00570c30) || ((float)pRVar3 < (float)param_6)) {
        param_6 = pRVar3;
        local_4 = pRVar1;
      }
    }
LAB_0046345a:
    pRVar9 = pRVar9->next;
    if (pRVar9 == (RGE_Object_Node *)0x0) {
      return local_4;
    }
  } while( true );
}

// --------------------------------------------------

// Function: find_by_id
// Address: 00463490
/* public: class RGE_Static_Object * __thiscall RGE_Object_List::find_by_id(long) */

RGE_Static_Object * __thiscall RGE_Object_List::find_by_id(RGE_Object_List *this,long param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = (RGE_Static_Object *)this->list;
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    return (RGE_Static_Object *)0x0;
  }
  while ((pRVar1->_padding_ == 0 || (*(int *)(pRVar1->_padding_ + 4) != param_1))) {
    pRVar1 = (RGE_Static_Object *)pRVar1->id;
    if (pRVar1 == (RGE_Static_Object *)0x0) {
      return pRVar1;
    }
  }
  return (RGE_Static_Object *)pRVar1->_padding_;
}

// --------------------------------------------------

// Function: find_by_master_id
// Address: 004634c0
/* WARNING: Variable defined which should be unmapped: diff_x */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class RGE_Static_Object * __thiscall
   RGE_Object_List::find_by_master_id(long,float,float,unsigned char,unsigned char,class
   RGE_Static_Object *) */

RGE_Static_Object * __thiscall
RGE_Object_List::find_by_master_id
          (RGE_Object_List *this,long param_1,float param_2,float param_3,uchar param_4,
          uchar param_5,RGE_Static_Object *param_6)
{
  RGE_Static_Object *pRVar1;
  float fVar2;
  RGE_Static_Object *pRVar3;
  float fVar4;
  RGE_Static_Object *this_00;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  RGE_Object_Node *pRVar9;
  float diff_x;
  RGE_Static_Object *found_obj;
  RGE_Static_Object *local_4;
  
  this_00 = param_6;
  if (((param_2 <= _DAT_00570c30) || (param_3 <= _DAT_00570c30)) ||
     (param_6 == (RGE_Static_Object *)0x0)) {
    uVar8 = 0xffffffff;
  }
  else {
    iVar6 = __ftol();
    iVar7 = __ftol();
    bVar5 = RGE_Static_Object::lookupZone(param_6,iVar7,iVar6);
    uVar8 = (uint)bVar5;
  }
  pRVar9 = this->list;
  local_4 = (RGE_Static_Object *)0x0;
  param_6 = (RGE_Static_Object *)0xbf800000;
  if (pRVar9 == (RGE_Object_Node *)0x0) {
    return (RGE_Static_Object *)0x0;
  }
  do {
    pRVar1 = pRVar9->node;
    if (((pRVar1 != (RGE_Static_Object *)0x0) && (pRVar1->master_obj->id == param_1)) &&
       ((param_4 == '\0' || (pRVar1->object_state == param_5)))) {
      if ((param_2 == _DAT_00570c30) || (param_3 == _DAT_00570c30)) {
        return pRVar9->node;
      }
      if (-1 < (int)uVar8) {
        iVar6 = __ftol();
        iVar7 = __ftol();
        bVar5 = RGE_Static_Object::lookupZone(this_00,iVar7,iVar6);
        if (bVar5 != uVar8) goto LAB_0046360a;
      }
      pRVar1 = pRVar9->node;
      fVar4 = param_2 - pRVar1->world_x;
      fVar2 = param_3 - pRVar1->world_y;
      pRVar3 = (RGE_Static_Object *)(fVar2 * fVar2 + fVar4 * fVar4);
      if (((float)param_6 == _DAT_00570c30) || ((float)pRVar3 < (float)param_6)) {
        param_6 = pRVar3;
        local_4 = pRVar1;
      }
    }
LAB_0046360a:
    pRVar9 = pRVar9->next;
    if (pRVar9 == (RGE_Object_Node *)0x0) {
      return local_4;
    }
  } while( true );
}

// --------------------------------------------------

// Function: find_by_master_ids
// Address: 00463640
/* WARNING: Variable defined which should be unmapped: diff_x */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class RGE_Static_Object * __thiscall
   RGE_Object_List::find_by_master_ids(long,long,float,float,unsigned char,unsigned char,class
   RGE_Static_Object *) */

RGE_Static_Object * __thiscall
RGE_Object_List::find_by_master_ids
          (RGE_Object_List *this,long param_1,long param_2,float param_3,float param_4,uchar param_5
          ,uchar param_6,RGE_Static_Object *param_7)
{
  RGE_Static_Object *pRVar1;
  float fVar2;
  RGE_Static_Object *pRVar3;
  float fVar4;
  RGE_Static_Object *this_00;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  RGE_Object_Node *pRVar9;
  float diff_x;
  RGE_Static_Object *found_obj;
  RGE_Static_Object *local_4;
  
  this_00 = param_7;
  if (((param_7 == (RGE_Static_Object *)0x0) || (param_3 <= _DAT_00570c30)) ||
     (param_4 <= _DAT_00570c30)) {
    uVar8 = 0xffffffff;
  }
  else {
    iVar6 = __ftol();
    iVar7 = __ftol();
    bVar5 = RGE_Static_Object::lookupZone(param_7,iVar7,iVar6);
    uVar8 = (uint)bVar5;
  }
  pRVar9 = this->list;
  local_4 = (RGE_Static_Object *)0x0;
  param_7 = (RGE_Static_Object *)0xbf800000;
  if (pRVar9 == (RGE_Object_Node *)0x0) {
    return (RGE_Static_Object *)0x0;
  }
  do {
    pRVar1 = pRVar9->node;
    iVar6 = (int)pRVar1->master_obj->id;
    if (((pRVar1 != (RGE_Static_Object *)0x0) && ((iVar6 == param_1 || (iVar6 == param_2)))) &&
       ((param_5 == '\0' || (pRVar1->object_state == param_6)))) {
      if ((param_3 == _DAT_00570c30) && (param_4 == _DAT_00570c30)) {
        return pRVar9->node;
      }
      if (-1 < (int)uVar8) {
        iVar6 = __ftol();
        iVar7 = __ftol();
        bVar5 = RGE_Static_Object::lookupZone(this_00,iVar7,iVar6);
        if (bVar5 != uVar8) goto LAB_0046378c;
      }
      pRVar1 = pRVar9->node;
      fVar4 = param_3 - pRVar1->world_x;
      fVar2 = param_4 - pRVar1->world_y;
      pRVar3 = (RGE_Static_Object *)(fVar2 * fVar2 + fVar4 * fVar4);
      if (((float)param_7 == _DAT_00570c30) || ((float)pRVar3 < (float)param_7)) {
        param_7 = pRVar3;
        local_4 = pRVar1;
      }
    }
LAB_0046378c:
    pRVar9 = pRVar9->next;
    if (pRVar9 == (RGE_Object_Node *)0x0) {
      return local_4;
    }
  } while( true );
}

// --------------------------------------------------

// Function: find_by_type
// Address: 004637c0
/* WARNING: Variable defined which should be unmapped: dist */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class RGE_Static_Object * __thiscall RGE_Object_List::find_by_type(unsigned
   char,float,float,unsigned char,unsigned char) */

RGE_Static_Object * __thiscall
RGE_Object_List::find_by_type
          (RGE_Object_List *this,uchar param_1,float param_2,float param_3,uchar param_4,
          uchar param_5)
{
  RGE_Static_Object *pRVar1;
  float fVar2;
  float fVar3;
  RGE_Object_Node *pRVar4;
  RGE_Static_Object *pRVar5;
  RGE_Static_Object *pRVar6;
  float dist;
  float local_4;
  
  pRVar4 = this->list;
  pRVar5 = (RGE_Static_Object *)0x0;
  local_4 = -1.0;
  if (pRVar4 == (RGE_Object_Node *)0x0) {
    return (RGE_Static_Object *)0x0;
  }
  do {
    pRVar1 = pRVar4->node;
    pRVar6 = pRVar5;
    fVar2 = local_4;
    if (((pRVar1 != (RGE_Static_Object *)0x0) && (pRVar1->type == param_1)) &&
       ((param_4 == '\0' || (pRVar1->object_state == param_5)))) {
      if ((param_2 == _DAT_00570c30) && (param_3 == _DAT_00570c30)) {
        return pRVar4->node;
      }
      fVar3 = param_2 - pRVar1->world_x;
      fVar2 = param_3 - pRVar1->world_y;
      fVar2 = fVar2 * fVar2 + fVar3 * fVar3;
      pRVar6 = pRVar1;
      if ((local_4 != _DAT_00570c30) && (local_4 <= fVar2)) {
        pRVar6 = pRVar5;
        fVar2 = local_4;
      }
    }
    local_4 = fVar2;
    pRVar4 = pRVar4->next;
    pRVar5 = pRVar6;
    if (pRVar4 == (RGE_Object_Node *)0x0) {
      return pRVar6;
    }
  } while( true );
}

// --------------------------------------------------

// Function: save
// Address: 00463890
/* WARNING: Variable defined which should be unmapped: finished */
/* public: void __thiscall RGE_Object_List::save(int) */

void __thiscall RGE_Object_List::save(RGE_Object_List *this,int param_1)
{
  RGE_Object_Node *pRVar1;
  uchar finished;
  undefined4 uStack_4;
  
  pRVar1 = this->list;
  uStack_4 = (uint)this & 0xffffff;
  for (; pRVar1 != (RGE_Object_Node *)0x0; pRVar1 = pRVar1->next) {
    if (pRVar1->node != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->node->_padding_ + 0x30))(param_1);
    }
  }
  rge_write(param_1,(void *)((int)&uStack_4 + 3),1);
  return;
}

// --------------------------------------------------

// Function: load_list
// Address: 004638d0
/* public: void __thiscall RGE_Object_List::load_list(int,class RGE_Game_World *) */

void __thiscall
RGE_Object_List::load_list(RGE_Object_List *this,int param_1,RGE_Game_World *param_2)
{
  RGE_Game_World *pRVar1;
  
  pRVar1 = param_2;
  while( true ) {
    rge_read(param_1,&param_2,1);
    if ((char)param_2 == '\0') break;
    (**(code **)this->_padding_)(param_2,param_1,pRVar1);
  }
  invert(this);
  return;
}

// --------------------------------------------------

// Function: rehook_list
// Address: 00463910
/* public: void __thiscall RGE_Object_List::rehook_list(void) */

void __thiscall RGE_Object_List::rehook_list(RGE_Object_List *this)
{
  RGE_Object_Node *pRVar1;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Object_Node *)0x0; pRVar1 = pRVar1->next) {
    (**(code **)(pRVar1->node->_padding_ + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: load
// Address: 00463930
/* protected: virtual void __thiscall RGE_Object_List::load(unsigned char,int,class RGE_Game_World
   *) */

void __thiscall
RGE_Object_List::load(RGE_Object_List *this,uchar param_1,int param_2,RGE_Game_World *param_3)
{
  RGE_Static_Object *this_00;
  RGE_Animated_Object *this_01;
  RGE_Doppleganger_Object *this_02;
  RGE_Moving_Object *this_03;
  RGE_Missile_Object *this_04;
  RGE_Action_Object *this_05;
  RGE_Combat_Object *this_06;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055de1d;
  *unaff_FS_OFFSET = &local_c;
  switch(param_1) {
  case '\n':
    this_00 = (RGE_Static_Object *)operator_new(0x88);
    local_4 = 0;
    if (this_00 != (RGE_Static_Object *)0x0) {
      RGE_Static_Object::RGE_Static_Object(this_00,param_2,param_3,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case '\x14':
    this_01 = (RGE_Animated_Object *)operator_new(0x8c);
    local_4 = 1;
    if (this_01 != (RGE_Animated_Object *)0x0) {
      RGE_Animated_Object::RGE_Animated_Object(this_01,param_2,param_3,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case '\x19':
    this_02 = (RGE_Doppleganger_Object *)operator_new(0xb0);
    local_4 = 2;
    if (this_02 != (RGE_Doppleganger_Object *)0x0) {
      RGE_Doppleganger_Object::RGE_Doppleganger_Object(this_02,param_2,param_3,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case '\x1e':
    this_03 = (RGE_Moving_Object *)operator_new(0x180);
    local_4 = 3;
    if (this_03 != (RGE_Moving_Object *)0x0) {
      RGE_Moving_Object::RGE_Moving_Object(this_03,param_2,param_3,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case '(':
    this_05 = (RGE_Action_Object *)operator_new(0x194);
    local_4 = 5;
    if (this_05 != (RGE_Action_Object *)0x0) {
      RGE_Action_Object::RGE_Action_Object(this_05,param_2,param_3,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
    break;
  case '2':
    this_06 = (RGE_Combat_Object *)operator_new(0x1c4);
    local_4 = 6;
    if (this_06 != (RGE_Combat_Object *)0x0) {
      RGE_Combat_Object::RGE_Combat_Object(this_06,param_2,param_3,1);
    }
    break;
  case '<':
    this_04 = (RGE_Missile_Object *)operator_new(0x1c8);
    local_4 = 4;
    if (this_04 != (RGE_Missile_Object *)0x0) {
      RGE_Missile_Object::RGE_Missile_Object(this_04,param_2,param_3,1);
      *unaff_FS_OFFSET = local_c;
      return;
    }
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------


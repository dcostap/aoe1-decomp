// Class: RGE_Active_Sprite_List
// Size:  0xC
//
// VTable Layout:
// [00] `vector_deleting_destructor'
// [01] frame
// [02] update
// [03] draw
// [04] normal_draw
// [05] shadow_draw
// [06] is_animating
// [07] set_frame
// [08] frame_passed
// [09] looped
// [10] get_facetindex
// [11] load_node
// [12] `scalar_deleting_destructor'
// [13] set_offset
// [14] save
// [15] update
// [16] draw
// [17] normal_draw
// [18] shadow_draw
// [19] what_frame
// [20] is_animating
// [21] set_frame
// [22] frame_passed
// [23] looped
// [24] get_facetindex
// [25] get_frame
// [26] setToFirstFrame
//
// Member Layout:
// [0x004] RGE_Active_Sprite_Node * list
// [0x008] RGE_Static_Object * owner
// ----------------------------------------------------------------

// Function: RGE_Active_Sprite_List
// Address: 0041a640
void __thiscall
RGE_Active_Sprite_List::RGE_Active_Sprite_List
          (RGE_Active_Sprite_List *this,RGE_Static_Object *param_1)
{
  this->_padding_ = (int)&_vftable_;
  this->list = (RGE_Active_Sprite_Node *)0x0;
  this->owner = param_1;
  return;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0041a660
void * __thiscall
RGE_Active_Sprite_List::_vector_deleting_destructor_(RGE_Active_Sprite_List *this,uint param_1)
{
  ~RGE_Active_Sprite_List(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Active_Sprite_List
// Address: 0041a680
void __thiscall RGE_Active_Sprite_List::~RGE_Active_Sprite_List(RGE_Active_Sprite_List *this)
{
  this->_padding_ = (int)&_vftable_;
  delete_list(this);
  return;
}

// --------------------------------------------------

// Function: load
// Address: 0041a690
void __thiscall
RGE_Active_Sprite_List::load(RGE_Active_Sprite_List *this,int param_1,RGE_Sprite **param_2)
{
  code *pcVar1;
  RGE_Active_Sprite_Node *pRVar2;
  RGE_Sprite **ppRVar3;
  char cVar4;
  RGE_Active_Sprite_Node *pRVar5;
  
  ppRVar3 = param_2;
  pcVar1 = *(code **)(this->_padding_ + 0x2c);
  do {
    rge_read(param_1,&param_2,1);
    cVar4 = (*pcVar1)(param_1,param_2,ppRVar3);
  } while (cVar4 != '\0');
  pRVar2 = this->list;
  pRVar5 = (RGE_Active_Sprite_Node *)0x0;
  while (pRVar2 != (RGE_Active_Sprite_Node *)0x0) {
    pRVar2 = this->list->next;
    this->list->next = pRVar5;
    pRVar5 = this->list;
    this->list = pRVar2;
  }
  this->list = pRVar5;
  return;
}

// --------------------------------------------------

// Function: load_node
// Address: 0041a6f0
uchar __thiscall
RGE_Active_Sprite_List::load_node
          (RGE_Active_Sprite_List *this,int param_1,uchar param_2,RGE_Sprite **param_3)
{
  RGE_Active_Sprite_Node *pRVar1;
  RGE_Active_Animated_Sprite *this_00;
  RGE_Active_Sprite *pRVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055c976;
  *unaff_FS_OFFSET = &local_c;
  if (param_2 == '\0') {
    *unaff_FS_OFFSET = local_c;
    return '\0';
  }
  if (param_2 == '\x01') {
    pRVar1 = (RGE_Active_Sprite_Node *)calloc(0xc,1);
    pRVar2 = (RGE_Active_Sprite *)operator_new(0x14);
    local_4 = 0;
    if (pRVar2 != (RGE_Active_Sprite *)0x0) {
      pRVar2 = (RGE_Active_Sprite *)RGE_Active_Sprite::RGE_Active_Sprite(pRVar2,param_1,param_3);
      pRVar1->node = pRVar2;
      pRVar1->next = this->list;
      this->list = pRVar1;
      *unaff_FS_OFFSET = local_c;
      return '\x01';
    }
  }
  else {
    if (param_2 != '\x02') goto LAB_0041a7e8;
    pRVar1 = (RGE_Active_Sprite_Node *)calloc(0xc,1);
    this_00 = (RGE_Active_Animated_Sprite *)operator_new(0x28);
    local_4 = 1;
    if (this_00 != (RGE_Active_Animated_Sprite *)0x0) {
      pRVar2 = (RGE_Active_Sprite *)
               RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(this_00,param_1,param_3);
      pRVar1->node = pRVar2;
      pRVar1->next = this->list;
      this->list = pRVar1;
      *unaff_FS_OFFSET = local_c;
      return '\x01';
    }
  }
  pRVar1->node = (RGE_Active_Sprite *)0x0;
  pRVar1->next = this->list;
  this->list = pRVar1;
LAB_0041a7e8:
  *unaff_FS_OFFSET = local_c;
  return '\x01';
}

// --------------------------------------------------

// Function: save
// Address: 0041a820
void __thiscall RGE_Active_Sprite_List::save(RGE_Active_Sprite_List *this,int param_1)
{
  RGE_Active_Sprite_Node *pRVar1;
  uchar ender;
  undefined4 uStack_4;
  
  pRVar1 = this->list;
  uStack_4 = (uint)this & 0xffffff;
  for (; pRVar1 != (RGE_Active_Sprite_Node *)0x0; pRVar1 = pRVar1->next) {
    (**(code **)(pRVar1->node->_padding_ + 8))(param_1);
  }
  rge_write(param_1,(void *)((int)&uStack_4 + 3),1);
  return;
}

// --------------------------------------------------

// Function: delete_list
// Address: 0041a860
void __thiscall RGE_Active_Sprite_List::delete_list(RGE_Active_Sprite_List *this)
{
  RGE_Active_Sprite_Node *pRVar1;
  RGE_Active_Sprite_Node *pRVar2;
  int iVar3;
  
  pRVar2 = this->list;
  while (pRVar2 != (RGE_Active_Sprite_Node *)0x0) {
    pRVar1 = pRVar2->next;
    iVar3 = RGE_Active_Sprite::check_for_shadows(pRVar2->node);
    if ((iVar3 != 0) && (this->owner != (RGE_Static_Object *)0x0)) {
      RGE_Static_Object::remove_shadows(this->owner);
    }
    if (pRVar2->node != (RGE_Active_Sprite *)0x0) {
      (**(code **)pRVar2->node->_padding_)(1);
    }
    free(pRVar2);
    pRVar2 = pRVar1;
  }
  this->list = (RGE_Active_Sprite_Node *)0x0;
  return;
}

// --------------------------------------------------

// Function: copy_sprite_list
// Address: 0041a8b0
RGE_Active_Sprite_Node * __thiscall
RGE_Active_Sprite_List::copy_sprite_list(RGE_Active_Sprite_List *this)
{
  RGE_Active_Sprite_Node *pRVar1;
  RGE_Active_Sprite *pRVar2;
  RGE_Active_Sprite_Node *pRVar3;
  
  pRVar1 = this->list;
  this->list = (RGE_Active_Sprite_Node *)0x0;
  for (pRVar3 = pRVar1; pRVar3 != (RGE_Active_Sprite_Node *)0x0; pRVar3 = pRVar3->next) {
    pRVar2 = pRVar3->node;
    add_sprite(this,pRVar2->sprite,pRVar3->order,pRVar2->offset_x,pRVar2->offset_y);
  }
  pRVar3 = this->list;
  this->list = pRVar1;
  return pRVar3;
}

// --------------------------------------------------

// Function: use_sprite_list
// Address: 0041a8f0
void __thiscall
RGE_Active_Sprite_List::use_sprite_list
          (RGE_Active_Sprite_List *this,RGE_Active_Sprite_Node *param_1)
{
  delete_list(this);
  this->list = param_1;
  return;
}

// --------------------------------------------------

// Function: add_sprite
// Address: 0041a910
void __thiscall
RGE_Active_Sprite_List::add_sprite
          (RGE_Active_Sprite_List *this,RGE_Sprite *param_1,uchar param_2,long param_3,long param_4)
{
  int iVar1;
  RGE_Active_Sprite_Node *pRVar2;
  RGE_Active_Sprite_Node *pRVar3;
  RGE_Active_Sprite *pRVar4;
  RGE_Active_Sprite_Node **ppRVar5;
  
  if (param_1 != (RGE_Sprite *)0x0) {
    iVar1 = RGE_Sprite::check_for_shadows(param_1);
    if ((iVar1 != 0) && (this->owner != (RGE_Static_Object *)0x0)) {
      RGE_Static_Object::remove_shadows(this->owner);
    }
    ppRVar5 = &this->list;
    pRVar2 = this->list;
    for (pRVar3 = pRVar2; pRVar3 != (RGE_Active_Sprite_Node *)0x0; pRVar3 = pRVar3->next) {
      if (pRVar3->node->sprite == param_1) {
        pRVar3->count = pRVar3->count + '\x01';
        return;
      }
    }
    for (; (pRVar2 != (RGE_Active_Sprite_Node *)0x0 && (pRVar2->order <= param_2));
        pRVar2 = pRVar2->next) {
      ppRVar5 = &pRVar2->next;
    }
    pRVar3 = (RGE_Active_Sprite_Node *)calloc(0xc,1);
    pRVar4 = RGE_Sprite::make_active_sprite(param_1);
    iVar1 = pRVar4->_padding_;
    pRVar3->node = pRVar4;
    (**(code **)(iVar1 + 4))(param_3,param_4);
    pRVar3->order = param_2;
    pRVar3->next = *ppRVar5;
    *ppRVar5 = pRVar3;
  }
  return;
}

// --------------------------------------------------

// Function: remove_sprite
// Address: 0041a9b0
void __thiscall
RGE_Active_Sprite_List::remove_sprite(RGE_Active_Sprite_List *this,RGE_Sprite *param_1)
{
  RGE_Active_Sprite_Node **ppRVar1;
  int iVar2;
  RGE_Active_Sprite_Node *pRVar3;
  
  pRVar3 = this->list;
  ppRVar1 = &this->list;
  if (pRVar3 != (RGE_Active_Sprite_Node *)0x0) {
    while (pRVar3->node->sprite != param_1) {
      ppRVar1 = &pRVar3->next;
      pRVar3 = pRVar3->next;
      if (pRVar3 == (RGE_Active_Sprite_Node *)0x0) {
        return;
      }
    }
    if (pRVar3->count != '\0') {
      pRVar3->count = pRVar3->count + 0xff;
      return;
    }
    *ppRVar1 = pRVar3->next;
    iVar2 = RGE_Active_Sprite::check_for_shadows(pRVar3->node);
    if ((iVar2 != 0) && (this->owner != (RGE_Static_Object *)0x0)) {
      RGE_Static_Object::remove_shadows(this->owner);
    }
    if (pRVar3->node != (RGE_Active_Sprite *)0x0) {
      (**(code **)pRVar3->node->_padding_)(1);
    }
    free(pRVar3);
  }
  return;
}

// --------------------------------------------------

// Function: update
// Address: 0041aa20
void __thiscall
RGE_Active_Sprite_List::update(RGE_Active_Sprite_List *this,float param_1,float param_2)
{
  RGE_Active_Sprite_Node *pRVar1;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Active_Sprite_Node *)0x0; pRVar1 = pRVar1->next) {
    (**(code **)(pRVar1->node->_padding_ + 0xc))(param_1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0041aa50
void __thiscall
RGE_Active_Sprite_List::draw
          (RGE_Active_Sprite_List *this,short param_1,short param_2,short param_3,short param_4,
          short param_5,RGE_Color_Table *param_6,TDrawArea *param_7)
{
  RGE_Active_Sprite_Node *pRVar1;
  undefined2 in_stack_00000006;
  
  pRVar1 = this->list;
  if (pRVar1 != (RGE_Active_Sprite_Node *)0x0) {
    do {
      (**(code **)(pRVar1->node->_padding_ + 0x10))
                (_param_1,(int)param_2,(int)param_3,(int)param_4,(int)param_5,param_6,param_7);
      pRVar1 = pRVar1->next;
    } while (pRVar1 != (RGE_Active_Sprite_Node *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: normal_draw
// Address: 0041aaa0
void __thiscall
RGE_Active_Sprite_List::normal_draw
          (RGE_Active_Sprite_List *this,short param_1,short param_2,short param_3,
          RGE_Color_Table *param_4,TDrawArea *param_5)
{
  RGE_Active_Sprite_Node *pRVar1;
  undefined2 in_stack_00000006;
  
  pRVar1 = this->list;
  if (pRVar1 != (RGE_Active_Sprite_Node *)0x0) {
    do {
      (**(code **)(pRVar1->node->_padding_ + 0x14))
                (_param_1,(int)param_2,(int)param_3,param_4,param_5);
      pRVar1 = pRVar1->next;
    } while (pRVar1 != (RGE_Active_Sprite_Node *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: shadow_draw
// Address: 0041aae0
void __thiscall
RGE_Active_Sprite_List::shadow_draw
          (RGE_Active_Sprite_List *this,short param_1,short param_2,short param_3,
          RGE_Color_Table *param_4,TDrawArea *param_5,uchar param_6)
{
  RGE_Active_Sprite_Node *pRVar1;
  undefined2 in_stack_00000006;
  undefined3 in_stack_00000019;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Active_Sprite_Node *)0x0; pRVar1 = pRVar1->next) {
    (**(code **)(pRVar1->node->_padding_ + 0x18))
              (_param_1,(int)param_2,(int)param_3,param_4,param_5,_param_6);
  }
  return;
}

// --------------------------------------------------

// Function: frame
// Address: 0041ab20
short __thiscall RGE_Active_Sprite_List::frame(RGE_Active_Sprite_List *this,RGE_Sprite *param_1)
{
  short sVar1;
  RGE_Active_Sprite_Node *pRVar2;
  
  pRVar2 = this->list;
  if (pRVar2 == (RGE_Active_Sprite_Node *)0x0) {
    return 0;
  }
  do {
    if (pRVar2->node->sprite == param_1) {
      sVar1 = (**(code **)(pRVar2->node->_padding_ + 0x1c))();
      return sVar1;
    }
    pRVar2 = pRVar2->next;
  } while (pRVar2 != (RGE_Active_Sprite_Node *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: is_animating
// Address: 0041ab60
uchar __thiscall
RGE_Active_Sprite_List::is_animating(RGE_Active_Sprite_List *this,RGE_Sprite *param_1)
{
  uchar uVar1;
  RGE_Active_Sprite_Node *pRVar2;
  
  pRVar2 = this->list;
  if (pRVar2 == (RGE_Active_Sprite_Node *)0x0) {
    return '\0';
  }
  do {
    if (pRVar2->node->sprite == param_1) {
      uVar1 = (**(code **)(pRVar2->node->_padding_ + 0x20))();
      return uVar1;
    }
    pRVar2 = pRVar2->next;
  } while (pRVar2 != (RGE_Active_Sprite_Node *)0x0);
  return '\0';
}

// --------------------------------------------------

// Function: set_frame
// Address: 0041ab90
void __thiscall
RGE_Active_Sprite_List::set_frame(RGE_Active_Sprite_List *this,RGE_Sprite *param_1,short param_2)
{
  RGE_Active_Sprite_Node *pRVar1;
  undefined2 in_stack_0000000a;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Active_Sprite_Node *)0x0; pRVar1 = pRVar1->next) {
    if (pRVar1->node->sprite == param_1) {
      (**(code **)(pRVar1->node->_padding_ + 0x24))(_param_2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: frame_passed
// Address: 0041abc0
uchar __thiscall
RGE_Active_Sprite_List::frame_passed(RGE_Active_Sprite_List *this,RGE_Sprite *param_1,short param_2)
{
  uchar uVar1;
  RGE_Active_Sprite_Node *pRVar2;
  undefined2 in_stack_0000000a;
  
  pRVar2 = this->list;
  if (pRVar2 == (RGE_Active_Sprite_Node *)0x0) {
    return '\0';
  }
  do {
    if (pRVar2->node->sprite == param_1) {
      uVar1 = (**(code **)(pRVar2->node->_padding_ + 0x28))(_param_2);
      return uVar1;
    }
    pRVar2 = pRVar2->next;
  } while (pRVar2 != (RGE_Active_Sprite_Node *)0x0);
  return '\0';
}

// --------------------------------------------------

// Function: looped
// Address: 0041ac00
uchar __thiscall RGE_Active_Sprite_List::looped(RGE_Active_Sprite_List *this,RGE_Sprite *param_1)
{
  uchar uVar1;
  RGE_Active_Sprite_Node *pRVar2;
  
  pRVar2 = this->list;
  if (pRVar2 == (RGE_Active_Sprite_Node *)0x0) {
    return '\0';
  }
  do {
    if (pRVar2->node->sprite == param_1) {
      uVar1 = (**(code **)(pRVar2->node->_padding_ + 0x2c))();
      return uVar1;
    }
    pRVar2 = pRVar2->next;
  } while (pRVar2 != (RGE_Active_Sprite_Node *)0x0);
  return '\0';
}

// --------------------------------------------------

// Function: get_facetindex
// Address: 0041ac30
short __thiscall
RGE_Active_Sprite_List::get_facetindex
          (RGE_Active_Sprite_List *this,RGE_Sprite *param_1,short param_2)
{
  short sVar1;
  RGE_Active_Sprite_Node *pRVar2;
  undefined2 in_stack_0000000a;
  
  pRVar2 = this->list;
  if (pRVar2 == (RGE_Active_Sprite_Node *)0x0) {
    return 0;
  }
  do {
    if (pRVar2->node->sprite == param_1) {
      sVar1 = (**(code **)(pRVar2->node->_padding_ + 0x30))(_param_2);
      return sVar1;
    }
    pRVar2 = pRVar2->next;
  } while (pRVar2 != (RGE_Active_Sprite_Node *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: get_frame
// Address: 0041ac70
uchar __thiscall
RGE_Active_Sprite_List::get_frame
          (RGE_Active_Sprite_List *this,short *param_1,short *param_2,short *param_3,short *param_4,
          RGE_Sprite *param_5,long param_6)
{
  uchar uVar1;
  RGE_Active_Sprite_Node *pRVar2;
  
  pRVar2 = this->list;
  if (pRVar2 == (RGE_Active_Sprite_Node *)0x0) {
    return '\0';
  }
  do {
    if (pRVar2->node->sprite == param_5) {
      uVar1 = (**(code **)(pRVar2->node->_padding_ + 0x34))(param_1,param_2,param_3,param_4,param_6)
      ;
      return uVar1;
    }
    pRVar2 = pRVar2->next;
  } while (pRVar2 != (RGE_Active_Sprite_Node *)0x0);
  return '\0';
}

// --------------------------------------------------

// Function: get_lowest_draw_level
// Address: 0041acc0
uchar __thiscall RGE_Active_Sprite_List::get_lowest_draw_level(RGE_Active_Sprite_List *this)
{
  RGE_Active_Sprite_Node *pRVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = 0x14;
  for (pRVar1 = this->list; pRVar1 != (RGE_Active_Sprite_Node *)0x0; pRVar1 = pRVar1->next) {
    bVar2 = RGE_Active_Sprite::get_lowest_draw_level(pRVar1->node);
    if (bVar2 < bVar3) {
      bVar3 = bVar2;
    }
  }
  return bVar3;
}

// --------------------------------------------------

// Function: check_for_shadows
// Address: 0041acf0
int __thiscall RGE_Active_Sprite_List::check_for_shadows(RGE_Active_Sprite_List *this)
{
  int iVar1;
  RGE_Active_Sprite_Node *pRVar2;
  
  pRVar2 = this->list;
  if (pRVar2 == (RGE_Active_Sprite_Node *)0x0) {
    return 0;
  }
  do {
    iVar1 = RGE_Active_Sprite::check_for_shadows(pRVar2->node);
    if (iVar1 != 0) {
      return 1;
    }
    pRVar2 = pRVar2->next;
  } while (pRVar2 != (RGE_Active_Sprite_Node *)0x0);
  return 0;
}

// --------------------------------------------------


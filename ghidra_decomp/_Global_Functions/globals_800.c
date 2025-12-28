// GLOBAL FUNCTIONS PART 800
// Function: FUN_0041a1d3
// Address: 0041a1d3
// XREFS: None
RGE_Animated_Object * __thiscall FUN_0041a1d3(RGE_Animated_Object *param_1,byte param_2)
{
  RGE_Animated_Object::~RGE_Animated_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041a205
// Address: 0041a205
// XREFS: None
RGE_Animated_Object * __thiscall
FUN_0041a205(RGE_Animated_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c948;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Static_Object::RGE_Static_Object((RGE_Static_Object *)param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Animated_Object::_vftable_;
  if (param_4 != 0) {
    RGE_Animated_Object::setup(param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041a275
// Address: 0041a275
// XREFS: None
void __thiscall
FUN_0041a275(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  RGE_Static_Object::recycle_in_to_game(param_1,param_2,param_3,param_4,param_5,param_6);
  param_1[1]._padding_ = 0;
  RGE_Static_Object::set_sleep_flag(param_1,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_0041a2ba
// Address: 0041a2ba
// XREFS: None
undefined4 __thiscall
FUN_0041a2ba(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  RGE_Static_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  param_1->type = '\x14';
  param_1[1]._padding_ = 0;
  RGE_Static_Object::set_sleep_flag(param_1,'\0');
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041a303
// Address: 0041a303
// XREFS: None
undefined4 __thiscall FUN_0041a303(RGE_Static_Object *param_1,int param_2,RGE_Game_World *param_3)
{
  RGE_Static_Object::setup(param_1,param_2,param_3);
  param_1->type = '\x14';
  rge_read(param_2,param_1 + 1,4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041a343
// Address: 0041a343
// XREFS: None
uchar __fastcall FUN_0041a343(RGE_Static_Object *param_1)
{
  uchar uVar1;
  char cVar2;
  
  uVar1 = RGE_Static_Object::update(param_1);
  if (param_1->object_state == '\x03') {
    if (param_1->master_obj->death_sprite == (RGE_Sprite *)0x0) {
      (**(code **)(param_1->_padding_ + 0x5c))(5);
    }
    else {
      (**(code **)(param_1->_padding_ + 0x5c))(4);
    }
  }
  else if (param_1->object_state == '\x04') {
    cVar2 = (**(code **)(param_1->sprite_list->_padding_ + 0x18))(param_1->sprite);
    if (cVar2 == '\0') {
      param_1->object_state = '\x05';
      param_1[1]._padding_ = 0;
    }
  }
  (**(code **)(param_1->sprite_list->_padding_ + 8))
            (param_1->owner->world->world_time_delta_seconds,param_1[1]._padding_);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0041a3c7
// Address: 0041a3c7
// XREFS: None
void __thiscall FUN_0041a3c7(RGE_Static_Object *param_1,int param_2)
{
  RGE_Static_Object::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  return;
}

// --------------------------------------------------

// Function: FUN_0041a3f5
// Address: 0041a3f5
// XREFS: None
void __thiscall FUN_0041a3f5(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Static_Object::transform(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0041a40d
// Address: 0041a40d
// XREFS: None
void __thiscall
FUN_0041a40d(RGE_Static_Object *param_1,RGE_Action_Object *param_2,short param_3,uchar param_4)
{
  RGE_Static_Object::set_being_worked_on(param_1,param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0041a427
// Address: 0041a427
// XREFS: None
void __thiscall FUN_0041a427(RGE_Static_Object *param_1,RGE_Static_Object *param_2)
{
  RGE_Static_Object::release_being_worked_on(param_1,param_2);
  RGE_Static_Object::set_sleep_flag(param_1,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_0041a44a
// Address: 0041a44a
// XREFS: None
void FUN_0041a44a(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a453
// Address: 0041a453
// XREFS: None
void FUN_0041a453(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a463
// Address: 0041a463
// XREFS: None
void FUN_0041a463(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a473
// Address: 0041a473
// XREFS: None
void FUN_0041a473(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a481
// Address: 0041a481
// XREFS: None
void FUN_0041a481(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a493
// Address: 0041a493
// XREFS: None
void FUN_0041a493(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a4a1
// Address: 0041a4a1
// XREFS: None
void FUN_0041a4a1(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a4b1
// Address: 0041a4b1
// XREFS: None
undefined4 __fastcall FUN_0041a4b1(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_0041a4c6
// Address: 0041a4c6
// XREFS: None
undefined4 FUN_0041a4c6(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a4d3
// Address: 0041a4d3
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0041a4d3(void)
{
  return (float10)_DAT_0056ee00;
}

// --------------------------------------------------

// Function: FUN_0041a4e7
// Address: 0041a4e7
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0041a4e7(void)
{
  return (float10)_DAT_0056ee00;
}

// --------------------------------------------------

// Function: FUN_0041a4f7
// Address: 0041a4f7
// XREFS: None
undefined4 FUN_0041a4f7(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a505
// Address: 0041a505
// XREFS: None
undefined1 FUN_0041a505(void)
{
  return 0xff;
}

// --------------------------------------------------

// Function: FUN_0041a513
// Address: 0041a513
// XREFS: None
void FUN_0041a513(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a523
// Address: 0041a523
// XREFS: None
undefined1 FUN_0041a523(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a533
// Address: 0041a533
// XREFS: None
undefined1 FUN_0041a533(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a543
// Address: 0041a543
// XREFS: None
undefined4 FUN_0041a543(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a555
// Address: 0041a555
// XREFS: None
undefined4 FUN_0041a555(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a565
// Address: 0041a565
// XREFS: None
undefined4 FUN_0041a565(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a575
// Address: 0041a575
// XREFS: None
undefined4 FUN_0041a575(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a585
// Address: 0041a585
// XREFS: None
undefined4 FUN_0041a585(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a595
// Address: 0041a595
// XREFS: None
undefined4 FUN_0041a595(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a5a5
// Address: 0041a5a5
// XREFS: None
undefined4 FUN_0041a5a5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a5b5
// Address: 0041a5b5
// XREFS: None
undefined4 FUN_0041a5b5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a5c5
// Address: 0041a5c5
// XREFS: None
undefined4 FUN_0041a5c5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a5d5
// Address: 0041a5d5
// XREFS: None
undefined4 FUN_0041a5d5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a5e5
// Address: 0041a5e5
// XREFS: None
undefined4 FUN_0041a5e5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a5f5
// Address: 0041a5f5
// XREFS: None
void FUN_0041a5f5(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a603
// Address: 0041a603
// XREFS: None
void FUN_0041a603(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041a613
// Address: 0041a613
// XREFS: None
undefined4 FUN_0041a613(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a623
// Address: 0041a623
// XREFS: None
undefined4 FUN_0041a623(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041a635
// Address: 0041a635
// XREFS: None
void __thiscall FUN_0041a635(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = &RGE_Active_Sprite_List::_vftable_;
  param_1[1] = 0;
  param_1[2] = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0041a659
// Address: 0041a659
// XREFS: None
RGE_Active_Sprite_List * __thiscall FUN_0041a659(RGE_Active_Sprite_List *param_1,byte param_2)
{
  RGE_Active_Sprite_List::~RGE_Active_Sprite_List(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041a67e
// Address: 0041a67e
// XREFS: None
void __fastcall FUN_0041a67e(RGE_Active_Sprite_List *param_1)
{
  param_1->_padding_ = (int)&RGE_Active_Sprite_List::_vftable_;
  RGE_Active_Sprite_List::delete_list(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0041a68b
// Address: 0041a68b
// XREFS: None
void __thiscall FUN_0041a68b(int *param_1,int param_2,undefined4 param_3)
{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  
  uVar3 = param_3;
  pcVar1 = *(code **)(*param_1 + 0x2c);
  do {
    rge_read(param_2,&param_3,1);
    cVar4 = (*pcVar1)(param_2,param_3,uVar3);
  } while (cVar4 != '\0');
  iVar2 = param_1[1];
  iVar5 = 0;
  while (iVar2 != 0) {
    iVar2 = *(int *)(param_1[1] + 8);
    *(int *)(param_1[1] + 8) = iVar5;
    iVar5 = param_1[1];
    param_1[1] = iVar2;
  }
  param_1[1] = iVar5;
  return;
}

// --------------------------------------------------

// Function: FUN_0041a6eb
// Address: 0041a6eb
// XREFS: None
undefined4 __thiscall FUN_0041a6eb(int param_1,int param_2,uint param_3,RGE_Sprite **param_4)
{
  int iVar1;
  undefined4 *puVar2;
  RGE_Active_Animated_Sprite *this;
  undefined4 uVar3;
  RGE_Active_Sprite *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c976;
  *unaff_FS_OFFSET = &uStack_c;
  param_3 = param_3 & 0xff;
  if (param_3 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  if (param_3 == 1) {
    puVar2 = (undefined4 *)calloc(0xc,1);
    this_00 = (RGE_Active_Sprite *)operator_new(0x14);
    uStack_4 = 0;
    if (this_00 != (RGE_Active_Sprite *)0x0) {
      uVar3 = RGE_Active_Sprite::RGE_Active_Sprite(this_00,param_2,param_4);
      *puVar2 = uVar3;
      uVar3 = *(undefined4 *)(param_1 + 4);
      puVar2[2] = uVar3;
      *(undefined4 **)(param_1 + 4) = puVar2;
      *unaff_FS_OFFSET = uStack_c;
      return CONCAT31((int3)((uint)uVar3 >> 8),1);
    }
  }
  else {
    iVar1 = param_3 - 2;
    if (iVar1 != 0) goto LAB_0041a7e8;
    puVar2 = (undefined4 *)calloc(0xc,1);
    this = (RGE_Active_Animated_Sprite *)operator_new(0x28);
    uStack_4 = 1;
    if (this != (RGE_Active_Animated_Sprite *)0x0) {
      uVar3 = RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(this,param_2,param_4);
      *puVar2 = uVar3;
      uVar3 = *(undefined4 *)(param_1 + 4);
      puVar2[2] = uVar3;
      *(undefined4 **)(param_1 + 4) = puVar2;
      *unaff_FS_OFFSET = uStack_c;
      return CONCAT31((int3)((uint)uVar3 >> 8),1);
    }
  }
  *puVar2 = 0;
  iVar1 = *(int *)(param_1 + 4);
  puVar2[2] = iVar1;
  *(undefined4 **)(param_1 + 4) = puVar2;
LAB_0041a7e8:
  *unaff_FS_OFFSET = uStack_c;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_0041a811
// Address: 0041a811
// XREFS: None
void __thiscall FUN_0041a811(uint param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 uStack_4;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  uStack_4 = param_1 & 0xffffff;
  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[2]) {
    (**(code **)(*(int *)*puVar1 + 8))(param_2);
  }
  rge_write(param_2,(void *)((int)&uStack_4 + 3),1);
  return;
}

// --------------------------------------------------

// Function: FUN_0041a858
// Address: 0041a858
// XREFS: None
void __fastcall FUN_0041a858(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_1 + 4);
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[2];
    iVar3 = RGE_Active_Sprite::check_for_shadows((RGE_Active_Sprite *)*piVar2);
    if ((iVar3 != 0) && (*(RGE_Static_Object **)(param_1 + 8) != (RGE_Static_Object *)0x0)) {
      RGE_Static_Object::remove_shadows(*(RGE_Static_Object **)(param_1 + 8));
    }
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    free(piVar2);
    piVar2 = piVar1;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0041a8ac
// Address: 0041a8ac
// XREFS: None
RGE_Active_Sprite_Node * __fastcall FUN_0041a8ac(RGE_Active_Sprite_List *param_1)
{
  RGE_Active_Sprite_Node *pRVar1;
  RGE_Active_Sprite *pRVar2;
  RGE_Active_Sprite_Node *pRVar3;
  
  pRVar1 = param_1->list;
  param_1->list = (RGE_Active_Sprite_Node *)0x0;
  for (pRVar3 = pRVar1; pRVar3 != (RGE_Active_Sprite_Node *)0x0; pRVar3 = pRVar3->next) {
    pRVar2 = pRVar3->node;
    RGE_Active_Sprite_List::add_sprite
              (param_1,pRVar2->sprite,pRVar3->order,pRVar2->offset_x,pRVar2->offset_y);
  }
  pRVar3 = param_1->list;
  param_1->list = pRVar1;
  return pRVar3;
}

// --------------------------------------------------

// Function: FUN_0041a8ef
// Address: 0041a8ef
// XREFS: None
void __thiscall FUN_0041a8ef(RGE_Active_Sprite_List *param_1,RGE_Active_Sprite_Node *param_2)
{
  RGE_Active_Sprite_List::delete_list(param_1);
  param_1->list = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0041a903
// Address: 0041a903
// XREFS: None
void __thiscall
FUN_0041a903(int param_1,RGE_Sprite *param_2,byte param_3,undefined4 param_4,undefined4 param_5)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  RGE_Active_Sprite *pRVar5;
  int *piVar6;
  
  if (param_2 != (RGE_Sprite *)0x0) {
    iVar2 = RGE_Sprite::check_for_shadows(param_2);
    if ((iVar2 != 0) && (*(RGE_Static_Object **)(param_1 + 8) != (RGE_Static_Object *)0x0)) {
      RGE_Static_Object::remove_shadows(*(RGE_Static_Object **)(param_1 + 8));
    }
    piVar6 = (int *)(param_1 + 4);
    piVar3 = *(int **)(param_1 + 4);
    for (piVar1 = piVar3; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      if (*(RGE_Sprite **)(*piVar1 + 4) == param_2) {
        *(char *)((int)piVar1 + 5) = *(char *)((int)piVar1 + 5) + '\x01';
        return;
      }
    }
    for (; (piVar3 != (int *)0x0 && (*(byte *)(piVar3 + 1) <= param_3)); piVar3 = (int *)piVar3[2])
{
      piVar6 = piVar3 + 2;
    }
    puVar4 = (undefined4 *)calloc(0xc,1);
    pRVar5 = RGE_Sprite::make_active_sprite(param_2);
    iVar2 = pRVar5->_padding_;
    *puVar4 = pRVar5;
    (**(code **)(iVar2 + 4))(param_4,param_5);
    *(byte *)(puVar4 + 1) = param_3;
    puVar4[2] = *piVar6;
    *piVar6 = (int)puVar4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041a9ae
// Address: 0041a9ae
// XREFS: None
void __thiscall FUN_0041a9ae(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 4);
  piVar1 = (int *)(param_1 + 4);
  if (piVar3 != (int *)0x0) {
    while (*(int *)(*piVar3 + 4) != param_2) {
      piVar1 = piVar3 + 2;
      piVar3 = (int *)piVar3[2];
      if (piVar3 == (int *)0x0) {
        return;
      }
    }
    if (*(char *)((int)piVar3 + 5) != '\0') {
      *(char *)((int)piVar3 + 5) = *(char *)((int)piVar3 + 5) + -1;
      return;
    }
    *piVar1 = piVar3[2];
    iVar2 = RGE_Active_Sprite::check_for_shadows((RGE_Active_Sprite *)*piVar3);
    if ((iVar2 != 0) && (*(RGE_Static_Object **)(param_1 + 8) != (RGE_Static_Object *)0x0)) {
      RGE_Static_Object::remove_shadows(*(RGE_Static_Object **)(param_1 + 8));
    }
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    free(piVar3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041aa1f
// Address: 0041aa1f
// XREFS: None
void __thiscall FUN_0041aa1f(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[2]) {
    (**(code **)(*(int *)*puVar1 + 0xc))(param_2,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041aa48
// Address: 0041aa48
// XREFS: None
void __thiscall
FUN_0041aa48(int param_1,undefined4 param_2,short param_3,short param_4,short param_5,short param_6,
            undefined4 param_7,undefined4 param_8)
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 != (undefined4 *)0x0) {
    do {
      (**(code **)(*(int *)*puVar1 + 0x10))
                (param_2,(int)param_3,(int)param_4,(int)param_5,(int)param_6,param_7,param_8);
      puVar1 = (undefined4 *)puVar1[2];
    } while (puVar1 != (undefined4 *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041aa97
// Address: 0041aa97
// XREFS: None
void __thiscall
FUN_0041aa97(int param_1,undefined4 param_2,short param_3,short param_4,undefined4 param_5,
            undefined4 param_6)
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 != (undefined4 *)0x0) {
    do {
      (**(code **)(*(int *)*puVar1 + 0x14))(param_2,(int)param_3,(int)param_4,param_5,param_6);
      puVar1 = (undefined4 *)puVar1[2];
    } while (puVar1 != (undefined4 *)0x0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041aadb
// Address: 0041aadb
// XREFS: None
void __thiscall
FUN_0041aadb(int param_1,undefined4 param_2,short param_3,short param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[2]) {
    (**(code **)(*(int *)*puVar1 + 0x18))(param_2,(int)param_3,(int)param_4,param_5,param_6,param_7)
    ;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041ab51
// Address: 0041ab51
// XREFS: None
undefined4 __thiscall FUN_0041ab51(int param_1,int param_2)
{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  do {
    if (*(int *)(*piVar1 + 4) == param_2) {
      uVar2 = (**(code **)(*(int *)*piVar1 + 0x20))();
      return uVar2;
    }
    piVar1 = (int *)piVar1[2];
  } while (piVar1 != (int *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041ab8f
// Address: 0041ab8f
// XREFS: None
void __thiscall FUN_0041ab8f(int param_1,int param_2,undefined4 param_3)
{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 4); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
    if (((int *)*piVar1)[1] == param_2) {
      (**(code **)(*(int *)*piVar1 + 0x24))(param_3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041abbc
// Address: 0041abbc
// XREFS: None
undefined4 __thiscall FUN_0041abbc(int param_1,int param_2,undefined4 param_3)
{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  do {
    if (*(int *)(*piVar1 + 4) == param_2) {
      uVar2 = (**(code **)(*(int *)*piVar1 + 0x28))(param_3);
      return uVar2;
    }
    piVar1 = (int *)piVar1[2];
  } while (piVar1 != (int *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041abf4
// Address: 0041abf4
// XREFS: None
undefined4 __thiscall FUN_0041abf4(int param_1,int param_2)
{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  do {
    if (*(int *)(*piVar1 + 4) == param_2) {
      uVar2 = (**(code **)(*(int *)*piVar1 + 0x2c))();
      return uVar2;
    }
    piVar1 = (int *)piVar1[2];
  } while (piVar1 != (int *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041ac2f
// Address: 0041ac2f
// XREFS: None
undefined4 __thiscall FUN_0041ac2f(int param_1,int param_2,undefined4 param_3)
{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  do {
    if (*(int *)(*piVar1 + 4) == param_2) {
      uVar2 = (**(code **)(*(int *)*piVar1 + 0x30))(param_3);
      return uVar2;
    }
    piVar1 = (int *)piVar1[2];
  } while (piVar1 != (int *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041ac66
// Address: 0041ac66
// XREFS: None
undefined4 __thiscall
FUN_0041ac66(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6,undefined4 param_7)
{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  do {
    if (*(int *)(*piVar1 + 4) == param_6) {
      uVar2 = (**(code **)(*(int *)*piVar1 + 0x34))(param_2,param_3,param_4,param_5,param_7);
      return uVar2;
    }
    piVar1 = (int *)piVar1[2];
  } while (piVar1 != (int *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041acb8
// Address: 0041acb8
// XREFS: None
byte __fastcall FUN_0041acb8(int param_1)
{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = 0x14;
  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[2]) {
    bVar2 = RGE_Active_Sprite::get_lowest_draw_level((RGE_Active_Sprite *)*puVar1);
    if (bVar2 < bVar3) {
      bVar3 = bVar2;
    }
  }
  return bVar3;
}

// --------------------------------------------------

// Function: FUN_0041ace4
// Address: 0041ace4
// XREFS: None
undefined4 __fastcall FUN_0041ace4(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  do {
    iVar1 = RGE_Active_Sprite::check_for_shadows((RGE_Active_Sprite *)*puVar2);
    if (iVar1 != 0) {
      return 1;
    }
    puVar2 = (undefined4 *)puVar2[2];
  } while (puVar2 != (undefined4 *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041ad17
// Address: 0041ad17
// XREFS: None
void __thiscall FUN_0041ad17(undefined4 *param_1,undefined4 param_2)
{
  param_1[1] = param_2;
  *param_1 = &RGE_Active_Sprite::_vftable_;
  *(undefined1 *)(param_1 + 2) = 1;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0041ad3e
// Address: 0041ad3e
// XREFS: None
RGE_Active_Sprite * __thiscall FUN_0041ad3e(RGE_Active_Sprite *param_1,byte param_2)
{
  RGE_Active_Sprite::~RGE_Active_Sprite(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041ad5e
// Address: 0041ad5e
// XREFS: None
undefined4 * __thiscall FUN_0041ad5e(undefined4 *param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = param_2;
  *param_1 = &RGE_Active_Sprite::_vftable_;
  *(undefined1 *)(param_1 + 2) = 1;
  rge_read(param_2,&param_2,2);
  if ((short)param_2 < 0) {
    param_1[1] = 0;
  }
  else {
    param_1[1] = *(undefined4 *)(param_3 + (short)param_2 * 4);
  }
  rge_read(iVar1,param_1 + 3,4);
  rge_read(iVar1,param_1 + 4,4);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041adc7
// Address: 0041adc7
// XREFS: None
void __fastcall FUN_0041adc7(undefined4 *param_1)
{
  *param_1 = &RGE_Active_Sprite::_vftable_;
  return;
}

// --------------------------------------------------

// Function: FUN_0041add7
// Address: 0041add7
// XREFS: None
void __thiscall FUN_0041add7(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0041adf1
// Address: 0041adf1
// XREFS: None
void __thiscall FUN_0041adf1(int param_1,int param_2)
{
  rge_write(param_2,(void *)(param_1 + 8),1);
  rge_write(param_2,(void *)(*(int *)(param_1 + 4) + 0x72),2);
  rge_write(param_2,(void *)(param_1 + 0xc),4);
  rge_write(param_2,(void *)(param_1 + 0x10),4);
  return;
}

// --------------------------------------------------

// Function: FUN_0041ae4c
// Address: 0041ae4c
// XREFS: None
void FUN_0041ae4c(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041ae53
// Address: 0041ae53
// XREFS: None
void __thiscall
FUN_0041ae53(int param_1,short param_2,int param_3,int param_4,int param_5,int param_6,
            RGE_Color_Table *param_7,TDrawArea *param_8)
{
  RGE_Sprite::draw(*(RGE_Sprite **)(param_1 + 4),(int)param_2,0,param_3 + *(int *)(param_1 + 0xc),
                   param_4 + *(int *)(param_1 + 0x10),param_5 + *(int *)(param_1 + 0xc),
                   param_6 + *(int *)(param_1 + 0x10),param_7,param_8,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_0041aea3
// Address: 0041aea3
// XREFS: None
void __thiscall
FUN_0041aea3(int param_1,short param_2,int param_3,int param_4,RGE_Color_Table *param_5,
            TDrawArea *param_6)
{
  RGE_Sprite::normal_draw
            (*(RGE_Sprite **)(param_1 + 4),(int)param_2,0,*(int *)(param_1 + 0xc) + param_3,
             *(int *)(param_1 + 0x10) + param_4,param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_0041aee1
// Address: 0041aee1
// XREFS: None
void __thiscall
FUN_0041aee1(int param_1,short param_2,int param_3,int param_4,RGE_Color_Table *param_5,
            TDrawArea *param_6,uchar param_7)
{
  RGE_Sprite::shadow_draw
            (*(RGE_Sprite **)(param_1 + 4),(int)param_2,0,*(int *)(param_1 + 0xc) + param_3,
             *(int *)(param_1 + 0x10) + param_4,param_5,param_6,param_7);
  return;
}

// --------------------------------------------------

// Function: FUN_0041af26
// Address: 0041af26
// XREFS: None
undefined2 FUN_0041af26(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041af34
// Address: 0041af34
// XREFS: None
void FUN_0041af34(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041af43
// Address: 0041af43
// XREFS: None
undefined1 FUN_0041af43(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041af53
// Address: 0041af53
// XREFS: None
undefined1 FUN_0041af53(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041af65
// Address: 0041af65
// XREFS: None
undefined1 FUN_0041af65(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041af73
// Address: 0041af73
// XREFS: None
uint __thiscall FUN_0041af73(int param_1,short param_2)
{
  uint uStack_4;
  
  uStack_4 = 0;
  RGE_Sprite::get_facetindex(*(RGE_Sprite **)(param_1 + 4),(int)param_2,0,(long *)&uStack_4);
  return uStack_4 & 0xffff;
}

// --------------------------------------------------

// Function: FUN_0041afa7
// Address: 0041afa7
// XREFS: None
void __thiscall
FUN_0041afa7(int param_1,short *param_2,short *param_3,short *param_4,short *param_5,long param_6)
{
  RGE_Sprite::get_frame(*(RGE_Sprite **)(param_1 + 4),param_2,param_3,param_4,param_5,param_6,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0041afd6
// Address: 0041afd6
// XREFS: None
uchar __fastcall FUN_0041afd6(int param_1)
{
  uchar uVar1;
  
  if (*(RGE_Sprite **)(param_1 + 4) != (RGE_Sprite *)0x0) {
    uVar1 = RGE_Sprite::get_lowest_draw_level(*(RGE_Sprite **)(param_1 + 4));
    return uVar1;
  }
  return '\x14';
}

// --------------------------------------------------

// Function: FUN_0041afef
// Address: 0041afef
// XREFS: None
void FUN_0041afef(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0041aff1
// Address: 0041aff1
// XREFS: None
int __fastcall FUN_0041aff1(int param_1)
{
  int iVar1;
  
  if (*(RGE_Sprite **)(param_1 + 4) != (RGE_Sprite *)0x0) {
    iVar1 = RGE_Sprite::check_for_shadows(*(RGE_Sprite **)(param_1 + 4));
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041b00f
// Address: 0041b00f
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_asprite_cp: "C:\msdev\work\age1_x1\asprite.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

RGE_Active_Sprite * __thiscall FUN_0041b00f(RGE_Active_Sprite *param_1,RGE_Sprite *param_2)
{
  RGE_Sprite *pRVar1;
  short sVar2;
  RGE_Sprite *pRVar3;
  short sVar4;
  undefined4 *unaff_FS_OFFSET;
  float10 extraout_ST0;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c988;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Active_Sprite::RGE_Active_Sprite(param_1,param_2);
  pRVar3 = param_1->sprite;
  param_1->_padding_ = (int)&RGE_Active_Animated_Sprite::_vftable_;
  param_1->type = '\x02';
  *(undefined2 *)&param_1[1].offset_x = 0;
  uStack_4 = 0;
  pRVar1 = (RGE_Sprite *)pRVar3->duration;
  param_1[1].sprite = pRVar1;
  if ((float)pRVar1 < (float)_DAT_0056ee78) {
    param_1[1].sprite = (RGE_Sprite *)0x3a83126f;
  }
  if ((pRVar3->flag & 4) == 0) {
    *(undefined2 *)&param_1[1]._padding_ = 0;
  }
  else {
    debug_rand(s_C__msdev_work_age1_x1_asprite_cp,0xb7);
    pRVar1 = param_1->sprite;
    sVar4 = __ftol();
    *(short *)&param_1[1]._padding_ = sVar4;
    sVar2 = pRVar1->frame_num;
    if (sVar2 <= sVar4) {
      sVar2 = sVar2 + -1;
      *(short *)&param_1[1]._padding_ = sVar2;
      param_1[1].sprite =
           (RGE_Sprite *)(float)(extraout_ST0 - (float10)(int)sVar2 * (float10)pRVar1->duration);
    }
    *(short *)&param_1[1].offset_x = (short)param_1[1]._padding_;
  }
  *(undefined4 *)&param_1[1].type = 0;
  *(undefined1 *)((int)&param_1[1].offset_x + 2) = 0;
  *(undefined1 *)((int)&param_1[1].offset_x + 3) = 0;
  *(undefined1 *)&param_1[1].offset_y = 1;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041b113
// Address: 0041b113
// XREFS: None
RGE_Active_Animated_Sprite * __thiscall
FUN_0041b113(RGE_Active_Animated_Sprite *param_1,byte param_2)
{
  RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041b13e
// Address: 0041b13e
// XREFS: None
RGE_Active_Sprite * __thiscall
FUN_0041b13e(RGE_Active_Sprite *param_1,int param_2,RGE_Sprite **param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c9a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Active_Sprite::RGE_Active_Sprite(param_1,param_2,param_3);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Active_Animated_Sprite::_vftable_;
  param_1->type = '\x02';
  rge_read(param_2,param_1 + 1,2);
  rge_read(param_2,&param_1[1].sprite,4);
  rge_read(param_2,&param_1[1].type,4);
  rge_read(param_2,&param_1[1].offset_x,2);
  rge_read(param_2,(void *)((int)&param_1[1].offset_x + 2),1);
  rge_read(param_2,(void *)((int)&param_1[1].offset_x + 3),1);
  rge_read(param_2,&param_1[1].offset_y,1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041b1fd
// Address: 0041b1fd
// XREFS: None
void __fastcall FUN_0041b1fd(RGE_Active_Sprite *param_1)
{
  param_1->_padding_ = (int)&RGE_Active_Animated_Sprite::_vftable_;
  RGE_Active_Sprite::~RGE_Active_Sprite(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0041b20b
// Address: 0041b20b
// XREFS: None
void __thiscall FUN_0041b20b(RGE_Active_Sprite *param_1,int param_2)
{
  RGE_Active_Sprite::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,2);
  rge_write(param_2,&param_1[1].sprite,4);
  rge_write(param_2,&param_1[1].type,4);
  rge_write(param_2,&param_1[1].offset_x,2);
  rge_write(param_2,(void *)((int)&param_1[1].offset_x + 2),1);
  rge_write(param_2,(void *)((int)&param_1[1].offset_x + 3),1);
  rge_write(param_2,&param_1[1].offset_y,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0041b28c
// Address: 0041b28c
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041b28c(int param_1,float param_2,float param_3)
{
  int iVar1;
  ushort uVar2;
  short sVar3;
  float10 extraout_ST0;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined1 *)(param_1 + 0x22) = 0;
  *(undefined1 *)(param_1 + 0x23) = 0;
  if ((iVar1 != 0) && (*(char *)(param_1 + 0x24) != '\0')) {
    if (*(short *)(iVar1 + 0x5e) <= *(short *)(param_1 + 0x14)) {
      *(short *)(param_1 + 0x14) = *(short *)(iVar1 + 0x5e) + -1;
    }
    if (((*(byte *)(iVar1 + 0x70) & 1) != 0) &&
       (param_2 = param_2 + *(float *)(param_1 + 0x1c), *(float *)(param_1 + 0x1c) = param_2,
       *(float *)(param_1 + 0x18) <= param_2)) {
      *(undefined1 *)(param_1 + 0x22) = 1;
      *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_1 + 0x14);
      uVar2 = __ftol();
      *(float *)(param_1 + 0x1c) =
           (float)(extraout_ST0 - (float10)(int)(short)uVar2 * (float10)*(float *)(param_1 + 0x18));
      if ((((float)_DAT_0056ee88 < param_3) || (*(float *)(iVar1 + 100) == (float)_DAT_0056ee88)) &&
         (*(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + (uVar2 & 0xff),
         *(short *)(iVar1 + 0x5e) <= *(short *)(param_1 + 0x14))) {
        *(undefined1 *)(param_1 + 0x23) = 1;
      }
      if ((*(float *)(iVar1 + 100) == (float)_DAT_0056ee88) || (param_3 == (float)_DAT_0056ee88)) {
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar1 + 0x68);
      }
      else {
        *(float *)(param_1 + 0x18) = (*(float *)(iVar1 + 0x68) * *(float *)(iVar1 + 100)) / param_3;
      }
      if (*(float *)(param_1 + 0x18) < (float)_DAT_0056ee78) {
        *(undefined4 *)(param_1 + 0x18) = 0x3a83126f;
      }
      if (*(char *)(param_1 + 0x23) == '\0') {
        return;
      }
      if ((*(float *)(iVar1 + 0x6c) <= (float)_DAT_0056ee88) ||
         (*(char *)(param_1 + 0x24) == '\x02')) {
        *(undefined1 *)(param_1 + 0x24) = 1;
        sVar3 = *(short *)(iVar1 + 0x5e);
        if (sVar3 <= *(short *)(param_1 + 0x14)) {
          do {
            *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) - sVar3;
            sVar3 = *(short *)(iVar1 + 0x5e);
          } while (sVar3 <= *(short *)(param_1 + 0x14));
        }
      }
      else {
        *(float *)(param_1 + 0x18) =
             *(float *)(iVar1 + 0x6c) -
             (float)((int)*(short *)(param_1 + 0x14) - (int)*(short *)(iVar1 + 0x5e)) *
             *(float *)(iVar1 + 0x68);
        sVar3 = *(short *)(iVar1 + 0x5e);
        *(undefined1 *)(param_1 + 0x24) = 2;
        *(undefined1 *)(param_1 + 0x23) = 0;
        *(short *)(param_1 + 0x14) = sVar3 + -1;
      }
    }
  }
  if ((*(char *)(param_1 + 0x23) != '\0') && ((*(byte *)(iVar1 + 0x70) & 8) != 0)) {
    *(undefined1 *)(param_1 + 0x24) = 0;
    *(short *)(param_1 + 0x14) = *(short *)(iVar1 + 0x5e) + -1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041b429
// Address: 0041b429
// XREFS: None
void __thiscall
FUN_0041b429(int param_1,short param_2,long param_3,long param_4,long param_5,long param_6,
            RGE_Color_Table *param_7,TDrawArea *param_8)
{
  RGE_Sprite::draw(*(RGE_Sprite **)(param_1 + 4),(int)param_2,(int)*(short *)(param_1 + 0x14),
                   param_3,param_4,param_5,param_6,param_7,param_8,'\0');
  if (*(char *)(param_1 + 0x22) != '\0') {
    if (fog_next_shape == 0) {
      RGE_Sprite::play_sound
                (*(RGE_Sprite **)(param_1 + 4),*(short *)(param_1 + 0x20),*(short *)(param_1 + 0x14)
                 ,param_2);
    }
    *(undefined1 *)(param_1 + 0x22) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041b495
// Address: 0041b495
// XREFS: None
void __thiscall
FUN_0041b495(int param_1,short param_2,long param_3,long param_4,RGE_Color_Table *param_5,
            TDrawArea *param_6)
{
  RGE_Sprite::normal_draw
            (*(RGE_Sprite **)(param_1 + 4),(int)param_2,(int)*(short *)(param_1 + 0x14),param_3,
             param_4,param_5,param_6);
  if (*(char *)(param_1 + 0x22) != '\0') {
    RGE_Sprite::play_sound
              (*(RGE_Sprite **)(param_1 + 4),*(short *)(param_1 + 0x20),*(short *)(param_1 + 0x14),
               param_2);
    *(undefined1 *)(param_1 + 0x22) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041b51f
// Address: 0041b51f
// XREFS: None
undefined2 __fastcall FUN_0041b51f(int param_1)
{
  return *(undefined2 *)(param_1 + 0x14);
}

// --------------------------------------------------

// Function: FUN_0041b525
// Address: 0041b525
// XREFS: None
undefined4 __fastcall FUN_0041b525(int param_1)
{
  undefined4 uVar1;
  
  if ((*(char *)(param_1 + 0x24) == '\0') ||
     (uVar1 = 1, (*(byte *)(*(int *)(param_1 + 4) + 0x70) & 1) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0041b547
// Address: 0041b547
// XREFS: None
void __thiscall FUN_0041b547(int param_1,undefined2 param_2)
{
  *(undefined2 *)(param_1 + 0x14) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0041b55c
// Address: 0041b55c
// XREFS: None
undefined4 __thiscall FUN_0041b55c(int param_1,short param_2)
{
  if ((*(char *)(param_1 + 0x22) != '\0') &&
     ((*(char *)(param_1 + 0x23) != '\0' ||
      ((param_2 <= *(short *)(param_1 + 0x14) && (*(short *)(param_1 + 0x20) < param_2)))))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041b58c
// Address: 0041b58c
// XREFS: None
undefined1 __fastcall FUN_0041b58c(int param_1)
{
  return *(undefined1 *)(param_1 + 0x23);
}

// --------------------------------------------------

// Function: FUN_0041b594
// Address: 0041b594
// XREFS: None
uint __thiscall FUN_0041b594(int param_1,short param_2)
{
  uint uStack_4;
  
  uStack_4 = 0;
  RGE_Sprite::get_facetindex
            (*(RGE_Sprite **)(param_1 + 4),(int)param_2,(int)*(short *)(param_1 + 0x14),
             (long *)&uStack_4);
  return uStack_4 & 0xffff;
}

// --------------------------------------------------

// Function: FUN_0041b5ca
// Address: 0041b5ca
// XREFS: None
void __thiscall
FUN_0041b5ca(int param_1,short *param_2,short *param_3,short *param_4,short *param_5,long param_6)
{
  RGE_Sprite::get_frame
            (*(RGE_Sprite **)(param_1 + 4),param_2,param_3,param_4,param_5,param_6,
             (int)*(short *)(param_1 + 0x14));
  return;
}

// --------------------------------------------------

// Function: FUN_0041b5f9
// Address: 0041b5f9
// XREFS: None
void __fastcall FUN_0041b5f9(int param_1)
{
  *(undefined1 *)(param_1 + 0x22) = 1;
  *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_1 + 0x14);
  *(undefined2 *)(param_1 + 0x14) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0041b613
// Address: 0041b613
// XREFS: None
// [HELPER] s__s: "%s"
void FUN_0041b613(undefined4 param_1)
{
  if (draw_log != (_iobuf *)0x0) {
    fprintf(draw_log,s__s,param_1);
    fflush(draw_log);
  }
  return;
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

// Function: FUN_0041b64c
// Address: 0041b64c
// XREFS: None
// [HELPER] draw_log_name: "00000000"
// [HELPER] s__s: "%s"
// [HELPER] s_a_: "a+"
void FUN_0041b64c(undefined4 param_1)
{
  if (draw_log != (_iobuf *)0x0) {
    fprintf(draw_log,s__s,param_1);
    fclose(draw_log);
    draw_log = (_iobuf *)fopen(&draw_log_name,s_a_);
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

// Function: FUN_0041b693
// Address: 0041b693
// XREFS: None
// [HELPER] draw_log_name: "00000000"
// [HELPER] s_: ""
// [HELPER] s_language_dll: "language.dll"
RGE_Base_Game * __thiscall FUN_0041b693(RGE_Base_Game *param_1,RGE_Prog_Info *param_2)
{
  char cVar1;
  void *pvVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int unaff_retaddr;
  
  param_1->player_game_info = (RGE_Game_Info *)0x0;
  param_1->random_game_seed = -1;
  param_1->random_map_seed = -1;
  param_1->save_random_game_seed = -1;
  param_1->save_random_map_seed = -1;
  param_1->quick_build = 0;
  param_1->_padding_ = (int)&RGE_Base_Game::_vftable_;
  do_draw_log = 0;
  safe_draw_log = 0;
  draw_log_name._0_1_ = 0;
  draw_log = (_iobuf *)0x0;
  RGE_Base_Game::setVersion(param_1,1.0);
  RGE_Base_Game::setScenarioGame(param_1,0);
  RGE_Base_Game::setCampaignGame(param_1,0);
  RGE_Base_Game::setSavedGame(param_1,0);
  RGE_Base_Game::setSinglePlayerGame(param_1,1);
  RGE_Base_Game::setMultiplayerGame(param_1,0);
  RGE_Base_Game::setMapSize(param_1,0x60,0x60,8);
  RGE_Base_Game::setAllowCheatCodes(param_1,0);
  RGE_Base_Game::setCheatNotification(param_1,1);
  RGE_Base_Game::setFullVisibility(param_1,0);
  RGE_Base_Game::setFogOfWar(param_1,1);
  RGE_Base_Game::setColoredChat(param_1,1);
  RGE_Base_Game::setGameDeveloperMode(param_1,0);
  RGE_Base_Game::setDifficulty(param_1,0);
  iVar8 = 0;
  do {
    RGE_Base_Game::setPlayerCDAndVersion(param_1,iVar8,'\0');
    RGE_Base_Game::setPlayerHasCD(param_1,iVar8,0);
    RGE_Base_Game::setPlayerVersion(param_1,iVar8,'\0');
    RGE_Base_Game::setPlayerTeam(param_1,iVar8,1);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 9);
  RGE_Base_Game::setPathFinding(param_1,'\0');
  RGE_Base_Game::setMpPathFinding(param_1,'\0');
  RGE_Base_Game::setNumberPlayers(param_1,4);
  RGE_Base_Game::setScenarioName(param_1,s_);
  rge_base_game = param_1;
  param_1->prog_info = param_2;
  param_1->prog_window = (void *)0x0;
  param_1->prog_ready = 0;
  param_1->prog_active = 1;
  param_1->prog_palette = (void *)0x0;
  param_1->window_style = 0;
  StringTable = (void *)0x0;
  param_1->screen_saver_enabled = 0;
  param_1->error_code = 0;
  param_1->is_timer = 0;
  param_1->draw_system = (TDrawSystem *)0x0;
  param_1->draw_area = (TDrawArea *)0x0;
  param_1->outline_type = '\x02';
  param_1->custom_mouse = 0;
  param_1->shapes = (TShape **)0x0;
  param_1->sound_system = (TSound_Driver *)0x0;
  param_1->music_system = (TMusic_System *)0x0;
  param_1->sound_num = 0;
  param_1->sounds = (TDigital **)0x0;
  param_1->save_music_type = '\0';
  param_1->save_music_track_from = 0;
  param_1->save_music_track_to = 0;
  param_1->save_music_cur_track = 0;
  param_1->save_music_file[0] = '\0';
  param_1->save_music_loop = 0;
  param_1->save_music_pos = 0;
  param_1->comm_handler = (TCommunications_Handler *)0x0;
  param_1->debugLog = (TDebuggingLog *)0x0;
  param_1->log_comm = 0;
  param_1->comm_syncstop = 0;
  param_1->comm_syncmsg = 0;
  param_1->comm_stepmode = 0;
  param_1->comm_speed = 1;
  param_1->comm_droppackets = 0;
  param_1->registry = (TRegistry *)0x0;
  param_1->prog_mode = 0;
  param_1->game_mode = 0;
  param_1->sub_game_mode = 0;
  param_1->paused = 0;
  param_1->mouse_pointer = (TMousePointer *)0x0;
  param_1->erase_mouse = 0;
  param_1->mouse_blit_sync = 0;
  param_1->is_mouse_on = 1;
  param_1->windows_mouse = 1;
  pvVar2 = (void *)LoadCursorA(0,0x7f00);
  param_1->mouse_cursor = pvVar2;
  param_1->font_num = 0;
  param_1->fonts = (RGE_Font *)0x0;
  GetCurrentDirectoryA(0x105,param_1->work_dir);
  uVar4 = 0xffffffff;
  pcVar7 = &s_language_dll;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = param_1->string_dll_name;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  param_1->master_obj_id = -1;
  param_1->terrain_id = -1;
  param_1->elevation_height = -1;
  param_1->world = (RGE_Game_World *)0x0;
  param_1->render_all = 1;
  param_1->brush_size = 1;
  param_1->timing_text[0] = '\0';
  param_1->frame_count = 0;
  param_1->world_update_count = 0;
  param_1->view_update_count = 0;
  param_1->last_frame_count = 0;
  param_1->last_world_update_count = 0;
  param_1->last_view_update_count = 0;
  param_1->fps = 0;
  param_1->world_update_fps = 0;
  param_1->view_update_fps = 0;
  param_1->last_view_time = 0;
  puVar3 = &param_1->timings[0].last_time;
  iVar8 = 0x1e;
  do {
    ((RGE_Timing_Info *)(puVar3 + -1))->accum_time = 0;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3 = puVar3 + 8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_1->do_show_timings = 0;
  param_1->do_show_comm = 0;
  param_1->do_show_ai = 0;
  param_1->save_check_for_cd = 1;
  L = (TDebuggingLog *)0x0;
  iVar8 = 0;
  AppInst = param_1->prog_info->instance;
  AppWnd = (void *)0x0;
  chat = (TChat *)0x0;
  comm = (TCommunications_Handler *)0x0;
  Regs = (TRegistry *)0x0;
  sound_driver = (TSound_Driver *)0x0;
  driveInfo = (DriveInformation *)0x0;
  param_1->scenario_info = (RGE_Scenario_File_Info *)0x0;
  piVar6 = param_1->playerIDValue;
  do {
    *piVar6 = 0;
    param_1->resigned[iVar8] = '\0';
    iVar8 = iVar8 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar8 < 9);
  param_1->auto_paused = 0;
  param_1->rollover = 1;
  param_1->map_save_area = (TDrawArea *)0x0;
  param_1->game_speed = 1.0;
  param_1->single_player_difficulty = 2;
  iVar8 = RGE_Base_Game::setup_registry(param_1);
  if (iVar8 == 0) {
    param_1->error_code = 0xe;
    return param_1;
  }
  Regs = param_1->registry;
  iVar8 = RGE_Base_Game::setup_debugging_log(param_1);
  if (iVar8 == 0) {
    param_1->error_code = 0xf;
    return param_1;
  }
  L = param_1->debugLog;
  if (unaff_retaddr != 0) {
    iVar8 = RGE_Base_Game::setup(param_1);
    if ((iVar8 == 0) && (param_1->error_code == 0)) {
      param_1->error_code = 1;
    }
  }
  param_1->display_selected_ids = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041ba7c
// Address: 0041ba7c
// XREFS: None
RGE_Base_Game * __thiscall FUN_0041ba7c(RGE_Base_Game *param_1,byte param_2)
{
  RGE_Base_Game::~RGE_Base_Game(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0041ba9e
// Address: 0041ba9e
// XREFS: None
// [HELPER] draw_log_name: "00000000"
// [HELPER] s_C__msdev_work_age1_x1_basegame_c: "C:\msdev\work\age1_x1\basegame.cpp"
// [HELPER] s_Difficulty: "Difficulty"
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_Game_Speed: "Game Speed"
// [HELPER] s_MP_Path_Finding: "MP Path Finding"
// [HELPER] s_Mouse_Style: "Mouse Style"
// [HELPER] s_NODXCHECK: "NODXCHECK"
// [HELPER] s_Path_Finding: "Path Finding"
// [HELPER] s_Rollover_Text: "Rollover Text"
// [HELPER] s_Screen_Size: "Screen Size"
// [HELPER] s_Scroll_Speed: "Scroll Speed"
// [HELPER] s__sscenario_inf: "%sscenario.inf"
// [HELPER] s_c__aoeact_txt: "c:\aoeact.txt"
// [HELPER] s_c__fps_txt: "c:\fps.txt"
// [HELPER] s_drawlog_d_txt: "drawlog%d.txt"
// [HELPER] s_empires_exe: "empires.exe"
// [HELPER] s_game_d_nfo: "game%d.nfo"
// [HELPER] s_w: "w"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0041ba9e(RGE_Base_Game *param_1)
{
  char cVar1;
  uchar uVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  RGE_Game_Info *pRVar6;
  RGE_Scenario_File_Info *pRVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  char **ppcVar13;
  undefined4 *unaff_FS_OFFSET;
  DriveInformation *pDStack_3d8;
  uint uStack_3d4;
  undefined1 auStack_3d0 [12];
  uint uStack_3c4;
  uint uStack_3bc;
  char acStack_3b0 [260];
  char acStack_2ac [256];
  undefined1 auStack_1ac [136];
  undefined1 auStack_124 [280];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055c9f8;
  *unaff_FS_OFFSET = &uStack_c;
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_basegame_c,0x20a);
  debug_srand(s_C__msdev_work_age1_x1_basegame_c,0x20a,uVar3);
  iVar4 = TRegistry::RegGetInt(param_1->registry,1,s_Screen_Size);
  if (iVar4 < 0x321) {
    if (iVar4 == 800) {
      param_1->prog_info->main_wid = 800;
      param_1->prog_info->main_hgt = 600;
    }
    else if (iVar4 == 0x280) {
      param_1->prog_info->main_wid = 0x280;
      param_1->prog_info->main_hgt = 0x1e0;
    }
  }
  else if (iVar4 == 0x400) {
    param_1->prog_info->main_wid = 0x400;
    param_1->prog_info->main_hgt = 0x300;
  }
  else if (iVar4 == 0x500) {
    param_1->prog_info->main_wid = 0x500;
    param_1->prog_info->main_hgt = 0x400;
  }
  iVar4 = TRegistry::RegGetInt(param_1->registry,1,s_Rollover_Text);
  if (iVar4 == 2) {
    param_1->rollover = 0;
  }
  else {
    param_1->rollover = 1;
  }
  iVar4 = TRegistry::RegGetInt(param_1->registry,1,s_Mouse_Style);
  if (iVar4 == 2) {
    param_1->prog_info->interface_style = 2;
  }
  else if (iVar4 == 1) {
    param_1->prog_info->interface_style = 1;
  }
  uStack_3d4 = TRegistry::RegGetInt(param_1->registry,1,s_Game_Speed);
  if (uStack_3d4 != 0xffffffff) {
    param_1->game_speed = (float)(int)uStack_3d4 * _DAT_0056f014;
  }
  iVar4 = TRegistry::RegGetInt(param_1->registry,1,s_Difficulty);
  if (iVar4 != -1) {
    param_1->single_player_difficulty = iVar4;
  }
  iVar4 = TRegistry::RegGetInt(param_1->registry,1,s_Path_Finding);
  if ((0 < iVar4) && (iVar4 < 4)) {
    RGE_Base_Game::setPathFinding(param_1,(char)iVar4 + 0xff);
  }
  iVar4 = TRegistry::RegGetInt(param_1->registry,1,s_MP_Path_Finding);
  if ((0 < iVar4) && (iVar4 < 4)) {
    RGE_Base_Game::setMpPathFinding(param_1,(char)iVar4 + 0xff);
  }
  uVar3 = TRegistry::RegGetInt(param_1->registry,1,s_Scroll_Speed);
  if (((uVar3 != 0xffffffff) && (9 < (int)uVar3)) && ((int)uVar3 < 0xc9)) {
    param_1->prog_info->mouse_scroll_interval = uVar3;
    param_1->prog_info->key_scroll_interval = uVar3;
  }
  iVar4 = __findfirst(s_empires_exe,auStack_124);
  if (iVar4 == -1) {
    param_1->error_code = 0x17;
  }
  else {
    iVar4 = param_1->_padding_;
    iVar5 = (**(code **)(iVar4 + 100))();
    if (iVar5 == 0) {
      param_1->error_code = 2;
    }
    else {
      StringTable = (void *)LoadLibraryA(param_1->string_dll_name);
      if (StringTable == (void *)0x0) {
        param_1->error_code = 1;
      }
      else {
        GlobalMemoryStatus(auStack_3d0);
        if ((((uStack_3c4 < 0x1400000) || (uStack_3bc < 0xa00000)) &&
            ((uStack_3c4 < 0xa00000 || (uStack_3bc < 0x1400000)))) && (uStack_3bc < 0x1e00000)) {
          param_1->error_code = 0x16;
        }
        else {
          (**(code **)(iVar4 + 0x140))();
          if (debugActions == 1) {
            actionFile = (_iobuf *)fopen(s_c__aoeact_txt,s_w);
          }
          if ((param_1->prog_info->check_expiration == 0) ||
             (iVar5 = RGE_Base_Game::check_expiration(param_1), iVar5 != 0)) {
            if ((param_1->prog_info->check_multi_copies == 0) ||
               (iVar5 = RGE_Base_Game::check_multi_copies(param_1), iVar5 != 0)) {
              uVar2 = RGE_Base_Game::check_prog_argument(param_1,s_NODXCHECK);
              if ((uVar2 == '\0') &&
                 (GetDXVersion(&uStack_3d4,(ulong *)&pDStack_3d8), uStack_3d4 < 0x501)) {
                param_1->error_code = 0x14;
              }
              else {
                SystemParametersInfoA(0x10,0,&param_1->screen_saver_enabled,0);
                if (param_1->screen_saver_enabled != 0) {
                  SystemParametersInfoA(0x11,0,0,2);
                }
                SystemParametersInfoA(0x53,0,&param_1->low_power_enabled,0);
                if (param_1->low_power_enabled != 0) {
                  SystemParametersInfoA(0x55,0,0,2);
                }
                iVar5 = RGE_Base_Game::check_for_cd(param_1,0);
                param_1->save_check_for_cd = iVar5;
                iVar5 = (**(code **)(iVar4 + 0x68))();
                if (iVar5 == 0) {
                  param_1->error_code = 5;
                }
                else {
                  iVar5 = (**(code **)(iVar4 + 0x6c))();
                  if (iVar5 == 0) {
                    param_1->error_code = 6;
                  }
                  else {
                    iVar5 = (**(code **)(iVar4 + 0x70))();
                    if (iVar5 == 0) {
                      if (param_1->error_code == 0) {
                        param_1->error_code = 7;
                      }
                    }
                    else {
                      iVar5 = (**(code **)(iVar4 + 0x74))();
                      if (iVar5 == 0) {
                        param_1->error_code = 0x11;
                      }
                      else {
                        iVar5 = (**(code **)(iVar4 + 0x98))();
                        if (iVar5 == 0) {
                          param_1->error_code = 7;
                        }
                        else {
                          iVar5 = (**(code **)(iVar4 + 0x13c))();
                          if (iVar5 == 0) {
                            param_1->error_code = 7;
                          }
                          else {
                            iVar5 = (**(code **)(iVar4 + 0x78))();
                            if (iVar5 == 0) {
                              param_1->error_code = 8;
                            }
                            else {
                              iVar5 = (**(code **)(iVar4 + 0x8c))();
                              if (iVar5 == 0) {
                                param_1->error_code = 10;
                              }
                              else {
                                iVar5 = (**(code **)(iVar4 + 0x84))();
                                if (iVar5 == 0) {
                                  param_1->error_code = 0x10;
                                }
                                else {
                                  iVar5 = (**(code **)(iVar4 + 0x88))();
                                  if (iVar5 == 0) {
                                    param_1->error_code = 9;
                                  }
                                  else {
                                    iVar5 = (**(code **)(iVar4 + 0x90))();
                                    if (iVar5 == 0) {
                                      param_1->error_code = 0xb;
                                    }
                                    else {
                                      iVar5 = (**(code **)(iVar4 + 0x94))();
                                      if (iVar5 == 0) {
                                        param_1->error_code = 0xc;
                                      }
                                      else {
                                        pDStack_3d8 = (DriveInformation *)operator_new(0x274);
                                        uStack_4 = 0;
                                        if (pDStack_3d8 == (DriveInformation *)0x0) {
                                          driveInfo = (DriveInformation *)0x0;
                                        }
                                        else {
                                          driveInfo = (DriveInformation *)
                                                      DriveInformation::DriveInformation
                                                                (pDStack_3d8);
                                        }
                                        uStack_4 = 0xffffffff;
                                        if (driveInfo != (DriveInformation *)0x0) {
                                          iVar5 = (**(code **)(iVar4 + 0x9c))();
                                          if (iVar5 != 0) {
                                            (**(code **)(iVar4 + 0xc))(0);
                                            (**(code **)(iVar4 + 0xa0))();
                                            (**(code **)(iVar4 + 0xe4))(param_1->prog_window,0,0,0);
                                            param_1->prog_ready = 1;
                                            ShowWindow(param_1->prog_window,5);
                                            SetFocus(param_1->prog_window);
                                            RGE_Base_Game::mouse_on(param_1);
                                            iVar4 = SetTimer(param_1->prog_window,1,0x32,0);
                                            param_1->is_timer = iVar4;
                                            iVar4 = TRegistry::RegGetInt
                                                              (param_1->registry,0,
                                                               s_Game_File_Number);
                                            if (iVar4 < 0) {
                                              iVar4 = 0;
                                              do {
                                                sprintf(acStack_3b0,s_game_d_nfo,iVar4);
                                                iVar5 = __findfirst(acStack_3b0,auStack_124);
                                                if (iVar5 == -1) {
                                                  TRegistry::RegSetInt
                                                            (param_1->registry,0,s_Game_File_Number,
                                                             iVar4);
                                                  pDStack_3d8 = (DriveInformation *)
                                                                operator_new(0x118);
                                                  uStack_4 = 2;
                                                  if (pDStack_3d8 == (DriveInformation *)0x0)
                                                  goto LAB_0041c0d5;
                                                  pRVar6 = (RGE_Game_Info *)
                                                           RGE_Game_Info::RGE_Game_Info
                                                                     ((RGE_Game_Info *)pDStack_3d8,
                                                                      acStack_3b0);
                                                  goto LAB_0041c0d7;
                                                }
                                                iVar4 = iVar4 + 1;
                                              } while (iVar4 < 9999);
                                            }
                                            else {
                                              iVar4 = TRegistry::RegGetInt
                                                                (param_1->registry,0,
                                                                 s_Game_File_Number);
                                              sprintf(acStack_3b0,s_game_d_nfo,iVar4);
                                              pDStack_3d8 = (DriveInformation *)operator_new(0x118);
                                              uStack_4 = 1;
                                              if (pDStack_3d8 == (DriveInformation *)0x0) {
LAB_0041c0d5:
                                                pRVar6 = (RGE_Game_Info *)0x0;
                                              }
                                              else {
                                                pRVar6 = (RGE_Game_Info *)
                                                         RGE_Game_Info::RGE_Game_Info
                                                                   ((RGE_Game_Info *)pDStack_3d8,
                                                                    acStack_3b0);
                                              }
LAB_0041c0d7:
                                              uStack_4 = 0xffffffff;
                                              param_1->player_game_info = pRVar6;
                                            }
                                            sprintf(acStack_3b0,s__sscenario_inf,
                                                    param_1->prog_info->scenario_dir);
                                            pDStack_3d8 = (DriveInformation *)operator_new(0x10c);
                                            uStack_4 = 3;
                                            if (pDStack_3d8 == (DriveInformation *)0x0) {
                                              pRVar7 = (RGE_Scenario_File_Info *)0x0;
                                            }
                                            else {
                                              pRVar7 = (RGE_Scenario_File_Info *)
                                                       RGE_Scenario_File_Info::
                                                       RGE_Scenario_File_Info
                                                                 ((RGE_Scenario_File_Info *)
                                                                  pDStack_3d8,acStack_3b0);
                                            }
                                            param_1->scenario_info = pRVar7;
                                            uStack_4 = 0xffffffff;
                                            if (do_draw_log != 0) {
                                              if ((char)draw_log_name == '\0') {
                                                iVar4 = 0;
                                                do {
                                                  sprintf(acStack_2ac,s_drawlog_d_txt,iVar4);
                                                  iVar5 = OpenFile(acStack_2ac,auStack_1ac,0x4000);
                                                  if (iVar5 == -1) {
                                                    draw_log = (_iobuf *)fopen(acStack_2ac,s_w);
                                                    uVar9 = 0xffffffff;
                                                    pcVar11 = acStack_2ac;
                                                    goto code_r0x0041c1b9;
                                                  }
                                                  iVar4 = iVar4 + 1;
                                                } while (iVar4 < 1000);
                                              }
                                              else {
                                                draw_log = (_iobuf *)fopen(&draw_log_name,s_w);
                                              }
                                            }
                                            goto LAB_0041c1ed;
                                          }
                                          param_1->error_code = 0xd;
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
                    }
                  }
                }
              }
            }
            else {
              param_1->error_code = 4;
            }
          }
          else {
            param_1->error_code = 3;
          }
        }
      }
    }
  }
  uVar8 = 0;
  goto LAB_0041c223;
  while( true ) {
    uVar9 = uVar9 - 1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
    if (cVar1 == '\0') break;
code_r0x0041c1b9:
    pcVar12 = pcVar11;
    if (uVar9 == 0) break;
  }
  uVar9 = ~uVar9;
  pcVar11 = pcVar12 + -uVar9;
  ppcVar13 = &draw_log_name;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *ppcVar13 = *(char **)pcVar11;
    pcVar11 = pcVar11 + 4;
    ppcVar13 = ppcVar13 + 1;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(char *)ppcVar13 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    ppcVar13 = (char **)((int)ppcVar13 + 1);
  }
LAB_0041c1ed:
  if ((do_fps_log != 0) && (fps_log = (_iobuf *)fopen(s_c__fps_txt,s_w), fps_log == (_iobuf *)0x0))
{
    do_fps_log = 0;
  }
  uVar8 = 1;
LAB_0041c223:
  *unaff_FS_OFFSET = uStack_c;
  return uVar8;
}

// --------------------------------------------------

// Function: FUN_0041c23c
// Address: 0041c23c
// XREFS: None
void __thiscall FUN_0041c23c(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1b0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0041c24d
// Address: 0041c24d
// XREFS: None
undefined4 FUN_0041c24d(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041c253
// Address: 0041c253
// XREFS: None
undefined4 FUN_0041c253(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041c263
// Address: 0041c263
// XREFS: None
// [HELPER] s_Blank_Screen: "Blank Screen"
// [HELPER] s_Difficulty: "Difficulty"
// [HELPER] s_Game_File_Number: "Game File Number"
// [HELPER] s_Game_Speed: "Game Speed"
// [HELPER] s_MP_Path_Finding: "MP Path Finding"
// [HELPER] s_MS_WINHELP: "MS_WINHELP"
// [HELPER] s_Mouse_Style: "Mouse Style"
// [HELPER] s_Path_Finding: "Path Finding"
// [HELPER] s_Rollover_Text: "Rollover Text"
// [HELPER] s_Screen_Size: "Screen Size"
// [HELPER] s_Scroll_Speed: "Scroll Speed"
// [HELPER] s_game_d_nfo: "game%d.nfo"
void __fastcall FUN_0041c263(RGE_Base_Game *param_1)
{
  RGE_Scenario_File_Info *this;
  RGE_Game_Info *this_00;
  TDrawArea *this_01;
  TMousePointer *this_02;
  TCommunications_Handler *this_03;
  int iVar1;
  TDrawSystem *this_04;
  TRegistry *this_05;
  TDebuggingLog *this_06;
  TShape *this_07;
  TChat *pTVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  char acStack_110 [16];
  char acStack_100 [256];
  
  param_1->_padding_ = (int)&RGE_Base_Game::_vftable_;
  if ((do_debug_random != 0) && (wrote_debug_random_log == 0)) {
    debug_random_write();
    dump_vismap_log();
  }
  if (param_1->draw_system != (TDrawSystem *)0x0) {
    TRegistry::RegSetInt(param_1->registry,1,s_Screen_Size,param_1->draw_system->ScreenWidth);
  }
  TRegistry::RegSetInt(param_1->registry,1,s_Rollover_Text,2 - (uint)(param_1->rollover != 0));
  if (param_1->prog_info->interface_style == 2) {
    iVar5 = 2;
  }
  else {
    iVar5 = 1;
  }
  TRegistry::RegSetInt(param_1->registry,1,s_Mouse_Style,iVar5);
  iVar5 = __ftol();
  TRegistry::RegSetInt(param_1->registry,1,s_Game_Speed,iVar5);
  TRegistry::RegSetInt(param_1->registry,1,s_Difficulty,param_1->single_player_difficulty);
  bVar3 = RGE_Base_Game::pathFinding(param_1);
  TRegistry::RegSetInt(param_1->registry,1,s_Path_Finding,bVar3 + 1);
  bVar3 = RGE_Base_Game::mpPathFinding(param_1);
  TRegistry::RegSetInt(param_1->registry,1,s_MP_Path_Finding,bVar3 + 1);
  TRegistry::RegSetInt(param_1->registry,1,s_Scroll_Speed,param_1->prog_info->mouse_scroll_interval)
  ;
  if (actionFile != (_iobuf *)0x0) {
    fclose(actionFile);
    actionFile = (_iobuf *)0x0;
  }
  if (fps_log != (_iobuf *)0x0) {
    fclose(fps_log);
    fps_log = (_iobuf *)0x0;
  }
  if (draw_log != (_iobuf *)0x0) {
    fclose(draw_log);
    draw_log = (_iobuf *)0x0;
  }
  this = param_1->scenario_info;
  if (this != (RGE_Scenario_File_Info *)0x0) {
    RGE_Scenario_File_Info::~RGE_Scenario_File_Info(this);
    operator_delete(this);
    param_1->scenario_info = (RGE_Scenario_File_Info *)0x0;
  }
  if (param_1->player_game_info != (RGE_Game_Info *)0x0) {
    iVar5 = TRegistry::RegGetInt(param_1->registry,0,s_Game_File_Number);
    if (-1 < iVar5) {
      iVar5 = TRegistry::RegGetInt(param_1->registry,0,s_Game_File_Number);
      sprintf(acStack_110,s_game_d_nfo,iVar5);
      RGE_Game_Info::save(param_1->player_game_info,acStack_110);
    }
    this_00 = param_1->player_game_info;
    if (this_00 != (RGE_Game_Info *)0x0) {
      RGE_Game_Info::~RGE_Game_Info(this_00);
      operator_delete(this_00);
    }
    param_1->player_game_info = (RGE_Game_Info *)0x0;
  }
  param_1->prog_mode = 0;
  if (param_1->world != (RGE_Game_World *)0x0) {
    (**(code **)(param_1->world->_padding_ + 0xa0))(1);
    param_1->world = (RGE_Game_World *)0x0;
  }
  this_01 = param_1->map_save_area;
  if (this_01 != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this_01);
    operator_delete(this_01);
    param_1->map_save_area = (TDrawArea *)0x0;
  }
  this_02 = param_1->mouse_pointer;
  if (this_02 != (TMousePointer *)0x0) {
    TMousePointer::~TMousePointer(this_02);
    operator_delete(this_02);
    param_1->mouse_pointer = (TMousePointer *)0x0;
  }
  if (driveInfo != (DriveInformation *)0x0) {
    operator_delete(driveInfo);
    driveInfo = (DriveInformation *)0x0;
  }
  this_03 = param_1->comm_handler;
  if (this_03 != (TCommunications_Handler *)0x0) {
    TCommunications_Handler::~TCommunications_Handler(this_03);
    operator_delete(this_03);
    param_1->comm_handler = (TCommunications_Handler *)0x0;
  }
  pTVar2 = chat;
  if (chat != (TChat *)0x0) {
    TChat::~TChat(chat);
    operator_delete(pTVar2);
    chat = (TChat *)0x0;
  }
  if (param_1->fonts != (RGE_Font *)0x0) {
    iVar5 = 0;
    if (0 < param_1->font_num) {
      iVar4 = 0;
      do {
        iVar1 = *(int *)((int)&param_1->fonts->font + iVar4);
        if (iVar1 != 0) {
          DeleteObject(iVar1);
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar5 < param_1->font_num);
    }
    free(param_1->fonts);
    param_1->fonts = (RGE_Font *)0x0;
  }
  RGE_Base_Game::stop_sound_system(param_1);
  TPanelSystem::destroyPanel(&panel_system,s_Blank_Screen);
  this_04 = param_1->draw_system;
  if (this_04 != (TDrawSystem *)0x0) {
    TDrawSystem::~TDrawSystem(this_04);
    operator_delete(this_04);
    param_1->draw_system = (TDrawSystem *)0x0;
    param_1->draw_area = (TDrawArea *)0x0;
  }
  if (param_1->screen_saver_enabled != 0) {
    SystemParametersInfoA(0x11,1,0,2);
  }
  if (param_1->low_power_enabled != 0) {
    SystemParametersInfoA(0x55,1,0,2);
  }
  if (param_1->prog_palette != (void *)0x0) {
    TPanelSystem::release_palette(&panel_system,param_1->prog_palette);
    param_1->prog_palette = (void *)0x0;
  }
  this_05 = param_1->registry;
  if (this_05 != (TRegistry *)0x0) {
    TRegistry::~TRegistry(this_05);
    operator_delete(this_05);
    param_1->registry = (TRegistry *)0x0;
  }
  if (param_1->prog_mutex != (void *)0x0) {
    CloseHandle(param_1->prog_mutex);
    param_1->prog_mutex = (void *)0x0;
  }
  rge_base_game = (RGE_Base_Game *)0x0;
  if (param_1->prog_window != (void *)0x0) {
    DestroyWindow(param_1->prog_window);
  }
  RGE_Base_Game::get_string(param_1,0x3eb,acStack_100,0x100);
  if ((acStack_100[0] != '\0') && (iVar5 = FindWindowA(s_MS_WINHELP,acStack_100), iVar5 != 0)) {
    SendMessageA(iVar5,0x10,0,0);
  }
  if ((StringTable != (void *)0x0) && (StringTable != param_1->prog_info->instance)) {
    FreeLibrary(StringTable);
    StringTable = (void *)0x0;
  }
  this_06 = param_1->debugLog;
  if (this_06 != (TDebuggingLog *)0x0) {
    TDebuggingLog::~TDebuggingLog(this_06);
    operator_delete(this_06);
    param_1->debugLog = (TDebuggingLog *)0x0;
  }
  if (param_1->shapes != (TShape **)0x0) {
    iVar5 = 0;
    if (0 < param_1->shape_num) {
      do {
        this_07 = param_1->shapes[iVar5];
        if (this_07 != (TShape *)0x0) {
          TShape::~TShape(this_07);
          operator_delete(this_07);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1->shape_num);
    }
    free(param_1->shapes);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041c6e3
// Address: 0041c6e3
// XREFS: None
undefined4 FUN_0041c6e3(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041c6f5
// Address: 0041c6f5
// XREFS: None
undefined4 FUN_0041c6f5(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c708
// Address: 0041c708
// XREFS: None
undefined4 FUN_0041c708(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c716
// Address: 0041c716
// XREFS: None
undefined4 FUN_0041c716(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c728
// Address: 0041c728
// XREFS: None
undefined4 FUN_0041c728(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c738
// Address: 0041c738
// XREFS: None
undefined4 FUN_0041c738(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c748
// Address: 0041c748
// XREFS: None
undefined4 FUN_0041c748(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c758
// Address: 0041c758
// XREFS: None
undefined4 FUN_0041c758(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c766
// Address: 0041c766
// XREFS: None
undefined4 FUN_0041c766(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c776
// Address: 0041c776
// XREFS: None
undefined4 FUN_0041c776(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c786
// Address: 0041c786
// XREFS: None
undefined4 FUN_0041c786(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c796
// Address: 0041c796
// XREFS: None
undefined4 FUN_0041c796(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c7a6
// Address: 0041c7a6
// XREFS: None
undefined4 FUN_0041c7a6(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c7b6
// Address: 0041c7b6
// XREFS: None
undefined4 FUN_0041c7b6(void)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041c7c6
// Address: 0041c7c6
// XREFS: None
void __fastcall FUN_0041c7c6(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0x52c);
  *(undefined4 *)(param_1 + 0x504) = 0;
  *(undefined4 *)(param_1 + 0x508) = 0;
  *(undefined4 *)(param_1 + 0x50c) = 0;
  *(undefined4 *)(param_1 + 0x510) = 0;
  *(undefined4 *)(param_1 + 0x514) = 0;
  *(undefined4 *)(param_1 + 0x518) = 0;
  *(undefined4 *)(param_1 + 0x51c) = 0;
  *(undefined4 *)(param_1 + 0x520) = 0;
  *(undefined4 *)(param_1 + 0x524) = 0;
  iVar2 = 0x1e;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_0041c82b
// Address: 0041c82b
// XREFS: None
void __thiscall FUN_0041c82b(int param_1,int param_2,uint param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2 * 0x20 + param_1;
  iVar2 = (param_2 + 0x2a) * 0x20;
  *(uint *)(iVar1 + 0x528) = *(int *)(iVar1 + 0x528) + param_3;
  *(uint *)(iVar1 + 0x53c) = param_3;
  if (*(uint *)(iVar2 + param_1) < param_3) {
    *(uint *)(iVar2 + param_1) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041c86c
// Address: 0041c86c
// XREFS: None
void __fastcall FUN_0041c86c(int param_1)
{
  *(int *)(param_1 + 0x508) = *(int *)(param_1 + 0x508) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0041c877
// Address: 0041c877
// XREFS: None
void __fastcall FUN_0041c877(int param_1)
{
  *(int *)(param_1 + 0x50c) = *(int *)(param_1 + 0x50c) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0041c887
// Address: 0041c887
// XREFS: None
void __thiscall FUN_0041c887(int param_1,int param_2,undefined4 param_3)
{
  *(undefined4 *)(param_2 * 0x20 + 0x53c + param_1) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0041c8a5
// Address: 0041c8a5
// XREFS: None
undefined4 __thiscall FUN_0041c8a5(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x52c + param_2 * 0x20);
}

// --------------------------------------------------

// Function: FUN_0041c8c1
// Address: 0041c8c1
// XREFS: None
undefined4 __thiscall FUN_0041c8c1(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x53c + param_2 * 0x20);
}

// --------------------------------------------------

// Function: FUN_0041c8e1
// Address: 0041c8e1
// XREFS: None
undefined4 __thiscall FUN_0041c8e1(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x528 + param_2 * 0x20);
}

// --------------------------------------------------

// Function: FUN_0041c901
// Address: 0041c901
// XREFS: None
undefined4 __thiscall FUN_0041c901(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x540 + param_2 * 0x20);
}

// --------------------------------------------------

// Function: FUN_0041c921
// Address: 0041c921
// XREFS: None
undefined4 __thiscall FUN_0041c921(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0x544 + param_2 * 0x20);
}

// --------------------------------------------------

// Function: FUN_0041c941
// Address: 0041c941
// XREFS: None
undefined4 __fastcall FUN_0041c941(int param_1)
{
  return *(undefined4 *)(param_1 + 0x514);
}

// --------------------------------------------------

// Function: FUN_0041c957
// Address: 0041c957
// XREFS: None
undefined4 __fastcall FUN_0041c957(int param_1)
{
  return *(undefined4 *)(param_1 + 0x518);
}

// --------------------------------------------------

// Function: FUN_0041c967
// Address: 0041c967
// XREFS: None
undefined4 __fastcall FUN_0041c967(int param_1)
{
  return *(undefined4 *)(param_1 + 0x508);
}

// --------------------------------------------------

// Function: FUN_0041c977
// Address: 0041c977
// XREFS: None
undefined4 __fastcall FUN_0041c977(int param_1)
{
  return *(undefined4 *)(param_1 + 0x50c);
}

// --------------------------------------------------

// Function: FUN_0041c987
// Address: 0041c987
// XREFS: None
undefined4 __fastcall FUN_0041c987(int param_1)
{
  return *(undefined4 *)(param_1 + 0x40);
}

// --------------------------------------------------

// Function: FUN_0041c994
// Address: 0041c994
// XREFS: None
Alignment * __thiscall FUN_0041c994(int *param_1,undefined4 param_2)
{
  (**(code **)(*param_1 + 0x20))(param_2,&DAT_005b2168,0x200);
  return &DAT_005b2168;
}

// --------------------------------------------------

// Function: FUN_0041c9bc
// Address: 0041c9bc
// XREFS: None
undefined1 * FUN_0041c9bc(undefined4 param_1,undefined1 *param_2,int param_3)
{
  int iVar1;
  
  iVar1 = LoadStringA(StringTable,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = 0;
  }
  param_2[param_3 + -1] = 0;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_0041ca0e
// Address: 0041ca0e
// XREFS: None
void __thiscall
FUN_0041ca0e(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined1 *param_5,
            int param_6)
{
  *param_5 = 0;
  if (param_2 == 1) {
    switch(param_3) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 0xe:
    case 0xf:
      (**(code **)(*param_1 + 0x20))(0x7d2,param_5,param_6);
      return;
    case 7:
    case 8:
    case 0xb:
    case 0xd:
    case 0x11:
      (**(code **)(*param_1 + 0x20))(0x7d3,param_5,param_6);
      return;
    case 9:
    case 0x10:
      (**(code **)(*param_1 + 0x20))(0x7d5,param_5,param_6);
      return;
    case 10:
    case 0xc:
      (**(code **)(*param_1 + 0x20))(0x7d4,param_5,param_6);
      return;
    case 0x12:
      (**(code **)(*param_1 + 0x20))(0x7dc,param_5,param_6);
      return;
    case 0x13:
      (**(code **)(*param_1 + 0x20))(0x7db,param_5,param_6);
      return;
    case 0x14:
      (**(code **)(*param_1 + 0x20))(0x7dd,param_5,param_6);
      return;
    case 0x15:
      (**(code **)(*param_1 + 0x20))(0x7de,param_5,param_6);
      return;
    case 0x16:
      (**(code **)(*param_1 + 0x20))(0x7df,param_5,param_6);
      return;
    case 0x17:
      (**(code **)(*param_1 + 0x20))(0x7e0,param_5,param_6);
      return;
    }
  }
  else if (param_2 == 2) {
    (**(code **)(*param_1 + 0x20))(param_3,param_5,param_6);
    return;
  }
  param_5[param_6 + -1] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0041cc93
// Address: 0041cc93
// XREFS: None
// [HELPER] s_1_03: "1.03"
// [HELPER] s_1_04: "1.04"
// [HELPER] s_1_05: "1.05"
// [HELPER] s_1_06: "1.06"
// [HELPER] s_1_07: "1.07"
// [HELPER] s_1_08: "1.08"
// [HELPER] s_1_09: "1.09"
// [HELPER] s_1_10: "1.10"
// [HELPER] s_1_11: "1.11"
// [HELPER] s__s_s: "%s%s"
undefined4 __thiscall FUN_0041cc93(int *param_1,int param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iStack_130;
  char acStack_12c [300];
  
  sprintf(acStack_12c,s__s_s,param_1[3] + 0xc17,param_2);
  if (param_3 == 0) {
    if (param_2 == 0) {
      return 0;
    }
    iVar1 = rge_open(acStack_12c,0x8000);
  }
  else {
    iVar1 = RGE_Game_Info::open_scenario((RGE_Game_Info *)param_1[1]);
  }
  if (iVar1 == -1) {
    return 0;
  }
  rge_read_uncompressed(iVar1,&iStack_130,4);
  uVar2 = 0;
  if ((((((iStack_130 == s_1_03._0_4_) || (iStack_130 == s_1_04._0_4_)) ||
        (iStack_130 == s_1_05._0_4_)) ||
       ((iStack_130 == s_1_06._0_4_ || (iStack_130 == s_1_07._0_4_)))) ||
      ((iStack_130 == s_1_08._0_4_ || ((iStack_130 == s_1_09._0_4_ || (iStack_130 == s_1_10._0_4_)))
       ))) || (iStack_130 == s_1_11._0_4_)) {
    uVar2 = (**(code **)(*param_1 + 0x38))(iVar1);
  }
  rge_close(iVar1);
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_0041cd9d
// Address: 0041cd9d
// XREFS: None
void __fastcall FUN_0041cd9d(int *param_1)
{
  RGE_Scenario_Header *this;
  int unaff_retaddr;
  
  this = (RGE_Scenario_Header *)
         (**(code **)(*param_1 + 0x34))(*(undefined4 *)(param_1[0xfd] + 0x5c));
  if (this != (RGE_Scenario_Header *)0x0) {
    (**(code **)(this->_padding_ + 4))(unaff_retaddr);
    RGE_Scenario_Header::~RGE_Scenario_Header(this);
    operator_delete(this);
    return;
  }
  rge_write_uncompressed(unaff_retaddr,&stack0xfffffff8,4);
  return;
}

// --------------------------------------------------

// Function: FUN_0041cdf9
// Address: 0041cdf9
// XREFS: None
undefined4 FUN_0041cdf9(int param_1)
{
  RGE_Scenario_Header *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ca1b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Scenario_Header *)operator_new(0x14);
  uStack_4 = 0;
  if (this != (RGE_Scenario_Header *)0x0) {
    uVar1 = RGE_Scenario_Header::RGE_Scenario_Header(this,param_1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041cf25
// Address: 0041cf25
// XREFS: None
void __thiscall FUN_0041cf25(int param_1,long *param_2,long *param_3,long *param_4)
{
  long lVar1;
  
  lVar1 = RGE_Game_Info::get_current_campaign(*(RGE_Game_Info **)(param_1 + 4));
  *param_2 = lVar1;
  lVar1 = RGE_Game_Info::get_current_player(*(RGE_Game_Info **)(param_1 + 4));
  *param_3 = lVar1;
  lVar1 = RGE_Game_Info::get_current_scenario(*(RGE_Game_Info **)(param_1 + 4));
  *param_4 = lVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0041cf61
// Address: 0041cf61
// XREFS: None
undefined4 __thiscall FUN_0041cf61(int param_1,long param_2,long param_3,long param_4)
{
  uchar uVar1;
  
  uVar1 = RGE_Game_Info::set_current_campaign(*(RGE_Game_Info **)(param_1 + 4),param_2);
  if (uVar1 != '\0') {
    uVar1 = RGE_Game_Info::set_current_person(*(RGE_Game_Info **)(param_1 + 4),param_3);
    if (uVar1 != '\0') {
      uVar1 = RGE_Game_Info::set_current_scenario(*(RGE_Game_Info **)(param_1 + 4),param_4);
      if (uVar1 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041cfb2
// Address: 0041cfb2
// XREFS: None
void __fastcall FUN_0041cfb2(int param_1)
{
  RGE_Game_Info::notify_of_scenario_complete(*(RGE_Game_Info **)(param_1 + 4));
  return;
}

// --------------------------------------------------

// Function: FUN_0041cfc8
// Address: 0041cfc8
// XREFS: None
undefined4 __fastcall FUN_0041cfc8(int *param_1)
{
  int iVar1;
  undefined1 auStack_1c [4];
  int iStack_18;
  undefined4 uStack_14;
  
  while( true ) {
    while( true ) {
      while (((param_1[6] == 0 || ((param_1[0x6c] != 4 && (param_1[0x6c] != 2)))) ||
             (((TCommunications_Handler *)param_1[99] != (TCommunications_Handler *)0x0 &&
              (iVar1 = TCommunications_Handler::IsPaused((TCommunications_Handler *)param_1[99]),
              iVar1 != 0))))) {
        iVar1 = GetMessageA(auStack_1c,0,0,0);
        if (iVar1 == 0) {
          return uStack_14;
        }
        TranslateMessage(auStack_1c);
        DispatchMessageA(auStack_1c);
      }
      iVar1 = PeekMessageA(auStack_1c,0,0,0,1);
      if (iVar1 != 0) break;
      (**(code **)(*param_1 + 0xbc))();
    }
    if (iStack_18 == 0x12) break;
    iVar1 = (**(code **)(*param_1 + 0xb8))(auStack_1c);
    if (iVar1 != 0) {
      TranslateMessage(auStack_1c);
      DispatchMessageA(auStack_1c);
    }
  }
  return uStack_14;
}

// --------------------------------------------------

// Function: FUN_0041d092
// Address: 0041d092
// XREFS: None
// [HELPER] do_color_log: " "
// [HELPER] draw_log_name: "00000000"
// [HELPER] s_1024: "1024"
// [HELPER] s_1280: "1280"
// [HELPER] s_640: "640"
// [HELPER] s_800: "800"
// [HELPER] s_AISPEED_: "AISPEED="
// [HELPER] s_ALLCP1: "ALLCP1"
// [HELPER] s_ALLCP: "ALLCP"
// [HELPER] s_ALLGRASS: "ALLGRASS"
// [HELPER] s_CDAUDIO: "CDAUDIO"
// [HELPER] s_CD_AUDIO: "CD AUDIO"
// [HELPER] s_COLORLOG: "COLORLOG"
// [HELPER] s_CUBEOUTLINE: "CUBEOUTLINE"
// [HELPER] s_CUBE_OUTLINE: "CUBE OUTLINE"
// [HELPER] s_CUSTOMMOUSE: "CUSTOMMOUSE"
// [HELPER] s_CUSTOM_MOUSE: "CUSTOM MOUSE"
// [HELPER] s_DATA_: "DATA="
// [HELPER] s_DDERRORLOG: "DDERRORLOG"
// [HELPER] s_DDFLUSHLOG: "DDFLUSHLOG"
// [HELPER] s_DDLOCKLOG: "DDLOCKLOG"
// [HELPER] s_DDLOG: "DDLOG"
// [HELPER] s_DDNOFLUSHLOG: "DDNOFLUSHLOG"
// [HELPER] s_DEVELOPER: "DEVELOPER"
// [HELPER] s_DIRECTDRAW: "DIRECTDRAW"
// [HELPER] s_DIRECT_DRAW: "DIRECT DRAW"
// [HELPER] s_DOLOGSTATUS: "DOLOGSTATUS"
// [HELPER] s_DRAWLOG: "DRAWLOG"
// [HELPER] s_DRAWLOG_: "DRAWLOG="
// [HELPER] s_DROPPACKETS: "DROPPACKETS"
// [HELPER] s_EDGEOUTLINE: "EDGEOUTLINE"
// [HELPER] s_EDGE_OUTLINE: "EDGE OUTLINE"
// [HELPER] s_FASTVIEW: "FASTVIEW"
// [HELPER] s_FAST_VIEW: "FAST VIEW"
// [HELPER] s_FILEFIRST: "FILEFIRST"
// [HELPER] s_FILE_FIRST: "FILE FIRST"
// [HELPER] s_FIXEDUPDATE: "FIXEDUPDATE"
// [HELPER] s_FIXEDUPDATE_: "FIXEDUPDATE="
// [HELPER] s_FULLSCREEN: "FULLSCREEN"
// [HELPER] s_FULL_SCREEN: "FULL SCREEN"
// [HELPER] s_GAMECD: "GAMECD"
// [HELPER] s_GROUNDOUTLINE: "GROUNDOUTLINE"
// [HELPER] s_GROUND_OUTLINE: "GROUND OUTLINE"
// [HELPER] s_IMAMUSIC: "IMAMUSIC"
// [HELPER] s_IMA_MUSIC: "IMA MUSIC"
// [HELPER] s_LOGACTION: "LOGACTION"
// [HELPER] s_LOGAI: "LOGAI"
// [HELPER] s_LOGAI_: "LOGAI="
// [HELPER] s_LOGCOMM: "LOGCOMM"
// [HELPER] s_LOGDEBUG_: "LOGDEBUG="
// [HELPER] s_LOGFPS: "LOGFPS"
// [HELPER] s_LOGOUTPUT: "LOGOUTPUT"
// [HELPER] s_LOGRANDOM: "LOGRANDOM"
// [HELPER] s_LOGUPDATECHANGES: "LOGUPDATECHANGES"
// [HELPER] s_LOG_COMM: "LOG COMM"
// [HELPER] s_LOG_FPS: "LOG FPS"
// [HELPER] s_LOG_OUTPUT: "LOG OUTPUT"
// [HELPER] s_MFILL: "MFILL"
// [HELPER] s_MIDIMUSIC: "MIDIMUSIC"
// [HELPER] s_MIDI_MUSIC: "MIDI MUSIC"
// [HELPER] s_MSYNC: "MSYNC"
// [HELPER] s_NOAICHEAT: "NOAICHEAT"
// [HELPER] s_NOCHATCHEATCODES: "NOCHATCHEATCODES"
// [HELPER] s_NOCOMMSPEED: "NOCOMMSPEED"
// [HELPER] s_NOCP: "NOCP"
// [HELPER] s_NOLOGSTATUS: "NOLOGSTATUS"
// [HELPER] s_NOMOUSE: "NOMOUSE"
// [HELPER] s_NOMUSIC: "NOMUSIC"
// [HELPER] s_NOPATHCAP: "NOPATHCAP"
// [HELPER] s_NOPATHLIMIT: "NOPATHLIMIT"
// [HELPER] s_NORMALMOUSE: "NORMALMOUSE"
// [HELPER] s_NORMAL_MOUSE: "NORMAL MOUSE"
// [HELPER] s_NOSOUND: "NOSOUND"
// [HELPER] s_NOSTARTUP: "NOSTARTUP"
// [HELPER] s_NO_MOUSE: "NO MOUSE"
// [HELPER] s_NO_MUSIC: "NO MUSIC"
// [HELPER] s_NO_SOUND: "NO SOUND"
// [HELPER] s_NO_STARTUP: "NO STARTUP"
// [HELPER] s_ONEBUTTON: "ONEBUTTON"
// [HELPER] s_ONE_BUTTON: "ONE BUTTON"
// [HELPER] s_RANDOMGAME_: "RANDOMGAME="
// [HELPER] s_RANDOMMAP_: "RANDOMMAP="
// [HELPER] s_RESEND1_: "RESEND1="
// [HELPER] s_RESEND2_: "RESEND2="
// [HELPER] s_RES_WARN: "RES_WARN"
// [HELPER] s_RUNLOG: "RUNLOG"
// [HELPER] s_SAFEDRAWLOG: "SAFEDRAWLOG"
// [HELPER] s_SCENARIOS_: "SCENARIOS="
// [HELPER] s_SLOWVIEW: "SLOWVIEW"
// [HELPER] s_SLOW_VIEW: "SLOW VIEW"
// [HELPER] s_SPEED1_: "SPEED1="
// [HELPER] s_SPEED2_: "SPEED2="
// [HELPER] s_SQUAREOUTLINE: "SQUAREOUTLINE"
// [HELPER] s_SQUARE_OUTLINE: "SQUARE OUTLINE"
// [HELPER] s_STEPMODE: "STEPMODE"
// [HELPER] s_STREAMMUSIC: "STREAMMUSIC"
// [HELPER] s_STREAM_MUSIC: "STREAM MUSIC"
// [HELPER] s_SYNCMSG: "SYNCMSG"
// [HELPER] s_SYNCSTOP: "SYNCSTOP"
// [HELPER] s_SYSTEMMEMORY: "SYSTEMMEMORY"
// [HELPER] s_SYSTEM_MEMORY: "SYSTEM MEMORY"
// [HELPER] s_TWOBUTTON: "TWOBUTTON"
// [HELPER] s_TWO_BUTTON: "TWO BUTTON"
// [HELPER] s_UIP: "UIP"
// [HELPER] s_UNP: "UNP"
// [HELPER] s_VIDEOMEMORY: "VIDEOMEMORY"
// [HELPER] s_VIDEO_MEMORY: "VIDEO MEMORY"
// [HELPER] s_WINDOW: "WINDOW"
// [HELPER] s_WING: "WING"
// [HELPER] s_WORLD_: "WORLD="
// [HELPER] s__: "}"
// [HELPER] shape_file_first: " "
// [HELPER] sound_file_first: " "
undefined4 __fastcall FUN_0041d092(RGE_Base_Game *param_1)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_200 [252];
  undefined1 auStack_104 [3];
  undefined1 uStack_101;
  
  strncpy(auStack_200,param_1->prog_info->cmd_line,0xff);
  uStack_101 = 0;
  CharUpperA(auStack_200);
  iVar2 = strstr(&stack0xfffffdfc,s_NOSTARTUP);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_NO_STARTUP), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_NO_STARTUP), iVar2 != 0)) {
    param_1->prog_info->skip_startup = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_SYSTEMMEMORY);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_SYSTEM_MEMORY), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_SYSTEM_MEMORY), iVar2 != 0)) {
    param_1->prog_info->use_sys_mem = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_MIDIMUSIC);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_MIDI_MUSIC), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_MIDI_MUSIC), iVar2 != 0)) {
    param_1->prog_info->use_music = 1;
    param_1->prog_info->use_cd_audio = 0;
    param_1->prog_info->use_ima = 0;
    param_1->prog_info->use_midi = 1;
    param_1->prog_info->use_wave_music = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_MSYNC);
  if (iVar2 != 0) {
    param_1->mouse_blit_sync = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_MFILL);
  DDSys_CanColorFill = (int)(iVar2 == 0);
  iVar2 = strstr(&stack0xfffffdfc,s_NOSOUND);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_NO_SOUND), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_NO_SOUND), iVar2 != 0)) {
    param_1->prog_info->use_sound = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_640);
  if (iVar2 != 0) {
    param_1->prog_info->main_wid = 0x280;
    param_1->prog_info->main_hgt = 0x1e0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_800);
  if (iVar2 != 0) {
    param_1->prog_info->main_wid = 800;
    param_1->prog_info->main_hgt = 600;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_1024);
  if (iVar2 != 0) {
    param_1->prog_info->main_wid = 0x400;
    param_1->prog_info->main_hgt = 0x300;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_ALLCP);
  if (iVar2 != 0) {
    all_cp = 1;
    do_run_log = 1;
    param_1->comm_speed = 0;
    do_debug_timeGetTime = 1;
    debug_timeGetTime_interval = 10;
    do_fixed_update = 1;
    fixed_update_time = 0x14;
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_RESEND1_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    resend_adj1 = atol(auStack_104);
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_RESEND2_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    resend_adj2 = atol(auStack_104);
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NOMOUSE);
  if ((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_NO_MOUSE), iVar2 != 0)) {
    param_1->custom_mouse = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_WING);
  if (iVar2 != 0) {
    param_1->prog_info->full_screen = 0;
    param_1->prog_info->use_dir_draw = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DIRECTDRAW);
  if ((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_DIRECT_DRAW), iVar2 != 0)) {
    param_1->prog_info->use_dir_draw = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_FULLSCREEN);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_FULL_SCREEN), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_FULL_SCREEN), iVar2 != 0)) {
    param_1->prog_info->full_screen = 1;
    param_1->prog_info->use_dir_draw = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_VIDEOMEMORY);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_VIDEO_MEMORY), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_VIDEO_MEMORY), iVar2 != 0)) {
    param_1->prog_info->use_sys_mem = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_STREAMMUSIC);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_STREAM_MUSIC), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_STREAM_MUSIC), iVar2 != 0)) {
    param_1->prog_info->use_music = 1;
    param_1->prog_info->use_cd_audio = 0;
    param_1->prog_info->use_ima = 0;
    param_1->prog_info->use_midi = 0;
    param_1->prog_info->use_wave_music = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_IMAMUSIC);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_IMA_MUSIC), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_IMA_MUSIC), iVar2 != 0)) {
    param_1->prog_info->use_music = 1;
    param_1->prog_info->use_cd_audio = 0;
    param_1->prog_info->use_ima = 1;
    param_1->prog_info->use_midi = 0;
    param_1->prog_info->use_wave_music = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_FASTVIEW);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_FAST_VIEW), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_FAST_VIEW), iVar2 != 0)) {
    param_1->prog_info->fast_view = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_SLOWVIEW);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_SLOW_VIEW), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_SLOW_VIEW), iVar2 != 0)) {
    param_1->prog_info->fast_view = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_ONEBUTTON);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_ONE_BUTTON), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_ONE_BUTTON), iVar2 != 0)) {
    param_1->prog_info->interface_style = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_TWOBUTTON);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_TWO_BUTTON), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_TWO_BUTTON), iVar2 != 0)) {
    param_1->prog_info->interface_style = 2;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_RUNLOG);
  if (iVar2 != 0) {
    do_run_log = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_SYNCMSG);
  if (iVar2 != 0) {
    param_1->comm_syncmsg = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DROPPACKETS);
  if (iVar2 != 0) {
    param_1->comm_droppackets = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NOCOMMSPEED);
  if (iVar2 != 0) {
    param_1->comm_speed = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_SYNCSTOP);
  if (iVar2 != 0) {
    param_1->comm_syncstop = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_STEPMODE);
  if (iVar2 != 0) {
    param_1->comm_stepmode = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_SQUAREOUTLINE);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_SQUARE_OUTLINE), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_SQUARE_OUTLINE), iVar2 != 0)) {
    param_1->outline_type = '\0';
  }
  iVar2 = strstr(&stack0xfffffdfc,s_CUBEOUTLINE);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_CUBE_OUTLINE), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_CUBE_OUTLINE), iVar2 != 0)) {
    param_1->outline_type = '\x01';
  }
  iVar2 = strstr(&stack0xfffffdfc,s_GROUNDOUTLINE);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_GROUND_OUTLINE), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_GROUND_OUTLINE), iVar2 != 0)) {
    param_1->outline_type = '\x02';
  }
  iVar2 = strstr(&stack0xfffffdfc,s_EDGEOUTLINE);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_EDGE_OUTLINE), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_EDGE_OUTLINE), iVar2 != 0)) {
    param_1->outline_type = '\x03';
  }
  iVar2 = strstr(&stack0xfffffdfc,s_CUSTOMMOUSE);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_CUSTOM_MOUSE), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_CUSTOM_MOUSE), iVar2 != 0)) {
    param_1->custom_mouse = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NOCP);
  if (iVar2 != 0) {
    useComputerPlayers = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_LOGAI);
  if (iVar2 != 0) {
    startLoggingAI = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NOLOGSTATUS);
  if (iVar2 != 0) {
    logStatusOn = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DOLOGSTATUS);
  if (iVar2 != 0) {
    logStatusOn = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NOAICHEAT);
  if (iVar2 != 0) {
    allowAIToCheat = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NOCHATCHEATCODES);
  if (iVar2 != 0) {
    chatCheatCodes = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_LOGUPDATECHANGES);
  if (iVar2 != 0) {
    logUpdateChanges = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_UIP);
  if (iVar2 != 0) {
    useInfluencePlacement = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_ALLGRASS);
  if (iVar2 != 0) {
    all_grassland_on = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_ALLCP);
  if (iVar2 != 0) {
    all_cp = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_ALLCP1);
  if (iVar2 != 0) {
    all_cp = 2;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NOPATHLIMIT);
  if (iVar2 != 0) {
    numberPathingIterations = -1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_UNP);
  if (iVar2 != 0) {
    useNewPathing = -1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_COLORLOG);
  if (iVar2 != 0) {
    do_color_log = '\x01';
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_LOGAI_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    specificAIPlayerToLog = atol(auStack_104);
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_LOGDEBUG_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    logDebugID = atol(auStack_104);
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NOPATHCAP);
  if (iVar2 != 0) {
    pathingCapValue = -1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_GAMECD);
  if (iVar2 != 0) {
    force_cd = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_1280);
  if (iVar2 != 0) {
    param_1->prog_info->main_wid = 0x500;
    param_1->prog_info->main_hgt = 0x400;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_LOGFPS);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_LOG_FPS), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_LOG_FPS), iVar2 != 0)) {
    do_fps_log = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DDERRORLOG);
  if (iVar2 != 0) {
    Sys_DDLOG_Enable = 1;
    Sys_DDLOG_ErrorOn = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DDLOG);
  if (iVar2 != 0) {
    Sys_DDLOG_Enable = 1;
    Sys_DDLOG_ErrorOn = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DDFLUSHLOG);
  if (iVar2 != 0) {
    DDlogAutoFlush = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DDNOFLUSHLOG);
  if (iVar2 != 0) {
    DDlogAutoFlush = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DDLOCKLOG);
  if (iVar2 != 0) {
    debug_log_lock = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_LOGRANDOM);
  if (iVar2 != 0) {
    do_debug_random = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_FIXEDUPDATE);
  if (iVar2 != 0) {
    do_debug_timeGetTime = 1;
    do_fixed_update = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_LOGACTION);
  if (iVar2 != 0) {
    debugActions = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_RES_WARN);
  if (iVar2 != 0) {
    RESFILE_Set_Missing_Flag(1);
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_SCENARIOS_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    param_1->prog_info->scenario_dir[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(param_1->prog_info->scenario_dir,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    __mbsncat(param_1->prog_info->scenario_dir,s__,1);
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_WORLD_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    param_1->prog_info->world_db_file[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(param_1->prog_info->world_db_file,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_FIXEDUPDATE_);
  if (pcVar3 != (char *)0x0) {
    do_debug_timeGetTime = 1;
    do_fixed_update = 1;
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    fixed_update_time = atol(auStack_104);
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_AISPEED_);
  if (pcVar3 != (char *)0x0) {
    do_debug_timeGetTime = 1;
    do_fixed_update = 1;
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    debug_timeGetTime_interval = atol(auStack_104);
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_RANDOMGAME_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    iVar2 = atol(auStack_104);
    param_1->random_game_seed = iVar2;
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_RANDOMMAP_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    iVar2 = atol(auStack_104);
    param_1->random_map_seed = iVar2;
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_DRAWLOG_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    draw_log_name._0_1_ = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(&draw_log_name,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DRAWLOG);
  if (iVar2 != 0) {
    do_draw_log = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_SAFEDRAWLOG);
  if (iVar2 != 0) {
    safe_draw_log = 1;
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_DATA_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    param_1->prog_info->game_data_file[0] = '\0';
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(param_1->prog_info->game_data_file,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
  }
  iVar2 = strstr(&stack0xfffffdfc,s_CDAUDIO);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_CD_AUDIO), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_CD_AUDIO), iVar2 != 0)) {
    param_1->prog_info->use_music = 1;
    param_1->prog_info->use_cd_audio = 1;
    param_1->prog_info->use_ima = 0;
    param_1->prog_info->use_midi = 0;
    param_1->prog_info->use_wave_music = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_WINDOW);
  if (iVar2 != 0) {
    param_1->prog_info->full_screen = 0;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_FILEFIRST);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_FILE_FIRST), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_FILE_FIRST), iVar2 != 0)) {
    shape_file_first = '\x01';
    sound_file_first = '\x01';
  }
  iVar2 = strstr(&stack0xfffffdfc,s_LOGCOMM);
  if ((((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_LOG_COMM), iVar2 != 0)) ||
      (iVar2 = strstr(&stack0xfffffdfc,s_LOG_COMM), iVar2 != 0)) &&
     (param_1->log_comm = 1, L != (TDebuggingLog *)0x0)) {
    TDebuggingLog::LogFile(L,1);
    TDebuggingLog::LogTimestamp(L,1);
  }
  iVar2 = strstr(&stack0xfffffdfc,s_LOGOUTPUT);
  if ((((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_LOG_OUTPUT), iVar2 != 0)) ||
      (iVar2 = strstr(&stack0xfffffdfc,s_LOG_OUTPUT), iVar2 != 0)) &&
     (log_output = 1, L != (TDebuggingLog *)0x0)) {
    TDebuggingLog::LogOutput(L,1);
  }
  iVar2 = strstr(&stack0xfffffdfc,s_DEVELOPER);
  if (iVar2 != 0) {
    RGE_Base_Game::setGameDeveloperMode(param_1,1);
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_SPEED1_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    speed_val1 = atol(auStack_104);
  }
  pcVar3 = (char *)__mbsstr(&stack0xfffffdfc,s_SPEED2_);
  if (pcVar3 != (char *)0x0) {
    cVar1 = *pcVar3;
    while (cVar1 != '=') {
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      cVar1 = *pcVar3;
    }
    pcVar3 = (char *)__mbsninc(pcVar3,1);
    auStack_104[0] = 0;
    iVar2 = __ismbcspace(*pcVar3);
    while ((iVar2 == 0 && (*pcVar3 != '\0'))) {
      __mbsncat(auStack_104,pcVar3,1);
      pcVar3 = (char *)__mbsninc(pcVar3,1);
      iVar2 = __ismbcspace(*pcVar3);
    }
    speed_val2 = atol(auStack_104);
  }
  if ((((param_1->prog_info->use_sound == 0) ||
       (iVar2 = strstr(&stack0xfffffdfc,s_NOMUSIC), iVar2 != 0)) ||
      (iVar2 = strstr(&stack0xfffffdfc,s_NO_MUSIC), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_NO_MUSIC), iVar2 != 0)) {
    param_1->prog_info->use_music = 0;
  }
  if ((param_1->prog_info->use_dir_draw == 1) && (param_1->prog_info->full_screen == 1)) {
    param_1->custom_mouse = 1;
  }
  iVar2 = strstr(&stack0xfffffdfc,s_NORMALMOUSE);
  if (((iVar2 != 0) || (iVar2 = strstr(&stack0xfffffdfc,s_NORMAL_MOUSE), iVar2 != 0)) ||
     (iVar2 = strstr(&stack0xfffffdfc,s_NORMAL_MOUSE), iVar2 != 0)) {
    param_1->custom_mouse = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041e6fe
// Address: 0041e6fe
// XREFS: None
// [HELPER] s_: ""
bool __fastcall FUN_0041e6fe(int param_1)
{
  int iVar1;
  short sVar2;
  undefined4 uStack_28;
  code *pcStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  char *pcStack_8;
  int iStack_4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0x414) != 0) {
    return true;
  }
  uStack_10 = 0;
  pcStack_8 = s_;
  if (*(char *)(iVar1 + 0x645) != '\0') {
    pcStack_8 = (char *)(iVar1 + 0x645);
  }
  uStack_14 = LoadIconA(*(undefined4 *)(iVar1 + 0x410),iVar1 + 0x61c);
  iStack_4 = *(int *)(param_1 + 0xc);
  uStack_c = 0;
  uStack_18 = *(undefined4 *)(iStack_4 + 0x410);
  uStack_28 = 0xb;
  pcStack_24 = rge_base_game_wnd_proc;
  uStack_1c = 0;
  uStack_20 = 0;
  sVar2 = RegisterClassA(&uStack_28);
  return sVar2 != 0;
}

// --------------------------------------------------

// Function: FUN_0041e798
// Address: 0041e798
// XREFS: None
undefined4 FUN_0041e798(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
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

// Function: FUN_0041e7cb
// Address: 0041e7cb
// XREFS: None
undefined4 __fastcall FUN_0041e7cb(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined1 auStack_10 [8];
  int iStack_8;
  int iStack_4;
  
  iVar1 = GetSystemMetrics(0);
  iVar2 = GetSystemMetrics(1);
  iVar3 = *(int *)(param_1 + 0xc);
  if ((*(int *)(iVar3 + 0x894) == 0) &&
     ((iVar1 != *(int *)(iVar3 + 0x8e0) || (iVar2 != *(int *)(iVar3 + 0x8e4))))) {
    uVar5 = *(undefined4 *)(iVar3 + 0x410);
    iVar2 = *(int *)(iVar3 + 0x8e4);
    uVar4 = 0x2ca0000;
    iVar1 = *(int *)(iVar3 + 0x8e0);
  }
  else {
    uVar5 = *(undefined4 *)(iVar3 + 0x410);
    uVar4 = 0x82080000;
  }
  iVar3 = CreateWindowExA(0,iVar3,iVar3 + 0x7a,uVar4,0,0,iVar1,iVar2,0,0,uVar5,0);
  *(int *)(param_1 + 0x10) = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  GetWindowRect(iVar3,&iStack_20);
  GetClientRect(*(undefined4 *)(param_1 + 0x10),auStack_10);
  iVar3 = *(int *)(param_1 + 0xc);
  if ((iStack_8 != *(int *)(iVar3 + 0x8e0)) || (iStack_4 != *(int *)(iVar3 + 0x8e4))) {
    SetWindowPos(*(undefined4 *)(param_1 + 0x10),0,iStack_20,iStack_1c,
                 ((iStack_18 - iStack_20) - iStack_8) + *(int *)(iVar3 + 0x8e0),
                 ((*(int *)(iVar3 + 0x8e4) - iStack_1c) - iStack_4) + iStack_14,0);
  }
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x894) != 0) {
    ShowWindow(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x618));
    UpdateWindow(*(undefined4 *)(param_1 + 0x10));
    SetFocus(*(undefined4 *)(param_1 + 0x10));
  }
  AppWnd = *(void **)(param_1 + 0x10);
  TPanelSystem::DisableIME(&panel_system);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041e91a
// Address: 0041e91a
// XREFS: None
undefined4 __fastcall FUN_0041e91a(int param_1)
{
  int iVar1;
  int iVar2;
  TDrawArea *this;
  undefined4 uVar3;
  int iVar4;
  TDrawSystem *pTVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ca7b;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x89c) != 0) {
    uVar3 = GetDC(0);
    iVar4 = GetDeviceCaps(uVar3,0xc);
    ReleaseDC(0,uVar3);
    if (iVar4 < 8) {
      *(undefined4 *)(param_1 + 0x40) = 0x13;
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
  }
  iVar4 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(iVar4 + 0x89c);
  iVar2 = *(int *)(iVar4 + 0x8a0);
  iVar4 = *(int *)(iVar4 + 0x894);
  pTVar5 = (TDrawSystem *)operator_new(0x47c);
  uStack_4 = 0;
  if (pTVar5 == (TDrawSystem *)0x0) {
    pTVar5 = (TDrawSystem *)0x0;
  }
  else {
    pTVar5 = (TDrawSystem *)TDrawSystem::TDrawSystem(pTVar5);
  }
  uStack_4 = 0xffffffff;
  *(TDrawSystem **)(param_1 + 0x48) = pTVar5;
  if (pTVar5 == (TDrawSystem *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  TDrawSystem::CheckAvailModes(pTVar5,*(int *)(*(int *)(param_1 + 0xc) + 0x894));
  iVar6 = TDrawSystem::IsModeAvail
                    (*(TDrawSystem **)(param_1 + 0x48),*(long *)(*(int *)(param_1 + 0xc) + 0x8e0),0,
                     8);
  if (iVar6 == 0) {
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x8e0) != 0x280) {
      iVar6 = TDrawSystem::IsModeAvail(*(TDrawSystem **)(param_1 + 0x48),0x280,0,8);
      if (iVar6 != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x8e0) = 0x280;
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x8e4) = 0x1e0;
        goto LAB_0041eb16;
      }
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x8e0) != 800) {
      iVar6 = TDrawSystem::IsModeAvail(*(TDrawSystem **)(param_1 + 0x48),800,0,8);
      if (iVar6 != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x8e0) = 800;
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x8e4) = 600;
        goto LAB_0041eb16;
      }
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x8e0) != 0x400) {
      iVar6 = TDrawSystem::IsModeAvail(*(TDrawSystem **)(param_1 + 0x48),0x400,0,8);
      if (iVar6 != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x8e0) = 0x400;
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x8e4) = 0x300;
        goto LAB_0041eb16;
      }
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x8e0) == 0x500) goto LAB_0041eb4d;
    iVar6 = TDrawSystem::IsModeAvail(*(TDrawSystem **)(param_1 + 0x48),0x400,0,8);
    if (iVar6 == 0) goto LAB_0041eb4d;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x8e0) = 0x500;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x8e4) = 0x400;
  }
LAB_0041eb16:
  iVar6 = *(int *)(param_1 + 0xc);
  iVar4 = TDrawSystem::Init(*(TDrawSystem **)(param_1 + 0x48),*(void **)(iVar6 + 0x410),
                            *(void **)(param_1 + 0x10),*(void **)(param_1 + 0x1c),
                            (iVar1 != 0) + '\x01',(iVar4 != 0) + '\x01',*(long *)(iVar6 + 0x8e0),
                            *(long *)(iVar6 + 0x8e4),(uint)(iVar2 != 0));
  if (iVar4 != 0) {
    TPanelSystem::release_palette(&panel_system,*(void **)(param_1 + 0x1c));
    pvVar7 = TPanelSystem::get_palette
                       (&panel_system,(char *)(*(int *)(param_1 + 0xc) + 0x66e),0xc544);
    *(void **)(param_1 + 0x1c) = pvVar7;
    this = *(TDrawArea **)(*(int *)(param_1 + 0x48) + 0xc);
    *(TDrawArea **)(param_1 + 0x4c) = this;
    TDrawArea::Clear(this,(tagRECT *)0x0,0);
    TDrawSystem::Paint(*(TDrawSystem **)(param_1 + 0x48),(tagRECT *)0x0);
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
LAB_0041eb4d:
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041ebe9
// Address: 0041ebe9
// XREFS: None
// [HELPER] s_Custom_Mouse: "Custom Mouse"
undefined4 __fastcall FUN_0041ebe9(RGE_Base_Game *param_1)
{
  int iVar1;
  TMousePointer *pTVar2;
  RGE_Base_Game *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055ca9b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = TRegistry::RegGetInt(param_1->registry,0,s_Custom_Mouse);
  if (iVar1 == -1) {
    TRegistry::RegSetInt(param_1->registry,0,s_Custom_Mouse,0);
  }
  else {
    if (iVar1 == 1) {
      pRVar3 = (RGE_Base_Game *)0x1;
      goto LAB_0041ec3b;
    }
    if (iVar1 == 2) {
      param_1->custom_mouse = 0;
      pRVar3 = param_1;
      goto LAB_0041ec3b;
    }
  }
  pRVar3 = (RGE_Base_Game *)0x0;
LAB_0041ec3b:
  pTVar2 = (TMousePointer *)operator_new(0x254);
  uStack_4 = 0;
  if (pTVar2 == (TMousePointer *)0x0) {
    pTVar2 = (TMousePointer *)0x0;
  }
  else {
    pTVar2 = (TMousePointer *)TMousePointer::TMousePointer(pTVar2,(int)pRVar3);
  }
  uStack_4 = 0xffffffff;
  param_1->mouse_pointer = pTVar2;
  if (pTVar2 == (TMousePointer *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  iVar1 = TMousePointer::setup
                    (pTVar2,param_1->custom_mouse,param_1->draw_area,param_1->prog_info->cursor_file
                     ,51000,10);
  if (iVar1 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  RGE_Base_Game::mouse_off(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041ecfe
// Address: 0041ecfe
// XREFS: None
bool __fastcall FUN_0041ecfe(int param_1)
{
  TChat *this;
  undefined4 *unaff_FS_OFFSET;
  bool bVar1;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cabb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TChat *)operator_new(0x100);
  uStack_4 = 0;
  if (this == (TChat *)0x0) {
    chat = (TChat *)0x0;
  }
  else {
    chat = (TChat *)TChat::TChat(this,*(void **)(param_1 + 0x10));
  }
  bVar1 = chat != (TChat *)0x0;
  *unaff_FS_OFFSET = uStack_c;
  return bVar1;
}

// --------------------------------------------------

// Function: FUN_0041ed63
// Address: 0041ed63
// XREFS: None
bool __fastcall FUN_0041ed63(int param_1)
{
  TRegistry *this;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cadb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRegistry *)operator_new(0x110);
  uStack_4 = 0;
  if (this == (TRegistry *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = TRegistry::TRegistry(this,(char *)(*(int *)(param_1 + 0xc) + 0x418));
  }
  *(int *)(param_1 + 0x1ac) = iVar1;
  *unaff_FS_OFFSET = uStack_c;
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_0041edda
// Address: 0041edda
// XREFS: None
undefined4 __fastcall FUN_0041edda(int param_1)
{
  TDebuggingLog *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cafb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = (TDebuggingLog *)operator_new(0x7b0);
  uStack_4 = 0;
  if (pTVar1 == (TDebuggingLog *)0x0) {
    pTVar1 = (TDebuggingLog *)0x0;
  }
  else {
    pTVar1 = (TDebuggingLog *)TDebuggingLog::TDebuggingLog(pTVar1);
  }
  uStack_4 = 0xffffffff;
  *(TDebuggingLog **)(param_1 + 0x1a4) = pTVar1;
  if (pTVar1 == (TDebuggingLog *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  TDebuggingLog::LogFile(pTVar1,*(int *)(param_1 + 0x1a8));
  TDebuggingLog::LogOutput(*(TDebuggingLog **)(param_1 + 0x1a4),log_output);
  TDebuggingLog::LogTimestamp(*(TDebuggingLog **)(param_1 + 0x1a4),1);
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041ee85
// Address: 0041ee85
// XREFS: None
undefined4 __fastcall FUN_0041ee85(int param_1)
{
  TCommunications_Handler *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cb1b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = (TCommunications_Handler *)operator_new(0x1774);
  uStack_4 = 0;
  if (pTVar1 == (TCommunications_Handler *)0x0) {
    pTVar1 = (TCommunications_Handler *)0x0;
  }
  else {
    pTVar1 = (TCommunications_Handler *)
             TCommunications_Handler::TCommunications_Handler
                       (pTVar1,*(void **)(param_1 + 0x10),
                        *(uchar *)(*(int *)(param_1 + 0xc) + 0x878),chat,
                        *(_GUID *)(*(int *)(param_1 + 0xc) + 0x8e8));
  }
  uStack_4 = 0xffffffff;
  *(TCommunications_Handler **)(param_1 + 0x18c) = pTVar1;
  if (pTVar1 == (TCommunications_Handler *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  TCommunications_Handler::StopIfSyncFail(pTVar1,*(int *)(param_1 + 400));
  TCommunications_Handler::ShowSyncChatMsgs
            (*(TCommunications_Handler **)(param_1 + 0x18c),*(int *)(param_1 + 0x198));
  TCommunications_Handler::SetStepMode
            (*(TCommunications_Handler **)(param_1 + 0x18c),*(int *)(param_1 + 0x19c));
  TCommunications_Handler::SetSpeedControl
            (*(TCommunications_Handler **)(param_1 + 0x18c),*(int *)(param_1 + 0x1a0));
  TCommunications_Handler::DropPacketsIntentionally
            (*(TCommunications_Handler **)(param_1 + 0x18c),*(int *)(param_1 + 0x194));
  comm = *(TCommunications_Handler **)(param_1 + 0x18c);
  if (*(RGE_Game_World **)(param_1 + 0x3f4) != (RGE_Game_World *)0x0) {
    RGE_Game_World::reset_communications
              (*(RGE_Game_World **)(param_1 + 0x3f4),*(TCommunications_Handler **)(param_1 + 0x18c))
    ;
  }
  if (speed_val1 != 0) {
    TCommunications_Handler::SetSpeedV1(*(TCommunications_Handler **)(param_1 + 0x18c),speed_val1);
  }
  if (speed_val2 != 0) {
    TCommunications_Handler::SetSpeedV1(*(TCommunications_Handler **)(param_1 + 0x18c),speed_val2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041efe6
// Address: 0041efe6
// XREFS: None
void __fastcall FUN_0041efe6(int *param_1)
{
  TCommunications_Handler *this;
  
  this = (TCommunications_Handler *)param_1[99];
  if (this != (TCommunications_Handler *)0x0) {
    TCommunications_Handler::~TCommunications_Handler(this);
    operator_delete(this);
    param_1[99] = 0;
    comm = (TCommunications_Handler *)0x0;
  }
  (**(code **)(*param_1 + 0x88))();
  return;
}

// --------------------------------------------------

// Function: FUN_0041f02f
// Address: 0041f02f
// XREFS: None
// [HELPER] s_Sound_Volume: "Sound Volume"
undefined4 __fastcall FUN_0041f02f(int *param_1)
{
  TSound_Driver *pTVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cb3b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar3 = 0;
  if (*(int *)(param_1[3] + 0x8a8) != 0) {
    pTVar1 = (TSound_Driver *)operator_new(0x69c);
    uStack_4 = 0;
    if (pTVar1 == (TSound_Driver *)0x0) {
      pTVar1 = (TSound_Driver *)0x0;
    }
    else {
      pTVar1 = (TSound_Driver *)
               TSound_Driver::TSound_Driver(pTVar1,(void *)param_1[4],(char *)(param_1[3] + 0xe21));
    }
    uStack_4 = 0xffffffff;
    param_1[0x18] = (int)pTVar1;
    if (pTVar1 != (TSound_Driver *)0x0) {
      iVar2 = TSound_Driver::driver_active(pTVar1);
      if (iVar2 == 0) {
        pTVar1 = (TSound_Driver *)param_1[0x18];
        if (pTVar1 != (TSound_Driver *)0x0) {
          TSound_Driver::~TSound_Driver(pTVar1);
          operator_delete(pTVar1);
        }
        param_1[0x18] = 0;
        goto LAB_0041f0f9;
      }
    }
    sound_driver = (TSound_Driver *)param_1[0x18];
    iVar2 = TRegistry::RegGetInt((TRegistry *)param_1[0x6b],1,s_Sound_Volume);
    if (iVar2 != -1) {
      iVar3 = -iVar2;
    }
    TSound_Driver::set_volume((TSound_Driver *)param_1[0x18],iVar3,1);
  }
  (**(code **)(*param_1 + 0x58))();
LAB_0041f0f9:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041f2ca
// Address: 0041f2ca
// XREFS: None
// [HELPER] s_groupnum_shp: "groupnum.shp"
// [HELPER] s_moveto_shp: "moveto.shp"
// [HELPER] s_waypoint_shp: "waypoint.shp"
undefined4 __fastcall FUN_0041f2ca(int param_1)
{
  int iVar1;
  TShape *pTVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cb91;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined2 *)(param_1 + 0x58) = 3;
  iVar1 = calloc(3,4);
  *(int *)(param_1 + 0x5c) = iVar1;
  if (iVar1 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  iVar1 = 0;
  if (0 < *(short *)(param_1 + 0x58)) {
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x5c) + -4 + iVar1 * 4) = 0;
    } while (iVar1 < *(short *)(param_1 + 0x58));
  }
  pTVar2 = (TShape *)operator_new(0x20);
  uStack_4 = 0;
  if (pTVar2 == (TShape *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TShape::TShape(pTVar2,s_groupnum_shp,0xc4e3);
  }
  uStack_4 = 0xffffffff;
  **(undefined4 **)(param_1 + 0x5c) = uVar3;
  pTVar2 = (TShape *)operator_new(0x20);
  uStack_4 = 1;
  if (pTVar2 == (TShape *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TShape::TShape(pTVar2,s_waypoint_shp,0xc4e4);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 4) = uVar3;
  pTVar2 = (TShape *)operator_new(0x20);
  uStack_4 = 2;
  if (pTVar2 == (TShape *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TShape::TShape(pTVar2,s_moveto_shp,0xc4e5);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 8) = uVar3;
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041f3f1
// Address: 0041f3f1
// XREFS: None
// [HELPER] s_button1_wav: "button1.wav"
// [HELPER] s_button2_wav: "button2.wav"
// [HELPER] s_chatrcvd_wav: "chatrcvd.wav"
undefined4 __fastcall FUN_0041f3f1(int param_1)
{
  int iVar1;
  TDigital *pTVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cbc1;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined2 *)(param_1 + 0x68) = 3;
  iVar1 = calloc(3,4);
  *(int *)(param_1 + 0x6c) = iVar1;
  if (iVar1 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  iVar1 = 0;
  if (0 < *(short *)(param_1 + 0x68)) {
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x6c) + -4 + iVar1 * 4) = 0;
    } while (iVar1 < *(short *)(param_1 + 0x68));
  }
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 0;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_button1_wav,0xc47c);
  }
  uStack_4 = 0xffffffff;
  **(undefined4 **)(param_1 + 0x6c) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 1;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_button2_wav,0xc47d);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 4) = uVar3;
  pTVar2 = (TDigital *)operator_new(0x3c);
  uStack_4 = 2;
  if (pTVar2 == (TDigital *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = TDigital::TDigital(pTVar2,*(TSound_Driver **)(param_1 + 0x60),s_chatrcvd_wav,0xc47e);
  }
  iVar1 = 0;
  uStack_4 = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x6c) + 8) = uVar3;
  if (0 < *(short *)(param_1 + 0x68)) {
    do {
      pTVar2 = *(TDigital **)(*(int *)(param_1 + 0x6c) + iVar1 * 4);
      if (pTVar2 != (TDigital *)0x0) {
        TDigital::load(pTVar2,(char *)0x0,-1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(short *)(param_1 + 0x68));
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041f55b
// Address: 0041f55b
// XREFS: None
// [HELPER] s_basegame__setup_fonts: "basegame::setup_fonts"
undefined4 __fastcall FUN_0041f55b(RGE_Base_Game *param_1)
{
  RGE_Font *pRVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  short sVar5;
  void *pvVar6;
  int aiStack_38 [4];
  int iStack_28;
  long lStack_24;
  
  param_1->font_num = 0xc;
  pRVar1 = (RGE_Font *)calloc(0xc,0xc);
  param_1->fonts = pRVar1;
  if (pRVar1 == (RGE_Font *)0x0) {
    return 0;
  }
  pvVar2 = TDrawArea::GetDc(param_1->draw_area,s_basegame__setup_fonts);
  if (pvVar2 != (void *)0x0) {
    sVar5 = 0;
    if (0 < param_1->font_num) {
      do {
        iVar3 = (int)sVar5;
        switch(iVar3) {
        case 0:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x6e,0);
          break;
        case 1:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x71,0);
          break;
        default:
          pvVar6 = (void *)0x0;
          break;
        case 4:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x74,0);
          break;
        case 6:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x83,0);
          break;
        case 7:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x77,0);
          break;
        case 8:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x80,1);
          break;
        case 9:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x7a,0);
          break;
        case 10:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x7d,0);
          break;
        case 0xb:
          pvVar6 = RGE_Base_Game::make_font(param_1,pvVar2,0x80,0);
        }
        if (pvVar6 != (void *)0x0) {
          uVar4 = SelectObject(pvVar2,pvVar6);
          GetTextMetricsA(pvVar2,aiStack_38);
          param_1->fonts[iVar3].font = pvVar6;
          param_1->fonts[iVar3].font_wid = lStack_24;
          param_1->fonts[iVar3].font_hgt = aiStack_38[0] + iStack_28;
          SelectObject(pvVar2,uVar4);
        }
        sVar5 = sVar5 + 1;
      } while (sVar5 < param_1->font_num);
    }
    TDrawArea::ReleaseDc(param_1->draw_area,s_basegame__setup_fonts);
    return 1;
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

// Function: FUN_0041f7f4
// Address: 0041f7f4
// XREFS: None
void __fastcall FUN_0041f7f4(int param_1)
{
  *(undefined4 *)(param_1 + 0x554) = 1;
  *(undefined4 *)(param_1 + 0x574) = 1;
  *(undefined4 *)(param_1 + 0x594) = 1;
  *(undefined4 *)(param_1 + 0x674) = 1;
  *(undefined4 *)(param_1 + 0x6d4) = 1;
  *(undefined4 *)(param_1 + 0x538) = 1;
  *(undefined4 *)(param_1 + 0x5b8) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0041f915
// Address: 0041f915
// XREFS: None
undefined4 __fastcall FUN_0041f915(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[0x18] == 0) {
    iVar1 = *param_1;
    iVar2 = (**(code **)(iVar1 + 0x8c))();
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = (**(code **)(iVar1 + 0x94))();
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = param_1[0xfd];
    if ((iVar2 != 0) && (iVar3 = 0, 0 < *(short *)(iVar2 + 0x2c))) {
      do {
        RGE_Sound::restart_sound
                  (*(RGE_Sound **)(*(int *)(iVar2 + 0x30) + iVar3 * 4),
                   (TSound_Driver *)param_1[0x18]);
        iVar2 = param_1[0xfd];
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(short *)(iVar2 + 0x2c));
    }
    TPanelSystem::restart_sound_system(&panel_system);
    if (chat != (TChat *)0x0) {
      TChat::RestartSoundSystem(chat,(TSound_Driver *)param_1[0x18]);
    }
    (**(code **)(iVar1 + 0xb0))();
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041f9aa
// Address: 0041f9aa
// XREFS: None
void __fastcall FUN_0041f9aa(int param_1)
{
  if (*(TMusic_System **)(param_1 + 100) != (TMusic_System *)0x0) {
    TMusic_System::get_play_info
              (*(TMusic_System **)(param_1 + 100),(uchar *)(param_1 + 0x70),(int *)(param_1 + 0x74),
               (int *)(param_1 + 0x78),(int *)(param_1 + 0x7c),(char *)(param_1 + 0x80),
               (int *)(param_1 + 0x184),(ulong *)(param_1 + 0x188));
    TMusic_System::stop_track(*(TMusic_System **)(param_1 + 100));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041f9ee
// Address: 0041f9ee
// XREFS: None
undefined4 __fastcall FUN_0041f9ee(int param_1)
{
  TMusic_System *this;
  int iVar1;
  
  this = *(TMusic_System **)(param_1 + 100);
  if (this == (TMusic_System *)0x0) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x74);
  if (iVar1 != 0) {
    if (iVar1 == *(int *)(param_1 + 0x78)) {
      TMusic_System::play_track(this,iVar1,*(int *)(param_1 + 0x184),*(ulong *)(param_1 + 0x188));
      return 1;
    }
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x78) != 0)) {
      TMusic_System::play_tracks
                (this,iVar1,*(int *)(param_1 + 0x78),*(int *)(param_1 + 0x184),
                 *(int *)(param_1 + 0x7c),*(ulong *)(param_1 + 0x188));
      return 1;
    }
  }
  if (*(char *)(param_1 + 0x80) != '\0') {
    TMusic_System::play_file
              (this,(char *)(param_1 + 0x80),*(int *)(param_1 + 0x184),*(ulong *)(param_1 + 0x188));
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0041fa85
// Address: 0041fa85
// XREFS: None
// [HELPER] s_Music_Volume: "Music Volume"
void __fastcall FUN_0041fa85(int *param_1)
{
  TMusic_System *this;
  
  if (param_1[0x19] != 0) {
    (**(code **)(*param_1 + 0xac))();
    TRegistry::RegSetInt
              ((TRegistry *)param_1[0x6b],1,s_Music_Volume,-*(int *)(param_1[0x19] + 0x254));
    this = (TMusic_System *)param_1[0x19];
    if (this != (TMusic_System *)0x0) {
      TMusic_System::~TMusic_System(this);
      operator_delete(this);
    }
    param_1[0x19] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0041fae2
// Address: 0041fae2
// XREFS: None
// [HELPER] s_B: "B"
// [HELPER] s_b: "b"
void * __thiscall FUN_0041fae2(RGE_Base_Game *param_1,undefined4 param_2,int param_3)
{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined1 *puStack_13c;
  undefined4 uStack_138;
  int iStack_130;
  undefined1 *puStack_12c;
  undefined4 uStack_128;
  undefined1 auStack_118 [12];
  char cStack_10c;
  undefined1 auStack_100 [224];
  void *pvStack_20;
  int iStack_18;
  
  puStack_12c = auStack_100;
  uStack_128 = 0x100;
  iStack_130 = param_3;
  pcVar1 = *(code **)(param_1->_padding_ + 0x20);
  (*pcVar1)();
  if (cStack_10c == '\0') {
    return (void *)0x0;
  }
  puStack_13c = auStack_118;
  uStack_138 = 10;
  (*pcVar1)(param_3 + 1);
  iVar2 = atoi(&stack0xfffffedc);
  (*pcVar1)(param_3 + 2,&iStack_130,10);
  iVar3 = strstr(&puStack_13c,s_B);
  if (iVar3 == 0) {
    iVar3 = strstr(&puStack_13c,s_b);
    iVar4 = 400;
    if (iVar3 == 0) goto LAB_0041fb90;
  }
  iVar4 = 700;
LAB_0041fb90:
  pvVar5 = RGE_Base_Game::make_font(param_1,pvStack_20,&stack0xfffffedc,iVar2,iVar4,iStack_18);
  return pvVar5;
}

// --------------------------------------------------

// Function: FUN_0041fbbb
// Address: 0041fbbb
// XREFS: None
void __fastcall FUN_0041fbbb(int *param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 unaff_retaddr;
  char acStack_12c [32];
  undefined1 auStack_10c [12];
  undefined1 auStack_100 [252];
  char *pcStack_4;
  
  (**(code **)(*param_1 + 0x20))(0x65,auStack_100,0x100);
  atoi(auStack_10c);
  puVar6 = (undefined4 *)&stack0xfffffeb8;
  for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  MulDiv(unaff_retaddr,0x60,0x48);
  uVar3 = 0xffffffff;
  do {
    pcVar5 = pcStack_4;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcStack_4 + 1;
    cVar1 = *pcStack_4;
    pcStack_4 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar7 = acStack_12c;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  CreateFontIndirectA(&stack0xfffffeb8);
  return;
}

// --------------------------------------------------

// Function: FUN_0041fc8f
// Address: 0041fc8f
// XREFS: None
// [HELPER] s_CDPath: "CDPath"
bool __thiscall FUN_0041fc8f(RGE_Base_Game *param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_20c [4];
  undefined1 auStack_208 [4];
  undefined1 auStack_204 [256];
  undefined1 auStack_104 [260];
  
  if (param_1->prog_info->verify_cd == 0) {
    return true;
  }
  if (0 < param_2) {
    iVar4 = 0;
    uVar5 = 0;
    do {
      uVar1 = uVar5 + 1;
      iVar2 = TCommunications_Handler::GetPlayerHumanity(param_1->comm_handler,uVar1);
      if (iVar2 == 2) {
        iVar2 = RGE_Base_Game::playerHasCD(param_1,uVar5);
        if (iVar2 != 0) {
          iVar4 = iVar4 + 1;
        }
      }
      uVar5 = uVar1;
    } while ((int)uVar1 < 9);
    return param_2 <= param_1->prog_info->max_players_per_cd * iVar4;
  }
  if (force_cd != 0) {
    return true;
  }
  pcVar3 = TRegistry::RegGetAscii(param_1->registry,0,s_CDPath);
  if (pcVar3 == (char *)0x0) {
    return false;
  }
  iVar4 = GetDriveTypeA();
  if (iVar4 != 5) {
    return false;
  }
  iVar4 = GetVolumeInformationA
                    (pcVar3,auStack_204,0x100,&stack0xfffffdf0,auStack_208,auStack_20c,auStack_104);
  if (iVar4 == 0) {
    return false;
  }
  iVar4 = stricmp(&stack0xfffffddc,param_1->prog_info->vol_name);
  return iVar4 == 0;
}

// --------------------------------------------------

// Function: FUN_0041fddb
// Address: 0041fddb
// XREFS: None
bool __fastcall FUN_0041fddb(int param_1)
{
  int iVar1;
  int *piVar2;
  int iStack_28;
  int aiStack_24 [4];
  int iStack_14;
  int iStack_10;
  
  piVar2 = aiStack_24;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  iStack_14 = *(short *)(iVar1 + 0x880) + -1;
  aiStack_24[3] = (int)*(short *)(iVar1 + 0x882);
  iStack_10 = (int)*(short *)(iVar1 + 0x884);
  iVar1 = mktime(aiStack_24);
  time(&iStack_28);
  return iStack_28 <= iVar1;
}

// --------------------------------------------------

// Function: FUN_0041fe46
// Address: 0041fe46
// XREFS: None
// [HELPER] s_LOBBY: "LOBBY"
undefined4 __fastcall FUN_0041fe46(RGE_Base_Game *param_1)
{
  uchar uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  pvVar2 = (void *)CreateMutexA(0,1,param_1->prog_info);
  param_1->prog_mutex = pvVar2;
  iVar3 = GetLastError();
  if (iVar3 != 0xb7) {
    if (param_1->prog_mutex != (void *)0x0) {
      ReleaseMutex(param_1->prog_mutex);
    }
    return 1;
  }
  iVar3 = FindWindowA(param_1->prog_info,param_1->prog_info->prog_title);
  if (iVar3 != 0) {
    uVar1 = RGE_Base_Game::check_prog_argument(param_1,s_LOBBY);
    if (uVar1 != '\0') {
      SendMessageA(iVar3,0x10,0,0);
      if (param_1->prog_mutex == (void *)0x0) {
        return 1;
      }
      ReleaseMutex(param_1->prog_mutex);
      return 1;
    }
    iVar4 = IsIconic(iVar3);
    if (iVar4 != 0) {
      ShowWindow(iVar3,1);
    }
    SetForegroundWindow(iVar3);
    uVar5 = GetLastActivePopup(iVar3);
    BringWindowToTop(uVar5);
  }
  if (param_1->prog_mutex != (void *)0x0) {
    ReleaseMutex(param_1->prog_mutex);
    CloseHandle(param_1->prog_mutex);
    param_1->prog_mutex = (void *)0x0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0041fffd
// Address: 0041fffd
// XREFS: None
void __fastcall FUN_0041fffd(int param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auStack_10 [16];
  
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar1 = GetDC(*(int *)(param_1 + 0x10));
    GetClientRect(*(undefined4 *)(param_1 + 0x10),auStack_10);
    uVar2 = GetStockObject(4);
    FillRect(uVar1,auStack_10,uVar2);
    ReleaseDC(*(undefined4 *)(param_1 + 0x10),uVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042004c
// Address: 0042004c
// XREFS: None
undefined4 FUN_0042004c(void)
{
  RGE_Game_World *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cbfb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Game_World *)operator_new(0x104);
  uStack_4 = 0;
  if (this != (RGE_Game_World *)0x0) {
    uVar1 = RGE_Game_World::RGE_Game_World(this);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004200aa
// Address: 004200aa
// XREFS: None
void __fastcall FUN_004200aa(int param_1)
{
  SendMessageA(*(undefined4 *)(param_1 + 0x10),0x10,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004200c1
// Address: 004200c1
// XREFS: None
undefined4 FUN_004200c1(undefined4 *param_1,undefined4 *param_2)
{
  *param_1 = 0;
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_2[0x36] != 0) {
    (**(code **)*param_2)(1);
    return 0;
  }
  *param_1 = param_2;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00420106
// Address: 00420106
// XREFS: None
void FUN_00420106(int *param_1)
{
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
    *param_1 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042012b
// Address: 0042012b
// XREFS: None
void __thiscall FUN_0042012b(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x1b4) = param_2;
  *(undefined4 *)(param_1 + 0x1b8) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00420147
// Address: 00420147
// XREFS: None
void __thiscall FUN_00420147(int param_1,short param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3f4);
  if ((iVar1 != 0) && (param_2 < *(short *)(iVar1 + 0x3c))) {
    *(short *)(iVar1 + 0x7c) = param_2;
    RGE_Map::clear_map_view_info(*(RGE_Map **)(*(int *)(param_1 + 0x3f4) + 0x28));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042017a
// Address: 0042017a
// XREFS: None
int __fastcall FUN_0042017a(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1b0) == 7) {
    return 0;
  }
  iVar1 = TCommunications_Handler::IsPaused(*(TCommunications_Handler **)(param_1 + 0x18c));
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00420197
// Address: 00420197
// XREFS: None
int __thiscall FUN_00420197(int param_1,int param_2)
{
  if (*(int *)(param_1 + 0x1e4) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 0x1e4) + param_2 * 0xc;
}

// --------------------------------------------------

// Function: FUN_004201bc
// Address: 004201bc
// XREFS: None
int __thiscall FUN_004201bc(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5c);
  if (iVar1 == 0) {
    return iVar1;
  }
  return *(int *)(iVar1 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_004201d4
// Address: 004201d4
// XREFS: None
int __thiscall FUN_004201d4(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 == 0) {
    return iVar1;
  }
  return *(int *)(iVar1 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_004201f4
// Address: 004201f4
// XREFS: None
void __fastcall FUN_004201f4(int param_1)
{
  TCommunications_Handler::TogglePauseGame(*(TCommunications_Handler **)(param_1 + 0x18c));
  if (*(int *)(param_1 + 0x3f4) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x3f4) + 0x1c) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042021e
// Address: 0042021e
// XREFS: None
void __thiscall FUN_0042021e(RGE_Base_Game *param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::get_paused(param_1);
  param_1->save_paused = iVar1;
  if (param_2 != iVar1) {
    if (param_2 != 0) {
      param_1->non_user_pause = param_3;
      RGE_Base_Game::request_pause(param_1);
      return;
    }
    param_1->non_user_pause = 0;
    RGE_Base_Game::request_pause(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00420264
// Address: 00420264
// XREFS: None
void FUN_00420264(uint param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6,
                 uint *param_7)
{
  uint uVar1;
  
  uVar1 = param_2 & 0xffff;
  param_2 = param_2 >> 0x10;
  *param_3 = uVar1;
  param_3[1] = param_2;
  if (60000 < uVar1) {
    *param_3 = uVar1 - 0x10000;
  }
  if (60000 < param_2) {
    param_3[1] = param_2 - 0x10000;
  }
  *param_4 = param_1 & 1;
  *param_5 = param_1 & 2;
  *param_6 = param_1 & 8;
  *param_7 = param_1 & 4;
  return;
}

// --------------------------------------------------

// Function: FUN_004202d7
// Address: 004202d7
// XREFS: None
void __thiscall FUN_004202d7(int param_1,int *param_2)
{
  GetCursorPos(param_2);
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x894) == 0) {
    ScreenToClient(*(undefined4 *)(param_1 + 0x10),param_2);
    if (60000 < *param_2) {
      *param_2 = *param_2 + -0x10000;
    }
    if (60000 < param_2[1]) {
      param_2[1] = param_2[1] + -0x10000;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0042032e
// Address: 0042032e
// XREFS: None
int __fastcall FUN_0042032e(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3f4);
  if (iVar1 == 0) {
    return iVar1;
  }
  if (*(short *)(iVar1 + 0x3c) == 0) {
    return 0;
  }
  if (*(short *)(iVar1 + 0x3c) <= *(short *)(iVar1 + 0x7c)) {
    return 0;
  }
  return *(int *)(*(int *)(iVar1 + 0x40) + *(short *)(iVar1 + 0x7c) * 4);
}

// --------------------------------------------------

// Function: FUN_0042035d
// Address: 0042035d
// XREFS: None
void __fastcall FUN_0042035d(int param_1)
{
  UpdateWindow(*(undefined4 *)(param_1 + 0x10));
  return;
}

// --------------------------------------------------

// Function: FUN_0042036b
// Address: 0042036b
// XREFS: None
void __fastcall FUN_0042036b(int param_1)
{
  if (*(int *)(param_1 + 0x1cc) == 0) {
    if ((*(int *)(param_1 + 0x54) != 0) && (*(int *)(param_1 + 0x1d0) == 0)) {
      TMousePointer::on(*(TMousePointer **)(param_1 + 0x1c0));
      *(undefined4 *)(param_1 + 0x1cc) = 1;
      return;
    }
    SetCursor(*(undefined4 *)(param_1 + 0x1d4));
    SetClassLongA(*(undefined4 *)(param_1 + 0x10),0xfffffff4,*(undefined4 *)(param_1 + 0x1d4));
    *(undefined4 *)(param_1 + 0x1cc) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004203d1
// Address: 004203d1
// XREFS: None
void __fastcall FUN_004203d1(int param_1)
{
  if (*(int *)(param_1 + 0x1cc) != 0) {
    if ((*(int *)(param_1 + 0x54) != 0) && (*(int *)(param_1 + 0x1d0) == 0)) {
      TMousePointer::off(*(TMousePointer **)(param_1 + 0x1c0));
      *(undefined4 *)(param_1 + 0x1cc) = 0;
      return;
    }
    SetCursor(0);
    SetClassLongA(*(undefined4 *)(param_1 + 0x10),0xfffffff4,0);
    *(undefined4 *)(param_1 + 0x1cc) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00420437
// Address: 00420437
// XREFS: None
void __thiscall FUN_00420437(int param_1,undefined4 param_2)
{
  if (*(int *)(param_1 + 0x54) == 0) {
    *(undefined4 *)(param_1 + 0x1d0) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x1d0) = param_2;
    if (*(int *)(param_1 + 0x1d0) == 0) {
      SetCursor(0);
      SetClassLongA(*(undefined4 *)(param_1 + 0x10),0xfffffff4,0);
      if (*(int *)(param_1 + 0x1cc) == 0) {
        TMousePointer::off(*(TMousePointer **)(param_1 + 0x1c0));
        return;
      }
      TMousePointer::on(*(TMousePointer **)(param_1 + 0x1c0));
      return;
    }
  }
  TMousePointer::off(*(TMousePointer **)(param_1 + 0x1c0));
  if (*(int *)(param_1 + 0x1cc) == 0) {
    SetCursor(0);
    SetClassLongA(*(undefined4 *)(param_1 + 0x10),0xfffffff4,0);
    return;
  }
  SetCursor(*(undefined4 *)(param_1 + 0x1d4));
  SetClassLongA(*(undefined4 *)(param_1 + 0x10),0xfffffff4,*(undefined4 *)(param_1 + 0x1d4));
  return;
}

// --------------------------------------------------

// Function: FUN_004204f9
// Address: 004204f9
// XREFS: None
void __thiscall FUN_004204f9(int param_1,void *param_2)
{
  *(void **)(param_1 + 0x1d4) = param_2;
  if (param_2 != (void *)0x0) {
    last_mouse_cursor = param_2;
  }
  if ((*(int *)(param_1 + 0x1cc) != 0) &&
     ((*(int *)(param_1 + 0x54) == 0 || (*(int *)(param_1 + 0x1d0) != 0)))) {
    SetCursor(*(undefined4 *)(param_1 + 0x1d4));
    SetClassLongA(*(undefined4 *)(param_1 + 0x10),0xfffffff4,*(undefined4 *)(param_1 + 0x1d4));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00420555
// Address: 00420555
// XREFS: None
void __thiscall FUN_00420555(int param_1,int param_2)
{
  TMousePointer::set_facet(*(TMousePointer **)(param_1 + 0x1c0),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00420573
// Address: 00420573
// XREFS: None
undefined4 FUN_00420573(undefined4 param_1)
{
  undefined1 auStack_100 [256];
  
  GetWindowTextA(param_1,auStack_100,0xff);
  return 1;
}

// --------------------------------------------------


// GLOBAL FUNCTIONS PART 3800
// Function: FUN_004c5871
// Address: 004c5871
// XREFS: None
uchar __thiscall
FUN_004c5871(int param_1,short *param_2,short *param_3,short *param_4,short *param_5)
{
  uchar uVar1;
  
  if ((*(RGE_Sprite **)(param_1 + 0x10) != (RGE_Sprite *)0x0) &&
     (*(RGE_Active_Sprite_List **)(param_1 + 0x18) != (RGE_Active_Sprite_List *)0x0)) {
    uVar1 = RGE_Active_Sprite_List::get_frame
                      (*(RGE_Active_Sprite_List **)(param_1 + 0x18),param_2,param_3,param_4,param_5,
                       *(RGE_Sprite **)(param_1 + 0x10),(uint)*(byte *)(param_1 + 0x35));
    return uVar1;
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004c58d3
// Address: 004c58d3
// XREFS: None
void __thiscall FUN_004c58d3(RGE_Static_Object *param_1,RGE_Static_Object *param_2)
{
  uchar uVar1;
  
  uVar1 = RGE_Static_Object::more_room(param_2);
  if (uVar1 != '\0') {
    if (param_1->inside_obj != (RGE_Static_Object *)0x0) {
      (**(code **)(param_1->inside_obj->_padding_ + 0xd4))();
    }
    if (param_1->tile != (RGE_Tile *)0x0) {
      (**(code **)(param_1->_padding_ + 0xdc))(param_1->owner,0,0xffffffff);
      RGE_Object_List::remove_node(&param_1->tile->objects,param_1,(RGE_Object_Node *)0x0);
      param_1->tile = (RGE_Tile *)0x0;
    }
    RGE_Static_Object::removeFromObstructionMap(param_1,2);
    RGE_Object_List::add_node(param_2->objects,param_1);
    param_1->inside_obj = param_2;
    param_1->world_x = param_2->world_x;
    param_1->world_y = param_2->world_y;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c5956
// Address: 004c5956
// XREFS: None
void __fastcall FUN_004c5956(RGE_Static_Object *param_1)
{
  if (param_1->inside_obj != (RGE_Static_Object *)0x0) {
    RGE_Object_List::remove_node(param_1->inside_obj->objects,param_1,(RGE_Object_Node *)0x0);
    param_1->inside_obj = (RGE_Static_Object *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c597e
// Address: 004c597e
// XREFS: None
LOSTBL * __fastcall FUN_004c597e(int param_1)
{
  int iVar1;
  int iVar2;
  LOSTBL *pLVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    return (LOSTBL *)0x0;
  }
  iVar4 = 0;
  iVar2 = __ftol();
  pLVar3 = RGE_Visible_Map::get_los_table(*(RGE_Visible_Map **)(iVar1 + 0x38),iVar2,iVar4);
  return pLVar3;
}

// --------------------------------------------------

// Function: FUN_004c59a4
// Address: 004c59a4
// XREFS: None
int __thiscall FUN_004c59a4(int param_1,int param_2,char param_3,int param_4)
{
  RGE_Visible_Map *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (param_2 != 0) {
    if (param_4 == -1) {
      param_4 = __ftol();
    }
    if (0 < param_4) {
      this = *(RGE_Visible_Map **)(param_2 + 0x38);
      uVar5 = (uint)(*(short *)(param_2 + 0x4a) == *(short *)(*(int *)(param_2 + 0x3c) + 0x7c));
      if (param_3 == '\0') {
        iVar3 = *(int *)(param_1 + 4);
        iVar6 = 0;
        iVar1 = __ftol();
        iVar2 = __ftol();
        iVar3 = RGE_Visible_Map::explore_terrain(this,iVar2,iVar1,param_4,iVar6,uVar5,iVar3);
        return iVar3;
      }
      if (((float)(double)DAT_00574718 < *(float *)(*(int *)(param_1 + 8) + 0x30)) &&
         ((float)(double)DAT_00574718 < *(float *)(*(int *)(param_1 + 8) + 0x34))) {
        iVar3 = *(int *)(param_1 + 4);
        iVar1 = __ftol();
        iVar2 = __ftol();
        iVar6 = __ftol();
        iVar4 = __ftol();
        iVar3 = RGE_Visible_Map::explore_terrain_sq(this,iVar4,iVar6,iVar2,iVar1,uVar5,iVar3);
        return iVar3;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c5a9a
// Address: 004c5a9a
// XREFS: None
void __thiscall FUN_004c5a9a(int param_1,int param_2,char param_3,int param_4)
{
  RGE_Visible_Map *this;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 != 0) {
    if (param_4 == -1) {
      param_4 = __ftol();
    }
    if (0 < param_4) {
      this = *(RGE_Visible_Map **)(param_2 + 0x38);
      uVar4 = (uint)(*(short *)(param_2 + 0x4a) == *(short *)(*(int *)(param_2 + 0x3c) + 0x7c));
      if (param_3 == '\0') {
        iVar6 = *(int *)(param_1 + 4);
        iVar5 = 0;
        iVar1 = __ftol();
        iVar2 = __ftol();
        RGE_Visible_Map::unexplore_terrain(this,iVar2,iVar1,param_4,iVar5,uVar4,iVar6);
        return;
      }
      if (((float)(double)DAT_00574718 < *(float *)(*(int *)(param_1 + 8) + 0x30)) &&
         ((float)(double)DAT_00574718 < *(float *)(*(int *)(param_1 + 8) + 0x34))) {
        iVar6 = *(int *)(param_1 + 4);
        iVar1 = __ftol();
        iVar2 = __ftol();
        iVar5 = __ftol();
        iVar3 = __ftol();
        RGE_Visible_Map::unexplore_terrain_sq(this,iVar3,iVar5,iVar2,iVar1,uVar4,iVar6);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c5b82
// Address: 004c5b82
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004c5b82(RGE_Static_Object *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)
{
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(param_1->_padding_ + 0x74))(param_2,param_3,param_4,param_5,param_6)
  ;
  fVar1 = (float10)param_1->hp - fVar1;
  param_1->hp = (float)fVar1;
  if (fVar1 < (float10)_DAT_00574758) {
    param_1->hp = 0.0;
    RGE_Static_Object::set_sleep_flag(param_1,'\0');
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c5bda
// Address: 004c5bda
// XREFS: None
float10 FUN_004c5bda(int param_1,int param_2,float param_3)
{
  short sVar1;
  short *psVar2;
  float10 fVar3;
  
  fVar3 = (float10)DAT_00574718._8_4_;
  if (0 < param_1) {
    psVar2 = (short *)(param_2 + 2);
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 2;
      param_1 = param_1 + -1;
      fVar3 = (float10)(int)sVar1 * (float10)param_3 + fVar3;
    } while (param_1 != 0);
  }
  return fVar3;
}

// --------------------------------------------------

// Function: FUN_004c5c0f
// Address: 004c5c0f
// XREFS: None
void __thiscall FUN_004c5c0f(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = (int)*(short *)(*(int *)(param_1 + 0x10) + 0x60);
  for (param_2 = param_2 + (uint)*(byte *)(param_1 + 0x35); param_2 < 0; param_2 = param_2 + iVar1)
{
  }
  for (; iVar1 <= param_2; param_2 = param_2 - iVar1) {
  }
  *(char *)(param_1 + 0x35) = (char)param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004c5c3c
// Address: 004c5c3c
// XREFS: None
void __thiscall FUN_004c5c3c(int param_1,undefined2 param_2,undefined4 param_3)
{
  *(undefined2 *)(param_1 + 0x4c) = param_2;
  *(undefined4 *)(param_1 + 0x44) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_004c5c53
// Address: 004c5c53
// XREFS: None
void __thiscall FUN_004c5c53(int param_1,float param_2,char param_3,char param_4)
{
  float fVar1;
  
  if (param_3 == '\0') {
    *(float *)(param_1 + 0x44) = param_2;
  }
  else {
    *(float *)(param_1 + 0x44) = param_2 + *(float *)(param_1 + 0x44);
  }
  if ((param_4 != '\0') &&
     (fVar1 = (float)(int)*(short *)(*(int *)(param_1 + 8) + 0x7c),
     fVar1 < *(float *)(param_1 + 0x44))) {
    *(float *)(param_1 + 0x44) = fVar1;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c5ca7
// Address: 004c5ca7
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004c5ca7(int param_1,float param_2)
{
  float fVar1;
  bool bVar2;
  float fVar3;
  uint3 uVar4;
  
  bVar2 = param_2 < DAT_00574718._8_4_;
  param_2 = param_2 + *(float *)(param_1 + 0x30);
  *(float *)(param_1 + 0x30) = param_2;
  if ((bVar2) && (param_2 < _DAT_0057472c)) {
    *(undefined4 *)(param_1 + 0x30) = 0x3f800000;
  }
  fVar3 = (float)(int)*(short *)(*(int *)(param_1 + 8) + 0x26);
  fVar1 = *(float *)(param_1 + 0x30);
  uVar4 = (uint3)(CONCAT22((short)((uint)*(int *)(param_1 + 8) >> 0x10),
                           (ushort)(fVar3 < fVar1) << 8 | (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
                           (ushort)(fVar3 == fVar1) << 0xe) >> 8);
  if (fVar3 >= fVar1 && (fVar3 == fVar1) == 0) {
    return (uint)uVar4 << 8;
  }
  *(float *)(param_1 + 0x30) = fVar3;
  return CONCAT31(uVar4,1);
}

// --------------------------------------------------

// Function: FUN_004c5d0d
// Address: 004c5d0d
// XREFS: None
void FUN_004c5d0d(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004c5d13
// Address: 004c5d13
// XREFS: None
void __fastcall FUN_004c5d13(RGE_Static_Object *param_1)
{
  if (param_1->worker_num < 0xfa) {
    param_1->worker_num = param_1->worker_num + 1;
  }
  RGE_Static_Object::set_sleep_flag(param_1,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_004c5d36
// Address: 004c5d36
// XREFS: None
void __fastcall FUN_004c5d36(RGE_Static_Object *param_1)
{
  if (param_1->worker_num != '\0') {
    param_1->worker_num = param_1->worker_num + 0xff;
  }
  if ((param_1->worker_num == '\0') &&
     (((param_1->object_state == '\x02' && (DAT_00574718._8_4_ <= param_1->hp)) ||
      (param_1->object_state == '\x06')))) {
    RGE_Static_Object::set_sleep_flag(param_1,'\x01');
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c5d7a
// Address: 004c5d7a
// XREFS: None
undefined4 __thiscall FUN_004c5d7a(int param_1,float param_2,float param_3)
{
  float fVar1;
  int iVar2;
  undefined4 uStack_4;
  
  iVar2 = (int)param_2;
  fVar1 = *(float *)((int)param_2 + 0x38) - *(float *)(param_1 + 0x38);
  param_2 = *(float *)((int)param_2 + 0x3c) - *(float *)(param_1 + 0x3c);
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = -fVar1;
  }
  if (param_2 < DAT_00574718._8_4_) {
    param_2 = -param_2;
  }
  uStack_4 = (fVar1 - *(float *)(*(int *)(param_1 + 8) + 0x30)) -
             *(float *)(*(int *)(iVar2 + 8) + 0x30);
  fVar1 = (param_2 - *(float *)(*(int *)(param_1 + 8) + 0x34)) -
          *(float *)(*(int *)(iVar2 + 8) + 0x34);
  if (uStack_4 < DAT_00574718._8_4_) {
    uStack_4 = 0.0;
  }
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = DAT_00574718._8_4_;
  }
  if (fVar1 * fVar1 + uStack_4 * uStack_4 < param_3 * param_3) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c5e47
// Address: 004c5e47
// XREFS: None
float10 __thiscall FUN_004c5e47(int param_1,float param_2)
{
  float fVar1;
  int iVar2;
  float10 fVar3;
  undefined4 uStack_4;
  
  iVar2 = (int)param_2;
  fVar1 = *(float *)((int)param_2 + 0x38) - *(float *)(param_1 + 0x38);
  param_2 = *(float *)((int)param_2 + 0x3c) - *(float *)(param_1 + 0x3c);
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = -fVar1;
  }
  if (param_2 < DAT_00574718._8_4_) {
    param_2 = -param_2;
  }
  uStack_4 = (fVar1 - *(float *)(*(int *)(param_1 + 8) + 0x30)) -
             *(float *)(*(int *)(iVar2 + 8) + 0x30);
  fVar3 = ((float10)param_2 - (float10)*(float *)(*(int *)(param_1 + 8) + 0x34)) -
          (float10)*(float *)(*(int *)(iVar2 + 8) + 0x34);
  if (uStack_4 < DAT_00574718._8_4_) {
    uStack_4 = 0.0;
  }
  if (fVar3 < (float10)DAT_00574718._8_4_) {
    fVar3 = (float10)DAT_00574718._8_4_;
  }
  return SQRT(fVar3 * fVar3 + (float10)uStack_4 * (float10)uStack_4);
}

// --------------------------------------------------

// Function: FUN_004c5ef7
// Address: 004c5ef7
// XREFS: None
float10 __thiscall FUN_004c5ef7(int param_1,float param_2,float param_3)
{
  float fVar1;
  float10 fVar2;
  
  fVar1 = *(float *)(param_1 + 0x38) - param_2;
  param_2 = *(float *)(param_1 + 0x3c) - param_3;
  if (fVar1 < DAT_00574718._8_4_) {
    fVar1 = -fVar1;
  }
  if (param_2 < DAT_00574718._8_4_) {
    param_2 = -param_2;
  }
  param_3 = fVar1 - *(float *)(*(int *)(param_1 + 8) + 0x30);
  fVar2 = (float10)param_2 - (float10)*(float *)(*(int *)(param_1 + 8) + 0x34);
  if (param_3 < DAT_00574718._8_4_) {
    param_3 = 0.0;
  }
  if (fVar2 < (float10)DAT_00574718._8_4_) {
    fVar2 = (float10)DAT_00574718._8_4_;
  }
  return SQRT(fVar2 * fVar2 + (float10)param_3 * (float10)param_3);
}

// --------------------------------------------------

// Function: FUN_004c5f98
// Address: 004c5f98
// XREFS: None
undefined4 __thiscall
FUN_004c5f98(int param_1,short param_2,short param_3,short param_4,short param_5)
{
  uchar uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short unaff_retaddr;
  
  if ((*(int *)(param_1 + 0x10) != 0) && (*(int **)(param_1 + 0x18) != (int *)0x0)) {
    sVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 4))(*(int *)(param_1 + 0x10));
    param_2 = (param_4 - *(short *)(param_1 + 0x2a)) - param_2;
    sVar4 = (param_3 - *(short *)(param_1 + 0x28)) - unaff_retaddr;
    uVar1 = RGE_Sprite::hit_test
                      (*(RGE_Sprite **)(param_1 + 0x10),sVar4,param_2,
                       (uint)*(byte *)(param_1 + 0x35),(int)sVar2);
    if (uVar1 != '\0') {
      return 1;
    }
    if ((param_5 != 0) && (sVar5 = -param_5, sVar3 = sVar5, sVar5 < param_5)) {
      do {
        if (sVar5 < param_5) {
          sVar7 = param_2 + sVar5;
          sVar6 = sVar5;
          do {
            uVar1 = RGE_Sprite::hit_test
                              (*(RGE_Sprite **)(param_1 + 0x10),sVar4 + sVar3,sVar7,
                               (uint)*(byte *)(param_1 + 0x35),(int)sVar2);
            if (uVar1 != '\0') {
              return 1;
            }
            sVar6 = sVar6 + 1;
            sVar7 = sVar7 + 1;
          } while (sVar6 < param_5);
        }
        sVar3 = sVar3 + 1;
      } while (sVar3 < param_5);
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c6092
// Address: 004c6092
// XREFS: None
uint __thiscall
FUN_004c6092(RGE_Static_Object *param_1,short param_2,short param_3,short param_4,short param_5)
{
  short sVar1;
  RGE_Sprite *pRVar2;
  undefined3 uVar3;
  short unaff_BX;
  short sVar4;
  short unaff_BP;
  short sVar5;
  int unaff_retaddr;
  short asStack_10 [2];
  int aiStack_c [2];
  short sStack_4;
  
  pRVar2 = param_1->sprite;
  if ((pRVar2 != (RGE_Sprite *)0x0) && (param_1->sprite_list != (RGE_Active_Sprite_List *)0x0)) {
    (**(code **)(param_1->sprite_list->_padding_ + 0x28))(pRVar2,param_1->facet);
    pRVar2 = (RGE_Sprite *)
             RGE_Static_Object::get_frame
                       (param_1,(short *)&stack0xffffffe8,(short *)&stack0xffffffec,asStack_10,
                        (short *)aiStack_c);
    if (pRVar2 == (RGE_Sprite *)0x0) goto LAB_004c6226;
    sVar5 = unaff_BP + sStack_4 + param_1->screen_x_offset;
    asStack_10[0] = asStack_10[0] + param_1->screen_x_offset + sStack_4;
    pRVar2 = (RGE_Sprite *)
             (aiStack_c[0] +
             unaff_retaddr + CONCAT22((short)((uint)param_1 >> 0x10),param_1->screen_y_offset));
    sVar4 = unaff_BX + (short)unaff_retaddr + param_1->screen_y_offset;
    uVar3 = (undefined3)((uint)pRVar2 >> 8);
    if ((((param_2 <= sVar5) && (sVar5 <= param_4)) && (param_3 <= sVar4)) && (sVar4 <= param_5)) {
      return CONCAT31(uVar3,1);
    }
    sVar1 = (short)pRVar2;
    if (((param_2 <= asStack_10[0]) && (asStack_10[0] <= param_4)) &&
       ((param_3 <= sVar1 && (sVar1 <= param_5)))) {
      return CONCAT31(uVar3,1);
    }
    if (((sVar5 <= param_2) && (param_2 <= asStack_10[0])) &&
       ((sVar4 <= param_3 && (param_3 <= sVar1)))) {
      return CONCAT31(uVar3,1);
    }
    if ((((sVar5 <= param_4) && (param_4 <= asStack_10[0])) && (sVar4 <= param_5)) &&
       (param_5 <= sVar1)) {
      return CONCAT31(uVar3,1);
    }
    if ((param_2 < sVar5) && (asStack_10[0] < param_4)) {
      if ((sVar4 < param_3) && (param_3 < sVar1)) goto LAB_004c621a;
      if ((sVar4 < param_5) && (param_5 < sVar1)) {
        return CONCAT31(uVar3,1);
      }
    }
    if (((param_3 < sVar4) && (sVar1 < param_5)) &&
       (((sVar5 < param_2 && (param_2 < asStack_10[0])) ||
        ((pRVar2 = (RGE_Sprite *)CONCAT22((short)((uint)pRVar2 >> 0x10),param_4), sVar5 < param_4 &&
         (param_4 < asStack_10[0])))))) {
LAB_004c621a:
      return CONCAT31((int3)((uint)pRVar2 >> 8),1);
    }
  }
LAB_004c6226:
  return (uint)pRVar2 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004c6232
// Address: 004c6232
// XREFS: None
void __thiscall FUN_004c6232(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x38) = param_2;
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x40) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_004c6258
// Address: 004c6258
// XREFS: None
void FUN_004c6258(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004c6263
// Address: 004c6263
// XREFS: None
char __thiscall FUN_004c6263(RGE_Static_Object *param_1,int param_2)
{
  float fVar1;
  float fVar2;
  RGE_Object_Node *pRVar3;
  RGE_Static_Object *this;
  RGE_Object_Node *pRVar4;
  uchar uVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  char cStack_b1;
  float fStack_ac;
  float fStack_a8;
  RGE_Object_Node *pRStack_a4;
  float afStack_a0 [10];
  float afStack_78 [9];
  float afStack_54 [11];
  float afStack_28 [10];
  
  afStack_54[1] = param_1->world_x;
  afStack_a0[0] = param_1->world_y;
  cStack_b1 = '\0';
  afStack_78[0] = param_1->master_obj->radius_x;
  afStack_78[0] = afStack_78[0] + afStack_78[0];
  afStack_28[0] = param_1->master_obj->radius_y;
  afStack_28[0] = afStack_28[0] + afStack_28[0];
  iVar8 = 1;
  pRStack_a4 = param_1->objects->list;
  do {
    do {
      pRVar4 = pRStack_a4;
      if (pRVar4 == (RGE_Object_Node *)0x0) {
        return cStack_b1;
      }
      pRStack_a4 = pRVar4->next;
    } while (iVar8 < 1);
    pfVar6 = afStack_28 + iVar8;
    iVar7 = iVar8;
    pfVar9 = afStack_78 + iVar8;
    do {
      uVar5 = RGE_Static_Object::find_drop_location
                        (param_1,param_2,&fStack_ac,&fStack_a8,pRVar4->node->master_obj,pRVar4->node
                         ,afStack_54[1],afStack_a0[0],afStack_78[0],afStack_28[0]);
      if (uVar5 != '\0') {
        this = pRVar4->node;
        RGE_Static_Object::set_location(this,param_1->world_x,param_1->world_y,param_1->world_z);
        iVar8 = this->_padding_;
        (**(code **)(iVar8 + 0xd4))();
        (**(code **)(iVar8 + 0x34))(fStack_ac,fStack_a8,param_1->world_z);
        cStack_b1 = cStack_b1 + '\x01';
        iVar8 = iVar7;
        if (iVar7 < 9) {
          iVar8 = iVar7 + 1;
          fVar1 = this->master_obj->radius_y;
          fVar2 = this->master_obj->radius_x;
          afStack_54[iVar7 + 1] = fStack_ac;
          afStack_a0[iVar7] = fStack_a8;
          afStack_78[iVar7] = fVar2 + fVar2;
          afStack_28[iVar7] = fVar1 + fVar1;
        }
        break;
      }
      iVar8 = iVar7 + -1;
      if (iVar8 < 1) break;
      pRVar3 = (RGE_Object_Node *)afStack_a0[iVar8];
      afStack_54[iVar8] = afStack_54[iVar7];
      pfVar6[-2] = pfVar6[-1];
      (&pRStack_a4)[iVar8] = pRVar3;
      pfVar9[-2] = pfVar9[-1];
      pfVar6 = pfVar6 + -1;
      iVar7 = iVar8;
      pfVar9 = pfVar9 + -1;
    } while (0 < iVar8);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004c63f3
// Address: 004c63f3
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_stat_obj_c: "C:\msdev\work\age1_x1\stat_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall
FUN_004c63f3(RGE_Static_Object *param_1,uint param_2,float *param_3,float *param_4,int *param_5,
            int *param_6,float param_7,float param_8,float param_9,float param_10)
{
  RGE_Map *pRVar1;
  float *pfVar2;
  int *piVar3;
  byte bVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  float fStack_8;
  uint uStack_4;
  
  piVar3 = param_5;
  pfVar2 = param_3;
  param_9 = param_9 + (float)param_5[0xc];
  param_10 = param_10 + (float)param_5[0xd];
  param_5 = (int *)(param_9 + param_9);
  fStack_8 = param_10 + param_10;
  uStack_4 = 1;
  do {
    sVar6 = 0;
    do {
      iVar7 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf3a);
      switch((iVar7 * 4) / 0x7fff) {
      case 0:
        *pfVar2 = param_9 + param_7;
        iVar7 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf3e);
        *param_4 = ((float)iVar7 * fStack_8 * _DAT_00574764 - param_10) + param_8;
        break;
      case 1:
        *pfVar2 = param_7 - param_9;
        iVar7 = debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf42);
        *param_4 = ((float)iVar7 * fStack_8 * _DAT_00574764 - param_10) + param_8;
        break;
      case 2:
        *param_4 = param_10 + param_8;
        param_3 = (float *)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf46);
        goto LAB_004c654e;
      case 3:
        *param_4 = param_8 - param_10;
        param_3 = (float *)debug_rand(s_C__msdev_work_age1_x1_stat_obj_c,0xf4a);
LAB_004c654e:
        *pfVar2 = ((float)(int)param_3 * (float)param_5 * _DAT_00574764 - param_9) + param_7;
      }
      if ((((DAT_00574718._8_4_ <= *pfVar2) && (DAT_00574718._8_4_ <= *param_4)) &&
          (pRVar1 = param_1->owner->world->map, *pfVar2 < (float)pRVar1->map_width)) &&
         (*param_4 < (float)pRVar1->map_height)) {
        if (param_2 != 0xffffffff) {
          iVar7 = __ftol();
          iVar8 = __ftol();
          bVar4 = RGE_Static_Object::lookupZone(param_1,iVar8,iVar7);
          if (param_2 != bVar4) goto LAB_004c6614;
        }
        cVar5 = (**(code **)(*piVar3 + 0x20))(param_1->owner,*pfVar2,*param_4,0,1,1,1,0,1,1);
        if ((cVar5 == '\0') &&
           (iVar7 = (**(code **)(*param_6 + 0x114))(*pfVar2,*param_4,0), iVar7 == 1)) {
          return 1;
        }
      }
LAB_004c6614:
      sVar6 = sVar6 + 1;
    } while (sVar6 < 0x32);
    param_9 = (float)piVar3[0xc] + (float)piVar3[0xc] + param_9;
    param_10 = (float)piVar3[0xd] + (float)piVar3[0xd] + param_10;
    param_5 = (int *)((float)piVar3[0xc] * _DAT_00574768 + (float)param_5);
    fStack_8 = (float)piVar3[0xd] * _DAT_00574768 + fStack_8;
    uStack_4 = uStack_4 + 1;
    if (1 < (short)uStack_4) {
      return uStack_4 & 0xffffff00;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004c66a2
// Address: 004c66a2
// XREFS: None
void FUN_004c66a2(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004c66c9
// Address: 004c66c9
// XREFS: None
void __fastcall FUN_004c66c9(int *param_1)
{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    iVar1 = *(int *)(*param_1 + 0x10);
    free(*param_1);
    *param_1 = iVar1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c66f2
// Address: 004c66f2
// XREFS: None
void __thiscall
FUN_004c66f2(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)calloc(1,0x14);
  puVar1[4] = *param_1;
  *puVar1 = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  *(undefined1 *)(puVar1 + 3) = param_5;
  *param_1 = (int)puVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_004c6735
// Address: 004c6735
// XREFS: None
RGE_Check_List * __thiscall FUN_004c6735(RGE_Static_Object *param_1,float param_2)
{
  float fVar1;
  RGE_Master_Static_Object *pRVar2;
  float fVar3;
  RGE_Map *pRVar4;
  undefined4 *puVar5;
  RGE_Static_Object *pRVar6;
  float fVar7;
  float fVar8;
  uchar uVar9;
  short sVar10;
  short sVar11;
  RGE_Check_List *this;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *unaff_FS_OFFSET;
  RGE_Check_List *pRStack_4c;
  short sStack_48;
  short sStack_38;
  int iStack_34;
  int iStack_20;
  RGE_Check_List *pRStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fa3b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar2 = param_1->master_obj;
  fVar1 = pRVar2->radius_x;
  fVar3 = pRVar2->radius_y;
  if (((fVar1 <= DAT_00574718._8_4_) || (fVar3 <= DAT_00574718._8_4_)) ||
     (pRVar2->radius_z <= (float)(double)DAT_00574718)) {
    pRStack_4c = (RGE_Check_List *)0x0;
  }
  else {
    sStack_38 = __ftol();
    sVar10 = __ftol();
    sStack_48 = __ftol();
    sVar11 = __ftol();
    pRVar4 = param_1->owner->world->map;
    this = (RGE_Check_List *)operator_new(4);
    uStack_4 = 0;
    if (this == (RGE_Check_List *)0x0) {
      pRStack_4c = (RGE_Check_List *)0x0;
    }
    else {
      pRStack_4c = (RGE_Check_List *)RGE_Check_List::RGE_Check_List(this);
    }
    uStack_4 = 0xffffffff;
    if (sStack_38 < 0) {
      sStack_38 = 0;
    }
    if (pRVar4->map_width <= (int)sStack_48) {
      sStack_48 = (short)pRVar4->map_width + -1;
    }
    if (sVar10 < 0) {
      sVar10 = 0;
    }
    if (pRVar4->map_height <= (int)sVar11) {
      sVar11 = (short)pRVar4->map_height + -1;
    }
    if (sVar10 <= sVar11) {
      iStack_34 = sVar10 * 4;
      iStack_20 = ((int)sVar11 - (int)sVar10) + 1;
      do {
        if (sStack_38 <= sStack_48) {
          puVar13 = (undefined4 *)
                    (*(int *)(iStack_34 + (int)pRVar4->map_row_offset) + sStack_38 * 0x18 + 0x10);
          iVar12 = ((int)sStack_48 - (int)sStack_38) + 1;
          do {
            for (puVar5 = (undefined4 *)*puVar13; puVar5 != (undefined4 *)0x0;
                puVar5 = (undefined4 *)puVar5[1]) {
              pRVar6 = (RGE_Static_Object *)*puVar5;
              if (pRVar6 != param_1) {
                pRVar2 = pRVar6->master_obj;
                if (((DAT_00574718._8_4_ < pRVar2->radius_y) &&
                    (DAT_00574718._8_4_ < pRVar2->radius_x)) &&
                   ((fVar7 = pRVar6->world_z - param_1->world_z, -pRVar2->radius_z <= fVar7 &&
                    (fVar7 <= param_1->master_obj->radius_z)))) {
                  fVar7 = pRVar6->world_x - param_1->world_x;
                  uVar9 = fVar7 < DAT_00574718._8_4_;
                  fVar8 = pRVar6->world_y - param_1->world_y;
                  if ((bool)uVar9) {
                    fVar7 = -fVar7;
                  }
                  if (fVar8 < DAT_00574718._8_4_) {
                    uVar9 = uVar9 + '\x02';
                    fVar8 = -fVar8;
                  }
                  fVar7 = fVar7 - (pRVar2->radius_x + fVar1);
                  fVar8 = fVar8 - (pRVar2->radius_y + fVar3);
                  if (((fVar7 < param_2) && (fVar8 < param_2)) &&
                     ((DAT_00574718._8_4_ <= fVar8 || (DAT_00574718._8_4_ <= fVar7)))) {
                    RGE_Check_List::add_node(pRStack_4c,pRVar6,fVar7,fVar8,uVar9);
                  }
                }
              }
            }
            puVar13 = puVar13 + 6;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        iStack_34 = iStack_34 + 4;
        iStack_20 = iStack_20 + -1;
      } while (iStack_20 != 0);
    }
    if (pRStack_4c->list == (RGE_Check_Node *)0x0) {
      if (pRStack_4c != (RGE_Check_List *)0x0) {
        RGE_Check_List::~RGE_Check_List(pRStack_4c);
        operator_delete(pRStack_4c);
      }
      pRStack_1c = (RGE_Check_List *)0x0;
      pRStack_4c = pRStack_1c;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return pRStack_4c;
}

// --------------------------------------------------

// Function: FUN_004c6a9b
// Address: 004c6a9b
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004c6a9b(int param_1,float param_2,float param_3,int param_4)
{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar5 = (float10)param_3;
  iVar2 = -1;
  param_3 = 0.0;
  fVar5 = (float10)fpatan((float10)*(float *)(param_1 + 0x3c) - fVar5,
                          (float10)*(float *)(param_1 + 0x38) - (float10)param_2);
  if (fVar5 < (float10)DAT_00574718._8_4_) {
    fVar5 = fVar5 - (float10)_DAT_0057476c;
  }
  fVar3 = (float10)DAT_00574718._8_4_;
  if (param_4 == -1) {
    param_4 = (int)*(short *)(*(int *)(param_1 + 0x10) + 0x60);
  }
  iVar1 = 0;
  if (0 < param_4) {
    do {
      fVar4 = fVar5 - fVar3;
      if (fVar4 < (float10)DAT_00574718._8_4_) {
        fVar4 = -fVar4;
      }
      if ((iVar2 == -1) || (fVar4 < (float10)param_3)) {
        param_3 = (float)fVar4;
        iVar2 = iVar1;
      }
      fVar3 = fVar3 + (float10)(_DAT_00574770 / (float)param_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_4);
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_004c6b42
// Address: 004c6b42
// XREFS: None
int __fastcall FUN_004c6b42(int param_1)
{
  if (*(int *)(param_1 + 0x10) != 0) {
    return (int)*(short *)(*(int *)(param_1 + 0x10) + 0x60);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c6b5f
// Address: 004c6b5f
// XREFS: None
undefined1 __fastcall FUN_004c6b5f(int param_1)
{
  return *(undefined1 *)(param_1 + 0x86);
}

// --------------------------------------------------

// Function: FUN_004c6b67
// Address: 004c6b67
// XREFS: None
void __thiscall FUN_004c6b67(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x86) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004c6b7d
// Address: 004c6b7d
// XREFS: None
undefined4 __thiscall FUN_004c6b7d(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_c;
  
  if (*(float *)(*(int *)(param_1 + 8) + 0x38) <= DAT_00574718._8_4_) {
    return 0;
  }
  if (*(char *)(param_1 + 0x84) != '\x01') {
    iVar2 = __ftol();
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iStack_c = __ftol();
    if (iStack_c < 0) {
      iStack_c = 0;
    }
    iVar3 = __ftol();
    iVar4 = __ftol();
    for (; iVar1 = iStack_c, iVar2 < iVar3; iVar2 = iVar2 + 1) {
      for (; iVar1 < iVar4; iVar1 = iVar1 + 1) {
        if (param_2 != 1) {
          PathingSystem::incrementObstruction(&pathSystem,iVar2,iVar1);
        }
        if (param_2 != 0) {
          PathingSystem::incrementObstruction(&aiPathSystem,iVar2,iVar1);
        }
      }
    }
    *(undefined1 *)(param_1 + 0x85) = *(undefined1 *)(param_1 + 0x84);
    *(undefined1 *)(param_1 + 0x84) = 1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c6c8a
// Address: 004c6c8a
// XREFS: None
undefined4 __thiscall FUN_004c6c8a(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_c;
  
  if (*(float *)(*(int *)(param_1 + 8) + 0x38) <= DAT_00574718._8_4_) {
    return 0;
  }
  if (*(char *)(param_1 + 0x84) != '\0') {
    iVar2 = __ftol();
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iStack_c = __ftol();
    if (iStack_c < 0) {
      iStack_c = 0;
    }
    iVar3 = __ftol();
    iVar4 = __ftol();
    for (; iVar1 = iStack_c, iVar2 < iVar3; iVar2 = iVar2 + 1) {
      for (; iVar1 < iVar4; iVar1 = iVar1 + 1) {
        if (param_2 != 1) {
          PathingSystem::decrementObstruction(&pathSystem,iVar2,iVar1);
        }
        if (param_2 != 0) {
          PathingSystem::decrementObstruction(&aiPathSystem,iVar2,iVar1);
        }
      }
    }
    *(undefined1 *)(param_1 + 0x85) = *(undefined1 *)(param_1 + 0x84);
    *(undefined1 *)(param_1 + 0x84) = 0;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c6d9b
// Address: 004c6d9b
// XREFS: None
void __thiscall FUN_004c6d9b(int param_1,InfluenceMap *param_2,int param_3,int param_4,int param_5)
{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int iStack_10;
  int iStack_8;
  
  fVar1 = *(float *)(param_1 + 0x38) - *(float *)(*(int *)(param_1 + 8) + 0x30);
  if (param_5 == 0) {
    floor((double)fVar1);
    iStack_8 = __ftol();
    ceil((double)(*(float *)(*(int *)(param_1 + 8) + 0x30) + *(float *)(param_1 + 0x38)));
    iStack_10 = __ftol();
    floor((double)(*(float *)(param_1 + 0x3c) - *(float *)(*(int *)(param_1 + 8) + 0x34)));
    iVar3 = __ftol();
    fVar1 = *(float *)(*(int *)(param_1 + 8) + 0x34);
  }
  else {
    floor((double)(fVar1 - *(float *)(*(int *)(param_1 + 8) + 0x28)));
    iStack_8 = __ftol();
    ceil((double)(*(float *)(*(int *)(param_1 + 8) + 0x30) +
                  *(float *)(*(int *)(param_1 + 8) + 0x28) + *(float *)(param_1 + 0x38)));
    iStack_10 = __ftol();
    floor((double)((*(float *)(param_1 + 0x3c) - *(float *)(*(int *)(param_1 + 8) + 0x34)) -
                  *(float *)(*(int *)(param_1 + 8) + 0x28)));
    iVar3 = __ftol();
    fVar1 = *(float *)(*(int *)(param_1 + 8) + 0x34) + *(float *)(*(int *)(param_1 + 8) + 0x28);
  }
  ceil((double)(fVar1 + *(float *)(param_1 + 0x3c)));
  iVar4 = __ftol();
  do {
    iVar2 = iStack_8;
    if (iVar4 <= iVar3) {
      return;
    }
    for (; iVar2 < iStack_10; iVar2 = iVar2 + 1) {
      if (param_4 == 0) {
        uVar6 = CONCAT44(0xff,iVar3);
        if (param_3 != 1) goto LAB_004c6ff6;
        InfluenceMap::incrementValue(param_2,iVar2,iVar3,0xff);
      }
      else {
        uVar5 = __ftol();
        uVar6 = CONCAT44(uVar5,iVar3);
        if (param_3 == 1) {
          InfluenceMap::incrementValue(param_2,iVar2,iVar3,(uchar)uVar5);
        }
        else {
LAB_004c6ff6:
          InfluenceMap::decrementValue(param_2,iVar2,(int)uVar6,(uchar)((ulonglong)uVar6 >> 0x20));
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004c7027
// Address: 004c7027
// XREFS: None
RGE_Check_List * __thiscall FUN_004c7027(RGE_Static_Object *param_1,float param_2)
{
  RGE_Master_Static_Object *pRVar1;
  RGE_Map *pRVar2;
  RGE_Object_Node *pRVar3;
  RGE_Static_Object *pRVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  RGE_Check_List *this;
  RGE_Check_List *this_00;
  undefined4 *unaff_FS_OFFSET;
  int iStack_2c;
  RGE_Object_Node **ppRStack_28;
  int iStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  RGE_Check_List *pRStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pRStack_4 = (RGE_Check_List *)0xffffffff;
  pcStack_8 = FUN_0055fa5b;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar1 = param_1->master_obj;
  if (((pRVar1->radius_x <= DAT_00574718._8_4_) || (pRVar1->radius_y <= DAT_00574718._8_4_)) ||
     (pRVar1->radius_z <= (float)(double)DAT_00574718)) {
    this_00 = (RGE_Check_List *)0x0;
  }
  else {
    pRVar2 = param_1->owner->world->map;
    iVar8 = __ftol();
    iStack_2c = iVar8 + -3;
    iVar8 = iVar8 + 3;
    iVar9 = __ftol();
    iStack_20 = iVar9 + 3;
    iVar9 = iVar9 + -3;
    if (iStack_2c < 0) {
      iStack_2c = 0;
    }
    if (pRVar2->map_width <= iVar8) {
      iVar8 = pRVar2->map_width + -1;
    }
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    if (pRVar2->map_height <= iStack_20) {
      iStack_20 = pRVar2->map_height + -1;
    }
    this_00 = (RGE_Check_List *)0x0;
    for (; iVar9 <= iStack_20; iVar9 = iVar9 + 1) {
      if (iStack_2c <= iVar8) {
        ppRStack_28 = &pRVar2->map_row_offset[iVar9][iStack_2c].objects.list;
        iVar10 = (iVar8 - iStack_2c) + 1;
        do {
          for (pRVar3 = *ppRStack_28; pRVar3 != (RGE_Object_Node *)0x0; pRVar3 = pRVar3->next) {
            pRVar4 = pRVar3->node;
            if ((pRVar4 != param_1) &&
               (pRVar1 = pRVar4->master_obj, (float)(double)DAT_00574718 < pRVar1->radius_z)) {
              fVar5 = pRVar1->radius_x;
              fVar6 = pRVar1->radius_y;
              if ((((DAT_00574718._8_4_ < fVar5) && (DAT_00574718._8_4_ < fVar6)) &&
                  ((fVar7 = pRVar4->world_z - param_1->world_z, fVar7 <= DAT_00574718._8_4_ ||
                   (fVar7 <= param_1->master_obj->radius_z)))) &&
                 ((DAT_00574718._8_4_ <= fVar7 || (-pRVar1->radius_z <= fVar7)))) {
                pRVar1 = param_1->master_obj;
                if (pRVar4->world_x <= param_1->world_x) {
                  if (-param_2 <= (fVar5 + pRVar4->world_x) - (param_1->world_x - pRVar1->radius_x))
                  goto LAB_004c724b;
                }
                else if ((pRVar4->world_x - fVar5) - (pRVar1->radius_x + param_1->world_x) <=
                         param_2) {
LAB_004c724b:
                  if (pRVar4->world_y <= param_1->world_y) {
                    if (-param_2 <=
                        (fVar6 + pRVar4->world_y) - (param_1->world_y - pRVar1->radius_y))
                    goto LAB_004c7298;
                  }
                  else if ((pRVar4->world_y - fVar6) - (pRVar1->radius_y + param_1->world_y) <=
                           param_2) {
LAB_004c7298:
                    if (this_00 == (RGE_Check_List *)0x0) {
                      this = (RGE_Check_List *)operator_new(4);
                      if (this == (RGE_Check_List *)0x0) {
                        this_00 = (RGE_Check_List *)0x0;
                      }
                      else {
                        pRStack_4 = this_00;
                        this_00 = (RGE_Check_List *)RGE_Check_List::RGE_Check_List(this);
                      }
                      pRStack_4 = (RGE_Check_List *)0xffffffff;
                    }
                    RGE_Check_List::add_node(this_00,pRVar4,0.0,0.0,'\0');
                  }
                }
              }
            }
          }
          ppRStack_28 = ppRStack_28 + 6;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return this_00;
}

// --------------------------------------------------

// Function: FUN_004c7338
// Address: 004c7338
// XREFS: None
// [HELPER] s_UNIT___5d_: "UNIT #%5d\n"
// [HELPER] s_UNIT___5d___s_: "UNIT #%5d: %s\n"
// [HELPER] s_WORLD_TIME___ld_: "WORLD TIME: %ld\n"
// [HELPER] s_c__aoeunit_txt: "c:\aoeunit.txt"
// [HELPER] s_w: "w"
void FUN_004c7338(int param_1,undefined4 param_2)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char acStack_400 [1024];
  
  if ((logDebugID == -1) || (logDebugID == *(int *)(param_1 + 4))) {
    if (debugOut == (_iobuf *)0x0) {
      debugOut = (_iobuf *)fopen(s_c__aoeunit_txt,s_w);
      if (debugOut == (_iobuf *)0x0) {
        return;
      }
      fprintf(debugOut,s_WORLD_TIME___ld_,
              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 4));
    }
    vsprintf(acStack_400,param_2,&stack0x0000000c);
    iVar2 = -1;
    pcVar3 = acStack_400;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      fprintf(debugOut,s_UNIT___5d___s_,*(undefined4 *)(param_1 + 4),acStack_400);
      return;
    }
    fprintf(debugOut,s_UNIT___5d_,*(undefined4 *)(param_1 + 4));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c7415
// Address: 004c7415
// XREFS: None
undefined4 __fastcall FUN_004c7415(int param_1)
{
  return *(undefined4 *)(param_1 + 0x74);
}

// --------------------------------------------------

// Function: FUN_004c7424
// Address: 004c7424
// XREFS: None
uchar __thiscall FUN_004c7424(int param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  RGE_Zone_Map *this;
  
  if ((-1 < param_2) && (-1 < param_3)) {
    if (*(int *)(param_1 + 0x7c) == -1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
      this = RGE_Zone_Map_List::get_zone_map
                       (*(RGE_Zone_Map_List **)(*(int *)(iVar1 + 0x28) + 0x8dc4),
                        *(float **)
                         (*(int *)(iVar1 + 0x54) + *(short *)(*(int *)(param_1 + 8) + 0x66) * 4),
                        (int)*(short *)(iVar1 + 0x52),(int *)(param_1 + 0x7c));
    }
    else {
      this = RGE_Zone_Map_List::get_zone_map
                       (*(RGE_Zone_Map_List **)
                         (*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28) + 0x8dc4),
                        *(int *)(param_1 + 0x7c));
    }
    if (this != (RGE_Zone_Map *)0x0) {
      uVar2 = RGE_Zone_Map::get_zone_info(this,param_2,param_3);
      return uVar2;
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004c74a5
// Address: 004c74a5
// XREFS: None
uchar __thiscall FUN_004c74a5(int param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  RGE_Zone_Map *this;
  
  if ((-1 < param_2) && (-1 < param_3)) {
    if (*(int *)(param_1 + 0x7c) == -1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
      this = RGE_Zone_Map_List::get_zone_map
                       (*(RGE_Zone_Map_List **)(*(int *)(iVar1 + 0x28) + 0x8dc4),
                        *(float **)
                         (*(int *)(iVar1 + 0x54) + *(short *)(*(int *)(param_1 + 8) + 0x66) * 4),
                        (int)*(short *)(iVar1 + 0x52),(int *)(param_1 + 0x7c));
    }
    else {
      this = RGE_Zone_Map_List::get_zone_map
                       (*(RGE_Zone_Map_List **)
                         (*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28) + 0x8dc4),
                        *(int *)(param_1 + 0x7c));
    }
    if (this != (RGE_Zone_Map *)0x0) {
      uVar2 = RGE_Zone_Map::get_zone_info(this,param_2,param_3);
      return uVar2;
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004c7525
// Address: 004c7525
// XREFS: None
uchar __fastcall FUN_004c7525(int param_1)
{
  int iVar1;
  uchar uVar2;
  RGE_Zone_Map *this;
  long lVar3;
  long lVar4;
  
  if (*(int *)(param_1 + 0x7c) == -1) {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)(*(int *)(iVar1 + 0x28) + 0x8dc4),
                      *(float **)
                       (*(int *)(iVar1 + 0x54) + *(short *)(*(int *)(param_1 + 8) + 0x66) * 4),
                      (int)*(short *)(iVar1 + 0x52),(int *)(param_1 + 0x7c));
  }
  else {
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)
                       (*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28) + 0x8dc4),
                      *(int *)(param_1 + 0x7c));
  }
  if (this != (RGE_Zone_Map *)0x0) {
    lVar3 = __ftol();
    lVar4 = __ftol();
    uVar2 = RGE_Zone_Map::get_zone_info(this,lVar4,lVar3);
    return uVar2;
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_004c75a5
// Address: 004c75a5
// XREFS: None
int __thiscall FUN_004c75a5(int param_1,uchar param_2,float param_3,XYPoint *param_4)
{
  RGE_Zone_Map *this;
  int iVar1;
  
  if (*(int *)(param_1 + 0x7c) == -1) {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)(*(int *)(iVar1 + 0x28) + 0x8dc4),
                      *(float **)
                       (*(int *)(iVar1 + 0x54) + *(short *)(*(int *)(param_1 + 8) + 0x66) * 4),
                      (int)*(short *)(iVar1 + 0x52),(int *)(param_1 + 0x7c));
  }
  else {
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)
                       (*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28) + 0x8dc4),
                      *(int *)(param_1 + 0x7c));
  }
  if (this != (RGE_Zone_Map *)0x0) {
    iVar1 = RGE_Zone_Map::withinRange(this,param_2,*param_4,param_3);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c7622
// Address: 004c7622
// XREFS: None
int __thiscall FUN_004c7622(int param_1,uchar param_2,float param_3)
{
  XYPoint XVar1;
  int iVar2;
  int iVar3;
  RGE_Zone_Map *this;
  int iVar4;
  
  iVar2 = __ftol();
  iVar3 = __ftol();
  iVar4 = *(int *)(param_1 + 0x7c);
  if (iVar4 == -1) {
    iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)(*(int *)(iVar4 + 0x28) + 0x8dc4),
                      *(float **)
                       (*(int *)(iVar4 + 0x54) + *(short *)(*(int *)(param_1 + 8) + 0x66) * 4),
                      (int)*(short *)(iVar4 + 0x52),(int *)(param_1 + 0x7c));
  }
  else {
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)
                       (*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28) + 0x8dc4),iVar4);
  }
  if (this != (RGE_Zone_Map *)0x0) {
    XVar1.y = iVar3;
    XVar1.x = iVar2;
    iVar4 = RGE_Zone_Map::withinRange(this,param_2,XVar1,param_3);
    return iVar4;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c76b7
// Address: 004c76b7
// XREFS: None
int __thiscall
FUN_004c76b7(int param_1,int param_2,int param_3,XYPoint *param_4,int param_5,int param_6,
            int param_7)
{
  XYPoint XVar1;
  RGE_Zone_Map *this;
  int iVar2;
  
  if (*(int *)(param_1 + 0x7c) == -1) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)(*(int *)(iVar2 + 0x28) + 0x8dc4),
                      *(float **)
                       (*(int *)(iVar2 + 0x54) + *(short *)(*(int *)(param_1 + 8) + 0x66) * 4),
                      (int)*(short *)(iVar2 + 0x52),(int *)(param_1 + 0x7c));
  }
  else {
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)
                       (*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28) + 0x8dc4),
                      *(int *)(param_1 + 0x7c));
  }
  if (this != (RGE_Zone_Map *)0x0) {
    XVar1.y = param_3;
    XVar1.x = param_2;
    iVar2 = RGE_Zone_Map::findClosestPointInTerrainType(this,XVar1,param_4,param_5,param_6,param_7);
    return iVar2;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c773b
// Address: 004c773b
// XREFS: None
bool __fastcall FUN_004c773b(int param_1)
{
  return *(int *)(param_1 + 4) == *(int *)(param_1 + 0x78);
}

// --------------------------------------------------

// Function: FUN_004c7752
// Address: 004c7752
// XREFS: None
bool __fastcall FUN_004c7752(int param_1)
{
  return 0 < *(int *)(param_1 + 0x68);
}

// --------------------------------------------------

// Function: FUN_004c776b
// Address: 004c776b
// XREFS: None
undefined4 __thiscall FUN_004c776b(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x68)) {
    while (iVar1 < *(int *)(param_1 + 0x70)) {
      if (*(int *)(*(int *)(param_1 + 100) + iVar1 * 4) == param_2) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      if (*(int *)(param_1 + 0x68) <= iVar1) {
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c77af
// Address: 004c77af
// XREFS: None
undefined4 __thiscall
FUN_004c77af(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if ((param_2 == (int *)0x0) || (param_3 == 0)) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x68) = 0;
  if (0 < param_3) {
    do {
      iVar1 = *param_2;
      if (-1 < iVar1) {
        iVar2 = *(int *)(param_1 + 0x68);
        iVar3 = 0;
        if (0 < iVar2) {
          do {
            if (*(int *)(param_1 + 0x70) <= iVar3) break;
            if (*(int *)(*(int *)(param_1 + 100) + iVar3 * 4) == iVar1) goto LAB_004c786f;
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar2);
        }
        if (*(int *)(param_1 + 0x70) + -1 < iVar2) {
          iVar2 = iVar2 + 1;
          pvVar4 = operator_new(iVar2 * 4);
          if (pvVar4 != (void *)0x0) {
            iVar3 = 0;
            if (0 < *(int *)(param_1 + 0x70)) {
              do {
                if (iVar2 <= iVar3) break;
                iVar3 = iVar3 + 1;
                *(undefined4 *)((int)pvVar4 + iVar3 * 4 + -4) =
                     *(undefined4 *)(*(int *)(param_1 + 100) + -4 + iVar3 * 4);
              } while (iVar3 < *(int *)(param_1 + 0x70));
            }
            operator_delete(*(void **)(param_1 + 100));
            *(void **)(param_1 + 100) = pvVar4;
            *(int *)(param_1 + 0x70) = iVar2;
          }
        }
        *(int *)(*(int *)(param_1 + 100) + *(int *)(param_1 + 0x68) * 4) = iVar1;
        *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
      }
LAB_004c786f:
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  *(undefined4 *)(param_1 + 0x80) = param_5;
  *(undefined4 *)(param_1 + 0x78) = param_4;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c78af
// Address: 004c78af
// XREFS: None
undefined4 __thiscall FUN_004c78af(int param_1,int *param_2,int param_3,int param_4,float param_5)
{
  int *piVar1;
  RGE_Static_Object *this;
  int *piVar2;
  
  piVar1 = param_2;
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    if (0 < param_3) {
      param_2 = (int *)param_3;
      piVar2 = piVar1;
      do {
        this = RGE_Game_World::object(*(RGE_Game_World **)(*(int *)(param_1 + 0xc) + 0x3c),*piVar2);
        if (this != (RGE_Static_Object *)0x0) {
          RGE_Static_Object::createGroup(this,piVar1,param_3,param_4,param_5);
        }
        piVar2 = piVar2 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (param_2 != (int *)0x0);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c791f
// Address: 004c791f
// XREFS: None
undefined4 __thiscall FUN_004c791f(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  
  if (0x18 < *(int *)(param_1 + 0x68)) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x68);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if (*(int *)(param_1 + 0x70) <= iVar2) break;
      if (*(int *)(*(int *)(param_1 + 100) + iVar2 * 4) == param_2) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if (*(int *)(param_1 + 0x70) + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    pvVar3 = operator_new(iVar1 * 4);
    if (pvVar3 != (void *)0x0) {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x70)) {
        do {
          if (iVar1 <= iVar2) break;
          iVar2 = iVar2 + 1;
          *(undefined4 *)((int)pvVar3 + iVar2 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 100) + -4 + iVar2 * 4);
        } while (iVar2 < *(int *)(param_1 + 0x70));
      }
      operator_delete(*(void **)(param_1 + 100));
      *(void **)(param_1 + 100) = pvVar3;
      *(int *)(param_1 + 0x70) = iVar1;
    }
  }
  *(int *)(*(int *)(param_1 + 100) + *(int *)(param_1 + 0x68) * 4) = param_2;
  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c79c2
// Address: 004c79c2
// XREFS: None
undefined4 __thiscall FUN_004c79c2(RGE_Static_Object *param_1,int param_2,float param_3)
{
  int *piVar1;
  int iVar2;
  RGE_Static_Object *this;
  int iVar3;
  uint uVar4;
  int iStack_70;
  RGE_Static_Object *pRStack_68;
  int aiStack_64 [25];
  
  pRStack_68 = RGE_Game_World::object(param_1->owner->world,param_2);
  if (pRStack_68 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  iVar2 = (param_1->groupMembers).numberValue;
  if (0x18 < iVar2) {
    return 0;
  }
  iVar3 = 0;
  iStack_70 = 0;
  if (0 < iVar2) {
    uVar4 = 4;
    do {
      if ((param_1->groupMembers).maximumSizeValue + -1 < iStack_70) {
        piVar1 = (int *)operator_new(uVar4);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (param_1->groupMembers).maximumSizeValue) {
            do {
              if (iStack_70 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar1[iVar2] = (param_1->groupMembers).value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < (param_1->groupMembers).maximumSizeValue);
          }
          operator_delete((param_1->groupMembers).value);
          (param_1->groupMembers).value = piVar1;
          (param_1->groupMembers).maximumSizeValue = iStack_70 + 1;
        }
      }
      iVar2 = *(int *)((int)(param_1->groupMembers).value + (uVar4 - 4));
      iVar3 = param_1->id;
      *(int *)((int)aiStack_64 + (uVar4 - 4)) = iVar2;
      if (iVar2 != iVar3) {
        if ((param_1->groupMembers).maximumSizeValue + -1 < iStack_70) {
          piVar1 = (int *)operator_new(uVar4);
          if (piVar1 != (int *)0x0) {
            iVar2 = 0;
            if (0 < (param_1->groupMembers).maximumSizeValue) {
              do {
                if (iStack_70 + 1 <= iVar2) break;
                iVar3 = iVar2 + 1;
                piVar1[iVar2] = (param_1->groupMembers).value[iVar2];
                iVar2 = iVar3;
              } while (iVar3 < (param_1->groupMembers).maximumSizeValue);
            }
            operator_delete((param_1->groupMembers).value);
            (param_1->groupMembers).value = piVar1;
            (param_1->groupMembers).maximumSizeValue = iStack_70 + 1;
          }
        }
        this = RGE_Game_World::object
                         (param_1->owner->world,
                          *(int *)((int)(param_1->groupMembers).value + (uVar4 - 4)));
        if (this != (RGE_Static_Object *)0x0) {
          RGE_Static_Object::addToGroup(this,param_2,param_3);
        }
      }
      iVar3 = iStack_70 + 1;
      uVar4 = uVar4 + 4;
      iStack_70 = iVar3;
    } while (iVar3 < (param_1->groupMembers).numberValue);
  }
  aiStack_64[iVar3] = param_2;
  RGE_Static_Object::addToGroup(param_1,param_2,param_3);
  RGE_Static_Object::createGroup(pRStack_68,aiStack_64,iVar3 + 1,param_1->id,param_3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c7b5f
// Address: 004c7b5f
// XREFS: None
undefined4 __thiscall FUN_004c7b5f(int param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(int *)(param_1 + 0x70);
  iVar1 = 0;
  if (0 < iVar3) {
    piVar4 = *(int **)(param_1 + 100);
    do {
      if (*piVar4 == param_2) break;
      iVar1 = iVar1 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar1 < iVar3);
  }
  if (iVar1 < iVar3) {
    if (iVar1 < iVar3 + -1) {
      do {
        iVar1 = iVar1 + 1;
        *(undefined4 *)(*(int *)(param_1 + 100) + -4 + iVar1 * 4) =
             *(undefined4 *)(*(int *)(param_1 + 100) + iVar1 * 4);
      } while (iVar1 < *(int *)(param_1 + 0x70) + -1);
    }
    iVar3 = *(int *)(param_1 + 0x68) + -1;
    *(int *)(param_1 + 0x68) = iVar3;
    if (iVar3 < 0) {
      *(undefined4 *)(param_1 + 0x68) = 0;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  if (*(int *)(param_1 + 0x68) < 1) {
    *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_004c7bc6
// Address: 004c7bc6
// XREFS: None
int __thiscall FUN_004c7bc6(RGE_Static_Object *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  
  if ((param_2 == param_1->id) && (param_1->id == param_1->groupCommanderValue)) {
    iVar1 = RGE_Static_Object::commanderDestroyGroup(param_1);
    return iVar1;
  }
  iVar1 = 0;
  if (0 < (param_1->groupMembers).numberValue) {
    do {
      if ((param_1->groupMembers).maximumSizeValue + -1 < iVar1) {
        piVar2 = (int *)operator_new(iVar1 * 4 + 4);
        if (piVar2 != (int *)0x0) {
          iVar5 = 0;
          if (0 < (param_1->groupMembers).maximumSizeValue) {
            do {
              if (iVar1 + 1 <= iVar5) break;
              iVar3 = iVar5 + 1;
              piVar2[iVar5] = (param_1->groupMembers).value[iVar5];
              iVar5 = iVar3;
            } while (iVar3 < (param_1->groupMembers).maximumSizeValue);
          }
          operator_delete((param_1->groupMembers).value);
          (param_1->groupMembers).value = piVar2;
          (param_1->groupMembers).maximumSizeValue = iVar1 + 1;
        }
      }
      pRVar4 = RGE_Game_World::object(param_1->owner->world,(param_1->groupMembers).value[iVar1]);
      if ((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar4->id != param_1->id)) {
        iVar5 = (pRVar4->groupMembers).maximumSizeValue;
        iVar3 = 0;
        if (0 < iVar5) {
          piVar2 = (pRVar4->groupMembers).value;
          do {
            if (*piVar2 == param_2) break;
            iVar3 = iVar3 + 1;
            piVar2 = piVar2 + 1;
          } while (iVar3 < iVar5);
        }
        if (iVar3 < iVar5) {
          if (iVar3 < iVar5 + -1) {
            do {
              piVar2 = (pRVar4->groupMembers).value;
              iVar5 = iVar3 + 1;
              piVar2[iVar3] = piVar2[iVar5];
              iVar3 = iVar5;
            } while (iVar5 < (pRVar4->groupMembers).maximumSizeValue + -1);
          }
          iVar5 = (pRVar4->groupMembers).numberValue + -1;
          (pRVar4->groupMembers).numberValue = iVar5;
          if (iVar5 < 0) {
            (pRVar4->groupMembers).numberValue = 0;
          }
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < (param_1->groupMembers).numberValue);
  }
  RGE_Static_Object::removeFromGroup(param_1,param_2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c7cdc
// Address: 004c7cdc
// XREFS: None
undefined4 __fastcall FUN_004c7cdc(int param_1)
{
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c7cf4
// Address: 004c7cf4
// XREFS: None
undefined4 __fastcall FUN_004c7cf4(RGE_Static_Object *param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  RGE_Static_Object *this;
  int iVar4;
  
  iVar4 = 0;
  if (0 < (param_1->groupMembers).numberValue) {
    do {
      if ((param_1->groupMembers).maximumSizeValue + -1 < iVar4) {
        piVar1 = (int *)operator_new(iVar4 * 4 + 4);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < (param_1->groupMembers).maximumSizeValue) {
            do {
              if (iVar4 + 1 <= iVar2) break;
              iVar3 = iVar2 + 1;
              piVar1[iVar2] = (param_1->groupMembers).value[iVar2];
              iVar2 = iVar3;
            } while (iVar3 < (param_1->groupMembers).maximumSizeValue);
          }
          operator_delete((param_1->groupMembers).value);
          (param_1->groupMembers).value = piVar1;
          (param_1->groupMembers).maximumSizeValue = iVar4 + 1;
        }
      }
      this = RGE_Game_World::object(param_1->owner->world,(param_1->groupMembers).value[iVar4]);
      if ((this != (RGE_Static_Object *)0x0) && (this->id != param_1->id)) {
        RGE_Static_Object::destroyGroup(this);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (param_1->groupMembers).numberValue);
  }
  RGE_Static_Object::destroyGroup(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c7daa
// Address: 004c7daa
// XREFS: None
void __thiscall FUN_004c7daa(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = 0;
  iVar1 = *(int *)(param_1 + 0x58);
  if (0 < iVar1) {
    do {
      if (*(int *)(param_1 + 0x60) <= iVar2) break;
      if (*(int *)(*(int *)(param_1 + 0x54) + iVar2 * 4) == param_2) {
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if (*(int *)(param_1 + 0x60) + -1 < iVar1) {
    iVar1 = iVar1 + 1;
    pvVar3 = operator_new(iVar1 * 4);
    if (pvVar3 != (void *)0x0) {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x60)) {
        do {
          if (iVar1 <= iVar2) break;
          iVar2 = iVar2 + 1;
          *(undefined4 *)((int)pvVar3 + iVar2 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0x54) + -4 + iVar2 * 4);
        } while (iVar2 < *(int *)(param_1 + 0x60));
      }
      operator_delete(*(void **)(param_1 + 0x54));
      *(void **)(param_1 + 0x54) = pvVar3;
      *(int *)(param_1 + 0x60) = iVar1;
    }
  }
  *(int *)(*(int *)(param_1 + 0x54) + *(int *)(param_1 + 0x58) * 4) = param_2;
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004c7e41
// Address: 004c7e41
// XREFS: None
void __fastcall FUN_004c7e41(int param_1)
{
  int iVar1;
  
  iVar1 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1 + 0xc));
  if (iVar1 == 1) {
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c7e69
// Address: 004c7e69
// XREFS: None
void __fastcall FUN_004c7e69(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = __ftol();
  iVar2 = __ftol();
  RGE_Map::request_redraw
            (*(RGE_Map **)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28),iVar1 + -2,iVar2 + -2,
             iVar1 + 1,iVar2 + 1,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_004c7ea9
// Address: 004c7ea9
// XREFS: None
void __thiscall FUN_004c7ea9(int param_1,char param_2)
{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x49) != param_2) {
    if (param_2 == '\0') {
      if (*(char *)(param_1 + 0x4b) != '\0') {
        *(undefined1 *)(param_1 + 0x49) = 0;
        *(undefined1 *)(param_1 + 0x4b) = 0;
        return;
      }
      (**(code **)(**(int **)(param_1 + 0xc) + 0xe0))
                (param_1,*(char *)(param_1 + 0x49),*(undefined1 *)(param_1 + 0x4a),
                 *(undefined4 *)(param_1 + 0x50));
      *(undefined1 *)(param_1 + 0x49) = 0;
      uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0xdc))
                        (param_1,0,*(undefined1 *)(param_1 + 0x4a));
      *(undefined4 *)(param_1 + 0x50) = uVar1;
      return;
    }
    *(undefined1 *)(param_1 + 0x4b) = 1;
    *(char *)(param_1 + 0x49) = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c7f23
// Address: 004c7f23
// XREFS: None
undefined4 FUN_004c7f23(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c7f33
// Address: 004c7f33
// XREFS: None
undefined4 FUN_004c7f33(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_004c7f43
// Address: 004c7f43
// XREFS: None
TRIBE_Building_Object * __thiscall
FUN_004c7f43(TRIBE_Building_Object *param_1,TRIBE_Master_Building_Object *param_2,
            RGE_Player *param_3,float param_4,float param_5,float param_6,int param_7,int param_8)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fa78;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Combat_Object::TRIBE_Combat_Object
            ((TRIBE_Combat_Object *)param_1,(TRIBE_Master_Combat_Object *)param_2,param_3,param_4,
             param_5,param_6,0);
  uStack_4 = 0;
  param_1->unique_build_id = param_7;
  param_1->production_queue = (Production_Queue_Record *)0x0;
  param_1->production_queue_size = 0;
  param_1->production_queue_count = 0;
  param_1->production_queue_enabled = '\x01';
  param_1->production_queue_actions = (RGE_Action_List *)0x0;
  param_1->production_queue_change_flag = '\0';
  param_1->production_queue_auto_paused = '\0';
  param_1->production_queue_need_attr = -1;
  param_1->DoppleInstalled = 0;
  param_1->_padding_ = (int)&TRIBE_Building_Object::_vftable_;
  if (param_8 != 0) {
    TRIBE_Building_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  if (*(short *)(param_1->_padding_ + 0x10) == 0x114) {
    RGE_Action_Object::set_task((RGE_Action_Object *)param_1,*(short *)(param_1->_padding_ + 0xdc));
  }
  iVar1 = __ftol();
  iVar2 = __ftol();
  iVar1 = RGE_Doppleganger_Creator::add_doppleganger_check
                    (*(RGE_Doppleganger_Creator **)(param_1->_padding_ + 0x40),
                     (RGE_Static_Object *)param_1,(ulong *)((&unified_map_offsets)[iVar1] + iVar2));
  param_1->DoppleInstalled = iVar1;
  param_1->PriorMap1 = 0;
  param_1->PriorMap2 = 0;
  param_1->PriorMap3 = 0;
  param_1->PriorTurn1 = 0;
  param_1->PriorTurn2 = 0;
  param_1->PriorTurn3 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004c8087
// Address: 004c8087
// XREFS: None
TRIBE_Building_Object * __thiscall FUN_004c8087(TRIBE_Building_Object *param_1,byte param_2)
{
  TRIBE_Building_Object::~TRIBE_Building_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004c80ae
// Address: 004c80ae
// XREFS: None
TRIBE_Building_Object * __thiscall
FUN_004c80ae(TRIBE_Building_Object *param_1,TRIBE_Master_Building_Object *param_2,
            RGE_Player *param_3,float param_4,float param_5,float param_6,int param_7)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fa98;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Combat_Object::TRIBE_Combat_Object
            ((TRIBE_Combat_Object *)param_1,(TRIBE_Master_Combat_Object *)param_2,param_3,param_4,
             param_5,param_6,0);
  uStack_4 = 0;
  param_1->production_queue_need_attr = -1;
  param_1->unique_build_id = -1;
  param_1->production_queue = (Production_Queue_Record *)0x0;
  param_1->production_queue_size = 0;
  param_1->production_queue_count = 0;
  param_1->production_queue_enabled = '\x01';
  param_1->production_queue_actions = (RGE_Action_List *)0x0;
  param_1->production_queue_change_flag = '\0';
  param_1->production_queue_auto_paused = '\0';
  param_1->DoppleInstalled = 0;
  param_1->_padding_ = (int)&TRIBE_Building_Object::_vftable_;
  if (param_7 != 0) {
    TRIBE_Building_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  iVar1 = __ftol();
  iVar2 = __ftol();
  iVar1 = RGE_Doppleganger_Creator::add_doppleganger_check
                    (*(RGE_Doppleganger_Creator **)(param_1->_padding_ + 0x40),
                     (RGE_Static_Object *)param_1,(ulong *)((&unified_map_offsets)[iVar1] + iVar2));
  param_1->DoppleInstalled = iVar1;
  param_1->PriorMap1 = 0;
  param_1->PriorMap2 = 0;
  param_1->PriorMap3 = 0;
  param_1->PriorTurn1 = 0;
  param_1->PriorTurn2 = 0;
  param_1->PriorTurn3 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004c81ca
// Address: 004c81ca
// XREFS: None
TRIBE_Building_Object * __thiscall
FUN_004c81ca(TRIBE_Building_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fab8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TRIBE_Combat_Object::TRIBE_Combat_Object((TRIBE_Combat_Object *)param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->production_queue = (Production_Queue_Record *)0x0;
  param_1->production_queue_size = 0;
  param_1->production_queue_count = 0;
  param_1->production_queue_enabled = '\x01';
  param_1->production_queue_actions = (RGE_Action_List *)0x0;
  param_1->production_queue_change_flag = '\0';
  param_1->production_queue_auto_paused = '\0';
  param_1->production_queue_need_attr = -1;
  param_1->DoppleInstalled = 0;
  param_1->_padding_ = (int)&TRIBE_Building_Object::_vftable_;
  if (param_4 != 0) {
    TRIBE_Building_Object::setup(param_1,param_2,param_3);
  }
  iVar1 = __ftol();
  iVar2 = __ftol();
  iVar1 = RGE_Doppleganger_Creator::add_doppleganger_check
                    (*(RGE_Doppleganger_Creator **)(param_1->_padding_ + 0x40),
                     (RGE_Static_Object *)param_1,(ulong *)((&unified_map_offsets)[iVar1] + iVar2));
  param_1->DoppleInstalled = iVar1;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004c829f
// Address: 004c829f
// XREFS: None
void __fastcall FUN_004c829f(TRIBE_Combat_Object *param_1)
{
  short sVar1;
  RGE_Action_List *this;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055fad8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Building_Object::_vftable_;
  uStack_4 = 0;
  RGE_Doppleganger_Creator::remove_doppleganger_check
            (*(RGE_Doppleganger_Creator **)(param_1->_padding_ + 0x40),(RGE_Static_Object *)param_1)
  ;
  this = (RGE_Action_List *)param_1[1]._padding_;
  if (this != (RGE_Action_List *)0x0) {
    RGE_Action_List::~RGE_Action_List(this);
    operator_delete(this);
    param_1[1]._padding_ = 0;
  }
  if (param_1[1]._padding_ != 0) {
    free(param_1[1]._padding_);
    sVar1 = *(short *)((int)&param_1[1]._padding_ + 2);
    param_1[1]._padding_ = 0;
    if (sVar1 == 4) {
      iVar2 = param_1->_padding_;
      *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0xffff;
      iVar2 = (int)*(short *)(iVar2 + 0x4a);
      *(int *)(rge_base_game[1].save_music_file + iVar2 * 4 + -0x70) =
           *(int *)(rge_base_game[1].save_music_file + iVar2 * 4 + -0x70) + -1;
    }
  }
  uStack_4 = 0xffffffff;
  TRIBE_Combat_Object::~TRIBE_Combat_Object(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004c8366
// Address: 004c8366
// XREFS: None
void __fastcall FUN_004c8366(RGE_Action_Object *param_1)
{
  if ((RGE_Action_List *)param_1[1]._padding_ != (RGE_Action_List *)0x0) {
    RGE_Action_List::delete_list((RGE_Action_List *)param_1[1]._padding_);
  }
  if (param_1[1]._padding_ != 0) {
    free(param_1[1]._padding_);
    param_1[1]._padding_ = 0;
    *(undefined2 *)&param_1[1]._padding_ = 0;
    *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0;
    *(undefined1 *)&param_1[1]._padding_ = 1;
    *(undefined1 *)&param_1[1]._padding_ = 0;
    *(undefined1 *)((int)&param_1[1]._padding_ + 1) = 0;
    *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0xffff;
  }
  RGE_Action_Object::recycle_out_of_game(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004c83d2
// Address: 004c83d2
// XREFS: None
undefined4 __thiscall
FUN_004c83d2(TRIBE_Combat_Object *param_1,TRIBE_Master_Combat_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  int iVar1;
  float fVar2;
  int iVar3;
  
  *(undefined1 *)((int)&param_1[1]._padding_ + 1) = 0;
  TRIBE_Combat_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  iVar3 = param_1->_padding_;
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x50;
  (**(code **)(iVar3 + 0x5c))(0);
  if (0 < *(short *)(param_1->_padding_ + 0x15a)) {
    (**(code **)(iVar3 + 0x38))(*(undefined4 *)(param_1->_padding_ + 0x168));
  }
  iVar1 = param_1->_padding_;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = 0x3f800000;
  *(undefined1 *)((int)&param_1->_padding_ + 1) = *(undefined1 *)(iVar1 + 0x16e);
  fVar2 = (float)param_1->_padding_;
  *(uchar *)&param_1[1]._padding_ = param_3->culture;
  TRIBE_World::check_destructables
            (*(TRIBE_World **)(param_1->_padding_ + 0x3c),*(short *)(param_1->_padding_ + 0x4a),
             *(short *)(iVar1 + 0x10),(float)param_1->_padding_,fVar2,'\0');
  iVar3 = (**(code **)(iVar3 + 0x218))();
  param_1[1]._padding_ = iVar3;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c85c3
// Address: 004c85c3
// XREFS: None
void __fastcall FUN_004c85c3(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0x6a;
  iVar3 = 0x70;
  do {
    iVar1 = *(int *)(param_1 + 8);
    if ((3 < *(byte *)(iVar4 + 0x88 + iVar1)) && (-1 < *(short *)(iVar2 + iVar1))) {
      (**(code **)(**(int **)(param_1 + 0xc) + 0x78))
                (*(short *)(iVar2 + iVar1),-*(float *)(iVar3 + iVar1),0);
    }
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 2;
  } while (iVar3 < 0x7c);
  return;
}

// --------------------------------------------------

// Function: FUN_004c8626
// Address: 004c8626
// XREFS: None
void __fastcall FUN_004c8626(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0x6a;
  iVar3 = 0x70;
  do {
    iVar1 = *(int *)(param_1 + 8);
    if ((3 < *(byte *)(iVar4 + 0x88 + iVar1)) && (-1 < *(short *)(iVar2 + iVar1))) {
      (**(code **)(**(int **)(param_1 + 0xc) + 0x78))
                (*(short *)(iVar2 + iVar1),*(undefined4 *)(iVar3 + iVar1),0);
    }
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 2;
  } while (iVar3 < 0x7c);
  return;
}

// --------------------------------------------------

// Function: FUN_004c8681
// Address: 004c8681
// XREFS: None
void __fastcall FUN_004c8681(RGE_Action_Object *param_1)
{
  (**(code **)(param_1->_padding_ + 600))();
  RGE_Action_Object::destroy_obj(param_1);
  RGE_Doppleganger_Creator::remove_doppleganger_check
            (*(RGE_Doppleganger_Creator **)(param_1->_padding_ + 0x40),(RGE_Static_Object *)param_1)
  ;
  param_1[1]._padding_ = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004c86ba
// Address: 004c86ba
// XREFS: None
uchar __thiscall FUN_004c86ba(TRIBE_Combat_Object *param_1,float param_2)
{
  int iVar1;
  float fVar2;
  uchar uVar3;
  
  iVar1 = param_1->_padding_;
  fVar2 = (float)(int)*(short *)(iVar1 + 0x26);
  param_2 = (param_2 * fVar2) / (float)(int)*(short *)(iVar1 + 0x15a);
  if (fVar2 < param_2 + (float)param_1->_padding_) {
    param_2 = fVar2 - (float)param_1->_padding_;
  }
  uVar3 = TRIBE_Player::pay_obj_cost
                    ((TRIBE_Player *)param_1->_padding_,*(short *)(iVar1 + 0x10),
                     param_2 / (float)(*(short *)(iVar1 + 0x26) * 2),0);
  if (uVar3 == '\0') {
    return '\x02';
  }
  uVar3 = TRIBE_Combat_Object::heal(param_1,param_2);
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_004c8a57
// Address: 004c8a57
// XREFS: None
void __fastcall FUN_004c8a57(RGE_Action_Object *param_1)
{
  RGE_Action_Object::rehook(param_1);
  RGE_Action_List::rehook((RGE_Action_List *)param_1[1]._padding_);
  return;
}

// --------------------------------------------------

// Function: FUN_004c8a75
// Address: 004c8a75
// XREFS: None
undefined4 __fastcall FUN_004c8a75(TRIBE_Building_Object *param_1)
{
  short sVar1;
  int iVar2;
  byte bVar3;
  uchar uVar4;
  
  if ((char)param_1->_padding_ == '\0') {
    iVar2 = param_1->_padding_;
    sVar1 = *(short *)(param_1->_padding_ + 0x60);
    bVar3 = __ftol();
    if (((short)(ushort)bVar3 < sVar1) && (bVar3 != *(byte *)((int)&param_1->_padding_ + 1))) {
      *(byte *)((int)&param_1->_padding_ + 1) = bVar3;
    }
    if ((float)(int)*(short *)(iVar2 + 0x15a) <= param_1->build_pts) {
      (**(code **)(param_1->_padding_ + 0x5c))(2);
    }
  }
  param_1->PriorMap3 = param_1->PriorMap2;
  param_1->PriorMap2 = param_1->PriorMap1;
  param_1->PriorTurn3 = param_1->PriorTurn2;
  param_1->PriorTurn2 = param_1->PriorTurn1;
  param_1->PriorTurn1 = world_update_counter;
  uVar4 = TRIBE_Combat_Object::update((TRIBE_Combat_Object *)param_1);
  if (2 < (byte)param_1->_padding_) {
    TRIBE_Building_Object::empty_production_queue(param_1);
    param_1->PriorMap1 = param_1->_padding_;
    return CONCAT31((int3)((uint)param_1->_padding_ >> 8),uVar4);
  }
  TRIBE_Building_Object::update_production_queue(param_1);
  param_1->PriorMap1 = param_1->_padding_;
  return CONCAT31((int3)((uint)param_1->_padding_ >> 8),uVar4);
}

// --------------------------------------------------

// Function: FUN_004c8b71
// Address: 004c8b71
// XREFS: None
void __thiscall
FUN_004c8b71(RGE_Static_Object *param_1,RGE_Player *param_2,uchar param_3,int param_4)
{
  if (*(char *)((int)&param_1[3].attribute_type_held + 1) != '\0') {
    RGE_Static_Object::explore_terrain(param_1,param_2,param_3,param_4);
    return;
  }
  RGE_Static_Object::explore_terrain(param_1,param_2,'\x01',param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_004c8bb5
// Address: 004c8bb5
// XREFS: None
void __thiscall FUN_004c8bb5(TRIBE_Combat_Object *param_1,int param_2)
{
  short sVar1;
  short sVar2;
  
  TRIBE_Combat_Object::save(param_1,param_2);
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 1),1);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,1);
  rge_write(param_2,&param_1[1]._padding_,2);
  sVar1 = (short)param_1[1]._padding_;
  if (0 < sVar1) {
    sVar2 = 0;
    if (0 < sVar1) {
      do {
        rge_write(param_2,(void *)(param_1[1]._padding_ + sVar2 * 4),2);
        rge_write(param_2,(void *)(param_1[1]._padding_ + 2 + sVar2 * 4),2);
        sVar2 = sVar2 + 1;
      } while (sVar2 < (short)param_1[1]._padding_);
    }
  }
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_write(param_2,&param_1[1]._padding_,1);
  RGE_Action_List::save((RGE_Action_List *)param_1[1]._padding_,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004c8caa
// Address: 004c8caa
// XREFS: None
void __thiscall FUN_004c8caa(TRIBE_Combat_Object *param_1,RGE_Player *param_2)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_4;
  
  if ((char)param_1->_padding_ == '\x02') {
    iVar3 = 0;
    iStack_4 = 0x6a;
    iVar4 = 0x70;
    do {
      iVar2 = param_1->_padding_;
      if ((3 < *(byte *)(iVar3 + 0x88 + iVar2)) && (-1 < *(short *)(iStack_4 + iVar2))) {
        (**(code **)(*(int *)param_1->_padding_ + 0x78))
                  (*(short *)(iStack_4 + iVar2),-*(float *)(iVar4 + iVar2),0);
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar3 + 1;
      iStack_4 = iStack_4 + 2;
    } while (iVar4 < 0x7c);
  }
  if ((char)param_1->_padding_ == '\0') {
    (**(code **)(param_1->_padding_ + 0xdc))(param_1->_padding_,1,0xffffffff);
  }
  if (0 < *(short *)((int)&param_1[1]._padding_ + 2)) {
    if (*(short *)((int)&param_1[1]._padding_ + 2) == 4) {
      iVar3 = param_1->_padding_;
      *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0xffff;
      iVar3 = (int)*(short *)(iVar3 + 0x4a);
      *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) =
           *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) + -1;
    }
    iVar3 = param_1[1]._padding_;
    *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 1;
    *(undefined2 *)(iVar3 + 2) = 1;
  }
  RGE_Action_List::delete_list((RGE_Action_List *)param_1->_padding_);
  TRIBE_Combat_Object::change_ownership(param_1,param_2);
  if ((char)param_1->_padding_ == '\0') {
    (**(code **)(param_1->_padding_ + 0xd8))(param_1->_padding_,1,0xffffffff);
  }
  if ((char)param_1->_padding_ == '\x02') {
    sVar1 = *(short *)(param_1->_padding_ + 0x172);
    if (-1 < sVar1) {
      (**(code **)(**(int **)(*(int *)(param_1->_padding_ + 0x24) + sVar1 * 4) + 0x18))
                (param_1->_padding_,param_1->_padding_,param_1->_padding_,param_1->_padding_);
    }
    sVar1 = *(short *)(param_1->_padding_ + 0x178);
    if (-1 < sVar1) {
      TRIBE_Player_Tech::do_tech(*(TRIBE_Player_Tech **)(param_1->_padding_ + 0x220),sVar1);
    }
    if ((char)param_1->_padding_ == '\x02') {
      iVar3 = 0;
      param_2 = (RGE_Player *)0x6a;
      iVar4 = 0x70;
      do {
        iVar2 = param_1->_padding_;
        if ((3 < *(byte *)(iVar3 + 0x88 + iVar2)) && (-1 < *(short *)((int)param_2 + iVar2))) {
          (**(code **)(*(int *)param_1->_padding_ + 0x78))
                    (CONCAT22((short)((uint)param_2 >> 0x10),*(short *)((int)param_2 + iVar2)),
                     *(undefined4 *)(iVar4 + iVar2),0);
        }
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
        param_2 = (RGE_Player *)((int)param_2 + 2);
      } while (iVar4 < 0x7c);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c8e8a
// Address: 004c8e8a
// XREFS: None
void __thiscall FUN_004c8e8a(TRIBE_Combat_Object *param_1,RGE_Master_Static_Object *param_2)
{
  TRIBE_Combat_Object::transform(param_1,param_2);
  *(undefined1 *)&param_1->_padding_ = 0;
  if (0 < *(short *)(param_1->_padding_ + 0x15a)) {
    (**(code **)(param_1->_padding_ + 0x38))(param_2[1].outline_radius_y);
  }
  param_1[1]._padding_ = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004c8ecc
// Address: 004c8ecc
// XREFS: None
int __thiscall FUN_004c8ecc(int param_1,undefined4 *param_2)
{
  short sVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  RGE_Static_Object *pRVar6;
  int iStack_10;
  
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  sVar4 = __ftol();
  sVar5 = __ftol();
  sVar1 = *(short *)(iVar3 + 8);
  iStack_10 = 0;
  sVar2 = *(short *)(iVar3 + 0xc);
  if (sVar5 < 1) {
LAB_004c8f71:
    *param_2 = 0;
  }
  else {
    pRVar6 = RGE_Object_List::find_by_master_id
                       ((RGE_Object_List *)
                        (*(int *)(*(int *)(iVar3 + 0x8d8c) + -4 + sVar5 * 4) + 0xc + sVar4 * 0x18),
                        (int)*(short *)(*(int *)(param_1 + 8) + 0x10),-1.0,-1.0,'\0','\0',
                        (RGE_Static_Object *)0x0);
    *param_2 = pRVar6;
    if (pRVar6 != (RGE_Static_Object *)0x0) {
      if (pRVar6->owner != *(RGE_Player **)(param_1 + 0xc)) goto LAB_004c8f71;
      iStack_10 = 1;
    }
  }
  if (sVar4 < 1) {
LAB_004c8fca:
    param_2[1] = 0;
  }
  else {
    pRVar6 = RGE_Object_List::find_by_master_id
                       ((RGE_Object_List *)
                        (*(int *)(*(int *)(iVar3 + 0x8d8c) + sVar5 * 4) + -0xc + sVar4 * 0x18),
                        (int)*(short *)(*(int *)(param_1 + 8) + 0x10),-1.0,-1.0,'\0','\0',
                        (RGE_Static_Object *)0x0);
    param_2[1] = pRVar6;
    if (pRVar6 != (RGE_Static_Object *)0x0) {
      if (pRVar6->owner != *(RGE_Player **)(param_1 + 0xc)) goto LAB_004c8fca;
      iStack_10 = iStack_10 + 1;
    }
  }
  if (sVar4 < (short)(sVar1 + -1)) {
    pRVar6 = RGE_Object_List::find_by_master_id
                       ((RGE_Object_List *)
                        (*(int *)(*(int *)(iVar3 + 0x8d8c) + sVar5 * 4) + 0x24 + sVar4 * 0x18),
                        (int)*(short *)(*(int *)(param_1 + 8) + 0x10),-1.0,-1.0,'\0','\0',
                        (RGE_Static_Object *)0x0);
    param_2[2] = pRVar6;
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004c902d;
    if (pRVar6->owner == *(RGE_Player **)(param_1 + 0xc)) {
      iStack_10 = iStack_10 + 1;
      goto LAB_004c902d;
    }
  }
  param_2[2] = 0;
LAB_004c902d:
  if (sVar5 < (short)(sVar2 + -1)) {
    pRVar6 = RGE_Object_List::find_by_master_id
                       ((RGE_Object_List *)
                        (*(int *)(*(int *)(iVar3 + 0x8d8c) + 4 + sVar5 * 4) + 0xc + sVar4 * 0x18),
                        (int)*(short *)(*(int *)(param_1 + 8) + 0x10),-1.0,-1.0,'\0','\0',
                        (RGE_Static_Object *)0x0);
    param_2[3] = pRVar6;
    if (pRVar6 == (RGE_Static_Object *)0x0) {
      return iStack_10;
    }
    if (pRVar6->owner == *(RGE_Player **)(param_1 + 0xc)) {
      return iStack_10 + 1;
    }
  }
  param_2[3] = 0;
  return iStack_10;
}

// --------------------------------------------------

// Function: FUN_004c90a3
// Address: 004c90a3
// XREFS: None
void __fastcall FUN_004c90a3(TRIBE_Building_Object *param_1)
{
  byte bVar1;
  int iVar2;
  TRIBE_Building_Object *pTStack_10;
  TRIBE_Building_Object *pTStack_c;
  TRIBE_Building_Object *pTStack_8;
  TRIBE_Building_Object *pTStack_4;
  
  if (param_1->_padding_ == 0) {
    return;
  }
  if (*(short *)(param_1->_padding_ + 0x60) != 3) {
    *(undefined1 *)((int)&param_1->_padding_ + 1) = 0;
    return;
  }
  RGE_Moving_Object::set_angle((RGE_Moving_Object *)param_1);
  TRIBE_Building_Object::check(param_1,&pTStack_10);
  if ((pTStack_10 == (TRIBE_Building_Object *)0x0) || (pTStack_4 == (TRIBE_Building_Object *)0x0)) {
LAB_004c9108:
    if (pTStack_c != (TRIBE_Building_Object *)0x0) {
LAB_004c910c:
      if (((pTStack_8 != (TRIBE_Building_Object *)0x0) &&
          (pTStack_10 == (TRIBE_Building_Object *)0x0)) &&
         (pTStack_4 == (TRIBE_Building_Object *)0x0)) {
        iVar2 = -(uint)*(byte *)((int)&param_1->_padding_ + 1);
        goto LAB_004c912d;
      }
    }
    iVar2 = 2;
    bVar1 = *(byte *)((int)&param_1->_padding_ + 1);
  }
  else {
    if (pTStack_c != (TRIBE_Building_Object *)0x0) goto LAB_004c910c;
    if (pTStack_8 != (TRIBE_Building_Object *)0x0) goto LAB_004c9108;
    bVar1 = *(byte *)((int)&param_1->_padding_ + 1);
    iVar2 = 1;
  }
  iVar2 = iVar2 - (uint)bVar1;
LAB_004c912d:
  RGE_Moving_Object::rotate((RGE_Moving_Object *)param_1,iVar2);
  if (pTStack_10 != (TRIBE_Building_Object *)0x0) {
    TRIBE_Building_Object::connect2(pTStack_10);
  }
  if (pTStack_c != (TRIBE_Building_Object *)0x0) {
    TRIBE_Building_Object::connect2(pTStack_c);
  }
  if (pTStack_8 != (TRIBE_Building_Object *)0x0) {
    TRIBE_Building_Object::connect2(pTStack_8);
  }
  if (pTStack_4 == (TRIBE_Building_Object *)0x0) {
    return;
  }
  TRIBE_Building_Object::connect2(pTStack_4);
  return;
}

// --------------------------------------------------

// Function: FUN_004c9178
// Address: 004c9178
// XREFS: None
void __fastcall FUN_004c9178(TRIBE_Building_Object *param_1)
{
  TRIBE_Building_Object *pTStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if (param_1->_padding_ == 0) {
    return;
  }
  if (*(short *)(param_1->_padding_ + 0x60) != 3) {
    *(undefined1 *)((int)&param_1->_padding_ + 1) = 0;
    return;
  }
  TRIBE_Building_Object::check(param_1,&pTStack_10);
  if ((pTStack_10 == (TRIBE_Building_Object *)0x0) || (iStack_4 == 0)) {
LAB_004c91db:
    if (iStack_c == 0) goto LAB_004c91fe;
  }
  else if (iStack_c == 0) {
    if (iStack_8 == 0) {
      RGE_Moving_Object::rotate
                ((RGE_Moving_Object *)param_1,1 - (uint)*(byte *)((int)&param_1->_padding_ + 1));
      return;
    }
    goto LAB_004c91db;
  }
  if (((iStack_8 != 0) && (pTStack_10 == (TRIBE_Building_Object *)0x0)) && (iStack_4 == 0)) {
    RGE_Moving_Object::rotate
              ((RGE_Moving_Object *)param_1,-(uint)*(byte *)((int)&param_1->_padding_ + 1));
    return;
  }
LAB_004c91fe:
  RGE_Moving_Object::rotate
            ((RGE_Moving_Object *)param_1,2 - (uint)*(byte *)((int)&param_1->_padding_ + 1));
  return;
}

// --------------------------------------------------

// Function: FUN_004c9222
// Address: 004c9222
// XREFS: None
void __fastcall FUN_004c9222(int param_1)
{
  int iVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 uStack_c;
  undefined2 uStack_8;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  if (0x7fff < *(ushort *)(*(int *)(param_1 + 8) + 0x174)) {
    uStack_8 = __ftol();
    uStack_c = __ftol();
    sVar3 = __ftol();
    sVar4 = __ftol();
    if (uStack_8 < 0) {
      uStack_8 = 0;
    }
    if (sVar3 < 0) {
      sVar3 = 0;
    }
    if (*(int *)(iVar1 + 8) <= (int)uStack_c) {
      uStack_c = *(short *)(iVar1 + 8) + -1;
    }
    if (*(int *)(iVar1 + 0xc) <= (int)sVar4) {
      sVar4 = *(short *)(iVar1 + 0xc) + -1;
    }
    if (sVar3 <= sVar4) {
      iVar7 = sVar3 * 4;
      iVar6 = ((int)sVar4 - (int)sVar3) + 1;
      do {
        if (uStack_8 <= uStack_c) {
          iVar8 = uStack_8 * 0x18;
          iVar9 = ((int)uStack_c - (int)uStack_8) + 1;
          do {
            iVar5 = *(int *)(iVar7 + *(int *)(iVar1 + 0x8d8c)) + iVar8;
            bVar2 = *(byte *)(iVar5 + 5);
            if ((bVar2 & 0x1f) == 0) {
              bVar2 = bVar2 & 0xf0 | 0x10;
LAB_004c933d:
              *(byte *)(iVar5 + 5) = bVar2;
            }
            else {
              if ((bVar2 & 0x1f) == 1) {
                bVar2 = bVar2 & 0xef | 0xf;
                goto LAB_004c933d;
              }
              if ((bVar2 & 0x1f) == 6) {
                bVar2 = bVar2 & 0xee | 0xe;
                goto LAB_004c933d;
              }
            }
            iVar8 = iVar8 + 0x18;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        iVar7 = iVar7 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c9354
// Address: 004c9354
// XREFS: None
void __fastcall FUN_004c9354(int param_1)
{
  int iVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 uStack_c;
  undefined2 uStack_8;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  if (0x7fff < *(ushort *)(*(int *)(param_1 + 8) + 0x174)) {
    uStack_8 = __ftol();
    uStack_c = __ftol();
    sVar3 = __ftol();
    sVar4 = __ftol();
    if (uStack_8 < 0) {
      uStack_8 = 0;
    }
    if (sVar3 < 0) {
      sVar3 = 0;
    }
    if (*(int *)(iVar1 + 8) <= (int)uStack_c) {
      uStack_c = *(short *)(iVar1 + 8) + -1;
    }
    if (*(int *)(iVar1 + 0xc) <= (int)sVar4) {
      sVar4 = *(short *)(iVar1 + 0xc) + -1;
    }
    if (sVar3 <= sVar4) {
      iVar8 = sVar3 * 4;
      iVar7 = ((int)sVar4 - (int)sVar3) + 1;
      do {
        if (uStack_8 <= uStack_c) {
          iVar9 = uStack_8 * 0x18;
          iVar10 = ((int)uStack_c - (int)uStack_8) + 1;
          do {
            iVar5 = *(int *)(iVar8 + *(int *)(iVar1 + 0x8d8c)) + iVar9;
            bVar2 = *(byte *)(iVar5 + 5);
            bVar6 = bVar2 & 0x1f;
            if (bVar6 == 0xe) {
              bVar2 = bVar2 & 0xe6 | 6;
LAB_004c9469:
              *(byte *)(iVar5 + 5) = bVar2;
            }
            else {
              if (bVar6 == 0xf) {
                bVar2 = bVar2 & 0xe1 | 1;
                goto LAB_004c9469;
              }
              if (bVar6 == 0x10) {
                bVar2 = bVar2 & 0xe0;
                goto LAB_004c9469;
              }
            }
            iVar9 = iVar9 + 0x18;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        iVar8 = iVar8 + 4;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c955e
// Address: 004c955e
// XREFS: None
undefined4 __thiscall FUN_004c955e(int *param_1,float param_2)
{
  float fVar1;
  int iVar2;
  
  if ((char)param_1[0x12] != '\0') {
    return 1;
  }
  iVar2 = param_1[2];
  fVar1 = (float)(int)*(short *)(iVar2 + 0x15a);
  if (fVar1 < param_2 + (float)param_1[0x77]) {
    param_2 = fVar1 - (float)param_1[0x77];
  }
  fVar1 = ((float)(int)*(short *)(iVar2 + 0x26) * param_2) / fVar1 + (float)param_1[0xc];
  param_1[0xc] = (int)fVar1;
  if ((float)(int)*(short *)(iVar2 + 0x26) < fVar1) {
    param_1[0xc] = (int)(float)(int)*(short *)(iVar2 + 0x26);
  }
  fVar1 = (float)param_1[0x77];
  param_1[0x77] = (int)(param_2 + fVar1);
  if (param_2 + fVar1 < (float)(int)*(short *)(iVar2 + 0x15a)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x5c))(2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c9616
// Address: 004c9616
// XREFS: None
undefined4 __thiscall
FUN_004c9616(int param_1,short *param_2,short *param_3,short *param_4,char *param_5,short param_6)
{
  TRIBE_Action_Make_Obj *this;
  
  this = (TRIBE_Action_Make_Obj *)
         RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x184));
  if (this == (TRIBE_Action_Make_Obj *)0x0) {
    *param_2 = 0;
  }
  else {
    *param_2 = (short)this->_padding_;
  }
  if (*param_2 != 0x66) {
    if (*param_2 != 0x67) {
      *param_3 = -1;
      *param_4 = 0;
      if (param_5 != (char *)0x0) {
        *param_5 = '\0';
      }
      return 0;
    }
    TRIBE_Action_Make_Tech::get_info((TRIBE_Action_Make_Tech *)this,param_3,param_4,param_5,param_6)
    ;
    return 1;
  }
  TRIBE_Action_Make_Obj::get_info(this,param_3,param_4,param_5,param_6);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004c96b6
// Address: 004c96b6
// XREFS: None
undefined4 __fastcall FUN_004c96b6(int param_1)
{
  short sVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x48) != '\0') {
    return 100;
  }
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x15a);
  if (sVar1 == 0) {
    return 100;
  }
  uVar2 = __ftol((int)sVar1);
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_004c9701
// Address: 004c9701
// XREFS: None
void __thiscall FUN_004c9701(TRIBE_Building_Object *param_1,RGE_Master_Static_Object *param_2)
{
  if (param_1->_padding_ == *(int *)(param_1->_padding_ + 0x168)) {
    (**(code **)(param_1->_padding_ + 0x38))(param_2[1].outline_radius_y);
  }
  RGE_Combat_Object::copy_obj((RGE_Combat_Object *)param_1,param_2);
  if (*(char *)(param_1->_padding_ + 0x16c) != '\0') {
    TRIBE_Building_Object::connect(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c9755
// Address: 004c9755
// XREFS: None
void FUN_004c9755(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004c9763
// Address: 004c9763
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004c9763(RGE_Combat_Object *param_1,int param_2,RGE_Armor_Weapon_Info *param_3,float param_4,
            RGE_Player *param_5,RGE_Static_Object *param_6)
{
  short sVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)param_1->_padding_;
  if ((float)param_1->_padding_ <= _DAT_005749f4) {
    return;
  }
  RGE_Combat_Object::damage(param_1,param_2,param_3,param_4,param_5,param_6);
  sVar1 = param_6->master_obj->object_group;
  if ((((((sVar1 == 0) || (sVar1 == 0x17)) || (sVar1 == 0x24)) ||
       ((sVar1 == 0x1a || (sVar1 = param_6->master_obj->id, sVar1 == 0x4f)))) ||
      ((sVar1 == 0x45 || ((sVar1 == 199 || (sVar1 == 0x17f)))))) || (sVar1 == 0x17c)) {
    fVar3 = _DAT_00574a18;
    if ((float)_DAT_00574a10 <= fVar2 - (float)param_1->_padding_) goto LAB_004c9835;
  }
  else {
    fVar3 = _DAT_00574a08;
    if ((float)_DAT_00574a00 <= fVar2 - (float)param_1->_padding_) goto LAB_004c9835;
  }
  param_1->_padding_ = (int)(fVar2 - fVar3);
LAB_004c9835:
  if ((0 < *(short *)(param_1->_padding_ + 0x4a)) &&
     ((float)param_1->_padding_ < (float)_DAT_00574a00)) {
    (**(code **)(param_5->_padding_ + 0x78))(0x2b,0x3f800000,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c9866
// Address: 004c9866
// XREFS: None
short * __thiscall FUN_004c9866(TRIBE_Building_Object *param_1,undefined4 param_2,short param_3)
{
  ushort uVar1;
  bool bVar2;
  uchar uVar3;
  short *psVar4;
  Production_Queue_Record *pPVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  
  uVar1 = param_1->production_queue_count;
  psVar4 = (short *)(uint)uVar1;
  bVar2 = false;
  sVar10 = (short)param_2;
  if (((short)uVar1 < 1) || (param_1->production_queue[(short)uVar1 + -1].master_id != sVar10)) {
    while (0 < (short)uVar1) {
      TRIBE_Building_Object::remove_from_production_queue
                (param_1,param_1->production_queue->master_id,1);
      uVar1 = param_1->production_queue_count;
    }
    uVar3 = TRIBE_Player::check_obj_cost
                      ((TRIBE_Player *)param_1->_padding_,sVar10,(short *)&param_2,1.0,1);
    if (uVar3 == '\0') {
      psVar4 = (short *)(**(code **)(rge_base_game->_padding_ + 0x40))
                                  (0x7d,(int)*(short *)(param_1->_padding_ + 0x4a),
                                   (int)(short)param_2,0,0);
      return psVar4;
    }
    if (param_1->production_queue_count == param_1->production_queue_size) {
      pPVar5 = (Production_Queue_Record *)calloc(param_1->production_queue_size + 10,4);
      if (pPVar5 == (Production_Queue_Record *)0x0) {
        return (short *)0x0;
      }
      if (param_1->production_queue != (Production_Queue_Record *)0x0) {
        sVar6 = 0;
        if (0 < param_1->production_queue_size) {
          do {
            sVar7 = sVar6 + 1;
            pPVar5[sVar6].master_id = param_1->production_queue[sVar6].master_id;
            pPVar5[sVar6].unit_count = param_1->production_queue[sVar6].unit_count;
            sVar6 = sVar7;
          } while (sVar7 < param_1->production_queue_size);
        }
        free(param_1->production_queue);
      }
      param_1->production_queue_size = param_1->production_queue_size + 10;
      param_1->production_queue = pPVar5;
    }
    iVar9 = (int)param_3;
    iVar8 = 0;
    param_1->production_queue[param_1->production_queue_count].unit_count = 0;
    if (0 < iVar9) {
      do {
        uVar3 = TRIBE_Player::check_obj_cost
                          ((TRIBE_Player *)param_1->_padding_,sVar10,(short *)&param_2,1.0,1);
        if (uVar3 == '\0') {
          (**(code **)(rge_base_game->_padding_ + 0x40))
                    (0x7d,(int)*(short *)(param_1->_padding_ + 0x4a),(int)(short)param_2,0,0);
          break;
        }
        TRIBE_Player::pay_obj_cost((TRIBE_Player *)param_1->_padding_,sVar10,1.0,1);
        psVar4 = &param_1->production_queue[param_1->production_queue_count].unit_count;
        *psVar4 = *psVar4 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar9);
    }
    param_1->production_queue[param_1->production_queue_count].master_id = sVar10;
    param_1->production_queue_count = param_1->production_queue_count + 1;
    param_1->production_queue_change_flag = param_1->production_queue_change_flag + '\x01';
    psVar4 = (short *)(**(code **)(rge_base_game->_padding_ + 0x40))
                                (0x7c,(int)*(short *)(param_1->_padding_ + 0x4a),0,0,0);
  }
  else {
    iVar8 = (int)param_3;
    iVar9 = 0;
    if (0 < iVar8) {
      do {
        uVar3 = TRIBE_Player::check_obj_cost
                          ((TRIBE_Player *)param_1->_padding_,sVar10,(short *)&param_2,1.0,1);
        if (uVar3 == '\0') {
          psVar4 = (short *)(**(code **)(rge_base_game->_padding_ + 0x40))
                                      (0x7d,(int)*(short *)(param_1->_padding_ + 0x4a),
                                       (int)(short)param_2,0,0);
          break;
        }
        TRIBE_Player::pay_obj_cost((TRIBE_Player *)param_1->_padding_,sVar10,1.0,1);
        sVar6 = param_1->production_queue_count;
        pPVar5 = param_1->production_queue;
        psVar4 = &pPVar5[sVar6 + -1].unit_count;
        *psVar4 = *psVar4 + 1;
        iVar9 = iVar9 + 1;
        bVar2 = true;
        psVar4 = &pPVar5[sVar6 + -1].unit_count;
      } while (iVar9 < iVar8);
    }
    if (bVar2) {
      param_1->production_queue_change_flag = param_1->production_queue_change_flag + '\x01';
      psVar4 = (short *)(**(code **)(rge_base_game->_padding_ + 0x40))
                                  (0x7c,(int)*(short *)(param_1->_padding_ + 0x4a),0,0,0);
      return psVar4;
    }
  }
  return psVar4;
}

// --------------------------------------------------

// Function: FUN_004c9b0d
// Address: 004c9b0d
// XREFS: None
void __thiscall FUN_004c9b0d(int param_1,short param_2,short param_3)
{
  short *psVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  
  if (*(short *)(param_1 + 0x1ce) != 0) {
    sVar4 = *(short *)(param_1 + 0x1ce) + -1;
    if (-1 < sVar4) {
LAB_004c9b36:
      if (*(short *)(*(int *)(param_1 + 0x1c8) + sVar4 * 4) != param_2) goto code_r0x004c9b44;
      iVar6 = sVar4 * 4;
      sVar3 = *(short *)(*(int *)(param_1 + 0x1c8) + 2 + iVar6);
      sVar2 = param_3;
      if (sVar3 <= param_3) {
        sVar2 = sVar3;
      }
      iVar5 = (int)sVar2;
      if (0 < iVar5) {
        do {
          TRIBE_Player::reimburse_obj_cost(*(TRIBE_Player **)(param_1 + 0xc),param_2);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      psVar1 = (short *)(iVar6 + 2 + *(int *)(param_1 + 0x1c8));
      *psVar1 = *psVar1 - param_3;
      *(char *)(param_1 + 0x1d8) = *(char *)(param_1 + 0x1d8) + '\x01';
      if (*(short *)(iVar6 + 2 + *(int *)(param_1 + 0x1c8)) < 1) {
        *(short *)(param_1 + 0x1ce) = *(short *)(param_1 + 0x1ce) + -1;
        sVar3 = sVar4;
        if (sVar4 < *(short *)(param_1 + 0x1ce)) {
          do {
            iVar5 = (int)sVar3;
            sVar3 = sVar3 + 1;
            iVar6 = iVar5 * 4;
            *(undefined2 *)(iVar6 + *(int *)(param_1 + 0x1c8)) =
                 *(undefined2 *)(*(int *)(param_1 + 0x1c8) + 4 + iVar5 * 4);
            *(undefined2 *)(iVar6 + *(int *)(param_1 + 0x1c8) + 2) =
                 *(undefined2 *)(iVar6 + 6 + *(int *)(param_1 + 0x1c8));
          } while (sVar3 < *(short *)(param_1 + 0x1ce));
        }
        if (sVar4 == 0) {
          if (*(short *)(param_1 + 0x1da) != -1) {
            if (*(short *)(param_1 + 0x1da) == 4) {
              iVar6 = (int)*(short *)(*(int *)(param_1 + 0xc) + 0x4a);
              *(int *)(rge_base_game[1].save_music_file + iVar6 * 4 + -0x70) =
                   *(int *)(rge_base_game[1].save_music_file + iVar6 * 4 + -0x70) + -1;
            }
            *(undefined2 *)(param_1 + 0x1da) = 0xffff;
          }
          RGE_Action_List::action_stop(*(RGE_Action_List **)(param_1 + 0x1d4));
          RGE_Action_List::delete_list(*(RGE_Action_List **)(param_1 + 0x1d4));
        }
      }
    }
LAB_004c9c51:
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (0x7c,(int)*(short *)(*(int *)(param_1 + 0xc) + 0x4a),0,0,0);
  }
  return;
code_r0x004c9b44:
  sVar4 = sVar4 + -1;
  if (sVar4 < 0) goto LAB_004c9c51;
  goto LAB_004c9b36;
}

// --------------------------------------------------

// Function: FUN_004c9c73
// Address: 004c9c73
// XREFS: None
void __fastcall FUN_004c9c73(int param_1)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x1ce) != 0) {
    psVar1 = (short *)(*(int *)(param_1 + 0x1c8) + 2);
    *psVar1 = *psVar1 + -1;
    *(char *)(param_1 + 0x1d8) = *(char *)(param_1 + 0x1d8) + '\x01';
    if (*(short *)(*(int *)(param_1 + 0x1c8) + 2) < 1) {
      *(short *)(param_1 + 0x1ce) = *(short *)(param_1 + 0x1ce) + -1;
      iVar4 = 0;
      if (0 < *(short *)(param_1 + 0x1ce)) {
        do {
          *(undefined2 *)(*(int *)(param_1 + 0x1c8) + iVar4 * 4) =
               *(undefined2 *)(*(int *)(param_1 + 0x1c8) + 4 + iVar4 * 4);
          iVar3 = iVar4 * 4;
          iVar2 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined2 *)(*(int *)(param_1 + 0x1c8) + iVar2 + 2) =
               *(undefined2 *)(*(int *)(param_1 + 0x1c8) + 6 + iVar3);
        } while (iVar4 < *(short *)(param_1 + 0x1ce));
      }
    }
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (0x7c,(int)*(short *)(*(int *)(param_1 + 0xc) + 0x4a),0,0,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004c9d15
// Address: 004c9d15
// XREFS: None
void __fastcall FUN_004c9d15(int param_1)
{
  int iVar1;
  
  if (*(short *)(param_1 + 0x1da) != -1) {
    if (*(short *)(param_1 + 0x1da) == 4) {
      iVar1 = (int)*(short *)(*(int *)(param_1 + 0xc) + 0x4a);
      *(int *)(rge_base_game[1].save_music_file + iVar1 * 4 + -0x70) =
           *(int *)(rge_base_game[1].save_music_file + iVar1 * 4 + -0x70) + -1;
    }
    *(undefined2 *)(param_1 + 0x1da) = 0xffff;
  }
  *(undefined2 *)(param_1 + 0x1ce) = 0;
  RGE_Action_List::delete_list(*(RGE_Action_List **)(param_1 + 0x1d4));
  *(char *)(param_1 + 0x1d8) = *(char *)(param_1 + 0x1d8) + '\x01';
  return;
}

// --------------------------------------------------

// Function: FUN_004c9d81
// Address: 004c9d81
// XREFS: None
void __thiscall FUN_004c9d81(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x1d0) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004c9d9d
// Address: 004c9d9d
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c9d9d(TRIBE_Building_Object *param_1)
{
  int iVar1;
  char cVar2;
  int iVar3;
  RGE_Action *pRVar4;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  short sStack_16;
  short sStack_14;
  short sStack_12;
  TRIBE_Action_Make_Obj *pTStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fafb;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_1->production_queue_enabled == '\0') || (param_1->production_queue_count == 0)) {
    if (param_1->production_queue_need_attr == 4) {
      param_1->production_queue_need_attr = -1;
      iVar3 = (int)*(short *)(param_1->_padding_ + 0x4a);
      *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) =
           *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) + -1;
    }
  }
  else {
    iVar3 = TRIBE_Building_Object::work_status
                      (param_1,&sStack_16,&sStack_12,&sStack_14,(char *)0x0,0);
    if ((iVar3 == 0) || ((sStack_16 != 0x66 && (sStack_16 != 0x67)))) {
      if (param_1->production_queue_actions->list == (RGE_Action_Node *)0x0) {
        iVar3 = param_1->_padding_;
        iVar1 = *(int *)(iVar3 + 0x50);
        if (*(float *)(iVar1 + 0x80) <= *(float *)(iVar1 + 0x2c)) {
          if (param_1->production_queue_need_attr != 0x20) {
            param_1->production_queue_need_attr = 0x20;
            (**(code **)(rge_base_game->_padding_ + 0x40))
                      (0x7d,(int)*(short *)(iVar3 + 0x4a),0x20,0,0);
            iVar3 = (int)*(short *)(param_1->_padding_ + 0x4a);
            *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) =
                 *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) + 1;
            *unaff_FS_OFFSET = unaff_EDI;
            return;
          }
          goto LAB_004c9fc1;
        }
        if (*(float *)(iVar1 + 0x10) <= _DAT_005749f4) {
          if (param_1->production_queue_need_attr != 4) {
            param_1->production_queue_need_attr = 4;
            (**(code **)(rge_base_game->_padding_ + 0x40))(0x7d,(int)*(short *)(iVar3 + 0x4a),4,0,0)
            ;
            iVar3 = (int)*(short *)(param_1->_padding_ + 0x4a);
            *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) =
                 *(int *)(rge_base_game[1].save_music_file + iVar3 * 4 + -0x70) + 1;
            *unaff_FS_OFFSET = unaff_EDI;
            return;
          }
          goto LAB_004c9fc1;
        }
        if (param_1->production_queue_need_attr == 4) {
          *(int *)(rge_base_game[1].save_music_file + *(short *)(iVar3 + 0x4a) * 4 + -0x70) =
               *(int *)(rge_base_game[1].save_music_file + *(short *)(iVar3 + 0x4a) * 4 + -0x70) +
               -1;
        }
        param_1->production_queue_need_attr = -1;
        pTStack_10 = (TRIBE_Action_Make_Obj *)operator_new(0x50);
        uStack_4 = 0;
        if (pTStack_10 == (TRIBE_Action_Make_Obj *)0x0) {
          pRVar4 = (RGE_Action *)0x0;
        }
        else {
          pRVar4 = (RGE_Action *)
                   TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj
                             (pTStack_10,(RGE_Action_Object *)param_1,
                              param_1->production_queue->master_id,-1,'\x01');
        }
        uStack_4 = 0xffffffff;
        if (pRVar4 != (RGE_Action *)0x0) {
          RGE_Action_List::add_action(param_1->production_queue_actions,pRVar4);
        }
      }
      cVar2 = (**(code **)(param_1->production_queue_actions->_padding_ + 0xc))();
      if (((cVar2 == '\x03') || (cVar2 == '\x02')) || (cVar2 == '\x01')) {
        RGE_Action_List::remove_action(param_1->production_queue_actions);
        TRIBE_Building_Object::advance_production_queue(param_1);
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
    }
    else if (0 < param_1->production_queue_count) {
      do {
        TRIBE_Building_Object::remove_from_production_queue
                  (param_1,param_1->production_queue->master_id,-1);
      } while (0 < param_1->production_queue_count);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
  }
LAB_004c9fc1:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004ca02c
// Address: 004ca02c
// XREFS: None
undefined4 __thiscall FUN_004ca02c(int param_1,short *param_2,short *param_3)
{
  TRIBE_Action_Make_Obj *this;
  
  *param_2 = -1;
  *param_3 = 0;
  this = (TRIBE_Action_Make_Obj *)
         RGE_Action_List::get_action(*(RGE_Action_List **)(param_1 + 0x1d4));
  if ((this != (TRIBE_Action_Make_Obj *)0x0) && ((short)this->_padding_ == 0x66)) {
    TRIBE_Action_Make_Obj::get_info(this,param_2,param_3,(char *)0x0,0);
    return 1;
  }
  if (0 < *(short *)(param_1 + 0x1ce)) {
    *param_2 = **(short **)(param_1 + 0x1c8);
    *param_3 = 0;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ca0a3
// Address: 004ca0a3
// XREFS: None
void __fastcall FUN_004ca0a3(TRIBE_Building_Object *param_1)
{
  short sVar1;
  
  RGE_Combat_Object::stop((RGE_Combat_Object *)param_1);
  sVar1 = param_1->production_queue_count;
  while (0 < sVar1) {
    TRIBE_Building_Object::remove_from_production_queue
              (param_1,param_1->production_queue->master_id,1);
    sVar1 = param_1->production_queue_count;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ca0e1
// Address: 004ca0e1
// XREFS: None
TRIBE_Combat_Object * __thiscall
FUN_004ca0e1(TRIBE_Combat_Object *param_1,TRIBE_Master_Combat_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fb18;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Combat_Object::RGE_Combat_Object
            ((RGE_Combat_Object *)param_1,(RGE_Master_Combat_Object *)param_2,param_3,param_4,
             param_5,param_6,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Combat_Object::_vftable_;
  if (param_7 != 0) {
    TRIBE_Combat_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ca173
// Address: 004ca173
// XREFS: None
TRIBE_Combat_Object * __thiscall FUN_004ca173(TRIBE_Combat_Object *param_1,byte param_2)
{
  TRIBE_Combat_Object::~TRIBE_Combat_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ca19e
// Address: 004ca19e
// XREFS: None
TRIBE_Combat_Object * __thiscall
FUN_004ca19e(TRIBE_Combat_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fb38;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Combat_Object::RGE_Combat_Object((RGE_Combat_Object *)param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Combat_Object::_vftable_;
  if (param_4 != 0) {
    TRIBE_Combat_Object::setup(param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ca205
// Address: 004ca205
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ca205(RGE_Combat_Object *param_1)
{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055fb58;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Combat_Object::_vftable_;
  uStack_4 = 0;
  if ((char)param_1[1]._padding_ != '\0') {
    puVar2 = (undefined4 *)param_1->_padding_;
    sVar1 = *(short *)(puVar2 + 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    param_1->_padding_ = *(int *)(*(int *)(param_1->_padding_ + 0x24) + sVar1 * 4);
  }
  iVar3 = param_1->_padding_;
  sVar1 = *(short *)(iVar3 + 0x14);
  if (((sVar1 == 4) || (sVar1 == 0x15)) || (sVar1 == 2)) {
    iVar3 = *(int *)(param_1->_padding_ + 0x50);
    *(float *)(iVar3 + 0x94) = *(float *)(iVar3 + 0x94) - _DAT_00574c78;
  }
  else if (((sVar1 != 0x12) && (*(char *)(iVar3 + 4) == 'F')) ||
          ((sVar1 = *(short *)(iVar3 + 0x10), sVar1 == 0x4f || ((sVar1 == 0x45 || (sVar1 == 199)))))
          ) {
    iVar3 = *(int *)(param_1->_padding_ + 0x50);
    *(float *)(iVar3 + 0xa0) = *(float *)(iVar3 + 0xa0) - _DAT_00574c78;
  }
  uStack_4 = 0xffffffff;
  RGE_Combat_Object::~RGE_Combat_Object(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004ca2f1
// Address: 004ca2f1
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004ca2f1(RGE_Combat_Object *param_1,RGE_Master_Combat_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  short sVar1;
  int iVar2;
  
  RGE_Combat_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  if (*(short *)(param_1->_padding_ + 0x4a) == 0) {
    param_1->capture_flag = '\x01';
  }
  iVar2 = param_1->_padding_;
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x46;
  (**(code **)(iVar2 + 0x250))();
  iVar2 = param_1->_padding_;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  sVar1 = *(short *)(iVar2 + 0x14);
  if (((sVar1 == 4) || (sVar1 == 0x15)) || (sVar1 == 2)) {
    iVar2 = *(int *)(param_1->_padding_ + 0x50);
    *(float *)(iVar2 + 0x94) = *(float *)(iVar2 + 0x94) - _DAT_00574c7c;
  }
  else if (((sVar1 != 0x12) && (*(char *)(iVar2 + 4) == 'F')) ||
          ((sVar1 = *(short *)(iVar2 + 0x10), sVar1 == 0x4f || ((sVar1 == 0x45 || (sVar1 == 199)))))
          ) {
    iVar2 = *(int *)(param_1->_padding_ + 0x50);
    *(float *)(iVar2 + 0xa0) = *(float *)(iVar2 + 0xa0) - _DAT_00574c7c;
  }
  if (*(short *)(param_1->_padding_ + 0x14) == 0x12) {
    param_1->_padding_ = 0x42c80000;
    *(undefined2 *)&param_1->_padding_ = 0x22;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004ca3d7
// Address: 004ca3d7
// XREFS: None
undefined4 __thiscall FUN_004ca3d7(RGE_Combat_Object *param_1,int param_2,RGE_Game_World *param_3)
{
  int iVar1;
  TRIBE_Master_Combat_Object *this;
  int iVar2;
  TRIBE_Master_Building_Object *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fb86;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Combat_Object::setup(param_1,param_2,param_3);
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x46;
  rge_read(iVar1,param_1 + 1,1);
  if ((char)param_1[1]._padding_ == '\0') goto LAB_004ca4c1;
  rge_read(iVar1,&param_3,1);
  if ((char)param_3 == 'F') {
    this = (TRIBE_Master_Combat_Object *)operator_new(0x164);
    uStack_4 = 0;
    if (this == (TRIBE_Master_Combat_Object *)0x0) {
LAB_004ca4b4:
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1->_padding_ + 0x3c);
      iVar2 = TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
                        (this,iVar1,*(RGE_Sprite ***)(iVar2 + 0x38),*(RGE_Sound ***)(iVar2 + 0x30),1
                        );
    }
  }
  else {
    if ((char)param_3 != 'P') goto LAB_004ca4c1;
    this_00 = (TRIBE_Master_Building_Object *)operator_new(0x17c);
    uStack_4 = 1;
    if (this_00 == (TRIBE_Master_Building_Object *)0x0) goto LAB_004ca4b4;
    iVar2 = *(int *)(param_1->_padding_ + 0x3c);
    iVar2 = TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
                      (this_00,iVar1,*(RGE_Sprite ***)(iVar2 + 0x38),*(RGE_Sound ***)(iVar2 + 0x30),
                       1);
  }
  uStack_4 = 0xffffffff;
  param_1->_padding_ = iVar2;
LAB_004ca4c1:
  rge_read(iVar1,&param_2,4);
  if (param_2 == 1) {
    (**(code **)(param_1->_padding_ + 0x250))();
    if ((int *)param_1->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1->_padding_ + 8))(iVar1);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004ca50c
// Address: 004ca50c
// XREFS: None
undefined4 __fastcall FUN_004ca50c(RGE_Action_Object *param_1)
{
  TRIBE_Action_List *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fb9b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (TRIBE_Action_List *)operator_new(0xc);
  uStack_4 = 0;
  if (this != (TRIBE_Action_List *)0x0) {
    uVar1 = TRIBE_Action_List::TRIBE_Action_List(this,param_1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ca56d
// Address: 004ca56d
// XREFS: None
void __thiscall FUN_004ca56d(RGE_Combat_Object *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = param_2;
  RGE_Combat_Object::save(param_1,param_2);
  rge_write(iVar1,param_1 + 1,1);
  if ((char)param_1[1]._padding_ != '\0') {
    (**(code **)(*(int *)param_1->_padding_ + 0x14))(iVar1);
  }
  if (param_1->_padding_ != 0) {
    param_2 = 1;
    rge_write(iVar1,&param_2,4);
    (**(code **)(*(int *)param_1->_padding_ + 4))(iVar1);
    return;
  }
  param_2 = 0;
  rge_write(iVar1,&param_2,4);
  return;
}

// --------------------------------------------------

// Function: FUN_004ca5ec
// Address: 004ca5ec
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ca5ec(RGE_Combat_Object *param_1)
{
  bool bVar1;
  float fVar2;
  
  if ((*(short *)(param_1->_padding_ + 0x14) == 0x12) && ((char)param_1->_padding_ == '\x02')) {
    fVar2 = *(float *)(*(int *)(param_1->_padding_ + 0x50) + 0x8c) *
            *(float *)(*(int *)(param_1->_padding_ + 0x3c) + 0x84) + (float)param_1->_padding_;
    bVar1 = _DAT_00574c80 <= fVar2;
    param_1->_padding_ = (int)fVar2;
    if (bVar1) {
      param_1->_padding_ = 0x42c80000;
    }
    *(undefined2 *)&param_1->_padding_ = 0x22;
  }
  RGE_Combat_Object::update(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004ca63a
// Address: 004ca63a
// XREFS: None
void __thiscall FUN_004ca63a(RGE_Static_Object *param_1,float param_2,uchar param_3)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 == 'e') {
    iVar3 = 0x70;
    iVar2 = 0x6a;
    do {
      if (*(short *)((int)param_1->master_obj->attribute_type_held + iVar2 + -0x6a) == 4) {
        pfVar1 = param_1->owner->attributes;
        pfVar1[4] = pfVar1[4] -
                    *(float *)((int)param_1->master_obj->attribute_type_held + iVar3 + -0x6a);
        pfVar1 = param_1->owner->attributes;
        pfVar1[4] = param_2 + pfVar1[4];
      }
      if (*(short *)((int)param_1->master_obj->attribute_type_held + iVar2 + -0x6a) == 0xb) {
        pfVar1 = param_1->owner->attributes;
        pfVar1[0xb] = pfVar1[0xb] -
                      *(float *)((int)param_1->master_obj->attribute_type_held + iVar3 + -0x6a);
        pfVar1 = param_1->owner->attributes;
        pfVar1[0xb] = pfVar1[0xb] - param_2;
      }
      if (*(short *)((int)param_1->master_obj->attribute_type_held + iVar2 + -0x6a) == 0x13) {
        pfVar1 = param_1->owner->attributes;
        pfVar1[0x13] = pfVar1[0x13] -
                       *(float *)((int)param_1->master_obj->attribute_type_held + iVar3 + -0x6a);
        pfVar1 = param_1->owner->attributes;
        pfVar1[0x13] = pfVar1[0x13] - param_2;
      }
      iVar2 = iVar2 + 2;
      iVar3 = iVar3 + 4;
    } while (iVar2 < 0x70);
  }
  RGE_Static_Object::modify(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004ca6f5
// Address: 004ca6f5
// XREFS: None
void __thiscall FUN_004ca6f5(RGE_Action_Object *param_1,RGE_Master_Static_Object *param_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1->_padding_;
  RGE_Action_Object::transform(param_1,param_2);
  if ((char)param_1[1]._padding_ == '\x01') {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    *(undefined1 *)&param_1[1]._padding_ = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ca732
// Address: 004ca732
// XREFS: None
void __thiscall FUN_004ca732(TRIBE_Combat_Object *param_1,byte param_2)
{
  if ((((*(char *)(*(int *)(param_1->_padding_ + 0x3c) + 0x1d) == '\0') && (2 < param_2)) &&
      ((byte)param_1->_padding_ < 3)) && (*(short *)(param_1->_padding_ + 0x14) == 1)) {
    TRIBE_Combat_Object::reposition_artifact(param_1);
    return;
  }
  RGE_Static_Object::set_object_state((RGE_Static_Object *)param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004ca776
// Address: 004ca776
// XREFS: None
void __fastcall FUN_004ca776(int *param_1)
{
                    /* WARNING: Could not recover jumptable at 0x004ca782. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x6c))();
  return;
}

// --------------------------------------------------

// Function: FUN_004ca785
// Address: 004ca785
// XREFS: None
// [HELPER] die_die_die: " "
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ca785(RGE_Static_Object *param_1)
{
  short sVar1;
  TRIBE_Action_Convert *this;
  
  if ((param_1->object_state == '\x02') && (_DAT_00574c78 <= param_1->owner->attributes[0x39])) {
    this = (TRIBE_Action_Convert *)
           RGE_Action_List::get_action((RGE_Action_List *)param_1[2].unitAIValue);
    if (this != (TRIBE_Action_Convert *)0x0) {
      sVar1 = (**(code **)(this->_padding_ + 0x18))();
      if (sVar1 == 0x68) {
        TRIBE_Action_Convert::martyrdom(this);
      }
    }
  }
  RGE_Static_Object::die_die_die(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004ca7e2
// Address: 004ca7e2
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004ca7e2(RGE_Combat_Object *param_1,int param_2,RGE_Armor_Weapon_Info *param_3,float param_4,
            RGE_Player *param_5,RGE_Static_Object *param_6)
{
  float fVar1;
  int iVar2;
  char cVar3;
  
  fVar1 = (float)param_1->_padding_;
  if ((float)_DAT_00574c88 <= (float)param_1->_padding_) {
    RGE_Combat_Object::damage(param_1,param_2,param_3,param_4,param_5,param_6);
    if ((float)param_1->_padding_ < (float)_DAT_00574c88) {
      iVar2 = param_1->_padding_;
      cVar3 = (**(code **)(iVar2 + 0x13c))((int)param_6->master_obj->object_group);
      if (cVar3 == '\0') {
        (**(code **)(iVar2 + 0x84))(0,0,1);
      }
    }
    if (fVar1 - (float)param_1->_padding_ < (float)_DAT_00574c88) {
      param_1->_padding_ = (int)(fVar1 - _DAT_00574c78);
    }
    if ((0 < *(short *)(param_1->_padding_ + 0x4a)) && ((float)param_1->_padding_ < _DAT_00574c78))
{
      (**(code **)(param_5->_padding_ + 0x78))(0x14,0x3f800000,0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ca8ba
// Address: 004ca8ba
// XREFS: None
void __thiscall FUN_004ca8ba(RGE_Action_Object *param_1,RGE_Player *param_2)
{
  RGE_Action_Object *pRVar1;
  int iVar2;
  
  if (-1 < param_1->_padding_) {
    pRVar1 = param_1 + 1;
    iVar2 = 9;
    do {
      if (pRVar1->_padding_ != 0) {
        *(char *)(pRVar1->_padding_ + 5) = (char)param_2->id;
      }
      pRVar1 = (RGE_Action_Object *)&pRVar1->_padding_;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (*(short *)(param_1->_padding_ + 0x14) == 1) {
    RGE_Action_Object::change_ownership(param_1,param_2);
    return;
  }
  if (param_2->master_objects[*(short *)(param_1->_padding_ + 0x10)] !=
      (RGE_Master_Static_Object *)0x0) {
    if ((param_1->_padding_ & 0x10000) != 0) {
      RGE_Player::unselect_one_object((RGE_Player *)param_1->_padding_,(RGE_Static_Object *)param_1)
      ;
    }
    RGE_Static_Object::take_attribute_from_owner((RGE_Static_Object *)param_1);
    (**(code **)(*(int *)param_1->_padding_ + 0xe0))
              (param_1,*(undefined1 *)((int)&param_1->_padding_ + 1),
               *(undefined1 *)((int)&param_1->_padding_ + 2),param_1->_padding_);
    iVar2 = (**(code **)(param_2->_padding_ + 0xdc))
                      (param_1,*(undefined1 *)((int)&param_1->_padding_ + 1),
                       *(undefined1 *)((int)&param_1->_padding_ + 2));
    param_1->_padding_ = iVar2;
    if ((char)param_1->_padding_ == '\x02') {
      (**(code **)(param_1->_padding_ + 0xdc))(param_1->_padding_,0,0xffffffff);
    }
    iVar2 = param_1[1]._padding_;
    param_1->_padding_ = (int)param_2;
    if ((char)iVar2 == '\0') {
      iVar2 = (**(code **)(*(int *)param_1->_padding_ + 0x1c))();
      param_1->_padding_ = iVar2;
      *(undefined1 *)&param_1[1]._padding_ = 1;
    }
    if ((char)param_1->_padding_ == '\x02') {
      (**(code **)(param_1->_padding_ + 0xd8))(param_1->_padding_,0,0xffffffff);
    }
    RGE_Static_Object::give_attribute_to_owner((RGE_Static_Object *)param_1);
    if ((UnitAIModule *)param_1->_padding_ != (UnitAIModule *)0x0) {
      UnitAIModule::purgeNotifyQueue
                ((UnitAIModule *)param_1->_padding_,
                 *(ulong *)(*(int *)(param_1->_padding_ + 0x3c) + 4));
    }
    (**(code **)(param_1->_padding_ + 0x148))
              (param_1->_padding_,param_1->_padding_,0x20b,(int)param_2->id,0,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ca9f2
// Address: 004ca9f2
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004ca9f2(int *param_1,int param_2)
{
  int iVar1;
  
  if (*(short *)(param_1[2] + 0x124) < 0) {
    if ((float)param_1[0x10] < *(float *)(param_2 + 0x40)) {
      return (float10)_DAT_00574c94;
    }
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x24c))(param_2);
    if (iVar1 != 0) {
      return (float10)_DAT_00574c90;
    }
  }
  return (float10)_DAT_00574c78;
}

// --------------------------------------------------

// Function: FUN_004caa4a
// Address: 004caa4a
// XREFS: None
void __thiscall
FUN_004caa4a(RGE_Combat_Object *param_1,RGE_Static_Object *param_2,RGE_Combat_Object *param_3)
{
  if (((-1 < *(short *)(param_1->_padding_ + 0x124)) && (param_2 != (RGE_Static_Object *)0x0)) &&
     (0 < param_2->owner->id)) {
    (**(code **)(param_2->owner->_padding_ + 0x94))
              (0x70,param_1->_padding_,param_1->_padding_,param_1->_padding_,0);
  }
  RGE_Combat_Object::attack(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_004caa9d
// Address: 004caa9d
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_t_c_obj_cp: "C:\msdev\work\age1_x1\t_c_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uchar __thiscall
FUN_004caa9d(RGE_Combat_Object *param_1,RGE_Static_Object *param_2,RGE_Combat_Object *param_3,
            float param_4,float param_5,float param_6)
{
  short sVar1;
  int iVar2;
  uchar uVar3;
  int iVar4;
  float10 fVar5;
  
  if (param_2 == (RGE_Static_Object *)0x0) {
    return '\0';
  }
  if ((rge_base_game->quick_build != 0) &&
     ((sVar1 = *(short *)(param_1->_padding_ + 0x10), sVar1 == 0x7a || (sVar1 == 0x7b)))) {
    (**(code **)(param_1->_padding_ + 0x148))
              (param_1->_padding_,param_1->_padding_,0x200,600,param_2->id,0);
    (**(code **)(param_2->_padding_ + 0x6c))();
    return '\x01';
  }
  if ((_DAT_00574c98 < *(float *)(param_1->_padding_ + 0x118)) &&
     (*(float *)(param_1->_padding_ + 0x114) < _DAT_00574c9c)) {
    iVar2 = param_1->_padding_;
    (**(code **)(iVar2 + 0x21c))(param_4,param_5,param_6,param_3,param_2);
    (**(code **)(iVar2 + 0x148))(param_1->_padding_,param_1->_padding_,0x200,600,param_2->id,0);
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_t_c_obj_cp,0x211);
    if ((iVar4 * 100) / 0x7fff <= (int)*(short *)(param_1->_padding_ + 0x126)) {
      fVar5 = (float10)(**(code **)(iVar2 + 0xf0))(param_2);
      (**(code **)(param_2->_padding_ + 0x70))
                ((int)*(short *)(param_1->_padding_ + 0x108),
                 *(undefined4 *)(param_1->_padding_ + 0x10c),(float)fVar5,param_1->_padding_,param_3
                );
    }
    return '\x01';
  }
  uVar3 = RGE_Combat_Object::do_attack(param_1,param_2,param_3,param_4,param_5,param_6);
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_004cac0d
// Address: 004cac0d
// XREFS: None
void __thiscall FUN_004cac0d(int param_1,ushort *param_2,undefined2 *param_3)
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  *param_2 = (ushort)*(byte *)(*(int *)(param_1 + 8) + 0x100);
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = 0;
  if (0 < *(short *)(iVar2 + 0x102)) {
    do {
      if ((*(short *)(*(int *)(iVar2 + 0x104) + iVar3 * 4) == 4) &&
         (uVar1 = *(ushort *)(*(int *)(iVar2 + 0x104) + iVar3 * 4 + 2),
         (short)*param_2 < (short)uVar1)) {
        *param_2 = uVar1;
      }
      iVar2 = *(int *)(param_1 + 8);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(iVar2 + 0x102));
  }
  *param_3 = *(undefined2 *)(*(int *)(param_1 + 8) + 0x13c);
  return;
}

// --------------------------------------------------

// Function: FUN_004cac73
// Address: 004cac73
// XREFS: None
void __thiscall FUN_004cac73(int param_1,short *param_2,undefined2 *param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  *param_2 = 0;
  iVar2 = *(int *)(param_1 + 8);
  if (0 < *(short *)(iVar2 + 0x102)) {
    do {
      if ((*(short *)(*(int *)(iVar2 + 0x104) + iVar3 * 4) == 3) &&
         (sVar1 = *(short *)(*(int *)(iVar2 + 0x104) + iVar3 * 4 + 2), *param_2 < sVar1)) {
        *param_2 = sVar1;
      }
      iVar2 = *(int *)(param_1 + 8);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(iVar2 + 0x102));
  }
  *param_3 = *(undefined2 *)(*(int *)(param_1 + 8) + 0x160);
  return;
}

// --------------------------------------------------

// Function: FUN_004cacda
// Address: 004cacda
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004cacda(RGE_Static_Object *param_1)
{
  RGE_Static_Object *pRVar1;
  RGE_Map *this;
  bool bVar2;
  int iVar3;
  uchar uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  float fStack_28;
  float fStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  pRVar1 = param_1->inside_obj;
  if (pRVar1 == (RGE_Static_Object *)0x0) {
    iStack_18 = __ftol();
    iStack_14 = __ftol();
    fStack_24 = param_1->world_x;
    fStack_28 = param_1->world_y;
  }
  else {
    iStack_18 = __ftol();
    iStack_14 = __ftol();
    fStack_28 = pRVar1->world_y;
    fStack_24 = pRVar1->world_x;
  }
  iStack_1c = iStack_18;
  bVar2 = false;
  this = param_1->owner->world->map;
  iVar6 = this->map_width + -1;
  iVar7 = this->map_height + -1;
  iVar3 = iStack_18;
  iStack_20 = iStack_14;
  do {
    for (; iVar3 <= iStack_1c; iVar3 = iVar3 + 1) {
      uVar4 = RGE_Map::get_terrain(this,(short)iVar3,(short)iStack_20);
      if ((uVar4 != '\x01') && (uVar4 != '\x02')) {
        fStack_24 = (float)iVar3 - _DAT_00574ca0;
        fStack_28 = (float)iStack_20 - _DAT_00574ca0;
        cVar5 = (**(code **)(param_1->master_obj->_padding_ + 0x20))
                          (param_1->owner,fStack_24,fStack_28,0,1,1,1,0,1,1);
        if (cVar5 != '\0') goto LAB_004cade0;
LAB_004cae4c:
        bVar2 = true;
        break;
      }
LAB_004cade0:
      uVar4 = RGE_Map::get_terrain(this,(short)iVar3,(short)iStack_14);
      if ((uVar4 != '\x01') && (uVar4 != '\x02')) {
        fStack_24 = (float)iVar3 - _DAT_00574ca0;
        fStack_28 = (float)iStack_14 - _DAT_00574ca0;
        cVar5 = (**(code **)(param_1->master_obj->_padding_ + 0x20))
                          (param_1->owner,fStack_24,fStack_28,0,1,1,1,0,1,1);
        if (cVar5 == '\0') goto LAB_004cae4c;
      }
    }
    if (bVar2) goto LAB_004cafd9;
    iVar3 = iStack_20;
    do {
      do {
        iVar3 = iVar3 + 1;
        if (iStack_14 + -1 < iVar3) goto LAB_004caf3f;
        uVar4 = RGE_Map::get_terrain(this,(short)iStack_18,(short)iVar3);
        if ((uVar4 != '\x01') && (uVar4 != '\x02')) {
          fStack_24 = (float)iStack_18 - _DAT_00574ca0;
          fStack_28 = (float)iVar3 - _DAT_00574ca0;
          cVar5 = (**(code **)(param_1->master_obj->_padding_ + 0x20))
                            (param_1->owner,fStack_24,fStack_28,0,1,1,1,0,1,1);
          if (cVar5 == '\0') goto LAB_004caf37;
        }
        uVar4 = RGE_Map::get_terrain(this,(short)iStack_1c,(short)iVar3);
      } while ((uVar4 == '\x01') || (uVar4 == '\x02'));
      fStack_24 = (float)iStack_1c - _DAT_00574ca0;
      fStack_28 = (float)iVar3 - _DAT_00574ca0;
      cVar5 = (**(code **)(param_1->master_obj->_padding_ + 0x20))
                        (param_1->owner,fStack_24,fStack_28,0,0,1,1,0,1,1);
    } while (cVar5 != '\0');
LAB_004caf37:
    bVar2 = true;
LAB_004caf3f:
    if (bVar2) goto LAB_004cafd9;
    if ((((iStack_18 == 0) && (iStack_1c == iVar6)) && (iStack_20 == 0)) && (iStack_14 == iVar7)) {
      pRVar1 = param_1->inside_obj;
      if (pRVar1 == (RGE_Static_Object *)0x0) {
        fStack_24 = param_1->world_x;
        fStack_28 = param_1->world_y;
      }
      else {
        fStack_24 = pRVar1->world_x;
        fStack_28 = pRVar1->world_y;
      }
LAB_004cafd9:
      RGE_Static_Object::set_location(param_1,fStack_24,fStack_28,param_1->world_z);
      if (param_1->inside_obj != (RGE_Static_Object *)0x0) {
        (**(code **)(param_1->_padding_ + 0xd4))();
      }
      iVar3 = param_1->_padding_;
      (**(code **)(iVar3 + 0x34))(fStack_24,fStack_28,param_1->world_z);
      (**(code **)(iVar3 + 0x44))(*param_1->owner->world->players);
      (**(code **)(iVar3 + 0x9c))(0,fStack_24,fStack_28,param_1->world_z);
      param_1->hp = 1.0;
      return;
    }
    if (0 < iStack_18) {
      iStack_18 = iStack_18 + -1;
    }
    if (0 < iStack_20) {
      iStack_20 = iStack_20 + -1;
    }
    if (iStack_1c < iVar6) {
      iStack_1c = iStack_1c + 1;
    }
    iVar3 = iStack_18;
    if (iStack_14 < iVar7) {
      iStack_14 = iStack_14 + 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004cb03e
// Address: 004cb03e
// XREFS: None
bool __fastcall FUN_004cb03e(int param_1)
{
  if (*(char *)(*(int *)(param_1 + 8) + 0x8f) != '\a') {
    return false;
  }
  return *(short *)(*(int *)(param_1 + 0x24) + 8) != 0;
}

// --------------------------------------------------

// Function: FUN_004cb05c
// Address: 004cb05c
// XREFS: None
RGE_Static_Object * __thiscall FUN_004cb05c(RGE_Action_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Hunt *this;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fbbb;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb196;
  if (param_3 == 0) {
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 != '\x01') goto LAB_004cb0de;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb0de;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x6e) goto LAB_004cb0de;
  }
  else {
LAB_004cb0de:
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action(param_1->actions);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x6e) {
        pRVar5 = RGE_Action_List::get_action(param_1->actions);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb191;
      }
    }
    iVar1 = param_1->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb196;
    this = (TRIBE_Action_Hunt *)operator_new(0x44);
    uStack_4 = 0;
    if (this == (TRIBE_Action_Hunt *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Hunt::TRIBE_Action_Hunt(this,param_1,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb196;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb191:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb196:
  *unaff_FS_OFFSET = uStack_c;
  return pRVar6;
}

// --------------------------------------------------

// Function: FUN_004cb1ab
// Address: 004cb1ab
// XREFS: None
RGE_Static_Object * __thiscall FUN_004cb1ab(RGE_Action_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Convert *this;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fbdb;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb2e6;
  if (param_3 == 0) {
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 != '\x01') goto LAB_004cb22e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb22e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x68) goto LAB_004cb22e;
  }
  else {
LAB_004cb22e:
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action(param_1->actions);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x68) {
        pRVar5 = RGE_Action_List::get_action(param_1->actions);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb2e1;
      }
    }
    iVar1 = param_1->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb2e6;
    this = (TRIBE_Action_Convert *)operator_new(0x48);
    uStack_4 = 0;
    if (this == (TRIBE_Action_Convert *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Convert::TRIBE_Action_Convert(this,param_1,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb2e6;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb2e1:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb2e6:
  *unaff_FS_OFFSET = uStack_c;
  return pRVar6;
}

// --------------------------------------------------

// Function: FUN_004cb2fb
// Address: 004cb2fb
// XREFS: None
RGE_Static_Object * __thiscall FUN_004cb2fb(RGE_Action_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Heal *this;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fbfb;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb436;
  if (param_3 == 0) {
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 != '\x01') goto LAB_004cb37e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb37e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x69) goto LAB_004cb37e;
  }
  else {
LAB_004cb37e:
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action(param_1->actions);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x69) {
        pRVar5 = RGE_Action_List::get_action(param_1->actions);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb431;
      }
    }
    iVar1 = param_1->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb436;
    this = (TRIBE_Action_Heal *)operator_new(0x40);
    uStack_4 = 0;
    if (this == (TRIBE_Action_Heal *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Heal::TRIBE_Action_Heal(this,param_1,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb436;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb431:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb436:
  *unaff_FS_OFFSET = uStack_c;
  return pRVar6;
}

// --------------------------------------------------

// Function: FUN_004cb44b
// Address: 004cb44b
// XREFS: None
RGE_Static_Object * __thiscall FUN_004cb44b(RGE_Action_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Repair *this;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fc1b;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb5a1;
  if (param_3 == 0) {
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 != '\x01') goto LAB_004cb4ce;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb4ce;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x6a) goto LAB_004cb4ce;
  }
  else {
LAB_004cb4ce:
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action(param_1->actions);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x6a) {
        pRVar5 = RGE_Action_List::get_action(param_1->actions);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb59c;
      }
    }
    iVar1 = *(int *)(*(int *)(param_1->_padding_ + 0x24) + 0x270);
    if (iVar1 != 0) {
      (**(code **)(param_1->_padding_ + 0x54))(iVar1);
    }
    iVar1 = param_1->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb5a1;
    this = (TRIBE_Action_Repair *)operator_new(0x44);
    uStack_4 = 0;
    if (this == (TRIBE_Action_Repair *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Repair::TRIBE_Action_Repair(this,param_1,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb5a1;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb59c:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb5a1:
  *unaff_FS_OFFSET = uStack_c;
  return pRVar6;
}

// --------------------------------------------------

// Function: FUN_004cb5b6
// Address: 004cb5b6
// XREFS: None
RGE_Static_Object * __thiscall FUN_004cb5b6(RGE_Action_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Build *this;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fc3b;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb6f6;
  if (param_3 == 0) {
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 != '\x01') goto LAB_004cb63e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb63e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x65) goto LAB_004cb63e;
  }
  else {
LAB_004cb63e:
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action(param_1->actions);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x65) {
        pRVar5 = RGE_Action_List::get_action(param_1->actions);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb6f1;
      }
    }
    iVar1 = param_1->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb6f6;
    this = (TRIBE_Action_Build *)operator_new(0x40);
    uStack_4 = 0;
    if (this == (TRIBE_Action_Build *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Build::TRIBE_Action_Build(this,param_1,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb6f6;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb6f1:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb6f6:
  *unaff_FS_OFFSET = uStack_c;
  return pRVar6;
}

// --------------------------------------------------

// Function: FUN_004cb70b
// Address: 004cb70b
// XREFS: None
RGE_Static_Object * __thiscall FUN_004cb70b(RGE_Action_Object *param_1,int param_2,int param_3)
{
  int iVar1;
  uchar uVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  RGE_Static_Object *pRVar6;
  TRIBE_Action_Trade *this;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fc5b;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar4 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = pRVar4;
  if (pRVar4 == (RGE_Static_Object *)0x0) goto LAB_004cb846;
  if (param_3 == 0) {
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 != '\x01') goto LAB_004cb78e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    pRVar6 = (RGE_Static_Object *)(**(code **)(pRVar5->_padding_ + 0x4c))();
    if (pRVar6 != pRVar4) goto LAB_004cb78e;
    pRVar5 = RGE_Action_List::get_action(param_1->actions);
    sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
    if (sVar3 != 0x6f) goto LAB_004cb78e;
  }
  else {
LAB_004cb78e:
    uVar2 = RGE_Action_List::have_action(param_1->actions);
    if (uVar2 == '\x01') {
      pRVar5 = RGE_Action_List::get_action(param_1->actions);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      if (sVar3 == 0x6f) {
        pRVar5 = RGE_Action_List::get_action(param_1->actions);
        (**(code **)(pRVar5->_padding_ + 0x34))
                  (pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
        goto LAB_004cb841;
      }
    }
    iVar1 = param_1->_padding_;
    pRVar6 = (RGE_Static_Object *)
             (**(code **)(iVar1 + 0x210))(pRVar4,pRVar4->world_x,pRVar4->world_y,pRVar4->world_z);
    if (pRVar6 == (RGE_Static_Object *)0x0) goto LAB_004cb846;
    this = (TRIBE_Action_Trade *)operator_new(0x48);
    uStack_4 = 0;
    if (this == (TRIBE_Action_Trade *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = TRIBE_Action_Trade::TRIBE_Action_Trade(this,param_1,(RGE_Task *)pRVar6,pRVar4);
    }
    uStack_4 = 0xffffffff;
    if (iVar7 == 0) {
      pRVar6 = (RGE_Static_Object *)0x0;
      goto LAB_004cb846;
    }
    RGE_Action_List::delete_list(param_1->actions);
    (**(code **)(iVar1 + 0x208))(iVar7);
  }
LAB_004cb841:
  pRVar6 = (RGE_Static_Object *)0x1;
LAB_004cb846:
  *unaff_FS_OFFSET = uStack_c;
  return pRVar6;
}

// --------------------------------------------------

// Function: FUN_004cb85b
// Address: 004cb85b
// XREFS: None
undefined4 FUN_004cb85b(int param_1)
{
  if ((param_1 != 0x32) && (param_1 != 0x2d)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cb878
// Address: 004cb878
// XREFS: None
undefined4 __thiscall FUN_004cb878(int param_1,int param_2)
{
  short sVar1;
  int3 iVar2;
  
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x14);
  iVar2 = (int3)(char)((ushort)sVar1 >> 8);
  if ((sVar1 != 9) && (sVar1 != 10)) {
    return CONCAT31(iVar2,1);
  }
  return CONCAT31(iVar2,param_2 == 4);
}

// --------------------------------------------------

// Function: FUN_004cb8a1
// Address: 004cb8a1
// XREFS: None
int __fastcall FUN_004cb8a1(int param_1)
{
  short sVar1;
  uint3 uVar2;
  
  sVar1 = *(short *)(*(int *)(param_1 + 8) + 0x14);
  uVar2 = (uint3)(char)((ushort)sVar1 >> 8);
  if ((sVar1 != 0x15) && (sVar1 != 2)) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}

// --------------------------------------------------

// Function: FUN_004cb8c7
// Address: 004cb8c7
// XREFS: None
void __fastcall FUN_004cb8c7(RGE_Static_Object *param_1)
{
  short sVar1;
  RGE_Master_Static_Object *pRVar2;
  TribeArtifactUnitAIModule *this;
  TribeCivilianUnitAIModule *this_00;
  TribePriestUnitAIModule *this_01;
  TribeHuntedAnimalUnitAIModule *pTVar3;
  TribeElephantUnitAIModule *this_02;
  TribeLionUnitAIModule *this_03;
  TribePreditorUnitAIModule *this_04;
  TribeFishingShipUnitAIModule *this_05;
  TribeTradeShipUnitAIModule *this_06;
  TribeTransportShipUnitAIModule *this_07;
  TribeBuildingUnitAIModule *this_08;
  TribeTowerUnitAIModule *this_09;
  TribeSoldierUnitAIModule *this_10;
  UnitAIModule *pUVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd0a;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar2 = param_1->master_obj;
  switch(pRVar2->object_group) {
  case 1:
    if ((pRVar2->id == 99) || (pRVar2->id == 10)) goto switchD_004cb902_caseD_5;
    this = (TribeArtifactUnitAIModule *)operator_new(0x134);
    uStack_4 = 0;
    if (this != (TribeArtifactUnitAIModule *)0x0) {
      pUVar4 = (UnitAIModule *)TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(this,param_1,5);
      param_1->unitAIValue = pUVar4;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 2:
    this_06 = (TribeTradeShipUnitAIModule *)operator_new(0x134);
    uStack_4 = 9;
    if (this_06 != (TribeTradeShipUnitAIModule *)0x0) {
      pUVar4 = (UnitAIModule *)
               TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(this_06,param_1,10);
      param_1->unitAIValue = pUVar4;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 3:
  case 0x1b:
    sVar1 = pRVar2->id;
    if (((((sVar1 == 0x4f) || (sVar1 == 199)) || (sVar1 == 0x45)) ||
        ((sVar1 == 0x116 || (sVar1 == 0x17f)))) || (sVar1 == 0x17c)) {
      this_09 = (TribeTowerUnitAIModule *)operator_new(0x134);
      uStack_4 = 0xb;
      if (this_09 != (TribeTowerUnitAIModule *)0x0) {
        pUVar4 = (UnitAIModule *)TribeTowerUnitAIModule::TribeTowerUnitAIModule(this_09,param_1,10);
        param_1->unitAIValue = pUVar4;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
    }
    else {
      this_08 = (TribeBuildingUnitAIModule *)operator_new(0x134);
      uStack_4 = 0xc;
      if (this_08 != (TribeBuildingUnitAIModule *)0x0) {
        pUVar4 = (UnitAIModule *)
                 TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(this_08,param_1,10);
        param_1->unitAIValue = pUVar4;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
    }
    break;
  case 4:
    this_00 = (TribeCivilianUnitAIModule *)operator_new(0x134);
    uStack_4 = 1;
    if (this_00 != (TribeCivilianUnitAIModule *)0x0) {
      pUVar4 = (UnitAIModule *)
               TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(this_00,param_1,10);
      param_1->unitAIValue = pUVar4;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 5:
  case 7:
  case 8:
  case 0xb:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
    goto switchD_004cb902_caseD_5;
  default:
    this_10 = (TribeSoldierUnitAIModule *)operator_new(0x134);
    uStack_4 = 0xd;
    if (this_10 != (TribeSoldierUnitAIModule *)0x0) {
      pUVar4 = (UnitAIModule *)
               TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(this_10,param_1,10);
      param_1->unitAIValue = pUVar4;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 9:
    pTVar3 = (TribeHuntedAnimalUnitAIModule *)operator_new(0x134);
    uStack_4 = 3;
    if (pTVar3 != (TribeHuntedAnimalUnitAIModule *)0x0) {
      pUVar4 = (UnitAIModule *)
               TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(pTVar3,param_1,10);
      param_1->unitAIValue = pUVar4;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 10:
    sVar1 = pRVar2->id;
    if (sVar1 == 0x9d) {
      pTVar3 = (TribeHuntedAnimalUnitAIModule *)operator_new(0x134);
      uStack_4 = 4;
      if (pTVar3 != (TribeHuntedAnimalUnitAIModule *)0x0) {
        pUVar4 = (UnitAIModule *)
                 TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(pTVar3,param_1,10);
        param_1->unitAIValue = pUVar4;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
    }
    else if (sVar1 == 0x30) {
      this_02 = (TribeElephantUnitAIModule *)operator_new(0x134);
      uStack_4 = 5;
      if (this_02 != (TribeElephantUnitAIModule *)0x0) {
        pUVar4 = (UnitAIModule *)
                 TribeElephantUnitAIModule::TribeElephantUnitAIModule(this_02,param_1,10);
        param_1->unitAIValue = pUVar4;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
    }
    else if (sVar1 == 0x7e) {
      this_03 = (TribeLionUnitAIModule *)operator_new(0x134);
      uStack_4 = 6;
      if (this_03 != (TribeLionUnitAIModule *)0x0) {
        pUVar4 = (UnitAIModule *)TribeLionUnitAIModule::TribeLionUnitAIModule(this_03,param_1,10);
        param_1->unitAIValue = pUVar4;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
    }
    else {
      this_04 = (TribePreditorUnitAIModule *)operator_new(0x134);
      uStack_4 = 7;
      if (this_04 != (TribePreditorUnitAIModule *)0x0) {
        pUVar4 = (UnitAIModule *)
                 TribePreditorUnitAIModule::TribePreditorUnitAIModule(this_04,param_1,10);
        param_1->unitAIValue = pUVar4;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
    }
    break;
  case 0x12:
    this_01 = (TribePriestUnitAIModule *)operator_new(0x134);
    uStack_4 = 2;
    if (this_01 != (TribePriestUnitAIModule *)0x0) {
      pUVar4 = (UnitAIModule *)TribePriestUnitAIModule::TribePriestUnitAIModule(this_01,param_1,10);
      param_1->unitAIValue = pUVar4;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 0x14:
    this_07 = (TribeTransportShipUnitAIModule *)operator_new(0x134);
    uStack_4 = 10;
    if (this_07 != (TribeTransportShipUnitAIModule *)0x0) {
      pUVar4 = (UnitAIModule *)
               TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(this_07,param_1,10);
      param_1->unitAIValue = pUVar4;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 0x15:
    this_05 = (TribeFishingShipUnitAIModule *)operator_new(0x134);
    uStack_4 = 8;
    if (this_05 != (TribeFishingShipUnitAIModule *)0x0) {
      pUVar4 = (UnitAIModule *)
               TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(this_05,param_1,10);
      param_1->unitAIValue = pUVar4;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
  }
  param_1->unitAIValue = (UnitAIModule *)0x0;
switchD_004cb902_caseD_5:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004cbccb
// Address: 004cbccb
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_004cbccb(char *param_1)
{
  undefined4 in_EAX;
  char unaff_BL;
  uint unaff_EDI;
  
  *(uint *)(param_1 + -0x449fffb4) = *(uint *)(param_1 + -0x449fffb4) | unaff_EDI;
  *param_1 = *param_1 + 'L';
  cRambcbb004c = cRambcbb004c + (char)((uint)in_EAX >> 8) + unaff_BL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: lines_intersect
// Address: 004cbd30
// XREFS: higher_check_for_cliff
/* int __cdecl lines_intersect(float,float,float,float,float,float,float,float) */

int __cdecl
lines_intersect(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
               float param_7,float param_8)
{
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cbd36
// Address: 004cbd36
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004cbd36(int param_1,int param_2,int param_3,int param_4,float param_5,float param_6,
            float param_7,float param_8,int param_9,int param_10,float *param_11,int *param_12)
{
  byte bVar1;
  int iVar2;
  float10 fVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  
  if ((((param_4 < 0) || (*(int *)(param_9 + 0xc) <= param_4)) || (param_3 < 0)) ||
     ((*(int *)(param_9 + 8) <= param_3 ||
      (piVar6 = *(int **)(*(int *)(*(int *)(param_9 + 0x8d8c) + param_4 * 4) + 0x10 + param_3 * 0x18
                         ), piVar6 == (int *)0x0)))) {
    return 0;
  }
  do {
    iVar2 = *piVar6;
    if ((*(short *)(*(int *)(iVar2 + 8) + 0x14) == 0x22) && (iVar2 != param_10)) {
      if (*param_11 == -1.0) {
        fVar7 = (float10)fpatan((float10)*(float *)(param_2 + 0x3c) -
                                (float10)*(float *)(param_1 + 0x3c),
                                (float10)*(float *)(param_2 + 0x38) -
                                (float10)*(float *)(param_1 + 0x38));
        fVar3 = (float10)_DAT_00574c98;
        *param_11 = (float)fVar7;
        if (fVar7 < fVar3) {
          *param_11 = (float)(fVar7 - (float10)_DAT_00574ca4);
        }
      }
      bVar1 = *(byte *)(iVar2 + 0x35);
      uVar4 = (uint)bVar1;
      iVar5 = uVar4 * 0x20;
      iVar5 = lines_intersect(param_5,param_6,param_7,param_8,
                              *(float *)(&DAT_00587268 + iVar5) + param_5,
                              *(float *)(&DAT_0058726c + iVar5) + param_6,
                              *(float *)(&DAT_00587270 + iVar5) + param_7,
                              *(float *)(&DAT_00587274 + iVar5) + param_8);
      param_10 = iVar2;
      if (iVar5 != 0) {
        if ((((0x18 < bVar1) || (*param_11 < (float)(&TRIBE_Cliff_Higher_Check_Table)[uVar4 * 8]))
            || (*(float *)(&DAT_0058725c + uVar4 * 0x20) < *param_11)) &&
           ((*param_11 < *(float *)(&DAT_00587260 + uVar4 * 0x20) ||
            (*(float *)(&DAT_00587264 + uVar4 * 0x20) < *param_11)))) {
          *param_12 = *param_12 + -1;
          return 1;
        }
        *param_12 = *param_12 + 1;
        return 1;
      }
    }
    piVar6 = (int *)piVar6[1];
    if (piVar6 == (int *)0x0) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004cbee5
// Address: 004cbee5
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_004cbee5(int *param_1,int param_2)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  code *pcVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  float10 extraout_ST0;
  float10 fVar14;
  float10 extraout_ST1;
  int iStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint uStack_c;
  uint uStack_8;
  int iStack_4;
  
  if (*(float *)(param_2 + 0x40) < (float)param_1[0x10]) {
    return true;
  }
  fVar3 = *(float *)(param_2 + 0x38);
  fVar4 = (float)param_1[0xe];
  fVar5 = *(float *)(param_2 + 0x3c);
  fVar6 = (float)param_1[0xf];
  if ((fVar3 - fVar4 == _DAT_00574c98) && (fVar5 - fVar6 == _DAT_00574c98)) {
    return false;
  }
  uVar9 = __ftol();
  iStack_4 = ((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f)) * 2;
  fVar14 = extraout_ST1 / (float10)iStack_4;
  fVar1 = (float)fVar14;
  fVar2 = (float)(extraout_ST0 / (float10)iStack_4);
  fVar8 = fVar1;
  if (fVar14 < (float10)_DAT_00574c98) {
    fVar8 = -fVar1;
  }
  fStack_20 = fVar2;
  if (fVar2 < _DAT_00574c98) {
    fStack_20 = -fVar2;
  }
  bVar13 = fVar8 <= fStack_20;
  if (bVar13) {
    iStack_10 = -1;
    iStack_14 = 0;
  }
  else {
    iStack_14 = -1;
    iStack_10 = 0;
  }
  uStack_8 = (uint)bVar13;
  uStack_c = (uint)!bVar13;
  iStack_1c = -999;
  iStack_18 = -999;
  fStack_20 = *(float *)(*(int *)(param_1[3] + 0x3c) + 0x28);
  uStack_24 = 0xbf800000;
  iStack_30 = 0;
  iVar10 = 0;
  fStack_2c = fVar4;
  fStack_28 = fVar6;
  if (0 < iStack_4) {
    do {
      fStack_2c = fStack_2c + fVar1;
      fStack_28 = fStack_28 + fVar2;
      iVar10 = __ftol();
      iVar11 = __ftol();
      if ((iVar10 != iStack_1c) || (iVar11 != iStack_18)) {
        pcVar7 = *(code **)(*param_1 + 0x248);
        iStack_1c = iVar10;
        iStack_18 = iVar11;
        iVar12 = (*pcVar7)(param_2,iVar10,iVar11,fVar4,fVar6,fVar3,fVar5,fStack_20,0,&uStack_24,
                           &iStack_30);
        if ((iVar12 == 0) &&
           (iVar12 = (*pcVar7)(param_2,iStack_10 + iVar10,iStack_14 + iVar11,fVar4,fVar6,fVar3,fVar5
                               ,fStack_20,0,&uStack_24,&iStack_30), iVar12 == 0)) {
          (*pcVar7)(param_2,uStack_8 + iVar10,uStack_c + iVar11,fVar4,fVar6,fVar3,fVar5,fStack_20,0,
                    &uStack_24,&iStack_30);
        }
      }
      iStack_4 = iStack_4 + -1;
      iVar10 = iStack_30;
    } while (iStack_4 != 0);
  }
  if (iVar10 < 1) {
    iVar10 = 0;
  }
  if (0 < iVar10) {
    iVar10 = 1;
  }
  return 0 < iVar10;
}

// --------------------------------------------------

// Function: FUN_004cc1ad
// Address: 004cc1ad
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_t_c_obj_cp: "C:\msdev\work\age1_x1\t_c_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004cc1ad(int *param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5,
            int *param_6)
{
  float fVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  short sVar12;
  undefined4 unaff_EBP;
  float10 fVar13;
  float fStack_28;
  short sStack_24;
  short sStack_20;
  int iStack_1c;
  int iStack_10;
  int iStack_c;
  
  fVar1 = *(float *)(param_1[2] + 0x118);
  iVar3 = *(int *)(*(int *)(param_1[3] + 0x3c) + 0x28);
  sVar2 = *(short *)(iVar3 + 8);
  sVar12 = *(short *)(iVar3 + 0xc) + -1;
  fVar6 = (float)_DAT_00574ca8;
  if (fVar1 < fVar6 || (fVar1 == fVar6) != 0) {
    return CONCAT22((short)((uint)iVar3 >> 0x10),
                    (ushort)(fVar1 < fVar6) << 8 | (ushort)(NAN(fVar1) || NAN(fVar6)) << 10 |
                    (ushort)(fVar1 == fVar6) << 0xe);
  }
  sStack_24 = __ftol();
  sStack_24 = sStack_24 + -2;
  sVar8 = __ftol();
  sVar9 = __ftol();
  sVar9 = sVar9 + -2;
  iStack_c = __ftol();
  iStack_c = iStack_c + 2;
  if (sStack_24 < 0) {
    sStack_24 = 0;
  }
  sStack_20 = sVar8 + 2;
  if ((short)(sVar2 + -1) + 1 < (int)(short)(sVar8 + 2)) {
    sStack_20 = sVar2;
  }
  if (sVar9 < 0) {
    sVar9 = 0;
  }
  if (sVar12 + 1 < (int)(short)iStack_c) {
    iStack_c = CONCAT22((short)((uint)unaff_EBP >> 0x10),sVar12) + 1;
  }
  if (sVar9 < (short)iStack_c) {
    iStack_1c = sVar9 * 4;
    iStack_c = (int)(short)iStack_c - (int)sVar9;
    do {
      if (sStack_24 < sStack_20) {
        iVar11 = sStack_24 * 0x18;
        iStack_10 = (int)sStack_20 - (int)sStack_24;
        do {
          for (piVar4 = *(int **)(*(int *)(iStack_1c + *(int *)(iVar3 + 0x8d8c)) + 0x10 + iVar11);
              piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
            piVar5 = (int *)*piVar4;
            if (piVar5 != param_6) {
              sVar2 = *(short *)(param_1[2] + 0x10);
              if ((((((sVar2 != 0x2e) && (sVar2 != 0x28)) && (sVar2 != 0x153)) && (sVar2 != 0x159))
                  || (piVar5[3] != param_1[3])) &&
                 ((piVar5 != param_1 &&
                  (iVar10 = piVar5[2], *(byte *)(param_1[2] + 0x11c) <= *(byte *)(iVar10 + 0x8b)))))
{
                fVar6 = (float)piVar5[0xe] - param_2;
                fStack_28 = (float)piVar5[0xf] - param_3;
                if (fVar6 < _DAT_00574c98) {
                  fVar6 = -fVar6;
                }
                if (fStack_28 < _DAT_00574c98) {
                  fStack_28 = -fStack_28;
                }
                fVar7 = _DAT_00574c98;
                if (*(float *)(iVar10 + 0x30) < fVar6) {
                  fVar7 = fVar6 - *(float *)(iVar10 + 0x30);
                }
                fVar6 = _DAT_00574c98;
                if (*(float *)(iVar10 + 0x34) < fStack_28) {
                  fVar6 = fStack_28 - *(float *)(iVar10 + 0x34);
                }
                if (fVar6 * fVar6 + fVar7 * fVar7 < fVar1 * fVar1) {
                  iVar10 = debug_rand(s_C__msdev_work_age1_x1_t_c_obj_cp,0x653);
                  iVar10 = iVar10 * 100;
                  if ((short)(((short)(iVar10 / 0x7fff) + (short)(iVar10 >> 0x1f)) -
                             (short)((longlong)iVar10 * 0x80010003 >> 0x3f)) <=
                      *(short *)(param_1[2] + 0x126)) {
                    fVar13 = (float10)(**(code **)(*param_1 + 0xf0))(piVar5);
                    iVar10 = *piVar5;
                    (**(code **)(iVar10 + 0x70))
                              ((int)*(short *)(param_1[2] + 0x108),
                               *(undefined4 *)(param_1[2] + 0x10c),(float)fVar13,param_1[3],param_4)
                    ;
                    if ((float)piVar5[0xc] < _DAT_00574c78) {
                      (**(code **)(iVar10 + 0x84))(0,0,1);
                    }
                  }
                }
              }
            }
          }
          iVar11 = iVar11 + 0x18;
          iStack_10 = iStack_10 + -1;
        } while (iStack_10 != 0);
      }
      iStack_1c = iStack_1c + 4;
      iStack_c = iStack_c + -1;
    } while (iStack_c != 0);
  }
  return CONCAT31((int3)((uint)iStack_c >> 8),1);
}

// --------------------------------------------------

// Function: FUN_004cc4b8
// Address: 004cc4b8
// XREFS: None
uchar __thiscall FUN_004cc4b8(RGE_Static_Object *param_1,float param_2)
{
  short sVar1;
  RGE_Master_Static_Object *pRVar2;
  float fVar3;
  uchar uVar4;
  
  pRVar2 = param_1->master_obj;
  sVar1 = pRVar2->object_group;
  if ((((sVar1 != 2) && (sVar1 != 0x14)) && (sVar1 != 0x15)) && (sVar1 != 0x16)) {
    uVar4 = RGE_Static_Object::heal(param_1,param_2);
    return uVar4;
  }
  fVar3 = (float)(int)pRVar2->hp;
  param_2 = (param_2 * fVar3) / (float)(int)*(short *)((int)&pRVar2[1].hotkey_id + 2);
  if (fVar3 < param_2 + param_1->hp) {
    param_2 = fVar3 - param_1->hp;
  }
  uVar4 = TRIBE_Player::pay_obj_cost
                    ((TRIBE_Player *)param_1->owner,pRVar2->id,param_2 / (float)(pRVar2->hp * 2),1);
  if (uVar4 == '\0') {
    return '\x02';
  }
  uVar4 = RGE_Static_Object::heal(param_1,param_2);
  return uVar4;
}

// --------------------------------------------------

// Function: FUN_004cc56d
// Address: 004cc56d
// XREFS: None
bool __fastcall FUN_004cc56d(int param_1)
{
  float fVar1;
  uchar uVar2;
  
  fVar1 = (float)(int)*(short *)(*(int *)(param_1 + 8) + 0x26);
  uVar2 = TRIBE_Player::check_obj_cost
                    (*(TRIBE_Player **)(param_1 + 0xc),*(short *)(*(int *)(param_1 + 8) + 0x10),
                     (short *)0x0,(fVar1 - *(float *)(param_1 + 0x30)) / fVar1,0);
  return uVar2 != '\0';
}

// --------------------------------------------------

// Function: FUN_004cc5a6
// Address: 004cc5a6
// XREFS: None
void __thiscall FUN_004cc5a6(RGE_Static_Object *param_1,RGE_Static_Object *param_2)
{
  RGE_Sprite *pRVar1;
  bool bVar2;
  short sVar3;
  RGE_Static_Object *pRVar4;
  RGE_Action *pRVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  RGE_Static_Object *pRVar9;
  
  if (param_2 != param_1) {
    if (param_1->master_obj->id != 0x9c) {
      (**(code **)(param_1->_padding_ + 0x54))(param_1->owner->master_objects[0x9c]);
    }
    pRVar1 = param_1->master_obj[1].undead_sprite;
    iVar7 = 0;
    iVar8 = (int)*(short *)(pRVar1->pict_name + 8);
    pRVar9 = param_2;
    if (0 < iVar8) {
      piVar6 = *(int **)(pRVar1->pict_name + 4);
      do {
        pRVar9 = (RGE_Static_Object *)*piVar6;
        if ((*(short *)((int)&pRVar9->id + 2) == 0x6a) &&
           (((param_2->master_obj->master_type == 'P' &&
             ((*(short *)&pRVar9->master_obj == -1 || (*(short *)&pRVar9->master_obj == 0)))) ||
            (*(short *)&pRVar9->master_obj == param_2->master_obj->object_group)))) break;
        pRVar9 = (RGE_Static_Object *)0x0;
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar7 < iVar8);
    }
    pRVar4 = (RGE_Static_Object *)
             RGE_Action_List::get_task((RGE_Action_List *)param_1[2].unitAIValue);
    sVar3 = 0;
    bVar2 = false;
    if (((pRVar4 != (RGE_Static_Object *)0x0) && (pRVar9 == pRVar4)) &&
       (iVar7 = RGE_Action_List::action_work
                          ((RGE_Action_List *)param_1[2].unitAIValue,param_2,param_2->world_x,
                           param_2->world_y,param_2->world_z), iVar7 != 0)) {
      pRVar5 = RGE_Action_List::get_action((RGE_Action_List *)param_1[2].unitAIValue);
      sVar3 = (**(code **)(pRVar5->_padding_ + 0x18))();
      bVar2 = true;
    }
    if (!bVar2) {
      if (pRVar9 == (RGE_Static_Object *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)(**(code **)((param_1[2].unitAIValue)->_padding_ + 4))
                                  (pRVar9,param_2,param_2->world_x,param_2->world_y,param_2->world_z
                                  );
      }
      if (piVar6 == (int *)0x0) {
        sVar3 = 0;
      }
      else {
        sVar3 = (**(code **)(*piVar6 + 0x18))();
        (**(code **)(param_1->_padding_ + 0x208))(piVar6);
      }
    }
    if (param_1->unitAIValue != (UnitAIModule *)0x0) {
      iVar7 = -1;
      iVar8 = -1;
      if (sVar3 == 0x6a) {
        iVar8 = 0x26a;
        iVar7 = 0x2ce;
      }
      UnitAIModule::setCurrentOrder(param_1->unitAIValue,iVar7);
      UnitAIModule::setCurrentAction(param_1->unitAIValue,iVar8);
      UnitAIModule::setCurrentTarget
                (param_1->unitAIValue,param_2->id,(int)param_2->master_obj->object_group,
                 param_2->world_x,param_2->world_y,param_2->world_z);
      UnitAIModule::setTaskedByPlayer(param_1->unitAIValue);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004cc72f
// Address: 004cc72f
// XREFS: None
TRIBE_History_Info * __thiscall FUN_004cc72f(TRIBE_History_Info *param_1,int param_2)
{
  param_1->history = (TRIBE_History_Entry *)0x0;
  param_1->events = (TRIBE_History_Events *)0x0;
  param_1->number_of_entries = 0;
  param_1->number_of_events = 0;
  param_1->max_number_of_entries = 0;
  if (-1 < param_2) {
    TRIBE_History_Info::load(param_1,param_2);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cc759
// Address: 004cc759
// XREFS: None
void __fastcall FUN_004cc759(int *param_1)
{
  int iVar1;
  
  if (*param_1 != 0) {
    free(*param_1);
  }
  iVar1 = param_1[1];
  while (iVar1 != 0) {
    param_1[1] = *(int *)(iVar1 + 0xc);
    free(iVar1);
    iVar1 = param_1[1];
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004cc791
// Address: 004cc791
// XREFS: None
void __thiscall FUN_004cc791(undefined4 *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  iVar3 = param_2;
  rge_write(param_2,param_1 + 3,4);
  rge_write(iVar3,param_1 + 2,4);
  rge_write(iVar3,param_1 + 4,4);
  rge_write(iVar3,(void *)*param_1,param_1[4]);
  iVar1 = param_1[1];
  param_2 = 0;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    param_2 = param_2 + 1;
  }
  rge_write(iVar3,&param_2,4);
  for (pvVar2 = (void *)param_1[1]; pvVar2 != (void *)0x0; pvVar2 = *(void **)((int)pvVar2 + 0xc)) {
    rge_write(iVar3,pvVar2,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004cc834
// Address: 004cc834
// XREFS: None
void __thiscall FUN_004cc834(undefined4 *param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = param_2;
  rge_read(param_2,param_1 + 3,4);
  rge_read(iVar2,param_1 + 2,4);
  piVar1 = param_1 + 4;
  rge_read(iVar2,piVar1,4);
  pvVar3 = (void *)calloc(*piVar1,1);
  *param_1 = pvVar3;
  rge_read(iVar2,pvVar3,*piVar1);
  param_1 = param_1 + 1;
  rge_read(iVar2,&param_2,4);
  for (; 0 < param_2; param_2 = param_2 + -1) {
    pvVar3 = (void *)calloc(1,0x10);
    rge_read(iVar2,pvVar3,0x10);
    *param_1 = pvVar3;
    param_1 = (undefined4 *)((int)pvVar3 + 0xc);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004cc8df
// Address: 004cc8df
// XREFS: None
void __thiscall FUN_004cc8df(int *param_1,char param_2,undefined1 param_3)
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar3 = param_1[4];
  if ((int)uVar3 <= param_1[3]) {
    param_1[4] = uVar3 + 0x3c;
    puVar1 = (undefined4 *)calloc(uVar3 + 0x3c,1);
    if (0 < (int)uVar3) {
      puVar4 = (undefined4 *)*param_1;
      puVar5 = puVar1;
      for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      free(*param_1);
    }
    *param_1 = (int)puVar1;
  }
  if (param_2 == '\0') {
    *(undefined1 *)(*param_1 + param_1[3]) = param_3;
  }
  param_1[3] = param_1[3] + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004cc94a
// Address: 004cc94a
// XREFS: None
undefined4 __fastcall FUN_004cc94a(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_004cc954
// Address: 004cc954
// XREFS: None
undefined1 __thiscall FUN_004cc954(int *param_1,char param_2,int param_3)
{
  if (((param_3 < param_1[3]) && (-1 < param_3)) && (param_2 == '\0')) {
    return *(undefined1 *)(*param_1 + param_3);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004cc984
// Address: 004cc984
// XREFS: None
void __thiscall FUN_004cc984(int param_1,undefined1 param_2)
{
  undefined1 *puVar1;
  
  if (0 < *(int *)(param_1 + 0xc)) {
    puVar1 = (undefined1 *)calloc(1,0x10);
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(param_1 + 0xc);
    *(ulong *)(puVar1 + 8) = rge_base_game->world->world_time;
    *puVar1 = param_2;
    *(undefined1 **)(param_1 + 4) = puVar1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004cc9d1
// Address: 004cc9d1
// XREFS: None
undefined4 __fastcall FUN_004cc9d1(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_004cc9e4
// Address: 004cc9e4
// XREFS: None
undefined4 __thiscall FUN_004cc9e4(int param_1,int param_2,undefined1 *param_3,undefined4 *param_4)
{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(param_1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    return 0;
  }
  do {
    if (param_2 == 0) {
      *param_3 = *puVar2;
      uVar1 = *(undefined4 *)(puVar2 + 4);
      *param_4 = uVar1;
      return CONCAT31((int3)((uint)uVar1 >> 8),1);
    }
    puVar2 = *(undefined1 **)(puVar2 + 0xc);
  } while (puVar2 != (undefined1 *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004cca26
// Address: 004cca26
// XREFS: None
undefined4 __thiscall FUN_004cca26(int param_1,int param_2,undefined1 *param_3)
{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    return 0;
  }
  do {
    if (*(int *)(puVar1 + 4) == param_2) {
      *param_3 = *puVar1;
      return CONCAT31((int3)((uint)puVar1 >> 8),1);
    }
    puVar1 = *(undefined1 **)(puVar1 + 0xc);
  } while (puVar1 != (undefined1 *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004cca5e
// Address: 004cca5e
// XREFS: None
RGE_Static_Object * __thiscall
FUN_004cca5e(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Static_Object::RGE_Static_Object(param_1,param_2,param_3,param_4,param_5,param_6,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Tree_Object::_vftable_;
  if (param_7 != 0) {
    RGE_Static_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ccae3
// Address: 004ccae3
// XREFS: None
TRIBE_Tree_Object * __thiscall FUN_004ccae3(TRIBE_Tree_Object *param_1,byte param_2)
{
  TRIBE_Tree_Object::~TRIBE_Tree_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ccb15
// Address: 004ccb15
// XREFS: None
RGE_Static_Object * __thiscall
FUN_004ccb15(RGE_Static_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Static_Object::RGE_Static_Object(param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Tree_Object::_vftable_;
  if (param_4 != 0) {
    RGE_Static_Object::setup(param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ccb85
// Address: 004ccb85
// XREFS: None
void __thiscall FUN_004ccb85(RGE_Static_Object *param_1,uchar param_2)
{
  RGE_Static_Object::set_object_state(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004ccb9d
// Address: 004ccb9d
// XREFS: None
RGE_Action * __thiscall FUN_004ccb9d(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  param_1->_padding_ = (int)&TRIBE_Action_Artifact::_vftable_;
  param_1->action_type = 0x6b;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ccbc8
// Address: 004ccbc8
// XREFS: None
TRIBE_Action_Artifact * __thiscall FUN_004ccbc8(TRIBE_Action_Artifact *param_1,byte param_2)
{
  TRIBE_Action_Artifact::~TRIBE_Action_Artifact(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ccbf5
// Address: 004ccbf5
// XREFS: None
RGE_Action * __thiscall
FUN_004ccbf5(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->_padding_ = (int)&TRIBE_Action_Artifact::_vftable_;
  param_1->action_type = 0x6b;
  param_1->task = param_3;
  param_1->target_obj = param_4;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ccc2f
// Address: 004ccc2f
// XREFS: None
RGE_Action * __thiscall
FUN_004ccc2f(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&TRIBE_Action_Artifact::_vftable_;
  param_1->action_type = 0x6b;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ccc6d
// Address: 004ccc6d
// XREFS: None
void __thiscall FUN_004ccc6d(int *param_1,char param_2)
{
  if (param_2 != '\0') {
    if (param_1[4] != 0) {
      (**(code **)(*param_1 + 0x5c))(5);
      return;
    }
    if ((param_1[8] != -0x40800000) && (param_1[9] != -0x40800000)) {
      (**(code **)(*param_1 + 0x5c))(4);
      return;
    }
    (**(code **)(*param_1 + 0x5c))(6);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004cccae
// Address: 004cccae
// XREFS: None
void __thiscall FUN_004cccae(int *param_1,char param_2)
{
  int iVar1;
  RGE_Action_Move_To *pRVar2;
  RGE_Action *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd76;
  *unaff_FS_OFFSET = &uStack_c;
  *(char *)(param_1 + 3) = param_2;
  if (param_2 == '\x04') {
    RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
    pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (pRVar2 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar2,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9]
                          ,(float)param_1[10],0.0,*(RGE_Sprite **)(param_1[0xc] + 0x34));
    }
  }
  else {
    if (param_2 != '\x05') {
      if (param_2 == '\n') {
        param_1[0xb] = 0x40400000;
        *unaff_FS_OFFSET = uStack_c;
        return;
      }
      goto LAB_004ccdd6;
    }
    RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
    iVar1 = param_1[4];
    param_1[8] = *(int *)(iVar1 + 0x38);
    param_1[9] = *(int *)(iVar1 + 0x3c);
    param_1[10] = *(int *)(iVar1 + 0x40);
    param_1[4] = 0;
    pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 1;
    if (pRVar2 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar2,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9]
                          ,(float)param_1[10],0.0,*(RGE_Sprite **)(param_1[0xc] + 0x34));
    }
  }
  if (pRVar3 != (RGE_Action *)0x0) {
    uStack_4 = 0xffffffff;
    RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],pRVar3);
    (**(code **)(*param_1 + 0x5c))(6);
  }
LAB_004ccdd6:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004ccde8
// Address: 004ccde8
// XREFS: None
uint __fastcall FUN_004ccde8(TRIBE_Action_Artifact *param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  uint uVar5;
  RGE_Player *pRVar6;
  
  bVar4 = (**(code **)(**(int **)&param_1->field_0x34 + 0xc))();
  if ((bVar4 != 0) && (bVar4 < 4)) {
    RGE_Action_List::delete_list(*(RGE_Action_List **)&param_1->field_0x34);
  }
  uVar5 = (byte)param_1->field_0xc - 1;
  switch(param_1->field_0xc) {
  case 1:
    return CONCAT31((int3)(uVar5 >> 8),1);
  case 6:
    break;
  case 10:
    iVar1 = *(int *)(*(int *)&param_1->field_0x8 + 0xc);
    fVar2 = *(float *)&param_1->field_0x2c - *(float *)(*(int *)(iVar1 + 0x3c) + 0x84);
    fVar3 = (float)(double)DAT_00574f08;
    *(float *)&param_1->field_0x2c = fVar2;
    uVar5 = CONCAT22((short)((uint)iVar1 >> 0x10),
                     (ushort)(fVar2 < fVar3) << 8 | (ushort)(NAN(fVar2) || NAN(fVar3)) << 10 |
                     (ushort)(fVar2 == fVar3) << 0xe);
    if (fVar2 < fVar3 || (fVar2 == fVar3) != 0) {
      uVar5 = (**(code **)(*(int *)param_1 + 0x5c))(6);
      return uVar5 & 0xffffff00;
    }
  default:
    return uVar5 & 0xffffff00;
  case 100:
    (**(code **)(**(int **)&param_1->field_0x8 + 0x44))
              (**(undefined4 **)(*(int *)((*(int **)&param_1->field_0x8)[3] + 0x3c) + 0x40));
    uVar5 = (**(code **)(*(int *)param_1 + 0x5c))(6);
    return uVar5 & 0xffffff00;
  }
  pRVar6 = TRIBE_Action_Artifact::check_ownership(param_1);
  if (pRVar6 != (RGE_Player *)0x0) {
    RGE_Action_List::delete_list(*(RGE_Action_List **)&param_1->field_0x34);
    uVar5 = (**(code **)(**(int **)&param_1->field_0x8 + 0x44))(pRVar6);
    return uVar5 & 0xffffff00;
  }
  uVar5 = (**(code **)(*(int *)param_1 + 0x5c))(10);
  return uVar5 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004cceb7
// Address: 004cceb7
// XREFS: None
undefined4 __fastcall FUN_004cceb7(int param_1,char *param_2)
{
  char cVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  char *pcVar10;
  char cVar12;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  uint uVar11;
  short sVar13;
  int unaff_EBX;
  int iVar14;
  int iVar15;
  undefined4 *unaff_ESI;
  uint uVar16;
  int iVar17;
  char *pcVar18;
  char in_OF;
  undefined8 uVar19;
  short sStack_1c;
  short sStack_18;
  int iStack_14;
  int iStack_4;
  
  pcVar10 = (char *)*unaff_ESI;
  pcVar6 = (code *)swi(4);
  if (in_OF == '\x01') {
    uVar19 = (*pcVar6)();
    param_2 = (char *)((ulonglong)uVar19 >> 0x20);
    pcVar10 = (char *)uVar19;
    param_1 = extraout_ECX;
  }
  param_2[-0x32] = param_2[-0x32] + (char)unaff_EBX;
  cVar1 = *param_2;
  cVar12 = (char)((uint)param_1 >> 8);
  *param_2 = *param_2 + cVar12;
  pcVar6 = (code *)swi(4);
  if (SCARRY1(cVar1,cVar12)) {
    pcVar10 = (char *)(*pcVar6)();
    param_1 = extraout_ECX_00;
  }
  pcVar18 = (char *)(unaff_EBX + -0x4dffb332);
  cVar1 = *pcVar18;
  *pcVar18 = *pcVar18 + (char)param_1;
  pcVar6 = (code *)swi(4);
  if (SCARRY1(cVar1,(char)param_1)) {
    pcVar10 = (char *)(*pcVar6)();
    param_1 = extraout_ECX_01;
  }
  *pcVar10 = *pcVar10 + (char)pcVar10;
  iVar14 = CONCAT31((int3)((uint)pcVar10 >> 8),(char)pcVar10 + '\b');
  piVar4 = (int *)((int)&iStack_4 + iVar14);
  *piVar4 = *piVar4 + iVar14;
  iVar14 = *(int *)(param_1 + 8);
  sStack_18 = __ftol();
  sVar7 = __ftol();
  sStack_1c = __ftol();
  sVar8 = __ftol();
  iVar14 = *(int *)(*(int *)(iVar14 + 0xc) + 0x3c);
  iVar3 = *(int *)(iVar14 + 0x28);
  sVar2 = *(short *)(iVar14 + 0x3c);
  uVar16 = (uint)sVar2;
  pcVar10 = (char *)calloc(uVar16,1);
  if (0 < sVar2) {
    pcVar18 = pcVar10;
    for (uVar11 = uVar16 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      pcVar18[0] = '\0';
      pcVar18[1] = '\0';
      pcVar18[2] = '\0';
      pcVar18[3] = '\0';
      pcVar18 = pcVar18 + 4;
    }
    for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
      *pcVar18 = '\0';
      pcVar18 = pcVar18 + 1;
    }
  }
  if (sStack_18 < 0) {
    sStack_18 = 0;
  }
  if (sVar7 < 0) {
    sVar7 = 0;
  }
  if (*(int *)(iVar3 + 8) <= (int)sStack_1c) {
    sStack_1c = *(short *)(iVar3 + 8) + -1;
  }
  if (*(int *)(iVar3 + 0xc) <= (int)sVar8) {
    sVar8 = *(short *)(iVar3 + 0xc) + -1;
  }
  if (sVar7 <= sVar8) {
    iStack_14 = sVar7 * 4;
    iVar14 = ((int)sVar8 - (int)sVar7) + 1;
    do {
      if (sStack_18 <= sStack_1c) {
        iVar17 = sStack_18 * 0x18;
        iVar15 = ((int)sStack_1c - (int)sStack_18) + 1;
        do {
          for (piVar4 = *(int **)(*(int *)(iStack_14 + *(int *)(iVar3 + 0x8d8c)) + 0x10 + iVar17);
              piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
            iVar5 = *piVar4;
            sVar7 = *(short *)(*(int *)(iVar5 + 8) + 0x14);
            if ((((sVar7 != 1) && (sVar7 != 0xb)) && (sVar7 != 0x1e)) &&
               (*(char *)(iVar5 + 0x48) == '\x02')) {
              pcVar10[*(short *)(*(int *)(iVar5 + 0xc) + 0x4a)] =
                   pcVar10[*(short *)(*(int *)(iVar5 + 0xc) + 0x4a)] + '\x01';
            }
          }
          iVar17 = iVar17 + 0x18;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      iStack_14 = iStack_14 + 4;
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
  }
  sVar9 = 1;
  sVar7 = -1;
  sVar13 = 0;
  pcVar18 = pcVar10;
  sVar8 = 0;
  if (1 < sVar2) {
    do {
      sVar13 = sVar8;
      if (pcVar18[1] != '\0') {
        sVar13 = sVar13 + 1;
        sVar7 = sVar9;
      }
      sVar9 = sVar9 + 1;
      pcVar18 = pcVar18 + 1;
      sVar8 = sVar13;
    } while (sVar9 < sVar2);
  }
  free(pcVar10);
  if (((sVar13 == 1) && (0 < sVar7)) &&
     (iVar14 = *(int *)(*(int *)(param_1 + 8) + 0xc), sVar7 != *(short *)(iVar14 + 0x4a))) {
    return *(undefined4 *)(*(int *)(*(int *)(iVar14 + 0x3c) + 0x40) + sVar7 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004cd11f
// Address: 004cd11f
// XREFS: None
undefined4 __fastcall FUN_004cd11f(int *param_1)
{
  (**(code **)(*param_1 + 0x5c))(6);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cd12d
// Address: 004cd12d
// XREFS: None
undefined4 __thiscall
FUN_004cd12d(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)
{
  param_1[8] = param_3;
  param_1[9] = param_4;
  param_1[10] = param_5;
  (**(code **)(*param_1 + 0x5c))(4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cd154
// Address: 004cd154
// XREFS: None
undefined4 __thiscall FUN_004cd154(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  if (param_2 != 0) {
    param_1[4] = param_2;
    (**(code **)(*param_1 + 0x5c))(5);
    return 1;
  }
  param_1[8] = param_3;
  param_1[9] = param_4;
  param_1[10] = param_5;
  (**(code **)(*param_1 + 0x5c))(4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cd19e
// Address: 004cd19e
// XREFS: None
void __fastcall FUN_004cd19e(int *param_1)
{
  (**(code **)(*param_1 + 0x5c))(100);
  return;
}

// --------------------------------------------------

// Function: FUN_004cd1a8
// Address: 004cd1a8
// XREFS: None
RGE_Action * __thiscall FUN_004cd1a8(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  param_1->_padding_ = (int)&TRIBE_Action_Build::_vftable_;
  param_1->action_type = 0x65;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cd1d8
// Address: 004cd1d8
// XREFS: None
TRIBE_Action_Build * __thiscall FUN_004cd1d8(TRIBE_Action_Build *param_1,byte param_2)
{
  TRIBE_Action_Build::~TRIBE_Action_Build(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cd205
// Address: 004cd205
// XREFS: None
RGE_Action * __thiscall
FUN_004cd205(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fd88;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Build::_vftable_;
  param_1->action_type = 0x65;
  param_1->task = param_3;
  if ((param_4 == (RGE_Static_Object *)0x0) ||
     (*(short *)(param_2->_padding_ + 0x4a) == param_4->owner->id)) {
    RGE_Action::set_target_obj(param_1,param_4);
    param_1->target_x = param_4->world_x;
    param_1->target_y = param_4->world_y;
    param_1->target_z = param_4->world_z;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cd29e
// Address: 004cd29e
// XREFS: None
RGE_Action * __thiscall
FUN_004cd29e(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&TRIBE_Action_Build::_vftable_;
  param_1->action_type = 0x65;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cd2dd
// Address: 004cd2dd
// XREFS: None
void __thiscall FUN_004cd2dd(int *param_1,char param_2)
{
  if (param_2 == '\0') {
    (**(code **)(*param_1 + 0x5c))(3);
    return;
  }
  if (param_1[4] != 0) {
    (**(code **)(*param_1 + 0x5c))(4);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(3);
  return;
}

// --------------------------------------------------

// Function: FUN_004cd30d
// Address: 004cd30d
// XREFS: None
void __thiscall FUN_004cd30d(int *param_1,undefined1 param_2)
{
  int iVar1;
  int iVar2;
  RGE_Action_Move_To *pRVar3;
  RGE_Action *pRVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_ESI;
  int *unaff_FS_OFFSET;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fdb6;
  *unaff_FS_OFFSET = (int)&iStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
  *(undefined1 *)(param_1 + 3) = param_2;
  switch(param_2) {
  case 1:
  case 0xd:
    iVar6 = *(int *)param_1[2];
    uVar5 = *(undefined4 *)(((int *)param_1[2])[2] + 0x18);
    break;
  case 2:
    iVar6 = *(int *)(((int *)param_1[2])[2] + 0x18);
    (**(code **)(*(int *)param_1[2] + 0x38))();
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0x54))(0);
    (**(code **)(iVar1 + 0x58))(0);
    param_1[8] = -0x40800000;
    param_1[9] = -0x40800000;
    param_1[10] = -0x40800000;
    *unaff_FS_OFFSET = iVar6;
    return;
  case 3:
    iVar2 = RGE_Player::computerPlayer(*(RGE_Player **)(param_1[2] + 0xc));
    iVar6 = ((int *)param_1[2])[1];
    iVar1 = *(int *)param_1[2];
    if (iVar2 == 1) {
      (**(code **)(iVar1 + 0x148))(iVar6,iVar6,0x1fa);
      (**(code **)(*param_1 + 0x5c))(1);
      (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
      *unaff_FS_OFFSET = iVar6;
      return;
    }
    (**(code **)(iVar1 + 0x148))(iVar6,iVar6,0x202,0x25a,0,0);
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
    *unaff_FS_OFFSET = iVar6;
    return;
  case 4:
    iVar6 = param_1[4];
    if (iVar6 != 0) {
      param_1[8] = *(int *)(iVar6 + 0x38);
      param_1[9] = *(int *)(iVar6 + 0x3c);
      param_1[10] = *(int *)(iVar6 + 0x40);
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
                          *(float *)(param_1[0xc] + 0x24),*(RGE_Sprite **)(param_1[0xc] + 0x34));
    }
    uStack_4 = 0xffffffff;
    if (pRVar4 == (RGE_Action *)0x0) {
      (**(code **)(*param_1 + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],pRVar4);
    RGE_Action::setSubAction(pRVar4,'\x01');
    *unaff_FS_OFFSET = iStack_c;
    return;
  default:
    goto switchD_004cd347_caseD_5;
  case 6:
    iVar6 = *(int *)param_1[2];
    uVar5 = *(undefined4 *)(param_1[0xc] + 0x34);
    break;
  case 7:
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(param_1[0xc] + 0x38));
    if (*(RGE_Sound **)(param_1[0xc] + 0x44) != (RGE_Sound *)0x0) {
      RGE_Sound::play(*(RGE_Sound **)(param_1[0xc] + 0x44),1);
      *unaff_FS_OFFSET = iStack_c;
      return;
    }
    goto switchD_004cd347_caseD_5;
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
    *unaff_FS_OFFSET = iStack_c;
    return;
  }
  (**(code **)(iVar6 + 0x38))(uVar5);
switchD_004cd347_caseD_5:
  *unaff_FS_OFFSET = iStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004cd5a5
// Address: 004cd5a5
// XREFS: None
// Error: 
Low-level Error: Symbol $$undef0000000d extends beyond the end of the address space

// --------------------------------------------------

// Function: FUN_004cd91d
// Address: 004cd91d
// XREFS: None
undefined4 __thiscall
FUN_004cd91d(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)
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

// Function: FUN_004cd953
// Address: 004cd953
// XREFS: None
undefined4 __thiscall FUN_004cd953(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  
  if ((param_2 == 0) ||
     (*(short *)(*(int *)(param_2 + 0xc) + 0x4a) != *(short *)(*(int *)(param_1[2] + 0xc) + 0x4a)))
{
    iVar1 = *param_1;
    param_1[10] = param_5;
    param_1[8] = param_3;
    param_1[9] = param_4;
    (**(code **)(iVar1 + 0x54))(0);
    (**(code **)(iVar1 + 0x5c))(0xb);
  }
  else if ((param_2 != param_1[4]) || (((char)param_1[3] != '\x04' && ((char)param_1[3] != '\x06')))
          ) {
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0x54))(param_2);
    (**(code **)(iVar1 + 0x5c))(4);
    return 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004cd9d9
// Address: 004cd9d9
// XREFS: None
RGE_Action * __thiscall FUN_004cd9d9(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fdc8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  uStack_4 = 0;
  *(undefined4 *)&param_1[1].action_type = 0x3f800000;
  param_1->_padding_ = (int)&TRIBE_Action_Convert::_vftable_;
  param_1->action_type = 0x68;
  rge_read(param_2,param_1 + 1,1);
  rge_read(param_2,&param_1[1].action_type,4);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cda5e
// Address: 004cda5e
// XREFS: None
TRIBE_Action_Convert * __thiscall FUN_004cda5e(TRIBE_Action_Convert *param_1,byte param_2)
{
  TRIBE_Action_Convert::~TRIBE_Action_Convert(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cda85
// Address: 004cda85
// XREFS: None
RGE_Action * __thiscall
FUN_004cda85(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fde8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  uStack_4 = 0;
  *(undefined4 *)&param_1[1].action_type = 0x3f800000;
  param_1->_padding_ = (int)&TRIBE_Action_Convert::_vftable_;
  param_1->action_type = 0x68;
  RGE_Action::set_target_obj(param_1,param_4);
  if (param_4 != (RGE_Static_Object *)0x0) {
    param_1->target_x = param_4->world_x;
    param_1->target_y = param_4->world_y;
    param_1->target_z = param_4->world_z;
  }
  *(undefined1 *)&param_1[1]._padding_ = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cdb17
// Address: 004cdb17
// XREFS: None
RGE_Action * __thiscall
FUN_004cdb17(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  *(undefined4 *)&param_1[1].action_type = 0x3f800000;
  param_1->_padding_ = (int)&TRIBE_Action_Convert::_vftable_;
  param_1->action_type = 0x68;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cdb68
// Address: 004cdb68
// XREFS: None
void __thiscall FUN_004cdb68(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,1);
  rge_write(param_2,&param_1[1].action_type,4);
  return;
}

// --------------------------------------------------

// Function: FUN_004cdba1
// Address: 004cdba1
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cdba1(int *param_1,char param_2)
{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1[4];
  if (iVar4 != 0) {
    iVar3 = param_1[2];
    sVar1 = *(short *)(*(int *)(iVar4 + 8) + 0x14);
    if (*(int *)(iVar4 + 0xc) == *(int *)(iVar3 + 0xc)) {
      *(undefined1 *)(param_1 + 0x10) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x10) = 0;
    }
    sVar2 = *(short *)(*(int *)(iVar4 + 8) + 0x10);
    if (((((sVar2 == 0x6d) || (sVar1 == 0x1b)) || (sVar2 == 0x9f)) ||
        ((sVar2 == 0x9e || (sVar2 == 0xa3)))) || (sVar2 == 0x114)) {
      iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(iVar3 + 0xc));
      if (iVar4 == 1) {
        (**(code **)(*param_1 + 0x5c))(0xb);
      }
      else {
        (**(code **)(*param_1 + 0x5c))(0xd);
      }
      sVar1 = *(short *)(*(int *)(param_1[4] + 8) + 0x10);
      if (sVar1 != 0x6d) {
        if (sVar1 != 0x114) {
          return;
        }
        (**(code **)(rge_base_game->_padding_ + 0x40))
                  (0x7a,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),0,0,0);
        return;
      }
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x79,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),0,0,0);
      return;
    }
    if (*(float *)(iVar3 + 0x44) < (float)_DAT_00574ff0) {
      (**(code **)(*param_1 + 0x5c))(0xd);
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x76,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),0,0,0);
      return;
    }
    if (sVar1 == 3) {
      param_1[0x11] = 0x3f800000;
    }
    else {
      param_1[0x11] = *(int *)(*(int *)(iVar3 + 8) + 0x114);
    }
    if (sVar1 == 0x1e) {
      (**(code **)(*param_1 + 0x5c))(0xd);
      return;
    }
    if ((sVar1 == 0x12) && ((*(RGE_Player **)(iVar3 + 0xc))->attributes[0x1b] <= _DAT_00574ff8)) {
      iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(iVar3 + 0xc));
      if (iVar4 == 1) {
        (**(code **)(*param_1 + 0x5c))(0xb);
      }
      else {
        (**(code **)(*param_1 + 0x5c))(0xd);
      }
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x77,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),0,0,0);
      return;
    }
    if ((sVar1 == 3) && ((*(RGE_Player **)(iVar3 + 0xc))->attributes[0x1c] <= _DAT_00574ff8)) {
      iVar4 = RGE_Player::computerPlayer(*(RGE_Player **)(iVar3 + 0xc));
      if (iVar4 == 1) {
        (**(code **)(*param_1 + 0x5c))(0xb);
      }
      else {
        (**(code **)(*param_1 + 0x5c))(0xd);
      }
      (**(code **)(rge_base_game->_padding_ + 0x40))
                (0x78,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),0,0,0);
      return;
    }
  }
  if (param_2 == '\0') {
    (**(code **)(*param_1 + 0x5c))(3);
    return;
  }
  if (iVar4 == 0) {
    (**(code **)(*param_1 + 0x5c))(3);
    return;
  }
  (**(code **)(*param_1 + 0x5c))(4);
  return;
}

// --------------------------------------------------

// Function: FUN_004cde03
// Address: 004cde03
// XREFS: None
void __thiscall FUN_004cde03(int *param_1,undefined1 param_2)
{
  int *piVar1;
  int iVar2;
  RGE_Action_Move_To *pRVar3;
  RGE_Action *pRVar4;
  undefined4 uVar5;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe16;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
  *(undefined1 *)(param_1 + 3) = param_2;
  switch(param_2) {
  case 3:
    iVar2 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar2,iVar2,0x202,0x25c,0,0);
  case 1:
  case 2:
  case 0xd:
  case 0xe:
    iVar2 = *(int *)param_1[2];
    uVar5 = *(undefined4 *)(((int *)param_1[2])[2] + 0x18);
    break;
  case 4:
    iVar2 = param_1[4];
    param_1[8] = *(int *)(iVar2 + 0x38);
    param_1[9] = *(int *)(iVar2 + 0x3c);
    param_1[10] = *(int *)(iVar2 + 0x40);
    pRVar3 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 1;
    if (pRVar3 == (RGE_Action_Move_To *)0x0) {
      pRVar4 = (RGE_Action *)0x0;
    }
    else {
      pRVar4 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar3,(RGE_Action_Object *)param_1[2],(RGE_Static_Object *)param_1[4],
                          (float)param_1[0x11],*(RGE_Sprite **)(param_1[0xc] + 0x34));
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
    goto switchD_004cde43_caseD_5;
  case 6:
    iVar2 = *(int *)param_1[2];
    uVar5 = *(undefined4 *)(param_1[0xc] + 0x34);
    break;
  case 7:
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(param_1[0xc] + 0x38));
    if (*(RGE_Sound **)(param_1[0xc] + 0x44) != (RGE_Sound *)0x0) {
      RGE_Sound::play(*(RGE_Sound **)(param_1[0xc] + 0x44),1);
    }
    if ((param_1[4] != 0) &&
       (piVar1 = *(int **)(param_1[4] + 0xc), 0 < *(short *)((int)piVar1 + 0x4a))) {
      iVar2 = param_1[2];
      (**(code **)(*piVar1 + 0x94))
                (0x70,*(undefined4 *)(iVar2 + 0x38),*(undefined4 *)(iVar2 + 0x3c),
                 *(undefined4 *)(iVar2 + 0x40),0);
    }
    param_1[0xb] = *(int *)(param_1[0xc] + 0x20);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
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
                          ,(float)param_1[10],(float)param_1[0x11],
                          *(RGE_Sprite **)(param_1[0xc] + 0x34));
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
  (**(code **)(iVar2 + 0x38))(uVar5);
switchD_004cde43_caseD_5:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004ce02d
// Address: 004ce02d
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_tact_cnv_c: "C:\msdev\work\age1_x1\tact_cnv.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004ce02d(int *param_1)
{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  float fVar4;
  char cVar5;
  int in_EAX;
  RGE_Static_Object *pRVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  float10 in_ST0;
  float10 in_ST1;
  float10 in_ST2;
  
  *(short *)(in_EAX * 2 + 0x77) =
       (short)(in_ST0 * (float10)*(short *)(in_EAX * 2 + 0x4a) *
              (float10)*(short *)(in_EAX * 2 + 0x19));
  *(short *)(in_EAX * 2 + -0x3b) = (short)(in_ST1 * (float10)*(short *)(in_EAX * 2 + -0x4b));
  *(short *)(in_EAX * 2 + 0x77) = (short)in_ST2;
  if ((param_1[6] != -1) &&
     (pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1[2] + 0xc) + 0x3c),param_1[6]),
     pRVar6 == (RGE_Static_Object *)0x0)) {
LAB_004ce0c6:
    iVar7 = *param_1;
    (**(code **)(iVar7 + 0x54))(0);
    (**(code **)(iVar7 + 0x5c))(3);
    return 0;
  }
  if ((param_1[7] != -1) &&
     (pRVar6 = RGE_Game_World::object
                         (*(RGE_Game_World **)(*(int *)(param_1[2] + 0xc) + 0x3c),param_1[7]),
     pRVar6 == (RGE_Static_Object *)0x0)) {
    (**(code **)(*param_1 + 0x58))(0);
  }
  iVar7 = param_1[4];
  if (iVar7 != 0) {
    if (*(char *)(iVar7 + 0x48) != '\x02') goto LAB_004ce0c6;
    if ((iVar7 != 0) &&
       (iVar7 = (**(code **)(**(int **)(param_1[2] + 0xc) + 0x1c))
                          ((int)*(short *)(*(int *)(iVar7 + 0xc) + 0x4a)), iVar7 == 1)) {
      cVar5 = (char)param_1[3];
      if ((cVar5 == '\a') || ((cVar5 == '\x06' || (cVar5 == '\x04')))) {
        (**(code **)(*(int *)param_1[2] + 0x80))(0x22,0);
      }
      (**(code **)(*param_1 + 0x5c))(1);
      iVar7 = ((int *)param_1[2])[1];
      (**(code **)(*(int *)param_1[2] + 0x148))(iVar7,iVar7,0x1fb,0x25c,0,0);
      return 4;
    }
  }
  switch((char)param_1[3]) {
  case '\x01':
    return 1;
  case '\x04':
    uVar8 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    switch((uVar8 & 0xff) - 1) {
    case 0:
    case 1:
      (**(code **)(*param_1 + 0x5c))(6);
      return 0;
    case 2:
      (**(code **)(*param_1 + 0x5c))(0xd);
      return 0;
    case 3:
    case 4:
switchD_004ce17c_caseD_3:
      iVar7 = *param_1;
      (**(code **)(iVar7 + 0x54))(0);
      (**(code **)(iVar7 + 0x5c))(0xb);
      return 0;
    }
    break;
  case '\x06':
    if (param_1[4] == 0) {
      (**(code **)(*param_1 + 0x5c))(3);
      return 0;
    }
    cVar5 = (**(code **)(*(int *)param_1[2] + 0x1f0))(param_1[4],0,0);
    if (cVar5 != '\0') {
      (**(code **)(*param_1 + 0x5c))(7);
      return 0;
    }
    break;
  case '\a':
    piVar2 = (int *)param_1[4];
    if (piVar2 == (int *)0x0) {
switchD_004ce17c_caseD_0:
      (**(code **)(*param_1 + 0x5c))(3);
      return 0;
    }
    uVar3 = *(undefined4 *)(param_1[2] + 4);
    iVar7 = *piVar2;
    uVar9 = __ftol((int)*(short *)(piVar2[2] + 0x26));
    (**(code **)(iVar7 + 0x148))(uVar3,piVar2[1],500,uVar3,uVar9);
    iVar7 = param_1[2];
    fVar4 = (float)param_1[0xb] - *(float *)(*(int *)(*(int *)(iVar7 + 0xc) + 0x3c) + 0x84);
    param_1[0xb] = (int)fVar4;
    if (fVar4 <= _DAT_00574ff8) {
      if ((param_1[4] != 0) &&
         (piVar2 = *(int **)(param_1[4] + 0xc), 0 < *(short *)((int)piVar2 + 0x4a))) {
        (**(code **)(*piVar2 + 0x94))
                  (0x70,*(undefined4 *)(iVar7 + 0x38),*(undefined4 *)(iVar7 + 0x3c),
                   *(undefined4 *)(iVar7 + 0x40),0);
      }
      iVar10 = debug_rand(s_C__msdev_work_age1_x1_tact_cnv_c,0x1d7);
      iVar7 = *(int *)(param_1[4] + 0xc);
      fVar4 = (float)iVar10 * _DAT_00574ffc;
      if (*(char *)(iVar7 + 0x105) == '\x10') {
        fVar4 = fVar4 * _DAT_00575000;
      }
      else {
        sVar1 = *(short *)(*(int *)(param_1[4] + 8) + 0x14);
        if ((((sVar1 == 0x15) || (sVar1 == 2)) || (sVar1 == 0x14)) ||
           ((sVar1 == 0x16 || (sVar1 == 0x12)))) {
          fVar4 = fVar4 + fVar4;
        }
        else if ((sVar1 == 0x23) || (sVar1 == 0x17)) {
          fVar4 = fVar4 * _DAT_00575004;
        }
      }
      if (fVar4 <= *(float *)(param_1[0xc] + 0x1c) * *(float *)(*(int *)(param_1[2] + 8) + 0xe4)) {
        (**(code **)(rge_base_game->_padding_ + 0x40))
                  (0x7b,(int)*(short *)(*(int *)(param_1[2] + 0xc) + 0x4a),
                   (int)*(short *)(iVar7 + 0x4a),0,0);
        (**(code **)(*(int *)param_1[4] + 0x44))(*(undefined4 *)(param_1[2] + 0xc));
        (**(code **)(**(int **)(param_1[2] + 0xc) + 0x78))(0x29,0x3f800000,0);
        (**(code **)(*(int *)param_1[2] + 0x80))(0x22,0);
        (**(code **)(*param_1 + 0x5c))(3);
      }
      (**(code **)(*param_1 + 0x5c))(4);
      return 0;
    }
    break;
  case '\v':
    uVar8 = (**(code **)(*(int *)param_1[0xd] + 0xc))();
    switch((uVar8 & 0xff) - 1) {
    case 0:
    case 1:
    case 4:
      goto switchD_004ce17c_caseD_0;
    case 2:
      (**(code **)(*param_1 + 0x5c))(0xd);
      return 0;
    case 3:
      goto switchD_004ce17c_caseD_3;
    }
    break;
  case '\r':
    iVar7 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar7,iVar7,0x1f9,0x25c,0,0);
    (**(code **)(*param_1 + 0x5c))(2);
    return 3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004ce3fa
// Address: 004ce3fa
// XREFS: None
/* WARNING: Instruction at (ram,0x004ce49b) overlaps instruction at (ram,0x004ce49a)
    */

int __fastcall FUN_004ce3fa(int param_1,int param_2)
{
  byte *pbVar1;
  byte bVar2;
  undefined4 in_EAX;
  char *pcVar3;
  int iVar4;
  int *piVar6;
  int iVar7;
  char cVar8;
  byte bVar10;
  undefined3 uVar11;
  int iVar12;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  char in_ZF;
  bool bVar13;
  int in_stack_00000010;
  char cVar5;
  char *pcVar9;
  
  iVar12 = -0x6bffb31d;
  piVar6 = (int *)(param_1 + -1);
  if (piVar6 == (int *)0x0 || in_ZF == '\0') {
    bVar2 = (byte)in_EAX;
    cVar5 = (char)((uint)in_EAX >> 8) + (char)((uint)piVar6 >> 8);
    pcVar3 = (char *)CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar5,bVar2));
    piVar6 = (int *)(param_1 + -2);
    if (piVar6 != (int *)0x0 && cVar5 == '\0') goto code_r0x004ce453;
    cRam65004ce2 = cRam65004ce2 + (char)((uint)piVar6 >> 8);
    bVar13 = cRam65004ce2 == '\0';
    if (param_1 != 3 && bVar13) goto code_r0x004ce45b;
    cVar5 = bVar2 - 0x1d;
    bVar10 = (byte)((uint)param_2 >> 8);
    if (param_1 == 3) {
      *(char *)(unaff_EBP + 0x1a) = *(char *)(unaff_EBP + 0x1a) + bVar10 + (0x1c < bVar2);
      goto code_r0x004ce462;
    }
    uVar11 = (undefined3)((uint)param_2 >> 8);
    cVar8 = (char)param_2 + bVar10;
    pcVar9 = (char *)CONCAT31(uVar11,cVar8);
    if (param_1 != 3) {
      *pcVar3 = *pcVar3 + bVar2;
      *unaff_ESI = (int)(pcVar3 + *unaff_ESI);
      iVar4 = CONCAT31((int3)((uint)pcVar3 >> 8),bVar2 + *(char *)CONCAT31(0x94004c,cVar5) + '\x06')
              + 0x34ff8b90;
      if (param_1 != 4) {
        return iVar4;
      }
      *pcVar9 = *pcVar9 + bVar10;
      pcVar3 = (char *)CONCAT31(0x94004c,cVar5) + -0x4dffb31f;
      *pcVar3 = *pcVar3 + (char)iVar4;
      if (*pcVar3 != '\0') {
        *pcVar9 = *pcVar9 + bVar10;
        iVar12 = CONCAT31(0x94004c,cVar5 * '\x02');
        iVar7 = -2;
        if ((char)(cVar5 * '\x02') == '\0') {
          *(byte *)(iVar12 + 0x4e893c4f) = *(byte *)(iVar12 + 0x4e893c4f) & 0xfe;
          goto code_r0x004ce48f;
        }
        iVar12 = CONCAT31(0x94004c,cVar5 * '\x04');
        iVar7 = -3;
        if ((char)(cVar5 * '\x04') == '\0') goto code_r0x004ce48f;
        cVar8 = cVar8 + -3;
        param_2 = CONCAT31(uVar11,cVar8);
        iVar7 = -4;
        if (cVar8 == '\0') goto code_r0x004ce48f;
        pbVar1 = (byte *)(param_2 + -0x4dffb31f);
        bVar2 = *pbVar1;
        *pbVar1 = *pbVar1 + bVar10;
        piVar6 = (int *)&DAT_fffffffb;
        if (*pbVar1 == 0) {
          cVar5 = ((char)iVar4 + 'H') - CARRY1(bVar2,bVar10);
          piVar6 = (int *)CONCAT31((int3)((uint)iVar4 >> 8),cVar5);
          *piVar6 = (int)(*piVar6 + (int)piVar6);
          *(char *)piVar6 = (char)*piVar6 + cVar5;
          return 1;
        }
        goto code_r0x004ce44f;
      }
      goto LAB_004ce47c;
    }
    unaff_ESI = (int *)((int)unaff_ESI + 1);
    bVar2 = (bVar2 | 0x3c) + 0x74 ^ 0x3c;
code_r0x004ce469:
    if (bVar2 == 6) {
      return 1;
    }
    if (bVar2 == 7) {
      return 1;
    }
  }
  else {
code_r0x004ce44f:
    *(char *)(iVar12 + 0x56) = *(char *)(iVar12 + 0x56) + (char)param_2;
code_r0x004ce453:
    bVar13 = in_stack_00000010 == 0;
    unaff_ESI = piVar6;
    unaff_EDI = in_stack_00000010;
code_r0x004ce45b:
    if (bVar13) {
      return 0;
    }
    if (unaff_EDI == unaff_ESI[4]) {
code_r0x004ce462:
      bVar2 = *(byte *)(unaff_ESI + 3);
      if (bVar2 == 4) {
        return 1;
      }
      goto code_r0x004ce469;
    }
  }
LAB_004ce47c:
  iVar12 = *unaff_ESI;
  (**(code **)(iVar12 + 0x54))(unaff_EDI);
  unaff_ESI[8] = *(int *)(unaff_EDI + 0x38);
  iVar7 = *(int *)(unaff_EDI + 0x3c);
code_r0x004ce48f:
  unaff_ESI[9] = iVar7;
  unaff_ESI[10] = *(int *)(unaff_EDI + 0x40);
  (**(code **)(iVar12 + 0x1c))();
  return 1;
}

// --------------------------------------------------

// Function: FUN_004ce52b
// Address: 004ce52b
// XREFS: None
RGE_Action * __thiscall FUN_004ce52b(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  RGE_Action_Object *pRVar1;
  void *pvVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  param_1->_padding_ = (int)&TRIBE_Action_Discovery_Artifact::_vftable_;
  param_1->action_type = 0x6c;
  uStack_4 = 0;
  pvVar2 = (void *)calloc((int)*(short *)(*(int *)(param_1->obj->_padding_ + 0x3c) + 0x3c),1);
  pRVar1 = param_1->obj;
  param_1[1]._padding_ = (int)pvVar2;
  rge_read(param_2,pvVar2,(int)*(short *)(*(int *)(pRVar1->_padding_ + 0x3c) + 0x3c));
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ce5bb
// Address: 004ce5bb
// XREFS: None
TRIBE_Action_Discovery_Artifact * __thiscall
FUN_004ce5bb(TRIBE_Action_Discovery_Artifact *param_1,byte param_2)
{
  TRIBE_Action_Discovery_Artifact::~TRIBE_Action_Discovery_Artifact(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ce5e5
// Address: 004ce5e5
// XREFS: None
RGE_Action * __thiscall
FUN_004ce5e5(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Discovery_Artifact::_vftable_;
  param_1->action_type = 0x6c;
  RGE_Action::set_target_obj(param_1,param_4);
  iVar1 = calloc((int)*(short *)(*(int *)(param_1->obj->_padding_ + 0x3c) + 0x3c),1);
  param_1[1]._padding_ = iVar1;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ce66f
// Address: 004ce66f
// XREFS: None
RGE_Action * __thiscall
FUN_004ce66f(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  int iVar1;
  
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_x = param_4;
  param_1->_padding_ = (int)&TRIBE_Action_Discovery_Artifact::_vftable_;
  param_1->action_type = 0x6c;
  param_1->target_y = param_5;
  param_1->target_z = param_6;
  iVar1 = calloc((int)*(short *)(*(int *)(param_1->obj->_padding_ + 0x3c) + 0x3c),1);
  param_1[1]._padding_ = iVar1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ce6c8
// Address: 004ce6c8
// XREFS: None
void __thiscall FUN_004ce6c8(RGE_Action *param_1,int param_2)
{
  RGE_Action::save(param_1,param_2);
  rge_write(param_2,(void *)param_1[1]._padding_,
            (int)*(short *)(*(int *)(param_1->obj->_padding_ + 0x3c) + 0x3c));
  return;
}

// --------------------------------------------------

// Function: FUN_004ce6fe
// Address: 004ce6fe
// XREFS: None
void __thiscall FUN_004ce6fe(int *param_1,char param_2)
{
  if (param_2 != '\0') {
    (**(code **)(*param_1 + 0x5c))(6);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ce712
// Address: 004ce712
// XREFS: None
void __thiscall FUN_004ce712(int param_1,char param_2)
{
  *(char *)(param_1 + 0xc) = param_2;
  if (param_2 == '\n') {
    *(undefined4 *)(param_1 + 0x2c) = 0x40400000;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ce735
// Address: 004ce735
// XREFS: None
uint __fastcall FUN_004ce735(TRIBE_Action_Discovery_Artifact *param_1)
{
  float fVar1;
  float fVar2;
  uint uVar3;
  
  uVar3 = (uint)(byte)param_1->_padding_;
  if (uVar3 == 1) {
    return 1;
  }
  if (uVar3 == 6) {
    TRIBE_Action_Discovery_Artifact::check_objects(param_1);
    uVar3 = (**(code **)(param_1->_padding_ + 0x5c))(10);
  }
  else {
    uVar3 = uVar3 - 10;
    if (uVar3 == 0) {
      fVar1 = (float)param_1->_padding_ -
              *(float *)(*(int *)(*(int *)(param_1->_padding_ + 0xc) + 0x3c) + 0x84);
      fVar2 = (float)(double)DAT_00575070;
      param_1->_padding_ = (int)fVar1;
      uVar3 = CONCAT22((short)((uint)param_1->_padding_ >> 0x10),
                       (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                       (ushort)(fVar1 == fVar2) << 0xe);
      if (fVar1 < fVar2 || (fVar1 == fVar2) != 0) {
        uVar3 = (**(code **)(param_1->_padding_ + 0x5c))(6);
        return uVar3 & 0xffffff00;
      }
    }
  }
  return uVar3 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004ce79c
// Address: 004ce79c
// XREFS: None
void __fastcall FUN_004ce79c(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  short sStack_1c;
  short sStack_18;
  int iStack_14;
  int iStack_c;
  
  iVar1 = *(int *)(param_1 + 8);
  sStack_1c = __ftol();
  sVar4 = __ftol();
  sStack_18 = __ftol();
  sVar5 = __ftol();
  iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0xc) + 0x3c) + 0x28);
  if (sStack_1c < 0) {
    sStack_1c = 0;
  }
  if (sVar4 < 0) {
    sVar4 = 0;
  }
  if (*(int *)(iVar1 + 8) <= (int)sStack_18) {
    sStack_18 = *(short *)(iVar1 + 8) + -1;
  }
  if (*(int *)(iVar1 + 0xc) <= (int)sVar5) {
    sVar5 = *(short *)(iVar1 + 0xc) + -1;
  }
  if (sVar4 <= sVar5) {
    iStack_14 = sVar4 * 4;
    iStack_c = ((int)sVar5 - (int)sVar4) + 1;
    do {
      if (sStack_1c <= sStack_18) {
        iVar8 = sStack_1c * 0x18;
        iVar7 = ((int)sStack_18 - (int)sStack_1c) + 1;
        do {
          for (piVar2 = *(int **)(*(int *)(iStack_14 + *(int *)(iVar1 + 0x8d8c)) + 0x10 + iVar8);
              piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
            if ((*(int *)(*piVar2 + 0xc) != *(int *)(*(int *)(param_1 + 8) + 0xc)) &&
               (pcVar6 = (char *)((int)*(short *)(*(int *)(*piVar2 + 0xc) + 0x4a) +
                                 *(int *)(param_1 + 0x40)), *pcVar6 == '\0')) {
              *pcVar6 = '\x01';
              iVar3 = *piVar2;
              (**(code **)(**(int **)(*(int *)(*(int *)(iVar3 + 0xc) + 0x24) + 0x288) + 0x18))
                        (*(int *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x38),
                         *(undefined4 *)(iVar3 + 0x3c),*(undefined4 *)(iVar3 + 0x40));
            }
          }
          iVar8 = iVar8 + 0x18;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      iStack_14 = iStack_14 + 4;
      iStack_c = iStack_c + -1;
    } while (iStack_c != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004ce922
// Address: 004ce922
// XREFS: None
RGE_Action * __thiscall FUN_004ce922(RGE_Action *param_1,int param_2,RGE_Action_Object *param_3)
{
  RGE_Action::RGE_Action(param_1,param_2,param_3,1);
  param_1->_padding_ = (int)&TRIBE_Action_Heal::_vftable_;
  param_1->action_type = 0x69;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ce958
// Address: 004ce958
// XREFS: None
TRIBE_Action_Heal * __thiscall FUN_004ce958(TRIBE_Action_Heal *param_1,byte param_2)
{
  TRIBE_Action_Heal::~TRIBE_Action_Heal(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004ce985
// Address: 004ce985
// XREFS: None
RGE_Action * __thiscall
FUN_004ce985(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,
            RGE_Static_Object *param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe68;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  uStack_4 = 0;
  param_1->_padding_ = (int)&TRIBE_Action_Heal::_vftable_;
  param_1->action_type = 0x69;
  RGE_Action::set_target_obj(param_1,param_4);
  param_1->target_x = param_4->world_x;
  param_1->target_y = param_4->world_y;
  param_1->target_z = param_4->world_z;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cea08
// Address: 004cea08
// XREFS: None
RGE_Action * __thiscall
FUN_004cea08(RGE_Action *param_1,RGE_Action_Object *param_2,RGE_Task *param_3,float param_4,
            float param_5,float param_6)
{
  RGE_Action::RGE_Action(param_1,param_2,1);
  param_1->task = param_3;
  param_1->target_y = param_5;
  param_1->_padding_ = (int)&TRIBE_Action_Heal::_vftable_;
  param_1->action_type = 0x69;
  param_1->target_x = param_4;
  param_1->target_z = param_6;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004cea4d
// Address: 004cea4d
// XREFS: None
void __fastcall FUN_004cea4d(int *param_1)
{
  short sVar1;
  
  if (param_1[4] == 0) {
    (**(code **)(*param_1 + 0x5c))(3);
  }
  else {
    sVar1 = *(short *)(*(int *)(param_1[4] + 8) + 0x14);
    if ((((sVar1 != 0x15) && (sVar1 != 2)) && (sVar1 != 0x14)) && (sVar1 != 0x16)) {
      (**(code **)(*param_1 + 0x5c))(4);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004cea8a
// Address: 004cea8a
// XREFS: None
void __thiscall FUN_004cea8a(int *param_1,undefined1 param_2)
{
  int iVar1;
  RGE_Action_Move_To *pRVar2;
  RGE_Action *pRVar3;
  int unaff_ESI;
  int *unaff_FS_OFFSET;
  int iVar4;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055fe96;
  *unaff_FS_OFFSET = (int)&iStack_c;
  RGE_Action_List::delete_list((RGE_Action_List *)param_1[0xd]);
  *(undefined1 *)(param_1 + 3) = param_2;
  switch(param_2) {
  case 2:
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  case 3:
    iVar4 = ((int *)param_1[2])[1];
    (**(code **)(*(int *)param_1[2] + 0x148))(iVar4,iVar4,0x202,0x25b,0,0);
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(((int *)param_1[2])[2] + 0x18));
    *unaff_FS_OFFSET = iVar4;
    return;
  case 4:
    break;
  case 6:
    iVar4 = param_1[4];
    param_1[8] = *(int *)(iVar4 + 0x38);
    param_1[9] = *(int *)(iVar4 + 0x3c);
    iVar1 = *(int *)param_1[2];
    param_1[10] = *(int *)(iVar4 + 0x40);
    (**(code **)(iVar1 + 0x38))(*(undefined4 *)(param_1[0xc] + 0x34));
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  case 7:
    (**(code **)(*(int *)param_1[2] + 0x38))(*(undefined4 *)(param_1[0xc] + 0x38));
    if (*(RGE_Sound **)(param_1[0xc] + 0x44) != (RGE_Sound *)0x0) {
      RGE_Sound::play(*(RGE_Sound **)(param_1[0xc] + 0x44),1);
    }
  default:
    *unaff_FS_OFFSET = iStack_c;
    return;
  case 0xb:
    pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
    uStack_4 = 0;
    if (pRVar2 == (RGE_Action_Move_To *)0x0) {
      pRVar3 = (RGE_Action *)0x0;
    }
    else {
      pRVar3 = (RGE_Action *)
               RGE_Action_Move_To::RGE_Action_Move_To
                         (pRVar2,(RGE_Action_Object *)param_1[2],(float)param_1[8],(float)param_1[9]
                          ,(float)param_1[10],0.0,*(RGE_Sprite **)(param_1[0xc] + 0x34));
    }
    uStack_4 = 0xffffffff;
    if (pRVar3 == (RGE_Action *)0x0) {
      (**(code **)(*param_1 + 0x5c))(0xd);
      *unaff_FS_OFFSET = unaff_ESI;
      return;
    }
    RGE_Action::setSubAction(pRVar3,'\x01');
    RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],pRVar3);
    *unaff_FS_OFFSET = iStack_c;
    return;
  }
  iVar4 = param_1[4];
  param_1[8] = *(int *)(iVar4 + 0x38);
  param_1[9] = *(int *)(iVar4 + 0x3c);
  param_1[10] = *(int *)(iVar4 + 0x40);
  pRVar2 = (RGE_Action_Move_To *)operator_new(0x44);
  uStack_4 = 1;
  if (pRVar2 == (RGE_Action_Move_To *)0x0) {
    pRVar3 = (RGE_Action *)0x0;
  }
  else {
    pRVar3 = (RGE_Action *)
             RGE_Action_Move_To::RGE_Action_Move_To
                       (pRVar2,(RGE_Action_Object *)param_1[2],(RGE_Static_Object *)param_1[4],0.4,
                        *(RGE_Sprite **)(param_1[0xc] + 0x34));
  }
  uStack_4 = 0xffffffff;
  if (pRVar3 == (RGE_Action *)0x0) {
    (**(code **)(*param_1 + 0x5c))(0xd);
    *unaff_FS_OFFSET = unaff_ESI;
    return;
  }
  RGE_Action_List::add_action((RGE_Action_List *)param_1[0xd],pRVar3);
  RGE_Action::setSubAction(pRVar3,'\x01');
  *unaff_FS_OFFSET = iStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004cecc6
// Address: 004cecc6
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void FUN_004cecc6(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_004cefd3
// Address: 004cefd3
// XREFS: None
undefined4 FUN_004cefd3(void)
{
  char *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  int *piVar5;
  char cVar7;
  undefined2 uVar8;
  undefined3 uVar9;
  char cVar10;
  char *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  char *unaff_EDI;
  undefined8 uVar11;
  int iStack_20;
  char cVar6;
  
  uVar11 = func_0xe9004cef();
  pcVar2 = (char *)uVar11;
  cVar6 = (char)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX + cVar6;
  uVar8 = (undefined2)((ulonglong)uVar11 >> 0x20);
  out(uVar8,(char)uVar11);
  pcVar2[-0x12] = pcVar2[-0x12] + cVar6;
  pcVar1 = (char *)(unaff_EBP * 9 + -0x105fffb4);
  *pcVar1 = *pcVar1 + cVar6;
  cVar6 = (char)((uint)extraout_ECX >> 8) + (char)extraout_ECX;
  piVar5 = (int *)CONCAT22((short)((uint)extraout_ECX >> 0x10),CONCAT11(cVar6,(char)extraout_ECX));
  out(uVar8,pcVar2);
  *pcVar2 = *pcVar2 + (char)uVar11;
  *unaff_ESI = (int)(pcVar2 + *unaff_ESI);
  in(uVar8);
  uVar9 = (undefined3)((ulonglong)uVar11 >> 0x28);
  cVar10 = (char)unaff_EBX;
  cVar7 = (char)((ulonglong)uVar11 >> 0x20) + cVar10;
  uVar8 = (undefined2)CONCAT31(uVar9,cVar7);
  uVar3 = in(uVar8);
  cRam07004cee = cRam07004cee + cVar10;
  out(uVar8,(char)uVar3);
  cVar7 = cVar7 + cVar10;
  uVar8 = (undefined2)CONCAT31(uVar9,cVar7);
  iVar4 = in(uVar8);
  *(char *)(unaff_ESI + unaff_EBP * 2) = (char)unaff_ESI[unaff_EBP * 2] + cVar6;
  *(char *)(unaff_ESI + unaff_EBP * 2) = (char)unaff_ESI[unaff_EBP * 2] + cVar6;
  cRam07004cee = cRam07004cee + cVar10;
  cVar6 = (char)iVar4;
  out(uVar8,cVar6);
  *unaff_EDI = *unaff_EDI + cVar6;
  out(uVar8,cVar6);
  *(char *)(iVar4 + -0x6f6f6f70) = *(char *)(iVar4 + -0x6f6f6f70) + cVar7;
  if (iStack_20 == 0) {
    return 0;
  }
  if (iStack_20 == piVar5[4]) {
    cVar6 = (char)piVar5[3];
    if (cVar6 == '\x04') {
      return 1;
    }
    if (cVar6 == '\x06') {
      return 1;
    }
    if (cVar6 == '\a') {
      return 1;
    }
  }
  iVar4 = *piVar5;
  (**(code **)(iVar4 + 0x54))(iStack_20);
  piVar5[8] = *(int *)(iStack_20 + 0x38);
  piVar5[9] = *(int *)(iStack_20 + 0x3c);
  piVar5[10] = *(int *)(iStack_20 + 0x40);
  (**(code **)(iVar4 + 0x1c))(1);
  return 1;
}

// --------------------------------------------------


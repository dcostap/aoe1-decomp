// GLOBAL FUNCTIONS PART 5400
// Function: FUN_00540678
// Address: 00540678
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00540678(int param_1,float *param_2)
{
  float fVar1;
  
  if (_DAT_00577908 <= *param_2) {
    fVar1 = (float)*(int *)(*(int *)(param_1 + 0x104) + 8);
    if (fVar1 <= *param_2) {
      *param_2 = fVar1 - _DAT_00577900;
    }
  }
  else {
    *param_2 = 0.0;
  }
  if (_DAT_00577908 <= param_2[1]) {
    fVar1 = (float)*(int *)(*(int *)(param_1 + 0x104) + 0xc);
    if (param_2[1] < fVar1) {
      return;
    }
    param_2[1] = fVar1 - _DAT_00577900;
    return;
  }
  param_2[1] = 0.0;
  return;
}

// --------------------------------------------------

// Function: FUN_005406f7
// Address: 005406f7
void __thiscall FUN_005406f7(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x35c)) {
    iVar2 = 0;
    do {
      piVar1 = (int *)(*(int *)(param_1 + 0x354) + iVar2);
      if ((*piVar1 == 1) && (piVar1[4] == param_2)) {
        piVar1[2] = piVar1[2] - piVar1[3];
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x14;
    } while (iVar3 < *(int *)(param_1 + 0x35c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00540748
// Address: 00540748
// [HELPER] s_c__aoeWVlog_txt: "c:\aoeWVlog.txt"
// [HELPER] s_w: "w"
undefined4 * __fastcall FUN_00540748(undefined4 *param_1)
{
  void *pvVar1;
  RGE_Object_List *pRVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561c0d;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 10000;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 1000;
  param_1[0x3d] = 2;
  param_1[0x3e] = 2;
  param_1[0x3f] = 0xffffffff;
  param_1[0x40] = 0xffffffff;
  *param_1 = &RGE_Game_World::_vftable_;
  world_update_counter = 0;
  pvVar1 = operator_new(param_1[0x24] << 2);
  param_1[0x22] = pvVar1;
  pvVar1 = operator_new(param_1[0x27] << 2);
  param_1[0x25] = pvVar1;
  VIS_UNIT_objectsValue = (RGE_Static_Object **)param_1[0x22];
  param_1[0x28] = 0;
  *(undefined2 *)(param_1 + 0xb) = 0;
  param_1[0xc] = 0;
  *(undefined2 *)(param_1 + 0xd) = 0;
  param_1[0xe] = 0;
  *(undefined2 *)(param_1 + 0xf) = 0;
  param_1[0x10] = 0;
  *(undefined2 *)(param_1 + 0x11) = 0;
  param_1[0x12] = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  param_1[0x15] = 0;
  *(undefined2 *)(param_1 + 0x18) = 0;
  param_1[0x19] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x13] = 0;
  param_1[10] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x21] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0xffffffff;
  param_1[0x1e] = 0xe;
  *(undefined2 *)(param_1 + 0x1f) = 1;
  param_1[0x20] = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 2;
  *(undefined1 *)((int)param_1 + 0x1e) = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0x2c] = 0;
  puVar5 = param_1 + 0x2d;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 0;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_Object_List::RGE_Object_List(pRVar2);
  }
  uStack_4 = 0xffffffff;
  param_1[0x36] = uVar3;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 1;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_Object_List::RGE_Object_List(pRVar2);
  }
  uStack_4 = 0xffffffff;
  param_1[0x37] = uVar3;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 2;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_Object_List::RGE_Object_List(pRVar2);
  }
  uStack_4 = 0xffffffff;
  param_1[0x38] = uVar3;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 3;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_Object_List::RGE_Object_List(pRVar2);
  }
  uStack_4 = 0xffffffff;
  param_1[0x39] = uVar3;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 4;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_Object_List::RGE_Object_List(pRVar2);
  }
  uStack_4 = 0xffffffff;
  param_1[0x3a] = uVar3;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 5;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_Object_List::RGE_Object_List(pRVar2);
  }
  uStack_4 = 0xffffffff;
  param_1[0x3b] = uVar3;
  pRVar2 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 6;
  if (pRVar2 == (RGE_Object_List *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_Object_List::RGE_Object_List(pRVar2);
  }
  param_1[0x3c] = uVar3;
  *(undefined1 *)(param_1 + 0x1d) = 0;
  if (DVlogf == (_iobuf *)0x0) {
    DVlogf = (_iobuf *)fopen(s_c__aoeWVlog_txt,s_w);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00540a0c
// Address: 00540a0c
void FUN_00540a0c(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00540a13
// Address: 00540a13
RGE_Game_World * __thiscall FUN_00540a13(RGE_Game_World *param_1,byte param_2)
{
  RGE_Game_World::~RGE_Game_World(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00540a3e
// Address: 00540a3e
void __fastcall FUN_00540a3e(RGE_Game_World *param_1)
{
  RGE_Object_List *pRVar1;
  RGE_Sprite *this;
  RGE_Sound *this_00;
  int iVar2;
  
  param_1->_padding_ = (int)&RGE_Game_World::_vftable_;
  if (param_1->commands != (RGE_Command *)0x0) {
    (**(code **)(param_1->commands->_padding_ + 4))(1);
  }
  RGE_Game_World::del_game_info(param_1);
  pRVar1 = param_1->reusable_static_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = param_1->reusable_animated_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = param_1->reusable_moving_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = param_1->reusable_action_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = param_1->reusable_combat_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = param_1->reusable_missile_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = param_1->reusable_doppleganger_objects;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  if (param_1->master_players != (RGE_Master_Player **)0x0) {
    iVar2 = 0;
    if (0 < param_1->master_player_num) {
      do {
        if (param_1->master_players[iVar2] != (RGE_Master_Player *)0x0) {
          (**(code **)param_1->master_players[iVar2]->_padding_)(1);
          param_1->master_players[iVar2] = (RGE_Master_Player *)0x0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1->master_player_num);
    }
    free(param_1->master_players);
    param_1->master_players = (RGE_Master_Player **)0x0;
  }
  if (param_1->effects != (RGE_Effects *)0x0) {
    (**(code **)param_1->effects->_padding_)(1);
    param_1->effects = (RGE_Effects *)0x0;
  }
  if (param_1->map != (RGE_Map *)0x0) {
    (**(code **)param_1->map->_padding_)(1);
    param_1->map = (RGE_Map *)0x0;
  }
  if (param_1->sprites != (RGE_Sprite **)0x0) {
    iVar2 = 0;
    if (0 < param_1->sprite_num) {
      do {
        this = param_1->sprites[iVar2];
        if (this != (RGE_Sprite *)0x0) {
          RGE_Sprite::~RGE_Sprite(this);
          operator_delete(this);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1->sprite_num);
    }
    free(param_1->sprites);
    param_1->sprites = (RGE_Sprite **)0x0;
  }
  if (param_1->sounds != (RGE_Sound **)0x0) {
    iVar2 = 0;
    if (0 < param_1->sound_num) {
      do {
        this_00 = param_1->sounds[iVar2];
        if (this_00 != (RGE_Sound *)0x0) {
          RGE_Sound::~RGE_Sound(this_00);
          operator_delete(this_00);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1->sound_num);
    }
    free(param_1->sounds);
    param_1->sounds = (RGE_Sound **)0x0;
  }
  if (param_1->terrains != (float **)0x0) {
    iVar2 = 0;
    if (0 < param_1->terrain_num) {
      do {
        if (param_1->terrains[iVar2] != (float *)0x0) {
          free(param_1->terrains[iVar2]);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1->terrain_num);
    }
    free(param_1->terrains);
    param_1->terrains = (float **)0x0;
  }
  if (param_1->color_tables != (RGE_Color_Table **)0x0) {
    iVar2 = 0;
    if (0 < param_1->color_table_num) {
      do {
        if (param_1->color_tables[iVar2] != (RGE_Color_Table *)0x0) {
          (**(code **)param_1->color_tables[iVar2]->_padding_)(1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1->color_table_num);
    }
    free(param_1->color_tables);
    param_1->color_tables = (RGE_Color_Table **)0x0;
  }
  if (param_1->objectsValue != (RGE_Static_Object **)0x0) {
    operator_delete(param_1->objectsValue);
    param_1->objectsValue = (RGE_Static_Object **)0x0;
    VIS_UNIT_objectsValue = (RGE_Static_Object **)0x0;
  }
  if (param_1->negativeObjectsValue != (RGE_Static_Object **)0x0) {
    operator_delete(param_1->negativeObjectsValue);
    param_1->negativeObjectsValue = (RGE_Static_Object **)0x0;
  }
  if (logStatusFile != (_iobuf *)0x0) {
    fclose(logStatusFile);
    logStatusFile = (_iobuf *)0x0;
  }
  if (param_1->playbook != (AIPlayBook *)0x0) {
    (**(code **)param_1->playbook->_padding_)(1);
    param_1->playbook = (AIPlayBook *)0x0;
  }
  if (DVlogf != (_iobuf *)0x0) {
    fclose(DVlogf);
    DVlogf = (_iobuf *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00540ce2
// Address: 00540ce2
void __fastcall FUN_00540ce2(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  puVar2 = (undefined4 *)(param_1 + 0xb4);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00540d23
// Address: 00540d23
void __thiscall FUN_00540d23(int param_1,char param_2)
{
  int iVar1;
  
  if ((param_2 != '\0') && (iVar1 = 0, 0 < *(short *)(param_1 + 0x2c))) {
    do {
      RGE_Sound::stop(*(RGE_Sound **)(*(int *)(param_1 + 0x30) + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(short *)(param_1 + 0x2c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00540d5d
// Address: 00540d5d
void __thiscall FUN_00540d5d(int param_1,uchar param_2)
{
  if (*(RGE_Map **)(param_1 + 0x28) != (RGE_Map *)0x0) {
    RGE_Map::set_map_visible(*(RGE_Map **)(param_1 + 0x28),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00540d74
// Address: 00540d74
void __thiscall FUN_00540d74(int param_1,uchar param_2)
{
  if (*(RGE_Map **)(param_1 + 0x28) != (RGE_Map *)0x0) {
    RGE_Map::set_map_fog(*(RGE_Map **)(param_1 + 0x28),param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00540d94
// Address: 00540d94
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_00540d94(int param_1,undefined4 param_2)
{
  short *psVar1;
  _iobuf *p_Var2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  short asStack_18 [2];
  int iStack_14;
  RGE_Sound *pRStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561c2b;
  *unaff_FS_OFFSET = &uStack_c;
  p_Var2 = (_iobuf *)fopen(param_2,s_r);
  if (p_Var2 != (_iobuf *)0x0) {
    psVar1 = (short *)(param_1 + 0x2c);
    iVar3 = fscanf(p_Var2,s__hd__hd,psVar1,&param_2);
    if (iVar3 == -1) {
      *psVar1 = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    else {
      uVar4 = calloc((int)*psVar1,4);
      *(undefined4 *)(param_1 + 0x30) = uVar4;
      iStack_14 = 0;
      if (0 < (short)param_2) {
        do {
          iVar3 = fscanf(p_Var2,s__hd,asStack_18);
          if (iVar3 != -1) {
            pRStack_10 = (RGE_Sound *)operator_new(0x10);
            uStack_4 = 0;
            if (pRStack_10 == (RGE_Sound *)0x0) {
              uVar4 = 0;
            }
            else {
              uVar4 = RGE_Sound::RGE_Sound(pRStack_10,p_Var2,asStack_18[0]);
            }
            uStack_4 = 0xffffffff;
            *(undefined4 *)(*(int *)(param_1 + 0x30) + asStack_18[0] * 4) = uVar4;
          }
          iStack_14 = iStack_14 + 1;
        } while ((short)iStack_14 < (short)param_2);
      }
    }
    fclose(p_Var2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00540ea1
// Address: 00540ea1
// [HELPER] s__f: "%f"
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_00540ea1(int param_1,undefined4 param_2)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  short sVar5;
  short sStack_8;
  short sStack_6;
  int iStack_4;
  
  iVar2 = fopen(param_2,s_r);
  if (iVar2 != 0) {
    psVar1 = (short *)(param_1 + 0x50);
    iVar3 = fscanf(iVar2,s__hd__hd,psVar1,(short *)(param_1 + 0x52));
    if (iVar3 == -1) {
      *psVar1 = 0;
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    else {
      uVar4 = calloc((int)*psVar1,4);
      *(undefined4 *)(param_1 + 0x54) = uVar4;
      iStack_4 = 0;
      if (0 < *psVar1) {
        do {
          iVar3 = fscanf(iVar2,s__hd__hd,&param_2,&sStack_8);
          if (iVar3 != -1) {
            uVar4 = calloc((int)*(short *)(param_1 + 0x52),4);
            sVar5 = 0;
            *(undefined4 *)(*(int *)(param_1 + 0x54) + (short)param_2 * 4) = uVar4;
            if (0 < sStack_8) {
              do {
                fscanf(iVar2,s__hd,&sStack_6);
                fscanf(iVar2,s__f,
                       *(int *)(*(int *)(param_1 + 0x54) + (short)param_2 * 4) + sStack_6 * 4);
                sVar5 = sVar5 + 1;
              } while (sVar5 < sStack_8);
            }
          }
          iStack_4 = iStack_4 + 1;
        } while ((short)iStack_4 < *(short *)(param_1 + 0x50));
      }
    }
    fclose(iVar2);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00540fca
// Address: 00540fca
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_00540fca(int param_1,undefined4 param_2)
{
  short *psVar1;
  _iobuf *p_Var2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  short asStack_18 [2];
  int iStack_14;
  RGE_Color_Table *pRStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561c4b;
  *unaff_FS_OFFSET = &uStack_c;
  p_Var2 = (_iobuf *)fopen(param_2,s_r);
  if (p_Var2 != (_iobuf *)0x0) {
    psVar1 = (short *)(param_1 + 0x60);
    iVar3 = fscanf(p_Var2,s__hd__hd,psVar1,&param_2);
    if (iVar3 == -1) {
      *psVar1 = 0;
      *(undefined4 *)(param_1 + 100) = 0;
    }
    else {
      uVar4 = calloc((int)*psVar1,4);
      *(undefined4 *)(param_1 + 100) = uVar4;
      iStack_14 = 0;
      if (0 < (short)param_2) {
        do {
          iVar3 = fscanf(p_Var2,s__hd,asStack_18);
          if (iVar3 != -1) {
            pRStack_10 = (RGE_Color_Table *)operator_new(0x128);
            uStack_4 = 0;
            if (pRStack_10 == (RGE_Color_Table *)0x0) {
              uVar4 = 0;
            }
            else {
              uVar4 = RGE_Color_Table::RGE_Color_Table(pRStack_10,p_Var2,asStack_18[0]);
            }
            uStack_4 = 0xffffffff;
            *(undefined4 *)(*(int *)(param_1 + 100) + asStack_18[0] * 4) = uVar4;
          }
          iStack_14 = iStack_14 + 1;
        } while ((short)iStack_14 < (short)param_2);
      }
    }
    fclose(p_Var2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_005410d8
// Address: 005410d8
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_005410d8(int param_1,undefined4 param_2)
{
  short *psVar1;
  short sVar2;
  _iobuf *p_Var3;
  int iVar4;
  undefined4 uVar5;
  short sVar6;
  undefined4 *unaff_FS_OFFSET;
  short asStack_14 [2];
  RGE_Sprite *pRStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561c76;
  *unaff_FS_OFFSET = &uStack_c;
  p_Var3 = (_iobuf *)fopen(param_2,s_r);
  if (p_Var3 != (_iobuf *)0x0) {
    psVar1 = (short *)(param_1 + 0x34);
    iVar4 = fscanf(p_Var3,s__hd__hd,psVar1,&param_2);
    if (iVar4 == -1) {
      *psVar1 = 0;
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    else {
      uVar5 = calloc((int)*psVar1,4);
      *(undefined4 *)(param_1 + 0x38) = uVar5;
      sVar6 = 0;
      sVar2 = (short)param_2;
      if (0 < (short)param_2) {
        do {
          iVar4 = fscanf(p_Var3,s__hd,asStack_14);
          if (iVar4 != -1) {
            pRStack_10 = (RGE_Sprite *)operator_new(0x78);
            uStack_4 = 0;
            if (pRStack_10 == (RGE_Sprite *)0x0) {
              uVar5 = 0;
            }
            else {
              uVar5 = RGE_Sprite::RGE_Sprite
                                (pRStack_10,p_Var3,asStack_14[0],*(RGE_Sound ***)(param_1 + 0x30));
            }
            uStack_4 = 0xffffffff;
            *(undefined4 *)(*(int *)(param_1 + 0x38) + asStack_14[0] * 4) = uVar5;
          }
          sVar6 = sVar6 + 1;
          sVar2 = (short)param_2;
        } while (sVar6 < (short)param_2);
      }
      sVar6 = 0;
      if (0 < sVar2) {
        do {
          if (*(int *)(*(int *)(param_1 + 0x38) + sVar6 * 4) == 0) {
            pRStack_10 = (RGE_Sprite *)operator_new(0x78);
            uStack_4 = 1;
            if (pRStack_10 == (RGE_Sprite *)0x0) {
              uVar5 = 0;
            }
            else {
              uVar5 = RGE_Sprite::RGE_Sprite(pRStack_10,sVar6);
            }
            uStack_4 = 0xffffffff;
            *(undefined4 *)(*(int *)(param_1 + 0x38) + sVar6 * 4) = uVar5;
            sVar2 = (short)param_2;
          }
          sVar6 = sVar6 + 1;
        } while (sVar6 < sVar2);
      }
    }
    fclose(p_Var3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0054123c
// Address: 0054123c
void __thiscall FUN_0054123c(int param_1,short param_2,short param_3,_iobuf *param_4)
{
  RGE_Master_Player *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561c8b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == 0) {
    this = (RGE_Master_Player *)operator_new(0x2c);
    uStack_4 = 0;
    if (this == (RGE_Master_Player *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = RGE_Master_Player::RGE_Master_Player(this,param_4);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x48) + param_2 * 4) = uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_005412a7
// Address: 005412a7
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_005412a7(int *param_1,undefined4 param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = fopen(param_2,s_r);
  if (iVar2 != 0) {
    piVar1 = param_1 + 0x11;
    iVar3 = fscanf(iVar2,s__hd__hd,piVar1,&param_2);
    if (iVar3 == -1) {
      *(short *)piVar1 = 0;
      param_1[0x12] = 0;
    }
    else {
      iVar3 = calloc((int)(short)*piVar1,4);
      sVar4 = 0;
      param_1[0x12] = iVar3;
      if (0 < (short)param_2) {
        do {
          iVar3 = fscanf(iVar2,s__hd__hd,&uStack_4,&uStack_8);
          if (iVar3 != -1) {
            (**(code **)(*param_1 + 0x1c))(uStack_4,uStack_8,iVar2);
          }
          sVar4 = sVar4 + 1;
        } while (sVar4 < (short)param_2);
        fclose(iVar2);
        return 1;
      }
    }
    fclose(iVar2);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00541375
// Address: 00541375
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_00541375(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  short sStack_e;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = fopen(param_2,s_r);
  if (iVar1 != 0) {
    iVar2 = fscanf(iVar1,s__hd,&sStack_e);
    if ((iVar2 != -1) && (sVar4 = 0, 0 < sStack_e)) {
      do {
        iVar2 = fscanf(iVar1,s__hd,&param_2);
        if (iVar2 != -1) {
          fscanf(iVar1,s__hd,&uStack_c);
          (**(code **)(**(int **)(*(int *)(param_1 + 0x48) + (short)param_2 * 4) + 0xc))(uStack_c);
          fscanf(iVar1,s__hd,&uStack_c);
          sVar3 = 0;
          if (0 < (short)uStack_c) {
            do {
              iVar2 = fscanf(iVar1,s__hd__hd,&uStack_4,&uStack_8);
              if (iVar2 != -1) {
                (**(code **)(**(int **)(*(int *)(param_1 + 0x48) + (short)param_2 * 4) + 0x10))
                          (iVar1,uStack_4,*(undefined4 *)(param_1 + 0x38),
                           *(undefined4 *)(param_1 + 0x30),uStack_8);
              }
              sVar3 = sVar3 + 1;
            } while (sVar3 < (short)uStack_c);
          }
        }
        sVar4 = sVar4 + 1;
      } while (sVar4 < sStack_e);
    }
    fclose(iVar1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00541497
// Address: 00541497
void __thiscall FUN_00541497(int param_1,char *param_2)
{
  RGE_Effects *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561cab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Effects *)operator_new(0xc);
  uStack_4 = 0;
  if (this == (RGE_Effects *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = RGE_Effects::RGE_Effects(this,param_2);
  }
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_005414f8
// Address: 005414f8
void __thiscall
FUN_005414f8(int param_1,char *param_2,undefined4 param_3,char *param_4,char *param_5,short param_6,
            short param_7,short param_8,RGE_Sound **param_9,char *param_10)
{
  RGE_Map *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561ccb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar1 = (RGE_Map *)operator_new(0x8dd0);
  uStack_4 = 0;
  if (pRVar1 == (RGE_Map *)0x0) {
    pRVar1 = (RGE_Map *)0x0;
  }
  else {
    pRVar1 = (RGE_Map *)
             RGE_Map::RGE_Map(pRVar1,param_2,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  uStack_4 = 0xffffffff;
  *(RGE_Map **)(param_1 + 0x28) = pRVar1;
  RGE_Map::load_terrain_obj_types(pRVar1,param_10);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0054158d
// Address: 0054158d
void __thiscall
FUN_0054158d(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  (**(code **)(**(int **)(param_1 + 0x28) + 8))(param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_005415af
// Address: 005415af
// [HELPER] s__s__s__s__s__s__s__s__s__s__s__s: "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %hd %hd %hd"
undefined4 __thiscall FUN_005415af(int *param_1,undefined4 param_2)
{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puStack_198;
  undefined1 auStack_18c [4];
  undefined1 auStack_188 [4];
  undefined1 auStack_184 [4];
  undefined1 auStack_180 [24];
  undefined1 auStack_168 [20];
  undefined1 auStack_154 [4];
  undefined1 auStack_150 [24];
  undefined1 auStack_138 [12];
  undefined1 auStack_12c [8];
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [24];
  undefined1 auStack_108 [4];
  undefined1 auStack_104 [16];
  undefined1 auStack_f4 [4];
  undefined1 auStack_f0 [8];
  undefined1 auStack_e8 [12];
  undefined1 auStack_dc [4];
  undefined1 auStack_d8 [24];
  undefined1 auStack_c0 [8];
  undefined1 auStack_b8 [16];
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [16];
  undefined1 auStack_90 [8];
  undefined1 auStack_88 [16];
  undefined1 auStack_78 [16];
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [8];
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [24];
  undefined1 auStack_30 [24];
  undefined1 auStack_18 [24];
  
  puStack_198 = auStack_188;
  fscanf(param_2,s__s__s__s__s__s__s__s__s__s__s__s,auStack_30,auStack_150,auStack_60,auStack_d8,
         auStack_108,auStack_138,auStack_168,auStack_120,auStack_90,auStack_f0,auStack_180,
         auStack_c0,auStack_18,auStack_48,auStack_78,auStack_a8,auStack_184,auStack_18c);
  iVar1 = *param_1;
  puStack_198 = auStack_30;
  (**(code **)(iVar1 + 4))();
  (**(code **)(iVar1 + 0x14))(auStack_154);
  puVar4 = auStack_68;
  (**(code **)(iVar1 + 0x10))(puVar4);
  puVar3 = auStack_12c;
  (**(code **)(iVar1 + 0x18))(puVar3);
  puVar2 = auStack_a0;
  (**(code **)(iVar1 + 8))(puVar2);
  (**(code **)(iVar1 + 0xc))(auStack_104);
  (**(code **)(iVar1 + 0x20))(&puStack_198);
  (**(code **)(iVar1 + 0x24))
            (auStack_f4,auStack_124,auStack_154,auStack_184,puVar4,puVar2,puVar3,param_1[0xc],
             auStack_dc);
  (**(code **)(iVar1 + 0x28))(auStack_58,auStack_88,auStack_b8,auStack_e8);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00541718
// Address: 00541718
// [HELPER] s_r: "r"
undefined4 __thiscall FUN_00541718(int *param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_retaddr;
  
  iVar2 = fopen(param_3,s_r);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)*param_1;
    (*(code *)*puVar1)(iVar2);
    fclose(iVar2);
    (*(code *)puVar1[0x37])(unaff_retaddr);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00541769
// Address: 00541769
undefined4 __thiscall FUN_00541769(int param_1,int param_2,short param_3,char param_4)
{
  undefined3 uVar2;
  RGE_Master_Player *this;
  undefined4 uVar1;
  undefined3 extraout_var;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561ceb;
  uVar2 = (undefined3)((uint)uStack_c >> 8);
  *unaff_FS_OFFSET = &uStack_c;
  if (param_4 == '\0') {
    this = (RGE_Master_Player *)operator_new(0x2c);
    uStack_4 = 0;
    if (this == (RGE_Master_Player *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = RGE_Master_Player::RGE_Master_Player(this,param_2);
    }
    uStack_4 = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x48) + param_3 * 4) = uVar1;
    (**(code **)(**(int **)(*(int *)(param_1 + 0x48) + param_3 * 4) + 4))
              (param_2,*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x30));
    uVar2 = extraout_var;
  }
  *unaff_FS_OFFSET = uStack_c;
  return CONCAT31(uVar2,1);
}

// --------------------------------------------------

// Function: FUN_005417fa
// Address: 005417fa
undefined4 __thiscall FUN_005417fa(int *param_1,int param_2)
{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_2;
  piVar1 = param_1 + 0x11;
  rge_read(param_2,piVar1,2);
  if (0 < (short)*piVar1) {
    iVar4 = calloc((int)(short)*piVar1,4);
    iVar5 = 0;
    param_1[0x12] = iVar4;
    if (0 < (short)*piVar1) {
      pcVar2 = *(code **)(*param_1 + 0x2c);
      do {
        rge_read(iVar3,&param_2,1);
        (*pcVar2)(iVar3,iVar5,param_2);
        iVar5 = iVar5 + 1;
      } while ((short)iVar5 < (short)*piVar1);
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00541871
// Address: 00541871
void __thiscall FUN_00541871(int param_1,int param_2)
{
  short *psVar1;
  short *psVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  
  psVar1 = (short *)(param_1 + 0x50);
  rge_read(param_2,psVar1,2);
  psVar2 = (short *)(param_1 + 0x52);
  rge_read(param_2,psVar2,2);
  if ((0 < *psVar1) && (0 < *psVar2)) {
    pvVar3 = (void *)calloc((int)*psVar1,4);
    *(void **)(param_1 + 0x54) = pvVar3;
    rge_read(param_2,pvVar3,(int)*psVar1 << 2);
    iVar5 = 0;
    if (0 < *(short *)(param_1 + 0x50)) {
      do {
        if (*(int *)(*(int *)(param_1 + 0x54) + iVar5 * 4) != 0) {
          uVar4 = calloc((int)*psVar2,4);
          *(undefined4 *)(*(int *)(param_1 + 0x54) + iVar5 * 4) = uVar4;
          rge_read(param_2,*(void **)(*(int *)(param_1 + 0x54) + iVar5 * 4),(int)*psVar2 << 2);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(param_1 + 0x50));
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00541924
// Address: 00541924
void __thiscall FUN_00541924(int param_1,int param_2)
{
  short *psVar1;
  undefined4 uVar2;
  RGE_Color_Table *this;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561d0b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  psVar1 = (short *)(param_1 + 0x60);
  rge_read(param_2,psVar1,2);
  if (0 < *psVar1) {
    uVar2 = calloc((int)*psVar1,4);
    iVar3 = 0;
    *(undefined4 *)(param_1 + 100) = uVar2;
    if (0 < *psVar1) {
      do {
        this = (RGE_Color_Table *)operator_new(0x128);
        uStack_4 = 0;
        if (this == (RGE_Color_Table *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = RGE_Color_Table::RGE_Color_Table(this,param_2);
        }
        iVar3 = iVar3 + 1;
        uStack_4 = 0xffffffff;
        *(undefined4 *)(*(int *)(param_1 + 100) + -4 + iVar3 * 4) = uVar2;
      } while (iVar3 < *psVar1);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_005419d7
// Address: 005419d7
void __thiscall FUN_005419d7(int param_1,int param_2)
{
  short *psVar1;
  undefined4 uVar2;
  RGE_Sound *this;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561d2b;
  *unaff_FS_OFFSET = &uStack_c;
  psVar1 = (short *)(param_1 + 0x2c);
  rge_read(param_2,psVar1,2);
  uVar2 = calloc((int)*psVar1,4);
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  if (0 < *psVar1) {
    do {
      this = (RGE_Sound *)operator_new(0x10);
      uStack_4 = 0;
      if (this == (RGE_Sound *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = RGE_Sound::RGE_Sound(this,param_2,*(TSound_Driver **)(param_1 + 0x80));
      }
      iVar3 = iVar3 + 1;
      uStack_4 = 0xffffffff;
      *(undefined4 *)(*(int *)(param_1 + 0x30) + -4 + iVar3 * 4) = uVar2;
    } while (iVar3 < *psVar1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00541a7f
// Address: 00541a7f
void __thiscall FUN_00541a7f(int param_1,int param_2)
{
  short *psVar1;
  void *pvVar2;
  RGE_Sprite *pRVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561d4b;
  *unaff_FS_OFFSET = &uStack_c;
  psVar1 = (short *)(param_1 + 0x34);
  rge_read(param_2,psVar1,2);
  pvVar2 = (void *)calloc((int)*psVar1,4);
  *(void **)(param_1 + 0x38) = pvVar2;
  rge_read(param_2,pvVar2,(int)*psVar1 << 2);
  iVar5 = 0;
  if (0 < *psVar1) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x38) + iVar5 * 4) != 0) {
        pRVar3 = (RGE_Sprite *)operator_new(0x78);
        uStack_4 = 0;
        if (pRVar3 == (RGE_Sprite *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = RGE_Sprite::RGE_Sprite
                            (pRVar3,param_2,*(RGE_Sound ***)(param_1 + 0x30),
                             *(RGE_Color_Table ***)(param_1 + 100));
        }
        uStack_4 = 0xffffffff;
        *(undefined4 *)(*(int *)(param_1 + 0x38) + iVar5 * 4) = uVar4;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *psVar1);
  }
  iVar5 = 0;
  if (0 < *psVar1) {
    do {
      pRVar3 = (*(RGE_Sprite ***)(param_1 + 0x38))[iVar5];
      if (pRVar3 != (RGE_Sprite *)0x0) {
        RGE_Sprite::rehook(pRVar3,*(RGE_Sprite ***)(param_1 + 0x38));
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *psVar1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00541b58
// Address: 00541b58
void __thiscall FUN_00541b58(int param_1,int param_2,RGE_Game_World *param_3)
{
  RGE_Scenario *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561d6b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Scenario *)operator_new(0x1990);
  uStack_4 = 0;
  if (this == (RGE_Scenario *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = RGE_Scenario::RGE_Scenario(this,param_2,param_3);
  }
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00541c1b
// Address: 00541c1b
void __thiscall FUN_00541c1b(int param_1,int param_2)
{
  RGE_Map *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561dab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Map *)operator_new(0x8dd0);
  uStack_4 = 0;
  if (this == (RGE_Map *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = RGE_Map::RGE_Map(this,param_2,*(RGE_Sound ***)(param_1 + 0x30),'\x01');
  }
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00541c81
// Address: 00541c81
void __thiscall FUN_00541c81(int param_1,int param_2)
{
  RGE_Effects *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561dcb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Effects *)operator_new(0xc);
  uStack_4 = 0;
  if (this == (RGE_Effects *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = RGE_Effects::RGE_Effects(this,param_2);
  }
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00541ce8
// Address: 00541ce8
void __thiscall FUN_00541ce8(int *param_1,undefined4 param_2)
{
  (**(code **)(*param_1 + 0x30))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00541cfd
// Address: 00541cfd
void __thiscall
FUN_00541cfd(RGE_Game_World *param_1,undefined4 param_2,TCommunications_Handler *param_3)
{
  RGE_Command *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561deb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar1 = (RGE_Command *)operator_new(0x18);
  uStack_4 = 0;
  if (pRVar1 == (RGE_Command *)0x0) {
    pRVar1 = (RGE_Command *)0x0;
  }
  else {
    pRVar1 = (RGE_Command *)RGE_Command::RGE_Command(pRVar1,param_1,param_3);
  }
  param_1->commands = pRVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00541d59
// Address: 00541d59
void __thiscall FUN_00541d59(int *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 unaff_retaddr;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0x3c))(param_2);
  uVar2 = param_2;
  (**(code **)(iVar1 + 0x38))(param_2);
  (**(code **)(iVar1 + 0x40))(param_2,unaff_retaddr);
  (**(code **)(iVar1 + 0x44))(param_2);
  (**(code **)(iVar1 + 0x48))(param_2,unaff_retaddr);
  (**(code **)(iVar1 + 0x4c))(param_2);
  (**(code **)(iVar1 + 0x50))(param_2);
  (**(code **)(iVar1 + 0x54))(param_2,uVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_00541dac
// Address: 00541dac
// [HELPER] s_VER_3_7: "VER 3.7"
undefined4 __thiscall FUN_00541dac(int *param_1,char *param_2,int param_3,undefined4 param_4)
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  byte abStack_8 [8];
  
  param_1[0x20] = param_3;
  param_1[0x1a] = 0;
  iVar2 = rge_open(param_2,0x8000);
  if (iVar2 == -1) {
    return 0;
  }
  rge_read(iVar2,abStack_8,8);
  pbVar5 = &s_VER_3_7;
  pbVar3 = abStack_8;
  do {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_00541e20:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_00541e25;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_00541e20;
    pbVar3 = pbVar3 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_00541e25:
  if (iVar4 != 0) {
    rge_close(iVar2);
    return 0;
  }
  (**(code **)(*param_1 + 0x58))(iVar2,param_3,param_4);
  rge_close(iVar2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00541e6e
// Address: 00541e6e
void __fastcall FUN_00541e6e(int param_1)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(short *)(param_1 + 0x2c)) {
    do {
      RGE_Sound::stop(*(RGE_Sound **)(*(int *)(param_1 + 0x30) + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(short *)(param_1 + 0x2c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00541e93
// Address: 00541e93
void __thiscall FUN_00541e93(int param_1,TCommunications_Handler *param_2)
{
  RGE_Command::reset_communications(*(RGE_Command **)(param_1 + 0x58),param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00541ed7
// Address: 00541ed7
void __fastcall FUN_00541ed7(int *param_1)
{
  RGE_Player *this;
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  world_update_counter = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 2;
  *(undefined1 *)((int)param_1 + 0x1e) = 0;
  RGE_Object_List::removeAllObjects((RGE_Object_List *)param_1[0x36]);
  RGE_Object_List::removeAllObjects((RGE_Object_List *)param_1[0x37]);
  RGE_Object_List::removeAllObjects((RGE_Object_List *)param_1[0x38]);
  RGE_Object_List::removeAllObjects((RGE_Object_List *)param_1[0x39]);
  RGE_Object_List::removeAllObjects((RGE_Object_List *)param_1[0x3a]);
  RGE_Object_List::removeAllObjects((RGE_Object_List *)param_1[0x3b]);
  RGE_Object_List::removeAllObjects((RGE_Object_List *)param_1[0x3c]);
  param_1[0x1b] = -1;
  param_1[0x29] = -1;
  param_1[0x2a] = -1;
  param_1[0x2b] = -1;
  param_1[0x40] = -1;
  iVar2 = 0;
  param_1[0x1a] = 0;
  if (0 < param_1[0x24]) {
    do {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(param_1[0x22] + -4 + iVar2 * 4) = 0;
    } while (iVar2 < param_1[0x24]);
  }
  iVar2 = 0;
  if (0 < param_1[0x27]) {
    do {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(param_1[0x25] + -4 + iVar2 * 4) = 0;
    } while (iVar2 < param_1[0x27]);
  }
  (**(code **)(*param_1 + 0xb4))();
  if ((int *)param_1[0x17] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x17] + 4))(1);
    param_1[0x17] = 0;
  }
  if (((0 < (short)param_1[0xf]) && (param_1[0x10] != 0)) && (iVar2 = 0, 0 < (short)param_1[0xf])) {
    do {
      this = *(RGE_Player **)(param_1[0x10] + iVar2 * 4);
      if (this != (RGE_Player *)0x0) {
        RGE_Player::destroy_objects(this);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (short)param_1[0xf]);
  }
  if ((0 < (short)param_1[0xf]) && (param_1[0x10] != 0)) {
    iVar2 = 0;
    if (0 < (short)param_1[0xf]) {
      do {
        puVar1 = *(undefined4 **)(param_1[0x10] + iVar2 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
          *(undefined4 *)(param_1[0x10] + iVar2 * 4) = 0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (short)param_1[0xf]);
    }
    *(undefined2 *)(param_1 + 0xf) = 0;
    free(param_1[0x10]);
    param_1[0x10] = 0;
  }
  param_1[0x1a] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0x2c] = 0;
  piVar3 = param_1 + 0x2d;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00542055
// Address: 00542055
void __thiscall FUN_00542055(RGE_Game_World *param_1,int param_2,char param_3,short param_4)
{
  RGE_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561e0b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == '\0') {
    pRVar1 = (RGE_Player *)operator_new(0x220);
    uStack_4 = 0;
    if (pRVar1 == (RGE_Player *)0x0) {
      pRVar1 = (RGE_Player *)0x0;
    }
    else {
      pRVar1 = (RGE_Player *)RGE_Player::RGE_Player(pRVar1,param_2,param_1,(uchar)param_4);
    }
    uStack_4 = 0xffffffff;
    param_1->players[param_4] = pRVar1;
    (**(code **)(param_1->players[param_4]->_padding_ + 0x74))(param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_005420e9
// Address: 005420e9
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005420e9(RGE_Game_World *param_1,int param_2)
{
  short *psVar1;
  code *pcVar2;
  RGE_Player **ppRVar3;
  int iVar4;
  ulong *puVar5;
  int iVar6;
  float fVar7;
  int iStack_8;
  undefined4 uStack_4;
  
  iVar4 = param_2;
  param_1->game_state = '\x02';
  param_1->game_end_condition = '\0';
  rge_read(param_2,&param_1->world_time,4);
  rge_read(iVar4,&param_1->old_world_time,4);
  rge_read(iVar4,&param_1->world_time_delta,4);
  rge_read(iVar4,&param_1->world_time_delta_seconds,4);
  rge_read(iVar4,&param_1->timer,4);
  rge_read(iVar4,&param_1->game_speed,4);
  rge_read(iVar4,&param_1->temp_pause,1);
  rge_read(iVar4,&param_1->next_object_id,4);
  rge_read(iVar4,&param_1->next_reusable_object_id,4);
  rge_read(iVar4,&param_1->random_seed,4);
  rge_read(iVar4,&param_1->curr_player,2);
  psVar1 = &param_1->player_num;
  rge_read(iVar4,psVar1,2);
  rge_read(iVar4,&param_2,1);
  rge_read(iVar4,&param_1->campaign,4);
  rge_read(iVar4,&param_1->campaign_player,4);
  rge_read(iVar4,&param_1->campaign_scenario,4);
  rge_read(iVar4,&param_1->player_turn,4);
  puVar5 = param_1->player_time_delta;
  iStack_8 = 9;
  do {
    rge_read(iVar4,puVar5,4);
    puVar5 = puVar5 + 1;
    iStack_8 = iStack_8 + -1;
  } while (iStack_8 != 0);
  iVar6 = 0;
  param_1->old_time = 0;
  RGE_Map::load_map(param_1->map,iVar4);
  RGE_Game_World::initializePathingSystem(param_1);
  param_1->currentUpdateComputerPlayer = -1;
  if (0 < *psVar1) {
    ppRVar3 = (RGE_Player **)calloc(4,(int)*psVar1);
    param_1->players = ppRVar3;
    if (0 < *psVar1) {
      pcVar2 = *(code **)(param_1->_padding_ + 0x34);
      do {
        rge_read(iVar4,&uStack_4,1);
        (*pcVar2)(iVar4,uStack_4,iVar6);
        iVar6 = iVar6 + 1;
      } while (iVar6 < *psVar1);
    }
  }
  RGE_Game_World::update_mutual_allies(param_1);
  RGE_Unified_Visible_Map::suppress_updates(param_1->map->unified_vis_map,1);
  iVar6 = 0;
  if (0 < *psVar1) {
    do {
      RGE_Player::load_info(param_1->players[iVar6],iVar4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *psVar1);
  }
  RGE_Unified_Visible_Map::suppress_updates(param_1->map->unified_vis_map,0);
  (**(code **)(param_1->_padding_ + 0xf4))(iVar4,param_1);
  if (save_game_version < _DAT_00577a10) {
    param_1->difficultyLevelValue = -1;
  }
  else {
    rge_read(iVar4,&param_1->difficultyLevelValue,4);
  }
  iVar4 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar4 != 0) {
    fVar7 = RGE_Base_Game::get_game_speed(rge_base_game);
    param_1->game_speed = fVar7;
  }
  param_1->game_state = (uchar)uStack_4;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00542356
// Address: 00542356
// [HELPER] s_VER_8_6: "VER 8.6"
// [HELPER] s__s_s: "%s%s"
undefined4 __thiscall FUN_00542356(int *param_1,undefined4 param_2)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  byte abStack_134 [8];
  char acStack_12c [300];
  
  world_update_counter = 0;
  iVar2 = *param_1;
  (**(code **)(iVar2 + 0xb8))();
  sprintf(acStack_12c,s__s_s,rge_base_game->prog_info->save_dir,param_2);
  iVar3 = rge_open(acStack_12c,0x8000);
  if (iVar3 == -1) {
    return 0;
  }
  rge_read(iVar3,abStack_134,8);
  rge_read(iVar3,&save_game_version,4);
  pbVar6 = &s_VER_8_6;
  pbVar4 = abStack_134;
  do {
    bVar1 = *pbVar4;
    bVar7 = bVar1 < *pbVar6;
    if (bVar1 != *pbVar6) {
LAB_00542413:
      iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_00542418;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar4[1];
    bVar7 = bVar1 < pbVar6[1];
    if (bVar1 != pbVar6[1]) goto LAB_00542413;
    pbVar4 = pbVar4 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar1 != 0);
  iVar5 = 0;
LAB_00542418:
  if (iVar5 != 0) {
    rge_close(iVar3);
    return 0;
  }
  (**(code **)(iVar2 + 200))();
  rge_close(iVar3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00542463
// Address: 00542463
void __thiscall FUN_00542463(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0054247a
// Address: 0054247a
// [HELPER] s_GAIA: "GAIA"
void __fastcall FUN_0054247a(RGE_Game_World *param_1)
{
  RGE_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561e2b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar1 = (RGE_Player *)operator_new(0x220);
  uStack_4 = 0;
  if (pRVar1 == (RGE_Player *)0x0) {
    pRVar1 = (RGE_Player *)0x0;
  }
  else {
    pRVar1 = (RGE_Player *)
             RGE_Player::RGE_Player(pRVar1,param_1,*param_1->master_players,'\0',s_GAIA,'\0','\x01')
    ;
  }
  *param_1->players = pRVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_005424e8
// Address: 005424e8
void __thiscall FUN_005424e8(RGE_Game_World *param_1,int param_2)
{
  uchar uVar1;
  RGE_Player *pRVar2;
  short sVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561e4b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  sVar3 = 1;
  if (1 < param_1->player_num) {
    do {
      uStack_4 = 0xffffffff;
      iVar4 = (int)sVar3;
      if (*(char *)(param_2 + 0x248 + iVar4) != -1) {
        pRVar2 = (RGE_Player *)operator_new(0x220);
        uStack_4 = 0;
        if (pRVar2 == (RGE_Player *)0x0) {
          pRVar2 = (RGE_Player *)0x0;
        }
        else {
          uVar1 = *(uchar *)(param_2 + 0x251 + iVar4);
          pRVar2 = (RGE_Player *)
                   RGE_Player::RGE_Player
                             (pRVar2,param_1,param_1->master_players[(char)uVar1],(uchar)sVar3,
                              (char *)(iVar4 * 0x41 + -0x41 + param_2),uVar1,'\x01');
        }
        param_1->players[iVar4] = pRVar2;
      }
      sVar3 = sVar3 + 1;
    } while (sVar3 < param_1->player_num);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_005425aa
// Address: 005425aa
void __thiscall FUN_005425aa(int param_1,int param_2)
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iStack_4;
  
  iVar4 = -1;
  RGE_Player::set_color_table((RGE_Player *)**(undefined4 **)(param_1 + 0x40),'\a');
  iVar2 = *(short *)(param_1 + 0x3c) + 1;
  iStack_4 = (int)*(short *)(param_2 + 0x294);
  if (iVar2 < *(short *)(param_2 + 0x294)) {
    iStack_4 = iVar2;
  }
  iVar6 = 1;
  iVar2 = calloc((int)*(short *)(param_1 + 0x60),1);
  iVar3 = calloc((int)*(short *)(param_1 + 0x3c),1);
  if (1 < *(short *)(param_1 + 0x3c)) {
    psVar5 = (short *)(param_2 + 0x25c);
    do {
      if (((iVar6 + -1 < iStack_4) && (-1 < *psVar5)) && (*(char *)(iVar2 + *psVar5) == '\0')) {
        RGE_Player::set_color_table
                  (*(RGE_Player **)(*(int *)(param_1 + 0x40) + iVar6 * 4),(uchar)*psVar5);
        *(undefined1 *)(iVar2 + *psVar5) = 1;
        *(undefined1 *)(iVar3 + iVar6) = 1;
      }
      iVar6 = iVar6 + 1;
      psVar5 = psVar5 + 1;
    } while (iVar6 < *(short *)(param_1 + 0x3c));
  }
  iVar6 = 1;
  if (1 < *(short *)(param_1 + 0x3c)) {
    do {
      if (*(char *)(iVar3 + iVar6) == '\0') {
        do {
          do {
            pcVar1 = (char *)(iVar2 + 1 + iVar4);
            iVar4 = iVar4 + 1;
          } while (*pcVar1 == '\x01');
        } while (*(char *)(*(int *)(*(int *)(param_1 + 100) + iVar4 * 4) + 0x24) != '\x01');
        RGE_Player::set_color_table
                  (*(RGE_Player **)(*(int *)(param_1 + 0x40) + iVar6 * 4),(uchar)iVar4);
        *(undefined1 *)(iVar2 + iVar4) = 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(short *)(param_1 + 0x3c));
  }
  free(iVar2);
  free(iVar3);
  return;
}

// --------------------------------------------------

// Function: FUN_005426d7
// Address: 005426d7
void __fastcall FUN_005426d7(int param_1)
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -1;
  RGE_Player::set_color_table((RGE_Player *)**(undefined4 **)(param_1 + 0x40),'\a');
  iVar2 = calloc((int)*(short *)(param_1 + 0x60),1);
  iVar3 = 1;
  if (1 < *(short *)(param_1 + 0x3c)) {
    do {
      do {
        do {
          pcVar1 = (char *)(iVar2 + 1 + iVar4);
          iVar4 = iVar4 + 1;
        } while (*pcVar1 == '\x01');
      } while (*(char *)(*(int *)(*(int *)(param_1 + 100) + iVar4 * 4) + 0x24) != '\x01');
      RGE_Player::set_color_table
                (*(RGE_Player **)(*(int *)(param_1 + 0x40) + iVar3 * 4),(uchar)iVar4);
      *(undefined1 *)(iVar2 + iVar4) = 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(param_1 + 0x3c));
  }
  free(iVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_0054274d
// Address: 0054274d
// [HELPER] s_C__msdev_work_age1_x1_World_cpp: "C:\msdev\work\age1_x1\World.cpp"
// [HELPER] s_World__new_game__rand__d_: "World: new_game (rand=%d)"
// [HELPER] s___World__after_gaia__rand__d_: "  World: after_gaia (rand=%d)"
// [HELPER] s___World__after_new_map__rand__d_: "  World: after_new_map (rand=%d)"
// [HELPER] s___World__after_players__rand__d_: "  World: after_players (rand=%d)"
// [HELPER] s___World__end_of_new_game__rand__: "  World: end_of_new_game (rand=%d)"
undefined1 __thiscall FUN_0054274d(RGE_Game_World *param_1,int param_2,short param_3)
{
  bool bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  RGE_Player **ppRVar6;
  int iVar7;
  int iVar8;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *this_02;
  uint uVar9;
  int **ppiVar10;
  float fVar11;
  int unaff_retaddr;
  undefined1 uVar12;
  int iStack_14;
  
  world_update_counter = 0;
  PathingSystem::zeroObstructionMap(&pathSystem);
  PathingSystem::zeroObstructionMap(&aiPathSystem);
  param_1->currentUpdateComputerPlayer = -1;
  ppiVar10 = &computerPlayerSetup;
  for (iVar8 = 0xd; iVar8 != 0; iVar8 = iVar8 + -1) {
    *ppiVar10 = (int *)0x0;
    ppiVar10 = ppiVar10 + 1;
  }
  iVar8 = param_1->_padding_;
  (**(code **)(iVar8 + 0xb8))();
  debug_random_reset();
  debug_timeGetTime_cnt = 0;
  debug_timeGetTime_time = 0;
  param_1->game_state = '\x03';
  param_1->curr_player = param_3;
  iVar4 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar4 == 0) {
    uVar5 = rge_base_game->random_game_seed;
    if (uVar5 == 0xffffffff) {
      uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x509);
    }
  }
  else {
    uVar5 = TCommunications_Handler::GetRandomSeed(param_1->commands->com_hand);
  }
  param_1->random_seed = uVar5;
  debug_srand(s_C__msdev_work_age1_x1_World_cpp,0x50c,uVar5);
  rge_base_game->save_random_game_seed = param_1->random_seed;
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x50f);
  param_1->random_seed = uVar5;
  TDebuggingLog::Log(this,(char *)L,s_World__new_game__rand__d_,uVar5);
  param_1->player_num = *(short *)(param_2 + 0x294) + 1;
  RGE_Map::new_map(param_1->map,(int)*(short *)(param_2 + 0x2a2),(int)*(short *)(param_2 + 0x2a4));
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x516);
  param_1->random_seed = uVar5;
  TDebuggingLog::Log(this_00,(char *)L,s___World__after_new_map__rand__d_,uVar5);
  sVar3 = *(short *)(param_2 + 0x294) + 1;
  param_1->player_num = sVar3;
  ppRVar6 = (RGE_Player **)calloc(4,(int)sVar3);
  param_1->players = ppRVar6;
  (**(code **)(iVar8 + 0x5c))();
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x520);
  param_1->random_seed = uVar5;
  TDebuggingLog::Log(this_01,(char *)L,s___World__after_gaia__rand__d_,uVar5);
  (**(code **)(iVar8 + 0x60))(param_2);
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x526);
  param_1->random_seed = uVar5;
  TDebuggingLog::Log(this_02,(char *)L,s___World__after_players__rand__d_,uVar5);
  uVar5 = 1;
  do {
    iVar8 = TCommunications_Handler::GetPlayerHumanity(param_1->commands->com_hand,uVar5);
    if (((iVar8 == 2) || (iVar8 == 4)) &&
       (iVar8 = RGE_Base_Game::playerTeam(rge_base_game,uVar5 - 1), 1 < iVar8)) {
      uVar9 = 1;
      do {
        iVar4 = TCommunications_Handler::GetPlayerHumanity(param_1->commands->com_hand,uVar9);
        if (((iVar4 == 2) || (iVar4 == 4)) &&
           (iVar4 = RGE_Base_Game::playerTeam(rge_base_game,uVar9 - 1), iVar4 == iVar8)) {
          iVar4 = RGE_Base_Game::playerID(rge_base_game,uVar5);
          iVar7 = RGE_Base_Game::playerID(rge_base_game,uVar9);
          if (iVar4 != iVar7) {
            RGE_Player::set_relation(param_1->players[iVar4],iVar7,'\0');
            RGE_Player::set_allied_victory(param_1->players[iVar4],'\x01');
          }
        }
        uVar9 = uVar9 + 1;
        param_2 = unaff_retaddr;
      } while ((int)uVar9 < 9);
    }
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 9);
  iVar8 = RGE_Base_Game::randomGame(rge_base_game);
  if ((iVar8 != 0) && (iVar8 = RGE_Base_Game::campaignGame(rge_base_game), iVar8 == 0)) {
    uVar5 = 1;
    do {
      iVar8 = TCommunications_Handler::GetPlayerHumanity(param_1->commands->com_hand,uVar5);
      if ((((iVar8 == 4) || (all_cp == 1)) || ((all_cp == 2 && (1 < (int)uVar5)))) &&
         (iVar8 = RGE_Base_Game::playerTeam(rge_base_game,uVar5 - 1), iVar8 == 1)) {
        uVar9 = 1;
        do {
          iVar8 = TCommunications_Handler::GetPlayerHumanity(param_1->commands->com_hand,uVar9);
          if ((iVar8 == 4) || (iVar8 == 2)) {
            iVar8 = RGE_Base_Game::playerID(rge_base_game,uVar5);
            iVar4 = RGE_Base_Game::playerID(rge_base_game,uVar9);
            if (iVar8 != iVar4) {
              RGE_Player::set_relation(param_1->players[iVar8],iVar4,'\x01');
              RGE_Player::set_allied_victory(param_1->players[iVar8],'\x01');
            }
          }
          uVar9 = uVar9 + 1;
        } while ((int)uVar9 < 9);
      }
      uVar5 = uVar5 + 1;
      param_2 = unaff_retaddr;
    } while ((int)uVar5 < 9);
  }
  iVar4 = 0;
  param_1->world_time = 0;
  param_1->old_world_time = 0;
  param_1->world_time_delta = 0;
  param_1->old_time = 0;
  iVar8 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar8 == 0) {
    param_1->game_speed = 1.0;
  }
  else {
    fVar11 = RGE_Base_Game::get_game_speed(rge_base_game);
    param_1->game_speed = fVar11;
  }
  param_1->temp_pause = '\0';
  param_1->world_time_delta_seconds = 0.0;
  bVar1 = false;
  if (*(int *)(param_2 + 0x298) == 0) {
    if (*(char *)(param_2 + 0x2a8) == '\0') {
      cVar2 = (**(code **)(param_1->_padding_ + 100))();
      bVar1 = true;
    }
    else {
      cVar2 = (**(code **)(param_1->_padding_ + 0x74))();
    }
  }
  else {
    cVar2 = (**(code **)(param_1->_padding_ + 0x78))(*(int *)(param_2 + 0x298));
  }
  RGE_Game_World::initializePathingSystem(param_1);
  if (0 < param_1->player_num) {
    do {
      if (param_1->players[iVar4] != (RGE_Player *)0x0) {
        (**(code **)(param_1->players[iVar4]->_padding_ + 0x90))();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1->player_num);
  }
  if (cVar2 != '\0') {
    param_1->game_state = '\0';
  }
  uVar5 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x5b2);
  param_1->random_seed = uVar5;
  TDebuggingLog::Log(L,(char *)L,s___World__end_of_new_game__rand__,uVar5);
  (**(code **)(rge_base_game->_padding_ + 0x20))(0x277b,&stack0xfffffef4,0x100);
  uVar12 = (undefined1)((uint)param_2 >> 0x18);
  iVar8 = 1;
  if ((bVar1) && (1 < param_1->player_num)) {
    do {
      if (param_1->players[iVar8] != (RGE_Player *)0x0) {
        (**(code **)(param_1->players[iVar8]->_padding_ + 0x2c))
                  (&stack0xfffffee8,&stack0xfffffee8,&stack0xfffffee8,0,
                   (int)*(short *)(iStack_14 + 0x2a0));
      }
      uVar12 = (undefined1)((uint)param_2 >> 0x18);
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_1->player_num);
  }
  return uVar12;
}

// --------------------------------------------------

// Function: FUN_00542d03
// Address: 00542d03
// [HELPER] s_C__msdev_work_age1_x1_World_cpp: "C:\msdev\work\age1_x1\World.cpp"
// [HELPER] s___World__after_map_gen__rand__d_: "  World: after_map_gen (rand=%d)"
// [HELPER] s___World__after_player_random_sta: "  World: after_player_random_start (rand=%d)"
// [HELPER] s___World__after_player_update__ra: "  World: after_player_update (rand=%d)"
// [HELPER] s___World__before_map_gen__rand__d: "  World: before_map_gen (rand=%d)"
undefined4 __thiscall FUN_00542d03(RGE_Game_World *param_1,int param_2)
{
  short sVar1;
  uint uVar2;
  int iVar3;
  TDebuggingLog *this;
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  short sVar4;
  
  world_update_counter = 0;
  iVar3 = param_1->_padding_;
  (**(code **)(iVar3 + 0xa8))(param_2);
  (**(code **)(iVar3 + 0xf0))(param_1);
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x612);
  param_1->random_seed = uVar2;
  TDebuggingLog::Log(this,(char *)L,s___World__before_map_gen__rand__d,uVar2);
  iVar3 = param_1->player_num + -1;
  (**(code **)(param_1->map->_padding_ + 0x28))
            (param_1,0xffffffff,0xffffffff,
             CONCAT31((int3)((uint)iVar3 >> 8),*(undefined1 *)(param_2 + 0x2a0)),iVar3);
  RGE_Game_World::initializePathingSystem(param_1);
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x61a);
  param_1->random_seed = uVar2;
  TDebuggingLog::Log(L,(char *)L,s___World__after_map_gen__rand__d_,uVar2);
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x622);
  param_1->random_seed = uVar2;
  TDebuggingLog::Log(this_00,(char *)L,s___World__after_player_random_sta,uVar2);
  sVar1 = param_1->curr_player;
  param_1->curr_player = -1;
  iVar3 = 3;
  do {
    sVar4 = 0;
    world_update_counter = world_update_counter + 1;
    if (0 < param_1->player_num) {
      do {
        if (param_1->players[sVar4] != (RGE_Player *)0x0) {
          (**(code **)(param_1->players[sVar4]->_padding_ + 0x7c))();
        }
        sVar4 = sVar4 + 1;
      } while (sVar4 < param_1->player_num);
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  param_1->curr_player = sVar1;
  uVar2 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x631);
  param_1->random_seed = uVar2;
  TDebuggingLog::Log(this_01,(char *)L,s___World__after_player_update__ra,uVar2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00542e4a
// Address: 00542e4a
void __thiscall FUN_00542e4a(int param_1,ulong param_2)
{
  if ((int)*(short *)(param_1 + 0x2c) <= *(int *)(param_1 + 0x20)) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  RGE_Sound::update(*(RGE_Sound **)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x20) * 4),param_2
                   );
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00542e81
// Address: 00542e81
void __thiscall FUN_00542e81(int param_1,ulong param_2)
{
  RGE_Sprite *this;
  
  if ((int)*(short *)(param_1 + 0x34) <= *(int *)(param_1 + 0x24)) {
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  this = *(RGE_Sprite **)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x24) * 4);
  if (this != (RGE_Sprite *)0x0) {
    RGE_Sprite::update(this,param_2);
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00542ec5
// Address: 00542ec5
// [HELPER] s_AILog__s_log: "AILog\%s.log"
// [HELPER] s_C__msdev_work_age1_x1_World_cpp: "C:\msdev\work\age1_x1\World.cpp"
// [HELPER] s_GAME_OVER__: "GAME OVER!\n"
// [HELPER] s__Status_Log_at_GameTime__02ld__0: "\nStatus Log at GameTime %02ld:%02ld:%02ld:\n"
// [HELPER] s___Player___d_Lost__: "  Player #%d Lost.\n"
// [HELPER] s___Player___d_Won__: "  Player #%d Won.\n"
// [HELPER] s_a: "a"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uchar __fastcall FUN_00542ec5(RGE_Game_World *param_1)
{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  bool bVar9;
  undefined1 auStack_100 [256];
  
  bVar9 = false;
  param_1->availableComputerPlayerUpdateTime = param_1->maximumComputerPlayerUpdateTime;
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_World_cpp,0x68e);
  iVar2 = TCommunications_Handler::DoCycle(param_1->commands->com_hand,param_1->world_time);
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_World_cpp,0x690);
  RGE_Base_Game::add_to_timing(rge_base_game,0xe,uVar3 - uVar1);
  if (iVar2 == 0) {
    param_1->world_time_delta = 0;
    return param_1->game_state;
  }
  visible_combats = 0;
  debug_random_on = 1;
  debug_timeGetTime_on = 1;
  if (do_fixed_update != 0) {
    iVar2 = fixed_update_time;
  }
  debug_srand(s_C__msdev_work_age1_x1_World_cpp,0x6a2,param_1->random_seed);
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_World_cpp,0x6a4);
  RGE_Game_World::update_sounds(param_1,uVar1);
  RGE_Game_World::update_sprites(param_1,uVar1);
  if (iVar2 == -1) {
    bVar9 = param_1->old_time == 0;
  }
  param_1->old_time = uVar1;
  uVar1 = param_1->world_time;
  param_1->old_world_time = uVar1;
  if (param_1->temp_pause == '\0') {
    iVar2 = __ftol();
    param_1->world_time = iVar2 + uVar1;
  }
  else {
    if (iVar2 != -1) {
      iVar2 = __ftol();
      param_1->world_time = iVar2 + uVar1;
    }
    param_1->temp_pause = '\0';
  }
  uVar1 = param_1->world_time - param_1->old_world_time;
  param_1->world_time_delta = uVar1;
  if ((uVar1 != 0) || (bVar9)) {
    RGE_Command::do_commands(param_1->commands);
    RGE_Scenario::update(param_1->scenario);
    iVar2 = 0;
    param_1->world_time_delta_seconds = (float)param_1->world_time_delta * _DAT_00577a14;
    world_update_counter = world_update_counter + 1;
    if (0 < param_1->player_num) {
      puVar8 = param_1->player_time_delta;
      do {
        if (param_1->players[iVar2] != (RGE_Player *)0x0) {
          *puVar8 = *puVar8 + param_1->world_time_delta;
          (**(code **)(param_1->players[iVar2]->_padding_ + 0x7c))();
          RGE_Tile_List::del_list(&param_1->players[iVar2]->tile_list);
        }
        iVar2 = iVar2 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar2 < param_1->player_num);
    }
    if (MouseSystem != (TMousePointer *)0x0) {
      TMousePointer::Poll(MouseSystem);
    }
    uVar4 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x6e2);
    iVar2 = 0;
    if (0 < param_1->player_num) {
      do {
        if (param_1->players[iVar2] != (RGE_Player *)0x0) {
          RGE_Object_List::update(param_1->players[iVar2]->doppleganger_objects);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1->player_num);
    }
    iVar2 = 0;
    if (0 < param_1->player_num) {
      do {
        if (param_1->players[iVar2] != (RGE_Player *)0x0) {
          RGE_Doppleganger_Creator::perform_doppleganger_checks
                    (param_1->players[iVar2]->doppleganger_creator);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1->player_num);
    }
    debug_srand(s_C__msdev_work_age1_x1_World_cpp,0x6f6,uVar4);
    param_1->player_time_delta[param_1->player_turn] = 0;
    iVar2 = param_1->player_turn + 1;
    param_1->player_turn = iVar2;
    if (param_1->player_num <= iVar2) {
      param_1->player_turn = 0;
    }
    (**(code **)(param_1->_padding_ + 0xc4))();
  }
  uVar4 = debug_rand(s_C__msdev_work_age1_x1_World_cpp,0x71a);
  param_1->random_seed = uVar4;
  debug_random_on = 0;
  debug_timeGetTime_on = 0;
  TCommunications_Handler::LastWorldRandom(param_1->commands->com_hand,param_1->random_seed);
  if (logStatusOn == 1) {
    if (param_1->game_state != '\x01') {
      if ((30000 < param_1->world_time - lastStatusLogTime) || (lastStatusLogTime == 0)) {
        if (logStatusFile == (_iobuf *)0x0) {
          pcVar5 = RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info);
          sprintf(auStack_100,s_AILog__s_log,pcVar5);
          logStatusFile = (_iobuf *)fopen(auStack_100,s_a);
          if (logStatusFile == (_iobuf *)0x0) goto LAB_00543368;
        }
        uVar6 = 0;
        uVar7 = 0;
        uVar4 = param_1->world_time / 1000;
        if (0x3b < uVar4) {
          uVar6 = uVar4 / 0x3c;
          uVar4 = uVar4 % 0x3c;
          if (0x3b < uVar6) {
            uVar7 = uVar6 / 0x3c;
            uVar6 = uVar6 % 0x3c;
          }
        }
        if (lastStatusLogTime == 0) {
          (**(code **)(param_1->_padding_ + 0x9c))(logStatusFile,1);
        }
        else {
          fprintf(logStatusFile,s__Status_Log_at_GameTime__02ld__0,uVar7,uVar6,uVar4);
        }
        iVar2 = 1;
        if (1 < param_1->player_num) {
          do {
            if (param_1->players[iVar2] != (RGE_Player *)0x0) {
              (**(code **)(param_1->players[iVar2]->_padding_ + 0xec))
                        (logStatusFile,lastStatusLogTime == 0);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < param_1->player_num);
        }
        lastStatusLogTime = param_1->world_time + 1;
      }
      goto LAB_005432e7;
    }
  }
  else {
LAB_005432e7:
    if (param_1->game_state != '\x01') goto LAB_00543368;
  }
  iVar2 = 1;
  if ((logStatusOn == 1) && (logStatusFile != (_iobuf *)0x0)) {
    fprintf(logStatusFile,s_GAME_OVER__);
    if (1 < param_1->player_num) {
      do {
        if (param_1->players[iVar2] != (RGE_Player *)0x0) {
          if (param_1->players[iVar2]->game_status == '\x01') {
            pcVar5 = s___Player___d_Won__;
          }
          else {
            pcVar5 = s___Player___d_Lost__;
          }
          fprintf(logStatusFile,pcVar5,iVar2);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1->player_num);
    }
    fclose(logStatusFile);
    logStatusFile = (_iobuf *)0x0;
  }
LAB_00543368:
  return param_1->game_state;
}

// --------------------------------------------------

// Function: FUN_00543376
// Address: 00543376
bool __thiscall FUN_00543376(int param_1,int param_2)
{
  return *(int *)(param_1 + 0xb0) == param_2;
}

// --------------------------------------------------

// Function: FUN_00543394
// Address: 00543394
undefined4 __thiscall FUN_00543394(int param_1,int param_2)
{
  return *(undefined4 *)(param_1 + 0xb4 + param_2 * 4);
}

// --------------------------------------------------

// Function: FUN_005433ae
// Address: 005433ae
undefined1 __fastcall FUN_005433ae(int param_1)
{
  return *(undefined1 *)(param_1 + 0x1d);
}

// --------------------------------------------------

// Function: FUN_005433b4
// Address: 005433b4
undefined1 __fastcall FUN_005433b4(int param_1)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar4 = 1;
  iVar2 = 0;
  iVar3 = 0;
  iStack_4 = 0;
  iStack_c = 0;
  iStack_8 = 0;
  if (1 < *(short *)(param_1 + 0x3c)) {
    do {
      uVar1 = RGE_Player::check_victory(*(RGE_Player **)(*(int *)(param_1 + 0x40) + iVar4 * 4));
      if (uVar1 == '\0') {
        iStack_4 = iStack_4 + 1;
        if ((iVar3 < 1) || (iVar2 == 0)) {
          iVar2 = 1;
          iVar3 = iVar4;
        }
        else if (((*(char *)(*(int *)(*(int *)(param_1 + 0x40) + iVar4 * 4) + 0x104) == '\0') ||
                 (uVar1 = RGE_Player::relation
                                    (*(RGE_Player **)(*(int *)(param_1 + 0x40) + iVar3 * 4),iVar4),
                 uVar1 != '\0')) ||
                (uVar1 = RGE_Player::relation
                                   (*(RGE_Player **)(*(int *)(param_1 + 0x40) + iVar4 * 4),iVar3),
                uVar1 != '\0')) {
          iVar2 = -1;
        }
      }
      else if (uVar1 == '\x01') {
        iStack_c = iStack_c + 1;
      }
      else if (uVar1 == '\x02') {
        iStack_8 = iStack_8 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(short *)(param_1 + 0x3c));
  }
  if (iStack_c < 1) {
    uVar1 = RGE_Scenario::Get_conquest_victory(*(RGE_Scenario **)(param_1 + 0x5c));
    if ((uVar1 != '\0') && (((0 < iStack_8 && (0 < iVar2)) || (iStack_4 == 0)))) {
      iVar3 = 1;
      *(undefined1 *)(param_1 + 0x1d) = 1;
      if (1 < *(short *)(param_1 + 0x3c)) {
        do {
          RGE_Player::victory_if_game_on(*(RGE_Player **)(*(int *)(param_1 + 0x40) + iVar3 * 4));
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(short *)(param_1 + 0x3c));
      }
      *(undefined1 *)(param_1 + 0x1e) = 1;
    }
  }
  else {
    iVar3 = 1;
    *(undefined1 *)(param_1 + 0x1d) = 1;
    if (1 < *(short *)(param_1 + 0x3c)) {
      do {
        RGE_Player::loss_if_game_on(*(RGE_Player **)(*(int *)(param_1 + 0x40) + iVar3 * 4));
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(short *)(param_1 + 0x3c));
    }
  }
  if ((*(char *)(param_1 + 0x1d) == '\x01') && (-1 < *(int *)(param_1 + 0xa4))) {
    uVar1 = RGE_Base_Game::set_campaign_info
                      (rge_base_game,*(int *)(param_1 + 0xa4),*(long *)(param_1 + 0xa8),
                       *(long *)(param_1 + 0xac));
    if (uVar1 == '\0') {
      *(undefined4 *)(param_1 + 0xa4) = 0xffffffff;
    }
    else if (*(char *)(*(int *)(*(int *)(param_1 + 0x40) + *(short *)(param_1 + 0x7c) * 4) + 0x80)
             == '\x01') {
      RGE_Base_Game::set_campaign_win(rge_base_game);
      return *(undefined1 *)(param_1 + 0x1d);
    }
  }
  return *(undefined1 *)(param_1 + 0x1d);
}

// --------------------------------------------------

// Function: FUN_0054353e
// Address: 0054353e
void __thiscall FUN_0054353e(int param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  
  iVar2 = param_2;
  color_log('$','$',1);
  save_game_version = 7.23;
  rge_write(param_2,(void *)(param_1 + 4),4);
  rge_write(param_2,(void *)(param_1 + 8),4);
  rge_write(param_2,(void *)(param_1 + 0xc),4);
  rge_write(param_2,(void *)(param_1 + 0x84),4);
  rge_write(param_2,(void *)(param_1 + 0x10),4);
  rge_write(param_2,(void *)(param_1 + 0x18),4);
  rge_write(param_2,(void *)(param_1 + 0x1c),1);
  rge_write(param_2,(void *)(param_1 + 0x68),4);
  rge_write(param_2,(void *)(param_1 + 0x6c),4);
  rge_write(param_2,(void *)(param_1 + 0x78),4);
  rge_write(param_2,(void *)(param_1 + 0x7c),2);
  psVar1 = (short *)(param_1 + 0x3c);
  rge_write(param_2,psVar1,2);
  rge_write(param_2,(void *)(param_1 + 0x1d),1);
  rge_write(param_2,(void *)(param_1 + 0xa4),4);
  rge_write(param_2,(void *)(param_1 + 0xa8),4);
  rge_write(param_2,(void *)(param_1 + 0xac),4);
  rge_write(param_2,(void *)(param_1 + 0xb0),4);
  pvVar3 = (void *)(param_1 + 0xb4);
  param_2 = 9;
  do {
    rge_write(iVar2,pvVar3,4);
    pvVar3 = (void *)((int)pvVar3 + 4);
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  RGE_Map::save_map(*(RGE_Map **)(param_1 + 0x28),iVar2);
  iVar4 = 0;
  if (0 < *psVar1) {
    do {
      color_log('$','L',1);
      (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar4 * 4) + 0x84))(iVar2);
      color_log('$','\x16',1);
      (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar4 * 4) + 0x88))(iVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *psVar1);
  }
  color_log('$','2',1);
  iVar4 = 0;
  if (0 < *psVar1) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar4 * 4) + 0x8c))(iVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *psVar1);
  }
  color_log('$','E',1);
  (**(code **)(**(int **)(param_1 + 0x5c) + 0xc))(iVar2);
  color_log('$','_',1);
  if (*(int *)(param_1 + 0x100) == -1) {
    iVar4 = RGE_Base_Game::difficulty(rge_base_game);
    *(int *)(param_1 + 0x100) = iVar4;
  }
  rge_write(iVar2,(int *)(param_1 + 0x100),4);
  return;
}

// --------------------------------------------------

// Function: FUN_00543844
// Address: 00543844
// [HELPER] s_VER_3_7: "VER 3.7"
void __thiscall FUN_00543844(int param_1,int param_2)
{
  short *psVar1;
  void *pvVar2;
  RGE_Sprite *this;
  int iVar3;
  
  rge_write(param_2,&s_VER_3_7,8);
  psVar1 = (short *)(param_1 + 0x50);
  rge_write(param_2,psVar1,2);
  rge_write(param_2,(short *)(param_1 + 0x52),2);
  if ((0 < *psVar1) && (0 < *(short *)(param_1 + 0x52))) {
    rge_write(param_2,*(void **)(param_1 + 0x54),(int)*psVar1 << 2);
    iVar3 = 0;
    if (0 < *psVar1) {
      do {
        pvVar2 = *(void **)(*(int *)(param_1 + 0x54) + iVar3 * 4);
        if (pvVar2 != (void *)0x0) {
          rge_write(param_2,pvVar2,(int)*(short *)(param_1 + 0x52) << 2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *psVar1);
    }
  }
  psVar1 = (short *)(param_1 + 0x60);
  rge_write(param_2,psVar1,2);
  iVar3 = 0;
  if (0 < *psVar1) {
    do {
      RGE_Color_Table::save(*(RGE_Color_Table **)(*(int *)(param_1 + 100) + iVar3 * 4),param_2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *psVar1);
  }
  psVar1 = (short *)(param_1 + 0x2c);
  rge_write(param_2,psVar1,2);
  iVar3 = 0;
  if (0 < *psVar1) {
    do {
      RGE_Sound::save(*(RGE_Sound **)(*(int *)(param_1 + 0x30) + iVar3 * 4),param_2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *psVar1);
  }
  psVar1 = (short *)(param_1 + 0x34);
  rge_write(param_2,psVar1,2);
  rge_write(param_2,*(void **)(param_1 + 0x38),(int)*psVar1 << 2);
  iVar3 = 0;
  if (0 < *psVar1) {
    do {
      this = *(RGE_Sprite **)(*(int *)(param_1 + 0x38) + iVar3 * 4);
      if (this != (RGE_Sprite *)0x0) {
        RGE_Sprite::save(this,param_2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *psVar1);
  }
  (**(code **)(**(int **)(param_1 + 0x28) + 0x2c))(param_2);
  (**(code **)(**(int **)(param_1 + 0x4c) + 4))(param_2);
  psVar1 = (short *)(param_1 + 0x44);
  rge_write(param_2,psVar1,2);
  iVar3 = 0;
  if (0 < *psVar1) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0x48) + iVar3 * 4) + 0x14))(param_2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *psVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005439ba
// Address: 005439ba
void __thiscall FUN_005439ba(int *param_1,char *param_2)
{
  int iVar1;
  
  iVar1 = rge_open(param_2,0x8309,0x180);
  if (iVar1 != -1) {
    (**(code **)(*param_1 + 0xe0))(iVar1);
    rge_close(iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005439fb
// Address: 005439fb
// [HELPER] s_1_10: "1.10"
// [HELPER] s_1_11: "1.11"
// [HELPER] s_TRIAL: "TRIAL"
// [HELPER] s__s_s: "%s%s"
// [HELPER] s__s_s_scn: "%s%s.scn"
uint __thiscall FUN_005439fb(int param_1,char *param_2)
{
  int *piVar1;
  uchar uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  int iStack_268;
  int iStack_264;
  undefined1 auStack_260 [4];
  int iStack_25c;
  char acStack_258 [300];
  char acStack_12c [300];
  
  iStack_25c = (int)*(short *)(param_1 + 0x3c);
  cVar6 = *param_2;
  pcVar3 = param_2;
  iVar4 = 0;
  do {
    iVar7 = iVar4;
    pcVar3[(int)(acStack_12c + -(int)param_2)] = cVar6;
    cVar6 = pcVar3[1];
    pcVar3 = pcVar3 + 1;
    iVar4 = iVar7 + 1;
  } while (cVar6 != '.');
  acStack_12c[iVar7 + 1] = '\0';
  sprintf(acStack_258,s__s_s_scn,rge_base_game->prog_info->scenario_dir,acStack_12c);
  __unlink(acStack_258);
  sprintf(acStack_258,s__s_s,rge_base_game->prog_info->scenario_dir,param_2);
  iVar4 = rge_open(acStack_258,0x8301,0x180);
  if (iVar4 == -1) {
    return 0xffffff00;
  }
  rge_write_error = 0;
  uVar2 = RGE_Base_Game::check_prog_argument(rge_base_game,s_TRIAL);
  if (uVar2 == '\x01') {
    pcVar3 = s_1_10;
  }
  else {
    pcVar3 = s_1_11;
  }
  rge_write_uncompressed(iVar4,pcVar3,4);
  RGE_Base_Game::write_scenario_header(rge_base_game,iVar4);
  rge_write(iVar4,(void *)(param_1 + 0x68),4);
  (**(code **)(**(int **)(param_1 + 0x5c) + 0xc))(iVar4);
  RGE_Map::scenario_save(*(RGE_Map **)(param_1 + 0x28),iVar4);
  rge_write(iVar4,auStack_260,4);
  iVar7 = 1;
  if (1 < *(short *)(param_1 + 0x3c)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar7 * 4) + 100))(iVar4);
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(short *)(param_1 + 0x3c));
  }
  iStack_264 = 0;
  if (0 < *(short *)(param_1 + 0x3c)) {
    do {
      iVar7 = iStack_264;
      iStack_268 = 0;
      for (piVar1 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + iStack_264 * 4) + 0x28) +
                             4); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
        if (*(char *)(*(int *)(*piVar1 + 8) + 4) != '\x19') {
          iStack_268 = iStack_268 + 1;
        }
      }
      for (piVar1 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + iStack_264 * 4) + 0x2c) +
                             4); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
        if (*(char *)(*(int *)(*piVar1 + 8) + 4) != '\x19') {
          iStack_268 = iStack_268 + 1;
        }
      }
      rge_write(iVar4,&iStack_268,4);
      for (piVar1 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + iVar7 * 4) + 0x28) + 4);
          piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
        if (*(char *)(*(int *)(*piVar1 + 8) + 4) != '\x19') {
          rge_write(iVar4,(void *)(*piVar1 + 0x38),4);
          rge_write(iVar4,(void *)(*piVar1 + 0x3c),4);
          rge_write(iVar4,(void *)(*piVar1 + 0x40),4);
          rge_write(iVar4,(void *)(*piVar1 + 4),4);
          rge_write(iVar4,(void *)(*(int *)(*piVar1 + 8) + 0x10),2);
          rge_write(iVar4,(void *)(*piVar1 + 0x48),1);
          rge_write(iVar4,&stack0xfffffd94,4);
        }
      }
      for (piVar1 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + iStack_264 * 4) + 0x2c) +
                             4); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
        if (*(char *)(*(int *)(*piVar1 + 8) + 4) != '\x19') {
          rge_write(iVar4,(void *)(*piVar1 + 0x38),4);
          rge_write(iVar4,(void *)(*piVar1 + 0x3c),4);
          rge_write(iVar4,(void *)(*piVar1 + 0x40),4);
          rge_write(iVar4,(void *)(*piVar1 + 4),4);
          rge_write(iVar4,(void *)(*(int *)(*piVar1 + 8) + 0x10),2);
          rge_write(iVar4,(void *)(*piVar1 + 0x48),1);
          rge_write(iVar4,&stack0xfffffd94,4);
        }
      }
      iStack_264 = iStack_264 + 1;
    } while (iStack_264 < *(short *)(param_1 + 0x3c));
  }
  rge_write(iVar4,auStack_260,4);
  iVar7 = 1;
  if (1 < *(short *)(param_1 + 0x3c)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0x40) + iVar7 * 4) + 0x6c))(iVar4);
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(short *)(param_1 + 0x3c));
  }
  rge_close(iVar4);
  if (rge_write_error != 0) {
    uVar5 = __unlink(&iStack_25c);
    return uVar5 & 0xffffff00;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00543df9
// Address: 00543df9
// [HELPER] s_1_01: "1.01"
// [HELPER] s_1_02: "1.02"
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
undefined4 __thiscall FUN_00543df9(int *param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iStack_134;
  int iStack_130;
  char acStack_12c [300];
  
  world_update_counter = 0;
  sprintf(acStack_12c,s__s_s,rge_base_game->prog_info->scenario_dir,param_2);
  if (param_2 != 0) {
    iVar2 = rge_open(acStack_12c,0x8000);
    if (iVar2 != -1) {
      rge_read_uncompressed(iVar2,&iStack_130,4);
      if (iStack_130 == s_1_01._0_4_) {
        iVar1 = *param_1;
        (**(code **)(iVar1 + 0x7c))(iVar2,param_3);
        (**(code **)(iVar1 + 0xa8))(param_3);
        return 1;
      }
      if (iStack_130 == s_1_02._0_4_) goto LAB_00543efd;
      if (iStack_130 == s_1_03._0_4_) {
        rge_read_uncompressed(iVar2,&iStack_134,4);
        if (iStack_134 < 1) {
LAB_00543efd:
          iVar1 = *param_1;
          (**(code **)(iVar1 + 0x80))(iVar2,param_3);
          (**(code **)(iVar1 + 0xa8))(param_3);
          return 1;
        }
        pvVar3 = (void *)malloc(iStack_134);
        if (pvVar3 != (void *)0x0) {
          rge_read_uncompressed(iVar2,pvVar3,iStack_134);
          free(pvVar3);
          goto LAB_00543efd;
        }
      }
      else {
        if (iStack_130 == s_1_04._0_4_) {
          iVar1 = *param_1;
          (**(code **)(iVar1 + 0x84))(iVar2,param_3);
          (**(code **)(iVar1 + 0xa8))(param_3);
          return 1;
        }
        if (iStack_130 == s_1_05._0_4_) {
          iVar1 = *param_1;
          (**(code **)(iVar1 + 0x88))(iVar2,param_3);
          (**(code **)(iVar1 + 0xa8))(param_3);
          return 1;
        }
        if (iStack_130 == s_1_06._0_4_) {
          iVar1 = *param_1;
          (**(code **)(iVar1 + 0x8c))(iVar2,param_3);
          (**(code **)(iVar1 + 0xa8))(param_3);
          return 1;
        }
        if (iStack_130 == s_1_07._0_4_) {
          iVar1 = *param_1;
          (**(code **)(iVar1 + 0x90))(iVar2,param_3);
          (**(code **)(iVar1 + 0xa8))(param_3);
          return 1;
        }
        if (iStack_130 == s_1_08._0_4_) {
          iVar1 = *param_1;
          (**(code **)(iVar1 + 0x94))(iVar2,param_3);
          (**(code **)(iVar1 + 0xa8))(param_3);
          return 1;
        }
        if (((iStack_130 == s_1_09._0_4_) || (iStack_130 == s_1_11._0_4_)) ||
           (iStack_130 == s_1_10._0_4_)) {
          iVar1 = *param_1;
          (**(code **)(iVar1 + 0x98))(iVar2,param_3);
          (**(code **)(iVar1 + 0xa8))(param_3);
          return 1;
        }
      }
      rge_close(iVar2);
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00544082
// Address: 00544082
// [HELPER] s_1_01: "1.01"
// [HELPER] s_1_02: "1.02"
// [HELPER] s_1_03: "1.03"
// [HELPER] s_1_04: "1.04"
// [HELPER] s_1_05: "1.05"
// [HELPER] s_1_06: "1.06"
// [HELPER] s_1_07: "1.07"
// [HELPER] s_1_08: "1.08"
// [HELPER] s_1_09: "1.09"
// [HELPER] s_1_10: "1.10"
// [HELPER] s_1_11: "1.11"
undefined4 __thiscall FUN_00544082(int *param_1,undefined4 param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iStack_8;
  int iStack_4;
  
  world_update_counter = 0;
  iVar1 = RGE_Base_Game::campaign_open_scenario(rge_base_game);
  if (iVar1 == -1) {
    return 0;
  }
  rge_read_uncompressed(iVar1,&iStack_4,4);
  if (iStack_4 == s_1_01._0_4_) {
    iVar3 = *param_1;
    (**(code **)(iVar3 + 0x7c))(iVar1,param_2);
  }
  else {
    if (iStack_4 != s_1_02._0_4_) {
      if (iStack_4 != s_1_03._0_4_) {
        if (iStack_4 == s_1_04._0_4_) {
          iVar3 = *param_1;
          (**(code **)(iVar3 + 0x84))(iVar1,param_2);
        }
        else if (iStack_4 == s_1_05._0_4_) {
          iVar3 = *param_1;
          (**(code **)(iVar3 + 0x88))(iVar1,param_2);
        }
        else if (iStack_4 == s_1_06._0_4_) {
          iVar3 = *param_1;
          (**(code **)(iVar3 + 0x8c))(iVar1,param_2);
        }
        else if (iStack_4 == s_1_07._0_4_) {
          iVar3 = *param_1;
          (**(code **)(iVar3 + 0x90))(iVar1,param_2);
        }
        else if (iStack_4 == s_1_08._0_4_) {
          iVar3 = *param_1;
          (**(code **)(iVar3 + 0x94))(iVar1,param_2);
        }
        else {
          if (((iStack_4 != s_1_09._0_4_) && (iStack_4 != s_1_11._0_4_)) &&
             (iStack_4 != s_1_10._0_4_)) goto LAB_00544233;
          iVar3 = *param_1;
          (**(code **)(iVar3 + 0x98))(iVar1,param_2);
        }
        goto LAB_005441fe;
      }
      rge_read_uncompressed(iVar1,&iStack_8,4);
      if (0 < iStack_8) {
        pvVar2 = (void *)malloc(iStack_8);
        if (pvVar2 == (void *)0x0) {
LAB_00544233:
          rge_close(iVar1);
          return 0;
        }
        rge_read_uncompressed(iVar1,pvVar2,iStack_8);
        free(pvVar2);
      }
    }
    iVar3 = *param_1;
    (**(code **)(iVar3 + 0x80))(iVar1,param_2);
  }
LAB_005441fe:
  (**(code **)(iVar3 + 0xa8))(param_2);
  RGE_Base_Game::get_campaign_info(rge_base_game,param_1 + 0x29,param_1 + 0x2a,param_1 + 0x2b);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00544248
// Address: 00544248
void __thiscall
FUN_00544248(RGE_Game_World *param_1,short param_2,undefined4 param_3,char param_4,byte param_5,
            char *param_6)
{
  RGE_Player *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561e6b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_4 == '\0') {
    pRVar1 = (RGE_Player *)operator_new(0x220);
    uStack_4 = 0;
    if (pRVar1 == (RGE_Player *)0x0) {
      pRVar1 = (RGE_Player *)0x0;
    }
    else {
      pRVar1 = (RGE_Player *)
               RGE_Player::RGE_Player
                         (pRVar1,param_1,param_1->master_players[param_5],(uchar)param_2,param_6,
                          param_5,'\x01');
    }
    param_1->players[param_2] = pRVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_005442d4
// Address: 005442d4
void __thiscall FUN_005442d4(int param_1,int param_2)
{
  RGE_Map::scenario_load(*(RGE_Map **)(param_1 + 0x28),param_2,(uchar *)0x0);
  return;
}

// --------------------------------------------------

// Function: FUN_005442f2
// Address: 005442f2
void __thiscall FUN_005442f2(int *param_1,int param_2)
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int unaff_EBX;
  int unaff_EBP;
  int iVar8;
  undefined4 uVar9;
  int iStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  int aiStack_30 [10];
  undefined1 auStack_8 [4];
  int iStack_4;
  
  rge_read(param_2,auStack_38,4);
  iVar7 = *param_1;
  (**(code **)(iVar7 + 0xf4))(param_2,param_1);
  (**(code **)(iVar7 + 0x70))(param_2);
  iVar7 = (int)(short)param_1[0xf];
  if (0 < iVar7) {
    do {
      piVar5 = aiStack_30;
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar5 = -1;
        piVar5 = piVar5 + 1;
      }
    } while (10 < iVar7);
  }
  iVar4 = 0;
  if (0 < iVar7) {
    piVar5 = (int *)(iStack_4 + 0x270);
    do {
      iVar8 = *piVar5;
      piVar5 = piVar5 + 1;
      aiStack_30[iVar8] = iVar4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar7);
  }
  iVar4 = 0;
  if (0 < iVar7) {
    do {
      RGE_Player::remake_visible_map(*(RGE_Player **)(param_1[0x10] + iVar4 * 4));
      iVar4 = iVar4 + 1;
    } while (iVar4 < (short)param_1[0xf]);
  }
  rge_read(param_2,&stack0xffffff98,4);
  iVar7 = 0;
  if (0 < unaff_EBP) {
    do {
      rge_read(param_2,auStack_8,1);
      rge_read(param_2,&stack0xffffff97,1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < unaff_EBP);
  }
  iVar7 = 0;
  if (0 < unaff_EBP) {
    do {
      rge_read(param_2,&stack0xffffff9c,4);
      iVar4 = 0;
      if (0 < unaff_EBX) {
        do {
          rge_read(param_2,&uStack_48,4);
          rge_read(param_2,&uStack_4c,4);
          rge_read(param_2,&uStack_50,4);
          rge_read(param_2,&iStack_60,4);
          rge_read(param_2,&uStack_54,2);
          rge_read(param_2,&uStack_58,1);
          rge_read(param_2,&uStack_5c,4);
          if (((iVar7 < (short)param_1[0xf]) && (iVar8 = aiStack_30[iVar7], -1 < iVar8)) &&
             (*(int *)(param_1[0x10] + iVar7 * 4) != 0)) {
            *(undefined1 *)(param_1 + 0x1d) = 1;
            param_1[0x1c] = iStack_60;
            (**(code **)(**(int **)(param_1[0x10] + iVar8 * 4) + 0x60))
                      (uStack_48,uStack_4c,uStack_50,uStack_54,uStack_58,uStack_5c);
            *(undefined1 *)(param_1 + 0x1d) = 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < unaff_EBX);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < unaff_EBP);
  }
  param_1[0x1a] = iStack_44;
  rge_read(param_2,auStack_40,0xd);
  iVar7 = 1;
  if (1 < unaff_EBP) {
    piVar5 = aiStack_30;
    do {
      piVar5 = piVar5 + 1;
      if ((((short)param_1[0xf] <= iVar7) || (*piVar5 < 0)) ||
         (piVar6 = *(int **)(param_1[0x10] + *piVar5 * 4), piVar6 == (int *)0x0)) {
        piVar6 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar6 + 0x68))(param_2,aiStack_30,0x3f800000);
      iVar7 = iVar7 + 1;
    } while (iVar7 < unaff_EBP);
  }
  rge_close(param_2);
  iStack_4 = 1;
  if (1 < (short)param_1[0xf]) {
    do {
      if (unaff_EBP <= iStack_4) {
        return;
      }
      if (*(int *)(param_1[0x10] + iStack_4 * 4) != 0) {
        iVar8 = iStack_4 + -1;
        uVar9 = 0xffffffff;
        iVar7 = **(int **)(param_1[0x10] + aiStack_30[iStack_4] * 4);
        iVar4 = RGE_Scenario::GetPlayerPosture((RGE_Scenario *)param_1[0x17],iVar8);
        pcVar1 = RGE_Scenario::Get_player_AI((RGE_Scenario *)param_1[0x17],iVar8,1);
        pcVar2 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)param_1[0x17],iVar8,1);
        pcVar3 = RGE_Scenario::Get_BuildList((RGE_Scenario *)param_1[0x17],iVar8,1);
        (**(code **)(iVar7 + 0x2c))(pcVar3,pcVar2,pcVar1,iVar4,uVar9);
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < (short)param_1[0xf]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005445b3
// Address: 005445b3
void __thiscall FUN_005445b3(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 uVar10;
  int iStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  int aiStack_30 [10];
  undefined1 auStack_8 [4];
  int iStack_4;
  
  world_update_counter = 0;
  rge_read(param_2,auStack_38,4);
  iVar9 = *param_1;
  (**(code **)(iVar9 + 0xf4))(param_2,param_1);
  (**(code **)(iVar9 + 0x70))(param_2);
  iVar9 = (int)(short)param_1[0xf];
  if (0 < iVar9) {
    do {
      piVar7 = aiStack_30;
      for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar7 = -1;
        piVar7 = piVar7 + 1;
      }
    } while (10 < iVar9);
  }
  iVar6 = 0;
  if (0 < iVar9) {
    piVar7 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar7;
      piVar7 = piVar7 + 1;
      aiStack_30[iVar1] = iVar6;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar9);
  }
  iVar6 = 0;
  if (0 < iVar9) {
    do {
      RGE_Player::remake_visible_map(*(RGE_Player **)(param_1[0x10] + iVar6 * 4));
      iVar6 = iVar6 + 1;
    } while (iVar6 < (short)param_1[0xf]);
  }
  rge_read(param_2,&stack0xffffff98,4);
  iVar9 = 0;
  if (0 < unaff_EBP) {
    do {
      rge_read(param_2,auStack_8,1);
      rge_read(param_2,&stack0xffffff97,1);
      iVar9 = iVar9 + 1;
    } while (iVar9 < unaff_EBP);
  }
  iStack_4 = 0;
  if (0 < unaff_EBP) {
    piVar7 = aiStack_30;
    do {
      rge_read(param_2,&stack0xffffff9c,4);
      iVar9 = 0;
      if (0 < unaff_EBX) {
        do {
          rge_read(param_2,&uStack_48,4);
          rge_read(param_2,&uStack_4c,4);
          rge_read(param_2,&uStack_50,4);
          rge_read(param_2,&iStack_60,4);
          rge_read(param_2,&uStack_54,2);
          rge_read(param_2,&uStack_58,1);
          rge_read(param_2,&uStack_5c,4);
          if ((-1 < *piVar7) && (piVar8 = (int *)(param_1[0x10] + *piVar7 * 4), *piVar8 != 0)) {
            *(undefined1 *)(param_1 + 0x1d) = 1;
            param_1[0x1c] = iStack_60;
            (**(code **)(*(int *)*piVar8 + 0x60))
                      (uStack_48,uStack_4c,uStack_50,uStack_54,uStack_58,uStack_5c);
            *(undefined1 *)(param_1 + 0x1d) = 0;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < unaff_EBX);
      }
      iStack_4 = iStack_4 + 1;
      piVar7 = piVar7 + 1;
    } while (iStack_4 < unaff_EBP);
  }
  param_1[0x1a] = iStack_44;
  rge_read(param_2,auStack_40,0xd);
  iVar9 = 1;
  if (1 < unaff_EBP) {
    piVar7 = aiStack_30;
    do {
      piVar7 = piVar7 + 1;
      if ((((short)param_1[0xf] <= iVar9) || (*piVar7 < 0)) ||
         (piVar8 = *(int **)(param_1[0x10] + *piVar7 * 4), piVar8 == (int *)0x0)) {
        piVar8 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar8 + 0x68))(param_2,aiStack_30,0x3f83d70a);
      iVar9 = iVar9 + 1;
    } while (iVar9 < unaff_EBP);
  }
  rge_close(param_2);
  iVar9 = 1;
  if (1 < (short)param_1[0xf]) {
    do {
      if (unaff_EBP <= iVar9) {
        return;
      }
      if ((*(int *)(param_1[0x10] + iVar9 * 4) != 0) && (-1 < aiStack_30[iVar9])) {
        iVar6 = iVar9 + -1;
        uVar10 = 0xffffffff;
        iVar1 = **(int **)(param_1[0x10] + aiStack_30[iVar9] * 4);
        iVar2 = RGE_Scenario::GetPlayerPosture((RGE_Scenario *)param_1[0x17],iVar6);
        pcVar3 = RGE_Scenario::Get_player_AI((RGE_Scenario *)param_1[0x17],iVar6,1);
        pcVar4 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)param_1[0x17],iVar6,1);
        pcVar5 = RGE_Scenario::Get_BuildList((RGE_Scenario *)param_1[0x17],iVar6,1);
        (**(code **)(iVar1 + 0x2c))(pcVar5,pcVar4,pcVar3,iVar2,uVar10);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (short)param_1[0xf]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054487c
// Address: 0054487c
void __thiscall FUN_0054487c(int *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int unaff_EBP;
  undefined4 uVar11;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  int aiStack_30 [10];
  undefined1 auStack_8 [4];
  int iStack_4;
  
  world_update_counter = 0;
  rge_read_uncompressed(param_2,&iStack_5c,4);
  if (0 < iStack_5c) {
    pvVar2 = (void *)malloc(iStack_5c);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_2);
      return;
    }
    rge_read_uncompressed(param_2,pvVar2,iStack_5c);
    free(pvVar2);
  }
  rge_read(param_2,auStack_38,4);
  iVar10 = *param_1;
  (**(code **)(iVar10 + 0xf4))(param_2,param_1);
  (**(code **)(iVar10 + 0x70))(param_2);
  iVar10 = (int)(short)param_1[0xf];
  if (0 < iVar10) {
    do {
      piVar8 = aiStack_30;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar8 = -1;
        piVar8 = piVar8 + 1;
      }
    } while (10 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    piVar8 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      aiStack_30[iVar1] = iVar7;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    do {
      RGE_Player::remake_visible_map(*(RGE_Player **)(param_1[0x10] + iVar7 * 4));
      iVar7 = iVar7 + 1;
    } while (iVar7 < (short)param_1[0xf]);
  }
  rge_read(param_2,&stack0xffffff94,4);
  iVar10 = 0;
  if (0 < unaff_EBP) {
    do {
      rge_read(param_2,auStack_8,1);
      rge_read(param_2,&stack0xffffff93,1);
      iVar10 = iVar10 + 1;
    } while (iVar10 < unaff_EBP);
  }
  iStack_4 = 0;
  if (0 < unaff_EBP) {
    piVar8 = aiStack_30;
    do {
      rge_read(param_2,&iStack_64,4);
      iVar10 = 0;
      if (0 < iStack_64) {
        do {
          rge_read(param_2,&uStack_48,4);
          rge_read(param_2,&uStack_4c,4);
          rge_read(param_2,&uStack_50,4);
          rge_read(param_2,&iStack_60,4);
          rge_read(param_2,&uStack_54,2);
          rge_read(param_2,&uStack_58,1);
          rge_read(param_2,&iStack_5c,4);
          if ((-1 < *piVar8) && (piVar9 = (int *)(param_1[0x10] + *piVar8 * 4), *piVar9 != 0)) {
            *(undefined1 *)(param_1 + 0x1d) = 1;
            param_1[0x1c] = iStack_60;
            (**(code **)(*(int *)*piVar9 + 0x60))
                      (uStack_48,uStack_4c,uStack_50,uStack_54,uStack_58,iStack_5c);
            *(undefined1 *)(param_1 + 0x1d) = 0;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < iStack_64);
      }
      iStack_4 = iStack_4 + 1;
      piVar8 = piVar8 + 1;
    } while (iStack_4 < unaff_EBP);
  }
  param_1[0x1a] = iStack_44;
  rge_read(param_2,auStack_40,0xd);
  iVar10 = 1;
  if (1 < unaff_EBP) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x68))(param_2,aiStack_30,0x3f851eb8);
      iVar10 = iVar10 + 1;
    } while (iVar10 < unaff_EBP);
  }
  rge_close(param_2);
  iVar10 = 1;
  if (1 < (short)param_1[0xf]) {
    do {
      if (unaff_EBP <= iVar10) {
        return;
      }
      if ((*(int *)(param_1[0x10] + iVar10 * 4) != 0) && (-1 < aiStack_30[iVar10])) {
        iVar7 = iVar10 + -1;
        uVar11 = 0xffffffff;
        iVar1 = **(int **)(param_1[0x10] + aiStack_30[iVar10] * 4);
        iVar3 = RGE_Scenario::GetPlayerPosture((RGE_Scenario *)param_1[0x17],iVar7);
        pcVar4 = RGE_Scenario::Get_player_AI((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar5 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar6 = RGE_Scenario::Get_BuildList((RGE_Scenario *)param_1[0x17],iVar7,1);
        (**(code **)(iVar1 + 0x2c))(pcVar6,pcVar5,pcVar4,iVar3,uVar11);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (short)param_1[0xf]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00544b8e
// Address: 00544b8e
void __thiscall FUN_00544b8e(int *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 uVar11;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int aiStack_30 [2];
  undefined1 auStack_28 [32];
  int iStack_8;
  int iStack_4;
  
  world_update_counter = 0;
  rge_read_uncompressed(param_2,&iStack_4c,4);
  if (0 < iStack_4c) {
    pvVar2 = (void *)malloc(iStack_4c);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_2);
      return;
    }
    rge_read_uncompressed(param_2,pvVar2,iStack_4c);
    free(pvVar2);
  }
  rge_read(param_2,auStack_28,4);
  iVar10 = *param_1;
  (**(code **)(iVar10 + 0xf4))(param_2,param_1);
  (**(code **)(iVar10 + 0x70))(param_2);
  iVar10 = (int)(short)param_1[0xf];
  if (0 < iVar10) {
    do {
      piVar8 = aiStack_30;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar8 = -1;
        piVar8 = piVar8 + 1;
      }
    } while (10 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    piVar8 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      aiStack_30[iVar1] = iVar7;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    do {
      RGE_Player::remake_visible_map(*(RGE_Player **)(param_1[0x10] + iVar7 * 4));
      iVar7 = iVar7 + 1;
    } while (iVar7 < (short)param_1[0xf]);
  }
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x68))(param_2,aiStack_30,0x3f851eb8);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  iStack_4 = 0;
  if (0 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      rge_read(param_2,&stack0xffffffac,4);
      iVar10 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_2,&uStack_38,4);
          rge_read(param_2,&uStack_3c,4);
          rge_read(param_2,&uStack_40,4);
          rge_read(param_2,&stack0xffffffb0,4);
          rge_read(param_2,&uStack_44,2);
          rge_read(param_2,&uStack_48,1);
          rge_read(param_2,&iStack_4c,4);
          if ((-1 < *piVar8) && (piVar9 = (int *)(param_1[0x10] + *piVar8 * 4), *piVar9 != 0)) {
            *(undefined1 *)(param_1 + 0x1d) = 1;
            param_1[0x1c] = unaff_EBX;
            (**(code **)(*(int *)*piVar9 + 0x60))
                      (uStack_38,uStack_3c,uStack_40,uStack_44,uStack_48,iStack_4c);
            *(undefined1 *)(param_1 + 0x1d) = 0;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      piVar8 = piVar8 + 1;
    } while (iStack_4 < iStack_8);
  }
  param_1[0x1a] = iStack_34;
  rge_close(param_2);
  iVar10 = 1;
  if (1 < (short)param_1[0xf]) {
    do {
      if (iStack_8 <= iVar10) {
        return;
      }
      if ((*(int *)(param_1[0x10] + iVar10 * 4) != 0) && (-1 < aiStack_30[iVar10])) {
        iVar7 = iVar10 + -1;
        uVar11 = 0xffffffff;
        iVar1 = **(int **)(param_1[0x10] + aiStack_30[iVar10] * 4);
        iVar3 = RGE_Scenario::GetPlayerPosture((RGE_Scenario *)param_1[0x17],iVar7);
        pcVar4 = RGE_Scenario::Get_player_AI((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar5 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar6 = RGE_Scenario::Get_BuildList((RGE_Scenario *)param_1[0x17],iVar7,1);
        (**(code **)(iVar1 + 0x2c))(pcVar6,pcVar5,pcVar4,iVar3,uVar11);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (short)param_1[0xf]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00544e61
// Address: 00544e61
void __thiscall FUN_00544e61(int *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 uVar11;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int aiStack_30 [2];
  undefined1 auStack_28 [32];
  int iStack_8;
  int iStack_4;
  
  world_update_counter = 0;
  rge_read_uncompressed(param_2,&iStack_4c,4);
  if (0 < iStack_4c) {
    pvVar2 = (void *)malloc(iStack_4c);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_2);
      return;
    }
    rge_read_uncompressed(param_2,pvVar2,iStack_4c);
    free(pvVar2);
  }
  rge_read(param_2,auStack_28,4);
  iVar10 = *param_1;
  (**(code **)(iVar10 + 0xf4))(param_2,param_1);
  (**(code **)(iVar10 + 0x70))(param_2);
  iVar10 = (int)(short)param_1[0xf];
  if (0 < iVar10) {
    do {
      piVar8 = aiStack_30;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar8 = -1;
        piVar8 = piVar8 + 1;
      }
    } while (10 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    piVar8 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      aiStack_30[iVar1] = iVar7;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    do {
      RGE_Player::remake_visible_map(*(RGE_Player **)(param_1[0x10] + iVar7 * 4));
      iVar7 = iVar7 + 1;
    } while (iVar7 < (short)param_1[0xf]);
  }
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x68))(param_2,aiStack_30,0x3f87ae14);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  iStack_4 = 0;
  if (0 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      rge_read(param_2,&stack0xffffffac,4);
      iVar10 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_2,&uStack_38,4);
          rge_read(param_2,&uStack_3c,4);
          rge_read(param_2,&uStack_40,4);
          rge_read(param_2,&stack0xffffffb0,4);
          rge_read(param_2,&uStack_44,2);
          rge_read(param_2,&uStack_48,1);
          rge_read(param_2,&iStack_4c,4);
          if ((-1 < *piVar8) && (piVar9 = (int *)(param_1[0x10] + *piVar8 * 4), *piVar9 != 0)) {
            *(undefined1 *)(param_1 + 0x1d) = 1;
            param_1[0x1c] = unaff_EBX;
            (**(code **)(*(int *)*piVar9 + 0x60))
                      (uStack_38,uStack_3c,uStack_40,uStack_44,uStack_48,iStack_4c);
            *(undefined1 *)(param_1 + 0x1d) = 0;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      piVar8 = piVar8 + 1;
    } while (iStack_4 < iStack_8);
  }
  param_1[0x1a] = iStack_34;
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x70))(param_2,aiStack_30,0x3f87ae14);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  rge_close(param_2);
  iVar10 = 1;
  if (1 < (short)param_1[0xf]) {
    do {
      if (iStack_8 <= iVar10) {
        return;
      }
      if ((*(int *)(param_1[0x10] + iVar10 * 4) != 0) && (-1 < aiStack_30[iVar10])) {
        iVar7 = iVar10 + -1;
        uVar11 = 0xffffffff;
        iVar1 = **(int **)(param_1[0x10] + aiStack_30[iVar10] * 4);
        iVar3 = RGE_Scenario::GetPlayerPosture((RGE_Scenario *)param_1[0x17],iVar7);
        pcVar4 = RGE_Scenario::Get_player_AI((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar5 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar6 = RGE_Scenario::Get_BuildList((RGE_Scenario *)param_1[0x17],iVar7,1);
        (**(code **)(iVar1 + 0x2c))(pcVar6,pcVar5,pcVar4,iVar3,uVar11);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (short)param_1[0xf]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0054519c
// Address: 0054519c
void __thiscall FUN_0054519c(int *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 uVar11;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int aiStack_30 [2];
  undefined1 auStack_28 [32];
  int iStack_8;
  int iStack_4;
  
  world_update_counter = 0;
  rge_read_uncompressed(param_2,&iStack_4c,4);
  if (0 < iStack_4c) {
    pvVar2 = (void *)malloc(iStack_4c);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_2);
      return;
    }
    rge_read_uncompressed(param_2,pvVar2,iStack_4c);
    free(pvVar2);
  }
  rge_read(param_2,auStack_28,4);
  iVar10 = *param_1;
  (**(code **)(iVar10 + 0xf4))(param_2,param_1);
  (**(code **)(iVar10 + 0x70))(param_2);
  iVar10 = (int)(short)param_1[0xf];
  if (0 < iVar10) {
    do {
      piVar8 = aiStack_30;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar8 = -1;
        piVar8 = piVar8 + 1;
      }
    } while (10 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    piVar8 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      aiStack_30[iVar1] = iVar7;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    do {
      RGE_Player::remake_visible_map(*(RGE_Player **)(param_1[0x10] + iVar7 * 4));
      iVar7 = iVar7 + 1;
    } while (iVar7 < (short)param_1[0xf]);
  }
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x68))(param_2,aiStack_30,0x3f88f5c3);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  iStack_4 = 0;
  if (0 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      rge_read(param_2,&stack0xffffffac,4);
      iVar10 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_2,&uStack_38,4);
          rge_read(param_2,&uStack_3c,4);
          rge_read(param_2,&uStack_40,4);
          rge_read(param_2,&stack0xffffffb0,4);
          rge_read(param_2,&uStack_44,2);
          rge_read(param_2,&uStack_48,1);
          rge_read(param_2,&iStack_4c,4);
          if ((-1 < *piVar8) && (piVar9 = (int *)(param_1[0x10] + *piVar8 * 4), *piVar9 != 0)) {
            *(undefined1 *)(param_1 + 0x1d) = 1;
            param_1[0x1c] = unaff_EBX;
            (**(code **)(*(int *)*piVar9 + 0x60))
                      (uStack_38,uStack_3c,uStack_40,uStack_44,uStack_48,iStack_4c);
            *(undefined1 *)(param_1 + 0x1d) = 0;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      piVar8 = piVar8 + 1;
    } while (iStack_4 < iStack_8);
  }
  param_1[0x1a] = iStack_34;
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x70))(param_2,aiStack_30,0x3f88f5c3);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  rge_close(param_2);
  iVar10 = 1;
  if (1 < (short)param_1[0xf]) {
    do {
      if (iStack_8 <= iVar10) {
        return;
      }
      if ((*(int *)(param_1[0x10] + iVar10 * 4) != 0) && (-1 < aiStack_30[iVar10])) {
        iVar7 = iVar10 + -1;
        uVar11 = 0xffffffff;
        iVar1 = **(int **)(param_1[0x10] + aiStack_30[iVar10] * 4);
        iVar3 = RGE_Scenario::GetPlayerPosture((RGE_Scenario *)param_1[0x17],iVar7);
        pcVar4 = RGE_Scenario::Get_player_AI((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar5 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar6 = RGE_Scenario::Get_BuildList((RGE_Scenario *)param_1[0x17],iVar7,1);
        (**(code **)(iVar1 + 0x2c))(pcVar6,pcVar5,pcVar4,iVar3,uVar11);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (short)param_1[0xf]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005454cc
// Address: 005454cc
void __thiscall FUN_005454cc(int *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 uVar11;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int aiStack_30 [2];
  undefined1 auStack_28 [32];
  int iStack_8;
  int iStack_4;
  
  world_update_counter = 0;
  rge_read_uncompressed(param_2,&iStack_4c,4);
  if (0 < iStack_4c) {
    pvVar2 = (void *)malloc(iStack_4c);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_2);
      return;
    }
    rge_read_uncompressed(param_2,pvVar2,iStack_4c);
    free(pvVar2);
  }
  rge_read(param_2,auStack_28,4);
  iVar10 = *param_1;
  (**(code **)(iVar10 + 0xf4))(param_2,param_1);
  (**(code **)(iVar10 + 0x70))(param_2);
  iVar10 = (int)(short)param_1[0xf];
  if (0 < iVar10) {
    do {
      piVar8 = aiStack_30;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar8 = -1;
        piVar8 = piVar8 + 1;
      }
    } while (10 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    piVar8 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      aiStack_30[iVar1] = iVar7;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    do {
      RGE_Player::remake_visible_map(*(RGE_Player **)(param_1[0x10] + iVar7 * 4));
      iVar7 = iVar7 + 1;
    } while (iVar7 < (short)param_1[0xf]);
  }
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x68))(param_2,aiStack_30,0x3f8a3d71);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  iStack_4 = 0;
  if (0 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      rge_read(param_2,&stack0xffffffac,4);
      iVar10 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_2,&uStack_38,4);
          rge_read(param_2,&uStack_3c,4);
          rge_read(param_2,&uStack_40,4);
          rge_read(param_2,&stack0xffffffb0,4);
          rge_read(param_2,&uStack_44,2);
          rge_read(param_2,&uStack_48,1);
          rge_read(param_2,&iStack_4c,4);
          if ((-1 < *piVar8) && (piVar9 = (int *)(param_1[0x10] + *piVar8 * 4), *piVar9 != 0)) {
            *(undefined1 *)(param_1 + 0x1d) = 1;
            param_1[0x1c] = unaff_EBX;
            (**(code **)(*(int *)*piVar9 + 0x60))
                      (uStack_38,uStack_3c,uStack_40,uStack_44,uStack_48,iStack_4c);
            *(undefined1 *)(param_1 + 0x1d) = 0;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      piVar8 = piVar8 + 1;
    } while (iStack_4 < iStack_8);
  }
  param_1[0x1a] = iStack_34;
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x70))(param_2,aiStack_30,0x3f8a3d71);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  rge_close(param_2);
  iVar10 = 1;
  if (1 < (short)param_1[0xf]) {
    do {
      if (iStack_8 <= iVar10) {
        return;
      }
      if ((*(int *)(param_1[0x10] + iVar10 * 4) != 0) && (-1 < aiStack_30[iVar10])) {
        iVar7 = iVar10 + -1;
        uVar11 = 0xffffffff;
        iVar1 = **(int **)(param_1[0x10] + aiStack_30[iVar10] * 4);
        iVar3 = RGE_Scenario::GetPlayerPosture((RGE_Scenario *)param_1[0x17],iVar7);
        pcVar4 = RGE_Scenario::Get_player_AI((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar5 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar6 = RGE_Scenario::Get_BuildList((RGE_Scenario *)param_1[0x17],iVar7,1);
        (**(code **)(iVar1 + 0x2c))(pcVar6,pcVar5,pcVar4,iVar3,uVar11);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (short)param_1[0xf]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005457fc
// Address: 005457fc
void __thiscall FUN_005457fc(int *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 uVar11;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int aiStack_30 [2];
  undefined1 auStack_28 [32];
  int iStack_8;
  int iStack_4;
  
  world_update_counter = 0;
  rge_read_uncompressed(param_2,&iStack_4c,4);
  if (0 < iStack_4c) {
    pvVar2 = (void *)malloc(iStack_4c);
    if (pvVar2 == (void *)0x0) {
      rge_close(param_2);
      return;
    }
    rge_read_uncompressed(param_2,pvVar2,iStack_4c);
    free(pvVar2);
  }
  rge_read(param_2,auStack_28,4);
  iVar10 = *param_1;
  (**(code **)(iVar10 + 0xf4))(param_2,param_1);
  (**(code **)(iVar10 + 0x70))(param_2);
  iVar10 = (int)(short)param_1[0xf];
  if (0 < iVar10) {
    do {
      piVar8 = aiStack_30;
      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar8 = -1;
        piVar8 = piVar8 + 1;
      }
    } while (10 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    piVar8 = (int *)(iStack_4 + 0x270);
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      aiStack_30[iVar1] = iVar7;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  iVar7 = 0;
  if (0 < iVar10) {
    do {
      RGE_Player::remake_visible_map(*(RGE_Player **)(param_1[0x10] + iVar7 * 4));
      iVar7 = iVar7 + 1;
    } while (iVar7 < (short)param_1[0xf]);
  }
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x68))(param_2,aiStack_30,0x3f8e147b);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  iStack_4 = 0;
  if (0 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      rge_read(param_2,&stack0xffffffac,4);
      iVar10 = 0;
      if (0 < unaff_EBP) {
        do {
          rge_read(param_2,&uStack_38,4);
          rge_read(param_2,&uStack_3c,4);
          rge_read(param_2,&uStack_40,4);
          rge_read(param_2,&stack0xffffffb0,4);
          rge_read(param_2,&uStack_44,2);
          rge_read(param_2,&uStack_48,1);
          rge_read(param_2,&iStack_4c,4);
          if ((-1 < *piVar8) && (piVar9 = (int *)(param_1[0x10] + *piVar8 * 4), *piVar9 != 0)) {
            *(undefined1 *)(param_1 + 0x1d) = 1;
            param_1[0x1c] = unaff_EBX;
            (**(code **)(*(int *)*piVar9 + 0x60))
                      (uStack_38,uStack_3c,uStack_40,uStack_44,uStack_48,iStack_4c);
            *(undefined1 *)(param_1 + 0x1d) = 0;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < unaff_EBP);
      }
      iStack_4 = iStack_4 + 1;
      piVar8 = piVar8 + 1;
    } while (iStack_4 < iStack_8);
  }
  param_1[0x1a] = iStack_34;
  rge_read(param_2,&iStack_8,4);
  iVar10 = 1;
  if (1 < iStack_8) {
    piVar8 = aiStack_30;
    do {
      piVar8 = piVar8 + 1;
      if ((((short)param_1[0xf] <= iVar10) || (*piVar8 < 0)) ||
         (piVar9 = *(int **)(param_1[0x10] + *piVar8 * 4), piVar9 == (int *)0x0)) {
        piVar9 = *(int **)param_1[0x10];
      }
      (**(code **)(*piVar9 + 0x70))(param_2,aiStack_30,0x3f8e147b);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iStack_8);
  }
  rge_close(param_2);
  iVar10 = 1;
  if (1 < (short)param_1[0xf]) {
    do {
      if (iStack_8 <= iVar10) {
        return;
      }
      if ((*(int *)(param_1[0x10] + iVar10 * 4) != 0) && (-1 < aiStack_30[iVar10])) {
        iVar7 = iVar10 + -1;
        uVar11 = 0xffffffff;
        iVar1 = **(int **)(param_1[0x10] + aiStack_30[iVar10] * 4);
        iVar3 = RGE_Scenario::GetPlayerPosture((RGE_Scenario *)param_1[0x17],iVar7);
        pcVar4 = RGE_Scenario::Get_player_AI((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar5 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)param_1[0x17],iVar7,1);
        pcVar6 = RGE_Scenario::Get_BuildList((RGE_Scenario *)param_1[0x17],iVar7,1);
        (**(code **)(iVar1 + 0x2c))(pcVar6,pcVar5,pcVar4,iVar3,uVar11);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (short)param_1[0xf]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00545b2c
// Address: 00545b2c
uint __thiscall FUN_00545b2c(int param_1,uint param_2)
{
  int iVar1;
  uint in_EAX;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0xfc);
  if (iVar1 == -1) {
    in_EAX = 0;
    if (0 < *(short *)(param_1 + 0x3c)) {
      piVar2 = *(int **)(param_1 + 0x40);
      do {
        if (*(byte *)(*piVar2 + 0x48) == param_2) {
          *(uint *)(param_1 + 0xfc) = in_EAX;
          return in_EAX;
        }
        in_EAX = in_EAX + 1;
        piVar2 = piVar2 + 1;
      } while ((int)in_EAX < (int)*(short *)(param_1 + 0x3c));
      return in_EAX;
    }
  }
  else {
    iVar4 = (int)*(short *)(param_1 + 0x3c);
    iVar5 = 0;
    iVar3 = iVar1;
    if (iVar1 < iVar4) {
      while (iVar5 < iVar4) {
        if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x40) + iVar3 * 4) + 0x48) == param_2) &&
           (iVar3 != iVar1)) {
          *(int *)(param_1 + 0xfc) = iVar3;
          return param_2;
        }
        in_EAX = (iVar3 + 1) / iVar4;
        iVar3 = (iVar3 + 1) % iVar4;
        iVar5 = iVar5 + 1;
        if (iVar4 <= iVar3) {
          return in_EAX;
        }
      }
    }
  }
  return in_EAX;
}

// --------------------------------------------------

// Function: FUN_00545bbf
// Address: 00545bbf
void __thiscall FUN_00545bbf(int param_1,uint param_2)
{
  if (*(uint *)(param_1 + 0xf8) < param_2) {
    *(undefined4 *)(param_1 + 0xf8) = 0;
    return;
  }
  *(uint *)(param_1 + 0xf8) = *(uint *)(param_1 + 0xf8) - param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00545be6
// Address: 00545be6
bool __fastcall FUN_00545be6(int param_1)
{
  return *(int *)(param_1 + 0xf8) != 0;
}

// --------------------------------------------------

// Function: FUN_00545bff
// Address: 00545bff
undefined4 __thiscall
FUN_00545bff(int param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)
{
  int iVar1;
  int *piVar2;
  
  if ((((param_4 < 0) || (param_5 < 0)) ||
      (iVar1 = *(int *)(param_1 + 0x28), *(int *)(iVar1 + 8) <= param_4)) ||
     (*(int *)(iVar1 + 0xc) <= param_5)) {
    *param_6 = 0;
  }
  else {
    *param_6 = (int)*(short *)(*(int *)(*(int *)(iVar1 + 0x8d8c) + param_5 * 4) + 0x14 +
                              param_4 * 0x18);
    piVar2 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x28) + 0x8d8c) + param_5 * 4) + 0x10 +
                      param_4 * 0x18);
    if (piVar2 != (int *)0x0) {
      while (iVar1 = *piVar2, iVar1 != 0) {
        if (((param_2 == -1) || (*(short *)(*(int *)(iVar1 + 0xc) + 0x4a) == param_2)) &&
           (*(short *)(*(int *)(iVar1 + 8) + 0x14) == param_3)) {
          return *(undefined4 *)(iVar1 + 4);
        }
        piVar2 = (int *)piVar2[1];
        if (piVar2 == (int *)0x0) {
          return 0xffffffff;
        }
      }
    }
  }
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00545ca6
// Address: 00545ca6
undefined4 __fastcall FUN_00545ca6(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x100) == -1) {
    iVar1 = RGE_Base_Game::difficulty(rge_base_game);
    *(int *)(param_1 + 0x100) = iVar1;
  }
  return *(undefined4 *)(param_1 + 0x100);
}

// --------------------------------------------------

// Function: FUN_00545cd5
// Address: 00545cd5
undefined4 FUN_00545cd5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00545ce5
// Address: 00545ce5
undefined4 __fastcall FUN_00545ce5(int param_1)
{
  return *(undefined4 *)(param_1 + 0x90);
}

// --------------------------------------------------

// Function: FUN_00545cf7
// Address: 00545cf7
undefined4 __fastcall FUN_00545cf7(int param_1)
{
  return *(undefined4 *)(param_1 + 0x9c);
}

// --------------------------------------------------

// Function: FUN_00545d07
// Address: 00545d07
undefined4 __fastcall FUN_00545d07(int param_1)
{
  return *(undefined4 *)(param_1 + 0x8c);
}

// --------------------------------------------------

// Function: FUN_00545d17
// Address: 00545d17
undefined4 __fastcall FUN_00545d17(int param_1)
{
  return *(undefined4 *)(param_1 + 0x98);
}

// --------------------------------------------------

// Function: FUN_00545d27
// Address: 00545d27
undefined4 __thiscall FUN_00545d27(int param_1,int param_2)
{
  if ((param_2 < 0) && (-param_2 < *(int *)(param_1 + 0x9c))) {
    return *(undefined4 *)(*(int *)(param_1 + 0x94) + param_2 * -4);
  }
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x90))) {
    return *(undefined4 *)(*(int *)(param_1 + 0x88) + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00545d74
// Address: 00545d74
void __thiscall FUN_00545d74(RGE_Game_World *param_1,int param_2)
{
  RGE_Game_World::object(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00545d8d
// Address: 00545d8d
int __fastcall FUN_00545d8d(int param_1)
{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x74) != '\0') {
    return *(int *)(param_1 + 0x70);
  }
  iVar1 = *(int *)(param_1 + 0x90) + -1;
  if (*(int *)(param_1 + 0x68) <= iVar1) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x88) + *(int *)(param_1 + 0x68) * 4) == 0) break;
      iVar2 = *(int *)(param_1 + 0x68) + 1;
      *(int *)(param_1 + 0x68) = iVar2;
    } while (iVar2 <= iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x68);
  *(int *)(param_1 + 0x68) = iVar1 + 1;
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00545dce
// Address: 00545dce
void __fastcall FUN_00545dce(int param_1)
{
  if (*(char *)(param_1 + 0x74) == '\0') {
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
  }
  else if (*(int *)(param_1 + 0x70) < *(int *)(param_1 + 0x6c)) {
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x70) + -1;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00545df2
// Address: 00545df2
undefined4 __thiscall FUN_00545df2(int param_1,int param_2)
{
  int *piVar1;
  RGE_Static_Object *this;
  int iVar2;
  RGE_Static_Object **ppRVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  RGE_Static_Object **ppRVar8;
  undefined4 *puVar9;
  
  iVar6 = *(int *)(param_2 + 4);
  if (iVar6 < 0) {
    iVar2 = *(int *)(param_1 + 0x9c) + -1;
    if (SBORROW4(iVar2,-iVar6) != iVar2 + iVar6 < 0) {
      iVar2 = *(int *)(param_1 + 0x9c) * 2;
      if (SBORROW4(iVar2,-iVar6) != iVar2 + iVar6 < 0) {
        iVar2 = __ftol();
      }
      pvVar5 = operator_new(iVar2 * 4);
      if (pvVar5 == (void *)0x0) {
        return 0;
      }
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x9c)) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)((int)pvVar5 + iVar4 * 4 + -4) =
               *(undefined4 *)(*(int *)(param_1 + 0x94) + -4 + iVar4 * 4);
        } while (iVar4 < *(int *)(param_1 + 0x9c));
      }
      if (iVar4 < iVar2) {
        puVar9 = (undefined4 *)((int)pvVar5 + iVar4 * 4);
        for (iVar7 = iVar2 - iVar4; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
      }
      operator_delete(*(void **)(param_1 + 0x94));
      *(void **)(param_1 + 0x94) = pvVar5;
      *(int *)(param_1 + 0x9c) = iVar2;
    }
    *(int *)(*(int *)(param_1 + 0x94) + iVar6 * -4) = param_2;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
  }
  else {
    if (*(int *)(param_1 + 0x90) + -1 < iVar6) {
      iVar2 = *(int *)(param_1 + 0x90) * 2;
      if (iVar2 < iVar6) {
        iVar2 = __ftol();
      }
      ppRVar3 = (RGE_Static_Object **)operator_new(iVar2 * 4);
      if (ppRVar3 == (RGE_Static_Object **)0x0) {
        return 0;
      }
      iVar4 = 0;
      iVar6 = iVar4;
      if (0 < *(int *)(param_1 + 0x90)) {
        do {
          iVar4 = iVar6 + 1;
          ppRVar3[iVar6] = *(RGE_Static_Object **)(*(int *)(param_1 + 0x88) + -4 + iVar4 * 4);
          iVar6 = iVar4;
        } while (iVar4 < *(int *)(param_1 + 0x90));
      }
      if (iVar4 < iVar2) {
        ppRVar8 = ppRVar3 + iVar4;
        for (iVar6 = iVar2 - iVar4; iVar6 != 0; iVar6 = iVar6 + -1) {
          *ppRVar8 = (RGE_Static_Object *)0x0;
          ppRVar8 = ppRVar8 + 1;
        }
      }
      operator_delete(*(void **)(param_1 + 0x88));
      *(RGE_Static_Object ***)(param_1 + 0x88) = ppRVar3;
      VIS_UNIT_objectsValue = ppRVar3;
      *(int *)(param_1 + 0x90) = iVar2;
    }
    piVar1 = (int *)(*(int *)(param_1 + 0x88) + *(int *)(param_2 + 4) * 4);
    this = (RGE_Static_Object *)*piVar1;
    *piVar1 = param_2;
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
    if ((this != (RGE_Static_Object *)0x0) && (*(char *)(param_1 + 0x74) != '\0')) {
      *(undefined1 *)(param_1 + 0x74) = 0;
      RGE_Static_Object::change_unique_id(this);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00545fc9
// Address: 00545fc9
undefined4 __thiscall FUN_00545fc9(int param_1,int param_2)
{
  if ((param_2 < 0) && (-param_2 < *(int *)(param_1 + 0x9c))) {
    *(undefined4 *)(*(int *)(param_1 + 0x94) + param_2 * -4) = 0;
    return 1;
  }
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x90))) {
    *(undefined4 *)(*(int *)(param_1 + 0x88) + param_2 * 4) = 0;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00546026
// Address: 00546026
RGE_Map * __fastcall FUN_00546026(RGE_Game_World *param_1)
{
  RGE_Map *pRVar1;
  
  pRVar1 = param_1->map;
  if (pRVar1 == (RGE_Map *)0x0) {
    return pRVar1;
  }
  PathingSystem::initialize(&pathSystem,pRVar1->map_width,pRVar1->map_height,pRVar1,param_1);
  pRVar1 = param_1->map;
  PathingSystem::initialize(&aiPathSystem,pRVar1->map_width,pRVar1->map_height,pRVar1,param_1);
  return (RGE_Map *)0x1;
}

// --------------------------------------------------

// Function: FUN_0054606e
// Address: 0054606e
undefined4 __thiscall FUN_0054606e(int param_1,undefined1 param_2,RGE_Static_Object *param_3)
{
  switch(param_2) {
  case 10:
    RGE_Object_List::add_node(*(RGE_Object_List **)(param_1 + 0xd8),param_3);
    return 1;
  default:
    return 0;
  case 0x14:
    RGE_Object_List::add_node(*(RGE_Object_List **)(param_1 + 0xdc),param_3);
    return 1;
  case 0x19:
    RGE_Object_List::add_node(*(RGE_Object_List **)(param_1 + 0xf0),param_3);
    return 1;
  case 0x1e:
    RGE_Object_List::add_node(*(RGE_Object_List **)(param_1 + 0xe0),param_3);
    return 1;
  case 0x28:
    RGE_Object_List::add_node(*(RGE_Object_List **)(param_1 + 0xe4),param_3);
    return 1;
  case 0x32:
    RGE_Object_List::add_node(*(RGE_Object_List **)(param_1 + 0xe8),param_3);
    return 1;
  case 0x3c:
    RGE_Object_List::add_node(*(RGE_Object_List **)(param_1 + 0xec),param_3);
    return 1;
  }
}

// --------------------------------------------------

// Function: FUN_0054627a
// Address: 0054627a
// [HELPER] s__8_8x: "%8.8x"
// [HELPER] s___: "]\n"
// [HELPER] s___RemoveVisibleBits____: "  RemoveVisibleBits = ["
// [HELPER] s___allied_LOS_Enable____d___allie: "  allied_LOS_Enable = %d   allied_victory = %d \n"
// [HELPER] s___mutualExploredMask____8_8x___m: "  mutualExploredMask = %8.8x   mutualVisibleMask = %8.8x   nonMutualVisibleMa..."
// [HELPER] s___mututalAlly____: "  mututalAlly = ["
// [HELPER] s___unitDiplomacy____: "  unitDiplomacy = ["
// [HELPER] s__d: "%d"
// [HELPER] s_player__d_: "player %d\n"
// [HELPER] s_updating_player_visibilites___wt: "updating player visibilites @ wt=%d\n"
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0054627a(void)
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined1 *puStack0000001c;
  int in_stack_00000024;
  undefined4 in_stack_0000002c;
  undefined1 *puStack00000034;
  int iStack00000038;
  char cStack0000003c;
  undefined4 in_stack_00000044;
  int in_stack_0000004c;
  undefined1 *in_stack_00000050;
  undefined4 in_stack_000000a8;
  _iobuf *in_stack_000000ac;
  char *pcStack000000b0;
  char *pcStack000000b4;
  char *pcStack000000b8;
  char *pcStack000000bc;
  undefined1 *puStack000000c0;
  undefined4 *puStack000000c4;
  undefined4 uStack000000c8;
  undefined4 uStack000000cc;
  int in_stack_000000d0;
  int in_stack_000000d4;
  undefined4 in_stack_000000d8;
  undefined2 in_stack_000000dc;
  
  iVar3 = in_stack_0000004c;
  uStack000000c8 = _cStack0000003c;
  puStack0000001c = &stack0x00000020;
  puStack000000c4 = (undefined4 *)&stack0x0000003c;
  puStack00000034 = (undefined1 *)&stack0x00000038;
  puStack000000c0 = (undefined1 *)&stack0x00000038;
  *(char *)(in_stack_00000024 + 0x62) =
       *(char *)(in_stack_00000024 + 0x62) + (char)in_stack_0000002c;
                    /* WARNING: Ignoring partial resolution of indirect */
  cStack0000003c = cStack0000003c + (char)in_stack_00000050;
  iStack00000038 = (int)&stack0x0000003c + (int)in_stack_00000050;
  uStack000000cc = in_stack_00000044;
  pcStack000000bc = *(char **)(in_stack_0000004c + 4);
  pcStack000000b8 = s_updating_player_visibilites___wt;
  pcStack000000b4 = (char *)DVlogf;
  pcStack000000b0 = (char *)0x5462ee;
  in_stack_00000050 = &stack0x00000054;
  fprintf();
  iVar8 = 0;
  if (0 < *(short *)(iVar3 + 0x3c)) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd0) = 0;
      *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd4) = 0;
      iVar4 = 0xdc;
      *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd8) = 0;
      do {
        iVar4 = iVar4 + 4;
        *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + -4 + iVar4) = 0;
      } while (iVar4 < 0x100);
      puVar5 = (undefined4 *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xac);
      iVar4 = 0;
      do {
        if (iVar4 == iVar8) {
          *puVar5 = 1;
          *(int *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd4) = 1 << ((byte)iVar8 & 0x1f);
          *(int *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar8 * 4) + 0xd0) =
               1 << ((byte)iVar8 + 0x10 & 0x1f);
        }
        else {
          *puVar5 = 0;
        }
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar4 < 9);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(short *)(iVar3 + 0x3c));
  }
  iVar8 = (int)*(short *)(iVar3 + 0x3c);
  iVar4 = 1;
  if (1 < iVar8) {
    do {
      if ((*(int *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar4 * 4) + 0x100) == 1) &&
         (iVar6 = 1, 1 < iVar8)) {
        do {
          if (iVar6 != iVar4) {
            iVar8 = *(int *)(*(int *)(iVar3 + 0x40) + iVar4 * 4);
            if ((*(char *)(*(int *)(iVar8 + 0x84) + iVar6) == '\0') &&
               (*(char *)(*(int *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar6 * 4) + 0x84) + iVar4) ==
                '\0')) {
              *(undefined4 *)(iVar8 + 0xac + iVar6 * 4) = 1;
              iVar8 = *(int *)(*(int *)(iVar3 + 0x40) + iVar4 * 4);
              *(uint *)(iVar8 + 0xd4) = *(uint *)(iVar8 + 0xd4) | 1 << ((byte)iVar6 & 0x1f);
              puVar1 = (uint *)(*(int *)(*(int *)(iVar3 + 0x40) + iVar4 * 4) + 0xd0);
              *puVar1 = *puVar1 | 1 << ((byte)iVar6 + 0x10 & 0x1f);
            }
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(short *)(iVar3 + 0x3c));
      }
      iVar8 = (int)*(short *)(iVar3 + 0x3c);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar8);
  }
  iVar8 = (int)*(short *)(iVar3 + 0x3c);
  in_stack_000000d4 = 0;
  if (0 < iVar8) {
    iVar4 = 0;
    do {
      in_stack_000000d0 = 1;
      if (1 < iVar8) {
        iVar6 = 0xe0;
        do {
          if (((in_stack_000000d0 != in_stack_000000d4) &&
              (*(int *)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + -0x30 + iVar6) == 0)) &&
             (iVar9 = 1, 1 < iVar8)) {
            do {
              iVar8 = *(int *)(iVar3 + 0x40);
              if (((*(int *)(*(int *)(iVar4 + iVar8) + 0xac + iVar9 * 4) == 0) &&
                  (iVar2 = *(int *)(iVar8 + iVar9 * 4), *(int *)(iVar6 + -0x30 + iVar2) == 1)) &&
                 (*(int *)(iVar4 + 0xac + iVar2) == 1)) {
                in_stack_000000d8 = 1;
                *(uint *)(*(int *)(iVar4 + iVar8) + 0xd8) =
                     *(uint *)(*(int *)(iVar4 + iVar8) + 0xd8) |
                     1 << ((byte)in_stack_000000d0 & 0x1f);
                puVar1 = (uint *)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + iVar6);
                *puVar1 = *puVar1 | 1 << ((byte)iVar9 & 0x1f);
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < *(short *)(iVar3 + 0x3c));
          }
          iVar8 = (int)*(short *)(iVar3 + 0x3c);
          in_stack_000000d0 = in_stack_000000d0 + 1;
          iVar6 = iVar6 + 4;
        } while (in_stack_000000d0 < iVar8);
      }
      iVar8 = (int)*(short *)(iVar3 + 0x3c);
      in_stack_000000d4 = in_stack_000000d4 + 1;
      iVar4 = iVar4 + 4;
    } while (in_stack_000000d4 < iVar8);
  }
  iVar8 = 0;
  if (0 < *(short *)(iVar3 + 0x3c)) {
    iVar4 = 0;
    do {
      pcStack000000b8 = s_player__d_;
      pcStack000000b4 = (char *)DVlogf;
      pcStack000000b0 = (char *)0x546531;
      pcStack000000bc = (char *)iVar8;
      fprintf();
      iVar6 = *(int *)(iVar4 + *(int *)(iVar3 + 0x40));
      pcStack000000bc = *(char **)(iVar6 + 0xd8);
      pcStack000000b8 = *(char **)(iVar6 + 0xd4);
      pcStack000000b4 = *(char **)(iVar6 + 0xd0);
      pcStack000000b0 = s___mutualExploredMask____8_8x___m;
      in_stack_000000ac = DVlogf;
      in_stack_000000a8 = 0x546560;
      fprintf();
      iVar6 = *(int *)(iVar4 + *(int *)(iVar3 + 0x40));
      pcStack000000bc = (char *)(uint)*(byte *)(iVar6 + 0x104);
      pcStack000000b8 = *(char **)(iVar6 + 0x100);
      pcStack000000b4 = s___allied_LOS_Enable____d___allie;
      pcStack000000b0 = (char *)DVlogf;
      in_stack_000000ac = (_iobuf *)0x546589;
      fprintf();
      pcStack000000bc = s___unitDiplomacy____;
      pcStack000000b8 = (char *)DVlogf;
      pcStack000000b4 = (char *)0x54659d;
      fprintf();
      iVar6 = 0x88;
      do {
        pcStack000000bc = *(char **)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + iVar6);
        pcStack000000b8 = (char *)&s__d;
        pcStack000000b4 = (char *)DVlogf;
        pcStack000000b0 = (char *)0x5465c0;
        fprintf();
        if (iVar6 < 0xa8) {
          pcStack000000bc = s___;
        }
        else {
          pcStack000000bc = s___;
        }
        pcStack000000b8 = (char *)DVlogf;
        pcStack000000b4 = (char *)0x5465e9;
        fprintf();
        iVar6 = iVar6 + 4;
      } while (iVar6 < 0xac);
      pcStack000000bc = s___mututalAlly____;
      pcStack000000b8 = (char *)DVlogf;
      pcStack000000b4 = (char *)0x546608;
      fprintf();
      iVar6 = 0xac;
      do {
        pcStack000000bc = *(char **)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + iVar6);
        pcStack000000b8 = (char *)&s__d;
        pcStack000000b4 = (char *)DVlogf;
        pcStack000000b0 = (char *)0x54662a;
        fprintf();
        if (iVar6 < 0xcc) {
          pcStack000000bc = s___;
        }
        else {
          pcStack000000bc = s___;
        }
        pcStack000000b8 = (char *)DVlogf;
        pcStack000000b4 = (char *)0x546654;
        fprintf();
        iVar6 = iVar6 + 4;
      } while (iVar6 < 0xd0);
      pcStack000000bc = s___RemoveVisibleBits____;
      pcStack000000b8 = (char *)DVlogf;
      pcStack000000b4 = (char *)0x546672;
      fprintf();
      iVar6 = 0xdc;
      do {
        pcStack000000bc = *(char **)(*(int *)(iVar4 + *(int *)(iVar3 + 0x40)) + iVar6);
        pcStack000000b8 = s__8_8x;
        pcStack000000b4 = (char *)DVlogf;
        pcStack000000b0 = (char *)0x546695;
        fprintf();
        if (iVar6 < 0xfc) {
          pcStack000000bc = s___;
        }
        else {
          pcStack000000bc = s___;
        }
        pcStack000000b8 = (char *)DVlogf;
        pcStack000000b4 = (char *)0x5466be;
        fprintf();
        iVar6 = iVar6 + 4;
      } while (iVar6 < 0x100);
      iVar8 = iVar8 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar8 < *(short *)(iVar3 + 0x3c));
  }
  pcStack000000bc = (char *)0x5466e7;
  piVar7 = (int *)(**(code **)(rge_base_game->_padding_ + 0x2c))();
  if (piVar7 != (int *)0x0) {
    pcStack000000bc = (char *)0x2;
    pcStack000000b8 = (char *)0x5466f4;
    (**(code **)(*piVar7 + 0x20))();
  }
  pcStack000000bc = (char *)0x5466ff;
  piVar7 = (int *)(**(code **)(rge_base_game->_padding_ + 0x30))();
  if (piVar7 != (int *)0x0) {
    pcStack000000bc = (char *)0x2;
    pcStack000000b8 = (char *)0x54670c;
    (**(code **)(*piVar7 + 0x20))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00546714
// Address: 00546714
undefined4 FUN_00546714(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  *param_3 = *puVar1;
  *param_4 = puVar1[1];
  *param_1 = puVar1[2];
  free(puVar1);
  iVar2 = *param_1;
  if (iVar2 == 0) {
    *param_2 = 0;
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}

// --------------------------------------------------

// Function: zone_pop
// Address: 00546720
/* unsigned char __cdecl zone_pop(struct Zone_Queue * *,struct Zone_Queue * *,long &,long &) */

uchar __cdecl zone_pop(Zone_Queue **param_1,Zone_Queue **param_2,long *param_3,long *param_4)
{
  Zone_Queue *pZVar1;
  
  pZVar1 = *param_1;
  if (pZVar1 == (Zone_Queue *)0x0) {
    return '\0';
  }
  *param_3 = pZVar1->x;
  *param_4 = pZVar1->y;
  *param_1 = pZVar1->next;
  free(pZVar1);
  if (*param_1 == (Zone_Queue *)0x0) {
    *param_2 = (Zone_Queue *)0x0;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: FUN_00546762
// Address: 00546762
void FUN_00546762(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)calloc(1,0xc);
  if (*param_2 != 0) {
    *(undefined4 **)(*param_2 + 8) = puVar1;
  }
  *puVar1 = param_3;
  puVar1[1] = param_4;
  *param_2 = (int)puVar1;
  if (*param_1 == 0) {
    *param_1 = (int)puVar1;
  }
  return;
}

// --------------------------------------------------

// Function: zone_push
// Address: 00546770
/* void __cdecl zone_push(struct Zone_Queue * *,struct Zone_Queue * *,long,long) */

void __cdecl zone_push(Zone_Queue **param_1,Zone_Queue **param_2,long param_3,long param_4)
{
  Zone_Queue *pZVar1;
  
  pZVar1 = (Zone_Queue *)calloc(1,0xc);
  if (*param_2 != (Zone_Queue *)0x0) {
    (*param_2)->next = pZVar1;
  }
  pZVar1->x = param_3;
  pZVar1->y = param_4;
  *param_2 = pZVar1;
  if (*param_1 == (Zone_Queue *)0x0) {
    *param_1 = pZVar1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005467a4
// Address: 005467a4
void * __thiscall FUN_005467a4(void *param_1,int param_2,int param_3)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  
  *(int *)((int)param_1 + 0x518) = param_3;
  uVar2 = calloc(*(int *)(param_3 + 8) * *(int *)(param_3 + 0xc),1);
  *(undefined4 *)((int)param_1 + 0x404) = uVar2;
  uVar2 = calloc(*(undefined4 *)(*(int *)((int)param_1 + 0x518) + 0xc),4);
  iVar5 = *(int *)((int)param_1 + 0x518);
  *(undefined4 *)((int)param_1 + 0x408) = uVar2;
  iVar3 = 0;
  if (0 < *(int *)(iVar5 + 0xc)) {
    do {
      *(int *)(*(int *)((int)param_1 + 0x408) + iVar3 * 4) =
           *(int *)(iVar5 + 8) * iVar3 + *(int *)((int)param_1 + 0x404);
      iVar5 = *(int *)((int)param_1 + 0x518);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar5 + 0xc));
  }
  rge_read(param_2,(void *)((int)param_1 + 0x40c),0xff);
  rge_read(param_2,param_1,0x3fc);
  rge_read(param_2,*(void **)((int)param_1 + 0x404),
           *(int *)(*(int *)((int)param_1 + 0x518) + 0xc) *
           *(int *)(*(int *)((int)param_1 + 0x518) + 8));
  piVar1 = (int *)((int)param_1 + 0x514);
  rge_read(param_2,piVar1,4);
  if (0 < *piVar1) {
    pvVar4 = (void *)calloc(*piVar1,4);
    *(void **)((int)param_1 + 0x510) = pvVar4;
    rge_read(param_2,pvVar4,*piVar1 << 2);
    return param_1;
  }
  *(undefined4 *)((int)param_1 + 0x510) = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005468bc
// Address: 005468bc
RGE_Zone_Map * __thiscall
FUN_005468bc(RGE_Zone_Map *param_1,RGE_Map *param_2,float *param_3,long param_4)
{
  uchar *puVar1;
  uchar **ppuVar2;
  int iVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  RGE_Map *pRVar7;
  RGE_Zone_Map *pRVar8;
  
  param_1->map = param_2;
  puVar1 = (uchar *)calloc(param_2->map_height * param_2->map_width,1);
  param_1->zone_map = puVar1;
  uVar5 = param_1->map->map_height * param_1->map->map_width;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    puVar1[0] = 0xff;
    puVar1[1] = 0xff;
    puVar1[2] = 0xff;
    puVar1[3] = 0xff;
    puVar1 = puVar1 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar1 = 0xff;
    puVar1 = puVar1 + 1;
  }
  ppuVar2 = (uchar **)calloc(param_1->map->map_height,4);
  pRVar7 = param_1->map;
  param_1->zone_map_rows = ppuVar2;
  iVar3 = 0;
  if (0 < pRVar7->map_height) {
    do {
      param_1->zone_map_rows[iVar3] = param_1->zone_map + pRVar7->map_width * iVar3;
      pRVar7 = param_1->map;
      iVar3 = iVar3 + 1;
    } while (iVar3 < pRVar7->map_height);
  }
  iVar3 = 0;
  pRVar8 = param_1;
  do {
    param_1->zone_info[iVar3] = 0xff;
    pRVar8->numberTilesInZoneValue[0] = 0;
    iVar3 = iVar3 + 1;
    pRVar8 = (RGE_Zone_Map *)(pRVar8->numberTilesInZoneValue + 1);
  } while (iVar3 < 0xff);
  param_1->terrain_passability_rules_num = param_4;
  pfVar4 = (float *)calloc(param_4,4);
  param_1->terrain_passability_rules = pfVar4;
  for (uVar6 = param_1->terrain_passability_rules_num & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pfVar4 = *param_3;
    param_3 = param_3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)pfVar4 = *(undefined1 *)param_3;
    param_3 = (float *)((int)param_3 + 1);
    pfVar4 = (float *)((int)pfVar4 + 1);
  }
  RGE_Zone_Map::do_zone_map(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_005469b8
// Address: 005469b8
void __fastcall FUN_005469b8(int param_1)
{
  free(*(undefined4 *)(param_1 + 0x404));
  free(*(undefined4 *)(param_1 + 0x408));
  free(*(undefined4 *)(param_1 + 0x510));
  return;
}

// --------------------------------------------------

// Function: FUN_005469f2
// Address: 005469f2
void __thiscall FUN_005469f2(void *param_1,int param_2)
{
  int iVar1;
  
  rge_write(param_2,(void *)((int)param_1 + 0x40c),0xff);
  rge_write(param_2,param_1,0x3fc);
  rge_write(param_2,*(void **)((int)param_1 + 0x404),
            *(int *)(*(int *)((int)param_1 + 0x518) + 0xc) *
            *(int *)(*(int *)((int)param_1 + 0x518) + 8));
  rge_write(param_2,(int *)((int)param_1 + 0x514),4);
  iVar1 = *(int *)((int)param_1 + 0x514);
  if (0 < iVar1) {
    rge_write(param_2,*(void **)((int)param_1 + 0x510),iVar1 * 4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00546a81
// Address: 00546a81
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00546a81(RGE_Zone_Map *param_1)
{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uchar *puVar9;
  int iStack_14;
  int iStack_10;
  
  iVar8 = 0;
  iVar2 = param_1->map->map_width;
  iVar3 = param_1->map->map_height;
  iVar5 = -1;
  puVar9 = param_1->zone_info;
  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {
    puVar9[0] = 0xff;
    puVar9[1] = 0xff;
    puVar9[2] = 0xff;
    puVar9[3] = 0xff;
    puVar9 = puVar9 + 4;
  }
  puVar9[0] = 0xff;
  puVar9[1] = 0xff;
  iVar7 = 0;
  puVar9[2] = 0xff;
  if (0 < iVar2) {
    do {
      iVar5 = 0;
      iVar6 = iVar5;
      if (0 < iVar3) {
        do {
          iVar5 = iVar6 + 1;
          param_1->zone_map_rows[iVar7][iVar6] = 0xff;
          iVar6 = iVar5;
        } while (iVar5 < iVar3);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar2);
  }
  iVar7 = 0;
  iStack_10 = 0;
  if (0 < iVar2) {
    do {
      iVar5 = 0;
      if (0 < iVar3) {
        iStack_14 = 0;
        do {
          if (*(char *)(iVar5 + *(int *)((int)param_1->zone_map_rows + iVar7)) == -1) {
            if (0xfe < iVar8) {
              iVar8 = 0;
            }
            fVar1 = param_1->terrain_passability_rules
                    [*(byte *)(*(int *)((int)param_1->map->map_row_offset + iVar7) + 5 + iStack_14)
                     & 0x1f];
            fVar4 = (float)_DAT_00577a20;
            *(uchar *)(iVar5 + *(int *)((int)param_1->zone_map_rows + iVar7)) = (uchar)iVar8;
            RGE_Zone_Map::do_zone_map_area(param_1,iVar5,iStack_10,fVar4 < fVar1,(uchar)iVar8);
            iVar8 = iVar8 + 1;
          }
          iVar5 = iVar5 + 1;
          iStack_14 = iStack_14 + 0x18;
        } while (iVar5 < iVar3);
      }
      iVar5 = iStack_10 + 1;
      iVar7 = iVar7 + 4;
      iStack_10 = iVar5;
    } while (iVar5 < iVar2);
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_00546baf
// Address: 00546baf
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00546baf(int param_1,int param_2,int param_3,uint param_4,char param_5)
{
  int iVar1;
  char cVar2;
  uchar uVar3;
  char *pcVar4;
  Zone_Queue *pZStack_10;
  Zone_Queue *pZStack_c;
  int iStack_8;
  int iStack_4;
  
  cVar2 = param_5;
  pZStack_c = (Zone_Queue *)0x0;
  pZStack_10 = (Zone_Queue *)0x0;
  iStack_8 = *(int *)(*(int *)(param_1 + 0x518) + 8) + -1;
  iStack_4 = *(int *)(*(int *)(param_1 + 0x518) + 0xc) + -1;
  do {
    if (0 < param_2) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x408) + param_3 * 4);
      if ((*(char *)(iVar1 + -1 + param_2) == -1) &&
         ((uint)((float)_DAT_00577a20 <
                *(float *)(*(int *)(param_1 + 0x510) +
                          (*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x518) + 0x8d8c) +
                                             param_3 * 4) + param_2 * 0x18 + -0x13) & 0x1f) * 4)) ==
          (param_4 & 0xff))) {
        *(char *)(iVar1 + -1 + param_2) = cVar2;
        zone_push(&pZStack_c,&pZStack_10,param_2 + -1,param_3);
      }
    }
    if (0 < param_3) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x408) + -4 + param_3 * 4);
      if ((*(char *)(iVar1 + param_2) == -1) &&
         ((uint)((float)_DAT_00577a20 <
                *(float *)(*(int *)(param_1 + 0x510) +
                          (*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x518) + 0x8d8c) + -4 +
                                             param_3 * 4) + param_2 * 0x18 + 5) & 0x1f) * 4)) ==
          (param_4 & 0xff))) {
        *(char *)(iVar1 + param_2) = cVar2;
        zone_push(&pZStack_c,&pZStack_10,param_2,param_3 + -1);
      }
    }
    if (param_2 < iStack_8) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x408) + param_3 * 4);
      if ((*(char *)(iVar1 + 1 + param_2) == -1) &&
         ((uint)((float)_DAT_00577a20 <
                *(float *)(*(int *)(param_1 + 0x510) +
                          (*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x518) + 0x8d8c) +
                                             param_3 * 4) + (param_2 + 1) * 0x18 + 5) & 0x1f) * 4))
          == (param_4 & 0xff))) {
        *(char *)(iVar1 + 1 + param_2) = cVar2;
        zone_push(&pZStack_c,&pZStack_10,param_2 + 1,param_3);
      }
    }
    if (param_3 < iStack_4) {
      iVar1 = param_3 * 4 + 4;
      pcVar4 = (char *)(param_2 + *(int *)(*(int *)(param_1 + 0x408) + iVar1));
      if ((*pcVar4 == -1) &&
         ((uint)((float)_DAT_00577a20 <
                *(float *)(*(int *)(param_1 + 0x510) +
                          (*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x518) + 0x8d8c) + iVar1)
                                     + param_2 * 0x18 + 5) & 0x1f) * 4)) == (param_4 & 0xff))) {
        *pcVar4 = cVar2;
        zone_push(&pZStack_c,&pZStack_10,param_2,param_3 + 1);
      }
    }
    uVar3 = zone_pop(&pZStack_c,&pZStack_10,&param_2,&param_3);
  } while (uVar3 != '\0');
  return;
}

// --------------------------------------------------

// Function: FUN_00546e44
// Address: 00546e44
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00546e44(int param_1,int param_2,int param_3)
{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x514);
  if (param_3 != iVar2) {
    return 0;
  }
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      fVar1 = *(float *)(*(int *)(param_1 + 0x510) + iVar3 * 4);
      if ((float)_DAT_00577a20 < *(float *)(param_2 + iVar3 * 4)) {
        if (fVar1 <= (float)_DAT_00577a20) {
          return 0;
        }
      }
      else if ((float)_DAT_00577a20 < fVar1) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00546eaa
// Address: 00546eaa
undefined1 __thiscall FUN_00546eaa(int param_1,int param_2,int param_3)
{
  return *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x408) + param_3 * 4) + param_2);
}

// --------------------------------------------------

// Function: FUN_00546ec7
// Address: 00546ec7
void __thiscall
FUN_00546ec7(RGE_Zone_Map *param_1,int param_2,int param_3,int param_4,int param_5,float param_6)
{
  XYPoint XVar1;
  
  XVar1.y = param_5;
  XVar1.x = param_4;
  RGE_Zone_Map::withinRange(param_1,param_1->zone_map_rows[param_3][param_2],XVar1,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_00546efc
// Address: 00546efc
undefined4 __thiscall FUN_00546efc(int param_1,char param_2,int param_3,int param_4,float param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_8;
  
  iVar1 = __ftol();
  iVar3 = param_3 - iVar1;
  iVar5 = param_4 - iVar1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x518) + 8) + -1;
  iStack_8 = param_3 + iVar1;
  if (iVar4 < param_3 + iVar1) {
    iStack_8 = iVar4;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x518) + 0xc) + -1;
  iVar4 = param_4 + iVar1;
  if (iVar2 < param_4 + iVar1) {
    iVar4 = iVar2;
  }
  if (iStack_8 < iVar3) {
    return 0;
  }
  param_3 = param_3 - iVar3;
  do {
    if (iVar5 <= iVar4) {
      iVar2 = param_4 - iVar5;
      iVar1 = iVar5;
      do {
        if ((SQRT((float)(iVar2 * iVar2 + param_3 * param_3)) <= param_5) &&
           (*(char *)(*(int *)(*(int *)(param_1 + 0x408) + iVar1 * 4) + iVar3) == param_2)) {
          return 1;
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar1 <= iVar4);
    }
    iVar3 = iVar3 + 1;
    param_3 = param_3 + -1;
    if (iStack_8 < iVar3) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00546ff7
// Address: 00546ff7
int __thiscall FUN_00546ff7(int param_1,byte param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  bVar4 = param_2;
  piVar1 = (int *)(param_1 + (uint)param_2 * 4);
  iVar6 = *piVar1;
  if (iVar6 < 1) {
    iVar7 = 0;
    iVar2 = *(int *)(*(int *)(param_1 + 0x518) + 8);
    iVar3 = *(int *)(*(int *)(param_1 + 0x518) + 0xc);
    _param_2 = 0;
    iVar6 = 0;
    if (0 < iVar2) {
      do {
        if (0 < iVar3) {
          piVar5 = *(int **)(param_1 + 0x408);
          iVar6 = iVar3;
          do {
            if (*(byte *)(iVar7 + *piVar5) == bVar4) {
              _param_2 = _param_2 + 1;
            }
            piVar5 = piVar5 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        iVar7 = iVar7 + 1;
        iVar6 = _param_2;
      } while (iVar7 < iVar2);
    }
    *piVar1 = iVar6;
  }
  return iVar6;
}

// --------------------------------------------------

// Function: FUN_0054707a
// Address: 0054707a
bool __thiscall
FUN_0054707a(int param_1,int param_2,int param_3,int *param_4,uint param_5,uint param_6,int param_7)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_c;
  int iStack_4;
  
  iVar5 = param_2 - param_7;
  iStack_4 = param_3 - param_7;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (iStack_4 < 0) {
    iStack_4 = 0;
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x518) + 8) + -1;
  iVar3 = param_7 + param_2;
  if (iVar4 < param_7 + param_2) {
    iVar3 = iVar4;
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x518) + 0xc) + -1;
  iStack_c = param_3 + param_7;
  if (iVar4 < param_3 + param_7) {
    iStack_c = iVar4;
  }
  iVar4 = -1;
  if (iVar5 <= iVar3) {
    param_7 = param_2 - iVar5;
    do {
      if (iStack_4 <= iStack_c) {
        iVar7 = param_3 - iStack_4;
        iVar6 = iStack_4;
        do {
          bVar1 = RGE_Map::get_terrain(*(RGE_Map **)(param_1 + 0x518),(short)iVar5,(short)iVar6);
          if (((bVar1 == param_5) || (bVar1 == param_6)) &&
             ((iVar2 = param_7 * param_7 + iVar7 * iVar7, iVar4 == -1 || (iVar2 < iVar4)))) {
            *param_4 = iVar5;
            param_4[1] = iVar6;
            iVar4 = iVar2;
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar6 <= iStack_c);
      }
      iVar5 = iVar5 + 1;
      param_7 = param_7 + -1;
    } while (iVar5 <= iVar3);
  }
  return iVar4 != -1;
}

// --------------------------------------------------

// Function: FUN_00547179
// Address: 00547179
int * __thiscall FUN_00547179(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  RGE_Zone_Map *this;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561e8b;
  *unaff_FS_OFFSET = &uStack_c;
  piVar1 = param_1 + 1;
  *param_1 = 0;
  param_1[2] = param_3;
  rge_read(param_2,piVar1,4);
  if (*piVar1 < 1) {
    *param_1 = 0;
  }
  else {
    iVar2 = calloc(*piVar1,4);
    *param_1 = iVar2;
    iVar2 = 0;
    if (0 < *piVar1) {
      do {
        this = (RGE_Zone_Map *)operator_new(0x51c);
        uStack_4 = 0;
        if (this == (RGE_Zone_Map *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = RGE_Zone_Map::RGE_Zone_Map(this,param_2,(RGE_Map *)param_1[2]);
        }
        iVar2 = iVar2 + 1;
        uStack_4 = 0xffffffff;
        *(undefined4 *)(*param_1 + -4 + iVar2 * 4) = uVar3;
      } while (iVar2 < *piVar1);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00547237
// Address: 00547237
void __thiscall FUN_00547237(undefined4 *param_1,undefined4 param_2)
{
  param_1[2] = param_2;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00547265
// Address: 00547265
void __thiscall FUN_00547265(int *param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 1;
  rge_write(param_2,piVar1,4);
  if ((0 < *piVar1) && (iVar2 = 0, 0 < *piVar1)) {
    do {
      RGE_Zone_Map::save(*(RGE_Zone_Map **)(*param_1 + iVar2 * 4),param_2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *piVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005472ae
// Address: 005472ae
int __thiscall FUN_005472ae(int *param_1,float *param_2,long param_3)
{
  uchar uVar1;
  RGE_Zone_Map *pRVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561eab;
  *unaff_FS_OFFSET = &uStack_c;
  iVar6 = 0;
  if (0 < param_1[1]) {
    do {
      pRVar2 = RGE_Zone_Map::check_info(*(RGE_Zone_Map **)(*param_1 + iVar6 * 4),param_2,param_3);
      if (pRVar2 != (RGE_Zone_Map *)0x0) {
        uVar1 = RGE_Zone_Map::do_zone_map(*(RGE_Zone_Map **)(*param_1 + iVar6 * 4));
        if (uVar1 == '\0') {
          iVar6 = -1;
        }
        goto LAB_0054737c;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1[1]);
  }
  puVar3 = (undefined4 *)calloc(param_1[1] + 1,4);
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    puVar7 = (undefined4 *)*param_1;
    puVar8 = puVar3;
    for (uVar5 = param_1[1] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    free(*param_1);
  }
  pRVar2 = (RGE_Zone_Map *)operator_new(0x51c);
  uStack_4 = 0;
  if (pRVar2 == (RGE_Zone_Map *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = RGE_Zone_Map::RGE_Zone_Map(pRVar2,(RGE_Map *)param_1[2],param_2,param_3);
  }
  puVar3[param_1[1]] = uVar4;
  iVar6 = param_1[1];
  *param_1 = (int)puVar3;
  param_1[1] = iVar6 + 1;
LAB_0054737c:
  *unaff_FS_OFFSET = uStack_c;
  return iVar6;
}

// --------------------------------------------------

// Function: FUN_005473a8
// Address: 005473a8
undefined4 __thiscall FUN_005473a8(int *param_1,float *param_2,long param_3,int *param_4)
{
  RGE_Zone_Map *pRVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561ecb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = 0;
  if (0 < param_1[1]) {
    do {
      pRVar1 = RGE_Zone_Map::check_info(*(RGE_Zone_Map **)(*param_1 + iVar5 * 4),param_2,param_3);
      if (pRVar1 != (RGE_Zone_Map *)0x0) {
        *param_4 = iVar5;
        uVar3 = *(undefined4 *)(*param_1 + iVar5 * 4);
        goto LAB_00547485;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1[1]);
  }
  puVar2 = (undefined4 *)calloc(param_1[1] + 1,4);
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    puVar6 = (undefined4 *)*param_1;
    puVar7 = puVar2;
    for (uVar4 = param_1[1] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    free(*param_1);
  }
  pRVar1 = (RGE_Zone_Map *)operator_new(0x51c);
  uStack_4 = 0;
  if (pRVar1 == (RGE_Zone_Map *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = RGE_Zone_Map::RGE_Zone_Map(pRVar1,(RGE_Map *)param_1[2],param_2,param_3);
  }
  puVar2[param_1[1]] = uVar3;
  iVar5 = param_1[1];
  *param_1 = (int)puVar2;
  param_1[1] = iVar5 + 1;
  *param_4 = iVar5;
  uVar3 = puVar2[param_1[1] + -1];
LAB_00547485:
  *unaff_FS_OFFSET = uStack_c;
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_005474a7
// Address: 005474a7
undefined4 __thiscall FUN_005474a7(int *param_1,int param_2)
{
  if ((param_2 < param_1[1]) && (-1 < param_2)) {
    return *(undefined4 *)(*param_1 + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005474cc
// Address: 005474cc
void __fastcall FUN_005474cc(int *param_1)
{
  RGE_Zone_Map *this;
  int iVar1;
  
  if ((*param_1 != 0) && (0 < param_1[1])) {
    iVar1 = 0;
    if (0 < param_1[1]) {
      do {
        this = *(RGE_Zone_Map **)(*param_1 + iVar1 * 4);
        if (this != (RGE_Zone_Map *)0x0) {
          RGE_Zone_Map::~RGE_Zone_Map(this);
          operator_delete(this);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[1]);
    }
    free(*param_1);
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00547524
// Address: 00547524
void FUN_00547524(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VerQueryValueA();
  return;
}

// --------------------------------------------------

// Function: _VerQueryValueA@16
// Address: 00547530
void _VerQueryValueA_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VerQueryValueA();
  return;
}

// --------------------------------------------------

// Function: _GetFileVersionInfoA@16
// Address: 00547536
void _GetFileVersionInfoA_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547536. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetFileVersionInfoA();
  return;
}

// --------------------------------------------------

// Function: _GetFileVersionInfoSizeA@8
// Address: 0054753c
void _GetFileVersionInfoSizeA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054753c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetFileVersionInfoSizeA();
  return;
}

// --------------------------------------------------

// Function: _GetCurrentDirectoryA@8
// Address: 00547542
void _GetCurrentDirectoryA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547542. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetCurrentDirectoryA();
  return;
}

// --------------------------------------------------

// Function: _OpenFile@12
// Address: 00547548
void _OpenFile_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OpenFile();
  return;
}

// --------------------------------------------------

// Function: _GlobalMemoryStatus@4
// Address: 0054754e
void _GlobalMemoryStatus_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054754e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalMemoryStatus();
  return;
}

// --------------------------------------------------

// Function: _LoadLibraryA@4
// Address: 00547554
void _LoadLibraryA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LoadLibraryA();
  return;
}

// --------------------------------------------------

// Function: _FreeLibrary@4
// Address: 0054755a
void _FreeLibrary_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054755a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FreeLibrary();
  return;
}

// --------------------------------------------------

// Function: _CloseHandle@4
// Address: 00547560
void _CloseHandle_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CloseHandle();
  return;
}

// --------------------------------------------------

// Function: _MulDiv@12
// Address: 00547566
void _MulDiv_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547566. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MulDiv();
  return;
}

// --------------------------------------------------

// Function: _GetVolumeInformationA@32
// Address: 0054756c
void _GetVolumeInformationA_32(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054756c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetVolumeInformationA();
  return;
}

// --------------------------------------------------

// Function: _GetDriveTypeA@4
// Address: 00547572
void _GetDriveTypeA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetDriveTypeA();
  return;
}

// --------------------------------------------------

// Function: _ReleaseMutex@4
// Address: 00547578
void _ReleaseMutex_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseMutex();
  return;
}

// --------------------------------------------------

// Function: _GetLastError@0
// Address: 0054757e
void _GetLastError_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054757e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetLastError();
  return;
}

// --------------------------------------------------

// Function: _CreateMutexA@12
// Address: 00547584
void _CreateMutexA_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547584. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CreateMutexA();
  return;
}

// --------------------------------------------------

// Function: _OutputDebugStringA@4
// Address: 0054758a
void _OutputDebugStringA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054758a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OutputDebugStringA();
  return;
}

// --------------------------------------------------

// Function: _GetTickCount@0
// Address: 00547590
void _GetTickCount_0(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetTickCount();
  return;
}

// --------------------------------------------------

// Function: __lclose@4
// Address: 00547596
void __lclose_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547596. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _lclose();
  return;
}

// --------------------------------------------------

// Function: __hread@12
// Address: 0054759c
void __hread_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054759c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _hread();
  return;
}

// --------------------------------------------------

// Function: _GlobalFree@4
// Address: 005475a2
void _GlobalFree_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalFree();
  return;
}

// --------------------------------------------------

// Function: _GlobalLock@4
// Address: 005475a8
void _GlobalLock_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalLock();
  return;
}

// --------------------------------------------------

// Function: _GlobalReAlloc@12
// Address: 005475ae
void _GlobalReAlloc_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalReAlloc();
  return;
}

// --------------------------------------------------

// Function: _GlobalUnlock@4
// Address: 005475b4
void _GlobalUnlock_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalUnlock();
  return;
}

// --------------------------------------------------

// Function: _GlobalHandle@4
// Address: 005475ba
void _GlobalHandle_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalHandle();
  return;
}

// --------------------------------------------------

// Function: _LockResource@4
// Address: 005475c0
void _LockResource_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LockResource();
  return;
}

// --------------------------------------------------

// Function: _LoadResource@8
// Address: 005475c6
void _LoadResource_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LoadResource();
  return;
}

// --------------------------------------------------

// Function: _FindResourceA@12
// Address: 005475cc
void _FindResourceA_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FindResourceA();
  return;
}

// --------------------------------------------------

// Function: _GetModuleHandleA@4
// Address: 005475d2
void _GetModuleHandleA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetModuleHandleA();
  return;
}

// --------------------------------------------------

// Function: __hwrite@12
// Address: 005475d8
void __hwrite_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _hwrite();
  return;
}

// --------------------------------------------------

// Function: __lwrite@12
// Address: 005475de
void __lwrite_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _lwrite();
  return;
}

// --------------------------------------------------

// Function: _LocalFree@4
// Address: 005475e4
void _LocalFree_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LocalFree();
  return;
}

// --------------------------------------------------

// Function: _LocalAlloc@8
// Address: 005475ea
void _LocalAlloc_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LocalAlloc();
  return;
}

// --------------------------------------------------

// Function: _GlobalAlloc@8
// Address: 005475f0
void _GlobalAlloc_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GlobalAlloc();
  return;
}

// --------------------------------------------------

// Function: __lread@12
// Address: 005475f6
void __lread_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _lread();
  return;
}

// --------------------------------------------------

// Function: __llseek@12
// Address: 005475fc
void __llseek_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x005475fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _llseek();
  return;
}

// --------------------------------------------------

// Function: _GetProcAddress@8
// Address: 00547602
void _GetProcAddress_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547602. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetProcAddress();
  return;
}

// --------------------------------------------------

// Function: _GetVersionExA@4
// Address: 00547608
void _GetVersionExA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetVersionExA();
  return;
}

// --------------------------------------------------

// Function: _IsDBCSLeadByte@4
// Address: 0054760e
void _IsDBCSLeadByte_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054760e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IsDBCSLeadByte();
  return;
}

// --------------------------------------------------

// Function: _CompareStringA@24
// Address: 00547614
void _CompareStringA_24(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547614. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CompareStringA();
  return;
}

// --------------------------------------------------

// Function: _MapViewOfFile@20
// Address: 0054761a
void _MapViewOfFile_20(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054761a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MapViewOfFile();
  return;
}

// --------------------------------------------------

// Function: _CreateFileMappingA@24
// Address: 00547620
void _CreateFileMappingA_24(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CreateFileMappingA();
  return;
}

// --------------------------------------------------

// Function: _CreateFileA@28
// Address: 00547626
void _CreateFileA_28(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547626. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CreateFileA();
  return;
}

// --------------------------------------------------

// Function: _UnmapViewOfFile@4
// Address: 0054762c
void _UnmapViewOfFile_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054762c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UnmapViewOfFile();
  return;
}

// --------------------------------------------------

// Function: _GetTempFileNameA@16
// Address: 00547632
void _GetTempFileNameA_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547632. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetTempFileNameA();
  return;
}

// --------------------------------------------------

// Function: _GetTempPathA@8
// Address: 00547638
void _GetTempPathA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547638. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetTempPathA();
  return;
}

// --------------------------------------------------

// Function: _VirtualFree@12
// Address: 0054763e
void _VirtualFree_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054763e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  VirtualFree();
  return;
}

// --------------------------------------------------

// Function: _WinExec@8
// Address: 00547644
void _WinExec_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547644. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WinExec();
  return;
}

// --------------------------------------------------

// Function: _FindClose@4
// Address: 0054764a
void _FindClose_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054764a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FindClose();
  return;
}

// --------------------------------------------------

// Function: _FileTimeToSystemTime@8
// Address: 00547650
void _FileTimeToSystemTime_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FileTimeToSystemTime();
  return;
}

// --------------------------------------------------

// Function: _FindFirstFileA@8
// Address: 00547656
void _FindFirstFileA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547656. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FindFirstFileA();
  return;
}

// --------------------------------------------------

// Function: _LoadCursorA@8
// Address: 0054765c
void _LoadCursorA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054765c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LoadCursorA();
  return;
}

// --------------------------------------------------

// Function: _SetTimer@16
// Address: 00547662
void _SetTimer_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547662. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetTimer();
  return;
}

// --------------------------------------------------

// Function: _SetFocus@4
// Address: 00547668
void _SetFocus_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547668. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetFocus();
  return;
}

// --------------------------------------------------

// Function: _ShowWindow@8
// Address: 0054766e
void _ShowWindow_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054766e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ShowWindow();
  return;
}

// --------------------------------------------------

// Function: _SystemParametersInfoA@16
// Address: 00547674
void _SystemParametersInfoA_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547674. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SystemParametersInfoA();
  return;
}

// --------------------------------------------------

// Function: _SendMessageA@16
// Address: 0054767a
void _SendMessageA_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054767a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SendMessageA();
  return;
}

// --------------------------------------------------

// Function: _FindWindowA@8
// Address: 00547680
void _FindWindowA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FindWindowA();
  return;
}

// --------------------------------------------------

// Function: _DestroyWindow@4
// Address: 00547686
void _DestroyWindow_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547686. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DestroyWindow();
  return;
}

// --------------------------------------------------

// Function: _LoadStringA@16
// Address: 0054768c
void _LoadStringA_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054768c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LoadStringA();
  return;
}

// --------------------------------------------------

// Function: _GetMessageA@16
// Address: 00547692
void _GetMessageA_16(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547692. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetMessageA();
  return;
}

// --------------------------------------------------

// Function: _TranslateMessage@4
// Address: 00547698
void _TranslateMessage_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547698. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TranslateMessage();
  return;
}

// --------------------------------------------------

// Function: _PeekMessageA@20
// Address: 0054769e
void _PeekMessageA_20(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054769e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PeekMessageA();
  return;
}

// --------------------------------------------------

// Function: _DispatchMessageA@4
// Address: 005476a4
void _DispatchMessageA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DispatchMessageA();
  return;
}

// --------------------------------------------------

// Function: _CharUpperA@4
// Address: 005476aa
void _CharUpperA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CharUpperA();
  return;
}

// --------------------------------------------------

// Function: _RegisterClassA@4
// Address: 005476b0
void _RegisterClassA_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RegisterClassA();
  return;
}

// --------------------------------------------------

// Function: _LoadIconA@8
// Address: 005476b6
void _LoadIconA_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LoadIconA();
  return;
}

// --------------------------------------------------

// Function: _UpdateWindow@4
// Address: 005476bc
void _UpdateWindow_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UpdateWindow();
  return;
}

// --------------------------------------------------

// Function: _SetWindowPos@28
// Address: 005476c2
void _SetWindowPos_28(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetWindowPos();
  return;
}

// --------------------------------------------------

// Function: _GetClientRect@8
// Address: 005476c8
void _GetClientRect_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetClientRect();
  return;
}

// --------------------------------------------------

// Function: _GetWindowRect@8
// Address: 005476ce
void _GetWindowRect_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetWindowRect();
  return;
}

// --------------------------------------------------

// Function: _CreateWindowExA@48
// Address: 005476d4
void _CreateWindowExA_48(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CreateWindowExA();
  return;
}

// --------------------------------------------------

// Function: _GetSystemMetrics@4
// Address: 005476da
void _GetSystemMetrics_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetSystemMetrics();
  return;
}

// --------------------------------------------------

// Function: _ReleaseDC@8
// Address: 005476e0
void _ReleaseDC_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseDC();
  return;
}

// --------------------------------------------------

// Function: _GetDC@4
// Address: 005476e6
void _GetDC_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetDC();
  return;
}

// --------------------------------------------------

// Function: _BringWindowToTop@4
// Address: 005476ec
void _BringWindowToTop_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BringWindowToTop();
  return;
}

// --------------------------------------------------

// Function: _GetLastActivePopup@4
// Address: 005476f2
void _GetLastActivePopup_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetLastActivePopup();
  return;
}

// --------------------------------------------------

// Function: _SetForegroundWindow@4
// Address: 005476f8
void _SetForegroundWindow_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetForegroundWindow();
  return;
}

// --------------------------------------------------

// Function: _IsIconic@4
// Address: 005476fe
void _IsIconic_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x005476fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IsIconic();
  return;
}

// --------------------------------------------------

// Function: _GetUpdateRect@12
// Address: 00547704
void _GetUpdateRect_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547704. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetUpdateRect();
  return;
}

// --------------------------------------------------

// Function: _ValidateRect@8
// Address: 0054770a
void _ValidateRect_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054770a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ValidateRect();
  return;
}

// --------------------------------------------------

// Function: _FillRect@12
// Address: 00547710
void _FillRect_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FillRect();
  return;
}

// --------------------------------------------------

// Function: _ScreenToClient@8
// Address: 00547716
void _ScreenToClient_8(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547716. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScreenToClient();
  return;
}

// --------------------------------------------------

// Function: _GetCursorPos@4
// Address: 0054771c
void _GetCursorPos_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054771c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetCursorPos();
  return;
}

// --------------------------------------------------

// Function: _SetClassLongA@12
// Address: 00547722
void _SetClassLongA_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547722. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetClassLongA();
  return;
}

// --------------------------------------------------

// Function: _SetCursor@4
// Address: 00547728
void _SetCursor_4(void)
{
                    /* WARNING: Could not recover jumptable at 0x00547728. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetCursor();
  return;
}

// --------------------------------------------------

// Function: _GetWindowTextA@12
// Address: 0054772e
void _GetWindowTextA_12(void)
{
                    /* WARNING: Could not recover jumptable at 0x0054772e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetWindowTextA();
  return;
}

// --------------------------------------------------


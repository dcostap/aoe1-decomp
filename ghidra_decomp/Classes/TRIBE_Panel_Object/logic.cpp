// Class: TRIBE_Panel_Object
// Function: TRIBE_Panel_Object
// Address: 0051adf0
// [HELPER] s_health_shp: "health.shp"
// [HELPER] s_itemicon_shp: "itemicon.shp"
/* public: __thiscall TRIBE_Panel_Object::TRIBE_Panel_Object(class TDrawArea *,class TPanel *,void
   *,long,long,class TShape *,class TShape * *,class TRIBE_Player *) */

TRIBE_Panel_Object * __thiscall
TRIBE_Panel_Object::TRIBE_Panel_Object
          (TRIBE_Panel_Object *this,TDrawArea *param_1,TPanel *param_2,void *param_3,long param_4,
          long param_5,TShape *param_6,TShape **param_7,TRIBE_Player *param_8)
{
  long lVar1;
  TShape *pTVar2;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0056136e;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TPanel::TPanel((TPanel *)this);
  this->_padding_ = (int)&_vftable_;
  this->font = param_3;
  this->font_wid = param_4;
  this->font_hgt = param_5;
  this->health_pic = (TShape *)0x0;
  this->item_pic = (TShape *)0x0;
  this->unit_pics = param_6;
  this->bldg_pics = param_7;
  this->player = (TRIBE_Player *)0x0;
  this->game_obj = (RGE_Static_Object *)0x0;
  this->idle_time = 0;
  this->idle_interval = 500;
  this->mode = '\x01';
  this->save_obj_type = (RGE_Master_Static_Object *)0x0;
  this->save_attr_type = -1;
  this->save_attr_amount = 0.0;
  this->save_object_state = '\0';
  this->save_build_pts = 0.0;
  this->save_list = (RGE_Object_Node *)0x0;
  this->save_hp = 0.0;
  this->save_armor = 0;
  this->save_pierce_armor = 0;
  this->save_weapon = 0;
  this->save_weapon_range = 0.0;
  this->save_speed_of_attack = 0.0;
  this->save_work_type = 0;
  this->save_work_target = 0;
  this->save_progress = 0;
  this->save_name[0] = '\0';
  this->save_facet = '\0';
  this->save_angle = 0.0;
  this->save_los = 0.0;
  this->save_pop = 0;
  this->save_max_pop = 0;
  this->save_selected_group = '\0';
  this->save_owner = (RGE_Player *)0x0;
  this->save_have_action = '\0';
  this->save_farm_amt = 0;
  piVar4 = this->save_score;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  local_4 = 0;
  lVar1 = TPanel::setup((TPanel *)this,param_1,param_2,0,0,0,0,'\0');
  if (lVar1 == 0) {
    this->_padding_ = 1;
  }
  else {
    set_player(this,param_8);
    pTVar2 = (TShape *)operator_new(0x20);
    local_4._0_1_ = 1;
    if (pTVar2 == (TShape *)0x0) {
      pTVar2 = (TShape *)0x0;
    }
    else {
      pTVar2 = (TShape *)TShape::TShape(pTVar2,s_health_shp,0xc639);
    }
    local_4._0_1_ = 0;
    this->health_pic = pTVar2;
    if (pTVar2 != (TShape *)0x0) {
      iVar3 = TShape::is_loaded(pTVar2);
      if (iVar3 == 0) {
        pTVar2 = this->health_pic;
        if (pTVar2 != (TShape *)0x0) {
          TShape::~TShape(pTVar2);
          operator_delete(pTVar2);
        }
        this->health_pic = (TShape *)0x0;
      }
    }
    pTVar2 = (TShape *)operator_new(0x20);
    local_4._0_1_ = 2;
    if (pTVar2 == (TShape *)0x0) {
      pTVar2 = (TShape *)0x0;
    }
    else {
      pTVar2 = (TShape *)TShape::TShape(pTVar2,s_itemicon_shp,0xc62b);
    }
    local_4 = (uint)local_4._1_3_ << 8;
    this->item_pic = pTVar2;
    if (pTVar2 != (TShape *)0x0) {
      iVar3 = TShape::is_loaded(pTVar2);
      if (iVar3 == 0) {
        pTVar2 = this->item_pic;
        if (pTVar2 != (TShape *)0x0) {
          TShape::~TShape(pTVar2);
          operator_delete(pTVar2);
        }
        this->item_pic = (TShape *)0x0;
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0051b050
/* public: virtual void * __thiscall TRIBE_Panel_Object::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Panel_Object::_scalar_deleting_destructor_(TRIBE_Panel_Object *this,uint param_1)
{
  ~TRIBE_Panel_Object(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_Panel_Object
// Address: 0051b070
/* public: virtual __thiscall TRIBE_Panel_Object::~TRIBE_Panel_Object(void) */

void __thiscall TRIBE_Panel_Object::~TRIBE_Panel_Object(TRIBE_Panel_Object *this)
{
  TShape *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00561388;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  pTVar1 = this->health_pic;
  local_4 = 0;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    this->health_pic = (TShape *)0x0;
  }
  pTVar1 = this->item_pic;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    this->item_pic = (TShape *)0x0;
  }
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: set_player
// Address: 0051b110
/* public: void __thiscall TRIBE_Panel_Object::set_player(class TRIBE_Player *) */

void __thiscall TRIBE_Panel_Object::set_player(TRIBE_Panel_Object *this,TRIBE_Player *param_1)
{
  this->player = param_1;
  if (param_1 != (TRIBE_Player *)0x0) {
    set_object(this,(RGE_Static_Object *)param_1->_padding_);
    return;
  }
  set_object(this,(RGE_Static_Object *)0x0);
  return;
}

// --------------------------------------------------

// Function: set_object
// Address: 0051b140
/* public: void __thiscall TRIBE_Panel_Object::set_object(class RGE_Static_Object *) */

void __thiscall TRIBE_Panel_Object::set_object(TRIBE_Panel_Object *this,RGE_Static_Object *param_1)
{
  this->game_obj = param_1;
  save_object_info(this);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_mode
// Address: 0051b160
/* public: void __thiscall TRIBE_Panel_Object::set_mode(unsigned char) */

void __thiscall TRIBE_Panel_Object::set_mode(TRIBE_Panel_Object *this,uchar param_1)
{
  this->mode = param_1;
  save_object_info(this);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: get_mode
// Address: 0051b180
/* public: unsigned char __thiscall TRIBE_Panel_Object::get_mode(void) */

uchar __thiscall TRIBE_Panel_Object::get_mode(TRIBE_Panel_Object *this)
{
  return this->mode;
}

// --------------------------------------------------

// Function: draw
// Address: 0051b190
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s__d__s: "%d-%s"
// [HELPER] s__s: "%s"
// [HELPER] s_tpnl_obj__draw: "tpnl_obj::draw"
/* WARNING: Variable defined which should be unmapped: cur_val */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall TRIBE_Panel_Object::draw(void) */

void __thiscall TRIBE_Panel_Object::draw(TRIBE_Panel_Object *this)
{
  char cVar1;
  byte bVar2;
  RGE_Master_Static_Object *pRVar3;
  RGE_Color_Table *pRVar4;
  bool bVar5;
  short sVar6;
  uchar *puVar7;
  void *pvVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  int iVar12;
  RGE_Action *pRVar13;
  RGE_Player *pRVar14;
  RGE_Static_Object *pRVar15;
  uint uVar16;
  uint uVar17;
  undefined2 uVar18;
  int unaff_EBX;
  float fVar19;
  undefined4 unaff_EBP;
  char cVar20;
  short unaff_SI;
  int unaff_EDI;
  TShape *this_00;
  char *pcVar21;
  TRIBE_Building_Object *this_01;
  TDrawArea *pTVar22;
  long lVar23;
  float fVar24;
  uchar uVar25;
  undefined4 uVar26;
  uchar uVar27;
  short cur_val;
  short orig_val;
  float fStack_154;
  float dx;
  short work_type;
  TRIBE_Building_Object *bldg_obj;
  float cur_fval;
  short progress;
  short work_target;
  float orig_fval;
  short temp;
  char name [100];
  char str [100];
  char work_name [100];
  
  if (((this->_padding_ == 0) || (this->_padding_ == 0)) || (this->_padding_ == 0)) {
LAB_0051be7b:
    this->_padding_ = 0;
    return;
  }
  if (this->mode == '\x02') {
    draw_score(this);
    return;
  }
  if (this->game_obj == (RGE_Static_Object *)0x0) {
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0x34))(&this->_padding_);
      this->_padding_ = 0;
      return;
    }
    goto LAB_0051be7b;
  }
  fVar19 = (float)this->_padding_;
  _cur_val = unaff_EBX;
  dx = fVar19;
  (**(code **)((int)fVar19 + 0x28))(0);
  TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,0);
  puVar7 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_obj__draw,1);
  if (puVar7 != (uchar *)0x0) {
    pRVar15 = this->game_obj;
    pRVar3 = pRVar15->master_obj;
    sVar6 = pRVar3->button_pict;
    if (sVar6 != -1) {
      if (pRVar3->unit_level == '\x02') {
        bVar2 = (byte)pRVar15[3].attribute_type_held;
        dx = (float)CONCAT31(dx._1_3_,bVar2);
        sVar6 = sVar6 + *(short *)((int)&pRVar3[1].outline_radius_z + 2);
        this_00 = this->bldg_pics[bVar2];
      }
      else {
        this_00 = this->unit_pics;
      }
      pRVar4 = pRVar15->owner->color_table;
      if (pRVar4 == (RGE_Color_Table *)0x0) {
        iVar9 = this->_padding_;
        iVar12 = this->_padding_;
        puVar7 = (uchar *)0x0;
        pTVar22 = (TDrawArea *)this->_padding_;
      }
      else {
        _ASMSet_Color_Xform((pRVar4->id + 1) * 0x10);
        iVar9 = this->_padding_;
        puVar7 = this->game_obj->owner->color_table->table;
        iVar12 = this->_padding_;
        pTVar22 = (TDrawArea *)this->_padding_;
      }
      TShape::shape_draw(this_00,pTVar22,iVar12 + 3,iVar9 + 0x1e,(int)sVar6,
                         pRVar4 != (RGE_Color_Table *)0x0,puVar7);
    }
    pRVar15 = this->game_obj;
    if ((UNK_00576d7c._4_4_ < pRVar15->hp) && (this->health_pic != (TShape *)0x0)) {
      dx = (float)TShape::shape_count(this->health_pic);
      bldg_obj = (TRIBE_Building_Object *)(float)(int)dx;
      TShape::shape_count(this->health_pic);
      dx = (float)(int)pRVar15->master_obj->hp;
      sVar6 = __ftol();
      if (sVar6 < 0) {
        sVar6 = 0;
      }
      else {
        lVar23 = TShape::shape_count(this->health_pic);
        if (lVar23 + -1 < (int)sVar6) {
          lVar23 = TShape::shape_count(this->health_pic);
          sVar6 = (short)lVar23 + -1;
        }
      }
      TShape::shape_draw(this->health_pic,(TDrawArea *)this->_padding_,this->_padding_ + 3,
                         this->_padding_ + 0x54,(int)sVar6,'\0',(uchar *)0x0);
    }
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_obj__draw);
  }
  pvVar8 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_obj__draw);
  if (pvVar8 != (void *)0x0) {
    SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
    SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
    bldg_obj = (TRIBE_Building_Object *)
               SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
    if (this->game_obj->owner->id != 0) {
      iVar9 = RGE_Base_Game::campaignGame(rge_base_game);
      if (iVar9 == 0) {
        name[0] = '\0';
      }
      else {
        pRVar14 = this->game_obj->owner;
        pcVar10 = RGE_Scenario::GetPlayerName(pRVar14->world->scenario,pRVar14->id + -1);
        uVar16 = 0xffffffff;
        do {
          pcVar21 = pcVar10;
          if (uVar16 == 0) break;
          uVar16 = uVar16 - 1;
          pcVar21 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar21;
        } while (cVar1 != '\0');
        uVar16 = ~uVar16;
        pcVar10 = pcVar21 + -uVar16;
        pcVar21 = name;
        for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
          *(undefined4 *)pcVar21 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar21 = pcVar21 + 4;
        }
        for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
          *pcVar21 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar21 = pcVar21 + 1;
        }
      }
      if (name[0] == '\0') {
        (**(code **)(rge_base_game->_padding_ + 0x28))
                  (0x69,this->game_obj->owner->master_player_id,0,name,100);
      }
      uVar16 = 0xffffffff;
      pcVar10 = name;
      do {
        if (uVar16 == 0) break;
        uVar16 = uVar16 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 3,this->_padding_ + -2,name
               ,~uVar16 - 1);
    }
    sVar6 = this->game_obj->master_obj->string_id;
    if (sVar6 < 1) {
      str[0] = '\0';
    }
    else {
      (**(code **)(rge_base_game->_padding_ + 0x20))((int)sVar6,str,100);
    }
    if (str[0] == '\0') {
      uVar16 = 0xffffffff;
      pcVar10 = this->game_obj->master_obj->name;
      do {
        pcVar21 = pcVar10;
        if (uVar16 == 0) break;
        uVar16 = uVar16 - 1;
        pcVar21 = pcVar10 + 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar21;
      } while (cVar1 != '\0');
      uVar16 = ~uVar16;
      pcVar10 = pcVar21 + -uVar16;
      pcVar21 = str;
      for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
        *(undefined4 *)pcVar21 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar21 = pcVar21 + 4;
      }
      for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
        *pcVar21 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar21 = pcVar21 + 1;
      }
    }
    if (*(int *)(rge_base_game[1].work_dir + 0x14) == 0) {
      sprintf(name,s__s,str);
    }
    else {
      sprintf(name,s__d__s,this->game_obj->id,str);
    }
    uVar16 = 0xffffffff;
    pcVar10 = name;
    do {
      if (uVar16 == 0) break;
      uVar16 = uVar16 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 3,this->_padding_ + 0xd,name,
             ~uVar16 - 1);
    if (UNK_00576d7c._4_4_ < this->game_obj->hp) {
      uVar11 = __ftol((int)this->game_obj->master_obj->hp);
      sprintf(str,s__d__d,uVar11);
      uVar16 = 0xffffffff;
      pcVar10 = str;
      do {
        if (uVar16 == 0) break;
        uVar16 = uVar16 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 3,this->_padding_ + 0x5c,
               str,~uVar16 - 1);
    }
    SelectObject(*(undefined4 *)(this->_padding_ + 0x38),bldg_obj);
    SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),0);
    TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_obj__draw);
    fVar19 = fStack_154;
  }
  this_01 = (TRIBE_Building_Object *)this->game_obj;
  cVar20 = '\0';
  cVar1 = *(char *)(this_01->_padding_ + 0x8f);
  sVar6 = (short)((uint)unaff_EBP >> 0x10);
  if (cVar1 == '\x03') {
LAB_0051bb21:
    (**(code **)(this_01->_padding_ + 0x230))(&cur_val,&orig_val);
    (**(code **)((int)fVar19 + 0xe0))(0,7,1,(int)sVar6,(int)unaff_SI);
    cVar20 = '\x01';
LAB_0051bb52:
    (**(code **)(this->game_obj->_padding_ + 0x22c))(&cur_val,&orig_val);
    if (((0 < unaff_SI) || (uVar25 = this->game_obj->master_obj->unit_level, uVar25 == '\x04')) ||
       (uVar25 == '\x06')) {
      (**(code **)((int)fVar19 + 0xe0))(cVar20,8,1,(int)sVar6,(int)unaff_SI);
      cVar20 = cVar20 + '\x01';
    }
    (**(code **)(this->game_obj->_padding_ + 0x244))(&stack0xfffffe9c,&stack0xfffffea2);
    if (0 < (short)_cur_val) {
      (**(code **)((int)fVar19 + 0xe0))(cVar20,10,1,(int)orig_val,(int)(short)_cur_val);
      cVar20 = cVar20 + '\x01';
    }
    uVar25 = this->game_obj->master_obj->unit_level;
    if (((uVar25 == '\x04') || (uVar25 == '\x06')) &&
       ((**(code **)(this->game_obj->_padding_ + 0x234))(&cur_fval,&orig_fval),
       _DAT_00576dac < cur_fval)) {
      uVar11 = __ftol();
      uVar11 = __ftol(uVar11);
      (**(code **)((int)fVar19 + 0xe0))(cVar20,6,1,uVar11);
      cVar20 = cVar20 + '\x01';
    }
    if (this->game_obj->master_obj->unit_level == '\x06') {
      uVar11 = __ftol(0);
      (**(code **)((int)fVar19 + 0xe0))(cVar20,9,3,uVar11);
      cVar20 = cVar20 + '\x01';
    }
    pRVar15 = this->game_obj;
    if ((TRIBE_Player *)pRVar15->owner != this->player) goto LAB_0051be67;
    uVar25 = pRVar15->master_obj->unit_level;
    if (uVar25 == '\a') {
      (**(code **)((int)fVar19 + 0xe0))
                (cVar20,4,2,(int)pRVar15->objects->number_of_objects,pRVar15->master_obj->obj_max);
      (**(code **)(unaff_EDI + 0x2c))();
      return;
    }
    if (uVar25 == '\t') {
      if ((pRVar15->attribute_type_held == 0x11) || (pRVar15->attribute_type_held == 0)) {
        _cur_val = __ftol();
      }
      else {
        _cur_val = 0;
      }
      (**(code **)((int)fVar19 + 0xe0))(cVar20,2,0,(int)(short)_cur_val,0);
      (**(code **)(unaff_EDI + 0x2c))();
      return;
    }
    if (uVar25 == '\x05') {
      switch(pRVar15->attribute_type_held) {
      case 0:
      case 0xf:
      case 0x10:
      case 0x11:
        _cur_val = 2;
        break;
      case 1:
        _cur_val = 0;
        break;
      case 2:
        _cur_val = 1;
        break;
      case 3:
        _cur_val = 3;
        break;
      default:
switchD_0051b6bc_caseD_4:
        _cur_val = 0xffffffff;
        (**(code **)((int)fStack_154 + 0x2c))();
        return;
      case 9:
        _cur_val = 5;
      }
      if ((float)_DAT_00576db0 < pRVar15->attribute_amount_held) {
        _cur_val = 3;
        uVar11 = __ftol(0);
        (**(code **)((int)fVar19 + 0xe0))(cVar20,3,0,uVar11);
        (**(code **)(unaff_EDI + 0x2c))();
        return;
      }
      (**(code **)((int)fVar19 + 0xe0))(cVar20,(short)_cur_val,4,0xffffffff,0);
      (**(code **)(unaff_EDI + 0x2c))();
      return;
    }
    iVar9 = __ftol();
    if (iVar9 < 1) goto LAB_0051be67;
    switch(pRVar15->attribute_type_held) {
    case 0:
    case 0xf:
    case 0x10:
    case 0x11:
      uVar18 = 2;
      _cur_val = 2;
      break;
    case 1:
      uVar18 = 0;
      _cur_val = 0;
      break;
    case 2:
      uVar18 = 1;
      _cur_val = 1;
      break;
    case 3:
      uVar18 = 3;
      _cur_val = 3;
      break;
    default:
      goto switchD_0051b6bc_caseD_4;
    case 9:
      uVar18 = 5;
      _cur_val = 5;
    }
    uVar11 = __ftol(0);
    uVar26 = 0;
  }
  else {
    if (((cVar1 == '\t') || (cVar1 == '\x04')) ||
       ((cVar1 == '\x05' || ((cVar1 == '\x06' || (cVar1 == '\a')))))) {
      if ((cVar1 == '\x03') || (cVar1 == '\x04')) goto LAB_0051bb21;
      goto LAB_0051bb52;
    }
    if (cVar1 == '\x01') {
      switch((short)this_01->_padding_) {
      case 0:
      case 0xf:
      case 0x10:
      case 0x11:
        uVar11 = 2;
        break;
      case 1:
        uVar11 = 0;
        break;
      case 2:
        uVar11 = 1;
        break;
      case 3:
        uVar11 = 3;
        break;
      default:
        goto switchD_0051b6bc_caseD_4;
      case 9:
        uVar11 = 5;
      }
      _cur_val = uVar11;
      uVar26 = __ftol(0);
      (**(code **)((int)fVar19 + 0xe0))(0,(short)uVar11,0,uVar26);
      (**(code **)(unaff_EDI + 0x2c))();
      return;
    }
    if ((cVar1 != '\x02') && (cVar1 != '\b')) goto LAB_0051be67;
    if (*(char *)(this_01->_padding_ + 4) == 'P') {
      bldg_obj = this_01;
      TRIBE_Building_Object::work_status(this_01,&work_type,&work_target,&progress,work_name,100);
      if ((((short)_work_type != 0x67) && ((short)_work_type != 0x66)) &&
         (iVar9 = TRIBE_Building_Object::production_queue_status(this_01,&work_target,&temp),
         iVar9 != 0)) {
        _work_type = 0x66;
        _progress = _temp;
      }
      if ((this->game_obj->object_state != '\0') &&
         (((TRIBE_Player *)this->game_obj->owner != this->player ||
          (((short)_work_type != 0x67 && ((short)_work_type != 0x66)))))) {
        iVar9 = this_01->_padding_;
        (**(code **)(iVar9 + 0x230))(&cur_val,&orig_val);
        if (0 < unaff_SI) {
          (**(code **)(_cur_val + 0xe0))(0,7,1,(int)sVar6,(int)unaff_SI);
        }
        cVar20 = 0 < unaff_SI;
        (**(code **)(iVar9 + 0x234))(&work_type,&progress);
        iVar9 = __ftol();
        if (0 < iVar9) {
          uVar11 = __ftol(iVar9);
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,6,1,uVar11);
          cVar20 = cVar20 + '\x01';
        }
      }
      if ((TRIBE_Player *)this->game_obj->owner == this->player) {
        if ((char)this_01->_padding_ == '\0') {
          uVar11 = 0;
          sVar6 = TRIBE_Building_Object::get_construction_progress(this_01);
LAB_0051b878:
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,9,3,(int)sVar6,uVar11);
        }
        else {
          if (((short)_work_type == 0x67) || ((short)_work_type == 0x66)) {
            uVar11 = 0;
            sVar6 = progress;
            goto LAB_0051b878;
          }
          if (this->game_obj->master_obj->id == 0x46) {
            iVar12 = __ftol();
            iVar9 = __ftol();
            if (iVar12 <= iVar9) {
              iVar9 = iVar12;
            }
            uVar11 = __ftol(iVar9);
            (**(code **)((int)fStack_154 + 0xe0))(cVar20,4,2,uVar11);
            cVar20 = cVar20 + '\x01';
            this_01 = bldg_obj;
          }
          if ((this->game_obj->master_obj->id != 0x32) ||
             (pRVar13 = RGE_Action_List::get_action((RGE_Action_List *)this_01->_padding_),
             pRVar13 == (RGE_Action *)0x0)) goto LAB_0051b925;
          uVar11 = __ftol(0);
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,2,0,uVar11);
        }
        cVar20 = cVar20 + '\x01';
      }
    }
LAB_0051b925:
    pRVar15 = this->game_obj;
    if ((pRVar15->object_state != '\0') && (pRVar15->object_state == '\x02')) {
      bVar5 = false;
      if ((TRIBE_Player *)pRVar15->owner == this->player) {
LAB_0051b95b:
        if (((short)_work_type != 0x67) && ((short)_work_type != 0x66)) {
          sVar6 = pRVar15->master_obj->id;
          if (sVar6 == 0x2d) {
LAB_0051b995:
            bVar5 = true;
          }
          else if (sVar6 == 0x32) {
            bVar5 = false;
          }
          else if ((pRVar15->attribute_type_held != -1) && (iVar9 = __ftol(), 0 < iVar9))
          goto LAB_0051b995;
        }
      }
      else {
        if (pRVar15->master_obj->id == 0x2d) goto LAB_0051b995;
        if ((TRIBE_Player *)pRVar15->owner == this->player) goto LAB_0051b95b;
      }
      if (bVar5) {
        switch(pRVar15->attribute_type_held) {
        case 0:
        case 0xf:
        case 0x10:
        case 0x11:
          uVar18 = 2;
          _cur_val = 2;
          break;
        case 1:
          uVar18 = 0;
          _cur_val = 0;
          break;
        case 2:
          uVar18 = 1;
          _cur_val = 1;
          break;
        case 3:
          uVar18 = 3;
          _cur_val = 3;
          break;
        default:
          _cur_val = -1;
          goto LAB_0051ba3c;
        case 9:
          uVar18 = 5;
          _cur_val = 5;
        }
        if (pRVar15->master_obj->id == 0x2d) {
          uVar11 = __ftol(0);
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,uVar18,0,uVar11);
        }
        else {
          uVar11 = __ftol(0);
          (**(code **)((int)fStack_154 + 0xe0))(cVar20,uVar18,0,uVar11);
        }
        cVar20 = cVar20 + '\x01';
      }
    }
LAB_0051ba3c:
    pRVar15 = this->game_obj;
    if ((pRVar15->master_obj->id != 0x2d) || ((TRIBE_Player *)pRVar15->owner == this->player))
    goto LAB_0051be67;
    fVar19 = pRVar15->world_y;
    fVar24 = pRVar15->world_x;
    uVar27 = '\x02';
    uVar25 = '\x01';
    lVar23 = 0x2d;
    pRVar14 = RGE_Base_Game::get_player(rge_base_game);
    pRVar15 = RGE_Object_List::find_by_master_id
                        (pRVar14->objects,lVar23,fVar24,fVar19,uVar25,uVar27,pRVar15);
    if (pRVar15 == (RGE_Static_Object *)0x0) goto LAB_0051be67;
    dx = pRVar15->world_x - this->game_obj->world_x;
    uVar11 = __ftol(0x14);
    uVar26 = 2;
    uVar18 = 3;
  }
  (**(code **)((int)fStack_154 + 0xe0))(cVar20,uVar18,uVar26,uVar11);
LAB_0051be67:
  (**(code **)((int)fStack_154 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: draw_score
// Address: 0051bf90
// [HELPER] s__d: "%d"
// [HELPER] s_tpnl_obj__draw_score: "tpnl_obj::draw_score"
/* WARNING: Variable defined which should be unmapped: i */
/* protected: void __thiscall TRIBE_Panel_Object::draw_score(void) */

void __thiscall TRIBE_Panel_Object::draw_score(TRIBE_Panel_Object *this)
{
  char cVar1;
  short sVar2;
  RGE_Player *pRVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  int i;
  short x_val;
  void *old_font;
  RGE_Player *temp_player;
  int iStack_84;
  short x;
  short y;
  tagRECT rect;
  char str [100];
  
  iVar12 = 0;
  if (((this->_padding_ == 0) || (this->_padding_ == 0)) || (this->_padding_ == 0)) {
    this->_padding_ = 0;
    return;
  }
  iVar14 = this->_padding_;
  (**(code **)(iVar14 + 0x28))(0);
  TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,0);
  pvVar4 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_obj__draw_score);
  if (pvVar4 != (void *)0x0) {
    SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
    uVar5 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
    sVar2 = (short)this->_padding_;
    x = sVar2 + 3;
    iVar14 = this->_padding_;
    i = 1;
    do {
      iVar6 = RGE_Base_Game::playerID(rge_base_game,i);
      if ((iVar6 != 0) && (iVar6 < rge_base_game->world->player_num)) {
        pRVar3 = rge_base_game->world->players[iVar6];
        switch(pRVar3->color_table->id) {
        case 0:
          uVar7 = 0xff0000;
          break;
        case 1:
          uVar7 = 0x2139c6;
          break;
        case 2:
          uVar7 = 0xffff;
          break;
        case 3:
          uVar7 = 0x4f73a3;
          break;
        case 4:
          uVar7 = 0xf77f3;
          break;
        case 5:
          uVar7 = 0xc700;
          break;
        case 6:
          uVar7 = 0x7b90a2;
          break;
        case 7:
          uVar7 = 0xadad00;
          break;
        default:
          uVar7 = 0xffffff;
        }
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),uVar7);
        pcVar8 = TCommunications_Handler::GetPlayerName(comm,i);
        uVar10 = 0xffffffff;
        do {
          pcVar15 = pcVar8;
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          pcVar15 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar15;
        } while (cVar1 != '\0');
        uVar10 = ~uVar10;
        pcVar8 = pcVar15 + -uVar10;
        pcVar15 = str;
        for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
          *pcVar15 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar15 = pcVar15 + 1;
        }
        uVar10 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        iVar13 = (int)(short)((short)iVar14 + -1);
        iVar6 = iVar12 + iVar13;
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),(int)x,iVar6,str,~uVar10 - 1);
        lVar9 = RGE_Victory_Conditions::get_victory_points(pRVar3->victory_conditions);
        sprintf(str,&s__d,lVar9);
        SetRect(&rect,(int)(short)(sVar2 + 0x5a),iVar6,this->_padding_ + -3 + this->_padding_,
                iVar12 + 0xe + iVar13);
        DrawTextA(*(undefined4 *)(this->_padding_ + 0x38),str,0xffffffff,&rect,0x22);
        iVar12 = iVar12 + 0xe;
      }
      i = i + 1;
    } while (i < 9);
    SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar5);
    TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_obj__draw_score);
    iVar14 = iStack_84;
  }
  (**(code **)(iVar14 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: draw_item
// Address: 0051c220
// [HELPER] s__d: "%d"
// [HELPER] s__d__: "%d%%"
// [HELPER] s__d__d: "%d+%d"
// [HELPER] s_tpnl_obj__draw_item: "tpnl_obj::draw_item"
/* WARNING: Variable defined which should be unmapped: val_str */
/* protected: virtual void __thiscall TRIBE_Panel_Object::draw_item(int,int,enum
   TRIBE_Panel_Object::ValueType,int,int) */

void __thiscall
TRIBE_Panel_Object::draw_item
          (TRIBE_Panel_Object *this,int param_1,int param_2,ValueType param_3,int param_4,
          int param_5)
{
  char cVar1;
  uchar *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  char val_str [20];
  
  if (((this->item_pic != (TShape *)0x0) && (param_2 != -1)) &&
     (puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_tpnl_obj__draw_item,1),
     puVar2 != (uchar *)0x0)) {
    TShape::shape_draw(this->item_pic,(TDrawArea *)this->_padding_,this->_padding_ + 0x36,
                       this->_padding_ + 0x1e + param_1 * 0x14,param_2,'\0',(uchar *)0x0);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_tpnl_obj__draw_item);
  }
  switch(param_3) {
  case ValueTypeNumber:
    sprintf(val_str + 4,&s__d,param_4);
    break;
  case ValueTypeBonus:
    if (param_4 < param_5) {
      sprintf(val_str + 4,s__d__d,param_4,param_5 - param_4);
    }
    else {
      sprintf(val_str + 4,&s__d,param_4);
    }
    break;
  case ValueTypeCompare:
    sprintf(val_str + 4,s__d__d,param_4,param_5);
    break;
  case ValueTypePercent:
    sprintf(val_str + 4,s__d__,param_4);
    break;
  default:
    val_str[4] = '\0';
  }
  if ((val_str[4] != '\0') &&
     (pvVar3 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_obj__draw_item),
     pvVar3 != (void *)0x0)) {
    SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
    SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
    uVar4 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
    uVar5 = 0xffffffff;
    pcVar6 = val_str + 4;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_ + 0x58,
             this->_padding_ + 0x21 + param_1 * 0x14,val_str + 4,~uVar5 - 1);
    SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar4);
    TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_obj__draw_item);
  }
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0051c3f0
// [HELPER] s_C__msdev_work_age1_x1_tpnl_obj_c: "C:\msdev\work\age1_x1\tpnl_obj.cpp"
/* WARNING: Variable defined which should be unmapped: changed */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual long __thiscall TRIBE_Panel_Object::handle_idle(void) */

long __thiscall TRIBE_Panel_Object::handle_idle(TRIBE_Panel_Object *this)
{
  byte bVar1;
  TRIBE_Player *pTVar2;
  RGE_Action_Object *this_00;
  RGE_Master_Static_Object *pRVar3;
  bool bVar4;
  uchar uVar5;
  short sVar6;
  ulong uVar7;
  int iVar8;
  long lVar9;
  byte *pbVar10;
  RGE_Action *pRVar11;
  TRIBE_Building_Object *this_01;
  char *pcVar12;
  int iVar13;
  bool bVar14;
  bool bVar15;
  int changed;
  int do_buttons;
  short cur_val;
  short work_target;
  short orig_val;
  float cur_fval;
  short temp;
  short work_type;
  TRIBE_Building_Object *bldg_obj;
  short progress;
  float orig_fval;
  char name [100];
  
  TPanel::handle_idle((TPanel *)this);
  if (this->_padding_ == 0) {
    return 0;
  }
  uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_tpnl_obj_c,0x37c);
  if (uVar7 - this->idle_time < this->idle_interval) {
    return 0;
  }
  uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_tpnl_obj_c,0x37f);
  this->idle_time = uVar7;
  if (this->mode == '\x02') {
    iVar13 = 1;
    while ((iVar8 = RGE_Base_Game::playerID(rge_base_game,iVar13), iVar8 == 0 ||
           (lVar9 = RGE_Victory_Conditions::get_victory_points
                              (rge_base_game->world->players[iVar8]->victory_conditions),
           this->save_score[iVar8] == lVar9))) {
      iVar13 = iVar13 + 1;
      if (8 < iVar13) {
        return 0;
      }
    }
    if (this->_padding_ == 0) {
      (**(code **)(this->_padding_ + 0x20))(1);
    }
    save_object_info(this);
    return 0;
  }
  pTVar2 = this->player;
  if (pTVar2 == (TRIBE_Player *)0x0) {
    if (this->game_obj != (RGE_Static_Object *)0x0) {
LAB_0051c4ef:
      if (pTVar2 == (TRIBE_Player *)0x0) {
        set_object(this,(RGE_Static_Object *)0x0);
        return 0;
      }
      set_object(this,(RGE_Static_Object *)pTVar2->_padding_);
      return 0;
    }
  }
  else if ((RGE_Static_Object *)pTVar2->_padding_ != this->game_obj) goto LAB_0051c4ef;
  this_00 = (RGE_Action_Object *)this->game_obj;
  bVar14 = false;
  bVar15 = false;
  bVar4 = false;
  if (this_00 == (RGE_Action_Object *)0x0) goto LAB_0051c9cd;
  if ((RGE_Player *)this_00->_padding_ == this->save_owner) {
    if (*(uchar *)((int)&this_00->_padding_ + 3) == this->save_selected_group) {
      pRVar3 = (RGE_Master_Static_Object *)this_00->_padding_;
      if (pRVar3 == this->save_obj_type) {
        sVar6 = *(short *)(this_00->_padding_ + 8);
        if (sVar6 == this->save_number_of_objects) {
          if (((((short)this_00->_padding_ != this->save_attr_type) ||
               ((float)this_00->_padding_ != this->save_attr_amount)) ||
              ((float)this_00->_padding_ != this->save_hp)) ||
             (((*(RGE_Object_Node **)(this_00->_padding_ + 4) != this->save_list ||
               (pRVar3->los != this->save_los)) || (pRVar3->id == 0x2d)))) {
            bVar14 = true;
            bVar15 = true;
          }
        }
        else {
          bVar14 = true;
          bVar15 = true;
          if ((sVar6 == 0) || (this->save_number_of_objects == 0)) {
            bVar4 = true;
          }
        }
      }
      else {
        bVar14 = true;
        bVar15 = true;
        bVar4 = true;
      }
    }
    else {
      bVar14 = true;
      bVar15 = true;
      bVar4 = true;
    }
  }
  else {
    bVar14 = true;
    bVar15 = true;
    bVar4 = true;
  }
  if (bVar14) {
LAB_0051c770:
    if (bVar4) goto LAB_0051c9cd;
  }
  else {
    bVar1 = *(byte *)(this_00->_padding_ + 4);
    if ((0x45 < bVar1) && (bVar1 != 0x5a)) {
      uVar5 = RGE_Action_Object::have_action(this_00);
      if (uVar5 != this->save_have_action) {
        bVar14 = true;
        bVar15 = true;
        bVar4 = true;
      }
      if (!bVar14) {
        (**(code **)(this->game_obj->_padding_ + 0x22c))(&orig_val,(int)&cur_fval + 2);
        if (orig_val != this->save_armor) {
          bVar14 = true;
          bVar15 = true;
        }
        if (!bVar14) {
          (**(code **)(this->game_obj->_padding_ + 0x244))(&orig_val,(int)&cur_fval + 2);
          if (orig_val != this->save_pierce_armor) {
            bVar14 = true;
            bVar15 = true;
          }
          if (!bVar14) {
            (**(code **)(this->game_obj->_padding_ + 0x230))(&orig_val,(int)&cur_fval + 2);
            if (orig_val != this->save_weapon) {
              bVar14 = true;
              bVar15 = true;
            }
            if (!bVar14) {
              (**(code **)(this->game_obj->_padding_ + 0x234))(&temp,name);
              if (_temp != this->save_weapon_range) {
                bVar14 = true;
                bVar15 = true;
              }
              if (!bVar14) {
                (**(code **)(this->game_obj->_padding_ + 0x238))(&temp,name);
                if (_temp != this->save_speed_of_attack) {
                  bVar14 = true;
                  bVar15 = true;
                }
                goto LAB_0051c76c;
              }
            }
          }
        }
      }
      goto LAB_0051c770;
    }
LAB_0051c76c:
    if (bVar14) goto LAB_0051c770;
  }
  this_01 = (TRIBE_Building_Object *)this->game_obj;
  if (*(char *)(this_01->_padding_ + 4) != 'P') goto LAB_0051c9cd;
  if ((uchar)this_01->_padding_ != this->save_object_state) {
    bVar14 = true;
    bVar4 = true;
    bVar15 = true;
  }
  _progress = this_01;
  if ((!bVar14) || (!bVar4)) {
    sVar6 = TRIBE_Building_Object::get_construction_progress(this_01);
    _work_type = (float)(int)sVar6;
    if ((float)(int)_work_type != this->save_build_pts) {
      bVar14 = true;
      bVar15 = true;
      if (_DAT_00576db8 < (float)(int)_work_type) {
        bVar4 = true;
      }
    }
  }
  if ((!bVar14) || (this_01 = _progress, !bVar4)) {
    TRIBE_Building_Object::work_status
              (this_01,(short *)&bldg_obj,(short *)&cur_fval,(short *)&orig_fval,name + 4,100);
    if (((short)bldg_obj != 0x67) &&
       (((short)bldg_obj != 0x66 &&
        (iVar13 = TRIBE_Building_Object::production_queue_status
                            (this_01,(short *)&cur_fval,&work_type), iVar13 != 0)))) {
      bldg_obj = (TRIBE_Building_Object *)0x66;
      orig_fval = _work_type;
    }
    if ((((short)bldg_obj == this->save_work_type) && (cur_fval._0_2_ == this->save_work_target)) &&
       (orig_fval._0_2_ == this->save_progress)) {
      pcVar12 = this->save_name;
      pbVar10 = (byte *)(name + 4);
      do {
        bVar1 = *pbVar10;
        bVar14 = bVar1 < (byte)*pcVar12;
        if (bVar1 != *pcVar12) {
LAB_0051c8bd:
          iVar13 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_0051c8c2;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar10[1];
        bVar14 = bVar1 < (byte)pcVar12[1];
        if (bVar1 != pcVar12[1]) goto LAB_0051c8bd;
        pbVar10 = pbVar10 + 2;
        pcVar12 = pcVar12 + 2;
      } while (bVar1 != 0);
      iVar13 = 0;
LAB_0051c8c2:
      bVar14 = bVar15;
      if (iVar13 == 0) goto LAB_0051c923;
    }
    bVar14 = true;
    if (((short)bldg_obj == this->save_work_type) && (cur_fval._0_2_ == this->save_work_target)) {
      pcVar12 = this->save_name;
      pbVar10 = (byte *)(name + 4);
      do {
        bVar1 = *pbVar10;
        bVar15 = bVar1 < (byte)*pcVar12;
        if (bVar1 != *pcVar12) {
LAB_0051c90c:
          iVar13 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
          goto LAB_0051c911;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar10[1];
        bVar15 = bVar1 < (byte)pcVar12[1];
        if (bVar1 != pcVar12[1]) goto LAB_0051c90c;
        pbVar10 = pbVar10 + 2;
        pcVar12 = pcVar12 + 2;
      } while (bVar1 != 0);
      iVar13 = 0;
LAB_0051c911:
      if (iVar13 == 0) goto LAB_0051c923;
    }
    bVar4 = true;
  }
LAB_0051c923:
  if (((!bVar14) || (!bVar4)) &&
     ((this->game_obj->master_obj->id == 0x46 &&
      ((iVar13 = __ftol(), iVar13 != this->save_pop ||
       (iVar13 = __ftol(), iVar13 != this->save_max_pop)))))) {
    bVar14 = true;
  }
  if (((((!bVar14) || (!bVar4)) && ((TRIBE_Player *)this->game_obj->owner == this->player)) &&
      ((this->game_obj->master_obj->id == 0x32 &&
       (pRVar11 = RGE_Action_List::get_action((RGE_Action_List *)_progress->_padding_),
       pRVar11 != (RGE_Action *)0x0)))) && (iVar13 = __ftol(), this->save_farm_amt != iVar13)) {
    bVar14 = true;
  }
LAB_0051c9cd:
  if (bVar14) {
    if (this->_padding_ == 0) {
      (**(code **)(this->_padding_ + 0x20))(1);
    }
    save_object_info(this);
    if (bVar4) {
      (**(code **)(*(int *)this->_padding_ + 0xb4))(this,1,0,0);
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: save_object_info
// Address: 0051ca10
/* WARNING: Variable defined which should be unmapped: orig_val */
/* protected: void __thiscall TRIBE_Panel_Object::save_object_info(void) */

void __thiscall TRIBE_Panel_Object::save_object_info(TRIBE_Panel_Object *this)
{
  short *psVar1;
  byte bVar2;
  RGE_Action_Object *this_00;
  TRIBE_Building_Object *this_01;
  TRIBE_Player *pTVar3;
  uchar uVar4;
  short sVar5;
  int iVar6;
  long lVar7;
  RGE_Action *pRVar8;
  int iVar9;
  short orig_val;
  short temp;
  float orig_fval;
  int iStack_4;
  
  if (this->mode == '\x02') {
    iVar9 = 1;
    do {
      iVar6 = RGE_Base_Game::playerID(rge_base_game,iVar9);
      if ((iVar6 != 0) && (iVar6 < rge_base_game->world->player_num)) {
        lVar7 = RGE_Victory_Conditions::get_victory_points
                          (rge_base_game->world->players[iVar6]->victory_conditions);
        this->save_score[iVar6] = lVar7;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 9);
    return;
  }
  this_00 = (RGE_Action_Object *)this->game_obj;
  if (this_00 != (RGE_Action_Object *)0x0) {
    this->save_selected_group = *(uchar *)((int)&this_00->_padding_ + 3);
    this->save_obj_type = (RGE_Master_Static_Object *)this_00->_padding_;
    this->save_attr_type = (short)this_00->_padding_;
    this->save_attr_amount = (float)this_00->_padding_;
    this->save_hp = (float)this_00->_padding_;
    this->save_list = *(RGE_Object_Node **)(this_00->_padding_ + 4);
    this->save_number_of_objects = *(short *)(this_00->_padding_ + 8);
    this->save_los = *(float *)(this_00->_padding_ + 0x28);
    this->save_owner = (RGE_Player *)this_00->_padding_;
    bVar2 = *(byte *)(this_00->_padding_ + 4);
    if ((0x45 < bVar2) && (bVar2 != 0x5a)) {
      uVar4 = RGE_Action_Object::have_action(this_00);
      this->save_have_action = uVar4;
      (**(code **)(this->game_obj->_padding_ + 0x22c))();
      (**(code **)(this->game_obj->_padding_ + 0x22c))(&this->save_pierce_armor);
      (**(code **)(this->game_obj->_padding_ + 0x230))(&this->save_weapon,&stack0xffffffe4);
      (**(code **)(this->game_obj->_padding_ + 0x234))(&this->save_weapon_range,&stack0xffffffe0);
      (**(code **)(this->game_obj->_padding_ + 0x238))(&this->save_speed_of_attack,&stack0xffffffd8)
      ;
    }
    this_01 = (TRIBE_Building_Object *)this->game_obj;
    if (*(char *)(this_01->_padding_ + 4) == 'P') {
      this->save_object_state = (uchar)this_01->_padding_;
      sVar5 = TRIBE_Building_Object::get_construction_progress(this_01);
      iStack_4 = (int)sVar5;
      this->save_build_pts = (float)iStack_4;
      psVar1 = &this->save_work_type;
      TRIBE_Building_Object::work_status
                (this_01,psVar1,&this->save_work_target,&this->save_progress,this->save_name,100);
      if ((*psVar1 != 0x67) && (*psVar1 != 0x66)) {
        iVar9 = TRIBE_Building_Object::production_queue_status
                          (this_01,&this->save_work_target,(short *)((int)&orig_fval + 2));
        if (iVar9 != 0) {
                    /* language.dll match for 0x66: "Copperplate Gothic Light" */
          *psVar1 = 0x66;
          this->save_progress = orig_fval._2_2_;
        }
      }
      pTVar3 = this->player;
      iVar9 = __ftol();
      this->save_pop = iVar9;
      iVar9 = __ftol();
      this->save_max_pop = iVar9;
      if (((TRIBE_Player *)this->game_obj->owner == pTVar3) &&
         (this->game_obj->master_obj->id == 0x32)) {
        pRVar8 = RGE_Action_List::get_action((RGE_Action_List *)this_01->_padding_);
        if (pRVar8 != (RGE_Action *)0x0) {
          iVar9 = __ftol();
          this->save_farm_amt = iVar9;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: mouse_left_down_action
// Address: 0051cc80
/* public: virtual long __thiscall TRIBE_Panel_Object::mouse_left_down_action(long,long,int,int) */

long __thiscall
TRIBE_Panel_Object::mouse_left_down_action
          (TRIBE_Panel_Object *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------

// Function: mouse_left_up_action
// Address: 0051cc90
/* public: virtual long __thiscall TRIBE_Panel_Object::mouse_left_up_action(long,long,int,int) */

long __thiscall
TRIBE_Panel_Object::mouse_left_up_action
          (TRIBE_Panel_Object *this,long param_1,long param_2,int param_3,int param_4)
{
  return 0;
}

// --------------------------------------------------


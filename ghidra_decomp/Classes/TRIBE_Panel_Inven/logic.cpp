// Class: TRIBE_Panel_Inven
// Function: TRIBE_Panel_Inven
// Address: 0051a5c0
/* public: __thiscall TRIBE_Panel_Inven::TRIBE_Panel_Inven(class TDrawArea *,class TPanel *,void
   *,class TRIBE_Player *) */

TRIBE_Panel_Inven * __thiscall
TRIBE_Panel_Inven::TRIBE_Panel_Inven
          (TRIBE_Panel_Inven *this,TDrawArea *param_1,TPanel *param_2,void *param_3,
          TRIBE_Player *param_4)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561318;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TPanel::TPanel((TPanel *)this);
  this->font = param_3;
  local_4 = 0;
  this->save_attr_num = 0;
  this->save_attr = (short *)0x0;
  this->pics = (TShape *)0x0;
  this->idle_time = 0;
  this->player = (TRIBE_Player *)0x0;
  this->back_color = 0;
  this->_padding_ = (int)&_vftable_;
  this->idle_interval = 500;
  this->font_color = 0xffffff;
  lVar1 = TPanel::setup((TPanel *)this,param_1,param_2,0,0,0,0,'\0');
  if (lVar1 == 0) {
    this->_padding_ = 1;
    *unaff_FS_OFFSET = local_c;
    return this;
  }
  set_player(this,param_4);
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0051a690
/* public: virtual void * __thiscall TRIBE_Panel_Inven::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
TRIBE_Panel_Inven::_scalar_deleting_destructor_(TRIBE_Panel_Inven *this,uint param_1)
{
  ~TRIBE_Panel_Inven(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: set_text_color
// Address: 0051a6b0
/* public: void __thiscall TRIBE_Panel_Inven::set_text_color(unsigned long,unsigned long) */

void __thiscall
TRIBE_Panel_Inven::set_text_color(TRIBE_Panel_Inven *this,ulong param_1,ulong param_2)
{
  this->font_color = param_1;
  this->back_color = param_2;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: ~TRIBE_Panel_Inven
// Address: 0051a6d0
/* public: virtual __thiscall TRIBE_Panel_Inven::~TRIBE_Panel_Inven(void) */

void __thiscall TRIBE_Panel_Inven::~TRIBE_Panel_Inven(TRIBE_Panel_Inven *this)
{
  TShape *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00561338;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  if (this->save_attr != (short *)0x0) {
    free(this->save_attr);
    this->save_attr = (short *)0x0;
  }
  this_00 = this->pics;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
    this->pics = (TShape *)0x0;
  }
  TPanel::~TPanel((TPanel *)this);
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0051a770
// [HELPER] s__ld: "%ld"
// [HELPER] s_tpnl_inv__draw: "tpnl_inv::draw"
/* WARNING: Variable defined which should be unmapped: x */
/* public: virtual void __thiscall TRIBE_Panel_Inven::draw(void) */

void __thiscall TRIBE_Panel_Inven::draw(TRIBE_Panel_Inven *this)
{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  long x;
  void *old_font;
  int iStack_1c;
  char str [20];
  
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0x34))(&this->_padding_);
    }
    if (this->player != (TRIBE_Player *)0x0) {
      iVar9 = this->_padding_;
      str._0_4_ = iVar9;
      (**(code **)(iVar9 + 0x28))(0);
      pvVar3 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_tpnl_inv__draw);
      if (pvVar3 != (void *)0x0) {
        uVar4 = SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
        SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
        iVar2 = this->_padding_;
        iVar9 = this->_padding_;
        iVar7 = iVar9 + 2;
        uVar5 = __ftol();
        sprintf(str,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->back_color);
        uVar6 = 0xffffffff;
        iVar9 = iVar9 + 3;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0x1f,iVar9,str,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->font_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0x20,iVar7,str,~uVar6 - 1);
        iVar2 = this->_padding_;
        uVar5 = __ftol();
        sprintf(str,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->back_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0x62,iVar9,str,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->font_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 99,iVar7,str,~uVar6 - 1);
        iVar2 = this->_padding_;
        uVar5 = __ftol();
        sprintf(str,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->back_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0xa5,iVar9,str,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->font_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0xa6,iVar7,str,~uVar6 - 1);
        iVar2 = this->_padding_;
        uVar5 = __ftol();
        sprintf(str,s__ld,uVar5);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->back_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0xe8,iVar9,str,~uVar6 - 1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),this->font_color);
        uVar6 = 0xffffffff;
        pcVar8 = str;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),iVar2 + 0xe9,iVar7,str,~uVar6 - 1);
        SelectObject(*(undefined4 *)(this->_padding_ + 0x38),uVar4);
        TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_tpnl_inv__draw);
        iVar9 = iStack_1c;
      }
      (**(code **)(iVar9 + 0x2c))();
      return;
    }
  }
  this->_padding_ = 0;
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0051aad0
// [HELPER] s_C__msdev_work_age1_x1_tpnl_inv_c: "C:\msdev\work\age1_x1\tpnl_inv.cpp"
/* WARNING: Variable defined which should be unmapped: changed */
/* public: virtual long __thiscall TRIBE_Panel_Inven::handle_idle(void) */

long __thiscall TRIBE_Panel_Inven::handle_idle(TRIBE_Panel_Inven *this)
{
  int iVar1;
  short *psVar2;
  bool bVar3;
  short sVar4;
  ulong uVar5;
  short sVar6;
  int changed;
  
  TPanel::handle_idle((TPanel *)this);
  iVar1 = rge_base_game->prog_mode;
  if (((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) &&
     (uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_tpnl_inv_c,0xad),
     this->idle_interval <= uVar5 - this->idle_time)) {
    color_log(0xba,0xba,5);
    sVar6 = 0;
    bVar3 = false;
    if (0 < this->save_attr_num) {
      psVar2 = this->save_attr;
      do {
        sVar4 = __ftol();
        if (sVar4 != psVar2[sVar6]) {
          bVar3 = true;
          break;
        }
        sVar6 = sVar6 + 1;
      } while (sVar6 < this->save_attr_num);
    }
    if (bVar3) {
      color_log(0xba,'\x16',5);
      save_info(this);
      (**(code **)(this->_padding_ + 0x20))(1);
    }
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_tpnl_inv_c,0xc2);
    this->idle_time = uVar5;
    color_log(0xba,'_',5);
  }
  return 0;
}

// --------------------------------------------------

// Function: set_player
// Address: 0051abf0
/* public: void __thiscall TRIBE_Panel_Inven::set_player(class TRIBE_Player *) */

void __thiscall TRIBE_Panel_Inven::set_player(TRIBE_Panel_Inven *this,TRIBE_Player *param_1)
{
  this->player = param_1;
  save_info(this);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: save_info
// Address: 0051ac10
/* protected: void __thiscall TRIBE_Panel_Inven::save_info(void) */

void __thiscall TRIBE_Panel_Inven::save_info(TRIBE_Panel_Inven *this)
{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  psVar2 = this->save_attr;
  if (psVar2 != (short *)0x0) {
    if (this->save_attr_num == (short)this->player->_padding_) goto LAB_0051ac6b;
    if (psVar2 != (short *)0x0) {
      free(psVar2);
      this->save_attr = (short *)0x0;
    }
  }
  sVar1 = (short)this->player->_padding_;
  this->save_attr_num = sVar1;
  psVar2 = (short *)calloc((int)sVar1,2);
  this->save_attr = psVar2;
LAB_0051ac6b:
  iVar3 = 0;
  if (0 < this->save_attr_num) {
    do {
      sVar1 = __ftol();
      iVar4 = iVar3 + 1;
      this->save_attr[iVar3] = sVar1;
      iVar3 = iVar4;
    } while (iVar4 < this->save_attr_num);
  }
  return;
}

// --------------------------------------------------

// Function: get_help_info
// Address: 0051aca0
/* public: virtual unsigned char __thiscall TRIBE_Panel_Inven::get_help_info(char * &,long
   &,long,long) */

uchar __thiscall
TRIBE_Panel_Inven::get_help_info
          (TRIBE_Panel_Inven *this,char **param_1,long *param_2,long param_3,long param_4)
{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *unaff_ESI;
  undefined4 *unaff_retaddr;
  
  if (this->_padding_ == 0) {
    return '\0';
  }
  iVar1 = (**(code **)(this->_padding_ + 0xbc))(param_3,param_4);
  if (iVar1 == 0) {
    return '\0';
  }
  iVar1 = this->_padding_;
  if (param_3 < iVar1 + 0x37) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string((TPanel *)this,0x1d4ee);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return '\x01';
  }
  if (param_3 < iVar1 + 0x6e) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string((TPanel *)this,0x1d4ed);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return '\x01';
  }
  if (param_3 < iVar1 + 0xa5) {
    uVar2 = __ftol();
    pcVar3 = TPanel::get_string((TPanel *)this,0x1d4ef);
    sprintf(*unaff_ESI,pcVar3,uVar2);
    *unaff_retaddr = 0xffffffff;
    return '\x01';
  }
  uVar2 = __ftol();
  pcVar3 = TPanel::get_string((TPanel *)this,0x1d4f0);
  sprintf(*unaff_ESI,pcVar3,uVar2);
  *unaff_retaddr = 0xffffffff;
  return '\x01';
}

// --------------------------------------------------


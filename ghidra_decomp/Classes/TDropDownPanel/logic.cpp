// Class: TDropDownPanel
// Function: TDropDownPanel
// Address: 00473ed0
/* public: __thiscall TDropDownPanel::TDropDownPanel(void) */

TDropDownPanel * __thiscall TDropDownPanel::TDropDownPanel(TDropDownPanel *this)
{
  TPanel::TPanel((TPanel *)this);
  this->_padding_ = (int)&_vftable_;
  this->val_panel = (TTextPanel *)0x0;
  this->btn_panel = (TButtonPanel *)0x0;
  this->list_panel = (TListPanel *)0x0;
  this->scbar_panel = (TScrollBarPanel *)0x0;
  this->mode = ModeNone;
  this->val_num = 0;
  this->list_is_above = '\0';
  this->draw_style = DrawStyleNormal;
  *(undefined1 *)((int)&this->_padding_ + 2) = 6;
  this->draw_val_rect = 1;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00473f30
/* public: virtual void * __thiscall TDropDownPanel::`scalar deleting destructor'(unsigned int) */

void * __thiscall TDropDownPanel::_scalar_deleting_destructor_(TDropDownPanel *this,uint param_1)
{
  ~TDropDownPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TDropDownPanel
// Address: 00473f50
/* public: virtual __thiscall TDropDownPanel::~TDropDownPanel(void) */

void __thiscall TDropDownPanel::~TDropDownPanel(TDropDownPanel *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055e408;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->btn_panel);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->list_panel);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->scbar_panel);
  TPanel::delete_panel((TPanel *)this,(TPanel **)&this->val_panel);
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 00473fd0
// [HELPER] s_: ""
/* public: long __thiscall TDropDownPanel::setup(class TDrawArea *,class TPanel *,void
   *,long,long,int,unsigned char,int,unsigned char,long,long,long,long,short,short,long,long,char
   *,long,long,char * *,short,long,char *,char *,char *,char *,long,long) */

long __thiscall
TDropDownPanel::setup
          (TDropDownPanel *this,TDrawArea *param_1,TPanel *param_2,void *param_3,long param_4,
          long param_5,int param_6,uchar param_7,int param_8,uchar param_9,long param_10,
          long param_11,long param_12,long param_13,short param_14,short param_15,long param_16,
          long param_17,char *param_18,long param_19,long param_20,char **param_21,short param_22,
          long param_23,char *param_24,char *param_25,char *param_26,char *param_27,long param_28,
          long param_29)
{
  TTextPanel *this_00;
  TButtonPanel *this_01;
  TDropDownButtonPanel *this_02;
  TListPanel *this_03;
  TScrollBarPanel *this_04;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e44c;
  *unaff_FS_OFFSET = &local_c;
  this->val_num = param_15;
  this->btn_wid = param_16;
  this->btn_hgt = param_17;
  this->list_wid = param_19;
  this->list_hgt = param_20;
  this->scbar_wid = param_23;
  this->scbar_arrow_hgt = param_28;
  this->scbar_tab_hgt = param_29;
  this->val_wid = (param_12 - param_16) + -1;
  this->val_hgt = param_13;
  this->outline_color = (uint)param_9;
  this->font_hgt = param_5;
  TPanel::setup((TPanel *)this,param_1,param_2,param_10,param_11,param_12,param_13,'\0');
  this_00 = (TTextPanel *)operator_new(0x188);
  local_4 = 0;
  if (this_00 == (TTextPanel *)0x0) {
    this_01 = (TButtonPanel *)0x0;
  }
  else {
    this_01 = (TButtonPanel *)TTextPanel::TTextPanel(this_00);
  }
  local_4 = 0xffffffff;
  this->val_panel = (TTextPanel *)this_01;
  if (this_01 != (TButtonPanel *)0x0) {
    this_01 = (TButtonPanel *)
              TTextPanel::setup((TTextPanel *)this_01,param_1,(TPanel *)this,0,0,this->val_wid,
                                this->val_hgt,param_3,param_4,param_5,(char *)0x0,param_6,param_7,
                                param_8,param_9,param_14,param_21[this->val_num]);
    if (this_01 != (TButtonPanel *)0x0) {
      TTextPanel::set_alignment(this->val_panel,AlignCenter,AlignLeft);
      this_02 = (TDropDownButtonPanel *)operator_new(700);
      local_4 = 1;
      if (this_02 == (TDropDownButtonPanel *)0x0) {
        this_01 = (TButtonPanel *)0x0;
      }
      else {
        this_01 = (TButtonPanel *)TDropDownButtonPanel::TDropDownButtonPanel(this_02,this);
      }
      local_4 = 0xffffffff;
      this->btn_panel = this_01;
      if (this_01 != (TButtonPanel *)0x0) {
        this_01 = (TButtonPanel *)
                  TButtonPanel::setup(this_01,param_1,(TPanel *)this,0,0,this->btn_wid,this->btn_hgt
                                      ,DrawBevelPicture,(TDigital *)0x0,NotifyAction,0);
        if (this_01 != (TButtonPanel *)0x0) {
          this_03 = (TListPanel *)operator_new(0x1a0);
          local_4 = 2;
          if (this_03 == (TListPanel *)0x0) {
            this_01 = (TButtonPanel *)0x0;
          }
          else {
            this_01 = (TButtonPanel *)TListPanel::TListPanel(this_03);
          }
          local_4 = 0xffffffff;
          this->list_panel = (TListPanel *)this_01;
          if (this_01 != (TButtonPanel *)0x0) {
            this_01 = (TButtonPanel *)
                      TTextPanel::setup((TTextPanel *)this_01,param_1,(TPanel *)this,0,0,
                                        this->list_wid,this->list_hgt,param_3,param_4,param_5,
                                        (char *)0x0,param_6,param_7,param_8,param_9,param_14,
                                        param_21,param_22);
            if (this_01 != (TButtonPanel *)0x0) {
              TListPanel::set_auto_track(this->list_panel,1);
              (**(code **)(this->list_panel->_padding_ + 0x14))(0);
              TTextPanel::setCurrentLineNumber((TTextPanel *)this->list_panel,(int)this->val_num);
              this_04 = (TScrollBarPanel *)operator_new(0x1c4);
              local_4 = 3;
              if (this_04 == (TScrollBarPanel *)0x0) {
                this_01 = (TButtonPanel *)0x0;
              }
              else {
                this_01 = (TButtonPanel *)TScrollBarPanel::TScrollBarPanel(this_04);
              }
              local_4 = 0xffffffff;
              this->scbar_panel = (TScrollBarPanel *)this_01;
              if (this_01 != (TButtonPanel *)0x0) {
                this_01 = (TButtonPanel *)
                          TScrollBarPanel::setup
                                    ((TScrollBarPanel *)this_01,(TDrawArea *)this->_padding_,
                                     (TPanel *)this,0,0,this->scbar_wid,this->list_hgt,s_,s_,s_,s_,
                                     this->scbar_arrow_hgt,this->scbar_tab_hgt,
                                     (TPanel *)this->list_panel,(int)param_22,Vertical);
                if (this_01 != (TButtonPanel *)0x0) {
                  TTextPanel::set_scrollbar((TTextPanel *)this->list_panel,this->scbar_panel,0);
                  (**(code **)(this->scbar_panel->_padding_ + 0x14))(0);
                  set_mode(this,ModeValue);
                  this_01 = (TButtonPanel *)0x1;
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return (long)this_01;
}

// --------------------------------------------------

// Function: draw
// Address: 00474340
/* public: virtual void __thiscall TDropDownPanel::draw(void) */

void __thiscall TDropDownPanel::draw(TDropDownPanel *this)
{
  int iVar1;
  
  this->_padding_ = 0;
  if ((((TDrawArea *)this->_padding_ != (TDrawArea *)0x0) && (this->_padding_ != 0)) &&
     (this->_padding_ != 0)) {
    if (((char)this->_padding_ == '\0') && ((int *)this->_padding_ != (int *)0x0)) {
      iVar1 = *(int *)this->_padding_;
      if (*(char *)((int)&this->_padding_ + 2) != '\0') {
        (**(code **)(iVar1 + 0x3c))(&this->_padding_);
        return;
      }
      (**(code **)(iVar1 + 0x34))(&this->_padding_);
      return;
    }
    TDrawArea::Clear((TDrawArea *)this->_padding_,(tagRECT *)&this->_padding_,
                     (uint)*(byte *)((int)&this->_padding_ + 3));
  }
  return;
}

// --------------------------------------------------

// Function: handle_mouse_down
// Address: 00474350
/* public: virtual long __thiscall TDropDownPanel::handle_mouse_down(unsigned
   char,long,long,int,int) */

long __thiscall
TDropDownPanel::handle_mouse_down
          (TDropDownPanel *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  long lVar3;
  
  if ((this->_padding_ != 0) && ((TPanel *)this->_padding_ != (TPanel *)0x0)) {
    TPanel::set_curr_child((TPanel *)this->_padding_,(TPanel *)this);
  }
  if (this->mode == ModeList) {
    iVar1 = (**(code **)(this->list_panel->_padding_ + 0xbc))(param_2,param_3);
    if (this->scbar_panel == (TScrollBarPanel *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (**(code **)(this->scbar_panel->_padding_ + 0xbc))(param_2,param_3);
    }
    if ((iVar1 == 0) && (iVar2 == 0)) {
      set_mode(this,ModeValue);
      set_line(this,(int)this->val_num);
      return 1;
    }
  }
  lVar3 = TPanel::handle_mouse_down((TPanel *)this,param_1,param_2,param_3,param_4,param_5);
  return lVar3;
}

// --------------------------------------------------

// Function: handle_mouse_move
// Address: 00474400
/* public: virtual long __thiscall TDropDownPanel::handle_mouse_move(long,long,int,int) */

long __thiscall
TDropDownPanel::handle_mouse_move
          (TDropDownPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  long lVar1;
  
  lVar1 = TPanel::handle_mouse_move((TPanel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: handle_mouse_up
// Address: 00474420
/* public: virtual long __thiscall TDropDownPanel::handle_mouse_up(unsigned char,long,long,int,int)
    */

long __thiscall
TDropDownPanel::handle_mouse_up
          (TDropDownPanel *this,uchar param_1,long param_2,long param_3,int param_4,int param_5)
{
  long lVar1;
  
  lVar1 = TPanel::handle_mouse_up((TPanel *)this,param_1,param_2,param_3,param_4,param_5);
  return lVar1;
}

// --------------------------------------------------

// Function: handle_key_down
// Address: 00474450
/* public: virtual long __thiscall TDropDownPanel::handle_key_down(long,short,int,int,int) */

long __thiscall
TDropDownPanel::handle_key_down
          (TDropDownPanel *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  long lVar1;
  
  if ((this->_padding_ != 0) &&
     (((param_1 == 0x28 || (param_1 == 0x26)) && (this->mode == ModeValue)))) {
    set_mode(this,ModeList);
    return 1;
  }
  lVar1 = TPanel::handle_key_down((TPanel *)this,param_1,param_2,param_3,param_4,param_5);
  return lVar1;
}

// --------------------------------------------------

// Function: action
// Address: 004744a0
/* public: virtual long __thiscall TDropDownPanel::action(class TPanel *,long,unsigned long,unsigned
   long) */

long __thiscall
TDropDownPanel::action
          (TDropDownPanel *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  if ((TButtonPanel *)param_1 == this->btn_panel) {
    if ((param_2 == 2) && (this->mode == ModeValue)) {
      set_mode(this,ModeList);
    }
  }
  else if (((TListPanel *)param_1 == this->list_panel) && ((param_2 == 3 || (param_2 == 2)))) {
    this->val_num = (short)param_3;
    iVar1 = this->val_panel->_padding_;
    pcVar2 = TTextPanel::get_text((TTextPanel *)this->list_panel,(int)(short)param_3);
    (**(code **)(iVar1 + 0xe8))(pcVar2);
    set_mode(this,ModeValue);
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0xb4))(this,0,0,0);
    }
  }
  lVar3 = TPanel::action((TPanel *)this,param_1,param_2,param_3,param_4);
  return lVar3;
}

// --------------------------------------------------

// Function: set_rect
// Address: 00474550
/* public: virtual void __thiscall TDropDownPanel::set_rect(long,long,long,long) */

void __thiscall
TDropDownPanel::set_rect(TDropDownPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  TPanel::set_rect((TPanel *)this,param_1,param_2,param_3,param_4);
  if (this->mode == ModeValue) {
    this->val_wid = (this->_padding_ - this->btn_wid) + -1;
    this->val_hgt = this->_padding_;
    set_mode(this,ModeNone);
    set_mode(this,ModeValue);
    return;
  }
  if (this->mode == ModeList) {
    this->list_wid = this->_padding_;
    this->list_hgt = (this->_padding_ - this->val_hgt) + -1;
    set_mode(this,ModeValue);
    set_mode(this,ModeList);
  }
  return;
}

// --------------------------------------------------

// Function: set_val_text_color
// Address: 004745e0
/* public: void __thiscall TDropDownPanel::set_val_text_color(unsigned long,unsigned long) */

void __thiscall TDropDownPanel::set_val_text_color(TDropDownPanel *this,ulong param_1,ulong param_2)
{
  if (this->val_panel != (TTextPanel *)0x0) {
    TTextPanel::set_text_color(this->val_panel,param_1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: set_draw_style
// Address: 00474600
/* public: void __thiscall TDropDownPanel::set_draw_style(enum TDropDownPanel::DrawStyle) */

void __thiscall TDropDownPanel::set_draw_style(TDropDownPanel *this,DrawStyle param_1)
{
  DropdownMode DVar1;
  
  this->draw_style = param_1;
  if (this->val_panel != (TTextPanel *)0x0) {
    DVar1 = this->mode;
    this->mode = ModeNone;
    set_mode(this,DVar1);
  }
  return;
}

// --------------------------------------------------

// Function: set_draw_val_rect
// Address: 00474630
/* public: void __thiscall TDropDownPanel::set_draw_val_rect(int) */

void __thiscall TDropDownPanel::set_draw_val_rect(TDropDownPanel *this,int param_1)
{
  this->draw_val_rect = param_1;
  if (this->val_panel != (TTextPanel *)0x0) {
    TTextPanel::set_outline(this->val_panel,param_1,(uchar)this->outline_color);
    (**(code **)(this->_padding_ + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: set_bevel_info
// Address: 00474670
/* public: void __thiscall TDropDownPanel::set_bevel_info(int,int,int,int,int,int,int) */

void __thiscall
TDropDownPanel::set_bevel_info
          (TDropDownPanel *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6,int param_7)
{
  undefined4 uVar1;
  int iVar2;
  
  if (this->val_panel != (TTextPanel *)0x0) {
    switch(param_1) {
    case 1:
      uVar1 = 1;
      break;
    case 2:
      uVar1 = 5;
      break;
    case 3:
      uVar1 = 6;
      break;
    case 4:
      uVar1 = 7;
      break;
    default:
      uVar1 = 0;
    }
    (**(code **)(this->val_panel->_padding_ + 0xec))
              (uVar1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  if (this->list_panel != (TListPanel *)0x0) {
    switch(param_1) {
    case 1:
      uVar1 = 1;
      break;
    case 2:
      uVar1 = 2;
      break;
    case 3:
      uVar1 = 3;
      break;
    case 4:
      uVar1 = 4;
      break;
    default:
      uVar1 = 0;
    }
    (**(code **)(this->list_panel->_padding_ + 0xec))
              (uVar1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  if (this->scbar_panel != (TScrollBarPanel *)0x0) {
    switch(param_1) {
    case 1:
      iVar2 = 1;
      break;
    case 2:
      iVar2 = 2;
      break;
    case 3:
      iVar2 = 3;
      break;
    case 4:
      iVar2 = 4;
      break;
    default:
      iVar2 = 0;
    }
    TScrollBarPanel::set_bevel_info
              (this->scbar_panel,iVar2,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  if (this->btn_panel != (TButtonPanel *)0x0) {
    switch(param_1) {
    case 1:
      iVar2 = 1;
      break;
    case 2:
      iVar2 = 2;
      break;
    case 3:
      iVar2 = 3;
      break;
    case 4:
      iVar2 = 4;
      break;
    default:
      iVar2 = 0;
    }
    TButtonPanel::set_bevel_info
              (this->btn_panel,iVar2,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}

// --------------------------------------------------

// Function: set_buttons
// Address: 00474820
/* public: void __thiscall TDropDownPanel::set_buttons(class TShape *,int,int,int,int,int) */

void __thiscall
TDropDownPanel::set_buttons
          (TDropDownPanel *this,TShape *param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  TShape *pTVar1;
  
  if (this->btn_panel != (TButtonPanel *)0x0) {
    pTVar1 = param_1;
    if (param_1 == (TShape *)0x0) {
      param_2._0_2_ = -1;
      pTVar1 = (TShape *)0x0;
    }
    TButtonPanel::set_picture(this->btn_panel,0,pTVar1,(short)param_2);
  }
  if (this->scbar_panel != (TScrollBarPanel *)0x0) {
    TScrollBarPanel::set_buttons(this->scbar_panel,param_1,param_3,param_4,param_5,param_6);
  }
  return;
}

// --------------------------------------------------

// Function: set_mode
// Address: 00474880
/* WARNING: Variable defined which should be unmapped: parent_y */
/* public: void __thiscall TDropDownPanel::set_mode(enum TDropDownPanel::DropdownMode) */

void __thiscall TDropDownPanel::set_mode(TDropDownPanel *this,DropdownMode param_1)
{
  uchar uVar1;
  DropdownMode DVar2;
  int *piVar3;
  TListPanel *pTVar4;
  code *pcVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  int iVar10;
  int iVar11;
  TButtonPanel *pTVar12;
  code *pcVar13;
  undefined4 uVar14;
  code *pcVar15;
  int iVar16;
  int iVar17;
  long parent_y;
  long parent_x;
  DropdownMode save_mode;
  long calc_wid;
  
  if (param_1 != this->mode) {
    if ((TPanel *)this->_padding_ == (TPanel *)0x0) {
      save_mode = ModeNone;
      iVar7 = *(int *)(this->_padding_ + 0x18);
      iVar8 = *(int *)(this->_padding_ + 0x1c);
      lVar6 = 0;
    }
    else {
      save_mode = TPanel::xPosition((TPanel *)this->_padding_);
      lVar6 = TPanel::yPosition((TPanel *)this->_padding_);
      iVar7 = TPanel::width((TPanel *)this->_padding_);
      iVar8 = TPanel::height((TPanel *)this->_padding_);
    }
    DVar2 = this->mode;
    this->mode = ModeNone;
    if (param_1 == ModeValue) {
      if ((((DVar2 == ModeList) && (this->_padding_ != 0)) &&
          (piVar3 = *(int **)(this->_padding_ + 0x40), piVar3 != (int *)0x0)) &&
         (((this->_padding_ < (int)save_mode || (this->_padding_ < lVar6)) ||
          (((int)(iVar7 + -1 + save_mode) < this->_padding_ ||
           (iVar8 + -1 + lVar6 < this->_padding_)))))) {
        (**(code **)(*piVar3 + 0x20))(2);
      }
      (**(code **)(this->list_panel->_padding_ + 0x14))(0);
      (**(code **)(this->scbar_panel->_padding_ + 0x14))(0);
      if (this->draw_style == DrawStyleLeftButton) {
        (**(code **)(this->btn_panel->_padding_ + 0x18))
                  (7,0,0,1,0,this->btn_wid,this->btn_wid,this->btn_hgt,this->btn_hgt,0,0,0,0);
        lVar6 = this->val_hgt;
        lVar9 = this->val_wid;
        pTVar12 = this->btn_panel;
        iVar7 = this->val_panel->_padding_;
      }
      else {
        (**(code **)(this->val_panel->_padding_ + 0x18))
                  (7,0,0,1,0,this->val_wid,this->val_wid,this->val_hgt,this->val_hgt,0,0,0,0);
        lVar6 = this->btn_hgt;
        lVar9 = this->btn_wid;
        pTVar12 = (TButtonPanel *)this->val_panel;
        iVar7 = this->btn_panel->_padding_;
      }
      iVar17 = 0;
      (**(code **)(iVar7 + 0x18))(7,1,0,0,0,lVar9,lVar9,lVar6,lVar6,pTVar12,0,0,0);
      iVar7 = this->val_wid;
      iVar8 = this->btn_wid;
      uVar1 = this->list_is_above;
      iVar16 = this->_padding_;
      iVar10 = this->val_hgt;
      *(undefined1 *)((int)&this->_padding_ + 1) = 1;
      if (uVar1 == '\0') {
        (**(code **)(iVar16 + 0x1c))
                  (this->_padding_ - save_mode,this->_padding_ - iVar17,iVar7 + 1 + iVar8,iVar10);
      }
      else {
        (**(code **)(iVar16 + 0x1c))
                  (this->_padding_ - save_mode,
                   ((this->_padding_ + this->_padding_) - iVar10) - iVar17);
        this->list_is_above = '\0';
      }
      if ((int *)this->_padding_ == (int *)0x0) {
        (**(code **)(iVar16 + 0x20))(1);
      }
      else {
        (**(code **)(*(int *)this->_padding_ + 0x20))(1);
      }
      TPanel::set_curr_child((TPanel *)this,(TPanel *)this->val_panel);
      if (DVar2 == ModeList) {
        iVar7 = TPanelSystem::restorePreviousModalPanel(&panel_system);
        if (iVar7 == 0) {
          TPanelSystem::setModalPanel(&panel_system,(TPanel *)0x0);
        }
        if ((int *)this->_padding_ != (int *)0x0) {
          (**(code **)(*(int *)this->_padding_ + 0xb4))(this,2,0,0);
          this->mode = save_mode;
          return;
        }
      }
    }
    else if (param_1 == ModeList) {
      (**(code **)(this->list_panel->_padding_ + 0x14))(1);
      pTVar4 = this->list_panel;
      iVar7 = pTVar4->_padding_;
      if (iVar7 == 0) {
        iVar7 = pTVar4->_padding_;
        iVar8 = TTextPanel::numberLines((TTextPanel *)pTVar4);
        this->list_hgt = iVar8 * (this->font_hgt + 2) + iVar7 * 2;
      }
      else {
        iVar8 = pTVar4->_padding_;
        iVar16 = TTextPanel::numberLines((TTextPanel *)pTVar4);
        this->list_hgt = iVar16 * (this->font_hgt + 1 + iVar7 * 2) + iVar8 * 2;
      }
      (**(code **)(this->list_panel->_padding_ + 0x1c))(0,0,this->list_wid,this->list_hgt);
      iVar7 = TTextPanel::numberLines((TTextPanel *)this->list_panel);
      iVar8 = TTextPanel::numberDrawLines((TTextPanel *)this->list_panel);
      if (iVar8 < iVar7) {
        (**(code **)(this->scbar_panel->_padding_ + 0x14))(1);
      }
      else {
        (**(code **)(this->scbar_panel->_padding_ + 0x14))(0);
      }
      if (this->draw_style == DrawStyleLeftButton) {
        (**(code **)(this->btn_panel->_padding_ + 0x18))
                  (7,0,0,1,0,this->btn_wid,this->btn_wid,this->btn_hgt,this->btn_hgt,0,0,0,0);
        lVar6 = this->val_hgt;
        lVar9 = this->val_wid;
        pTVar12 = this->btn_panel;
        iVar7 = this->val_panel->_padding_;
      }
      else {
        (**(code **)(this->val_panel->_padding_ + 0x18))
                  (7,0,0,1,0,this->val_wid,this->val_wid,this->val_hgt,this->val_hgt,0,0,0,0);
        lVar6 = this->btn_hgt;
        lVar9 = this->btn_wid;
        pTVar12 = (TButtonPanel *)this->val_panel;
        iVar7 = this->btn_panel->_padding_;
      }
      (**(code **)(iVar7 + 0x18))(7,1,0,0,0,lVar9,lVar9,lVar6,lVar6,pTVar12,0,0,0);
      (**(code **)(this->scbar_panel->_padding_ + 0x18))
                (10,1,1,0,0,this->scbar_wid,this->scbar_wid,0,0,0,this->val_panel,0,0);
      iVar16 = 0;
      (**(code **)(this->list_panel->_padding_ + 0x18))
                (8,0,1,1,0,0,0,0,0,0,this->val_panel,this->scbar_panel,0);
      pcVar13 = (code *)this->list_wid;
      iVar7 = this->list_hgt + 1 + this->val_hgt;
      iVar16 = this->_padding_ - iVar16;
      pcVar5 = *(code **)(this->_padding_ + 0x1c);
      iVar8 = this->_padding_ - save_mode;
      *(undefined1 *)((int)&this->_padding_ + 1) = 0;
      pcVar15 = pcVar13;
      (*pcVar5)(iVar8,iVar16,pcVar13,iVar7);
      lVar6 = TPanel::yPosition((TPanel *)this->list_panel);
      lVar9 = TPanel::height((TPanel *)this->list_panel);
      if (*(int *)(this->_padding_ + 0x1c) + -4 < lVar6 + lVar9) {
        lVar6 = TPanel::yPosition((TPanel *)this->list_panel);
        lVar9 = TPanel::height((TPanel *)this->list_panel);
        iVar17 = lVar6 + lVar9 + (4 - *(int *)(this->_padding_ + 0x1c));
        lVar6 = TPanel::height((TPanel *)this->list_panel);
        iVar10 = lVar6 + (4 - this->_padding_);
        if (iVar10 < iVar17) {
          if (0 < iVar10) {
            iVar10 = this->list_hgt - iVar10;
            iVar7 = this->list_panel->_padding_;
            this->list_hgt = iVar10;
            (**(code **)(iVar7 + 0x1c))(0,0,this->list_wid,iVar10);
            pTVar4 = this->list_panel;
            iVar7 = pTVar4->_padding_;
            if (iVar7 == 0) {
              iVar7 = pTVar4->_padding_;
              iVar8 = TTextPanel::numberDrawLines((TTextPanel *)pTVar4);
              this->list_hgt = iVar8 * (this->font_hgt + 2) + iVar7 * 2;
            }
            else {
              iVar8 = pTVar4->_padding_;
              iVar16 = TTextPanel::numberDrawLines((TTextPanel *)pTVar4);
              this->list_hgt = iVar16 * (this->font_hgt + 1 + iVar7 * 2) + iVar8 * 2;
            }
            iVar7 = this->list_hgt + 1 + this->val_hgt;
            if (this->scbar_panel->_padding_ == 0) {
              (**(code **)(this->list_panel->_padding_ + 0x1c))(0,0,this->list_wid,this->list_hgt);
              iVar8 = TTextPanel::numberLines((TTextPanel *)this->list_panel);
              iVar16 = TTextPanel::numberDrawLines((TTextPanel *)this->list_panel);
              if (iVar16 < iVar8) {
                (**(code **)(this->scbar_panel->_padding_ + 0x14))(1);
              }
            }
          }
          if (this->draw_style == DrawStyleLeftButton) {
            (**(code **)(this->btn_panel->_padding_ + 0x18))
                      (8,0,0,1,0,this->btn_wid,this->btn_wid,this->btn_hgt,this->btn_hgt,0,0,0,0);
            lVar6 = this->val_hgt;
            lVar9 = this->val_wid;
            pTVar12 = this->btn_panel;
            iVar8 = this->val_panel->_padding_;
          }
          else {
            (**(code **)(this->val_panel->_padding_ + 0x18))
                      (8,0,0,1,0,this->val_wid,this->val_wid,this->val_hgt,this->val_hgt,0,0,0,0);
            lVar6 = this->btn_hgt;
            lVar9 = this->btn_wid;
            pTVar12 = (TButtonPanel *)this->val_panel;
            iVar8 = this->btn_panel->_padding_;
          }
          (**(code **)(iVar8 + 0x18))(8,1,0,0,0,lVar9,lVar9,lVar6,lVar6,pTVar12,0,0,0);
          (**(code **)(this->scbar_panel->_padding_ + 0x18))
                    (9,1,1,0,0,this->scbar_wid,this->scbar_wid,0,0,0,0,0,this->val_panel);
          uVar14 = 0;
          pcVar13 = (code *)0x0;
          iVar16 = 0;
          iVar8 = 0;
          (**(code **)(this->list_panel->_padding_ + 0x18))
                    (7,0,1,1,0,0,0,0,0,0,0,this->scbar_panel,this->val_panel);
          (*pcVar13)(this->_padding_ - iVar16,((this->val_hgt - iVar7) - iVar8) + this->_padding_,
                     uVar14,iVar7);
          this->list_is_above = '\x01';
        }
        else {
          iVar17 = this->list_hgt - iVar17;
          iVar7 = this->list_panel->_padding_;
          this->list_hgt = iVar17;
          (**(code **)(iVar7 + 0x1c))(0,0,this->list_wid,iVar17);
          pTVar4 = this->list_panel;
          iVar7 = pTVar4->_padding_;
          if (iVar7 == 0) {
            iVar7 = pTVar4->_padding_;
            iVar10 = TTextPanel::numberDrawLines((TTextPanel *)pTVar4);
            this->list_hgt = iVar10 * (this->font_hgt + 2) + iVar7 * 2;
          }
          else {
            iVar10 = pTVar4->_padding_;
            iVar17 = TTextPanel::numberDrawLines((TTextPanel *)pTVar4);
            this->list_hgt = iVar17 * (this->font_hgt + 1 + iVar7 * 2) + iVar10 * 2;
          }
          iVar7 = this->list_hgt;
          iVar10 = this->val_hgt;
          if (this->scbar_panel->_padding_ == 0) {
            (**(code **)(this->list_panel->_padding_ + 0x1c))(0,0,this->list_wid,iVar7);
            iVar17 = TTextPanel::numberLines((TTextPanel *)this->list_panel);
            iVar11 = TTextPanel::numberDrawLines((TTextPanel *)this->list_panel);
            if (iVar11 < iVar17) {
              (**(code **)(this->scbar_panel->_padding_ + 0x14))(1);
            }
            (**(code **)(this->list_panel->_padding_ + 0x18))
                      (8,0,1,1,0,0,0,0,0,0,this->val_panel,this->scbar_panel,0);
          }
          (*pcVar15)(this->_padding_ - iVar16,this->_padding_ - iVar8,pcVar13,iVar7 + 1 + iVar10);
        }
      }
      (**(code **)(this->_padding_ + 0x20))(1);
      TPanel::set_z_order((TPanel *)this,'\x01',0);
      TPanel::set_curr_child((TPanel *)this,(TPanel *)this->list_panel);
      TPanelSystem::setModalPanel(&panel_system,(TPanel *)this);
      if ((int *)this->_padding_ != (int *)0x0) {
        (**(code **)(*(int *)this->_padding_ + 0xb4))(this,1,0,0);
      }
    }
    this->mode = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: numberLines
// Address: 00475110
/* public: int __thiscall TDropDownPanel::numberLines(void) */

int __thiscall TDropDownPanel::numberLines(TDropDownPanel *this)
{
  int iVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    iVar1 = TTextPanel::numberLines((TTextPanel *)this->list_panel);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: currentLineNumber
// Address: 00475130
/* public: int __thiscall TDropDownPanel::currentLineNumber(void) */

int __thiscall TDropDownPanel::currentLineNumber(TDropDownPanel *this)
{
  int iVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    iVar1 = TTextPanel::currentLineNumber((TTextPanel *)this->list_panel);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: setCurrentLineNumber
// Address: 00475150
/* public: void __thiscall TDropDownPanel::setCurrentLineNumber(int) */

void __thiscall TDropDownPanel::setCurrentLineNumber(TDropDownPanel *this,int param_1)
{
  set_line(this,param_1);
  return;
}

// --------------------------------------------------

// Function: setCurrentLineId
// Address: 00475160
/* public: void __thiscall TDropDownPanel::setCurrentLineId(int) */

void __thiscall TDropDownPanel::setCurrentLineId(TDropDownPanel *this,int param_1)
{
  int iVar1;
  long lVar2;
  char *pcVar3;
  
  if (this->list_panel != (TListPanel *)0x0) {
    TTextPanel::set_line_by_id((TTextPanel *)this->list_panel,param_1);
    lVar2 = TTextPanel::get_line((TTextPanel *)this->list_panel);
    this->val_num = (short)lVar2;
    if (this->val_panel != (TTextPanel *)0x0) {
      iVar1 = this->val_panel->_padding_;
      pcVar3 = TTextPanel::get_text((TTextPanel *)this->list_panel,(int)(short)lVar2);
      (**(code **)(iVar1 + 0xe8))(pcVar3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: currentLine
// Address: 004751c0
/* public: char * __thiscall TDropDownPanel::currentLine(void) */

char * __thiscall TDropDownPanel::currentLine(TDropDownPanel *this)
{
  char *pcVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    pcVar1 = TTextPanel::currentLine((TTextPanel *)this->list_panel);
    return pcVar1;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: set_tab_order
// Address: 004751e0
/* public: virtual void __thiscall TDropDownPanel::set_tab_order(class TPanel *,class TPanel *) */

void __thiscall TDropDownPanel::set_tab_order(TDropDownPanel *this,TPanel *param_1,TPanel *param_2)
{
  TPanel::set_tab_order((TPanel *)this,param_1,param_2);
  if (this->val_panel != (TTextPanel *)0x0) {
    (**(code **)(this->val_panel->_padding_ + 0xc4))(0,0);
  }
  return;
}

// --------------------------------------------------

// Function: set_sorted
// Address: 00475210
/* public: void __thiscall TDropDownPanel::set_sorted(int) */

void __thiscall TDropDownPanel::set_sorted(TDropDownPanel *this,int param_1)
{
  if (this->list_panel != (TListPanel *)0x0) {
    this->list_panel->_padding_ = param_1;
  }
  return;
}

// --------------------------------------------------

// Function: get_sorted
// Address: 00475230
/* public: int __thiscall TDropDownPanel::get_sorted(void) */

int __thiscall TDropDownPanel::get_sorted(TDropDownPanel *this)
{
  if (this->list_panel != (TListPanel *)0x0) {
    return this->list_panel->_padding_;
  }
  return 0;
}

// --------------------------------------------------

// Function: set_line
// Address: 00475250
/* public: void __thiscall TDropDownPanel::set_line(long) */

void __thiscall TDropDownPanel::set_line(TDropDownPanel *this,long param_1)
{
  int iVar1;
  char *pcVar2;
  
  this->val_num = (short)param_1;
  if (this->list_panel != (TListPanel *)0x0) {
    TTextPanel::set_line((TTextPanel *)this->list_panel,param_1);
    if (this->val_panel != (TTextPanel *)0x0) {
      iVar1 = this->val_panel->_padding_;
      pcVar2 = TTextPanel::get_text((TTextPanel *)this->list_panel,param_1);
      (**(code **)(iVar1 + 0xe8))(pcVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: append_line
// Address: 004752a0
/* public: int __thiscall TDropDownPanel::append_line(char *,long) */

int __thiscall TDropDownPanel::append_line(TDropDownPanel *this,char *param_1,long param_2)
{
  int iVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    iVar1 = TTextPanel::append_line((TTextPanel *)this->list_panel,param_1,param_2);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: append_line
// Address: 004752d0
/* public: int __thiscall TDropDownPanel::append_line(long,long) */

int __thiscall TDropDownPanel::append_line(TDropDownPanel *this,long param_1,long param_2)
{
  int iVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    iVar1 = TTextPanel::append_line((TTextPanel *)this->list_panel,param_1,param_2);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: insert_line
// Address: 00475300
/* public: int __thiscall TDropDownPanel::insert_line(long,char *,long) */

int __thiscall
TDropDownPanel::insert_line(TDropDownPanel *this,long param_1,char *param_2,long param_3)
{
  int iVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    iVar1 = TTextPanel::insert_line((TTextPanel *)this->list_panel,param_1,param_2,param_3);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: insert_line
// Address: 00475330
/* public: int __thiscall TDropDownPanel::insert_line(long,long,long) */

int __thiscall
TDropDownPanel::insert_line(TDropDownPanel *this,long param_1,long param_2,long param_3)
{
  int iVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    iVar1 = TTextPanel::insert_line((TTextPanel *)this->list_panel,param_1,param_2,param_3);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: delete_line
// Address: 00475360
/* public: int __thiscall TDropDownPanel::delete_line(long) */

int __thiscall TDropDownPanel::delete_line(TDropDownPanel *this,long param_1)
{
  int iVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    iVar1 = TTextPanel::delete_line((TTextPanel *)this->list_panel,param_1);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: get_line
// Address: 00475380
/* public: long __thiscall TDropDownPanel::get_line(void) */

long __thiscall TDropDownPanel::get_line(TDropDownPanel *this)
{
  long lVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    lVar1 = TTextPanel::get_line((TTextPanel *)this->list_panel);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: get_line
// Address: 004753a0
/* public: long __thiscall TDropDownPanel::get_line(long) */

long __thiscall TDropDownPanel::get_line(TDropDownPanel *this,long param_1)
{
  long lVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    lVar1 = TTextPanel::get_line((TTextPanel *)this->list_panel,param_1);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: get_line
// Address: 004753c0
/* public: long __thiscall TDropDownPanel::get_line(char *) */

long __thiscall TDropDownPanel::get_line(TDropDownPanel *this,char *param_1)
{
  long lVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    lVar1 = TTextPanel::get_line((TTextPanel *)this->list_panel,param_1);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: get_text
// Address: 004753e0
/* public: char * __thiscall TDropDownPanel::get_text(void) */

char * __thiscall TDropDownPanel::get_text(TDropDownPanel *this)
{
  char *pcVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    pcVar1 = TTextPanel::get_text((TTextPanel *)this->list_panel);
    return pcVar1;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: get_text
// Address: 00475400
/* public: char * __thiscall TDropDownPanel::get_text(long) */

char * __thiscall TDropDownPanel::get_text(TDropDownPanel *this,long param_1)
{
  char *pcVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    pcVar1 = TTextPanel::get_text((TTextPanel *)this->list_panel,param_1);
    return pcVar1;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: get_id
// Address: 00475420
/* public: long __thiscall TDropDownPanel::get_id(void) */

long __thiscall TDropDownPanel::get_id(TDropDownPanel *this)
{
  long lVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    lVar1 = TTextPanel::get_id((TTextPanel *)this->list_panel);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: get_id
// Address: 00475440
/* public: long __thiscall TDropDownPanel::get_id(long) */

long __thiscall TDropDownPanel::get_id(TDropDownPanel *this,long param_1)
{
  long lVar1;
  
  if (this->list_panel != (TListPanel *)0x0) {
    lVar1 = TTextPanel::get_id((TTextPanel *)this->list_panel,param_1);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: empty_list
// Address: 00475460
/* public: void __thiscall TDropDownPanel::empty_list(void) */

void __thiscall TDropDownPanel::empty_list(TDropDownPanel *this)
{
  if (this->list_panel != (TListPanel *)0x0) {
    TTextPanel::empty_list((TTextPanel *)this->list_panel);
    return;
  }
  return;
}

// --------------------------------------------------


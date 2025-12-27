// Class: RGE_Panel_Time
// Function: RGE_Panel_Time
// Address: 0048a680
/* public: __thiscall RGE_Panel_Time::RGE_Panel_Time(class TDrawArea *,class TPanel *,void *) */

RGE_Panel_Time * __thiscall
RGE_Panel_Time::RGE_Panel_Time
          (RGE_Panel_Time *this,TDrawArea *param_1,TPanel *param_2,void *param_3)
{
  long lVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e798;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  TPanel::TPanel((TPanel *)this);
  this->font = param_3;
  local_4 = 0;
  this->_padding_ = 0;
  this->game_time = 0;
  this->last_game_time = 0;
  this->_padding_ = (int)&_vftable_;
  this->old_time = -1;
  lVar1 = TPanel::setup((TPanel *)this,param_1,param_2,0,0,0,0,'\0');
  if (lVar1 == 0) {
    this->_padding_ = 1;
  }
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0048a710
/* public: virtual void * __thiscall RGE_Panel_Time::`scalar deleting destructor'(unsigned int) */

void * __thiscall RGE_Panel_Time::_scalar_deleting_destructor_(RGE_Panel_Time *this,uint param_1)
{
  ~RGE_Panel_Time(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Panel_Time
// Address: 0048a730
/* public: virtual __thiscall RGE_Panel_Time::~RGE_Panel_Time(void) */

void __thiscall RGE_Panel_Time::~RGE_Panel_Time(RGE_Panel_Time *this)
{
  int iVar1;
  char *pcVar2;
  
  this->_padding_ = (int)&TPanel::_vftable_;
  TPanel::release_mouse((TPanel *)this);
  if (this->_padding_ != 0) {
    iVar1 = TPanelSystem::inSystem(&panel_system,(TPanel *)this);
    if (iVar1 != 0) {
      pcVar2 = TPanel::panelName((TPanel *)this);
      TPanelSystem::removePanel(&panel_system,pcVar2);
    }
  }
  if ((PanelNode *)this->_padding_ != (PanelNode *)0x0) {
    if ((TPanel *)this->_padding_ != (TPanel *)0x0) {
      TPanel::remove_panel_node((TPanel *)this->_padding_,(PanelNode *)this->_padding_);
    }
    free(this->_padding_);
    this->_padding_ = 0;
  }
  this->_padding_ = 0;
  if (this->_padding_ != 0) {
    DeleteObject(this->_padding_);
    this->_padding_ = 0;
  }
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0x20))(2);
  }
  if (this->_padding_ != 0) {
    free(this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0048a740
// [HELPER] s__02ld__02ld__02ld___3_1f_: "%02ld:%02ld:%02ld (%3.1f)"
// [HELPER] s_rpnl_tim__draw: "rpnl_tim::draw"
/* WARNING: Variable defined which should be unmapped: countdown_timer */
/* public: virtual void __thiscall RGE_Panel_Time::draw(void) */

void __thiscall RGE_Panel_Time::draw(RGE_Panel_Time *this)
{
  char cVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  long unaff_ESI;
  long countdown_timer;
  long player_num;
  void *pvStack_78;
  void *old_font;
  tagPALETTEENTRY paletteColor;
  char str [100];
  
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    pvVar7 = (void *)this->_padding_;
    countdown_timer = unaff_ESI;
    old_font = pvVar7;
    (**(code **)((int)pvVar7 + 0x28))(0);
    this->_padding_ = this->_padding_ + 1;
    pvVar2 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_rpnl_tim__draw);
    if (pvVar2 != (void *)0x0) {
      SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_);
      old_font = (void *)SelectObject(*(undefined4 *)(this->_padding_ + 0x38),this->font);
      iVar3 = RGE_Base_Game::get_paused(rge_base_game);
      if (iVar3 == 0) {
        SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),1);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
        iVar3 = this->game_time;
        iVar6 = 0;
        iVar8 = 0;
        if (0x3b < iVar3) {
          iVar6 = iVar3 / 0x3c;
          iVar3 = iVar3 % 0x3c;
          if (0x3b < iVar6) {
            iVar8 = iVar6 / 0x3c;
            iVar6 = iVar6 % 0x3c;
          }
        }
        sprintf(str,s__02ld__02ld__02ld___3_1f_,iVar8,iVar6,iVar3,
                (double)rge_base_game->world->game_speed);
        uVar5 = 0xffffffff;
        pcVar4 = str;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_,this->_padding_ + -2,str,
                 ~uVar5 - 1);
        iVar6 = 1;
        iVar3 = (int)rge_base_game->world->player_num;
        player_num = iVar3;
        if (1 < iVar3) {
          iVar8 = 0xd;
          do {
            RGE_Base_Game::get_countdown_timer(rge_base_game,iVar6,&countdown_timer);
            if (-1 < countdown_timer) {
              GetPaletteEntries(rge_base_game->draw_system->Pal,
                                rge_base_game->world->players[iVar6]->color_table->map_color,1,
                                &paletteColor);
              SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),
                           (((ushort)paletteColor._2_2_ & 0xff) << 8 |
                           CONCAT21(paletteColor._2_2_,paletteColor.peGreen) & 0xff) << 8 |
                           CONCAT11(paletteColor.peGreen,paletteColor.peRed) & 0xff);
                    /* language.dll match for 0x2c24: "%d Years" */
              pcVar4 = TPanel::get_string((TPanel *)this,0x2c24);
              sprintf(str,pcVar4);
              uVar5 = 0xffffffff;
              pcVar4 = str;
              do {
                if (uVar5 == 0) break;
                uVar5 = uVar5 - 1;
                cVar1 = *pcVar4;
                pcVar4 = pcVar4 + 1;
              } while (cVar1 != '\0');
              TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_,
                       iVar8 + this->_padding_,str,~uVar5 - 1);
              iVar8 = iVar8 + 0xd;
              iVar3 = player_num;
            }
            iVar6 = iVar6 + 1;
            pvVar7 = pvStack_78;
          } while (iVar6 < iVar3);
        }
      }
      else {
        SetBkColor(*(undefined4 *)(this->_padding_ + 0x38),0xffffff);
        SetBkMode(*(undefined4 *)(this->_padding_ + 0x38),2);
        SetTextColor(*(undefined4 *)(this->_padding_ + 0x38),0xff);
        sprintf(str);
        uVar5 = 0xffffffff;
        pcVar4 = str;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        TextOutA(*(undefined4 *)(this->_padding_ + 0x38),this->_padding_,this->_padding_ + -2,str,
                 ~uVar5 - 1);
      }
      SelectObject(*(undefined4 *)(this->_padding_ + 0x38),old_font);
      SelectClipRgn(*(undefined4 *)(this->_padding_ + 0x38),0);
      TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_rpnl_tim__draw);
    }
    (**(code **)((int)pvVar7 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: handle_idle
// Address: 0048aa70
/* public: virtual long __thiscall RGE_Panel_Time::handle_idle(void) */

long __thiscall RGE_Panel_Time::handle_idle(RGE_Panel_Time *this)
{
  uint uVar1;
  
  TPanel::handle_idle((TPanel *)this);
  this->game_time = rge_base_game->world->world_time / 1000;
  uVar1 = rge_base_game->world->old_time / 1000;
  if (uVar1 != 0) {
    if (this->old_time == -1) {
      this->old_time = uVar1;
      this->real_time = 0;
    }
    else {
      this->real_time = uVar1 - this->old_time;
    }
  }
  if (this->game_time != this->last_game_time) {
    (**(code **)(this->_padding_ + 0x20))(1);
    if ((int *)this->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)this->_padding_ + 0x20))(1);
    }
    this->last_game_time = this->game_time;
  }
  return 0;
}

// --------------------------------------------------


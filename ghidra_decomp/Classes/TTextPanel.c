// Class: TTextPanel
// Size:  0x188
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
// [01] setup
// [02] set_rect
// [03] set_rect
// [04] set_color
// [05] set_active
// [06] set_positioning
// [07] set_fixed_position
// [08] set_redraw
// [09] set_overlapped_redraw
// [10] draw_setup
// [11] draw_finish
// [12] draw
// [13] draw_rect
// [14] draw_offset
// [15] draw_rect2
// [16] draw_offset2
// [17] paint
// [18] wnd_proc
// [19] handle_idle
// [20] handle_size
// [21] handle_paint
// [22] handle_key_down
// [23] handle_char
// [24] handle_command
// [25] handle_user_command
// [26] handle_timer_command
// [27] handle_scroll
// [28] handle_mouse_down
// [29] handle_mouse_move
// [30] handle_mouse_up
// [31] handle_mouse_dbl_click
// [32] mouse_move_action
// [33] mouse_left_down_action
// [34] mouse_left_hold_action
// [35] mouse_left_move_action
// [36] mouse_left_up_action
// [37] mouse_left_dbl_click_action
// [38] mouse_right_down_action
// [39] mouse_right_hold_action
// [40] mouse_right_move_action
// [41] mouse_right_up_action
// [42] mouse_right_dbl_click_action
// [43] key_down_action
// [44] char_action
// [45] action
// [46] get_true_render_rect
// [47] is_inside
// [48] set_focus
// [49] set_tab_order
// [50] set_tab_order
// [51] get_help_info
// [52] stop_sound_system
// [53] restart_sound_system
// [54] take_snapshot
// [55] handle_reactivate
// [56] set_text
// [57] set_text
// [58] set_text
// [59] set_bevel_info
//
// Member Layout:
// [0x0F4] TextNode * list
// [0x0F8] short num_lines
// [0x0FA] short draw_lines
// [0x0FC] short top_line
// [0x0FE] short bot_line
// [0x100] short cur_line
// [0x102] short cur_col
// [0x104] void * font
// [0x108] long font_wid
// [0x10C] long font_hgt
// [0x110] Alignment vert_align
// [0x114] Alignment horz_align
// [0x118] int word_wrap
// [0x11C] Style text_style
// [0x120] ulong text_color1
// [0x124] ulong text_color2
// [0x128] ulong highlightTextColor1
// [0x12C] ulong highlightTextColor2
// [0x130] TScrollBarPanel * scbar_panel
// [0x134] int auto_scbar
// [0x138] short fixed_len
// [0x13C] long text_wid
// [0x140] long text_hgt
// [0x144] TShape * back_pic
// [0x148] short back_pic_wid
// [0x14A] short back_pic_hgt
// [0x14C] int fill_back
// [0x150] uchar back_color
// [0x154] int outline
// [0x158] uchar outline_color
// [0x15C] int sorted
// [0x160] long second_column_pos
// [0x164] long full_width
// [0x168] long scbar_width
// [0x16C] int scbar_active
// [0x170] int bevel_type
// [0x174] uchar bevel_color1
// [0x175] uchar bevel_color2
// [0x176] uchar bevel_color3
// [0x177] uchar bevel_color4
// [0x178] uchar bevel_color5
// [0x179] uchar bevel_color6
// [0x17C] void * clip_rgn2
// [0x180] int border_size
// [0x184] int spacer_size
// ----------------------------------------------------------------

// Function: TTextPanel
// Address: 0047bf40
/* public: __thiscall TTextPanel::TTextPanel(void) */

TTextPanel * __thiscall TTextPanel::TTextPanel(TTextPanel *this)
{
  TPanel::TPanel((TPanel *)this);
  this->back_color = 0xff;
  this->list = (TextNode *)0x0;
  this->num_lines = 0;
  this->draw_lines = 0;
  this->top_line = 0;
  this->bot_line = 0;
  this->cur_line = 0;
  this->cur_col = 0;
  this->font = (void *)0x0;
  this->font_wid = 0;
  this->font_hgt = 0;
  this->vert_align = AlignCenter;
  this->horz_align = AlignCenter;
  this->word_wrap = 0;
  this->text_style = ChiseledStyle;
  this->text_color1 = 0xffffff;
  this->text_color2 = 0;
  this->highlightTextColor2 = 0;
  this->scbar_panel = (TScrollBarPanel *)0x0;
  this->auto_scbar = 0;
  this->fixed_len = 0;
  this->text_wid = 0;
  this->text_hgt = 0;
  this->back_pic = (TShape *)0x0;
  this->back_pic_wid = 0;
  this->back_pic_hgt = 0;
  this->fill_back = 0;
  this->outline = 0;
  this->outline_color = '\0';
  this->sorted = 0;
  this->second_column_pos = 0;
  this->full_width = 0;
  this->scbar_width = 0;
  this->scbar_active = 0;
  this->bevel_type = 0;
  this->bevel_color1 = '\0';
  this->bevel_color2 = '\0';
  this->bevel_color3 = '\0';
  this->bevel_color4 = '\0';
  this->bevel_color5 = '\0';
  this->bevel_color6 = '\0';
  this->clip_rgn2 = (void *)0x0;
  this->border_size = 0;
  this->spacer_size = 0;
  this->_padding_ = 0;
  this->highlightTextColor1 = 0xffff;
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)((int)&this->_padding_ + 2) = 1;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0047c090
/* public: virtual void * __thiscall TTextPanel::`scalar deleting destructor'(unsigned int) */

void * __thiscall TTextPanel::_scalar_deleting_destructor_(TTextPanel *this,uint param_1)
{
  ~TTextPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TTextPanel
// Address: 0047c0b0
/* public: virtual __thiscall TTextPanel::~TTextPanel(void) */

void __thiscall TTextPanel::~TTextPanel(TTextPanel *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055e598;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  free_text(this);
  if (this->clip_rgn2 != (void *)0x0) {
    DeleteObject(this->clip_rgn2);
    this->clip_rgn2 = (void *)0x0;
  }
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0047c120
/* public: long __thiscall TTextPanel::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,void *,long,long,char *,int,unsigned char,int,unsigned char,short,char *)
    */

long __thiscall
TTextPanel::setup(TTextPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
                 long param_5,long param_6,void *param_7,long param_8,long param_9,char *param_10,
                 int param_11,uchar param_12,int param_13,uchar param_14,short param_15,
                 char *param_16)
{
  TPanel::setup((TPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,'\0');
  this->fill_back = param_11;
  this->back_color = param_12;
  this->outline = param_13;
  this->outline_color = param_14;
  this->fixed_len = param_15;
  if (param_13 != 0) {
    this->bevel_type = 1;
  }
  (**(code **)(this->_padding_ + 0xe8))(param_16);
  set_font(this,(void *)param_6,(long)param_7,param_8);
  set_alignment(this,AlignCenter,AlignCenter);
  set_back_pic(this,(char *)param_9);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0047c1e0
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Variable defined which should be unmapped: str */
/* public: long __thiscall TTextPanel::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,void *,long,long,char *,int,unsigned char,int,unsigned char,short,long) */

long __thiscall
TTextPanel::setup(TTextPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
                 long param_5,long param_6,void *param_7,long param_8,long param_9,char *param_10,
                 int param_11,uchar param_12,int param_13,uchar param_14,short param_15,
                 long param_16)
{
  char str [4096];
  
  TPanel::setup((TPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,'\0');
  this->fill_back = param_11;
  this->back_color = param_12;
  this->outline = param_13;
  this->outline_color = param_14;
  this->fixed_len = param_15;
  if (param_13 != 0) {
    this->bevel_type = 1;
  }
  set_font(this,param_7,param_8,param_9);
  set_alignment(this,AlignCenter,AlignCenter);
  set_back_pic(this,param_10);
  TPanel::get_string((TPanel *)this,param_16,str + 4,0x1000);
  (**(code **)(this->_padding_ + 0xe8))(str + 4);
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0047c2f0
/* public: long __thiscall TTextPanel::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,void *,long,long,char *,int,unsigned char,int,unsigned char,short,char *
   *,short) */

long __thiscall
TTextPanel::setup(TTextPanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
                 long param_5,long param_6,void *param_7,long param_8,long param_9,char *param_10,
                 int param_11,uchar param_12,int param_13,uchar param_14,short param_15,
                 char **param_16,short param_17)
{
  undefined2 in_stack_00000046;
  
  TPanel::setup((TPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,'\0');
  this->fill_back = param_11;
  this->back_color = param_12;
  this->outline = param_13;
  this->outline_color = param_14;
  this->fixed_len = param_15;
  if (param_13 != 0) {
    this->bevel_type = 1;
  }
  (**(code **)(this->_padding_ + 0xe0))(param_16,_param_17);
  set_font(this,(void *)param_5,param_6,(long)param_7);
  set_alignment(this,AlignTop,AlignLeft);
  set_back_pic(this,(char *)param_8);
  return 1;
}

// --------------------------------------------------

// Function: set_rect
// Address: 0047c3b0
/* WARNING: Variable defined which should be unmapped: clip_rect2 */
/* public: virtual void __thiscall TTextPanel::set_rect(long,long,long,long) */

void __thiscall
TTextPanel::set_rect(TTextPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  long lVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  tagRECT clip_rect2;
  
  TPanel::set_rect((TPanel *)this,param_1,param_2,param_3,param_4);
  this->full_width = this->_padding_;
  if ((this->auto_scbar != 0) && (this->scbar_panel != (TScrollBarPanel *)0x0)) {
    (**(code **)(this->scbar_panel->_padding_ + 0x14))(0);
    this->scbar_active = 0;
    if ((TPanel *)this->_padding_ == (TPanel *)0x0) {
      iVar4 = this->_padding_;
      iVar3 = this->_padding_;
    }
    else {
      lVar1 = TPanel::xPosition((TPanel *)this->_padding_);
      iVar4 = this->_padding_ - lVar1;
      lVar1 = TPanel::yPosition((TPanel *)this->_padding_);
      iVar3 = this->_padding_ - lVar1;
    }
    (**(code **)(this->scbar_panel->_padding_ + 0x1c))
              ((iVar4 + this->full_width) - this->scbar_width,iVar3,this->scbar_width,
               this->_padding_);
  }
  calc_draw_info(this,1);
  if (this->second_column_pos != 0) {
    if (this->clip_rgn2 != (void *)0x0) {
      DeleteObject(this->clip_rgn2);
      this->clip_rgn2 = (void *)0x0;
    }
    if (this->_padding_ != 0) {
      iVar4 = this->_padding_ + -10 + this->second_column_pos;
      if (this->_padding_ < iVar4) {
        iVar4 = this->_padding_;
      }
      pvVar2 = (void *)CreateRectRgn(this->_padding_,this->_padding_,iVar4,this->_padding_);
      this->clip_rgn2 = pvVar2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: set_scrollbar
// Address: 0047c4d0
/* public: void __thiscall TTextPanel::set_scrollbar(class TScrollBarPanel *,int) */

void __thiscall TTextPanel::set_scrollbar(TTextPanel *this,TScrollBarPanel *param_1,int param_2)
{
  long lVar1;
  
  this->scbar_panel = param_1;
  this->auto_scbar = param_2;
  if (param_1 != (TScrollBarPanel *)0x0) {
    lVar1 = TPanel::width((TPanel *)param_1);
    this->scbar_width = lVar1;
    (**(code **)(this->_padding_ + 0xc))
              (this->_padding_,this->_padding_,this->_padding_,this->_padding_);
  }
  return;
}

// --------------------------------------------------

// Function: char_type
// Address: 0047c520
/* public: enum TTextPanel::CharType __thiscall TTextPanel::char_type(unsigned char *) */

CharType __thiscall TTextPanel::char_type(TTextPanel *this,uchar *param_1)
{
  int iVar1;
  
  if ((param_1 != (uchar *)0x0) && (*param_1 != '\0')) {
    iVar1 = IsDBCSLeadByte(*param_1);
    if (iVar1 != 0) {
      return DoubleByteChar;
    }
    if ((0xa0 < *param_1) && (*param_1 < 0xe0)) {
      return SingleByteKanaChar;
    }
  }
  return SingleByteChar;
}

// --------------------------------------------------

// Function: set_text
// Address: 0047c560
// [HELPER] s_: ""
/* WARNING: Variable defined which should be unmapped: temp_text */
/* public: virtual void __thiscall TTextPanel::set_text(char *) */

void __thiscall TTextPanel::set_text(TTextPanel *this,char *param_1)
{
  int iVar1;
  int iVar2;
  uchar temp_text [256];
  
  free_text(this);
  if (param_1 == (char *)0x0) {
    if (this->fixed_len != 0) {
      append_line(this,s_,0);
      return;
    }
  }
  else {
    if (*param_1 == '\0') {
      append_line(this,s_,0);
      return;
    }
    if ((this->word_wrap == 0) && (this->horz_align != AlignWordwrap)) {
      while( true ) {
        iVar1 = __mbschr(param_1,10);
        if (iVar1 == 0) break;
        iVar2 = (int)(short)((short)iVar1 - (short)param_1);
        strncpy(temp_text + 4,param_1,iVar2);
        temp_text[iVar2 + 4] = '\0';
        append_line(this,(char *)(temp_text + 4),0);
        param_1 = (char *)(iVar1 + 1);
      }
      append_line(this,param_1,0);
      return;
    }
    word_wrap_append(this,param_1);
  }
  return;
}

// --------------------------------------------------

// Function: word_wrap_append
// Address: 0047c640
// [HELPER] s__: "}"
// [HELPER] s_pnl_txt__word_wrap_append: "pnl_txt::word_wrap_append"
/* WARNING: Variable defined which should be unmapped: found_break */
/* WARNING: Type propagation algorithm not settling */
/* public: int __thiscall TTextPanel::word_wrap_append(char *) */

int __thiscall TTextPanel::word_wrap_append(TTextPanel *this,char *param_1)
{
  uchar uVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  long lVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  int iVar13;
  void *pvVar14;
  uchar *puVar15;
  uchar *puVar16;
  CharType CVar17;
  int iVar18;
  uchar *puVar19;
  int found_break;
  int found_return;
  void *dc;
  int found_space;
  uchar *last_char;
  long max_wid;
  uchar *next_char;
  tagSIZE text_size;
  int found_linefeed;
  int found_bad_return;
  int japanese;
  void *old_font;
  tagTEXTMETRICA tm;
  uchar temp_text [256];
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    return 1;
  }
  if (this->auto_scbar == 0) {
    iVar13 = this->_padding_;
  }
  else {
    iVar13 = this->full_width - this->scbar_width;
  }
  iVar13 = iVar13 + -10;
  pvVar14 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_pnl_txt__word_wrap_append);
  if (pvVar14 == (void *)0x0) {
    return 0;
  }
  tm.tmHeight = SelectObject(pvVar14,this->font);
  GetTextMetricsA(pvVar14,&tm.tmAscent);
LAB_0047c6e3:
  sVar9 = __mbslen(param_1);
  bVar3 = false;
  bVar6 = false;
  bVar4 = false;
  bVar5 = false;
  bVar7 = false;
  sVar2 = (short)param_1;
  if (*param_1 == '\n') {
    bVar3 = true;
    sVar10 = 0;
  }
  else {
    sVar10 = __mbsinc(param_1);
    GetTextExtentPoint32A(pvVar14,param_1,(int)(short)(sVar10 - sVar2),&text_size.cy);
    puVar16 = (uchar *)0x0;
    puVar19 = (uchar *)param_1;
    sVar10 = 1;
    sVar11 = 1;
    if (0 < sVar9) {
      while (sVar10 = sVar11, text_size.cy < iVar13) {
        if (*puVar19 == '\n') {
          sVar10 = sVar11 + -1;
          bVar3 = true;
          if ((puVar16 != (uchar *)0x0) && (*puVar16 == '\r')) {
            bVar6 = true;
            sVar10 = sVar11 + -2;
          }
          break;
        }
        if (*puVar19 == '\r') {
          bVar7 = true;
        }
        puVar15 = (uchar *)__mbsinc(puVar19);
        sVar10 = sVar11 + 1;
        sVar11 = __mbsinc(puVar15);
        GetTextExtentPoint32A(pvVar14,param_1,(int)(short)(sVar11 - sVar2),&text_size.cy);
        puVar16 = puVar19;
        puVar19 = puVar15;
        sVar11 = sVar10;
        if (sVar9 < sVar10) break;
      }
    }
  }
  if (bVar3) goto LAB_0047c955;
  iVar18 = -1;
  puVar16 = (uchar *)param_1;
  do {
    if (iVar18 == 0) break;
    iVar18 = iVar18 + -1;
    uVar1 = *puVar16;
    puVar16 = puVar16 + 1;
  } while (uVar1 != '\0');
  GetTextExtentPoint32A(pvVar14,param_1,(int)(short)(~(ushort)iVar18 - 1),&text_size.cy);
  if (iVar13 < text_size.cy) {
    sVar10 = 1;
    sVar11 = 1;
    puVar16 = (uchar *)param_1;
    lVar8 = text_size.cx;
    if (1 < sVar9) {
      do {
        sVar12 = __mbsinc(puVar16);
        GetTextExtentPoint32A(pvVar14,param_1,(int)(short)(sVar12 - sVar2),&text_size.cy);
        lVar8 = text_size.cx;
        if (iVar13 < text_size.cy) break;
        sVar11 = sVar10 + -1;
        puVar16 = (uchar *)__mbsinc(puVar16);
        sVar10 = sVar10 + 1;
        lVar8 = text_size.cx;
      } while (sVar10 < sVar9);
    }
joined_r0x0047c85c:
    do {
      text_size.cx = (long)puVar16;
      if (sVar10 < 2) goto LAB_0047c91d;
      puVar16 = (uchar *)__mbsdec(param_1,text_size.cx);
      sVar10 = sVar10 + -1;
      if (temp_text[0] != 0x80) {
        iVar18 = __ismbcspace(*puVar16);
        lVar8 = text_size.cx;
        if (iVar18 != 0) {
LAB_0047c915:
          bVar4 = true;
          lVar8 = text_size.cx;
          goto LAB_0047c91d;
        }
        goto joined_r0x0047c85c;
      }
      CVar17 = char_type(this,puVar16);
      text_size.cx = char_type(this,(uchar *)text_size.cx);
      if (((CVar17 == SingleByteChar) && (text_size.cx == SingleByteChar)) &&
         (iVar18 = __ismbcspace(*puVar16), iVar18 != 0)) goto LAB_0047c915;
      lVar8 = text_size.cx;
      if ((((((CVar17 == DoubleByteChar) && (text_size.cx == 2)) ||
            ((CVar17 == SingleByteKanaChar && (text_size.cx == 1)))) ||
           ((CVar17 == SingleByteChar && (text_size.cx == 2)))) ||
          ((CVar17 == DoubleByteChar && (text_size.cx == 0)))) ||
         (((CVar17 == SingleByteChar && (text_size.cx == 1)) ||
          ((CVar17 == SingleByteKanaChar && (text_size.cx == 0)))))) goto LAB_0047c90b;
    } while( true );
  }
LAB_0047ca2b:
  append_line(this,param_1,0);
  SelectObject(pvVar14,tm.tmHeight);
  TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_pnl_txt__word_wrap_append);
  return 1;
LAB_0047c90b:
  bVar5 = true;
LAB_0047c91d:
  text_size.cx = lVar8;
  if ((!bVar4) && (!bVar5)) {
    bVar5 = true;
    sVar10 = sVar11;
  }
  if ((!bVar4) && (!bVar5)) goto LAB_0047ca2b;
LAB_0047c955:
  puVar16 = temp_text;
  for (iVar18 = 0x40; puVar16 = puVar16 + 4, iVar18 != 0; iVar18 = iVar18 + -1) {
    puVar16[0] = '\0';
    puVar16[1] = '\0';
    puVar16[2] = '\0';
    puVar16[3] = '\0';
  }
  __mbsncpy(temp_text + 4,param_1,(int)sVar10);
  if (bVar6) {
    __mbscat(temp_text + 4,&s__);
  }
  if (bVar3) {
    __mbscat(temp_text + 4,&s__);
  }
  if (bVar7) {
    puVar16 = temp_text + 4;
    uVar1 = temp_text[4];
    while (uVar1 != '\0') {
      if (*puVar16 == '\r') {
        *puVar16 = ' ';
      }
      puVar16 = (uchar *)__mbsinc(puVar16);
      uVar1 = *puVar16;
    }
  }
  append_line(this,(char *)(temp_text + 4),0);
  param_1 = (char *)__mbsninc(param_1,(int)sVar10);
  if (bVar6) {
    param_1 = (char *)__mbsinc(param_1);
  }
  if (bVar3) {
    param_1 = (char *)__mbsinc(param_1);
  }
  goto LAB_0047c6e3;
}

// --------------------------------------------------

// Function: set_text
// Address: 0047ca70
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Variable defined which should be unmapped: str */
/* public: virtual void __thiscall TTextPanel::set_text(long) */

void __thiscall TTextPanel::set_text(TTextPanel *this,long param_1)
{
  char str [4096];
  
  TPanel::get_string((TPanel *)this,param_1,str + 4,0x1000);
  (**(code **)(this->_padding_ + 0xe8))(str + 4);
  return;
}

// --------------------------------------------------

// Function: set_text
// Address: 0047cab0
// [HELPER] s_: ""
/* public: virtual void __thiscall TTextPanel::set_text(char * *,short) */

void __thiscall TTextPanel::set_text(TTextPanel *this,char **param_1,short param_2)
{
  int iVar1;
  
  free_text(this);
  if (param_2 == 0) {
    if (this->fixed_len != 0) {
      append_line(this,s_,0);
      return;
    }
  }
  else if (0 < param_2) {
    iVar1 = (int)param_2;
    do {
      append_line(this,*param_1,0);
      param_1 = param_1 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: set_font
// Address: 0047cb10
/* public: void __thiscall TTextPanel::set_font(void *,long,long) */

void __thiscall TTextPanel::set_font(TTextPanel *this,void *param_1,long param_2,long param_3)
{
  this->font_wid = param_2;
  this->font = param_1;
  this->font_hgt = param_3;
  calc_draw_info(this,1);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_alignment
// Address: 0047cb50
/* public: void __thiscall TTextPanel::set_alignment(enum TTextPanel::Alignment,enum
   TTextPanel::Alignment) */

void __thiscall TTextPanel::set_alignment(TTextPanel *this,Alignment param_1,Alignment param_2)
{
  this->vert_align = param_1;
  this->horz_align = param_2;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_word_wrap
// Address: 0047cb70
/* public: void __thiscall TTextPanel::set_word_wrap(int) */

void __thiscall TTextPanel::set_word_wrap(TTextPanel *this,int param_1)
{
  this->word_wrap = param_1;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_style
// Address: 0047cb90
/* public: void __thiscall TTextPanel::set_style(enum TTextPanel::Style) */

void __thiscall TTextPanel::set_style(TTextPanel *this,Style param_1)
{
  this->text_style = param_1;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_text_color
// Address: 0047cbb0
/* public: void __thiscall TTextPanel::set_text_color(unsigned long,unsigned long) */

void __thiscall TTextPanel::set_text_color(TTextPanel *this,ulong param_1,ulong param_2)
{
  this->text_color1 = param_1;
  this->text_color2 = param_2;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_highlight_text_color
// Address: 0047cbd0
/* public: void __thiscall TTextPanel::set_highlight_text_color(unsigned long,unsigned long) */

void __thiscall TTextPanel::set_highlight_text_color(TTextPanel *this,ulong param_1,ulong param_2)
{
  this->highlightTextColor1 = param_1;
  this->highlightTextColor2 = param_2;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_fill_back
// Address: 0047cbf0
/* public: void __thiscall TTextPanel::set_fill_back(int,unsigned char) */

void __thiscall TTextPanel::set_fill_back(TTextPanel *this,int param_1,uchar param_2)
{
  this->fill_back = param_1;
  this->back_color = param_2;
  return;
}

// --------------------------------------------------

// Function: set_back_pic
// Address: 0047cc10
/* WARNING: Variable defined which should be unmapped: x_max */
/* public: void __thiscall TTextPanel::set_back_pic(char *) */

void __thiscall TTextPanel::set_back_pic(TTextPanel *this,char *param_1)
{
  TShape *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  long x_max;
  long x_min;
  long y_max;
  long y_min;
  short local_10 [2];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e5bb;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = this->back_pic;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    this->back_pic = (TShape *)0x0;
    this->back_pic_wid = 0;
    this->back_pic_hgt = 0;
  }
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    pTVar1 = (TShape *)operator_new(0x20);
    local_4 = 0;
    if (pTVar1 == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape(pTVar1,param_1,-1);
    }
    local_4 = 0xffffffff;
    this->back_pic = pTVar1;
    TShape::shape_minmax(pTVar1,&y_max,(long *)local_10,&x_min,&y_min,0);
    this->back_pic_wid = ((short)x_min - (short)y_max) + 1;
    this->back_pic_hgt = ((short)y_min - local_10[0]) + 1;
  }
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: set_outline
// Address: 0047ccf0
/* public: void __thiscall TTextPanel::set_outline(int,unsigned char) */

void __thiscall TTextPanel::set_outline(TTextPanel *this,int param_1,uchar param_2)
{
  this->outline = param_1;
  if (param_1 != 0) {
    this->bevel_type = 1;
    this->outline_color = param_2;
    (**(code **)(this->_padding_ + 0x20))(1);
    return;
  }
  this->bevel_type = 0;
  this->outline_color = param_2;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_bevel_info
// Address: 0047cd40
/* public: virtual void __thiscall TTextPanel::set_bevel_info(int,int,int,int,int,int,int) */

void __thiscall
TTextPanel::set_bevel_info
          (TTextPanel *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
          int param_7)
{
  this->bevel_color1 = (uchar)param_2;
  this->bevel_color2 = (uchar)param_3;
  this->bevel_color3 = (uchar)param_4;
  this->bevel_color4 = (uchar)param_5;
  this->bevel_type = param_1;
  this->bevel_color5 = (uchar)param_6;
  this->bevel_color6 = (uchar)param_7;
  switch(param_1) {
  case 1:
  case 2:
  case 5:
    this->border_size = 1;
    calc_draw_info(this,1);
    return;
  case 3:
  case 6:
    this->border_size = 2;
    calc_draw_info(this,1);
    return;
  case 4:
  case 7:
    this->border_size = 3;
    calc_draw_info(this,1);
    return;
  default:
    this->border_size = 0;
    calc_draw_info(this,1);
    return;
  }
}

// --------------------------------------------------

// Function: set_spacer_size
// Address: 0047ce00
/* public: void __thiscall TTextPanel::set_spacer_size(int) */

void __thiscall TTextPanel::set_spacer_size(TTextPanel *this,int param_1)
{
  this->spacer_size = param_1;
  calc_draw_info(this,1);
  return;
}

// --------------------------------------------------

// Function: set_active
// Address: 0047ce20
/* public: virtual void __thiscall TTextPanel::set_active(int) */

void __thiscall TTextPanel::set_active(TTextPanel *this,int param_1)
{
  int iVar1;
  
  TPanel::set_active((TPanel *)this,param_1);
  if ((this->auto_scbar != 0) && (this->scbar_panel != (TScrollBarPanel *)0x0)) {
    iVar1 = this->scbar_panel->_padding_;
    if (this->_padding_ != 0) {
      (**(code **)(iVar1 + 0x14))(this->scbar_active);
      return;
    }
    (**(code **)(iVar1 + 0x14))(0);
  }
  return;
}

// --------------------------------------------------

// Function: calc_draw_info
// Address: 0047ce70
/* public: void __thiscall TTextPanel::calc_draw_info(int) */

void __thiscall TTextPanel::calc_draw_info(TTextPanel *this,int param_1)
{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = this->font_hgt;
  iVar6 = iVar4 + 2;
  this->text_hgt = iVar6;
  if (iVar4 == 0) {
    this->draw_lines = 1;
  }
  else {
    if (this->spacer_size == 0) {
      iVar5 = this->_padding_ + this->border_size * -2;
    }
    else {
      iVar5 = this->_padding_ + this->border_size * -2;
      iVar6 = iVar4 + 1 + this->spacer_size * 2;
    }
    this->draw_lines = (short)(iVar5 / iVar6);
  }
  if (this->draw_lines < 1) {
    this->draw_lines = 1;
  }
  sVar2 = this->num_lines;
  if (sVar2 <= this->top_line) {
    this->top_line = sVar2 + -1;
  }
  sVar3 = this->draw_lines;
  if ((int)sVar2 - (int)this->top_line < (int)sVar3) {
    this->top_line = sVar2 - sVar3;
  }
  if (this->top_line < 0) {
    this->top_line = 0;
  }
  sVar1 = this->top_line + -1 + sVar3;
  this->bot_line = sVar1;
  if (sVar1 < 0) {
    this->bot_line = 0;
  }
  if (sVar2 <= this->bot_line) {
    this->bot_line = sVar2 + -1;
  }
  if (this->cur_line < 0) {
    this->cur_line = 0;
  }
  if (sVar2 <= this->cur_line) {
    this->cur_line = sVar2 + -1;
  }
  if (this->scbar_panel != (TScrollBarPanel *)0x0) {
    if (param_1 != 0) {
      TScrollBarPanel::set_list_len
                (this->scbar_panel,((int)sVar2 - (int)sVar3) + 1,(int)this->top_line);
    }
    if (this->auto_scbar != 0) {
      if (this->draw_lines < this->num_lines) {
        if (this->scbar_active == 0) {
          TPanel::set_rect((TPanel *)this,this->_padding_,this->_padding_,
                           this->full_width - this->scbar_width,this->_padding_);
          this->scbar_active = 1;
          if (this->_padding_ != 0) {
            (**(code **)(this->scbar_panel->_padding_ + 0x14))(1);
            this->text_wid = this->_padding_;
            return;
          }
        }
      }
      else if (this->scbar_active != 0) {
        TPanel::set_rect((TPanel *)this,this->_padding_,this->_padding_,this->full_width,
                         this->_padding_);
        this->scbar_active = 0;
        if (this->_padding_ != 0) {
          (**(code **)(this->scbar_panel->_padding_ + 0x14))(0);
        }
      }
    }
  }
  this->text_wid = this->_padding_;
  return;
}

// --------------------------------------------------

// Function: scroll
// Address: 0047d060
/* public: void __thiscall TTextPanel::scroll(unsigned char,short,int) */

void __thiscall TTextPanel::scroll(TTextPanel *this,uchar param_1,short param_2,int param_3)
{
  switch(param_1) {
  case '\0':
    this->top_line = this->top_line + param_2;
    break;
  case '\x01':
    goto LAB_0047d0d9;
  case '\x02':
    this->top_line = this->top_line + 1;
    break;
  case '\x03':
    this->top_line = this->top_line + -1;
    break;
  case '\x04':
    this->top_line = this->top_line + this->draw_lines + -1;
    break;
  case '\x05':
    this->top_line = this->top_line + (1 - this->draw_lines);
    break;
  case '\x06':
    this->top_line = 0;
    break;
  case '\a':
    param_2 = this->num_lines + -1;
LAB_0047d0d9:
    this->top_line = param_2;
  }
  calc_draw_info(this,param_3);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: key_down_action
// Address: 0047d120
/* public: virtual long __thiscall TTextPanel::key_down_action(long,short,int,int,int) */

long __thiscall
TTextPanel::key_down_action
          (TTextPanel *this,long param_1,short param_2,int param_3,int param_4,int param_5)
{
  int *piVar1;
  int iVar2;
  undefined2 in_stack_0000000a;
  uchar uVar3;
  
  switch(param_1) {
  case 0x21:
    uVar3 = '\x05';
    break;
  case 0x22:
    uVar3 = '\x04';
    break;
  case 0x23:
    scroll(this,'\a',0,1);
    return 1;
  case 0x24:
    scroll(this,'\x06',0,1);
    return 1;
  default:
    return 0;
  case 0x26:
    uVar3 = '\x03';
    goto LAB_0047d149;
  case 0x28:
    uVar3 = '\x02';
LAB_0047d149:
    scroll(this,uVar3,0,1);
    piVar1 = (int *)this->_padding_;
    if (piVar1 == (int *)0x0) {
      return 1;
    }
    iVar2 = this->_padding_;
    goto joined_r0x0047d15c;
  }
  scroll(this,uVar3,0,1);
  piVar1 = (int *)this->_padding_;
  if (piVar1 != (int *)0x0) {
    iVar2 = this->_padding_;
joined_r0x0047d15c:
    if (iVar2 != 0) {
      (**(code **)(*piVar1 + 0xac))(param_1,_param_2,param_3,param_4,param_5);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: action
// Address: 0047d200
/* public: virtual long __thiscall TTextPanel::action(class TPanel *,long,unsigned long,unsigned
   long) */

long __thiscall
TTextPanel::action(TTextPanel *this,TPanel *param_1,long param_2,ulong param_3,ulong param_4)
{
  long lVar1;
  
  if ((this->scbar_panel != (TScrollBarPanel *)0x0) &&
     ((TScrollBarPanel *)param_1 == this->scbar_panel)) {
    switch(param_2) {
    case 0:
      scroll(this,'\x03',0,1);
      return 1;
    case 1:
      scroll(this,'\x02',0,1);
      return 1;
    case 2:
      scroll(this,'\x05',0,1);
      return 1;
    case 3:
      scroll(this,'\x04',0,1);
      return 1;
    case 4:
      scroll(this,'\x01',(short)param_3,0);
      return 1;
    }
  }
  lVar1 = TPanel::action((TPanel *)this,param_1,param_2,param_3,param_4);
  return lVar1;
}

// --------------------------------------------------

// Function: draw
// Address: 0047d2c0
// [HELPER] s_pnl_txt__draw: "pnl_txt::draw"
/* WARNING: Variable defined which should be unmapped: old_font */
/* public: virtual void __thiscall TTextPanel::draw(void) */

void __thiscall TTextPanel::draw(TTextPanel *this)
{
  void *pvVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  ulong uVar6;
  ulong uVar7;
  void *old_font;
  int iStack_8;
  
  sVar5 = 0;
  this->_padding_ = 0;
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    draw_background(this);
    iVar4 = this->_padding_;
    (**(code **)(iVar4 + 0x28))(0);
    pvVar1 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_pnl_txt__draw);
    if (pvVar1 != (void *)0x0) {
      SelectClipRgn(pvVar1,this->_padding_);
      uVar2 = SelectObject(pvVar1,this->font);
      SetBkMode(pvVar1,1);
      sVar3 = this->top_line;
      if (sVar3 <= this->bot_line) {
        do {
          if (((this->_padding_ == 0) || (this->_padding_ == 0)) && (this->_padding_ == 0)) {
            uVar7 = this->text_color2;
            uVar6 = this->text_color1;
          }
          else {
            uVar7 = this->highlightTextColor2;
            uVar6 = this->highlightTextColor1;
          }
          draw_line(this,pvVar1,sVar5,sVar3,uVar6,uVar7);
          sVar3 = sVar3 + 1;
          sVar5 = sVar5 + 1;
        } while (sVar3 <= this->bot_line);
      }
      SelectObject(pvVar1,uVar2);
      SelectClipRgn(pvVar1,0);
      TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_pnl_txt__draw);
      iVar4 = iStack_8;
    }
    draw_border(this);
    (**(code **)(iVar4 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: draw_background
// Address: 0047d3d0
// [HELPER] s_pnl_txt__draw_background2: "pnl_txt::draw_background2"
// [HELPER] s_pnl_txt__draw_background: "pnl_txt::draw_background"
/* WARNING: Variable defined which should be unmapped: pic_cols */
/* public: void __thiscall TTextPanel::draw_background(void) */

void __thiscall TTextPanel::draw_background(TTextPanel *this)
{
  int *piVar1;
  uchar *puVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  short pic_cols;
  short local_8;
  int local_4;
  
  sVar4 = 0;
  if (this->back_pic == (TShape *)0x0) {
    if (this->fill_back == 0) {
      piVar1 = (int *)this->_padding_;
      if (piVar1 != (int *)0x0) {
        if ((1 < this->bevel_type) && (this->bevel_type < 8)) {
          (**(code **)(*piVar1 + 0x3c))(&this->_padding_);
          return;
        }
        if (piVar1[0x21] == 0) {
          (**(code **)(*piVar1 + 0x34))(&this->_padding_);
        }
      }
    }
    else {
      puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_pnl_txt__draw_background2,1);
      if (puVar2 != (uchar *)0x0) {
        TDrawArea::FillRect((TDrawArea *)this->_padding_,this->_padding_,this->_padding_,
                            this->_padding_ + -1 + this->_padding_,
                            this->_padding_ + -1 + this->_padding_,this->back_color);
        TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_txt__draw_background2);
        return;
      }
    }
  }
  else {
    puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_pnl_txt__draw_background,1);
    if (puVar2 != (uchar *)0x0) {
      iVar3 = (int)this->back_pic_wid;
      iVar5 = this->_padding_;
      if (iVar3 < iVar5) {
        local_8 = (short)(iVar5 / iVar3);
        if (local_8 * iVar3 < iVar5) {
          local_8 = local_8 + 1;
        }
      }
      else {
        local_8 = 1;
      }
      iVar3 = (int)this->back_pic_hgt;
      iVar5 = this->_padding_;
      if ((iVar5 <= iVar3) && (sVar4 = (short)(iVar5 / iVar3), sVar4 * iVar3 < iVar5)) {
        sVar4 = sVar4 + 1;
      }
      if (0 < sVar4) {
        local_4 = (int)sVar4;
        iVar5 = 0;
        do {
          if (0 < local_8) {
            iVar6 = 0;
            iVar3 = (int)local_8;
            do {
              TShape::shape_draw(this->back_pic,(TDrawArea *)this->_padding_,
                                 iVar6 * this->back_pic_wid + this->_padding_,
                                 iVar5 * this->back_pic_hgt + this->_padding_,0,'\0',(uchar *)0x0);
              iVar6 = iVar6 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          iVar5 = iVar5 + 1;
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
      TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_txt__draw_background);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: draw_border
// Address: 0047d570
// [HELPER] s_pnl_txt__draw_border: "pnl_txt::draw_border"
/* public: void __thiscall TTextPanel::draw_border(void) */

void __thiscall TTextPanel::draw_border(TTextPanel *this)
{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uchar uVar6;
  uchar *puVar7;
  int iVar8;
  int iVar9;
  
  if (this->bevel_type == 0) {
    return;
  }
  puVar7 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_pnl_txt__draw_border,1);
  if (puVar7 == (uchar *)0x0) goto switchD_0047d5a8_default;
  switch(this->bevel_type) {
  case 1:
    TDrawArea::DrawRect((TDrawArea *)this->_padding_,this->_padding_,this->_padding_,
                        this->_padding_ + -1 + this->_padding_,
                        this->_padding_ + -1 + this->_padding_,this->outline_color);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_txt__draw_border);
    return;
  case 2:
    uVar1 = this->bevel_color1;
    iVar8 = this->_padding_;
    iVar9 = this->_padding_;
    uVar2 = this->bevel_color6;
    goto LAB_0047d667;
  case 3:
    uVar1 = this->bevel_color1;
    iVar8 = this->_padding_;
    iVar9 = this->_padding_;
    uVar2 = this->bevel_color2;
    uVar3 = this->bevel_color5;
    uVar4 = this->bevel_color6;
    goto LAB_0047d6b2;
  case 4:
    uVar1 = this->bevel_color1;
    iVar8 = this->_padding_;
    uVar2 = this->bevel_color2;
    uVar3 = this->bevel_color3;
    iVar9 = this->_padding_;
    uVar4 = this->bevel_color4;
    uVar5 = this->bevel_color5;
    uVar6 = this->bevel_color6;
    break;
  case 5:
    uVar1 = this->bevel_color6;
    iVar8 = this->_padding_;
    iVar9 = this->_padding_;
    uVar2 = this->bevel_color1;
LAB_0047d667:
    TDrawArea::DrawBevel
              ((TDrawArea *)this->_padding_,iVar9,iVar8,this->_padding_ + -1 + iVar9,
               this->_padding_ + -1 + iVar8,uVar2,uVar1);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_txt__draw_border);
    return;
  case 6:
    uVar1 = this->bevel_color6;
    iVar8 = this->_padding_;
    iVar9 = this->_padding_;
    uVar2 = this->bevel_color5;
    uVar3 = this->bevel_color2;
    uVar4 = this->bevel_color1;
LAB_0047d6b2:
    TDrawArea::DrawBevel2
              ((TDrawArea *)this->_padding_,iVar9,iVar8,this->_padding_ + -1 + iVar9,
               this->_padding_ + -1 + iVar8,uVar4,uVar3,uVar2,uVar1);
    TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_txt__draw_border);
    return;
  case 7:
    uVar1 = this->bevel_color6;
    iVar8 = this->_padding_;
    uVar2 = this->bevel_color5;
    uVar3 = this->bevel_color4;
    iVar9 = this->_padding_;
    uVar4 = this->bevel_color3;
    uVar5 = this->bevel_color2;
    uVar6 = this->bevel_color1;
    break;
  default:
    goto switchD_0047d5a8_default;
  }
  TDrawArea::DrawBevel3
            ((TDrawArea *)this->_padding_,iVar9,iVar8,this->_padding_ + -1 + iVar9,
             this->_padding_ + -1 + iVar8,uVar6,uVar5,uVar4,uVar3,uVar2,uVar1);
switchD_0047d5a8_default:
  TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_txt__draw_border);
  return;
}

// --------------------------------------------------

// Function: draw_line
// Address: 0047d760
/* WARNING: Variable defined which should be unmapped: text_len */
/* public: void __thiscall TTextPanel::draw_line(void *,short,short,unsigned long,unsigned long) */

void __thiscall
TTextPanel::draw_line
          (TTextPanel *this,void *param_1,short param_2,short param_3,ulong param_4,ulong param_5)
{
  char cVar1;
  Style SVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  short text_len;
  char *temp_text2;
  short text2_len;
  short local_18;
  tagRECT line_rect;
  
  temp_text2._0_2_ = 0;
  local_18 = 0;
  line_rect.left = (long)this;
  pcVar5 = get_text(this,(int)param_3);
  pcVar6 = get_text2(this,(int)param_3);
  if (pcVar5 == (char *)0x0) {
    if (pcVar6 == (char *)0x0) {
      return;
    }
  }
  else {
    iVar7 = -1;
    pcVar8 = pcVar5;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    temp_text2._0_2_ = ~(ushort)iVar7 - 1;
  }
  if (pcVar6 != (char *)0x0) {
    iVar7 = -1;
    pcVar8 = pcVar6;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    local_18 = ~(ushort)iVar7 - 1;
  }
  calc_line_pos(this,param_1,param_2,param_3,(tagRECT *)&line_rect.top,(long *)0x0);
  _param_3 = line_rect.top;
  if ((this->horz_align != AlignCenter) && (this->horz_align != AlignWordwrap)) {
    _param_3 = line_rect.top + 5;
  }
  iVar7 = this->second_column_pos + _param_3;
  if (this->clip_rgn2 != (void *)0x0) {
    SelectClipRgn(param_1,this->clip_rgn2);
  }
  SVar2 = this->text_style;
  if (SVar2 == NormalStyle) {
    SetTextColor(param_1,param_4);
  }
  else if (SVar2 == BeveledStyle) {
    SetTextColor(param_1,param_4);
    if (pcVar5 != (char *)0x0) {
      TextOutA(param_1,_param_3 + -1,line_rect.right + 1,pcVar5,(int)(short)temp_text2);
    }
    SetTextColor(param_1,param_5);
  }
  else {
    if (SVar2 != ChiseledStyle) goto LAB_0047d8dd;
    SetTextColor(param_1,param_5);
    if (pcVar5 != (char *)0x0) {
      TextOutA(param_1,_param_3 + -1,line_rect.right + 1,pcVar5,(int)(short)temp_text2);
    }
    SetTextColor(param_1,param_4);
  }
  if (pcVar5 != (char *)0x0) {
    TextOutA(param_1,_param_3,line_rect.right,pcVar5,(int)(short)temp_text2);
  }
LAB_0047d8dd:
  lVar4 = line_rect.left;
  if (pcVar6 != (char *)0x0) {
    if (*(int *)(line_rect.left + 0x17c) != 0) {
      SelectClipRgn(param_1,*(undefined4 *)(line_rect.left + 0x88));
    }
    iVar3 = *(int *)(lVar4 + 0x11c);
    if (iVar3 == 0) {
      SetTextColor(param_1,param_4);
      TextOutA(param_1,iVar7,line_rect.right,pcVar6,(int)local_18);
    }
    else {
      if (iVar3 == 1) {
        SetTextColor(param_1,param_4);
        TextOutA(param_1,iVar7 + -1,line_rect.right + 1,pcVar6,(int)local_18);
        SetTextColor(param_1,param_5);
        TextOutA(param_1,iVar7,line_rect.right,pcVar6,(int)local_18);
        return;
      }
      if (iVar3 == 2) {
        SetTextColor(param_1,param_5);
        TextOutA(param_1,iVar7 + -1,line_rect.right + 1,pcVar6,(int)local_18);
        SetTextColor(param_1,param_4);
        TextOutA(param_1,iVar7,line_rect.right,pcVar6,(int)local_18);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: calc_line_pos
// Address: 0047d9e0
/* WARNING: Variable defined which should be unmapped: col_offset */
/* public: void __thiscall TTextPanel::calc_line_pos(void *,short,short,struct tagRECT *,long *) */

void __thiscall
TTextPanel::calc_line_pos
          (TTextPanel *this,void *param_1,short param_2,short param_3,tagRECT *param_4,long *param_5
          )
{
  char cVar1;
  short sVar2;
  Alignment AVar3;
  ushort uVar4;
  short sVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  long col_offset;
  tagSIZE text_size;
  char temp_text2 [256];
  
  pcVar6 = get_text(this,(int)param_3);
  if (pcVar6 == (char *)0x0) {
    text_size.cx = 0;
    text_size.cy = 0;
  }
  else {
    if (this->cur_col == 0) {
      text_size.cx = 0;
    }
    else {
      sVar5 = __mbslen(pcVar6);
      sVar2 = this->cur_col;
      if (sVar5 < sVar2) {
        iVar8 = -1;
        pcVar10 = pcVar6;
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        uVar4 = (ushort)iVar8;
      }
      else {
        pcVar10 = temp_text2;
        for (iVar8 = 0x40; pcVar10 = pcVar10 + 4, iVar8 != 0; iVar8 = iVar8 + -1) {
          pcVar10[0] = '\0';
          pcVar10[1] = '\0';
          pcVar10[2] = '\0';
          pcVar10[3] = '\0';
        }
        __mbsncpy(temp_text2 + 4,pcVar6,(int)sVar2);
        iVar8 = -1;
        pcVar10 = temp_text2 + 4;
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        uVar4 = (ushort)iVar8;
      }
      GetTextExtentPoint32A(param_1,pcVar6,(int)(short)(~uVar4 - 1),&text_size.cy);
      text_size.cx = text_size.cy;
    }
    __mbslen(pcVar6);
    iVar8 = -1;
    pcVar10 = pcVar6;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    GetTextExtentPoint32A(param_1,pcVar6,(int)(short)(~(ushort)iVar8 - 1),&text_size.cy);
  }
  AVar3 = this->horz_align;
  if ((AVar3 != AlignCenter) && (AVar3 != AlignWordwrap)) {
    text_size.cx = text_size.cx + 5;
  }
  if (AVar3 == AlignLeft) {
    iVar8 = this->_padding_;
    iVar7 = this->border_size;
LAB_0047db35:
    iVar8 = iVar8 + iVar7;
  }
  else if (AVar3 == AlignRight) {
    iVar8 = (((this->_padding_ + this->_padding_) - this->border_size) - text_size.cy) + -7;
  }
  else {
    if (AVar3 != AlignHorizontalScroll) {
      iVar8 = this->_padding_ - text_size.cy / 2;
      iVar7 = this->_padding_ / 2;
      goto LAB_0047db35;
    }
    iVar8 = this->_padding_ + this->border_size;
    if (this->_padding_ <= text_size.cx + 1) {
      iVar8 = iVar8 + -2 + (this->_padding_ - text_size.cx);
    }
  }
  iVar7 = this->spacer_size;
  if (iVar7 == 0) {
    iVar9 = this->text_hgt;
  }
  else {
    iVar9 = this->text_hgt + -1 + iVar7 * 2;
  }
  if (this->vert_align == AlignTop) {
    iVar9 = param_2 * iVar9 + this->_padding_ + this->border_size;
  }
  else {
    if (this->vert_align == AlignBottom) {
      iVar9 = ((((this->_padding_ - ((int)this->num_lines - (int)param_2) * iVar9) + this->_padding_
                ) - this->border_size) - iVar7) + -1;
      goto LAB_0047dbcf;
    }
    iVar9 = (param_2 * iVar9 - (this->num_lines * iVar9) / 2) + this->_padding_;
    iVar7 = this->_padding_ / 2;
  }
  iVar9 = iVar9 + iVar7;
LAB_0047dbcf:
  param_4->left = iVar8;
  param_4->top = iVar9;
  param_4->right = text_size.cy + -1 + iVar8;
  param_4->bottom = iVar9 + this->text_hgt;
  if (param_5 != (long *)0x0) {
    *param_5 = text_size.cx;
  }
  return;
}

// --------------------------------------------------

// Function: mouse_left_down_action
// Address: 0047dc10
/* public: virtual long __thiscall TTextPanel::mouse_left_down_action(long,long,int,int) */

long __thiscall
TTextPanel::mouse_left_down_action
          (TTextPanel *this,long param_1,long param_2,int param_3,int param_4)
{
  if ((int *)this->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)this->_padding_ + 0xb4))(this,1,0,0);
  }
  return 0;
}

// --------------------------------------------------

// Function: numberLines
// Address: 0047dc30
/* public: int __thiscall TTextPanel::numberLines(void)const  */

int __thiscall TTextPanel::numberLines(TTextPanel *this)
{
  return (int)this->num_lines;
}

// --------------------------------------------------

// Function: numberDrawLines
// Address: 0047dc40
/* public: int __thiscall TTextPanel::numberDrawLines(void)const  */

int __thiscall TTextPanel::numberDrawLines(TTextPanel *this)
{
  return (int)this->draw_lines;
}

// --------------------------------------------------

// Function: currentLineNumber
// Address: 0047dc50
/* public: int __thiscall TTextPanel::currentLineNumber(void)const  */

int __thiscall TTextPanel::currentLineNumber(TTextPanel *this)
{
  return (int)this->cur_line;
}

// --------------------------------------------------

// Function: setCurrentLineNumber
// Address: 0047dc60
/* public: void __thiscall TTextPanel::setCurrentLineNumber(int) */

void __thiscall TTextPanel::setCurrentLineNumber(TTextPanel *this,int param_1)
{
  set_line(this,param_1);
  return;
}

// --------------------------------------------------

// Function: currentLine
// Address: 0047dc70
/* public: char * __thiscall TTextPanel::currentLine(void) */

char * __thiscall TTextPanel::currentLine(TTextPanel *this)
{
  char *pcVar1;
  
  pcVar1 = get_text(this,(int)this->cur_line);
  return pcVar1;
}

// --------------------------------------------------

// Function: set_line
// Address: 0047dc80
/* public: void __thiscall TTextPanel::set_line(long) */

void __thiscall TTextPanel::set_line(TTextPanel *this,long param_1)
{
  this->cur_line = (short)param_1;
  calc_draw_info(this,1);
  return;
}

// --------------------------------------------------

// Function: set_line_by_id
// Address: 0047dca0
/* public: void __thiscall TTextPanel::set_line_by_id(long) */

void __thiscall TTextPanel::set_line_by_id(TTextPanel *this,long param_1)
{
  TextNode *pTVar1;
  int iVar2;
  
  pTVar1 = this->list;
  iVar2 = 0;
  if (pTVar1 != (TextNode *)0x0) {
    while (pTVar1->id != param_1) {
      pTVar1 = pTVar1->next_node;
      iVar2 = iVar2 + 1;
      if (pTVar1 == (TextNode *)0x0) {
        return;
      }
    }
    set_line(this,iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: append_line
// Address: 0047dcd0
/* public: int __thiscall TTextPanel::append_line(char *,long) */

int __thiscall TTextPanel::append_line(TTextPanel *this,char *param_1,long param_2)
{
  int iVar1;
  
  iVar1 = insert_line(this,(int)this->num_lines,param_1,param_2);
  return iVar1;
}

// --------------------------------------------------

// Function: append_line
// Address: 0047dcf0
/* public: int __thiscall TTextPanel::append_line(char *,char *,long) */

int __thiscall TTextPanel::append_line(TTextPanel *this,char *param_1,char *param_2,long param_3)
{
  int iVar1;
  
  iVar1 = insert_line(this,(int)this->num_lines,param_1,param_2,param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: append_line
// Address: 0047dd10
/* public: int __thiscall TTextPanel::append_line(long,long) */

int __thiscall TTextPanel::append_line(TTextPanel *this,long param_1,long param_2)
{
  int iVar1;
  
  iVar1 = insert_line(this,(int)this->num_lines,param_1,param_2);
  return iVar1;
}

// --------------------------------------------------

// Function: append_line
// Address: 0047dd30
/* public: int __thiscall TTextPanel::append_line(long,long,long) */

int __thiscall TTextPanel::append_line(TTextPanel *this,long param_1,long param_2,long param_3)
{
  int iVar1;
  
  iVar1 = insert_line(this,(int)this->num_lines,param_1,param_2,param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: insert_line
// Address: 0047dd50
/* public: int __thiscall TTextPanel::insert_line(long,char *,long) */

int __thiscall TTextPanel::insert_line(TTextPanel *this,long param_1,char *param_2,long param_3)
{
  int iVar1;
  
  iVar1 = insert_line(this,param_1,param_2,(char *)0x0,param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: insert_line
// Address: 0047dd70
/* public: int __thiscall TTextPanel::insert_line(long,char *,char *,long) */

int __thiscall
TTextPanel::insert_line(TTextPanel *this,long param_1,char *param_2,char *param_3,long param_4)
{
  char cVar1;
  TextNode *pTVar2;
  uint uVar3;
  char *pcVar4;
  TextNode *pTVar5;
  uint uVar6;
  int iVar7;
  TextNode *pTVar8;
  TextNode *pTVar9;
  char *pcVar10;
  
  pTVar2 = (TextNode *)calloc(1,0x10);
  if (pTVar2 == (TextNode *)0x0) {
    return 0;
  }
  if (this->fixed_len == 0) {
    if (param_2 == (char *)0x0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0xffffffff;
      pcVar4 = param_2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
    }
  }
  else {
    uVar3 = (int)this->fixed_len + 1;
  }
  pcVar4 = (char *)calloc(uVar3,1);
  pTVar2->text = pcVar4;
  if (pcVar4 == (char *)0x0) {
    free(pTVar2);
    return 0;
  }
  if (param_3 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar4 = param_3;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = (char *)calloc(~uVar3,1);
    pTVar2->text2 = pcVar4;
    if (pcVar4 == (char *)0x0) {
      free(pTVar2->text);
      free(pTVar2);
      return 0;
    }
  }
  if (param_2 == (char *)0x0) {
    *pTVar2->text = '\0';
  }
  else if (this->fixed_len == 0) {
    uVar3 = 0xffffffff;
    do {
      pcVar4 = param_2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar4 = param_2 + 1;
      cVar1 = *param_2;
      param_2 = pcVar4;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar4 = pcVar4 + -uVar3;
    pcVar10 = pTVar2->text;
    for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar10 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar10 = pcVar10 + 1;
    }
  }
  else {
    strncpy(pTVar2->text,param_2,(int)this->fixed_len);
    pTVar2->text[this->fixed_len] = '\0';
  }
  if (param_3 != (char *)0x0) {
    uVar3 = 0xffffffff;
    do {
      pcVar4 = param_3;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar4 = param_3 + 1;
      cVar1 = *param_3;
      param_3 = pcVar4;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar4 = pcVar4 + -uVar3;
    pcVar10 = pTVar2->text2;
    for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar10 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar10 = pcVar10 + 1;
    }
  }
  pTVar2->id = param_4;
  iVar7 = 0;
  pTVar2->next_node = (TextNode *)0x0;
  pTVar5 = this->list;
  if (pTVar5 == (TextNode *)0x0) {
    this->list = pTVar2;
  }
  else if (this->sorted == 0) {
    if (param_1 == 0) {
      pTVar2->next_node = pTVar5;
      this->list = pTVar2;
    }
    else if (param_1 < this->num_lines) {
      for (; iVar7 != param_1 + -1; iVar7 = iVar7 + 1) {
        pTVar5 = pTVar5->next_node;
      }
      pTVar2->next_node = pTVar5->next_node;
      pTVar5->next_node = pTVar2;
    }
    else {
      do {
        pTVar8 = pTVar5;
        pTVar5 = pTVar8->next_node;
      } while (pTVar5 != (TextNode *)0x0);
      pTVar8->next_node = pTVar2;
    }
  }
  else {
    pTVar8 = (TextNode *)0x0;
    if (pTVar5 != (TextNode *)0x0) {
      do {
        iVar7 = CompareStringA(0x400,1,pTVar2->text,0xffffffff,pTVar5->text,0xffffffff);
        if (iVar7 == 1) {
          pTVar2->next_node = pTVar5;
          pTVar9 = pTVar5;
          if (pTVar8 == (TextNode *)0x0) {
            this->list = pTVar2;
          }
          else {
            pTVar8->next_node = pTVar2;
          }
          break;
        }
        pTVar9 = pTVar5->next_node;
        pTVar8 = pTVar5;
        pTVar5 = pTVar9;
      } while (pTVar9 != (TextNode *)0x0);
      if (pTVar9 != (TextNode *)0x0) goto LAB_0047df25;
    }
    pTVar8->next_node = pTVar2;
  }
LAB_0047df25:
  this->num_lines = this->num_lines + 1;
  calc_draw_info(this,1);
  (**(code **)(this->_padding_ + 0x20))(1);
  return 1;
}

// --------------------------------------------------

// Function: insert_line
// Address: 0047df90
/* WARNING: Variable defined which should be unmapped: str */
/* public: int __thiscall TTextPanel::insert_line(long,long,long) */

int __thiscall TTextPanel::insert_line(TTextPanel *this,long param_1,long param_2,long param_3)
{
  int iVar1;
  char str [256];
  
  TPanel::get_string((TPanel *)this,param_2,str + 4,0x100);
  iVar1 = insert_line(this,param_1,str + 4,param_3);
  return iVar1;
}

// --------------------------------------------------

// Function: insert_line
// Address: 0047dfe0
/* WARNING: Variable defined which should be unmapped: str2 */
/* public: int __thiscall TTextPanel::insert_line(long,long,long,long) */

int __thiscall
TTextPanel::insert_line(TTextPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  int iVar1;
  char str2 [256];
  char str1 [256];
  
  TPanel::get_string((TPanel *)this,param_2,str1 + 4,0x100);
  TPanel::get_string((TPanel *)this,param_3,str2 + 4,0x100);
  iVar1 = insert_line(this,param_1,str1 + 4,str2 + 4,param_4);
  return iVar1;
}

// --------------------------------------------------

// Function: change_line
// Address: 0047e050
/* public: int __thiscall TTextPanel::change_line(long,char *,char *,long) */

int __thiscall
TTextPanel::change_line(TTextPanel *this,long param_1,char *param_2,char *param_3,long param_4)
{
  int iVar1;
  int iVar2;
  
  iVar1 = this->sorted;
  this->sorted = 0;
  iVar2 = insert_line(this,param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    this->sorted = iVar1;
    return 0;
  }
  delete_line(this,param_1 + 1);
  this->sorted = iVar1;
  return 1;
}

// --------------------------------------------------

// Function: change_line
// Address: 0047e0b0
/* public: int __thiscall TTextPanel::change_line(long,long,long,long) */

int __thiscall
TTextPanel::change_line(TTextPanel *this,long param_1,long param_2,long param_3,long param_4)
{
  int iVar1;
  int iVar2;
  
  iVar1 = this->sorted;
  this->sorted = 0;
  iVar2 = insert_line(this,param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    this->sorted = iVar1;
    return 0;
  }
  delete_line(this,param_1 + 1);
  this->sorted = iVar1;
  return 1;
}

// --------------------------------------------------

// Function: delete_line
// Address: 0047e110
/* public: int __thiscall TTextPanel::delete_line(long) */

int __thiscall TTextPanel::delete_line(TTextPanel *this,long param_1)
{
  short sVar1;
  TextNode *pTVar2;
  int iVar3;
  TextNode *pTVar4;
  
  if ((-1 < param_1) && (param_1 <= this->num_lines + -1)) {
    if (param_1 == 0) {
      pTVar4 = this->list;
      this->list = pTVar4->next_node;
    }
    else {
      pTVar2 = this->list;
      for (iVar3 = 0; iVar3 != param_1 + -1; iVar3 = iVar3 + 1) {
        pTVar2 = pTVar2->next_node;
      }
      pTVar4 = pTVar2->next_node;
      pTVar2->next_node = pTVar4->next_node;
    }
    if (pTVar4 != (TextNode *)0x0) {
      if (pTVar4->text != (char *)0x0) {
        free(pTVar4->text);
      }
      if (pTVar4->text2 != (char *)0x0) {
        free(pTVar4->text2);
      }
      free(pTVar4);
      this->num_lines = this->num_lines + -1;
      sVar1 = this->num_lines;
      if (sVar1 == 0) {
        this->cur_line = 0;
      }
      else if (sVar1 <= this->cur_line) {
        this->cur_line = sVar1 + -1;
      }
      calc_draw_info(this,1);
      (**(code **)(this->_padding_ + 0x20))(1);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: get_line
// Address: 0047e1e0
/* public: long __thiscall TTextPanel::get_line(void) */

long __thiscall TTextPanel::get_line(TTextPanel *this)
{
  if (this->num_lines == 0) {
    return -1;
  }
  return (int)this->cur_line;
}

// --------------------------------------------------

// Function: get_line
// Address: 0047e200
/* public: long __thiscall TTextPanel::get_line(long) */

long __thiscall TTextPanel::get_line(TTextPanel *this,long param_1)
{
  TextNode *pTVar1;
  int iVar2;
  
  pTVar1 = this->list;
  iVar2 = 0;
  while( true ) {
    if (pTVar1 == (TextNode *)0x0) {
      return -1;
    }
    if (pTVar1->id == param_1) break;
    pTVar1 = pTVar1->next_node;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

// --------------------------------------------------

// Function: get_line
// Address: 0047e230
/* public: long __thiscall TTextPanel::get_line(char *) */

long __thiscall TTextPanel::get_line(TTextPanel *this,char *param_1)
{
  byte bVar1;
  TextNode *pTVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  
  pTVar2 = this->list;
  iVar3 = 0;
  do {
    if (pTVar2 == (TextNode *)0x0) {
      return -1;
    }
    pbVar4 = (byte *)pTVar2->text;
    pbVar6 = (byte *)param_1;
    do {
      bVar1 = *pbVar4;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_0047e26c:
        iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_0047e271;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_0047e26c;
      pbVar4 = pbVar4 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_0047e271:
    if (iVar5 == 0) {
      return iVar3;
    }
    pTVar2 = pTVar2->next_node;
    iVar3 = iVar3 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: get_text
// Address: 0047e290
/* public: char * __thiscall TTextPanel::get_text(void) */

char * __thiscall TTextPanel::get_text(TTextPanel *this)
{
  char *pcVar1;
  
  pcVar1 = get_text(this,(int)this->cur_line);
  return pcVar1;
}

// --------------------------------------------------

// Function: get_text
// Address: 0047e2a0
/* public: char * __thiscall TTextPanel::get_text(long) */

char * __thiscall TTextPanel::get_text(TTextPanel *this,long param_1)
{
  TextNode *pTVar1;
  int iVar2;
  
  pTVar1 = this->list;
  iVar2 = 0;
  if (pTVar1 == (TextNode *)0x0) {
    DAT_0086b24c._4_1_ = 0;
    return (char *)((int)&DAT_0086b24c + 4);
  }
  do {
    if (iVar2 == param_1) {
      return pTVar1->text;
    }
    pTVar1 = pTVar1->next_node;
    iVar2 = iVar2 + 1;
  } while (pTVar1 != (TextNode *)0x0);
  DAT_0086b24c._4_1_ = 0;
  return (char *)((int)&DAT_0086b24c + 4);
}

// --------------------------------------------------

// Function: get_text2
// Address: 0047e2e0
/* public: char * __thiscall TTextPanel::get_text2(void) */

char * __thiscall TTextPanel::get_text2(TTextPanel *this)
{
  char *pcVar1;
  
  pcVar1 = get_text2(this,(int)this->cur_line);
  return pcVar1;
}

// --------------------------------------------------

// Function: get_text2
// Address: 0047e2f0
/* public: char * __thiscall TTextPanel::get_text2(long) */

char * __thiscall TTextPanel::get_text2(TTextPanel *this,long param_1)
{
  TextNode *pTVar1;
  int iVar2;
  
  pTVar1 = this->list;
  iVar2 = 0;
  if (pTVar1 == (TextNode *)0x0) {
    DAT_0086b24c._0_1_ = 0;
    return (char *)&DAT_0086b24c;
  }
  do {
    if (iVar2 == param_1) {
      return pTVar1->text2;
    }
    pTVar1 = pTVar1->next_node;
    iVar2 = iVar2 + 1;
  } while (pTVar1 != (TextNode *)0x0);
  DAT_0086b24c._0_1_ = 0;
  return (char *)&DAT_0086b24c;
}

// --------------------------------------------------

// Function: get_id
// Address: 0047e330
/* public: long __thiscall TTextPanel::get_id(void) */

long __thiscall TTextPanel::get_id(TTextPanel *this)
{
  long lVar1;
  
  lVar1 = get_id(this,(int)this->cur_line);
  return lVar1;
}

// --------------------------------------------------

// Function: get_id
// Address: 0047e340
/* public: long __thiscall TTextPanel::get_id(long) */

long __thiscall TTextPanel::get_id(TTextPanel *this,long param_1)
{
  TextNode *pTVar1;
  int iVar2;
  
  pTVar1 = this->list;
  iVar2 = 0;
  if (pTVar1 == (TextNode *)0x0) {
    return -1;
  }
  do {
    if (iVar2 == param_1) {
      return pTVar1->id;
    }
    pTVar1 = pTVar1->next_node;
    iVar2 = iVar2 + 1;
  } while (pTVar1 != (TextNode *)0x0);
  return -1;
}

// --------------------------------------------------

// Function: empty_list
// Address: 0047e370
/* public: void __thiscall TTextPanel::empty_list(void) */

void __thiscall TTextPanel::empty_list(TTextPanel *this)
{
  TextNode *pTVar1;
  TextNode *pTVar2;
  
  pTVar2 = this->list;
  if (this->list != (TextNode *)0x0) {
    do {
      if (pTVar2->text != (char *)0x0) {
        free(pTVar2->text);
      }
      if (pTVar2->text2 != (char *)0x0) {
        free(pTVar2->text2);
      }
      pTVar1 = pTVar2->next_node;
      free(pTVar2);
      pTVar2 = pTVar1;
    } while (pTVar1 != (TextNode *)0x0);
    this->list = (TextNode *)0x0;
  }
  this->num_lines = 0;
  calc_draw_info(this,1);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: free_text
// Address: 0047e380
/* public: void __thiscall TTextPanel::free_text(void) */

void __thiscall TTextPanel::free_text(TTextPanel *this)
{
  TextNode *pTVar1;
  TextNode *pTVar2;
  
  pTVar2 = this->list;
  if (this->list != (TextNode *)0x0) {
    do {
      if (pTVar2->text != (char *)0x0) {
        free(pTVar2->text);
      }
      if (pTVar2->text2 != (char *)0x0) {
        free(pTVar2->text2);
      }
      pTVar1 = pTVar2->next_node;
      free(pTVar2);
      pTVar2 = pTVar1;
    } while (pTVar1 != (TextNode *)0x0);
    this->list = (TextNode *)0x0;
  }
  this->num_lines = 0;
  calc_draw_info(this,1);
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: set_second_column_pos
// Address: 0047e3f0
/* public: void __thiscall TTextPanel::set_second_column_pos(long) */

void __thiscall TTextPanel::set_second_column_pos(TTextPanel *this,long param_1)
{
  this->second_column_pos = param_1;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: get_text_rect
// Address: 0047e410
// [HELPER] s_pnl_txt__get_text_rect: "pnl_txt::get_text_rect"
/* public: int __thiscall TTextPanel::get_text_rect(struct tagRECT *) */

int __thiscall TTextPanel::get_text_rect(TTextPanel *this,tagRECT *param_1)
{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = TDrawArea::GetDc((TDrawArea *)this->_padding_,s_pnl_txt__get_text_rect);
  if (pvVar1 != (void *)0x0) {
    uVar2 = SelectObject(pvVar1,this->font);
    calc_line_pos(this,pvVar1,0,0,param_1,(long *)0x0);
    SelectObject(pvVar1,uVar2);
    TDrawArea::ReleaseDc((TDrawArea *)this->_padding_,s_pnl_txt__get_text_rect);
    return 1;
  }
  return 0;
}

// --------------------------------------------------


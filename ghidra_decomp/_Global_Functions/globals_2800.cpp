// GLOBAL FUNCTIONS PART 2800
// Function: FUN_00473d5b
// Address: 00473d5b
undefined4 __thiscall
FUN_00473d5b(TEasy_Panel *param_1,TDrawArea *param_2,TPanel *param_3,int param_4,int param_5,
            undefined4 param_6,int param_7)
{
  TPanel *this;
  int iVar1;
  int iVar2;
  long lVar3;
  
  if (param_3 == (TPanel *)0x0) {
    iVar1 = param_2->Width;
    iVar2 = param_2->Height;
  }
  else {
    iVar1 = TPanel::width(param_3);
    iVar2 = TPanel::height(param_3);
  }
  lVar3 = TEasy_Panel::setup(param_1,param_2,param_3,(char *)0x0,-1,0,iVar1 / 2 - param_4 / 2,
                             iVar2 / 2 - param_5 / 2,param_4,param_5,param_7);
  if (lVar3 == 0) {
    param_1->_padding_ = 1;
    return 0;
  }
  (**(code **)(param_1->_padding_ + 0x10))(param_6);
  TPanel::set_z_order((TPanel *)param_1,'\x01',0);
  TPanelSystem::setModalPanel(&panel_system,(TPanel *)param_1);
  this = (TPanel *)param_1->_padding_;
  if (this != (TPanel *)0x0) {
    param_1[1]._padding_ = (int)this->curr_child;
    TPanel::set_curr_child(this,(TPanel *)param_1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00473e33
// Address: 00473e33
void __fastcall FUN_00473e33(TEasy_Panel *param_1)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e3e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TDialogPanel::_vftable_;
  uStack_4 = 0;
  iVar1 = TPanelSystem::restorePreviousModalPanel(&panel_system);
  if (iVar1 == 0) {
    TPanelSystem::setModalPanel(&panel_system,(TPanel *)0x0);
  }
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0x20))(2);
    TPanel::set_curr_child((TPanel *)param_1->_padding_,(TPanel *)param_1[1]._padding_);
  }
  uStack_4 = 0xffffffff;
  TEasy_Panel::~TEasy_Panel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00473ecd
// Address: 00473ecd
TPanel * __fastcall FUN_00473ecd(TPanel *param_1)
{
  TPanel::TPanel(param_1);
  param_1->_padding_ = (int)&TDropDownPanel::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1].previousPanelValue = (TPanel *)0x0;
  param_1[1].previousModalPanelValue = (TPanel *)0x0;
  param_1[1].pnl_x = 0;
  param_1[1].pnl_y = 0;
  *(undefined2 *)&param_1[1].pnl_wid = 0;
  *(undefined1 *)&param_1[1].curr_child = 0;
  param_1[1].top_panel = (TPanel *)0x0;
  param_1->panel_type = '\x06';
  param_1[1].right_panel = (TPanel *)0x1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00473f26
// Address: 00473f26
TDropDownPanel * __thiscall FUN_00473f26(TDropDownPanel *param_1,byte param_2)
{
  TDropDownPanel::~TDropDownPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00473f4e
// Address: 00473f4e
void __fastcall FUN_00473f4e(TPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e408;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TDropDownPanel::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel(param_1,&param_1[1].previousPanelValue);
  TPanel::delete_panel(param_1,&param_1[1].previousModalPanelValue);
  TPanel::delete_panel(param_1,(TPanel **)&param_1[1].pnl_x);
  TPanel::delete_panel(param_1,(TPanel **)(param_1 + 1));
  uStack_4 = 0xffffffff;
  TPanel::~TPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00474331
// Address: 00474331
void __fastcall FUN_00474331(int param_1)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (((*(TDrawArea **)(param_1 + 0x20) != (TDrawArea *)0x0) && (*(int *)(param_1 + 0x70) != 0)) &&
     (*(int *)(param_1 + 0x6c) != 0)) {
    if ((*(char *)(param_1 + 0xf0) == '\0') && (*(int **)(param_1 + 0x40) != (int *)0x0)) {
      iVar1 = **(int **)(param_1 + 0x40);
      if (*(char *)(param_1 + 0xf2) != '\0') {
        (**(code **)(iVar1 + 0x3c))(param_1 + 0x24);
        return;
      }
      (**(code **)(iVar1 + 0x34))(param_1 + 0x24);
      return;
    }
    TDrawArea::Clear(*(TDrawArea **)(param_1 + 0x20),(tagRECT *)(param_1 + 0x24),
                     (uint)*(byte *)(param_1 + 0xef));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00474345
// Address: 00474345
long __thiscall
FUN_00474345(TDropDownPanel *param_1,uchar param_2,long param_3,long param_4,int param_5,int param_6
            )
{
  int iVar1;
  int iVar2;
  long lVar3;
  
  if ((param_1->_padding_ != 0) && ((TPanel *)param_1->_padding_ != (TPanel *)0x0)) {
    TPanel::set_curr_child((TPanel *)param_1->_padding_,(TPanel *)param_1);
  }
  if (param_1->mode == ModeList) {
    iVar1 = (**(code **)(param_1->list_panel->_padding_ + 0xbc))(param_3,param_4);
    if (param_1->scbar_panel == (TScrollBarPanel *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (**(code **)(param_1->scbar_panel->_padding_ + 0xbc))(param_3,param_4);
    }
    if ((iVar1 == 0) && (iVar2 == 0)) {
      TDropDownPanel::set_mode(param_1,ModeValue);
      TDropDownPanel::set_line(param_1,(int)param_1->val_num);
      return 1;
    }
  }
  lVar3 = TPanel::handle_mouse_down((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6);
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_004743f2
// Address: 004743f2
void __thiscall FUN_004743f2(TPanel *param_1,long param_2,long param_3,int param_4,int param_5)
{
  TPanel::handle_mouse_move(param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0047441c
// Address: 0047441c
void __thiscall
FUN_0047441c(TPanel *param_1,uchar param_2,long param_3,long param_4,int param_5,int param_6)
{
  TPanel::handle_mouse_up(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_00474441
// Address: 00474441
long __thiscall
FUN_00474441(TDropDownPanel *param_1,int param_2,short param_3,int param_4,int param_5,int param_6)
{
  long lVar1;
  
  if ((param_1->_padding_ != 0) &&
     (((param_2 == 0x28 || (param_2 == 0x26)) && (param_1->mode == ModeValue)))) {
    TDropDownPanel::set_mode(param_1,ModeList);
    return 1;
  }
  lVar1 = TPanel::handle_key_down((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_0047449a
// Address: 0047449a
void __thiscall
FUN_0047449a(TDropDownPanel *param_1,TButtonPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == param_1->btn_panel) {
    if ((param_3 == 2) && (param_1->mode == ModeValue)) {
      TDropDownPanel::set_mode(param_1,ModeList);
    }
  }
  else if ((param_2 == (TButtonPanel *)param_1->list_panel) && ((param_3 == 3 || (param_3 == 2)))) {
    param_1->val_num = (short)param_4;
    iVar1 = param_1->val_panel->_padding_;
    pcVar2 = TTextPanel::get_text((TTextPanel *)param_1->list_panel,(int)(short)param_4);
    (**(code **)(iVar1 + 0xe8))(pcVar2);
    TDropDownPanel::set_mode(param_1,ModeValue);
    if ((int *)param_1->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,0,0,0);
    }
  }
  TPanel::action((TPanel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_00474542
// Address: 00474542
void __thiscall
FUN_00474542(TDropDownPanel *param_1,long param_2,long param_3,long param_4,long param_5)
{
  TPanel::set_rect((TPanel *)param_1,param_2,param_3,param_4,param_5);
  if (param_1->mode == ModeValue) {
    param_1->val_wid = (param_1->_padding_ - param_1->btn_wid) + -1;
    param_1->val_hgt = param_1->_padding_;
    TDropDownPanel::set_mode(param_1,ModeNone);
    TDropDownPanel::set_mode(param_1,ModeValue);
    return;
  }
  if (param_1->mode == ModeList) {
    param_1->list_wid = param_1->_padding_;
    param_1->list_hgt = (param_1->_padding_ - param_1->val_hgt) + -1;
    TDropDownPanel::set_mode(param_1,ModeValue);
    TDropDownPanel::set_mode(param_1,ModeList);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004745fc
// Address: 004745fc
void __thiscall FUN_004745fc(TDropDownPanel *param_1,DrawStyle param_2)
{
  DropdownMode DVar1;
  
  param_1->draw_style = param_2;
  if (param_1->val_panel != (TTextPanel *)0x0) {
    DVar1 = param_1->mode;
    param_1->mode = ModeNone;
    TDropDownPanel::set_mode(param_1,DVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047462d
// Address: 0047462d
void __thiscall FUN_0047462d(int *param_1,int param_2)
{
  param_1[0x50] = param_2;
  if ((TTextPanel *)param_1[0x3d] != (TTextPanel *)0x0) {
    TTextPanel::set_outline((TTextPanel *)param_1[0x3d],param_2,(uchar)param_1[0x4e]);
    (**(code **)(*param_1 + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00474661
// Address: 00474661
void __thiscall
FUN_00474661(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int **)(param_1 + 0xf4) != (int *)0x0) {
    switch(param_2) {
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
    (**(code **)(**(int **)(param_1 + 0xf4) + 0xec))
              (uVar1,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  if (*(int **)(param_1 + 0xfc) != (int *)0x0) {
    switch(param_2) {
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
    (**(code **)(**(int **)(param_1 + 0xfc) + 0xec))
              (uVar1,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  if (*(TScrollBarPanel **)(param_1 + 0x100) != (TScrollBarPanel *)0x0) {
    switch(param_2) {
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
              (*(TScrollBarPanel **)(param_1 + 0x100),iVar2,param_3,param_4,param_5,param_6,param_7,
               param_8);
  }
  if (*(TButtonPanel **)(param_1 + 0xf8) != (TButtonPanel *)0x0) {
    switch(param_2) {
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
              (*(TButtonPanel **)(param_1 + 0xf8),iVar2,param_3,param_4,param_5,param_6,param_7,
               param_8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004747db
// Address: 004747db
void __fastcall
FUN_004747db(int param_1,char *param_2,undefined4 param_3,undefined4 param_4,TShape *param_5,
            short param_6,int param_7,int param_8,int param_9,int param_10)
{
  char *pcVar1;
  int in_EAX;
  int iVar2;
  char *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  TShape *pTVar4;
  char cVar3;
  
  pcVar1 = (char *)(unaff_ESI + 0x46ab0048 + in_EAX * 2);
  cVar3 = (char)((uint)in_EAX >> 8);
  *pcVar1 = *pcVar1 + cVar3;
  param_2[-0xaffb8ba] = param_2[-0xaffb8ba] + (char)((uint)param_2 >> 8);
  cVar3 = cVar3 + (char)((uint)unaff_EBX >> 8);
  iVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(cVar3,(char)in_EAX));
  *unaff_EBX = *unaff_EBX + (char)in_EAX;
  *param_2 = *param_2 + (char)param_1;
  *(char *)(unaff_EBP + 0x47) = *(char *)(unaff_EBP + 0x47) + (char)param_1;
  pcVar1 = (char *)(unaff_EDI + 0x50 + iVar2 * 2);
  *pcVar1 = *pcVar1 + (char)param_2;
  unaff_EBX[0x47] = unaff_EBX[0x47] + (char)unaff_EBX;
  param_2[0x47] = param_2[0x47] + cVar3;
  *(char *)(unaff_ESI + -0x5affb8b6) = *(char *)(unaff_ESI + -0x5affb8b6) + (char)unaff_EBX;
  pcVar1 = (char *)(unaff_EDI + 0x47b30054 + iVar2 * 2);
  *pcVar1 = *pcVar1 + (char)((uint)param_1 >> 8);
  *(char *)(iVar2 + 0x56909090) = *(char *)(iVar2 + 0x56909090) + (char)param_2;
  if (*(TButtonPanel **)(param_1 + 0xf8) != (TButtonPanel *)0x0) {
    pTVar4 = param_5;
    if (param_5 == (TShape *)0x0) {
      param_6 = -1;
      pTVar4 = (TShape *)0x0;
    }
    TButtonPanel::set_picture(*(TButtonPanel **)(param_1 + 0xf8),0,pTVar4,param_6);
  }
  if (*(TScrollBarPanel **)(param_1 + 0x100) != (TScrollBarPanel *)0x0) {
    TScrollBarPanel::set_buttons
              (*(TScrollBarPanel **)(param_1 + 0x100),param_5,param_7,param_8,param_9,param_10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00474872
// Address: 00474872
void __thiscall FUN_00474872(TPanel *param_1,int param_2)
{
  char cVar1;
  TTextPanel *pTVar2;
  code *pcVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  long lVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  TDrawArea *pTVar12;
  TPanel *pTVar13;
  code *pcVar14;
  undefined4 uVar15;
  code *pcVar16;
  int iVar17;
  int iStack_c;
  
  if (param_2 != param_1[1].pnl_y) {
    if (param_1->parent_panel == (TPanel *)0x0) {
      iStack_c = 0;
      iVar5 = param_1->render_area->Width;
      iVar6 = param_1->render_area->Height;
      lVar4 = 0;
    }
    else {
      iStack_c = TPanel::xPosition(param_1->parent_panel);
      lVar4 = TPanel::yPosition(param_1->parent_panel);
      iVar5 = TPanel::width(param_1->parent_panel);
      iVar6 = TPanel::height(param_1->parent_panel);
    }
    iVar9 = param_1[1].pnl_y;
    param_1[1].pnl_y = 0;
    if (param_2 == 1) {
      if ((((iVar9 == 2) && (param_1->parent_panel != (TPanel *)0x0)) &&
          (pTVar13 = param_1->parent_panel->parent_panel, pTVar13 != (TPanel *)0x0)) &&
         ((((param_1->clip_rect).left < iStack_c || ((param_1->clip_rect).top < lVar4)) ||
          ((iVar5 + -1 + iStack_c < (param_1->clip_rect).right ||
           (iVar6 + -1 + lVar4 < (param_1->clip_rect).bottom)))))) {
        (**(code **)(pTVar13->_padding_ + 0x20))(2);
      }
      (**(code **)((param_1[1].previousModalPanelValue)->_padding_ + 0x14))(0);
      (**(code **)(*(int *)param_1[1].pnl_x + 0x14))(0);
      if (param_1[1].top_panel == (TPanel *)0x1) {
        lVar4 = param_1[1].clip_rect.left;
        (**(code **)((param_1[1].previousPanelValue)->_padding_ + 0x18))
                  (7,0,0,1,0,param_1[1].render_area,param_1[1].render_area,lVar4,lVar4,0,0,0,0);
        pcVar7 = param_1[1].panelNameValue;
        pTVar12 = (TDrawArea *)param_1[1].pnl_hgt;
        pTVar13 = param_1[1].previousPanelValue;
        iVar5 = *(int *)param_1[1]._padding_;
      }
      else {
        (**(code **)(*(int *)param_1[1]._padding_ + 0x18))
                  (7,0,0,1,0,param_1[1].pnl_hgt,param_1[1].pnl_hgt,param_1[1].panelNameValue,
                   param_1[1].panelNameValue,0,0,0,0);
        pcVar7 = (char *)param_1[1].clip_rect.left;
        pTVar12 = param_1[1].render_area;
        pTVar13 = (TPanel *)param_1[1]._padding_;
        iVar5 = (param_1[1].previousPanelValue)->_padding_;
      }
      iVar17 = 0;
      (**(code **)(iVar5 + 0x18))(7,1,0,0,0,pTVar12,pTVar12,pcVar7,pcVar7,pTVar13,0,0,0);
      iVar5 = param_1[1].pnl_hgt;
      pTVar12 = param_1[1].render_area;
      cVar1 = *(char *)&param_1[1].curr_child;
      iVar6 = param_1->_padding_;
      pcVar7 = param_1[1].panelNameValue;
      param_1->clip_to_parent = '\x01';
      if (cVar1 == '\0') {
        (**(code **)(iVar6 + 0x1c))
                  (param_1->pnl_x - iStack_c,param_1->pnl_y - iVar17,
                   (int)&pTVar12->DrawSystem + iVar5 + 1,pcVar7);
      }
      else {
        (**(code **)(iVar6 + 0x1c))
                  (param_1->pnl_x - iStack_c,
                   ((param_1->pnl_y + param_1->pnl_hgt) - (int)pcVar7) - iVar17);
        *(undefined1 *)&param_1[1].curr_child = 0;
      }
      if (param_1->parent_panel == (TPanel *)0x0) {
        (**(code **)(iVar6 + 0x20))(1);
      }
      else {
        (**(code **)(param_1->parent_panel->_padding_ + 0x20))(1);
      }
      TPanel::set_curr_child(param_1,(TPanel *)param_1[1]._padding_);
      if (iVar9 == 2) {
        iVar5 = TPanelSystem::restorePreviousModalPanel(&panel_system);
        if (iVar5 == 0) {
          TPanelSystem::setModalPanel(&panel_system,(TPanel *)0x0);
        }
        if (param_1->parent_panel != (TPanel *)0x0) {
          (**(code **)(param_1->parent_panel->_padding_ + 0xb4))(param_1,2,0,0);
          param_1[1].pnl_y = iStack_c;
          return;
        }
      }
    }
    else if (param_2 == 2) {
      (**(code **)((param_1[1].previousModalPanelValue)->_padding_ + 0x14))(1);
      pTVar2 = (TTextPanel *)param_1[1].previousModalPanelValue;
      iVar5 = pTVar2->spacer_size;
      if (iVar5 == 0) {
        iVar5 = pTVar2->border_size;
        iVar6 = TTextPanel::numberLines(pTVar2);
        param_1[1].clip_rect.right =
             iVar6 * (int)((int)&(param_1[1].parent_panel)->_padding_ + 2) + iVar5 * 2;
      }
      else {
        iVar6 = pTVar2->border_size;
        iVar9 = TTextPanel::numberLines(pTVar2);
        param_1[1].clip_rect.right =
             iVar9 * ((int)&(param_1[1].parent_panel)->_padding_ + iVar5 * 2 + 1) + iVar6 * 2;
      }
      (**(code **)((param_1[1].previousModalPanelValue)->_padding_ + 0x1c))
                (0,0,param_1[1].clip_rect.top,param_1[1].clip_rect.right);
      iVar5 = TTextPanel::numberLines((TTextPanel *)param_1[1].previousModalPanelValue);
      iVar6 = TTextPanel::numberDrawLines((TTextPanel *)param_1[1].previousModalPanelValue);
      if (iVar6 < iVar5) {
        (**(code **)(*(int *)param_1[1].pnl_x + 0x14))(1);
      }
      else {
        (**(code **)(*(int *)param_1[1].pnl_x + 0x14))(0);
      }
      if (param_1[1].top_panel == (TPanel *)0x1) {
        lVar4 = param_1[1].clip_rect.left;
        (**(code **)((param_1[1].previousPanelValue)->_padding_ + 0x18))
                  (7,0,0,1,0,param_1[1].render_area,param_1[1].render_area,lVar4,lVar4,0,0,0,0);
        pcVar7 = param_1[1].panelNameValue;
        pTVar12 = (TDrawArea *)param_1[1].pnl_hgt;
        pTVar13 = param_1[1].previousPanelValue;
        iVar5 = *(int *)param_1[1]._padding_;
      }
      else {
        (**(code **)(*(int *)param_1[1]._padding_ + 0x18))
                  (7,0,0,1,0,param_1[1].pnl_hgt,param_1[1].pnl_hgt,param_1[1].panelNameValue,
                   param_1[1].panelNameValue,0,0,0,0);
        pcVar7 = (char *)param_1[1].clip_rect.left;
        pTVar12 = param_1[1].render_area;
        pTVar13 = (TPanel *)param_1[1]._padding_;
        iVar5 = (param_1[1].previousPanelValue)->_padding_;
      }
      (**(code **)(iVar5 + 0x18))(7,1,0,0,0,pTVar12,pTVar12,pcVar7,pcVar7,pTVar13,0,0,0);
      lVar4 = param_1[1].clip_rect.bottom;
      (**(code **)(*(int *)param_1[1].pnl_x + 0x18))
                (10,1,1,0,0,lVar4,lVar4,0,0,0,param_1[1]._padding_,0,0);
      iVar6 = 0;
      (**(code **)((param_1[1].previousModalPanelValue)->_padding_ + 0x18))
                (8,0,1,1,0,0,0,0,0,0,param_1[1]._padding_,param_1[1].pnl_x,0);
      pcVar14 = (code *)param_1[1].clip_rect.top;
      pcVar7 = param_1[1].panelNameValue + param_1[1].clip_rect.right + 1;
      iVar6 = param_1->pnl_y - iVar6;
      pcVar3 = *(code **)(param_1->_padding_ + 0x1c);
      iVar5 = param_1->pnl_x - iStack_c;
      param_1->clip_to_parent = '\0';
      pcVar16 = pcVar14;
      (*pcVar3)(iVar5,iVar6,pcVar14,pcVar7);
      lVar4 = TPanel::yPosition(param_1[1].previousModalPanelValue);
      lVar8 = TPanel::height(param_1[1].previousModalPanelValue);
      if (param_1->render_area->Height + -4 < lVar4 + lVar8) {
        lVar4 = TPanel::yPosition(param_1[1].previousModalPanelValue);
        lVar8 = TPanel::height(param_1[1].previousModalPanelValue);
        iVar17 = lVar4 + lVar8 + (4 - param_1->render_area->Height);
        lVar4 = TPanel::height(param_1[1].previousModalPanelValue);
        iVar9 = lVar4 + (4 - param_1->pnl_y);
        if (iVar9 < iVar17) {
          if (0 < iVar9) {
            iVar9 = param_1[1].clip_rect.right - iVar9;
            iVar5 = (param_1[1].previousModalPanelValue)->_padding_;
            lVar4 = param_1[1].clip_rect.top;
            param_1[1].clip_rect.right = iVar9;
            (**(code **)(iVar5 + 0x1c))(0,0,lVar4,iVar9);
            pTVar2 = (TTextPanel *)param_1[1].previousModalPanelValue;
            iVar5 = pTVar2->spacer_size;
            if (iVar5 == 0) {
              iVar5 = pTVar2->border_size;
              iVar6 = TTextPanel::numberDrawLines(pTVar2);
              param_1[1].clip_rect.right =
                   iVar6 * (int)((int)&(param_1[1].parent_panel)->_padding_ + 2) + iVar5 * 2;
            }
            else {
              iVar6 = pTVar2->border_size;
              iVar9 = TTextPanel::numberDrawLines(pTVar2);
              param_1[1].clip_rect.right =
                   iVar9 * ((int)&(param_1[1].parent_panel)->_padding_ + iVar5 * 2 + 1) + iVar6 * 2;
            }
            iVar5 = param_1[1].clip_rect.right;
            pcVar7 = param_1[1].panelNameValue + iVar5 + 1;
            if (*(int *)(param_1[1].pnl_x + 0x6c) == 0) {
              (**(code **)((param_1[1].previousModalPanelValue)->_padding_ + 0x1c))
                        (0,0,param_1[1].clip_rect.top,iVar5);
              iVar5 = TTextPanel::numberLines((TTextPanel *)param_1[1].previousModalPanelValue);
              iVar6 = TTextPanel::numberDrawLines((TTextPanel *)param_1[1].previousModalPanelValue);
              if (iVar6 < iVar5) {
                (**(code **)(*(int *)param_1[1].pnl_x + 0x14))(1);
              }
            }
          }
          if (param_1[1].top_panel == (TPanel *)0x1) {
            lVar4 = param_1[1].clip_rect.left;
            (**(code **)((param_1[1].previousPanelValue)->_padding_ + 0x18))
                      (8,0,0,1,0,param_1[1].render_area,param_1[1].render_area,lVar4,lVar4,0,0,0,0);
            pcVar10 = param_1[1].panelNameValue;
            pTVar12 = (TDrawArea *)param_1[1].pnl_hgt;
            pTVar13 = param_1[1].previousPanelValue;
            iVar5 = *(int *)param_1[1]._padding_;
          }
          else {
            (**(code **)(*(int *)param_1[1]._padding_ + 0x18))
                      (8,0,0,1,0,param_1[1].pnl_hgt,param_1[1].pnl_hgt,param_1[1].panelNameValue,
                       param_1[1].panelNameValue,0,0,0,0);
            pcVar10 = (char *)param_1[1].clip_rect.left;
            pTVar12 = param_1[1].render_area;
            pTVar13 = (TPanel *)param_1[1]._padding_;
            iVar5 = (param_1[1].previousPanelValue)->_padding_;
          }
          (**(code **)(iVar5 + 0x18))(8,1,0,0,0,pTVar12,pTVar12,pcVar10,pcVar10,pTVar13,0,0,0);
          lVar4 = param_1[1].clip_rect.bottom;
          (**(code **)(*(int *)param_1[1].pnl_x + 0x18))
                    (9,1,1,0,0,lVar4,lVar4,0,0,0,0,0,param_1[1]._padding_);
          uVar15 = 0;
          pcVar14 = (code *)0x0;
          iVar6 = 0;
          iVar5 = 0;
          (**(code **)((param_1[1].previousModalPanelValue)->_padding_ + 0x18))
                    (7,0,1,1,0,0,0,0,0,0,0,param_1[1].pnl_x,param_1[1]._padding_);
          (*pcVar14)(param_1->pnl_x - iVar6,
                     param_1[1].panelNameValue + param_1->pnl_y + (-iVar5 - (int)pcVar7),uVar15,
                     pcVar7);
          *(undefined1 *)&param_1[1].curr_child = 1;
        }
        else {
          iVar17 = param_1[1].clip_rect.right - iVar17;
          iVar9 = (param_1[1].previousModalPanelValue)->_padding_;
          param_1[1].clip_rect.right = iVar17;
          (**(code **)(iVar9 + 0x1c))(0,0,param_1[1].clip_rect.top,iVar17);
          pTVar2 = (TTextPanel *)param_1[1].previousModalPanelValue;
          iVar9 = pTVar2->spacer_size;
          if (iVar9 == 0) {
            iVar9 = pTVar2->border_size;
            iVar17 = TTextPanel::numberDrawLines(pTVar2);
            param_1[1].clip_rect.right =
                 iVar17 * (int)((int)&(param_1[1].parent_panel)->_padding_ + 2) + iVar9 * 2;
          }
          else {
            iVar17 = pTVar2->border_size;
            iVar11 = TTextPanel::numberDrawLines(pTVar2);
            param_1[1].clip_rect.right =
                 iVar11 * ((int)&(param_1[1].parent_panel)->_padding_ + iVar9 * 2 + 1) + iVar17 * 2;
          }
          iVar9 = param_1[1].clip_rect.right;
          pcVar7 = param_1[1].panelNameValue;
          if (*(int *)(param_1[1].pnl_x + 0x6c) == 0) {
            (**(code **)((param_1[1].previousModalPanelValue)->_padding_ + 0x1c))
                      (0,0,param_1[1].clip_rect.top,iVar9);
            iVar17 = TTextPanel::numberLines((TTextPanel *)param_1[1].previousModalPanelValue);
            iVar11 = TTextPanel::numberDrawLines((TTextPanel *)param_1[1].previousModalPanelValue);
            if (iVar11 < iVar17) {
              (**(code **)(*(int *)param_1[1].pnl_x + 0x14))(1);
            }
            (**(code **)((param_1[1].previousModalPanelValue)->_padding_ + 0x18))
                      (8,0,1,1,0,0,0,0,0,0,param_1[1]._padding_,param_1[1].pnl_x,0);
          }
          (*pcVar16)(param_1->pnl_x - iVar6,param_1->pnl_y - iVar5,pcVar14,pcVar7 + iVar9 + 1);
        }
      }
      (**(code **)(param_1->_padding_ + 0x20))(1);
      TPanel::set_z_order(param_1,'\x01',0);
      TPanel::set_curr_child(param_1,param_1[1].previousModalPanelValue);
      TPanelSystem::setModalPanel(&panel_system,param_1);
      if (param_1->parent_panel != (TPanel *)0x0) {
        (**(code **)(param_1->parent_panel->_padding_ + 0xb4))(param_1,1,0,0);
      }
    }
    param_1[1].pnl_y = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00475109
// Address: 00475109
int __fastcall FUN_00475109(int param_1)
{
  int iVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    iVar1 = TTextPanel::numberLines(*(TTextPanel **)(param_1 + 0xfc));
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00475122
// Address: 00475122
int __fastcall FUN_00475122(int param_1)
{
  int iVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    iVar1 = TTextPanel::currentLineNumber(*(TTextPanel **)(param_1 + 0xfc));
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00475142
// Address: 00475142
void __thiscall FUN_00475142(TDropDownPanel *param_1,long param_2)
{
  TDropDownPanel::set_line(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0047515d
// Address: 0047515d
void __thiscall FUN_0047515d(int param_1,long param_2)
{
  int iVar1;
  long lVar2;
  char *pcVar3;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    TTextPanel::set_line_by_id(*(TTextPanel **)(param_1 + 0xfc),param_2);
    lVar2 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0xfc));
    *(short *)(param_1 + 0x108) = (short)lVar2;
    if (*(int **)(param_1 + 0xf4) != (int *)0x0) {
      iVar1 = **(int **)(param_1 + 0xf4);
      pcVar3 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0xfc),(int)(short)lVar2);
      (**(code **)(iVar1 + 0xe8))(pcVar3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004751b7
// Address: 004751b7
char * __fastcall FUN_004751b7(int param_1)
{
  char *pcVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    pcVar1 = TTextPanel::currentLine(*(TTextPanel **)(param_1 + 0xfc));
    return pcVar1;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: FUN_004751d2
// Address: 004751d2
void __thiscall FUN_004751d2(TPanel *param_1,TPanel *param_2,TPanel *param_3)
{
  TPanel::set_tab_order(param_1,param_2,param_3);
  if ((int *)param_1[1]._padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1[1]._padding_ + 0xc4))(0,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047520e
// Address: 0047520e
void __thiscall FUN_0047520e(int param_1,undefined4 param_2)
{
  if (*(int *)(param_1 + 0xfc) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xfc) + 0x15c) = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00475227
// Address: 00475227
undefined4 __fastcall FUN_00475227(int param_1)
{
  if (*(int *)(param_1 + 0xfc) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0xfc) + 0x15c);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00475244
// Address: 00475244
void __thiscall FUN_00475244(int param_1,long param_2)
{
  int iVar1;
  char *pcVar2;
  
  *(short *)(param_1 + 0x108) = (short)param_2;
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    TTextPanel::set_line(*(TTextPanel **)(param_1 + 0xfc),param_2);
    if (*(int **)(param_1 + 0xf4) != (int *)0x0) {
      iVar1 = **(int **)(param_1 + 0xf4);
      pcVar2 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0xfc),param_2);
      (**(code **)(iVar1 + 0xe8))(pcVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047529b
// Address: 0047529b
int __thiscall FUN_0047529b(int param_1,char *param_2,long param_3)
{
  int iVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    iVar1 = TTextPanel::append_line(*(TTextPanel **)(param_1 + 0xfc),param_2,param_3);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004752c1
// Address: 004752c1
int __thiscall FUN_004752c1(int param_1,long param_2,long param_3)
{
  int iVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    iVar1 = TTextPanel::append_line(*(TTextPanel **)(param_1 + 0xfc),param_2,param_3);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004752f1
// Address: 004752f1
int __thiscall FUN_004752f1(int param_1,long param_2,char *param_3,long param_4)
{
  int iVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    iVar1 = TTextPanel::insert_line(*(TTextPanel **)(param_1 + 0xfc),param_2,param_3,param_4);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00475326
// Address: 00475326
int __thiscall FUN_00475326(int param_1,long param_2,long param_3,long param_4)
{
  int iVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    iVar1 = TTextPanel::insert_line(*(TTextPanel **)(param_1 + 0xfc),param_2,param_3,param_4);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00475356
// Address: 00475356
int __thiscall FUN_00475356(int param_1,long param_2)
{
  int iVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    iVar1 = TTextPanel::delete_line(*(TTextPanel **)(param_1 + 0xfc),param_2);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047537c
// Address: 0047537c
long __fastcall FUN_0047537c(int param_1)
{
  long lVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0xfc));
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00475392
// Address: 00475392
long __thiscall FUN_00475392(int param_1,long param_2)
{
  long lVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0xfc),param_2);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004753bc
// Address: 004753bc
long __thiscall FUN_004753bc(int param_1,char *param_2)
{
  long lVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    lVar1 = TTextPanel::get_line(*(TTextPanel **)(param_1 + 0xfc),param_2);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004753dc
// Address: 004753dc
char * __fastcall FUN_004753dc(int param_1)
{
  char *pcVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    pcVar1 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0xfc));
    return pcVar1;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: FUN_004753f2
// Address: 004753f2
char * __thiscall FUN_004753f2(int param_1,long param_2)
{
  char *pcVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    pcVar1 = TTextPanel::get_text(*(TTextPanel **)(param_1 + 0xfc),param_2);
    return pcVar1;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: FUN_0047541c
// Address: 0047541c
long __fastcall FUN_0047541c(int param_1)
{
  long lVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    lVar1 = TTextPanel::get_id(*(TTextPanel **)(param_1 + 0xfc));
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00475432
// Address: 00475432
long __thiscall FUN_00475432(int param_1,long param_2)
{
  long lVar1;
  
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    lVar1 = TTextPanel::get_id(*(TTextPanel **)(param_1 + 0xfc),param_2);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047545c
// Address: 0047545c
void __fastcall FUN_0047545c(int param_1)
{
  if (*(TTextPanel **)(param_1 + 0xfc) != (TTextPanel *)0x0) {
    TTextPanel::empty_list(*(TTextPanel **)(param_1 + 0xfc));
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047548e
// Address: 0047548e
TDropDownButtonPanel * __thiscall FUN_0047548e(TDropDownButtonPanel *param_1,byte param_2)
{
  TDropDownButtonPanel::~TDropDownButtonPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004754b5
// Address: 004754b5
void __thiscall FUN_004754b5(TPanel *param_1,long param_2,long param_3,int param_4,int param_5)
{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined4 unaff_EBP;
  undefined4 unaff_EDI;
  
  if (param_1->mouse_captured != 0) {
    iVar1 = (**(code **)(**(int **)(param_1[2].mouse_down_shift + 0xfc) + 0xbc))(param_2,param_3);
    if (iVar1 != 0) {
      (**(code **)(param_1->_padding_ + 0x78))(1,param_2,param_3,param_2,param_3);
      (**(code **)(**(int **)(param_1[2].mouse_down_shift + 0xfc) + 0x70))
                (1,param_2,param_3,unaff_EDI,param_3);
      return;
    }
    iVar1 = (**(code **)(**(int **)(param_1[2].mouse_down_shift + 0x100) + 0xbc))(param_2,param_3);
    if (iVar1 != 0) {
      (**(code **)(param_1->_padding_ + 0x78))(1,param_2,param_3,param_4,param_5);
      lVar2 = TPanel::width(*(TPanel **)(param_1[2].mouse_down_shift + 0xfc));
      lVar3 = TPanel::xPosition(*(TPanel **)(param_1[2].mouse_down_shift + 0xfc));
      (**(code **)(**(int **)(param_1[2].mouse_down_shift + 0xfc) + 0x70))
                (1,lVar2 + -1 + lVar3,param_3,unaff_EBP,param_5);
      return;
    }
  }
  TPanel::handle_mouse_move(param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_004755bd
// Address: 004755bd
TPanel * __fastcall FUN_004755bd(TPanel *param_1)
{
  TPanel::TPanel(param_1);
  param_1[1]._padding_ = 0;
  param_1[1].previousModalPanelValue = (TPanel *)0x0;
  *(undefined2 *)&param_1[1].previousPanelValue = 0;
  param_1[1].pnl_wid = 0;
  param_1[1].panelNameValue = (char *)0x0;
  param_1[1].render_area = (TDrawArea *)0x0;
  param_1[1].clip_rect.left = 0;
  param_1[1].clip_rect.top = 0;
  param_1[1].clip_rect.right = 0;
  param_1[1].clip_rect.bottom = 0;
  param_1[1].first_child_node = (PanelNode *)0x0;
  *(undefined1 *)&param_1[1].tab_prev_panel = 0;
  *(undefined1 *)((int)&param_1[1].tab_prev_panel + 1) = 0;
  *(undefined1 *)((int)&param_1[1].tab_prev_panel + 2) = 0;
  *(undefined1 *)((int)&param_1[1].tab_prev_panel + 3) = 0;
  *(undefined1 *)&param_1[1].tab_next_panel = 0;
  *(undefined1 *)((int)&param_1[1].tab_next_panel + 1) = 0;
  param_1[1].mouse_captured = 0;
  param_1[1].active = 0;
  param_1[1].visible = 0;
  param_1[1].tab_stop = 0;
  param_1->_padding_ = (int)&TEditPanel::_vftable_;
  param_1->handle_mouse_input = 1;
  param_1[1].pnl_y = 1;
  param_1[1].last_child_node = (PanelNode *)0x1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047566a
// Address: 0047566a
TEditPanel * __thiscall FUN_0047566a(TEditPanel *param_1,byte param_2)
{
  TEditPanel::~TEditPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047568e
// Address: 0047568e
void __fastcall FUN_0047568e(TPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e468;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TEditPanel::_vftable_;
  uStack_4 = 0;
  if ((param_1[1]._padding_ != 0) && (param_1[1].pnl_y == 0)) {
    ShowWindow(param_1[1]._padding_,0);
    param_1[1].pnl_y = 1;
  }
  if (param_1[1].previousModalPanelValue != (TPanel *)0x0) {
    free(param_1[1].previousModalPanelValue);
    param_1[1].previousModalPanelValue = (TPanel *)0x0;
  }
  if (param_1[1]._padding_ != 0) {
    if (param_1[1].active != 0) {
      _ImmNotifyIME_16(param_1[1].active,0x15,4,0);
      if (param_1[1].visible != 0) {
        _ImmReleaseContext_8(param_1[1]._padding_,param_1[1].active);
      }
      param_1[1].active = 0;
    }
    DestroyWindow(param_1[1]._padding_);
    param_1[1]._padding_ = 0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00475768
// Address: 00475768
// [HELPER] s_edit: "edit"
undefined4 __thiscall
FUN_00475768(TEditPanel *param_1,TDrawArea *param_2,TPanel *param_3,int param_4,int param_5,
            int param_6,int param_7,void *param_8,short param_9,char *param_10,FormatType param_11,
            int param_12)
{
  long lVar1;
  void *pvVar2;
  char *pcVar3;
  
  param_1->format = param_11;
  if (0 < param_9) {
    param_9 = param_9 + 1;
  }
  param_1->fixed_len = param_9;
  param_1->font = param_8;
  param_1->auto_sel = param_12;
  lVar1 = TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6,param_7,0xff);
  if (lVar1 == 0) {
    return 0;
  }
  pvVar2 = (void *)CreateWindowExA(0,s_edit,0,
                                   (-(uint)(param_1->format != FormatMultiLine) & 0xffe0003c) +
                                   0x40200044,param_4 + 1,param_5 + 1,param_6 + -2,param_7 + -2,
                                   param_2->Wnd,1,**(undefined4 **)param_1->_padding_,0);
  param_1->edit_wnd = pvVar2;
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
  SetWindowLongA(pvVar2,0xffffffeb,param_1);
  pvVar2 = (void *)GetWindowLongA(param_1->edit_wnd,0xfffffffc);
  param_1->old_sub_wnd_proc = pvVar2;
  SetWindowLongA(param_1->edit_wnd,0xfffffffc,pnl_sub_wnd_proc);
  pcVar3 = (char *)calloc(param_1->fixed_len + 2,1);
  param_1->text = pcVar3;
  if (pcVar3 == (char *)0x0) {
    return 0;
  }
  *pcVar3 = '\0';
  param_1->text_len = 0;
  if ((param_10 != (char *)0x0) && (*param_10 != '\0')) {
    TEditPanel::set_text(param_1,param_10);
  }
  pvVar2 = (void *)GetStockObject(4);
  param_1->brush = pvVar2;
  param_1->text_color1 = 0xffffff;
  param_1->highlight_text_color1 = 0xffffff;
  param_1->back_color = 0;
  param_1->text_color2 = 0;
  param_1->highlight_text_color2 = 0;
  if (param_1->font != (void *)0x0) {
    SendMessageA(param_1->edit_wnd,0x30,param_1->font,0);
  }
  param_1->draw_format = 0x2000;
  param_1->draw_format = (-(uint)(param_1->format != FormatMultiLine) & 0x10) + 0x2010;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047592f
// Address: 0047592f
long FUN_0047592f(void *param_1,uint param_2,uint param_3,long param_4)
{
  TEditPanel *this;
  long lVar1;
  
  this = (TEditPanel *)GetWindowLongA(param_1,0xffffffeb);
  if (this != (TEditPanel *)0x0) {
    lVar1 = TEditPanel::sub_wnd_proc(this,param_1,param_2,param_3,param_4);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: pnl_sub_wnd_proc
// Address: 00475930
long pnl_sub_wnd_proc(void *param_1,uint param_2,uint param_3,long param_4)
{
  TEditPanel *this;
  long lVar1;
  
  this = (TEditPanel *)GetWindowLongA(param_1,0xffffffeb);
  if (this != (TEditPanel *)0x0) {
    lVar1 = TEditPanel::sub_wnd_proc(this,param_1,param_2,param_3,param_4);
    return lVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00475963
// Address: 00475963
void __thiscall FUN_00475963(int *param_1,int param_2)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  if (param_1[0x3d] != 0) {
    if (param_2 == 0) {
      *(undefined1 *)param_1[0x3f] = 0;
      param_1[0x40] = 0;
    }
    else {
      iVar2 = param_1[0x3e];
      puVar4 = (undefined4 *)param_1[0x3f];
      for (uVar3 = (uint)(int)(short)iVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (uVar3 = (int)(short)iVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      strncpy(param_1[0x3f],param_2,(short)param_1[0x3e] + -1);
      uVar3 = 0xffffffff;
      *(undefined1 *)(param_1[0x3f] + -1 + (int)(short)param_1[0x3e]) = 0;
      pcVar5 = (char *)param_1[0x3f];
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      param_1[0x40] = ~uVar3 - 1;
    }
    SetWindowTextA(param_1[0x3d],param_1[0x3f]);
    param_1[0x53] = 0;
  }
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00475a2b
// Address: 00475a2b
void __fastcall FUN_00475a2b(int param_1)
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iStack_8;
  int iStack_4;
  
  if (*(int *)(param_1 + 0xf4) != 0) {
    GetWindowTextA(*(int *)(param_1 + 0xf4),*(undefined4 *)(param_1 + 0xfc),
                   *(short *)(param_1 + 0xf8) + 1);
    uVar2 = 0xffffffff;
    pcVar3 = *(char **)(param_1 + 0xfc);
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    *(uint *)(param_1 + 0x100) = ~uVar2 - 1;
    (*(char **)(param_1 + 0xfc))[*(short *)(param_1 + 0xf8) + -1] = '\0';
    if (*(short *)(param_1 + 0xf8) + -1 < *(int *)(param_1 + 0x100)) {
      SetWindowTextA(*(undefined4 *)(param_1 + 0xf4),*(undefined4 *)(param_1 + 0xfc));
      MessageBeep(0xffffffff);
    }
    iStack_4 = 0;
    iStack_8 = 0;
    SendMessageA(*(undefined4 *)(param_1 + 0xf4),0xb0,&iStack_4,&iStack_8);
    *(int *)(param_1 + 0x14c) = iStack_8 - iStack_4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00475b55
// Address: 00475b55
void __thiscall FUN_00475b55(TEditPanel *param_1,int param_2)
{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  ulong uVar4;
  
  iVar1 = param_1->_padding_;
  TPanel::set_focus((TPanel *)param_1,param_2);
  if (param_1->edit_wnd != (void *)0x0) {
    pvVar3 = (void *)GetFocus();
    pvVar2 = param_1->edit_wnd;
    if (param_1->_padding_ == 0) {
      if ((pvVar3 == pvVar2) && (pvVar2 = *(void **)(param_1->_padding_ + 4), pvVar3 != pvVar2)) {
        SetFocus(pvVar2);
      }
    }
    else {
      if (pvVar3 != pvVar2) {
        SetFocus(pvVar2);
      }
      if (param_1->imc == 0) {
        if (param_1->enable_ime == 0) {
          uVar4 = _ImmAssociateContext_8(param_1->edit_wnd,0);
        }
        else {
          uVar4 = _ImmGetContext_4(param_1->edit_wnd);
        }
        param_1->imc = uVar4;
      }
      uVar4 = param_1->imc;
      if ((uVar4 != 0) && (param_1->enable_ime != 0)) {
        if (param_1->turn_ime_on == 0) {
          imc_retval = _ImmSetOpenStatus_8(uVar4,0);
        }
        else {
          imc_retval = _ImmSetOpenStatus_8(uVar4,1);
        }
      }
    }
  }
  if ((iVar1 != 0) && (param_1->_padding_ == 0)) {
    TEditPanel::update_text(param_1);
    (**(code **)(param_1->_padding_ + 0x20))(1);
  }
  if ((((param_1->edit_wnd != (void *)0x0) && (param_1->_padding_ != 0)) && (iVar1 == 0)) &&
     (param_1->auto_sel != 0)) {
    SendMessageA(param_1->edit_wnd,0xb1,0,0xffffffff);
  }
  if (((DAT_0086b240 == 0) && (param_1->edit_wnd != (void *)0x0)) &&
     ((param_1->_padding_ == 0 && (param_1->hidden == 0)))) {
    ShowWindow(param_1->edit_wnd,0);
    param_1->hidden = 1;
  }
  if (param_1->_padding_ != 0) {
    DAT_0086b244 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00475cba
// Address: 00475cba
void __thiscall FUN_00475cba(TPanel *param_1,long param_2,long param_3,long param_4,long param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  TPanel::set_rect(param_1,param_2,param_3,param_4,param_5);
  if (param_1[1]._padding_ != 0) {
    if (((param_1[1].pnl_y == 0) && (param_1->visible != 0)) && (param_1->active != 0)) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    iVar1 = param_1[1].mouse_captured;
    MoveWindow(param_1[1]._padding_,param_1->pnl_x + iVar1,param_1->pnl_y + iVar1,
               param_1->pnl_wid + iVar1 * -2 + -1,param_1->pnl_hgt + iVar1 * -2 + -1,uVar4);
  }
  iVar1 = (param_1->render_rect).left;
  iVar2 = param_1[1].mouse_captured;
  if (param_1[1].position_mode == PositionLeftTop) {
    iVar3 = (param_1->render_rect).top;
    param_1[1].parent_panel = (TPanel *)(iVar1 + 1 + iVar2);
    param_1[1].left_panel = (TPanel *)(iVar3 + iVar2);
    iVar3 = GetSystemMetrics(0x15);
    iVar1 = (param_1->render_rect).bottom;
    param_1[1].top_panel = (TPanel *)((((param_1->render_rect).right - iVar2) - iVar3) + -1);
    param_1[1].right_panel = (TPanel *)(iVar1 - iVar2);
    return;
  }
  iVar3 = (param_1->render_rect).top;
  param_1[1].parent_panel = (TPanel *)(iVar1 + 8 + iVar2);
  iVar1 = (param_1->render_rect).right;
  param_1[1].left_panel = (TPanel *)(iVar3 + iVar2);
  iVar3 = (param_1->render_rect).bottom;
  param_1[1].top_panel = (TPanel *)(iVar1 - iVar2);
  param_1[1].right_panel = (TPanel *)(iVar3 - iVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_00475dcb
// Address: 00475dcb
void __thiscall FUN_00475dcb(TPanel *param_1,int param_2)
{
  TPanel::set_redraw(param_1,RedrawNormal);
  if ((((param_1->active != 0) && (param_2 != 0)) && (param_1[1]._padding_ != 0)) &&
     (param_1[1].pnl_y == 0)) {
    InvalidateRect(param_1[1]._padding_,0,1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00475e0c
// Address: 00475e0c
void __thiscall FUN_00475e0c(int *param_1,int param_2,int param_3)
{
  param_1[0x45] = param_2;
  param_1[0x46] = param_3;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00475e2e
// Address: 00475e2e
void FUN_00475e2e(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00475e33
// Address: 00475e33
void FUN_00475e33(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00475e43
// Address: 00475e43
void __thiscall
FUN_00475e43(int *param_1,int param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5,
            undefined1 param_6,undefined1 param_7,undefined1 param_8)
{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x55) = param_3;
  *(undefined1 *)((int)param_1 + 0x155) = param_4;
  param_1[0x54] = param_2;
  *(undefined1 *)((int)param_1 + 0x156) = param_5;
  *(undefined1 *)((int)param_1 + 0x157) = param_6;
  *(undefined1 *)(param_1 + 0x56) = param_7;
  *(undefined1 *)((int)param_1 + 0x159) = param_8;
  switch(param_2) {
  case 1:
  case 2:
  case 5:
    param_1[0x57] = 1;
    break;
  case 3:
  case 6:
    param_1[0x57] = 2;
    break;
  case 4:
  case 7:
    param_1[0x57] = 3;
    break;
  default:
    param_1[0x57] = 0;
  }
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0xc))(param_1[3],param_1[4],param_1[5],param_1[6]);
  (**(code **)(iVar1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00475f37
// Address: 00475f37
long __thiscall FUN_00475f37(TPanel *param_1,void *param_2,uint param_3,uint param_4,uint param_5)
{
  uint uVar1;
  long lVar2;
  
  uVar1 = param_1[1]._padding_;
  if ((((uVar1 != 0) && (param_1->active != 0)) && (param_1->visible != 0)) &&
     (param_1[1].pnl_y == 0)) {
    if (param_3 == 7) {
      lVar2 = TPanel::wnd_proc(param_1,param_2,7,param_4,param_5);
      return lVar2;
    }
    if (param_3 == 0x111) {
      if ((param_5 == uVar1) && ((short)(param_4 >> 0x10) == 0x400)) {
        InvalidateRect(uVar1,0,1);
      }
    }
    else if (((param_3 == 0x133) && (param_1[1].pnl_wid != 0)) && ((param_5 & 0xffff) == uVar1)) {
      SetBkColor(param_4,param_1[1].clip_rect.bottom);
      SetBkMode(param_4,2);
      SetTextColor(param_4,param_1[1].clip_rect.top);
      return param_1[1].pnl_wid;
    }
  }
  lVar2 = TPanel::wnd_proc(param_1,param_2,param_3,param_4,param_5);
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_00476032
// Address: 00476032
undefined4 __thiscall
FUN_00476032(TEditPanel *param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)
{
  uint uVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  TPanel *pTVar8;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined1 auStack_10 [16];
  
  uVar2 = param_5;
  iVar6 = param_4;
  uVar1 = param_3;
  if ((((param_1->edit_wnd != (void *)0x0) && (param_1->_padding_ != 0)) &&
      (param_1->_padding_ != 0)) && (param_1->hidden == 0)) {
    if (param_3 < 0x15) {
      if (param_3 == 0x14) {
        if (param_1->brush != (void *)0x0) {
          SelectObject(param_4,param_1->brush);
          GetClientRect(param_2,auStack_10);
          FillRect(iVar6,auStack_10,param_1->brush);
          return 1;
        }
      }
      else if (param_3 == 0xf) {
        InvalidateRect(param_2,0,1);
      }
    }
    else if (param_3 < 0x201) {
      if (param_3 == 0x200) {
        if (rge_base_game->windows_mouse == 0) {
          MouseCursorInChildContol = 1;
          RGE_Base_Game::mouse_off(rge_base_game);
        }
      }
      else {
        switch(param_3) {
        case 0x100:
          if ((int *)param_1->_padding_ == (int *)0x0) {
            if (param_4 == 0x1b) {
              SendMessageA(param_1->edit_wnd,199,0,0);
              return 0;
            }
          }
          else {
            iVar5 = (**(code **)(*(int *)param_1->_padding_ + 0x48))
                              (param_2,param_3,param_4,param_5);
            if (iVar5 != 0) {
              return 0;
            }
            if (iVar6 == 9) {
              sVar3 = GetKeyState(0x12);
              sVar4 = GetKeyState(0x11);
              param_4 = (uint)(sVar4 < 0);
              sVar4 = GetKeyState(0x10);
              DAT_0086b240 = 1;
              (**(code **)(param_1->_padding_ + 0x58))(9,uVar2,sVar3 < 0,param_4,sVar4 < 0);
              DAT_0086b240 = 0;
              return 0;
            }
            if (iVar6 == 0xd) {
              (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,0,0,0);
              return 0;
            }
            if (iVar6 == 0x1b) {
              iVar6 = (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,1,0,0);
              if (iVar6 != 0) {
                return 0;
              }
              SendMessageA(param_1->edit_wnd,199,0,0);
              return 0;
            }
          }
          goto LAB_004762dd;
        case 0x101:
          if (param_4 == 9) {
            return 0;
          }
          break;
        case 0x102:
          iVar6 = TEditPanel::verify_char(param_1,param_4);
          if (iVar6 == 0) {
            return 0;
          }
          break;
        case 0x104:
          if ((param_1->imc == 0) || (param_1->enable_ime == 0)) {
            SetFocus(*(undefined4 *)(param_1->_padding_ + 4));
            PostMessageA(*(undefined4 *)(param_1->_padding_ + 4),uVar1,param_3,param_4);
          }
          return 0;
        }
      }
    }
  }
  iVar6 = param_4;
LAB_004762dd:
  iStack_1c = 0;
  iStack_14 = 0;
  param_3 = 0;
  iStack_18 = 0;
  if ((param_1->edit_wnd == (void *)0x0) || (uVar1 == 0xb0)) {
    param_5 = 0;
  }
  else {
    param_5 = 1;
    SendMessageA(param_1->edit_wnd,0xb0,&iStack_1c,&iStack_14);
  }
  uVar7 = CallWindowProcA(param_1->old_sub_wnd_proc,param_2,uVar1,iVar6,uVar2);
  if ((param_5 != 0) &&
     ((SendMessageA(param_1->edit_wnd,0xb0,&param_3,&iStack_18), param_3 != iStack_1c ||
      (iStack_18 != iStack_14)))) {
    InvalidateRect(param_1->edit_wnd,0,1);
    UpdateWindow(param_1->edit_wnd);
  }
  if (uVar1 == 0x302) {
    TEditPanel::update_text(param_1);
  }
  if ((((uVar1 == 0x201) || (uVar1 == 0x202)) || (uVar1 == 0x204)) || (uVar1 == 0x205)) {
    iVar6 = param_1->_padding_;
    iVar5 = param_1->_padding_;
    pTVar8 = TPanelSystem::currentPanel(&panel_system);
    uVar7 = (**(code **)(pTVar8->_padding_ + 0x48))
                      (*(undefined4 *)(param_1->_padding_ + 4),uVar1,param_4,
                       ((uVar2 >> 0x10) + iVar5) * 0x10000 | iVar6 + (uVar2 & 0xffff) & 0xffff);
  }
  return uVar7;
}

// --------------------------------------------------

// Function: FUN_00476422
// Address: 00476422
// [HELPER] s_10: "10"
/* WARNING: Instruction at (ram,0x00476498) overlaps instruction at (ram,0x00476493)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __fastcall FUN_00476422(int param_1,int param_2)
{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  char cVar5;
  int unaff_EBX;
  undefined1 *puVar6;
  int unaff_EBP;
  undefined4 unaff_ESI;
  int unaff_EDI;
  byte in_CF;
  bool bVar7;
  int aiStack_10 [2];
  int aiStack_8 [2];
  TEditPanel *this;
  
  iVar4 = *(int *)(param_1 + 0x47);
  iVar3 = -(uint)in_CF;
  *(char *)(param_2 + 0x47) = *(char *)(param_2 + 0x47) + (char)in_EAX;
  *(char *)(unaff_EBX + 0x62) = *(char *)(unaff_EBX + 0x62) + (char)unaff_EBX;
  cVar5 = (char)param_1 + (char)unaff_EBX;
  this = (TEditPanel *)CONCAT31((int3)((uint)param_1 >> 8),cVar5);
  if (cVar5 != '\0') {
    *(char *)(unaff_EBP + 0xf5d75c0) = *(char *)(unaff_EBP + 0xf5d75c0) + (char)in_EAX;
    *(char *)(unaff_EBX + 0x10096) = *(char *)(unaff_EBX + 0x10096) + cVar5;
    pcVar2 = (char *)((int)&this->_padding_ + 3);
    *pcVar2 = *pcVar2 + cVar5;
    this[0xaf]._padding_ = this[0xaf]._padding_ >> 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + (char)param_2;
  *(undefined4 *)((int)aiStack_8 + (iVar3 - iVar4) + 4) = unaff_ESI;
  *(int *)((int)aiStack_8 + (iVar3 - iVar4)) = unaff_EDI + 2;
  if (DAT_0086b244 != 0) {
    DAT_0086b244 = 0;
    return 0;
  }
  iVar1 = *(int *)(&stack0x00000004 + (iVar3 - iVar4));
  if (iVar1 == 9) {
    return 0;
  }
  if ((iVar1 == 0xd) && (this->format != FormatMultiLine)) {
    return 0;
  }
  if (iVar1 == 8) {
    return 1;
  }
  *(undefined4 *)((int)aiStack_10 + (iVar3 - iVar4) + 4) = 0x476493;
  TEditPanel::update_text(this);
  puVar6 = (undefined1 *)((int)aiStack_8 + (iVar3 - iVar4));
  if (this->sel_len == 0) {
    if (this->fixed_len + -1 <= this->text_len) {
      *(undefined4 *)((int)aiStack_10 + (iVar3 - iVar4) + 4) = 0xffffffff;
      *(undefined4 *)((int)aiStack_10 + (iVar3 - iVar4)) = 0x4764b7;
      MessageBeep();
      return 0;
    }
    puVar6 = (undefined1 *)((int)aiStack_8 + (iVar3 - iVar4));
    if (this->fixed_len + -2 <= this->text_len) {
      *(int *)((int)aiStack_10 + (iVar3 - iVar4) + 4) = iVar1;
      puVar6 = (undefined1 *)((int)aiStack_10 + (iVar3 - iVar4));
      *(undefined4 *)((int)aiStack_10 + (iVar3 - iVar4)) = 0x4764dd;
      iVar4 = IsDBCSLeadByte();
      if (iVar4 != 0) {
        *(undefined4 *)(puVar6 + -4) = 0xffffffff;
        DAT_0086b244 = 1;
        *(undefined4 *)(puVar6 + -8) = 0x4764f3;
        MessageBeep();
        return 0;
      }
    }
  }
  switch(this->format) {
  default:
    goto switchD_00476509_caseD_0;
  case FormatNumber:
  case FormatInteger:
  case FormatUnsignedInt:
    *(undefined4 *)(puVar6 + -4) = 0x47655a;
    TEditPanel::update_text(this);
    if ((0x2f < iVar1) && (iVar1 < 0x3a)) {
      return 1;
    }
    if (((iVar1 == 0x2d) && (*this->text == '\0')) && (this->format != FormatUnsignedInt)) {
      return 1;
    }
    if (iVar1 != 0x2e) goto LAB_00476634;
    pcVar2 = this->text;
    *(undefined4 *)(puVar6 + -4) = 0x2e;
    *(char **)(puVar6 + -8) = pcVar2;
    *(undefined4 *)(puVar6 + -0xc) = 0x47659b;
    iVar4 = __mbschr();
    if (iVar4 == 0) goto LAB_00476634;
    bVar7 = this->format == FormatNumber;
    break;
  case FormatFile:
  case FormatFileNoExt:
    *(undefined4 *)(puVar6 + -4) = 0x4765c9;
    TEditPanel::update_text(this);
    if (iVar1 == 0x2e) {
      if (this->format == FormatFile) {
        pcVar2 = this->text;
        *(undefined4 *)(puVar6 + -4) = 0x2e;
        *(char **)(puVar6 + -8) = pcVar2;
        *(undefined4 *)(puVar6 + -0xc) = 0x4765e4;
        iVar4 = __mbschr();
        if (iVar4 == 0) {
          return 1;
        }
      }
      goto LAB_00476634;
    }
    if ((iVar1 == 0x5c) || (iVar1 == 0x3a)) goto LAB_00476634;
    goto LAB_00476611;
  case FormatPath:
    *(undefined4 *)(puVar6 + -4) = 0x476603;
    TEditPanel::update_text(this);
    if ((iVar1 == 0x3a) && (this->text_len != 1)) goto LAB_00476634;
LAB_00476611:
    if (((iVar1 != 0x2f) && (((iVar1 != 0x22 && (iVar1 != 0x2a)) && (iVar1 != 0x3f)))) &&
       (((iVar1 != 0x3e && (iVar1 != 0x3c)) && (iVar1 != 0x7c)))) {
      return 1;
    }
LAB_00476634:
    *(undefined4 *)(puVar6 + -4) = 0xffffffff;
    *(undefined4 *)(puVar6 + -8) = 0x47663c;
    MessageBeep();
    return 0;
  case FormatPercent:
    if (((this->text_len < 2) && (0x2f < iVar1)) && (iVar1 < 0x3a)) {
      return 1;
    }
    if ((this->text_len != 2) || (iVar1 != 0x30)) goto LAB_00476634;
    *(char **)(puVar6 + -4) = this->text;
    *(char **)(puVar6 + -8) = s_10;
    *(undefined4 *)(puVar6 + -0xc) = 0x47654c;
    iVar4 = __mbscmp();
    bVar7 = iVar4 == 0;
  }
  if (!bVar7) {
    *(undefined4 *)(puVar6 + -4) = 0xffffffff;
    *(undefined4 *)(puVar6 + -8) = 0x4765bb;
    MessageBeep();
    return 0;
  }
switchD_00476509_caseD_0:
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047664d
// Address: 0047664d
// [HELPER] s_pnl_edit__draw: "pnl_edit::draw"
void __fastcall FUN_0047664d(int *param_1,char param_2)
{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uchar uVar6;
  int *piVar7;
  char cVar8;
  byte bVar9;
  undefined4 in_EAX;
  char *pcVar10;
  uchar *puVar11;
  int iVar12;
  void *pvVar13;
  undefined4 uVar14;
  int iVar15;
  int unaff_EBX;
  int iVar16;
  undefined4 unaff_EDI;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  *(char *)(unaff_EBX + 0x66) = *(char *)(unaff_EBX + 0x66) + param_2;
  *(char *)(unaff_EBX + 0x66) = *(char *)(unaff_EBX + 0x66) + param_2;
  *(char *)(unaff_EBX + 0x66) = *(char *)(unaff_EBX + 0x66) + param_2;
  cVar8 = (char)in_EAX;
  param_2 = param_2 + cVar8 * '\x02';
  pcVar10 = (char *)CONCAT22((short)((uint)in_EAX >> 0x10),
                             CONCAT11((char)((uint)in_EAX >> 8) + (char)((uint)(unaff_EBX + 1) >> 8)
                                      ,cVar8));
  *(char *)(unaff_EBX + 0x67) = *(char *)(unaff_EBX + 0x67) + cVar8;
  *pcVar10 = *pcVar10 + param_2;
  pcVar10[-0x6f6f6f70] = pcVar10[-0x6f6f6f70] + param_2;
  param_1[0xe] = 0;
  if (param_1[0x1c] == 0) {
    return;
  }
  iVar16 = *param_1;
  iStack_14 = iVar16;
  (**(code **)(iVar16 + 0x28))
            (0,unaff_EBX + 1,CONCAT22((short)((uint)unaff_EDI >> 0x10),(short)unaff_EDI + 1) + 8);
  if (((param_1[0x42] == 0) || (param_1[0x1b] == 0)) || (param_1[0x1e] == 0)) {
    piVar7 = (int *)param_1[0x10];
    if (piVar7 == (int *)0x0) {
      bVar9 = *(byte *)((int)param_1 + 0xef);
      goto LAB_00476722;
    }
    if ((param_1[0x54] < 2) || (7 < param_1[0x54])) {
      if (piVar7[0x21] == 0) {
        (**(code **)(*piVar7 + 0x34))(param_1 + 9);
      }
    }
    else {
      (**(code **)(*piVar7 + 0x3c))(param_1 + 9);
    }
  }
  else {
    bVar9 = GetNearestPaletteIndex(*(undefined4 *)(*(int *)param_1[8] + 8),param_1[0x49]);
LAB_00476722:
    TDrawArea::Clear((TDrawArea *)param_1[8],(tagRECT *)(param_1 + 9),(uint)bVar9);
  }
  if (param_1[0x54] == 0) goto LAB_004768c7;
  puVar11 = TDrawArea::Lock((TDrawArea *)param_1[8],s_pnl_edit__draw,1);
  if (puVar11 == (uchar *)0x0) goto switchD_0047675d_default;
  switch(param_1[0x54]) {
  case 1:
    TDrawArea::DrawRect((TDrawArea *)param_1[8],param_1[3],param_1[4],param_1[5] + -1 + param_1[3],
                        param_1[6] + -1 + param_1[4],(uchar)param_1[0x55]);
    break;
  case 2:
    uVar3 = (uchar)param_1[0x55];
    iVar12 = param_1[4];
    iVar15 = param_1[3];
    uVar1 = *(uchar *)((int)param_1 + 0x159);
    goto LAB_00476812;
  case 3:
    uVar3 = (uchar)param_1[0x55];
    iVar12 = param_1[4];
    iVar15 = param_1[3];
    uVar1 = *(uchar *)((int)param_1 + 0x155);
    uVar4 = (uchar)param_1[0x56];
    uVar5 = *(uchar *)((int)param_1 + 0x159);
    goto LAB_00476853;
  case 4:
    uVar3 = (uchar)param_1[0x55];
    iVar12 = param_1[4];
    uVar1 = *(uchar *)((int)param_1 + 0x155);
    uVar4 = *(uchar *)((int)param_1 + 0x156);
    iVar15 = param_1[3];
    uVar5 = *(uchar *)((int)param_1 + 0x157);
    uVar6 = (uchar)param_1[0x56];
    uVar2 = *(uchar *)((int)param_1 + 0x159);
    goto LAB_0047689f;
  case 5:
    uVar3 = *(uchar *)((int)param_1 + 0x159);
    iVar12 = param_1[4];
    iVar15 = param_1[3];
    uVar1 = (uchar)param_1[0x55];
LAB_00476812:
    TDrawArea::DrawBevel
              ((TDrawArea *)param_1[8],iVar15,iVar12,param_1[5] + -1 + iVar15,
               param_1[6] + -1 + iVar12,uVar1,uVar3);
    break;
  case 6:
    uVar3 = *(uchar *)((int)param_1 + 0x159);
    iVar12 = param_1[4];
    iVar15 = param_1[3];
    uVar1 = (uchar)param_1[0x56];
    uVar4 = *(uchar *)((int)param_1 + 0x155);
    uVar5 = (uchar)param_1[0x55];
LAB_00476853:
    TDrawArea::DrawBevel2
              ((TDrawArea *)param_1[8],iVar15,iVar12,param_1[5] + -1 + iVar15,
               param_1[6] + -1 + iVar12,uVar5,uVar4,uVar1,uVar3);
    break;
  case 7:
    uVar3 = *(uchar *)((int)param_1 + 0x159);
    iVar12 = param_1[4];
    uVar1 = (uchar)param_1[0x56];
    uVar4 = *(uchar *)((int)param_1 + 0x157);
    iVar15 = param_1[3];
    uVar5 = *(uchar *)((int)param_1 + 0x156);
    uVar6 = *(uchar *)((int)param_1 + 0x155);
    uVar2 = (uchar)param_1[0x55];
LAB_0047689f:
    TDrawArea::DrawBevel3
              ((TDrawArea *)param_1[8],iVar15,iVar12,param_1[5] + -1 + iVar15,
               param_1[6] + -1 + iVar12,uVar2,uVar6,uVar5,uVar4,uVar1,uVar3);
  }
switchD_0047675d_default:
  TDrawArea::Unlock((TDrawArea *)param_1[8],s_pnl_edit__draw);
LAB_004768c7:
  iVar12 = param_1[0x3d];
  if ((iVar12 != 0) && (param_1[0x1b] != 0)) {
    if (param_1[0x1e] == 0) {
      if (param_1[0x41] == 0) {
        ShowWindow(iVar12,0);
        param_1[0x41] = 1;
      }
      pvVar13 = TDrawArea::GetDc((TDrawArea *)param_1[8],s_pnl_edit__draw);
      if (pvVar13 != (void *)0x0) {
        SelectClipRgn(pvVar13,param_1[0x22]);
        uVar14 = SelectObject(pvVar13,param_1[0x4b]);
        SetBkMode(pvVar13,1);
        SetTextColor(pvVar13,param_1[0x46]);
        iStack_14 = param_1[0x4d] + -1;
        iStack_10 = param_1[0x4e] + 1;
        iStack_c = param_1[0x4f] + -1;
        iStack_8 = param_1[0x50] + 1;
        DrawTextExA(pvVar13,param_1[0x3f],0xffffffff,&iStack_14,param_1[0x51],0);
        SetTextColor(pvVar13,param_1[0x45]);
        DrawTextExA(pvVar13,param_1[0x3f],0xffffffff,param_1 + 0x4d,param_1[0x51],0);
        SelectObject(pvVar13,uVar14);
        SelectClipRgn(pvVar13,0);
        TDrawArea::ReleaseDc((TDrawArea *)param_1[8],s_pnl_edit__draw);
        iVar16 = iStack_18;
      }
    }
    else if (param_1[0x41] != 0) {
      ShowWindow(iVar12,5);
      InvalidateRect(param_1[0x3d],0,1);
      param_1[0x41] = 0;
      (**(code **)(iVar16 + 0x2c))();
      return;
    }
  }
  (**(code **)(iVar16 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_00476a51
// Address: 00476a51
undefined4 __fastcall FUN_00476a51(TEditPanel *param_1)
{
  int iVar1;
  char *pcVar2;
  
  TEditPanel::update_text(param_1);
  pcVar2 = param_1->text;
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    for (; *pcVar2 != '\0'; pcVar2 = (char *)__mbsinc(pcVar2)) {
      iVar1 = __ismbcspace(*pcVar2);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00476aa7
// Address: 00476aa7
undefined4 * __thiscall FUN_00476aa7(TEditPanel *param_1,undefined4 *param_2,uint param_3)
{
  char cVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint *puVar9;
  uint auStack_100 [64];
  
  TEditPanel::update_text(param_1);
  puVar2 = auStack_100;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = param_1->text;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  puVar2 = (uint *)(pcVar8 + -uVar5);
  puVar9 = auStack_100;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar9 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar9 = puVar9 + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)puVar9 = (char)*puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
    puVar9 = (uint *)((int)puVar9 + 1);
  }
  puVar3 = param_2;
  for (uVar5 = param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar2 = auStack_100;
  iVar4 = __ismbcspace(auStack_100[0] & 0xff);
  while (iVar4 != 0) {
    puVar2 = (uint *)__mbsinc(puVar2);
    iVar4 = __ismbcspace((char)*puVar2);
  }
  cVar1 = (char)*puVar2;
  puVar3 = param_2;
  while (cVar1 != '\0') {
    __mbsncpy(puVar3,puVar2,1);
    puVar3 = (undefined4 *)__mbsinc(puVar3);
    puVar2 = (uint *)__mbsinc(puVar2);
    cVar1 = (char)*puVar2;
  }
  do {
    *(undefined1 *)puVar3 = 0;
    if (puVar3 == param_2) {
      return param_2;
    }
    puVar3 = (undefined4 *)__mbsdec(param_2,puVar3);
    iVar4 = __ismbcspace(*(undefined1 *)puVar3);
  } while (iVar4 != 0);
  return param_2;
}

// --------------------------------------------------

// Function: FUN_00476ba8
// Address: 00476ba8
void __fastcall FUN_00476ba8(int param_1)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xf4) != 0) && (*(int *)(param_1 + 0x78) != 0)) {
    iVar1 = GetFocus();
    if (iVar1 != *(int *)(param_1 + 0xf4)) {
      SetFocus(*(int *)(param_1 + 0xf4));
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00476bdd
// Address: 00476bdd
void __thiscall
FUN_00476bdd(TPanel *param_1,uchar param_2,long param_3,long param_4,int param_5,int param_6)
{
  TPanel::handle_mouse_down(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_00476c01
// Address: 00476c01
TTextPanel * __fastcall FUN_00476c01(TTextPanel *param_1)
{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e488;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TTextPanel::TTextPanel(param_1);
  uStack_4 = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  iVar1 = GetCaretBlinkTime();
  param_1[1]._padding_ = iVar1;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 1;
  param_1[1]._padding_ = 1;
  param_1->_padding_ = 1;
  param_1->bevel_type = 1;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *(undefined2 *)&param_1[1]._padding_ = 0;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0;
  *(undefined2 *)&param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TInputPanel::_vftable_;
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 7;
  param_1->horz_align = AlignHorizontalScroll;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00476cc5
// Address: 00476cc5
TInputPanel * __thiscall FUN_00476cc5(TInputPanel *param_1,byte param_2)
{
  TInputPanel::~TInputPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00476cee
// Address: 00476cee
void __fastcall FUN_00476cee(TTextPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e4a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TInputPanel::_vftable_;
  uStack_4 = 0;
  if ((void *)param_1[1]._padding_ != (void *)0x0) {
    operator_delete((void *)param_1[1]._padding_);
    param_1[1]._padding_ = 0;
  }
  if ((void *)param_1[1]._padding_ != (void *)0x0) {
    operator_delete((void *)param_1[1]._padding_);
    param_1[1]._padding_ = 0;
  }
  param_1[1]._padding_ = 0;
  param_1->_padding_ = 1;
  uStack_4 = 0xffffffff;
  TTextPanel::~TTextPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00476d7c
// Address: 00476d7c
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
undefined4 __thiscall
FUN_00476d7c(TInputPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,void *param_8,long param_9,long param_10,char *param_11,
            int param_12,uchar param_13,int param_14,uchar param_15,uchar param_16,short param_17,
            TDigital *param_18,undefined4 param_19,FormatType param_20)
{
  int iVar1;
  short sVar2;
  long lVar3;
  ulong uVar4;
  char *pcVar5;
  
  sVar2 = param_17;
  if (param_20 == FormatMultiLine) {
    sVar2 = 0;
  }
  lVar3 = TTextPanel::setup((TTextPanel *)param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                            param_8,param_9,param_10,param_11,param_12,param_13,param_14,param_15,
                            sVar2,(char *)0x0);
  if (lVar3 == 0) {
    return 0;
  }
  param_1->caret_color = param_16;
  param_1->format_type = param_20;
  if (param_1->_padding_ != 0) {
    param_1->draw_caret = 1;
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x59);
    param_1->caret_last_time = uVar4;
  }
  if (param_17 == 0) {
    param_1->overLengthSound = (TDigital *)0x0;
  }
  else {
    param_1->overLengthSound = param_18;
  }
  if (param_1->format_type == FormatMultiLine) {
    TTextPanel::set_alignment((TTextPanel *)param_1,AlignTop,AlignLeft);
    TTextPanel::set_word_wrap((TTextPanel *)param_1,1);
  }
  else {
    TTextPanel::set_alignment((TTextPanel *)param_1,AlignCenter,AlignHorizontalScroll);
  }
  iVar1 = param_17 * 2 + 1;
  pcVar5 = (char *)calloc(iVar1,1);
  param_1->input_buffer1 = pcVar5;
  if (pcVar5 != (char *)0x0) {
    pcVar5 = (char *)calloc(iVar1,1);
    param_1->input_buffer2 = pcVar5;
    if (pcVar5 != (char *)0x0) {
      param_1->input_buffer = param_1->input_buffer1;
      (**(code **)(param_1->_padding_ + 0xe8))(param_19);
      param_1->max_len = param_17;
      TInputPanel::reformat(param_1);
      return 1;
    }
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00476f1a
// Address: 00476f1a
void __thiscall FUN_00476f1a(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x19c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00476f2d
// Address: 00476f2d
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
void __fastcall FUN_00476f2d(TPanel *param_1)
{
  int iVar1;
  ulong uVar2;
  
  if (param_1->have_focus != 0) {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x9e);
    if ((uint)param_1[1].render_rect.bottom <= uVar2 - param_1[1].left_border) {
      iVar1 = param_1->_padding_;
      param_1[1].top_border = (uint)(param_1[1].top_border == 0);
      (**(code **)(iVar1 + 0x20))(1);
      uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0xa3);
      param_1[1].left_border = uVar2;
    }
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00476f9b
// Address: 00476f9b
// [HELPER] s_10: "10"
undefined4 __thiscall FUN_00476f9b(TInputPanel *param_1,int param_2,short param_3)
{
  FormatType FVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  
  if ((((param_2 != 8) && (param_2 != 9)) && (param_2 != 10)) &&
     (((param_2 != 0xd && (param_2 != 0x1b)) && (0x1a < param_2)))) {
    if (param_3 == 0) {
      param_3 = 1;
    }
    sVar5 = 0;
    if (0 < param_3) {
      do {
        FVar1 = param_1->format_type;
        switch(FVar1) {
        case FormatNumber:
        case FormatInteger:
        case FormatUnsignedInt:
          if ((((param_2 < 0x30) || (0x39 < param_2)) &&
              (((param_2 != 0x2d || (*param_1->input_buffer != '\0')) ||
               (FVar1 == FormatUnsignedInt)))) &&
             (((param_2 != 0x2e || (iVar4 = __mbschr(param_1->input_buffer,0x2e), iVar4 == 0)) ||
              (param_1->format_type != FormatNumber)))) goto LAB_004771ae;
          break;
        case FormatFile:
        case FormatFileNoExt:
          if (param_2 == 0x2e) {
            if ((FVar1 != FormatFile) || (iVar4 = __mbschr(param_1->input_buffer,0x2e), iVar4 != 0))
            goto LAB_004771ae;
          }
          else if (((param_2 == 0x5c) ||
                   (((param_2 == 0x3a || (param_2 == 0x2f)) || (param_2 == 0x22)))) ||
                  (((param_2 == 0x2a || (param_2 == 0x3f)) ||
                   ((param_2 == 0x3e || ((param_2 == 0x3c || (param_2 == 0x7c)))))))) {
LAB_004771ae:
            if (param_1->overLengthSound != (TDigital *)0x0) {
              TDigital::play(param_1->overLengthSound);
              return 1;
            }
LAB_004771e4:
            MessageBeep(0xffffffff);
            return 1;
          }
          break;
        case FormatPath:
          if ((((((param_2 == 0x3a) && (param_1->input_len != 1)) || (param_2 == 0x2f)) ||
               ((param_2 == 0x22 || (param_2 == 0x2a)))) || (param_2 == 0x3f)) ||
             (((param_2 == 0x3e || (param_2 == 0x3c)) || (param_2 == 0x7c)))) {
            if (param_1->overLengthSound != (TDigital *)0x0) {
              TDigital::play(param_1->overLengthSound);
              return 1;
            }
            goto LAB_004771e4;
          }
          break;
        case FormatPercent:
          pcVar2 = TTextPanel::get_text((TTextPanel *)param_1);
          uVar3 = __mbslen(pcVar2);
          if (((1 < uVar3) || (param_2 < 0x30)) || (0x39 < param_2)) {
            pcVar2 = TTextPanel::get_text((TTextPanel *)param_1);
            iVar4 = __mbslen(pcVar2);
            if ((iVar4 == 2) && (param_2 == 0x30)) {
              pcVar2 = TTextPanel::get_text((TTextPanel *)param_1);
              iVar4 = __mbscmp(s_10,pcVar2);
              if (iVar4 == 0) break;
            }
            if (param_1->overLengthSound != (TDigital *)0x0) {
              TDigital::play(param_1->overLengthSound);
              return 1;
            }
            goto LAB_004771e4;
          }
        }
        iVar4 = TInputPanel::insert_character(param_1,param_2);
        if (iVar4 == 0) {
          return 1;
        }
        sVar5 = sVar5 + 1;
        if (param_3 <= sVar5) {
          return 1;
        }
      } while( true );
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00477729
// Address: 00477729
// [HELPER] s_pnl_inp__draw: "pnl_inp::draw"
/* WARNING: Instruction at (ram,0x0047778e) overlaps instruction at (ram,0x0047778d)
    */

void __fastcall FUN_00477729(TTextPanel *param_1,undefined4 param_2)
{
  byte *pbVar1;
  char *pcVar2;
  byte bVar6;
  char *in_EAX;
  void *pvVar3;
  undefined4 uVar4;
  uchar *puVar5;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  byte bVar11;
  int unaff_EBX;
  int unaff_EBP;
  byte *unaff_ESI;
  int unaff_EDI;
  int iVar12;
  bool in_CF;
  byte in_PF;
  byte in_AF;
  bool in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  int iStack_110;
  tagRECT atStack_10c [16];
  uint uStack_4;
  byte *pbVar10;
  
  uStack_4 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
             (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
             (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1) |
             (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
             (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  bVar7 = (byte)param_1;
  if (in_CF || in_ZF) {
code_r0x00477776:
    param_1 = (TTextPanel *)CONCAT31((int3)((uint)param_1 >> 8),bVar7 + *unaff_ESI);
  }
  else {
    pbVar10 = (byte *)(unaff_EBP + -0x16ffb88a);
    bVar9 = *pbVar10;
    bVar6 = (byte)((uint)param_1 >> 8);
    *pbVar10 = *pbVar10 + bVar6;
    if (!CARRY1(bVar9,bVar6) && *pbVar10 != 0) {
      *(byte *)&param_1->_padding_ = (char)param_1->_padding_ + bVar6;
      if ((char)param_1->_padding_ == '\0') {
        pcVar2 = (char *)(unaff_EBP + 0x746a0047 + (int)unaff_ESI * 2);
        *pcVar2 = *pcVar2 + bVar7;
        bVar11 = (byte)((uint)param_2 >> 8);
        bVar9 = (byte)param_2;
        pbVar10 = (byte *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(bVar11 + bVar6,bVar9));
        if (CARRY1(bVar11,bVar6)) {
          *(char *)(unaff_EBX + 0x72) = *(char *)(unaff_EBX + 0x72) + (char)in_EAX;
          iVar12 = param_1->_padding_;
          *(byte *)&param_1->_padding_ = (char)param_1->_padding_ + bVar9;
          if (!CARRY1((byte)iVar12,bVar9)) goto code_r0x004777ae;
          pbVar1 = pbVar10 + -0x6cffb88e;
          bVar6 = *pbVar1;
          *pbVar1 = *pbVar1 + bVar7;
          if (!CARRY1(bVar6,bVar7)) goto code_r0x004777ae;
          bVar6 = (byte)((uint)in_EAX >> 8);
          *(char *)(unaff_EDI + 0x78) = *(char *)(unaff_EDI + 0x78) + bVar6;
          unaff_ESI[0x76] = unaff_ESI[0x76] + bVar9;
          iVar12 = param_1->_padding_;
          *(byte *)&param_1->_padding_ = (char)param_1->_padding_ + bVar7;
          if ((!CARRY1((byte)iVar12,bVar7) && (char)param_1->_padding_ != '\0') ||
             (bVar9 = *pbVar10, *pbVar10 = *pbVar10 + bVar6, !CARRY1(bVar9,bVar6) && *pbVar10 != 0))
          goto code_r0x004777ae;
          *in_EAX = *in_EAX + (char)in_EAX;
          *(int *)unaff_ESI = (int)&param_1->_padding_ + *(int *)unaff_ESI;
          goto code_r0x00477776;
        }
      }
      else {
        *(byte *)&param_1->_padding_ = (byte)param_1->_padding_ | bVar7;
      }
    }
  }
  uVar8 = CONCAT31((int3)((uint)param_1 >> 8),(byte)param_1 | *unaff_ESI);
  param_1 = (TTextPanel *)(uVar8 | *(uint *)(unaff_ESI + uVar8));
code_r0x004777ae:
  TTextPanel::draw(param_1);
  if ((((param_1->_padding_ != 0) && (param_1->_padding_ != 0)) && (param_1->_padding_ != 0)) &&
     (((param_1->_padding_ != 0 && (param_1[1]._padding_ != 0)) &&
      ((param_1->top_line <= param_1->cur_line && (param_1->cur_line <= param_1->bot_line)))))) {
    atStack_10c[0].left = param_1->_padding_;
    (**(code **)(atStack_10c[0].left + 0x28))(0);
    pvVar3 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_pnl_inp__draw);
    if (pvVar3 != (void *)0x0) {
      uVar4 = SelectObject(pvVar3,param_1->font);
      TTextPanel::calc_line_pos
                (param_1,pvVar3,param_1->cur_line - param_1->top_line,param_1->cur_line,atStack_10c,
                 (long *)&stack0xfffffeec);
      SelectObject(pvVar3,uVar4);
      TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_pnl_inp__draw);
      puVar5 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_pnl_inp__draw,1);
      if (puVar5 != (uchar *)0x0) {
        pbVar10 = unaff_ESI + atStack_10c[0].left;
        iVar12 = (atStack_10c[0].bottom - atStack_10c[0].top) + 1;
        if ((int)pbVar10 < param_1->_padding_) {
          TDrawArea::DrawVertLine
                    ((TDrawArea *)param_1->_padding_,(long)pbVar10,atStack_10c[0].top,iVar12,
                     (uchar)param_1[1]._padding_);
          TDrawArea::DrawVertLine
                    ((TDrawArea *)param_1->_padding_,(long)(pbVar10 + 1),atStack_10c[0].top,iVar12,
                     (uchar)param_1[1]._padding_);
        }
        TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_pnl_inp__draw);
      }
    }
    (**(code **)(iStack_110 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047790a
// Address: 0047790a
void __thiscall FUN_0047790a(TInputPanel *param_1,int param_2)
{
  char *pcVar1;
  FormatType FVar2;
  short sVar3;
  
  pcVar1 = param_1->input_buffer;
  if (pcVar1 != (char *)0x0) {
    if (param_2 == 0) {
      *pcVar1 = '\0';
    }
    else {
      __mbscpy(pcVar1,param_2);
    }
    sVar3 = __mbslen(param_1->input_buffer);
    FVar2 = param_1->format_type;
    param_1->input_len = sVar3;
    param_1->input_pos = 0;
    *(undefined2 *)&param_1->_padding_ = 0;
    *(undefined2 *)((int)&param_1->_padding_ + 2) = 0;
    if ((FVar2 != FormatMultiLine) && (0 < sVar3)) {
      param_1->input_pos = sVar3;
      *(short *)((int)&param_1->_padding_ + 2) = sVar3;
    }
    TInputPanel::reformat(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047798d
// Address: 0047798d
void FUN_0047798d(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00477993
// Address: 00477993
undefined4 __fastcall FUN_00477993(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1a0);
}

// --------------------------------------------------

// Function: FUN_004779a7
// Address: 004779a7
void __thiscall FUN_004779a7(TInputPanel *param_1,long param_2)
{
  param_1->input_pos = param_1->input_len;
  TInputPanel::insert_character(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004779cb
// Address: 004779cb
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
undefined4 __fastcall FUN_004779cb(TInputPanel *param_1)
{
  char *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  ulong uVar4;
  
  if (param_1->input_len < param_1->max_len) {
    pcVar2 = param_1->input_buffer1;
    if (param_1->input_buffer == pcVar2) {
      pcVar1 = pcVar2;
      pcVar2 = param_1->input_buffer2;
    }
    else {
      pcVar1 = param_1->input_buffer2;
    }
    param_1->input_buffer = pcVar2;
    *pcVar2 = '\0';
    if (0 < param_1->input_pos) {
      __mbsncpy(pcVar2,pcVar1,(int)param_1->input_pos);
      pcVar1 = (char *)__mbsninc(pcVar1,(int)param_1->input_pos);
      pcVar2 = (char *)__mbsninc(pcVar2,(int)param_1->input_pos);
    }
    __mbsncpy(pcVar2,&stack0x00000004,1);
    uVar3 = __mbsinc(pcVar2);
    __mbsncpy(uVar3,pcVar1,((int)param_1->input_len - (int)param_1->input_pos) + 1);
    param_1->input_len = param_1->input_len + 1;
    param_1->input_pos = param_1->input_pos + 1;
    TInputPanel::reformat(param_1);
    TInputPanel::calc_cur_line_col(param_1);
    param_1->draw_caret = 1;
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x28f);
    param_1->caret_last_time = uVar4;
    return 1;
  }
  if (param_1->overLengthSound != (TDigital *)0x0) {
    TDigital::play(param_1->overLengthSound);
    return 0;
  }
  MessageBeep(0xffffffff);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00477aef
// Address: 00477aef
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
undefined4 __fastcall FUN_00477aef(TInputPanel *param_1)
{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  ulong uVar5;
  short sVar6;
  char *pcStack_8;
  
  if (param_1->input_len <= param_1->input_pos) {
    return 0;
  }
  pcVar3 = param_1->input_buffer1;
  bVar1 = false;
  if (param_1->input_buffer == pcVar3) {
    pcVar4 = pcVar3;
    pcVar3 = param_1->input_buffer2;
  }
  else {
    pcVar4 = param_1->input_buffer2;
  }
  param_1->input_buffer = pcVar3;
  *pcVar3 = '\0';
  pcVar2 = pcVar4;
  pcStack_8 = pcVar3;
  if (0 < param_1->input_pos) {
    __mbsncpy(pcVar3,pcVar4,(int)param_1->input_pos);
    pcVar2 = (char *)__mbsninc(pcVar4,(int)param_1->input_pos);
    pcStack_8 = (char *)__mbsninc(pcVar3,(int)param_1->input_pos);
  }
  if (*pcVar2 == '\r') {
    pcVar3 = (char *)__mbsinc(pcVar2);
    sVar6 = 1;
    if (*pcVar3 == '\n') {
      pcVar3 = (char *)__mbsinc(pcVar3);
      sVar6 = 2;
    }
  }
  else {
    if ((*pcVar2 == '\n') && (pcVar4 < pcVar2)) {
      pcVar4 = (char *)__mbsdec(pcVar4,pcVar2);
      if (*pcVar4 == '\r') {
        pcStack_8 = (char *)__mbsdec(pcVar3,pcStack_8);
        pcVar3 = (char *)__mbsninc(pcVar4,2);
        sVar6 = 2;
        bVar1 = true;
        goto LAB_00477c15;
      }
      pcVar3 = (char *)__mbsninc(pcVar4,2);
    }
    else {
      pcVar3 = (char *)__mbsinc(pcVar2);
    }
    sVar6 = 1;
  }
LAB_00477c15:
  __mbsncpy(pcStack_8,pcVar3,((int)param_1->input_len - (int)param_1->input_pos) + 1);
  if (bVar1) {
    param_1->input_pos = param_1->input_pos + -1;
  }
  param_1->input_len = param_1->input_len - sVar6;
  TInputPanel::reformat(param_1);
  TInputPanel::calc_cur_line_col(param_1);
  param_1->draw_caret = 1;
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x2f6);
  param_1->caret_last_time = uVar5;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00477c88
// Address: 00477c88
int __fastcall FUN_00477c88(TInputPanel *param_1)
{
  int iVar1;
  
  if (0 < param_1->input_pos) {
    param_1->input_pos = param_1->input_pos + -1;
    iVar1 = TInputPanel::delete_character(param_1);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00477cac
// Address: 00477cac
// [HELPER] s_C__msdev_work_age1_x1_Pnl_inp_cp: "C:\msdev\work\age1_x1\Pnl_inp.cpp"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

undefined4 __fastcall FUN_00477cac(TInputPanel *param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  undefined4 auStack_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x477cba;
  iVar7 = 0;
  auStack_1000[0]._0_1_ = 0;
  iVar1 = IsClipboardFormatAvailable(1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = OpenClipboard(*(undefined4 *)(param_1->_padding_ + 4));
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = GetClipboardData(1);
  if (iVar1 != 0) {
    iVar2 = GlobalLock(iVar1);
    if (iVar2 != 0) {
      iVar7 = __mbslen(iVar2);
      if (0xfff < iVar7) {
        iVar7 = 0xfff;
      }
      puVar9 = auStack_1000;
      for (iVar6 = 0x400; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      __mbsncpy(auStack_1000,iVar2,iVar7);
      GlobalUnlock(iVar1);
    }
  }
  CloseClipboard();
  if ((int)param_1->max_len <= iVar7 + param_1->input_len) {
    if (param_1->overLengthSound != (TDigital *)0x0) {
      TDigital::play(param_1->overLengthSound);
      return 0;
    }
    MessageBeep(0xffffffff);
    return 0;
  }
  pcVar10 = param_1->input_buffer1;
  if (param_1->input_buffer == pcVar10) {
    pcVar8 = pcVar10;
    pcVar10 = param_1->input_buffer2;
  }
  else {
    pcVar8 = param_1->input_buffer2;
  }
  param_1->input_buffer = pcVar10;
  *pcVar10 = '\0';
  __mbsncpy(pcVar10,pcVar8,(int)param_1->input_pos);
  uVar3 = __mbsninc(pcVar8,(int)param_1->input_pos);
  uVar4 = __mbsninc(pcVar10,(int)param_1->input_pos);
  __mbsncpy(uVar4,auStack_1000,iVar7);
  uVar4 = __mbsninc(uVar4,iVar7);
  __mbsncpy(uVar4,uVar3,((int)param_1->input_len - (int)param_1->input_pos) + 1);
  param_1->input_len = param_1->input_len + (short)iVar7;
  param_1->input_pos = param_1->input_pos + (short)iVar7;
  TInputPanel::reformat(param_1);
  TInputPanel::calc_cur_line_col(param_1);
  param_1->draw_caret = 1;
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_inp_cp,0x362);
  param_1->caret_last_time = uVar5;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00477e88
// Address: 00477e88
void __fastcall FUN_00477e88(TTextPanel *param_1)
{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar1 = param_1->top_line;
  sVar3 = param_1->cur_line;
  TTextPanel::set_text(param_1,(char *)param_1[1]._padding_);
  sVar2 = param_1->num_lines;
  if (sVar2 <= sVar3) {
    sVar3 = sVar2 + -1;
  }
  param_1->cur_line = sVar3;
  if (sVar2 <= sVar1) {
    param_1->top_line = sVar2 + -1;
  }
  TTextPanel::scroll(param_1,'\x01',sVar1,1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00477eeb
// Address: 00477eeb
void __fastcall FUN_00477eeb(TTextPanel *param_1)
{
  TextNode *pTVar1;
  short sVar2;
  short sVar3;
  
  pTVar1 = param_1->list;
  *(undefined2 *)&param_1[1]._padding_ = 0;
  for (sVar3 = 0; (pTVar1 != (TextNode *)0x0 && (sVar3 < param_1->cur_line)); sVar3 = sVar3 + 1) {
    sVar2 = __mbslen(pTVar1->text);
    *(short *)&param_1[1]._padding_ = (short)param_1[1]._padding_ + sVar2;
    pTVar1 = pTVar1->next_node;
  }
  sVar3 = param_1->cur_col;
  *(short *)&param_1[1]._padding_ = (short)param_1[1]._padding_ + sVar3;
  sVar2 = (short)param_1[1]._padding_;
  if (((0 < sVar3) && (0 < sVar2)) && (*(char *)(param_1[1]._padding_ + -1 + (int)sVar2) == '\n')) {
    *(short *)&param_1[1]._padding_ = sVar2 + -1;
    param_1->cur_col = sVar3 + -1;
  }
  sVar3 = param_1->cur_col;
  if (((0 < sVar3) && (sVar2 = (short)param_1[1]._padding_, 0 < sVar2)) &&
     (*(char *)(param_1[1]._padding_ + -1 + (int)sVar2) == '\r')) {
    *(short *)&param_1[1]._padding_ = sVar2 + -1;
    param_1->cur_col = sVar3 + -1;
  }
  if (param_1->cur_line < param_1->top_line) {
    do {
      TTextPanel::scroll(param_1,'\x03',1,1);
    } while (param_1->cur_line < param_1->top_line);
  }
  if (param_1->bot_line < param_1->cur_line) {
    do {
      TTextPanel::scroll(param_1,'\x02',1,1);
    } while (param_1->bot_line < param_1->cur_line);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00478002
// Address: 00478002
void __fastcall FUN_00478002(TTextPanel *param_1)
{
  TextNode *pTVar1;
  short sVar2;
  short sVar3;
  
  pTVar1 = param_1->list;
  param_1->cur_line = 0;
  param_1->cur_col = 0;
  for (sVar3 = 0;
      ((pTVar1 != (TextNode *)0x0 && ((int)param_1->cur_line != param_1->num_lines + -1)) &&
      (sVar2 = __mbslen(pTVar1->text), (int)sVar3 + (int)sVar2 <= (int)(short)param_1[1]._padding_))
      ; sVar3 = sVar3 + sVar2) {
    param_1->cur_line = param_1->cur_line + 1;
    pTVar1 = pTVar1->next_node;
  }
  sVar2 = (short)param_1[1]._padding_;
  param_1->cur_col = sVar2 - sVar3;
  if (((0 < (short)(sVar2 - sVar3)) && (0 < sVar2)) &&
     (*(char *)(param_1[1]._padding_ + -1 + (int)sVar2) == '\n')) {
    param_1->cur_col = param_1->cur_col + -1;
    *(short *)&param_1[1]._padding_ = sVar2 + -1;
  }
  if (((0 < param_1->cur_col) && (sVar3 = (short)param_1[1]._padding_, 0 < sVar3)) &&
     (*(char *)(param_1[1]._padding_ + -1 + (int)sVar3) == '\r')) {
    param_1->cur_col = param_1->cur_col + -1;
    *(short *)&param_1[1]._padding_ = sVar3 + -1;
  }
  if (param_1->cur_line < param_1->top_line) {
    do {
      TTextPanel::scroll(param_1,'\x03',1,1);
    } while (param_1->cur_line < param_1->top_line);
  }
  if (param_1->bot_line < param_1->cur_line) {
    do {
      TTextPanel::scroll(param_1,'\x02',1,1);
    } while (param_1->bot_line < param_1->cur_line);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00478142
// Address: 00478142
undefined4 __fastcall FUN_00478142(TTextPanel *param_1)
{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = TTextPanel::currentLine(param_1);
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    for (; *pcVar1 != '\0'; pcVar1 = (char *)__mbsinc(pcVar1)) {
      iVar2 = __ismbcspace(*pcVar1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00478191
// Address: 00478191
undefined4 * __thiscall FUN_00478191(TTextPanel *param_1,undefined4 *param_2,uint param_3)
{
  char cVar1;
  char *pcVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  uint auStack_100 [64];
  
  puVar3 = auStack_100;
  for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  pcVar2 = TTextPanel::currentLine(param_1);
  uVar6 = 0xffffffff;
  do {
    pcVar8 = pcVar2;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar8 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar8;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  puVar3 = (uint *)(pcVar8 + -uVar6);
  puVar9 = auStack_100;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar9 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar9 = puVar9 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)puVar9 = (char)*puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
    puVar9 = (uint *)((int)puVar9 + 1);
  }
  puVar4 = param_2;
  for (uVar6 = param_3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)puVar4 = 0;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  puVar3 = auStack_100;
  iVar5 = __ismbcspace(auStack_100[0] & 0xff);
  while (iVar5 != 0) {
    puVar3 = (uint *)__mbsinc(puVar3);
    iVar5 = __ismbcspace((char)*puVar3);
  }
  cVar1 = (char)*puVar3;
  puVar4 = param_2;
  while (cVar1 != '\0') {
    __mbsncpy(puVar4,puVar3,1);
    puVar4 = (undefined4 *)__mbsinc(puVar4);
    puVar3 = (uint *)__mbsinc(puVar3);
    cVar1 = (char)*puVar3;
  }
  do {
    *(undefined1 *)puVar4 = 0;
    if (puVar4 == param_2) {
      return param_2;
    }
    puVar4 = (undefined4 *)__mbsdec(param_2,puVar4);
    iVar5 = __ismbcspace(*(undefined1 *)puVar4);
  } while (iVar5 != 0);
  return param_2;
}

// --------------------------------------------------

// Function: FUN_00478298
// Address: 00478298
TTextPanel * __fastcall FUN_00478298(TTextPanel *param_1)
{
  TTextPanel::TTextPanel(param_1);
  param_1->_padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 1;
  param_1->_padding_ = (int)&TListPanel::_vftable_;
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 4;
  param_1->bevel_type = 1;
  param_1[1]._padding_ = 0x32;
  param_1->_padding_ = 1;
  param_1->spacer_size = 1;
  param_1->border_size = 1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00478306
// Address: 00478306
TListPanel * __thiscall FUN_00478306(TListPanel *param_1,byte param_2)
{
  TListPanel::~TListPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047832e
// Address: 0047832e
void __fastcall FUN_0047832e(TTextPanel *param_1)
{
  param_1->_padding_ = (int)&TListPanel::_vftable_;
  TTextPanel::~TTextPanel(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047833b
// Address: 0047833b
void __thiscall FUN_0047833b(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x188) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0047834d
// Address: 0047834d
void __thiscall
FUN_0047834d(TTextPanel *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)
{
  switch(param_2) {
  default:
    param_1->spacer_size = 1;
    break;
  case 3:
  case 6:
    param_1->spacer_size = 2;
    break;
  case 4:
  case 7:
    param_1->spacer_size = 3;
  }
  TTextPanel::set_bevel_info(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (param_1->border_size == 0) {
    param_1->border_size = 1;
    TTextPanel::calc_draw_info(param_1,1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004783cf
// Address: 004783cf
// [HELPER] s_C__msdev_work_age1_x1_Pnl_lst_cp: "C:\msdev\work\age1_x1\Pnl_lst.cpp"
int __fastcall
FUN_004783cf(TListPanel *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6,int param_7,int param_8,int param_9,int param_10)
{
  char *pcVar1;
  short sVar2;
  char cVar5;
  int extraout_EAX;
  int iVar3;
  int in_EAX;
  ulong uVar4;
  char cVar6;
  char unaff_BH;
  TTextPanel *unaff_ESI;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  if (in_ZF || in_OF != in_SF) {
    switch(param_1) {
    default:
      unaff_ESI->spacer_size = 1;
      break;
    case (TListPanel *)0x3:
    case (TListPanel *)0x6:
      unaff_ESI->spacer_size = 2;
      break;
    case (TListPanel *)0x4:
    case (TListPanel *)0x7:
      unaff_ESI->spacer_size = 3;
    }
    TTextPanel::set_bevel_info
              (unaff_ESI,(int)param_1,param_5,param_6,param_7,param_8,param_9,param_10);
    iVar3 = unaff_ESI->border_size;
    if (iVar3 == 0) {
      unaff_ESI->border_size = 1;
      TTextPanel::calc_draw_info(unaff_ESI,1);
      iVar3 = extraout_EAX;
    }
    return iVar3;
  }
  pcVar1 = (char *)((int)&unaff_ESI[-1].font_wid + 3);
  *pcVar1 = *pcVar1 + unaff_BH;
  pcVar1 = (char *)((int)&unaff_ESI[-1].font_wid + 3);
  cVar5 = (char)((uint)in_EAX >> 8);
  *pcVar1 = *pcVar1 + cVar5;
  cVar6 = (char)((uint)param_2 >> 8);
  *(char *)(param_2 + -0x7d) = *(char *)(param_2 + -0x7d) + cVar6;
  pcVar1 = (char *)((int)&unaff_ESI[-1].font_wid + 3);
  *pcVar1 = *pcVar1 + unaff_BH;
  pcVar1 = (char *)((int)&unaff_ESI[-1].font_wid + 3);
  *pcVar1 = *pcVar1 + cVar5;
  *(char *)(param_2 + -0x7d) = *(char *)(param_2 + -0x7d) + cVar6;
  *(char *)(in_EAX + 0x56909090) = *(char *)(in_EAX + 0x56909090) + (char)param_2;
  TPanel::handle_idle((TPanel *)param_1);
  if (((param_1->mouse_scroll_up != 0) || (param_1->mouse_scroll_down != 0)) &&
     (uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_lst_cp,0x6c),
     param_1->mouse_scroll_interval <= uVar4 - param_1->mouse_scroll_last_time)) {
    param_1->mouse_scroll_last_time = uVar4;
    if (param_1->mouse_scroll_up != 0) {
      sVar2 = (short)param_1->_padding_;
      if ((short)param_1->_padding_ != sVar2) {
        TListPanel::scroll_cur_line(param_1,'\x01',sVar2,1);
      }
      TListPanel::scroll_cur_line(param_1,'\x03',0,1);
      return 0;
    }
    sVar2 = *(short *)((int)&param_1->_padding_ + 2);
    if ((short)param_1->_padding_ != sVar2) {
      TListPanel::scroll_cur_line(param_1,'\x01',sVar2,1);
    }
    TListPanel::scroll_cur_line(param_1,'\x02',0,1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047849d
// Address: 0047849d
undefined4 __thiscall FUN_0047849d(TListPanel *param_1,long param_2,long param_3)
{
  short sVar1;
  int iVar2;
  
  if (param_1->auto_track == 0) {
    return 0;
  }
  iVar2 = (**(code **)(param_1->_padding_ + 0xbc))(param_2,param_3);
  if (iVar2 == 0) {
    return 0;
  }
  sVar1 = TListPanel::item_at(param_1,param_2,param_3);
  if (((short)param_1->_padding_ <= sVar1) && (sVar1 <= *(short *)((int)&param_1->_padding_ + 2))) {
    TListPanel::goto_item(param_1,param_2,param_3);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00478504
// Address: 00478504
undefined4 __thiscall FUN_00478504(TListPanel *param_1,long param_2,long param_3)
{
  TPanel::capture_mouse((TPanel *)param_1);
  TListPanel::goto_item(param_1,param_2,param_3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00478532
// Address: 00478532
// [HELPER] s_C__msdev_work_age1_x1_Pnl_lst_cp: "C:\msdev\work\age1_x1\Pnl_lst.cpp"
undefined4 __thiscall FUN_00478532(TListPanel *param_1,long param_2,int param_3)
{
  ulong uVar1;
  int iVar2;
  
  iVar2 = param_1->_padding_;
  if (iVar2 <= param_3) {
    if (param_3 < param_1->_padding_ + iVar2) {
      param_1->mouse_scroll_up = 0;
      param_1->mouse_scroll_down = 0;
      TListPanel::goto_item(param_1,param_2,param_3);
      return 1;
    }
    if (iVar2 <= param_3) {
      if (param_3 <= param_1->_padding_ + -1 + iVar2) {
        param_1->mouse_scroll_up = 0;
        param_1->mouse_scroll_down = 0;
        return 1;
      }
      param_1->mouse_scroll_up = 0;
      if (param_1->mouse_scroll_down != 0) {
        return 1;
      }
      param_1->mouse_scroll_down = 1;
      iVar2 = 0xba;
      goto LAB_004785ce;
    }
  }
  param_1->mouse_scroll_down = 0;
  if (param_1->mouse_scroll_up != 0) {
    return 1;
  }
  param_1->mouse_scroll_up = 1;
  iVar2 = 0xb1;
LAB_004785ce:
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_lst_cp,iVar2);
  param_1->mouse_scroll_last_time = uVar1 - param_1->mouse_scroll_interval;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00478609
// Address: 00478609
undefined4 __fastcall FUN_00478609(TPanel *param_1)
{
  short sVar1;
  TPanel *pTVar2;
  
  TPanel::release_mouse(param_1);
  pTVar2 = param_1->parent_panel;
  param_1[1].top_border = 0;
  param_1[1].right_border = 0;
  if (((pTVar2 != (TPanel *)0x0) && (sVar1 = (short)param_1[1].pnl_x, -1 < sVar1)) &&
     (sVar1 < *(short *)&param_1[1].previousPanelValue)) {
    (**(code **)(pTVar2->_padding_ + 0xb4))(param_1,2,(int)sVar1,0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047865e
// Address: 0047865e
undefined4 __thiscall FUN_0047865e(TListPanel *param_1,long param_2,long param_3)
{
  short sVar1;
  
  TListPanel::goto_item(param_1,param_2,param_3);
  if ((((int *)param_1->_padding_ != (int *)0x0) && (sVar1 = (short)param_1->_padding_, -1 < sVar1))
     && (sVar1 < (short)param_1->_padding_)) {
    (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,3,(int)sVar1,0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004786ab
// Address: 004786ab
int __thiscall FUN_004786ab(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x184);
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x140);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x140) + -1 + iVar1 * 2;
  }
  return (((param_3 - *(int *)(param_1 + 0x180)) - *(int *)(param_1 + 0x10)) - iVar1) / iVar2 +
         CONCAT22((short)((uint)param_1 >> 0x10),*(undefined2 *)(param_1 + 0xfc));
}

// --------------------------------------------------

// Function: FUN_004786f2
// Address: 004786f2
void __thiscall FUN_004786f2(TListPanel *param_1,long param_2,long param_3)
{
  short sVar1;
  int iVar2;
  
  iVar2 = 1;
  sVar1 = TListPanel::item_at(param_1,param_2,param_3);
  TListPanel::scroll_cur_line(param_1,'\x01',sVar1,iVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_00478724
// Address: 00478724
undefined4 __thiscall FUN_00478724(TListPanel *param_1,undefined4 param_2)
{
  short sVar1;
  
  switch(param_2) {
  case 0xd:
    break;
  default:
    return 0;
  case 0x21:
    TListPanel::scroll_cur_line(param_1,'\x05',0,1);
    return 1;
  case 0x22:
    TListPanel::scroll_cur_line(param_1,'\x04',0,1);
    return 1;
  case 0x23:
    TListPanel::scroll_cur_line(param_1,'\a',0,1);
    return 1;
  case 0x24:
    TListPanel::scroll_cur_line(param_1,'\x06',0,1);
    return 1;
  case 0x26:
    TListPanel::scroll_cur_line(param_1,'\x03',0,1);
    return 1;
  case 0x28:
    TListPanel::scroll_cur_line(param_1,'\x02',0,1);
    return 1;
  }
  if ((((int *)param_1->_padding_ != (int *)0x0) && (sVar1 = (short)param_1->_padding_, -1 < sVar1))
     && (sVar1 < (short)param_1->_padding_)) {
    (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,3,(int)sVar1,0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00478807
// Address: 00478807
undefined4 __fastcall FUN_00478807(TListPanel *param_1,int *param_2)
{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  char *pcVar5;
  int iVar6;
  undefined2 in_ES;
  
  *(undefined2 *)(unaff_EDI + -0x7887ffb9) = in_ES;
  pcVar5 = (char *)(unaff_EDI + -0x785fffb8 + in_EAX * 4);
  *pcVar5 = *pcVar5 + (char)((uint)param_2 >> 8);
  pcVar5 = (char *)(unaff_EDI + 0x49 + in_EAX * 4);
  *pcVar5 = *pcVar5 + (char)((uint)in_EAX >> 8);
  *(char *)(in_EAX + -0x79) = *(char *)(in_EAX + -0x79) + (char)param_2;
  pcVar5 = (char *)(unaff_EDI + 3);
  cVar1 = (char)in_EAX;
  *(char *)&param_1->_padding_ = (char)param_1->_padding_ + cVar1;
  *pcVar5 = cVar1;
  *pcVar5 = *pcVar5 + cVar1;
  *param_2 = *param_2 + in_EAX;
  iVar2 = toupper();
  iVar6 = 0;
  for (puVar4 = (undefined4 *)param_1->_padding_; puVar4 != (undefined4 *)0x0;
      puVar4 = (undefined4 *)puVar4[3]) {
    if (((short)param_1->_padding_ < iVar6) &&
       (iVar3 = toupper((int)*(char *)*puVar4,pcVar5), iVar3 == iVar2)) goto LAB_004788da;
    iVar6 = iVar6 + 1;
  }
  if (0 < (short)param_1->_padding_) {
    puVar4 = (undefined4 *)param_1->_padding_;
    iVar6 = 0;
    if (puVar4 != (undefined4 *)0x0) {
      while (iVar3 = toupper((int)*(char *)*puVar4,pcVar5), iVar3 != iVar2) {
        iVar6 = iVar6 + 1;
        if ((short)param_1->_padding_ <= iVar6) {
          return 0;
        }
        puVar4 = (undefined4 *)puVar4[3];
        if (puVar4 == (undefined4 *)0x0) {
          return 0;
        }
      }
LAB_004788da:
      TListPanel::scroll_cur_line(param_1,'\x01',(short)iVar6,1);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004788fb
// Address: 004788fb
void __thiscall
FUN_004788fb(TTextPanel *param_1,TPanel *param_2,long param_3,ulong param_4,ulong param_5)
{
  TTextPanel::action(param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0047891c
// Address: 0047891c
void __thiscall FUN_0047891c(TTextPanel *param_1,undefined1 param_2,short param_3,int param_4)
{
  short sVar1;
  short sVar2;
  short sVar3;
  uchar uVar4;
  
  sVar1 = param_1->cur_line;
  switch(param_2) {
  case 1:
    param_1->cur_line = param_3;
    if (param_3 < 0) {
      param_1->cur_line = 0;
    }
    else if (param_1->num_lines + -1 < (int)param_3) {
      param_1->cur_line = param_1->num_lines + -1;
    }
    sVar2 = param_1->cur_line;
    if (sVar2 < param_1->top_line) {
      TTextPanel::scroll(param_1,'\x01',sVar2,param_4);
    }
    else if (param_1->bot_line < sVar2) {
      TTextPanel::scroll(param_1,'\0',sVar2 - param_1->bot_line,param_4);
    }
    goto switchD_00478941_default;
  case 2:
    if ((sVar1 < param_1->top_line) || (sVar3 = param_1->bot_line, sVar3 < sVar1)) {
      sVar3 = param_1->bot_line;
      param_1->cur_line = sVar3;
    }
    sVar2 = param_1->cur_line;
    if (sVar3 <= sVar2) {
      if ((int)sVar2 < param_1->num_lines + -1) {
        param_1->cur_line = sVar2 + 1;
        TTextPanel::scroll(param_1,'\x02',0,param_4);
      }
      goto switchD_00478941_default;
    }
    sVar2 = sVar2 + 1;
    break;
  case 3:
    sVar3 = param_1->top_line;
    if ((sVar1 < sVar3) || (param_1->bot_line < sVar1)) {
      param_1->cur_line = sVar3;
    }
    sVar2 = param_1->cur_line;
    if (sVar2 <= sVar3) {
      if (0 < sVar2) {
        param_1->cur_line = sVar2 + -1;
        TTextPanel::scroll(param_1,'\x03',0,param_4);
      }
      goto switchD_00478941_default;
    }
    sVar2 = sVar2 + -1;
    break;
  case 4:
    if ((sVar1 < param_1->top_line) || (sVar2 = param_1->bot_line, sVar2 < sVar1)) {
      sVar2 = param_1->bot_line;
      param_1->cur_line = sVar2;
    }
    if (param_1->cur_line != sVar2) goto LAB_00478b14;
    uVar4 = '\x04';
    goto LAB_00478b26;
  case 5:
    sVar2 = param_1->top_line;
    if ((sVar1 < sVar2) || (param_1->bot_line < sVar1)) {
      param_1->cur_line = sVar2;
    }
    if (param_1->cur_line == sVar2) {
      TTextPanel::scroll(param_1,'\x05',0,param_4);
      param_1->cur_line = param_1->top_line;
      goto switchD_00478941_default;
    }
    goto LAB_00478b14;
  case 6:
    TTextPanel::scroll(param_1,'\x06',0,param_4);
    sVar2 = param_1->top_line;
LAB_00478b14:
    param_1->cur_line = sVar2;
    goto switchD_00478941_default;
  case 7:
    uVar4 = '\a';
LAB_00478b26:
    TTextPanel::scroll(param_1,uVar4,0,param_4);
    sVar2 = param_1->bot_line;
    break;
  default:
    goto switchD_00478941_default;
  }
  param_1->cur_line = sVar2;
switchD_00478941_default:
  (**(code **)(param_1->_padding_ + 0x20))(1);
  sVar2 = param_1->cur_line;
  if ((((sVar2 != sVar1) && ((int *)param_1->_padding_ != (int *)0x0)) && (-1 < sVar2)) &&
     (sVar2 < param_1->num_lines)) {
    (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,1,(int)sVar2,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00478ccf
// Address: 00478ccf
// [HELPER] s_pnl_lst__draw_highlight_bar: "pnl_lst::draw_highlight_bar"
void __fastcall FUN_00478ccf(TTextPanel *param_1)
{
  int iVar1;
  int iVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uchar uVar6;
  uchar uVar7;
  uchar uVar8;
  void *pvVar9;
  uchar *puVar10;
  int iVar11;
  int iVar12;
  tagRECT tStack_10;
  
  if (param_1[1]._padding_ == 0) {
    return;
  }
  if (param_1->cur_line < param_1->top_line) {
    return;
  }
  if (param_1->bot_line < param_1->cur_line) {
    return;
  }
  pvVar9 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_pnl_lst__draw_highlight_bar);
  if (pvVar9 == (void *)0x0) goto switchD_00478d96_default;
  TTextPanel::calc_line_pos
            (param_1,pvVar9,param_1->cur_line - param_1->top_line,param_1->cur_line,&tStack_10,
             (long *)0x0);
  TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_pnl_lst__draw_highlight_bar);
  puVar10 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_pnl_lst__draw_highlight_bar,1);
  if (puVar10 == (uchar *)0x0) goto switchD_00478d96_default;
  iVar1 = param_1->border_size + param_1->_padding_;
  iVar12 = tStack_10.top - param_1->spacer_size;
  iVar11 = ((param_1->_padding_ + param_1->_padding_) - param_1->border_size) + -1;
  iVar2 = tStack_10.bottom + param_1->spacer_size;
  switch(param_1->bevel_type) {
  case 0:
  case 1:
    TDrawArea::DrawRect((TDrawArea *)param_1->_padding_,iVar1,iVar12,iVar11,iVar2,0xff);
    break;
  case 2:
    TDrawArea::DrawBevel
              ((TDrawArea *)param_1->_padding_,iVar1,iVar12,iVar11,iVar2,param_1->bevel_color1,
               param_1->bevel_color6);
    break;
  case 3:
    TDrawArea::DrawBevel2
              ((TDrawArea *)param_1->_padding_,iVar1,iVar12,iVar11,iVar2,param_1->bevel_color1,
               param_1->bevel_color2,param_1->bevel_color5,param_1->bevel_color6);
    break;
  case 4:
    uVar3 = param_1->bevel_color6;
    uVar4 = param_1->bevel_color5;
    uVar5 = param_1->bevel_color4;
    uVar6 = param_1->bevel_color3;
    uVar7 = param_1->bevel_color2;
    uVar8 = param_1->bevel_color1;
    goto LAB_00478e99;
  case 5:
    TDrawArea::DrawBevel
              ((TDrawArea *)param_1->_padding_,iVar1,iVar12,iVar11,iVar2,param_1->bevel_color6,
               param_1->bevel_color1);
    break;
  case 6:
    TDrawArea::DrawBevel2
              ((TDrawArea *)param_1->_padding_,iVar1,iVar12,iVar11,iVar2,param_1->bevel_color6,
               param_1->bevel_color5,param_1->bevel_color2,param_1->bevel_color1);
    break;
  case 7:
    uVar3 = param_1->bevel_color1;
    uVar4 = param_1->bevel_color2;
    uVar5 = param_1->bevel_color3;
    uVar6 = param_1->bevel_color4;
    uVar7 = param_1->bevel_color5;
    uVar8 = param_1->bevel_color6;
LAB_00478e99:
    TDrawArea::DrawBevel3
              ((TDrawArea *)param_1->_padding_,iVar1,iVar12,iVar11,iVar2,uVar8,uVar7,uVar6,uVar5,
               uVar4,uVar3);
  }
switchD_00478d96_default:
  TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_pnl_lst__draw_highlight_bar);
  return;
}

// --------------------------------------------------

// Function: FUN_00478ebb
// Address: 00478ebb
void __fastcall
FUN_00478ebb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  char cVar1;
  char cVar2;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  cVar2 = (char)((uint)param_2 >> 8);
  cVar1 = *(char *)(unaff_ESI + -0x71b9ffb9);
  *(char *)(unaff_EDI + -0x72) = *(char *)(unaff_EDI + -0x72) + cVar2;
  *(char *)(unaff_EBX + -0x2dffb873) = *(char *)(unaff_EBX + -0x2dffb873) + cVar2;
  *(int *)(unaff_EBP + -0x6f6fffb9) = *(int *)(unaff_EBP + -0x6f6fffb9) + -1;
  *(undefined4 *)(CONCAT31((int3)((uint)param_1 >> 8),(char)param_1 - cVar1) + 0x19c) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_00478eed
// Address: 00478eed
void __thiscall FUN_00478eed(TPanel *param_1,int param_2)
{
  short sVar1;
  
  TPanel::set_focus(param_1,param_2);
  if ((((param_1->have_focus != 0) && (param_1->parent_panel != (TPanel *)0x0)) &&
      (sVar1 = (short)param_1[1].pnl_x, -1 < sVar1)) &&
     (sVar1 < *(short *)&param_1[1].previousPanelValue)) {
    (**(code **)(param_1->parent_panel->_padding_ + 0xb4))(param_1,1,(int)sVar1,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00478f36
// Address: 00478f36
TPanel * __thiscall FUN_00478f36(TPanel *param_1,long param_2,long param_3,long param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e4c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel(param_1);
  param_1[3].clip_rect.top = param_2;
  param_1[3].clip_rect.bottom = param_4;
  param_1[3].clip_rgn = (void *)0xffffffff;
  param_1[3].render_rect.left = -1;
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  param_1[3].panelNameValue = (char *)0x0;
  param_1[3].render_area = (TDrawArea *)0x0;
  param_1[3].clip_rect.left = 8000;
  param_1[3].clip_rect.right = param_3;
  *(undefined1 *)&param_1[3].position_mode = PositionFixed;
  *(byte *)((int)&param_1[3].position_mode + 1) = 0;
  param_1[3].left_panel = (TPanel *)0x2;
  param_1[3].top_panel = (TPanel *)0x0;
  param_1[3].right_panel = (TPanel *)0x0;
  param_1[3].bottom_panel = (TPanel *)0x0;
  param_1[3].node = (PanelNode *)0x0;
  param_1[3].render_rect.top = 0;
  param_1[3].render_rect.right = 0;
  param_1[3].render_rect.bottom = 0;
  param_1[3].left_border = 0;
  param_1[3].top_border = 0;
  param_1->_padding_ = (int)&TMessagePanel::_vftable_;
  *(undefined1 *)&param_1[1].previousPanelValue = 0;
  param_1->handle_mouse_input = 0;
  TPanel::set_active(param_1,0);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047902b
// Address: 0047902b
TMessagePanel * __thiscall FUN_0047902b(TMessagePanel *param_1,byte param_2)
{
  TMessagePanel::~TMessagePanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047904e
// Address: 0047904e
void __fastcall FUN_0047904e(TPanel *param_1)
{
  TDrawArea *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e4e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TMessagePanel::_vftable_;
  uStack_4 = 0;
  if (param_1[3].bottom_panel != (TPanel *)0x0) {
    DeleteObject(param_1[3].bottom_panel);
    param_1[3].bottom_panel = (TPanel *)0x0;
  }
  this = (TDrawArea *)param_1[3].node;
  if (this != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this);
    operator_delete(this);
    param_1[3].node = (PanelNode *)0x0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004790db
// Address: 004790db
// [HELPER] s_message_panel: "message panel"
void __thiscall FUN_004790db(TPanel *param_1,int param_2,long param_3,long param_4,long param_5)
{
  long lVar1;
  long lVar2;
  TDrawArea *pTVar3;
  void *pvVar4;
  int iVar5;
  TDrawArea *pTVar6;
  TPanel *pTVar7;
  TPanel *pTVar8;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e50b;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::set_rect(param_1,param_2,param_3,param_4,param_5);
  if ((((int)param_1[3].clip_rgn < param_1->pnl_wid) ||
      (param_1[3].render_rect.left < param_1->pnl_hgt)) ||
     (param_1->render_area->Width <= param_2 + (int)param_1[3].clip_rgn)) {
    if (param_1[3].bottom_panel != (TPanel *)0x0) {
      DeleteObject(param_1[3].bottom_panel);
      param_1[3].bottom_panel = (TPanel *)0x0;
    }
    pTVar6 = (TDrawArea *)param_1[3].node;
    if (pTVar6 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar6);
      operator_delete(pTVar6);
      param_1[3].node = (PanelNode *)0x0;
    }
    pTVar6 = (TDrawArea *)operator_new(0x100);
    uStack_4 = 0;
    if (pTVar6 == (TDrawArea *)0x0) {
      pTVar6 = (TDrawArea *)0x0;
    }
    else {
      pTVar6 = (TDrawArea *)TDrawArea::TDrawArea(pTVar6,s_message_panel,0);
    }
    lVar1 = param_1->pnl_hgt;
    lVar2 = param_1->pnl_wid;
    pTVar3 = param_1->render_area;
    param_1[3].node = (PanelNode *)pTVar6;
    uStack_4 = 0xffffffff;
    TDrawArea::Init(pTVar6,pTVar3->DrawSystem,lVar2,lVar1,0,0);
    pvVar4 = (void *)param_1->pnl_wid;
    iVar5 = param_1->pnl_hgt;
    param_1[3].clip_rgn = pvVar4;
    param_1[3].render_rect.left = iVar5;
    pTVar7 = (TPanel *)((int)pvVar4 + -1);
    pTVar8 = (TPanel *)(iVar5 + -1);
    param_1[3].first_child_node = (PanelNode *)0x0;
    param_1[3].last_child_node = (PanelNode *)0x0;
    param_1[3].tab_prev_panel = pTVar7;
    param_1[3].tab_next_panel = pTVar8;
    pTVar7 = (TPanel *)CreateRectRgn(0,0,pTVar7,pTVar8);
    param_1[3].bottom_panel = pTVar7;
  }
  if (param_1[3].node == (PanelNode *)0x0) {
    param_1[3].clip_rgn = (void *)0xffffffff;
    param_1[3].render_rect.left = -1;
  }
  else {
    param_1[3].mouse_captured = (int)param_1[3].first_child_node;
    param_1[3].active = (int)param_1[3].last_child_node;
    param_1[3].visible = (int)param_1[3].tab_prev_panel;
    param_1[3].tab_stop = (int)param_1[3].tab_next_panel;
  }
  param_1->need_restore = '\x01';
  (**(code **)(param_1->_padding_ + 0x20))(1);
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}

// --------------------------------------------------

// Function: FUN_00479265
// Address: 00479265
void __thiscall FUN_00479265(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 800) = param_2;
  *(undefined4 *)(param_1 + 0x324) = param_3;
  *(undefined4 *)(param_1 + 0x328) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_00479291
// Address: 00479291
// [HELPER] s_C__msdev_work_age1_x1_Pnl_msg_cp: "C:\msdev\work\age1_x1\Pnl_msg.cpp"
void __thiscall
FUN_00479291(TMessagePanel *param_1,MessageType param_2,undefined4 param_3,uchar param_4,
            uchar param_5,void *param_6,long param_7,long param_8)
{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  
  if (((param_1->showing_message != 0) && (param_1->message_type == param_2)) &&
     (iVar1 = strncmp(param_3,param_1->text,0x1ff), iVar1 == 0)) {
    if (param_6 == (void *)0x0) {
      return;
    }
    if (param_6 == param_1->font) {
      return;
    }
  }
  if (param_6 != (void *)0x0) {
    param_1->font = param_6;
    param_1->font_wid = param_7;
    param_1->font_hgt = param_8;
  }
  param_1->message_type = param_2;
  pcVar3 = param_1->text;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3 = pcVar3 + 4;
  }
  strncpy(param_1->text,param_3,0x1ff);
  param_1->_padding_ = param_1->_padding_ + 1;
  param_1->showing_message = 1;
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_msg_cp,0x9e);
  param_1->start_time = uVar2;
  param_1->font_color = param_4;
  param_1->index_color = 1;
  param_1->back_color = param_5;
  if (param_1->ImageBuffer != (TDrawArea *)0x0) {
    TMessagePanel::render_to_image_buffer(param_1);
  }
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0x14))(1);
  (**(code **)(iVar1 + 0x20))(1);
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004793b2
// Address: 004793b2
// [HELPER] s_C__msdev_work_age1_x1_Pnl_msg_cp: "C:\msdev\work\age1_x1\Pnl_msg.cpp"
void __thiscall
FUN_004793b2(TMessagePanel *param_1,MessageType param_2,undefined4 param_3,ulong param_4,
            ulong param_5,void *param_6,long param_7,long param_8,TShape *param_9,int param_10,
            TShape *param_11,int param_12)
{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  
  if ((((((param_1->showing_message != 0) && (param_1->message_type == param_2)) &&
        (iVar1 = strncmp(param_3,param_1->text,0x1ff), iVar1 == 0)) &&
       ((param_6 == (void *)0x0 || (param_6 == param_1->font)))) &&
      ((param_1->Icon1 == param_9 &&
       ((param_1->Icon2 == param_11 && (param_1->IconFrame1 == param_10)))))) &&
     (param_1->IconFrame2 == param_12)) {
    return;
  }
  if (param_6 != (void *)0x0) {
    param_1->font = param_6;
    param_1->font_wid = param_7;
    param_1->font_hgt = param_8;
  }
  param_1->IconFrame1 = param_10;
  param_1->message_type = param_2;
  param_1->Icon1 = param_9;
  param_1->IconFrame2 = param_12;
  param_1->Icon2 = param_11;
  pcVar3 = param_1->text;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3 = pcVar3 + 4;
  }
  strncpy(param_1->text,param_3,0x1ff);
  param_1->showing_message = 1;
  param_1->_padding_ = param_1->_padding_ + 1;
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_msg_cp,0xd3);
  param_1->start_time = uVar2;
  param_1->font_color1 = param_4;
  param_1->index_color = 0;
  param_1->font_color2 = param_5;
  if (param_1->ImageBuffer != (TDrawArea *)0x0) {
    TMessagePanel::render_to_image_buffer(param_1);
  }
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0x14))(1);
  (**(code **)(iVar1 + 0x20))(1);
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00479532
// Address: 00479532
void __fastcall FUN_00479532(int *param_1)
{
  int iVar1;
  
  if (param_1[0xbe] != 0) {
    iVar1 = *param_1;
    param_1[0xbe] = 0;
    (**(code **)(iVar1 + 0x14))(0);
    (**(code **)(iVar1 + 0x20))(1);
    if ((int *)param_1[0x10] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x10] + 0x20))(1);
    }
  }
  param_1[0xdb] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00479581
// Address: 00479581
// [HELPER] s_pnl_msg__draw: "pnl_msg::draw"
void __fastcall FUN_00479581(TMessagePanel *param_1)
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  char *pcVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uStack_3c;
  int iStack_28;
  undefined1 uStack_24;
  undefined1 uStack_23;
  ushort uStack_22;
  int aiStack_1c [2];
  undefined1 auStack_14 [20];
  
  if ((((param_1->_padding_ == 0) || (param_1->_padding_ == 0)) || (param_1->_padding_ == 0)) ||
     (param_1->showing_message == 0)) {
    param_1->_padding_ = 0;
    return;
  }
  iVar11 = param_1->_padding_;
  uStack_24 = (undefined1)iVar11;
  uStack_23 = (undefined1)((uint)iVar11 >> 8);
  uStack_22 = (ushort)((uint)iVar11 >> 0x10);
  (**(code **)(iVar11 + 0x28))(0);
  if ((param_1->ImageTextActive != 0) && (param_1->ImageBuffer != (TDrawArea *)0x0)) {
    if (*(char *)((int)&param_1->_padding_ + 3) != '\0') {
      TMessagePanel::render_to_image_buffer(param_1);
      *(undefined1 *)((int)&param_1->_padding_ + 3) = 0;
      (**(code **)(iVar11 + 0x2c))();
      return;
    }
    TDrawArea::SetTrans(param_1->ImageBuffer,1,'\x01');
    TDrawArea::Copy(param_1->ImageBuffer,(TDrawArea *)param_1->_padding_,
                    (param_1->UsedScreenRect).left,(param_1->UsedScreenRect).top,
                    &param_1->UsedImageRect,1);
    TDrawArea::SetTrans(param_1->ImageBuffer,0,'\x01');
    (**(code **)(iVar11 + 0x2c))();
    return;
  }
  pcVar1 = param_1->text;
  if (param_1->text[0] != '\0') {
    pvVar5 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_pnl_msg__draw);
    if (pvVar5 != (void *)0x0) {
      SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->_padding_);
      uVar6 = SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),param_1->font);
      if (param_1->index_color == 0) {
        uStack_3c = param_1->font_color1;
        uVar9 = param_1->font_color2;
      }
      else {
        GetPaletteEntries(rge_base_game->draw_system->Pal,param_1->font_color,1,&uStack_24);
        uStack_3c = ((uStack_22 & 0xff) << 8 | CONCAT21(uStack_22,uStack_23) & 0xff) << 8 |
                    CONCAT11(uStack_23,uStack_24) & 0xff;
        GetPaletteEntries(rge_base_game->draw_system->Pal,param_1->back_color,1,&uStack_24);
        uVar9 = ((uStack_22 & 0xff) << 8 | CONCAT21(uStack_22,uStack_23) & 0xff) << 8 |
                CONCAT11(uStack_23,uStack_24) & 0xff;
      }
      if (param_1->message_type == DebugMessage) {
        SetBkColor(*(undefined4 *)(param_1->_padding_ + 0x38),0);
        uVar13 = 2;
        uVar12 = *(undefined4 *)(param_1->_padding_ + 0x38);
      }
      else {
        uVar13 = 1;
        uVar12 = *(undefined4 *)(param_1->_padding_ + 0x38);
      }
      SetBkMode(uVar12,uVar13);
      iVar11 = param_1->_padding_;
      uVar8 = 0xffffffff;
      iVar3 = param_1->_padding_;
      iVar7 = param_1->_padding_ + -2;
      iVar4 = param_1->_padding_;
      pcVar10 = pcVar1;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar2 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar2 != '\0');
      GetTextExtentPoint32A(*(undefined4 *)(param_1->_padding_ + 0x38),pcVar1,~uVar8 - 1,aiStack_1c)
      ;
      if (param_1->message_type == BadMessage) {
        uVar8 = 0x21;
      }
      else if (param_1->message_type == RightInfoMessage) {
        uVar8 = 0x22;
      }
      else {
        uVar8 = 0xffffffff;
        pcVar10 = pcVar1;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          cVar2 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar2 != '\0');
        GetTextExtentPoint32A
                  (*(undefined4 *)(param_1->_padding_ + 0x38),pcVar1,~uVar8 - 1,aiStack_1c);
        if ((param_1->word_wrap == 0) || (uVar8 = 0x10, aiStack_1c[0] <= iVar7)) {
          uVar8 = 0x20;
        }
        if (param_1->horz_just == CenterJust) {
          uVar8 = uVar8 | 1;
        }
        else if (param_1->horz_just == RightJust) {
          uVar8 = uVar8 | 2;
        }
        if (param_1->vert_just == CenterJust) {
          uVar8 = uVar8 | 4;
        }
        else if (param_1->vert_just == BottomJust) {
          uVar8 = uVar8 | 8;
        }
      }
      SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),uVar9);
      iVar4 = iVar4 + -2 + iVar3 + 1;
      iVar7 = iVar7 + iVar11 + 1;
      SetRect(auStack_14,iVar11,iVar3,iVar7 + -2,iVar4 + -2);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),pcVar1,0xffffffff,auStack_14,uVar8);
      SetRect(auStack_14,iVar11,iVar3 + 2,iVar7 + -2,iVar4);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),pcVar1,0xffffffff,auStack_14,uVar8);
      SetRect(auStack_14,iVar11 + 2,iVar3,iVar7,iVar4 + -2);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),pcVar1,0xffffffff,auStack_14,uVar8);
      SetRect(auStack_14,iVar11 + 2,iVar3 + 2,iVar7,iVar4);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),pcVar1,0xffffffff,auStack_14,uVar8);
      SetTextColor(*(undefined4 *)(param_1->_padding_ + 0x38),uStack_3c);
      SetRect(auStack_14,iVar11 + 1,iVar3 + 1,iVar7 + -1,iVar4 + -1);
      DrawTextA(*(undefined4 *)(param_1->_padding_ + 0x38),pcVar1,0xffffffff,auStack_14,uVar8);
      SelectObject(*(undefined4 *)(param_1->_padding_ + 0x38),uVar6);
      SelectClipRgn(*(undefined4 *)(param_1->_padding_ + 0x38),0);
      TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_pnl_msg__draw);
      iVar11 = iStack_28;
    }
  }
  (**(code **)(iVar11 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_00479a0b
// Address: 00479a0b
void __thiscall FUN_00479a0b(int param_1,undefined4 *param_2)
{
  if ((((*(int *)(param_1 + 0x330) != 0) && (*(int *)(param_1 + 0x20) != 0)) &&
      (*(int *)(param_1 + 0x70) != 0)) &&
     ((*(int *)(param_1 + 0x6c) != 0 && (*(int *)(param_1 + 0x2f8) != 0)))) {
    *param_2 = *(undefined4 *)(param_1 + 0x354);
    param_2[1] = *(undefined4 *)(param_1 + 0x358);
    param_2[2] = *(undefined4 *)(param_1 + 0x35c);
    param_2[3] = *(undefined4 *)(param_1 + 0x360);
    return;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x8c);
  param_2[1] = *(undefined4 *)(param_1 + 0x90);
  param_2[2] = *(undefined4 *)(param_1 + 0x94);
  param_2[3] = *(undefined4 *)(param_1 + 0x98);
  return;
}

// --------------------------------------------------

// Function: FUN_00479a7f
// Address: 00479a7f
// [HELPER] s_C__msdev_work_age1_x1_Pnl_msg_cp: "C:\msdev\work\age1_x1\Pnl_msg.cpp"
undefined4 __fastcall FUN_00479a7f(TMessagePanel *param_1)
{
  MessageType MVar1;
  ulong uVar2;
  
  if (((param_1->_padding_ != 0) && (param_1->showing_message != 0)) &&
     ((MVar1 = param_1->message_type, MVar1 == BadMessage ||
      ((MVar1 == ChatMessage || (MVar1 == ColoredChatMessage)))))) {
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_msg_cp,0x1ba);
    if (param_1->show_message_interval <= (int)(uVar2 - param_1->start_time)) {
      TMessagePanel::remove_message(param_1);
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00479ad8
// Address: 00479ad8
// [HELPER] s_pnl_msg__render_to_image_buffer: "pnl_msg::render_to_image_buffer"
undefined4 __fastcall FUN_00479ad8(int param_1)
{
  tagRECT *ptVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  TShape *pTVar6;
  long lVar7;
  Shape_Info *pSVar8;
  bool bVar9;
  void *pvVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  char *pcVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  int iStack_3c;
  uint uStack_28;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  ushort uStack_1e;
  int iStack_18;
  int iStack_14;
  undefined1 auStack_10 [16];
  
  if (*(TDrawArea **)(param_1 + 0x330) == (TDrawArea *)0x0) {
    return 0;
  }
  ptVar1 = (tagRECT *)(param_1 + 0x334);
  TDrawArea::PtrClear(*(TDrawArea **)(param_1 + 0x330),ptVar1,1);
  if (*(char *)(param_1 + 0xf8) == '\0') {
    SetRect(param_1 + 0x344,0,0,1,1);
    SetRect(param_1 + 0x354,*(int *)(param_1 + 0x8c),*(int *)(param_1 + 0x90),
            *(int *)(param_1 + 0x8c) + 1,*(int *)(param_1 + 0x90) + 1);
    *(undefined4 *)(param_1 + 0x36c) = 1;
    return 1;
  }
  pvVar10 = TDrawArea::GetDc(*(TDrawArea **)(param_1 + 0x330),s_pnl_msg__render_to_image_buffer);
  if (pvVar10 == (void *)0x0) {
    return 0;
  }
  TDrawArea::SetClipRect(*(TDrawArea **)(param_1 + 0x330),ptVar1);
  SelectClipRgn(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),*(undefined4 *)(param_1 + 0x32c));
  uVar11 = SelectObject(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),
                        *(undefined4 *)(param_1 + 0x304));
  if (*(int *)(param_1 + 0x314) == 0) {
    uStack_28 = *(uint *)(param_1 + 0x318);
    uVar12 = *(uint *)(param_1 + 0x31c);
  }
  else {
    GetPaletteEntries(rge_base_game->draw_system->Pal,*(undefined1 *)(param_1 + 0x310),1,&uStack_20)
    ;
    uStack_28 = ((uStack_1e & 0xff) << 8 | CONCAT21(uStack_1e,uStack_1f) & 0xff) << 8 |
                CONCAT11(uStack_1f,uStack_20) & 0xff;
    GetPaletteEntries(rge_base_game->draw_system->Pal,*(undefined1 *)(param_1 + 0x311),1,&uStack_20)
    ;
    uVar12 = ((uStack_1e & 0xff) << 8 | CONCAT21(uStack_1e,uStack_1f) & 0xff) << 8 |
             CONCAT11(uStack_1f,uStack_20) & 0xff;
  }
  if (*(int *)(param_1 + 0xf4) == 2) {
    SetBkColor(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),0);
    uVar22 = 2;
    uVar21 = *(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38);
  }
  else {
    uVar22 = 1;
    uVar21 = *(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38);
  }
  SetBkMode(uVar21,uVar22);
  iVar17 = *(int *)(param_1 + 0x14);
  iVar3 = ptVar1->left;
  iVar4 = *(int *)(param_1 + 0x338);
  iVar13 = iVar17 + -2;
  iVar5 = *(int *)(param_1 + 0x18);
  iVar19 = iVar3 + 1;
  uVar16 = 0xffffffff;
  iVar18 = iVar4 + 1;
  pcVar20 = (char *)(param_1 + 0xf8);
  do {
    if (uVar16 == 0) break;
    uVar16 = uVar16 - 1;
    cVar2 = *pcVar20;
    pcVar20 = pcVar20 + 1;
  } while (cVar2 != '\0');
  iVar14 = GetTextExtentPoint32A
                     (*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),param_1 + 0xf8,~uVar16 - 1,
                      &iStack_18);
  if (iVar14 == 0) {
    SetRect(auStack_10,iVar3,iVar4,iVar17 + -4 + iVar19,iVar5 + -4 + iVar18);
    SetRect(param_1 + 0x344,0,0,1,1);
    *(undefined4 *)(param_1 + 0x36c) = 0;
  }
  else {
    iStack_3c = iStack_14 + 2;
    iVar14 = 0;
    iVar17 = iStack_18 + 2;
    if (*(int *)(param_1 + 0xf4) == 1) {
      uVar16 = 0x21;
      iVar15 = (*(int *)(param_1 + 0x14) - iVar17 >> 1) + -1;
    }
    else if (*(int *)(param_1 + 0xf4) == 5) {
      uVar16 = 0x22;
      iVar15 = (*(int *)(param_1 + 0x14) - iVar17) + -1;
      iVar14 = 0;
    }
    else {
      if ((*(int *)(param_1 + 0x328) == 0) || (iStack_18 <= iVar13)) {
        iVar17 = iStack_18 + 1;
        iStack_3c = iStack_14 + 1;
        uVar16 = 0x20;
        bVar9 = true;
      }
      else {
        iStack_3c = *(int *)(param_1 + 0x18);
        iVar17 = *(int *)(param_1 + 0x14);
        uVar16 = 0x10;
        bVar9 = false;
      }
      iVar14 = 0;
      iVar15 = 0;
      if (*(int *)(param_1 + 800) == 4) {
        uVar16 = uVar16 | 1;
        if (bVar9) {
          iVar15 = (*(int *)(param_1 + 0x14) - iVar17 >> 1) + -1;
        }
      }
      else if (*(int *)(param_1 + 800) == 3) {
        uVar16 = uVar16 | 2;
        if (bVar9) {
          iVar15 = (*(int *)(param_1 + 0x14) - iVar17) + -1;
        }
      }
      else if (bVar9) {
        iVar15 = 0;
      }
      if (*(int *)(param_1 + 0x324) == 4) {
        uVar16 = uVar16 | 4;
        if (bVar9) {
          iVar14 = (*(int *)(param_1 + 0x18) - iStack_3c >> 1) + -1;
        }
      }
      else if (*(int *)(param_1 + 0x324) == 1) {
        uVar16 = uVar16 | 8;
        if (bVar9) {
          iVar14 = (*(int *)(param_1 + 0x18) - iStack_3c) + -1;
        }
      }
      else if (bVar9) {
        iVar14 = 0;
      }
    }
    if (iVar14 < 0) {
      iVar14 = 0;
    }
    if (iVar15 < 0) {
      iVar15 = 0;
    }
    *(int *)(param_1 + 0x344) = iVar15;
    *(int *)(param_1 + 0x348) = iVar14;
    *(int *)(param_1 + 0x34c) = iVar15 + iVar17;
    *(int *)(param_1 + 0x350) = iVar14 + iStack_3c;
    if (*(int *)(param_1 + 0x33c) < iVar15 + iVar17) {
      *(int *)(param_1 + 0x34c) = *(int *)(param_1 + 0x33c);
    }
    if (*(int *)(param_1 + 0x340) < iVar14 + iStack_3c) {
      *(int *)(param_1 + 0x350) = *(int *)(param_1 + 0x340);
    }
    SetTextColor(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),uVar12);
    iVar13 = iVar19 + iVar13;
    iVar17 = iVar5 + -2 + iVar18;
    SetRect(auStack_10,iVar3,iVar4,iVar13 + -2,iVar17 + -2);
    DrawTextA(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),param_1 + 0xf8,0xffffffff,auStack_10
              ,uVar16);
    SetRect(auStack_10,iVar3,iVar4 + 2,iVar13 + -2,iVar17);
    DrawTextA(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),param_1 + 0xf8,0xffffffff,auStack_10
              ,uVar16);
    SetRect(auStack_10,iVar3 + 2,iVar4,iVar13,iVar17 + -2);
    DrawTextA(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),param_1 + 0xf8,0xffffffff,auStack_10
              ,uVar16);
    SetRect(auStack_10,iVar3 + 2,iVar4 + 2,iVar13,iVar17);
    DrawTextA(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),param_1 + 0xf8,0xffffffff,auStack_10
              ,uVar16);
    SetTextColor(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),uStack_28);
    SetRect(auStack_10,iVar19,iVar18,iVar13 + -1,iVar17 + -1);
    DrawTextA(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),param_1 + 0xf8,0xffffffff,auStack_10
              ,uVar16);
    pTVar6 = *(TShape **)(param_1 + 0x370);
    if (pTVar6 != (TShape *)0x0) {
      lVar7 = *(long *)(param_1 + 0x378);
      pSVar8 = pTVar6->shape_info;
      iVar17 = pSVar8[lVar7].Width;
      TShape::shape_draw(pTVar6,*(TDrawArea **)(param_1 + 0x330),
                         (pSVar8[lVar7].Hotspot_X - iVar17) + -4 + *(int *)(param_1 + 0x344),
                         pSVar8[lVar7].Hotspot_Y + 6 + *(int *)(param_1 + 0x348),lVar7,'\0',
                         (uchar *)0x0);
      *(int *)(param_1 + 0x344) = *(int *)(param_1 + 0x344) + (-4 - iVar17);
    }
    pTVar6 = *(TShape **)(param_1 + 0x374);
    if (pTVar6 != (TShape *)0x0) {
      lVar7 = *(long *)(param_1 + 0x37c);
      pSVar8 = pTVar6->shape_info;
      iVar17 = pSVar8[lVar7].Width;
      TShape::shape_draw(pTVar6,*(TDrawArea **)(param_1 + 0x330),
                         (pSVar8[lVar7].Hotspot_X - iVar17) + -4 + *(int *)(param_1 + 0x344),
                         pSVar8[lVar7].Hotspot_Y + 6 + *(int *)(param_1 + 0x348),lVar7,'\0',
                         (uchar *)0x0);
      *(int *)(param_1 + 0x344) = *(int *)(param_1 + 0x344) + (-4 - iVar17);
    }
    *(undefined4 *)(param_1 + 0x36c) = 1;
  }
  SelectObject(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),uVar11);
  SelectClipRgn(*(undefined4 *)(*(int *)(param_1 + 0x330) + 0x38),0);
  TDrawArea::ReleaseDc(*(TDrawArea **)(param_1 + 0x330),s_pnl_msg__render_to_image_buffer);
  *(int *)(param_1 + 0x354) = *(int *)(param_1 + 0x344) + *(int *)(param_1 + 0x8c);
  *(int *)(param_1 + 0x358) = *(int *)(param_1 + 0x348) + *(int *)(param_1 + 0x90);
  *(int *)(param_1 + 0x35c) = *(int *)(param_1 + 0x34c) + *(int *)(param_1 + 0x8c);
  *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x350) + *(int *)(param_1 + 0x90);
  return *(undefined4 *)(param_1 + 0x36c);
}

// --------------------------------------------------

// Function: FUN_0047a15e
// Address: 0047a15e
undefined4 FUN_0047a15e(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047a165
// Address: 0047a165
undefined4 FUN_0047a165(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047a175
// Address: 0047a175
undefined4 FUN_0047a175(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047a185
// Address: 0047a185
void __thiscall FUN_0047a185(int *param_1,int param_2,int param_3,int param_4)
{
  if (param_1[0xc1] != param_2) {
    param_1[0xc1] = param_2;
    param_1[0xc2] = param_3;
    param_1[0xc3] = param_4;
    *(undefined1 *)((int)param_1 + 0xf3) = 1;
    (**(code **)(*param_1 + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047a1c9
// Address: 0047a1c9
TPanel * __fastcall FUN_0047a1c9(TPanel *param_1)
{
  TPanel::TPanel(param_1);
  param_1[1].pnl_wid = 1;
  param_1[1].pnl_y = 0;
  param_1[1].pnl_hgt = 0;
  param_1[1].panelNameValue = (char *)0x0;
  param_1[1].render_area = (TDrawArea *)0x0;
  param_1[1].clip_rect.left = 0;
  param_1->handle_mouse_input = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TPicturePanel::_vftable_;
  param_1->panel_type = '\x02';
  param_1[1].pnl_x = -1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047a229
// Address: 0047a229
TPicturePanel * __thiscall FUN_0047a229(TPicturePanel *param_1,byte param_2)
{
  TPicturePanel::~TPicturePanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047a24e
// Address: 0047a24e
void __fastcall FUN_0047a24e(TPicturePanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e528;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TPicturePanel::_vftable_;
  uStack_4 = 0;
  TPicturePanel::free_pic(param_1);
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0047a29f
// Address: 0047a29f
undefined4 __thiscall
FUN_0047a29f(TPicturePanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,char *param_8,long param_9,int param_10,int param_11)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_8 == (char *)0x0) {
    param_1->pic_name[0] = '\0';
  }
  else {
    uVar3 = 0xffffffff;
    pcVar5 = param_8;
    do {
      pcVar6 = pcVar5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar5 = pcVar6 + -uVar3;
    pcVar6 = param_1->pic_name;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  param_1->res_id = param_9;
  param_1->size_from_pic = param_10;
  param_1->keep_loaded = param_11;
  if (((param_10 != 0) || (param_11 != 0)) && (iVar2 = TPicturePanel::load_pic(param_1), iVar2 != 0)
     ) {
    if (param_1->size_from_pic != 0) {
      if (param_1->pic_type == Picture) {
        param_6 = param_1->pic->Width;
        param_7 = param_1->pic->Height;
      }
      else {
        TShape::shape_bounds(param_1->shape,0,(short *)&param_8,(short *)&param_9);
        param_6 = (long)(short)param_8;
        param_7 = (long)(short)param_9;
      }
    }
    if (param_1->keep_loaded == 0) {
      TPicturePanel::free_pic(param_1);
    }
  }
  TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6,param_7,'\0');
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047a39c
// Address: 0047a39c
void __thiscall FUN_0047a39c(TPicturePanel *param_1,TShape *param_2,long param_3)
{
  TPicturePanel::free_pic(param_1);
  param_1->res_id = param_3;
  param_1->shape = param_2;
  param_1->own_pic = 0;
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047a3d3
// Address: 0047a3d3
// [HELPER] s_: ""
// [HELPER] s__s_bmp: "%s.bmp"
// [HELPER] s__s_shp: "%s.shp"
undefined4 __fastcall FUN_0047a3d3(TPicturePanel *param_1)
{
  TShape *pTVar1;
  int iVar2;
  TPicture *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  char acStack_5c [80];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e561;
  *unaff_FS_OFFSET = &uStack_c;
  TPicturePanel::free_pic(param_1);
  if (param_1->pic_name[0] == '\0') {
    if (param_1->res_id == -1) goto LAB_0047a59a;
    pTVar1 = (TShape *)operator_new(0x20);
    uStack_4 = 1;
    if (pTVar1 == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape(pTVar1,s_,param_1->res_id);
    }
  }
  else {
    sprintf(acStack_5c,s__s_shp,param_1->pic_name);
    pTVar1 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTVar1 == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape(pTVar1,acStack_5c,param_1->res_id);
    }
  }
  uStack_4 = 0xffffffff;
  param_1->shape = pTVar1;
  if (pTVar1 != (TShape *)0x0) {
    iVar2 = TShape::is_loaded(pTVar1);
    if (iVar2 != 0) {
      param_1->pic_type = Shape;
      param_1->own_pic = 1;
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    pTVar1 = param_1->shape;
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
    }
    param_1->shape = (TShape *)0x0;
  }
  sprintf(acStack_5c,s__s_bmp,param_1->pic_name);
  pTVar3 = (TPicture *)operator_new(0x20);
  uStack_4 = 2;
  if (pTVar3 == (TPicture *)0x0) {
    pTVar3 = (TPicture *)0x0;
  }
  else {
    pTVar3 = (TPicture *)TPicture::TPicture(pTVar3,acStack_5c,-1,0,(void *)0x0,0);
  }
  uStack_4 = 0xffffffff;
  param_1->pic = pTVar3;
  if (pTVar3 != (TPicture *)0x0) {
    if (pTVar3->Dib != (tagBITMAPINFOHEADER *)0x0) {
      param_1->pic_type = Picture;
      param_1->own_pic = 1;
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    TPicture::~TPicture(pTVar3);
    operator_delete(pTVar3);
    param_1->pic = (TPicture *)0x0;
  }
LAB_0047a59a:
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047a5af
// Address: 0047a5af
void __fastcall FUN_0047a5af(int param_1)
{
  TPicture *this;
  TShape *this_00;
  
  this = *(TPicture **)(param_1 + 0x114);
  if (this != (TPicture *)0x0) {
    if ((*(int *)(param_1 + 0x10c) != 0) && (this != (TPicture *)0x0)) {
      TPicture::~TPicture(this);
      operator_delete(this);
    }
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  this_00 = *(TShape **)(param_1 + 0x118);
  if (this_00 != (TShape *)0x0) {
    if ((*(int *)(param_1 + 0x10c) != 0) && (this_00 != (TShape *)0x0)) {
      TShape::~TShape(this_00);
      operator_delete(this_00);
    }
    *(undefined4 *)(param_1 + 0x118) = 0;
  }
  *(undefined4 *)(param_1 + 0x10c) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0047a625
// Address: 0047a625
// [HELPER] s_pnl_pic__draw: "pnl_pic::draw"
void __fastcall FUN_0047a625(TPicturePanel *param_1)
{
  int iVar1;
  uchar *puVar2;
  
  if (((param_1->_padding_ != 0) && (param_1->_padding_ != 0)) && (param_1->_padding_ != 0)) {
    iVar1 = param_1->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    if (param_1->keep_loaded == 0) {
      TPicturePanel::load_pic(param_1);
    }
    puVar2 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_pnl_pic__draw,1);
    if (puVar2 != (uchar *)0x0) {
      if (param_1->pic_type == Picture) {
        if (param_1->pic != (TPicture *)0x0) {
          TPicture::Draw(param_1->pic,(TDrawArea *)param_1->_padding_,param_1->_padding_,
                         param_1->_padding_,0,0);
        }
      }
      else if (param_1->shape != (TShape *)0x0) {
        TShape::shape_draw(param_1->shape,(TDrawArea *)param_1->_padding_,param_1->_padding_,
                           param_1->_padding_,0,'\0',(uchar *)0x0);
      }
      TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_pnl_pic__draw);
    }
    if (param_1->keep_loaded == 0) {
      TPicturePanel::free_pic(param_1);
    }
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047a6f2
// Address: 0047a6f2
TPanel * __fastcall FUN_0047a6f2(TPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e578;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel(param_1);
  param_1[1]._padding_ = 0;
  param_1[1].previousPanelValue = (TPanel *)0x0;
  param_1[1].previousModalPanelValue = (TPanel *)0x0;
  param_1[1].pnl_x = 0;
  param_1[1].pnl_y = 0;
  param_1[1].pnl_wid = 0;
  param_1[1].pnl_hgt = 0;
  uStack_4 = 0;
  param_1[1].panelNameValue = (char *)0x0;
  param_1[1].render_area = (TDrawArea *)0x0;
  param_1[1].clip_rect.left = 0;
  param_1[1].clip_rect.top = 0;
  param_1[1].clip_rect.right = 0;
  param_1[1].clip_rect.bottom = 0;
  param_1[1].position_mode = PositionFixed;
  param_1[1].need_redraw = RedrawNone;
  param_1[1].curr_child = (TPanel *)0x0;
  param_1[1].parent_panel = (TPanel *)0x0;
  param_1[1].left_panel = (TPanel *)0x0;
  param_1[1].top_panel = (TPanel *)0x0;
  param_1[1].right_panel = (TPanel *)0x0;
  *(undefined1 *)&param_1[1].bottom_panel = 0;
  param_1[1].node = (PanelNode *)0x0;
  param_1[1].first_child_node = (PanelNode *)0x0;
  param_1[1].last_child_node = (PanelNode *)0x0;
  *(undefined1 *)&param_1[1].tab_prev_panel = 0;
  param_1[1].tab_next_panel = (TPanel *)0x0;
  param_1[1].mouse_captured = 100;
  param_1[1].active = 0xfa;
  param_1[1].mouse_move_tolerance = 0;
  param_1[1].mouse_down_x = 1;
  *(undefined1 *)&param_1[1].mouse_down_y = 0;
  *(undefined1 *)((int)&param_1[1].mouse_down_y + 1) = 0;
  *(undefined1 *)((int)&param_1[1].mouse_down_y + 2) = 0;
  *(undefined1 *)((int)&param_1[1].mouse_down_y + 3) = 0;
  *(undefined1 *)&param_1[1].mouse_down_ctrl = 0;
  *(undefined1 *)((int)&param_1[1].mouse_down_ctrl + 1) = 0;
  param_1->_padding_ = (int)&TScrollBarPanel::_vftable_;
  param_1->panel_type = '\x05';
  param_1->mouse_move_tolerance = 0;
  SetRect(&param_1[1].visible,0,0,0,0);
  SetRect(&param_1[1].handle_mouse_input,0,0,0,0);
  SetRect(&param_1[1].render_rect.top,0,0,0,0);
  SetRect(&param_1[1].top_border,0,0,0,0);
  SetRect(&param_1[1].max_wid,0,0,0,0);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047a87c
// Address: 0047a87c
TScrollBarPanel * __thiscall FUN_0047a87c(TScrollBarPanel *param_1,byte param_2)
{
  TScrollBarPanel::~TScrollBarPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047a89e
// Address: 0047a89e
void __fastcall FUN_0047a89e(TPanel *param_1)
{
  param_1->_padding_ = (int)&TScrollBarPanel::_vftable_;
  TPanel::~TPanel(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047a8ab
// Address: 0047a8ab
undefined4 __thiscall
FUN_0047a8ab(TPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7)
{
  long in_stack_0000002c;
  long in_stack_00000030;
  int in_stack_00000034;
  TPanel *in_stack_00000038;
  long in_stack_0000003c;
  
  param_1[1].mouse_move_tolerance = in_stack_0000003c;
  param_1[1].clip_rect.top = in_stack_0000002c;
  param_1[1].clip_rect.right = in_stack_00000030;
  param_1[1]._padding_ = in_stack_00000034;
  param_1[1].previousPanelValue = in_stack_00000038;
  TPanel::setup(param_1,param_2,param_3,param_4,param_5,param_6,param_7,'\0');
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047a90f
// Address: 0047a90f
void __thiscall
FUN_0047a90f(TScrollBarPanel *param_1,long param_2,long param_3,long param_4,long param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  TPanel::set_rect((TPanel *)param_1,param_2,param_3,param_4,param_5);
  if (param_1->orientationValue == Horizontal) {
    iVar2 = param_1->_padding_;
    iVar3 = param_1->_padding_;
    iVar1 = param_1->_padding_ + 2;
    iVar5 = iVar2 + -5 + param_1->_padding_;
    iVar4 = param_1->_padding_;
    (param_1->up_rect).top = iVar1;
    (param_1->down_rect).top = iVar1;
    iVar6 = (iVar3 + iVar4) - iVar2;
    (param_1->up_rect).left = iVar4 + 2;
    (param_1->tab_rect).top = iVar1;
    iVar3 = iVar6 + 2;
    iVar4 = iVar4 + -3 + iVar2;
    (param_1->down_rect).left = iVar3;
    (param_1->top_rect).top = iVar1;
    (param_1->bottom_rect).top = iVar1;
    iVar1 = iVar4 + 1;
    param_1->tab_min_x = iVar1;
    param_1->tab_x = iVar1;
    (param_1->up_rect).bottom = iVar5;
    (param_1->up_rect).right = iVar4;
    (param_1->down_rect).bottom = iVar5;
    (param_1->down_rect).right = iVar6 + -3 + iVar2;
    (param_1->tab_rect).bottom = iVar5;
    (param_1->top_rect).bottom = iVar5;
    (param_1->bottom_rect).bottom = iVar5;
    param_1->tab_max_x = (iVar3 - iVar2) + 4;
    TScrollBarPanel::calc_item_rects(param_1);
    return;
  }
  iVar2 = param_1->_padding_;
  iVar1 = param_1->_padding_ + 2;
  iVar6 = (param_1->_padding_ + param_1->_padding_) - iVar2;
  iVar5 = param_1->_padding_ + 2;
  (param_1->up_rect).top = iVar1;
  iVar1 = iVar2 + -5 + iVar1;
  iVar3 = iVar6 + 2;
  (param_1->up_rect).left = iVar5;
  (param_1->down_rect).top = iVar3;
  iVar4 = iVar2 + -5 + iVar5;
  (param_1->down_rect).left = iVar5;
  (param_1->tab_rect).left = iVar5;
  (param_1->top_rect).left = iVar5;
  (param_1->bottom_rect).left = iVar5;
  iVar5 = iVar1 + 1;
  param_1->tab_max_y = (iVar3 - iVar2) + 4;
  (param_1->up_rect).right = iVar4;
  (param_1->up_rect).bottom = iVar1;
  (param_1->down_rect).right = iVar4;
  (param_1->down_rect).bottom = iVar6 + -3 + iVar2;
  (param_1->tab_rect).right = iVar4;
  (param_1->top_rect).right = iVar4;
  (param_1->bottom_rect).right = iVar4;
  param_1->tab_min_y = iVar5;
  param_1->tab_y = iVar5;
  TScrollBarPanel::calc_item_rects(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047ab12
// Address: 0047ab12
void __thiscall FUN_0047ab12(TScrollBarPanel *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = param_1->list_len;
  param_1->list_num = param_2;
  if (param_1->orientationValue == Horizontal) {
    if (0 < iVar1) {
      param_1->tab_x =
           (((param_1->tabSize / 2 + param_1->tab_max_x) - param_1->tab_min_x) * param_2) / iVar1 +
           param_1->tab_min_x;
    }
    if (param_1->tab_x < param_1->tab_min_x) {
      param_1->tab_x = param_1->tab_min_x;
    }
    else if (param_1->tab_max_x < param_1->tab_x) {
      param_1->tab_x = param_1->tab_max_x;
    }
  }
  else {
    if (0 < iVar1) {
      if (param_2 == iVar1 + -1) {
        param_1->tab_y = param_1->tab_max_y;
      }
      else {
        param_1->tab_y =
             (((param_1->tabSize / 2 + param_1->tab_max_y) - param_1->tab_min_y) * param_2) / iVar1
             + param_1->tab_min_y;
      }
    }
    iVar1 = param_1->tab_min_y;
    if ((param_1->tab_y < iVar1) || (iVar1 = param_1->tab_max_y, iVar1 < param_1->tab_y)) {
      param_1->tab_y = iVar1;
    }
  }
  TScrollBarPanel::calc_item_rects(param_1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047ac0f
// Address: 0047ac0f
void __thiscall FUN_0047ac0f(TScrollBarPanel *param_1,long param_2,long param_3)
{
  param_1->list_len = param_2;
  TScrollBarPanel::set_tab_pos(param_1,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0047ac27
// Address: 0047ac27
void __thiscall
FUN_0047ac27(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)
{
  *(undefined4 *)(param_1 + 0x108) = param_2;
  *(undefined4 *)(param_1 + 0x10c) = param_3;
  *(undefined4 *)(param_1 + 0x110) = param_4;
  *(undefined4 *)(param_1 + 0x114) = param_5;
  *(undefined4 *)(param_1 + 0x118) = param_6;
  return;
}

// --------------------------------------------------

// Function: FUN_0047ac65
// Address: 0047ac65
void __thiscall
FUN_0047ac65(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5
            ,undefined1 param_6,undefined1 param_7,undefined1 param_8)
{
  *(undefined4 *)(param_1 + 0x1b8) = param_2;
  *(undefined1 *)(param_1 + 0x1bc) = param_3;
  *(undefined1 *)(param_1 + 0x1bd) = param_4;
  *(undefined1 *)(param_1 + 0x1be) = param_5;
  *(undefined1 *)(param_1 + 0x1bf) = param_6;
  *(undefined1 *)(param_1 + 0x1c0) = param_7;
  *(undefined1 *)(param_1 + 0x1c1) = param_8;
  return;
}

// --------------------------------------------------

// Function: FUN_0047acb9
// Address: 0047acb9
// [HELPER] s_C__msdev_work_age1_x1_Pnl_scbr_c: "C:\msdev\work\age1_x1\Pnl_scbr.cpp"
undefined4 __fastcall FUN_0047acb9(TScrollBarPanel *param_1)
{
  ulong uVar1;
  int iVar2;
  
  if (param_1->item_mode == '\x01') {
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_scbr_c,0x128);
    if (param_1->item_down_interval <= uVar1 - param_1->item_last_time) {
      param_1->item_mode = '\x02';
      param_1->item_last_time = uVar1 - param_1->item_hold_interval;
    }
  }
  else if (((param_1->item_mode == '\x02') && (param_1->item_is_down != 0)) &&
          (uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_scbr_c,0x132),
          param_1->item_hold_interval <= uVar1 - param_1->item_last_time)) {
    param_1->item_last_time = uVar1;
    switch(param_1->item_down) {
    case '\x01':
      TScrollBarPanel::scroll(param_1,ActionUp,0);
      return 0;
    case '\x02':
      TScrollBarPanel::scroll(param_1,ActionDown,0);
      return 0;
    case '\x04':
      iVar2 = TPanel::is_inside_rect
                        ((TPanel *)param_1,param_1->item_x,param_1->item_y,&param_1->top_rect);
      if (iVar2 == 0) {
        param_1->item_is_down = 0;
        param_1->item_mode = '\0';
        (**(code **)(param_1->_padding_ + 0x20))(1);
        return 0;
      }
      TScrollBarPanel::scroll(param_1,ActionPrior,0);
      return 0;
    case '\x05':
      iVar2 = TPanel::is_inside_rect
                        ((TPanel *)param_1,param_1->item_x,param_1->item_y,&param_1->bottom_rect);
      if (iVar2 == 0) {
        param_1->item_is_down = 0;
        param_1->item_mode = '\0';
        (**(code **)(param_1->_padding_ + 0x20))(1);
        return 0;
      }
      TScrollBarPanel::scroll(param_1,ActionNext,0);
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047ae22
// Address: 0047ae22
// [HELPER] s_C__msdev_work_age1_x1_Pnl_scbr_c: "C:\msdev\work\age1_x1\Pnl_scbr.cpp"
undefined4 __thiscall FUN_0047ae22(TScrollBarPanel *param_1,int param_2,int param_3)
{
  char *pcVar1;
  TPanel *pTVar2;
  int iVar3;
  ulong uVar4;
  char unaff_BL;
  
  cRam500047ae = cRam500047ae + unaff_BL;
  pcVar1 = (char *)((int)&param_1[-0x3f6eda]._padding_ + 1);
  *pcVar1 = *pcVar1 + unaff_BL;
  TPanel::capture_mouse((TPanel *)param_1);
  iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->up_rect);
  if (iVar3 == 0) {
    iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->down_rect);
    if (iVar3 == 0) {
      iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->tab_rect);
      if (iVar3 == 0) {
        iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->top_rect);
        if (iVar3 == 0) {
          iVar3 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->bottom_rect);
          if (iVar3 == 0) {
            param_1->item_down = '\0';
          }
          else {
            param_1->item_down = '\x05';
            param_1->item_is_down = 1;
            TScrollBarPanel::scroll(param_1,ActionNext,0);
          }
        }
        else {
          param_1->item_down = '\x04';
          param_1->item_is_down = 1;
          TScrollBarPanel::scroll(param_1,ActionPrior,0);
        }
      }
      else {
        param_1->item_down = '\x03';
        if (param_1->orientationValue == Horizontal) {
          param_1->tab_mouse_x = param_2 - param_1->tab_x;
        }
        else {
          param_1->tab_mouse_y = param_3 - param_1->tab_y;
        }
      }
    }
    else {
      param_1->item_down = '\x02';
      param_1->item_is_down = 1;
      TScrollBarPanel::scroll(param_1,ActionDown,0);
    }
  }
  else {
    param_1->item_down = '\x01';
    param_1->item_is_down = 1;
    TScrollBarPanel::scroll(param_1,ActionUp,0);
  }
  if (param_1->item_down != '\0') {
    pTVar2 = param_1->list_panel;
    if (((pTVar2 != (TPanel *)0x0) && (pTVar2->tab_stop != 0)) &&
       (pTVar2->parent_panel != (TPanel *)0x0)) {
      TPanel::set_curr_child(pTVar2->parent_panel,pTVar2);
    }
    param_1->item_x = param_2;
    param_1->item_y = param_3;
    param_1->item_mode = '\x01';
    uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_scbr_c,0x185);
    param_1->item_last_time = uVar4;
    (**(code **)(param_1->_padding_ + 0x20))(1);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047afc7
// Address: 0047afc7
// [HELPER] s_C__msdev_work_age1_x1_Pnl_scbr_c: "C:\msdev\work\age1_x1\Pnl_scbr.cpp"
undefined4 __thiscall FUN_0047afc7(TScrollBarPanel *param_1,int param_2,int param_3)
{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  ActionType AVar6;
  
  switch(param_1->item_down) {
  case '\x01':
    iVar1 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->up_rect);
    iVar3 = param_1->item_is_down;
    if (iVar1 == 0) {
LAB_0047b111:
      if (iVar3 != 0) {
        param_1->item_is_down = 0;
        param_1->item_mode = '\0';
        (**(code **)(param_1->_padding_ + 0x20))(1);
      }
      goto switchD_0047afee_default;
    }
    if (iVar3 != 0) goto switchD_0047afee_default;
    param_1->item_is_down = 1;
    param_1->item_mode = '\x02';
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_scbr_c,0x19a);
    param_1->item_last_time = uVar2;
    AVar6 = ActionUp;
    break;
  case '\x02':
    iVar1 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->down_rect);
    iVar3 = param_1->item_is_down;
    if (iVar1 == 0) {
LAB_0047b19a:
      if (iVar3 != 0) {
        param_1->item_is_down = 0;
        param_1->item_mode = '\0';
        (**(code **)(param_1->_padding_ + 0x20))(1);
      }
      goto switchD_0047afee_default;
    }
    if (iVar3 != 0) goto switchD_0047afee_default;
    param_1->item_is_down = 1;
    param_1->item_mode = '\x02';
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_scbr_c,0x1ad);
    param_1->item_last_time = uVar2;
    AVar6 = ActionDown;
    goto LAB_0047b185;
  case '\x03':
    if (param_1->orientationValue == Horizontal) {
      iVar4 = param_2 - param_1->item_x;
      iVar3 = param_1->tab_x;
      iVar1 = param_1->tab_min_x;
      if ((((iVar3 == iVar1) && (0 < iVar4)) && (param_2 < param_1->tab_mouse_x + iVar3)) ||
         (((iVar3 == param_1->tab_max_x && (iVar4 < 0)) && (param_1->tab_mouse_x + iVar3 <= param_2)
          ))) {
        iVar4 = 0;
      }
      if (iVar4 == 0) goto switchD_0047afee_default;
      iVar4 = param_1->tab_x + iVar4;
      param_1->tab_x = iVar4;
      if (iVar4 < iVar1) {
        param_1->tab_x = iVar1;
      }
      else if (param_1->tab_max_x < iVar4) {
        param_1->tab_x = param_1->tab_max_x;
      }
      TScrollBarPanel::calc_item_rects(param_1);
      (**(code **)(param_1->_padding_ + 0x20))(1);
      iVar3 = param_1->tab_min_x;
      if (iVar3 == param_1->tab_max_x) {
        lVar5 = 0;
      }
      else {
        lVar5 = ((param_1->tab_x - iVar3) * param_1->list_len) / (param_1->tab_max_x - iVar3);
        if (lVar5 < 0) {
          lVar5 = 0;
        }
        else {
          iVar3 = param_1->list_len + -1;
          if (iVar3 < lVar5) {
LAB_0047b382:
            lVar5 = iVar3;
          }
        }
      }
    }
    else {
      iVar4 = param_3 - param_1->item_y;
      iVar3 = param_1->tab_y;
      iVar1 = param_1->tab_min_y;
      if (((iVar3 == iVar1) && (0 < iVar4)) && (param_3 < param_1->tab_mouse_y + iVar3)) {
        iVar4 = 0;
      }
      else if (((iVar3 == param_1->tab_max_y) && (iVar4 < 0)) &&
              (param_1->tab_mouse_y + iVar3 <= param_3)) {
        iVar4 = 0;
      }
      if (iVar4 == 0) goto switchD_0047afee_default;
      iVar4 = param_1->tab_y + iVar4;
      param_1->tab_y = iVar4;
      if (iVar4 < iVar1) {
        param_1->tab_y = iVar1;
      }
      else if (param_1->tab_max_y < iVar4) {
        param_1->tab_y = param_1->tab_max_y;
      }
      TScrollBarPanel::calc_item_rects(param_1);
      (**(code **)(param_1->_padding_ + 0x20))(1);
      iVar3 = param_1->tab_min_y;
      if (iVar3 == param_1->tab_max_y) {
        lVar5 = 0;
      }
      else {
        lVar5 = ((param_1->tab_y - iVar3) * param_1->list_len) / (param_1->tab_max_y - iVar3);
        if (lVar5 < 0) {
          lVar5 = 0;
        }
        else {
          iVar3 = param_1->list_len + -1;
          if (iVar3 < lVar5) goto LAB_0047b382;
        }
      }
    }
    TScrollBarPanel::scroll(param_1,ActionPosition,lVar5);
    goto switchD_0047afee_default;
  case '\x04':
    iVar1 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->top_rect);
    iVar3 = param_1->item_is_down;
    if (iVar1 == 0) goto LAB_0047b111;
    if (iVar3 != 0) goto switchD_0047afee_default;
    param_1->item_is_down = 1;
    param_1->item_mode = '\x02';
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_scbr_c,0x1c0);
    param_1->item_last_time = uVar2;
    AVar6 = ActionPrior;
    break;
  case '\x05':
    iVar1 = TPanel::is_inside_rect((TPanel *)param_1,param_2,param_3,&param_1->bottom_rect);
    iVar3 = param_1->item_is_down;
    if (iVar1 == 0) goto LAB_0047b19a;
    if (iVar3 != 0) goto switchD_0047afee_default;
    param_1->item_is_down = 1;
    param_1->item_mode = '\x02';
    uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_scbr_c,0x1d3);
    param_1->item_last_time = uVar2;
    AVar6 = ActionNext;
LAB_0047b185:
    TScrollBarPanel::scroll(param_1,AVar6,0);
    (**(code **)(param_1->_padding_ + 0x20))(1);
  default:
    goto switchD_0047afee_default;
  }
  TScrollBarPanel::scroll(param_1,AVar6,0);
  (**(code **)(param_1->_padding_ + 0x20))(1);
switchD_0047afee_default:
  if (param_1->item_down != '\0') {
    param_1->item_x = param_2;
    param_1->item_y = param_3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047b3af
// Address: 0047b3af
undefined4 __fastcall FUN_0047b3af(int param_1,undefined4 param_2)
{
  char *pcVar1;
  int iVar2;
  int in_EAX;
  TPanel *this;
  char *unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  *(char *)(unaff_EDI + -0x4b) = *(char *)(unaff_EDI + -0x4b) + (char)param_1;
  pcVar1 = (char *)(param_1 + -0x4f55ffb9 + unaff_ESI * 4);
  *pcVar1 = *pcVar1 + (char)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX + (char)((uint)param_2 >> 8);
  this = (TPanel *)CONCAT31((int3)((uint)param_1 >> 8),0x47);
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + (char)param_2;
  if (this->parent_panel != (TPanel *)0x0) {
    (**(code **)(this->parent_panel->_padding_ + 0xb4))(this,5,this[1].pnl_y,0);
  }
  TPanel::release_mouse(this);
  iVar2 = this->_padding_;
  *(undefined1 *)&this[1].bottom_panel = 0;
  *(undefined1 *)&this[1].tab_prev_panel = 0;
  this[1].node = (PanelNode *)0x0;
  (**(code **)(iVar2 + 0x20))(1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047b41c
// Address: 0047b41c
void __thiscall FUN_0047b41c(TScrollBarPanel *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  if (param_1->list_panel != (TPanel *)0x0) {
    (**(code **)(param_1->list_panel->_padding_ + 0xb4))(param_1,param_2,param_3,0);
    return;
  }
  iVar1 = param_1->list_num;
  switch(param_2) {
  case 0:
    param_3 = iVar1 - param_1->one_step;
    break;
  case 1:
    param_3 = iVar1 + param_1->one_step;
    break;
  case 2:
    param_3 = iVar1 - param_1->page_step;
    break;
  case 3:
    param_3 = iVar1 + param_1->page_step;
    break;
  case 4:
    break;
  default:
    goto switchD_0047b459_default;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  else {
    iVar2 = param_1->list_len + -1;
    if (iVar2 < param_3) {
      param_3 = iVar2;
    }
  }
  if (param_3 != iVar1) {
    TScrollBarPanel::set_tab_pos(param_1,param_3);
    if ((int *)param_1->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,4,param_3,0);
    }
  }
switchD_0047b459_default:
  return;
}

// --------------------------------------------------

// Function: FUN_0047b4bf
// Address: 0047b4bf
// [HELPER] s_pnl_scbr__draw: "pnl_scbr::draw"
void __fastcall FUN_0047b4bf(TScrollBarPanel *param_1,undefined4 param_2)
{
  undefined4 in_EAX;
  int iVar1;
  uchar *puVar2;
  int iVar3;
  undefined4 unaff_EBX;
  int unaff_EDI;
  
  iVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(0x47,(char)in_EAX));
  *(char *)(iVar1 + -0x4c) = *(char *)(iVar1 + -0x4c) + (char)((uint)param_1 >> 8);
  *(char *)(iVar1 + -0x4c) = *(char *)(iVar1 + -0x4c) + (char)((uint)param_2 >> 8);
  *(char *)(iVar1 + -0x4c) = *(char *)(iVar1 + -0x4c) + (char)((uint)unaff_EBX >> 8);
  *(char *)(iVar1 + -0x6fffb84c) = *(char *)(iVar1 + -0x6fffb84c) + (char)in_EAX;
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0x3c))(&param_1->_padding_,unaff_EDI + 3);
  }
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0x28))(0);
  puVar2 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_pnl_scbr__draw,1);
  if (puVar2 != (uchar *)0x0) {
    TScrollBarPanel::draw_back_pic(param_1);
    TScrollBarPanel::draw_border(param_1,0,1,(tagRECT *)&param_1->_padding_);
    if (((param_1->up_rect).top != (param_1->up_rect).bottom) &&
       ((param_1->up_rect).left != (param_1->up_rect).right)) {
      if ((param_1->item_down == '\x01') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic(param_1,param_1->up_frame,iVar3,&param_1->up_rect);
      if ((param_1->item_down == '\x01') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border(param_1,1,iVar3,&param_1->up_rect);
    }
    if (((param_1->down_rect).top != (param_1->down_rect).bottom) &&
       ((param_1->down_rect).left != (param_1->down_rect).right)) {
      if ((param_1->item_down == '\x02') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic(param_1,param_1->down_frame,iVar3,&param_1->down_rect);
      if ((param_1->item_down == '\x02') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border(param_1,1,iVar3,&param_1->down_rect);
    }
    TScrollBarPanel::draw_button_pic(param_1,param_1->tab_frame,0,&param_1->tab_rect);
    TScrollBarPanel::draw_border(param_1,1,0,&param_1->tab_rect);
    TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_pnl_scbr__draw);
  }
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0047b659
// Address: 0047b659
void __thiscall FUN_0047b659(TScrollBarPanel *param_1,int param_2,int param_3,long *param_4)
{
  TScrollBarPanel::draw_border(param_1,param_2,param_3,*param_4,param_4[1],param_4[2],param_4[3]);
  return;
}

// --------------------------------------------------

// Function: FUN_0047b685
// Address: 0047b685
void __thiscall
FUN_0047b685(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)
{
  uchar uVar1;
  
  if ((param_4 != param_6) && (param_5 != param_7)) {
    if (param_3 == 0) {
      switch(*(undefined4 *)(param_1 + 0x1b8)) {
      case 1:
        uVar1 = '\0';
        if (param_2 != 0) {
          TDrawArea::DrawVertLine
                    (*(TDrawArea **)(param_1 + 0x20),param_6,param_5 + 1,param_7 - param_5,'\0');
          TDrawArea::DrawHorzLine
                    (*(TDrawArea **)(param_1 + 0x20),param_4 + 1,param_5,param_6 - param_4,'\0');
          TDrawArea::DrawRect(*(TDrawArea **)(param_1 + 0x20),param_4,param_5,param_6 + -1,
                              param_5 + -1,0xff);
          return;
        }
        goto LAB_0047b7e8;
      case 2:
        TDrawArea::DrawBevel
                  (*(TDrawArea **)(param_1 + 0x20),param_4,param_5,param_6,param_7,
                   *(uchar *)(param_1 + 0x1bc),*(uchar *)(param_1 + 0x1c1));
        return;
      case 3:
        TDrawArea::DrawBevel2
                  (*(TDrawArea **)(param_1 + 0x20),param_4,param_5,param_6,param_7,
                   *(uchar *)(param_1 + 0x1bc),*(uchar *)(param_1 + 0x1bd),
                   *(uchar *)(param_1 + 0x1c0),*(uchar *)(param_1 + 0x1c1));
        return;
      case 4:
        TDrawArea::DrawBevel3
                  (*(TDrawArea **)(param_1 + 0x20),param_4,param_5,param_6,param_7,
                   *(uchar *)(param_1 + 0x1bc),*(uchar *)(param_1 + 0x1bd),
                   *(uchar *)(param_1 + 0x1be),*(uchar *)(param_1 + 0x1bf),
                   *(uchar *)(param_1 + 0x1c0),*(uchar *)(param_1 + 0x1c1));
      }
    }
    else {
      switch(*(undefined4 *)(param_1 + 0x1b8)) {
      case 1:
        uVar1 = 0xff;
        if (param_2 != 0) {
          TDrawArea::DrawRect(*(TDrawArea **)(param_1 + 0x20),param_4 + 1,param_5 + 1,param_6,
                              param_7,0xff);
          return;
        }
LAB_0047b7e8:
        TDrawArea::DrawRect(*(TDrawArea **)(param_1 + 0x20),param_4,param_5,param_6 + -1,param_7,
                            uVar1);
        return;
      case 2:
        TDrawArea::DrawBevel
                  (*(TDrawArea **)(param_1 + 0x20),param_4,param_5,param_6,param_7,
                   *(uchar *)(param_1 + 0x1c1),*(uchar *)(param_1 + 0x1bc));
        return;
      case 3:
        TDrawArea::DrawBevel2
                  (*(TDrawArea **)(param_1 + 0x20),param_4,param_5,param_6,param_7,
                   *(uchar *)(param_1 + 0x1c1),*(uchar *)(param_1 + 0x1c0),
                   *(uchar *)(param_1 + 0x1bd),*(uchar *)(param_1 + 0x1bc));
        return;
      case 4:
        TDrawArea::DrawBevel3
                  (*(TDrawArea **)(param_1 + 0x20),param_4,param_5,param_6,param_7,
                   *(uchar *)(param_1 + 0x1c1),*(uchar *)(param_1 + 0x1c0),
                   *(uchar *)(param_1 + 0x1bf),*(uchar *)(param_1 + 0x1be),
                   *(uchar *)(param_1 + 0x1bd),*(uchar *)(param_1 + 0x1bc));
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047b964
// Address: 0047b964
void __thiscall FUN_0047b964(int param_1,int param_2,int param_3,tagRECT *param_4)
{
  tagRECT *ptVar1;
  short sVar2;
  short sVar3;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  ptVar1 = param_4;
  if ((*(int *)(param_1 + 0x108) != 0) && (param_2 != -1)) {
    TDrawArea::SetClipRect(*(TDrawArea **)(param_1 + 0x20),param_4);
    TShape::shape_minmax
              (*(TShape **)(param_1 + 0x108),&iStack_c,&iStack_4,(long *)&param_4,&iStack_8,param_2)
    ;
    sVar2 = (((short)(((ptVar1->right - ptVar1->left) + 1) / 2) -
             (short)(((int)param_4 + (1 - iStack_c)) / 2)) - (short)iStack_c) + (short)ptVar1->left;
    sVar3 = (((short)(((ptVar1->bottom - ptVar1->top) + 1) / 2) -
             (short)(((iStack_8 - iStack_4) + 1) / 2)) - (short)iStack_4) + (short)ptVar1->top;
    if (param_3 != 0) {
      sVar2 = sVar2 + 1;
      sVar3 = sVar3 + -1;
    }
    TShape::shape_draw(*(TShape **)(param_1 + 0x108),*(TDrawArea **)(param_1 + 0x20),(int)sVar2,
                       (int)sVar3,(uint)(param_3 != 0) + param_2,'\0',(uchar *)0x0);
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x40) + 0x3c))(param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0047ba65
// Address: 0047ba65
TEasy_Panel * __fastcall FUN_0047ba65(TEasy_Panel *param_1)
{
  TEasy_Panel::TEasy_Panel(param_1);
  param_1->_padding_ = (int)&TScreenPanel::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047ba82
// Address: 0047ba82
TScreenPanel * __thiscall FUN_0047ba82(TScreenPanel *param_1,byte param_2)
{
  TScreenPanel::~TScreenPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047baae
// Address: 0047baae
TEasy_Panel * __thiscall FUN_0047baae(TEasy_Panel *param_1,char *param_2)
{
  TEasy_Panel::TEasy_Panel(param_1,param_2);
  param_1->_padding_ = (int)&TScreenPanel::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047bac9
// Address: 0047bac9
void __fastcall FUN_0047bac9(TEasy_Panel *param_1)
{
  param_1->_padding_ = (int)&TScreenPanel::_vftable_;
  TEasy_Panel::~TEasy_Panel(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047badb
// Address: 0047badb
bool __thiscall
FUN_0047badb(TEasy_Panel *param_1,TDrawArea *param_2,char *param_3,long param_4,int param_5)
{
  long lVar1;
  
  lVar1 = TEasy_Panel::setup(param_1,param_2,(TPanel *)0x0,param_3,param_4,1,0,0,0,0,param_5);
  return lVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_0047bb0e
// Address: 0047bb0e
bool __thiscall FUN_0047bb0e(TEasy_Panel *param_1,TDrawArea *param_2)
{
  long lVar1;
  int in_stack_00000014;
  
  lVar1 = TEasy_Panel::setup(param_1,param_2,(TPanel *)0x0,(char *)0x0,-1,1,0,0,0,0,
                             in_stack_00000014);
  return lVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_0047bb38
// Address: 0047bb38
void __fastcall FUN_0047bb38(TEasy_Panel *param_1)
{
  if (*(char *)((int)&param_1->_padding_ + 3) != '\0') {
    if (param_1->shadow_area != (TDrawArea *)0x0) {
      TEasy_Panel::setup_shadow_area(param_1,1);
    }
    *(undefined1 *)((int)&param_1->_padding_ + 3) = 0;
  }
  if (*(char *)((int)&param_1->_padding_ + 2) != '\0') {
    (**(code **)(param_1->_padding_ + 0xe0))(1);
    return;
  }
  (**(code **)(param_1->_padding_ + 0xe0))(0);
  return;
}

// --------------------------------------------------

// Function: FUN_0047bb45
// Address: 0047bb45
undefined4 __fastcall FUN_0047bb45(TPanel *param_1)
{
  TPanel::handle_paint(param_1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047bb58
// Address: 0047bb58
void __thiscall FUN_0047bb58(TEasy_Panel *param_1,int param_2)
{
  int iVar1;
  TDrawArea *pTVar2;
  TDrawSystem *pTVar3;
  bool bVar4;
  tagPALETTEENTRY tStack_408;
  tagPALETTEENTRY atStack_400 [256];
  
  iVar1 = param_1->_padding_;
  bVar4 = param_1 != (TEasy_Panel *)last_screen;
  pTVar2 = (TDrawArea *)param_1->_padding_;
  if (((((pTVar2 != (TDrawArea *)0x0) && (pTVar3 = pTVar2->DrawSystem, pTVar3 != (TDrawSystem *)0x0)
        ) && (param_2 != 0)) && (bVar4)) &&
     ((pTVar3->ScreenMode == '\x02' || (pTVar3->DrawType == '\x01')))) {
    tStack_408 = (tagPALETTEENTRY)((uint)tStack_408 & 0xff000000);
    if (param_1->palette == (void *)0x0) {
      TDrawArea::GetPalette(pTVar2,atStack_400);
    }
    else {
      GetPaletteEntries(param_1->palette,0,0x100,atStack_400);
    }
    RGE_fade_palette((TDrawArea *)param_1->_padding_,tStack_408,0.13,'\x01',(tagPALETTEENTRY *)0x0,
                     -1,-1);
    TDrawArea::Clear((TDrawArea *)param_1->_padding_,(tagRECT *)0x0,0);
    TDrawSystem::Paint(*(TDrawSystem **)param_1->_padding_,(tagRECT *)0x0);
  }
  TEasy_Panel::set_focus(param_1,param_2);
  pTVar2 = (TDrawArea *)param_1->_padding_;
  if ((((pTVar2 != (TDrawArea *)0x0) && (pTVar3 = pTVar2->DrawSystem, pTVar3 != (TDrawSystem *)0x0))
      && ((param_2 != 0 && (bVar4)))) &&
     ((pTVar3->ScreenMode == '\x02' || (pTVar3->DrawType == '\x01')))) {
    RGE_fade_palette(pTVar2,tStack_408,0.0,'\x02',atStack_400,-1,-1);
    (**(code **)(param_1->_padding_ + 0x54))();
    RGE_fade_palette((TDrawArea *)param_1->_padding_,tStack_408,0.0,'\x01',(tagPALETTEENTRY *)0x0,-1
                     ,-1);
    TDrawSystem::Paint(*(TDrawSystem **)param_1->_padding_,(tagRECT *)0x0);
    RGE_fade_palette((TDrawArea *)param_1->_padding_,tStack_408,0.13,'\x02',atStack_400,-1,-1);
  }
  if ((param_2 != iVar1) && (param_1->_padding_ != 0)) {
    last_screen = (TScreenPanel *)param_1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047bcdf
// Address: 0047bcdf
TScrollBarPanel * __fastcall FUN_0047bcdf(TScrollBarPanel *param_1)
{
  TScrollBarPanel::TScrollBarPanel(param_1);
  param_1[1]._padding_ = 1;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TVerticalSliderPanel::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047bd06
// Address: 0047bd06
TVerticalSliderPanel * __thiscall FUN_0047bd06(TVerticalSliderPanel *param_1,byte param_2)
{
  TVerticalSliderPanel::~TVerticalSliderPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047bd2e
// Address: 0047bd2e
void __fastcall FUN_0047bd2e(TScrollBarPanel *param_1)
{
  param_1->_padding_ = (int)&TVerticalSliderPanel::_vftable_;
  TScrollBarPanel::~TScrollBarPanel(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047bd3b
// Address: 0047bd3b
undefined4 __thiscall
FUN_0047bd3b(TScrollBarPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,char *param_8,char *param_9,long param_10,long param_11,
            long param_12,long param_13,int param_14,int param_15)
{
  long lVar1;
  
  param_1[1]._padding_ = param_14;
  param_1[1]._padding_ = param_15;
  lVar1 = TScrollBarPanel::setup
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,(char *)0x0,
                     (char *)0x0,param_9,0,param_10,(TPanel *)0x0,param_11,Vertical);
  if (lVar1 == 0) {
    return 0;
  }
  param_1->one_step = param_12;
  param_1->page_step = param_13;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047bdbf
// Address: 0047bdbf
void __thiscall
FUN_0047bdbf(TScrollBarPanel *param_1,long param_2,long param_3,long param_4,long param_5)
{
  TScrollBarPanel::set_rect(param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0047bde5
// Address: 0047bde5
TVerticalSliderPanel * __fastcall FUN_0047bde5(TVerticalSliderPanel *param_1)
{
  TVerticalSliderPanel::TVerticalSliderPanel(param_1);
  param_1->_padding_ = (int)&THorizontalSliderPanel::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047be02
// Address: 0047be02
THorizontalSliderPanel * __thiscall FUN_0047be02(THorizontalSliderPanel *param_1,byte param_2)
{
  THorizontalSliderPanel::~THorizontalSliderPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047be2e
// Address: 0047be2e
void __fastcall FUN_0047be2e(TVerticalSliderPanel *param_1)
{
  param_1->_padding_ = (int)&THorizontalSliderPanel::_vftable_;
  TVerticalSliderPanel::~TVerticalSliderPanel(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047be3b
// Address: 0047be3b
undefined4 __thiscall
FUN_0047be3b(TScrollBarPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,char *param_8,char *param_9,long param_10,long param_11,
            long param_12,long param_13,int param_14,int param_15)
{
  long lVar1;
  
  param_1[1]._padding_ = param_14;
  param_1[1]._padding_ = param_15;
  lVar1 = TScrollBarPanel::setup
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,(char *)0x0,
                     (char *)0x0,param_9,0,param_10,(TPanel *)0x0,param_11,Horizontal);
  if (lVar1 == 0) {
    return 0;
  }
  param_1->one_step = param_12;
  param_1->page_step = param_13;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047bebf
// Address: 0047bebf
void __thiscall
FUN_0047bebf(TScrollBarPanel *param_1,long param_2,long param_3,long param_4,long param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  TScrollBarPanel::set_rect(param_1,param_2,param_3,param_4,param_5);
  iVar1 = param_1->_padding_;
  iVar2 = param_1->_padding_;
  (param_1->up_rect).left = iVar1;
  (param_1->up_rect).right = iVar1;
  iVar2 = iVar2 + -1 + iVar1;
  iVar3 = param_1->_padding_;
  (param_1->down_rect).left = iVar2;
  (param_1->down_rect).right = iVar2;
  param_1->tab_min_x = iVar1 + 1;
  param_1->tab_x = iVar1 + 1;
  param_1->tab_max_x = (iVar2 - iVar3) + 2;
  TScrollBarPanel::calc_item_rects(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047bf26
// Address: 0047bf26
// [HELPER] s_pnl_scbr__draw: "pnl_scbr::draw"
void __fastcall FUN_0047bf26(TScrollBarPanel *param_1)
{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0x3c))(&param_1->_padding_);
  }
  iVar1 = param_1->_padding_;
  (**(code **)(iVar1 + 0x28))(0);
  puVar2 = TDrawArea::Lock((TDrawArea *)param_1->_padding_,s_pnl_scbr__draw,1);
  if (puVar2 != (uchar *)0x0) {
    TScrollBarPanel::draw_back_pic(param_1);
    TScrollBarPanel::draw_border(param_1,0,1,(tagRECT *)&param_1->_padding_);
    if (((param_1->up_rect).top != (param_1->up_rect).bottom) &&
       ((param_1->up_rect).left != (param_1->up_rect).right)) {
      if ((param_1->item_down == '\x01') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic(param_1,param_1->up_frame,iVar3,&param_1->up_rect);
      if ((param_1->item_down == '\x01') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border(param_1,1,iVar3,&param_1->up_rect);
    }
    if (((param_1->down_rect).top != (param_1->down_rect).bottom) &&
       ((param_1->down_rect).left != (param_1->down_rect).right)) {
      if ((param_1->item_down == '\x02') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_button_pic(param_1,param_1->down_frame,iVar3,&param_1->down_rect);
      if ((param_1->item_down == '\x02') && (param_1->item_is_down != 0)) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      TScrollBarPanel::draw_border(param_1,1,iVar3,&param_1->down_rect);
    }
    TScrollBarPanel::draw_button_pic(param_1,param_1->tab_frame,0,&param_1->tab_rect);
    TScrollBarPanel::draw_border(param_1,1,0,&param_1->tab_rect);
    TDrawArea::Unlock((TDrawArea *)param_1->_padding_,s_pnl_scbr__draw);
  }
  (**(code **)(iVar1 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_0047bf35
// Address: 0047bf35
TPanel * __fastcall FUN_0047bf35(TPanel *param_1)
{
  TPanel::TPanel(param_1);
  *(undefined1 *)&param_1[1].last_child_node = 0xff;
  param_1[1]._padding_ = 0;
  *(undefined2 *)&param_1[1].previousPanelValue = 0;
  *(undefined2 *)((int)&param_1[1].previousPanelValue + 2) = 0;
  *(undefined2 *)&param_1[1].previousModalPanelValue = 0;
  *(undefined2 *)((int)&param_1[1].previousModalPanelValue + 2) = 0;
  *(undefined2 *)&param_1[1].pnl_x = 0;
  *(undefined2 *)((int)&param_1[1].pnl_x + 2) = 0;
  param_1[1].pnl_y = 0;
  param_1[1].pnl_wid = 0;
  param_1[1].pnl_hgt = 0;
  param_1[1].panelNameValue = (char *)0x0;
  param_1[1].render_area = (TDrawArea *)0x0;
  param_1[1].clip_rect.left = 0;
  param_1[1].clip_rect.top = 2;
  param_1[1].clip_rect.right = 0xffffff;
  param_1[1].clip_rect.bottom = 0;
  param_1[1].need_redraw = RedrawNone;
  param_1[1].curr_child = (TPanel *)0x0;
  param_1[1].parent_panel = (TPanel *)0x0;
  *(undefined2 *)&param_1[1].left_panel = 0;
  param_1[1].top_panel = (TPanel *)0x0;
  param_1[1].right_panel = (TPanel *)0x0;
  param_1[1].bottom_panel = (TPanel *)0x0;
  *(undefined2 *)&param_1[1].node = 0;
  *(undefined2 *)((int)&param_1[1].node + 2) = 0;
  param_1[1].first_child_node = (PanelNode *)0x0;
  param_1[1].tab_prev_panel = (TPanel *)0x0;
  *(undefined1 *)&param_1[1].tab_next_panel = 0;
  param_1[1].mouse_captured = 0;
  param_1[1].active = 0;
  param_1[1].visible = 0;
  param_1[1].tab_stop = 0;
  param_1[1].have_focus = 0;
  param_1[1].overlapping_children = 0;
  *(undefined1 *)&param_1[1].handle_mouse_input = 0;
  *(undefined1 *)((int)&param_1[1].handle_mouse_input + 1) = 0;
  *(undefined1 *)((int)&param_1[1].handle_mouse_input + 2) = 0;
  *(undefined1 *)((int)&param_1[1].handle_mouse_input + 3) = 0;
  *(undefined1 *)&param_1[1].just_drawn = 0;
  *(undefined1 *)((int)&param_1[1].just_drawn + 1) = 0;
  param_1[1].clip_rgn = (void *)0x0;
  param_1[1].render_rect.left = 0;
  param_1[1].render_rect.top = 0;
  param_1->handle_mouse_input = 0;
  param_1[1].position_mode = 0xffff;
  param_1->_padding_ = (int)&TTextPanel::_vftable_;
  param_1->panel_type = '\x01';
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047c085
// Address: 0047c085
TTextPanel * __thiscall FUN_0047c085(TTextPanel *param_1,byte param_2)
{
  TTextPanel::~TTextPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047c0ae
// Address: 0047c0ae
void __fastcall FUN_0047c0ae(TTextPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055e598;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TTextPanel::_vftable_;
  uStack_4 = 0;
  TTextPanel::free_text(param_1);
  if (param_1->clip_rgn2 != (void *)0x0) {
    DeleteObject(param_1->clip_rgn2);
    param_1->clip_rgn2 = (void *)0x0;
  }
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0047c11a
// Address: 0047c11a
undefined4 __thiscall
FUN_0047c11a(TTextPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,void *param_7,long param_8,long param_9,char *param_10,undefined4 param_11,
            int param_12,uchar param_13,int param_14,uchar param_15,short param_16,
            undefined4 param_17)
{
  TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6,(long)param_7,'\0');
  param_1->fill_back = param_12;
  param_1->back_color = param_13;
  param_1->outline = param_14;
  param_1->outline_color = param_15;
  param_1->fixed_len = param_16;
  if (param_14 != 0) {
    param_1->bevel_type = 1;
  }
  (**(code **)(param_1->_padding_ + 0xe8))(param_17);
  TTextPanel::set_font(param_1,param_7,param_8,param_9);
  TTextPanel::set_alignment(param_1,AlignCenter,AlignCenter);
  TTextPanel::set_back_pic(param_1,param_10);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047c1d1
// Address: 0047c1d1
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

undefined4 __thiscall
FUN_0047c1d1(TTextPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,void *param_8,long param_9,long param_10,char *param_11,
            int param_12,uchar param_13,int param_14,uchar param_15,short param_16,int param_17)
{
  char acStack_1000 [4092];
  undefined4 uStack_4;
  
  uStack_4 = 0x47c1ea;
  TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6,param_7,'\0');
  param_1->fill_back = param_12;
  param_1->back_color = param_13;
  param_1->outline = param_14;
  param_1->outline_color = param_15;
  param_1->fixed_len = param_16;
  if (param_14 != 0) {
    param_1->bevel_type = 1;
  }
  TTextPanel::set_font(param_1,param_8,param_9,param_10);
  TTextPanel::set_alignment(param_1,AlignCenter,AlignCenter);
  TTextPanel::set_back_pic(param_1,param_11);
  TPanel::get_string((TPanel *)param_1,param_17,acStack_1000,0x1000);
  (**(code **)(param_1->_padding_ + 0xe8))(acStack_1000);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047c2e7
// Address: 0047c2e7
undefined4 __thiscall
FUN_0047c2e7(TTextPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            void *param_6,long param_7,long param_8,char *param_9,undefined4 param_10,
            undefined4 param_11,int param_12,uchar param_13,int param_14,uchar param_15,
            short param_16,undefined4 param_17,undefined4 param_18)
{
  TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,(long)param_6,param_7,'\0');
  param_1->fill_back = param_12;
  param_1->back_color = param_13;
  param_1->outline = param_14;
  param_1->outline_color = param_15;
  param_1->fixed_len = param_16;
  if (param_14 != 0) {
    param_1->bevel_type = 1;
  }
  (**(code **)(param_1->_padding_ + 0xe0))(param_17,param_18);
  TTextPanel::set_font(param_1,param_6,param_7,param_8);
  TTextPanel::set_alignment(param_1,AlignTop,AlignLeft);
  TTextPanel::set_back_pic(param_1,param_9);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047c3a6
// Address: 0047c3a6
void __thiscall
FUN_0047c3a6(TTextPanel *param_1,long param_2,long param_3,long param_4,long param_5)
{
  long lVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  TPanel::set_rect((TPanel *)param_1,param_2,param_3,param_4,param_5);
  param_1->full_width = param_1->_padding_;
  if ((param_1->auto_scbar != 0) && (param_1->scbar_panel != (TScrollBarPanel *)0x0)) {
    (**(code **)(param_1->scbar_panel->_padding_ + 0x14))(0);
    param_1->scbar_active = 0;
    if ((TPanel *)param_1->_padding_ == (TPanel *)0x0) {
      iVar4 = param_1->_padding_;
      iVar3 = param_1->_padding_;
    }
    else {
      lVar1 = TPanel::xPosition((TPanel *)param_1->_padding_);
      iVar4 = param_1->_padding_ - lVar1;
      lVar1 = TPanel::yPosition((TPanel *)param_1->_padding_);
      iVar3 = param_1->_padding_ - lVar1;
    }
    (**(code **)(param_1->scbar_panel->_padding_ + 0x1c))
              ((iVar4 + param_1->full_width) - param_1->scbar_width,iVar3,param_1->scbar_width,
               param_1->_padding_);
  }
  TTextPanel::calc_draw_info(param_1,1);
  if (param_1->second_column_pos != 0) {
    if (param_1->clip_rgn2 != (void *)0x0) {
      DeleteObject(param_1->clip_rgn2);
      param_1->clip_rgn2 = (void *)0x0;
    }
    if (param_1->_padding_ != 0) {
      iVar4 = param_1->_padding_ + -10 + param_1->second_column_pos;
      if (param_1->_padding_ < iVar4) {
        iVar4 = param_1->_padding_;
      }
      pvVar2 = (void *)CreateRectRgn(param_1->_padding_,param_1->_padding_,iVar4,param_1->_padding_)
      ;
      param_1->clip_rgn2 = pvVar2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047c4c5
// Address: 0047c4c5
void __thiscall FUN_0047c4c5(int *param_1,TPanel *param_2,int param_3)
{
  long lVar1;
  
  param_1[0x4c] = (int)param_2;
  param_1[0x4d] = param_3;
  if (param_2 != (TPanel *)0x0) {
    lVar1 = TPanel::width(param_2);
    param_1[0x5a] = lVar1;
    (**(code **)(*param_1 + 0xc))(param_1[3],param_1[4],param_1[5],param_1[6]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047c511
// Address: 0047c511
undefined4 FUN_0047c511(byte *param_1)
{
  int iVar1;
  
  if ((param_1 != (byte *)0x0) && (*param_1 != 0)) {
    iVar1 = IsDBCSLeadByte(*param_1);
    if (iVar1 != 0) {
      return 2;
    }
    if ((0xa0 < *param_1) && (*param_1 < 0xe0)) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047c55c
// Address: 0047c55c
// [HELPER] s_: ""
void __thiscall FUN_0047c55c(TTextPanel *param_1,char *param_2)
{
  int iVar1;
  int iVar2;
  char acStack_100 [256];
  
  TTextPanel::free_text(param_1);
  if (param_2 == (char *)0x0) {
    if (param_1->fixed_len != 0) {
      TTextPanel::append_line(param_1,s_,0);
      return;
    }
  }
  else {
    if (*param_2 == '\0') {
      TTextPanel::append_line(param_1,s_,0);
      return;
    }
    if ((param_1->word_wrap == 0) && (param_1->horz_align != AlignWordwrap)) {
      while( true ) {
        iVar1 = __mbschr(param_2,10);
        if (iVar1 == 0) break;
        iVar2 = (int)(short)((short)iVar1 - (short)param_2);
        strncpy(acStack_100,param_2,iVar2);
        acStack_100[iVar2] = '\0';
        TTextPanel::append_line(param_1,acStack_100,0);
        param_2 = (char *)(iVar1 + 1);
      }
      TTextPanel::append_line(param_1,param_2,0);
      return;
    }
    TTextPanel::word_wrap_append(param_1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047c63f
// Address: 0047c63f
// [HELPER] s__: "}"
// [HELPER] s_pnl_txt__word_wrap_append: "pnl_txt::word_wrap_append"
undefined4 __thiscall FUN_0047c63f(TTextPanel *param_1,uchar *param_2)
{
  uchar uVar1;
  char cVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  int iVar11;
  void *pvVar12;
  uchar *puVar13;
  uchar *puVar14;
  uchar *puVar15;
  CharType CVar16;
  CharType CVar17;
  char *pcVar18;
  int iVar19;
  int aiStack_150 [2];
  int iStack_148;
  int iStack_144;
  uint uStack_140;
  undefined4 uStack_13c;
  undefined1 auStack_138 [52];
  char cStack_104;
  char acStack_100 [256];
  
  if ((param_2 == (uchar *)0x0) || (*param_2 == '\0')) {
    return 1;
  }
  if (param_1->auto_scbar == 0) {
    iVar11 = param_1->_padding_;
  }
  else {
    iVar11 = param_1->full_width - param_1->scbar_width;
  }
  iVar11 = iVar11 + -10;
  pvVar12 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_pnl_txt__word_wrap_append);
  if (pvVar12 == (void *)0x0) {
    return 0;
  }
  uStack_13c = SelectObject(pvVar12,param_1->font);
  GetTextMetricsA(pvVar12,auStack_138);
  uStack_140 = (uint)(cStack_104 == -0x80);
LAB_0047c6e3:
  sVar7 = __mbslen(param_2);
  bVar4 = false;
  iStack_148 = 0;
  bVar5 = false;
  bVar6 = false;
  iStack_144 = 0;
  sVar3 = (short)param_2;
  if (*param_2 == '\n') {
    bVar4 = true;
    sVar8 = 0;
  }
  else {
    sVar8 = __mbsinc(param_2);
    GetTextExtentPoint32A(pvVar12,param_2,(int)(short)(sVar8 - sVar3),aiStack_150);
    puVar14 = (uchar *)0x0;
    puVar15 = param_2;
    sVar8 = 1;
    sVar9 = 1;
    if (0 < sVar7) {
      while (sVar8 = sVar9, aiStack_150[0] < iVar11) {
        if (*puVar15 == '\n') {
          sVar8 = sVar9 + -1;
          bVar4 = true;
          if ((puVar14 != (uchar *)0x0) && (*puVar14 == '\r')) {
            iStack_148 = 1;
            sVar8 = sVar9 + -2;
          }
          break;
        }
        if (*puVar15 == '\r') {
          iStack_144 = 1;
        }
        puVar13 = (uchar *)__mbsinc(puVar15);
        sVar8 = sVar9 + 1;
        sVar9 = __mbsinc(puVar13);
        GetTextExtentPoint32A(pvVar12,param_2,(int)(short)(sVar9 - sVar3),aiStack_150);
        puVar14 = puVar15;
        puVar15 = puVar13;
        sVar9 = sVar8;
        if (sVar7 < sVar8) break;
      }
    }
  }
  if (bVar4) goto LAB_0047c955;
  iVar19 = -1;
  puVar14 = param_2;
  do {
    if (iVar19 == 0) break;
    iVar19 = iVar19 + -1;
    uVar1 = *puVar14;
    puVar14 = puVar14 + 1;
  } while (uVar1 != '\0');
  GetTextExtentPoint32A(pvVar12,param_2,(int)(short)(~(ushort)iVar19 - 1),aiStack_150);
  if (iVar11 < aiStack_150[0]) {
    sVar8 = 1;
    sVar9 = 1;
    puVar14 = param_2;
    if (1 < sVar7) {
      do {
        sVar10 = __mbsinc(puVar14);
        GetTextExtentPoint32A(pvVar12,param_2,(int)(short)(sVar10 - sVar3),aiStack_150);
        if (iVar11 < aiStack_150[0]) break;
        sVar9 = sVar8 + -1;
        puVar14 = (uchar *)__mbsinc(puVar14);
        sVar8 = sVar8 + 1;
      } while (sVar8 < sVar7);
    }
joined_r0x0047c85c:
    do {
      if (sVar8 < 2) goto LAB_0047c91d;
      puVar15 = (uchar *)__mbsdec(param_2,puVar14);
      sVar8 = sVar8 + -1;
      if (uStack_140 == 0) {
        iVar19 = __ismbcspace(*puVar15);
        puVar14 = puVar15;
        if (iVar19 != 0) {
LAB_0047c915:
          bVar5 = true;
          goto LAB_0047c91d;
        }
        goto joined_r0x0047c85c;
      }
      CVar16 = TTextPanel::char_type(param_1,puVar15);
      CVar17 = TTextPanel::char_type(param_1,puVar14);
      if (((CVar16 == SingleByteChar) && (CVar17 == SingleByteChar)) &&
         (iVar19 = __ismbcspace(*puVar15), iVar19 != 0)) goto LAB_0047c915;
      if ((((((CVar16 == DoubleByteChar) && (CVar17 == DoubleByteChar)) ||
            ((CVar16 == SingleByteKanaChar && (CVar17 == SingleByteKanaChar)))) ||
           ((CVar16 == SingleByteChar && (CVar17 == DoubleByteChar)))) ||
          ((CVar16 == DoubleByteChar && (CVar17 == SingleByteChar)))) ||
         (((CVar16 == SingleByteChar && (CVar17 == SingleByteKanaChar)) ||
          ((puVar14 = puVar15, CVar16 == SingleByteKanaChar && (CVar17 == SingleByteChar))))))
      goto LAB_0047c90b;
    } while( true );
  }
LAB_0047ca2b:
  TTextPanel::append_line(param_1,(char *)param_2,0);
  SelectObject(pvVar12,uStack_13c);
  TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_pnl_txt__word_wrap_append);
  return 1;
LAB_0047c90b:
  bVar6 = true;
LAB_0047c91d:
  if ((!bVar5) && (!bVar6)) {
    bVar6 = true;
    sVar8 = sVar9;
  }
  if ((!bVar5) && (!bVar6)) goto LAB_0047ca2b;
LAB_0047c955:
  pcVar18 = acStack_100;
  for (iVar19 = 0x40; iVar19 != 0; iVar19 = iVar19 + -1) {
    pcVar18[0] = '\0';
    pcVar18[1] = '\0';
    pcVar18[2] = '\0';
    pcVar18[3] = '\0';
    pcVar18 = pcVar18 + 4;
  }
  __mbsncpy(acStack_100,param_2,(int)sVar8);
  iVar19 = iStack_148;
  if (iStack_148 != 0) {
    __mbscat(acStack_100,&s__);
  }
  if (bVar4) {
    __mbscat(acStack_100,&s__);
  }
  if (iStack_144 != 0) {
    pcVar18 = acStack_100;
    cVar2 = acStack_100[0];
    while (cVar2 != '\0') {
      if (*pcVar18 == '\r') {
        *pcVar18 = ' ';
      }
      pcVar18 = (char *)__mbsinc(pcVar18);
      cVar2 = *pcVar18;
    }
  }
  TTextPanel::append_line(param_1,acStack_100,0);
  param_2 = (uchar *)__mbsninc(param_2,(int)sVar8);
  if (iVar19 != 0) {
    param_2 = (uchar *)__mbsinc(param_2);
  }
  if (bVar4) {
    param_2 = (uchar *)__mbsinc(param_2);
  }
  goto LAB_0047c6e3;
}

// --------------------------------------------------

// Function: FUN_0047ca68
// Address: 0047ca68
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_0047ca68(TPanel *param_1,int param_2)
{
  char acStack_1000 [4092];
  undefined4 uStack_4;
  
  uStack_4 = 0x47ca7a;
  TPanel::get_string(param_1,param_2,acStack_1000,0x1000);
  (**(code **)(param_1->_padding_ + 0xe8))(acStack_1000);
  return;
}

// --------------------------------------------------

// Function: FUN_0047caaf
// Address: 0047caaf
// [HELPER] s_: ""
void __thiscall FUN_0047caaf(TTextPanel *param_1,undefined4 *param_2,short param_3)
{
  int iVar1;
  
  TTextPanel::free_text(param_1);
  if (param_3 == 0) {
    if (param_1->fixed_len != 0) {
      TTextPanel::append_line(param_1,s_,0);
      return;
    }
  }
  else if (0 < param_3) {
    iVar1 = (int)param_3;
    do {
      TTextPanel::append_line(param_1,(char *)*param_2,0);
      param_2 = param_2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047cb02
// Address: 0047cb02
void __thiscall FUN_0047cb02(TTextPanel *param_1,void *param_2,long param_3,long param_4)
{
  param_1->font_wid = param_3;
  param_1->font = param_2;
  param_1->font_hgt = param_4;
  TTextPanel::calc_draw_info(param_1,1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047cb47
// Address: 0047cb47
void __thiscall FUN_0047cb47(int *param_1,int param_2,int param_3)
{
  param_1[0x44] = param_2;
  param_1[0x45] = param_3;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047cb6e
// Address: 0047cb6e
void __thiscall FUN_0047cb6e(int *param_1,int param_2)
{
  param_1[0x46] = param_2;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047cb84
// Address: 0047cb84
void __thiscall FUN_0047cb84(int *param_1,int param_2)
{
  param_1[0x47] = param_2;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047cba4
// Address: 0047cba4
void __thiscall FUN_0047cba4(int *param_1,int param_2,int param_3)
{
  param_1[0x48] = param_2;
  param_1[0x49] = param_3;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047cbce
// Address: 0047cbce
void __thiscall FUN_0047cbce(int *param_1,int param_2,int param_3)
{
  param_1[0x4a] = param_2;
  param_1[0x4b] = param_3;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047cbee
// Address: 0047cbee
void __thiscall FUN_0047cbee(int param_1,undefined4 param_2,undefined1 param_3)
{
  *(undefined4 *)(param_1 + 0x14c) = param_2;
  *(undefined1 *)(param_1 + 0x150) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0047cc07
// Address: 0047cc07
void __thiscall FUN_0047cc07(int param_1,char *param_2)
{
  TShape *pTVar1;
  undefined4 *unaff_FS_OFFSET;
  short asStack_1c [2];
  short asStack_18 [2];
  short asStack_14 [2];
  short asStack_10 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e5bb;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = *(TShape **)(param_1 + 0x144);
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined2 *)(param_1 + 0x148) = 0;
    *(undefined2 *)(param_1 + 0x14a) = 0;
  }
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    pTVar1 = (TShape *)operator_new(0x20);
    uStack_4 = 0;
    if (pTVar1 == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape(pTVar1,param_2,-1);
    }
    uStack_4 = 0xffffffff;
    *(TShape **)(param_1 + 0x144) = pTVar1;
    TShape::shape_minmax
              (pTVar1,(long *)asStack_18,(long *)asStack_10,(long *)asStack_1c,(long *)asStack_14,0)
    ;
    *(short *)(param_1 + 0x148) = (asStack_1c[0] - asStack_18[0]) + 1;
    *(short *)(param_1 + 0x14a) = (asStack_14[0] - asStack_10[0]) + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0047ccef
// Address: 0047ccef
void __thiscall FUN_0047ccef(int *param_1,int param_2,undefined1 param_3)
{
  param_1[0x55] = param_2;
  if (param_2 != 0) {
    param_1[0x5c] = 1;
    *(undefined1 *)(param_1 + 0x56) = param_3;
    (**(code **)(*param_1 + 0x20))(1);
    return;
  }
  param_1[0x5c] = 0;
  *(undefined1 *)(param_1 + 0x56) = param_3;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047cd3a
// Address: 0047cd3a
void __thiscall
FUN_0047cd3a(TTextPanel *param_1,int param_2,uchar param_3,uchar param_4,uchar param_5,uchar param_6
            ,uchar param_7,uchar param_8)
{
  param_1->bevel_color1 = param_3;
  param_1->bevel_color2 = param_4;
  param_1->bevel_color3 = param_5;
  param_1->bevel_color4 = param_6;
  param_1->bevel_type = param_2;
  param_1->bevel_color5 = param_7;
  param_1->bevel_color6 = param_8;
  switch(param_2) {
  case 1:
  case 2:
  case 5:
    param_1->border_size = 1;
    TTextPanel::calc_draw_info(param_1,1);
    return;
  case 3:
  case 6:
    param_1->border_size = 2;
    TTextPanel::calc_draw_info(param_1,1);
    return;
  case 4:
  case 7:
    param_1->border_size = 3;
    TTextPanel::calc_draw_info(param_1,1);
    return;
  default:
    param_1->border_size = 0;
    TTextPanel::calc_draw_info(param_1,1);
    return;
  }
}

// --------------------------------------------------

// Function: FUN_0047cde3
// Address: 0047cde3
void FUN_0047cde3(void)
{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  char cVar4;
  char extraout_AH;
  int in_EAX;
  undefined4 uVar5;
  TPanel *this;
  char extraout_DL;
  int unaff_EDI;
  int in_stack_00000018;
  char *pcVar6;
  
  pcVar3 = (code *)swi(0x47);
  (*pcVar3)();
  *(char *)(in_EAX + -0x58ffb833) = *(char *)(in_EAX + -0x58ffb833) + extraout_DL;
  pcVar3 = (code *)swi(0x47);
  (*pcVar3)();
  *(char *)(in_EAX + -0x6cffb833) = *(char *)(in_EAX + -0x6cffb833) + (char)((uint)in_EAX >> 8);
  pcVar3 = (code *)swi(0x47);
  (*pcVar3)();
  *(char *)(unaff_EDI + -0x44ffb833) = *(char *)(unaff_EDI + -0x44ffb833) + extraout_AH;
  pcVar3 = (code *)swi(0x47);
  uVar5 = (*pcVar3)();
  *(char *)(in_EAX + 0x6a042444) = *(char *)(in_EAX + 0x6a042444) + (char)this;
  piVar1 = (int *)((int)&this[0x197].render_rect.right + 1);
  *piVar1 = (int)&this->_padding_ + *piVar1;
  cVar4 = (char)uVar5 + (char)((uint)this >> 8);
  pcVar6 = (char *)CONCAT31((int3)((uint)uVar5 >> 8),cVar4);
  *pcVar6 = *pcVar6 + cVar4;
  TPanel::set_active(this,in_stack_00000018);
  if ((this[1].parent_panel != (TPanel *)0x0) && (this[1].curr_child != (TPanel *)0x0)) {
    iVar2 = (this[1].curr_child)->_padding_;
    if (this->active != 0) {
      (**(code **)(iVar2 + 0x14))();
      return;
    }
    (**(code **)(iVar2 + 0x14))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047ce14
// Address: 0047ce14
void __thiscall FUN_0047ce14(TPanel *param_1,int param_2)
{
  int iVar1;
  
  TPanel::set_active(param_1,param_2);
  if ((param_1[1].parent_panel != (TPanel *)0x0) && (param_1[1].curr_child != (TPanel *)0x0)) {
    iVar1 = (param_1[1].curr_child)->_padding_;
    if (param_1->active != 0) {
      (**(code **)(iVar1 + 0x14))(param_1[1].have_focus);
      return;
    }
    (**(code **)(iVar1 + 0x14))(0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047ce61
// Address: 0047ce61
void __thiscall FUN_0047ce61(TPanel *param_1,int param_2)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  TPanel *pTVar8;
  
  iVar5 = param_1[1].pnl_hgt;
  pTVar8 = (TPanel *)(iVar5 + 2);
  param_1[1].right_panel = pTVar8;
  if (iVar5 == 0) {
    *(undefined2 *)((int)&param_1[1].previousPanelValue + 2) = 1;
  }
  else {
    iVar6 = param_1[1].render_rect.top;
    iVar7 = param_1[1].render_rect.left;
    if (iVar6 == 0) {
      iVar7 = param_1->pnl_hgt + iVar7 * -2;
    }
    else {
      iVar7 = param_1->pnl_hgt + iVar7 * -2;
      pTVar8 = (TPanel *)(iVar5 + 1 + iVar6 * 2);
    }
    *(short *)((int)&param_1[1].previousPanelValue + 2) = (short)(iVar7 / (int)pTVar8);
  }
  if (*(short *)((int)&param_1[1].previousPanelValue + 2) < 1) {
    *(undefined2 *)((int)&param_1[1].previousPanelValue + 2) = 1;
  }
  sVar2 = *(short *)&param_1[1].previousPanelValue;
  if (sVar2 <= *(short *)&param_1[1].previousModalPanelValue) {
    *(short *)&param_1[1].previousModalPanelValue = sVar2 + -1;
  }
  sVar3 = *(short *)((int)&param_1[1].previousPanelValue + 2);
  if ((int)sVar2 - (int)*(short *)&param_1[1].previousModalPanelValue < (int)sVar3) {
    *(short *)&param_1[1].previousModalPanelValue = sVar2 - sVar3;
  }
  if (*(short *)&param_1[1].previousModalPanelValue < 0) {
    *(undefined2 *)&param_1[1].previousModalPanelValue = 0;
  }
  sVar4 = *(short *)&param_1[1].previousModalPanelValue;
  sVar1 = sVar4 + -1 + sVar3;
  *(short *)((int)&param_1[1].previousModalPanelValue + 2) = sVar1;
  if (sVar1 < 0) {
    *(undefined2 *)((int)&param_1[1].previousModalPanelValue + 2) = 0;
  }
  if (sVar2 <= *(short *)((int)&param_1[1].previousModalPanelValue + 2)) {
    *(short *)((int)&param_1[1].previousModalPanelValue + 2) = sVar2 + -1;
  }
  if ((short)param_1[1].pnl_x < 0) {
    *(undefined2 *)&param_1[1].pnl_x = 0;
  }
  if (sVar2 <= (short)param_1[1].pnl_x) {
    *(short *)&param_1[1].pnl_x = sVar2 + -1;
  }
  if ((TScrollBarPanel *)param_1[1].curr_child != (TScrollBarPanel *)0x0) {
    if (param_2 != 0) {
      TScrollBarPanel::set_list_len
                ((TScrollBarPanel *)param_1[1].curr_child,((int)sVar2 - (int)sVar3) + 1,(int)sVar4);
    }
    if (param_1[1].parent_panel != (TPanel *)0x0) {
      if (*(short *)((int)&param_1[1].previousPanelValue + 2) <
          *(short *)&param_1[1].previousPanelValue) {
        if (param_1[1].have_focus == 0) {
          TPanel::set_rect(param_1,param_1->pnl_x,param_1->pnl_y,
                           param_1[1].visible - param_1[1].tab_stop,param_1->pnl_hgt);
          iVar5 = param_1->active;
          param_1[1].have_focus = 1;
          if (iVar5 != 0) {
            (**(code **)((param_1[1].curr_child)->_padding_ + 0x14))(1);
            param_1[1].top_panel = (TPanel *)param_1->pnl_wid;
            return;
          }
        }
      }
      else if (param_1[1].have_focus != 0) {
        TPanel::set_rect(param_1,param_1->pnl_x,param_1->pnl_y,param_1[1].visible,param_1->pnl_hgt);
        iVar5 = param_1->active;
        param_1[1].have_focus = 0;
        if (iVar5 != 0) {
          (**(code **)((param_1[1].curr_child)->_padding_ + 0x14))(0);
        }
      }
    }
  }
  param_1[1].top_panel = (TPanel *)param_1->pnl_wid;
  return;
}

// --------------------------------------------------

// Function: FUN_0047d0f9
// Address: 0047d0f9
undefined4 __fastcall
FUN_0047d0f9(undefined4 param_1,char param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8)
{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char in_AL;
  char cVar8;
  undefined4 uVar9;
  TTextPanel *this;
  TTextPanel *unaff_ESI;
  int unaff_EDI;
  byte *pbVar10;
  int iVar11;
  char in_AF;
  bool in_SF;
  uchar uVar12;
  
  if (in_SF) {
    TTextPanel::calc_draw_info(unaff_ESI,param_6);
    uVar9 = (**(code **)(unaff_ESI->_padding_ + 0x20))(1);
    return uVar9;
  }
  pbVar10 = (byte *)(unaff_EDI + 1);
  piVar4 = &unaff_ESI[-0x4b19f1]._padding_;
  *(char *)piVar4 = (char)*piVar4 + in_AL;
  iVar5 = *piVar4;
  iVar6 = *piVar4;
  iVar7 = *piVar4;
  *pbVar10 = *pbVar10 << 1 | (char)*pbVar10 < '\0';
  bVar2 = *pbVar10;
  *pbVar10 = *pbVar10 << 1 | (char)bVar2 < '\0';
  cVar8 = (char)unaff_ESI;
  *pbVar10 = *pbVar10 << 1 | (char)*pbVar10 < '\0';
  pbVar10 = (byte *)(unaff_EDI + 2);
  this = (TTextPanel *)
         CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11((char)((uint)param_1 >> 8) + cVar8,0xd0));
  bVar3 = *pbVar10;
  *pbVar10 = *pbVar10 << 1 | (char)bVar3 < '\0';
  iVar11 = unaff_EDI + 3;
  pcVar1 = (char *)(CONCAT31((int3)(CONCAT22((short)((uint)unaff_ESI >> 0x10),
                                             CONCAT11(((char)iVar5 < '\0') << 7 |
                                                      ((char)iVar6 == '\0') << 6 | in_AF << 4 |
                                                      ((POPCOUNT((char)iVar7) & 1U) == 0) << 2 | 2U
                                                      | (char)bVar2 < '\0',cVar8)) >> 8),
                             cVar8 << 1 | (char)bVar3 < '\0') + 0x56909090);
  *pcVar1 = *pcVar1 + param_2;
  switch(param_4) {
  case 0x21:
    uVar12 = '\x05';
    break;
  case 0x22:
    uVar12 = '\x04';
    break;
  case 0x23:
    TTextPanel::scroll(this,'\a',0,1);
    return 1;
  case 0x24:
    TTextPanel::scroll(this,'\x06',0,1);
    return 1;
  default:
    return 0;
  case 0x26:
    uVar12 = '\x03';
    goto LAB_0047d149;
  case 0x28:
    uVar12 = '\x02';
LAB_0047d149:
    TTextPanel::scroll(this,uVar12,0,1);
    piVar4 = (int *)this->_padding_;
    if (piVar4 == (int *)0x0) {
      return 1;
    }
    iVar5 = this->_padding_;
    goto joined_r0x0047d15c;
  }
  TTextPanel::scroll(this,uVar12,0,1);
  piVar4 = (int *)this->_padding_;
  if (piVar4 != (int *)0x0) {
    iVar5 = this->_padding_;
joined_r0x0047d15c:
    if (iVar5 != 0) {
      (**(code **)(*piVar4 + 0xac))(param_4,param_5,param_6,param_7,param_8,iVar11);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047d1df
// Address: 0047d1df
long __fastcall FUN_0047d1df(int param_1,int param_2,long param_3,ulong param_4,ulong param_5)
{
  uint uVar1;
  long lVar2;
  TTextPanel *this;
  int unaff_EBX;
  char *pcVar3;
  uint *unaff_EDI;
  uint *puVar4;
  TScrollBarPanel *unaff_retaddr;
  
  uVar1 = *unaff_EDI;
  *unaff_EDI = *unaff_EDI << 1 | (uint)((int)uVar1 < 0);
  this = (TTextPanel *)(param_1 << 7 | (uint)(CONCAT14((int)uVar1 < 0,param_1) >> 0x1a));
  *(char *)(param_2 + -0x27ffb82f) =
       *(char *)(param_2 + -0x27ffb82f) + (char)((uint)(param_1 << 7) >> 8);
  *unaff_EDI = *unaff_EDI << 1 | (uint)((int)*unaff_EDI < 0);
  pcVar3 = (char *)(unaff_EBX + 1);
  *unaff_EDI = *unaff_EDI << 1 | (uint)((int)*unaff_EDI < 0);
  puVar4 = (uint *)((int)unaff_EDI + 1);
  *pcVar3 = *pcVar3 + (char)((uint)pcVar3 >> 8);
  *puVar4 = *puVar4 << 1 | (uint)((int)*puVar4 < 0);
  if ((this->scbar_panel != (TScrollBarPanel *)0x0) && (unaff_retaddr == this->scbar_panel)) {
    switch(param_3) {
    case 0:
      TTextPanel::scroll(this,'\x03',0,1);
      return 1;
    case 1:
      TTextPanel::scroll(this,'\x02',0,1);
      return 1;
    case 2:
      TTextPanel::scroll(this,'\x05',0,1);
      return 1;
    case 3:
      TTextPanel::scroll(this,'\x04',0,1);
      return 1;
    case 4:
      TTextPanel::scroll(this,'\x01',(short)param_4,0);
      return 1;
    }
  }
  lVar2 = TPanel::action((TPanel *)this,(TPanel *)unaff_retaddr,param_3,param_4,param_5);
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_0047d29f
// Address: 0047d29f
// [HELPER] s_pnl_txt__draw: "pnl_txt::draw"
void __fastcall FUN_0047d29f(TTextPanel *param_1,undefined4 param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char *in_EAX;
  void *pvVar7;
  undefined4 uVar8;
  byte bVar9;
  byte bVar10;
  short sVar11;
  int unaff_EBX;
  int iVar12;
  int iVar13;
  short sVar14;
  int unaff_EDI;
  byte *pbVar15;
  byte *unaff_retaddr;
  ulong uVar16;
  ulong uVar17;
  int iStack_4;
  
  pbVar15 = (byte *)(unaff_EDI + 1);
  bVar1 = *pbVar15;
  bVar10 = (byte)((uint)param_2 >> 8);
  *pbVar15 = *pbVar15 + bVar10;
  bVar9 = (byte)param_1;
  *pbVar15 = *pbVar15 << (bVar9 & 7) | *pbVar15 >> 8 - (bVar9 & 7);
  bVar4 = ((uint)param_1 & 0x1f) == 0;
  bVar2 = *pbVar15;
  iVar12 = unaff_EBX + -1;
  *pbVar15 = *pbVar15 << (bVar9 & 7) | *pbVar15 >> 8 - (bVar9 & 7);
  bVar5 = ((uint)param_1 & 0x1f) == 0;
  bVar3 = *pbVar15;
  *unaff_retaddr = *unaff_retaddr << (bVar9 & 7) | *unaff_retaddr >> 8 - (bVar9 & 7);
  bVar6 = ((uint)param_1 & 0x1f) == 0;
  if (bVar6 && (bVar5 && (bVar4 && CARRY1(bVar1,bVar10) || !bVar4 && (bVar2 & 1) != 0) ||
               !bVar5 && (bVar3 & 1) != 0) || !bVar6 && (*unaff_retaddr & 1) != 0) {
    pbVar15 = unaff_retaddr + 1;
    in_EAX[-0x6f6f6f70] = in_EAX[-0x6f6f6f70] + (char)param_2;
    sVar14 = 0;
    param_1->_padding_ = 0;
    if (((param_1->_padding_ != 0) && (param_1->_padding_ != 0)) && (param_1->_padding_ != 0)) {
      TTextPanel::draw_background(param_1);
      iVar13 = param_1->_padding_;
      (**(code **)(iVar13 + 0x28))(0,iVar12,pbVar15);
      pvVar7 = TDrawArea::GetDc((TDrawArea *)param_1->_padding_,s_pnl_txt__draw);
      if (pvVar7 != (void *)0x0) {
        SelectClipRgn(pvVar7,param_1->_padding_);
        uVar8 = SelectObject(pvVar7,param_1->font);
        SetBkMode(pvVar7,1);
        sVar11 = param_1->top_line;
        if (sVar11 <= param_1->bot_line) {
          do {
            if (((param_1->_padding_ == 0) || (param_1->_padding_ == 0)) &&
               (param_1->_padding_ == 0)) {
              uVar17 = param_1->text_color2;
              uVar16 = param_1->text_color1;
            }
            else {
              uVar17 = param_1->highlightTextColor2;
              uVar16 = param_1->highlightTextColor1;
            }
            TTextPanel::draw_line(param_1,pvVar7,sVar14,sVar11,uVar16,uVar17);
            sVar11 = sVar11 + 1;
            sVar14 = sVar14 + 1;
          } while (sVar11 <= param_1->bot_line);
        }
        SelectObject(pvVar7,uVar8);
        SelectClipRgn(pvVar7,0);
        TDrawArea::ReleaseDc((TDrawArea *)param_1->_padding_,s_pnl_txt__draw);
        iVar13 = iStack_4;
      }
      TTextPanel::draw_border(param_1);
      (**(code **)(iVar13 + 0x2c))();
    }
    return;
  }
  *in_EAX = *in_EAX + (char)in_EAX;
  return;
}

// --------------------------------------------------

// Function: FUN_0047d3ce
// Address: 0047d3ce
// [HELPER] s_pnl_txt__draw_background2: "pnl_txt::draw_background2"
// [HELPER] s_pnl_txt__draw_background: "pnl_txt::draw_background"
void __fastcall FUN_0047d3ce(int param_1)
{
  int *piVar1;
  uchar *puVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  short sStack_8;
  int iStack_4;
  
  sVar4 = 0;
  if (*(int *)(param_1 + 0x144) == 0) {
    if (*(int *)(param_1 + 0x14c) == 0) {
      piVar1 = *(int **)(param_1 + 0x40);
      if (piVar1 != (int *)0x0) {
        if ((1 < *(int *)(param_1 + 0x170)) && (*(int *)(param_1 + 0x170) < 8)) {
          (**(code **)(*piVar1 + 0x3c))(param_1 + 0x24);
          return;
        }
        if (piVar1[0x21] == 0) {
          (**(code **)(*piVar1 + 0x34))(param_1 + 0x24);
        }
      }
    }
    else {
      puVar2 = TDrawArea::Lock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_background2,1);
      if (puVar2 != (uchar *)0x0) {
        TDrawArea::FillRect(*(TDrawArea **)(param_1 + 0x20),*(int *)(param_1 + 0xc),
                            *(int *)(param_1 + 0x10),
                            *(int *)(param_1 + 0x14) + -1 + *(int *)(param_1 + 0xc),
                            *(int *)(param_1 + 0x18) + -1 + *(int *)(param_1 + 0x10),
                            *(uchar *)(param_1 + 0x150));
        TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_background2);
        return;
      }
    }
  }
  else {
    puVar2 = TDrawArea::Lock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_background,1);
    if (puVar2 != (uchar *)0x0) {
      iVar3 = (int)*(short *)(param_1 + 0x148);
      iVar5 = *(int *)(param_1 + 0x14);
      if (iVar3 < iVar5) {
        sStack_8 = (short)(iVar5 / iVar3);
        if (sStack_8 * iVar3 < iVar5) {
          sStack_8 = sStack_8 + 1;
        }
      }
      else {
        sStack_8 = 1;
      }
      iVar3 = (int)*(short *)(param_1 + 0x14a);
      iVar5 = *(int *)(param_1 + 0x18);
      if ((iVar5 <= iVar3) && (sVar4 = (short)(iVar5 / iVar3), sVar4 * iVar3 < iVar5)) {
        sVar4 = sVar4 + 1;
      }
      if (0 < sVar4) {
        iStack_4 = (int)sVar4;
        iVar5 = 0;
        do {
          if (0 < sStack_8) {
            iVar6 = 0;
            iVar3 = (int)sStack_8;
            do {
              TShape::shape_draw(*(TShape **)(param_1 + 0x144),*(TDrawArea **)(param_1 + 0x20),
                                 iVar6 * *(short *)(param_1 + 0x148) + *(int *)(param_1 + 0xc),
                                 iVar5 * *(short *)(param_1 + 0x14a) + *(int *)(param_1 + 0x10),0,
                                 '\0',(uchar *)0x0);
              iVar6 = iVar6 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          iVar5 = iVar5 + 1;
          iStack_4 = iStack_4 + -1;
        } while (iStack_4 != 0);
      }
      TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_background);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047d56a
// Address: 0047d56a
// [HELPER] s_pnl_txt__draw_border: "pnl_txt::draw_border"
void __fastcall FUN_0047d56a(int param_1)
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
  
  if (*(int *)(param_1 + 0x170) == 0) {
    return;
  }
  puVar7 = TDrawArea::Lock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_border,1);
  if (puVar7 == (uchar *)0x0) goto switchD_0047d5a8_default;
  switch(*(undefined4 *)(param_1 + 0x170)) {
  case 1:
    TDrawArea::DrawRect(*(TDrawArea **)(param_1 + 0x20),*(int *)(param_1 + 0xc),
                        *(int *)(param_1 + 0x10),
                        *(int *)(param_1 + 0x14) + -1 + *(int *)(param_1 + 0xc),
                        *(int *)(param_1 + 0x18) + -1 + *(int *)(param_1 + 0x10),
                        *(uchar *)(param_1 + 0x158));
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_border);
    return;
  case 2:
    uVar1 = *(uchar *)(param_1 + 0x174);
    iVar8 = *(int *)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar2 = *(uchar *)(param_1 + 0x179);
    goto LAB_0047d667;
  case 3:
    uVar1 = *(uchar *)(param_1 + 0x174);
    iVar8 = *(int *)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar2 = *(uchar *)(param_1 + 0x175);
    uVar3 = *(uchar *)(param_1 + 0x178);
    uVar4 = *(uchar *)(param_1 + 0x179);
    goto LAB_0047d6b2;
  case 4:
    uVar1 = *(uchar *)(param_1 + 0x174);
    iVar8 = *(int *)(param_1 + 0x10);
    uVar2 = *(uchar *)(param_1 + 0x175);
    uVar3 = *(uchar *)(param_1 + 0x176);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar4 = *(uchar *)(param_1 + 0x177);
    uVar5 = *(uchar *)(param_1 + 0x178);
    uVar6 = *(uchar *)(param_1 + 0x179);
    break;
  case 5:
    uVar1 = *(uchar *)(param_1 + 0x179);
    iVar8 = *(int *)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar2 = *(uchar *)(param_1 + 0x174);
LAB_0047d667:
    TDrawArea::DrawBevel
              (*(TDrawArea **)(param_1 + 0x20),iVar9,iVar8,*(int *)(param_1 + 0x14) + -1 + iVar9,
               *(int *)(param_1 + 0x18) + -1 + iVar8,uVar2,uVar1);
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_border);
    return;
  case 6:
    uVar1 = *(uchar *)(param_1 + 0x179);
    iVar8 = *(int *)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar2 = *(uchar *)(param_1 + 0x178);
    uVar3 = *(uchar *)(param_1 + 0x175);
    uVar4 = *(uchar *)(param_1 + 0x174);
LAB_0047d6b2:
    TDrawArea::DrawBevel2
              (*(TDrawArea **)(param_1 + 0x20),iVar9,iVar8,*(int *)(param_1 + 0x14) + -1 + iVar9,
               *(int *)(param_1 + 0x18) + -1 + iVar8,uVar4,uVar3,uVar2,uVar1);
    TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_border);
    return;
  case 7:
    uVar1 = *(uchar *)(param_1 + 0x179);
    iVar8 = *(int *)(param_1 + 0x10);
    uVar2 = *(uchar *)(param_1 + 0x178);
    uVar3 = *(uchar *)(param_1 + 0x177);
    iVar9 = *(int *)(param_1 + 0xc);
    uVar4 = *(uchar *)(param_1 + 0x176);
    uVar5 = *(uchar *)(param_1 + 0x175);
    uVar6 = *(uchar *)(param_1 + 0x174);
    break;
  default:
    goto switchD_0047d5a8_default;
  }
  TDrawArea::DrawBevel3
            (*(TDrawArea **)(param_1 + 0x20),iVar9,iVar8,*(int *)(param_1 + 0x14) + -1 + iVar9,
             *(int *)(param_1 + 0x18) + -1 + iVar8,uVar6,uVar5,uVar4,uVar3,uVar2,uVar1);
switchD_0047d5a8_default:
  TDrawArea::Unlock(*(TDrawArea **)(param_1 + 0x20),s_pnl_txt__draw_border);
  return;
}

// --------------------------------------------------

// Function: FUN_0047d735
// Address: 0047d735
void __fastcall
FUN_0047d735(TTextPanel *param_1,undefined4 param_2,void *param_3,short param_4,short param_5,
            undefined4 param_6,undefined4 param_7)
{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  Style SVar4;
  undefined4 in_EAX;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  byte bVar9;
  undefined4 unaff_EBX;
  int unaff_ESI;
  char *pcVar10;
  short sStack_20;
  short sStack_18;
  tagRECT tStack_10;
  
  bVar9 = (char)param_2 + (char)((uint)unaff_EBX >> 8);
  puVar5 = (undefined1 *)
           CONCAT22((short)((uint)in_EAX >> 0x10),
                    (ushort)(byte)((char)in_EAX + (char)((uint)in_EAX >> 8) * 'G'));
  *puVar5 = *puVar5;
  pcVar6 = (char *)(unaff_ESI + 0x47 + CONCAT31((int3)((uint)param_2 >> 8),bVar9) * 8);
  *pcVar6 = *pcVar6 + bVar9;
  pbVar1 = (byte *)((int)&param_1[-0x17826e]._padding_ + 2);
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar9;
  pcVar6 = (char *)(CONCAT31((int3)((uint)puVar5 >> 8),-CARRY1(bVar2,bVar9)) + -0x6f6f6f70);
  *pcVar6 = *pcVar6 + bVar9;
  sStack_20 = 0;
  sStack_18 = 0;
  pcVar6 = TTextPanel::get_text(param_1,(int)param_5);
  pcVar7 = TTextPanel::get_text2(param_1,(int)param_5);
  if (pcVar6 == (char *)0x0) {
    if (pcVar7 == (char *)0x0) {
      return;
    }
  }
  else {
    iVar8 = -1;
    pcVar10 = pcVar6;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar3 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar3 != '\0');
    sStack_20 = ~(ushort)iVar8 - 1;
  }
  if (pcVar7 != (char *)0x0) {
    iVar8 = -1;
    pcVar10 = pcVar7;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar3 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar3 != '\0');
    sStack_18 = ~(ushort)iVar8 - 1;
  }
  TTextPanel::calc_line_pos(param_1,param_3,param_4,param_5,&tStack_10,(long *)0x0);
  _param_5 = tStack_10.left;
  if ((param_1->horz_align != AlignCenter) && (param_1->horz_align != AlignWordwrap)) {
    _param_5 = tStack_10.left + 5;
  }
  iVar8 = param_1->second_column_pos + _param_5;
  if (param_1->clip_rgn2 != (void *)0x0) {
    SelectClipRgn(param_3,param_1->clip_rgn2);
  }
  SVar4 = param_1->text_style;
  if (SVar4 == NormalStyle) {
    SetTextColor(param_3,param_6);
  }
  else if (SVar4 == BeveledStyle) {
    SetTextColor(param_3,param_6);
    if (pcVar6 != (char *)0x0) {
      TextOutA(param_3,_param_5 + -1,tStack_10.top + 1,pcVar6,(int)sStack_20);
    }
    SetTextColor(param_3,param_7);
  }
  else {
    if (SVar4 != ChiseledStyle) goto LAB_0047d8dd;
    SetTextColor(param_3,param_7);
    if (pcVar6 != (char *)0x0) {
      TextOutA(param_3,_param_5 + -1,tStack_10.top + 1,pcVar6,(int)sStack_20);
    }
    SetTextColor(param_3,param_6);
  }
  if (pcVar6 != (char *)0x0) {
    TextOutA(param_3,_param_5,tStack_10.top,pcVar6,(int)sStack_20);
  }
LAB_0047d8dd:
  if (pcVar7 != (char *)0x0) {
    if (param_1->clip_rgn2 != (void *)0x0) {
      SelectClipRgn(param_3,param_1->_padding_);
    }
    SVar4 = param_1->text_style;
    if (SVar4 == NormalStyle) {
      SetTextColor(param_3,param_6);
      TextOutA(param_3,iVar8,tStack_10.top,pcVar7,(int)sStack_18);
    }
    else {
      if (SVar4 == BeveledStyle) {
        SetTextColor(param_3,param_6);
        TextOutA(param_3,iVar8 + -1,tStack_10.top + 1,pcVar7,(int)sStack_18);
        SetTextColor(param_3,param_7);
        TextOutA(param_3,iVar8,tStack_10.top,pcVar7,(int)sStack_18);
        return;
      }
      if (SVar4 == ChiseledStyle) {
        SetTextColor(param_3,param_7);
        TextOutA(param_3,iVar8 + -1,tStack_10.top + 1,pcVar7,(int)sStack_18);
        SetTextColor(param_3,param_6);
        TextOutA(param_3,iVar8,tStack_10.top,pcVar7,(int)sStack_18);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047d9da
// Address: 0047d9da
void __thiscall
FUN_0047d9da(TTextPanel *param_1,undefined4 param_2,short param_3,short param_4,int *param_5,
            int *param_6)
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
  int iStack_10c;
  int aiStack_108 [2];
  char acStack_100 [256];
  
  pcVar6 = TTextPanel::get_text(param_1,(int)param_4);
  if (pcVar6 == (char *)0x0) {
    iStack_10c = 0;
    aiStack_108[0] = 0;
  }
  else {
    if (param_1->cur_col == 0) {
      iStack_10c = 0;
    }
    else {
      sVar5 = __mbslen(pcVar6);
      sVar2 = param_1->cur_col;
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
        pcVar10 = acStack_100;
        for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
          pcVar10[0] = '\0';
          pcVar10[1] = '\0';
          pcVar10[2] = '\0';
          pcVar10[3] = '\0';
          pcVar10 = pcVar10 + 4;
        }
        __mbsncpy(acStack_100,pcVar6,(int)sVar2);
        iVar8 = -1;
        pcVar10 = acStack_100;
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        uVar4 = (ushort)iVar8;
      }
      GetTextExtentPoint32A(param_2,pcVar6,(int)(short)(~uVar4 - 1),aiStack_108);
      iStack_10c = aiStack_108[0];
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
    GetTextExtentPoint32A(param_2,pcVar6,(int)(short)(~(ushort)iVar8 - 1),aiStack_108);
  }
  AVar3 = param_1->horz_align;
  if ((AVar3 != AlignCenter) && (AVar3 != AlignWordwrap)) {
    iStack_10c = iStack_10c + 5;
  }
  if (AVar3 == AlignLeft) {
    iVar8 = param_1->_padding_;
    iVar7 = param_1->border_size;
LAB_0047db35:
    iVar8 = iVar8 + iVar7;
  }
  else if (AVar3 == AlignRight) {
    iVar8 = (((param_1->_padding_ + param_1->_padding_) - param_1->border_size) - aiStack_108[0]) +
            -7;
  }
  else {
    if (AVar3 != AlignHorizontalScroll) {
      iVar8 = param_1->_padding_ - aiStack_108[0] / 2;
      iVar7 = param_1->_padding_ / 2;
      goto LAB_0047db35;
    }
    iVar8 = param_1->_padding_ + param_1->border_size;
    if (param_1->_padding_ <= iStack_10c + 1) {
      iVar8 = iVar8 + -2 + (param_1->_padding_ - iStack_10c);
    }
  }
  iVar7 = param_1->spacer_size;
  if (iVar7 == 0) {
    iVar9 = param_1->text_hgt;
  }
  else {
    iVar9 = param_1->text_hgt + -1 + iVar7 * 2;
  }
  if (param_1->vert_align == AlignTop) {
    iVar9 = param_3 * iVar9 + param_1->_padding_ + param_1->border_size;
  }
  else {
    if (param_1->vert_align == AlignBottom) {
      iVar9 = ((((param_1->_padding_ - ((int)param_1->num_lines - (int)param_3) * iVar9) +
                param_1->_padding_) - param_1->border_size) - iVar7) + -1;
      goto LAB_0047dbcf;
    }
    iVar9 = (param_3 * iVar9 - (param_1->num_lines * iVar9) / 2) + param_1->_padding_;
    iVar7 = param_1->_padding_ / 2;
  }
  iVar9 = iVar9 + iVar7;
LAB_0047dbcf:
  *param_5 = iVar8;
  param_5[1] = iVar9;
  param_5[2] = aiStack_108[0] + -1 + iVar8;
  param_5[3] = iVar9 + param_1->text_hgt;
  if (param_6 != (int *)0x0) {
    *param_6 = iStack_10c;
  }
  return;
}

// --------------------------------------------------


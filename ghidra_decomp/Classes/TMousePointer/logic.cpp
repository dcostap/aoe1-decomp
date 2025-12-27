// Class: TMousePointer
// Function: TMousePointer
// Address: 0045ae50
// [HELPER] s_C__msdev_work_age1_x1_Mouseptr_c: "C:\msdev\work\age1_x1\Mouseptr.cpp"
/* public: __thiscall TMousePointer::TMousePointer(int) */

TMousePointer * __thiscall TMousePointer::TMousePointer(TMousePointer *this,int param_1)
{
  tagRECT *ptVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  int iVar5;
  TDrawArea **ppTVar6;
  
  ptVar1 = &this->save_rect;
  (this->save_rect).top = 0;
  (this->save_rect).right = 0;
  ptVar1->left = 0;
  (this->save_rect).bottom = 0;
  lVar2 = ptVar1->left;
  this->custom_draw = 0;
  this->render_area = (TDrawArea *)0x0;
  (this->mouse_rect).left = lVar2;
  lVar2 = (this->save_rect).top;
  this->save_area = (TDrawArea *)0x0;
  this->primary_area = (TDrawArea *)0x0;
  (this->mouse_rect).top = lVar2;
  lVar2 = (this->save_rect).right;
  this->Cursor_Shape = (TShape *)0x0;
  this->Max_CX = 0;
  lVar3 = (this->save_rect).bottom;
  (this->mouse_rect).right = lVar2;
  this->Max_CY = 0;
  this->cWidth = 0;
  (this->mouse_rect).bottom = lVar3;
  this->cHeight = 0;
  lVar2 = ptVar1->left;
  this->gWidth = 0;
  (this->cursor_rect).left = lVar2;
  this->gHeight = 0;
  lVar2 = (this->save_rect).top;
  this->mouse_x = 0;
  (this->cursor_rect).top = lVar2;
  this->mouse_y = 0;
  lVar2 = (this->save_rect).right;
  this->facet = 0;
  (this->cursor_rect).right = lVar2;
  this->game_facet = 0;
  lVar2 = (this->save_rect).bottom;
  this->next_facet = 0;
  (this->cursor_rect).bottom = lVar2;
  this->last_facet = 0;
  lVar2 = ptVar1->left;
  this->d_top = 0;
  (this->new_save_rect).left = lVar2;
  this->d_left = 0;
  lVar2 = (this->save_rect).top;
  this->d_bottom = 0;
  (this->new_save_rect).top = lVar2;
  this->d_right = 0;
  lVar2 = (this->save_rect).right;
  this->g_top = 0;
  (this->new_save_rect).right = lVar2;
  this->g_left = 0;
  lVar2 = (this->save_rect).bottom;
  this->g_bottom = 0;
  (this->new_save_rect).bottom = lVar2;
  this->g_right = 0;
  (this->restore_rect).left = 0;
  lVar2 = (this->save_rect).top;
  this->active = 0;
  this->drawn = 0;
  (this->restore_rect).top = lVar2;
  lVar2 = (this->save_rect).right;
  lVar3 = (this->save_rect).bottom;
  this->Shutdown = 0;
  (this->restore_rect).right = lVar2;
  this->Setup = 0;
  (this->restore_rect).bottom = lVar3;
  this->save_x = -0x7fff;
  this->save_y = -0x7fff;
  this->Mouse_Mode = param_1;
  this->restoreSurface = (IDirectDrawSurface *)0x0;
  this->renderSurface = (IDirectDrawSurface *)0x0;
  this->GameMode = 0;
  this->GameEnabled = 0;
  this->MouseOnScreen = 0;
  this->Num_Cursors = 0;
  this->Max_Cursors = 0;
  this->cursor_file_id = -1;
  this->cursor_file[0] = '\0';
  ppTVar6 = this->cursors;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppTVar6 = (TDrawArea *)0x0;
    ppTVar6 = ppTVar6 + 1;
  }
  uVar4 = debug_timeGetTime(s_C__msdev_work_age1_x1_Mouseptr_c,100);
  this->LastDrawTime = uVar4 - 0x24;
  this->save_area_valid = 0;
  this->LastddError = 0;
  return this;
}

// --------------------------------------------------

// Function: ~TMousePointer
// Address: 0045b000
/* public: __thiscall TMousePointer::~TMousePointer(void) */

void __thiscall TMousePointer::~TMousePointer(TMousePointer *this)
{
  TShape *this_00;
  
  this_00 = this->Cursor_Shape;
  if (this_00 != (TShape *)0x0) {
    TShape::~TShape(this_00);
    operator_delete(this_00);
    this->Cursor_Shape = (TShape *)0x0;
  }
  delete_surfaces(this);
  MouseSystem = (TMousePointer *)0x0;
  return;
}

// --------------------------------------------------

// Function: Shutdown_Mouse
// Address: 0045b040
/* public: int __thiscall TMousePointer::Shutdown_Mouse(void) */

int __thiscall TMousePointer::Shutdown_Mouse(TMousePointer *this)
{
  if (this->Shutdown != 0) {
    return 0;
  }
  if (this->custom_draw == 0) {
    return 1;
  }
  if (this->Setup == 0) {
    return 0;
  }
  reset(this);
  this->render_area = (TDrawArea *)0x0;
  this->restoreSurface = (IDirectDrawSurface *)0x0;
  this->renderSurface = (IDirectDrawSurface *)0x0;
  this->PrimarySurface = (IDirectDrawSurface *)0x0;
  this->primary_area = (TDrawArea *)0x0;
  this->active = 0;
  this->Shutdown = 1;
  return 1;
}

// --------------------------------------------------

// Function: Restore_Mouse
// Address: 0045b0a0
/* public: int __thiscall TMousePointer::Restore_Mouse(class TDrawArea *) */

int __thiscall TMousePointer::Restore_Mouse(TMousePointer *this,TDrawArea *param_1)
{
  int iVar1;
  
  if (this->Shutdown == 0) {
    return 0;
  }
  if (this->custom_draw != 0) {
    if (this->Setup == 0) {
      return 0;
    }
    this->render_area = param_1;
    this->renderSurface = param_1->DrawSurface;
    this->PrimarySurface = param_1->DrawSystem->PrimarySurface;
    this->primary_area = param_1->DrawSystem->PrimaryArea;
    iVar1 = LoadCursors(this,(char *)0x0,-1,1);
    if (iVar1 == 0) {
      return 0;
    }
    this->Shutdown = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: setup
// Address: 0045b120
// [HELPER] s__s_slp: "%s.slp"
/* public: int __thiscall TMousePointer::setup(int,class TDrawArea *,char *,int,int) */

int __thiscall
TMousePointer::setup
          (TMousePointer *this,int param_1,TDrawArea *param_2,char *param_3,int param_4,int param_5)
{
  int iVar1;
  TShape *this_00;
  long lVar2;
  undefined4 *unaff_FS_OFFSET;
  char file_name [260];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  local_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dc0e;
  *unaff_FS_OFFSET = &local_c;
  MouseSystem = this;
  this->custom_draw = param_1;
  this->render_area = param_2;
  if (param_1 == 0) {
    iVar1 = 1;
  }
  else {
    if (param_2->DrawSystem->DrawType != '\x01') {
      this->renderSurface = param_2->DrawSurface;
      this->PrimarySurface = param_2->DrawSystem->PrimarySurface;
      this->primary_area = param_2->DrawSystem->PrimaryArea;
      SetCursor(0);
      sprintf(file_name + 4,s__s_slp,param_3);
      file_name._0_4_ = operator_new(0x20);
      uStack_4 = 0;
      if ((TShape *)file_name._0_4_ == (TShape *)0x0) {
        this_00 = (TShape *)0x0;
      }
      else {
        this_00 = (TShape *)TShape::TShape((TShape *)file_name._0_4_,file_name + 4,param_4);
      }
      uStack_4 = 0xffffffff;
      this->Cursor_Shape = this_00;
      if (this_00 != (TShape *)0x0) {
        iVar1 = TShape::is_loaded(this_00);
        if ((iVar1 != 0) && (this->Cursor_Shape->FShape != (SLhape_File_Header *)0x0)) {
          this->Max_Cursors = param_5;
          if ((0 < param_5) && (param_5 < 0x11)) {
            lVar2 = TShape::shape_count(this->Cursor_Shape);
            this->Num_Cursors = lVar2;
            if (lVar2 <= this->Max_Cursors) {
              iVar1 = LoadCursors(this,param_3,param_4,0);
              if (iVar1 != 0) {
                set_facet(this,0);
                set_game_facet(this,0);
                this->Setup = 1;
                iVar1 = 1;
                goto LAB_0045b267;
              }
            }
          }
        }
      }
    }
    iVar1 = 0;
  }
LAB_0045b267:
  *unaff_FS_OFFSET = local_c;
  return iVar1;
}

// --------------------------------------------------

// Function: set_game_mode
// Address: 0045b290
/* public: void __thiscall TMousePointer::set_game_mode(int) */

void __thiscall TMousePointer::set_game_mode(TMousePointer *this,int param_1)
{
  this->GameMode = param_1;
  return;
}

// --------------------------------------------------

// Function: set_game_enable
// Address: 0045b2a0
/* public: void __thiscall TMousePointer::set_game_enable(int) */

void __thiscall TMousePointer::set_game_enable(TMousePointer *this,int param_1)
{
  this->GameEnabled = param_1;
  return;
}

// --------------------------------------------------

// Function: get_game_enable
// Address: 0045b2b0
/* public: int __thiscall TMousePointer::get_game_enable(void) */

int __thiscall TMousePointer::get_game_enable(TMousePointer *this)
{
  return this->GameEnabled;
}

// --------------------------------------------------

// Function: in_game_mode
// Address: 0045b2c0
/* public: int __thiscall TMousePointer::in_game_mode(void) */

int __thiscall TMousePointer::in_game_mode(TMousePointer *this)
{
  if ((this->GameMode != 0) && (this->GameEnabled != 0)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: set_game_window
// Address: 0045b2e0
/* public: void __thiscall TMousePointer::set_game_window(int,int,int,int) */

void __thiscall
TMousePointer::set_game_window(TMousePointer *this,int param_1,int param_2,int param_3,int param_4)
{
  (this->game_window).left = param_1;
  (this->game_window).top = param_2;
  (this->game_window).right = param_3;
  (this->game_window).bottom = param_4;
  return;
}

// --------------------------------------------------

// Function: LoadCursors
// Address: 0045b310
// [HELPER] s__s_slp: "%s.slp"
// [HELPER] s_mouseptr__LoadCursors: "mouseptr::LoadCursors"
/* WARNING: Variable defined which should be unmapped: LoadOk */
/* public: int __thiscall TMousePointer::LoadCursors(char *,int,int) */

int __thiscall TMousePointer::LoadCursors(TMousePointer *this,char *param_1,int param_2,int param_3)
{
  Shape_Info *pSVar1;
  TShape *pTVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  uchar *puVar6;
  int iVar7;
  TDrawArea **ppTVar8;
  undefined4 *unaff_FS_OFFSET;
  int LoadOk;
  int local_10;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dc2b;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  pTVar2 = this->Cursor_Shape;
  local_10 = 1;
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
  }
  if (param_3 == 0) {
    this->cursor_file_id = param_2;
    sprintf(this->cursor_file,s__s_slp,param_1);
  }
  pTVar2 = (TShape *)operator_new(0x20);
  local_4 = 0;
  if (pTVar2 == (TShape *)0x0) {
    pTVar2 = (TShape *)0x0;
  }
  else {
    pTVar2 = (TShape *)TShape::TShape(pTVar2,this->cursor_file,this->cursor_file_id);
  }
  local_4 = 0xffffffff;
  this->Cursor_Shape = pTVar2;
  if (((pTVar2 != (TShape *)0x0) && (iVar3 = TShape::is_loaded(pTVar2), iVar3 != 0)) &&
     (this->Cursor_Shape->FShape != (SLhape_File_Header *)0x0)) {
    lVar4 = TShape::shape_count(this->Cursor_Shape);
    this->Num_Cursors = lVar4;
    this->Max_CX = 0;
    this->Max_CY = 0;
    if (0 < lVar4) {
      iVar3 = 0;
      do {
        pSVar1 = this->Cursor_Shape->shape_info;
        iVar7 = *(int *)((int)&pSVar1->Width + iVar3);
        if (this->Max_CX < iVar7) {
          this->Max_CX = iVar7;
        }
        iVar7 = *(int *)((int)&pSVar1->Height + iVar3);
        if (this->Max_CY < iVar7) {
          this->Max_CY = iVar7;
        }
        iVar3 = iVar3 + 0x20;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    if ((this->Max_CX != 0) && (this->Max_CY != 0)) {
      this->Max_CX = 0x40;
      this->Max_CY = 0x30;
      if ((this->save_area != (TDrawArea *)0x0) || (iVar3 = create_surfaces(this), iVar3 != 0)) {
        set_facet(this,this->facet);
        set_game_facet(this,this->game_facet);
        if (this->Mouse_Mode != 0) goto LAB_0045b546;
        iVar3 = this->Num_Cursors;
        if (iVar3 <= this->Max_Cursors) {
          iVar7 = 0;
          if (0 < iVar3) {
            plVar5 = &this->Cursor_Shape->shape_info->Height;
            do {
              if ((this->Max_CX < plVar5[-1]) || (this->Max_CY < *plVar5)) goto LAB_0045b544;
              iVar7 = iVar7 + 1;
              plVar5 = plVar5 + 8;
            } while (iVar7 < iVar3);
          }
          iVar3 = 0;
          if (0 < this->Max_Cursors) {
            iVar7 = 0;
            ppTVar8 = this->cursors;
            do {
              TDrawArea::Clear(*ppTVar8,(tagRECT *)0x0,0);
              TDrawArea::SetTrans(*ppTVar8,1,'\0');
              if (iVar3 < this->Num_Cursors) {
                puVar6 = TDrawArea::Lock(*ppTVar8,s_mouseptr__LoadCursors,1);
                if (puVar6 == (uchar *)0x0) {
                  local_10 = 0;
                }
                else {
                  TDrawArea::FillRect(*ppTVar8,0,0,this->Max_CX,this->Max_CY,'\0');
                  pSVar1 = this->Cursor_Shape->shape_info;
                  TShape::shape_draw(this->Cursor_Shape,*ppTVar8,
                                     *(long *)((int)&pSVar1->Hotspot_X + iVar7),
                                     *(long *)((int)&pSVar1->Hotspot_Y + iVar7),iVar3,'\0',
                                     (uchar *)0x0);
                  TDrawArea::Unlock(*ppTVar8,s_mouseptr__LoadCursors);
                }
              }
              iVar3 = iVar3 + 1;
              ppTVar8 = ppTVar8 + 1;
              iVar7 = iVar7 + 0x20;
            } while (iVar3 < this->Max_Cursors);
          }
          goto LAB_0045b546;
        }
      }
    }
  }
LAB_0045b544:
  local_10 = 0;
LAB_0045b546:
  *unaff_FS_OFFSET = local_c;
  return local_10;
}

// --------------------------------------------------

// Function: delete_surfaces
// Address: 0045b560
/* public: void __thiscall TMousePointer::delete_surfaces(void) */

void __thiscall TMousePointer::delete_surfaces(TMousePointer *this)
{
  TDrawArea *pTVar1;
  int iVar2;
  TDrawArea **ppTVar3;
  
  iVar2 = 0;
  if (this->custom_draw != 0) {
    pTVar1 = this->save_area;
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar1);
      operator_delete(pTVar1);
      this->save_area = (TDrawArea *)0x0;
    }
    if (0 < this->Max_Cursors) {
      ppTVar3 = this->cursors;
      do {
        pTVar1 = *ppTVar3;
        if (pTVar1 != (TDrawArea *)0x0) {
          TDrawArea::~TDrawArea(pTVar1);
          operator_delete(pTVar1);
          *ppTVar3 = (TDrawArea *)0x0;
        }
        iVar2 = iVar2 + 1;
        ppTVar3 = ppTVar3 + 1;
      } while (iVar2 < this->Max_Cursors);
    }
    this->Num_Cursors = 0;
    reset(this);
  }
  return;
}

// --------------------------------------------------

// Function: create_surfaces
// Address: 0045b5d0
// [HELPER] s_Mouse_Cursor___d: "Mouse Cursor #%d"
// [HELPER] s_Mouse_Save_area: "Mouse Save area"
/* public: int __thiscall TMousePointer::create_surfaces(void) */

int __thiscall TMousePointer::create_surfaces(TMousePointer *this)
{
  TDrawArea *pTVar1;
  int iVar2;
  TDrawArea **ppTVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  char NameBuf [32];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055dc56;
  *unaff_FS_OFFSET = &local_c;
  iVar4 = 0;
  if (this->custom_draw == 0) {
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
  if (((this->save_area == (TDrawArea *)0x0) && (0 < this->Max_CX)) && (0 < this->Max_CY)) {
    NameBuf._0_4_ = operator_new(0x100);
    local_4 = 0;
    if ((TDrawArea *)NameBuf._0_4_ == (TDrawArea *)0x0) {
      pTVar1 = (TDrawArea *)0x0;
    }
    else {
      pTVar1 = (TDrawArea *)TDrawArea::TDrawArea((TDrawArea *)NameBuf._0_4_,s_Mouse_Save_area,0);
    }
    local_4 = 0xffffffff;
    this->save_area = pTVar1;
    if (pTVar1 == (TDrawArea *)0x0) {
      *unaff_FS_OFFSET = local_c;
      return 0;
    }
    iVar2 = TDrawArea::Init(pTVar1,this->render_area->DrawSystem,this->Max_CX,this->Max_CY,0,0);
    if (iVar2 == 0) {
      *unaff_FS_OFFSET = local_c;
      return 0;
    }
  }
  if ((this->Mouse_Mode == 0) && (0 < this->Max_Cursors)) {
    ppTVar3 = this->cursors;
    do {
      if (*ppTVar3 == (TDrawArea *)0x0) {
        sprintf(NameBuf + 4,s_Mouse_Cursor___d,iVar4);
        NameBuf._0_4_ = operator_new(0x100);
        local_4 = 1;
        if ((TDrawArea *)NameBuf._0_4_ == (TDrawArea *)0x0) {
          pTVar1 = (TDrawArea *)0x0;
        }
        else {
          pTVar1 = (TDrawArea *)TDrawArea::TDrawArea((TDrawArea *)NameBuf._0_4_,NameBuf + 4,0);
        }
        local_4 = 0xffffffff;
        *ppTVar3 = pTVar1;
        if (pTVar1 == (TDrawArea *)0x0) {
LAB_0045b745:
          *unaff_FS_OFFSET = local_c;
          return 0;
        }
        iVar2 = TDrawArea::Init(pTVar1,this->render_area->DrawSystem,this->Max_CX,this->Max_CY,0,0);
        if (iVar2 == 0) goto LAB_0045b745;
      }
      iVar4 = iVar4 + 1;
      ppTVar3 = ppTVar3 + 1;
    } while (iVar4 < this->Max_Cursors);
  }
  *unaff_FS_OFFSET = local_c;
  return 1;
}

// --------------------------------------------------

// Function: update_mouse_position
// Address: 0045b760
/* WARNING: Variable defined which should be unmapped: point */
/* public: int __thiscall TMousePointer::update_mouse_position(void) */

int __thiscall TMousePointer::update_mouse_position(TMousePointer *this)
{
  int iVar1;
  long lVar2;
  long lVar3;
  TDrawArea *pTVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  tagPOINT point;
  int iStack_4;
  
  if (this->custom_draw == 0) {
    return 0;
  }
  GetCursorPos(&point.y);
  if (this->render_area->DrawSystem->ScreenMode == '\x01') {
    ScreenToClient(this->render_area->Wnd,&point.y);
    if (0x8000 < point.y) {
      point.y = point.y + -0x10000;
    }
    if (0x8000 < iStack_4) {
      iStack_4 = iStack_4 + -0x10000;
    }
  }
  this->mouse_x = point.y;
  this->mouse_y = iStack_4;
  if (((((this->GameMode == 0) || (this->GameEnabled == 0)) ||
       (this->mouse_x < (this->game_window).left)) ||
      (((this->game_window).right <= this->mouse_x || (iStack_4 < (this->game_window).top)))) ||
     ((this->game_window).bottom <= iStack_4)) {
    this->next_facet = this->facet;
    bVar7 = false;
  }
  else {
    this->next_facet = this->game_facet;
    bVar7 = true;
  }
  if (((this->save_area_valid != 0) && (point.y == this->save_x)) &&
     ((iStack_4 == this->save_y && (this->next_facet == this->last_facet)))) {
    return 0;
  }
  this->save_x = point.y;
  this->save_y = iStack_4;
  (this->new_save_rect).left = 0;
  (this->new_save_rect).top = 0;
  if (bVar7) {
    iVar8 = this->gWidth;
    (this->new_save_rect).bottom = this->gHeight;
    iVar1 = this->mouse_x;
    (this->new_save_rect).right = iVar8;
    iVar9 = this->g_top;
    (this->mouse_rect).left = iVar1 - this->g_left;
    iVar8 = this->mouse_y;
    (this->mouse_rect).top = iVar8 - iVar9;
    iVar9 = this->g_bottom;
    (this->mouse_rect).right = this->g_right + iVar1;
  }
  else {
    iVar8 = this->cHeight;
    iVar1 = this->mouse_x;
    (this->new_save_rect).right = this->cWidth;
    (this->new_save_rect).bottom = iVar8;
    iVar9 = this->d_top;
    (this->mouse_rect).left = iVar1 - this->d_left;
    iVar8 = this->mouse_y;
    (this->mouse_rect).top = iVar8 - iVar9;
    iVar9 = this->d_bottom;
    (this->mouse_rect).right = this->d_right + iVar1;
  }
  lVar2 = (this->new_save_rect).left;
  (this->mouse_rect).bottom = iVar9 + iVar8;
  lVar3 = (this->new_save_rect).top;
  (this->cursor_rect).left = lVar2;
  lVar2 = (this->new_save_rect).right;
  (this->cursor_rect).top = lVar3;
  lVar3 = (this->new_save_rect).bottom;
  (this->cursor_rect).right = lVar2;
  (this->cursor_rect).bottom = lVar3;
  iVar8 = (this->mouse_rect).right;
  if ((-1 < iVar8) && (iVar9 = (this->mouse_rect).bottom, -1 < iVar9)) {
    pTVar4 = this->render_area;
    iVar1 = (this->mouse_rect).left;
    if ((iVar1 <= pTVar4->Width) && (iVar5 = (this->mouse_rect).top, iVar5 <= pTVar4->Height)) {
      if (iVar1 < 0) {
        (this->cursor_rect).left = -iVar1;
        iVar6 = (this->new_save_rect).right;
        (this->mouse_rect).left = 0;
        (this->new_save_rect).right = iVar6 + iVar1;
      }
      if (pTVar4->Width < iVar8) {
        iVar8 = iVar8 - pTVar4->Width;
        (this->cursor_rect).right = (this->cursor_rect).right - iVar8;
        (this->new_save_rect).right = (this->new_save_rect).right - iVar8;
        (this->mouse_rect).right = pTVar4->Width;
      }
      if (iVar5 < 0) {
        iVar8 = (this->new_save_rect).bottom;
        (this->mouse_rect).top = 0;
        (this->cursor_rect).top = -iVar5;
        (this->new_save_rect).bottom = iVar8 + iVar5;
      }
      if (pTVar4->Height < iVar9) {
        iVar9 = iVar9 - pTVar4->Height;
        (this->cursor_rect).bottom = (this->cursor_rect).bottom - iVar9;
        (this->new_save_rect).bottom = (this->new_save_rect).bottom - iVar9;
        (this->mouse_rect).bottom = pTVar4->Height;
      }
      this->MouseOnScreen = 1;
      return 1;
    }
  }
  this->MouseOnScreen = 0;
  return 1;
}

// --------------------------------------------------

// Function: draw
// Address: 0045ba60
// [HELPER] s_C__msdev_work_age1_x1_Mouseptr_c: "C:\msdev\work\age1_x1\Mouseptr.cpp"
// [HELPER] s_mouseptr__draw: "mouseptr::draw"
/* WARNING: Variable defined which should be unmapped: lplpDDClipper */
/* public: void __thiscall TMousePointer::draw(int) */

void __thiscall TMousePointer::draw(TMousePointer *this,int param_1)
{
  tagRECT *ptVar1;
  IDirectDrawSurface *pIVar2;
  long lVar3;
  Shape_Info *pSVar4;
  ulong uVar5;
  int iVar6;
  uchar *puVar7;
  IDirectDrawClipper *lplpDDClipper;
  int local_4;
  
  local_4 = 0;
  if ((this->active != 0) && (this->custom_draw != 0)) {
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Mouseptr_c,0x2e3);
    if ((this->GameMode == 0) ||
       (((this->GameEnabled == 0 || (param_1 != 0)) || (0x21 < uVar5 - this->LastDrawTime)))) {
      iVar6 = update_mouse_position(this);
      if ((iVar6 != 0) || (param_1 != 0)) {
        this->LastDrawTime = uVar5;
        if ((this->save_area_valid != 0) &&
           (pIVar2 = this->restoreSurface, pIVar2 != this->PrimarySurface)) {
          iVar6 = (**(code **)((int)*pIVar2 + 0x14))
                            (pIVar2,&this->restore_rect,this->save_area->DrawSurface,
                             &this->save_rect,0x1000000,0);
          if (iVar6 != 0) {
            this->LastddError = iVar6;
            return;
          }
        }
        if (this->MouseOnScreen == 0) {
          this->save_area_valid = 0;
        }
        else {
          ptVar1 = &this->mouse_rect;
          pIVar2 = this->save_area->DrawSurface;
          iVar6 = (**(code **)((int)*pIVar2 + 0x14))
                            (pIVar2,&this->new_save_rect,this->renderSurface,ptVar1,0x1000000,0);
          if (iVar6 != 0) {
            this->LastddError = iVar6;
            return;
          }
          pIVar2 = this->renderSurface;
          lVar3 = ptVar1->left;
          this->restoreSurface = pIVar2;
          (this->restore_rect).left = lVar3;
          (this->restore_rect).top = (this->mouse_rect).top;
          (this->restore_rect).right = (this->mouse_rect).right;
          (this->restore_rect).bottom = (this->mouse_rect).bottom;
          (this->save_rect).left = (this->new_save_rect).left;
          (this->save_rect).top = (this->new_save_rect).top;
          (this->save_rect).right = (this->new_save_rect).right;
          (this->save_rect).bottom = (this->new_save_rect).bottom;
          this->save_area_valid = 1;
          if (this->Mouse_Mode == 0) {
            iVar6 = (**(code **)((int)*pIVar2 + 0x3c))(pIVar2,&local_4);
            if (iVar6 == -0x7789fdc8) {
              iVar6 = 0;
              local_4 = 0;
            }
            if (iVar6 != 0) {
              this->LastddError = iVar6;
              return;
            }
            if (local_4 != 0) {
              iVar6 = (**(code **)((int)*this->renderSurface + 0x70))(this->renderSurface,0);
              if (iVar6 != 0) {
                this->LastddError = iVar6;
                return;
              }
            }
          }
          if (this->Mouse_Mode == 1) {
            puVar7 = TDrawArea::Lock(this->render_area,s_mouseptr__draw,1);
            if (puVar7 != (uchar *)0x0) {
              lVar3 = this->next_facet;
              pSVar4 = this->Cursor_Shape->shape_info;
              TShape::shape_draw(this->Cursor_Shape,this->render_area,
                                 pSVar4[lVar3].Hotspot_X + ptVar1->left,
                                 pSVar4[lVar3].Hotspot_Y + (this->mouse_rect).top,lVar3,'\0',
                                 (uchar *)0x0);
              TDrawArea::Unlock(this->render_area,s_mouseptr__draw);
            }
          }
          if (this->Mouse_Mode == 0) {
            TDrawArea::SetTrans(this->cursors[this->next_facet],1,'\0');
            iVar6 = (**(code **)((int)*this->renderSurface + 0x1c))
                              (this->renderSurface,ptVar1->left,(this->mouse_rect).top,
                               this->cursors[this->next_facet]->DrawSurface,&this->cursor_rect,0x11)
            ;
            if (iVar6 != 0) {
              this->LastddError = iVar6;
              return;
            }
          }
          this->last_facet = this->next_facet;
          if ((this->Mouse_Mode == 0) && (local_4 != 0)) {
            iVar6 = (**(code **)((int)*this->renderSurface + 0x70))(this->renderSurface,local_4);
            if (iVar6 != 0) {
              this->LastddError = iVar6;
              return;
            }
          }
        }
        if ((this->GameMode == 0) || (this->GameEnabled == 0)) {
          InvalidateRect(this->render_area->Wnd,&this->mouse_rect,0);
        }
        this->drawn = 1;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: erase
// Address: 0045bd60
/* public: void __thiscall TMousePointer::erase(void) */

void __thiscall TMousePointer::erase(TMousePointer *this)
{
  IDirectDrawSurface *pIVar1;
  int iVar2;
  
  if ((((this->active != 0) && (this->custom_draw != 0)) && (this->drawn != 0)) &&
     ((this->save_area_valid != 0 && (pIVar1 = this->restoreSurface, pIVar1 != this->PrimarySurface)
      ))) {
    iVar2 = (**(code **)((int)*pIVar1 + 0x14))
                      (pIVar1,&this->restore_rect,this->save_area->DrawSurface,&this->save_rect,
                       0x1000000,0);
    if (iVar2 != 0) {
      this->LastddError = iVar2;
      return;
    }
    if ((this->GameMode != 0) && (this->GameEnabled != 0)) {
      this->save_area_valid = 1;
      this->restoreSurface = this->PrimarySurface;
      return;
    }
    InvalidateRect(this->render_area->Wnd,&this->restore_rect,0);
    this->save_area_valid = 0;
  }
  return;
}

// --------------------------------------------------

// Function: set_facet
// Address: 0045be20
/* public: void __thiscall TMousePointer::set_facet(int) */

void __thiscall TMousePointer::set_facet(TMousePointer *this,int param_1)
{
  Shape_Info *pSVar1;
  
  if ((-1 < param_1) && (param_1 < this->Num_Cursors)) {
    this->facet = param_1;
    pSVar1 = this->Cursor_Shape->shape_info;
    this->cWidth = pSVar1[param_1].Width;
    this->cHeight = pSVar1[param_1].Height;
    this->d_top = pSVar1[param_1].Hotspot_Y;
    this->d_left = pSVar1[param_1].Hotspot_X;
    this->d_right = this->cWidth - pSVar1[param_1].Hotspot_X;
    this->d_bottom = this->cHeight - pSVar1[param_1].Hotspot_Y;
  }
  return;
}

// --------------------------------------------------

// Function: set_game_facet
// Address: 0045be80
/* public: void __thiscall TMousePointer::set_game_facet(int) */

void __thiscall TMousePointer::set_game_facet(TMousePointer *this,int param_1)
{
  Shape_Info *pSVar1;
  
  if ((-1 < param_1) && (param_1 < this->Num_Cursors)) {
    this->game_facet = param_1;
    pSVar1 = this->Cursor_Shape->shape_info;
    this->gWidth = pSVar1[param_1].Width;
    this->gHeight = pSVar1[param_1].Height;
    this->g_top = pSVar1[param_1].Hotspot_Y;
    this->g_left = pSVar1[param_1].Hotspot_X;
    this->g_right = this->gWidth - pSVar1[param_1].Hotspot_X;
    this->g_bottom = this->gHeight - pSVar1[param_1].Hotspot_Y;
  }
  return;
}

// --------------------------------------------------

// Function: off
// Address: 0045bee0
/* public: void __thiscall TMousePointer::off(void) */

void __thiscall TMousePointer::off(TMousePointer *this)
{
  if (this->Shutdown == 0) {
    if (((this->custom_draw != 0) && (this->drawn != 0)) && (this->save_area_valid != 0)) {
      erase(this);
      TDrawSystem::Paint(this->render_area->DrawSystem,&this->restore_rect);
    }
    SetCursor(0);
    this->active = 0;
    reset(this);
  }
  return;
}

// --------------------------------------------------

// Function: on
// Address: 0045bf40
/* public: void __thiscall TMousePointer::on(void) */

void __thiscall TMousePointer::on(TMousePointer *this)
{
  undefined4 uVar1;
  
  if (this->Shutdown == 0) {
    if (this->custom_draw == 0) {
      uVar1 = LoadCursorA(0,0x7f00);
      SetCursor(uVar1);
    }
    this->active = 1;
  }
  return;
}

// --------------------------------------------------

// Function: reset
// Address: 0045bf80
/* public: void __thiscall TMousePointer::reset(void) */

void __thiscall TMousePointer::reset(TMousePointer *this)
{
  this->save_area_valid = 0;
  this->drawn = 0;
  return;
}

// --------------------------------------------------

// Function: center
// Address: 0045bf90
/* WARNING: Variable defined which should be unmapped: win_rect */
/* public: void __thiscall TMousePointer::center(void) */

void __thiscall TMousePointer::center(TMousePointer *this)
{
  TDrawSystem *pTVar1;
  tagRECT win_rect;
  int iStack_4;
  
  pTVar1 = this->render_area->DrawSystem;
  if (pTVar1->ScreenMode == '\x01') {
    GetWindowRect(pTVar1->Wnd,&win_rect.top);
    SetCursorPos((win_rect.bottom - win_rect.top) / 2 + win_rect.top,
                 (iStack_4 - win_rect.right) / 2 + win_rect.right);
    return;
  }
  SetCursorPos(pTVar1->ScreenWidth / 2,pTVar1->ScreenHeight / 2);
  return;
}

// --------------------------------------------------

// Function: Poll
// Address: 0045c010
// [HELPER] s_C__msdev_work_age1_x1_Mouseptr_c: "C:\msdev\work\age1_x1\Mouseptr.cpp"
// [HELPER] s_mouseptr__poll: "mouseptr::poll"
/* WARNING: Variable defined which should be unmapped: lplpDDClipper */
/* public: void __thiscall TMousePointer::Poll(void) */

void __thiscall TMousePointer::Poll(TMousePointer *this)
{
  tagRECT *ptVar1;
  IDirectDrawSurface *pIVar2;
  long lVar3;
  long lVar4;
  Shape_Info *pSVar5;
  ulong uVar6;
  int iVar7;
  uchar *puVar8;
  IDirectDrawClipper *lplpDDClipper;
  int local_4;
  
  local_4 = 0;
  if ((((this->active != 0) && (this->custom_draw != 0)) && (this->GameMode != 0)) &&
     (this->GameEnabled != 0)) {
    uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_Mouseptr_c,0x42e);
    if (0x21 < uVar6 - this->LastDrawTime) {
      iVar7 = update_mouse_position(this);
      if (iVar7 != 0) {
        this->LastDrawTime = uVar6;
        if (this->Mouse_Mode == 0) {
          iVar7 = (**(code **)((int)*this->PrimarySurface + 0x3c))(this->PrimarySurface,&local_4);
          if (iVar7 == -0x7789fdc8) {
            iVar7 = 0;
            local_4 = 0;
          }
          if (iVar7 != 0) {
            this->LastddError = iVar7;
            return;
          }
          if (local_4 != 0) {
            iVar7 = (**(code **)((int)*this->PrimarySurface + 0x70))(this->PrimarySurface,0);
            if (iVar7 != 0) {
              this->LastddError = iVar7;
              return;
            }
          }
        }
        if (this->save_area_valid != 0) {
          iVar7 = (**(code **)((int)*this->restoreSurface + 0x14))
                            (this->restoreSurface,&this->restore_rect,this->save_area->DrawSurface,
                             &this->save_rect,0x1000000,0);
          if (iVar7 != 0) {
            this->LastddError = iVar7;
            return;
          }
          pIVar2 = this->PrimarySurface;
          if (this->restoreSurface != pIVar2) {
            iVar7 = (**(code **)((int)*pIVar2 + 0x14))
                              (pIVar2,&this->restore_rect,this->save_area->DrawSurface,
                               &this->save_rect,0x1000000,0);
            if (iVar7 != 0) {
              this->LastddError = iVar7;
              return;
            }
          }
        }
        if (this->MouseOnScreen == 0) {
          this->save_area_valid = 0;
        }
        else {
          ptVar1 = &this->mouse_rect;
          pIVar2 = this->save_area->DrawSurface;
          iVar7 = (**(code **)((int)*pIVar2 + 0x14))
                            (pIVar2,&this->new_save_rect,this->PrimarySurface,ptVar1,0x1000000,0);
          if (iVar7 != 0) {
            this->LastddError = iVar7;
            iVar7 = GetDDBltError(this,iVar7);
            this->LastddError = iVar7;
            return;
          }
          this->restoreSurface = this->PrimarySurface;
          (this->restore_rect).left = ptVar1->left;
          (this->restore_rect).top = (this->mouse_rect).top;
          (this->restore_rect).right = (this->mouse_rect).right;
          (this->restore_rect).bottom = (this->mouse_rect).bottom;
          lVar3 = (this->new_save_rect).top;
          (this->save_rect).left = (this->new_save_rect).left;
          lVar4 = (this->new_save_rect).right;
          (this->save_rect).top = lVar3;
          lVar3 = (this->new_save_rect).bottom;
          (this->save_rect).right = lVar4;
          this->save_area_valid = 1;
          (this->save_rect).bottom = lVar3;
          if (this->Mouse_Mode == 0) {
            TDrawArea::SetTrans(this->cursors[this->next_facet],1,'\0');
            iVar7 = (**(code **)((int)*this->PrimarySurface + 0x1c))
                              (this->PrimarySurface,ptVar1->left,(this->mouse_rect).top,
                               this->cursors[this->next_facet]->DrawSurface,&this->cursor_rect,0x11)
            ;
            if (iVar7 != 0) {
              this->LastddError = iVar7;
              return;
            }
          }
          if (this->Mouse_Mode == 1) {
            puVar8 = TDrawArea::Lock(this->primary_area,s_mouseptr__poll,1);
            if (puVar8 != (uchar *)0x0) {
              lVar3 = this->next_facet;
              pSVar5 = this->Cursor_Shape->shape_info;
              TShape::shape_draw(this->Cursor_Shape,this->primary_area,
                                 pSVar5[lVar3].Hotspot_X + ptVar1->left,
                                 (this->mouse_rect).top + pSVar5[lVar3].Hotspot_Y,lVar3,'\0',
                                 (uchar *)0x0);
              TDrawArea::Unlock(this->primary_area,s_mouseptr__poll);
            }
          }
          this->last_facet = this->next_facet;
        }
        if ((this->Mouse_Mode == 0) && (local_4 != 0)) {
          iVar7 = (**(code **)((int)*this->PrimarySurface + 0x70))(this->PrimarySurface,local_4);
          if (iVar7 != 0) {
            this->LastddError = iVar7;
            return;
          }
        }
        this->drawn = 1;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: GetDDBltError
// Address: 0045c300
/* public: int __thiscall TMousePointer::GetDDBltError(long) */

int __thiscall TMousePointer::GetDDBltError(TMousePointer *this,long param_1)
{
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      return 1;
    }
    if (param_1 == -0x7fffbfff) {
      return 0x11;
    }
  }
  else if (param_1 < -0x7789ffc8) {
    if (param_1 == -0x7789ffc9) {
      return 0x12;
    }
    if (param_1 == -0x7ff8ffa9) {
      return 4;
    }
  }
  else if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return 3;
    }
    if (param_1 == -0x7789ff92) {
      return 2;
    }
  }
  else if (param_1 < -0x7789ff4b) {
    if (param_1 == -0x7789ff4c) {
      return 6;
    }
    if (param_1 == -0x7789ff6a) {
      return 5;
    }
  }
  else if (param_1 < -0x7789ff05) {
    if (param_1 == -0x7789ff06) {
      return 10;
    }
    if (param_1 == -0x7789ff33) {
      return 8;
    }
  }
  else if (param_1 < -0x7789fedd) {
    if (param_1 == -0x7789fede) {
      return 0xc;
    }
    if (param_1 == -0x7789fee8) {
      return 0xb;
    }
  }
  else if (param_1 < -0x7789feab) {
    if (param_1 == -0x7789feac) {
      return 0xe;
    }
    if (param_1 == -0x7789feca) {
      return 0xd;
    }
  }
  else if (param_1 < -0x7789fe3d) {
    if (param_1 == -0x7789fe3e) {
      return 0x10;
    }
    if (param_1 == -0x7789fe52) {
      return 0xf;
    }
  }
  else {
    if (param_1 == -0x7789fdc1) {
      return 7;
    }
    if (param_1 == -0x7789fdc0) {
      return 9;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return -1;
}

// --------------------------------------------------


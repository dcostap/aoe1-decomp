// Class: TDrawArea
// Size:  0x100
//
// Member Layout:
// [0x000] TDrawSystem * DrawSystem
// [0x004] void * Wnd
// [0x008] uchar * Bits
// [0x00C] BITMAPINFO256 * BitmapInfo
// [0x010] void * Bitmap
// [0x014] void * OldBitmap
// [0x018] int Width
// [0x01C] int Height
// [0x020] int Pitch
// [0x024] int Orien
// [0x028] tagRECT ClipRect (sz: 0x10)
// [0x038] void * DrawDc
// [0x03C] IDirectDrawSurface * DrawSurface
// [0x040] _DDSURFACEDESC SurfaceDesc (sz: 0x6C)
// [0x0AC] DrawAreaNode * Node
// [0x0B0] char * Name
// [0x0B4] uchar * LastBits
// [0x0B8] int LastPitch
// [0x0BC] void * * DisplayOffsets
// [0x0C0] void * * CurDisplayOffsets
// [0x0C4] void * * FloatOffsets
// [0x0C8] RGE_Color_Table * shadow_color_table
// [0x0CC] TSpan_List_Manager * SpanList
// [0x0D0] TSpan_List_Manager * CurSpanList
// [0x0D4] int Float_X_Delta
// [0x0D8] int Float_Y_Delta
// [0x0DC] int DisplayOffsetsSz
// [0x0E0] int FloatOffsetsSz
// [0x0E4] int SystemMemOnly
// [0x0E8] int UsingVidMem
// [0x0EC] int UseTrans
// [0x0F0] int IsPrimarySurface
// [0x0F4] int Restored
// [0x0F8] int ExtendedLines
// [0x0FC] uchar TransColor
// ----------------------------------------------------------------

// Function: TDrawArea
// Address: 00443de0
/* public: __thiscall TDrawArea::TDrawArea(char *,int) */

TDrawArea * __thiscall TDrawArea::TDrawArea(TDrawArea *this,char *param_1,int param_2)
{
  char cVar1;
  BITMAPINFO256 *pBVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  this->DrawSystem = (TDrawSystem *)0x0;
  this->Wnd = (void *)0x0;
  this->DrawSurface = (IDirectDrawSurface *)0x0;
  this->UsingVidMem = 0;
  this->DrawDc = (void *)0x0;
  this->BitmapInfo = (BITMAPINFO256 *)0x0;
  this->Bitmap = (void *)0x0;
  this->OldBitmap = (void *)0x0;
  this->Bits = (uchar *)0x0;
  this->Width = 0;
  this->Height = 0;
  this->Pitch = 0;
  this->UseTrans = 0;
  this->TransColor = 0xff;
  this->Node = (DrawAreaNode *)0x0;
  this->Restored = 0;
  this->IsPrimarySurface = 0;
  this->SystemMemOnly = param_2;
  (this->ClipRect).left = 0;
  (this->ClipRect).top = 0;
  (this->ClipRect).right = 0;
  (this->ClipRect).bottom = 0;
  this->LastBits = (uchar *)0x0;
  this->DisplayOffsets = (void **)0x0;
  this->CurDisplayOffsets = (void **)0x0;
  this->DisplayOffsetsSz = 0;
  this->ExtendedLines = 0;
  this->FloatOffsets = (void **)0x0;
  this->Float_X_Delta = 0;
  this->Float_Y_Delta = 0;
  this->FloatOffsetsSz = 0;
  memset(&this->SurfaceDesc,0,0x6c);
  pBVar2 = (BITMAPINFO256 *)calloc(1,0x428);
  this->BitmapInfo = pBVar2;
  uVar4 = 0xffffffff;
  this->Orien = 1;
  this->SpanList = (TSpan_List_Manager *)0x0;
  this->CurSpanList = (TSpan_List_Manager *)0x0;
  this->shadow_color_table = (RGE_Color_Table *)0x0;
  pcVar3 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((int)(~uVar4 - 1) < 1) {
    this->Name = (char *)0x0;
    return this;
  }
  pcVar3 = (char *)malloc(~uVar4);
  uVar4 = 0xffffffff;
  this->Name = pcVar3;
  do {
    pcVar6 = param_1;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar3 = pcVar3 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: ~TDrawArea
// Address: 00443f10
/* public: __thiscall TDrawArea::~TDrawArea(void) */

void __thiscall TDrawArea::~TDrawArea(TDrawArea *this)
{
  DrawAreaNode *pDVar1;
  TDrawSystem *pTVar2;
  IDirectDrawSurface *pIVar3;
  TSpan_List_Manager *this_00;
  
  pDVar1 = this->Node;
  if (pDVar1 != (DrawAreaNode *)0x0) {
    pTVar2 = this->DrawSystem;
    if ((pTVar2 != (TDrawSystem *)0x0) && (pDVar1 == pTVar2->DrawAreaList)) {
      pTVar2->DrawAreaList = pDVar1->NextNode;
    }
    pDVar1 = this->Node->PrevNode;
    if (pDVar1 != (DrawAreaNode *)0x0) {
      pDVar1->NextNode = this->Node->NextNode;
    }
    pDVar1 = this->Node->NextNode;
    if (pDVar1 != (DrawAreaNode *)0x0) {
      pDVar1->PrevNode = this->Node->PrevNode;
    }
    free(this->Node);
    this->Node = (DrawAreaNode *)0x0;
  }
  if ((this->DrawSystem == (TDrawSystem *)0x0) || (this->DrawSystem->DrawType != '\x01')) {
    pIVar3 = this->DrawSurface;
    if ((pIVar3 != (IDirectDrawSurface *)0x0) && (this->IsPrimarySurface == 0)) {
      (**(code **)((int)*pIVar3 + 8))(pIVar3);
      this->DrawSurface = (IDirectDrawSurface *)0x0;
    }
  }
  else if (this->DrawDc != (void *)0x0) {
    if (this->Bitmap != (void *)0x0) {
      if (this->OldBitmap != (void *)0x0) {
        SelectObject(this->DrawDc,this->OldBitmap);
      }
      DeleteObject(this->Bitmap);
    }
    DeleteDC(this->DrawDc);
  }
  if (this->BitmapInfo != (BITMAPINFO256 *)0x0) {
    free(this->BitmapInfo);
  }
  if (this->DisplayOffsets != (void **)0x0) {
    free(this->DisplayOffsets);
  }
  if (this->FloatOffsets != (void **)0x0) {
    free(this->FloatOffsets);
  }
  this_00 = this->SpanList;
  if (this_00 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(this_00);
    operator_delete(this_00);
  }
  if (this->Name != (char *)0x0) {
    free(this->Name);
  }
  return;
}

// --------------------------------------------------

// Function: Init
// Address: 00444040
/* public: int __thiscall TDrawArea::Init(class TDrawSystem *,long,long,int,int) */

int __thiscall
TDrawArea::Init(TDrawArea *this,TDrawSystem *param_1,long param_2,long param_3,int param_4,
               int param_5)
{
  DrawAreaNode *pDVar1;
  DrawAreaNode *pDVar2;
  
  this->DrawSystem = param_1;
  this->IsPrimarySurface = param_5;
  if (param_1 != (TDrawSystem *)0x0) {
    this->Wnd = param_1->Wnd;
    if (this->Node == (DrawAreaNode *)0x0) {
      pDVar2 = (DrawAreaNode *)calloc(1,0xc);
      this->Node = pDVar2;
      if (pDVar2 == (DrawAreaNode *)0x0) {
        return 0;
      }
      pDVar2->DrawArea = this;
      this->Node->PrevNode = (DrawAreaNode *)0x0;
      this->Node->NextNode = (DrawAreaNode *)0x0;
      pDVar2 = this->DrawSystem->DrawAreaList;
      if (pDVar2 == (DrawAreaNode *)0x0) {
        this->DrawSystem->DrawAreaList = this->Node;
      }
      else {
        for (pDVar1 = pDVar2->NextNode; pDVar1 != (DrawAreaNode *)0x0; pDVar1 = pDVar1->NextNode) {
          pDVar2 = pDVar1;
        }
        pDVar2->NextNode = this->Node;
        this->Node->PrevNode = pDVar2;
      }
    }
    if (this->DrawSystem->DrawType == '\x01') {
      return 0;
    }
  }
  SetSize(this,param_2,param_3,param_4);
  return 1;
}

// --------------------------------------------------

// Function: CheckSurface
// Address: 00444110
/* WARNING: Variable defined which should be unmapped: ddsd */
/* public: unsigned char __thiscall TDrawArea::CheckSurface(void) */

uchar __thiscall TDrawArea::CheckSurface(TDrawArea *this)
{
  IDirectDrawSurface *pIVar1;
  IDirectDraw *pIVar2;
  int iVar3;
  _DDSURFACEDESC ddsd;
  _DDBLTFX ddbltfx;
  
  if ((this->DrawSystem != (TDrawSystem *)0x0) && (this->DrawSystem->DrawType == '\x02')) {
    pIVar1 = this->DrawSurface;
    if (pIVar1 == (IDirectDrawSurface *)0x0) {
      return '\x03';
    }
    iVar3 = (**(code **)((int)*pIVar1 + 0x60))(pIVar1);
    if (iVar3 != 0) {
      TDrawSystem::GetIsLostErrorNum(this->DrawSystem,iVar3);
      memset(&ddsd,0,0x6c);
      ddsd.dwSize = 0x6c;
      pIVar2 = this->DrawSystem->DirDraw;
      iVar3 = (**(code **)((int)*pIVar2 + 0x30))(pIVar2,&ddsd);
      if ((iVar3 == 0) &&
         (((ddsd.dwFlags != this->DrawSystem->ScreenWidth ||
           (ddsd.dwSize != this->DrawSystem->ScreenHeight)) || (ddsd.ddpfPixelFormat.dwFlags != 8)))
         ) {
        return '\x01';
      }
      iVar3 = (**(code **)((int)*this->DrawSurface + 0x6c))(this->DrawSurface);
      if (iVar3 == 0) {
        ddsd.ddpfPixelFormat.field6_0x18.dwBBitMask = 100;
        (**(code **)((int)*this->DrawSurface + 0x14))
                  (this->DrawSurface,0,0,0,0x1000400,&ddsd.ddpfPixelFormat.field6_0x18);
        this->Restored = 1;
        return '\x02';
      }
      if ((iVar3 == -0x7789fdb5) || (iVar3 == -0x7ff8fff2)) {
        (**(code **)((int)*this->DrawSurface + 8))(this->DrawSurface);
        this->DrawSurface = (IDirectDrawSurface *)0x0;
        SetSize(this,this->Width,this->Height,0);
        if (this->DrawSurface != (IDirectDrawSurface *)0x0) {
          return '\x02';
        }
      }
      TDrawSystem::GetRestoreErrorNum(this->DrawSystem,iVar3);
      return '\x03';
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: Lock
// Address: 00444270
/* public: unsigned char * __thiscall TDrawArea::Lock(char *,int) */

uchar * __thiscall TDrawArea::Lock(TDrawArea *this,char *param_1,int param_2)
{
  IDirectDrawSurface *pIVar1;
  int iVar2;
  
  if ((this->DrawSystem == (TDrawSystem *)0x0) || (this->DrawSystem->DrawType != '\x01')) {
    pIVar1 = this->DrawSurface;
    if (pIVar1 == (IDirectDrawSurface *)0x0) {
      return (uchar *)0x0;
    }
    if (this->Bits != (uchar *)0x0) {
      return this->Bits;
    }
    if (this->DrawDc != (void *)0x0) {
      return (uchar *)0x0;
    }
    iVar2 = (**(code **)((int)*pIVar1 + 100))(pIVar1,0,&this->SurfaceDesc,param_2 != 0,0);
    if (iVar2 != 0) {
      return (uchar *)0x0;
    }
    this->Bits = (uchar *)(this->SurfaceDesc).lpSurface;
    SetInfo(this);
    if (this->Bits != this->LastBits) {
      SetAccessOffsets(this);
    }
  }
  return this->Bits;
}

// --------------------------------------------------

// Function: Unlock
// Address: 00444300
/* public: void __thiscall TDrawArea::Unlock(char *) */

void __thiscall TDrawArea::Unlock(TDrawArea *this,char *param_1)
{
  IDirectDrawSurface *pIVar1;
  
  if ((((this->DrawSystem == (TDrawSystem *)0x0) || (this->DrawSystem->DrawType != '\x01')) &&
      (pIVar1 = this->DrawSurface, pIVar1 != (IDirectDrawSurface *)0x0)) &&
     (this->Bits != (uchar *)0x0)) {
    (**(code **)((int)*pIVar1 + 0x80))(pIVar1,this->Bits);
    this->Bits = (uchar *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: GetDc
// Address: 00444340
/* public: void * __thiscall TDrawArea::GetDc(char *) */

void * __thiscall TDrawArea::GetDc(TDrawArea *this,char *param_1)
{
  IDirectDrawSurface *pIVar1;
  void *pvVar2;
  
  if ((this->DrawSystem != (TDrawSystem *)0x0) && (this->DrawSystem->DrawType == '\x01')) {
    return this->DrawDc;
  }
  pIVar1 = this->DrawSurface;
  if (pIVar1 == (IDirectDrawSurface *)0x0) {
    return (void *)0x0;
  }
  pvVar2 = this->DrawDc;
  if (pvVar2 == (void *)0x0) {
    if (this->Bits != (uchar *)0x0) {
      return (void *)0x0;
    }
    (**(code **)((int)*pIVar1 + 0x44))(pIVar1,&this->DrawDc);
    pvVar2 = this->DrawDc;
  }
  return pvVar2;
}

// --------------------------------------------------

// Function: ReleaseDc
// Address: 00444390
/* public: void __thiscall TDrawArea::ReleaseDc(char *) */

void __thiscall TDrawArea::ReleaseDc(TDrawArea *this,char *param_1)
{
  IDirectDrawSurface *pIVar1;
  
  if ((((this->DrawSystem == (TDrawSystem *)0x0) || (this->DrawSystem->DrawType != '\x01')) &&
      (pIVar1 = this->DrawSurface, pIVar1 != (IDirectDrawSurface *)0x0)) &&
     (this->DrawDc != (void *)0x0)) {
    (**(code **)((int)*pIVar1 + 0x68))(pIVar1,this->DrawDc);
    this->DrawDc = (void *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: SetSize
// Address: 004443d0
/* public: void __thiscall TDrawArea::SetSize(long,long,int) */

void __thiscall TDrawArea::SetSize(TDrawArea *this,long param_1,long param_2,int param_3)
{
  IDirectDrawSurface **ppIVar1;
  TDrawSystem *pTVar2;
  IDirectDrawSurface *pIVar3;
  IDirectDraw *pIVar4;
  IDirectDrawSurface IVar5;
  int iVar6;
  TSpan_List_Manager *pTVar7;
  ulong uVar8;
  undefined4 *unaff_FS_OFFSET;
  _DDSURFACEDESC ddsd;
  _DDBLTFX ddbltfx;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d30e;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar2 = this->DrawSystem;
  if ((((pTVar2 != (TDrawSystem *)0x0) && (pTVar2->DrawType != '\x01')) &&
      (pTVar2 != (TDrawSystem *)0x0)) &&
     ((((pTVar2->DirDraw != (IDirectDraw *)0x0 && (param_1 != 0)) && (param_2 != 0)) &&
      (((param_1 != this->Width || (param_2 != this->Height)) ||
       (this->DrawSurface == (IDirectDrawSurface *)0x0)))))) {
    if (param_1 < 1) {
      param_1 = 1;
    }
    if (param_2 < 1) {
      param_2 = 1;
    }
    uVar8 = param_2 + 10;
    if (param_3 == 0) {
      uVar8 = param_2;
    }
    this->ExtendedLines = param_3;
    (this->BitmapInfo->bmiHeader).biWidth = param_1;
    if (this->Orien == 1) {
      (this->BitmapInfo->bmiHeader).biHeight = -uVar8;
    }
    else {
      (this->BitmapInfo->bmiHeader).biHeight = uVar8;
    }
    this->Width = param_1;
    this->Height = param_2;
    if (this->IsPrimarySurface == 0) {
      pIVar3 = this->DrawSurface;
      ppIVar1 = &this->DrawSurface;
      if (pIVar3 != (IDirectDrawSurface *)0x0) {
        (**(code **)((int)*pIVar3 + 8))(pIVar3);
        *ppIVar1 = (IDirectDrawSurface *)0x0;
        memset(&this->SurfaceDesc,0,0x6c);
        this->Pitch = 0;
        this->UsingVidMem = 0;
      }
      memset(&ddsd.dwFlags,0,0x6c);
      ddsd.dwFlags = 0x6c;
      ddsd.dwHeight = 7;
      if ((((this->DrawSystem->Flags & 1) != 0) || (param_3 != 0)) ||
         (ddbltfx.dwSize = 0x40, this->SystemMemOnly != 0)) {
        ddbltfx.dwSize = 0x840;
      }
      ddsd.field4_0x10 = (_DDSURFACEDESC_u_16)this->Width;
      pIVar4 = this->DrawSystem->DirDraw;
      ddsd.dwWidth = uVar8;
      iVar6 = (**(code **)((int)*pIVar4 + 0x18))(pIVar4,&ddsd.dwFlags,ppIVar1,0);
      if (iVar6 == 0) {
        pIVar3 = *ppIVar1;
        IVar5 = *pIVar3;
        (this->SurfaceDesc).dwSize = 0x6c;
        iVar6 = (**(code **)((int)IVar5 + 0x58))(pIVar3,&this->SurfaceDesc);
        if (iVar6 == 0) {
          SetInfo(this);
          SetAccessOffsets(this);
          ddbltfx.dwDDFX = 100;
          ddbltfx.ddckDestColorkey.dwColorSpaceLowValue = 0;
          (**(code **)((int)**ppIVar1 + 0x14))(*ppIVar1,0,0,0,0x1000400,&ddbltfx.dwDDFX);
        }
        else {
          TDrawSystem::GetCreateErrorNum(this->DrawSystem,iVar6);
        }
      }
    }
    else {
      this->DrawSurface = this->DrawSystem->PrimarySurface;
    }
    SetClipRect(this,(tagRECT *)0x0);
    Clear(this,(tagRECT *)0x0,0);
  }
  pTVar7 = this->SpanList;
  if (pTVar7 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar7);
    operator_delete(pTVar7);
  }
                    /* language.dll match for 0x68: "Arial" */
  ddsd.dwSize = (ulong)operator_new(0x68);
  iVar6 = 0;
  uStack_4 = 0;
  if ((TSpan_List_Manager *)ddsd.dwSize == (TSpan_List_Manager *)0x0) {
    pTVar7 = (TSpan_List_Manager *)0x0;
  }
  else {
    pTVar7 = (TSpan_List_Manager *)
             TSpan_List_Manager::TSpan_List_Manager
                       ((TSpan_List_Manager *)ddsd.dwSize,param_1,param_2);
  }
  uStack_4 = 0xffffffff;
  this->SpanList = pTVar7;
  if (0 < param_2) {
    do {
      TSpan_List_Manager::AddSpan(this->SpanList,0,param_1 + -1,iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_2);
  }
  this->CurSpanList = this->SpanList;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: Clear
// Address: 00444680
/* WARNING: Variable defined which should be unmapped: wid */
/* public: void __thiscall TDrawArea::Clear(struct tagRECT *,int) */

void __thiscall TDrawArea::Clear(TDrawArea *this,tagRECT *param_1,int param_2)
{
  IDirectDrawSurface *pIVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  int wid;
  tagRECT dest;
  _DDBLTFX ddbltfx;
  
  if (DDSys_CanColorFill == 0) {
    PtrClear(this,param_1,param_2);
    return;
  }
  if ((this->DrawSystem == (TDrawSystem *)0x0) || (this->DrawSystem->DrawType != '\x01')) {
    pIVar1 = this->DrawSurface;
    if (pIVar1 != (IDirectDrawSurface *)0x0) {
      ddbltfx.dwDDFX = 100;
      ddbltfx.ddckDestColorkey.dwColorSpaceLowValue = param_2;
      if (param_1 == (tagRECT *)0x0) {
        (**(code **)((int)*pIVar1 + 0x14))(pIVar1,0,0,0,0x1000400,&ddbltfx.dwDDFX);
        return;
      }
      dest.top = param_1->left;
      dest.right = param_1->top;
      dest.bottom = param_1->right + 1;
      ddbltfx.dwSize = param_1->bottom + 1;
      (**(code **)((int)*pIVar1 + 0x14))(pIVar1,&dest.top,0,0,0x1000400,&ddbltfx.dwDDFX);
    }
  }
  else {
    puVar7 = this->Bits;
    if (puVar7 != (uchar *)0x0) {
      if (param_1 == (tagRECT *)0x0) {
        memset(puVar7,param_2,this->Height * this->Pitch);
        return;
      }
      iVar2 = param_1->left;
      iVar4 = param_1->top;
      iVar5 = param_1->right;
      iVar3 = param_1->bottom;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      else if (this->Width <= iVar2) {
        iVar2 = this->Width + -1;
      }
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (this->Height <= iVar4) {
        iVar4 = this->Height + -1;
      }
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      else if (this->Width <= iVar5) {
        iVar5 = this->Width + -1;
      }
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else if (this->Height <= iVar3) {
        iVar3 = this->Height + -1;
      }
      if ((iVar2 < iVar5) && (iVar4 < iVar3)) {
        dest.left = (iVar5 - iVar2) + 1;
        if (this->Orien == 1) {
          iVar5 = this->Pitch;
          iVar6 = iVar4 * iVar5;
        }
        else {
          iVar6 = ((this->Height - iVar4) + -1) * this->Pitch;
          iVar5 = -this->Pitch;
        }
        puVar7 = puVar7 + iVar6 + iVar2;
        if (iVar4 <= iVar3) {
          iVar2 = (iVar3 - iVar4) + 1;
          do {
            memset(puVar7,param_2,dest.left);
            puVar7 = puVar7 + iVar5;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: PtrClear
// Address: 00444850
// [HELPER] s_PtrClear: "PtrClear"
/* public: void __thiscall TDrawArea::PtrClear(struct tagRECT *,int) */

void __thiscall TDrawArea::PtrClear(TDrawArea *this,tagRECT *param_1,int param_2)
{
  void **ppvVar1;
  uchar *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  void **SrcP;
  int nWidth;
  int nLines;
  int x1;
  
  if (param_1 == (tagRECT *)0x0) {
    iVar3 = this->Width;
    iVar5 = this->Height;
    x1 = 0;
    param_1 = (tagRECT *)0x0;
  }
  else {
    x1 = param_1->left;
    iVar3 = param_1->right;
    iVar5 = param_1->bottom;
    param_1 = (tagRECT *)param_1->top;
  }
  if (((((-1 < iVar3) && (x1 <= iVar3)) && (x1 < this->Width)) &&
      ((-1 < iVar5 && ((int)param_1 <= iVar5)))) && ((int)param_1 < this->Height)) {
    if (x1 < 0) {
      x1 = 0;
    }
    if (this->Width <= iVar3) {
      iVar3 = this->Width + -1;
    }
    if ((int)param_1 < 0) {
      param_1 = (tagRECT *)0x0;
    }
    if (this->Height <= iVar5) {
      iVar5 = this->Height + -1;
    }
    nLines = (iVar5 - (int)param_1) + 1;
    iVar3 = (iVar3 - x1) + 1;
    if (((this->DrawSystem != (TDrawSystem *)0x0) && (this->DrawSystem->DrawType == '\x02')) &&
       (puVar2 = Lock(this,s_PtrClear,1), puVar2 == (uchar *)0x0)) {
      return;
    }
    ppvVar1 = this->CurDisplayOffsets;
    uVar6 = (undefined1)param_2;
    do {
                    /* Symbol Ref: {@symbol PtrClearLoop} */
      puVar9 = (undefined4 *)((int)ppvVar1[(int)param_1] + x1);
      uVar4 = -(int)puVar9 & 3;
      uVar7 = iVar3 - uVar4;
      uVar8 = uVar7;
      if (uVar7 != 0 && (int)uVar4 <= iVar3) {
        for (; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar9 = uVar6;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        uVar8 = uVar7 & 3;
        for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar9 = CONCAT22(CONCAT11(uVar6,uVar6),CONCAT11(uVar6,uVar6));
          puVar9 = puVar9 + 1;
        }
      }
                    /* Symbol Ref: {@symbol PtrClearLEndBytes} */
      for (iVar5 = uVar4 + uVar8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar9 = uVar6;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      param_1 = (tagRECT *)((int)&param_1->left + 1);
      nLines = nLines + -1;
    } while (nLines != 0);
    if ((this->DrawSystem != (TDrawSystem *)0x0) && (this->DrawSystem->DrawType == '\x02')) {
      Unlock(this,s_PtrClear);
    }
  }
  return;
}

// --------------------------------------------------

// Function: SetAccessOffsets
// Address: 00444990
/* public: void __thiscall TDrawArea::SetAccessOffsets(void) */

void __thiscall TDrawArea::SetAccessOffsets(TDrawArea *this)
{
  void **ppvVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = this->Height << 2;
  if (iVar4 != this->DisplayOffsetsSz) {
    if (this->DisplayOffsets != (void **)0x0) {
      free(this->DisplayOffsets);
    }
    ppvVar1 = (void **)malloc(iVar4);
    this->DisplayOffsets = ppvVar1;
    this->DisplayOffsetsSz = iVar4;
    this->CurDisplayOffsets = ppvVar1;
  }
  if ((this->Orien == 1) || (this->ExtendedLines != 0)) {
    if (this->ExtendedLines == 0) {
      puVar2 = this->Bits;
    }
    else {
      puVar2 = this->Bits + this->Pitch * 5;
    }
    iVar4 = this->Pitch;
    if (this->ExtendedLines != 0) {
      iVar4 = this->Width;
    }
  }
  else {
    puVar2 = this->Bits + (this->Height + -1) * this->Pitch;
    iVar4 = -this->Pitch;
  }
  iVar3 = 0;
  if (0 < this->Height) {
    do {
      this->DisplayOffsets[iVar3] = puVar2;
      puVar2 = puVar2 + iVar4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->Height);
  }
  if (this->FloatOffsets != (void **)0x0) {
    SetFloatOffsets(this,this->Float_X_Delta,this->Float_Y_Delta);
  }
  this->LastBits = this->Bits;
  return;
}

// --------------------------------------------------

// Function: SetFloatOffsets
// Address: 00444a60
/* public: void __thiscall TDrawArea::SetFloatOffsets(int,int) */

void __thiscall TDrawArea::SetFloatOffsets(TDrawArea *this,int param_1,int param_2)
{
  void **ppvVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = this->Height << 2;
  if ((((iVar3 != 0) && (this->ExtendedLines != 0)) && (-1 < param_1)) && (-1 < param_2)) {
    if (iVar3 != this->FloatOffsetsSz) {
      if (this->FloatOffsets != (void **)0x0) {
        free(this->FloatOffsets);
      }
      ppvVar1 = (void **)malloc(iVar3);
      this->FloatOffsets = ppvVar1;
      this->FloatOffsetsSz = iVar3;
    }
    iVar2 = 0;
    iVar3 = param_2;
    if (0 < this->Height) {
      do {
        ppvVar1 = this->DisplayOffsets + iVar3;
        iVar3 = iVar3 + 1;
        this->FloatOffsets[iVar2] = (void *)((int)*ppvVar1 + param_1);
        if (this->Height <= iVar3) {
          iVar3 = 0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < this->Height);
    }
    this->Float_X_Delta = param_1;
    this->Float_Y_Delta = param_2;
    this->CurDisplayOffsets = this->FloatOffsets;
  }
  return;
}

// --------------------------------------------------

// Function: SetInfo
// Address: 00444b10
/* public: void __thiscall TDrawArea::SetInfo(void) */

void __thiscall TDrawArea::SetInfo(TDrawArea *this)
{
  _DDSURFACEDESC_u_16 _Var1;
  
  _Var1 = (this->SurfaceDesc).field4_0x10;
  this->Pitch = (int)_Var1;
  (this->BitmapInfo->bmiHeader).biWidth = (long)_Var1;
  if (((this->SurfaceDesc).ddsCaps.dwCaps & 0x800) != 0) {
    this->UsingVidMem = 0;
    return;
  }
  this->UsingVidMem = 1;
  return;
}

// --------------------------------------------------

// Function: AlignedWidth
// Address: 00444b40
/* public: long __thiscall TDrawArea::AlignedWidth(void) */

long __thiscall TDrawArea::AlignedWidth(TDrawArea *this)
{
  return this->Pitch;
}

// --------------------------------------------------

// Function: SetClipRect
// Address: 00444b50
/* public: void __thiscall TDrawArea::SetClipRect(struct tagRECT *) */

void __thiscall TDrawArea::SetClipRect(TDrawArea *this,tagRECT *param_1)
{
  int iVar1;
  int iVar2;
  
  if (param_1 == (tagRECT *)0x0) {
    iVar1 = this->Width;
    iVar2 = this->Height;
    (this->ClipRect).left = 0;
    (this->ClipRect).top = 0;
    (this->ClipRect).right = iVar1 + -1;
    (this->ClipRect).bottom = iVar2 + -1;
  }
  else {
    (this->ClipRect).left = param_1->left;
    (this->ClipRect).top = param_1->top;
    (this->ClipRect).right = param_1->right;
    (this->ClipRect).bottom = param_1->bottom;
    iVar1 = (this->ClipRect).left;
    if (iVar1 < 0) {
      (this->ClipRect).left = 0;
    }
    else {
      iVar2 = this->Width + -1;
      if (iVar2 < iVar1) {
        (this->ClipRect).left = iVar2;
      }
    }
    iVar1 = (this->ClipRect).right;
    if (iVar1 < 0) {
      (this->ClipRect).right = 0;
    }
    else {
      iVar2 = this->Width + -1;
      if (iVar2 < iVar1) {
        (this->ClipRect).right = iVar2;
      }
    }
    iVar1 = (this->ClipRect).top;
    if (iVar1 < 0) {
      (this->ClipRect).top = 0;
    }
    else {
      iVar2 = this->Height + -1;
      if (iVar2 < iVar1) {
        (this->ClipRect).top = iVar2;
      }
    }
    iVar1 = (this->ClipRect).bottom;
    if (iVar1 < 0) {
      (this->ClipRect).bottom = 0;
    }
    else {
      iVar2 = this->Height + -1;
      if (iVar2 < iVar1) {
        (this->ClipRect).bottom = iVar2;
      }
    }
    iVar1 = (this->ClipRect).right;
    iVar2 = (this->ClipRect).left;
    if (iVar1 < iVar2) {
      (this->ClipRect).right = iVar2;
      (this->ClipRect).left = iVar1;
    }
    iVar1 = (this->ClipRect).bottom;
    iVar2 = (this->ClipRect).top;
    if (iVar1 < iVar2) {
      (this->ClipRect).bottom = iVar2;
      (this->ClipRect).top = iVar1;
    }
  }
  SetClipRect(this,(this->ClipRect).left,(this->ClipRect).top,(this->ClipRect).right,
              (this->ClipRect).bottom);
  return;
}

// --------------------------------------------------

// Function: SetClipRect
// Address: 00444c30
/* public: void __thiscall TDrawArea::SetClipRect(long,long,long,long) */

void __thiscall
TDrawArea::SetClipRect(TDrawArea *this,long param_1,long param_2,long param_3,long param_4)
{
  TSpan_List_Manager *pTVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055d32b;
  *unaff_FS_OFFSET = &local_c;
  pTVar1 = this->SpanList;
  (this->ClipRect).left = param_1;
  (this->ClipRect).top = param_2;
  (this->ClipRect).right = param_3;
  (this->ClipRect).bottom = param_4;
  if ((pTVar1 != (TSpan_List_Manager *)0x0) && (this->Height != pTVar1->Num_Lines)) {
    if (pTVar1 != (TSpan_List_Manager *)0x0) {
      TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
      operator_delete(pTVar1);
    }
    this->SpanList = (TSpan_List_Manager *)0x0;
  }
  if (this->SpanList == (TSpan_List_Manager *)0x0) {
                    /* language.dll match for 0x68: "Arial" */
    pTVar1 = (TSpan_List_Manager *)operator_new(0x68);
    local_4 = 0;
    if (pTVar1 == (TSpan_List_Manager *)0x0) {
      pTVar1 = (TSpan_List_Manager *)0x0;
    }
    else {
      pTVar1 = (TSpan_List_Manager *)
               TSpan_List_Manager::TSpan_List_Manager(pTVar1,this->Width,this->Height);
    }
    local_4 = 0xffffffff;
    this->SpanList = pTVar1;
  }
  TSpan_List_Manager::ResetAll(this->SpanList);
  TSpan_List_Manager::SetSpanRegions
            (this->SpanList,(this->ClipRect).left,(this->ClipRect).top,(this->ClipRect).right,
             (this->ClipRect).bottom);
  iVar2 = (this->ClipRect).top;
  if (iVar2 <= (this->ClipRect).bottom) {
    do {
      TSpan_List_Manager::AddSpan(this->SpanList,(this->ClipRect).left,(this->ClipRect).right,iVar2)
      ;
      iVar2 = iVar2 + 1;
    } while (iVar2 <= (this->ClipRect).bottom);
  }
  this->CurSpanList = this->SpanList;
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: Copy
// Address: 00444d50
/* WARNING: Variable defined which should be unmapped: src_rect2 */
/* public: void __thiscall TDrawArea::Copy(class TDrawArea *,long,long,struct tagRECT *,int) */

void __thiscall
TDrawArea::Copy(TDrawArea *this,TDrawArea *param_1,long param_2,long param_3,tagRECT *param_4,
               int param_5)
{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  tagRECT src_rect2;
  tagRECT dest_rect2;
  int iStack_4;
  
  iVar5 = 0;
  if ((this->DrawSystem == (TDrawSystem *)0x0) || (this->DrawSystem->DrawType != '\x01')) {
    if ((this->DrawSurface != (IDirectDrawSurface *)0x0) &&
       ((param_1 != (TDrawArea *)0x0 && (param_1->DrawSurface != (IDirectDrawSurface *)0x0)))) {
      if (param_4 == (tagRECT *)0x0) {
        iVar5 = this->Width + -1;
        src_rect2.top = 0;
        src_rect2.right = 0;
        iVar3 = this->Height + -1;
      }
      else {
        src_rect2.top = param_4->left;
        src_rect2.right = param_4->top;
        iVar5 = param_4->right;
        iVar3 = param_4->bottom;
      }
      src_rect2.bottom = iVar5 + 1;
      dest_rect2.left = iVar3 + 1;
      SetRect(&dest_rect2.top,param_2,param_3,(src_rect2.bottom - src_rect2.top) + param_2,
              (dest_rect2.left - src_rect2.right) + param_3);
      lVar2 = src_rect2.right;
      lVar1 = src_rect2.top;
      if (src_rect2.top < 0) {
        src_rect2.top = 0;
        dest_rect2.top = dest_rect2.top - lVar1;
      }
      if (src_rect2.right < 0) {
        src_rect2.right = 0;
        dest_rect2.right = dest_rect2.right - lVar2;
      }
      if (this->Width < src_rect2.bottom) {
        iVar5 = src_rect2.bottom - this->Width;
        src_rect2.bottom = src_rect2.bottom - iVar5;
        dest_rect2.bottom = dest_rect2.bottom - iVar5;
      }
      if (this->Height < dest_rect2.left) {
        iVar5 = dest_rect2.left - this->Height;
        dest_rect2.left = dest_rect2.left - iVar5;
        iStack_4 = iStack_4 - iVar5;
      }
      iVar5 = (param_1->ClipRect).left;
      if (dest_rect2.top < iVar5) {
        iVar5 = iVar5 - dest_rect2.top;
        dest_rect2.top = dest_rect2.top + iVar5;
        src_rect2.top = src_rect2.top + iVar5;
      }
      iVar5 = (param_1->ClipRect).top;
      if (dest_rect2.right < iVar5) {
        iVar5 = iVar5 - dest_rect2.right;
        dest_rect2.right = dest_rect2.right + iVar5;
        src_rect2.right = src_rect2.right + iVar5;
      }
      iVar5 = (param_1->ClipRect).right;
      if (iVar5 + 1 < dest_rect2.bottom) {
        iVar5 = (dest_rect2.bottom - iVar5) + -1;
        dest_rect2.bottom = dest_rect2.bottom - iVar5;
        src_rect2.bottom = src_rect2.bottom - iVar5;
      }
      iVar5 = (param_1->ClipRect).bottom;
      if (iVar5 + 1 < iStack_4) {
        iVar5 = (iStack_4 - iVar5) + -1;
        iStack_4 = iStack_4 - iVar5;
        dest_rect2.left = dest_rect2.left - iVar5;
      }
      if ((((dest_rect2.top < dest_rect2.bottom) && (dest_rect2.right < iStack_4)) &&
          (src_rect2.top < src_rect2.bottom)) && (src_rect2.right < dest_rect2.left)) {
        DAT_0062e64c._0_4_ = 1;
        if ((this->UseTrans == 0) || (param_5 == 0)) {
          DAT_0062e64c._0_4_ =
               (**(code **)((int)*param_1->DrawSurface + 0x14))
                         (param_1->DrawSurface,&dest_rect2.top,this->DrawSurface,&src_rect2.top,
                          0x1000000,0);
        }
        else {
          DAT_0062e64c._0_4_ =
               (**(code **)((int)*param_1->DrawSurface + 0x14))
                         (param_1->DrawSurface,&dest_rect2.top,this->DrawSurface,&src_rect2.top,
                          0x1008000,0);
        }
        DAT_0062e64c._4_4_ = 0;
        if ((int)DAT_0062e64c != 0) {
          DAT_0062e64c._4_4_ = TDrawSystem::GetBlitErrorNum(this->DrawSystem,(int)DAT_0062e64c);
        }
      }
    }
  }
  else if (((this->Bits != (uchar *)0x0) && (param_1 != (TDrawArea *)0x0)) &&
          (param_1->Bits != (uchar *)0x0)) {
    if (param_4 == (tagRECT *)0x0) {
      iVar3 = this->Width;
      iVar4 = this->Height;
      iVar6 = 0;
    }
    else {
      iVar6 = param_4->left;
      iVar5 = param_4->top;
      iVar3 = (param_4->right - iVar6) + 1;
      iVar4 = (param_4->bottom - iVar5) + 1;
    }
    if (this->Width < iVar3 + iVar6) {
      iVar3 = this->Width - iVar6;
    }
    if (this->Height < iVar4 + iVar5) {
      iVar4 = this->Height - iVar5;
    }
    if ((this->UseTrans != 0) && (param_5 != 0)) {
      TransDibBlt(param_1->BitmapInfo,param_1->Bits,&param_1->ClipRect,param_2,param_3,iVar3,iVar4,
                  this->BitmapInfo,this->Bits,(TRANSINFO *)0x0,iVar6,iVar5,iVar3,iVar4,1,0,0,
                  (uint)this->TransColor);
      DAT_0062e64c._4_4_ = 0;
      return;
    }
    DibBlt(param_1->BitmapInfo,param_1->Bits,&param_1->ClipRect,param_2,param_3,iVar3,iVar4,
           this->BitmapInfo,this->Bits,iVar6,iVar5,iVar3,iVar4,1,0,0);
    DAT_0062e64c._4_4_ = 0;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: PtrCopy
// Address: 004450c0
// [HELPER] s_PtrCopy1: "PtrCopy1"
// [HELPER] s_PtrCopy2: "PtrCopy2"
/* public: void __thiscall TDrawArea::PtrCopy(class TDrawArea *,long,long,struct tagRECT *) */

void __thiscall
TDrawArea::PtrCopy(TDrawArea *this,TDrawArea *param_1,long param_2,long param_3,tagRECT *param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void **ppvVar4;
  void **ppvVar5;
  uchar *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  void **SrcP;
  void **DestP;
  int XofS;
  int nWidth;
  int nLines;
  
  iVar1 = param_4->left;
  if (((((-1 < iVar1) && (iVar10 = param_4->right, iVar1 <= iVar10)) && (iVar10 < this->Width)) &&
      ((iVar2 = param_4->top, -1 < iVar2 && (iVar3 = param_4->bottom, iVar2 <= iVar3)))) &&
     (iVar3 < this->Height)) {
    nLines = (iVar3 - iVar2) + 1;
    nWidth = (iVar10 - iVar1) + 1;
    if (((-1 < param_2) && (iVar1 = param_1->Width, param_2 < iVar1)) &&
       ((-1 < param_3 && (iVar10 = param_1->Height, param_3 < iVar10)))) {
      if (iVar1 < nWidth + param_2) {
        nWidth = iVar1 - param_2;
      }
      if (iVar10 < nLines + param_3) {
        nLines = iVar10 - param_3;
      }
      if (((this->DrawSystem == (TDrawSystem *)0x0) || (this->DrawSystem->DrawType != '\x02')) ||
         ((puVar6 = Lock(this,s_PtrCopy1,1), puVar6 != (uchar *)0x0 &&
          (puVar6 = Lock(param_1,s_PtrCopy2,1), puVar6 != (uchar *)0x0)))) {
        iVar1 = param_4->left;
        param_4 = (tagRECT *)param_4->top;
        ppvVar4 = this->CurDisplayOffsets;
        ppvVar5 = param_1->CurDisplayOffsets;
        do {
                    /* Symbol Ref: {@symbol PtrCpyLoop} */
          puVar11 = (undefined4 *)((int)ppvVar4[(int)param_4] + iVar1);
          puVar12 = (undefined4 *)((int)ppvVar5[param_3] + param_2);
          uVar9 = -(int)puVar12 & 3;
          uVar7 = nWidth - uVar9;
          uVar8 = uVar7;
          if (uVar7 != 0 && (int)uVar9 <= nWidth) {
            for (; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
              puVar11 = (undefined4 *)((int)puVar11 + 1);
              puVar12 = (undefined4 *)((int)puVar12 + 1);
            }
            uVar8 = uVar7 & 3;
            for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar12 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar12 = puVar12 + 1;
            }
          }
                    /* Symbol Ref: {@symbol PtrCpyLEndBytes} */
          for (iVar10 = uVar9 + uVar8; iVar10 != 0; iVar10 = iVar10 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          param_4 = (tagRECT *)((int)&param_4->left + 1);
          param_3 = param_3 + 1;
          nLines = nLines + -1;
        } while (nLines != 0);
        if ((this->DrawSystem != (TDrawSystem *)0x0) && (this->DrawSystem->DrawType == '\x02')) {
          Unlock(this,s_PtrCopy1);
          Unlock(param_1,s_PtrCopy2);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: PtrSpanCopy
// Address: 00445250
// [HELPER] s_PtrSpanCopy: "PtrSpanCopy"
/* public: void __thiscall TDrawArea::PtrSpanCopy(class TDrawArea *,long,long,struct tagRECT
   *,unsigned char * *) */

void __thiscall
TDrawArea::PtrSpanCopy
          (TDrawArea *this,TDrawArea *param_1,long param_2,long param_3,tagRECT *param_4,
          uchar **param_5)
{
  int iVar1;
  void **ppvVar2;
  void **ppvVar3;
  void *pvVar4;
  void *pvVar5;
  long lVar6;
  tagRECT *ptVar7;
  uchar *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  void **SrcP;
  int XofS;
  void **DestP;
  
  ptVar7 = param_4;
  lVar6 = param_2;
  if (((((-1 < param_4->left) && (param_4->left <= param_4->right)) &&
       (param_4->right < this->Width)) &&
      ((((iVar1 = param_4->top, -1 < iVar1 && (iVar11 = param_4->bottom, iVar1 <= iVar11)) &&
        ((iVar11 < this->Height &&
         ((param_4 = (tagRECT *)((iVar11 - iVar1) + 1), -1 < param_2 && (param_2 < param_1->Width)))
         ))) && (-1 < param_3)))) && (iVar1 = param_1->Height, param_3 < iVar1)) {
    if (iVar1 < (int)&param_4->left + param_3) {
      param_4 = (tagRECT *)(iVar1 - param_3);
    }
    if (((this->DrawSystem == (TDrawSystem *)0x0) || (this->DrawSystem->DrawType != '\x02')) ||
       (puVar8 = Lock(param_1,s_PtrSpanCopy,1), puVar8 != (uchar *)0x0)) {
      iVar1 = ptVar7->left;
      ppvVar2 = this->CurDisplayOffsets;
      ppvVar3 = param_1->CurDisplayOffsets;
      param_2 = param_3;
      param_1 = (TDrawArea *)ptVar7->top;
      do {
                    /* Symbol Ref: {@symbol PtrSpanCpyLoop} */
        pvVar4 = ppvVar2[(int)param_1];
        pvVar5 = ppvVar3[param_2];
        for (puVar8 = param_5[(int)param_1]; puVar8 != (uchar *)0x0; puVar8 = *(uchar **)puVar8) {
                    /* Symbol Ref: {@symbol PtrSpanProc} */
          iVar11 = *(int *)(puVar8 + 8);
          puVar13 = (undefined4 *)((int)pvVar4 + iVar11 + iVar1);
          puVar14 = (undefined4 *)((int)pvVar5 + iVar11 + lVar6);
          iVar11 = (*(int *)(puVar8 + 0xc) - iVar11) + 1;
          uVar12 = -(int)puVar14 & 3;
          uVar9 = iVar11 - uVar12;
          uVar10 = uVar9;
          if (uVar9 != 0 && (int)uVar12 <= iVar11) {
            for (; uVar12 != 0; uVar12 = uVar12 - 1) {
              *(undefined1 *)puVar14 = *(undefined1 *)puVar13;
              puVar13 = (undefined4 *)((int)puVar13 + 1);
              puVar14 = (undefined4 *)((int)puVar14 + 1);
            }
            uVar10 = uVar9 & 3;
            for (uVar12 = uVar9 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar14 = *puVar13;
              puVar13 = puVar13 + 1;
              puVar14 = puVar14 + 1;
            }
          }
                    /* Symbol Ref: {@symbol PtrSpanCpyLEndBytes} */
          for (iVar11 = uVar12 + uVar10; iVar11 != 0; iVar11 = iVar11 + -1) {
            *(undefined1 *)puVar14 = *(undefined1 *)puVar13;
            puVar13 = (undefined4 *)((int)puVar13 + 1);
            puVar14 = (undefined4 *)((int)puVar14 + 1);
          }
        }
                    /* Symbol Ref: {@symbol PtrSpanSkip1} */
        param_1 = (TDrawArea *)((int)&param_1->DrawSystem + 1);
        param_2 = param_2 + 1;
        param_4 = (tagRECT *)((int)&param_4[-1].bottom + 3);
      } while (param_4 != (tagRECT *)0x0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: PtrSurfaceCopy
// Address: 004453a0
// [HELPER] s_PtrSurfaceCopy1: "PtrSurfaceCopy1"
// [HELPER] s_PtrSurfaceCopy2: "PtrSurfaceCopy2"
/* public: void __thiscall TDrawArea::PtrSurfaceCopy(class TDrawArea *,long,long,struct tagRECT
   *,int,int) */

void __thiscall
TDrawArea::PtrSurfaceCopy
          (TDrawArea *this,TDrawArea *param_1,long param_2,long param_3,tagRECT *param_4,int param_5
          ,int param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  void **ppvVar4;
  void **ppvVar5;
  uchar *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  void **SrcP;
  void **DestP;
  int nWidth;
  int XofS;
  int nLines;
  
  iVar1 = param_4->left;
  if (((((-1 < iVar1) && (iVar10 = param_4->right, iVar1 <= iVar10)) && (iVar10 < this->Width)) &&
      ((iVar2 = param_4->top, -1 < iVar2 && (iVar3 = param_4->bottom, iVar2 <= iVar3)))) &&
     (iVar3 < this->Height)) {
    nLines = (iVar3 - iVar2) + 1;
    nWidth = (iVar10 - iVar1) + 1;
    if (((-1 < param_2) && (iVar1 = param_1->Width, param_2 < iVar1)) &&
       ((-1 < param_3 && (iVar10 = param_1->Height, param_3 < iVar10)))) {
      if (iVar1 < nWidth + param_2) {
        nWidth = iVar1 - param_2;
      }
      if (iVar10 < nLines + param_3) {
        nLines = iVar10 - param_3;
      }
      if ((this->DrawSystem != (TDrawSystem *)0x0) && (this->DrawSystem->DrawType == '\x02')) {
        if ((param_5 != 0) && (puVar6 = Lock(this,s_PtrSurfaceCopy1,1), puVar6 == (uchar *)0x0)) {
          return;
        }
        if ((param_6 != 0) && (puVar6 = Lock(param_1,s_PtrSurfaceCopy2,1), puVar6 == (uchar *)0x0))
{
          if (param_5 == 0) {
            return;
          }
          Unlock(this,s_PtrSurfaceCopy1);
          return;
        }
      }
      ppvVar4 = this->CurDisplayOffsets;
      iVar1 = param_4->left;
      param_4 = (tagRECT *)param_4->top;
      ppvVar5 = param_1->CurDisplayOffsets;
      do {
                    /* Symbol Ref: {@symbol PtrSCpyLoop} */
        puVar11 = (undefined4 *)((int)ppvVar4[(int)param_4] + iVar1);
        puVar12 = (undefined4 *)((int)ppvVar5[param_3] + param_2);
        iVar10 = nWidth;
        if ((((uint)puVar11 ^ (uint)puVar12) & 3) == 0) {
          uVar9 = -(int)puVar12 & 3;
          uVar7 = nWidth - uVar9;
          uVar8 = uVar7;
          if (uVar7 != 0 && (int)uVar9 <= nWidth) {
            for (; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
              puVar11 = (undefined4 *)((int)puVar11 + 1);
              puVar12 = (undefined4 *)((int)puVar12 + 1);
            }
            uVar8 = uVar7 & 3;
            for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar12 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar12 = puVar12 + 1;
            }
          }
                    /* Symbol Ref: {@symbol PtrSCpyLEndBytes} */
          for (iVar10 = uVar9 + uVar8; iVar10 != 0; iVar10 = iVar10 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
        }
        else {
          for (; iVar10 != 0; iVar10 = iVar10 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
        }
                    /* Symbol Ref: {@symbol PtrSDone} */
        param_4 = (tagRECT *)((int)&param_4->left + 1);
        param_3 = param_3 + 1;
        nLines = nLines + -1;
      } while (nLines != 0);
      if ((this->DrawSystem != (TDrawSystem *)0x0) && (this->DrawSystem->DrawType == '\x02')) {
        if (param_5 != 0) {
          Unlock(this,s_PtrSurfaceCopy1);
        }
        if (param_6 != 0) {
          Unlock(param_1,s_PtrSurfaceCopy2);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: OverlayMemCopy
// Address: 00445580
// [HELPER] s_OverlayMemCopy: "OverlayMemCopy"
/* public: void __thiscall TDrawArea::OverlayMemCopy(struct tagRECT &,struct tagRECT
   &,int,int,int,int) */

void __thiscall
TDrawArea::OverlayMemCopy
          (TDrawArea *this,tagRECT *param_1,tagRECT *param_2,int param_3,int param_4,int param_5,
          int param_6)
{
  long *plVar1;
  long *plVar2;
  int iVar3;
  void **ppvVar4;
  bool bVar5;
  tagRECT *ptVar6;
  uchar *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int LineLen;
  int BackCopy;
  int SrcXStart;
  int DstXStart;
  int Lines;
  
  iVar8 = param_5;
  ptVar6 = param_2;
  if (((param_3 != 0) || (param_4 != 0)) &&
     ((this->DrawSystem == (TDrawSystem *)0x0 ||
      ((this->DrawSystem->DrawType != '\x02' ||
       (puVar7 = Lock(this,s_OverlayMemCopy,1), puVar7 != (uchar *)0x0)))))) {
    bVar5 = false;
    plVar1 = &param_1->bottom;
    iVar3 = param_1->top;
    plVar2 = &param_1->right;
    Lines = (*plVar1 - iVar3) + 1;
    SrcXStart = param_1->left + param_5;
    iVar9 = (*plVar2 - param_1->left) + 4 >> 2;
    DstXStart = param_5 + param_2->left;
    if (param_4 < 0) {
      param_1 = (tagRECT *)0xffffffff;
      param_5 = param_2->bottom + param_6;
      param_2 = (tagRECT *)(*plVar1 + param_6);
    }
    if (0 < param_4) {
      param_2 = (tagRECT *)(param_6 + iVar3);
      param_1 = (tagRECT *)0x1;
      param_5 = ptVar6->top + param_6;
    }
    if (param_4 == 0) {
      param_2 = (tagRECT *)(iVar3 + param_6);
      param_5 = ptVar6->top + param_6;
      param_1 = (tagRECT *)0x1;
      if (param_3 < 0) {
        bVar5 = true;
        SrcXStart = iVar8 + -3 + *plVar2;
        DstXStart = ptVar6->right + -3 + iVar8;
      }
    }
    ppvVar4 = this->CurDisplayOffsets;
    if (bVar5) {
      do {
                    /* Symbol Ref: {@symbol OverlayCpyLoop2} */
        puVar10 = (undefined4 *)((int)ppvVar4[(int)param_2] + SrcXStart);
        puVar11 = (undefined4 *)((int)ppvVar4[param_5] + DstXStart);
        for (iVar8 = iVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + -1;
          puVar11 = puVar11 + -1;
        }
        param_2 = (tagRECT *)((int)&param_1->left + (int)&param_2->left);
        param_5 = (int)&param_1->left + param_5;
        Lines = Lines + -1;
      } while (Lines != 0);
    }
    else {
      do {
                    /* Symbol Ref: {@symbol OverlayCpyLoop1} */
        puVar10 = (undefined4 *)((int)ppvVar4[(int)param_2] + SrcXStart);
        puVar11 = (undefined4 *)((int)ppvVar4[param_5] + DstXStart);
        for (iVar8 = iVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        param_2 = (tagRECT *)((int)&param_1->left + (int)&param_2->left);
        param_5 = (int)&param_1->left + param_5;
        Lines = Lines + -1;
      } while (Lines != 0);
    }
    if ((this->DrawSystem != (TDrawSystem *)0x0) && (this->DrawSystem->DrawType == '\x02')) {
      Unlock(this,s_OverlayMemCopy);
    }
  }
  return;
}

// --------------------------------------------------

// Function: SetTrans
// Address: 00445710
/* WARNING: Variable defined which should be unmapped: ddck */
/* public: void __thiscall TDrawArea::SetTrans(int,unsigned char) */

void __thiscall TDrawArea::SetTrans(TDrawArea *this,int param_1,uchar param_2)
{
  IDirectDrawSurface *pIVar1;
  _DDCOLORKEY ddck;
  
  ddck.dwColorSpaceLowValue = (ulong)&ddck.dwColorSpaceHighValue;
  this->UseTrans = param_1;
  if (param_1 == 0) {
    this->TransColor = 0xff;
  }
  else {
    this->TransColor = param_2;
    pIVar1 = this->DrawSurface;
    if (((pIVar1 != (IDirectDrawSurface *)0x0) && (this->DrawSystem != (TDrawSystem *)0x0)) &&
       (this->DrawSystem->DrawType == '\x02')) {
      ddck.dwColorSpaceHighValue = (ulong)this->TransColor;
      (**(code **)((int)*pIVar1 + 0x74))(pIVar1,8,&ddck.dwColorSpaceHighValue);
    }
  }
  return;
}

// --------------------------------------------------

// Function: SetOverlayTrans
// Address: 00445780
/* WARNING: Variable defined which should be unmapped: ddck */
/* public: void __thiscall TDrawArea::SetOverlayTrans(int,unsigned char) */

void __thiscall TDrawArea::SetOverlayTrans(TDrawArea *this,int param_1,uchar param_2)
{
  IDirectDrawSurface *pIVar1;
  _DDCOLORKEY ddck;
  
  ddck.dwColorSpaceLowValue = (ulong)&ddck.dwColorSpaceHighValue;
  this->UseTrans = param_1;
  this->TransColor = param_2;
  if ((((param_1 != 0) && (pIVar1 = this->DrawSurface, pIVar1 != (IDirectDrawSurface *)0x0)) &&
      (this->DrawSystem != (TDrawSystem *)0x0)) && (this->DrawSystem->DrawType == '\x02')) {
    ddck.dwColorSpaceHighValue = (ulong)param_2;
    (**(code **)((int)*pIVar1 + 0x74))(pIVar1,0x10,&ddck.dwColorSpaceHighValue);
  }
  return;
}

// --------------------------------------------------

// Function: SetPixel
// Address: 004457e0
/* public: void __thiscall TDrawArea::SetPixel(long,long,unsigned char) */

void __thiscall TDrawArea::SetPixel(TDrawArea *this,long param_1,long param_2,uchar param_3)
{
  uchar *puVar1;
  
  puVar1 = this->Bits;
  if ((((puVar1 != (uchar *)0x0) && ((this->ClipRect).left <= param_1)) &&
      (param_1 <= (this->ClipRect).right)) &&
     (((this->ClipRect).top <= param_2 && (param_2 <= (this->ClipRect).bottom)))) {
    if (this->Orien == 1) {
      puVar1[this->Pitch * param_2 + param_1] = param_3;
      return;
    }
    puVar1[((this->Height - param_2) + -1) * this->Pitch + param_1] = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: DrawLine
// Address: 00445840
/* public: void __thiscall TDrawArea::DrawLine(int,int,int,int,unsigned char) */

void __thiscall
TDrawArea::DrawLine(TDrawArea *this,int param_1,int param_2,int param_3,int param_4,uchar param_5)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = param_4;
  iVar6 = param_3;
  if (param_1 == param_3) {
    iVar6 = param_2;
    if ((param_2 <= param_4) ||
       (bVar1 = param_4 <= param_2, iVar6 = param_4, param_4 = param_2, bVar1)) {
      do {
        _ASMDraw_HLine(param_1,param_3,iVar6,param_5);
        iVar6 = iVar6 + 1;
      } while (iVar6 <= param_4);
    }
  }
  else {
    if (param_2 == param_4) {
      _ASMDraw_HLine(param_1,param_3,param_2,param_5);
      return;
    }
    iVar5 = param_1;
    if (param_3 < param_1) {
      param_3 = param_1;
      param_4 = param_2;
      param_2 = iVar2;
      iVar5 = iVar6;
    }
    iVar6 = (param_3 - iVar5) + 1;
    if (param_2 < param_4) {
      iVar2 = param_4 - param_2;
      param_1 = 1;
    }
    else {
      iVar2 = param_2 - param_4;
      param_1 = -1;
    }
    iVar2 = iVar2 + 1;
    if (iVar2 <= iVar6) {
      iVar3 = 0;
      iVar4 = iVar5;
      for (; iVar5 < param_3; iVar5 = iVar5 + 1) {
        iVar3 = iVar3 + iVar2;
        if (iVar6 <= iVar3) {
          _ASMDraw_HLine(iVar4,iVar5,param_2,param_5);
          param_2 = param_2 + param_1;
          iVar3 = iVar3 - iVar6;
          iVar4 = iVar5 + 1;
        }
      }
      _ASMDraw_HLine(iVar4,iVar5,param_2,param_5);
      return;
    }
    iVar4 = 0;
    for (; _ASMDraw_HLine(iVar5,iVar5,param_2,param_5), param_2 != param_4;
        param_2 = param_2 + param_1) {
      iVar4 = iVar4 + iVar6;
      if (iVar2 <= iVar4) {
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 - iVar2;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: DrawRect
// Address: 004459a0
/* public: void __thiscall TDrawArea::DrawRect(long,long,long,long,unsigned char) */

void __thiscall
TDrawArea::DrawRect(TDrawArea *this,long param_1,long param_2,long param_3,long param_4,
                   uchar param_5)
{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = param_4;
  lVar1 = param_3;
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = lVar1;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = lVar2;
  }
  iVar4 = (param_3 - param_1) + 1;
  if ((0 < iVar4) && (iVar3 = (param_4 - param_2) + 1, 0 < iVar3)) {
    DrawHorzLine(this,param_1,param_2,iVar4,param_5);
    DrawHorzLine(this,param_1,param_4,iVar4,param_5);
    DrawVertLine(this,param_1,param_2,iVar3,param_5);
    DrawVertLine(this,param_3,param_2,iVar3,param_5);
  }
  return;
}

// --------------------------------------------------

// Function: DrawRect
// Address: 00445a40
/* public: void __thiscall TDrawArea::DrawRect(struct tagRECT *,unsigned char) */

void __thiscall TDrawArea::DrawRect(TDrawArea *this,tagRECT *param_1,uchar param_2)
{
  DrawRect(this,param_1->left,param_1->top,param_1->right,param_1->bottom,param_2);
  return;
}

// --------------------------------------------------

// Function: DrawHorzLine
// Address: 00445a60
/* public: void __thiscall TDrawArea::DrawHorzLine(long,long,long,unsigned char) */

void __thiscall
TDrawArea::DrawHorzLine(TDrawArea *this,long param_1,long param_2,long param_3,uchar param_4)
{
  int iVar1;
  int iVar2;
  
  if ((((this->Bits != (uchar *)0x0) && (iVar2 = (this->ClipRect).right, param_1 <= iVar2)) &&
      ((this->ClipRect).top <= param_2)) && (param_2 <= (this->ClipRect).bottom)) {
    iVar1 = (this->ClipRect).left;
    if (param_1 < iVar1) {
      param_3 = param_3 + (param_1 - iVar1);
      param_1 = iVar1;
    }
    if (iVar2 < param_3 + -1 + param_1) {
      param_3 = (iVar2 - param_1) + 1;
    }
    if (0 < param_3) {
      if (this->Orien == 1) {
        iVar2 = this->Pitch * param_2;
      }
      else {
        iVar2 = ((this->Height - param_2) + -1) * this->Pitch;
      }
      memset(this->Bits + iVar2 + param_1,param_4,param_3);
    }
  }
  return;
}

// --------------------------------------------------

// Function: DrawVertLine
// Address: 00445af0
/* public: void __thiscall TDrawArea::DrawVertLine(long,long,long,unsigned char) */

void __thiscall
TDrawArea::DrawVertLine(TDrawArea *this,long param_1,long param_2,long param_3,uchar param_4)
{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  
  if ((((this->Bits != (uchar *)0x0) && ((this->ClipRect).left <= param_1)) &&
      (param_1 <= (this->ClipRect).right)) && (iVar3 = (this->ClipRect).bottom, param_2 <= iVar3)) {
    iVar2 = (this->ClipRect).top;
    if (param_2 < iVar2) {
      param_3 = param_3 + (param_2 - iVar2);
      param_2 = iVar2;
    }
    if (iVar3 < param_3 + -1 + param_2) {
      param_3 = (iVar3 - param_2) + 1;
    }
    if (0 < param_3) {
      if (this->Orien == 1) {
        iVar3 = this->Pitch;
        iVar2 = param_2 * iVar3;
      }
      else {
        iVar2 = ((this->Height - param_2) + -1) * this->Pitch;
        iVar3 = -this->Pitch;
      }
      puVar1 = this->Bits + iVar2 + param_1;
      if (0 < param_3) {
        do {
          *puVar1 = param_4;
          puVar1 = puVar1 + iVar3;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FillRect
// Address: 00445b80
/* public: void __thiscall TDrawArea::FillRect(long,long,long,long,unsigned char) */

void __thiscall
TDrawArea::FillRect(TDrawArea *this,long param_1,long param_2,long param_3,long param_4,
                   uchar param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  
  if (this->Bits != (uchar *)0x0) {
    iVar2 = param_3;
    if (param_3 < param_1) {
      iVar2 = param_1;
      param_1 = param_3;
    }
    iVar1 = param_2;
    if (param_4 < param_2) {
      iVar1 = param_4;
      param_4 = param_2;
    }
    if ((((param_1 <= (this->ClipRect).right) && (iVar4 = (this->ClipRect).left, iVar4 <= iVar2)) &&
        (iVar1 <= (this->ClipRect).bottom)) && (iVar3 = (this->ClipRect).top, iVar3 <= param_4)) {
      if (param_1 < iVar4) {
        param_1 = iVar4;
      }
      iVar4 = (this->ClipRect).right;
      if (iVar4 < iVar2) {
        iVar2 = iVar4;
      }
      if (iVar1 < iVar3) {
        iVar1 = iVar3;
      }
      iVar4 = (this->ClipRect).bottom;
      if (iVar4 < param_4) {
        param_4 = iVar4;
      }
      iVar4 = (iVar2 - param_1) + 1;
      iVar2 = (param_4 - iVar1) + 1;
      if ((0 < iVar4) && (0 < iVar2)) {
        if (this->Orien == 1) {
          iVar3 = this->Pitch;
          iVar1 = iVar1 * iVar3;
        }
        else {
          iVar1 = ((this->Height - iVar1) + -1) * this->Pitch;
          iVar3 = -this->Pitch;
        }
        puVar5 = this->Bits + iVar1 + param_1;
        if (0 < iVar2) {
          do {
            memset(puVar5,param_5,iVar4);
            puVar5 = puVar5 + iVar3;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: DrawBevel
// Address: 00445c70
/* public: void __thiscall TDrawArea::DrawBevel(long,long,long,long,unsigned char,unsigned char) */

void __thiscall
TDrawArea::DrawBevel
          (TDrawArea *this,long param_1,long param_2,long param_3,long param_4,uchar param_5,
          uchar param_6)
{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = param_4;
  lVar1 = param_3;
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = lVar1;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = lVar2;
  }
  iVar4 = (param_3 - param_1) + 1;
  if ((0 < iVar4) && (iVar3 = param_4 - param_2, 0 < iVar3 + 1)) {
    DrawHorzLine(this,param_1 + 1,param_2,param_3 - param_1,param_5);
    DrawVertLine(this,param_3,param_2 + 1,iVar3,param_5);
    DrawHorzLine(this,param_1,param_4,iVar4,param_6);
    DrawVertLine(this,param_1,param_2,iVar3,param_6);
  }
  return;
}

// --------------------------------------------------

// Function: DrawBevel2
// Address: 00445d20
/* public: void __thiscall TDrawArea::DrawBevel2(long,long,long,long,unsigned char,unsigned
   char,unsigned char,unsigned char) */

void __thiscall
TDrawArea::DrawBevel2
          (TDrawArea *this,long param_1,long param_2,long param_3,long param_4,uchar param_5,
          uchar param_6,uchar param_7,uchar param_8)
{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  lVar3 = param_4;
  lVar2 = param_1;
  if (param_3 < param_1) {
    param_1 = param_3;
    param_3 = lVar2;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = lVar3;
  }
  iVar5 = param_3 - param_1;
  if ((0 < iVar5 + 1) && (iVar6 = param_4 - param_2, 0 < iVar6 + 1)) {
    iVar4 = param_1 + 1;
    DrawHorzLine(this,iVar4,param_2,iVar5,param_5);
    iVar1 = param_2 + 1;
    DrawVertLine(this,param_3,iVar1,iVar6 + -1,param_5);
    DrawHorzLine(this,param_1 + 2,iVar1,iVar5 + -2,param_6);
    DrawVertLine(this,param_3 + -1,param_2 + 2,iVar6 + -3,param_6);
    DrawHorzLine(this,param_1,param_4,iVar5 + 1,param_8);
    DrawVertLine(this,param_1,param_2,iVar6,param_8);
    DrawHorzLine(this,iVar4,param_4 + -1,iVar5 + -1,param_7);
    DrawVertLine(this,iVar4,iVar1,iVar6 + -2,param_7);
  }
  return;
}

// --------------------------------------------------

// Function: DrawBevel3
// Address: 00445e40
/* public: void __thiscall TDrawArea::DrawBevel3(long,long,long,long,unsigned char,unsigned
   char,unsigned char,unsigned char,unsigned char,unsigned char) */

void __thiscall
TDrawArea::DrawBevel3
          (TDrawArea *this,long param_1,long param_2,long param_3,long param_4,uchar param_5,
          uchar param_6,uchar param_7,uchar param_8,uchar param_9,uchar param_10)
{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  lVar5 = param_4;
  lVar4 = param_1;
  if (param_3 < param_1) {
    param_1 = param_3;
    param_3 = lVar4;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = lVar5;
  }
  iVar7 = param_3 - param_1;
  if ((0 < iVar7 + 1) && (iVar8 = param_4 - param_2, 0 < iVar8 + 1)) {
    iVar6 = param_1 + 1;
    DrawHorzLine(this,iVar6,param_2,iVar7,param_5);
    iVar1 = param_2 + 1;
    DrawVertLine(this,param_3,iVar1,iVar8 + -1,param_5);
    iVar2 = param_1 + 2;
    DrawHorzLine(this,iVar2,iVar1,iVar7 + -2,param_6);
    iVar3 = param_2 + 2;
    DrawVertLine(this,param_3 + -1,iVar3,iVar8 + -3,param_6);
    DrawHorzLine(this,param_1 + 3,iVar3,iVar7 + -4,param_7);
    DrawVertLine(this,param_3 + -2,param_2 + 3,iVar8 + -5,param_7);
    DrawHorzLine(this,param_1,param_4,iVar7 + 1,param_10);
    DrawVertLine(this,param_1,param_2,iVar8,param_10);
    DrawHorzLine(this,iVar6,param_4 + -1,iVar7 + -1,param_9);
    DrawVertLine(this,iVar6,iVar1,iVar8 + -2,param_9);
    DrawHorzLine(this,iVar2,param_4 + -2,iVar7 + -3,param_8);
    DrawVertLine(this,iVar2,iVar3,iVar8 + -4,param_8);
  }
  return;
}

// --------------------------------------------------

// Function: DrawBevel21
// Address: 00445fe0
/* public: void __thiscall TDrawArea::DrawBevel21(long,long,long,long,unsigned char,unsigned
   char,unsigned char,unsigned char) */

void __thiscall
TDrawArea::DrawBevel21
          (TDrawArea *this,long param_1,long param_2,long param_3,long param_4,uchar param_5,
          uchar param_6,uchar param_7,uchar param_8)
{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = param_4;
  lVar1 = param_1;
  if (param_3 < param_1) {
    param_1 = param_3;
    param_3 = lVar1;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = lVar2;
  }
  iVar4 = param_3 - param_1;
  if ((0 < iVar4 + 1) && (iVar3 = param_4 - param_2, 0 < iVar3 + 1)) {
    DrawHorzLine(this,param_1 + 1,param_2,iVar4,param_5);
    DrawVertLine(this,param_3,param_2 + 1,iVar3 + -1,param_5);
    DrawHorzLine(this,param_1 + 1,param_2 + 1,iVar4 + -1,param_6);
    DrawVertLine(this,param_3 + -1,param_2 + 2,iVar3 + -2,param_6);
    DrawHorzLine(this,param_1,param_4,iVar4 + 1,param_8);
    DrawVertLine(this,param_1,param_2,iVar3,param_8);
  }
  return;
}

// --------------------------------------------------

// Function: DrawBevel32
// Address: 004460c0
/* public: void __thiscall TDrawArea::DrawBevel32(long,long,long,long,unsigned char,unsigned
   char,unsigned char,unsigned char,unsigned char,unsigned char) */

void __thiscall
TDrawArea::DrawBevel32
          (TDrawArea *this,long param_1,long param_2,long param_3,long param_4,uchar param_5,
          uchar param_6,uchar param_7,uchar param_8,uchar param_9,uchar param_10)
{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  lVar3 = param_4;
  lVar2 = param_1;
  if (param_3 < param_1) {
    param_1 = param_3;
    param_3 = lVar2;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = lVar3;
  }
  iVar5 = param_3 - param_1;
  if ((0 < iVar5 + 1) && (iVar6 = param_4 - param_2, 0 < iVar6 + 1)) {
    iVar4 = param_1 + 1;
    DrawHorzLine(this,iVar4,param_2,iVar5,param_5);
    iVar1 = param_2 + 1;
    DrawVertLine(this,param_3,iVar1,iVar6 + -1,param_5);
    DrawHorzLine(this,param_1 + 2,iVar1,iVar5 + -2,param_6);
    DrawVertLine(this,param_3 + -1,param_2 + 2,iVar6 + -3,param_6);
    DrawHorzLine(this,param_1 + 2,param_2 + 2,iVar5 + -3,param_7);
    DrawVertLine(this,param_3 + -2,param_2 + 3,iVar6 + -4,param_7);
    DrawHorzLine(this,param_1,param_4,iVar5 + 1,param_10);
    DrawVertLine(this,param_1,param_2,iVar6,param_10);
    DrawHorzLine(this,iVar4,param_4 + -1,iVar5 + -1,param_9);
    DrawVertLine(this,iVar4,iVar1,iVar6 + -2,param_9);
  }
  return;
}

// --------------------------------------------------

// Function: SetShadowTable
// Address: 00446220
/* public: void __thiscall TDrawArea::SetShadowTable(class RGE_Color_Table *) */

void __thiscall TDrawArea::SetShadowTable(TDrawArea *this,RGE_Color_Table *param_1)
{
  this->shadow_color_table = param_1;
  return;
}

// --------------------------------------------------

// Function: DrawShadowBox
// Address: 00446230
/* public: void __thiscall TDrawArea::DrawShadowBox(long,long,long,long) */

void __thiscall
TDrawArea::DrawShadowBox(TDrawArea *this,long param_1,long param_2,long param_3,long param_4)
{
  RGE_Color_Table *pRVar1;
  int iVar2;
  long lVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  
  if ((this->shadow_color_table != (RGE_Color_Table *)0x0) && (this->Bits != (uchar *)0x0)) {
    iVar6 = (this->ClipRect).left;
    if (param_1 < iVar6) {
      param_1 = iVar6;
    }
    iVar6 = (this->ClipRect).top;
    if (param_2 < iVar6) {
      param_2 = iVar6;
    }
    iVar6 = (this->ClipRect).right;
    if (iVar6 < param_3) {
      param_3 = iVar6;
    }
    iVar6 = (this->ClipRect).bottom;
    if (iVar6 < param_4) {
      param_4 = iVar6;
    }
    if (param_1 < 0) {
      param_1 = 0;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (this->Width <= param_3) {
      param_3 = this->Width + -1;
    }
    if (this->Height <= param_4) {
      param_4 = this->Height + -1;
    }
    if ((param_1 <= param_3) && (param_2 <= param_4)) {
      iVar6 = this->Orien;
      lVar3 = AlignedWidth(this);
      iVar7 = lVar3 * iVar6;
      iVar2 = param_2;
      if (iVar6 < 1) {
        iVar2 = (param_2 - this->Height) + 1;
      }
      pRVar1 = this->shadow_color_table;
      pbVar4 = this->Bits + iVar2 * iVar7 + param_1;
      pbVar8 = pbVar4 + (param_3 - param_1);
      if (param_2 <= param_4) {
        iVar6 = (param_4 - param_2) + 1;
        pbVar5 = pbVar4;
        do {
          for (; pbVar4 <= pbVar8; pbVar4 = pbVar4 + 1) {
            *pbVar4 = pRVar1->table[*pbVar4];
          }
          pbVar4 = pbVar5 + iVar7;
          pbVar8 = pbVar8 + iVar7;
          iVar6 = iVar6 + -1;
          pbVar5 = pbVar4;
        } while (iVar6 != 0);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: GetPalette
// Address: 00446340
/* public: void __thiscall TDrawArea::GetPalette(struct tagPALETTEENTRY *) */

void __thiscall TDrawArea::GetPalette(TDrawArea *this,tagPALETTEENTRY *param_1)
{
  tagPALETTEENTRY *ptVar1;
  int iVar2;
  
  iVar2 = 0x100;
  ptVar1 = param_1;
  do {
    iVar2 = iVar2 + -1;
    *ptVar1 = *(tagPALETTEENTRY *)
               ((int)this->DrawSystem + (0x74 - (int)param_1) + (int)(ptVar1 + 1));
    ptVar1 = ptVar1 + 1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: SetPalette
// Address: 00446370
/* public: void __thiscall TDrawArea::SetPalette(struct tagPALETTEENTRY *) */

void __thiscall TDrawArea::SetPalette(TDrawArea *this,tagPALETTEENTRY *param_1)
{
  param_1->peRed = '\0';
  param_1->peGreen = '\0';
  param_1->peBlue = '\0';
  param_1->peFlags = '\0';
  param_1[0xff].peRed = 0xff;
  param_1[0xff].peGreen = 0xff;
  param_1[0xff].peBlue = 0xff;
  param_1[0xff].peFlags = '\0';
  TDrawSystem::ModifyPalette(this->DrawSystem,0,0x100,param_1);
  return;
}

// --------------------------------------------------

// Function: take_snapshot
// Address: 004463b0
// [HELPER] s_C__AOE__03d_BMP: "C:\AOE_%03d.BMP"
// [HELPER] s_take_snapshot: "take_snapshot"
/* WARNING: Variable defined which should be unmapped: bmWide */
/* public: void __thiscall TDrawArea::take_snapshot(char *,int &) */

void __thiscall TDrawArea::take_snapshot(TDrawArea *this,char *param_1,int *param_2)
{
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  char *pcVar10;
  int bmWide;
  tagBITMAPFILEHEADER bmFH;
  tagBITMAPINFOHEADER bmIH;
  char BMPFile [60];
  tagRGBQUAD bmPAL [256];
  tagPALETTEENTRY thePal [256];
  
  bmIH.biHeight = this->Width;
  bmFH._0_4_ = this->Height;
  uVar9 = bmIH.biHeight + 3U & 0xfffc;
  bmFH._6_4_ = bmFH._0_4_ * uVar9 + 0x436;
  bmFH.bfSize._2_2_ = 0x4d42;
  bmFH.bfOffBits._0_2_ = 0;
  bmFH.bfOffBits._2_2_ = 0;
  bmIH.biWidth = 0x28;
  bmIH.biCompression._0_2_ = 1;
  bmIH.biCompression._2_2_ = 8;
  bmIH.biSizeImage = 0;
  bmIH.biXPelsPerMeter = 0;
  bmIH.biYPelsPerMeter = 0;
  bmIH.biClrUsed = 0;
  bmIH.biClrImportant = 0;
  BMPFile[0] = '\0';
  BMPFile[1] = '\0';
  BMPFile[2] = '\0';
  BMPFile[3] = '\0';
  bmIH._12_4_ = bmFH._0_4_;
  GetPalette(this,thePal + 1);
  iVar4 = 0;
  do {
    uVar1 = (&thePal[1].peGreen)[iVar4];
    (&bmPAL[1].rgbBlue)[iVar4] = (&thePal[1].peBlue)[iVar4];
    uVar2 = (&thePal[1].peRed)[iVar4];
    (&bmPAL[1].rgbGreen)[iVar4] = uVar1;
    (&bmPAL[1].rgbRed)[iVar4] = uVar2;
    (&bmPAL[1].rgbReserved)[iVar4] = '\0';
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x400);
  iVar4 = 0;
  while( true ) {
    if (param_1 == (char *)0x0) {
      iVar5 = *param_2;
      pcVar10 = s_C__AOE__03d_BMP;
    }
    else {
      iVar5 = *param_2;
      pcVar10 = param_1;
    }
    sprintf(BMPFile + 4,pcVar10,iVar5);
    iVar4 = iVar4 + 1;
    iVar5 = __open(BMPFile + 4,0);
    if (iVar5 == -1) break;
    *param_2 = *param_2 + 1;
    close(iVar5);
    if (1000 < iVar4) {
      return;
    }
  }
  iVar4 = malloc(uVar9);
  iVar5 = __open(BMPFile + 4,0x8301,0x180);
  if (iVar5 != -1) {
    write(iVar5,(undefined1 *)((int)&bmFH.bfSize + 2),0xe);
    write(iVar5,&bmIH.biWidth,0x28);
    write(iVar5,bmPAL + 1,0x400);
    puVar6 = Lock(this,s_take_snapshot,1);
    iVar3 = bmFH._0_4_;
    if (puVar6 != (uchar *)0x0) {
      while (iVar3 = iVar3 + -1, -1 < iVar3) {
        iVar7 = 0;
        puVar8 = (undefined1 *)this->CurDisplayOffsets[iVar3];
        if (0 < this->Width) {
          do {
            *(undefined1 *)(iVar7 + iVar4) = *puVar8;
            iVar7 = iVar7 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar7 < this->Width);
        }
        write(iVar5,iVar4,uVar9);
      }
      Unlock(this,s_take_snapshot);
    }
    close(iVar5);
  }
  free(iVar4);
  return;
}

// --------------------------------------------------


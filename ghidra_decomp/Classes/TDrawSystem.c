// Class: TDrawSystem
// Size:  0x47C
//
// Member Layout:
// [0x000] void * Inst
// [0x004] void * Wnd
// [0x008] void * Pal
// [0x00C] TDrawArea * DrawArea
// [0x010] TDrawArea * PrimaryArea
// [0x014] DrawAreaNode * DrawAreaList
// [0x018] IDirectDraw * DirDraw
// [0x01C] IDirectDrawSurface * PrimarySurface
// [0x020] IDirectDrawClipper * Clipper
// [0x024] IDirectDrawPalette * DirDrawPal
// [0x028] ulong Flags
// [0x02C] int ScreenWidth
// [0x030] int ScreenHeight
// [0x034] int ColorBits
// [0x038] int ErrorCode
// [0x03C] int ChangedMode
// [0x040] int IsBanked
// [0x044] int CanSrcBlt
// [0x048] int Restored
// [0x04C] int ModeAvail640
// [0x050] int ModeAvail800
// [0x054] int ModeAvail1024
// [0x058] int ModeAvail1280
// [0x05C] int ModeAvail320_200
// [0x060] int ModeAvail320_240
// [0x064] int ModeAvail320_200_16
// [0x068] int ModeAvail320_240_16
// [0x06C] int ModeAvail640_16
// [0x070] int ModeAvail800_16
// [0x074] int ModeAvail1024_16
// [0x078] tagPALETTEENTRY[256] palette (sz: 0x400)
// [0x478] uchar DrawType
// [0x479] uchar ScreenMode
// ----------------------------------------------------------------

// Function: TDrawSystem
// Address: 00442680
/* public: __thiscall TDrawSystem::TDrawSystem(void) */

TDrawSystem * __thiscall TDrawSystem::TDrawSystem(TDrawSystem *this)
{
  this->Inst = (void *)0x0;
  this->Wnd = (void *)0x0;
  this->Pal = (void *)0x0;
  this->DrawArea = (TDrawArea *)0x0;
  this->PrimaryArea = (TDrawArea *)0x0;
  this->DirDraw = (IDirectDraw *)0x0;
  this->PrimarySurface = (IDirectDrawSurface *)0x0;
  this->Clipper = (IDirectDrawClipper *)0x0;
  this->DirDrawPal = (IDirectDrawPalette *)0x0;
  this->ChangedMode = 0;
  this->DrawType = '\0';
  this->ScreenMode = '\0';
  this->ScreenWidth = 0;
  this->ScreenHeight = 0;
  this->ColorBits = 8;
  this->Flags = 0;
  this->IsBanked = 0;
  this->CanSrcBlt = 0;
  this->DrawAreaList = (DrawAreaNode *)0x0;
  this->Restored = 0;
  this->ModeAvail640 = 0;
  this->ModeAvail800 = 0;
  this->ModeAvail1024 = 0;
  this->ModeAvail1280 = 0;
  this->ModeAvail320_200 = 0;
  this->ModeAvail320_240 = 0;
  this->ModeAvail320_200_16 = 0;
  this->ModeAvail320_240_16 = 0;
  this->ModeAvail640_16 = 0;
  this->ModeAvail800_16 = 0;
  this->ModeAvail1024_16 = 0;
  this->ErrorCode = 0;
  system_ignore_size_messages = 0;
  _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
  return this;
}

// --------------------------------------------------

// Function: ~TDrawSystem
// Address: 00442710
/* WARNING: Variable defined which should be unmapped: ddbltfx */
/* public: __thiscall TDrawSystem::~TDrawSystem(void) */

void __thiscall TDrawSystem::~TDrawSystem(TDrawSystem *this)
{
  IDirectDrawSurface *pIVar1;
  IDirectDrawPalette *pIVar2;
  IDirectDrawClipper *pIVar3;
  _DDBLTFX ddbltfx;
  
  if ((this->ScreenMode == '\x02') &&
     (pIVar1 = this->PrimarySurface, pIVar1 != (IDirectDrawSurface *)0x0)) {
    ddbltfx.dwDDFX = 100;
    ddbltfx.ddckDestColorkey.dwColorSpaceLowValue = 0;
    (**(code **)((int)*pIVar1 + 0x14))(pIVar1,0,0,0,0x1000400,&ddbltfx.dwDDFX);
  }
  DeleteSurfaces(this);
  if (this->DirDraw != (IDirectDraw *)0x0) {
    pIVar2 = this->DirDrawPal;
    if (pIVar2 != (IDirectDrawPalette *)0x0) {
      (**(code **)((int)*pIVar2 + 8))(pIVar2);
      this->DirDrawPal = (IDirectDrawPalette *)0x0;
    }
    pIVar3 = this->Clipper;
    if (pIVar3 != (IDirectDrawClipper *)0x0) {
      (**(code **)((int)*pIVar3 + 8))(pIVar3);
      this->Clipper = (IDirectDrawClipper *)0x0;
    }
    if (this->ChangedMode != 0) {
      (**(code **)((int)*this->DirDraw + 0x4c))(this->DirDraw);
      this->ChangedMode = 0;
    }
    (**(code **)((int)*this->DirDraw + 8))(this->DirDraw);
    this->DirDraw = (IDirectDraw *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: CheckAvailModes
// Address: 004427a0
// [HELPER] s_DISPLAY: "DISPLAY"
/* public: void __thiscall TDrawSystem::CheckAvailModes(int) */

void __thiscall TDrawSystem::CheckAvailModes(TDrawSystem *this,int param_1)
{
  IDirectDraw **ppIVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    this->ModeAvail640 = 1;
    iVar3 = CreateICA(s_DISPLAY,0,0,0);
    if (iVar3 != 0) {
      iVar4 = GetDeviceCaps(iVar3,8);
      GetDeviceCaps(iVar3,10);
      DeleteDC(iVar3);
      if (799 < iVar4) {
        this->ModeAvail800 = 1;
      }
      if (0x3ff < iVar4) {
        this->ModeAvail1024 = 1;
      }
      if (0x4ff < iVar4) {
        this->ModeAvail1280 = 1;
        return;
      }
    }
  }
  else {
    ppIVar1 = &this->DirDraw;
    if (this->DirDraw == (IDirectDraw *)0x0) {
      iVar3 = _DirectDrawCreate_12(0,ppIVar1,0);
      if (iVar3 != 0) {
        return;
      }
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    (**(code **)((int)**ppIVar1 + 0x20))(*ppIVar1,0,0,this,CheckAvailModesCallback);
    if (!bVar2) {
      (**(code **)((int)**ppIVar1 + 8))(*ppIVar1);
      *ppIVar1 = (IDirectDraw *)0x0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: CheckAvailModesCallback
// Address: 00442860
/* public: static long __stdcall TDrawSystem::CheckAvailModesCallback(struct _DDSURFACEDESC *,void
   *) */

long TDrawSystem::CheckAvailModesCallback(_DDSURFACEDESC *param_1,void *param_2)
{
  ulong uVar1;
  long lVar2;
  
  lVar2 = 1;
  uVar1 = (param_1->ddpfPixelFormat).field3_0xc.dwRGBBitCount;
  if (uVar1 == 8) {
    uVar1 = param_1->dwWidth;
    if ((uVar1 == 0x280) && (param_1->dwHeight == 0x1e0)) {
      *(undefined4 *)((int)param_2 + 0x4c) = 1;
      return lVar2;
    }
    if ((uVar1 == 800) && (param_1->dwHeight == 600)) {
      *(undefined4 *)((int)param_2 + 0x50) = 1;
      return lVar2;
    }
    if ((uVar1 == 0x400) && (param_1->dwHeight == 0x300)) {
      *(undefined4 *)((int)param_2 + 0x54) = 1;
      return lVar2;
    }
    if ((uVar1 == 0x500) && (param_1->dwHeight == 0x400)) {
      *(undefined4 *)((int)param_2 + 0x58) = 1;
      return lVar2;
    }
    if (uVar1 == 0x140) {
      if (param_1->dwHeight == 200) {
        *(undefined4 *)((int)param_2 + 0x5c) = 1;
        return lVar2;
      }
      if (param_1->dwHeight == 0xf0) {
        *(undefined4 *)((int)param_2 + 0x60) = 1;
        return lVar2;
      }
    }
  }
  else if (uVar1 == 0x10) {
    uVar1 = param_1->dwWidth;
    if ((uVar1 == 0x280) && (param_1->dwHeight == 0x1e0)) {
      *(undefined4 *)((int)param_2 + 0x6c) = 1;
      return lVar2;
    }
    if ((uVar1 == 800) && (param_1->dwHeight == 600)) {
      *(undefined4 *)((int)param_2 + 0x70) = 1;
      return lVar2;
    }
    if ((uVar1 == 0x400) && (param_1->dwHeight == 0x300)) {
      *(undefined4 *)((int)param_2 + 0x74) = 1;
      return lVar2;
    }
    if (uVar1 == 0x140) {
      if (param_1->dwHeight == 200) {
        *(undefined4 *)((int)param_2 + 100) = 1;
        return lVar2;
      }
      if (param_1->dwHeight == 0xf0) {
        *(undefined4 *)((int)param_2 + 0x68) = 1;
      }
    }
  }
  return lVar2;
}

// --------------------------------------------------

// Function: IsModeAvail
// Address: 004429c0
/* public: int __thiscall TDrawSystem::IsModeAvail(long,long,int) */

int __thiscall TDrawSystem::IsModeAvail(TDrawSystem *this,long param_1,long param_2,int param_3)
{
  if (param_3 == 8) {
    if (param_1 < 0x281) {
      if (param_1 == 0x280) {
        return this->ModeAvail640;
      }
      if (param_1 == 0x140) {
        if (param_2 == 200) {
          return this->ModeAvail320_200;
        }
        if (param_2 == 0xf0) {
          return this->ModeAvail320_240;
        }
      }
    }
    else {
      if (param_1 == 800) {
        return this->ModeAvail800;
      }
      if (param_1 == 0x400) {
        return this->ModeAvail1024;
      }
      if (param_1 == 0x500) {
        return this->ModeAvail1280;
      }
    }
  }
  else if (param_3 == 0x10) {
    if (param_1 < 0x281) {
      if (param_1 == 0x280) {
        return this->ModeAvail640_16;
      }
      if (param_1 == 0x140) {
        if (param_2 == 200) {
          return this->ModeAvail320_200_16;
        }
        if (param_2 == 0xf0) {
          return this->ModeAvail320_240_16;
        }
      }
    }
    else {
      if (param_1 == 800) {
        return this->ModeAvail800_16;
      }
      if (param_1 == 0x400) {
        return this->ModeAvail1024_16;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: Init
// Address: 00442a90
/* WARNING: Variable defined which should be unmapped: ddsd */
/* public: int __thiscall TDrawSystem::Init(void *,void *,void *,unsigned char,unsigned
   char,long,long,unsigned long) */

int __thiscall
TDrawSystem::Init(TDrawSystem *this,void *param_1,void *param_2,void *param_3,uchar param_4,
                 uchar param_5,long param_6,long param_7,ulong param_8)
{
  IDirectDraw **ppIVar1;
  IDirectDraw *pIVar2;
  IDirectDrawPalette *pIVar3;
  IDirectDrawClipper *pIVar4;
  IDirectDraw IVar5;
  int iVar6;
  undefined1 *puVar7;
  uchar *puVar8;
  _DDSURFACEDESC ddsd;
  _DDBLTFX ddbltfx;
  _DDCAPS ddcaps;
  tagPALETTEENTRY color_table [256];
  
  this->Wnd = param_2;
  this->Pal = param_3;
  this->Inst = param_1;
  this->ScreenMode = param_5;
  this->ScreenWidth = param_6;
  this->DrawType = param_4;
  this->ScreenHeight = param_7;
  this->Flags = param_8;
  if (param_4 == '\x01') {
    return 0;
  }
  ppIVar1 = &this->DirDraw;
  iVar6 = _DirectDrawCreate_12(0,ppIVar1,0);
  if (iVar6 != 0) {
    this->ErrorCode = 1;
    return 0;
  }
  CheckAvailModes(this,1);
  pIVar2 = *ppIVar1;
  if (this->ScreenMode == '\x01') {
    iVar6 = (**(code **)((int)*pIVar2 + 0x50))(pIVar2,this->Wnd,8);
    if (iVar6 != 0) {
      this->ErrorCode = 1;
      return 0;
    }
    memset(&stack0xfffff9e8,0,0x6c);
    iVar6 = (**(code **)((int)**ppIVar1 + 0x30))(*ppIVar1,&stack0xfffff9e8);
    if (iVar6 != 0) {
      this->ErrorCode = 1;
      return 0;
    }
    if (ddsd.ddckCKSrcBlt.dwColorSpaceHighValue != 8) {
      this->ErrorCode = 2;
      return 0;
    }
  }
  else {
    iVar6 = (**(code **)((int)*pIVar2 + 0x50))(pIVar2,this->Wnd,0x11);
    if (iVar6 != 0) {
      this->ErrorCode = 1;
      return 0;
    }
    IVar5 = **ppIVar1;
    this->ColorBits = 8;
    iVar6 = (**(code **)((int)IVar5 + 0x54))(*ppIVar1,this->ScreenWidth,this->ScreenHeight,8);
    if (iVar6 != 0) {
      this->ErrorCode = 1;
      return 0;
    }
    this->ChangedMode = 1;
  }
  if (this->Pal == (void *)0x0) {
    puVar7 = (undefined1 *)((int)ddcaps.dwSSBRops + 0x1d);
    iVar6 = 0x100;
    do {
      puVar7[-1] = 0;
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7 = puVar7 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    GetPaletteEntries(this->Pal,0,0x100,ddcaps.dwSSBRops + 7);
  }
  puVar8 = &this->palette[0].peBlue;
  iVar6 = 0x100;
  do {
    ((tagPALETTEENTRY *)(puVar8 + -2))->peRed = '\0';
    *puVar8 = '\0';
    puVar8[-1] = '\0';
    puVar8[1] = '\0';
    puVar8 = puVar8 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = (**(code **)((int)**ppIVar1 + 0x14))
                    (*ppIVar1,0x44,ddcaps.dwSSBRops + 7,&this->DirDrawPal,0);
  if (iVar6 != 0) {
    this->ErrorCode = 1;
    return 0;
  }
  pIVar3 = this->DirDrawPal;
  (**(code **)((int)*pIVar3 + 0x18))(pIVar3,0,0,0x100,this->palette);
  iVar6 = (**(code **)((int)**ppIVar1 + 0x10))(*ppIVar1,0,&this->Clipper,0);
  if (iVar6 != 0) {
    this->ErrorCode = 1;
    return 0;
  }
  pIVar4 = this->Clipper;
  iVar6 = (**(code **)((int)*pIVar4 + 0x20))(pIVar4,0,this->Wnd);
  if (iVar6 != 0) {
    this->ErrorCode = 1;
    return 0;
  }
  iVar6 = CreateSurfaces(this);
  if (iVar6 == 0) {
    this->ErrorCode = 1;
    return 0;
  }
  IVar5 = **ppIVar1;
  this->IsBanked = 0;
  ddbltfx.dwRotationAngle = 0x13c;
  iVar6 = (**(code **)((int)IVar5 + 0x2c))(*ppIVar1,&ddbltfx.dwRotationAngle,0);
  if (iVar6 == 0) {
    if ((ddbltfx.dwROP & 0x8000000) != 0) {
      this->IsBanked = 1;
    }
    if (((ddbltfx.dwROP & 0x400000) != 0) && ((ddbltfx.dwRotationAngle & 0x200) != 0)) {
      this->CanSrcBlt = 1;
    }
  }
  if (this->ScreenMode == '\x02') {
    ddsd.dwWidth = 100;
    ddsd.ddpfPixelFormat.field5_0x14.dwGBitMask = 0;
    (**(code **)((int)*this->PrimarySurface + 0x14))
              (this->PrimarySurface,0,0,0,0x1000400,&ddsd.dwWidth);
  }
  return 1;
}

// --------------------------------------------------

// Function: SetDisplaySize
// Address: 00442dc0
/* WARNING: Variable defined which should be unmapped: save_wid */
/* public: int __thiscall TDrawSystem::SetDisplaySize(long,long,int) */

int __thiscall TDrawSystem::SetDisplaySize(TDrawSystem *this,long param_1,long param_2,int param_3)
{
  IDirectDraw IVar1;
  ulong uVar2;
  int iVar3;
  IDirectDrawSurface *pIVar4;
  int iVar5;
  long save_wid;
  long save_hgt;
  _DDBLTFX ddbltfx;
  
  if ((this->DrawType == '\x02') && (this->ScreenMode == '\x02')) {
    system_ignore_size_messages = 1;
    pIVar4 = this->PrimarySurface;
    iVar5 = 0;
    ddbltfx.dwDDFX = 100;
    ddbltfx.ddckDestColorkey.dwColorSpaceLowValue = 0;
    (**(code **)((int)*pIVar4 + 0x14))(pIVar4,0,0,0,0x1000400,&ddbltfx.dwDDFX);
    uVar2 = ddbltfx.ddckDestColorkey.dwColorSpaceLowValue;
    IVar1 = *this->DirDraw;
    this->ScreenWidth = ddbltfx.ddckDestColorkey.dwColorSpaceLowValue;
    this->ScreenHeight = ddbltfx.ddckDestColorkey.dwColorSpaceHighValue;
    iVar3 = (**(code **)((int)IVar1 + 0x54))
                      (this->DirDraw,ddbltfx.ddckDestColorkey.dwColorSpaceLowValue,
                       ddbltfx.ddckDestColorkey.dwColorSpaceHighValue,
                       ddbltfx.ddckSrcColorkey.dwColorSpaceLowValue);
    system_ignore_size_messages = 0;
    if (iVar3 != 0) {
      this->ScreenWidth = (int)pIVar4;
      this->ScreenHeight = iVar5;
      return 0;
    }
    pIVar4 = this->PrimarySurface;
    this->ColorBits = ddbltfx.ddckSrcColorkey.dwColorSpaceLowValue;
    this->ChangedMode = 1;
    if (pIVar4 != (IDirectDrawSurface *)0x0) {
      (**(code **)((int)*pIVar4 + 8))(pIVar4);
      this->PrimarySurface = (IDirectDrawSurface *)0x0;
    }
    CreateSurfaces(this);
    if (this->DrawArea != (TDrawArea *)0x0) {
      TDrawArea::SetSize(this->DrawArea,this->ScreenWidth,this->ScreenHeight,0);
    }
    SendMessageA(this->Wnd,5,0,
                 ddbltfx.ddckDestColorkey.dwColorSpaceHighValue << 0x10 | uVar2 & 0xffff);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: ClearPrimarySurface
// Address: 00442ef0
/* WARNING: Variable defined which should be unmapped: ddbltfx */
/* public: void __thiscall TDrawSystem::ClearPrimarySurface(void) */

void __thiscall TDrawSystem::ClearPrimarySurface(TDrawSystem *this)
{
  IDirectDrawSurface *pIVar1;
  _DDBLTFX ddbltfx;
  
  ddbltfx.dwSize = (ulong)&ddbltfx.dwDDFX;
  if ((this->ScreenMode == '\x02') &&
     (pIVar1 = this->PrimarySurface, pIVar1 != (IDirectDrawSurface *)0x0)) {
    ddbltfx.dwDDFX = 100;
    ddbltfx.ddckDestColorkey.dwColorSpaceLowValue = 0;
    (**(code **)((int)*pIVar1 + 0x14))(pIVar1,0,0,0,0x1000400,&ddbltfx.dwDDFX);
  }
  return;
}

// --------------------------------------------------

// Function: CheckSurfaces
// Address: 00442f30
/* WARNING: Variable defined which should be unmapped: ddsd */
/* public: unsigned char __thiscall TDrawSystem::CheckSurfaces(void) */

uchar __thiscall TDrawSystem::CheckSurfaces(TDrawSystem *this)
{
  IDirectDrawSurface *pIVar1;
  IDirectDrawSurface IVar2;
  DrawAreaNode *pDVar3;
  uchar uVar4;
  int iVar5;
  uchar uVar6;
  ulong unaff_EBX;
  _DDSURFACEDESC ddsd;
  _DDBLTFX ddbltfx;
  
  if (this->DrawType != '\x02') {
    return '\0';
  }
  pIVar1 = this->PrimarySurface;
  if (((pIVar1 != (IDirectDrawSurface *)0x0) && (this->DrawArea != (TDrawArea *)0x0)) &&
     (this->DrawArea->DrawSurface != (IDirectDrawSurface *)0x0)) {
    uVar6 = '\0';
    ddsd.dwSize = unaff_EBX;
    iVar5 = (**(code **)((int)*pIVar1 + 0x60))(pIVar1);
    if (iVar5 != 0) {
      GetIsLostErrorNum(this,iVar5);
      memset(&ddsd,0,0x6c);
      ddsd.dwSize = 0x6c;
      iVar5 = (**(code **)((int)*this->DirDraw + 0x30))(this->DirDraw,&ddsd);
      if ((iVar5 == 0) &&
         (((ddsd.dwFlags != this->ScreenWidth || (ddsd.dwSize != this->ScreenHeight)) ||
          (ddsd.ddpfPixelFormat.dwFlags != 8)))) {
        return '\x01';
      }
      iVar5 = (**(code **)((int)*this->PrimarySurface + 0x6c))(this->PrimarySurface);
      if (iVar5 != 0) {
        GetRestoreErrorNum(this,iVar5);
        return '\x03';
      }
      IVar2 = *this->PrimarySurface;
      this->Restored = 1;
      uVar6 = '\x02';
      ddsd.ddpfPixelFormat.field6_0x18.dwBBitMask = 100;
      (**(code **)((int)IVar2 + 0x14))
                (this->PrimarySurface,0,0,0,0x1000400,&ddsd.ddpfPixelFormat.field6_0x18);
    }
    pDVar3 = this->DrawAreaList;
    while( true ) {
      if (pDVar3 == (DrawAreaNode *)0x0) {
        return uVar6;
      }
      if ((pDVar3->DrawArea != this->PrimaryArea) &&
         (uVar4 = TDrawArea::CheckSurface(pDVar3->DrawArea), uVar4 == '\x03')) break;
      pDVar3 = pDVar3->NextNode;
    }
  }
  return '\x03';
}

// --------------------------------------------------

// Function: ClearRestored
// Address: 00443070
/* public: void __thiscall TDrawSystem::ClearRestored(void) */

void __thiscall TDrawSystem::ClearRestored(TDrawSystem *this)
{
  DrawAreaNode *pDVar1;
  
  pDVar1 = this->DrawAreaList;
  this->Restored = 0;
  for (; pDVar1 != (DrawAreaNode *)0x0; pDVar1 = pDVar1->NextNode) {
    pDVar1->DrawArea->Restored = 0;
  }
  return;
}

// --------------------------------------------------

// Function: DeleteSurfaces
// Address: 00443090
/* public: void __thiscall TDrawSystem::DeleteSurfaces(void) */

void __thiscall TDrawSystem::DeleteSurfaces(TDrawSystem *this)
{
  TDrawArea *pTVar1;
  
  pTVar1 = this->DrawArea;
  if (pTVar1 != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(pTVar1);
    operator_delete(pTVar1);
    this->DrawArea = (TDrawArea *)0x0;
  }
  if (this->PrimarySurface != (IDirectDrawSurface *)0x0) {
    pTVar1 = this->PrimaryArea;
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar1);
      operator_delete(pTVar1);
    }
    this->PrimaryArea = (TDrawArea *)0x0;
    (**(code **)((int)*this->PrimarySurface + 8))(this->PrimarySurface);
    this->PrimarySurface = (IDirectDrawSurface *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: CreateSurfaces
// Address: 004430f0
// [HELPER] s_Back_Buffer: "Back Buffer"
// [HELPER] s_Primary_Surface: "Primary Surface"
/* public: int __thiscall TDrawSystem::CreateSurfaces(void) */

int __thiscall TDrawSystem::CreateSurfaces(TDrawSystem *this)
{
  IDirectDrawSurface **ppIVar1;
  int iVar2;
  TDrawArea *pTVar3;
  ulong *unaff_FS_OFFSET;
  tagRECT wnd_rect;
  _DDSURFACEDESC ddsd;
  _DDBLTFX ddbltfx;
  ulong uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d2ec;
  *unaff_FS_OFFSET = (ulong)&uStack_c;
  if (this->DrawType == '\x02') {
    ppIVar1 = &this->PrimarySurface;
    if (this->PrimarySurface == (IDirectDrawSurface *)0x0) {
      memset(&ddsd.dwFlags,0,0x6c);
      ddsd.dwFlags = 0x6c;
      ddsd.dwHeight = 1;
      iVar2 = (**(code **)((int)*this->DirDraw + 0x18))(this->DirDraw,&ddsd.dwFlags,ppIVar1,0);
      if (iVar2 != 0) {
        *unaff_FS_OFFSET = ddbltfx.ddckDestColorkey.dwColorSpaceHighValue;
        return 0;
      }
      if (this->ScreenMode == '\x02') {
        ddsd.ddpfPixelFormat.field6_0x18.dwBBitMask = 100;
        (**(code **)((int)**ppIVar1 + 0x14))
                  (*ppIVar1,0,0,0,0x1000400,&ddsd.ddpfPixelFormat.field6_0x18);
      }
      if (this->ColorBits == 8) {
        iVar2 = (**(code **)((int)**ppIVar1 + 0x7c))(*ppIVar1,this->DirDrawPal);
        if (iVar2 != 0) {
          *unaff_FS_OFFSET = ddbltfx.ddckDestColorkey.dwColorSpaceHighValue;
          return 0;
        }
      }
      iVar2 = (**(code **)((int)**ppIVar1 + 0x70))(*ppIVar1,this->Clipper);
      if (iVar2 != 0) {
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
    }
    if (this->PrimaryArea == (TDrawArea *)0x0) {
      wnd_rect.left = (long)operator_new(0x100);
      uStack_4 = 0;
      if ((TDrawArea *)wnd_rect.left == (TDrawArea *)0x0) {
        pTVar3 = (TDrawArea *)0x0;
      }
      else {
        pTVar3 = (TDrawArea *)TDrawArea::TDrawArea((TDrawArea *)wnd_rect.left,s_Primary_Surface,0);
      }
      uStack_4 = 0xffffffff;
      this->PrimaryArea = pTVar3;
      if (pTVar3 == (TDrawArea *)0x0) {
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
      if (this->ScreenMode == '\x01') {
        GetClientRect(this->Wnd,&wnd_rect.top);
        iVar2 = TDrawArea::Init(this->PrimaryArea,this,wnd_rect.bottom,ddsd.dwSize,0,1);
        if (iVar2 == 0) {
          *unaff_FS_OFFSET = uStack_c;
          return 0;
        }
      }
      else {
        iVar2 = TDrawArea::Init(pTVar3,this,this->ScreenWidth,this->ScreenHeight,0,1);
        if (iVar2 == 0) {
          *unaff_FS_OFFSET = uStack_c;
          return 0;
        }
      }
    }
  }
  if (this->DrawArea == (TDrawArea *)0x0) {
    wnd_rect.left = (long)operator_new(0x100);
    uStack_4 = 1;
    if ((TDrawArea *)wnd_rect.left == (TDrawArea *)0x0) {
      pTVar3 = (TDrawArea *)0x0;
    }
    else {
      pTVar3 = (TDrawArea *)TDrawArea::TDrawArea((TDrawArea *)wnd_rect.left,s_Back_Buffer,0);
    }
    uStack_4 = 0xffffffff;
    this->DrawArea = pTVar3;
    if (pTVar3 == (TDrawArea *)0x0) {
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    if (this->ScreenMode == '\x01') {
      GetClientRect(this->Wnd,&wnd_rect.top);
      iVar2 = TDrawArea::Init(this->DrawArea,this,wnd_rect.bottom,ddsd.dwSize,0,0);
      if (iVar2 == 0) {
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
    }
    else {
      iVar2 = TDrawArea::Init(pTVar3,this,this->ScreenWidth,this->ScreenHeight,0,0);
      if (iVar2 == 0) {
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: HandleSize
// Address: 004433f0
/* WARNING: Variable defined which should be unmapped: wnd_rect */
/* public: void __thiscall TDrawSystem::HandleSize(void *,unsigned int,unsigned int,long) */

void __thiscall
TDrawSystem::HandleSize(TDrawSystem *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  tagRECT wnd_rect;
  int iStack_4;
  
  if (this->DrawArea != (TDrawArea *)0x0) {
    if ((this->DrawType == '\x01') || (this->ScreenMode == '\x01')) {
      GetClientRect(this->Wnd,&wnd_rect.top);
      this->ScreenWidth = wnd_rect.bottom;
      this->ScreenHeight = iStack_4;
    }
    if (this->PrimaryArea != (TDrawArea *)0x0) {
      TDrawArea::SetSize(this->PrimaryArea,this->ScreenWidth,this->ScreenHeight,0);
    }
    TDrawArea::SetSize(this->DrawArea,this->ScreenWidth,this->ScreenHeight,0);
  }
  return;
}

// --------------------------------------------------

// Function: HandlePaletteChanged
// Address: 00443460
/* public: void __thiscall TDrawSystem::HandlePaletteChanged(void *,unsigned int,unsigned int,long)
    */

void __thiscall
TDrawSystem::HandlePaletteChanged
          (TDrawSystem *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  if (param_1 != this->Wnd) {
    HandleQueryNewPalette(this,param_1,param_2,param_3,param_4);
  }
  return;
}

// --------------------------------------------------

// Function: HandleQueryNewPalette
// Address: 00443490
/* public: int __thiscall TDrawSystem::HandleQueryNewPalette(void *,unsigned int,unsigned int,long)
    */

int __thiscall
TDrawSystem::HandleQueryNewPalette
          (TDrawSystem *this,void *param_1,uint param_2,uint param_3,long param_4)
{
  char cVar1;
  undefined4 uVar2;
  
  if ((this->Pal != (void *)0x0) && ((this->DrawType == '\x01' || (this->ScreenMode == '\x01')))) {
    uVar2 = GetDC(this->Wnd);
    if (this->Pal != (void *)0x0) {
      SelectPalette(uVar2,this->Pal,0);
    }
    cVar1 = RealizePalette(uVar2);
    ReleaseDC(this->Wnd,uVar2);
    if (cVar1 != '\0') {
      InvalidateRect(this->Wnd,0,0);
      return 1;
    }
  }
  ModifyPalette(this,0,0x100,this->palette);
  return 0;
}

// --------------------------------------------------

// Function: Paint
// Address: 00443520
/* WARNING: Variable defined which should be unmapped: dest */
/* public: void __thiscall TDrawSystem::Paint(struct tagRECT *) */

void __thiscall TDrawSystem::Paint(TDrawSystem *this,tagRECT *param_1)
{
  int iVar1;
  int iVar2;
  tagRECT dest;
  tagRECT src;
  long local_4;
  
  if ((((this->DrawType != '\x01') && (this->PrimarySurface != (IDirectDrawSurface *)0x0)) &&
      (this->DrawArea != (TDrawArea *)0x0)) &&
     (this->DrawArea->DrawSurface != (IDirectDrawSurface *)0x0)) {
    if (this->ScreenMode == '\x01') {
      GetClientRect(this->Wnd,&src.top);
      dest.right = src.right;
      dest.bottom = src.bottom;
      dest.top = src.top;
      src.left = local_4;
      ClientToScreen(this->Wnd,&dest.top);
      ClientToScreen(this->Wnd,&dest.bottom);
    }
    else {
      dest.bottom = this->ScreenWidth;
      src.left = this->ScreenHeight;
      src.top = 0;
      src.right = 0;
      dest.top = 0;
      dest.right = 0;
      src.bottom = dest.bottom;
    }
    if (param_1 != (tagRECT *)0x0) {
      src.top = param_1->left;
      src.right = param_1->top;
      iVar1 = param_1->right;
      iVar2 = param_1->bottom;
      if (src.top < 0) {
        src.top = 0;
      }
      if (src.right < 0) {
        src.right = 0;
      }
      if (this->ScreenWidth <= iVar1) {
        iVar1 = this->ScreenWidth + -1;
      }
      if (this->ScreenHeight <= iVar2) {
        iVar2 = this->ScreenHeight + -1;
      }
      dest.top = dest.top + src.top;
      dest.right = dest.right + src.right;
      src.bottom = iVar1 + 1;
      dest.bottom = ((dest.top + iVar1) - src.top) + 1;
      src.left = ((iVar2 + dest.right) - src.right) + 1;
    }
    (**(code **)((int)*this->PrimarySurface + 0x14))
              (this->PrimarySurface,&dest.top,this->DrawArea->DrawSurface,&src.top,0x1000000,0);
  }
  return;
}

// --------------------------------------------------

// Function: GetIsLostErrorNum
// Address: 00443680
/* public: int __thiscall TDrawSystem::GetIsLostErrorNum(long) */

int __thiscall TDrawSystem::GetIsLostErrorNum(TDrawSystem *this,long param_1)
{
  if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return 0x6a4;
    }
    if (param_1 == -0x7ff8ffa9) {
      return 0x6a5;
    }
  }
  else {
    if (param_1 == -0x7789fe3e) {
      return 0x6a6;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return 0x707;
}

// --------------------------------------------------

// Function: GetRestoreErrorNum
// Address: 004436d0
/* public: int __thiscall TDrawSystem::GetRestoreErrorNum(long) */

int __thiscall TDrawSystem::GetRestoreErrorNum(TDrawSystem *this,long param_1)
{
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      return 0x708;
    }
    if (param_1 == -0x7fffbfff) {
      return 0x70f;
    }
  }
  else if (param_1 < -0x7ff8ffa8) {
    if (param_1 == -0x7ff8ffa9) {
      return 0x70c;
    }
    if (param_1 == -0x7ff8fff2) {
      return 0x70e;
    }
  }
  else if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return 0x70b;
    }
    if (param_1 == -0x7789ffa1) {
      return 0x70a;
    }
  }
  else if (param_1 < -0x7789fdb4) {
    if (param_1 == -0x7789fdb5) {
      return 0x710;
    }
    if (param_1 == -0x7789ff1f) {
      return 0x70d;
    }
  }
  else {
    if (param_1 == -0x7789fdb4) {
      return 0x709;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return 0x76b;
}

// --------------------------------------------------

// Function: GetSetDispModeErrorNum
// Address: 00443780
/* public: int __thiscall TDrawSystem::GetSetDispModeErrorNum(long) */

int __thiscall TDrawSystem::GetSetDispModeErrorNum(TDrawSystem *this,long param_1)
{
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      return 0x76c;
    }
    if (param_1 == -0x7fffbfff) {
      return 0x773;
    }
  }
  else if (param_1 < -0x7789ff87) {
    if (param_1 == -0x7789ff88) {
      return 0x76d;
    }
    if (param_1 == -0x7ff8ffa9) {
      return 0x76f;
    }
  }
  else if (param_1 < -0x7789ff5f) {
    if (param_1 == -0x7789ff60) {
      return 0x770;
    }
    if (param_1 == -0x7789ff7e) {
      return 0x76e;
    }
  }
  else if (param_1 < -0x7789fe51) {
    if (param_1 == -0x7789fe52) {
      return 0x772;
    }
    if (param_1 == -0x7789ff1f) {
      return 0x771;
    }
  }
  else {
    if (param_1 == -0x7789fde4) {
      return 0x775;
    }
    if (param_1 == -0x7789fdb2) {
      return 0x774;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return 1999;
}

// --------------------------------------------------

// Function: GetLockErrorNum
// Address: 00443840
/* public: int __thiscall TDrawSystem::GetLockErrorNum(long) */

int __thiscall TDrawSystem::GetLockErrorNum(TDrawSystem *this,long param_1)
{
  if (param_1 < -0x7ff8fff1) {
    if (param_1 == -0x7ff8fff2) {
      return 0x7d6;
    }
    if (param_1 == -0x7fffbffb) {
      return 2000;
    }
  }
  else if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return 0x7d1;
    }
    if (param_1 == -0x7ff8ffa9) {
      return 0x7d2;
    }
  }
  else if (param_1 < -0x7789fe51) {
    if (param_1 == -0x7789fe52) {
      return 0x7d3;
    }
    if (param_1 == -0x7789ff6a) {
      return 0x7d8;
    }
  }
  else if (param_1 < -0x7789fde3) {
    if (param_1 == -0x7789fde4) {
      return 0x7d5;
    }
    if (param_1 == -0x7789fe3e) {
      return 0x7d4;
    }
  }
  else {
    if (param_1 == -0x7789fdb8) {
      return 0x7d7;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return 0x833;
}

// --------------------------------------------------

// Function: GetDCErrorNum
// Address: 004438f0
/* public: int __thiscall TDrawSystem::GetDCErrorNum(long) */

int __thiscall TDrawSystem::GetDCErrorNum(TDrawSystem *this,long param_1)
{
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      return 0x834;
    }
    if (param_1 == -0x7fffbfff) {
      return 0x83a;
    }
  }
  else if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return 0x836;
    }
    if (param_1 == -0x7ff8ffa9) {
      return 0x837;
    }
  }
  else if (param_1 < -0x7789fde3) {
    if (param_1 == -0x7789fde4) {
      return 0x83b;
    }
    if (param_1 == -0x7789fe3e) {
      return 0x839;
    }
  }
  else {
    if (param_1 == -0x7789fdb0) {
      return 0x838;
    }
    if (param_1 == -0x7789fd94) {
      return 0x835;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return 0x897;
}

// --------------------------------------------------

// Function: GetBlitErrorNum
// Address: 00443990
/* public: int __thiscall TDrawSystem::GetBlitErrorNum(long) */

int __thiscall TDrawSystem::GetBlitErrorNum(TDrawSystem *this,long param_1)
{
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      return 0x898;
    }
    if (param_1 == -0x7fffbfff) {
      return 0x8a3;
    }
  }
  else if (param_1 < -0x7789ff91) {
    if (param_1 == -0x7789ff92) {
      return 0x89c;
    }
    if (param_1 == -0x7ff8ffa9) {
      return 0x89a;
    }
  }
  else if (param_1 < -0x7789ff69) {
    if (param_1 == -0x7789ff6a) {
      return 0x89d;
    }
    if (param_1 == -0x7789ff7e) {
      return 0x899;
    }
  }
  else if (param_1 < -0x7789ff32) {
    if (param_1 == -0x7789ff33) {
      return 0x8a0;
    }
    if (param_1 == -0x7789ff4c) {
      return 0x89e;
    }
  }
  else if (param_1 < -0x7789fee7) {
    if (param_1 == -0x7789fee8) {
      return 0x8a5;
    }
    if (param_1 == -0x7789ff06) {
      return 0x8a4;
    }
  }
  else if (param_1 < -0x7789fec9) {
    if (param_1 == -0x7789feca) {
      return 0x8a7;
    }
    if (param_1 == -0x7789fede) {
      return 0x8a6;
    }
  }
  else if (param_1 < -0x7789fe51) {
    if (param_1 == -0x7789fe52) {
      return 0x8a8;
    }
    if (param_1 == -0x7789feac) {
      return 0x89b;
    }
  }
  else if (param_1 < -0x7789fdc0) {
    if (param_1 == -0x7789fdc1) {
      return 0x89f;
    }
    if (param_1 == -0x7789fe3e) {
      return 0x8a2;
    }
  }
  else {
    if (param_1 == -0x7789fdc0) {
      return 0x8a1;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return 0x8fb;
}

// --------------------------------------------------

// Function: GetCreateErrorNum
// Address: 00443ad0
/* public: int __thiscall TDrawSystem::GetCreateErrorNum(long) */

int __thiscall TDrawSystem::GetCreateErrorNum(TDrawSystem *this,long param_1)
{
  if (param_1 < -0x7ff8fff1) {
    if (param_1 == -0x7ff8fff2) {
      return 0x908;
    }
    if (param_1 == -0x7fffbffb) {
      return 0x8fc;
    }
  }
  else if (param_1 < -0x7789ffa0) {
    if (param_1 == -0x7789ffa1) {
      return 0x90b;
    }
    if (param_1 == -0x7ff8ffa9) {
      return 0x8fe;
    }
  }
  else if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return 0x8fd;
    }
    if (param_1 == -0x7789ff9c) {
      return 0x902;
    }
  }
  else if (param_1 < -0x7789ff4b) {
    if (param_1 == -0x7789ff4c) {
      return 0x904;
    }
    if (param_1 == -0x7789ff6f) {
      return 0x903;
    }
  }
  else if (param_1 < -0x7789ff1e) {
    if (param_1 == -0x7789ff1f) {
      return 0x907;
    }
    if (param_1 == -0x7789ff2c) {
      return 0x901;
    }
  }
  else if (param_1 < -0x7789feab) {
    if (param_1 == -0x7789feac) {
      return 0x906;
    }
    if (param_1 == -0x7789ff1a) {
      return 0x905;
    }
  }
  else if (param_1 < -0x7789fdcc) {
    if (param_1 == -0x7789fdcd) {
      return 0x900;
    }
    if (param_1 == -0x7789fe84) {
      return 0x8ff;
    }
  }
  else {
    if (param_1 == -0x7789fdcc) {
      return 0x909;
    }
    if (param_1 == -0x7789fdcb) {
      return 0x90a;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return 0x95f;
}

// --------------------------------------------------

// Function: GetColorKeyErrorNum
// Address: 00443c00
/* public: int __thiscall TDrawSystem::GetColorKeyErrorNum(long) */

int __thiscall TDrawSystem::GetColorKeyErrorNum(TDrawSystem *this,long param_1)
{
  if (param_1 < -0x7fffbffa) {
    if (param_1 == -0x7fffbffb) {
      return 0x960;
    }
    if (param_1 == -0x7fffbfff) {
      return 0x967;
    }
  }
  else if (param_1 < -0x7789ff7d) {
    if (param_1 == -0x7789ff7e) {
      return 0x961;
    }
    if (param_1 == -0x7ff8ffa9) {
      return 0x962;
    }
  }
  else if (param_1 < -0x7789fe3d) {
    if (param_1 == -0x7789fe3e) {
      return 0x966;
    }
    if (param_1 == -0x7789fefc) {
      return 0x964;
    }
  }
  else if (param_1 < -0x7789fdbb) {
    if (param_1 == -0x7789fdbc) {
      return 0x965;
    }
    if (param_1 == -0x7789fde4) {
      return 0x968;
    }
  }
  else {
    if (param_1 == -0x7789fdb0) {
      return 0x963;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  return 0x9c3;
}

// --------------------------------------------------

// Function: SetPalette
// Address: 00443cb0
/* WARNING: Variable defined which should be unmapped: color_table */
/* public: void __thiscall TDrawSystem::SetPalette(void *) */

void __thiscall TDrawSystem::SetPalette(TDrawSystem *this,void *param_1)
{
  uchar *puVar1;
  int iVar2;
  tagPALETTEENTRY color_table [256];
  
  this->Pal = param_1;
  if (param_1 == (void *)0x0) {
    puVar1 = &color_table[1].peGreen;
    iVar2 = 0x100;
    do {
      ((tagPALETTEENTRY *)(puVar1 + -1))->peRed = '\0';
      *puVar1 = '\0';
      puVar1[1] = '\0';
      puVar1[2] = '\0';
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    GetPaletteEntries(param_1,0,0x100,color_table + 1);
  }
  color_table[1].peRed = '\0';
  color_table[1].peGreen = '\0';
  color_table[1].peBlue = '\0';
  color_table[1].peFlags = '\0';
  ModifyPalette(this,0,0x100,color_table + 1);
  return;
}

// --------------------------------------------------

// Function: ModifyPalette
// Address: 00443d40
/* public: void __thiscall TDrawSystem::ModifyPalette(int,int,struct tagPALETTEENTRY *) */

void __thiscall
TDrawSystem::ModifyPalette(TDrawSystem *this,int param_1,int param_2,tagPALETTEENTRY *param_3)
{
  int iVar1;
  int iVar2;
  tagPALETTEENTRY *ptVar3;
  
  PalSetRes = -99;
  if (param_2 == 0x100) {
    FullPalSets = FullPalSets + 1;
  }
  if (param_1 < param_2 + param_1) {
    iVar2 = (param_2 + param_1) - param_1;
    iVar1 = param_1 * 4;
    ptVar3 = this->palette + param_1;
    do {
      iVar2 = iVar2 + -1;
      *ptVar3 = *(tagPALETTEENTRY *)(&param_3[-param_1].peRed + iVar1);
      iVar1 = iVar1 + 4;
      ptVar3 = ptVar3 + 1;
    } while (iVar2 != 0);
  }
  if ((this->DrawType != '\x01') && (this->DirDrawPal != (IDirectDrawPalette *)0x0)) {
    if (param_2 == 7) {
      AniPalSets = AniPalSets + 1;
    }
    (**(code **)((int)*this->DirDrawPal + 0x18))(this->DirDrawPal,0,param_1,param_2,param_3);
  }
  return;
}

// --------------------------------------------------


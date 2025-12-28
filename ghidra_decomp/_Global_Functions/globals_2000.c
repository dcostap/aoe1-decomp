// GLOBAL FUNCTIONS PART 2000
// Function: FUN_0044d9ac
// Address: 0044d9ac
// XREFS: None
long __fastcall FUN_0044d9ac(int *param_1)
{
  int iVar1;
  long lVar2;
  
  iVar1 = *param_1;
  if ((iVar1 < param_1[1]) && (-1 < iVar1)) {
    lVar2 = RGE_Person_Info::get_current_campaign(*(RGE_Person_Info **)(param_1[2] + iVar1 * 4));
    return lVar2;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0044d9cc
// Address: 0044d9cc
// XREFS: None
undefined4 __fastcall FUN_0044d9cc(undefined4 *param_1)
{
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_0044d9d3
// Address: 0044d9d3
// XREFS: None
char * __fastcall FUN_0044d9d3(int *param_1)
{
  char *pcVar1;
  
  if (*param_1 < 0) {
    return (char *)0x0;
  }
  pcVar1 = RGE_Person_Info::get_name(*(RGE_Person_Info **)(param_1[2] + *param_1 * 4));
  return pcVar1;
}

// --------------------------------------------------

// Function: FUN_0044d9f4
// Address: 0044d9f4
// XREFS: None
void __fastcall FUN_0044d9f4(RGE_Game_Info *param_1)
{
  int iVar1;
  
  iVar1 = param_1->current_person;
  if ((iVar1 < param_1->people_num) && (-1 < iVar1)) {
    RGE_Person_Info::notify_of_scenario_complete(param_1->people_info[iVar1]);
  }
  RGE_Game_Info::save(param_1,param_1->save_filename);
  return;
}

// --------------------------------------------------

// Function: FUN_0044da28
// Address: 0044da28
// XREFS: None
int __fastcall FUN_0044da28(int *param_1)
{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 < param_1[1]) && (-1 < iVar1)) {
    iVar1 = RGE_Person_Info::open_scenario(*(RGE_Person_Info **)(param_1[2] + iVar1 * 4));
    return iVar1;
  }
  return -1;
}

// --------------------------------------------------

// Function: FUN_0044da4c
// Address: 0044da4c
// XREFS: None
void __thiscall FUN_0044da4c(int *param_1,int param_2)
{
  RGE_Person_Info *this;
  int iVar1;
  int iVar2;
  
  if ((-1 < param_2) && (param_2 < param_1[1])) {
    this = *(RGE_Person_Info **)(param_1[2] + param_2 * 4);
    if (this != (RGE_Person_Info *)0x0) {
      RGE_Person_Info::~RGE_Person_Info(this);
      operator_delete(this);
    }
    if (param_2 < param_1[1] + -1) {
      do {
        param_2 = param_2 + 1;
        *(undefined4 *)(param_1[2] + -4 + param_2 * 4) = *(undefined4 *)(param_1[2] + param_2 * 4);
      } while (param_2 < param_1[1] + -1);
    }
    iVar1 = param_1[1];
    iVar2 = iVar1 + -1;
    param_1[1] = iVar2;
    if (*param_1 == iVar2) {
      *param_1 = iVar1 + -2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044dab1
// Address: 0044dab1
// XREFS: None
// [HELPER] s_Couldn_t_CreateSurface__: "Couldn't CreateSurface\n"
// [HELPER] s_Couldn_t_GetProcAddress_DInputCr: "Couldn't GetProcAddress DInputCreate\n"
// [HELPER] s_Couldn_t_LoadLibrary_DDraw__: "Couldn't LoadLibrary DDraw\n"
// [HELPER] s_Couldn_t_LoadLibrary_DInput__: "Couldn't LoadLibrary DInput\n"
// [HELPER] s_Couldn_t_QI_DDraw2__: "Couldn't QI DDraw2\n"
// [HELPER] s_Couldn_t_Set_coop_level__: "Couldn't Set coop level\n"
// [HELPER] s_Couldn_t_create_DDraw__: "Couldn't create DDraw\n"
// [HELPER] s_DDRAW_DLL: "DDRAW.DLL"
// [HELPER] s_DINPUT_DLL: "DINPUT.DLL"
// [HELPER] s_DirectDrawCreate: "DirectDrawCreate"
// [HELPER] s_DirectInputCreateA: "DirectInputCreateA"
void FUN_0044dab1(undefined4 *param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  char **ppcVar5;
  int *unaff_retaddr;
  undefined **ppuVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piStack_14c;
  uint *puStack_148;
  uint *puStack_144;
  int *piStack_140;
  int *piStack_13c;
  undefined *puStack_138;
  int *piStack_134;
  int *piStack_130;
  char *apcStack_12c [2];
  uint auStack_94 [2];
  uint uStack_8c;
  int iStack_88;
  int *piStack_10;
  undefined4 *puStack_4;
  
  apcStack_12c[1] = (char *)auStack_94;
  auStack_94[0] = 0x94;
  apcStack_12c[0] = (char *)0x44daf5;
  iVar1 = GetVersionExA();
  if (iVar1 == 0) {
    *unaff_retaddr = 0;
    *param_1 = 0;
    return;
  }
  if (iStack_88 == 2) {
    *param_1 = 2;
    if (auStack_94[0] < 4) {
      *param_1 = 0;
      return;
    }
    if (auStack_94[0] != 4) {
      *unaff_retaddr = 0x501;
      return;
    }
    apcStack_12c[0] = s_DINPUT_DLL;
    *unaff_retaddr = 0x200;
    piStack_130 = (int *)0x44db68;
    piVar2 = (int *)LoadLibraryA();
    if (piVar2 == (int *)0x0) {
      piStack_130 = (int *)s_Couldn_t_LoadLibrary_DInput__;
      piStack_134 = (int *)0x44db79;
      OutputDebugStringA();
      return;
    }
    piStack_130 = (int *)s_DirectInputCreateA;
    puStack_138 = (undefined *)0x44db90;
    piStack_134 = piVar2;
    iVar1 = GetProcAddress();
    piStack_134 = (int *)0x44db99;
    piStack_130 = piVar2;
    FreeLibrary();
    if (iVar1 == 0) {
      piStack_134 = (int *)s_Couldn_t_GetProcAddress_DInputCr;
      puStack_138 = (undefined *)0x44dba8;
      OutputDebugStringA();
      return;
    }
    piStack_134 = (int *)0x0;
    *unaff_retaddr = 0x300;
    puStack_138 = (undefined *)0x44dbc1;
    iVar1 = CoInitialize();
    piStack_134 = (int *)&stack0xfffffee4;
    puStack_138 = &_IID_IDirectPlay3;
    piStack_13c = (int *)0x1;
    piStack_140 = (int *)0x0;
    puStack_144 = (uint *)&_CLSID_DirectPlay;
    puStack_148 = (uint *)0x44dbdc;
    iVar3 = CoCreateInstance();
    if (-1 < iVar3) {
      puStack_148 = (uint *)piStack_130;
      piStack_14c = (int *)0x44dc03;
      (**(code **)(*piStack_130 + 8))();
      if (iVar1 != 0) {
        piStack_14c = (int *)0x44dc0d;
        CoUninitialize();
      }
      piStack_14c = (int *)0x44dc12;
      iVar1 = IsDPlay501a();
      *unaff_retaddr = (iVar1 != 0) + 0x500;
      return;
    }
    if (iVar1 != 0) {
      puStack_148 = (uint *)0x44dbee;
      CoUninitialize();
      return;
    }
  }
  else {
    *param_1 = 1;
    if (0x549 < (uStack_8c & 0xffff)) {
      *unaff_retaddr = 0x501;
      return;
    }
    apcStack_12c[0] = s_DDRAW_DLL;
    piStack_130 = (int *)0x44dc87;
    piVar2 = (int *)LoadLibraryA();
    if (piVar2 == (int *)0x0) {
      piStack_130 = (int *)0x0;
      *puStack_4 = 0;
      *param_1 = 0;
      piStack_134 = (int *)0x44dc9f;
      FreeLibrary();
      return;
    }
    piStack_130 = (int *)s_DirectDrawCreate;
    puStack_138 = (undefined *)0x44dcb6;
    piStack_134 = piVar2;
    pcVar4 = (code *)GetProcAddress();
    if (pcVar4 == (code *)0x0) {
      *puStack_4 = 0;
      *param_1 = 0;
      piStack_134 = (int *)0x44dccc;
      piStack_130 = piVar2;
      FreeLibrary();
      piStack_134 = (int *)s_Couldn_t_LoadLibrary_DDraw__;
      puStack_138 = (undefined *)0x44dcd7;
      OutputDebugStringA();
      return;
    }
    piStack_134 = (int *)&stack0xfffffee4;
    piStack_130 = (int *)0x0;
    puStack_138 = (undefined *)0x0;
    piStack_13c = (int *)0x44dceb;
    iVar1 = (*pcVar4)();
    if (iVar1 < 0) {
      *piStack_10 = 0;
      *param_1 = 0;
      piStack_140 = (int *)0x44dd01;
      piStack_13c = piVar2;
      FreeLibrary();
      piStack_140 = (int *)s_Couldn_t_create_DDraw__;
      puStack_144 = (uint *)0x44dd0c;
      OutputDebugStringA();
      return;
    }
    piStack_13c = (int *)&stack0xfffffee4;
    puVar9 = *(undefined4 **)apcStack_12c[1];
    piStack_140 = (int *)&_IID_IDirectDraw2;
    puStack_144 = (uint *)apcStack_12c[1];
    *piStack_10 = 0x100;
    puStack_148 = (uint *)0x44dd37;
    iVar1 = (*(code *)*puVar9)();
    if (iVar1 < 0) {
      puStack_148 = (uint *)piStack_134;
      piStack_14c = (int *)0x44dd45;
      (**(code **)(*piStack_134 + 8))();
      piStack_14c = piVar2;
      FreeLibrary();
      OutputDebugStringA(s_Couldn_t_QI_DDraw2__);
      return;
    }
    puStack_148 = (uint *)apcStack_12c[1];
    piStack_14c = (int *)0x44dd6c;
    (**(code **)(*(uint *)apcStack_12c[1] + 8))();
    piStack_14c = (int *)s_DINPUT_DLL;
    *piStack_10 = 0x200;
    iVar1 = LoadLibraryA();
    if (iVar1 == 0) {
      OutputDebugStringA(s_Couldn_t_LoadLibrary_DInput__);
      (**(code **)(*piStack_140 + 8))(piStack_140);
      FreeLibrary(piVar2);
      return;
    }
    puStack_138 = (undefined *)GetProcAddress(iVar1,s_DirectInputCreateA);
    FreeLibrary(iVar1);
    if (piStack_13c == (int *)0x0) {
      FreeLibrary(piVar2);
      (**(code **)(*puStack_144 + 8))(puStack_144);
      OutputDebugStringA(s_Couldn_t_GetProcAddress_DInputCr);
      return;
    }
    puVar9 = (undefined4 *)0x8;
    ppcVar5 = apcStack_12c;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar5 = (char *)0x0;
      ppcVar5 = ppcVar5 + 1;
    }
    *piStack_10 = 0x300;
    apcStack_12c[0] = (char *)0x6c;
    apcStack_12c[1] = (char *)0x1;
    piVar8 = piStack_140;
    iVar1 = (**(code **)(*piStack_140 + 0x50))(piStack_140,0);
    if (iVar1 < 0) {
      (**(code **)(*piStack_14c + 8))(piStack_14c);
      FreeLibrary(piVar2);
      *piStack_10 = 0;
      OutputDebugStringA(s_Couldn_t_Set_coop_level__);
      return;
    }
    piVar7 = (int *)0x0;
    ppuVar6 = &puStack_138;
    iVar1 = (**(code **)(*piStack_14c + 0x18))(piStack_14c,ppuVar6,&puStack_144);
    if (iVar1 < 0) {
      (**(code **)(*piVar8 + 8))(piVar8);
      FreeLibrary(piVar2);
      *piStack_10 = 0;
      OutputDebugStringA(s_Couldn_t_CreateSurface__);
      return;
    }
    iVar1 = (**(code **)*puVar9)(puVar9,&_IID_IDirectDrawSurface3,&piStack_14c);
    if (-1 < iVar1) {
      iVar1 = IsDPlay501a();
      *piStack_10 = (iVar1 != 0) + 0x500;
      (**(code **)(*piVar7 + 8))(piVar7);
    }
    (**(code **)(*ppuVar6 + 8))(ppuVar6);
    FreeLibrary(piVar2);
  }
  return;
}

// --------------------------------------------------

// Function: GetDXVersion
// Address: 0044dac0
// XREFS: setup
// [HELPER] s_Couldn_t_CreateSurface__: "Couldn't CreateSurface\n"
// [HELPER] s_Couldn_t_GetProcAddress_DInputCr: "Couldn't GetProcAddress DInputCreate\n"
// [HELPER] s_Couldn_t_LoadLibrary_DDraw__: "Couldn't LoadLibrary DDraw\n"
// [HELPER] s_Couldn_t_LoadLibrary_DInput__: "Couldn't LoadLibrary DInput\n"
// [HELPER] s_Couldn_t_QI_DDraw2__: "Couldn't QI DDraw2\n"
// [HELPER] s_Couldn_t_Set_coop_level__: "Couldn't Set coop level\n"
// [HELPER] s_Couldn_t_create_DDraw__: "Couldn't create DDraw\n"
// [HELPER] s_DDRAW_DLL: "DDRAW.DLL"
// [HELPER] s_DINPUT_DLL: "DINPUT.DLL"
// [HELPER] s_DirectDrawCreate: "DirectDrawCreate"
// [HELPER] s_DirectInputCreateA: "DirectInputCreateA"
/* WARNING: Variable defined which should be unmapped: pDDraw */
/* void __cdecl GetDXVersion(unsigned long *,unsigned long *) */

void __cdecl GetDXVersion(ulong *param_1,ulong *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  char **ppcVar5;
  int *unaff_retaddr;
  undefined **ppuVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piStack_14c;
  ulong *puStack_148;
  ulong *puStack_144;
  int *piStack_140;
  int *piStack_13c;
  undefined *puStack_138;
  int *piStack_134;
  int *piStack_130;
  char *apcStack_12c [2];
  IDirectDraw *pDDraw;
  IDirectPlay3 *dp3;
  IDirectDrawSurface *pSurf;
  IDirectDraw2 *pDDraw2;
  IDirectDrawSurface3 *pSurf3;
  _DDSURFACEDESC desc;
  _OSVERSIONINFOA osVer;
  undefined4 *puStack_4;
  
  apcStack_12c[1] = (char *)&osVer.dwMajorVersion;
  osVer.dwMajorVersion = 0x94;
  apcStack_12c[0] = (char *)0x44daf5;
  iVar1 = GetVersionExA();
  if (iVar1 == 0) {
    *unaff_retaddr = 0;
    *param_1 = 0;
    return;
  }
  if (osVer.dwPlatformId == 2) {
    *param_1 = 2;
    if (osVer.dwMajorVersion < 4) {
      *param_1 = 0;
      return;
    }
    if (osVer.dwMajorVersion != 4) {
      *unaff_retaddr = 0x501;
      return;
    }
    apcStack_12c[0] = s_DINPUT_DLL;
    *unaff_retaddr = 0x200;
    piStack_130 = (int *)0x44db68;
    piVar2 = (int *)LoadLibraryA();
    if (piVar2 == (int *)0x0) {
      piStack_130 = (int *)s_Couldn_t_LoadLibrary_DInput__;
      piStack_134 = (int *)0x44db79;
      OutputDebugStringA();
      return;
    }
    piStack_130 = (int *)s_DirectInputCreateA;
    puStack_138 = (undefined *)0x44db90;
    piStack_134 = piVar2;
    iVar1 = GetProcAddress();
    piStack_134 = (int *)0x44db99;
    piStack_130 = piVar2;
    FreeLibrary();
    if (iVar1 == 0) {
      piStack_134 = (int *)s_Couldn_t_GetProcAddress_DInputCr;
      puStack_138 = (undefined *)0x44dba8;
      OutputDebugStringA();
      return;
    }
    piStack_134 = (int *)0x0;
    *unaff_retaddr = 0x300;
    puStack_138 = (undefined *)0x44dbc1;
    iVar1 = CoInitialize();
    piStack_134 = (int *)&stack0xfffffee4;
    puStack_138 = &_IID_IDirectPlay3;
    piStack_13c = (int *)0x1;
    piStack_140 = (int *)0x0;
    puStack_144 = (ulong *)&_CLSID_DirectPlay;
    puStack_148 = (ulong *)0x44dbdc;
    iVar3 = CoCreateInstance();
    if (-1 < iVar3) {
      puStack_148 = (ulong *)piStack_130;
      piStack_14c = (int *)0x44dc03;
      (**(code **)(*piStack_130 + 8))();
      if (iVar1 != 0) {
        piStack_14c = (int *)0x44dc0d;
        CoUninitialize();
      }
      piStack_14c = (int *)0x44dc12;
      iVar1 = IsDPlay501a();
      *unaff_retaddr = (iVar1 != 0) + 0x500;
      return;
    }
    if (iVar1 != 0) {
      puStack_148 = (ulong *)0x44dbee;
      CoUninitialize();
      return;
    }
  }
  else {
    *param_1 = 1;
    if (0x549 < (osVer.dwBuildNumber & 0xffff)) {
      *unaff_retaddr = 0x501;
      return;
    }
    apcStack_12c[0] = s_DDRAW_DLL;
    piStack_130 = (int *)0x44dc87;
    piVar2 = (int *)LoadLibraryA();
    if (piVar2 == (int *)0x0) {
      piStack_130 = (int *)0x0;
      *puStack_4 = 0;
      *param_1 = 0;
      piStack_134 = (int *)0x44dc9f;
      FreeLibrary();
      return;
    }
    piStack_130 = (int *)s_DirectDrawCreate;
    puStack_138 = (undefined *)0x44dcb6;
    piStack_134 = piVar2;
    pcVar4 = (code *)GetProcAddress();
    if (pcVar4 == (code *)0x0) {
      *puStack_4 = 0;
      *param_1 = 0;
      piStack_134 = (int *)0x44dccc;
      piStack_130 = piVar2;
      FreeLibrary();
      piStack_134 = (int *)s_Couldn_t_LoadLibrary_DDraw__;
      puStack_138 = (undefined *)0x44dcd7;
      OutputDebugStringA();
      return;
    }
    piStack_134 = (int *)&stack0xfffffee4;
    piStack_130 = (int *)0x0;
    puStack_138 = (undefined *)0x0;
    piStack_13c = (int *)0x44dceb;
    iVar1 = (*pcVar4)();
    if (iVar1 < 0) {
      *(undefined4 *)osVer.szCSDVersion._116_4_ = 0;
      *param_1 = 0;
      piStack_140 = (int *)0x44dd01;
      piStack_13c = piVar2;
      FreeLibrary();
      piStack_140 = (int *)s_Couldn_t_create_DDraw__;
      puStack_144 = (ulong *)0x44dd0c;
      OutputDebugStringA();
      return;
    }
    piStack_13c = (int *)&stack0xfffffee4;
    puVar9 = *(undefined4 **)apcStack_12c[1];
    piStack_140 = (int *)&_IID_IDirectDraw2;
    puStack_144 = (ulong *)apcStack_12c[1];
    *(undefined4 *)osVer.szCSDVersion._116_4_ = 0x100;
    puStack_148 = (ulong *)0x44dd37;
    iVar1 = (*(code *)*puVar9)();
    if (iVar1 < 0) {
      puStack_148 = (ulong *)piStack_134;
      piStack_14c = (int *)0x44dd45;
      (**(code **)(*piStack_134 + 8))();
      piStack_14c = piVar2;
      FreeLibrary();
      OutputDebugStringA(s_Couldn_t_QI_DDraw2__);
      return;
    }
    puStack_148 = (ulong *)apcStack_12c[1];
    piStack_14c = (int *)0x44dd6c;
    (**(code **)(*(ulong *)apcStack_12c[1] + 8))();
    piStack_14c = (int *)s_DINPUT_DLL;
    *(undefined4 *)osVer.szCSDVersion._116_4_ = 0x200;
    iVar1 = LoadLibraryA();
    if (iVar1 == 0) {
      OutputDebugStringA(s_Couldn_t_LoadLibrary_DInput__);
      (**(code **)(*piStack_140 + 8))(piStack_140);
      FreeLibrary(piVar2);
      return;
    }
    puStack_138 = (undefined *)GetProcAddress(iVar1,s_DirectInputCreateA);
    FreeLibrary(iVar1);
    if (piStack_13c == (int *)0x0) {
      FreeLibrary(piVar2);
      (**(code **)(*puStack_144 + 8))(puStack_144);
      OutputDebugStringA(s_Couldn_t_GetProcAddress_DInputCr);
      return;
    }
    puVar9 = (undefined4 *)0x8;
    ppcVar5 = apcStack_12c;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar5 = (char *)0x0;
      ppcVar5 = ppcVar5 + 1;
    }
    *(undefined4 *)osVer.szCSDVersion._116_4_ = 0x300;
    apcStack_12c[0] = (char *)0x6c;
    apcStack_12c[1] = (char *)0x1;
    piVar8 = piStack_140;
    iVar1 = (**(code **)(*piStack_140 + 0x50))(piStack_140,0);
    if (iVar1 < 0) {
      (**(code **)(*piStack_14c + 8))(piStack_14c);
      FreeLibrary(piVar2);
      *(undefined4 *)osVer.szCSDVersion._116_4_ = 0;
      OutputDebugStringA(s_Couldn_t_Set_coop_level__);
      return;
    }
    piVar7 = (int *)0x0;
    ppuVar6 = &puStack_138;
    iVar1 = (**(code **)(*piStack_14c + 0x18))(piStack_14c,ppuVar6,&puStack_144);
    if (iVar1 < 0) {
      (**(code **)(*piVar8 + 8))(piVar8);
      FreeLibrary(piVar2);
      *(undefined4 *)osVer.szCSDVersion._116_4_ = 0;
      OutputDebugStringA(s_Couldn_t_CreateSurface__);
      return;
    }
    iVar1 = (**(code **)*puVar9)(puVar9,&_IID_IDirectDrawSurface3,&piStack_14c);
    if (-1 < iVar1) {
      iVar1 = IsDPlay501a();
      *(uint *)osVer.szCSDVersion._116_4_ = (iVar1 != 0) + 0x500;
      (**(code **)(*piVar7 + 8))(piVar7);
    }
    (**(code **)(*ppuVar6 + 8))(ppuVar6);
    FreeLibrary(piVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044dedd
// Address: 0044dedd
// XREFS: None
// [HELPER] s__: "}"
// [HELPER] s_dplayx_dll: "dplayx.dll"
undefined4 FUN_0044dedd(void)
{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  uint *puVar6;
  uint uStack_24;
  char *pcStack_1c;
  undefined1 *puStack_18;
  undefined1 auStack_8 [8];
  
  puStack_18 = auStack_8;
  pcStack_1c = s_dplayx_dll;
  uVar1 = _GetFileVersionInfoSizeA_8();
  if (uVar1 == 0) {
    GetLastError();
    return 0;
  }
  uStack_24 = 0x44df0e;
  pvVar2 = operator_new(uVar1);
  if (pvVar2 != (void *)0x0) {
    uStack_24 = uVar1;
    iVar3 = _GetFileVersionInfoA_16(s_dplayx_dll,0);
    if (iVar3 == 0) {
      GetLastError();
      return 0;
    }
    puVar6 = &uStack_24;
    iVar3 = _VerQueryValueA_16(pvVar2,s__,puVar6,&pcStack_1c);
    if (iVar3 == 0) {
      return 0;
    }
    bVar4 = puVar6[2] < 0x40005;
    bVar5 = puVar6[2] == 0x40005;
    if (bVar5) {
      if (0x1062e < puVar6[3]) {
        return 1;
      }
      bVar4 = false;
      bVar5 = true;
    }
    if (!bVar4 && !bVar5) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: IsDPlay501a
// Address: 0044dee0
// XREFS: GetDXVersion
// [HELPER] s__: "}"
// [HELPER] s_dplayx_dll: "dplayx.dll"
/* WARNING: Variable defined which should be unmapped: verInfo */
/* int __cdecl IsDPlay501a(void) */

int __cdecl IsDPlay501a(void)
{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  uint *puVar6;
  uint uStack_24;
  char *pcStack_1c;
  uint *puStack_18;
  tagVS_FIXEDFILEINFO *verInfo;
  ulong zero;
  uint verSize;
  
  puStack_18 = &verSize;
  pcStack_1c = s_dplayx_dll;
  uVar1 = _GetFileVersionInfoSizeA_8();
  if (uVar1 == 0) {
    GetLastError();
    return 0;
  }
  uStack_24 = 0x44df0e;
  pvVar2 = operator_new(uVar1);
  if (pvVar2 != (void *)0x0) {
    uStack_24 = uVar1;
    iVar3 = _GetFileVersionInfoA_16(s_dplayx_dll,0);
    if (iVar3 == 0) {
      GetLastError();
      return 0;
    }
    puVar6 = &uStack_24;
    iVar3 = _VerQueryValueA_16(pvVar2,s__,puVar6,&pcStack_1c);
    if (iVar3 == 0) {
      return 0;
    }
    bVar4 = puVar6[2] < 0x40005;
    bVar5 = puVar6[2] == 0x40005;
    if (bVar5) {
      if (0x1062e < puVar6[3]) {
        return 1;
      }
      bVar4 = false;
      bVar5 = true;
    }
    if (!bVar4 && !bVar5) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044e022
// Address: 0044e022
// XREFS: None
InfluenceMap * __thiscall FUN_0044e022(InfluenceMap *param_1,byte param_2)
{
  InfluenceMap::~InfluenceMap(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044e04e
// Address: 0044e04e
// XREFS: None
InfluenceMap * __thiscall FUN_0044e04e(InfluenceMap *param_1,int param_2)
{
  param_1->xSizeValue = -1;
  param_1->ySizeValue = -1;
  param_1->_padding_ = (int)&InfluenceMap::_vftable_;
  param_1->xReferencePointValue = 0;
  param_1->yReferencePointValue = 0;
  InfluenceMap::load(param_1,param_2);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044e07a
// Address: 0044e07a
// XREFS: None
void __fastcall FUN_0044e07a(undefined4 *param_1)
{
  *param_1 = &InfluenceMap::_vftable_;
  if ((void *)param_1[5] != (void *)0x0) {
    operator_delete((void *)param_1[5]);
  }
  if ((void *)param_1[6] != (void *)0x0) {
    operator_delete((void *)param_1[6]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044e0ab
// Address: 0044e0ab
// XREFS: None
undefined4 __thiscall FUN_0044e0ab(int param_1,undefined1 param_2)
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = *(int *)(param_1 + 8) * *(int *)(param_1 + 4);
  puVar3 = *(undefined4 **)(param_1 + 0x14);
  for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    puVar3 = puVar3 + 1;
  }
  for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar3 = param_2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044e0eb
// Address: 0044e0eb
// XREFS: None
void __thiscall FUN_0044e0eb(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2;
  piVar1 = (int *)(param_1 + 4);
  rge_write(param_2,piVar1,4);
  rge_write(param_2,(int *)(param_1 + 8),4);
  rge_write(param_2,(void *)(param_1 + 0xc),4);
  rge_write(param_2,(void *)(param_1 + 0x10),4);
  rge_write(param_2,(void *)(param_1 + 0x24),1);
  param_2 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      iVar3 = 0;
      if (0 < *piVar1) {
        do {
          rge_write(iVar2,(void *)(*(int *)(*(int *)(param_1 + 0x18) + param_2 * 4) + iVar3),1);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *piVar1);
      }
      param_2 = param_2 + 1;
    } while (param_2 < *(int *)(param_1 + 8));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044e193
// Address: 0044e193
// XREFS: None
void __thiscall FUN_0044e193(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  iVar2 = param_2;
  piVar1 = (int *)(param_1 + 4);
  rge_read(param_2,piVar1,4);
  rge_read(iVar2,(int *)(param_1 + 8),4);
  rge_read(iVar2,(void *)(param_1 + 0xc),4);
  rge_read(iVar2,(void *)(param_1 + 0x10),4);
  rge_read(iVar2,(void *)(param_1 + 0x24),1);
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      iVar3 = 0;
      if (0 < *piVar1) {
        do {
          rge_read(iVar2,&param_2,1);
          iVar3 = iVar3 + 1;
          *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x18) + iStack_4 * 4) + -1 + iVar3) =
               (undefined1)param_2;
        } while (iVar3 < *piVar1);
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < *(int *)(param_1 + 8));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044e24f
// Address: 0044e24f
// XREFS: None
// [HELPER] s_FILENAME___s_: "FILENAME: %s\n"
// [HELPER] s_R_03d__: "R%03d: "
// [HELPER] s__03d_: "%03d "
// [HELPER] s__: "}"
// [HELPER] s__R_03d_: ":R%03d\n"
// [HELPER] s__R_03d__: ":R%03d\n\n"
// [HELPER] s___03d_: " %03d "
// [HELPER] s___Dimensions___d_X__d_: "  Dimensions: %d X %d\n"
// [HELPER] s___Reference_Point____d___d__: "  Reference Point: (%d, %d)\n"
// [HELPER] s_____: "--- "
// [HELPER] s______: "---- "
// [HELPER] s_______: "      "
// [HELPER] s_wa: "wa"
void __thiscall FUN_0044e24f(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 != 0) {
    iVar1 = fopen(param_2,s_wa);
    if (iVar1 != 0) {
      fprintf(iVar1,s_FILENAME___s_,param_2);
      fprintf(iVar1,s___Dimensions___d_X__d_,*(undefined4 *)(param_1 + 4),
              *(undefined4 *)(param_1 + 8));
      fprintf(iVar1,s___Reference_Point____d___d__,*(undefined4 *)(param_1 + 0xc),
              *(undefined4 *)(param_1 + 0x10));
      fprintf(iVar1,&s__);
      fprintf(iVar1,s_______);
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 4)) {
        do {
          if (iVar2 % 5 == 0) {
            pcVar3 = s___03d_;
          }
          else {
            pcVar3 = s__03d_;
          }
          fprintf(iVar1,pcVar3,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 4));
      }
      fprintf(iVar1,&s__);
      fprintf(iVar1,s_______);
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 4)) {
        do {
          if (iVar2 % 5 == 0) {
            pcVar3 = s______;
          }
          else {
            pcVar3 = s_____;
          }
          fprintf(iVar1,pcVar3,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 4));
      }
      fprintf(iVar1,&s__);
      param_2 = 0;
      if (0 < *(int *)(param_1 + 8)) {
        do {
          fprintf(iVar1,s_R_03d__,param_2);
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 4)) {
            do {
              if (iVar2 % 5 == 0) {
                pcVar3 = s___03d_;
              }
              else {
                pcVar3 = s__03d_;
              }
              fprintf(iVar1,pcVar3,
                      *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x18) + param_2 * 4) + iVar2));
              iVar2 = iVar2 + 1;
            } while (iVar2 < *(int *)(param_1 + 4));
          }
          iVar2 = param_2 + 1;
          if (iVar2 % 5 == 0) {
            pcVar3 = s__R_03d__;
          }
          else {
            pcVar3 = s__R_03d_;
          }
          fprintf(iVar1,pcVar3,param_2);
          param_2 = iVar2;
        } while (iVar2 < *(int *)(param_1 + 8));
      }
      fprintf(iVar1,s_______);
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 4)) {
        do {
          if (iVar2 % 5 == 0) {
            pcVar3 = s______;
          }
          else {
            pcVar3 = s_____;
          }
          fprintf(iVar1,pcVar3,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 4));
      }
      fprintf(iVar1,&s__);
      fprintf(iVar1,s_______);
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 4)) {
        do {
          if (iVar2 % 5 == 0) {
            pcVar3 = s___03d_;
          }
          else {
            pcVar3 = s__03d_;
          }
          fprintf(iVar1,pcVar3,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 4));
      }
      fprintf(iVar1,&s__);
      fclose(iVar1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044e4b3
// Address: 0044e4b3
// XREFS: None
void __thiscall FUN_0044e4b3(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0044e4d1
// Address: 0044e4d1
// XREFS: None
undefined1 __thiscall FUN_0044e4d1(int param_1,int param_2,int param_3)
{
  return *(undefined1 *)
          ((*(int *)(*(int *)(param_1 + 0x18) + (param_3 - *(int *)(param_1 + 0x10)) * 4) -
           *(int *)(param_1 + 0xc)) + param_2);
}

// --------------------------------------------------

// Function: FUN_0044e502
// Address: 0044e502
// XREFS: None
undefined4 __thiscall FUN_0044e502(int param_1,int param_2,int param_3,undefined1 param_4)
{
  param_2 = param_2 - *(int *)(param_1 + 0xc);
  param_3 = param_3 - *(int *)(param_1 + 0x10);
  if ((((-1 < param_2) && (-1 < param_3)) && (param_2 < *(int *)(param_1 + 4))) &&
     (param_3 < *(int *)(param_1 + 8))) {
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x18) + param_3 * 4) + param_2) = param_4;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044e551
// Address: 0044e551
// XREFS: None
undefined4 __thiscall
FUN_0044e551(int param_1,int param_2,int param_3,int param_4,int param_5,undefined1 param_6)
{
  int iVar1;
  
  param_4 = param_4 - *(int *)(param_1 + 0xc);
  param_2 = param_2 - *(int *)(param_1 + 0xc);
  param_3 = param_3 - *(int *)(param_1 + 0x10);
  param_5 = param_5 - *(int *)(param_1 + 0x10);
  if (((((-1 < param_2) && (-1 < param_3)) && (param_2 < *(int *)(param_1 + 4))) &&
      ((param_3 < *(int *)(param_1 + 8) && (-1 < param_4)))) &&
     ((-1 < param_5 && ((param_4 < *(int *)(param_1 + 4) && (param_5 < *(int *)(param_1 + 8))))))) {
    for (; param_3 <= param_5; param_3 = param_3 + 1) {
      if (param_2 <= param_4) {
        iVar1 = param_2;
        do {
          iVar1 = iVar1 + 1;
          *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x18) + param_3 * 4) + -1 + iVar1) = param_6;
        } while (iVar1 <= param_4);
      }
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044e5f9
// Address: 0044e5f9
// XREFS: None
undefined4 __thiscall FUN_0044e5f9(int param_1,int param_2,int param_3,uint param_4)
{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  param_2 = param_2 - *(int *)(param_1 + 0xc);
  param_3 = param_3 - *(int *)(param_1 + 0x10);
  if ((((param_2 < 0) || (param_3 < 0)) || (*(int *)(param_1 + 4) <= param_2)) ||
     (*(int *)(param_1 + 8) <= param_3)) {
    return 0;
  }
  bVar2 = *(byte *)(param_1 + 0x24);
  iVar4 = *(int *)(*(int *)(param_1 + 0x18) + param_3 * 4);
  pcVar1 = (char *)(iVar4 + param_2);
  bVar3 = *(byte *)(iVar4 + param_2);
  if (bVar2 <= bVar3) {
    return 1;
  }
  uVar5 = (param_4 & 0xff) + (uint)bVar3;
  if (bVar2 <= uVar5) {
    *pcVar1 = bVar2 - 1;
    return 1;
  }
  *pcVar1 = (char)uVar5;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044e67b
// Address: 0044e67b
// XREFS: None
undefined4 __thiscall
FUN_0044e67b(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  param_2 = param_2 - *(int *)(param_1 + 0xc);
  param_4 = param_4 - *(int *)(param_1 + 0xc);
  iVar4 = param_3 - *(int *)(param_1 + 0x10);
  param_5 = param_5 - *(int *)(param_1 + 0x10);
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (*(int *)(param_1 + 4) <= param_2) {
    param_2 = *(int *)(param_1 + 4) + -1;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  else if (*(int *)(param_1 + 4) <= iVar4) {
    iVar4 = *(int *)(param_1 + 4) + -1;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (*(int *)(param_1 + 4) <= param_4) {
    param_4 = *(int *)(param_1 + 4) + -1;
  }
  if (param_5 < 0) {
    param_5 = 0;
  }
  else if (*(int *)(param_1 + 4) <= param_5) {
    param_5 = *(int *)(param_1 + 4) + -1;
  }
  if (iVar4 <= param_5) {
    param_3 = iVar4 * 4;
    param_5 = (param_5 - iVar4) + 1;
    iVar4 = param_2;
    do {
      for (; iVar4 <= param_4; iVar4 = iVar4 + 1) {
        bVar1 = *(byte *)(param_1 + 0x24);
        iVar2 = *(int *)(param_3 + *(int *)(param_1 + 0x18));
        if (*(byte *)(iVar4 + iVar2) < bVar1) {
          uVar3 = (param_6 & 0xff) + (uint)*(byte *)(iVar4 + iVar2);
          if (uVar3 < bVar1) {
            *(char *)(iVar4 + iVar2) = (char)uVar3;
          }
          else {
            *(char *)(iVar4 + iVar2) = bVar1 - 1;
          }
        }
      }
      param_3 = param_3 + 4;
      param_5 = param_5 + -1;
      iVar4 = param_2;
    } while (param_5 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044e783
// Address: 0044e783
// XREFS: None
undefined4 __thiscall FUN_0044e783(int param_1,int param_2,int param_3,uint param_4)
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  param_2 = param_2 - *(int *)(param_1 + 0xc);
  param_3 = param_3 - *(int *)(param_1 + 0x10);
  if ((((-1 < param_2) && (-1 < param_3)) && (param_2 < *(int *)(param_1 + 4))) &&
     (param_3 < *(int *)(param_1 + 8))) {
    pbVar3 = (byte *)(*(int *)(*(int *)(param_1 + 0x18) + param_3 * 4) + param_2);
    bVar1 = *pbVar3;
    if (*(byte *)(param_1 + 0x24) <= bVar1) {
      return 1;
    }
    iVar2 = (uint)bVar1 - (param_4 & 0xff);
    *pbVar3 = (iVar2 < 0) - 1U & (byte)iVar2;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044e7fb
// Address: 0044e7fb
// XREFS: None
undefined4 __thiscall
FUN_0044e7fb(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  param_2 = param_2 - *(int *)(param_1 + 0xc);
  param_4 = param_4 - *(int *)(param_1 + 0xc);
  iVar3 = param_3 - *(int *)(param_1 + 0x10);
  param_5 = param_5 - *(int *)(param_1 + 0x10);
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (*(int *)(param_1 + 4) <= param_2) {
    param_2 = *(int *)(param_1 + 4) + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (*(int *)(param_1 + 4) <= iVar3) {
    iVar3 = *(int *)(param_1 + 4) + -1;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (*(int *)(param_1 + 4) <= param_4) {
    param_4 = *(int *)(param_1 + 4) + -1;
  }
  if (param_5 < 0) {
    param_5 = 0;
  }
  else if (*(int *)(param_1 + 4) <= param_5) {
    param_5 = *(int *)(param_1 + 4) + -1;
  }
  if (iVar3 <= param_5) {
    param_3 = (param_5 - iVar3) + 1;
    iVar3 = iVar3 * 4;
    iVar1 = param_2;
    do {
      for (; iVar1 <= param_4; iVar1 = iVar1 + 1) {
        if (*(byte *)(iVar1 + *(int *)(*(int *)(param_1 + 0x18) + iVar3)) <
            *(byte *)(param_1 + 0x24)) {
          pbVar4 = (byte *)(*(int *)(*(int *)(param_1 + 0x18) + iVar3) + iVar1);
          iVar2 = (uint)*pbVar4 - (param_6 & 0xff);
          *pbVar4 = (iVar2 < 0) - 1U & (byte)iVar2;
        }
      }
      iVar3 = iVar3 + 4;
      param_3 = param_3 + -1;
      iVar1 = param_2;
    } while (param_3 != 0);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044e8f2
// Address: 0044e8f2
// XREFS: None
undefined4 __thiscall FUN_0044e8f2(int param_1,int *param_2,int *param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x1c) = 0;
  iVar4 = *param_2;
  if (((((-1 < iVar4) && (-1 < param_2[1])) && (iVar4 < *(int *)(param_1 + 4))) &&
      ((param_2[1] < *(int *)(param_1 + 8) && (iVar3 = *param_3, -1 < iVar3)))) &&
     ((iVar1 = param_3[1], -1 < iVar1 &&
      ((iVar3 < *(int *)(param_1 + 4) && (iVar1 < *(int *)(param_1 + 8))))))) {
    if (iVar4 <= iVar3) {
      do {
        iVar3 = param_2[1];
        if (iVar3 <= iVar1) {
          iVar2 = iVar3 * 4;
          do {
            if (param_4 <=
                (int)(uint)*(byte *)(*(int *)(iVar2 + *(int *)(param_1 + 0x10) * -4 +
                                             *(int *)(param_1 + 0x18)) +
                                    (iVar4 - *(int *)(param_1 + 0xc)))) {
              *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
            }
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 4;
            iVar1 = param_3[1];
          } while (iVar3 <= iVar1);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= *param_3);
    }
    return *(undefined4 *)(param_1 + 0x1c);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044e9dd
// Address: 0044e9dd
// XREFS: None
undefined4 __thiscall
FUN_0044e9dd(int param_1,int *param_2,int *param_3,int param_4,int param_5,int param_6,int param_7)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_20;
  int iStack_1c;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar7 = *param_2;
  if ((((iVar7 < 0) || (param_2[1] < 0)) || (iVar1 = *(int *)(param_1 + 4), iVar1 <= iVar7)) ||
     (((iVar2 = *(int *)(param_1 + 8), iVar2 <= param_2[1] || (iVar4 = *param_3, iVar4 < 0)) ||
      ((iVar6 = param_3[1], iVar6 < 0 || ((iVar1 <= iVar4 || (iVar2 <= iVar6)))))))) {
    return 0;
  }
  if (iVar7 <= iVar4) {
    do {
      iStack_1c = param_2[1];
      if (iStack_1c <= iVar6) {
        iStack_20 = iStack_1c * 4;
        do {
          if (param_4 <=
              (int)(uint)*(byte *)(*(int *)(iStack_20 + *(int *)(param_1 + 0x10) * -4 +
                                           *(int *)(param_1 + 0x18)) +
                                  (iVar7 - *(int *)(param_1 + 0xc)))) {
            uVar5 = 0;
            iVar4 = iStack_1c;
            iVar6 = iStack_20;
            iVar8 = iVar7;
            do {
              switch(uVar5) {
              case 0:
                iVar8 = iVar8 + -1;
              case 7:
                iVar4 = iVar4 + -1;
                iVar6 = iVar6 + -4;
                break;
              case 1:
              case 2:
                iVar8 = iVar8 + 1;
                break;
              case 3:
              case 4:
                iVar4 = iVar4 + 1;
                iVar6 = iVar6 + 4;
                break;
              case 5:
              case 6:
                iVar8 = iVar8 + -1;
              }
              uVar3 = (int)uVar5 >> 0x1f;
              if ((param_7 != 0) || (((uVar5 ^ uVar3) - uVar3 & 1 ^ uVar3) != uVar3)) {
                if ((iVar8 < 0) || (((iVar1 <= iVar8 || (iVar4 < 0)) || (iVar2 <= iVar4)))) {
                  if (((param_5 == 1) && (((uVar5 ^ uVar3) - uVar3 & 1 ^ uVar3) - uVar3 == 1)) ||
                     ((param_6 == 1 && (((uVar5 ^ uVar3) - uVar3 & 1 ^ uVar3) == uVar3))))
                  goto LAB_0044eb54;
                }
                else if (param_4 <=
                         (int)(uint)*(byte *)((*(int *)(iVar6 + *(int *)(param_1 + 0x10) * -4 +
                                                       *(int *)(param_1 + 0x18)) + iVar8) -
                                             *(int *)(param_1 + 0xc))) {
LAB_0044eb54:
                  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
                }
              }
              uVar5 = uVar5 + 1;
            } while ((int)uVar5 < 8);
          }
          iStack_20 = iStack_20 + 4;
          iStack_1c = iStack_1c + 1;
          iVar6 = param_3[1];
        } while (iStack_1c <= iVar6);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= *param_3);
  }
  return *(undefined4 *)(param_1 + 0x20);
}

// --------------------------------------------------

// Function: FUN_0044ebd2
// Address: 0044ebd2
// XREFS: None
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_0044ed13
// Address: 0044ed13
// XREFS: None
int __thiscall
FUN_0044ed13(int param_1,int *param_2,int *param_3,byte param_4,uint param_5,int param_6,int param_7
            ,int param_8)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iStack_34;
  
  iVar11 = *param_2;
  iVar13 = *(int *)(param_1 + 0x20);
  if ((((iVar11 < 0) || (iVar1 = param_2[1], iVar1 < 0)) ||
      (iVar2 = *(int *)(param_1 + 4), iVar2 <= iVar11)) ||
     (((iVar3 = *(int *)(param_1 + 8), iVar3 <= iVar1 || (iVar4 = *param_3, iVar4 < 0)) ||
      ((iVar5 = param_3[1], iVar5 < 0 || ((iVar2 <= iVar4 || (iStack_34 = iVar13, iVar3 <= iVar5))))
      )))) {
    return 0;
  }
  do {
    if (iVar4 < iVar11) {
      return iVar13;
    }
    if (iVar1 <= iVar5) {
      iVar6 = *(int *)(param_1 + 0x18);
      iVar9 = iVar11 - *(int *)(param_1 + 0xc);
      iVar8 = iVar1 * 4;
      iVar7 = *(int *)(param_1 + 0x10);
      param_2 = (int *)iVar1;
      do {
        if ((uint)param_4 <=
            (uint)*(byte *)(*(int *)(iVar8 + iVar7 * -4 + iVar6) + iVar9) + (param_5 & 0xff)) {
          if (param_4 <= *(byte *)(*(int *)(iVar8 + iVar7 * -4 + iVar6) + iVar9)) {
            uVar14 = 0;
            iVar12 = (int)param_2;
            iVar16 = iVar11;
            do {
              switch(uVar14) {
              case 0:
                iVar16 = iVar16 + -1;
              case 7:
                iVar12 = iVar12 + -1;
                break;
              case 1:
              case 2:
                iVar16 = iVar16 + 1;
                break;
              case 3:
              case 4:
                iVar12 = iVar12 + 1;
                break;
              case 5:
              case 6:
                iVar16 = iVar16 + -1;
              }
              uVar10 = (int)uVar14 >> 0x1f;
              if ((param_8 != 0) || (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) != uVar10)) {
                if (((iVar16 < 0) || (((iVar2 <= iVar16 || (iVar12 < 0)) || (iVar3 <= iVar12)))) &&
                   (((param_6 == 1 && (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) - uVar10 == 1)) ||
                    ((param_7 == 1 && (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))))) {
                  iVar13 = iVar13 + -1;
                }
                iStack_34 = iVar13;
                if (iVar13 < 1) break;
              }
              uVar14 = uVar14 + 1;
              iStack_34 = iVar13;
            } while ((int)uVar14 < 8);
          }
          uVar14 = 0;
          iVar12 = (int)param_2;
          iVar16 = iVar8;
          iVar15 = iVar11;
          do {
            switch(uVar14) {
            case 0:
              iVar15 = iVar15 + -1;
            case 7:
              iVar12 = iVar12 + -1;
              iVar16 = iVar16 + -4;
              break;
            case 1:
            case 2:
              iVar15 = iVar15 + 1;
              break;
            case 3:
            case 4:
              iVar12 = iVar12 + 1;
              iVar16 = iVar16 + 4;
              break;
            case 5:
            case 6:
              iVar15 = iVar15 + -1;
            }
            uVar10 = (int)uVar14 >> 0x1f;
            if ((param_8 != 0) || (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) != uVar10)) {
              if ((iVar15 < 0) || (((iVar2 <= iVar15 || (iVar12 < 0)) || (iVar3 <= iVar12)))) {
                if (((param_6 == 1) && (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) - uVar10 == 1)) ||
                   ((param_7 == 1 && (((uVar14 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))) {
                  iStack_34 = iStack_34 + -1;
                }
              }
              else if (param_4 <=
                       *(byte *)((*(int *)(iVar16 + iVar7 * -4 + iVar6) + iVar15) -
                                *(int *)(param_1 + 0xc))) {
                iStack_34 = iStack_34 + 2;
              }
            }
            uVar14 = uVar14 + 1;
            iVar13 = iStack_34;
          } while ((int)uVar14 < 8);
        }
        param_2 = (int *)((int)param_2 + 1);
        iVar8 = iVar8 + 4;
      } while ((int)param_2 <= iVar5);
    }
    iVar11 = iVar11 + 1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0044efe9
// Address: 0044efe9
// XREFS: None
void __fastcall FUN_0044efe9(undefined4 param_1,undefined2 param_2)
{
  byte bVar1;
  char cVar2;
  uint in_EAX;
  char cVar3;
  char cVar5;
  undefined2 uVar4;
  char unaff_BL;
  char cVar6;
  
  bVar1 = (byte)in_EAX;
  out(param_2,bVar1);
  out(param_2,in_EAX);
  out(param_2,in_EAX);
  out(param_2,in_EAX);
  out(param_2,in_EAX);
  cVar2 = (char)(in_EAX >> 8);
  cVar6 = unaff_BL + cVar2 * '\x02';
  out(param_2,in_EAX);
  out(param_2,in_EAX);
  *(char *)(in_EAX - 0x12) = *(char *)(in_EAX - 0x12) + (char)param_2;
  out(param_2,bVar1);
  cVar5 = (char)((ushort)param_2 >> 8);
  cVar3 = (char)param_2 + cVar6;
  out(CONCAT11(cVar5,cVar3),bVar1);
  cVar3 = cVar3 + cVar6;
  uVar4 = CONCAT11(cVar5,cVar3);
  out(uVar4,bVar1);
  out(uVar4,bVar1);
  out(uVar4,bVar1);
  out(uVar4,bVar1);
  out(uVar4,bVar1);
  out(CONCAT11(cVar5 + cVar2,cVar3),bVar1);
  *(char *)(in_EAX + 0x8a909090) = *(char *)(in_EAX + 0x8a909090) + cVar3;
  if ((in_EAX & 4) != 0) {
    *(byte *)(CONCAT22((short)((uint)param_1 >> 0x10),
                       CONCAT11((char)((uint)param_1 >> 8) + unaff_BL * '\x02' + cVar6 * '\x02',
                                (char)param_1)) + 0x24) = bVar1 & 4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044f03e
// Address: 0044f03e
// XREFS: None
void __fastcall FUN_0044f03e(int param_1)
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4) * *(int *)(param_1 + 8);
  iVar3 = 0;
  bVar2 = **(byte **)(param_1 + 0x14);
  if (0 < iVar4) {
    do {
      bVar1 = (*(byte **)(param_1 + 0x14))[iVar3];
      if (bVar2 < bVar1) {
        bVar2 = bVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044f069
// Address: 0044f069
// XREFS: None
RGE_Master_Action_Object * __thiscall
FUN_0044f069(RGE_Master_Action_Object *param_1,RGE_Master_Action_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d638;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object
            ((RGE_Master_Moving_Object *)param_1,(RGE_Master_Moving_Object *)param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Action_Object::_vftable_;
  if (param_3 != 0) {
    RGE_Master_Action_Object::setup(param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044f0cd
// Address: 0044f0cd
// XREFS: None
RGE_Master_Action_Object * __thiscall FUN_0044f0cd(RGE_Master_Action_Object *param_1,byte param_2)
{
  RGE_Master_Action_Object::~RGE_Master_Action_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044f0ee
// Address: 0044f0ee
// XREFS: None
RGE_Master_Action_Object * __thiscall
FUN_0044f0ee(RGE_Master_Action_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4,
            int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d658;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object
            ((RGE_Master_Moving_Object *)param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Action_Object::_vftable_;
  if (param_5 != 0) {
    RGE_Master_Action_Object::setup(param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044f15d
// Address: 0044f15d
// XREFS: None
RGE_Master_Action_Object * __thiscall
FUN_0044f15d(RGE_Master_Action_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d678;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object
            ((RGE_Master_Moving_Object *)param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Action_Object::_vftable_;
  if (param_6 != 0) {
    RGE_Master_Action_Object::setup(param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044f1d7
// Address: 0044f1d7
// XREFS: None
undefined4 __thiscall
FUN_0044f1d7(RGE_Master_Moving_Object *param_1,RGE_Master_Moving_Object *param_2)
{
  int iVar1;
  RGE_Task_List *this;
  
  RGE_Master_Moving_Object::setup(param_1,param_2);
  *(undefined1 *)&param_1->_padding_ = 0x28;
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  iVar1 = param_1->_padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  this = (RGE_Task_List *)(**(code **)(iVar1 + 0x38))();
  param_1[1]._padding_ = (int)this;
  RGE_Task_List::copy(this,(RGE_Task_List *)param_2[1]._padding_);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044f289
// Address: 0044f289
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0044f289(RGE_Master_Moving_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sprite **param_4
            )
{
  RGE_Sprite **ppRVar1;
  RGE_Sprite **ppRVar2;
  RGE_Sprite *pRVar3;
  RGE_Task_List *this;
  
  ppRVar2 = param_4;
  ppRVar1 = param_3;
  RGE_Master_Moving_Object::setup(param_1,param_2,param_3,(RGE_Sound **)param_4);
  *(undefined1 *)&param_1->_padding_ = 0x28;
  rge_read(param_2,&param_1[1]._padding_,2);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,2);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_read(param_2,&param_1[1]._padding_,1);
  rge_read(param_2,&param_4,2);
  if (save_game_version < _DAT_00570484) {
    param_3 = param_4;
  }
  else {
    rge_read(param_2,&param_3,2);
  }
  rge_read(param_2,&param_1[1]._padding_,1);
  if ((short)param_4 < 0) {
    pRVar3 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar3 = ppRVar2[(short)param_4];
  }
  param_1[1]._padding_ = (int)pRVar3;
  if ((short)param_3 < 0) {
    pRVar3 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar3 = ppRVar2[(short)param_3];
  }
  param_1[1]._padding_ = (int)pRVar3;
  this = (RGE_Task_List *)(**(code **)(param_1->_padding_ + 0x38))();
  param_1[1]._padding_ = (int)this;
  RGE_Task_List::load(this,param_2,ppRVar1,(RGE_Sound **)ppRVar2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044f3be
// Address: 0044f3be
// XREFS: None
// [HELPER] s__f__f__hd__hd__hd__hd__hd__hd: "%f %f %hd %hd %hd %hd %hd %hd"
undefined4 __thiscall
FUN_0044f3be(RGE_Master_Moving_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,undefined4 param_5)
{
  _iobuf *p_Var1;
  RGE_Sprite **ppRVar2;
  RGE_Sound **ppRVar3;
  RGE_Sound *pRVar4;
  RGE_Task_List *this;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  ppRVar3 = param_4;
  ppRVar2 = param_3;
  p_Var1 = param_2;
  RGE_Master_Moving_Object::setup(param_1,param_2,param_3,param_4,(short)param_5);
  *(undefined1 *)&param_1->_padding_ = 0x28;
  fscanf(p_Var1,s__f__f__hd__hd__hd__hd__hd__hd,&param_1[1]._padding_,&param_1[1]._padding_,
         &param_1[1]._padding_,(undefined1 *)((int)&param_1[1]._padding_ + 2),&param_5,&param_3,
         &param_2,&param_4);
  *(undefined1 *)&param_1[1]._padding_ = (undefined1)param_5;
  *(undefined1 *)&param_1[1]._padding_ = param_4._0_1_;
  if ((short)param_3 < 0) {
    pRVar4 = (RGE_Sound *)0x0;
  }
  else {
    pRVar4 = ppRVar3[(short)param_3];
  }
  param_1[1]._padding_ = (int)pRVar4;
  if ((short)param_2 < 0) {
    pRVar4 = (RGE_Sound *)0x0;
  }
  else {
    pRVar4 = ppRVar3[(short)param_2];
  }
  iVar5 = param_1->_padding_;
  param_1[1]._padding_ = (int)pRVar4;
  this = (RGE_Task_List *)(**(code **)(iVar5 + 0x38))();
  param_1[1]._padding_ = (int)this;
  RGE_Task_List::load(this,p_Var1,ppRVar2,ppRVar3);
  *(undefined2 *)&param_1[1]._padding_ = 0xffff;
  iVar5 = 0;
  iVar6 = (int)*(short *)(param_1[1]._padding_ + 8);
  if (0 < iVar6) {
    piVar7 = *(int **)(param_1[1]._padding_ + 4);
    while (*(char *)(*piVar7 + 4) == '\0') {
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 1;
      if (iVar6 <= iVar5) {
        return 1;
      }
    }
    *(short *)&param_1[1]._padding_ = (short)iVar5;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044f4cc
// Address: 0044f4cc
// XREFS: None
void __fastcall FUN_0044f4cc(RGE_Master_Moving_Object *param_1)
{
  RGE_Task_List *this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d698;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Master_Action_Object::_vftable_;
  this = (RGE_Task_List *)param_1[1]._padding_;
  uStack_4 = 0;
  if (this != (RGE_Task_List *)0x0) {
    RGE_Task_List::~RGE_Task_List(this);
    operator_delete(this);
    param_1[1]._padding_ = 0;
  }
  uStack_4 = 0xffffffff;
  RGE_Master_Moving_Object::~RGE_Master_Moving_Object(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0044f597
// Address: 0044f597
// XREFS: None
RGE_Static_Object * __thiscall
FUN_0044f597(RGE_Master_Action_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  RGE_Static_Object *pRVar1;
  RGE_Action_Object *this;
  float *unaff_FS_OFFSET;
  float fStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  fStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d6db;
  *unaff_FS_OFFSET = (float)&fStack_c;
  if ((char)param_1->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_2->world,(uchar)param_1->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = param_4;
      return pRVar1;
    }
  }
  this = (RGE_Action_Object *)operator_new(0x194);
  uStack_4 = 0;
  if (this != (RGE_Action_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Action_Object::RGE_Action_Object(this,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = fStack_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = fStack_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: FUN_0044f669
// Address: 0044f669
// XREFS: None
undefined4 __fastcall FUN_0044f669(RGE_Master_Action_Object *param_1)
{
  RGE_Master_Action_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d6fb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Master_Action_Object *)operator_new(0xfc);
  uStack_4 = 0;
  if (this != (RGE_Master_Action_Object *)0x0) {
    uVar1 = RGE_Master_Action_Object::RGE_Master_Action_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044f6d2
// Address: 0044f6d2
// XREFS: None
undefined4 __thiscall FUN_0044f6d2(int param_1,short param_2)
{
  if ((param_2 != -1) && (param_2 < *(short *)(*(int *)(param_1 + 0xd8) + 8))) {
    return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xd8) + 4) + param_2 * 4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044f708
// Address: 0044f708
// XREFS: None
int __thiscall FUN_0044f708(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 != -1) {
    iVar2 = 0;
    iVar4 = (int)*(short *)(*(int *)(param_1 + 0xd8) + 8);
    if (0 < iVar4) {
      piVar1 = *(int **)(*(int *)(param_1 + 0xd8) + 4);
      piVar3 = piVar1;
      do {
        if (param_2 == *(short *)(*piVar3 + 6)) {
          return piVar1[iVar2];
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar2 < iVar4);
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044f75c
// Address: 0044f75c
// XREFS: None
void __thiscall FUN_0044f75c(RGE_Master_Moving_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Master_Moving_Object::copy_obj(param_1,param_2);
  *(undefined2 *)&param_1[1]._padding_ = *(undefined2 *)&param_2[1].undead_flag;
  param_1[1]._padding_ = (int)param_2[1].los;
  param_1[1]._padding_ = *(int *)&param_2[1].obj_max;
  *(undefined2 *)&param_1[1]._padding_ = *(undefined2 *)&param_2[1].radius_x;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1].radius_x + 2);
  *(undefined1 *)&param_1[1]._padding_ = *(undefined1 *)&param_2[1].radius_y;
  param_1[1]._padding_ = (int)param_2[1].radius_z;
  param_1[1]._padding_ = (int)param_2[1].selected_sound;
  RGE_Task_List::copy((RGE_Task_List *)param_1[1]._padding_,
                      (RGE_Task_List *)param_2[1].undead_sprite);
  return;
}

// --------------------------------------------------

// Function: FUN_0044f7eb
// Address: 0044f7eb
// XREFS: None
void __thiscall FUN_0044f7eb(RGE_Master_Moving_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\r') {
    RGE_Master_Moving_Object::modify(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044f813
// Address: 0044f813
// XREFS: None
void __thiscall FUN_0044f813(RGE_Master_Moving_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\r') {
    RGE_Master_Moving_Object::modify_delta(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)(param_2 + (float)param_1[1]._padding_);
  return;
}

// --------------------------------------------------

// Function: FUN_0044f849
// Address: 0044f849
// XREFS: None
void __thiscall FUN_0044f849(RGE_Master_Moving_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\r') {
    RGE_Master_Moving_Object::modify_percent(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)(param_2 * (float)param_1[1]._padding_);
  return;
}

// --------------------------------------------------

// Function: FUN_0044f879
// Address: 0044f879
// XREFS: None
void __thiscall FUN_0044f879(RGE_Master_Moving_Object *param_1,int param_2)
{
  int iVar1;
  undefined2 extraout_var;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = 0xffffffff;
  uStack_4 = 0xffffffff;
  RGE_Master_Moving_Object::save(param_1,param_2);
  iVar1 = param_1[1]._padding_;
  if (iVar1 != 0) {
    uStack_8 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0xc));
  }
  if (param_1[1]._padding_ != 0) {
    uStack_4 = CONCAT22(extraout_var,*(undefined2 *)(param_1[1]._padding_ + 0xc));
  }
  rge_write(param_2,&param_1[1]._padding_,2);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,2);
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_write(param_2,&param_1[1]._padding_,1);
  rge_write(param_2,&uStack_8,2);
  rge_write(param_2,&uStack_4,2);
  rge_write(param_2,&param_1[1]._padding_,1);
  RGE_Task_List::save((RGE_Task_List *)param_1[1]._padding_,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0044f972
// Address: 0044f972
// XREFS: None
void __fastcall FUN_0044f972(int param_1)
{
  if (*(RGE_Sound **)(param_1 + 0xf0) != (RGE_Sound *)0x0) {
    RGE_Sound::play(*(RGE_Sound **)(param_1 + 0xf0),1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044f992
// Address: 0044f992
// XREFS: None
void __fastcall FUN_0044f992(int param_1)
{
  if (*(RGE_Sound **)(param_1 + 0xf4) != (RGE_Sound *)0x0) {
    RGE_Sound::play(*(RGE_Sound **)(param_1 + 0xf4),1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044f9b2
// Address: 0044f9b2
// XREFS: None
RGE_Master_Animated_Object * __thiscall
FUN_0044f9b2(RGE_Master_Animated_Object *param_1,RGE_Master_Animated_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d718;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)param_1,(RGE_Master_Static_Object *)param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Animated_Object::_vftable_;
  if (param_3 != 0) {
    RGE_Master_Animated_Object::setup(param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044fa1d
// Address: 0044fa1d
// XREFS: None
RGE_Master_Animated_Object * __thiscall
FUN_0044fa1d(RGE_Master_Animated_Object *param_1,byte param_2)
{
  RGE_Master_Animated_Object::~RGE_Master_Animated_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044fa3e
// Address: 0044fa3e
// XREFS: None
RGE_Master_Animated_Object * __thiscall
FUN_0044fa3e(RGE_Master_Animated_Object *param_1,int param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d738;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Animated_Object::_vftable_;
  if (param_5 != 0) {
    RGE_Master_Animated_Object::setup(param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044faad
// Address: 0044faad
// XREFS: None
RGE_Master_Animated_Object * __thiscall
FUN_0044faad(RGE_Master_Animated_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d758;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Static_Object::RGE_Master_Static_Object
            ((RGE_Master_Static_Object *)param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Animated_Object::_vftable_;
  if (param_6 != 0) {
    RGE_Master_Animated_Object::setup(param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044fb27
// Address: 0044fb27
// XREFS: None
undefined4 __thiscall
FUN_0044fb27(RGE_Master_Static_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Master_Static_Object::setup(param_1,param_2);
  param_1->master_type = '\x14';
  param_1[1]._padding_ = param_2[1]._padding_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044fb58
// Address: 0044fb58
// XREFS: None
undefined4 __thiscall
FUN_0044fb58(RGE_Master_Static_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4)
{
  RGE_Master_Static_Object::setup(param_1,param_2,param_3,param_4);
  param_1->master_type = '\x14';
  rge_read(param_2,param_1 + 1,4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044fb9a
// Address: 0044fb9a
// XREFS: None
// [HELPER] s__f: "%f"
undefined4 __thiscall
FUN_0044fb9a(RGE_Master_Static_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5)
{
  RGE_Master_Static_Object::setup(param_1,param_2,param_3,param_4,param_5);
  param_1->master_type = '\x14';
  fscanf(param_2,s__f,param_1 + 1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0044fbe2
// Address: 0044fbe2
// XREFS: None
void __fastcall FUN_0044fbe2(RGE_Master_Static_Object *param_1)
{
  param_1->_padding_ = (int)&RGE_Master_Animated_Object::_vftable_;
  RGE_Master_Static_Object::~RGE_Master_Static_Object(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0044fbfb
// Address: 0044fbfb
// XREFS: None
RGE_Static_Object * __thiscall
FUN_0044fbfb(RGE_Master_Animated_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  RGE_Static_Object *pRVar1;
  RGE_Animated_Object *this;
  float *unaff_FS_OFFSET;
  float fStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  fStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d77b;
  *unaff_FS_OFFSET = (float)&fStack_c;
  if ((char)param_1->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_2->world,(uchar)param_1->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = param_4;
      return pRVar1;
    }
  }
  this = (RGE_Animated_Object *)operator_new(0x8c);
  uStack_4 = 0;
  if (this != (RGE_Animated_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Animated_Object::RGE_Animated_Object
                       (this,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = fStack_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = fStack_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: FUN_0044fcc9
// Address: 0044fcc9
// XREFS: None
undefined4 __fastcall FUN_0044fcc9(RGE_Master_Animated_Object *param_1)
{
  RGE_Master_Animated_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d79b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Master_Animated_Object *)operator_new(0xbc);
  uStack_4 = 0;
  if (this != (RGE_Master_Animated_Object *)0x0) {
    uVar1 = RGE_Master_Animated_Object::RGE_Master_Animated_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044fd32
// Address: 0044fd32
// XREFS: None
void __thiscall FUN_0044fd32(RGE_Master_Static_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Master_Static_Object::copy_obj(param_1,param_2);
  param_1[1]._padding_ = param_2[1]._padding_;
  return;
}

// --------------------------------------------------

// Function: FUN_0044fd5f
// Address: 0044fd5f
// XREFS: None
void __thiscall FUN_0044fd5f(RGE_Master_Static_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\x05') {
    RGE_Master_Static_Object::modify(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044fd83
// Address: 0044fd83
// XREFS: None
void __thiscall FUN_0044fd83(RGE_Master_Static_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\x05') {
    RGE_Master_Static_Object::modify_delta(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)(param_2 + (float)param_1[1]._padding_);
  return;
}

// --------------------------------------------------

// Function: FUN_0044fdb9
// Address: 0044fdb9
// XREFS: None
void __thiscall FUN_0044fdb9(RGE_Master_Static_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\x05') {
    RGE_Master_Static_Object::modify_percent(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)(param_2 * (float)param_1[1]._padding_);
  return;
}

// --------------------------------------------------

// Function: FUN_0044fde9
// Address: 0044fde9
// XREFS: None
void __thiscall FUN_0044fde9(RGE_Master_Static_Object *param_1,int param_2)
{
  RGE_Master_Static_Object::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  return;
}

// --------------------------------------------------

// Function: FUN_0044fe15
// Address: 0044fe15
// XREFS: None
void FUN_0044fe15(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0044fe21
// Address: 0044fe21
// XREFS: None
void FUN_0044fe21(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0044fe31
// Address: 0044fe31
// XREFS: None
RGE_Master_Combat_Object * __thiscall
FUN_0044fe31(RGE_Master_Combat_Object *param_1,RGE_Master_Combat_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d7b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Action_Object::RGE_Master_Action_Object
            ((RGE_Master_Action_Object *)param_1,(RGE_Master_Action_Object *)param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Combat_Object::_vftable_;
  if (param_3 != 0) {
    RGE_Master_Combat_Object::setup(param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044fe9d
// Address: 0044fe9d
// XREFS: None
RGE_Master_Combat_Object * __thiscall FUN_0044fe9d(RGE_Master_Combat_Object *param_1,byte param_2)
{
  RGE_Master_Combat_Object::~RGE_Master_Combat_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044febe
// Address: 0044febe
// XREFS: None
RGE_Master_Combat_Object * __thiscall
FUN_0044febe(RGE_Master_Combat_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4,
            int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d7d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Action_Object::RGE_Master_Action_Object
            ((RGE_Master_Action_Object *)param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Combat_Object::_vftable_;
  if (param_5 != 0) {
    RGE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044ff2d
// Address: 0044ff2d
// XREFS: None
RGE_Master_Combat_Object * __thiscall
FUN_0044ff2d(RGE_Master_Combat_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d7f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Action_Object::RGE_Master_Action_Object
            ((RGE_Master_Action_Object *)param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Combat_Object::_vftable_;
  if (param_6 != 0) {
    RGE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044ffa7
// Address: 0044ffa7
// XREFS: None
undefined4 __thiscall
FUN_0044ffa7(RGE_Master_Action_Object *param_1,RGE_Master_Action_Object *param_2)
{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  RGE_Master_Action_Object::setup(param_1,param_2);
  *(undefined1 *)&param_1->_padding_ = 0x32;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  sVar1 = (short)param_2[1]._padding_;
  *(short *)&param_1[1]._padding_ = sVar1;
  if (sVar1 < 1) {
    param_1[1]._padding_ = 0;
  }
  else {
    puVar2 = (undefined4 *)calloc((int)sVar1,4);
    param_1[1]._padding_ = (int)puVar2;
    puVar5 = (undefined4 *)param_2[1]._padding_;
    for (uVar3 = (int)(short)param_1[1]._padding_ & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar2 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  sVar1 = *(short *)((int)&param_2[1]._padding_ + 2);
  *(short *)((int)&param_1[1]._padding_ + 2) = sVar1;
  if (sVar1 < 1) {
    param_1[1]._padding_ = 0;
  }
  else {
    puVar2 = (undefined4 *)calloc((int)sVar1,4);
    sVar1 = *(short *)((int)&param_1[1]._padding_ + 2);
    param_1[1]._padding_ = (int)puVar2;
    puVar5 = (undefined4 *)param_2[1]._padding_;
    for (uVar3 = (int)sVar1 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar2 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  param_1[1]._padding_ = param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(short *)&param_1[1]._padding_ = (short)param_2[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  param_1[1]._padding_ = param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00450166
// Address: 00450166
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00450166(RGE_Master_Action_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4)
{
  int *piVar1;
  short sVar2;
  void *pvVar3;
  RGE_Sprite *pRVar4;
  short *psVar5;
  int iVar6;
  
  RGE_Master_Action_Object::setup(param_1,param_2,param_3,param_4);
  *(undefined1 *)&param_1->_padding_ = 0x32;
  rge_read(param_2,&param_1[1]._padding_,1);
  piVar1 = &param_1[1]._padding_;
  rge_read(param_2,piVar1,2);
  if ((short)*piVar1 < 1) {
    param_1[1]._padding_ = 0;
  }
  else {
    pvVar3 = (void *)calloc((int)(short)*piVar1,4);
    param_1[1]._padding_ = (int)pvVar3;
    rge_read(param_2,pvVar3,(int)(short)*piVar1 << 2);
  }
  psVar5 = (short *)((int)&param_1[1]._padding_ + 2);
  rge_read(param_2,psVar5,2);
  if (*psVar5 < 1) {
    param_1[1]._padding_ = 0;
  }
  else {
    pvVar3 = (void *)calloc((int)*psVar5,4);
    sVar2 = *psVar5;
    param_1[1]._padding_ = (int)pvVar3;
    rge_read(param_2,pvVar3,(int)sVar2 << 2);
  }
  rge_read(param_2,&param_1[1]._padding_,2);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,2);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_read(param_2,&param_1[1]._padding_,1);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,1);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_4,2);
  if ((short)param_4 < 0) {
    pRVar4 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar4 = param_3[(short)param_4];
  }
  param_1[1]._padding_ = (int)pRVar4;
  if (_DAT_00570500 <= save_game_version) {
    rge_read(param_2,&param_1[1]._padding_,2);
    rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
    rge_read(param_2,&param_1[1]._padding_,4);
    rge_read(param_2,&param_1[1]._padding_,4);
    return 1;
  }
  *(ushort *)&param_1[1]._padding_ = (ushort)(byte)param_1[1]._padding_;
  iVar6 = (int)*psVar5;
  if (0 < iVar6) {
    psVar5 = (short *)(param_1[1]._padding_ + 2);
    do {
      if ((short)param_1[1]._padding_ < *psVar5) {
        *(short *)&param_1[1]._padding_ = *psVar5;
      }
      psVar5 = psVar5 + 2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar6 = (int)(short)param_1[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0;
  if (0 < iVar6) {
    psVar5 = (short *)(param_1[1]._padding_ + 2);
    do {
      if (*(short *)((int)&param_1[1]._padding_ + 2) < *psVar5) {
        *(short *)((int)&param_1[1]._padding_ + 2) = *psVar5;
      }
      psVar5 = psVar5 + 2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  param_1[1]._padding_ = param_1[1]._padding_;
  param_1[1]._padding_ = param_1[1]._padding_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045044a
// Address: 0045044a
// XREFS: None
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s__hd__hd__hd__hd__hd__f__f__f__hd: "%hd %hd %hd %hd %hd %f %f %f %hd %hd %hd %hd %f %f %f %hd %f"
undefined4 __thiscall
FUN_0045044a(RGE_Master_Action_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,undefined4 param_5)
{
  _iobuf *p_Var1;
  int iVar2;
  RGE_Sprite *pRVar3;
  short *psVar4;
  short sVar5;
  short sVar6;
  undefined4 uStack_4;
  
  p_Var1 = param_2;
  uStack_4 = param_1;
  RGE_Master_Action_Object::setup(param_1,param_2,param_3,param_4,(short)param_5);
  psVar4 = (short *)((int)&param_1[1]._padding_ + 2);
  *(undefined1 *)&param_1->_padding_ = 0x32;
  fscanf(p_Var1,s__hd__hd__hd__hd__hd__f__f__f__hd,&param_5,&param_2,psVar4,&param_1[1]._padding_,
         &param_1[1]._padding_,&param_1[1]._padding_,&param_1[1]._padding_,&param_1[1]._padding_,
         &param_1[1]._padding_,(undefined1 *)((int)&param_1[1]._padding_ + 2),&uStack_4,
         (int)&uStack_4 + 2,&param_1[1]._padding_,&param_1[1]._padding_,&param_1[1]._padding_,
         &param_4,&param_1[1]._padding_);
  sVar5 = 0;
  if (*psVar4 < 1) {
    param_1[1]._padding_ = 0;
  }
  else {
    iVar2 = calloc((int)*psVar4,4);
    sVar6 = *psVar4;
    param_1[1]._padding_ = iVar2;
    if (0 < sVar6) {
      do {
        iVar2 = param_1[1]._padding_ + sVar5 * 4;
        fscanf(p_Var1,s__hd__hd,iVar2,iVar2 + 2);
        sVar5 = sVar5 + 1;
      } while (sVar5 < *psVar4);
    }
  }
  sVar5 = (short)param_1[1]._padding_;
  sVar6 = 0;
  if (sVar5 < 1) {
    param_1[1]._padding_ = 0;
  }
  else {
    iVar2 = calloc((int)sVar5,4);
    param_1[1]._padding_ = iVar2;
    if (0 < (short)param_1[1]._padding_) {
      do {
        iVar2 = param_1[1]._padding_ + sVar6 * 4;
        fscanf(p_Var1,s__hd__hd,iVar2,iVar2 + 2);
        sVar6 = sVar6 + 1;
      } while (sVar6 < (short)param_1[1]._padding_);
    }
  }
  if ((short)param_5 < 0) {
    pRVar3 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar3 = param_3[(short)param_5];
  }
  param_1[1]._padding_ = (int)pRVar3;
  *(undefined1 *)&param_1[1]._padding_ = (undefined1)uStack_4;
  *(undefined1 *)&param_1[1]._padding_ = param_4._0_1_;
  iVar2 = (int)*psVar4;
  *(byte *)&param_1[1]._padding_ = (byte)param_2;
  *(ushort *)((int)&param_1[1]._padding_ + 2) = (ushort)uStack_4._2_1_;
  *(ushort *)&param_1[1]._padding_ = (ushort)(byte)param_2;
  if (0 < iVar2) {
    psVar4 = (short *)(param_1[1]._padding_ + 2);
    do {
      if ((short)param_1[1]._padding_ < *psVar4) {
        *(short *)&param_1[1]._padding_ = *psVar4;
      }
      psVar4 = psVar4 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = (int)(short)param_1[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = 0;
  if (0 < iVar2) {
    psVar4 = (short *)(param_1[1]._padding_ + 2);
    do {
      if (*(short *)((int)&param_1[1]._padding_ + 2) < *psVar4) {
        *(short *)((int)&param_1[1]._padding_ + 2) = *psVar4;
      }
      psVar4 = psVar4 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  param_1[1]._padding_ = param_1[1]._padding_;
  param_1[1]._padding_ = param_1[1]._padding_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045067d
// Address: 0045067d
// XREFS: None
void __fastcall FUN_0045067d(RGE_Master_Action_Object *param_1)
{
  int iVar1;
  
  iVar1 = param_1[1]._padding_;
  param_1->_padding_ = (int)&RGE_Master_Combat_Object::_vftable_;
  if (iVar1 != 0) {
    free(iVar1);
    param_1[1]._padding_ = 0;
  }
  if (param_1[1]._padding_ != 0) {
    free(param_1[1]._padding_);
    param_1[1]._padding_ = 0;
  }
  RGE_Master_Action_Object::~RGE_Master_Action_Object(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004506cc
// Address: 004506cc
// XREFS: None
RGE_Static_Object * __thiscall
FUN_004506cc(RGE_Master_Combat_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  RGE_Static_Object *pRVar1;
  RGE_Combat_Object *this;
  float *unaff_FS_OFFSET;
  float fStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  fStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d81b;
  *unaff_FS_OFFSET = (float)&fStack_c;
  if ((char)param_1->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_2->world,(uchar)param_1->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = param_4;
      return pRVar1;
    }
  }
  this = (RGE_Combat_Object *)operator_new(0x1c4);
  uStack_4 = 0;
  if (this != (RGE_Combat_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Combat_Object::RGE_Combat_Object(this,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = fStack_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = fStack_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: FUN_00450799
// Address: 00450799
// XREFS: None
undefined4 __fastcall FUN_00450799(RGE_Master_Combat_Object *param_1)
{
  RGE_Master_Combat_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d83b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Master_Combat_Object *)operator_new(0x148);
  uStack_4 = 0;
  if (this != (RGE_Master_Combat_Object *)0x0) {
    uVar1 = RGE_Master_Combat_Object::RGE_Master_Combat_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00450802
// Address: 00450802
// XREFS: None
void __thiscall FUN_00450802(RGE_Master_Action_Object *param_1,RGE_Master_Static_Object *param_2)
{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  RGE_Master_Action_Object::copy_obj(param_1,param_2);
  param_1[1]._padding_ = (int)param_2[1].death_sound;
  *(char *)&param_1[1]._padding_ = (char)param_2[1].death_spawn_obj_id;
  *(short *)&param_1[1]._padding_ = param_2[1].portrait_pict;
  if (param_1[1]._padding_ != 0) {
    free(param_1[1]._padding_);
  }
  sVar1 = (short)param_1[1]._padding_;
  if (sVar1 < 1) {
    param_1[1]._padding_ = 0;
  }
  else {
    puVar2 = (undefined4 *)calloc((int)sVar1,4);
    param_1[1]._padding_ = (int)puVar2;
    puVar5 = *(undefined4 **)&param_2[1].tile_req1;
    for (uVar3 = (int)(short)param_1[1]._padding_ & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar2 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)&param_2[1].sort_number;
  if (param_1[1]._padding_ != 0) {
    free(param_1[1]._padding_);
  }
  sVar1 = *(short *)((int)&param_1[1]._padding_ + 2);
  if (sVar1 < 1) {
    param_1[1]._padding_ = 0;
  }
  else {
    puVar2 = (undefined4 *)calloc((int)sVar1,4);
    sVar1 = *(short *)((int)&param_1[1]._padding_ + 2);
    param_1[1]._padding_ = (int)puVar2;
    puVar5 = *(undefined4 **)&param_2[1].button_pict;
    for (uVar3 = (int)sVar1 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar2 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  *(short *)&param_1[1]._padding_ = param_2[1].center_tile_req1;
  param_1[1]._padding_ = (int)param_2[1].construction_radius_x;
  param_1[1]._padding_ = (int)param_2[1].construction_radius_y;
  param_1[1]._padding_ = *(int *)&param_2[1].movement_type;
  *(short *)&param_1[1]._padding_ = param_2[1].attribute_type_held[1];
  *(short *)((int)&param_1[1]._padding_ + 2) = param_2[1].attribute_type_held[2];
  *(undefined1 *)&param_1[1]._padding_ = *(undefined1 *)param_2[1].attribute_amount_held;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) =
       *(undefined2 *)((int)param_2[1].attribute_amount_held + 2);
  param_1[1]._padding_ = (int)param_2[1].attribute_amount_held[1];
  param_1[1]._padding_ = (int)param_2[1].attribute_amount_held[2];
  param_1[1]._padding_ = *(int *)&param_2[1].attribute_max_amount;
  *(uchar *)&param_1[1]._padding_ = param_2[1].elevation_flag;
  param_1[1]._padding_ = (int)param_2[1].attribute_rot;
  *(undefined2 *)&param_1[1]._padding_ = *(undefined2 *)&param_2[1].multiple_attribute_mod;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) =
       *(undefined2 *)((int)&param_2[1].multiple_attribute_mod + 2);
  param_1[1]._padding_ = *(int *)param_2[1].attribute_flag;
  param_1[1]._padding_ = *(int *)&param_2[1].combat_level;
  return;
}

// --------------------------------------------------

// Function: FUN_004509f1
// Address: 004509f1
// XREFS: None
void __thiscall FUN_004509f1(RGE_Master_Action_Object *param_1,float param_2,uchar param_3)
{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar7;
  uint uVar6;
  
  switch(param_3) {
  case '\b':
    uVar6 = __ftol();
    uVar4 = (ushort)uVar6;
    iVar7 = param_1[1]._padding_;
    if (iVar7 == 0) {
      return;
    }
    sVar1 = *(short *)((int)&param_1[1]._padding_ + 2);
    break;
  case '\t':
    uVar6 = __ftol();
    uVar4 = (ushort)uVar6;
    iVar7 = param_1[1]._padding_;
    if (iVar7 == 0) {
      return;
    }
    sVar1 = (short)param_1[1]._padding_;
    break;
  case '\n':
    param_1[1]._padding_ = (int)param_2;
    return;
  case '\v':
    uVar5 = __ftol();
    *(undefined2 *)((int)&param_1[1]._padding_ + 2) = uVar5;
    return;
  case '\f':
    param_1[1]._padding_ = (int)param_2;
    return;
  default:
    RGE_Master_Action_Object::modify(param_1,param_2,param_3);
    return;
  case '\x0f':
    uVar2 = __ftol();
    *(undefined1 *)&param_1[1]._padding_ = uVar2;
    return;
  case '\x10':
    bVar3 = __ftol();
    *(ushort *)&param_1[1]._padding_ = (ushort)bVar3;
    return;
  case '\x12':
    uVar5 = __ftol();
    *(undefined2 *)&param_1[1]._padding_ = uVar5;
    return;
  }
  uVar6 = uVar6 >> 8 & 0xff;
  if ((int)sVar1 <= (int)uVar6) {
    return;
  }
  *(ushort *)(iVar7 + 2 + uVar6 * 4) = uVar4 & 0xff;
  return;
}

// --------------------------------------------------

// Function: FUN_00450b09
// Address: 00450b09
// XREFS: None
void __fastcall FUN_00450b09(uint param_1,uint *param_2,float param_3,uchar param_4)
{
  char *pcVar1;
  short *psVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  char cVar5;
  ushort uVar6;
  short sVar7;
  undefined4 in_EAX;
  undefined3 uVar9;
  uint uVar10;
  uint uVar11;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_EDI;
  int iVar12;
  uint uVar8;
  
  *param_2 = *param_2 & param_1;
  *(char *)(unaff_EBX + 10) = *(char *)(unaff_EBX + 10) + (char)param_1;
  *(char *)(param_1 + 0x9700450a) = *(char *)(param_1 + 0x9700450a) + (char)param_1;
  uVar9 = (undefined3)((uint)in_EAX >> 8);
  puVar3 = unaff_EDI + 1;
  *unaff_EDI = CONCAT31(uVar9,(byte)in_EAX | *(byte *)(unaff_EBP + 2));
  uVar4 = in(10);
  pcVar1 = (char *)(CONCAT31(uVar9,uVar4) + -0x6f6f6f70);
  *pcVar1 = *pcVar1 + (char)param_2;
  switch(param_4) {
  case '\x06':
    fRamcc0045ce = param_3 + fRamcc0045ce;
    return;
  default:
    RGE_Master_Action_Object::modify_delta((RGE_Master_Action_Object *)0xcc00450a,param_3,param_4);
    break;
  case '\b':
    uVar8 = __ftol(puVar3);
    uVar6 = (ushort)uVar8;
    if (iRamcc00460e != 0) {
      uVar11 = 0;
      if (0 < sRamcc00460c) {
        uVar10 = 0;
        while (iVar12 = iRamcc00460e,
              (int)*(short *)(iRamcc00460e + uVar10 * 4) != (uVar8 >> 8 & 0xff)) {
          uVar11 = uVar11 + 1;
          uVar10 = uVar11 & 0xffff;
          if ((int)sRamcc00460c <= (int)uVar10) {
            return;
          }
        }
LAB_00450c01:
        psVar2 = (short *)(iVar12 + 2 + (uVar11 & 0xffff) * 4);
        *psVar2 = *psVar2 + (uVar6 & 0xff);
        return;
      }
    }
    break;
  case '\t':
    uVar8 = __ftol(puVar3);
    uVar6 = (ushort)uVar8;
    if (iRamcc004616 != 0) {
      uVar11 = 0;
      if (0 < sRamcc004612) {
        uVar10 = 0;
        while (iVar12 = iRamcc004616,
              (int)*(short *)(iRamcc004616 + uVar10 * 4) != (uVar8 >> 8 & 0xff)) {
          uVar11 = uVar11 + 1;
          uVar10 = uVar11 & 0xffff;
          if ((int)sRamcc004612 <= (int)uVar10) {
            return;
          }
        }
        goto LAB_00450c01;
      }
    }
    break;
  case '\n':
    fRamcc00462a = param_3 + fRamcc00462a;
    return;
  case '\v':
    sVar7 = __ftol(puVar3);
    sRamcc004630 = sRamcc004630 + sVar7;
    return;
  case '\f':
    fRamcc00461e = param_3 + fRamcc00461e;
    return;
  case '\x0f':
    cVar5 = __ftol(puVar3);
    cRamcc00460a = cRamcc00460a + cVar5;
    return;
  case '\x10':
    sVar7 = __ftol(puVar3);
    sRamcc00462e = sRamcc00462e + sVar7;
    return;
  case '\x12':
    uRamcc00461a = __ftol(puVar3);
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00450cc7
// Address: 00450cc7
// XREFS: None
void __fastcall FUN_00450cc7(int param_1,int param_2,float param_3,uchar param_4)
{
  char *pcVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint in_EAX;
  RGE_Master_Action_Object *this;
  char cVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  byte in_CF;
  
  this = (RGE_Master_Action_Object *)((param_1 - *(int *)(in_EAX * 2 + 0x450cb400)) - (uint)in_CF);
  *(char *)(unaff_EBX + 0xb) = *(char *)(unaff_EBX + 0xb) + (char)(in_EAX >> 8);
  cVar4 = (char)((uint)param_2 >> 8);
  *(char *)(param_2 + 0x3100450b) = *(char *)(param_2 + 0x3100450b) + cVar4;
  *(char *)(unaff_EDI + 0xc) = *(char *)(unaff_EDI + 0xc) + (char)(in_EAX | 0x45);
  *(char *)(unaff_EBP + 0xe) = *(char *)(unaff_EBP + 0xe) + (char)unaff_EBX;
  (&stack0x0cb40045)[(int)this] = (&stack0x0cb40045)[(int)this] + cVar4;
  *(char *)(unaff_EBX + 0xc) = *(char *)(unaff_EBX + 0xc) + cVar4;
  pcVar1 = (char *)((in_EAX | 0x45) + 0xb400450c);
  *pcVar1 = *pcVar1 + (char)this;
  *(char *)(unaff_ESI + -0x6fffbaf4) = *(char *)(unaff_ESI + -0x6fffbaf4) + (char)unaff_EBX;
  switch(param_4) {
  case '\x06':
    this->_padding_ = (int)(param_3 * (float)this->_padding_);
    return;
  default:
    RGE_Master_Action_Object::modify_percent(this,param_3,param_4);
switchD_00450d1a_caseD_8:
    return;
  case '\b':
  case '\t':
    goto switchD_00450d1a_caseD_8;
  case '\n':
    this[1]._padding_ = (int)(param_3 * (float)this[1]._padding_);
    return;
  case '\v':
    uVar3 = __ftol();
    *(undefined2 *)((int)&this[1]._padding_ + 2) = uVar3;
    return;
  case '\f':
    this[1]._padding_ = (int)(param_3 * (float)this[1]._padding_);
    return;
  case '\x0f':
    uVar2 = __ftol();
    *(undefined1 *)&this[1]._padding_ = uVar2;
    return;
  case '\x10':
    uVar3 = __ftol();
    *(undefined2 *)&this[1]._padding_ = uVar3;
    return;
  case '\x12':
    uVar3 = __ftol();
    *(undefined2 *)&this[1]._padding_ = uVar3;
    return;
  }
}

// --------------------------------------------------

// Function: FUN_00450dea
// Address: 00450dea
// XREFS: None
void __fastcall
FUN_00450dea(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  char *pcVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  uint in_EAX;
  RGE_Master_Action_Object *this;
  char unaff_BL;
  
  iVar4 = param_5;
  uRam0dd90045 = uRam0dd90045 & param_1;
  cRam4900450d = cRam4900450d + (char)((uint)param_2 >> 8) + (char)(in_EAX >> 8);
  pcVar1 = (char *)((in_EAX | 0xdff0045) + 0xa200450d);
  *pcVar1 = *pcVar1 + (char)(in_EAX | 0xdff0045);
  this = (RGE_Master_Action_Object *)
         CONCAT22((short)(param_1 >> 0x10),
                  CONCAT11((char)(param_1 >> 8) + ((byte)in_EAX | 0x45),(char)param_1 + unaff_BL));
  RGE_Master_Action_Object::save(this,param_5);
  iVar3 = this[1]._padding_;
  if (iVar3 == 0) {
    param_5 = 0xffffffff;
  }
  else {
    param_5 = CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(iVar3 + 0x72));
  }
  rge_write(iVar4,&this[1]._padding_,1);
  rge_write(iVar4,&this[1]._padding_,2);
  if ((void *)this[1]._padding_ != (void *)0x0) {
    rge_write(iVar4,(void *)this[1]._padding_,(int)(short)this[1]._padding_ << 2);
  }
  psVar2 = (short *)((int)&this[1]._padding_ + 2);
  rge_write(iVar4,psVar2,2);
  if ((void *)this[1]._padding_ != (void *)0x0) {
    rge_write(iVar4,(void *)this[1]._padding_,(int)*psVar2 << 2);
  }
  rge_write(iVar4,&this[1]._padding_,2);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,2);
  rge_write(iVar4,(void *)((int)&this[1]._padding_ + 2),2);
  rge_write(iVar4,&this[1]._padding_,1);
  rge_write(iVar4,(void *)((int)&this[1]._padding_ + 2),2);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,1);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&param_5,2);
  rge_write(iVar4,&this[1]._padding_,2);
  rge_write(iVar4,(void *)((int)&this[1]._padding_ + 2),2);
  rge_write(iVar4,&this[1]._padding_,4);
  rge_write(iVar4,&this[1]._padding_,4);
  return;
}

// --------------------------------------------------

// Function: FUN_00450fff
// Address: 00450fff
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00450fff(int param_1,int param_2)
{
  int iVar1;
  int iStack_8;
  
  iStack_8 = (int)*(short *)(param_2 + 0x108);
  if (0 < iStack_8) {
    do {
      iVar1 = (int)*(short *)(param_1 + 0x102);
      if (0 < *(short *)(param_1 + 0x102)) {
        do {
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
  }
  __ftol();
  return;
}

// --------------------------------------------------

// Function: FUN_004510bc
// Address: 004510bc
// XREFS: None
RGE_Master_Animated_Object * __thiscall
FUN_004510bc(RGE_Master_Animated_Object *param_1,RGE_Master_Animated_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d858;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(param_1,param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Doppleganger_Object::_vftable_;
  if (param_3 != 0) {
    RGE_Master_Doppleganger_Object::setup
              ((RGE_Master_Doppleganger_Object *)param_1,(RGE_Master_Doppleganger_Object *)param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045111d
// Address: 0045111d
// XREFS: None
RGE_Master_Doppleganger_Object * __thiscall
FUN_0045111d(RGE_Master_Doppleganger_Object *param_1,byte param_2)
{
  RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045113e
// Address: 0045113e
// XREFS: None
RGE_Master_Animated_Object * __thiscall
FUN_0045113e(RGE_Master_Animated_Object *param_1,int param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d878;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Doppleganger_Object::_vftable_;
  if (param_5 != 0) {
    RGE_Master_Doppleganger_Object::setup
              ((RGE_Master_Doppleganger_Object *)param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004511ad
// Address: 004511ad
// XREFS: None
RGE_Master_Animated_Object * __thiscall
FUN_004511ad(RGE_Master_Animated_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d898;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Doppleganger_Object::_vftable_;
  if (param_6 != 0) {
    RGE_Master_Doppleganger_Object::setup
              ((RGE_Master_Doppleganger_Object *)param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00451227
// Address: 00451227
// XREFS: None
undefined4 __thiscall
FUN_00451227(RGE_Master_Animated_Object *param_1,RGE_Master_Animated_Object *param_2)
{
  RGE_Master_Animated_Object::setup(param_1,param_2);
  *(undefined1 *)&param_1->_padding_ = 0x19;
  *(undefined1 *)((int)&param_1->_padding_ + 1) = 3;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045124e
// Address: 0045124e
// XREFS: None
undefined4 __thiscall
FUN_0045124e(RGE_Master_Animated_Object *param_1,int param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4)
{
  RGE_Master_Animated_Object::setup(param_1,param_2,param_3,param_4);
  *(undefined1 *)&param_1->_padding_ = 0x19;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00451276
// Address: 00451276
// XREFS: None
void __thiscall
FUN_00451276(RGE_Master_Animated_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5)
{
  RGE_Master_Animated_Object::setup(param_1,param_2,param_3,param_4,param_5);
  *(undefined1 *)&param_1->_padding_ = 0x19;
  *(undefined1 *)&param_1->_padding_ = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004512b1
// Address: 004512b1
// XREFS: None
void __fastcall FUN_004512b1(RGE_Master_Animated_Object *param_1)
{
  param_1->_padding_ = (int)&RGE_Master_Doppleganger_Object::_vftable_;
  RGE_Master_Animated_Object::~RGE_Master_Animated_Object(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_004512cb
// Address: 004512cb
// XREFS: None
RGE_Static_Object * __thiscall
FUN_004512cb(RGE_Master_Doppleganger_Object *param_1,RGE_Player *param_2,float param_3,float param_4
            ,float param_5,RGE_Static_Object *param_6)
{
  RGE_Static_Object *pRVar1;
  RGE_Doppleganger_Object *this;
  float *unaff_FS_OFFSET;
  float fStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  fStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d8bb;
  *unaff_FS_OFFSET = (float)&fStack_c;
  if (param_1->field_0xa4 != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_2->world,param_1->field_0x4);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 0x1ec))(param_1,param_2,param_3,param_4,param_5,param_6);
      *unaff_FS_OFFSET = param_4;
      return pRVar1;
    }
  }
  this = (RGE_Doppleganger_Object *)operator_new(0xb0);
  uStack_4 = 0;
  if (this != (RGE_Doppleganger_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Doppleganger_Object::RGE_Doppleganger_Object
                       (this,param_1,param_2,param_3,param_4,param_5,1,param_6);
    *unaff_FS_OFFSET = fStack_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = fStack_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: FUN_004513a6
// Address: 004513a6
// XREFS: None
undefined4 __fastcall FUN_004513a6(RGE_Master_Doppleganger_Object *param_1)
{
  RGE_Master_Doppleganger_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d8db;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Master_Doppleganger_Object *)operator_new(0xbc);
  uStack_4 = 0;
  if (this != (RGE_Master_Doppleganger_Object *)0x0) {
    uVar1 = RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00451412
// Address: 00451412
// XREFS: None
void __thiscall FUN_00451412(RGE_Master_Animated_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Master_Animated_Object::copy_obj(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0045142d
// Address: 0045142d
// XREFS: None
void __thiscall FUN_0045142d(RGE_Master_Animated_Object *param_1,int param_2)
{
  RGE_Master_Animated_Object::save(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0045143d
// Address: 0045143d
// XREFS: None
RGE_Master_Missile_Object * __thiscall
FUN_0045143d(RGE_Master_Missile_Object *param_1,RGE_Master_Missile_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d8f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)param_1,(RGE_Master_Combat_Object *)param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Missile_Object::_vftable_;
  if (param_3 != 0) {
    RGE_Master_Missile_Object::setup(param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045149d
// Address: 0045149d
// XREFS: None
RGE_Master_Missile_Object * __thiscall FUN_0045149d(RGE_Master_Missile_Object *param_1,byte param_2)
{
  RGE_Master_Missile_Object::~RGE_Master_Missile_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004514be
// Address: 004514be
// XREFS: None
RGE_Master_Missile_Object * __thiscall
FUN_004514be(RGE_Master_Missile_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4
            ,int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d918;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Missile_Object::_vftable_;
  if (param_5 != 0) {
    RGE_Master_Missile_Object::setup(param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045152d
// Address: 0045152d
// XREFS: None
RGE_Master_Missile_Object * __thiscall
FUN_0045152d(RGE_Master_Missile_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d938;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object
            ((RGE_Master_Combat_Object *)param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Missile_Object::_vftable_;
  if (param_6 != 0) {
    RGE_Master_Missile_Object::setup(param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004515a7
// Address: 004515a7
// XREFS: None
undefined4 __thiscall
FUN_004515a7(RGE_Master_Combat_Object *param_1,RGE_Master_Combat_Object *param_2)
{
  RGE_Master_Combat_Object::setup(param_1,param_2);
  *(undefined1 *)&param_1->_padding_ = 0x3c;
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  *(undefined1 *)((int)&param_1[1]._padding_ + 1) = *(undefined1 *)((int)&param_2[1]._padding_ + 1);
  *(undefined1 *)((int)&param_1[1]._padding_ + 2) = *(undefined1 *)((int)&param_2[1]._padding_ + 2);
  *(undefined1 *)((int)&param_1[1]._padding_ + 3) = *(undefined1 *)((int)&param_2[1]._padding_ + 3);
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00451614
// Address: 00451614
// XREFS: None
undefined4 __thiscall
FUN_00451614(RGE_Master_Combat_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4)
{
  RGE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4);
  *(undefined1 *)&param_1->_padding_ = 0x3c;
  rge_read(param_2,param_1 + 1,1);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 1),1);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),1);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 3),1);
  rge_read(param_2,&param_1[1]._padding_,1);
  rge_read(param_2,&param_1[1]._padding_,4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004516b4
// Address: 004516b4
// XREFS: None
// [HELPER] s__hd__hd__hd__hd__hd__f: "%hd %hd %hd %hd %hd %f"
undefined4 __thiscall
FUN_004516b4(RGE_Master_Combat_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,undefined4 param_5)
{
  _iobuf *p_Var1;
  undefined4 uStack_4;
  
  p_Var1 = param_2;
  uStack_4 = param_1;
  RGE_Master_Combat_Object::setup(param_1,param_2,param_3,param_4,(short)param_5);
  *(undefined1 *)&param_1->_padding_ = 1;
  *(undefined1 *)&param_1->_padding_ = 0x3c;
  fscanf(p_Var1,s__hd__hd__hd__hd__hd__f,(int)&uStack_4 + 2,&param_5,&param_4,&param_3,&param_2,
         &param_1[1]._padding_);
  *(undefined1 *)((int)&param_1[1]._padding_ + 1) = (undefined1)param_5;
  *(undefined1 *)((int)&param_1[1]._padding_ + 2) = param_4._0_1_;
  *(undefined1 *)((int)&param_1[1]._padding_ + 3) = param_3._0_1_;
  *(undefined1 *)&param_1[1]._padding_ = param_2._0_1_;
  *(undefined1 *)&param_1[1]._padding_ = uStack_4._2_1_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00451756
// Address: 00451756
// XREFS: None
void __fastcall FUN_00451756(RGE_Master_Combat_Object *param_1)
{
  param_1->_padding_ = (int)&RGE_Master_Missile_Object::_vftable_;
  RGE_Master_Combat_Object::~RGE_Master_Combat_Object(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0045176b
// Address: 0045176b
// XREFS: None
RGE_Static_Object * __thiscall
FUN_0045176b(RGE_Master_Combat_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  RGE_Static_Object *pRVar1;
  RGE_Missile_Object *this;
  float *unaff_FS_OFFSET;
  float fStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  fStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d95b;
  *unaff_FS_OFFSET = (float)&fStack_c;
  if ((char)param_1->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_2->world,(uchar)param_1->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = param_4;
      return pRVar1;
    }
  }
  this = (RGE_Missile_Object *)operator_new(0x1c8);
  uStack_4 = 0;
  if (this != (RGE_Missile_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Missile_Object::RGE_Missile_Object(this,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = fStack_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = fStack_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: FUN_00451839
// Address: 00451839
// XREFS: None
undefined4 __fastcall FUN_00451839(RGE_Master_Missile_Object *param_1)
{
  RGE_Master_Missile_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d97b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Master_Missile_Object *)operator_new(0x154);
  uStack_4 = 0;
  if (this != (RGE_Master_Missile_Object *)0x0) {
    uVar1 = RGE_Master_Missile_Object::RGE_Master_Missile_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_004518a2
// Address: 004518a2
// XREFS: None
void __thiscall FUN_004518a2(RGE_Master_Combat_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Master_Combat_Object::copy_obj(param_1,param_2);
  *(uchar *)&param_1[1]._padding_ = param_2[1].map_color;
  *(uchar *)((int)&param_1[1]._padding_ + 1) = param_2[1].attack_reaction;
  *(uchar *)((int)&param_1[1]._padding_ + 2) = param_2[1].convert_terrain_flag;
  *(uchar *)((int)&param_1[1]._padding_ + 3) = param_2[1].damage_sprite_num;
  *(undefined1 *)&param_1[1]._padding_ = *(undefined1 *)&param_2[1].damage_sprites;
  param_1[1]._padding_ = param_2[1].help_string_id;
  return;
}

// --------------------------------------------------

// Function: FUN_0045190b
// Address: 0045190b
// XREFS: None
void __thiscall FUN_0045190b(RGE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  undefined1 uVar1;
  
  if (param_3 == '\x13') {
    uVar1 = __ftol();
    *(undefined1 *)((int)&param_1[1]._padding_ + 1) = uVar1;
  }
  RGE_Master_Combat_Object::modify(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0045193e
// Address: 0045193e
// XREFS: None
void __thiscall FUN_0045193e(RGE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  undefined1 uVar1;
  
  if (param_3 == '\x13') {
    uVar1 = __ftol();
    *(undefined1 *)((int)&param_1[1]._padding_ + 1) = uVar1;
  }
  RGE_Master_Combat_Object::modify_delta(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0045196e
// Address: 0045196e
// XREFS: None
void __thiscall FUN_0045196e(RGE_Master_Combat_Object *param_1,float param_2,uchar param_3)
{
  undefined1 uVar1;
  
  if (param_3 == '\x13') {
    uVar1 = __ftol();
    *(undefined1 *)((int)&param_1[1]._padding_ + 1) = uVar1;
  }
  RGE_Master_Combat_Object::modify_percent(param_1,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0045199e
// Address: 0045199e
// XREFS: None
void __thiscall FUN_0045199e(RGE_Master_Combat_Object *param_1,int param_2)
{
  RGE_Master_Combat_Object::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,1);
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 1),1);
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 2),1);
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 3),1);
  rge_write(param_2,&param_1[1]._padding_,1);
  rge_write(param_2,&param_1[1]._padding_,4);
  return;
}

// --------------------------------------------------

// Function: FUN_00451a1f
// Address: 00451a1f
// XREFS: None
RGE_Master_Moving_Object * __thiscall
FUN_00451a1f(RGE_Master_Moving_Object *param_1,RGE_Master_Moving_Object *param_2,int param_3)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d998;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)param_1,(RGE_Master_Animated_Object *)param_2,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Moving_Object::_vftable_;
  if (param_3 != 0) {
    RGE_Master_Moving_Object::setup(param_1,param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00451a7d
// Address: 00451a7d
// XREFS: None
RGE_Master_Moving_Object * __thiscall FUN_00451a7d(RGE_Master_Moving_Object *param_1,byte param_2)
{
  RGE_Master_Moving_Object::~RGE_Master_Moving_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00451a9e
// Address: 00451a9e
// XREFS: None
RGE_Master_Moving_Object * __thiscall
FUN_00451a9e(RGE_Master_Moving_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4,
            int param_5)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d9b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)param_1,param_2,param_3,param_4,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Moving_Object::_vftable_;
  if (param_5 != 0) {
    RGE_Master_Moving_Object::setup(param_1,param_2,param_3,param_4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00451b0d
// Address: 00451b0d
// XREFS: None
RGE_Master_Moving_Object * __thiscall
FUN_00451b0d(RGE_Master_Moving_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d9d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object
            ((RGE_Master_Animated_Object *)param_1,param_2,param_3,param_4,param_5,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Master_Moving_Object::_vftable_;
  if (param_6 != 0) {
    RGE_Master_Moving_Object::setup(param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00451b87
// Address: 00451b87
// XREFS: None
undefined4 __thiscall
FUN_00451b87(RGE_Master_Animated_Object *param_1,RGE_Master_Animated_Object *param_2)
{
  RGE_Master_Animated_Object::setup(param_1,param_2);
  *(undefined1 *)&param_1->_padding_ = 0x1e;
  param_1[1]._padding_ = param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  *(undefined2 *)((int)&param_1[1]._padding_ + 2) = *(undefined2 *)((int)&param_2[1]._padding_ + 2);
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  param_1[1]._padding_ = param_2[1]._padding_;
  *(char *)&param_1[1]._padding_ = (char)param_2[1]._padding_;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00451c0e
// Address: 00451c0e
// XREFS: None
undefined4 __thiscall
FUN_00451c0e(RGE_Master_Animated_Object *param_1,int param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4)
{
  RGE_Sprite **ppRVar1;
  RGE_Sprite *pRVar2;
  
  ppRVar1 = param_3;
  RGE_Master_Animated_Object::setup(param_1,param_2,param_3,param_4);
  *(undefined1 *)&param_1->_padding_ = 0x1e;
  rge_read(param_2,&param_4,2);
  rge_read(param_2,&param_3,2);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,1);
  rge_read(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_read(param_2,&param_1[1]._padding_,1);
  rge_read(param_2,&param_1[1]._padding_,4);
  rge_read(param_2,&param_1[1]._padding_,1);
  if ((short)param_4 < 0) {
    pRVar2 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar2 = ppRVar1[(short)param_4];
  }
  param_1[1]._padding_ = (int)pRVar2;
  if (-1 < (short)param_3) {
    param_1[1]._padding_ = (int)ppRVar1[(short)param_3];
    return 1;
  }
  param_1[1]._padding_ = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00451d07
// Address: 00451d07
// XREFS: None
// [HELPER] s__hd__hd__f__hd__hd__hd__f__hd: "%hd %hd %f %hd %hd %hd %f %hd"
undefined4 __thiscall
FUN_00451d07(RGE_Master_Animated_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,undefined4 param_5)
{
  _iobuf *p_Var1;
  RGE_Sprite **ppRVar2;
  RGE_Sprite *pRVar3;
  undefined4 uStack_4;
  
  ppRVar2 = param_3;
  p_Var1 = param_2;
  uStack_4 = param_1;
  RGE_Master_Animated_Object::setup(param_1,param_2,param_3,param_4,(short)param_5);
  *(undefined1 *)&param_1->_padding_ = 0x1e;
  fscanf(p_Var1,s__hd__hd__f__hd__hd__hd__f__hd,&param_2,(int)&uStack_4 + 2,&param_1[1]._padding_,
         &param_5,(undefined1 *)((int)&param_1[1]._padding_ + 2),&param_3,&param_1[1]._padding_,
         &param_4);
  *(undefined1 *)&param_1[1]._padding_ = param_3._0_1_;
  *(undefined1 *)&param_1[1]._padding_ = (undefined1)param_5;
  *(undefined1 *)&param_1[1]._padding_ = param_4._0_1_;
  if ((short)param_2 < 0) {
    pRVar3 = (RGE_Sprite *)0x0;
  }
  else {
    pRVar3 = ppRVar2[(short)param_2];
  }
  param_1[1]._padding_ = (int)pRVar3;
  if (-1 < (int)uStack_4) {
    param_1[1]._padding_ = (int)ppRVar2[uStack_4._2_2_];
    return 1;
  }
  param_1[1]._padding_ = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00451ddf
// Address: 00451ddf
// XREFS: None
void __fastcall FUN_00451ddf(RGE_Master_Animated_Object *param_1)
{
  param_1->_padding_ = (int)&RGE_Master_Moving_Object::_vftable_;
  RGE_Master_Animated_Object::~RGE_Master_Animated_Object(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00451deb
// Address: 00451deb
// XREFS: None
RGE_Static_Object * __thiscall
FUN_00451deb(RGE_Master_Moving_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  RGE_Static_Object *pRVar1;
  RGE_Moving_Object *this;
  float *unaff_FS_OFFSET;
  float fStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  fStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d9fb;
  *unaff_FS_OFFSET = (float)&fStack_c;
  if ((char)param_1->_padding_ != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_2->world,(uchar)param_1->_padding_);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = param_4;
      return pRVar1;
    }
  }
  this = (RGE_Moving_Object *)operator_new(0x180);
  uStack_4 = 0;
  if (this != (RGE_Moving_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Moving_Object::RGE_Moving_Object(this,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = fStack_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = fStack_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: FUN_00451eb9
// Address: 00451eb9
// XREFS: None
undefined4 __fastcall FUN_00451eb9(RGE_Master_Moving_Object *param_1)
{
  RGE_Master_Moving_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055da1b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Master_Moving_Object *)operator_new(0xd8);
  uStack_4 = 0;
  if (this != (RGE_Master_Moving_Object *)0x0) {
    uVar1 = RGE_Master_Moving_Object::RGE_Master_Moving_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00451f22
// Address: 00451f22
// XREFS: None
void __thiscall FUN_00451f22(RGE_Master_Animated_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Master_Animated_Object::copy_obj(param_1,param_2);
  param_1[1]._padding_ = *(int *)&param_2[1].master_type;
  param_1[1]._padding_ = (int)param_2[1].name;
  param_1[1]._padding_ = *(int *)&param_2[1].string_id;
  *(char *)&param_1[1]._padding_ = (char)param_2[1].id;
  *(short *)((int)&param_1[1]._padding_ + 2) = param_2[1].copy_id;
  *(char *)&param_1[1]._padding_ = (char)param_2[1].object_group;
  param_1[1]._padding_ = (int)param_2[1].sprite;
  *(undefined1 *)&param_1[1]._padding_ = *(undefined1 *)&param_2[1].death_sprite;
  return;
}

// --------------------------------------------------

// Function: FUN_00451fa5
// Address: 00451fa5
// XREFS: None
void __thiscall FUN_00451fa5(RGE_Master_Animated_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\x06') {
    RGE_Master_Animated_Object::modify(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00451fd3
// Address: 00451fd3
// XREFS: None
void __thiscall FUN_00451fd3(RGE_Master_Animated_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\x06') {
    RGE_Master_Animated_Object::modify_delta(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)(param_2 + (float)param_1[1]._padding_);
  return;
}

// --------------------------------------------------

// Function: FUN_00452009
// Address: 00452009
// XREFS: None
void __thiscall FUN_00452009(RGE_Master_Animated_Object *param_1,float param_2,uchar param_3)
{
  if (param_3 != '\x06') {
    RGE_Master_Animated_Object::modify_percent(param_1,param_2,param_3);
    return;
  }
  param_1[1]._padding_ = (int)(param_2 * (float)param_1[1]._padding_);
  return;
}

// --------------------------------------------------

// Function: FUN_00452039
// Address: 00452039
// XREFS: None
void __thiscall FUN_00452039(RGE_Master_Animated_Object *param_1,int param_2)
{
  int iVar1;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  iVar1 = param_1[1]._padding_;
  if (iVar1 == 0) {
    uStack_8 = 0xffffffff;
  }
  else {
    uStack_8 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x72));
  }
  if (param_1[1]._padding_ != 0) {
    uStack_4 = CONCAT22(0xffff,*(undefined2 *)(param_1[1]._padding_ + 0x72));
  }
  RGE_Master_Animated_Object::save(param_1,param_2);
  rge_write(param_2,&uStack_8,2);
  rge_write(param_2,&uStack_4,2);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,1);
  rge_write(param_2,(void *)((int)&param_1[1]._padding_ + 2),2);
  rge_write(param_2,&param_1[1]._padding_,1);
  rge_write(param_2,&param_1[1]._padding_,4);
  rge_write(param_2,&param_1[1]._padding_,1);
  return;
}

// --------------------------------------------------

// Function: FUN_00452114
// Address: 00452114
// XREFS: None
RGE_Master_Static_Object * __thiscall
FUN_00452114(RGE_Master_Static_Object *param_1,RGE_Master_Static_Object *param_2,int param_3)
{
  param_1->_padding_ = (int)&RGE_Master_Static_Object::_vftable_;
  if (param_3 != 0) {
    RGE_Master_Static_Object::setup(param_1,param_2);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00452141
// Address: 00452141
// XREFS: None
RGE_Master_Static_Object * __thiscall FUN_00452141(RGE_Master_Static_Object *param_1,byte param_2)
{
  RGE_Master_Static_Object::~RGE_Master_Static_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045216e
// Address: 0045216e
// XREFS: None
RGE_Master_Static_Object * __thiscall
FUN_0045216e(RGE_Master_Static_Object *param_1,int param_2,RGE_Sprite **param_3,RGE_Sound **param_4,
            int param_5)
{
  param_1->_padding_ = (int)&RGE_Master_Static_Object::_vftable_;
  if (param_5 != 0) {
    RGE_Master_Static_Object::setup(param_1,param_2,param_3,param_4);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045219d
// Address: 0045219d
// XREFS: None
RGE_Master_Static_Object * __thiscall
FUN_0045219d(RGE_Master_Static_Object *param_1,_iobuf *param_2,RGE_Sprite **param_3,
            RGE_Sound **param_4,short param_5,int param_6)
{
  param_1->_padding_ = (int)&RGE_Master_Static_Object::_vftable_;
  if (param_6 != 0) {
    RGE_Master_Static_Object::setup(param_1,param_2,param_3,param_4,param_5);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004521d2
// Address: 004521d2
// XREFS: None
undefined4 __thiscall FUN_004521d2(int param_1,int param_2)
{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  short sVar6;
  undefined2 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  
  iVar3 = param_2;
  *(undefined1 *)(param_1 + 4) = 10;
  *(undefined1 *)(param_1 + 0xa4) = *(undefined1 *)(param_2 + 0xa4);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_2 + 0xe);
  uVar2 = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(param_1 + 0x10) = uVar2;
  *(undefined2 *)(param_1 + 0x12) = uVar2;
  *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(param_2 + 0x24);
  *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(param_2 + 0x26);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
  *(undefined1 *)(param_1 + 0x2c) = *(undefined1 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  *(undefined2 *)(param_1 + 0x48) = *(undefined2 *)(param_2 + 0x48);
  *(undefined1 *)(param_1 + 0x4a) = *(undefined1 *)(param_2 + 0x4a);
  *(undefined1 *)(param_1 + 0x4b) = *(undefined1 *)(param_2 + 0x4b);
  *(undefined2 *)(param_1 + 0x4c) = *(undefined2 *)(param_2 + 0x4c);
  *(undefined1 *)(param_1 + 0x4e) = *(undefined1 *)(param_2 + 0x4e);
  *(undefined2 *)(param_1 + 0x50) = *(undefined2 *)(param_2 + 0x50);
  *(undefined1 *)(param_1 + 0x52) = *(undefined1 *)(param_2 + 0x52);
  *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(param_2 + 0x54);
  *(undefined2 *)(param_1 + 0x56) = *(undefined2 *)(param_2 + 0x56);
  *(undefined2 *)(param_1 + 0x58) = *(undefined2 *)(param_2 + 0x58);
  *(undefined2 *)(param_1 + 0x5a) = *(undefined2 *)(param_2 + 0x5a);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
  *(undefined1 *)(param_1 + 100) = *(undefined1 *)(param_2 + 100);
  *(undefined1 *)(param_1 + 0x65) = *(undefined1 *)(param_2 + 0x65);
  *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(param_2 + 0x66);
  *(undefined1 *)(param_1 + 0x68) = *(undefined1 *)(param_2 + 0x68);
  *(undefined2 *)(param_1 + 0x7c) = *(undefined2 *)(param_2 + 0x7c);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_2 + 0x80);
  *(undefined1 *)(param_1 + 0x8b) = *(undefined1 *)(param_2 + 0x8b);
  *(undefined1 *)(param_1 + 0x8c) = *(undefined1 *)(param_2 + 0x8c);
  *(undefined1 *)(param_1 + 0x8d) = *(undefined1 *)(param_2 + 0x8d);
  *(undefined1 *)(param_1 + 0x8e) = *(undefined1 *)(param_2 + 0x8e);
  *(undefined1 *)(param_1 + 0x8f) = *(undefined1 *)(param_2 + 0x8f);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_2 + 0x84);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_2 + 0x44);
  *(undefined1 *)(param_1 + 0x91) = *(undefined1 *)(param_2 + 0x91);
  *(undefined1 *)(param_1 + 0x92) = *(undefined1 *)(param_2 + 0x92);
  *(undefined1 *)(param_1 + 0x90) = *(undefined1 *)(param_2 + 0x90);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_2 + 0x98);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_2 + 0x9c);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0xa0);
  *(undefined1 *)(param_1 + 0xa5) = *(undefined1 *)(param_2 + 0xa5);
  *(undefined1 *)(param_1 + 0xa6) = *(undefined1 *)(param_2 + 0xa6);
  *(undefined1 *)(param_1 + 0xa7) = *(undefined1 *)(param_2 + 0xa7);
  *(undefined1 *)(param_1 + 0xa8) = *(undefined1 *)(param_2 + 0xa8);
  *(undefined1 *)(param_1 + 0xa9) = *(undefined1 *)(param_2 + 0xa9);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_2 + 0xac);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_2 + 0xb0);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_2 + 0xb4);
  puVar8 = (undefined1 *)(param_1 + 0x88);
  puVar7 = (undefined2 *)(param_1 + 0x6a);
  iVar4 = param_2 - param_1;
  param_2 = 3;
  puVar9 = (undefined4 *)(param_1 + 0x70);
  do {
    *puVar7 = *(undefined2 *)(iVar4 + (int)puVar7);
    *puVar9 = *(undefined4 *)(iVar4 + -4 + (int)(puVar9 + 1));
    *puVar8 = puVar8[iVar4];
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
    param_2 = param_2 + -1;
    puVar9 = puVar9 + 1;
  } while (param_2 != 0);
  cVar1 = *(char *)(iVar3 + 0x93);
  *(char *)(param_1 + 0x93) = cVar1;
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  else {
    uVar5 = calloc(cVar1,8);
    *(undefined4 *)(param_1 + 0x94) = uVar5;
    sVar6 = 0;
    if (*(char *)(param_1 + 0x93) != '\0') {
      do {
        iVar4 = sVar6 * 8;
        sVar6 = sVar6 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x94) + iVar4) =
             *(undefined4 *)(*(int *)(iVar3 + 0x94) + iVar4);
        *(undefined1 *)(*(int *)(param_1 + 0x94) + 4 + iVar4) =
             *(undefined1 *)(*(int *)(iVar3 + 0x94) + 4 + iVar4);
        *(undefined1 *)(*(int *)(param_1 + 0x94) + 5 + iVar4) =
             *(undefined1 *)(*(int *)(iVar3 + 0x94) + 5 + iVar4);
      } while (sVar6 < (short)(ushort)*(byte *)(param_1 + 0x93));
    }
  }
  *(char **)(param_1 + 8) = (char *)0x0;
  getstring((char **)(param_1 + 8),*(char **)(iVar3 + 8));
  return 1;
}

// --------------------------------------------------

// Function: FUN_004524d3
// Address: 004524d3
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004524d3(int param_1,int param_2,int param_3,int param_4)
{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  void *pvVar5;
  void *pvVar6;
  int iVar7;
  short sStack_16;
  short sStack_14;
  short sStack_12;
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  void *pvStack_8;
  int iStack_4;
  
  iVar2 = param_2;
  *(undefined1 *)(param_1 + 4) = 10;
  rge_read(param_2,&param_2,2);
  rge_read(iVar2,(void *)(param_1 + 0x10),2);
  rge_read(iVar2,(void *)(param_1 + 0xc),2);
  rge_read(iVar2,(void *)(param_1 + 0xe),2);
  rge_read(iVar2,(void *)(param_1 + 0x14),2);
  rge_read(iVar2,&sStack_e,2);
  rge_read(iVar2,&sStack_c,2);
  rge_read(iVar2,&sStack_a,2);
  rge_read(iVar2,(void *)(param_1 + 0x24),1);
  rge_read(iVar2,(void *)(param_1 + 0x26),2);
  rge_read(iVar2,(void *)(param_1 + 0x28),4);
  rge_read(iVar2,(void *)(param_1 + 0x2c),1);
  rge_read(iVar2,(undefined4 *)(param_1 + 0x30),4);
  rge_read(iVar2,(undefined4 *)(param_1 + 0x34),4);
  rge_read(iVar2,(void *)(param_1 + 0x38),4);
  rge_read(iVar2,&sStack_10,2);
  rge_read(iVar2,(void *)(param_1 + 0x48),2);
  rge_read(iVar2,(void *)(param_1 + 0x4a),1);
  rge_read(iVar2,(void *)(param_1 + 0x4b),1);
  rge_read(iVar2,(void *)(param_1 + 0x4c),2);
  rge_read(iVar2,(void *)(param_1 + 0x4e),1);
  rge_read(iVar2,(void *)(param_1 + 0x50),2);
  rge_read(iVar2,(void *)(param_1 + 0x52),1);
  rge_read(iVar2,(void *)(param_1 + 0x54),2);
  rge_read(iVar2,(void *)(param_1 + 0x56),2);
  rge_read(iVar2,(void *)(param_1 + 0x58),2);
  rge_read(iVar2,(void *)(param_1 + 0x5a),2);
  rge_read(iVar2,(void *)(param_1 + 0x5c),4);
  rge_read(iVar2,(void *)(param_1 + 0x60),4);
  rge_read(iVar2,(void *)(param_1 + 100),1);
  rge_read(iVar2,(void *)(param_1 + 0x65),1);
  rge_read(iVar2,(void *)(param_1 + 0x66),2);
  rge_read(iVar2,(void *)(param_1 + 0x68),1);
  rge_read(iVar2,(void *)(param_1 + 0x7c),2);
  rge_read(iVar2,(void *)(param_1 + 0x80),4);
  rge_read(iVar2,(void *)(param_1 + 0x8b),1);
  rge_read(iVar2,(void *)(param_1 + 0x8c),1);
  rge_read(iVar2,(void *)(param_1 + 0x8d),1);
  rge_read(iVar2,(void *)(param_1 + 0x8e),1);
  rge_read(iVar2,(void *)(param_1 + 0x8f),1);
  rge_read(iVar2,(void *)(param_1 + 0x84),4);
  rge_read(iVar2,(void *)(param_1 + 0x90),1);
  rge_read(iVar2,(void *)(param_1 + 0x98),4);
  rge_read(iVar2,(void *)(param_1 + 0x9c),4);
  rge_read(iVar2,(void *)(param_1 + 0xa0),4);
  rge_read(iVar2,(void *)(param_1 + 0xa4),1);
  rge_read(iVar2,(void *)(param_1 + 0xa5),1);
  rge_read(iVar2,(void *)(param_1 + 0xa6),1);
  rge_read(iVar2,(void *)(param_1 + 0xa7),1);
  if (save_game_version < _DAT_00570610) {
    *(undefined1 *)(param_1 + 0xa8) = 0;
    *(undefined1 *)(param_1 + 0xa9) = 0;
    *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0x38);
  }
  else {
    rge_read(iVar2,(void *)(param_1 + 0xa8),1);
    rge_read(iVar2,(void *)(param_1 + 0xa9),1);
    rge_read(iVar2,(void *)(param_1 + 0xac),4);
    rge_read(iVar2,(void *)(param_1 + 0xb0),4);
    rge_read(iVar2,(void *)(param_1 + 0xb4),4);
  }
  pvStack_8 = (void *)(param_1 + 0x88);
  pvVar5 = (void *)(param_1 + 0x70);
  pvVar6 = (void *)(param_1 + 0x6a);
  iStack_4 = 3;
  do {
    rge_read(iVar2,pvVar6,2);
    rge_read(iVar2,pvVar5,4);
    rge_read(iVar2,pvStack_8,1);
    pvVar6 = (void *)((int)pvVar6 + 2);
    pvVar5 = (void *)((int)pvVar5 + 4);
    pvStack_8 = (void *)((int)pvStack_8 + 1);
    iStack_4 = iStack_4 + -1;
  } while (iStack_4 != 0);
  pcVar1 = (char *)(param_1 + 0x93);
  rge_read(iVar2,pcVar1,1);
  if (*pcVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  else {
    uVar3 = calloc(*pcVar1,8);
    *(undefined4 *)(param_1 + 0x94) = uVar3;
    sVar4 = 0;
    if (*pcVar1 != '\0') {
      do {
        rge_read(iVar2,&sStack_16,2);
        iVar7 = sVar4 * 8;
        rge_read(iVar2,(void *)(*(int *)(param_1 + 0x94) + 4 + iVar7),2);
        rge_read(iVar2,(void *)(*(int *)(param_1 + 0x94) + 5 + iVar7),1);
        if (sStack_16 < 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined4 *)(param_3 + sStack_16 * 4);
        }
        sVar4 = sVar4 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x94) + iVar7) = uVar3;
      } while (sVar4 < (short)(ushort)*(byte *)(param_1 + 0x93));
    }
  }
  rge_read(iVar2,&sStack_14,2);
  rge_read(iVar2,&sStack_12,2);
  rge_read(iVar2,(void *)(param_1 + 0x91),1);
  rge_read(iVar2,(void *)(param_1 + 0x92),1);
  if ((short)param_2 < 1) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    pvVar5 = (void *)calloc((int)(short)param_2,1);
    *(void **)(param_1 + 8) = pvVar5;
    rge_read(iVar2,pvVar5,(int)(short)param_2);
  }
  if (_DAT_00570614 <= save_game_version) {
    rge_read(iVar2,(void *)(param_1 + 0x12),2);
  }
  if (sStack_14 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_4 + sStack_14 * 4);
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  if (sStack_12 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_4 + sStack_12 * 4);
  }
  *(undefined4 *)(param_1 + 0x44) = uVar3;
  if (sStack_10 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_4 + sStack_10 * 4);
  }
  *(undefined4 *)(param_1 + 0x40) = uVar3;
  if (sStack_e < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_3 + sStack_e * 4);
  }
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  if (sStack_c < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_3 + sStack_c * 4);
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar3;
  if (sStack_a < 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    return 1;
  }
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + sStack_a * 4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00452afb
// Address: 00452afb
// XREFS: None
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__f__hd: "%hd %f %hd"
// [HELPER] s__hd__hd__hd: "%hd %hd %hd"
// [HELPER] s__hd__hd__hd__hd: "%hd %hd %hd %hd"
// [HELPER] s__s__hd__hd__hd__hd__hd__hd__hd__: "%s %hd %hd %hd %hd %hd %hd %hd %hd %f %hd %f %f %f %hd %hd %hd %hd %hd %hd %h..."
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00452afb(int param_1,undefined4 param_2,int param_3,int param_4,undefined2 param_5)
{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  short sVar6;
  int iVar7;
  char *pcVar8;
  undefined1 auStack_c2 [2];
  undefined1 auStack_c0 [2];
  short sStack_be;
  undefined1 auStack_bc [2];
  undefined1 auStack_ba [2];
  undefined1 auStack_b8 [2];
  short sStack_b6;
  undefined1 auStack_b4 [2];
  short sStack_b2;
  byte abStack_b0 [2];
  short sStack_ae;
  undefined1 auStack_ac [2];
  undefined1 auStack_aa [2];
  undefined1 auStack_a8 [2];
  undefined1 auStack_a6 [2];
  undefined1 auStack_a4 [2];
  undefined1 auStack_a2 [2];
  undefined1 auStack_a0 [2];
  undefined1 auStack_9e [2];
  undefined1 auStack_9c [2];
  short sStack_9a;
  undefined1 auStack_98 [2];
  short sStack_96;
  undefined1 auStack_94 [2];
  undefined1 auStack_92 [2];
  undefined1 auStack_90 [2];
  undefined1 auStack_8e [2];
  undefined1 auStack_8c [2];
  short sStack_8a;
  undefined1 auStack_88 [2];
  undefined1 auStack_86 [2];
  undefined1 auStack_84 [2];
  undefined1 auStack_82 [2];
  int iStack_80;
  uint uStack_7c;
  char acStack_78 [120];
  
  *(undefined1 *)(param_1 + 4) = 10;
  *(undefined2 *)(param_1 + 0x10) = param_5;
  fscanf(param_2,s__s__hd__hd__hd__hd__hd__hd__hd__,acStack_78,param_1 + 0xc,param_1 + 0xe,
         param_1 + 0x14,&sStack_b2,&sStack_96,&sStack_ae,auStack_ac,param_1 + 0x26,param_1 + 0x28,
         auStack_92,param_1 + 0x30,param_1 + 0x34,param_1 + 0x38,param_1 + 0x48,auStack_a6,
         auStack_86,param_1 + 0x4c,auStack_a8,param_1 + 0x50,auStack_a2,param_1 + 0x54,
         param_1 + 0x56,param_1 + 0x58,param_1 + 0x5a,param_1 + 0x5c,param_1 + 0x60,auStack_84,
         auStack_aa,abStack_b0,&sStack_8a,auStack_8e,param_1 + 0x7c,param_1 + 0x84,param_1 + 0x80,
         auStack_c2,auStack_c0,auStack_bc,auStack_b8,auStack_b4,auStack_9c,param_1 + 0x98,
         param_1 + 0x9c,param_1 + 0xa0,auStack_98,auStack_94,auStack_90,auStack_8c,auStack_88,
         param_1 + 0xac,param_1 + 0xb0,param_1 + 0xb4);
  puVar5 = (undefined1 *)(param_1 + 0x88);
  iVar4 = param_1 + 0x6a;
  iVar7 = param_1 + 0x70;
  iStack_80 = 3;
  do {
    fscanf(param_2,s__hd__f__hd,iVar4,iVar7,auStack_9e);
    *puVar5 = auStack_9e[0];
    iVar7 = iVar7 + 4;
    iVar4 = iVar4 + 2;
    puVar5 = puVar5 + 1;
    iStack_80 = iStack_80 + -1;
  } while (iStack_80 != 0);
  fscanf(param_2,s__hd,&uStack_7c);
  *(char *)(param_1 + 0x93) = (char)uStack_7c;
  if ((char)uStack_7c == '\0') {
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  else {
    uVar3 = calloc(uStack_7c & 0xff,8);
    *(undefined4 *)(param_1 + 0x94) = uVar3;
    sVar6 = 0;
    if (*(char *)(param_1 + 0x93) != '\0') {
      do {
        fscanf(param_2,s__hd__hd__hd,&sStack_be,auStack_82,auStack_ba);
        if (sStack_be < 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined4 *)(param_3 + sStack_be * 4);
        }
        iVar4 = sVar6 * 8;
        sVar6 = sVar6 + 1;
        *(undefined4 *)(iVar4 + *(int *)(param_1 + 0x94)) = uVar3;
        *(undefined1 *)(iVar4 + 4 + *(int *)(param_1 + 0x94)) = auStack_82[0];
        *(undefined1 *)(iVar4 + 5 + *(int *)(param_1 + 0x94)) = auStack_ba[0];
      } while (sVar6 < (short)(ushort)*(byte *)(param_1 + 0x93));
    }
  }
  fscanf(param_2,s__hd__hd__hd__hd,&sStack_9a,&sStack_b6,auStack_a4,auStack_a0);
  if (sStack_9a < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_4 + sStack_9a * 4);
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  if (sStack_b6 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_4 + sStack_b6 * 4);
  }
  *(undefined4 *)(param_1 + 0x44) = uVar3;
  if (sStack_8a < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_4 + sStack_8a * 4);
  }
  *(undefined4 *)(param_1 + 0x40) = uVar3;
  if (sStack_b2 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_3 + sStack_b2 * 4);
  }
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  if (sStack_96 < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_3 + sStack_96 * 4);
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar3;
  if (sStack_ae < 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_3 + sStack_ae * 4);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar3;
  *(undefined1 *)(param_1 + 100) = auStack_84[0];
  *(undefined1 *)(param_1 + 0x4a) = auStack_a6[0];
  *(undefined1 *)(param_1 + 0x68) = auStack_8e[0];
  *(undefined1 *)(param_1 + 0x65) = auStack_aa[0];
  *(undefined1 *)(param_1 + 0x8d) = auStack_bc[0];
  *(undefined1 *)(param_1 + 0x2c) = auStack_92[0];
  bVar2 = *(float *)(param_1 + 0xac) == _DAT_00570618;
  *(undefined1 *)(param_1 + 0x4b) = auStack_86[0];
  *(undefined1 *)(param_1 + 0x52) = auStack_a2[0];
  *(undefined1 *)(param_1 + 0x8b) = auStack_c2[0];
  *(ushort *)(param_1 + 0x66) = (ushort)abStack_b0[0];
  *(undefined1 *)(param_1 + 0x8c) = auStack_c0[0];
  *(undefined1 *)(param_1 + 0x8e) = auStack_b8[0];
  *(undefined1 *)(param_1 + 0x91) = auStack_a4[0];
  *(undefined1 *)(param_1 + 0x8f) = auStack_b4[0];
  *(undefined1 *)(param_1 + 0x24) = auStack_ac[0];
  *(undefined1 *)(param_1 + 0xa5) = auStack_98[0];
  *(undefined1 *)(param_1 + 0x4e) = auStack_a8[0];
  *(undefined1 *)(param_1 + 0x92) = auStack_a0[0];
  *(undefined1 *)(param_1 + 0xa8) = auStack_8c[0];
  *(undefined1 *)(param_1 + 0x90) = auStack_9c[0];
  *(undefined1 *)(param_1 + 0xa6) = auStack_94[0];
  *(undefined1 *)(param_1 + 0xa7) = auStack_90[0];
  *(undefined1 *)(param_1 + 0xa9) = auStack_88[0];
  if (bVar2) {
    *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0x30);
  }
  if (*(float *)(param_1 + 0xb0) == _DAT_00570618) {
    *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x34);
  }
  if (*(float *)(param_1 + 0xb4) == _DAT_00570618) {
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0x38);
  }
  *(undefined1 *)(param_1 + 0xa4) = 0;
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_1 + 0x10);
  if (*(short *)(param_1 + 0x14) == 0xb) {
    *(undefined1 *)(param_1 + 0xa4) = 1;
  }
  iVar4 = -1;
  pcVar8 = acStack_78;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  if (0 < (short)(~(ushort)iVar4 - 1)) {
    *(char **)(param_1 + 8) = (char *)0x0;
    getstring((char **)(param_1 + 8),acStack_78);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00452f9f
// Address: 00452f9f
// XREFS: None
void __fastcall FUN_00452f9f(undefined4 *param_1)
{
  *param_1 = &RGE_Master_Static_Object::_vftable_;
  if (param_1[2] != 0) {
    free(param_1[2]);
    param_1[2] = 0;
  }
  if (param_1[0x25] != 0) {
    free(param_1[0x25]);
    param_1[0x25] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00452fdf
// Address: 00452fdf
// XREFS: None
RGE_Static_Object * __thiscall
FUN_00452fdf(RGE_Master_Static_Object *param_1,RGE_Player *param_2,float param_3,float param_4,
            float param_5)
{
  RGE_Static_Object *pRVar1;
  float *unaff_FS_OFFSET;
  float fStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  fStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055da3b;
  *unaff_FS_OFFSET = (float)&fStack_c;
  if (param_1->recyclable != '\0') {
    pRVar1 = RGE_Game_World::recycle_object_in_to_game(param_2->world,param_1->master_type);
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      (**(code **)(pRVar1->_padding_ + 4))(param_1,param_2,param_3,param_4,param_5);
      *unaff_FS_OFFSET = param_4;
      return pRVar1;
    }
  }
  pRVar1 = (RGE_Static_Object *)operator_new(0x88);
  uStack_4 = 0;
  if (pRVar1 != (RGE_Static_Object *)0x0) {
    pRVar1 = (RGE_Static_Object *)
             RGE_Static_Object::RGE_Static_Object(pRVar1,param_1,param_2,param_3,param_4,param_5,1);
    *unaff_FS_OFFSET = fStack_c;
    return pRVar1;
  }
  *unaff_FS_OFFSET = fStack_c;
  return (RGE_Static_Object *)0x0;
}

// --------------------------------------------------

// Function: FUN_004530a9
// Address: 004530a9
// XREFS: None
undefined4 __fastcall FUN_004530a9(RGE_Master_Static_Object *param_1)
{
  RGE_Master_Static_Object *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055da5b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Master_Static_Object *)operator_new(0xb8);
  uStack_4 = 0;
  if (this != (RGE_Master_Static_Object *)0x0) {
    uVar1 = RGE_Master_Static_Object::RGE_Master_Static_Object(this,param_1,1);
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00453112
// Address: 00453112
// XREFS: None
void __thiscall FUN_00453112(int param_1,int param_2)
{
  char **ppcVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  
  uVar4 = *(undefined2 *)(param_1 + 0x10);
  uVar5 = *(undefined2 *)(param_1 + 0x12);
  uVar2 = *(undefined1 *)(param_1 + 0x52);
  uVar3 = *(undefined1 *)(param_1 + 0x4e);
  ppcVar1 = (char **)(param_1 + 8);
  if (*ppcVar1 != (char *)0x0) {
    free(*ppcVar1);
  }
  *(undefined1 *)(param_1 + 4) = *(undefined1 *)(param_2 + 4);
  *ppcVar1 = *(char **)(param_2 + 8);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_2 + 0x12);
  *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(param_2 + 0x24);
  *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(param_2 + 0x26);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
  *(undefined1 *)(param_1 + 0x2c) = *(undefined1 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_2 + 0x44);
  *(undefined2 *)(param_1 + 0x48) = *(undefined2 *)(param_2 + 0x48);
  *(undefined1 *)(param_1 + 0x4a) = *(undefined1 *)(param_2 + 0x4a);
  *(undefined1 *)(param_1 + 0x4b) = *(undefined1 *)(param_2 + 0x4b);
  *(undefined2 *)(param_1 + 0x4c) = *(undefined2 *)(param_2 + 0x4c);
  *(undefined1 *)(param_1 + 0x4e) = *(undefined1 *)(param_2 + 0x4e);
  *(undefined2 *)(param_1 + 0x50) = *(undefined2 *)(param_2 + 0x50);
  *(undefined1 *)(param_1 + 0x52) = *(undefined1 *)(param_2 + 0x52);
  *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(param_2 + 0x54);
  *(undefined2 *)(param_1 + 0x56) = *(undefined2 *)(param_2 + 0x56);
  *(undefined2 *)(param_1 + 0x58) = *(undefined2 *)(param_2 + 0x58);
  *(undefined2 *)(param_1 + 0x5a) = *(undefined2 *)(param_2 + 0x5a);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
  *(undefined1 *)(param_1 + 100) = *(undefined1 *)(param_2 + 100);
  *(undefined1 *)(param_1 + 0x65) = *(undefined1 *)(param_2 + 0x65);
  *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(param_2 + 0x66);
  *(undefined1 *)(param_1 + 0x68) = *(undefined1 *)(param_2 + 0x68);
  puVar6 = (undefined2 *)(param_1 + 0x6a);
  iVar10 = param_2 - param_1;
  iVar11 = 3;
  do {
    *puVar6 = *(undefined2 *)(iVar10 + (int)puVar6);
    puVar6 = puVar6 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  puVar7 = (undefined4 *)(param_1 + 0x70);
  iVar11 = 3;
  do {
    *puVar7 = *(undefined4 *)((int)puVar7 + iVar10);
    puVar7 = puVar7 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  *(undefined2 *)(param_1 + 0x7c) = *(undefined2 *)(param_2 + 0x7c);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_2 + 0x80);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_2 + 0x84);
  puVar8 = (undefined1 *)(param_1 + 0x88);
  do {
    *puVar8 = puVar8[iVar10];
    puVar8 = puVar8 + 1;
  } while (puVar8 + (-0x88 - param_1) < &DAT_00000003);
  *(undefined1 *)(param_1 + 0x8b) = *(undefined1 *)(param_2 + 0x8b);
  *(undefined1 *)(param_1 + 0x8c) = *(undefined1 *)(param_2 + 0x8c);
  *(undefined1 *)(param_1 + 0x8d) = *(undefined1 *)(param_2 + 0x8d);
  *(undefined1 *)(param_1 + 0x8e) = *(undefined1 *)(param_2 + 0x8e);
  *(undefined1 *)(param_1 + 0x8f) = *(undefined1 *)(param_2 + 0x8f);
  *(undefined1 *)(param_1 + 0x90) = *(undefined1 *)(param_2 + 0x90);
  *(undefined1 *)(param_1 + 0x91) = *(undefined1 *)(param_2 + 0x91);
  *(undefined1 *)(param_1 + 0x92) = *(undefined1 *)(param_2 + 0x92);
  *(undefined1 *)(param_1 + 0x93) = *(undefined1 *)(param_2 + 0x93);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_2 + 0x94);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_2 + 0x98);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_2 + 0x9c);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0xa0);
  *(undefined1 *)(param_1 + 0xa4) = *(undefined1 *)(param_2 + 0xa4);
  *(undefined1 *)(param_1 + 0xa5) = *(undefined1 *)(param_2 + 0xa5);
  *(undefined1 *)(param_1 + 0xa6) = *(undefined1 *)(param_2 + 0xa6);
  *(undefined1 *)(param_1 + 0xa7) = *(undefined1 *)(param_2 + 0xa7);
  *(undefined1 *)(param_1 + 0xa8) = *(undefined1 *)(param_2 + 0xa8);
  *(undefined1 *)(param_1 + 0xa9) = *(undefined1 *)(param_2 + 0xa9);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_2 + 0xac);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_2 + 0xb0);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_2 + 0xb4);
  if (*(char *)(param_2 + 0x4e) == '\x01') {
    *(undefined2 *)(param_1 + 0x12) = uVar5;
  }
  *(undefined1 *)(param_1 + 0x4e) = uVar3;
  *(undefined1 *)(param_2 + 0x4e) = 1;
  if (*(char *)(param_1 + 0x93) == '\0') {
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  else {
    uVar9 = calloc(*(char *)(param_1 + 0x93),8);
    *(undefined4 *)(param_1 + 0x94) = uVar9;
    iVar10 = 0;
    if (*(char *)(param_1 + 0x93) != '\0') {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x94) + iVar10 * 8) =
             *(undefined4 *)(*(int *)(param_2 + 0x94) + iVar10 * 8);
        *(undefined1 *)(*(int *)(param_1 + 0x94) + 4 + iVar10 * 8) =
             *(undefined1 *)(*(int *)(param_2 + 0x94) + 4 + iVar10 * 8);
        *(undefined1 *)(*(int *)(param_1 + 0x94) + 5 + iVar10 * 8) =
             *(undefined1 *)(*(int *)(param_2 + 0x94) + 5 + iVar10 * 8);
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x93));
    }
  }
  *ppcVar1 = (char *)0x0;
  getstring(ppcVar1,*(char **)(param_2 + 8));
  *(undefined2 *)(param_1 + 0x10) = uVar4;
  *(undefined1 *)(param_1 + 0x52) = uVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_00453493
// Address: 00453493
// XREFS: None
void __thiscall FUN_00453493(int param_1,undefined4 param_2,undefined1 param_3)
{
  undefined1 uVar1;
  undefined2 uVar2;
  
  switch(param_3) {
  case 0:
    uVar2 = __ftol();
    *(undefined2 *)(param_1 + 0x26) = uVar2;
    return;
  case 1:
    *(undefined4 *)(param_1 + 0x28) = param_2;
    return;
  case 2:
    uVar1 = __ftol();
    *(undefined1 *)(param_1 + 0x2c) = uVar1;
    return;
  case 3:
    *(undefined4 *)(param_1 + 0x30) = param_2;
    return;
  case 4:
    *(undefined4 *)(param_1 + 0x34) = param_2;
    return;
  case 0xe:
    uVar2 = __ftol();
    *(undefined2 *)(param_1 + 0x7c) = uVar2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00453513
// Address: 00453513
// XREFS: None
float10 __fastcall FUN_00453513(int param_1,int *param_2)
{
  undefined1 *puVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  uint in_EAX;
  char *pcVar5;
  int *piVar6;
  int unaff_ESI;
  undefined2 in_ES;
  float10 in_ST0;
  float10 fVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float fStack_18;
  
  puVar1 = (undefined1 *)(in_EAX * 2 + 0x4534d100);
  *puVar1 = *puVar1;
  fVar7 = in_ST0 / (float10)*(double *)(in_EAX * 2 + 0x4534ec00);
  *(byte *)param_2 = (char)*param_2 + ((byte)in_EAX ^ 0x45);
  pcVar5 = (char *)(in_EAX ^ 0x350f0000);
  *pcVar5 = *pcVar5 + (byte)in_EAX;
  *param_2 = (int)(pcVar5 + *param_2);
  iVar2 = *(int *)(pcVar5 + unaff_ESI);
  fStack_18 = (float)CONCAT22(fStack_18._2_2_,in_ES);
  piVar6 = (int *)(pcVar5 + iVar2 + 0x24448b90);
  *(byte *)(unaff_ESI + 0x25) = *(byte *)(unaff_ESI + 0x25) | (byte)param_2;
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + (char)piVar6;
  switch(pcVar5 + iVar2) {
  case (char *)0xdbbb7470:
    sVar4 = __ftol();
    *(short *)(param_1 + 0x26) = *(short *)(param_1 + 0x26) + sVar4;
    return extraout_ST0;
  case (char *)0xdbbb7471:
    *(float *)(param_1 + 0x28) = fStack_18 + *(float *)(param_1 + 0x28);
    return fVar7;
  case (char *)0xdbbb7472:
    cVar3 = __ftol();
    *(char *)(param_1 + 0x2c) = *(char *)(param_1 + 0x2c) + cVar3;
    return extraout_ST0_00;
  case (char *)0xdbbb7473:
    *(float *)(param_1 + 0x30) = fStack_18 + *(float *)(param_1 + 0x30);
    return fVar7;
  case (char *)0xdbbb7474:
    *(float *)(param_1 + 0x34) = fStack_18 + *(float *)(param_1 + 0x34);
    return fVar7;
  case (char *)0xdbbb747e:
    sVar4 = __ftol();
    *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + sVar4;
    fVar7 = extraout_ST0_01;
  }
  return fVar7;
}

// --------------------------------------------------

// Function: FUN_00453695
// Address: 00453695
// XREFS: None
void __fastcall FUN_00453695(char *param_1,int *param_2)
{
  char *pcVar1;
  undefined4 in_EAX;
  uint uVar2;
  char cVar3;
  undefined4 unaff_EBX;
  short sVar4;
  char *pcVar5;
  int unaff_ESI;
  char *unaff_EDI;
  char *pcVar6;
  int iVar7;
  undefined2 in_ES;
  char in_CF;
  uint uStack_40;
  int *piStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  int *piStack_28;
  undefined4 auStack_24 [2];
  char *pcStack_1c;
  
  iVar7 = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + '6' + in_CF);
  *param_1 = *param_1 + (char)((uint)param_2 >> 8);
  cVar3 = (char)((uint)unaff_EBX >> 8);
  *unaff_EDI = *unaff_EDI + cVar3;
  pcVar1 = (char *)(unaff_ESI * 2 + 0x45);
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  *(char *)((int)param_2 + 0x36) = *(char *)((int)param_2 + 0x36) + (char)((uint)param_1 >> 8);
  pcVar1 = (char *)(iVar7 + 0x36);
  *pcVar1 = *pcVar1 + cVar3;
  param_1[0x4536] = param_1[0x4536] + (char)param_2;
  *param_2 = *param_2 + iVar7;
  pcStack_1c = (char *)CONCAT22(pcStack_1c._2_2_,in_ES);
  pcVar1 = pcStack_1c;
  uVar2 = 0xffffffff;
  iVar7 = *(int *)(param_1 + 0x40);
  piStack_3c = (int *)0xffffffff;
  uStack_38 = 0xffffffff;
  uStack_34 = 0xffffffff;
  uStack_30 = 0xffffffff;
  auStack_24[0] = 0xffffffff;
  piStack_28 = (int *)0xffffffff;
  if (iVar7 != 0) {
    uStack_30 = CONCAT22((short)((uint)iVar7 >> 0x10),*(undefined2 *)(iVar7 + 0xc));
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    param_2 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),
                              *(undefined2 *)(*(int *)(param_1 + 0x3c) + 0xc));
    piStack_28 = param_2;
  }
  iVar7 = *(int *)(param_1 + 0x44);
  if (iVar7 != 0) {
    auStack_24[0] = CONCAT22((short)((uint)iVar7 >> 0x10),*(undefined2 *)(iVar7 + 0xc));
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    param_2 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),
                              *(undefined2 *)(*(int *)(param_1 + 0x18) + 0x72));
    piStack_3c = param_2;
  }
  iVar7 = *(int *)(param_1 + 0x1c);
  if (iVar7 != 0) {
    uStack_38 = CONCAT22((short)((uint)iVar7 >> 0x10),*(undefined2 *)(iVar7 + 0x72));
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    uStack_34 = CONCAT22((short)((uint)param_2 >> 0x10),
                         *(undefined2 *)(*(int *)(param_1 + 0x20) + 0x72));
  }
  pcVar5 = *(char **)(param_1 + 8);
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  uStack_40 = ~uVar2 - 1;
  if (0 < (short)uStack_40) {
    uStack_40 = ~uVar2;
  }
  rge_write((int)pcStack_1c,param_1 + 4,1);
  rge_write((int)pcVar1,&uStack_40,2);
  rge_write((int)pcVar1,param_1 + 0x10,2);
  rge_write((int)pcVar1,param_1 + 0xc,2);
  rge_write((int)pcVar1,param_1 + 0xe,2);
  rge_write((int)pcVar1,param_1 + 0x14,2);
  rge_write((int)pcVar1,&piStack_3c,2);
  rge_write((int)pcVar1,&uStack_38,2);
  rge_write((int)pcVar1,&uStack_34,2);
  rge_write((int)pcVar1,param_1 + 0x24,1);
  rge_write((int)pcVar1,param_1 + 0x26,2);
  rge_write((int)pcVar1,param_1 + 0x28,4);
  rge_write((int)pcVar1,param_1 + 0x2c,1);
  rge_write((int)pcVar1,param_1 + 0x30,4);
  rge_write((int)pcVar1,param_1 + 0x34,4);
  rge_write((int)pcVar1,param_1 + 0x38,4);
  rge_write((int)pcVar1,&uStack_30,2);
  rge_write((int)pcVar1,param_1 + 0x48,2);
  rge_write((int)pcVar1,param_1 + 0x4a,1);
  rge_write((int)pcVar1,param_1 + 0x4b,1);
  rge_write((int)pcVar1,param_1 + 0x4c,2);
  rge_write((int)pcVar1,param_1 + 0x4e,1);
  rge_write((int)pcVar1,param_1 + 0x50,2);
  rge_write((int)pcVar1,param_1 + 0x52,1);
  rge_write((int)pcVar1,param_1 + 0x54,2);
  rge_write((int)pcVar1,param_1 + 0x56,2);
  rge_write((int)pcVar1,param_1 + 0x58,2);
  rge_write((int)pcVar1,param_1 + 0x5a,2);
  rge_write((int)pcVar1,param_1 + 0x5c,4);
  rge_write((int)pcVar1,param_1 + 0x60,4);
  rge_write((int)pcVar1,param_1 + 100,1);
  rge_write((int)pcVar1,param_1 + 0x65,1);
  rge_write((int)pcVar1,param_1 + 0x66,2);
  rge_write((int)pcVar1,param_1 + 0x68,1);
  rge_write((int)pcVar1,param_1 + 0x7c,2);
  rge_write((int)pcVar1,param_1 + 0x80,4);
  rge_write((int)pcVar1,param_1 + 0x8b,1);
  rge_write((int)pcVar1,param_1 + 0x8c,1);
  rge_write((int)pcVar1,param_1 + 0x8d,1);
  rge_write((int)pcVar1,param_1 + 0x8e,1);
  rge_write((int)pcVar1,param_1 + 0x8f,1);
  rge_write((int)pcVar1,param_1 + 0x84,4);
  rge_write((int)pcVar1,param_1 + 0x90,1);
  rge_write((int)pcVar1,param_1 + 0x98,4);
  rge_write((int)pcVar1,param_1 + 0x9c,4);
  rge_write((int)pcVar1,param_1 + 0xa0,4);
  rge_write((int)pcVar1,param_1 + 0xa4,1);
  rge_write((int)pcVar1,param_1 + 0xa5,1);
  rge_write((int)pcVar1,param_1 + 0xa6,1);
  rge_write((int)pcVar1,param_1 + 0xa7,1);
  rge_write((int)pcVar1,param_1 + 0xa8,1);
  rge_write((int)pcVar1,param_1 + 0xa9,1);
  rge_write((int)pcVar1,param_1 + 0xac,4);
  rge_write((int)pcVar1,param_1 + 0xb0,4);
  rge_write((int)pcVar1,param_1 + 0xb4,4);
  pcStack_1c = param_1 + 0x88;
  pcVar5 = param_1 + 0x70;
  pcVar6 = param_1 + 0x6a;
  iStack_2c = 3;
  do {
    rge_write((int)pcVar1,pcVar6,2);
    rge_write((int)pcVar1,pcVar5,4);
    rge_write((int)pcVar1,pcStack_1c,1);
    pcVar6 = pcVar6 + 2;
    pcVar5 = pcVar5 + 4;
    pcStack_1c = pcStack_1c + 1;
    iStack_2c = iStack_2c + -1;
  } while (iStack_2c != 0);
  rge_write((int)pcVar1,param_1 + 0x93,1);
  cVar3 = param_1[0x93];
  if (cVar3 != '\0') {
    sVar4 = 0;
    if (cVar3 != '\0') {
      do {
        iVar7 = sVar4 * 8;
        rge_write((int)pcVar1,(void *)(*(int *)(*(int *)(param_1 + 0x94) + iVar7) + 0x72),2);
        rge_write((int)pcVar1,(void *)(*(int *)(param_1 + 0x94) + 4 + iVar7),2);
        rge_write((int)pcVar1,(void *)(*(int *)(param_1 + 0x94) + 5 + iVar7),1);
        sVar4 = sVar4 + 1;
      } while (sVar4 < (short)(ushort)(byte)param_1[0x93]);
    }
  }
  rge_write((int)pcVar1,&piStack_28,2);
  rge_write((int)pcVar1,auStack_24,2);
  rge_write((int)pcVar1,param_1 + 0x91,1);
  rge_write((int)pcVar1,param_1 + 0x92,1);
  if ((short)uStack_40 != 0) {
    rge_write((int)pcVar1,*(void **)(param_1 + 8),(int)(short)uStack_40);
  }
  rge_write((int)pcVar1,param_1 + 0x12,2);
  return;
}

// --------------------------------------------------

// Function: FUN_00453c33
// Address: 00453c33
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __thiscall
FUN_00453c33(int param_1,int param_2,float param_3,float param_4,undefined4 *param_5,char param_6,
            char param_7,undefined4 param_8,char param_9,char param_10,char param_11)
{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  float fVar7;
  float fVar8;
  bool bVar9;
  uchar uVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  ushort uVar15;
  byte *pbVar16;
  short sVar17;
  undefined4 *puVar18;
  int iVar19;
  int *piVar20;
  int iVar21;
  short sStack_38;
  short sStack_34;
  short sStack_30;
  short sStack_2c;
  short sStack_28;
  float fStack_20;
  float fStack_1c;
  short sStack_8;
  
  iVar3 = *(int *)(*(int *)(param_2 + 0x3c) + 0x28);
  iVar4 = *(int *)(*(int *)(*(int *)(param_2 + 0x3c) + 0x54) + *(short *)(param_1 + 0x66) * 4);
  if (param_9 == '\0') {
    fStack_20 = *(float *)(param_1 + 0x30);
    fStack_1c = *(float *)(param_1 + 0x34);
  }
  else {
    fStack_20 = *(float *)(param_1 + 0x5c);
    fStack_1c = *(float *)(param_1 + 0x60);
  }
  if ((((param_3 - fStack_20 < (float)_DAT_00570620) ||
       (iVar21 = *(int *)(iVar3 + 8), (float)iVar21 <= (fStack_20 + param_3) - _DAT_0057061c)) ||
      (param_4 - fStack_1c < (float)_DAT_00570620)) ||
     (iVar5 = *(int *)(iVar3 + 0xc), (float)iVar5 <= (fStack_1c + param_4) - _DAT_0057061c)) {
    return 7;
  }
  sVar11 = __ftol();
  sVar12 = __ftol();
  sVar13 = __ftol();
  sVar14 = __ftol();
  uVar2 = *(ushort *)(param_1 + 0x58);
  if ((-1 < (short)uVar2) ||
     (sStack_30 = sVar13, sStack_28 = sVar12, sStack_34 = sVar14, sVar17 = sVar11,
     -1 < *(short *)(param_1 + 0x5a))) {
    sStack_30 = __ftol();
    sStack_28 = __ftol();
    uVar15 = (ushort)(*(byte *)(*(int *)(*(int *)(iVar3 + 0x8d8c) + sStack_30 * 4) + 5 +
                               sStack_28 * 0x18) & 0x1f);
    sStack_34 = sStack_30;
    sVar17 = sStack_28;
    if ((uVar15 != uVar2) && (uVar15 != *(ushort *)(param_1 + 0x5a))) {
      return 1;
    }
  }
  bVar6 = false;
  bVar9 = false;
  uVar2 = *(ushort *)(param_1 + 0x54);
  if ((-1 < (short)uVar2) || (-1 < *(short *)(param_1 + 0x56))) {
    sStack_8 = sVar17 + -1;
    if ((-1 < (short)(sStack_30 + -1)) && (sVar17 <= sStack_28)) {
      pbVar16 = (byte *)(*(int *)(*(int *)(iVar3 + 0x8d8c) + (short)(sStack_30 + -1) * 4) + 5 +
                        sVar17 * 0x18);
      iVar19 = ((int)sStack_28 - (int)sVar17) + 1;
      do {
        if ((*pbVar16 & 0x1f) == uVar2) {
          bVar6 = true;
        }
        if ((ushort)(*pbVar16 & 0x1f) == *(ushort *)(param_1 + 0x56)) {
          bVar9 = true;
        }
        pbVar16 = pbVar16 + 0x18;
        iVar19 = iVar19 + -1;
      } while (iVar19 != 0);
    }
    if (((short)(sStack_28 + 1) < iVar21) && (sStack_30 <= sStack_34)) {
      piVar20 = (int *)(*(int *)(iVar3 + 0x8d8c) + sStack_30 * 4);
      iVar21 = ((int)sStack_34 - (int)sStack_30) + 1;
      do {
        uVar15 = (ushort)(*(byte *)(*piVar20 + 5 + (short)(sStack_28 + 1) * 0x18) & 0x1f);
        if (uVar15 == uVar2) {
          bVar6 = true;
        }
        if (uVar15 == *(ushort *)(param_1 + 0x56)) {
          bVar9 = true;
        }
        piVar20 = piVar20 + 1;
        iVar21 = iVar21 + -1;
      } while (iVar21 != 0);
    }
    if (((short)(sStack_34 + 1) < iVar5) && (sVar17 <= sStack_28)) {
      pbVar16 = (byte *)(*(int *)(*(int *)(iVar3 + 0x8d8c) + (short)(sStack_34 + 1) * 4) + 5 +
                        sStack_28 * 0x18);
      iVar21 = ((int)sStack_28 - (int)sVar17) + 1;
      do {
        if ((*pbVar16 & 0x1f) == uVar2) {
          bVar6 = true;
        }
        if ((ushort)(*pbVar16 & 0x1f) == *(ushort *)(param_1 + 0x56)) {
          bVar9 = true;
        }
        pbVar16 = pbVar16 + -0x18;
        iVar21 = iVar21 + -1;
      } while (iVar21 != 0);
    }
    if ((-1 < sStack_8) && (sStack_30 <= sStack_34)) {
      piVar20 = (int *)(*(int *)(iVar3 + 0x8d8c) + sStack_34 * 4);
      iVar21 = ((int)sStack_34 - (int)sStack_30) + 1;
      do {
        uVar15 = (ushort)(*(byte *)(*piVar20 + 5 + sStack_8 * 0x18) & 0x1f);
        if (uVar15 == uVar2) {
          bVar6 = true;
        }
        if (uVar15 == *(ushort *)(param_1 + 0x56)) {
          bVar9 = true;
        }
        piVar20 = piVar20 + -1;
        iVar21 = iVar21 + -1;
      } while (iVar21 != 0);
    }
    if ((!bVar6) && (!bVar9)) {
      return 1;
    }
  }
  bVar6 = false;
  for (; sVar11 <= sVar12; sVar11 = sVar11 + 1) {
    if (sVar13 <= sVar14) {
      iVar21 = sVar11 * 0x18;
      sVar17 = sVar13;
      do {
        iVar5 = sVar17 * 4;
        if (*(float *)(iVar4 + (*(byte *)(*(int *)(*(int *)(iVar3 + 0x8d8c) + iVar5) + 5 + iVar21) &
                               0x1f) * 4) <= _DAT_00570618) {
          return 2;
        }
        if ((param_6 != '\0') &&
           ((rge_base_game->prog_mode == 7 ||
            (uVar10 = RGE_Visible_Map::get_visible
                                (*(RGE_Visible_Map **)(param_2 + 0x38),(int)sVar11,(int)sVar17),
            uVar10 != '\0')))) {
          bVar6 = true;
        }
        if (param_7 != '\0') {
          cVar1 = *(char *)(*(int *)(*(int *)(iVar3 + 0x8d8c) + iVar5) + 4 + iVar21);
          if (*(char *)(param_1 + 100) == '\x01') {
            if ((((cVar1 != '\0') && (cVar1 != '\x05')) && (cVar1 != '\a')) &&
               ((cVar1 != '\x06' && (cVar1 != '\b')))) {
              return 3;
            }
          }
          else if ((*(char *)(param_1 + 100) == '\x02') && (cVar1 != '\0')) {
            return 3;
          }
        }
        sVar17 = sVar17 + 1;
      } while (sVar17 <= sVar14);
    }
  }
  if ((param_6 == '\x01') && (!bVar6)) {
    return 5;
  }
  if ((fStack_20 <= _DAT_00570618) && (fStack_1c <= _DAT_00570618)) {
    return 0;
  }
  sVar11 = __ftol();
  sVar12 = __ftol();
  sStack_38 = __ftol();
  sStack_2c = __ftol();
  if (sVar11 < 0) {
    sVar11 = 0;
  }
  if (*(int *)(iVar3 + 8) <= (int)sStack_38) {
    sStack_38 = *(short *)(iVar3 + 8) + -1;
  }
  if (sVar12 < 0) {
    sVar12 = 0;
  }
  if (*(int *)(iVar3 + 0xc) <= (int)sStack_2c) {
    sStack_2c = *(short *)(iVar3 + 0xc) + -1;
  }
  if ((param_11 != '\0') &&
     (((param_10 != '\0' || ((float)_DAT_00570620 < *(float *)(param_1 + 0x38))) &&
      (sVar12 <= sStack_2c)))) {
    do {
      if (sVar11 <= sStack_38) {
        puVar18 = (undefined4 *)
                  (*(int *)(*(int *)(iVar3 + 0x8d8c) + sVar12 * 4) + sVar11 * 0x18 + 0x10);
        sVar13 = sVar11;
        do {
          for (piVar20 = (int *)*puVar18; piVar20 != (int *)0x0; piVar20 = (int *)piVar20[1]) {
            iVar4 = *piVar20;
            if ((*(byte *)(iVar4 + 0x48) < 7) &&
               (((param_10 == '\0' || (*(char *)(*(int *)(iVar4 + 8) + 0x4b) != '\x01')) ||
                (*(char *)(param_1 + 0x4b) != '\0')))) {
              iVar21 = *(int *)(iVar4 + 8);
              if ((((float)_DAT_00570620 < *(float *)(iVar21 + 0x30)) &&
                  ((float)_DAT_00570620 < *(float *)(iVar21 + 0x34))) &&
                 ((((float)_DAT_00570620 < *(float *)(iVar21 + 0x38) &&
                   ((float)_DAT_00570620 < *(float *)(param_1 + 0x38))) ||
                  ((*(float *)(iVar21 + 0x38) <= (float)_DAT_00570620 &&
                   (*(float *)(param_1 + 0x38) <= (float)_DAT_00570620)))))) {
                fVar7 = *(float *)(iVar4 + 0x3c) - param_4;
                fVar8 = *(float *)(iVar4 + 0x38) - param_3;
                if (fVar7 < _DAT_00570618) {
                  fVar7 = -fVar7;
                }
                if (fVar8 < _DAT_00570618) {
                  fVar8 = -fVar8;
                }
                if ((fVar8 < *(float *)(iVar21 + 0x30) + fStack_20) &&
                   (fVar7 < *(float *)(iVar21 + 0x34) + fStack_1c)) {
                  if (param_5 != (undefined4 *)0x0) {
                    *param_5 = *(undefined4 *)(iVar4 + 4);
                  }
                  return 6;
                }
              }
            }
          }
          puVar18 = puVar18 + 6;
          sVar13 = sVar13 + 1;
        } while (sVar13 <= sStack_38);
      }
      sVar12 = sVar12 + 1;
    } while (sVar12 <= sStack_2c);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004543b5
// Address: 004543b5
// XREFS: None
void __thiscall FUN_004543b5(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x52) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004543ca
// Address: 004543ca
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004543ca(int param_1,float *param_2,float *param_3,int param_4,char param_5)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  short sVar11;
  undefined4 uVar12;
  undefined2 uVar14;
  undefined3 uVar13;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  
  iVar5 = *(int *)(param_4 + 0x28);
  fVar3 = *param_2 - *(float *)(param_1 + 0x30);
  fVar1 = *param_3 - *(float *)(param_1 + 0x34);
  fVar2 = *param_2 + *(float *)(param_1 + 0x30);
  fVar4 = *param_3 + *(float *)(param_1 + 0x34);
  fVar9 = (float)*(int *)(iVar5 + 8) - _DAT_00570630;
  fVar10 = (float)*(int *)(iVar5 + 0xc) - _DAT_00570630;
  if (fVar3 < _DAT_00570618) {
    fVar3 = -fVar3;
    fVar2 = fVar2 + fVar3;
    *param_2 = *param_2 + fVar3;
  }
  if (fVar1 < _DAT_00570618) {
    fVar1 = -fVar1;
    fVar4 = fVar4 + fVar1;
    *param_3 = *param_3 + fVar1;
  }
  if (fVar9 <= fVar2) {
    *param_2 = *param_2 + (fVar9 - fVar2);
  }
  if (fVar4 < fVar10 == 0) {
    *param_3 = *param_3 + (fVar10 - fVar4);
  }
  if (param_5 == '\0') {
    return CONCAT31((int3)(CONCAT22((short)((uint)iVar5 >> 0x10),
                                    (ushort)(fVar4 < fVar10) << 8 |
                                    (ushort)(NAN(fVar4) || NAN(fVar10)) << 10 |
                                    (ushort)(fVar4 == fVar10) << 0xe) >> 8),1);
  }
  sVar11 = __ftol();
  fVar1 = (float)(extraout_ST0 - (float10)(int)sVar11);
  sVar11 = __ftol();
  fVar2 = (float)(extraout_ST1 - (float10)(int)sVar11);
  sVar11 = __ftol();
  fVar3 = (float)((float10)_DAT_00570634 - (extraout_ST1_00 - (float10)(int)sVar11));
  uVar12 = __ftol();
  uVar14 = (undefined2)((uint)uVar12 >> 0x10);
  fVar4 = (float)((float10)_DAT_00570634 - (extraout_ST1_01 - (float10)(int)(short)uVar12));
  if (fVar3 + fVar1 < _DAT_00570634) {
    fVar1 = *param_2;
  }
  else if (fVar1 < fVar3) {
    fVar1 = *param_2 - (_DAT_00570634 - fVar3);
  }
  else {
    fVar1 = (_DAT_00570634 - fVar1) + *param_2;
  }
  fVar3 = fVar4 + fVar2;
  bVar6 = NAN(_DAT_00570634);
  bVar7 = fVar3 < _DAT_00570634;
  bVar8 = fVar3 == _DAT_00570634;
  if (bVar7 == 0) {
    uVar13 = (undefined3)
             (CONCAT22(uVar14,(ushort)(fVar2 < fVar4) << 8 |
                              (ushort)(NAN(fVar2) || NAN(fVar4)) << 10 |
                              (ushort)(fVar2 == fVar4) << 0xe) >> 8);
    if (fVar2 < fVar4 == 0 && (fVar2 == fVar4) == 0) {
      fVar2 = _DAT_00570634 - fVar2;
      fVar3 = *param_3;
      *param_2 = fVar1;
      *param_3 = fVar2 + fVar3;
      return CONCAT31(uVar13,1);
    }
    fVar4 = _DAT_00570634 - fVar4;
    fVar2 = *param_3;
    *param_2 = fVar1;
    *param_3 = fVar2 - fVar4;
    return CONCAT31(uVar13,1);
  }
  fVar2 = *param_3;
  *param_2 = fVar1;
  *param_3 = fVar2;
  return CONCAT31((int3)(CONCAT22(uVar14,(ushort)bVar7 << 8 | (ushort)(NAN(fVar3) || bVar6) << 10 |
                                         (ushort)bVar8 << 0xe) >> 8),1);
}

// --------------------------------------------------

// Function: FUN_00454682
// Address: 00454682
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00454682(void)
{
  undefined2 uVar1;
  undefined2 *in_stack_00000010;
  undefined2 *in_stack_00000014;
  undefined2 *in_stack_00000018;
  undefined2 *in_stack_0000001c;
  undefined2 *in_stack_00000020;
  undefined2 *in_stack_00000024;
  undefined2 *in_stack_00000028;
  undefined2 *in_stack_0000002c;
  
  __ftol();
  __ftol();
  uVar1 = __ftol();
  *in_stack_00000010 = uVar1;
  uVar1 = __ftol();
  *in_stack_00000014 = uVar1;
  uVar1 = __ftol();
  *in_stack_00000018 = uVar1;
  uVar1 = __ftol();
  *in_stack_0000001c = uVar1;
  uVar1 = __ftol();
  *in_stack_00000020 = uVar1;
  uVar1 = __ftol();
  *in_stack_00000024 = uVar1;
  uVar1 = __ftol();
  *in_stack_00000028 = uVar1;
  uVar1 = __ftol();
  *in_stack_0000002c = uVar1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004547e1
// Address: 004547e1
// XREFS: None
void __thiscall
FUN_004547e1(int param_1,TDrawArea *param_2,undefined4 param_3,undefined4 param_4,
            RGE_Color_Table *param_5,long param_6,long param_7,int param_8,uint param_9)
{
  RGE_Map *this;
  short sVar1;
  int iVar2;
  short sVar3;
  short sStack_e;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(RGE_Sprite **)(param_1 + 0x18) != (RGE_Sprite *)0x0) {
    sVar3 = (short)param_4;
    iVar2 = (int)sVar3;
    sVar1 = (short)param_3;
    fStack_4 = (float)param_1;
    RGE_Sprite::draw(*(RGE_Sprite **)(param_1 + 0x18),param_6,param_7,(int)sVar1,iVar2,(int)sVar1,
                     iVar2,param_5,param_2,'\n');
    if (param_8 != 0) {
      fStack_c = *(float *)((int)fStack_4 + 0xac);
      fStack_8 = *(float *)((int)fStack_4 + 0xb0);
      this = rge_base_game->world->map;
      fStack_4 = -fStack_8;
      RGE_Map::get_point(this,&sStack_e,(short *)&param_8,fStack_c,fStack_4,0.0,sVar1,sVar3);
      RGE_Map::get_point(this,(short *)&param_6,(short *)&param_7,fStack_c,fStack_8,0.0,sVar1,sVar3)
      ;
      fStack_c = -fStack_c;
      RGE_Map::get_point(this,(short *)&param_5,(short *)&param_2,fStack_c,fStack_8,0.0,sVar1,sVar3)
      ;
      RGE_Map::get_point(this,(short *)&param_3,(short *)&param_4,fStack_c,fStack_4,0.0,sVar1,sVar3)
      ;
      DClipInfo_List::AddGDINode
                (SDI_List,1,iVar2,(int)sStack_e,(int)(short)param_8,(int)(short)param_6,
                 (int)(short)param_7,(int)(short)param_5,(int)(short)param_2,(int)(short)param_3,
                 (int)(short)param_4,10,param_9 & 0xff,SDI_Object_ID);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045494c
// Address: 0045494c
// XREFS: None
undefined4 __fastcall FUN_0045494c(int param_1)
{
  return *(undefined4 *)(param_1 + 0x98);
}

// --------------------------------------------------

// Function: FUN_00454957
// Address: 00454957
// XREFS: None
undefined4 __fastcall FUN_00454957(int param_1)
{
  return *(undefined4 *)(param_1 + 0x9c);
}

// --------------------------------------------------

// Function: FUN_00454967
// Address: 00454967
// XREFS: None
undefined4 __fastcall FUN_00454967(int param_1)
{
  return *(undefined4 *)(param_1 + 0xa0);
}

// --------------------------------------------------

// Function: FUN_00454977
// Address: 00454977
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454977(int param_1)
{
  int iVar1;
  
  iVar1 = (int)*(short *)(param_1 + 0x108);
  if (0 < iVar1) {
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  __ftol();
  return;
}

// --------------------------------------------------

// Function: FUN_004549df
// Address: 004549df
// XREFS: None
// [HELPER] s_00_03_01_0717: "00.03.01.0717"
// [HELPER] s_: ""
// [HELPER] s_AOE: "AOE"
// [HELPER] s_Age_of_Empires__Roman_Expansion: "Age of Empires, Roman Expansion"
// [HELPER] s_AppIcon: "AppIcon"
// [HELPER] s_Software_Microsoft_Games_Age_of_: "Software\Microsoft\Games\Age of Empires\1.00"
// [HELPER] s__s: "%s"
// [HELPER] s_avi_: "avi\"
// [HELPER] s_campaign_: "campaign\"
// [HELPER] s_data2_: "data2\"
// [HELPER] s_data2_empires_dat: "data2\empires.dat"
// [HELPER] s_mcursors: "mcursors"
// [HELPER] s_palette: "palette"
// [HELPER] s_savegame_: "savegame\"
// [HELPER] s_scenario_: "scenario\"
// [HELPER] s_sound_: "sound\"
// [HELPER] s_tr_wrld_txt: "tr_wrld.txt"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

undefined4 FUN_004549df(void *param_1,void *param_2,char *param_3,int param_4)
{
  char cVar1;
  undefined4 *puVar2;
  TRIBE_Game *this;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_EBP;
  char *pcVar7;
  RGE_Prog_Info *pRVar8;
  char *pcVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_144c;
  RGE_Prog_Info RStack_1444;
  undefined1 auStack_20c [244];
  undefined1 auStack_118 [12];
  undefined1 auStack_10c [252];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055da7e;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_10 = 0x4549ff;
  uVar5 = 0xffffffff;
  pcVar7 = &s_Age_of_Empires__Roman_Expansion;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pRVar8 = &RStack_1444;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pRVar8->prog_name = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pRVar8 = (RGE_Prog_Info *)(pRVar8->prog_name + 4);
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    pRVar8->prog_name[0] = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pRVar8 = (RGE_Prog_Info *)(pRVar8->prog_name + 1);
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_00_03_01_0717;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.prog_version;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  sprintf(RStack_1444.prog_title,s__s,&RStack_1444);
  uVar5 = 0xffffffff;
  pcVar7 = &s_tr_wrld_txt;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.world_db_file;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_data2_empires_dat;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.game_data_file;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_Software_Microsoft_Games_Age_of_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.registry_key;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar7 = param_3;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar7 + -uVar5;
  pcVar9 = RStack_1444.cmd_line;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_AppIcon;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.icon_name;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.menu_name;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_palette;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.pal_file;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_mcursors;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.cursor_file;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_AOE;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.vol_name;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  RStack_1444.prev_instance = param_2;
  RStack_1444.instance = param_1;
  RStack_1444.show_wnd_flag = param_4;
  RStack_1444.mouse_scroll_interval = 0x54;
  RStack_1444.key_scroll_interval = 0x54;
  RStack_1444.game_guid.Data2 = (ushort)DAT_00570654;
  RStack_1444.game_guid.Data3 = DAT_00570654._2_2_;
  RStack_1444.game_guid.Data1 = _TRIBE_GUID;
  RStack_1444.game_guid.Data4[4] = (uchar)DAT_0057065c;
  RStack_1444.game_guid.Data4[5] = DAT_0057065c._1_1_;
  RStack_1444.game_guid.Data4[6] = DAT_0057065c._2_1_;
  RStack_1444.game_guid.Data4[7] = DAT_0057065c._3_1_;
  RStack_1444.game_guid.Data4[0] = (uchar)DAT_00570658;
  RStack_1444.game_guid.Data4[1] = DAT_00570658._1_1_;
  RStack_1444.game_guid.Data4[2] = DAT_00570658._2_1_;
  RStack_1444.game_guid.Data4[3] = DAT_00570658._3_1_;
  RStack_1444.zone_guid.Data2 = (ushort)DAT_00570664;
  RStack_1444.zone_guid.Data3 = DAT_00570664._2_2_;
  RStack_1444.zone_guid.Data1 = _ZONE_GUID;
  RStack_1444.zone_guid.Data4[4] = (uchar)DAT_0057066c;
  RStack_1444.zone_guid.Data4[5] = DAT_0057066c._1_1_;
  RStack_1444.zone_guid.Data4[6] = DAT_0057066c._2_1_;
  RStack_1444.zone_guid.Data4[7] = DAT_0057066c._3_1_;
  RStack_1444.vol_ser_num = 0;
  RStack_1444.verify_cd = 1;
  RStack_1444.max_players_per_cd = 3;
  RStack_1444.max_players = 8;
  RStack_1444.check_expiration = 0;
  RStack_1444.expire_month = 0;
  RStack_1444.expire_day = 0;
  RStack_1444.expire_year = 0;
  RStack_1444.update_interval = 1;
  RStack_1444.check_multi_copies = 1;
  RStack_1444.skip_startup = 0;
  RStack_1444.full_screen = 1;
  RStack_1444.fixed_window_size = 1;
  RStack_1444.use_dir_draw = 1;
  RStack_1444.use_sys_mem = 0;
  RStack_1444.use_music = 1;
  RStack_1444.use_sound = 1;
  RStack_1444.fast_view = 1;
  RStack_1444.auto_scroll = 1;
  RStack_1444.mouse_scroll_edge = 3;
  RStack_1444.mouse_scroll_max_dist = 4.0;
  RStack_1444.key_scroll_max_dist = 4.0;
  RStack_1444.key_scroll_object_move = 0.05;
  RStack_1444.interface_style = 2;
  RStack_1444.use_cd_audio = 0;
  RStack_1444.use_ima = 0;
  RStack_1444.use_midi = 0;
  RStack_1444.use_wave_music = 0;
  RStack_1444.main_wid = 800;
  RStack_1444.main_hgt = 600;
  RStack_1444.zone_guid.Data4[0] = (uchar)DAT_00570668;
  RStack_1444.zone_guid.Data4[1] = DAT_00570668._1_1_;
  RStack_1444.zone_guid.Data4[2] = DAT_00570668._2_1_;
  RStack_1444.zone_guid.Data4[3] = DAT_00570668._3_1_;
  uVar5 = 0xffffffff;
  pcVar7 = &s_data2_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.data_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_sound_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.sounds_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = s_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.graphics_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_savegame_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.save_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_scenario_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.scenario_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_campaign_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.campaign_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_data2_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.resource_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_data2_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.ai_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &s_avi_;
  do {
    pcVar9 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar9 + -uVar5;
  pcVar9 = RStack_1444.avi_dir;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  uStack_144c = 0;
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  this = (TRIBE_Game *)operator_new(0x1254);
  uStack_4 = 0;
  if (this == (TRIBE_Game *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)TRIBE_Game::TRIBE_Game(this,&RStack_1444,1);
  }
  uStack_4 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    puVar2 = (undefined4 *)*piVar3;
    iVar4 = (*(code *)puVar2[6])();
    if (iVar4 == 0) {
      uStack_144c = (*(code *)puVar2[1])();
      (*(code *)puVar2[6])();
      (*(code *)*puVar2)(1);
    }
    else if (iVar4 != 4) {
      (*(code *)puVar2[8])(0x7d1,auStack_20c,0x100);
      (*(code *)puVar2[10])(1,unaff_EBP,0,auStack_118,0x100);
      (*(code *)*puVar2)(1);
      MessageBoxA(0,auStack_10c,auStack_20c,0x10);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return uStack_144c;
}

// --------------------------------------------------

// Function: _WinMain@16
// Address: 004549e0
// XREFS: entry
// [HELPER] s_00_03_01_0717: "00.03.01.0717"
// [HELPER] s_: ""
// [HELPER] s_AOE: "AOE"
// [HELPER] s_Age_of_Empires__Roman_Expansion: "Age of Empires, Roman Expansion"
// [HELPER] s_AppIcon: "AppIcon"
// [HELPER] s_Software_Microsoft_Games_Age_of_: "Software\Microsoft\Games\Age of Empires\1.00"
// [HELPER] s__s: "%s"
// [HELPER] s_avi_: "avi\"
// [HELPER] s_campaign_: "campaign\"
// [HELPER] s_data2_: "data2\"
// [HELPER] s_data2_empires_dat: "data2\empires.dat"
// [HELPER] s_mcursors: "mcursors"
// [HELPER] s_palette: "palette"
// [HELPER] s_savegame_: "savegame\"
// [HELPER] s_scenario_: "scenario\"
// [HELPER] s_sound_: "sound\"
// [HELPER] s_tr_wrld_txt: "tr_wrld.txt"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Variable defined which should be unmapped: retval */

int _WinMain_16(void *param_1,undefined4 param_2,char *param_3,undefined4 param_4)
{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_EBP;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  int retval;
  int error_code;
  RGE_Prog_Info info;
  char title [256];
  char msg [256];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055da7e;
                    /* language.dll match for 0x1440: "Axeman" */
  *unaff_FS_OFFSET = &local_c;
  uVar4 = 0xffffffff;
  pcVar7 = info.prog_name;
  pcVar8 = &s_Age_of_Empires__Roman_Expansion;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = info.prog_version;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_00_03_01_0717;
  do {
    pcVar6 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  sprintf(info.prog_title + 4,s__s,info.prog_name + 4);
  uVar4 = 0xffffffff;
  pcVar7 = &s_tr_wrld_txt;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.world_db_file;
  pcVar6 = info.game_data_file;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_data2_empires_dat;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.registry_key;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar6 = pcVar6 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar8 = &s_Software_Microsoft_Games_Age_of_;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = info.cmd_line;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar7 = param_3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = info.icon_name;
  pcVar7 = pcVar7 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_AppIcon;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.menu_name;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar6 = pcVar6 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar8 = s_;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = info.pal_file;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_palette;
  do {
    pcVar6 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.cursor_file;
  pcVar6 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar8 = pcVar8 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar8 = &s_mcursors;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  pcVar6 = info.vol_name;
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_AOE;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar6 = pcVar6 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  }
  info.registry_key._0_4_ = param_2;
  info.prev_instance = param_1;
  info.icon_name._0_4_ = param_4;
  info.mouse_scroll_max_dist = 1.17709e-43;
  info.key_scroll_max_dist = 1.17709e-43;
  info.game_guid.Data4[0] = (uchar)DAT_00570654;
  info.game_guid.Data4[1] = DAT_00570654._1_1_;
  info.game_guid.Data4[2] = DAT_00570654._2_1_;
  info.game_guid.Data4[3] = DAT_00570654._3_1_;
  info.game_guid.Data2 = (ushort)_TRIBE_GUID;
  info.game_guid.Data3 = _TRIBE_GUID._2_2_;
  info.zone_guid.Data1 = DAT_0057065c;
  info.game_guid.Data4[4] = (uchar)DAT_00570658;
  info.game_guid.Data4[5] = DAT_00570658._1_1_;
  info.game_guid.Data4[6] = DAT_00570658._2_1_;
  info.game_guid.Data4[7] = DAT_00570658._3_1_;
  info.zone_guid.Data4[0] = (uchar)DAT_00570664;
  info.zone_guid.Data4[1] = DAT_00570664._1_1_;
  info.zone_guid.Data4[2] = DAT_00570664._2_1_;
  info.zone_guid.Data4[3] = DAT_00570664._3_1_;
  info.zone_guid.Data2 = (ushort)_ZONE_GUID;
  info.zone_guid.Data3 = _ZONE_GUID._2_2_;
  info.data_dir[0] = (char)DAT_0057066c;
  info.data_dir[1] = DAT_0057066c._1_1_;
  info.data_dir[2] = DAT_0057066c._2_1_;
  info.data_dir[3] = DAT_0057066c._3_1_;
  info.verify_cd = 0;
  info.max_players_per_cd = 1;
  info.instance = &DAT_00000003;
  info.check_expiration = 8;
  info.expire_month = 0;
  info.expire_day = 0;
  info.expire_year = 0;
  info._2182_2_ = 0;
  info.update_interval._0_2_ = 0;
  info.check_multi_copies = 1;
  info.skip_startup = 1;
  info.full_screen = 0;
  info.fixed_window_size = 1;
  info.use_dir_draw = 1;
  info.use_sys_mem = 1;
  info.use_music = 0;
  info.use_sound = 1;
  info.use_cd_audio = 1;
  info.auto_scroll = 1;
  info.mouse_scroll_edge = 1;
  info.mouse_scroll_interval = 3;
  info.key_scroll_interval = 0x40800000;
  info.key_scroll_object_move = 4.0;
  info.interface_style = -0x3333;
  info._2270_2_ = 0x3d4c;
  info.main_wid._0_2_ = 2;
  info.use_ima = 0;
  info.use_midi = 0;
  info.use_wave_music = 0;
  info.fast_view = 0;
  info.main_hgt = 800;
  info.game_guid.Data1 = 600;
  info.zone_guid.Data4[4] = (uchar)DAT_00570668;
  info.zone_guid.Data4[5] = DAT_00570668._1_1_;
  info.zone_guid.Data4[6] = DAT_00570668._2_1_;
  info.zone_guid.Data4[7] = DAT_00570668._3_1_;
  pcVar7 = info.data_dir;
  uVar4 = 0xffffffff;
  pcVar8 = &s_data2_;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_sound_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.sounds_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = s_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.graphics_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_savegame_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.save_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_scenario_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.scenario_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = info.campaign_dir;
  pcVar8 = &s_campaign_;
  do {
    pcVar6 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar6;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = pcVar6 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_data2_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.resource_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_data2_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.ai_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &s_avi_;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = info.avi_dir;
  pcVar8 = pcVar8 + -uVar4;
  for (uVar5 = uVar4 >> 2; pcVar7 = pcVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  error_code = 0;
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  info.prog_name._0_4_ = operator_new(0x1254);
  local_4 = 0;
  if ((TRIBE_Game *)info.prog_name._0_4_ == (TRIBE_Game *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)TRIBE_Game::TRIBE_Game
                              ((TRIBE_Game *)info.prog_name._0_4_,
                               (RGE_Prog_Info *)(info.prog_name + 4),1);
  }
  local_4 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    puVar2 = (undefined4 *)*piVar3;
    info.prog_name._0_4_ = (*(code *)puVar2[6])();
    if (info.prog_name._0_4_ == 0) {
      error_code = (*(code *)puVar2[1])();
      (*(code *)puVar2[6])();
      (*(code *)*puVar2)(1);
    }
    else if (info.prog_name._0_4_ != 4) {
                    /* language.dll match for 0x7d1: "Error" */
      (*(code *)puVar2[8])(0x7d1,title + 4,0x100);
      (*(code *)puVar2[10])(1,unaff_EBP,0,title + 0xf8,0x100);
      (*(code *)*puVar2)(1);
      MessageBoxA(0,msg + 4,title + 4,0x10);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return error_code;
}

// --------------------------------------------------

// Function: FUN_00454ff1
// Address: 00454ff1
// XREFS: None
RGE_Map * __thiscall FUN_00454ff1(RGE_Map *param_1,int param_2,RGE_Sound **param_3,char param_4)
{
  RGE_Game_World *pRVar1;
  
  param_1->_padding_ = (int)&RGE_Map::_vftable_;
  param_1->map_zones = (RGE_Zone_Map_List *)0x0;
  rge_read(param_2,param_1,0x8dd0);
  pRVar1 = rge_base_game->world;
  param_1->map = (RGE_Tile *)0x0;
  param_1->game_world = pRVar1;
  param_1->search_map = (uchar *)0x0;
  param_1->map_row_offset = (RGE_Tile **)0x0;
  param_1->search_map_rows = (uchar **)0x0;
  RGE_Map::load_terrain_types(param_1,param_3);
  RGE_Map::load_border_types(param_1,param_3);
  RGE_Map::init_tile_sizes(param_1);
  if (param_4 != '\0') {
    RGE_Map::data_load_random_map(param_1,param_2);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045507f
// Address: 0045507f
// XREFS: None
RGE_Map * __thiscall FUN_0045507f(RGE_Map *param_1,byte param_2)
{
  RGE_Map::~RGE_Map(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045509e
// Address: 0045509e
// XREFS: None
RGE_Map * __thiscall
FUN_0045509e(RGE_Map *param_1,char *param_2,char *param_3,undefined4 param_4,short param_5,
            short param_6,short param_7,RGE_Sound **param_8)
{
  short *psVar1;
  RGE_Sound **ppRVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  param_1->_padding_ = (int)&RGE_Map::_vftable_;
  param_1->map_zones = (RGE_Zone_Map_List *)0x0;
  param_1->random_map = (RGE_RMM_Database_Controller *)0x0;
  param_1->game_world = rge_base_game->world;
  param_1->tile_width = param_5;
  param_1->tile_half_width = param_5 / 2;
  param_1->tile_height = param_6;
  param_1->tile_half_height = param_6 / 2;
  param_1->elev_height = param_7;
  param_1->map_width = 0;
  param_1->map_height = 0;
  param_1->world_width = 0;
  param_1->world_height = 0;
  RGE_Map::set_tile_size(param_1,'\0',param_5,param_6,0);
  RGE_Map::set_tile_size(param_1,'\x01',param_1->tile_width,param_1->elev_height,-100);
  RGE_Map::set_tile_size
            (param_1,'\x02',param_1->tile_width,param_1->elev_height + param_1->tile_height,100);
  RGE_Map::set_tile_size(param_1,'\x03',param_1->tile_width,param_1->tile_height,-100);
  RGE_Map::set_tile_size(param_1,'\x04',param_1->tile_width,param_1->tile_height,-100);
  RGE_Map::set_tile_size(param_1,'\x05',param_1->tile_width,param_1->elev_height,-100);
  RGE_Map::set_tile_size
            (param_1,'\x06',param_1->tile_width,param_1->elev_height + param_1->tile_height,100);
  RGE_Map::set_tile_size(param_1,'\a',param_1->tile_width,param_1->elev_height,-100);
  RGE_Map::set_tile_size
            (param_1,'\b',param_1->tile_width,param_1->elev_height + param_1->tile_height,100);
  RGE_Map::set_tile_size(param_1,'\t',param_1->tile_width,param_1->elev_height,-100);
  RGE_Map::set_tile_size
            (param_1,'\n',param_1->tile_width,param_1->elev_height + param_1->tile_height,100);
  RGE_Map::set_tile_size(param_1,'\v',param_1->tile_width,param_1->tile_height,-100);
  RGE_Map::set_tile_size(param_1,'\f',param_1->tile_width,param_1->tile_height,-100);
  RGE_Map::set_tile_size(param_1,'\r',param_1->tile_width,param_1->elev_height,-100);
  RGE_Map::set_tile_size
            (param_1,'\x0e',param_1->tile_width,param_1->elev_height + param_1->tile_height,100);
  RGE_Map::set_tile_size(param_1,'\x0f',param_1->tile_width,param_1->tile_height,100);
  RGE_Map::set_tile_size(param_1,'\x10',param_1->tile_width,param_1->tile_height,100);
  RGE_Map::set_tile_size(param_1,'\x11',param_1->tile_half_width,param_1->tile_height,0);
  RGE_Map::set_tile_size(param_1,'\x12',param_1->tile_half_width,param_1->tile_height,0);
  param_1->cur_row = 0;
  param_1->cur_col = 0;
  param_1->num_terrain = 0;
  param_1->max_terrain = 0;
  param_1->block_beg_row = 0;
  param_1->block_end_row = 0;
  param_1->block_beg_col = 0;
  param_1->block_end_col = 0;
  param_1->any_frame_change = '\0';
  param_1->map_visible_flag = '\0';
  param_1->fog_flag = '\x01';
  iVar5 = 0x20;
  psVar4 = &param_1->terrain_types[0].rows;
  do {
    psVar4[0x6d] = 0;
    *psVar4 = 0;
    psVar4[1] = 0;
    psVar1 = psVar4 + 0x40;
    iVar3 = 0x1e;
    do {
      psVar1[-0x1e] = 0;
      *psVar1 = 0;
      psVar1 = psVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    psVar1 = psVar4;
    for (iVar3 = 0x10; psVar1 = psVar1 + 2, iVar3 != 0; iVar3 = iVar3 + -1) {
      psVar1[0] = 0;
      psVar1[1] = 0;
    }
    *(TShape **)(psVar4 + -0x4d) = (TShape *)0x0;
    *(RGE_Sound **)(psVar4 + -0x4b) = (RGE_Sound *)0x0;
    iVar5 = iVar5 + -1;
    psVar4 = psVar4 + 0xcc;
  } while (iVar5 != 0);
  ppRVar2 = &param_1->border_types[0xf].sound;
  iVar5 = 0x10;
  do {
    ppRVar2[-1] = (RGE_Sound *)0x0;
    *ppRVar2 = (RGE_Sound *)0x0;
    ppRVar2 = ppRVar2 + -0x168;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  RGE_Map::load_terrain_types(param_1,param_3,param_8);
  RGE_Map::load_border_types(param_1,param_2,param_8);
  param_1->map = (RGE_Tile *)0x0;
  param_1->search_map = (uchar *)0x0;
  param_1->map_row_offset = (RGE_Tile **)0x0;
  param_1->search_map_rows = (uchar **)0x0;
  param_1->unified_vis_map = (RGE_Unified_Visible_Map *)0x0;
  param_1->unit_manager = (Visible_Unit_Manager *)0x0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00455426
// Address: 00455426
// XREFS: None
void __fastcall FUN_00455426(undefined4 *param_1)
{
  RGE_Zone_Map_List *this;
  RGE_RMM_Database_Controller *this_00;
  TShape *pTVar1;
  RGE_Unified_Visible_Map *this_01;
  Visible_Unit_Manager *this_02;
  int iVar2;
  undefined4 *puVar3;
  
  this = (RGE_Zone_Map_List *)param_1[0x2371];
  *param_1 = &RGE_Map::_vftable_;
  if (this != (RGE_Zone_Map_List *)0x0) {
    RGE_Zone_Map_List::~RGE_Zone_Map_List(this);
    operator_delete(this);
    param_1[0x2371] = 0;
  }
  this_00 = (RGE_RMM_Database_Controller *)param_1[0x236f];
  if (this_00 != (RGE_RMM_Database_Controller *)0x0) {
    RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller(this_00);
    operator_delete(this_00);
    param_1[0x236f] = 0;
  }
  if (param_1[1] != 0) {
    free(param_1[1]);
  }
  if (param_1[0x236c] != 0) {
    free(param_1[0x236c]);
  }
  if (param_1[0x2363] != 0) {
    free(param_1[0x2363]);
  }
  if (param_1[0x236d] != 0) {
    free(param_1[0x236d]);
  }
  puVar3 = param_1 + 0xc85;
  iVar2 = 0x20;
  do {
    pTVar1 = (TShape *)*puVar3;
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
      *puVar3 = 0;
    }
    puVar3 = puVar3 + -0x66;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar3 = param_1 + 0x2203;
  iVar2 = 0x10;
  do {
    pTVar1 = (TShape *)*puVar3;
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
      *puVar3 = 0;
    }
    puVar3 = puVar3 + -0x168;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this_01 = (RGE_Unified_Visible_Map *)param_1[0x2372];
  if (this_01 != (RGE_Unified_Visible_Map *)0x0) {
    RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(this_01);
    operator_delete(this_01);
  }
  this_02 = (Visible_Unit_Manager *)param_1[0x2373];
  if (this_02 != (Visible_Unit_Manager *)0x0) {
    Visible_Unit_Manager::~Visible_Unit_Manager(this_02);
    operator_delete(this_02);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00455561
// Address: 00455561
// XREFS: None
void __fastcall FUN_00455561(RGE_Map *param_1)
{
  param_1->tile_width = 0x40;
  param_1->tile_height = 0x20;
  param_1->tile_half_width = 0x20;
  param_1->tile_half_height = 0x10;
  param_1->elev_height = 0x10;
  RGE_Map::set_tile_size(param_1,'\0',0x40,0x20,0);
  RGE_Map::set_tile_size(param_1,'\x01',param_1->tile_width,param_1->elev_height,-8);
  RGE_Map::set_tile_size
            (param_1,'\x02',param_1->tile_width,param_1->elev_height + param_1->tile_height,8);
  RGE_Map::set_tile_size(param_1,'\x03',param_1->tile_width,param_1->tile_height,-8);
  RGE_Map::set_tile_size(param_1,'\x04',param_1->tile_width,param_1->tile_height,-8);
  RGE_Map::set_tile_size(param_1,'\x05',param_1->tile_width,param_1->elev_height,-8);
  RGE_Map::set_tile_size
            (param_1,'\x06',param_1->tile_width,param_1->elev_height + param_1->tile_height,8);
  RGE_Map::set_tile_size(param_1,'\a',param_1->tile_width,param_1->elev_height,-8);
  RGE_Map::set_tile_size
            (param_1,'\b',param_1->tile_width,param_1->elev_height + param_1->tile_height,8);
  RGE_Map::set_tile_size(param_1,'\t',param_1->tile_width,param_1->elev_height,-8);
  RGE_Map::set_tile_size
            (param_1,'\n',param_1->tile_width,param_1->elev_height + param_1->tile_height,8);
  RGE_Map::set_tile_size(param_1,'\v',param_1->tile_width,param_1->tile_height,-8);
  RGE_Map::set_tile_size(param_1,'\f',param_1->tile_width,param_1->tile_height,-8);
  RGE_Map::set_tile_size(param_1,'\r',param_1->tile_width,param_1->elev_height,-8);
  RGE_Map::set_tile_size
            (param_1,'\x0e',param_1->tile_width,param_1->elev_height + param_1->tile_height,8);
  RGE_Map::set_tile_size(param_1,'\x0f',param_1->tile_width,param_1->tile_height,8);
  RGE_Map::set_tile_size(param_1,'\x10',param_1->tile_width,param_1->tile_height,8);
  RGE_Map::set_tile_size(param_1,'\x11',param_1->tile_half_width,param_1->tile_height,0);
  RGE_Map::set_tile_size(param_1,'\x12',param_1->tile_half_width,param_1->tile_height,0);
  return;
}

// --------------------------------------------------

// Function: FUN_004557b8
// Address: 004557b8
// XREFS: None
void __thiscall FUN_004557b8(int param_1,int param_2)
{
  RGE_RMM_Database_Controller *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055da9b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_RMM_Database_Controller *)operator_new(0x4f5c);
  uStack_4 = 0;
  if (this == (RGE_RMM_Database_Controller *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(this,param_2);
  }
  *(undefined4 *)(param_1 + 0x8dbc) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0045581e
// Address: 0045581e
// XREFS: None
void __thiscall FUN_0045581e(int param_1,char *param_2,char *param_3,char *param_4,char *param_5)
{
  RGE_RMM_Database_Controller *this;
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dabb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_RMM_Database_Controller *)operator_new(0x4f5c);
  uStack_4 = 0;
  if (this == (RGE_RMM_Database_Controller *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = RGE_RMM_Database_Controller::RGE_RMM_Database_Controller
                      (this,param_3,param_4,param_5,param_2);
  }
  *(undefined4 *)(param_1 + 0x8dbc) = uVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0045588d
// Address: 0045588d
// XREFS: None
void __thiscall FUN_0045588d(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x8db8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0045589d
// Address: 0045589d
// XREFS: None
void __thiscall FUN_0045589d(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x8db9) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004558ad
// Address: 004558ad
// XREFS: None
void __thiscall
FUN_004558ad(RGE_Map *param_1,RGE_Player *param_2,RGE_Game_World *param_3,uchar param_4,long param_5
            ,long param_6)
{
  RGE_Map::new_map(param_1,param_5,param_6);
  if (param_3 != (RGE_Game_World *)0x0) {
    RGE_Game_World::reset_object_count(param_3);
  }
  RGE_Map::set_terrain
            (param_1,param_2,param_3,0,0,(short)param_5 + -1,(short)param_6 + -1,param_4,'\x01',0);
  if (param_3 != (RGE_Game_World *)0x0) {
    RGE_Game_World::reset_player_visible_maps(param_3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00455904
// Address: 00455904
// XREFS: None
void __thiscall FUN_00455904(RGE_Map *param_1,int param_2,int param_3)
{
  RGE_Player **ppRVar1;
  RGE_Player *pRVar2;
  RGE_Tile *pRVar3;
  uchar *puVar4;
  RGE_Tile **ppRVar5;
  uchar **ppuVar6;
  RGE_Zone_Map_List *pRVar7;
  RGE_Unified_Visible_Map *pRVar8;
  Visible_Unit_Manager *pVVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055daf1;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if ((0 < param_2) && (0 < param_3)) {
    if (param_1->map != (RGE_Tile *)0x0) {
      if (param_1->game_world != (RGE_Game_World *)0x0) {
        iVar11 = (int)param_1->game_world->player_num;
        iVar12 = 0;
        if (0 < iVar11) {
          do {
            ppRVar1 = param_1->game_world->players;
            if ((ppRVar1 != (RGE_Player **)0x0) &&
               (pRVar2 = ppRVar1[iVar12], pRVar2 != (RGE_Player *)0x0)) {
              RGE_Object_List::removeAllObjects(pRVar2->objects);
              RGE_Object_List::removeAllObjects
                        (param_1->game_world->players[iVar12]->sleeping_objects);
              RGE_Object_List::removeAllObjects
                        (param_1->game_world->players[iVar12]->doppleganger_objects);
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 < iVar11);
        }
      }
      free(param_1->map);
    }
    if (param_1->search_map != (uchar *)0x0) {
      free(param_1->search_map);
    }
    if (param_1->map_row_offset != (RGE_Tile **)0x0) {
      free(param_1->map_row_offset);
    }
    if (param_1->search_map_rows != (uchar **)0x0) {
      free(param_1->search_map_rows);
    }
    param_1->map_height = param_3;
    param_1->map_width = param_2;
    param_1->world_width = param_1->tile_width * param_2;
    param_1->world_height = param_1->tile_height * param_3;
    pRVar3 = (RGE_Tile *)calloc(param_3 * param_2,0x18);
    param_1->map = pRVar3;
    puVar4 = (uchar *)calloc(param_1->map_height * param_1->map_width,1);
    param_1->search_map = puVar4;
    ppRVar5 = (RGE_Tile **)calloc(param_1->map_height + 1,4);
    param_1->map_row_offset = ppRVar5;
    ppuVar6 = (uchar **)calloc(param_1->map_height + 1,4);
    param_1->search_map_rows = ppuVar6;
    iVar11 = 0;
    if (0 < param_1->map_height) {
      do {
        param_1->map_row_offset[iVar11] = param_1->map + iVar11 * param_1->map_width;
        param_1->search_map_rows[iVar11] = param_1->search_map + iVar11 * param_1->map_width;
        iVar11 = iVar11 + 1;
      } while (iVar11 < param_1->map_height);
    }
    iVar11 = 0;
    param_1->map_row_offset[param_1->map_height] = param_1->map;
    param_1->search_map_rows[param_1->map_height] = param_1->search_map;
    if (0 < param_1->map_height) {
      do {
        iVar12 = 0;
        if (0 < param_1->map_width) {
          iVar10 = 0;
          do {
            iVar12 = iVar12 + 1;
            (&param_1->map_row_offset[iVar11]->field_0x5)[iVar10] =
                 (&param_1->map_row_offset[iVar11]->field_0x5)[iVar10] & 0x1f | 0x20;
            iVar10 = iVar10 + 0x18;
          } while (iVar12 < param_1->map_width);
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < param_1->map_height);
    }
    RGE_Map::set_map_screen_pos(param_1,0,0,param_1->map_width + -1,param_1->map_height + -1);
    pRVar7 = param_1->map_zones;
    if (pRVar7 != (RGE_Zone_Map_List *)0x0) {
      RGE_Zone_Map_List::~RGE_Zone_Map_List(pRVar7);
      operator_delete(pRVar7);
    }
    pRVar7 = (RGE_Zone_Map_List *)operator_new(0xc);
    uStack_4 = 0;
    if (pRVar7 == (RGE_Zone_Map_List *)0x0) {
      pRVar7 = (RGE_Zone_Map_List *)0x0;
    }
    else {
      pRVar7 = (RGE_Zone_Map_List *)RGE_Zone_Map_List::RGE_Zone_Map_List(pRVar7,param_1);
    }
    pRVar8 = param_1->unified_vis_map;
    uStack_4 = 0xffffffff;
    param_1->map_zones = pRVar7;
    if (pRVar8 != (RGE_Unified_Visible_Map *)0x0) {
      RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(pRVar8);
      operator_delete(pRVar8);
    }
    pRVar8 = (RGE_Unified_Visible_Map *)operator_new(0xc);
    uStack_4 = 1;
    if (pRVar8 == (RGE_Unified_Visible_Map *)0x0) {
      pRVar8 = (RGE_Unified_Visible_Map *)0x0;
    }
    else {
      pRVar8 = (RGE_Unified_Visible_Map *)
               RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(pRVar8,param_2,param_3);
    }
    pVVar9 = param_1->unit_manager;
    uStack_4 = 0xffffffff;
    param_1->unified_vis_map = pRVar8;
    if (pVVar9 != (Visible_Unit_Manager *)0x0) {
      Visible_Unit_Manager::~Visible_Unit_Manager(pVVar9);
      operator_delete(pVVar9);
    }
    pVVar9 = (Visible_Unit_Manager *)operator_new(0x24);
    uStack_4 = 2;
    if (pVVar9 == (Visible_Unit_Manager *)0x0) {
      pVVar9 = (Visible_Unit_Manager *)0x0;
    }
    else {
      pVVar9 = (Visible_Unit_Manager *)
               Visible_Unit_Manager::Visible_Unit_Manager
                         (pVVar9,(int)param_1->game_world->player_num,0x40);
    }
    param_1->unit_manager = pVVar9;
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00455c1f
// Address: 00455c1f
// XREFS: None
void __thiscall FUN_00455c1f(RGE_Map *param_1,byte param_2,char param_3)
{
  RGE_Tile *pRVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < param_1->map_height) {
    do {
      iVar3 = 0;
      pRVar1 = param_1->map_row_offset[iVar2];
      if (0 < param_1->map_width) {
        do {
          pRVar1->tile_type = '\0';
          pRVar1->field_0x6 = 0;
          pRVar1->screen_xpos = 0;
          pRVar1->field_0x5 = param_2 & 0x1f | param_3 << 5;
          pRVar1->screen_ypos = 0;
          pRVar1->last_drawn_as = '\0';
          pRVar1->last_drawn_shape = 0xff;
          pRVar1->draw_as = '\0';
          pRVar1->draw_attribute = '\0';
          pRVar1->last_drawn_shape2 = 0xff;
          pRVar1 = pRVar1 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_1->map_width);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1->map_height);
  }
  RGE_Map::set_map_screen_pos(param_1,0,0,param_1->map_width + -1,param_1->map_height + -1);
  return;
}

// --------------------------------------------------

// Function: FUN_00455ca8
// Address: 00455ca8
// XREFS: None
void __thiscall
FUN_00455ca8(int param_1,int param_2,int param_3,int param_4,int param_5,undefined1 param_6)
{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_5;
  iVar4 = param_2;
  if (param_4 < param_2) {
    iVar4 = param_4;
    param_4 = param_2;
  }
  if (param_5 < param_3) {
    param_5 = param_3;
    param_3 = iVar3;
  }
  if ((((-1 < param_4) && (-1 < param_5)) && (iVar3 = *(int *)(param_1 + 8), iVar4 < iVar3)) &&
     (iVar1 = *(int *)(param_1 + 0xc), param_3 < iVar1)) {
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (iVar3 <= param_4) {
      param_4 = iVar3 + -1;
    }
    if (iVar1 <= param_5) {
      param_5 = iVar1 + -1;
    }
    if (param_3 <= param_5) {
      do {
        if (iVar4 <= param_4) {
          puVar2 = (undefined1 *)
                   (*(int *)(*(int *)(param_1 + 0x8d8c) + param_3 * 4) + iVar4 * 0x18 + 10);
          iVar3 = (param_4 - iVar4) + 1;
          do {
            puVar2[-3] = 0xcc;
            *puVar2 = param_6;
            puVar2 = puVar2 + 0x18;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        param_3 = param_3 + 1;
      } while (param_3 <= param_5);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00455d5f
// Address: 00455d5f
// XREFS: None
void __fastcall FUN_00455d5f(int param_1)
{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    do {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 8)) {
        puVar1 = (undefined1 *)(*(int *)(*(int *)(param_1 + 0x8d8c) + iVar3 * 4) + 8);
        do {
          puVar1[-1] = 0;
          *puVar1 = 0xff;
          puVar1[1] = 0;
          puVar1[2] = 0;
          puVar1[3] = 0xff;
          puVar1 = puVar1 + 0x18;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 8));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0xc));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00455daa
// Address: 00455daa
// XREFS: None
void __fastcall FUN_00455daa(RGE_Map *param_1)
{
  RGE_Map::set_map_screen_pos(param_1,0,0,param_1->map_width + -1,param_1->map_height + -1);
  return;
}

// --------------------------------------------------

// Function: FUN_00455dc4
// Address: 00455dc4
// XREFS: None
void __thiscall FUN_00455dc4(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  short *psVar1;
  int iVar2;
  
  if (param_2 < 0) {
    param_2 = 0;
    iVar2 = param_2;
  }
  else {
    iVar2 = *(int *)(param_1 + 8) + -1;
    if (param_2 <= iVar2) goto LAB_00455df4;
  }
  param_2 = iVar2;
LAB_00455df4:
  if (param_3 < 0) {
    param_3 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + -1;
    if (iVar2 < param_3) {
      param_3 = iVar2;
    }
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 8) + -1;
    if (iVar2 < param_4) {
      param_4 = iVar2;
    }
  }
  if (param_5 < 0) {
    param_5 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + -1;
    if (iVar2 < param_5) {
      param_5 = iVar2;
    }
  }
  if (param_3 <= param_5) {
    do {
      psVar1 = (short *)(*(int *)(*(int *)(param_1 + 0x8d8c) + param_3 * 4) + param_2 * 0x18);
      for (iVar2 = param_2; iVar2 <= param_4; iVar2 = iVar2 + 1) {
        *psVar1 = (short)(param_3 + iVar2) * *(short *)(param_1 + 0x8d9c);
        psVar1[1] = ((short)param_3 - (short)iVar2) * *(short *)(param_1 + 0x8d9a) -
                    (ushort)(*(byte *)((int)psVar1 + 5) >> 5) * *(short *)(param_1 + 0x8d9e);
        switch((char)psVar1[2]) {
        case '\x02':
        case '\x06':
        case '\b':
        case '\n':
        case '\x0e':
        case '\x0f':
        case '\x10':
          psVar1[1] = psVar1[1] - *(short *)(param_1 + 0x8d9e);
        }
        psVar1 = psVar1 + 0xc;
      }
      param_3 = param_3 + 1;
    } while (param_3 <= param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00455eda
// Address: 00455eda
// XREFS: None
void __fastcall
FUN_00455eda(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            uint param_6)
{
  uint uVar1;
  undefined4 in_EAX;
  int iVar2;
  char cVar4;
  short sVar3;
  int unaff_EBX;
  int *piVar5;
  short sVar6;
  undefined4 *unaff_EDI;
  
  uVar1 = param_6;
  *unaff_EDI = in_EAX;
  cVar4 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_EBX + -0x54ffbaa2) = *(char *)(unaff_EBX + -0x54ffbaa2) + cVar4;
  *(char *)(unaff_EBX + -0x54ffbaa2) = *(char *)(unaff_EBX + -0x54ffbaa2) + cVar4;
  *(char *)(param_4 + 0x455e) = *(char *)(param_4 + 0x455e) + (char)((uint)param_2 >> 8);
  rge_write(param_6,(void *)(param_1 + 8),4);
  piVar5 = (int *)(param_1 + 0xc);
  rge_write(uVar1,piVar5,4);
  iVar2 = *piVar5;
  sVar3 = 0;
  if (0 < iVar2) {
    do {
      sVar6 = 0;
      if (0 < iVar2) {
        iVar2 = 0;
        do {
          param_6 = CONCAT31(param_6._1_3_,
                             *(undefined1 *)
                              (*(int *)(*(int *)(param_1 + 0x8d8c) + sVar3 * 4) + 5 + iVar2 * 0x18))
                    & 0xffffff1f;
          rge_write(uVar1,&param_6,1);
          rge_write(uVar1,&stack0x00000002,1);
          rge_write(uVar1,&stack0x00000003,1);
          sVar6 = sVar6 + 1;
          iVar2 = (int)sVar6;
        } while (iVar2 < *piVar5);
      }
      iVar2 = *piVar5;
      sVar3 = sVar3 + 1;
    } while (sVar3 < iVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00455fea
// Address: 00455fea
// XREFS: None
void __thiscall FUN_00455fea(RGE_Map *param_1,int param_2)
{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  char cStack_12;
  undefined1 uStack_11;
  int iStack_10;
  int iStack_c;
  long lStack_8;
  long lStack_4;
  
  iVar3 = param_2;
  rge_read(param_2,&lStack_4,4);
  rge_read(iVar3,&lStack_8,4);
  RGE_Map::new_map(param_1,lStack_4,lStack_8);
  iVar4 = param_1->map_height;
  iStack_c = 0;
  if (0 < iVar4) {
    do {
      iVar6 = 0;
      iStack_10 = 0;
      if (0 < iVar4) {
        sVar5 = (short)iStack_c;
        do {
          rge_read(iVar3,&param_2,1);
          rge_read(iVar3,&cStack_12,1);
          rge_read(iVar3,&uStack_11,1);
          bVar2 = param_1->map_row_offset[sVar5][iVar6].field_0x5;
          param_1->map_row_offset[sVar5][iVar6].field_0x5 = ((byte)param_2 ^ bVar2) & 0x1f ^ bVar2;
          puVar1 = &param_1->map_row_offset[sVar5][iVar6].field_0x5;
          *puVar1 = cStack_12 << 5 | *puVar1 & 0x1f;
          iStack_10 = iStack_10 + 1;
          iVar6 = (int)(short)iStack_10;
        } while (iVar6 < param_1->map_height);
      }
      iVar4 = param_1->map_height;
      iStack_c = iStack_c + 1;
    } while ((short)iStack_c < iVar4);
  }
  RGE_Map::set_elev(param_1,0,0,(short)param_1->map_width + -1,(short)param_1->map_height + -1,'\0',
                    0,'\0');
  RGE_Map::set_terrain
            (param_1,(RGE_Player *)0x0,(RGE_Game_World *)0x0,0,0,(short)param_1->map_width + -1,
             (short)param_1->map_height + -1,'\0','\0',0);
  return;
}

// --------------------------------------------------

// Function: FUN_0045613e
// Address: 0045613e
// XREFS: None
undefined4 __fastcall FUN_0045613e(int param_1)
{
  return *(undefined4 *)(param_1 + 0x8d8c);
}

// --------------------------------------------------

// Function: FUN_00456147
// Address: 00456147
// XREFS: None
undefined4 __fastcall FUN_00456147(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_00456154
// Address: 00456154
// XREFS: None
undefined4 __fastcall FUN_00456154(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_00456164
// Address: 00456164
// XREFS: None
undefined1 __thiscall
FUN_00456164(int param_1,int param_2,int param_3,int param_4,int param_5,byte param_6)
{
  int iVar1;
  int iVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  byte bVar7;
  ushort uVar8;
  int iVar9;
  undefined1 uStack_23;
  
  sVar3 = *(short *)(param_1 + 8);
  uStack_23 = 0;
  if (0 < param_2) {
    param_2 = param_2 + -1;
  }
  if (0 < param_3) {
    param_3 = param_3 + -1;
  }
  if (param_4 < *(int *)(param_1 + 8) + -1) {
    param_4 = param_4 + 1;
  }
  if (param_5 < *(int *)(param_1 + 0xc) + -1) {
    param_5 = param_5 + 1;
  }
  if (param_3 <= param_5) {
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x8d8c) + param_3 * 4) + param_2 * 0x18;
      for (iVar6 = param_2; iVar6 <= param_4; iVar6 = iVar6 + 1) {
        bVar5 = false;
        bVar4 = false;
        bVar7 = *(byte *)(iVar9 + 5) >> 5;
        uVar8 = (ushort)bVar7;
        if (bVar7 < param_6) {
          uVar8 = uVar8 + 1;
          if ((0 < param_3) && (uVar8 < *(byte *)(iVar9 + 5 + -sVar3 * 0x18) >> 5)) {
            bVar5 = true;
          }
          iVar1 = *(int *)(param_1 + 0xc) + -1;
          if ((param_3 < iVar1) && (uVar8 < *(byte *)(iVar9 + 5 + sVar3 * 0x18) >> 5)) {
            bVar5 = true;
          }
          if ((0 < iVar6) && (uVar8 < *(byte *)(iVar9 + -0x13) >> 5)) {
            bVar5 = true;
          }
          iVar2 = *(int *)(param_1 + 8) + -1;
          if ((iVar6 < iVar2) && (uVar8 < *(byte *)(iVar9 + 0x1d) >> 5)) {
            bVar5 = true;
          }
          bVar4 = bVar5;
          if (0 < param_3) {
            if ((0 < iVar6) && (uVar8 < *(byte *)(iVar9 + 5 + (short)(-1 - sVar3) * 0x18) >> 5)) {
              bVar5 = true;
            }
            bVar4 = bVar5;
            if ((iVar6 < iVar2) && (uVar8 < *(byte *)(iVar9 + 5 + (short)(1 - sVar3) * 0x18) >> 5))
{
              bVar4 = true;
            }
          }
          if (param_3 < iVar1) {
            if ((0 < iVar6) && (uVar8 < *(byte *)(iVar9 + 5 + (short)(sVar3 + -1) * 0x18) >> 5)) {
              bVar4 = true;
            }
            if ((iVar6 < iVar2) && (uVar8 < *(byte *)(iVar9 + 5 + (short)(sVar3 + 1) * 0x18) >> 5))
{
LAB_0045647c:
              bVar4 = true;
            }
          }
        }
        else if (param_6 < bVar7) {
          uVar8 = uVar8 - 1;
          bVar4 = bVar5;
          if ((0 < param_3) &&
             ((short)(ushort)(*(byte *)(iVar9 + 5 + -sVar3 * 0x18) >> 5) < (short)uVar8)) {
            bVar4 = true;
          }
          iVar1 = *(int *)(param_1 + 0xc) + -1;
          if ((param_3 < iVar1) &&
             ((short)(ushort)(*(byte *)(iVar9 + 5 + sVar3 * 0x18) >> 5) < (short)uVar8)) {
            bVar4 = true;
          }
          if ((0 < iVar6) && ((short)(ushort)(*(byte *)(iVar9 + -0x13) >> 5) < (short)uVar8)) {
            bVar4 = true;
          }
          iVar2 = *(int *)(param_1 + 8) + -1;
          if ((iVar6 < iVar2) && ((short)(ushort)(*(byte *)(iVar9 + 0x1d) >> 5) < (short)uVar8)) {
            bVar4 = true;
          }
          if (0 < param_3) {
            if ((0 < iVar6) &&
               ((short)(ushort)(*(byte *)(iVar9 + 5 + (short)(-1 - sVar3) * 0x18) >> 5) <
                (short)uVar8)) {
              bVar4 = true;
            }
            if ((iVar6 < iVar2) &&
               ((short)(ushort)(*(byte *)(iVar9 + 5 + (short)(1 - sVar3) * 0x18) >> 5) <
                (short)uVar8)) {
              bVar4 = true;
            }
          }
          if (param_3 < iVar1) {
            if ((0 < iVar6) &&
               ((short)(ushort)(*(byte *)(iVar9 + 5 + (short)(sVar3 + -1) * 0x18) >> 5) <
                (short)uVar8)) {
              bVar4 = true;
            }
            if ((iVar6 < iVar2) &&
               ((short)(ushort)(*(byte *)(iVar9 + 5 + (short)(sVar3 + 1) * 0x18) >> 5) <
                (short)uVar8)) goto LAB_0045647c;
          }
        }
        if (bVar4) {
          uStack_23 = 1;
          *(byte *)(iVar9 + 5) = (char)uVar8 << 5 | *(byte *)(iVar9 + 5) & 0x1f;
        }
        iVar9 = iVar9 + 0x18;
      }
      param_3 = param_3 + 1;
    } while (param_3 <= param_5);
  }
  return uStack_23;
}

// --------------------------------------------------

// Function: FUN_004568b9
// Address: 004568b9
// XREFS: None
void __thiscall
FUN_004568b9(RGE_Map *param_1,int param_2,int param_3,int param_4,int param_5,byte param_6)
{
  int iVar1;
  int iVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  uchar uVar14;
  int iVar15;
  int iVar16;
  byte bVar17;
  RGE_Tile *pRVar18;
  short sStack_1c;
  short sStack_18;
  short sStack_14;
  short sStack_10;
  short sStack_8;
  
  sVar3 = (short)param_1->map_width;
  sStack_1c = -1 - sVar3;
  sStack_18 = -sVar3;
  sStack_14 = 1 - sVar3;
  sStack_10 = sVar3 + 1;
  sStack_8 = sVar3 + -1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1->map_width <= param_4) {
    param_4 = param_1->map_width + -1;
  }
  if (param_1->map_height <= param_5) {
    param_5 = param_1->map_height + -1;
  }
  do {
    param_2 = param_2 + -2;
    param_3 = param_3 + -2;
    param_4 = param_4 + 2;
    param_5 = param_5 + 2;
    bVar6 = false;
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (param_1->map_width <= param_4) {
      param_4 = param_1->map_width + -1;
    }
    if (param_1->map_height <= param_5) {
      param_5 = param_1->map_height + -1;
    }
    RGE_Map::preclean_elevation(param_1,param_2,param_3,param_4,param_5,param_6);
    for (iVar16 = param_3; iVar16 <= param_5; iVar16 = iVar16 + 1) {
      pRVar18 = param_1->map_row_offset[iVar16] + param_2;
      for (iVar15 = param_2; iVar15 <= param_4; iVar15 = iVar15 + 1) {
        bVar4 = false;
        bVar17 = (byte)pRVar18->field_0x5 >> 5;
        bVar8 = false;
        bVar7 = false;
        bVar9 = false;
        bVar13 = false;
        bVar12 = false;
        bVar10 = false;
        bVar11 = false;
        if ((0 < iVar16) && (bVar17 < (byte)pRVar18[sStack_18].field_0x5 >> 5)) {
          bVar8 = true;
        }
        iVar1 = param_1->map_height + -1;
        if ((iVar16 < iVar1) && (bVar17 < (byte)pRVar18[sVar3].field_0x5 >> 5)) {
          bVar12 = true;
        }
        if ((0 < iVar15) && (bVar17 < (byte)pRVar18[-1].field_0x5 >> 5)) {
          bVar11 = true;
        }
        iVar2 = param_1->map_width + -1;
        if ((iVar15 < iVar2) && (bVar17 < (byte)pRVar18[1].field_0x5 >> 5)) {
          bVar9 = true;
        }
        if (0 < iVar16) {
          if ((0 < iVar15) && (bVar17 < (byte)pRVar18[sStack_1c].field_0x5 >> 5)) {
            bVar4 = true;
          }
          if ((iVar15 < iVar2) && (bVar17 < (byte)pRVar18[sStack_14].field_0x5 >> 5)) {
            bVar7 = true;
          }
        }
        if (iVar16 < iVar1) {
          bVar10 = false;
          if ((0 < iVar15) && (bVar17 < (byte)pRVar18[sStack_8].field_0x5 >> 5)) {
            bVar10 = true;
          }
          if ((iVar15 < iVar2) && (bVar17 < (byte)pRVar18[sStack_10].field_0x5 >> 5)) {
            bVar13 = true;
          }
        }
        bVar5 = false;
        if (bVar4) {
          if (((((bVar7) && (!bVar8)) || ((bVar9 && (!bVar7)))) || ((bVar10 && (!bVar11)))) ||
             ((bVar12 && (!bVar10)))) {
            bVar5 = true;
          }
          else if (((bVar13) && (!bVar12)) && (!bVar9)) {
            bVar5 = true;
          }
        }
        if (((bVar7) && (!bVar5)) &&
           (((((bVar13 && (!bVar9)) || ((bVar12 && (!bVar13)))) || ((bVar4 && (!bVar8)))) ||
            (((bVar11 && (!bVar4)) || ((bVar10 && ((!bVar11 && (!bVar12)))))))))) {
          bVar5 = true;
        }
        if (((bVar13) && (!bVar5)) &&
           ((((bVar10 && (!bVar12)) || (((bVar11 && (!bVar10)) || ((bVar7 && (!bVar9)))))) ||
            (((bVar8 && (!bVar7)) || ((bVar4 && ((!bVar8 && (!bVar11)))))))))) {
          bVar5 = true;
        }
        if (bVar10) {
          if (!bVar5) {
            if ((((bVar4) && (!bVar11)) || ((bVar8 && (!bVar4)))) ||
               ((((bVar13 && (!bVar12)) || ((bVar9 && (!bVar13)))) ||
                (((bVar7 && (!bVar9)) && (!bVar8)))))) {
              bVar5 = true;
            }
            goto LAB_00456cd0;
          }
LAB_00456cd8:
          if (bVar17 < param_6) {
            pRVar18->field_0x5 = (bVar17 + 1) * ' ' ^ pRVar18->field_0x5 & 0x1f;
          }
          else {
            if (bVar4) {
              pRVar18[sStack_1c].field_0x5 = bVar17 << 5 | pRVar18[sStack_1c].field_0x5 & 0x1f;
            }
            if (bVar8) {
              pRVar18[sStack_18].field_0x5 = bVar17 << 5 | pRVar18[sStack_18].field_0x5 & 0x1f;
            }
            if (bVar7) {
              pRVar18[sStack_14].field_0x5 = bVar17 << 5 | pRVar18[sStack_14].field_0x5 & 0x1f;
            }
            if (bVar9) {
              pRVar18[1].field_0x5 = bVar17 << 5 | pRVar18[1].field_0x5 & 0x1f;
            }
            if (bVar13) {
              pRVar18[sStack_10].field_0x5 = bVar17 << 5 | pRVar18[sStack_10].field_0x5 & 0x1f;
            }
            if (bVar12) {
              pRVar18[sVar3].field_0x5 = bVar17 << 5 | pRVar18[sVar3].field_0x5 & 0x1f;
            }
            if (bVar10) {
              pRVar18[sStack_8].field_0x5 = bVar17 << 5 | pRVar18[sStack_8].field_0x5 & 0x1f;
            }
            if (bVar11) {
              pRVar18[-1].field_0x5 = bVar17 << 5 | pRVar18[-1].field_0x5 & 0x1f;
            }
          }
          bVar6 = true;
        }
        else {
LAB_00456cd0:
          if (bVar5) goto LAB_00456cd8;
        }
        pRVar18 = pRVar18 + 1;
      }
    }
    uVar14 = RGE_Map::postclean_elevation(param_1,param_2,param_3,param_4,param_5,param_6);
    if (uVar14 != '\0') {
      bVar6 = true;
    }
    if (!bVar6) {
      RGE_Map::set_elev(param_1,(short)param_2,(short)param_3,(short)param_4,(short)param_5,'\0',0,
                        '\0');
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00456e86
// Address: 00456e86
// XREFS: None
void __thiscall
FUN_00456e86(RGE_Map *param_1,int param_2,int param_3,int param_4,int param_5,byte param_6)
{
  short sVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  RGE_Tile *pRVar17;
  int iStack_20;
  short sStack_1c;
  short sStack_14;
  short sStack_10;
  short sStack_c;
  short sStack_8;
  
  sVar1 = (short)param_1->map_width;
  sStack_14 = -1 - sVar1;
  sStack_1c = -sVar1;
  sStack_10 = 1 - sVar1;
  sStack_8 = sVar1 + 1;
  sStack_c = sVar1 + -1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1->map_width <= param_4) {
    param_4 = param_1->map_width + -1;
  }
  iVar14 = param_5;
  iVar15 = param_2;
  if (param_1->map_height <= param_5) {
    iVar14 = param_1->map_height + -1;
    param_5 = iVar14;
  }
  do {
    bVar11 = false;
    if (0 < iVar15) {
      iVar15 = iVar15 + -1;
      param_2 = iVar15;
    }
    if (0 < param_3) {
      param_3 = param_3 + -1;
    }
    if (param_4 < param_1->map_width + -1) {
      param_4 = param_4 + 1;
    }
    if (iVar14 < param_1->map_height + -1) {
      iVar14 = iVar14 + 1;
      param_5 = iVar14;
    }
    iStack_20 = 0;
    do {
      iVar13 = param_3;
      iVar12 = iVar15;
      iVar16 = iVar15;
      if (param_3 <= iVar14) {
        do {
          pRVar17 = param_1->map_row_offset[iVar13] + iVar15;
          iVar16 = iVar12;
          for (; iVar12 <= param_4; iVar12 = iVar12 + 1) {
            if ((pRVar17->field_0x5 & 0x1f) != param_6) {
              bVar4 = false;
              bVar5 = false;
              bVar3 = false;
              bVar6 = false;
              bVar2 = false;
              bVar9 = false;
              bVar8 = false;
              bVar10 = false;
              bVar7 = false;
              if ((0 < iVar13) && ((pRVar17[sStack_1c].field_0x5 & 0x1f) == param_6)) {
                bVar6 = true;
              }
              iVar14 = param_1->map_height + -1;
              if ((iVar13 < iVar14) && ((pRVar17[sVar1].field_0x5 & 0x1f) == param_6)) {
                bVar7 = true;
              }
              if ((0 < iVar12) && ((pRVar17[-1].field_0x5 & 0x1f) == param_6)) {
                bVar4 = true;
              }
              iVar16 = param_1->map_width + -1;
              if ((iVar12 < iVar16) && ((pRVar17[1].field_0x5 & 0x1f) == param_6)) {
                bVar8 = true;
              }
              if (iStack_20 == 1) {
                bVar9 = bVar2;
                if (0 < iVar13) {
                  if ((0 < iVar12) && ((pRVar17[sStack_14].field_0x5 & 0x1f) == param_6)) {
                    bVar3 = true;
                  }
                  if ((iVar12 < iVar16) && ((pRVar17[sStack_10].field_0x5 & 0x1f) == param_6)) {
                    bVar9 = true;
                  }
                }
                if (iVar13 < iVar14) {
                  bVar5 = false;
                  if ((0 < iVar12) && ((pRVar17[sStack_c].field_0x5 & 0x1f) == param_6)) {
                    bVar5 = true;
                  }
                  if ((iVar12 < iVar16) && ((pRVar17[sStack_8].field_0x5 & 0x1f) == param_6)) {
                    bVar10 = true;
                  }
                }
              }
              bVar2 = false;
              if (iStack_20 == 0) {
                if (((bVar6) && (bVar7)) || ((bVar8 && (bVar4)))) {
LAB_00457268:
                  bVar2 = true;
                }
LAB_0045726a:
                if (!bVar2) goto LAB_00457292;
              }
              else {
                if (bVar3) {
                  if (((((bVar9) && (!bVar6)) || ((bVar8 && (!bVar9)))) || ((bVar5 && (!bVar4)))) ||
                     ((bVar7 && (!bVar5)))) {
                    bVar2 = true;
                  }
                  else if (((bVar10) && (!bVar7)) && (!bVar8)) {
                    bVar2 = true;
                  }
                }
                if (((bVar9) && (!bVar2)) &&
                   (((((bVar3 && (!bVar6)) || ((bVar4 && (!bVar3)))) || ((bVar10 && (!bVar8)))) ||
                    (((bVar7 && (!bVar10)) || ((bVar5 && ((!bVar4 && (!bVar7)))))))))) {
                  bVar2 = true;
                }
                if (((bVar10) && (!bVar2)) &&
                   ((((bVar9 && (!bVar8)) || (((bVar6 && (!bVar9)) || ((bVar5 && (!bVar7)))))) ||
                    (((bVar4 && (!bVar5)) || ((bVar3 && ((!bVar4 && (!bVar6)))))))))) {
                  bVar2 = true;
                }
                if (!bVar5) goto LAB_0045726a;
                if (!bVar2) {
                  if ((((bVar3) && (!bVar4)) || ((bVar6 && (!bVar3)))) ||
                     ((((bVar10 && (!bVar7)) || ((bVar8 && (!bVar10)))) ||
                      (((bVar9 && (!bVar8)) && (!bVar6)))))) goto LAB_00457268;
                  goto LAB_0045726a;
                }
              }
              RGE_Map::set_terrain
                        (param_1,param_1->game_world,(short)iVar12,(short)iVar13,param_6,0,0);
              bVar11 = true;
            }
LAB_00457292:
            pRVar17 = pRVar17 + 1;
            iVar14 = param_5;
            iVar16 = param_2;
          }
          iVar13 = iVar13 + 1;
          iVar12 = iVar16;
        } while (iVar13 <= iVar14);
      }
      iStack_20 = iStack_20 + 1;
      iVar15 = iVar16;
    } while (iStack_20 < 2);
    if (!bVar11) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004572f7
// Address: 004572f7
// XREFS: None
void FUN_004572f7(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00457303
// Address: 00457303
// XREFS: None
undefined4 FUN_00457303(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_00457316
// Address: 00457316
// XREFS: None
undefined4 __thiscall
FUN_00457316(RGE_Map *param_1,int param_2,int param_3,int param_4,uchar param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_4 + param_2;
  param_2 = param_2 - param_4;
  iVar3 = param_3 - param_4;
  param_4 = param_4 + param_3;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1->map_width <= iVar2) {
    iVar2 = param_1->map_width + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (param_1->map_height <= param_4) {
    param_4 = param_1->map_height + -1;
  }
  for (; iVar1 = param_2, iVar3 <= param_4; iVar3 = iVar3 + 1) {
    for (; iVar1 <= iVar2; iVar1 = iVar1 + 1) {
      RGE_Map::set_terrain(param_1,param_1->game_world,(short)iVar1,(short)iVar3,param_5,0,0);
    }
  }
  return CONCAT31((int3)((uint)param_4 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_004573b1
// Address: 004573b1
// XREFS: None
undefined4 __thiscall
FUN_004573b1(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)
{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iStack_3c;
  double dVar3;
  double dStack_30;
  undefined4 uStack_2c;
  
  dVar3 = (double)CONCAT44(unaff_ESI,unaff_EDI);
  param_6 = param_6 >> 1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1[2] <= param_4) {
    param_4 = param_1[2] + -1;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1[3] <= param_5) {
    param_5 = param_1[3] + -1;
  }
  uVar2 = __ftol();
  dStack_30 = (double)CONCAT44(uVar2,unaff_EBX);
  pcVar1 = *(code **)(*param_1 + 0xc);
  (*pcVar1)(param_2,param_3,param_6);
  if (0 < param_7) {
    iStack_3c = param_7;
    do {
      dVar3 = dVar3 + (double)param_2;
      dStack_30 = dStack_30 + (double)param_3;
      uVar2 = __ftol(param_6,param_7);
      uVar2 = __ftol(uVar2);
      (*pcVar1)(uVar2);
      iStack_3c = iStack_3c + -1;
    } while (iStack_3c != 0);
  }
  if (((double)param_4 == dVar3) && ((double)param_5 == dStack_30)) {
    return 1;
  }
  (*pcVar1)(param_4,param_5,param_6,param_7);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00457504
// Address: 00457504
// XREFS: None
undefined4 __thiscall FUN_00457504(int param_1,int param_2,int param_3,int param_4,char param_5)
{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = param_4 + param_2;
  param_2 = param_2 - param_4;
  iVar3 = param_3 - param_4;
  param_4 = param_4 + param_3;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (*(int *)(param_1 + 8) <= iVar5) {
    iVar5 = *(int *)(param_1 + 8) + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (*(int *)(param_1 + 0xc) <= param_4) {
    param_4 = *(int *)(param_1 + 0xc) + -1;
  }
  for (; iVar3 <= param_4; iVar3 = iVar3 + 1) {
    if (param_2 <= iVar5) {
      iVar4 = param_2 * 0x18;
      iVar6 = (iVar5 - param_2) + 1;
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x8d8c) + iVar3 * 4);
        pbVar1 = (byte *)(iVar2 + 5 + iVar4);
        iVar2 = iVar2 + iVar4;
        iVar4 = iVar4 + 0x18;
        iVar6 = iVar6 + -1;
        *(byte *)(iVar2 + 5) = *pbVar1 & 0x1f | param_5 << 5;
      } while (iVar6 != 0);
    }
  }
  return CONCAT31((int3)((uint)param_4 >> 8),1);
}

// --------------------------------------------------

// Function: FUN_004575bb
// Address: 004575bb
// XREFS: None
undefined4 __thiscall
FUN_004575bb(RGE_Map *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)
{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iStack_3c;
  double dVar5;
  double dStack_30;
  undefined4 uStack_2c;
  
  dVar5 = (double)CONCAT44(unaff_ESI,unaff_EDI);
  param_6 = param_6 >> 1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1->map_width <= param_4) {
    param_4 = param_1->map_width + -1;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1->map_height <= param_5) {
    param_5 = param_1->map_height + -1;
  }
  uVar2 = __ftol();
  dStack_30 = (double)CONCAT44(uVar2,unaff_EBX);
  pcVar1 = *(code **)(param_1->_padding_ + 0x14);
  (*pcVar1)(param_2,param_3,param_6);
  if (0 < param_7) {
    iStack_3c = param_7;
    do {
      dVar5 = dVar5 + (double)param_2;
      dStack_30 = dStack_30 + (double)param_3;
      uVar2 = __ftol(param_6,param_7);
      uVar2 = __ftol(uVar2);
      (*pcVar1)(uVar2);
      iStack_3c = iStack_3c + -1;
    } while (iStack_3c != 0);
  }
  if (((double)param_4 != dVar5) || ((double)param_5 != dStack_30)) {
    (*pcVar1)(param_4,param_5,param_6,param_7);
  }
  if (param_2 < param_4) {
    lVar4 = param_2 - param_6;
  }
  else {
    lVar4 = param_4 - param_6;
    param_4 = param_2;
  }
  if (param_3 < param_5) {
    lVar3 = param_3 - param_6;
  }
  else {
    lVar3 = param_5 - param_6;
    param_5 = param_3;
  }
  RGE_Map::clean_elevation(param_1,lVar4,lVar3,param_4 + param_6,param_5 + param_6,(uchar)param_7);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045774b
// Address: 0045774b
// XREFS: None
undefined1 FUN_0045774b(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00457755
// Address: 00457755
// XREFS: None
undefined4 __thiscall
FUN_00457755(int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7)
{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iStack_3c;
  double dVar3;
  double dStack_30;
  undefined4 uStack_2c;
  
  dVar3 = (double)CONCAT44(unaff_ESI,unaff_EDI);
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1[2] <= param_4) {
    param_4 = param_1[2] + -1;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1[3] <= param_5) {
    param_5 = param_1[3] + -1;
  }
  uVar2 = __ftol();
  dStack_30 = (double)CONCAT44(uVar2,unaff_EBX);
  pcVar1 = *(code **)(*param_1 + 0x1c);
  (*pcVar1)(param_2,param_3,param_6);
  if (0 < param_7) {
    iStack_3c = param_7;
    do {
      dVar3 = dVar3 + (double)param_2;
      dStack_30 = dStack_30 + (double)param_3;
      uVar2 = __ftol(param_6,param_7);
      uVar2 = __ftol(uVar2);
      (*pcVar1)(uVar2);
      iStack_3c = iStack_3c + -1;
    } while (iStack_3c != 0);
  }
  if (((double)param_4 == dVar3) && ((double)param_5 == dStack_30)) {
    return 1;
  }
  (*pcVar1)(param_4,param_5,param_6,param_7);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045789c
// Address: 0045789c
// XREFS: None
void FUN_0045789c(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_004578a3
// Address: 004578a3
// XREFS: None
// [HELPER] s_After_Random_Map_Generation_rand: "After Random Map Generation random number is %d"
// [HELPER] s_C__msdev_work_age1_x1_map_cpp: "C:\msdev\work\age1_x1\map.cpp"
// [HELPER] s_Random_Map_Seed____d: "Random Map Seed = %d"
void __thiscall
FUN_004578a3(RGE_Map *param_1,RGE_Game_World *param_2,long param_3,long param_4,undefined4 param_5,
            undefined4 param_6)
{
  uchar uVar1;
  RGE_Base_Game *this;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1->game_world->game_state;
  param_1->game_world->game_state = '\x03';
  uVar2 = rge_base_game->random_map_seed;
  if (uVar2 == 0xffffffff) {
    uVar2 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x5ce);
  }
  this = rge_base_game;
  rge_base_game->save_random_map_seed = uVar2;
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s_Random_Map_Seed____d,uVar2);
  debug_srand(s_C__msdev_work_age1_x1_map_cpp,0x5da,uVar2);
  RGE_Map::clear_map(param_1,(RGE_Player *)0x0,param_2,'\0',param_3,param_4);
  debug_srand(s_C__msdev_work_age1_x1_map_cpp,0x5dd,uVar2);
  (**(code **)(param_1->random_map->_padding_ + 0x14))(param_1,param_2,param_5,param_6,1);
  debug_srand(s_C__msdev_work_age1_x1_map_cpp,0x5e0,uVar2);
  (**(code **)param_1->random_map->_padding_)();
  (**(code **)(param_1->random_map->_padding_ + 0x18))();
  iVar3 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x5e5);
  TDebuggingLog::Log(L,(char *)L,s_After_Random_Map_Generation_rand,iVar3);
  param_1->game_world->game_state = uVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_004579ba
// Address: 004579ba
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004579ba(RGE_Map *param_1,int param_2)
{
  int iVar1;
  RGE_Zone_Map_List *pRVar2;
  int iVar3;
  int iVar4;
  RGE_Tile *pRVar5;
  undefined4 *unaff_FS_OFFSET;
  int iStack_1c;
  int iStack_18;
  long lStack_14;
  long lStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055db0b;
  *unaff_FS_OFFSET = &uStack_c;
  rge_read(param_2,&lStack_10,4);
  rge_read(iVar1,&lStack_14,4);
  RGE_Map::new_map(param_1,lStack_10,lStack_14);
  pRVar2 = param_1->map_zones;
  if (pRVar2 != (RGE_Zone_Map_List *)0x0) {
    RGE_Zone_Map_List::~RGE_Zone_Map_List(pRVar2);
    operator_delete(pRVar2);
  }
  pRVar2 = (RGE_Zone_Map_List *)operator_new(0xc);
  uStack_4 = 0;
  if (pRVar2 == (RGE_Zone_Map_List *)0x0) {
    pRVar2 = (RGE_Zone_Map_List *)0x0;
  }
  else {
    pRVar2 = (RGE_Zone_Map_List *)RGE_Zone_Map_List::RGE_Zone_Map_List(pRVar2,iVar1,param_1);
  }
  uStack_4 = 0xffffffff;
  param_1->map_zones = pRVar2;
  rge_read(iVar1,&param_1->map_visible_flag,1);
  rge_read(iVar1,&param_1->fog_flag,1);
  if (save_game_version < _DAT_005706a8) {
    rge_read(iVar1,param_1->map,param_1->map_width * param_1->map_height * 0x18);
    iStack_18 = 0;
    if (0 < param_1->map_height) {
      do {
        iVar4 = 0;
        if (0 < param_1->map_width) {
          iVar3 = 0;
          do {
            iVar4 = iVar4 + 1;
            *(undefined4 *)((int)&(param_1->map_row_offset[iStack_18]->objects).list + iVar3) = 0;
            iVar3 = iVar3 + 0x18;
          } while (iVar4 < param_1->map_width);
        }
        iStack_18 = iStack_18 + 1;
      } while (iStack_18 < param_1->map_height);
    }
  }
  else {
    iStack_18 = 0;
    if (0 < param_1->map_height) {
      do {
        iStack_1c = 0;
        pRVar5 = param_1->map_row_offset[iStack_18];
        if (0 < param_1->map_width) {
          do {
            rge_read(iVar1,pRVar5,2);
            rge_read(iVar1,&pRVar5->screen_ypos,2);
            rge_read(iVar1,&pRVar5->tile_type,1);
            rge_read(iVar1,&param_2,1);
            pRVar5->field_0x5 = ((byte)param_2 ^ pRVar5->field_0x5) & 0x1f ^ pRVar5->field_0x5;
            rge_read(iVar1,&param_2,1);
            pRVar5->field_0x5 = (byte)param_2 << 5 | pRVar5->field_0x5 & 0x1f;
            rge_read(iVar1,&param_2,1);
            pRVar5->field_0x6 = ((byte)param_2 ^ pRVar5->field_0x6) & 0xf ^ pRVar5->field_0x6;
            rge_read(iVar1,&param_2,1);
            pRVar5->last_drawn_as = '\0';
            pRVar5->last_drawn_shape = 0xff;
            pRVar5->field_0x6 = (byte)param_2 << 4 | pRVar5->field_0x6 & 0xf;
            (pRVar5->objects).list = (RGE_Object_Node *)0x0;
            (pRVar5->objects).number_of_objects = 0;
            pRVar5->draw_as = '\0';
            pRVar5->draw_attribute = '\0';
            pRVar5->last_drawn_shape2 = 0xff;
            pRVar5 = pRVar5 + 1;
            iStack_1c = iStack_1c + 1;
          } while (iStack_1c < param_1->map_width);
        }
        iStack_18 = iStack_18 + 1;
      } while (iStack_18 < param_1->map_height);
    }
  }
  RGE_Unified_Visible_Map::load(param_1->unified_vis_map,iVar1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00457c43
// Address: 00457c43
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00457c43(int param_1,uint param_2)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int iStack_c;
  
  iVar3 = param_2;
  piVar1 = (int *)(param_1 + 8);
  rge_write(param_2,piVar1,4);
  piVar2 = (int *)(param_1 + 0xc);
  rge_write(iVar3,piVar2,4);
  RGE_Zone_Map_List::save(*(RGE_Zone_Map_List **)(param_1 + 0x8dc4),iVar3);
  rge_write(iVar3,(void *)(param_1 + 0x8db8),1);
  rge_write(iVar3,(void *)(param_1 + 0x8db9),1);
  if (save_game_version < _DAT_005706a8) {
    rge_write(iVar3,*(void **)(param_1 + 4),*piVar2 * *piVar1 * 0x18);
  }
  else {
    iStack_c = 0;
    if (0 < *piVar2) {
      do {
        iVar4 = 0;
        pvVar5 = *(void **)(*(int *)(param_1 + 0x8d8c) + iStack_c * 4);
        if (0 < *piVar1) {
          do {
            rge_write(iVar3,pvVar5,2);
            rge_write(iVar3,(void *)((int)pvVar5 + 2),2);
            rge_write(iVar3,(void *)((int)pvVar5 + 4),1);
            param_2 = CONCAT31(param_2._1_3_,*(undefined1 *)((int)pvVar5 + 5)) & 0xffffff1f;
            rge_write(iVar3,&param_2,1);
            param_2._0_1_ = *(byte *)((int)pvVar5 + 5) >> 5;
            rge_write(iVar3,&param_2,1);
            param_2._0_1_ = *(byte *)((int)pvVar5 + 6) & 0xf;
            rge_write(iVar3,&param_2,1);
            param_2 = CONCAT31(param_2._1_3_,*(byte *)((int)pvVar5 + 6) >> 4);
            rge_write(iVar3,&param_2,1);
            pvVar5 = (void *)((int)pvVar5 + 0x18);
            iVar4 = iVar4 + 1;
          } while (iVar4 < *piVar1);
        }
        iStack_c = iStack_c + 1;
      } while (iStack_c < *piVar2);
    }
  }
  RGE_Unified_Visible_Map::save(*(RGE_Unified_Visible_Map **)(param_1 + 0x8dc8),iVar3);
  return;
}

// --------------------------------------------------

// Function: FUN_00457de3
// Address: 00457de3
// XREFS: None
void __thiscall FUN_00457de3(undefined4 *param_1,int param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)calloc(1,0x8dd0);
  puVar4 = param_1;
  puVar6 = puVar1;
  for (iVar3 = 0x2374; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  piVar2 = param_1 + 0x2c;
  iVar3 = (int)puVar1 - (int)param_1;
  iVar5 = 0x20;
  do {
    if ((char)piVar2[-9] != '\0') {
      if (*piVar2 == 0) {
        *(undefined4 *)(iVar3 + (int)piVar2) = 0xffffffff;
      }
      else {
        *(int *)(iVar3 + (int)piVar2) = (int)*(short *)(*piVar2 + 0xc);
      }
    }
    piVar2 = piVar2 + 0x66;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  piVar2 = param_1 + 0xcec;
  iVar5 = 0x10;
  do {
    if ((*piVar2 == 0) || ((char)piVar2[-9] == '\0')) {
      *(undefined4 *)((int)piVar2 + iVar3) = 0xffffffff;
    }
    else {
      *(int *)((int)piVar2 + iVar3) = (int)*(short *)(*piVar2 + 0xc);
    }
    piVar2 = piVar2 + 0x168;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  rge_write(param_2,puVar1,0x8dd0);
  RGE_RMM_Database_Controller::save((RGE_RMM_Database_Controller *)param_1[0x236f],param_2);
  free(puVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00457ea4
// Address: 00457ea4
// XREFS: None
// [HELPER] s__shp: ".shp"
void __thiscall FUN_00457ea4(int param_1,int param_2)
{
  TShape *pTVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  undefined4 *unaff_FS_OFFSET;
  char *pcStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055db2b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pcStack_10 = (char *)0x0;
  plVar4 = (long *)(param_1 + 0x3210);
  iVar3 = 0x20;
  do {
    if ((char)plVar4[-7] != '\0') {
      addstring(&pcStack_10,(char *)((int)plVar4 + -0xd),s__shp);
      pTVar1 = (TShape *)operator_new(0x20);
      uStack_4 = 0;
      if (pTVar1 == (TShape *)0x0) {
        pTVar1 = (TShape *)0x0;
      }
      else {
        pTVar1 = (TShape *)TShape::TShape(pTVar1,pcStack_10,*plVar4);
      }
      uStack_4 = 0xffffffff;
      plVar4[1] = (long)pTVar1;
      iVar2 = TShape::is_loaded(pTVar1);
      if (iVar2 == 0) {
        *(undefined1 *)(plVar4 + -7) = 0;
      }
      if (plVar4[2] < 0) {
        plVar4[2] = 0;
      }
      else {
        plVar4[2] = *(long *)(param_2 + plVar4[2] * 4);
      }
    }
    plVar4 = plVar4 + -0x66;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (pcStack_10 != (char *)0x0) {
    free(pcStack_10);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00457f7d
// Address: 00457f7d
// XREFS: None
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s__hd__s__s__d__hd__hd__hd__hd__hd: "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00457f7d(int param_1,undefined4 param_2,int param_3)
{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  short *psVar10;
  char *pcVar11;
  char *pcVar12;
  short sStack_5c;
  undefined2 uStack_5a;
  short sStack_58;
  undefined1 auStack_56 [2];
  undefined1 auStack_54 [2];
  undefined1 auStack_52 [2];
  undefined1 auStack_50 [2];
  undefined1 auStack_4e [2];
  undefined1 auStack_4c [2];
  undefined1 auStack_4a [2];
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined1 auStack_44 [2];
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined1 auStack_3e [2];
  float fStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  char acStack_20 [16];
  char acStack_10 [16];
  
  puVar4 = (undefined1 *)(param_1 + 0x31f4);
  iVar7 = 0x20;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + -0x198;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iStack_24 = param_1;
  iVar7 = fopen(param_2,s_r);
  iStack_38 = iVar7;
  if (iVar7 != 0) {
    fscanf(iVar7,s__hd,(short *)(param_1 + 0x8d90));
    sVar2 = *(short *)(param_1 + 0x8d90) + -1;
    if (-1 < sVar2) {
      iStack_2c = sVar2 + 1;
      do {
        sVar2 = 0;
        iVar5 = fscanf(iVar7,s__hd__s__s__d__hd__hd__hd__hd__hd,&param_2,acStack_20,acStack_10,
                       &uStack_28,auStack_3e,auStack_54,auStack_52,auStack_56,&sStack_58,auStack_44,
                       &uStack_42,&fStack_3c,&uStack_30,&uStack_40,&uStack_48,&uStack_46,auStack_50,
                       auStack_4e,auStack_4c,auStack_4a,&sStack_5c);
        if (((iVar5 != -1) && ((short)param_2 < 0x20)) && (-1 < (short)param_2)) {
          iStack_34 = 0x13;
          puVar4 = (undefined1 *)(param_1 + 0x8c + (short)param_2 * 0x198);
          psVar10 = (short *)(puVar4 + 0x46);
          do {
            fscanf(iStack_38,s__hd__hd,psVar10,psVar10 + 1);
            psVar10[2] = sVar2;
            sVar2 = sVar2 + *psVar10 * psVar10[1];
            psVar10 = psVar10 + 3;
            iStack_34 = iStack_34 + -1;
          } while (iStack_34 != 0);
          sVar2 = 0;
          iStack_34 = 0;
          if (0 < sStack_5c) {
            do {
              fscanf(iStack_38,s__hd__hd,&param_2,&uStack_5a);
              sVar2 = sVar2 + 1;
              *(undefined2 *)(puVar4 + (short)param_2 * 2 + 0xbe) = uStack_5a;
            } while (sVar2 < sStack_5c);
          }
          if (sStack_58 < 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(undefined4 *)(param_3 + sStack_58 * 4);
          }
          *(undefined4 *)(puVar4 + 0x24) = uVar6;
          puVar4[0x2a] = auStack_56[0];
          puVar4[0x29] = auStack_54[0];
          puVar4[0x28] = auStack_52[0];
          puVar4[0x2b] = auStack_50[0];
          puVar4[0x2c] = auStack_4e[0];
          puVar4[0x2e] = auStack_4c[0];
          puVar4[0x2d] = auStack_4a[0];
          convert_us(acStack_20);
          uVar8 = 0xffffffff;
          pcVar11 = acStack_20;
          do {
            pcVar12 = pcVar11;
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            pcVar12 = pcVar11 + 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar12;
          } while (cVar1 != '\0');
          uVar8 = ~uVar8;
          pcVar11 = pcVar12 + -uVar8;
          pcVar12 = puVar4 + 2;
          for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
            pcVar11 = pcVar11 + 4;
            pcVar12 = pcVar12 + 4;
          }
          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *pcVar12 = *pcVar11;
            pcVar11 = pcVar11 + 1;
            pcVar12 = pcVar12 + 1;
          }
          uVar8 = 0xffffffff;
          pcVar11 = acStack_10;
          do {
            pcVar12 = pcVar11;
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            pcVar12 = pcVar11 + 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar12;
          } while (cVar1 != '\0');
          uVar8 = ~uVar8;
          pcVar11 = pcVar12 + -uVar8;
          pcVar12 = puVar4 + 0xf;
          for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
            pcVar11 = pcVar11 + 4;
            pcVar12 = pcVar12 + 4;
          }
          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *pcVar12 = *pcVar11;
            pcVar11 = pcVar11 + 1;
            pcVar12 = pcVar12 + 1;
          }
          *(undefined4 *)(puVar4 + 0x40) = 0;
          *(undefined4 *)(puVar4 + 0x1c) = uStack_28;
          *puVar4 = 1;
          *(undefined2 *)(puVar4 + 0xba) = uStack_48;
          *(undefined2 *)(puVar4 + 0xbc) = uStack_46;
          puVar4[0x2f] = auStack_44[0];
          *(undefined2 *)(puVar4 + 0x30) = uStack_42;
          if (fStack_3c == _DAT_005706ac) {
            uVar3 = 0;
          }
          else {
            uVar3 = __ftol();
          }
          *(undefined2 *)(puVar4 + 0x32) = uVar3;
          *(float *)(puVar4 + 0x34) = fStack_3c;
          *(undefined2 *)(puVar4 + 0x3c) = 0;
          *(undefined4 *)(puVar4 + 0x38) = uStack_30;
          *(undefined2 *)(puVar4 + 0x3e) = 0;
          puVar4[0x44] = 0;
          puVar4[0x45] = 0;
          *(undefined2 *)(puVar4 + 0xb8) = uStack_40;
          param_1 = iStack_24;
          iVar7 = iStack_38;
        }
        iStack_2c = iStack_2c + -1;
      } while (iStack_2c != 0);
    }
  }
  fclose(iVar7);
  return;
}

// --------------------------------------------------

// Function: FUN_0045827a
// Address: 0045827a
// XREFS: None
// [HELPER] s__shp: ".shp"
void __thiscall FUN_0045827a(int param_1,int param_2)
{
  TShape *pTVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  undefined4 *unaff_FS_OFFSET;
  char *pcStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055db4b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pcStack_10 = (char *)0x0;
  plVar4 = (long *)(param_1 + 0x8808);
  iVar3 = 0x10;
  do {
    if ((char)plVar4[-7] != '\0') {
      addstring(&pcStack_10,(char *)((int)plVar4 + -0xd),s__shp);
      pTVar1 = (TShape *)operator_new(0x20);
      uStack_4 = 0;
      if (pTVar1 == (TShape *)0x0) {
        pTVar1 = (TShape *)0x0;
      }
      else {
        pTVar1 = (TShape *)TShape::TShape(pTVar1,pcStack_10,*plVar4);
      }
      uStack_4 = 0xffffffff;
      plVar4[1] = (long)pTVar1;
      iVar2 = TShape::is_loaded(pTVar1);
      if (iVar2 == 0) {
        *(undefined1 *)(plVar4 + -7) = 0;
      }
      if (plVar4[2] < 0) {
        plVar4[2] = 0;
      }
      else {
        plVar4[2] = *(long *)(param_2 + plVar4[2] * 4);
      }
    }
    plVar4 = plVar4 + -0x168;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (pcStack_10 != (char *)0x0) {
    free(pcStack_10);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0045834d
// Address: 0045834d
// XREFS: None
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd: "%hd %hd"
// [HELPER] s__hd__s__s__d__hd__hd__hd__hd__hd: "%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd"
// [HELPER] s_r: "r"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045834d(int param_1,undefined4 param_2,int param_3)
{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  short *psVar11;
  short *psVar12;
  char *pcVar13;
  char *pcVar14;
  short sStack_58;
  undefined1 auStack_56 [2];
  undefined1 auStack_54 [2];
  undefined1 auStack_52 [2];
  undefined1 auStack_50 [2];
  undefined2 uStack_4e;
  undefined1 auStack_4c [2];
  undefined2 uStack_4a;
  undefined2 uStack_48;
  undefined1 auStack_46 [2];
  short *psStack_44;
  float fStack_40;
  int iStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  char acStack_20 [16];
  char acStack_10 [16];
  
  iVar8 = 0x10;
  puVar5 = (undefined1 *)(param_1 + 0x87ec);
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + -0x5a0;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iStack_24 = param_1;
  iVar8 = fopen(param_2,s_r);
  iStack_30 = iVar8;
  if (iVar8 != 0) {
    fscanf(iVar8,s__hd,(short *)(param_1 + 0x8d92));
    sVar3 = *(short *)(param_1 + 0x8d92) + -1;
    if (-1 < sVar3) {
      iStack_2c = sVar3 + 1;
      do {
        sVar3 = 0;
        iVar6 = fscanf(iVar8,s__hd__s__s__d__hd__hd__hd__hd__hd,&param_2,acStack_20,acStack_10,
                       &uStack_28,auStack_46,auStack_54,auStack_52,auStack_56,&sStack_58,auStack_50,
                       &uStack_4e,&fStack_40,&uStack_34,auStack_4c,&uStack_4a,&uStack_48);
        if (((iVar6 != -1) && ((short)param_2 < 0x10)) && (-1 < (short)param_2)) {
          iStack_38 = 0x13;
          puVar5 = (undefined1 *)((short)param_2 * 0x5a0 + 0x338c + param_1);
          psVar11 = (short *)(puVar5 + 0x42);
          do {
            psVar12 = psVar11 + 1;
            iStack_3c = 0xc;
            psStack_44 = psVar11;
            do {
              fscanf(iStack_30,s__hd__hd,psVar11,psVar12);
              sVar2 = *psVar11;
              psVar12[1] = sVar3;
              sVar3 = sVar3 + sVar2 * *psVar12;
              psVar11 = psVar11 + 3;
              psVar12 = psVar12 + 3;
              iStack_3c = iStack_3c + -1;
            } while (iStack_3c != 0);
            psVar11 = psStack_44 + 0x24;
            iStack_38 = iStack_38 + -1;
          } while (iStack_38 != 0);
          if (sStack_58 < 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(undefined4 *)(param_3 + sStack_58 * 4);
          }
          *(undefined4 *)(puVar5 + 0x24) = uVar7;
          puVar5[0x2a] = auStack_56[0];
          puVar5[0x29] = auStack_54[0];
          puVar5[0x28] = auStack_52[0];
          psStack_44 = psVar11;
          convert_us(acStack_20);
          uVar9 = 0xffffffff;
          pcVar13 = acStack_20;
          do {
            pcVar14 = pcVar13;
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            pcVar14 = pcVar13 + 1;
            cVar1 = *pcVar13;
            pcVar13 = pcVar14;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          pcVar13 = pcVar14 + -uVar9;
          pcVar14 = puVar5 + 2;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar14 = *(undefined4 *)pcVar13;
            pcVar13 = pcVar13 + 4;
            pcVar14 = pcVar14 + 4;
          }
          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar14 = *pcVar13;
            pcVar13 = pcVar13 + 1;
            pcVar14 = pcVar14 + 1;
          }
          uVar9 = 0xffffffff;
          pcVar13 = acStack_10;
          do {
            pcVar14 = pcVar13;
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            pcVar14 = pcVar13 + 1;
            cVar1 = *pcVar13;
            pcVar13 = pcVar14;
          } while (cVar1 != '\0');
          uVar9 = ~uVar9;
          pcVar13 = pcVar14 + -uVar9;
          pcVar14 = puVar5 + 0xf;
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar14 = *(undefined4 *)pcVar13;
            pcVar13 = pcVar13 + 4;
            pcVar14 = pcVar14 + 4;
          }
          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar14 = *pcVar13;
            pcVar13 = pcVar13 + 1;
            pcVar14 = pcVar14 + 1;
          }
          *puVar5 = 1;
          *(undefined4 *)(puVar5 + 0x1c) = uStack_28;
          puVar5[0x2b] = auStack_50[0];
          *(undefined2 *)(puVar5 + 0x2c) = uStack_4e;
          if (fStack_40 == _DAT_005706ac) {
            uVar4 = 0;
          }
          else {
            uVar4 = __ftol();
          }
          *(undefined2 *)(puVar5 + 0x2e) = uVar4;
          *(float *)(puVar5 + 0x30) = fStack_40;
          *(undefined4 *)(puVar5 + 0x34) = uStack_34;
          *(undefined2 *)(puVar5 + 0x38) = 0;
          *(undefined2 *)(puVar5 + 0x3a) = 0;
          *(undefined4 *)(puVar5 + 0x3c) = 0;
          puVar5[0x40] = 0;
          puVar5[0x41] = 0;
          puVar5[0x59a] = auStack_4c[0];
          *(undefined2 *)(puVar5 + 0x59c) = uStack_4a;
          *(undefined2 *)(puVar5 + 0x59e) = uStack_48;
          iVar8 = iStack_30;
          param_1 = iStack_24;
        }
        iStack_2c = iStack_2c + -1;
      } while (iStack_2c != 0);
    }
  }
  fclose(iVar8);
  return;
}

// --------------------------------------------------

// Function: FUN_004585f7
// Address: 004585f7
// XREFS: None
// [HELPER] s__hd: "%hd"
// [HELPER] s__hd__hd__hd__hd: "%hd %hd %hd %hd"
// [HELPER] s_r: "r"
void __thiscall FUN_004585f7(int param_1,undefined4 param_2)
{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 auStack_a [2];
  undefined2 uStack_8;
  undefined2 uStack_6;
  undefined4 uStack_4;
  
  iVar3 = fopen(param_2,s_r);
  if (iVar3 != 0) {
    fscanf(iVar3,s__hd,&uStack_4);
    uVar5 = fscanf(iVar3,s__hd__hd__hd__hd,&param_2,&uStack_6,&uStack_8,auStack_a);
    while ((int)uVar5 != -1) {
      iVar4 = (int)(short)param_2;
      if (*(char *)(param_1 + 0x8c + iVar4 * 0x198) != '\0') {
        sVar2 = *(short *)(param_1 + iVar4 * 0x198 + 0x220);
        if (sVar2 < 0x1e) {
          *(undefined2 *)(param_1 + 0x18a + ((int)sVar2 + iVar4 * 0xcc) * 2) = uStack_6;
          *(undefined2 *)(param_1 + 0x1c6 + ((int)sVar2 + (short)param_2 * 0xcc) * 2) = uStack_8;
          *(undefined1 *)(param_1 + sVar2 + 0x202 + (short)param_2 * 0x198) = auStack_a[0];
          psVar1 = (short *)(param_1 + 0x220 + (short)param_2 * 0x198);
          *psVar1 = *psVar1 + 1;
          uStack_4 = CONCAT22((short)((ulonglong)uVar5 >> 0x30),sVar2);
        }
      }
      uVar5 = fscanf(iVar3,s__hd__hd__hd__hd,&param_2,&uStack_6,&uStack_8,auStack_a);
    }
  }
  fclose(iVar3);
  return;
}

// --------------------------------------------------

// Function: FUN_00458755
// Address: 00458755
// XREFS: None
void __thiscall
FUN_00458755(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            int param_7)
{
  int *piVar1;
  undefined4 *puVar2;
  
  if ((((-1 < param_4) && (param_4 < *(int *)(param_1 + 8))) && (-1 < param_5)) &&
     (param_5 < *(int *)(param_1 + 0xc))) {
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x8d8c) + param_5 * 4) + 0x10 + param_4 * 0x18);
    while (piVar1 != (int *)0x0) {
      puVar2 = (undefined4 *)*piVar1;
      piVar1 = (int *)piVar1[1];
      if (((puVar2[3] == param_2) &&
          ((*(short *)(puVar2[2] + 0x10) < param_6 || (param_7 < *(short *)(puVar2[2] + 0x10))))) &&
         (puVar2 != (undefined4 *)0x0)) {
        (**(code **)*puVar2)(1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004587ce
// Address: 004587ce
// XREFS: None
void __thiscall FUN_004587ce(int param_1,int param_2,int param_3)
{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 8))) && (-1 < param_3)) &&
     (param_3 < *(int *)(param_1 + 0xc))) {
    piVar3 = *(int **)(*(int *)(*(int *)(param_1 + 0x8d8c) + param_3 * 4) + 0x10 + param_2 * 0x18);
    while (piVar3 != (int *)0x0) {
      piVar1 = (int *)piVar3[1];
      puVar2 = (undefined4 *)*piVar3;
      piVar3 = piVar1;
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045881a
// Address: 0045881a
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_map_cpp: "C:\msdev\work\age1_x1\map.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0045881a(RGE_Map *param_1,RGE_Player *param_2,undefined4 param_3,short param_4,short param_5,
            short param_6,int param_7,int param_8,int param_9)
{
  uchar uVar1;
  short sVar2;
  RGE_Object_Node *pRVar3;
  RGE_Static_Object *pRVar4;
  RGE_Master_Static_Object *pRVar5;
  bool bVar6;
  byte bVar7;
  char cVar8;
  ushort uVar9;
  short sVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  short sVar14;
  float fStack_10;
  float fStack_c;
  
  fStack_c = 0.0;
  fStack_10 = 0.0;
  bVar7 = RGE_Map::get_terrain(param_1,param_5,param_4);
  uVar9 = (ushort)bVar7;
  sVar14 = param_1->terrain_types[(short)uVar9].num_obj_type;
  if (0 < sVar14) {
    pRVar3 = param_1->map_row_offset[param_4][param_5].objects.list;
    while (pRVar3 != (RGE_Object_Node *)0x0) {
      pRVar4 = pRVar3->node;
      pRVar3 = pRVar3->next;
      sVar2 = pRVar4->master_obj->id;
      if ((pRVar4->owner == param_2) && ((sVar2 < param_8 || (param_9 < sVar2)))) {
        if (param_6 < 0) {
          if (param_7 == 0) {
            (**(code **)(pRVar4->_padding_ + 0x68))();
          }
          else if (pRVar4 != (RGE_Static_Object *)0x0) {
            (**(code **)pRVar4->_padding_)(1);
          }
        }
        else {
          sVar10 = param_1->terrain_types[param_6].num_obj_type;
          if (-1 < sVar10) {
            do {
              if (param_1->terrain_types[param_6].obj_types[sVar10] == sVar2) break;
              sVar10 = sVar10 + -1;
            } while (-1 < sVar10);
            if (-1 < sVar10) {
              if (param_7 == 0) {
                (**(code **)(pRVar4->_padding_ + 0x68))();
              }
              else if (pRVar4 != (RGE_Static_Object *)0x0) {
                (**(code **)pRVar4->_padding_)(1);
              }
            }
          }
        }
      }
    }
    if (0 < sVar14) {
      param_8 = (int)sVar14;
      _param_6 = param_1->terrain_types[(short)uVar9].obj_placement_flag;
      psVar12 = param_1->terrain_types[(short)uVar9].obj_density;
      do {
        if (psVar12[-0x1e] != -1) {
          sVar14 = *psVar12;
          pRVar5 = param_2->master_objects[psVar12[-0x1e]];
          uVar1 = *_param_6;
          if ((pRVar5 != (RGE_Master_Static_Object *)0x0) && (0 < sVar14)) {
            iVar13 = (int)sVar14;
            do {
              if (uVar1 == '\0') {
                iVar11 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x813);
                fStack_c = (float)(int)param_5 - (float)iVar11 * _DAT_005706b4;
                iVar11 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x814);
                fStack_10 = (float)(int)param_4 - (float)iVar11 * _DAT_005706b4;
              }
              else if (uVar1 == '\x01') {
                fStack_c = (float)(int)param_5 - _DAT_005706b0;
                fStack_10 = (float)(int)param_4 - _DAT_005706b0;
              }
              if (sVar14 < 1000) {
                iVar11 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x820);
                bVar6 = (iVar11 * 1000) / 0x7fff < iVar13;
              }
              else {
                bVar6 = true;
              }
              if (bVar6) {
                iVar11 = pRVar5->_padding_;
                cVar8 = (**(code **)(iVar11 + 0x20))(param_2,fStack_c,fStack_10,0,0,1,0,1,0,1);
                if (cVar8 == '\0') {
                  (**(code **)(iVar11 + 0x18))(param_2,fStack_c,fStack_10,0);
                }
              }
              sVar14 = sVar14 + -1000;
              iVar13 = iVar13 + -1000;
            } while (0 < sVar14);
          }
        }
        psVar12 = psVar12 + 1;
        _param_6 = _param_6 + 1;
        param_8 = param_8 + -1;
      } while (param_8 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00458b3a
// Address: 00458b3a
// XREFS: None
int __thiscall
FUN_00458b3a(RGE_Map *param_1,undefined4 param_2,short param_3,short param_4,short param_5,
            int param_6,int param_7,int param_8)
{
  short sVar1;
  RGE_Object_Node *pRVar2;
  RGE_Object_Node *pRVar3;
  short sVar4;
  char cVar5;
  short sVar6;
  RGE_Static_Object *pRVar7;
  
  RGE_Map::get_terrain(param_1,param_4,param_3);
  pRVar2 = param_1->map_row_offset[param_3][param_4].objects.list;
  sVar4 = -1;
joined_r0x00458b74:
  do {
    while( true ) {
      do {
        pRVar3 = pRVar2;
        if (pRVar3 == (RGE_Object_Node *)0x0) {
          return (int)sVar4;
        }
        pRVar7 = pRVar3->node;
        pRVar2 = pRVar3->next;
        sVar1 = pRVar7->master_obj->id;
      } while ((param_7 <= sVar1) && (sVar1 <= param_8));
      if (-1 < param_5) break;
      if (param_6 == 0) {
        (**(code **)(pRVar7->_padding_ + 0x68))();
      }
      else if (pRVar7 != (RGE_Static_Object *)0x0) {
        (**(code **)pRVar7->_padding_)(1);
      }
    }
    sVar6 = param_1->terrain_types[param_5].num_obj_type;
    sVar4 = sVar1;
    if (sVar6 < 0) break;
    do {
      if (param_1->terrain_types[param_5].obj_types[sVar6] == sVar1) break;
      sVar6 = sVar6 + -1;
    } while (-1 < sVar6);
    if (sVar6 < 0) break;
    if (param_6 == 0) goto LAB_00458c62;
    if (pRVar7 != (RGE_Static_Object *)0x0) {
      (**(code **)pRVar7->_padding_)(1);
    }
  } while( true );
  cVar5 = (**(code **)(pRVar7->master_obj->_padding_ + 0x20))
                    (pRVar7->owner,pRVar7->world_x,pRVar7->world_y,0,0,1,1,1,0,0);
  if (cVar5 != '\0') {
    pRVar7 = pRVar3->node;
    if (param_6 == 0) {
LAB_00458c62:
      (**(code **)(pRVar7->_padding_ + 0x68))();
    }
    else if (pRVar7 != (RGE_Static_Object *)0x0) {
      (**(code **)pRVar7->_padding_)(1);
    }
  }
  goto joined_r0x00458b74;
}

// --------------------------------------------------

// Function: FUN_00458c81
// Address: 00458c81
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_map_cpp: "C:\msdev\work\age1_x1\map.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00458c81(RGE_Map *param_1,int param_2,undefined4 param_3,short param_4,short param_5,
            undefined4 param_6,int param_7)
{
  uchar uVar1;
  int *piVar2;
  bool bVar3;
  float fVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  float fStack_28;
  int iStack_20;
  short *psStack_1c;
  int iStack_18;
  
  bVar5 = RGE_Map::get_terrain(param_1,param_5,param_4);
  iVar8 = (int)param_1->terrain_types[bVar5].num_obj_type;
  iStack_18 = 0;
  if (iVar8 < 1) {
    return;
  }
  psStack_1c = param_1->terrain_types[bVar5].obj_types;
  do {
    if (*psStack_1c != -1) {
      piVar2 = *(int **)(*(int *)(param_2 + 0x24) + *psStack_1c * 4);
      sVar9 = param_1->terrain_types[bVar5].obj_density[iStack_18];
      uVar1 = param_1->terrain_types[bVar5].obj_placement_flag[iStack_18];
      if (piVar2 != (int *)0x0) {
        if (param_7 == 0) {
          if (0 < sVar9) {
            iStack_20 = (int)sVar9;
            do {
              if (uVar1 == '\0') {
                iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x894);
                fStack_28 = (float)(int)param_5 - (float)iVar7 * _DAT_005706b4;
                iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x895);
                fVar4 = (float)(int)param_4 - (float)iVar7 * _DAT_005706b4;
              }
              else {
                fStack_28 = (float)(int)param_5 - _DAT_005706b0;
                fVar4 = (float)(int)param_4 - _DAT_005706b0;
              }
              if (sVar9 < 1000) {
                iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x8a2);
                bVar3 = (iVar7 * 1000) / 0x7fff < iStack_20;
              }
              else {
                bVar3 = true;
              }
              if (bVar3) {
                iVar7 = *piVar2;
                cVar6 = (**(code **)(iVar7 + 0x20))(param_2,fStack_28,fVar4,0,0,1,0,1,0,1);
                if (cVar6 == '\0') {
                  (**(code **)(iVar7 + 0x18))(param_2,fStack_28,fVar4,0);
                }
              }
              sVar9 = sVar9 + -1000;
              iStack_20 = iStack_20 + -1000;
            } while (0 < sVar9);
          }
        }
        else if ((piVar2 != (int *)0x0) && (param_7 == 1)) {
          if (uVar1 == '\0') {
            iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x8af);
            fStack_28 = (float)(int)param_5 - (float)iVar7 * _DAT_005706b4;
            iVar7 = debug_rand(s_C__msdev_work_age1_x1_map_cpp,0x8b0);
            fVar4 = (float)(int)param_4 - (float)iVar7 * _DAT_005706b4;
          }
          else {
            fStack_28 = (float)(int)param_5 - _DAT_005706b0;
            fVar4 = (float)(int)param_4 - _DAT_005706b0;
          }
          cVar6 = (**(code **)(*piVar2 + 0x20))(param_2,fStack_28,fVar4,0,0,1,0,1,0,1);
          if (cVar6 == '\0') {
            (**(code **)(*piVar2 + 0x18))(param_2,fStack_28,fVar4,0);
            return;
          }
        }
      }
    }
    iStack_18 = iStack_18 + 1;
    psStack_1c = psStack_1c + 1;
    if (iVar8 <= iStack_18) {
      return;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00459055
// Address: 00459055
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00459055(int param_1,short param_2,short param_3,int param_4,float *param_5,float *param_6)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = (int)param_3;
  fVar4 = (float)(int)param_2 / (float)(int)*(short *)(param_1 + 0x8d96);
  fVar3 = 0.0;
  fVar1 = (float)iVar5 / (float)(int)*(short *)(param_1 + 0x8d98);
  switch(*(undefined1 *)(param_4 + 4)) {
  case 0:
  case 9:
    goto switchD_004590c7_caseD_0;
  case 1:
    if (fVar4 <= (float)_DAT_005706c0) {
      fVar3 = (fVar1 + fVar1) - (((float)_DAT_005706c0 - fVar4) + ((float)_DAT_005706c0 - fVar4));
    }
    else {
      fVar3 = (fVar1 + fVar1) - ((fVar4 - (float)_DAT_005706c0) + (fVar4 - (float)_DAT_005706c0));
    }
    break;
  case 2:
    if ((float)_DAT_005706c0 < fVar4) {
      fVar3 = fVar4 * (float)_DAT_005706d0 - (fVar1 - (float)_DAT_005706c0);
      break;
    }
    goto switchD_004590c7_caseD_8;
  case 3:
    fVar3 = (float)_DAT_005706d8 - fVar4;
    if (fVar4 * (float)_DAT_005706c0 < (float)iVar5) {
      fVar3 = fVar3 * (float)_DAT_005706c0 - (fVar1 - (float)_DAT_005706c0);
      break;
    }
    fVar2 = fVar1 + fVar1;
    fVar3 = (fVar3 + fVar3) - (float)_DAT_005706d8;
    goto LAB_00459318;
  case 4:
    if (((float)_DAT_005706d8 - fVar4) * (float)_DAT_005706c0 < (float)iVar5) {
      fVar3 = fVar4 * (float)_DAT_005706c0 - (fVar1 - (float)_DAT_005706c0);
      break;
    }
  case 7:
switchD_004590c7_caseD_7:
    fVar2 = fVar1 + fVar1;
    fVar3 = (fVar4 + fVar4) - (float)_DAT_005706d8;
LAB_00459318:
    fVar3 = fVar3 + fVar2;
    break;
  case 5:
    goto switchD_004590c7_caseD_5;
  case 6:
switchD_004590c7_caseD_6:
    fVar3 = fVar4 * (float)_DAT_005706d0 - (fVar1 - (float)_DAT_005706c0);
    break;
  case 8:
    goto switchD_004590c7_caseD_8;
  case 10:
    if ((float)_DAT_005706d8 <= fVar1) {
      fVar3 = -1.0;
    }
    else {
      fVar3 = -fVar1;
    }
    break;
  case 0xb:
    if (fVar4 <= (float)_DAT_005706c0) {
      fVar3 = ((float)_DAT_005706c0 - fVar4) + ((float)_DAT_005706c0 - fVar4);
      break;
    }
    goto switchD_004590c7_caseD_0;
  case 0xc:
    if ((float)_DAT_005706c0 < fVar4) {
      fVar3 = (fVar4 - (float)_DAT_005706c0) + (fVar4 - (float)_DAT_005706c0);
      break;
    }
switchD_004590c7_caseD_0:
    fVar3 = 0.0;
    break;
  case 0xd:
    if (fVar4 <= (float)_DAT_005706c0) {
      fVar3 = ((float)_DAT_005706c0 - fVar4) + fVar1;
      fVar3 = fVar3 + fVar3;
    }
    else {
      fVar3 = (fVar4 - (float)_DAT_005706c0) + fVar1;
      fVar3 = fVar3 + fVar3;
    }
    break;
  case 0xe:
    if (fVar4 <= (float)_DAT_005706c0) goto switchD_004590c7_caseD_6;
    goto switchD_004590c7_caseD_8;
  case 0xf:
    if ((float)iVar5 <= (float)_DAT_005706d8 - fVar4 * (float)_DAT_005706c0)
    goto switchD_004590c7_caseD_7;
switchD_004590c7_caseD_8:
    fVar3 = ((float)_DAT_005706d8 - fVar4) * (float)_DAT_005706d0 - (fVar1 - (float)_DAT_005706c0);
    break;
  case 0x10:
    if ((float)_DAT_005706d8 - ((float)_DAT_005706d8 - fVar4) * (float)_DAT_005706c0 < (float)iVar5)
    goto switchD_004590c7_caseD_6;
switchD_004590c7_caseD_5:
    fVar3 = fVar1 + fVar1;
    fVar2 = (float)_DAT_005706d8 - (fVar4 + fVar4);
    goto LAB_00459318;
  }
  fVar1 = (((fVar4 + fVar4) - ((float)_DAT_005706d8 - (fVar1 + fVar1))) + fVar3) *
          (float)_DAT_005706c0;
  *param_6 = fVar1;
  *param_5 = (fVar4 + fVar4) - fVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_00459352
// Address: 00459352
// XREFS: None
uint __fastcall FUN_00459352(char *param_1,uint param_2,short param_3,short param_4)
{
  char *pcVar1;
  char *in_EAX;
  int iVar2;
  uint uVar3;
  char cVar6;
  char cVar7;
  char *unaff_EBX;
  int unaff_EBP;
  char *unaff_ESI;
  int unaff_EDI;
  char cVar4;
  undefined2 uVar5;
  
  *(uint *)(param_2 + 0x90ce0045) = *(uint *)(param_2 + 0x90ce0045) & param_2;
  cVar6 = (char)param_1;
  *unaff_EBX = *unaff_EBX + cVar6;
  cVar4 = (char)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX + cVar4;
  in_EAX[0x6004591] = in_EAX[0x6004591] + (char)in_EAX;
  uVar5 = (undefined2)((uint)unaff_EBX >> 0x10);
  cVar7 = (char)((uint)param_1 >> 8);
  cVar4 = cVar4 + cVar7;
  iVar2 = CONCAT22(uVar5,CONCAT11(cVar4,(char)unaff_EBX));
  *(char *)(unaff_EBP + -0x68ffba69) = *(char *)(unaff_EBP + -0x68ffba69) + cVar4;
  *param_1 = *param_1 + cVar4;
  pcVar1 = (char *)(iVar2 + -0x1affba6f);
  cVar4 = (char)((uint)in_EAX >> 8);
  *pcVar1 = *pcVar1 + cVar4;
  *in_EAX = *in_EAX + cVar6;
  *unaff_ESI = *unaff_ESI + cVar7;
  *(char *)(unaff_EDI + -0x6e) = *(char *)(unaff_EDI + -0x6e) + cVar7;
  param_1[-0x6e] = param_1[-0x6e] + cVar4;
  pcVar1 = (char *)(iVar2 + -0x6f6f6f70);
  *pcVar1 = *pcVar1 + cVar6;
  uVar3 = CONCAT22(uVar5,param_3);
  if ((-1 < param_3) && (uVar3 = (uint)param_3, (int)uVar3 < *(int *)(param_2 + 8))) {
    uVar3 = CONCAT22(param_3 >> 0xf,param_4);
    if ((-1 < param_4) && ((int)param_4 < *(int *)(param_2 + 0xc))) {
      return CONCAT31((int3)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_004593f6
// Address: 004593f6
// XREFS: None
uint __thiscall FUN_004593f6(int param_1,short param_2,short param_3)
{
  byte bVar1;
  uint3 uVar3;
  uint uVar2;
  
  bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x8d8c) + param_3 * 4) + 5 + param_2 * 0x18);
  uVar3 = (uint3)((uint)(param_2 * 3) >> 8);
  uVar2 = CONCAT31(uVar3,bVar1) & 0xffffff1f;
  _param_3 = bVar1 & 0x1f;
  if ((0x20 < (byte)uVar2) ||
     ((param_1 = param_1 + _param_3 * 0x198, *(char *)(param_1 + 0x8c) == '\0' &&
      (*(short *)(param_1 + 0x144) < 0)))) {
    uVar2 = (uint)uVar3 << 8;
  }
  return uVar2;
}

// --------------------------------------------------


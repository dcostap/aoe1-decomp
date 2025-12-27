// GLOBAL FUNCTIONS PART 1600
// Function: FUN_0043a4fe
// Address: 0043a4fe
undefined4 * FUN_0043a4fe(int param_1,int param_2,int param_3)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  
  param_3 = (((int)(param_2 * param_1 + (param_2 * param_1 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc) *
            param_3;
  uVar1 = GlobalAlloc(0x42,param_3 + 0x428);
  puVar2 = (undefined4 *)GlobalLock(uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar2 = 0x28;
  puVar2[1] = param_2;
  puVar2[2] = unaff_retaddr;
  *(undefined2 *)(puVar2 + 3) = 1;
  *(short *)((int)puVar2 + 0xe) = (short)param_1;
  puVar2[4] = 0;
  puVar2[5] = param_3;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  if (param_1 == 4) {
    puVar2[8] = 0x10;
  }
  else if (param_1 == 8) {
    puVar2[8] = 0x100;
  }
  iVar4 = 0;
  puVar3 = puVar2 + 10;
  if (0 < (int)(puVar2[8] + ((int)puVar2[8] >> 0x1f & 0xfU)) >> 4) {
    do {
      *puVar3 = 0;
      puVar3[1] = 0x800000;
      puVar3[2] = 0x8000;
      puVar3[3] = 0x808000;
      puVar3[4] = 0x80;
      puVar3[5] = 0x800080;
      puVar3[6] = 0x8080;
      puVar3[7] = 0xc0c0c0;
      puVar3[8] = 0x808080;
      puVar3[9] = 0xff0000;
      puVar3[10] = 0xff00;
      puVar3[0xb] = 0xffff00;
      puVar3[0xc] = 0xff;
      puVar3[0xd] = 0xff00ff;
      puVar3[0xe] = 0xffff;
      puVar3[0xf] = 0xffffff;
      puVar3 = puVar3 + 0x10;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(puVar2[8] + ((int)puVar2[8] >> 0x1f & 0xfU)) >> 4);
  }
  return puVar2;
}

// --------------------------------------------------

// Function: DibCreate
// Address: 0043a500
/* struct tagBITMAPINFOHEADER * __cdecl DibCreate(int,int,int) */

tagBITMAPINFOHEADER * __cdecl DibCreate(int param_1,int param_2,int param_3)
{
  undefined4 uVar1;
  tagBITMAPINFOHEADER *ptVar2;
  tagBITMAPINFOHEADER *ptVar3;
  ulong uVar4;
  int iVar5;
  long unaff_retaddr;
  
  uVar4 = (((int)(param_2 * param_1 + (param_2 * param_1 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc) *
          param_3;
  uVar1 = GlobalAlloc(0x42,uVar4 + 0x428);
  ptVar2 = (tagBITMAPINFOHEADER *)GlobalLock(uVar1);
  if (ptVar2 == (tagBITMAPINFOHEADER *)0x0) {
    return (tagBITMAPINFOHEADER *)0x0;
  }
  ptVar2->biSize = 0x28;
  ptVar2->biWidth = param_2;
  ptVar2->biHeight = unaff_retaddr;
  ptVar2->biPlanes = 1;
  ptVar2->biBitCount = (ushort)param_1;
  ptVar2->biCompression = 0;
  ptVar2->biSizeImage = uVar4;
  ptVar2->biXPelsPerMeter = 0;
  ptVar2->biYPelsPerMeter = 0;
  ptVar2->biClrUsed = 0;
  ptVar2->biClrImportant = 0;
  if (param_1 == 4) {
    ptVar2->biClrUsed = 0x10;
  }
  else if (param_1 == 8) {
    ptVar2->biClrUsed = 0x100;
  }
  iVar5 = 0;
  ptVar3 = ptVar2 + 1;
  if (0 < (int)(ptVar2->biClrUsed + ((int)ptVar2->biClrUsed >> 0x1f & 0xfU)) >> 4) {
    do {
      ptVar3->biSize = 0;
      ptVar3->biWidth = 0x800000;
      ptVar3->biHeight = 0x8000;
      ptVar3->biPlanes = 0x8000;
      ptVar3->biBitCount = 0x80;
      ptVar3->biCompression = 0x80;
      ptVar3->biSizeImage = 0x800080;
      ptVar3->biXPelsPerMeter = 0x8080;
      ptVar3->biYPelsPerMeter = 0xc0c0c0;
      ptVar3->biClrUsed = 0x808080;
      ptVar3->biClrImportant = 0xff0000;
      ptVar3[1].biSize = 0xff00;
      ptVar3[1].biWidth = 0xffff00;
      ptVar3[1].biHeight = 0xff;
      ptVar3[1].biPlanes = 0xff;
      ptVar3[1].biBitCount = 0xff;
      ptVar3[1].biCompression = 0xffff;
      ptVar3[1].biSizeImage = 0xffffff;
      ptVar3 = (tagBITMAPINFOHEADER *)&ptVar3[1].biXPelsPerMeter;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(ptVar2->biClrUsed + ((int)ptVar2->biClrUsed >> 0x1f & 0xfU)) >> 4);
  }
  return ptVar2;
}

// --------------------------------------------------

// Function: FUN_0043a655
// Address: 0043a655
void FUN_0043a655(int *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  uint3 uVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 uStack_128;
  int iStack_124;
  int iStack_120;
  int iStack_11c;
  int iStack_118;
  byte *pbStack_114;
  byte bStack_110;
  byte bStack_10f;
  byte bStack_10e;
  uint uStack_10c;
  uint uStack_108;
  int iStack_104;
  char acStack_100 [256];
  
  uVar2 = (uint3)uStack_128;
  iStack_11c = 0;
  uStack_128 = (uint)(uint3)uStack_128;
  uStack_108 = uStack_108 & 0xffffff00;
  if (param_2 == 0) {
    return;
  }
  if (param_1 == (int *)0x0) {
    return;
  }
  iVar8 = *param_1;
  pbStack_114 = (byte *)(iVar8 + (int)param_1);
  GetObjectA(param_2,4,&iStack_11c);
  iVar1 = param_1[8];
  iStack_118 = iVar1;
  if ((iVar1 == 0) && (*(ushort *)((int)param_1 + 0xe) < 9)) {
    iStack_118 = 1 << ((byte)*(ushort *)((int)param_1 + 0xe) & 0x1f);
  }
  iStack_120 = param_1[5];
  if (iStack_120 == 0) {
    iStack_120 = (param_1[1] * (uint)*(ushort *)((int)param_1 + 0xe) + 0x1f >> 3 & 0x1ffffffc) *
                 param_1[2];
  }
  if (param_1[4] == 3) {
    iStack_124 = *param_1 + 0xc;
  }
  else {
    iStack_124 = *param_1 + iVar1 * 4;
  }
  iStack_124 = iStack_124 + (int)param_1;
  if (param_3 != 0) {
    if (param_4 == 0) {
      uStack_108 = CONCAT31(uStack_108._1_3_,
                            *(undefined1 *)
                             ((param_1[1] + 3U & 0xfffffffc) * (param_1[2] + -1) + iStack_124));
    }
    else {
      uStack_108 = (uint)uStack_108._1_3_ << 8;
    }
    uVar6 = (uint)((byte *)(iVar8 + (int)param_1))[2];
    uVar5 = (uint)pbStack_114[1];
    uStack_128 = (uint)uVar2;
    uStack_10c = (uint)*pbStack_114;
    iStack_104 = 0;
    iVar8 = 1;
    do {
      uVar6 = uVar6 + iVar8;
      uVar5 = uVar5 + iVar8;
      uStack_10c = uStack_10c + iVar8;
      if ((((0xff < (int)uVar6) || (0xff < (int)uVar5)) || (0xff < (int)uStack_10c)) ||
         ((((int)uVar6 < 0 || ((int)uVar5 < 0)) || ((int)uStack_10c < 0)))) {
        if (iStack_104 != 0) break;
        iVar8 = -1;
        uVar6 = (uint)pbStack_114[2];
        uVar5 = (uint)pbStack_114[1];
        uStack_10c = (uint)*pbStack_114;
        iStack_104 = 1;
      }
      cVar3 = GetNearestPaletteIndex
                        (param_2,(uint)CONCAT11((char)uStack_10c,(char)uVar5) << 8 | uVar6 & 0xff);
      uStack_128 = CONCAT13(cVar3,(uint3)uStack_128);
    } while (cVar3 == '\0');
  }
  uVar6 = 0;
  if (0 < iStack_118) {
    pbVar7 = pbStack_114 + 2;
    do {
      if (param_3 == 0) {
        cVar3 = GetNearestPaletteIndex
                          (param_2,(uint)CONCAT21(CONCAT11(pbVar7[-2],pbVar7[-1]),*pbVar7));
        acStack_100[uVar6] = cVar3;
      }
      else if (uVar6 == (uStack_108 & 0xff)) {
        acStack_100[uVar6] = '\0';
      }
      else {
        cVar3 = GetNearestPaletteIndex
                          (param_2,(uint)CONCAT21(CONCAT11(pbVar7[-2],pbVar7[-1]),*pbVar7));
        acStack_100[uVar6] = cVar3;
        if (cVar3 == '\0') {
          acStack_100[uVar6] = uStack_128._3_1_;
        }
      }
      uVar6 = uVar6 + 1;
      pbVar7 = pbVar7 + 4;
    } while ((int)uVar6 < iStack_118);
  }
  param_1[8] = iStack_11c;
  if (iStack_118 < iStack_11c) {
    uVar4 = GlobalHandle(param_1);
    GlobalUnlock(uVar4);
    uVar4 = GlobalHandle(param_1,*param_1 + iStack_124 * 4 + uStack_128,0);
    uVar4 = GlobalReAlloc(uVar4);
    GlobalLock(uVar4);
    if (param_1[4] == 3) {
      iVar8 = *param_1 + 0xc;
    }
    else {
      iVar8 = *param_1 + param_1[8] * 4;
    }
    memmove(iVar8 + (int)param_1,iStack_124,uStack_128);
    if (param_1[4] == 3) {
      iStack_124 = *param_1 + 0xc + (int)param_1;
      goto LAB_0043a9a9;
    }
  }
  else {
    if (iStack_118 <= iStack_11c) goto LAB_0043a9a9;
    if (param_1[4] == 3) {
      iVar8 = *param_1 + 0xc;
    }
    else {
      iVar8 = *param_1 + iStack_11c * 4;
    }
    memcpy(iVar8 + (int)param_1,iStack_124,iStack_120);
    uVar4 = GlobalHandle(param_1);
    GlobalUnlock(uVar4);
    uVar4 = GlobalHandle(param_1,*param_1 + iStack_124 * 4 + uStack_128,0);
    uVar4 = GlobalReAlloc(uVar4);
    GlobalLock(uVar4);
    if (param_1[4] == 3) {
      iStack_124 = *param_1 + 0xc + (int)param_1;
      goto LAB_0043a9a9;
    }
  }
  iStack_124 = *param_1 + param_1[8] * 4 + (int)param_1;
LAB_0043a9a9:
  iVar8 = param_1[4];
  if (iVar8 == 0) {
    if (*(short *)((int)param_1 + 0xe) == 8) {
      xlatClut8();
    }
    else {
      xlatClut4(iStack_124,iStack_120,acStack_100);
    }
  }
  else if (iVar8 == 1) {
    xlatRle8(iStack_124,iStack_120,acStack_100);
  }
  else if (iVar8 == 2) {
    xlatRle4(iStack_124,iStack_120,acStack_100);
  }
  iVar8 = 0;
  if (0 < iStack_11c) {
    pbVar7 = pbStack_114 + 1;
    do {
      GetPaletteEntries(param_2,iVar8,1,&bStack_110);
      iVar8 = iVar8 + 1;
      pbVar7[1] = bStack_110;
      *pbVar7 = bStack_10f;
      pbVar7[-1] = bStack_10e;
      pbVar7[2] = 0;
      pbVar7 = pbVar7 + 4;
    } while (iVar8 < iStack_11c);
  }
  return;
}

// --------------------------------------------------

// Function: DibMapToPalette
// Address: 0043a660
/* WARNING: Variable defined which should be unmapped: ZeroIndex */
/* void __cdecl DibMapToPalette(struct tagBITMAPINFOHEADER *,void *,int,int) */

void __cdecl DibMapToPalette(tagBITMAPINFOHEADER *param_1,void *param_2,int param_3,int param_4)
{
  tagRGBQUAD *ptVar1;
  ulong uVar2;
  uchar *puVar3;
  char cVar4;
  uchar uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  tagPALETTEENTRY tVar10;
  int iVar11;
  uchar ZeroIndex;
  uchar *lpBits;
  ulong SizeImage;
  int nPalColors;
  int nDibColors;
  tagRGBQUAD *lpRgb;
  tagPALETTEENTRY pe;
  int ZeroBlue;
  uchar TransIndex;
  int HitEnd;
  uchar xlat [256];
  
  puVar3 = lpBits;
  nDibColors = 0;
  lpBits = (uchar *)((uint)lpBits & 0xffffff);
  HitEnd = HitEnd & 0xffffff00;
  if (param_2 == (void *)0x0) {
    return;
  }
  if (param_1 == (tagBITMAPINFOHEADER *)0x0) {
    return;
  }
  tVar10 = (tagPALETTEENTRY)((int)&param_1->biSize + param_1->biSize);
  pe = tVar10;
  GetObjectA(param_2,4,&nDibColors);
  ptVar1 = (tagRGBQUAD *)param_1->biClrUsed;
  lpRgb = ptVar1;
  if ((ptVar1 == (tagRGBQUAD *)0x0) && (param_1->biBitCount < 9)) {
    lpRgb = (tagRGBQUAD *)(1 << ((byte)param_1->biBitCount & 0x1f));
  }
  nPalColors = param_1->biSizeImage;
  if (nPalColors == 0) {
    nPalColors = (param_1->biWidth * (uint)param_1->biBitCount + 0x1f >> 3 & 0x1ffffffc) *
                 param_1->biHeight;
  }
  if (param_1->biCompression == 3) {
    iVar11 = param_1->biSize + 0xc;
  }
  else {
    iVar11 = param_1->biSize + (int)ptVar1 * 4;
  }
  SizeImage = (int)&param_1->biSize + iVar11;
  if (param_3 != 0) {
    if (param_4 == 0) {
      HitEnd = CONCAT31(HitEnd._1_3_,
                        *(undefined1 *)
                         ((param_1->biWidth + 3U & 0xfffffffc) * (param_1->biHeight + -1) +
                         SizeImage));
    }
    else {
      HitEnd = (uint)HitEnd._1_3_ << 8;
    }
    uVar8 = (uint)*(byte *)((int)tVar10 + 2);
    uVar7 = (uint)*(byte *)((int)pe + 1);
    lpBits = (uchar *)((uint)puVar3 & 0xffffff);
    _TransIndex = (uint)*(byte *)pe;
    xlat[0] = '\0';
    xlat[1] = '\0';
    xlat[2] = '\0';
    xlat[3] = '\0';
    iVar11 = 1;
    do {
      uVar8 = uVar8 + iVar11;
      uVar7 = uVar7 + iVar11;
      _TransIndex = _TransIndex + iVar11;
      if ((((0xff < (int)uVar8) || (0xff < (int)uVar7)) || (0xff < (int)_TransIndex)) ||
         ((((int)uVar8 < 0 || ((int)uVar7 < 0)) || ((int)_TransIndex < 0)))) {
        if (xlat._0_4_ != 0) break;
        iVar11 = -1;
        uVar8 = (uint)*(byte *)((int)pe + 2);
        uVar7 = (uint)*(byte *)((int)pe + 1);
        _TransIndex = (uint)*(byte *)pe;
        xlat[0] = '\x01';
        xlat[1] = '\0';
        xlat[2] = '\0';
        xlat[3] = '\0';
      }
      cVar4 = GetNearestPaletteIndex
                        (param_2,(uint)CONCAT11((char)_TransIndex,(char)uVar7) << 8 | uVar8 & 0xff);
      lpBits = (uchar *)CONCAT13(cVar4,lpBits._0_3_);
    } while (cVar4 == '\0');
  }
  uVar8 = 0;
  if (0 < (int)lpRgb) {
    puVar9 = (undefined1 *)((int)pe + 2);
    do {
      if (param_3 == 0) {
        uVar5 = GetNearestPaletteIndex
                          (param_2,(uint)CONCAT21(CONCAT11(puVar9[-2],puVar9[-1]),*puVar9));
        xlat[uVar8 + 4] = uVar5;
      }
      else if (uVar8 == (HitEnd & 0xffU)) {
        xlat[uVar8 + 4] = '\0';
      }
      else {
        uVar5 = GetNearestPaletteIndex
                          (param_2,(uint)CONCAT21(CONCAT11(puVar9[-2],puVar9[-1]),*puVar9));
        xlat[uVar8 + 4] = uVar5;
        if (uVar5 == '\0') {
          xlat[uVar8 + 4] = lpBits._3_1_;
        }
      }
      uVar8 = uVar8 + 1;
      puVar9 = puVar9 + 4;
    } while ((int)uVar8 < (int)lpRgb);
  }
  param_1->biClrUsed = nDibColors;
  if ((int)lpRgb < nDibColors) {
    uVar6 = GlobalHandle(param_1);
    GlobalUnlock(uVar6);
    uVar6 = GlobalHandle(param_1,lpBits + param_1->biSize + SizeImage * 4,0);
    uVar6 = GlobalReAlloc(uVar6);
    GlobalLock(uVar6);
    if (param_1->biCompression == 3) {
      iVar11 = param_1->biSize + 0xc;
    }
    else {
      iVar11 = param_1->biSize + param_1->biClrUsed * 4;
    }
    memmove((int)&param_1->biSize + iVar11,SizeImage,lpBits);
    if (param_1->biCompression == 3) {
      SizeImage = (int)&param_1->biPlanes + param_1->biSize;
      goto LAB_0043a9a9;
    }
  }
  else {
    if ((int)lpRgb <= nDibColors) goto LAB_0043a9a9;
    if (param_1->biCompression == 3) {
      iVar11 = param_1->biSize + 0xc;
    }
    else {
      iVar11 = param_1->biSize + nDibColors * 4;
    }
    memcpy((int)&param_1->biSize + iVar11,SizeImage,nPalColors);
    uVar6 = GlobalHandle(param_1);
    GlobalUnlock(uVar6);
    uVar6 = GlobalHandle(param_1,lpBits + param_1->biSize + SizeImage * 4,0);
    uVar6 = GlobalReAlloc(uVar6);
    GlobalLock(uVar6);
    if (param_1->biCompression == 3) {
      SizeImage = (int)&param_1->biPlanes + param_1->biSize;
      goto LAB_0043a9a9;
    }
  }
  SizeImage = (int)&param_1->biSize + param_1->biSize + param_1->biClrUsed * 4;
LAB_0043a9a9:
  uVar2 = param_1->biCompression;
  if (uVar2 == 0) {
    if (param_1->biBitCount == 8) {
      xlatClut8();
    }
    else {
      xlatClut4(SizeImage,nPalColors,xlat + 4);
    }
  }
  else if (uVar2 == 1) {
    xlatRle8(SizeImage,nPalColors,xlat + 4);
  }
  else if (uVar2 == 2) {
    xlatRle4(SizeImage,nPalColors,xlat + 4);
  }
  iVar11 = 0;
  if (0 < nDibColors) {
    puVar9 = (undefined1 *)((int)pe + 1);
    do {
      GetPaletteEntries(param_2,iVar11,1,&ZeroBlue);
      iVar11 = iVar11 + 1;
      puVar9[1] = (undefined1)ZeroBlue;
      *puVar9 = ZeroBlue._1_1_;
      puVar9[-1] = ZeroBlue._2_1_;
      puVar9[2] = 0;
      puVar9 = puVar9 + 4;
    } while (iVar11 < nDibColors);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043aa59
// Address: 0043aa59
void FUN_0043aa59(byte *param_1,int param_2,int param_3)
{
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      *param_1 = *(byte *)((uint)*param_1 + param_3);
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: xlatClut8
// Address: 0043aa60
void xlatClut8(byte *param_1,int param_2,int param_3)
{
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      *param_1 = *(byte *)((uint)*param_1 + param_3);
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043aa81
// Address: 0043aa81
void FUN_0043aa81(byte *param_1,int param_2,int param_3)
{
  if (param_2 != 0) {
    do {
      *param_1 = *(byte *)((*param_1 & 0xf) + param_3) |
                 *(char *)((uint)(*param_1 >> 4) + param_3) << 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: xlatClut4
// Address: 0043aa90
void xlatClut4(byte *param_1,int param_2,int param_3)
{
  if (param_2 != 0) {
    do {
      *param_1 = *(byte *)((*param_1 & 0xf) + param_3) |
                 *(char *)((uint)(*param_1 >> 4) + param_3) << 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043aac2
// Address: 0043aac2
void FUN_0043aac2(byte *param_1,undefined4 param_2,int param_3)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = param_1;
  while( true ) {
    do {
      while( true ) {
        pbVar3 = pbVar2;
        bVar1 = pbVar3[1];
        param_1 = (byte *)(uint)bVar1;
        if (*pbVar3 == 0) break;
        pbVar3[1] = *(byte *)((int)param_1 + param_3);
        pbVar2 = pbVar3 + 2;
      }
      pbVar2 = pbVar3 + 2;
    } while (param_1 == (byte *)0x0);
    if (param_1 == (byte *)0x1) break;
    if (param_1 == (byte *)0x2) {
      pbVar2 = pbVar3 + 4;
    }
    else {
      pbVar3 = pbVar2;
      if (bVar1 != 0) {
        do {
          pbVar2 = pbVar3 + 1;
          param_1 = (byte *)((int)param_1 - 1);
          *pbVar3 = *(byte *)(param_3 + (uint)*pbVar3);
          pbVar3 = pbVar2;
        } while (param_1 != (byte *)0x0);
      }
      if ((bVar1 & 1) != 0) {
        pbVar2 = pbVar2 + 1;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: xlatRle8
// Address: 0043aad0
void xlatRle8(byte *param_1,undefined4 param_2,int param_3)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = param_1;
  while( true ) {
    do {
      while( true ) {
        pbVar3 = pbVar2;
        bVar1 = pbVar3[1];
        param_1 = (byte *)(uint)bVar1;
        if (*pbVar3 == 0) break;
        pbVar3[1] = *(byte *)((int)param_1 + param_3);
        pbVar2 = pbVar3 + 2;
      }
      pbVar2 = pbVar3 + 2;
    } while (param_1 == (byte *)0x0);
    if (param_1 == (byte *)0x1) break;
    if (param_1 == (byte *)0x2) {
      pbVar2 = pbVar3 + 4;
    }
    else {
      pbVar3 = pbVar2;
      if (bVar1 != 0) {
        do {
          pbVar2 = pbVar3 + 1;
          param_1 = (byte *)((int)param_1 - 1);
          *pbVar3 = *(byte *)(param_3 + (uint)*pbVar3);
          pbVar3 = pbVar2;
        } while (param_1 != (byte *)0x0);
      }
      if ((bVar1 & 1) != 0) {
        pbVar2 = pbVar2 + 1;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043ab35
// Address: 0043ab35
void FUN_0043ab35(void)
{
  return;
}

// --------------------------------------------------

// Function: xlatRle4
// Address: 0043ab40
void xlatRle4(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0043ab41
// Address: 0043ab41
void FUN_0043ab41(int param_1,int param_2,int param_3)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)(param_1 + -1 + param_3);
  puVar2 = (undefined1 *)(param_2 + -1 + param_3);
  if (param_3 != 0) {
    do {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + -1;
      puVar2 = puVar2 + -1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: memmove
// Address: 0043ab50
void memmove(int param_1,int param_2,int param_3)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)(param_1 + -1 + param_3);
  puVar2 = (undefined1 *)(param_2 + -1 + param_3);
  if (param_3 != 0) {
    do {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + -1;
      puVar2 = puVar2 + -1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043ab7a
// Address: 0043ab7a
void FUN_0043ab7a(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  PAL_TABLE *pPVar7;
  undefined1 *puVar8;
  undefined1 auStack_800 [40];
  undefined1 auStack_7d8 [984];
  undefined1 auStack_400 [40];
  undefined1 auStack_3d8 [984];
  
  iVar1 = GetActiveWindow();
  iVar3 = iVar1;
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  uVar2 = GetDC(iVar3);
  iVar3 = GetSystemPaletteEntries(uVar2,0,0x100,auStack_800);
  iVar4 = GetPaletteEntries(param_1,0,0x100,auStack_400);
  puVar6 = auStack_7d8 + 3;
  iVar5 = 0;
  puVar8 = auStack_3d8 + 1;
  do {
    auStack_7d8[iVar5] = auStack_3d8[iVar5];
    auStack_7d8[iVar5 + 1] = *puVar8;
    puVar6[-1] = auStack_3d8[iVar5 + 2];
    *puVar6 = 1;
    iVar5 = iVar5 + 4;
    puVar6 = puVar6 + 4;
    puVar8 = puVar8 + 4;
  } while (iVar5 < 0x3b0);
  if (((iVar3 == 0) || (iVar4 == 0)) && (-1 < (int)System_color_Table)) {
    puVar6 = &DAT_005841e5;
    pPVar7 = System_color_Table;
    do {
      iVar3 = (int)pPVar7 * 4;
      auStack_800[iVar3] = puVar6[-1];
      auStack_800[iVar3 + 1] = *puVar6;
      auStack_800[iVar3 + 2] = puVar6[1];
      auStack_800[iVar3 + 3] = 0;
      pPVar7 = *(PAL_TABLE **)(puVar6 + 3);
      puVar6 = puVar6 + 8;
    } while (-1 < (int)pPVar7);
  }
  ReleaseDC(iVar1,uVar2);
  ResizePalette(param_1,0x100);
  SetPaletteEntries(param_1,0,0x100,auStack_800);
  return;
}

// --------------------------------------------------

// Function: CreateIdentityPalette
// Address: 0043ab80
/* WARNING: Variable defined which should be unmapped: hdc */
/* void __cdecl CreateIdentityPalette(void *) */

void __cdecl CreateIdentityPalette(void *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  PAL_TABLE *pPVar6;
  uchar *puVar7;
  tagPALETTEENTRY tVar8;
  void *hdc;
  void *hwnd;
  tagPALETTEENTRY new_pal [256];
  tagPALETTEENTRY from_pal [256];
  
  new_pal[0] = (tagPALETTEENTRY)GetActiveWindow();
  tVar8 = new_pal[0];
  if (new_pal[0] == (tagPALETTEENTRY)0x0) {
    tVar8.peRed = '\0';
    tVar8.peGreen = '\0';
    tVar8.peBlue = '\0';
    tVar8.peFlags = '\0';
  }
  uVar1 = GetDC(tVar8);
  iVar2 = GetSystemPaletteEntries(uVar1,0,0x100,new_pal + 1);
  iVar3 = GetPaletteEntries(param_1,0,0x100,from_pal + 1);
  puVar5 = &new_pal[0xb].peFlags;
  iVar4 = 0;
  puVar7 = &from_pal[0xb].peGreen;
  do {
    (&new_pal[0xb].peRed)[iVar4] = (&from_pal[0xb].peRed)[iVar4];
    (&new_pal[0xb].peGreen)[iVar4] = *puVar7;
    puVar5[-1] = (&from_pal[0xb].peBlue)[iVar4];
    *puVar5 = '\x01';
    iVar4 = iVar4 + 4;
    puVar5 = puVar5 + 4;
    puVar7 = puVar7 + 4;
  } while (iVar4 < 0x3b0);
  if (((iVar2 == 0) || (iVar3 == 0)) && (-1 < (int)System_color_Table)) {
    puVar5 = &DAT_005841e5;
    pPVar6 = System_color_Table;
    do {
      new_pal[(int)((int)&pPVar6->index + 1)].peRed = puVar5[-1];
      new_pal[(int)((int)&pPVar6->index + 1)].peGreen = *puVar5;
      new_pal[(int)((int)&pPVar6->index + 1)].peBlue = puVar5[1];
      new_pal[(int)((int)&pPVar6->index + 1)].peFlags = '\0';
      pPVar6 = *(PAL_TABLE **)(puVar5 + 3);
      puVar5 = puVar5 + 8;
    } while (-1 < (int)pPVar6);
  }
  ReleaseDC(new_pal[0],uVar1);
  ResizePalette(param_1,0x100);
  SetPaletteEntries(param_1,0,0x100,new_pal + 1);
  return;
}

// --------------------------------------------------

// Function: FUN_0043aca9
// Address: 0043aca9
int FUN_0043aca9(int param_1)
{
  undefined2 *puVar1;
  int iVar2;
  undefined4 unaff_EDI;
  int iStack_4;
  
  iStack_4 = 0;
  if (param_1 == 0) {
    return 0;
  }
  GetObjectA(param_1,4,&iStack_4);
  if (iStack_4 == 0) {
    return iStack_4;
  }
  puVar1 = (undefined2 *)LocalAlloc(0x40,iStack_4 * 4 + 8);
  if (puVar1 == (undefined2 *)0x0) {
    return 0;
  }
  *puVar1 = 0x300;
  puVar1[1] = (short)unaff_EDI;
  GetPaletteEntries(param_1,0,unaff_EDI,puVar1 + 2);
  iVar2 = CreatePalette(puVar1);
  LocalFree(puVar1);
  return iVar2;
}

// --------------------------------------------------

// Function: CopyPalette
// Address: 0043acb0
/* WARNING: Variable defined which should be unmapped: nNumEntries */
/* void * __cdecl CopyPalette(void *) */

void * __cdecl CopyPalette(void *param_1)
{
  undefined2 *puVar1;
  void *pvVar2;
  undefined4 unaff_EDI;
  int nNumEntries;
  void *local_4;
  
  local_4 = (void *)0x0;
  if (param_1 == (void *)0x0) {
    return (void *)0x0;
  }
  GetObjectA(param_1,4,&local_4);
  if (local_4 == (void *)0x0) {
    return local_4;
  }
  puVar1 = (undefined2 *)LocalAlloc(0x40,(int)local_4 * 4 + 8);
  if (puVar1 == (undefined2 *)0x0) {
    return (void *)0x0;
  }
  *puVar1 = 0x300;
  puVar1[1] = (short)unaff_EDI;
  GetPaletteEntries(param_1,0,unaff_EDI,puVar1 + 2);
  pvVar2 = (void *)CreatePalette(puVar1);
  LocalFree(puVar1);
  return pvVar2;
}

// --------------------------------------------------

// Function: FUN_0043ad33
// Address: 0043ad33
void FUN_0043ad33(undefined4 param_1)
{
  undefined4 uVar1;
  
  uVar1 = GlobalHandle(param_1);
  GlobalUnlock(uVar1);
  uVar1 = GlobalHandle(param_1);
  GlobalFree(uVar1);
  return;
}

// --------------------------------------------------

// Function: DibFree
// Address: 0043ad40
/* void __cdecl DibFree(struct tagBITMAPINFOHEADER *) */

void __cdecl DibFree(tagBITMAPINFOHEADER *param_1)
{
  undefined4 uVar1;
  
  uVar1 = GlobalHandle(param_1);
  GlobalUnlock(uVar1);
  uVar1 = GlobalHandle(param_1);
  GlobalFree(uVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_0043ad63
// Address: 0043ad63
// [HELPER] s_00000_000_0000000_00000: "00000-000-0000000-00000"
// [HELPER] s_: ""
// [HELPER] s_About_Dialog: "About Dialog"
// [HELPER] s_PID: "PID"
// [HELPER] s__: "}"
// [HELPER] s__s: "%s"
// [HELPER] s_circlep: "circlep"
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

TDialogPanel * __thiscall FUN_0043ad63(TDialogPanel *param_1,TEasy_Panel *param_2)
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  TTextPanel *this;
  long lVar4;
  char *pcVar5;
  TDrawArea *pTVar6;
  TPicturePanel *this_00;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 *unaff_FS_OFFSET;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  TButtonPanel *pTStack_122c;
  int iStack_1228;
  tagRECT tStack_1224;
  TPicturePanel *pTStack_1214;
  TDialogPanel *pTStack_1210;
  char acStack_120c [512];
  char acStack_100c [4092];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055cf89;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_10 = 0x43ad8f;
  pTStack_1210 = param_1;
  TDialogPanel::TDialogPanel(param_1,s_About_Dialog);
  piVar1 = &param_1[1]._padding_;
  piVar2 = &param_1[1]._padding_;
  iVar18 = 1;
  iStack_4 = 0;
  param_1->_padding_ = (int)&TribeAboutDialog::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *piVar1 = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *piVar2 = 0;
  lVar4 = TEasy_Panel::get_popup_info_id(param_2);
  pcVar5 = TEasy_Panel::get_popup_info_file(param_2);
  lVar14 = 0x19c;
  lVar12 = 0x208;
  pTVar6 = TPanel::renderArea((TPanel *)param_2);
  iVar18 = TDialogPanel::setup(param_1,pTVar6,(TPanel *)param_2,lVar12,lVar14,pcVar5,lVar4,iVar18);
  if (iVar18 != 0) {
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)piVar2,s_,10,10,500,0x15e,4,0
               ,0,0);
    (**(code **)(*(int *)*piVar2 + 0xec))
              (3,(char)param_1->_padding_,*(undefined1 *)((int)&param_1->_padding_ + 1),
               *(undefined1 *)((int)&param_1->_padding_ + 2),
               *(undefined1 *)((int)&param_1->_padding_ + 3),(char)param_1->_padding_,
               *(undefined1 *)((int)&param_1->_padding_ + 1));
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),0x2419,0x14,
               0x14,0x1e0,0x14,4,0,0,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x241a,
               0x14,0x28,0x1e0,0x14,0xb,0,0,0);
    TPanel::get_string((TPanel *)param_1,0x2424,acStack_120c,0x200);
    if (acStack_120c[0] == '\0') {
      TEasy_Panel::create_text
                ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)piVar1,0x241b,0x14,0x41,
                 0x1e0,0x14,10,0,0,0);
      if ((TTextPanel *)*piVar1 != (TTextPanel *)0x0) {
        iVar18 = TTextPanel::get_text_rect((TTextPanel *)*piVar1,&tStack_1224);
        if (iVar18 != 0) {
          pTStack_1214 = (TPicturePanel *)operator_new(0x11c);
          iStack_4._0_1_ = 1;
          if (pTStack_1214 == (TPicturePanel *)0x0) {
            this_00 = (TPicturePanel *)0x0;
          }
          else {
            this_00 = (TPicturePanel *)TPicturePanel::TPicturePanel(pTStack_1214);
          }
          iStack_4 = (uint)iStack_4._1_3_ << 8;
          param_1[1]._padding_ = (int)this_00;
          if (this_00 != (TPicturePanel *)0x0) {
            TPicturePanel::setup
                      (this_00,(TDrawArea *)param_1->_padding_,(TPanel *)param_1,
                       (tStack_1224.right - param_1->_padding_) + 3,0x42,0xf,0xe,s_circlep,0xc4e0,0,
                       1);
            iVar19 = 0;
            iVar17 = 0;
            iVar16 = 0;
            lVar15 = 10;
            lVar13 = 0x14;
            lVar11 = 0x1e0;
            lVar14 = 0x41;
            lVar4 = TPanel::xPosition((TPanel *)param_1[1]._padding_);
            iVar18 = param_1->_padding_;
            lVar12 = TPanel::width((TPanel *)param_1[1]._padding_);
            TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_
                       ,0x241c,(lVar4 - iVar18) + lVar12,lVar14,lVar11,lVar13,lVar15,iVar16,iVar17,
                       iVar19);
          }
        }
      }
    }
    else {
      pcVar5 = TPanel::get_string((TPanel *)param_1,0x241b);
      uVar7 = 0xffffffff;
      do {
        pcVar10 = pcVar5;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar10 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar3 != '\0');
      uVar7 = ~uVar7;
      pcVar5 = pcVar10 + -uVar7;
      pcVar10 = acStack_120c;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
      pcVar5 = TPanel::get_string((TPanel *)param_1,0x2424);
      uVar7 = 0xffffffff;
      do {
        pcVar10 = pcVar5;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar10 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar3 != '\0');
      uVar7 = ~uVar7;
      iVar18 = -1;
      pcVar5 = acStack_120c;
      do {
        pcVar9 = pcVar5;
        if (iVar18 == 0) break;
        iVar18 = iVar18 + -1;
        pcVar9 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar9;
      } while (cVar3 != '\0');
      pcVar5 = pcVar10 + -uVar7;
      pcVar10 = pcVar9 + -1;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
      uVar7 = 0xffffffff;
      pcVar5 = &s__;
      do {
        pcVar10 = pcVar5;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar10 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar3 != '\0');
      uVar7 = ~uVar7;
      iVar18 = -1;
      pcVar5 = acStack_120c;
      do {
        pcVar9 = pcVar5;
        if (iVar18 == 0) break;
        iVar18 = iVar18 + -1;
        pcVar9 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar9;
      } while (cVar3 != '\0');
      pcVar5 = pcVar10 + -uVar7;
      pcVar10 = pcVar9 + -1;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
      pcVar5 = TPanel::get_string((TPanel *)param_1,0x241c);
      uVar7 = 0xffffffff;
      do {
        pcVar10 = pcVar5;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar10 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar10;
      } while (cVar3 != '\0');
      uVar7 = ~uVar7;
      iVar18 = -1;
      pcVar5 = acStack_120c;
      do {
        pcVar9 = pcVar5;
        if (iVar18 == 0) break;
        iVar18 = iVar18 + -1;
        pcVar9 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar9;
      } while (cVar3 != '\0');
      pcVar5 = pcVar10 + -uVar7;
      pcVar10 = pcVar9 + -1;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar10 = pcVar10 + 1;
      }
      TEasy_Panel::create_text
                ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)piVar1,acStack_120c,0x14,
                 0x41,0x1e0,0x14,10,0,0,0);
    }
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x241d,
               0x14,0x55,0x1e0,0x14,10,0,0,0);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x2423,
               0x14,0x69,0x1e0,0x28,10,0,0,1);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,0x241e,
               0x14,0x96,0x5f,0x14,10,0,0,0);
    this = (TTextPanel *)param_1[1]._padding_;
    if (this != (TTextPanel *)0x0) {
      iVar18 = TTextPanel::get_text_rect(this,&tStack_1224);
      if (iVar18 != 0) {
        pcVar5 = TRegistry::RegGetAscii(Regs,0,s_PID);
        if (pcVar5 == (char *)0x0) {
          pcVar5 = s_00000_000_0000000_00000;
        }
        sprintf(acStack_100c,s__s,pcVar5);
        TEasy_Panel::create_text
                  ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,
                   acStack_100c,(tStack_1224.right - param_1->_padding_) + 4,0x96,200,0x14,0xb,0,0,0
                  );
      }
    }
    TPanel::get_string((TPanel *)param_1,0x241f,acStack_100c,0x1000);
    TEasy_Panel::create_text
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,
               acStack_100c,0x14,0xaf,0x1e0,0xdc,10,0,0,1);
    piVar1 = &param_1[1]._padding_;
    TEasy_Panel::create_button
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piVar1,0x2420,0,0x46,0x172,
               0xaa,0x1e,0,0,0);
    piVar2 = &param_1[1]._padding_;
    TEasy_Panel::create_button
              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piVar2,0x2421,0,0x118,0x172
               ,0xaa,0x1e,0,0,0);
    iVar18 = *piVar2;
    *(undefined4 *)(iVar18 + 0x298) = 0x1b;
    *(undefined4 *)(iVar18 + 0x29c) = 0;
    pTStack_122c = (TButtonPanel *)*piVar1;
    iStack_1228 = *piVar2;
    TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_122c,2);
    TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*piVar1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043b2dc
// Address: 0043b2dc
TribeAboutDialog * __thiscall FUN_0043b2dc(TribeAboutDialog *param_1,byte param_2)
{
  TribeAboutDialog::~TribeAboutDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043b2fe
// Address: 0043b2fe
void __fastcall FUN_0043b2fe(TDialogPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055cfa8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TribeAboutDialog::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0043b3fe
// Address: 0043b3fe
// [HELPER] s_About_Dialog: "About Dialog"
// [HELPER] s_Credits_Screen: "Credits Screen"
// [HELPER] s_Game_Screen: "Game Screen"
long __thiscall
FUN_0043b3fe(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  TPanel *pTVar1;
  int iVar2;
  TRIBE_Credits_Screen *this;
  long lVar3;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cfcb;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == 1) {
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      pTVar1 = TPanelSystem::panel(&panel_system,s_Game_Screen);
      if (pTVar1 != (TPanel *)0x0) {
        iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
        if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
          RGE_Base_Game::set_paused(rge_base_game,0,0);
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        (**(code **)(param_1->_padding_ + 0x14))(0);
        TPanelSystem::destroyPanel(&panel_system,s_About_Dialog);
        *unaff_FS_OFFSET = unaff_ESI;
        return 1;
      }
    }
    else {
      if (param_2 != (TPanel *)param_1[1]._padding_) goto LAB_0043b520;
      this = (TRIBE_Credits_Screen *)operator_new(0x8b8);
      uStack_4 = 0;
      if (this != (TRIBE_Credits_Screen *)0x0) {
        TRIBE_Credits_Screen::TRIBE_Credits_Screen(this);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Credits_Screen,0);
    }
    TPanelSystem::destroyPanel(&panel_system,s_About_Dialog);
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
LAB_0043b520:
  lVar3 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  *unaff_FS_OFFSET = uStack_c;
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_0043b545
// Address: 0043b545
void __fastcall FUN_0043b545(TEasy_Panel *param_1)
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

// Function: FUN_0043b555
// Address: 0043b555
// [HELPER] s_Config_Dialog: "Config Dialog"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TDialogPanel * __thiscall FUN_0043b555(TDialogPanel *param_1,int param_2,TEasy_Panel *param_3)
{
  float fVar1;
  ulong uVar2;
  bool bVar3;
  byte bVar4;
  long lVar5;
  char *pcVar6;
  TDrawArea *pTVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  TButtonPanel *pTVar11;
  int *piVar12;
  int *piVar13;
  undefined4 *unaff_FS_OFFSET;
  long lVar14;
  long lVar15;
  int iVar16;
  TButtonPanel *pTStack_34;
  int iStack_30;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055cfe8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel(param_1,s_Config_Dialog);
  param_1[1]._padding_ = param_2;
  param_1->_padding_ = (int)&TribeConfigDialog::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  iVar16 = 1;
  param_1[1]._padding_ = 0;
  uStack_4 = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  lVar5 = TEasy_Panel::get_popup_info_id(param_3);
  pcVar6 = TEasy_Panel::get_popup_info_file(param_3);
  lVar15 = 0x186;
  lVar14 = 600;
  pTVar7 = TPanel::renderArea((TPanel *)param_3);
  iVar16 = TDialogPanel::setup(param_1,pTVar7,(TPanel *)param_3,lVar14,lVar15,pcVar6,lVar5,iVar16);
  if (((iVar16 == 0) ||
      (iVar16 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TTextPanel **)&param_1[1]._padding_,0x24d7,0x67,10,0x18b,0x1e,1,1,1,0),
      iVar16 == 0)) ||
     (iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,
                          (TTextPanel **)&param_1[1]._padding_,0x24df,0x14,0x32,0x6e,0x1e,0xb,0,1,0)
     , iVar16 == 0)) goto LAB_0043c089;
  iVar16 = 0;
  do {
    if (iVar16 == 0) {
LAB_0043b74d:
      iVar10 = 0x24d8;
    }
    else if (iVar16 == 1) {
      iVar10 = 0x24d9;
    }
    else {
      if (iVar16 != 2) goto LAB_0043b74d;
      iVar10 = 0x24da;
    }
    iVar9 = iVar16 * 0x23 + 0x55;
    iVar8 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,
                       (TTextPanel **)(&param_1[1]._padding_ + iVar16),iVar10,0x37,iVar9,0x6e,0x1e,
                       0xb,0,1,0);
    if ((iVar8 == 0) ||
       (iVar9 = TEasy_Panel::create_radio_button
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TButtonPanel **)(&param_1[1]._padding_ + iVar16),0x14,iVar9,0x1e,0x1e,0,
                           0), iVar9 == 0)) goto LAB_0043c089;
    iVar16 = iVar16 + 1;
  } while (iVar16 < 3);
  piVar12 = &param_1[1]._padding_;
  iVar16 = 3;
  piVar13 = piVar12;
  do {
    TButtonPanel::set_radio_info((TButtonPanel *)*piVar13,(TButtonPanel **)piVar12,3);
    piVar13 = piVar13 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  if (rge_base_game->prog_mode == 5) {
    iVar16 = 3;
    do {
      TButtonPanel::set_disabled((TButtonPanel *)*piVar12,1);
      piVar12 = piVar12 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
  }
  fVar1 = rge_base_game->world->game_speed;
  bVar3 = fVar1 == _DAT_0056f740;
  param_1[1]._padding_ = (int)fVar1;
  if (bVar3) {
    pTVar11 = (TButtonPanel *)param_1[1]._padding_;
LAB_0043b849:
    TButtonPanel::set_radio_button(pTVar11);
  }
  else {
    if (fVar1 == _DAT_0056f744) {
      pTVar11 = (TButtonPanel *)param_1[1]._padding_;
      goto LAB_0043b849;
    }
    if (fVar1 == _DAT_0056f748) {
      pTVar11 = (TButtonPanel *)param_1[1]._padding_;
      goto LAB_0043b849;
    }
  }
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,
                      0x24db,0xa5,0x2d,0x6e,0x28,0xb,0,1,1);
  if (((iVar16 == 0) ||
      (iVar16 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TTextPanel **)&param_1[1]._padding_,0x24dc,0xbe,0x55,0x6e,0x14,0xb,0,1,0
                          ), iVar16 == 0)) ||
     (iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,
                          (TTextPanel **)&param_1[1]._padding_,0x24dd,0xbe,0xa5,0x6e,0x14,0xb,0,1,0)
     , iVar16 == 0)) goto LAB_0043c089;
  iVar16 = TEasy_Panel::create_vert_slider
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,
                      (TVerticalSliderPanel **)&param_1[1]._padding_,100,10,0x14,0xaa,0x55,0x14,100)
  ;
  if (iVar16 == 0) goto LAB_0043c089;
  if (rge_base_game->music_system == (TMusic_System *)0x0) {
    param_1[1]._padding_ = 99;
  }
  else {
    iVar16 = (int)((ulonglong)((longlong)rge_base_game->music_system->volume * -0x51eb851f) >> 0x20)
    ;
    param_1[1]._padding_ = (iVar16 >> 5) - (iVar16 >> 0x1f);
  }
  TScrollBarPanel::set_tab_pos((TScrollBarPanel *)param_1[1]._padding_,param_1[1]._padding_);
  param_1[1]._padding_ = param_1[1]._padding_;
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,
                      0x24de,0x131,0x2d,0x6e,0x28,0xb,0,1,1);
  if (((iVar16 == 0) ||
      (iVar16 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TTextPanel **)&param_1[1]._padding_,0x24dc,0x14a,0x55,0x6e,0x14,0xb,0,1,
                           0), iVar16 == 0)) ||
     (iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,
                          (TTextPanel **)&param_1[1]._padding_,0x24dd,0x14a,0xa5,0x6e,0x14,0xb,0,1,0
                         ), iVar16 == 0)) goto LAB_0043c089;
  iVar16 = TEasy_Panel::create_vert_slider
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,
                      (TVerticalSliderPanel **)&param_1[1]._padding_,100,10,0x14,0x136,0x55,0x14,100
                     );
  if (iVar16 == 0) goto LAB_0043c089;
  if (rge_base_game->sound_system == (TSound_Driver *)0x0) {
    param_1[1]._padding_ = 99;
  }
  else {
    lVar5 = TSound_Driver::get_volume(rge_base_game->sound_system);
    iVar16 = (int)((ulonglong)((longlong)lVar5 * -0x51eb851f) >> 0x20);
    param_1[1]._padding_ = (iVar16 >> 5) - (iVar16 >> 0x1f);
  }
  TScrollBarPanel::set_tab_pos((TScrollBarPanel *)param_1[1]._padding_,param_1[1]._padding_);
  param_1[1]._padding_ = param_1[1]._padding_;
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,
                      0x24f0,0x1bd,0x2d,0x6e,0x28,0xb,0,1,1);
  if (((iVar16 == 0) ||
      (iVar16 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TTextPanel **)&param_1[1]._padding_,0x24f1,0x1d6,0x55,0x6e,0x14,0xb,0,1,
                           0), iVar16 == 0)) ||
     (iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,
                          (TTextPanel **)&param_1[1]._padding_,0x24f2,0x1d6,0xa5,0x6e,0x14,0xb,0,1,0
                         ), iVar16 == 0)) goto LAB_0043c089;
  iVar16 = TEasy_Panel::create_vert_slider
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,
                      (TVerticalSliderPanel **)&param_1[1]._padding_,100,10,0x14,0x1c2,0x55,0x14,100
                     );
  if (iVar16 == 0) goto LAB_0043c089;
  uVar2 = rge_base_game->prog_info->mouse_scroll_interval;
  param_1[1]._padding_ = uVar2;
  TScrollBarPanel::set_tab_pos((TScrollBarPanel *)param_1[1]._padding_,uVar2 - 10);
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,
                      0x24e0,0x14,0xbe,200,0x1e,0xb,0,1,0);
  if (iVar16 == 0) goto LAB_0043c089;
  iVar16 = 0;
  do {
    if (iVar16 == 0) {
      iVar10 = 0x24e7;
    }
    else if (iVar16 == 1) {
      iVar10 = 0x24e8;
    }
    else if (iVar16 == 2) {
      iVar10 = 0x24e9;
    }
    iVar9 = iVar16 * 0x23 + 0xe1;
    iVar8 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,
                       (TTextPanel **)(&param_1[1]._padding_ + iVar16),iVar10,0x37,iVar9,100,0x1e,
                       0xb,0,1,0);
    if ((iVar8 == 0) ||
       (iVar9 = TEasy_Panel::create_radio_button
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TButtonPanel **)(&param_1[1]._padding_ + iVar16),0x14,iVar9,0x1e,0x1e,0,
                           0), iVar9 == 0)) goto LAB_0043c089;
    iVar16 = iVar16 + 1;
  } while (iVar16 < 3);
  piVar12 = &param_1[1]._padding_;
  iVar16 = 3;
  piVar13 = piVar12;
  do {
    TButtonPanel::set_radio_info((TButtonPanel *)*piVar13,(TButtonPanel **)piVar12,3);
    piVar13 = piVar13 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  iVar16 = *(int *)(*(int *)param_1->_padding_ + 0x2c);
  if (iVar16 == 0x280) {
    pTVar11 = (TButtonPanel *)*piVar12;
LAB_0043bc37:
    TButtonPanel::set_radio_button(pTVar11);
  }
  else {
    if (iVar16 == 800) {
      pTVar11 = (TButtonPanel *)param_1[1]._padding_;
      goto LAB_0043bc37;
    }
    if (iVar16 == 0x400) {
      pTVar11 = (TButtonPanel *)param_1[1]._padding_;
      goto LAB_0043bc37;
    }
  }
  iVar16 = TDrawSystem::IsModeAvail(*(TDrawSystem **)param_1->_padding_,0x280,0,8);
  if (iVar16 == 0) {
    TButtonPanel::set_disabled((TButtonPanel *)*piVar12,1);
  }
  iVar16 = TDrawSystem::IsModeAvail(*(TDrawSystem **)param_1->_padding_,800,0,8);
  if (iVar16 == 0) {
    TButtonPanel::set_disabled((TButtonPanel *)param_1[1]._padding_,1);
  }
  iVar16 = TDrawSystem::IsModeAvail(*(TDrawSystem **)param_1->_padding_,0x400,0,8);
  if (iVar16 == 0) {
    TButtonPanel::set_disabled((TButtonPanel *)param_1[1]._padding_,1);
  }
  iVar16 = TEasy_Panel::create_text
                     ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_,
                      0x24ea,0xaa,0xbe,0xd2,0x1e,0xb,0,1,0);
  if (iVar16 != 0) {
    iVar16 = 0;
    do {
      if (iVar16 == 0) {
        iVar10 = TEasy_Panel::create_text
                           ((TEasy_Panel *)param_1,(TPanel *)param_1,
                            (TTextPanel **)&param_1[1]._padding_,0x24eb,0xcd,0xe1,0x78,0x1e,0xb,0,1,
                            0);
      }
      else {
        iVar10 = TEasy_Panel::create_text
                           ((TEasy_Panel *)param_1,(TPanel *)param_1,
                            (TTextPanel **)(&param_1[1]._padding_ + iVar16),0x24ec,0xcd,
                            iVar16 * 0x23 + 0xe1,0x78,0x1e,0xb,0,1,0);
      }
      if ((iVar10 == 0) ||
         (iVar10 = TEasy_Panel::create_radio_button
                             ((TEasy_Panel *)param_1,(TPanel *)param_1,
                              (TButtonPanel **)(&param_1[1]._padding_ + iVar16),0xaa,
                              iVar16 * 0x23 + 0xe1,0x1e,0x1e,0,0), iVar10 == 0)) goto LAB_0043c089;
      iVar16 = iVar16 + 1;
    } while (iVar16 < 2);
    piVar12 = &param_1[1]._padding_;
    iVar16 = 2;
    piVar13 = piVar12;
    do {
      TButtonPanel::set_radio_info((TButtonPanel *)*piVar13,(TButtonPanel **)piVar12,2);
      piVar13 = piVar13 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    if (rge_base_game->prog_info->interface_style == 2) {
      pTVar11 = (TButtonPanel *)*piVar12;
    }
    else {
      pTVar11 = (TButtonPanel *)param_1[1]._padding_;
    }
    TButtonPanel::set_radio_button(pTVar11);
    iVar16 = TEasy_Panel::create_text
                       ((TEasy_Panel *)param_1,(TPanel *)param_1,
                        (TTextPanel **)&param_1[1]._padding_,0x24ed,0x14a,0xbe,0xd2,0x1e,0xb,0,1,0);
    if (iVar16 != 0) {
      iVar16 = 0;
      do {
        if (iVar16 == 0) {
          iVar10 = TEasy_Panel::create_text
                             ((TEasy_Panel *)param_1,(TPanel *)param_1,
                              (TTextPanel **)&param_1[1]._padding_,0x24ee,0x16d,0xe1,0x78,0x1e,0xb,0
                              ,1,0);
        }
        else {
          iVar10 = TEasy_Panel::create_text
                             ((TEasy_Panel *)param_1,(TPanel *)param_1,
                              (TTextPanel **)(&param_1[1]._padding_ + iVar16),0x24ef,0x16d,
                              iVar16 * 0x23 + 0xe1,0x78,0x1e,0xb,0,1,0);
        }
        if ((iVar10 == 0) ||
           (iVar10 = TEasy_Panel::create_radio_button
                               ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                (TButtonPanel **)(&param_1[1]._padding_ + iVar16),0x14a,
                                iVar16 * 0x23 + 0xe1,0x1e,0x1e,0,0), iVar10 == 0))
        goto LAB_0043c089;
        iVar16 = iVar16 + 1;
      } while (iVar16 < 2);
      piVar12 = &param_1[1]._padding_;
      iVar16 = 2;
      piVar13 = piVar12;
      do {
        TButtonPanel::set_radio_info((TButtonPanel *)*piVar13,(TButtonPanel **)piVar12,2);
        piVar13 = piVar13 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      if (rge_base_game->rollover == 0) {
        pTVar11 = (TButtonPanel *)param_1[1]._padding_;
      }
      else {
        pTVar11 = (TButtonPanel *)*piVar12;
      }
      TButtonPanel::set_radio_button(pTVar11);
      iVar16 = TEasy_Panel::create_text
                         ((TEasy_Panel *)param_1,(TPanel *)param_1,
                          (TTextPanel **)&param_1[1]._padding_,0x260d,0x1cc,0xbe,0xd2,0x1e,0xb,0,1,0
                         );
      if (iVar16 != 0) {
        iVar16 = 0;
        iVar10 = 0xe1;
        piVar12 = &param_1[1]._padding_;
        do {
          iVar9 = TEasy_Panel::create_text
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(piVar12 + -3),
                             iVar16 + 0x260e,0x1ef,iVar10,0x78,0x1e,0xb,0,1,0);
          if ((iVar9 == 0) ||
             (iVar9 = TEasy_Panel::create_radio_button
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piVar12,
                                 0x1cc,iVar10,0x1e,0x1e,0,0), iVar9 == 0)) goto LAB_0043c089;
          iVar9 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if (iVar9 != 0) {
            TButtonPanel::set_disabled((TButtonPanel *)*piVar12,1);
          }
          iVar10 = iVar10 + 0x23;
          iVar16 = iVar16 + 1;
          piVar12 = piVar12 + 1;
        } while (iVar10 < 0x14a);
        piVar12 = &param_1[1]._padding_;
        iVar16 = 3;
        do {
          TButtonPanel::set_radio_info
                    ((TButtonPanel *)*piVar12,(TButtonPanel **)&param_1[1]._padding_,3);
          piVar12 = piVar12 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        iVar16 = RGE_Base_Game::multiplayerGame(rge_base_game);
        if (iVar16 == 0) {
          bVar4 = RGE_Base_Game::pathFinding(rge_base_game);
        }
        else {
          bVar4 = RGE_Base_Game::mpPathFinding(rge_base_game);
        }
        if (bVar4 < 3) {
          TButtonPanel::set_radio_button((TButtonPanel *)(&param_1[1]._padding_)[bVar4]);
        }
        piVar12 = &param_1[1]._padding_;
        iVar16 = TEasy_Panel::create_button
                           ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piVar12,0xfa1,
                            0,0x78,0x159,0xaa,0x1e,0,0,0);
        if (iVar16 != 0) {
          piVar13 = &param_1[1]._padding_;
          iVar16 = TEasy_Panel::create_button
                             ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piVar13,
                              0xfa2,0,0x136,0x159,0xaa,0x1e,0,0,0);
          if (iVar16 != 0) {
            iVar16 = *piVar13;
            *(undefined4 *)(iVar16 + 0x298) = 0x1b;
            *(undefined4 *)(iVar16 + 0x29c) = 0;
            TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*piVar12);
            pTStack_34 = (TButtonPanel *)*piVar12;
            iStack_30 = *piVar13;
            TPanel::set_tab_order((TPanel *)param_1,(TPanel **)&pTStack_34,2);
          }
        }
      }
    }
  }
LAB_0043c089:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043c0be
// Address: 0043c0be
void __fastcall FUN_0043c0be(TDialogPanel *param_1)
{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d008;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TribeConfigDialog::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 2;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 2;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 3;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0043c2a5
// Address: 0043c2a5
// [HELPER] do_color_log: " "
// [HELPER] s_Config_Dialog: "Config Dialog"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Main_Menu: "Main Menu"
// [HELPER] s_Music_Volume: "Music Volume"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __thiscall
FUN_0043c2a5(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  RGE_Prog_Info *pRVar1;
  TMusic_System *this;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  TSound_Driver *this_00;
  long lVar6;
  long lVar7;
  int iVar8;
  float fStack_104;
  char acStack_100 [256];
  
  if (param_2 == (TPanel *)0x0) goto LAB_0043c80d;
  if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
    if (param_1[1]._padding_ == 0) {
      iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
      }
      iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
      if (iVar2 == 0) {
        rge_base_game->prog_info->interface_style = 1;
      }
      else {
        rge_base_game->prog_info->interface_style = 2;
      }
      (**(code **)(rge_base_game->_padding_ + 0x140))();
      iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
      if (iVar2 == 0) {
        rge_base_game->rollover = 0;
      }
      else {
        rge_base_game->rollover = 1;
      }
      iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if (iVar2 != 0) {
        iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
        if (iVar2 == 0) {
          iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
          if (iVar2 == 0) {
            iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
            if (iVar2 != 0) {
              RGE_Base_Game::setPathFinding(rge_base_game,'\x02');
              numberPathingIterations = 0x1d4c;
            }
          }
          else {
            RGE_Base_Game::setPathFinding(rge_base_game,'\x01');
            numberPathingIterations = 5000;
          }
        }
        else {
          RGE_Base_Game::setPathFinding(rge_base_game,'\0');
          numberPathingIterations = 0x9c4;
        }
      }
      if (rge_base_game->prog_mode != 5) {
        fStack_104 = 0.0;
        iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
        if (iVar2 == 0) {
          iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
          if (iVar2 == 0) {
            iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
            if (iVar2 != 0) {
              fStack_104 = 2.0;
            }
          }
          else {
            fStack_104 = 1.5;
          }
        }
        else {
          fStack_104 = 1.0;
        }
        if (((allow_user_commands != 0) && (fStack_104 != _DAT_0056f74c)) &&
           (fStack_104 != (float)param_1[1]._padding_)) {
          iVar2 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if (iVar2 != 0) {
            uVar3 = TCommunications_Handler::WhoAmI(comm);
            pcVar4 = TCommunications_Handler::GetPlayerName(comm,uVar3);
            pcVar5 = TPanel::get_string((TPanel *)param_1,0xbf3);
            sprintf(acStack_100,pcVar5,pcVar4);
            TCommunications_Handler::SendChatMsgAll(comm,acStack_100);
          }
          TRIBE_Command::command_game_speed
                    ((TRIBE_Command *)rge_base_game->world->commands,fStack_104);
          iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
          if (iVar2 != 0) {
            RGE_Base_Game::set_game_speed(rge_base_game,fStack_104);
          }
        }
      }
      if (param_1[1]._padding_ != param_1[1]._padding_) {
        pRVar1 = rge_base_game->prog_info;
        if (param_1[1]._padding_ < 99) {
          if (pRVar1->use_music == 0) {
            pRVar1->use_music = 1;
            TRegistry::RegSetInt(Regs,1,s_Music_Volume,param_1[1]._padding_ * 100);
            (**(code **)(rge_base_game->_padding_ + 0x58))();
            this = rge_base_game->music_system;
            if (this != (TMusic_System *)0x0) {
              if (this->music_type == '\x01') {
                iVar2 = this->track_count;
                iVar8 = 5;
              }
              else {
                if (this->music_type != '\x02') goto LAB_0043c5dd;
                iVar2 = this->track_count;
                iVar8 = 1;
              }
              TMusic_System::play_tracks(this,iVar8,iVar2,1,0,0);
            }
          }
        }
        else if (pRVar1->use_music != 0) {
          pRVar1->use_music = 0;
          (**(code **)(rge_base_game->_padding_ + 0x5c))();
        }
LAB_0043c5dd:
        if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
          TSound_Driver::set_volume(rge_base_game->sound_system,param_1[1]._padding_ * -100,1);
        }
      }
      iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
      if (iVar2 == 0) {
        iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
        if (iVar2 == 0) {
          iVar2 = TButtonPanel::get_state((TButtonPanel *)param_1[1]._padding_);
          if (iVar2 == 0) goto LAB_0043c64b;
          lVar7 = 0x400;
          lVar6 = 0x300;
        }
        else {
          lVar7 = 800;
          lVar6 = 600;
        }
      }
      else {
LAB_0043c64b:
        lVar7 = 0x280;
        lVar6 = 0x1e0;
      }
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      (**(code **)(param_1->_padding_ + 0x14))(0);
      TEasy_Panel::prepare_for_close(param_1);
      if (do_color_log == '\0') {
        RGE_Base_Game::set_screen_size(rge_base_game,lVar7,lVar6);
      }
      goto LAB_0043c90b;
    }
  }
  else {
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
      return 1;
    }
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
      return 1;
    }
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 1)) {
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      return 1;
    }
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 4)) {
      param_1[1]._padding_ = param_4;
      if (rge_base_game->music_system == (TMusic_System *)0x0) {
        return 1;
      }
      TMusic_System::set_volume(rge_base_game->music_system,param_4 * -100,1);
      this_00 = rge_base_game->sound_system;
      if (this_00 == (TSound_Driver *)0x0) {
        return 1;
      }
      param_4 = param_1[1]._padding_;
LAB_0043c7cb:
      TSound_Driver::set_volume(this_00,param_4 * -100,1);
      return 1;
    }
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 4)) {
      param_1[1]._padding_ = param_4;
      this_00 = rge_base_game->sound_system;
      if (this_00 == (TSound_Driver *)0x0) {
        return 1;
      }
      goto LAB_0043c7cb;
    }
    if ((param_2 == (TPanel *)param_1[1]._padding_) && (param_3 == 4)) {
      pRVar1 = rge_base_game->prog_info;
      pRVar1->mouse_scroll_interval = param_4 + 10;
      pRVar1->key_scroll_interval = param_4 + 10;
LAB_0043c80d:
      lVar6 = TPanel::action((TPanel *)param_1,param_2,param_3,param_4,param_5);
      return lVar6;
    }
    if ((param_2 != (TPanel *)param_1[1]._padding_) || (param_3 != 1)) goto LAB_0043c80d;
    if (rge_base_game->music_system != (TMusic_System *)0x0) {
      TMusic_System::set_volume(rge_base_game->music_system,param_1[1]._padding_ * -100,1);
    }
    if (rge_base_game->sound_system != (TSound_Driver *)0x0) {
      TSound_Driver::set_volume(rge_base_game->sound_system,param_1[1]._padding_ * -100,1);
    }
    pRVar1 = rge_base_game->prog_info;
    pRVar1->mouse_scroll_interval = param_1[1]._padding_;
    pRVar1->key_scroll_interval = param_1[1]._padding_;
    if (param_1[1]._padding_ == 0) {
      iVar2 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar2 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
      }
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      (**(code **)(param_1->_padding_ + 0x14))(0);
      goto LAB_0043c90b;
    }
  }
  TPanelSystem::setCurrentPanel(&panel_system,s_Main_Menu,0);
LAB_0043c90b:
  TPanelSystem::destroyPanel(&panel_system,s_Config_Dialog);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0043c92b
// Address: 0043c92b
// [HELPER] s_Diplomacy_Dialog: "Diplomacy Dialog"
// [HELPER] s__ld: "%ld"
// [HELPER] s_dlg_plbn_shp: "dlg_plbn.shp"
// [HELPER] s_tradicon_shp: "tradicon.shp"
TribeDiplomacyDialog * __thiscall FUN_0043c92b(TribeDiplomacyDialog *param_1,TEasy_Panel *param_2)
{
  TButtonPanel **ppTVar1;
  TTextPanel **ppTVar2;
  RGE_Game_World *pRVar3;
  TButtonPanel *pTVar4;
  bool bVar5;
  byte bVar6;
  uchar uVar7;
  short sVar8;
  TTextPanel **ppTVar9;
  long lVar10;
  char *pcVar11;
  TDrawArea *pTVar12;
  TShape *pTVar13;
  undefined4 uVar14;
  int iVar15;
  RGE_Player *pRVar16;
  int iVar17;
  undefined4 extraout_ECX;
  uint uVar18;
  TButtonPanel **ppTVar19;
  TButtonPanel **ppTVar20;
  undefined4 *unaff_FS_OFFSET;
  long lVar21;
  float fVar22;
  long lVar23;
  float fVar24;
  uchar uVar25;
  RGE_Static_Object *pRVar26;
  TButtonPanel **ppTStack_130;
  int iStack_12c;
  int iStack_128;
  int iStack_120;
  TButtonPanel **ppTStack_11c;
  uint uStack_118;
  int iStack_110;
  undefined1 auStack_100 [4];
  char acStack_fc [100];
  TButtonPanel *apTStack_98 [35];
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d047;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel((TDialogPanel *)param_1,s_Diplomacy_Dialog);
  param_1->_padding_ = (int)&TribeDiplomacyDialog::_vftable_;
  iStack_4 = 0;
  ppTVar9 = param_1->playerName;
  iVar17 = 8;
  do {
    ppTVar9[-8] = (TTextPanel *)0x0;
    *ppTVar9 = (TTextPanel *)0x0;
    ppTVar9[8] = (TTextPanel *)0x0;
    ppTVar9[0x10] = (TTextPanel *)0x0;
    ppTVar9[0x19] = (TTextPanel *)0x0;
    ppTVar9[0x29] = (TTextPanel *)0x0;
    ppTVar9[0x21] = (TTextPanel *)0x0;
    ppTVar9[0x31] = (TTextPanel *)0x0;
    ppTVar9[0x60] = (TTextPanel *)0x0;
    ppTVar9[0x68] = (TTextPanel *)0x0;
    ppTVar9[0x70] = (TTextPanel *)0x0;
    ppTVar9[0x78] = (TTextPanel *)0x0;
    ppTVar9 = ppTVar9 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  ppTVar20 = param_1->allyButton;
  for (iVar17 = 0x18; iVar17 != 0; iVar17 = iVar17 + -1) {
    *ppTVar20 = (TButtonPanel *)0x0;
    ppTVar20 = ppTVar20 + 1;
  }
  iVar17 = 1;
  param_1->allianceButton = (TButtonPanel *)0x0;
  param_1->okButton = (TButtonPanel *)0x0;
  param_1->cancelButton = (TButtonPanel *)0x0;
  param_1->clearButton = (TButtonPanel *)0x0;
  param_1->help_button = (TButtonPanel *)0x0;
  param_1->needMarket = (TTextPanel *)0x0;
  param_1->buttonPics = (TShape *)0x0;
  param_1->backgroundPics = (TShape *)0x0;
  param_1->playerWood = (TTextPanel *)0x0;
  param_1->playerStone = (TTextPanel *)0x0;
  param_1->playerGold = (TTextPanel *)0x0;
  param_1->playerFood = (TTextPanel *)0x0;
  param_1->woodTotal = 0.0;
  param_1->stoneTotal = 0.0;
  param_1->foodTotal = 0.0;
  param_1->goldTotal = 0.0;
  param_1->tribute_flag = 0;
  lVar10 = TEasy_Panel::get_popup_info_id(param_2);
  pcVar11 = TEasy_Panel::get_popup_info_file(param_2);
  lVar23 = 0x195;
  lVar21 = 0x271;
  pTVar12 = TPanel::renderArea((TPanel *)param_2);
  iVar17 = TDialogPanel::setup((TDialogPanel *)param_1,pTVar12,(TPanel *)param_2,lVar21,lVar23,
                               pcVar11,lVar10,iVar17);
  if (iVar17 != 0) {
    pTVar13 = (TShape *)operator_new(0x20);
    iStack_4._0_1_ = 1;
    if (pTVar13 == (TShape *)0x0) {
      pTVar13 = (TShape *)0x0;
    }
    else {
      pTVar13 = (TShape *)TShape::TShape(pTVar13,s_tradicon_shp,0xc62c);
    }
    iStack_4._0_1_ = 0;
    param_1->buttonPics = pTVar13;
    if (pTVar13 != (TShape *)0x0) {
      pTVar13 = (TShape *)operator_new(0x20);
      iStack_4._0_1_ = 2;
      if (pTVar13 == (TShape *)0x0) {
        pTVar13 = (TShape *)0x0;
      }
      else {
        pTVar13 = (TShape *)TShape::TShape(pTVar13,s_dlg_plbn_shp,0xc63a);
      }
      iStack_4 = (uint)iStack_4._1_3_ << 8;
      param_1->backgroundPics = pTVar13;
      if (pTVar13 != (TShape *)0x0) {
        RGE_Base_Game::get_font(rge_base_game,1);
        iVar17 = TEasy_Panel::create_text
                           ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title,0x267b,0x48,5,
                            500,0x1e,1,1,1,0);
        if (((((iVar17 != 0) &&
              (iVar17 = TEasy_Panel::create_text
                                  ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->needMarket,
                                   0x2687,0x1b8,0x6e,0xaf,0x3c,0xb,1,1,1), iVar17 != 0)) &&
             (iVar17 = TEasy_Panel::create_text
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title + 1,0x2686
                                  ,5,0x32,0x82,0x1e,0xb,0,1,0), iVar17 != 0)) &&
            ((iVar17 = TEasy_Panel::create_text
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title + 2,0x267c
                                  ,0x89,0x32,0x50,0x1e,0xb,0,1,0), iVar17 != 0 &&
             (iVar17 = TEasy_Panel::create_text
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title + 3,0x267d
                                  ,0xeb,0x32,0x46,0x1e,0xb,0,1,0), iVar17 != 0)))) &&
           ((iVar17 = TEasy_Panel::create_text
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title + 4,0x267e,
                                 0x122,0x32,0x46,0x1e,0xb,0,1,0), iVar17 != 0 &&
            (iVar17 = TEasy_Panel::create_text
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title + 5,0x267f,
                                 0x168,0x32,0x46,0x1e,0xb,0,1,0), iVar17 != 0)))) {
          RGE_Base_Game::get_player(rge_base_game);
          uVar14 = __ftol();
          pcVar11 = TPanel::get_string((TPanel *)param_1,0x2680);
          sprintf(acStack_fc,pcVar11,uVar14);
          iVar17 = TEasy_Panel::create_text
                             ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title + 6,acStack_fc
                              ,0x1b8,0x32,0xb4,0x1e,0xb,0,1,0);
          if ((iVar17 != 0) &&
             (iVar17 = TEasy_Panel::create_text
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,param_1->title + 7,0x2681
                                  ,0x13e,0x14a,300,0x1e,0xb,0,1,0), iVar17 != 0)) {
            param_1->cur_player_row = -1;
            iStack_128 = 1;
            pRVar3 = rge_base_game->world;
            if (pRVar3->player_num != 1 && -1 < pRVar3->player_num + -1) {
              ppTStack_130 = param_1->woodTributeButton;
              ppTStack_11c = param_1->allyButton;
              iStack_110 = 0;
              iStack_12c = 0x50;
              do {
                iVar17 = (-0x530 - (int)param_1) + (int)ppTStack_130;
                GetPaletteEntries(param_1->_padding_,
                                  *(undefined1 *)
                                   (*(int *)(*(int *)(iVar17 + (int)pRVar3->players) + 0x108) + 0x25
                                   ),1,auStack_100);
                if (((rge_base_game->prog_mode == 5) || (iStack_128 == pRVar3->curr_player)) ||
                   (*(char *)(*(int *)(iVar17 + (int)pRVar3->players) + 0x80) != '\0')) {
                  bVar5 = true;
                }
                else {
                  bVar5 = false;
                }
                if (iStack_128 == pRVar3->curr_player) {
                  param_1->cur_player_row = iStack_128 + -1;
                }
                bVar6 = 0;
                if (*(char *)(*(int *)(iVar17 + (int)pRVar3->players) + 0x80) == '\x02') {
LAB_0043ce5d:
                  bVar6 = 1;
                }
                else {
                  iVar15 = RGE_Base_Game::multiplayerGame(rge_base_game);
                  if (iVar15 != 0) {
                    iStack_120 = 0;
                    uVar18 = 1;
                    iVar15 = RGE_Base_Game::numberPlayers(rge_base_game);
                    if (0 < iVar15) {
                      do {
                        iVar15 = RGE_Base_Game::playerID(rge_base_game,uVar18);
                        if ((iVar15 == iStack_128) &&
                           ((iVar15 = TCommunications_Handler::GetPlayerHumanity(comm,uVar18),
                            iVar15 == 2 || (iVar15 == 4)))) {
                          iStack_120 = iVar15;
                        }
                        uVar18 = uVar18 + 1;
                        iVar15 = RGE_Base_Game::numberPlayers(rge_base_game);
                      } while ((int)uVar18 <= iVar15);
                    }
                    if ((iStack_120 != 2) && (iStack_120 != 4)) goto LAB_0043ce5d;
                  }
                }
                iVar15 = TEasy_Panel::create_text
                                   ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                    (TTextPanel **)(ppTStack_130 + -0x21),
                                    *(char **)(*(int *)(iVar17 + (int)pRVar3->players) + 0x44),5,
                                    iStack_12c,0x82,0x1e,(-(uint)bVar6 & 0xfffffffd) + 0xb,0,1,0);
                if (iVar15 == 0) goto LAB_0043d694;
                (**(code **)(rge_base_game->_padding_ + 0x28))
                          (0x69,*(undefined1 *)(*(int *)(iVar17 + (int)pRVar3->players) + 0x105),0,
                           acStack_fc,100);
                iVar17 = TEasy_Panel::create_text
                                   ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                    (TTextPanel **)(ppTStack_130 + -0x11),acStack_fc,0x89,iStack_12c
                                    ,100,0x1e,0xb,0,1,0);
                if (iVar17 == 0) goto LAB_0043d694;
                if (iStack_128 != pRVar3->curr_player) {
                  iVar17 = TEasy_Panel::create_radio_button
                                     ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTStack_11c,0xf0,
                                      iStack_12c,0x1e,0x1e,0,0);
                  if (iVar17 == 0) goto LAB_0043d694;
                  TPanel::set_help_info((TPanel *)*ppTStack_11c,0x7684,-1);
                  iVar17 = TEasy_Panel::create_radio_button
                                     ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTStack_11c + 1,
                                      0x136,iStack_12c,0x1e,0x1e,0,0);
                  if (iVar17 == 0) goto LAB_0043d694;
                  TPanel::set_help_info((TPanel *)ppTStack_11c[1],0x7685,-1);
                  iVar17 = TEasy_Panel::create_radio_button
                                     ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTStack_11c + 2,
                                      0x17c,iStack_12c,0x1e,0x1e,0,0);
                  if (iVar17 == 0) goto LAB_0043d694;
                  TPanel::set_help_info((TPanel *)ppTStack_11c[2],0x7686,-1);
                  if (iStack_110 < iStack_110 + 3) {
                    iVar17 = (iStack_110 + 3) - iStack_110;
                    ppTVar20 = ppTStack_11c;
                    do {
                      TButtonPanel::set_radio_info(*ppTVar20,ppTStack_11c,3);
                      if (rge_base_game->prog_mode == 5) {
                        TButtonPanel::set_disabled(*ppTVar20,1);
                      }
                      ppTVar20 = ppTVar20 + 1;
                      iVar17 = iVar17 + -1;
                    } while (iVar17 != 0);
                  }
                  iVar17 = iStack_128;
                  pRVar16 = RGE_Base_Game::get_player(rge_base_game);
                  uVar7 = RGE_Player::relation(pRVar16,iVar17);
                  if ((iStack_128 == pRVar3->curr_player) || (uVar7 == '\0')) {
                    TButtonPanel::set_radio_button(*ppTStack_11c);
                  }
                  else if (uVar7 == '\x01') {
                    TButtonPanel::set_radio_button(ppTStack_11c[1]);
                  }
                  else {
                    TButtonPanel::set_radio_button(ppTStack_11c[2]);
                  }
                }
                if (!bVar5) {
                  iVar17 = TEasy_Panel::create_button
                                     ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTStack_130,-1,0,
                                      0x1b8,iStack_12c,0x28,0x1e,0xb,0,0);
                  if (iVar17 == 0) goto LAB_0043d694;
                  ppTVar20 = ppTStack_130 + 8;
                  iVar17 = TEasy_Panel::create_button
                                     ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20,-1,0,0x1e0,
                                      iStack_12c,0x28,0x1e,0xb,0,0);
                  if (iVar17 == 0) goto LAB_0043d694;
                  ppTVar19 = ppTStack_130 + -8;
                  iVar17 = TEasy_Panel::create_button
                                     ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar19,-1,0,0x208,
                                      iStack_12c,0x28,0x1e,0xb,0,0);
                  if (iVar17 == 0) goto LAB_0043d694;
                  ppTVar1 = ppTStack_130 + 0x10;
                  iVar17 = TEasy_Panel::create_button
                                     ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar1,-1,0,0x230,
                                      iStack_12c,0x28,0x1e,0xb,0,0);
                  if (iVar17 == 0) goto LAB_0043d694;
                  TButtonPanel::set_picture(*ppTStack_130,0,param_1->buttonPics,0);
                  TButtonPanel::set_picture(*ppTVar20,0,param_1->buttonPics,2);
                  TButtonPanel::set_picture(*ppTVar19,0,param_1->buttonPics,3);
                  TButtonPanel::set_picture(*ppTVar1,0,param_1->buttonPics,1);
                  TButtonPanel::setDrawType(*ppTStack_130,DrawPictureAndText);
                  TButtonPanel::setDrawType(*ppTVar20,DrawPictureAndText);
                  TButtonPanel::setDrawType(*ppTVar19,DrawPictureAndText);
                  TButtonPanel::setDrawType(*ppTVar1,DrawPictureAndText);
                  TPanel::set_help_info((TPanel *)*ppTStack_130,0x7687,-1);
                  TPanel::set_help_info((TPanel *)*ppTVar20,0x7688,-1);
                  TPanel::set_help_info((TPanel *)*ppTVar19,0x7689,-1);
                  TPanel::set_help_info((TPanel *)*ppTVar1,0x768a,-1);
                }
                iStack_110 = iStack_110 + 3;
                ppTStack_11c = ppTStack_11c + 3;
                iStack_12c = iStack_12c + 0x1e;
                ppTStack_130 = ppTStack_130 + 1;
                bVar5 = iStack_128 < pRVar3->player_num + -1;
                iStack_128 = iStack_128 + 1;
              } while (bVar5);
            }
            ppTVar20 = &param_1->allianceButton;
            iVar17 = TEasy_Panel::create_check_box
                               ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20,0x11a,0x147,0x1e,
                                0x1e,0,0);
            if (iVar17 != 0) {
              iVar17 = (*ppTVar20)->_padding_;
              pRVar16 = RGE_Base_Game::get_player(rge_base_game);
              uVar7 = RGE_Player::get_allied_victory(pRVar16);
              (**(code **)(iVar17 + 0xe0))
                        (CONCAT31((int3)((uint)extraout_ECX >> 8),uVar7) & 0xffff00ff);
              TPanel::set_help_info((TPanel *)*ppTVar20,0x768c,-1);
              if (rge_base_game->prog_mode == 5) {
                TButtonPanel::set_disabled(*ppTVar20,1);
              }
              if (rge_base_game->prog_mode != 5) {
                iVar17 = TEasy_Panel::create_button
                                   ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->okButton,
                                    0xfa1,0,10,0x16f,0xbe,0x1e,0,0,0);
                if (iVar17 == 0) goto LAB_0043d694;
                TPanel::set_help_info((TPanel *)param_1->okButton,0x7531,-1);
                iVar17 = TEasy_Panel::create_button
                                   ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->clearButton,
                                    0x2683,0,0xd7,0x16f,0xbe,0x1e,0,0,0);
                if (iVar17 == 0) goto LAB_0043d694;
                TPanel::set_help_info((TPanel *)param_1->clearButton,0x768b,-1);
              }
              ppTVar20 = &param_1->cancelButton;
              iVar17 = TEasy_Panel::create_button
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar20,0xfa2,0,0x1a4,
                                  0x16f,0xbe,0x1e,0,0,0);
              if (iVar17 != 0) {
                TPanel::set_help_info((TPanel *)*ppTVar20,0x7532,-1);
                pTVar4 = *ppTVar20;
                pTVar4->hotkey = 0x1b;
                pTVar4->hotkey_shift = 0;
                iVar17 = TEasy_Panel::create_button
                                   ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->help_button,
                                    0xfa9,0,500,0x147,0x1e,0x1e,0,0,0);
                if (iVar17 != 0) {
                  RGE_Base_Game::get_player(rge_base_game);
                  uVar14 = __ftol();
                  sprintf(acStack_fc,s__ld,uVar14);
                  iVar17 = TEasy_Panel::create_text
                                     ((TEasy_Panel *)param_1,(TPanel *)param_1,&param_1->playerWood,
                                      acStack_fc,0x1b8,param_1->cur_player_row * 0x1e + 0x50,0x28,
                                      0x1e,0xb,0,1,0);
                  if (iVar17 != 0) {
                    RGE_Base_Game::get_player(rge_base_game);
                    uVar14 = __ftol();
                    sprintf(acStack_fc,s__ld,uVar14);
                    iVar17 = TEasy_Panel::create_text
                                       ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                        &param_1->playerFood,acStack_fc,0x1e0,
                                        param_1->cur_player_row * 0x1e + 0x50,0x28,0x1e,0xb,0,1,0);
                    if (iVar17 != 0) {
                      RGE_Base_Game::get_player(rge_base_game);
                      uVar14 = __ftol();
                      sprintf(acStack_fc,s__ld,uVar14);
                      ppTVar9 = &param_1->playerGold;
                      iVar17 = TEasy_Panel::create_text
                                         ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar9,
                                          acStack_fc,0x208,param_1->cur_player_row * 0x1e + 0x50,
                                          0x28,0x1e,0xb,0,1,0);
                      if (iVar17 != 0) {
                        RGE_Base_Game::get_player(rge_base_game);
                        uVar14 = __ftol();
                        sprintf(acStack_fc,s__ld,uVar14);
                        ppTVar2 = &param_1->playerStone;
                        iVar17 = TEasy_Panel::create_text
                                           ((TEasy_Panel *)param_1,(TPanel *)param_1,ppTVar2,
                                            acStack_fc,0x230,param_1->cur_player_row * 0x1e + 0x50,
                                            0x28,0x1e,0xb,0,1,0);
                        if (iVar17 != 0) {
                          pRVar26 = (RGE_Static_Object *)0x0;
                          uVar25 = '\x02';
                          uVar7 = '\x01';
                          fVar24 = -1.0;
                          fVar22 = -1.0;
                          lVar10 = 0x54;
                          pRVar16 = RGE_Base_Game::get_player(rge_base_game);
                          pRVar26 = RGE_Object_List::find_by_master_id
                                              (pRVar16->objects,lVar10,fVar22,fVar24,uVar7,uVar25,
                                               pRVar26);
                          if (pRVar26 == (RGE_Static_Object *)0x0) {
                            param_1->tribute_flag = 0;
                            (**(code **)(param_1->needMarket->_padding_ + 0x14))(1);
                            (**(code **)(param_1->title[6]->_padding_ + 0x14))(0);
                            (**(code **)(param_1->playerWood->_padding_ + 0x14))(0);
                            (**(code **)(param_1->playerFood->_padding_ + 0x14))(0);
                            (**(code **)((*ppTVar9)->_padding_ + 0x14))(0);
                            iVar17 = (*ppTVar2)->_padding_;
                          }
                          else {
                            param_1->tribute_flag = 1;
                            (**(code **)(param_1->needMarket->_padding_ + 0x14))(0);
                            (**(code **)(param_1->title[6]->_padding_ + 0x14))(1);
                            (**(code **)(param_1->playerWood->_padding_ + 0x14))(1);
                            (**(code **)(param_1->playerFood->_padding_ + 0x14))(1);
                            (**(code **)((*ppTVar9)->_padding_ + 0x14))(1);
                            iVar17 = (*ppTVar2)->_padding_;
                          }
                          (**(code **)(iVar17 + 0x14))(pRVar26 != (RGE_Static_Object *)0x0);
                          sVar8 = 0x1e;
                          pRVar16 = RGE_Base_Game::get_player(rge_base_game);
                          sVar8 = TRIBE_Player_Tech::get_tech_state
                                            ((TRIBE_Player_Tech *)pRVar16[1]._padding_,sVar8);
                          if (sVar8 == 3) {
                            (**(code **)(param_1->title[6]->_padding_ + 0x14))(0);
                          }
                          TribeDiplomacyDialog::check_gold(param_1);
                          TribeDiplomacyDialog::check_wood(param_1);
                          TribeDiplomacyDialog::check_food(param_1);
                          TribeDiplomacyDialog::check_stone(param_1);
                          TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1->okButton);
                          pTVar4 = param_1->okButton;
                          if (pTVar4 != (TButtonPanel *)0x0) {
                            apTStack_98[0] = pTVar4;
                          }
                          uStack_118 = (uint)(pTVar4 != (TButtonPanel *)0x0);
                          if (param_1->clearButton != (TButtonPanel *)0x0) {
                            apTStack_98[uStack_118] = param_1->clearButton;
                            uStack_118 = uStack_118 + 1;
                          }
                          if (param_1->cancelButton != (TButtonPanel *)0x0) {
                            apTStack_98[uStack_118] = param_1->cancelButton;
                            uStack_118 = uStack_118 + 1;
                          }
                          TPanel::set_tab_order
                                    ((TPanel *)param_1,(TPanel **)apTStack_98,(short)uStack_118);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0043d694:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043d6b1
// Address: 0043d6b1
TribeDiplomacyDialog * __thiscall FUN_0043d6b1(TribeDiplomacyDialog *param_1,byte param_2)
{
  TribeDiplomacyDialog::~TribeDiplomacyDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043d6de
// Address: 0043d6de
void __fastcall FUN_0043d6de(TDialogPanel *param_1)
{
  TShape *pTVar1;
  int *piVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d068;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TribeDiplomacyDialog::_vftable_;
  uStack_4 = 0;
  piVar2 = &param_1[1]._padding_;
  iVar3 = 8;
  do {
    if ((undefined4 *)((TDialogPanel *)(piVar2 + -0x10))->_padding_ != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)((TDialogPanel *)(piVar2 + -0x10))->_padding_)(1);
    }
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    if ((undefined4 *)piVar2[-8] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[-8])(1);
    }
    if ((undefined4 *)piVar2[8] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[8])(1);
    }
    if ((undefined4 *)piVar2[0x19] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[0x19])(1);
    }
    if ((undefined4 *)piVar2[0x21] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[0x21])(1);
    }
    if ((undefined4 *)piVar2[0x11] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[0x11])(1);
    }
    if ((undefined4 *)piVar2[0x29] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar2[0x29])(1);
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar3 = 0x18;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  pTVar1 = (TShape *)param_1[1]._padding_;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = (TShape *)param_1[1]._padding_;
  if (pTVar1 != (TShape *)0x0) {
    TShape::~TShape(pTVar1);
    operator_delete(pTVar1);
  }
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0043d89d
// Address: 0043d89d
// [HELPER] s_: ""
// [HELPER] s_Diplomacy_Dialog: "Diplomacy Dialog"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s__ld: "%ld"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __thiscall
FUN_0043d89d(TribeDiplomacyDialog *param_1,TButtonPanel *param_2,int param_3,ulong param_4,
            ulong param_5)
{
  RGE_Command *this;
  bool bVar1;
  float fVar2;
  byte bVar3;
  uchar uVar4;
  byte bVar5;
  RGE_Player *pRVar6;
  uint uVar7;
  RGE_Game_World *pRVar9;
  int iVar10;
  undefined4 uVar11;
  TButtonPanel **ppTVar12;
  long lVar13;
  float *pfVar14;
  int iVar15;
  ushort uVar16;
  TButtonPanel **ppTStack_108;
  RGE_Command *pRStack_104;
  undefined1 auStack_100 [256];
  int iVar8;
  
  if ((param_2 == (TButtonPanel *)0x0) || (param_3 != 1)) {
LAB_0043de3c:
    lVar13 = TPanel::action((TPanel *)param_1,(TPanel *)param_2,param_3,param_4,param_5);
    return lVar13;
  }
  if (param_2 == param_1->okButton) {
    this = rge_base_game->world->commands;
    pRStack_104 = this;
    if (allow_user_commands != 0) {
      pRVar6 = RGE_Base_Game::get_player(rge_base_game);
      bVar3 = RGE_Player::get_allied_victory(pRVar6);
      uVar7 = TButtonPanel::get_state(param_1->allianceButton);
      if (uVar7 != bVar3) {
        iVar8 = TButtonPanel::get_state(param_1->allianceButton);
        uVar4 = (uchar)iVar8;
        pRVar6 = RGE_Base_Game::get_player(rge_base_game);
        TRIBE_Command::command_allied_victory((TRIBE_Command *)this,pRVar6->id,uVar4);
      }
    }
    pRVar9 = rge_base_game->world;
    if (pRVar9->player_num != 1 && -1 < pRVar9->player_num + -1) {
      pfVar14 = param_1->woodTributeAmount;
      ppTVar12 = param_1->allyButton;
      iVar8 = 1;
      do {
        ppTStack_108 = ppTVar12;
        if ((iVar8 != pRVar9->curr_player) && (*ppTVar12 != (TButtonPanel *)0x0)) {
          iVar10 = TButtonPanel::get_state(*ppTVar12);
          if (iVar10 == 1) {
            bVar3 = 0;
          }
          else {
            iVar10 = TButtonPanel::get_state(ppTVar12[1]);
            bVar3 = (-(iVar10 != 1) & 2U) + 1;
          }
          if (allow_user_commands != 0) {
            iVar10 = iVar8;
            pRVar6 = RGE_Base_Game::get_player(rge_base_game);
            bVar5 = RGE_Player::relation(pRVar6,iVar10);
            if (bVar5 != bVar3) {
              uVar16 = (ushort)bVar3;
              iVar10 = iVar8;
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              TRIBE_Command::command_relation
                        ((TRIBE_Command *)pRStack_104,pRVar6->id,(short)iVar10,uVar16);
            }
            if (_DAT_0056f884 < pfVar14[-0x18]) {
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              iVar10 = pRVar6->_padding_;
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              (**(code **)(iVar10 + 0xf8))(iVar8,3,pfVar14[-0x18],pRVar6->attributes[0x2e]);
            }
            if (_DAT_0056f884 < *pfVar14) {
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              iVar10 = pRVar6->_padding_;
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              (**(code **)(iVar10 + 0xf8))(iVar8,1,*pfVar14,pRVar6->attributes[0x2e]);
            }
            if (_DAT_0056f884 < pfVar14[-0x10]) {
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              iVar10 = pRVar6->_padding_;
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              (**(code **)(iVar10 + 0xf8))(iVar8,0,pfVar14[-0x10],pRVar6->attributes[0x2e]);
            }
            if (_DAT_0056f884 < pfVar14[-8]) {
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              iVar10 = pRVar6->_padding_;
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              (**(code **)(iVar10 + 0xf8))(iVar8,2,pfVar14[-8],pRVar6->attributes[0x2e]);
            }
          }
        }
        ppTVar12 = ppTStack_108 + 3;
        pRVar9 = rge_base_game->world;
        pfVar14 = pfVar14 + 1;
        bVar1 = iVar8 < pRVar9->player_num + -1;
        iVar8 = iVar8 + 1;
      } while (bVar1);
      ppTStack_108 = ppTVar12;
      iVar8 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar8 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Diplomacy_Dialog);
        return 1;
      }
      goto LAB_0043dbaa;
    }
  }
  else if (param_2 != param_1->cancelButton) {
    if (param_2 == param_1->help_button) {
      TEasy_Panel::setup_popup_help((TEasy_Panel *)param_1);
      return 1;
    }
    if (param_2 == param_1->clearButton) {
      ppTVar12 = param_1->foodTributeButton;
      param_1->foodTotal = 0.0;
      param_1->goldTotal = 0.0;
      param_1->stoneTotal = 0.0;
      param_1->woodTotal = 0.0;
      iVar8 = 8;
      do {
        if (ppTVar12[-0x10] != (TButtonPanel *)0x0) {
          TButtonPanel::set_text(ppTVar12[-0x10],0,s_);
        }
        if (*ppTVar12 != (TButtonPanel *)0x0) {
          TButtonPanel::set_text(*ppTVar12,0,s_);
        }
        if (ppTVar12[-8] != (TButtonPanel *)0x0) {
          TButtonPanel::set_text(ppTVar12[-8],0,s_);
        }
        if (ppTVar12[8] != (TButtonPanel *)0x0) {
          TButtonPanel::set_text(ppTVar12[8],0,s_);
        }
        ppTVar12[0x37] = (TButtonPanel *)0x0;
        ppTVar12[0x3f] = (TButtonPanel *)0x0;
        ppTVar12[0x47] = (TButtonPanel *)0x0;
        ppTVar12[0x4f] = (TButtonPanel *)0x0;
        ppTVar12 = ppTVar12 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      RGE_Base_Game::get_player(rge_base_game);
      uVar11 = __ftol();
      sprintf(auStack_100,s__ld,uVar11);
      (**(code **)(param_1->playerGold->_padding_ + 0xe8))(auStack_100);
      RGE_Base_Game::get_player(rge_base_game);
      uVar11 = __ftol();
      sprintf(&pRStack_104,s__ld,uVar11);
      (**(code **)(param_1->playerFood->_padding_ + 0xe8))(&pRStack_104);
      RGE_Base_Game::get_player(rge_base_game);
      uVar11 = __ftol();
      sprintf(&ppTStack_108,s__ld,uVar11);
      (**(code **)(param_1->playerWood->_padding_ + 0xe8))(&ppTStack_108);
      RGE_Base_Game::get_player(rge_base_game);
      uVar11 = __ftol();
      sprintf(&stack0xfffffef4,s__ld,uVar11);
      (**(code **)(param_1->playerStone->_padding_ + 0xe8))(&stack0xfffffef4);
      TribeDiplomacyDialog::check_gold(param_1);
      TribeDiplomacyDialog::check_wood(param_1);
      TribeDiplomacyDialog::check_stone(param_1);
      TribeDiplomacyDialog::check_food(param_1);
      return 1;
    }
    ppTStack_108 = (TButtonPanel **)0x0;
    pRVar6 = RGE_Base_Game::get_player(rge_base_game);
    if ((float)_DAT_0056f888 < pRVar6->attributes[0x2e]) {
      pRVar6 = RGE_Base_Game::get_player(rge_base_game);
      ppTStack_108 = (TButtonPanel **)pRVar6->attributes[0x2e];
    }
    iVar10 = 0;
    iVar15 = 1;
    iVar8 = rge_base_game->world->player_num + -1;
    if (0 < iVar8) {
      ppTVar12 = param_1->woodTributeButton;
      do {
        if (param_2 == ppTVar12[-8]) {
          iVar8 = TribeDiplomacyDialog::check_gold(param_1);
          if (iVar8 == 0) {
            ppTStack_108 = (TButtonPanel **)((float)ppTStack_108 - _DAT_0056f890);
            pRVar6 = RGE_Base_Game::get_player(rge_base_game);
            if ((float)ppTStack_108 * _DAT_0056f880 <= pRVar6->attributes[3] - param_1->goldTotal) {
              fVar2 = (float)ppTStack_108 * _DAT_0056f894;
              param_1->goldTributeAmount[iVar15 + -1] =
                   param_1->goldTributeAmount[iVar15 + -1] - _DAT_0056f894;
              fVar2 = param_1->goldTotal - fVar2;
            }
            else {
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              fVar2 = (pRVar6->attributes[3] - param_1->goldTotal) / (float)ppTStack_108;
              param_1->goldTributeAmount[iVar15 + -1] =
                   fVar2 + param_1->goldTributeAmount[iVar15 + -1];
              fVar2 = fVar2 * (float)ppTStack_108 + param_1->goldTotal;
            }
            param_1->goldTotal = fVar2;
            RGE_Base_Game::get_player(rge_base_game);
            uVar11 = __ftol();
            sprintf(auStack_100,s__ld,uVar11);
            (**(code **)(param_1->playerGold->_padding_ + 0xe8))(auStack_100);
            uVar11 = __ftol();
            sprintf(&pRStack_104,s__ld,uVar11);
            TButtonPanel::set_text(param_1->goldTributeButton[iVar10],0,(char *)&pRStack_104);
            TribeDiplomacyDialog::check_gold(param_1);
            return 1;
          }
          RGE_Base_Game::get_player(rge_base_game);
          uVar11 = __ftol();
          sprintf(auStack_100,s__ld,uVar11);
          (**(code **)(param_1->playerGold->_padding_ + 0xe8))(auStack_100);
          TribeDiplomacyDialog::check_gold(param_1);
          return 1;
        }
        if (param_2 == *ppTVar12) {
          iVar8 = TribeDiplomacyDialog::check_wood(param_1);
          if (iVar8 == 0) {
            ppTStack_108 = (TButtonPanel **)((float)ppTStack_108 - _DAT_0056f890);
            pRVar6 = RGE_Base_Game::get_player(rge_base_game);
            if ((float)ppTStack_108 * _DAT_0056f880 <= pRVar6->attributes[1] - param_1->woodTotal) {
              fVar2 = (float)ppTStack_108 * _DAT_0056f894;
              param_1->stoneTributeAmount[iVar15 + 7] =
                   param_1->stoneTributeAmount[iVar15 + 7] - _DAT_0056f894;
              fVar2 = param_1->woodTotal - fVar2;
            }
            else {
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              fVar2 = (pRVar6->attributes[1] - param_1->woodTotal) / (float)ppTStack_108;
              param_1->stoneTributeAmount[iVar15 + 7] =
                   fVar2 + param_1->stoneTributeAmount[iVar15 + 7];
              fVar2 = fVar2 * (float)ppTStack_108 + param_1->woodTotal;
            }
            param_1->woodTotal = fVar2;
            RGE_Base_Game::get_player(rge_base_game);
            uVar11 = __ftol();
            sprintf(auStack_100,s__ld,uVar11);
            (**(code **)(param_1->playerWood->_padding_ + 0xe8))(auStack_100);
            uVar11 = __ftol();
            sprintf(&pRStack_104,s__ld,uVar11);
            TButtonPanel::set_text(param_1->woodTributeButton[iVar10],0,(char *)&pRStack_104);
            TribeDiplomacyDialog::check_wood(param_1);
            return 1;
          }
          RGE_Base_Game::get_player(rge_base_game);
          uVar11 = __ftol();
          sprintf(auStack_100,s__ld,uVar11);
          (**(code **)(param_1->playerWood->_padding_ + 0xe8))(auStack_100);
          TribeDiplomacyDialog::check_wood(param_1);
          return 1;
        }
        if (param_2 == ppTVar12[8]) {
          iVar8 = TribeDiplomacyDialog::check_food(param_1);
          if (iVar8 == 0) {
            ppTStack_108 = (TButtonPanel **)((float)ppTStack_108 - _DAT_0056f890);
            pRVar6 = RGE_Base_Game::get_player(rge_base_game);
            if ((float)ppTStack_108 * _DAT_0056f880 <= *pRVar6->attributes - param_1->foodTotal) {
              fVar2 = (float)ppTStack_108 * _DAT_0056f894;
              param_1->goldTributeAmount[iVar15 + 7] =
                   param_1->goldTributeAmount[iVar15 + 7] - _DAT_0056f894;
              fVar2 = param_1->foodTotal - fVar2;
            }
            else {
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              fVar2 = (*pRVar6->attributes - param_1->foodTotal) / (float)ppTStack_108;
              param_1->goldTributeAmount[iVar15 + 7] =
                   fVar2 + param_1->goldTributeAmount[iVar15 + 7];
              fVar2 = fVar2 * (float)ppTStack_108 + param_1->foodTotal;
            }
            param_1->foodTotal = fVar2;
            RGE_Base_Game::get_player(rge_base_game);
            uVar11 = __ftol();
            sprintf(auStack_100,s__ld,uVar11);
            (**(code **)(param_1->playerFood->_padding_ + 0xe8))(auStack_100);
            uVar11 = __ftol();
            sprintf(&pRStack_104,s__ld,uVar11);
            TButtonPanel::set_text(param_1->foodTributeButton[iVar10],0,(char *)&pRStack_104);
            TribeDiplomacyDialog::check_food(param_1);
            return 1;
          }
          RGE_Base_Game::get_player(rge_base_game);
          uVar11 = __ftol();
          sprintf(auStack_100,s__ld,uVar11);
          (**(code **)(param_1->playerFood->_padding_ + 0xe8))(auStack_100);
          TribeDiplomacyDialog::check_food(param_1);
          return 1;
        }
        if (param_2 == ppTVar12[0x10]) {
          iVar8 = TribeDiplomacyDialog::check_stone(param_1);
          if (iVar8 == 0) {
            ppTStack_108 = (TButtonPanel **)((float)ppTStack_108 - _DAT_0056f890);
            pRVar6 = RGE_Base_Game::get_player(rge_base_game);
            if ((float)ppTStack_108 * _DAT_0056f880 <= pRVar6->attributes[2] - param_1->stoneTotal)
{
              fVar2 = (float)ppTStack_108 * _DAT_0056f894;
              param_1->foodTributeAmount[iVar15 + 7] =
                   param_1->foodTributeAmount[iVar15 + 7] - _DAT_0056f894;
              fVar2 = param_1->stoneTotal - fVar2;
            }
            else {
              pRVar6 = RGE_Base_Game::get_player(rge_base_game);
              fVar2 = (pRVar6->attributes[2] - param_1->stoneTotal) / (float)ppTStack_108;
              param_1->foodTributeAmount[iVar15 + 7] =
                   fVar2 + param_1->foodTributeAmount[iVar15 + 7];
              fVar2 = fVar2 * (float)ppTStack_108 + param_1->stoneTotal;
            }
            param_1->stoneTotal = fVar2;
            RGE_Base_Game::get_player(rge_base_game);
            uVar11 = __ftol();
            sprintf(auStack_100,s__ld,uVar11);
            (**(code **)(param_1->playerStone->_padding_ + 0xe8))(auStack_100);
            uVar11 = __ftol();
            sprintf(&pRStack_104,s__ld,uVar11);
            TButtonPanel::set_text(param_1->stoneTributeButton[iVar10],0,(char *)&pRStack_104);
            TribeDiplomacyDialog::check_stone(param_1);
            return 1;
          }
          RGE_Base_Game::get_player(rge_base_game);
          uVar11 = __ftol();
          sprintf(auStack_100,s__ld,uVar11);
          (**(code **)(param_1->playerStone->_padding_ + 0xe8))(auStack_100);
          TribeDiplomacyDialog::check_stone(param_1);
          return 1;
        }
        iVar10 = iVar10 + 1;
        ppTVar12 = ppTVar12 + 1;
        iVar15 = iVar15 + 1;
      } while (iVar10 < iVar8);
    }
    goto LAB_0043de3c;
  }
  iVar8 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if ((iVar8 == 1) && (rge_base_game->save_paused == 0)) {
    RGE_Base_Game::set_paused(rge_base_game,0,0);
  }
LAB_0043dbaa:
  TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
  TPanelSystem::destroyPanel(&panel_system,s_Diplomacy_Dialog);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0043e521
// Address: 0043e521
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0043e521(int param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if ((rge_base_game->prog_mode == 5) ||
     (pRVar1 = RGE_Base_Game::get_player(rge_base_game),
     pRVar1->attributes[3] - *(float *)(param_1 + 0x618) <= _DAT_0056f884)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  iVar4 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x514);
  do {
    if ((TButtonPanel *)*puVar3 != (TButtonPanel *)0x0) {
      iVar5 = iVar2;
      if (iVar4 == *(int *)(param_1 + 0x6b0)) {
        iVar5 = 1;
      }
      TButtonPanel::set_disabled((TButtonPanel *)*puVar3,iVar5);
      if (*(int *)(param_1 + 0x6b4) == 0) {
        (**(code **)(*(int *)*puVar3 + 0x14))(0);
      }
      else {
        (**(code **)(*(int *)*puVar3 + 0x14))(1);
      }
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar4 < 8);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0043e5b8
// Address: 0043e5b8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0043e5b8(int param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if ((rge_base_game->prog_mode == 5) ||
     (pRVar1 = RGE_Base_Game::get_player(rge_base_game),
     pRVar1->attributes[1] - *(float *)(param_1 + 0x614) <= _DAT_0056f884)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  iVar4 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x534);
  do {
    if ((TButtonPanel *)*puVar3 != (TButtonPanel *)0x0) {
      iVar5 = iVar2;
      if (iVar4 == *(int *)(param_1 + 0x6b0)) {
        iVar5 = 1;
      }
      TButtonPanel::set_disabled((TButtonPanel *)*puVar3,iVar5);
      if (*(int *)(param_1 + 0x6b4) == 0) {
        (**(code **)(*(int *)*puVar3 + 0x14))(0);
      }
      else {
        (**(code **)(*(int *)*puVar3 + 0x14))(1);
      }
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar4 < 8);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0043e648
// Address: 0043e648
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0043e648(int param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if ((rge_base_game->prog_mode == 5) ||
     (pRVar1 = RGE_Base_Game::get_player(rge_base_game),
     *pRVar1->attributes - *(float *)(param_1 + 0x610) <= _DAT_0056f884)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  iVar4 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x554);
  do {
    if ((TButtonPanel *)*puVar3 != (TButtonPanel *)0x0) {
      iVar5 = iVar2;
      if (iVar4 == *(int *)(param_1 + 0x6b0)) {
        iVar5 = 1;
      }
      TButtonPanel::set_disabled((TButtonPanel *)*puVar3,iVar5);
      if (*(int *)(param_1 + 0x6b4) == 0) {
        (**(code **)(*(int *)*puVar3 + 0x14))(0);
      }
      else {
        (**(code **)(*(int *)*puVar3 + 0x14))(1);
      }
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar4 < 8);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0043e6d7
// Address: 0043e6d7
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0043e6d7(int param_1)
{
  RGE_Player *pRVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if ((rge_base_game->prog_mode == 5) ||
     (pRVar1 = RGE_Base_Game::get_player(rge_base_game),
     pRVar1->attributes[2] - *(float *)(param_1 + 0x61c) <= _DAT_0056f884)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  iVar4 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x574);
  do {
    if ((TButtonPanel *)*puVar3 != (TButtonPanel *)0x0) {
      iVar5 = iVar2;
      if (iVar4 == *(int *)(param_1 + 0x6b0)) {
        iVar5 = 1;
      }
      TButtonPanel::set_disabled((TButtonPanel *)*puVar3,iVar5);
      if (*(int *)(param_1 + 0x6b4) == 0) {
        (**(code **)(*(int *)*puVar3 + 0x14))(0);
      }
      else {
        (**(code **)(*(int *)*puVar3 + 0x14))(1);
      }
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar4 < 8);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_0043e768
// Address: 0043e768
void __fastcall FUN_0043e768(TEasy_Panel *param_1)
{
  RGE_Game_World *pRVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_8;
  
  TEasy_Panel::draw(param_1);
  iVar4 = 0;
  if (*(int *)(param_1[1].info_file_name + 0x98) != 0) {
    iVar3 = param_1->_padding_;
    pRVar1 = rge_base_game->world;
    (**(code **)(iVar3 + 0x28))(0);
    if (pRVar1->player_num != 1 && -1 < pRVar1->player_num + -1) {
      iVar5 = 0;
      iVar2 = 4;
      do {
        iVar3 = *(int *)(*(int *)((int)pRVar1->players + iVar2) + 0x108);
        if (iVar3 != 0) {
          _ASMSet_Color_Xform((*(short *)(iVar3 + 0x26) + 1) * 0x10);
          TShape::shape_draw(*(TShape **)(param_1[1].info_file_name + 0x98),
                             (TDrawArea *)param_1->_padding_,param_1->_padding_ + 10,
                             param_1->_padding_ + 0x50 + iVar4,0,'\x01',
                             (uchar *)(*(int *)(*(int *)((int)pRVar1->players + iVar2) + 0x108) +
                                      0x28));
        }
        iVar4 = iVar4 + 0x1e;
        iVar2 = iVar2 + 4;
        iVar5 = iVar5 + 1;
        iVar3 = iStack_8;
      } while (iVar5 < pRVar1->player_num + -1);
    }
    (**(code **)(iVar3 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043e833
// Address: 0043e833
// [HELPER] s_Help_Dialog: "Help Dialog"
THelpDialog * __thiscall
FUN_0043e833(THelpDialog *param_1,TEasy_Panel *param_2,char *param_3,int param_4,long param_5,
            long param_6,long param_7)
{
  char *pcVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d088;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel((TDialogPanel *)param_1,s_Help_Dialog);
  uStack_4 = 0;
  param_1->_padding_ = (int)&THelpDialog::_vftable_;
  pcVar1 = TPanel::get_string((TPanel *)param_1,param_4);
  THelpDialog::setup_help(param_1,param_2,param_3,pcVar1,param_5,param_6,param_7);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043e8b6
// Address: 0043e8b6
THelpDialog * __thiscall FUN_0043e8b6(THelpDialog *param_1,byte param_2)
{
  THelpDialog::~THelpDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043e8de
// Address: 0043e8de
// [HELPER] s_Help_Dialog: "Help Dialog"
THelpDialog * __thiscall
FUN_0043e8de(THelpDialog *param_1,TEasy_Panel *param_2,char *param_3,char *param_4,long param_5,
            long param_6,long param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d0a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel((TDialogPanel *)param_1,s_Help_Dialog);
  uStack_4 = 0;
  param_1->_padding_ = (int)&THelpDialog::_vftable_;
  THelpDialog::setup_help(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043e94e
// Address: 0043e94e
void __fastcall FUN_0043e94e(TDialogPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d0c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&THelpDialog::_vftable_;
  uStack_4 = 0;
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0043e9da
// Address: 0043e9da
void __thiscall
FUN_0043e9da(TPanel *param_1,TEasy_Panel *param_2,char *param_3,undefined4 param_4,long param_5)
{
  ulong *puVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  long *plVar12;
  long *plVar13;
  undefined4 uVar14;
  int iStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  
  puVar1 = &param_1[5].mouse_down_time;
  uVar10 = 0xffffffff;
  param_1[5].error_code = 0;
  param_1[5].z_order = 0;
  param_1[5].mouse_down_shift = 0;
  *puVar1 = 0;
  do {
    pcVar9 = param_3;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar9 = param_3 + 1;
    cVar3 = *param_3;
    param_3 = pcVar9;
  } while (cVar3 != '\0');
  uVar10 = ~uVar10;
  plVar12 = (long *)(pcVar9 + -uVar10);
  plVar13 = &param_1[4].mouse_down_x;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *plVar13 = *plVar12;
    plVar12 = plVar12 + 1;
    plVar13 = plVar13 + 1;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(char *)plVar13 = (char)*plVar12;
    plVar12 = (long *)((int)plVar12 + 1);
    plVar13 = (long *)((int)plVar13 + 1);
  }
  param_1[4].mouse_move_tolerance = param_5;
  RGE_Base_Game::get_font(rge_base_game,0xb);
  iVar5 = param_1->_padding_;
  TEasy_Panel::get_popup_info_id(param_2);
  TEasy_Panel::get_popup_info_file(param_2);
  TPanel::renderArea((TPanel *)param_2);
  iVar4 = (**(code **)(iVar5 + 300))();
  if (iVar4 != 0) {
    (**(code **)(iVar5 + 0x100))();
    iVar4 = *(short *)(*puVar1 + 0xfe) + 2;
    iVar5 = iVar4 * iRam00000012;
    lVar6 = TPanel::width((TPanel *)param_2);
    lVar7 = TPanel::xPosition((TPanel *)param_2);
    if (lVar6 + lVar7 < (int)(param_2->info_file_name + 0x67)) {
      lVar6 = TPanel::xPosition((TPanel *)param_2);
      if ((int)((int)&param_2[-1].use_bevels + 3) < lVar6 + 10) {
        TPanel::width((TPanel *)param_2);
      }
      else {
        TPanel::xPosition((TPanel *)param_2);
      }
    }
    else {
      TPanel::xPosition((TPanel *)param_2);
    }
    lVar6 = TPanel::yPosition((TPanel *)param_2);
    if (0x14a - (iVar5 + 0x37) < lVar6) {
      lVar6 = TPanel::height((TPanel *)param_2);
      lVar7 = TPanel::yPosition((TPanel *)param_2);
      if (lVar6 + lVar7 < iVar5 + 0x195) {
        TPanel::height((TPanel *)param_2);
      }
      else {
        TPanel::yPosition((TPanel *)param_2);
      }
    }
    else {
      TPanel::yPosition((TPanel *)param_2);
    }
    iVar5 = param_1->_padding_;
    (**(code **)(iVar5 + 0x1c))();
    (**(code **)(iVar5 + 0xe4))();
    (**(code **)(*(int *)param_1[5].mouse_down_time + 0x1c))();
    iVar8 = RGE_Base_Game::singlePlayerGame(rge_base_game);
    if ((iVar8 != 0) && (-1 < (int)puVar1)) {
      uStack_94 = 0x43ec61;
      pcVar9 = TPanel::get_string(param_1,(int)puVar1);
      if ((pcVar9 != (char *)0x0) && (*pcVar9 != '\0')) {
        uStack_94 = 0;
        uStack_98 = 0xb;
        uStack_9c = 0x19;
        iStack_a4 = iVar4 * iRam0000015c + 0x14;
        iStack_a0 = 0x78;
        (**(code **)(iVar5 + 0xe8))(param_1,&param_1[5].z_order,0x243d,0,0x19);
      }
    }
    uStack_94 = 0;
    uStack_98 = 0xb;
    uStack_9c = 0x19;
    iStack_a0 = 0x78;
    if (param_1[5].z_order == 0) {
      uVar14 = 0x6e;
    }
    else {
      uVar14 = 0xc3;
    }
    iStack_a4 = iVar4 * iRam0000015c + 0x14;
    piVar2 = &param_1[5].error_code;
    (**(code **)(iVar5 + 0xe8))(param_1,piVar2,0xfa1,0,uVar14);
    iVar4 = *piVar2;
    *(undefined4 *)(iVar4 + 0x298) = 0x1b;
    *(undefined4 *)(iVar4 + 0x29c) = 0;
    TPanel::set_curr_child(param_1,(TPanel *)*piVar2);
    iStack_a4 = *piVar2;
    uVar14 = 1;
    if (param_1[5].z_order != 0) {
      uVar14 = 2;
      iStack_a0 = param_1[5].z_order;
    }
    (**(code **)(iVar5 + 200))(&iStack_a4,uVar14);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0043ed31
// Address: 0043ed31
// [HELPER] s_Help_Dialog: "Help Dialog"
// [HELPER] s_empires_hlp: "empires.hlp"
long __thiscall
FUN_0043ed31(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  long lVar4;
  
  iVar1 = param_1[1]._padding_;
  if (param_3 == 1) {
    if (param_2 == *(TPanel **)(param_1[1].info_file_name + 0x28)) {
      TPanelSystem::setCurrentPanel(&panel_system,(char *)&param_1[1]._padding_,0);
      TPanelSystem::destroyPanel(&panel_system,s_Help_Dialog);
      return 1;
    }
    if (param_2 == *(TPanel **)(param_1[1].info_file_name + 0x2c)) {
      TPanelSystem::setCurrentPanel(&panel_system,(char *)&param_1[1]._padding_,0);
      TPanelSystem::destroyPanel(&panel_system,s_Help_Dialog);
      pvVar2 = rge_base_game->prog_window;
      pcVar3 = TPanel::get_string((TPanel *)param_1,iVar1);
      WinHelpA(pvVar2,s_empires_hlp,0x101,pcVar3);
      return 1;
    }
  }
  lVar4 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  return lVar4;
}

// --------------------------------------------------

// Function: FUN_0043ee02
// Address: 0043ee02
long __thiscall FUN_0043ee02(TEasy_Panel *param_1,undefined4 param_2,long param_3,long param_4)
{
  int iVar1;
  int iVar2;
  long lVar3;
  uchar unaff_BL;
  
  iVar1 = param_1->_padding_;
  iVar2 = (**(code **)(iVar1 + 0xbc))(param_3,param_4);
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0xb4))(*(undefined4 *)(param_1[1].info_file_name + 0x28),1,0,0);
    return 1;
  }
  lVar3 = TEasy_Panel::handle_mouse_down(param_1,unaff_BL,param_3,param_4,param_3,param_4);
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_0043ee6a
// Address: 0043ee6a
TDialogPanel * __thiscall FUN_0043ee6a(TDialogPanel *param_1,char *param_2)
{
  TDialogPanel::TDialogPanel(param_1,param_2);
  *(undefined2 *)&param_1[1]._padding_ = 0xffff;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TListDialog::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043eeb8
// Address: 0043eeb8
TListDialog * __thiscall FUN_0043eeb8(TListDialog *param_1,byte param_2)
{
  TListDialog::~TListDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043eede
// Address: 0043eede
void __fastcall FUN_0043eede(TDialogPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d0e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TListDialog::_vftable_;
  uStack_4 = 0;
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0043ef7a
// Address: 0043ef7a
undefined4 __thiscall
FUN_0043ef7a(TDialogPanel *param_1,TPanel *param_2,char *param_3,long param_4,long param_5,
            int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10
            ,char *param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,
            undefined4 param_15)
{
  int *piVar1;
  code *pcVar2;
  TDrawArea *pTVar3;
  int iVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_retaddr;
  TPanel *pTVar5;
  int iVar6;
  
  iVar6 = 1;
  pTVar5 = param_2;
  iVar4 = param_6;
  pTVar3 = TPanel::renderArea(param_2);
  iVar4 = TDialogPanel::setup(param_1,pTVar3,pTVar5,param_5,iVar4,param_3,param_4,iVar6);
  if (iVar4 == 0) {
    return 0;
  }
  if ((param_11 != (char *)0x0) && (*param_11 != '\0')) {
    iVar4 = (**(code **)(param_1->_padding_ + 0x100))
                      (param_1,param_1 + 1,param_11,param_7,param_8,param_9,param_10,4,1,1,1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  iVar4 = param_1->_padding_;
  piVar1 = &param_1[1]._padding_;
  iVar6 = (**(code **)(iVar4 + 0x110))(param_1,piVar1,param_12,param_13,param_14,param_15,0xb);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = (**(code **)(iVar4 + 0x118))(&param_1[1]._padding_,*piVar1,0x14);
  if (iVar6 == 0) {
    return 0;
  }
  if (param_6 != 0) {
    (**(code **)(*(int *)*piVar1 + 0xe0))(param_6,param_7);
  }
  *(short *)&param_1[1]._padding_ = (short)param_8;
  TListPanel::scroll_cur_line((TListPanel *)*piVar1,'\x01',(short)param_8,1);
  pcVar2 = *(code **)(iVar4 + 0xe8);
  iVar4 = (*pcVar2)(param_1,&param_1[1]._padding_,0xfa1,0,param_9,param_11,param_12,param_13,0,0,0);
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = (*pcVar2)(param_1,&param_1[1]._padding_,0xfa2,0,unaff_EBP,unaff_EBX,unaff_retaddr,param_2,
                    0,0,0);
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = param_1[1]._padding_;
  *(undefined4 *)(iVar4 + 0x298) = 0x1b;
  *(undefined4 *)(iVar4 + 0x29c) = 0;
  TPanel::set_curr_child((TPanel *)param_1,(TPanel *)*piVar1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0043f124
// Address: 0043f124
void __thiscall
FUN_0043f124(TListDialog *param_1,TPanel *param_2,char *param_3,long param_4,long param_5,
            long param_6,long param_7,long param_8,long param_9,long param_10,int param_11,
            long param_12,long param_13,long param_14,long param_15,char **param_16,short param_17,
            short param_18,long param_19,long param_20,long param_21,long param_22,long param_23)
{
  char acStack_100 [256];
  
  TPanel::get_string((TPanel *)param_1,param_11,acStack_100,0x100);
  TListDialog::setup(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10,acStack_100,param_12,param_13,param_14,param_15,param_16,param_17,
                     param_18,param_19,param_20,param_21,param_22,param_23);
  return;
}

// --------------------------------------------------

// Function: FUN_0043f215
// Address: 0043f215
long __thiscall
FUN_0043f215(TEasy_Panel *param_1,TTextPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  
  if (param_2 != (TTextPanel *)0x0) {
    if (param_2 == (TTextPanel *)param_1[1]._padding_) {
      if (param_3 == 1) {
        iVar2 = TTextPanel::currentLineNumber((TTextPanel *)param_1[1]._padding_);
        *(short *)&param_1[1]._padding_ = (short)iVar2;
        pcVar3 = TTextPanel::currentLine((TTextPanel *)param_1[1]._padding_);
        piVar1 = (int *)param_1->_padding_;
        param_1[1]._padding_ = (int)pcVar3;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0xb4))(param_1,1,0,0);
          return 1;
        }
        return 1;
      }
    }
    else if (param_2 == (TTextPanel *)param_1[1]._padding_) {
      if (param_3 == 1) {
        if ((int *)param_1->_padding_ == (int *)0x0) {
          return 1;
        }
        (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,2,0,0);
        return 1;
      }
    }
    else if ((param_2 == (TTextPanel *)param_1[1]._padding_) && (param_3 == 3)) {
      iVar2 = TTextPanel::currentLineNumber((TTextPanel *)param_1[1]._padding_);
      *(short *)&param_1[1]._padding_ = (short)iVar2;
      pcVar3 = TTextPanel::currentLine((TTextPanel *)param_1[1]._padding_);
      piVar1 = (int *)param_1->_padding_;
      param_1[1]._padding_ = (int)pcVar3;
      if (piVar1 == (int *)0x0) {
        return 1;
      }
      (**(code **)(*piVar1 + 0xb4))(param_1,1,0,0);
      return 1;
    }
  }
  lVar4 = TEasy_Panel::action(param_1,(TPanel *)param_2,param_3,param_4,param_5);
  return lVar4;
}

// --------------------------------------------------

// Function: FUN_0043f318
// Address: 0043f318
undefined2 __fastcall FUN_0043f318(int param_1)
{
  return *(undefined2 *)(param_1 + 0x4a4);
}

// --------------------------------------------------

// Function: FUN_0043f328
// Address: 0043f328
undefined4 __fastcall FUN_0043f328(int param_1)
{
  return *(undefined4 *)(param_1 + 0x4a8);
}

// --------------------------------------------------

// Function: FUN_0043f337
// Address: 0043f337
// [HELPER] s_Menu_Dialog: "Menu Dialog"
TDialogPanel * __thiscall FUN_0043f337(TDialogPanel *param_1,TEasy_Panel *param_2)
{
  RGE_Player *pRVar1;
  long lVar2;
  char *pcVar3;
  TDrawArea *pTVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  TDialogPanel *pTVar9;
  int iVar10;
  undefined4 *unaff_FS_OFFSET;
  long lVar11;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d108;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel(param_1,s_Menu_Dialog);
  param_1->_padding_ = (int)&TribeMenuDialog::_vftable_;
  pTVar9 = param_1 + 1;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    pTVar9->_padding_ = 0;
    pTVar9 = (TDialogPanel *)&pTVar9->_padding_;
  }
  uStack_4 = 0;
  iVar6 = 300;
  iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if (iVar5 != 0) {
    pRVar1 = RGE_Base_Game::get_player(rge_base_game);
    if (pRVar1->game_status == '\0') {
      iVar6 = 0x14f;
    }
  }
  iVar5 = RGE_Base_Game::singlePlayerGame(rge_base_game);
  if (iVar5 != 0) {
    iVar6 = iVar6 + 0x69;
  }
  iVar5 = 1;
  lVar2 = TEasy_Panel::get_popup_info_id(param_2);
  pcVar3 = TEasy_Panel::get_popup_info_file(param_2);
  lVar11 = 400;
  pTVar4 = TPanel::renderArea((TPanel *)param_2);
  iVar5 = TDialogPanel::setup(param_1,pTVar4,(TPanel *)param_2,lVar11,iVar6,pcVar3,lVar2,iVar5);
  if (iVar5 != 0) {
    iVar6 = 1;
    iVar5 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)(param_1 + 1),
                       0x2439,0,0x14,0xf,0x168,0x1e,0,0,4);
    if (iVar5 != 0) {
      iVar7 = 0x41;
      iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
      if (iVar5 != 0) {
        pRVar1 = RGE_Base_Game::get_player(rge_base_game);
        if (pRVar1->game_status == '\0') {
          iVar6 = 2;
          iVar5 = TEasy_Panel::create_button
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,
                             (TButtonPanel **)&param_1[1]._padding_,0x2440,0,0x14,0x41,0x168,0x1e,0,
                             0,0xc);
          if (iVar5 == 0) goto LAB_0043f66f;
          iVar7 = 100;
        }
      }
      iVar5 = TEasy_Panel::create_button
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,
                         (TButtonPanel **)(&param_1[1]._padding_ + iVar6),0x2437,0,0x14,iVar7,0x168,
                         0x1e,0,0,7);
      if (iVar5 != 0) {
        iVar10 = iVar6 + 2;
        iVar5 = TEasy_Panel::create_button
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TButtonPanel **)(&param_1[1]._padding_ + iVar6),0x243e,0,0x14,
                           iVar7 + 0x23,0x168,0x1e,0,0,9);
        if (iVar5 != 0) {
          iVar8 = iVar7 + 0x46;
          iVar5 = RGE_Base_Game::singlePlayerGame(rge_base_game);
          if (iVar5 != 0) {
            iVar5 = TEasy_Panel::create_button
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,
                               (TButtonPanel **)(&param_1[1]._padding_ + iVar6),0x2438,0,0x14,iVar8,
                               0x168,0x1e,0,0,1);
            if (iVar5 == 0) goto LAB_0043f66f;
            iVar5 = TEasy_Panel::create_button
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,
                               (TButtonPanel **)(&param_1[1]._padding_ + iVar6),0x243c,0,0x14,
                               iVar7 + 0x69,0x168,0x1e,0,0,3);
            if (iVar5 == 0) goto LAB_0043f66f;
            iVar10 = iVar6 + 5;
            iVar5 = TEasy_Panel::create_button
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,
                               (TButtonPanel **)(&param_1[1]._padding_ + iVar6),0x243f,0,0x14,
                               iVar7 + 0x8c,0x168,0x1e,0,0,0xb);
            if (iVar5 == 0) goto LAB_0043f66f;
            iVar8 = iVar7 + 0xaf;
          }
          iVar5 = TEasy_Panel::create_button
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,
                             (TButtonPanel **)(&param_1[1]._padding_ + iVar10),0x243a,0,0x14,iVar8,
                             0x168,0x1e,0,0,5);
          if (iVar5 != 0) {
            iVar5 = TEasy_Panel::create_button
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,
                               (TButtonPanel **)(&param_1[1]._padding_ + iVar10),0x23f5,0,0x14,
                               iVar8 + 0x23,0x168,0x1e,0,0,8);
            if (iVar5 != 0) {
              iVar5 = TEasy_Panel::create_button
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                 (TButtonPanel **)(&param_1[1]._padding_ + iVar10),0x23f9,0,0x14,
                                 iVar8 + 0x46,0x168,0x1e,0,0,10);
              if (iVar5 != 0) {
                iVar5 = TEasy_Panel::create_button
                                  ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                   (TButtonPanel **)(&param_1[1]._padding_ + iVar10),0x243b,0,0x14,
                                   iVar8 + 0x78,0x168,0x1e,0,0,6);
                if (iVar5 != 0) {
                  iVar5 = (&param_1[1]._padding_)[iVar10];
                  *(undefined4 *)(iVar5 + 0x29c) = 0;
                  *(undefined4 *)(iVar5 + 0x298) = 0x1b;
                  TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
                  TPanel::set_tab_order
                            ((TPanel *)param_1,(TPanel **)(param_1 + 1),(short)iVar10 + 4);
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0043f66f:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043f686
// Address: 0043f686
TribeMenuDialog * __thiscall FUN_0043f686(TribeMenuDialog *param_1,byte param_2)
{
  TribeMenuDialog::~TribeMenuDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043f6ae
// Address: 0043f6ae
void __fastcall FUN_0043f6ae(TDialogPanel *param_1)
{
  int iVar1;
  TDialogPanel *pTVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d128;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TribeMenuDialog::_vftable_;
  uStack_4 = 0;
  pTVar2 = param_1 + 1;
  iVar1 = 0xb;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)pTVar2);
    pTVar2 = (TDialogPanel *)&pTVar2->_padding_;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0043f717
// Address: 0043f717
// [HELPER] s_Achievements_Screen: "Achievements Screen"
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Menu_Dialog: "Menu Dialog"
// [HELPER] s_Mission_Dialog: "Mission Dialog"
// [HELPER] s_QuitAndLoadDialog: "QuitAndLoadDialog"
// [HELPER] s_QuitGameDialog: "QuitGameDialog"
// [HELPER] s_ResignDialog: "ResignDialog"
// [HELPER] s_RestartDialog: "RestartDialog"
// [HELPER] s_Save_Game_Screen: "Save Game Screen"
// [HELPER] s_empires_hlp: "empires.hlp"
long __thiscall
FUN_0043f717(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  TEasy_Panel *pTVar1;
  TScreenPanel *pTVar2;
  TribeSaveGameScreen *pTVar3;
  int iVar4;
  TribeConfigDialog *this;
  TribeAchievementsScreen *this_00;
  char *pcVar5;
  TribeAboutDialog *this_01;
  TRIBE_Mission_Screen *this_02;
  long lVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d182;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_2 != (TPanel *)0x0) && (param_3 == 1)) {
    if (param_4 == 1) {
      pTVar3 = (TribeSaveGameScreen *)operator_new(0x6a4);
      uStack_4 = 0;
      if (pTVar3 != (TribeSaveGameScreen *)0x0) {
        TribeSaveGameScreen::TribeSaveGameScreen(pTVar3,SaveGame,(char *)0x0,0);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Save_Game_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_4 == 2) {
      pTVar3 = (TribeSaveGameScreen *)operator_new(0x6a4);
      uStack_4 = 1;
      if (pTVar3 != (TribeSaveGameScreen *)0x0) {
        TribeSaveGameScreen::TribeSaveGameScreen(pTVar3,SaveScenario,(char *)0x0,0);
      }
      uStack_4 = 0xffffffff;
      TPanelSystem::setCurrentPanel(&panel_system,s_Save_Game_Screen,0);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_4 == 3) {
      pTVar1 = (TEasy_Panel *)param_1->_padding_;
      TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      TEasy_Panel::popupYesNoDialog(pTVar1,0xc1c,&s_QuitAndLoadDialog,0x1c2,100);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_4 == 8) {
      iVar4 = RGE_Base_Game::singlePlayerGame(rge_base_game);
      if ((iVar4 == 1) && (rge_base_game->save_paused == 0)) {
        RGE_Base_Game::set_paused(rge_base_game,0,0);
      }
      TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      WinHelpA(rge_base_game->prog_window,s_empires_hlp,3,0);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_4 == 4) {
      confirmed_close = 1;
      pTVar1 = (TEasy_Panel *)param_1->_padding_;
      TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      TEasy_Panel::popupYesNoDialog(pTVar1,0xc1d,&s_QuitGameDialog,0x1c2,100);
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (param_4 == 5) {
      pTVar2 = (TScreenPanel *)param_1->_padding_;
      TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
      TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
      this = (TribeConfigDialog *)operator_new(0x564);
      uStack_4 = 2;
      if (this != (TribeConfigDialog *)0x0) {
        TribeConfigDialog::TribeConfigDialog(this,InGame,pTVar2);
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
    }
    else {
      if (param_4 == 7) {
        this_00 = (TribeAchievementsScreen *)operator_new(0x5f8);
        uStack_4 = 3;
        if (this_00 != (TribeAchievementsScreen *)0x0) {
          iVar4 = 0;
          pcVar5 = TPanel::get_string((TPanel *)param_1,0x269e);
          TribeAchievementsScreen::TribeAchievementsScreen(this_00,pcVar5,iVar4);
        }
        uStack_4 = 0xffffffff;
        TPanelSystem::setCurrentPanel(&panel_system,s_Achievements_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
      if (param_4 == 10) {
        pTVar2 = (TScreenPanel *)param_1->_padding_;
        TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        this_01 = (TribeAboutDialog *)operator_new(0x4c4);
        uStack_4 = 4;
        if (this_01 != (TribeAboutDialog *)0x0) {
          TribeAboutDialog::TribeAboutDialog(this_01,pTVar2);
          *unaff_FS_OFFSET = uStack_c;
          return 1;
        }
      }
      else {
        if (param_4 == 0xb) {
          pTVar1 = (TEasy_Panel *)param_1->_padding_;
          TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
          TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
          TEasy_Panel::popupYesNoDialog(pTVar1,0xc1e,&s_RestartDialog,0x1c2,100);
          *unaff_FS_OFFSET = uStack_c;
          return 1;
        }
        if (param_4 == 9) {
          this_02 = (TRIBE_Mission_Screen *)operator_new(0x49c);
          uStack_4 = 5;
          if (this_02 != (TRIBE_Mission_Screen *)0x0) {
            TRIBE_Mission_Screen::TRIBE_Mission_Screen
                      (this_02,(char *)0x0,'\x01',rge_base_game->world->scenario->mission_picture);
          }
          uStack_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_Mission_Dialog,0);
          TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
          *unaff_FS_OFFSET = uStack_c;
          return 1;
        }
        if (param_4 == 6) {
          iVar4 = RGE_Base_Game::singlePlayerGame(rge_base_game);
          if ((iVar4 == 1) && (rge_base_game->save_paused == 0)) {
            RGE_Base_Game::set_paused(rge_base_game,0,0);
          }
          TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
          *unaff_FS_OFFSET = uStack_c;
          return 1;
        }
        if (param_4 != 0xc) goto LAB_0043fc43;
        pTVar1 = (TEasy_Panel *)param_1->_padding_;
        TPanelSystem::destroyPanel(&panel_system,s_Menu_Dialog);
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        TEasy_Panel::popupYesNoDialog(pTVar1,0xc1f,&s_ResignDialog,0x1c2,100);
      }
    }
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
LAB_0043fc43:
  lVar6 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  *unaff_FS_OFFSET = uStack_c;
  return lVar6;
}

// --------------------------------------------------

// Function: FUN_0043fc65
// Address: 0043fc65
TDialogPanel * __thiscall FUN_0043fc65(TDialogPanel *param_1,char *param_2)
{
  TDialogPanel::TDialogPanel(param_1,param_2);
  *(undefined1 *)&param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TMessageDialog::_vftable_;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043fcab
// Address: 0043fcab
TMessageDialog * __thiscall FUN_0043fcab(TMessageDialog *param_1,byte param_2)
{
  TMessageDialog::~TMessageDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0043fcce
// Address: 0043fcce
void __fastcall FUN_0043fcce(TDialogPanel *param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d198;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TMessageDialog::_vftable_;
  uStack_4 = 0;
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  piVar1 = &param_1[1]._padding_;
  iVar2 = 3;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0043fd4b
// Address: 0043fd4b
// [HELPER] s_: ""
undefined4 __thiscall
FUN_0043fd4b(TDialogPanel *param_1,TPanel *param_2,char *param_3,long param_4,long param_5,
            long param_6,undefined1 param_7,undefined4 param_8,undefined4 param_9,int param_10)
{
  TDrawArea *pTVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 unaff_EBP;
  int unaff_ESI;
  long lVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  int iVar10;
  
  iVar10 = 1;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  pTVar1 = TPanel::renderArea(param_2);
  iVar10 = TDialogPanel::setup(param_1,pTVar1,param_2,param_5,param_6,param_3,param_4,iVar10);
  if (iVar10 == 0) {
switchD_0043fdf0_default:
    return 0;
  }
  iVar10 = param_1->_padding_;
  iVar2 = param_1->_padding_;
  iVar8 = param_1->_padding_;
  *(undefined1 *)&param_1[1]._padding_ = param_7;
  iVar10 = (**(code **)(iVar8 + 0x100))
                     (param_1,&param_1[1]._padding_,param_8,3,3,iVar2 + -3,(iVar10 - param_10) + -6,
                      0xb,1,1,1);
  if (iVar10 == 0) {
    return 0;
  }
  switch((char)param_1[1]._padding_) {
  case '\0':
    iVar10 = 1;
    break;
  case '\x01':
  case '\x02':
  case '\x03':
    iVar10 = 2;
    break;
  case '\x04':
    iVar10 = 3;
    break;
  default:
    goto switchD_0043fdf0_default;
  }
  iVar2 = param_1->_padding_ - iVar10 * unaff_ESI;
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 / (iVar10 + 1);
  }
  iVar3 = (param_1->_padding_ - param_10) + -7;
  iVar7 = 0;
  if (iVar10 != 0) {
    pcVar9 = *(code **)(iVar8 + 0xec);
    piVar5 = &param_1[1]._padding_;
    iVar8 = iVar2;
    do {
      iVar4 = (*pcVar9)(param_1,piVar5,s_,s_,iVar2,iVar3,unaff_ESI,unaff_EBP,0xb,0,0);
      if (iVar4 == 0) {
        return 0;
      }
      piVar5 = piVar5 + 1;
      iVar2 = iVar2 + iVar8 + unaff_ESI;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar10);
  }
  switch((char)param_1[1]._padding_) {
  case '\0':
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0xfa1);
    goto switchD_0043fec6_default;
  case '\x01':
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0xfa1);
    lVar6 = 0xfa2;
    break;
  case '\x02':
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0xfa3);
    lVar6 = 0xfa4;
    break;
  case '\x03':
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0xfa5);
    lVar6 = 0xfa7;
    break;
  case '\x04':
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0xfa3);
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0xfa4);
    TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,0xfa2);
    iVar2 = param_1[1]._padding_;
    goto LAB_0043ff7e;
  default:
    goto switchD_0043fec6_default;
  }
  TButtonPanel::set_text((TButtonPanel *)param_1[1]._padding_,0,lVar6);
  iVar2 = param_1[1]._padding_;
LAB_0043ff7e:
  *(undefined4 *)(iVar2 + 0x298) = 0x1b;
  *(undefined4 *)(iVar2 + 0x29c) = 0;
switchD_0043fec6_default:
  (**(code **)(param_1->_padding_ + 200))(&param_1[1]._padding_,iVar10);
  TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0043ffc7
// Address: 0043ffc7
void __thiscall
FUN_0043ffc7(undefined4 param_1,TPanel *param_2,TPanel *param_3,long param_4,uchar param_5,
            int param_6,long param_7,char *param_8)
{
  char cVar1;
  TMessageDialog *this;
  int unaff_EBX;
  char *pcVar2;
  int *piVar3;
  char *unaff_retaddr;
  char acStack_108 [260];
  
  pcVar2 = (char *)(unaff_EBX + 1);
  cVar1 = (char)param_1;
  *pcVar2 = *pcVar2 + cVar1;
  *pcVar2 = *pcVar2 + '\x01';
  pcVar2 = (char *)(unaff_EBX + 2);
  *pcVar2 = *pcVar2 + cVar1;
  *pcVar2 = *pcVar2 + '\x01';
  *(char *)(unaff_EBX + 3) = *(char *)(unaff_EBX + 3) + '\x01';
  in(0xfe);
  piVar3 = (int *)(unaff_EBX + 4);
  this = (TMessageDialog *)
         CONCAT22((short)((uint)param_1 >> 0x10),
                  CONCAT11((char)((uint)param_1 >> 8) + cVar1 + (char)((uint)piVar3 >> 8),cVar1));
  *(char *)piVar3 = *(char *)piVar3 + '\x01';
  *piVar3 = *piVar3 + 1;
  *piVar3 = *piVar3 + 1;
  TPanel::get_string((TPanel *)this,param_6,acStack_108,0x100);
  TMessageDialog::setup
            (this,(TPanel *)&stack0x00000000,unaff_retaddr,(long)param_2,(long)param_3,param_4,
             param_5,acStack_108,param_7,(long)param_8);
  return;
}

// --------------------------------------------------

// Function: FUN_00440068
// Address: 00440068
long __thiscall
FUN_00440068(TEasy_Panel *param_1,TPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  int *piVar1;
  long lVar2;
  
  piVar1 = (int *)param_1->_padding_;
  if ((piVar1 != (int *)0x0) && (param_3 == 1)) {
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      (**(code **)(*piVar1 + 0xb4))(param_1,0,0,0);
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      (**(code **)(*piVar1 + 0xb4))(param_1,1,0,0);
      return 1;
    }
    if (param_2 == (TPanel *)param_1[1]._padding_) {
      (**(code **)(*piVar1 + 0xb4))(param_1,2,0,0);
      return 1;
    }
  }
  lVar2 = TEasy_Panel::action(param_1,param_2,param_3,param_4,param_5);
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_004400fb
// Address: 004400fb
undefined4 FUN_004400fb(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00440105
// Address: 00440105
void __fastcall FUN_00440105(TPanel *param_1)
{
  if (rge_base_game->input_enabled == 0) {
    RGE_Base_Game::enable_input(rge_base_game);
  }
  TPanel::handle_idle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00440131
// Address: 00440131
// [HELPER] s_Scenario_Menu_Dialog: "Scenario Menu Dialog"
TDialogPanel * __thiscall FUN_00440131(TDialogPanel *param_1,TEasy_Panel *param_2)
{
  long lVar1;
  char *pcVar2;
  TDrawArea *pTVar3;
  int iVar4;
  int *piVar5;
  undefined4 *unaff_FS_OFFSET;
  long lVar6;
  long lVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d1b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel(param_1,s_Scenario_Menu_Dialog);
  param_1[1]._padding_ = (int)param_2;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TRIBE_Dialog_Sed_Menu::_vftable_;
  piVar5 = &param_1[1]._padding_;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  iVar4 = 1;
  uStack_4 = 0;
  lVar1 = TEasy_Panel::get_popup_info_id(param_2);
  pcVar2 = TEasy_Panel::get_popup_info_file(param_2);
  lVar7 = 400;
  lVar6 = 0x1cc;
  pTVar3 = TPanel::renderArea((TPanel *)param_2);
  iVar4 = TDialogPanel::setup(param_1,pTVar3,(TPanel *)param_2,lVar6,lVar7,pcVar2,lVar1,iVar4);
  if (iVar4 != 0) {
    iVar4 = TEasy_Panel::create_button
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,
                       (TButtonPanel **)&param_1[1]._padding_,0x2443,0,0x1e,0x14,400,0x28,0,0,0);
    if (iVar4 != 0) {
      iVar4 = TEasy_Panel::create_button
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,
                         (TButtonPanel **)&param_1[1]._padding_,0x2441,0,0x1e,0x46,400,0x28,0,0,0);
      if (iVar4 != 0) {
        iVar4 = TEasy_Panel::create_button
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TButtonPanel **)&param_1[1]._padding_,0x2442,0,0x1e,0x78,400,0x28,0,0,0)
        ;
        if (iVar4 != 0) {
          iVar4 = TEasy_Panel::create_button
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,
                             (TButtonPanel **)&param_1[1]._padding_,0x2445,0,0x1e,0xaa,400,0x28,0,0,
                             0);
          if (iVar4 != 0) {
            iVar4 = TEasy_Panel::create_button
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,
                               (TButtonPanel **)&param_1[1]._padding_,0x242e,0,0x1e,0xdc,400,0x28,0,
                               0,0);
            if (iVar4 != 0) {
              iVar4 = TEasy_Panel::create_button
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                 (TButtonPanel **)&param_1[1]._padding_,0x2446,0,0x1e,0x10e,400,0x28
                                 ,0,0,0);
              if (iVar4 != 0) {
                iVar4 = TEasy_Panel::create_button
                                  ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                   (TButtonPanel **)&param_1[1]._padding_,0x2444,0,0x1e,0x154,400,
                                   0x28,0,0,0);
                if (iVar4 != 0) {
                  iVar4 = param_1[1]._padding_;
                  *(undefined4 *)(iVar4 + 0x298) = 0x1b;
                  *(undefined4 *)(iVar4 + 0x29c) = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00440339
// Address: 00440339
TRIBE_Dialog_Sed_Menu * __thiscall FUN_00440339(TRIBE_Dialog_Sed_Menu *param_1,byte param_2)
{
  TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044035e
// Address: 0044035e
// [HELPER] s_New_Dialog: "New Dialog"
// [HELPER] s_Open_Dialog: "Open Dialog"
void __fastcall FUN_0044035e(TDialogPanel *param_1)
{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d1d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TRIBE_Dialog_Sed_Menu::_vftable_;
  uStack_4 = 0;
  TPanelSystem::destroyPanel(&panel_system,&s_Open_Dialog);
  TPanelSystem::destroyPanel(&panel_system,&s_New_Dialog);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 7;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004403f3
// Address: 004403f3
// [HELPER] s_New_Dialog: "New Dialog"
// [HELPER] s_Open_Dialog: "Open Dialog"
// [HELPER] s_Scenario_Editor_Open: "Scenario Editor Open"
// [HELPER] s_Scenario_Editor_Screen: "Scenario Editor Screen"
// [HELPER] s_Scenario_Menu_Dialog: "Scenario Menu Dialog"
undefined4 __thiscall FUN_004403f3(int param_1,TPanel *param_2,int param_3)
{
  byte bVar1;
  TRIBE_Screen_Sed *this;
  undefined4 uVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  TRIBE_Screen_Sed_Open *this_00;
  byte *pbVar6;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d1fb;
  *unaff_FS_OFFSET = &uStack_c;
  this = *(TRIBE_Screen_Sed **)(param_1 + 0x490);
  if (param_3 == 1) {
    if (param_2 == *(TPanel **)(param_1 + 0x498)) {
      TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
      TRIBE_Screen_Sed::command_quit(this);
      uVar2 = 1;
      goto LAB_00440782;
    }
    if (param_2 == *(TPanel **)(param_1 + 0x49c)) {
      TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
      TRIBE_Screen_Sed::command_save(this,'\x01','\0');
      uVar2 = 1;
      goto LAB_00440782;
    }
    if (param_2 == *(TPanel **)(param_1 + 0x4a0)) {
      TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
      TRIBE_Screen_Sed::command_save_as(this,'\0');
      uVar2 = 1;
      goto LAB_00440782;
    }
    if (param_2 == *(TPanel **)(param_1 + 0x4a4)) {
      TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
      TRIBE_Screen_Sed::command_open(this);
      uVar2 = 1;
      goto LAB_00440782;
    }
    if (param_2 == *(TPanel **)(param_1 + 0x4a8)) {
      TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
      TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
      TRIBE_Screen_Sed::command_new(this);
      uVar2 = 1;
      goto LAB_00440782;
    }
    if (param_2 != *(TPanel **)(param_1 + 0x4ac)) {
      if (param_2 == *(TPanel **)(param_1 + 0x4b0)) {
        TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
        uVar2 = 1;
        goto LAB_00440782;
      }
      goto LAB_004405d2;
    }
    TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
    pcVar3 = TRIBE_Screen_Sed::scenario_save_defaulted(this);
    if (pcVar3 != (char *)0x0) {
      TRIBE_Game::test_scenario((TRIBE_Game *)rge_base_game,pcVar3);
      uVar2 = 1;
      goto LAB_00440782;
    }
LAB_0044076a:
    TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
LAB_00440779:
    uVar2 = 1;
  }
  else {
LAB_004405d2:
    if (param_2 != (TPanel *)0x0) {
      pcVar3 = TPanel::panelName(param_2);
      if (pcVar3 != (char *)0x0) {
        pbVar6 = &s_New_Dialog;
        pbVar4 = (byte *)TPanel::panelName(param_2);
        do {
          bVar1 = *pbVar4;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_00440619:
            iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_0044061e;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_00440619;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_0044061e:
        if (iVar5 != 0) goto LAB_0044068b;
        TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,&s_New_Dialog);
        TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
        if (param_3 == 0) {
          TRIBE_Screen_Sed::command_quick_save(this);
LAB_00440668:
          TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
          TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game,(char *)0x0,0);
        }
        else if (param_3 == 1) goto LAB_00440668;
LAB_00440765:
        if (param_3 == 2) goto LAB_0044076a;
        goto LAB_00440779;
      }
LAB_0044068b:
      pcVar3 = TPanel::panelName(param_2);
      if (pcVar3 != (char *)0x0) {
        pbVar6 = &s_Open_Dialog;
        pbVar4 = (byte *)TPanel::panelName(param_2);
        do {
          bVar1 = *pbVar4;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_004406ca:
            iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_004406cf;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_004406ca;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_004406cf:
        if (iVar5 == 0) {
          TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Screen,0);
          TPanelSystem::destroyPanel(&panel_system,&s_Open_Dialog);
          TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
          if (param_3 == 0) {
            TRIBE_Screen_Sed::command_quick_save(this);
          }
          else if (param_3 != 1) goto LAB_00440765;
          this_00 = (TRIBE_Screen_Sed_Open *)operator_new(0x490);
          uStack_4 = 0;
          if (this_00 != (TRIBE_Screen_Sed_Open *)0x0) {
            TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(this_00);
          }
          uStack_4 = 0xffffffff;
          TPanelSystem::setCurrentPanel(&panel_system,s_Scenario_Editor_Open,0);
          TPanelSystem::destroyPanel(&panel_system,s_Scenario_Menu_Dialog);
          goto LAB_00440765;
        }
      }
    }
    uVar2 = 0;
  }
LAB_00440782:
  *unaff_FS_OFFSET = uStack_c;
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00440797
// Address: 00440797
// [HELPER] s_: ""
// [HELPER] s_Send_Message_Dialog: "Send Message Dialog"
// [HELPER] s_dlg_plbn_shp: "dlg_plbn.shp"
TDialogPanel * __thiscall FUN_00440797(TDialogPanel *param_1,TEasy_Panel *param_2)
{
  RGE_Game_World *pRVar1;
  byte bVar2;
  int *piVar3;
  TShape *this;
  long lVar4;
  char *pcVar5;
  TDrawArea *pTVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  undefined4 *unaff_FS_OFFSET;
  long lVar13;
  long lVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piStack_8c;
  uint uStack_88;
  int iStack_84;
  char acStack_70 [100];
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d223;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel(param_1,s_Send_Message_Dialog);
  iStack_4 = 0;
  param_1->_padding_ = (int)&TribeSendMessageDialog::_vftable_;
  param_1[1]._padding_ = 0;
  piVar3 = &param_1[1]._padding_;
  iVar9 = 8;
  do {
    piVar3[-8] = 0;
    *piVar3 = 0;
    piVar3[8] = 0;
    piVar3[0x1e] = 0;
    piVar3 = piVar3 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  piVar3 = &param_1[1]._padding_;
  iVar9 = 3;
  do {
    piVar3[-4] = 0;
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  this = (TShape *)operator_new(0x20);
  iStack_4._0_1_ = 1;
  if (this == (TShape *)0x0) {
    iVar9 = 0;
  }
  else {
    iVar9 = TShape::TShape(this,s_dlg_plbn_shp,0xc63a);
  }
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  param_1[1]._padding_ = iVar9;
  if (iVar9 != 0) {
    iVar9 = 1;
    lVar4 = TEasy_Panel::get_popup_info_id(param_2);
    pcVar5 = TEasy_Panel::get_popup_info_file(param_2);
    lVar14 = 0x1d1;
    lVar13 = 0x208;
    pTVar6 = TPanel::renderArea((TPanel *)param_2);
    iVar9 = TDialogPanel::setup(param_1,pTVar6,(TPanel *)param_2,lVar13,lVar14,pcVar5,lVar4,iVar9);
    if ((iVar9 != 0) &&
       (iVar9 = TEasy_Panel::create_text
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)(param_1 + 1),
                           0x2667,5,10,param_1->_padding_ + -0x28,0x1e,1,1,1,0), iVar9 != 0)) {
      piStack_8c = &param_1[1]._padding_;
      uStack_88 = 1;
      pRVar1 = rge_base_game->world;
      iVar9 = 0x28;
      do {
        iVar7 = RGE_Base_Game::playerID(rge_base_game,uStack_88);
        if (iVar7 != 0) {
          bVar2 = 0;
          if (pRVar1->players[iVar7]->game_status == '\x02') {
LAB_004409b4:
            bVar2 = 1;
          }
          else {
            iVar8 = RGE_Base_Game::multiplayerGame(rge_base_game);
            if (iVar8 != 0) {
              iStack_84 = 0;
              uVar10 = 1;
              iVar8 = RGE_Base_Game::numberPlayers(rge_base_game);
              if (0 < iVar8) {
                do {
                  iVar8 = RGE_Base_Game::playerID(rge_base_game,uVar10);
                  if ((iVar8 == iVar7) &&
                     ((iVar8 = TCommunications_Handler::GetPlayerHumanity(comm,uVar10), iVar8 == 2
                      || (iVar8 == 4)))) {
                    iStack_84 = iVar8;
                  }
                  uVar10 = uVar10 + 1;
                  iVar8 = RGE_Base_Game::numberPlayers(rge_base_game);
                } while ((int)uVar10 <= iVar8);
              }
              if ((iStack_84 != 2) && (iStack_84 != 4)) goto LAB_004409b4;
            }
          }
          iVar17 = 0;
          iVar16 = 1;
          iVar11 = (-(uint)bVar2 & 0xfffffffd) + 0xb;
          iVar15 = 0;
          lVar14 = 0x1e;
          lVar13 = 0xbe;
          lVar4 = 0x32;
          iVar8 = iVar9;
          pcVar5 = TCommunications_Handler::GetPlayerName(comm,uStack_88);
          iVar8 = TEasy_Panel::create_text
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,
                             (TTextPanel **)(piStack_8c + -0x10),pcVar5,lVar4,iVar8,lVar13,lVar14,
                             iVar11,iVar15,iVar16,iVar17);
          if (iVar8 == 0) goto LAB_00440dda;
          (**(code **)(rge_base_game->_padding_ + 0x28))
                    (0x69,pRVar1->players[iVar7]->master_player_id,0,acStack_70,100);
          iVar7 = TEasy_Panel::create_text
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,
                             (TTextPanel **)(piStack_8c + -8),acStack_70,0x104,iVar9,0x78,0x1e,0xb,0
                             ,1,0);
          if (iVar7 == 0) goto LAB_00440dda;
          uVar10 = TCommunications_Handler::WhoAmI(comm);
          if ((uStack_88 != uVar10) &&
             ((iVar7 = TCommunications_Handler::GetPlayerHumanity(comm,uStack_88), iVar7 == 2 ||
              (iVar7 = TCommunications_Handler::GetPlayerHumanity(comm,uStack_88), iVar7 == 4)))) {
            iVar7 = TEasy_Panel::create_check_box
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piStack_8c,
                               10,iVar9,0x1e,0x1e,0,0);
            if (iVar7 == 0) goto LAB_00440dda;
            TPanel::set_help_info((TPanel *)*piStack_8c,0x767f,-1);
            iVar7 = TChat::inChatGroup(chat,uStack_88);
            if (iVar7 == 0) {
              (**(code **)(*(int *)*piStack_8c + 0xe0))(0);
            }
            else {
              (**(code **)(*(int *)*piStack_8c + 0xe0))(1);
            }
          }
          piStack_8c[0x16] = uStack_88;
          piStack_8c = piStack_8c + 1;
          iVar9 = iVar9 + 0x1e;
        }
        uStack_88 = uStack_88 + 1;
      } while ((int)uStack_88 < 9);
      iVar9 = TEasy_Panel::create_text
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,
                         (TTextPanel **)&param_1[1]._padding_,0x2668,10,0x13b,0x78,0x1e,4,1,1,0);
      if (iVar9 != 0) {
        iVar9 = TEasy_Panel::create_edit
                          ((TEasy_Panel *)param_1,(TPanel *)param_1,
                           (TEditPanel **)&param_1[1]._padding_,s_,0x41,FormatText,0x82,0x13b,0x17c,
                           0x17,0xb,1,0);
        if (iVar9 != 0) {
          TPanel::set_help_info((TPanel *)param_1[1]._padding_,0x767a,-1);
          piVar3 = &param_1[1]._padding_;
          iVar9 = TEasy_Panel::create_radio_button
                            ((TEasy_Panel *)param_1,(TPanel *)param_1,(TButtonPanel **)piVar3,0x2d,
                             0x15e,0x1e,0x1e,0,0);
          if ((((iVar9 != 0) &&
               (iVar9 = TEasy_Panel::create_radio_button
                                  ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                   (TButtonPanel **)&param_1[1]._padding_,0x113,0x15e,0x1e,0x1e,0,0)
               , iVar9 != 0)) &&
              (iVar9 = TEasy_Panel::create_radio_button
                                 ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                  (TButtonPanel **)&param_1[1]._padding_,0x2d,0x181,0x1e,0x1e,0,0),
              iVar9 != 0)) &&
             (iVar9 = TEasy_Panel::create_radio_button
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                 (TButtonPanel **)&param_1[1]._padding_,0x113,0x181,0x1e,0x1e,0,0),
             iVar9 != 0)) {
            iVar9 = TEasy_Panel::create_text
                              ((TEasy_Panel *)param_1,(TPanel *)param_1,
                               (TTextPanel **)&param_1[1]._padding_,0x2669,0x4b,0x15e,200,0x1e,0xb,0
                               ,1,0);
            if (iVar9 != 0) {
              TPanel::set_help_info((TPanel *)param_1[1]._padding_,-1,-1);
              iVar9 = TEasy_Panel::create_text
                                ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                 (TTextPanel **)&param_1[1]._padding_,0x266a,0x131,0x15e,200,0x1e,
                                 0xb,0,1,0);
              if (iVar9 != 0) {
                TPanel::set_help_info((TPanel *)param_1[1]._padding_,-1,-1);
                iVar9 = TEasy_Panel::create_text
                                  ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                   (TTextPanel **)&param_1[1]._padding_,0x266b,0x4b,0x181,200,0x1e,
                                   0xb,0,1,0);
                if (iVar9 != 0) {
                  TPanel::set_help_info((TPanel *)param_1[1]._padding_,-1,-1);
                  iVar9 = TEasy_Panel::create_text
                                    ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                     (TTextPanel **)&param_1[1]._padding_,0x266e,0x131,0x181,200,
                                     0x1e,0xb,0,1,0);
                  if (iVar9 != 0) {
                    TPanel::set_help_info((TPanel *)param_1[1]._padding_,-1,-1);
                    iVar9 = 4;
                    piVar12 = piVar3;
                    do {
                      TButtonPanel::set_radio_info
                                ((TButtonPanel *)*piVar12,(TButtonPanel **)piVar3,4);
                      piVar12 = piVar12 + 1;
                      iVar9 = iVar9 + -1;
                    } while (iVar9 != 0);
                    (**(code **)(*(int *)param_1[1]._padding_ + 0xe0))(1);
                    TPanel::set_help_info((TPanel *)*piVar3,0x767b,-1);
                    TPanel::set_help_info((TPanel *)param_1[1]._padding_,0x767c,-1);
                    TPanel::set_help_info((TPanel *)param_1[1]._padding_,0x767d,-1);
                    TPanel::set_help_info((TPanel *)param_1[1]._padding_,0x767e,-1);
                    piVar3 = &param_1[1]._padding_;
                    iVar9 = TEasy_Panel::create_button
                                      ((TEasy_Panel *)param_1,(TPanel *)param_1,
                                       (TButtonPanel **)piVar3,0x266c,0,100,0x1a9,300,0x1e,0,0,0);
                    if (iVar9 != 0) {
                      TPanel::set_help_info((TPanel *)*piVar3,0x7531,-1);
                      iVar9 = *piVar3;
                      *(undefined4 *)(iVar9 + 0x298) = 0x1b;
                      *(undefined4 *)(iVar9 + 0x29c) = 0;
                      TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00440dda:
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00440df7
// Address: 00440df7
TribeSendMessageDialog * __thiscall FUN_00440df7(TribeSendMessageDialog *param_1,byte param_2)
{
  TribeSendMessageDialog::~TribeSendMessageDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00440e1e
// Address: 00440e1e
void __fastcall FUN_00440e1e(TDialogPanel *param_1)
{
  TShape *this;
  int iVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d238;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TribeSendMessageDialog::_vftable_;
  uStack_4 = 0;
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)(param_1 + 1));
  piVar2 = &param_1[1]._padding_;
  iVar1 = 8;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)(piVar2 + -8));
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)(piVar2 + 8));
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = &param_1[1]._padding_;
  iVar1 = 4;
  do {
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)(piVar2 + -4));
    TPanel::delete_panel((TPanel *)param_1,(TPanel **)piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  TPanel::delete_panel((TPanel *)param_1,(TPanel **)&param_1[1]._padding_);
  this = (TShape *)param_1[1]._padding_;
  if (this != (TShape *)0x0) {
    TShape::~TShape(this);
    operator_delete(this);
  }
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00440f1f
// Address: 00440f1f
// [HELPER] s_: ""
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Send_Message_Dialog: "Send Message Dialog"
// [HELPER] s_____SEND_CHAT___u___s: "$$$ SEND CHAT @%u: %s"
long __thiscall
FUN_00440f1f(TribeSendMessageDialog *param_1,TButtonPanel *param_2,int param_3,ulong param_4,
            ulong param_5)
{
  char cVar1;
  TRIBE_Screen_Game *pTVar2;
  RGE_Player *pRVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  TButtonPanel **ppTVar10;
  char *pcVar11;
  char acStack_44 [68];
  
  if (param_2 == (TButtonPanel *)0x0) {
    lVar7 = TPanel::action((TPanel *)param_1,(TPanel *)0x0,param_3,param_4,param_5);
    return lVar7;
  }
  if (param_2 == (TButtonPanel *)param_1->chatInput) {
    if (param_3 == 0) {
      pTVar2 = (TRIBE_Screen_Game *)param_1->_padding_;
      pcVar4 = TEditPanel::currentLine(param_1->chatInput);
      if ((pcVar4 == (char *)0x0) ||
         (pcVar4 = TEditPanel::currentLine(param_1->chatInput), *pcVar4 == '\0')) {
        acStack_44[0] = '\0';
      }
      else {
        pcVar4 = TEditPanel::currentLine(param_1->chatInput);
        uVar8 = 0xffffffff;
        do {
          pcVar11 = pcVar4;
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          pcVar11 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar11;
        } while (cVar1 != '\0');
        uVar8 = ~uVar8;
        pcVar4 = pcVar11 + -uVar8;
        pcVar11 = acStack_44;
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
          pcVar4 = pcVar4 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar11 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar11 = pcVar11 + 1;
        }
      }
      if (acStack_44[0] != '\0') {
        iVar5 = (**(code **)(rge_base_game->_padding_ + 0x54))
                          ((int)rge_base_game->world->curr_player,acStack_44);
        if (iVar5 == 0) {
          iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
          if (iVar5 == 0) {
            RGE_Base_Game::play_sound(rge_base_game,2);
            TRIBE_Screen_Game::display_system_message(pTVar2,&stack0xffffffb4);
          }
          else if (rge_base_game->prog_mode != 5) {
            TCommunications_Handler::SendGroupChatMsg(comm,&stack0xffffffb4);
            TDebuggingLog::Log(L,(char *)L,s_____SEND_CHAT___u___s,rge_base_game->world->world_time,
                               &stack0xffffffb4);
          }
        }
        TEditPanel::set_text(param_1->chatInput,s_);
        return 1;
      }
    }
  }
  else {
    if (param_2 == param_1->okButton) {
      if (param_3 == 1) {
        TribeSendMessageDialog::checkButtons(param_1);
        pTVar2 = (TRIBE_Screen_Game *)param_1->_padding_;
        pcVar4 = TEditPanel::currentLine(param_1->chatInput);
        if ((pcVar4 == (char *)0x0) ||
           (pcVar4 = TEditPanel::currentLine(param_1->chatInput), *pcVar4 == '\0')) {
          acStack_44[0] = '\0';
        }
        else {
          pcVar4 = TEditPanel::currentLine(param_1->chatInput);
          uVar8 = 0xffffffff;
          do {
            pcVar11 = pcVar4;
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            pcVar11 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar11;
          } while (cVar1 != '\0');
          uVar8 = ~uVar8;
          pcVar4 = pcVar11 + -uVar8;
          pcVar11 = acStack_44;
          for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
            pcVar4 = pcVar4 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *pcVar11 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            pcVar11 = pcVar11 + 1;
          }
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Send_Message_Dialog);
        if (acStack_44[0] == '\0') {
          return 1;
        }
        iVar5 = (**(code **)(rge_base_game->_padding_ + 0x54))
                          ((int)rge_base_game->world->curr_player,acStack_44);
        if (iVar5 != 0) {
          return 1;
        }
        iVar5 = RGE_Base_Game::multiplayerGame(rge_base_game);
        if (iVar5 == 0) {
          RGE_Base_Game::play_sound(rge_base_game,2);
          TRIBE_Screen_Game::display_system_message(pTVar2,&stack0xffffffb4);
          return 1;
        }
        if (rge_base_game->prog_mode == 5) {
          return 1;
        }
        TCommunications_Handler::SendGroupChatMsg(comm,&stack0xffffffb4);
        TDebuggingLog::Log(L,(char *)L,s_____SEND_CHAT___u___s,rge_base_game->world->world_time,
                           &stack0xffffffb4);
        return 1;
      }
    }
    else {
      if (param_2 == param_1->help_button) {
        TEasy_Panel::setup_popup_help((TEasy_Panel *)param_1);
        return 1;
      }
      ppTVar10 = param_1->checkButton;
      if (((((param_2 == param_1->checkButton[0]) || (param_2 == param_1->checkButton[1])) ||
           (param_2 == param_1->checkButton[2])) ||
          ((param_2 == param_1->checkButton[3] || (param_2 == param_1->checkButton[4])))) ||
         ((param_2 == param_1->checkButton[5] ||
          ((param_2 == param_1->checkButton[6] || (param_2 == param_1->checkButton[7])))))) {
        (**(code **)(param_1->radioButton[0]->_padding_ + 0xe0))(0);
        (**(code **)(param_1->radioButton[1]->_padding_ + 0xe0))(0);
        (**(code **)(param_1->radioButton[2]->_padding_ + 0xe0))(0);
        (**(code **)(param_1->radioButton[3]->_padding_ + 0xe0))(1);
      }
      else {
        if (param_2 == param_1->radioButton[0]) {
          iVar5 = 8;
          pRVar3 = rge_base_game->world->players[rge_base_game->world->curr_player];
          do {
            if (*ppTVar10 != (TButtonPanel *)0x0) {
              iVar6 = RGE_Base_Game::playerID(rge_base_game,(int)ppTVar10[0x16]);
              if ((iVar6 == pRVar3->id) ||
                 (iVar6 = (**(code **)(pRVar3->_padding_ + 0x1c))(iVar6), iVar6 != 0)) {
                (**(code **)((*ppTVar10)->_padding_ + 0xe0))(1);
              }
              else {
                (**(code **)((*ppTVar10)->_padding_ + 0xe0))(0);
              }
            }
            ppTVar10 = ppTVar10 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          TribeSendMessageDialog::checkButtons(param_1);
          return 1;
        }
        if (param_2 == param_1->radioButton[1]) {
          iVar5 = 8;
          pRVar3 = rge_base_game->world->players[rge_base_game->world->curr_player];
          do {
            if (*ppTVar10 != (TButtonPanel *)0x0) {
              iVar6 = RGE_Base_Game::playerID(rge_base_game,(int)ppTVar10[0x16]);
              if ((iVar6 == pRVar3->id) ||
                 (iVar6 = (**(code **)(pRVar3->_padding_ + 0x18))(iVar6), iVar6 == 0)) {
                (**(code **)((*ppTVar10)->_padding_ + 0xe0))(0);
              }
              else {
                (**(code **)((*ppTVar10)->_padding_ + 0xe0))(1);
              }
            }
            ppTVar10 = ppTVar10 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          TribeSendMessageDialog::checkButtons(param_1);
          return 1;
        }
        if (param_2 != param_1->radioButton[2]) {
          TribeSendMessageDialog::checkButtons(param_1);
          return 1;
        }
        if (param_3 == 1) {
          iVar5 = 8;
          do {
            if (*ppTVar10 != (TButtonPanel *)0x0) {
              (**(code **)((*ppTVar10)->_padding_ + 0xe0))(1);
            }
            ppTVar10 = ppTVar10 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          TribeSendMessageDialog::checkButtons(param_1);
          return 1;
        }
      }
    }
    TribeSendMessageDialog::checkButtons(param_1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00441451
// Address: 00441451
void __fastcall FUN_00441451(TEasy_Panel *param_1)
{
  RGE_Game_World *pRVar1;
  RGE_Color_Table *pRVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_8;
  
  TEasy_Panel::draw(param_1);
  if (param_1[1]._padding_ != 0) {
    pRVar1 = rge_base_game->world;
    (**(code **)(param_1->_padding_ + 0x28))(0);
    iVar4 = 0;
    iVar5 = 1;
    do {
      iVar3 = RGE_Base_Game::playerID(rge_base_game,iVar5);
      if (iVar3 != 0) {
        pRVar2 = pRVar1->players[iVar3]->color_table;
        if (pRVar2 != (RGE_Color_Table *)0x0) {
          _ASMSet_Color_Xform((pRVar2->id + 1) * 0x10);
          TShape::shape_draw((TShape *)param_1[1]._padding_,(TDrawArea *)param_1->_padding_,
                             param_1->_padding_ + 0x32,param_1->_padding_ + 0x28 + iVar4,0,'\x01',
                             pRVar1->players[iVar3]->color_table->table);
        }
        iVar4 = iVar4 + 0x1e;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 9);
    (**(code **)(iStack_8 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044152b
// Address: 0044152b
// [HELPER] s_: ""
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
TDialogPanel * __thiscall FUN_0044152b(TDialogPanel *param_1,TEasy_Panel *param_2,int param_3)
{
  long lVar1;
  char *pcVar2;
  TDrawArea *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  long lVar4;
  long lVar5;
  int iVar6;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d258;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TDialogPanel::TDialogPanel(param_1,s_Send_Quick_Message_Dialog);
  iVar6 = 1;
  uStack_4 = 0;
  param_1[1]._padding_ = param_3;
  param_1->_padding_ = (int)&TribeSendQuickMessageDialog::_vftable_;
  lVar1 = TEasy_Panel::get_popup_info_id(param_2);
  pcVar2 = TEasy_Panel::get_popup_info_file(param_2);
  lVar5 = 0x23;
  lVar4 = 0x21c;
  pTVar3 = TPanel::renderArea((TPanel *)param_2);
  iVar6 = TDialogPanel::setup(param_1,pTVar3,(TPanel *)param_2,lVar4,lVar5,pcVar2,lVar1,iVar6);
  if (iVar6 != 0) {
    iVar6 = TEasy_Panel::create_text
                      ((TEasy_Panel *)param_1,(TPanel *)param_1,(TTextPanel **)&param_1[1]._padding_
                       ,(-(uint)(param_1[1]._padding_ != 0) & 5) + 0x2668,5,5,0x78,0x19,4,1,1,0);
    if (iVar6 != 0) {
      iVar6 = TEasy_Panel::create_edit
                        ((TEasy_Panel *)param_1,(TPanel *)param_1,(TEditPanel **)(param_1 + 1),s_,
                         0x41,FormatText,0x82,5,0x195,0x19,0xb,1,0);
      if (iVar6 != 0) {
        TPanel::set_curr_child((TPanel *)param_1,(TPanel *)param_1[1]._padding_);
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00441626
// Address: 00441626
TribeSendQuickMessageDialog * __thiscall
FUN_00441626(TribeSendQuickMessageDialog *param_1,byte param_2)
{
  TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044164e
// Address: 0044164e
void __fastcall FUN_0044164e(TDialogPanel *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_0055d278;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&TribeSendQuickMessageDialog::_vftable_;
  uStack_4 = 0;
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  if ((undefined4 *)param_1[1]._padding_ != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1]._padding_)(1);
  }
  uStack_4 = 0xffffffff;
  TDialogPanel::~TDialogPanel(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004416ba
// Address: 004416ba
// [HELPER] s_Game_Screen: "Game Screen"
// [HELPER] s_Send_Quick_Message_Dialog: "Send Quick Message Dialog"
long __thiscall
FUN_004416ba(TEasy_Panel *param_1,TEditPanel *param_2,int param_3,ulong param_4,ulong param_5)
{
  char cVar1;
  TRIBE_Screen_Game *this;
  char *pcVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char acStack_44 [68];
  
  if ((param_2 != (TEditPanel *)0x0) && (param_2 == (TEditPanel *)param_1[1]._padding_)) {
    if (param_3 == 0) {
      pcVar2 = TEditPanel::currentLine((TEditPanel *)param_1[1]._padding_);
      if ((pcVar2 != (char *)0x0) &&
         (pcVar2 = TEditPanel::currentLine((TEditPanel *)param_1[1]._padding_), *pcVar2 != '\0')) {
        this = (TRIBE_Screen_Game *)param_1->_padding_;
        pcVar2 = TEditPanel::currentLine((TEditPanel *)param_1[1]._padding_);
        uVar5 = 0xffffffff;
        do {
          pcVar7 = pcVar2;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar7 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar7;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        pcVar2 = pcVar7 + -uVar5;
        pcVar7 = acStack_44;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
          pcVar2 = pcVar2 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar7 = *pcVar2;
          pcVar2 = pcVar2 + 1;
          pcVar7 = pcVar7 + 1;
        }
        TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
        TPanelSystem::destroyPanel(&panel_system,s_Send_Quick_Message_Dialog);
        iVar3 = (**(code **)(rge_base_game->_padding_ + 0x54))
                          ((int)rge_base_game->world->curr_player,acStack_44);
        if (iVar3 != 0) {
          return 1;
        }
        iVar3 = RGE_Base_Game::multiplayerGame(rge_base_game);
        if (iVar3 == 0) {
          RGE_Base_Game::play_sound(rge_base_game,2);
          TRIBE_Screen_Game::display_system_message(this,&stack0xffffffb4);
          return 1;
        }
        if (rge_base_game->prog_mode == 5) {
          return 1;
        }
        TCommunications_Handler::SendGroupChatMsg(comm,&stack0xffffffb4);
        return 1;
      }
    }
    else if (param_3 != 1) goto LAB_00441819;
    TPanelSystem::setCurrentPanel(&panel_system,s_Game_Screen,0);
    TPanelSystem::destroyPanel(&panel_system,s_Send_Quick_Message_Dialog);
    return 1;
  }
LAB_00441819:
  lVar4 = TEasy_Panel::action(param_1,(TPanel *)param_2,param_3,param_4,param_5);
  return lVar4;
}

// --------------------------------------------------

// Function: FUN_00441835
// Address: 00441835
long __thiscall FUN_00441835(TEasy_Panel *param_1,undefined4 param_2,long param_3,long param_4)
{
  int iVar1;
  int iVar2;
  long lVar3;
  uchar unaff_BL;
  
  iVar1 = param_1->_padding_;
  iVar2 = (**(code **)(iVar1 + 0xbc))(param_3,param_4);
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0xb4))(param_1[1]._padding_,1,0,0);
    return 1;
  }
  lVar3 = TEasy_Panel::handle_mouse_down(param_1,unaff_BL,param_3,param_4,param_3,param_4);
  return lVar3;
}

// --------------------------------------------------

// Function: FUN_0044189a
// Address: 0044189a
RGE_Doppleganger_Object * __thiscall
FUN_0044189a(RGE_Doppleganger_Object *param_1,RGE_Master_Animated_Object *param_2,
            RGE_Player *param_3,float param_4,float param_5,float param_6,int param_7,
            RGE_Static_Object *param_8)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  RGE_Active_Sprite_Node *pRVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d298;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Animated_Object::RGE_Animated_Object
            ((RGE_Animated_Object *)param_1,param_2,param_3,param_4,param_5,param_6,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Doppleganger_Object::_vftable_;
  param_1->doppled_object = (RGE_Static_Object *)0x0;
  param_1->draw_color = (RGE_Color_Table *)0x0;
  param_1->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
  param_1->doppled_player = 0;
  param_1->MapAddress = (ulong *)0x0;
  param_1->LastMapValue = 0;
  param_1->CantSeeBits = 0;
  param_1->map_draw_level = '\0';
  param_1->map_color = '\0';
  param_1->doppledObjectID = -1;
  if (param_7 != 0) {
    RGE_Doppleganger_Object::setup
              (param_1,(RGE_Master_Doppleganger_Object *)param_2,param_3,param_4,param_5,param_6);
  }
  param_1->doppled_object = param_8;
  if (param_8 == (RGE_Static_Object *)0x0) {
    param_1->doppledObjectID = -1;
    param_1->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
    param_1->doppled_player = 0;
    RGE_Static_Object::destroy_obj((RGE_Static_Object *)param_1);
  }
  else {
    param_1->doppled_master_obj = param_8->master_obj;
    param_1->doppled_player = (int)param_8->owner->id;
    param_1->doppledObjectID = param_8->id;
    param_1->_padding_ = (int)param_8->sprite;
    pRVar3 = RGE_Active_Sprite_List::copy_sprite_list(param_8->sprite_list);
    RGE_Active_Sprite_List::use_sprite_list((RGE_Active_Sprite_List *)param_1->_padding_,pRVar3);
    pRVar2 = param_1->doppled_object;
    *(uchar *)((int)&param_1->_padding_ + 1) = pRVar2->facet;
    param_1->draw_color = pRVar2->owner->color_table;
    uVar1 = pRVar2->master_obj->map_draw_level;
    param_1->map_draw_level = uVar1;
    if (uVar1 == '\x03') {
      param_1->map_color = pRVar2->master_obj->map_color;
    }
    else {
      param_1->map_color = pRVar2->owner->color_table->map_color;
    }
    if (6 < pRVar2->object_state) {
      param_1->doppled_object = (RGE_Static_Object *)0x0;
      param_1->doppledObjectID = -1;
    }
  }
  RGE_Doppleganger_Object::validate(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00441a3a
// Address: 00441a3a
RGE_Doppleganger_Object * __thiscall FUN_00441a3a(RGE_Doppleganger_Object *param_1,byte param_2)
{
  RGE_Doppleganger_Object::~RGE_Doppleganger_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00441a65
// Address: 00441a65
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

RGE_Doppleganger_Object * __thiscall
FUN_00441a65(RGE_Doppleganger_Object *param_1,RGE_Master_Static_Object *param_2,
            RGE_Game_World *param_3,int param_4)
{
  RGE_Master_Static_Object *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pRVar1 = param_2;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d2b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Animated_Object::RGE_Animated_Object((RGE_Animated_Object *)param_1,(int)param_2,param_3,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Doppleganger_Object::_vftable_;
  param_1->doppled_object = (RGE_Static_Object *)0x0;
  param_1->draw_color = (RGE_Color_Table *)0x0;
  param_1->doppled_master_obj = (RGE_Master_Static_Object *)0x0;
  param_1->doppled_player = 0;
  param_1->MapAddress = (ulong *)0x0;
  param_1->LastMapValue = 0;
  param_1->CantSeeBits = 0;
  param_1->map_draw_level = '\0';
  param_1->map_color = '\0';
  param_1->doppledObjectID = -1;
  if (param_4 != 0) {
    RGE_Doppleganger_Object::setup(param_1,(int)pRVar1,param_3);
  }
  rge_read((int)pRVar1,&param_2,4);
  param_1->doppled_object = (RGE_Static_Object *)param_2;
  param_1->doppledObjectID = -1;
  rge_read((int)pRVar1,&param_1->map_draw_level,1);
  rge_read((int)pRVar1,&param_1->map_color,4);
  rge_read((int)pRVar1,&param_2,4);
  param_1->doppled_master_obj = param_2;
  rge_read((int)pRVar1,&param_1->doppled_player,4);
  if (_DAT_00570418 <= save_game_version) {
    rge_read((int)pRVar1,&param_1->CantSeeBits,4);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00441bae
// Address: 00441bae
void __thiscall
FUN_00441bae(RGE_Animated_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  char cVar1;
  int iVar2;
  ulong **ppuVar3;
  RGE_Active_Sprite_Node *pRVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  *(undefined1 *)&param_1[1]._padding_ = 0;
  *(undefined1 *)((int)&param_1[1]._padding_ + 1) = 0;
  param_1[1]._padding_ = -1;
  RGE_Animated_Object::recycle_in_to_game(param_1,param_2,param_3,param_4,param_5,param_6);
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x19;
  param_1[1]._padding_ = param_7;
  if (param_7 == 0) {
    iVar2 = param_1->_padding_;
    param_1[1]._padding_ = -1;
    param_1[1]._padding_ = 0;
    param_1[1]._padding_ = 0;
    (**(code **)(iVar2 + 0x68))();
  }
  else {
    param_1[1]._padding_ = *(int *)(param_7 + 8);
    param_1[1]._padding_ = (int)*(short *)(*(int *)(param_7 + 0xc) + 0x4a);
    param_1[1]._padding_ = *(int *)(param_7 + 4);
    param_1->_padding_ = *(int *)(param_7 + 0x10);
    pRVar4 = RGE_Active_Sprite_List::copy_sprite_list(*(RGE_Active_Sprite_List **)(param_7 + 0x18));
    RGE_Active_Sprite_List::use_sprite_list((RGE_Active_Sprite_List *)param_1->_padding_,pRVar4);
    iVar2 = param_1[1]._padding_;
    *(undefined1 *)((int)&param_1->_padding_ + 1) = *(undefined1 *)(iVar2 + 0x35);
    param_1[1]._padding_ = *(int *)(*(int *)(iVar2 + 0xc) + 0x108);
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x8e);
    *(char *)&param_1[1]._padding_ = cVar1;
    if (cVar1 == '\x03') {
      uVar7 = *(undefined1 *)(*(int *)(iVar2 + 8) + 0x90);
    }
    else {
      uVar7 = *(undefined1 *)(*(int *)(*(int *)(iVar2 + 0xc) + 0x108) + 0x25);
    }
    *(undefined1 *)((int)&param_1[1]._padding_ + 1) = uVar7;
    iVar5 = __ftol();
    iVar6 = __ftol();
    ppuVar3 = (&unified_map_offsets)[iVar5];
    param_1[1]._padding_ = 0;
    param_1[1]._padding_ = 0;
    param_1[1]._padding_ = (int)(ppuVar3 + iVar6);
    if (6 < *(byte *)(iVar2 + 0x48)) {
      iVar2 = param_1->_padding_;
      param_1[1]._padding_ = 0;
      param_1[1]._padding_ = -1;
      (**(code **)(iVar2 + 0x1f0))();
      return;
    }
  }
  (**(code **)(param_1->_padding_ + 0x1f0))();
  return;
}

// --------------------------------------------------

// Function: FUN_00441d94
// Address: 00441d94
undefined4 __thiscall FUN_00441d94(RGE_Animated_Object *param_1,int param_2,RGE_Game_World *param_3)
{
  int iVar1;
  int iVar2;
  
  RGE_Animated_Object::setup(param_1,param_2,param_3);
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x19;
  iVar1 = __ftol();
  iVar2 = __ftol();
  param_1[1]._padding_ = (int)((&unified_map_offsets)[iVar1] + iVar2);
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00441df3
// Address: 00441df3
void __fastcall FUN_00441df3(RGE_Static_Object *param_1)
{
  int iVar1;
  RGE_Player *pRVar2;
  RGE_Static_Object *pRVar3;
  RGE_Player *pRVar4;
  
  RGE_Static_Object::rehook(param_1);
  iVar1 = param_1[1].id;
  if (iVar1 < 0) {
    param_1[1].id = 0;
    pRVar4 = param_1->owner;
    param_1[1].objects = (RGE_Object_List *)0xffffffff;
    pRVar4 = pRVar4->world->players[-1 - iVar1];
  }
  else {
    pRVar3 = RGE_Static_Object::get_object_pointer(param_1,iVar1);
    param_1[1].id = (long)pRVar3;
    if (pRVar3 == (RGE_Static_Object *)0x0) goto LAB_00441e63;
    param_1[1].objects = (RGE_Object_List *)pRVar3->id;
    pRVar4 = pRVar3->owner;
  }
  param_1[1].master_obj = (RGE_Master_Static_Object *)pRVar4->color_table;
LAB_00441e63:
  pRVar4 = param_1[1].owner;
  if ((-1 < (int)pRVar4) &&
     (pRVar2 = param_1->owner->world->players[(int)param_1[1].sprite],
     (int)pRVar4 < (int)pRVar2->master_object_num)) {
    param_1[1].owner = (RGE_Player *)pRVar2->master_objects[(int)pRVar4];
    return;
  }
  iVar1 = param_1->_padding_;
  param_1[1].owner = (RGE_Player *)0x0;
  (**(code **)(iVar1 + 0x68))();
  return;
}

// --------------------------------------------------

// Function: FUN_00441ea8
// Address: 00441ea8
// [HELPER] s_DIE_DOP____d__id__d_own__d_: "DIE DOP (@%d) id=%d own=%d\n"
undefined4 __fastcall FUN_00441ea8(RGE_Animated_Object *param_1)
{
  uint uVar1;
  int iVar2;
  uchar uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar3 = RGE_Animated_Object::update(param_1);
  if (param_1[1]._padding_ != 0) {
    if (*(byte *)(param_1[1]._padding_ + 0x48) < 7) goto LAB_00441ee1;
    param_1[1]._padding_ = 0;
  }
  param_1[1]._padding_ = -1;
LAB_00441ee1:
  uVar1 = *(uint *)param_1[1]._padding_;
  uVar4 = param_1[1]._padding_;
  if (uVar1 != uVar4) {
    iVar2 = param_1->_padding_;
    if (((*(uint *)(iVar2 + 0xd4) & uVar1) != 0) && ((byte)param_1->_padding_ < 3)) {
      if (DDlogf != (_iobuf *)0x0) {
        fprintf(DDlogf,s_DIE_DOP____d__id__d_own__d_,*(undefined4 *)(*(int *)(iVar2 + 0x3c) + 4),
                param_1->_padding_,(int)*(short *)(iVar2 + 0x4a));
      }
      (**(code **)(param_1->_padding_ + 0x68))();
    }
    uVar4 = *(uint *)(param_1->_padding_ + 0xd8) & uVar1;
    if (uVar4 != 0) {
      puVar5 = (uint *)(param_1->_padding_ + 0xdc);
      do {
        if (((byte)uVar4 & 1) == 1) {
          param_1[1]._padding_ = param_1[1]._padding_ | *puVar5;
        }
        puVar5 = puVar5 + 1;
        uVar4 = uVar4 >> 1;
      } while (uVar4 != 0);
    }
    param_1[1]._padding_ = uVar1;
  }
  return CONCAT31((int3)(uVar4 >> 8),uVar3);
}

// --------------------------------------------------

// Function: FUN_00441f74
// Address: 00441f74
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00441f74(RGE_Animated_Object *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = param_2;
  RGE_Animated_Object::save(param_1,param_2);
  if (param_1[1]._padding_ == 0) {
    param_2 = -1 - param_1[1]._padding_;
  }
  else {
    param_2 = *(int *)(param_1[1]._padding_ + 4);
  }
  rge_write(iVar1,&param_2,4);
  rge_write(iVar1,&param_1[1]._padding_,1);
  rge_write(iVar1,(void *)((int)&param_1[1]._padding_ + 1),4);
  if (param_1[1]._padding_ == 0) {
    param_2 = -1;
  }
  else {
    param_2 = (int)*(short *)(param_1[1]._padding_ + 0x10);
  }
  rge_write(iVar1,&param_2,4);
  rge_write(iVar1,&param_1[1]._padding_,4);
  if (_DAT_00570418 <= save_game_version) {
    rge_write(iVar1,&param_1[1]._padding_,4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044204c
// Address: 0044204c
void __fastcall FUN_0044204c(int param_1)
{
  short sVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x28);
  iVar5 = __ftol();
  iVar2 = *(int *)(iVar2 + 0x8d8c);
  iVar6 = __ftol();
  for (piVar3 = *(int **)(*(int *)(iVar2 + iVar5 * 4) + 0x10 + iVar6 * 0x18); piVar3 != (int *)0x0;
      piVar3 = (int *)piVar3[1]) {
    piVar4 = (int *)*piVar3;
    if ((((piVar4 != (int *)0x0) && (*(char *)((int)piVar4 + 0x4e) == '\x19')) &&
        (piVar4[1] != *(int *)(param_1 + 4))) &&
       ((piVar4[0x2b] == *(int *)(param_1 + 0xac) && ((char)piVar4[0x12] == '\x02')))) {
      sVar1 = *(short *)(*(int *)(param_1 + 0xc) + 0x4a);
      if (*(short *)(piVar4[3] + 0x4a) == sVar1) {
        (**(code **)(*piVar4 + 0x68))();
      }
      else {
        piVar4[0x29] = piVar4[0x29] | 1 << ((byte)sVar1 & 0x1f);
        *(uint *)(param_1 + 0xa4) =
             *(uint *)(param_1 + 0xa4) | 1 << (*(byte *)(piVar4[3] + 0x4a) & 0x1f);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004420fc
// Address: 004420fc
// [HELPER] s_c__aoedoppl_txt: "c:\aoedoppl.txt"
// [HELPER] s_w: "w"
undefined4 * __thiscall FUN_004420fc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  
  uVar1 = calloc(param_3,4);
  param_1[3] = uVar1;
  uVar1 = calloc(param_3,4);
  param_1[4] = uVar1;
  uVar1 = calloc(param_3,4);
  param_1[5] = uVar1;
  uVar1 = calloc(param_3,4);
  param_1[6] = uVar1;
  param_1[1] = param_3;
  param_1[2] = 0;
  *param_1 = param_2;
  if (DDlogf == (_iobuf *)0x0) {
    DDlogf = (_iobuf *)fopen(s_c__aoedoppl_txt,s_w);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00442177
// Address: 00442177
void __fastcall FUN_00442177(int param_1)
{
  if (*(int *)(param_1 + 0xc) != 0) {
    free(*(int *)(param_1 + 0xc));
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    free(*(int *)(param_1 + 0x10));
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    free(*(int *)(param_1 + 0x14));
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    free(*(int *)(param_1 + 0x18));
  }
  if (DDlogf != (_iobuf *)0x0) {
    fclose(DDlogf);
    DDlogf = (_iobuf *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004421e1
// Address: 004421e1
// [HELPER] s_ADC____d__p__d__id__d_: "ADC (@%d) p=%d  id=%d\n"
undefined4 __thiscall
FUN_004421e1(RGE_Doppleganger_Creator *param_1,RGE_Static_Object *param_2,ulong *param_3)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object **ppRVar3;
  
  if (DDlogf != (_iobuf *)0x0) {
    fprintf(DDlogf,s_ADC____d__p__d__id__d_,param_1->owner->world->world_time,
            (int)param_1->owner->id,param_2->id);
  }
  if (param_1->allocated_size <= param_1->active_size) {
    RGE_Doppleganger_Creator::expand_allocations(param_1,0x1e);
  }
  if (param_2->owner->id != param_1->owner->id) {
    return 0;
  }
  iVar1 = param_1->active_size;
  if ((0 < iVar1) && (iVar2 = 0, 0 < iVar1)) {
    ppRVar3 = param_1->Objects;
    do {
      if (*ppRVar3 == param_2) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      ppRVar3 = ppRVar3 + 1;
    } while (iVar2 < iVar1);
  }
  param_1->Objects[iVar1] = param_2;
  param_1->Map_Addresses[param_1->active_size] = param_3;
  param_1->Last_Map_Value[param_1->active_size] = *param_3;
  param_1->Object_ids[param_1->active_size] = param_2->id;
  param_1->active_size = param_1->active_size + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004422a9
// Address: 004422a9
// [HELPER] s_RDC____d___p__d__id__d_: "RDC (@%d)  p=%d  id=%d\n"
undefined4 __thiscall FUN_004422a9(int *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (DDlogf != (_iobuf *)0x0) {
    fprintf(DDlogf,s_RDC____d___p__d__id__d_,*(undefined4 *)(*(int *)(*param_1 + 0x3c) + 4),
            (int)*(short *)(*param_1 + 0x4a),*(undefined4 *)(param_2 + 4));
  }
  iVar1 = param_1[2];
  if ((0 < iVar1) && (iVar3 = 0, 0 < iVar1)) {
    piVar2 = (int *)param_1[3];
    piVar5 = piVar2;
    do {
      if (*piVar5 == param_2) {
        iVar1 = iVar1 + -1;
        param_1[2] = iVar1;
        if (iVar3 < iVar1) {
          iVar4 = iVar3 * 4;
          piVar2[iVar3] = piVar2[iVar1];
          *(undefined4 *)(param_1[4] + iVar4) = *(undefined4 *)(param_1[4] + param_1[2] * 4);
          *(undefined4 *)(param_1[5] + iVar4) = *(undefined4 *)(param_1[5] + param_1[2] * 4);
          *(undefined4 *)(param_1[6] + iVar4) = *(undefined4 *)(param_1[6] + param_1[2] * 4);
        }
        *(undefined4 *)(param_1[3] + param_1[2] * 4) = 0;
        *(undefined4 *)(param_1[4] + param_1[2] * 4) = 0;
        *(undefined4 *)(param_1[5] + param_1[2] * 4) = 0;
        *(undefined4 *)(param_1[6] + param_1[2] * 4) = 0;
        return 1;
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar3 < iVar1);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0044238f
// Address: 0044238f
// [HELPER] s_NEW_DOP____d__by_p__d_for_p__d_o: "NEW DOP (@%d) by p=%d for p=%d of id=%d (x=%d, y=%d)\n"
// [HELPER] s_____REMOVE_CHECK____d__by_p__d_i: "*** REMOVE CHECK (@%d) by p=%d id=%d\n"
void __fastcall FUN_0044238f(RGE_Doppleganger_Creator *param_1)
{
  uint uVar1;
  RGE_Player *pRVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  undefined4 uVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  uint uVar8;
  int iStack_10;
  RGE_Static_Object *pRStack_c;
  
  pRStack_c = (RGE_Static_Object *)0x0;
  if (0 < param_1->active_size) {
    iStack_10 = 0;
    pRVar6 = (RGE_Static_Object *)0x0;
    if (0 < param_1->active_size) {
      do {
        uVar1 = *param_1->Map_Addresses[iStack_10];
        if (uVar1 != param_1->Last_Map_Value[iStack_10]) {
          pRVar6 = param_1->Objects[iStack_10];
          if (pRVar6 == (RGE_Static_Object *)0x0) {
LAB_00442506:
            pRStack_c = pRVar6;
            if (DDlogf != (_iobuf *)0x0) {
              fprintf(DDlogf,s_____REMOVE_CHECK____d__by_p__d_i,param_1->owner->world->world_time,
                      (int)param_1->owner->id,param_1->Object_ids[iStack_10]);
            }
          }
          else {
            pRVar6 = param_1->Objects[iStack_10];
            pRVar3 = RGE_Game_World::object(param_1->owner->world,param_1->Object_ids[iStack_10]);
            if (pRVar3 != pRVar6) goto LAB_00442506;
            iVar7 = 1;
            for (uVar8 = ((uVar1 ^ param_1->Last_Map_Value[iStack_10]) &
                         param_1->Last_Map_Value[iStack_10]) >> 1 & 0x7fff; uVar8 != 0;
                uVar8 = uVar8 >> 1) {
              if (((byte)uVar8 & 1) == 1) {
                pRVar2 = param_1->owner;
                iVar4 = (int)pRVar2->id;
                if (iVar7 != iVar4) {
                  if (DDlogf != (_iobuf *)0x0) {
                    pRVar6 = param_1->Objects[iStack_10];
                    uVar5 = __ftol();
                    uVar5 = __ftol(uVar5);
                    fprintf(DDlogf,s_NEW_DOP____d__by_p__d_for_p__d_o,pRVar2->world->world_time,
                            iVar4,iVar7,pRVar6->id,uVar5);
                  }
                  pRVar2 = param_1->owner->world->players[iVar7];
                  pRVar6 = param_1->Objects[iStack_10];
                  (**(code **)(pRVar2->master_objects[0xf3]->_padding_ + 0x38))
                            (pRVar2,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z,pRVar6);
                }
              }
              iVar7 = iVar7 + 1;
            }
          }
          param_1->Last_Map_Value[iStack_10] = uVar1;
        }
        iStack_10 = iStack_10 + 1;
        pRVar6 = pRStack_c;
      } while (iStack_10 < param_1->active_size);
    }
    if (pRVar6 != (RGE_Static_Object *)0x0) {
      RGE_Doppleganger_Creator::remove_doppleganger_check(param_1,pRVar6);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00442539
// Address: 00442539
// [HELPER] s_RESIZE____d__p__d__grow__d_: "RESIZE (@%d) p=%d  grow=%d\n"
void __thiscall FUN_00442539(int *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (DDlogf != (_iobuf *)0x0) {
    fprintf(DDlogf,s_RESIZE____d__p__d__grow__d_,*(undefined4 *)(*(int *)(*param_1 + 0x3c) + 4),
            (int)*(short *)(*param_1 + 0x4a),param_2);
  }
  iVar6 = param_1[1];
  param_1[1] = iVar6 + param_2;
  puVar1 = (undefined4 *)calloc(iVar6 + param_2,4);
  puVar2 = (undefined4 *)calloc(param_1[1],4);
  puVar3 = (undefined4 *)calloc(param_1[1],4);
  puVar4 = (undefined4 *)calloc(param_1[1],4);
  puVar7 = (undefined4 *)param_1[3];
  puVar8 = puVar1;
  for (uVar5 = param_1[2] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  puVar7 = (undefined4 *)param_1[4];
  puVar8 = puVar2;
  for (uVar5 = param_1[2] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  puVar7 = (undefined4 *)param_1[5];
  puVar8 = puVar3;
  for (uVar5 = param_1[2] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  puVar7 = (undefined4 *)param_1[6];
  puVar8 = puVar4;
  for (uVar5 = param_1[2] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  free(param_1[3]);
  free(param_1[4]);
  free(param_1[5]);
  free(param_1[6]);
  param_1[3] = (int)puVar1;
  param_1[4] = (int)puVar2;
  param_1[5] = (int)puVar3;
  param_1[6] = (int)puVar4;
  return;
}

// --------------------------------------------------

// Function: FUN_0044267b
// Address: 0044267b
undefined4 * __fastcall FUN_0044267b(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 0x11e) = 0;
  *(undefined1 *)((int)param_1 + 0x479) = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 8;
  param_1[10] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[5] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0xe] = 0;
  system_ignore_size_messages = 0;
  _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044270b
// Address: 0044270b
void __fastcall FUN_0044270b(TDrawSystem *param_1)
{
  IDirectDrawSurface *pIVar1;
  IDirectDrawPalette *pIVar2;
  IDirectDrawClipper *pIVar3;
  undefined4 auStack_64 [20];
  undefined4 uStack_14;
  
  if ((param_1->ScreenMode == '\x02') &&
     (pIVar1 = param_1->PrimarySurface, pIVar1 != (IDirectDrawSurface *)0x0)) {
    auStack_64[0] = 100;
    uStack_14 = 0;
    (**(code **)((int)*pIVar1 + 0x14))(pIVar1,0,0,0,0x1000400,auStack_64);
  }
  TDrawSystem::DeleteSurfaces(param_1);
  if (param_1->DirDraw != (IDirectDraw *)0x0) {
    pIVar2 = param_1->DirDrawPal;
    if (pIVar2 != (IDirectDrawPalette *)0x0) {
      (**(code **)((int)*pIVar2 + 8))(pIVar2);
      param_1->DirDrawPal = (IDirectDrawPalette *)0x0;
    }
    pIVar3 = param_1->Clipper;
    if (pIVar3 != (IDirectDrawClipper *)0x0) {
      (**(code **)((int)*pIVar3 + 8))(pIVar3);
      param_1->Clipper = (IDirectDrawClipper *)0x0;
    }
    if (param_1->ChangedMode != 0) {
      (**(code **)((int)*param_1->DirDraw + 0x4c))(param_1->DirDraw);
      param_1->ChangedMode = 0;
    }
    (**(code **)((int)*param_1->DirDraw + 8))(param_1->DirDraw);
    param_1->DirDraw = (IDirectDraw *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00442797
// Address: 00442797
// [HELPER] s_DISPLAY: "DISPLAY"
void __thiscall FUN_00442797(int param_1,int param_2)
{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x4c) = 1;
    iVar3 = CreateICA(s_DISPLAY,0,0,0);
    if (iVar3 != 0) {
      iVar4 = GetDeviceCaps(iVar3,8);
      GetDeviceCaps(iVar3,10);
      DeleteDC(iVar3);
      if (799 < iVar4) {
        *(undefined4 *)(param_1 + 0x50) = 1;
      }
      if (0x3ff < iVar4) {
        *(undefined4 *)(param_1 + 0x54) = 1;
      }
      if (0x4ff < iVar4) {
        *(undefined4 *)(param_1 + 0x58) = 1;
        return;
      }
    }
  }
  else {
    puVar1 = (undefined4 *)(param_1 + 0x18);
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar3 = _DirectDrawCreate_12(0,puVar1,0);
      if (iVar3 != 0) {
        return;
      }
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    (**(code **)(*(int *)*puVar1 + 0x20))
              ((int *)*puVar1,0,0,param_1,TDrawSystem::CheckAvailModesCallback);
    if (!bVar2) {
      (**(code **)(*(int *)*puVar1 + 8))((int *)*puVar1);
      *puVar1 = 0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044285e
// Address: 0044285e
void FUN_0044285e(int param_1,int param_2)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x54) == 8) {
    iVar1 = *(int *)(param_1 + 0xc);
    if ((iVar1 == 0x280) && (*(int *)(param_1 + 8) == 0x1e0)) {
      *(undefined4 *)(param_2 + 0x4c) = 1;
      return;
    }
    if ((iVar1 == 800) && (*(int *)(param_1 + 8) == 600)) {
      *(undefined4 *)(param_2 + 0x50) = 1;
      return;
    }
    if ((iVar1 == 0x400) && (*(int *)(param_1 + 8) == 0x300)) {
      *(undefined4 *)(param_2 + 0x54) = 1;
      return;
    }
    if ((iVar1 == 0x500) && (*(int *)(param_1 + 8) == 0x400)) {
      *(undefined4 *)(param_2 + 0x58) = 1;
      return;
    }
    if (iVar1 == 0x140) {
      if (*(int *)(param_1 + 8) == 200) {
        *(undefined4 *)(param_2 + 0x5c) = 1;
        return;
      }
      if (*(int *)(param_1 + 8) == 0xf0) {
        *(undefined4 *)(param_2 + 0x60) = 1;
        return;
      }
    }
  }
  else if (*(int *)(param_1 + 0x54) == 0x10) {
    iVar1 = *(int *)(param_1 + 0xc);
    if ((iVar1 == 0x280) && (*(int *)(param_1 + 8) == 0x1e0)) {
      *(undefined4 *)(param_2 + 0x6c) = 1;
      return;
    }
    if ((iVar1 == 800) && (*(int *)(param_1 + 8) == 600)) {
      *(undefined4 *)(param_2 + 0x70) = 1;
      return;
    }
    if ((iVar1 == 0x400) && (*(int *)(param_1 + 8) == 0x300)) {
      *(undefined4 *)(param_2 + 0x74) = 1;
      return;
    }
    if (iVar1 == 0x140) {
      if (*(int *)(param_1 + 8) == 200) {
        *(undefined4 *)(param_2 + 100) = 1;
        return;
      }
      if (*(int *)(param_1 + 8) == 0xf0) {
        *(undefined4 *)(param_2 + 0x68) = 1;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004429b9
// Address: 004429b9
undefined4 __thiscall FUN_004429b9(int param_1,int param_2,int param_3,int param_4)
{
  if (param_4 == 8) {
    if (param_2 < 0x281) {
      if (param_2 == 0x280) {
        return *(undefined4 *)(param_1 + 0x4c);
      }
      if (param_2 == 0x140) {
        if (param_3 == 200) {
          return *(undefined4 *)(param_1 + 0x5c);
        }
        if (param_3 == 0xf0) {
          return *(undefined4 *)(param_1 + 0x60);
        }
      }
    }
    else {
      if (param_2 == 800) {
        return *(undefined4 *)(param_1 + 0x50);
      }
      if (param_2 == 0x400) {
        return *(undefined4 *)(param_1 + 0x54);
      }
      if (param_2 == 0x500) {
        return *(undefined4 *)(param_1 + 0x58);
      }
    }
  }
  else if (param_4 == 0x10) {
    if (param_2 < 0x281) {
      if (param_2 == 0x280) {
        return *(undefined4 *)(param_1 + 0x6c);
      }
      if (param_2 == 0x140) {
        if (param_3 == 200) {
          return *(undefined4 *)(param_1 + 100);
        }
        if (param_3 == 0xf0) {
          return *(undefined4 *)(param_1 + 0x68);
        }
      }
    }
    else {
      if (param_2 == 800) {
        return *(undefined4 *)(param_1 + 0x70);
      }
      if (param_2 == 0x400) {
        return *(undefined4 *)(param_1 + 0x74);
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00442a8c
// Address: 00442a8c
undefined4 __thiscall
FUN_00442a8c(TDrawSystem *param_1,void *param_2,void *param_3,void *param_4,uchar param_5,
            uchar param_6,int param_7,int param_8,ulong param_9)
{
  IDirectDraw **ppIVar1;
  IDirectDraw *pIVar2;
  IDirectDrawPalette *pIVar3;
  IDirectDrawClipper *pIVar4;
  IDirectDraw IVar5;
  int iVar6;
  undefined1 *puVar7;
  uchar *puVar8;
  undefined4 auStack_604 [14];
  int iStack_5cc;
  undefined4 uStack_5b4;
  uint uStack_59c;
  uint auStack_594 [96];
  undefined1 auStack_414 [1044];
  
  param_1->Wnd = param_3;
  param_1->Pal = param_4;
  param_1->Inst = param_2;
  param_1->ScreenMode = param_6;
  param_1->ScreenWidth = param_7;
  param_1->DrawType = param_5;
  param_1->ScreenHeight = param_8;
  param_1->Flags = param_9;
  if (param_5 == '\x01') {
    return 0;
  }
  ppIVar1 = &param_1->DirDraw;
  iVar6 = _DirectDrawCreate_12(0,ppIVar1,0);
  if (iVar6 != 0) {
    param_1->ErrorCode = 1;
    return 0;
  }
  TDrawSystem::CheckAvailModes(param_1,1);
  pIVar2 = *ppIVar1;
  if (param_1->ScreenMode == '\x01') {
    iVar6 = (**(code **)((int)*pIVar2 + 0x50))(pIVar2,param_1->Wnd,8);
    if (iVar6 != 0) {
      param_1->ErrorCode = 1;
      return 0;
    }
    memset(&stack0xfffff9e8,0,0x6c);
    iVar6 = (**(code **)((int)**ppIVar1 + 0x30))(*ppIVar1,&stack0xfffff9e8);
    if (iVar6 != 0) {
      param_1->ErrorCode = 1;
      return 0;
    }
    if (iStack_5cc != 8) {
      param_1->ErrorCode = 2;
      return 0;
    }
  }
  else {
    iVar6 = (**(code **)((int)*pIVar2 + 0x50))(pIVar2,param_1->Wnd,0x11);
    if (iVar6 != 0) {
      param_1->ErrorCode = 1;
      return 0;
    }
    IVar5 = **ppIVar1;
    param_1->ColorBits = 8;
    iVar6 = (**(code **)((int)IVar5 + 0x54))(*ppIVar1,param_1->ScreenWidth,param_1->ScreenHeight,8);
    if (iVar6 != 0) {
      param_1->ErrorCode = 1;
      return 0;
    }
    param_1->ChangedMode = 1;
  }
  if (param_1->Pal == (void *)0x0) {
    puVar7 = auStack_414 + 1;
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
    GetPaletteEntries(param_1->Pal,0,0x100,auStack_414);
  }
  puVar8 = &param_1->palette[0].peBlue;
  iVar6 = 0x100;
  do {
    ((tagPALETTEENTRY *)(puVar8 + -2))->peRed = '\0';
    *puVar8 = '\0';
    puVar8[-1] = '\0';
    puVar8[1] = '\0';
    puVar8 = puVar8 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = (**(code **)((int)**ppIVar1 + 0x14))(*ppIVar1,0x44,auStack_414,&param_1->DirDrawPal,0);
  if (iVar6 != 0) {
    param_1->ErrorCode = 1;
    return 0;
  }
  pIVar3 = param_1->DirDrawPal;
  (**(code **)((int)*pIVar3 + 0x18))(pIVar3,0,0,0x100,param_1->palette);
  iVar6 = (**(code **)((int)**ppIVar1 + 0x10))(*ppIVar1,0,&param_1->Clipper,0);
  if (iVar6 != 0) {
    param_1->ErrorCode = 1;
    return 0;
  }
  pIVar4 = param_1->Clipper;
  iVar6 = (**(code **)((int)*pIVar4 + 0x20))(pIVar4,0,param_1->Wnd);
  if (iVar6 != 0) {
    param_1->ErrorCode = 1;
    return 0;
  }
  iVar6 = TDrawSystem::CreateSurfaces(param_1);
  if (iVar6 == 0) {
    param_1->ErrorCode = 1;
    return 0;
  }
  IVar5 = **ppIVar1;
  param_1->IsBanked = 0;
  auStack_594[0] = 0x13c;
  iVar6 = (**(code **)((int)IVar5 + 0x2c))(*ppIVar1,auStack_594,0);
  if (iVar6 == 0) {
    if ((uStack_59c & 0x8000000) != 0) {
      param_1->IsBanked = 1;
    }
    if (((uStack_59c & 0x400000) != 0) && ((auStack_594[0] & 0x200) != 0)) {
      param_1->CanSrcBlt = 1;
    }
  }
  if (param_1->ScreenMode == '\x02') {
    auStack_604[0] = 100;
    uStack_5b4 = 0;
    (**(code **)((int)*param_1->PrimarySurface + 0x14))
              (param_1->PrimarySurface,0,0,0,0x1000400,auStack_604);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00442db2
// Address: 00442db2
undefined4 __fastcall FUN_00442db2(TDrawSystem *param_1)
{
  IDirectDraw IVar1;
  uint uVar2;
  int iVar3;
  IDirectDrawSurface *pIVar4;
  int iVar5;
  undefined4 auStack_64 [20];
  uint uStack_14;
  int iStack_10;
  int iStack_c;
  
  if ((param_1->DrawType == '\x02') && (param_1->ScreenMode == '\x02')) {
    system_ignore_size_messages = 1;
    pIVar4 = param_1->PrimarySurface;
    iVar5 = 0;
    auStack_64[0] = 100;
    uStack_14 = 0;
    (**(code **)((int)*pIVar4 + 0x14))(pIVar4,0,0,0,0x1000400,auStack_64);
    uVar2 = uStack_14;
    IVar1 = *param_1->DirDraw;
    param_1->ScreenWidth = uStack_14;
    param_1->ScreenHeight = iStack_10;
    iVar3 = (**(code **)((int)IVar1 + 0x54))(param_1->DirDraw,uStack_14,iStack_10,iStack_c);
    system_ignore_size_messages = 0;
    if (iVar3 != 0) {
      param_1->ScreenWidth = (int)pIVar4;
      param_1->ScreenHeight = iVar5;
      return 0;
    }
    pIVar4 = param_1->PrimarySurface;
    param_1->ColorBits = iStack_c;
    param_1->ChangedMode = 1;
    if (pIVar4 != (IDirectDrawSurface *)0x0) {
      (**(code **)((int)*pIVar4 + 8))(pIVar4);
      param_1->PrimarySurface = (IDirectDrawSurface *)0x0;
    }
    TDrawSystem::CreateSurfaces(param_1);
    if (param_1->DrawArea != (TDrawArea *)0x0) {
      TDrawArea::SetSize(param_1->DrawArea,param_1->ScreenWidth,param_1->ScreenHeight,0);
    }
    SendMessageA(param_1->Wnd,5,0,iStack_10 << 0x10 | uVar2 & 0xffff);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00442eec
// Address: 00442eec
void __fastcall FUN_00442eec(int param_1)
{
  int *piVar1;
  undefined4 auStack_64 [20];
  undefined4 uStack_14;
  
  if ((*(char *)(param_1 + 0x479) == '\x02') &&
     (piVar1 = *(int **)(param_1 + 0x1c), piVar1 != (int *)0x0)) {
    auStack_64[0] = 100;
    uStack_14 = 0;
    (**(code **)(*piVar1 + 0x14))(piVar1,0,0,0,0x1000400,auStack_64);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00442f2e
// Address: 00442f2e
undefined1 __fastcall FUN_00442f2e(TDrawSystem *param_1)
{
  IDirectDrawSurface *pIVar1;
  IDirectDrawSurface IVar2;
  DrawAreaNode *pDVar3;
  uchar uVar4;
  int iVar5;
  undefined1 uVar6;
  int iStack_d0;
  int iStack_88;
  undefined4 auStack_74 [20];
  undefined4 uStack_24;
  
  if (param_1->DrawType != '\x02') {
    return 0;
  }
  pIVar1 = param_1->PrimarySurface;
  if (((pIVar1 != (IDirectDrawSurface *)0x0) && (param_1->DrawArea != (TDrawArea *)0x0)) &&
     (param_1->DrawArea->DrawSurface != (IDirectDrawSurface *)0x0)) {
    uVar6 = 0;
    iVar5 = (**(code **)((int)*pIVar1 + 0x60))(pIVar1);
    if (iVar5 != 0) {
      TDrawSystem::GetIsLostErrorNum(param_1,iVar5);
      memset(&stack0xffffff2c,0,0x6c);
      iVar5 = (**(code **)((int)*param_1->DirDraw + 0x30))(param_1->DirDraw,&stack0xffffff2c);
      if ((iVar5 == 0) &&
         (((iStack_d0 != param_1->ScreenWidth || (param_1->ScreenHeight != 0x6c)) ||
          (iStack_88 != 8)))) {
        return 1;
      }
      iVar5 = (**(code **)((int)*param_1->PrimarySurface + 0x6c))(param_1->PrimarySurface);
      if (iVar5 != 0) {
        TDrawSystem::GetRestoreErrorNum(param_1,iVar5);
        return 3;
      }
      IVar2 = *param_1->PrimarySurface;
      param_1->Restored = 1;
      uVar6 = 2;
      auStack_74[0] = 100;
      uStack_24 = 0;
      (**(code **)((int)IVar2 + 0x14))(param_1->PrimarySurface,0,0,0,0x1000400,auStack_74);
    }
    pDVar3 = param_1->DrawAreaList;
    while( true ) {
      if (pDVar3 == (DrawAreaNode *)0x0) {
        return uVar6;
      }
      if ((pDVar3->DrawArea != param_1->PrimaryArea) &&
         (uVar4 = TDrawArea::CheckSurface(pDVar3->DrawArea), uVar4 == '\x03')) break;
      pDVar3 = pDVar3->NextNode;
    }
  }
  return 3;
}

// --------------------------------------------------

// Function: FUN_0044306e
// Address: 0044306e
void __fastcall FUN_0044306e(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x48) = 0;
  for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
    *(undefined4 *)(*piVar1 + 0xf4) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044308c
// Address: 0044308c
void __fastcall FUN_0044308c(int param_1)
{
  TDrawArea *pTVar1;
  
  pTVar1 = *(TDrawArea **)(param_1 + 0xc);
  if (pTVar1 != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(pTVar1);
    operator_delete(pTVar1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    pTVar1 = *(TDrawArea **)(param_1 + 0x10);
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar1);
      operator_delete(pTVar1);
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
    (**(code **)(**(int **)(param_1 + 0x1c) + 8))(*(int **)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004430ea
// Address: 004430ea
// [HELPER] s_Back_Buffer: "Back Buffer"
// [HELPER] s_Primary_Surface: "Primary Surface"
undefined4 __fastcall FUN_004430ea(TDrawSystem *param_1)
{
  IDirectDrawSurface **ppIVar1;
  int iVar2;
  TDrawArea *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_ec [8];
  long lStack_e4;
  long lStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 auStack_80 [3];
  undefined4 uStack_74;
  undefined4 uStack_30;
  undefined4 uStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d2ec;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_1->DrawType == '\x02') {
    ppIVar1 = &param_1->PrimarySurface;
    if (param_1->PrimarySurface == (IDirectDrawSurface *)0x0) {
      memset(&uStack_dc,0,0x6c);
      uStack_dc = 0x6c;
      uStack_d8 = 1;
      uStack_74 = 0x200;
      iVar2 = (**(code **)((int)*param_1->DirDraw + 0x18))(param_1->DirDraw,&uStack_dc,ppIVar1,0);
      if (iVar2 != 0) {
        *unaff_FS_OFFSET = uStack_1c;
        return 0;
      }
      if (param_1->ScreenMode == '\x02') {
        auStack_80[0] = 100;
        uStack_30 = 0;
        (**(code **)((int)**ppIVar1 + 0x14))(*ppIVar1,0,0,0,0x1000400,auStack_80);
      }
      if (param_1->ColorBits == 8) {
        iVar2 = (**(code **)((int)**ppIVar1 + 0x7c))(*ppIVar1,param_1->DirDrawPal);
        if (iVar2 != 0) {
          *unaff_FS_OFFSET = uStack_1c;
          return 0;
        }
      }
      iVar2 = (**(code **)((int)**ppIVar1 + 0x70))(*ppIVar1,param_1->Clipper);
      if (iVar2 != 0) {
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
    }
    if (param_1->PrimaryArea == (TDrawArea *)0x0) {
      pTVar3 = (TDrawArea *)operator_new(0x100);
      uStack_4 = 0;
      if (pTVar3 == (TDrawArea *)0x0) {
        pTVar3 = (TDrawArea *)0x0;
      }
      else {
        pTVar3 = (TDrawArea *)TDrawArea::TDrawArea(pTVar3,s_Primary_Surface,0);
      }
      uStack_4 = 0xffffffff;
      param_1->PrimaryArea = pTVar3;
      if (pTVar3 == (TDrawArea *)0x0) {
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
      if (param_1->ScreenMode == '\x01') {
        GetClientRect(param_1->Wnd,auStack_ec);
        iVar2 = TDrawArea::Init(param_1->PrimaryArea,param_1,lStack_e4,lStack_e0,0,1);
        if (iVar2 == 0) {
          *unaff_FS_OFFSET = uStack_c;
          return 0;
        }
      }
      else {
        iVar2 = TDrawArea::Init(pTVar3,param_1,param_1->ScreenWidth,param_1->ScreenHeight,0,1);
        if (iVar2 == 0) {
          *unaff_FS_OFFSET = uStack_c;
          return 0;
        }
      }
    }
  }
  if (param_1->DrawArea == (TDrawArea *)0x0) {
    pTVar3 = (TDrawArea *)operator_new(0x100);
    uStack_4 = 1;
    if (pTVar3 == (TDrawArea *)0x0) {
      pTVar3 = (TDrawArea *)0x0;
    }
    else {
      pTVar3 = (TDrawArea *)TDrawArea::TDrawArea(pTVar3,s_Back_Buffer,0);
    }
    uStack_4 = 0xffffffff;
    param_1->DrawArea = pTVar3;
    if (pTVar3 == (TDrawArea *)0x0) {
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    if (param_1->ScreenMode == '\x01') {
      GetClientRect(param_1->Wnd,auStack_ec);
      iVar2 = TDrawArea::Init(param_1->DrawArea,param_1,lStack_e4,lStack_e0,0,0);
      if (iVar2 == 0) {
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
    }
    else {
      iVar2 = TDrawArea::Init(pTVar3,param_1,param_1->ScreenWidth,param_1->ScreenHeight,0,0);
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

// Function: FUN_0044345d
// Address: 0044345d
void __thiscall
FUN_0044345d(TDrawSystem *param_1,void *param_2,uint param_3,uint param_4,long param_5)
{
  if (param_2 != param_1->Wnd) {
    TDrawSystem::HandleQueryNewPalette(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00443483
// Address: 00443483
undefined4 __fastcall FUN_00443483(TDrawSystem *param_1)
{
  char cVar1;
  undefined4 uVar2;
  
  if ((param_1->Pal != (void *)0x0) &&
     ((param_1->DrawType == '\x01' || (param_1->ScreenMode == '\x01')))) {
    uVar2 = GetDC(param_1->Wnd);
    if (param_1->Pal != (void *)0x0) {
      SelectPalette(uVar2,param_1->Pal,0);
    }
    cVar1 = RealizePalette(uVar2);
    ReleaseDC(param_1->Wnd,uVar2);
    if (cVar1 != '\0') {
      InvalidateRect(param_1->Wnd,0,0);
      return 1;
    }
  }
  TDrawSystem::ModifyPalette(param_1,0,0x100,param_1->palette);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00443516
// Address: 00443516
void __thiscall FUN_00443516(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if ((((*(char *)(param_1 + 0x478) != '\x01') && (*(int *)(param_1 + 0x1c) != 0)) &&
      (*(int *)(param_1 + 0xc) != 0)) && (*(int *)(*(int *)(param_1 + 0xc) + 0x3c) != 0)) {
    if (*(char *)(param_1 + 0x479) == '\x01') {
      GetClientRect(*(undefined4 *)(param_1 + 4),&iStack_10);
      iStack_1c = iStack_c;
      iStack_18 = iStack_8;
      iStack_20 = iStack_10;
      iStack_14 = iStack_4;
      ClientToScreen(*(undefined4 *)(param_1 + 4),&iStack_20);
      ClientToScreen(*(undefined4 *)(param_1 + 4),&iStack_18);
    }
    else {
      iStack_18 = *(int *)(param_1 + 0x2c);
      iStack_14 = *(int *)(param_1 + 0x30);
      iStack_10 = 0;
      iStack_c = 0;
      iStack_20 = 0;
      iStack_1c = 0;
      iStack_8 = iStack_18;
      iStack_4 = iStack_14;
    }
    if (param_2 != (int *)0x0) {
      iStack_10 = *param_2;
      iStack_c = param_2[1];
      iVar1 = param_2[2];
      iVar2 = param_2[3];
      if (iStack_10 < 0) {
        iStack_10 = 0;
      }
      if (iStack_c < 0) {
        iStack_c = 0;
      }
      if (*(int *)(param_1 + 0x2c) <= iVar1) {
        iVar1 = *(int *)(param_1 + 0x2c) + -1;
      }
      if (*(int *)(param_1 + 0x30) <= iVar2) {
        iVar2 = *(int *)(param_1 + 0x30) + -1;
      }
      iStack_20 = iStack_20 + iStack_10;
      iStack_1c = iStack_1c + iStack_c;
      iStack_8 = iVar1 + 1;
      iStack_4 = iVar2 + 1;
      iStack_18 = ((iStack_20 + iVar1) - iStack_10) + 1;
      iStack_14 = ((iVar2 + iStack_1c) - iStack_c) + 1;
    }
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x14))
              (*(int **)(param_1 + 0x1c),&iStack_20,*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3c),
               &iStack_10,0x1000000,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00443676
// Address: 00443676
undefined4 FUN_00443676(int param_1)
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

// Function: FUN_004436c4
// Address: 004436c4
undefined4 FUN_004436c4(int param_1)
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

// Function: FUN_00443774
// Address: 00443774
undefined4 FUN_00443774(int param_1)
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

// Function: FUN_00443837
// Address: 00443837
undefined4 FUN_00443837(int param_1)
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

// Function: FUN_004438e4
// Address: 004438e4
undefined4 FUN_004438e4(int param_1)
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

// Function: FUN_00443983
// Address: 00443983
undefined4 FUN_00443983(int param_1)
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

// Function: FUN_00443ac4
// Address: 00443ac4
undefined4 FUN_00443ac4(int param_1)
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

// Function: FUN_00443bf3
// Address: 00443bf3
undefined4 FUN_00443bf3(int param_1)
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

// Function: FUN_00443ca4
// Address: 00443ca4
void __thiscall FUN_00443ca4(TDrawSystem *param_1,void *param_2)
{
  uchar *puVar1;
  int iVar2;
  tagPALETTEENTRY atStack_400 [255];
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  param_1->Pal = param_2;
  if (param_2 == (void *)0x0) {
    puVar1 = &atStack_400[0].peGreen;
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
    GetPaletteEntries(param_2,0,0x100,atStack_400);
  }
  atStack_400[0].peRed = '\0';
  atStack_400[0].peGreen = '\0';
  atStack_400[0].peBlue = '\0';
  atStack_400[0].peFlags = '\0';
  uStack_4 = 0xff;
  uStack_3 = 0xff;
  uStack_2 = 0xff;
  uStack_1 = 0;
  TDrawSystem::ModifyPalette(param_1,0,0x100,atStack_400);
  return;
}

// --------------------------------------------------

// Function: FUN_00443dd5
// Address: 00443dd5
undefined4 * __thiscall FUN_00443dd5(undefined4 *param_1,char *param_2,undefined4 param_3)
{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[0xf] = 0;
  param_1[0x3a] = 0;
  param_1[0xe] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3f) = 0xff;
  param_1[0x2b] = 0;
  param_1[0x3d] = 0;
  param_1[0x3c] = 0;
  param_1[0x39] = param_3;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0x2d] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x37] = 0;
  param_1[0x3e] = 0;
  param_1[0x31] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x38] = 0;
  memset(param_1 + 0x10,0,0x6c);
  uVar2 = calloc(1,0x428);
  param_1[3] = uVar2;
  uVar4 = 0xffffffff;
  param_1[9] = 1;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x32] = 0;
  pcVar3 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((int)(~uVar4 - 1) < 1) {
    param_1[0x2c] = 0;
    return param_1;
  }
  pcVar3 = (char *)malloc(~uVar4);
  uVar4 = 0xffffffff;
  param_1[0x2c] = pcVar3;
  do {
    pcVar6 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar6 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar6;
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00444034
// Address: 00444034
undefined4 __thiscall
FUN_00444034(TDrawArea *param_1,TDrawSystem *param_2,long param_3,long param_4,int param_5,
            int param_6)
{
  DrawAreaNode *pDVar1;
  DrawAreaNode *pDVar2;
  
  param_1->DrawSystem = param_2;
  param_1->IsPrimarySurface = param_6;
  if (param_2 != (TDrawSystem *)0x0) {
    param_1->Wnd = param_2->Wnd;
    if (param_1->Node == (DrawAreaNode *)0x0) {
      pDVar2 = (DrawAreaNode *)calloc(1,0xc);
      param_1->Node = pDVar2;
      if (pDVar2 == (DrawAreaNode *)0x0) {
        return 0;
      }
      pDVar2->DrawArea = param_1;
      param_1->Node->PrevNode = (DrawAreaNode *)0x0;
      param_1->Node->NextNode = (DrawAreaNode *)0x0;
      pDVar2 = param_1->DrawSystem->DrawAreaList;
      if (pDVar2 == (DrawAreaNode *)0x0) {
        param_1->DrawSystem->DrawAreaList = param_1->Node;
      }
      else {
        for (pDVar1 = pDVar2->NextNode; pDVar1 != (DrawAreaNode *)0x0; pDVar1 = pDVar1->NextNode) {
          pDVar2 = pDVar1;
        }
        pDVar2->NextNode = param_1->Node;
        param_1->Node->PrevNode = pDVar2;
      }
    }
    if (param_1->DrawSystem->DrawType == '\x01') {
      return 0;
    }
  }
  TDrawArea::SetSize(param_1,param_3,param_4,param_5);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00444107
// Address: 00444107
undefined4 __fastcall FUN_00444107(TDrawArea *param_1)
{
  IDirectDrawSurface *pIVar1;
  IDirectDraw *pIVar2;
  int iVar3;
  int iStack_d0;
  int iStack_88;
  undefined4 auStack_74 [20];
  undefined4 uStack_24;
  
  if ((param_1->DrawSystem != (TDrawSystem *)0x0) && (param_1->DrawSystem->DrawType == '\x02')) {
    pIVar1 = param_1->DrawSurface;
    if (pIVar1 == (IDirectDrawSurface *)0x0) {
      return 3;
    }
    iVar3 = (**(code **)((int)*pIVar1 + 0x60))(pIVar1);
    if (iVar3 != 0) {
      TDrawSystem::GetIsLostErrorNum(param_1->DrawSystem,iVar3);
      memset(&stack0xffffff2c,0,0x6c);
      pIVar2 = param_1->DrawSystem->DirDraw;
      iVar3 = (**(code **)((int)*pIVar2 + 0x30))(pIVar2,&stack0xffffff2c);
      if ((iVar3 == 0) &&
         (((iStack_d0 != param_1->DrawSystem->ScreenWidth ||
           (param_1->DrawSystem->ScreenHeight != 0x6c)) || (iStack_88 != 8)))) {
        return 1;
      }
      iVar3 = (**(code **)((int)*param_1->DrawSurface + 0x6c))(param_1->DrawSurface);
      if (iVar3 == 0) {
        auStack_74[0] = 100;
        uStack_24 = 0;
        (**(code **)((int)*param_1->DrawSurface + 0x14))
                  (param_1->DrawSurface,0,0,0,0x1000400,auStack_74);
        param_1->Restored = 1;
        return 2;
      }
      if ((iVar3 == -0x7789fdb5) || (iVar3 == -0x7ff8fff2)) {
        (**(code **)((int)*param_1->DrawSurface + 8))(param_1->DrawSurface);
        param_1->DrawSurface = (IDirectDrawSurface *)0x0;
        TDrawArea::SetSize(param_1,param_1->Width,param_1->Height,0);
        if (param_1->DrawSurface != (IDirectDrawSurface *)0x0) {
          return 2;
        }
      }
      TDrawSystem::GetRestoreErrorNum(param_1->DrawSystem,iVar3);
      return 3;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00444262
// Address: 00444262
uchar * __thiscall FUN_00444262(TDrawArea *param_1,undefined4 param_2,int param_3)
{
  IDirectDrawSurface *pIVar1;
  int iVar2;
  
  if ((param_1->DrawSystem == (TDrawSystem *)0x0) || (param_1->DrawSystem->DrawType != '\x01')) {
    pIVar1 = param_1->DrawSurface;
    if (pIVar1 == (IDirectDrawSurface *)0x0) {
      return (uchar *)0x0;
    }
    if (param_1->Bits != (uchar *)0x0) {
      return param_1->Bits;
    }
    if (param_1->DrawDc != (void *)0x0) {
      return (uchar *)0x0;
    }
    iVar2 = (**(code **)((int)*pIVar1 + 100))(pIVar1,0,&param_1->SurfaceDesc,param_3 != 0,0);
    if (iVar2 != 0) {
      return (uchar *)0x0;
    }
    param_1->Bits = (uchar *)(param_1->SurfaceDesc).lpSurface;
    TDrawArea::SetInfo(param_1);
    if (param_1->Bits != param_1->LastBits) {
      TDrawArea::SetAccessOffsets(param_1);
    }
  }
  return param_1->Bits;
}

// --------------------------------------------------

// Function: FUN_004442f1
// Address: 004442f1
void __fastcall FUN_004442f1(int *param_1)
{
  int *piVar1;
  
  if ((((*param_1 == 0) || (*(char *)(*param_1 + 0x478) != '\x01')) &&
      (piVar1 = (int *)param_1[0xf], piVar1 != (int *)0x0)) && (param_1[2] != 0)) {
    (**(code **)(*piVar1 + 0x80))(piVar1,param_1[2]);
    param_1[2] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00444335
// Address: 00444335
int __fastcall FUN_00444335(int *param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*param_1 != 0) && (*(char *)(*param_1 + 0x478) == '\x01')) {
    return param_1[0xe];
  }
  piVar1 = (int *)param_1[0xf];
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = param_1[0xe];
  if (iVar2 == 0) {
    if (param_1[2] != 0) {
      return 0;
    }
    (**(code **)(*piVar1 + 0x44))(piVar1,param_1 + 0xe);
    iVar2 = param_1[0xe];
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00444388
// Address: 00444388
void __fastcall FUN_00444388(int *param_1)
{
  int *piVar1;
  
  if ((((*param_1 == 0) || (*(char *)(*param_1 + 0x478) != '\x01')) &&
      (piVar1 = (int *)param_1[0xf], piVar1 != (int *)0x0)) && (param_1[0xe] != 0)) {
    (**(code **)(*piVar1 + 0x68))(piVar1,param_1[0xe]);
    param_1[0xe] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004443c2
// Address: 004443c2
void __thiscall FUN_004443c2(TDrawArea *param_1,int param_2,int param_3,int param_4)
{
  IDirectDrawSurface **ppIVar1;
  TDrawSystem *pTVar2;
  IDirectDrawSurface *pIVar3;
  IDirectDraw *pIVar4;
  IDirectDrawSurface IVar5;
  int iVar6;
  TSpan_List_Manager *pTVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  int iStack_d4;
  int iStack_d0;
  undefined4 uStack_74;
  undefined4 auStack_70 [20];
  undefined4 uStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d30e;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar2 = param_1->DrawSystem;
  if ((((pTVar2 != (TDrawSystem *)0x0) && (pTVar2->DrawType != '\x01')) &&
      (pTVar2 != (TDrawSystem *)0x0)) &&
     ((((pTVar2->DirDraw != (IDirectDraw *)0x0 && (param_2 != 0)) && (param_3 != 0)) &&
      (((param_2 != param_1->Width || (param_3 != param_1->Height)) ||
       (param_1->DrawSurface == (IDirectDrawSurface *)0x0)))))) {
    if (param_2 < 1) {
      param_2 = 1;
    }
    if (param_3 < 1) {
      param_3 = 1;
    }
    iVar6 = param_3 + 10;
    if (param_4 == 0) {
      iVar6 = param_3;
    }
    param_1->ExtendedLines = param_4;
    (param_1->BitmapInfo->bmiHeader).biWidth = param_2;
    if (param_1->Orien == 1) {
      (param_1->BitmapInfo->bmiHeader).biHeight = -iVar6;
    }
    else {
      (param_1->BitmapInfo->bmiHeader).biHeight = iVar6;
    }
    param_1->Width = param_2;
    param_1->Height = param_3;
    if (param_1->IsPrimarySurface == 0) {
      pIVar3 = param_1->DrawSurface;
      ppIVar1 = &param_1->DrawSurface;
      if (pIVar3 != (IDirectDrawSurface *)0x0) {
        (**(code **)((int)*pIVar3 + 8))(pIVar3);
        *ppIVar1 = (IDirectDrawSurface *)0x0;
        memset(&param_1->SurfaceDesc,0,0x6c);
        param_1->Pitch = 0;
        param_1->UsingVidMem = 0;
      }
      memset(&uStack_dc,0,0x6c);
      uStack_dc = 0x6c;
      uStack_d8 = 7;
      if ((((param_1->DrawSystem->Flags & 1) != 0) || (param_4 != 0)) ||
         (uStack_74 = 0x40, param_1->SystemMemOnly != 0)) {
        uStack_74 = 0x840;
      }
      iStack_d0 = param_1->Width;
      pIVar4 = param_1->DrawSystem->DirDraw;
      iStack_d4 = iVar6;
      iVar6 = (**(code **)((int)*pIVar4 + 0x18))(pIVar4,&uStack_dc,ppIVar1,0);
      if (iVar6 == 0) {
        pIVar3 = *ppIVar1;
        IVar5 = *pIVar3;
        (param_1->SurfaceDesc).dwSize = 0x6c;
        iVar6 = (**(code **)((int)IVar5 + 0x58))(pIVar3,&param_1->SurfaceDesc);
        if (iVar6 == 0) {
          TDrawArea::SetInfo(param_1);
          TDrawArea::SetAccessOffsets(param_1);
          auStack_70[0] = 100;
          uStack_20 = 0;
          (**(code **)((int)**ppIVar1 + 0x14))(*ppIVar1,0,0,0,0x1000400,auStack_70);
        }
        else {
          TDrawSystem::GetCreateErrorNum(param_1->DrawSystem,iVar6);
        }
      }
    }
    else {
      param_1->DrawSurface = param_1->DrawSystem->PrimarySurface;
    }
    TDrawArea::SetClipRect(param_1,(tagRECT *)0x0);
    TDrawArea::Clear(param_1,(tagRECT *)0x0,0);
  }
  pTVar7 = param_1->SpanList;
  if (pTVar7 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar7);
    operator_delete(pTVar7);
  }
  pTVar7 = (TSpan_List_Manager *)operator_new(0x68);
  iVar6 = 0;
  uStack_4 = 0;
  if (pTVar7 == (TSpan_List_Manager *)0x0) {
    pTVar7 = (TSpan_List_Manager *)0x0;
  }
  else {
    pTVar7 = (TSpan_List_Manager *)TSpan_List_Manager::TSpan_List_Manager(pTVar7,param_2,param_3);
  }
  uStack_4 = 0xffffffff;
  param_1->SpanList = pTVar7;
  if (0 < param_3) {
    do {
      TSpan_List_Manager::AddSpan(param_1->SpanList,0,param_2 + -1,iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_3);
  }
  param_1->CurSpanList = param_1->SpanList;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00444673
// Address: 00444673
void __thiscall FUN_00444673(TDrawArea *param_1,tagRECT *param_2,int param_3)
{
  IDirectDrawSurface *pIVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uchar *puVar8;
  long lStack_74;
  long lStack_70;
  int iStack_6c;
  int iStack_68;
  undefined4 auStack_64 [20];
  int iStack_14;
  
  if (DDSys_CanColorFill == 0) {
    TDrawArea::PtrClear(param_1,param_2,param_3);
    return;
  }
  if ((param_1->DrawSystem == (TDrawSystem *)0x0) || (param_1->DrawSystem->DrawType != '\x01')) {
    pIVar1 = param_1->DrawSurface;
    if (pIVar1 != (IDirectDrawSurface *)0x0) {
      auStack_64[0] = 100;
      iStack_14 = param_3;
      if (param_2 == (tagRECT *)0x0) {
        (**(code **)((int)*pIVar1 + 0x14))(pIVar1,0,0,0,0x1000400,auStack_64);
        return;
      }
      lStack_74 = param_2->left;
      lStack_70 = param_2->top;
      iStack_6c = param_2->right + 1;
      iStack_68 = param_2->bottom + 1;
      (**(code **)((int)*pIVar1 + 0x14))(pIVar1,&lStack_74,0,0,0x1000400,auStack_64);
    }
  }
  else {
    puVar8 = param_1->Bits;
    if (puVar8 != (uchar *)0x0) {
      if (param_2 == (tagRECT *)0x0) {
        memset(puVar8,param_3,param_1->Height * param_1->Pitch);
        return;
      }
      iVar3 = param_2->left;
      iVar5 = param_2->top;
      iVar6 = param_2->right;
      iVar4 = param_2->bottom;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else if (param_1->Width <= iVar3) {
        iVar3 = param_1->Width + -1;
      }
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      else if (param_1->Height <= iVar5) {
        iVar5 = param_1->Height + -1;
      }
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      else if (param_1->Width <= iVar6) {
        iVar6 = param_1->Width + -1;
      }
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (param_1->Height <= iVar4) {
        iVar4 = param_1->Height + -1;
      }
      if ((iVar3 < iVar6) && (iVar5 < iVar4)) {
        if (param_1->Orien == 1) {
          iVar2 = param_1->Pitch;
          iVar7 = iVar5 * iVar2;
        }
        else {
          iVar7 = ((param_1->Height - iVar5) + -1) * param_1->Pitch;
          iVar2 = -param_1->Pitch;
        }
        puVar8 = puVar8 + iVar7 + iVar3;
        if (iVar5 <= iVar4) {
          iVar5 = (iVar4 - iVar5) + 1;
          do {
            memset(puVar8,param_3,(iVar6 - iVar3) + 1);
            puVar8 = puVar8 + iVar2;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          return;
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044484a
// Address: 0044484a
// [HELPER] s_PtrClear: "PtrClear"
void __thiscall FUN_0044484a(TDrawArea *param_1,int *param_2,undefined1 param_3)
{
  void **ppvVar1;
  uchar *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iStack_c;
  int iStack_8;
  
  if (param_2 == (int *)0x0) {
    iVar3 = param_1->Width;
    iVar5 = param_1->Height;
    iStack_8 = 0;
    param_2 = (int *)0x0;
  }
  else {
    iStack_8 = *param_2;
    iVar3 = param_2[2];
    iVar5 = param_2[3];
    param_2 = (int *)param_2[1];
  }
  if (((((-1 < iVar3) && (iStack_8 <= iVar3)) && (iStack_8 < param_1->Width)) &&
      ((-1 < iVar5 && ((int)param_2 <= iVar5)))) && ((int)param_2 < param_1->Height)) {
    if (iStack_8 < 0) {
      iStack_8 = 0;
    }
    if (param_1->Width <= iVar3) {
      iVar3 = param_1->Width + -1;
    }
    if ((int)param_2 < 0) {
      param_2 = (int *)0x0;
    }
    if (param_1->Height <= iVar5) {
      iVar5 = param_1->Height + -1;
    }
    iStack_c = (iVar5 - (int)param_2) + 1;
    iVar3 = (iVar3 - iStack_8) + 1;
    if (((param_1->DrawSystem != (TDrawSystem *)0x0) && (param_1->DrawSystem->DrawType == '\x02'))
       && (puVar2 = TDrawArea::Lock(param_1,s_PtrClear,1), puVar2 == (uchar *)0x0)) {
      return;
    }
    ppvVar1 = param_1->CurDisplayOffsets;
    do {
      puVar8 = (undefined4 *)((int)ppvVar1[(int)param_2] + iStack_8);
      uVar4 = -(int)puVar8 & 3;
      uVar6 = iVar3 - uVar4;
      uVar7 = uVar6;
      if (uVar6 != 0 && (int)uVar4 <= iVar3) {
        for (; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar8 = param_3;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        uVar7 = uVar6 & 3;
        for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar8 = CONCAT22(CONCAT11(param_3,param_3),CONCAT11(param_3,param_3));
          puVar8 = puVar8 + 1;
        }
      }
      for (iVar5 = uVar4 + uVar7; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar8 = param_3;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      param_2 = (int *)((int)param_2 + 1);
      iStack_c = iStack_c + -1;
    } while (iStack_c != 0);
    if ((param_1->DrawSystem != (TDrawSystem *)0x0) && (param_1->DrawSystem->DrawType == '\x02')) {
      TDrawArea::Unlock(param_1,s_PtrClear);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00444984
// Address: 00444984
void __fastcall FUN_00444984(TDrawArea *param_1)
{
  void **ppvVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1->Height << 2;
  if (iVar4 != param_1->DisplayOffsetsSz) {
    if (param_1->DisplayOffsets != (void **)0x0) {
      free(param_1->DisplayOffsets);
    }
    ppvVar1 = (void **)malloc(iVar4);
    param_1->DisplayOffsets = ppvVar1;
    param_1->DisplayOffsetsSz = iVar4;
    param_1->CurDisplayOffsets = ppvVar1;
  }
  if ((param_1->Orien == 1) || (param_1->ExtendedLines != 0)) {
    if (param_1->ExtendedLines == 0) {
      puVar2 = param_1->Bits;
    }
    else {
      puVar2 = param_1->Bits + param_1->Pitch * 5;
    }
    iVar4 = param_1->Pitch;
    if (param_1->ExtendedLines != 0) {
      iVar4 = param_1->Width;
    }
  }
  else {
    puVar2 = param_1->Bits + (param_1->Height + -1) * param_1->Pitch;
    iVar4 = -param_1->Pitch;
  }
  iVar3 = 0;
  if (0 < param_1->Height) {
    do {
      param_1->DisplayOffsets[iVar3] = puVar2;
      puVar2 = puVar2 + iVar4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1->Height);
  }
  if (param_1->FloatOffsets != (void **)0x0) {
    TDrawArea::SetFloatOffsets(param_1,param_1->Float_X_Delta,param_1->Float_Y_Delta);
  }
  param_1->LastBits = param_1->Bits;
  return;
}

// --------------------------------------------------

// Function: FUN_00444b0d
// Address: 00444b0d
void __fastcall FUN_00444b0d(int param_1)
{
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = *(undefined4 *)(param_1 + 0x50);
  if ((*(uint *)(param_1 + 0xa8) & 0x800) != 0) {
    *(undefined4 *)(param_1 + 0xe8) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0xe8) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00444b3d
// Address: 00444b3d
undefined4 __fastcall FUN_00444b3d(int param_1)
{
  return *(undefined4 *)(param_1 + 0x20);
}

// --------------------------------------------------

// Function: FUN_00444b44
// Address: 00444b44
void __thiscall FUN_00444b44(TDrawArea *param_1,long *param_2)
{
  int iVar1;
  int iVar2;
  
  if (param_2 == (long *)0x0) {
    iVar1 = param_1->Width;
    iVar2 = param_1->Height;
    (param_1->ClipRect).left = 0;
    (param_1->ClipRect).top = 0;
    (param_1->ClipRect).right = iVar1 + -1;
    (param_1->ClipRect).bottom = iVar2 + -1;
  }
  else {
    (param_1->ClipRect).left = *param_2;
    (param_1->ClipRect).top = param_2[1];
    (param_1->ClipRect).right = param_2[2];
    (param_1->ClipRect).bottom = param_2[3];
    iVar1 = (param_1->ClipRect).left;
    if (iVar1 < 0) {
      (param_1->ClipRect).left = 0;
    }
    else {
      iVar2 = param_1->Width + -1;
      if (iVar2 < iVar1) {
        (param_1->ClipRect).left = iVar2;
      }
    }
    iVar1 = (param_1->ClipRect).right;
    if (iVar1 < 0) {
      (param_1->ClipRect).right = 0;
    }
    else {
      iVar2 = param_1->Width + -1;
      if (iVar2 < iVar1) {
        (param_1->ClipRect).right = iVar2;
      }
    }
    iVar1 = (param_1->ClipRect).top;
    if (iVar1 < 0) {
      (param_1->ClipRect).top = 0;
    }
    else {
      iVar2 = param_1->Height + -1;
      if (iVar2 < iVar1) {
        (param_1->ClipRect).top = iVar2;
      }
    }
    iVar1 = (param_1->ClipRect).bottom;
    if (iVar1 < 0) {
      (param_1->ClipRect).bottom = 0;
    }
    else {
      iVar2 = param_1->Height + -1;
      if (iVar2 < iVar1) {
        (param_1->ClipRect).bottom = iVar2;
      }
    }
    iVar1 = (param_1->ClipRect).right;
    iVar2 = (param_1->ClipRect).left;
    if (iVar1 < iVar2) {
      (param_1->ClipRect).right = iVar2;
      (param_1->ClipRect).left = iVar1;
    }
    iVar1 = (param_1->ClipRect).bottom;
    iVar2 = (param_1->ClipRect).top;
    if (iVar1 < iVar2) {
      (param_1->ClipRect).bottom = iVar2;
      (param_1->ClipRect).top = iVar1;
    }
  }
  TDrawArea::SetClipRect
            (param_1,(param_1->ClipRect).left,(param_1->ClipRect).top,(param_1->ClipRect).right,
             (param_1->ClipRect).bottom);
  return;
}

// --------------------------------------------------

// Function: FUN_00444c21
// Address: 00444c21
void __thiscall
FUN_00444c21(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  TSpan_List_Manager *pTVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d32b;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar1 = *(TSpan_List_Manager **)(param_1 + 0xcc);
  *(undefined4 *)(param_1 + 0x28) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = param_3;
  *(undefined4 *)(param_1 + 0x30) = param_4;
  *(undefined4 *)(param_1 + 0x34) = param_5;
  if ((pTVar1 != (TSpan_List_Manager *)0x0) && (*(int *)(param_1 + 0x1c) != pTVar1->Num_Lines)) {
    if (pTVar1 != (TSpan_List_Manager *)0x0) {
      TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
      operator_delete(pTVar1);
    }
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  if (*(int *)(param_1 + 0xcc) == 0) {
    pTVar1 = (TSpan_List_Manager *)operator_new(0x68);
    uStack_4 = 0;
    if (pTVar1 == (TSpan_List_Manager *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = TSpan_List_Manager::TSpan_List_Manager
                        (pTVar1,*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
    }
    uStack_4 = 0xffffffff;
    *(undefined4 *)(param_1 + 0xcc) = uVar2;
  }
  TSpan_List_Manager::ResetAll(*(TSpan_List_Manager **)(param_1 + 0xcc));
  TSpan_List_Manager::SetSpanRegions
            (*(TSpan_List_Manager **)(param_1 + 0xcc),*(int *)(param_1 + 0x28),
             *(int *)(param_1 + 0x2c),*(int *)(param_1 + 0x30),*(int *)(param_1 + 0x34));
  iVar3 = *(int *)(param_1 + 0x2c);
  if (iVar3 <= *(int *)(param_1 + 0x34)) {
    do {
      TSpan_List_Manager::AddSpan
                (*(TSpan_List_Manager **)(param_1 + 0xcc),*(int *)(param_1 + 0x28),
                 *(int *)(param_1 + 0x30),iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(param_1 + 0x34));
  }
  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xcc);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00444d47
// Address: 00444d47
void __thiscall
FUN_00444d47(int *param_1,int param_2,int param_3,int param_4,int *param_5,int param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar3 = 0;
  if ((*param_1 == 0) || (*(char *)(*param_1 + 0x478) != '\x01')) {
    if ((param_1[0xf] != 0) && ((param_2 != 0 && (*(int *)(param_2 + 0x3c) != 0)))) {
      if (param_5 == (int *)0x0) {
        iStack_18 = param_1[6] + -1;
        iStack_20 = 0;
        iStack_1c = 0;
        iStack_14 = param_1[7] + -1;
      }
      else {
        iStack_20 = *param_5;
        iStack_1c = param_5[1];
        iStack_18 = param_5[2];
        iStack_14 = param_5[3];
      }
      iStack_18 = iStack_18 + 1;
      iStack_14 = iStack_14 + 1;
      SetRect(&iStack_10,param_3,param_4,(iStack_18 - iStack_20) + param_3,
              (iStack_14 - iStack_1c) + param_4);
      iVar1 = iStack_1c;
      iVar3 = iStack_20;
      if (iStack_20 < 0) {
        iStack_20 = 0;
        iStack_10 = iStack_10 - iVar3;
      }
      if (iStack_1c < 0) {
        iStack_1c = 0;
        iStack_c = iStack_c - iVar1;
      }
      if (param_1[6] < iStack_18) {
        iVar3 = iStack_18 - param_1[6];
        iStack_18 = iStack_18 - iVar3;
        iStack_8 = iStack_8 - iVar3;
      }
      if (param_1[7] < iStack_14) {
        iVar3 = iStack_14 - param_1[7];
        iStack_14 = iStack_14 - iVar3;
        iStack_4 = iStack_4 - iVar3;
      }
      if (iStack_10 < *(int *)(param_2 + 0x28)) {
        iVar3 = *(int *)(param_2 + 0x28) - iStack_10;
        iStack_10 = iStack_10 + iVar3;
        iStack_20 = iStack_20 + iVar3;
      }
      if (iStack_c < *(int *)(param_2 + 0x2c)) {
        iVar3 = *(int *)(param_2 + 0x2c) - iStack_c;
        iStack_c = iStack_c + iVar3;
        iStack_1c = iStack_1c + iVar3;
      }
      if (*(int *)(param_2 + 0x30) + 1 < iStack_8) {
        iVar3 = (iStack_8 - *(int *)(param_2 + 0x30)) + -1;
        iStack_8 = iStack_8 - iVar3;
        iStack_18 = iStack_18 - iVar3;
      }
      if (*(int *)(param_2 + 0x34) + 1 < iStack_4) {
        iVar3 = (iStack_4 - *(int *)(param_2 + 0x34)) + -1;
        iStack_4 = iStack_4 - iVar3;
        iStack_14 = iStack_14 - iVar3;
      }
      if ((((iStack_10 < iStack_8) && (iStack_c < iStack_4)) && (iStack_20 < iStack_18)) &&
         (iStack_1c < iStack_14)) {
        DAT_0062e64c._0_4_ = 1;
        if ((param_1[0x3b] == 0) || (param_6 == 0)) {
          DAT_0062e64c._0_4_ =
               (**(code **)(**(int **)(param_2 + 0x3c) + 0x14))
                         (*(int **)(param_2 + 0x3c),&iStack_10,param_1[0xf],&iStack_20,0x1000000,0);
        }
        else {
          DAT_0062e64c._0_4_ =
               (**(code **)(**(int **)(param_2 + 0x3c) + 0x14))
                         (*(int **)(param_2 + 0x3c),&iStack_10,param_1[0xf],&iStack_20,0x1008000,0);
        }
        DAT_0062e64c._4_4_ = 0;
        if ((int)DAT_0062e64c != 0) {
          DAT_0062e64c._4_4_ =
               TDrawSystem::GetBlitErrorNum((TDrawSystem *)*param_1,(int)DAT_0062e64c);
        }
      }
    }
  }
  else if (((param_1[2] != 0) && (param_2 != 0)) && (*(int *)(param_2 + 8) != 0)) {
    if (param_5 == (int *)0x0) {
      iVar1 = param_1[6];
      iVar2 = param_1[7];
      iVar4 = 0;
    }
    else {
      iVar4 = *param_5;
      iVar3 = param_5[1];
      iVar1 = (param_5[2] - iVar4) + 1;
      iVar2 = (param_5[3] - iVar3) + 1;
    }
    if (param_1[6] < iVar1 + iVar4) {
      iVar1 = param_1[6] - iVar4;
    }
    if (param_1[7] < iVar2 + iVar3) {
      iVar2 = param_1[7] - iVar3;
    }
    if ((param_1[0x3b] != 0) && (param_6 != 0)) {
      TransDibBlt(*(BITMAPINFO256 **)(param_2 + 0xc),*(uchar **)(param_2 + 8),
                  (tagRECT *)(param_2 + 0x28),param_3,param_4,iVar1,iVar2,
                  (BITMAPINFO256 *)param_1[3],(uchar *)param_1[2],(TRANSINFO *)0x0,iVar4,iVar3,iVar1
                  ,iVar2,1,0,0,(uint)*(byte *)(param_1 + 0x3f));
      DAT_0062e64c._4_4_ = 0;
      return;
    }
    DibBlt(*(BITMAPINFO256 **)(param_2 + 0xc),*(uchar **)(param_2 + 8),(tagRECT *)(param_2 + 0x28),
           param_3,param_4,iVar1,iVar2,(BITMAPINFO256 *)param_1[3],(uchar *)param_1[2],iVar4,iVar3,
           iVar1,iVar2,1,0,0);
    DAT_0062e64c._4_4_ = 0;
    return;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004450b1
// Address: 004450b1
// [HELPER] s_PtrCopy1: "PtrCopy1"
// [HELPER] s_PtrCopy2: "PtrCopy2"
void __thiscall
FUN_004450b1(TDrawArea *param_1,TDrawArea *param_2,int param_3,int param_4,int *param_5)
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
  int iStack_10;
  int iStack_8;
  
  iVar1 = *param_5;
  if (((((-1 < iVar1) && (iVar10 = param_5[2], iVar1 <= iVar10)) && (iVar10 < param_1->Width)) &&
      ((iVar2 = param_5[1], -1 < iVar2 && (iVar3 = param_5[3], iVar2 <= iVar3)))) &&
     (iVar3 < param_1->Height)) {
    iStack_8 = (iVar3 - iVar2) + 1;
    iStack_10 = (iVar10 - iVar1) + 1;
    if (((-1 < param_3) && (iVar1 = param_2->Width, param_3 < iVar1)) &&
       ((-1 < param_4 && (iVar10 = param_2->Height, param_4 < iVar10)))) {
      if (iVar1 < iStack_10 + param_3) {
        iStack_10 = iVar1 - param_3;
      }
      if (iVar10 < iStack_8 + param_4) {
        iStack_8 = iVar10 - param_4;
      }
      if (((param_1->DrawSystem == (TDrawSystem *)0x0) || (param_1->DrawSystem->DrawType != '\x02'))
         || ((puVar6 = TDrawArea::Lock(param_1,s_PtrCopy1,1), puVar6 != (uchar *)0x0 &&
             (puVar6 = TDrawArea::Lock(param_2,s_PtrCopy2,1), puVar6 != (uchar *)0x0)))) {
        iVar1 = *param_5;
        param_5 = (int *)param_5[1];
        ppvVar4 = param_1->CurDisplayOffsets;
        ppvVar5 = param_2->CurDisplayOffsets;
        do {
          puVar11 = (undefined4 *)((int)ppvVar4[(int)param_5] + iVar1);
          puVar12 = (undefined4 *)((int)ppvVar5[param_4] + param_3);
          uVar9 = -(int)puVar12 & 3;
          uVar7 = iStack_10 - uVar9;
          uVar8 = uVar7;
          if (uVar7 != 0 && (int)uVar9 <= iStack_10) {
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
          for (iVar10 = uVar9 + uVar8; iVar10 != 0; iVar10 = iVar10 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          param_5 = (int *)((int)param_5 + 1);
          param_4 = param_4 + 1;
          iStack_8 = iStack_8 + -1;
        } while (iStack_8 != 0);
        if ((param_1->DrawSystem != (TDrawSystem *)0x0) && (param_1->DrawSystem->DrawType == '\x02')
           ) {
          TDrawArea::Unlock(param_1,s_PtrCopy1);
          TDrawArea::Unlock(param_2,s_PtrCopy2);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044524b
// Address: 0044524b
// [HELPER] s_PtrSpanCopy: "PtrSpanCopy"
void __thiscall
FUN_0044524b(int *param_1,TDrawArea *param_2,int param_3,int param_4,int *param_5,int param_6)
{
  int iVar1;
  int iVar2;
  void **ppvVar3;
  int iVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  uchar *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  
  piVar8 = param_5;
  iVar7 = param_3;
  if (((((-1 < *param_5) && (*param_5 <= param_5[2])) && (param_5[2] < param_1[6])) &&
      ((((iVar1 = param_5[1], -1 < iVar1 && (iVar2 = param_5[3], iVar1 <= iVar2)) &&
        ((iVar2 < param_1[7] &&
         ((param_5 = (int *)((iVar2 - iVar1) + 1), -1 < param_3 && (param_3 < param_2->Width))))))
       && (-1 < param_4)))) && (iVar1 = param_2->Height, param_4 < iVar1)) {
    if (iVar1 < (int)param_5 + param_4) {
      param_5 = (int *)(iVar1 - param_4);
    }
    if (((*param_1 == 0) || (*(char *)(*param_1 + 0x478) != '\x02')) ||
       (puVar9 = TDrawArea::Lock(param_2,s_PtrSpanCopy,1), puVar9 != (uchar *)0x0)) {
      iVar1 = *piVar8;
      iVar2 = param_1[0x30];
      ppvVar3 = param_2->CurDisplayOffsets;
      param_3 = param_4;
      param_2 = (TDrawArea *)piVar8[1];
      do {
        iVar4 = *(int *)(iVar2 + (int)param_2 * 4);
        pvVar5 = ppvVar3[param_3];
        for (puVar6 = *(undefined4 **)(param_6 + (int)param_2 * 4); puVar6 != (undefined4 *)0x0;
            puVar6 = (undefined4 *)*puVar6) {
          iVar12 = puVar6[2];
          puVar14 = (undefined4 *)(iVar4 + iVar1 + iVar12);
          puVar15 = (undefined4 *)((int)pvVar5 + iVar12 + iVar7);
          iVar12 = (puVar6[3] - iVar12) + 1;
          uVar13 = -(int)puVar15 & 3;
          uVar10 = iVar12 - uVar13;
          uVar11 = uVar10;
          if (uVar10 != 0 && (int)uVar13 <= iVar12) {
            for (; uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined1 *)puVar15 = *(undefined1 *)puVar14;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
              puVar15 = (undefined4 *)((int)puVar15 + 1);
            }
            uVar11 = uVar10 & 3;
            for (uVar13 = uVar10 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
              *puVar15 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar15 = puVar15 + 1;
            }
          }
          for (iVar12 = uVar13 + uVar11; iVar12 != 0; iVar12 = iVar12 + -1) {
            *(undefined1 *)puVar15 = *(undefined1 *)puVar14;
            puVar14 = (undefined4 *)((int)puVar14 + 1);
            puVar15 = (undefined4 *)((int)puVar15 + 1);
          }
        }
        param_2 = (TDrawArea *)((int)param_2 + 1);
        param_3 = param_3 + 1;
        param_5 = (int *)((int)param_5 + -1);
      } while (param_5 != (int *)0x0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044539e
// Address: 0044539e
// [HELPER] s_PtrSurfaceCopy1: "PtrSurfaceCopy1"
// [HELPER] s_PtrSurfaceCopy2: "PtrSurfaceCopy2"
void __thiscall
FUN_0044539e(TDrawArea *param_1,TDrawArea *param_2,int param_3,int param_4,int *param_5,int param_6,
            int param_7)
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
  int iStack_10;
  int iStack_8;
  
  iVar1 = *param_5;
  if (((((-1 < iVar1) && (iVar10 = param_5[2], iVar1 <= iVar10)) && (iVar10 < param_1->Width)) &&
      ((iVar2 = param_5[1], -1 < iVar2 && (iVar3 = param_5[3], iVar2 <= iVar3)))) &&
     (iVar3 < param_1->Height)) {
    iStack_8 = (iVar3 - iVar2) + 1;
    iStack_10 = (iVar10 - iVar1) + 1;
    if (((-1 < param_3) && (iVar1 = param_2->Width, param_3 < iVar1)) &&
       ((-1 < param_4 && (iVar10 = param_2->Height, param_4 < iVar10)))) {
      if (iVar1 < iStack_10 + param_3) {
        iStack_10 = iVar1 - param_3;
      }
      if (iVar10 < iStack_8 + param_4) {
        iStack_8 = iVar10 - param_4;
      }
      if ((param_1->DrawSystem != (TDrawSystem *)0x0) && (param_1->DrawSystem->DrawType == '\x02'))
{
        if ((param_6 != 0) &&
           (puVar6 = TDrawArea::Lock(param_1,s_PtrSurfaceCopy1,1), puVar6 == (uchar *)0x0)) {
          return;
        }
        if ((param_7 != 0) &&
           (puVar6 = TDrawArea::Lock(param_2,s_PtrSurfaceCopy2,1), puVar6 == (uchar *)0x0)) {
          if (param_6 == 0) {
            return;
          }
          TDrawArea::Unlock(param_1,s_PtrSurfaceCopy1);
          return;
        }
      }
      ppvVar4 = param_1->CurDisplayOffsets;
      iVar1 = *param_5;
      param_5 = (int *)param_5[1];
      ppvVar5 = param_2->CurDisplayOffsets;
      do {
        puVar11 = (undefined4 *)((int)ppvVar4[(int)param_5] + iVar1);
        puVar12 = (undefined4 *)((int)ppvVar5[param_4] + param_3);
        iVar10 = iStack_10;
        if ((((uint)puVar11 ^ (uint)puVar12) & 3) == 0) {
          uVar9 = -(int)puVar12 & 3;
          uVar7 = iStack_10 - uVar9;
          uVar8 = uVar7;
          if (uVar7 != 0 && (int)uVar9 <= iStack_10) {
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
        param_5 = (int *)((int)param_5 + 1);
        param_4 = param_4 + 1;
        iStack_8 = iStack_8 + -1;
      } while (iStack_8 != 0);
      if ((param_1->DrawSystem != (TDrawSystem *)0x0) && (param_1->DrawSystem->DrawType == '\x02'))
{
        if (param_6 != 0) {
          TDrawArea::Unlock(param_1,s_PtrSurfaceCopy1);
        }
        if (param_7 != 0) {
          TDrawArea::Unlock(param_2,s_PtrSurfaceCopy2);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00445576
// Address: 00445576
// [HELPER] s_OverlayMemCopy: "OverlayMemCopy"
void __thiscall
FUN_00445576(TDrawArea *param_1,int *param_2,int *param_3,int param_4,int param_5,int param_6,
            int param_7)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void **ppvVar4;
  bool bVar5;
  int *piVar6;
  uchar *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar8 = param_6;
  piVar6 = param_3;
  if (((param_4 != 0) || (param_5 != 0)) &&
     ((param_1->DrawSystem == (TDrawSystem *)0x0 ||
      ((param_1->DrawSystem->DrawType != '\x02' ||
       (puVar7 = TDrawArea::Lock(param_1,s_OverlayMemCopy,1), puVar7 != (uchar *)0x0)))))) {
    bVar5 = false;
    piVar1 = param_2 + 3;
    iVar3 = param_2[1];
    piVar2 = param_2 + 2;
    iStack_8 = (*piVar1 - iVar3) + 1;
    iStack_10 = *param_2 + param_6;
    iVar9 = (*piVar2 - *param_2) + 4 >> 2;
    iStack_c = param_6 + *param_3;
    if (param_5 < 0) {
      param_2 = (int *)0xffffffff;
      param_6 = param_3[3] + param_7;
      param_3 = (int *)(*piVar1 + param_7);
    }
    if (0 < param_5) {
      param_3 = (int *)(param_7 + iVar3);
      param_2 = (int *)0x1;
      param_6 = piVar6[1] + param_7;
    }
    if (param_5 == 0) {
      param_3 = (int *)(iVar3 + param_7);
      param_6 = piVar6[1] + param_7;
      param_2 = (int *)0x1;
      if (param_4 < 0) {
        bVar5 = true;
        iStack_10 = iVar8 + -3 + *piVar2;
        iStack_c = piVar6[2] + -3 + iVar8;
      }
    }
    ppvVar4 = param_1->CurDisplayOffsets;
    if (bVar5) {
      do {
        puVar10 = (undefined4 *)((int)ppvVar4[(int)param_3] + iStack_10);
        puVar11 = (undefined4 *)((int)ppvVar4[param_6] + iStack_c);
        for (iVar8 = iVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + -1;
          puVar11 = puVar11 + -1;
        }
        param_3 = (int *)((int)param_3 + (int)param_2);
        param_6 = param_6 + (int)param_2;
        iStack_8 = iStack_8 + -1;
      } while (iStack_8 != 0);
    }
    else {
      do {
        puVar10 = (undefined4 *)((int)ppvVar4[(int)param_3] + iStack_10);
        puVar11 = (undefined4 *)((int)ppvVar4[param_6] + iStack_c);
        for (iVar8 = iVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        param_3 = (int *)((int)param_3 + (int)param_2);
        param_6 = param_6 + (int)param_2;
        iStack_8 = iStack_8 + -1;
      } while (iStack_8 != 0);
    }
    if ((param_1->DrawSystem != (TDrawSystem *)0x0) && (param_1->DrawSystem->DrawType == '\x02')) {
      TDrawArea::Unlock(param_1,s_OverlayMemCopy);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00445701
// Address: 00445701
void __thiscall FUN_00445701(int *param_1,int param_2,undefined1 param_3)
{
  int *piVar1;
  uint uStack_8;
  uint uStack_4;
  
  param_1[0x3b] = param_2;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x3f) = 0xff;
  }
  else {
    *(undefined1 *)(param_1 + 0x3f) = param_3;
    piVar1 = (int *)param_1[0xf];
    if (((piVar1 != (int *)0x0) && (*param_1 != 0)) && (*(char *)(*param_1 + 0x478) == '\x02')) {
      uStack_8 = (uint)*(byte *)(param_1 + 0x3f);
      uStack_4 = uStack_8;
      (**(code **)(*piVar1 + 0x74))(piVar1,8,&uStack_8);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00445773
// Address: 00445773
void __thiscall FUN_00445773(int *param_1,int param_2,byte param_3)
{
  int *piVar1;
  uint uStack_8;
  uint uStack_4;
  
  param_1[0x3b] = param_2;
  *(byte *)(param_1 + 0x3f) = param_3;
  if ((((param_2 != 0) && (piVar1 = (int *)param_1[0xf], piVar1 != (int *)0x0)) && (*param_1 != 0))
     && (*(char *)(*param_1 + 0x478) == '\x02')) {
    uStack_8 = (uint)param_3;
    uStack_4 = uStack_8;
    (**(code **)(*piVar1 + 0x74))(piVar1,0x10,&uStack_8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004457d1
// Address: 004457d1
void __thiscall FUN_004457d1(int param_1,int param_2,int param_3,undefined1 param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x28) <= param_2)) &&
      (param_2 <= *(int *)(param_1 + 0x30))) &&
     ((*(int *)(param_1 + 0x2c) <= param_3 && (param_3 <= *(int *)(param_1 + 0x34))))) {
    if (*(int *)(param_1 + 0x24) == 1) {
      *(undefined1 *)(*(int *)(param_1 + 0x20) * param_3 + param_2 + iVar1) = param_4;
      return;
    }
    *(undefined1 *)
     (((*(int *)(param_1 + 0x1c) - param_3) + -1) * *(int *)(param_1 + 0x20) + param_2 + iVar1) =
         param_4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0044583b
// Address: 0044583b
void FUN_0044583b(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)
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

// Function: FUN_0044599c
// Address: 0044599c
void __thiscall
FUN_0044599c(TDrawArea *param_1,int param_2,int param_3,int param_4,int param_5,uchar param_6)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_5;
  iVar2 = param_4;
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = iVar2;
  }
  if (param_5 < param_3) {
    param_5 = param_3;
    param_3 = iVar1;
  }
  iVar2 = (param_4 - param_2) + 1;
  if ((0 < iVar2) && (iVar1 = (param_5 - param_3) + 1, 0 < iVar1)) {
    TDrawArea::DrawHorzLine(param_1,param_2,param_3,iVar2,param_6);
    TDrawArea::DrawHorzLine(param_1,param_2,param_5,iVar2,param_6);
    TDrawArea::DrawVertLine(param_1,param_2,param_3,iVar1,param_6);
    TDrawArea::DrawVertLine(param_1,param_4,param_3,iVar1,param_6);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00445a33
// Address: 00445a33
void __thiscall FUN_00445a33(TDrawArea *param_1,long *param_2,uchar param_3)
{
  TDrawArea::DrawRect(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_00445ae7
// Address: 00445ae7
void __thiscall FUN_00445ae7(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)
{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if ((((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0x28) <= param_2)) &&
      (param_2 <= *(int *)(param_1 + 0x30))) && (iVar3 = *(int *)(param_1 + 0x34), param_3 <= iVar3)
     ) {
    iVar1 = *(int *)(param_1 + 0x2c);
    if (param_3 < iVar1) {
      param_4 = param_4 + (param_3 - iVar1);
      param_3 = iVar1;
    }
    if (iVar3 < param_4 + -1 + param_3) {
      param_4 = (iVar3 - param_3) + 1;
    }
    if (0 < param_4) {
      if (*(int *)(param_1 + 0x24) == 1) {
        iVar3 = *(int *)(param_1 + 0x20);
        param_3 = param_3 * iVar3;
      }
      else {
        param_3 = ((*(int *)(param_1 + 0x1c) - param_3) + -1) * *(int *)(param_1 + 0x20);
        iVar3 = -*(int *)(param_1 + 0x20);
      }
      puVar2 = (undefined1 *)(param_3 + param_2 + *(int *)(param_1 + 8));
      if (0 < param_4) {
        do {
          *puVar2 = param_5;
          puVar2 = puVar2 + iVar3;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00445b7f
// Address: 00445b7f
void __thiscall
FUN_00445b7f(int param_1,int param_2,int param_3,int param_4,int param_5,undefined1 param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 8) != 0) {
    iVar2 = param_4;
    if (param_4 < param_2) {
      iVar2 = param_2;
      param_2 = param_4;
    }
    iVar1 = param_3;
    if (param_5 < param_3) {
      iVar1 = param_5;
      param_5 = param_3;
    }
    if ((((param_2 <= *(int *)(param_1 + 0x30)) &&
         (iVar4 = *(int *)(param_1 + 0x28), iVar4 <= iVar2)) && (iVar1 <= *(int *)(param_1 + 0x34)))
       && (iVar3 = *(int *)(param_1 + 0x2c), iVar3 <= param_5)) {
      if (param_2 < iVar4) {
        param_2 = iVar4;
      }
      if (*(int *)(param_1 + 0x30) < iVar2) {
        iVar2 = *(int *)(param_1 + 0x30);
      }
      if (iVar1 < iVar3) {
        iVar1 = iVar3;
      }
      if (*(int *)(param_1 + 0x34) < param_5) {
        param_5 = *(int *)(param_1 + 0x34);
      }
      iVar4 = (iVar2 - param_2) + 1;
      iVar2 = (param_5 - iVar1) + 1;
      if ((0 < iVar4) && (0 < iVar2)) {
        if (*(int *)(param_1 + 0x24) == 1) {
          iVar3 = *(int *)(param_1 + 0x20);
          iVar1 = iVar1 * iVar3;
        }
        else {
          iVar1 = ((*(int *)(param_1 + 0x1c) - iVar1) + -1) * *(int *)(param_1 + 0x20);
          iVar3 = -*(int *)(param_1 + 0x20);
        }
        iVar1 = iVar1 + param_2 + *(int *)(param_1 + 8);
        if (0 < iVar2) {
          do {
            memset(iVar1,param_6,iVar4);
            iVar1 = iVar1 + iVar3;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00445d17
// Address: 00445d17
void __thiscall
FUN_00445d17(TDrawArea *param_1,int param_2,int param_3,int param_4,int param_5,uchar param_6,
            uchar param_7,uchar param_8,uchar param_9)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_5;
  iVar3 = param_2;
  if (param_4 < param_2) {
    param_2 = param_4;
    param_4 = iVar3;
  }
  if (param_5 < param_3) {
    param_5 = param_3;
    param_3 = iVar4;
  }
  iVar3 = param_4 - param_2;
  if ((0 < iVar3 + 1) && (iVar4 = param_5 - param_3, 0 < iVar4 + 1)) {
    iVar2 = param_2 + 1;
    TDrawArea::DrawHorzLine(param_1,iVar2,param_3,iVar3,param_6);
    iVar1 = param_3 + 1;
    TDrawArea::DrawVertLine(param_1,param_4,iVar1,iVar4 + -1,param_6);
    TDrawArea::DrawHorzLine(param_1,param_2 + 2,iVar1,iVar3 + -2,param_7);
    TDrawArea::DrawVertLine(param_1,param_4 + -1,param_3 + 2,iVar4 + -3,param_7);
    TDrawArea::DrawHorzLine(param_1,param_2,param_5,iVar3 + 1,param_9);
    TDrawArea::DrawVertLine(param_1,param_2,param_3,iVar4,param_9);
    TDrawArea::DrawHorzLine(param_1,iVar2,param_5 + -1,iVar3 + -1,param_8);
    TDrawArea::DrawVertLine(param_1,iVar2,iVar1,iVar4 + -2,param_8);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00445e3c
// Address: 00445e3c
void __thiscall
FUN_00445e3c(TDrawArea *param_1,int param_2,int param_3,int param_4,int param_5,uchar param_6,
            uchar param_7,uchar param_8,uchar param_9,uchar param_10,uchar param_11)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_5;
  iVar5 = param_2;
  if (param_4 < param_2) {
    param_2 = param_4;
    param_4 = iVar5;
  }
  if (param_5 < param_3) {
    param_5 = param_3;
    param_3 = iVar6;
  }
  iVar5 = param_4 - param_2;
  if ((0 < iVar5 + 1) && (iVar6 = param_5 - param_3, 0 < iVar6 + 1)) {
    iVar4 = param_2 + 1;
    TDrawArea::DrawHorzLine(param_1,iVar4,param_3,iVar5,param_6);
    iVar1 = param_3 + 1;
    TDrawArea::DrawVertLine(param_1,param_4,iVar1,iVar6 + -1,param_6);
    iVar2 = param_2 + 2;
    TDrawArea::DrawHorzLine(param_1,iVar2,iVar1,iVar5 + -2,param_7);
    iVar3 = param_3 + 2;
    TDrawArea::DrawVertLine(param_1,param_4 + -1,iVar3,iVar6 + -3,param_7);
    TDrawArea::DrawHorzLine(param_1,param_2 + 3,iVar3,iVar5 + -4,param_8);
    TDrawArea::DrawVertLine(param_1,param_4 + -2,param_3 + 3,iVar6 + -5,param_8);
    TDrawArea::DrawHorzLine(param_1,param_2,param_5,iVar5 + 1,param_11);
    TDrawArea::DrawVertLine(param_1,param_2,param_3,iVar6,param_11);
    TDrawArea::DrawHorzLine(param_1,iVar4,param_5 + -1,iVar5 + -1,param_10);
    TDrawArea::DrawVertLine(param_1,iVar4,iVar1,iVar6 + -2,param_10);
    TDrawArea::DrawHorzLine(param_1,iVar2,param_5 + -2,iVar5 + -3,param_9);
    TDrawArea::DrawVertLine(param_1,iVar2,iVar3,iVar6 + -4,param_9);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00445fd4
// Address: 00445fd4
void __thiscall
FUN_00445fd4(TDrawArea *param_1,int param_2,int param_3,int param_4,int param_5,uchar param_6,
            uchar param_7,undefined4 param_8,uchar param_9)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_5;
  iVar2 = param_2;
  if (param_4 < param_2) {
    param_2 = param_4;
    param_4 = iVar2;
  }
  if (param_5 < param_3) {
    param_5 = param_3;
    param_3 = iVar1;
  }
  iVar2 = param_4 - param_2;
  if ((0 < iVar2 + 1) && (iVar1 = param_5 - param_3, 0 < iVar1 + 1)) {
    TDrawArea::DrawHorzLine(param_1,param_2 + 1,param_3,iVar2,param_6);
    TDrawArea::DrawVertLine(param_1,param_4,param_3 + 1,iVar1 + -1,param_6);
    TDrawArea::DrawHorzLine(param_1,param_2 + 1,param_3 + 1,iVar2 + -1,param_7);
    TDrawArea::DrawVertLine(param_1,param_4 + -1,param_3 + 2,iVar1 + -2,param_7);
    TDrawArea::DrawHorzLine(param_1,param_2,param_5,iVar2 + 1,param_9);
    TDrawArea::DrawVertLine(param_1,param_2,param_3,iVar1,param_9);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004460bf
// Address: 004460bf
void __thiscall
FUN_004460bf(TDrawArea *param_1,int param_2,int param_3,int param_4,int param_5,uchar param_6,
            uchar param_7,uchar param_8,undefined4 param_9,uchar param_10,uchar param_11)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_5;
  iVar3 = param_2;
  if (param_4 < param_2) {
    param_2 = param_4;
    param_4 = iVar3;
  }
  if (param_5 < param_3) {
    param_5 = param_3;
    param_3 = iVar4;
  }
  iVar3 = param_4 - param_2;
  if ((0 < iVar3 + 1) && (iVar4 = param_5 - param_3, 0 < iVar4 + 1)) {
    iVar2 = param_2 + 1;
    TDrawArea::DrawHorzLine(param_1,iVar2,param_3,iVar3,param_6);
    iVar1 = param_3 + 1;
    TDrawArea::DrawVertLine(param_1,param_4,iVar1,iVar4 + -1,param_6);
    TDrawArea::DrawHorzLine(param_1,param_2 + 2,iVar1,iVar3 + -2,param_7);
    TDrawArea::DrawVertLine(param_1,param_4 + -1,param_3 + 2,iVar4 + -3,param_7);
    TDrawArea::DrawHorzLine(param_1,param_2 + 2,param_3 + 2,iVar3 + -3,param_8);
    TDrawArea::DrawVertLine(param_1,param_4 + -2,param_3 + 3,iVar4 + -4,param_8);
    TDrawArea::DrawHorzLine(param_1,param_2,param_5,iVar3 + 1,param_11);
    TDrawArea::DrawVertLine(param_1,param_2,param_3,iVar4,param_11);
    TDrawArea::DrawHorzLine(param_1,iVar2,param_5 + -1,iVar3 + -1,param_10);
    TDrawArea::DrawVertLine(param_1,iVar2,iVar1,iVar4 + -2,param_10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00446215
// Address: 00446215
void __thiscall FUN_00446215(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 200) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0044622d
// Address: 0044622d
void __thiscall FUN_0044622d(TDrawArea *param_1,int param_2,int param_3,int param_4,int param_5)
{
  RGE_Color_Table *pRVar1;
  int iVar2;
  long lVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  
  if ((param_1->shadow_color_table != (RGE_Color_Table *)0x0) && (param_1->Bits != (uchar *)0x0)) {
    iVar6 = (param_1->ClipRect).left;
    if (param_2 < iVar6) {
      param_2 = iVar6;
    }
    iVar6 = (param_1->ClipRect).top;
    if (param_3 < iVar6) {
      param_3 = iVar6;
    }
    iVar6 = (param_1->ClipRect).right;
    if (iVar6 < param_4) {
      param_4 = iVar6;
    }
    iVar6 = (param_1->ClipRect).bottom;
    if (iVar6 < param_5) {
      param_5 = iVar6;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (param_1->Width <= param_4) {
      param_4 = param_1->Width + -1;
    }
    if (param_1->Height <= param_5) {
      param_5 = param_1->Height + -1;
    }
    if ((param_2 <= param_4) && (param_3 <= param_5)) {
      iVar6 = param_1->Orien;
      lVar3 = TDrawArea::AlignedWidth(param_1);
      iVar7 = lVar3 * iVar6;
      iVar2 = param_3;
      if (iVar6 < 1) {
        iVar2 = (param_3 - param_1->Height) + 1;
      }
      pRVar1 = param_1->shadow_color_table;
      pbVar4 = param_1->Bits + iVar2 * iVar7 + param_2;
      pbVar8 = pbVar4 + (param_4 - param_2);
      if (param_3 <= param_5) {
        iVar6 = (param_5 - param_3) + 1;
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

// Function: FUN_0044633f
// Address: 0044633f
void __thiscall FUN_0044633f(int *param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x100;
  puVar1 = param_2;
  do {
    iVar2 = iVar2 + -1;
    *puVar1 = *(undefined4 *)((*param_1 - (int)param_2) + 0x74 + (int)(puVar1 + 1));
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0);
  return;
}

// --------------------------------------------------

// Function: FUN_00446368
// Address: 00446368
void __thiscall FUN_00446368(undefined4 *param_1,tagPALETTEENTRY *param_2)
{
  param_2->peRed = '\0';
  param_2->peGreen = '\0';
  param_2->peBlue = '\0';
  param_2->peFlags = '\0';
  param_2[0xff].peRed = 0xff;
  param_2[0xff].peGreen = 0xff;
  param_2[0xff].peBlue = 0xff;
  param_2[0xff].peFlags = '\0';
  TDrawSystem::ModifyPalette((TDrawSystem *)*param_1,0,0x100,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004463ad
// Address: 004463ad
// [HELPER] s_C__AOE__03d_BMP: "C:\AOE_%03d.BMP"
// [HELPER] s_take_snapshot: "take_snapshot"
void __thiscall FUN_004463ad(TDrawArea *param_1,char *param_2,int *param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  char *pcVar8;
  undefined2 uStack_874;
  int iStack_872;
  undefined2 uStack_86e;
  undefined2 uStack_86c;
  undefined4 uStack_86a;
  undefined4 uStack_864;
  int iStack_860;
  int iStack_85c;
  undefined2 uStack_858;
  undefined2 uStack_856;
  undefined4 uStack_854;
  undefined4 uStack_850;
  undefined4 uStack_84c;
  undefined4 uStack_848;
  undefined4 uStack_844;
  undefined4 uStack_840;
  undefined1 auStack_83c [60];
  undefined1 auStack_800 [1024];
  tagPALETTEENTRY atStack_400 [256];
  
  iStack_860 = param_1->Width;
  iVar1 = param_1->Height;
  uVar7 = iStack_860 + 3U & 0xfffc;
  iStack_872 = iVar1 * uVar7 + 0x436;
  uStack_874 = 0x4d42;
  uStack_86e = 0;
  uStack_86c = 0;
  uStack_86a = 0x436;
  uStack_864 = 0x28;
  uStack_858 = 1;
  uStack_856 = 8;
  uStack_854 = 0;
  uStack_850 = 0;
  uStack_84c = 0;
  uStack_848 = 0;
  uStack_844 = 0;
  uStack_840 = 0;
  iStack_85c = iVar1;
  TDrawArea::GetPalette(param_1,(tagPALETTEENTRY *)(auStack_800 + 0x400));
  iVar2 = 0;
  do {
    auStack_800[iVar2] = auStack_800[iVar2 + 0x402];
    auStack_800[iVar2 + 1] = auStack_800[iVar2 + 0x401];
    auStack_800[iVar2 + 2] = auStack_800[iVar2 + 0x400];
    auStack_800[iVar2 + 3] = 0;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x400);
  iVar2 = 0;
  while( true ) {
    if (param_2 == (char *)0x0) {
      iVar3 = *param_3;
      pcVar8 = s_C__AOE__03d_BMP;
    }
    else {
      iVar3 = *param_3;
      pcVar8 = param_2;
    }
    sprintf(auStack_83c,pcVar8,iVar3);
    iVar2 = iVar2 + 1;
    iVar3 = __open(auStack_83c,0);
    if (iVar3 == -1) break;
    *param_3 = *param_3 + 1;
    close(iVar3);
    if (1000 < iVar2) {
      return;
    }
  }
  iVar2 = malloc(uVar7);
  iVar3 = __open(auStack_83c,0x8301,0x180);
  if (iVar3 != -1) {
    write(iVar3,&uStack_874,0xe);
    write(iVar3,&uStack_864,0x28);
    write(iVar3,auStack_800,0x400);
    puVar4 = TDrawArea::Lock(param_1,s_take_snapshot,1);
    if (puVar4 != (uchar *)0x0) {
      while (iVar1 = iVar1 + -1, -1 < iVar1) {
        iVar5 = 0;
        puVar6 = (undefined1 *)param_1->CurDisplayOffsets[iVar1];
        if (0 < param_1->Width) {
          do {
            *(undefined1 *)(iVar5 + iVar2) = *puVar6;
            iVar5 = iVar5 + 1;
            puVar6 = puVar6 + 1;
          } while (iVar5 < param_1->Width);
        }
        write(iVar3,iVar2,uVar7);
      }
      TDrawArea::Unlock(param_1,s_take_snapshot);
    }
    close(iVar3);
  }
  free(iVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_004465cc
// Address: 004465cc
// [HELPER] s_: ""
undefined4 * __fastcall FUN_004465cc(undefined4 *param_1)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  param_1[3] = 0;
  param_1[4] = 0;
  pcVar2 = (char *)malloc(1);
  uVar3 = 0xffffffff;
  *param_1 = pcVar2;
  pcVar5 = s_;
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
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044661f
// Address: 0044661f
undefined4 * __thiscall FUN_0044661f(undefined4 *param_1,undefined4 *param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  if ((int)param_1[1] < 1) {
    *param_1 = 0;
    return param_1;
  }
  pcVar2 = (char *)malloc(param_1[1] + 1);
  uVar3 = 0xffffffff;
  *param_1 = pcVar2;
  pcVar5 = (char *)*param_2;
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
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044668a
// Address: 0044668a
undefined4 * __thiscall FUN_0044668a(undefined4 *param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  param_1[2] = 0xffffffff;
  param_1[1] = iVar4;
  param_1[3] = 0;
  param_1[4] = 0;
  if (iVar4 < 1) {
    *param_1 = 0;
    return param_1;
  }
  pcVar2 = (char *)malloc(~uVar3);
  uVar3 = 0xffffffff;
  *param_1 = pcVar2;
  do {
    pcVar6 = param_2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004466f8
// Address: 004466f8
void __fastcall FUN_004466f8(int *param_1)
{
  if (*param_1 != 0) {
    free(*param_1);
  }
  return;
}

// --------------------------------------------------

// Function: operator<<
// Address: 00446710
/* class ostream & __cdecl operator<<(class ostream &,class DString const &) */

ostream * __cdecl operator<<(ostream *param_1,DString *param_2)
{
  if (param_2->stringValue != (char *)0x0) {
    ostream::operator<<(param_1,param_2->stringValue);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0044672b
// Address: 0044672b
istream * FUN_0044672b(istream *param_1,DString *param_2)
{
  char acStack_100 [256];
  
  param_1->_fGline = param_1->_fGline + 1;
  istream::get(param_1,acStack_100,0x100,10);
  DString::operator=(param_2,acStack_100);
  return param_1;
}

// --------------------------------------------------

// Function: operator>>
// Address: 00446730
/* WARNING: Variable defined which should be unmapped: buffer */
/* class istream & __cdecl operator>>(class istream &,class DString &) */

istream * __cdecl operator>>(istream *param_1,DString *param_2)
{
  char buffer [256];
  
  param_1->_fGline = param_1->_fGline + 1;
  istream::get(param_1,buffer + 4,0x100,10);
  DString::operator=(param_2,buffer + 4);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00446773
// Address: 00446773
int * __thiscall FUN_00446773(int *param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  if (*param_1 != 0) {
    free(*param_1);
  }
  uVar3 = 0xffffffff;
  param_1[2] = -1;
  param_1[3] = 0;
  param_1[4] = 0;
  pcVar2 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  param_1[1] = iVar4;
  if (iVar4 < 1) {
    *param_1 = 0;
    return param_1;
  }
  pcVar2 = (char *)malloc(~uVar3);
  uVar3 = 0xffffffff;
  *param_1 = (int)pcVar2;
  do {
    pcVar6 = param_2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004467ff
// Address: 004467ff
int * __thiscall FUN_004467ff(int *param_1,undefined4 *param_2)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (*param_1 != 0) {
    free(*param_1);
  }
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  iVar2 = param_2[1];
  param_1[1] = iVar2;
  if (iVar2 < 1) {
    *param_1 = 0;
    return param_1;
  }
  pcVar3 = (char *)malloc(iVar2 + 1);
  uVar4 = 0xffffffff;
  *param_1 = (int)pcVar3;
  pcVar6 = (char *)*param_2;
  do {
    pcVar7 = pcVar6;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar7 + -uVar4;
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
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00446877
// Address: 00446877
bool FUN_00446877(undefined4 *param_1,undefined4 *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)*param_2;
  pbVar2 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar4 == (uint)(bVar4 != 0);
}

// --------------------------------------------------

// Function: operator==
// Address: 00446880
/* int __cdecl operator==(class DString const &,class DString const &) */

int __cdecl operator==(DString *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)param_2->stringValue;
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return 1;
    }
  }
  return (uint)(1 - bVar4 == (uint)(bVar4 != 0));
}

// --------------------------------------------------

// Function: FUN_004468d1
// Address: 004468d1
bool FUN_004468d1(undefined4 *param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar3 == (uint)(bVar3 != 0);
}

// --------------------------------------------------

// Function: operator==
// Address: 004468e0
/* int __cdecl operator==(class DString const &,char const *) */

int __cdecl operator==(DString *param_1,char *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return 1;
    }
  }
  return (uint)(1 - bVar3 == (uint)(bVar3 != 0));
}

// --------------------------------------------------

// Function: FUN_0044692f
// Address: 0044692f
bool FUN_0044692f(byte *param_1,undefined4 *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)*param_2;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = param_1[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = param_1 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar3 == (uint)(bVar3 != 0);
}

// --------------------------------------------------

// Function: operator==
// Address: 00446930
/* int __cdecl operator==(char const *,class DString const &) */

int __cdecl operator==(char *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_2->stringValue;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 1;
    }
  }
  return (uint)(1 - bVar3 == (uint)(bVar3 != 0));
}

// --------------------------------------------------

// Function: FUN_0044697f
// Address: 0044697f
bool FUN_0044697f(undefined4 *param_1,undefined4 *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)*param_2;
  pbVar2 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return 1 - bVar4 != (uint)(bVar4 != 0);
}

// --------------------------------------------------

// Function: operator!=
// Address: 00446980
/* int __cdecl operator!=(class DString const &,class DString const &) */

int __cdecl operator!=(DString *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)param_2->stringValue;
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)(1 - bVar4 != (uint)(bVar4 != 0));
}

// --------------------------------------------------

// Function: FUN_004469d1
// Address: 004469d1
bool FUN_004469d1(undefined4 *param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return 1 - bVar3 != (uint)(bVar3 != 0);
}

// --------------------------------------------------

// Function: operator!=
// Address: 004469e0
/* int __cdecl operator!=(class DString const &,char const *) */

int __cdecl operator!=(DString *param_1,char *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)(1 - bVar3 != (uint)(bVar3 != 0));
}

// --------------------------------------------------

// Function: FUN_00446a2f
// Address: 00446a2f
bool FUN_00446a2f(byte *param_1,undefined4 *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)*param_2;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = param_1[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = param_1 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return 1 - bVar3 != (uint)(bVar3 != 0);
}

// --------------------------------------------------

// Function: operator!=
// Address: 00446a30
/* int __cdecl operator!=(char const *,class DString const &) */

int __cdecl operator!=(char *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_2->stringValue;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)(1 - bVar3 != (uint)(bVar3 != 0));
}

// --------------------------------------------------

// Function: FUN_00446a7f
// Address: 00446a7f
bool FUN_00446a7f(undefined4 *param_1,undefined4 *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)*param_2;
  pbVar2 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return (int)((1 - (uint)bVar4) - (uint)(bVar4 != 0)) < 0;
}

// --------------------------------------------------

// Function: operator<
// Address: 00446a80
/* int __cdecl operator<(class DString const &,class DString const &) */

int __cdecl operator<(DString *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)param_2->stringValue;
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) break;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)((int)((1 - (uint)bVar4) - (uint)(bVar4 != 0)) < 0);
}

// --------------------------------------------------

// Function: FUN_00446ad1
// Address: 00446ad1
bool FUN_00446ad1(undefined4 *param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return (int)((1 - (uint)bVar3) - (uint)(bVar3 != 0)) < 0;
}

// --------------------------------------------------

// Function: operator<
// Address: 00446ae0
/* int __cdecl operator<(class DString const &,char const *) */

int __cdecl operator<(DString *param_1,char *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)((int)((1 - (uint)bVar3) - (uint)(bVar3 != 0)) < 0);
}

// --------------------------------------------------

// Function: FUN_00446b2f
// Address: 00446b2f
bool FUN_00446b2f(byte *param_1,undefined4 *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)*param_2;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = param_1[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = param_1 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return (int)((1 - (uint)bVar3) - (uint)(bVar3 != 0)) < 0;
}

// --------------------------------------------------

// Function: operator<
// Address: 00446b30
/* int __cdecl operator<(char const *,class DString const &) */

int __cdecl operator<(char *param_1,DString *param_2)
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  pbVar2 = (byte *)param_2->stringValue;
  while( true ) {
    bVar1 = *param_1;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (uint)((int)((1 - (uint)bVar3) - (uint)(bVar3 != 0)) < 0);
}

// --------------------------------------------------

// Function: FUN_00446b7f
// Address: 00446b7f
bool FUN_00446b7f(undefined4 *param_1,undefined4 *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  pbVar5 = (byte *)*param_2;
  pbVar4 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar4;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar4[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) break;
    pbVar4 = pbVar4 + 2;
    pbVar5 = pbVar5 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  uVar2 = (uint)(bVar6 != 0);
  uVar3 = 1 - bVar6;
  return uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2);
}

// --------------------------------------------------

// Function: operator>
// Address: 00446b80
/* int __cdecl operator>(class DString const &,class DString const &) */

int __cdecl operator>(DString *param_1,DString *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  pbVar5 = (byte *)param_2->stringValue;
  pbVar4 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar4;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar4[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) break;
    pbVar4 = pbVar4 + 2;
    pbVar5 = pbVar5 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  uVar2 = (uint)(bVar6 != 0);
  uVar3 = 1 - bVar6;
  return (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2));
}

// --------------------------------------------------

// Function: FUN_00446bd1
// Address: 00446bd1
bool FUN_00446bd1(undefined4 *param_1,byte *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar4;
    bVar5 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar4[1];
    bVar5 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    pbVar4 = pbVar4 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  uVar2 = (uint)(bVar5 != 0);
  uVar3 = 1 - bVar5;
  return uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2);
}

// --------------------------------------------------

// Function: operator>
// Address: 00446be0
/* int __cdecl operator>(class DString const &,char const *) */

int __cdecl operator>(DString *param_1,char *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = (byte *)param_1->stringValue;
  while( true ) {
    bVar1 = *pbVar4;
    bVar5 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = pbVar4[1];
    bVar5 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar4 = pbVar4 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  uVar2 = (uint)(bVar5 != 0);
  uVar3 = 1 - bVar5;
  return (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2));
}

// --------------------------------------------------

// Function: FUN_00446c2f
// Address: 00446c2f
bool FUN_00446c2f(byte *param_1,undefined4 *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = (byte *)*param_2;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = param_1[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) break;
    param_1 = param_1 + 2;
    pbVar4 = pbVar4 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  uVar2 = (uint)(bVar5 != 0);
  uVar3 = 1 - bVar5;
  return uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2);
}

// --------------------------------------------------

// Function: operator>
// Address: 00446c30
/* int __cdecl operator>(char const *,class DString const &) */

int __cdecl operator>(char *param_1,DString *param_2)
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar4 = (byte *)param_2->stringValue;
  while( true ) {
    bVar1 = *param_1;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = ((byte *)param_1)[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) break;
    param_1 = (char *)((byte *)param_1 + 2);
    pbVar4 = pbVar4 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  uVar2 = (uint)(bVar5 != 0);
  uVar3 = 1 - bVar5;
  return (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2));
}

// --------------------------------------------------

// Function: FUN_00446c7f
// Address: 00446c7f
DString * __thiscall FUN_00446c7f(DString *param_1,DString *param_2,DString *param_3)
{
  DString DVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 in_stack_ffffffc0 [12];
  int iVar2;
  DString DStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d35f;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = 0x446cab;
  DString::DString(&DStack_20,param_1);
  uStack_4 = 1;
  DString::DString((DString *)&stack0xffffffc0,param_3);
  DVar1.indexValue = iVar2;
  DVar1.stringValue = (char *)in_stack_ffffffc0._0_4_;
  DVar1.lengthValue = in_stack_ffffffc0._4_4_;
  DVar1.numWordsValue = in_stack_ffffffc0._8_4_;
  DVar1.currentWordValue = (int)param_1;
  DString::append(&DStack_20,DVar1);
  DString::DString(param_2,&DStack_20);
  uStack_4 = uStack_4 & 0xffffff00;
  DString::~DString(&DStack_20);
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_00446d09
// Address: 00446d09
int __thiscall FUN_00446d09(int *param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 + 1 <= param_1[1])) {
    return param_2 + *param_1;
  }
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_00446d2f
// Address: 00446d2f
undefined4 __fastcall FUN_00446d2f(undefined4 *param_1)
{
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_00446d33
// Address: 00446d33
undefined4 __fastcall FUN_00446d33(int param_1)
{
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_00446d44
// Address: 00446d44
undefined4 __fastcall FUN_00446d44(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_00446d54
// Address: 00446d54
undefined4 __fastcall FUN_00446d54(undefined4 *param_1)
{
  char *pcVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0055d378;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  pcVar1 = DString::operator_char_((DString *)&stack0x00000004);
  iVar2 = strstr(*param_1,pcVar1);
  uStack_4 = 0xffffffff;
  if (iVar2 != 0) {
    DString::~DString((DString *)&stack0x00000004);
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
  DString::~DString((DString *)&stack0x00000004);
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00446dda
// Address: 00446dda
bool __thiscall FUN_00446dda(undefined4 *param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = strstr(*param_1,param_2);
  return iVar1 != 0;
}

// --------------------------------------------------

// Function: FUN_00446df9
// Address: 00446df9
int __fastcall FUN_00446df9(int *param_1)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = param_1[2];
  if (iVar1 == -1) {
    iVar1 = param_1[1];
    if (iVar1 == 0) {
      return iVar1;
    }
    bVar3 = *(char *)*param_1 != ' ';
    if (bVar3) {
      param_1[2] = 1;
    }
    else {
      param_1[2] = 0;
    }
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (bVar3) {
LAB_00446e61:
          iVar1 = isspace((int)*(char *)(iVar2 + *param_1));
          if (iVar1 != 0) {
            bVar3 = false;
          }
        }
        else {
          iVar1 = isspace((int)*(char *)(iVar2 + *param_1));
          if (iVar1 != 0) goto LAB_00446e61;
          bVar3 = true;
          param_1[2] = param_1[2] + 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[1]);
    }
    iVar1 = param_1[2];
  }
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00446e85
// Address: 00446e85
// [HELPER] s_: ""
DString * __thiscall FUN_00446e85(DString *param_1,DString *param_2,int param_3)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  DString DStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d398;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = 0;
  iVar2 = DString::numWords(param_1);
  if ((param_3 <= iVar2) && (0 < param_3)) {
    iVar2 = param_1->currentWordValue + 1;
    if (param_3 == iVar2) {
      param_1->currentWordValue = iVar2;
      DString::nextWord(param_1,param_2,1);
      goto LAB_00446fb6;
    }
    iVar2 = 0;
    bVar1 = false;
    if (param_3 != 0) {
      do {
        if (param_1->lengthValue <= iVar2) break;
        if ((bVar1) || (iVar3 = isspace((int)param_1->stringValue[iVar2]), iVar3 != 0)) {
          iVar3 = isspace((int)param_1->stringValue[iVar2]);
          if (iVar3 != 0) {
            bVar1 = false;
          }
        }
        else {
          iVar4 = iVar4 + 1;
          bVar1 = true;
        }
        iVar2 = iVar2 + 1;
      } while (iVar4 != param_3);
    }
    if (iVar4 == param_3) {
      iVar4 = iVar2 + -1;
      iVar3 = isspace((int)param_1->stringValue[iVar2]);
      while ((iVar3 == 0 && (iVar2 < param_1->lengthValue))) {
        iVar2 = iVar2 + 1;
        iVar3 = isspace((int)param_1->stringValue[iVar2]);
      }
      DString::subString(param_1,&DStack_20,iVar4,iVar2 - iVar4);
      uStack_4 = 0;
      DString::DString(param_2,&DStack_20);
      uStack_4 = 0xffffffff;
      DString::~DString(&DStack_20);
      goto LAB_00446fb6;
    }
  }
  DString::DString(param_2,s_);
LAB_00446fb6:
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_00446fcd
// Address: 00446fcd
DString * __thiscall FUN_00446fcd(DString *param_1,DString *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  DString DStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d3cf;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar3 = param_1->indexValue;
  iVar1 = isspace((int)param_1->stringValue[iVar3]);
  while ((iVar1 != 0 && (iVar3 < param_1->lengthValue))) {
    iVar3 = iVar3 + 1;
    iVar1 = isspace((int)param_1->stringValue[iVar3]);
  }
  iVar2 = isspace((int)param_1->stringValue[iVar3]);
  iVar1 = iVar3;
  while ((iVar2 == 0 && (iVar1 < param_1->lengthValue))) {
    iVar1 = iVar1 + 1;
    iVar2 = isspace((int)param_1->stringValue[iVar1]);
  }
  if (param_3 != 0) {
    param_1->indexValue = iVar1;
  }
  DString::subString(param_1,&DStack_20,iVar3,iVar1 - iVar3);
  uStack_4 = 1;
  DString::DString(param_2,&DStack_20);
  uStack_4 = uStack_4 & 0xffffff00;
  DString::~DString(&DStack_20);
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------

// Function: FUN_004470ae
// Address: 004470ae
void __fastcall FUN_004470ae(int param_1)
{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_004470b9
// Address: 004470b9
void __fastcall FUN_004470b9(int *param_1)
{
  int iVar1;
  
  iVar1 = isspace((int)*(char *)(*param_1 + param_1[3]));
  while ((iVar1 != 0 && (param_1[3] < param_1[1]))) {
    iVar1 = param_1[3] + 1;
    param_1[3] = iVar1;
    iVar1 = isspace((int)*(char *)(*param_1 + iVar1));
  }
  iVar1 = isspace((int)*(char *)(*param_1 + param_1[3]));
  while ((iVar1 == 0 && (param_1[3] < param_1[1]))) {
    iVar1 = param_1[3] + 1;
    param_1[3] = iVar1;
    iVar1 = isspace((int)*(char *)(*param_1 + iVar1));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00447133
// Address: 00447133
DString * __thiscall FUN_00447133(int *param_1,DString *param_2,int param_3,int param_4)
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  DString DStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055d3ff;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pcVar2 = (char *)malloc(param_4 + 1);
  iVar3 = 0;
  iVar4 = 0;
  if (param_3 < param_1[1]) {
    do {
      iVar4 = iVar3;
      if (param_4 <= iVar3) break;
      iVar4 = iVar3 + 1;
      pcVar1 = (char *)(param_3 + *param_1);
      param_3 = param_3 + 1;
      pcVar2[iVar3] = *pcVar1;
      iVar3 = iVar4;
    } while (param_3 < param_1[1]);
  }
  pcVar2[iVar4] = '\0';
  DString::DString(&DStack_20,pcVar2);
  uStack_4 = 1;
  DString::DString(param_2,&DStack_20);
  uStack_4 = uStack_4 & 0xffffff00;
  DString::~DString(&DStack_20);
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}

// --------------------------------------------------


// GLOBAL FUNCTIONS PART 2600
// Function: FUN_0046b676
// Address: 0046b676
// [HELPER] ObstructionValueMask: "3fcff3fc"
// [HELPER] ObstructionValueShift: "06040200"
void __thiscall FUN_0046b676(int param_1,int param_2,uint param_3)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  param_1 = param_1 + param_2 * 0xff;
  bVar1 = *(byte *)(((int)param_3 >> 2) + 0xce624 + param_1);
  bVar2 = *(byte *)((int)&ObstructionValueShift + (param_3 & 3));
  bVar3 = bVar1 >> (bVar2 & 0x1f) & 3;
  if (bVar3 != 0) {
    *(byte *)(((int)param_3 >> 2) + 0xce624 + param_1) =
         *(byte *)((int)&ObstructionValueMask + (param_3 & 3)) & bVar1 | bVar3 - 1 << (bVar2 & 0x1f)
    ;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046b6d2
// Address: 0046b6d2
// [HELPER] ObstructionValueShift: "06040200"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0046b6d2(PathingSystem *param_1,ulong *param_2,ulong *param_3,uint param_4,void *param_5,
            RGE_Moving_Object *param_6,float param_7,RGE_Static_Object *param_8,int param_9,
            float *param_10,int param_11,int param_12,int param_13,int param_14,int *param_15,
            void *param_16)
{
  XYPoint *pXVar1;
  MGP_FloatHeap *pMVar2;
  MGP_FloatHeap *pMVar3;
  uchar uVar4;
  uchar uVar5;
  RGE_Player *this;
  bool bVar6;
  uchar uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  uchar *puVar11;
  int *piVar12;
  RGE_Static_Object *pRVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  void *pvVar21;
  uint uVar22;
  int iVar23;
  void *pvVar24;
  uchar *puVar25;
  int iVar26;
  int iVar27;
  float fVar28;
  uint uVar29;
  ulong *puVar30;
  Path *pPVar31;
  RGE_Map *pRVar32;
  void *pvVar33;
  uint uVar34;
  byte bVar35;
  uint uVar36;
  RGE_Moving_Object *pRVar37;
  uint uVar38;
  void *pvVar39;
  byte *pbVar40;
  uchar (*pauVar41) [255];
  ulong *puVar42;
  float10 fVar43;
  float fVar44;
  uint uStack_78;
  void *pvStack_74;
  uint uStack_50;
  float fStack_4c;
  uint uStack_3c;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  uint uStack_28;
  float fStack_24;
  int iStack_20;
  
  pRVar37 = param_6;
  if (((((((int)param_2 < 0) || ((int)param_3 < 0)) ||
        (iVar10 = param_1->xSizeValue, iVar10 < (int)param_2)) ||
       ((iVar10 < (int)param_3 || ((int)param_4 < 0)))) || ((int)param_5 < 0)) ||
     ((iVar10 < (int)param_4 || (iVar10 < (int)param_5)))) {
    if (param_9 != 1) {
      return 0;
    }
    pPVar31 = &param_6->pathValue;
    if (param_6->storePathInExceptionPath != '\0') {
      pPVar31 = &param_6->exceptionPathValue;
    }
LAB_0046d1eb:
    Path::killPath(pPVar31);
    return 0;
  }
  if (_DAT_00570e54 < param_7) {
    uVar9 = param_4;
    uVar36 = (uint)param_2;
    if ((int)param_4 < (int)param_2) {
      uVar9 = (uint)param_2;
      uVar36 = param_4;
    }
    pvVar21 = param_3;
    pvVar33 = param_5;
    if ((int)param_5 < (int)param_3) {
      pvVar21 = param_5;
      pvVar33 = param_3;
    }
    uVar9 = uVar9 - uVar36;
    uVar36 = (int)pvVar33 - (int)pvVar21;
    if ((int)uVar9 < (int)uVar36) {
      iVar10 = uVar36 - uVar9;
    }
    else {
      iVar10 = uVar9 - uVar36;
      uVar9 = uVar36;
    }
    if ((float)(int)((&DiagionalDistance)[uVar9 & 0xff] + iVar10 * 4) < param_7 * _DAT_00570e58) {
      if (param_10 != (float *)0x0) {
        *param_10 = 0.0;
      }
      if (param_9 != 1) {
        return 1;
      }
      pPVar31 = &param_6->pathValue;
      if (param_6->storePathInExceptionPath != '\0') {
        pPVar31 = &param_6->exceptionPathValue;
      }
      Path::killPath(pPVar31);
      return 1;
    }
    fVar43 = (float10)(**(code **)(param_6->_padding_ + 0xfc))();
    if (fVar43 == (float10)_DAT_00570e5c) {
      if (param_10 != (float *)0x0) {
        *param_10 = 0.0;
      }
      if (param_9 != 1) {
        return 0;
      }
      pPVar31 = &pRVar37->pathValue;
      if (pRVar37->storePathInExceptionPath != '\0') {
        Path::killPath(&pRVar37->exceptionPathValue);
        return 0;
      }
      goto LAB_0046d1eb;
    }
  }
  param_1->currentObject = pRVar37;
  param_1->currentTerrainTable =
       param_1->worldValue->terrains[*(short *)(pRVar37->_padding_ + 0x66)];
  param_1->currentTerrainException1 = pRVar37->currentTerrainException1;
  param_1->currentTerrainException2 = pRVar37->currentTerrainException2;
  param_1->currentUnobstructiblePlayerID = (int)param_15;
  param_1->currentUnobstructibleGroupID = (int)param_16;
  (param_1->currentUnobstructibles).numberValue = 0;
  if (MapPathsDisplay != 0) {
    pRVar32 = param_1->mapValue;
    iVar10 = 0;
    if (0 < pRVar32->map_height) {
      do {
        iVar27 = 0;
        if (0 < pRVar32->map_width) {
          puVar11 = &pRVar32->map_row_offset[iVar10]->draw_attribute;
          do {
            iVar27 = iVar27 + 1;
            *puVar11 = *puVar11 & 0x70;
            puVar11 = puVar11 + 0x18;
          } while (iVar27 < param_1->mapValue->map_width);
        }
        pRVar32 = param_1->mapValue;
        iVar10 = iVar10 + 1;
      } while (iVar10 < pRVar32->map_height);
    }
    piVar12 = (int *)(**(code **)(rge_base_game->_padding_ + 0x2c))();
    (**(code **)(*piVar12 + 0x20))(2);
  }
  (param_1->minTarget).x = param_4 * 4;
  (param_1->minTarget).y = (int)param_5 * 4;
  param_1->currentTargetID = (int)param_8;
  (param_1->maxTarget).x = param_4 * 4 + 3;
  (param_1->maxTarget).y = (int)param_5 * 4 + 3;
  if (param_8 != (RGE_Static_Object *)0xffffffff) {
    pRVar13 = RGE_Game_World::object(param_1->worldValue,(int)param_8);
    if (pRVar13 == (RGE_Static_Object *)0x0) {
      param_1->currentTargetID = -1;
    }
    else {
      iVar10 = __ftol();
      (param_1->minTarget).x = iVar10;
      iVar10 = __ftol();
      (param_1->minTarget).y = iVar10;
      iVar10 = __ftol();
      (param_1->maxTarget).x = iVar10;
      iVar10 = __ftol();
      (param_1->maxTarget).y = iVar10;
    }
  }
  param_1->startOfPath = 1;
  param_1->checkTerrainOnFirstPass = param_12;
  iVar10 = RGE_Static_Object::removeFromObstructionMap
                     ((RGE_Static_Object *)param_1->currentObject,param_1->aiPS);
  iVar27 = 1;
  param_1->currentObjectInObMap = iVar10;
  fVar43 = (float10)floor((double)(float)param_1->currentObject->_padding_);
  fVar44 = (float)(fVar43 - (float10)_DAT_00570e64);
  fVar43 = (float10)floor((double)(float)param_1->currentObject->_padding_);
  iVar10 = PathingSystem::passable
                     (param_1,param_1->currentObject,(float)(fVar43 - (float10)_DAT_00570e64),fVar44
                      ,iVar27);
  if (iVar10 == 0) {
    fVar43 = (float10)floor((double)(float)pRVar37->_padding_);
    param_1->currentXOffset = (float)((float10)(float)pRVar37->_padding_ - fVar43);
    fVar43 = (float10)floor((double)(float)pRVar37->_padding_);
    param_1->currentYOffset = (float)((float10)(float)pRVar37->_padding_ - fVar43);
  }
  else {
    param_1->currentXOffset = 0.5;
    param_1->currentYOffset = 0.5;
  }
  pRVar37 = param_1->currentObject;
  if ((9 < pRVar37->continueCounter) && (param_15 = (int *)0x0, 0 < pRVar37->_padding_)) {
    do {
      iVar10 = (int)param_15;
      if ((pRVar37->_padding_ + -1 < (int)param_15) &&
         (param_16 = operator_new((int)param_15 * 4 + 4), param_16 != (void *)0x0)) {
        iVar27 = 0;
        if (0 < pRVar37->_padding_) {
          do {
            if (iVar10 + 1 <= iVar27) break;
            *(undefined4 *)((int)param_16 + iVar27 * 4) =
                 *(undefined4 *)(pRVar37->_padding_ + iVar27 * 4);
            iVar27 = iVar27 + 1;
            iVar10 = (int)param_15;
          } while (iVar27 < pRVar37->_padding_);
        }
        operator_delete((void *)pRVar37->_padding_);
        pRVar37->_padding_ = (int)param_16;
        pRVar37->_padding_ = iVar10 + 1;
      }
      pRVar13 = RGE_Game_World::object
                          (param_1->worldValue,*(int *)(pRVar37->_padding_ + iVar10 * 4));
      if ((pRVar13 != (RGE_Static_Object *)0x0) &&
         (pRVar13->id != param_1->currentObject->_padding_)) {
        uVar9 = (**(code **)(pRVar13->_padding_ + 0x130))();
        param_15 = (int *)(uVar9 & 0xff);
        fVar43 = (float10)(**(code **)(pRVar13->_padding_ + 0xf4))();
        param_8 = pRVar13[2].inside_obj;
        if ((param_15 != (int *)0x0) ||
           ((fVar43 != (float10)_DAT_00570e5c || (_DAT_00570e5c < (float)param_8)))) {
          RGE_Static_Object::removeFromObstructionMap(pRVar13,param_1->aiPS);
        }
      }
      pRVar37 = param_1->currentObject;
      param_15 = (int *)(iVar10 + 1);
    } while ((int)param_15 < pRVar37->_padding_);
  }
  pRVar37 = param_1->currentObject;
  iVar10 = __ftol();
  (param_1->minInitialPosition).x = iVar10;
  if (iVar10 < 0) {
    (param_1->minInitialPosition).x = 0;
  }
  iVar10 = __ftol();
  (param_1->minInitialPosition).y = iVar10;
  if (iVar10 < 0) {
    (param_1->minInitialPosition).y = 0;
  }
  iVar10 = __ftol();
  pXVar1 = &param_1->maxInitialPosition;
  iVar27 = param_1->xSizeValue * 4;
  pXVar1->x = iVar10;
  if (iVar27 < iVar10) {
    pXVar1->x = iVar27;
  }
  iVar27 = __ftol();
  iVar10 = param_1->ySizeValue;
  (param_1->maxInitialPosition).y = iVar27;
  iVar10 = iVar10 * 4;
  if (iVar10 < iVar27) {
    (param_1->maxInitialPosition).y = iVar10;
  }
  RGE_Moving_Object::setInitialPoints(pRVar37,&param_1->minInitialPosition,pXVar1);
  (param_1->initialTile).y = (int)param_3;
  bVar35 = param_1->CurrentFacetMask;
  (param_1->initialTile).x = (int)param_2;
  param_1->MGP_closestTargetDistance = -1;
  if (bVar35 < 0xf0) {
    param_1->CurrentFacetMask = bVar35 + 8;
  }
  else {
    param_1->CurrentFacetMask = '\0';
    pauVar41 = param_1->facetValue;
    for (iVar10 = 0x3f80; iVar10 != 0; iVar10 = iVar10 + -1) {
      *(uchar *)((int)pauVar41 + 0) = 0xff;
      *(uchar *)((int)pauVar41 + 1) = 0xff;
      *(uchar *)((int)pauVar41 + 2) = 0xff;
      *(uchar *)((int)pauVar41 + 3) = 0xff;
      pauVar41 = (uchar (*) [255])(*pauVar41 + 4);
    }
    (*pauVar41)[0] = 0xff;
  }
  param_1->numberOpenPathsValue = 1;
  param_1->numberTraversedPathsValue = 0;
  uVar9 = param_4;
  uVar36 = (uint)param_2;
  if ((int)param_4 < (int)param_2) {
    uVar9 = (uint)param_2;
    uVar36 = param_4;
  }
  pvVar21 = param_3;
  pvVar33 = param_5;
  if ((int)param_5 < (int)param_3) {
    pvVar21 = param_5;
    pvVar33 = param_3;
  }
  uVar9 = uVar9 - uVar36;
  uVar36 = (int)pvVar33 - (int)pvVar21;
  if ((int)uVar9 < (int)uVar36) {
    iVar10 = uVar36 - uVar9;
  }
  else {
    iVar10 = uVar9 - uVar36;
    uVar9 = uVar36;
  }
  param_15 = (&DiagionalDistance)[uVar9 & 0xff] + iVar10 * 4;
  param_1->MGP_costValue[(int)param_2][(int)param_3] = (int)param_15;
  param_1->MGP_openPaths[1].total = (int)param_15;
  (param_1->MGP_bestTraversedPath).total = (int)param_15;
  param_1->MGP_openPaths[1].x = (uchar)param_2;
  param_1->MGP_openPaths[1].y = (uchar)param_3;
  param_1->MGP_openPaths[0].total = -2000000000;
  (param_1->MGP_bestTraversedPath).x = (uchar)param_2;
  (param_1->MGP_bestTraversedPath).y = (uchar)param_3;
  if ((float)param_14 <= param_7) {
    iVar10 = __ftol();
  }
  else {
    iVar10 = param_14 << 4;
  }
  iVar27 = param_1->currentObject->_padding_;
  param_2 = *(ulong **)(iVar27 + 0x34);
  param_7 = (param_1->currentXOffset - _DAT_00570e68) - *(float *)(iVar27 + 0x30);
  iVar27 = __ftol();
  iVar27 = iVar27 + -100;
  iVar14 = __ftol();
  iVar14 = iVar14 + -100;
  param_15 = (int *)((param_1->currentYOffset - _DAT_00570e68) - (float)param_2);
  iVar15 = __ftol();
  param_2 = (ulong *)((float)param_2 + param_1->currentYOffset);
  iVar15 = iVar15 + -100;
  iVar16 = __ftol();
  iVar16 = iVar16 + -100;
  iVar17 = __ftol();
  param_8 = (RGE_Static_Object *)(-400 - iVar17);
  iVar17 = __ftol();
  iVar17 = -400 - iVar17;
  param_12 = __ftol();
  param_12 = -400 - param_12;
  iVar18 = __ftol();
  iStack_2c = 0;
  param_3 = (ulong *)(((int)param_5 - (int)param_3) * ((int)param_5 - (int)param_3));
  iVar19 = __ftol();
  iVar19 = (int)(iVar19 + (iVar19 >> 0x1f & 0xfU)) >> 4;
  if (iVar19 < 0xb) {
    iStack_20 = (iVar19 * numberPathingIterations) / 10;
  }
  else {
    iStack_20 = (iVar19 * numberPathingIterations) / 100;
  }
  this = (RGE_Player *)param_1->currentObject->_padding_;
  if ((this->id == 0) && (100 < iStack_20)) {
    iStack_20 = 100;
  }
  iVar20 = RGE_Player::computerPlayer(this);
  if (iVar20 == 1) {
    iStack_20 = (iVar19 * 0x9c4) / 100;
  }
  if (0 < param_1->numberOpenPathsValue) {
LAB_0046bf0e:
    if ((((numberPathingIterations == -1) || (param_11 != 1)) || (iStack_2c <= iStack_20)) &&
       (iStack_2c < 0x4e21)) {
      uVar9 = (uint)param_1->MGP_openPaths[1].x;
      pvVar21 = (void *)(uint)param_1->MGP_openPaths[1].y;
      if (MapPathsDisplay != 0) {
        param_1->mapValue->map_row_offset[(int)pvVar21][uVar9].draw_attribute = 0x81;
      }
      uVar36._0_1_ = param_1->MGP_openPaths[1].x;
      uVar36._1_1_ = param_1->MGP_openPaths[1].y;
      uVar36._2_2_ = param_1->MGP_openPaths[1].next;
      uVar36 = uVar36 & 0xff;
      pvStack_74 = (void *)(*(uint *)&param_1->MGP_openPaths[1].y & 0xff);
      param_3 = (ulong *)(((int)param_5 - (int)pvStack_74) * ((int)param_5 - (int)pvStack_74));
      iVar19 = __ftol();
      if ((param_1->MGP_closestTargetDistance == -1) ||
         (iVar19 < param_1->MGP_closestTargetDistance)) {
        param_1->MGP_closestTargetDistance = iVar19;
      }
      if (iVar10 <= iVar19) {
        if (iVar19 < (param_1->MGP_bestTraversedPath).total) {
          uVar4 = param_1->MGP_openPaths[1].x;
          (param_1->MGP_bestTraversedPath).total = iVar19;
          (param_1->MGP_bestTraversedPath).x = uVar4;
          (param_1->MGP_bestTraversedPath).y = param_1->MGP_openPaths[1].y;
        }
        param_7 = 1.4013e-45;
        param_1->numberTraversedPathsValue = param_1->numberTraversedPathsValue + 1;
        iVar19 = param_1->numberOpenPathsValue;
        param_1->MGP_openPaths[1].x = param_1->MGP_openPaths[iVar19].x;
        param_1->MGP_openPaths[1].y = param_1->MGP_openPaths[iVar19].y;
        param_1->MGP_openPaths[1].total = param_1->MGP_openPaths[iVar19].total;
        fVar44 = (float)(iVar19 + -1);
        param_1->numberOpenPathsValue = (int)fVar44;
        uVar4 = param_1->MGP_openPaths[1].x;
        uVar5 = param_1->MGP_openPaths[1].y;
        param_3 = (ulong *)CONCAT31(param_3._1_3_,uVar4);
        param_16 = (void *)param_1->MGP_openPaths[1].total;
        param_2 = (ulong *)CONCAT31(param_2._1_3_,uVar5);
        if (1 < (int)fVar44 / 2) {
          do {
            param_15 = (int *)fVar44;
            fVar28 = (float)((int)param_7 * 2);
            if (((int)fVar28 < (int)param_15) &&
               (param_1->MGP_openPaths[(int)param_7 * 2 + 1].total <
                param_1->MGP_openPaths[(int)param_7 * 2].total)) {
              fVar28 = (float)((int)fVar28 + 1);
            }
            if ((int)param_16 < param_1->MGP_openPaths[(int)fVar28].total) break;
            pMVar2 = param_1->MGP_openPaths + (int)fVar28;
            uVar7 = pMVar2->y;
            uVar8 = pMVar2->next;
            pMVar3 = param_1->MGP_openPaths + (int)param_7;
            pMVar3->x = pMVar2->x;
            pMVar3->y = uVar7;
            pMVar3->next = uVar8;
            param_1->MGP_openPaths[(int)param_7].total = param_1->MGP_openPaths[(int)fVar28].total;
            param_15 = (int *)param_1->numberOpenPathsValue;
            param_7 = fVar28;
            fVar44 = (float)param_15;
          } while ((int)fVar28 < (int)param_15 / 2);
        }
        if (param_7 != 1.4013e-45) {
          param_1->MGP_openPaths[(int)param_7].x = uVar4;
          param_1->MGP_openPaths[(int)param_7].y = uVar5;
          param_1->MGP_openPaths[(int)param_7].total = (int)param_16;
        }
        uStack_28 = 0;
        uStack_3c = 1;
        uStack_78 = uVar36;
LAB_0046c153:
        switch(uStack_28) {
        case 0:
          uVar36 = uVar36 - param_14;
          pvStack_74 = (void *)((int)pvStack_74 - param_14);
          uStack_78 = uVar36;
          break;
        case 1:
        case 2:
          uVar36 = uVar36 + param_14;
          uStack_78 = uVar36;
          break;
        case 3:
          iVar19 = param_14;
          goto LAB_0046c1a0;
        case 4:
          pvStack_74 = (void *)((int)pvStack_74 + param_14);
          break;
        case 5:
        case 6:
          uVar36 = uVar36 - param_14;
          uStack_78 = uVar36;
          break;
        case 7:
          iVar19 = -param_14;
LAB_0046c1a0:
          pvStack_74 = (void *)((int)pvStack_74 + iVar19);
        }
        bVar35 = param_1->facetValue[uVar9][(int)pvVar21];
        if ((bVar35 & 0xf8) == param_1->CurrentFacetMask) {
          uVar22 = bVar35 & 7;
        }
        else {
          uVar22 = 8;
        }
        if ((((((uint)(&FacetSkipMask)[uVar22] & uStack_3c) != 0) || ((int)uVar36 < 0)) ||
            ((int)pvStack_74 < 0)) ||
           (((param_1->xSizeValue <= (int)uVar36 || (param_1->ySizeValue <= (int)pvStack_74)) ||
            ((uVar36 == (param_1->initialTile).x && (pvStack_74 == (void *)(param_1->initialTile).y)
             ))))) goto LAB_0046ca94;
        param_3 = (ulong *)(((int)pvStack_74 - (int)pvVar21) * ((int)pvStack_74 - (int)pvVar21));
        param_2 = (ulong *)__ftol();
        iVar19 = param_1->MGP_costValue[uVar9][(int)pvVar21];
        uVar36 = param_4;
        uVar22 = uVar9;
        if ((int)param_4 < (int)uVar9) {
          uVar36 = uVar9;
          uVar22 = param_4;
        }
        pvVar33 = pvVar21;
        pvVar39 = param_5;
        if ((int)param_5 < (int)pvVar21) {
          pvVar33 = param_5;
          pvVar39 = pvVar21;
        }
        uVar36 = uVar36 - uVar22;
        uVar22 = (int)pvVar39 - (int)pvVar33;
        if ((int)uVar36 < (int)uVar22) {
          iVar20 = uVar22 - uVar36;
        }
        else {
          iVar20 = uVar36 - uVar22;
          uVar36 = uVar22;
        }
        uVar22 = param_4;
        uVar38 = uStack_78;
        if ((int)param_4 < (int)uStack_78) {
          uVar22 = uStack_78;
          uVar38 = param_4;
        }
        pvVar33 = pvStack_74;
        pvVar39 = param_5;
        if ((int)param_5 < (int)pvStack_74) {
          pvVar33 = param_5;
          pvVar39 = pvStack_74;
        }
        uVar22 = uVar22 - uVar38;
        uVar38 = (int)pvVar39 - (int)pvVar33;
        if ((int)uVar22 < (int)uVar38) {
          iVar23 = uVar38 - uVar22;
        }
        else {
          iVar23 = uVar22 - uVar38;
          uVar22 = uVar38;
        }
        iVar20 = (int)(&DiagionalDistance)[uVar22 & 0xff] +
                 iVar19 + (iVar23 * 0x10 - (int)((&DiagionalDistance)[uVar36 & 0xff] + iVar20 * 4))
                 + (int)param_2;
        puVar11 = param_1->facetValue[uStack_78] + (int)pvStack_74;
        bVar35 = *puVar11;
        param_3._1_3_ = (undefined3)((uint)iVar19 >> 8);
        param_3 = (ulong *)CONCAT31(param_3._1_3_,bVar35);
        if ((bVar35 & 0xf8) == param_1->CurrentFacetMask) {
          bVar35 = bVar35 & 7;
        }
        else {
          bVar35 = 0xff;
        }
        uVar36 = uStack_78;
        if ((bVar35 < 8) && (param_1->MGP_costValue[uStack_78][(int)pvStack_74] <= iVar20))
        goto LAB_0046ca94;
        pvVar33 = pvVar21;
        pvVar39 = pvStack_74;
        uVar38 = uStack_78;
        uVar22 = uVar9;
        switch(uStack_28) {
        case 0:
          uVar34 = iVar27 + uStack_78;
          pvVar24 = (void *)((int)pvStack_74 + iVar15);
          param_2 = (ulong *)((int)param_8 + uStack_78 * 4);
          break;
        case 1:
          pvVar24 = (void *)((int)pvStack_74 + iVar15);
          uVar34 = iVar27 + uVar9;
          param_2 = (ulong *)((int)param_8 + uVar9 * 4);
          break;
        case 2:
          goto LAB_0046c3ef;
        case 3:
          pvVar39 = pvVar21;
LAB_0046c3ef:
          param_15 = (int *)(iVar16 + (int)pvVar21);
          param_2 = (ulong *)((int)param_8 + uVar9 * 4);
          pvVar24 = (void *)(iVar15 + (int)pvVar39);
          uVar34 = iVar27 + uVar9;
          uVar29 = uStack_78 + iVar14;
          param_7 = (float)(param_12 + (int)pvVar39 * 4);
          param_3 = (ulong *)(iVar17 + uStack_78 * 4);
          goto LAB_0046c51b;
        case 4:
          uVar34 = iVar27 + uVar9;
          pvVar24 = (void *)(iVar15 + (int)pvVar21);
          uVar29 = uStack_78 + iVar14;
          param_15 = (int *)(iVar16 + (int)pvStack_74);
          goto LAB_0046c50f;
        case 5:
          goto LAB_0046c489;
        case 6:
          uVar22 = uStack_78;
LAB_0046c489:
          param_15 = (int *)(iVar16 + (int)pvStack_74);
          pvVar24 = (void *)(iVar15 + (int)pvVar21);
          uVar29 = iVar14 + uVar9;
          uVar34 = iVar27 + uVar22;
          uVar38 = uVar9;
          goto LAB_0046c50f;
        case 7:
          uVar34 = iVar27 + uStack_78;
          pvVar24 = (void *)(iVar15 + (int)pvVar21);
          param_2 = (ulong *)((int)param_8 + uStack_78 * 4);
          pvVar39 = pvVar21;
          break;
        default:
          param_15 = (int *)pvStack_74;
          pvVar24 = pvStack_74;
          uVar29 = uStack_78;
          uVar34 = uStack_78;
          uVar22 = uStack_78;
          pvVar33 = pvStack_74;
LAB_0046c50f:
          param_7 = (float)(param_12 + (int)pvVar33 * 4);
          param_2 = (ulong *)((int)param_8 + uVar22 * 4);
          param_3 = (ulong *)(iVar17 + uVar38 * 4);
          pvVar33 = pvStack_74;
          goto LAB_0046c51b;
        }
        param_15 = (int *)(iVar16 + (int)pvVar21);
        uVar29 = iVar14 + uVar9;
        param_7 = (float)(param_12 + (int)pvVar39 * 4);
        param_3 = (ulong *)(iVar17 + uVar9 * 4);
LAB_0046c51b:
        param_16 = (void *)((-400 - iVar18) + (int)pvVar33 * 4);
        if ((int)uVar34 < 0) {
          uVar34 = uVar34 + 1;
        }
        if ((int)pvVar24 < 0) {
          pvVar24 = (void *)((int)pvVar24 + 1);
        }
        if ((int)param_2 < 0) {
          param_2 = (ulong *)((int)param_2 + 1);
        }
        if ((int)param_7 < 0) {
          param_7 = (float)((int)param_7 + 1);
        }
        pRVar32 = param_1->mapValue;
        if (((int)(uVar29 & 0xff) < pRVar32->map_width) &&
           ((int)((uint)param_15 & 0xff) < pRVar32->map_height)) {
          uStack_34 = (uint)pvVar24 & 0xff;
          if ((byte)pvVar24 <= (byte)param_15) {
            do {
              uStack_30 = uVar34 & 0xff;
              if ((byte)uVar34 <= (byte)uVar29) {
                pbVar40 = &pRVar32->map_row_offset[uStack_34][uVar34 & 0xff].field_0x6;
                do {
                  if (((param_1->initialTile).x != uStack_30) ||
                     ((param_1->initialTile).y != uStack_34)) {
                    uVar22 = pbVar40[-1] & 0x1f;
                    if (((uVar22 != param_1->currentTerrainException1) &&
                        ((uVar22 != param_1->currentTerrainException2 &&
                         (param_1->currentTerrainTable[uVar22] <= (float)_DAT_00570e80)))) &&
                       (((*pbVar40 & 0xf) == 0 ||
                        (param_1->currentTerrainTable
                         [param_1->mapValue->border_types[*pbVar40 & 0xf].underlay_terrain] <=
                         (float)_DAT_00570e80)))) goto LAB_0046c674;
                  }
                  pbVar40 = pbVar40 + 0x18;
                  bVar35 = (char)uStack_30 + 1;
                  uStack_30 = (uint)bVar35;
                } while (bVar35 <= (byte)uVar29);
              }
              bVar35 = (char)uStack_34 + 1;
              uStack_34 = (uint)bVar35;
            } while (bVar35 <= (byte)param_15);
          }
          fStack_24 = 1.4013e-45;
        }
        else {
LAB_0046c674:
          fStack_24 = 3.5593e-43;
        }
        param_15 = (int *)fStack_24;
        if ((fStack_24 == 1.4013e-45) && (param_13 == 1)) {
          bVar6 = false;
          iVar19 = (int)param_16 + (-1 - (int)param_7);
          if (iVar19 < 0) {
            param_15 = (int *)0x1;
          }
          else if ((iVar19 < 0x18) &&
                  (((((param_1->maxTarget).x < (int)param_2 ||
                     ((param_1->maxTarget).y < (int)param_7)) ||
                    ((int)param_3 < (param_1->minTarget).x)) ||
                   ((int)param_16 < (param_1->minTarget).y)))) {
            iVar19 = ((uint)param_7 & 3) + iVar19 * 4;
            puVar30 = (&ObstructionMasks)[iVar19 * 2];
            uVar22 = *(uint *)((int)&DAT_00584f24 + iVar19 * 8);
            if (uVar22 == 0) {
              if ((int)param_2 < (int)param_3) {
                puVar25 = param_1->obstructionValue[(int)param_2] + ((int)param_7 >> 2);
                do {
                  if ((*(uint *)puVar25 & (uint)puVar30) != 0) goto LAB_0046c826;
                  param_2 = (ulong *)((int)param_2 + 1);
                  puVar25 = puVar25 + 0xff;
                } while ((int)param_2 < (int)param_3);
              }
            }
            else if ((int)param_2 < (int)param_3) {
              puVar25 = param_1->obstructionValue[(int)param_2] + ((int)param_7 >> 2);
              do {
                if (((*(uint *)puVar25 & (uint)puVar30) != 0) ||
                   ((*(uint *)(puVar25 + 4) & uVar22) != 0)) {
                  param_15 = (int *)0xfe;
                  param_2 = puVar30;
                  goto LAB_0046c83b;
                }
                param_2 = (ulong *)((int)param_2 + 1);
                puVar25 = puVar25 + 0xff;
              } while ((int)param_2 < (int)param_3);
              param_15 = (int *)0x1;
              param_2 = puVar30;
              goto LAB_0046c83b;
            }
            param_15 = (int *)0x1;
            param_2 = puVar30;
          }
          else {
            if ((int)param_2 < (int)param_3) {
              uVar22 = (uint)param_7;
              puVar30 = (ulong *)((int)param_2 * 0xff);
              puVar42 = param_2;
              do {
                for (; param_2 = puVar30, (int)uVar22 < (int)param_16; uVar22 = uVar22 + 1) {
                  if ((*(uchar *)((int)param_2 +
                                 (int)(param_1->obstructionValue[0] + ((int)uVar22 >> 2))) >>
                       (*(byte *)((int)&ObstructionValueShift + (uVar22 & 3)) & 0x1f) & 3) != 0) {
                    puVar30 = param_2;
                    if (((param_1->currentTargetID == -1) || ((int)puVar42 < (param_1->minTarget).x)
                        ) || (((param_1->maxTarget).x < (int)puVar42 ||
                              (((int)uVar22 < (param_1->minTarget).y ||
                               ((param_1->maxTarget).y < (int)uVar22)))))) goto LAB_0046c826;
                    bVar6 = true;
                  }
                  puVar30 = param_2;
                }
                puVar42 = (ulong *)((int)puVar42 + 1);
                param_2 = (ulong *)((int)param_2 + 0xff);
                uVar22 = (uint)param_7;
                puVar30 = param_2;
              } while ((int)puVar42 < (int)param_3);
            }
            param_15 = (int *)(uint)!bVar6;
          }
        }
        goto LAB_0046c83b;
      }
      if ((param_9 == 1) && (iVar10 = PathingSystem::copyPath(param_1,param_14), iVar10 == 0)) {
        pPVar31 = &param_6->pathValue;
        if (param_6->storePathInExceptionPath != '\0') {
          pPVar31 = &param_6->exceptionPathValue;
        }
        Path::killPath(pPVar31);
        pRVar37 = param_1->currentObject;
        param_14 = 0;
        if (0 < pRVar37->_padding_) {
          do {
            iVar10 = param_14;
            if ((pRVar37->_padding_ + -1 < param_14) &&
               (param_5 = operator_new(param_14 * 4 + 4), param_5 != (void *)0x0)) {
              iVar27 = 0;
              if (0 < pRVar37->_padding_) {
                do {
                  if (iVar10 + 1 <= iVar27) break;
                  *(undefined4 *)((int)param_5 + iVar27 * 4) =
                       *(undefined4 *)(pRVar37->_padding_ + iVar27 * 4);
                  iVar27 = iVar27 + 1;
                  iVar10 = param_14;
                } while (iVar27 < pRVar37->_padding_);
              }
              operator_delete((void *)pRVar37->_padding_);
              pRVar37->_padding_ = (int)param_5;
              pRVar37->_padding_ = iVar10 + 1;
            }
            pRVar13 = RGE_Game_World::object
                                (param_1->worldValue,*(int *)(pRVar37->_padding_ + iVar10 * 4));
            if ((((pRVar13 != (RGE_Static_Object *)0x0) &&
                 (pRVar13->id != param_1->currentObject->_padding_)) &&
                (pRVar13->lastInObstructionMapValue == '\x01')) &&
               (pRVar13->inside_obj == (RGE_Static_Object *)0x0)) {
              RGE_Static_Object::addToObstructionMap(pRVar13,param_1->aiPS);
            }
            pRVar37 = param_1->currentObject;
            param_14 = iVar10 + 1;
          } while (param_14 < pRVar37->_padding_);
        }
        goto LAB_0046d19f;
      }
      if (param_10 != (float *)0x0) {
        *param_10 = (float)param_1->MGP_costValue[uVar9][(int)pvVar21];
      }
      pRVar37 = param_1->currentObject;
      param_14 = 0;
      if (0 < pRVar37->_padding_) {
        do {
          iVar10 = param_14;
          if ((pRVar37->_padding_ + -1 < param_14) &&
             (param_5 = operator_new(param_14 * 4 + 4), param_5 != (void *)0x0)) {
            iVar27 = 0;
            if (0 < pRVar37->_padding_) {
              do {
                if (iVar10 + 1 <= iVar27) break;
                *(undefined4 *)((int)param_5 + iVar27 * 4) =
                     *(undefined4 *)(pRVar37->_padding_ + iVar27 * 4);
                iVar27 = iVar27 + 1;
                iVar10 = param_14;
              } while (iVar27 < pRVar37->_padding_);
            }
            operator_delete((void *)pRVar37->_padding_);
            pRVar37->_padding_ = (int)param_5;
            pRVar37->_padding_ = iVar10 + 1;
          }
          pRVar13 = RGE_Game_World::object
                              (param_1->worldValue,*(int *)(pRVar37->_padding_ + iVar10 * 4));
          if ((((pRVar13 != (RGE_Static_Object *)0x0) &&
               (pRVar13->id != param_1->currentObject->_padding_)) &&
              (pRVar13->lastInObstructionMapValue == '\x01')) &&
             (pRVar13->inside_obj == (RGE_Static_Object *)0x0)) {
            RGE_Static_Object::addToObstructionMap(pRVar13,param_1->aiPS);
          }
          pRVar37 = param_1->currentObject;
          param_14 = iVar10 + 1;
        } while (param_14 < pRVar37->_padding_);
      }
      goto LAB_0046ceaf;
    }
  }
LAB_0046cedf:
  iVar10 = param_1->numberOpenPathsValue;
  param_1->numberOpenPathsValue = iVar10 + 1;
  param_1->MGP_openPaths[iVar10 + 1].x = (param_1->MGP_bestTraversedPath).x;
  param_1->MGP_openPaths[param_1->numberOpenPathsValue].y = (param_1->MGP_bestTraversedPath).y;
  param_1->MGP_openPaths[param_1->numberOpenPathsValue].total = 0;
  iVar10 = param_1->numberOpenPathsValue;
  if (0 < iVar10) {
    uVar4 = param_1->MGP_openPaths[iVar10].x;
    uVar5 = param_1->MGP_openPaths[iVar10].y;
    iVar15 = iVar10 / 2;
    param_5 = (void *)CONCAT31(param_5._1_3_,uVar4);
    param_4 = CONCAT31(param_4._1_3_,uVar5);
    param_3 = (ulong *)param_1->MGP_openPaths[iVar10].total;
    iVar27 = param_1->MGP_openPaths[iVar15].total;
    iVar14 = iVar10;
    while ((int)param_3 < iVar27) {
      pMVar2 = param_1->MGP_openPaths + iVar15;
      uVar7 = pMVar2->y;
      uVar8 = pMVar2->next;
      pMVar3 = param_1->MGP_openPaths + iVar14;
      pMVar3->x = pMVar2->x;
      pMVar3->y = uVar7;
      pMVar3->next = uVar8;
      param_1->MGP_openPaths[iVar14].total = param_1->MGP_openPaths[iVar15].total;
      iVar14 = iVar14 / 2;
      iVar15 = iVar15 / 2;
      iVar27 = param_1->MGP_openPaths[iVar15].total;
    }
    if (iVar14 != iVar10) {
      param_1->MGP_openPaths[iVar14].x = uVar4;
      param_1->MGP_openPaths[iVar14].y = uVar5;
      param_1->MGP_openPaths[iVar14].total = (int)param_3;
    }
  }
  if ((param_9 == 1) && (iVar10 = PathingSystem::copyPath(param_1,param_14), iVar10 == 0)) {
    pPVar31 = &param_6->pathValue;
    if (param_6->storePathInExceptionPath != '\0') {
      pPVar31 = &param_6->exceptionPathValue;
    }
    Path::killPath(pPVar31);
    pRVar37 = param_1->currentObject;
    param_14 = 0;
    if (0 < pRVar37->_padding_) {
      do {
        iVar10 = param_14;
        if ((pRVar37->_padding_ + -1 < param_14) &&
           (param_5 = operator_new(param_14 * 4 + 4), param_5 != (void *)0x0)) {
          iVar27 = 0;
          if (0 < pRVar37->_padding_) {
            do {
              if (iVar10 + 1 <= iVar27) break;
              *(undefined4 *)((int)param_5 + iVar27 * 4) =
                   *(undefined4 *)(pRVar37->_padding_ + iVar27 * 4);
              iVar27 = iVar27 + 1;
              iVar10 = param_14;
            } while (iVar27 < pRVar37->_padding_);
          }
          operator_delete((void *)pRVar37->_padding_);
          pRVar37->_padding_ = (int)param_5;
          pRVar37->_padding_ = iVar10 + 1;
        }
        pRVar13 = RGE_Game_World::object
                            (param_1->worldValue,*(int *)(pRVar37->_padding_ + iVar10 * 4));
        if (((pRVar13 != (RGE_Static_Object *)0x0) &&
            (pRVar13->id != param_1->currentObject->_padding_)) &&
           ((pRVar13->lastInObstructionMapValue == '\x01' &&
            (pRVar13->inside_obj == (RGE_Static_Object *)0x0)))) {
          RGE_Static_Object::addToObstructionMap(pRVar13,param_1->aiPS);
        }
        pRVar37 = param_1->currentObject;
        param_14 = iVar10 + 1;
      } while (param_14 < pRVar37->_padding_);
    }
  }
  else {
    if (param_10 != (float *)0x0) {
      *param_10 = (float)(param_1->MGP_bestTraversedPath).total;
    }
    pRVar37 = param_1->currentObject;
    param_14 = 0;
    if (0 < pRVar37->_padding_) {
      do {
        iVar10 = param_14;
        if ((pRVar37->_padding_ + -1 < param_14) &&
           (param_5 = operator_new(param_14 * 4 + 4), param_5 != (void *)0x0)) {
          iVar27 = 0;
          if (0 < pRVar37->_padding_) {
            do {
              if (iVar10 + 1 <= iVar27) break;
              *(undefined4 *)((int)param_5 + iVar27 * 4) =
                   *(undefined4 *)(pRVar37->_padding_ + iVar27 * 4);
              iVar27 = iVar27 + 1;
              iVar10 = param_14;
            } while (iVar27 < pRVar37->_padding_);
          }
          operator_delete((void *)pRVar37->_padding_);
          pRVar37->_padding_ = (int)param_5;
          pRVar37->_padding_ = iVar10 + 1;
        }
        pRVar13 = RGE_Game_World::object
                            (param_1->worldValue,*(int *)(pRVar37->_padding_ + iVar10 * 4));
        if ((((pRVar13 != (RGE_Static_Object *)0x0) &&
             (pRVar13->id != param_1->currentObject->_padding_)) &&
            (pRVar13->lastInObstructionMapValue == '\x01')) &&
           (pRVar13->inside_obj == (RGE_Static_Object *)0x0)) {
          RGE_Static_Object::addToObstructionMap(pRVar13,param_1->aiPS);
        }
        pRVar37 = param_1->currentObject;
        param_14 = iVar10 + 1;
      } while (param_14 < pRVar37->_padding_);
    }
  }
  goto LAB_0046d19f;
LAB_0046c826:
  param_2 = puVar30;
  param_15 = (int *)0xfe;
LAB_0046c83b:
  param_7 = 0.0;
  fStack_4c = 0.0;
  if (param_15 == (int *)0xfe) {
    if (param_1->currentUnobstructibleGroupID == -1) goto LAB_0046ca94;
    iVar19 = uStack_78 - 1;
    if (iVar19 < 0) {
      iVar19 = 0;
    }
    puVar30 = (ulong *)0x0;
    param_3 = (ulong *)0x0;
    while (((iVar19 <= (int)(uStack_78 + 1) && (iVar19 < param_1->xSizeValue)) &&
           (puVar30 == (ulong *)0x0))) {
      iVar23 = (int)pvStack_74 - 1;
      if (iVar23 < 0) {
        iVar23 = 0;
      }
      param_16 = (void *)((int)pvStack_74 + 1);
      if (iVar23 <= (int)param_16) {
        do {
          if ((param_1->ySizeValue <= iVar23) || (puVar30 != (ulong *)0x0)) break;
          param_2 = puVar30;
          iVar26 = RGE_Game_World::objectGroupOnTile
                             (param_1->worldValue,param_1->currentUnobstructiblePlayerID,
                              param_1->currentUnobstructibleGroupID,iVar19,iVar23,(int *)&param_2);
          if (iVar26 == -1) {
            if (0 < (int)param_2) {
              param_3 = (ulong *)0x1;
            }
          }
          else {
            pRVar13 = RGE_Game_World::object(param_1->worldValue,iVar26);
            if (pRVar13 != (RGE_Static_Object *)0x0) {
              fStack_4c = pRVar13->hp;
              param_7 = 1.4013e-45;
            }
          }
          iVar23 = iVar23 + 1;
          puVar30 = param_3;
        } while (iVar23 <= (int)param_16);
      }
      iVar19 = iVar19 + 1;
    }
    if (puVar30 == (ulong *)0x1) goto LAB_0046ca94;
  }
  iVar20 = iVar20 + (uint)param_1->miscValue[uStack_78][(int)pvStack_74] * 0x10;
  if (param_7 == 1.4013e-45) {
    if (fStack_4c < _DAT_00570e88) {
      iVar20 = iVar20 + 0x10;
    }
    else {
      iVar20 = iVar20 + 0x3c;
    }
  }
  bVar35 = param_1->facetValue[uVar9][(int)pvVar21];
  if ((bVar35 & 0xf8) == param_1->CurrentFacetMask) {
    uStack_50 = bVar35 & 0xffffff07;
  }
  else {
    uStack_50 = 0xff;
  }
  if (uStack_28 != uStack_50) {
    iVar20 = iVar20 + 1;
  }
  if (param_15 == (int *)0x0) {
    iVar20 = 0;
  }
  param_1->MGP_costValue[uStack_78][(int)pvStack_74] = iVar20;
  *puVar11 = (byte)uStack_28 & 7 | param_1->CurrentFacetMask;
  iVar19 = param_1->numberOpenPathsValue;
  param_1->numberOpenPathsValue = iVar19 + 1;
  param_1->MGP_openPaths[iVar19 + 1].x = (uchar)uStack_78;
  param_1->MGP_openPaths[param_1->numberOpenPathsValue].y = (uchar)pvStack_74;
  param_1->MGP_openPaths[param_1->numberOpenPathsValue].total = iVar20;
  iVar19 = param_1->numberOpenPathsValue;
  if (0 < iVar19) {
    uVar4 = param_1->MGP_openPaths[iVar19].x;
    uVar5 = param_1->MGP_openPaths[iVar19].y;
    iVar26 = iVar19 / 2;
    param_3 = (ulong *)CONCAT31(param_3._1_3_,uVar4);
    param_2 = (ulong *)CONCAT31(param_2._1_3_,uVar5);
    param_7 = (float)param_1->MGP_openPaths[iVar19].total;
    iVar20 = param_1->MGP_openPaths[iVar26].total;
    iVar23 = iVar19;
    while ((int)param_7 < iVar20) {
      pMVar2 = param_1->MGP_openPaths + iVar26;
      uVar7 = pMVar2->y;
      uVar8 = pMVar2->next;
      pMVar3 = param_1->MGP_openPaths + iVar23;
      pMVar3->x = pMVar2->x;
      pMVar3->y = uVar7;
      pMVar3->next = uVar8;
      param_1->MGP_openPaths[iVar23].total = param_1->MGP_openPaths[iVar26].total;
      iVar23 = iVar23 / 2;
      iVar26 = iVar26 / 2;
      iVar20 = param_1->MGP_openPaths[iVar26].total;
    }
    if (iVar23 != iVar19) {
      param_1->MGP_openPaths[iVar23].x = uVar4;
      param_1->MGP_openPaths[iVar23].y = uVar5;
      param_1->MGP_openPaths[iVar23].total = (int)param_7;
    }
  }
  if (param_15 == (int *)0x0) {
    if ((param_9 == 1) && (iVar10 = PathingSystem::copyPath(param_1,param_14), iVar10 == 0)) {
      pPVar31 = &param_6->pathValue;
      if (param_6->storePathInExceptionPath != '\0') {
        pPVar31 = &param_6->exceptionPathValue;
      }
      Path::killPath(pPVar31);
      pRVar37 = param_1->currentObject;
      param_14 = 0;
      if (0 < pRVar37->_padding_) goto LAB_0046cd11;
      goto LAB_0046d19f;
    }
    if (param_10 != (float *)0x0) {
      *param_10 = (float)param_1->MGP_costValue[uVar9][(int)pvVar21];
    }
    pRVar37 = param_1->currentObject;
    param_14 = 0;
    if (0 < pRVar37->_padding_) goto LAB_0046cdfd;
    goto LAB_0046ceaf;
  }
LAB_0046ca94:
  uStack_28 = uStack_28 + 1;
  uStack_3c = uStack_3c << 1;
  if (7 < (int)uStack_28) goto code_r0x0046caa9;
  goto LAB_0046c153;
code_r0x0046caa9:
  iStack_2c = iStack_2c + 1;
  param_1->startOfPath = 0;
  if (param_1->numberOpenPathsValue < 1) goto LAB_0046cedf;
  goto LAB_0046bf0e;
  while( true ) {
    pRVar13 = RGE_Game_World::object(param_1->worldValue,*(int *)(pRVar37->_padding_ + iVar10 * 4));
    if ((((pRVar13 != (RGE_Static_Object *)0x0) &&
         (pRVar13->id != param_1->currentObject->_padding_)) &&
        (pRVar13->lastInObstructionMapValue == '\x01')) &&
       (pRVar13->inside_obj == (RGE_Static_Object *)0x0)) {
      RGE_Static_Object::addToObstructionMap(pRVar13,param_1->aiPS);
    }
    pRVar37 = param_1->currentObject;
    param_14 = iVar10 + 1;
    if (pRVar37->_padding_ <= param_14) break;
LAB_0046cdfd:
    iVar10 = param_14;
    if ((pRVar37->_padding_ + -1 < param_14) &&
       (param_5 = operator_new(param_14 * 4 + 4), param_5 != (void *)0x0)) {
      iVar27 = 0;
      if (0 < pRVar37->_padding_) {
        do {
          if (iVar10 + 1 <= iVar27) break;
          *(undefined4 *)((int)param_5 + iVar27 * 4) =
               *(undefined4 *)(pRVar37->_padding_ + iVar27 * 4);
          iVar27 = iVar27 + 1;
          iVar10 = param_14;
        } while (iVar27 < pRVar37->_padding_);
      }
      operator_delete((void *)pRVar37->_padding_);
      pRVar37->_padding_ = (int)param_5;
      pRVar37->_padding_ = iVar10 + 1;
    }
  }
LAB_0046ceaf:
  if ((param_1->currentObjectInObMap == 1) &&
     ((RGE_Static_Object *)param_1->currentObject->_padding_ == (RGE_Static_Object *)0x0)) {
    RGE_Static_Object::addToObstructionMap
              ((RGE_Static_Object *)param_1->currentObject,param_1->aiPS);
  }
  return 1;
  while( true ) {
    pRVar13 = RGE_Game_World::object(param_1->worldValue,*(int *)(pRVar37->_padding_ + iVar10 * 4));
    if (((pRVar13 != (RGE_Static_Object *)0x0) && (pRVar13->id != param_1->currentObject->_padding_)
        ) && ((pRVar13->lastInObstructionMapValue == '\x01' &&
              (pRVar13->inside_obj == (RGE_Static_Object *)0x0)))) {
      RGE_Static_Object::addToObstructionMap(pRVar13,param_1->aiPS);
    }
    pRVar37 = param_1->currentObject;
    param_14 = iVar10 + 1;
    if (pRVar37->_padding_ <= param_14) break;
LAB_0046cd11:
    iVar10 = param_14;
    if ((pRVar37->_padding_ + -1 < param_14) &&
       (param_5 = operator_new(param_14 * 4 + 4), param_5 != (void *)0x0)) {
      iVar27 = 0;
      if (0 < pRVar37->_padding_) {
        do {
          if (iVar10 + 1 <= iVar27) break;
          *(undefined4 *)((int)param_5 + iVar27 * 4) =
               *(undefined4 *)(pRVar37->_padding_ + iVar27 * 4);
          iVar27 = iVar27 + 1;
          iVar10 = param_14;
        } while (iVar27 < pRVar37->_padding_);
      }
      operator_delete((void *)pRVar37->_padding_);
      pRVar37->_padding_ = (int)param_5;
      pRVar37->_padding_ = iVar10 + 1;
    }
  }
LAB_0046d19f:
  if ((param_1->currentObjectInObMap == 1) &&
     ((RGE_Static_Object *)param_1->currentObject->_padding_ == (RGE_Static_Object *)0x0)) {
    RGE_Static_Object::addToObstructionMap
              ((RGE_Static_Object *)param_1->currentObject,param_1->aiPS);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046d202
// Address: 0046d202
void FUN_0046d202(void)
{
  uint *unaff_ESI;
  
  *unaff_ESI = *unaff_ESI << 0x11 | *unaff_ESI >> 0xf;
  *unaff_ESI = *unaff_ESI << 0x11 | *unaff_ESI >> 0xf;
  *unaff_ESI = *unaff_ESI << 0x19 | *unaff_ESI >> 7;
  *unaff_ESI = *unaff_ESI << 3 | *unaff_ESI >> 0x1d;
  *unaff_ESI = *unaff_ESI << 0x10 | *unaff_ESI >> 0x10;
  *unaff_ESI = *unaff_ESI << 0x10 | *unaff_ESI >> 0x10;
  *unaff_ESI = *unaff_ESI << 0x18 | *unaff_ESI >> 8;
  *unaff_ESI = *unaff_ESI << 0xf | *unaff_ESI >> 0x11;
  return;
}

// --------------------------------------------------

// Function: FUN_0046d257
// Address: 0046d257
void __fastcall FUN_0046d257(int param_1)
{
  *(int *)(param_1 + 0x11dcc0) = *(int *)(param_1 + 0x11dcc0) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0046d267
// Address: 0046d267
void __fastcall FUN_0046d267(int param_1)
{
  *(int *)(param_1 + 0x11dcc4) = *(int *)(param_1 + 0x11dcc4) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0046d277
// Address: 0046d277
// [HELPER] ObstructionValueShift: "06040200"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0046d277(int param_1,RGE_Static_Object *param_2,float param_3,float param_4,int param_5)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  byte *pbVar12;
  uint *puVar13;
  byte bVar14;
  uint uVar15;
  int iVar17;
  uint uStack_1c;
  uint uStack_14;
  uint uVar16;
  
  *(RGE_Static_Object **)(param_1 + 0x11dc44) = param_2;
  *(undefined4 *)(param_1 + 0x11dc50) =
       *(undefined4 *)
        (*(int *)(*(int *)(param_1 + 0x11dc40) + 0x54) + param_2->master_obj->terrain * 4);
  *(undefined4 *)(param_1 + 0x11dc7c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x11dc80) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x11dc94) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x11dc98) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x11dc9c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x11dca0) = 0xffffffff;
  floor((double)param_3);
  floor((double)param_4);
  iVar2 = __ftol();
  iVar3 = __ftol();
  iVar3 = iVar2 * 4 - iVar3;
  iVar17 = iVar3 + -400;
  iVar4 = __ftol();
  iVar5 = __ftol();
  iVar5 = iVar4 * 4 - iVar5;
  uVar6 = iVar5 - 400;
  iVar7 = __ftol();
  iVar7 = (iVar2 * 4 - iVar7) + -400;
  iVar2 = __ftol();
  iVar2 = (iVar4 * 4 - iVar2) + -400;
  if (iVar17 < 0) {
    iVar17 = iVar3 + -399;
  }
  if ((int)uVar6 < 0) {
    uVar6 = iVar5 - 399;
  }
  uVar8 = (int)uVar6 >> 2;
  if (param_5 != 0) {
    uVar11 = iVar7 >> 2;
    uVar15 = iVar17 >> 2;
    bVar10 = (byte)(iVar2 >> 2);
    if (*(int *)(*(int *)(param_1 + 0x11dc3c) + 8) <= (int)(uVar11 & 0xff)) {
      return 0;
    }
    if (*(int *)(*(int *)(param_1 + 0x11dc3c) + 0xc) <= (int)(iVar2 >> 2 & 0xffU)) {
      return 0;
    }
    uStack_1c = uVar8 & 0xff;
    if ((byte)uVar8 <= bVar10) {
      uVar9 = uVar11;
      uVar16 = uVar15;
      do {
        uStack_14 = uVar16 & 0xff;
        if ((byte)uVar16 <= (byte)uVar9) {
          pbVar12 = (byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x11dc3c) + 0x8d8c) +
                                     uStack_1c * 4) + (uVar15 & 0xff) * 0x18 + 6);
          do {
            if ((*(uint *)(param_1 + 0x11dc7c) != uStack_14) ||
               (*(uint *)(param_1 + 0x11dc80) != uStack_1c)) {
              uVar9 = pbVar12[-1] & 0x1f;
              if ((uVar9 != *(uint *)(param_1 + 0x11dc5c)) &&
                 ((uVar9 != *(uint *)(param_1 + 0x11dc60) &&
                  (*(float *)(*(int *)(param_1 + 0x11dc50) + uVar9 * 4) <= (float)_DAT_00570e80))))
{
                if ((*pbVar12 & 0xf) == 0) {
                  return 0;
                }
                if (*(float *)(*(int *)(param_1 + 0x11dc50) +
                              *(short *)((*pbVar12 & 0xf) * 0x5a0 + 0x3928 +
                                        *(int *)(param_1 + 0x11dc3c)) * 4) <= (float)_DAT_00570e80)
{
                  return 0;
                }
              }
            }
            pbVar12 = pbVar12 + 0x18;
            bVar14 = (char)uVar16 + 1;
            uVar16 = (uint)bVar14;
            uStack_14 = (uint)bVar14;
          } while (bVar14 <= (byte)uVar11);
          uVar16 = uVar15 & 0xff;
          uVar9 = uVar11 & 0xff;
        }
        bVar14 = (char)uStack_1c + 1;
        uStack_1c = (uint)bVar14;
      } while (bVar14 <= bVar10);
    }
  }
  iVar3 = RGE_Static_Object::removeFromObstructionMap(param_2,*(int *)(param_1 + 0x11dcf4));
  bVar1 = false;
  iVar4 = (iVar2 - uVar6) + -1;
  if (-1 < iVar4) {
    if ((iVar4 < 0x18) &&
       ((((*(int *)(param_1 + 0x11dc8c) < iVar17 || (*(int *)(param_1 + 0x11dc90) < (int)uVar6)) ||
         (iVar7 < *(int *)(param_1 + 0x11dc84))) || (iVar2 < *(int *)(param_1 + 0x11dc88))))) {
      iVar2 = (uVar6 & 3) + iVar4 * 4;
      uVar6 = *(uint *)((int)&DAT_00584f24 + iVar2 * 8);
      if (uVar6 == 0) {
        if (iVar17 < iVar7) {
          puVar13 = (uint *)(iVar17 * 0xff + uVar8 + 0xce624 + param_1);
          do {
            if ((*puVar13 & (uint)(&ObstructionMasks)[iVar2 * 2]) != 0) goto LAB_0046d6d7;
            iVar17 = iVar17 + 1;
            puVar13 = (uint *)((int)puVar13 + 0xff);
          } while (iVar17 < iVar7);
        }
      }
      else if (iVar17 < iVar7) {
        puVar13 = (uint *)(iVar17 * 0xff + uVar8 + 0xce624 + param_1);
        do {
          if (((*puVar13 & (uint)(&ObstructionMasks)[iVar2 * 2]) != 0) ||
             ((puVar13[1] & uVar6) != 0)) goto LAB_0046d6d7;
          iVar17 = iVar17 + 1;
          puVar13 = (uint *)((int)puVar13 + 0xff);
        } while (iVar17 < iVar7);
      }
    }
    else {
      if (iVar17 < iVar7) {
        iVar4 = iVar17 * 0xff;
        uVar8 = uVar6;
        do {
          for (; (int)uVar8 < iVar2; uVar8 = uVar8 + 1) {
            if ((*(byte *)(((int)uVar8 >> 2) + param_1 + 0xce624 + iVar4) >>
                 (*(byte *)((int)&ObstructionValueShift + (uVar8 & 3)) & 0x1f) & 3) != 0) {
              if (((*(int *)(param_1 + 0x11dc4c) == -1) || (iVar17 < *(int *)(param_1 + 0x11dc84)))
                 || ((*(int *)(param_1 + 0x11dc8c) < iVar17 ||
                     (((int)uVar8 < *(int *)(param_1 + 0x11dc88) ||
                      (*(int *)(param_1 + 0x11dc90) < (int)uVar8)))))) goto LAB_0046d6d7;
              bVar1 = true;
            }
          }
          iVar17 = iVar17 + 1;
          iVar4 = iVar4 + 0xff;
          uVar8 = uVar6;
        } while (iVar17 < iVar7);
      }
      if (bVar1) {
LAB_0046d6d7:
        if ((iVar3 != 0) && (param_2->inside_obj == (RGE_Static_Object *)0x0)) {
          RGE_Static_Object::addToObstructionMap(param_2,*(int *)(param_1 + 0x11dcf4));
        }
        return 0;
      }
    }
  }
  if ((iVar3 != 0) && (param_2->inside_obj == (RGE_Static_Object *)0x0)) {
    RGE_Static_Object::addToObstructionMap(param_2,*(int *)(param_1 + 0x11dcf4));
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0046d737
// Address: 0046d737
byte __fastcall FUN_0046d737(int param_1)
{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = 0;
  param_1 = param_1 + 0xce624;
  iVar3 = 0x3fc;
  do {
    iVar1 = 0;
    do {
      bVar2 = bVar2 ^ *(byte *)(iVar1 + param_1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0xff);
    param_1 = param_1 + 0xff;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return bVar2;
}

// --------------------------------------------------

// Function: FUN_0046d76f
// Address: 0046d76f
// [HELPER] s_____The_open_paths_: "    The open paths:"
// [HELPER] s_____There_are__d_open_paths_and_: "    There are %d open paths and %d traversed paths."
// [HELPER] s________5d____d___d___total__d__f: "      %5d: (%d, %d), total=%d, facet=%d."
void __thiscall FUN_0046d76f(int param_1,int *param_2)
{
  byte bVar1;
  code *pcVar2;
  byte *pbVar3;
  int iVar4;
  
  pcVar2 = *(code **)(*param_2 + 0x144);
  (*pcVar2)(param_2,s_____There_are__d_open_paths_and_,*(undefined4 *)(param_1 + 0x11dc2c),
            *(undefined4 *)(param_1 + 0x11dc38));
  (*pcVar2)(param_2,s_____The_open_paths_);
  iVar4 = 1;
  if (0 < *(int *)(param_1 + 0x11dc2c)) {
    pbVar3 = (byte *)(param_1 + 0x4f61d);
    do {
      bVar1 = *(byte *)((uint)pbVar3[-1] * 0xff + param_1 + 0xc + (uint)*pbVar3);
      if ((bVar1 & 0xf8) == *(byte *)(param_1 + 0x11dcd8)) {
        bVar1 = bVar1 & 7;
      }
      else {
        bVar1 = 0xff;
      }
      (*pcVar2)(param_2,s________5d____d___d___total__d__f,iVar4,(uint)pbVar3[-1],(uint)*pbVar3,
                *(undefined4 *)(pbVar3 + 3),bVar1);
      iVar4 = iVar4 + 1;
      pbVar3 = pbVar3 + 8;
    } while (iVar4 <= *(int *)(param_1 + 0x11dc2c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046d82e
// Address: 0046d82e
undefined4 __thiscall FUN_0046d82e(int param_1,char param_2)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  Path *pPVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_1c;
  char cStack_18;
  byte bStack_17;
  Waypoint WStack_10;
  
  iVar4 = *(int *)(param_1 + 0x11dc44);
  pPVar8 = (Path *)(iVar4 + 0xa4);
  if (*(char *)(iVar4 + 0x154) != '\0') {
    pPVar8 = (Path *)(iVar4 + 0xd8);
  }
  Path::killPath(pPVar8);
  cStack_18 = *(char *)(param_1 + 0x4f61c);
  bStack_17 = *(byte *)(param_1 + 0x4f61d);
  uVar10 = (uint)bStack_17;
  uVar11 = *(ushort *)(param_1 + 0x4f61c) & 0xff;
  bVar1 = *(byte *)(uVar11 * 0xff + param_1 + 0xc + uVar10);
  if ((bVar1 & 0xf8) == *(byte *)(param_1 + 0x11dcd8)) {
    bVar1 = bVar1 & 7;
  }
  else {
    bVar1 = 0xff;
  }
  iVar4 = *(int *)(param_1 + 0x11dc44);
  WStack_10.x = (float)uVar11 + *(float *)(param_1 + 0x11dc54);
  WStack_10.y = (float)uVar10 + *(float *)(param_1 + 0x11dc58);
  WStack_10.z = *(float *)(iVar4 + 0x40);
  pPVar8 = (Path *)(iVar4 + 0xa4);
  if (*(char *)(iVar4 + 0x154) != '\0') {
    pPVar8 = (Path *)(iVar4 + 0xd8);
  }
  WStack_10.facetToNextWaypoint = bVar1;
  Path::initToStart(pPVar8);
  bVar9 = 0xff;
  do {
    if ((*(uint *)(param_1 + 0x11dc7c) == uVar11) && (*(uint *)(param_1 + 0x11dc80) == uVar10)) {
      iVar4 = *(int *)(param_1 + 0x11dc44);
      if (*(char *)(iVar4 + 0x154) == '\0') {
        iVar4 = Path::insertAtCurrent((Path *)(iVar4 + 0xa4),&WStack_10);
        if (iVar4 == 0) {
          return 0;
        }
      }
      else {
        iVar4 = Path::insertAtCurrent((Path *)(iVar4 + 0xd8),&WStack_10);
        if (iVar4 == 0) {
          return 0;
        }
      }
      return 1;
    }
    if (bVar1 != bVar9) {
      iVar4 = *(int *)(param_1 + 0x11dc44);
      if (*(char *)(iVar4 + 0x154) == '\0') {
        iVar4 = Path::insertAtCurrent((Path *)(iVar4 + 0xa4),&WStack_10);
      }
      else {
        iVar4 = Path::insertAtCurrent((Path *)(iVar4 + 0xd8),&WStack_10);
      }
      if (iVar4 == 0) {
        return 0;
      }
    }
    if (*(int *)(param_1 + 0x11dcdc) != -1) {
      iVar4 = uVar11 - 1;
      iStack_2c = uVar11 + 1;
      if (iVar4 < 0) {
        iVar4 = 0;
        iStack_2c = uVar11 + 2;
      }
      else if (*(int *)(param_1 + 4) <= iStack_2c) {
        iVar4 = uVar11 - 2;
        iStack_2c = *(int *)(param_1 + 4) + -1;
      }
      iStack_28 = uVar10 - 1;
      iStack_30 = uVar10 + 1;
      if (iStack_28 < 0) {
        iStack_30 = uVar10 + 2;
        iStack_28 = 0;
      }
      else if (*(int *)(param_1 + 8) <= iStack_30) {
        iStack_28 = uVar10 - 2;
        iStack_30 = *(int *)(param_1 + 8) + -1;
      }
      for (; iVar3 = iStack_28, iVar4 <= iStack_2c; iVar4 = iVar4 + 1) {
        for (; iVar3 <= iStack_30; iVar3 = iVar3 + 1) {
          iStack_1c = 0;
          iVar5 = RGE_Game_World::objectGroupOnTile
                            (*(RGE_Game_World **)(param_1 + 0x11dc40),*(int *)(param_1 + 0x11dce0),
                             *(int *)(param_1 + 0x11dcdc),iVar4,iVar3,&iStack_1c);
          if (iVar5 != -1) {
            iVar2 = *(int *)(param_1 + 0x11dce8);
            iVar6 = 0;
            if (0 < iVar2) {
              do {
                if (*(int *)(param_1 + 0x11dcf0) <= iVar6) break;
                if (*(int *)(*(int *)(param_1 + 0x11dce4) + iVar6 * 4) == iVar5) goto LAB_0046dacf;
                iVar6 = iVar6 + 1;
              } while (iVar6 < iVar2);
            }
            if (*(int *)(param_1 + 0x11dcf0) + -1 < iVar2) {
              iVar2 = iVar2 + 1;
              pvVar7 = operator_new(iVar2 * 4);
              if (pvVar7 != (void *)0x0) {
                iVar6 = 0;
                if (0 < *(int *)(param_1 + 0x11dcf0)) {
                  do {
                    if (iVar2 <= iVar6) break;
                    iVar6 = iVar6 + 1;
                    *(undefined4 *)((int)pvVar7 + iVar6 * 4 + -4) =
                         *(undefined4 *)(*(int *)(param_1 + 0x11dce4) + -4 + iVar6 * 4);
                  } while (iVar6 < *(int *)(param_1 + 0x11dcf0));
                }
                operator_delete(*(void **)(param_1 + 0x11dce4));
                *(void **)(param_1 + 0x11dce4) = pvVar7;
                *(int *)(param_1 + 0x11dcf0) = iVar2;
              }
            }
            *(int *)(*(int *)(param_1 + 0x11dce4) + *(int *)(param_1 + 0x11dce8) * 4) = iVar5;
            *(int *)(param_1 + 0x11dce8) = *(int *)(param_1 + 0x11dce8) + 1;
          }
LAB_0046dacf:
        }
      }
    }
    switch(bVar1) {
    case 0:
      cStack_18 = cStack_18 + param_2;
      bStack_17 = bStack_17 + param_2;
      break;
    case 1:
      bStack_17 = bStack_17 + param_2;
      break;
    case 2:
      cStack_18 = cStack_18 - param_2;
      bStack_17 = bStack_17 + param_2;
      break;
    case 3:
      cStack_18 = cStack_18 - param_2;
      break;
    case 4:
      cStack_18 = cStack_18 - param_2;
      bStack_17 = bStack_17 - param_2;
      break;
    case 5:
      bStack_17 = bStack_17 - param_2;
      break;
    case 6:
      cStack_18 = cStack_18 + param_2;
      bStack_17 = bStack_17 - param_2;
      break;
    case 7:
      cStack_18 = cStack_18 + param_2;
    }
    uVar10 = (uint)bStack_17;
    uVar11 = CONCAT11(bStack_17,cStack_18) & 0xff;
    WStack_10.facetToNextWaypoint = *(byte *)(uVar11 * 0xff + param_1 + 0xc + uVar10);
    if ((WStack_10.facetToNextWaypoint & 0xf8) == *(byte *)(param_1 + 0x11dcd8)) {
      WStack_10.facetToNextWaypoint = WStack_10.facetToNextWaypoint & 7;
    }
    else {
      WStack_10.facetToNextWaypoint = 0xff;
    }
    WStack_10.x = (float)uVar11 + *(float *)(param_1 + 0x11dc54);
    WStack_10.y = (float)uVar10 + *(float *)(param_1 + 0x11dc58);
    bVar9 = bVar1;
    bVar1 = WStack_10.facetToNextWaypoint;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0046dc8a
// Address: 0046dc8a
int __fastcall FUN_0046dc8a(int param_1)
{
  int iVar1;
  int in_EAX;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  int iVar5;
  undefined2 in_CS;
  int *piStack_4;
  
  piStack_4 = (int *)CONCAT22(piStack_4._2_2_,in_CS);
  if (cRam00000000 != '\0' && SCARRY1(cRam00000000,'\0') == cRam00000000 < '\0') {
    *(undefined1 *)(unaff_EDI + 0x5e) = *(undefined1 *)(unaff_EDI + 0x5e);
    return 0;
  }
  *(char *)(unaff_EDI + -0x56ffb925) = *(char *)(unaff_EDI + -0x56ffb925) + (char)param_1;
  iVar5 = *(int *)(param_1 + 0x11dce8);
  do {
    if (iVar5 < 0) {
      return in_EAX;
    }
    if (*(int *)(param_1 + 0x11dcf0) + -1 < iVar5) {
      pvVar2 = operator_new(iVar5 * 4 + 4);
      if (pvVar2 != (void *)0x0) {
        iVar3 = 0;
        if (0 < *(int *)(param_1 + 0x11dcf0)) {
          do {
            if (iVar5 + 1 <= iVar3) break;
            iVar3 = iVar3 + 1;
            *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x11dce4) + -4 + iVar3 * 4);
          } while (iVar3 < *(int *)(param_1 + 0x11dcf0));
        }
        operator_delete(*(void **)(param_1 + 0x11dce4));
        *(void **)(param_1 + 0x11dce4) = pvVar2;
        *(int *)(param_1 + 0x11dcf0) = iVar5 + 1;
      }
    }
    iVar3 = piStack_4[1];
    iVar1 = *(int *)(*(int *)(param_1 + 0x11dce4) + iVar5 * 4);
    in_EAX = 0;
    if (0 < iVar3) {
      do {
        if (piStack_4[3] <= in_EAX) break;
        if (*(int *)(*piStack_4 + in_EAX * 4) == iVar1) goto LAB_0046ddc8;
        in_EAX = in_EAX + 1;
      } while (in_EAX < iVar3);
    }
    if (piStack_4[3] + -1 < iVar3) {
      iVar3 = iVar3 + 1;
      pvVar2 = operator_new(iVar3 * 4);
      if (pvVar2 != (void *)0x0) {
        iVar4 = 0;
        if (0 < piStack_4[3]) {
          do {
            if (iVar3 <= iVar4) break;
            iVar4 = iVar4 + 1;
            *(undefined4 *)((int)pvVar2 + iVar4 * 4 + -4) =
                 *(undefined4 *)(*piStack_4 + -4 + iVar4 * 4);
          } while (iVar4 < piStack_4[3]);
        }
        operator_delete((void *)*piStack_4);
        *piStack_4 = (int)pvVar2;
        piStack_4[3] = iVar3;
      }
    }
    *(int *)(*piStack_4 + piStack_4[1] * 4) = iVar1;
    in_EAX = piStack_4[1] + 1;
    piStack_4[1] = in_EAX;
LAB_0046ddc8:
    iVar5 = iVar5 + -1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0046dddb
// Address: 0046dddb
TPicture * __thiscall
FUN_0046dddb(TPicture *param_1,char *param_2,long param_3,int param_4,void *param_5,int param_6)
{
  param_1->Dib = (tagBITMAPINFOHEADER *)0x0;
  param_1->BitmapInfo = (BITMAPINFO256 *)0x0;
  param_1->Bits = (uchar *)0x0;
  param_1->TransInfo = (TRANSINFO *)0x0;
  param_1->OwnMemory = 0;
  param_1->Width = 0;
  param_1->Height = 0;
  param_1->Orien = 1;
  TPicture::Load(param_1,param_2,param_3,param_4,param_5,param_6);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046de25
// Address: 0046de25
TPicture * __thiscall FUN_0046de25(TPicture *param_1,int param_2,int param_3)
{
  int *piVar1;
  long *plVar2;
  BITMAPINFO256 *pBVar3;
  long lVar4;
  tagBITMAPINFOHEADER *ptVar5;
  TRANSINFO *pTVar6;
  undefined4 uVar7;
  
  piVar1 = &param_1->OwnMemory;
  plVar2 = &param_1->Height;
  param_1->Dib = (tagBITMAPINFOHEADER *)0x0;
  param_1->BitmapInfo = (BITMAPINFO256 *)0x0;
  param_1->Bits = (uchar *)0x0;
  param_1->TransInfo = (TRANSINFO *)0x0;
  *piVar1 = 0;
  param_1->Width = 0;
  *plVar2 = 0;
  param_1->Orien = 1;
  rge_read(param_2,piVar1,4);
  rge_read(param_2,&param_1->Width,4);
  rge_read(param_2,plVar2,4);
  rge_read(param_2,&param_1->Orien,2);
  if (*piVar1 != 0) {
    *piVar1 = 2;
  }
  if ((param_1->Width < 1) || (*plVar2 < 1)) {
    param_1->Dib = (tagBITMAPINFOHEADER *)0x0;
    param_1->BitmapInfo = (BITMAPINFO256 *)0x0;
    param_1->Bits = (uchar *)0x0;
  }
  else {
    uVar7 = 1;
    lVar4 = TPicture::AlignedWidth(param_1);
    ptVar5 = (tagBITMAPINFOHEADER *)calloc(lVar4 * *plVar2 + 0x428,uVar7);
    param_1->Dib = ptVar5;
    lVar4 = TPicture::AlignedWidth(param_1);
    rge_read(param_2,param_1->Dib,lVar4 * *plVar2 + 0x428);
    param_1->BitmapInfo = (BITMAPINFO256 *)param_1->Dib;
    param_1->Bits = (uchar *)((BITMAPINFO256 *)param_1->Dib + 1);
  }
  param_1->TransInfo = (TRANSINFO *)0x0;
  if ((param_3 != 0) && (param_1->Dib != (tagBITMAPINFOHEADER *)0x0)) {
    pTVar6 = (TRANSINFO *)malloc(0x18);
    param_1->TransInfo = pTVar6;
    if (pTVar6 != (TRANSINFO *)0x0) {
      pBVar3 = (BITMAPINFO256 *)param_1->Dib;
      if ((pBVar3->bmiHeader).biCompression == 3) {
        DibCheckTrans(pBVar3,pTVar6,
                      (uchar *)((int)(pBVar3->bmiColors + -7) + (pBVar3->bmiHeader).biSize));
        return param_1;
      }
      DibCheckTrans(pBVar3,pTVar6,
                    &pBVar3->bmiColors[(pBVar3->bmiHeader).biClrUsed - 10].rgbBlue +
                    (pBVar3->bmiHeader).biSize);
      return param_1;
    }
    DibFree(param_1->Dib);
    param_1->Dib = (tagBITMAPINFOHEADER *)0x0;
    param_1->BitmapInfo = (BITMAPINFO256 *)0x0;
    *piVar1 = 0;
    param_1->Width = 0;
    *plVar2 = 0;
    param_1->Orien = 1;
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046df9e
// Address: 0046df9e
void __fastcall FUN_0046df9e(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 7) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0046dfbf
// Address: 0046dfbf
void __fastcall FUN_0046dfbf(undefined4 *param_1)
{
  int *piVar1;
  
  if (param_1[4] != 0) {
    piVar1 = (int *)param_1[3];
    if (piVar1 != (int *)0x0) {
      if ((piVar1[5] != 0) && (*piVar1 != 0)) {
        free(piVar1[5]);
      }
      free(param_1[3]);
    }
    if ((tagBITMAPINFOHEADER *)*param_1 != (tagBITMAPINFOHEADER *)0x0) {
      if (param_1[4] == 2) {
        free();
        return;
      }
      DibFree((tagBITMAPINFOHEADER *)*param_1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046e015
// Address: 0046e015
void __thiscall FUN_0046e015(TPicture *param_1,int param_2)
{
  long *plVar1;
  long lVar2;
  
  rge_write(param_2,&param_1->OwnMemory,4);
  rge_write(param_2,&param_1->Width,4);
  plVar1 = &param_1->Height;
  rge_write(param_2,plVar1,4);
  rge_write(param_2,&param_1->Orien,2);
  if ((0 < param_1->Width) && (0 < *plVar1)) {
    rge_write(param_2,param_1->BitmapInfo,0x428);
    lVar2 = TPicture::AlignedWidth(param_1);
    rge_write(param_2,param_1->Bits,lVar2 * *plVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046e0a4
// Address: 0046e0a4
// [HELPER] s_C__msdev_work_age1_x1_Picture_cp: "C:\msdev\work\age1_x1\Picture.cpp"
// [HELPER] shape_file_first: " "
void __thiscall
FUN_0046e0a4(int *param_1,char *param_2,ulong param_3,int param_4,void *param_5,int param_6)
{
  BITMAPINFO256 *pBVar1;
  tagBITMAPINFOHEADER *ptVar2;
  int iVar3;
  TRANSINFO *pTVar4;
  _iobuf *p_Stack_108;
  char acStack_104 [260];
  
  debug_timeGetTime(s_C__msdev_work_age1_x1_Picture_cp,0x7f);
  param_1[3] = 0;
  param_1[4] = 1;
  if (shape_file_first != '\0') {
    ptVar2 = DibOpenFile(param_2);
    *param_1 = (int)ptVar2;
  }
  if (((*param_1 == 0) && (param_3 != 0xffffffff)) &&
     (iVar3 = RESFILE_Extract_to_File(0x62696e61,param_3,acStack_104,&p_Stack_108), iVar3 != 0)) {
    fclose(p_Stack_108);
    ptVar2 = DibOpenFile(acStack_104);
    *param_1 = (int)ptVar2;
    __unlink(acStack_104);
  }
  if ((shape_file_first == '\0') && (*param_1 == 0)) {
    ptVar2 = DibOpenFile(param_2);
    *param_1 = (int)ptVar2;
  }
  ptVar2 = (tagBITMAPINFOHEADER *)*param_1;
  if (ptVar2 == (tagBITMAPINFOHEADER *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  else {
    param_1[1] = (int)ptVar2;
    if (ptVar2->biCompression == 3) {
      iVar3 = ptVar2->biSize + 0xc;
    }
    else {
      iVar3 = ptVar2->biSize + ptVar2->biClrUsed * 4;
    }
    param_1[2] = (int)&ptVar2->biSize + iVar3;
    param_1[5] = ptVar2->biWidth;
    iVar3 = ptVar2->biHeight;
    param_1[6] = iVar3;
    if (iVar3 < 0) {
      *(undefined2 *)(param_1 + 7) = 1;
      param_1[6] = -iVar3;
    }
    else {
      *(undefined2 *)(param_1 + 7) = 0xffff;
    }
    if (param_5 != (void *)0x0) {
      DibMapToPalette(ptVar2,param_5,param_4,param_6);
    }
    if (param_4 == 0) {
      return;
    }
    pTVar4 = (TRANSINFO *)malloc(0x18);
    param_1[3] = (int)pTVar4;
    if (pTVar4 != (TRANSINFO *)0x0) {
      pBVar1 = (BITMAPINFO256 *)*param_1;
      if ((pBVar1->bmiHeader).biCompression != 3) {
        DibCheckTrans(pBVar1,pTVar4,
                      &pBVar1->bmiColors[(pBVar1->bmiHeader).biClrUsed - 10].rgbBlue +
                      (pBVar1->bmiHeader).biSize);
        return;
      }
      DibCheckTrans(pBVar1,pTVar4,
                    (uchar *)((int)(pBVar1->bmiColors + -7) + (pBVar1->bmiHeader).biSize));
      return;
    }
    DibFree((tagBITMAPINFOHEADER *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 7) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0046e266
// Address: 0046e266
void __thiscall FUN_0046e266(int *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  
  param_1[2] = param_3;
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[3] = param_4;
  param_1[4] = 0;
  param_1[5] = *(int *)(param_2 + 4);
  iVar1 = *(int *)(param_2 + 8);
  param_1[6] = iVar1;
  if (iVar1 < 0) {
    *(undefined2 *)(param_1 + 7) = 1;
    param_1[6] = -iVar1;
    return;
  }
  *(undefined2 *)(param_1 + 7) = 0xffff;
  return;
}

// --------------------------------------------------

// Function: FUN_0046e2b5
// Address: 0046e2b5
uint __fastcall FUN_0046e2b5(int param_1)
{
  return *(int *)(param_1 + 0x14) + 3U & 0xfffffffc;
}

// --------------------------------------------------

// Function: FUN_0046e2c9
// Address: 0046e2c9
void __thiscall
FUN_0046e2c9(int param_1,int param_2,long param_3,long param_4,int param_5,int param_6)
{
  if (*(TRANSINFO **)(param_1 + 0xc) != (TRANSINFO *)0x0) {
    TransDibBlt(*(BITMAPINFO256 **)(param_2 + 0xc),*(uchar **)(param_2 + 8),
                (tagRECT *)(param_2 + 0x28),param_3,param_4,*(long *)(param_1 + 0x14),
                *(long *)(param_1 + 0x18),*(BITMAPINFO256 **)(param_1 + 4),*(uchar **)(param_1 + 8),
                *(TRANSINFO **)(param_1 + 0xc),0,0,*(long *)(param_1 + 0x14),
                *(long *)(param_1 + 0x18),1,param_5,param_6,0);
    return;
  }
  DibBlt(*(BITMAPINFO256 **)(param_2 + 0xc),*(uchar **)(param_2 + 8),(tagRECT *)(param_2 + 0x28),
         param_3,param_4,*(long *)(param_1 + 0x14),*(long *)(param_1 + 0x18),
         *(BITMAPINFO256 **)(param_1 + 4),*(uchar **)(param_1 + 8),0,0,*(long *)(param_1 + 0x14),
         *(long *)(param_1 + 0x18),1,param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_0046e36d
// Address: 0046e36d
void __thiscall
FUN_0046e36d(int param_1,int param_2,long param_3,long param_4,long param_5,long param_6,
            long param_7,long param_8,long param_9,long param_10,long param_11,long param_12)
{
  TileDibBlt(*(BITMAPINFO256 **)(param_2 + 0xc),*(uchar **)(param_2 + 8),(tagRECT *)(param_2 + 0x28)
             ,param_3,param_4,param_5,param_6,param_7,param_8,*(BITMAPINFO256 **)(param_1 + 4),
             *(uchar **)(param_1 + 8),*(TRANSINFO **)(param_1 + 0xc),param_9,param_10,param_11,
             param_12,(uint)(*(TRANSINFO **)(param_1 + 0xc) != (TRANSINFO *)0x0),0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_0046e3d5
// Address: 0046e3d5
uint __thiscall FUN_0046e3d5(TPicture *param_1,int param_2,int param_3,int param_4,int param_5)
{
  char cVar1;
  undefined4 in_EAX;
  uint uVar2;
  long lVar3;
  
  cVar1 = (char)param_1->Orien;
  uVar2 = CONCAT31((int3)((uint)in_EAX >> 8),cVar1);
  if (param_5 != 0) {
    uVar2 = (-(uint)(cVar1 != '\x01') & 2) - 1;
  }
  if ((((param_2 < 1) || (param_1->Width <= param_2)) || (param_3 < 0)) ||
     (param_1->Height <= param_3)) {
    return uVar2 & 0xffffff00;
  }
  if (param_4 == 0) {
    if ((char)uVar2 == '\x01') {
      lVar3 = TPicture::AlignedWidth(param_1);
      return CONCAT31((int3)((uint)(param_1->Bits + lVar3 * param_3) >> 8),
                      (param_1->Bits + lVar3 * param_3)[param_2]);
    }
    lVar3 = TPicture::AlignedWidth(param_1);
    return CONCAT31((int3)((uint)(param_1->Bits + lVar3 * ((param_1->Height - param_3) + -1)) >> 8),
                    (param_1->Bits + lVar3 * ((param_1->Height - param_3) + -1))[param_2]);
  }
  if ((char)uVar2 == '\x01') {
    lVar3 = TPicture::AlignedWidth(param_1);
    return CONCAT31((int3)((uint)(param_1->Bits + (lVar3 * param_3 - param_2)) >> 8),
                    (param_1->Bits + (lVar3 * param_3 - param_2))[param_1->Width + -1]);
  }
  lVar3 = TPicture::AlignedWidth(param_1);
  return CONCAT31((int3)((uint)(param_1->Bits +
                               (lVar3 * ((param_1->Height - param_3) + -1) - param_2)) >> 8),
                  (param_1->Bits + (lVar3 * ((param_1->Height - param_3) + -1) - param_2))
                  [param_1->Width + -1]);
}

// --------------------------------------------------

// Function: FUN_0046e4ac
// Address: 0046e4ac
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

RGE_Player * __thiscall
FUN_0046e4ac(RGE_Player *param_1,int param_2,RGE_Game_World *param_3,byte param_4)
{
  int *piVar1;
  short *psVar2;
  int iVar3;
  RGE_Doppleganger_Creator *pRVar4;
  uchar *puVar5;
  char *pcVar6;
  float *pfVar7;
  undefined4 *unaff_FS_OFFSET;
  short sStack_16;
  uchar auStack_14 [4];
  RGE_Player *pRStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e241;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  piVar1 = &param_1->pathingAttemptCapValue;
  param_1->computerPlayerValue = 0;
  *piVar1 = 5;
  param_1->pathingDelayCapValue = 10;
  pRStack_10 = param_1;
  RGE_Tile_List::RGE_Tile_List(&param_1->tile_list,400);
  uStack_4 = 0;
  RGE_Tile_List::RGE_Tile_List(&param_1->diam_tile_list,400);
  param_1->_padding_ = (int)&RGE_Player::_vftable_;
  iVar3 = pathingCapValue;
  param_1->id = (ushort)param_4;
  uStack_4._0_1_ = 1;
  *piVar1 = iVar3;
  param_1->world = param_3;
  RGE_Player::reset_selected(param_1);
  pRVar4 = (RGE_Doppleganger_Creator *)operator_new(0x1c);
  uStack_4._0_1_ = 2;
  if (pRVar4 == (RGE_Doppleganger_Creator *)0x0) {
    pRVar4 = (RGE_Doppleganger_Creator *)0x0;
  }
  else {
    pRVar4 = (RGE_Doppleganger_Creator *)
             RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(pRVar4,param_1,100);
  }
  param_1->doppleganger_creator = pRVar4;
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  puVar5 = (uchar *)calloc(1,(int)param_1->world->player_num);
  param_1->relations = puVar5;
  rge_read(param_2,puVar5,(int)param_1->world->player_num);
  rge_read(param_2,param_1->unitDiplomacy,0x24);
  if (save_game_version < _DAT_00570e90) {
    param_1->allied_LOS_Enable = 0;
  }
  else {
    rge_read(param_2,&param_1->allied_LOS_Enable,4);
  }
  rge_read(param_2,&param_1->allied_victory,1);
  rge_read(param_2,&sStack_16,2);
  if (sStack_16 < 1) {
    param_1->name = (char *)0x0;
  }
  else {
    pcVar6 = (char *)calloc((int)sStack_16,1);
    param_1->name = pcVar6;
    rge_read(param_2,pcVar6,(int)sStack_16);
  }
  psVar2 = &param_1->attribute_num;
  rge_read(param_2,psVar2,2);
  if (*psVar2 < 1) {
    param_1->attributes = (float *)0x0;
  }
  else {
    pfVar7 = (float *)calloc((int)*psVar2,4);
    param_1->attributes = pfVar7;
    rge_read(param_2,pfVar7,(int)*psVar2 << 2);
  }
  rge_read(param_2,&param_1->view_x,4);
  rge_read(param_2,&param_1->view_y,4);
  rge_read(param_2,&param_1->map_x,2);
  rge_read(param_2,&param_1->map_y,2);
  rge_read(param_2,&param_1->culture,1);
  rge_read(param_2,&param_1->master_player_id,1);
  rge_read(param_2,&param_1->game_status,1);
  rge_read(param_2,&param_1->resigned,1);
  rge_read(param_2,auStack_14,1);
  RGE_Player::set_color_table(param_1,auStack_14[0]);
  rge_read(param_2,piVar1,4);
  rge_read(param_2,&param_1->pathingDelayCapValue,4);
  param_1->checksum_created_this_update = '\0';
  param_1->checksum = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046e745
// Address: 0046e745
RGE_Player * __thiscall FUN_0046e745(RGE_Player *param_1,byte param_2)
{
  RGE_Player::~RGE_Player(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046e76e
// Address: 0046e76e
RGE_Player * __thiscall
FUN_0046e76e(RGE_Player *param_1,RGE_Game_World *param_2,int param_3,byte param_4,char *param_5,
            uchar param_6,char param_7)
{
  RGE_Map *pRVar1;
  uchar *puVar2;
  RGE_Master_Static_Object **ppRVar3;
  RGE_Master_Static_Object *pRVar4;
  RGE_Object_List *pRVar5;
  RGE_Visible_Map *pRVar6;
  RGE_Doppleganger_Creator *pRVar7;
  float *pfVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  float *pfVar12;
  int *piVar13;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e29d;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->computerPlayerValue = 0;
  param_1->pathingAttemptCapValue = 5;
  param_1->pathingDelayCapValue = 10;
  RGE_Tile_List::RGE_Tile_List(&param_1->tile_list,400);
  uStack_4 = 0;
  RGE_Tile_List::RGE_Tile_List(&param_1->diam_tile_list,400);
  param_1->_padding_ = (int)&RGE_Player::_vftable_;
  param_1->pathingAttemptCapValue = pathingCapValue;
  param_1->master_player_id = param_6;
  uStack_4._0_1_ = 1;
  param_1->type = '\0';
  param_1->world = param_2;
  param_1->id = (ushort)param_4;
  RGE_Player::reset_selected(param_1);
  param_1->name = (char *)0x0;
  if (param_5 != (char *)0x0) {
    getstring(&param_1->name,param_5);
  }
  puVar2 = (uchar *)calloc(1,(int)param_1->world->player_num);
  param_1->relations = puVar2;
  piVar13 = param_1->unitDiplomacy;
  for (iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) {
    *piVar13 = -1;
    piVar13 = piVar13 + 1;
  }
  sVar9 = 0;
  if (0 < param_1->world->player_num) {
    do {
      param_1->relations[sVar9] = '\x01';
      if (sVar9 == param_1->id) {
        param_1->unitDiplomacy[sVar9] = 1;
      }
      else if (sVar9 == 0) {
        param_1->unitDiplomacy[0] = 0;
      }
      else {
        param_1->unitDiplomacy[sVar9] = 3;
      }
      sVar9 = sVar9 + 1;
    } while (sVar9 < param_1->world->player_num);
  }
  param_1->mutualExploredMask = 0;
  param_1->mutualVisibleMask = 0;
  param_1->nonMutualVisibleMask = 0;
  param_1->allied_LOS_Enable = 0;
  param_1->allied_victory = '\0';
  sVar9 = *(short *)(param_3 + 0x18);
  param_1->master_object_num = sVar9;
  if (0 < sVar9) {
    ppRVar3 = (RGE_Master_Static_Object **)calloc((int)sVar9,4);
    sVar9 = 0;
    param_1->master_objects = ppRVar3;
    if (0 < param_1->master_object_num) {
      do {
        piVar13 = *(int **)(sVar9 * 4 + *(int *)(param_3 + 0x1c));
        if (piVar13 != (int *)0x0) {
          pRVar4 = (RGE_Master_Static_Object *)(**(code **)(*piVar13 + 0x1c))();
          param_1->master_objects[sVar9] = pRVar4;
        }
        sVar9 = sVar9 + 1;
      } while (sVar9 < param_1->master_object_num);
    }
  }
  if (param_7 == '\0') {
    param_1->objects = (RGE_Object_List *)0x0;
    param_1->sleeping_objects = (RGE_Object_List *)0x0;
    param_1->doppleganger_objects = (RGE_Object_List *)0x0;
    param_1->victory_conditions = (RGE_Victory_Conditions *)0x0;
    param_1->visible = (RGE_Visible_Map *)0x0;
  }
  else {
    pRVar5 = (RGE_Object_List *)operator_new(0xc);
    uStack_4._0_1_ = 2;
    if (pRVar5 == (RGE_Object_List *)0x0) {
      pRVar5 = (RGE_Object_List *)0x0;
    }
    else {
      pRVar5 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar5);
    }
    uStack_4._0_1_ = 1;
    param_1->objects = pRVar5;
    pRVar5 = (RGE_Object_List *)operator_new(0xc);
    uStack_4._0_1_ = 3;
    if (pRVar5 == (RGE_Object_List *)0x0) {
      pRVar5 = (RGE_Object_List *)0x0;
    }
    else {
      pRVar5 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar5);
    }
    uStack_4._0_1_ = 1;
    param_1->sleeping_objects = pRVar5;
    pRVar5 = (RGE_Object_List *)operator_new(0xc);
    uStack_4._0_1_ = 4;
    if (pRVar5 == (RGE_Object_List *)0x0) {
      pRVar5 = (RGE_Object_List *)0x0;
    }
    else {
      pRVar5 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar5);
    }
    uStack_4._0_1_ = 1;
    param_1->doppleganger_objects = pRVar5;
    RGE_Player::new_victory(param_1);
    pRVar6 = (RGE_Visible_Map *)operator_new(0x38);
    uStack_4._0_1_ = 5;
    if (pRVar6 == (RGE_Visible_Map *)0x0) {
      uStack_4._0_1_ = 1;
      param_1->visible = (RGE_Visible_Map *)0x0;
    }
    else {
      pRVar6 = (RGE_Visible_Map *)RGE_Visible_Map::RGE_Visible_Map(pRVar6,param_2->map,param_1);
      uStack_4._0_1_ = 1;
      param_1->visible = pRVar6;
    }
  }
  pRVar7 = (RGE_Doppleganger_Creator *)operator_new(0x1c);
  uStack_4._0_1_ = 6;
  if (pRVar7 == (RGE_Doppleganger_Creator *)0x0) {
    pRVar7 = (RGE_Doppleganger_Creator *)0x0;
  }
  else {
    pRVar7 = (RGE_Doppleganger_Creator *)
             RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(pRVar7,param_1,100);
  }
  param_1->doppleganger_creator = pRVar7;
  sVar9 = *(short *)(param_3 + 0x20);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  param_1->attribute_num = sVar9;
  if (sVar9 < 1) {
    param_1->attributes = (float *)0x0;
  }
  else {
    pfVar8 = (float *)calloc((int)sVar9,4);
    param_1->attributes = pfVar8;
    pfVar12 = *(float **)(param_3 + 0x24);
    for (uVar11 = (int)param_1->attribute_num & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
      *pfVar8 = *pfVar12;
      pfVar12 = pfVar12 + 1;
      pfVar8 = pfVar8 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
      *(undefined1 *)pfVar8 = *(undefined1 *)pfVar12;
      pfVar12 = (float *)((int)pfVar12 + 1);
      pfVar8 = (float *)((int)pfVar8 + 1);
    }
  }
  param_1->culture = *(uchar *)(param_3 + 0x28);
  pRVar1 = param_1->world->map;
  RGE_Player::set_view_loc(param_1,(float)(pRVar1->map_width / 2),(float)(pRVar1->map_height / 2));
  pRVar1 = param_1->world->map;
  RGE_Player::set_map_loc(param_1,(short)(pRVar1->map_width / 2),(short)(pRVar1->map_height / 2));
  param_1->game_status = '\0';
  param_1->resigned = '\0';
  param_1->color_table = (RGE_Color_Table *)0x0;
  sVar9 = *(short *)(param_3 + 0x2a);
  param_1->tribe_effect = (int)sVar9;
  if ((param_7 != '\0') && (-1 < sVar9)) {
    (**(code **)(param_1->world->effects->_padding_ + 8))
              (CONCAT22(sVar9 >> 0xf,(short)param_1->tribe_effect),param_1);
  }
  param_1->checksum = 0;
  param_1->checksum_created_this_update = '\0';
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0046eaf1
// Address: 0046eaf1
void __fastcall FUN_0046eaf1(undefined4 *param_1)
{
  RGE_Object_List *pRVar1;
  RGE_Victory_Conditions *this;
  undefined4 *puVar2;
  RGE_Visible_Map *this_00;
  RGE_Doppleganger_Creator *this_01;
  Visible_Resource_Manager *this_02;
  short sVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  pcStack_8 = FUN_0055e2c6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &RGE_Player::_vftable_;
  pRVar1 = (RGE_Object_List *)param_1[10];
  uStack_4 = 1;
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = (RGE_Object_List *)param_1[0xb];
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = (RGE_Object_List *)param_1[0xc];
  if (pRVar1 != (RGE_Object_List *)0x0) {
    RGE_Object_List::~RGE_Object_List(pRVar1);
    operator_delete(pRVar1);
  }
  this = (RGE_Victory_Conditions *)param_1[0xd];
  if (this != (RGE_Victory_Conditions *)0x0) {
    RGE_Victory_Conditions::~RGE_Victory_Conditions(this);
    operator_delete(this);
  }
  free(param_1[0x21]);
  param_1[0x21] = 0;
  if (0 < *(short *)((int)param_1 + 0x22)) {
    sVar3 = 0;
    if (0 < *(short *)((int)param_1 + 0x22)) {
      do {
        puVar2 = *(undefined4 **)(param_1[9] + sVar3 * 4);
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)*puVar2)(1);
        }
        sVar3 = sVar3 + 1;
      } while (sVar3 < *(short *)((int)param_1 + 0x22));
    }
    free(param_1[9]);
    param_1[9] = 0;
    *(undefined2 *)((int)param_1 + 0x22) = 0;
  }
  this_00 = (RGE_Visible_Map *)param_1[0xe];
  if (this_00 != (RGE_Visible_Map *)0x0) {
    RGE_Visible_Map::~RGE_Visible_Map(this_00);
    operator_delete(this_00);
  }
  this_01 = (RGE_Doppleganger_Creator *)param_1[0x10];
  if (this_01 != (RGE_Doppleganger_Creator *)0x0) {
    RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator(this_01);
    operator_delete(this_01);
  }
  this_02 = (Visible_Resource_Manager *)param_1[0x44];
  if (this_02 != (Visible_Resource_Manager *)0x0) {
    Visible_Resource_Manager::~Visible_Resource_Manager(this_02);
    operator_delete(this_02);
  }
  if (param_1[0x11] != 0) {
    free(param_1[0x11]);
    param_1[0x11] = 0;
  }
  if (0 < *(short *)(param_1 + 0x13)) {
    free(param_1[0x14]);
    *(undefined2 *)(param_1 + 0x13) = 0;
  }
  uStack_4 = uStack_4 & 0xffffff00;
  RGE_Tile_List::~RGE_Tile_List((RGE_Tile_List *)(param_1 + 0x1b));
  uStack_4 = 0xffffffff;
  RGE_Tile_List::~RGE_Tile_List((RGE_Tile_List *)(param_1 + 0x16));
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0046ec7c
// Address: 0046ec7c
void FUN_0046ec7c(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0046ec81
// Address: 0046ec81
void FUN_0046ec81(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0046ec91
// Address: 0046ec91
void FUN_0046ec91(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0046eca3
// Address: 0046eca3
undefined4 FUN_0046eca3(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0046ecb6
// Address: 0046ecb6
undefined4 FUN_0046ecb6(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046ecc5
// Address: 0046ecc5
undefined4 FUN_0046ecc5(void)
{
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0046ecd6
// Address: 0046ecd6
void __thiscall FUN_0046ecd6(int param_1,char param_2)
{
  if (((param_2 != *(char *)(param_1 + 0x80)) &&
      (((*(char *)(param_1 + 0x81) == '\0' || (param_2 == '\x02')) &&
       (*(char *)(param_1 + 0x80) = param_2, param_2 == '\x02')))) &&
     (*(char *)(param_1 + 0x81) == '\0')) {
    (**(code **)(rge_base_game->_padding_ + 0x40))(6,(int)*(short *)(param_1 + 0x4a),0,0,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046ed27
// Address: 0046ed27
void FUN_0046ed27(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0046ed33
// Address: 0046ed33
void FUN_0046ed33(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0046ed43
// Address: 0046ed43
void __fastcall FUN_0046ed43(int *param_1)
{
  char cVar1;
  undefined4 unaff_retaddr;
  
  cVar1 = *(char *)((int)param_1 + 0x81);
  *(undefined1 *)((int)param_1 + 0x81) = 1;
  (**(code **)(*param_1 + 4))(2);
  if (cVar1 == '\0') {
    (**(code **)(rge_base_game->_padding_ + 0x40))
              (5,(int)*(short *)((int)param_1 + 0x4a),unaff_retaddr,0,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046ed8c
// Address: 0046ed8c
undefined1 __fastcall FUN_0046ed8c(int param_1)
{
  return *(undefined1 *)(param_1 + 0x81);
}

// --------------------------------------------------

// Function: FUN_0046ed97
// Address: 0046ed97
undefined4 FUN_0046ed97(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046eda5
// Address: 0046eda5
undefined4 __fastcall FUN_0046eda5(int param_1)
{
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_0046edb4
// Address: 0046edb4
undefined4 __thiscall FUN_0046edb4(int param_1,int param_2)
{
  if ((((param_2 != *(short *)(param_1 + 0x4a)) && (0 < param_2)) &&
      (param_2 < *(short *)(*(int *)(param_1 + 0x3c) + 0x3c))) &&
     (*(char *)(*(int *)(param_1 + 0x84) + param_2) == '\x03')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046edf4
// Address: 0046edf4
undefined4 __thiscall FUN_0046edf4(int param_1,int param_2)
{
  if (param_2 == *(short *)(param_1 + 0x4a)) {
    return 1;
  }
  if (((0 < param_2) && (param_2 < *(short *)(*(int *)(param_1 + 0x3c) + 0x3c))) &&
     (*(char *)(*(int *)(param_1 + 0x84) + param_2) == '\0')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046ee3c
// Address: 0046ee3c
undefined4 __thiscall FUN_0046ee3c(int param_1,int param_2)
{
  if ((((param_2 != *(short *)(param_1 + 0x4a)) && (0 < param_2)) &&
      (param_2 < *(short *)(*(int *)(param_1 + 0x3c) + 0x3c))) &&
     (*(char *)(*(int *)(param_1 + 0x84) + param_2) == '\x01')) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046ee74
// Address: 0046ee74
undefined4 __fastcall FUN_0046ee74(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (*(short *)(param_1[0xf] + 0x3c) < 2) {
    return 1;
  }
  do {
    if (iVar2 != *(short *)((int)param_1 + 0x4a)) {
      iVar1 = (**(code **)(*param_1 + 0x20))(iVar2);
      if (iVar1 == 0) {
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < *(short *)(param_1[0xf] + 0x3c));
  return 1;
}

// --------------------------------------------------

// Function: FUN_0046eec7
// Address: 0046eec7
void FUN_0046eec7(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0046eed3
// Address: 0046eed3
void FUN_0046eed3(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0046eee3
// Address: 0046eee3
void __thiscall
FUN_0046eee3(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,float param_7,
            float param_8,float param_9,float param_10,uchar param_11,uchar param_12,uchar param_13)
{
  RGE_Command::command_ai_order
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),param_2,param_2,param_3,param_4,
             param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,param_13);
  return;
}

// --------------------------------------------------

// Function: FUN_0046ef3b
// Address: 0046ef3b
void __thiscall
FUN_0046ef3b(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13)
{
  RGE_Static_Object *this;
  UnitAIModule *pUVar1;
  
  this = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 0x3c),param_3);
  if (this != (RGE_Static_Object *)0x0) {
    pUVar1 = RGE_Static_Object::unitAI(this);
    if (pUVar1 != (UnitAIModule *)0x0) {
      pUVar1 = RGE_Static_Object::unitAI(this);
      (**(code **)(pUVar1->_padding_ + 0x10))
                (param_2,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,
                 param_13);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046efa8
// Address: 0046efa8
void __thiscall
FUN_0046efa8(int param_1,RGE_Static_Object *param_2,RGE_Static_Object *param_3,float param_4,
            float param_5)
{
  RGE_Command::command_order
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),&param_2,1,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0046efdc
// Address: 0046efdc
void __thiscall FUN_0046efdc(int param_1,int param_2,XYZBYTEPoint *param_3,int param_4)
{
  RGE_Command::command_add_waypoint
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             param_2,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_0046f002
// Address: 0046f002
void __thiscall FUN_0046f002(int param_1,int param_2,int param_3,int param_4)
{
  code *pcVar1;
  RGE_Static_Object *pRVar2;
  
  pRVar2 = RGE_Game_World::object(*(RGE_Game_World **)(param_1 + 0x3c),param_2);
  if ((pRVar2 != (RGE_Static_Object *)0x0) && (0 < param_4)) {
    pcVar1 = *(code **)(pRVar2->_padding_ + 0x1bc);
    do {
      (*pcVar1)(param_3,1);
      param_3 = param_3 + 3;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046f04f
// Address: 0046f04f
void __thiscall FUN_0046f04f(int *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  AIPlay *pAVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0xd0))(param_2);
  pAVar2 = AIPlayBook::play(*(AIPlayBook **)(param_1[0xf] + 0xa0),param_3);
  if (pAVar2 == (AIPlay *)0x0) {
    (**(code **)(iVar1 + 0x30))
              ((int)*(short *)((int)param_1 + 0x4a),param_2,0x2d7,0xffffffff,0xffffffff,0xbf800000,
               0xbf800000,0xbf800000,0xbf800000,1,0,100);
    return;
  }
  iVar6 = 0;
  puVar3 = (undefined4 *)&stack0xffffff98;
  piVar4 = param_1 + 0x4d;
  iVar5 = 0x19;
  do {
    if (*piVar4 != 0) {
      iVar6 = iVar6 + 1;
      *puVar3 = *(undefined4 *)(*piVar4 + 4);
      puVar3 = puVar3 + 1;
    }
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (iVar6 != 0) {
    (**(code **)(iVar1 + 0xc4))(unaff_retaddr,&stack0xffffff98,iVar6,0x40000000);
    (**(code **)(iVar1 + 0x30))
              ((int)*(short *)((int)param_1 + 0x4a),unaff_retaddr,0x2d6,uStack_c,uStack_8,0xbf800000
               ,0xbf800000,0xbf800000,0xbf800000,1,0,100);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046f13d
// Address: 0046f13d
void __thiscall
FUN_0046f13d(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)
{
  int iVar1;
  AIPlay *pAVar2;
  undefined4 unaff_EBX;
  
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0xd0))(param_2);
  pAVar2 = AIPlayBook::play(*(AIPlayBook **)(param_1[0xf] + 0xa0),param_5);
  if (pAVar2 == (AIPlay *)0x0) {
    (**(code **)(iVar1 + 0x30))
              ((int)*(short *)((int)param_1 + 0x4a),param_2,0x2d7,0xffffffff,0xffffffff,0xbf800000,
               0xbf800000,0xbf800000,0xbf800000,1,0,100);
    return;
  }
  if (param_3 != 0) {
    (**(code **)(iVar1 + 0xc4))(param_2,param_2,param_3,0x40000000);
    (**(code **)(iVar1 + 0x30))
              ((int)*(short *)((int)param_1 + 0x4a),param_2,0x2d6,unaff_EBX,param_5,0xbf800000,
               0xbf800000,0xbf800000,0xbf800000,1,0,100);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046f1f1
// Address: 0046f1f1
undefined4 __fastcall FUN_0046f1f1(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_0046f204
// Address: 0046f204
void __thiscall FUN_0046f204(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0046f21a
// Address: 0046f21a
undefined4 __fastcall FUN_0046f21a(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_0046f224
// Address: 0046f224
void __thiscall FUN_0046f224(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0046f23a
// Address: 0046f23a
undefined4 __fastcall FUN_0046f23a(int param_1)
{
  return *(undefined4 *)(param_1 + 0x10);
}

// --------------------------------------------------

// Function: FUN_0046f244
// Address: 0046f244
bool __thiscall FUN_0046f244(int param_1,int param_2)
{
  if ((*(int *)(param_1 + 0xc) != -1) && (*(int *)(param_1 + 0xc) < param_2)) {
    return true;
  }
  if (*(int *)(param_1 + 8) == -1) {
    return true;
  }
  return *(int *)(param_1 + 0x10) < *(int *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_0046f289
// Address: 0046f289
void __fastcall FUN_0046f289(int param_1)
{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0046f294
// Address: 0046f294
void FUN_0046f294(int param_1,int param_2,int param_3,undefined4 param_4)
{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char acStack_404 [1028];
  
  vsprintf(acStack_404,param_4,&stack0x00000014);
  iVar3 = -1;
  pcVar5 = acStack_404;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    uVar4 = 1;
    iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
    if (0 < iVar3) {
      do {
        iVar3 = RGE_Base_Game::playerID(rge_base_game,uVar4);
        if (iVar3 == param_2) {
          TCommunications_Handler::SendChatMsg
                    (*(TCommunications_Handler **)(*(int *)(*(int *)(param_1 + 0x3c) + 0x58) + 0x14)
                     ,(int)*(short *)(param_1 + 0x4a),uVar4,acStack_404);
        }
        uVar4 = uVar4 + 1;
        iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
      } while ((int)uVar4 <= iVar3);
    }
    if ((param_3 == 1) && (param_2 != *(short *)(param_1 + 0x4a))) {
      uVar4 = 1;
      iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
      if (0 < iVar3) {
        do {
          uVar2 = RGE_Base_Game::playerID(rge_base_game,uVar4);
          if (uVar2 == (int)*(short *)(param_1 + 0x4a)) {
            TCommunications_Handler::SendChatMsg
                      (*(TCommunications_Handler **)
                        (*(int *)(*(int *)(param_1 + 0x3c) + 0x58) + 0x14),
                       (int)*(short *)(param_1 + 0x4a),uVar4,acStack_404);
          }
          uVar4 = uVar4 + 1;
          iVar3 = RGE_Base_Game::numberPlayers(rge_base_game);
        } while ((int)uVar4 <= iVar3);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046f39b
// Address: 0046f39b
int * __thiscall
FUN_0046f39b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,short param_5)
{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  piVar1 = *(int **)(*(int *)(param_1 + 0x24) + param_5 * 4);
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar1 + 0x18))(param_1,param_2,param_3,param_4);
    if (6 < (byte)param_2) {
      (**(code **)(*piVar2 + 0x68))();
      return piVar2;
    }
    if (2 < (byte)param_2) {
      (**(code **)(*piVar2 + 0x6c))();
      return piVar2;
    }
    (**(code **)(*piVar2 + 0xb4))(param_3);
  }
  return piVar2;
}

// --------------------------------------------------

// Function: FUN_0046f406
// Address: 0046f406
void FUN_0046f406(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0046f413
// Address: 0046f413
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046f413(int *param_1,int param_2,int param_3,float param_4)
{
  int *piVar1;
  RGE_Victory_Conditions *this;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  undefined1 uStack_9;
  short sStack_8;
  short sStack_6;
  int iStack_4;
  
  iVar2 = param_2;
  if (param_4 <= (float)_DAT_00570e98) {
    rge_read(param_2,&sStack_8,2);
    if (0 < sStack_8) {
      pvVar3 = (void *)calloc((int)sStack_8,1);
      rge_read(iVar2,pvVar3,(int)sStack_8);
      if (param_1[0x11] == 0) {
        param_1[0x11] = (int)pvVar3;
      }
      else {
        free(pvVar3);
      }
    }
    rge_read(iVar2,param_1 + 0x45,4);
    rge_read(iVar2,param_1 + 0x46,4);
    rge_read(iVar2,param_1 + 0x47,2);
    rge_read(iVar2,(void *)((int)param_1 + 0x11e),2);
    iVar5 = 0;
    iStack_4 = 0;
    if (rge_base_game->prog_mode != 7) {
      uVar7 = 1;
      do {
        iVar4 = RGE_Base_Game::playerID(rge_base_game,uVar7);
        if ((iVar4 == *(short *)((int)param_1 + 0x4a)) &&
           ((iVar4 = TCommunications_Handler::GetPlayerHumanity(comm,uVar7), iVar4 == 2 ||
            (iVar4 = TCommunications_Handler::GetPlayerHumanity(comm,uVar7), iVar4 == 4)))) {
          iVar4 = RGE_Base_Game::playerTeam(rge_base_game,uVar7 - 1);
          if (1 < iVar4) {
            iVar5 = 1;
            iStack_4 = 1;
          }
          break;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 9);
    }
    if (((float)_DAT_00570ea0 < param_4) && (rge_read(iVar2,&uStack_9,1), iVar5 == 0)) {
      *(undefined1 *)(param_1 + 0x41) = uStack_9;
    }
    sVar6 = 0;
    param_1[0x40] = 0;
    if (0 < (short)param_1[0x13]) {
      rge_read(iVar2,(void *)param_1[0x14],0x74);
    }
    rge_read(iVar2,&sStack_6,2);
    if (0 < sStack_6) {
      do {
        rge_read(iVar2,&param_2,1);
        if (iVar5 == 0) {
          piVar1 = (int *)(param_3 + sVar6 * 4);
          iVar5 = *piVar1;
          if ((iVar5 < *(short *)(param_1[0xf] + 0x3c)) && (-1 < iVar5)) {
            *(char *)(param_1[0x21] + iVar5) = (char)param_2;
            iVar5 = *piVar1;
            if (iVar5 == 0) {
              param_1[0x22] = 0;
            }
            else if (sVar6 == *(short *)((int)param_1 + 0x4a)) {
              param_1[iVar5 + 0x22] = 1;
            }
            else if ((char)param_2 == '\0') {
              param_1[iVar5 + 0x22] = 2;
            }
            else if ((char)param_2 == '\x01') {
              param_1[iVar5 + 0x22] = 3;
            }
            else {
              param_1[iVar5 + 0x22] = 4;
            }
          }
        }
        sVar6 = sVar6 + 1;
        iVar5 = iStack_4;
      } while (sVar6 < sStack_6);
    }
    if ((float)_DAT_00570ea8 < param_4) {
      rge_read(iVar2,param_1 + 0x22,0x24);
    }
    this = (RGE_Victory_Conditions *)param_1[0xd];
    if (this != (RGE_Victory_Conditions *)0x0) {
      RGE_Victory_Conditions::~RGE_Victory_Conditions(this);
      operator_delete(this);
    }
    (**(code **)(*param_1 + 0xf0))(iVar2,param_3,0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046f6ad
// Address: 0046f6ad
void __thiscall FUN_0046f6ad(int param_1,int param_2)
{
  char cVar1;
  char *pcVar2;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  pcVar2 = *(char **)(param_1 + 0x44);
  do {
    if (uStack_4 == 0) break;
    uStack_4 = uStack_4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uStack_4 = ~uStack_4;
  rge_write(param_2,&uStack_4,2);
  rge_write(param_2,*(void **)(param_1 + 0x44),(int)(short)uStack_4);
  rge_write(param_2,(void *)(param_1 + 0x114),4);
  rge_write(param_2,(void *)(param_1 + 0x118),4);
  rge_write(param_2,(void *)(param_1 + 0x11c),2);
  rge_write(param_2,(void *)(param_1 + 0x11e),2);
  rge_write(param_2,(void *)(param_1 + 0x104),1);
  rge_write(param_2,(void *)(*(int *)(param_1 + 0x3c) + 0x3c),2);
  rge_write(param_2,*(void **)(param_1 + 0x84),(int)*(short *)(*(int *)(param_1 + 0x3c) + 0x3c));
  rge_write(param_2,(void *)(param_1 + 0x88),0x24);
  (**(code **)(**(int **)(param_1 + 0x34) + 0xc))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_0046f791
// Address: 0046f791
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046f791(int *param_1,int param_2,int param_3,float param_4)
{
  RGE_Victory_Conditions *this;
  float fVar1;
  int iVar2;
  short sVar3;
  void *pvVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  undefined1 uStack_9;
  short sStack_8;
  short sStack_6;
  int iStack_4;
  
  iVar2 = param_2;
  rge_read(param_2,&sStack_8,2);
  if (0 < sStack_8) {
    pvVar4 = (void *)calloc((int)sStack_8,1);
    rge_read(iVar2,pvVar4,(int)sStack_8);
    if (param_1[0x11] == 0) {
      param_1[0x11] = (int)pvVar4;
    }
    else {
      free(pvVar4);
    }
  }
  rge_read(iVar2,param_1 + 0x45,4);
  rge_read(iVar2,param_1 + 0x46,4);
  rge_read(iVar2,param_1 + 0x47,2);
  rge_read(iVar2,(void *)((int)param_1 + 0x11e),2);
  iStack_4 = 0;
  if (rge_base_game->prog_mode != 7) {
    uVar7 = 1;
    do {
      iVar5 = RGE_Base_Game::playerID(rge_base_game,uVar7);
      if ((iVar5 == *(short *)((int)param_1 + 0x4a)) &&
         ((iVar5 = TCommunications_Handler::GetPlayerHumanity(comm,uVar7), iVar5 == 2 ||
          (iVar5 = TCommunications_Handler::GetPlayerHumanity(comm,uVar7), iVar5 == 4)))) {
        iVar5 = RGE_Base_Game::playerTeam(rge_base_game,uVar7 - 1);
        if (1 < iVar5) {
          iStack_4 = 1;
        }
        break;
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < 9);
  }
  if (((float)_DAT_00570ea0 < param_4) && (rge_read(iVar2,&uStack_9,1), iStack_4 == 0)) {
    *(undefined1 *)(param_1 + 0x41) = uStack_9;
  }
  fVar1 = (float)_DAT_00570eb0;
  param_1[0x40] = 0;
  if ((param_4 <= fVar1) && (0 < (short)param_1[0x13])) {
    rge_read(iVar2,(void *)param_1[0x14],0x74);
  }
  rge_read(iVar2,&sStack_6,2);
  sVar6 = 0;
  if (0 < sStack_6) {
    do {
      iVar5 = param_3;
      rge_read(iVar2,&param_2,1);
      if (iStack_4 == 0) {
        sVar3 = sVar6;
        if (iVar5 != 0) {
          sVar3 = *(short *)(iVar5 + sVar6 * 4);
        }
        if ((sVar3 < *(short *)(param_1[0xf] + 0x3c)) && (-1 < sVar3)) {
          iVar5 = (int)sVar3;
          *(char *)(param_1[0x21] + iVar5) = (char)param_2;
          if (sVar3 == 0) {
            param_1[0x22] = 0;
          }
          else if (sVar3 == *(short *)((int)param_1 + 0x4a)) {
            param_1[iVar5 + 0x22] = 1;
          }
          else if ((char)param_2 == '\0') {
            param_1[iVar5 + 0x22] = 2;
          }
          else if ((char)param_2 == '\x01') {
            param_1[iVar5 + 0x22] = 3;
          }
          else {
            param_1[iVar5 + 0x22] = 4;
          }
        }
      }
      sVar6 = sVar6 + 1;
    } while (sVar6 < sStack_6);
  }
  iVar5 = param_3;
  if ((float)_DAT_00570ea8 <= param_4) {
    rge_read(iVar2,param_1 + 0x22,0x24);
  }
  this = (RGE_Victory_Conditions *)param_1[0xd];
  if (this != (RGE_Victory_Conditions *)0x0) {
    RGE_Victory_Conditions::~RGE_Victory_Conditions(this);
    operator_delete(this);
  }
  if (param_4 < (float)_DAT_00570eb8) {
    (**(code **)(*param_1 + 0xf0))(iVar2,iVar5,0);
    return;
  }
  (**(code **)(*param_1 + 0xf0))(iVar2,iVar5,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0046fa5f
// Address: 0046fa5f
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046fa5f(RGE_Player *param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  RGE_Master_Static_Object **ppRVar3;
  RGE_Visible_Map *pRVar4;
  Visible_Resource_Manager *pVVar5;
  RGE_Object_List *pRVar6;
  short sVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_2;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e307;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  psVar1 = &param_1->master_object_num;
  rge_read(param_2,psVar1,2);
  sVar7 = 0;
  if (*psVar1 < 1) {
    param_1->master_objects = (RGE_Master_Static_Object **)0x0;
  }
  else {
    ppRVar3 = (RGE_Master_Static_Object **)calloc((int)*psVar1,4);
    param_1->master_objects = ppRVar3;
    rge_read(iVar2,ppRVar3,(int)*psVar1 << 2);
    if (0 < *psVar1) {
      do {
        if (param_1->master_objects[sVar7] != (RGE_Master_Static_Object *)0x0) {
          rge_read(iVar2,&param_2,1);
          RGE_Player::load_master_object
                    (param_1,iVar2,sVar7,(uchar)param_2,param_1->world->sprites,
                     param_1->world->sounds);
        }
        sVar7 = sVar7 + 1;
      } while (sVar7 < *psVar1);
    }
  }
  pRVar4 = (RGE_Visible_Map *)operator_new(0x38);
  uStack_4 = 0;
  if (pRVar4 == (RGE_Visible_Map *)0x0) {
    pRVar4 = (RGE_Visible_Map *)0x0;
  }
  else {
    pRVar4 = (RGE_Visible_Map *)RGE_Visible_Map::RGE_Visible_Map(pRVar4,iVar2,param_1->world);
  }
  uStack_4 = 0xffffffff;
  param_1->visible = pRVar4;
  pVVar5 = (Visible_Resource_Manager *)operator_new(0x14);
  uStack_4 = 1;
  if (pVVar5 == (Visible_Resource_Manager *)0x0) {
    pVVar5 = (Visible_Resource_Manager *)0x0;
  }
  else {
    pVVar5 = (Visible_Resource_Manager *)
             Visible_Resource_Manager::Visible_Resource_Manager(pVVar5,iVar2,param_1);
  }
  uStack_4 = 0xffffffff;
  param_1->VR_List = pVVar5;
  pRVar6 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 2;
  if (pRVar6 == (RGE_Object_List *)0x0) {
    pRVar6 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar6 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar6);
  }
  uStack_4 = 0xffffffff;
  param_1->objects = pRVar6;
  RGE_Object_List::load_list(pRVar6,iVar2,param_1->world);
  pRVar6 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 3;
  if (pRVar6 == (RGE_Object_List *)0x0) {
    pRVar6 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar6 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar6);
  }
  uStack_4 = 0xffffffff;
  param_1->sleeping_objects = pRVar6;
  pRVar6 = (RGE_Object_List *)operator_new(0xc);
  uStack_4 = 4;
  if (pRVar6 == (RGE_Object_List *)0x0) {
    pRVar6 = (RGE_Object_List *)0x0;
  }
  else {
    pRVar6 = (RGE_Object_List *)RGE_Object_List::RGE_Object_List(pRVar6);
  }
  uStack_4 = 0xffffffff;
  param_1->doppleganger_objects = pRVar6;
  RGE_Object_List::load_list(param_1->sleeping_objects,iVar2,param_1->world);
  if (_DAT_00570ec0 <= save_game_version) {
    RGE_Object_List::load_list(param_1->doppleganger_objects,iVar2,param_1->world);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0046fc3b
// Address: 0046fc3b
void __thiscall
FUN_0046fc3b(int param_1,int param_2,short param_3,undefined1 param_4,RGE_Sprite **param_5,
            RGE_Sound **param_6)
{
  RGE_Master_Static_Object *this;
  RGE_Master_Animated_Object *this_00;
  RGE_Master_Moving_Object *this_01;
  RGE_Master_Missile_Object *this_02;
  undefined4 uVar1;
  RGE_Master_Action_Object *this_03;
  RGE_Master_Combat_Object *this_04;
  RGE_Master_Doppleganger_Object *this_05;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e36d;
  *unaff_FS_OFFSET = &uStack_c;
  switch(param_4) {
  case 10:
    this = (RGE_Master_Static_Object *)operator_new(0xb8);
    uStack_4 = 0;
    if (this == (RGE_Master_Static_Object *)0x0) {
LAB_0046fe8a:
      uVar1 = 0;
    }
    else {
      uVar1 = RGE_Master_Static_Object::RGE_Master_Static_Object(this,param_2,param_5,param_6,1);
    }
    break;
  default:
    goto switchD_0046fc75_caseD_b;
  case 0x14:
    this_00 = (RGE_Master_Animated_Object *)operator_new(0xbc);
    uStack_4 = 1;
    if (this_00 != (RGE_Master_Animated_Object *)0x0) {
      uVar1 = RGE_Master_Animated_Object::RGE_Master_Animated_Object
                        (this_00,param_2,param_5,param_6,1);
      *(undefined4 *)(*(int *)(param_1 + 0x24) + param_3 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    goto LAB_0046fe34;
  case 0x19:
    this_05 = (RGE_Master_Doppleganger_Object *)operator_new(0xbc);
    uStack_4 = 6;
    if (this_05 == (RGE_Master_Doppleganger_Object *)0x0) goto LAB_0046fe8a;
    uVar1 = RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object
                      (this_05,param_2,param_5,param_6,1);
    break;
  case 0x1e:
    this_01 = (RGE_Master_Moving_Object *)operator_new(0xd8);
    uStack_4 = 2;
    if (this_01 == (RGE_Master_Moving_Object *)0x0) goto LAB_0046fe8a;
    uVar1 = RGE_Master_Moving_Object::RGE_Master_Moving_Object(this_01,param_2,param_5,param_6,1);
    break;
  case 0x28:
    this_03 = (RGE_Master_Action_Object *)operator_new(0xfc);
    uStack_4 = 4;
    if (this_03 == (RGE_Master_Action_Object *)0x0) goto LAB_0046fe8a;
    uVar1 = RGE_Master_Action_Object::RGE_Master_Action_Object(this_03,param_2,param_5,param_6,1);
    break;
  case 0x32:
    this_04 = (RGE_Master_Combat_Object *)operator_new(0x148);
    uStack_4 = 5;
    if (this_04 != (RGE_Master_Combat_Object *)0x0) {
      uVar1 = RGE_Master_Combat_Object::RGE_Master_Combat_Object(this_04,param_2,param_5,param_6,1);
      *(undefined4 *)(*(int *)(param_1 + 0x24) + param_3 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    goto LAB_0046fe34;
  case 0x3c:
    this_02 = (RGE_Master_Missile_Object *)operator_new(0x154);
    uStack_4 = 3;
    if (this_02 != (RGE_Master_Missile_Object *)0x0) {
      uVar1 = RGE_Master_Missile_Object::RGE_Master_Missile_Object
                        (this_02,param_2,param_5,param_6,1);
      *(undefined4 *)(*(int *)(param_1 + 0x24) + param_3 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
LAB_0046fe34:
    *(undefined4 *)(*(int *)(param_1 + 0x24) + param_3 * 4) = 0;
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x24) + param_3 * 4) = uVar1;
switchD_0046fc75_caseD_b:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0046fea9
// Address: 0046fea9
void __fastcall FUN_0046fea9(undefined4 param_1,int param_2)
{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  int in_EAX;
  int *piVar4;
  byte unaff_BH;
  int unaff_EBP;
  char *unaff_ESI;
  int *unaff_EDI;
  char in_SF;
  char in_OF;
  undefined4 uStack00000078;
  undefined4 uStack0000007c;
  undefined4 uStack00000080;
  undefined4 uStack00000084;
  char *pcStack00000088;
  undefined4 in_stack_00000090;
  
  do {
  } while (in_OF != in_SF);
  pbVar1 = (byte *)(param_2 + 0x530046fc);
  bVar3 = *pbVar1;
  *pbVar1 = *pbVar1 + unaff_BH;
  unaff_ESI[1] = unaff_ESI[1] + '\x01';
  piVar4 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),
                           CONCAT11((char)((uint)param_1 >> 8) + unaff_BH + CARRY1(bVar3,unaff_BH),
                                    (char)param_1));
  pcVar2 = (char *)(unaff_EBP + -0x21dffba + (int)unaff_EDI * 8);
  *pcVar2 = *pcVar2 + (char)((uint)in_EAX >> 8);
  *unaff_ESI = *unaff_ESI + (char)param_1;
  pcStack00000088 = unaff_ESI + 4;
  *(char *)((int)unaff_EDI + 0x46fe) = *(char *)((int)unaff_EDI + 0x46fe) + (char)param_2;
  *unaff_EDI = *unaff_EDI + in_EAX;
  uStack00000084 = 1;
  uStack00000080 = 0;
  uStack0000007c = in_stack_00000090;
  uStack00000078 = 0x46ff16;
  (**(code **)(*piVar4 + 0xf0))();
  uStack00000078 = 0x46ff1e;
  RGE_Object_List::rehook_list((RGE_Object_List *)piVar4[10]);
  uStack00000078 = 0x46ff26;
  RGE_Object_List::rehook_list((RGE_Object_List *)piVar4[0xb]);
  uStack00000078 = 0x46ff2e;
  RGE_Object_List::rehook_list((RGE_Object_List *)piVar4[0xc]);
  return;
}

// --------------------------------------------------

// Function: FUN_0046ff32
// Address: 0046ff32
long __fastcall FUN_0046ff32(RGE_Player *param_1)
{
  if (param_1->checksum_created_this_update == '\0') {
    RGE_Player::create_checksum(param_1);
  }
  return param_1->checksum;
}

// --------------------------------------------------

// Function: FUN_0046ff54
// Address: 0046ff54
undefined4 __thiscall FUN_0046ff54(RGE_Player *param_1,long *param_2,long *param_3,long *param_4)
{
  if (param_1->checksum_created_this_update == '\0') {
    RGE_Player::create_checksum(param_1);
  }
  *param_2 = param_1->checksum;
  *param_3 = param_1->position_checksum;
  *param_4 = param_1->action_checksum;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004700a5
// Address: 004700a5
void __thiscall FUN_004700a5(int param_1,short param_2,undefined4 param_3)
{
  if ((-1 < param_2) && (param_2 < *(short *)(param_1 + 0x4c))) {
    *(undefined4 *)(*(int *)(param_1 + 0x50) + param_2 * 4) = param_3;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004700f5
// Address: 004700f5
void __thiscall FUN_004700f5(int param_1,short param_2,uchar param_3)
{
  RGE_Master_Static_Object *this;
  
  this = *(RGE_Master_Static_Object **)(*(int *)(param_1 + 0x24) + param_2 * 4);
  if (this != (RGE_Master_Static_Object *)0x0) {
    RGE_Master_Static_Object::make_available(this,param_3);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047011c
// Address: 0047011c
void __fastcall FUN_0047011c(RGE_Player *param_1)
{
  uchar uVar1;
  
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  param_1->currentUpdatePathingAttemptsValue = 0;
  RGE_Object_List::update(param_1->objects);
  RGE_Player::update_selected(param_1);
  uVar1 = RGE_Victory_Conditions::update(param_1->victory_conditions);
  if (uVar1 == '\x01') {
    (**(code **)(param_1->_padding_ + 4))(2);
  }
  param_1->checksum_created_this_update = '\0';
  if (param_1->VR_List != (Visible_Resource_Manager *)0x0) {
    Visible_Resource_Manager::Process_New_Tiles(param_1->VR_List,&param_1->tile_list);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470176
// Address: 00470176
void __fastcall FUN_00470176(int param_1)
{
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  RGE_Object_List::update(*(RGE_Object_List **)(param_1 + 0x30));
  RGE_Doppleganger_Creator::perform_doppleganger_checks
            (*(RGE_Doppleganger_Creator **)(param_1 + 0x40));
  return;
}

// --------------------------------------------------

// Function: FUN_004701a4
// Address: 004701a4
void __thiscall FUN_004701a4(int param_1,int param_2)
{
  char cVar1;
  short sVar2;
  char *pcVar3;
  undefined1 uStack_5;
  uint uStack_4;
  
  color_log('2','2',3);
  rge_write(param_2,(void *)(param_1 + 0x48),1);
  rge_write(param_2,*(void **)(param_1 + 0x84),(int)*(short *)(*(int *)(param_1 + 0x3c) + 0x3c));
  rge_write(param_2,(void *)(param_1 + 0x88),0x24);
  rge_write(param_2,(void *)(param_1 + 0x100),4);
  rge_write(param_2,(void *)(param_1 + 0x104),1);
  uStack_4 = 0xffffffff;
  pcVar3 = *(char **)(param_1 + 0x44);
  do {
    if (uStack_4 == 0) break;
    uStack_4 = uStack_4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uStack_4 = ~uStack_4;
  rge_write(param_2,&uStack_4,2);
  if (0 < (short)uStack_4) {
    rge_write(param_2,*(void **)(param_1 + 0x44),(int)(short)uStack_4);
  }
  rge_write(param_2,(short *)(param_1 + 0x4c),2);
  sVar2 = *(short *)(param_1 + 0x4c);
  if (0 < sVar2) {
    rge_write(param_2,*(void **)(param_1 + 0x50),(int)sVar2 << 2);
  }
  rge_write(param_2,(void *)(param_1 + 0x114),4);
  rge_write(param_2,(void *)(param_1 + 0x118),4);
  rge_write(param_2,(void *)(param_1 + 0x11c),2);
  rge_write(param_2,(void *)(param_1 + 0x11e),2);
  rge_write(param_2,(void *)(param_1 + 0x54),1);
  rge_write(param_2,(void *)(param_1 + 0x105),1);
  rge_write(param_2,(void *)(param_1 + 0x80),1);
  rge_write(param_2,(void *)(param_1 + 0x81),1);
  if (*(int *)(param_1 + 0x108) == 0) {
    uStack_5 = 0;
  }
  else {
    uStack_5 = *(undefined1 *)(*(int *)(param_1 + 0x108) + 0x26);
  }
  rge_write(param_2,&uStack_5,1);
  rge_write(param_2,(void *)(param_1 + 8),4);
  rge_write(param_2,(void *)(param_1 + 0xc),4);
  color_log('2','_',3);
  return;
}

// --------------------------------------------------

// Function: FUN_00470376
// Address: 00470376
void __thiscall FUN_00470376(int param_1,int param_2)
{
  short *psVar1;
  int *piVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  
  color_log('L','L',4);
  iVar3 = param_2;
  psVar1 = (short *)(param_1 + 0x22);
  rge_write(param_2,psVar1,2);
  if (0 < *psVar1) {
    iVar5 = 0;
    if (0 < *psVar1) {
      do {
        param_2 = *(int *)(*(int *)(param_1 + 0x24) + iVar5 * 4);
        if (param_2 != 0) {
          param_2 = 1;
        }
        rge_write(iVar3,&param_2,4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < *psVar1);
    }
    sVar4 = 0;
    if (0 < *psVar1) {
      do {
        piVar2 = *(int **)(*(int *)(param_1 + 0x24) + sVar4 * 4);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x14))(iVar3);
        }
        sVar4 = sVar4 + 1;
      } while (sVar4 < *psVar1);
    }
  }
  color_log('L','$',4);
  RGE_Visible_Map::save(*(RGE_Visible_Map **)(param_1 + 0x38),iVar3);
  Visible_Resource_Manager::save(*(Visible_Resource_Manager **)(param_1 + 0x110),iVar3);
  color_log('L','\x16',4);
  RGE_Object_List::save(*(RGE_Object_List **)(param_1 + 0x28),iVar3);
  color_log('L','2',4);
  RGE_Object_List::save(*(RGE_Object_List **)(param_1 + 0x2c),iVar3);
  color_log('L','2',4);
  RGE_Object_List::save(*(RGE_Object_List **)(param_1 + 0x30),iVar3);
  color_log('L','_',4);
  return;
}

// --------------------------------------------------

// Function: FUN_00470485
// Address: 00470485
void __thiscall FUN_00470485(int param_1,undefined4 param_2)
{
  (**(code **)(**(int **)(param_1 + 0x34) + 0xc))(param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_004704bb
// Address: 004704bb
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004704bb(int param_1,float param_2,float param_3)
{
  bool bVar1;
  float fVar2;
  
  bVar1 = _DAT_00570ec4 <= param_2;
  *(float *)(param_1 + 0x114) = param_2;
  *(float *)(param_1 + 0x118) = param_3;
  if (bVar1) {
    fVar2 = (float)(*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x28) + 8) + -1);
    if (fVar2 < param_2) {
      *(float *)(param_1 + 0x114) = fVar2;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  if (_DAT_00570ec4 <= param_3) {
    fVar2 = (float)(*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x28) + 0xc) + -1);
    if (param_3 <= fVar2) {
      return;
    }
    *(float *)(param_1 + 0x118) = fVar2;
    return;
  }
  *(undefined4 *)(param_1 + 0x118) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00470563
// Address: 00470563
void FUN_00470563(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00470571
// Address: 00470571
void __fastcall FUN_00470571(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x28) + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    (**(code **)(*(int *)*puVar1 + 0x68))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047059b
// Address: 0047059b
void __thiscall FUN_0047059b(int param_1,uint param_2)
{
  *(undefined4 *)(param_1 + 0x108) =
       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x3c) + 100) + (param_2 & 0xff) * 4);
  return;
}

// --------------------------------------------------

// Function: FUN_004705bb
// Address: 004705bb
void __fastcall FUN_004705bb(int *param_1)
{
  if ((char)param_1[0x20] == '\0') {
    (**(code **)(*param_1 + 4))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004705d2
// Address: 004705d2
void __fastcall FUN_004705d2(int *param_1)
{
  if ((char)param_1[0x20] == '\0') {
    (**(code **)(*param_1 + 4))(2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004705f2
// Address: 004705f2
void __fastcall FUN_004705f2(RGE_Player *param_1)
{
  RGE_Player *this;
  uchar uVar1;
  int iVar2;
  
  RGE_Player::victory_if_game_on(param_1);
  iVar2 = 1;
  if (1 < param_1->world->player_num) {
    do {
      if (iVar2 != param_1->id) {
        if (param_1->allied_victory != '\0') {
          uVar1 = RGE_Player::relation(param_1,iVar2);
          if (uVar1 == '\0') {
            uVar1 = RGE_Player::relation(param_1->world->players[iVar2],(int)param_1->id);
            if ((uVar1 == '\0') &&
               (this = param_1->world->players[iVar2], this->allied_victory != '\0')) {
              RGE_Player::victory_if_game_on(this);
              goto LAB_00470674;
            }
          }
        }
        RGE_Player::loss_if_game_on(param_1->world->players[iVar2]);
      }
LAB_00470674:
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1->world->player_num);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470683
// Address: 00470683
uchar __fastcall FUN_00470683(int param_1)
{
  uchar uVar1;
  
  if (*(char *)(param_1 + 0x80) != '\x02') {
    uVar1 = RGE_Victory_Conditions::victory_achieved(*(RGE_Victory_Conditions **)(param_1 + 0x34));
    return uVar1;
  }
  return '\x01';
}

// --------------------------------------------------

// Function: FUN_004706a4
// Address: 004706a4
undefined4 __thiscall FUN_004706a4(int param_1,int *param_2)
{
  int iVar1;
  uchar uVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  
  iVar1 = *param_2;
  uVar4 = 1;
  if (*(char *)(param_1 + 0x80) != '\x02') {
    *param_2 = 0;
    iVar3 = *(int *)(param_1 + 0x3c);
    iVar5 = 1;
    if (1 < *(short *)(iVar3 + 0x3c)) {
      do {
        if ((*(char *)(iVar5 + *(int *)(param_1 + 0x84)) == '\0') &&
           ((uVar2 = RGE_Player::relation
                               (*(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar5 * 4),
                                (int)*(short *)(param_1 + 0x4a)), uVar2 != '\0' ||
            (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x40) + iVar5 * 4) + 0x104) ==
             '\0')))) {
          uVar4 = 0;
          break;
        }
        iVar5 = iVar5 + 1;
        *param_2 = *param_2 + 1;
        iVar3 = *(int *)(param_1 + 0x3c);
      } while (iVar5 < *(short *)(iVar3 + 0x3c));
    }
  }
  if ((-1 < iVar1) && (*param_2 != iVar1)) {
    uVar4 = 0;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),uVar4);
}

// --------------------------------------------------

// Function: FUN_00470744
// Address: 00470744
undefined1 __fastcall FUN_00470744(int *param_1)
{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  long lStack_4;
  
  lStack_4 = -1;
  if (((char)param_1[0x20] != '\x02') &&
     (uVar2 = RGE_Victory_Conditions::victory_achieved((RGE_Victory_Conditions *)param_1[0xd]),
     uVar2 != '\0')) {
    bVar1 = false;
    if ((char)param_1[0x41] != '\0') {
      iVar3 = param_1[0xf];
      iVar4 = 1;
      if (1 < *(short *)(iVar3 + 0x3c)) {
        do {
          if (((iVar4 == *(short *)((int)param_1 + 0x4a)) ||
              (*(char *)(param_1[0x21] + iVar4) == '\0')) &&
             (uVar2 = RGE_Player::check_ally_group
                                (*(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar4 * 4),&lStack_4),
             uVar2 == '\0')) {
            bVar1 = true;
            break;
          }
          iVar3 = param_1[0xf];
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(short *)(iVar3 + 0x3c));
      }
      if ((char)param_1[0x41] != '\0') {
        if (bVar1) goto LAB_0047082c;
        iVar3 = param_1[0xf];
        iVar4 = 1;
        if (1 < *(short *)(iVar3 + 0x3c)) {
          do {
            if ((*(char *)(iVar4 + param_1[0x21]) == '\0') &&
               (uVar2 = RGE_Player::check_victory_conditions
                                  (*(RGE_Player **)(*(int *)(iVar3 + 0x40) + iVar4 * 4)),
               uVar2 == '\0')) {
              bVar1 = true;
              break;
            }
            iVar3 = param_1[0xf];
            iVar4 = iVar4 + 1;
          } while (iVar4 < *(short *)(iVar3 + 0x3c));
        }
      }
    }
    if (!bVar1) {
      (**(code **)(*param_1 + 4))(1);
      *(undefined1 *)(param_1[0xf] + 0x1e) = 2;
    }
  }
LAB_0047082c:
  return (char)param_1[0x20];
}

// --------------------------------------------------

// Function: FUN_00470837
// Address: 00470837
void __thiscall
FUN_00470837(int param_1,short param_2,short param_3,undefined4 param_4,undefined4 param_5)
{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 < 0) {
    if ((-1 < param_3) && (sVar2 = 0, 0 < *(short *)(param_1 + 0x22))) {
      do {
        iVar3 = sVar2 * 4;
        iVar4 = *(int *)(*(int *)(param_1 + 0x24) + iVar3);
        if ((iVar4 != 0) && (*(short *)(iVar4 + 0x14) == param_3)) {
          if (*(int *)(param_1 + 0x28) != 0) {
            for (piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar1 != (int *)0x0;
                piVar1 = (int *)piVar1[1]) {
              if (((int *)*piVar1)[2] == *(int *)(*(int *)(param_1 + 0x24) + iVar3)) {
                (**(code **)(*(int *)*piVar1 + 0x48))(param_4,param_5);
              }
            }
          }
          (**(code **)(**(int **)(*(int *)(param_1 + 0x24) + iVar3) + 8))(param_4,param_5);
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < *(short *)(param_1 + 0x22));
    }
  }
  else {
    iVar4 = param_2 * 4;
    if (*(int *)(*(int *)(param_1 + 0x24) + iVar4) != 0) {
      if (*(int *)(param_1 + 0x28) != 0) {
        for (piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar1 != (int *)0x0;
            piVar1 = (int *)piVar1[1]) {
          if (((int *)*piVar1)[2] == *(int *)(*(int *)(param_1 + 0x24) + iVar4)) {
            (**(code **)(*(int *)*piVar1 + 0x48))(param_4,param_5);
          }
        }
      }
      (**(code **)(**(int **)(*(int *)(param_1 + 0x24) + iVar4) + 8))(param_4,param_5);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470933
// Address: 00470933
void __thiscall
FUN_00470933(int param_1,short param_2,short param_3,undefined4 param_4,undefined4 param_5)
{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 < 0) {
    if ((-1 < param_3) && (sVar2 = 0, 0 < *(short *)(param_1 + 0x22))) {
      do {
        iVar3 = sVar2 * 4;
        iVar4 = *(int *)(*(int *)(param_1 + 0x24) + iVar3);
        if ((iVar4 != 0) && (*(short *)(iVar4 + 0x14) == param_3)) {
          if (*(int *)(param_1 + 0x28) != 0) {
            for (piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar1 != (int *)0x0;
                piVar1 = (int *)piVar1[1]) {
              if (((int *)*piVar1)[2] == *(int *)(*(int *)(param_1 + 0x24) + iVar3)) {
                (**(code **)(*(int *)*piVar1 + 0x4c))(param_4,param_5);
              }
            }
          }
          (**(code **)(**(int **)(*(int *)(param_1 + 0x24) + iVar3) + 0xc))(param_4,param_5);
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < *(short *)(param_1 + 0x22));
    }
  }
  else {
    iVar4 = param_2 * 4;
    if (*(int *)(*(int *)(param_1 + 0x24) + iVar4) != 0) {
      if (*(int *)(param_1 + 0x28) != 0) {
        for (piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar1 != (int *)0x0;
            piVar1 = (int *)piVar1[1]) {
          if (((int *)*piVar1)[2] == *(int *)(*(int *)(param_1 + 0x24) + iVar4)) {
            (**(code **)(*(int *)*piVar1 + 0x4c))(param_4,param_5);
          }
        }
      }
      (**(code **)(**(int **)(*(int *)(param_1 + 0x24) + iVar4) + 0xc))(param_4,param_5);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470a33
// Address: 00470a33
void __thiscall
FUN_00470a33(int param_1,short param_2,short param_3,undefined4 param_4,undefined4 param_5)
{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 < 0) {
    if ((-1 < param_3) && (sVar2 = 0, 0 < *(short *)(param_1 + 0x22))) {
      do {
        iVar3 = sVar2 * 4;
        iVar4 = *(int *)(*(int *)(param_1 + 0x24) + iVar3);
        if ((iVar4 != 0) && (*(short *)(iVar4 + 0x14) == param_3)) {
          if (*(int *)(param_1 + 0x28) != 0) {
            for (piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar1 != (int *)0x0;
                piVar1 = (int *)piVar1[1]) {
              if (((int *)*piVar1)[2] == *(int *)(*(int *)(param_1 + 0x24) + iVar3)) {
                (**(code **)(*(int *)*piVar1 + 0x50))(param_4,param_5);
              }
            }
          }
          (**(code **)(**(int **)(*(int *)(param_1 + 0x24) + iVar3) + 0x10))(param_4,param_5);
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < *(short *)(param_1 + 0x22));
    }
  }
  else {
    iVar4 = param_2 * 4;
    if (*(int *)(*(int *)(param_1 + 0x24) + iVar4) != 0) {
      if (*(int *)(param_1 + 0x28) != 0) {
        for (piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar1 != (int *)0x0;
            piVar1 = (int *)piVar1[1]) {
          if (((int *)*piVar1)[2] == *(int *)(*(int *)(param_1 + 0x24) + iVar4)) {
            (**(code **)(*(int *)*piVar1 + 0x50))(param_4,param_5);
          }
        }
      }
      (**(code **)(**(int **)(*(int *)(param_1 + 0x24) + iVar4) + 0x10))(param_4,param_5);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470b33
// Address: 00470b33
void __thiscall FUN_00470b33(int param_1,short param_2,short param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2 * 4;
  if ((*(int *)(*(int *)(param_1 + 0x24) + iVar3) != 0) &&
     (iVar2 = param_3 * 4, *(int *)(iVar2 + *(int *)(param_1 + 0x24)) != 0)) {
    if (*(int *)(param_1 + 0x28) != 0) {
      for (piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar1 != (int *)0x0;
          piVar1 = (int *)piVar1[1]) {
        if (((int *)*piVar1)[2] == *(int *)(*(int *)(param_1 + 0x24) + iVar3)) {
          (**(code **)(*(int *)*piVar1 + 0x58))(*(undefined4 *)(iVar2 + *(int *)(param_1 + 0x24)));
        }
      }
    }
    (**(code **)(**(int **)(*(int *)(param_1 + 0x24) + iVar3) + 4))
              (*(undefined4 *)(iVar2 + *(int *)(param_1 + 0x24)));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470ba9
// Address: 00470ba9
void __thiscall FUN_00470ba9(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x104) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00470bbd
// Address: 00470bbd
undefined1 __fastcall FUN_00470bbd(int param_1)
{
  return *(undefined1 *)(param_1 + 0x104);
}

// --------------------------------------------------

// Function: FUN_00470bc7
// Address: 00470bc7
undefined4 __thiscall FUN_00470bc7(int param_1,int param_2)
{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x84) >> 8),
                  *(undefined1 *)(*(int *)(param_1 + 0x84) + param_2));
}

// --------------------------------------------------

// Function: FUN_00470c66
// Address: 00470c66
undefined4 __thiscall
FUN_00470c66(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int *piVar1;
  undefined4 uVar2;
  
  if ((-1 < param_2) &&
     (piVar1 = *(int **)(*(int *)(param_1 + 0x24) + param_2 * 4), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x18))(param_1,param_3,param_4,param_5);
    return uVar2;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00470ca4
// Address: 00470ca4
void __fastcall FUN_00470ca4(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined2 *)(param_1 + 0x120) = 0xffff;
  *(undefined2 *)(param_1 + 0x122) = 0xffff;
  *(undefined2 *)(param_1 + 0x124) = 0xffff;
  *(undefined2 *)(param_1 + 0x126) = 0xffff;
  *(undefined2 *)(param_1 + 0x128) = 0xffff;
  *(undefined2 *)(param_1 + 0x12a) = 0xffff;
  *(undefined2 *)(param_1 + 300) = 0xffff;
  *(undefined2 *)(param_1 + 0x19c) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x134);
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)(param_1 + 0x19e);
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00470d15
// Address: 00470d15
undefined4 __thiscall FUN_00470d15(RGE_Player *param_1,RGE_Static_Object *param_2)
{
  byte bVar1;
  RGE_Object_Node *pRVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  
  iVar4 = RGE_Player::select_one_object(param_1,param_2,1);
  if (iVar4 == 0) {
    return 0;
  }
  bVar1 = param_2->selected_group;
  if (10 < bVar1) {
    pRVar2 = param_1->objects->list;
    while ((pRVar2 != (RGE_Object_Node *)0x0 &&
           (((pRVar3 = pRVar2->node, pRVar3 == param_2 || (pRVar3->selected_group != bVar1)) ||
            (iVar4 = RGE_Player::select_one_object(param_1,pRVar3,0), iVar4 != 0))))) {
      pRVar2 = pRVar2->next;
    }
  }
  param_1->selected_obj = param_2;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00470d7f
// Address: 00470d7f
undefined4 __thiscall FUN_00470d7f(int param_1,int param_2,int param_3)
{
  short sVar1;
  RGE_Sound *this;
  short sVar2;
  short sVar3;
  
  sVar1 = *(short *)(param_1 + 0x19c);
  if (sVar1 < 0x19) {
    sVar3 = sVar1;
    if ((*(int *)(param_1 + 0x134 + sVar1 * 4) != 0) && (sVar2 = 0, sVar3 = -1, 0 < sVar1)) {
      do {
        sVar3 = sVar2;
        if (*(int *)(param_1 + 0x134 + sVar2 * 4) == 0) break;
        sVar2 = sVar2 + 1;
        sVar3 = -1;
      } while (sVar2 < sVar1);
    }
    if (sVar3 != -1) {
      *(int *)(param_1 + 0x134 + sVar3 * 4) = param_2;
      *(short *)(param_1 + 0x19c) = *(short *)(param_1 + 0x19c) + 1;
      *(int *)(param_1 + 0x130) = param_2;
      *(undefined1 *)(param_2 + 0x36) = 1;
      if (((param_3 != 0) &&
          (this = *(RGE_Sound **)(*(int *)(param_2 + 8) + 0x3c), this != (RGE_Sound *)0x0)) &&
         ((*(int *)(param_2 + 0xc) == param_1 || (*(short *)(*(int *)(param_2 + 0xc) + 0x4a) == 0)))
         ) {
        RGE_Sound::play(this,1);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00470e29
// Address: 00470e29
void __fastcall FUN_00470e29(int param_1)
{
  int iVar1;
  short sVar2;
  short sVar3;
  
  if (0 < *(short *)(param_1 + 0x19c)) {
    sVar2 = 0;
    *(undefined4 *)(param_1 + 0x130) = 0;
    sVar3 = 0;
    do {
      if (*(short *)(param_1 + 0x19c) <= sVar3) break;
      iVar1 = *(int *)(param_1 + 0x134 + sVar2 * 4);
      if (iVar1 != 0) {
        *(undefined1 *)(iVar1 + 0x36) = 0;
        sVar3 = sVar3 + 1;
        *(undefined4 *)(param_1 + 0x134 + sVar2 * 4) = 0;
      }
      sVar2 = sVar2 + 1;
    } while (sVar2 < 0x19);
    *(undefined2 *)(param_1 + 0x19c) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470e7e
// Address: 00470e7e
void __thiscall FUN_00470e7e(RGE_Player *param_1,RGE_Static_Object *param_2)
{
  short sVar1;
  short sVar2;
  
  if (0 < param_1->sel_count) {
    sVar1 = 0;
    sVar2 = 0;
    while (sVar2 < param_1->sel_count) {
      if (param_1->sel_list[sVar1] != (RGE_Static_Object *)0x0) {
        if (param_1->sel_list[sVar1] == param_2) {
          RGE_Player::unselect_one_object(param_1,sVar1);
          return;
        }
        sVar2 = sVar2 + 1;
      }
      sVar1 = sVar1 + 1;
      if (0x18 < sVar1) {
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470ec8
// Address: 00470ec8
void __thiscall FUN_00470ec8(int param_1,short param_2)
{
  int iVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = (int)param_2;
  iVar1 = *(int *)(param_1 + 0x134 + iVar3 * 4);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x36) = 0;
    if (iVar3 < *(short *)(param_1 + 0x19c) + -1) {
      *(undefined4 *)(param_1 + 0x134 + iVar3 * 4) =
           *(undefined4 *)(param_1 + 0x130 + *(short *)(param_1 + 0x19c) * 4);
      *(undefined4 *)(param_1 + 0x130 + *(short *)(param_1 + 0x19c) * 4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x134 + iVar3 * 4) = 0;
    }
    *(short *)(param_1 + 0x19c) = *(short *)(param_1 + 0x19c) + -1;
    if ((*(int *)(param_1 + 0x130) == iVar1) &&
       (*(undefined4 *)(param_1 + 0x130) = 0, 0 < *(short *)(param_1 + 0x19c))) {
      sVar2 = 0;
      while (*(int *)(param_1 + 0x134 + sVar2 * 4) == 0) {
        sVar2 = sVar2 + 1;
        if (0x18 < sVar2) {
          return;
        }
      }
      *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(param_1 + 0x134 + sVar2 * 4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00470f73
// Address: 00470f73
undefined4 __thiscall FUN_00470f73(int param_1,uint param_2)
{
  byte bVar1;
  int *piVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  undefined4 *puVar6;
  
  if (*(short *)(param_1 + 0x19c) == 0) {
    return 0;
  }
  if (param_2 == -1) {
    sVar4 = 0xb;
    do {
      if (*(char *)(param_1 + 0x19e + (int)sVar4) == '\0') {
        param_2._0_1_ = (byte)sVar4;
        *(undefined1 *)(param_1 + 0x19e + (int)sVar4) = 1;
        break;
      }
      sVar4 = sVar4 + 1;
    } while (sVar4 < 0x7f);
    if (sVar4 == 0x7f) {
      puVar6 = (undefined4 *)(param_1 + 0x19f);
      for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *(undefined2 *)puVar6 = 0;
      for (piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar2 != (int *)0x0;
          piVar2 = (int *)piVar2[1]) {
        bVar1 = *(byte *)(*piVar2 + 0x37);
        param_2 = (uint)bVar1;
        if ((bVar1 != 0) && (*(char *)(param_1 + 0x19e + param_2) == '\0')) {
          *(undefined1 *)(param_1 + 0x19e + param_2) = 1;
        }
        param_2._0_1_ = bVar1;
      }
      sVar4 = 1;
      do {
        if (*(char *)(param_1 + 0x19e + (int)sVar4) == '\0') {
          param_2._0_1_ = (byte)sVar4;
          *(undefined1 *)(param_1 + 0x19e + (int)sVar4) = 1;
          break;
        }
        sVar4 = sVar4 + 1;
      } while (sVar4 < 0x7f);
      if (sVar4 == 0x7f) {
        return 0;
      }
    }
  }
  else {
    for (piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 4); piVar2 != (int *)0x0;
        piVar2 = (int *)piVar2[1]) {
      if (*(byte *)(*piVar2 + 0x37) == (byte)param_2) {
        *(undefined1 *)(*piVar2 + 0x37) = 0;
      }
    }
  }
  sVar4 = 0;
  sVar5 = 0;
  do {
    if (*(short *)(param_1 + 0x19c) <= sVar5) {
      return 1;
    }
    iVar3 = *(int *)(param_1 + 0x134 + sVar4 * 4);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0xc) == param_1)) {
      sVar5 = sVar5 + 1;
      *(byte *)(iVar3 + 0x37) = (byte)param_2;
    }
    sVar4 = sVar4 + 1;
  } while (sVar4 < 0x19);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004710b1
// Address: 004710b1
bool __thiscall FUN_004710b1(RGE_Player *param_1,uchar param_2)
{
  RGE_Object_Node *pRVar1;
  RGE_Static_Object *pRVar2;
  bool bVar3;
  int iVar4;
  
  bVar3 = true;
  for (pRVar1 = param_1->objects->list; pRVar1 != (RGE_Object_Node *)0x0; pRVar1 = pRVar1->next) {
    pRVar2 = pRVar1->node;
    if (pRVar2->selected_group == param_2) {
      if (bVar3) {
        iVar4 = RGE_Player::select_one_object(param_1,pRVar2,1);
        if (iVar4 == 0) break;
        bVar3 = false;
      }
      else {
        iVar4 = RGE_Player::select_one_object(param_1,pRVar2,0);
        if (iVar4 == 0) break;
      }
    }
  }
  return !bVar3;
}

// --------------------------------------------------

// Function: FUN_00471119
// Address: 00471119
undefined4 __fastcall FUN_00471119(int param_1)
{
  int iVar1;
  short sVar2;
  short sVar3;
  
  sVar2 = 0;
  sVar3 = 0;
  do {
    if (*(short *)(param_1 + 0x19c) <= sVar3) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x134 + sVar2 * 4);
    if (iVar1 != 0) {
      sVar3 = sVar3 + 1;
      if (*(int *)(iVar1 + 0xc) == param_1) {
        return 1;
      }
    }
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x19);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00471165
// Address: 00471165
undefined4 __thiscall FUN_00471165(int param_1,short param_2)
{
  int iVar1;
  short sVar2;
  short sVar3;
  
  sVar2 = 0;
  sVar3 = 0;
  do {
    if (*(short *)(param_1 + 0x19c) <= sVar3) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x134 + sVar2 * 4);
    if (iVar1 != 0) {
      sVar3 = sVar3 + 1;
      if (*(short *)(*(int *)(iVar1 + 8) + 0x10) == param_2) {
        return 1;
      }
    }
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x19);
  return 0;
}

// --------------------------------------------------

// Function: FUN_004711c2
// Address: 004711c2
undefined4 __thiscall FUN_004711c2(int param_1,short param_2)
{
  int iVar1;
  short sVar2;
  short sVar3;
  
  sVar2 = 0;
  sVar3 = 0;
  do {
    if (*(short *)(param_1 + 0x19c) <= sVar3) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x134 + sVar2 * 4);
    if (iVar1 != 0) {
      sVar3 = sVar3 + 1;
      if (*(short *)(*(int *)(iVar1 + 8) + 0x14) == param_2) {
        return 1;
      }
    }
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x19);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00471222
// Address: 00471222
uint __fastcall FUN_00471222(int param_1)
{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  short sVar3;
  short sVar4;
  
  uVar2 = in_EAX & 0xffffff00;
  sVar3 = 0;
  sVar4 = 0;
  do {
    if (*(short *)(param_1 + 0x19c) <= sVar4) {
      return uVar2;
    }
    iVar1 = *(int *)(param_1 + 0x134 + sVar3 * 4);
    if (iVar1 != 0) {
      if ((sVar4 != 0) && (*(char *)(*(int *)(iVar1 + 8) + 0x8f) != (char)uVar2)) {
        return uVar2 & 0xffffff00;
      }
      sVar4 = sVar4 + 1;
      uVar2 = CONCAT31((int3)((uint)*(int *)(iVar1 + 8) >> 8),
                       *(undefined1 *)(*(int *)(iVar1 + 8) + 0x8f));
    }
    sVar3 = sVar3 + 1;
    if (0x18 < sVar3) {
      return uVar2;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00471281
// Address: 00471281
uint __fastcall FUN_00471281(int param_1)
{
  byte bVar1;
  int in_EAX;
  short sVar2;
  byte bVar3;
  short sVar4;
  
  bVar3 = 0xff;
  sVar2 = 0;
  sVar4 = 0;
  do {
    if (*(short *)(param_1 + 0x19c) <= sVar4) break;
    in_EAX = *(int *)(param_1 + 0x134 + sVar2 * 4);
    if (in_EAX != 0) {
      bVar1 = *(byte *)(*(int *)(in_EAX + 8) + 0x8d);
      in_EAX = CONCAT31((int3)((uint)*(int *)(in_EAX + 8) >> 8),bVar1);
      if (bVar1 < bVar3) {
        bVar3 = bVar1;
      }
      sVar4 = sVar4 + 1;
    }
    sVar2 = sVar2 + 1;
  } while (sVar2 < 0x19);
  return CONCAT31((int3)((uint)in_EAX >> 8),bVar3 == 0xff) - 1U &
         CONCAT31((int3)((uint)param_1 >> 8),bVar3);
}

// --------------------------------------------------

// Function: FUN_004712e6
// Address: 004712e6
undefined4 __thiscall
FUN_004712e6(int param_1,int *param_2,short *param_3,short param_4,ushort param_5,ushort param_6,
            short param_7)
{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int *piVar6;
  int iStack_8;
  
  iVar5 = 0;
  *param_2 = 0;
  sVar4 = 0;
  *param_3 = 0;
  if (*(short *)(param_1 + 0x19c) == 0) {
    return 0;
  }
  iVar2 = calloc(4,(int)*(short *)(param_1 + 0x19c));
  if (param_4 == -1) {
    param_4 = 4;
  }
  iStack_8 = 0;
  piVar6 = (int *)(param_1 + 0x134);
  do {
    if (*(short *)(param_1 + 0x19c) <= iStack_8) break;
    iVar1 = *piVar6;
    if (iVar1 != 0) {
      if ((((*(char *)(iVar1 + 0x48) == '\x02') && (*(int *)(iVar1 + 0xc) == param_1)) &&
          ((iVar3 = *(int *)(iVar1 + 8), param_4 <= (short)(ushort)*(byte *)(iVar3 + 0x8d) ||
           (*(short *)(param_1 + 0x4a) == 0)))) &&
         ((((param_5 == 0xffff || (*(ushort *)(iVar3 + 0x14) == (param_5 & 0xff))) &&
           ((param_6 == 0xffff || (*(ushort *)(iVar3 + 0x10) == (param_6 & 0xff))))) &&
          ((((param_7 == -1 || (*(char *)(iVar3 + 0x8f) == (char)param_7)) &&
            (0x27 < *(byte *)(iVar3 + 4))) && (*(byte *)(iVar3 + 4) != 0x5a)))))) {
        iVar3 = (int)sVar4;
        sVar4 = sVar4 + 1;
        *(int *)(iVar2 + iVar3 * 4) = iVar1;
      }
      iStack_8 = iStack_8 + 1;
    }
    iVar5 = iVar5 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar5 < 0x19);
  if (sVar4 == 0) {
    free(iVar2);
    return 0;
  }
  *param_2 = iVar2;
  *param_3 = sVar4;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00471429
// Address: 00471429
void __fastcall FUN_00471429(RGE_Player *param_1)
{
  RGE_Static_Object *pRVar1;
  short sVar2;
  short sVar3;
  
  sVar3 = 0;
  sVar2 = 0;
  do {
    if (param_1->sel_count <= sVar2) {
      return;
    }
    pRVar1 = param_1->sel_list[sVar3];
    if (pRVar1 != (RGE_Static_Object *)0x0) {
      if ((pRVar1->object_state < 7) && (pRVar1->inside_obj == (RGE_Static_Object *)0x0)) {
        sVar2 = sVar2 + 1;
      }
      else {
        RGE_Player::unselect_one_object(param_1,sVar3);
      }
    }
    sVar3 = sVar3 + 1;
  } while (sVar3 < 0x19);
  return;
}

// --------------------------------------------------

// Function: FUN_00471476
// Address: 00471476
void __thiscall
FUN_00471476(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5
            )
{
  *(undefined2 *)(param_1 + 0x120) = param_2;
  *(undefined2 *)(param_1 + 0x122) = param_3;
  *(undefined2 *)(param_1 + 0x124) = param_4;
  *(undefined2 *)(param_1 + 0x126) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_004714b3
// Address: 004714b3
void __fastcall FUN_004714b3(int param_1)
{
  *(undefined2 *)(param_1 + 0x120) = 0xffff;
  *(undefined2 *)(param_1 + 0x122) = 0xffff;
  *(undefined2 *)(param_1 + 0x124) = 0xffff;
  *(undefined2 *)(param_1 + 0x126) = 0xffff;
  return;
}

// --------------------------------------------------

// Function: FUN_00471511
// Address: 00471511
void FUN_00471511(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00471521
// Address: 00471521
undefined4 FUN_00471521(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = 0;
  *param_3 = 0;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00471549
// Address: 00471549
undefined4 __thiscall
FUN_00471549(RGE_Player *param_1,RGE_Static_Object *param_2,float param_3,float param_4)
{
  uchar uVar1;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,-1,-1,-1,-1);
  if (uVar1 != '\0') {
    (**(code **)((*ppRStack_8)->_padding_ + 0xb0))();
    RGE_Command::command_move
              (param_1->world->commands,ppRStack_8,asStack_4[0],param_2,param_3,param_4);
    free(ppRStack_8);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004715c4
// Address: 004715c4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004715c4(RGE_Player *param_1,RGE_Static_Object *param_2,float param_3,float param_4)
{
  code *pcVar1;
  uchar uVar2;
  int *piVar3;
  RGE_Static_Object **unaff_EBP;
  undefined4 unaff_ESI;
  int iVar4;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar2 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,-1,-1,-1,-1);
  if (uVar2 != '\0') {
    piVar3 = (int *)(**(code **)((*ppRStack_8)->_padding_ + 0xbc))(param_2,param_3,param_4,0);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x2c))();
    }
    RGE_Command::command_work
              (param_1->world->commands,unaff_EBP,(short)unaff_ESI,param_2,param_3,param_4);
    if ((param_2 != (RGE_Static_Object *)0x0) && (iVar4 = 0, 0 < (short)unaff_ESI)) {
      pcVar1 = *(code **)(param_1->_padding_ + 0x30);
      do {
        (*pcVar1)((int)param_1->id,unaff_EBP[iVar4]->id,0x2bd,param_2->id,(int)param_2->owner->id,
                  param_2->world_x,param_2->world_y,0x3f800000,
                  param_2->master_obj->los * _DAT_00570ec8,0,0,100);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (short)unaff_ESI);
    }
    free(unaff_EBP);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004716c2
// Address: 004716c2
undefined4 __thiscall
FUN_004716c2(RGE_Player *param_1,RGE_Static_Object *param_2,float param_3,float param_4)
{
  uchar uVar1;
  int *piVar2;
  RGE_Static_Object **unaff_EBX;
  short unaff_SI;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,-1,-1,-1,-1);
  if (uVar1 != '\0') {
    piVar2 = (int *)(**(code **)((*ppRStack_8)->_padding_ + 0xbc))(param_2,param_3,param_4,0);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x2c))();
    }
    RGE_Command::command_order(param_1->world->commands,unaff_EBX,unaff_SI,param_2,param_3,param_4);
    free(unaff_EBX);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047175a
// Address: 0047175a
undefined4 __fastcall FUN_0047175a(RGE_Player *param_1)
{
  uchar uVar1;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,3,-1,-1,-1);
  if (uVar1 != '\0') {
    (**(code **)((*ppRStack_8)->_padding_ + 0xac))();
    RGE_Command::command_stop(param_1->world->commands,ppRStack_8,asStack_4[0]);
    free(ppRStack_8);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004717c1
// Address: 004717c1
undefined4 __thiscall
FUN_004717c1(int param_1,short param_2,float param_3,float param_4,float param_5)
{
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0x24) + param_2 * 4) != 0)) {
    RGE_Command::command_create
              (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),param_2,*(short *)(param_1 + 0x4a)
               ,param_3,param_4,param_5);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00471813
// Address: 00471813
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00471813(int param_1,int param_2,float param_3)
{
  if (param_2 != -1) {
    if (param_3 != _DAT_00570ec4) {
      RGE_Command::command_add_attribute
                (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
                 param_2,param_3);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0047185a
// Address: 0047185a
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0047185a(int param_1,undefined4 param_2,int param_3,float param_4)
{
  if (param_3 != -1) {
    if (param_4 != _DAT_00570ec4) {
      if (param_4 <= *(float *)(*(int *)(param_1 + 0x50) + param_3 * 4)) {
        (**(code **)(**(int **)(*(int *)(param_1 + 0x3c) + 0x58) + 0xc))
                  ((int)*(short *)(param_1 + 0x4a),param_2,param_3,param_4);
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004718b8
// Address: 004718b8
undefined4 __thiscall FUN_004718b8(RGE_Player *param_1,int param_2)
{
  int iVar1;
  uchar uVar2;
  RGE_Player *pRStack_4;
  
  iVar1 = param_2;
  if ((-1 < param_2) && (param_2 < 6)) {
    pRStack_4 = param_1;
    uVar2 = RGE_Player::get_selected_objects_to_command
                      (param_1,(RGE_Static_Object ***)&pRStack_4,(short *)&param_2,-1,-1,-1,-1);
    if (uVar2 != '\0') {
      (**(code **)(*(int *)pRStack_4->_padding_ + 0xac))();
      RGE_Command::command_formation
                (param_1->world->commands,(RGE_Static_Object **)pRStack_4,(int)(short)param_2,iVar1)
      ;
      free(pRStack_4);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00471931
// Address: 00471931
undefined4 __fastcall FUN_00471931(RGE_Player *param_1)
{
  uchar uVar1;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,-1,-1,-1,-1);
  if (uVar1 != '\0') {
    (**(code **)((*ppRStack_8)->_padding_ + 0xac))();
    RGE_Command::command_group_ai_order
              (param_1->world->commands,(int)param_1->id,(int)param_1->id,ppRStack_8,asStack_4[0],
               0x2d5,-1,-1,-1.0,-1.0,-1.0,1.0,'\x01','\0','d');
    free(ppRStack_8);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004719ca
// Address: 004719ca
undefined4 __thiscall FUN_004719ca(int param_1,int param_2,int *param_3,int param_4,float param_5)
{
  RGE_Command::command_create_group
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             param_2,param_3,param_4,param_5);
  return 1;
}

// --------------------------------------------------

// Function: FUN_004719f9
// Address: 004719f9
undefined4 __thiscall FUN_004719f9(int param_1,int param_2,int param_3,float param_4)
{
  RGE_Command::command_add_to_group
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             param_2,param_3,param_4);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00471a24
// Address: 00471a24
undefined4 __thiscall FUN_00471a24(int param_1,int param_2,int param_3)
{
  RGE_Command::command_remove_from_group
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             param_2,param_3);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00471a4f
// Address: 00471a4f
undefined4 __thiscall FUN_00471a4f(int param_1,int param_2)
{
  RGE_Command::command_destroy_group
            (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
             param_2);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00471a6a
// Address: 00471a6a
undefined4 __thiscall FUN_00471a6a(int param_1,int param_2,int param_3)
{
  if (*(char *)(param_1 + 0x80) == '\0') {
    RGE_Command::command_resign
              (*(RGE_Command **)(*(int *)(param_1 + 0x3c) + 0x58),(int)*(short *)(param_1 + 0x4a),
               param_2,param_3);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00471a9e
// Address: 00471a9e
undefined4 __fastcall FUN_00471a9e(RGE_Player *param_1)
{
  uchar uVar1;
  uchar uVar2;
  RGE_Static_Object **ppRStack_8;
  short asStack_4 [2];
  
  uVar1 = RGE_Player::get_selected_objects_to_command(param_1,&ppRStack_8,asStack_4,-1,-1,-1,-1);
  if (uVar1 != '\0') {
    (**(code **)((*ppRStack_8)->_padding_ + 0xac))();
    uVar1 = __ftol();
    uVar2 = __ftol();
    RGE_Command::command_group_waypoint
              (param_1->world->commands,ppRStack_8,asStack_4[0],uVar2,uVar1);
    free(ppRStack_8);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00471b19
// Address: 00471b19
RGE_Object_Node * __thiscall
FUN_00471b19(int param_1,RGE_Static_Object *param_2,int param_3,int param_4)
{
  RGE_Object_Node *pRVar1;
  RGE_Object_List *this;
  
  if (param_3 == 0) {
    if (param_4 == 0) {
      this = *(RGE_Object_List **)(param_1 + 0x28);
    }
    else {
      this = *(RGE_Object_List **)(param_1 + 0x30);
    }
  }
  else {
    this = *(RGE_Object_List **)(param_1 + 0x2c);
  }
  pRVar1 = RGE_Object_List::add_node(this,param_2);
  (**(code **)(**(int **)(param_1 + 0x3c) + 0xf8))(param_2);
  return pRVar1;
}

// --------------------------------------------------

// Function: FUN_00471b67
// Address: 00471b67
void __thiscall
FUN_00471b67(int param_1,RGE_Static_Object *param_2,int param_3,int param_4,RGE_Object_Node *param_5
            )
{
  RGE_Object_List *this;
  
  if (param_3 == 0) {
    if (param_4 == 0) {
      this = *(RGE_Object_List **)(param_1 + 0x28);
    }
    else {
      this = *(RGE_Object_List **)(param_1 + 0x30);
    }
  }
  else {
    this = *(RGE_Object_List **)(param_1 + 0x2c);
  }
  RGE_Object_List::remove_node(this,param_2,param_5);
  (**(code **)(**(int **)(param_1 + 0x3c) + 0xfc))(param_2->id);
  return;
}

// --------------------------------------------------

// Function: FUN_00471bc8
// Address: 00471bc8
void FUN_00471bc8(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00471bd1
// Address: 00471bd1
void FUN_00471bd1(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00471be3
// Address: 00471be3
void __fastcall FUN_00471be3(int param_1)
{
  RGE_Visible_Map::set_all(*(RGE_Visible_Map **)(param_1 + 0x38),'\x01');
  return;
}

// --------------------------------------------------

// Function: FUN_00471bfb
// Address: 00471bfb
void __fastcall FUN_00471bfb(RGE_Player *param_1)
{
  RGE_Visible_Map *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e38b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar1 = param_1->visible;
  if (pRVar1 != (RGE_Visible_Map *)0x0) {
    RGE_Visible_Map::~RGE_Visible_Map(pRVar1);
    operator_delete(pRVar1);
  }
  pRVar1 = (RGE_Visible_Map *)operator_new(0x38);
  uStack_4 = 0;
  if (pRVar1 != (RGE_Visible_Map *)0x0) {
    pRVar1 = (RGE_Visible_Map *)RGE_Visible_Map::RGE_Visible_Map(pRVar1,param_1->world->map,param_1)
    ;
    param_1->visible = pRVar1;
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  param_1->visible = (RGE_Visible_Map *)0x0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00471c84
// Address: 00471c84
void __thiscall FUN_00471c84(RGE_Player *param_1,int param_2,long *param_3,uchar param_4)
{
  RGE_Victory_Conditions *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e3ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar1 = (RGE_Victory_Conditions *)operator_new(0x20);
  uStack_4 = 0;
  if (pRVar1 == (RGE_Victory_Conditions *)0x0) {
    pRVar1 = (RGE_Victory_Conditions *)0x0;
  }
  else {
    pRVar1 = (RGE_Victory_Conditions *)
             RGE_Victory_Conditions::RGE_Victory_Conditions(pRVar1,param_1,param_2,param_3,param_4);
  }
  param_1->victory_conditions = pRVar1;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00471cf3
// Address: 00471cf3
void __fastcall FUN_00471cf3(RGE_Player *param_1)
{
  RGE_Victory_Conditions *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055e3cb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pRVar1 = (RGE_Victory_Conditions *)operator_new(0x20);
  uStack_4 = 0;
  if (pRVar1 != (RGE_Victory_Conditions *)0x0) {
    pRVar1 = (RGE_Victory_Conditions *)
             RGE_Victory_Conditions::RGE_Victory_Conditions(pRVar1,param_1);
    param_1->victory_conditions = pRVar1;
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  param_1->victory_conditions = (RGE_Victory_Conditions *)0x0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00471d63
// Address: 00471d63
void __thiscall FUN_00471d63(int *param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (*param_1 <= param_1[1]) {
    puVar1 = (undefined4 *)calloc(*param_1 * 2,8);
    puVar4 = (undefined4 *)param_1[4];
    puVar5 = puVar1;
    for (uVar2 = (uint)(*param_1 << 3) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    free(param_1[4]);
    param_1[4] = (int)puVar1;
    *param_1 = *param_1 << 1;
  }
  *(undefined4 *)(param_1[4] + param_1[1] * 8) = param_2;
  *(undefined4 *)(param_1[4] + 4 + param_1[1] * 8) = param_3;
  param_1[1] = param_1[1] + 1;
  param_1[2] = param_1[2] + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00471deb
// Address: 00471deb
void __fastcall FUN_00471deb(undefined4 *param_1)
{
  undefined4 uVar1;
  
  param_1[1] = 0;
  param_1[2] = 0;
  if (param_1[3] != 0) {
    free(param_1[4]);
    *param_1 = 8;
    uVar1 = calloc(8,8);
    param_1[4] = uVar1;
    param_1[3] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00471e32
// Address: 00471e32
undefined4 * __thiscall FUN_00471e32(undefined4 *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  uVar1 = calloc(param_2,8);
  param_1[4] = uVar1;
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00471e6a
// Address: 00471e6a
void __fastcall FUN_00471e6a(int param_1)
{
  if (*(int *)(param_1 + 0x10) != 0) {
    free(*(int *)(param_1 + 0x10));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00471e81
// Address: 00471e81
void __thiscall FUN_00471e81(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  *param_3 = *(undefined4 *)(param_1 + 4);
  return;
}

// --------------------------------------------------

// Function: FUN_00471ea5
// Address: 00471ea5
undefined4 __fastcall FUN_00471ea5(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = 0;
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_00471ebb
// Address: 00471ebb
TPanel * __fastcall FUN_00471ebb(TPanel *param_1)
{
  tagRECT *ptVar1;
  int *piVar2;
  int iVar3;
  
  TPanel::TPanel(param_1);
  param_1[1].top_panel = (TPanel *)0x1;
  param_1[1].right_panel = (TPanel *)0x1;
  param_1[1].bottom_panel = (TPanel *)0x1;
  param_1[1].render_rect.top = 1;
  param_1[1].left_border = 1;
  param_1[1].mouse_action = 0xff;
  param_1[1].mouse_down_button = 0xff;
  param_1[1].panel_type = 0xff;
  param_1[1].color = 0xff;
  param_1[1].fill_in_background = 0xff;
  param_1[1].clip_to_parent = 0xff;
  param_1[1].draw_rect2_flag = 0xff;
  param_1[1].need_restore = 0xff;
  *(undefined2 *)&param_1[2].pnl_x = 1;
  param_1[2].max_hgt = 1;
  param_1[2].mouse_down_ctrl = -1;
  param_1[1].node = (PanelNode *)0x0;
  param_1[1].render_rect.right = 0;
  param_1[1].render_rect.bottom = 0;
  param_1[1].top_border = 0;
  param_1[2]._padding_ = 0;
  param_1[2].previousPanelValue = (TPanel *)0x0;
  param_1[2].previousModalPanelValue = (TPanel *)0x0;
  *(undefined2 *)((int)&param_1[2].pnl_x + 2) = 0;
  param_1[2].pnl_y = 0;
  param_1[2].pnl_wid = 0;
  *(undefined2 *)&param_1[2].pnl_hgt = 0;
  param_1[2].panelNameValue = (char *)0x0;
  param_1[2].max_wid = 0;
  param_1[2].min_hgt = 0;
  *(undefined1 *)&param_1[2].mouse_hold_interval = 0;
  *(undefined1 *)((int)&param_1[2].mouse_hold_interval + 1) = 0;
  *(undefined1 *)((int)&param_1[2].mouse_hold_interval + 2) = 0;
  *(undefined1 *)((int)&param_1[2].mouse_hold_interval + 3) = 0;
  *(undefined1 *)&param_1[2].mouse_move_tolerance = 0;
  *(undefined1 *)((int)&param_1[2].mouse_move_tolerance + 1) = 0;
  param_1[2].mouse_down_x = 0;
  param_1[2].mouse_down_y = 0;
  param_1->_padding_ = (int)&TButtonPanel::_vftable_;
  param_1->panel_type = '\x03';
  piVar2 = &param_1[1].overlapping_children;
  ptVar1 = &param_1[1].clip_rect;
  iVar3 = 9;
  do {
    *(undefined4 *)((int)(ptVar1 + -3) + 0xc) = 0;
    ptVar1->left = 0;
    *(PanelNode **)((int)(ptVar1 + 3) + 4) = (PanelNode *)0x0;
    *(undefined2 *)piVar2 = 0xffff;
    ptVar1[8].left = 0;
    *(long *)((int)(ptVar1 + 10) + 4) = 0;
    ptVar1[0xf].left = 0xffffff;
    *(undefined4 *)((int)(ptVar1 + 0x11) + 4) = 0;
    *(undefined4 *)((int)(ptVar1 + 0x13) + 8) = 0xffff;
    *(undefined4 *)((int)(ptVar1 + 0x15) + 0xc) = 0;
    piVar2 = (int *)((int)piVar2 + 2);
    ptVar1 = (tagRECT *)&ptVar1->top;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00472001
// Address: 00472001
TButtonPanel * __thiscall FUN_00472001(TButtonPanel *param_1,byte param_2)
{
  TButtonPanel::~TButtonPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0047202e
// Address: 0047202e
void __fastcall FUN_0047202e(TPanel *param_1)
{
  int iVar1;
  long *plVar2;
  
  iVar1 = 9;
  param_1->_padding_ = (int)&TButtonPanel::_vftable_;
  plVar2 = &param_1[1].mouse_down_y;
  do {
    if (plVar2[-9] != 0) {
      free(plVar2[-9]);
      plVar2[-9] = 0;
    }
    if (*plVar2 != 0) {
      free(*plVar2);
      *plVar2 = 0;
    }
    plVar2 = plVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (param_1[2].pnl_wid != 0) {
    free(param_1[2].pnl_wid);
    param_1[2].pnl_wid = 0;
  }
  TPanel::~TPanel(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00472099
// Address: 00472099
undefined4 __thiscall
FUN_00472099(TButtonPanel *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,DrawType param_8,TDigital *param_9,NotifyType param_10,
            long param_11)
{
  TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6,param_7,'\0');
  param_1->notifyTypeValue = param_10;
  param_1->drawTypeValue = param_8;
  TButtonPanel::set_sound(param_1,param_9);
  TButtonPanel::set_id(param_1,0,param_11,0);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00472103
// Address: 00472103
undefined4 __fastcall FUN_00472103(int param_1)
{
  return *(undefined4 *)(param_1 + 0x13c);
}

// --------------------------------------------------

// Function: FUN_00472117
// Address: 00472117
undefined4 __fastcall FUN_00472117(int param_1)
{
  return *(undefined4 *)(param_1 + 0x140);
}

// --------------------------------------------------

// Function: FUN_00472127
// Address: 00472127
undefined4 __fastcall FUN_00472127(int param_1)
{
  return *(undefined4 *)(param_1 + 0x144);
}

// --------------------------------------------------

// Function: FUN_00472137
// Address: 00472137
void __thiscall FUN_00472137(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x140) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0047214d
// Address: 0047214d
void __thiscall FUN_0047214d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0047215d
// Address: 0047215d
void __thiscall
FUN_0047215d(TButtonPanel *param_1,TShape *param_2,short param_3,long param_4,long param_5,
            int param_6,int param_7)
{
  param_1->pic_x = param_4;
  param_1->pic_y = param_5;
  param_1->all_hot = param_6;
  param_1->auto_pic_pos = param_7;
  TButtonPanel::set_picture(param_1,0,param_2,param_3);
  return;
}

// --------------------------------------------------

// Function: FUN_0047219c
// Address: 0047219c
void __thiscall
FUN_0047219c(TButtonPanel *param_1,char *param_2,void *param_3,long param_4,long param_5,
            long param_6,long param_7)
{
  TButtonPanel::set_text_pos(param_1,param_6,param_7);
  TButtonPanel::set_text(param_1,0,param_2);
  TButtonPanel::set_font(param_1,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_004721dc
// Address: 004721dc
void __thiscall
FUN_004721dc(TButtonPanel *param_1,long param_2,void *param_3,long param_4,long param_5,long param_6
            ,long param_7)
{
  TButtonPanel::set_text_pos(param_1,param_6,param_7);
  TButtonPanel::set_text(param_1,0,param_2);
  TButtonPanel::set_font(param_1,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0047221c
// Address: 0047221c
void __thiscall FUN_0047221c(int *param_1,int param_2,int param_3)
{
  param_1[0x78] = param_2;
  param_1[0x79] = param_3;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047223e
// Address: 0047223e
void __thiscall FUN_0047223e(int param_1,int param_2,short param_3)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x13c) = 2;
  if (*(int *)(param_1 + 0x1fc) != 0) {
    free(*(int *)(param_1 + 0x1fc));
    *(undefined4 *)(param_1 + 0x1fc) = 0;
  }
  if (param_3 != 0) {
    iVar3 = (int)param_3;
    *(short *)(param_1 + 0x200) = param_3;
    uVar1 = calloc(iVar3,4);
    *(undefined4 *)(param_1 + 0x1fc) = uVar1;
    if (0 < param_3) {
      iVar2 = 0;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x1fc) + iVar2) = *(undefined4 *)(param_2 + iVar2);
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004722b6
// Address: 004722b6
void __thiscall FUN_004722b6(int param_1,undefined2 param_2)
{
  *(undefined4 *)(param_1 + 0x13c) = 3;
  *(undefined2 *)(param_1 + 500) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_004722d9
// Address: 004722d9
void __thiscall FUN_004722d9(int param_1,short param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0xf4 + param_2 * 4) = param_3;
  *(undefined4 *)(param_1 + 0x118 + param_2 * 4) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_004722fe
// Address: 004722fe
void __thiscall FUN_004722fe(int *param_1,short param_2,int param_3,undefined2 param_4)
{
  param_1[param_2 + 0x53] = param_3;
  *(undefined2 *)((int)param_1 + param_2 * 2 + 0x170) = param_4;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00472327
// Address: 00472327
void __thiscall FUN_00472327(int *param_1,short param_2,char *param_3)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  
  iVar8 = (int)param_2;
  if (param_1[iVar8 + 0x66] != 0) {
    free(param_1[iVar8 + 0x66]);
    param_1[iVar8 + 0x66] = 0;
  }
  if (param_1[iVar8 + 0x6f] != 0) {
    free(param_1[iVar8 + 0x6f]);
    param_1[iVar8 + 0x6f] = 0;
  }
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    iVar2 = strchr(param_3,10);
    if (iVar2 == 0) {
      iVar3 = -1;
      pcVar4 = param_3;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      sVar5 = ~(ushort)iVar3 - 1;
    }
    else {
      sVar5 = (short)iVar2 - (short)param_3;
    }
    iVar10 = (int)sVar5;
    iVar3 = calloc(iVar10 + 1,1);
    param_1[iVar8 + 0x66] = iVar3;
    if (iVar3 != 0) {
      strncpy(iVar3,param_3,iVar10);
      *(undefined1 *)(iVar10 + param_1[iVar8 + 0x66]) = 0;
      if (iVar2 != 0) {
        uVar6 = 0xffffffff;
        pcVar4 = (char *)(iVar2 + 1);
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        pcVar4 = (char *)calloc(~uVar6,1);
        param_1[iVar8 + 0x6f] = (int)pcVar4;
        if (pcVar4 != (char *)0x0) {
          uVar6 = 0xffffffff;
          pcVar9 = (char *)(iVar2 + 1);
          do {
            pcVar11 = pcVar9;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar11 = pcVar9 + 1;
            cVar1 = *pcVar9;
            pcVar9 = pcVar11;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          pcVar9 = pcVar11 + -uVar6;
          for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)pcVar4 = *(undefined4 *)pcVar9;
            pcVar9 = pcVar9 + 4;
            pcVar4 = pcVar4 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar4 = *pcVar9;
            pcVar9 = pcVar9 + 1;
            pcVar4 = pcVar4 + 1;
          }
        }
      }
    }
  }
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00472437
// Address: 00472437
void __thiscall FUN_00472437(int *param_1,short param_2,char *param_3,char *param_4)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = (int)param_2;
  if (param_1[iVar5 + 0x66] != 0) {
    free(param_1[iVar5 + 0x66]);
    param_1[iVar5 + 0x66] = 0;
  }
  if (param_1[iVar5 + 0x6f] != 0) {
    free(param_1[iVar5 + 0x6f]);
    param_1[iVar5 + 0x6f] = 0;
  }
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    uVar3 = 0xffffffff;
    pcVar2 = param_3;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)calloc(~uVar3,1);
    param_1[iVar5 + 0x66] = (int)pcVar2;
    if (pcVar2 != (char *)0x0) {
      uVar3 = 0xffffffff;
      do {
        pcVar6 = param_3;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar6 = pcVar6 + -uVar3;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar2 = pcVar2 + 1;
      }
      if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
        uVar3 = 0xffffffff;
        pcVar2 = param_4;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = (char *)calloc(~uVar3,1);
        param_1[iVar5 + 0x6f] = (int)pcVar2;
        if (pcVar2 != (char *)0x0) {
          uVar3 = 0xffffffff;
          do {
            pcVar6 = param_4;
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            pcVar6 = param_4 + 1;
            cVar1 = *param_4;
            param_4 = pcVar6;
          } while (cVar1 != '\0');
          uVar3 = ~uVar3;
          pcVar6 = pcVar6 + -uVar3;
          for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
            pcVar6 = pcVar6 + 4;
            pcVar2 = pcVar2 + 4;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *pcVar2 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            pcVar2 = pcVar2 + 1;
          }
        }
      }
    }
  }
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_0047253a
// Address: 0047253a
void __thiscall FUN_0047253a(TButtonPanel *param_1,short param_2,int param_3)
{
  char acStack_100 [256];
  
  TPanel::get_string((TPanel *)param_1,param_3,acStack_100,0x100);
  TButtonPanel::set_text(param_1,param_2,acStack_100);
  return;
}

// --------------------------------------------------

// Function: FUN_004725e4
// Address: 004725e4
void __thiscall FUN_004725e4(int *param_1,int param_2,int param_3,int param_4)
{
  param_1[0x7a] = param_2;
  param_1[0x7b] = param_3;
  param_1[0x7c] = param_4;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00472618
// Address: 00472618
void __thiscall FUN_00472618(int *param_1,int param_2,int param_3,int param_4)
{
  if ((-1 < param_2) && (param_2 < 9)) {
    param_1[param_2 + 0x82] = param_3;
    param_1[param_2 + 0x8b] = param_4;
    (**(code **)(*param_1 + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047264d
// Address: 0047264d
void __thiscall FUN_0047264d(int *param_1,int param_2,int param_3,int param_4)
{
  if ((-1 < param_2) && (param_2 < 9)) {
    param_1[param_2 + 0x94] = param_3;
    param_1[param_2 + 0x9d] = param_4;
    (**(code **)(*param_1 + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047267d
// Address: 0047267d
void __thiscall FUN_0047267d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x148) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0047268d
// Address: 0047268d
void __fastcall FUN_0047268d(int *param_1)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < (short)param_1[0x80]) {
    do {
      *(undefined4 *)(*(int *)(param_1[0x7f] + iVar1 * 4) + 0x1f8) = 0;
      (**(code **)(**(int **)(param_1[0x7f] + iVar1 * 4) + 0xe0))(0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (short)param_1[0x80]);
  }
  if ((param_1[0x50] == 3) || (param_1[0x50] == 5)) {
    param_1[0x7e] = 1;
  }
  (**(code **)(*param_1 + 0xe0))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_004726f9
// Address: 004726f9
void __thiscall FUN_004726f9(int *param_1,undefined2 param_2)
{
  *(undefined2 *)((int)param_1 + 0x1f6) = param_2;
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_00472716
// Address: 00472716
void __thiscall FUN_00472716(int *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < (short)param_1[0x7d]) {
    piVar2 = param_1 + 0x3d;
    while (*piVar2 != param_2) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if ((short)param_1[0x7d] <= iVar1) {
        return;
      }
    }
    *(short *)((int)param_1 + 0x1f6) = (short)iVar1;
    (**(code **)(*param_1 + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0047275d
// Address: 0047275d
void __thiscall
FUN_0047275d(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5
            ,undefined1 param_6,undefined1 param_7,undefined1 param_8)
{
  *(undefined4 *)(param_1 + 0x2a0) = param_2;
  *(undefined1 *)(param_1 + 0x2a4) = param_3;
  *(undefined1 *)(param_1 + 0x2a5) = param_4;
  *(undefined1 *)(param_1 + 0x2a6) = param_5;
  *(undefined1 *)(param_1 + 0x2a7) = param_6;
  *(undefined1 *)(param_1 + 0x2a8) = param_7;
  *(undefined1 *)(param_1 + 0x2a9) = param_8;
  return;
}

// --------------------------------------------------

// Function: FUN_004727a9
// Address: 004727a9
void __thiscall FUN_004727a9(int *param_1,int param_2)
{
  param_1[0xac] = param_2;
  (**(code **)(*param_1 + 0x20))(1);
  if (param_1[0xac] != 0) {
    param_1[0x20] = 0;
    return;
  }
  param_1[0x20] = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004727ea
// Address: 004727ea
void __thiscall FUN_004727ea(TPanel *param_1,long param_2,long param_3,long param_4,long param_5)
{
  TPanel::set_rect(param_1,param_2,param_3,param_4,param_5);
  return;
}

// --------------------------------------------------

// Function: FUN_0047280c
// Address: 0047280c
int __fastcall FUN_0047280c(int param_1)
{
  return (int)*(short *)(param_1 + 0x1f6);
}

// --------------------------------------------------

// Function: FUN_00472818
// Address: 00472818
undefined4 __fastcall FUN_00472818(int param_1)
{
  return *(undefined4 *)(param_1 + 0xf4 + *(short *)(param_1 + 0x1f6) * 4);
}

// --------------------------------------------------

// Function: FUN_0047282f
// Address: 0047282f
undefined4 __fastcall FUN_0047282f(int param_1)
{
  return *(undefined4 *)(param_1 + 0x118 + *(short *)(param_1 + 0x1f6) * 4);
}

// --------------------------------------------------

// Function: FUN_0047283f
// Address: 0047283f
bool __thiscall FUN_0047283f(int param_1,short param_2,int *param_3,undefined4 *param_4)
{
  if (param_2 == -1) {
    param_2 = *(short *)(param_1 + 0x1f6);
  }
  *param_3 = *(int *)(param_1 + 0x198 + param_2 * 4);
  *param_4 = *(undefined4 *)(param_1 + 0x1bc + param_2 * 4);
  return *param_3 != 0;
}

// --------------------------------------------------

// Function: FUN_0047287c
// Address: 0047287c
void __thiscall FUN_0047287c(int param_1,short param_2,undefined4 *param_3,undefined4 *param_4)
{
  if (param_2 == -1) {
    param_2 = *(short *)(param_1 + 0x1f6);
  }
  *param_3 = *(undefined4 *)(param_1 + 0x208 + param_2 * 4);
  *param_4 = *(undefined4 *)(param_1 + 0x22c + param_2 * 4);
  return;
}

// --------------------------------------------------

// Function: FUN_004728b3
// Address: 004728b3
// [HELPER] s_pnl_btn__draw2: "pnl_btn::draw2"
// [HELPER] s_pnl_btn__draw: "pnl_btn::draw"
void __fastcall FUN_004728b3(int *param_1)
{
  char cVar1;
  uchar uVar2;
  int *piVar3;
  uchar *puVar4;
  long lVar5;
  void *pvVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  uchar uVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  code *pcVar14;
  undefined4 unaff_EDI;
  int iVar15;
  char *pcVar16;
  undefined4 uVar17;
  int iStack_30;
  int iStack_2c;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int aiStack_c [3];
  
  if (((((TDrawArea *)param_1[8] == (TDrawArea *)0x0) || (param_1[0x1c] == 0)) ||
      (param_1[0x1b] == 0)) || (param_1[0x50] == 1)) {
    param_1[0xe] = 0;
    return;
  }
  if (param_1[0x50] == 5) {
    TDrawArea::Clear((TDrawArea *)param_1[8],(tagRECT *)(param_1 + 9),
                     (uint)*(byte *)((int)param_1 + 0xef));
  }
  else {
    piVar3 = (int *)param_1[0x10];
    if (piVar3 != (int *)0x0) {
      if ((param_1[0xa8] < 2) || (4 < param_1[0xa8])) {
        if (piVar3[0x21] == 0) {
          (**(code **)(*piVar3 + 0x34))(param_1 + 9);
        }
      }
      else {
        (**(code **)(*piVar3 + 0x3c))(param_1 + 9);
      }
    }
  }
  iVar12 = *param_1;
  uVar17 = 0;
  aiStack_c[0] = iVar12;
  (**(code **)(iVar12 + 0x28))(0);
  iVar8 = param_1[0x50];
  if ((((iVar8 == 2) || (iVar8 == 4)) || (iVar8 == 6)) &&
     (puVar4 = TDrawArea::Lock((TDrawArea *)param_1[8],s_pnl_btn__draw,1), puVar4 != (uchar *)0x0))
{
    if ((TShape *)param_1[*(short *)((int)param_1 + 0x1f6) + 0x53] != (TShape *)0x0) {
      if (param_1[0x61] != 0) {
        TShape::shape_minmax
                  ((TShape *)param_1[*(short *)((int)param_1 + 0x1f6) + 0x53],&iStack_20,&iStack_18,
                   &iStack_24,&iStack_1c,
                   (int)*(short *)((int)param_1 + *(short *)((int)param_1 + 0x1f6) * 2 + 0x170));
        param_1[0x62] =
             (int)(short)(((short)(param_1[5] / 2) - (short)(((iStack_24 - iStack_20) + 1) / 2)) -
                         (short)iStack_20);
        param_1[99] = (int)(short)(((short)(param_1[6] / 2) -
                                   (short)(((iStack_1c - iStack_18) + 1) / 2)) - (short)iStack_18);
      }
      lVar7 = param_1[99] + param_1[4];
      lVar5 = param_1[0x62] + param_1[3];
      if (param_1[0x65] == 0) {
        if (param_1[0x7e] != 0) {
LAB_00472a41:
          lVar5 = lVar5 + 1;
          lVar7 = lVar7 + -1;
        }
      }
      else if (param_1[0x7e] == 0) goto LAB_00472a41;
      TShape::shape_draw((TShape *)param_1[*(short *)((int)param_1 + 0x1f6) + 0x53],
                         (TDrawArea *)param_1[8],lVar5,lVar7,
                         (int)*(short *)((int)param_1 + *(short *)((int)param_1 + 0x1f6) * 2 + 0x170
                                        ),'\0',(uchar *)0x0);
    }
    TDrawArea::Unlock((TDrawArea *)param_1[8],s_pnl_btn__draw);
  }
  iVar8 = param_1[0x50];
  if ((((iVar8 == 3) || (iVar8 == 4)) || (iVar8 == 5)) &&
     (pvVar6 = TDrawArea::GetDc((TDrawArea *)param_1[8],s_pnl_btn__draw), pvVar6 != (void *)0x0)) {
    SelectClipRgn(pvVar6,param_1[0x22]);
    uStack_14 = SelectObject(pvVar6,param_1[0x7a]);
    SetBkMode(pvVar6,1);
    iVar12 = param_1[0x78];
    if (iVar12 == -1) {
      iVar12 = param_1[5] / 2;
    }
    iStack_30 = param_1[0x79];
    if (iStack_30 == -1) {
      iStack_30 = param_1[6] / 2;
    }
    pcVar11 = (char *)param_1[*(short *)((int)param_1 + 0x1f6) + 0x66];
    if (pcVar11 == (char *)0x0) {
      pcVar11 = (char *)param_1[0x66];
    }
    if (pcVar11 != (char *)0x0) {
      iVar8 = -1;
      pcVar16 = pcVar11;
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        cVar1 = *pcVar16;
        pcVar16 = pcVar16 + 1;
      } while (cVar1 != '\0');
      iVar8 = (int)(short)(~(ushort)iVar8 - 1);
      GetTextExtentPoint32A(pvVar6,pcVar11,iVar8,aiStack_c);
      iVar15 = (iVar12 - aiStack_c[0] / 2) + param_1[3];
      iVar9 = (int)*(short *)((int)param_1 + 0x1f6);
      if (param_1[iVar9 + 0x6f] == 0) {
        iVar13 = param_1[0x7c] / 2;
      }
      else {
        iVar13 = param_1[0x7c];
      }
      iVar13 = (iStack_30 - iVar13) + param_1[4];
      if (param_1[0x65] == 0) {
        if (param_1[0x7e] != 0) {
LAB_00472bbc:
          iVar15 = iVar15 + 1;
          iVar13 = iVar13 + -1;
        }
      }
      else if (param_1[0x7e] == 0) goto LAB_00472bbc;
      if (param_1[0x1e] == 0) {
        SetTextColor(pvVar6,param_1[iVar9 + 0x8b]);
        TextOutA(pvVar6,iVar15 + -1,iVar13 + 1,pcVar11,iVar8);
        SetTextColor(pvVar6,param_1[*(short *)((int)param_1 + 0x1f6) + 0x82]);
        TextOutA(pvVar6,iVar15,iVar13,pcVar11,iVar8);
        pcVar14 = TextOutA_exref;
      }
      else {
        SetTextColor(pvVar6,param_1[iVar9 + 0x9d]);
        TextOutA(pvVar6,iVar15 + -1,iVar13 + 1,pcVar11,iVar8);
        SetTextColor(pvVar6,param_1[*(short *)((int)param_1 + 0x1f6) + 0x94]);
        pcVar14 = TextOutA_exref;
        TextOutA(pvVar6,iVar15,iVar13,pcVar11,iVar8);
      }
      pcVar11 = (char *)param_1[*(short *)((int)param_1 + 0x1f6) + 0x6f];
      if (pcVar11 == (char *)0x0) {
        pcVar11 = (char *)param_1[0x6f];
      }
      if (pcVar11 != (char *)0x0) {
        iVar8 = -1;
        pcVar16 = pcVar11;
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          cVar1 = *pcVar16;
          pcVar16 = pcVar16 + 1;
        } while (cVar1 != '\0');
        iVar8 = (int)(short)(~(ushort)iVar8 - 1);
        GetTextExtentPoint32A(pvVar6,pcVar11,iVar8,aiStack_c);
        iStack_2c = (iVar12 - aiStack_c[0] / 2) + param_1[3];
        iStack_30 = iStack_30 + param_1[4];
        if (param_1[0x65] == 0) {
          if (param_1[0x7e] != 0) {
LAB_00472d03:
            iStack_2c = iStack_2c + 1;
            iStack_30 = iStack_30 + -1;
          }
        }
        else if (param_1[0x7e] == 0) goto LAB_00472d03;
        iVar12 = iVar8;
        if (param_1[0x1e] == 0) {
          SetTextColor(pvVar6,param_1[*(short *)((int)param_1 + 0x1f6) + 0x8b]);
          (*pcVar14)(pvVar6,iStack_2c + -1,iStack_30 + 1,pcVar11,iVar8);
          SetTextColor(pvVar6,param_1[*(short *)((int)param_1 + 0x1f6) + 0x82]);
        }
        else {
          SetTextColor(pvVar6,param_1[*(short *)((int)param_1 + 0x1f6) + 0x9d]);
          (*pcVar14)(pvVar6,iStack_2c + -1,iStack_30 + 1,pcVar11,iVar8);
          SetTextColor(pvVar6,param_1[*(short *)((int)param_1 + 0x1f6) + 0x94]);
        }
        (*pcVar14)(pvVar6,unaff_EDI,uVar17,iVar12,iVar8);
      }
    }
    SelectObject(pvVar6,uStack_14);
    SelectClipRgn(pvVar6,0);
    TDrawArea::ReleaseDc((TDrawArea *)param_1[8],s_pnl_btn__draw);
    iVar12 = iStack_10;
  }
  iVar8 = param_1[0x50];
  if ((((iVar8 != 3) && (iVar8 != 4)) && ((iVar8 != 5 && (iVar8 != 6)))) ||
     (puVar4 = TDrawArea::Lock((TDrawArea *)param_1[8],s_pnl_btn__draw2,1), puVar4 == (uchar *)0x0))
  goto LAB_004730d9;
  if (param_1[0xac] == 0) {
    if (param_1[0x65] == 0) {
      iVar8 = param_1[0x7e];
    }
    else {
      iVar8 = param_1[0x7e];
    }
    if (iVar8 == 0) {
      switch(param_1[0xa8]) {
      case 1:
        TDrawArea::DrawRect((TDrawArea *)param_1[8],param_1[3] + 1,param_1[4] + 1,
                            param_1[5] + -2 + param_1[3],param_1[6] + -2 + param_1[4],0xff);
        break;
      case 2:
        uVar2 = (uchar)param_1[0xa9];
        iVar8 = param_1[4];
        iVar9 = param_1[3];
        uVar10 = *(uchar *)((int)param_1 + 0x2a9);
        goto LAB_00473024;
      case 3:
        TDrawArea::DrawBevel21
                  ((TDrawArea *)param_1[8],param_1[3],param_1[4],param_1[5] + -1 + param_1[3],
                   param_1[6] + -1 + param_1[4],*(uchar *)((int)param_1 + 0x2a9),
                   (uchar)param_1[0xaa],*(uchar *)((int)param_1 + 0x2a5),(uchar)param_1[0xa9]);
        break;
      case 4:
        TDrawArea::DrawBevel32
                  ((TDrawArea *)param_1[8],param_1[3],param_1[4],param_1[5] + -1 + param_1[3],
                   param_1[6] + -1 + param_1[4],*(uchar *)((int)param_1 + 0x2a9),
                   (uchar)param_1[0xaa],*(uchar *)((int)param_1 + 0x2a7),
                   *(uchar *)((int)param_1 + 0x2a6),*(uchar *)((int)param_1 + 0x2a5),
                   (uchar)param_1[0xa9]);
      }
    }
    else {
      switch(param_1[0xa8]) {
      case 1:
        TDrawArea::DrawVertLine
                  ((TDrawArea *)param_1[8],param_1[5] + -1 + param_1[3],param_1[4] + 1,
                   param_1[6] + -1,'\0');
        TDrawArea::DrawHorzLine
                  ((TDrawArea *)param_1[8],param_1[3] + 1,param_1[6] + -1 + param_1[4],
                   param_1[5] + -1,'\0');
        TDrawArea::DrawRect((TDrawArea *)param_1[8],param_1[3],param_1[4],
                            param_1[5] + -2 + param_1[3],param_1[6] + -2 + param_1[4],0xff);
        break;
      case 2:
        uVar2 = *(uchar *)((int)param_1 + 0x2a9);
        iVar8 = param_1[4];
        iVar9 = param_1[3];
        uVar10 = (uchar)param_1[0xa9];
LAB_00473024:
        TDrawArea::DrawBevel
                  ((TDrawArea *)param_1[8],iVar9,iVar8,param_1[5] + -1 + iVar9,
                   param_1[6] + -1 + iVar8,uVar10,uVar2);
        break;
      case 3:
        TDrawArea::DrawBevel2
                  ((TDrawArea *)param_1[8],param_1[3],param_1[4],param_1[5] + -1 + param_1[3],
                   param_1[6] + -1 + param_1[4],(uchar)param_1[0xa9],
                   *(uchar *)((int)param_1 + 0x2a5),(uchar)param_1[0xaa],
                   *(uchar *)((int)param_1 + 0x2a9));
        break;
      case 4:
        TDrawArea::DrawBevel3
                  ((TDrawArea *)param_1[8],param_1[3],param_1[4],param_1[5] + -1 + param_1[3],
                   param_1[6] + -1 + param_1[4],(uchar)param_1[0xa9],
                   *(uchar *)((int)param_1 + 0x2a5),*(uchar *)((int)param_1 + 0x2a6),
                   *(uchar *)((int)param_1 + 0x2a7),(uchar)param_1[0xaa],
                   *(uchar *)((int)param_1 + 0x2a9));
      }
    }
  }
  else {
    TDrawArea::DrawRect((TDrawArea *)param_1[8],param_1[3],param_1[4],param_1[5] + -1 + param_1[3],
                        param_1[6] + -1 + param_1[4],*(uchar *)((int)param_1 + 0x2a9));
    TDrawArea::DrawRect((TDrawArea *)param_1[8],param_1[3] + 1,param_1[4] + 1,
                        param_1[5] + -2 + param_1[3],param_1[6] + -2 + param_1[4],
                        (uchar)param_1[0xa9]);
  }
  TDrawArea::Unlock((TDrawArea *)param_1[8],s_pnl_btn__draw2);
LAB_004730d9:
  (**(code **)(iVar12 + 0x2c))();
  return;
}

// --------------------------------------------------

// Function: FUN_004730f1
// Address: 004730f1
// Error: 
Low-level Error: Cannot properly adjust input varnodes

// --------------------------------------------------

// Function: FUN_0047317f
// Address: 0047317f
undefined4 FUN_0047317f(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00473185
// Address: 00473185
// [HELPER] s_C__msdev_work_age1_x1_Pnl_btn_cp: "C:\msdev\work\age1_x1\Pnl_btn.cpp"
undefined4 __fastcall FUN_00473185(TPanel *param_1)
{
  short sVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1[2].mouse_down_y != 0) {
    return 0;
  }
  if ((TDigital *)param_1[1].node != (TDigital *)0x0) {
    iVar2 = TDigital::is_playing((TDigital *)param_1[1].node);
    if (iVar2 != 0) {
      TDigital::stop((TDigital *)param_1[1].node);
    }
    TDigital::play((TDigital *)param_1[1].node);
  }
  TPanel::capture_mouse(param_1);
  param_1[2].pnl_y = 1;
  pcVar3 = (char *)debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_btn_cp,0x372);
  param_1[2].panelNameValue = pcVar3;
  (**(code **)(param_1->_padding_ + 0x20))(1);
  if (param_1->parent_panel != (TPanel *)0x0) {
    sVar1 = *(short *)((int)&param_1[2].pnl_x + 2);
    (**(code **)(param_1->parent_panel->_padding_ + 0xb4))
              (param_1,2,(&param_1[1]._padding_)[sVar1],(&param_1[1].clip_rect.left)[sVar1]);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00473232
// Address: 00473232
// [HELPER] s_C__msdev_work_age1_x1_Pnl_btn_cp: "C:\msdev\work\age1_x1\Pnl_btn.cpp"
undefined4 __thiscall FUN_00473232(int *param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  
  iVar1 = *param_1;
  iVar4 = (**(code **)(iVar1 + 0xbc))(param_2,param_3);
  uVar3 = (uint)(iVar4 != 0);
  if (param_1[0x7e] != uVar3) {
    param_1[0x7e] = uVar3;
    if (uVar3 != 0) {
      uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_btn_cp,0x389);
      param_1[0x81] = uVar5;
    }
    (**(code **)(iVar1 + 0x20))(1);
    piVar2 = (int *)param_1[0x10];
    if (param_1[0x7e] == 0) {
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0xb4))
                  (param_1,3,param_1[*(short *)((int)param_1 + 0x1f6) + 0x3d],
                   param_1[*(short *)((int)param_1 + 0x1f6) + 0x46]);
      }
    }
    else if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xb4))
                (param_1,2,param_1[*(short *)((int)param_1 + 0x1f6) + 0x3d],
                 param_1[*(short *)((int)param_1 + 0x1f6) + 0x46]);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00473302
// Address: 00473302
undefined4 __fastcall FUN_00473302(TButtonPanel *param_1)
{
  TPanel::release_mouse((TPanel *)param_1);
  if (param_1->is_down != 0) {
    if (param_1->buttonTypeValue != Radio) {
      param_1->is_down = 0;
    }
    (**(code **)(param_1->_padding_ + 0x20))(1);
    SendMessageA(*(undefined4 *)(param_1->_padding_ + 4),0xf,0,0);
    TButtonPanel::do_action(param_1);
    return 1;
  }
  if ((param_1->buttonTypeValue == Radio) && (param_1->cur_state == 1)) {
    param_1->is_down = 1;
    (**(code **)(param_1->_padding_ + 0x20))(1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0047338e
// Address: 0047338e
undefined4 FUN_0047338e(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00473395
// Address: 00473395
// [HELPER] s_C__msdev_work_age1_x1_Pnl_btn_cp: "C:\msdev\work\age1_x1\Pnl_btn.cpp"
undefined4 __fastcall FUN_00473395(TPanel *param_1)
{
  short sVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1[2].mouse_down_y != 0) {
    return 0;
  }
  if ((TDigital *)param_1[1].node != (TDigital *)0x0) {
    iVar2 = TDigital::is_playing((TDigital *)param_1[1].node);
    if (iVar2 != 0) {
      TDigital::stop((TDigital *)param_1[1].node);
    }
    TDigital::play((TDigital *)param_1[1].node);
  }
  TPanel::capture_mouse(param_1);
  param_1[2].pnl_y = 1;
  pcVar3 = (char *)debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_btn_cp,0x3cc);
  param_1[2].panelNameValue = pcVar3;
  (**(code **)(param_1->_padding_ + 0x20))(1);
  if (param_1->parent_panel != (TPanel *)0x0) {
    sVar1 = *(short *)((int)&param_1[2].pnl_x + 2);
    (**(code **)(param_1->parent_panel->_padding_ + 0xb4))
              (param_1,5,(&param_1[1]._padding_)[sVar1],(&param_1[1].clip_rect.left)[sVar1]);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00473442
// Address: 00473442
// [HELPER] s_C__msdev_work_age1_x1_Pnl_btn_cp: "C:\msdev\work\age1_x1\Pnl_btn.cpp"
undefined4 __thiscall FUN_00473442(int *param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  
  iVar1 = *param_1;
  iVar4 = (**(code **)(iVar1 + 0xbc))(param_2,param_3);
  uVar3 = (uint)(iVar4 != 0);
  if (param_1[0x7e] != uVar3) {
    param_1[0x7e] = uVar3;
    if (uVar3 != 0) {
      uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_btn_cp,0x3e3);
      param_1[0x81] = uVar5;
    }
    (**(code **)(iVar1 + 0x20))(1);
    piVar2 = (int *)param_1[0x10];
    if (param_1[0x7e] == 0) {
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0xb4))
                  (param_1,6,param_1[*(short *)((int)param_1 + 0x1f6) + 0x3d],
                   param_1[*(short *)((int)param_1 + 0x1f6) + 0x46]);
      }
    }
    else if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xb4))
                (param_1,5,param_1[*(short *)((int)param_1 + 0x1f6) + 0x3d],
                 param_1[*(short *)((int)param_1 + 0x1f6) + 0x46]);
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00473512
// Address: 00473512
undefined4 __thiscall
FUN_00473512(TButtonPanel *param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  TPanel::release_mouse((TPanel *)param_1);
  if (param_1->is_down != 0) {
    if (param_1->buttonTypeValue != Radio) {
      param_1->is_down = 0;
    }
    (**(code **)(param_1->_padding_ + 0x20))(1);
    SendMessageA(*(undefined4 *)(param_1->_padding_ + 4),0xf,0,0);
    TButtonPanel::do_right_action(param_1,param_4);
    return 1;
  }
  if ((param_1->buttonTypeValue == Radio) && (param_1->cur_state == 1)) {
    param_1->is_down = 1;
    (**(code **)(param_1->_padding_ + 0x20))(1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_004735a3
// Address: 004735a3
// [HELPER] s_C__msdev_work_age1_x1_Pnl_btn_cp: "C:\msdev\work\age1_x1\Pnl_btn.cpp"
long __thiscall
FUN_004735a3(TPanel *param_1,int param_2,short param_3,int param_4,int param_5,int param_6)
{
  short sVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  
  if (((((param_1->active != 0) && (param_1[2].mouse_down_y == 0)) && (param_4 == 0)) &&
      (((param_5 == 0 && (param_1[2].max_wid != 0)) &&
       ((param_2 == param_1[2].max_wid && (param_1[2].mouse_down_x == 0)))))) &&
     ((param_1[2].min_hgt == 0 || (param_6 == param_1[2].min_hgt)))) {
    if (((param_1->tab_stop != 0) && (param_1->parent_panel != (TPanel *)0x0)) &&
       (param_1->have_focus == 0)) {
      TPanel::set_curr_child(param_1->parent_panel,param_1);
    }
    if ((TDigital *)param_1[1].node != (TDigital *)0x0) {
      iVar2 = TDigital::is_playing((TDigital *)param_1[1].node);
      if (iVar2 != 0) {
        TDigital::stop((TDigital *)param_1[1].node);
      }
      TDigital::play((TDigital *)param_1[1].node);
    }
    param_1[2].mouse_down_x = param_2;
    param_1[2].pnl_y = 1;
    pcVar3 = (char *)debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_btn_cp,0x421);
    param_1[2].panelNameValue = pcVar3;
    (**(code **)(param_1->_padding_ + 0x20))(1);
    if (param_1->parent_panel != (TPanel *)0x0) {
      sVar1 = *(short *)((int)&param_1[2].pnl_x + 2);
      (**(code **)(param_1->parent_panel->_padding_ + 0xb4))
                (param_1,2,(&param_1[1]._padding_)[sVar1],(&param_1[1].clip_rect.left)[sVar1]);
    }
    return 1;
  }
  lVar4 = TPanel::handle_key_down(param_1,param_2,param_3,param_4,param_5,param_6);
  return lVar4;
}

// --------------------------------------------------

// Function: FUN_004736e3
// Address: 004736e3
// [HELPER] s_C__msdev_work_age1_x1_Pnl_btn_cp: "C:\msdev\work\age1_x1\Pnl_btn.cpp"
undefined4 __thiscall
FUN_004736e3(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5)
{
  int iVar1;
  ulong uVar2;
  TPanel *this;
  TPanel *pTVar3;
  
  if (param_1[0xab] == 0) {
    switch(param_2) {
    case 0xd:
    case 0x20:
      if (param_1[0xac] != 0) {
        return 0;
      }
      if (param_4 != 0) {
        return 0;
      }
      if (param_5 != 0) {
        return 0;
      }
      if ((TDigital *)param_1[0x52] != (TDigital *)0x0) {
        iVar1 = TDigital::is_playing((TDigital *)param_1[0x52]);
        if (iVar1 != 0) {
          TDigital::stop((TDigital *)param_1[0x52]);
        }
        TDigital::play((TDigital *)param_1[0x52]);
      }
      param_1[0xab] = param_2;
      param_1[0x7e] = 1;
      uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Pnl_btn_cp,1099);
      param_1[0x81] = uVar2;
      (**(code **)(*param_1 + 0x20))(1);
      if ((int *)param_1[0x10] == (int *)0x0) {
        return 1;
      }
      (**(code **)(*(int *)param_1[0x10] + 0xb4))
                (param_1,2,param_1[*(short *)((int)param_1 + 0x1f6) + 0x3d],
                 param_1[*(short *)((int)param_1 + 0x1f6) + 0x46]);
      return 1;
    default:
      goto switchD_0047371a_caseD_e;
    case 0x26:
      if (param_4 != 0) {
        return 1;
      }
      if (param_5 != 0) {
        return 1;
      }
      if (param_1[0x1d] == 0) {
        return 1;
      }
      this = (TPanel *)param_1[0x10];
      if (this == (TPanel *)0x0) {
        return 1;
      }
      pTVar3 = (TPanel *)param_1[0x18];
      break;
    case 0x28:
      if (param_4 != 0) {
        return 1;
      }
      if (param_5 != 0) {
        return 1;
      }
      if (param_1[0x1d] == 0) {
        return 1;
      }
      this = (TPanel *)param_1[0x10];
      if (this == (TPanel *)0x0) {
        return 1;
      }
      pTVar3 = (TPanel *)param_1[0x19];
    }
    if (pTVar3 == (TPanel *)0x0) {
      return 1;
    }
    TPanel::set_curr_child(this,pTVar3);
    return 1;
  }
switchD_0047371a_caseD_e:
  return 0;
}

// --------------------------------------------------

// Function: FUN_00473857
// Address: 00473857
long __fastcall
FUN_00473857(TButtonPanel *param_1,char param_2,undefined4 param_3,void *param_4,uint param_5,
            uint param_6,long param_7)
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  char cVar9;
  undefined4 in_EAX;
  int iVar7;
  long lVar8;
  char unaff_BL;
  int unaff_EBP;
  uint unaff_retaddr;
  uint uVar5;
  char *pcVar6;
  
  bVar1 = 9 < ((byte)in_EAX & 0xf) || (unaff_retaddr & 0x10) != 0;
  bVar3 = (byte)in_EAX + bVar1 * '\x06' & 0xf;
  *(char *)(unaff_EBP + 0x54004737) = *(char *)(unaff_EBP + 0x54004737) + unaff_BL;
  bVar2 = 9 < bVar3 || bVar1;
  bVar3 = bVar3 + bVar2 * '\x06' & 0xf;
  cVar9 = (char)((uint)in_EAX >> 8) + bVar1 + bVar2;
  *(char *)&param_1->_padding_ = (char)param_1->_padding_ + cVar9;
  bVar2 = 9 < bVar3 || bVar2;
  uVar5 = CONCAT31((int3)((uint)in_EAX >> 8),bVar3 + bVar2 * '\x06') & 0xffff000f;
  cVar4 = (char)uVar5;
  pcVar6 = (char *)CONCAT22((short)(uVar5 >> 0x10),CONCAT11(cVar9 + bVar2,cVar4));
  pcVar6[0x38] = pcVar6[0x38] + param_2;
  *pcVar6 = *pcVar6 + cVar4;
  iVar7 = CONCAT31((int3)((uint)pcVar6 >> 8),cVar4 + '$');
  *(int *)((int)&param_3 + iVar7) = *(int *)((int)&param_3 + iVar7) + iVar7;
  if (((param_5 == 0x101) && (param_1->key_down != 0)) && (param_6 == param_1->key_down)) {
    param_1->key_down = 0;
    if (param_1->buttonTypeValue != Radio) {
      param_1->is_down = 0;
    }
    (**(code **)(param_1->_padding_ + 0x20))(1);
    SendMessageA(*(undefined4 *)(param_1->_padding_ + 4),0xf,0,0);
    TButtonPanel::do_action(param_1);
    return 1;
  }
  lVar8 = TPanel::wnd_proc((TPanel *)param_1,param_4,param_5,param_6,param_7);
  return lVar8;
}

// --------------------------------------------------

// Function: FUN_00473913
// Address: 00473913
undefined4 FUN_00473913(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00473925
// Address: 00473925
bool __thiscall FUN_00473925(int *param_1,int param_2,int param_3)
{
  uchar uVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0xbc))(param_2,param_3);
  if (iVar2 == 0) {
    return false;
  }
  if (param_1[100] == 0) {
    if ((TShape *)param_1[*(short *)((int)param_1 + 0x1f6) + 0x53] != (TShape *)0x0) {
      uVar1 = TShape::shape_check((TShape *)param_1[*(short *)((int)param_1 + 0x1f6) + 0x53],
                                  (param_2 - param_1[0x62]) - param_1[3],
                                  (param_3 - param_1[99]) - param_1[4],
                                  (int)*(short *)((int)param_1 +
                                                 *(short *)((int)param_1 + 0x1f6) * 2 + 0x170));
      return uVar1 != '\0';
    }
  }
  return true;
}

// --------------------------------------------------

// Function: FUN_004739ac
// Address: 004739ac
void __fastcall FUN_004739ac(TButtonPanel *param_1)
{
  short sVar1;
  
  if (param_1->buttonTypeValue == State) {
    if ((int)param_1->cur_state == param_1->num_states + -1) {
      (**(code **)(param_1->_padding_ + 0xe0))(0);
    }
    else {
      (**(code **)(param_1->_padding_ + 0xe0))((ushort)param_1->cur_state + 1);
    }
  }
  else if (param_1->buttonTypeValue == Radio) {
    TButtonPanel::set_radio_button(param_1);
  }
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0xb4))
              (param_1,3,param_1->id[param_1->cur_state],param_1->id2[param_1->cur_state]);
  }
  if (param_1->notifyTypeValue == NotifyAction) {
    if ((int *)param_1->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xb4))
                (param_1,1,param_1->id[param_1->cur_state],param_1->id2[param_1->cur_state]);
      return;
    }
  }
  else {
    sVar1 = param_1->cur_state;
    if ((param_1->id[sVar1] != 0) || (param_1->id2[sVar1] != 0)) {
      SendMessageA(*(undefined4 *)(param_1->_padding_ + 4),0x111,param_1->id[sVar1],
                   param_1->id2[sVar1]);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00473a96
// Address: 00473a96
void __fastcall FUN_00473a96(TButtonPanel *param_1)
{
  long lVar1;
  long lVar2;
  
  if (param_1->buttonTypeValue == State) {
    if ((int)param_1->cur_state == param_1->num_states + -1) {
      (**(code **)(param_1->_padding_ + 0xe0))(0);
    }
    else {
      (**(code **)(param_1->_padding_ + 0xe0))((ushort)param_1->cur_state + 1);
    }
  }
  else if (param_1->buttonTypeValue == Radio) {
    TButtonPanel::set_radio_button(param_1);
  }
  lVar1 = param_1->id[param_1->cur_state];
  lVar2 = param_1->id2[param_1->cur_state];
  if ((int *)param_1->_padding_ != (int *)0x0) {
    (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,6,lVar1,lVar2);
  }
  if (param_1->notifyTypeValue == NotifyAction) {
    if ((int *)param_1->_padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1->_padding_ + 0xb4))(param_1,4,lVar1,lVar2);
      return;
    }
  }
  else if ((param_1->id[param_1->cur_state] != 0) || (param_1->id2[param_1->cur_state] != 0)) {
    SendMessageA(*(undefined4 *)(param_1->_padding_ + 4),0x111,lVar1,lVar2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00473b71
// Address: 00473b71
void __fastcall FUN_00473b71(TPanel *param_1)
{
  TPanel::release_mouse(param_1);
  if (param_1[2].pnl_y != 0) {
    if (param_1[1].top_panel != (TPanel *)0x2) {
      param_1[2].pnl_y = 0;
    }
    (**(code **)(param_1->_padding_ + 0x20))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00473bbd
// Address: 00473bbd
void __fastcall FUN_00473bbd(int param_1)
{
  if (*(int *)(param_1 + 0x148) != 0) {
    *(undefined4 *)(param_1 + 0x148) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00473bd5
// Address: 00473bd5
undefined4 __fastcall FUN_00473bd5(int param_1)
{
  TDigital *pTVar1;
  
  if (*(int *)(param_1 + 0x2b4) != -1) {
    pTVar1 = RGE_Base_Game::get_sound(rge_base_game,*(int *)(param_1 + 0x2b4));
    *(TDigital **)(param_1 + 0x148) = pTVar1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00473c07
// Address: 00473c07
TEasy_Panel * __thiscall FUN_00473c07(TEasy_Panel *param_1,char *param_2)
{
  TEasy_Panel::TEasy_Panel(param_1,param_2);
  param_1[1]._padding_ = 0xb;
  param_1[1]._padding_ = 0xb;
  param_1[1]._padding_ = 0xb;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&TDialogPanel::_vftable_;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00473c54
// Address: 00473c54
TDialogPanel * __thiscall FUN_00473c54(TDialogPanel *param_1,byte param_2)
{
  TDialogPanel::~TDialogPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00473c7e
// Address: 00473c7e
undefined4 __thiscall
FUN_00473c7e(TEasy_Panel *param_1,TDrawArea *param_2,TPanel *param_3,int param_4,int param_5,
            char *param_6,long param_7,int param_8)
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
    TPanel::xPosition(param_3);
    TPanel::yPosition(param_3);
  }
  lVar3 = TEasy_Panel::setup(param_1,param_2,param_3,param_6,param_7,0,iVar1 / 2 - param_4 / 2,
                             iVar2 / 2 - param_5 / 2,param_4,param_5,param_8);
  if (lVar3 == 0) {
    param_1->_padding_ = 1;
    return 0;
  }
  this = (TPanel *)param_1->_padding_;
  if (this != (TPanel *)0x0) {
    param_1[1]._padding_ = (int)this->curr_child;
    TPanel::set_curr_child(this,(TPanel *)param_1);
  }
  TPanel::set_z_order((TPanel *)param_1,'\x01',0);
  TPanelSystem::setModalPanel(&panel_system,(TPanel *)param_1);
  return 1;
}

// --------------------------------------------------


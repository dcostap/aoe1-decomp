// GLOBAL FUNCTIONS PART 2200
// Function: FUN_00459456
// Address: 00459456
// XREFS: None
uint __thiscall FUN_00459456(int param_1,short param_2,short param_3)
{
  byte bVar1;
  uint3 uVar3;
  uint uVar2;
  
  bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x8d8c) + param_3 * 4) + 6 + param_2 * 0x18);
  uVar3 = (uint3)((uint)(param_2 * 3) >> 8);
  uVar2 = CONCAT31(uVar3,bVar1) & 0xffffff0f;
  _param_3 = bVar1 & 0xf;
  if ((0x10 < (byte)uVar2) || (*(char *)(_param_3 * 0x5a0 + 0x338c + param_1) == '\0')) {
    uVar2 = (uint)uVar3 << 8;
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_004594ab
// Address: 004594ab
// XREFS: None
void __thiscall
FUN_004594ab(int param_1,short param_2,short param_3,short param_4,short param_5,char param_6)
{
  byte bVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  byte bVar5;
  int iVar6;
  undefined4 uStack_4;
  
  sVar4 = param_5;
  if (param_5 < param_3) {
    sVar4 = param_3;
    param_3 = param_5;
  }
  sVar2 = param_4;
  if (param_4 < param_2) {
    sVar2 = param_2;
    param_2 = param_4;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (*(int *)(param_1 + 0xc) <= (int)sVar4) {
    sVar4 = *(short *)(param_1 + 0xc) + -1;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (*(int *)(param_1 + 8) <= (int)sVar2) {
    sVar2 = *(short *)(param_1 + 8) + -1;
  }
  if (param_3 <= sVar4) {
    iVar6 = (int)param_3;
    _param_3 = iVar6 * 4;
    uStack_4 = (sVar4 - iVar6) + 1;
    do {
      if (param_2 <= sVar2) {
        iVar6 = param_2 * 0x18;
        _param_5 = ((int)sVar2 - (int)param_2) + 1;
        do {
          iVar3 = *(int *)(*(int *)(param_1 + 0x8d8c) + _param_3);
          bVar1 = *(byte *)(iVar3 + 5 + iVar6);
          iVar3 = iVar3 + iVar6;
          if (param_6 == '\0') {
            bVar5 = *(byte *)(param_1 + 0xba + (short)(ushort)(bVar1 & 0x1f) * 0x198);
          }
          else {
            bVar5 = *(byte *)(param_1 + 0xb9 + (short)(ushort)(bVar1 & 0x1f) * 0x198);
          }
          iVar6 = iVar6 + 0x18;
          *(byte *)(iVar3 + 5) = (bVar5 ^ bVar1) & 0x1f ^ bVar1;
          _param_5 = _param_5 + -1;
        } while (_param_5 != 0);
      }
      _param_3 = _param_3 + 4;
      uStack_4 = uStack_4 + -1;
    } while (uStack_4 != 0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004595df
// Address: 004595df
// XREFS: None
void __thiscall
FUN_004595df(RGE_Map *param_1,short param_2,short param_3,short param_4,short param_5,byte param_6,
            short param_7,char param_8)
{
  RGE_Player *pRVar1;
  int *piVar2;
  int *piVar3;
  uchar uVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  short sVar12;
  int iVar13;
  int iStack_8;
  
  pRVar1 = param_1->game_world->players[param_1->game_world->curr_player];
  sVar5 = param_5;
  if (param_5 < param_3) {
    sVar5 = param_3;
    param_3 = param_5;
  }
  sVar6 = param_4;
  if (param_4 < param_2) {
    sVar6 = param_2;
    param_2 = param_4;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1->map_height <= (int)sVar5) {
    sVar5 = (short)param_1->map_height + -1;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1->map_width <= (int)sVar6) {
    sVar6 = (short)param_1->map_width + -1;
  }
  if (param_8 != '\0') {
    if (param_7 == 0) {
      if (8 < param_6) {
        param_6 = 0;
      }
      if (param_3 <= sVar5) {
        iVar10 = param_3 * 4;
        _param_8 = ((int)sVar5 - (int)param_3) + 1;
        do {
          if (param_2 <= sVar6) {
            iVar11 = param_2 * 0x18;
            iVar13 = ((int)sVar6 - (int)param_2) + 1;
            do {
              iVar8 = *(int *)(iVar10 + (int)param_1->map_row_offset) + iVar11;
              iVar11 = iVar11 + 0x18;
              iVar13 = iVar13 + -1;
              *(byte *)(iVar8 + 5) = *(byte *)(iVar8 + 5) & 0x1f | param_6 << 5;
            } while (iVar13 != 0);
          }
          iVar10 = iVar10 + 4;
          _param_8 = _param_8 + -1;
        } while (_param_8 != 0);
      }
    }
    else if (param_3 <= sVar5) {
      iVar10 = param_3 * 4;
      _param_6 = ((int)sVar5 - (int)param_3) + 1;
      do {
        if (param_2 <= sVar6) {
          iVar11 = param_2 * 0x18;
          iVar13 = ((int)sVar6 - (int)param_2) + 1;
          do {
            iVar8 = *(int *)(iVar10 + (int)param_1->map_row_offset) + iVar11;
            sVar7 = (ushort)(*(byte *)(iVar8 + 5) >> 5) + param_7;
            if (sVar7 < 0) {
              sVar7 = 0;
            }
            else if (0xff < sVar7) {
              sVar7 = 0xff;
            }
            bVar9 = *(byte *)(iVar8 + 5) & 0x1f;
            *(byte *)(iVar8 + 5) = (byte)sVar7 << 5 | bVar9;
            if (8 < ((byte)sVar7 & 7)) {
              *(byte *)(iVar8 + 5) = bVar9;
            }
            iVar11 = iVar11 + 0x18;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        iVar10 = iVar10 + 4;
        _param_6 = _param_6 + -1;
      } while (_param_6 != 0);
    }
  }
  if (0 < param_3) {
    param_3 = param_3 + -1;
  }
  if ((int)sVar5 < param_1->map_height + -1) {
    sVar5 = sVar5 + 1;
  }
  if (0 < param_2) {
    param_2 = param_2 + -1;
  }
  if ((int)sVar6 < param_1->map_width + -1) {
    sVar6 = sVar6 + 1;
  }
  if (param_3 <= sVar5) {
    _param_7 = (int)param_3;
    iStack_8 = _param_7 << 2;
    sVar7 = param_3;
    do {
      if (param_2 <= sVar6) {
        _param_6 = (int)param_2;
        iVar10 = _param_6 * 0x18;
        sVar12 = param_2;
        do {
          iVar11 = *(int *)(iStack_8 + (int)param_1->map_row_offset) + iVar10;
          uVar4 = RGE_Map::get_tile_type(param_1,sVar12,sVar7);
          *(uchar *)(iVar11 + 4) = uVar4;
          for (piVar2 = *(int **)(iVar11 + 0x10); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
            piVar3 = (int *)*piVar2;
            (**(code **)(*piVar3 + 0x34))(piVar3[0xe],piVar3[0xf],0);
          }
          if (param_1->game_world->game_state != '\x03') {
            RGE_Tile_List::add_node(&pRVar1->diam_tile_list,_param_6,_param_7);
          }
          sVar12 = sVar12 + 1;
          _param_6 = _param_6 + 1;
          iVar10 = iVar10 + 0x18;
        } while (sVar12 <= sVar6);
      }
      sVar7 = sVar7 + 1;
      _param_7 = _param_7 + 1;
      iStack_8 = iStack_8 + 4;
    } while (sVar7 <= sVar5);
  }
  RGE_Map::set_map_screen_pos(param_1,(int)param_2,(int)param_3,(int)sVar6,(int)sVar5);
  RGE_Map::request_redraw(param_1,(int)param_2,(int)param_3,(int)sVar6,(int)sVar5,'\0');
  return;
}

// --------------------------------------------------

// Function: FUN_004598f8
// Address: 004598f8
// XREFS: None
void __thiscall
FUN_004598f8(RGE_Map *param_1,RGE_Game_World *param_2,short param_3,short param_4,byte param_5,
            int param_6,int param_7)
{
  byte bVar1;
  RGE_Player *pRVar2;
  RGE_Player *pRVar3;
  int iVar4;
  int iVar5;
  
  pRVar2 = *param_2->players;
  iVar4 = (int)param_4;
  iVar5 = (int)param_3;
  pRVar3 = param_1->game_world->players[param_1->game_world->curr_player];
  bVar1 = param_1->map_row_offset[iVar4][iVar5].field_0x5;
  if (((ushort)(bVar1 & 0x1f) != (ushort)param_5) &&
     (param_1->map_row_offset[iVar4][iVar5].field_0x5 = (param_5 ^ bVar1) & 0x1f ^ bVar1,
     pRVar2 != (RGE_Player *)0x0)) {
    RGE_Map::request_redraw(param_1,iVar5,iVar4,iVar5,iVar4,'\0');
    if (param_2->game_state != '\x03') {
      RGE_Tile_List::add_node(&pRVar3->diam_tile_list,iVar5,iVar4);
    }
    iVar4 = RGE_Map::clear_terrain_object
                      (param_1,param_2,param_4,param_3,(ushort)(bVar1 & 0x1f),1,param_6,param_7);
    RGE_Map::place_terrain_object(param_1,pRVar2,param_2,param_4,param_3,iVar4,0);
    RGE_Map::get_border_type(param_1,param_3,param_4);
    return;
  }
  RGE_Map::get_border_type(param_1,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_004599ff
// Address: 004599ff
// XREFS: None
void __thiscall
FUN_004599ff(RGE_Map *param_1,RGE_Game_World *param_2,short param_3,short param_4,byte param_5,
            int param_6,int param_7)
{
  byte bVar1;
  RGE_Player *pRVar2;
  int iVar3;
  
  pRVar2 = *param_2->players;
  bVar1 = param_1->map_row_offset[param_4][param_3].field_0x5;
  param_1->map_row_offset[param_4][param_3].field_0x5 = (param_5 ^ bVar1) & 0x1f ^ bVar1;
  if (pRVar2 != (RGE_Player *)0x0) {
    iVar3 = RGE_Map::clear_terrain_object(param_1,param_2,param_4,param_3,-1,1,param_6,param_7);
    RGE_Map::place_terrain_object(param_1,pRVar2,param_2,param_4,param_3,iVar3,1);
  }
  RGE_Map::get_border_type(param_1,param_3,param_4);
  return;
}

// --------------------------------------------------

// Function: FUN_00459a8a
// Address: 00459a8a
// XREFS: None
void __thiscall
FUN_00459a8a(RGE_Map *param_1,RGE_Player *param_2,RGE_Game_World *param_3,short param_4,
            short param_5,short param_6,short param_7,byte param_8,char param_9,int param_10)
{
  byte bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  byte *pbVar8;
  
  if ((short)(ushort)param_8 < param_1->num_terrain) {
    uVar4 = (uint)param_8;
    if ((param_1->terrain_types[uVar4].loaded != '\0') ||
       ((sVar2 = param_1->terrain_types[uVar4].terrain_to_draw, -1 < sVar2 &&
        (param_1->terrain_types[sVar2].loaded == '\x01')))) {
      sVar2 = param_7;
      if (param_7 < param_5) {
        sVar2 = param_5;
        param_5 = param_7;
      }
      sVar3 = param_6;
      if (param_6 < param_4) {
        sVar3 = param_4;
        param_4 = param_6;
      }
      if (param_5 < 0) {
        param_5 = 0;
      }
      if (param_1->map_height <= (int)sVar2) {
        sVar2 = (short)param_1->map_height + -1;
      }
      if (param_4 < 0) {
        param_4 = 0;
      }
      if (param_1->map_width <= (int)sVar3) {
        sVar3 = (short)param_1->map_width + -1;
      }
      if (((param_9 != '\0') || (param_2 != (RGE_Player *)0x0)) && (param_5 <= sVar2)) {
        iVar5 = (int)param_5 << 2;
        sVar7 = param_5;
        do {
          if (param_4 <= sVar3) {
            pbVar8 = (byte *)(*(int *)(iVar5 + (int)param_1->map_row_offset) + param_4 * 0x18 + 5);
            sVar6 = param_4;
            do {
              if (0 < param_1->terrain_types[uVar4].tiles[pbVar8[-1]].count) {
                bVar1 = *pbVar8;
                if (((ushort)(bVar1 & 0x1f) != (ushort)param_8) && (param_9 != '\0')) {
                  *pbVar8 = (param_8 ^ bVar1) & 0x1f ^ bVar1;
                }
                if (param_2 != (RGE_Player *)0x0) {
                  RGE_Map::create_terrain_object
                            (param_1,param_2,param_3,sVar7,sVar6,(ushort)(bVar1 & 0x1f),param_10,-1,
                             -1);
                }
              }
              sVar6 = sVar6 + 1;
              pbVar8 = pbVar8 + 0x18;
            } while (sVar6 <= sVar3);
          }
          sVar7 = sVar7 + 1;
          iVar5 = iVar5 + 4;
        } while (sVar7 <= sVar2);
      }
      if (0 < param_5) {
        param_5 = param_5 + -1;
      }
      if ((int)sVar2 < param_1->map_height + -1) {
        sVar2 = sVar2 + 1;
      }
      if (0 < param_4) {
        param_4 = param_4 + -1;
      }
      sVar7 = param_5;
      if ((int)sVar3 < param_1->map_width + -1) {
        sVar3 = sVar3 + 1;
      }
      for (; sVar6 = param_4, sVar7 <= sVar2; sVar7 = sVar7 + 1) {
        for (; sVar6 <= sVar3; sVar6 = sVar6 + 1) {
          RGE_Map::get_border_type(param_1,sVar6,sVar7);
        }
      }
      RGE_Map::request_redraw(param_1,(int)param_4,(int)param_5,(int)sVar3,(int)sVar2,'\0');
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00459d19
// Address: 00459d19
// XREFS: None
uint __thiscall FUN_00459d19(int param_1,short param_2,short param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  short sVar7;
  short sVar8;
  undefined4 in_EAX;
  uint uVar9;
  int iVar10;
  undefined3 uVar12;
  uint uVar11;
  short sVar13;
  short sVar14;
  int iVar15;
  short sVar16;
  uint uVar17;
  short sVar18;
  undefined4 unaff_EDI;
  uint uVar19;
  uint uStack_1c;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  
  sVar7 = param_2;
  uVar11 = CONCAT22((short)((uint)in_EAX >> 0x10),param_2);
  if (-1 < param_2) {
    iVar2 = *(int *)(param_1 + 8);
    uVar9 = (uint)param_2;
    uVar11 = uVar9;
    if (((int)uVar9 < iVar2) && (-1 < param_3)) {
      iVar3 = *(int *)(param_1 + 0xc);
      iVar15 = (int)param_3;
      if (iVar15 < iVar3) {
        iVar4 = *(int *)(param_1 + 0x8d8c);
        iVar10 = uVar9 * 0x18;
        iVar5 = *(int *)(iVar4 + iVar15 * 4);
        iVar1 = iVar10 + iVar5;
        uVar19 = CONCAT22((short)((uint)unaff_EDI >> 0x10),
                          (ushort)(*(byte *)(iVar10 + 5 + iVar5) >> 5));
        uVar11 = uVar19 + 1;
        iVar5 = uVar19 - 1;
        uStack_10 = uVar19;
        if ((0 < param_3) && ((int)uVar9 < iVar2 + -1)) {
          uStack_10 = (uint)(*(byte *)(*(int *)(iVar4 + -4 + iVar15 * 4) + 0x1d + iVar10) >> 5);
        }
        uStack_14 = uVar19;
        if (0 < param_3) {
          uStack_14 = (uint)(*(byte *)(*(int *)(iVar4 + -4 + iVar15 * 4) + 5 + iVar10) >> 5);
        }
        uStack_1c = uVar19;
        if ((int)uVar9 < iVar2 + -1) {
          uStack_1c = (uint)(*(byte *)(iVar1 + 0x1d) >> 5);
        }
        uStack_c = uVar19;
        if ((0 < param_2) && (iVar15 < iVar3 + -1)) {
          uStack_c = (uint)(*(byte *)(*(int *)(iVar4 + 4 + iVar15 * 4) + -0x13 + iVar10) >> 5);
        }
        bVar6 = 0 < param_2;
        _param_2 = uVar19;
        if (bVar6) {
          _param_2 = (uint)(*(byte *)(iVar1 + -0x13) >> 5);
        }
        uVar17 = uVar19;
        if (iVar15 < iVar3 + -1) {
          uVar17 = (uint)(*(byte *)(*(int *)(iVar4 + 4 + iVar15 * 4) + 5 + iVar10) >> 5);
        }
        bVar6 = 0 < param_3;
        _param_3 = uVar19;
        if ((bVar6) && (0 < sVar7)) {
          _param_3 = (uint)(*(byte *)(*(int *)(iVar4 + -4 + iVar15 * 4) + -0x13 + iVar10) >> 5);
        }
        if ((iVar15 < iVar3 + -1) && ((int)uVar9 < iVar2 + -1)) {
          uVar19 = (uint)(*(byte *)(*(int *)(iVar4 + 4 + iVar15 * 4) + 0x1d + iVar10) >> 5);
        }
        sVar7 = (short)uVar11;
        sVar13 = (short)uStack_14;
        uVar12 = (undefined3)(uVar11 >> 8);
        sVar18 = (short)uStack_1c;
        if ((sVar13 == sVar7) && (sVar18 == sVar7)) {
          return CONCAT31(uVar12,0xe);
        }
        sVar14 = (short)_param_2;
        sVar16 = (short)uVar17;
        if ((sVar14 == sVar7) && (sVar16 == sVar7)) {
          return CONCAT31(uVar12,0xd);
        }
        if ((sVar13 == sVar7) && (sVar14 == sVar7)) {
          return CONCAT31(uVar12,0x10);
        }
        if ((sVar18 == sVar7) && (sVar16 == sVar7)) {
          return CONCAT31(uVar12,0xf);
        }
        if (sVar13 == sVar7) {
          return CONCAT31(uVar12,6);
        }
        if (sVar18 == sVar7) {
          return CONCAT31(uVar12,8);
        }
        if (sVar14 == sVar7) {
          return CONCAT31(uVar12,5);
        }
        if (sVar16 == sVar7) {
          return CONCAT31(uVar12,7);
        }
        sVar8 = (short)iVar5;
        uVar12 = (undefined3)((uint)iVar5 >> 8);
        if ((short)uStack_10 == sVar7) {
          if ((sVar14 == sVar8) && (sVar16 == sVar8)) {
            return CONCAT31(uVar12,2);
          }
          return CONCAT31(uVar12,10);
        }
        if ((short)uStack_c == sVar7) {
          if ((sVar13 == sVar8) && (sVar18 == sVar8)) {
            return CONCAT31(uVar12,1);
          }
          return CONCAT31(uVar12,9);
        }
        if (param_3 == sVar7) {
          if ((sVar18 == sVar8) && (sVar16 == sVar8)) {
            return CONCAT31(uVar12,3);
          }
          return CONCAT31(uVar12,0xb);
        }
        if ((short)uVar19 == sVar7) {
          if ((sVar13 == sVar8) && (sVar14 == sVar8)) {
            return CONCAT31(uVar12,4);
          }
          return CONCAT31(uVar12,0xc);
        }
      }
    }
  }
  return uVar11 & 0xffffff00;
}

// --------------------------------------------------

// Function: FUN_0045a026
// Address: 0045a026
// XREFS: None
void __thiscall FUN_0045a026(RGE_Map *param_1,uint param_2,uint param_3)
{
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  RGE_Tile **ppRVar5;
  bool bVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte bVar11;
  uint uVar12;
  char cVar13;
  uchar uVar14;
  uint uStack_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  RGE_Tile *pRStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  int iStack_8;
  uint uStack_4;
  
  if ((((-1 < (short)param_2) && (iVar8 = (int)(short)param_2, iVar8 < param_1->map_width)) &&
      (-1 < (short)param_3)) && (iVar9 = (int)(short)param_3, iVar9 < param_1->map_height)) {
    ppRVar5 = param_1->map_row_offset;
    pRStack_18 = ppRVar5[iVar9] + iVar8;
    bVar1 = pRStack_18->field_0x5;
    bVar11 = bVar1 & 0x1f;
    uStack_4 = CONCAT31(uStack_4._1_3_,bVar1) & 0xffffff1f;
    bVar7 = bVar1;
    if (0 < (short)param_3) {
      bVar7 = ppRVar5[iVar9 + -1][iVar8].field_0x5;
    }
    uStack_28 = CONCAT31(uStack_28._1_3_,bVar7) & 0xffffff1f;
    iVar10 = param_1->map_height + -1;
    bVar7 = bVar1;
    if (iVar9 < iVar10) {
      bVar7 = ppRVar5[iVar9 + 1][iVar8].field_0x5;
    }
    uStack_1c = CONCAT31(uStack_1c._1_3_,bVar7) & 0xffffff1f;
    bVar7 = bVar1;
    if (0 < (short)param_2) {
      bVar7 = ppRVar5[iVar9][iVar8 + -1].field_0x5;
    }
    uStack_24 = CONCAT31(uStack_24._1_3_,bVar7) & 0xffffff1f;
    iStack_8 = param_1->map_width + -1;
    bVar7 = bVar1;
    if (iVar8 < iStack_8) {
      bVar7 = ppRVar5[iVar9][iVar8 + 1].field_0x5;
    }
    uStack_20 = CONCAT31(uStack_20._1_3_,bVar7) & 0xffffff1f;
    bVar7 = bVar1;
    if ((0 < (short)param_3) && (0 < (short)param_2)) {
      bVar7 = ppRVar5[iVar9 + -1][iVar8 + -1].field_0x5;
    }
    uStack_14 = CONCAT31(uStack_14._1_3_,bVar7) & 0xffffff1f;
    bVar6 = 0 < (short)param_3;
    bVar7 = bVar1;
    if ((bVar6) && (iVar8 < iStack_8)) {
      bVar7 = ppRVar5[iVar9 + -1][iVar8 + 1].field_0x5;
    }
    param_3 = CONCAT31(param_3._1_3_,bVar7) & 0xffffff1f;
    uStack_10._1_3_ = (undefined3)((uint)iVar10 >> 8);
    bVar7 = bVar1;
    if ((iVar9 < iVar10) && (0 < (short)param_2)) {
      bVar7 = ppRVar5[iVar9 + 1][iVar8 + -1].field_0x5;
    }
    uStack_10 = CONCAT31(uStack_10._1_3_,bVar7) & 0xffffff1f;
    uStack_c._1_3_ = (int3)(char)(param_2 >> 8);
    bVar7 = bVar1;
    if ((iVar9 < iVar10) && (iVar8 < iStack_8)) {
      bVar7 = ppRVar5[iVar9 + 1][iVar8 + 1].field_0x5;
    }
    uStack_c = CONCAT31(uStack_c._1_3_,bVar7) & 0xffffff1f;
    uVar14 = (uchar)uStack_4;
    RGE_Map::check_for_border(param_1,uVar14,(uchar *)&uStack_28);
    RGE_Map::check_for_border(param_1,uVar14,(uchar *)&uStack_1c);
    RGE_Map::check_for_border(param_1,uVar14,(uchar *)&uStack_24);
    RGE_Map::check_for_border(param_1,uVar14,(uchar *)&uStack_20);
    RGE_Map::check_for_border(param_1,uVar14,(uchar *)&uStack_14);
    RGE_Map::check_for_border(param_1,uVar14,(uchar *)&param_3);
    RGE_Map::check_for_border(param_1,uVar14,(uchar *)&uStack_10);
    RGE_Map::check_for_border(param_1,uVar14,(uchar *)&uStack_c);
    bVar7 = (byte)uStack_28;
    if (((((byte)uStack_28 != bVar11) || (bVar7 = (byte)uStack_1c, (byte)uStack_1c != bVar11)) ||
        (bVar7 = (byte)uStack_24, (byte)uStack_24 != bVar11)) ||
       (((bVar7 = (byte)uStack_20, (byte)uStack_20 != bVar11 ||
         (bVar7 = (byte)uStack_14, (byte)uStack_14 != bVar11)) ||
        ((bVar7 = (byte)param_3, (byte)param_3 != bVar11 ||
         ((bVar7 = (byte)uStack_10, (byte)uStack_10 != bVar11 ||
          (bVar7 = (byte)uStack_c, (byte)uStack_c != bVar11)))))))) {
      uVar12 = bVar1 & 0x1f;
      param_2 = (uint)bVar7;
      sVar2 = param_1->terrain_types[uVar12].borders[param_2];
      if ((sVar2 == -1) ||
         (((sVar2 < 0 || (0xf < sVar2)) || (param_1->border_types[sVar2].loaded == '\0')))) {
        pRStack_18->field_0x6 = 0;
        return;
      }
      if (param_1->border_types[sVar2].border_style == 1) {
        cVar13 = param_1->terrain_types[uVar12].borders[uStack_28 & 0xff] == sVar2;
        if (param_1->terrain_types[uVar12].borders[uStack_1c & 0xff] == sVar2) {
          cVar13 = cVar13 + '\x02';
        }
        if (param_1->terrain_types[uVar12].borders[uStack_24 & 0xff] == sVar2) {
          cVar13 = cVar13 + '\x04';
        }
        if (param_1->terrain_types[uVar12].borders[uStack_20 & 0xff] == sVar2) {
          cVar13 = cVar13 + '\b';
        }
        pRStack_18->field_0x6 = (byte)sVar2 & 0xf | cVar13 << 4;
        return;
      }
      sVar3 = param_1->terrain_types[uVar12].borders[uStack_28 & 0xff];
      if ((sVar3 == sVar2) && (param_1->terrain_types[uVar12].borders[uStack_24 & 0xff] == sVar2)) {
        cVar13 = '\x01';
      }
      else if ((sVar3 == sVar2) &&
              (param_1->terrain_types[uVar12].borders[uStack_20 & 0xff] == sVar2)) {
        cVar13 = '\x02';
      }
      else {
        sVar4 = param_1->terrain_types[uVar12].borders[uStack_1c & 0xff];
        if (sVar4 == sVar2) {
          if (param_1->terrain_types[uVar12].borders[uStack_24 & 0xff] == sVar2) {
            cVar13 = '\x03';
            goto LAB_0045a436;
          }
          if ((sVar4 == sVar2) &&
             (param_1->terrain_types[uVar12].borders[uStack_20 & 0xff] == sVar2)) {
            cVar13 = '\x04';
            goto LAB_0045a436;
          }
        }
        if (sVar3 == sVar2) {
          cVar13 = '\t';
        }
        else if (sVar4 == sVar2) {
          cVar13 = '\n';
        }
        else if (param_1->terrain_types[uVar12].borders[uStack_24 & 0xff] == sVar2) {
          cVar13 = '\v';
        }
        else if (param_1->terrain_types[uVar12].borders[uStack_20 & 0xff] == sVar2) {
          cVar13 = '\f';
        }
        else if (param_1->terrain_types[uVar12].borders[uStack_14 & 0xff] == sVar2) {
          cVar13 = '\x05';
        }
        else if (param_1->terrain_types[uVar12].borders[param_3 & 0xff] == sVar2) {
          cVar13 = '\x06';
        }
        else if (param_1->terrain_types[uVar12].borders[uStack_10 & 0xff] == sVar2) {
          cVar13 = '\a';
        }
        else {
          if (param_1->terrain_types[uVar12].borders[uStack_c & 0xff] != sVar2) {
            pRStack_18->field_0x6 = 0;
            return;
          }
          cVar13 = '\b';
        }
      }
LAB_0045a436:
      pRStack_18->field_0x6 = (byte)sVar2 & 0xf | cVar13 << 4;
      return;
    }
    pRStack_18->field_0x6 = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045a48b
// Address: 0045a48b
// XREFS: None
void __thiscall FUN_0045a48b(int param_1,byte param_2,byte *param_3)
{
  short sVar1;
  
  if ((*param_3 != param_2) &&
     ((((sVar1 = *(short *)(param_1 + 0x14a + ((uint)*param_3 + (uint)param_2 * 0xcc) * 2),
        sVar1 == -1 || (sVar1 < 0)) || (0xf < sVar1)) ||
      (*(char *)(sVar1 * 0x5a0 + 0x338c + param_1) == '\0')))) {
    *param_3 = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045a4f6
// Address: 0045a4f6
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045a4f6(int param_1,uint param_2)
{
  int iVar1;
  short sVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  if (99 < param_2 - DAT_0062e65c) {
    sVar7 = 0;
    fVar3 = (float)param_2 * _DAT_005706e8;
    if (0 < *(short *)(param_1 + 0x8d90)) {
      do {
        iVar1 = param_1 + 0x8c + sVar7 * 0x198;
        if ((*(char *)(param_1 + 0xbb + sVar7 * 0x198) != '\0') &&
           (*(float *)(iVar1 + 0x34) <= fVar3 - *(float *)(iVar1 + 0x40))) {
          sVar4 = __ftol();
          sVar2 = *(short *)(iVar1 + 0x30);
          sVar5 = *(short *)(iVar1 + 0x32) + sVar2;
          sVar6 = sVar4 + *(short *)(iVar1 + 0x3c);
          if (sVar5 <= sVar6) {
            sVar6 = sVar6 % sVar5;
          }
          *(short *)(iVar1 + 0x3c) = sVar6;
          if (sVar2 <= sVar6) {
            sVar6 = sVar2 + -1;
          }
          if (*(short *)(iVar1 + 0x3e) != sVar6) {
            *(short *)(iVar1 + 0x3e) = sVar6;
            *(undefined1 *)(iVar1 + 0x44) = 1;
            *(undefined1 *)(param_1 + 0x8dac) = 1;
          }
          *(float *)(iVar1 + 0x40) =
               (float)((float10)fVar3 -
                      (extraout_ST0 - (float10)(int)sVar4 * (float10)*(float *)(iVar1 + 0x34)));
        }
        sVar7 = sVar7 + 1;
      } while (sVar7 < *(short *)(param_1 + 0x8d90));
    }
    sVar7 = 0;
    if (0 < *(short *)(param_1 + 0x8d92)) {
      do {
        iVar1 = sVar7 * 0x5a0 + 0x338c + param_1;
        if ((*(char *)(sVar7 * 0x5a0 + 0x33b7 + param_1) != '\0') &&
           (*(float *)(iVar1 + 0x30) <= fVar3 - *(float *)(iVar1 + 0x3c))) {
          sVar4 = __ftol();
          sVar2 = *(short *)(iVar1 + 0x2c);
          sVar5 = *(short *)(iVar1 + 0x2e) + sVar2;
          sVar6 = sVar4 + *(short *)(iVar1 + 0x38);
          if (sVar5 <= sVar6) {
            sVar6 = sVar6 % sVar5;
          }
          *(short *)(iVar1 + 0x38) = sVar6;
          if (sVar2 <= sVar6) {
            sVar6 = sVar2 + -1;
          }
          if (*(short *)(iVar1 + 0x3a) != sVar6) {
            *(short *)(iVar1 + 0x3a) = sVar6;
            *(undefined1 *)(iVar1 + 0x40) = 1;
            *(undefined1 *)(param_1 + 0x8dac) = 1;
          }
          *(float *)(iVar1 + 0x3c) =
               (float)((float10)fVar3 -
                      (extraout_ST0_00 - (float10)(int)sVar4 * (float10)*(float *)(iVar1 + 0x30)));
        }
        sVar7 = sVar7 + 1;
      } while (sVar7 < *(short *)(param_1 + 0x8d92));
    }
    DAT_0062e65c = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045a6ce
// Address: 0045a6ce
// XREFS: None
void FUN_0045a6ce(short *param_1,short *param_2)
{
  short sVar1;
  short in_stack_00000018;
  short in_stack_0000001c;
  
  sVar1 = __ftol();
  *param_1 = sVar1 + in_stack_00000018;
  sVar1 = __ftol();
  *param_2 = sVar1 + -0x10 + in_stack_0000001c;
  return;
}

// --------------------------------------------------

// Function: FUN_0045a737
// Address: 0045a737
// XREFS: None
RGE_Missile_Object * __thiscall
FUN_0045a737(RGE_Missile_Object *param_1,RGE_Master_Combat_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055db68;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Combat_Object::RGE_Combat_Object
            ((RGE_Combat_Object *)param_1,param_2,param_3,param_4,param_5,param_6,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Missile_Object::_vftable_;
  if (param_7 != 0) {
    RGE_Missile_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x3c;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045a7c7
// Address: 0045a7c7
// XREFS: None
RGE_Missile_Object * __thiscall FUN_0045a7c7(RGE_Missile_Object *param_1,byte param_2)
{
  RGE_Missile_Object::~RGE_Missile_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045a7f5
// Address: 0045a7f5
// XREFS: None
RGE_Missile_Object * __thiscall
FUN_0045a7f5(RGE_Missile_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055db88;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Combat_Object::RGE_Combat_Object((RGE_Combat_Object *)param_1,param_2,param_3,0);
  uStack_4 = 0;
  param_1->_padding_ = (int)&RGE_Missile_Object::_vftable_;
  if (param_4 != 0) {
    RGE_Missile_Object::setup(param_1,param_2,param_3);
  }
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x3c;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045a869
// Address: 0045a869
// XREFS: None
undefined4 __thiscall
FUN_0045a869(RGE_Combat_Object *param_1,RGE_Master_Combat_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  RGE_Combat_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x3c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045a905
// Address: 0045a905
// XREFS: None
void __thiscall FUN_0045a905(RGE_Combat_Object *param_1,int param_2)
{
  RGE_Combat_Object::save(param_1,param_2);
  rge_write(param_2,param_1 + 1,4);
  return;
}

// --------------------------------------------------

// Function: FUN_0045a935
// Address: 0045a935
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uchar __fastcall FUN_0045a935(RGE_Action_Object *param_1)
{
  ulong *puVar1;
  ulong *puVar2;
  bool bVar3;
  float fVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  
  if ((_DAT_0056f4a8 < (float)param_1[1]._padding_) &&
     (fVar4 = (float)param_1[1]._padding_ - *(float *)(*(int *)(param_1->_padding_ + 0x3c) + 0x84),
     bVar3 = fVar4 < _DAT_0056f4a8, param_1[1]._padding_ = (int)fVar4, bVar3)) {
    param_1[1]._padding_ = 0;
  }
  uVar5 = RGE_Action_Object::update(param_1);
  iVar8 = param_1->_padding_;
  if ((-1 < iVar8) && (param_1->_padding_ == 0)) {
    iVar6 = __ftol();
    iVar7 = __ftol();
    puVar1 = (ulong *)param_1[1]._padding_;
    puVar2 = (&unified_map_offsets)[iVar7][iVar6];
    param_1[1]._padding_ = (int)puVar2;
    if (puVar2 != puVar1) {
      Visible_Unit_Manager::Update_Unit_Info
                (VisibleUnitManager,iVar8,(int)*(short *)(param_1->_padding_ + 0x4a),iVar6,iVar7,
                 (int)*(short *)(param_1->_padding_ + 0x14),(ulong)puVar1,(ulong)puVar2,
                 (VISIBLE_UNIT_REC **)(param_1 + 1));
      if ((char)param_1[1]._padding_ != '\0') {
        iVar6 = 1;
        iVar8 = *(int *)(param_1->_padding_ + 0x3c);
        iVar7 = (int)*(short *)(iVar8 + 0x3c);
        if (1 < iVar7) {
          do {
            if ((iVar6 != *(short *)(param_1->_padding_ + 0x4a)) &&
               (((uint)puVar2 & 1 << ((byte)iVar6 & 0x1f)) != 0)) goto LAB_00430784;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar7);
        }
        iVar6 = -1;
LAB_00430784:
        if (-1 < iVar6) {
          iVar8 = RGE_Player::computerPlayer(*(RGE_Player **)(*(int *)(iVar8 + 0x40) + iVar6 * 4));
          if (iVar8 == 0) {
            (**(code **)(param_1->_padding_ + 0x44))
                      (*(undefined4 *)
                        (*(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0x40) + iVar6 * 4));
            if ((char)param_1[1]._padding_ == '\x01') {
              *(undefined1 *)&param_1[1]._padding_ = 0;
            }
          }
        }
      }
    }
  }
  if (param_1->_padding_ != 0) {
    iVar8 = RGE_Game_World::is_player_turn
                      (*(RGE_Game_World **)(param_1->_padding_ + 0x3c),
                       (int)*(short *)(param_1->_padding_ + 0x4a));
    if (iVar8 != 0) {
      uVar9 = RGE_Game_World::get_accum_time_delta
                        (*(RGE_Game_World **)(param_1->_padding_ + 0x3c),
                         (int)*(short *)(param_1->_padding_ + 0x4a));
      UnitAIModule::update((UnitAIModule *)param_1->_padding_,uVar9);
    }
  }
  return uVar5;
}

// --------------------------------------------------

// Function: FUN_0045a945
// Address: 0045a945
// XREFS: None
void __thiscall
FUN_0045a945(RGE_Action_Object *param_1,RGE_Static_Object *param_2,RGE_Static_Object *param_3,
            int param_4)
{
  RGE_Action_Missile *this;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Action_Missile *)operator_new(0x54);
  uStack_4 = 0;
  if (this == (RGE_Action_Missile *)0x0) {
    pRVar1 = (RGE_Action *)0x0;
  }
  else {
    pRVar1 = (RGE_Action *)
             RGE_Action_Missile::RGE_Action_Missile
                       (this,param_1,param_2,param_3,param_3->world_x,param_3->world_y,
                        param_3->world_z);
  }
  uStack_4 = 0xffffffff;
  if (pRVar1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action(param_1->actions,pRVar1);
  }
  param_1[1]._padding_ = param_4;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0045a9d9
// Address: 0045a9d9
// XREFS: None
void __thiscall
FUN_0045a9d9(RGE_Action_Object *param_1,RGE_Static_Object *param_2,float param_3,float param_4,
            float param_5,int param_6)
{
  RGE_Action_Missile *this;
  RGE_Action *pRVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbcb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  this = (RGE_Action_Missile *)operator_new(0x54);
  uStack_4 = 0;
  if (this == (RGE_Action_Missile *)0x0) {
    pRVar1 = (RGE_Action *)0x0;
  }
  else {
    pRVar1 = (RGE_Action *)
             RGE_Action_Missile::RGE_Action_Missile
                       (this,param_1,param_2,(RGE_Static_Object *)0x0,param_3,param_4,param_5);
  }
  uStack_4 = 0xffffffff;
  if (pRVar1 != (RGE_Action *)0x0) {
    RGE_Action_List::add_action(param_1->actions,pRVar1);
  }
  param_1[1]._padding_ = param_6;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0045aa69
// Address: 0045aa69
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0045aa69(int *param_1)
{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  
  fVar5 = (float)param_1[0xe] + (float)param_1[0x24];
  fVar1 = (float)param_1[0x26];
  fVar4 = (float)param_1[0xf] + (float)param_1[0x25];
  fVar2 = (float)param_1[0x10];
  if ((((fVar5 < _DAT_00570934) ||
       (iVar3 = *(int *)(*(int *)(param_1[3] + 0x3c) + 0x28), (float)*(int *)(iVar3 + 8) <= fVar5))
      || (fVar4 < _DAT_00570934)) || ((float)*(int *)(iVar3 + 0xc) <= fVar4)) {
    (**(code **)(*param_1 + 0x6c))();
  }
  fVar6 = (float10)(**(code **)(*param_1 + 0x34))(fVar5,fVar4,fVar1 + fVar2);
  if (fVar6 == (float10)(float)param_1[0x10]) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0045ab1c
// Address: 0045ab1c
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

RGE_Check_List * __thiscall FUN_0045ab1c(RGE_Static_Object *param_1,float param_2)
{
  float fVar1;
  float fVar2;
  RGE_Map *pRVar3;
  undefined4 *puVar4;
  RGE_Static_Object *pRVar5;
  RGE_Master_Static_Object *pRVar6;
  float fVar7;
  float fVar8;
  short sVar9;
  short sVar10;
  RGE_Check_List *this;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *unaff_FS_OFFSET;
  RGE_Check_List *pRStack_48;
  short sStack_44;
  short sStack_40;
  int iStack_3c;
  int iStack_24;
  RGE_Check_List *pRStack_20;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dbeb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  fVar1 = param_1->master_obj->radius_x;
  fVar2 = param_1->master_obj->radius_y;
  if ((fVar1 <= _DAT_00570934) || (fVar2 <= _DAT_00570934)) {
    pRStack_48 = (RGE_Check_List *)0x0;
  }
  else {
    sStack_40 = __ftol();
    sVar9 = __ftol();
    sStack_44 = __ftol();
    sVar10 = __ftol();
    pRVar3 = param_1->owner->world->map;
    this = (RGE_Check_List *)operator_new(4);
    uStack_4 = 0;
    if (this == (RGE_Check_List *)0x0) {
      pRStack_48 = (RGE_Check_List *)0x0;
    }
    else {
      pRStack_48 = (RGE_Check_List *)RGE_Check_List::RGE_Check_List(this);
    }
    uStack_4 = 0xffffffff;
    if (sStack_40 < 0) {
      sStack_40 = 0;
    }
    if (pRVar3->map_width <= (int)sStack_44) {
      sStack_44 = (short)pRVar3->map_width + -1;
    }
    if (sVar9 < 0) {
      sVar9 = 0;
    }
    if (pRVar3->map_height <= (int)sVar10) {
      sVar10 = (short)pRVar3->map_height + -1;
    }
    if (sVar9 <= sVar10) {
      iStack_3c = sVar9 * 4;
      iStack_24 = ((int)sVar10 - (int)sVar9) + 1;
      do {
        if (sStack_40 <= sStack_44) {
          puVar12 = (undefined4 *)
                    (*(int *)(iStack_3c + (int)pRVar3->map_row_offset) + sStack_40 * 0x18 + 0x10);
          iVar11 = ((int)sStack_44 - (int)sStack_40) + 1;
          do {
            for (puVar4 = (undefined4 *)*puVar12; puVar4 != (undefined4 *)0x0;
                puVar4 = (undefined4 *)puVar4[1]) {
              pRVar5 = (RGE_Static_Object *)*puVar4;
              if (pRVar5 != param_1) {
                pRVar6 = pRVar5->master_obj;
                if ((((_DAT_00570934 < pRVar6->radius_y) && (_DAT_00570934 < pRVar6->radius_x)) &&
                    (fVar7 = pRVar5->world_z - param_1->world_z,
                    -(pRVar6->radius_z - _DAT_00570940) <= fVar7)) &&
                   (fVar7 <= param_1->master_obj->radius_z - _DAT_00570940)) {
                  fVar7 = pRVar5->world_x - param_1->world_x;
                  fVar8 = pRVar5->world_y - param_1->world_y;
                  if (fVar7 < _DAT_00570934) {
                    fVar7 = -fVar7;
                  }
                  if (fVar8 < _DAT_00570934) {
                    fVar8 = -fVar8;
                  }
                  fVar7 = fVar7 - (pRVar6->radius_x + fVar1 + param_2);
                  fVar8 = fVar8 - (pRVar6->radius_y + fVar2 + param_2);
                  if ((fVar7 <= _DAT_00570934) && (fVar8 <= _DAT_00570934)) {
                    RGE_Check_List::add_node(pRStack_48,pRVar5,fVar7,fVar8,'\0');
                  }
                }
              }
            }
            puVar12 = puVar12 + 6;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        iStack_3c = iStack_3c + 4;
        iStack_24 = iStack_24 + -1;
      } while (iStack_24 != 0);
    }
    if (pRStack_48->list == (RGE_Check_Node *)0x0) {
      if (pRStack_48 != (RGE_Check_List *)0x0) {
        RGE_Check_List::~RGE_Check_List(pRStack_48);
        operator_delete(pRStack_48);
      }
      pRStack_20 = (RGE_Check_List *)0x0;
      pRStack_48 = pRStack_20;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return pRStack_48;
}

// --------------------------------------------------

// Function: FUN_0045ae42
// Address: 0045ae42
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Mouseptr_c: "C:\msdev\work\age1_x1\Mouseptr.cpp"
undefined4 * __thiscall FUN_0045ae42(undefined4 *param_1,undefined4 param_2)
{
  ulong uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_1 + 0x2f;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  *puVar3 = 0;
  param_1[0x32] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[0x33] = *puVar3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x34] = param_1[0x30];
  param_1[0x16] = 0;
  param_1[0x18] = 0;
  param_1[0x35] = param_1[0x31];
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x36] = param_1[0x32];
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x37] = *puVar3;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x38] = param_1[0x30];
  param_1[0x1f] = 0;
  param_1[0x22] = 0;
  param_1[0x39] = param_1[0x31];
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x3a] = param_1[0x32];
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x3b] = *puVar3;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x3c] = param_1[0x30];
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x3d] = param_1[0x31];
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x3e] = param_1[0x32];
  param_1[0x2d] = 0;
  param_1[0x3f] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x40] = param_1[0x30];
  param_1[0x4c] = 0;
  param_1[0x41] = param_1[0x31];
  param_1[0x4d] = 0;
  param_1[0x42] = param_1[0x32];
  param_1[0x20] = 0xffff8001;
  param_1[0x21] = 0xffff8001;
  param_1[0x17] = param_2;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0x94] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x53) = 0;
  puVar3 = param_1 + 6;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_Mouseptr_c,100);
  param_1[0x51] = uVar1 - 0x24;
  param_1[0x2e] = 0;
  param_1[0x52] = 0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045aff1
// Address: 0045aff1
// XREFS: None
void __fastcall FUN_0045aff1(TMousePointer *param_1)
{
  TShape *this;
  
  this = param_1->Cursor_Shape;
  if (this != (TShape *)0x0) {
    TShape::~TShape(this);
    operator_delete(this);
    param_1->Cursor_Shape = (TShape *)0x0;
  }
  TMousePointer::delete_surfaces(param_1);
  MouseSystem = (TMousePointer *)0x0;
  return;
}

// --------------------------------------------------

// Function: FUN_0045b036
// Address: 0045b036
// XREFS: None
undefined4 __fastcall FUN_0045b036(TMousePointer *param_1)
{
  if (param_1->Shutdown != 0) {
    return 0;
  }
  if (param_1->custom_draw == 0) {
    return 1;
  }
  if (param_1->Setup == 0) {
    return 0;
  }
  TMousePointer::reset(param_1);
  param_1->render_area = (TDrawArea *)0x0;
  param_1->restoreSurface = (IDirectDrawSurface *)0x0;
  param_1->renderSurface = (IDirectDrawSurface *)0x0;
  param_1->PrimarySurface = (IDirectDrawSurface *)0x0;
  param_1->primary_area = (TDrawArea *)0x0;
  param_1->active = 0;
  param_1->Shutdown = 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045b09f
// Address: 0045b09f
// XREFS: None
undefined4 __thiscall FUN_0045b09f(TMousePointer *param_1,TDrawArea *param_2)
{
  int iVar1;
  
  if (param_1->Shutdown == 0) {
    return 0;
  }
  if (param_1->custom_draw != 0) {
    if (param_1->Setup == 0) {
      return 0;
    }
    param_1->render_area = param_2;
    param_1->renderSurface = param_2->DrawSurface;
    param_1->PrimarySurface = param_2->DrawSystem->PrimarySurface;
    param_1->primary_area = param_2->DrawSystem->PrimaryArea;
    iVar1 = TMousePointer::LoadCursors(param_1,(char *)0x0,-1,1);
    if (iVar1 == 0) {
      return 0;
    }
    param_1->Shutdown = 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045b113
// Address: 0045b113
// XREFS: None
// [HELPER] s__s_slp: "%s.slp"
undefined4 __thiscall
FUN_0045b113(TMousePointer *param_1,int param_2,TDrawArea *param_3,char *param_4,long param_5,
            int param_6)
{
  undefined4 uVar1;
  TShape *pTVar2;
  int iVar3;
  long lVar4;
  undefined4 *unaff_FS_OFFSET;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dc0e;
  *unaff_FS_OFFSET = &uStack_c;
  MouseSystem = param_1;
  param_1->custom_draw = param_2;
  param_1->render_area = param_3;
  if (param_2 == 0) {
    uVar1 = 1;
  }
  else {
    if (param_3->DrawSystem->DrawType != '\x01') {
      param_1->renderSurface = param_3->DrawSurface;
      param_1->PrimarySurface = param_3->DrawSystem->PrimarySurface;
      param_1->primary_area = param_3->DrawSystem->PrimaryArea;
      SetCursor(0);
      sprintf(acStack_110,s__s_slp,param_4);
      pTVar2 = (TShape *)operator_new(0x20);
      uStack_4 = 0;
      if (pTVar2 == (TShape *)0x0) {
        pTVar2 = (TShape *)0x0;
      }
      else {
        pTVar2 = (TShape *)TShape::TShape(pTVar2,acStack_110,param_5);
      }
      uStack_4 = 0xffffffff;
      param_1->Cursor_Shape = pTVar2;
      if (pTVar2 != (TShape *)0x0) {
        iVar3 = TShape::is_loaded(pTVar2);
        if ((iVar3 != 0) && (param_1->Cursor_Shape->FShape != (SLhape_File_Header *)0x0)) {
          param_1->Max_Cursors = param_6;
          if ((0 < param_6) && (param_6 < 0x11)) {
            lVar4 = TShape::shape_count(param_1->Cursor_Shape);
            param_1->Num_Cursors = lVar4;
            if (lVar4 <= param_1->Max_Cursors) {
              iVar3 = TMousePointer::LoadCursors(param_1,param_4,param_5,0);
              if (iVar3 != 0) {
                TMousePointer::set_facet(param_1,0);
                TMousePointer::set_game_facet(param_1,0);
                param_1->Setup = 1;
                uVar1 = 1;
                goto LAB_0045b267;
              }
            }
          }
        }
      }
    }
    uVar1 = 0;
  }
LAB_0045b267:
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0045b281
// Address: 0045b281
// XREFS: None
void __thiscall FUN_0045b281(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x138) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0045b29d
// Address: 0045b29d
// XREFS: None
void __thiscall FUN_0045b29d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0045b2ad
// Address: 0045b2ad
// XREFS: None
undefined4 __fastcall FUN_0045b2ad(int param_1)
{
  return *(undefined4 *)(param_1 + 0x13c);
}

// --------------------------------------------------

// Function: FUN_0045b2b7
// Address: 0045b2b7
// XREFS: None
undefined4 __fastcall FUN_0045b2b7(int param_1)
{
  if ((*(int *)(param_1 + 0x138) != 0) && (*(int *)(param_1 + 0x13c) != 0)) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0045b2dd
// Address: 0045b2dd
// XREFS: None
void __thiscall
FUN_0045b2dd(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  *(undefined4 *)(param_1 + 0x10c) = param_2;
  *(undefined4 *)(param_1 + 0x110) = param_3;
  *(undefined4 *)(param_1 + 0x114) = param_4;
  *(undefined4 *)(param_1 + 0x118) = param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_0045b30b
// Address: 0045b30b
// XREFS: None
// [HELPER] s__s_slp: "%s.slp"
// [HELPER] s_mouseptr__LoadCursors: "mouseptr::LoadCursors"
undefined4 __thiscall
FUN_0045b30b(TMousePointer *param_1,undefined4 param_2,int param_3,int param_4)
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
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dc2b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pTVar2 = param_1->Cursor_Shape;
  uStack_10 = 1;
  if (pTVar2 != (TShape *)0x0) {
    TShape::~TShape(pTVar2);
    operator_delete(pTVar2);
  }
  if (param_4 == 0) {
    param_1->cursor_file_id = param_3;
    sprintf(param_1->cursor_file,s__s_slp,param_2);
  }
  pTVar2 = (TShape *)operator_new(0x20);
  uStack_4 = 0;
  if (pTVar2 == (TShape *)0x0) {
    pTVar2 = (TShape *)0x0;
  }
  else {
    pTVar2 = (TShape *)TShape::TShape(pTVar2,param_1->cursor_file,param_1->cursor_file_id);
  }
  uStack_4 = 0xffffffff;
  param_1->Cursor_Shape = pTVar2;
  if (((pTVar2 != (TShape *)0x0) && (iVar3 = TShape::is_loaded(pTVar2), iVar3 != 0)) &&
     (param_1->Cursor_Shape->FShape != (SLhape_File_Header *)0x0)) {
    lVar4 = TShape::shape_count(param_1->Cursor_Shape);
    param_1->Num_Cursors = lVar4;
    param_1->Max_CX = 0;
    param_1->Max_CY = 0;
    if (0 < lVar4) {
      iVar3 = 0;
      do {
        pSVar1 = param_1->Cursor_Shape->shape_info;
        iVar7 = *(int *)((int)&pSVar1->Width + iVar3);
        if (param_1->Max_CX < iVar7) {
          param_1->Max_CX = iVar7;
        }
        iVar7 = *(int *)((int)&pSVar1->Height + iVar3);
        if (param_1->Max_CY < iVar7) {
          param_1->Max_CY = iVar7;
        }
        iVar3 = iVar3 + 0x20;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    if ((param_1->Max_CX != 0) && (param_1->Max_CY != 0)) {
      param_1->Max_CX = 0x40;
      param_1->Max_CY = 0x30;
      if ((param_1->save_area != (TDrawArea *)0x0) ||
         (iVar3 = TMousePointer::create_surfaces(param_1), iVar3 != 0)) {
        TMousePointer::set_facet(param_1,param_1->facet);
        TMousePointer::set_game_facet(param_1,param_1->game_facet);
        if (param_1->Mouse_Mode != 0) goto LAB_0045b546;
        iVar3 = param_1->Num_Cursors;
        if (iVar3 <= param_1->Max_Cursors) {
          iVar7 = 0;
          if (0 < iVar3) {
            plVar5 = &param_1->Cursor_Shape->shape_info->Height;
            do {
              if ((param_1->Max_CX < plVar5[-1]) || (param_1->Max_CY < *plVar5)) goto LAB_0045b544;
              iVar7 = iVar7 + 1;
              plVar5 = plVar5 + 8;
            } while (iVar7 < iVar3);
          }
          iVar3 = 0;
          if (0 < param_1->Max_Cursors) {
            iVar7 = 0;
            ppTVar8 = param_1->cursors;
            do {
              TDrawArea::Clear(*ppTVar8,(tagRECT *)0x0,0);
              TDrawArea::SetTrans(*ppTVar8,1,'\0');
              if (iVar3 < param_1->Num_Cursors) {
                puVar6 = TDrawArea::Lock(*ppTVar8,s_mouseptr__LoadCursors,1);
                if (puVar6 == (uchar *)0x0) {
                  uStack_10 = 0;
                }
                else {
                  TDrawArea::FillRect(*ppTVar8,0,0,param_1->Max_CX,param_1->Max_CY,'\0');
                  pSVar1 = param_1->Cursor_Shape->shape_info;
                  TShape::shape_draw(param_1->Cursor_Shape,*ppTVar8,
                                     *(long *)((int)&pSVar1->Hotspot_X + iVar7),
                                     *(long *)((int)&pSVar1->Hotspot_Y + iVar7),iVar3,'\0',
                                     (uchar *)0x0);
                  TDrawArea::Unlock(*ppTVar8,s_mouseptr__LoadCursors);
                }
              }
              iVar3 = iVar3 + 1;
              ppTVar8 = ppTVar8 + 1;
              iVar7 = iVar7 + 0x20;
            } while (iVar3 < param_1->Max_Cursors);
          }
          goto LAB_0045b546;
        }
      }
    }
  }
LAB_0045b544:
  uStack_10 = 0;
LAB_0045b546:
  *unaff_FS_OFFSET = uStack_c;
  return uStack_10;
}

// --------------------------------------------------

// Function: FUN_0045b55b
// Address: 0045b55b
// XREFS: None
void __fastcall FUN_0045b55b(TMousePointer *param_1)
{
  TDrawArea *pTVar1;
  int iVar2;
  TDrawArea **ppTVar3;
  
  iVar2 = 0;
  if (param_1->custom_draw != 0) {
    pTVar1 = param_1->save_area;
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::~TDrawArea(pTVar1);
      operator_delete(pTVar1);
      param_1->save_area = (TDrawArea *)0x0;
    }
    if (0 < param_1->Max_Cursors) {
      ppTVar3 = param_1->cursors;
      do {
        pTVar1 = *ppTVar3;
        if (pTVar1 != (TDrawArea *)0x0) {
          TDrawArea::~TDrawArea(pTVar1);
          operator_delete(pTVar1);
          *ppTVar3 = (TDrawArea *)0x0;
        }
        iVar2 = iVar2 + 1;
        ppTVar3 = ppTVar3 + 1;
      } while (iVar2 < param_1->Max_Cursors);
    }
    param_1->Num_Cursors = 0;
    TMousePointer::reset(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045b5c9
// Address: 0045b5c9
// XREFS: None
// [HELPER] s_Mouse_Cursor___d: "Mouse Cursor #%d"
// [HELPER] s_Mouse_Save_area: "Mouse Save area"
undefined4 __fastcall FUN_0045b5c9(int *param_1)
{
  TDrawArea *pTVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  char acStack_2c [32];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dc56;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = 0;
  if (*param_1 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 1;
  }
  if (((param_1[2] == 0) && (0 < param_1[0x18])) && (0 < param_1[0x19])) {
    pTVar1 = (TDrawArea *)operator_new(0x100);
    uStack_4 = 0;
    if (pTVar1 == (TDrawArea *)0x0) {
      pTVar1 = (TDrawArea *)0x0;
    }
    else {
      pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,s_Mouse_Save_area,0);
    }
    uStack_4 = 0xffffffff;
    param_1[2] = (int)pTVar1;
    if (pTVar1 == (TDrawArea *)0x0) {
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    iVar2 = TDrawArea::Init(pTVar1,*(TDrawSystem **)param_1[1],param_1[0x18],param_1[0x19],0,0);
    if (iVar2 == 0) {
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
  }
  if ((param_1[0x17] == 0) && (0 < param_1[5])) {
    piVar3 = param_1 + 6;
    do {
      if (*piVar3 == 0) {
        sprintf(acStack_2c,s_Mouse_Cursor___d,iVar4);
        pTVar1 = (TDrawArea *)operator_new(0x100);
        uStack_4 = 1;
        if (pTVar1 == (TDrawArea *)0x0) {
          pTVar1 = (TDrawArea *)0x0;
        }
        else {
          pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,acStack_2c,0);
        }
        uStack_4 = 0xffffffff;
        *piVar3 = (int)pTVar1;
        if (pTVar1 == (TDrawArea *)0x0) {
LAB_0045b745:
          *unaff_FS_OFFSET = uStack_c;
          return 0;
        }
        iVar2 = TDrawArea::Init(pTVar1,*(TDrawSystem **)param_1[1],param_1[0x18],param_1[0x19],0,0);
        if (iVar2 == 0) goto LAB_0045b745;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < param_1[5]);
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045b75a
// Address: 0045b75a
// XREFS: None
undefined4 __fastcall FUN_0045b75a(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iStack_8;
  int iStack_4;
  
  if (*param_1 == 0) {
    return 0;
  }
  GetCursorPos(&iStack_8);
  if (*(char *)(*(int *)param_1[1] + 0x479) == '\x01') {
    ScreenToClient(((int *)param_1[1])[1],&iStack_8);
    if (0x8000 < iStack_8) {
      iStack_8 = iStack_8 + -0x10000;
    }
    if (0x8000 < iStack_4) {
      iStack_4 = iStack_4 + -0x10000;
    }
  }
  param_1[0x1e] = iStack_8;
  param_1[0x1f] = iStack_4;
  if (((((param_1[0x4e] == 0) || (param_1[0x4f] == 0)) || (param_1[0x1e] < param_1[0x43])) ||
      ((param_1[0x45] <= param_1[0x1e] || (iStack_4 < param_1[0x44])))) ||
     (param_1[0x46] <= iStack_4)) {
    param_1[0x24] = param_1[0x22];
    bVar4 = false;
  }
  else {
    param_1[0x24] = param_1[0x23];
    bVar4 = true;
  }
  if (((param_1[0x2e] != 0) && (iStack_8 == param_1[0x20])) &&
     ((iStack_4 == param_1[0x21] && (param_1[0x24] == param_1[0x25])))) {
    return 0;
  }
  param_1[0x20] = iStack_8;
  param_1[0x21] = iStack_4;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  if (bVar4) {
    param_1[0x3e] = param_1[0x1d];
    param_1[0x3d] = param_1[0x1c];
    param_1[0x33] = param_1[0x1e] - param_1[0x2b];
    iVar5 = param_1[0x1f];
    param_1[0x34] = iVar5 - param_1[0x2a];
    iVar6 = param_1[0x2c];
    param_1[0x35] = param_1[0x2d] + param_1[0x1e];
  }
  else {
    param_1[0x3d] = param_1[0x1a];
    param_1[0x3e] = param_1[0x1b];
    param_1[0x33] = param_1[0x1e] - param_1[0x27];
    iVar5 = param_1[0x1f];
    param_1[0x34] = iVar5 - param_1[0x26];
    iVar6 = param_1[0x28];
    param_1[0x35] = param_1[0x29] + param_1[0x1e];
  }
  param_1[0x36] = iVar6 + iVar5;
  param_1[0x37] = param_1[0x3b];
  param_1[0x38] = param_1[0x3c];
  param_1[0x39] = param_1[0x3d];
  param_1[0x3a] = param_1[0x3e];
  iVar5 = param_1[0x35];
  if ((-1 < iVar5) && (iVar6 = param_1[0x36], -1 < iVar6)) {
    iVar1 = param_1[1];
    iVar2 = param_1[0x33];
    if ((iVar2 <= *(int *)(iVar1 + 0x18)) &&
       (iVar3 = param_1[0x34], iVar3 <= *(int *)(iVar1 + 0x1c))) {
      if (iVar2 < 0) {
        param_1[0x37] = -iVar2;
        param_1[0x33] = 0;
        param_1[0x3d] = param_1[0x3d] + iVar2;
      }
      if (*(int *)(iVar1 + 0x18) < iVar5) {
        iVar5 = iVar5 - *(int *)(iVar1 + 0x18);
        param_1[0x39] = param_1[0x39] - iVar5;
        param_1[0x3d] = param_1[0x3d] - iVar5;
        param_1[0x35] = *(int *)(iVar1 + 0x18);
      }
      if (iVar3 < 0) {
        param_1[0x34] = 0;
        param_1[0x38] = -iVar3;
        param_1[0x3e] = param_1[0x3e] + iVar3;
      }
      if (*(int *)(iVar1 + 0x1c) < iVar6) {
        iVar6 = iVar6 - *(int *)(iVar1 + 0x1c);
        param_1[0x3a] = param_1[0x3a] - iVar6;
        param_1[0x3e] = param_1[0x3e] - iVar6;
        param_1[0x36] = *(int *)(iVar1 + 0x1c);
      }
      param_1[0x50] = 1;
      return 1;
    }
  }
  param_1[0x50] = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045ba53
// Address: 0045ba53
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Mouseptr_c: "C:\msdev\work\age1_x1\Mouseptr.cpp"
// [HELPER] s_mouseptr__draw: "mouseptr::draw"
void __thiscall FUN_0045ba53(TMousePointer *param_1,int param_2)
{
  tagRECT *ptVar1;
  IDirectDrawSurface *pIVar2;
  long lVar3;
  Shape_Info *pSVar4;
  ulong uVar5;
  int iVar6;
  uchar *puVar7;
  int iStack_4;
  
  iStack_4 = 0;
  if ((param_1->active != 0) && (param_1->custom_draw != 0)) {
    uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_Mouseptr_c,0x2e3);
    if ((param_1->GameMode == 0) ||
       (((param_1->GameEnabled == 0 || (param_2 != 0)) || (0x21 < uVar5 - param_1->LastDrawTime))))
{
      iVar6 = TMousePointer::update_mouse_position(param_1);
      if ((iVar6 != 0) || (param_2 != 0)) {
        param_1->LastDrawTime = uVar5;
        if ((param_1->save_area_valid != 0) &&
           (pIVar2 = param_1->restoreSurface, pIVar2 != param_1->PrimarySurface)) {
          iVar6 = (**(code **)((int)*pIVar2 + 0x14))
                            (pIVar2,&param_1->restore_rect,param_1->save_area->DrawSurface,
                             &param_1->save_rect,0x1000000,0);
          if (iVar6 != 0) {
            param_1->LastddError = iVar6;
            return;
          }
        }
        if (param_1->MouseOnScreen == 0) {
          param_1->save_area_valid = 0;
        }
        else {
          ptVar1 = &param_1->mouse_rect;
          pIVar2 = param_1->save_area->DrawSurface;
          iVar6 = (**(code **)((int)*pIVar2 + 0x14))
                            (pIVar2,&param_1->new_save_rect,param_1->renderSurface,ptVar1,0x1000000,
                             0);
          if (iVar6 != 0) {
            param_1->LastddError = iVar6;
            return;
          }
          pIVar2 = param_1->renderSurface;
          lVar3 = ptVar1->left;
          param_1->restoreSurface = pIVar2;
          (param_1->restore_rect).left = lVar3;
          (param_1->restore_rect).top = (param_1->mouse_rect).top;
          (param_1->restore_rect).right = (param_1->mouse_rect).right;
          (param_1->restore_rect).bottom = (param_1->mouse_rect).bottom;
          (param_1->save_rect).left = (param_1->new_save_rect).left;
          (param_1->save_rect).top = (param_1->new_save_rect).top;
          (param_1->save_rect).right = (param_1->new_save_rect).right;
          (param_1->save_rect).bottom = (param_1->new_save_rect).bottom;
          param_1->save_area_valid = 1;
          if (param_1->Mouse_Mode == 0) {
            iVar6 = (**(code **)((int)*pIVar2 + 0x3c))(pIVar2,&iStack_4);
            if (iVar6 == -0x7789fdc8) {
              iVar6 = 0;
              iStack_4 = 0;
            }
            if (iVar6 != 0) {
              param_1->LastddError = iVar6;
              return;
            }
            if (iStack_4 != 0) {
              iVar6 = (**(code **)((int)*param_1->renderSurface + 0x70))(param_1->renderSurface,0);
              if (iVar6 != 0) {
                param_1->LastddError = iVar6;
                return;
              }
            }
          }
          if (param_1->Mouse_Mode == 1) {
            puVar7 = TDrawArea::Lock(param_1->render_area,s_mouseptr__draw,1);
            if (puVar7 != (uchar *)0x0) {
              lVar3 = param_1->next_facet;
              pSVar4 = param_1->Cursor_Shape->shape_info;
              TShape::shape_draw(param_1->Cursor_Shape,param_1->render_area,
                                 pSVar4[lVar3].Hotspot_X + ptVar1->left,
                                 pSVar4[lVar3].Hotspot_Y + (param_1->mouse_rect).top,lVar3,'\0',
                                 (uchar *)0x0);
              TDrawArea::Unlock(param_1->render_area,s_mouseptr__draw);
            }
          }
          if (param_1->Mouse_Mode == 0) {
            TDrawArea::SetTrans(param_1->cursors[param_1->next_facet],1,'\0');
            iVar6 = (**(code **)((int)*param_1->renderSurface + 0x1c))
                              (param_1->renderSurface,ptVar1->left,(param_1->mouse_rect).top,
                               param_1->cursors[param_1->next_facet]->DrawSurface,
                               &param_1->cursor_rect,0x11);
            if (iVar6 != 0) {
              param_1->LastddError = iVar6;
              return;
            }
          }
          param_1->last_facet = param_1->next_facet;
          if ((param_1->Mouse_Mode == 0) && (iStack_4 != 0)) {
            iVar6 = (**(code **)((int)*param_1->renderSurface + 0x70))
                              (param_1->renderSurface,iStack_4);
            if (iVar6 != 0) {
              param_1->LastddError = iVar6;
              return;
            }
          }
        }
        if ((param_1->GameMode == 0) || (param_1->GameEnabled == 0)) {
          InvalidateRect(param_1->render_area->Wnd,&param_1->mouse_rect,0);
        }
        param_1->drawn = 1;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045bd58
// Address: 0045bd58
// XREFS: None
void __fastcall FUN_0045bd58(int *param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((((param_1[0x4a] != 0) && (*param_1 != 0)) && (param_1[0x4b] != 0)) &&
     ((param_1[0x2e] != 0 && (piVar1 = (int *)param_1[0x47], piVar1 != (int *)param_1[0x49])))) {
    iVar2 = (**(code **)(*piVar1 + 0x14))
                      (piVar1,param_1 + 0x3f,*(undefined4 *)(param_1[2] + 0x3c),param_1 + 0x2f,
                       0x1000000,0);
    if (iVar2 != 0) {
      param_1[0x52] = iVar2;
      return;
    }
    if ((param_1[0x4e] != 0) && (param_1[0x4f] != 0)) {
      param_1[0x2e] = 1;
      param_1[0x47] = param_1[0x49];
      return;
    }
    InvalidateRect(*(undefined4 *)(param_1[1] + 4),param_1 + 0x3f,0);
    param_1[0x2e] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045be7b
// Address: 0045be7b
// XREFS: None
void __thiscall FUN_0045be7b(int param_1,int param_2)
{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x10))) {
    *(int *)(param_1 + 0x8c) = param_2;
    iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x1c) + param_2 * 0x20;
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(iVar1 + 0x18);
    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0x70) - *(int *)(iVar1 + 0x18);
    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0x74) - *(int *)(iVar1 + 0x1c);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045bedb
// Address: 0045bedb
// XREFS: None
void __fastcall FUN_0045bedb(TMousePointer *param_1)
{
  if (param_1->Shutdown == 0) {
    if (((param_1->custom_draw != 0) && (param_1->drawn != 0)) && (param_1->save_area_valid != 0)) {
      TMousePointer::erase(param_1);
      TDrawSystem::Paint(param_1->render_area->DrawSystem,&param_1->restore_rect);
    }
    SetCursor(0);
    param_1->active = 0;
    TMousePointer::reset(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045bf37
// Address: 0045bf37
// XREFS: None
void __fastcall FUN_0045bf37(int *param_1)
{
  undefined4 uVar1;
  
  if (param_1[0x4c] == 0) {
    if (*param_1 == 0) {
      uVar1 = LoadCursorA(0,0x7f00);
      SetCursor(uVar1);
    }
    param_1[0x4a] = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045bf72
// Address: 0045bf72
// XREFS: None
void __fastcall FUN_0045bf72(int param_1)
{
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0045bf8f
// Address: 0045bf8f
// XREFS: None
void __fastcall FUN_0045bf8f(int param_1)
{
  int iVar1;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar1 = **(int **)(param_1 + 4);
  if (*(char *)(iVar1 + 0x479) == '\x01') {
    GetWindowRect(*(undefined4 *)(iVar1 + 4),&iStack_10);
    SetCursorPos((iStack_8 - iStack_10) / 2 + iStack_10,(iStack_4 - iStack_c) / 2 + iStack_c);
    return;
  }
  SetCursorPos(*(int *)(iVar1 + 0x2c) / 2,*(int *)(iVar1 + 0x30) / 2);
  return;
}

// --------------------------------------------------

// Function: FUN_0045c001
// Address: 0045c001
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_Mouseptr_c: "C:\msdev\work\age1_x1\Mouseptr.cpp"
// [HELPER] s_mouseptr__poll: "mouseptr::poll"
void __fastcall FUN_0045c001(TMousePointer *param_1)
{
  tagRECT *ptVar1;
  IDirectDrawSurface *pIVar2;
  long lVar3;
  long lVar4;
  Shape_Info *pSVar5;
  ulong uVar6;
  int iVar7;
  uchar *puVar8;
  int iStack_4;
  
  iStack_4 = 0;
  if ((((param_1->active != 0) && (param_1->custom_draw != 0)) && (param_1->GameMode != 0)) &&
     (param_1->GameEnabled != 0)) {
    uVar6 = debug_timeGetTime(s_C__msdev_work_age1_x1_Mouseptr_c,0x42e);
    if (0x21 < uVar6 - param_1->LastDrawTime) {
      iVar7 = TMousePointer::update_mouse_position(param_1);
      if (iVar7 != 0) {
        param_1->LastDrawTime = uVar6;
        if (param_1->Mouse_Mode == 0) {
          iVar7 = (**(code **)((int)*param_1->PrimarySurface + 0x3c))
                            (param_1->PrimarySurface,&iStack_4);
          if (iVar7 == -0x7789fdc8) {
            iVar7 = 0;
            iStack_4 = 0;
          }
          if (iVar7 != 0) {
            param_1->LastddError = iVar7;
            return;
          }
          if (iStack_4 != 0) {
            iVar7 = (**(code **)((int)*param_1->PrimarySurface + 0x70))(param_1->PrimarySurface,0);
            if (iVar7 != 0) {
              param_1->LastddError = iVar7;
              return;
            }
          }
        }
        if (param_1->save_area_valid != 0) {
          iVar7 = (**(code **)((int)*param_1->restoreSurface + 0x14))
                            (param_1->restoreSurface,&param_1->restore_rect,
                             param_1->save_area->DrawSurface,&param_1->save_rect,0x1000000,0);
          if (iVar7 != 0) {
            param_1->LastddError = iVar7;
            return;
          }
          pIVar2 = param_1->PrimarySurface;
          if (param_1->restoreSurface != pIVar2) {
            iVar7 = (**(code **)((int)*pIVar2 + 0x14))
                              (pIVar2,&param_1->restore_rect,param_1->save_area->DrawSurface,
                               &param_1->save_rect,0x1000000,0);
            if (iVar7 != 0) {
              param_1->LastddError = iVar7;
              return;
            }
          }
        }
        if (param_1->MouseOnScreen == 0) {
          param_1->save_area_valid = 0;
        }
        else {
          ptVar1 = &param_1->mouse_rect;
          pIVar2 = param_1->save_area->DrawSurface;
          iVar7 = (**(code **)((int)*pIVar2 + 0x14))
                            (pIVar2,&param_1->new_save_rect,param_1->PrimarySurface,ptVar1,0x1000000
                             ,0);
          if (iVar7 != 0) {
            param_1->LastddError = iVar7;
            iVar7 = TMousePointer::GetDDBltError(param_1,iVar7);
            param_1->LastddError = iVar7;
            return;
          }
          param_1->restoreSurface = param_1->PrimarySurface;
          (param_1->restore_rect).left = ptVar1->left;
          (param_1->restore_rect).top = (param_1->mouse_rect).top;
          (param_1->restore_rect).right = (param_1->mouse_rect).right;
          (param_1->restore_rect).bottom = (param_1->mouse_rect).bottom;
          lVar3 = (param_1->new_save_rect).top;
          (param_1->save_rect).left = (param_1->new_save_rect).left;
          lVar4 = (param_1->new_save_rect).right;
          (param_1->save_rect).top = lVar3;
          lVar3 = (param_1->new_save_rect).bottom;
          (param_1->save_rect).right = lVar4;
          param_1->save_area_valid = 1;
          (param_1->save_rect).bottom = lVar3;
          if (param_1->Mouse_Mode == 0) {
            TDrawArea::SetTrans(param_1->cursors[param_1->next_facet],1,'\0');
            iVar7 = (**(code **)((int)*param_1->PrimarySurface + 0x1c))
                              (param_1->PrimarySurface,ptVar1->left,(param_1->mouse_rect).top,
                               param_1->cursors[param_1->next_facet]->DrawSurface,
                               &param_1->cursor_rect,0x11);
            if (iVar7 != 0) {
              param_1->LastddError = iVar7;
              return;
            }
          }
          if (param_1->Mouse_Mode == 1) {
            puVar8 = TDrawArea::Lock(param_1->primary_area,s_mouseptr__poll,1);
            if (puVar8 != (uchar *)0x0) {
              lVar3 = param_1->next_facet;
              pSVar5 = param_1->Cursor_Shape->shape_info;
              TShape::shape_draw(param_1->Cursor_Shape,param_1->primary_area,
                                 pSVar5[lVar3].Hotspot_X + ptVar1->left,
                                 (param_1->mouse_rect).top + pSVar5[lVar3].Hotspot_Y,lVar3,'\0',
                                 (uchar *)0x0);
              TDrawArea::Unlock(param_1->primary_area,s_mouseptr__poll);
            }
          }
          param_1->last_facet = param_1->next_facet;
        }
        if ((param_1->Mouse_Mode == 0) && (iStack_4 != 0)) {
          iVar7 = (**(code **)((int)*param_1->PrimarySurface + 0x70))
                            (param_1->PrimarySurface,iStack_4);
          if (iVar7 != 0) {
            param_1->LastddError = iVar7;
            return;
          }
        }
        param_1->drawn = 1;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045c2fb
// Address: 0045c2fb
// XREFS: None
undefined4 FUN_0045c2fb(int param_1)
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
  return 0xffffffff;
}

// --------------------------------------------------

// Function: FUN_0045c445
// Address: 0045c445
// XREFS: None
RGE_Moving_Object * __thiscall
FUN_0045c445(RGE_Moving_Object *param_1,RGE_Master_Moving_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6,int param_7)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dc84;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Animated_Object::RGE_Animated_Object
            ((RGE_Animated_Object *)param_1,(RGE_Master_Animated_Object *)param_2,param_3,param_4,
             param_5,param_6,0);
  uStack_4 = 0;
  Path::Path(&param_1->pathValue,10);
  uStack_4._0_1_ = 1;
  Path::Path(&param_1->exceptionPathValue,10);
  uStack_4 = CONCAT31(uStack_4._1_3_,2);
  param_1->rangeStatusValue = 2;
  param_1->currentTerrainException1 = -1;
  param_1->currentTerrainException2 = -1;
  param_1->storePathInExceptionPath = '\0';
  param_1->waitingToMoveValue = '\0';
  param_1->numberWaitDelays = '\0';
  param_1->userDefinedWaypoints = (XYZBYTEPoint *)0x0;
  param_1->numberUserDefinedWaypointsValue = 0;
  param_1->maxUserDefinedWaypointsValue = 0;
  param_1->finalUserDefinedWaypoint = '\0';
  param_1->_padding_ = (int)&RGE_Moving_Object::_vftable_;
  (param_1->startValue).x = 0.0;
  (param_1->startValue).y = 0.0;
  (param_1->startValue).z = 0.0;
  RGE_Moving_Object::setGoal(param_1,0.0,0.0,0.0);
  param_1->turnTimer = 0.0;
  param_1->lastFacet = 0xff;
  param_1->lastFacet2 = 0xff;
  param_1->collisionAvoidanceDistance = 0.0;
  param_1->actionRange = 0.0;
  param_1->targetIDValue = -1;
  param_1->targetRadiusX = 0.0;
  param_1->targetRadiusY = 0.0;
  param_1->continueCounter = 0;
  param_1->closestDistanceToWaypoint = 100000.0;
  if (param_7 != 0) {
    RGE_Moving_Object::setup(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045c59d
// Address: 0045c59d
// XREFS: None
RGE_Moving_Object * __thiscall FUN_0045c59d(RGE_Moving_Object *param_1,byte param_2)
{
  RGE_Moving_Object::~RGE_Moving_Object(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045c5be
// Address: 0045c5be
// XREFS: None
RGE_Moving_Object * __thiscall
FUN_0045c5be(RGE_Moving_Object *param_1,int param_2,RGE_Game_World *param_3,int param_4)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dcb4;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  RGE_Animated_Object::RGE_Animated_Object((RGE_Animated_Object *)param_1,param_2,param_3,0);
  uStack_4 = 0;
  Path::Path(&param_1->pathValue,10);
  uStack_4._0_1_ = 1;
  Path::Path(&param_1->exceptionPathValue,10);
  uStack_4 = CONCAT31(uStack_4._1_3_,2);
  param_1->rangeStatusValue = 2;
  param_1->currentTerrainException1 = -1;
  param_1->currentTerrainException2 = -1;
  param_1->storePathInExceptionPath = '\0';
  param_1->waitingToMoveValue = '\0';
  param_1->numberWaitDelays = '\0';
  param_1->userDefinedWaypoints = (XYZBYTEPoint *)0x0;
  param_1->numberUserDefinedWaypointsValue = 0;
  param_1->maxUserDefinedWaypointsValue = 0;
  param_1->finalUserDefinedWaypoint = '\0';
  param_1->_padding_ = (int)&RGE_Moving_Object::_vftable_;
  (param_1->startValue).x = 0.0;
  (param_1->startValue).y = 0.0;
  (param_1->startValue).z = 0.0;
  RGE_Moving_Object::setGoal(param_1,0.0,0.0,0.0);
  param_1->turnTimer = 0.0;
  param_1->lastFacet = 0xff;
  param_1->lastFacet2 = 0xff;
  param_1->collisionAvoidanceDistance = 0.0;
  param_1->actionRange = 0.0;
  param_1->targetIDValue = -1;
  param_1->targetRadiusX = 0.0;
  param_1->targetRadiusY = 0.0;
  param_1->continueCounter = 0;
  param_1->closestDistanceToWaypoint = 100000.0;
  if (param_4 != 0) {
    RGE_Moving_Object::setup(param_1,param_2,param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0045c6f4
// Address: 0045c6f4
// XREFS: None
void __fastcall FUN_0045c6f4(RGE_Static_Object *param_1)
{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  pcStack_8 = FUN_0055dce4;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_Moving_Object::_vftable_;
  pvVar1 = (void *)param_1[2].pathingGroupMembers.numberValue;
  iStack_4 = 2;
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
    param_1[2].pathingGroupMembers.numberValue = 0;
  }
  iStack_4._0_1_ = 1;
  Path::~Path((Path *)&param_1[1].player_object_node);
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  Path::~Path((Path *)&param_1[1].tile);
  iStack_4 = 0xffffffff;
  RGE_Static_Object::~RGE_Static_Object(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0045c787
// Address: 0045c787
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_move_obj_c: "C:\msdev\work\age1_x1\move_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0045c787(RGE_Moving_Object *param_1,RGE_Master_Static_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  short sVar1;
  float fVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  Path PStack_40;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055dcf8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  Path::Path(&PStack_40,10);
  uStack_4 = 0;
  Path::operator=(&param_1->pathValue,&PStack_40);
  uStack_4 = 0xffffffff;
  Path::~Path(&PStack_40);
  param_1->rangeStatusValue = 2;
  param_1->currentTerrainException1 = -1;
  param_1->currentTerrainException2 = -1;
  param_1->storePathInExceptionPath = '\0';
  param_1->waitingToMoveValue = '\0';
  param_1->numberWaitDelays = '\0';
  (param_1->startValue).x = 0.0;
  (param_1->startValue).y = 0.0;
  (param_1->startValue).z = 0.0;
  RGE_Moving_Object::setGoal(param_1,0.0,0.0,0.0);
  param_1->lastFacet = 0xff;
  param_1->lastFacet2 = 0xff;
  param_1->turnTimer = 0.0;
  param_1->collisionAvoidanceDistance = 0.0;
  param_1->actionRange = 0.0;
  param_1->targetIDValue = -1;
  param_1->targetRadiusX = 0.0;
  param_1->targetRadiusY = 0.0;
  param_1->continueCounter = 0;
  param_1->closestDistanceToWaypoint = 100000.0;
  RGE_Animated_Object::recycle_in_to_game
            ((RGE_Animated_Object *)param_1,param_2,param_3,param_4,param_5,param_6);
  iVar3 = param_1->_padding_;
  param_1->velocity_x = 0.0;
  param_1->velocity_y = 0.0;
  param_1->velocity_z = 0.0;
  param_1->angle = 0.0;
  param_1->turn_towards_time = 0.0;
  param_1->trail_remainder = 0.0;
  if (((iVar3 != 0) && ((*(byte *)(iVar3 + 0x70) & 2) != 0)) && (1 < *(short *)(iVar3 + 0x60))) {
    sVar1 = *(short *)(iVar3 + 0x60);
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0xc5);
    fVar2 = ((float)_DAT_00570b40 / (float)(int)sVar1) * (float)((iVar3 * sVar1) / 0x7fff);
    param_1->angle = fVar2;
    if (_DAT_00570b48 <= fVar2) {
      if (_DAT_00570b50 < fVar2) {
        param_1->angle = fVar2 - _DAT_00570b50;
      }
    }
    else {
      param_1->angle = fVar2 - _DAT_00570b4c;
    }
  }
  RGE_Moving_Object::set_angle(param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_0045c967
// Address: 0045c967
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_move_obj_c: "C:\msdev\work\age1_x1\move_obj.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0045c967(RGE_Moving_Object *param_1,RGE_Master_Animated_Object *param_2,RGE_Player *param_3,
            float param_4,float param_5,float param_6)
{
  short sVar1;
  float fVar2;
  int iVar3;
  
  RGE_Animated_Object::setup((RGE_Animated_Object *)param_1,param_2,param_3,param_4,param_5,param_6)
  ;
  iVar3 = param_1->_padding_;
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x1e;
  param_1->velocity_x = 0.0;
  param_1->velocity_y = 0.0;
  param_1->velocity_z = 0.0;
  param_1->angle = 0.0;
  param_1->turn_towards_time = 0.0;
  param_1->trail_remainder = 0.0;
  if (((iVar3 != 0) && ((*(byte *)(iVar3 + 0x70) & 2) != 0)) && (1 < *(short *)(iVar3 + 0x60))) {
    sVar1 = *(short *)(iVar3 + 0x60);
    iVar3 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0xde);
    fVar2 = ((float)_DAT_00570b40 / (float)(int)sVar1) * (float)((iVar3 * sVar1) / 0x7fff);
    param_1->angle = fVar2;
    if (fVar2 < _DAT_00570b48) {
      param_1->angle = fVar2 - _DAT_00570b4c;
      RGE_Moving_Object::set_angle(param_1);
      return 1;
    }
    if (_DAT_00570b50 < fVar2) {
      param_1->angle = fVar2 - _DAT_00570b50;
      RGE_Moving_Object::set_angle(param_1);
      return 1;
    }
  }
  RGE_Moving_Object::set_angle(param_1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045ca93
// Address: 0045ca93
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0045ca93(RGE_Animated_Object *param_1,int param_2,RGE_Game_World *param_3)
{
  int *piVar1;
  Waypoint WVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar3 = param_2;
  RGE_Animated_Object::setup(param_1,param_2,param_3);
  *(undefined1 *)((int)&param_1->_padding_ + 2) = 0x1e;
  rge_read(iVar3,param_1 + 1,4);
  rge_read(iVar3,&param_1[1]._padding_,4);
  rge_read(iVar3,&param_1[1]._padding_,4);
  rge_read(iVar3,&param_1[1]._padding_,4);
  rge_read(iVar3,&param_1[1]._padding_,4);
  rge_read(iVar3,&param_1[1]._padding_,4);
  rge_read(iVar3,&param_2,4);
  iVar5 = 0;
  if (0 < param_2) {
    do {
      rge_read(iVar3,&uStack_10,0x10);
      WVar2.y = (float)uStack_c;
      WVar2.x = (float)uStack_10;
      WVar2.z = (float)uStack_8;
      WVar2._12_4_ = uStack_4;
      Path::insertAtEnd((Path *)&param_1[1]._padding_,WVar2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_2);
  }
  rge_read(iVar3,&iStack_14,4);
  iVar5 = 0;
  Path::initToStart((Path *)&param_1[1]._padding_);
  if (0 < iStack_14) {
    do {
      Path::moveToNextWaypoint((Path *)&param_1[1]._padding_);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iStack_14);
  }
  rge_read(iVar3,&param_1[1]._padding_,0x10);
  rge_read(iVar3,&param_1[2]._padding_,0x10);
  rge_read(iVar3,&param_1[2]._padding_,4);
  rge_read(iVar3,&param_1[2]._padding_,4);
  rge_read(iVar3,&param_1[2]._padding_,4);
  rge_read(iVar3,&param_1[2]._padding_,4);
  rge_read(iVar3,&param_1[2]._padding_,4);
  rge_read(iVar3,&param_1[2]._padding_,4);
  rge_read(iVar3,&param_1[2]._padding_,4);
  rge_read(iVar3,&param_1[2]._padding_,4);
  rge_read(iVar3,(void *)((int)&param_1[2]._padding_ + 1),1);
  rge_read(iVar3,(void *)((int)&param_1[2]._padding_ + 2),1);
  piVar1 = &param_1[2]._padding_;
  rge_read(iVar3,piVar1,4);
  rge_read(iVar3,&param_1[2]._padding_,4);
  pvVar4 = operator_new(param_1[2]._padding_ * 3);
  param_1[2]._padding_ = (int)pvVar4;
  iVar5 = 0;
  if (0 < *piVar1) {
    param_3 = (RGE_Game_World *)0x0;
    do {
      rge_read(iVar3,(void *)((int)&param_3->_padding_ + param_1[2]._padding_),3);
      iVar5 = iVar5 + 1;
      param_3 = (RGE_Game_World *)((int)&param_3->_padding_ + 3);
    } while (iVar5 < *piVar1);
  }
  rge_read(iVar3,&param_1[2]._padding_,1);
  if (save_game_version < _DAT_00570b54) {
    param_1[2]._padding_ = -1;
    param_1[2]._padding_ = -1;
    param_1[2]._padding_ = -1;
    param_1[2]._padding_ = -1;
  }
  else {
    rge_read(iVar3,&param_1[2]._padding_,8);
    rge_read(iVar3,&param_1[2]._padding_,8);
  }
  if (save_game_version < _DAT_00570b58) {
    param_1[2]._padding_ = 0x47c35000;
    *(undefined1 *)&param_1[2]._padding_ = 0xff;
  }
  else {
    rge_read(iVar3,&param_1[2]._padding_,4);
    rge_read(iVar3,&param_1[2]._padding_,1);
  }
  if (_DAT_00570b5c <= save_game_version) {
    rge_read(iVar3,(void *)((int)&param_1[2]._padding_ + 1),1);
    return 1;
  }
  *(undefined1 *)((int)&param_1[2]._padding_ + 1) = 0xff;
  return 1;
}

// --------------------------------------------------

// Function: FUN_0045cdfe
// Address: 0045cdfe
// XREFS: None
void __thiscall FUN_0045cdfe(RGE_Animated_Object *param_1,int param_2)
{
  int *this;
  int iVar1;
  Waypoint *pWVar2;
  int iVar3;
  int iVar4;
  RGE_Animated_Object *pRStack_4;
  
  iVar1 = param_2;
  pRStack_4 = param_1;
  RGE_Animated_Object::save(param_1,param_2);
  rge_write(iVar1,param_1 + 1,4);
  rge_write(iVar1,&param_1[1]._padding_,4);
  rge_write(iVar1,&param_1[1]._padding_,4);
  rge_write(iVar1,&param_1[1]._padding_,4);
  rge_write(iVar1,&param_1[1]._padding_,4);
  rge_write(iVar1,&param_1[1]._padding_,4);
  this = &param_1[1]._padding_;
  param_2 = Path::numberOfWaypoints((Path *)this);
  rge_write(iVar1,&param_2,4);
  iVar3 = 0;
  if (0 < param_2) {
    do {
      iVar4 = 0x10;
      pWVar2 = Path::waypoint((Path *)this,iVar3);
      rge_write(iVar1,pWVar2,iVar4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  pRStack_4 = (RGE_Animated_Object *)Path::currentWaypointNumber((Path *)this);
  rge_write(iVar1,&pRStack_4,4);
  rge_write(iVar1,&param_1[1]._padding_,0x10);
  rge_write(iVar1,&param_1[2]._padding_,0x10);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,(void *)((int)&param_1[2]._padding_ + 1),1);
  rge_write(iVar1,(void *)((int)&param_1[2]._padding_ + 2),1);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,4);
  iVar3 = 0;
  if (0 < param_1[2]._padding_) {
    iVar4 = 0;
    do {
      rge_write(iVar1,(void *)(iVar4 + param_1[2]._padding_),3);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 3;
    } while (iVar3 < param_1[2]._padding_);
  }
  rge_write(iVar1,&param_1[2]._padding_,1);
  rge_write(iVar1,&param_1[2]._padding_,8);
  rge_write(iVar1,&param_1[2]._padding_,8);
  rge_write(iVar1,&param_1[2]._padding_,4);
  rge_write(iVar1,&param_1[2]._padding_,1);
  rge_write(iVar1,(void *)((int)&param_1[2]._padding_ + 1),1);
  return;
}

// --------------------------------------------------

// Function: FUN_0045d07f
// Address: 0045d07f
// XREFS: None
void __thiscall FUN_0045d07f(RGE_Moving_Object *param_1,RGE_Sprite *param_2)
{
  if (param_2 == (RGE_Sprite *)0x0) {
    param_2 = *(RGE_Sprite **)(param_1->_padding_ + 0x18);
  }
  if ((RGE_Sprite *)param_1->_padding_ != param_2) {
    param_1->_padding_ = param_1->_padding_;
    RGE_Static_Object::new_sprite((RGE_Static_Object *)param_1,param_2);
    RGE_Moving_Object::set_angle(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0045d0ae
// Address: 0045d0ae
// XREFS: None
RGE_Static_Object * __fastcall FUN_0045d0ae(RGE_Static_Object *param_1)
{
  RGE_Static_Object *pRVar1;
  
  pRVar1 = RGE_Static_Object::spawn_death_obj(param_1);
  if ((pRVar1 != (RGE_Static_Object *)0x0) && (0x1d < pRVar1->master_obj->master_type)) {
    (**(code **)(pRVar1->_padding_ + 0xb4))(param_1[1].old_sprite);
  }
  return pRVar1;
}

// --------------------------------------------------

// Function: FUN_0045d0de
// Address: 0045d0de
// XREFS: None
void __thiscall FUN_0045d0de(RGE_Moving_Object *param_1,RGE_Master_Static_Object *param_2)
{
  RGE_Animated_Object::transform((RGE_Animated_Object *)param_1,param_2);
  param_1->velocity_x = 0.0;
  param_1->velocity_y = 0.0;
  param_1->velocity_z = 0.0;
  param_1->collisionAvoidanceDistance = 0.0;
  param_1->turnTimer = 0.0;
  param_1->turn_towards_time = 0.0;
  RGE_Moving_Object::set_angle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0045d11e
// Address: 0045d11e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short __fastcall FUN_0045d11e(int param_1)
{
  float fVar1;
  byte bVar2;
  
  fVar1 = *(float *)(param_1 + 0x88);
  bVar2 = fVar1 < _DAT_00570b48 |
          (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00570b48)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar1 == _DAT_00570b48) << 0xe) >> 8);
  if (fVar1 >= _DAT_00570b48 && (fVar1 == _DAT_00570b48) == 0) {
    return CONCAT11(bVar2,1);
  }
  return (ushort)bVar2 << 8;
}

// --------------------------------------------------

// Function: FUN_0045d139
// Address: 0045d139
// XREFS: None
void __fastcall FUN_0045d139(int param_1)
{
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0045d14b
// Address: 0045d14b
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0045d14b(int param_1,int param_2,float param_3,float param_4)
{
  int iVar1;
  float10 fVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x70) & 2) != 0)) && (0 < *(short *)(iVar1 + 0x60))) {
    if (param_2 != 0) {
      param_4 = *(float *)(param_2 + 0x3c);
      param_3 = *(float *)(param_2 + 0x38);
    }
    fVar2 = (float10)fpatan((float10)param_4 - (float10)*(float *)(param_1 + 0x3c),
                            (float10)param_3 - (float10)*(float *)(param_1 + 0x38));
    if (fVar2 < (float10)_DAT_00570b48) {
      fVar2 = fVar2 - (float10)_DAT_00570b4c;
    }
    fVar2 = fVar2 - (float10)*(float *)(param_1 + 0x9c);
    if ((float10)_DAT_00570b68 < fVar2) {
      fVar2 = fVar2 - (float10)_DAT_00570b50;
    }
    if (fVar2 < (float10)_DAT_00570b70) {
      fVar2 = fVar2 - (float10)_DAT_00570b4c;
    }
    return (float10)(int)*(short *)(iVar1 + 0x60) * (float10)_DAT_00570b78 * fVar2;
  }
  return (float10)_DAT_00570b48;
}

// --------------------------------------------------

// Function: FUN_0045d356
// Address: 0045d356
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045d356(int param_1)
{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x70) & 2) != 0)) && (0 < *(short *)(iVar1 + 0x60))) {
    uVar2 = __ftol();
    *(undefined1 *)(param_1 + 0x35) = uVar2;
    return;
  }
  *(undefined1 *)(param_1 + 0x35) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0045d3c8
// Address: 0045d3c8
// XREFS: None
float10 __thiscall
FUN_0045d3c8(RGE_Static_Object *param_1,float param_2,float param_3,float param_4)
{
  char cVar1;
  RGE_Master_Static_Object *pRVar2;
  code *pcVar3;
  float10 fVar4;
  float10 fVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  int *piVar9;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float fVar10;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  int iStack_c;
  
  cVar1 = (char)param_1->master_obj[1].object_group;
  if ((cVar1 != '\0') && (param_1->tile != (RGE_Tile *)0x0)) {
    pRVar2 = param_1->owner->master_objects[param_1->master_obj[1].copy_id];
    if (pRVar2 != (RGE_Master_Static_Object *)0x0) {
      if (cVar1 == '\x01') {
        piVar9 = (int *)(**(code **)(pRVar2->_padding_ + 0x18))
                                  (param_1->owner,param_1->world_x,param_1->world_y,param_1->world_z
                                  );
        if (0x1e < *(short *)(piVar9[2] + 0x10)) {
          (**(code **)(*piVar9 + 0xb4))(param_1[1].old_sprite);
        }
      }
      else if (cVar1 == '\x02') {
        fVar6 = param_2 - param_1->world_x;
        fVar10 = param_3 - param_1->world_y;
        fVar7 = param_4 - param_1->world_z;
        fVar10 = SQRT(fVar7 * fVar7 + fVar10 * fVar10 + fVar6 * fVar6) + (float)param_1[1].id;
        sVar8 = __ftol();
        if (sVar8 < 1) {
          param_1[1].id = (long)(fVar10 + (float)param_1[1].id);
        }
        else {
          iStack_c = (int)sVar8;
          fStack_18 = param_1->world_y;
          fVar6 = (float)iStack_c;
          fStack_1c = param_1->world_x;
          fVar4 = (float10)iStack_c;
          fStack_14 = param_1->world_z;
          fVar5 = (float10)iStack_c;
          if (0 < sVar8) {
            pcVar3 = *(code **)(pRVar2->_padding_ + 0x18);
            do {
              piVar9 = (int *)(*pcVar3)(param_1->owner,fStack_1c,fStack_18,fStack_14);
              if (0x1e < *(short *)(piVar9[2] + 0x10)) {
                (**(code **)(*piVar9 + 0xb4))(param_1[1].old_sprite);
              }
              fStack_1c = fStack_1c + (float)(extraout_ST1 / fVar4);
              fStack_18 = fStack_18 + (float)(extraout_ST0 / fVar5);
              fStack_14 = fStack_14 + fVar7 / fVar6;
              iStack_c = iStack_c + -1;
            } while (iStack_c != 0);
          }
          param_1[1].id = (long)(fVar10 - (float)param_1->master_obj[1].sprite * fVar6);
        }
      }
    }
  }
  fVar10 = RGE_Static_Object::teleport(param_1,param_2,param_3,param_4);
  return (float10)fVar10;
}

// --------------------------------------------------

// Function: FUN_0045d5bb
// Address: 0045d5bb
// XREFS: None
void __thiscall FUN_0045d5bb(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x90) = param_2;
  *(undefined4 *)(param_1 + 0x94) = param_3;
  *(undefined4 *)(param_1 + 0x98) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_0045d5e1
// Address: 0045d5e1
// XREFS: None
void __thiscall FUN_0045d5e1(RGE_Moving_Object *param_1,float param_2)
{
  param_1->angle = param_2;
  RGE_Moving_Object::set_angle(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0045d602
// Address: 0045d602
// XREFS: None
int __fastcall FUN_0045d602(int param_1)
{
  return param_1 + 0xa4;
}

// --------------------------------------------------

// Function: FUN_0045d617
// Address: 0045d617
// XREFS: None
uchar __fastcall FUN_0045d617(int param_1)
{
  Waypoint *pWVar1;
  
  pWVar1 = Path::currentWaypoint((Path *)(param_1 + 0xa4));
  if (pWVar1 != (Waypoint *)0x0) {
    pWVar1 = Path::currentWaypoint((Path *)(param_1 + 0xa4));
    return pWVar1->facetToNextWaypoint;
  }
  return 0xff;
}

// --------------------------------------------------

// Function: FUN_0045d642
// Address: 0045d642
// XREFS: None
void __thiscall FUN_0045d642(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x11c) = param_2;
  *(undefined4 *)(param_1 + 0x120) = param_3;
  *(undefined4 *)(param_1 + 0x124) = param_4;
  return;
}

// --------------------------------------------------

// Function: FUN_0045d671
// Address: 0045d671
// XREFS: None
void __thiscall FUN_0045d671(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x134) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0045d68d
// Address: 0045d68d
// XREFS: None
void __thiscall FUN_0045d68d(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x138) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0045d69d
// Address: 0045d69d
// XREFS: None
void __thiscall FUN_0045d69d(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  *(undefined4 *)(param_1 + 0x140) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_0045d6b7
// Address: 0045d6b7
// XREFS: None
// [HELPER] s___: "]\n"
// [HELPER] s_t_ld_uID__d__fP1_s___6_2f__6_2f_: "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)"
/* WARNING: Removing unreachable block (ram,0x0045d774) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0045d6b7(RGE_Moving_Object *param_1)
{
  Path *pPVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  Waypoint *pWVar8;
  int unaff_EBX;
  float10 fVar9;
  RGE_Moving_Object *pRVar10;
  float fVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  
  if (*(float *)(param_1->_padding_ + 0x38) <= _DAT_00570b48) {
    (**(code **)(param_1->_padding_ + 300))(0);
    pPVar1 = &param_1->pathValue;
    (param_1->startValue).x = (float)param_1->_padding_;
    (param_1->startValue).y = (float)param_1->_padding_;
    (param_1->startValue).z = (float)param_1->_padding_;
    param_1->_padding_ = 0;
    Path::setTimeStamp(pPVar1,*(ulong *)(*(int *)(param_1->_padding_ + 0x3c) + 4));
    Path::killPath(pPVar1);
    Path::insertAtCurrent(pPVar1,&param_1->goalValue);
    Path::insertAtCurrent(pPVar1,&param_1->startValue);
    Path::initToStart(pPVar1);
    Path::moveToNextWaypoint(pPVar1);
    param_1->closestDistanceToWaypoint = 100000.0;
    return 0;
  }
  iVar2 = RGE_Player::availablePathingAttempts
                    ((RGE_Player *)param_1->_padding_,(uint)param_1->numberWaitDelays);
  if (iVar2 == 0) {
    param_1->numberWaitDelays = param_1->numberWaitDelays + '\x01';
    return 2;
  }
  RGE_Player::incrementPathingAttempts((RGE_Player *)param_1->_padding_);
  iVar2 = param_1->_padding_;
  param_1->numberWaitDelays = '\0';
  (**(code **)(iVar2 + 300))(0);
  iVar3 = RGE_Player::computerPlayer((RGE_Player *)param_1->_padding_);
  if (iVar3 == 0) {
    param_1->continueCounter = param_1->numberUserDefinedWaypointsValue + 0x19;
  }
  else {
    param_1->continueCounter = param_1->numberUserDefinedWaypointsValue + 0xf;
  }
  (param_1->startValue).x = (float)param_1->_padding_;
  (param_1->startValue).y = (float)param_1->_padding_;
  (param_1->startValue).z = (float)param_1->_padding_;
  param_1->closestDistanceToWaypoint = 100000.0;
  PathingSystem::incrementInitialPaths(&pathSystem);
  pRVar10 = param_1;
  if (param_1->numberUserDefinedWaypointsValue < 1) {
    iVar3 = param_1->targetIDValue;
    fVar11 = param_1->actionRange;
    iVar17 = -1;
    iVar16 = -1;
    iVar15 = 1;
    iVar14 = 1;
    uVar13 = 0x100000001;
    uVar12 = 1;
    uVar4 = __ftol();
    uVar5 = __ftol();
  }
  else {
    iVar3 = param_1->targetIDValue;
    fVar11 = param_1->actionRange;
    iVar17 = -1;
    iVar16 = -1;
    iVar15 = 1;
    iVar14 = 1;
    uVar13 = 0x100000001;
    uVar12 = 1;
    uVar4 = (uint)param_1->userDefinedWaypoints->y;
    uVar5 = (uint)param_1->userDefinedWaypoints->x;
  }
  iVar6 = __ftol();
  iVar7 = __ftol();
  iVar3 = PathingSystem::findTilePath
                    (&pathSystem,iVar7,iVar6,uVar5,uVar4,pRVar10,fVar11,iVar3,(int)uVar12,
                     (float *)((ulonglong)uVar12 >> 0x20),(int)uVar13,
                     (int)((ulonglong)uVar13 >> 0x20),iVar14,iVar15,iVar16,iVar17);
  if (actionFile != (_iobuf *)0x0) {
    fprintf(actionFile,s_t_ld_uID__d__fP1_s___6_2f__6_2f_,
            *(undefined4 *)(*(int *)(param_1->_padding_ + 0x3c) + 4),param_1->_padding_,
            (double)(param_1->startValue).x,(double)(param_1->startValue).y,
            (double)(param_1->goalValue).x,(double)(param_1->goalValue).y);
    pPVar1 = &param_1->pathValue;
    Path::initToStart(pPVar1);
    iVar14 = 0;
    iVar2 = Path::numberOfWaypoints(pPVar1);
    if (0 < iVar2) {
      do {
        Path::currentWaypoint(pPVar1);
        Path::currentWaypoint(pPVar1);
        fprintf();
        iVar14 = iVar14 + 1;
        Path::moveToNextWaypoint(pPVar1);
        iVar2 = Path::numberOfWaypoints(pPVar1);
      } while (iVar14 < iVar2);
    }
    fprintf(actionFile,s___);
    Path::initToStart(pPVar1);
    Path::moveToNextWaypoint(pPVar1);
    iVar2 = unaff_EBX;
  }
  if ((iVar3 == 0) && (iVar3 = Path::numberOfWaypoints(&param_1->pathValue), iVar3 == 1)) {
    fVar9 = (float10)floor((double)(float)param_1->_padding_);
    fVar11 = (float)(fVar9 - (float10)_DAT_00570b80);
    fVar9 = (float10)floor((double)(float)param_1->_padding_);
    iVar3 = PathingSystem::passable
                      (&pathSystem,param_1,(float)(fVar9 - (float10)_DAT_00570b80),fVar11,iVar3);
    if (iVar3 != 0) {
      fVar11 = (float)param_1->_padding_;
      fVar9 = (float10)floor((double)fVar11);
      if ((float10)fVar11 - fVar9 == (float10)_DAT_00570b90) {
        fVar11 = (float)param_1->_padding_;
        fVar9 = (float10)floor((double)fVar11);
        if ((float10)fVar11 - fVar9 == (float10)_DAT_00570b90) goto LAB_0045dab9;
      }
      fVar9 = (float10)floor((double)(float)param_1->_padding_,param_1->_padding_);
      fVar9 = (float10)floor((double)(float)param_1->_padding_,
                             (float)(fVar9 - (float10)_DAT_00570b80));
      (**(code **)(iVar2 + 0x34))((float)(fVar9 - (float10)_DAT_00570b80));
      return 2;
    }
  }
LAB_0045dab9:
  pPVar1 = &param_1->pathValue;
  Path::setTimeStamp(pPVar1,*(ulong *)(*(int *)(param_1->_padding_ + 0x3c) + 4));
  iVar2 = displayPathObjectID;
  if ((displayPathingFlags != 0) && ((param_1->_padding_ & 0x10000) != 0)) {
    Path::initToStart(pPVar1);
    iVar14 = 0;
    iVar3 = Path::numberOfWaypoints(pPVar1);
    if (0 < iVar3) {
      do {
        iVar3 = param_1->_padding_;
        uVar18 = 0x3f800000;
        iVar15 = **(int **)(*(int *)(iVar3 + 0x24) + iVar2 * 4);
        pWVar8 = Path::currentWaypoint(pPVar1);
        fVar11 = pWVar8->y;
        pWVar8 = Path::currentWaypoint(pPVar1);
        (**(code **)(iVar15 + 0x18))(iVar3,pWVar8->x,fVar11,uVar18);
        iVar14 = iVar14 + 1;
        Path::moveToNextWaypoint(pPVar1);
        iVar3 = Path::numberOfWaypoints(pPVar1);
      } while (iVar14 < iVar3);
    }
    Path::initToStart(pPVar1);
    Path::moveToNextWaypoint(pPVar1);
  }
  Path::initToStart(pPVar1);
  Path::moveToNextWaypoint(pPVar1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0045e967
// Address: 0045e967
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_move_obj_c: "C:\msdev\work\age1_x1\move_obj.cpp"
// [HELPER] s___: "]\n"
// [HELPER] s_t_ld_uID__d__fP1_s___6_2f__6_2f_: "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f,%6.2f)"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0045e967(RGE_Moving_Object *param_1,float param_2,float param_3)
{
  float *pfVar1;
  Path *pPVar2;
  uchar uVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  RGE_Static_Object *pRVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  Waypoint *pWVar12;
  int iVar13;
  int iVar14;
  float10 fVar15;
  float10 fVar16;
  float fVar17;
  RGE_Moving_Object *pRVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  undefined4 uVar25;
  float fVar26;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  int iStack_18;
  float fStack_14;
  undefined8 uStack_10;
  
  bVar4 = true;
  iStack_18 = 1;
  if ((float)param_1->_padding_ == (float)_DAT_00570b98) {
    iVar14 = param_1->_padding_;
    bVar4 = false;
    iStack_18 = 0;
    if ((iVar14 == 0) || (*(float *)(iVar14 + 100) <= (float)_DAT_00570b98)) {
      param_1->_padding_ = *(int *)(param_1->_padding_ + 0xb8);
    }
    else {
      param_1->_padding_ = (int)(*(float *)(param_1->_padding_ + 0xb8) * *(float *)(iVar14 + 100));
    }
  }
  fStack_28 = *(float *)(*(int *)(param_1->_padding_ + 0x3c) + 0x84) * (float)param_1->_padding_;
  if ((float)_DAT_00570b98 < param_1->collisionAvoidanceDistance) {
    fVar26 = param_1->collisionAvoidanceDistance - fStack_28;
    fVar17 = (float)_DAT_00570b98;
    param_1->collisionAvoidanceDistance = fVar26;
    if (fVar17 < fVar26) {
      param_1->_padding_ = 0;
      return 0;
    }
    param_1->collisionAvoidanceDistance = -1.0;
  }
  if ((float)_DAT_00570b98 < *(float *)(param_1->_padding_ + 0xc4)) {
    if ((float)_DAT_00570b98 <= param_1->turnTimer) {
      param_1->turnTimer =
           param_1->turnTimer - *(float *)(*(int *)(param_1->_padding_ + 0x3c) + 0x84);
    }
    else {
      param_1->turnTimer = 0.0;
    }
  }
  if (param_1->_padding_ == 0) {
    iVar14 = 8;
  }
  else {
    iVar14 = (int)*(short *)(param_1->_padding_ + 0x60);
  }
  if (bVar4) {
    fStack_30 = param_2 - (float)param_1->_padding_;
    fVar15 = (float10)param_3 - (float10)(float)param_1->_padding_;
  }
  else {
    fVar15 = (float10)floor((double)(float)param_1->_padding_);
    fStack_30 = (float)((float10)param_2 - (fVar15 - (float10)_DAT_00570b80));
    fVar15 = (float10)floor((double)(float)param_1->_padding_);
    fVar15 = (float10)param_3 - (fVar15 - (float10)_DAT_00570b80);
  }
  fVar15 = (float10)fpatan(fVar15,(float10)fStack_30);
  fStack_2c = (float)fVar15;
  RGE_Moving_Object::boundAngle(param_1,&fStack_2c,-1);
  fStack_30 = fStack_2c - param_1->angle;
  if (fStack_30 < (float)_DAT_00570b70) {
    do {
      fStack_30 = fStack_30 - _DAT_00570b4c;
    } while (fStack_30 < (float)_DAT_00570b70);
  }
  if ((float)_DAT_00570b68 < fStack_30) {
    do {
      fStack_30 = fStack_30 - _DAT_00570b50;
    } while ((float)_DAT_00570b68 < fStack_30);
  }
  fStack_14 = (float)iVar14;
  pfVar1 = &param_1->angle;
  fStack_1c = fStack_30 * fStack_14 * _DAT_00570b78;
  RGE_Moving_Object::boundAngle(param_1,pfVar1,iVar14);
  fVar26 = fStack_1c;
  if (param_1->turnTimer <= _DAT_00570b48) {
    do {
      if ((fVar26 <= (float)_DAT_00570bb0) && ((float)_DAT_00570bb8 <= fVar26)) break;
      bVar4 = _DAT_00570b48 <= fStack_30;
      param_1->turnTimer = *(float *)(param_1->_padding_ + 0xc4) + param_1->turnTimer;
      if (bVar4) {
        fVar5 = (float)_DAT_00570b40 / (float)iVar14 + *pfVar1;
        fVar17 = _DAT_00570b60;
      }
      else {
        fVar5 = *pfVar1 - (float)_DAT_00570b40 / (float)iVar14;
        fVar17 = _DAT_00570b64;
      }
      *pfVar1 = fVar5;
      fVar26 = fVar26 - fVar17;
    } while (param_1->turnTimer <= _DAT_00570b48);
  }
  RGE_Moving_Object::boundAngle(param_1,pfVar1,iVar14);
  RGE_Moving_Object::set_angle(param_1);
  fVar15 = (float10)fcos((float10)*pfVar1);
  iVar13 = 1;
  fVar16 = (float10)fsin((float10)*pfVar1);
  fStack_24 = (float)(fVar16 * (float10)fStack_28);
  param_1->velocity_x = (float)(fVar15 * (float10)fStack_28);
  param_1->velocity_y = (float)(fVar16 * (float10)fStack_28);
  fVar26 = (float)param_1->_padding_ + (float)(fVar15 * (float10)fStack_28);
  fStack_20 = (float)param_1->_padding_ + fStack_24;
  fStack_1c = fVar26;
  if (_DAT_00570b48 < *(float *)(param_1->_padding_ + 0x38)) {
    iVar13 = PathingSystem::passable(&pathSystem,param_1,fVar26,fStack_20,1);
  }
  if (iVar13 == 0) {
    if (param_1->collisionAvoidanceDistance == _DAT_00570b48) {
      if ((float)param_1->_padding_ <= _DAT_00570b48) {
        iVar14 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0x6d1);
        param_1->_padding_ = 0;
        param_1->collisionAvoidanceDistance = (float)(iVar14 % 6) * _DAT_00570bc0 - _DAT_00570b80;
        return 0;
      }
      iVar14 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0x6cf);
      fVar26 = (float)(iVar14 % 6) * _DAT_00570bc0;
      fVar17 = _DAT_00570b80 / (float)param_1->_padding_;
      param_1->_padding_ = 0;
      param_1->collisionAvoidanceDistance = fVar26 - fVar17;
      return 0;
    }
    iVar13 = 1;
    param_1->collisionAvoidanceDistance = 0.0;
    fVar15 = (float10)floor((double)(float)param_1->_padding_);
    fVar26 = (float)(fVar15 - (float10)_DAT_00570b80);
    fVar15 = (float10)floor((double)(float)param_1->_padding_);
    iVar13 = PathingSystem::passable
                       (&pathSystem,param_1,(float)(fVar15 - (float10)_DAT_00570b80),fVar26,iVar13);
    if (iVar13 != 0) {
      iVar13 = param_1->_padding_;
      fVar15 = (float10)floor((double)(float)param_1->_padding_,param_1->_padding_);
      fVar15 = (float10)floor((double)(float)param_1->_padding_,
                              (float)(fVar15 - (float10)_DAT_00570b80));
      (**(code **)(iVar13 + 0x34))((float)(fVar15 - (float10)_DAT_00570b80));
    }
    if (((param_1->targetIDValue != -1) &&
        (pRVar7 = RGE_Game_World::object
                            (*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_1->targetIDValue)
        , pRVar7 != (RGE_Static_Object *)0x0)) &&
       (fVar26 = *(float *)(param_1->_padding_ + 0x34),
       fVar17 = *(float *)(param_1->_padding_ + 0x30),
       fVar5 = pRVar7->world_x - (float)param_1->_padding_,
       fVar6 = pRVar7->world_y - (float)param_1->_padding_,
       fStack_24 = SQRT(fVar6 * fVar6 + fVar5 * fVar5),
       fStack_24 < (SQRT(fVar26 * fVar26 + fVar17 * fVar17) + param_1->actionRange) - _DAT_00570ba8)
       ) {
      return 5;
    }
    iVar13 = PathingSystem::passable(&pathSystem,param_1,param_2,param_3,1);
    if (iVar13 == 0) {
      return 2;
    }
    iVar13 = param_1->continueCounter + -1;
    param_1->continueCounter = iVar13;
    if (iVar13 < 1) {
      return 4;
    }
    iVar13 = RGE_Player::availablePathingAttempts
                       ((RGE_Player *)param_1->_padding_,(uint)param_1->numberWaitDelays);
    if (iVar13 == 0) {
      param_1->numberWaitDelays = param_1->numberWaitDelays + '\x01';
      return 1;
    }
    RGE_Player::incrementPathingAttempts((RGE_Player *)param_1->_padding_);
    (param_1->startValue).x = (float)param_1->_padding_;
    (param_1->startValue).y = (float)param_1->_padding_;
    (param_1->startValue).z = (float)param_1->_padding_;
    param_1->numberWaitDelays = '\0';
    PathingSystem::incrementContinuePaths(&pathSystem);
    pRVar18 = param_1;
    if (param_1->numberUserDefinedWaypointsValue < 1) {
      iVar13 = param_1->targetIDValue;
      fVar26 = param_1->actionRange;
      iVar24 = -1;
      iVar23 = -1;
      iVar22 = 1;
      iVar21 = 1;
      uVar20 = 0x100000001;
      uVar19 = 1;
      uVar8 = __ftol();
      uVar9 = __ftol();
    }
    else {
      iVar13 = param_1->targetIDValue;
      fVar26 = param_1->actionRange;
      iVar24 = -1;
      iVar23 = -1;
      iVar22 = 1;
      iVar21 = 1;
      uVar20 = 0x100000001;
      uVar19 = 1;
      uVar8 = (uint)param_1->userDefinedWaypoints->y;
      uVar9 = (uint)param_1->userDefinedWaypoints->x;
    }
    iVar10 = __ftol();
    iVar11 = __ftol();
    fStack_24 = (float)PathingSystem::findTilePath
                                 (&pathSystem,iVar11,iVar10,uVar9,uVar8,pRVar18,fVar26,iVar13,
                                  (int)uVar19,(float *)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                                  (int)((ulonglong)uVar20 >> 0x20),iVar21,iVar22,iVar23,iVar24);
    if (actionFile != (_iobuf *)0x0) {
      fprintf(actionFile,s_t_ld_uID__d__fP1_s___6_2f__6_2f_,
              *(undefined4 *)(*(int *)(param_1->_padding_ + 0x3c) + 4),param_1->_padding_,
              (double)(param_1->startValue).x,(double)(param_1->startValue).y,
              (double)(param_1->goalValue).x,(double)(param_1->goalValue).y);
      pPVar2 = &param_1->pathValue;
      Path::initToStart(pPVar2);
      iVar21 = 0;
      iVar13 = Path::numberOfWaypoints(pPVar2);
      if (0 < iVar13) {
        do {
          Path::currentWaypoint(pPVar2);
          Path::currentWaypoint(pPVar2);
          fprintf();
          iVar21 = iVar21 + 1;
          Path::moveToNextWaypoint(pPVar2);
          iVar13 = Path::numberOfWaypoints(pPVar2);
        } while (iVar21 < iVar13);
      }
      fprintf(actionFile,s___);
      Path::initToStart(pPVar2);
      Path::moveToNextWaypoint(pPVar2);
    }
    if ((fStack_24 == 0.0) && (iVar13 = Path::numberOfWaypoints(&param_1->pathValue), iVar13 == 1))
{
      fVar15 = (float10)floor((double)(float)param_1->_padding_);
      fVar26 = (float)(fVar15 - (float10)_DAT_00570b80);
      fVar15 = (float10)floor((double)(float)param_1->_padding_);
      iVar13 = PathingSystem::passable
                         (&pathSystem,param_1,(float)(fVar15 - (float10)_DAT_00570b80),fVar26,iVar13
                         );
      if (iVar13 != 0) {
        uStack_10 = (double)(float)param_1->_padding_;
        fVar15 = (float10)floor(uStack_10);
        if ((float10)uStack_10 - fVar15 == (float10)_DAT_00570b90) {
          uStack_10 = (double)(float)param_1->_padding_;
          fVar15 = (float10)floor(uStack_10);
          if ((float10)uStack_10 - fVar15 == (float10)_DAT_00570b90) {
            return 4;
          }
        }
        iVar13 = param_1->_padding_;
        fVar15 = (float10)floor((double)(float)param_1->_padding_,param_1->_padding_);
        fVar15 = (float10)floor((double)(float)param_1->_padding_,
                                (float)(fVar15 - (float10)_DAT_00570b80));
        (**(code **)(iVar13 + 0x34))((float)(fVar15 - (float10)_DAT_00570b80));
      }
    }
    iVar13 = displayPathObjectID;
    if ((displayPathingFlags != 0) && ((param_1->_padding_ & 0x10000) != 0)) {
      pPVar2 = &param_1->pathValue;
      Path::initToStart(pPVar2);
      fStack_24 = 0.0;
      iVar21 = Path::numberOfWaypoints(pPVar2);
      if (0 < iVar21) {
        iVar13 = iVar13 << 2;
        uStack_10 = (double)CONCAT44(uStack_10._4_4_,iVar13);
        do {
          iVar21 = param_1->_padding_;
          uVar25 = 0x3f800000;
          iVar22 = **(int **)(*(int *)(iVar21 + 0x24) + iVar13);
          pWVar12 = Path::currentWaypoint(pPVar2);
          fVar26 = pWVar12->y;
          pWVar12 = Path::currentWaypoint(pPVar2);
          iVar13 = (int)uStack_10;
          (**(code **)(iVar22 + 0x18))(iVar21,pWVar12->x,fVar26,uVar25);
          fStack_24 = (float)((int)fStack_24 + 1);
          Path::moveToNextWaypoint(pPVar2);
          iVar21 = Path::numberOfWaypoints(pPVar2);
        } while ((int)fStack_24 < iVar21);
      }
      Path::initToStart(pPVar2);
      Path::moveToNextWaypoint(pPVar2);
    }
    pPVar2 = &param_1->pathValue;
    Path::initToStart(pPVar2);
    iVar13 = Path::moveToNextWaypoint(pPVar2);
    if (iVar13 == 0) {
      return 4;
    }
    param_1->closestDistanceToWaypoint = 100000.0;
    if (iStack_18 == 1) {
      pWVar12 = Path::currentWaypoint(pPVar2);
      fStack_30 = pWVar12->x - (float)param_1->_padding_;
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar15 = (float10)pWVar12->y - (float10)(float)param_1->_padding_;
    }
    else {
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar15 = (float10)floor((double)(float)param_1->_padding_);
      fStack_30 = (float)((float10)pWVar12->x - (fVar15 - (float10)_DAT_00570b80));
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar15 = (float10)floor((double)(float)param_1->_padding_);
      fVar15 = (float10)pWVar12->y - (fVar15 - (float10)_DAT_00570b80);
    }
    fVar15 = (float10)fpatan(fVar15,(float10)fStack_30);
    fStack_2c = (float)fVar15;
    RGE_Moving_Object::boundAngle(param_1,&fStack_2c,-1);
    fVar26 = fStack_2c - param_1->angle;
    pfVar1 = &param_1->angle;
    fVar17 = fVar26 * fStack_14 * _DAT_00570b78;
    if (_DAT_00570b48 < param_1->turnTimer) {
      param_1->_padding_ = 0;
      return 0;
    }
    do {
      if ((fVar17 <= (float)_DAT_00570bc8) && ((float)_DAT_00570bd0 <= fVar17)) break;
      bVar4 = _DAT_00570b48 <= fVar26;
      param_1->turnTimer = *(float *)(param_1->_padding_ + 0xc4) + param_1->turnTimer;
      if (bVar4) {
        fVar6 = (float)_DAT_00570b40 / (float)iVar14 + *pfVar1;
        fVar5 = _DAT_00570b60;
      }
      else {
        fVar6 = *pfVar1 - (float)_DAT_00570b40 / (float)iVar14;
        fVar5 = _DAT_00570b64;
      }
      fVar17 = fVar17 - fVar5;
      *pfVar1 = fVar6;
    } while (param_1->turnTimer <= _DAT_00570b48);
    RGE_Moving_Object::boundAngle(param_1,pfVar1,iVar14);
    RGE_Moving_Object::set_angle(param_1);
    fVar15 = (float10)fsin((float10)*pfVar1);
    fVar16 = (float10)fcos((float10)*pfVar1);
    uStack_10 = (double)CONCAT44(uStack_10._4_4_,(float)fVar16);
    fStack_24 = (float)(fVar15 * (float10)fStack_28);
    fStack_20 = (float)param_1->_padding_ + fStack_24;
    fStack_1c = (float)param_1->_padding_ + (float)(fVar16 * (float10)fStack_28);
    param_1->velocity_x = (float)(fVar16 * (float10)fStack_28);
    param_1->velocity_y = fStack_24;
    fStack_14 = fStack_1c;
    iVar14 = PathingSystem::passable(&pathSystem,param_1,fStack_1c,fStack_20,1);
    fVar26 = fStack_1c;
    if (iVar14 == 0) {
      iVar14 = RGE_Player::computerPlayer((RGE_Player *)param_1->_padding_);
      if (iVar14 != 1) {
        if ((float)param_1->_padding_ <= _DAT_00570b48) {
          iVar14 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0x7d5);
          fVar26 = (float)(iVar14 % 6) * _DAT_00570bc0 - _DAT_00570b80;
        }
        else {
          iVar14 = debug_rand(s_C__msdev_work_age1_x1_move_obj_c,0x7d3);
          fVar26 = (float)(iVar14 % 6) * _DAT_00570bc0 - _DAT_00570b80 / (float)param_1->_padding_;
        }
        param_1->collisionAvoidanceDistance = fVar26;
        param_1->_padding_ = 0;
        return 0;
      }
      return 4;
    }
  }
  iStack_18 = param_1->_padding_;
  pPVar2 = &param_1->pathValue;
  pWVar12 = Path::currentWaypoint(pPVar2);
  if (pWVar12 == (Waypoint *)0x0) {
    param_2 = param_2 - fStack_1c;
    fStack_14 = param_3 - fStack_20;
    uStack_10 = (double)param_2;
    fVar17 = param_1->velocity_z + (float)param_1->_padding_;
    iVar14 = param_1->_padding_;
    fStack_1c = SQRT(fStack_14 * fStack_14 + param_2 * param_2);
  }
  else {
    pWVar12 = Path::currentWaypoint(pPVar2);
    fStack_24 = pWVar12->x - (float)param_1->_padding_;
    pWVar12 = Path::currentWaypoint(pPVar2);
    fStack_14 = pWVar12->y - (float)param_1->_padding_;
    fStack_1c = SQRT(fStack_14 * fStack_14 + fStack_24 * fStack_24);
    pWVar12 = Path::currentWaypoint(pPVar2);
    fStack_24 = pWVar12->x - ((float)param_1->_padding_ + param_1->velocity_x);
    pWVar12 = Path::currentWaypoint(pPVar2);
    fVar17 = pWVar12->y - ((float)param_1->_padding_ + param_1->velocity_y);
    fVar17 = SQRT(fVar17 * fVar17 + fStack_24 * fStack_24);
    uStack_10._4_4_ = (undefined4)((ulonglong)(double)fStack_24 >> 0x20);
    uStack_10 = (double)CONCAT44(uStack_10._4_4_,fVar17);
    if (((param_1->closestDistanceToWaypoint < fVar17) && (fStack_1c < _DAT_00570bd8)) ||
       ((param_1->lastFacet2 == *(uchar *)((int)&param_1->_padding_ + 1) &&
        ((param_1->lastFacet2 != param_1->lastFacet && (fStack_1c < _DAT_00570b7c)))))) {
      iVar14 = 1;
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar26 = pWVar12->y;
      pWVar12 = Path::currentWaypoint(pPVar2);
      iVar14 = PathingSystem::passable(&pathSystem,param_1,pWVar12->x,fVar26,iVar14);
      if (iVar14 == 0) {
        return 2;
      }
      iVar14 = param_1->_padding_;
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar26 = pWVar12->z;
      pWVar12 = Path::currentWaypoint(pPVar2);
      fVar17 = pWVar12->y;
      pWVar12 = Path::currentWaypoint(pPVar2);
      (**(code **)(iVar14 + 0x34))(pWVar12->x,fVar17,fVar26);
      goto LAB_0045f704;
    }
    fVar17 = param_1->velocity_z + (float)param_1->_padding_;
    iVar14 = param_1->_padding_;
  }
  (**(code **)(iVar14 + 0x34))(fVar26,fStack_20,fVar17);
LAB_0045f704:
  fVar17 = fStack_24 - (float)param_1->_padding_;
  uVar3 = param_1->lastFacet;
  fVar5 = (float)_DAT_00570be0;
  fVar26 = 1.0;
  param_1->lastFacet = *(uchar *)((int)&param_1->_padding_ + 1);
  param_1->lastFacet2 = uVar3;
  param_1->closestDistanceToWaypoint = fStack_28;
  if (fVar5 <= fVar17) {
    if (fVar17 <= (float)_DAT_00570bf0) {
      iVar14 = param_1->_padding_;
      if ((iVar14 == 0) || (*(float *)(iVar14 + 100) <= (float)_DAT_00570b98)) {
        param_1->_padding_ = *(int *)(param_1->_padding_ + 0xb8);
      }
      else {
        param_1->_padding_ = (int)(*(float *)(param_1->_padding_ + 0xb8) * *(float *)(iVar14 + 100))
        ;
      }
    }
    else {
      fVar26 = 1.03;
    }
  }
  else {
    fVar26 = 0.9;
  }
  if (param_1->_padding_ != 0) {
    fVar17 = RGE_Static_Object::get_terrain_speed
                       ((RGE_Static_Object *)param_1,*(byte *)(param_1->_padding_ + 5) & 0x1f);
    fVar26 = fVar17 * fVar26;
  }
  if (_DAT_00570b48 < fVar26) {
    param_1->_padding_ = (int)(fVar26 * (float)param_1->_padding_);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0045f7e8
// Address: 0045f7e8
// XREFS: None
void __thiscall FUN_0045f7e8(RGE_Moving_Object *param_1,float param_2,float param_3,int param_4)
{
  PathingSystem *this;
  
  this = &aiPathSystem;
  if (param_4 == 0) {
    this = &pathSystem;
  }
  PathingSystem::passable(this,param_1,param_2,param_3,1);
  return;
}

// --------------------------------------------------

// Function: FUN_0045f817
// Address: 0045f817
// XREFS: None
int __thiscall
FUN_0045f817(RGE_Moving_Object *param_1,int param_2,int param_3,undefined4 param_4,float param_5,
            int param_6,float *param_7,int param_8,int param_9,int param_10)
{
  XYPoint XVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Zone_Map *this;
  long lVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  if ((-1 < param_2) && (-1 < param_3)) {
    iVar7 = *(int *)(param_1->_padding_ + 0x3c);
    iVar8 = *(int *)(iVar7 + 0x28);
    if ((param_2 < *(int *)(iVar8 + 8)) && (param_3 < *(int *)(iVar8 + 0xc))) {
      if (param_1->_padding_ == -1) {
        RGE_Zone_Map_List::get_zone_map
                  (*(RGE_Zone_Map_List **)(iVar8 + 0x8dc4),
                   *(float **)(*(int *)(iVar7 + 0x54) + *(short *)(param_1->_padding_ + 0x66) * 4),
                   (int)*(short *)(iVar7 + 0x52),&param_1->_padding_);
      }
      this = RGE_Zone_Map_List::get_zone_map
                       (*(RGE_Zone_Map_List **)
                         (*(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0x28) + 0x8dc4),
                        param_1->_padding_);
      if (this != (RGE_Zone_Map *)0x0) {
        lVar5 = __ftol();
        lVar6 = __ftol();
        uVar3 = RGE_Zone_Map::get_zone_info(this,lVar6,lVar5);
        uVar4 = RGE_Zone_Map::get_zone_info(this,param_2,param_3);
        if (uVar4 != uVar3) {
          iVar7 = __ftol();
          iVar8 = __ftol();
          XVar1.y = iVar8;
          XVar1.x = iVar7;
          XVar2.y = param_3;
          XVar2.x = param_2;
          iVar7 = RGE_Zone_Map::withinRange(this,XVar1,XVar2,param_5);
          if (iVar7 == 0) {
            return 0;
          }
        }
        if (param_8 == 0) {
          PathingSystem::incrementCanPaths(&pathSystem);
          iVar13 = 1;
          iVar12 = 1;
          iVar11 = 1;
          iVar10 = 1;
          iVar9 = 0;
          iVar7 = __ftol();
          iVar8 = __ftol();
          iVar7 = PathingSystem::findTilePath
                            (&pathSystem,iVar8,iVar7,param_2,param_3,param_1,param_5,param_6,iVar9,
                             param_7,iVar10,iVar11,iVar12,iVar13,param_9,param_10);
          return iVar7;
        }
        PathingSystem::incrementCanPaths(&aiPathSystem);
        iVar13 = 1;
        iVar12 = 1;
        iVar11 = 1;
        iVar10 = 1;
        iVar9 = 0;
        iVar7 = __ftol();
        iVar8 = __ftol();
        iVar7 = PathingSystem::findTilePath
                          (&aiPathSystem,iVar8,iVar7,param_2,param_3,param_1,param_5,param_6,iVar9,
                           param_7,iVar10,iVar11,iVar12,iVar13,param_9,param_10);
        return iVar7;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0045f9c3
// Address: 0045f9c3
// XREFS: None
void __thiscall
FUN_0045f9c3(RGE_Moving_Object *param_1,int param_2,float param_3,float *param_4,int param_5,
            int param_6,int param_7)
{
  XYPoint XVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *pRVar5;
  RGE_Zone_Map *this;
  long lVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  pRVar5 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  if (pRVar5 == (RGE_Static_Object *)0x0) {
    return;
  }
  if (param_1->_padding_ == -1) {
    iVar8 = *(int *)(param_1->_padding_ + 0x3c);
    RGE_Zone_Map_List::get_zone_map
              (*(RGE_Zone_Map_List **)(*(int *)(iVar8 + 0x28) + 0x8dc4),
               *(float **)(*(int *)(iVar8 + 0x54) + *(short *)(param_1->_padding_ + 0x66) * 4),
               (int)*(short *)(iVar8 + 0x52),&param_1->_padding_);
  }
  this = RGE_Zone_Map_List::get_zone_map
                   (*(RGE_Zone_Map_List **)
                     (*(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0x28) + 0x8dc4),
                    param_1->_padding_);
  if (this == (RGE_Zone_Map *)0x0) {
    return;
  }
  lVar6 = __ftol();
  lVar7 = __ftol();
  uVar3 = RGE_Zone_Map::get_zone_info(this,lVar7,lVar6);
  lVar6 = __ftol();
  lVar7 = __ftol();
  uVar4 = RGE_Zone_Map::get_zone_info(this,lVar7,lVar6);
  if (uVar4 != uVar3) {
    iVar8 = __ftol();
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    XVar1.y = iVar9;
    XVar1.x = iVar8;
    XVar2.y = iVar11;
    XVar2.x = iVar10;
    iVar8 = RGE_Zone_Map::withinRange(this,XVar1,XVar2,param_3);
    if (iVar8 == 0) {
      return;
    }
  }
  if (param_5 != 0) {
    PathingSystem::incrementCanPaths(&aiPathSystem);
    iVar16 = 1;
    iVar15 = 1;
    iVar14 = 1;
    iVar13 = 1;
    iVar12 = 0;
    iVar8 = __ftol();
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    PathingSystem::findTilePath
              (&aiPathSystem,iVar11,iVar10,iVar9,iVar8,param_1,param_3,param_2,iVar12,param_4,iVar13
               ,iVar14,iVar15,iVar16,param_6,param_7);
    return;
  }
  PathingSystem::incrementCanPaths(&pathSystem);
  iVar16 = 1;
  iVar15 = 1;
  iVar14 = 1;
  iVar13 = 1;
  iVar12 = 0;
  iVar8 = __ftol();
  iVar9 = __ftol();
  iVar10 = __ftol();
  iVar11 = __ftol();
  PathingSystem::findTilePath
            (&pathSystem,iVar11,iVar10,iVar9,iVar8,param_1,param_3,param_2,iVar12,param_4,iVar13,
             iVar14,iVar15,iVar16,param_6,param_7);
  return;
}

// --------------------------------------------------

// Function: FUN_0045fbb7
// Address: 0045fbb7
// XREFS: None
int __thiscall
FUN_0045fbb7(RGE_Moving_Object *param_1,int param_2,int param_3,float param_4,float *param_5,
            int param_6,int param_7,int param_8)
{
  XYPoint XVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *pRVar5;
  RGE_Static_Object *pRVar6;
  RGE_Zone_Map *this;
  long lVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  RGE_Moving_Object *pRVar15;
  float fVar16;
  int iVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  
  pRVar5 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  pRVar6 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_3);
  if ((pRVar5 != (RGE_Static_Object *)0x0) && (pRVar6 != (RGE_Static_Object *)0x0)) {
    if (param_1->_padding_ == -1) {
      iVar9 = *(int *)(param_1->_padding_ + 0x3c);
      RGE_Zone_Map_List::get_zone_map
                (*(RGE_Zone_Map_List **)(*(int *)(iVar9 + 0x28) + 0x8dc4),
                 *(float **)(*(int *)(iVar9 + 0x54) + *(short *)(param_1->_padding_ + 0x66) * 4),
                 (int)*(short *)(iVar9 + 0x52),&param_1->_padding_);
    }
    this = RGE_Zone_Map_List::get_zone_map
                     (*(RGE_Zone_Map_List **)
                       (*(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0x28) + 0x8dc4),
                      param_1->_padding_);
    if (this != (RGE_Zone_Map *)0x0) {
      lVar7 = __ftol();
      lVar8 = __ftol();
      uVar3 = RGE_Zone_Map::get_zone_info(this,lVar8,lVar7);
      lVar7 = __ftol();
      lVar8 = __ftol();
      uVar4 = RGE_Zone_Map::get_zone_info(this,lVar8,lVar7);
      if (uVar4 != uVar3) {
        iVar9 = __ftol();
        iVar10 = __ftol();
        iVar11 = __ftol();
        iVar12 = __ftol();
        XVar1.y = iVar10;
        XVar1.x = iVar9;
        XVar2.y = iVar12;
        XVar2.x = iVar11;
        iVar9 = RGE_Zone_Map::withinRange(this,XVar1,XVar2,param_4);
        if (iVar9 == 0) {
          return 0;
        }
      }
      param_1->storePathInExceptionPath = '\x01';
      if (param_6 != 0) {
        PathingSystem::incrementCanPaths(&aiPathSystem);
        iVar22 = 1;
        iVar21 = 1;
        iVar20 = 1;
        iVar19 = 1;
        iVar17 = 1;
        pRVar15 = param_1;
        fVar16 = param_4;
        pfVar18 = param_5;
        iVar9 = param_7;
        iVar10 = param_8;
        iVar11 = __ftol();
        iVar12 = __ftol();
        iVar13 = __ftol();
        iVar14 = __ftol();
        iVar9 = PathingSystem::findTilePath
                          (&aiPathSystem,iVar14,iVar13,iVar12,iVar11,pRVar15,fVar16,param_2,iVar17,
                           pfVar18,iVar19,iVar20,iVar21,iVar22,iVar9,iVar10);
        if (iVar9 != 0) {
          iVar20 = 1;
          iVar19 = 1;
          iVar17 = 1;
          iVar14 = 1;
          iVar13 = 0;
          pRVar15 = param_1;
          iVar9 = __ftol();
          iVar10 = __ftol();
          Path::lastWaypoint(&param_1->exceptionPathValue);
          iVar11 = __ftol();
          Path::lastWaypoint(&param_1->exceptionPathValue);
          iVar12 = __ftol();
          iVar9 = PathingSystem::findTilePath
                            (&aiPathSystem,iVar12,iVar11,iVar10,iVar9,pRVar15,param_4,param_3,iVar13
                             ,param_5,iVar14,iVar17,iVar19,iVar20,param_7,param_8);
          param_1->storePathInExceptionPath = '\0';
          return iVar9;
        }
        param_1->storePathInExceptionPath = '\0';
        return 0;
      }
      PathingSystem::incrementCanPaths(&pathSystem);
      iVar22 = 1;
      iVar21 = 1;
      iVar20 = 1;
      iVar19 = 1;
      iVar17 = 1;
      pRVar15 = param_1;
      fVar16 = param_4;
      pfVar18 = param_5;
      iVar9 = param_7;
      iVar10 = param_8;
      iVar11 = __ftol();
      iVar12 = __ftol();
      iVar13 = __ftol();
      iVar14 = __ftol();
      iVar9 = PathingSystem::findTilePath
                        (&pathSystem,iVar14,iVar13,iVar12,iVar11,pRVar15,fVar16,param_2,iVar17,
                         pfVar18,iVar19,iVar20,iVar21,iVar22,iVar9,iVar10);
      if (iVar9 != 0) {
        iVar20 = 1;
        iVar19 = 1;
        iVar17 = 1;
        iVar14 = 1;
        iVar13 = 0;
        pRVar15 = param_1;
        iVar9 = __ftol();
        iVar10 = __ftol();
        Path::lastWaypoint(&param_1->exceptionPathValue);
        iVar11 = __ftol();
        Path::lastWaypoint(&param_1->exceptionPathValue);
        iVar12 = __ftol();
        iVar9 = PathingSystem::findTilePath
                          (&pathSystem,iVar12,iVar11,iVar10,iVar9,pRVar15,param_4,param_3,iVar13,
                           param_5,iVar14,iVar17,iVar19,iVar20,param_7,param_8);
        param_1->storePathInExceptionPath = '\0';
        return iVar9;
      }
      param_1->storePathInExceptionPath = '\0';
      return 0;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0045fecb
// Address: 0045fecb
// XREFS: None
int __thiscall
FUN_0045fecb(RGE_Moving_Object *param_1,int param_2,float param_3,float *param_4,int param_5,
            int param_6,int param_7,ManagedArray<int> *param_8)
{
  XYPoint XVar1;
  XYPoint XVar2;
  uchar uVar3;
  uchar uVar4;
  RGE_Static_Object *pRVar5;
  RGE_Zone_Map *this;
  long lVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  PathingSystem *this_00;
  RGE_Moving_Object *pRVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  pRVar5 = RGE_Game_World::object(*(RGE_Game_World **)(param_1->_padding_ + 0x3c),param_2);
  if (pRVar5 == (RGE_Static_Object *)0x0) {
    return 0;
  }
  if (param_1->_padding_ == -1) {
    iVar8 = *(int *)(param_1->_padding_ + 0x3c);
    RGE_Zone_Map_List::get_zone_map
              (*(RGE_Zone_Map_List **)(*(int *)(iVar8 + 0x28) + 0x8dc4),
               *(float **)(*(int *)(iVar8 + 0x54) + *(short *)(param_1->_padding_ + 0x66) * 4),
               (int)*(short *)(iVar8 + 0x52),&param_1->_padding_);
  }
  this = RGE_Zone_Map_List::get_zone_map
                   (*(RGE_Zone_Map_List **)
                     (*(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0x28) + 0x8dc4),
                    param_1->_padding_);
  if (this == (RGE_Zone_Map *)0x0) {
    return 0;
  }
  lVar6 = __ftol();
  lVar7 = __ftol();
  uVar3 = RGE_Zone_Map::get_zone_info(this,lVar7,lVar6);
  lVar6 = __ftol();
  lVar7 = __ftol();
  uVar4 = RGE_Zone_Map::get_zone_info(this,lVar7,lVar6);
  if (uVar4 != uVar3) {
    iVar8 = __ftol();
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    XVar1.y = iVar9;
    XVar1.x = iVar8;
    XVar2.y = iVar11;
    XVar2.x = iVar10;
    iVar8 = RGE_Zone_Map::withinRange(this,XVar1,XVar2,param_3);
    if (iVar8 == 0) {
      return 0;
    }
  }
  param_1->storePathInExceptionPath = '\x01';
  if (param_5 == 0) {
    PathingSystem::incrementCanPaths(&pathSystem);
    iVar18 = 1;
    iVar17 = 1;
    iVar16 = 1;
    iVar15 = 1;
    iVar14 = 1;
    pRVar13 = param_1;
    iVar8 = param_7;
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    iVar12 = __ftol();
    iVar8 = PathingSystem::findTilePath
                      (&pathSystem,iVar12,iVar11,iVar10,iVar9,pRVar13,param_3,param_2,iVar14,param_4
                       ,iVar15,iVar16,iVar17,iVar18,param_6,iVar8);
    if (param_7 == -1) goto LAB_004600d3;
    this_00 = &pathSystem;
  }
  else {
    PathingSystem::incrementCanPaths(&aiPathSystem);
    iVar18 = 1;
    iVar17 = 1;
    iVar16 = 1;
    iVar15 = 1;
    iVar14 = 1;
    pRVar13 = param_1;
    iVar8 = param_7;
    iVar9 = __ftol();
    iVar10 = __ftol();
    iVar11 = __ftol();
    iVar12 = __ftol();
    iVar8 = PathingSystem::findTilePath
                      (&aiPathSystem,iVar12,iVar11,iVar10,iVar9,pRVar13,param_3,param_2,iVar14,
                       param_4,iVar15,iVar16,iVar17,iVar18,param_6,iVar8);
    if (param_7 == -1) goto LAB_004600d3;
    this_00 = &aiPathSystem;
  }
  PathingSystem::copyUnobstructibles(this_00,param_8);
LAB_004600d3:
  param_1->storePathInExceptionPath = '\0';
  return iVar8;
}

// --------------------------------------------------

// Function: FUN_004600e6
// Address: 004600e6
// XREFS: None
int __thiscall
FUN_004600e6(RGE_Moving_Object *param_1,int param_2,int param_3,undefined4 param_4,float param_5,
            int param_6,float *param_7,int param_8,int param_9,int param_10,int param_11,
            int param_12)
{
  int iVar1;
  int iVar2;
  PathingSystem *this;
  RGE_Moving_Object *pRVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((((-1 < param_2) && (-1 < param_3)) &&
      (iVar1 = *(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0x28), param_2 < *(int *)(iVar1 + 8)))
     && (param_3 < *(int *)(iVar1 + 0xc))) {
    param_1->currentTerrainException2 = param_9;
    param_1->currentTerrainException1 = param_8;
    param_1->storePathInExceptionPath = '\x01';
    pRVar3 = param_1;
    if (param_10 == 0) {
      PathingSystem::incrementCanPaths(&pathSystem);
      iVar8 = 1;
      iVar7 = 1;
      iVar6 = 1;
      iVar5 = 1;
      iVar4 = 1;
      iVar1 = __ftol();
      iVar2 = __ftol();
      this = &pathSystem;
    }
    else {
      PathingSystem::incrementCanPaths(&aiPathSystem);
      iVar8 = 1;
      iVar7 = 1;
      iVar6 = 1;
      iVar5 = 1;
      iVar4 = 1;
      iVar1 = __ftol();
      iVar2 = __ftol();
      this = &aiPathSystem;
    }
    iVar1 = PathingSystem::findTilePath
                      (this,iVar2,iVar1,param_2,param_3,pRVar3,param_5,param_6,iVar4,param_7,iVar5,
                       iVar6,iVar7,iVar8,param_11,param_12);
    param_1->storePathInExceptionPath = '\0';
    param_1->currentTerrainException1 = -1;
    param_1->currentTerrainException2 = -1;
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00460204
// Address: 00460204
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00460204(int *param_1,undefined4 param_2,float *param_3,float *param_4)
{
  Path *this;
  code *pcVar1;
  float fVar2;
  int iVar3;
  Waypoint *pWVar4;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int aiStack_8 [2];
  
  this = (Path *)(param_1 + 0x36);
  iVar3 = Path::numberOfWaypoints(this);
  if (1 < iVar3) {
    Path::initToStart(this);
    pWVar4 = Path::currentWaypoint(this);
    if (pWVar4 != (Waypoint *)0x0) {
      Path::currentWaypoint(this);
      uStack_18 = __ftol();
      Path::currentWaypoint(this);
      uStack_14 = __ftol();
      Path::moveToNextWaypoint(this);
      pWVar4 = Path::currentWaypoint(this);
      if (pWVar4 != (Waypoint *)0x0) {
        Path::currentWaypoint(this);
        uStack_10 = __ftol();
        Path::currentWaypoint(this);
        uStack_c = __ftol();
        iStack_1c = 1;
        iVar3 = Path::numberOfWaypoints(this);
        if (1 < iVar3) {
          pcVar1 = *(code **)(*param_1 + 0x1b4);
          do {
            iVar3 = (*pcVar1)(&uStack_18,&uStack_10,aiStack_8,param_2,param_2,1);
            if (iVar3 == 1) {
              fVar2 = (float)aiStack_8[0] - _DAT_00570b80;
              *param_3 = fVar2;
              *param_4 = fVar2;
              return 1;
            }
            Path::currentWaypoint(this);
            uStack_18 = __ftol();
            Path::currentWaypoint(this);
            uStack_14 = __ftol();
            Path::moveToNextWaypoint(this);
            pWVar4 = Path::currentWaypoint(this);
            if (pWVar4 == (Waypoint *)0x0) {
              return 0;
            }
            Path::currentWaypoint(this);
            uStack_10 = __ftol();
            Path::currentWaypoint(this);
            uStack_c = __ftol();
            iStack_1c = iStack_1c + 1;
            iVar3 = Path::numberOfWaypoints(this);
          } while (iStack_1c < iVar3);
        }
        *param_3 = -1.0;
        *param_4 = -1.0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004603a6
// Address: 004603a6
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004603a6(int *param_1,int *param_2,int *param_3,float param_4,int *param_5,undefined4 param_6)
{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar8;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar9;
  float fStack_1c;
  int iStack_14;
  int iStack_c;
  
  iVar5 = *param_2;
  iVar6 = param_2[1];
  fVar1 = (float)(*param_3 - iVar5);
  fVar2 = (float)(param_3[1] - iVar6);
  if ((fVar1 == _DAT_00570b48) && (fVar2 == _DAT_00570b48)) {
    return 0;
  }
  if (ABS(fVar2) <= ABS(fVar1)) {
    uVar3 = __ftol();
    iVar4 = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
    fVar8 = extraout_ST0_00;
    fVar9 = extraout_ST1_00;
  }
  else {
    uVar3 = __ftol();
    iVar4 = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
    fVar8 = extraout_ST0;
    fVar9 = extraout_ST1;
  }
  iVar4 = iVar4 * 2;
  iVar7 = -999;
  iStack_c = 0;
  iStack_14 = -999;
  param_2 = (int *)(float)iVar5;
  fStack_1c = (float)iVar6;
  if (iVar4 < 1) {
    return 1;
  }
  do {
    param_2 = (int *)((float)param_2 + (float)(fVar9 / (float10)iVar4));
    fStack_1c = fStack_1c + (float)(fVar8 / (float10)iVar4);
    iVar5 = __ftol();
    iVar6 = __ftol();
    if ((iVar5 != iVar7) || (iVar6 != iStack_14)) {
      iVar7 = (**(code **)(*param_1 + 0x114))(param_2,fStack_1c,param_6);
      if (iVar7 == 0) {
        *param_5 = iVar5;
        param_5[1] = iVar6;
        return 0;
      }
      iVar7 = iVar5;
      iStack_14 = iVar6;
      if (SQRT(((float)param_3[1] - fStack_1c) * ((float)param_3[1] - fStack_1c) +
               ((float)*param_3 - (float)param_2) * ((float)*param_3 - (float)param_2)) <= param_4)
{
        return 1;
      }
    }
    iStack_c = iStack_c + 1;
    if (iVar4 <= iStack_c) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0046056a
// Address: 0046056a
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0046056a(int *param_1,float param_2,float param_3,int param_4,int param_5,float param_6,
            undefined4 param_7)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar7;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar8;
  int iStack_c;
  
  if (((float)(param_4 - (int)param_2) == _DAT_00570b48) &&
     ((float)(param_5 - (int)param_3) == _DAT_00570b48)) {
    return 0;
  }
  if (ABS((float)(param_5 - (int)param_3)) <= ABS((float)(param_4 - (int)param_2))) {
    uVar1 = __ftol();
    iVar2 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
    fVar7 = extraout_ST0_00;
    fVar8 = extraout_ST1_00;
  }
  else {
    uVar1 = __ftol();
    iVar2 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
    fVar7 = extraout_ST0;
    fVar8 = extraout_ST1;
  }
  iVar2 = iVar2 * 2;
  iVar6 = -999;
  iStack_c = 0;
  iVar5 = -999;
  param_2 = (float)(int)param_2;
  param_3 = (float)(int)param_3;
  if (iVar2 < 1) {
    return 1;
  }
  do {
    param_2 = param_2 + (float)(fVar8 / (float10)iVar2);
    param_3 = param_3 + (float)(fVar7 / (float10)iVar2);
    iVar3 = __ftol();
    iVar4 = __ftol();
    if ((iVar3 != iVar6) || (iVar4 != iVar5)) {
      iVar5 = (**(code **)(*param_1 + 0x114))(param_2,param_3,param_7);
      if (iVar5 == 0) {
        return 0;
      }
      iVar5 = iVar4;
      iVar6 = iVar3;
      if (SQRT(((float)param_5 - param_3) * ((float)param_5 - param_3) +
               ((float)param_4 - param_2) * ((float)param_4 - param_2)) <= param_6) {
        return 1;
      }
    }
    iStack_c = iStack_c + 1;
    if (iVar2 <= iStack_c) {
      return 1;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0046070e
// Address: 0046070e
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0046070e(int *param_1,int *param_2,int *param_3,int *param_4,uint param_5,uint param_6,
            int param_7)
{
  RGE_Map *this;
  float fVar1;
  float fVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar11;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar12;
  int iStack_18;
  
  iVar6 = *param_2;
  iVar7 = param_2[1];
  fVar1 = (float)(*param_3 - iVar6);
  fVar2 = (float)(param_3[1] - iVar7);
  if ((fVar1 == _DAT_00570b48) && (fVar2 == _DAT_00570b48)) {
    return 0;
  }
  if (ABS(fVar2) <= ABS(fVar1)) {
    uVar4 = __ftol();
    iVar5 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
    fVar11 = extraout_ST0_00;
    fVar12 = extraout_ST1_00;
  }
  else {
    uVar4 = __ftol();
    iVar5 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
    fVar11 = extraout_ST0;
    fVar12 = extraout_ST1;
  }
  iVar5 = iVar5 * 2;
  iVar9 = -999;
  iVar10 = -999;
  iStack_18 = 0;
  this = *(RGE_Map **)(*(int *)(param_1[3] + 0x3c) + 0x28);
  param_3 = (int *)(float)iVar6;
  param_2 = (int *)(float)iVar7;
  if (0 < iVar5) {
    do {
      param_3 = (int *)((float)param_3 + (float)(fVar12 / (float10)iVar5));
      param_2 = (int *)((float)param_2 + (float)(fVar11 / (float10)iVar5));
      iVar6 = __ftol();
      iVar7 = __ftol();
      if ((iVar6 != iVar9) || (iVar7 != iVar10)) {
        bVar3 = RGE_Map::get_terrain(this,(short)iVar6,(short)iVar7);
        iVar9 = iVar6;
        iVar10 = iVar7;
        if (((bVar3 == param_5) || (bVar3 == param_6)) && (param_7 == 1)) {
          iVar8 = (**(code **)(*param_1 + 0x114))(param_3,param_2,0);
          if (iVar8 == 1) {
            *param_4 = iVar6;
            param_4[1] = iVar7;
            return 1;
          }
        }
      }
      iStack_18 = iStack_18 + 1;
    } while (iStack_18 < iVar5);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_004608c9
// Address: 004608c9
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004608c9(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if ((iVar1 != 0) && ((float)_DAT_00570b98 < *(float *)(iVar1 + 100))) {
    return (float10)*(float *)(*(int *)(param_1 + 8) + 0xb8) * (float10)*(float *)(iVar1 + 100);
  }
  return (float10)*(float *)(*(int *)(param_1 + 8) + 0xb8);
}

// --------------------------------------------------

// Function: FUN_004608fe
// Address: 004608fe
// XREFS: None
undefined1 __fastcall FUN_004608fe(int *param_1)
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x134))();
  if ((cVar1 != '\x06') && (cVar1 != '\a')) {
    return *(undefined1 *)((int)param_1 + 0x155);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00460926
// Address: 00460926
// XREFS: None
void __thiscall FUN_00460926(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x155) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_0046093d
// Address: 0046093d
// XREFS: None
int __thiscall FUN_0046093d(int param_1,int param_2)
{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x16c))) {
    return *(int *)(param_1 + 0x168) + param_2 * 3;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00460963
// Address: 00460963
// XREFS: None
undefined4 __thiscall FUN_00460963(int *param_1,undefined1 *param_2,undefined4 param_3)
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  if ((char)param_1[0x5d] == '\x01') {
    (**(code **)(*param_1 + 0x1c0))(param_3);
    *(undefined1 *)(param_1 + 0x5d) = 0;
  }
  iVar2 = param_1[0x5c];
  if (param_1[0x5b] < iVar2) {
    *(undefined1 *)(param_1[0x5b] * 3 + param_1[0x5a]) = *param_2;
    *(undefined1 *)(param_1[0x5b] * 3 + 1 + param_1[0x5a]) = param_2[1];
    *(undefined1 *)(param_1[0x5b] * 3 + 2 + param_1[0x5a]) = param_2[2];
  }
  else {
    if (iVar2 == 0) {
      pvVar1 = operator_new(0xf);
      param_1[0x5a] = (int)pvVar1;
      param_1[0x5c] = 5;
      param_1[0x5b] = 0;
    }
    else {
      pvVar1 = operator_new(iVar2 * 6);
      if (pvVar1 == (void *)0x0) {
        return 0;
      }
      iVar2 = 0;
      if (0 < param_1[0x5b]) {
        iVar3 = 0;
        puVar4 = (undefined1 *)((int)pvVar1 + 2);
        do {
          iVar2 = iVar2 + 1;
          puVar4[-2] = *(undefined1 *)(iVar3 + param_1[0x5a]);
          puVar4[-1] = *(undefined1 *)(iVar3 + 1 + param_1[0x5a]);
          *puVar4 = *(undefined1 *)(iVar3 + 2 + param_1[0x5a]);
          iVar3 = iVar3 + 3;
          puVar4 = puVar4 + 3;
        } while (iVar2 < param_1[0x5b]);
      }
      iVar3 = param_1[0x5c];
      param_1[0x5c] = iVar3 * 2;
      if (iVar2 < iVar3 * 2) {
        puVar4 = (undefined1 *)(iVar2 * 3 + 2 + (int)pvVar1);
        do {
          puVar4[-2] = 0;
          puVar4[-1] = 0;
          *puVar4 = 0;
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 3;
        } while (iVar2 < param_1[0x5c]);
      }
      operator_delete((void *)param_1[0x5a]);
      param_1[0x5a] = (int)pvVar1;
    }
    *(undefined1 *)(param_1[0x5b] * 3 + param_1[0x5a]) = *param_2;
    *(undefined1 *)(param_1[0x5b] * 3 + 1 + param_1[0x5a]) = param_2[1];
    *(undefined1 *)(param_1[0x5b] * 3 + 2 + param_1[0x5a]) = param_2[2];
  }
  param_1[0x5b] = param_1[0x5b] + 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00460b19
// Address: 00460b19
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_move_obj_c: "C:\msdev\work\age1_x1\move_obj.cpp"
// [HELPER] s___d_call_stopObject__s__d_: "#%d call stopObject %s %d\n"
void __thiscall FUN_00460b19(int param_1,int param_2)
{
  *(undefined4 *)(param_1 + 0x16c) = 0;
  if ((param_2 == 1) && (*(int *)(param_1 + 0x74) != 0)) {
    if (actionFile != (_iobuf *)0x0) {
      fprintf(actionFile,s___d_call_stopObject__s__d_,*(undefined4 *)(param_1 + 4),
              s_C__msdev_work_age1_x1_move_obj_c,0xb59);
    }
    (**(code **)(**(int **)(param_1 + 0x74) + 0x58))(0);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00460bed
// Address: 00460bed
// XREFS: None
void __fastcall FUN_00460bed(int param_1)
{
  *(undefined1 *)(param_1 + 0x174) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_00460bf8
// Address: 00460bf8
// XREFS: None
Path * __thiscall
FUN_00460bf8(RGE_Moving_Object *param_1,XYPoint *param_2,float param_3,int param_4)
{
  XYPoint XVar1;
  uchar uVar2;
  uchar uVar3;
  RGE_Zone_Map *this;
  long lVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  RGE_Moving_Object *pRVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  if (param_1->_padding_ == -1) {
    iVar6 = *(int *)(param_1->_padding_ + 0x3c);
    RGE_Zone_Map_List::get_zone_map
              (*(RGE_Zone_Map_List **)(*(int *)(iVar6 + 0x28) + 0x8dc4),
               *(float **)(*(int *)(iVar6 + 0x54) + *(short *)(param_1->_padding_ + 0x66) * 4),
               (int)*(short *)(iVar6 + 0x52),&param_1->_padding_);
  }
  this = RGE_Zone_Map_List::get_zone_map
                   (*(RGE_Zone_Map_List **)
                     (*(int *)(*(int *)(param_1->_padding_ + 0x3c) + 0x28) + 0x8dc4),
                    param_1->_padding_);
  lVar4 = __ftol();
  lVar5 = __ftol();
  uVar2 = RGE_Zone_Map::get_zone_info(this,lVar5,lVar4);
  uVar3 = RGE_Zone_Map::get_zone_info(this,param_2->x,param_2->y);
  if (uVar3 != uVar2) {
    iVar6 = __ftol();
    iVar7 = __ftol();
    XVar1.y = iVar7;
    XVar1.x = iVar6;
    iVar6 = RGE_Zone_Map::withinRange(this,XVar1,*param_2,param_3);
    if (iVar6 == 0) {
      return (Path *)0x0;
    }
  }
  iVar18 = -1;
  iVar17 = -1;
  iVar16 = 1;
  iVar15 = 1;
  iVar14 = 1;
  iVar13 = 0;
  pfVar12 = (float *)0x0;
  iVar11 = 1;
  param_1->storePathInExceptionPath = '\x01';
  iVar6 = param_2->y;
  iVar7 = param_2->x;
  pRVar10 = param_1;
  iVar8 = __ftol();
  iVar9 = __ftol();
  PathingSystem::findTilePath
            (&aiPathSystem,iVar9,iVar8,iVar7,iVar6,pRVar10,param_3,param_4,iVar11,pfVar12,iVar13,
             iVar14,iVar15,iVar16,iVar17,iVar18);
  param_1->storePathInExceptionPath = '\0';
  PathingSystem::initMisc(&aiPathSystem,'\0');
  return &param_1->exceptionPathValue;
}

// --------------------------------------------------

// Function: FUN_00460d24
// Address: 00460d24
// XREFS: None
void __thiscall FUN_00460d24(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  *(undefined4 *)(param_1 + 0x158) = *param_2;
  *(undefined4 *)(param_1 + 0x15c) = param_2[1];
  *(undefined4 *)(param_1 + 0x160) = *param_3;
  *(undefined4 *)(param_1 + 0x164) = param_3[1];
  return;
}

// --------------------------------------------------

// Function: FUN_00460d5d
// Address: 00460d5d
// XREFS: None
void __thiscall FUN_00460d5d(RGE_Static_Object *param_1,RGE_Master_Static_Object *param_2)
{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if (param_1->sprite == *(RGE_Sprite **)&param_1->master_obj[1].master_type) {
    pcVar1 = *(char **)&param_2[1].master_type;
  }
  else if (param_1->sprite == (RGE_Sprite *)param_1->master_obj[1].name) {
    pcVar1 = param_2[1].name;
  }
  if (pcVar1 != (char *)0x0) {
    (**(code **)(param_1->_padding_ + 0x38))(pcVar1);
  }
  RGE_Static_Object::copy_obj(param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: FUN_00460da9
// Address: 00460da9
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00460da9(float *param_1,int param_2)
{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int iStack_4;
  
  iVar4 = param_2;
  pfVar3 = param_1;
  fVar1 = *param_1;
  if (_DAT_00570b48 <= *param_1) {
    if (_DAT_00570b50 < fVar1) {
      do {
        fVar2 = _DAT_00570b50;
        fVar1 = *param_1 - _DAT_00570b50;
        *param_1 = fVar1;
      } while (fVar2 < fVar1);
    }
  }
  else {
    do {
      fVar1 = fVar1 - _DAT_00570b4c;
    } while (fVar1 < _DAT_00570b48);
    *param_1 = fVar1;
  }
  if (param_2 != -1) {
    param_1 = (float *)0x3f490fdb;
    if (param_2 != 8) {
      param_1 = (float *)0x3ec90fdb;
    }
    param_2 = -1;
    iStack_4 = 0;
    if (-1 < iVar4) {
      do {
        fVar1 = *pfVar3 - (float)iStack_4 * (float)param_1;
        if (fVar1 < (float)_DAT_00570b98) {
          fVar1 = -fVar1;
        }
        if (fVar1 < (float)param_1) {
          param_1 = (float *)fVar1;
          param_2 = iStack_4;
        }
      } while (((float)_DAT_00570c00 <= (float)param_1) &&
              (iStack_4 = iStack_4 + 1, iStack_4 <= iVar4));
    }
    if (iVar4 == 8) {
      *pfVar3 = (float)param_2 * _DAT_00570b88;
      return;
    }
    *pfVar3 = (float)param_2 * _DAT_00570bfc;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00460ea3
// Address: 00460ea3
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00460ea3(int *param_1,int param_2)
{
  float fVar1;
  
  for (fVar1 = ((float)param_2 * (float)_DAT_00570b40) / (float)(int)*(short *)(param_1[4] + 0x60) +
               (float)param_1[0x27]; fVar1 < _DAT_00570b48; fVar1 = fVar1 - _DAT_00570b4c) {
  }
  if ((float)_DAT_00570b40 <= fVar1) {
    do {
      fVar1 = fVar1 - _DAT_00570b50;
    } while ((float)_DAT_00570b40 <= fVar1);
    (**(code **)(*param_1 + 0xb4))(fVar1);
    return;
  }
  (**(code **)(*param_1 + 0xb4))(fVar1);
  return;
}

// --------------------------------------------------

// Function: FUN_00460f3f
// Address: 00460f3f
// XREFS: None
void __fastcall FUN_00460f3f(int param_1)
{
  Path *this;
  int iVar1;
  int iVar2;
  int iVar3;
  
  this = (Path *)(param_1 + 0xa4);
  iVar1 = Path::currentWaypointNumber(this);
  Path::initToStart(this);
  iVar3 = 0;
  iVar2 = Path::numberOfWaypoints(this);
  if (0 < iVar2) {
    do {
      Path::currentWaypoint(this);
      Path::currentWaypoint(this);
      iVar3 = iVar3 + 1;
      Path::moveToNextWaypoint(this);
      iVar2 = Path::numberOfWaypoints(this);
    } while (iVar3 < iVar2);
  }
  Path::setCurrentWaypointNumber(this,iVar1);
  __ftol();
  return;
}

// --------------------------------------------------

// Function: FUN_00460fb7
// Address: 00460fb7
// XREFS: None
void __fastcall FUN_00460fb7(int *param_1)
{
                    /* WARNING: Could not recover jumptable at 0x00460fc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x1c8))();
  return;
}

// --------------------------------------------------

// Function: `vcall'{456,{flat}}'_}'
// Address: 00460fc0
// XREFS: findPath
/* [thunk]: __thiscall `vcall'{456,{flat}}' }' */

void __thiscall _vcall__456__flat______(void *this)
{
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Could not recover jumptable at 0x00460fc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*this + 0x1c8))();
  return;
}

// --------------------------------------------------

// Function: FUN_00461098
// Address: 00461098
// XREFS: None
RGE_Master_Player * __thiscall FUN_00461098(RGE_Master_Player *param_1,byte param_2)
{
  RGE_Master_Player::~RGE_Master_Player(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_004610be
// Address: 004610be
// XREFS: None
undefined4 * __thiscall FUN_004610be(undefined4 *param_1,int param_2)
{
  short *psVar1;
  void *pvVar2;
  
  *param_1 = &RGE_Master_Player::_vftable_;
  rge_read(param_2,param_1 + 1,0x14);
  psVar1 = (short *)(param_1 + 8);
  rge_read(param_2,psVar1,2);
  rge_read(param_2,(void *)((int)param_1 + 0x2a),2);
  if (*psVar1 < 1) {
    param_1[9] = 0;
  }
  else {
    pvVar2 = (void *)calloc((int)*psVar1,4);
    param_1[9] = pvVar2;
    rge_read(param_2,pvVar2,(int)*psVar1 << 2);
  }
  rge_read(param_2,param_1 + 10,1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00461146
// Address: 00461146
// XREFS: None
void __fastcall FUN_00461146(undefined4 *param_1)
{
  undefined4 *puVar1;
  short sVar2;
  
  *param_1 = &RGE_Master_Player::_vftable_;
  if ((0 < *(short *)(param_1 + 8)) && (param_1[9] != 0)) {
    free(param_1[9]);
    param_1[9] = 0;
    *(undefined2 *)(param_1 + 8) = 0;
  }
  if ((0 < *(short *)(param_1 + 6)) && (param_1[7] != 0)) {
    sVar2 = 0;
    if (0 < *(short *)(param_1 + 6)) {
      do {
        puVar1 = *(undefined4 **)(param_1[7] + sVar2 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
          *(undefined4 *)(param_1[7] + sVar2 * 4) = 0;
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 < *(short *)(param_1 + 6));
    }
    free(param_1[7]);
    param_1[7] = 0;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004611cb
// Address: 004611cb
// XREFS: None
void __thiscall FUN_004611cb(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  
  iVar2 = param_2;
  piVar1 = param_1 + 6;
  rge_read(param_2,piVar1,2);
  iVar4 = 0;
  if ((short)*piVar1 < 1) {
    param_1[7] = 0;
  }
  else {
    pvVar3 = (void *)calloc((int)(short)*piVar1,4);
    param_1[7] = (int)pvVar3;
    rge_read(iVar2,pvVar3,(int)(short)*piVar1 << 2);
    if (0 < (short)*piVar1) {
      do {
        if (*(int *)(param_1[7] + (short)iVar4 * 4) != 0) {
          rge_read(iVar2,&param_2,1);
          (**(code **)(*param_1 + 8))(iVar2,param_2,param_3,param_4,iVar4);
        }
        iVar4 = iVar4 + 1;
      } while ((short)iVar4 < (short)*piVar1);
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00461269
// Address: 00461269
// XREFS: None
void __thiscall
FUN_00461269(int param_1,int param_2,undefined1 param_3,RGE_Sprite **param_4,RGE_Sound **param_5,
            short param_6)
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
  pcStack_8 = FUN_0055dd5d;
  *unaff_FS_OFFSET = &uStack_c;
  switch(param_3) {
  case 10:
    this = (RGE_Master_Static_Object *)operator_new(0xb8);
    uStack_4 = 0;
    if (this == (RGE_Master_Static_Object *)0x0) {
LAB_004614ba:
      uVar1 = 0;
    }
    else {
      uVar1 = RGE_Master_Static_Object::RGE_Master_Static_Object(this,param_2,param_4,param_5,1);
    }
    break;
  default:
    goto switchD_004612a5_caseD_b;
  case 0x14:
    this_00 = (RGE_Master_Animated_Object *)operator_new(0xbc);
    uStack_4 = 1;
    if (this_00 != (RGE_Master_Animated_Object *)0x0) {
      uVar1 = RGE_Master_Animated_Object::RGE_Master_Animated_Object
                        (this_00,param_2,param_4,param_5,1);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    goto LAB_00461464;
  case 0x19:
    this_05 = (RGE_Master_Doppleganger_Object *)operator_new(0xbc);
    uStack_4 = 6;
    if (this_05 == (RGE_Master_Doppleganger_Object *)0x0) goto LAB_004614ba;
    uVar1 = RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object
                      (this_05,param_2,param_4,param_5,1);
    break;
  case 0x1e:
    this_01 = (RGE_Master_Moving_Object *)operator_new(0xd8);
    uStack_4 = 2;
    if (this_01 == (RGE_Master_Moving_Object *)0x0) goto LAB_004614ba;
    uVar1 = RGE_Master_Moving_Object::RGE_Master_Moving_Object(this_01,param_2,param_4,param_5,1);
    break;
  case 0x28:
    this_03 = (RGE_Master_Action_Object *)operator_new(0xfc);
    uStack_4 = 4;
    if (this_03 == (RGE_Master_Action_Object *)0x0) goto LAB_004614ba;
    uVar1 = RGE_Master_Action_Object::RGE_Master_Action_Object(this_03,param_2,param_4,param_5,1);
    break;
  case 0x32:
    this_04 = (RGE_Master_Combat_Object *)operator_new(0x148);
    uStack_4 = 5;
    if (this_04 != (RGE_Master_Combat_Object *)0x0) {
      uVar1 = RGE_Master_Combat_Object::RGE_Master_Combat_Object(this_04,param_2,param_4,param_5,1);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    goto LAB_00461464;
  case 0x3c:
    this_02 = (RGE_Master_Missile_Object *)operator_new(0x154);
    uStack_4 = 3;
    if (this_02 != (RGE_Master_Missile_Object *)0x0) {
      uVar1 = RGE_Master_Missile_Object::RGE_Master_Missile_Object
                        (this_02,param_2,param_4,param_5,1);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
LAB_00461464:
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = 0;
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = uVar1;
switchD_004612a5_caseD_b:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_004614d9
// Address: 004614d9
// XREFS: None
/* WARNING: Control flow encountered bad instruction data */

void FUN_004614d9(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_00461556
// Address: 00461556
// XREFS: None
void __thiscall
FUN_00461556(int param_1,_iobuf *param_2,undefined1 param_3,RGE_Sprite **param_4,RGE_Sound **param_5
            ,short param_6)
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
  pcStack_8 = FUN_0055ddbd;
  *unaff_FS_OFFSET = &uStack_c;
  switch(param_3) {
  case 10:
    this = (RGE_Master_Static_Object *)operator_new(0xb8);
    uStack_4 = 0;
    if (this == (RGE_Master_Static_Object *)0x0) {
LAB_004617ca:
      uVar1 = 0;
    }
    else {
      uVar1 = RGE_Master_Static_Object::RGE_Master_Static_Object
                        (this,param_2,param_4,param_5,param_6,1);
    }
    break;
  default:
    goto switchD_00461596_caseD_b;
  case 0x14:
    this_00 = (RGE_Master_Animated_Object *)operator_new(0xbc);
    uStack_4 = 1;
    if (this_00 != (RGE_Master_Animated_Object *)0x0) {
      uVar1 = RGE_Master_Animated_Object::RGE_Master_Animated_Object
                        (this_00,param_2,param_4,param_5,param_6,1);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    goto LAB_00461770;
  case 0x19:
    this_05 = (RGE_Master_Doppleganger_Object *)operator_new(0xbc);
    uStack_4 = 6;
    if (this_05 == (RGE_Master_Doppleganger_Object *)0x0) goto LAB_004617ca;
    uVar1 = RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object
                      (this_05,param_2,param_4,param_5,param_6,1);
    break;
  case 0x1e:
    this_01 = (RGE_Master_Moving_Object *)operator_new(0xd8);
    uStack_4 = 2;
    if (this_01 == (RGE_Master_Moving_Object *)0x0) goto LAB_004617ca;
    uVar1 = RGE_Master_Moving_Object::RGE_Master_Moving_Object
                      (this_01,param_2,param_4,param_5,param_6,1);
    break;
  case 0x28:
    this_03 = (RGE_Master_Action_Object *)operator_new(0xfc);
    uStack_4 = 4;
    if (this_03 == (RGE_Master_Action_Object *)0x0) goto LAB_004617ca;
    uVar1 = RGE_Master_Action_Object::RGE_Master_Action_Object
                      (this_03,param_2,param_4,param_5,param_6,1);
    break;
  case 0x32:
    this_04 = (RGE_Master_Combat_Object *)operator_new(0x148);
    uStack_4 = 5;
    if (this_04 != (RGE_Master_Combat_Object *)0x0) {
      uVar1 = RGE_Master_Combat_Object::RGE_Master_Combat_Object
                        (this_04,param_2,param_4,param_5,param_6,1);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    goto LAB_00461770;
  case 0x3c:
    this_02 = (RGE_Master_Missile_Object *)operator_new(0x154);
    uStack_4 = 3;
    if (this_02 != (RGE_Master_Missile_Object *)0x0) {
      uVar1 = RGE_Master_Missile_Object::RGE_Master_Missile_Object
                        (this_02,param_2,param_4,param_5,param_6,1);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = uVar1;
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
LAB_00461770:
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = 0;
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_6 * 4) = uVar1;
switchD_00461596_caseD_b:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00461906
// Address: 00461906
// XREFS: None
TMusic_System * __thiscall
FUN_00461906(TMusic_System *param_1,uchar param_2,void *param_3,void *param_4,TSound_Driver *param_5
            ,char *param_6)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  TMusic_System *pTVar5;
  
  param_1->music_type = param_2;
  param_1->sound_system = param_5;
  param_1->window = param_4;
  param_1->instance = param_3;
  param_1->device_open = 0;
  param_1->device_id = 0;
  param_1->playing_track = '\0';
  param_1->start_track = 0;
  param_1->end_track = 0;
  param_1->make_cur_track = 0;
  param_1->set_pos = 0;
  param_1->loop = 0;
  param_1->current_track = 0;
  param_1->track_count = 0;
  param_1->notify_waiting = 0;
  param_1->start_volume = 1;
  param_1->volume = 0;
  param_1->paused = 0;
  param_1->auto_paused = 0;
  param_1->inactivated = 0;
  param_1->fade_out = 0;
  param_1->fade_time = 2000;
  param_1->fading_track = 0;
  param_1->last_fade_time = 0;
  param_1->mixer_open = 0;
  param_1->mixer_handle = (void *)0x0;
  param_1->midi_window = (void *)0x0;
  param_1->file_name[0] = '\0';
  if (param_6 == (char *)0x0) {
    param_1->path[0] = '\0';
    TMusic_System::open_device(param_1);
    return param_1;
  }
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_6 + 1;
    cVar1 = *param_6;
    param_6 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pTVar5 = param_1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pTVar5->path = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pTVar5 = (TMusic_System *)(pTVar5->path + 4);
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    pTVar5->path[0] = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pTVar5 = (TMusic_System *)(pTVar5->path + 1);
  }
  TMusic_System::open_device(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00461a25
// Address: 00461a25
// XREFS: None
// [HELPER] s__smusic_d_mid: "%smusic%d.mid"
// [HELPER] s__smusic_d_wav: "%smusic%d.wav"
// [HELPER] s_r: "r"
undefined4 __fastcall FUN_00461a25(TMusic_System *param_1)
{
  uchar uVar1;
  int iVar2;
  undefined1 auStack_138 [4];
  int iStack_134;
  undefined4 uStack_130;
  undefined1 auStack_128 [4];
  undefined4 uStack_124;
  undefined1 auStack_11c [4];
  uint uStack_118;
  undefined4 uStack_114;
  undefined1 auStack_108 [264];
  
  uVar1 = param_1->music_type;
  if (uVar1 == '\x01') {
    uStack_114 = 0x204;
    iVar2 = mciSendCommandA(0,0x803,0x3102,auStack_11c);
    if (iVar2 == 0) {
      param_1->device_open = 1;
      param_1->device_id = uStack_118;
      uStack_124 = 10;
      mciSendCommandA(uStack_118,0x80d,0x402,auStack_128);
      uStack_130 = 3;
      iVar2 = mciSendCommandA(param_1->device_id,0x814,0x102,auStack_138);
      if (iVar2 == 0) {
        param_1->track_count = iStack_134;
      }
      iVar2 = TMusic_System::open_mixer(param_1);
      if (iVar2 != 0) {
        iVar2 = ((param_1->mixer_volume_value).dwValue * 10000) /
                (uint)((param_1->mixer_volume_control).Bounds._s_0.lMaximum -
                      (param_1->mixer_volume_control).Bounds._s_0.lMinimum) - 10000;
        param_1->start_volume = iVar2;
        param_1->volume = iVar2;
      }
      return 1;
    }
  }
  else {
    if (uVar1 == '\x02') {
      iVar2 = TMusic_System::open_mixer(param_1);
      if (iVar2 != 0) {
        iVar2 = ((param_1->mixer_volume_value).dwValue * 10000) /
                (uint)((param_1->mixer_volume_control).Bounds._s_0.lMaximum -
                      (param_1->mixer_volume_control).Bounds._s_0.lMinimum) - 10000;
        param_1->start_volume = iVar2;
        param_1->volume = iVar2;
      }
      param_1->track_count = 0;
      while( true ) {
        sprintf(auStack_108,s__smusic_d_mid,param_1,param_1->track_count + 1);
        iVar2 = fopen(auStack_108,s_r);
        if (iVar2 == 0) break;
        fclose(iVar2);
        param_1->track_count = param_1->track_count + 1;
      }
      param_1->device_open = 1;
      return 1;
    }
    if (uVar1 == '\x03') {
      param_1->track_count = 0;
      while( true ) {
        sprintf(auStack_108,s__smusic_d_wav,param_1,param_1->track_count + 1);
        iVar2 = fopen(auStack_108,s_r);
        if (iVar2 == 0) break;
        fclose(iVar2);
        param_1->track_count = param_1->track_count + 1;
      }
      param_1->volume = 0;
      param_1->device_open = 1;
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00461c57
// Address: 00461c57
// XREFS: None
void __fastcall FUN_00461c57(TMusic_System *param_1)
{
  uchar uVar1;
  
  if (param_1->device_open != 0) {
    TMusic_System::stop_track(param_1);
    uVar1 = param_1->music_type;
    if (uVar1 == '\x01') {
      if (param_1->start_volume != 1) {
        TMusic_System::set_volume(param_1,param_1->start_volume,0);
        param_1->start_volume = 1;
      }
      TMusic_System::close_mixer(param_1);
      mciSendCommandA(param_1->device_id,0x804,2,0);
      param_1->device_id = 0;
      param_1->device_open = 0;
      param_1->track_count = 0;
    }
    else {
      if (uVar1 == '\x02') {
        if (param_1->start_volume != 1) {
          TMusic_System::set_volume(param_1,param_1->start_volume,0);
          param_1->start_volume = 1;
        }
        TMusic_System::close_mixer(param_1);
        param_1->device_open = 0;
        param_1->track_count = 0;
        return;
      }
      if (uVar1 == '\x03') {
        param_1->track_count = 0;
        param_1->device_open = 0;
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00461d1e
// Address: 00461d1e
// XREFS: None
undefined4 __fastcall FUN_00461d1e(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint unaff_ESI;
  undefined4 *puVar6;
  
  uVar3 = mixerGetNumDevs();
  if ((uVar3 == 0) || (uVar5 = 0, uVar3 == 0)) {
    return 0;
  }
  puVar1 = (undefined4 *)(param_1 + 0x27c);
  do {
    iVar4 = mixerOpen(puVar1,uVar5,0,0,0);
    if (iVar4 == 0) {
      puVar2 = (undefined4 *)(param_1 + 0x280);
      puVar6 = puVar2;
      for (iVar4 = 0x2a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *puVar2 = 0xa8;
      if (*(char *)(param_1 + 0x104) == '\x01') {
        *(undefined4 *)(param_1 + 0x298) = 0x1005;
      }
      else {
        *(undefined4 *)(param_1 + 0x298) = 0x1004;
      }
      iVar4 = mixerGetLineInfoA(*puVar1,puVar2,3);
      if (iVar4 == 0) {
        puVar2 = (undefined4 *)(param_1 + 0x328);
        puVar6 = puVar2;
        for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        puVar6 = (undefined4 *)(param_1 + 0x340);
        for (iVar4 = 0x25; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        *puVar2 = 0x18;
        *(undefined4 *)(param_1 + 0x32c) = *(undefined4 *)(param_1 + 0x28c);
        *(undefined4 *)(param_1 + 0x330) = 0x50030001;
        *(undefined4 *)(param_1 + 0x334) = 1;
        *(undefined4 *)(param_1 + 0x338) = 0x94;
        *(undefined4 **)(param_1 + 0x33c) = (undefined4 *)(param_1 + 0x340);
        iVar4 = mixerGetLineControlsA(*puVar1,puVar2,2);
        uVar5 = unaff_ESI;
        if (iVar4 == 0) {
          puVar2 = (undefined4 *)(param_1 + 0x3d4);
          puVar6 = puVar2;
          for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          *(undefined4 *)(param_1 + 0x3ec) = 0;
          *puVar2 = 0x18;
          *(undefined4 *)(param_1 + 0x3d8) = *(undefined4 *)(param_1 + 0x344);
          *(undefined4 *)(param_1 + 0x3dc) = 1;
          *(undefined4 *)(param_1 + 0x3e4) = 4;
          *(undefined4 **)(param_1 + 1000) = (undefined4 *)(param_1 + 0x3ec);
          iVar4 = mixerGetControlDetailsA(*puVar1,puVar2,0);
          if (iVar4 == 0) {
            *(undefined4 *)(param_1 + 0x278) = 1;
            return 1;
          }
        }
      }
      mixerClose(*puVar1);
      *puVar1 = 0;
    }
    uVar5 = uVar5 + 1;
    if (uVar3 <= uVar5) {
      return 0;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00461eb6
// Address: 00461eb6
// XREFS: None
void __fastcall FUN_00461eb6(int param_1)
{
  if (*(int *)(param_1 + 0x278) != 0) {
    if (*(int *)(param_1 + 0x27c) != 0) {
      mixerClose(*(int *)(param_1 + 0x27c));
      *(undefined4 *)(param_1 + 0x27c) = 0;
    }
    *(undefined4 *)(param_1 + 0x278) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00461ef4
// Address: 00461ef4
// XREFS: None
int __thiscall FUN_00461ef4(TMusic_System *param_1,uchar param_2)
{
  int iVar1;
  
  if (param_2 == param_1->music_type) {
    return param_1->device_open;
  }
  TMusic_System::close_device(param_1);
  param_1->music_type = param_2;
  iVar1 = TMusic_System::open_device(param_1);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00461f34
// Address: 00461f34
// XREFS: None
void __thiscall FUN_00461f34(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x264) = param_2;
  *(undefined4 *)(param_1 + 0x268) = param_3;
  return;
}

// --------------------------------------------------

// Function: FUN_00461f57
// Address: 00461f57
// XREFS: None
void __thiscall FUN_00461f57(int param_1,int param_2,int param_3)
{
  char cVar1;
  int iVar2;
  
  if (param_2 < -10000) {
    param_2 = -10000;
  }
  else if (0 < param_2) {
    param_2 = 0;
  }
  if (param_3 != 0) {
    *(int *)(param_1 + 0x254) = param_2;
  }
  if (*(int *)(param_1 + 0x114) != 0) {
    cVar1 = *(char *)(param_1 + 0x104);
    if (cVar1 == '\x01') {
      iVar2 = *(int *)(param_1 + 0x278);
    }
    else {
      if (cVar1 != '\x02') {
        if (cVar1 != '\x03') {
          return;
        }
        if (*(TSound_Driver **)(param_1 + 0x108) == (TSound_Driver *)0x0) {
          return;
        }
        TSound_Driver::set_stream_volume(*(TSound_Driver **)(param_1 + 0x108),param_2);
        return;
      }
      iVar2 = *(int *)(param_1 + 0x278);
    }
    if (iVar2 != 0) {
      *(uint *)(param_1 + 0x3ec) =
           (uint)((*(int *)(param_1 + 0x3a8) - *(int *)(param_1 + 0x3a4)) * (param_2 + 10000)) /
           10000;
      mixerSetControlDetails(*(undefined4 *)(param_1 + 0x27c),param_1 + 0x3d4,0);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046200c
// Address: 0046200c
// XREFS: None
int __thiscall FUN_0046200c(TMusic_System *param_1,int param_2,int param_3,ulong param_4)
{
  int iVar1;
  
  param_1->file_name[0] = '\0';
  param_1->start_track = param_2;
  param_1->end_track = param_2;
  param_1->make_cur_track = 0;
  param_1->set_pos = param_4;
  param_1->loop = param_3;
  if (((param_1->playing_track != '\0') && (param_1->fade_out != 0)) && (param_1->fade_time != 0)) {
    TMusic_System::start_fade(param_1);
    return 1;
  }
  iVar1 = TMusic_System::play(param_1,param_2,param_2,(char *)0x0,0,param_4);
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_00462081
// Address: 00462081
// XREFS: None
int __thiscall FUN_00462081(TMusic_System *param_1,char *param_2,int param_3,ulong param_4)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1->music_type == '\x01') {
    return 0;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = param_2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar6 = param_1->file_name;
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
  param_1->start_track = 0;
  param_1->end_track = 0;
  param_1->make_cur_track = 0;
  param_1->set_pos = param_4;
  param_1->loop = param_3;
  if (((param_1->playing_track != '\0') && (param_1->fade_out != 0)) && (param_1->fade_time != 0)) {
    TMusic_System::start_fade(param_1);
    return 1;
  }
  iVar2 = TMusic_System::play(param_1,0,0,param_1->file_name,0,param_4);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_00462131
// Address: 00462131
// XREFS: None
int __thiscall
FUN_00462131(TMusic_System *param_1,int param_2,int param_3,int param_4,int param_5,ulong param_6)
{
  int iVar1;
  int iVar2;
  
  param_1->loop = param_4;
  iVar2 = param_1->track_count;
  param_1->file_name[0] = '\0';
  param_1->start_track = param_2;
  param_1->end_track = param_3;
  param_1->make_cur_track = param_5;
  param_1->set_pos = param_6;
  if (iVar2 == 0) {
    return iVar2;
  }
  if (iVar2 < param_2) {
    param_1->start_track = iVar2;
  }
  iVar1 = param_1->start_track;
  if (param_3 < iVar1) {
    param_1->end_track = iVar1;
  }
  else if (iVar2 < param_3) {
    param_1->end_track = iVar2;
  }
  if (((param_1->playing_track != '\0') && (param_1->fade_out != 0)) && (param_1->fade_time != 0)) {
    TMusic_System::start_fade(param_1);
    return 1;
  }
  iVar2 = TMusic_System::play(param_1,iVar1,param_1->end_track,(char *)0x0,param_5,param_6);
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_004621f7
// Address: 004621f7
// XREFS: None
// [HELPER] s_Unknow_Error: "Unknow Error"
// [HELPER] s__mid: ".mid"
// [HELPER] s__s_s: "%s%s"
// [HELPER] s__smusic_d_mid: "%smusic%d.mid"
// [HELPER] s__smusic_d_wav: "%smusic%d.wav"
undefined4 __thiscall
FUN_004621f7(TMusic_System *param_1,int param_2,int param_3,char *param_4,int param_5,int param_6)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 uStack_224;
  int iStack_220;
  undefined1 auStack_21c [4];
  uint uStack_218;
  undefined4 uStack_214;
  char *pcStack_210;
  char acStack_208 [264];
  char acStack_100 [256];
  
  if (param_1->device_open == 0) {
    return 0;
  }
  if (param_1->playing_track != '\0') {
    TMusic_System::stop_playing(param_1);
  }
  if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
    if (param_1->track_count == 0) {
      return 0;
    }
    if (param_1->track_count < param_2) {
      return 0;
    }
    if (param_2 == 0) {
      return 0;
    }
    if (param_5 == 0) {
      param_1->current_track = param_2;
    }
    else {
      param_1->current_track = param_5;
    }
  }
  uVar2 = param_1->music_type;
  if (uVar2 == '\x01') {
    (param_1->play_info).dwCallback = (ulong)param_1->window;
    uVar5 = 1;
    if (param_6 == 0) {
      uVar5 = 5;
      (param_1->play_info).dwFrom = (uint)(byte)param_1->current_track;
    }
    else {
      iStack_220 = param_6;
      uStack_224 = 0;
      mciSendCommandA(param_1->device_id,0x807,10,&uStack_224);
    }
    if ((param_2 < param_1->track_count) && (param_3 < param_1->track_count)) {
      uVar5 = uVar5 | 8;
      (param_1->play_info).dwTo = (uint)(byte)((char)param_3 + 1);
    }
    iVar3 = mciSendCommandA(param_1->device_id,0x806,uVar5,&param_1->play_info);
    if (iVar3 == 0) {
      param_1->playing_track = '\x01';
      param_1->notify_waiting = param_1->notify_waiting + 1;
    }
    else {
      iVar3 = mciGetErrorStringA(iVar3,acStack_100,0x100);
      if (iVar3 == 0) {
        uVar5 = 0xffffffff;
        pcVar10 = &s_Unknow_Error;
        do {
          pcVar9 = pcVar10;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        pcVar10 = pcVar9 + -uVar5;
        pcVar9 = acStack_100;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar9 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar9 = pcVar9 + 1;
        }
      }
    }
  }
  else if (uVar2 == '\x02') {
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      sprintf(acStack_208,s__smusic_d_mid,param_1,param_1->current_track);
    }
    else {
      sprintf(acStack_208,s__s_s,param_1,param_4);
      iVar3 = strchr(acStack_208,0x2e);
      if (iVar3 == 0) {
        uVar5 = 0xffffffff;
        pcVar10 = &s__mid;
        do {
          pcVar9 = pcVar10;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        iVar3 = -1;
        pcVar10 = acStack_208;
        do {
          pcVar8 = pcVar10;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar8 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar8;
        } while (cVar1 != '\0');
        pcVar10 = pcVar9 + -uVar5;
        pcVar9 = pcVar8 + -1;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar9 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar9 = pcVar9 + 1;
        }
      }
    }
    iVar3 = __open(acStack_208,0);
    if (iVar3 != -1) {
      close(iVar3);
      pcVar7 = mciSendCommandA_exref;
      pcStack_210 = acStack_208;
      uStack_214 = 0x20b;
      iVar3 = mciSendCommandA(0,0x803,0x3200,auStack_21c);
      if (iVar3 != 0) {
        iVar4 = mciGetErrorStringA(iVar3,acStack_100,0x100);
        if (iVar4 == 0) {
          uVar5 = 0xffffffff;
          pcVar10 = &s_Unknow_Error;
          do {
            pcVar9 = pcVar10;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar9 = pcVar10 + 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar9;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          pcVar10 = pcVar9 + -uVar5;
          pcVar9 = acStack_100;
          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
            pcVar10 = pcVar10 + 4;
            pcVar9 = pcVar9 + 4;
          }
          for (uVar5 = uVar5 & 3; pcVar7 = mciSendCommandA_exref, uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            pcVar9 = pcVar9 + 1;
          }
        }
        if (iVar3 != 0) goto LAB_00462579;
      }
      param_1->device_id = uStack_218;
      if (param_6 != 0) {
        iStack_220 = param_6;
        uStack_224 = 0;
        (*pcVar7)(uStack_218,0x807,8,&uStack_224);
      }
      (param_1->play_info).dwCallback = (ulong)param_1->window;
      iVar3 = (*pcVar7)(param_1->device_id,0x806,1,&param_1->play_info);
      if (iVar3 == 0) {
        param_1->playing_track = '\x01';
        param_1->notify_waiting = param_1->notify_waiting + 1;
      }
    }
  }
  else if ((uVar2 == '\x03') && (param_1->sound_system != (TSound_Driver *)0x0)) {
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      param_4 = (char *)param_1->current_track;
      pcVar10 = s__smusic_d_wav;
    }
    else {
      pcVar10 = s__s_s;
    }
    sprintf(acStack_208,pcVar10,param_1,param_4);
    iVar3 = TSound_Driver::stream_file(param_1->sound_system,acStack_208,0,param_1->volume);
    if (iVar3 == 0) {
      return 0;
    }
    param_1->playing_track = '\x01';
  }
LAB_00462579:
  if (param_1->playing_track == '\0') {
    return 0;
  }
  param_1->paused = 0;
  param_1->auto_paused = 0;
  param_1->inactivated = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004625b8
// Address: 004625b8
// XREFS: None
undefined4 __fastcall FUN_004625b8(int param_1)
{
  char cVar1;
  
  if ((*(int *)(param_1 + 0x114) == 0) || (*(char *)(param_1 + 0x128) == '\0')) {
    return 0;
  }
  if (*(int *)(param_1 + 600) != 0) {
    *(undefined4 *)(param_1 + 0x25c) = 0;
    return 1;
  }
  *(undefined4 *)(param_1 + 600) = 1;
  if (*(int *)(param_1 + 0x25c) != 0) {
    *(undefined4 *)(param_1 + 0x25c) = 0;
    return 1;
  }
  cVar1 = *(char *)(param_1 + 0x104);
  if (cVar1 == '\x01') {
    mciSendCommandA(*(undefined4 *)(param_1 + 0x118),0x809,2,0);
  }
  else {
    if (cVar1 == '\x02') {
      mciSendCommandA(*(undefined4 *)(param_1 + 0x118),0x809,2,0);
      return 1;
    }
    if ((cVar1 == '\x03') && (*(TSound_Driver **)(param_1 + 0x108) != (TSound_Driver *)0x0)) {
      TSound_Driver::pause_stream(*(TSound_Driver **)(param_1 + 0x108));
      return 1;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0046266f
// Address: 0046266f
// XREFS: None
undefined4 __fastcall FUN_0046266f(TMusic_System *param_1)
{
  uchar uVar1;
  int iVar2;
  
  if (((param_1->device_open == 0) || (param_1->playing_track == '\0')) || (param_1->paused == 0)) {
    return 0;
  }
  param_1->paused = 0;
  param_1->auto_paused = 0;
  if (param_1->fading_track != 0) {
    TMusic_System::end_fade(param_1);
    return 1;
  }
  uVar1 = param_1->music_type;
  if (uVar1 == '\x01') {
    iVar2 = mciSendCommandA(param_1->device_id,0x806,0,&param_1->play_info);
  }
  else {
    if (uVar1 != '\x02') {
      if (uVar1 != '\x03') {
        return 1;
      }
      if (param_1->sound_system == (TSound_Driver *)0x0) {
        return 1;
      }
      TSound_Driver::resume_stream(param_1->sound_system);
      return 1;
    }
    iVar2 = mciSendCommandA(param_1->device_id,0x806,0,&param_1->play_info);
  }
  if (iVar2 == 0) {
    param_1->notify_waiting = param_1->notify_waiting + 1;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0046273f
// Address: 0046273f
// XREFS: None
void __fastcall FUN_0046273f(TMusic_System *param_1)
{
  param_1->loop = 0;
  param_1->start_track = 0;
  param_1->end_track = 0;
  param_1->file_name[0] = '\0';
  param_1->fading_track = 0;
  TMusic_System::stop_playing(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_00462765
// Address: 00462765
// XREFS: None
undefined4 __fastcall FUN_00462765(int param_1)
{
  char cVar1;
  
  if (*(char *)(param_1 + 0x128) == '\0') {
    return 1;
  }
  cVar1 = *(char *)(param_1 + 0x104);
  if (cVar1 == '\x01') {
    mciSendCommandA(*(undefined4 *)(param_1 + 0x118),0x808,2,0);
    *(undefined1 *)(param_1 + 0x128) = 0;
  }
  else if (cVar1 == '\x02') {
    mciSendCommandA(*(undefined4 *)(param_1 + 0x118),0x808,2,0);
    *(undefined1 *)(param_1 + 0x128) = 0;
    mciSendCommandA(*(undefined4 *)(param_1 + 0x118),0x804,2,0);
    *(undefined4 *)(param_1 + 0x118) = 0;
  }
  else if ((cVar1 == '\x03') && (*(TSound_Driver **)(param_1 + 0x108) != (TSound_Driver *)0x0)) {
    TSound_Driver::stop_stream(*(TSound_Driver **)(param_1 + 0x108));
  }
  *(undefined1 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 600) = 0;
  *(undefined4 *)(param_1 + 0x25c) = 0;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00462815
// Address: 00462815
// XREFS: None
undefined4 __fastcall FUN_00462815(TMusic_System *param_1)
{
  param_1->loop = 0;
  param_1->start_track = 0;
  param_1->end_track = 0;
  param_1->file_name[0] = '\0';
  param_1->fading_track = 0;
  if (param_1->playing_track != '\0') {
    TMusic_System::start_fade(param_1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00462855
// Address: 00462855
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_music_cpp: "C:\msdev\work\age1_x1\music.cpp"
void __fastcall FUN_00462855(int param_1)
{
  ulong uVar1;
  
  if (*(int *)(param_1 + 0x26c) == 0) {
    *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(param_1 + 0x254);
    uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_music_cpp,0x38c);
    *(ulong *)(param_1 + 0x274) = uVar1;
    *(undefined4 *)(param_1 + 0x26c) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046289d
// Address: 0046289d
// XREFS: None
// [HELPER] s_C__msdev_work_age1_x1_music_cpp: "C:\msdev\work\age1_x1\music.cpp"
void __fastcall FUN_0046289d(TMusic_System *param_1)
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  if (param_1->paused == 0) {
    debug_timeGetTime(s_C__msdev_work_age1_x1_music_cpp,0x39e);
    if ((param_1->fade_volume < -9999) && (param_1->playing_track != '\0')) {
      TMusic_System::stop_playing(param_1);
    }
    iVar1 = __ftol();
    iVar1 = param_1->fade_volume + iVar1;
    param_1->fade_volume = iVar1;
    iVar2 = __ftol();
    if (-10000 - iVar2 < iVar1) {
      TMusic_System::set_volume(param_1,iVar1,0);
      uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_music_cpp,0x3b8);
      param_1->last_fade_time = uVar3;
    }
    else {
      if (param_1->playing_track != '\0') {
        TMusic_System::stop_playing(param_1);
      }
      if (param_1->fading_track != 0) {
        TMusic_System::end_fade(param_1);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004629a6
// Address: 004629a6
// XREFS: None
void __fastcall FUN_004629a6(TMusic_System *param_1)
{
  param_1->fading_track = 0;
  TMusic_System::set_volume(param_1,param_1->volume,0);
  if (((0 < param_1->start_track) && (0 < param_1->end_track)) || (param_1->file_name[0] != '\0')) {
    TMusic_System::play(param_1,param_1->start_track,param_1->end_track,param_1->file_name,
                        param_1->make_cur_track,param_1->set_pos);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00462a0f
// Address: 00462a0f
// XREFS: None
undefined4 __thiscall
FUN_00462a0f(TMusic_System *param_1,undefined4 param_2,uint param_3,int param_4)
{
  uchar uVar1;
  
  if (param_3 < 0x114) {
    if (param_3 == 0x113) {
      if (param_1->fading_track != 0) {
        TMusic_System::do_fade(param_1);
        return 0;
      }
    }
    else if (param_3 == 0x1c) {
      if (param_4 == 0) {
        if (param_1->inactivated == 0) {
          TMusic_System::pause_play(param_1);
          param_1->auto_paused = 1;
          param_1->inactivated = 1;
          return 0;
        }
      }
      else if ((param_1->inactivated != 0) && (param_1->auto_paused != 0)) {
        TMusic_System::resume_play(param_1);
        param_1->auto_paused = 0;
        param_1->inactivated = 0;
        return 0;
      }
    }
  }
  else if (param_3 == 0x3b9) {
    uVar1 = param_1->music_type;
    if ((uVar1 == '\x01') || (uVar1 == '\x02')) {
      if (0 < param_1->notify_waiting) {
        param_1->notify_waiting = param_1->notify_waiting + -1;
      }
      if ((param_1->notify_waiting == 0) && (param_1->paused == 0)) {
        if (uVar1 == '\x01') {
          param_1->playing_track = '\0';
        }
        TMusic_System::after_end_track(param_1);
      }
    }
  }
  else if (((param_3 == 0x500) && (param_1->music_type == '\x03')) && (param_1->paused == 0)) {
    param_1->playing_track = '\0';
    TMusic_System::after_end_track(param_1);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00462b37
// Address: 00462b37
// XREFS: None
void __fastcall FUN_00462b37(TMusic_System *param_1)
{
  uchar uVar1;
  int iVar2;
  char cVar3;
  
  uVar1 = param_1->music_type;
  if (uVar1 == '\x01') {
    if (param_1->fading_track != 0) {
      return;
    }
    if (param_1->loop == 0) {
      return;
    }
  }
  else {
    if (uVar1 == '\x02') {
      if (param_1->fading_track != 0) {
        return;
      }
      cVar3 = param_1->file_name[0];
      if ((cVar3 == '\0') && (param_1->current_track < param_1->end_track)) {
        iVar2 = param_1->current_track + 1;
        TMusic_System::play(param_1,iVar2,iVar2,(char *)0x0,0,0);
        return;
      }
    }
    else {
      if (uVar1 != '\x03') {
        return;
      }
      if (param_1->fading_track != 0) {
        return;
      }
      cVar3 = param_1->file_name[0];
      if ((cVar3 == '\0') && (param_1->current_track < param_1->end_track)) {
        iVar2 = param_1->current_track + 1;
        TMusic_System::play(param_1,iVar2,iVar2,(char *)0x0,0,0);
        return;
      }
    }
    if (param_1->loop == 0) {
      return;
    }
    if (cVar3 != '\0') {
      TMusic_System::play(param_1,0,0,param_1->file_name,0,0);
      return;
    }
  }
  TMusic_System::play(param_1,param_1->start_track,param_1->end_track,(char *)0x0,0,0);
  return;
}

// --------------------------------------------------

// Function: FUN_00462c24
// Address: 00462c24
// XREFS: None
undefined4 __thiscall
FUN_00462c24(int param_1,undefined1 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,char *param_6,undefined4 *param_7,undefined4 *param_8)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *param_2 = *(undefined1 *)(param_1 + 0x104);
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = '\0';
  *param_7 = 0;
  *param_8 = 0;
  if (*(int *)(param_1 + 0x114) == 0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x128) != '\0') {
    *param_3 = *(undefined4 *)(param_1 + 0x230);
    *param_4 = *(undefined4 *)(param_1 + 0x234);
    *param_5 = *(undefined4 *)(param_1 + 0x244);
    uVar3 = 0xffffffff;
    pcVar5 = (char *)(param_1 + 0x129);
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
      *(undefined4 *)param_6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      param_6 = param_6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      param_6 = param_6 + 1;
    }
    *param_7 = *(undefined4 *)(param_1 + 0x240);
    *param_8 = 0;
    if (*(char *)(param_1 + 0x104) == '\x01') {
      uStack_8 = 2;
      iVar2 = mciSendCommandA(*(undefined4 *)(param_1 + 0x118),0x814,0x102,auStack_10);
    }
    else {
      if (*(char *)(param_1 + 0x104) != '\x02') {
        return 1;
      }
      uStack_8 = 2;
      iVar2 = mciSendCommandA(*(undefined4 *)(param_1 + 0x118),0x814,0x102,auStack_10);
    }
    if (iVar2 == 0) {
      *param_8 = uStack_c;
    }
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00462d65
// Address: 00462d65
// XREFS: None
void FUN_00462d65(char *param_1)
{
  char *pcVar1;
  char cVar2;
  
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    if (cVar2 == '_') {
      *param_1 = ' ';
    }
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  return;
}

// --------------------------------------------------

// Function: convert_us
// Address: 00462d70
// XREFS: RGE_Effects, RGE_Sprite, load_border_types, load_terrain_types
/* void __cdecl convert_us(char *) */

void __cdecl convert_us(char *param_1)
{
  char *pcVar1;
  char cVar2;
  
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    if (cVar2 == '_') {
      *param_1 = ' ';
    }
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00462d8a
// Address: 00462d8a
// XREFS: None
void FUN_00462d8a(char *param_1)
{
  char *pcVar1;
  char cVar2;
  
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    if (cVar2 == ' ') {
      *param_1 = '_';
    }
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  return;
}

// --------------------------------------------------

// Function: unconvert_us
// Address: 00462d90
// XREFS: None
/* void __cdecl unconvert_us(char *) */

void __cdecl unconvert_us(char *param_1)
{
  char *pcVar1;
  char cVar2;
  
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    if (cVar2 == ' ') {
      *param_1 = '_';
    }
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00462daa
// Address: 00462daa
// XREFS: None
void FUN_00462daa(int *param_1,char *param_2,char *param_3)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar3 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  uVar4 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar4 - 1;
  pcVar2 = (char *)calloc(~uVar4 + uVar3,1);
  pcVar6 = pcVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *param_2;
    param_2 = param_2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  pcVar6 = pcVar2 + uVar3;
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_3;
    param_3 = param_3 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar6 = *param_3;
    param_3 = param_3 + 1;
    pcVar6 = pcVar6 + 1;
  }
  if (*param_1 != 0) {
    free(*param_1);
  }
  *param_1 = (int)pcVar2;
  return;
}

// --------------------------------------------------

// Function: addstring
// Address: 00462db0
// XREFS: Check_shape, RGE_Color_Table, add_description, do_draw, get_frame, get_size, load_border_types, load_campaign, load_terrain_types, make_campaign, shape_hit_test
/* void __cdecl addstring(char * *,char *,char *) */

void __cdecl addstring(char **param_1,char *param_2,char *param_3)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar3 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  uVar4 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar4 - 1;
  pcVar2 = (char *)calloc(~uVar4 + uVar3,1);
  pcVar6 = pcVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *param_2;
    param_2 = param_2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  pcVar6 = pcVar2 + uVar3;
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_3;
    param_3 = param_3 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar6 = *param_3;
    param_3 = param_3 + 1;
    pcVar6 = pcVar6 + 1;
  }
  if (*param_1 != (char *)0x0) {
    free(*param_1);
  }
  *param_1 = pcVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_00462e2d
// Address: 00462e2d
// XREFS: None
void FUN_00462e2d(int *param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  if (*param_1 != 0) {
    free(*param_1);
  }
  pcVar2 = (char *)calloc(uVar3,1);
  *param_1 = (int)pcVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *param_2;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: getstring
// Address: 00462e30
// XREFS: RGE_Player, TRIBE_Tech, add_description, condition_description, copy_obj, get_campaign_list, get_people_list, get_scenario_list, make_campaign, scenario_info, setup
/* void __cdecl getstring(char * *,char *) */

void __cdecl getstring(char **param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  if (*param_1 != (char *)0x0) {
    free(*param_1);
  }
  pcVar2 = (char *)calloc(uVar3,1);
  *param_1 = pcVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *param_2;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00462e7c
// Address: 00462e7c
// XREFS: None
void __fastcall FUN_00462e7c(undefined4 *param_1)
{
  *param_1 = &RGE_Object_List::_vftable_;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00462e92
// Address: 00462e92
// XREFS: None
void __fastcall FUN_00462e92(undefined4 *param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  *param_1 = &RGE_Object_List::_vftable_;
  piVar4 = (int *)param_1[1];
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)piVar4[1];
    puVar2 = (undefined4 *)*piVar4;
    piVar4 = piVar1;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  iVar3 = param_1[1];
  while (iVar3 != 0) {
    iVar3 = *(int *)(param_1[1] + 4);
    free(iVar3);
    param_1[1] = iVar3;
  }
  *(undefined2 *)(param_1 + 2) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00462eee
// Address: 00462eee
// XREFS: None
void __fastcall FUN_00462eee(int param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 4);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    puVar2 = (undefined4 *)*piVar3;
    piVar3 = piVar1;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00462f22
// Address: 00462f22
// XREFS: None
void __thiscall FUN_00462f22(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)calloc(1,0x10);
  uVar1 = *(undefined4 *)(param_1 + 4);
  puVar2[2] = 0;
  puVar2[1] = uVar1;
  if (*(int *)(param_1 + 4) != 0) {
    *(undefined4 **)(*(int *)(param_1 + 4) + 8) = puVar2;
  }
  *puVar2 = param_2;
  *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + 1;
  *(undefined4 **)(param_1 + 4) = puVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_00462f67
// Address: 00462f67
// XREFS: None
void __thiscall FUN_00462f67(int param_1,int param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    if (param_3 == (int *)0x0) {
      iVar2 = *piVar1;
      param_3 = piVar1;
      while (iVar2 != param_2) {
        param_3 = (int *)param_3[1];
        if (param_3 == (int *)0x0) {
          return;
        }
        iVar2 = *param_3;
      }
    }
    if (param_3[2] == 0) {
      *(int *)(param_1 + 4) = param_3[1];
    }
    else {
      *(int *)(param_3[2] + 4) = param_3[1];
    }
    if (param_3[1] != 0) {
      *(int *)(param_3[1] + 8) = param_3[2];
    }
    free(param_3);
    *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + -1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00462fce
// Address: 00462fce
// XREFS: None
void __fastcall FUN_00462fce(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar2 = 0;
  while (iVar1 = iVar3, iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 4);
    *(int *)(iVar1 + 4) = iVar2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 8) = iVar1;
    }
    *(undefined4 *)(iVar1 + 8) = 0;
    iVar2 = iVar1;
    iVar3 = *(int *)(param_1 + 4);
  }
  *(int *)(param_1 + 4) = iVar2;
  return;
}

// --------------------------------------------------

// Function: FUN_00462fff
// Address: 00462fff
// XREFS: None
void __thiscall
FUN_00462fff(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  int iVar6;
  
  piVar1 = *(int **)(param_1 + 4);
  do {
    if (piVar1 == (int *)0x0) {
      return;
    }
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      iVar3 = piVar2[3];
      bVar5 = true;
      iVar6 = *(int *)(iVar3 + 0x108);
      switch(*(undefined1 *)(piVar2[2] + 0x65)) {
      case 0:
        if (param_5 != '\0') {
LAB_0046303d:
          bVar5 = false;
        }
        break;
      case 2:
        if ((param_5 != '\0') && (2 < *(byte *)(piVar2 + 0x12))) goto LAB_0046303d;
        break;
      case 3:
        bVar5 = false;
        if ((param_5 != '\0') &&
           (*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 0x3c) + 0x40) +
                             *(short *)(*(int *)(iVar3 + 0x3c) + 0x7c) * 4) + 0xac +
                    *(short *)(iVar3 + 0x4a) * 4) != 0)) {
          iVar6 = piVar2[0x24];
          bVar5 = true;
        }
        break;
      case 4:
        if ((param_5 != '\0') && (1 < *(short *)(param_1 + 8))) {
          for (piVar4 = *(int **)(param_1 + 4); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
            if (*(char *)(*piVar4 + 0x4e) == '\x19') goto LAB_0046303d;
          }
        }
      }
      if (bVar5) {
        (**(code **)(*piVar2 + 0xc))(param_2,param_3,param_4,iVar6);
      }
    }
    piVar1 = (int *)piVar1[1];
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004630dd
// Address: 004630dd
// XREFS: None
/* WARNING: Instruction at (ram,0x0046311e) overlaps instruction at (ram,0x0046311b)
    */

int __thiscall
FUN_004630dd(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            char param_6,undefined4 param_7,undefined4 param_8)
{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  uint in_EAX;
  uint uVar4;
  undefined3 uVar6;
  int iVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  byte *unaff_ESI;
  int unaff_EDI;
  undefined2 in_SS;
  
  uVar4 = in_EAX ^ 0x3f004630;
  bVar3 = (byte)uVar4;
  *unaff_ESI = *unaff_ESI ^ bVar3;
  pbVar1 = (byte *)segment(in_SS,(short)unaff_EBP);
  *pbVar1 = *pbVar1 ^ bVar3;
  uVar6 = (undefined3)(uVar4 >> 8);
  if (*pbVar1 == 0) {
    *(char *)(unaff_EDI + -0x6fffb9d0) = *(char *)(unaff_EDI + -0x6fffb9d0) + (char)(uVar4 >> 8);
    iVar5 = CONCAT31(uVar6,param_6);
    unaff_ESI = *(byte **)(param_1 + 4);
    if (param_6 == '\0') {
      for (; unaff_ESI != (byte *)0x0; unaff_ESI = *(byte **)(unaff_ESI + 4)) {
        if (*(int **)unaff_ESI != (int *)0x0) {
          iVar5 = (**(code **)(**(int **)unaff_ESI + 0x10))(param_2,param_3,param_4,param_5);
        }
      }
    }
    else {
      unaff_EBX = param_3;
      unaff_EBP = param_4;
      unaff_EDI = param_2;
      if (unaff_ESI != (byte *)0x0) goto LAB_0046311f;
    }
    return iVar5;
  }
  iVar5 = CONCAT31(uVar6,bVar3 + 0x75);
LAB_0046311f:
  do {
    piVar2 = *(int **)unaff_ESI;
    if ((piVar2 != (int *)0x0) && (iVar5 = piVar2[2], *(char *)(iVar5 + 0x65) != '\0')) {
      iVar5 = (**(code **)(*piVar2 + 0x10))(unaff_EDI,unaff_EBX,unaff_EBP,param_8);
    }
    unaff_ESI = *(byte **)(unaff_ESI + 4);
  } while (unaff_ESI != (byte *)0x0);
  return iVar5;
}

// --------------------------------------------------

// Function: FUN_0046317b
// Address: 0046317b
// XREFS: None
void __thiscall
FUN_0046317b(RGE_Object_List *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            char param_5)
{
  RGE_Object_Node **ppRVar1;
  RGE_Static_Object *pRVar2;
  RGE_Object_Node *pRVar3;
  RGE_Object_Node *pRVar4;
  
  pRVar3 = RGE_Object_List::sort(param_1);
  if (param_5 == '\0') {
    pRVar4 = pRVar3;
    if (pRVar3 == (RGE_Object_Node *)0x0) {
      return;
    }
    do {
      if (pRVar4->node != (RGE_Static_Object *)0x0) {
        (**(code **)(pRVar4->node->_padding_ + 0x14))(param_2,param_3,param_4);
      }
      ppRVar1 = &pRVar4->next;
      pRVar4 = *ppRVar1;
    } while (*ppRVar1 != (RGE_Object_Node *)0x0);
  }
  else {
    pRVar4 = pRVar3;
    if (pRVar3 == (RGE_Object_Node *)0x0) {
      return;
    }
    do {
      pRVar2 = pRVar4->node;
      if ((pRVar2 != (RGE_Static_Object *)0x0) && (pRVar2->master_obj->fog_flag != '\0')) {
        (**(code **)(pRVar2->_padding_ + 0x14))(param_2,param_3,param_4);
      }
      ppRVar1 = &pRVar4->next;
      pRVar4 = *ppRVar1;
    } while (*ppRVar1 != (RGE_Object_Node *)0x0);
  }
  while (pRVar3 != (RGE_Object_Node *)0x0) {
    pRVar4 = pRVar3->next;
    free(pRVar3);
    pRVar3 = pRVar4;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00463208
// Address: 00463208
// XREFS: None
void __fastcall FUN_00463208(int param_1)
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar1 = *(int **)(param_1 + 4);
  while (piVar2 = piVar1, piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if ((int *)*piVar2 != (int *)0x0) {
      cVar3 = (**(code **)(*(int *)*piVar2 + 0x24))();
      if (cVar3 != '\0') {
        (**(code **)(*(int *)*piVar2 + 8))();
      }
      iVar4 = iVar4 + 1;
      if ((9 < iVar4) && (iVar4 = 0, MouseSystem != (TMousePointer *)0x0)) {
        TMousePointer::Poll(MouseSystem);
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00463256
// Address: 00463256
// XREFS: None
void __fastcall FUN_00463256(int param_1)
{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  int **ppiVar4;
  int *piVar5;
  int *piStack_4;
  
  piVar3 = *(int **)(param_1 + 4);
  piStack_4 = (int *)0x0;
  do {
    if (piVar3 == (int *)0x0) {
      return;
    }
    ppiVar4 = &piStack_4;
    bVar1 = *(byte *)(*(int *)(*piVar3 + 8) + 0x4a);
    for (piVar5 = piStack_4; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[1]) {
      bVar2 = *(byte *)(*(int *)(*piVar5 + 8) + 0x4a);
      if ((bVar2 < bVar1) ||
         ((bVar2 == bVar1 && (*(short *)(*piVar3 + 0x2a) < *(short *)(*piVar5 + 0x2a))))) break;
      ppiVar4 = (int **)(piVar5 + 1);
    }
    piVar5 = (int *)calloc(1,0x10);
    piVar5[1] = (int)*ppiVar4;
    if (*ppiVar4 != (int *)0x0) {
      piVar5[2] = (*ppiVar4)[2];
      (*ppiVar4)[2] = (int)piVar5;
    }
    *piVar5 = *piVar3;
    *ppiVar4 = piVar5;
    piVar3 = (int *)piVar3[1];
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004632dd
// Address: 004632dd
// XREFS: None
int * __thiscall FUN_004632dd(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  while ((*piVar1 == 0 || (*(short *)(*(int *)(*piVar1 + 8) + 0x14) != param_2))) {
    piVar1 = (int *)piVar1[1];
    if (piVar1 == (int *)0x0) {
      return piVar1;
    }
  }
  return (int *)*piVar1;
}

// --------------------------------------------------

// Function: FUN_0046348d
// Address: 0046348d
// XREFS: None
int * __thiscall FUN_0046348d(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  while ((*piVar1 == 0 || (*(int *)(*piVar1 + 4) != param_2))) {
    piVar1 = (int *)piVar1[1];
    if (piVar1 == (int *)0x0) {
      return piVar1;
    }
  }
  return (int *)*piVar1;
}

// --------------------------------------------------

// Function: FUN_004634ba
// Address: 004634ba
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_004634ba(int param_1,int param_2,float param_3,float param_4,char param_5,char param_6,
            RGE_Static_Object *param_7)
{
  float fVar1;
  float fVar2;
  RGE_Static_Object *this;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iStack_4;
  
  this = param_7;
  if (((param_3 <= _DAT_00570c30) || (param_4 <= _DAT_00570c30)) ||
     (param_7 == (RGE_Static_Object *)0x0)) {
    uVar6 = 0xffffffff;
  }
  else {
    iVar4 = __ftol();
    iVar5 = __ftol();
    bVar3 = RGE_Static_Object::lookupZone(param_7,iVar5,iVar4);
    uVar6 = (uint)bVar3;
  }
  piVar7 = *(int **)(param_1 + 4);
  iStack_4 = 0;
  param_7 = (RGE_Static_Object *)0xbf800000;
  if (piVar7 == (int *)0x0) {
    return 0;
  }
  do {
    iVar4 = *piVar7;
    if (((iVar4 != 0) && (*(short *)(*(int *)(iVar4 + 8) + 0x10) == param_2)) &&
       ((param_5 == '\0' || (*(char *)(iVar4 + 0x48) == param_6)))) {
      if ((param_3 == _DAT_00570c30) || (param_4 == _DAT_00570c30)) {
        return *piVar7;
      }
      if (-1 < (int)uVar6) {
        iVar4 = __ftol();
        iVar5 = __ftol();
        bVar3 = RGE_Static_Object::lookupZone(this,iVar5,iVar4);
        if (bVar3 != uVar6) goto LAB_0046360a;
      }
      iVar4 = *piVar7;
      fVar2 = param_3 - *(float *)(iVar4 + 0x38);
      fVar1 = param_4 - *(float *)(iVar4 + 0x3c);
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
      if (((float)param_7 == _DAT_00570c30) || (fVar1 < (float)param_7)) {
        param_7 = (RGE_Static_Object *)fVar1;
        iStack_4 = iVar4;
      }
    }
LAB_0046360a:
    piVar7 = (int *)piVar7[1];
    if (piVar7 == (int *)0x0) {
      return iStack_4;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0046363d
// Address: 0046363d
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_0046363d(int param_1,int param_2,int param_3,float param_4,float param_5,char param_6,
            char param_7,RGE_Static_Object *param_8)
{
  float fVar1;
  float fVar2;
  RGE_Static_Object *this;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iStack_4;
  
  this = param_8;
  if (((param_8 == (RGE_Static_Object *)0x0) || (param_4 <= _DAT_00570c30)) ||
     (param_5 <= _DAT_00570c30)) {
    uVar6 = 0xffffffff;
  }
  else {
    iVar4 = __ftol();
    iVar5 = __ftol();
    bVar3 = RGE_Static_Object::lookupZone(param_8,iVar5,iVar4);
    uVar6 = (uint)bVar3;
  }
  piVar7 = *(int **)(param_1 + 4);
  iStack_4 = 0;
  param_8 = (RGE_Static_Object *)0xbf800000;
  if (piVar7 == (int *)0x0) {
    return 0;
  }
  do {
    iVar4 = *piVar7;
    iVar5 = (int)*(short *)(*(int *)(iVar4 + 8) + 0x10);
    if (((iVar4 != 0) && ((iVar5 == param_2 || (iVar5 == param_3)))) &&
       ((param_6 == '\0' || (*(char *)(iVar4 + 0x48) == param_7)))) {
      if ((param_4 == _DAT_00570c30) && (param_5 == _DAT_00570c30)) {
        return *piVar7;
      }
      if (-1 < (int)uVar6) {
        iVar4 = __ftol();
        iVar5 = __ftol();
        bVar3 = RGE_Static_Object::lookupZone(this,iVar5,iVar4);
        if (bVar3 != uVar6) goto LAB_0046378c;
      }
      iVar4 = *piVar7;
      fVar2 = param_4 - *(float *)(iVar4 + 0x38);
      fVar1 = param_5 - *(float *)(iVar4 + 0x3c);
      fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
      if (((float)param_8 == _DAT_00570c30) || (fVar1 < (float)param_8)) {
        param_8 = (RGE_Static_Object *)fVar1;
        iStack_4 = iVar4;
      }
    }
LAB_0046378c:
    piVar7 = (int *)piVar7[1];
    if (piVar7 == (int *)0x0) {
      return iStack_4;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_004637bf
// Address: 004637bf
// XREFS: None
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_004637bf(int param_1,char param_2,float param_3,float param_4,char param_5,char param_6)
{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  float fStack_4;
  
  piVar4 = *(int **)(param_1 + 4);
  iVar5 = 0;
  fStack_4 = -1.0;
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  do {
    iVar1 = *piVar4;
    iVar6 = iVar5;
    fVar2 = fStack_4;
    if (((iVar1 != 0) && (*(char *)(iVar1 + 0x4e) == param_2)) &&
       ((param_5 == '\0' || (*(char *)(iVar1 + 0x48) == param_6)))) {
      if ((param_3 == _DAT_00570c30) && (param_4 == _DAT_00570c30)) {
        return *piVar4;
      }
      fVar3 = param_3 - *(float *)(iVar1 + 0x38);
      fVar2 = param_4 - *(float *)(iVar1 + 0x3c);
      fVar2 = fVar2 * fVar2 + fVar3 * fVar3;
      iVar6 = iVar1;
      if ((fStack_4 != _DAT_00570c30) && (fStack_4 <= fVar2)) {
        iVar6 = iVar5;
        fVar2 = fStack_4;
      }
    }
    fStack_4 = fVar2;
    piVar4 = (int *)piVar4[1];
    iVar5 = iVar6;
    if (piVar4 == (int *)0x0) {
      return iVar6;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0046388f
// Address: 0046388f
// XREFS: None
void __thiscall FUN_0046388f(uint param_1,int param_2)
{
  int *piVar1;
  undefined4 uStack_4;
  
  piVar1 = *(int **)(param_1 + 4);
  uStack_4 = param_1 & 0xffffff;
  for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0x30))(param_2);
    }
  }
  rge_write(param_2,(void *)((int)&uStack_4 + 3),1);
  return;
}

// --------------------------------------------------

// Function: FUN_004638cc
// Address: 004638cc
// XREFS: None
void __thiscall FUN_004638cc(RGE_Object_List *param_1,int param_2,undefined4 param_3)
{
  undefined4 uVar1;
  
  uVar1 = param_3;
  while( true ) {
    rge_read(param_2,&param_3,1);
    if ((char)param_3 == '\0') break;
    (**(code **)param_1->_padding_)(param_3,param_2,uVar1);
  }
  RGE_Object_List::invert(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_0046390d
// Address: 0046390d
// XREFS: None
void __fastcall FUN_0046390d(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    (**(code **)(*(int *)*puVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00463928
// Address: 00463928
// XREFS: None
void FUN_00463928(undefined1 param_1,int param_2,RGE_Game_World *param_3)
{
  RGE_Static_Object *this;
  RGE_Animated_Object *this_00;
  RGE_Doppleganger_Object *this_01;
  RGE_Moving_Object *this_02;
  RGE_Missile_Object *this_03;
  RGE_Action_Object *this_04;
  RGE_Combat_Object *this_05;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0055de1d;
  *unaff_FS_OFFSET = &uStack_c;
  switch(param_1) {
  case 10:
    this = (RGE_Static_Object *)operator_new(0x88);
    uStack_4 = 0;
    if (this != (RGE_Static_Object *)0x0) {
      RGE_Static_Object::RGE_Static_Object(this,param_2,param_3,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 0x14:
    this_00 = (RGE_Animated_Object *)operator_new(0x8c);
    uStack_4 = 1;
    if (this_00 != (RGE_Animated_Object *)0x0) {
      RGE_Animated_Object::RGE_Animated_Object(this_00,param_2,param_3,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 0x19:
    this_01 = (RGE_Doppleganger_Object *)operator_new(0xb0);
    uStack_4 = 2;
    if (this_01 != (RGE_Doppleganger_Object *)0x0) {
      RGE_Doppleganger_Object::RGE_Doppleganger_Object(this_01,param_2,param_3,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 0x1e:
    this_02 = (RGE_Moving_Object *)operator_new(0x180);
    uStack_4 = 3;
    if (this_02 != (RGE_Moving_Object *)0x0) {
      RGE_Moving_Object::RGE_Moving_Object(this_02,param_2,param_3,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 0x28:
    this_04 = (RGE_Action_Object *)operator_new(0x194);
    uStack_4 = 5;
    if (this_04 != (RGE_Action_Object *)0x0) {
      RGE_Action_Object::RGE_Action_Object(this_04,param_2,param_3,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    break;
  case 0x32:
    this_05 = (RGE_Combat_Object *)operator_new(0x1c4);
    uStack_4 = 6;
    if (this_05 != (RGE_Combat_Object *)0x0) {
      RGE_Combat_Object::RGE_Combat_Object(this_05,param_2,param_3,1);
    }
    break;
  case 0x3c:
    this_03 = (RGE_Missile_Object *)operator_new(0x1c8);
    uStack_4 = 4;
    if (this_03 != (RGE_Missile_Object *)0x0) {
      RGE_Missile_Object::RGE_Missile_Object(this_03,param_2,param_3,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: $E4
// Address: 00463ba0
// XREFS: None
void _E4(void)
{
  _E1();
  _E3();
  return;
}

// --------------------------------------------------

// Function: FUN_00463baa
// Address: 00463baa
// XREFS: None
void FUN_00463baa(void)
{
  TPanelSystem::TPanelSystem(&panel_system);
  return;
}

// --------------------------------------------------

// Function: $E1
// Address: 00463bb0
// XREFS: $E4
void _E1(void)
{
  TPanelSystem::TPanelSystem(&panel_system);
  return;
}

// --------------------------------------------------

// Function: FUN_00463bba
// Address: 00463bba
// XREFS: None
void FUN_00463bba(void)
{
  atexit(_E2);
  return;
}

// --------------------------------------------------

// Function: $E3
// Address: 00463bc0
// XREFS: $E4
void _E3(void)
{
  atexit(_E2);
  return;
}

// --------------------------------------------------

// Function: FUN_00463bce
// Address: 00463bce
// XREFS: None
void FUN_00463bce(void)
{
  TPanelSystem::~TPanelSystem(&panel_system);
  return;
}

// --------------------------------------------------

// Function: $E2
// Address: 00463bd0
// XREFS: $E3
void _E2(void)
{
  TPanelSystem::~TPanelSystem(&panel_system);
  return;
}

// --------------------------------------------------

// Function: FUN_00463bda
// Address: 00463bda
// XREFS: None
TPanelSystem * __fastcall FUN_00463bda(TPanelSystem *param_1)
{
  int *piVar1;
  char (*pacVar2) [260];
  int iVar3;
  
  param_1->ImeEnabled = 1;
  param_1->InputEnabled = 1;
  param_1->mouseOwnerValue = (TPanel *)0x0;
  param_1->keyboardOwnerValue = (TPanel *)0x0;
  param_1->modalPanelValue = (TPanel *)0x0;
  param_1->currentPanelValue = (TPanel *)0x0;
  param_1->panelListValue = (PanelNode *)0x0;
  param_1->numberActivePanelsValue = 0;
  param_1->prevCurrentChildValue = (TPanel *)0x0;
  param_1->Imc = 0;
  param_1->ImeOn = 0;
  param_1->saved_colors = 0;
  piVar1 = param_1->palette_use_count;
  pacVar2 = param_1->palette_file;
  iVar3 = 10;
  do {
    piVar1[-0x294] = 0;
    (*pacVar2)[0] = '\0';
    *piVar1 = 0;
    piVar1[10] = 0;
    piVar1 = piVar1 + 1;
    pacVar2 = pacVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  TPanelSystem::setup(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00463cf2
// Address: 00463cf2
// XREFS: None
undefined4 __fastcall FUN_00463cf2(int param_1)
{
  return *(undefined4 *)(param_1 + 0xc);
}

// --------------------------------------------------

// Function: FUN_00463d04
// Address: 00463d04
// XREFS: None
TPanel * __fastcall FUN_00463d04(int param_1)
{
  TPanel *pTVar1;
  
  if (*(TPanel **)(param_1 + 0xc) != (TPanel *)0x0) {
    pTVar1 = TPanel::previousPanel(*(TPanel **)(param_1 + 0xc));
    return pTVar1;
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: FUN_00463d1f
// Address: 00463d1f
// XREFS: None
undefined4 __fastcall FUN_00463d1f(undefined4 *param_1)
{
  return *param_1;
}

// --------------------------------------------------

// Function: FUN_00463d23
// Address: 00463d23
// XREFS: None
undefined4 __fastcall FUN_00463d23(int param_1)
{
  return *(undefined4 *)(param_1 + 4);
}

// --------------------------------------------------

// Function: FUN_00463d34
// Address: 00463d34
// XREFS: None
undefined4 __fastcall FUN_00463d34(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_00463d44
// Address: 00463d44
// XREFS: None
TPanel * __thiscall FUN_00463d44(TPanelSystem *param_1,char *param_2)
{
  PanelNode *pPVar1;
  
  pPVar1 = TPanelSystem::findPanelNode(param_1,param_2);
  if (pPVar1 != (PanelNode *)0x0) {
    return pPVar1->panel;
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: FUN_00463d68
// Address: 00463d68
// XREFS: None
undefined4 __fastcall FUN_00463d68(int param_1)
{
  return *(undefined4 *)(param_1 + 0x14);
}

// --------------------------------------------------

// Function: FUN_00463d74
// Address: 00463d74
// XREFS: None
undefined4 __thiscall FUN_00463d74(TPanelSystem *param_1,TPanel *param_2,int param_3,int param_4)
{
  char *pcVar1;
  PanelNode *pPVar2;
  
  pcVar1 = TPanel::panelName(param_2);
  pPVar2 = TPanelSystem::findPanelNode(param_1,pcVar1);
  if (pPVar2 == (PanelNode *)0x0) {
    pPVar2 = (PanelNode *)calloc(1,0xc);
    if (pPVar2 == (PanelNode *)0x0) {
      return 0;
    }
    pPVar2->panel = param_2;
    TPanel::setPreviousPanel(param_2,(TPanel *)0x0);
    pPVar2->prev_node = param_1->panelListValue->prev_node;
    pPVar2->next_node = param_1->panelListValue;
    param_1->panelListValue->prev_node = pPVar2;
    pPVar2->prev_node->next_node = pPVar2;
    param_1->numberActivePanelsValue = param_1->numberActivePanelsValue + 1;
  }
  if (param_3 != 0) {
    TPanelSystem::setCurrentPanel(param_1,param_2,param_4);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_00463e01
// Address: 00463e01
// XREFS: None
char * __thiscall FUN_00463e01(TPanelSystem *param_1,char *param_2)
{
  PanelNode *pPVar1;
  
  if (param_2 == (char *)0x0) {
    return param_2;
  }
  pPVar1 = TPanelSystem::findPanelNode(param_1,param_2);
  if (pPVar1 == (PanelNode *)0x0) {
    return (char *)0x0;
  }
  param_1->numberActivePanelsValue = param_1->numberActivePanelsValue + -1;
  pPVar1->prev_node->next_node = pPVar1->next_node;
  pPVar1->next_node->prev_node = pPVar1->prev_node;
  free(pPVar1);
  return (char *)0x1;
}

// --------------------------------------------------

// Function: FUN_00463e5a
// Address: 00463e5a
// XREFS: None
undefined4 __thiscall FUN_00463e5a(TPanelSystem *param_1,char *param_2,int param_3)
{
  PanelNode *pPVar1;
  
  pPVar1 = TPanelSystem::findPanelNode(param_1,param_2);
  if (pPVar1 != (PanelNode *)0x0) {
    if (param_1->mouseOwnerValue != (TPanel *)0x0) {
      TPanel::release_mouse(param_1->mouseOwnerValue);
    }
    param_1->modalPanelValue = (TPanel *)0x0;
    param_1->keyboardOwnerValue = (TPanel *)0x0;
    TPanelSystem::setCurrentPanel(param_1,pPVar1->panel,param_3);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00463ead
// Address: 00463ead
// XREFS: None
undefined4 __thiscall FUN_00463ead(TPanelSystem *param_1,int param_2)
{
  TPanel *this;
  int iVar1;
  TPanel *this_00;
  TPanel *pTVar2;
  char *pcVar3;
  
  if (param_1->currentPanelValue == (TPanel *)0x0) {
    return 0;
  }
  this_00 = TPanel::previousPanel(param_1->currentPanelValue);
  if (this_00 == (TPanel *)0x0) {
    return 0;
  }
  this = param_1->currentPanelValue;
  if (param_2 == 0) {
    TPanel::setPreviousPanel(this_00,this);
  }
  else {
    pTVar2 = TPanel::previousPanel(this_00);
    if (pTVar2 == this) {
      TPanel::setPreviousPanel(this_00,(TPanel *)0x0);
    }
    pcVar3 = TPanel::panelName(this);
    TPanelSystem::destroyPanel(param_1,pcVar3);
  }
  iVar1 = this_00->_padding_;
  param_1->currentPanelValue = this_00;
  (**(code **)(iVar1 + 0xc0))(1);
  (**(code **)(param_1->currentPanelValue->_padding_ + 0x20))(2);
  UpdateWindow(AppWnd);
  return 1;
}

// --------------------------------------------------

// Function: FUN_00463f3d
// Address: 00463f3d
// XREFS: None
void __thiscall FUN_00463f3d(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00463f49
// Address: 00463f49
// XREFS: None
void __thiscall FUN_00463f49(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

// --------------------------------------------------

// Function: FUN_00463f5a
// Address: 00463f5a
// XREFS: None
void __thiscall FUN_00463f5a(int param_1,TPanel *param_2)
{
  int iVar1;
  TPanel *pTVar2;
  TPanel *pTVar3;
  
  if ((*(TPanel **)(param_1 + 8) != (TPanel *)0x0) && (param_2 != (TPanel *)0x0)) {
    TPanel::setPreviousModalPanel(param_2,*(TPanel **)(param_1 + 8));
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    pTVar3 = *(TPanel **)(param_1 + 0x18);
    if ((pTVar3 == (TPanel *)0x0) || (pTVar2 = pTVar3->parent_panel, pTVar2 == (TPanel *)0x0))
    goto LAB_00463fac;
  }
  else {
    if ((*(int *)(iVar1 + 0x74) != 0) ||
       (pTVar2 = *(TPanel **)(iVar1 + 0x40), pTVar2 == (TPanel *)0x0)) goto LAB_00463fac;
    pTVar3 = *(TPanel **)(param_1 + 0x18);
  }
  TPanel::set_curr_child(pTVar2,pTVar3);
LAB_00463fac:
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(TPanel **)(param_1 + 8) = param_2;
  if ((param_2 != (TPanel *)0x0) && (param_2 != *(TPanel **)(param_1 + 0xc))) {
    pTVar2 = param_2->parent_panel;
    if (pTVar2 != (TPanel *)0x0) {
      *(TPanel **)(param_1 + 0x18) = pTVar2->curr_child;
      TPanel::set_curr_child(pTVar2,param_2);
      return;
    }
    iVar1 = param_2->_padding_;
    *(undefined4 *)(param_1 + 0x18) = 0;
    (**(code **)(iVar1 + 0xc0))(1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00463fef
// Address: 00463fef
// XREFS: None
void __fastcall FUN_00463fef(int param_1)
{
  TPanel *pTVar1;
  
  pTVar1 = *(TPanel **)(param_1 + 8);
  if ((pTVar1 != (TPanel *)0x0) && (pTVar1 != *(TPanel **)(param_1 + 0xc))) {
    TPanel::setPreviousModalPanel(*(TPanel **)(param_1 + 0xc),pTVar1);
  }
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xc);
  return;
}

// --------------------------------------------------

// Function: FUN_0046400f
// Address: 0046400f
// XREFS: None
undefined4 __fastcall FUN_0046400f(TPanelSystem *param_1)
{
  TPanel *pTVar1;
  
  if (param_1->modalPanelValue == (TPanel *)0x0) {
    return 0;
  }
  pTVar1 = TPanel::previousModalPanel(param_1->modalPanelValue);
  if (pTVar1 == (TPanel *)0x0) {
    return 0;
  }
  (**(code **)(pTVar1->_padding_ + 0xc0))(1);
  TPanelSystem::setMouseOwner(param_1,pTVar1);
  TPanelSystem::setKeyboardOwner(param_1,pTVar1);
  param_1->modalPanelValue = pTVar1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00464055
// Address: 00464055
// XREFS: None
char * __thiscall FUN_00464055(TPanelSystem *param_1,char *param_2)
{
  PanelNode *pPVar1;
  
  if (param_2 == (char *)0x0) {
    return param_2;
  }
  pPVar1 = TPanelSystem::findPanelNode(param_1,param_2);
  if (pPVar1 == (PanelNode *)0x0) {
    return (char *)0x0;
  }
  param_1->numberActivePanelsValue = param_1->numberActivePanelsValue + -1;
  if (param_1->currentPanelValue == pPVar1->panel) {
    param_1->currentPanelValue = (TPanel *)0x0;
  }
  if (param_1->mouseOwnerValue == pPVar1->panel) {
    param_1->mouseOwnerValue = (TPanel *)0x0;
  }
  if (param_1->keyboardOwnerValue == pPVar1->panel) {
    param_1->keyboardOwnerValue = (TPanel *)0x0;
  }
  if (param_1->modalPanelValue == pPVar1->panel) {
    param_1->modalPanelValue = (TPanel *)0x0;
  }
  pPVar1->prev_node->next_node = pPVar1->next_node;
  pPVar1->next_node->prev_node = pPVar1->prev_node;
  if (pPVar1->panel != (TPanel *)0x0) {
    (**(code **)pPVar1->panel->_padding_)(1);
  }
  free(pPVar1);
  return (char *)0x1;
}

// --------------------------------------------------

// Function: FUN_004640fa
// Address: 004640fa
// XREFS: None
bool __thiscall FUN_004640fa(TPanelSystem *param_1,char *param_2)
{
  PanelNode *pPVar1;
  
  pPVar1 = TPanelSystem::findPanelNode(param_1,param_2);
  return pPVar1 != (PanelNode *)0x0;
}

// --------------------------------------------------

// Function: FUN_00464113
// Address: 00464113
// XREFS: None
undefined4 __thiscall FUN_00464113(TPanelSystem *param_1,TPanel *param_2)
{
  char *pcVar1;
  PanelNode *pPVar2;
  
  if (param_2 != (TPanel *)0x0) {
    pcVar1 = TPanel::panelName(param_2);
    pPVar2 = TPanelSystem::findPanelNode(param_1,pcVar1);
    if (pPVar2 != (PanelNode *)0x0) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0046414b
// Address: 0046414b
// XREFS: None
undefined4 __fastcall FUN_0046414b(int param_1)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)calloc(1,0xc);
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar1 = 0;
  *(int *)(*(int *)(param_1 + 0x10) + 4) = *(int *)(param_1 + 0x10);
  *(int *)(*(int *)(param_1 + 0x10) + 8) = *(int *)(param_1 + 0x10);
  uVar2 = GetSysColor(5);
  *(undefined4 *)(param_1 + 0xad0) = uVar2;
  uVar2 = GetSysColor(8);
  *(undefined4 *)(param_1 + 0xad4) = uVar2;
  *(undefined4 *)(param_1 + 0xacc) = 1;
  return 1;
}

// --------------------------------------------------

// Function: FUN_004641a7
// Address: 004641a7
// XREFS: None
undefined4 * __thiscall FUN_004641a7(int param_1,byte *param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  if (param_2 != (byte *)0x0) {
    puVar5 = (undefined4 *)(*(undefined4 **)(param_1 + 0x10))[2];
    if (puVar5 != *(undefined4 **)(param_1 + 0x10)) {
      do {
        pbVar2 = (byte *)TPanel::panelName((TPanel *)*puVar5);
        pbVar4 = param_2;
        do {
          bVar1 = *pbVar2;
          bVar6 = bVar1 < *pbVar4;
          if (bVar1 != *pbVar4) {
LAB_004641f9:
            iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_004641fe;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar6 = bVar1 < pbVar4[1];
          if (bVar1 != pbVar4[1]) goto LAB_004641f9;
          pbVar2 = pbVar2 + 2;
          pbVar4 = pbVar4 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_004641fe:
      } while ((iVar3 != 0) &&
              (puVar5 = (undefined4 *)puVar5[2], puVar5 != *(undefined4 **)(param_1 + 0x10)));
    }
    if (puVar5 != *(undefined4 **)(param_1 + 0x10)) {
      pbVar4 = (byte *)TPanel::panelName((TPanel *)*puVar5);
      do {
        bVar1 = *pbVar4;
        bVar6 = bVar1 < *param_2;
        if (bVar1 != *param_2) {
LAB_00464242:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_00464247;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar6 = bVar1 < param_2[1];
        if (bVar1 != param_2[1]) goto LAB_00464242;
        pbVar4 = pbVar4 + 2;
        param_2 = param_2 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_00464247:
      if (iVar3 == 0) {
        return puVar5;
      }
    }
  }
  return (undefined4 *)0x0;
}

// --------------------------------------------------

// Function: FUN_0046425d
// Address: 0046425d
// XREFS: None
void __thiscall FUN_0046425d(TPanelSystem *param_1,TPanel *param_2)
{
  int iVar1;
  int unaff_retaddr;
  
  TPanel::setPreviousPanel(param_2,param_1->currentPanelValue);
  if (param_1->currentPanelValue != (TPanel *)0x0) {
    (**(code **)(param_1->currentPanelValue->_padding_ + 0xc0))(0);
  }
  iVar1 = param_2->_padding_;
  param_1->currentPanelValue = param_2;
  (**(code **)(iVar1 + 0xc0))(1);
  (**(code **)(param_1->currentPanelValue->_padding_ + 0x20))(2);
  UpdateWindow(AppWnd);
  if (unaff_retaddr != 0) {
    TPanelSystem::setCurrentPanelModal(param_1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004642bd
// Address: 004642bd
// XREFS: None
// [HELPER] s__s_pal: "%s.pal"
undefined4 __thiscall FUN_004642bd(int param_1,char *param_2,int param_3)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  byte *pbVar10;
  char *pcVar11;
  int iVar12;
  bool bVar13;
  byte *pbStack_10c;
  byte abStack_104 [260];
  
  if (param_2 == (char *)0x0) {
    abStack_104[0] = 0;
  }
  else {
    iVar3 = strchr(param_2,0x2e);
    if (iVar3 == 0) {
      sprintf(abStack_104,s__s_pal,param_2);
    }
    else {
      uVar7 = 0xffffffff;
      do {
        pcVar11 = param_2;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar11 = param_2 + 1;
        cVar1 = *param_2;
        param_2 = pcVar11;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pbVar10 = (byte *)(pcVar11 + -uVar7);
      pbVar4 = abStack_104;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pbVar4 = *(undefined4 *)pbVar10;
        pbVar10 = pbVar10 + 4;
        pbVar4 = pbVar4 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pbVar4 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        pbVar4 = pbVar4 + 1;
      }
    }
    strupr(abStack_104);
  }
  pbStack_10c = (byte *)(param_1 + 0x44);
  iVar3 = -1;
  iVar12 = 0;
  piVar9 = (int *)(param_1 + 0xa94);
  do {
    if (piVar9[-0x29e] == 0) {
      if (iVar3 == -1) {
        iVar3 = iVar12;
      }
    }
    else {
      if ((param_3 != -1) && (*piVar9 == param_3)) {
LAB_0046445b:
        *(int *)(param_1 + 0xa6c + iVar12 * 4) = *(int *)(param_1 + 0xa6c + iVar12 * 4) + 1;
        return *(undefined4 *)(param_1 + 0x1c + iVar12 * 4);
      }
      pbVar10 = abStack_104;
      pbVar4 = pbStack_10c;
      do {
        bVar2 = *pbVar4;
        bVar13 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_00464390:
          iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          goto LAB_00464395;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar13 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_00464390;
        pbVar4 = pbVar4 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_00464395:
      if (iVar5 == 0) goto LAB_0046445b;
    }
    iVar12 = iVar12 + 1;
    piVar9 = piVar9 + 1;
    pbStack_10c = pbStack_10c + 0x104;
  } while (iVar12 < 10);
  if (iVar3 == -1) {
    return 0;
  }
  pvVar6 = ReadPalette((char *)abStack_104,param_3,1);
  *(void **)(param_1 + 0x1c + iVar3 * 4) = pvVar6;
  if (pvVar6 == (void *)0x0) {
    return 0;
  }
  uVar7 = 0xffffffff;
  *(int *)(param_1 + 0xa6c + iVar3 * 4) = *(int *)(param_1 + 0xa6c + iVar3 * 4) + 1;
  pbVar10 = abStack_104;
  do {
    pbVar4 = pbVar10;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pbVar4 = pbVar10 + 1;
    bVar2 = *pbVar10;
    pbVar10 = pbVar4;
  } while (bVar2 != 0);
  uVar7 = ~uVar7;
  pbVar10 = pbVar4 + -uVar7;
  pbVar4 = (byte *)(param_1 + 0x44 + iVar3 * 0x104);
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pbVar4 = *(undefined4 *)pbVar10;
    pbVar10 = pbVar10 + 4;
    pbVar4 = pbVar4 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pbVar4 = *pbVar10;
    pbVar10 = pbVar10 + 1;
    pbVar4 = pbVar4 + 1;
  }
  *(int *)(param_1 + 0xa94 + iVar3 * 4) = param_3;
  return *(undefined4 *)(param_1 + 0x1c + iVar3 * 4);
}

// --------------------------------------------------

// Function: FUN_0046447b
// Address: 0046447b
// XREFS: None
void __thiscall FUN_0046447b(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = (int *)(param_1 + 0x1c);
  do {
    if (*piVar1 == param_2) {
      iVar2 = *(int *)(param_1 + 0xa6c + iVar3 * 4) + -1;
      *(int *)(param_1 + 0xa6c + iVar3 * 4) = iVar2;
      if (iVar2 == 0) {
        DeleteObject(*(undefined4 *)(param_1 + 0x1c + iVar3 * 4));
        *(undefined4 *)(param_1 + 0x1c + iVar3 * 4) = 0;
        *(undefined1 *)(param_1 + 0x44 + iVar3 * 0x104) = 0;
      }
      return;
    }
    iVar3 = iVar3 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar3 < 10);
  return;
}

// --------------------------------------------------

// Function: FUN_004644d4
// Address: 004644d4
// XREFS: None
void __fastcall FUN_004644d4(int param_1)
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xac0) != 0) {
    uVar1 = _ImmAssociateContext_8(AppWnd,0);
    *(undefined4 *)(param_1 + 0xabc) = uVar1;
    *(undefined4 *)(param_1 + 0xac0) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046450c
// Address: 0046450c
// XREFS: None
void __fastcall FUN_0046450c(int param_1)
{
  if ((*(int *)(param_1 + 0xabc) != 0) && (*(int *)(param_1 + 0xac0) == 0)) {
    _ImmAssociateContext_8(AppWnd,*(int *)(param_1 + 0xabc));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464531
// Address: 00464531
// XREFS: None
undefined4 __fastcall FUN_00464531(int param_1)
{
  return *(undefined4 *)(param_1 + 0xac0);
}

// --------------------------------------------------

// Function: FUN_00464547
// Address: 00464547
// XREFS: None
void __fastcall FUN_00464547(int param_1)
{
  if (((*(int *)(param_1 + 0xac4) == 0) && (*(int *)(param_1 + 0xac0) != 0)) &&
     (*(int *)(param_1 + 0xabc) != 0)) {
    _ImmSetOpenStatus_8(*(int *)(param_1 + 0xabc),1);
    *(undefined4 *)(param_1 + 0xac4) = 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464585
// Address: 00464585
// XREFS: None
void __fastcall FUN_00464585(int param_1)
{
  if (((*(int *)(param_1 + 0xac4) != 0) && (*(int *)(param_1 + 0xac0) != 0)) &&
     (*(int *)(param_1 + 0xabc) != 0)) {
    _ImmSetOpenStatus_8(*(int *)(param_1 + 0xabc),0);
    *(undefined4 *)(param_1 + 0xac4) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004645c5
// Address: 004645c5
// XREFS: None
undefined4 __fastcall FUN_004645c5(int param_1)
{
  return *(undefined4 *)(param_1 + 0xac4);
}

// --------------------------------------------------

// Function: FUN_004645d7
// Address: 004645d7
// XREFS: None
undefined4 __fastcall FUN_004645d7(int param_1)
{
  return *(undefined4 *)(param_1 + 0xac8);
}

// --------------------------------------------------

// Function: FUN_004645e7
// Address: 004645e7
// XREFS: None
void __fastcall FUN_004645e7(int param_1)
{
  *(undefined4 *)(param_1 + 0xac8) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_004645fb
// Address: 004645fb
// XREFS: None
void __fastcall FUN_004645fb(int param_1)
{
  *(undefined4 *)(param_1 + 0xac8) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0046460b
// Address: 0046460b
// XREFS: None
void __fastcall FUN_0046460b(int param_1)
{
  int *piVar1;
  
  for (piVar1 = *(int **)(*(int *)(param_1 + 0x10) + 8);
      (piVar1 != (int *)0x0 && (piVar1 != *(int **)(param_1 + 0x10))); piVar1 = (int *)piVar1[2]) {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0xd0))();
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0046463b
// Address: 0046463b
// XREFS: None
undefined4 __fastcall FUN_0046463b(int param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  for (piVar1 = *(int **)(*(int *)(param_1 + 0x10) + 8);
      (piVar1 != (int *)0x0 && (piVar1 != *(int **)(param_1 + 0x10))); piVar1 = (int *)piVar1[2]) {
    if (((int *)*piVar1 != (int *)0x0) &&
       (iVar2 = (**(code **)(*(int *)*piVar1 + 0xd4))(), iVar2 == 0)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

// --------------------------------------------------

// Function: FUN_0046467a
// Address: 0046467a
// XREFS: None
void __fastcall FUN_0046467a(int param_1)
{
  int iVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(param_1 + 0xacc) != 0) {
    iVar1 = GetSysColor(5);
    if ((iVar1 == *(int *)(param_1 + 0xad0)) &&
       (iVar1 = GetSysColor(8), iVar1 == *(int *)(param_1 + 0xad4))) {
      return;
    }
    uStack_10 = *(undefined4 *)(param_1 + 0xad0);
    uStack_c = *(undefined4 *)(param_1 + 0xad4);
    uStack_8 = 5;
    uStack_4 = 8;
    SetSysColors(2,&uStack_8,&uStack_10);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_004646eb
// Address: 004646eb
// XREFS: None
void __fastcall FUN_004646eb(int param_1)
{
  int *piVar1;
  
  piVar1 = (int *)(*(int **)(param_1 + 0x10))[2];
  if (piVar1 != *(int **)(param_1 + 0x10)) {
    do {
      if (*piVar1 != 0) {
        *(undefined1 *)(*piVar1 + 0xf3) = 1;
      }
      piVar1 = (int *)piVar1[2];
    } while (piVar1 != *(int **)(param_1 + 0x10));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00464715
// Address: 00464715
// XREFS: None
TPanel * __thiscall FUN_00464715(TPanel *param_1,char *param_2)
{
  param_1->previousPanelValue = (TPanel *)0x0;
  param_1->previousModalPanelValue = (TPanel *)0x0;
  param_1->pnl_x = 0;
  param_1->pnl_y = 0;
  param_1->pnl_wid = 0;
  param_1->pnl_hgt = 0;
  param_1->panelNameValue = (char *)0x0;
  param_1->render_area = (TDrawArea *)0x0;
  param_1->position_mode = PositionFixed;
  param_1->need_redraw = RedrawFull;
  param_1->curr_child = (TPanel *)0x0;
  param_1->parent_panel = (TPanel *)0x0;
  param_1->left_panel = (TPanel *)0x0;
  param_1->top_panel = (TPanel *)0x0;
  param_1->right_panel = (TPanel *)0x0;
  param_1->bottom_panel = (TPanel *)0x0;
  param_1->node = (PanelNode *)0x0;
  param_1->first_child_node = (PanelNode *)0x0;
  param_1->last_child_node = (PanelNode *)0x0;
  param_1->tab_prev_panel = (TPanel *)0x0;
  param_1->tab_next_panel = (TPanel *)0x0;
  param_1->mouse_captured = 0;
  param_1->active = 1;
  param_1->visible = 0;
  param_1->tab_stop = 0;
  param_1->have_focus = 0;
  param_1->overlapping_children = 1;
  param_1->handle_mouse_input = 1;
  param_1->just_drawn = 0;
  param_1->clip_rgn = (void *)0x0;
  param_1->left_border = 0;
  param_1->top_border = 0;
  param_1->right_border = 0;
  param_1->bottom_border = 0;
  param_1->min_wid = 0;
  param_1->max_wid = 0;
  param_1->min_hgt = 0;
  param_1->max_hgt = 0;
  param_1->mouse_hold_interval = 0xfa;
  param_1->mouse_move_tolerance = 0;
  param_1->mouse_down_x = 0;
  param_1->mouse_down_y = 0;
  param_1->mouse_down_ctrl = 0;
  param_1->mouse_down_shift = 0;
  param_1->mouse_down_time = 0;
  param_1->error_code = 0;
  param_1->z_order = 0;
  param_1->display_changed_count = 0;
  param_1->mouse_action = '\0';
  param_1->mouse_down_button = '\0';
  param_1->panel_type = '\0';
  param_1->color = '\0';
  param_1->fill_in_background = '\0';
  param_1->draw_rect2_flag = '\0';
  param_1->_padding_ = (int)&TPanel::_vftable_;
  (param_1->render_rect).left = 0;
  (param_1->render_rect).top = 0;
  (param_1->render_rect).right = 0;
  (param_1->render_rect).bottom = 0;
  TPanel::setPanelName(param_1,param_2);
  param_1->need_restore = '\0';
  param_1->help_string_id = -1;
  param_1->help_page_id = -1;
  if ((param_1->panelNameValue != (char *)0x0) && (*param_1->panelNameValue != '\0')) {
    TPanelSystem::addPanel(&panel_system,param_1,0,0);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00464882
// Address: 00464882
// XREFS: None
TPanel * __thiscall FUN_00464882(TPanel *param_1,byte param_2)
{
  TPanel::~TPanel(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------


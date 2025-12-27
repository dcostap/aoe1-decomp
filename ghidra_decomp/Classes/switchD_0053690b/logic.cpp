// Class: switchD_0053690b
// Function: caseD_3
// Address: 00536932
char switchD_0053690b::caseD_3(void)
{
  uchar uVar1;
  RGE_Visible_Map *this;
  RGE_Tile *pRVar2;
  float fVar3;
  RGE_Map *pRVar4;
  byte bVar5;
  short sVar6;
  RGE_Map *pRVar7;
  undefined4 extraout_ECX;
  RGE_Map *extraout_ECX_00;
  RGE_Map *extraout_ECX_01;
  RGE_Map *extraout_ECX_02;
  RGE_Map *extraout_ECX_03;
  RGE_Map *extraout_ECX_04;
  RGE_Map *extraout_ECX_05;
  short sVar8;
  short sVar9;
  byte bVar10;
  bool bVar11;
  RGE_Tile *pRVar12;
  RGE_View *unaff_ESI;
  int iVar13;
  uchar uStack00000013;
  short sStack00000014;
  short sStack00000018;
  short sStack0000001c;
  short sStack00000020;
  undefined2 uStack00000022;
  short in_stack_00000024;
  short sStack00000028;
  char in_stack_0000002c;
  uchar uStack00000030;
  RGE_Map *in_stack_00000038;
  RGE_Map *in_stack_0000003c;
  char in_stack_00000040;
  RGE_Map *in_stack_00000048;
  uint uStack0000004c;
  uint uStack00000050;
  int iStack00000054;
  short in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  RGE_Map *in_stack_0000006c;
  short in_stack_00000070;
  short in_stack_00000074;
  short in_stack_00000078;
  short in_stack_0000007c;
  tagPOINT *in_stack_00000094;
  tagPOINT *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  float *in_stack_000000a0;
  float *in_stack_000000a4;
  short *in_stack_000000a8;
  short *in_stack_000000ac;
  
code_r0x00536932:
  _sStack00000028 = _sStack00000028 + -1;
  _sStack00000020 =
       _sStack00000020 + CONCAT22((short)((uint)_sStack00000028 >> 0x10),unaff_ESI->tile_half_wid);
  in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
  goto switchD_0053690b_default;
  do {
    switch(in_stack_00000040) {
    case '\x01':
      _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
      _sStack00000028 = _sStack00000028 + 1;
      in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
    default:
switchD_0053690b_default:
      in_stack_00000024 = in_stack_00000024 + unaff_ESI->tile_half_hgt;
      in_stack_00000058 = in_stack_00000058 + 1;
      if (in_stack_0000007c <= in_stack_00000058) {
        if (unaff_ESI->function_mode == '\n') {
          pRVar7 = unaff_ESI->map;
          sVar9 = 0;
          if (0 < pRVar7->num_terrain) {
            do {
              iVar13 = (int)sVar9;
              sVar9 = sVar9 + 1;
              pRVar7->terrain_types[iVar13].frame_changed = '\0';
              pRVar7 = unaff_ESI->map;
            } while (sVar9 < pRVar7->num_terrain);
          }
        }
        uVar1 = unaff_ESI->function_mode;
        if ((((uVar1 == ')') || (uVar1 == '*')) || (uVar1 == '+')) && (in_stack_0000002c == '4')) {
          *in_stack_0000009c = in_stack_00000048;
        }
        return in_stack_0000002c;
      }
      _sStack00000014 = _sStack00000020;
      _sStack0000001c = in_stack_00000038;
      _sStack00000018 = in_stack_0000003c;
      iStack00000054 = 0;
      pRVar7 = in_stack_0000003c;
      if (0 < sStack00000028) {
        do {
          sVar8 = (short)_sStack0000001c;
          sVar9 = (short)_sStack00000018;
          if (((sVar8 < 0) || (pRVar7 = unaff_ESI->map, (int)pRVar7->map_width <= (int)sVar8)) ||
             ((sVar9 < 0 || ((int)pRVar7->map_height <= (int)sVar9)))) {
            uVar1 = unaff_ESI->function_mode;
            pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uVar1);
            bVar11 = false;
            if ((uVar1 == '(') || (uVar1 == '*')) goto LAB_00536221;
          }
          else {
            bVar11 = true;
LAB_00536221:
            if (bVar11) {
              this = unaff_ESI->player->visible;
              if ((this == (RGE_Visible_Map *)0x0) || (unaff_ESI->map->map_visible_flag != '\0')) {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar8,(int)sVar9);
                pRVar7 = extraout_ECX_00;
                if (uStack00000013 == '\0') {
                  uStack00000013 = 0x80;
                }
              }
              else {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar8,(int)sVar9);
                uVar1 = unaff_ESI->function_mode;
                pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)extraout_ECX >> 8),uVar1);
                if ((uVar1 == '\x1e') || (uVar1 == '\x1f')) {
                  uStack00000013 = '\x0f';
                }
              }
              if ((unaff_ESI->function_mode == '\v') &&
                 (pRVar12 = unaff_ESI->map->map_row_offset[sVar9],
                 pRVar7 = (RGE_Map *)(pRVar12 + sVar8),
                 pRVar12[sVar8].draw_as == *(uchar *)((int)&pRVar7->map + 3))) goto LAB_005362af;
            }
            else {
LAB_005362af:
              uStack00000013 = '\0';
            }
            if ((uStack00000013 != '\x0f') && (uStack00000013 != 0x80)) {
              uStack00000013 = '\0';
            }
            if (uStack00000013 == '\0') {
              uVar1 = unaff_ESI->function_mode;
              if ((((uVar1 != '\x0e') && (uVar1 != '(')) && (uVar1 != '<')) &&
                 (pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uVar1), uVar1 != '*'))
              goto LAB_005368a9;
            }
            if (bVar11) {
              pRVar2 = unaff_ESI->map->map_row_offset[sStack00000018];
              pRVar12 = pRVar2 + sStack0000001c;
              uStack00000050 = (uint)pRVar2[sStack0000001c].tile_type;
              bVar5 = (byte)pRVar12->field_0x5 >> 5;
            }
            else {
              uStack00000050 = 0;
              bVar5 = 0;
              pRVar12 = (RGE_Tile *)0x0;
            }
            sVar9 = in_stack_00000024 - (ushort)bVar5 * unaff_ESI->elev_hgt;
            switch(uStack00000050) {
            case 2:
            case 6:
            case 8:
            case 10:
            case 0xe:
            case 0xf:
            case 0x10:
              sVar9 = sVar9 - unaff_ESI->elev_hgt;
            }
            if ((((unaff_ESI->_padding_ < (int)sStack00000014) ||
                 (unaff_ESI->_padding_ < (int)sVar9)) ||
                (((int)unaff_ESI->map->tilesizes[uStack00000050].width + (int)sStack00000014 <=
                  unaff_ESI->_padding_ ||
                 (uStack00000050 =
                       (int)unaff_ESI->map->tilesizes[uStack00000050].height + (int)sVar9,
                 (int)uStack00000050 <= unaff_ESI->_padding_)))) ||
               ((unaff_ESI->function_mode == '\x0e' &&
                (((sStack0000001c < in_stack_0000005c || (in_stack_00000060 < sStack0000001c)) ||
                 ((sStack00000018 < in_stack_00000064 || (in_stack_00000068 < sStack00000018))))))))
{
              bVar11 = true;
            }
            else {
              bVar11 = false;
            }
            uVar1 = unaff_ESI->function_mode;
            pRVar7 = (RGE_Map *)CONCAT31((int3)(uStack00000050 >> 8),uVar1);
            if ((((uVar1 == '\n') || (uVar1 == '\x1e')) || (uVar1 == '\x1f')) ||
               (((uVar1 == ' ' || (uVar1 == '\x15')) || ((uVar1 == '\v' || (uVar1 == '\x0e')))))) {
              if ((!bVar11) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\n' || (uVar1 == '\v')) ||
                  (uVar1 == '\x0e')))) {
                bVar5 = pRVar12->field_0x5;
                pRVar7 = unaff_ESI->map;
                bVar10 = bVar5 & 0x1f;
                uStack0000004c = bVar5 & 0xffffff1f;
                sVar9 = pRVar7->terrain_types[bVar5 & 0x1f].terrain_to_draw;
                if (sVar9 != -1) {
                  bVar10 = (byte)sVar9;
                  uStack0000004c = (uint)bVar10;
                }
                if (((unaff_ESI->function_mode == '\n') && (unaff_ESI->calc_draw_count != 0)) &&
                   ((short)(ushort)bVar10 < pRVar7->num_terrain)) {
                  pRVar7->terrain_types[uStack0000004c].drawn =
                       pRVar7->terrain_types[uStack0000004c].drawn + '\x01';
                }
                pRVar7 = (RGE_Map *)0x0;
                if (unaff_ESI->function_mode == '\v') {
                  pRVar12->last_drawn_as = pRVar12->draw_as;
                }
              }
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\x1e' ||
                   ((uVar1 == '\x1f' || (uVar1 == ' ')))) || (uVar1 == '\x15')))) {
                pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uStack00000013);
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (pRVar7 = unaff_ESI->map, pRVar7->fog_flag == '\0')))
                   ) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                if (uVar1 == '\x1e') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->cur_render_area->SpanList;
                  pRVar7 = extraout_ECX_03;
                }
                if (unaff_ESI->function_mode == '\x1f') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  pRVar7 = (RGE_Map *)unaff_ESI->cur_render_area->SpanList;
                  unaff_ESI->cur_render_area->CurSpanList = (TSpan_List_Manager *)pRVar7;
                }
                if (unaff_ESI->function_mode == ' ') {
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\0',uStack00000030);
                  pRVar7 = extraout_ECX_04;
                }
                else {
                  if (unaff_ESI->function_mode != '\x15') goto LAB_005368a9;
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::normal_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,uStack00000030);
                  pRVar7 = extraout_ECX_05;
                }
                fog_next_shape = 0;
              }
            }
            else {
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 ((uVar1 == ')' || (((uVar1 == '*' || (uVar1 == '+')) || (uVar1 == ',')))))) {
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (unaff_ESI->map->fog_flag == '\0')))) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                pRVar4 = (RGE_Map *)
                         RGE_View::hit_object
                                   (unaff_ESI,pRVar12,sStack00000014,in_stack_00000024,
                                    sStack0000001c,sStack00000018,in_stack_00000094,
                                    in_stack_00000098,in_stack_000000a8,in_stack_000000ac,
                                    (RGE_Static_Object *)in_stack_0000006c,uStack00000030);
                pRVar7 = extraout_ECX_01;
                if (pRVar4 != (RGE_Map *)0x0) {
                  if (unaff_ESI->function_mode == ',') {
                    in_stack_0000002c = '4';
                    pRVar7 = extraout_ECX_01;
                  }
                  else {
                    if (((in_stack_0000006c != (RGE_Map *)0x0) && (pRVar4 == in_stack_0000006c)) &&
                       (in_stack_0000002c == '4')) {
                      *in_stack_0000009c = in_stack_00000048;
                      return '4';
                    }
                    if (((in_stack_00000048 == (RGE_Map *)0x0) ||
                        (((RGE_Master_Static_Object *)in_stack_00000048->map_width)->select_level <=
                         ((RGE_Master_Static_Object *)pRVar4->map_width)->select_level)) ||
                       ((pRVar7 = in_stack_00000048, in_stack_00000048 == in_stack_0000006c &&
                        (pRVar4 != in_stack_0000006c)))) {
                      pRVar7 = *(RGE_Map **)&pRVar4->tilesizes[5].height;
                      *in_stack_000000a0 = (float)pRVar7;
                      *in_stack_000000a4 = *(float *)(pRVar4->tilesizes + 6);
                      in_stack_0000002c = '4';
                      in_stack_00000048 = pRVar4;
                    }
                  }
                }
              }
              uVar1 = unaff_ESI->function_mode;
              sVar6 = (short)_sStack0000001c;
              sVar8 = (short)_sStack00000018;
              if ((uVar1 == '(') || ((uVar1 == '*' && (in_stack_0000002c == '2')))) {
                iVar13 = RGE_View::hit_tile(unaff_ESI,pRVar12,sStack00000014,sVar9,sVar6,sVar8,
                                            in_stack_00000094);
                pRVar7 = extraout_ECX_02;
                if (iVar13 != 0) {
                  if (pRVar12 == (RGE_Tile *)0x0) {
                    iVar13 = (int)sStack00000018;
                    *in_stack_000000a0 = (float)(int)sStack0000001c;
                    fVar3 = (float)iVar13;
                  }
                  else {
                    RGE_Map::tile_map_coords
                              (unaff_ESI->map,(short)in_stack_00000094->x - sStack00000014,
                               (short)in_stack_00000094->y - sVar9,pRVar12,in_stack_000000a0,
                               in_stack_000000a4);
                    iVar13 = (int)sStack0000001c;
                    *in_stack_000000a0 = (float)iVar13 + *in_stack_000000a0;
                    fVar3 = (float)(int)sStack00000018 + *in_stack_000000a4;
                  }
                  *in_stack_000000a4 = fVar3;
                  *in_stack_000000a8 = sStack00000014;
                  in_stack_0000002c = '3';
                  *in_stack_000000ac = sVar9;
                  *in_stack_0000009c = pRVar12;
                  pRVar7 = (RGE_Map *)CONCAT22((short)((uint)iVar13 >> 0x10),sVar9);
                }
              }
              else if (((uVar1 == '<') && (pRVar7 = _sStack0000001c, sVar6 == in_stack_00000070)) &&
                      (sVar8 == in_stack_00000074)) {
                *in_stack_000000a0 = (float)(int)sVar6;
                *in_stack_000000a4 = (float)(int)sVar8;
                *in_stack_000000a8 = sStack00000014;
                *in_stack_000000ac = sVar9;
                *in_stack_0000009c = pRVar12;
                return '3';
              }
            }
          }
LAB_005368a9:
          pRVar7 = (RGE_Map *)CONCAT22((short)((uint)pRVar7 >> 0x10),unaff_ESI->tile_wid);
          _sStack00000014 = (int)&((RGE_Map *)(pRVar7->tilesizes + -4))->_padding_ + _sStack00000014
          ;
          _sStack0000001c = (RGE_Map *)((int)&_sStack0000001c->_padding_ + 1);
          _sStack00000018 = (RGE_Map *)((int)&_sStack00000018->_padding_ + 1);
          iStack00000054 = iStack00000054 + 1;
        } while ((short)iStack00000054 < sStack00000028);
      }
      if ((in_stack_00000040 == '\x01') && (sStack00000028 == in_stack_00000078)) {
        in_stack_00000040 = '\x02';
      }
      break;
    case '\x02':
      goto code_r0x00536932;
    case '\x03':
      in_stack_00000040 = '\x04';
      _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
      in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
      break;
    case '\x04':
      _sStack00000020 =
           _sStack00000020 + CONCAT22((short)((uint)pRVar7 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
      in_stack_00000040 = '\x03';
      break;
    }
  } while( true );
}

// --------------------------------------------------


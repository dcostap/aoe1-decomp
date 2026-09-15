#include "../include/diam_map.h"
#include "../include/game_globals.h"

#include <stdlib.h>
#include <string.h>

#pragma function(memset)

RGE_Diamond_Map::RGE_Diamond_Map() {
  world = 0;
  player = 0;
  map = 0;
  repos_mouse = 0;
  last_player = 0;
  map_image_start_y = 0;
  map_image_lines = 0;
  map_tile_rows = 0;
  map_image_wid = 0;
  map_image_hgt = 0;
  map_tile_row_cnt = 0;
  map_row_step = 0.0f;
  map_tile_draw_hgt = 0;
  map_tile_draw_wid = 0;
  map_col_ratio = 0.0f;
  map_row_ratio = 0.0f;
  save_area = 0;
  own_save_area = 0;

  view_col = -1;
  view_row = -1;
  render_all = 1;
  fog_color = 0xFF;

  view_rect.left = 0;
  view_rect.top = 0;
  view_rect.right = 0;
  view_rect.bottom = 0;
  main_view = 0;
  scrolling = 0;
  draw_objects_mode = 0;
  cur_player_bit = 0;
}

RGE_Diamond_Map::~RGE_Diamond_Map() {
  this->delete_surfaces();
  if (this->map_tile_rows != 0) {
    free((void *)this->map_tile_rows);
    this->map_tile_rows = 0;
  }
  if (this->map_image_lines != 0) {
    free((void *)this->map_image_lines);
    this->map_image_lines = 0;
  }
}

long RGE_Diamond_Map::setup(TDrawArea *render_area_in, TPanel *parent_panel_in,
                            long x_in, long y_in, long wid_in, long hgt_in,
                            unsigned char color_in, int all_visible_in,
                            TDrawArea *save_area_in) {
  this->save_area = save_area_in;
  this->own_save_area = 0;
  TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in,
                color_in);
  return 1;
}

int RGE_Diamond_Map::set_bitmap(char *map_bmp, long res_id) {
  TPicture *picture;
  short pic_hgt;
  short pic_wid;
  char *pic_line;
  short pic_pitch;
  short y;
  if (this->map_image_lines != 0) {
    free(this->map_image_lines);
    this->map_image_lines = 0;
  }
  if (this->map_tile_rows != 0) {
    free(this->map_tile_rows);
    this->map_tile_rows = 0;
  }

  picture = new TPicture(map_bmp, res_id, 0, 0, 0);
  if (picture == 0)
    return 0;
  if (picture->Dib == 0) {
    delete picture;
    return 0;
  }
  pic_hgt = (short)picture->Height;
  pic_wid = (short)picture->Width;
  this->map_image_lines = (RGE_Map_Image_Line *)calloc(pic_hgt, 6);

  if (picture->Orien == 1) {
    pic_line = (char *)picture->Bits;
    pic_pitch = (short)picture->AlignedWidth();
  } else {
    pic_line =
        (char *)(picture->AlignedWidth() * (pic_hgt - 1) + (long)picture->Bits);
    pic_pitch = -(short)picture->AlignedWidth();
  }

  this->map_image_start_y = -1;
  this->map_image_wid = 0;
  this->map_image_hgt = 0;

  y = 0;
  if (pic_hgt > 0) {
    do {
      short start_x = -1;
      short x = 0;
      char *p = pic_line;

      if (pic_wid > 0) {
        for (; x < pic_wid; ++p, ++x) {
          if (*p == -1) {
            start_x = x;
            break;
          }
        }
      }

      if (start_x != -1) {
        short line_len = 0;
        while (x < pic_wid && *p == -1) {
          ++line_len;
          ++p;
          ++x;
        }

        this->map_image_lines[this->map_image_hgt].start_x = start_x;
        this->map_image_lines[this->map_image_hgt].line_len = line_len;
        ++this->map_image_hgt;
        if (line_len > this->map_image_wid) {
          this->map_image_wid = line_len;
        }
        if (this->map_image_start_y == -1) {
          this->map_image_start_y = y;
        }
      }

      pic_line += pic_pitch;
      ++y;
    } while (y < pic_hgt);
  }

  delete picture;
  if (this->world != 0) {
    this->set_world(this->world);
  }
  return 1;
}

void RGE_Diamond_Map::set_world(RGE_Game_World *world_in) {
  short line;
  float tile_row;
  short draw_wid;
  short tot_draw_wid;
  float col_step;

  this->world = world_in;
  if (world_in != 0 && this->map_image_lines != 0) {
    this->map = world_in->map;
    this->map_wid = (short)this->map->map_width;
    this->map_tile_row_cnt =
        this->map_wid + (this->map_hgt = (short)this->map->map_height) - 1;

    if (this->map_tile_rows != 0) {
      free(this->map_tile_rows);
    }
    this->map_tile_rows =
        (RGE_Map_Tile_Row *)calloc(this->map_tile_row_cnt, 0x24);

    tile_row = 0;
    this->map_row_step =
        (float)this->map_tile_row_cnt / (float)this->map_image_hgt;
    if (this->map_tile_row_cnt > this->map_image_hgt) {
      tile_row =
          ((float)this->map_tile_row_cnt / (float)this->map_image_hgt) * 0.5f;
    }

    float ratio_sum = 0.0f;
    tot_draw_wid = 0;
    line = 0;
    if (this->map_image_hgt > 0) {
      do {
        short line_len = this->map_image_lines[line].line_len;
        short row = (short)tile_row;

        if (row >= this->map_tile_row_cnt) {
          row = this->map_tile_row_cnt - 1;
        }

        this->map_image_lines[line].tile_row = row;

        short row_len_tiles;
        if (row < this->map_wid) {
          row_len_tiles = this->map_hgt;
          if (row < row_len_tiles) {
            row_len_tiles = row + 1;
          }
        } else {
          row_len_tiles = this->map_hgt - row - 1 + this->map_wid;
        }

        col_step = (float)row_len_tiles / (float)line_len;
        float draw_step = 1.0f / col_step;
        draw_wid = (short)draw_step;
        if ((float)draw_wid != draw_step) {
          ++draw_wid;
        }

        this->map_tile_rows[row].image_line = line;
        this->map_tile_rows[row].draw = 1;
        this->map_tile_rows[row].row_len = row_len_tiles;
        this->map_tile_rows[row].col_step = col_step;
        this->map_tile_rows[row].draw_wid = draw_wid;
        this->map_tile_rows[row].draw_step = draw_step;
        this->map_tile_rows[row].num_tiles =
            (short)((float)line_len / draw_step);
        this->map_tile_rows[row].ratio =
            (float)line_len / (float)row_len_tiles;
        this->map_tile_rows[row].col_extra =
            this->map_tile_rows[row].ratio < 1.0f ? col_step * 0.5f : 0.0f;

        if (row < this->map_wid) {
          this->map_tile_rows[row].map_row = 0;
          this->map_tile_rows[row].map_col = this->map_wid - row - 1;
        } else {
          this->map_tile_rows[row].map_row = row - this->map_wid + 1;
          this->map_tile_rows[row].map_col = 0;
        }

        tot_draw_wid += draw_wid;
        ratio_sum += this->map_tile_rows[row].ratio;
        ++line;
        tile_row += this->map_row_step;
      } while (line < this->map_image_hgt);
    }

    float draw_height = 1.0f / this->map_row_step;
    this->map_tile_draw_hgt = (short)draw_height;
    if ((float)this->map_tile_draw_hgt != draw_height) {
      ++this->map_tile_draw_hgt;
    }

    this->map_tile_draw_wid = tot_draw_wid / this->map_image_hgt;
    if (this->map_tile_draw_wid == 0) {
      this->map_tile_draw_wid = 1;
    }

    this->map_col_ratio = ratio_sum / (float)this->map_image_hgt;
    this->map_row_ratio =
        (float)this->map_image_hgt / (float)this->map_tile_row_cnt;

    short row = 0;
    short source_row = 0;
    if (this->map_tile_row_cnt > 0) {
      do {
        unsigned char draw = this->map_tile_rows[row].draw;
        if (draw != 0) {
          source_row = row;
        } else {
          this->map_tile_rows[row].image_line =
              this->map_tile_rows[source_row].image_line;
          this->map_tile_rows[row].row_len =
              this->map_tile_rows[source_row].row_len;
          this->map_tile_rows[row].col_step =
              this->map_tile_rows[source_row].col_step;
          this->map_tile_rows[row].draw_wid =
              this->map_tile_rows[source_row].draw_wid;
          this->map_tile_rows[row].draw_step =
              this->map_tile_rows[source_row].draw_step;
          this->map_tile_rows[row].num_tiles =
              this->map_tile_rows[source_row].num_tiles;
          this->map_tile_rows[row].ratio =
              this->map_tile_rows[source_row].ratio;
          this->map_tile_rows[row].col_extra =
              this->map_tile_rows[source_row].col_extra;
        }
        ++row;
      } while (row < this->map_tile_row_cnt);
    }

    this->view_col = -1;
    this->view_row = -1;
    this->set_redraw(TPanel::RedrawImmediate);
    return;
  }

  this->map = 0;
}

void RGE_Diamond_Map::set_player(RGE_Player *player_in) {
  this->player = player_in;
  this->set_redraw(TPanel::RedrawImmediate);
}

void RGE_Diamond_Map::set_redraw(TPanel::RedrawMode redraw_mode) {
  TPanel::set_redraw(redraw_mode);
  if (redraw_mode == 2) {
    this->render_all = 1;
  }
}

void RGE_Diamond_Map::delete_surfaces() {
  if (this->save_area != 0 && this->own_save_area != 0) {
    delete this->save_area;
    this->save_area = 0;
    this->own_save_area = 0;
  }
}

int RGE_Diamond_Map::create_surfaces() {
  if (this->save_area == 0) {
    TDrawArea *da = new TDrawArea("Diamond map (restored)", 0);
    this->save_area = da;
    if (da == 0) {
      return 0;
    }
    if (!da->Init(this->render_area->DrawSystem, this->pnl_wid, this->pnl_hgt,
                  0, 0)) {
      delete this->save_area;
      this->save_area = 0;
      return 0;
    }
    this->own_save_area = 1;
  } else if (this->own_save_area) {
    this->save_area->SetSize(this->pnl_wid, this->pnl_hgt, 0);
  }
  return 1;
}

extern RGE_Base_Game *rge_base_game;

void RGE_Diamond_Map::draw() {
  if (this->render_area == 0 || this->save_area == 0 || this->visible == 0 ||
      this->active == 0) {
    this->need_redraw = 0;
    return;
  }

  if (this->map != 0 && this->player != 0 && this->map_image_lines != 0 &&
      this->map_tile_rows != 0) {
    this->draw_setup(0);
    this->cur_player_bit = 1 << this->world->curr_player;

    if (this->render_all != 0) {
      if (this->parent_panel != 0) {
        this->parent_panel->draw_rect(&this->clip_rect);
        this->render_area->Copy(this->save_area, 0, 0, &this->render_rect, 0);
        this->clear_image();
      } else {
        this->save_area->Clear(0, this->color);
      }
      this->draw_all_tiles();
      this->render_all = 0;
    } else {
      this->draw_explored_tiles();
    }

    this->copy_image();
    if (rge_base_game->game_mode != 0x15)
      this->draw_selected_area();
    this->draw_objects();

    if (this->render_area->Lock("diam_map::draw", 1) != 0) {
      this->draw_view_rect();
      this->render_area->Unlock("diam_map::draw");
    }

    this->draw_finish();
    this->player->diam_tile_list.del_list();
    return;
  }

  this->draw_setup(0);
  if (this->map_image_lines != 0) {
    this->clear_image();
    this->copy_image();
    this->draw_finish();
    return;
  }

  if (this->parent_panel != 0) {
    this->parent_panel->draw_rect(&this->clip_rect);
    this->draw_finish();
    return;
  }

  this->render_area->Clear(&this->clip_rect, this->color);
  this->draw_finish();
}

void RGE_Diamond_Map::clear_image() {
  unsigned char *p;
  TDrawArea *save_area;
  short pi;
  if (this->save_area->Lock("diam_map::clear_image", 1) == 0)
    return;

  save_area = this->save_area;

  if (save_area->Orien == 1) {
    p = save_area->Bits +
        (int)this->map_image_start_y * save_area->Pitch;
    pi = (short)save_area->Pitch;
  } else {
    p = save_area->Bits +
        ((save_area->Height - (int)this->map_image_start_y) - 1) *
            save_area->Pitch;
    pi = -(short)save_area->Pitch;
  }

  RGE_Map_Image_Line *line = this->map_image_lines;
  short y = (short)this->pnl_y + this->map_image_start_y;
  short end_y = this->map_image_hgt + y;

  for (; y < end_y; y++) {
    if ((int)y >= this->clip_rect.top &&
        (int)y <= this->clip_rect.bottom) {
      short sx = line->start_x;
      short s2 = (short)this->pnl_x + sx;
      short ex = s2 + line->line_len - 1;

      if ((int)s2 < this->clip_rect.left) {
        sx += (short)(this->clip_rect.left - (int)s2);
        s2 = (short)this->clip_rect.left;
      }
      if ((int)ex > this->clip_rect.right)
        ex = (short)this->clip_rect.right;

      if ((int)s2 >= this->clip_rect.left &&
          (int)ex <= this->clip_rect.right)
        memset(p + sx, this->color, (int)ex - (int)s2 + 1);
    }
    line++;
    p += (int)pi;
  }

  this->save_area->Unlock("diam_map::clear_image");
}

void RGE_Diamond_Map::copy_image() {
  RECT r;
  r.left = 0;
  r.top = 0;
  r.right = this->pnl_wid - 1;
  r.bottom = this->pnl_hgt - 1;
  this->save_area->Copy(this->render_area, this->pnl_x, this->pnl_y, &r, 0);
}

void RGE_Diamond_Map::draw_all_tiles() {
  if (this->save_area->Lock("diam_map::draw_all_tiles", 1) == 0) {
    return;
  }

  for (short y = 0; y < this->map_hgt; ++y) {
    for (short x = 0; x < this->map_wid; ++x) {
      this->draw_tile(x, y, 0, 0);
    }
  }

  this->save_area->Unlock("diam_map::draw_all_tiles");
}

void RGE_Diamond_Map::draw_explored_tiles() {
  RGE_Tile_List_Node *list;
  int list_size;

  this->player->diam_tile_list.get_list_info(list, list_size);

  if (list_size > 0) {
    if (this->save_area->Lock("diam_map::draw_explored_tiles", 1)) {
      int i;
      i = 0;
      while (i < list_size) {
        this->draw_tile((short)list->col, (short)list->row, 0, 0);
        i++;
        list++;
      }
      this->save_area->Unlock("diam_map::draw_explored_tiles");
    }
  }
}

void RGE_Diamond_Map::draw_tile(short col, short row, int fog,
                                unsigned char override_color) {
  RGE_Map_Tile_Row *tile_row =
      this->map_tile_rows + this->map_wid + row - col - 1;
  if (tile_row->draw == 0)
    return;

  RGE_Map *map = this->map;
  RGE_Tile **map_rows = map->map_row_offset;
  RGE_Tile *tile = map_rows[row] + col;

  if (map->map_visible_flag == 0 &&
      (this->player->mutualExploredMask & unified_map_offsets[row][col]) == 0)
    return;

  short min_coord = row;
  if (col < row)
    min_coord = col;

  short draw_offset;
  int draw = 0;
  if (tile_row->ratio < 1.0f) {
    float position = (float)min_coord * tile_row->ratio;
    draw_offset = (short)position;
    if (position - (float)draw_offset < tile_row->ratio)
      draw = 1;
  } else {
    draw_offset = (short)((float)min_coord * tile_row->draw_step);
    draw = 1;
  }

  if (draw == 0)
    return;

  short image_line = tile_row->image_line;
  long x = this->map_image_lines[image_line].start_x + draw_offset;
  long y = this->map_image_start_y + image_line;
  unsigned char terrain = tile->terrain_type;

  if (fog != 0) {
    x += this->pnl_x;
    y += this->pnl_y;
    short draw_wid = tile_row->draw_wid;
    if (this->map_tile_draw_hgt == 1) {
      if (draw_wid == 1) {
        this->render_area->SetPixel(x, y, this->fog_color);
      } else if (draw_wid == 2) {
        this->render_area->SetPixel(x, y, this->fog_color);
        this->render_area->SetPixel(x + 1, y, this->fog_color);
      } else if (draw_wid > 0) {
        do {
          this->render_area->SetPixel(x, y, this->fog_color);
          ++x;
          --draw_wid;
        } while (draw_wid != 0);
      }
    } else {
      short draw_row = 0;
      while (draw_row < this->map_tile_draw_hgt) {
        short width = draw_wid;
        long pixel_x = x;
        if (width > 0) {
          do {
            this->render_area->SetPixel(pixel_x, y + draw_row,
                                        this->fog_color);
            ++pixel_x;
            --width;
          } while (width != 0);
        }
        ++draw_row;
      }
    }
    return;
  }

  if (override_color == 0) {
    switch (tile->tile_type) {
    case 0:
      override_color = map->terrain_types[terrain].map_med_color;
      break;

    case 1:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 12:
    case 13:
    case 15:
      override_color = map->terrain_types[terrain].map_low_color;
      break;

    case 2:
    case 3:
    case 6:
    case 10:
    case 11:
    case 14:
    case 16:
      override_color = map->terrain_types[terrain].map_hi_color;
      break;
    }
  }

  short trow;
  for (trow = row - 1; trow < row + 2; ++trow) {
    if (trow < 0 || trow >= this->map_hgt)
      continue;

    short j;
    for (j = col - 1; j < col + 2; ++j) {
      if (j < 0 || j >= this->map_wid)
        continue;

      RGE_Object_Node *node = map_rows[trow][j].objects.list;
      while (node != 0) {
        if (node->node->master_obj->map_draw_level == 4) {
          override_color = node->node->master_obj->map_color;
          break;
        }
        node = node->next;
      }
    }
  }

  short draw_wid = tile_row->draw_wid;
  if (this->map_tile_draw_hgt == 1) {
    if (draw_wid == 1) {
      this->save_area->SetPixel(x, y, override_color);
    } else if (draw_wid == 2) {
      this->save_area->SetPixel(x, y, override_color);
      this->save_area->SetPixel(x + 1, y, override_color);
    } else if (draw_wid > 0) {
      do {
        this->save_area->SetPixel(x, y, override_color);
        ++x;
        --draw_wid;
      } while (draw_wid != 0);
    }
  } else {
    short draw_row = 0;
    while (draw_row < this->map_tile_draw_hgt) {
      short width = draw_wid;
      long pixel_x = x;
      if (width > 0) {
        do {
          this->save_area->SetPixel(pixel_x, y + draw_row, override_color);
          ++pixel_x;
          --width;
        } while (width != 0);
      }
      ++draw_row;
    }
  }
}

void RGE_Diamond_Map::draw_selected_area(void) {
  if (this->main_view == 0)
    return;

  long sel_col1, sel_row1, sel_col2, sel_row2;
  if (!this->main_view->get_selection_area(sel_col1, sel_row1, sel_col2,
                                           sel_row2, 1))
    return;

  if (!this->render_area->Lock("diam_map::draw_selected_area", 1))
    return;

  int y;
  for (y = sel_row1; y <= sel_row2; y++) {
    int x;
    for (x = sel_col1; x <= sel_col2; x++) {
      draw_tile((short)x, (short)y, 1, 0);
    }
  }

  this->render_area->Unlock("diam_map::draw_selected_area");
}

void RGE_Diamond_Map::draw_objects() {
  RGE_Object_Node *node;
  RGE_Static_Object *object;
  RGE_Player *player;
  unsigned char color2;
  unsigned char color1;
  short i;
  short j;

  if (this->render_area->Lock("diam_map::draw_objects", 1) == 0)
    return;

  this->draw_objects_mode = 1;
  for (node = this->world->players[0]->objects->list; node != 0;
       node = node->next) {
    if (node->node != 0)
      this->draw_visible_object(node->node, 0xFF, 0xFF);
  }

  this->draw_objects_mode = 2;
  i = 1;
  if (i < this->world->player_num) {
    do {
      player = this->world->players[i];
      color1 = player->color_table->map_color;
      color2 = player->color_table->map_color;

      for (node = player->doppleganger_objects->list; node != 0;
           node = node->next) {
        if (node->node != 0)
          this->draw_visible_object(node->node, color1, color2);
      }

      for (node = player->objects->list; node != 0; node = node->next) {
        object = node->node;
        if (object != 0 && (object->selected & 1) == 0 &&
            (object->owner != this->player || object->underAttack() == 0)) {
          this->draw_visible_object(object, color1, color2);
        }
      }

      ++i;
    } while (i < this->world->player_num);
  }

  if (this->player->sel_count > 0) {
    this->draw_objects_mode = 3;
    i = 0;
    j = 0;
    while (i < 25 && j < this->player->sel_count) {
      object = this->player->sel_list[i];
      if (object != 0) {
        this->draw_visible_object(object, 0xFF, 0xFF);
        ++j;
      }
      ++i;
    }
  }

  this->draw_objects_mode = 4;
  color1 = this->player->color_table->map_color;
  color2 = this->player->color_table->map_color;
  for (node = this->player->objects->list; node != 0; node = node->next) {
    object = node->node;
    if (object != 0 && object->underAttack() != 0)
      this->draw_visible_object(object, color1, color2);
  }

  this->render_area->Unlock("diam_map::draw_objects");
}

void RGE_Diamond_Map::draw_visible_object(RGE_Static_Object *game_obj,
                                           unsigned char color1,
                                           unsigned char color2) {
  unsigned char visible;
  unsigned char draw_level;
  unsigned long map_value;
  short col;
  short row;
  RGE_Player *player;

  if (game_obj->tile == 0)
    return;

  col = (short)(long)game_obj->world_x;
  row = (short)(long)game_obj->world_y;
  player = this->player;

  if (player->visible == 0) {
    visible = 0x0F;
  } else if (this->map->map_visible_flag != 0 &&
             this->map->fog_flag == 0) {
    visible = 0x0F;
  } else {
    map_value = unified_map_offsets[(short)row][(short)col];
    visible = 0;
    if ((player->mutualExploredMask & map_value) != 0)
      visible = 0x80;
    if ((player->mutualVisibleMask & map_value) != 0)
      visible = 0x0F;
    if (this->map->map_visible_flag != 0 && visible == 0)
      visible = 0x80;
    if (this->map->fog_flag == 0 && visible == 0x80)
      visible = 0x0F;
  }

  if (visible != 0x0F &&
      (visible != 0x80 || game_obj->master_obj->fog_flag == 0))
    return;

  if (game_obj->type == 0x19) {
    RGE_Doppleganger_Object *doppleganger =
        static_cast<RGE_Doppleganger_Object *>(game_obj);

    if (visible == 0x0F)
      return;

    if (player->mutualAlly[game_obj->owner->id] == 1 &&
        (this->cur_player_bit & doppleganger->CantSeeBits) == 0) {
      draw_level = doppleganger->map_draw_level;
      color1 = doppleganger->map_color;
      color2 = color1;
    } else {
      draw_level = 0;
      color1 = 0xFF;
      color2 = 0xFF;
    }
  } else {
    draw_level = game_obj->master_obj->map_draw_level;
    if (draw_level == 3)
      color1 = game_obj->master_obj->map_color;
  }

  switch (draw_level) {
  case 2:
    this->draw_object(col, row, color1, 2, game_obj);
    return;
  case 1:
    this->draw_object(col, row, color2, 1, game_obj);
    break;
  case 3:
    this->draw_object(col, row, color1, 2, game_obj);
    break;
  }
}

void RGE_Diamond_Map::draw_object(short col, short row, unsigned char color,
                                  short size, RGE_Static_Object *game_obj) {
  short max_coord = row;
  int row_index = (int)this->map_wid + (int)row - (int)col;
  RGE_Map_Tile_Row *tile_row = this->map_tile_rows + row_index - 1;

  if (col < row)
    max_coord = col;

  short x_offset;
  if (tile_row->ratio < 1.0f) {
    x_offset = (short)((float)max_coord * tile_row->ratio);
  } else {
    x_offset = (short)((float)max_coord * tile_row->draw_step);
  }

  short image_line = tile_row->image_line;
  short x = this->map_image_lines[image_line].start_x;
  x = x + (short)this->pnl_x + x_offset;

  short y = (short)this->pnl_y + this->map_image_start_y + image_line;

  if (size == 1) {
    this->render_area->FillRect(x - 1, y - 1, x + 1, y + 1, color);
    return;
  }
  if (size == 2) {
    this->render_area->FillRect(x, y - 1, x, y + 1, color);
    this->render_area->FillRect(x - 1, y, x + 1, y, color);
    return;
  }
  if (size == 3) {
    this->render_area->FillRect(x - 3, y, x + 3, y + 1, color);
    this->render_area->FillRect(x - 2, y - 1, x + 2, y + 2, color);
    return;
  }
  if (size == 4) {
    this->render_area->FillRect(x - 2, y - 2, x + 2, y + 2, color);
  }
}

void RGE_Diamond_Map::draw_clipped_horz_line(
    short x, short y, short len, unsigned char color,
    RGE_Map_Image_Line *image_line) {
  short start_x = image_line->start_x;
  int line_start = this->pnl_x + (int)start_x;

  if ((int)x < line_start) {
    x = (short)this->pnl_x + start_x;
  }

  if (image_line->line_len + line_start <= len - 1 + (int)x) {
    len = (short)this->pnl_x - x + image_line->line_len + start_x;
  }

  this->render_area->DrawHorzLine(x, y, len, color);
}

void RGE_Diamond_Map::draw_view_rect() {
  short col = (short)(long)this->player->view_x;
  long row = (long)this->player->view_y;

  if (col != this->view_col || (short)row != this->view_row) {
    if (col < 0 || col >= this->map->map_width || (short)row < 0 ||
        (short)row >= this->map->map_height) {
      return;
    }

    RGE_Map_Tile_Row *tile_row =
        &this->map_tile_rows[(int)this->map_wid -
                             (int)(short)(long)this->player->view_x +
                             (int)(short)(long)this->player->view_y - 1];

    short min_coord = (short)row;
    if (col < (short)row) {
      min_coord = col;
    }

    short x_offset;
    if (tile_row->ratio < 1.0f) {
      x_offset = (short)((float)min_coord * tile_row->ratio);
    } else {
      x_offset = (short)((float)min_coord * tile_row->draw_step);
    }

    short image_line = tile_row->image_line;
    short map_x = (short)this->pnl_x +
                  this->map_image_lines[image_line].start_x + x_offset;
    short map_y =
        (short)this->pnl_y + this->map_image_start_y + image_line;
    short vwid;
    short vhgt;
    this->main_view->get_max_size(&vwid, &vhgt);

    this->view_rect.left =
        (long)((float)map_x - (float)(vwid / 2) * this->map_col_ratio);
    this->view_rect.top =
        (long)((float)map_y - (float)vhgt * this->map_row_ratio);
    this->view_rect.right =
        (long)((float)map_x +
               (float)(vwid / 2 + 2) * this->map_col_ratio);
    this->view_rect.bottom =
        (long)((float)map_y + (float)(vhgt + 4) * this->map_row_ratio);

    this->view_col = col;
    this->view_row = (short)row;
  }

  for (long y = this->view_rect.top; y <= this->view_rect.bottom; ++y) {
    long image_top = this->pnl_y + (long)this->map_image_start_y;
    if (y < image_top ||
        y > image_top + (long)this->map_image_hgt - 1) {
      continue;
    }

    RGE_Map_Image_Line *line =
        &this->map_image_lines[y - this->map_image_start_y - this->pnl_y];
    long left = this->view_rect.left;
    long right = this->view_rect.right;

    if (y == this->view_rect.top || y == this->view_rect.bottom) {
      long line_start = this->pnl_x + (long)line->start_x;
      long line_end = line_start + (long)line->line_len;
      if (left < line_end && right >= line_start) {
        if (left < line_start) {
          left = line_start;
        }
        if (right >= line_end) {
          right = line_end - 1;
        }
        this->render_area->DrawHorzLine(left, y, right - left + 1, 0xFF);
      }
    } else {
      long line_start = this->pnl_x + (long)line->start_x;
      long line_end = line_start + (long)line->line_len;
      if (left < line_end && left >= line_start) {
        this->render_area->SetPixel(left, y, 0xFF);
      }
      line_start = this->pnl_x + (long)line->start_x;
      line_end = line_start + (long)line->line_len;
      if (right < line_end && right >= line_start) {
        this->render_area->SetPixel(right, y, 0xFF);
      }
    }
  }
}

int RGE_Diamond_Map::pick_tile(long x, long y, short *col, short *row,
                               RGE_Tile **tile) {
  if (this->map == 0) {
    return 0;
  }

  if (this->map_image_lines == 0) {
    return 0;
  }

  int adjusted_x = x - this->pnl_x;
  int adjusted_y = y - this->pnl_y;

  if (adjusted_y >= this->map_image_start_y &&
      adjusted_y <= this->map_image_start_y + this->map_image_hgt - 1) {
    int line_idx = adjusted_y - this->map_image_start_y;
    RGE_Map_Image_Line *line = &this->map_image_lines[line_idx];

    if (adjusted_x >= line->start_x &&
        adjusted_x <= line->start_x + line->line_len - 1) {
      int tile_adjusted_x = adjusted_x - line->start_x;
      RGE_Map_Tile_Row *tile_row_ptr = &this->map_tile_rows[line->tile_row];

      long col_offset = (long)(tile_adjusted_x * tile_row_ptr->col_step +
                               tile_row_ptr->col_extra);

      short result_col = tile_row_ptr->map_col + (short)col_offset;
      short result_row = tile_row_ptr->map_row + (short)col_offset;

      if (col != 0) {
        *col = result_col;
      }
      if (row != 0) {
        *row = result_row;
      }
      if (tile != 0) {
        *tile = this->map->map_row_offset[result_row] + result_col;
      }
      return 1;
    }
  }
  return 0;
}

long RGE_Diamond_Map::handle_size(long win_wid, long win_hgt) {
  this->TPanel::handle_size(win_wid, win_hgt);
  this->view_col = -1;
  this->view_row = -1;
  this->create_surfaces();
  return 0;
}

void RGE_Diamond_Map::start_scroll_view(long x, long y) {
  short col, row;
  RGE_Tile *tile;

  if (pick_tile(x, y, &col, &row, &tile)) {
    this->capture_mouse();

    this->scrolling = 1;
    this->player->set_view_loc((float)col + 0.5f, (float)row + 0.5f);

    this->set_redraw(TPanel::RedrawNormal);

    if (this->main_view) {
      this->main_view->set_redraw(TPanel::RedrawNormal);
    }

    this->mouse_last_x = x;
    this->mouse_last_y = y;
  }
}

void RGE_Diamond_Map::handle_scroll_view(long x, long y) {
  short col;
  short row;
  RGE_Tile *tile;
  if (this->pick_tile(x, y, &col, &row, &tile) != 0) {
    this->player->set_view_loc((float)col + 0.5f, (float)row + 0.5f);

    this->set_redraw(TPanel::RedrawNormal);

    if (this->main_view != 0) {
      this->main_view->set_redraw(TPanel::RedrawNormal);
    }

    this->mouse_last_x = x;
    this->mouse_last_y = y;
  }
}

void RGE_Diamond_Map::end_scroll_view() {
  this->scrolling = 0;
  this->release_mouse();
}

int RGE_Diamond_Map::is_inside(long x, long y) {
  short col;
  short row;
  RGE_Tile *tile;

  if (TPanel::is_inside(x, y))
    return this->pick_tile(x, y, &col, &row, &tile);
  return 0;
}

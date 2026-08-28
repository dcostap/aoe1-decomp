#include "../include/diam_map.h"

#include <stdlib.h>
#include <string.h>

extern const float DAT_0056f5fc;
extern const float DAT_0056f600;
extern const float DAT_0056f604;
extern char s_draw_explored_tiles[];

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

long RGE_Diamond_Map::setup(TDrawArea *param_1, TPanel *param_2, long param_3,
                            long param_4, long param_5, long param_6,
                            unsigned char param_7, int param_8,
                            TDrawArea *param_9) {
  this->save_area = param_9;
  this->own_save_area = 0;
  TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
  return 1;
}

int RGE_Diamond_Map::set_bitmap(char *name, long param_2) {
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

  picture = new TPicture(name, param_2, 0, 0, 0);
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

void RGE_Diamond_Map::set_world(RGE_Game_World *world) {
  short line;
  float tile_row;
  short draw_wid;
  short tot_draw_wid;
  float col_step;

  this->world = world;
  if (world != 0 && this->map_image_lines != 0) {
    this->map = world->map;
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
        float draw_step =
            DAT_0056f604 / ((float)row_len_tiles / (float)line_len);
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
        this->map_tile_rows[row].ratio = draw_step / (float)line_len;
        this->map_tile_rows[row].col_extra =
            this->map_tile_rows[row].ratio < DAT_0056f604
                ? col_step * DAT_0056f600
                : DAT_0056f5fc;

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

    float draw_height = DAT_0056f604 / this->map_row_step;
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

void RGE_Diamond_Map::set_player(RGE_Player *value) {
  this->player = value;
  this->set_redraw(TPanel::RedrawImmediate);
}

void RGE_Diamond_Map::set_redraw(TPanel::RedrawMode mode) {
  TPanel::set_redraw(mode);
  if (mode == 2) {
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
      TDrawArea *to_delete = this->save_area;
      if (to_delete != 0) {
        to_delete->TDrawArea::~TDrawArea();
        operator delete(to_delete);
      }
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
  short start_y;
  short pi;
  p = this->save_area->Lock("diam_map::clear_image", 1);
  if (p == 0)
    return;

  save_area = this->save_area;
  start_y = this->map_image_start_y;

  if (save_area->Orien == 1) {
    pi = (short)save_area->Pitch;
    p = save_area->Bits + (int)start_y * save_area->Pitch;
  } else {
    p = save_area->Bits +
        ((save_area->Height - (int)start_y) - 1) * save_area->Pitch;
    pi = -(short)save_area->Pitch;
  }

  RGE_Map_Image_Line *line = this->map_image_lines;
  short cur_y = (short)this->pnl_y + start_y;
  short end_y = this->map_image_hgt + cur_y;

  if (cur_y < end_y) {
    int yv = (int)cur_y;
    int rm = (int)end_y - yv;

    do {
      if (yv >= this->clip_rect.top && yv <= this->clip_rect.bottom) {
        short sx = line->start_x;
        int s2 = (short)(this->pnl_x + sx);
        int ex = (short)(s2 + line->line_len - 1);

        if (s2 < this->clip_rect.left) {
          int adj = this->clip_rect.left - s2;
          sx = (short)((int)sx + adj);
          s2 = this->clip_rect.left;
        }
        if (ex > this->clip_rect.right)
          ex = this->clip_rect.right;

        if (s2 >= this->clip_rect.left && ex <= this->clip_rect.right)
          memset(p + (int)sx, this->color, ex - s2 + 1);
      }
      line++;
      p += (int)pi;
      yv++;
      rm--;
    } while (rm);
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

extern char s_draw_explored_tiles[];

void RGE_Diamond_Map::draw_explored_tiles() {
  RGE_Tile_List_Node *list;
  int count;

  this->player->diam_tile_list.get_list_info(list, count);

  if (count > 0) {
    if (this->save_area->Lock(s_draw_explored_tiles, 1)) {
      int i;
      i = 0;
      while (i < count) {
        this->draw_tile((short)list[i].col, (short)list[i].row, 0, 0);
        i++;
      }
      this->save_area->Unlock(s_draw_explored_tiles);
    }
  }
}

void RGE_Diamond_Map::draw_tile(short param_1, short param_2, int param_3,
                                unsigned char param_4) {
  unsigned char color = 0;
  RGE_Map_Tile_Row *row =
      this->map_tile_rows + ((int)param_2 + (int)this->map_wid - (int)param_1);
  --row;

  if (row->draw == 0) {
    return;
  }

  RGE_Map *map = this->map;
  RGE_Tile **tile_rows = map->map_row_offset;
  RGE_Tile *tile = tile_rows[param_2] + param_1;

  if (map->map_visible_flag == 0 &&
      (this->player->mutualExploredMask &
       unified_map_offsets[param_2][param_1]) == 0) {
    return;
  }

  bool draw = false;
  short x_offset;
  short max_coord = param_2;
  if (param_1 < param_2) {
    max_coord = param_1;
  }

  if (!(row->ratio >= DAT_0056f604)) {
    float scaled = (float)max_coord * row->ratio;
    x_offset = (short)scaled;
    if (scaled - (float)x_offset < row->ratio) {
      draw = true;
    }
  } else {
    x_offset = (short)((float)max_coord * row->draw_step);
    draw = true;
  }

  if (!draw) {
    return;
  }

  int x = (int)this->map_image_lines[row->image_line].start_x + x_offset;
  int y = (int)this->map_image_start_y + (int)row->image_line;
  unsigned char terrain = tile->terrain_type & 0x1F;

  if (param_3 == 0) {
    if (param_4 > 0) {
      color = param_4;
    } else {
      switch (tile->tile_type) {
      case 0:
        color = map->terrain_types[terrain].map_med_color;
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
        color = map->terrain_types[terrain].map_low_color;
        break;
      case 2:
      case 3:
      case 6:
      case 10:
      case 11:
      case 14:
      case 16:
        color = map->terrain_types[terrain].map_hi_color;
        break;
      }
    }

    short scan_row = param_2 - 1;
    param_2 += 2;
    while (scan_row < param_2) {
      if (scan_row > -1 && scan_row < this->map_hgt) {
        short scan_col = param_1 - 1;
        while (scan_col < param_1 + 2) {
          if (scan_col <= -1 || scan_col >= this->map_wid) {
            ++scan_col;
          } else {
            RGE_Object_Node *node = tile_rows[scan_row][scan_col].objects.list;
            if (node == 0) {
              ++scan_col;
            } else {
              do {
                if (node->node->master_obj->map_draw_level == 4) {
                  color = node->node->master_obj->map_color;
                  break;
                }
                node = node->next;
              } while (node != 0);
              ++scan_col;
            }
          }
        }
      }
      ++scan_row;
    }

    short width = row->draw_wid;
    if (this->map_tile_draw_hgt == 1) {
      if (width == 1) {
        this->save_area->SetPixel(x, y, color);
        return;
      }
      if (width == 2) {
        this->save_area->SetPixel(x, y, color);
        this->save_area->SetPixel(x + 1, y, color);
        return;
      }
      if (width > 0) {
        int count = width;
        do {
          this->save_area->SetPixel(x, y, color);
          ++x;
          --count;
        } while (count != 0);
      }
    } else {
      short dy = 0;
      if (this->map_tile_draw_hgt > 0) {
        do {
          if (width > 0) {
            int count = width;
            int px = x;
            do {
              this->save_area->SetPixel(px, y + dy, color);
              ++px;
              --count;
            } while (count != 0);
          }
          ++dy;
        } while (dy < this->map_tile_draw_hgt);
      }
    }
    return;
  } else {
    x += this->pnl_x;
    y += this->pnl_y;
    short width = row->draw_wid;
    if (this->map_tile_draw_hgt == 1) {
      if (width == 1) {
        this->render_area->SetPixel(x, y, this->fog_color);
        return;
      }
      if (width == 2) {
        this->render_area->SetPixel(x, y, this->fog_color);
        this->render_area->SetPixel(x + 1, y, this->fog_color);
        return;
      }
      if (width < 1) {
        return;
      }
      int count = width;
      do {
        this->render_area->SetPixel(x, y, this->fog_color);
        ++x;
        --count;
      } while (count != 0);
      return;
    }
    short dy = 0;
    if (this->map_tile_draw_hgt < 1) {
      return;
    }
    do {
      if (width > 0) {
        int count = width;
        int px = x;
        do {
          this->render_area->SetPixel(px, y + dy, this->fog_color);
          ++px;
          --count;
        } while (count != 0);
      }
      ++dy;
    } while (dy < this->map_tile_draw_hgt);
    return;
  }
}

void RGE_Diamond_Map::draw_selected_area(void) {
  if (this->main_view == 0)
    return;

  long x1, y1, x2, y2;
  if (!this->main_view->get_selection_area(x1, y1, x2, y2, 1))
    return;

  if (!this->render_area->Lock("diam_map::draw_selected_area", 1))
    return;

  int y;
  for (y = y1; y <= y2; y++) {
    int x;
    for (x = x1; x <= x2; x++) {
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

void RGE_Diamond_Map::draw_visible_object(RGE_Static_Object *object,
                                          unsigned char color1,
                                          unsigned char color2) {
  if (object->tile == 0)
    return;

  short col;
  short row;
  RGE_Player *player;
  col = (short)object->world_x;
  row = (short)object->world_y;
  player = this->player;
  unsigned char visibility;
  if (player->visible != 0) {
    RGE_Map *map = this->map;
    if (map->map_visible_flag != 0 && map->fog_flag == 0) {
      visibility = 0x0F;
    } else {
      visibility = 0;
      unsigned long mask = unified_map_offsets[(short)row][(short)col];
      if ((player->mutualExploredMask & mask) != 0)
        visibility = 0x80;
      if ((player->mutualVisibleMask & mask) != 0)
        visibility = 0x0F;
      if (map->map_visible_flag != 0 && visibility == 0)
        visibility = 0x80;
      if (map->fog_flag == 0 && visibility == 0x80)
        visibility = 0x0F;
    }
  } else {
    visibility = 0x0F;
  }

  if (visibility != 0x0F &&
      (visibility != 0x80 || object->master_obj->fog_flag == 0))
    return;

  int level;
  if (object->type == 0x19) {
    if (visibility == 0x0F)
      return;

    RGE_Doppleganger_Object *dopple = (RGE_Doppleganger_Object *)object;
    if (player->mutualAlly[object->owner->id] == 1 &&
        (this->cur_player_bit & dopple->CantSeeBits) == 0) {
      level = dopple->map_draw_level;
      color1 = dopple->map_color;
      color2 = color1;
    } else {
      level = 0;
      color1 = 0xFF;
      color2 = 0xFF;
    }
  } else {
    level = object->master_obj->map_draw_level;
    if (level == 3)
      color1 = object->master_obj->map_color;
  }

  switch (level) {
  case 0:
    return;
  case 2:
    this->draw_object(col, (short)row, color1, 2, object);
    return;
  case 1:
    this->draw_object(col, (short)row, color2, 1, object);
    break;
  case 3:
    color2 = color1;
    this->draw_object(col, row, color2, 2, object);
    break;
  default:
    return;
  }
}

void RGE_Diamond_Map::draw_object(short param_1, short param_2,
                                  unsigned char param_3, short param_4,
                                  RGE_Static_Object *param_5) {
  short max_coord = param_2;
  int row_index = (int)this->map_wid + (int)param_2 - (int)param_1;
  RGE_Map_Tile_Row *row = this->map_tile_rows + row_index - 1;

  if (param_1 < param_2)
    max_coord = param_1;

  short x_offset;
  if (row->ratio < DAT_0056f604) {
    x_offset = (short)((float)max_coord * row->ratio);
  } else {
    x_offset = (short)((float)max_coord * row->draw_step);
  }

  short image_line = row->image_line;
  short x = this->map_image_lines[image_line].start_x;
  x = x + (short)this->pnl_x + x_offset;

  short y = (short)this->pnl_y + this->map_image_start_y + image_line;

  if (param_4 == 1) {
    this->render_area->FillRect(x - 1, y - 1, x + 1, y + 1, param_3);
    return;
  }
  if (param_4 == 2) {
    this->render_area->FillRect(x, y - 1, x, y + 1, param_3);
    this->render_area->FillRect(x - 1, y, x + 1, y, param_3);
    return;
  }
  if (param_4 == 3) {
    this->render_area->FillRect(x - 3, y, x + 3, y + 1, param_3);
    this->render_area->FillRect(x - 2, y - 1, x + 2, y + 2, param_3);
    return;
  }
  if (param_4 == 4) {
    this->render_area->FillRect(x - 2, y - 2, x + 2, y + 2, param_3);
  }
}

void RGE_Diamond_Map::draw_clipped_horz_line(short p1, short p2, short p3,
                                             unsigned char p4,
                                             RGE_Map_Image_Line *line) {
  long clipped_left = this->pnl_x + line->start_x;

  if (p1 < clipped_left) {
    p1 = (short)(this->pnl_x + line->start_x);
  }

  short result_x = p3;
  if ((long)(p1 + p3 - 1) >= clipped_left + line->line_len) {
    result_x = (short)(this->pnl_x - p1 + line->line_len + line->start_x);
  }

  this->render_area->DrawHorzLine((long)p1, (long)p2, (long)result_x, p4);
}

void RGE_Diamond_Map::draw_view_rect() {
  short view_x = (short)(long)this->player->view_x;
  long local_8 = (long)this->player->view_y;

  if (view_x != this->view_col || (short)local_8 != this->view_row) {
    if (view_x < 0) {
      return;
    }
    RGE_Map *map = this->map;
    if ((int)view_x >= map->map_width) {
      return;
    }
    if ((short)local_8 < 0) {
      return;
    }
    if ((int)(short)local_8 >= map->map_height) {
      return;
    }

    short map_x = (short)this->map_wid;
    short tile_x = (short)(long)this->player->view_x;
    short tile_y = (short)(long)this->player->view_y;
    RGE_Map_Tile_Row *tile_row =
        this->map_tile_rows + ((int)map_x - (int)tile_x) - 1 + (int)tile_y;

    short row = (short)local_8;
    if (view_x < (short)local_8) {
      row = view_x;
    }
    long x_offset;
    if (tile_row->ratio < DAT_0056f604) {
      x_offset = (long)((float)row * tile_row->ratio);
    } else {
      x_offset = (long)((float)row * tile_row->draw_step);
    }

    short image_line_num = tile_row->image_line;
    RGE_Map_Image_Line *image_line = this->map_image_lines + image_line_num;
    long x = this->pnl_x + image_line->start_x + x_offset;
    long y = this->pnl_y + this->map_image_start_y + image_line_num;

    short vhgt;
    short map_row;
    ((RGE_View *)this->main_view)->get_max_size(&vhgt, &map_row);

    int half_width = (int)vhgt / 2;
    this->view_rect.left =
        (long)((float)x - (float)half_width * this->map_col_ratio);
    this->view_rect.top =
        (long)((float)y - (float)map_row * this->map_row_ratio);
    this->view_rect.right =
        (long)((float)x + (float)(half_width + 2) * this->map_col_ratio);
    this->view_rect.bottom =
        (long)((float)y + (float)(map_row + 4) * this->map_row_ratio);
    this->view_col = view_x;
    this->view_row = (short)local_8;
  }

  long current_y = this->view_rect.top;
  long bottom = this->view_rect.bottom;
  if (current_y <= bottom) {
    do {
      long image_top = this->pnl_y + this->map_image_start_y;
      if (!(current_y < image_top ||
            current_y > this->map_image_hgt - 1 + image_top)) {
        long image_index = (current_y - this->map_image_start_y) - this->pnl_y;
        long right = this->view_rect.right;
        RGE_Map_Image_Line *line = this->map_image_lines + image_index;
        long left = this->view_rect.left;

        if (current_y == this->view_rect.top || current_y == bottom) {
          long line_start = line->start_x;
          line_start += this->pnl_x;
          long line_end = line_start + line->line_len;
          if (left < line_end) {
            if (right >= line_start) {
              if (left < line_start) {
                left = line_start;
              }
              if (right >= line_end) {
                right = line_end - 1;
              }
              this->render_area->DrawHorzLine(left, current_y, right - left + 1,
                                              0xFF);
            }
          }
        } else {
          long line_start = line->start_x;
          line_start += this->pnl_x;
          if (left < line_start + line->line_len) {
            if (left >= line_start) {
              this->render_area->SetPixel(left, current_y, 0xFF);
            }
          }
          line_start = line->start_x;
          line_start += this->pnl_x;
          if (right < line_start + line->line_len) {
            if (right >= line_start) {
              this->render_area->SetPixel(right, current_y, 0xFF);
            }
          }
        }
      }
      bottom = this->view_rect.bottom;
      ++current_y;
    } while (current_y <= bottom);
  }
}

int RGE_Diamond_Map::pick_tile(long param_1, long param_2, short *param_3,
                               short *param_4, RGE_Tile **param_5) {
  if (this->map == 0) {
    return 0;
  }

  if (this->map_image_lines == 0) {
    return 0;
  }

  int adjusted_y = param_2 - this->pnl_y;
  int adjusted_x = param_1 - this->pnl_x;

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

      if (param_3 != 0) {
        *param_3 = result_col;
      }
      if (param_4 != 0) {
        *param_4 = result_row;
      }
      if (param_5 != 0) {
        *param_5 = this->map->map_row_offset[result_row] + result_col;
      }
      return 1;
    }
  }
  return 0;
}

long RGE_Diamond_Map::handle_size(long width, long height) {
  this->TPanel::handle_size(width, height);
  this->view_col = -1;
  this->view_row = -1;
  this->create_surfaces();
  return 0;
}

void RGE_Diamond_Map::start_scroll_view(long x, long y) {
  short xs, ys;
  RGE_Tile *tile;

  if (pick_tile(x, y, &xs, &ys, &tile)) {
    this->capture_mouse();

    this->scrolling = 1;
    this->player->set_view_loc((float)xs - 0.5f, (float)ys - 0.5f);

    this->set_redraw(TPanel::RedrawNormal);

    if (this->main_view) {
      this->main_view->set_redraw(TPanel::RedrawNormal);
    }

    this->mouse_last_x = x;
    this->mouse_last_y = y;
  }
}

void RGE_Diamond_Map::handle_scroll_view(long param_1, long param_2) {
  short out_1;
  short out_2;
  RGE_Tile *tile;
  if (this->pick_tile(param_1, param_2, &out_1, &out_2, &tile) != 0) {
    this->player->set_view_loc((float)out_1 - 0.5f, (float)out_2 - 0.5f);

    this->set_redraw(TPanel::RedrawNormal);

    if (this->main_view != 0) {
      this->main_view->set_redraw(TPanel::RedrawNormal);
    }

    this->mouse_last_x = param_1;
    this->mouse_last_y = param_2;
  }
}

void RGE_Diamond_Map::end_scroll_view() {
  this->scrolling = 0;
  this->release_mouse();
}

int RGE_Diamond_Map::is_inside(long x, long y) {
  short out_x;
  short out_y;
  RGE_Tile *tile;

  if (TPanel::is_inside(x, y))
    return this->pick_tile(x, y, &out_x, &out_y, &tile);
  return 0;
}

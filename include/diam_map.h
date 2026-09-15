#ifndef AOE1_DIAM_MAP_H
#define AOE1_DIAM_MAP_H

#include "map.h"
#include "color.h"
#include "dpl_obj.h"
#include "Picture.h"
#include "player.h"
#include "view.h"
#include "world.h"

struct RGE_Map_Image_Line {
  short tile_row;
  short start_x;
  short line_len;
};

class RGE_Map_Tile_Row {
public:
  short image_line;
  unsigned char draw;
  short row_len;
  float col_step;
  float col_extra;
  short map_col;
  short map_row;
  short draw_wid;
  float draw_step;
  short num_tiles;
  float ratio;
};

class RGE_Diamond_Map : public TPanel {
public:
  RGE_Diamond_Map();
  virtual ~RGE_Diamond_Map();

  long setup(TDrawArea *render_area_in, TPanel *parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in,
             unsigned char color_in, int all_visible_in, TDrawArea *save_area_in);
  int set_bitmap(char *map_bmp, long res_id);
  void set_world(RGE_Game_World *world_in);
  void set_player(RGE_Player *player_in);
  void set_visibility(int);
  void set_main_view(RGE_View *);
  virtual void set_redraw(TPanel::RedrawMode redraw_mode);
  void set_fog_color(unsigned char);
  unsigned char get_fog_color();
  void delete_surfaces();
  int create_surfaces();
  virtual void draw();
  int pick_tile(long x, long y, short *col, short *row, RGE_Tile **tile);
  virtual long handle_size(long win_wid, long win_hgt);
  void start_scroll_view(long x, long y);
  void handle_scroll_view(long x, long y);
  void end_scroll_view();
  virtual int is_inside(long x, long y);

protected:
  void clear_image();
  void copy_image();
  void draw_all_tiles();
  void draw_explored_tiles();
  void draw_tile(short col, short row, int fog, unsigned char override_color);
  virtual void draw_selected_area();
  virtual void draw_objects();
  virtual void draw_visible_object(RGE_Static_Object *game_obj, unsigned char color1, unsigned char color2);
  virtual void draw_object(short col, short row, unsigned char color, short size, RGE_Static_Object *game_obj);
  void draw_clipped_horz_line(short x, short y, short len, unsigned char color, RGE_Map_Image_Line *image_line);
  virtual void draw_view_rect();

public:
  RGE_Game_World *world;
  RGE_Player *player;
  RGE_Map *map;
  int all_visible;
  int render_all;
  long mouse_last_x;
  long mouse_last_y;
  int repos_mouse;
  tagRECT view_rect;
  RGE_Player *last_player;
  RGE_Map_Image_Line *map_image_lines;
  RGE_Map_Tile_Row *map_tile_rows;
  short map_wid;
  short map_hgt;
  short map_image_start_y;
  short map_image_wid;
  short map_image_hgt;
  short map_tile_row_cnt;
  float map_row_step;
  float map_col_ratio;
  float map_row_ratio;
  short map_tile_draw_hgt;
  short map_tile_draw_wid;
  short view_col;
  short view_row;
  RGE_View *main_view;
  int scrolling;
  unsigned char fog_color;
  int draw_objects_mode;
  unsigned long cur_player_bit;
  int own_save_area;
  TDrawArea *save_area;
};

typedef char diam_map_image_line_size_check[(sizeof(RGE_Map_Image_Line) == 0x06)
                                                ? 1
                                                : -1];
typedef char
    diam_map_tile_row_size_check[(sizeof(RGE_Map_Tile_Row) == 0x24) ? 1 : -1];
typedef char diam_map_size_check[(sizeof(RGE_Diamond_Map) == 0x16C) ? 1 : -1];

#endif

#include "../../include/diam_map_context.h"

// 00436830 RGE_Diamond_Map::RGE_Diamond_Map (diam_map.cpp:40-76)
// Attempt 3: give TPanel a non-inline constructor so VC5 emits the base ctor call

RGE_Diamond_Map::RGE_Diamond_Map()
{
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

TPanel::TPanel()
{
}

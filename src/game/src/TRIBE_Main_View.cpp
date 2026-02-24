// TRIBE_Main_View.cpp
// Transliterated from src/game/decomp/tvw_main.cpp.decomp
// ASM audited vs src/game/decomp/tvw_main.cpp.asm as noted per-function.

#include "TRIBE_Main_View.h"
#include "RGE_Main_View.h"
#include "RGE_View.h"
#include "RGE_Pick_Info.h"
#include "RGE_Base_Game.h"
#include "RGE_Static_Object.h"
#include "RGE_Master_Static_Object.h"
#include "RGE_Player.h"
#include "RGE_Object_List.h"
#include "RGE_Object_Node.h"
#include "RGE_Game_World.h"
#include "RGE_Color_Table.h"
#include "TRIBE_Player.h"
#include "TRIBE_Master_Building_Object.h"
#include "TDrawArea.h"
#include "globals.h"

TRIBE_Main_View::TRIBE_Main_View()
    : RGE_Main_View() {}
TRIBE_Main_View::~TRIBE_Main_View() {}
// ---------------------------------------------------------------------------
// Offset: 0x0052D060
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052D060
// ---------------------------------------------------------------------------
int TRIBE_Main_View::draw_wall_outline(long col, long row,
                                       TRIBE_Master_Building_Object* master_bldg,
                                       long endpoint_flag)
{
    short x3_out, scr_y_out;
    int ok = this->get_tile_screen_coords((short)col, (short)row, &x3_out, &scr_y_out, 0);
    if (!ok) {
        fog_next_shape = 0;
        return 1;
    }

    // alignment_box outputs (screen-space bounding box corners)
    short ab_x4, ab_local_12, ab_scr_y, ab_y3, ab_y4, ab_y1, ab_x2;
    short local_4[2];
    master_bldg->alignment_box(this->world, col + 0.5f, row + 0.5f,
                                &ab_x4, &ab_local_12, &ab_scr_y,
                                &ab_y3, &ab_y4, &ab_y1, &ab_x2,
                                local_4);

    // check_placement to determine fog ghost shape
    // returns 0 = can place (fog_next_shape=5), non-zero = blocked (animated shape)
    uchar check = master_bldg->check_placement(
        (RGE_Player*)this->player, col + 0.5f, row + 0.5f,
        nullptr, 1, master_bldg->elevation_flag, 0, 1, 1, 1);
    if (check == 0) {
        fog_next_shape = 5;
    } else {
        uint anim = (this->world->world_time >> 7) & 7;
        int base = (anim < 4) ? (int)anim + 0x24 : 0x2c - (int)anim;
        fog_next_shape = (base << 4) | 9;
    }

    // Draw master building sprite centered on the tile's footprint
    if (master_bldg->sprite != nullptr) {
        // Compute center_x = tile_scr_x + signed_midpoint(ab_x4, ab_y4)
        int mid_x_raw   = (int)(short)ab_x4 - (int)(short)ab_y4;
        int mid_x_floor = (mid_x_raw - (mid_x_raw >> 31)) >> 1;
        int center_x    = (int)(short)ab_y4 + mid_x_floor + (int)x3_out;

        // Compute center_y = tile_scr_y + signed_midpoint(ab_y3, local_4[0])
        int local4_val  = (int)(short)local_4[0];
        int mid_y_raw   = (int)(short)ab_y3 - local4_val;
        int mid_y_floor = (mid_y_raw - (mid_y_raw >> 31)) >> 1;
        int center_y    = local4_val + mid_y_floor + (int)scr_y_out;

        SDI_Draw_Line = (short)center_y;

        RGE_Player* draw_player = rge_base_game->get_player();
        master_bldg->draw(
            this->render_area,
            (short)center_x, (short)center_y,
            draw_player->color_table,
            (long)(endpoint_flag + 1),
            0L, 0, (uchar)0);
    }

    fog_next_shape = 0;
    return 1;
}

// ---------------------------------------------------------------------------
// Offset: 0x0052CAF0
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052CAF0
// ---------------------------------------------------------------------------
void TRIBE_Main_View::draw_multi_object_outline()
{
    if (rge_base_game->master_obj_id == (short)-1)
        return;

    TRIBE_Player* player = (TRIBE_Player*)this->player;
    TRIBE_Master_Building_Object* mk = (TRIBE_Master_Building_Object*)
        player->master_objects[(int)(short)rge_base_game->master_obj_id];
    if (!mk)
        return;

    this->render_area->SetClipRect(&this->clip_rect);

    long sel_col1 = 0, sel_row1 = 0, sel_col2 = 0, sel_row2 = 0;
    int has_sel = this->get_selection_area(&sel_col1, &sel_row1, &sel_col2, &sel_row2, 0);

    if (!has_sel) {
        tagPOINT pt = {};
        rge_base_game->get_mouse_pos(&pt);
        if (!this->is_inside(pt.x, pt.y)) {
            this->render_area->SetClipRect((tagRECT*)nullptr);
            return;
        }
        long panel_x = pt.x - this->render_rect.left;
        long panel_y = pt.y - this->render_rect.top;
        RGE_Pick_Info pick_info = {};
        uchar pick_res = this->pick1('(', '\0', panel_x, panel_y, &pick_info, nullptr, 1);
        if (pick_res != '3') {
            this->render_area->SetClipRect((tagRECT*)nullptr);
            return;
        }
        this->fixup_pick_info(&pick_info);
        int col = (int)pick_info.x;
        int row = (int)pick_info.y;
        sel_col1 = col; sel_row1 = row;
        sel_col2 = col; sel_row2 = row;
    }

    long c1 = sel_col1;
    long r1 = sel_row1;
    long c2 = sel_col2;
    long r2 = sel_row2;

    long abs_row_diff = r2 - r1; if (abs_row_diff < 0) abs_row_diff = -abs_row_diff;
    long abs_col_diff = c2 - c1; if (abs_col_diff < 0) abs_col_diff = -abs_col_diff;

    if (abs_row_diff == abs_col_diff) {
        // Diagonal: all tiles are endpoints (flag=2)
        if (c2 < c1) {
            if (r2 < r1) {
                // NW diagonal: col++ row++ from (c2,r2) to (c1,r1)
                long ci = c2, ri = r2;
                do { draw_wall_outline(ci, ri, mk, 2); ci++; ri++; } while (ci <= c1);
            } else {
                // SW diagonal: col-- row++ from (c1,r1) to (c2,r2)
                long ci = c1, ri = r1;
                do { draw_wall_outline(ci, ri, mk, 2); ci--; ri++; } while (c2 <= ci);
            }
        } else {
            if (r2 < r1) {
                // NE diagonal: col-- row++ from (c2,r2) to (c1,r1)
                long ci = c2, ri = r2;
                do { draw_wall_outline(ci, ri, mk, 2); ci--; ri++; } while (c1 <= ci);
            } else {
                // SE diagonal: col++ row++ from (c1,r1) to (c2,r2)
                long ci = c1, ri = r1;
                do { draw_wall_outline(ci, ri, mk, 2); ci++; ri++; } while (ci <= c2);
            }
        }
    } else if (abs_row_diff < abs_col_diff) {
        // Horizontal dominant: draw col segment on r1, row-segment corner at c2
        long c_min = (c1 < c2) ? c1 : c2;
        long c_max = (c1 < c2) ? c2 : c1;
        long row_corner = -1;
        long r_lo = -1, r_hi = -1;

        if (r1 < r2)      { row_corner = c2; r_lo = r1 + 1; r_hi = r2; }
        else if (r2 < r1) { row_corner = c2; r_lo = r2;     r_hi = r1 - 1; }

        // Draw horizontal segment
        for (long ci = c_max; ci >= c_min; ci--) {
            long flag = ((ci == c1) || (ci == c2)) ? 2L : 0L;
            draw_wall_outline(ci, r1, mk, flag);
        }
        // Draw vertical corner segment
        if (row_corner != -1 && r_lo <= r_hi) {
            for (long ri = r_lo; ri <= r_hi; ri++) {
                long flag = ((ri == r1) || (ri == r2)) ? 2L : 1L;
                draw_wall_outline(row_corner, ri, mk, flag);
            }
        }
    } else {
        // Vertical dominant: draw row segment on c1, col-segment corner at r2
        long r_min = (r1 < r2) ? r1 : r2;
        long r_max = (r1 < r2) ? r2 : r1;
        long col_corner = -1;
        long c_lo = -1, c_hi = -1;

        if (c1 < c2)      { col_corner = r2; c_lo = c1 + 1; c_hi = c2; }
        else if (c2 < c1) { col_corner = r2; c_lo = c2;     c_hi = c1 - 1; }

        // Draw vertical segment
        for (long ri = r_min; ri <= r_max; ri++) {
            long flag = ((ri == r1) || (ri == r2)) ? 2L : 1L;
            draw_wall_outline(c1, ri, mk, flag);
        }
        // Draw horizontal corner segment
        if (col_corner != -1 && c_lo <= c_hi) {
            for (long ci = c_lo; ci <= c_hi; ci++) {
                long flag = ((ci == c1) || (ci == c2)) ? 2L : 0L;
                draw_wall_outline(ci, col_corner, mk, flag);
            }
        }
    }

    this->render_area->SetClipRect((tagRECT*)nullptr);
}

// ---------------------------------------------------------------------------
// Offset: 0x0052D540
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052D540
// ---------------------------------------------------------------------------
void TRIBE_Main_View::place_line_of_walls(TRIBE_Player* player,
                                          TRIBE_Master_Building_Object* master_bldg,
                                          int col1, int row1,
                                          int col2, int row2)
{
    int col_step = (col1 == col2) ? 0 : (col2 > col1 ? 1 : -1);
    int row_step = (row1 == row2) ? 0 : (row2 > row1 ? 1 : -1);

    int cur_col = col1, cur_row = row1;
    for (;;) {
        uchar bad = master_bldg->check_placement(
            (RGE_Player*)player, cur_col + 0.5f, cur_row + 0.5f,
            nullptr, 1, master_bldg->elevation_flag, 0, 1, 1, 1);
        if (bad == 0)
            player->make_new_object((long)master_bldg->id,
                                    cur_col + 0.5f, cur_row + 0.5f, 0.0f, 1);
        if (cur_col == col2 && cur_row == row2)
            break;
        cur_col += col_step;
        cur_row += row_step;
    }
}

// ---------------------------------------------------------------------------
// Offset: 0x0052D1F0
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052D1F0
// ---------------------------------------------------------------------------
int TRIBE_Main_View::command_place_object(long param_1, long param_2, int param_3)
{
    if (!allow_user_commands)
        return 0;

    if (rge_base_game->game_mode != 7)
        return RGE_Main_View::command_place_object(param_1, param_2, 1);

    RGE_Pick_Info pick_info = {};
    uchar pick_res = this->pick1('(', '\0', param_1, param_2, &pick_info, nullptr, 1);
    if (pick_res != '3')
        return 0;
    this->fixup_pick_info(&pick_info);

    short master_obj_id = rge_base_game->master_obj_id;
    if (master_obj_id == (short)-1)
        return 0;

    TRIBE_Player* player = (TRIBE_Player*)this->player;
    TRIBE_Master_Building_Object* master_bldg = (TRIBE_Master_Building_Object*)
        player->master_objects[(int)master_obj_id];
    if (!master_bldg)
        return 0;

    master_bldg->alignment(&pick_info.x, &pick_info.y, this->world, 0);

    uchar bad = master_bldg->check_placement(
        (RGE_Player*)player, pick_info.x, pick_info.y,
        nullptr, 1, master_bldg->elevation_flag, 0, 1, 1, 1);
    if (bad != 0)
        return 0;

    if (param_3 || master_obj_id == (short)0x6d)
        rge_base_game->set_game_mode(0, 0);

    uchar ok = player->command_make_building(master_obj_id, pick_info.x, pick_info.y);
    return ok ? 1 : 0;
}

// ---------------------------------------------------------------------------
// Offset: 0x0052D320
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052D320
// ---------------------------------------------------------------------------
int TRIBE_Main_View::command_place_multi_object(long param_1, long param_2,
                                                long param_3, long param_4,
                                                int param_5)
{
    if (!allow_user_commands)
        return 0;

    if (rge_base_game->prog_mode != 7)
        return RGE_Main_View::command_place_multi_object(param_1, param_2, param_3, param_4, param_5);

    short master_obj_id = rge_base_game->master_obj_id;
    if (master_obj_id == (short)-1)
        return 0;

    TRIBE_Player* player = (TRIBE_Player*)this->player;
    TRIBE_Master_Building_Object* mk = (TRIBE_Master_Building_Object*)
        player->master_objects[(int)master_obj_id];
    if (!mk)
        return 0;

    long c1 = param_1, r1 = param_2;
    long c2 = param_3, r2 = param_4;

    long abs_col = c2 - c1; if (abs_col < 0) abs_col = -abs_col;
    long abs_row = r2 - r1; if (abs_row < 0) abs_row = -abs_row;

    if (abs_col == abs_row) {
        // Diagonal: single direct line
        place_line_of_walls(player, mk, (int)c1, (int)r1, (int)c2, (int)r2);
    } else if (abs_row > abs_col) {
        // Abs_row > abs_col: sweep rows first (along rows at fixed col c1), then cols at row r2.
        // ASM 0052d3b2-0052d414 (primary = rows at c1, corner = cols at r2)
        place_line_of_walls(player, mk, (int)c1, (int)r1, (int)c1, (int)r2);
        if (c1 < c2) {
            // Horizontal corner from c1+1 to c2 at row r2
            place_line_of_walls(player, mk, (int)(c1 + 1), (int)r2, (int)c2, (int)r2);
        } else if (c2 < c1) {
            // Horizontal corner from c2 to c1-1 at row r2
            place_line_of_walls(player, mk, (int)c2, (int)r2, (int)(c1 - 1), (int)r2);
        }
    } else {
        // Abs_row < abs_col: sweep cols first (along cols at fixed row r1), then rows at col c2.
        // ASM 0052d417-0052d53f (primary = cols at r1, corner = rows at c2)
        place_line_of_walls(player, mk, (int)c1, (int)r1, (int)c2, (int)r1);
        if (r1 < r2) {
            // Vertical corner from r1+1 to r2 at col c2
            place_line_of_walls(player, mk, (int)c2, (int)(r1 + 1), (int)c2, (int)r2);
        } else if (r2 < r1) {
            // Vertical corner from r2 to r1-1 at col c2
            place_line_of_walls(player, mk, (int)c2, (int)r2, (int)c2, (int)(r1 - 1));
        }
    }

    return 1;
}

// ---------------------------------------------------------------------------
// Offset: 0x0052D620
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052D620
// ---------------------------------------------------------------------------
long TRIBE_Main_View::mouse_left_up_action(long param_1, long param_2,
                                            int param_3, int param_4)
{
    int prog = rge_base_game->prog_mode;
    if (prog != 4 && prog != 5 && prog != 6 && prog != 7)
        return 0;
    return RGE_Main_View::mouse_left_up_action(param_1, param_2, param_3, param_4);
}

// ---------------------------------------------------------------------------
// Offset: 0x0052D960
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052D960
// Handles right-up in special game modes (attack, patrol, repair, unload, etc.).
// ---------------------------------------------------------------------------
long TRIBE_Main_View::mouse_right_up_action(long param_1, long param_2,
                                             int param_3, int param_4)
{
    int game_mode = rge_base_game->game_mode;

    switch (game_mode) {
    case 100: { // 0x64: attack-ground
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            return 1;
        RGE_Pick_Info pick_info = {};
        uchar res = this->pick1('(', '\0', param_1, param_2, &pick_info, nullptr, 1);
        if (res == '3') {
            this->fixup_pick_info(&pick_info);
            TRIBE_Player* player = (TRIBE_Player*)this->player;
            uchar ok = player->command_attack_ground(pick_info.x, pick_info.y);
            if (ok) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(
                    rge_base_game->shapes[2], 0,
                    this->map_scr_x_offset + (int)param_1,
                    this->map_scr_y_offset + (int)param_2,
                    0, 0xf, nullptr, 2, 0x7d);
                rge_base_game->set_game_mode(0, 0);
                return 1;
            }
        }
        rge_base_game->play_sound(3);
        rge_base_game->set_game_mode(0, 0);
        return 1;
    }
    case 0x65: { // patrol
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            return 1;
        int ok = this->command_make_do(param_1, param_2, 0, 0x68);
        if (!ok) rge_base_game->play_sound(3);
        rge_base_game->set_game_mode(0, 0);
        return 1;
    }
    case 0x66: { // attack-move
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            return 1;
        int ok = this->command_make_do(param_1, param_2, 0, 0x69);
        if (!ok) rge_base_game->play_sound(3);
        rge_base_game->set_game_mode(0, 0);
        return 1;
    }
    case 0x67: { // stand-ground move
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            return 1;
        int ok = this->command_make_do(param_1, param_2, 0, 7);
        if (!ok) rge_base_game->play_sound(3);
        rge_base_game->set_game_mode(0, 0);
        return 1;
    }
    case 0x68: { // repair
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            return 1;
        RGE_Static_Object* target = this->pick_best_target(param_1, param_2, nullptr, -1);
        if (target) {
            TRIBE_Player* player = (TRIBE_Player*)this->player;
            uchar ok = player->command_make_repair(target);
            if (ok) {
                this->display_object_selection(target->id, 0x5dc, 2, 2);
                this->reset_overlay_sprites();
                rge_base_game->set_game_mode(0, 0);
                return 1;
            }
        }
        rge_base_game->play_sound(3);
        rge_base_game->set_game_mode(0, 0);
        return 1;
    }
    case 0x69: { // unload
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            return 1;
        RGE_Pick_Info pick_info = {};
        uchar res = this->pick1('(', '\0', param_1, param_2, &pick_info, nullptr, 1);
        if (res == '3') {
            this->fixup_pick_info(&pick_info);
            TRIBE_Player* player = (TRIBE_Player*)this->player;
            uchar ok = player->command_make_unload(pick_info.x, pick_info.y);
            if (ok) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(
                    rge_base_game->shapes[2], 0,
                    this->map_scr_x_offset + (int)param_1,
                    this->map_scr_y_offset + (int)param_2,
                    0, 0xf, nullptr, 2, 0x7d);
                rge_base_game->set_game_mode(0, 0);
                return 1;
            }
        }
        rge_base_game->play_sound(3);
        rge_base_game->set_game_mode(0, 0);
        return 1;
    }
    default:
        return RGE_Main_View::mouse_right_up_action(param_1, param_2, param_3, param_4);
    }
}

// ---------------------------------------------------------------------------
// Offset: 0x0052DCE0
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052DCE0
// ---------------------------------------------------------------------------
int TRIBE_Main_View::pick_through_fog(RGE_Static_Object* param_1)
{
    // Object type 0x2d (e.g. Ruins) is always visible through fog
    if (param_1 != nullptr && param_1->master_obj->id == 0x2d)
        return 1;
    return RGE_View::pick_through_fog(param_1);
}

// ---------------------------------------------------------------------------
// Offset: 0x0052DD10
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052DD10
// ---------------------------------------------------------------------------
int TRIBE_Main_View::pick_weight(RGE_Static_Object* param_1, int param_2)
{
    short id        = param_1->master_obj->id;
    int   sel_level = (int)param_1->master_obj->select_level;

    // Certain object types (trees, cliffs, fish, walls) always treated as sel_level 3
    if (id == 0x4f || id == 199 || id == 0x45 || id == 0x116)
        sel_level = 3;

    bool is_targeted = (this->UC_ObjectTouched != 0 &&
                        this->UC_TouchedObj == (int)param_1->id);

    switch (sel_level) {
    case 2:
        if (is_targeted)                      return 5;
        if (param_2 == 1 || param_2 == 2)     return 3;
        return (param_2 == 3) ? 2 : 0;
    case 3:
        if (is_targeted)                      return 5;
        if (param_2 == 1 || param_2 == 2)     return 3;
        if (param_2 != 3)                     return 0;
        return (param_1->object_state > 1) ? 0 : 2;
    case 4:
        if (is_targeted)                      return 5;
        if (param_2 == 1 || param_2 == 2)     return 4;
        return (param_2 == 3) ? 3 : 2;
    default:
        return 1;
    }
}

// ---------------------------------------------------------------------------
// Offset: 0x0052DE20
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052DE20
// ---------------------------------------------------------------------------
int TRIBE_Main_View::command_make_do(long param_1, long param_2,
                                      int param_3, short param_4)
{
    return RGE_Main_View::command_make_do(param_1, param_2, param_3, param_4);
}

// ---------------------------------------------------------------------------
// Offset: 0x0052DE40
// Fully verified. Source of truth: tvw_main.cpp.decomp @ 0x0052DE40
// Double-click selects all visible same-type units on screen.
// ---------------------------------------------------------------------------
long TRIBE_Main_View::mouse_left_dbl_click_action(long param_1, long param_2,
                                                    int param_3, int param_4)
{
    RGE_Pick_Info pick_info = {};
    uchar res = this->pick1(')', '\x01', param_1, param_2, &pick_info, nullptr, 1);
    if (res != '4')
        return 0;

    RGE_Static_Object* picked = pick_info.object;
    if (!picked)
        return 0;

    // Must be a selectable unit (select_level == 4) owned by this player
    if (picked->master_obj->select_level != 4)
        return 0;
    TRIBE_Player* player = (TRIBE_Player*)this->player;
    if (picked->owner != (RGE_Player*)player)
        return 0;

    if (param_3 == 0 && param_4 == 0)
        player->unselect_object();

    player->select_one_object(picked, 0);

    short match_id         = picked->master_obj->id;
    uchar match_unit_level = picked->master_obj->unit_level;
    if (match_unit_level != 3)
        match_unit_level = 0xff;

    // Walk the player's object list; select visible units of the same type
    RGE_Object_Node* node = player->objects->list;
    while (node) {
        RGE_Static_Object* obj = node->node;
        if ((obj->master_obj->id == match_id ||
             obj->master_obj->unit_level == match_unit_level) &&
            this->Object_Was_Displayed(obj->id, 0)) {
            player->select_one_object(obj, 0);
        }
        node = node->next;
    }

    player->select_one_object(picked, 0);
    return 1;
}

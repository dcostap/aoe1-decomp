// PDB source module: C:\msdev\work\age1_x1\spnl_obj.cpp.
// Definitions follow the original PDB source order.

#include "../include/spnl_obj.h"

#include "../include/Shape.h"
#include "../include/basegame.h"
#include "../include/color.h"
#include "../include/game_globals.h"
#include "../include/m_co_obj.h"
#include "../include/rge_base_game_global.h"
#include "../include/sprite.h"
#include "../include/tm_b_obj.h"
#include "../include/tplayer.h"

#include <stdio.h>
#include <string.h>

extern "C" void __cdecl _ASMSet_Color_Xform(int);

// spnl_obj.cpp lines 48-52.
TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scenario_Editor_Panel_Object(
    TDrawArea* draw_area, TPanel* panel, void* font, long font_width,
    long font_height, TShape* unit_pictures, TShape** building_pictures,
    TRIBE_Player* player)
    : TRIBE_Panel_Object(draw_area, panel, font, font_width, font_height,
                         unit_pictures, building_pictures, player)
{
    master_game_obj = 0;
    master_culture_id = 0;
}

// spnl_obj.cpp line 58.
TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_Panel_Object()
{
}

// spnl_obj.cpp lines 63-70.
void TRIBE_Scenario_Editor_Panel_Object::set_master_info(
    RGE_Master_Static_Object* master, TRIBE_Player* player)
{
    master_game_obj = master;
    this->player = player;
    if (player == 0) {
        master_culture_id = 0;
        return;
    }
    master_culture_id = player->culture;
}

// spnl_obj.cpp lines 78-325.
// BINARY NOTE: The building facet belongs to the building-master extension.
void TRIBE_Scenario_Editor_Panel_Object::draw()
{
    int text_flag;
    long min_x;
    long min_y;
    long max_y;
    long max_x;
    char name[100];
    char str[100];

    if (render_area == 0 || visible == 0 || active == 0) {
        need_redraw = 0;
        return;
    }

    if (mode == 2) {
        draw_score();
        return;
    }

    if (master_game_obj == 0) {
        if (parent_panel != 0) {
            parent_panel->draw_rect(&clip_rect);
            need_redraw = 0;
            return;
        }
        need_redraw = 0;
        return;
    }

    draw_setup(0);
    render_area->Clear(&clip_rect, 0);

    if (render_area->Lock(0, 1) != 0) {
        text_flag = 1;
        short button_pict = master_game_obj->button_pict;

        if (button_pict != -1) {
            TShape* shape;
            if (master_game_obj->unit_level == 2) {
                shape = bldg_pics[master_culture_id];
                button_pict += static_cast<TRIBE_Master_Building_Object*>(
                    master_game_obj)->building_facet;
            } else {
                shape = unit_pics;
            }

            if (player != 0 && player->color_table->table != 0) {
                _ASMSet_Color_Xform((player->color_table->id + 1) * 0x10);
                shape->shape_draw(render_area, pnl_x + 2, pnl_y + 0x21,
                                  button_pict, 1,
                                  player->color_table->table);
            } else {
                shape->shape_draw(render_area, pnl_x + 2, pnl_y + 0x21,
                                  button_pict, 0, 0);
            }
        } else if (master_game_obj->sprite != 0) {
            text_flag = 0;
            if (master_game_obj->sprite->get_size(min_x, min_y, max_x, max_y,
                                                  0) != 0) {
                master_game_obj->sprite->do_draw(
                    0, 0, (pnl_x - min_x) + 10, (pnl_y - min_y) + 0x28,
                    player->color_table, render_area, 0);
            }
        }

        render_area->Unlock(0);
    }

    if (render_area->GetDc(0)) {
        SetBkMode(render_area->DrawDc, 1);
        SetTextColor(render_area->DrawDc, 0xFFFFFF);
        SelectClipRgn(render_area->DrawDc, (HRGN)clip_rgn);
        HGDIOBJ old_font =
            SelectObject(render_area->DrawDc, (HGDIOBJ)font);

        if (player != 0) {
            rge_base_game->get_string2(0x69, player->id, 0, name, 100);
            if (strcmp(name, "Unknown") == 0)
                strcpy(name, "Gaia");
            TextOutA(render_area->DrawDc, pnl_x + 2, pnl_y, name,
                     strlen(name));
        }

        short string_id = master_game_obj->string_id;
        if (string_id > 0)
            rge_base_game->get_string((long)string_id, str, 100);
        else
            str[0] = 0;
        if (str[0] == 0)
            strcpy(str, master_game_obj->name);
        sprintf(name, "%s", str);
        TextOutA(render_area->DrawDc, pnl_x + 2, pnl_y + 0x0F, name,
                 strlen(name));

        if (text_flag != 0) {
            sprintf(str, "%d/%d", (int)master_game_obj->hp,
                    (int)master_game_obj->hp);
            TextOutA(render_area->DrawDc, pnl_x + 5, pnl_y + 0x55, str,
                     strlen(str));
            SelectObject(render_area->DrawDc, old_font);
            SelectClipRgn(render_area->DrawDc, 0);
        }

        render_area->ReleaseDc(0);
    }

    if (text_flag == 0)
        goto draw_finish;

    {
        RGE_Master_Static_Object* master = master_game_obj;
        int item_index = 0;
        unsigned char unit_level = master->unit_level;

        if (unit_level == 3) {
            short amount =
                static_cast<RGE_Master_Combat_Object*>(master)->orig_weapon;
            draw_item(0, 7, ValueTypeBonus, amount, amount);
            item_index = 1;
        } else {
            if (unit_level != 9 && unit_level != 4 && unit_level != 5 &&
                unit_level != 6 && unit_level != 7) {
                if (unit_level == 1) {
                    short attr_type = -1;
                    int attr_index = 0;
                    float* attr_amount = master->attribute_amount_held;
                    while (attr_index < 3) {
                        if (*attr_amount > DAT_00574524) {
                            attr_type = master->attribute_type_held[attr_index];
                            break;
                        }
                        ++attr_index;
                        ++attr_amount;
                    }

                    int value_type;
                    switch (attr_type) {
                    case 0:
                        value_type = 2;
                        break;
                    case 0x0F:
                        value_type = 2;
                        break;
                    case 0x10:
                        value_type = 2;
                        break;
                    case 0x11:
                        value_type = 2;
                        break;
                    case 1:
                        value_type = 0;
                        break;
                    case 2:
                        value_type = 1;
                        break;
                    case 3:
                        value_type = 3;
                        break;
                    default:
                        goto draw_finish;
                    }

                    draw_item(0, value_type, ValueTypeNumber,
                              (int)master->attribute_amount_held[attr_index],
                              0);
                    draw_finish();
                    return;
                }

                if (unit_level == 2) {
                    draw_item(0, 7, ValueTypeBonus,
                              static_cast<RGE_Master_Combat_Object*>(master)
                                  ->orig_weapon,
                              static_cast<RGE_Master_Combat_Object*>(master)
                                  ->orig_weapon);
            draw_item(1, 8, ValueTypeBonus,
                              static_cast<RGE_Master_Combat_Object*>(
                                  master_game_obj)->orig_armor,
                              static_cast<RGE_Master_Combat_Object*>(
                                  master_game_obj)->orig_armor);
            draw_item(2, 6, ValueTypeBonus,
                              static_cast<int>(
                                  static_cast<RGE_Master_Combat_Object*>(
                                      master_game_obj)->weapon_range),
                              static_cast<int>(
                                  static_cast<RGE_Master_Combat_Object*>(
                                      master_game_obj)->weapon_range));
                    draw_finish();
                    return;
                }

                goto draw_finish;
            }

            if (master->unit_level == 3 || master->unit_level == 4) {
                short amount = static_cast<RGE_Master_Combat_Object*>(master)
                                   ->orig_weapon;
                draw_item(0, 7, ValueTypeBonus, amount, amount);
                item_index = 1;
            }
        }

        RGE_Master_Combat_Object* combat =
            static_cast<RGE_Master_Combat_Object*>(master_game_obj);
        short armor_value = combat->orig_armor;
        if (master_game_obj->unit_level == 4 ||
            master_game_obj->unit_level == 6) {
            draw_item(item_index, 8, ValueTypeBonus, armor_value, armor_value);
            ++item_index;
        }

        long pierce_armor = get_pierce_armor();
        short pierce_value = (short)pierce_armor;
        if (master_game_obj->unit_level == 4 ||
            master_game_obj->unit_level == 6) {
            draw_item(item_index, 10, ValueTypeBonus, pierce_value,
                      pierce_value);
            ++item_index;
        }

        if (master_game_obj->unit_level == 4 ||
            master_game_obj->unit_level == 6) {
            short speed_value = static_cast<short>(
                static_cast<RGE_Master_Combat_Object*>(master_game_obj)
                    ->orig_weapon_range);
            draw_item(item_index, 6, ValueTypeBonus, speed_value, pierce_value);
        }
    }

draw_finish:
    draw_finish();
}

// spnl_obj.cpp lines 333-382.
void TRIBE_Scenario_Editor_Panel_Object::draw_item(
    int item_index, int picture, ValueType value_type, int value,
    int comparison_value)
{
    char value_string[20];

    if (item_pic != 0 && picture != -1) {
        if (render_area->Lock(0, 1) != 0) {
            item_pic->shape_draw(render_area, pnl_x + 0x3C,
                                 pnl_y + item_index * 9 * 2 + 0x1E, picture,
                                 0, 0);
            render_area->Unlock(0);
        }
    }

    switch (value_type) {
    case ValueTypeNumber:
        sprintf(value_string, "%d", value);
        break;
    case ValueTypeBonus:
        if (comparison_value > value)
            sprintf(value_string, "%d+%d", value,
                    comparison_value - value);
        else
            sprintf(value_string, "%d", value);
        break;
    case ValueTypeCompare:
        sprintf(value_string, "%d/%d", value, comparison_value);
        break;
    case ValueTypePercent:
        sprintf(value_string, "%d%%", value);
        break;
    default:
        value_string[0] = 0;
    }

    if (value_string[0] != 0) {
        if (render_area->GetDc(0) != 0) {
            SetBkMode(render_area->DrawDc, 1);
            SetTextColor(render_area->DrawDc, 0xFFFFFF);
            SelectClipRgn(render_area->DrawDc, (HRGN)clip_rgn);
            HGDIOBJ old_font =
                SelectObject(render_area->DrawDc, (HGDIOBJ)font);
            int length = strlen(value_string);

            TextOutA(render_area->DrawDc, pnl_x + 0x64,
                     pnl_y + item_index * 9 * 2 + 0x20, value_string, length);

            SelectObject(render_area->DrawDc, old_font);
            SelectClipRgn(render_area->DrawDc, 0);
            render_area->ReleaseDc(0);
        }
    }
}

// spnl_obj.cpp lines 390-397.
long TRIBE_Scenario_Editor_Panel_Object::mouse_left_up_action(
    long x, long y, int ctrl, int shift)
{
    release_mouse();
    return 1;
}

// spnl_obj.cpp lines 406-423.
long TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor()
{
    RGE_Master_Static_Object* master = master_game_obj;
    if (master == 0)
        return 0;
    if (master->master_type != 'F')
        return 0;

    RGE_Master_Combat_Object* combat =
        static_cast<RGE_Master_Combat_Object*>(master);
    int armor_count = combat->armor_num;
    long result = 0;
    if (armor_count > 0) {
        RGE_Armor_Weapon_Info* armor = combat->armor;
        do {
            if (armor->type == 3)
                result = armor->value;
            ++armor;
            --armor_count;
        } while (armor_count != 0);
    }
    return result;
}

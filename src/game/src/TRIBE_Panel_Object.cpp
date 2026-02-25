#include "../include/TRIBE_Panel_Object.h"

#include "../include/TCommunications_Handler.h"
#include "../include/TRIBE_Action_Make_Obj.h"
#include "../include/TRIBE_Action_Make_Tech.h"
#include "../include/TRIBE_Building_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Master_Combat_Object.h"

#include "../include/RGE_Action.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
#include "../include/TRIBE_Player.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <cstdio>
#include <cstring>

extern "C" void _ASMSet_Color_Xform(int v);

namespace {
constexpr float kRoundBias = 0.5f;
constexpr float kDistanceScale0 = 0.000251256279f;
constexpr float kDistanceScale1 = 0.7f;
constexpr float kDistanceClamp = 0.35f;
constexpr float kDistanceToValue = 20.0f;
constexpr float kDistanceValueMax = 75.0f;
constexpr float kRangeThreshold = 0.99f;
constexpr float kProgressDoneThreshold = 99.0f;

static long panel_ftol(float value) {
    long result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

static int panel_ftol_biased(float value) {
    return (int)panel_ftol(value + kRoundBias);
}

static void panel_copy_string(char* dst, size_t dst_size, const char* src) {
    if (dst == nullptr || dst_size == 0) return;
    if (src == nullptr) {
        dst[0] = '\0';
        return;
    }
    std::strncpy(dst, src, dst_size - 1);
    dst[dst_size - 1] = '\0';
}

static int panel_resource_icon(short attr_type) {
    switch (attr_type) {
    case 0:
    case 0x0F:
    case 0x10:
    case 0x11:
        return 2;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 3;
    case 9:
        return 5;
    default:
        return -1;
    }
}

static short panel_get_construction_progress(TRIBE_Building_Object* building) {
    if (building == nullptr) return 100;
    if (building->built != 0) return 100;

    TRIBE_Master_Combat_Object* master = (TRIBE_Master_Combat_Object*)building->master_obj;
    short required = (master != nullptr) ? master->build_pts_required : 0;
    if (required == 0) return 100;

    return (short)panel_ftol((building->build_pts / (float)(int)required) * 100.0f);
}

static int panel_work_status(TRIBE_Building_Object* building,
                             short* work_type,
                             short* work_target,
                             short* progress,
                             char* work_name,
                             short work_name_len) {
    TRIBE_Action_Make_Obj* action = nullptr;
    if (building != nullptr && building->actions != nullptr) {
        action = (TRIBE_Action_Make_Obj*)building->actions->get_action();
    }

    if (action == nullptr) {
        *work_type = 0;
    } else {
        *work_type = action->action_type;
    }

    if (*work_type == 0x66) {
        action->get_info(work_target, progress, work_name, work_name_len);
        return 1;
    }

    if (*work_type == 0x67) {
        ((TRIBE_Action_Make_Tech*)action)->get_info(work_target, progress, work_name, work_name_len);
        return 1;
    }

    *work_target = -1;
    *progress = 0;
    if (work_name != nullptr) {
        work_name[0] = '\0';
    }
    return 0;
}

static int panel_production_queue_status(TRIBE_Building_Object* building, short* obj_id, short* progress) {
    *obj_id = -1;
    *progress = 0;

    if (building == nullptr) return 0;

    TRIBE_Action_Make_Obj* action = nullptr;
    if (building->production_queue_actions != nullptr) {
        action = (TRIBE_Action_Make_Obj*)building->production_queue_actions->get_action();
    }

    if (action != nullptr && action->action_type == 0x66) {
        action->get_info(obj_id, progress, nullptr, 0);
        return 1;
    }

    if (building->production_queue_count > 0 && building->production_queue != nullptr) {
        *obj_id = building->production_queue->master_id;
        *progress = 0;
        return 1;
    }

    return 0;
}

static void panel_get_pierce_armor(RGE_Static_Object* obj, short& cur, short& orig) {
    cur = 0;
    orig = 0;

    if (obj == nullptr || obj->master_obj == nullptr) return;

    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)obj->master_obj;
    if (master->armor_num > 0 && master->armor != nullptr) {
        for (int i = 0; i < (int)master->armor_num; ++i) {
            if (master->armor[i].type == 3 && master->armor[i].value > cur) {
                cur = master->armor[i].value;
            }
        }
    }

    TRIBE_Master_Combat_Object* tribe_master = (TRIBE_Master_Combat_Object*)master;
    orig = tribe_master->orig_pierce_armor;
}

static int panel_show_obj_id() {
    if (rge_base_game == nullptr) return 0;
    return *(int*)((char*)rge_base_game + 0xC20);
}

static int panel_string_equals(const char* a, const char* b) {
    if (a == nullptr || b == nullptr) return (a == b) ? 1 : 0;
    return std::strcmp(a, b) == 0;
}
} // namespace

TRIBE_Panel_Object::TRIBE_Panel_Object(
    TDrawArea* area,
    TPanel* parent,
    void* font_param,
    long font_wid_param,
    long font_hgt_param,
    TShape* unit_pics_param,
    TShape** bldg_pics_param,
    TRIBE_Player* player_param)
    : TPanel() {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051ADF0
    this->font = font_param;
    this->font_wid = font_wid_param;
    this->font_hgt = font_hgt_param;
    this->health_pic = nullptr;
    this->item_pic = nullptr;
    this->unit_pics = unit_pics_param;
    this->bldg_pics = bldg_pics_param;
    this->player = nullptr;
    this->game_obj = nullptr;
    this->idle_time = 0;
    this->idle_interval = 500;
    this->mode = 1;
    this->save_obj_type = nullptr;
    this->save_sprite = nullptr;
    this->save_attr_type = -1;
    this->save_attr_amount = 0.0f;
    this->save_object_state = 0;
    this->save_build_pts = 0.0f;
    this->save_list = nullptr;
    this->save_number_of_objects = 0;
    this->save_can_debark = 0;
    this->save_world_x = 0.0f;
    this->save_world_y = 0.0f;
    this->save_hp = 0.0f;
    this->save_armor = 0;
    this->save_pierce_armor = 0;
    this->save_weapon = 0;
    this->save_weapon_range = 0.0f;
    this->save_speed_of_attack = 0.0f;
    this->save_work_type = 0;
    this->save_work_target = 0;
    this->save_progress = 0;
    this->save_name[0] = '\0';
    this->save_facet = 0;
    this->save_angle = 0.0f;
    this->save_los = 0.0f;
    this->save_pop = 0;
    this->save_max_pop = 0;
    this->save_selected_group = 0;
    this->save_owner = nullptr;
    this->save_age = 0;
    this->save_have_action = 0;
    this->save_farm_amt = 0;
    std::memset(this->save_score, 0, sizeof(this->save_score));

    if (this->setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_player(player_param);

    this->health_pic = new TShape((char*)"health.shp", 0xC639);
    if (this->health_pic != nullptr && this->health_pic->is_loaded() == 0) {
        delete this->health_pic;
        this->health_pic = nullptr;
    }

    this->item_pic = new TShape((char*)"itemicon.shp", 0xC62B);
    if (this->item_pic != nullptr && this->item_pic->is_loaded() == 0) {
        delete this->item_pic;
        this->item_pic = nullptr;
    }
}

TRIBE_Panel_Object::~TRIBE_Panel_Object() {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051B070
    if (this->health_pic != nullptr) {
        delete this->health_pic;
        this->health_pic = nullptr;
    }

    if (this->item_pic != nullptr) {
        delete this->item_pic;
        this->item_pic = nullptr;
    }
}

void TRIBE_Panel_Object::set_player(TRIBE_Player* player_param) {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051B110
    this->player = player_param;
    if (player_param != nullptr) {
        this->set_object(player_param->selected_obj);
        return;
    }
    this->set_object(nullptr);
}

void TRIBE_Panel_Object::set_object(RGE_Static_Object* obj) {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051B140
    this->game_obj = obj;
    this->save_object_info();
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Panel_Object::set_mode(unsigned char mode_param) {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051B160
    this->mode = mode_param;
    this->save_object_info();
    this->set_redraw(TPanel::Redraw);
}

unsigned char TRIBE_Panel_Object::get_mode() {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051B180
    return this->mode;
}

void TRIBE_Panel_Object::draw() {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051B190
    if (this->render_area == nullptr || this->active == 0 || this->visible == 0) {
        this->need_redraw = TPanel::NoRedraw;
        return;
    }

    if (this->mode == 2) {
        this->draw_score();
        return;
    }

    if (this->game_obj == nullptr) {
        if (this->parent_panel != nullptr) {
            this->parent_panel->draw_rect(&this->clip_rect);
            this->need_redraw = TPanel::NoRedraw;
            return;
        }
        this->need_redraw = TPanel::NoRedraw;
        return;
    }

    this->draw_setup(0);
    this->render_area->Clear(&this->clip_rect, 0);

    if (this->render_area->Lock((char*)"tpnl_obj::draw", 1) != nullptr) {
        RGE_Static_Object* obj = this->game_obj;
        RGE_Master_Static_Object* master = obj->master_obj;
        short button_pic = master->button_pict;
        if (button_pic != -1) {
            TShape* pic_set = this->unit_pics;
            if (master->unit_level == 2) {
                unsigned char age = this->save_age;
                button_pic = (short)(button_pic + ((TRIBE_Master_Building_Object*)master)->building_facet);
                if (this->bldg_pics != nullptr) {
                    pic_set = this->bldg_pics[age];
                } else {
                    pic_set = nullptr;
                }
            }

            if (pic_set != nullptr) {
                RGE_Color_Table* color_table = (obj->owner != nullptr) ? obj->owner->color_table : nullptr;
                uchar* color_xform = nullptr;
                uchar use_color_xform = 0;
                if (color_table != nullptr) {
                    _ASMSet_Color_Xform((color_table->id + 1) * 0x10);
                    color_xform = color_table->table;
                    use_color_xform = 1;
                }
                pic_set->shape_draw(this->render_area, this->pnl_x + 3, this->pnl_y + 0x1E, button_pic, use_color_xform, color_xform);
            }
        }

        if (obj->hp > 0.0f && this->health_pic != nullptr) {
            long frame = 0;
            long shape_count = this->health_pic->shape_count();
            if (shape_count > 0 && master->hp > 0) {
                frame = panel_ftol((float)(int)shape_count - ((float)(int)shape_count * obj->hp) / (float)(int)master->hp);
            }
            if (frame < 0) frame = 0;
            if (shape_count > 0 && frame > shape_count - 1) frame = shape_count - 1;
            this->health_pic->shape_draw(this->render_area, this->pnl_x + 3, this->pnl_y + 0x54, frame, 0, nullptr);
        }

        this->render_area->Unlock((char*)"tpnl_obj::draw");
    }

    void* dc_ptr = this->render_area->GetDc((char*)"tpnl_obj::draw");
    if (dc_ptr != nullptr) {
        HDC dc = (HDC)this->render_area->DrawDc;
        SetBkMode(dc, 1);
        SetTextColor(dc, 0x00FFFFFF);
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, this->font);

        RGE_Static_Object* obj = this->game_obj;
        RGE_Master_Static_Object* master = obj->master_obj;

        if (obj->owner != nullptr && obj->owner->id != 0) {
            char owner_name[100];
            owner_name[0] = '\0';
            if (rge_base_game != nullptr && rge_base_game->campaignGame() != 0 && obj->owner->world != nullptr && obj->owner->world->scenario != nullptr) {
                panel_copy_string(owner_name, sizeof(owner_name), obj->owner->world->scenario->GetPlayerName((int)obj->owner->id - 1));
            }
            if (owner_name[0] == '\0' && rge_base_game != nullptr) {
                rge_base_game->get_string2(0x69, obj->owner->master_player_id, 0, owner_name, 100);
            }
            TextOutA(dc, this->pnl_x + 3, this->pnl_y - 2, owner_name, (int)std::strlen(owner_name));
        }

        char obj_name[100];
        if (master->string_id > 0 && rge_base_game != nullptr) {
            rge_base_game->get_string((long)master->string_id, obj_name, 100);
        } else {
            obj_name[0] = '\0';
        }
        if (obj_name[0] == '\0') {
            panel_copy_string(obj_name, sizeof(obj_name), master->name);
        }

        char line[100];
        if (panel_show_obj_id() == 0) {
            std::sprintf(line, "%s", obj_name);
        } else {
            std::sprintf(line, "%d-%s", obj->id, obj_name);
        }
        TextOutA(dc, this->pnl_x + 3, this->pnl_y + 0x0D, line, (int)std::strlen(line));

        if (obj->hp > 0.0f) {
            std::sprintf(line, "%d/%d", (int)panel_ftol(obj->hp), (int)master->hp);
            TextOutA(dc, this->pnl_x + 3, this->pnl_y + 0x5C, line, (int)std::strlen(line));
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, nullptr);
        this->render_area->ReleaseDc((char*)"tpnl_obj::draw");
    }

    auto finish_draw = [this]() { this->draw_finish(); };

    RGE_Static_Object* obj = this->game_obj;
    RGE_Master_Static_Object* master = obj->master_obj;
    int row = 0;
    short work_type = 0;
    short work_target = 0;
    short progress = 0;
    short temp_progress = 0;
    char work_name[100];
    work_name[0] = '\0';

    const unsigned char unit_level = master->unit_level;
    if (unit_level == 3 || unit_level == 9 || unit_level == 4 || unit_level == 5 || unit_level == 6 || unit_level == 7) {
        if (unit_level == 3 || unit_level == 4) {
            short cur_weapon = 0;
            short orig_weapon = 0;
            ((RGE_Combat_Object*)obj)->get_weapon(cur_weapon, orig_weapon);
            this->draw_item(0, 7, ValueTypeBonus, (int)orig_weapon, (int)cur_weapon);
            row = 1;
        }

        short cur_armor = 0;
        short orig_armor = 0;
        ((RGE_Combat_Object*)obj)->get_armor(cur_armor, orig_armor);
        if (orig_armor > 0 || unit_level == 4 || unit_level == 6) {
            this->draw_item(row, 8, ValueTypeBonus, (int)orig_armor, (int)cur_armor);
            row++;
        }

        short cur_pierce = 0;
        short orig_pierce = 0;
        panel_get_pierce_armor(obj, cur_pierce, orig_pierce);
        if (cur_pierce > 0) {
            this->draw_item(row, 10, ValueTypeBonus, (int)orig_pierce, (int)cur_pierce);
            row++;
        }

        if (unit_level == 4 || unit_level == 6) {
            float cur_range = 0.0f;
            float orig_range = 0.0f;
            ((RGE_Combat_Object*)obj)->get_weapon_range(cur_range, orig_range);
            if (cur_range > kRangeThreshold) {
                this->draw_item(row, 6, ValueTypeBonus, (int)panel_ftol(orig_range), (int)panel_ftol(cur_range));
                row++;
            }
        }

        if (unit_level == 6) {
            this->draw_item(row, 9, ValueTypePercent, panel_ftol_biased(obj->attribute_amount_held), 0);
            row++;
        }

        if (obj->owner == this->player) {
            if (unit_level == 7) {
                const int cur = (obj->objects != nullptr) ? obj->objects->number_of_objects : 0;
                this->draw_item(row, 4, ValueTypeCompare, cur, master->obj_max);
                finish_draw();
                return;
            }

            if (unit_level == 9) {
                int val = 0;
                if (obj->attribute_type_held == 0x11 || obj->attribute_type_held == 0) {
                    val = panel_ftol_biased(obj->attribute_amount_held);
                }
                this->draw_item(row, 2, ValueTypeNumber, val, 0);
                finish_draw();
                return;
            }

            if (unit_level == 5) {
                int icon = panel_resource_icon(obj->attribute_type_held);
                if (icon == -1) {
                    finish_draw();
                    return;
                }
                if (obj->attribute_amount_held > 0.0f) {
                    this->draw_item(row, 3, ValueTypeNumber, panel_ftol_biased(obj->attribute_amount_held), 0);
                    finish_draw();
                    return;
                }
                this->draw_item(row, icon, ValueTypePercent, -1, 0);
                finish_draw();
                return;
            }

            const int held = panel_ftol_biased(obj->attribute_amount_held);
            if (held > 0) {
                const int icon = panel_resource_icon(obj->attribute_type_held);
                if (icon == -1) {
                    finish_draw();
                    return;
                }
                this->draw_item(row, icon, ValueTypeNumber, held, 0);
                finish_draw();
                return;
            }
        }
    } else if (unit_level == 1) {
        const int icon = panel_resource_icon(obj->attribute_type_held);
        if (icon == -1) {
            finish_draw();
            return;
        }
        this->draw_item(0, icon, ValueTypeNumber, panel_ftol_biased(obj->attribute_amount_held), 0);
        finish_draw();
        return;
    } else if (unit_level == 2 || unit_level == 8) {
        if (master->master_type == 'P') {
            TRIBE_Building_Object* building = (TRIBE_Building_Object*)obj;
            panel_work_status(building, &work_type, &work_target, &progress, work_name, 100);
            if (work_type != 0x67 && work_type != 0x66 && panel_production_queue_status(building, &work_target, &temp_progress) != 0) {
                work_type = 0x66;
                progress = temp_progress;
            }

            if (obj->object_state != 0 && (obj->owner != this->player || (work_type != 0x67 && work_type != 0x66))) {
                short cur_weapon = 0;
                short orig_weapon = 0;
                ((RGE_Combat_Object*)obj)->get_weapon(cur_weapon, orig_weapon);
                if (orig_weapon > 0) {
                    this->draw_item(0, 7, ValueTypeBonus, (int)orig_weapon, (int)cur_weapon);
                    row = 1;
                }

                float cur_range = 0.0f;
                float orig_range = 0.0f;
                ((RGE_Combat_Object*)obj)->get_weapon_range(cur_range, orig_range);
                int cur_range_i = (int)panel_ftol(cur_range);
                if (cur_range_i > 0) {
                    this->draw_item(row, 6, ValueTypeBonus, (int)panel_ftol(orig_range), cur_range_i);
                    row++;
                }
            }

            if (obj->owner == this->player) {
                if (building->object_state == 0) {
                    this->draw_item(row, 9, ValueTypePercent, (int)panel_get_construction_progress(building), 0);
                } else if (work_type == 0x67 || work_type == 0x66) {
                    this->draw_item(row, 9, ValueTypePercent, (int)progress, 0);
                } else {
                    if (master->id == 0x46 && obj->owner != nullptr && obj->owner->attributes != nullptr) {
                        int pop = (int)panel_ftol(obj->owner->attributes[11]);
                        int max_pop = (int)panel_ftol(obj->owner->attributes[4] + obj->owner->attributes[11]);
                        int max_pop_cap = (int)panel_ftol(obj->owner->attributes[32]);
                        if (max_pop_cap < max_pop) {
                            max_pop_cap = max_pop;
                        }
                        this->draw_item(row, 4, ValueTypeCompare, pop, max_pop_cap);
                        row++;
                    }
                    if (master->id == 0x32 && building->production_queue_actions != nullptr) {
                        RGE_Action* action = building->production_queue_actions->get_action();
                        if (action != nullptr) {
                            int farm_amt = panel_ftol_biased(action->timer + obj->attribute_amount_held);
                            this->draw_item(row, 2, ValueTypeNumber, farm_amt, 0);
                        }
                    }
                }
                row++;
            }
        }

        if (obj->object_state != 0 && obj->object_state == 2) {
            bool show_resource = false;
            if (obj->owner == this->player) {
                if (work_type != 0x67 && work_type != 0x66) {
                    if (master->id == 0x2D) {
                        show_resource = true;
                    } else if (master->id == 0x32) {
                        show_resource = false;
                    } else if (obj->attribute_type_held != -1 && panel_ftol(obj->attribute_amount_held) > 0) {
                        show_resource = true;
                    }
                }
            } else if (master->id == 0x2D) {
                show_resource = true;
            }

            if (show_resource) {
                int icon = panel_resource_icon(obj->attribute_type_held);
                if (icon == -1) {
                    finish_draw();
                    return;
                }
                this->draw_item(row, icon, ValueTypeNumber, panel_ftol_biased(obj->attribute_amount_held), 0);
                row++;
            }
        }

        if (master->id == 0x2D && obj->owner != this->player) {
            RGE_Player* local_player = (rge_base_game != nullptr) ? rge_base_game->get_player() : nullptr;
            RGE_Static_Object* target = nullptr;
            if (local_player != nullptr && local_player->objects != nullptr) {
                target = local_player->objects->find_by_master_ids(0x2D, 0x2D, obj->world_x, obj->world_y, 1, 2, obj);
            }
            if (target != nullptr) {
                const float dx = target->world_x - obj->world_x;
                const float dy = target->world_y - obj->world_y;

                float value = ((dy * dy) + (dx * dx)) * kDistanceScale0 * kDistanceScale1;
                if (this->player != nullptr && this->player->master_player_id == 0x0F) {
                    value += value;
                }
                if (value >= kDistanceClamp) {
                    value = kDistanceClamp;
                }

                value *= kDistanceToValue;
                if (value > kDistanceValueMax) {
                    value = kDistanceValueMax;
                }

                this->draw_item(row, 3, ValueTypeCompare, panel_ftol_biased(value), 20);
            }
        }
    }

    finish_draw();
}

void TRIBE_Panel_Object::draw_score() {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051BF90
    if (this->render_area == nullptr || this->active == 0 || this->visible == 0) {
        this->need_redraw = TPanel::NoRedraw;
        return;
    }

    this->draw_setup(0);
    this->render_area->Clear(&this->clip_rect, 0);

    void* dc_ptr = this->render_area->GetDc((char*)"tpnl_obj::draw_score");
    if (dc_ptr != nullptr) {
        HDC dc = (HDC)this->render_area->DrawDc;
        SetBkMode(dc, 1);
        SetTextColor(dc, 0x00FFFFFF);
        HGDIOBJ old_font = SelectObject(dc, this->font);

        const short x = (short)this->pnl_x + 3;
        const short x_val = (short)this->pnl_x + 0x5A;
        const short y_base = (short)this->pnl_y - 1;
        int y_off = 0;

        for (int i = 1; i < 9; ++i) {
            int player_id = rge_base_game->playerID(i);
            if (player_id != 0 && player_id < rge_base_game->world->player_num) {
                RGE_Player* temp_player = rge_base_game->world->players[player_id];
                unsigned long color = 0x00FFFFFF;
                int color_id = (temp_player != nullptr && temp_player->color_table != nullptr) ? temp_player->color_table->id : -1;
                switch (color_id) {
                case 0:
                    color = 0x00FF0000;
                    break;
                case 1:
                    color = 0x002139C6;
                    break;
                case 2:
                    color = 0x0000FFFF;
                    break;
                case 3:
                    color = 0x004F73A3;
                    break;
                case 4:
                    color = 0x000F77F3;
                    break;
                case 5:
                    color = 0x0000C700;
                    break;
                case 6:
                    color = 0x007B90A2;
                    break;
                case 7:
                    color = 0x00ADAD00;
                    break;
                default:
                    color = 0x00FFFFFF;
                    break;
                }
                SetTextColor(dc, color);

                char str[100];
                str[0] = '\0';
                if (comm != nullptr) {
                    panel_copy_string(str, sizeof(str), ((TCommunications_Handler*)comm)->GetPlayerName(i));
                }

                int y = y_base + y_off;
                TextOutA(dc, x, y, str, (int)std::strlen(str));

                long points = (temp_player != nullptr && temp_player->victory_conditions != nullptr)
                                  ? temp_player->victory_conditions->get_victory_points()
                                  : 0;
                std::sprintf(str, "%d", points);

                tagRECT rect;
                SetRect(&rect, x_val, y, this->pnl_x + this->pnl_wid - 3, y + 0x0E);
                DrawTextA(dc, str, -1, &rect, 0x22);
                y_off += 0x0E;
            }
        }

        SelectObject(dc, old_font);
        this->render_area->ReleaseDc((char*)"tpnl_obj::draw_score");
    }

    this->draw_finish();
}

void TRIBE_Panel_Object::draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051C220
    if (this->item_pic != nullptr && param_2 != -1 && this->render_area->Lock((char*)"tpnl_obj::draw_item", 1) != nullptr) {
        this->item_pic->shape_draw(this->render_area, this->pnl_x + 0x36, this->pnl_y + 0x1E + param_1 * 0x14, param_2, 0, nullptr);
        this->render_area->Unlock((char*)"tpnl_obj::draw_item");
    }

    char val_str[20];
    switch (param_3) {
    case ValueTypeNumber:
        std::sprintf(val_str, "%d", param_4);
        break;
    case ValueTypeBonus:
        if (param_4 < param_5) {
            std::sprintf(val_str, "%d+%d", param_4, param_5 - param_4);
        } else {
            std::sprintf(val_str, "%d", param_4);
        }
        break;
    case ValueTypeCompare:
        std::sprintf(val_str, "%d/%d", param_4, param_5);
        break;
    case ValueTypePercent:
        std::sprintf(val_str, "%d%%", param_4);
        break;
    default:
        val_str[0] = '\0';
        break;
    }

    if (val_str[0] == '\0') return;

    void* dc_ptr = this->render_area->GetDc((char*)"tpnl_obj::draw_item");
    if (dc_ptr == nullptr) return;

    HDC dc = (HDC)this->render_area->DrawDc;
    SetBkMode(dc, 1);
    SetTextColor(dc, 0x00FFFFFF);
    HGDIOBJ old_font = SelectObject(dc, this->font);

    TextOutA(dc, this->pnl_x + 0x58, this->pnl_y + 0x21 + param_1 * 0x14, val_str, (int)std::strlen(val_str));

    SelectObject(dc, old_font);
    this->render_area->ReleaseDc((char*)"tpnl_obj::draw_item");
}

long TRIBE_Panel_Object::handle_idle() {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051C3F0
    TPanel::handle_idle();
    if (this->visible == 0) {
        return 0;
    }

    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp", 0x37C);
    if (now - this->idle_time < this->idle_interval) {
        return 0;
    }

    this->idle_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp", 0x37F);

    if (this->mode == 2) {
        for (int i = 1; i < 9; ++i) {
            int player_id = rge_base_game->playerID(i);
            if (player_id != 0) {
                long score = rge_base_game->world->players[player_id]->victory_conditions->get_victory_points();
                if (this->save_score[player_id] != score) {
                    if (this->need_redraw == 0) {
                        this->set_redraw(TPanel::Redraw);
                    }
                    this->save_object_info();
                    return 0;
                }
            }
        }
        return 0;
    }

    TRIBE_Player* panel_player = this->player;
    if (panel_player == nullptr) {
        if (this->game_obj != nullptr) {
            this->set_object(nullptr);
            return 0;
        }
    } else if (panel_player->selected_obj != this->game_obj) {
        this->set_object(panel_player->selected_obj);
        return 0;
    }

    RGE_Action_Object* obj = (RGE_Action_Object*)this->game_obj;
    bool changed = false;
    bool do_buttons = false;
    bool full_refresh = false;

    if (obj == nullptr) goto done_checks;

    if (obj->owner == this->save_owner) {
        if (obj->selected_group == this->save_selected_group) {
            if (obj->master_obj == this->save_obj_type) {
                short object_count = (obj->objects != nullptr) ? obj->objects->number_of_objects : 0;
                if (object_count == this->save_number_of_objects) {
                    if (obj->attribute_type_held != this->save_attr_type || obj->attribute_amount_held != this->save_attr_amount || obj->hp != this->save_hp ||
                        (obj->objects != nullptr ? obj->objects->list : nullptr) != this->save_list || obj->master_obj->los != this->save_los ||
                        obj->master_obj->id == 0x2D) {
                        changed = true;
                        do_buttons = true;
                    }
                } else {
                    changed = true;
                    do_buttons = true;
                    if (object_count == 0 || this->save_number_of_objects == 0) {
                        full_refresh = true;
                    }
                }
            } else {
                changed = true;
                do_buttons = true;
                full_refresh = true;
            }
        } else {
            changed = true;
            do_buttons = true;
            full_refresh = true;
        }
    } else {
        changed = true;
        do_buttons = true;
        full_refresh = true;
    }

    if (!changed) {
        const unsigned char master_type = obj->master_obj->master_type;
        if (master_type >= 0x46 && master_type != 0x5A) {
            if (obj->have_action() != this->save_have_action) {
                changed = true;
                do_buttons = true;
                full_refresh = true;
            }
            if (!changed) {
                short cur = 0;
                short orig = 0;
                ((RGE_Combat_Object*)obj)->get_armor(cur, orig);
                if (cur != this->save_armor) {
                    changed = true;
                    do_buttons = true;
                }
                if (!changed) {
                    panel_get_pierce_armor((RGE_Static_Object*)obj, cur, orig);
                    if (cur != this->save_pierce_armor) {
                        changed = true;
                        do_buttons = true;
                    }
                    if (!changed) {
                        ((RGE_Combat_Object*)obj)->get_weapon(cur, orig);
                        if (cur != this->save_weapon) {
                            changed = true;
                            do_buttons = true;
                        }
                        if (!changed) {
                            float cur_f = 0.0f;
                            float orig_f = 0.0f;
                            ((RGE_Combat_Object*)obj)->get_weapon_range(cur_f, orig_f);
                            if (cur_f != this->save_weapon_range) {
                                changed = true;
                                do_buttons = true;
                            }
                            if (!changed) {
                                ((RGE_Combat_Object*)obj)->get_speed_of_attack(cur_f, orig_f);
                                if (cur_f != this->save_speed_of_attack) {
                                    changed = true;
                                    do_buttons = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!changed || !full_refresh) {
        TRIBE_Building_Object* building = (TRIBE_Building_Object*)this->game_obj;
        if (building->master_obj->master_type == 'P') {
            if (building->object_state != this->save_object_state) {
                changed = true;
                do_buttons = true;
                full_refresh = true;
            }

            if (!changed || !full_refresh) {
                short construction = panel_get_construction_progress(building);
                if ((float)(int)construction != this->save_build_pts) {
                    changed = true;
                    do_buttons = true;
                    if ((float)(int)construction > kProgressDoneThreshold) {
                        full_refresh = true;
                    }
                }
            }

            if (!changed || !full_refresh) {
                short cur_work_type = 0;
                short cur_work_target = 0;
                short cur_progress = 0;
                char name[100];
                name[0] = '\0';
                panel_work_status(building, &cur_work_type, &cur_work_target, &cur_progress, name, 100);
                if (cur_work_type != 0x67 && cur_work_type != 0x66 && panel_production_queue_status(building, &cur_work_target, &cur_progress) != 0) {
                    cur_work_type = 0x66;
                }

                if (!(cur_work_type == this->save_work_type && cur_work_target == this->save_work_target && cur_progress == this->save_progress &&
                      panel_string_equals(name, this->save_name))) {
                    changed = true;
                    if (!(cur_work_type == this->save_work_type && cur_work_target == this->save_work_target &&
                          panel_string_equals(name, this->save_name))) {
                        full_refresh = true;
                    }
                }
            }

            if ((!changed || !full_refresh) && this->game_obj->master_obj->id == 0x46 && this->game_obj->owner != nullptr && this->game_obj->owner->attributes != nullptr) {
                int pop = (int)panel_ftol(this->game_obj->owner->attributes[11]);
                int max_pop = (int)panel_ftol(this->game_obj->owner->attributes[4]);
                if (pop != this->save_pop || max_pop != this->save_max_pop) {
                    changed = true;
                }
            }

            if ((!changed || !full_refresh) && this->game_obj->owner == this->player && this->game_obj->master_obj->id == 0x32) {
                RGE_Action* action = building->production_queue_actions != nullptr ? building->production_queue_actions->get_action() : nullptr;
                if (action != nullptr) {
                    int farm_amt = panel_ftol_biased(action->timer + this->game_obj->attribute_amount_held);
                    if (this->save_farm_amt != farm_amt) {
                        changed = true;
                    }
                }
            }
        }
    }

done_checks:
    if (changed) {
        if (this->need_redraw == 0) {
            this->set_redraw(TPanel::Redraw);
        }
        this->save_object_info();
        if (full_refresh && this->parent_panel != nullptr) {
            this->parent_panel->action(this, 1, 0, 0);
        }
    }
    return 0;
}

void TRIBE_Panel_Object::save_object_info() {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051CA10
    if (this->mode == 2) {
        for (int i = 1; i < 9; ++i) {
            int player_id = rge_base_game->playerID(i);
            if (player_id != 0 && player_id < rge_base_game->world->player_num) {
                this->save_score[player_id] = rge_base_game->world->players[player_id]->victory_conditions->get_victory_points();
            }
        }
        return;
    }

    RGE_Action_Object* obj = (RGE_Action_Object*)this->game_obj;
    if (obj == nullptr) return;

    this->save_selected_group = obj->selected_group;
    this->save_obj_type = obj->master_obj;
    this->save_attr_type = obj->attribute_type_held;
    this->save_attr_amount = obj->attribute_amount_held;
    this->save_hp = obj->hp;
    this->save_list = (obj->objects != nullptr) ? obj->objects->list : nullptr;
    this->save_number_of_objects = (obj->objects != nullptr) ? obj->objects->number_of_objects : 0;
    this->save_los = obj->master_obj->los;
    this->save_owner = obj->owner;

    const unsigned char master_type = obj->master_obj->master_type;
    if (master_type >= 0x46 && master_type != 0x5A) {
        this->save_have_action = obj->have_action();

        short cur = 0;
        short orig = 0;
        ((RGE_Combat_Object*)obj)->get_armor(cur, orig);
        this->save_armor = cur;

        panel_get_pierce_armor((RGE_Static_Object*)obj, cur, orig);
        this->save_pierce_armor = cur;

        ((RGE_Combat_Object*)obj)->get_weapon(cur, orig);
        this->save_weapon = cur;

        float cur_f = 0.0f;
        float orig_f = 0.0f;
        ((RGE_Combat_Object*)obj)->get_weapon_range(cur_f, orig_f);
        this->save_weapon_range = cur_f;

        ((RGE_Combat_Object*)obj)->get_speed_of_attack(cur_f, orig_f);
        this->save_speed_of_attack = cur_f;
    }

    TRIBE_Building_Object* building = (TRIBE_Building_Object*)this->game_obj;
    if (building->master_obj->master_type == 'P') {
        this->save_object_state = building->object_state;
        this->save_build_pts = (float)(int)panel_get_construction_progress(building);

        panel_work_status(building, &this->save_work_type, &this->save_work_target, &this->save_progress, this->save_name, 100);
        if (this->save_work_type != 0x67 && this->save_work_type != 0x66) {
            short queued_progress = 0;
            if (panel_production_queue_status(building, &this->save_work_target, &queued_progress) != 0) {
                this->save_work_type = 0x66;
                this->save_progress = queued_progress;
            }
        }

        if (building->owner != nullptr && building->owner->attributes != nullptr) {
            this->save_pop = (int)panel_ftol(building->owner->attributes[11]);
            this->save_max_pop = (int)panel_ftol(building->owner->attributes[4]);
        } else {
            this->save_pop = 0;
            this->save_max_pop = 0;
        }

        if (this->game_obj->owner == this->player && this->game_obj->master_obj->id == 0x32 && building->production_queue_actions != nullptr) {
            RGE_Action* action = building->production_queue_actions->get_action();
            if (action != nullptr) {
                this->save_farm_amt = panel_ftol_biased(action->timer + this->game_obj->attribute_amount_held);
            }
        }
    }
}

long TRIBE_Panel_Object::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051CC80
    return 0;
}

long TRIBE_Panel_Object::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: tpnl_obj.cpp.asm @ 0x0051CC90
    return 0;
}

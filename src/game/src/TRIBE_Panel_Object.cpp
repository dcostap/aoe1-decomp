#include "../include/TRIBE_Panel_Object.h"

#include "../include/TShape.h"
#include <string.h>

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
    memset(this->save_score, 0, sizeof(this->save_score));

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
    this->player = player_param;
    this->set_object(nullptr);
}

void TRIBE_Panel_Object::set_object(RGE_Static_Object* obj) {
    this->game_obj = obj;
    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Panel_Object::set_mode(unsigned char mode_param) {
    this->mode = mode_param;
    this->set_redraw(TPanel::Redraw);
}

unsigned char TRIBE_Panel_Object::get_mode() {
    return this->mode;
}

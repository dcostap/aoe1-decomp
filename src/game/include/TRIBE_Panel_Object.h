#pragma once

#include "TPanel.h"

class TRIBE_Panel_Object : public TPanel {
public:
    enum ValueType : int {
        ValueTypeNumber = 0,
        ValueTypeBonus = 1,
        ValueTypeCompare = 2,
        ValueTypePercent = 3,
    };

    TRIBE_Panel_Object(
        TDrawArea* area,
        TPanel* parent,
        void* font,
        long font_wid,
        long font_hgt,
        TShape* unit_pics,
        TShape** bldg_pics,
        TRIBE_Player* player);
    virtual ~TRIBE_Panel_Object();
    virtual void draw() override;
    virtual long handle_idle() override;
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) override;

    void set_player(TRIBE_Player* player);
    void set_object(RGE_Static_Object* obj);
    void set_mode(unsigned char mode);
    unsigned char get_mode();

protected:
    void draw_score();
    virtual void draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5);
    void save_object_info();

public:
    void* font;
    long font_wid;
    long font_hgt;
    TShape* health_pic;
    TShape* item_pic;
    TShape* unit_pics;
    TShape** bldg_pics;
    TRIBE_Player* player;
    RGE_Static_Object* game_obj;
    unsigned long idle_time;
    unsigned long idle_interval;
    unsigned char mode;
    RGE_Master_Static_Object* save_obj_type;
    RGE_Sprite* save_sprite;
    short save_attr_type;
    float save_attr_amount;
    unsigned char save_object_state;
    float save_build_pts;
    RGE_Object_Node* save_list;
    short save_number_of_objects;
    unsigned char save_can_debark;
    float save_world_x;
    float save_world_y;
    float save_hp;
    short save_armor;
    short save_pierce_armor;
    short save_weapon;
    float save_weapon_range;
    float save_speed_of_attack;
    short save_work_type;
    short save_work_target;
    short save_progress;
    char save_name[100];
    unsigned char save_facet;
    float save_angle;
    float save_los;
    int save_pop;
    int save_max_pop;
    unsigned char save_selected_group;
    RGE_Player* save_owner;
    int save_age;
    unsigned char save_have_action;
    int save_score[9];
    int save_farm_amt;
};

static_assert(sizeof(TRIBE_Panel_Object) == 0x214, "Size mismatch");

#pragma once
#include "../common.h"

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* victory_list;         // 0x4
    long list_num;                           // 0x8
    RGE_Player* player;                      // 0xC
    uchar victory;                           // 0x10
    RGE_Victory_Point_Entry* victory_point_list; // 0x14
    long point_list_num;                     // 0x18
    long tot_victory_points;                 // 0x1C

    RGE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4);
    RGE_Victory_Conditions(RGE_Player* param_1);
    virtual ~RGE_Victory_Conditions();
    virtual void save(int param_1);
    virtual void check_for_victory();
    virtual uchar update();
    virtual void update_for_object(RGE_Static_Object* param_1);
    virtual void handle_point_condition(RGE_Victory_Point_Entry* param_1);
    virtual void handle_condition(RGE_Victory_Entry* param_1);
    virtual void handle_capture(RGE_Victory_Entry* param_1);
    virtual void handle_create(RGE_Victory_Entry* param_1);
    virtual void handle_create_in_area(RGE_Victory_Entry* param_1);
    virtual void handle_destroy(RGE_Victory_Entry* param_1);
    virtual void handle_destroy_multiple(RGE_Victory_Entry* param_1);
    virtual void handle_destroy_all(RGE_Victory_Entry* param_1);
    virtual void handle_destroy_player(RGE_Victory_Entry* param_1);
    virtual void handle_bring_area(RGE_Victory_Entry* param_1);
    virtual void handle_bring_object(RGE_Victory_Entry* param_1);
    virtual void handle_attribute(RGE_Victory_Entry* param_1);
    virtual void handle_explore(RGE_Victory_Entry* param_1);
    virtual void handle_victory_points(RGE_Victory_Entry* param_1);
    virtual RGE_Victory_Entry* add(uchar param_1, uchar param_2);
    virtual uchar add_capture(uchar param_1, RGE_Static_Object* param_2, uchar param_3);
    virtual uchar add_create(uchar param_1, long param_2, long param_3, uchar param_4);
    virtual uchar add_create(uchar param_1, long param_2, long param_3, float param_4, float param_5, float param_6, float param_7, uchar param_8);
    virtual uchar add_destroy(uchar param_1, RGE_Static_Object* param_2);
    virtual uchar add_destroy(uchar param_1, long param_2, long param_3, RGE_Player* param_4);
    virtual uchar add_destroy(uchar param_1, long param_2, RGE_Player* param_3);
    virtual uchar add_destroy(uchar param_1, RGE_Player* param_2);
    virtual uchar add_bring(uchar param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3);
    virtual uchar add_bring(uchar param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5, float param_6);
    virtual uchar add_attributes(uchar param_1, long param_2, long param_3, uchar param_4);
    virtual uchar add_explore(uchar param_1, long param_2, uchar param_3);
    virtual uchar add_victory_points(uchar param_1, long param_2, uchar param_3);
    virtual void sub(RGE_Victory_Entry* param_1);
    virtual void destroy_all();
    virtual uchar condition_info(long param_1, char** param_2, uchar* param_3);
    virtual char* condition_description(RGE_Victory_Entry* param_1);
    virtual RGE_Victory_Entry* condition_raw_info(long param_1);
    virtual long condition_number(long param_1);
    virtual uchar victory_achieved();
    virtual uchar remove_condition(long param_1);
    virtual RGE_Victory_Point_Entry* add_point(uchar param_1, uchar param_2);
    virtual void sub_point(RGE_Victory_Point_Entry* param_1);
    virtual uchar add_points_attribute_amount(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    virtual uchar add_points_attribute_first(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    virtual uchar add_points_highest_attribute(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    virtual uchar add_points_high_attribute_once(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    virtual uchar add_points_high_attribute_amount(uchar param_1, uchar param_2, long param_3, long param_4, long param_5);
    virtual void handle_points_attribute_amount(RGE_Victory_Point_Entry* param_1);
    virtual void handle_points_attribute_first(RGE_Victory_Point_Entry* param_1);
    virtual void handle_points_highest_attribute(RGE_Victory_Point_Entry* param_1);
    virtual void handle_points_high_attribute_once(RGE_Victory_Point_Entry* param_1);
    virtual void handle_points_high_attribute_amount(RGE_Victory_Point_Entry* param_1);
    virtual long get_victory_points();
    virtual long get_victory_points_group(uchar param_1);
    virtual long get_victory_points_id(uchar param_1);
    virtual long get_attribute_id(uchar param_1);
};

static_assert(sizeof(RGE_Victory_Conditions) == 0x20, "RGE_Victory_Conditions Size Mismatch");
static_assert(offsetof(RGE_Victory_Conditions, tot_victory_points) == 0x1C, "RGE_Victory_Conditions Offset Mismatch");


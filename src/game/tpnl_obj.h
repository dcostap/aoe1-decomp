#pragma once
#include "common.h"

enum ActionType : unsigned int {
    ActionObjectChanged = 1,
};

enum ValueType : unsigned int {
    ValueTypeNumber = 0,
    ValueTypeBonus = 1,
    ValueTypeCompare = 2,
    ValueTypePercent = 3,
    ValueTypeNone = 4,
};

class TRIBE_Panel_Object : public TPanel {
public:
    void* font;                              // 0xF4
    long font_wid;                           // 0xF8
    long font_hgt;                           // 0xFC
    TShape* health_pic;                      // 0x100
    TShape* item_pic;                        // 0x104
    TShape* unit_pics;                       // 0x108
    TShape** bldg_pics;                      // 0x10C
    TRIBE_Player* player;                    // 0x110
    RGE_Static_Object* game_obj;             // 0x114
    ulong idle_time;                         // 0x118
    ulong idle_interval;                     // 0x11C
    uchar mode;                              // 0x120
    RGE_Master_Static_Object* save_obj_type; // 0x124
    RGE_Sprite* save_sprite;                 // 0x128
    short save_attr_type;                    // 0x12C
    float save_attr_amount;                  // 0x130
    uchar save_object_state;                 // 0x134
    float save_build_pts;                    // 0x138
    RGE_Object_Node* save_list;              // 0x13C
    short save_number_of_objects;            // 0x140
    uchar save_can_debark;                   // 0x142
    float save_world_x;                      // 0x144
    float save_world_y;                      // 0x148
    float save_hp;                           // 0x14C
    short save_armor;                        // 0x150
    short save_pierce_armor;                 // 0x152
    short save_weapon;                       // 0x154
    float save_weapon_range;                 // 0x158
    float save_speed_of_attack;              // 0x15C
    short save_work_type;                    // 0x160
    short save_work_target;                  // 0x162
    short save_progress;                     // 0x164
    char save_name[100];                     // 0x166
    uchar save_facet;                        // 0x1CA
    float save_angle;                        // 0x1CC
    float save_los;                          // 0x1D0
    int save_pop;                            // 0x1D4
    int save_max_pop;                        // 0x1D8
    uchar save_selected_group;               // 0x1DC
    RGE_Player* save_owner;                  // 0x1E0
    int save_age;                            // 0x1E4
    uchar save_have_action;                  // 0x1E8
    int save_score[9];                       // 0x1EC
    int save_farm_amt;                       // 0x210

    virtual void draw();                                    // vt0[12]+0x30=0x51B190
    virtual long handle_idle();                             // vt0[19]+0x4C=0x51C3F0
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[33]+0x84=0x51CC80
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[36]+0x90=0x51CC90
    virtual void draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5); // vt0[56]+0xE0=0x51C220
    TRIBE_Panel_Object(TDrawArea* param_1, TPanel* param_2, void* param_3, long param_4, long param_5, TShape* param_6, TShape** param_7, TRIBE_Player* param_8);
    ~TRIBE_Panel_Object();
    void set_player(TRIBE_Player* param_1);
    void set_object(RGE_Static_Object* param_1);
    void set_mode(uchar param_1);
    uchar get_mode();
    void draw_score();
    void save_object_info();
};

static_assert(sizeof(TRIBE_Panel_Object) == 0x214, "TRIBE_Panel_Object Size Mismatch");


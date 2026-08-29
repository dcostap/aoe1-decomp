#ifndef AOE1_TPNL_OBJ_H
#define AOE1_TPNL_OBJ_H

// The panel base is owned by panel.cpp.  This header owns only the panel
// object declared by this source module.
#include "panel.h"

class TDrawArea;
class TShape;
class TRIBE_Player;
class TRIBE_Building_Object;
class RGE_Master_Static_Object;
class RGE_Sprite;
class RGE_Static_Object;
struct RGE_Object_Node;

class TRIBE_Panel_Object : public TPanel {
public:
    enum ValueType {
        ValueTypeNumber,
        ValueTypeBonus,
        ValueTypeCompare,
        ValueTypePercent,
        ValueTypeNone
    };

    void* font;
    long font_wid;
    long font_hgt;
    TShape* health_pic;
    TShape* item_pic;
    TShape* unit_pics;
    TShape** bldg_pics;
    TRIBE_Player* player;
    TRIBE_Building_Object* game_obj;
    unsigned long idle_time;
    unsigned long idle_interval;
    unsigned char mode;
    unsigned char gap_121[3];
    RGE_Master_Static_Object* save_obj_type;
    RGE_Sprite* save_sprite;
    short save_attr_type;
    unsigned char gap_12E[2];
    float save_attr_amount;
    unsigned char save_object_state;
    unsigned char gap_135[3];
    float save_build_pts;
    RGE_Object_Node* save_list;
    short save_number_of_objects;
    unsigned char save_can_debark;
    unsigned char gap_143[1];
    float save_world_x;
    float save_world_y;
    float save_hp;
    short save_armor;
    short save_pierce_armor;
    short save_weapon;
    unsigned char gap_156[2];
    float save_weapon_range;
    float save_speed_of_attack;
    short save_work_type;
    short save_work_target;
    short save_progress;
    char save_name[100];
    unsigned char save_facet;
    unsigned char gap_1CB[1];
    float save_angle;
    float save_los;
    int save_pop;
    int save_max_pop;
    unsigned char save_selected_group;
    unsigned char gap_1DD[3];
    RGE_Player* save_owner;
    int save_age;
    unsigned char save_have_action;
    unsigned char gap_1E9[3];
    int save_score[9];
    int save_farm_amt;

    virtual ~TRIBE_Panel_Object();
    TRIBE_Panel_Object(TDrawArea*, TPanel*, void*, long, long, TShape*,
                       TShape**, TRIBE_Player*);
    virtual void draw();

protected:
    virtual void draw_item(int, int, ValueType, int, int);

public:
    virtual long handle_idle();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);

    void set_player(TRIBE_Player*);
    void set_object(RGE_Static_Object*);
    void set_mode(unsigned char);
    unsigned char get_mode();

protected:
    void draw_score();
    void save_object_info();
};

typedef char tpnl_obj_panel_size_check[
    (sizeof(TRIBE_Panel_Object) == 0x214) ? 1 : -1];

#endif  // AOE1_TPNL_OBJ_H

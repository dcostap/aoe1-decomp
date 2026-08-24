// VA: 0051ADF0 TRIBE_Panel_Object::TRIBE_Panel_Object (596B)
// PDB: tpnl_obj.cpp:49-116
// FLAGS: config/flags/tpnl_obj.rsp (/GX; constructor EH is
// present in the original around the two TShape allocations)
//
// Attempt log:
// - canonical baseline: real TPanel base/setup, named TRIBE panel fields,
//   natural save-score initialization, and owned TShape construction/load
//   cleanup.
// - binary-proven constructor ownership leaves save_number_of_objects,
//   save_world_x/y, and save_age uninitialized here.

#ifndef AOE1_TPNL_OBJ_CONTEXT_H
class TDrawArea;
class TShape;
class TRIBE_Player;
class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Sprite;
class RGE_Object_Node;

struct PanelNode;
struct HRGN__;
typedef HRGN__* HRGN;

class TPanel {
public:
    virtual ~TPanel();
    TPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    long clip_left;
    long clip_top;
    long clip_right;
    long clip_bottom;
    long position_mode;
    long need_redraw;
    long field_3C;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* curr_child;
    long field_64;
    long field_68;
    long active;
    long field_70;
    long have_focus;
    long field_78;
    long field_7C;
    long field_80;
    long gap_84;
    HRGN clip_rgn;
    long field_8C;
    long field_90;
    long field_94;
    long field_98;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long field_BC;
    long field_C0;
    long field_C4;
    long field_C8;
    long field_CC;
    long field_D0;
    long field_D4;
    long error_code;
    long field_DC;
    long field_E0;
    long field_E4;
    long field_E8;
    unsigned char field_EC;
    unsigned char field_ED;
    unsigned char field_EE;
    unsigned char field_EF;
    unsigned char field_F0;
    unsigned char gap_F1;
    unsigned char field_F2;
    unsigned char field_F3;
};

class TShape {
public:
    char shape_data[0x20];

    TShape(char*, int);
    ~TShape();
    int is_loaded();
};

extern char s_health_shp[];
extern char s_itemicon_shp[];

class TRIBE_Panel_Object : public TPanel {
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
    void set_player(TRIBE_Player*);
};
#endif

TRIBE_Panel_Object::TRIBE_Panel_Object(
    TDrawArea* draw_area, TPanel* parent, void* font_, long font_wid_,
    long font_hgt_, TShape* unit_pics_, TShape** bldg_pics_,
    TRIBE_Player* player_)
    : TPanel()
{
    this->font = font_;
    this->font_wid = font_wid_;
    this->font_hgt = font_hgt_;
    this->health_pic = 0;
    this->item_pic = 0;
    this->unit_pics = unit_pics_;
    this->bldg_pics = bldg_pics_;
    this->player = 0;
    this->game_obj = 0;
    this->idle_time = 0;
    this->idle_interval = 500;
    this->mode = 1;
    this->save_obj_type = 0;
    this->save_attr_type = -1;
    this->save_attr_amount = 0.0f;
    this->save_object_state = 0;
    this->save_build_pts = 0.0f;
    this->save_list = 0;
    this->save_hp = 0.0f;
    this->save_armor = 0;
    this->save_pierce_armor = 0;
    this->save_weapon = 0;
    this->save_weapon_range = 0.0f;
    this->save_speed_of_attack = 0.0f;
    this->save_work_type = 0;
    this->save_work_target = 0;
    this->save_progress = 0;
    this->save_name[0] = 0;
    this->save_facet = 0;
    this->save_angle = 0.0f;
    this->save_los = 0.0f;
    this->save_pop = 0;
    this->save_max_pop = 0;
    this->save_selected_group = 0;
    this->save_owner = 0;
    this->save_have_action = 0;
    this->save_farm_amt = 0;

    for (int i = 0; i < 9; ++i)
        this->save_score[i] = 0;

    if (this->setup(draw_area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_player(player_);

    this->health_pic = new TShape((char*)s_health_shp, 0xC639);
    if (this->health_pic != 0 && this->health_pic->is_loaded() == 0) {
        if (this->health_pic != 0)
            delete this->health_pic;
        this->health_pic = 0;
    }

    this->item_pic = new TShape((char*)s_itemicon_shp, 0xC62B);
    if (this->item_pic != 0 && this->item_pic->is_loaded() == 0) {
        if (this->item_pic != 0)
            delete this->item_pic;
        this->item_pic = 0;
    }
}

// VA: 0051C3F0 TRIBE_Panel_Object::handle_idle (1568B)
// tpnl_obj.cpp
// Attempt log:
// try 1: packet-grounded natural control flow with exact field offsets, virtual slots, and typed object surfaces.
// try 2: corrected active field and object layouts; call set now matches, but frame/CFG remain short.
// try 3: added real get_action and corrected child notify slot; all 25 call targets now align.
// try 4: explored local/frame padding and source guard forms; no exact movement beyond 62% shape.
// try 5: typed the distinct pierce-armor and child notification virtual slots
// from the oracle call map; this is the only post-baseline structural lead.
// try 6: separated typed range and speed output destinations to preserve both
// getter results; retained despite frame growth because this fixes behavior.
// validated pause state: meaningful code is 1413/1568B, frame 0x84/0x8C, ordered calls
// are 96% with -1/+1 site gaps, and strict diff is 1330B (84.8214%). Structural work remains.

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

class TPanel {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void set_redraw(int value);
    virtual void vf09(); virtual void vf0A(); virtual void vf0B(); virtual void vf0C();
    virtual void vf0D(); virtual void vf0E(); virtual void vf0F(); virtual void vf10();
    virtual void vf11(); virtual void vf12(); virtual long handle_idle();
    virtual void vf13(); virtual void vf14(); virtual void vf15(); virtual void vf16();
    virtual void vf17(); virtual void vf18(); virtual void vf19(); virtual void vf1A();
    virtual void vf1B(); virtual void vf1C(); virtual void vf1D(); virtual void vf1E();
    virtual void vf1F(); virtual void vf20(); virtual void vf21(); virtual void vf22();
    virtual void vf23(); virtual void vf24(); virtual void vf25(); virtual void vf26();
    virtual void vf27(); virtual void vf28(); virtual void vf29(); virtual void vf2A();
    virtual void vf2B();
    virtual void notify(void*, int, int, int);
    char gap_04[0x3C];
    TPanel* child; // +40
    char gap_44[0x28];
    int active; // +6C
    char gap_70[0x84];
};

class RGE_Object_Node { public: char gap_00[0x10]; };
class TRIBE_Player;
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[0x12];
    float los;
};
class RGE_Victory_Conditions { public: long get_victory_points(); };
class RGE_Action {
public:
    unsigned char gap_00[0x2C];
    float attribute_amount;
};
class RGE_Action_List { public: RGE_Action* get_action(); };
class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
};
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf01(); virtual void vf02(); virtual void vf03(); virtual void vf04();
    virtual void vf05(); virtual void vf06(); virtual void vf07(); virtual void vf08();
    virtual void vf09(); virtual void vf0A(); virtual void vf0B(); virtual void vf0C();
    virtual void vf0D(); virtual void vf0E(); virtual void vf0F(); virtual void vf10();
    virtual void vf11(); virtual void vf12(); virtual void vf13(); virtual void vf14();
    virtual void vf15(); virtual void vf16(); virtual void vf17(); virtual void vf18();
    virtual void vf19(); virtual void vf1A(); virtual void vf1B(); virtual void vf1C();
    virtual void vf1D(); virtual void vf1E(); virtual void vf1F(); virtual void vf20();
    virtual void vf21(); virtual void vf22(); virtual void vf23(); virtual void vf24();
    virtual void vf25(); virtual void vf26(); virtual void vf27(); virtual void vf28();
    virtual void vf29(); virtual void vf2A(); virtual void vf2B(); virtual void vf2C();
    virtual void vf2D(); virtual void vf2E(); virtual void vf2F(); virtual void vf30();
    virtual void vf31(); virtual void vf32(); virtual void vf33(); virtual void vf34();
    virtual void vf35(); virtual void vf36(); virtual void vf37(); virtual void vf38();
    virtual void vf39(); virtual void vf3A(); virtual void vf3B(); virtual void vf3C();
    virtual void vf3D(); virtual void vf3E(); virtual void vf3F(); virtual void vf40();
    virtual void vf41(); virtual void vf42(); virtual void vf43(); virtual void vf44();
    virtual void vf45(); virtual void vf46(); virtual void vf47(); virtual void vf48();
    virtual void vf49(); virtual void vf4A(); virtual void vf4B(); virtual void vf4C();
    virtual void vf4D(); virtual void vf4E(); virtual void vf4F(); virtual void vf50();
    virtual void vf51(); virtual void vf52(); virtual void vf53(); virtual void vf54();
    virtual void vf55(); virtual void vf56(); virtual void vf57(); virtual void vf58();
    virtual void vf59(); virtual void vf5A(); virtual void vf5B(); virtual void vf5C();
    virtual void vf5D(); virtual void vf5E(); virtual void vf5F(); virtual void vf60();
    virtual void vf61(); virtual void vf62(); virtual void vf63(); virtual void vf64();
    virtual void vf65(); virtual void vf66(); virtual void vf67(); virtual void vf68();
    virtual void vf69(); virtual void vf6A(); virtual void vf6B(); virtual void vf6C();
    virtual void vf6D(); virtual void vf6E(); virtual void vf6F(); virtual void vf70();
    virtual void vf71(); virtual void vf72(); virtual void vf73(); virtual void vf74();
    virtual void vf75(); virtual void vf76(); virtual void vf77(); virtual void vf78();
    virtual void vf79();
    long id;
    RGE_Master_Static_Object* master_obj;
    TRIBE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    RGE_Object_Node* player_object_node;
    unsigned char gap_54[0x34];
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual void action_vf1(); virtual void action_vf2(); virtual void action_vf3();
    virtual void action_vf4(); virtual void action_vf5(); virtual void action_vf6();
    virtual void action_vf7(); virtual void action_vf8(); virtual void action_vf9();
    virtual void action_vfA(); virtual void action_vfB(); virtual void action_vfC();
    unsigned char gap_88[0xF8];
    unsigned char waiting;
    unsigned char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    unsigned char gap_189[3];
    int last_action;
    int last_action_state;
    unsigned char have_action();
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual void create_action_list();
    virtual void area_attack();
    virtual void attack_float();
    virtual void attack_object();
    virtual void do_attack();
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);
    virtual void setup_combat();
    virtual void vf_after_combat();
    virtual void get_pierce_armor(short&, short&);
};

class TRIBE_Building_Object : public RGE_Combat_Object {
public:
    short get_construction_progress();
    int work_status(short&, short&, short&, char*, short);
    int production_queue_status(short&, short&);
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x18];
    float* attributes;
    char gap_54[0xDC];
    RGE_Static_Object* object_130;
};
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    TRIBE_Player** players;
};
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;
    int playerID(int id);
};
extern RGE_Base_Game* rge_base_game;
extern float DAT_00576d84;

class TRIBE_Panel_Object : public TPanel {
public:
    void* font;
    long font_wid;
    long font_hgt;
    void* health_pic;
    void* item_pic;
    void* unit_pics;
    void* bldg_pics;
    TRIBE_Player* player;
    RGE_Static_Object* game_obj;
    unsigned long idle_time;
    unsigned long idle_interval;
    unsigned char mode;
    char gap_121[3];
    RGE_Master_Static_Object* save_obj_type;
    void* save_sprite;
    short save_attr_type;
    char gap_12E[2];
    float save_attr_amount;
    unsigned char save_object_state;
    char gap_135[3];
    float save_build_pts;
    RGE_Object_Node* save_list;
    short save_number_of_objects;
    unsigned char save_can_debark;
    unsigned char gap_143;
    float save_world_x;
    float save_world_y;
    float save_hp;
    short save_armor;
    short save_pierce_armor;
    short save_weapon;
    char gap_156[2];
    float save_weapon_range;
    float save_speed_of_attack;
    short save_work_type;
    short save_work_target;
    short save_progress;
    char save_name[100];
    unsigned char save_facet;
    unsigned char gap_1CB;
    float save_angle;
    float save_los;
    int save_pop;
    int save_max_pop;
    unsigned char save_selected_group;
    char gap_1DD[3];
    TRIBE_Player* save_owner;
    int save_age;
    unsigned char save_have_action; // +1E8
    char gap_1E9[3];
    int save_score[9];
    int save_farm_amt;
    virtual long handle_idle();
    void set_object(RGE_Static_Object*);
    void save_object_info();
};

long TRIBE_Panel_Object::handle_idle()
{
    TPanel::handle_idle();
    if (this->active == 0) return 0;

    unsigned long now = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp", 0x37C);
    if (now - this->idle_time < this->idle_interval) return 0;
    now = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp", 0x37F);
    this->idle_time = now;

    if (this->mode == 2) {
        for (int i = 1; i < 9; ++i) {
            int p = rge_base_game->playerID(i);
            if (p != 0) {
                long score = rge_base_game->world->players[p]->victory_conditions->get_victory_points();
                if (this->save_score[p] != score) {
                    if (this->child == 0) this->set_redraw(1);
                    this->save_object_info();
                    return 0;
                }
            }
        }
        return 0;
    }

    TRIBE_Player* p = this->player;
    if ((p != 0 && p->object_130 != this->game_obj) ||
        (p == 0 && this->game_obj != 0)) {
        this->set_object(p != 0 ? p->object_130 : 0);
        return 0;
    }

    RGE_Action_Object* obj = (RGE_Action_Object*)this->game_obj;
    int changed = 0;
    int do_buttons = 0;
    short unused_val = 0;
    short work_target = 0;
    short orig_val = 0;
    short temp = 0;
    short work_type = 0;
    short progress_value = 0;
    float orig_fval = 0;
    float unused_fval = 0;
    float weapon_range = 0;
    float speed_of_attack = 0;
    char name[100];
    TRIBE_Building_Object* bldg = (TRIBE_Building_Object*)obj;
    if (obj == 0) goto finish;

    if (obj->owner == this->save_owner) {
        if (obj->selected_group == this->save_selected_group) {
            RGE_Master_Static_Object* master = obj->master_obj;
            if (master == this->save_obj_type) {
                short n = obj->objects->number_of_objects;
                if (n == this->save_number_of_objects) {
                    if (obj->attribute_type_held != this->save_attr_type ||
                        obj->attribute_amount_held != this->save_attr_amount ||
                        obj->hp != this->save_hp ||
                        obj->objects->list != this->save_list ||
                        master->los != this->save_los || master->id == 0x2d) {
                        changed = 1; do_buttons = 1;
                    }
                } else {
                    changed = 1; do_buttons = 1;
                    if (n == 0 || this->save_number_of_objects == 0) do_buttons = 1;
                }
            } else { changed = 1; do_buttons = 1; }
        } else { changed = 1; do_buttons = 1; }
    } else { changed = 1; do_buttons = 1; }

    if (!changed) {
        unsigned char type = obj->master_obj->master_type;
        if (type > 0x45 && type != 0x5A) {
            if (obj->have_action() != this->save_have_action) {
                changed = 1; do_buttons = 1;
            }
            if (!changed) {
                RGE_Combat_Object* combat = (RGE_Combat_Object*)obj;
                combat->get_armor(orig_val, unused_val);
                if (orig_val != this->save_armor) { changed = 1; }
                if (!changed) {
                    combat->get_pierce_armor(orig_val, unused_val);
                    if (orig_val != this->save_pierce_armor) { changed = 1; }
                }
                if (!changed) {
                    combat->get_weapon(orig_val, unused_val);
                    if (orig_val != this->save_weapon) { changed = 1; }
                }
                if (!changed) {
                    combat->get_weapon_range(weapon_range, unused_fval);
                    if (weapon_range != this->save_weapon_range) { changed = 1; }
                }
                if (!changed) {
                    combat->get_speed_of_attack(speed_of_attack, unused_fval);
                    if (speed_of_attack != this->save_speed_of_attack) { changed = 1; }
                }
            }
        }
    }

    if (changed && do_buttons) goto finish;
    if (bldg->master_obj->master_type != 'P') goto finish;
    if (bldg->object_state != this->save_object_state) {
        changed = 1; do_buttons = 1;
    }
    if (!changed || !do_buttons) {
        int progress = bldg->get_construction_progress();
        if ((float)progress != this->save_build_pts) {
            changed = 1;
            if ((float)progress > 99.0f) do_buttons = 1;
        }
    }
    if (!changed || !do_buttons) {
        bldg->work_status(work_type, work_target, progress_value, name, 100);
        short work_type2 = work_type;
        if (work_type2 != 0x67 && work_type2 != 0x66 && bldg->production_queue_status(work_target, temp) != 0) {
            work_type2 = 0x66;
            orig_fval = (float)temp;
        }
        if (work_type2 == this->save_work_type &&
            work_target == this->save_work_target &&
            progress_value == this->save_progress) {
            int i = 0;
            while (name[i] == this->save_name[i] && name[i] != 0) ++i;
            if (name[i] == this->save_name[i]) goto name_same;
        }
        changed = 1;
        if (work_type2 == this->save_work_type &&
            work_target == this->save_work_target) {
            int i = 0;
            while (name[i] == this->save_name[i] && name[i] != 0) ++i;
            if (name[i] == this->save_name[i]) goto name_same;
        }
        do_buttons = 1;
    }
name_same:
finish:
    if ((!changed || !do_buttons) && this->game_obj->master_obj->id == 0x46) {
        int pop = (int)this->player->attributes[11];
        int max_pop = (int)this->player->attributes[4];
        if (pop != this->save_pop || max_pop != this->save_max_pop) changed = 1;
    }
    if ((!changed || !do_buttons) && obj->owner == this->player &&
        obj->master_obj->id == 0x32) {
        RGE_Action* action = bldg->actions->get_action();
        if (action != 0 &&
            (int)(action->attribute_amount + obj->attribute_amount_held -
                  DAT_00576d84) != this->save_farm_amt) {
            changed = 1;
        }
    }
    if (changed) {
        if (this->child == 0) this->set_redraw(1);
        this->save_object_info();
        if (do_buttons) this->child->notify(this, 1, 0, 0);
    }
    return 0;
}

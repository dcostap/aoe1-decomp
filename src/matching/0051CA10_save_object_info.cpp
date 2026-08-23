// VA: 0051CA10 TRIBE_Panel_Object::save_object_info (620B)
// PDB: tpnl_obj.cpp:1139-1228
//
// Attempt log:
// - canonical baseline: reconstructed the mode score loop, the action/combat
//   snapshot, and the building/population snapshot using the proven period
//   object layouts and virtual getter surface.
// - corrected the inherited static-object virtual count; combat getter calls
//   then landed at the proven 22C/230/234/238 slots.
// - restored the polymorphic master-object and player layouts (los +28,
//   attributes +50) and the unsigned 46h type threshold from the oracle.
// - a local action amount preserves the binary-proven fld-before-game-object
//   reload order in the final farm total; the source remains typed and has no
//   raw offset or register-forcing plumbing.
// - exact: 620/620 bytes, 15/15 ordered calls, frame 0xC, 171 instructions.

class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Action_List;
class RGE_Action;
class RGE_Game_World;
class RGE_Base_Game;

class RGE_Victory_Conditions {
public:
    long get_victory_points();
};

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

class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
};

class RGE_Action {
public:
    unsigned char gap_00[0x2C];
    float attribute_amount;
};

class RGE_Action_List {
public:
    RGE_Action* get_action();
};

class RGE_Static_Object {
public:
    // The inherited object surface occupies slots 0..121.  The named fields
    // below retain the binary-proven RGE_Static_Object offsets.
    virtual ~RGE_Static_Object();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0A();
    virtual void vf0B();
    virtual void vf0C();
    virtual void vf0D();
    virtual void vf0E();
    virtual void vf0F();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1A();
    virtual void vf1B();
    virtual void vf1C();
    virtual void vf1D();
    virtual void vf1E();
    virtual void vf1F();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2A();
    virtual void vf2B();
    virtual void vf2C();
    virtual void vf2D();
    virtual void vf2E();
    virtual void vf2F();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf3A();
    virtual void vf3B();
    virtual void vf3C();
    virtual void vf3D();
    virtual void vf3E();
    virtual void vf3F();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf4A();
    virtual void vf4B();
    virtual void vf4C();
    virtual void vf4D();
    virtual void vf4E();
    virtual void vf4F();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf5A();
    virtual void vf5B();
    virtual void vf5C();
    virtual void vf5D();
    virtual void vf5E();
    virtual void vf5F();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf6A();
    virtual void vf6B();
    virtual void vf6C();
    virtual void vf6D();
    virtual void vf6E();
    virtual void vf6F();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
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
    virtual void action_vf1();
    virtual void action_vf2();
    virtual void action_vf3();
    virtual void action_vf4();
    virtual void action_vf5();
    virtual void action_vf6();
    virtual void action_vf7();
    virtual void action_vf8();
    virtual void action_vf9();
    virtual void action_vfA();
    virtual void action_vfB();
    virtual void action_vfC();

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
};

class TRIBE_Building_Object : public RGE_Combat_Object {
public:
    unsigned char gap_1C4[4];

    short get_construction_progress();
    int work_status(short&, short&, short&, char*, short);
    int production_queue_status(short&, short&);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    unsigned char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    unsigned char gap_38[0x18];
    float* attributes;
};

typedef RGE_Player TRIBE_Player;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned char gap_04[0x38];
    short player_num;
    unsigned char gap_3E[2];
    RGE_Player** players;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    unsigned char gap_04[0x3F0];
    RGE_Game_World* world;

    int playerID(int);
};

extern RGE_Base_Game* rge_base_game;
extern float DAT_00576d84;

class TPanel {
public:
    virtual ~TPanel();
    unsigned char gap_04[0xF0];
};

class TRIBE_Panel_Object : public TPanel {
public:
    void* font;
    long font_wid;
    long font_hgt;
    void* health_pic;
    void* item_pic;
    void* unit_pics;
    void* bldg_pics;
    RGE_Player* player;
    RGE_Static_Object* game_obj;
    unsigned long idle_time;
    unsigned long idle_interval;
    unsigned char mode;
    unsigned char gap_121[3];
    RGE_Master_Static_Object* save_obj_type;
    void* save_sprite;
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

protected:
    void save_object_info();
};

void TRIBE_Panel_Object::save_object_info()
{
    if (this->mode == 2) {
        int i = 1;
        do {
            int player_id = rge_base_game->playerID(i);
            if (player_id != 0 &&
                player_id < rge_base_game->world->player_num) {
                this->save_score[player_id] =
                    rge_base_game->world->players[player_id]
                        ->victory_conditions->get_victory_points();
            }
            ++i;
        } while (i < 9);
        return;
    }

    RGE_Action_Object* object = (RGE_Action_Object*)this->game_obj;
    if (object == 0)
        return;

    short orig_val;
    short temp;
    float orig_fval;

    this->save_selected_group = object->selected_group;
    this->save_obj_type = object->master_obj;
    this->save_attr_type = object->attribute_type_held;
    this->save_attr_amount = object->attribute_amount_held;
    this->save_hp = object->hp;
    this->save_list = object->objects->list;
    this->save_number_of_objects = object->objects->number_of_objects;
    this->save_los = object->master_obj->los;
    this->save_owner = object->owner;

    if (object->master_obj->master_type >= 0x46 &&
        object->master_obj->master_type != 0x5A) {
        this->save_have_action = object->have_action();
        ((RGE_Combat_Object*)this->game_obj)->get_armor(
            this->save_armor, orig_val);
        ((RGE_Combat_Object*)this->game_obj)->get_armor(
            this->save_pierce_armor, orig_val);
        ((RGE_Combat_Object*)this->game_obj)->get_weapon(
            this->save_weapon, orig_val);
        ((RGE_Combat_Object*)this->game_obj)->get_weapon_range(
            this->save_weapon_range, orig_fval);
        ((RGE_Combat_Object*)this->game_obj)->get_speed_of_attack(
            this->save_speed_of_attack, orig_fval);
    }

    TRIBE_Building_Object* building =
        (TRIBE_Building_Object*)this->game_obj;
    if (building->master_obj->master_type == 'P') {
        this->save_object_state = building->object_state;
        int construction_progress = building->get_construction_progress();
        this->save_build_pts = (float)construction_progress;
        building->work_status(this->save_work_type,
                              this->save_work_target,
                              this->save_progress,
                              this->save_name, 100);

        if (this->save_work_type != 0x67 &&
            this->save_work_type != 0x66 &&
            building->production_queue_status(this->save_work_target,
                                               temp) != 0) {
            this->save_work_type = 0x66;
            this->save_progress = temp;
        }

        TRIBE_Player* player = this->player;
        this->save_pop = (int)player->attributes[11];
        this->save_max_pop = (int)player->attributes[4];

        if (this->game_obj->owner == player &&
            this->game_obj->master_obj->id == 0x32) {
            RGE_Action* action = building->actions->get_action();
            if (action != 0) {
                float action_amount = action->attribute_amount;
                this->save_farm_amt =
                    (int)(action_amount +
                          this->game_obj->attribute_amount_held -
                          DAT_00576d84);
            }
        }
    }
}

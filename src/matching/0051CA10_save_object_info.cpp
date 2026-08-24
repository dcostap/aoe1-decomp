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

#ifndef AOE1_TPNL_OBJ_CONTEXT_H
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Action_List;
class RGE_Action;
class RGE_Task;
class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Action_Object;
class RGE_Master_Combat_Object;
class RGE_Armor_Weapon_Info;
class LOSTBL;
class RGE_Active_Sprite_List;
class Path;
struct XYZPoint;
struct XYPoint;
struct XYZBYTEPoint;
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
    virtual ~RGE_Object_List();
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
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual void can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual void canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual void is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual void underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual void useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    virtual void get_action_checksum();
    virtual void get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();
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
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, unsigned char);
    virtual void set_task(short);
    virtual void setTaskByTaskID(int);
    virtual void set_action(RGE_Action*);
    virtual void set_only_action(RGE_Action*);
    virtual void set_end_action(RGE_Action*);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);
    virtual int setup(RGE_Master_Action_Object*, RGE_Player*, float, float, float);

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
    virtual unsigned char area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
    virtual unsigned char attack(float, float, float, RGE_Combat_Object*);
    virtual unsigned char attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual unsigned char do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);
    virtual int setup_combat(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    virtual void get_pierce_armor(short&, short&);
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
#endif

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

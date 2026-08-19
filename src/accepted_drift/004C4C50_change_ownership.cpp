// VA: 004C4C50 | RGE_Static_Object::change_ownership | stat_obj.cpp:2406-2447
//
// Attempt log:
// baseline: natural typed ownership transfer reconstructed from the original
// call order, the proven RGE_Static_Object/RGE_Master_Static_Object layouts,
// and the executable's virtual slots.
// behavior: the replacement sprite falls back to the new master's default
// sprite when the old sprite is neither the default, death, nor undead sprite.
// liveness: a named new-node temporary preserves the observed old-master load
// before the player-node store; VC5 still chooses a different volatile color.
// probes: declaration order, separate old-sprite, comma sequencing, and
// register hints were unchanged or less plausible; the remaining drift is the
// localized old-master/sprite register coloring and its branch-span fallout.
// Main-agent audit restored canonical master/player/static-object destructor
// slots in place of raw vptr/slot-zero placeholders; emitted code is unchanged.
// fresh worker: direct this->master_obj lookup before naming old_master widened
// to 136B/45.2%; restored canonical old-master local.
// fresh worker: distinct old_sprite declared after old_master preserved 301B/134
// basin; restored existing clean source.
// fresh worker: reversed sprite/master comparison operands changed only cmp
// encoding and worsened shape; restored canonical current-sprite-left form.
// fresh worker: function-scope/top-scope local declarations, a named short id,
// canonical virtual change_ownership slot, and the proven full master class
// surface all emitted the same 301B/134 basin; no source/layout lead.
// fresh worker: an 8-way comparison-order lab and a 16-way lookup/sprite-shape
// lab found no exact or alternate emitted group; all variants retained the
// same 301B/134 result. Pointer-arithmetic lookup and const old-master probes
// were also codegen duplicates. Remaining gap is the localized VC5 register
// coloring at old-master lookup/sprite selection (oracle has mov eax,edx and
// cmp ecx,[eax+...]; clean source has the swapped color and is retained).
// follow-up worker: direct this->master_obj lookup without old_master widened
// to 136B; retaining old_master with the direct index, a named master-table
// alias, int index, declaration-order changes, and zero initialization all
// emitted the same clean 301B/134 basin. Restored the clean source.
// managed worker: moving old_master after the node store widened to 136B;
// function-scope locals, split initialization, scoped sprite selection, a
// reference alias, void* master table casts, windows.h context, positive
// sprite guards, and a redundant master alias were duplicates or worse.
// Declaring change_ownership virtual corrected the decorated ABI name but did
// not change body bytes; placing it at vtable slot 0x44 also preserved bytes.
// revisit worker: grouping the ownership-transfer statements and sprite guard
// to match the PDB line bands was a codegen duplicate at 134B.
// revisit worker: a direct typed player_object_node assignment matched a
// sibling donor's style but widened the result to 136B; the local node remains.
// revisit worker: separate old_sprite/new_sprite, early result initialization,
// direct this->sprite comparisons, split initialization, and declaration-order
// variants were duplicates or worse. The exact copy_obj donor supports the
// old-sprite/result-local model, but it does not select this function's basin.
// revisit worker: replaced generic virtual pads and invented slot names with
// the reviewed RGE_Player/RGE_Static_Object method surfaces. Renamed the
// proven add/remove, explore/unexplore, and notify calls. Body bytes remain
// 301B/134; source is now policy-valid without fake virtual slots.
// ACCEPTED DRIFT: the first 151 bytes are exact except for one later branch
// displacement. The sprite-selection hunk applies a complete EAX/ECX/EDX
// recolor to old_master, its ID, the new owner's master table, and the current
// sprite. It reads each field in the same order and selects the same default,
// death, or undead sprite. The extra original move only transfers the same
// old_master value between private registers. The remainder resynchronizes
// exactly. Size, all nine calls, predicates, x87 HP calculation, ownership
// stores, notifications, cleanup, and fault order match. This function has no
// SEH. Twenty-eight focused probes found no natural exact register allocation.

class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Static_Object;
class RGE_Master_Static_Object;

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
    unsigned char gap_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap_25[1];
    short hp;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                                float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                  unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float,
                                                int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21[1];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    void* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49[1];
    short id;

    void unselect_one_object(RGE_Static_Object*);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
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
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*,
                                  RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*,
                                                          float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
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
    virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
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

    void take_attribute_from_owner();
    void give_attribute_to_owner();
};

void RGE_Static_Object::change_ownership(RGE_Player* player)
{
    if (player->master_objects[this->master_obj->id] == 0) {
        return;
    }

    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }

    float hp_num = this->hp / (float)(int)this->master_obj->hp;
    this->take_attribute_from_owner();

    if (this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
    }

    this->owner->removeObject(this, this->sleep_flag, this->dopple_flag,
                              this->player_object_node);
    RGE_Object_Node* new_node =
        player->addObject(this, this->sleep_flag, this->dopple_flag);

    RGE_Master_Static_Object* old_master = this->master_obj;
    this->player_object_node = new_node;
    RGE_Master_Static_Object* new_master =
        player->master_objects[old_master->id];
    RGE_Sprite* new_sprite = this->sprite;
    if (new_sprite != old_master->sprite) {
        if (new_sprite == old_master->death_sprite) {
            new_sprite = new_master->death_sprite;
        } else if (new_sprite == old_master->undead_sprite) {
            new_sprite = new_master->undead_sprite;
        } else {
            new_sprite = new_master->sprite;
        }
    } else {
        new_sprite = new_master->sprite;
    }

    if (new_sprite != 0) {
        this->new_sprite(new_sprite);
    }

    this->owner = player;
    this->master_obj = new_master;
    this->hp = (float)(int)new_master->hp * hp_num;

    if (this->object_state == 2) {
        this->explore_terrain(player, 0, -1);
    }

    this->give_attribute_to_owner();
    this->notify(this->id, this->id, 0x20B, (int)player->id, 0, 0);
}

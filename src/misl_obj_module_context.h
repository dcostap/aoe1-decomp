#ifndef MISL_OBJ_MODULE_CONTEXT_H
#define MISL_OBJ_MODULE_CONTEXT_H

class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
    float radius_z;
};

class RGE_Game_World;
class RGE_Map;
class RGE_Player;
class RGE_Master_Combat_Object;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class TDrawArea;
class RGE_Color_Table;
class LOSTBL;
class RGE_Armor_Weapon_Info;
class Path;
class RGE_Tile;
struct RGE_Object_Node;
struct XYPoint;
struct XYZPoint;
struct XYZBYTEPoint;
template<class T> class ManagedArray;
class RGE_Action_List;

class RGE_Map_Info {
public:
    char gap_00[8];
    int width;
    int height;
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void rehook();
};

class RGE_Static_Object : public RGE_Action_Object {
public:
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
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
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
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
    virtual int canPathWithObstructions(int, float, float*, int, int, int,
                                        ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*,
                                                  int, int, int, int, int);
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
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();

protected:
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);

public:
    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    union {
        float world_x;
        float x;
    };
    union {
        float world_y;
        float y;
    };
    union {
        float world_z;
        float z;
    };
};

class RGE_Combat_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float, float, int);
    RGE_Combat_Object(int, RGE_Game_World*, int);
protected:
    virtual int setup(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    virtual int setup(int, RGE_Game_World*);

public:
    virtual void save(int);
    virtual unsigned char update();
};

class RGE_Check_List;

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    char gap_44[0x4C];
    float dx;
    float dy;
    float dz;
    char gap_9C[0xE8];
    RGE_Action_List* action_list;
    char gap_188[0x3C];
    float max_range;

    RGE_Missile_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float, float, int);
    RGE_Missile_Object(int, RGE_Game_World*, int);
protected:
    virtual int setup(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    virtual int setup(int, RGE_Game_World*);

public:
    virtual void rehook();
    virtual void save(int);
    virtual unsigned char update();
    void init_missile(RGE_Combat_Object*, float, float, float, float);
    void init_missile(RGE_Combat_Object*, RGE_Static_Object*, float);
    unsigned char missile_move();
    void* scalar_deleting_destructor(unsigned int);
    void parent_destroy();
    RGE_Check_List* make_object_collision_list(float);
};

struct RGE_Check_Node {
    RGE_Static_Object* object;
    float dx;
    float dy;
    unsigned char flag;
    unsigned char gap_0D[3];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;
    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object*, float, float, unsigned char);
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
};

struct RGE_Object_Node {
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Tile {
public:
    char gap_00[0x0C];
    RGE_Object_List objects;
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    union {
        RGE_Map* map;
        RGE_Map_Info* map_info;
    };
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Action_Missile : public RGE_Action_Object {
public:
    char pad[0x50];
    ~RGE_Action_Missile();
    RGE_Action_Missile(RGE_Action_Object*, RGE_Combat_Object*, int,
                       float, float, float);
    RGE_Action_Missile(RGE_Action_Object*, RGE_Combat_Object*,
                       RGE_Static_Object*, float, float, float);
};

class RGE_Action_List {
public:
    int some_field;
    void add_action(RGE_Action_Object*);
};

#endif

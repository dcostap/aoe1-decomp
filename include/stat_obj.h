#ifndef AOE1_STAT_OBJ_H
#define AOE1_STAT_OBJ_H

#include "utmarray.h"
#include "xyz_point.h"

class InfluenceMap;
struct LOSTBL;
class Path;
class RGE_Action_Object;
class RGE_Active_Sprite_List;
struct RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
struct RGE_Tile;
class TDrawArea;
class UnitAIModule;
struct RGE_Object_Node;
struct XYPoint;
struct XYZBYTEPoint;

struct RGE_Check_Node {
    RGE_Static_Object* node;
    float dx;
    float dy;
    unsigned char flag;
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;
    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object* obj, float dx, float dy, unsigned char flag1);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    RGE_Static_Object(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int do_setup);
    RGE_Static_Object(int infile, RGE_Game_World* gworld, int do_setup);
    virtual void recycle_in_to_game(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner,
                                    float x, float y, float z);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea* render_area, short x, short y, RGE_Color_Table* draw_color);
    virtual void shadow_draw(TDrawArea* render_area, short x, short y, unsigned char flag);
    virtual void normal_draw(TDrawArea* render_area, short x, short y);
    virtual void draw_front_frame(TDrawArea* render_area, short x, short y);
    virtual void draw_back_frame(TDrawArea* render_area, short x, short y);
    virtual void draw_frame(TDrawArea* render_area, short x, short y);
    void draw_frame_3d_cube_front(TDrawArea* render_area, short x, short y);
    void draw_frame_3d_square_front(TDrawArea* render_area, short x, short y);
    void draw_frame_3d_cube_back(TDrawArea* render_area, short x, short y);
    void draw_frame_3d_cube_back_case(TDrawArea* render_area, short x, short y);
    void draw_frame_3d_square_back(TDrawArea* render_area, short x, short y);
    void capture_frame_3d_cube(TDrawArea* render_area, short x, short y);
    void capture_frame_3d_square(TDrawArea* render_area, short x, short y);
    void capture_square_frame(TDrawArea* render_area, short x, short y);
    int get_frame(short& min_x, short& min_y, short& max_x, short& max_y);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int outfile);
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Sprite* nsprite);
    virtual void add_overlay_sprite(RGE_Sprite* nsprite, unsigned char order);
    virtual void remove_overlay_sprite(RGE_Sprite* nsprite);
    virtual void change_ownership(RGE_Player* new_owner);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void transform(RGE_Master_Static_Object* obj);
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void set_object_state(unsigned char new_object_state);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier,
                        RGE_Player* attacking_player, RGE_Static_Object* attackingObject);
    virtual float calculateDamage(int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier,
                                  RGE_Player* attacking_player, RGE_Static_Object* attackingObject);
    virtual void rotate(long amount);
    virtual unsigned char can_attack() { return 0; }
    virtual void set_attribute(short attr_type, float attr_amount);
    virtual void set_attribute_amount(float attr_amount, unsigned char delta, unsigned char check_max);
    // VC5 emits this overload group in reverse declaration order.
    virtual unsigned char heal(float healing);
    virtual int heal(int, int) { return 0; }
    virtual int canRepair() { return 0; }
    virtual void notify_of_relation(long player_id, unsigned char relation);
    virtual void do_command(RGE_Static_Object*, float, float, float) {}
    virtual void move_to(RGE_Static_Object*, float, float, float) {}
    virtual void work(RGE_Static_Object*, float, float, float) {}
    virtual void stop() {}
    virtual void set_attack(RGE_Static_Object*) {}
    virtual void play_command_sound() {}
    virtual void play_move_sound() {}
    virtual void new_angle(float new_angle);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float) {
        return this->master_obj;
    }
    virtual void set_being_worked_on(RGE_Action_Object* work_obj, short action_type, unsigned char attack_flag);
    virtual void release_being_worked_on(RGE_Static_Object* caller);
    virtual unsigned char is_moving();
    unsigned char is_dying();
    virtual RGE_Static_Object* get_target_obj() { return 0; }
    virtual void enter_obj(RGE_Static_Object* target);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player* whos, unsigned char explore_type, int Override_LOS);
    virtual void unexplore_terrain(RGE_Player* whos, unsigned char explore_type, int Override_LOS);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*) { return 0; }
    virtual unsigned char underAttack() const;
    virtual void setUnderAttack(unsigned char v);
    virtual float calc_attack_modifier(RGE_Static_Object*) {
        return 1.0f;
    }
    virtual float getSpeed() const { return 0.0f; }
    virtual float getAngle() const { return 0.0f; }
    virtual float maximumSpeed() { return 0.0f; }
    virtual float rateOfFire() { return 0.0f; }
    virtual float damageCapability() { return 0.0f; }
    virtual float damageCapability(RGE_Static_Object*) { return 0.0f; }
    virtual float weaponRange() { return 0.0f; }
    virtual float minimumWeaponRange() { return 0.0f; }
    virtual int passableTile(float, float, int) { return 0; }
    virtual unsigned char facetToNextWaypoint() const { return 0xFF; }
    virtual int currentTargetID() const { return -1; }
    virtual float currentTargetX() const { return -1.0f; }
    virtual float currentTargetY() const { return -1.0f; }
    virtual float currentTargetZ() const { return -1.0f; }
    virtual void setWaitingToMove(unsigned char) {}
    virtual unsigned char waitingToMove() const { return 0; }
    virtual unsigned char actionState() const { return 0; }
    virtual unsigned char keepGatheringWhenObjectIsOut(int) const { return 0; }
    virtual unsigned char produceWhenKilledBy(int) const { return 1; }
    virtual unsigned char useSameZoneDropsite() const { return 1; }
    virtual void __cdecl logDebug(char* textIn, ...);
    virtual void notify(int, int, int, long, long, long) {}
    virtual int attack(int, int) { return 0; }
    virtual int attack(float, float, float, int) { return 0; }
    virtual int moveTo(int, int) { return 0; }
    virtual int moveTo(int, float, int) { return 0; }
    virtual int moveTo(float, float, float, float, int) { return 0; }
    virtual int moveAwayFrom(int, int) { return 0; }
    virtual int hunt(int, int) { return 0; }
    virtual int gather(int, int) { return 0; }
    virtual int convert(int, int) { return 0; }
    virtual int repair(int, int) { return 0; }
    virtual int build(int, int) { return 0; }
    virtual int trade(int, int) { return 0; }
    virtual int explore(int, int, int) { return 0; }
    virtual int enter(int, int) { return 0; }
    virtual int unload(int, float, float, float) { return 0; }
    virtual int transport(float, float, float, int) { return 0; }
    virtual int stopAction() { return 0; }
    virtual int pause() { return 0; }
    // VC5 reverses this adjacent overload pair in the original vtable.
    virtual int canPath(XYZPoint, float, int, float*, int, int, int) { return 0; }
    virtual int canPath(int, float, float* = 0, int = 1, int = -1, int = -1) { return 0; }
    virtual int canBidirectionPath(int, int, float, float*, int, int, int) { return 0; }
    virtual int canPathWithObstructions(int, float, float*, int, int, int,
                                        ManagedArray<int>&) { return 0; }
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int,
                                                 int, int, int, int) { return 0; }
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*) { return 0; }
    virtual int canLinePath(const XYPoint&, const XYPoint&, float, XYPoint&, int) { return 0; }
    virtual int canLinePath(int, int, int, int, float, int) { return 0; }
    virtual int firstTileAlongLine(const XYPoint&, const XYPoint&, XYPoint&, int,
                                   int, int) { return 0; }
    virtual XYZBYTEPoint* userDefinedWaypoint(int) { return 0; }
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int) { return 0; }
    virtual void removeAllUserDefinedWaypoints(int) {}
    virtual void removeUserDefinedWaypoint(int) {}
    virtual int numberUserDefinedWaypoints() const { return 0; }
    virtual Path* findAvoidancePath(XYZPoint&, float, int) { return 0; }
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    // overload at +0x1D8 and the master overload at +0x1DC.
protected:
    virtual int setup(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y, float z);
    virtual int setup(int infile, RGE_Game_World* gworld);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();

public:
    void release_from_holder();
    unsigned char more_room();
    float distance_to_position(float x, float y, float z);
    unsigned char hit_test(short draw_x, short draw_y, short mouse_x, short mouse_y, short check_radius);
    unsigned char box_hit_test(short draw_x, short draw_y, short start_x, short start_y, short end_x, short end_y);
    void set_location(float x, float y, float z);
    int isGroupCommander();
    int inGroup();
    int groupUnitCount();
    int groupUnitCommand(int, int);
    int groupUnitCallback(int);
    int unitIsInGroup(int uID);
    int createGroup(int* units, int count, int commander, float range);
    int commanderCreateGroup(int* units, int count, int commander, float range);
    int addToGroup(int unit, float range);
    int commanderAddToGroup(int unit, float range);
    int removeFromGroup(int unit);
    int commanderRemoveFromGroup(int uID);
    int destroyGroup();
    int commanderDestroyGroup();
    void addToPathingGroup(int uID);
    void removeAllFromPathingGroup();
    void remove_shadows();
    int boundToFacet(float tX, float tY, int numberBindingFacets);
    int numberFacets();
    unsigned char lookupZone(XYPoint p);
    unsigned char lookupZone(int x, int y);
    unsigned char currentZone();
    int withinRangeOfZoneAtPoint(unsigned char zone, float range, XYPoint& point);
    int withinRangeOfZone(unsigned char zone, float range);
    int findClosestPointInTerrainType(XYPoint p, XYPoint& rVal, int type1, int type2, int range);
    void changeInfluenceMap(InfluenceMap* iMap, int increment, int usePercentCoverage, int useLOS);
    int removeFromObstructionMap(int obMapCode);
    int addToObstructionMap(int obMapCode);
    float get_terrain_speed(unsigned char terrain);
    void notify(RGE_Player*);
    void setDamage(float);
    void setHealth(float);
    void setDamage(RGE_Player*, int, int);
    void setHealth(RGE_Player*, int, int);
    UnitAIModule* unitAI();
    void update(int);
    RGE_Sprite* get_sprite_pointer(short sprite_id);
    void give_attribute_to_owner();
    void take_attribute_from_owner();
    void get_starting_attribute();
    void change_unique_id();
    int inRange(RGE_Static_Object* obj, float range);
    float distance_to_object(RGE_Static_Object* obj);
    RGE_Check_List* make_object_bounds_list(float delta);
    RGE_Check_List* objectCollisionList(float delta);
    RGE_Static_Object* check_object_bounds();

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
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;

    void set_sleep_flag(unsigned char flag_in);
    void capture_frame(TDrawArea* render_area, short x, short y);
    RGE_Static_Object* get_object_pointer(long obj_id);
    unsigned char drop_held_objects(int dropZone);
    unsigned char find_drop_location(int dropZone, float& x, float& y, RGE_Master_Static_Object* m_obj,
                                     RGE_Static_Object* obj, float drop_x, float drop_y,
                                     float radius_x, float radius_y);
};

typedef char rge_static_object_size_check[
    (sizeof(RGE_Static_Object) == 0x88) ? 1 : -1];

#endif

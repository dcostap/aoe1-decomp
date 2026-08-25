// VA: 0046F010 processAddWaypointCommand (63B)
// PDB source: player.cpp lines 550-556

#ifndef PLAYER_GROUPED_TU
struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual void update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual float teleport();
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state();
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate();
    virtual void can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual void heal();
    virtual void heal(float);
    virtual void canRepair();
    virtual void notify_of_relation();
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual void spawn_death_obj();
    virtual void get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual void is_moving();
    virtual void get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual void explore_terrain();
    virtual void unexplore_terrain();
    virtual void get_los_table();
    virtual void inAttackRange();
    virtual void underAttack();
    virtual void setUnderAttack();
    virtual void calc_attack_modifier();
    virtual void getSpeed();
    virtual void getAngle();
    virtual void maximumSpeed();
    virtual void rateOfFire();
    virtual void damageCapability();
    virtual void damageCapability(int);
    virtual void weaponRange();
    virtual void minimumWeaponRange();
    virtual void passableTile();
    virtual void facetToNextWaypoint();
    virtual void currentTargetID();
    virtual void currentTargetX();
    virtual void currentTargetY();
    virtual void currentTargetZ();
    virtual void setWaitingToMove();
    virtual void waitingToMove();
    virtual void actionState();
    virtual void keepGatheringWhenObjectIsOut();
    virtual void produceWhenKilledBy();
    virtual void useSameZoneDropsite();
    virtual void logDebug();
    virtual void notify();
    virtual void attack();
    virtual void attack(int);
    virtual void moveTo();
    virtual void moveTo(float);
    virtual void moveTo(short);
    virtual void moveAwayFrom();
    virtual void hunt();
    virtual void gather();
    virtual void convert();
    virtual void repair();
    virtual void build();
    virtual void trade();
    virtual void explore();
    virtual void enter();
    virtual void unload();
    virtual void transport();
    virtual void stopAction();
    virtual void pause();
    virtual void canPath();
    virtual void canPath(float);
    virtual void canBidirectionPath();
    virtual void canPathWithObstructions();
    virtual void canPathWithAdditionalPassability();
    virtual void findFirstTerrainAlongExceptionPath();
    virtual void canLinePath();
    virtual void canLinePath(float);
    virtual void firstTileAlongLine();
    virtual int addUserDefinedWaypoint(XYZBYTEPoint* waypoint, int one);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int obj_id);
};

class RGE_Player {
public:
    virtual void processAddWaypointCommand(int object_id, XYZBYTEPoint* waypoints, int count);
    char gap_00[0x38];
    RGE_Game_World* world;
};
#endif

void RGE_Player::processAddWaypointCommand(int object_id, XYZBYTEPoint* waypoints, int count) {
    RGE_Static_Object* object;

    object = this->world->object(object_id);
    if ((object != 0) && (count > 0)) {
        int n;
        int (RGE_Static_Object::*method)(XYZBYTEPoint*, int);

        n = count;
        *(int*)&method = *(int*)((char*)*(void**)object + 0x1BC);
        do {
            (object->*method)(waypoints, 1);
            waypoints = waypoints + 1;
            n = n - 1;
        } while (n != 0);
    }
}

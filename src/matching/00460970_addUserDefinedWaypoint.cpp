// VA: 00460970 RGE_Moving_Object::addUserDefinedWaypoint
// move_obj.cpp:2817-2890
// Attempt log:
// 1: the old stub only modeled the final-waypoint guard.  The binary instead
//    appends three-byte XYZBYTEPoint records and grows a 5/2x byte buffer.
// 2: reconstructed the natural typed append/grow source; it reached the
//    exact call set and 425-byte neighborhood but had reversed capacity
//    operand order and a redundant nested copy-loop guard.
// 3: wrote the capacity test as max > count and flattened the copy loop to
//    one top guard; exact 425-byte match (all four calls and all CFG blocks).
// Source audit: the +1C0 virtual call is the donor-backed
// removeAllUserDefinedWaypoints slot; the surrounding ABI declarations retain
// the proven inherited slot order without manual vtable stores.

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;
class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Armor_Weapon_Info;
class RGE_Action_Object;
class RGE_Game_World;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class Path;
struct LOSTBL;
struct XYPoint;
template<class T> class ManagedArray;

extern void* operator new(unsigned int);
extern void operator delete(void*);

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
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
    virtual int canPath(XYPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);

    char gap_04[0x164];
    XYZBYTEPoint* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    unsigned char gap_175[3];

};

int RGE_Moving_Object::addUserDefinedWaypoint(XYZBYTEPoint* point, int param_2) {
    if (this->finalUserDefinedWaypoint == 1) {
        this->removeAllUserDefinedWaypoints(param_2);
        this->finalUserDefinedWaypoint = 0;
    }

    if (this->maxUserDefinedWaypointsValue >
        this->numberUserDefinedWaypointsValue) {
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].x = point->x;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].y = point->y;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].z = point->z;
    } else {
        if (this->maxUserDefinedWaypointsValue == 0) {
            this->userDefinedWaypoints =
                (XYZBYTEPoint*)operator new(0x0F);
            this->maxUserDefinedWaypointsValue = 5;
            this->numberUserDefinedWaypointsValue = 0;
        } else {
            XYZBYTEPoint* newWaypoints = (XYZBYTEPoint*)operator new(
                this->maxUserDefinedWaypointsValue * 6);
            if (newWaypoints == 0) {
                return 0;
            }

            int i = 0;
            for (; i < this->numberUserDefinedWaypointsValue; ++i) {
                newWaypoints[i].x = this->userDefinedWaypoints[i].x;
                newWaypoints[i].y = this->userDefinedWaypoints[i].y;
                newWaypoints[i].z = this->userDefinedWaypoints[i].z;
            }

            this->maxUserDefinedWaypointsValue =
                this->maxUserDefinedWaypointsValue * 2;
            for (; i < this->maxUserDefinedWaypointsValue; ++i) {
                newWaypoints[i].x = 0;
                newWaypoints[i].y = 0;
                newWaypoints[i].z = 0;
            }

            operator delete(this->userDefinedWaypoints);
            this->userDefinedWaypoints = newWaypoints;
        }

        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].x = point->x;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].y = point->y;
        this->userDefinedWaypoints[
            this->numberUserDefinedWaypointsValue].z = point->z;
    }

    ++this->numberUserDefinedWaypointsValue;
    return 1;
}

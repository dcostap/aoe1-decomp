// VA: 004CBEF0 TRIBE_Combat_Object::higher_than_target
// Attempt log:
// prior worker: raw offset/vtable reconstruction; same size but broad FPU,
// helper-ABI, and frame drift.
// clean reconstruction: restored the typed combat/static-object coordinates,
// the TRIBE vtable slot for higher_check_for_cliff, and the natural line-step
// source family shared by the movement line walkers.
// probe: this-z greater-than target-z restored the original x87 guard polarity.
// probe: declaring both absolute-step temporaries before their sign tests
// restored the original spill/reload basin, reducing the best result to 143
// differing bytes and a 4-byte size excess.
// probes: direction-plus-tile operand reversal and branch-local offset temps
// were emitted-code duplicates; one-shot direction mutation worsened broadly.
// probe: a natural short-circuit && guard for the sequential helper calls was
// an emitted-code duplicate; restored the nested source form.
// final best: retain the clean typed source and direct secondary-call offsets;
// remaining drift is localized to VC5 scheduling of the two secondary helper
// call argument additions and the resulting late tail displacement.
// fresh pass: coordinate temporaries, operand/order variants, aliases, and
// function-scope tile conversions all emitted the same 705-byte code.
// precomputing both neighbor pairs was worse: 0x50 frame and 723 bytes; restored.
// donor polymorphic static/player declarations were codegen-neutral; restored.
// fresh pass r2: period <stdlib.h> context and several natural neighbor-pair
// lifetime forms were codegen duplicates. Reusing tile coordinates for the
// secondary calls improved size and block coverage but worsened positional
// drift; restored. The remaining source/codegen gap is the oracle's stack-load
// plus ADD sequence versus VC5's equivalent LEA in the second and third calls.
// fresh pass r3: offset-first expressions, branch-local accumulators, const
// coordinate locals, and six structured secondary-call variants were all
// emitted-code duplicates. An incomplete named period virtual surface worsened
// one byte and lost early exact blocks; the corrected binary-supported named
// surface is an emitted-code duplicate. Swapping tile conversion declarations
// worsened the FPU basin by 20 bytes. A bool diagonal offset worsened size by 9 bytes.
// Logical-negation guards improved block coverage but widened the body by 5
// bytes. A natural for-loop was a codegen duplicate. Restored the pinned
// typed source; no policy-valid exact source found.
// BINARY NOTE: 004CBD40 confirms that shipped x87 unordered
// comparisons use C0|C3 status bits. The target's direct relational forms
// preserve those flags, including its initial world-z NaN path. Moving the
// helper declaration to its PDB-qualified TRIBE owner, offset-first compound
// assignments, and donor local declaration order were codegen duplicates.
// Fresh final validation: owner, 701-byte boundary, six calls, direct __ftol
// sites, virtual slot +0x248, target rereads, map fault order, and return clamp
// are correct. The only mismatch remains two secondary tile additions: original
// stack loads plus ADD, rebuilt equivalent LEA; no natural policy-valid source
// form found that changes this basin without fake volatility or dummy context.
// Accepted-drift review: the residual only forms the two neighboring tile
// pairs with stack-load plus ADD versus equivalent LEA instructions. The final
// call mutates coordinate registers that the next loop iteration overwrites.
// All six calls receive the same target, tile coordinates, float values, map,
// references, and flags. x87 order, helper predicates, and loop effects match.

#include <math.h>

extern float DAT_00574C98;

#ifndef T_C_OBJ_CONTEXT_H
class RGE_Map;

class RGE_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
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
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
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
    virtual void* get_command_master(RGE_Static_Object*, float, float, float);
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
    virtual unsigned char keepGatheringWhenObjectIs(int);
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
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExcept(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual void* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(void*, int);
    virtual int removeAllUserDefinedWaypoints();
    virtual int removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual int findAvoidancePath();
    virtual int get_action_checksum();
    virtual int get_waypoint_checksum();
    virtual void setup();
    virtual void setup(int);
    virtual void create_object_list();
    virtual void create_sprite_list();
    virtual void setup(float);
    virtual void stop_moving();
    virtual void turn_towards(float);
    virtual void setup(int, int);
    virtual void work2();
    virtual void set_task(void*);
    virtual void setTaskByTaskID(int);
    virtual void set_action(void*);
    virtual void set_only_action(void*);
    virtual void set_end_action(void*);
    virtual void* getTask();
    virtual void setup(void*);
    virtual void create_action_list();
    virtual unsigned char area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
    virtual unsigned char attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual unsigned char attack(float, float, float, RGE_Combat_Object*);
    virtual unsigned char do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);
    virtual void setup(long);
    virtual void cancel_object();
    virtual void get_pierce_armor(short&, short&);
    virtual int higher_check_for_cliff(RGE_Static_Object* object,
                                       int col, int row,
                                       float x1, float y1,
                                       float x2, float y2,
                                       RGE_Map* map,
                                       RGE_Static_Object* old_object,
                                       float& angle, int& direction);

    int id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x180];
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    virtual int higher_than_target(RGE_Static_Object* target);
    virtual int initUnitAI();
    virtual void setup(short);
    virtual void take_building_attribute(short, short);
    virtual void give_building_attribute(short, short);
    virtual void setup(unsigned short);
};
#endif

int TRIBE_Combat_Object::higher_than_target(RGE_Static_Object* target)
{
    if (this->world_z > target->world_z) {
        return 1;
    }

    float dest_x = target->world_x;
    float start_x = this->world_x;
    float dest_y = target->world_y;
    float start_y = this->world_y;
    float x_distance = dest_x - start_x;
    float y_distance = dest_y - start_y;

    if ((x_distance == DAT_00574C98) &&
        (y_distance == DAT_00574C98)) {
        return 0;
    }

    int num_steps;
    if (fabs(y_distance) > fabs(x_distance)) {
        num_steps = abs((int)y_distance) * 2;
    } else {
        num_steps = abs((int)x_distance) * 2;
    }

    float x_step;
    float y_step;
    x_step = x_distance / (float)num_steps;
    y_step = y_distance / (float)num_steps;

    float abs_x = x_step;
    float abs_y = y_step;
    if (abs_x < DAT_00574C98) {
        abs_x = -x_step;
    }
    if (abs_y < DAT_00574C98) {
        abs_y = -y_step;
    }

    int dx1;
    int dy1;
    int dx2;
    int dy2;
    int diagonal;
    if (abs_x > abs_y) {
        dx1 = -1;
        dy2 = 0;
        diagonal = 0;
        dx2 = 1;
    } else {
        dy2 = -1;
        dx1 = 0;
        diagonal = 1;
        dx2 = 0;
    }

    float x = start_x;
    float y = start_y;
    int prior_x = -999;
    int prior_y = -999;
    RGE_Map* map = this->owner->world->map;
    float angle = -1.0f;
    int direction = 0;
    int i;
    if (num_steps > 0) {
        i = num_steps;
        do {
            x += x_step;
            y += y_step;
            int tile_x = (int)x;
            int tile_y = (int)y;
            if (tile_x != prior_x || tile_y != prior_y) {
                prior_x = tile_x;
                prior_y = tile_y;
                if (this->higher_check_for_cliff(target, tile_x, tile_y,
                                                 start_x, start_y,
                                                 dest_x, dest_y,
                                                 map, 0, angle, direction) == 0) {
                    if (this->higher_check_for_cliff(target,
                                                     tile_x + dy2,
                                                     tile_y + dx1,
                                                     start_x, start_y,
                                                     dest_x, dest_y,
                                                     map, 0, angle,
                                                     direction) == 0) {
                        this->higher_check_for_cliff(target,
                                                     tile_x + diagonal,
                                                     tile_y + dx2,
                                                     start_x, start_y,
                                                     dest_x, dest_y,
                                                     map, 0, angle,
                                                     direction);
                    }
                }
            }
            --i;
        } while (i != 0);
    }

    if (direction < 1) {
        direction = 0;
    }
    if (direction > 0) {
        direction = 1;
    }
    return direction > 0;
}

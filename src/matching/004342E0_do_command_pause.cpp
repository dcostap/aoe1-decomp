// VA: 004342E0 RGE_Command::do_command_pause (59B, 27 asm lines)
// PDB source: Command.cpp lines 447-461
// Declare counter inside if block for conditional ebx save;
// id pointer before the if for unconditional esi setup

#ifndef COMMAND_TU_CONTEXT
class RGE_Static_Object;
class RGE_Player;
class RGE_Command_Pause;

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[0x4];
    void* world;

    RGE_Static_Object* get_obj(int id);
    void do_command_pause(RGE_Command_Pause* pause);
};

#pragma pack(push, 1)
class RGE_Command_Pause {
public:
    char gap_00;
    unsigned char unit_num;
    int object_ids[1];
};
#pragma pack(pop)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object() = 0;
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float) = 0;
    virtual void recycle_out_of_game() = 0; virtual void draw() = 0; virtual void shadow_draw() = 0;
    virtual void normal_draw() = 0; virtual void draw_front_frame() = 0; virtual void draw_back_frame() = 0;
    virtual void draw_frame() = 0; virtual unsigned char update() = 0; virtual void check_damage_sprites() = 0;
    virtual void rehook() = 0; virtual void save(int) = 0; virtual float teleport(float, float, float) = 0;
    virtual void new_sprite(void*) = 0; virtual void add_overlay_sprite(void*, unsigned char) = 0;
    virtual void remove_overlay_sprite(void*) = 0; virtual void change_ownership(RGE_Player*) = 0;
    virtual void modify(float, unsigned char) = 0; virtual void modify_delta(float, unsigned char) = 0;
    virtual void modify_percent(float, unsigned char) = 0; virtual void transform(void*) = 0;
    virtual void copy_obj(void*) = 0; virtual void set_object_state(unsigned char) = 0;
    virtual void remove_visible_resource() = 0; virtual void create_doppleganger_when_dying() = 0;
    virtual void destroy_obj() = 0; virtual void die_die_die() = 0; virtual void damage() = 0;
    virtual float calculateDamage() = 0; virtual void rotate(long) = 0; virtual unsigned char can_attack() = 0;
    virtual void set_attribute(short, float) = 0;
    virtual void set_attribute_amount(float, unsigned char, unsigned char) = 0;
    virtual int heal(int, int) = 0; virtual unsigned char heal(float) = 0;
    virtual int canRepair() = 0; virtual void notify_of_relation(long, unsigned char) = 0;
    virtual void do_command(RGE_Static_Object*, float, float, float) = 0;
    virtual void move_to(RGE_Static_Object*, float, float, float) = 0;
    virtual void work(RGE_Static_Object*, float, float, float) = 0;
    virtual void stop() = 0; virtual void set_attack(RGE_Static_Object*) = 0;
    virtual void play_command_sound() = 0; virtual void play_move_sound() = 0;
    virtual void new_angle(float) = 0; virtual RGE_Static_Object* spawn_death_obj() = 0;
    virtual void* get_command_master() = 0; virtual void set_being_worked_on() = 0;
    virtual void release_being_worked_on(RGE_Static_Object*) = 0; virtual unsigned char is_moving() = 0;
    virtual RGE_Static_Object* get_target_obj() = 0; virtual void enter_obj(RGE_Static_Object*) = 0;
    virtual void exit_obj() = 0; virtual int explore_terrain() = 0; virtual void unexplore_terrain() = 0;
    virtual void* get_los_table() = 0; virtual int inAttackRange(RGE_Static_Object*) = 0;
    virtual unsigned char underAttack() = 0; virtual void setUnderAttack(unsigned char) = 0;
    virtual float calc_attack_modifier(RGE_Static_Object*) = 0; virtual float getSpeed() = 0;
    virtual float getAngle() = 0; virtual float maximumSpeed() = 0; virtual float rateOfFire() = 0;
    virtual float damageCapability(RGE_Static_Object*) = 0; virtual float damageCapability() = 0;
    virtual float weaponRange() = 0; virtual float minimumWeaponRange() = 0;
    virtual int passableTile(float, float, int) = 0; virtual unsigned char facetToNextWaypoint() = 0;
    virtual int currentTargetID() = 0; virtual float currentTargetX() = 0;
    virtual float currentTargetY() = 0; virtual float currentTargetZ() = 0;
    virtual void setWaitingToMove(unsigned char) = 0; virtual unsigned char waitingToMove() = 0;
    virtual unsigned char actionState() = 0; virtual unsigned char keepGatheringWhenObjectIsOut(int) = 0;
    virtual unsigned char produceWhenKilledBy(int) = 0; virtual unsigned char useSameZoneDropsite() = 0;
    virtual void notify(int, int, int, long, long, long) = 0;
    virtual int attack(float, float, float, int) = 0; virtual int attack(int, int) = 0;
    virtual int moveTo(float, float, float, float, int) = 0; virtual int moveTo(int, float, int) = 0;
    virtual int moveTo(int, int) = 0; virtual int moveAwayFrom(int, int) = 0;
    virtual int hunt(int, int) = 0; virtual int gather(int, int) = 0; virtual int convert(int, int) = 0;
    virtual int heal(int, int) = 0; virtual int repair(int, int) = 0; virtual int build(int, int) = 0;
    virtual int trade(int, int) = 0; virtual int explore(int, int, int) = 0; virtual int enter(int, int) = 0;
    virtual int unload(int, float, float, float) = 0; virtual int transport(float, float, float, int) = 0;
    virtual int pause() = 0;
};
#endif

void RGE_Command::do_command_pause(RGE_Command_Pause* pause) {
    int count = pause->unit_num;
    int* id = pause->object_ids;
    if (count > 0) {
        int cnt = count;
        do {
            RGE_Static_Object* obj = this->get_obj(*id);
            if (obj != 0) {
                obj->pause();
            }
            id++;
            cnt--;
        } while (cnt != 0);
    }
}

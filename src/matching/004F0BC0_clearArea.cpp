// VA: 004F0BC0 TribeTacticalAIModule::clearArea (397 B)
// PDB source: taitacmd.cpp:3031-3093
// __thiscall, int clearArea(int, float, float, float, float)
//
// Attempt log:
// - Replaced the old raw helper scaffold with the period-typed object,
//   tactical-module, and passableTile surfaces. The binary selects the best
//   passable point around the four supplied area corners, then calls moveUnit.
// - Reordered the point and distance declarations to reproduce the original
//   stack homes; frame and call structure then aligned.
// - Reversed corner assignment order as a control-flow probe; it worsened the
//   switch and FPU layout, so it was restored.
// - Ordered switch arms by the original emitted block order. This produced an
//   exact match with the default VC5 flags.

#ifndef TAITACMD_SHARED_CONTEXT
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
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual int explore_terrain();
    virtual void unexplore_terrain();
    virtual void* get_los_table();
    virtual int inAttackRange();
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier();
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability();
    virtual float damageCapability(int);
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float x, float y, int flag);

    char gap_04[0x34];
    float world_x;
    float world_y;
    float world_z;

    float distance_to_position(float x, float y, float z);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xec];
    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xec];
    MainDecisionAIModule* md;

    int busyWithAction(int object_id, int action_id);
    int moveUnit(int object_id, float x, float y, int priority);
    int clearArea(int object_id, float x1, float y1, float x2, float y2);
};
#endif

int TribeTacticalAIModule::clearArea(int object_id, float x1, float y1,
                                     float x2, float y2)
{
    if (this->busyWithAction(object_id, -1) == 1) {
        RGE_Static_Object* object = this->md->object(object_id);
        if (object != 0) {
            float newX = -1.0f;
            float newY = -1.0f;
            float bestDistance = -1.0f;
            float tempX = -1.0f;
            float tempY = -1.0f;

            for (int i = 0; i < 8; i++) {
                switch (i) {
                case 0:
                    tempX = x1 - 2.0f;
                    tempY = y1 - 2.0f;
                    break;
                case 2:
                    tempX = x2 + 2.0f;
                    break;
                case 4:
                    tempY = y2 + 2.0f;
                    break;
                case 1:
                case 5:
                    tempX = (x2 + x1) * 0.5f;
                    break;
                case 6:
                    tempX = x1 - 2.0f;
                    break;
                case 3:
                case 7:
                    tempY = (y2 + y1) * 0.5f;
                    break;
                }

                if (object->passableTile(tempX, tempY, 1) != 0) {
                    float distance = object->distance_to_position(
                        tempX, tempY, object->world_z);
                    if (bestDistance == -1.0f || distance < bestDistance) {
                        bestDistance = distance;
                        newX = tempX;
                        newY = tempY;
                    }
                }
            }

            if (bestDistance != -1.0f) {
                this->moveUnit(object_id, newX, newY, 100);
                return 1;
            }
        }
    }
    return 0;
}

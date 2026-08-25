// VA: 00434290 do_command_stop (70 B)
// PDB source: Command.cpp lines 425-442
// attempt 2: mirror the exact pause-family topology
// - count before id to mimic the exact pause-family source order
// - id pointer at function scope for unconditional edi save/setup
// - counter inside the if block for conditional ebp save
// - object local inside the loop for conditional esi save

#ifndef COMMAND_TU_CONTEXT
class RGE_Static_Object;
class RGE_Player;
class RGE_Command_Stop;

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[0x4];
    void* world;

    RGE_Static_Object* get_obj(int id);
    void do_command_stop(RGE_Command_Stop* stop);
};

#pragma pack(push, 1)
class RGE_Command_Stop {
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
    virtual void recycle_out_of_game() = 0; virtual void draw() = 0;
    virtual void shadow_draw() = 0; virtual void normal_draw() = 0;
    virtual void draw_front_frame() = 0; virtual void draw_back_frame() = 0;
    virtual void draw_frame() = 0; virtual unsigned char update() = 0;
    virtual void check_damage_sprites() = 0; virtual void rehook() = 0;
    virtual void save(int) = 0; virtual float teleport(float, float, float) = 0;
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
    virtual void stop() = 0;

    void removeAllFromPathingGroup();
};
#endif

void RGE_Command::do_command_stop(RGE_Command_Stop* stop) {
    int count = stop->unit_num;
    int* id = stop->object_ids;
    if (count > 0) {
        int cnt = count;
        do {
            RGE_Static_Object* obj = this->get_obj(*id);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->stop();
            }
            id++;
            cnt--;
        } while (cnt != 0);
    }
}

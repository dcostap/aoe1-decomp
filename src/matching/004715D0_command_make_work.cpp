// VA: 004715D0 RGE_Player::command_make_work
// PDB source: player.cpp
// attempt log:
// - Natural selected-list reconstruction matched calls, frame, and loop body.
// - Initializing the loop index inside a combined guard omitted the original xor/cmp pair.
// - Keep the index as a function local and initialize it inside the target guard before the count test.
// - The natural 0.5f spelling emits the same binary constant reference and is retained.

extern "C" void __cdecl free(void*);

class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player*, float, float, int*, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, void*, unsigned char);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();

    char gap_04[0x24];
    float los;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
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
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
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

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
};

class RGE_Command {
public:
    void command_work(RGE_Static_Object**, short, RGE_Static_Object*, float, float);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* commands;
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0a];
    short id;

    unsigned char get_selected_objects_to_command(RGE_Static_Object***, void*, int, int, int, int);
    unsigned char command_make_work(RGE_Static_Object*, float, float);
};

unsigned char RGE_Player::command_make_work(RGE_Static_Object* target, float x, float y) {
    RGE_Static_Object** list;
    short local_4[2];
    int i;

    if (this->get_selected_objects_to_command(&list, local_4, -1, -1, -1, -1)) {
        RGE_Master_Static_Object* master = list[0]->get_command_master(target, x, y, 0);
        if (master != 0) {
            master->play_command_sound();
        }
        this->world->commands->command_work(list, local_4[0], target, x, y);
        if (target != 0) {
            i = 0;
            if (local_4[0] > 0) {
                do {
                    this->sendUnitAIOrder((int)this->id, list[i]->id, 0x2bd,
                        target->id, (int)target->owner->id,
                        target->world_x, target->world_y, 1.0f,
                        target->master_obj->los * 0.5f, 0, 0, 100);
                    ++i;
                } while (i < local_4[0]);
            }
        }
        free(list);
        return 1;
    }
    return 0;
}

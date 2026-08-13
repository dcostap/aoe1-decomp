// 004C6400 RGE_Static_Object::find_drop_location
// Fresh typed reconstruction from stat_obj.cpp:3881-3940.
// The candidate keeps the canonical argument order, master/object ownership,
// map bounds, placement virtual, and passable-tile virtual from the binary.
// Attempt log:
// - baseline typed reconstruction reached the original 0x8 frame, all four
//   saved registers, and the complete ten-call set. It emits 672 versus 674
//   bytes with 84.65% instruction-shape similarity.
// - inlining or splitting the random side expression was codegen-neutral.
// - grouped y-offset arithmetic made the body 704 bytes and was rolled back.
// - a shared x-coordinate tail removed two debug_rand calls and was rolled
//   back. The four separate calls are required by the original switch.
// - binary final-loop stores update the expanded radii, not the drop center;
//   restored typed radius updates before testing the ordered object calls.
// - prior validation: 548 positional diff bytes; call sites and targets align.
//   Remaining drift starts at random side scaling (original mov/shl/imul).
//   The natural typed spatial reconstruction remains in scratch.
// - radius ownership probe kept 548 positional-diff bytes and the 0x8 frame;
//   shape improved to 85.58% and edit diff to 176, so the radius form remains.
// - inlining the side-selection debug_rand call reproduced the original
//   mov/magic-multiply/shl division sequence; this removed the early hunk and
//   reduced positional diff to 178 bytes.
// - parenthesizing case-1 as drop_y + (scaled_y - radius_y) stopped VC5 from
//   tail-sharing the case-0 y calculation; both original y blocks now align.
// - spelling final updates as existing-radius + master increment preserved the
//   typed ownership and restored the original 674-byte function size; current
//   best is 152 positional bytes, 93.06% shape, and all ten calls aligned.
// - remaining drift begins at the first bound-failure branch displacement and
//   includes late block/return layout; no call, frame, or size uncertainty.
// - Restored the named stat_obj.cpp debug source. The former raw address was
//   diagnostic data plumbing.
// - final validation follows this source and the documented probe.

extern "C" int debug_rand(char*, int);
extern float DAT_00574720;
extern float DAT_00574764;

static char s_stat_obj_cpp[] = "C:\\msdev\\work\\age1_x1\\stat_obj.cpp";

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;

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
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    char gap_04[0x2c];
    float radius_x;
    float radius_y;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int map_width;
    int map_height;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
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

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;

    unsigned char lookupZone(int, int);

    unsigned char find_drop_location(int, float*, float*, RGE_Master_Static_Object*,
                                     RGE_Static_Object*, float, float, float, float);
};

unsigned char RGE_Static_Object::find_drop_location(
    int terrain, float* x, float* y, RGE_Master_Static_Object* master,
    RGE_Static_Object* object, float drop_x, float drop_y,
    float radius_x, float radius_y)
{
    radius_x += master->radius_x;
    radius_y += master->radius_y;
    float radius_2x = radius_x + radius_x;
    float radius_2y = radius_y + radius_y;
    int outer = 1;

    do {
        int attempt = 0;
        do {
            switch ((debug_rand(s_stat_obj_cpp, 0xf3a) * 4) / 0x7fff) {
            case 0: {
                *x = radius_x + drop_x;
                int value = debug_rand(s_stat_obj_cpp, 0xf3e);
                *y = (float)value * radius_2y * DAT_00574764 - radius_y + drop_y;
                break;
            }
            case 1: {
                *x = drop_x - radius_x;
                int value = debug_rand(s_stat_obj_cpp, 0xf42);
                *y = drop_y +
                     ((float)value * radius_2y * DAT_00574764 - radius_y);
                break;
            }
            case 2: {
                *y = radius_y + drop_y;
                int value = debug_rand(s_stat_obj_cpp, 0xf46);
                *x = (float)value * radius_2x * DAT_00574764 - radius_x + drop_x;
                break;
            }
            case 3: {
                *y = drop_y - radius_y;
                int value = debug_rand(s_stat_obj_cpp, 0xf4a);
                *x = (float)value * radius_2x * DAT_00574764 - radius_x + drop_x;
                break;
            }
            }

            if (*x >= DAT_00574720 && *y >= DAT_00574720) {
                RGE_Map* map = this->owner->world->map;
                if ((float)map->map_width >= *x &&
                    (float)map->map_height >= *y) {
                    if (terrain == -1 ||
                        terrain == (int)this->lookupZone((int)*x, (int)*y)) {
                        if (master->check_placement(this->owner, *x, *y,
                                                    0, 1, 1, 1, 0, 1, 1) == 0 &&
                            object->passableTile(*x, *y, 0) == 1) {
                            return 1;
                        }
                    }
                }
            }
            ++attempt;
        } while (attempt < 50);

        radius_x = radius_x + (master->radius_x + master->radius_x);
        radius_y = radius_y + (master->radius_y + master->radius_y);
        radius_2x = radius_2x + (master->radius_x * 4.0f);
        radius_2y = radius_2y + (master->radius_y * 4.0f);
        ++outer;
    } while (outer < 2);

    return 0;
}

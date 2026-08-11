// VA: 004C52F0 RGE_Static_Object::set_object_state
// PDB: stat_obj.cpp:2706-2776
// Attempt log:
// - Prior scratch attempts used an incorrect object layout, owner/master aliases,
//   and hand-expanded array growth; they produced broad drift (704B vs 787B).
// - Reconstructed the canonical RGE_Static_Object/master/player ownership from
//   exact stat_obj.cpp donors: master_obj +08, owner +0C, tile +1C,
//   groupMembers +64, unitAI +74, commander +78.
// - Restored the period ManagedArray<int>::operator[] grow-on-read surface and
//   the real virtual slots (+60/+64, +D8/+DC), plus the typed unitAI/status path.
// - baseline candidate: natural typed state transitions and group reassignment;
//   validate before treating any remaining codegen drift as a source lead.
// - Probe 1 baseline: 2 bytes differed at the child-state threshold; all calls,
//   layout, frame, CFG, and array growth were exact.
// - Probe 2 control-flow: spelling the binary-proven threshold as <= 2 instead
//   of < 3 selected cmp 2/ja; exact 787-byte match.

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class UnitAIModule;
class AIPlayStatus;
class RGE_Sprite;
class TDrawArea;
class RGE_Color_Table;
class RGE_Armor_Weapon_Info;
class RGE_Action_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int index);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world; // +0x3C
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x24];
    float los; // +0x28
    char gap_2c[0x7A];
    unsigned char create_doppleganger_on_death; // +0xA6
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_value = (int*)operator_new(new_size * 4);
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class UnitAIModule {
public:
    char gap_00[0x12C];
    AIPlayStatus* playStatus; // +0x12C
    void setPlayStatus(AIPlayStatus* status);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
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
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
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
    virtual int explore_terrain(RGE_Player*, unsigned char, int); // +0xD8
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int); // +0xDC

    long id; // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner; // +0x0C
    void* sprite; // +0x10
    void* old_sprite; // +0x14
    void* sprite_list; // +0x18
    void* tile; // +0x1C
    RGE_Static_Object* inside_obj; // +0x20
    void* objects; // +0x24
    short screen_x_offset; // +0x28
    short screen_y_offset; // +0x2A
    short shadow_x_offset; // +0x2C
    short shadow_y_offset; // +0x2E
    float hp; // +0x30
    unsigned char curr_damage_percent; // +0x34
    unsigned char facet; // +0x35
    unsigned char selected; // +0x36
    unsigned char selected_group; // +0x37
    float world_x; // +0x38
    float world_y; // +0x3C
    float world_z; // +0x40
    float attribute_amount_held; // +0x44
    unsigned char object_state; // +0x48
    unsigned char sleep_flag; // +0x49
    unsigned char dopple_flag; // +0x4A
    unsigned char goto_sleep_flag; // +0x4B
    short attribute_type_held; // +0x4C
    unsigned char type; // +0x4E
    unsigned char worker_num; // +0x4F
    void* player_object_node; // +0x50
    ManagedArray_int pathingGroupMembers; // +0x54
    ManagedArray_int groupMembers; // +0x64
    UnitAIModule* unitAIValue; // +0x74
    int groupCommanderValue; // +0x78
    int zoneMapIndex; // +0x7C
    float groupRangeValue; // +0x80

    void take_attribute_from_owner();
    UnitAIModule* unitAI();
    void set_sleep_flag(unsigned char sleep_flag);

};

void RGE_Static_Object::set_object_state(unsigned char state)
{
    if (this->object_state != state) {
        if (state >= 3 && this->object_state < 3) {
            this->take_attribute_from_owner();
            if (this->master_obj->create_doppleganger_on_death == 2) {
                this->create_doppleganger_when_dying();
            }
        }

        if (this->object_state <= 3 && state >= 7) {
            this->remove_visible_resource();
        }

        if (state >= 3 && this->object_state == 2 && this->tile != 0) {
            this->unexplore_terrain(this->owner, 0, -1);
            if (this->master_obj->los > 0.0) {
                this->explore_terrain(this->owner, 1, -1);
            }
        }

        if (this->object_state < 7 && state == 7 && this->tile != 0 &&
            this->master_obj->los > 0.0) {
            this->unexplore_terrain(this->owner, 1, -1);
        }

        this->object_state = state;

        if (state == 3 &&
            this->groupCommanderValue == this->id &&
            this->unitAIValue != 0 &&
            this->groupMembers.numberValue > 1) {
            int i = 0;
            int newCommander = -1;
            if (this->groupMembers.numberValue > 0) {
                do {
                    if (this->groupMembers[i] != this->id) {
                        RGE_Static_Object* object =
                            this->owner->world->object(this->groupMembers[i]);
                        if (object != 0 && object->object_state <= 2 &&
                            object->unitAI() != 0) {
                            if (newCommander == -1) {
                                newCommander = this->groupMembers[i];
                            }
                            object->groupCommanderValue = newCommander;
                            if (this->groupMembers[i] == newCommander) {
                                object->unitAI()->setPlayStatus(
                                    this->unitAIValue->playStatus);
                            }
                        }
                    }
                    ++i;
                } while (i < this->groupMembers.numberValue);
            }
        }

        if (this->sleep_flag != 0 && this->object_state != 2 &&
            this->object_state != 6) {
            this->set_sleep_flag(0);
        }
    }
}

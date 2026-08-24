// VA: 004C3C70 RGE_Static_Object::update()
// PDB: C:\msdev\work\age1_x1\stat_obj.cpp, lines 1684-1861.
// Qualified symbol: ?update@RGE_Static_Object@@UAEEXZ.
// Boundary: [004C3C70,004C3F64), 757 bytes; the 004C3F68 table is outside it.
// Canonical reconstruction uses the reviewed RGE_Player and RGE_Static_Object
// virtual surfaces. The used slots are addObject, removeObject,
// check_damage_sprites, new_sprite, set_object_state, and spawn_death_obj.
// ManagedArray uses the period new[] and delete[] ownership form.
// The group removal loop, state switch, decay path, and recyclable result match
// the original control flow and field widths.
// Final validation: 757 bytes, 17 ordered calls, frame 0x8, Result: MATCH.

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" void __cdecl debug_srand(char* file, int line, int seed);
extern int debug_random_on;
extern char STR_STAT_OBJ[];

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Object_Node;
class RGE_Game_World { public: char gap[0x7C]; short curr_player; char gap2[6]; float attr_rate; RGE_Static_Object* object(int id); };
class RGE_Sound { public: void play(int); };
class RGE_Sprite;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int value);
    virtual int isAlly(int value);
    virtual int isNeutral(int value);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int value, int value2);
    virtual void loadAIInformation(char* a, char* b, char* c, int d, int e);
    virtual void sendUnitAIOrder(int a, int b, int c, int d, int e,
                                 float f, float g, float h, float i, int j, int k, int l);
    virtual void processAIOrder(int a, int b, int c, int d, int e,
                                float f, float g, float h, float i, int j, int k, int l);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(void* a, void* b, float c, float d);
    virtual void sendAddWaypointCommand(int a, void* b, int c);
    virtual void processAddWaypointCommand(int a, void* b, int c);
    virtual void sendPlayCommand(int a, int* b, int c, int d, int e);
    virtual void sendPlayCommand(int a, int b, int c);
    virtual int sendAICommand(int a, int b, int c, int d, int e);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int a, int b, int c);
    virtual void* make_scenario_obj(float a, float b, float c, short d, uchar e, float f);
    virtual void scenario_save(int value);
    virtual void scenario_load(int a, long* b, float c);
    virtual void scenario_postsave(int value);
    virtual void scenario_postload(int a, long* b, float c);
    virtual void load(int value);
    virtual void add_attribute_num(short a, float b, uchar c);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int value);
    virtual void save2(int value);
    virtual void save_info(int value);
    virtual void random_start();
    virtual void* make_new_object(long a, float b, float c, float d, int e);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int a, int* b, int* c);
    virtual uchar command_make_move(void* a, float b, float c);
    virtual uchar command_make_work(void* a, float b, float c);
    virtual uchar command_make_do(void* a, float b, float c);
    virtual uchar command_stop();
    virtual uchar command_place_object(short a, float b, float c, float d);
    virtual uchar command_add_attribute(int a, float b);
    virtual uchar command_give_attribute(int a, int b, float c);
    virtual uchar command_formation(int value);
    virtual uchar command_stand_ground();
    virtual uchar command_create_group(int a, int* b, int c, float d);
    virtual uchar command_add_to_group(int a, int b, float c);
    virtual uchar command_remove_from_group(int a, int b);
    virtual uchar command_destroy_group(int value);
    virtual uchar command_resign(int a, int b);
    virtual uchar command_add_waypoint(float a, float b, float c);
    virtual RGE_Object_Node* addObject(RGE_Static_Object* object, int sleep, int dopple);
    virtual void removeObject(RGE_Static_Object* object, int sleep, int dopple, RGE_Object_Node* node);
    char gap0[0x38]; RGE_Game_World* world; char gap44[0x0A]; short id;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    uchar master_type;
    char gap05[0x17];
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    uchar undead_flag;
    char gap25;
    short hp;
    float los;
    uchar obj_max;
    char gap2d[3];
    float radius_x;
    float radius_y;
    float radius_z;
    RGE_Sound* selected_sound;
    RGE_Sound* created_sound;
    RGE_Sound* death_sound;
    char gap48[0x38];
    float decay;
    char gap84[0x20];
    uchar recyclable;
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_value = new int[new_size];
            if (new_value != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; ++i)
                    new_value[i] = this->value[i];
                delete[] this->value;
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
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
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int file);
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Sprite* sprite);
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player* player);
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state(uchar state);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate(long angle);
    virtual uchar can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual int heal(int amount, int max_amount);
    virtual uchar heal(float amount);
    virtual int canRepair();
    virtual void notify_of_relation();
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float angle);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual int explore_terrain();
    virtual void unexplore_terrain();
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object* object);
    virtual uchar underAttack();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
    uchar sleep_flag;
    uchar dopple_flag;
    uchar goto_sleep_flag;
    short attribute_type_held;
    uchar type;
    uchar worker_num;
    RGE_Object_Node* player_object_node;
    ManagedArray_int pathingGroupMembers;
    ManagedArray_int groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;
    uchar gap_87;
};
#endif

uchar RGE_Static_Object::update()
{
    uchar ret = 0;
    if (this->goto_sleep_flag != 0) {
        RGE_Player* own = this->owner;
        this->goto_sleep_flag = 0;
        own->removeObject(this, 0, this->dopple_flag, this->player_object_node);
        this->player_object_node = this->owner->addObject(this, 1, this->dopple_flag);
        return 0;
    }
    if (this->groupMembers.numberValue > 0) {
        int i = 0;
        if (i < this->groupMembers.numberValue) {
            while (i < this->groupMembers.numberValue) {
                int id = this->groupMembers[i];
                RGE_Static_Object* obj = this->owner->world->object(id);
                if (obj == 0 || obj->object_state > 2) {
                    int n = this->groupMembers.maximumSizeValue; int k = 0;
                    while (k < n && this->groupMembers.value[k] != id) { k++; }
                    if (k < n) {
                        if (k < n - 1) { do { int* p = this->groupMembers.value; k++; p[k-1] = p[k]; } while (k < this->groupMembers.maximumSizeValue - 1); }
                        int gn = this->groupMembers.numberValue - 1; this->groupMembers.numberValue = gn; if (gn < 0) this->groupMembers.numberValue = 0;
                    }
                    i--;
                }
                i++;
            }
        }
    }
    if (this->inside_obj == 0) {
        switch (this->object_state) {
    case 2: this->check_damage_sprites();
    case 0:
        if (this->hp < 1.0f) {
            this->set_object_state(3); this->new_sprite(this->master_obj->death_sprite);
            int r = debug_rand(STR_STAT_OBJ, 0x704); int old = debug_random_on; debug_random_on = 0;
            if (this->master_obj->death_sound != 0 && this->owner->id == this->owner->world->curr_player) this->master_obj->death_sound->play(1);
            debug_random_on = old; debug_srand(STR_STAT_OBJ, 0x70e, r);
        } break;
    case 3: case 5:
        if (this->attribute_type_held == -1 || this->attribute_amount_held <= 0.0f) {
            if (this->master_obj->undead_flag != 0) { this->set_object_state(6); this->new_sprite(this->master_obj->undead_sprite); break; }
            this->set_object_state(7); this->spawn_death_obj(); break;
        }
        if (this->master_obj->decay > 0.0f) {
            this->attribute_amount_held = this->attribute_amount_held - this->owner->world->attr_rate * this->master_obj->decay;
            if (this->attribute_amount_held < 0.0f) {
                this->attribute_amount_held = 0.0f;
            }
        }
        break;
    case 7: this->set_object_state(8); break;
    case 8:
        if (this->master_obj->recyclable != 0)
            ret = 2;
        else
            ret = 1;
        break;
        }
    } else {
        if (this->inside_obj->object_state > 2)
            this->set_object_state(this->inside_obj->object_state);
    }
    return ret;
}

#ifndef AOE1_TIMELINE_H
#define AOE1_TIMELINE_H

// Reviewed declarations for C:\\msdev\\work\\age1_x1\\Timeline.cpp.
// The class layouts and virtual slots below cover the fields and calls used by
// this module.

class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Sprite;
class TDrawArea;
struct RGE_Time_Entry;

extern "C" void __cdecl rge_read(int fd, void* data, int size);
extern "C" void __cdecl rge_write(int fd, void* data, int size);

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_id(long id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1e];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    char gap_2c[0x1e];
    short id;
};

typedef char timeline_player_layout[
    (sizeof(RGE_Player) >= 0x4c) ? 1 : -1];

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    char gap_08[0x38];
    RGE_Player** players;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);

    char gap_04[0x0c];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
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

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[4];
    unsigned char object_state;
};

struct RGE_Time_Entry {
    float time;
    unsigned char command;
    unsigned char gap_05[1];
    short obj_type;
    unsigned char player;
    unsigned char gap_09[3];
    float x;
    float y;
    float z;
    short task;
    unsigned char gap_1a[2];
    RGE_Static_Object* this_obj;
    short this_obj_id;
    unsigned char gap_22[2];
    RGE_Static_Object* target_obj;
    short target_obj_id;
    unsigned char gap_2a[2];
    RGE_Time_Entry* next;
};

typedef char timeline_entry_layout[
    (sizeof(RGE_Time_Entry) == 0x30) ? 1 : -1];
typedef char timeline_entry_next_offset[
    ((char*)&((RGE_Time_Entry*)0)->next - (char*)0 == 0x2c) ? 1 : -1];

class RGE_Timeline {
public:
    RGE_Timeline(int fd, RGE_Game_World* world);
    RGE_Timeline(RGE_Game_World* world);
    virtual ~RGE_Timeline();

    void save(int fd);
    void update();
    void mock_update(float time);

private:
    short find_id(RGE_Static_Object* obj);

public:
    RGE_Time_Entry* add(float time);
    RGE_Time_Entry* add_attack(float time, RGE_Static_Object* this_obj,
                               RGE_Static_Object* target_obj);
    RGE_Time_Entry* add_create(float time, short obj_type,
                               unsigned char player, float x, float y,
                               float z);
    RGE_Time_Entry* add_move(float time, RGE_Static_Object* this_obj,
                             float x, float y, float z);
    RGE_Time_Entry* add_delete(float time, RGE_Static_Object* this_obj);
    void sub(RGE_Time_Entry* entry);

    RGE_Game_World* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    float old_time;
};

typedef char timeline_object_layout[
    (sizeof(RGE_Timeline) == 0x14) ? 1 : -1];
typedef char timeline_world_offset[
    ((char*)&((RGE_Timeline*)0)->world - (char*)0 == 0x04) ? 1 : -1];
typedef char timeline_list_offset[
    ((char*)&((RGE_Timeline*)0)->time_list - (char*)0 == 0x08) ? 1 : -1];

#endif
